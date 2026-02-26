#include "project_include.h" 

KalmanFilter::KalmanFilter(float q,float r):Q(q),R(r),state(0.0,1.0){};

void KalmanFilter::KalmanPredict()
{
    state.x=state.x;
    state.P+=Q;
}

void KalmanFilter::KalmanUpdate(float z)
{
    K=state.P/(state.P+R);
    state.x=state.x+K*(z-state.x);
    state.P=(1-K)*state.P;
}

float KalmanFilter::KalmanGetState()
{
    return state.x;
}