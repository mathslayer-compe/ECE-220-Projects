#include <stdlib.h>
#include <stdio.h>


/*
 * is_prime: determines whether the provided number is prime or not
 * Input    : a number
 * Return   : 0 if the number is not prime, else 1
 */

//Group partners: Kevin Kim (sangwoo2), Akhil Nallacheruvu(analla6)

//List of Errors encountered
// error 1: is_prime function and its for loop. It returns 1 when the number wasn't a prime number, and returns
//          0 when it is a prime number. Originally, this was a big error because it didn't print out the 
//          numbers that had prime numbers. Changed return values where if number was a prime number, 
//          it returned 1, if it wasn't, it returned 0 (changed for loop).

// error 2: added if conditions before printing out semiprime numbers. Original code only had function is_prime(k), this wasn't enough checks,
//	    as numbers like 12 was getting printed out. 


// error 3: changed k = i%j into k = i/j. This mainly printed out both semi-primes and non-semi prime numbers. For example, 
//	    12 was printed out because 12%2 equals 0, and that there had to be one more check on the other operand to see if that operand
//	    was a prime number. Since 12 = 2*6, and that there wasn't any prime number check on 6, the division for k is needed for the purpose to see if that other operand was a prime number. 

// error 4: added break as this printed out multiple semiprime numbers. When input was 2 and 6, it printed out 4 6 6, and that the break after one print solved the issue of printing out multiple
//	    semiprime numbers. 

// error 5: added RET values where the value is 1 when there's a semiprime within the range given by the user, and 0 if there aren't any semiprime numbers within that same range. 

int is_prime(int number)
{
    int i;
    if (number == 1) {return 0;} 				

    for (i = 2; i < number; i++) { 				
        if (number % i == 0) { 					
            return 0;						//see error 1
        }
    }
   return 1;
}


/*
 * print_semiprimes: prints all semiprimes in [a,b] (including a, b).
 * Input   : a, b (a should be smaller than or equal to b)
 * Return  : 0 if there is no semiprime in [a,b], else 1
 */
int print_semiprimes(int a, int b)
{
    int i, j;
    float k;
    int ret = 0;
    for (i = a; i <=b; i++){ 					//for each item in interval ranges from a to b
        //check if semiprime
        for (j = 2; j <= i; j++){
            if (i%j == 0) {
	      if (is_prime(j)) {       				
                    k = i/j;					//see error 3
                    if (i != j && is_prime(k)) 			//see error 2
			{    					
			printf("%d ", i);
			ret = 1;				//see error 4
			}
			break;
		    }             
		}
            }        
}

    
    printf("\n");
    return ret;

}
