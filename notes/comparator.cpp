#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// The type of the priority_queue can be complicated
template<typename T>
void print_queue(T& q)
{
    while (!q.empty())
    {
        cout << q.top().name << " ";
        q.pop();
    }
    cout << endl;
}

struct Student
{
    int grade;
    string name;

    Student(int g, string n): grade(g),name(n) {};

    bool operator<(Student& other) const
    {
        return grade < other.grade;
    }

    bool operator>(Student& other) const
    {
        return grade > other.grade;
    }
};


// This is a function
bool CompareName(Student& a, Student& b)
{
    return a.name < b.name;
}

// This is a function object (i.e. functor)
struct CompareGrade
{
    bool operator()(Student& a, Student& b)
    {
        return a.grade > b.grade;
    }
};

int main()
{
    vector<Student> students;
    students.push_back(Student(68,"Tom"));
    students.push_back(Student(32,"Alice"));
    students.push_back(Student(99,"Tim"));
    students.push_back(Student(83,"Angela"));
    students.push_back(Student(75,"Joe"));

    // Use lambda expression
    // sort(students.begin(),students.end(),[](Student& a, Student& b){return a.grade > b.grade;});
    // Use function object to store a lambda function
    // Can use "auto" to replace the type
    function<bool(Student&,Student&)> lambda_comp = [](Student& a, Student& b){return a.grade > b.grade;};
    sort(students.begin(),students.end(),lambda_comp);
    for (auto & s : students)
        cout << s.name << endl;

    if (students[0] > students[1])
        cout << students[0].name << " scored higher than " << students[1].name << endl;

    // Note the template arguments of the pq
    // 1. Use regular functor, 3rd argument must be a TYPE of the comparator
    priority_queue<Student,vector<Student>,CompareGrade> pq1;
    // 2. Use function directly
    priority_queue<Student,vector<Student>,function<bool(Student&,Student&)>> pq2(CompareName);
    // 3. Use lambda functor
    priority_queue<Student,vector<Student>,decltype(lambda_comp)> pq3(lambda_comp);

    // The type of a function is different from the type of a functor
    // The type of a lambda functor is only known by the compiler
    // The type of a regular functor is known by the programmer

    for (auto & s: students)
    {
        pq1.push(s);
        pq2.push(s);
        pq3.push(s);
    }
    print_queue(pq1);
    print_queue(pq2);
    print_queue(pq3);

    return 0;
}
