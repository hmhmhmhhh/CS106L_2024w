#include "class.h"
#include <iostream>
/*
 * Assigment 3: Make a class!
 * Requirements:
 * Must have a custom constructor ❌
 * Must have a default constructor ❌
    - i.e. constructor overloading
 * Must have private members (functions and/or variables) ❌
 * Must have public members (functions) ❌
 * Must have at least one getter function ❌
 * Must have at least one setter function ❌
 */

int main() {
  // initialize class and run this file
  student s;
  std::cout << "age: " << s.getAge() << " name: " << s.getName() << " state: " << s.getState() << std::endl;
  student c("HM", "CS", 20);
  std::cout << "age: " << c.getAge() << " name: " << c.getName() << " state: " << c.getState() << std::endl;
  c.setAge(19);
  std::cout << "age: " << c.getAge() << std::endl;
  return 0;
}