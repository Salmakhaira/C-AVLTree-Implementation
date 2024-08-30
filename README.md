# C-AVLTree-Implementation

# AVLTree-Implementation

Project Overview
This project is an implementation of an AVL Tree, a self-balancing binary search tree where the height difference between the left and right subtrees of any node is no more than one. This ensures that the tree remains balanced, providing efficient operations for insertion, deletion, and searching with a time complexity of O(log n).

Key Features
- Insertion: Automatically balances the tree after inserting a new node.
- Deletion: Removes a node and rebalances the tree to maintain its properties.
- Rotations: Includes left, right, left-right, and right-left rotations to restore balance.
- Traversal Methods: Supports pre-order, in-order, and post-order traversal of the tree.
  
Project Structure
- Node Structure: Each node contains a value (num), height, and pointers to its left and right children.
- Balance Factor: Calculated to determine the need for tree rotation after insertion or deletion.
- Rotations: Implemented to ensure the AVL Tree remains balanced.

Usage
The project provides a simple command-line interface for inserting and deleting nodes, as well as traversing the tree in various orders.
1. Insertion
2. Deletion
3. Traversal (Preorder, Inorder, Postorder)
4. Exit

Conclusion
This AVL Tree implementation demonstrates fundamental concepts of data structures and algorithms, specifically self-balancing trees. It serves as an educational tool and a foundational codebase for further enhancements or integration into larger projects.
