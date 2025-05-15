#include "File.hpp"

#include <iostream>
#include <vector>

int main()
{
    File f = File("/run/media/quinaz/ROAD_TRIP_ADVENTURE/car0/q00.bin");

    std::vector<uint8_t> header(48);
    f.read(header, 48);
    f.printBytes(header);

    std::vector<uint32_t> offsets;
    for(int i=0;i<48;i+=4)
    {
        uint32_t aux2 = f.intLittleEndian(header, i, i + 4);
        offsets.push_back(aux2);
    }
    
    for(auto it : offsets)
        std::cout << std::dec << it << std::endl;

    for(int i=0;i<7;i++)
    {
        std::vector<uint8_t> subfile(offsets[i+1] - offsets[i]);
        f.read(subfile, offsets[i+1] - offsets[i]);

        std::cout << offsets[i] << " " << offsets[i+1] - offsets[i] << " : " << subfile.size() << std::endl;
        //f.printBytes(data2);

        f.write(subfile, offsets[i+1] - offsets[i], "/home/quinaz/Desktop/road trip/result/q00_" + std::to_string(i + 1) + ".bin");
    }
    
}