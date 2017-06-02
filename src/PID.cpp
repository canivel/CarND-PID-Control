#include "PID.h"
#include <time.h>

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
    static double time_previous = 0;
    double time_now = clock();
    double dt = (time_now - time_previous) / CLOCKS_PER_SEC;
    time_previous = time_now;
    p_error = cte - p_error;
    i_error += cte;
    d_error = (cte - error) * dt;
}

double PID::TotalError() {
}

