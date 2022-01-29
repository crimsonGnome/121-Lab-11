// Name: Joseph Eggers
// CWID: 88593948
// Email: joseph.eggers@csu.fullerton.edu

#ifndef RAINDROP_H
#define RAINDROP_H

#include "cpputils/graphics/image.h"

class Raindrop {
 private:
  int x_;
  int y_;
  int rate_;
  graphics::Image* image_;

 public:
  // Constructors
  Raindrop(graphics::Image* image, int x, int y, int rate);

  // Getters
  int GetY() const { return y_; };
  int GetX() const { return x_; };
  int GetRate() const { return rate_; };
  // Memeber Function
  void Fall();
  void Draw();
};

#endif  // RAINDROP_H
