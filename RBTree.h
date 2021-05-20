#ifndef RBTREE_H
#define RBTREE_H

#include "RBNode.h"
#include "EasySaveLoad.h"
#include <fstream>

/*
    Red Black trees are a special type of binary search tree (bst for short)
    Firstly, red black trees must meet the requirements of a BST, which are:
    - each node has at most two children (a left child and a right child)
    - all nodes smaller than x must be in x's left subtree, and all nodes larger than x must be in x's right subtree

    These requirements allow us to search for a value in the tree by:
    traversing into a node's left subtree if the target value is less than the node's value
    traversing into a node's right subtree if the target value is greater than the node's value
    otherwise the target value is found at the current node

    In addition, the red black tree has extra requirements, which are:
    - each node is coloured either red or black
    - the root node is always black
    - every path from the root to any leaf node must contain the same number of black nodes
    - red nodes cannot have red children or a red parent
    These extra requirements combined together form what is called:
    the red black tree invariant

    The invariant keeps the tree mostly balanced, which means that operations such as insertion, deletion, and finding
    can all be done in O(log N) time complexity, where N is the number of nodes in the tree.
    This is a big improvement over normal BSTs, which have worst-cae complexities of O(N)

    However, modification operations can often break the invariant, which means that after each modification,
    we must check if the invariant has been violated, and restore the invariant if needed
*/

class RBTree : public EasySaveLoad {
private:
    RBNode *root = nullptr; // the root node of the tree
public:
    RBTree() {};
    ~RBTree() { delete root; } // 1 of 3
    // to avoid dangerous behaviour, disallow copying:
    RBTree& operator=(const RBTree &rhs) = delete; // 2 of 3
    RBTree(const RBTree &rhs) = delete; // 3 of 3

    // for the following functions, most of the work is offloaded to RBNode functions:

    void insert(Record *data); // add a Record to the red-black tree
    void erase(Record *data); // erase a Record from the red-black tree
    bool contains(Record *data); // check if a Record exists within the red-black tree

    // the data argument is an 'incomplete' record, which only has enough information to compare with other Records
    // function will return a 'complete' record, where returned_record->compare(data) == 0
    Record* get(Record *data);

    void save(std::ofstream &fout) const;
    void load(std::ifstream &fin, Record *type); // type is used to create correct subclass of Record

    void forEach(const std::function<void(Record*)> &func);
};

#endif // RBTREE_H
