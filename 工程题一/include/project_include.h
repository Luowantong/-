#ifndef PROJECT_INCLUDE_H
#define PROJECT_INCLUDE_H
class KalmanFilter
{
public:
    KalmanFilter(float q,float r);
    struct KalmanState
    {
        float x; //状态估计值
        float P; //误差协方差

        KalmanState(float x_init=0.0,float P_init=1.0):x(x_init),P(P_init){}
    };
    void KalmanPredict(); //预测函数
    void KalmanUpdate(float z); //状态更新函数
    float KalmanGetState(); //获取当前状态
    
private:
    float Q; //过程噪声
    float K; //卡尔曼增益
    float R; //测量噪声
    KalmanState state;
};
#endif
