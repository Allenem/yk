#include <iostream>
#include <queue>

using namespace std;

class Stack {
    queue<int> q1, q2;
public:
    Stack() {}

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q1.pop();
        swap(q1, q2);
        return x;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int x = q1.front();
        q2.push(q1.front()); // This line is different from pop()
        q1.pop();
        swap(q1, q2);
        return x;
    }

    bool empty() {
        return q1.empty();
    }

    int size() {
        return q1.size();
    }
};

// q1 = 1 2 3
// q2 = NULL

// q1 = 3
// q2 = 1 2

// q1 = NULL
// q2 = 1 2
// q1 = 1 2
// q2 = NULL

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.empty() << endl;
    return 0;
}
