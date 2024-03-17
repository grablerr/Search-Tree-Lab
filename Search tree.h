#pragma once
#include <iostream>
#include <queue>
#include <iomanip>
#include <vector>

using namespace std;
namespace tree {

	struct Node {
		int _value;
		Node* _left;
		Node* _right;
		Node(int value) :_value(value), _left(nullptr), _right(nullptr) {}
	};

	class BTree {
	private:
		Node* _root;
	public:
		BTree() : _root(nullptr) {};

		BTree(Node* rootNode) : _root(rootNode) {};

		void destroyTree(Node* node);
		~BTree();

		Node* copyTree(Node* node);
		BTree& operator=(const BTree lhs);

		void printRecursive(Node* node, int key);
		void print();

		bool insertRecursive(Node*& node, int key);
		bool insert(int key);

		bool containsRecursive(Node* node, int key);
		bool contains(int key);

		bool eraseRecursive(Node*& node, int key);
		bool erase(int key);

		Node* minValueNode(Node* node);

		Node* getRoot() const { return _root; }

		vector<int> to_vector();

		void to_vector(Node* ptr, vector<int>& vec);
	};

	void BTree::destroyTree(Node* node) {
		if (node) {
			destroyTree(node->_left);
			destroyTree(node->_right);
			delete node;
		}
	}

	BTree::~BTree() {
		destroyTree(_root);
	}
	Node* BTree::copyTree(Node* node) {
		if (!node) return nullptr;

		Node* newNode = new Node(node->_value);
		newNode->_left = copyTree(node->_left);
		newNode->_right = copyTree(node->_right);
		return newNode;
	}

	BTree& BTree::operator=(BTree lhs) {
		destroyTree(_root);
		_root = copyTree(lhs._root);
		return *this;
	}

	void BTree::printRecursive(Node* node, int l) {
		int i;
		if (node != nullptr) {
			printRecursive(node->_right, l + 1);

			for (i = 1; i <= l; i++)
				std::cout << "   ";

			std::cout << node->_value << std::endl;

			printRecursive(node->_left, l + 1);
		}
	}

	void BTree::print() {
		printRecursive(_root, 0);
	}

	bool BTree::insertRecursive(Node*& node, int key) {
		if (node->_value == key)
			return false;

		if (key < node->_value) {
			if (!node->_left) {
				node->_left = new Node(key);
				return true;
			}
			return insertRecursive(node->_left, key);
		}

		else {
			
			if (!node->_right) {
				node->_right = new Node(key);
				return true; 
			}
			return insertRecursive(node->_right, key);
		}
	}

	bool BTree::insert(int key) {
		if (!_root) {
			_root = new Node(key);
			return true;
		}

		return insertRecursive(_root, key);
	}

	bool BTree::containsRecursive(Node* node, int key) {
		if (!node)
			return false;

		if (node->_value == key)
			return true;

		if (key < node->_value)
			return containsRecursive(node->_left, key);
		else
			return containsRecursive(node->_right, key);
	}

	bool BTree::contains(int key) {
		return containsRecursive(_root, key);
	}

	bool BTree::eraseRecursive(Node*& node, int key) {
		if (!node)
			return false;

		if (key < node->_value)
			return eraseRecursive(node->_left, key);
		else if (key > node->_value)
			return eraseRecursive(node->_right, key);
		else {
			if (!node->_left) {
				Node* temp = node->_right;
				delete node;
				node = temp;
			}
			else if (!node->_right) {
				Node* temp = node->_left;
				delete node;
				node = temp;
			}
			else {
				Node* temp = minValueNode(node->_right);
				node->_value = temp->_value;
				eraseRecursive(node->_right, temp->_value);
			}
			return true;
		}
	}

	bool BTree::erase(int key) {
		return eraseRecursive(_root, key);
	}

	Node* BTree::minValueNode(Node* node) {
		Node* current = node;
		while (current && current->_left)
			current = current->_left;
		return current;
	}

	vector<int> BTree::to_vector() {
		vector<int> vec;
		to_vector(_root, vec);
		return vec;
	}

	void BTree::to_vector(Node* ptr, vector<int>& vec) {
		if (!ptr) {
			return;
		}
		vec.push_back(ptr->_value);
		to_vector(ptr->_left, vec);
		to_vector(ptr->_right, vec);
	}

	vector<int> get_unique(vector<int> vec) {
		auto set_repeat = BTree();
		auto set_unique = BTree();

		for (auto i : vec) {
			if (!set_unique.contains(i) && !set_repeat.contains(i)) {
				set_unique.insert(i);
			}
			else {
				if (set_unique.contains(i) && !set_repeat.contains(i)) {
					set_unique.erase(i);
					set_repeat.insert(i);
				}
			}
		}

		vector<int> unique = set_unique.to_vector();
		return unique;
	}
}