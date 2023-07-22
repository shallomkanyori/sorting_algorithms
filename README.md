## C - Sorting algorithms & Big O

#### Task 0: Bubble sort
[0-bubble_sort.c](0-bubble_sort.c) implements a function that sorts an array of integers in ascending order using the Bubble sort algorithm
- Prototype: `void bubble_sort(int *array, size_t size);`
- Prints the `array` after each time two elements are swapped

[`0-O`](0-O) contains the big O notations of the time complexity of the Bubble sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case

#### Task 1: Insertion sort
[1-insertion_sort.c](1-insert_sort.c) implements a function that sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm
- Prototype: `void insertion_sort_list(listint_t **list);`
- The integer `n` of a node is not modified. The nodes themselves are swapped
- Prints the `list` after each time two element are swapped

[`1-O`](1-O) contains the big O notations of the time complexity of the Insertion sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case

#### Task 2: Selection sort
[2-selection_sort.c](2-selection_sort.c) implements a function that sorts an array of integers in ascending order using the Selection sort algorithm
- Prototype: `void selection_sort(int *array, size_t size);`
- Prints the `array` after each time two elements are swapped

[2-O](2-O) contains the big O notations of the time complexity of the Selection sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case

#### Task 3: Quick sort
[3-quick_sort.c](3-quick_sort.c) implements a function that sorts an array of integers in ascending order using the Quick sort algorithm
- Prototype: `void quick_sort(int *array, size_t size);`
- Implements the Lomuto partition scheme; The pivot is always the last element of the partition being sorted.
- Prints the `array` after each time two elements are swapped

[3-O](3-O) contains the big O notations of the time complexity of the Quick sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case


#### Task 4: Shell sort - Knuth sequence
[100-shell_sort.c](100-shell_sort.c) implements a function that sorts an array of integers in ascending order using the Shell sort algorithm, using the Knuth sequence
- Prototype: `void shell_sort(int *array, size_t size);`
- Uses the following sequence of intervals (a.k.a the Knuth sequence):
	- `n+1 = n * 3 + 1`
	- `1, 4, 13, 40, 121, ...`
- Prints the `array` each time the interval is decreased

#### Task 5: Cocktail shaker sort
[101-cocktail_sort.c](101-cocktail_sort.c) implements a function that sorts a doubly linked list of integers in ascending order using the Cocktail shaker sort algorithm
- Prototype: `void cocktail_sort_list(listint_t **list);`
- The integer `n` of a node is not modified. The nodes themseves are swapped
- Prints the `list` after each time two elements are swapped

[101-O](101-O) contains the big O notations of the time complexity of the Cocktail shaker sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case

#### Task 6: Counting sort
[102-counting_sort.c](102-counting_sort.c) implements a function that sorts an array of integers in ascending order using the Counting sort algorithm
- Prototype: `void counting_sort(int *array, size_t size);`
- Assumes that `array` will contain only numbers `>= 0`
- Prints the counting array once it is set up
	- This array is of size `k + 1` where `k` is the largest number in `array`

[102-O](102-O) contains the big O notations of the time complexity of the Counting sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case

#### Task 7: Merge sort
[103-merge_sort.c](103-merge_sort.c) implements a function that sorts an array of integers in ascending order using the Merge sort algorithm
- Prototype: `void merge_sort(int *array, size_t size);`
- Implements the top-down merge sort algorithm
	- When dividing an array into two sub-arrays, the size of the left array is always <= the size of the right array. i.e. `{1, 2, 3, 4, 5}` -> `{1, 2}, {3, 4, 5}`
	- The left array is sorted before the right array

[103-O](103-O) contains the big O notations of the time complexity of the Merge sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case

#### Task 8: Heap sort
[1040-heap_sort.c](104-heap_sort.c) implements a function that sorts an array of integers in ascending order using the Heap sort algorithm
- Prototype: `void heap_sort(int *array, size_t size);`
- Implements the sift-down heap sort algorithm
- Prints the `array` after each time two elements are swapped

[104-O](104-O) contains the big O notations of the time complexity of the Heap sort algorithm, with 1 notation per line:
- in the best case
- in the average case
- in the worst case

#### Task 9: Radix sort
[105-radix_sort.c](105-radix_sort.c) implements a function that sorts an array of integers in ascending order using the Radix sort algorithm
- Prototype: `void radix_sort(int *array, size_t size);`
- Implements the `LSD` radix sort algorithm
- Assumes that array will contain only numbers `>= 0`
- Prints the `array` each time the significant digit is increased
