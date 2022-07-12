#include "studentc.h"

const int pupils = 3;
const int quizzes = 5;
void set(Student &stu, int n);
int main()
{
    Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};

    for (int i = 0; i < pupils; i++)
    {
        set(ada[i], quizzes);
    }
    cout << "\nStudent List: \n";
    for (int i = 0; i < pupils; i++)
    {
        cout << ada[i].Name() << endl;
    }
    ada[0].Set_name("Tome");
    cout << "\nResults List: \n";
    for (int i = 0; i < pupils; i++)
    {
        cout << ada[i];
        cout << "Average:" << ada[i].Average() << endl;
    }
    return 0;
}

void set(Student &stu, int n)
{
    cout << "Please enter the student's name:";
    getline(cin, stu);
    cout << "Please enter: " << n << " quiz scores:\n";
    for (int i = 0; i < quizzes; i++)
        cin >> stu[i];
    while (cin.get() != '\n')
        ;
}