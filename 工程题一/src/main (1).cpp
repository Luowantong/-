#include "project_include.h" 
#include <iostream>
#include <ostream>
#include <random>
#include <chrono>

int main()
{
    KalmanFilter filter(1.0,0.1);
    unsigned seed=std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::normal_distribution<double> noise(0.0,0.1);
    for (int step=0; step<100; step++) 
    {
        float true_x=step*0.1;
        float measurement=true_x+noise(generator);
        if (step%10==0) 
        {
            filter.KalmanPredict();
            filter.KalmanUpdate(measurement);
            float result=filter.KalmanGetState();
            std::cout<<"真实数据:"<<true_x<<std::endl;
            std::cout<<"原始数据"<<measurement<<std::endl;
            std::cout<<"处理之后的滤波:"<<result<<std::endl;
        }
    }
}