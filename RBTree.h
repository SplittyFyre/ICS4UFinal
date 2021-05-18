#ifndef RBTREE_H
#define RBTREE_H

#include "RBNode.h"
#include "EasySaveLoad.h"
#include <fstream>

class RBTree : public EasySaveLoad {
private:
    RBNode *root = nullptr;
public:
    RBTree() {};
    ~RBTree() { delete root; } // 1 of 3
    // to avoid dangerous behaviour, disallow copying:
    RBTree& operator=(const RBTree &rhs) = delete; // 2 of 3
    RBTree(const RBTree &rhs) = delete; // 3 of 3

    void insert(Record *data);
    void erase(Record *data);
    bool contains(Record *data);

    // the data argument is an 'incomplete' record, which only has enough information to compare with other Records
    // function will return a 'complete' record, where returned_record->compare(data) == 0
    Record* get(Record *data);

    void save(std::ofstream &fout) const;
    void load(std::ifstream &fin, Record *type); // type is used to create correct subclass of Record

    void forEach(const std::function<void(Record*)> &func);
};

#endif // RBTREE_H
