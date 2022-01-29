// Name: Joseph Eggers
// CWID: 88593948
// Email: joseph.eggers@csu.fullerton.edu

#include "raindrop.h"

Raindrop::Raindrop(graphics::Image* image, int x, int y, int rate) {
  this->image_ = image;
  this->x_ = x;
  this->y_ = y;
  this->rate_ = rate;
}

void Raindrop::Fall() { this->y_ = y_ + rate_; }

void Raindrop::Draw() { image_->DrawCircle(x_, y_, 10, 180, 196, 235); }
