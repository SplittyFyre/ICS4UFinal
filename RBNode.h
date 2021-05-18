#ifndef RBNODE_H
#define RBNODE_H

#include <cstdlib>
#include <fstream>
#include <functional>
#include "Record.h"
#include "EasySaveLoad.h"

class RBNode : public EasySaveLoad {
    friend class RBTree; // only allow RBTree to access these complicated functions
private: // even the constructors are private since this class should only be used by RBTree
    Record *data;
    RBNode *left = nullptr, *right = nullptr;
    int8_t colour;

    static const int8_t BLACK, RED; // constants for the two different colours

    RBNode(Record *data, int8_t colour) : data(data), colour(colour) {}
    ~RBNode(); // 1 of 3

    // to avoid unwanted and possibly dangerous behaviour, disallow these:
    RBNode& operator=(const RBNode &rhs) = delete; // 2 of 3
    RBNode(const RBNode &rhs) = delete; // 3 of 3

    // helper functions for convenience:
    void flipColours();
    static bool isRed(RBNode *node);

    /*
        Red Black trees are a special type of binary search tree (bst for short)
        firstly, red black trees must meet the requirements of a BST, which are:
        - each node has at most two children (a left child and a right child)
        - nodes smaller than x must be in x's left subtree, and nodes larger than x must be in x's right subtree
        in addition, the red black tree has extra requirements, which are:
        - each node is coloured either red or black
        - the root node is always black
        - every path from the root to any leaf node must contain the same number of black nodes
        - no two red nodes can be adjacent in the tree
        all of these requirements combined together form what is called:
        the red black tree invariant
        the invariant guarantees that the tree will be balanced, which means that insertion, deletion, and searching
        can all be done in O(log n) complexity
        however, modification operations can often break the invariant, which means that after each modification,
        we must check if the invariant has been violated, and restore the invariant if needed
    */

    // utility functions which are used to maintain the invariant:
    // (more info in .cpp file)
    static RBNode* rotateLeft(RBNode *h);
    static RBNode* rotateRight(RBNode *h);
    static RBNode* balance(RBNode *h);
    static RBNode* moveRedLeft(RBNode *h);
    static RBNode* moveRedRight(RBNode *h);

    // main operations:
    static RBNode* insert(RBNode *h, Record *data);
    static RBNode* erase(RBNode *h, Record *data);
    static RBNode* eraseMin(RBNode *h);
    static RBNode* findMin(RBNode *h);
    static RBNode* find(RBNode *h, Record *data);
    void save(std::ofstream &fout) const;
    void load(std::ifstream &fin, Record *type); // type is used to create correct subclass of Record

    // the forEach function takes another function called func, and runs func for each Record stored in the tree
    // func must return void and take a Record* as an argument
    void forEach(const std::function<void(Record*)> &func);
};

#endif // RBNODE_H
