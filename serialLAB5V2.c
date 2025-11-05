#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int hist[25] = {0};  
    int iteration, counter, i, step;

    printf("Enter the number of iterations: ");
    scanf("%d", &iteration);

    srand(time(NULL));

    clock_t start = clock();

  
    for (i = 0; i < iteration; i++) {
        counter = 0;
        for (step = 0; step < 12; step++) {
            int random_number = rand() % 101;
            if (random_number >= 49)
                counter++;
            else
                counter--;
        }
        hist[counter + 12]++; 
    }

    clock_t end = clock();
    double runtime = (double)(end - start) / CLOCKS_PER_SEC;

   
    printf("\nThe runtime is: %.4f seconds\n", runtime);
    printf("Histogram of results:\n");

    for (i = 0; i < 25; i++) {
        printf("%3d : %5d\n", i - 12, hist[i]);
    }

       int total = 0;
    for (i = 0; i < 25; i++) total += hist[i];
    printf("\nTotal samples processed: %d\n", total);

   
    printf("\nGraphical representation:\n");
    for (i = 0; i < 25; i++) {
        int count = hist[i] / (iteration / 100); 
        printf("%3d : ", i - 12);
        for (int j = 0; j < count; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}