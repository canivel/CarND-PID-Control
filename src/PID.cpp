#include "PID.h"
#include <time.h>
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->p_error = 0;
    this->i_error = 0;
    this->d_error = 0;
}

void PID::UpdateError(double cte) {
    // static double time_previous = 0;
    // double time_now = clock();
    // double dt = (time_now - time_previous) / CLOCKS_PER_SEC;
    // time_previous = time_now;
    // p_error is previous cte
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    std::cout << "PID errors: " << p_error << " " << i_error << " " << d_error << endl;
}

double PID::TotalError() {
    cout << "PID Gains: " << -Kp*p_error << " " << Ki*i_error << " " << Kd*d_error << endl;
    return -Kp*p_error - Ki*i_error - Kd*d_error;
}

