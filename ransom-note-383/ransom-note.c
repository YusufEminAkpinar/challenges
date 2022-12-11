#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"

/* Loop through each element of str arr and  */

typedef struct tuple
{
	char character;
	int iValue;
} tuple;


// int intArrSize(int arr[]){
// 	int size = sizeof(arr)/sizeof(int);
// 	return size;
// }


bool checkDupe(char word[]){
	for (int i = 0; word[i] != '\0'; i++)
		for (int j = i+1; word[j] != '\0'; j++)
			if (word[i] == word[j])
				return false;
	return true;
}


char *remDupe(char word[]){
    char *new_word = malloc(sizeof(char) * strlen(word));
	/* I do not know if there is better way to do this but it looks really *loopy*... */
	strcpy(new_word, word);
	while (!checkDupe(new_word)) /* Continue to run until no more duplicate */	
		for (int i = 0; i < new_word[i] != '\0'; i++)		
			for (int j = i+1; new_word[j] != '\0'; j++)			
				if (new_word[i] == new_word[j])				
					for (int k = j; k <= (int)strlen(new_word); k++)					
						new_word[k] = new_word[k+1];																		
    return new_word;
}


static void arrOfNum(char word[], tuple arrTup[]){
	int *numArr = malloc(sizeof(int) * strlen(word));
 	char *cleanedWord = remDupe(word);
	for (size_t i = 0; i < strlen(cleanedWord); i++)
	{
		numArr[i] = 0;
		for (size_t j = 0; j < strlen(word); j++)
			if (cleanedWord[i] == word[j])
				numArr[i]++;
	}
	
	for (size_t i = 0; i < strlen(cleanedWord); i++)
	{
		arrTup[i].character = cleanedWord[i];
		arrTup[i].iValue = numArr[i]; 
	}
}



// bool canConstruct(char *ransomNote, char *magazine){
// 	int *ransom_count = arrOfNum(ransomNote);
// 	int *magazine_count = arrOfNum(magazine);
// 	for (size_t i = 0; i < sizeof(magazine_count)/sizeof(int); i++)
// 	{
		
// 	}
	
// }


bool compareTuples(tuple t1[], tuple t2[]){
	printf("The i will go for: %d, and j will go for: %d\n", sizeof(t1)/2, sizeof(t2)/2);
	for (int i = 0; i < sizeof(t1) ; i++)
	{
		printf("%c ", t1[i].character);
	}
	printf("\n\n");
	for (int i = 0; i < sizeof(t2) ; i++)
	{
		printf("%c ", t2[i].character);
	}	
	printf("\n\n");



	int cond;
	for (int i = 0; i <= sizeof(t1); i++)
	{
		cond = 0;
		for (int j = 0; j < sizeof(t2)/2; j++)
		{
			if (t1[i].character == t2[j].character)
			{
				printf("%c/%d and i:%d || %c/%d and j:%d\n", t1[i].character, t1[i].iValue, i, t2[j].character, t2[j].iValue, j);
				cond = 1;
				if (t1[i].iValue < t2[j].iValue)
				{
					printf("Okay that's the i: %d and j: %d\n", i, j);
					// return false;
				}
			}
		}

	}
	// for (int i = 0; i < sizeof(t1) ; i++)
	// {
	// 	printf("%c ", t1[i].character);
	// }
	return true;
}



int main(int argc, char const *argv[])
{
	char word[] = "abcw";
	char word2[] = "abce";	
	char *cleaned_word = remDupe(word);
	char *cleaned_word2 = remDupe(word2);
	tuple *arrTup = malloc(strlen(cleaned_word));
	tuple *arrTup2 = malloc(strlen(cleaned_word));
	arrOfNum(word, arrTup);
	arrOfNum(word2, arrTup2);
	// for (size_t i = 0; i < strlen(cleaned_word); i++)
	// {
	// 	printf("%c --> %d\n", arrTup[i].character, arrTup[i].iValue);
	// }
	// printf("\n\n");
	// for (size_t i = 0; i < strlen(cleaned_word2); i++)
	// {
	// 	printf("%c --> %d\n", arrTup2[i].character, arrTup2[i].iValue);
	// }
	// printf("Okay we understand this now its time to compare function\n\n\n\n");

	if (compareTuples(arrTup, arrTup2))
	{
		printf("Ho Ho Ho\n");
	}
	else
	{
		printf("Hi Hi Hi\n");
	}
	
	

	// printf("%d\n", sizeof(arrTup)/8);
	// printf("%d\n", sizeof(arrTup2)/8);
	// char w1[] = "ac";
	// int wa1[] = {4, 2};
	// char w2[] = "abc";
	// int wa2[] = {3, 2, 1};
	// for (size_t i = 0; w1[i] != '\0'; i++)
	// {
		
	// }
	


	return 0;
}
