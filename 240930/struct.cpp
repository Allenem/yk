#include <iostream>
#include <string>

using namespace std;

struct Course {
private:
    int id;
    string name;
    double credit;
    double score = 0;

public:
    void setID(int id) {
        this->id = id;
    }

    int getID() {
        return id;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setCredit(double credit) {
        this->credit = credit;
    }

    double getCredit() {
        return credit;
    }

    void setScore(double score) {
        this->score = score;
    }

    double getScore() {
        return score;
    }

};

int main() {
    Course course;
    course.setID(1);
    course.setName("C++ Programming");
    course.setCredit(3.0);
    course.setScore(4.0);

    cout << "Course ID: " << course.getID() << endl;
    cout << "Course Name: " << course.getName() << endl;
    cout << "Course Credit: " << course.getCredit() << endl;
    cout << "Course Score: " << course.getScore() << endl;

    return 0;
}