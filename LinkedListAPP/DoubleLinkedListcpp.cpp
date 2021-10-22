#include "Header.h"

void InsertDoubleBegin(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if ((*head_ref) != NULL) {
		(*head_ref)->prev = new_node;
	}
	(*head_ref) = new_node;
}
void InsertDoubleAfter(Node* prev_node, int new_data) {
	if (prev_node == NULL) {
		cout << "The given previous node cannot be NULL";
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
	new_node->prev = prev_node;
	if (new_node->next != NULL) {
		new_node->next->prev = new_node;
	}
}
void InsertDoubleEnd(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	Node* last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_node;
	new_node->prev = last;
	return;
}
void DoublePrint(Node *node) {
	struct Node* last;
	cout << "\nDouble Linked List is: ";
	while (node != NULL) {
		cout << " " << node->data;
		last = node;
		node = node->next;
	}
}
void DoublePrint1(Node *node) {
	while (node != NULL) {
		cout << node->data << " ";
		node = node->next;
	}
}
void DeleteDouble(Node** head_ref, Node* del) {
	if (*head_ref == NULL || del == NULL) {
		return;
	}
	if (*head_ref == del) {
		*head_ref = del->next;
	}
	if (del->next != NULL) {
		del->next->prev = del->prev;
	}
	if (del->prev != NULL) {
		del->prev->next = del->next;
	}
	free(del);
	return;
}
void DoublePush(Node** head_ref, int new_data) {
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head_ref);
	if ((*head_ref) != NULL) {
		(*head_ref)->prev = new_node;
	}
	(*head_ref) = new_node;
}
void DoubleLength(struct Node *node) {
	int res = 0;
	while (node != NULL) {
		res++;
		node = node->next;
	}
}
bool DoubleSearch(Node* head, int x) {
	Node* current = head;
	while (current != NULL) {
		if (current->data == x) {
			return true;
		}
		current = current->next;
	}
	return false;
}
void DoubleList(struct Node* node) {
	struct Node* last;

	while (node != NULL) {
		cout << node->data << "<==>";
		last = node;
		node = node->next;
	}
	if (node == NULL)
		cout << "NULL";
}

void DoubleMemory() {
	auto start = high_resolution_clock::now();
	int size;
	int* ptr;
	cout << "Enter number of values you want to store:" << endl;
	cin >> size;

	ptr = new int[size];
	cout << "Enter values to be stored in the array" << endl;
	for (int i = 0; i < size; i++) {
		cin >> ptr[i];
	}
	cout << "Values in the array are:" << endl;
	for (int i = 0; i < size; i++) {
		cout << ptr[i] << endl;
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void InsertDOUBLE() {
	Node* head = NULL;
	auto start = high_resolution_clock::now();
	InsertDoubleEnd(&head, 6);
	InsertDoubleBegin(&head, 7);
	InsertDoubleBegin(&head, 1);
	InsertDoubleEnd(&head, 4);
	InsertDoubleAfter(head->next, 8);
	cout << "\nCreated Double Linked List is: ";
	CircularPrint(head);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void DeleteDOUBLE() {
	Node* head = NULL;
	auto start = high_resolution_clock::now();
	DoublePush(&head, 2);
	DoublePush(&head, 4);
	DoublePush(&head, 8);
	DoublePush(&head, 10);
	cout << "\nLinked List is ";
	DoublePrint1(head);
	DeleteDouble(&head, head);
	DeleteDouble(&head, head->next);
	DeleteDouble(&head, head->next);
	cout << "\nAfter Deleted Double Linked List is ";
	DoublePrint1(head);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void DoubleLENGTH() { ///BURAYA BAK HATA VAR
	struct Node* head = NULL;
	auto start = high_resolution_clock::now();
	DoublePush(&head, 2);
	DoublePush(&head, 4);
	DoublePush(&head, 8);
	DoublePush(&head, 10);
	cout << "Length of Double List is :";
	DoubleLength(head);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;;
}
void DoubleSEARCH() {
	Node* head = NULL;
	auto start = high_resolution_clock::now();
	DoublePush(&head, 6);
	DoublePush(&head, 7);
	DoublePush(&head, 1);
	DoublePush(&head, 4);
	DoubleSearch(head, 5) ? cout << "\nYes" : cout << "\nNo";
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void DoubleLIST() {
	Node* head = NULL;
	DoublePush(&head, 6);
	DoublePush(&head, 7);
	DoublePush(&head, 1);
	DoublePush(&head, 4);
	cout << "Doubly linked list is as follows: " << endl;
	DoubleList(head);
}