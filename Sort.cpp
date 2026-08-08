// Quick Sort
QUICKSORT(A, n):
    stack = new array
    top = -1

    stack[++top] = 0
    stack[++top] = n - 1

    while top >= 0:
        high = stack[top--]
        low  = stack[top--]

        p = PARTITION(A, low, high)

        if low < p - 1:
            stack[++top] = low
            stack[++top] = p - 1

        if p + 1 < high:
            stack[++top] = p + 1
            stack[++top] = high


PARTITION(A, low, high):
    pivot = A[high]
    i = low - 1

    for j = low to high - 1:
        if A[j] <= pivot:
            i++
            swap(A[i], A[j])

    swap(A[i + 1], A[high])
    return i + 1
















// Bubble Sort
BUBBLE_SORT(A, n):

    for i = 0 to n - 2:
        swapped = false

        for j = 0 to n - i - 2:

            if A[j] > A[j + 1]:
                swap(A[j], A[j + 1])
                swapped = true

        if swapped == false:
            break
