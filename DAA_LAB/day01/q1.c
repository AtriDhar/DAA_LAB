#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter the size of the array (n): ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Array must contain at least 2 elements to find second smallest and second largest.\n");
        return 1;
    }
    int arr[n];
    printf("Enter %d integer elements for the array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Array elements entered: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int smallest = -1;
    int SSmallest = arr[0];
    int largest = 0;
    int SLargest = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            SSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < SSmallest && arr[i] != smallest) {
            SSmallest = arr[i];
        }
        if (arr[i] > largest) {
            SLargest = largest;
            largest = arr[i]; 
        } else if (arr[i] > SLargest && arr[i] != largest) {

            SLargest = arr[i];
        }
    }



    if (SSmallest == INT_MAX) {
        printf("Second Smallest: Not found (All elements might be identical or n < 2 after duplicates removed).\n");
    } else {
        printf("Second Smallest: %d\n", SSmallest);
    }

    if (SLargest == INT_MIN) {
        printf("Second Largest: Not found (All elements might be identical or n < 2 after duplicates removed).\n");
    } else {
        printf("Second Largest: %d\n", SLargest);
    }

    return 0; // Indicate successful execution
}