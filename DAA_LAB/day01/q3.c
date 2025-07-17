#include <stdio.h>

int main() {
    int n;
    
    printf("Enter how many numbers you want to read: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Read array elements from user
    printf("Enter %d numbers: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Display the array content
    printf("\nThe content of the array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Find duplicate elements and count them
    int duplicateCount = 0;
    int counted[n]; // Array to track which elements we've already counted
    for(int i = 0; i < n; i++) {
        counted[i] = 0; // Initialize as not counted
    }
    
    for(int i = 0; i < n; i++) {
        if(counted[i] == 0) { // If this element hasn't been counted yet
            int frequency = 1;
            
            // Count occurrences of arr[i] in the rest of the array
            for(int j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    frequency++;
                    counted[j] = 1; // Mark as counted
                }
            }
            
            // If frequency > 1, it's a duplicate
            if(frequency > 1) {
                duplicateCount++;
            }
        }
    }
    
    // Find the most repeating element
    int maxFrequency = 0;
    int mostRepeatingElement = arr[0];
    
    // Reset counted array
    for(int i = 0; i < n; i++) {
        counted[i] = 0;
    }
    
    for(int i = 0; i < n; i++) {
        if(counted[i] == 0) {
            int frequency = 1;
            
            // Count occurrences of arr[i]
            for(int j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    frequency++;
                    counted[j] = 1; // Mark as counted
                }
            }
            
            // Update most repeating element if this has higher frequency
            if(frequency > maxFrequency) {
                maxFrequency = frequency;
                mostRepeatingElement = arr[i];
            }
        }
    }
    
    // Display results
    printf("Total number of duplicate values = %d\n", duplicateCount);
    printf("The most repeating element in the array = %d\n", mostRepeatingElement);
    
    return 0;
}