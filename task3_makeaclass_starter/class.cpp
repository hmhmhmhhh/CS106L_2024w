// Blank cpp file
#include "class.h"

student::student() {
    age = 18;
    name = "Xiao Ming";
    state = "Computer Science";
}

student::student(std::string name, std::string state, int age) {
    this->age = age;
    this->name = name;
    this->state = state;
}

int student::getAge() {
    return this->age;
}

std::string student::getState() {
    return this->state;
}

std::string student::getName() {
    return this->name;
}

void student::setAge(int age) {
    this->age = age;
}

void student::setState(std::string state) {
    this->state = state;
}

void student::setName(std::string name) {
    this->name = name;
}

student::~student(){}