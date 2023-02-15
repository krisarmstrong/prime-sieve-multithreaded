# Multithreaded Prime Sieve
This is a C program that uses the Sieve of Eratosthenes algorithm to find prime numbers among 100 million integers, with multi-threading support for faster execution. The program is platform-independent and can be compiled and executed on most operating systems.

## Requirements
To compile and run this program, you need to have the following installed:

A C compiler (such as gcc or clang)
The pthreads library (should be available on most systems)
Building the Program
To build the program, simply run the following command:


gcc -pthread -o prime_sieve prime_sieve.c
This will compile the program and generate an executable file called prime_sieve.

## Running the Program
To run the program, simply execute the prime_sieve file generated in the previous step. The program will generate 100 million integers and then find all prime numbers among them using the Sieve of Eratosthenes algorithm. The program will output the number of primes found and the elapsed time.

## Program Options
The program currently does not have any options or command-line arguments. However, you can modify the NUM_THREADS constant in the program to change the number of threads used for multi-threading.

## License
This program is released under the Apache 2 License. See the LICENSE file for more information.
