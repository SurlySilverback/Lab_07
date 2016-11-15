#ifndef PREORDERITERATOR_H
#define PREORDERITERATOR_H

#include "Iterator.h"
#include <stack>

class PreOrderIterator : public Iterator {

    protected:
        stack<Iterator*> iterators;

    public:
        PreOrderIterator( Base* ptr );

        void first();
        void next();
        bool is_done();
        Base* current();
};

#endif
