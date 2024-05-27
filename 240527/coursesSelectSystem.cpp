#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct Course {
    int id;
    string name;
    double credit;
    double score = 0;
};

vector<Course> courses = { {1, "漫画艺术欣赏与创作", 1},
                          {2, "《共产党宣言》导读", 1.5},
                          {3, "通榆年画", 0.5},
                          {4, "公共关系礼仪实务", 1.5},
                          {5, "中国文化遗产鉴赏", 2},
                          {6, "世界文化遗产鉴赏", 0.5},
                          {7, "中国民间艺术的奇妙之旅", 0.5},
                          {8, "笔墨时空——解读中国书法文化基因", 1.5},
                          {9, "舞台人生:走进戏剧艺术", 1.5},
                          {10, "走进故宫", 1.5} };

vector<Course> selectedCourses;

// 计算学分函数
double calculateCredit() {
    return accumulate(selectedCourses.begin(), selectedCourses.end(), 0.0, [](double sum, const Course& course) { return sum + course.credit; });
}

// 2.显示已选课程函数
void showSelectedCourses() {
    cout << "\n已选课程数量: " << selectedCourses.size() << endl;
    cout << "已选学分: " << calculateCredit() << endl;
    if (selectedCourses.size() == 0) {
        cout << "未选课程" << endl;
        return;
    }
    cout << "课序号\t课程名称\t学分\t已得学分" << endl;
    for (const Course& course : selectedCourses) {
        cout << course.id << "\t" << course.name << "\t" << course.credit << "\t" << course.score << endl;
    }
}

// 1.选课函数
void selectCourse() {

    // 没有选课或学分不足4分时，继续选课
    while (selectedCourses.size() == 0 || calculateCredit() < 4) {
        showSelectedCourses();
        cout << "所选课程学分未达4分, 请继续选课" << endl;
        cout << "请输入课序号进行选课 (输入0退出选课): ";
        int id;
        bool repeatflag = false;
        cin >> id;
        if (id == 0) {
            cout << "暂时退出选课, 但请注意已选课程学分未达到4分 !!!" << endl;
            break;
        }
        for (const Course& course : selectedCourses) {
            if (course.id == id) {
                cout << "该课程已选, 请重新选择!!!" << endl;
                repeatflag = true;
                break; // 结束 L62 for 循环
            }
        }
        if (repeatflag) continue; // 重复选课，重新回到 L51 while 循环

        // 既没有退出，也没有重复选课，继续选课
        bool findflag = false;
        for (const Course& course : courses) {
            if (course.id == id) {
                findflag = true;
                selectedCourses.push_back(course);
                break; // 结束 L73 for 循环
            }
        }
        if (!findflag) {
            cout << "未找到该课程" << endl;
        }
    }

    // 学分已满足要求时，询问是否继续选课
    while (calculateCredit() >= 4) {
        showSelectedCourses();
        cout << "\n总学分已满足要求，是否继续选课？(1.继续选课 0.退出选课): ";
        int id;
        cin >> id;
        if (id == 1) {
            cout << "请输入课序号进行选课 (输入0退出选课): ";
            int subid;
            bool repeatflag = false;
            cin >> subid;
            if (subid == 0) break; // 结束 L86 while 循环
            for (const Course& course : selectedCourses) {
                if (course.id == subid) {
                    cout << "该课程已选, 请重新选择!!!" << endl;
                    repeatflag = true;
                }
            }
            if (repeatflag) continue; // 重复选课，重新回到 L86 while 循环

            bool findflag = false;
            for (const Course& course : courses) {
                if (course.id == subid) {
                    findflag = true;
                    selectedCourses.push_back(course);
                    break; // 结束 L106 for 循环
                }
            }
            if (!findflag) {
                cout << "未找到该课程" << endl;
            }
        }
        else {
            break; // 结束 L86 while 循环
        }
    }
}

// 3.录入成绩函数
void inputExamScore() {
    showSelectedCourses();
    if (selectedCourses.size() == 0) {
        cout << "未选课程" << endl;
        return;
    }
    int id;
    double score;
    cout << "\n请输入课序号和成绩(以空格分隔): ";
    cin >> id >> score;
    bool findflag = false;

    for (Course& course : selectedCourses) {
        if (course.id == id) {
            findflag = true;
            if (score >= 60) {
                course.score = course.credit;
            }
            cout << "录入成功" << endl;
            break; // 结束 L123 for 循环
        }
    }
    if (!findflag) {
        cout << "未找到该课程" << endl;
    }
}

// 4.显示最终选课及所得学分函数
void showFinalSelectedAndCredit() {
    if (selectedCourses.size() == 0) {
        cout << "未选课程" << endl;
        return;
    }
    double totalScore = 0;
    cout << "\n课序号\t课程名称\t所得学分" << endl;
    for (const Course& course : selectedCourses) {
        totalScore += course.score;
        cout << course.id << "\t" << course.name << "\t" << course.score << endl;
    }
    cout << "总学分: " << totalScore << endl;
}

// 主函数
int main() {
    int choice;
    do {
        cout << "\n*******************知识改变命运，请认真选课********************" << endl;
        cout << "课序号\t课程名称\t学分" << endl;
        for (const Course& course : courses) {
            cout << course.id << "\t" << course.name << "\t" << course.credit << endl;
        }
        cout << "*************************************************************\n" << endl;

        cout << "1.选课(总学分不少于 4 分)" << endl;
        cout << "2.显示所选课程(课序号，课程名称，学分)" << endl;
        cout << "3.录入所选课程的考试成绩" << endl;
        cout << "4.显示最终选课及所得学分(课序号，课程名称，所得学分)" << endl;
        cout << "0.退出\n" << endl;
        cout << "请选择: ";
        cin >> choice;

        switch (choice) {
        case 1:
            selectCourse();
            system("pause");
            break;
        case 2:
            showSelectedCourses();
            system("pause");
            break;
        case 3:
            inputExamScore();
            system("pause");
            break;
        case 4:
            showFinalSelectedAndCredit();
            system("pause");
            break;
        case 0:
            break;
        default:
            cout << "无效选择" << endl;
            system("pause");
        }
    } while (choice != 0);

    return 0;
}