// BinarySearchTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> // cout
#include <algorithm> // random_shuffle()
#include <vector> // vector
#include <ctime> // time()
#include <cstdlib> // srand()
using namespace std;

#define SEED 1
// For predictable randomness, change the number to test a different start order
// For unpredictable randomness, get the number from the clock, e.g. unsigned(time(0))

//TODO finish defining a tree node
struct Node {
	//void* value;
	char value;
	Node* left;
	Node* right;

	//Node(void* value) {
	//	this->value = value;
	//}

	Node(char value) {
		this->value = value;
		left = nullptr;
		right = nullptr;
	}

	void display() {

	}
};

//TODO finish defining a BST
struct Tree {
	Node* root;

	//constructor for an empty tree
	Tree() {
		root = nullptr;
	}

	void inOrderDisplay(Node* subtree) {
		//recursive tree traversal, aka walking
		if (subtree == nullptr) return;
		inOrderDisplay(subtree->left);
		cout << subtree->value;
		if (subtree->right) inOrderDisplay(subtree->right);
	}

	void preOrderDisplay(Node* subtree) {
		//recursive tree traversal, aka walking
		if (subtree == nullptr) return;
		cout << subtree->value;
		if (subtree->left) preOrderDisplay(subtree->left);
		if (subtree->right) preOrderDisplay(subtree->right);
	}

	void postOrderDisplay(Node* subtree) {
		//recursive tree traversal, aka walking
		if (subtree == nullptr) return;
		if (subtree->left) postOrderDisplay(subtree->left);
		if (subtree->right) postOrderDisplay(subtree->right);
		cout << subtree->value;
	}

	void insert(char value) {
		Node* newNode = new Node(value); // create the new node
		Node* curNode = root; // start at the root of the tree

		while (curNode != nullptr) { // if our current place is defined
			if (value < curNode->value) { // traverse left if less than curNode
				if (curNode->left == nullptr) { // can't traverse any farther
					curNode->left = newNode; // so go ahead and insert left
					break; // we inserted, so end the loop
				}
				curNode = curNode->left; // we didn't insert, so step left
			}
			else { // traverse right if value is greater or equal to curNode
				if (curNode->right == nullptr) { // can't traverse any farther
					curNode->right = newNode; // so insert right
					break; // we inserted, so end the loop
				}
				curNode = curNode->right; // we didn't insert, so step right
			}
		}
		// the while condition is already true for an empty tree, so assign root
		if (root == nullptr) root = newNode;
	}

	void deleteNode(char value) {

	}

	bool search(char value) {

	}


};

int main() {
	// HINT: start with a shorter alphabet
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector<char> letters(alphabet, alphabet + sizeof(alphabet) - 1);

	// comment out to prevent shuffling
	srand(SEED);
	random_shuffle(letters.begin(), letters.end());

	// dump out the order of input
	for (auto letter : letters) {
		cout << letter << ' ';
	}
	cout << '\n';

	Tree* tree = new Tree();

	// loop over the input
	for (auto letter : letters) {
		// insert a letter into the tree
		tree->insert(letter);
	}
	// display the tree
	tree->inOrderDisplay(tree->root);
	// search for the letter

	// loop over the input
	// delete a letter from the tree
	// display the tree
	// search for the letter

	getchar();
	return 0;
}