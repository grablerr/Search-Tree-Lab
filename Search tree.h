#pragma once
#include <iostream>
#include <queue>
#include <iomanip>
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
		BTree& operator=(BTree lhs);

		void printRecursive(Node* node);
		void print();

		bool insertRecursive(Node*& node, int key);
		bool insert(int key);

		bool contains(int key);

		bool erase(int key);

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

	void BTree::printRecursive(Node* node) {
		if (node) {
			cout << node->_value << " ";
			printRecursive(node->_left);
			printRecursive(node->_right);
		}
	}

	void BTree::print() {
		printRecursive(_root);
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

	bool BTree::contains(int key) {
		return true;
	}

	bool BTree::erase(int key) {
		return true;
	}

}

