#include "File.hpp"

#include <fstream>
#include <filesystem>
#include <cstdint>
#include <iomanip>
#include <iostream>

File::File(const std::string path)
{
    filePath = path;
    std::filesystem::path inputFilePath{filePath};
    auto length = std::filesystem::file_size(inputFilePath);	

    f = new std::ifstream(filePath, std::ios_base::binary);
}

File::~File(){
    f->close();
    delete f;
}

void File::write(std::vector<uint8_t> &data, uint32_t size, std::string name) 
{ 
    std::ofstream f;
    f.open(name, std::ios::binary | std::ios::out);

    for(auto it : data)
        f.write(reinterpret_cast<const char*>(&it), sizeof(it));

    f.close();
}  

void File::read(std::vector<uint8_t> &data, uint32_t size) 
{ 
    f->read(reinterpret_cast<char*>(data.data()), size); 
}  

void File::seek(uint32_t offset)
{
    f->seekg(offset, std::ios::beg);
}

bool File::isOpen() 
{ 
    return f->is_open();
}  

uint32_t File::intLittleEndian(std::vector<uint8_t> v, uint32_t start, uint32_t end)
{
    uint32_t res = 0;

    while (end-- > start)
    {
        res = (res << 8) + v[end];
    }

    return res;
}

void File::printBytes(const std::vector<uint8_t> &data)
{
    for(auto it : data )
        std::cout << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << static_cast< unsigned >(it) << " ";

    std::cout << std::endl;
}