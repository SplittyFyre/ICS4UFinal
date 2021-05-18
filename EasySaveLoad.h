#ifndef EASYSAVELOAD_H
#define EASYSAVELOAD_H

#include <fstream>
#include <string>

// a base class without any data members which provides an interface for convenient read/write to disk
// it provides the interface via protected functions which any derived class can use
class EasySaveLoad {
public:
    EasySaveLoad() {};
    virtual ~EasySaveLoad() {}; // 1 of 3
    // we dont want or need these, so delete them:
    EasySaveLoad& operator=(const EasySaveLoad &rhs) = delete; // 2 of 3
    EasySaveLoad(const EasySaveLoad &esl) = delete; // 3 of 3

protected: // derived classes can use these for convenience
    void writeByte(std::ofstream &fout, char c) const;
    void writeInt(std::ofstream &fout, int i) const;
    void writeString(std::ofstream &fout, const std::string &s) const;

    char readByte(std::ifstream &fin);
    int readInt(std::ifstream &fin);
    std::string readString(std::ifstream &fin);
};

#endif // EASYSAVELOAD_H
