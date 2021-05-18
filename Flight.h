#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include "Record.h"
#include "Customer.h"

class Flight : public Record {
private:
    std::string id;
    int size = 0;

    // seats is a dynamically-allocated array with each element being a pointer to a Customer class
    // element seats[i] stores a pointer to the Customer object that occupies seat number i, or nullptr if that seat is unoccupied
    // note that the Flight class does not 'own' these Customer objects, so we do not delete them in the destructor
    Customer **seats = nullptr;

    static void quickSort(Customer **arr, int lo, int hi); // private helper function to sort Customers
public:
    Flight(const std::string &id) : id(id) {}; // leaves seats uninitialized
    Flight(const std::string &id, int size);
    ~Flight() { delete[] seats; /*works even if seats is still nullptr*/ } // 1 of 3
    Flight& operator=(const Flight &rhs); // 2 of 3
    Flight(const Flight &f); // 3 of 3

    int compare(const Record *that) const override;
    void save(std::ofstream &fout) const override;
    void load(std::ifstream &fin) override;
    Record* duplicateType() const override { return new Flight("arbitrary"); };

    inline int getSize() const { return size; }
    Customer* getSeat(int i) const;
    inline std::string getId() const { return id; }

    void setSeat(int i, Customer *c);
    // don't want setters for id or size

    std::string toString(bool showOccupiedOnly) const;
    std::string toSortedString() const;
};

#endif // FLIGHT_H
