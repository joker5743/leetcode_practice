// 1417. 重新格式化字符串
#include<string>
#include<algorithm> 

class Reformat{
public:
    std::string reformat(std::string s) {
        int sum_digit = 0;
        for(auto c : s){
            if(isdigit(c))
                sum_digit++;
        }

        int sum_alpha = s.size() - sum_digit;
        //统计字母和数字的个数
        if(abs(sum_alpha - sum_digit) > 1){
            return "";
        }

        bool flag = sum_digit > sum_alpha;
        for (int i = 0, j = 1; i < s.size(); i += 2)    //双指针
        {
            if(isdigit(s[i]) != flag){
                while (isdigit(s[j]) != flag)
                {
                    j += 2;
                }
                std::swap(s[i], s[j]);
            }
        }
        return s;
    }
};