// 921. 使括号有效的最少添加
#include<string>
#include<vector>
using namespace std;

class MinAddToMakeValid {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int leftCount = 0;
        for (auto c: s)
        {
            if(c == '(')
                leftCount++;
            else{
                if(leftCount > 0)
                    leftCount--;
                else
                    ans++;
            }
        }
        ans += leftCount;
        return ans;
    }
};