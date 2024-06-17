// 131. 分割回文串

#include<vector>
#include<string>
using namespace std;

class SplitPalindromeString{
    private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;

    public:
        // 方法一：回溯+动态规划
        vector<vector<string>> partition_1(string s) {
            n = s.size();
            f.assign(n, vector<int>(n, true));

            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = i + 1; j < n; j++)
                {
                    f[i][j] = (s[i] == s[j]) && f[i+1][j-1];
                }
            }
            
            dfs_1(s, 0);
            return ret;
        }

        void dfs_1(const string& s, int i){
            if(i== n){
                ret.push_back(ans);
                return;
            }
                
            for (int j = i; j < n; j++)
            {
                if(f[i][j]){
                    ans.push_back(s.substr(i, j-i+1));
                    dfs_1(s, j + 1);
                    ans.pop_back();
                }
            }
        }


        //方法二：回溯
        vector<vector<string>> partition_2(string s) {
            n = s.size();
            f.assign(n, vector<int>(n, 0));

            dfs_2(s, 0);
            return ret;
        }
        /* 
        f[i][j]含有三种值。
        0表示未搜索，1代表是回文串，-1代表不是回文串。
         */
        int isPalindrome(const string& s, int i, int j){
            if(f[i][j])
                return f[i][j];

            if(i >= j){
                return f[i][j] = 1;
            }
            return f[i][j] = (s[i] == s[j]) ? isPalindrome(s, i+1, j -1): -1;
        }

        void dfs_2(const string& s, int i){
            if(i== n){
                ret.push_back(ans);
                return;
            }

            for (int j = i; j < n; j++)
            {
                if(isPalindrome(s, i ,j) == 1){
                    ans.push_back(s.substr(i, j-i+1));
                    dfs_2(s, j + 1);
                    ans.pop_back();
                }
            }
        }
};