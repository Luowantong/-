#ifndef IMAGESTORAGE_H
#define IMAGESTORAGE_H

#include <vector>

class ImageStorage
{
public:
    ImageStorage(int width,int height,int channels);
    //索引坐标
    unsigned char& at(int x,int y,int c);
    unsigned char at(int x,int y,int c)const;
    //获取长宽通道
    int getWidth()const{return width_;}
    int getHeight()const{return height_;}
    int getChannel()const{return channels_;}
private:
    std::vector<unsigned char> pixels_;
    int width_;
    int height_; 
    int channels_;
};

#endif