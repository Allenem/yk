#include <iostream>
#include <stack>

using namespace std;

class Queue {
stack<int> s1, s2;
public:
    Queue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }

    int size() {
        return s1.size() + s2.size();
    }
};

// s1: 1 2 3
// s1: NULL

// s2: 3 2 1
// s2: 3 2
// x = 1


// queue = s2[::-1] + s1[:] = [2, 3, 4, 5]
// s1: 4 5
// s2: 3 2

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    // bool to string
    string s = q.empty()? "true":"false";
    cout << s << endl;

    cout << q.peek() << endl;
    cout << q.pop() << endl;
    s = q.empty()? "true": "false";
    cout << s << endl;

    cout << q.peek() << endl;
    cout << q.pop() << endl;
    s = q.empty()? "true": "false";
    cout << s << endl;

    return 0;
}
