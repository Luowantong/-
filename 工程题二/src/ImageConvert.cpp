#include "ImageConvert.h"
#include <stdexcept>

ImageConvert::ImageConvert(){}

ImageStorage ImageConvert::rgb2gray(const ImageStorage &rgb)
{
    if (rgb.getChannel()!=3) 
    {
        throw std::invalid_argument("need three channels");
    }

    ImageStorage gray(rgb.getWidth(),rgb.getHeight(),1);

    for (int y=0; y<rgb.getHeight(); y++) 
    {
        for (int x=0; x<rgb.getWidth(); x++) 
        {
            unsigned char r=rgb.at(x,y,0);
            unsigned char g=rgb.at(x,y, 1);
            unsigned char b=rgb.at(x,y, 2);

            unsigned char gray_val=static_cast<unsigned char>(
                RGB2GRAY_R*r+RGB2GRAY_G*g+RGB2GRAY_B*b
            );

            gray.at(x, y, 0)=gray_val;
        }
    }
    return gray;
}

ImageStorage ImageConvert::gray2binary(const ImageStorage& gray,unsigned char thresh)
{
    if (gray.getChannel()!=1) 
    {
        throw std::invalid_argument("need gray image");
    }

    ImageStorage binary(gray.getWidth(),gray.getHeight(),1);

    for (int y=0; y<gray.getHeight(); y++) 
    {
        for (int x=0; x<gray.getWidth(); x++) 
        {
            unsigned char p=gray.at(x, y, 0);
            unsigned char val=(p>thresh)?255:0;
            binary.at(x, y, 0)=val;
        }
    }
    return binary;
}