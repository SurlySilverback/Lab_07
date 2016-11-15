#ifndef OPERATOR_ITERATOR_H
#define OPERATOR_ITERATOR_H
#include "Iterator.h"
class OperatorIterator: public Iterator { 
  //inherited:
  //  Base* self_ptr; 
  //  Base* current_ptr;
  public:
    //inherited:
    //  Iterator (Base * ptr) {this->self_ptr = ptr;}
    OperatorIterator(Base* ptr);
    void first(); 
    void next(); 
    bool is_done();
    Base* current();
};

OperatorIterator::OperatorIterator(Base* ptr): Iterator(ptr) {
  std::cout << "Constructor: Operator Iterator\n";
}

void OperatorIterator::first() {
  this->current_ptr = this->self_ptr->get_left();  
}

void OperatorIterator::next() {
  
  if (this->current_ptr == this->self_ptr->get_left()) {
    
     this->current_ptr = this->self_ptr->get_right();    
  }
  
  else if (this->current_ptr == this->self_ptr->get_right()){
    
    this->current_ptr = NULL;
  }
}

bool OperatorIterator::is_done() {
  if ( this->current_ptr == NULL )
  // ORIGINAL CODE
  //if (this->current_ptr == NULL || this->current_ptr == this->self_ptr->get_right() ) 
    return true;
  return false;
}

Base* OperatorIterator::current() {
  return this->current_ptr;
}
#endif
