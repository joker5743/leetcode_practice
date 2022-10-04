// 899. 有序队列

#include<string>
#include<iostream>
#include<algorithm>

class OrderlyQueue{
public:
    OrderlyQueue(){
        std::cout << "construct finished..." << std::endl;
    }

    std::string orderlyQueue(std::string s, int k){
        if(k == 1){
            std::string smallest = s;
            int n = s.size();
            for (int i = 1; i < n; i++)
            {
                char c = s[0];
                s = s.substr(1);
                s.push_back(c);
                if(s < smallest)
                    smallest = s;
            }
            return smallest;
        }
        else{
            std::sort(s.begin(),s.end());
            return s;
        }
    }
};