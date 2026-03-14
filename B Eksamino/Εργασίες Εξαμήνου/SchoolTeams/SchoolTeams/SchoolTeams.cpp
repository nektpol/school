#include <iostream>
#include <iomanip>
#include <vector>
#include "Student.h"
#include "TeamMember.h"

using namespace std;

// -----------------------------------------------
// Navigation signal returned by all menu functions
// -----------------------------------------------
enum class MenuSignal { Back, End };

// -----------------------------------------------
// Input helpers
// -----------------------------------------------
bool isEndCommand(const string& input)
{
    return input == "end" || input == "End" || input == "END";
}

bool isBackCommand(const string& input)
{
    return input == "back" || input == "Back" || input == "BACK";
}

// -----------------------------------------------
// Student helpers
// -----------------------------------------------
void printStudentsTable(vector<Student>& students)
{
    cout << "\nStudents Table\n";
    cout << "---------------------------------------\n";
    cout << left << setw(8) << "Index" << setw(20) << "Last Name" << "First Name\n";
    cout << "---------------------------------------\n";

    for (size_t i = 0; i < students.size(); ++i)
    {
        cout << left << setw(8) << (i + 1)
             << setw(20) << students[i].getLastName()
             << students[i].getFirstName() << '\n';
    }
}

enum class ParseResult { Valid, InvalidFormat, OutOfRange };

ParseResult parseStudentIndex(const string& input, size_t totalStudents, int& index)
{
    try
    {
        index = stoi(input);
    }
    catch (...)
    {
        return ParseResult::InvalidFormat;
    }

    if (index < 1 || index > static_cast<int>(totalStudents))
        return ParseResult::OutOfRange;

    return ParseResult::Valid;
}

MenuSignal runStudentLookup(vector<Student>& students)
{
    printStudentsTable(students);

    while (true)
    {
        string input;
        cout << "\nEnter student index (1-" << students.size()
             << "), \"back\", or \"end\": " << flush;
        getline(cin, input);

        if (isEndCommand(input))  return MenuSignal::End;
        if (isBackCommand(input)) return MenuSignal::Back;

        int index = 0;
        ParseResult result = parseStudentIndex(input, students.size(), index);

        if (result == ParseResult::OutOfRange)
        {
            cout << "Invalid index. Please enter a number between 1 and "
                 << students.size() << ".\n";
            continue;
        }

        if (result == ParseResult::InvalidFormat)
        {
            cout << "Invalid input. Type a valid index, \"back\", or \"end\".\n";
            continue;
        }

        students[index - 1].print();
    }
}

// -----------------------------------------------
// Teams helpers
// -----------------------------------------------
void printAllTeams(vector<TeamMember>& teams)
{
    cout << '\n';
    for (size_t i = 0; i < teams.size(); ++i)
        teams[i].print();
}

MenuSignal runTeamsMenu(vector<TeamMember>& teams)
{
    printAllTeams(teams);

    while (true)
    {
        string input;
        cout << "\nType \"back\" to return to main menu or \"end\" to exit: " << flush;
        getline(cin, input);

        if (isEndCommand(input))  return MenuSignal::End;
        if (isBackCommand(input)) return MenuSignal::Back;

        cout << "Invalid input. Type \"back\" or \"end\".\n";
    }
}

// -----------------------------------------------
// Main menu
// -----------------------------------------------
void runMainMenu(vector<Student>& students, vector<TeamMember>& teams)
{
    while (true)
    {
        cout << "\n=== Main Menu ===\n";
        cout << "  1. Show Teams\n";
        cout << "  2. Show Students\n";
        cout << "Type \"back\" to confirm exit or \"end\" to exit immediately.\n";
        cout << "Choice: " << flush;

        string input;
        getline(cin, input);

        if (isEndCommand(input))
        {
            cout << "Exiting...\n";
            break;
        }

        if (isBackCommand(input))
        {
            string confirm;
            cout << "Are you sure you want to exit? (y/n): " << flush;
            getline(cin, confirm);
            if (confirm == "y" || confirm == "Y")
            {
                cout << "Exiting...\n";
                break;
            }
            continue;
        }

        if (input == "1")
        {
            if (runTeamsMenu(teams) == MenuSignal::End)
            {
                cout << "Exiting...\n";
                break;
            }
        }
        else if (input == "2")
        {
            if (runStudentLookup(students) == MenuSignal::End)
            {
                cout << "Exiting...\n";
                break;
            }
        }
        else
        {
            cout << "Invalid choice. Press 1, 2, type \"back\", or \"end\".\n";
        }
    }
}

// -----------------------------------------------
// Entry point
// -----------------------------------------------
int main(int argc, char* argv[])
{
    // Students
    Student s1(1,"Papadopoulos","Nikos","Giorgos","10/02/2002","6900000001","Athens","Informatics");
    Student s2(2,"Ioannou","Maria","Kostas","12/04/2001","6900000002","Athens","Mechanical");
    Student s3(3,"Kostas","Petros","Dimitris","05/03/2002","6900000003","Athens","Informatics");
    Student s4(4,"Nikolaou","Anna","Spyros","07/08/2001","6900000004","Athens","Mechanical");
    Student s5(5,"Karalis","John","Panos","02/11/2002","6900000005","Athens","Informatics");
    Student s6(6,"Manos","Giorgos","Nikos","03/06/2001","6900000006","Athens","Mechanical");
    Student s7(7,"Petrou","Sofia","Nikos","11/07/2002","6900000007","Athens","Informatics");
    Student s8(8,"Kiriakou","Dimitris","Antonis","19/01/2002","6900000008","Athens","Mechanical");
    Student s9(9,"Rigas","Manos","Petros","13/05/2001","6900000009","Athens","Informatics");
    Student s10(10,"Galanis","Spyros","Nikos","23/03/2002","6900000010","Athens","Mechanical");
    Student s11(11,"Kostas","Anna","Petros","03/03/2002","6900000011","Athens","Informatics");
    Student s12(12,"Antonopoulos","Maria","Giorgos","05/04/2001","6900000012","Athens","Mechanical");
    Student s13(13,"Dimas","Nikos","Panos","09/08/2002","6900000013","Athens","Informatics");
    Student s14(14,"Pappas","Eleni","Nikos","11/10/2001","6900000014","Athens","Mechanical");
    Student s15(15,"Kotsis","Manos","Dimitris","14/02/2002","6900000015","Athens","Informatics");

    vector<Student> students = {
        s1, s2, s3, s4, s5,
        s6, s7, s8, s9, s10,
        s11, s12, s13, s14, s15
    };

    // Teams
    TeamMember team1(100,"Delta Coders","Hackers",95,10,"Coach Nikos","Informatics",1,3,5,7,9);
    TeamMember team2(200,"Delta Mechanics","Iron Team",88,12,"Coach Giorgos","Mechanical",2,4,6,8,10);

    vector<TeamMember> teams = { team1, team2 };

    runMainMenu(students, teams);

    return 0;
}
