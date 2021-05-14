#ifndef TEST_H
#define TEST_H

#include "Record.h"

class Test : public Record {
public:
    int val;
    Test(int val) : val(val) {}
    ~Test() {}
    int compare(const Record *that) const override {
        const Test *t = dynamic_cast<const Test*>(that);
        if (val < t->val) return -1;
        else if (val > t->val) return 1;
        else return 0;
    }

    void save(std::ofstream &fout) override {};
    void load(std::ifstream &fin) override {};
};

#endif // TEST_H