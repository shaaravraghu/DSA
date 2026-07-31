// A two-pointer algorithm (O(n)) uses two indices that move through an array or string to solve a problem more efficiently than nested loops (O(n^2)).
// Fundamental Rule: Every time a pointer moves, one possibility is permanently eliminated.

// Type 1: Opposite Ends
// Pointers start at opposite ends.

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

// The Container with Most Water: This problem deals with choosing indices that maximise the amount of water; that is the (difference of the indices) X (min. of height of both the walls) because water will spill of the shorter wall
int l = 0, r = h.size() - 1;
int ans = 0;
while (l < r) {
    ans = max(ans, min(h[l], h[r]) * (r - l));
    if (h[l] < h[r]) l++;
    else r--;
} return ans;


// Type 2: Same Direction (Fast & Slow; Sliding Window)
// Both the pointers move in the same direction

// Remove Duplicates (Sorted Array): Fast & Slow
if (nums.empty()) return 0;
int slow = 0; // slow points to last unique element; scan looking for new values
for (int fast = 1; fast < nums.size(); fast++) {
    if (nums[fast] != nums[slow]) { // doesn't care about duplicates, searches for the next unique number
        slow++; // increments slow to hold position for unique number
        nums[slow] = nums[fast]; // instead of clearing number and leaving a blank at duplicate positions, nums[fast] is copied to position where duplicate exists. 
    }
}
return slow + 1; // returns number of unique elements

// Move Zeroes: Shift the zeroes to the end of the array (keeping the rest of the order intact)
int slow = 0;
for (int fast = 0; fast < nums.size(); fast++) {
    if (nums[fast] != 0) { // fast pulls slow forward every time it encounters a non-zero number; when fast encounters a zero, it moves forward leaving slow at the latest zero
        swap(nums[slow], nums[fast]); // when the first non-zero number is encountered, it swaps with zero (slow)
        slow++;
    }
}

// Remove Specific Element: Remove all occurrences of a given value
int slow = 0;
for (int fast = 0; fast < nums.size(); fast++) {
    if (nums[fast] != val) { // until value is encountered keep moving fast value to slow value and keep incrementing slow
        nums[slow] = nums[fast];
        slow++;
    }
} return slow;

// Merge Two Sorted Arrays
vector<int> ans;
int i = 0, j = 0;
while (i < a.size() && j < b.size()) {
    if (a[i] <= b[j])
        ans.push_back(a[i++]);
    else
        ans.push_back(b[j++]);
}
while (i < a.size()) ans.push_back(a[i++]); // continuation if any one of the conditions terminate the above while loop
while (j < b.size()) ans.push_back(b[j++]); // still keeps it sorted
return ans;

// Sliding Window (Fixed Size): Finding max/ min of every subarray of size k
int sum = 0, max_ans = INT_MIN, min_ans = INT_MAX;
int slow = 0;
for (int fast = 0; fast < nums.size(); fast++) { // increments window size to move forward
    sum += nums[fast]; // adds element while incrementing window
    if (fast - slow + 1 == k) { // ensure subarray is of size k
        max_ans = max(max_ans, sum); // returns maximum of subarray
        min_ans = min(min_ans, sum); // returns minimum of subarray
        sum -= nums[slow]; // removes element while decrementing window
        slow++; // decrements window size while moving forward
    }
} return ans;








