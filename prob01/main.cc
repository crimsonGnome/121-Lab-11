// Name: Joseph Eggers
// CWID: 85939488
// Email: joseph.eggers@csu.fullerton.edu

#include <iostream>
#include <string>

#include "person.h"

using std::cin, std::cout, std::endl, std::string;

int main() {
  string GGParent;
  string GParent;
  string Parent;
  string kid;

  cout << "What is the great-grandparent's name? ";
  cin >> GGParent;
  cout << "What is the grandparent's name? ";
  cin >> GParent;
  cout << "What is the parent's name? ";
  cin >> Parent;
  cout << "What is the kid's name? ";
  cin >> kid;
  cout << endl;

  // Create People
  Person greatGrandParent(GGParent);
  Person grandParent(GParent);
  Person parent(Parent);
  Person child(kid);

  // Create family Relationship
  Person* theirChild;
  theirChild = &grandParent;
  greatGrandParent.SetChild(theirChild);

  // grandParent to parent
  theirChild = &parent;
  grandParent.SetChild(theirChild);

  // Set parent to kid
  theirChild = &child;
  parent.SetChild(theirChild);

  // Print family tree
  cout << "The family tree is:\n";
  greatGrandParent.Print();

  return 0;
}
