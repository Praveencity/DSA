# Data Structures and Algorithms

This repository is a personal collection of C++ implementations for common Data Structures and Algorithms (DSA). It's structured by topic, with each folder containing code, sample inputs, and outputs.

## Topics Covered

This guide is arranged in a logical learning order, from foundational concepts to more advanced data structures. Click on any topic to jump directly to that section.

1.  [Basic Maths](#1-basic-maths)
2.  [Sorting Algorithms](#2-sorting_algo)
3.  [Two Pointer](#3-two-pointer)
4.  [Binary Search](#4-binary-search)
5.  [Hashing](#5-hashing)
6.  [Pre Computation](#6-pre-computation)
7.  [Linked List](#7-linked-list)
8.  [Stack & Queue](#8-stack--queue)
9.  [Binary Tree](#9-binary-tree)
10. [Graphs](#10-graphs)

---

## How to Compile & Run (VS Code)

This repository is configured with a default VS Code build task to compile and run files with I/O redirection automatically.

### 1. Setup

1.  Make sure you have a **`.vscode`** folder in the root of this project.
2.  Inside `.vscode`, ensure you have a **`tasks.json`** file.
3.  You must have **`g++`** installed and added to your system's PATH.

### 2. How to Use

1.  Open any C++ file you want to run (e.g., `Graphs/BFS/bfsBasic.cpp`).
2.  Make sure an **`input.txt`** file exists in the *same folder* as the C++ file.
3.  Press **`Ctrl+Shift+B`** (or `Cmd+Shift+B` on Mac).

This will compile the file, run the resulting `output.exe`, and feed it the `input.txt`. The program's results will be saved in the `output.txt` file in that same directory.

**Example of running a C++ file with input/output redirection:**
![VS Code Setup Example](assets/vscode_setup_example.png)

---

### 1. Basic Maths
Folder: **[Basic Maths](Basic%20Maths)** Implementations of fundamental mathematical algorithms needed for problem-solving.
* [`armstrongno.cpp`](Basic%20Maths/armstrongno.cpp)
* [`divisor.cpp`](Basic%20Maths/divisor.cpp)
* [`fibonacci.cpp`](Basic%20Maths/fibonacci.cpp)
* [`gcd.cpp`](Basic%20Maths/gcd.cpp)
* [`powerex.cpp`](Basic%20Maths/powerex.cpp)
* [`primefactor.cpp`](Basic%20Maths/primefactor.cpp)
* [`rangeprime.cpp`](Basic%20Maths/rangeprime.cpp)
* [`sieveoferatosthenes.cpp`](Basic%20Maths/sieveoferatosthenes.cpp)
* [`spf.cpp`](Basic%20Maths/spf.cpp) (Smallest Prime Factor)

### 2. Sorting_Algo
Folder: **[Sorting_Algo](Sorting_Algo)** Implementations of fundamental sorting algorithms.
* [`bubbleSort.cpp`](Sorting_Algo/bubbleSort.cpp)
* [`insertionSort.cpp`](Sorting_Algo/insertionSort.cpp)
* [`mergeSort.cpp`](Sorting_Algo/mergeSort.cpp)
* [`quickSort.cpp`](Sorting_Algo/quickSort.cpp)
* [`selectionSort.cpp`](Sorting_Algo/selectionSort.cpp)

### 3. Two Pointer
Folder: **[Two Pointer](Two%20Pointer)** Problems solved using the Two Pointer technique, often on sorted arrays.
* [`2sum.cpp`](Two%20Pointer/2sum.cpp)
* [`3sum.cpp`](Two%20Pointer/3sum.cpp)
* [`constwin.cpp`](Two%20Pointer/constwin.cpp) (Constant/Fixed sliding window)
* [`countsubarr.cpp`](Two%20Pointer/countsubarr.cpp)
* [`longsubarr.cpp`](Two%20Pointer/longsubarr.cpp) (Longest subarray with condition)
* [`q1.cpp`](Two%20Pointer/q1.cpp)
* [`totalSubarr.cpp`](Two%20Pointer/totalSubarr.cpp)

### 4. Binary Search
Folder: **[Binary Search](Binary%20Search)** Algorithms based on the Binary Search principle, which requires sorted data.
* [`hmtrotated.cpp`](Binary%20Search/hmtrotated.cpp) (Searching in a rotated array)
* [`insertBS.cpp`](Binary%20Search/insertBS.cpp) (Position to insert element)
* [`occurrence.cpp`](Binary%20Search/occurrence.cpp) (Finding first/last occurrence)
* [`rotatedBS.cpp`](Binary%20Search/rotatedBS.cpp) (Searching in a rotated array)
* [`searchConcept.cpp`](Binary%20Search/searchConcept.cpp)
* [`uplowbound.cpp`](Binary%20Search/uplowbound.cpp) (Upper and Lower Bound)

### 5. Hashing
Folder: **[Hassing](Hassing)** Techniques for fast lookups and data storage.
* [`hasharray.cpp`](Hassing/hasharray.cpp) (Hashing using arrays)
* [`hashmapset.cpp`](Hassing/hashmapset.cpp) (Using C++ STL `map` and `set`)

### 6. Pre Computation
Folder: **[Pre Computation](Pre%20Computation)** Techniques for optimizing queries by pre-calculating results (e.g., prefix sums).
* [`prefixSum.cpp`](Pre%20Computation/prefixSum.cpp) (1D Prefix Sum)
* [`prefixSum2.cpp`](Pre%20Computation/prefixSum2.cpp) (2D Prefix Sum)
* [`prefixSum3.cpp`](Pre%20Computation/prefixSum3.cpp)
* [`lonsubarr.cpp`](Pre%20Computation/lonsubarr.cpp) (Longest subarray)
* [`maxSum.cpp`](Pre%20Computation/maxSum.cpp)
* [`subSum.cpp`](Pre%20Computation/subSum.cpp)
* [`subSum2.cpp`](Pre%20Computation/subSum2.cpp)

### 7. Linked List
Folder: **[Linked List](Linked%20List)** Implementations of linear, node-based data structures.
* [`LL1D.cpp`](Linked%20List/LL1D.cpp) (Singly Linked List)
* [`LL2D.cpp`](Linked%20List/LL2D.cpp) (Doubly Linked List)

### 8. Stack & Queue
Folder: **[Stack & Queue](Stack%20%26%20Queue)** Implementations of Stack (LIFO) and Queue (FIFO) data structures.
* **[Basic Implementation](Stack%20%26%20Queue/Basic%20Implementation):**
    * [`queuewitharray.cpp`](Stack%20%26%20Queue/Basic%20Implementation/queuewitharray.cpp)
    * [`queuewithLL.cpp`](Stack%20%26%20Queue/Basic%20Implementation/queuewithLL.cpp)
    * [`stackwitharray.cpp`](Stack%20%26%20Queue/Basic%20Implementation/stackwitharray.cpp)
    * [`stackwithLL.cpp`](Stack%20%26%20Queue/Basic%20Implementation/stackwithLL.cpp)
* **[Balanced Parentheses](Stack%20%26%20Queue/Balanced%20Parentheses):**
    * [`balanceParen.cpp`](Stack%20%26%20Queue/Balanced%20Parentheses/balanceParen.cpp)
* **[Conversion](Stack%20%26%20Queue/Conversion):**
    * [`queue2stack.cpp`](Stack%20%26%20Queue/Conversion/queue2stack.cpp)
    * [`stack2queue.cpp`](Stack%20%26%20Queue/Conversion/stack2queue.cpp)
* **[Prefix, Postfix & Infix](Stack%20%26%20Queue/Prefix%2C%20Postfix%20%26%20Infix):**
    * [`infix2postfix.cpp`](Stack%20%26%20Queue/Prefix%2C%20Postfix%20%26%20Infix/infix2postfix.cpp)
    * [`infix2prefix.cpp`](Stack%20%26%20Queue/Prefix%2C%20Postfix%20%26%20Infix/infix2prefix.cpp)
    * [`postfix2infix.cpp`](Stack%20%26%20Queue/Prefix%2C%20Postfix%20%26%20Infix/postfix2infix.cpp)
    * [`postfix2prefix.cpp`](Stack%20%26%20Queue/Prefix%2C%20Postfix%20%26%20Infix/postfix2prefix.cpp)
    * [`prefix2infix.cpp`](Stack%20%26%20Queue/Prefix%2C%20Postfix%20%26%20Infix/prefix2infix.cpp)
    * [`prefix2postfix.cpp`](Stack%20%26%20Queue/Prefix%2C%20Postfix%20%26%20Infix/prefix2postfix.cpp)

### 9. Binary Tree
Folder: **[Binary Tree](Binary%20Tree)** Implementation of non-linear, hierarchical tree data structures.
* **[Basic Tree](Binary%20Tree/Basic%20Tree):**
    * [`linkedBinaryTree.cpp`](Binary%20Tree/Basic%20Tree/linkedBinaryTree.cpp) (Linked list representation)
    * [`operationInBT.cpp`](Binary%20Tree/Basic%20Tree/operationInBT.cpp) (Core operations)
* **[Binary Search Tree (BST)](Binary%20Tree/Binary%20Search%20Tree):**
    * *(Contains BST-specific algorithms)*

### 10. Graphs
Folder: **[Graphs](Graphs)** Implementations of various graph algorithms and representations.
* [`representation.cpp`](Graphs/representation.cpp) (Adjacency matrix/list)
* **[Algorithm](Graphs/Algorithm):**
    * [`bellmanFord.cpp`](Graphs/Algorithm/bellmanFord.cpp)
    * [`dijkstra.cpp`](Graphs/Algorithm/dijkstra.cpp)
    * [`dsu.cpp`](Graphs/Algorithm/dsu.cpp) (Disjoint Set Union)
    * [`floydWarshall.cpp`](Graphs/Algorithm/floydWarshall.cpp)
* **[BFS (Breadth-First Search)](Graphs/BFS):**
    * [`bfsBasic.cpp`](Graphs/BFS/bfsBasic.cpp)
    * [`knight.cpp`](Graphs/BFS/knight.cpp) (Knight's shortest path)
* **[DFS (Depth-First Search)](Graphs/DFS):**
    * [`connectedcom.cpp`](Graphs/DFS/connectedcom.cpp)
    * [`dfsBasic.cpp`](Graphs/DFS/dfsBasic.cpp)
    * [`diameter.cpp`](Graphs/DFS/diameter.cpp) (Diameter of a tree)
    * [`height&depth.cpp`](Graphs/DFS/height&depth.cpp)
    * [`iscyclic.cpp`](Graphs/DFS/iscyclic.cpp) (Detecting cycles)
    * [`lca.cpp`](Graphs/DFS/lca.cpp) (Lowest Common Ancestor)
    * [`precomputation.cpp`](Graphs/DFS/precomputation.cpp) (DFS for precomputation)
    * [`treeDfs.cpp`](Graphs/DFS/treeDfs.cpp)

## How to Use (Manual Compilation)

If not using the VS Code task, you can compile and run files manually.

**Compile a file:**
```bash
g++ filename.cpp -o filename.exe
