#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int Array[100];
    int max = 0;
    int min = 100000;
    int sum = 0;
    int avg;

    #pragma omp parallel for reduction(max:max) reduction(min:min) reduction(+:sum) num_threads(100)
   {
        int i=omp_get_thread_num();
        Array[i] = rand() % 10000;
        if (Array[i] > max) {
            max = Array[i];
        }
        if (Array[i] < min) {
            min = Array[i];
        }
        sum += Array[i];
    }

    avg = sum / 100;

    printf("Valor máximo: %d\n", max);
    printf("Valor mínimo: %d\n", min);
    printf("Promedio: %d\n", avg);

    return 0;
}
