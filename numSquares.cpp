// 279. 完全平方数

#include<cmath>
#include<vector>
using namespace std;

class numSquares
{
public:
    // 动态规划
    int numSquares_1(int n) {
        vector<int> f(n+1);
        for (int i = 1; i <= n; i++)
        {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }

    // 数学理论，四平方和定理
    int numSquares_2(int n) {
        if(isPerfectSquare(n))
            return 1;

        if(checkAnswer4(n))
            return 4;

        for(int i = 1; i * i < n; i++){
            int j = n - i * i;
            if(isPerfectSquare(j)){
                return 2;
            }
        }

        return 3;
    }

    bool isPerfectSquare(int n) {
        int y = sqrt(n);
        return y * y == n;
    }

    bool checkAnswer4(int x){
        while (x % 4 == 0)
        {
            x /= 4;
        }
        return x % 8 == 7;
    }
};