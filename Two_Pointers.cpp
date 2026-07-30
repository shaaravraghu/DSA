// A two-pointer algorithm (O(n)) uses two indices that move through an array or string to solve a problem more efficiently than nested loops (O(n^2)).
// Fundamental Rule: Every time a pointer moves, one possibility is permanently eliminated.

// Type 1: Opposite Ends
Pointers start at opposite ends.

// Palindrome
int l = 0, r = s.size() - 1;
while (l < r) {
    if (s[l] != s[r]) return false;
    l++;
    r--;
}
return true;

// Pair Sum (Sorted Array): return true if two numbers add up to a target
int l = 0, r = a.size() - 1;
while (l < r) {
    int sum = a[l] + a[r];
    if (sum == target) return true;
    else if (sum < target) l++;
    else r--;
}
return false;

// Reverse An Array/ String
void reverse(vector<int>& a) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
        swap(a[l], a[r]);
        l++;
        r--;
    }
}
