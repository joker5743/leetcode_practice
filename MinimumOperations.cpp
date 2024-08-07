// 2844. 生成特殊数字的最少操作

#include <string>
using namespace std;

class MinimumOperations {
 public:
  // 模拟能被25整除的数字特性，从低位开始遍历
  int minimumOperations(string num) {
    int n = num.size();
    bool find5 = false, find0 = false;  // 低位是0或者5
    for (int i = n - 1; i >= 0; i--) {
      if (num[i] == '0' || num[i] == '5') {
        if (find0) {
          // 如果之前有访问到字符0，即存在0XXX0的结构
          return n - i - 2;
        }

        if (num[i] == '0') {
          find0 = true;
        } else {
          find5 = true;
        }
      }

      else if (num[i] == '2' || num[i] == '7') {
        if (find5) {
          // 如果之前有访问到字符5，则存在2XXX5或者7XXX5的结构
          return n - i - 2;
        }
      }
    }

    // 访问完之后没有00,25,50,75这种的结构，则寻找是否含有0字符，使得最后0能被25整除
    if (find0) {
      return n - 1;
    }
    return n;
  }
};