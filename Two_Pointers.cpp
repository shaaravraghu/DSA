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

// Sliding Window (Variable Size): Finding longest/ shortest subarray with condition
int slow = 0;
for (int fast = 0; fast < n; fast++) { // extend window
    // Add nums[fast] to the window
    while (window is invalid) {
        // Remove nums[slow]
        slow++; // contract window
    }
    // Update answer
}

// Generic Template: Read-Write (Compaction)
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    if (keep(nums[fast])) {
        nums[slow] = nums[fast];
        slow++;
    }
}

// Generic Template: Sliding Window
int slow = 0;
for (int fast = 0; fast < n; fast++) {
    // Expand window
    while (window is invalid) {
        // Shrink window
        slow++;
    }
    // Process current valid window
}

// Type 3: Intervals
// Merge Intervals
sort(intervals.begin(), intervals.end());
vector<vector<int>> ans;
for (auto &cur : intervals) {
    if (ans.empty() || ans.back()[1] < cur[0]) // (1st condition) if empty -> just insert the first interval; (2nd condition) we check the last interval in ans (end time) and curr (start time): no merge condition
        ans.push_back(cur);
    else // merge condition
        ans.back()[1] = max(ans.back()[1], cur[1]);
}
return ans;

// Add Interval (Merged)
vector<vector<int>> ans; // intervals is the array of all previously sorted arrays; newInterval is the interval that needs to be added
int i = 0, n = intervals.size();
while (i < n && intervals[i][1] < newInterval[0]) // until end time of intervals are less than start time of new interval; just keep pushing the intervals
    ans.push_back(intervals[i++]); // increment i after interval is added to ans
while (i < n && intervals[i][0] <= newInterval[1]) { // intervals overlap // update newInterval to keep it clean; keep repeating until all conflicting intervals are merged
    newInterval[0] = min(newInterval[0], intervals[i][0]); // set min. of both (start time)
    newInterval[1] = max(newInterval[1], intervals[i][1]); // set max. of both (end time)
    i++;
}
ans.push_back(newInterval); // push latest interval (after conflicts have been merged)
while (i < n)
    ans.push_back(intervals[i++]); // just push the intervals after newInterval in (without conflicts)
return ans;

// Non-overlapping Intervals: Minimum intervals to remove so none overlap
sort(intervals.begin(), intervals.end(), // we're sorting by the end time
[](auto &a, auto &b) {
    return a[1] < b[1]; // place interval with smaller end time first
}); // this is part of the sort function
int end = intervals[0][1]; // the end time value of the (latest) interval we decided to keep
int remove = 0;
for (int i = 1; i < intervals.size(); i++) {
    if (intervals[i][0] < end) // remove intervals with start time less than end time of the latest kept interval // removing multiple smaller intervals doesn't have to be worried upon because we have sorted the array based on end time
        remove++;
    else
        end = intervals[i][1]; // update the value of the end time value of the (latest) interval we decided to keep
} return remove;

// Meeting rooms: can a person attend all meetings?
sort(intervals.begin(), intervals.end());
for (int i = 1; i < intervals.size(); i++)
    if (intervals[i][0] < intervals[i-1][1])
        return false;
return true;

// Minimum Meeting Rooms
sort(intervals.begin(), intervals.end());
priority_queue<int,
vector<int>,
greater<int>> pq;
for (auto &it : intervals) {
    if (!pq.empty() && pq.top() <= it[0])
        pq.pop();
    pq.push(it[1]);
}
return pq.size();
// algorithm
// Sort start times
// Use min-heap of ending times
// Remove meetings that ended
// Heap size = rooms occupied
// Maximum heap size = answer

// Interval Intersection: Converge two list of intervals
int i = 0, j = 0;
while (i < A.size() && j < B.size()) {
    int l = max(A[i][0], B[j][0]);
    int r = min(A[i][1], B[j][1]);
    if (l <= r)
        ans.push_back({l, r});
    if (A[i][1] < B[j][1])
        i++;
    else
        j++;
}

// general template
sort(intervals.begin(), intervals.end());
vector<vector<int>> ans;
for (auto &cur : intervals) {
    if (ans.empty() || ans.back()[1] < cur[0]) {
        ans.push_back(cur);
    } else {
        ans.back()[1] = max(ans.back()[1], cur[1]);
    }
}

// Type 3: 3 Pointer
// Dutch National Flag: Sort 0's, 1's, 2's
// 0s       1s      Unknown     2s
// |--------|-------|-----------|------|
// 0      l-1     m-1           h    n-1
//          l       m
// Here we do swap along m because values smaller than m get swapped to the left of it and values greater than it get swapped right
int l = 0, m = 0, h = a.size() - 1; // Here we increment l & m and decrement h; m also acts as the pointer moving to the array (gets incremented in all steps)
while (m <= h) { // loop keeps running until m & h coincide
    if (a[m] == 0) 
        swap(a[l++], a[m++]); // we provide the number 'm' fetches to 'l'; l's post increment for the next swap
    else if (a[m] == 1)
        m++; // number remains and next index is checked
    else // refers to a[m] == 2
        swap(a[m], a[h--]); // we provide the number 'm' fetches to 'h'; h's post decrement for the next swap
}

// 3Sum: Triplets with target = 0
vector<vector<int>> ans;
sort(a.begin(), a.end()); // sorting the array
for (int i = 0; i < a.size(); i++) { // checks for all possible values of i
    if (i && a[i] == a[i - 1]) continue;
    int l = i + 1, r = a.size() - 1; // defining 'l': left and 'r': right; 
    while (l < r) { // increment 'l' and decrement 'r' until they try to coincide
        int sum = a[i] + a[l] + a[r]; // noting value at each interval
        if (sum == 0) {
            ans.push_back({a[i], a[l], a[r]});
            l++;
            r--;
            while (l < r && a[l] == a[l - 1]) l++; // avoid repetitions in ans by avoiding duplicates
            while (l < r && a[r] == a[r + 1]) r--; // avoid repetitions in ans by avoiding duplicates
        }
        else if (sum < 0)
            l++; // increasing value of sum
        else
            r--; // decreasing value of sum
    }
}
return ans;

// 3Sum: Closest value to target
sort(a.begin(), a.end()); // sorting allows to use the pointer technique
int ans = a[0] + a[1] + a[2]; // initial known value for comparison
for (int i = 0; i < a.size() - 2; i++) { // counter to check all variables
    int l = i + 1, r = a.size() - 1; // initialising 'l' from start and 'r' from end
    while (l < r) { // 'l' & 'r' to not coincide
        int sum = a[i] + a[l] + a[r]; // notes current value
        if (abs(target - sum) < abs(target - ans)) // smaller difference chosen
            ans = sum;
        if (sum < target)
            l++; // increase value to get closer to target
        else
            r--; // decrease value to get closer to target
    }
}
return ans;

// 4Sum: k-Sum to target
// For 2Sum (sorted): Use two pointers (l, r).
// For 3Sum: Fix one number (i). Solve 2Sum on the remaining array.
// For 4Sum: Fix two numbers (i, j). Solve 2Sum on the remaining array.
// For k-sum: fix (k-2) numbers. Solve 2Sum on the remaining array.
sort(a.begin(), a.end()); // to apply 2-sum
for (int i = 0; i < n - 3; i++) { // index extends to 4th number from last
    if (i && a[i] == a[i - 1]) continue; // keep incrementing until duplicate elements are surpassed
    for (int j = i + 1; j < n - 2; j++) { // index extends to 3rd number from last and starts from 1 position post i
        if (j > i + 1 && a[j] == a[j - 1]) continue; // keep incrementing until duplicate elements are surpassed
        int l = j + 1, r = n - 1; // set-up 2-sum by defining l (1 position past j) & r
        while (l < r) {
            long long sum = 1LL * a[i] + a[j] + a[l] + a[r]; // 1LL is 1 in long long form
            if (sum == target) {
                // answer array append
                l++; // keep incrementing till all possibilities are done
                r--; // keep decrementing till all possibilities are done
                while (l < r && a[l] == a[l - 1]) l++; // keep incrementing until duplicate elements are surpassed and ensure l & r do not coincide
                while (l < r && a[r] == a[r + 1]) r--; // keep decrementing until duplicate elements are surpassed and ensure l & r do not coincide
            }
            else if (sum < target)
                l++; // keep incrementing till target is reached
            else
                r--; // keep decrementing till target is reached
        }
    }
}

// Quicksort: Lomotu's Partition
int partition(vector<int>& a, int l, int r)
{
    int pivot = a[r]; // take pivot as last element or pre-defined value
    int i = l;
    for (int j = l; j < r; j++) // keep swapping until all elements less than pivot are moved towards the left
    {
        if (a[j] <= pivot)
            swap(a[i++], a[j]);
    }
    swap(a[i], a[r]); // once the loop above ends (j < r: j doesn't coincide with pivot)
    return i; // returns pivot position
}

// Quicksort: Hoare's Partition
// Core idea: Two pointers move towards each other:
// i moves left → right looking for an element that doesn't belong on the left (i.e., >= pivot).
// j moves right → left looking for an element that doesn't belong on the right (i.e., <= pivot).
// When both stop, swap them.
int partition(vector<int>& a, int l, int r)
{
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    while (true)
    {
        do i++; while (a[i] < pivot);
        do j--; while (a[j] > pivot);
        if (i >= j) // initially | correct |i| unknown |j| correct | -> | correct |j| correct |i| correct |
            return j; // returns partition boundary
        swap(a[i], a[j]);
    }
}

// Wiggle sort
// Input: 3 5 2 1 6 4; Sorted: 1 2 3 4 5 6; Wiggle: 3 (<) 5 (>) 1 (<) 6 (>) 2 (<) 4;
// The wiggle array is not sorted, but every adjacent pair satisfies the required alternating relationship.
for (int i = 1; i < n; i++)
{
    if ((i & 1 && a[i] < a[i - 1]) || // must follow odd case properly (a[i] < a[i - 1])
        (!(i & 1) && a[i] > a[i - 1])) // must follow even case properly (a[i] > a[i - 1])
        swap(a[i], a[i - 1]);
}
