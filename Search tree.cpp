#include "Search tree.h"

using namespace std;
using namespace tree;

int main(){

	BTree MyTree;
	MyTree.insert(8);
	MyTree.insert(6);
	MyTree.insert(4);
	MyTree.insert(9);

	MyTree.print();

	return 0;
}