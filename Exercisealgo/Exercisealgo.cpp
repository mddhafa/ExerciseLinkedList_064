#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private :
	Node* LAST;

public :
	CircularLinkedList() {
		LAST = NULL;
	}

	void addNode();
	bool search(int rollno, Node** dhafa, Node** muhammad);
	bool listEmpty();
	bool delNode();
	void traverse();

};

void CircularLinkedList::addNode() {
	int No;
	string name;
	cout << "\nEnter the roll number : ";
	cin >> No;
	cout << "\nEnter the name  ";
	cin >> name;

	Node* newNode = new Node();
	newNode->rollNumber = No;
	newNode->name = name;

	if (LAST == NULL || No <= LAST->rollNumber ) {
		if (LAST != NULL && No == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST; 
		if (LAST != NULL)
			LAST-> next = newNode; 
		newNode-> next = NULL; 
		LAST = newNode;
		return;
	}

	Node* muhammad = LAST;
	Node* dhafa = NULL;
	while (muhammad->next != NULL && muhammad->next->rollNumber < No)
	{
		dhafa = muhammad;
		muhammad = muhammad->next;
	}

	if (muhammad->next != NULL && No == muhammad->next->rollNumber) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}

}

bool CircularLinkedList::search(int rollno, Node** dhafa, Node** muhammad) {
	*dhafa= LAST->next;
	*muhammad = LAST->next;

	while (*muhammad != LAST) {
		if (rollno == (*muhammad)->rollNumber) {
			return true;
		}
		*dhafa = *muhammad;
		*muhammad = (*muhammad)->next;
	}
	if (rollno = LAST->rollNumber) {
		return true;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() { //write your answer here

}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << "  " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			case '2': {
				obj.delNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << "search" << endl;
		}
	}
	return 0;
}
