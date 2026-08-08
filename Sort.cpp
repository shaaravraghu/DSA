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











// Heap Sort
HEAPSORT(A, n):

    // Build Max Heap
    for i = n/2 - 1 down to 0:
        HEAPIFY(A, n, i)

    // Extract maximum
    for i = n - 1 down to 1:
        swap(A[0], A[i])
        HEAPIFY(A, i, 0)


HEAPIFY(A, n, i):
    largest = i
    left  = 2*i + 1
    right = 2*i + 2

    if left < n AND A[left] > A[largest]:
        largest = left

    if right < n AND A[right] > A[largest]:
        largest = right

    if largest != i:
        swap(A[i], A[largest])
        HEAPIFY(A, n, largest)























// Insertion Sort
INSERTION_SORT(A, n):

    for i = 1 to n - 1:
        key = A[i]
        j = i - 1

        while j >= 0 AND A[j] > key:
            A[j + 1] = A[j]
            j--

        A[j + 1] = key
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
          
SELECTION_SORT(A, n):

    for i = 0 to n - 2:

        minIndex = i

        for j = i + 1 to n - 1:
            if A[j] < A[minIndex]:
                minIndex = j

        swap(A[i], A[minIndex])














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
















// Counting Sort
COUNTING_SORT(A, n):

    maxVal = maximum(A)
    minVal = minimum(A)

    range = maxVal - minVal + 1

    count = new array[range] initialized to 0

    for i = 0 to n - 1:
        count[A[i] - minVal]++

    k = 0

    for value = 0 to range - 1:
        while count[value] > 0:
            A[k++] = value + minVal
            count[value]--











// Bucket Sort
BUCKET_SORT(A, n):

    buckets = new array[n]
    
    for i = 0 to n - 1:
        buckets[i] = empty array

    for i = 0 to n - 1:
        index = floor(n * A[i])
        buckets[index].append(A[i])

    k = 0

    for i = 0 to n - 1:
        INSERTION_SORT(buckets[i])

        for x in buckets[i]:
            A[k++] = x





















RADIX_SORT(A, n):

    maxVal = maximum(A)

    exp = 1

    while maxVal / exp > 0:

        COUNTING_SORT_DIGIT(A, n, exp)

        exp *= 10

COUNTING_SORT_DIGIT(A, n, exp):

    output = new array[n]
    count = new array[10] initialized to 0

    // Count digit
    for i = 0 to n - 1:
        digit = (A[i] / exp) % 10
        count[digit]++

    // Prefix sum
    for i = 1 to 9:
        count[i] += count[i - 1]

    // Stable placement
    for i = n - 1 down to 0:
        digit = (A[i] / exp) % 10

        output[count[digit] - 1] = A[i]
        count[digit]--

    // Copy back
    for i = 0 to n - 1:
        A[i] = output[i]
