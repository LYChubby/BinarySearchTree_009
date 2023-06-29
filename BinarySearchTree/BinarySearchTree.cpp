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

	void search(string element, Node*& parent, Node*& currentNode) {
		// This Function Searches The CurrentNode Of The Specified Node As Well As The Current Node Of Its Parent

		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element)) {

			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(Node* ptr) {

		if (ROOT == NULL) {

			cout << "Tree Is Empty" << endl;
			return;
		}
		if (ptr != NULL) {
			
			inorder(ptr->leftchild);
			cout << ptr->info << " ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(Node* ptr) {

		if (ROOT == NULL) {

			cout << "Tree Is Empty" << endl;
			return;
		}
		if (ptr != NULL) {

			cout << ptr->info << " ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(Node* ptr) {  // Performs The Postorder Traversal Of The Tree

		if (ROOT == NULL) {

			cout << "Tree Is Empty" << endl;
			return;
		}
		if (ptr != NULL) {

			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << " ";
		}
	}
};

int main() {

	BinaryTree obj;
	while (true) {

		cout << "\nMenu" << endl;
		cout << "1. Implement Insert Operation" << endl;
		cout << "2. Perform Inorder Traversal" << endl;
		cout << "3. Perform preorder Traversal" << endl;
		cout << "4. Perform Postorder Traversal" << endl;
		cout << "5. Exit" << endl;
		cout << "\nEnter Your Choice ( 1 - 5 ) : ";

		char ch;
		cin >> ch;
		cout << endl;

		switch (ch) {

		case '1': {

			cout << "Enter A Word : ";
			string word;
			cin >> word;
			obj.insert(word);
			break;
		}
		case '2': {

			obj.inorder(obj.ROOT);
			break;
		}

		}
	}
}