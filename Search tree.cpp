#include "Search tree.h"

using namespace std;
using namespace tree;

int main(){

	Node a(2);
	Node l(1);
	Node r(3);
	a._left = &l;
	a._right = &r;
	cout << a._value << endl;
	cout << a._left->_value << endl;
	cout << a._right->_value << endl;

	return 0;
}