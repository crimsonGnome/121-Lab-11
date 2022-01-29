// Name: Joseph Eggers
// CWID: 88593948
// Email: joseph.eggers@csu.fullerton.edu

#ifndef RAINSTORM_H
#define RAINSTORM_H

#include <vector>

#include "cpputils/graphics/image.h"
#include "raindrop.h"

// Rainstorm class inherits from AnimationEventListener.
class Rainstorm : public graphics::AnimationEventListener {
 public:
  // Destructor must free up memory from any dynamically allocated Raindrops.
  ~Rainstorm();

  // Initialize the Rainstorm by allocating |raindrop_count| Raindrop objects.
  void Initialize(int raindrop_count);

  // Shows the image. Separating ``Initialize`` from ``Start`` ensures unit
  // tests will work, and it's good design too!
  void Start();

  // Animation event overridden from graphics::AnimationEventListener.
  void OnAnimationStep() override;

  // Constructor
  Rainstorm();
  // Used by unit tests. Do not modify.
  graphics::Image* GetImageForTesting() { return &image_; }

 private:
  // The image onto which you can draw the Rainstorm.
  graphics::Image image_;
  std::vector<Raindrop*> raindropVector_;
};

#endif  // RAINSTORM_H
