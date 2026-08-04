// Select answer (mid+1, mid or mid-1) based on Target definition

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

// Lower Bound: First Element >= Target
int l = 0, r = a.size(); // this defines the solution to belong in [l, r) 
while (l < r) { // when r-l = 0, the search is over; it doesn't define the solution [[l, r) -> [l, l) -> NULL]
    int mid = l + (r - l) / 2;
    if (a[mid] < target)
        l = mid + 1; // mid+1 because a[mid] < target
    else // a[mid] >= target
        r = mid; // mid because a[mid] = target is a possiblity
} return l; // or return 'r' because l == r

// Upper Bound: First Element > Target
int l = 0, r = a.size();
while (l < r) {
    int mid = l + (r - l) / 2;
    if (a[mid] <= target)
        l = mid + 1;
    else
        r = mid;
} return l;   // or return r;

// First Occurrence
int l = 0, r = a.size() - 1;
int ans = -1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (a[mid] == target) {
        ans = mid;
        r = mid - 1;
    }
    else if (a[mid] < target)
        l = mid + 1;
    else
        r = mid - 1;
} return ans;

// Binary Search on Answer (Minimum Yield)
// after a particular value the if condition becomes TRUE; we have to find that index (FFFFFFFFFF(T)TTTTTT)
while (low < high) {
    int mid = low + (high - low) / 2;
    if (check(mid))
        high = mid;
    else
        low = mid + 1;
} return low;
