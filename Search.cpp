// Linear Search
for (int i = 0; i < n; i++){
  if (arr[i] == target) return i;
}
return -1;

// Ternary Search (requires sorted array)
int low = 0;
int high = n - 1;
while (low <= high){
    int mid1 = low + (high - low) / 3; // (+2/3) low + (-1/3) high
    int mid2 = high - (high - low) / 3; // (+2/3) high + (+1/3) low
    if (arr[mid1] == target)
        return mid1;
    if (arr[mid2] == target)
        return mid2;
    if (target < arr[mid1]){
        high = mid1 - 1;
    }
    else if (target > arr[mid2]){
        low = mid2 + 1;
    }
    else {
        low = mid1 + 1;
        high = mid2 - 1;
    }
} return -1;
