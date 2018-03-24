// https://leetcode.com/problems/min-stack/description/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {
    }

    void push(int x) {
        if(min_stack.size() == 0) {
            min = x;
            min_stack.push(0);
        } else {
            long long diff = x - min;
            min_stack.push(diff);
            if(diff < 0) {
                min = x;
            }
        }
    }

    void pop() {
        long long ret = min_stack.top();
        if(ret < 0) {
           min = min - ret;
        }
        min_stack.pop();
    }

    int top() {
        long long ret = min_stack.top();
        if(ret < 0) {
            return min;
        } else {
            return min + ret;
        }
    }

    int getMin() {
        return (int)min;
    }
private:
    stack<long long> min_stack;
    long long min;
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    if(minStack.getMin() != -3) {
        cout << "Test #1 failed." << endl;
    }
    minStack.pop();
    if(minStack.top() != 0) {
        cout << "Test #2 failed." << endl;
    }
    if(minStack.getMin() != -2) {
        cout << "Test #3 failed." << endl;
    }

    return 0;
}
