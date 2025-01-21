# Customized-Collection-Framework-of-Data-Structures

This repository contains a comprehensive collection of data structures and algorithms implemented in C++. It covers singly and doubly linked lists, circular linked lists, stacks, queues, binary search trees, and various sorting and searching algorithms. The code is written with templates for reusability and generic programming.

---

## Features

### Data Structures
- **Singly Linear Linked List**
- **Doubly Circular Linked List**
- **Doubly Linear Linked List**
- **Singly Circular Linked List**
- **Stack**
- **Queue**
- **Binary Search Tree (BST)**

### Algorithms
- **Searching**: Linear Search, Bi-Directional Search, Binary Search
- **Sorting**: Bubble Sort, Efficient Bubble Sort, Selection Sort, Insertion Sort

---

## Getting Started

### Prerequisites
- A C++ compiler (e.g., GCC)
- Basic understanding of C++ templates and pointers

### Compilation
To compile the code, use the following command:
```bash
g++ collection.cpp -o Myexe
```

### Execution
To execute the code, use the following command:
```bash
Myexe.exe
```

# Project Structure
## Files
- collection.cpp: Contains the implementation of all data structures and algorithms.

## Classes and Templates
Each data structure or algorithm is encapsulated in a class, ensuring modularity and reusability.
 - SinglyLL<T>
 - DoublyLL<T>
 - SinglyCL<T>
 - DoublyCL<T>
 - Stack<T>
 - Queue<T>
 - BinarySearchTree<T>
 - ArrayX<T>

# Usage
## Example
Here is an example of using Singly Linear Linked List:
```
#include "collection.cpp"
using namespace std;

int main()
{
    SinglyLL<int> *iobj = new SinglyLL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout << "Number of elemensts are : " << iRet << endl;

    return 0;
}
```
### Compilation
To compile the code, use the following command:
```bash
g++ collection.cpp collectionUse.cpp -o Myexe
```

### Execution
To execute the code, use the following command:
```bash
Myexe.exe
```

# License
This project is licensed under the MIT License. See the LICENSE file for details.

# Author
Gaurav Mahadev Shinde
