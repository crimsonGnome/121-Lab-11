// Name: Joseph Eggers
// CWID: 88593948
// Email: joseph.eggers@csu.fullerton.edu

#include "rainstorm.h"

#include <random>
#include <vector>

#include "raindrop.h"

// Constants you can use in your program.
const int kRaindropSize = 10;
const int kImageSize = 300;
const int kFastRate = 5;
const int kSlowRate = 3;
const graphics::Color kWhite(255, 255, 255);

// Provided function to calculate a raindrop's initial state. Pass pointers to
// a x coordianet, a y coordinate, and a integer rate of fall.
void CalculateRandomRaindropParams(int* x, int* y, int* rate) {
  const int kFastRate = 5;
  const int kSlowRate = 3;
  *x = rand() % kImageSize;
  *y = rand() % kImageSize;
  *rate = rand() % 2 ? kSlowRate : kFastRate;
}

Rainstorm::Rainstorm() {
  this->image_.Initialize(300, 500);
  std::vector<Raindrop*> raindropVector;
  this->raindropVector_ = raindropVector;
}

Rainstorm::~Rainstorm() {
  // Remove itself as an animation event listener.
  image_.RemoveAnimationEventListener(*this);

  for (size_t i = 0; i < raindropVector_.size(); i++) {
    delete raindropVector_[i];
  }
}

// Initializes the Rainstorm class.
void Rainstorm::Initialize(int raindrop_count) {
  // Create the image to be 300x300px. Do not change the size.
  image_.Initialize(kImageSize, kImageSize);
  // Adds itself as an animation event listener to the image.
  image_.AddAnimationEventListener(*this);

  // dynamic memory allocation of pointers

  graphics::Image* image = &image_;

  for (int i = 0; i < raindrop_count; i++) {
    int x = 0;
    int y = 0;
    int rate = 0;
    int* xptr = &x;
    int* yptr = &y;
    int* rateptr = &rate;
    // Randomize
    CalculateRandomRaindropParams(xptr, yptr, rateptr);

    // Create new pointer
    Raindrop* raindropPtr;
    raindropPtr = new Raindrop(image, x, y, rate);

    // Draw RainDrop
    raindropPtr->Draw();

    // push to
    this->raindropVector_.push_back(raindropPtr);
  }
}

void Rainstorm::Start() {
  // Feel free to rename the window.
  image_.ShowUntilClosed("Rainy day");
}

void Rainstorm::OnAnimationStep() {
  // Clear the image by drawing a white rectangle across the whole background.
  int height = image_.GetHeight();
  int width = image_.GetWidth();
  image_.DrawRectangle(0, 0, width, height, kWhite);
  graphics::Image* image = &image_;

  // For each Raindrop* in the vector, ask it to Fall(), then check its
  // y coordinate is still within the image bounds. If it is within bounds,
  // Draw() it, otherwise delete it and dynamically allocate memory for a new
  // Raindrop*, replacing the old Raindrop* at that location with the new one,
  // using CalculateRandomRaindropParams and starting y at 0.

  for (size_t i = 0; i < raindropVector_.size(); i++) {
    raindropVector_[i]->Fall();

    if (height <= raindropVector_[i]->GetY()) {
      int x;
      int y;
      int rate;
      int* xptr = &x;
      int* yptr = &y;
      int* rateptr = &rate;
      // Randomize
      CalculateRandomRaindropParams(xptr, yptr, rateptr);

      delete raindropVector_[i];
      Raindrop* raindropPtr;
      raindropVector_[i] = new Raindrop(image, x, 0, rate);
    }
    raindropVector_[i]->Draw();
  }

  // Refresh the drawing using Image::Flush.
  image_.Flush();
}
