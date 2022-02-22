#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define n 10




/*Part A*/


int theArray[10] = {1,2,3,4,5,6,7,8,9,10};


void ReverseArray(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int temp;
    for(int i = 0; i<n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d,", arr[i]);
    }
}


/*Part B*/

typedef struct student
{
    int  ID;
    char first[30];
    char last[30];
    float GPA;
} Student;




Student* CreateStudent(void)
{
	int  x;
	int i; 
    char fn[30];
    char ln[30];
    float g;
	Student* Studinf = (Student*)malloc(sizeof(Student));


	printf("Student's ID: ");
	scanf("%d", &x);
	Studinf ->ID = x;
	printf("First Name: ");
	scanf("%s", fn);
	strcpy(Studinf->first,fn);
	printf("Last Name: ");
	scanf("%s", ln);
	strcpy(Studinf->last, ln);
	printf("Student's GPA: ");
	scanf("%f", &g);
	Studinf ->GPA = g;
	return Studinf;
}


void readFile(Student** array)
{
	int SUID = 0;
	char firstname[30] = "";
	char lastname[30] = "";
	float grade;
	int studentnumb = 0;
	float avGPA = 0;
	char c;
	Student* pointer = (Student*)malloc(sizeof(Student));
	FILE *GPAFile;
	GPAFile = fopen("lol.txt", "r"); 

	if(GPAFile == NULL)
    {
		printf("File does not exist"); 
		return NULL;
	}

	fscanf(GPAFile, "number of students: %d\n", &studentnumb);
	printf("Number of Student: %d\n", studentnumb);

	for(int i = 0; i < studentnumb; i++)
    {
		fscanf(GPAFile, "Student ID: %d\n", &SUID ); 
		fscanf(GPAFile, "First Name: %s\n", firstname);
		fscanf(GPAFile, "Last Name: %s\n", lastname);
		fscanf(GPAFile, "GPA: %f\n", &grade);

		pointer -> ID = SUID; 
		strcpy(pointer -> first,firstname); 
		strcpy(pointer -> first,lastname);
		pointer -> GPA = grade;  

		printf("Student ID: %d\n", SUID); 
		printf("First Name: %s\n", firstname);
		printf("Last Name: %s\n", lastname);
		printf("GPA: %f\n", grade);

		array[i] = pointer; 
		avGPA += grade; 
	}
	avGPA /= studentnumb; 
	printf("There are %d students", studentnumb);
	printf("\nAverage GPA is: %f",avGPA);
}




int main()
{
    ReverseArray();

    
    struct student temp;

    int numStudents = 0;
    printf("\nHow many students in the class: \n");
    scanf("%d", &numStudents);
	Student **library = (Student*)malloc(numStudents*sizeof(Student));
	for(int i = 0; i < numStudents; i++)
    {
		printf("Student %d Details: \n", i+1);
		library[i] = CreateStudent();
	}



  
     for (int i = 0; i < numStudents; i++) 
     {     
        for (int j = i+1; j < numStudents; j++) 
        {     
           if(library[i]->GPA < library[j]->GPA) 
           {    
               Student* temp = library[i];    
               library[i] = library[j];    
               library[j] = temp;    
           }     
        }     
    }    

	FILE *myfile;
	myfile = fopen("lol.txt","wt");
	fprintf(myfile,"number of students: %d\n", numStudents);
	for(int i = 0; i < numStudents; i++)
    {
		fprintf(myfile,"Student ID: %d\n", library[i]->ID);
		fprintf(myfile,"First Name: %s\n", library[i]->first);
		fprintf(myfile,"Last Name: %s\n", library[i]->last);
		fprintf(myfile,"GPA: %f\n", library[i]->GPA);
										
    }
	fclose(myfile);
	free(library);

	Student** inf = (Student**)malloc(numStudents*sizeof(Student*));
	readFile(inf);
	free(inf);
}