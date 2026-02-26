#include "ImageVisualize.h"
#include <ios>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>

void ImageVisualize::print(const ImageStorage &img)
{
    const std::string chars = " .:-=+*#%@";
    for (int y=0; y<img.getHeight(); y++) 
    {
        for (int x=0; x<img.getWidth(); x++) 
        {
            unsigned char value=img.at(x, y, 0);
            int index=value*(chars.length()-1)/255;
            std::cout<<chars[index];
        }
        std::cout<<std::endl;
    }
}

void ImageVisualize::savefile(const ImageStorage &img,std::string filename)
{
    std::ofstream file(filename,std::ios::binary);
    if (!file.is_open()) 
    {
        throw std::runtime_error("文件无法打开");
    }

    file << "P5\n";                          
    file << img.getWidth() << " " << img.getHeight() << "\n";
    file << "255\n";                          
    
    for (int y = 0; y < img.getHeight(); y++) 
    {
        for (int x = 0; x < img.getWidth(); x++) 
        {
            unsigned char val = img.at(x, y, 0); 
            file.write(reinterpret_cast<const char*>(&val), 1);
        }
    }
}