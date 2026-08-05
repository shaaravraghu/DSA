// Linear Search
for (int i = 0; i < n; i++){
  if (arr[i] == target) return i;
}
return -1;

// Fibonacci Search (requires sorted array): instead of dividing by halves; divide by fibonacci numbers
int fibMMm2 = 0;   // (m-2)'th Fibonacci
int fibMMm1 = 1;   // (m-1)'th Fibonacci
int fibM = fibMMm2 + fibMMm1;
// Find the smallest Fibonacci number >= n
while (fibM < n){
    fibMMm2 = fibMMm1;
    fibMMm1 = fibM;
    fibM = fibMMm2 + fibMMm1;
}
int offset = -1;
while (fibM > 1){
    int i = min(offset + fibMMm2, n - 1);
    if (arr[i] < target){ // reverse fibonacci
        fibM = fibMMm1;
        fibMMm1 = fibMMm2;
        fibMMm2 = fibM - fibMMm1;
        offset = i;
    }
    else if (arr[i] > target){ // reduction of all 3 terms
        fibM = fibMMm2;
        fibMMm1 = fibMMm1 - fibMMm2;
        fibMMm2 = fibM - fibMMm1;
    }
    else {
        return i; // return for arr[i] == target
    }
}
if (fibMMm1 && offset + 1 < n && arr[offset + 1] == target) // if while loop fails
    return offset + 1;
return -1; // if not found

// Exponential Search (needs a sorted array)
if (arr[0] == target)
    return 0;
int i = 1;
while (i < n && arr[i] <= target)
    i *= 2;
int low = i / 2;
int high = min(i, n - 1);
// Binary Search implemented when exponential fails!
    if (target < arr[mid])
        high = mid - 1;
    else
        low = mid + 1;
} return -1;

// Interpolation Search (works best for uniformly distributed data (must be sorted))
int low = 0;
int high = n - 1;
while (low <= high && target >= arr[low] && target <= arr[high]){
    int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);
    if (arr[pos] == target)
        return pos;
    if (arr[pos] < target)
        low = pos + 1;
    else
        high = pos - 1;
} return -1;

// Binary Search (requires sorted array)
int low = 0;
int high = n - 1;
while (low <= high){
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] < target)
        low = mid + 1;
    else
        high = mid - 1;
} return -1;


// Jump Search (requires sorted array)
int step = sqrt(n);
int prev = 0;
while (prev < n && arr[min(step, n) - 1] < target){
    prev = step;
    step += sqrt(n);
    if (prev >= n) 
        return -1;
}
for (int i = prev; i < min(step, n); i++){
    if (arr[i] == target)
        return i;
} return -1;  


