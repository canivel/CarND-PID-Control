#ifndef TWIDDLE_H
#define TWIDDLE_H

#include <vector>

class Twiddle {

private:
  double tolerance = 0.2;
  int param_cnt = 3;
  int max_iterations = 20;
  int iterations = 0;
  std::vector<double> dp;
  enum States {INIT, NEXT_PARAM, GOING_UP, GOING_DOWN};
  States state;
  int idx;

public:
  /*
  * Errors
  */
  double curr_err = 0;
  double best_err = __DBL_MAX__;
  std::vector<double> p;

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
  void Reset(void);
  double Sum_dp(void);
  bool Update(double cte);
  double Evaluate(void);
};

#endif /* TWIDDLE_H */
