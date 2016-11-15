#ifndef OPERATOR_ITERATOR_H
#define OPERATOR_ITERATOR_H
#include "iterator.h"
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

OperatorIterator::OperatorIterator(Base* ptr): Iterator(ptr) {}

Base* OperatorIterator::first() {
  this->current_ptr = this->self_ptr->get_left();  
  return this->current_ptr;
}

void OperatorIterator::next() {
  if (this->current_ptr = this->self_ptr->get_left())
    this->current_ptr = this->self_ptr->get_right();
  if (this->current_ptr = this->self_ptr->get_right())
    this->current_ptr = NULL;
}

bool OperatorIterator::is_done() {
  if (this->current_ptr = NULL || this->current_ptr = this->self_ptr->get_right()) 
    return true;
  return false;
}

Base* OperatorIterator::current() {
  return this->current_ptr;
}
#endif
