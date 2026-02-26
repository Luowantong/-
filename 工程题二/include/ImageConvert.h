#ifndef IMAGECONVERT_H
#define IMAGECONVERT_H

#include "ImageStorage.h"

class ImageConvert
{
public:
    ImageConvert();
    static constexpr float RGB2GRAY_R=0.299f;
    static constexpr float RGB2GRAY_G=0.587f;
    static constexpr float RGB2GRAY_B=0.114f;
    ImageStorage rgb2gray(const ImageStorage& rgb);
    ImageStorage gray2binary(const ImageStorage& gray,unsigned char thresh);
};

#endif