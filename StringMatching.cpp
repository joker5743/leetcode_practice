// 1408. 数组中的字符串匹配

#include <string>
#include <vector>

class StringMatching {
 public:
  std::vector<std::string> stringMatching_1(std::vector<std::string>& words) {
    std::vector<std::string> ret;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        if (i != j && words[j].find(words[i]) != std::string::npos) {
          ret.emplace_back(words[i]);
          break;
        }
      }
    }
    return ret;
  }
};