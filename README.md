# project1
First exercise of Object Programming course, year 2.
<br>An educational application for managing and analyzing student data. It includes functionality for manual and automatic entry of student information, calculation of final marks based on different criteria (average or median), reading and sorting student data from files, and implementing various strategies for categorizing and saving student data. The application measures and displays execution times for key operations, providing insights into the performance of different data structures and strategies. The code is written in C++ and utilizes features such as file I/O, sorting algorithms, and chrono for time measurement.

## Installation
Make sure you have the following software installed on your system:
- [Visual Studio Code](https://code.visualstudio.com/)
- [GCC (GNU Compiler Collection)](https://gcc.gnu.org/)

## Getting Started

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/your-username/your-repository.git

2. **Open project in Visual Studio Code**
3. **Install C/C++ Extension**
4. **Build and Run:**
    - Open the terminal in VSCode (`View` > `Terminal` or `Ctrl + ``) and navigate to your project directory.
    - Run the build command to compile your C++ program:
        ```bash
        g++ -std=c++11 main.cpp functions.cpp -o myprogram
        ```
    - Execute the program:
        ```bash
        ./myprogram
        ```


## Visual Studio Code Configuration

If you are using Visual Studio Code to develop and run your C++ project, you may find the following configuration files useful:

### tasks.json

The `tasks.json` file in the `.vscode` directory defines build and other tasks for your project. If you've included this file in your project, you can find predefined tasks for building and running your program.

### launch.json

The `launch.json` file in the `.vscode` directory is used for configuring the debugger settings. It defines how VSCode should start and debug your program. If you've included this file in your project, you can find predefined configurations for debugging.

### How to Use

1. **Building Your Project:**
   - Open the command palette (`View` > `Command Palette` or `Ctrl + Shift + P`) and select `Run Build Task`.
   - Choose the build task corresponding to your project.

2. **Debugging Your Program:**
   - Open the `Run` sidebar (`View` > `Run` or `Ctrl + Shift + D`) and click on the "Run" button.
   - If you've set breakpoints in your code, the debugger will stop at those points.

Remember to customize these files according to your project structure and needs. If you don't have these files yet, you can create them manually or let VSCode generate them for you by running the corresponding tasks.



## Releases
### [v.pradine](https://github.com/ErikaKriks/project1/releases/tag/v.pradine)
**main.cpp** - the script for students' final mark calculations, all data is input by the user.
<br>**autogenerated.cpp** - the script for student's final make calculations, where exam mark and homework marks are generated randomly.


### [v.01](https://github.com/ErikaKriks/project1/releases/tag/v.01)
**main.cpp** - the script for students' final mark calculations, all data is input by the user.
<br>**Additional functionality**
* Reading data from a file: sample file kursiokai.txt, file structure: first name, last name, student grades and exam grade.
* Exception handling: The readStudentsFromFile function uses exception handling.
* Code formatted.


### [v.02](https://github.com/ErikaKriks/project1/releases/tag/v.02)
**main.cpp** - the script for students' final mark calculations.
<br>**Additional functionality**
* Generations of students_number.txt files with information about 1 000, 10 000, 100 000, 1 000 000, 10 000 000 students.
* Sorting students based on the Final Mark into two groups - failed and passed.
* Experiment measuring time of each process performed.


#### Results of the Experiment

| Operation                   | 1,000 Students      | 10,000 Students     | 100,000 Students    | 1,000,000 Students  | 10,000,000 Students |
| --------------------------- | ------------------- | -------------------- | ------------------- | -------------------- | -------------------- |
| Data Generation and Saving  | 0.023 seconds       | 0.095 seconds       | 0.832 seconds       | 8.452 seconds       | 91.601 seconds      |
| Reading                     | 0.002 seconds       | 0.016 seconds       | 0.187 seconds       | 2.263 seconds       | 26.528 seconds      |
| Categorization              | 0.015 seconds       | 0.090 seconds       | 0.893 seconds       | 9.152 seconds       | 93.732 seconds      |
| Saving Categorized Data     | 0.009 seconds       | 0.054 seconds       | 0.528 seconds       | 5.243 seconds       | 58.0112 seconds     |


### [v.03](https://github.com/ErikaKriks/project1/releases/tag/v.03)
**main.cpp** - the script for students' final mark calculations.
<br>**Additional functionality**
* Vector structure changed to List.
* Experiment comparing List and Vector structures efficiency performed.

Technical Specifications of Computer:
* 6-core GPU,19-core GPU
* 200GB/s memory bandwidth
* 16 GB RAM
* 512GB SSD

#### v.02 (Vectors)
| Records | Data Generation | Data Reading | Data Categorization | Data Saving| 
|--|--|--|--|--|
| 1 000 | 0.023s | 0.002s | 0.015s | 0.009s |
| 10 000 | 0.095s | 0.016s | 0.090s | 0.054s |
| 100 000 | 0.832s  | 0.187s | 0.893s | 0.528s | 
| 1 000 000 | 8.452s | 2.263s | 9.152s | 5.243s |
| 10 000 000 | 91.601s | 26.528s | 93.732s | 58.0112s |


#### v.03 (Lists)
| Records | Data Generation | Data Reading | Data Categorization | Data Saving| 
|--|--|--|--|--|
| 1 000 | 0.037s | 0.001s | 0.015s | 0.009s |
| 10 000 | 0.114s | 0.009s | 0.094s | 0.066s |
| 100 000 | 0.978s  | 0.103s | 0.931s | 0.612s | 
| 1 000 000 | 10.129s | 1.231s | 9.276s | 6.421s |
| 10 000 000 | 105.885s | 15.338s | 93.242s | 72.306s |


Data Reading from File
| Records | std::vector | std::list |
|--|--|--|
| 1 000 | 0.002s | 0.001s |
| 10 000 | 0.016s | 0.009s |
| 100 000 | 0.187s  | 0.103s | 
| 1 000 000 | 2.263s | 1.231s |
| 10 000 000 | 26.528s | 15.338s |


Data Categorization 
| Records | std::vector | std::list |
|--|--|--|
| 1 000 | 0.015s | 0.015s |
| 10 000 | 0.090s | 0.094s |
| 100 000 |  0.893s  | 0.931s |
| 1 000 000 | 9.152s | 9.276s | 
| 10 000 000 | 93.732s | 93.242s |

### [v.1.0](https://github.com/ErikaKriks/project1/releases/tag/v.1.0)
**main.cpp** - the script for students' final mark calculations, there are options to input data or data can be generated using different algorithms.
<br>**Additional functionality**
* Students categorization into Pass and Fail groups implemented using 3 strategies:
    * Strategy 1 - using two containers Fail and Pass to store information after categorization.
    * Strategy 2 - using initial container and Fail students container to store data (failing students are added to the new container and removed from the initial container).
    * Strategy 3 - improving Strategy 2 by using additional functions  __std::stable_partition__, applicable only for Vector container.
* Experiment measuring time of each process performed.

#### v.1.0 (Lists)

Data Categorization
| Records | Strategy 1 | Strategy 2 |
|--|--|--|
| 1 000 | 0.002s | 0.002s |
| 10 000 | 0.0115s | 0.0103s |
| 100 000 | 0.118s  | 0.115s | 
| 1 000 000 | 1.514s | 1.595s |
| 10 000 000 | 21.347s | 20.760s |

#### v.1.0 (Vectors)

Data Categorization
| Records | Strategy 1 | Strategy 2 | Strategy 3 |
|--|--|--|--|
| 1 000 | 0.002s | 0.0182s | 0.0004s |
| 10 000 | 0.0130s | 1.011s | 0.004s |
| 100 000 | 0.126s  | 100.477s | 0.0397s |
| 1 000 000 | 1.312s | - | 0.4109s |
| 10 000 000 | 13.723s | - | 4.350s |

Strategy 2 uses erase method, which is computationally expensive as it seems - O(n) complexity.
Strategy 3 is the most efficient one for Vector container, Strategy 2 improved program, using List container. It was not possible to get results for large vector for strategy 2.



