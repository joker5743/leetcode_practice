// 811. 子域名访问计数
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class SubDomainVisits {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> cnt;
        for (auto cpdomain : cpdomains)
        {
            int space = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, space));
            string domain = cpdomain.substr(space+1);
            cnt[domain] += count;

            for (size_t i = 0; i < domain.size(); i++)
            {
                if (domain[i] == '.')
                {
                    string subdomain = domain.substr(i+1);
                    cnt[subdomain] += count;
                }
            }
        }
        
        for (auto &&[subdomain, count] : cnt)
        {
            ans.emplace_back(to_string(count) + " " + subdomain);
        }
        return ans;
    }
};