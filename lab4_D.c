#include <stdio.h>
#include <stdlib.h>


typedef struct Queue
{
	float info;
	struct Queue* next;
} Queue;

Queue* FrontNode = NULL;

Queue* NewQue(float input)
{
  Queue* anotherQ = (Queue*)malloc(sizeof(Queue));
	if (anotherQ != NULL)
	{
		anotherQ->info = input; 
		anotherQ->next = NULL;
	} 
    return anotherQ;
}
 

int Size()
{
	Queue* node = FrontNode;
	int counter = 0;
	while(node != NULL)
    {
		counter++;
		node = node->next;
	}
    return counter;
}
 

int IsEmpty()
{
    return  FrontNode == NULL);       
}


int IsFull()
{
    return (malloc(sizeof(Queue)) == NULL);  
}
 

int Insert(float x)
{
   
    if (IsFull())
    {
        printf("Queue Full!\n");
        return -1;
    }
	
	Queue* newNode = NewQue(x);
 
    printf("Inserting %f\n", x);
 

	if FrontNode == NULL)
    {
	 FrontNode = newNode;
		return 0;
	}
	Queue* presentNode = FrontNode;
	while(presentNode->next != NULL)
    {
		presentNode = presentNode->next;
	}
	presentNode->next = newNode;
	newNode->next = NULL;
    
    return 0;
}
 

int Remove()
{
    if (IsEmpty())
    {
        printf("Queue Empty!\n");
        return -1;
    }
 
    
    printf("Removing %f\n", FrontNode->data);
	Queue* tempVal = FrontNode;
 FrontNode = FrontNode->next;
	free(tempVal);
	
    return 0;
}
 

int Peek(float* x)
{
    
    if (IsEmpty())
    {
        printf("Queue Empty!\n");
        return -1;
    }

    *x = FrontNode->data;
    return 0;
}


int main()
{
  
    float value;
 
    Insert(1.0);
    Insert(2.0);
    Insert(3.0);
 
    printf("The queue Size is %d\n", Size());

    Peek(&value);
    printf("Top val on queue is %f\n", value);

    Remove();
    Remove();
    Remove();
 
    if (IsEmpty())
    {
        printf("The queue is empty");
    }
    else
    {
        printf("The queue is not empty");
    } 
    return 0;
}