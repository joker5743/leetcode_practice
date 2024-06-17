// 1656. 设计有序流
#include <string>
#include <vector>
using namespace std;

class OrderedStream {
 public:
  OrderedStream(int n) {
    stream.resize(n + 1);
    ptr = 1;
  }

  vector<string> insert(int idKey, string value) {
    stream[idKey] = value;
    vector<string> res;
    while (ptr < stream.size() && !stream[ptr].empty()) {
      res.emplace_back(stream[ptr]);
      ptr++;
    }
    return res;
  }

 private:
  vector<string> stream;
  int ptr;
};