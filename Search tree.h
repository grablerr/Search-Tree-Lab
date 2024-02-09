#pragma once
#include <iostream>

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

		BTree& operator=(BTree lhs);

		void print();

		bool insert(int key);

		bool contains(int key);

		bool erase(int key);

	};

	void BTree::destroyTree(Node* node) {

	}

	BTree::~BTree() {

	}

	BTree& BTree::operator=(BTree lhs) {

	}

	void BTree::print() {

	}

	bool BTree::insert(int key) {
		return true;
	}

	bool BTree::contains(int key) {
		return true;
	}

	bool BTree::erase(int key) {
		return true;
	}

}

