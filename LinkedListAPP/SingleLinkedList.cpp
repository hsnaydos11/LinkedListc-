#include "Header.h"

void InsertSingle(Node** head_ref, int data) {
	Node* new_node = new Node();
	new_node->data = data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void InsertSingleEnd(Node* prev_node, int new_data)
{
	if (prev_node == NULL)
	{
		cout << "The given previous node cannot be NULL";
		return;
	}
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
void InsertSingleSpecific(Node** head_ref, int new_data)
{

    Node* new_node = new Node();

    Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
    return;
}

void Singlepush(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void SingleDelete(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            
        return;
    }

    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;

        delete temp;
    }
}
void SinglePrintList(Node *node){
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int SingleLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
bool SingleSearch(Node* head, int x) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == x) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void SingleList(Node *n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}
void SingleMemory(){
    auto start = high_resolution_clock::now();
    int size;
    int* ptr;
    cout << "Enter number of values you want to store:" << endl;
    cin >> size;

    ptr = new int[size];
    cout << "Enter values to be stored in the array"<< endl;
    for (int i = 0; i < size; i++) {
        cin >> ptr[i];
    }
    cout << "Values in the array are:" << endl;
    for (int i = 0; i < size; i++) {
        cout << ptr[i] << endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << "microseconds" << endl;
}

void SingleINSERT() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    InsertSingleEnd(head, 6);

    InsertSingle(&head, 7);

    InsertSingle(&head, 1);

    InsertSingleEnd(head, 4);

    InsertSingleSpecific(&head->next, 8);

    cout << "\nCreated Linked list is: ";
    SinglePrintList(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void SingleDELETE() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    Singlepush(&head, 6);
    Singlepush(&head, 7);
    Singlepush(&head, 1);
    Singlepush(&head, 4);
    printf("\nCreated Linked List:");
    SinglePrintList(head);
    SingleDelete(&head, 1);
    printf("\nLinked List after Deletion of 1: ");
    SinglePrintList(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void SingleLIST() {
    Node* head1 = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* fourth = NULL;
    auto start = high_resolution_clock::now();
    head1 = new Node();
    second = new Node();
    third = new Node();
    fourth = new Node();
    head1->data = 6;
    head1->next = second;

    second->data = 7;
    second->next = third;

    third->data = 1;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;
    cout << "Single Linked List is ";
    SinglePrintList(head1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void SingleSEARCH() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    Singlepush(&head, 6);
    Singlepush(&head, 7);
    Singlepush(&head, 1);
    Singlepush(&head, 4);
    SingleSearch(head, 1) ? cout << "\nYes" : cout << "\nNo";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void SingleLENGTH() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    Singlepush(&head, 6);
    Singlepush(&head, 7);
    Singlepush(&head, 1);
    Singlepush(&head, 4);
    cout << "\ncount of node is " << SingleLength(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}