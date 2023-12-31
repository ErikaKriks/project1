#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sstream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "functions.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::printf;
using std::sort;
using std::ifstream;
using std::cerr;
using std::invalid_argument;
using std::runtime_error;
using std::to_string;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::ofstream;
using std::left;
using std::setw;



// Function to calculate the final mark for a student
float calculateFinalMarkAvg(const Student &student) {
    float sum = 0.0;

    if (student.marks.empty()) {
        return 0.6 * student.examMark; // If no individual marks, return 0.6 * exam mark
    }
    
    // Calculate the sum of individual marks
    for (int mark : student.marks) {
        sum += mark;
    }
    
    // Calculate the average of individual marks
    float averageMarks = sum / student.marks.size();
    
    // Calculate the final mark using the formula: 0.4 * average marks + 0.6 * exam
    return 0.4 * averageMarks + 0.6 * student.examMark;
}


// Function to calculate the final mark using median
float calculateFinalMarkMed(const Student &student) {
    if (student.marks.empty()) {
        return 0.6 * student.examMark; // If no individual marks, return 0.6 * exam mark
    }

    // Sort the individual marks
    vector<int> sortedMarks = student.marks;
    sort(sortedMarks.begin(), sortedMarks.end());
    
    int n = student.marks.size();

    // Calculate the median
    float median;
    if (n % 2 == 0) {
        // If even number of marks, take the average of the middle two
        int middle1 = sortedMarks[(n / 2) - 1];
        int middle2 = sortedMarks[n / 2];
        median = (static_cast<float>(middle1) + static_cast<float>(middle2)) / 2.0;
    } else {
        // If odd number of marks, take the middle value
        median = static_cast<float>(sortedMarks[n / 2]);
    }

    // Calculate the final mark using the formula: 0.4 * median + 0.6 * exam
    return 0.4 * median + 0.6 * student.examMark;
}

void printStudentTable(const vector<Student> &students)
{
    // Print the table header
    printf("%-20s%-20s%-20s%-20s\n", "Name", "Surname", "Final Mark (Avg.)", "Final Mark (Med.)");
    printf("-----------------------------------------------------------------------------\n");

    // Print student data in a table
    for (const Student &student : students)
    {
        printf("%-20s%-20s%-20.2f%-20.2f\n", student.name.c_str(), student.surname.c_str(), student.finalMarkAvg, student.finalMarkMed);
    }

    // Print the table footer
    printf("-----------------------------------------------------------------------------\n");
}


// Comparison function for sorting students by name and surname
bool compareStudents(const Student &student1, const Student &student2) {
    // Compare by name
    int nameComparison = student1.name.compare(student2.name);
    if (nameComparison != 0) {
        return nameComparison < 0;
    }
    
    // If names are equal, compare by surname
    return student1.surname.compare(student2.surname) < 0;
}

void readStudentsFromFile(const string &filename, vector<Student> &students)
{
    ifstream inputFile(filename);

    try {
        if (filename.empty())
        {
            throw invalid_argument("Error: File name not provided.");
        }

        if (!inputFile.is_open())
        {
            throw runtime_error("Error: Unable to open the file.");
        }

        string line;
        bool firstLine = true; // Skip the first line with headers
        int lineCount = 0;

        while (getline(inputFile, line))
        {
            ++lineCount;

            if (firstLine)
            {
                firstLine = false;
                continue; // Skip the header line
            }

            Student student;
            std::istringstream iss(line);
            string name, surname;
            int mark;

            iss >> student.name >> student.surname;

            while (iss >> mark)
            {
                student.marks.push_back(mark);
            }

            // Assign the last value in marks as the exam mark
            if (!student.marks.empty())
            {
                student.examMark = student.marks.back();
                student.marks.pop_back(); // Remove the last element from marks
            }

            if (iss.eof())
            {
                iss.clear();
                iss >> student.examMark;
            }

            students.push_back(student);
        }

        inputFile.close();
    } catch (const invalid_argument &e) {
        cerr << e.what() << endl;
        cout << "File not provided." << endl;
    } catch (const runtime_error &e) {
        cerr << e.what() << endl;
        cout << "Error opening a file: " << e.what() << endl;
}

}

// Function to generate a random student name
string generateRandomName(int studentNumber) {
    return "Vardas" + to_string(studentNumber);
}


// Function to generate a random student surname
string generateRandomSurname(int studentNumber) {
    return "Pavarde" + to_string(studentNumber);
}


// Function to generate random individual marks between 1 and 10
int generateRandomMark() {
    static default_random_engine generator(time(0));
    uniform_int_distribution<int> markDistribution(1, 10);
    return markDistribution(generator);
}


// Function to generate random student data
Student generateRandomStudent(int studentNumber, int numMarks) {
    Student student;
    student.name = generateRandomName(studentNumber);
    student.surname = generateRandomSurname(studentNumber);
    student.examMark = generateRandomMark(); // Random exam mark between 1 and 10

    for (int i = 0; i < numMarks; ++i) {
        student.marks.push_back(generateRandomMark()); // Random individual marks between 1 and 10
    }

    return student;
}

// Function to save student data to a file
void saveStudentDataToFile(const string& filename, const vector<Student>& students) {
    ofstream file(filename);

    if (file.is_open()) {
        file << left << setw(24) << "Vardas" << setw(24) << "Pavarde";
        for (int i = 1; i <= 15; ++i) {
            file << left << setw(9) << "ND" + to_string(i);
        }
        file << "Egz." << endl;

        for (const Student& student : students) {
            file << left << setw(24) << student.name << setw(24) << student.surname;
            for (int mark : student.marks) {
                file << left << setw(9) << mark;
            }
            file << student.examMark << endl;
        }

        file.close();
    } else {
        cout << "Error: Could not open file for writing." << endl;
    }
}
