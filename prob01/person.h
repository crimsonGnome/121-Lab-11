// Name: Joseph Eggers
// CWID: 85939488
// Email: joseph.eggers@csu.fullerton.edu

#ifndef PERSON_H
#define PERSON_H

#include <string>

using std::string;

class Person {
 private:
  string name_;
  Person* child_;

 public:
  // Constructor
  Person(string name);

  // Getters
  string GetName() const { return name_; };
  Person* GetChild() const { return child_; };

  // Setters
  void SetChild(Person* child) { this->child_ = child; };

  // class methods
  void Print();
  void TreePrint();
};

#endif  // PERSON_H
