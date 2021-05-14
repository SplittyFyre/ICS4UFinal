#ifndef RBNODE_H
#define RBNODE_H

#include <cstdlib>
#include <fstream>
#include <functional>
#include "Record.h"
#include "EasySaveLoad.h"

#define BLACK 0
#define RED 1

class RBNode : public EasySaveLoad {
    friend class RBTree; // only allow RBTree to access these complicated functions
private: // even the constructors are private, which is good since this class should only be used by RBTree
    Record *data;
    RBNode *left = nullptr, *right = nullptr;
    int8_t colour;

    RBNode(Record *data, int8_t colour) : data(data), colour(colour) {}
    ~RBNode(); // 1 of 3
    // to avoid unwanted and possibly dangerous behaviour, disallow these:
    RBNode& operator=(const RBNode &rhs) = delete; // 2 of 3
    RBNode(const RBNode &rhs) = delete; // 3 of 3

    // helper functions for convenience:
    void flipColours();
    static bool isRed(RBNode *node);

    // functions which maintain red-black tree structure:
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

    // this function takes in a function which returns void and takes and argument of Record*
    // forEach then runs the provided function for each Record, passing that Record as the argument
    void forEach(const std::function<void(Record*)> &func);
};

#endif // RBNODE_H
