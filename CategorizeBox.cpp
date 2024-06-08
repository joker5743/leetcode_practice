// 2525. 箱体分类
#include<string>
using namespace std;

class CategorizeBox {
public:
  string categorizeBox(int length, int width, int height, int mass) {
    long long maxd = max(length, max(width, height)),
              vol = 1L * length * width * height;
    bool isBulky = maxd >= 10000 || vol >= 1000000000, isHeavy = mass >= 100;
    if (isHeavy && isBulky)
      return "Both";
    else if (isBulky)
      return "Bulky";
    else if (isHeavy)
      return "Heavy";
    else{
      return "Neither";
    }
  }
};