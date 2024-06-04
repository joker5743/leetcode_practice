// 128. 最长连续序列

#include<map>
#include<unordered_set>
#include<vector>
using namespace std;

class LongestConsecutive{
    public:
        int longestConsecutive(vector<int> &nums){
            unordered_set<int> num_set;
            for(const int &num : nums){
                num_set.insert(num);
            }
            
            int longestStreak = 0;
            for(const int &num : nums){
                if(!num_set.count(num - 1)){
                    int currentNum = num;
                    int currentStreak = 1;
                    
                    while(num_set.count(currentNum + 1)){
                        currentNum += 1;
                        currentStreak += 1;
                    }

                    longestStreak = max(longestStreak, currentStreak);
                }
            }
            return longestStreak;
        }       
};