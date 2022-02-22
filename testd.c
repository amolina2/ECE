
int countVowels(char x[100]){
  int vowels = 0;
	for(int i = 0; i < strlen(x); i++){
    if(x[i] == 'a' || x[i] == 'A' || x[i] == 'e' || x[i] == 'E' || x[i] == 'i' || 
        x[i] == 'I' || x[i] =='o' || x[i]=='O' || x[i] == 'u' || x[i] == 'U'){
            vowels++;
    }
  }
  printf("Number of vowels %d\n", vowels);
  printf("\n");
return 0;
}

int countConsonants(char x[100]){
  int cons = 0;
	for(int i = 0; i < strlen(x); i++){
	if(x[i] == 'a' || x[i] == 'A' || x[i] == 'e' || x[i] == 'E' || x[i] == 'i' || 
        x[i] == 'I' || x[i] =='o' || x[i]=='O' || x[i] == 'u' || x[i] == 'U' || x[i] == ' '){
		}
	else{
		cons++;
	}
  }
  printf("Number of consonats: %d\n", cons);
  printf("\n");
return 0;
}

void UpperCase(char x[100]){
	for(int i = 0; i < strlen(x); ++i){
		if(x[i]> 96 && x[i] < 123){
			x[i] = x[i]-32;
		}  
	}
	printf("The string is: %s\n", x);	
return 0;
}

int LowerCase(char x[100]){
	for(int i = 0; i < strlen(x); ++i){
		if(x[i]> 64 && x[i] < 91){
			x[i] = x[i]+32;
		}  
	}
	printf("The string is: %s\n", x);
return 0;	
}

int printing(char x[100]){
	printf("%s\n", x);
return 0;
}

void reverseIt(char str[], int start, int end){
    char temp;
    while(start<end)
    {
        temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
}


int main(){

  char x[100];
  char y, a;
	printf("Enter a string: \n");
	scanf("%[^\n]",x);

	while(1){
	  printf("A) Count the number of vowels in the string\n");
	  printf("B) Count the number of consonants in the string\n");
	  printf("C) Convert the string to uppercase\n");
	  printf("D) Convert the string to LowerCase\n");
	  printf("E) Display the current string\n");
	  printf("F) Enter another string\n");
	  printf("M) Display the menu\n");
	  printf("R) Reverse the string\n");
	  printf("X) Exit the program\n");
	  printf("Choose an option(A-X): \n");
	  scanf("%c", &y);
	  scanf("%c", &a);

    if(a == 'A'){
      countVowels(x);
    }
    else if(a == 'B'){
      countConsonants(x);
    }
    else if(a == 'C'){
      UpperCase(x);
    }
    else if(a == 'D'){
      LowerCase(x);
    }
    else if(a == 'E'){
      printing(x);
    }
    else if(a == 'F'){
      printf("Enter a string: \n");
	  scanf("%[^\n]",x);
    }
    else if(a == 'M'){
      continue;
    }
    else if(a == 'X'){
      printf("Okay bye!");
      break;
	}
	else if(a == 'R'){
		int start, end;
		end=0;
		start=0;
		while(x[end])
		{
			for(end=start;x[end]&&x[end]!=' ';end++);
			reverseIt(x, start, end-1);
			start=end+1;
		}
			printf("%s\n",x);
	}
    else{
	   printf("Invalid input!\n");
    }
  }
  
return 0;

}
