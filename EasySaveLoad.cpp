#include "EasySaveLoad.h"

void EasySaveLoad::writeByte(std::ofstream &fout, char c) const {
    fout.write(&c, 1);
}
// use bitwise operations to extract individual bytes from int and write them:
void EasySaveLoad::writeInt(std::ofstream &fout, int i) const {
    char c[4];
    c[0] = i & 0xff;
    c[1] = (i >> 8) & 0xff;
    c[2] = (i >> 16) & 0xff;
    c[3] = (i >> 24) & 0xff;
    fout.write(c, 4);
}
void EasySaveLoad::writeString(std::ofstream &fout, const std::string &s) const {
    writeInt(fout, s.length()); // write length of string first
    fout.write(s.c_str(), s.length()); // write every char in the string
}

char EasySaveLoad::readByte(std::ifstream &fin) {
    char c;
    fin.read(&c, 1);
    return c;
}
// use bitwise operations to combine individual bytes to an int:
int EasySaveLoad::readInt(std::ifstream &fin) {
    char c[4];
    fin.read(c, 4);
    int i = 0;
    for (int j = 3; j >= 0; j--) {
        i <<= 8;
        i |= static_cast<unsigned char>(c[j]);
    }
    return i;
}
std::string EasySaveLoad::readString(std::ifstream &fin) {
    int len = readInt(fin);
    std::string s;
    for (int i = 0; i < len; i++) s.push_back(readByte(fin));
    return s;
}
