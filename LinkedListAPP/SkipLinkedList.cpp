#include "Header.h"
struct snode
{
    int value;
    snode** forw;
    snode(int level, int& value)
    {
        forw = new snode * [level + 1];
        memset(forw, 0, sizeof(snode*) * (level + 1));
        this->value = value;
    }
    ~snode()
    {
        delete[] forw;
    }
};

/* Skip List Declaration     */

struct skiplist
{
    snode* header;
    int value;
    int level;
    skiplist()
    {
        header = new snode(MAX_LEVEL, value);
        level = 0;
    }
    ~skiplist()
    {
        delete header;
    }
    void ListSkip();
    bool SkipSearch(int&);
    void InsertSkip(int&);
    void DeleteSkip(int&);
};


float frand()
{
    return (float)rand() / RAND_MAX;
}

/* Random Level Generator     */

int random_level()
{
    static bool first = true;
    if (first)
    {
        srand((unsigned)time(NULL));
        first = false;
    }
    int lvl = (int)(log(frand()) / log(1. - P));
    return lvl < MAX_LEVEL ? lvl : MAX_LEVEL;
}

/* Insert Element in Skip List     */

void skiplist::InsertSkip(int& value)
{
    snode* x = header;
    snode* update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(snode*) * (MAX_LEVEL + 1));
    for (int i = level; i >= 0; i--)
    {
        while (x->forw[i] != NULL && x->forw[i]->value < value)
        {
            x = x->forw[i];
        }
        update[i] = x;
    }
    x = x->forw[0];
    if (x == NULL || x->value != value)
    {
        int lvl = random_level();
        if (lvl > level)
        {
            for (int i = level + 1; i <= lvl; i++)
            {
                update[i] = header;
            }
            level = lvl;
        }
        x = new snode(lvl, value);
        for (int i = 0; i <= lvl; i++)
        {
            x->forw[i] = update[i]->forw[i];
            update[i]->forw[i] = x;
        }
    }
}

/* Delete Element from Skip List     */

void skiplist::DeleteSkip(int& value)
{
    snode* x = header;
    snode* update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(snode*) * (MAX_LEVEL + 1));
    for (int i = level; i >= 0; i--)
    {
        while (x->forw[i] != NULL && x->forw[i]->value < value)
        {
            x = x->forw[i];
        }
        update[i] = x;
    }
    x = x->forw[0];
    if (x->value == value)
    {
        for (int i = 0; i <= level; i++)
        {
            if (update[i]->forw[i] != x)
                break;
            update[i]->forw[i] = x->forw[i];
        }
        delete x;
        while (level > 0 && header->forw[level] == NULL)
        {
            level--;
        }
    }
}

/* Display Elements of Skip List     */

void skiplist::ListSkip()
{
    struct Node* n{};
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

/* Search Elemets in Skip List     */

bool skiplist::SkipSearch(int& s_value)
{
    snode* x = header;

    for (int i = level; i >= 0; i--)
    {
        while (x->forw[i] != NULL && x->forw[i]->value < s_value)
        {
            x = x->forw[i];
        }
    }
    x = x->forw[0];
    return x != NULL && x->value == s_value;
}
void SkipPush(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void SkipMemory() {
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

    cout << "\nTime taken by function:" << duration.count() << "microseconds" << endl;
}
int SkipLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void InsertSKIP() {
    int n;
    skiplist ss;
    auto start = high_resolution_clock::now();
    cout << "Enter the element to be inserted: ";

    cin >> n;

    ss.InsertSkip(n);

    if (ss.SkipSearch(n))

        cout << "Element Inserted" << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void DeleteSKIP() {
    int n;
    skiplist ss;
    auto start = high_resolution_clock::now();
    cout << "Enter the element to be deleted: ";
    cin >> n;
    if (!ss.SkipSearch(n))
    {
        cout << "Element not found" << endl;
    }

    ss.DeleteSkip(n);

    if (!ss.SkipSearch(n)) {
        cout << "Element Deleted" << endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void ListSKIP() {
    skiplist ss;
    auto start = high_resolution_clock::now();
    cout << "The List is: ";
    ss.ListSkip();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void SkipSEARCH() {
    int n;
    skiplist ss;
    auto start = high_resolution_clock::now();
    cout << "Enter the element to be searched: ";
    cin >> n;
    if (ss.SkipSearch(n)) {
        cout << "Element " << n << " is in the list" << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}
void SkipLENGHT() {
    Node* head = NULL;
    auto start = high_resolution_clock::now();
    SkipPush(&head, 6);
    SkipPush(&head, 7);
    SkipPush(&head, 1);
    SkipPush(&head, 4);
    cout << "\ncount of node is " << SingleLength(head);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nTime taken by function:" << duration.count() << " microseconds" << endl;
}