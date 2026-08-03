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

