#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>
#include "composite.h"

class Iterator{
    protected:
        Base* self_ptr;
        Base* current_ptr;

    public:
        Iterator ( Base* ptr ) { this->self_ptr = ptr; }

        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool is_done() = 0;
        virtual Base* current() = 0;
};
#endif
