#ifndef UNARY_ITERATOR_H
#define UNARY_ITERATOR_H
#include "Iterator.h"
class UnaryIterator: public Iterator {
  //  Base* self_ptr; 
  //  Base* current_ptr;
  public:
  //inherited:
  //  Iterator (Base * ptr) {this->self_ptr = ptr;}
    UnaryIterator(Base* ptr);
    void first(); 
    void next(); 
    bool is_done(); 
    Base* current();
};

UnaryIterator::UnaryIterator(Base* ptr): Iterator(ptr) {}

void UnaryIterator::first() {
  this->current_ptr = this->self_ptr->get_left();
}

void UnaryIterator::next() {
  
  this->current_ptr = NULL;
}

bool UnaryIterator::is_done() {
  if (this->current_ptr == NULL)
    return true;
  return false; 
}

Base* UnaryIterator::current() {

  return this->current_ptr;
}
#endif
