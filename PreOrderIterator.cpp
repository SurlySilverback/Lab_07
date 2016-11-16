#include "PreOrderIterator.h"

PreOrderIterator::PreOrderIterator(Base* ptr): Iterator(ptr) {};

void PreOrderIterator::first() {
  while(!(this->iterators.empty())) {
    delete this->iterators.top();
    this->iterators.pop();
  }

  Iterator* iter = this->self_ptr->create_iterator(); 
  iter->first();

  this->iterators.push(iter);    
}

void PreOrderIterator::next() {
  Iterator* it = iterators.top()->current()->create_iterator();
  it->first();
  iterators.push(it);
  
  while (this->iterators.size() > 0 && this->iterators.top()->is_done()) {
    delete this->iterators.top();  //FIXME: fix order of delete and setting next
    this->iterators.pop();
    
    if ( iterators.size() != 0 )
    {
        this->iterators.top()->next();
    }
  }
}

bool PreOrderIterator::is_done() {
  if (iterators.size() == 0)
    return true;
  else
    return false;
}

Base* PreOrderIterator::current() {
  if (this->iterators.size() > 0) {
    //std::cout << "PreOrderIter.current(): stack still > 0\n";
    if (this->iterators.top()->current() == NULL)
      std::cout << "current was pointing to NULL\n";

    return (this->iterators.top())->current();
  } 
  else
    return NULL;
}