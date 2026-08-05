// Linear Search
for (int i = 0; i < n; i++){
  if (arr[i] == target) return i;
}
return -1;

// Exponential Search (needs a sorted array)
if (arr[0] == target)
    return 0;
int i = 1;
while (i < n && arr[i] <= target)
    i *= 2;
int low = i / 2;
int high = min(i, n - 1);
// Binary Search implemented when exponential fails!
while (low <= high){
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] < target)
        low = mid + 1;
    else
        high = mid - 1;
} return -1;
