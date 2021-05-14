#ifndef EASYSAVELOAD_H
#define EASYSAVELOAD_H

#include <fstream>
#include <string>

// a shell of a class which provides protected helper functions to make saving and loading more convenient
class EasySaveLoad {
public:
    EasySaveLoad() {};
    virtual ~EasySaveLoad() {}; // 1 of 3
    // we dont want or need these, so delete them:
    EasySaveLoad& operator=(const EasySaveLoad &rhs) = delete; // 2 of 3
    EasySaveLoad(const EasySaveLoad &esl) = delete; // 3 of 3

protected: // children can use these functions for convenience
    void writeByte(std::ofstream &fout, char c) const;
    void writeInt(std::ofstream &fout, int i) const;
    void writeString(std::ofstream &fout, const std::string &s) const;

    char readByte(std::ifstream &fin);
    int readInt(std::ifstream &fin);
    std::string readString(std::ifstream &fin);
};

#endif // EASYSAVELOAD_H
