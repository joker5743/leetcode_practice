// 761. 特殊的二进制序列

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class MakeLargestSpecial {
 public:
  std::string makeLargestSpecial(std::string str) {
    if (str.size() <= 2) return str;

    int cnt = 0, left = 0;
    std::vector<std::string> subs;

    for (int i = 0; i < str.size(); i++) {
      if (str[i] == '1')
        ++cnt;
      else {
        --cnt;
        if (cnt == 0) {
          subs.emplace_back(
              "1" + makeLargestSpecial(str.substr(left + 1, i - left - 1)) +
              '0');
          left = i + 1;
        }
      }
    }

    std::sort(subs.begin(), subs.end(), std::greater<std::string>{});
    std::string re = "";  // using namespace std::literals
    std::string ans = std::accumulate(subs.begin(), subs.end(), re);
    return ans;
  }
};