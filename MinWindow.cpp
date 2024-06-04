// 76. 最小覆盖子串

#include<string>
#include<unordered_map>
using namespace std;

class MinWindow{
    public:
        unordered_map<char, int> ori, cnt;
        // cnt记录滑窗内的字符串字母频次，ori记录则目标字符串

        bool check(){
            for (const auto &i : ori)
            {
                if(cnt[i.first] < i.second){
                    return false;
                }
            }
            return true;
        }

        string minWindow(string s, string t) {
            // 统计目标字符串的字符频率
            for(const auto &i : t){
                ori[i]++;
            }

            int l = 0, r = -1;
            int len = INT_MAX, ansL = -1, ansR = -1;
            while (r < int(s.size()))
            {
                if(ori.find(s[++r]) != ori.end()){
                    ++cnt[s[r]];
                }

                while (check() && l <= r)
                {
                    if(r - l + 1 < len){
                        len = r - l + 1;
                        ansL = l;
                        ansR = r;
                    }
                    if(ori.find(s[l]) != ori.end()){
                        --cnt[s[l]];
                    }
                    ++l;
                }
            }
            return ansL == -1 ? string() : s.substr(ansL, len);
        }
};