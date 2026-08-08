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
















// Merge Sort
MERGESORT(A, n):
    size = 1

    while size < n:
        left = 0

        while left < n:
            mid = min(left + size, n)
            right = min(left + 2*size, n)

            MERGE(A, left, mid, right)

            left += 2 * size

        size *= 2


MERGE(A, left, mid, right):
    temp = new array[right - left]

    i = left
    j = mid
    k = 0

    while i < mid AND j < right:
        if A[i] <= A[j]:
            temp[k++] = A[i++]
        else:
            temp[k++] = A[j++]

    while i < mid:
        temp[k++] = A[i++]

    while j < right:
        temp[k++] = A[j++]

    for i = 0 to length(temp)-1:
        A[left + i] = temp[i]
