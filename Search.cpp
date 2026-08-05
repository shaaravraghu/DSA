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
