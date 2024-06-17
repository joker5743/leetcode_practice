// 856. 括号的分数
#include <stack>
#include <string>

using namespace std;

class ScoreOfParentheses {
 public:
  int scoreofparentheses(string s) {
    stack<int> st;
    st.push(0);
    for (auto i : s) {
      if (i == '(') {
        st.push(0);
      } else {
        int v = st.top();
        st.pop();
        st.top() += max(2 * v, 1);
      }
    }
    return st.top();
  }
};