#ifndef TWIDDLE_H
#define TWIDDLE_H

#include <vector>

class Twiddle {
public:
  /*
  * Errors
  */
  double curr_err;
  double best_err;

  double tolerance = 0.2;
  int param_cnt = 3;
  int iterations;
  std::vector<double> p;
  std::vector<double> dp;

  /*
  * Constructor
  */
  Twiddle();

  /*
  * Destructor.
  */
  virtual ~Twiddle();

  /*
  * Initialize PID.
  */
  void InitPID(double Kp, double Ki, double Kd);
  double Sum_dp();
};

#endif /* TWIDDLE_H */
