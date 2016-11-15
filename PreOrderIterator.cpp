#include "PreOrderIterator.h"

void PreOrderIterator::first()
{
    // FIXME: Make sure this constructs a new pointer correctly
    Iterator it = this->self_ptr->CreateIterator();

    if (it) // check if not NULL
    {
        it->First();
        
        for ( unsigned int i = 0; i < iterators.size(); ++i )
        {
            iterators.pop();
        }

        this->iterators.push(it);
    }
}

void PreOrderIterator::next()
{
    Iterator it = iterators.top()->current()->CreateIterator();
    it->first();
    iterators.push(it)

    while ( iterators.size() > 0 && iterators.top()->is_done() )
    {
        delete iterators.pop();
        
        if (iterators.top != NULL )
        {
            iterators.top()->next();
        }
    }
}

void PreOrderIterator::is_done()
{
    if ( iterators.size() == 0 )
        return true;

    else
        return false;
}

Base* PreOrderIterator::current()
{
    if ( this->iterators.Size() > 0 )
        return this->iterators.Top()->current();
    
    else
        return NULL;
}
