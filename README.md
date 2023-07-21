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
