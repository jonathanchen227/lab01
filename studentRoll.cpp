#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = nullptr;
}

void StudentRoll::insertAtTail(const Student &student) {
  Node* newNode = new Node;
  newNode->s  = new Student(student);
  if ( !head ) {
	  head= tail = newNode;
  }
  else {
	tail->next = newNode;
	tail = newNode;
  }	  
}

std::string StudentRoll::toString() const {
	std::string result= "[";
  Node* curr = head;
  while ( curr ) {
	  result += curr->s->toString();
	  result += "\n";
	  curr = curr->next;
  }
  result += "]";
  return result;

	  
}

StudentRoll::StudentRoll(const StudentRoll& orig) {
  head = tail = nullptr;
  Node* curr = orig.head;
   while ( curr ) 
   {
	 insertAtTail(*(curr->s));
	 curr = curr->next;
   } 
}

StudentRoll::~StudentRoll() {
  Node* current = head;
  while ( current ) {
	  Node* temp = current;
	  current = current->next;
	  delete temp->s;
	  delete temp;
	  
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  Node* curr = head;
  while ( curr ) {
	  Node* temp = curr;
	  curr = curr->next;
	  delete temp->s;
	  delete temp;
  }
  head = tail = nullptr;
  if ( !(&right) ) {
	  return *this;
  }
  Node* tempOther = right.head;

  while (tempOther ) {
	  insertAtTail(*(tempOther->s));
	  tempOther = tempOther->next;
  }
  

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}






