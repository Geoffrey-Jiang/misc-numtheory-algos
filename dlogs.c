#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printListOfPrimes(int *primes);
int *generateListOfPrimes(int upper);
int *findGenerator (int prime);

int main (void) {
    printf("Input number: ");
    int n = 0;
    scanf(" %d", &n);
    printListOfPrimes(generateListOfPrimes(n));
}

void printListOfPrimes(int *primes) {
    int index = 0;
    while (primes[index] != 0) {
        printf("%d ", primes[index]);
        index++;
    }
}

int *generateListOfPrimes(int upper) {
    // Create an array initialised by 1's
    int *numbers = malloc(upper * sizeof(int));
    int *primes = malloc(upper * sizeof(int));
    for (int i = 0; i < upper; i++) {
        numbers[i] = 1;
        primes[i] = 0;
    }
    int no_primes = 0;

    // Sieve
    for (int i = 2; i < upper; i++) {
        if (numbers[i] == 1) {
            primes[no_primes] = i;
            no_primes++;
            for (int j = i; j < upper; j += i) {
                numbers[j] = 0;
            }
        }
    }

    return primes;
}

// Validate this function...
// Generator definition confirm...

int *findGenerator (int prime) {
    int *Generator = malloc(prime * sizeof(int));
    int GeneratorsCount = 0;

    for (int g = 2; g < prime; g++) {
        // Check for proper distribution 
        int *distribution = malloc(prime * sizeof(int));
        for (int i = 0; i < prime; i++) {
            distribution[i] = 0;
        }

        // Checking results
        for (int i = 1; i <= prime; i++) {
            int result = pow(g, i);
            distribution[result % prime] = 1;
        }

        for (int i = 1; i < prime; i++) {
            if (distribution[i] == 0) {
                free(distribution);
                continue;
            }
        }
        free(distribution);
        Generator[GeneratorsCount] = g;
        GeneratorsCount++;
    }

    return Generator;
}