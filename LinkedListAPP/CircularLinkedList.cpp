#include "Header.h"

struct Node* InsertCircularBegin(struct Node* last, int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = last->next;
    last->next = temp;

    return last;
}
struct Node* InsertCircularEnd(struct Node* last, int data)
{
    struct Node* temp =
        (struct Node*)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}
struct Node* InsertCircularAfter(struct Node* last, int data, int item)
{
    if (last == NULL)
        return NULL;

    struct Node* temp, * p;
    p = last->next;
    do
    {
        if (p->data == item)
        {
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;

            if (p == last)
                last = temp;
            return last;
        }
        p = p->next;
    } while (p != last->next);

    cout << item << " not present in the list." << endl;
    return last;
}

void CircularPrint(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
void CircularPush(Node **head_ref, int data) {
    Node* ptr1 = new Node();
    ptr1->data = data;
    ptr1->next = *head_ref;

    if (*head_ref != NULL) {
        Node* temp = *head_ref;
        while (temp->next != *head_ref) {
            temp = temp->next;
        }
        temp->next = ptr1;
    }
    else {
        ptr1->next = ptr1;
    }
    *head_ref = ptr1;
}
void DeleteCircular(Node** head, int key) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node* last = *head, * d;

    if ((*head)->data == key)
    {

        while (last->next != *head)
            last = last->next;

        last->next = (*head)->next;
        free(*head);
        *head = last->next;
    }

    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }

    if (last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }
    else {
        cout << "no such keyfound";
    }
}


bool CircularSearch(Node* head, int x) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == x) {
            return true;
        }
        current = current->next;
    }
    return false;
}
int CircularLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void CircularList(Node* n) {
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}
void CircularMemory() {
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
void CircularTRAVERSE(struct Node *last) {
    struct Node* p;
    if (last == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    p = last->next;
    do {
        cout << p->data << " ";
        p = p->next;
    }     while (p != last->next);
}

void InsertCIRCULAR() {
    struct Node* last = NULL;
    auto start = high_resolution_clock::now();
    last = InsertCircularBegin(last, 4);
    last = InsertCircularBegin(last, 2);
    last = InsertCircularEnd(last, 8);
    last = InsertCircularEnd(last, 12);
    last = InsertCircularAfter(last, 10, 8);

    CircularTRAVERSE(last);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void DeleteCIRCULAR() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    CircularPush(&head, 2);
    CircularPush(&head, 5);
    CircularPush(&head, 7);
    CircularPush(&head, 8);
    CircularPush(&head, 10);
    cout << "\nList Before Deletion: \n";
    CircularPrint(head);
    DeleteCircular(&head, 7);
    cout << "\nList after Deletion : \n";
    CircularPrint(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void ListCIRCULAR() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    CircularPush(&head, 2);
    CircularPush(&head, 5);
    CircularPush(&head, 7);
    CircularPush(&head, 8);
    CircularPush(&head, 10);
    cout << "\ncount of node is " << SingleLength(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void SearchCIRCULAR() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    CircularPush(&head, 2);
    CircularPush(&head, 5);
    CircularPush(&head, 7);
    CircularPush(&head, 8);
    CircularPush(&head, 10);
    CircularSearch(head, 1) ? cout << "\nYes" : cout << "\nNo";
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void LengthCIRCULAR() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    CircularPush(&head, 2);
    CircularPush(&head, 5);
    CircularPush(&head, 7);
    CircularPush(&head, 8);
    CircularPush(&head, 10);
    cout << "\ncount of node is " << CircularLength(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}