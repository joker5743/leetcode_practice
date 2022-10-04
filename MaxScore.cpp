// 1422. 分割字符串的最大得分
#include<string>
using namespace std;

class MaxScore
{
public:
// 1.遍历枚举
    int maxScore_1(string s) {
        int ans = 0;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {
            int score = 0;
            for (int j = 0; j < i; j++)
            {
                if(s[j] == '0')
                    score++;
            }

            for (int j = i; j < n; j++)
            {
                if(s[j] == '1')
                    score++;
            }
            ans = max(ans, score);
        }
        return ans;
    }

// 2.简化版遍历
    int maxScore_2(string s) {
        int score = 0;
        int n = s.size();
        if(s[0] == '0')
            score++;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == '1')
            {
                score++;
            }
        }

        int ans = score;
        for (int j = 1; j < n - 1; j++)
        {
            if(s[j] == '0')
                score++;
            else
                score--;
            
            ans = max(ans, score);
        }
        
        return ans;
    }
};