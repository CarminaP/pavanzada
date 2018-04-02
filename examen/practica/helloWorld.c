#include <stdio.h>
#define MAX_IN 250

/*
scanf() needs a format specifier for a particular type of data.
If you're not sure about the input data type, use fgets() to take the data from the user.
ref: https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm
char *fgets(char *str, int n, FILE *stream)
str − The pointer to an array of chars where the string read is stored.
n − The maximum number of characters to be read (including the final null-character).
stream − The pointer to a FILE object that identifies the stream where characters are read from.
*/

int main() {
  char input[MAX_IN];
  fgets(input, MAX_IN, stdin);
	printf("Hello World");
	return 0;
}
