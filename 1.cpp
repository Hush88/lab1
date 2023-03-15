#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;


class Student {
public:
    string last_name;
    string first_name;
    string middle_name;
    int birth_year;
    int course;
    int group_number;
    vector<int> grades;

    float average_grade() {
        float sum = 0;
        for (int i = 0; i < grades.size(); i++) 
        {
            sum += grades[i];
        }
        return sum / grades.size();
    }
};


bool compare_students(Student& s1, Student& s2) {

    if (s1.course != s2.course)
    {
        return s1.course < s2.course;
    }

    else 
    {
        return s1.last_name < s2.last_name;
    }
}


int main() 
{
    SetConsoleOutputCP(1251);

    vector<Student> students = {
        {"Дедюхін", "Дмитро", "Євгенович", 2000, 1, 101, {5, 4, 4, 3, 5}},
        {"Смирнов", "Антон", "Максимович", 1999, 2, 201, {3, 3, 3, 4, 4}},
        {"Шевченко", "Тарас", "Григорович", 2001, 1, 102, {4, 4, 4, 5, 4}},
        {"Олійник", "Назар", "Олексійович", 1998, 3, 301, {5, 5, 4, 5, 5}},
        {"Бутко", "Ярослав", "Сергійович", 2000, 2, 202, {3, 3, 3, 3, 3}}};


    sort(students.begin(), students.end(), compare_students);


    // Знаходження середнього балу кожної групи з кожного предмета
    vector<vector<float>> average_grades(307, vector<float>(5, 0));
    vector<int> group_sizes(307, 0);


    for (int i = 0; i < students.size(); i++) {
        Student& s = students[i];
        int group = s.group_number;
        for (int j = 0; j < 5; j++) {
            average_grades[group][j] += s.grades[j];
        }
        group_sizes[group]++;
    }


    for (int i = 101; i <= 306; i++) {
        if (group_sizes[i] > 0) {
            cout << "Група " << i << ":" << endl;
            for (int j = 0; j < 5; j++) {
                float average_grade = average_grades[i][j] / group_sizes[i];
                cout << "Пердмет " << j + 1 << ": " << average_grade << endl;
            }
        }
    }


    // Знаходження найстаршого та наймолодшого студентів
    Student& youngest_student = *min_element(students.begin(), students.end(), [](Student& s1, Student& s2) {
        return s1.birth_year < s2.birth_year;
        });


    Student& oldest_student = *max_element(students.begin(), students.end(), [](Student& s1, Student& s2) {
        return s1.birth_year < s2.birth_year;
        });


    cout << "Наймолодший студент: " << youngest_student.first_name << " " << youngest_student.last_name << endl;
    cout << "Старший студент: " << oldest_student.first_name << " " << oldest_student.last_name << endl;


    // Знаходження найуспішнішого студента у кожній групі
    for (int i = 101; i <= 306; i++) {
        if (group_sizes[i] > 0) {
            auto group_begin = students.begin();
            auto group_end = students.end();
            for (int j = 0; j < i - 101; j++) {
                group_begin = find_if(group_begin, students.end(), [=](Student& s) {
                    return s.group_number == i;
                    });
            }
            group_end = find_if(group_begin, students.end(), [=](Student& s) {
                return s.group_number != i;
                });
            Student& best_student = *max_element(group_begin, group_end, [](Student& s1, Student& s2) {
                return s1.average_grade() < s2.average_grade();
                });
            cout << "Кращий студент в групі " << i << ": " << best_student.first_name << " " << best_student.last_name << endl;
        }
    }

    return 0;
};