#ifndef NULL_ITERATOR_H
#define NULL_ITERATOR_H
#include "Iterator.h"
class NullIterator: public Iterator {
  //inherited:
  //  Base* self_ptr; 
  //  Base* current_ptr;
  public:
    //inherited:
    //  Iterator (Base * ptr) {this->self_ptr = ptr;}
    NullIterator(Base* ptr);
    void first(); 
    void next(); 
    bool is_done();
    Base* current();
};

NullIterator::NullIterator(Base* ptr): Iterator(ptr) {}

void NullIterator::first() {}
void NullIterator::next() {}
bool NullIterator::is_done() { return true; }
Base* NullIterator::current() { return NULL; }
#endif

