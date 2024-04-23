// 最小堆栈
// 设计一个支持push, pop, top, 并在常量时间内检索最小元素的堆栈
// getMin() 检索堆栈中的最小元素
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
    stack<int> s1, s2;
public:
    MinStack() {}

    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin()) {
            s2.push(x);
        }
    }

    int pop() {
        if (s1.top() == getMin()) {
            s2.pop();
        }
        int x = s1.top();
        s1.pop();
        return x;
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }

    bool empty() {
        return s1.empty();
    }

    int size() {
        return s1.size();
    }
};

// [4 2 1 5 1]
// s1: 4 2 1 5 1
// s2: 4 2 1 1

// [4 2 1 5]
// s1: 4 2 1 5
// s2: 4 2 1

// [4 2 1]
// s1: 4 2 1
// s2: 4 2 1


int main() {
    MinStack s;
    s.push(4);
    s.push(2);
    s.push(1);
    s.push(5);
    s.push(1);

    // [4 2 1 5 1]
    cout << s.getMin() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;

    cout << " " << endl;
    cout << s.getMin() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;

    cout << " " << endl;
    cout << s.getMin() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;

    cout << " " << endl;
    cout << s.getMin() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;

    cout << " " << endl;
    cout << s.getMin() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;

    cout << " " << endl;
    cout << s.empty() << endl;

    return 0;
}