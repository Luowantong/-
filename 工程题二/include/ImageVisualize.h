#ifndef IMAGEVISUALIZE_H
#define IMAGEVISUALIZE_H

#include "ImageStorage.h"
#include <string>

class ImageVisualize
{
public:
    void print(const ImageStorage& img);
    void savefile(const ImageStorage& img,std::string filename);
};

#endif