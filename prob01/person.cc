// Name: Joseph Eggers
// CWID: 85939488
// Email: joseph.eggers@csu.fullerton.edu

#include "person.h"

#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

Person::Person(string name) {
  this->name_ = name;
  this->child_ = nullptr;
}
void Person::TreePrint() {
  Person* child;
  child = GetChild();
  cout << ", parent of " << GetName();
  if (GetChild() != nullptr) {
    child->TreePrint();
  }
}

void Person::Print() {
  if (GetChild() != nullptr) {
    cout << GetName();
    Person* child;
    child = GetChild();
    child->TreePrint();
  } else {
    // Base Case
    cout << GetName() << endl;
  }
}
