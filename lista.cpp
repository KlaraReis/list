#include <iostream>

using namespace std;

class Node {
    public:
    int value;
    Node* next;
};

class LinkedList {
    
    public:
    Node* head;
    
    void add(int newValue) {
        if (head == NULL) {
            head = new Node();
            head->value = newValue;
            head->next = NULL;
        }
        else {
            Node* lastNode = head;
            while(lastNode->next != NULL) {
                lastNode = lastNode->next;
            }
            Node* newNode = new Node();
            newNode->value = newValue;
            newNode->next = NULL;
            lastNode->next = newNode;
        }
    }
    
    void remove(int valueToBeRemoved) {
        
        if (head == NULL) {
            return;
        }
        
        if (head->value == valueToBeRemoved) {
            head = head->next;
        }
        else {
            Node* currNode = head;
            while (currNode != NULL) {
                if (currNode->next->value == valueToBeRemoved) {
                    currNode->next = currNode->next->next;
                    break;
                }
    	        currNode = currNode->next;
    	    }
        }
    }
};

int main() {
	LinkedList* list = new LinkedList();
	list->add(5);
	list->add(2);
	list->add(3);
	
	//list->remove(5);
	
	//print all values
	Node* currNode = list->head;
	while (currNode != NULL) {
	    cout << currNode->value << " ";
	    currNode = currNode->next;
	}
	
	return 0;
}