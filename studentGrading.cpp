#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Student {
    std::string name;
    float grade;
};

std::vector<Student> getStudentGrades() {
    std::vector<Student> students;
    while (true) {
        std::string studentName;
        std::cout << "Enter student name (or 'quit' to exit): ";
        std::getline(std::cin, studentName);

        if (studentName == "quit") {
            break;
        }

        std::string gradeInput;
        std::cout << "Enter grade for " << studentName << ": ";
        std::getline(std::cin, gradeInput);
        float grade = std::stof(gradeInput);

        students.push_back({ studentName, grade });
    }
    return students;
}

float calculateAverageGrade(const std::vector<Student>& students) {
    float totalGrades = 0.0f;
    for (const auto& student : students) {
        totalGrades += student.grade;
    }
    float averageGrade = totalGrades / students.size();
    return averageGrade;
}

void displayHighestAndLowestGrades(const std::vector<Student>& students) {
    float highestGrade = std::numeric_limits<float>::min();
    float lowestGrade = std::numeric_limits<float>::max();
    std::vector<std::string> highestGradeStudents;
    std::vector<std::string> lowestGradeStudents;

    for (const auto& student : students) {
        float grade = student.grade;
        if (grade > highestGrade) {
            highestGrade = grade;
            highestGradeStudents = { student.name };
        } else if (grade == highestGrade) {
            highestGradeStudents.push_back(student.name);
        }

        if (grade < lowestGrade) {
            lowestGrade = grade;
            lowestGradeStudents = { student.name };
        } else if (grade == lowestGrade) {
            lowestGradeStudents.push_back(student.name);
        }
    }

    std::cout << "Highest Grade: " << highestGrade << std::endl;
    std::cout << "Students with the highest grade:" << std::endl;
    for (const std::string& student : highestGradeStudents) {
        std::cout << student << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Lowest Grade: " << lowestGrade << std::endl;
    std::cout << "Students with the lowest grade:" << std::endl;
    for (const std::string& student : lowestGradeStudents) {
        std::cout << student << std::endl;
    }
}

int main() {
    std::cout << "=== Student Grading System ===" << std::endl;
    std::cout << "Enter student names and their course grades." << std::endl;

    std::vector<Student> students = getStudentGrades();

    if (!students.empty()) {
        float averageGrade = calculateAverageGrade(students);
        std::cout << std::endl;
        std::cout << "Average Grade: " << averageGrade << std::endl;
        displayHighestAndLowestGrades(students);
    } else {
        std::cout << "No grades entered. Exiting..." << std::endl;
    }

    return 0;
}