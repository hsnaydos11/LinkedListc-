#include "Header.h"

Node* Xor(Node* x, Node* y)
{
    return reinterpret_cast<Node*>(
        reinterpret_cast<uintptr_t>(x)
        ^ reinterpret_cast<uintptr_t>(y));
}

void XORPush(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}
void XORPush1(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void InsertXOR(Node** head_ref, int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->xnode = *head_ref;

    if (*head_ref != NULL) {
        (*head_ref)
            ->xnode = Xor(new_node, (*head_ref)->xnode);
    }

    *head_ref = new_node;
}
void XORPrint(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    cout << "The nodes of Linked List are: \n";

    while (curr != NULL) {
        cout << curr->data << " ";

        next = Xor(prev, curr->xnode);
        prev = curr;
        curr = next;
    }
}
void XORPrint1(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
void DeleteXOR(Node** head_ref, int key) {
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
void XORMemory() {
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
void XORLength(struct Node* node) {
    int res = 0;
    while (node != NULL) {
        res++;
        node = node->next;
    }
}
bool XORSearch(Node* head, int x) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == x) {
            return true;
        }
        current = current->next;
    }
    return false;
}
void XORList(struct Node* node) {
    struct Node* last;

    while (node != NULL) {
        cout << node->data << "<==>";
        last = node;
        node = node->next;
    }
    if (node == NULL)
        cout << "NULL";
}
void INSERTXOR() {
    auto start = high_resolution_clock::now();
    Node* head = NULL;
    InsertXOR(&head, 10);
    InsertXOR(&head, 100);
    InsertXOR(&head, 1000);
    InsertXOR(&head, 10000);

    XORPrint(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void XORLENGTH() {
    struct Node* head = NULL;
    auto start = high_resolution_clock::now();
    XORPush(&head, 10);
    XORPush(&head, 100);
    XORPush(&head, 1000);
    XORPush(&head, 10000);
    cout << "Length of Double List is :";
    XORLength(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;;
}
void XORLIST() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    XORPush(&head, 6);
    XORPush(&head, 7);
    XORPush(&head, 1);
    XORPush(&head, 4);
    cout << "Doubly linked list is as follows: " << endl;
    XORList(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;;
}
void DELETEXOR() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    XORPush1(&head, 6);
    XORPush1(&head, 7);
    XORPush1(&head, 1);
    XORPush1(&head, 4);
    printf("\nCreated Linked List:");
    SinglePrintList(head);
    DeleteXOR(&head, 1);
    printf("\nLinked List after Deletion of 1: \n");
    XORPrint1(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void XORSEARCH() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    XORPush(&head, 6);
    XORPush(&head, 7);
    XORPush(&head, 1);
    XORPush(&head, 4);
    XORSearch(head, 1) ? cout << "\nYes" : cout << "\nNo";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
