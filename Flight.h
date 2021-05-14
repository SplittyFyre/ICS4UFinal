#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include "Record.h"
#include "Customer.h"

class Flight : public Record {
private:
    std::string id;
    int size;
    Customer **seats = nullptr; // element is null if empty, otherwise points to customer who occupies it
    // note that this class does not own the Customer*, so we don't delete them in the destructor

    static void quickSort(Customer **arr, int lo, int hi); // private helper function to sort Customers
public:
    Flight(const std::string &id) : id(id) {}; // leaves seats uninitialized
    Flight(const std::string &id, int size);
    ~Flight() { delete[] seats; /*works even if seats is still nullptr*/ }

    int compare(const Record *that) const override;
    void save(std::ofstream &fout) const override;
    void load(std::ifstream &fin) override;
    Record* duplicateType() const override { return new Flight("arbitrary"); };

    inline int getSize() const { return size; }
    inline Customer* getSeat(int i) const { return seats[i]; }
    inline void setSeat(int i, Customer *c) { seats[i] = c; }
    std::string toString(bool showOccupiedOnly) const;
    std::string toSortedString() const;
};

#endif // FLIGHT_H
