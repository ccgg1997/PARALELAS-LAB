#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int max = 0;
    int min = 100000;
    int sum = 0;
    int avg;
    int num_hilos = 10;
    
    srand(time(NULL));

    #pragma omp parallel num_threads(num_hilos) reduction(max:max) reduction(min:min) reduction(+:sum)
    {
        int random_num;
        
        #pragma omp critical
        {
            random_num = rand() % 10000;
        }

        if (random_num > max) {
            max = random_num;
        }
        if (random_num < min) {
            min = random_num;
        }
        sum += random_num;
    }

    avg = sum / num_hilos;

    printf("Valor máximo: %d\n", max);
    printf("Valor mínimo: %d\n", min);
    printf("Promedio: %d\n", avg);

    return 0;
}
