// 1282. 用户分组

#include<vector>
#include<unordered_map>
using namespace std;

class GruopThePeople{
public:
    vector<vector<int>> groupThepeople(vector<int>& groupSizes){
        unordered_map<int, vector<int>> groups;
        //记录<每组人数 - 对应的人序号>
        int n = groupSizes.size();
        for (int i = 0; i < n; i++)
        {
            int size = groupSizes[i];
            groups[size].emplace_back(i);
        }
        
        vector<vector<int>> groupList;
        for (auto [size, people] : groups)
        {
            int groupConut = people.size() / size;      //人数相同的组有多少组
            for(int i = 0; i < groupConut; i++){
                vector<int> group;
                int start = i * size;
                for(int j = 0; j < size ; j++){
                    group.emplace_back(people[start + j]);
                }
                groupList.emplace_back(group);
            }
        }
        return groupList;
    }
};