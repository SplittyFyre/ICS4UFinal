#ifndef RECORD_H
#define RECORD_H

#include <fstream>
#include "EasySaveLoad.h"

// the abstract base Record class, anything inheriting from this can be stored in the RBTree
// we also inherit EasySaveLoad to provide any derived classes with helpful helper functions
class Record : public EasySaveLoad {
public:
    Record() {};
    virtual ~Record() {}; // 1 of 3
    // we dont want or need these (this class doesnt even have any variables!), so delete them:
    Record& operator=(const Record &rhs) = delete; // 2 of 3
    Record(const Record &r) = delete; // 3 of 3

    // return -1 if less than, 0 if equal, 1 if greater than
    virtual int compare(const Record *that) const = 0;

    // derived classes should return one of their own type allocated on heap (with any values)
    // used when loading objects in RBTree in order to create correct type
    virtual Record* duplicateType() const = 0;

    // force any records to allow saving and loading
    virtual void save(std::ofstream &fout) const = 0;
    virtual void load(std::ifstream &fin) = 0;
};

#endif // RECORD_H
