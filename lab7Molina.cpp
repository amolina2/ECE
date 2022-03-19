#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <typeinfo>
#include <stdlib.h>

using namespace std;

template <class DType, class SType>
bool instanceof (const SType *src)
{
    return dynamic_cast<const DType *>(src) != nullptr;
}

enum Department
{
    BIO,
    CHEM,
    CS,
    PHYS,
    MATH,
    OTHER
};

class Person
{
private:
    int ID;
    string firstName;
    string lastName;
    Person *next;

public:
    Person();
    Person(int inID, string inFirst, string inLast);
    Person(Person &pls);
    virtual ~Person();
    Person &operator=(Person const &p)
    {
        this->ID = p.ID;
        setFirstName(p.firstName);
        setLastName(p.lastName);
        this->next = p.next;

        return *this;
    }

    // Get and set
    int getID()
    {
        return ID;
    }
    void setID(int inID)
    {
        ID = inID;
    }
    //-------------------

    string getFirstName()
    {
        return firstName;
    }
    void setFirstName(string inFirst)
    {
        this->firstName = inFirst;
    }

    //---------------

    string getLastName()
    {
        return lastName;
    }
    void setLastName(string inLast)
    {
        this->lastName = inLast;
    }

    //------------------

    Person *getNext()
    {
        return next;
    }

    void setNext(Person *next_in)
    {
        next = next_in;
    }
};

Person *frontP = NULL;

Person ::Person() // default constructor
{
    this->ID = 0000;
    this->firstName = "";
    this->lastName = "";
    this->next = NULL;
}

Person ::Person(int inID, string inFirst, string inLast) // parametrized constructor
{
    this->ID = inID;
    this->firstName = inFirst;
    this->lastName = inLast;
    this->next = NULL;
}

Person ::Person(Person &pls) // copy constructor
{
    this->ID = pls.ID;
    this->firstName = "";
    this->lastName = "";
    setFirstName(pls.firstName);
    setLastName(pls.lastName);
    this->next = pls.next;
}

Person ::~Person() // destructor
{
}

class Student : public Person
{
private:
    float GPA;

public:
    Student();
    Student(int inID, string inFirst, string inLast, float gpa_in);
    Student(Student &pls);
    ~Student();
    float getGPA()
    {
        return GPA;
    }

    void setGPA(float gpa_in)
    {
        GPA = gpa_in;
    }
};

Student ::Student() // default constructor
{
    this->setID(0000);
    this->setFirstName("");
    this->setLastName("");
    this->GPA = 0.0;
    this->setNext(NULL);
}

Student ::Student(int inID, string inFirst, string inLast, float gpa_in) // parametrized constructor
{
    setID(inID);
    setFirstName(inFirst);
    setLastName(inLast);
    this->GPA = gpa_in;
    this->setNext(NULL);
}

Student ::Student(Student &pls) // copy construcotr
{
    this->setID(pls.getID());
    this->setGPA(pls.GPA);
    this->setFirstName(pls.getFirstName());
    this->setLastName(pls.getLastName());
    this->setNext(pls.getNext());
}

Student ::~Student() // destructor
{
}

class Employee : public Person
{
private:
    float salary;

public:
    Employee();
    Employee(int inID, string inFirst, string inLast, float salary_in);
    Employee(Employee &pls);
    ~Employee();
    float getSalary()
    {
        return salary;
    }

    void setSalary(float salary_in)
    {
        salary = salary_in;
    }
};

Employee ::Employee() // default constructor
{
    this->setID(0000);
    this->setFirstName("");
    this->setLastName("");
    this->salary = 0.0;
    this->setNext(NULL);
}

Employee ::Employee(int inID, string inFirst, string inLast, float salary_in) // parametrized constructor
{
    setID(inID);
    setFirstName(inFirst);
    setLastName(inLast);
    this->salary = salary_in;
    this->setNext(NULL);
}

Employee ::Employee(Employee &pls) // copy constructor
{
    this->setID(pls.getID());
    this->setSalary(pls.salary);
    this->setFirstName(pls.getFirstName());
    this->setLastName(pls.getLastName());
    this->setNext(pls.getNext());
}

Employee ::~Employee() // destructor
{
}

class Professor : public Employee
{
private:
    bool tenured;
    Department department;

public:
    Professor();
    Professor(int inID, string inFirst, string inLast, float salary_in, bool tenured_in, Department department_in);
    Professor(Professor &pls);
    ~Professor();
    bool getTenured()
    {
        return tenured;
    }
    Department getDepartment()
    {
        return department;
    }

    void setTenured(bool tenured_in)
    {
        tenured = tenured_in;
    }
    void setDepartment(Department department_in)
    {
        department = department_in;
    }
};

Professor ::Professor()
{
    this->setID(0000);
    this->setFirstName("");
    this->setLastName("");
    this->setSalary(0.0);
    this->tenured = false;
    this->department = OTHER;
    this->setNext(NULL);
}

Professor ::Professor(int inID, string inFirst, string inLast, float salary_in, bool tenured_in, Department department_in)
{
    setID(inID);
    setFirstName(inFirst);
    setLastName(inLast);
    setSalary(salary_in);
    this->tenured = tenured_in;
    this->department = department_in;
    this->setNext(NULL);
}

Professor ::Professor(Professor &pls)
{
    this->setID(pls.getID());
    this->setSalary(pls.getSalary());
    this->setFirstName(pls.getFirstName());
    this->setLastName(pls.getLastName());
    this->setTenured(pls.tenured);
    this->setDepartment(pls.department);
    this->setNext(pls.getNext());
}

Professor ::~Professor()
{
}

void ReadRecords(void);
void ScanList(void);
void saveList(void);
void insertN(Person *person_in);
void deleteN(Person *person_in);
void addToList();
void removeFromList(int inID);
void updateList(int inID);
void menuDisplay(void);
void secondMenu(void);
void updateStudentM(string first, string last);
void updateProfessorM(string first, string last);
void updateEmployeeM(string first, string last);

int main()
{

    int userin = 0;
    ReadRecords();
    do
    {
        int userID_in;

        menuDisplay();
        cout << "\nWhat would you like to do? ";
        cin >> userin;

        switch (userin)
        {
        case 1:
        {
            ScanList();
            break;
        }
        case 2:
        {
            addToList();
            break;
        }
        case 3:
        {
            printf("\nEnter the ID of the person you want to delete: ");
            cin >> userID_in;
            removeFromList(userID_in);
            break;
        }
        case 4:
        {
            printf("\nEnter the ID of the person you want to update: ");
            cin >> userID_in;
            updateList(userID_in);
            break;
        }
        case 5:
        {
            break;
        }
        }

    } while (userin != 5);
    saveList();
}

void ReadRecords()
{
    ifstream ShowRecord;
    int NumP = 0;
    ShowRecord.open("OneMoreSiu.txt.");
    if (!ShowRecord.is_open())
    {
        cerr << "Could not open file: OneMoreSiu.txt" << endl;
    }
    else
    {
        string temp = "";
        ShowRecord >> temp;
        ShowRecord >> temp;
        ShowRecord >> temp;
        ShowRecord >> NumP;
        cout << "\nNumber of People: " << NumP << "\n";
        for (int i = 0; i < NumP; i++)
        {
            ShowRecord >> temp;
            if (temp == "Student")
            {
                int read_id = 0;
                string read_first = "";
                string read_last = "";
                float read_gpa = 0.0;
                ShowRecord >> temp;
                ShowRecord >> read_id;
                ShowRecord >> temp;
                ShowRecord >> temp;
                ShowRecord >> read_first;
                ShowRecord >> temp;
                ShowRecord >> temp;
                ShowRecord >> read_last;
                ShowRecord >> temp;
                ShowRecord >> read_gpa;

                Person *newStudent = new Student(read_id, read_first, read_last, read_gpa);
                insertN(newStudent);
            }
            else if (temp == "Professor")
            {
                int read_id = 0;
                string read_first = "";
                string read_last = "";
                float read_salary = 0.0;
                bool read_tenured = false;
                Department read_department = OTHER;
                ShowRecord >> temp;
                ShowRecord >> read_id;
                ShowRecord >> temp;
                ShowRecord >> temp;
                ShowRecord >> read_first;
                ShowRecord >> temp;
                ShowRecord >> temp;
                ShowRecord >> read_last;
                ShowRecord >> temp;
                ShowRecord >> read_salary;
                ShowRecord >> temp;
                ShowRecord >> read_tenured;
                ShowRecord >> temp;
                ShowRecord >> temp;
                if (temp == "BIO")
                {
                    read_department = BIO;
                }
                else if (temp == "CHEM")
                {
                    read_department = CHEM;
                }
                else if (temp == "CS")
                {
                    read_department = CS;
                }
                else if (temp == "PHYS")
                {
                    read_department = PHYS;
                }
                else if (temp == "MATH")
                {
                    read_department = MATH;
                }
                else
                {
                    read_department = OTHER;
                }

                Person *newProfesor = new Professor(read_id, read_first, read_last, read_salary, read_tenured, read_department);
                insertN(newProfesor);
            }
            else if (temp == "Employee")
            {
                int read_id = 0;
                string read_first = "";
                string read_last = "";
                float read_salary = 0.0;
                ShowRecord >> temp;
                ShowRecord >> read_id;
                ShowRecord >> temp;
                ShowRecord >> temp;
                ShowRecord >> read_first;
                ShowRecord >> temp;
                ShowRecord >> temp;
                ShowRecord >> read_last;
                ShowRecord >> temp;
                ShowRecord >> read_salary;

                Person *newEmployee = new Employee(read_id, read_first, read_last, read_salary);
                insertN(newEmployee);
            }
            else
            {
            }
        }
        ShowRecord.close();
        cout << "OneMoreSiu.txt successfully scanned" << endl;
    }
}

void ScanList()
{
    Person *node = frontP;
    printf("\n-----------RECORDS-----------");
    while (node != NULL)
    {

        if (instanceof <Student>(node))
        {
            Student *tempStudent = (Student *)node;
            cout << "\n\nStudent";
            cout << "\nID: " << tempStudent->getID();
            cout << "\nFirst Name: " << tempStudent->getFirstName();
            cout << "\nLast Name: " << tempStudent->getLastName();
            cout << "\nGPA: " << tempStudent->getGPA();
        }
        else if (instanceof <Professor>(node))
        {
            Professor *tempProfessor = (Professor *)node;
            cout << "\n\nProfessor";
            cout << "\nID: " << tempProfessor->getID();
            cout << "\nFirst Name: " << tempProfessor->getFirstName();
            cout << "\nLast Name: " << tempProfessor->getLastName();
            cout << "\nSalary: " << tempProfessor->getSalary();
            if (tempProfessor->getTenured())
            {
                cout << "\nTenured: Yes";
            }
            else
            {
                cout << "\nTenured: No";
            }
            tempProfessor->getTenured();
            if (tempProfessor->getDepartment() == BIO)
            {
                cout << "\nDepartment: BIO";
            }
            else if (tempProfessor->getDepartment() == CHEM)
            {
                cout << "\nDepartment: CHEM";
            }
            else if (tempProfessor->getDepartment() == CS)
            {
                cout << "\nDepartment: CS";
            }
            else if (tempProfessor->getDepartment() == PHYS)
            {
                cout << "\nDepartment: PHYS";
            }
            else if (tempProfessor->getDepartment() == MATH)
            {
                cout << "\nDepartment: MATH";
            }
            else
            {
                cout << "\nDepartment: OTHER";
            }
        }
        else if (instanceof <Employee>(node))
        {
            Employee *tempEmployee = (Employee *)node;
            cout << "\n\nEmployee";
            cout << "\nID: " << tempEmployee->getID();
            cout << "\nFirst Name: " << tempEmployee->getFirstName();
            cout << "\nLast Name: " << tempEmployee->getLastName();
            cout << "\nSalary: " << tempEmployee->getSalary();
        }
        node = node->getNext(); // i++
    }
    printf("\n\n---------------------\n");
}

void saveList()
{
    ofstream ShowRecords;
    ShowRecords.open("OneMoreSiu.txt");
    Person *node = frontP;
    int numberP = 0;
    while (node != NULL)
    {
        numberP++;
        node = node->getNext();
    }
    if (!ShowRecords.is_open())
    {
        cout << "Unable to write file\n";
    }
    else
    {
        ShowRecords << "Number of people: " << numberP;
        node = frontP;
        while (node != NULL)
        {

            if (instanceof <Student>(node))
            {
                Student *tempStudent = (Student *)node;
                ShowRecords << "\n\nStudent";
                ShowRecords << "\nID: " << tempStudent->getID();
                ShowRecords << "\nFirst Name: " << tempStudent->getFirstName();
                ShowRecords << "\nLast Name: " << tempStudent->getLastName();
                ShowRecords << "\nGPA: " << tempStudent->getGPA();
            }
            else if (instanceof <Professor>(node))
            {
                Professor *tempProfessor = (Professor *)node;
                ShowRecords << "\n\nProfessor";
                ShowRecords << "\nID: " << tempProfessor->getID();
                ShowRecords << "\nFirst Name: " << tempProfessor->getFirstName();
                ShowRecords << "\nLast Name: " << tempProfessor->getLastName();
                ShowRecords << "\nSalary: " << tempProfessor->getSalary();
                ShowRecords << "\nTenured: " << tempProfessor->getTenured();
                if (tempProfessor->getDepartment() == BIO)
                {
                    ShowRecords << "\nDepartment: BIO";
                }
                else if (tempProfessor->getDepartment() == CHEM)
                {
                    ShowRecords << "\nDepartment: CHEM";
                }
                else if (tempProfessor->getDepartment() == CS)
                {
                    ShowRecords << "\nDepartment: CS";
                }
                else if (tempProfessor->getDepartment() == PHYS)
                {
                    ShowRecords << "\nDepartment: PHYS";
                }
                else if (tempProfessor->getDepartment() == MATH)
                {
                    ShowRecords << "\nDepartment: MATH";
                }
                else
                {
                    ShowRecords << "\nDepartment: OTHER";
                }
            }
            else if (instanceof <Employee>(node))
            {
                Employee *tempEmployee = (Employee *)node;
                ShowRecords << "\n\nEmployee";
                ShowRecords << "\nID: " << tempEmployee->getID();
                ShowRecords << "\nFirst Name: " << tempEmployee->getFirstName();
                ShowRecords << "\nLast Name: " << tempEmployee->getLastName();
                ShowRecords << "\nSalary: " << tempEmployee->getSalary();
            }

            node = node->getNext();
        }
        ShowRecords.close();
    }
}

void insertN(Person *person_in)
{
    if (frontP == NULL)
    {
        frontP = person_in;
        return;
    }
    else if (frontP->getNext() == NULL)
    {
        if (frontP->getID() >= person_in->getID())
        {
            frontP->setNext(person_in);
            return;
        }
        else
        {
            Person *temp = frontP;
            frontP = person_in;
            frontP->setNext(temp);
            return;
        }
    }

    Person *node = frontP;

    while (node->getNext() != NULL)
    {
        Person *nextNode = node->getNext();

        if ((node->getID() > person_in->getID()) && (person_in->getID() >= nextNode->getID()))
        {
            person_in->setNext(node->getNext());
            node->setNext(person_in);
            return;
        }
        else if (node->getID() <= person_in->getID())
        {
            person_in->setNext(node);
            frontP = person_in;
            return;
        }
        node = node->getNext();
    }
    node->setNext(person_in);
    person_in->setNext(NULL);
    return;
}

void deleteN(Person *person_in)
{
    Person *thisP = frontP;
    Person *lastP = NULL;

    if (frontP == person_in)
    {
        frontP = frontP->getNext();
        delete person_in;
        return;
    }

    while (thisP != NULL && thisP != person_in)
    {
        lastP = thisP;
        thisP = thisP->getNext();
    }

    if (thisP != NULL)
    {
        lastP->setNext(thisP->getNext());
    }

    delete person_in;
}

void addToList()
{
    int userinput = 0;
    do
    {
        int inIDput;
        string inFirstput, inLastput;
        float gpa_input, salary_input;
        bool ten_input;
        Department dep_input;
        string temp;
        Person *idCheck = frontP;

        secondMenu();
        cout << "\nWho would you like to add? ";
        cin >> userinput;

        switch (userinput)
        {
        case 1:
        {
            printf("\nEnter the ID of the student: ");
            cin >> inIDput;
            while (idCheck != NULL)
            {
                if (inIDput == idCheck->getID())
                {
                    printf("\nEntered ID is currently used by and existing person.");
                    idCheck = frontP;
                    printf("\nEnter the ID of the student: ");
                    cin >> inIDput;
                }
                idCheck = idCheck->getNext();
            }

            printf("\nEnter the first name of the student: ");
            cin >> inFirstput;

            printf("\nEnter the last name of the student: ");
            cin >> inLastput;

            printf("\nEnter the GPA of the student: ");
            cin >> gpa_input;
            while ((gpa_input > 4.0) || (gpa_input < 1.0))
            {
                printf("\nPlease enter a GPA in the range of 4.0 and 1.0.");
                printf("\nEnter the GPA of the student: ");
                cin >> gpa_input;
            }

            Person *peterPtr = new Student(inIDput, inFirstput, inLastput, gpa_input);
            insertN(peterPtr);
            break;
        }
        case 2:
        {
            printf("\nEnter the ID of the professor: ");
            cin >> inIDput;
            while (idCheck != NULL)
            {
                if (inIDput == idCheck->getID())
                {
                    printf("\nEntered ID is currently used by an existing person.");
                    idCheck = frontP;
                    printf("\nEnter the ID of the professor: ");
                    cin >> inIDput;
                }
                idCheck = idCheck->getNext();
            }

            printf("\n First name of the professor: ");
            cin >> inFirstput;

            printf("\n Last name of the professor: ");
            cin >> inLastput;

            printf("\n Salary of the professor: ");
            cin >> salary_input;

            cout << "\nAre they tenured? ";
            cin >> temp;
            string yes = "yes";
            string no = "no";
            if (strcasecmp(yes.c_str(), temp.c_str()) == 0)
                ten_input = true;
            else if (strcasecmp(no.c_str(), temp.c_str()) == 0)
                ten_input = false;
            else
            {
                bool check = true;
                while (check)
                {
                    cout << "\n Indicate yes or no: ";
                    cin >> temp;
                    if (strcasecmp(yes.c_str(), temp.c_str()) == 0)
                    {
                        ten_input = true;
                        check = false;
                    }

                    else if (strcasecmp(no.c_str(), temp.c_str()) == 0)
                    {
                        ten_input = false;
                        check = false;
                    }
                }
            }

            cout << "\n Department of the professor (BIO, CHEM, CS, PHYS, MATH): ";
            cin >> temp;

            if (temp == "BIO")
            {
                dep_input = BIO;
            }
            else if (temp == "CHEM")
            {
                dep_input = CHEM;
            }
            else if (temp == "CS")
            {
                dep_input = CS;
            }
            else if (temp == "PHYS")
            {
                dep_input = PHYS;
            }
            else if (temp == "MATH")
            {
                dep_input = MATH;
            }
            else
            {
                dep_input = OTHER;
            }

            Person *peterPtr = new Professor(inIDput, inFirstput, inLastput, salary_input, ten_input, dep_input);
            insertN(peterPtr);
            break;
        }
        case 3:
        {
            printf("\nID of the employee: ");
            cin >> inIDput;
            while (idCheck != NULL)
            {
                if (inIDput == idCheck->getID())
                {
                    printf("\n ID is currently used by an existing person.");
                    idCheck = frontP;
                    printf("\n Try again, ID of the employee: ");
                    cin >> inIDput;
                }
                idCheck = idCheck->getNext();
            }

            printf("\n First name of the employee: ");
            cin >> inFirstput;

            printf("\n Last name of the employee: ");
            cin >> inLastput;

            printf("\n Salary of the employee: ");
            cin >> salary_input;

            Person *peterPtr = new Employee(inIDput, inFirstput, inLastput, salary_input);
            insertN(peterPtr);
            break;
        }

        case 4:
            break;

        default:
            printf("\nInvalid input\n");
        }
    } while (userinput != 4);
}

void removeFromList(int inID)
{
    Person *node = frontP;
    while (node != NULL)
    {
        if (inID == node->getID())
        {
            string first = node->getFirstName();
            string last = node->getLastName();
            deleteN(node);
            cout << "\n"
                 << first << " " << last << " was successfully deleted.";
            return;
        }
        node = node->getNext();
    }
    cout << "\nThere is no person associated with the given ID.";
}

void updateList(int inID)
{
    Person *node = frontP;

    int userinput = 0;
    while (node != NULL)
    {
        if (inID == node->getID())
        {
            if (instanceof <Student>(node))
            {
                do
                {
                    updateStudentM(node->getFirstName(), node->getLastName());
                    cin >> userinput;
                    int new_id, old_id = 0;
                    string new_first = "";
                    string old_first = "";
                    string new_last = "";
                    string old_last = "";
                    string temp = "";
                    float new_gpa, old_gpa = 0.0;
                    Person *idCheck = frontP;
                    Student *tempStudent = (Student *)node;

                    switch (userinput)
                    {
                    case 1:
                        cout << "\nEnter the new ID: ";
                        cin >> new_id;
                        while (idCheck != NULL)
                        {
                            if (new_id == idCheck->getID())
                            {
                                printf("\nEntered ID is currently used by and existing student.");
                                idCheck = frontP;
                                printf("\nEnter the ID of the student: ");
                                scanf("%d", &new_id);
                            }
                            idCheck = idCheck->getNext();
                        }
                        old_id = tempStudent->getID();
                        tempStudent->setID(new_id);
                        node = tempStudent;
                        printf("\n%d was sucessfully updated to %d", old_id, new_id);
                        break;
                    case 2:
                        printf("\nEnter the new first name: ");
                        cin >> new_first;
                        old_first = tempStudent->getFirstName();
                        tempStudent->setFirstName(new_first);
                        cout << "\n"
                             << old_first << " was sucessfully updated to " << new_first;
                        node = tempStudent;
                        break;
                    case 3:
                        printf("\nEnter the new last name: ");
                        cin >> new_last;
                        old_last = tempStudent->getLastName();
                        tempStudent->setLastName(new_last);
                        cout << "\n"
                             << old_last << " was sucessfully updated to " << new_last;
                        node = tempStudent;
                        break;
                    case 4:
                        printf("\nEnter the new GPA: ");
                        scanf("%f", &new_gpa);
                        while ((new_gpa > 4.0) || (new_gpa < 1.0))
                        {
                            printf("\nPlease enter a GPA in the range of 4.0 and 1.0.");
                            printf("\nEnter the GPA of the student: ");
                            scanf("%f", &new_gpa);
                        }
                        old_gpa = tempStudent->getGPA();
                        tempStudent->setGPA(new_gpa);
                        node = tempStudent;
                        printf("\n%f was sucessfully updated to %f", old_gpa, new_gpa);
                        break;

                    case 5:
                        break;

                    default:
                        printf("\nInvalid input\n");
                    }
                } while (userinput != 5);
                return;
            }
            else if (instanceof <Professor>(node))
            {
                do
                {
                    updateProfessorM(node->getFirstName(), node->getLastName());
                    cin >> userinput;
                    int new_id, old_id = 0;
                    string new_first = "";
                    string old_first = "";
                    string new_last = "";
                    string old_last = "";
                    string temp, temp2 = "";
                    float new_salary, old_salary = 0.0;
                    bool new_ten, old_ten = false;
                    Department new_dep;
                    Person *idCheck = frontP;
                    Professor *tempProfessor = (Professor *)node;

                    switch (userinput)
                    {
                    case 1:
                    {
                        cout << "\nEnter the new ID: ";
                        cin >> new_id;
                        while (idCheck != NULL)
                        {
                            if (new_id == idCheck->getID())
                            {
                                printf("\nEntered ID is currently used by and existing student.");
                                idCheck = frontP;
                                printf("\nEnter the ID of the student: ");
                                scanf("%d", &new_id);
                            }
                            idCheck = idCheck->getNext();
                        }
                        old_id = tempProfessor->getID();
                        tempProfessor->setID(new_id);
                        node = tempProfessor;
                        printf("\n%d was sucessfully updated to %d", old_id, new_id);
                        break;
                    }

                    case 2:
                    {
                        printf("\nEnter the new first name: ");
                        cin >> new_first;
                        old_first = tempProfessor->getFirstName();
                        tempProfessor->setFirstName(new_first);
                        cout << "\n"
                             << old_first << " was sucessfully updated to " << new_first;
                        node = tempProfessor;
                        break;
                    }

                    case 3:
                    {
                        printf("\nEnter the new last name: ");
                        cin >> new_last;
                        old_last = tempProfessor->getLastName();
                        tempProfessor->setLastName(new_last);
                        cout << "\n"
                             << old_last << " was sucessfully updated to " << new_last;
                        node = tempProfessor;
                        break;
                    }
                    case 4:
                    {
                        printf("\nEnter the new Salary: ");
                        scanf("%f", &new_salary);
                        old_salary = tempProfessor->getSalary();
                        tempProfessor->setSalary(new_salary);
                        node = tempProfessor;
                        printf("\n%f was sucessfully updated to %f", old_salary, new_salary);
                        break;
                    }

                    case 5:
                    {
                        cout << "\nAre they tenured? (yes/no) ";
                        cin >> temp;
                        string yes = "yes";
                        string no = "no";
                        if (strcasecmp(yes.c_str(), temp.c_str()) == 0)
                            new_ten = true;
                        else if (strcasecmp(no.c_str(), temp.c_str()) == 0)
                            new_ten = false;
                        else
                        {
                            bool check = true;
                            while (check)
                            {
                                cout << "\nPlease indicate yes or no: ";
                                cin >> temp;
                                if (strcasecmp(yes.c_str(), temp.c_str()) == 0)
                                {
                                    new_ten = true;
                                    check = false;
                                }

                                else if (strcasecmp(no.c_str(), temp.c_str()) == 0)
                                {
                                    new_ten = false;
                                    check = false;
                                }
                            }
                        }
                        old_ten = tempProfessor->getTenured();
                        tempProfessor->setTenured(new_ten);
                        node = tempProfessor;
                        if (new_ten == old_ten)
                            cout << "\nNo change was made (value entered was the same as the current value)";
                        else
                            cout << "\nTenured was updated";
                        break;
                    }

                    case 6:
                    {
                        cout << "\nEnter the department of the professor: ";
                        cin >> temp;

                        if (temp == "BIO")
                        {
                            new_dep = BIO;
                        }
                        else if (temp == "CHEM")
                        {
                            new_dep = CHEM;
                        }
                        else if (temp == "CS")
                        {
                            new_dep = CS;
                        }
                        else if (temp == "PHYS")
                        {
                            new_dep = PHYS;
                        }
                        else if (temp == "MATH")
                        {
                            new_dep = MATH;
                        }
                        else
                        {
                            new_dep = OTHER;
                        }

                        if (tempProfessor->getDepartment() == BIO)
                        {
                            temp2 = "BIO";
                        }
                        else if (tempProfessor->getDepartment() == CHEM)
                        {
                            temp2 = "CHEM";
                        }
                        else if (tempProfessor->getDepartment() == CS)
                        {
                            temp2 = "CS";
                        }
                        else if (tempProfessor->getDepartment() == PHYS)
                        {
                            temp2 = "PHYS";
                        }
                        else if (tempProfessor->getDepartment() == MATH)
                        {
                            temp2 = "MATH";
                        }
                        else
                        {
                            temp2 = "OTHER";
                        }
                        tempProfessor->setDepartment(new_dep);
                        node = tempProfessor;
                        cout << "\n"
                             << temp2 << " was successfully updated to " << temp;
                        break;
                    }

                    case 7:
                    {
                        break;
                    }

                    default:
                        printf("\nInvalid input\n");
                    }
                } while (userinput != 7);
                return;
            }
            else if (instanceof <Employee>(node))
            {
                do
                {
                    updateEmployeeM(node->getFirstName(), node->getLastName());
                    cin >> userinput;
                    int new_id, old_id = 0;
                    string new_first = "";
                    string old_first = "";
                    string new_last = "";
                    string old_last = "";
                    string temp = "";
                    float new_salary, old_salary = 0.0;
                    Person *idCheck = frontP;
                    Employee *tempStudent = (Employee *)node;

                    switch (userinput)
                    {
                    case 1:
                        cout << "\nEnter the new ID: ";
                        cin >> new_id;
                        while (idCheck != NULL)
                        {
                            if (new_id == idCheck->getID())
                            {
                                printf("\nEntered ID is currently used by and existing student.");
                                idCheck = frontP;
                                printf("\nEnter the ID of the student: ");
                                scanf("%d", &new_id);
                            }
                            idCheck = idCheck->getNext();
                        }
                        old_id = tempStudent->getID();
                        tempStudent->setID(new_id);
                        node = tempStudent;

                        printf("\n%d was sucessfully updated to %d", old_id, new_id);
                        break;
                    case 2:
                        printf("\nEnter the new first name: ");
                        cin >> new_first;
                        old_first = tempStudent->getFirstName();
                        tempStudent->setFirstName(new_first);
                        cout << "\n"
                             << old_first << " was sucessfully updated to " << new_first;
                        node = tempStudent;
                        break;
                    case 3:
                        printf("\nEnter the new last name: ");
                        cin >> new_last;
                        old_last = tempStudent->getLastName();
                        tempStudent->setLastName(new_last);
                        cout << "\n"
                             << old_last << " was sucessfully updated to " << new_last;
                        node = tempStudent;
                        break;
                    case 4:
                        printf("\nEnter the new Salary: ");
                        scanf("%f", &new_salary);

                        old_salary = tempStudent->getSalary();
                        tempStudent->setSalary(new_salary);
                        node = tempStudent;
                        printf("\n%f was sucessfully updated to %f", old_salary, new_salary);
                        break;

                    case 5:
                        break;

                    default:
                        printf("\nInvalid input\n");
                    }
                } while (userinput != 5);
                return;
            }
        }
        node = node->getNext();
    }
    cout << "\nThere is no person associated with the given ID.";
}

void menuDisplay()
{
    printf("\n-------------------MENU-------------");

    printf("\n\n 1) List");
    printf("\n 2) Add");
    printf("\n 3) Remove");
    printf("\n 4) Update");

    printf("\n\n 5) Quit");
    printf("\n\n--------------------");
    printf("\n\n");
}

void secondMenu()
{
    printf("\n-------------------MENU-------------");

    printf("\n\n 1) Student");
    printf("\n 2) Professor");
    printf("\n 3) Employee");

    printf("\n\n 4) Quit");
    printf("\n\n-------------------");
    printf("\n\n");
}

void updateStudentM(string first, string last)
{
    printf("\n-------------------UPDATE STUDENT MENU-------------");
    cout << "\nWhat do you want update about student " << first << " " << last << "?";
    printf("\n\n 1) ID");
    printf("\n 2) First Name");
    printf("\n 3) Last Name");
    printf("\n 4) GPA");

    printf("\n\n 5) Quit");
    printf("\n\n-------------------");
    printf("\n\n");
}

void updateProfessorM(string first, string last)
{
    printf("\n-------------------UPDATE PROFESSOR MENU-------------");
    cout << "\nWhat do you want to update about professor " << first << " " << last << "?";
    printf("\n\n1) ID");
    printf("\n 2) First Name");
    printf("\n 3) Last Name");
    printf("\n 4) Salary");
    printf("\n 5) Tenured");
    printf("\n 6) Department");

    printf("\n\n7) Quit");
    printf("\n\n-------------------");
    printf("\n\n");
}

void updateEmployeeM(string first, string last)
{
    printf("\n-------------------UPDATE EMPLOYEE MENU-------------");
    cout << "\nWhat do you want to update about employee" << first << " " << last << "?";
    printf("\n 1) ID");
    printf("\n 2) First Name");
    printf("\n 3) Last Name");
    printf("\n 4) Salary");

    printf("\n\n 5) Quit");
    printf("\n\n-------------------");
    printf("\n\n");
}