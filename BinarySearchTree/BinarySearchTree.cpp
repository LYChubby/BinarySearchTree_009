#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Constructor For The Node Class
	Node(string i, Node* l, Node* r) {
		
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public :
	Node* ROOT;

	BinaryTree() {

		ROOT = NULL; // Initializing ROOT To NULL
	}

	void insert(string element) { // Insert a Node In The Binary Search Tree

		Node* newNode = new Node(element, NULL, NULL);  // Allocate Memory For The New Node
		newNode->info = element;  // Assign Value To The Data Field Of The New Node
		newNode->leftchild = NULL;  // Make The Left Child Of The New Node Point To NULL
		newNode->rightchild = NULL; // Make The Right Child Of The New Node Point To NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		search(element, parent, currentNode);  // Locate The Node Which Will Be The Parent Of The Node To Be Inserted

		if (parent == NULL) { // If The Parent Is NULL (Tree Is Empty)

			ROOT = newNode;  // Mark The New Node As ROOT
			return;  // Exit
		}

		if (element < parent->info) { // If The Value In The Data Field Of The New Node Is Less Than That Of The Parent

			parent->leftchild = newNode;  // Make The Left Child Of The Parent Point To The New Node
		}
		else if (element > parent->info) {  // If The Value In The Data Field Of The New Node Is Greater Than That Of The Parent

			parent->rightchild = newNode;  // Make The Right Child Of TheParent Point to The New Node
		}
	}
};