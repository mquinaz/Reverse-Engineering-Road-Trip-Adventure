#ifndef FILE_H
#define FILE_H
  
#include <fstream>
#include <vector>
#include <cstdint>


class File
{
public:
    File(const std::string path);
    ~File();

    void write(std::vector<uint8_t> &data, uint32_t size, std::string name);
    void read(std::vector<uint8_t> &data, uint32_t size);
    void seek(uint32_t offset);
    bool isOpen();
    uint32_t intLittleEndian(std::vector<uint8_t> v, uint32_t start, uint32_t end);
    void printBytes(const std::vector<uint8_t> &data);


private:
    std::ifstream *f;
    std::string filePath;
};

#endif