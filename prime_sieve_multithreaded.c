#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

#define N 100000000 // the number of integers to generate
#define NUM_THREADS 8 // the number of threads to use

bool *is_prime; // boolean array to mark prime numbers

/**
 * Thread function to find prime numbers using the Sieve of Eratosthenes algorithm.
 * 
 * @param arg pointer to a uint32_t containing the thread ID
 * @return void pointer
 */
void *find_primes(void *arg) {
    uint32_t thread_id = *(uint32_t *) arg;
    uint32_t start = (N / NUM_THREADS) * thread_id + 1;
    uint32_t end = (N / NUM_THREADS) * (thread_id + 1);

    for (uint32_t i = start; i <= end; i++) {
        if (is_prime[i]) {
            for (uint32_t j = i * 2; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    pthread_exit(NULL);
}

int main(void) {
    clock_t start_time = clock(); // start timer

    is_prime = calloc(N + 1, sizeof(bool)); // allocate memory for boolean array

    for (uint32_t i = 2; i <= N; i++) {
        is_prime[i] = true; // mark all numbers as potentially prime
    }

    pthread_t threads[NUM_THREADS]; // array of threads
    uint32_t thread_ids[NUM_THREADS]; // array of thread IDs

    // create threads
    for (uint32_t i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, find_primes, &thread_ids[i]);
    }

    // join threads
    for (uint32_t i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // count the number of prime numbers found
    uint32_t count = 0;
    for (uint32_t i = 2; i <= N; i++) {
        if (is_prime[i]) {
            count++;
        }
    }

    free(is_prime); // free memory allocated for boolean array

    clock_t end_time = clock(); // end timer
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; // calculate elapsed time in seconds

    // print the number of primes found and elapsed time
    printf("Found %d primes in %f seconds\n", count, elapsed_time);
    return 0;
}
