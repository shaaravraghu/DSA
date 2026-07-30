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
