//unit6.hw
//Group members: Katie Kwatinetz, Lanaiya Walters, Jimmy Winchester

//include directives go here…
#include <stdio.h>
#include <stdlib.h>

//Prototypes
int most_occuring_character ( char *str);
void count_low_up_digit ( char *str, int *lower, int *upper , int *digit);
char * Up_letters ( char *str);

//Function definitions...

//MOST OCCURING CHARACTER
int most_occuring_character(char *str)
{
    int count[256] = {0};
    int counter = 0;
    char mostChar = -1;
    int index;

    // Count occurrences of each character
    for (int index = 0; str[index] != '\0'; index++) {
        if(str[index] != ' '){
            char c = str[index];
            count[(char)c]++;
                if (count[(char)c] > counter) {
                counter = count[(char)c];
                mostChar = c;
            }
        }
    }

    // Check if max_count is 1 (all characters appear once)
    if (counter <= 1) {
        return -1; // All characters appear only once
    }

    return (int)mostChar;
}

//COUNT LOWERCASE, UPPERCASE, AND DIGITS
void count_low_up_digit ( char *str, int *lower, int *upper , int *digit)
{
	int index;
	for(index = 0; index < strlen(str); index++)
    {
        if (isdigit(str[index]))
        {
           (*digit)++;
        }
        else if (islower(str[index]))
        {
            (*lower)++;
        }
        else if (isupper(str[index]))
        {
            (*upper)++;
        }
        else
        {
            continue;
        }
    }
}

//MAKES ALL LETTERS UPPERCASE AND IN ORDER
char * Up_letters ( char *str)
{

    int index = 0;
    int len = strlen(str);
    char *sortedstr = (char *)malloc((len + 1) * sizeof(char));


    for (int i = 0; i < len; i++)
    {
        if (isalpha(str[i]))
        {
            sortedstr[index++] = toupper(str[i]);
        }
    }
    sortedstr[index] = '\0';

    for (int i = 0; i < index - 1; i++)
    {
        for (int j = i + 1; j < index; j++)
        {
            if (sortedstr[i] > sortedstr[j])
            {
                char temp = sortedstr[i];
                sortedstr[i] = sortedstr[j];
                sortedstr[j] = temp;
            }
        }
    }

    return sortedstr;
}


//the following main function is to remain UNCHANGED!

int main()
{

      char str[50] ="";
      char *upper_sorted;
      char most_occur = -1;
      int lower_case=0 , upper_case=0, digits=0;


      printf("Enter your string: ");
      gets(str);


      most_occur = most_occuring_character ( str );
      if ( most_occur == -1 ) printf ("All characters appears once\n"); //ADDDED \n
      else printf ("The most occuring character is: %c \n", most_occur);

      count_low_up_digit ( str, &lower_case, &upper_case , &digits );
      printf ("There is/are %d lower case letter(s)\n", lower_case);
      printf ("There is/are %d upper case letter(s)\n", upper_case);
      printf ("There is/are %d digit(s)\n", digits);

      printf ("------\n\n"); //ADDED

      upper_sorted = Up_letters ( str );
      printf ("%s\n", upper_sorted);
      printf ("%s\n", str);




      return 0;
}
