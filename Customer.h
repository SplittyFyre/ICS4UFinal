#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Record.h"

class Customer : public Record {
private:
    std::string name, address, phonenum, flightid; // default initiated to empty string
    int seatnum = -1;
public:
    Customer() {} // default constructor
    // this constructor makes a 'key' object, only taking enough information to allow the object to compare with others in RBTree
    Customer(const std::string &n, const std::string &pn) : name(n), phonenum(pn) {}
    // this is full constructor:
    Customer(const std::string &n, const std::string &a, const std::string &pn, const std::string &flightid, int seatnum) :
        name(n), address(a), phonenum(pn), flightid(flightid), seatnum(seatnum) {}
    // rule of three: none of the three (copy assign, copy construct, destruct) are needed

    inline void setName(const std::string &n) { name = n; }
    inline void setAddress(const std::string &a) { address = a; }
    inline void setPhoneNumber(const std::string &pn) { phonenum = pn; }
    inline void setFlightId(const std::string &id) { flightid = id; }
    inline void setSeatNum(int i) { seatnum = i; }

    inline std::string getName() const { return name; }
    inline std::string getAddress() const { return address; }
    inline std::string getPhoneNumber() const { return phonenum; }
    inline std::string getFlightId() const { return flightid; }
    inline int getSeatNum() const { return seatnum; }

    int compare(const Record *that) const override;
    Record* duplicateType() const override { return new Customer(); }
    void save(std::ofstream &fout) const override;
    void load(std::ifstream &fin) override;

    std::string toString() const;
};

#endif // CUSTOMER_H
