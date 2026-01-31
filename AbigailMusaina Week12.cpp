#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Forward declaration to handle Dependency
class Course; 

// --- COURSE CLASS ---
class Course {
public:
    std::string courseCode;
    std::string title;
    int credits;

    Course(std::string code, std::string t, int c) 
        : courseCode(code), title(t), credits(c) {}

    void display() const {
        std::cout << "[" << courseCode << "] " << title << " (" << credits << " Credits)" << std::endl;
    }
};

// STUDENT CLASS 
class Student {
public:
    std::string studentID;
    std::string name;
    
    // ASSOCIATION: Student 'knows' many Courses via pointers
    std::vector<Course*> enrolledCourses;

    Student(std::string id, std::string n) : studentID(id), name(n) {}

    void showSchedule() const {
        std::cout << "\n--- Schedule for " << name << " (" << studentID << ") ---" << std::endl;
        if (enrolledCourses.empty()) {
            std::cout << "No courses enrolled." << std::endl;
        } else {
            for (const auto& course : enrolledCourses) {
                std::cout << " * ";
                course->display();
            }
        }
        std::cout << "------------------------------------------" << std::endl;
    }
};

//  REGISTRAR CLASS
class Registrar {
public:
   #include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Forward declaration to handle Dependency
class Course; 

// --- COURSE CLASS ---
class Course {
public:
    std::string courseCode;
    std::string title;
    int credits;

    Course(std::string code, std::string t, int c) 
        : courseCode(code), title(t), credits(c) {}

    void display() const {
        std::cout << "[" << courseCode << "] " << title << " (" << credits << " Credits)" << std::endl;
    }
};

// --- STUDENT CLASS ---
class Student {
public:
    std::string studentID;
    std::string name;
    
    // ASSOCIATION: Student 'knows' many Courses via pointers
    std::vector<Course*> enrolledCourses;

    Student(std::string id, std::string n) : studentID(id), name(n) {}

    void showSchedule() const {
        std::cout << "\n--- Schedule for " << name << " (" << studentID << ") ---" << std::endl;
        if (enrolledCourses.empty()) {
            std::cout << "No courses enrolled." << std::endl;
        } else {
            for (const auto& course : enrolledCourses) {
                std::cout << " * ";
                course->display();
            }
        }
        std::cout << "------------------------------------------" << std::endl;
    }
};

// --- REGISTRAR CLASS ---
class Registrar {
public:
    /**
     * DEPENDENCY: This method depends on Student and Course objects.
     * It does not own them, it just facilitates the relationship.
     */
    void enroll(Student& student, Course& course) {
        // Check if already enrolled
        for (auto c : student.enrolledCourses) {
            if (c->courseCode == course.courseCode) {
                std::cout << "Error: " << student.name << " is already in " << course.title << std::endl;
                return;
            }
        }

        // Establish the Association
        student.enrolledCourses.push_back(&course);
        std::cout << "Success: " << student.name << " registered for " << course.courseCode << std::endl;
    }
};

//  MAIN EXECUTION 
int main() {
    // 1. Initialize objects
    Registrar registrar;
    
    Course math101("MATH101", "Calculus I", 4);
    Course cs101("CS101", "Intro to C++", 3);
    
    Student s1("2026-001", "Alice");
    Student s2("2026-002", "Bob");

    // 2. Demonstrate Dependency
    // The registrar is used to link students and courses
    std::cout << "--- Registration Process ---" << std::endl;
    registrar.enroll(s1, math101);
    registrar.enroll(s1, cs101);
    registrar.enroll(s2, cs101);
    
    // Attempting duplicate
    registrar.enroll(s1, math101);

    // 3. Demonstrate Association
    // The data now lives inside the student objects
    s1.showSchedule();
    s2.showSchedule();

    return 0;
}
    void enroll(Student& student, Course& course) {
        // Check if already enrolled
        for (auto c : student.enrolledCourses) {
            if (c->courseCode == course.courseCode) {
                std::cout << "Error: " << student.name << " is already in " << course.title << std::endl;
                return;
            }
        }

        // Establish the Association
        student.enrolledCourses.push_back(&course);
        std::cout << "Success: " << student.name << " registered for " << course.courseCode << std::endl;
    }
};

//  MAIN EXECUTION
int main() {
    // 1. Initialize objects
    Registrar registrar;
    
    Course math101("MATH101", "Calculus I", 4);
    Course cs101("CS101", "Intro to C++", 3);
    
    Student s1("2026-001", "Alice");
    Student s2("2026-002", "Bob");

    // 2. Demonstrate Dependency
    
    std::cout << "--- Registration Process ---" << std::endl;
    registrar.enroll(s1, math101);
    registrar.enroll(s1, cs101);
    registrar.enroll(s2, cs101);
    
    // Attempting duplicate
    registrar.enroll(s1, math101);

    // 3. Demonstrate Association

    s1.showSchedule();
    s2.showSchedule();

    return 0;
}