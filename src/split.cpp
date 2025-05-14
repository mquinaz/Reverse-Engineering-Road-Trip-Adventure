#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <cstring>
#include <algorithm>

uint32_t intLittleEndian(std::vector<uint8_t> v, int start, int end)
{
    uint32_t res = 0;

    while (end-- > start)
    {
        res = (res << 8) + v[end];
    }

    return res;
}

std::vector<uint8_t> readFileHeader(const char* name, uint32_t size, int offset = 0)
{
    std::filesystem::path inputFilePath{name};
    auto length = std::filesystem::file_size(inputFilePath);
    if (length == 0)
    {
        return {};
    }

    std::ifstream f(name, std::ios_base::binary);

    if (!f)
    {
        std::cerr << "Failed to open file " << name << std::endl;
        return {};
    }

    f.seekg(offset, std::ios::beg);

    if (!f)
    {
        std::cerr << "Error occurred during reading " << name << std::endl;
        return {};
    }

    std::vector<uint8_t> buffer(size);
    f.read(reinterpret_cast<char*>(buffer.data()), size); 
    f.close();

    return buffer;
}

void printBytes(const std::vector<uint8_t> data)
{
    for(auto it : data )
        std::cout << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << static_cast< unsigned >(it) << " ";

    std::cout << std::endl;
}

int main()
{
    std::vector<uint8_t> data = readFileHeader("/run/media/quinaz/ROAD_TRIP_ADVENTURE/car0/q00.bin", 48);

    printBytes(data);

    std::vector<uint32_t> offsets;

    for(int i=0;i<48;i+=4)
    {
        uint32_t aux2 = intLittleEndian(data, i, i + 4);
        offsets.push_back(aux2);
    }
    
    for(auto it : offsets)
        std::cout << std::dec << it << std::endl;

    
    for(int i=0;i<7;i++)
    {
        std::vector<uint8_t> data2 = readFileHeader("/run/media/quinaz/ROAD_TRIP_ADVENTURE/car0/q00.bin", offsets[i+1] - offsets[i], offsets[i]);

        std::cout << offsets[i] << " " << offsets[i+1] - offsets[i] << " : " << data2.size() << std::endl;
        //printBytes(data2);

        std::ofstream f;
        f.open("/home/quinaz/Desktop/road trip/result/q00_" + std::to_string(i + 1) + ".bin", std::ios::binary | std::ios::out);

        for(auto it : data2)
            f.write(reinterpret_cast<const char*>(&it), sizeof(it));

        f.close();
    }

}