#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


class Stack {
	//private node structure
private:
	struct node {
		int data;
		node* next; //pointer to next element
	};
	node *topvalue;
	int count; //count of elements
	int maxnum; //maximum number of elements
	int stackData;
public:
	Stack(int data) : topvalue(NULL), maxnum(data), count(0) {}

	~Stack() { //destructor
		node *current = topvalue;
		//need to delete all vallue
		while (!current == NULL) {
			node *next = current->next;
			delete current;
			current = next;

		}
	}

	void push(int value);


	int top();


	void pop();


	void begin() {}


	bool rollback() {
	}

	bool commit() {
	}


};

//implementation
void Stack::push(int value) {
	if (count == maxnum)
		cout << "stack is full";
	else
	{
		node *newTop = new node;
		if (topvalue == NULL)
		{
			newTop->data = value;
			newTop->next = NULL;
			topvalue = newTop;
			count++;
		}
		else
		{
			newTop->data = value;
			newTop->next = topvalue;
			topvalue = newTop;
			count++;
		}
	}
}

int Stack::top() {
	if (topvalue == NULL) {
		return 0;
	}
	return topvalue->data;
}

void Stack::pop() {
	if (topvalue == NULL)
		cout << "nothing to pop";
	else
	{
		node * old = topvalue;
		topvalue = topvalue->next;
		count--;
		delete(old);
	}
}