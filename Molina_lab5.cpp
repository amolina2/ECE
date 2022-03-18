#include <iostream>
#include <cstring>
using namespace std;

//-------------------------------Students----------------------------------------------------------------------------------
class Students{
private: 
	int  ID;
    char *firstName;
    char *lastName;
    float GPA;
	//------------------------
	 int sl;
	 int sl2;
public:
	//----------------------Constructors---------------
	Students(){//default constructor 
	}
	
	Students(int ID, const char* firstName, const char* lastName, float GPA){//Parametrized Constructor
		this->ID = ID;
		
		sl = strlen(firstName);
		this->firstName = new char[sl+1];
		for(unsigned int i = 0; i < sl; i++){
			this->firstName[i] = firstName[i];
		}
		
		sl2 = strlen(lastName);
		this->lastName = new char[sl2+1];
		for(unsigned int i = 0; i < sl2; i++){
			this->lastName[i] = lastName[i];
		} 
		
		this->GPA = GPA;
		
		cout<< "Parametrized Constructor called!" << endl;
	}
	
	Students(const Students &p){//copy constructor 
		ID = p.ID;
		
		sl = p.sl;
		firstName = new char[sl+1];
		for(unsigned int i = 0; i < sl; i++){
			firstName[i] = p.firstName[i];
		}
		
		sl2 = p.sl2;
		lastName = new char[sl2+1];
		for(unsigned int i = 0; i < sl2; i++){
			lastName[i] = p.lastName[i];
		}		
		
		GPA = p.GPA;
		
		cout << "Copy constructor! " << endl;
	}
	
	~Students(){//destructor
		delete [] firstName;
		delete [] lastName;
		cout << "Destructor!" << endl;
	}

	
	void setID(int a){
		ID = a;
	}
	void setFirstName(const char *firstName){
		this->firstName = (char*) malloc(strlen(firstName)+1);
		strcpy(this->firstName, firstName);
		}
	void setLastName(const char *lastName){
			this->lastName = (char*) malloc(strlen(lastName)+1);
			strcpy(this->lastName, lastName);
		}
	void setGPA(float b){
		GPA = b;
	}
	
	void getID(){
		cout << ID << endl;
	}
	void getfirstname(){
		cout << firstName << endl;
	}
	void getlastname(){
		cout << lastName << endl;
	}
	void getGPA(){
		cout << GPA << endl;
	}
};

void testS(){
	/* get and set functions */
	Students Alex;
	Alex.setID(896);
	Alex.setFirstName("Alex");
	Alex.setLastName("Molina");
	Alex.setGPA(3.5);
	cout << "Student 1" << endl;

	Alex.getID();
	Alex.getfirstname();
	Alex.getlastname();
	Alex.getGPA();


	/* constructors*/
	Students Jordan(236, "Jordan", "Hunter" , 3.2);
	Jordan.getID();
	Jordan.getfirstname();
	Jordan.getlastname();
	Jordan.getGPA();
	cout<< endl;

	
    
    Students quitter = Jordan; 
	cout << "Copy: " << endl;
	quitter.getID();
	quitter.getfirstname();
    quitter.setLastName("Sarina");
	quitter.getlastname();
	quitter.setGPA(1.3);
	quitter.getGPA();
	cout << endl;
	
}
//--------------------------------PROFESSORS---------------------------------------------------------------------------------------
class Professors{
public:
	
	enum Department{
		Dep = 1, BIO, CHEM, PHYS, CS, MATH
	};
	
private:
	int ID;
	char* firstName;
	char* lastName;
	float salary;
	bool tenured; 
	Department department;
	
	 int sl;
	 int sl2;
		
public:
	//----------------------Constructors/Destructors---
	Professors(){//default constructor
	}
	
	Professors(int ID, const char* firstName, const char* lastName, float salary, bool tenured, Department department){//paramterized constructor
		this->ID = ID;
		
		sl = strlen(firstName);
		this->firstName = new char[sl + 1];
		for(unsigned int i = 0; i < sl; i++){
			this->firstName[i] = firstName[i];
		}
		
		sl2 = strlen(lastName);
		this->lastName = new char[sl2 + 1];
		for(unsigned int i = 0; i < sl2; i++){
			this->lastName[i] = lastName[i];
		}
	
		this->salary = salary;
		
		this->tenured = tenured;
		
		this->department = department;
		
		cout<< "Parameterized constructorcalled!" << endl;
	}
	Professors(const Professors& p){//copy constructor
		ID = p.ID;
		
		sl = p.sl;
		firstName = new char[sl+1];
		for(unsigned int i = 0; i < sl; i++){
			firstName[i] = p.firstName[i];
		}
		
		sl2 = p.sl2;
		lastName = new char[sl2+1];
		for(unsigned int i = 0; i < sl2; i++){
			lastName[i] = p.lastName[i];
		}		
		
		salary = p.salary;
		
		tenured = p.tenured;
		
		department = p.department;
		cout << "Copy constructor was called!!"<< endl;
	}
	~Professors(){//destructor
		delete[] firstName;
		delete[] lastName;
		cout << "Destructor!" << endl;
	}
	
	
	void setID(int a){
		ID = a;
	}
	void setfirstname(const char* firstName){
		sl = strlen(firstName);
		this->firstName = new char[sl+1];
		for(unsigned int i = 0; i < sl; i++){
			this->firstName[i] = firstName[i];
		}
	}
	void setlastname(const char* lastName){
		sl2 = strlen(lastName);
		this->lastName = new char[sl2 +1];
		for(unsigned int i = 0; i < sl2; i++){
			this->lastName[i] = lastName[i];
		}
	}
	void setsalary(float b){
		salary = b;
	}
	void settenured(bool c){
		tenured = c;
	}
	void setdepartment(Department x){
		department = x;
	}
	//----------------------Getting Functions----------
	void getID(){
		cout << ID << endl;
	}
	void getfirstname(){
		for(unsigned int i = 0; i < sl; i++){
			cout << firstName[i];
		}
		cout << endl;
	}
	void getlastname(){
		for(unsigned int i = 0; i < sl2; i++){
			cout << lastName[i];
		}
		cout << endl;
	}
	void getsalary(){
		cout << salary << endl;
	}
	void gettenured(){
		if(tenured == 1){
			cout << "A tenured professor at Seattle University" << endl;
		}
		else if(tenured == 0){
			cout << "Not a tenured professor" << endl;
		}
	}
	void getdepartment(){
		if(department == 1){
			cout << "Professor works in a Department" << endl;
		}
		if(department == 2){
			cout << "Professor works in the BIO department" << endl;
		}
		if(department == 3){
			cout << "Professor works in the CHEM department" << endl;
		}
		if(department == 4){
			cout << "Professor works in the CS department" << endl;
		}
		if(department == 5){
			cout << "Professor works in the PHYS department" << endl;
		}
		if(department == 6){
			cout << "Professor works in the MATH department" << endl;
		}
	}
};

void testP(){

	Professors Garcia;
	cout << "Professor 1: " << endl;
	Garcia.setID(333);
	Garcia.setfirstname("Mercedes");
	Garcia.setlastname("Garcia");
	Garcia.setsalary(186235);
	Garcia.settenured(false);
	Garcia.setdepartment(Professors::BIO);
	Garcia.getID();
	Garcia.getfirstname();
	Garcia.getlastname();
	Garcia.getsalary();
	Garcia.gettenured();
	Garcia.getdepartment();
	cout<< endl;
	
	Professors Marshall(21358, "Robert", "Marshall", 1500.0, false, Professors::MATH);

	Marshall.getID();
	Marshall.getfirstname();
	Marshall.getlastname();
	Marshall.getsalary();
	Marshall.gettenured();
	Marshall.getdepartment();
	cout << endl;
	Professors professor3 = Marshall; 
	professor3.getID();
	professor3.getfirstname();
	professor3.getlastname();
	professor3.getsalary();
	professor3.gettenured();
	professor3.getdepartment();
	cout << endl;
	
	
	
}

//-----------------------------------------EMPLOYEE----------------------------------------------//

class Employee{
private: 
	int  ID;
    char *firstName;
    char *lastName;
    float salary;

	unsigned int sl;
	unsigned int sl2;
public:
	//----------------------Constructors---------------
	Employee(){//default constructor 
	}
	
	Employee(int ID, const char* firstName, const char* lastName, float salary){
    //Parametrized Constructor
		this->ID = ID;
		
		sl = strlen(firstName);
		this->firstName = new char[sl+1];
		for(unsigned int i = 0; i < sl; i++){
			this->firstName[i] = firstName[i];
		}
		
		sl2 = strlen(lastName);
		this->lastName = new char[sl2+1];
		for(unsigned int i = 0; i < sl2; i++){
			this->lastName[i] = lastName[i];
		} 
		
		this->salary = salary;
		
		cout<< "Parametrized Constructor called!" << endl;
	}
	
	Employee(const Employee &p){
        //copy constructor 
		ID = p.ID;
		
		sl = p.sl;
		firstName = new char[sl+1];
		for(unsigned int i = 0; i < sl; i++){
			firstName[i] = p.firstName[i];
		}
		
		sl2 = p.sl2;
		lastName = new char[sl2+1];
		for(unsigned int i = 0; i < sl2; i++){
			lastName[i] = p.lastName[i];
		}		
		
		salary = p.salary;
		
		cout << "Copy constructor! " << endl;
	}
	
	~Employee(){
    //destructor
		delete [] firstName;
		delete [] lastName;
		cout << "Destructor!" << endl;
	}

	
	void setID(int a){
		ID = a;
	}
	void setFirstName(const char *firstName){
		this->firstName = (char*) malloc(strlen(firstName)+1);
		strcpy(this->firstName, firstName);
		}
	void setLastName(const char *lastName){
			this->lastName = (char*) malloc(strlen(lastName)+1);
			strcpy(this->lastName, lastName);
		}
	void setsalary(float b){
		salary = b;
	}
	
	void getID(){
		cout << ID << endl;
	}
	void getfirstname(){
		cout << firstName << endl;
	}
	void getlastname(){
		cout << lastName << endl;
	}
	void getsalary(){
		cout << salary << endl;
	}
};

void testE(){
	/* get and set functions */
	Employee Justine;
	Justine.setID(896);
	Justine.setFirstName("Justine");
	Justine.setLastName("Williams");
	Justine.setsalary(150000);
	cout << "Employee 1" << endl;

	Justine.getID();
	Justine.getfirstname();
	Justine.getlastname();
	Justine.getsalary();


	/* constructors*/
	Employee Nadia(23, "Nadia", "Hello" , 250);
	Nadia.getID();
	Nadia.getfirstname();
	Nadia.getlastname();
	Nadia.getsalary();
	cout<< endl;

    
    Employee quitter = Nadia; 
	cout << "Copy: " << endl;
	quitter.getID();
	quitter.getfirstname();
	quitter.getlastname();
	quitter.getsalary();
	cout << endl;
	
}











//-----------------------------------------------------------------------------------------------------------------------
int main (){
    testS();
    testP();
    testE();
}




/* I can be sure that all of the class methods are working properly because 
when I want them to print something within the class, the correct information prints. 
When testing the paramterized constructor the output comes out as desired and
according to the parameters that were set. When testing the copy constructor 
the output is equal to the one I set it equal to. Because of the place where my destructor
is placed I think I dont have any memory leaks*/