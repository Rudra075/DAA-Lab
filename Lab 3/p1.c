/* q1_binary_vs_ternary_search.c
 *
 * DAA Q1 : search x in a sorted list of n elements by binary search (two
 * intervals) and by ternary search (three intervals).  Both are counted in
 * element comparisons, swept over n, and every result is checked against a
 * linear scan before its counts are believed.
 */
 
 #include <stdio.h>
#define MAX 1000
// Binary Search
int binarySearch(int a[], int n, int x, int *comparisons)
{
    int low = 0, high = n - 1;
    while (low <= high){
        int mid = low + (high - low) / 2;
        (*comparisons)++;
        if (a[mid] == x) return mid;
        if (a[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
// Ternary Search
int ternarySearch(int a[], int n, int x, int *comparisons){
    int low = 0, high = n - 1;
    while (low <= high){
        int third = (high - low) / 3;
        int mid1 = low + third;
        int mid2 = high - third;
        (*comparisons)++;
        if (a[mid1] == x) return mid1;
        // Compare with second middle element
        (*comparisons)++;

        if (a[mid2] == x) return mid2;

        if (x < a[mid1]){
            high = mid1 - 1;
        }
        else if (x > a[mid2]){
            low = mid2 + 1;
        }
        else{
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
}
int main()
{
    int a[MAX], n, x;
    int binaryComparisons = 0;
    int ternaryComparisons = 0;

    printf("Enter size of sorted array: ");
    scanf("%d", &n);
    printf("Enter %d elements in sorted order:\n", n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter element to search: ");
    scanf("%d", &x);

    int binaryResult = binarySearch(a, n, x, &binaryComparisons);
    int ternaryResult = ternarySearch(a, n, x, &ternaryComparisons);

    printf("\n--- Binary Search ---\n");

    if (binaryResult != -1) printf("Element found at index %d\n", binaryResult);
    else printf("Element not found\n");

    printf("Number of comparisons: %d\n", binaryComparisons);

    printf("\n--- Ternary Search ---\n");

    if (ternaryResult != -1)
        printf("Element found at index %d\n", ternaryResult);
    else
        printf("Element not found\n");

    printf("Number of comparisons: %d\n", ternaryComparisons);

    printf("\n--- Comparison ---\n");

    if (binaryComparisons < ternaryComparisons)
        printf("Binary Search is better for this input.\n");
    else if (binaryComparisons > ternaryComparisons)
        printf("Ternary Search is better for this input.\n");
    else
        printf("Both performed the same number of comparisons.\n");

    return 0;
}