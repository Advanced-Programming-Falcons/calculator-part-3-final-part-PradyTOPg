#include <iostream>
#include <string>
#include <vector>
#include <functional> // for std::reference_wrapper

using namespace std;

// -------------------
// Teacher class
// -------------------
class Teacher {
private:
    string m_name;

public:
    Teacher(string name) : m_name(name) {
        cout << "Another Teacher Graduated! Name: " << m_name << endl;
    }

    ~Teacher() {
        cout << "Teacher " << m_name << " has left the school." << endl;
    }

    string get_name() const {
        return m_name;
    }
};

// -------------------
// Experiment 1: Single teacher aggregation using reference
// -------------------
class DepartmentRef {
private:
    Teacher& m_teacher;   // Reference to a Teacher (aggregation: no ownership)

public:
    DepartmentRef(Teacher& teacher) : m_teacher(teacher) {
        cout << "Department (Ref) created." << endl;
    }

    void print_teacher() const {
        cout << "Department has teacher: " << m_teacher.get_name() << endl;
    }

    ~DepartmentRef() {
        cout << "Department (Ref) destroyed." << endl;
    }
};

// -------------------
// Experiment 2: Single teacher aggregation using pointer
// -------------------
class DepartmentPtr {
private:
    const Teacher* m_teacherPtr;  // Pointer to Teacher (aggregation, no ownership)

public:
    DepartmentPtr(const Teacher* teacherPtr) : m_teacherPtr(teacherPtr) {
        cout << "Department (Ptr) created." << endl;
    }

    void print_teacher() const {
        if (m_teacherPtr)
            cout << "Department has teacher: " << m_teacherPtr->get_name() << endl;
        else
            cout << "Department has no teacher assigned." << endl;
    }

    ~DepartmentPtr() {
        cout << "Department (Ptr) destroyed." << endl;
    }
};

// -------------------
// Experiment 3: Multiple teachers using vector of pointers (aggregation)
// -------------------
class DepartmentMultiPtr {
private:
    vector<const Teacher*> m_teachers;

public:
    DepartmentMultiPtr(const vector<const Teacher*>& teachers) : m_teachers(teachers) {
        cout << "Department (MultiPtr) created with multiple teachers." << endl;
    }

    void print_teachers() const {
        cout << "Department has teachers:" << endl;
        for (const auto* teacher : m_teachers) {
            if (teacher)
                cout << "- " << teacher->get_name() << endl;
        }
    }

    ~DepartmentMultiPtr() {
        cout << "Department (MultiPtr) destroyed." << endl;
    }
};

// -------------------
// Experiment 4: Multiple teachers using std::reference_wrapper
// -------------------
class DepartmentMultiRefWrapper {
private:
    vector<reference_wrapper<const Teacher>> m_teachers;

public:
    DepartmentMultiRefWrapper(const vector<reference_wrapper<const Teacher>>& teachers)
        : m_teachers(teachers) {
        cout << "Department (MultiRefWrapper) created with multiple teachers." << endl;
    }

    void print_teachers() const {
        cout << "Department has teachers:" << endl;
        for (const auto& ref : m_teachers) {
            cout << "- " << ref.get().get_name() << endl;
        }
    }

    ~DepartmentMultiRefWrapper() {
        cout << "Department (MultiRefWrapper) destroyed." << endl;
    }
};

// -------------------
// Main function: run all experiments and illustrate aggregation concepts
// -------------------
int main() {
    cout << "----- Experiment 1: Single teacher (reference) -----" << endl;
    {
        Teacher bob("Bob");
        {
            DepartmentRef deptRef(bob);
            deptRef.print_teacher();
            // When DepartmentRef is destroyed here, Teacher bob still alive
        }
        cout << "Back in main: Teacher is still alive: " << bob.get_name() << endl;
    }
    cout << endl;

    cout << "----- Experiment 2: Single teacher (pointer) -----" << endl;
    {
        Teacher alice("Alice");
        {
            DepartmentPtr deptPtr(&alice);
            deptPtr.print_teacher();
            // When DepartmentPtr destroyed here, Teacher alice still alive
        }
        cout << "Back in main: Teacher is still alive: " << alice.get_name() << endl;

        // Dangerous example: if Teacher destroyed before DepartmentPtr pointer access,
        // pointer would dangle, causing undefined behavior.
    }
    cout << endl;

    cout << "----- Experiment 3: Multiple teachers (vector of pointers) -----" << endl;
    {
        Teacher tom("Tom");
        Teacher jerry("Jerry");

        vector<const Teacher*> teachers = { &tom, &jerry };
        DepartmentMultiPtr deptMultiPtr(teachers);
        deptMultiPtr.print_teachers();

        // Destroy Tom before Department
        cout << "Destroying Tom before DepartmentMultiPtr..." << endl;
    }
    cout << endl;

    cout << "----- Experiment 4: Multiple teachers (std::reference_wrapper) -----" << endl;
    {
        Teacher steve("Steve");
        Teacher bill("Bill");

        vector<reference_wrapper<const Teacher>> teachersRef = { steve, bill };
        DepartmentMultiRefWrapper deptMultiRef(teachersRef);
        deptMultiRef.print_teachers();
    }
    cout << endl;

    return 0;
}

