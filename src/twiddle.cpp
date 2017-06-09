#include "twiddle.h"
#include <iostream>

using namespace std;

Twiddle::Twiddle() : param_cnt(3), p(param_cnt, 0.), dp(param_cnt, 1.)
{
}

Twiddle::~Twiddle() {}

void Twiddle::InitPID(double Kp, double Ki, double Kd) {
    param_cnt = 3;
    p[0] = Kp;
    p[1] = Ki;
    p[2] = Kd;
}

double Twiddle::Sum_dp() {
    double sum = 0;
    for(const auto elem:p) 
    {
        sum += elem;        
    }
    return sum;
}
