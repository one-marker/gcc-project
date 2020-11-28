#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
 
void print(int gcd,int number1, int number2);
int isValidate(int number1, int number2);	
int euclid(int number1, int number2);			//алгоритм Евклдиа
	



void print(int gcd,int number1, int number2) {
	printf("Numbers: %d and %d\n", number1, number2);
	printf("The result of the Euclidean algorithm: \t");
	printf("NOD = %d\n", gcd);
}

int isValidate(int number1, int number2) {

   if ((number1 == 0) || (number2 == 0)) {
		printf("The result is undefined!");
		return(0);
	}
	if (number1 == number2) {
		printf("NOD = %d\n", number1);
		return(0);
	}
	if ((number1 == 1) || (number2 == 1)) {
		printf("NOD = 1\n");
		return(0);
	}
	return(1);
}
 



int euclid(int number1, int number2) {

	if (number1 > number2){
        int tmp = number1;
        number1 = number2;
        number2 = tmp;
    }
    
	int div;	
	int mod;
	int gcd = 0;

	while (1) {

		div = number1 / number2;
		mod = number1 % number2;
		number1 = number2;
		number2 = mod;

		if (mod == 0) 
			break;
		else
			gcd = mod;

	}

	if (gcd > 0) 
		return(gcd);
	
}



int main() {
	
	//используем int

	int number1 = 24;
	int number2 = 6;

	if (isValidate(number1, number2) > 0) {
        int gcd = euclid(abs(number1), abs(number2));
		if (gcd > 0) {
			print(number1, number2, gcd);
		}
	}
	
	getchar();
	return(0);
}