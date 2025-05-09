#include <iostream>
#include <fstream>
#include <vector>
#include <filesystem>

std::vector<std::byte> readFileData(const std::string& name)
{
    std::filesystem::path inputFilePath{name};
    auto length = std::filesystem::file_size(inputFilePath);
    if (length == 0) {
        return {};  // empty vector
    }

    std::vector<std::byte> buffer(length);
    std::ifstream inputFile(name, std::ios_base::binary);
    inputFile.read(reinterpret_cast<char*>(buffer.data()), length);
    inputFile.close();

    return buffer;
}

void printBytes(const std::vector<std::byte> data)
{
    for(auto it : data )
        std::cout << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << static_cast< unsigned >(it) << " ";
}

int main()
{
    std::vector<std::byte> data = readFileData("/run/media/quinaz/ROAD_TRIP_ADVENTURE/car0/q00.bin");

    printBytes(data);


    //std::ifstream infile;
    //infile.open("/run/media/quinaz/ROAD_TRIP_ADVENTURE/car0/", std::ios::binary | std::ios::in);


    
}
