#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "libs/big_int.h"
 
void print(big_int *gcd);	
int isValidate(big_int *number1, big_int *number2);	
big_int * euclid(big_int *number1, big_int *number2);			//алгоритм Евклдиа для больших чисел




void print(big_int *gcd) {
	printf("The result of the Euclidean algorithm: ");
	printf("NOD = %s\n", dprint(gcd));
}

int isValidate(big_int *number1, big_int *number2) {
   
    if ((dprint(number1)[0] == '0') || (dprint(number2)[0] == '0')) {
		printf("The result is undefined!");
		return(0);
	}
	if (!compare(number1, number2)) {
		printf("NOD = %s\n", dprint(number1));
		return(0);
	}
	if ((!compare(number1, dcreate("1"))) || (!compare(number2, dcreate("1")))) {
		printf("NOD = 1\n");
		return(0);
	}

	return(1);
}
 

big_int * euclid(big_int *number1, big_int *number2) {

	if (compare(number1, number2) > 0){
        big_int *tmp = number1;
        number1 = number2;
        number2 = tmp;
    }
    
	big_int *div = number1;
	big_int *mod;
	big_int *gcd = 0;

	while (1) {

        divide(div, number2, &mod);
		div = number2;
		number2 = mod;

		if (dprint(mod)[0] == '0') 
			break;
		else
			gcd = mod;

	}

	if (gcd > 0) 
		return(gcd);
	
}



int main() {

    big_int *number1 = dcreate("432322");
    big_int *number2 = dcreate("24");

	if (isValidate(number1, number2) > 0) {
         big_int * gcd = euclid(number1, number2);
		 if (compare(gcd, dcreate("0")) > 0) {
		    print(gcd);
		 }
	}
    
	getchar();
	return(0);
}
