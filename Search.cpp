// Linear Search
for (int i = 0; i < n; i++){
  if (arr[i] == target) return i;
}
return -1;

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
