// 636. 函数的独占时间
#include <stack>
#include <string>
#include <vector>

class ExclusiveTime {
  std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs) {
    std::stack<std::pair<int, int>>
        st;  // 模拟程序在栈中调用的信息存储顺序,栈顶是当前执行程序的开始信息
    std::vector<int> res(n, 0);  // 记录每个程序的单独运行时间

    for (auto& log : logs) {
      char type[10];
      int idx, timestap;
      sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type,
             &timestap);  // 格式化读取字符串。获取程序编号idx， 记录类型（start
                          // OR end）， 时间戳
      // 当前记录是某个程序的开始。
      if (type[0] == 's') {
        if (!st.empty()) {  // 如果之前还存在未调用完的程序
          res[st.top().first] +=
              timestap - st.top().second;  // 将前一个程序目前运行的时间进行更新
          st.top().second =
              timestap;  // 这一行可以注释，因为在当前程序结束时还会更新
        }
        st.emplace(idx, timestap);
      }
      // 当前记录是某个程序的结束。
      else {
        auto t = st.top();
        st.pop();
        res[t.first] += timestap - t.second + 1;
        if (!st.empty()) {
          st.top().second = timestap + 1;  // 更新上一个程序接着执行的开始时间。
        }
      }
    }
    return res;
  }
};