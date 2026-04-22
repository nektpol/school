#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ================= SUPER CLASS =================
class DeltaMember {
protected:
    string name;
    string firstName;
    int age;
    long phone;
    long cellPhone;
    string fatherName;
    bool isMarried;
    string familyMembers;
    string placeOfBirth;

public:
    // Constructor
    DeltaMember(string n, string fn, int a, long p, long cp,
                string fName, bool married, string fam, string pob)
        : name(n), firstName(fn), age(a), phone(p), cellPhone(cp),
          fatherName(fName), isMarried(married),
          familyMembers(fam), placeOfBirth(pob) {}

    // Getters
    string getName() { return name; }
    string getFirstName() { return firstName; }
    string getFatherName() { return fatherName; }
    bool getIsMarried() { return isMarried; }

    // Virtual destructor
    virtual ~DeltaMember() {}
};

// ================= STUDENT =================
class Student : public DeltaMember {
private:
    vector<int> grades;
    string studentClass;

public:
    Student(string n, string fn, int a, long p, long cp,
            string fName, bool married, string fam, string pob,
            vector<int> g, string sClass)
        : DeltaMember(n, fn, a, p, cp, fName, married, fam, pob),
          grades(g), studentClass(sClass) {}

    double getAverage() {
        double sum = 0;
        for (int g : grades) sum += g;
        return sum / grades.size();
    }
};

// ================= TEACHER =================
class Teacher : public DeltaMember {
private:
    double salary;
    string bachelor;
    int yearsExperience;
    string course;

public:
    Teacher(string n, string fn, int a, long p, long cp,
            string fName, bool married, string fam, string pob,
            double sal, string bach, int years, string c = "")
        : DeltaMember(n, fn, a, p, cp, fName, married, fam, pob),
          salary(sal), bachelor(bach),
          yearsExperience(years), course(c) {}

    double getSalary() { return salary; }
    int getYearsExperience() { return yearsExperience; }

    int getDegreesCount() {
        int count = 0;
        if (bachelor != "") count++;
        return count; // απλό για άσκηση
    }
};

// ================= MAIN =================
int main() {

    vector<Teacher> teachers = {
        Teacher("Aris","Pappas",45,2105551234,6970000001,"Georgios",true,"1-2 Children","Athens",2500,"Mathematics",20,"Algebraic Topology"),
        Teacher("Olga","Markou",38,2105555678,6970000002,"Dimitrios",false,"None","Thessaloniki",2100,"Physics",12),
        Teacher("Nikos","Fourakis",50,2105559012,6970000003,"Ioannis",true,"1-2 Children","Patras",2800,"Literature",25,"Creative Writing"),
        Teacher("Mania","Zanna",32,2105553456,6970000004,"Vasileios",false,"None","Heraklion",1900,"History",5)
    };

    vector<Student> students = {
        Student("Eleni","Karra",15,2101112222,6980000001,"Antonios",false,"Parents","Larissa",{9,10,8,9,10,9,8,7,9,10},"Class A"),
        Student("Petros","Ladas",16,2101113333,6980000002,"Petros",true,"Parents","Volos",{5,4,6,5,7,4,5,6,5,6},"Class B"),
        Student("Maria","Dimou",14,2101114444,6980000003,"Christos",false,"Parents","Ioannina",{10,10,9,10,10,9,10,10,9,10},"Class A"),
        Student("Elvis","Gikas",17,2101115555,6980000004,"Stavros",true,"Parents","Chania",{7,8,7,6,7,8,9,7,8,7},"Class C"),
        Student("Maria","Noe",15,2101116666,6980000005,"Emmanouil",false,"Parents","Rhodes",{9,8,9,10,8,9,8,9,10,9},"Class B"),
        Student("Giannis","Vergis",16,2101117777,6980000006,"Michail",false,"None","Kalamata",{4,3,5,2,6,3,4,2,5,3},"Class C")
    };

    // ================= PRINT ALL MEMBERS =================
    cout << "\n--- All Members ---\n";
    for (auto &t : teachers)
        cout << t.getName() << " " << t.getFirstName() << " (Teacher)\n";

    for (auto &s : students)
        cout << s.getName() << " " << s.getFirstName() << " (Student)\n";

    // ================= STUDENT AVERAGE =================
    cout << "\n--- Student Averages ---\n";
    for (auto &s : students)
        cout << s.getName() << " " << s.getFirstName()
             << " Avg: " << s.getAverage() << endl;

    // ================= TEACHER DATA =================
    cout << "\n--- Teachers Experience ---\n";
    for (auto &t : teachers)
        cout << t.getName() << " " << t.getFirstName()
             << " Years: " << t.getYearsExperience() << endl;

    // ================= MARRIED MEMBERS =================
    cout << "\n--- Married Members ---\n";
    for (auto &t : teachers)
        if (t.getIsMarried())
            cout << t.getName() << " " << t.getFirstName() << endl;

    for (auto &s : students)
        if (s.getIsMarried())
            cout << s.getName() << " " << s.getFirstName() << endl;

    // ================= AVG SALARY =================
    double sumSalary = 0;
    for (auto &t : teachers) sumSalary += t.getSalary();
    cout << "\nAverage Salary: " << sumSalary / teachers.size() << endl;

    // ================= AVG GRADE ALL STUDENTS =================
    double totalAvg = 0;
    for (auto &s : students) totalAvg += s.getAverage();
    cout << "Average Student Grade: " << totalAvg / students.size() << endl;

    return 0;
}