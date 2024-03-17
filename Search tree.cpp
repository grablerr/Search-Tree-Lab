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
	if (set.insert(2))cout << '\n' << "aboba" << '\n';
	set.print();
}

int main() {

	std::vector<int> input = { 3, 2, 2, 4 };
	std::vector<int> result = get_unique(input);

	for (int value : result) {
		std::cout << value << " ";
	}
	std::cout << std::endl;

	return 0;
}