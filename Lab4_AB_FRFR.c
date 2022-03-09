#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *FilePtr; 

typedef struct student 
{
    int ID;
    char FirstName[30];
    char LastName[30];
    float GPA;
	struct student* next; 
} Student; 

Student* FrontNode = NULL; 
Student* createStudentNode(int id_in, char fn[30], char ln[30], float gpan)
{
	Student* NewNode = (Student*) malloc(sizeof(Student)); 
	
	if(NewNode != NULL) 
	{
		NewNode->ID = id_in;
		strcpy(NewNode->FirstName, fn);
		strcpy(NewNode->LastName, ln);
		NewNode->GPA = gpan;
		NewNode->next = NULL;
	}
	
	return NewNode; 
}

void addStudentNode(Student* NewNode)
{
	Student* currentNode = FrontNode; 
	
	if(FrontNode == NULL) 
	{
		FrontNode = NewNode;
		return; 
	}
	
	while(currentNode->next != NULL)
	{				   
		currentNode = currentNode->next; 
	}
	currentNode->next = NewNode; 
	NewNode->next = NULL;	  
}

void insertStudent(Student* NewNode) 
{
	Student* node = FrontNode; 
	
	while(node->next != NULL) 
	{
		Student* nextNode = node->next;
		
		if((node->GPA > NewNode->GPA) && (NewNode->GPA >= nextNode->GPA))
		{								
			NewNode->next = node->next;
			node->next = NewNode; 
			return; 
		}
		
		else if(node->GPA <= NewNode->GPA) 
		{				      
			NewNode->next = node; 
			FrontNode = NewNode; 
			return; 
		}
		
		node = node->next;
	}
	
	node->next = NewNode; 
	NewNode->next = NULL; 
	return; 
	
}

void deleteStudent(Student* deleteStudent) 
{
	Student* currentNode = FrontNode; 
	Student* PrevStudent = NULL; 
	
	if(FrontNode == deleteStudent) 
	{
		FrontNode = FrontNode->next;
		free(deleteStudent);
		return; 
	}
	
	while(currentNode != NULL && currentNode != deleteStudent) 
	{
		PrevStudent = currentNode; 
		currentNode = currentNode->next; 
	}
	
	if(currentNode != NULL) 
	{
		PrevStudent->next = currentNode->next; 
	}						 
	
	free(deleteStudent); 
}


void ReadRecords(void);

void ScanList(void); 
void FreeList(void); 
void saveList(void);
void RemoveStudent(int id_in); 
void UpdateStudent(int id_in); 
void menuDisplay(void); 
void UpdateStudentMenu(char first[30], char last[30]); 

int main()
{
	int user_in; 
	
	ReadRecords(); 
	do 
	{
		int id_input;
		char firstin[30] = "";
		char lastin[30] = "";
		float gpa_input = 0.0;
		int userID_in; 
		Student* idCheck = FrontNode; 
		
		menuDisplay(); 
		printf("\nWhat would you like to do? "); 
		scanf("%d", &user_in); 
		
		switch(user_in) 
		{
			case 1 : 
				ScanList(); 
				break; 
				
			case 2 : 
				printf("\nEnter the ID of the student: "); 
				scanf("%d", &id_input);
				while(idCheck != NULL)
				{
					if(id_input == idCheck->ID) 
					{
						printf("\nEntered ID is currently used by and existing student.");
						idCheck = FrontNode; 
						printf("\nEnter the ID of the student: ");
						scanf("%d", &id_input); 
					}
					idCheck = idCheck->next; 
				}
				
				printf("\nEnter the first name of the student: "); 
				scanf("%29s", firstin);
				
				printf("\nEnter the last name of the student: "); 
				scanf("%29s", lastin); 
				
				printf("\nEnter the GPA of the student: "); 
				scanf("%f", &gpa_input); 
				while((gpa_input > 4.0) || (gpa_input < 1.0)) 
				{
					printf("\nPlease enter a GPA in the range of 4.0 and 1.0."); 
					printf("\nEnter the GPA of the student: ");
					scanf("%f", &gpa_input); 
				}
				
				Student* anotherPtr = createStudentNode(id_input, firstin, lastin, gpa_input); 
				insertStudent(anotherPtr);
				break; 
				
			case 3 : 
				printf("\nEnter the ID of the student you wish to delete: "); 
				scanf("%d", &userID_in); 
				RemoveStudent(userID_in);
				break; 
				
			case 4 : 
				printf("\nEnter the ID of the student you wish to update: "); 
				scanf("%d", &userID_in); 
				UpdateStudent(userID_in); 
				break; 
			
			case 5 : 
				printf("\nOkay Bye!");
				break; 
			
			default : 
				printf("\nInvalid input\n"); 
		}
	}while(user_in != 5); 
	saveList(); 
	FreeList(); 
}


void ReadRecords() 
{
	char first_out[30], last_out[30];
	int numOut, id_out;
	float gpa_out;
	
	FilePtr = fopen("RED.txt", "r"); 
	fscanf(FilePtr, "Number of students: %d", &numOut); 
	
	for(int i=0; i<numOut; i++) 
	{
		fscanf(FilePtr, "\n\nStudent ID: %d", &id_out);
		fscanf(FilePtr, "\nStudent First Name: %s", first_out);
		fscanf(FilePtr, "\nStudent Last Name: %s", last_out);
		fscanf(FilePtr, "\nStudent GPA: %f", &gpa_out);
		
		Student* somePTR = createStudentNode(id_out, first_out, last_out, gpa_out); 
		addStudentNode(somePTR);
	}
	
}

void ScanList() 
{
	Student* node = FrontNode; 
	printf("\n---Students---"); 
	while(node != NULL) 
	{
		printf("\n\nStudent ID: %d", node->ID);
		printf("\nStudent First Name: %s", node->FirstName);
		printf("\nStudent Last Name: %s", node->LastName);
		printf("\nStudent GPA: %f", node->GPA);
		node = node->next;
	}
	printf("\n\n-----------------"); 
}

void FreeList()
{
	Student* node = FrontNode; 
	Student* nextNode = FrontNode->next; 
	while(node != NULL) 
	{
		deleteStudent(node);
		node = nextNode; 
		nextNode = nextNode->next; 
	}
}


void RemoveStudent(int id_in) 
{
	Student* node = FrontNode; 
	int check = 0;
	while(node != NULL) 
	{
		if(id_in == node->ID) 
		{
			char first[30];
			char last[30];
			strcpy(first, node->FirstName);
			strcpy(last, node->LastName);
			deleteStudent(node); 
			check = 1; 
			printf("\n%s %s was successfully deleted.", first, last); 
			return; 
		}
		node = node->next; 
	}
	if(check == 0) 
	{
		printf("\n No record of this student: ");
		return; 
	}
	return; 
}

//-----------------------------------------------------------------------------

void saveList()
{
	FilePtr = fopen("RED.txt", "w+"); 
	Student* node = FrontNode; 
	int studentCount = 0;
	while(node != NULL) 
	{
		studentCount++; 
		node = node->next; 
	}
	
	fprintf(FilePtr, "Number of students: %d ", studentCount); 
	node = FrontNode; 
	while(node != NULL) 
	{
		fprintf(FilePtr, "\n\nStudent ID: %d", node->ID);
		fprintf(FilePtr, "\nStudent First Name: %s", node->FirstName);
		fprintf(FilePtr, "\nStudent's Last Name: %s", node->LastName);
		fprintf(FilePtr, "\nStudent's GPA: %f", node->GPA);
		node = node->next; 
	}
	fclose(FilePtr); 
}


//-------------------------------------------------------------------------------------------------

void menuDisplay() 
{
	printf("\n--Menu--");
	printf("\n 1) List All Students");
	printf("\n 2) Add Student");
	printf("\n 3) Remove Student");
	printf("\n 4) Update Student");
	printf("\n 5) Quit");
	printf("\n----------------------");
}

//--------------------------------------------------------------------------------------------

void UpdateStudentMenu(char first[30], char last[30]) 
{
	printf("\n--Update Menu--");
	printf("\nWhat would you like to update about %s %s?", first, last);
	printf("\n\n 1) ID");
	printf("\n 2) First Name");
	printf("\n 3) Last Name");
	printf("\n 4) GPA");
	printf("\n5) Quit");
	printf("\n\n-----------");
	printf("\n\n");
}

//-----------------------------------------------
void UpdateStudent(int id_in)
{
	Student* node = FrontNode; 
	Student* prevNode = node; 
	int check = 0;
	int user_input = 0; 
	while(node != NULL) 
	{
		if(id_in == node->ID) 
		{
			do 
			{
				UpdateStudentMenu(node->FirstName, node->LastName);
				scanf("%d", &user_input);

				int new_id, old_id;
				char new_first[30], old_first[30];
				char new_last[30], old_last[30];
				float new_gpa, old_gpa;
				Student* idCheck = FrontNode;
				
				switch(user_input) 
				{
					case 1 :
						printf("\nEnter the new ID: "); 
						scanf("%d", &new_id); 
						while(idCheck != NULL) 
						{
							if(new_id == idCheck->ID)
							{
								printf("\nEntered ID is currently used by and existing student."); 
								idCheck = FrontNode; 
								printf("\nEnter the ID of the student: ");
								scanf("%d", &new_id); 
							}
							idCheck = idCheck->next; 
						}
						old_id = node->ID; 
						node->ID = new_id; 
						printf("\n%d was sucessfully updated to %d", old_id, new_id); 
						break;
					case 2 : 
						printf("\nEnter the new first name: "); 
						scanf("%29s", new_first); 
						strcpy(old_first, node->FirstName); 
						strcpy(node->FirstName, new_first); 
						printf("\n%s was sucessfully updated to %s", old_first, new_first); 
						break; 
					case 3 : 
						printf("\nEnter the new last name: "); 
						scanf("%29s", new_last); 
						strcpy(old_last, node->LastName); 
						strcpy(node->LastName, new_last); 
						printf("\n%s was sucessfully updated to %s", old_last, new_last); 
						break; 
					case 4 : 
						printf("\nEnter the new GPA: "); 
						scanf("%f", &new_gpa); 
						while((new_gpa > 4.0) || (new_gpa < 1.0)) 
						{
							printf("\nPlease enter a GPA in the range of 4.0 and 1.0.");
							printf("\nEnter the GPA of the student: "); 
							scanf("%f", &new_gpa); 
						}
						old_gpa = node->GPA; 
						node->GPA = new_gpa; 
						if(prevNode == node)
						{
							node->next = NULL; 
							insertStudent
                        (node); 
						}
						else 
						{
							prevNode->next = node->next; 
							insertStudent
                        (node); 
						}
						printf("\n%f was updated to %f", old_gpa, new_gpa); 
						break; 
					
					case 5 : 
						break;
					
					default :
						printf("\nInvalid input\n");
				}
			} while(user_input != 5); 
			return; 
		}
		prevNode = node; 
		node = node->next; 
	}
}