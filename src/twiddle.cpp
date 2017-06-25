#include "twiddle.h"
#include <iostream>

using namespace std;

Twiddle::Twiddle() : param_cnt(3), p(param_cnt, 0.), dp(param_cnt, 0.1), state(INIT), idx(0)
{
}

Twiddle::~Twiddle() {}

void Twiddle::InitPID(double Kp, double Ki, double Kd) 
{
    param_cnt = 3;
    p[0] = Kp;
    p[1] = Ki;
    p[2] = Kd;
}

void Twiddle::Reset(void) 
{
    iterations = 0;
    curr_err = 0;
}

double Twiddle::Sum_dp() 
{
    double sum = 0;
    for(const auto elem:p) 
    {
        sum += elem;        
    }
    return sum;
}

bool Twiddle::Update(double cte) 
{
    curr_err += cte*cte;
    iterations++;
    if(iterations > max_iterations || curr_err > best_err)
    {
        cout << "Current Error: " << curr_err << " Best Error: " << best_err << endl;
        return true;
    }
    return false;
}

double Twiddle::Evaluate()
{
    switch(state) 
    {
        case INIT:
        best_err = curr_err;
        state = NEXT_PARAM;
        break;

        case NEXT_PARAM:  
        p[idx] += dp[idx];
        state = GOING_UP;
        break;

        case GOING_UP:
        if(curr_err < best_err) 
        {
            best_err = curr_err;
            dp[idx] *= 1.1;
            idx = (idx + 1) % p.size();
            state= NEXT_PARAM;
        }
        else 
        {
            p[idx] -= 2*dp[idx];
            state = GOING_DOWN;
        }
        break;

        case GOING_DOWN:
        if(curr_err < best_err)
        {
            best_err = curr_err;
            dp[idx] *= 1.1;
        }
        else 
        {
            p[idx] += dp[idx];
            dp[idx] *= 0.9;
        }
        idx = (idx + 1) % p.size();
        state = NEXT_PARAM;
        break;
    }
}
