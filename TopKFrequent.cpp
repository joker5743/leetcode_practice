// 347. 前K个高频元素

#include<vector>
#include<queue>
#include<utility>
#include<unordered_map>
using namespace std;

class TopKFrequent
{
public:
    // 方法一：基于堆排序
    static bool comp(pair<int, int>& m, pair<int, int>&n){
        return m.second > n.second;     // 按照元素出现频率次数，降序排列。
    }

    vector<int> topKFrequent_1(vector<int>& nums, int k) {
        unordered_map<int, int> occ;
        for(const int &i : nums){
            occ[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comp)> q(comp);
        for(auto& [num, count] : occ){
            if(q.size() == k){
                if(q.top().second < count){
                    q.pop();
                    q.emplace(num, count);
                }
            }
            else{
                q.emplace(num, count);
            }
        }

        vector<int> res;
        while (!q.empty())
        {
            res.emplace_back(q.top().first);
            q.pop();
        }
        return res;
    }

    // 方法二：基于快排
    vector<int> topKFrequent_2(vector<int>& nums, int k) {
        unordered_map<int, int> occ;
        for(auto& v: nums){
            occ[v]++;
        }

        vector<pair<int, int>> values;
        for(auto& kv: occ){
            values.push_back(kv);
        }

        vector<int> ret;
        qsort(values, 0, values.size() - 1, ret, k);
        return ret;
    }

    void qsort(vector<pair<int, int>>& v, int start, int end, vector<int>& ret, int k){
        int picked = rand() % (end - start + 1) + start;    // 随机定位比对的主元
        swap(v[start], v[picked]);

        int pivot = v[start].second;
        int index = start;
        for(int i = start + 1; i <= end; i++){
            if(v[i].second >= pivot){
                swap(v[++index], v[i]);
            }
        }
        swap(v[start], v[index]);

        if(k <= index - start){
            qsort(v, start, index - 1, ret, k);
        }
        else{
            for(int i = start; i <= index; i++){
                ret.push_back(v[i].first);
            }
            if(k > index - start + 1){
                qsort(v, index + 1, end, ret, k - (index - start + 1));
            }
        }
    }
};