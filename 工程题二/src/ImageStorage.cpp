#include "ImageStorage.h"

ImageStorage::ImageStorage(int width,int height,int channels):width_(width),height_(height),
        channels_(channels),pixels_(width*height*channels){}

unsigned char& ImageStorage::at(int x, int y,int c)
{
    int index=(width_*y+x)*channels_+c;
    return pixels_[index];
}

unsigned char ImageStorage::at(int x, int y,int c)const
{
    int index=(width_*y+x)*channels_+c;
    return pixels_[index];
}