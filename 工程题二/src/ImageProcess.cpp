#include "ImageProcess.h"
#include <algorithm>
#include <vector>

ImageProcess::ImageProcess(){}

ImageStorage ImageProcess::meanBlur(const ImageStorage &img, int kernel_size)
{
    ImageStorage output(img.getWidth(),img.getHeight(),img.getChannel());
    for (int y=0; y<img.getHeight(); y++) 
    {
        for (int x=0; x<img.getWidth(); x++) 
        {
            for (int i=0; i<img.getChannel(); i++) 
            {
                int count=0;
                int sum=0;
                int half=kernel_size/2;
                for (int ky=-half; ky<=half; ky++) 
                {
                    for (int kx=-half; kx<=half; kx++) 
                    {
                        int nx=x+kx;
                        int ny=y+ky;
                        if (nx>=0&&ny>=0&&nx<img.getWidth()&&ny<img.getHeight()) 
                        {
                            sum+=img.at(nx, ny, i);
                            count++;
                        }
                    }
                }
                unsigned char val=static_cast<unsigned char>(sum/count);
                output.at(x, y, i)=val;
            }
        }
    }
    return output;
}

int ImageProcess::find(int x)
{
    if (parent[x]!=x) 
    {
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void ImageProcess::unite(int x, int y)
{
    int findX=find(x);
    int findY=find(y);
    if (findX==findY) 
    {
        return;
    }
    else if (findX>findY) 
    {
        parent[findX]=findY;
    }
    else 
    {
        parent[findY]=findX;
    }
}

ImageStorage ImageProcess::connectedComponents(const ImageStorage& binary)
{
    ImageStorage img(binary.getWidth(),binary.getHeight(),1);
    int next_img=1;
    int max_=binary.getHeight()*binary.getWidth();
    parent.resize(max_);
    for (int i=0; i<parent.size(); i++) 
    {
        parent[i]=i;
    }
    for (int y=0; y<binary.getHeight(); y++) 
    {
        for (int x=0; x<binary.getWidth(); x++) 
        {
            if (binary.at(x, y, 0)==0) 
            {
                img.at(x, y, 0)=0;
                continue;
            }
            int left=(x>0)?img.at(x-1, y, 0):0;
            int top=(y>0)?img.at(x, y-1, 0):0;

            if (binary.at(x, y, 0)==255)
            {
                if (left==0&&top==0) 
                {
                    img.at(x, y, 0)=next_img++;
                }
                else if (left!=0&&top==0) 
                {
                    img.at(x, y, 0)=left;
                }
                else if (top!=0&&left==0) 
                {
                    img.at(x, y, 0)=top;
                }
                else if (left == top) 
                {
                    img.at(x, y, 0) = left;
                }
                else 
                {  
                    int min_ = std::min(left, top);
                    img.at(x, y, 0) = min_;
                    unite(left, top);
                }
            }
        }
    }

    for (int y=0; y<img.getHeight(); y++) 
    {
        for (int x=0; x<img.getWidth(); x++)
        {
            if (img.at(x, y, 0)>0)
            {
                int represent=find(img.at(x, y, 0));
                img.at(x, y, 0)=represent;
            }
        }
    }
    return img;
}