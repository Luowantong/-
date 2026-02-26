#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include "ImageStorage.h"
#include <vector>

class ImageProcess
{
public:
    ImageProcess();
    ImageStorage meanBlur(const ImageStorage& img,int kernel_size);
    int find(int x);
    void unite(int x,int y);
    ImageStorage connectedComponents(const ImageStorage& binary);
private:
    std::vector<int> parent;
};

#endif