#include "Search tree.h"
#include <set>
#include <random>

using namespace std;
using namespace tree;

void tests() {
	BTree set;
	set.print();
	set.insert(0);
	set.erase(0);
	cout << endl;
	set.print();
	cout << endl;
	for (int i = 0; i < 20; ++i) {
		set.insert(i);
	}
	set.print();

	for (int i = 0; i < 20; i += 2) {
		set.erase(i);
	}
	if(set.insert(2))cout << '\n' << "aboba" << '\n';
	set.print();
}

int main(){
	tests();
	return 0;
}