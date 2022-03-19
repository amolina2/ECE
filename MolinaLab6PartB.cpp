#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

enum Department
{
    BIO,CHEM,CS,PHYS,MATH
};

class Student
{
private:
    int ID;
    string firstName;  //changed
    string lastName;   //changed
    float GPA;
    Student* next;

public:
    Student();
    Student(int inID, string inFirst, string inLast, float inGPA);
    Student(Student &pls);
    ~Student();
    Student &operator=(Student const &s)
    {
        this->ID = s.ID;
        setFirstName(s.firstName);
        setLastName(s.lastName);
        this->GPA = s.GPA;
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
    //--------------
    float getGPA()
    {
        return GPA;
    }

    void setGPA(float inGPA)
    {
        GPA = inGPA;
    }
    //-------------
    string getFirstName()
    {
        return firstName;
    }
    void setFirstName(string inFirst)
    {
        this -> firstName = inFirst;
    }

    //---------------

    string getLastName()
    {
        return lastName;
    }
    void setLastName(string inLast)
    {
        this -> lastName = inLast;
    }

    //------------------

    Student *getNext()
    {
        return next;
    }

    void setNext(Student *next_in)
    {
        next = next_in;
    }
};

Student *FrontNode = NULL;

Student::Student()
{
    this->ID = 100;
    this->firstName = "null";
    this->lastName = "null";
    this->GPA = 0.0;
    this->next = NULL;
}

Student:: Student(int inID, string inFirst, string inLast, float inGPA)
{
    this->ID = inID;
    this->firstName = inFirst;
    this->lastName = inLast;
    this->GPA = inGPA;
    this->next = NULL;
}

Student ::Student(Student &pls)
{
    ID = pls.ID;
    GPA = pls.GPA;
    firstName = "";
    lastName = "";
    setFirstName(pls.firstName);
    setLastName(pls.lastName);
    next = pls.next;
}

Student ::~Student()
{

}

void insertStudent(Student *student_in);
void deleteStudent(Student *student_in);
void ReadRecords(void);
void ScanList(void);

void saveList(void);
void RemoveStudent(int inID);
void UpdateStudent(int inID);
void menuDisplay(void);
void UpdateStudentMenu(string firstName, string lastName);

int main()
{
    int userin = 0;
    ReadRecords();
    do 
    {
        int IDin;
        string firstin;
        string lastin;
        float gpa_input = 0.0;
        int userID_in;                
        Student *idCheck = FrontNode; 

        menuDisplay();                          
        cout<<"What would you like to do? "<< endl;
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
            cout<<"Enter the ID of the student: " <<endl; 
            cin >> IDin;                            
            while (idCheck != NULL)                    
            {
                if (IDin == idCheck->getID()) 
                {
                    cout<<"Entered ID is currently used by and existing student."<<endl;
                    idCheck = FrontNode;                                               
                    cout<<"Enter the ID of the student: "<<endl;                      
                    cin >> IDin;                                                    
                }
                idCheck = idCheck->getNext();
            }

            cout<<"Enter the first name of the student: "<<endl; 
            cin >> firstin;                                      
            

            cout<<"Enter the last name of the student: "<<endl; 
            cin >> lastin;                                      

            cout<<"Enter the GPA of the student: "<<endl;  
            cin >> gpa_input;                             


            Student *peterPtr = new Student(IDin, firstin, lastin, gpa_input); 
            insertStudent(peterPtr);                                                
            break; 
        }

        case 3: 
        {
            printf("\nEnter the ID of the student you wish to delete: "); 
            scanf("%d", &userID_in);                                       
            break;                                                        
        }

        case 4: 
        {
            printf("\nEnter the ID of the student you wish to update: "); 
            cin >> userID_in;                                              
            UpdateStudent(userID_in);                                     
            break;                                                        
        }

        case 5: 
        {
        
            break;                             
        }

        default: 
            printf("\nInvalid input\n");
        }
    } while (userin != 5);
    saveList();

    return 0;
}

void insertStudent(Student *student_in)
{
    if (FrontNode == NULL)
    {
        FrontNode = student_in;
        return;
    }
    else if (FrontNode->getNext() == NULL)
    {
        if (FrontNode->getGPA() >= student_in->getGPA())
        {
            FrontNode->setNext(student_in);
            return;
        }
        else
        {
            Student* temp = FrontNode;
            FrontNode = student_in;
            FrontNode->setNext(temp);
            return;
        }
    }

    Student* node = FrontNode;

    while (node->getNext() != NULL)
    {
        Student* nextNode = node->getNext();

        if ((node->getGPA() > student_in->getGPA()) && (student_in->getGPA() >= nextNode->getGPA()))
        {
            student_in->setNext(node->getNext());
            node->setNext(student_in);
            return;
        }
        else if (node->getGPA() <= student_in->getGPA())
        {
            student_in->setNext(node);
            FrontNode = student_in;
            return;
        }
        node = node->getNext();
    }
    node->setNext(student_in);
    student_in->setNext(NULL);
    return;
}

void deleteStudent(Student* student_in)
{
    Student* thisStudent = FrontNode;
    Student* lastStudent = NULL;

    if (FrontNode == student_in)
    {
        FrontNode = FrontNode->getNext();
        delete student_in;
        return;
    }

    while (thisStudent != NULL && thisStudent != student_in) 
    {
        lastStudent= thisStudent;              
        thisStudent = thisStudent->getNext(); 
    }

    if (thisStudent != NULL)
    {
        lastStudent->setNext(thisStudent->getNext());
    }

    delete student_in;
}

void ReadRecords() 
{
    ifstream readRecords;
    int totalS = 0;
    readRecords.open("lol.txt");
    if (!readRecords.is_open())
    {
        cerr << "Could not open file: lol.txt" << endl;
    }
    else
    {
        string temp = "";
        readRecords >> temp;
        readRecords >> temp;
        readRecords >> temp;
        readRecords >> totalS;
        cout << "\nNumber of Students: " << totalS << "\n";
        for (int i = 0; i < totalS; i++)
        {
            int read_id = 0;
            string read_first = "";
            string read_last = "";
            float read_gpa = 0.0;
            readRecords >> temp;
            readRecords >> temp;
            readRecords >> read_id;
           /*readRecords >> temp;*/
            readRecords >> temp;
            readRecords >> temp;
            readRecords >> temp;

           readRecords >> read_first;

            readRecords >> temp;
            readRecords >> temp;
            readRecords >> temp;
            readRecords >> temp;
            readRecords >> read_last;

            readRecords >> temp;
            readRecords >> temp;
            readRecords >> read_gpa;

            Student* newStudent = new Student(read_id, read_first, read_last, read_gpa);
            insertStudent(newStudent);

            /*free(read_first);
            free(read_last);*/
        }
        readRecords.close();
        printf("lol.txt successfully scanned\n"); 
    }
}

void ScanList() 
{
    Student* node = FrontNode;                           
    printf("\n------STUDENTLIST-----"); 
    while (node != NULL)                                 
    {
    
        printf("\n\nStudent ID: %d", node->getID());
        cout<<"\nStudent First Name:" << node->getFirstName();
        cout<<"\nStudent Last Name:"<< node->getLastName();
        printf("\nStudent GPA: %f", node->getGPA());
        node = node->getNext(); 
    }
    printf("\n\n---------------------------------------\n"); 
}

/*void freeList()
{
    Student* node = FrontNode;
    Student* nextNode = FrontNode->getNext();
    while(node != NULL)
    {
        delete node;
        node = nextNode;
        nextNode = nextNode->getNext();
    }
}
*/

void saveList() 
{
    ofstream openRecords;
    openRecords.open("lol.txt");
    Student* node = FrontNode; 
    int studentCount = 0;      
    while (node != NULL)       
    {
        studentCount++;         
        node = node->getNext(); 
    }
    if (!openRecords.is_open())
    {
        cout << "Unable to write file\n";
    }
    else
    {
        openRecords << "Number of students: " << studentCount; 
        node = FrontNode;                                      
        while (node != NULL)                                   
        {
            //
            openRecords << "\n\nStudent ID: " << node->getID();
            openRecords << "\nStudent First Name: " << node->getFirstName();
            openRecords << "\nStudent Last Name: " << node->getLastName();
            openRecords << "\nStudent GPA: " << node->getGPA();
            node = node->getNext();
        }
        openRecords.close(); 
    }
}

void RemoveStudent(int inID) 
{
    Student*node = FrontNode; 
    int check = 0;             
    while (node != NULL)       
    {
        if (inID == node->getID()) 
        {
            string first = node -> getFirstName();
            string last = node -> getLastName();
            deleteStudent(node);
            check = 1;
            cout <<first << ""<< last<<"was deleted";
            return;
        }
        
    
            /*char *first;
            first = (char *)malloc(strlen(node->getFirstName() + 1));
            char *last;
            last = (char *)malloc(strlen(node->getLastName() + 1));
            strcpy(first, node->getFirstName());
            strcpy(last, node->getLastName());
            deleteStudent(node);                                              
            check = 1;                                                
            printf("\n%s %s was successfully deleted.", first, last); 
            free(first);
            free(last);
            return; 
        }*/
        node = node->getNext(); 
    }
    if (check == 0) 
    {
        printf("\nThere is no student associated with the given ID."); 
        return;                                                     
    }
    return; 
}

void UpdateStudent(int inID) 
{
    Student *node = FrontNode; 
    Student *prevNode = node;  
    int check = 0;             
    int userinput = 0;       
    while (node != NULL)       
    {
        if (inID == node->getID()) 
        {
            do 
            {
                UpdateStudentMenu(node->getFirstName(), node->getLastName()); 
                cin >> userinput;                                           
            
                
                
                int new_id = 0;
                int old_id = 0;
                string new_first = "";
                string old_first = "";
                string new_last = "";
                string old_last = "";
                string temp = "";
                float new_gpa, old_gpa = 0.0;
                Student *idCheck = FrontNode;

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
                            idCheck = FrontNode;                                               
                            printf("\nEnter the ID of the student: ");                        
                            scanf("%d", &new_id);                                           
                        }
                        idCheck = idCheck->getNext(); 
                    }
                    old_id = node->getID();                                       
                    node->setID(new_id);                                       
                    printf("\n%d was sucessfully updated to %d", old_id, new_id); 
                    break;                                                       
                case 2:                                                           
                    printf("\nEnter the new first name: ");                       
                    cin >> new_first;
                    old_first = node -> getFirstName();
                    node -> setFirstName(new_first);
                    cout<<old_first<<"was updated to "<< new_first;
                    break;



                    /*old_first = (char *)malloc(strlen(node->getFirstName() + 1));
                    strcpy(old_first, node->getFirstName());                            
                    node->setFirstName(new_first);                                      
                    printf("\n%s was sucessfully updated to %s", old_first, new_first); 
                    free(new_first);
                    free(old_first);
                    break; */                               
                case 3:                                   
                    
                    printf("\nEnter the new last name: "); 
                    cin >> new_last; 
                    old_last = node -> getLastName();
                    node -> setLastName(new_last);
                    cout << old_last<<"Was sucessfully updated to"<< new_first;
                    break;

                    /*new_last = (char *)malloc(strlen(temp.c_str() + 1));
                    strcpy(new_last, temp.c_str());
                    old_last = (char *)malloc(strlen(node->getLastName() + 1));
                    strcpy(old_last, node->getLastName());                            
                    node->setLastName(new_last);                                      
                    printf("\n%s was sucessfully updated to %s", old_last, new_last); 
                    break;*/                                                            
                case 4:                                                              
                    printf("\nEnter the new GPA: ");                                  
                    scanf("%f", &new_gpa);                                            
                    old_gpa = node->getGPA(); 
                    node->setGPA(new_gpa);    
                    if (prevNode == node)    
                    {
                        node->setNext(NULL); 
                        insertStudent(node); 
                    }
                    else 
                    {
                        prevNode->setNext(node->getNext()); 
                        insertStudent(node);                
                    }
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
        prevNode = node;        
        node = node->getNext(); 
    }
    if (check == 0) 
    {
        printf("\nThere is no student associated with the given ID."); 
        return;                                                        
    }
}

void menuDisplay() 
{
    printf("\n---------------STUDENT MENU------------");

    printf("\n\n1) List All Students");
    printf("\n 2) Add Student");
    printf("\n 3) Remove Student");
    printf("\n 4) Update Student");

    printf("\n\n 5) Quit");
    printf("\n\n------------------------");
    printf("\n\n");
}

void UpdateStudentMenu(string first, string last) 
{
    printf("\n-------------------UPDATE STUDENT MENU-------------");
    cout<<"\nWhat would you like to update about" <<first<<" "<< last <<"?";
    printf("\n 1) ID");
    printf("\n 2) First Name");
    printf("\n 3) Last Name");
    printf("\n 4) GPA");

    printf("\n\n 5) Quit");
    printf("\n\n-------------------");
    printf("\n\n");
}
