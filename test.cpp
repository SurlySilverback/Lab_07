#include <iostream>
#include <vector>
#include "composite.h"
#include "PreOrderIterator.h"

using namespace std;

int main() {
	
	Base* op3 = new Op(3);
	Base* op4 = new Op(4);
	Base* op2 = new Op(2);
	Base* add = new Add(op3, op4);
	Base* sqr = new Sqr(op2);
	Base* sub = new Sub(add, sqr);
	Base* root = new Root(sub);

	cout << "--- PreOrder Iteration ---" << endl;
	PreOrderIterator* pre_itr = new PreOrderIterator(root);
	for(pre_itr->first(); !pre_itr->is_done(); pre_itr->next()) { 
		pre_itr->current()->print();
		cout << endl;
	}
};
