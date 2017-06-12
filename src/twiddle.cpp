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

bool Twiddle::Update(double cte) {
    curr_err += cte*cte;
    if(iterations > max_iterations)
    {
        return true;
    }
    return false;
}

double Twiddle::Evaluate() {

    while (this->Sum_dp() > tolerance)
    {
        cout << "Current Error: " << curr_err << "Best Error: " << best_err << endl;
        for(int i=0; i<p.size(); i++)
        {
           p[i] += dp[i];
           if(curr_err < best_err) 
           {
               best_err = curr_err;
               dp[i] *= 1.1;
           } 
           else
           {
               p[i] -= 2*dp[i];
           }
        }
    }
}
