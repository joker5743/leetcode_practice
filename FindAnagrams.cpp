// 438. 找到字符串中所有字母异位词

#include<vector>
using namespace std;

class FindAnagrams{
    public:
        // 方法1：滑动窗口。
        vector<int> findAnagrams_1(string s, string p) {
            int sLen = s.length(), pLen = p.length();
            if(sLen < pLen) return vector<int>();

            vector<int> res;
            vector<int> sCount(26, 0), pCount(26, 0);
            for (int i = 0; i < pLen; i++)
            {
                sCount[s[i] - 'a']++;
                pCount[p[i] - 'a']++;
            }
            if(sCount == pCount) res.emplace_back(0);
            
            for (int i = 0; i < sLen - pLen; i++)
            {
                sCount[s[i] - 'a']--;
                sCount[s[i + pLen] - 'a']++;
                if(sCount == pCount)
                {
                    res.emplace_back(i + 1);   
                }
            }
            return res;
        }

        // 方法2：滑动窗口，基于差值优化版。
        vector<int> findAnagrams_2(string s, string p) {
            int sLen = s.length(), pLen = p.length();
            if(sLen < pLen) return vector<int>();

            vector<int> res;
            vector<int> count(26);
            for (int i = 0; i < pLen; i++)
            {
                ++count[s[i] - 'a'];
                --count[p[i] - 'a'];
            }

            // 统计初始阶段，源(窗口部分内容)和目标字符串的字母频率差异
            int differ = 0;
            for (int i = 0; i < 26; i++)
            {
                if(count[i] != 0)
                {
                    ++differ;
                }
            }
            
            if(differ == 0){
                res.emplace_back(0);
            }

            // 开始滑窗移动，这里i=0其实已经开始在比对[i, i+pLen]这一区间的滑窗和目标字符串的差异了。
            // count数组中记录的，为正数表示改字符source中含有target无，为负数则表示source无但是target有。
            for(int i = 0; i < sLen - pLen; i++){
                // 滑窗开头
                if(count[s[i] - 'a'] == 1)
                    --differ;
                else if(count[s[i] - 'a'] == 0)
                    ++differ;
                --count[s[i] - 'a'];

                // 滑窗末尾
                if(count[s[i+pLen] - 'a'] == -1)
                    --differ;
                else if (count[s[i+pLen] - 'a'] == 0)
                    ++differ;
                ++count[s[i+pLen] - 'a'];

                if(differ == 0){
                    res.emplace_back(i + 1);
                }
            }
            return res;
        } 
};