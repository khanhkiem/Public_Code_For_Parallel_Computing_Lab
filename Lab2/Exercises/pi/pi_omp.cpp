#include "pi.h"
#include "stdio.h"
#include "omp.h"

#define SIZE 100l

int num_threads = 8;

/* TODO */
/* Modify this function to implement a parallel version with openmp */
int compute(long int num_steps)
{
    double pi;

    double width = 2. / num_steps;
    pi = 0.;

    /* TODO */
    /* Modify this function to implement a parallel version with openmp */

    return (0);
}

int prepare(long int Count)
{
    int i, j, n = Count;

    return (0);
}

int cleanup(long int N)
{
    return (0);
}

int main(int argc, char *argv[])
{
    long int Count = SIZE;
    int Error;

    if (argc < 3)
    {
        std::cerr << "Invalid argument" << std::endl;
        std::cerr << "Usage: " << argv[0] << "N T" << std::endl;
        std::cerr << "       N = size" << std::endl;
        std::cerr << "       T = num threads" << std::endl;
        return 1;
    }

    Count = std::atol(argv[1]);
    num_threads = std::atoi(argv[2]);

    printf("Count: %ld\n", Count);
    printf("Num threads: %d\n", num_threads);

    std::cout << "counts:" << Count << std::endl;
    std::cout << "preparation starting" << std::endl;
    if ((Error = prepare(Count)) != 0)
        return Error;
    std::cout << "preparation done" << std::endl;
    unsigned long long start_ticks = my_getticks();
    Error = compute(Count);

    unsigned long long end_ticks = my_getticks();
    unsigned long long ticks = end_ticks - start_ticks;

    if (Error == 0)
        std::cout << "succeeded in ";
    else
        std::cout << "failed in ";
    std::cout << my_ticks_to_seconds(ticks) << " seconds." << std::endl;
    std::cout << "starting cleanup" << std::endl;
    return cleanup(Count);
}