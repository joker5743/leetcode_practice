// 50. 快速幂

using namespace std;

class FastPow {
 public:
  // 1. 递归
  double myPow_1(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul_1(x, N) : 1.0 / quickMul_1(x, -N);  // 考虑负指数
  }

  double quickMul_1(double x, long long N) {
    if (N == 0) {
      return 1.0;
    }

    double y = quickMul_1(x, N / 2);
    return N % 2 == 0 ? y * y : y * y * x;
  }

  // 2. 非递归，迭代
  double myPow_2(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul_1(x, N) : 1.0 / quickMul_1(x, -N);
  }

  double quickMul_2(double x, long long N) {
    double ans = 1.0;
    double x_contribute = x;
    while (N > 0) {
      if (N % 2 == 1) {
        ans *= x_contribute;
      }

      x_contribute *= x_contribute;
      N /= 2;
    }
    return ans;
  }
};