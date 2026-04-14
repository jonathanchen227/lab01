#include "student.h"
#include <string>
#include <cstring>

Student::Student(const char * const n, int p) {
  perm = p;
  if ( n ) {
	  name = new char[strlen(n) + 1];
	  strcpy(name,n);
  }
  else {
	  name = nullptr;
  }
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
  perm = permNumber;
}

void Student::setName(const char * const n) {
  delete[]name;
  if(n) {
  name = new char[strlen(n)+1];
  strcpy(name,n);
  }
  else {
	  name = nullptr;
 }
}


Student::Student(const Student &orig) {
  setName(orig.getName());
  setPerm(orig.getPerm());
}

Student::~Student() {
    delete[] name;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);
  delete[] name;
  // TODO... Here is where there is code missing that you need to 
  // fill in...
  if(right.name) {
	  perm = right.perm;
  name = new char[strlen(right.name)+1];
  strcpy(name,right.name);
  } else {
	  name = nullptr;
 }



  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
	std::string n = (name ? name : "" );
	return "[" + std::string(name) +  "," + std::to_string(perm) +"]";
}

