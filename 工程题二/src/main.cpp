#include "ImageStorage.h"
#include "ImageConvert.h"
#include "ImageProcess.h"
#include "ImageVisualize.h"
#include <fstream>
#include <iostream>

int main() {
    std::cout << "开始测试图像处理库..." << std::endl;
    
    // 1. 创建图像
    ImageStorage rgb(5,5,3);
    for (int y=0; y<5; y++) {
        for (int x=0; x<5; x++) {
            rgb.at(x,y,0) = 255;  // R
            rgb.at(x,y,1) = 0;    // G
            rgb.at(x,y,2) = 0;    // B
        }
    }
    
    // 2. 转灰度
    ImageConvert convert;
    ImageStorage gray = convert.rgb2gray(rgb);
    std::cout << "灰度图:" << std::endl;
    ImageVisualize vis;
    vis.print(gray);
    
    // 3. 二值化
    ImageStorage binary = convert.gray2binary(gray, 128);
    std::cout << "\n二值图:" << std::endl;
    vis.print(binary);
    
    // 4. 保存文件
    vis.savefile(gray, "gray.pgm");
    vis.savefile(binary, "binary.pgm");
    std::cout << "\n已保存 gray.pgm 和 binary.pgm" << std::endl;
    
    return 0;
}