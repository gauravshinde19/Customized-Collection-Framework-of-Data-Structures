#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////
//
// Code of Singly Linear
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
private:
    struct nodeSL<T> *First;
    int iCount;

public:
    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout << "Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> *temp = First;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> *newn = NULL;

    newn = new nodeSL<T>; // malloc

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> *newn = NULL;
    struct nodeSL<T> *temp = First;

    newn = new nodeSL<T>; // malloc

    newn->data = No;
    newn->next = NULL;

    if (First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> *newn = NULL;
    int i = 0;
    struct nodeSL<T> *temp;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> *temp = First;

    if (First == NULL)
    {
        cout << "LL is empty\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> *temp = First;

    if (First == NULL)
    {
        cout << "LL is empty\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> *temp1;
    struct nodeSL<T> *temp2;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Circular
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
private:
    struct nodeDC<T> *First;
    struct nodeDC<T> *Last;
    int iCount;

public:
    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Linked List is emprty\n";
        return;
    }

    cout << "<=> ";
    do
    {
        cout << "| " << First->data << " | <=> ";
        First = First->next;
    } while (Last->next != First);

    cout << "\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC<T> *newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC<T> *newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last->next = First;
    First->prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC<T> *temp = NULL;
    struct nodeDC<T> *newn = NULL;

    int i = 0;

    if (iPos < 1 || iPos > iCount + 1)
    {
        cout << "Invalid postion\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else // More than one node
    {
        First = First->next;
        delete Last->next;
        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if (First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else // More than one node
    {
        Last = Last->prev;
        delete First->prev;

        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> *temp = NULL;

    int i = 0;

    if (iPos < 1 || iPos > iCount)
    {
        cout << "Invalid postion\n";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Doubly Linear
//
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
private:
    struct nodeDL<T> *First;
    int iCount;

public:
    DoublyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL<T> *temp = First;

    if (First == NULL)
    {
        cout << "Linked List is emprty\n";
        return;
    }
    cout << "<=> ";
    while (temp != NULL)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> *newn = NULL;
    newn = new struct nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> *newn = NULL;
    struct nodeDL<T> *temp = NULL;
    newn = new struct nodeDL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }

    iCount++;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    struct nodeDL<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "Element cannot be deleted as LinkedList is empty\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        delete temp;
    }

    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "Element cannot be deleted as LinkedList is empty\n";
        return;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    struct nodeDL<T> *newn = NULL;
    struct nodeDL<T> *temp = NULL;
    newn = new struct nodeDL<T>;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid Position\n";
        return;
    }
    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == (iCount + 1))
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for (i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeDL<T> *temp = NULL;
    // struct nodeDL <T> * temp2 = NULL;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid Position\n";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for (i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }

    iCount--;
}

/////////////////////////////////////////////////////////////
//
// Code of Singly Circular
//
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};

template <class T>
class SinglyCircularLL
{
private:
    struct nodeSC<T> *First;
    struct nodeSC<T> *Last;
    int iCount;

public:
    SinglyCircularLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyCircularLL<T>::SinglyCircularLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCircularLL<T>::Display()
{
    if (First == NULL && Last == NULL)
    {
        cout << "Linked List is emprty\n";
        return;
    }

    cout << "-> ";
    do
    {
        cout << "| " << First->data << " | -> ";
        First = First->next;
    } while (Last->next != First);

    cout << "\n";
}

template <class T>
int SinglyCircularLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCircularLL<T>::InsertFirst(T No)
{
    struct nodeSC<T> *newn = NULL;

    newn = new struct nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;

    iCount++;
}

template <class T>
void SinglyCircularLL<T>::InsertLast(T No)
{
    struct nodeSC<T> *newn = NULL;

    newn = new struct nodeSC<T>;

    newn->data = No;
    newn->next = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;

    iCount++;
}

template <class T>
void SinglyCircularLL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    struct nodeSC<T> *newn = NULL;
    struct nodeSC<T> *temp = NULL;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid Position\n";
    }
    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == (iCount + 1))
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new struct nodeSC<T>;
        newn->data = No;
        newn->next = NULL;

        for (i = 1; i < (iPos - 1); i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyCircularLL<T>::DeleteFirst()
{
    if (First == NULL && Last == NULL)
    {
        return;
    }
    else if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCircularLL<T>::DeleteLast()
{
    if (First == NULL)
    {
        cout << "LL is empty" << endl;
        return;
    }

    if (First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        struct nodeSC<T> *temp = First;

        while (temp->next != Last)
        {
            temp = temp->next;
        }

        delete Last;

        Last = temp;
        Last->next = First;
    }

    iCount--;
}

template <class T>
void SinglyCircularLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSC<T> *temp1 = NULL;
    struct nodeSC<T> *temp2 = NULL;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid Position\n";
        return;
    }
    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 1; i < (iPos - 1); i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////
//
// Code of Stack
//
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <class T>
struct nodeST
{
    T data;
    struct nodeST *next;
};

template <class T>
class Stack
{
private:
    struct nodeST<T> *First;
    int iCount;

public:
    Stack();

    void Display();
    int Count();

    void Push(T No);
    int Pop();
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Display()
{
    cout << "Elements of stack are : \n";
    struct nodeST<T> *temp = First;

    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No)
{
    struct nodeST<T> *newn = NULL;

    newn = new struct nodeST<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
int Stack<T>::Pop()
{
    int iValue = 0;
    struct nodeST<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "Unable to pop the element as stack is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }

    return iValue;
}

/////////////////////////////////////////////////////////////
//
// Code of Queue
//
/////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <class T>
struct nodeQU
{
    int data;
    struct nodeQU *next;
};

template <class T>
class Queue
{
private:
    struct nodeQU<T> *First;
    int iCount;

public:
    Queue();

    void Display();
    int Count();

    void EnQueue(T No);
    int DeQueue();
};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Display()
{
    cout << "Elements of Queue are : \n";
    struct nodeQU<T> *temp = First;

    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n";
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQU<T> *newn = NULL;
    struct nodeQU<T> *temp = NULL;

    newn = new struct nodeQU<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    iCount++;
}

template <class T>
int Queue<T>::DeQueue()
{
    int iValue = 0;
    struct nodeQU<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "Unable to remove the element as queue is empty\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }

    return iValue;
}

/////////////////////////////////////////////////////////////
//
// Code of Binary Search Tree (BST)
//
/////////////////////////////////////////////////////////////

template <class T>
struct nodeBST
{
    T data;
    struct nodeBST *left;
    struct nodeBST *right;
};

template <class T>
class BinarySearchTree
{
private:
    struct nodeBST<T> *root;

public:
    BinarySearchTree(); // Constructor

    void Insert(T no);
    bool Search(T no);
    void InOrderTraversal();   // To display elements in sorted order
    void PreOrderTraversal();  // Pre-order: root-left-right
    void PostOrderTraversal(); // Post-order: left-right-root

private:
    void InsertRec(struct nodeBST<T> **head, T no);
    bool SearchRec(struct nodeBST<T> *head, T no);
    void InOrderRec(struct nodeBST<T> *head);
    void PreOrderRec(struct nodeBST<T> *head);
    void PostOrderRec(struct nodeBST<T> *head);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = NULL;
}

template <class T>
void BinarySearchTree<T>::Insert(T no)
{
    InsertRec(&root, no);
}

template <class T>
void BinarySearchTree<T>::InsertRec(struct nodeBST<T> **head, T no)
{
    if (*head == NULL)
    {
        *head = new nodeBST<T>;
        (*head)->data = no;
        (*head)->left = NULL;
        (*head)->right = NULL;
    }
    else if (no < (*head)->data)
    {
        InsertRec(&((*head)->left), no);
    }
    else if (no > (*head)->data)
    {
        InsertRec(&((*head)->right), no);
    }
}

template <class T>
bool BinarySearchTree<T>::Search(T no)
{
    return SearchRec(root, no);
}

template <class T>
bool BinarySearchTree<T>::SearchRec(struct nodeBST<T> *head, T no)
{
    if (head == NULL)
    {
        return false;
    }
    else if (head->data == no)
    {
        return true;
    }
    else if (no < head->data)
    {
        return SearchRec(head->left, no);
    }
    else
    {
        return SearchRec(head->right, no);
    }
}

template <class T>
void BinarySearchTree<T>::InOrderTraversal()
{
    InOrderRec(root);
}

template <class T>
void BinarySearchTree<T>::InOrderRec(struct nodeBST<T> *head)
{
    if (head != NULL)
    {
        InOrderRec(head->left);
        cout << "| " << head->data << " | -> ";
        InOrderRec(head->right);
    }
}

template <class T>
void BinarySearchTree<T>::PreOrderTraversal()
{
    PreOrderRec(root);
}

template <class T>
void BinarySearchTree<T>::PreOrderRec(struct nodeBST<T> *head)
{
    if (head != NULL)
    {
        cout << "| " << head->data << " | -> ";
        PreOrderRec(head->left);
        PreOrderRec(head->right);
    }
}

template <class T>
void BinarySearchTree<T>::PostOrderTraversal()
{
    PostOrderRec(root);
}

template <class T>
void BinarySearchTree<T>::PostOrderRec(struct nodeBST<T> *head)
{
    if (head != NULL)
    {
        PostOrderRec(head->left);
        PostOrderRec(head->right);
        cout << "| " << head->data << " | -> ";
    }
}

/////////////////////////////////////////////////////////////
//
// Searching and sorting algorithms
//
/////////////////////////////////////////////////////////////

template <class T>
class ArrayX
{
public:
    T *Arr;
    int iSize;

    ArrayX(int Value);
    ~ArrayX();

    void Accept();
    void Display();

    bool LinearSearch(T Value);
    bool BiDirectionalSearch(T Value);
    bool BinarySearch(T Value);

    void BubbleSort();
    void BubbleSortEfficient();
    void SelectionSort();
    void InsertionSort();
};

template <class T>
ArrayX<T>::ArrayX(int Value)
{
    this->iSize = Value;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T>::~ArrayX()
{
    delete[] Arr;
}

template <class T>
void ArrayX<T>::Accept()
{
    int i = 0;

    cout << "Entered elements :\n";
    for (i = 0; i < iSize; i++)
    {
        cin >> Arr[i];
    }
}

template <class T>
void ArrayX<T>::Display()
{
    int i = 0;

    // cout << "Entered elements are :\n";
    for (i = 0; i < iSize; i++)
    {
        cout << Arr[i] << "\t";
    }
    cout << "\n";
}

template <class T>
bool ArrayX<T>::LinearSearch(T Value)
{
    bool flag = false;
    int i = 0;

    for (i = 0; i < iSize; i++)
    {
        if (Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T>::BiDirectionalSearch(T Value)
{
    bool flag = false;
    int iStart = 0;
    int iEnd = 0;

    for (iStart = 0, iEnd = iSize - 1; iStart <= iEnd; iStart++, iEnd--)
    {
        if ((Arr[iStart] == Value) || (Arr[iEnd] == Value))
        {
            flag = true;
            break;
        }
    }

    return flag;
}

template <class T>
bool ArrayX<T>::BinarySearch(T Value)
{
    int iStart = 0;
    int iEnd = iSize - 1;
    int iMid = 0;
    bool flag = false;

    while (iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if ((Arr[iMid] == Value) || (Arr[iStart] == Value) || (Arr[iEnd] == Value))
        {
            flag = true;
            break;
        }
        else if (Value > Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if (Value < Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }

    return flag;
}

template <class T>
void ArrayX<T>::BubbleSort()
{
    T temp;
    int i = 0, j = 0;

    for (i = 0; i < iSize - 1; i++) // outer
    {
        for (j = 0; j < iSize - 1 - i; j++) // inner
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }

        cout << "\nArray after pass : " << i + 1 << "\n";
        Display();
    }
}

template <class T>
void ArrayX<T>::BubbleSortEfficient()
{
    T temp;
    int i = 0, j = 0;
    bool flag = true;

    for (i = 0; i < iSize - 1 && flag == true; i++) // outer
    {
        flag = false;

        for (j = 0; j < iSize - 1 - i; j++) // inner
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
                flag = true;
            }
        }

        cout << "\nArray after pass : " << i + 1 << "\n";

        Display();
    }
}

template <class T>
void ArrayX<T>::SelectionSort()
{
    int i = 0, j = 0, min_index = 0;
    T temp;

    for (i = 0; i < iSize - 1; i++) // outer
    {
        min_index = i;

        for (j = i + 1; j < iSize; j++) // inner
        {
            if (Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }

        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

template <class T>
void ArrayX<T>::InsertionSort()
{
    int i = 0, j = 0;
    T selected;

    for (i = 1; i < iSize; i++) // outer
    {
        for (j = i - 1, selected = Arr[i]; (j >= 0) && (Arr[j] > selected); j--) // inner
        {
            Arr[j + 1] = Arr[j];
        }

        Arr[j + 1] = selected;
    }
}