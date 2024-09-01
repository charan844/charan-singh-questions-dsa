#include <stdio.h>


int findElement(int arr[], int n, int key);


int deleteElement(int arr[], int n, int key)
{

	int pos = findElement(arr, n, key);

	if (pos == -1) {
		printf("Element not found");
		return n;
	}

	int i;
	for (i = pos; i < n - 1; i++)
		arr[i] = arr[i + 1];

	return n - 1;
}

int findElement(int arr[], int n, int key)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == key)
			return i;

	return -1;
}


int main()
{
	int i;
	int arr[] = { 10, 50, 30, 40, 20 };

	int n = sizeof(arr) / sizeof(arr[0]);
	int key = 30;

	printf("Array before deletion\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);


	n = deleteElement(arr, n, key);

	printf("\nArray after deletion\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	return 0;
}
 18 changes: 18 additions & 0 deletions18  
arrayinsertion.c
Original file line number	Diff line number	Diff line change
@@ -0,0 +1,18 @@
#include <stdio.h>

int main() {
    int arr[100] = {10, 20, 30, 40, 50,60};  
    int size = 6;  
    int element = 70;  


    arr[size] = element;
    size++;  


    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
 28 changes: 28 additions & 0 deletions28  
arrayinsertion2
Original file line number	Diff line number	Diff line change
@@ -0,0 +1,28 @@


#include <stdio.h>

int main()
{
	int arr[100] = { 0 };
	int i, x, pos, n = 10;

    for (i = 0; i < 10; i++)
		arr[i] = i + 1;


	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
    x = 50;
    pos = 5;
    n++;
    for (i = n - 1; i >= pos; i--)
		    arr[i] = arr[i - 1];
    arr[pos - 1] = x;
    for (i = 0; i < n; i++)
		    printf("%d ", arr[i]);
	    printf("\n");

	    return 0;
}
 38 changes: 38 additions & 0 deletions38  
binarysearch.c
Original file line number	Diff line number	Diff line change
@@ -0,0 +1,38 @@
#include <stdio.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;


        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            low = mid + 1;


        else
            high = mid - 1;
    }


    return -1;
}

int main() {
    int arr[] = {20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 50;
    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
