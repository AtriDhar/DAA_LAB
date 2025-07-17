#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the size of the array (N): ");
    scanf("%d", &N);
    if (N <= 0) {
        printf("Array size must be positive.\n");
        return 1;
    }
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Enter %d elements for the array:\n", N);
    for (int i = 0; i < N; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int *prefixSum = (int *)malloc(N * sizeof(int));
    if (prefixSum == NULL) {
        printf("Memory allocation failed!\n");
        free(arr);
        return 1;
    }
    prefixSum[0] = arr[0];
    for (int i = 1; i < N; i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
    printf("\nInput Array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Output Array (Prefix Sum): ");
    for (int i = 0; i < N; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");
    free(arr);
    free(prefixSum);

    return 0;
}