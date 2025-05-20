#ifndef TEXTURE_H
#define TEXTURE_H
  
#include <fstream>
#include <cstdint>


class Texture
{
public:
    uint32_t dataSize;
    uint32_t chunkSize;
    uint32_t chunkFlag;
    uint32_t width;
    uint32_t height;

    uint32_t colors;

    uint8_t* pixels;
    uint8_t* pals;
    bool readPixel;

    Texture(const std::string path);

    void process();
    uint8_t* rgba32(uint32_t rawPixel);


private:
    std::ifstream *f; //bitstream bs
    std::string filePath;
};

#endif