#include <stdio.h>
#include <stdlib.h>


typedef struct Stack
{
	float data;
    struct Stack* next;  
} Stack;


Stack* initialItem = NULL;


Stack* createStack(float in)
{
	Stack* newMember = (Stack*) malloc(sizeof(Stack));
	
	if(newMember != NULL)
    {
		newMember->data = in;
		newMember->next = NULL;
	}
	
	return newMember;
}
 

int size()
{
  Stack* node = initialItem;
	int counter = 0;
	while(node != NULL)
    {
		counter++;
		node = node->next;
	}
	return counter;
}
 

int isEmpty()
{
    return initialItem == NULL;
}
 

int isFull()
{
    return (malloc(sizeof(Stack)) == NULL);
}
 

int push(float x)
{

    if (isFull())
    {
        printf("Stack Full!\n");
        return -1;
    }
	
	Stack* newItem = createStack(x);
 
  printf("Inserting %f\n", x);
 
    
	if(initialItem == NULL)
    {
		initialItem = newItem;
		return 0;
	}
  
	newItem->next = initialItem;
	initialItem = newItem;
  return 0;
}
 

int pop()
{
    
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
   
	printf("Removing %f\n", initialItem->data);
    Stack* tempVal = initialItem;
	initialItem = initialItem->next;
	free(tempVal);
    
  return 0;
}
 

int peek(float* x)
{
    
    if (isEmpty())
    {
        printf("Stack Empty!\n");
        return -1;
    }
 
    
    *x = initialItem->data;
    return 0;
}
 
int main()
{
    float value;
 
    push(1.0);
    push(2.0);
    push(3.0);
 
    printf("The stack size is %d\n", size());

    peek(&value);
    printf("Top val on stack is %f\n", value);

    pop();
    pop();
    pop();
 
    if (isEmpty())
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty");
    }
 
    return 0;
}