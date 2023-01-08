
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"
#include <time.h>

int main(int argc, char const *argv[])
{
    FILE *compare, *timeTaken;
    compare = fopen("SizeVsNumberOfComparisions.txt", "w");
    timeTaken = fopen("SizeVsExecutionTime.txt", "w");

    if(compare == NULL || timeTaken == NULL) {
        printf("Error!");
        exit(1);
    }

    int TEST_CASE = 0;
    scanf("%d", &TEST_CASE);

    for (int tc = 0; tc < TEST_CASE; tc++) {

        long long length = 0, number_of_comparisions = 0;
        scanf("%lld", &length);


        long long *array = malloc(length * size(long long));
        for (int i = 0; i < length; i++) {
            scanf("%lld", &array[i]);
        }

        clock_t start, end;
        start = clock();

        mergeSort(array, 0ll, length - 1ll, &number_of_comparisions);

        end = clock();
        double time_taken = (double)(end - start) / (double)(CLOCKS_PER_SEC);

        fprintf(compare, "%lld %lld\n", length, number_of_comparisions);
        fprintf(timeTaken, "%lld %lf\n", length, time_taken);

        printf("Finished iteration #%d\n", tc+1);
        free(array);
    }
    fclose(compare);
    fclose(timeTaken);

    return 0;
}
