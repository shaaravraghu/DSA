// Linear Search
for (int i = 0; i < n; i++){
  if (arr[i] == target) return i;
}
return -1;

// Binary Search (requires sorted array)
int low = 0;
int high = n - 1;
while (low <= high){
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    if (target < arr[mid])
        high = mid - 1;
    else
        low = mid + 1;
}
return -1;
