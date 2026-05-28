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
    int getAge() { return age; }
    long getPhone() { return phone; }
    long getCellPhone() { return cellPhone; }
    string getFatherName() { return fatherName; }
    bool getIsMarried() { return isMarried; }
    string getFamilyMembers() { return familyMembers; }
    string getPlaceOfBirth() { return placeOfBirth; }

    // Setters
    void setName(string n) { name = n; }
    void setFirstName(string fn) { firstName = fn; }
    void setAge(int a) { age = a; }
    void setPhone(long p) { phone = p; }
    void setCellPhone(long cp) { cellPhone = cp; }
    void setFatherName(string fName) { fatherName = fName; }
    void setIsMarried(bool married) { isMarried = married; }
    void setFamilyMembers(string fam) { familyMembers = fam; }
    void setPlaceOfBirth(string pob) { placeOfBirth = pob; }

    void printInfo()
    {
        cout << "Last Name: " << getName() << " First Name: " << getFirstName() << " \n";
    }

    // Virtual destructor
    virtual ~DeltaMember() {}
};

// ================= STUDENT =================
class Student : public DeltaMember {
private:
    vector<int> grades;
    string course;;

public:
    Student(string n, string fn, int a, long p, long cp,
            string fName, bool married, string fam, string pob,
            vector<int> g, string sClass)
        : DeltaMember(n, fn, a, p, cp, fName, married, fam, pob),
          grades(g), course(sClass) {}

    // Getters
    vector<int> getGrades() { return grades; }
    string getCourse() { return course; }

    // Setters
    void setGrades(vector<int> g) { grades = g; }
    void setCourse(string sClass) { course = sClass; }

    double getAverage() {
        double sum = 0;
        for (int g : grades) sum += g;
        return sum / grades.size();
    }
    
    void printInfo()
    {
        DeltaMember::printInfo();
        cout << "Course: " << getCourse() << " Average:" << getAverage() << " \n";
        cout << "------------------------------------------------" << " \n";
    }
};

// ================= TEACHER =================
class Teacher : public DeltaMember {
private:
    double salary;
    string bachelors;
    string masters;
    int yearsExperience;
    

public:
    Teacher(string n, string fn, int a, long p, long cp,
            string fName, bool married, string fam, string pob,
            double sal, string bach, string mast, int years)
        : DeltaMember(n, fn, a, p, cp, fName, married, fam, pob),
          salary(sal), bachelors(bach), masters(mast), yearsExperience(years) {}    

    // Getters
    double getSalary() const { return salary; }
    int getYearsExperience() const { return yearsExperience; }
    string getBachelors() const { return bachelors; }
    string getMasters() const { return masters; }

    // Setters
    void setSalary(double sal) { salary = sal; }
    void setYearsExperience(int years) { yearsExperience = years; }
    void setBachelors(string bach) { bachelors = bach; }
    void setMasters(string mast) { masters = mast; }

    int getNumberOfDegrees() const {
        int count = 0;
        if (!bachelors.empty() && bachelors != "None") count++;
        if (!masters.empty() && masters != "None") count++;
        return count;
    }
    
    void printInfo()
    {
        DeltaMember::printInfo();
        cout << "Salary: " << getSalary() << " Bachelor: " << getBachelors() << " Master: " << getMasters() << " Years Experience: " << getYearsExperience() << " \n";
        cout << "------------------------------------------------" << " \n";
    }
};

// ================= MAIN =================
int main() {

    vector<Teacher> teachers = {
        Teacher("Aris","Pappas",45,2105551234,6970000001,"Georgios",true,"1-2 Children","Athens",2500,"Mathematics","Algebraic Topology",5),
        Teacher("Olga","Markou",38,2105555678,6970000002,"Dimitrios",false,"None","Thessaloniki",2100,"Physics","Quantum Mechanics",7),
        Teacher("Nikos","Fourakis",50,2105559012,6970000003,"Ioannis",true,"1-2 Children","Patras",2800,"Literature","Creative Writing",3),
        Teacher("Mania","Zanna",32,2105553456,6970000004,"Vasileios",false,"None","Heraklion",1900,"History","Ancient Civilizations",5)
    };

    vector<Student> students = {
        Student("Eleni","Karra",15,2101112222,6980000001,"Antonios",false,"Parents","Larissa",{9,10,8,9,10,9,8,7,9,10},"Mathematics"),
        Student("Petros","Ladas",16,2101113333,6980000002,"Petros",true,"Parents","Volos",{5,4,6,5,7,4,5,6,5,6},"Mathematics"),
        Student("Maria","Dimou",14,2101114444,6980000003,"Christos",false,"Parents","Ioannina",{10,10,9,10,10,9,10,10,9,10},"Information Technology"),
        Student("Elvis","Gikas",17,2101115555,6980000004,"Stavros",true,"Parents","Chania",{7,8,7,6,7,8,9,7,8,7},"Information Technology"),
        Student("Maria","Noe",15,2101116666,6980000005,"Emmanouil",false,"Parents","Rhodes",{9,8,9,10,8,9,8,9,10,9},"Information Technology"),
        Student("Giannis","Vergis",16,2101117777,6980000006,"Michail",false,"None","Kalamata",{4,3,5,2,6,3,4,2,5,3},"Information Technology")
    };
    
    vector<DeltaMember> members = {
        teachers[0], teachers[1], teachers[2], teachers[3],
        students[0], students[1], students[2], students[3], students[4], students[5]
    };

    // ================= PRINT ALL MEMBERS =================
    cout << "\n--- All Members ---\n";
    for (auto &m : members)
    {
        m.printInfo();
    }

    // ================= PRINT STUDENTS WITH AVERAGE GRADE =================
    cout << "Students with Average Grade:\n";
    for (auto &s : students)
    {
        cout << s.getName() << " " << s.getFirstName() << " - Average Grade: " << s.getAverage() << '\n';
    }

    // ================= PRINT TEACHERS WITH NUMBER OF DEGREES =================
    cout << "Teachers with Number of Degrees:\n";
    for (auto &t : teachers)
    {
        cout << t.getName() << " " << t.getFirstName() << " - Number of Degrees: " << t.getNumberOfDegrees() << '\n';
    }

    // ================= PRINT TEACHERS WITH YEARS EXPERIENCE =================
    cout << "Teachers with Years Experience:\n";
    for (auto &t : teachers)
    {
        cout << t.getName() << " " << t.getFirstName() << " - Years Experience: " << t.getYearsExperience() << '\n';
    }

    // ================= MARRIED MEMBERS =================
    cout << "\nMarried Members:\n";
    for (auto &s : members)
        if (s.getIsMarried())
            cout << s.getName() << " " << s.getFirstName() << '\n';

    // ================= AVG SALARY =================
    double sumSalary = 0;
    for (auto &t : teachers) sumSalary += t.getSalary();
    cout << "\nAverage Salary: " << sumSalary / teachers.size() << '\n';

    // ================= AVG GRADE ALL STUDENTS =================
    double totalAvg = 0;
    for (auto &s : students) totalAvg += s.getAverage();
    cout << "Average Student Grade: " << totalAvg / students.size() << '\n';

    return 0;
}