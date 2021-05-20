#include "Customer.h"

// compare by name first, if names are the same, break ties using phone number, no customer can have the same name AND phone#
// return -1 if less than, 0 if equal, 1 if greater than
int Customer::compare(const Record *that) const {
    const Customer *c = dynamic_cast<const Customer*>(that);
    if (name < c->name) return -1;
    else if (name > c->name) return 1;
    else {
        if (phonenum < c->phonenum) return -1;
        else if (phonenum > c->phonenum) return 1;
        else return 0;
    }
}

std::string Customer::toString() const {
    return name + ", " + address + ", " + phonenum;
}

void Customer::save(std::ofstream &fout) const {
    writeString(fout, name);
    writeString(fout, address);
    writeString(fout, phonenum);
    writeString(fout, flightid);
    writeInt(fout, seatnum);
}
void Customer::load(std::ifstream &fin) {
    name = readString(fin);
    address = readString(fin);
    phonenum = readString(fin);
    flightid = readString(fin);
    seatnum = readInt(fin);
}
