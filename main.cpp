//# Project-D---Problem-15.5---Heily-Cabrera

// Reimplement Programming Project 15.11.4 so that the keys of the map are objects of class Student. 
// A student should have a first name, a last name, and a unique integer ID. 
// For grade changes and removals, lookup should be by ID. The printout should be sorted by last name. 
// If two students have the same last name, then use the first name as a tie breaker. 
// If the first names are also identical, then use the integer ID. Hint: Use two maps. // 

//Programmer: Heily Cabrera
//Tester: Audrey Tapia 

// Group Project D //
/***** Members *****/
/***** Ashley Jacobson *****/
/***** Giannfranco Brance *****/
/***** Audrey Tapia *****/
/***** Heily Cabrera Guerrero *****/

#include <iostream>
#include <map>
#include <string>

using namespace std;

void clearInput() 
{
    cin.clear();                  
    cin.ignore(1000, '\n');       
}

class Student
{
public:
    string firstname;
    string lastname;
    int id;

    Student() {}
    Student(string f, string l, int num)
      : firstname(f), lastname(l), id(num) {}

    bool operator<(const Student& other) const 
    {
        if (lastname != other.lastname)
            return lastname < other.lastname;
        if (firstname != other.firstname)
            return firstname < other.firstname;
        return id < other.id;
    }
};

int main()
{
  map<int, Student> idtoStudent;
  map<Student, double> StudentGrade;

  while (true)
    {
      cout << "\nChoose option:\n";
        cout << "1. Choose student and grade\n";
        cout << "2. Change grade by ID\n";
        cout << "3. Remove student by ID\n";
        cout << "4. Print all students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        
        if (cin.fail()) 
        {
            clearInput();
            cout << "Invalid input. Try again.\n";
            continue;
        }
        

        if (choice == 1) 
        {
            string f, l;
            int id;
            double grade;
            cout << "First name: ";
            cin >> f;
            cout << "Last name: ";
            cin >> l;
            cout << "Enter student ID: ";
            cin >> id;
            if (cin.fail()) 
            {
              clearInput();
              cout << "Invalid. Try again.\n";
              continue;
             }
            cout << "Enter grade: ";
            cin >> grade;
            {
              clearInput();
              cout << "Invalid. Try again.\n";
              continue;
             }

            Student s(f, l, id);
            idtoStudent[id] = s;
            StudentGrade[s] = grade;

            cout << "Student added.\n";

           }
            else if (choice == 2)
          {
            int id;
            double newGrade;
            cout << "Enter student ID: ";
            cin >> id;
            {
              clearInput();
              cout << "Invalid. Try again.\n";
              continue;
            }
            cout << "Enter new grade: ";
            cin >> newGrade;
            {
              clearInput();
              cout << "Invalid. Try again.\n";
              continue;
            }

            if (idtoStudent.find(id) != idtoStudent.end()) {
                Student s = idtoStudent[id];
                StudentGrade[s] = newGrade;
                cout << "Grade changed.\n";
            } 
            else 
            {
                cout << "Student ID not found.\n";
            }
        }
        else if (choice == 3) 
        {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            {
              clearInput();
              cout << "Invalid. Try again.\n";
              continue;
            }

            if (idtoStudent.find(id) != idtoStudent.end()) 
            {
                Student s = idtoStudent[id];
                idtoStudent.erase(id);
                StudentGrade.erase(s);
                cout << "Student removed.\n";
            } 
            else 
            {
                cout << "Student ID not found.\n";
            }
        }
        else if (choice == 4) 
        {
            cout << "\nStudent list:\n";
            for (const auto& entry : StudentGrade) 
            {
                const Student& s = entry.first;
                double grade = entry.second;
                cout << s.lastname << ", " << s.firstname
                     << " (ID: " << s.id << ") - Grade: " << grade << endl;
            }
        }
        else if (choice == 5) 
        {
            cout << "Bye bye\n";
            break;
        }
        else 
        {
            cout << "Invalid\n";
        }
    }

    return 0;
}

