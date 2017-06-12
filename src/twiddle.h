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
  int max_iterations = 2000;
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
  double Sum_dp(void);
  bool Update(double cte);
  double Evaluate(void);
};

#endif /* TWIDDLE_H */
