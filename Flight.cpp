#include "Flight.h"

#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>

Flight::Flight(const std::string &id, int size) : id(id), size(size) {
    seats = new Customer*[size];
    memset(seats, 0, sizeof(Customer*) * size);
}

Flight& Flight::operator=(const Flight &rhs) {
    id = rhs.id;
    size = rhs.size;

    delete[] seats; // works even if its already null
    seats = nullptr;

    if (rhs.seats != nullptr) { // rhs actually has seat data
        seats = new Customer*[size];
        memcpy(seats, rhs.seats, sizeof(Customer*) * size);
    }

    return *this;
}
Flight::Flight(const Flight &f) {
    *this = f; // overloaded assignment is able to properly initialize seats memory
}

// getSeat and setSeat offer encapsulation in the form of bounds checking
Customer* Flight::getSeat(int i) const {
    if (i < 0 || i >= size) { // bounds checking
        std::cout << "Warning: attempted to access invalid seat index " << i << " on Flight of size " << size << std::endl;
        return nullptr;
    }
    return seats[i];
}
void Flight::setSeat(int i, Customer *c) {
    if (i < 0 || i >= size) { // bounds checking
        std::cout << "Warning: attempted to set invalid seat index " << i << " on Flight of size " << size << std::endl;
    }
    else seats[i] = c;
}

// return -1 if less than, 0 if equal, 1 if greater than
int Flight::compare(const Record *that) const {
    const Flight *f = dynamic_cast<const Flight*>(that);
    if (id < f->id) return -1;
    else if (id > f->id) return 1;
    else return 0;
}

void Flight::save(std::ofstream &fout) const {
    writeString(fout, id);
    writeInt(fout, size);
}
void Flight::load(std::ifstream &fin) {
    id = readString(fin);
    size = readInt(fin);
    if (seats != nullptr) delete[] seats;
    seats = new Customer*[size];
    memset(seats, 0, sizeof(Customer*) * size);
}

// show each seat as either unoccupied or print occupant information
std::string Flight::toString(bool showOccupiedOnly) const {
    std::stringstream ss;
    ss << "Flight " << id << ": \n";
    for (int i = 0; i < size; i++) {
        if (seats[i] == nullptr && showOccupiedOnly) continue;
        ss << "Seat " << i << ": ";
        if (seats[i]) ss << seats[i]->toString() << '\n';
        else ss << "Unoccupied\n";
    }
    return ss.str();
}

// show all seats, but sort them in lexicographical order of passanger names
std::string Flight::toSortedString() const {
    Customer **tmp = new Customer*[size];
    int cnt = 0;
    for (int i = 0; i < size; i++) // add and count only non-empty seats
        if (seats[i])
            tmp[cnt++] = seats[i];

    quickSort(tmp, 0, cnt - 1);

    std::stringstream ss;
    ss << "Flight " << id << ": \n";
    for (int i = 0; i < cnt; i++) {
        Customer *c = tmp[i];
        ss << "Seat " << c->getSeatNum() << ": " << c->toString() << '\n';
    }

    delete[] tmp;

    return ss.str();
}

// a simple, recursive quickSort implementation
void Flight::quickSort(Customer **arr, int lo, int hi) {
    if (lo < hi) {
        // partition array:
        Customer *pivot = arr[hi];
        int i = lo;
        for (int j = lo; j < hi; j++)
            if (arr[j]->getName() < pivot->getName())
                std::swap(arr[j], arr[i++]);
        std::swap(arr[i], arr[hi]); // swap with pivot

        int p = i;
        quickSort(arr, lo, p - 1);
        quickSort(arr, p + 1, hi);
    }
}
