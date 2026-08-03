// Sorted Array: Find Target
// bisects search area by half every time it progresses; returns index of target
int l = 0, r = a.size() - 1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (a[mid] == target)
        return mid;
    else if (a[mid] < target)
        l = mid + 1;
    else
        r = mid - 1;
} return -1;

// Lower Bound: First Element < Target
int l = 0, r = a.size(); // this defines the solution to belong in [l, r) and when r-l = 1 we have only possible solution as l
while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] < target)
        l = mid + 1; // mid+1 because a[mid] < target
    else // a[mid] >= target
        r = mid; // mid because a[mid] = target is a possiblity
} return l; 
