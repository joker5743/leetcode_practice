// 155. 最小栈

#include<stack>
#include<limits>
using namespace std;

class MinStack
{
private:
    //利用额外的一个存放最小值的栈模拟实现，达到O(1)时间查询复杂度。
    stack<int> x_stack;
    stack<int> min_stack;
public:
    MinStack(){
        min_stack.push(numeric_limits<int>::max());
    }

    void push(int val) {
        x_stack.push(val);
        min_stack.push(min(min_stack.top(), val));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};
