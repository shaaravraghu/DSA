// Hashing is a technique to store and retrieve data in O(1) time. The need for hashing comes from searching in an array linearly in O(n) time. Hash function is like a library search (search where it should be).

#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

// STL Contianers:
// set (ordered) - O(log n)
// unordered_set - O(1)
// map (ordered) - O(log n)
// unordered_map - O(1)

// set
set<int> st;
st.insert(5);
st.insert(2);
st.insert(3);
st.insert(5);
st[3]; // error
// Memory: 2 3 5
// stores key values only, ordered/ sorted, NO index, NO frequency, NO duplicate

// unordered_set
unordered_set<int> ust;
st.insert(5);
st.insert(2);
st.insert(3);
st.insert(5);
// Memory: 5 2 3 (random)
// stores key values only, NOT ordered/ sorted, NO index, NO frequency, NO duplicate

// map
map<string, int> marks;
marks["Name1"] = 92;
marks["Name2"] = 87;
// stores key value pairs, NO index, sorted, NO duplicate keys, duplicate values possible (updates to latest value)

// unordered_map 
unordered_map<string, int> marks;
marks["Name1"] = 92;
marks["Name2"] = 87;
// pre-defined functions
mp.insert({key, value});
mp.find(key); if (mp.find(5) != mp.end()) {}
mp.count(key);  if (mp.count(5)) {}
mp.erase(key);
mp.clear();
mp.size();
mp.empty(); // size check
mp.begin();
mp.end();
// iteration elements
for (auto p : mp) cout << p.first << " " << p.second;
// stores key value pairs, NO index, NOT sorted, NO duplicate keys, duplicate values possible (updates to latest value)

// frequency problems are stored as KEY-FREQ PAIRS
// counting frequency in array
unordered_map<int,int> freq;
for(int x : arr)
    freq[x]++;

// EXISTENCE CHECKING

// Checking for Duplicates
unordered_set<int> st;
for (int x: arr){
    if (st.count(x)) return true;
    st.insert(x);
} return false;

// Number of Distinct Elements
unordered_set<int> st(arr.begin(), arr.end());
return st.size();

// Remove Duplicates
unordered_set<int> st(arr.begin(), arr.end());
vector<int> nums(st.begin(), st.end());

// Checking Missing Element
unordered_set<int> st(arr1.begin(), arr1.end());
for (int x: arr2){
    if (!st.count(x)) {cout<<x; counter++;}
}

// FREQUENCY COUNTING

// finding frequency of each element
unordered_map<int, int> freq;
for(int x : arr) freq[x]++;

// finding majority element (more than 50%)
unordered_map<int, int> freq;
for (int x : arr){
    freq[x]++;
    if (freq[x] > arr.size()/2) return x;
}

// first unique character in a string
unordered_map<int, int> freq;
for(int x : arr) freq[x]++;
for (int i=0; i<s.size(); i++){
    if (freq[s[i]] == 1) return s[i];
}

// verifying anagram
if (s.size() != t.size()) return false;
unordered_map<int, int> f1, f2;
for (int i : s) f1[i]++;
for (int i : t) f2[i]++;
for (int i : s) if (f1[i] != f2[i]) return false;
return true;

// top K frequent elements
// convert frequency to min. heap
// (OR) frequency + sort
unordered_map<char, int> freq;
for (char c : s) freq[c]++;
vector<pair<int, char>> v;
for (auto p : freq) v.push_back({p.second, p.first});
sort(v.rbegin(), v.rend());

// sort characters by frequency
// convert frequency to min. heap
// (OR) frequency + sort
unordered_map<char, int> freq;
for (char c : s) freq[c]++;
vector<pair<int, char>> v;
for (auto p : freq) v.push_back({p.second, p.first});
sort(v.rbegin(), v.rend());

// HASHMAPS + ARRAYS PATTERN
// Two Sum: a + b = target
unordered_map<int, int> mp; // nums is copied onto mp (only keys)
for (int x: nums){
    complement = target - x;
    if (mp.count(complement){ // no need to check nums
        mp[complement]=x;
    }
}

// Longest Consecutive Sequence
unordered_set<int> st(nums.begin(), nums.end());
int longest = 0;
for (int num : st) {
    // Start only if num is the beginning of a sequence
    if (!st.count(num - 1)) {
        int curr = num;
        int len = 1;
        while (st.count(curr + 1)) { // Checks 
            curr++;
            len++;
        }
        longest = max(longest, len);
    }
}
return longest;

// Missing Number: Sum Method
int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int expected = n * (n + 1) / 2;
    int actual = accumulate(nums.begin(), nums.end(), 0);
    return expected - actual;
}

// Missing Number: XOR Logic
int missingNumber(vector<int>& nums) {
    int ans = nums.size();
    for (int i = 0; i < nums.size(); i++)
        ans ^= i ^ nums[i];
    return ans;
}

// Continuous Subarray Sum Divisible By K
unordered_map<int, int> mp;
mp[0] = -1;  // Handle subarrays starting at index 0
int sum = 0;
for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    int rem = sum % k;
    if (mp.count(rem)) {
        if (i - mp[rem] >= 2)
            return true;
    } else {
        mp[rem] = i;   // Store first occurrence only
    }
}
return false;

// Total Subarrays with sum equals K
unordered_map<int, int> mp;
mp[0] = 1; // indicates start and visited
int sum = 0, ans = 0; // current prefix sum and total number of subarrays
for (int x : nums) {
sum += x;
ans += mp[sum - k]; // current prefix sum (sum) - previous prefix sum = k; // If sum - k has appeared before, then every occurrence represents one valid subarray ending at the current index.
mp[sum]++; // store current prefix sum for future iterations
} return ans;

// Need Longest Subarray with equal number of 0's (-1) and 1's (+1): SUM=0
unordered_map<int,int> mp; // key: prefix sum | value: first index where this prefix sum occured
mp[0] = -1; // occurred before starting array
int sum = 0, ans = 0; // sum: longest prefix sum; ans: longest length found
for(int i=0;i<nums.size();i++){
    sum += nums[i] ? 1 : -1;
    if(mp.count(sum)) // Checks whether we've seen this prefix sum before
        ans = max(ans, i - mp[sum]); // If the same prefix sum has appeared before, then the sum between those two indices is 0.
    else
        mp[sum] = i; // appearing for first time -> store it
}
return ans;

// Longest Subarray with sum = k
unordered_map<int,int> mp;
int sum = 0, ans = 0;
for(int i=0;i<nums.size();i++){
    sum += nums[i];
    if(sum == k)
        ans = i + 1; // takes the length of longest subarray as it is
    if(mp.count(sum-k))
        ans = max(ans, i - mp[sum-k]); // if current prefix sum - previous prefix sum = k
    if(!mp.count(sum))
        mp[sum] = i; // if never encountered, store value
}
return ans;

// SLIDING WINDOW + HASHMAP
// Longest Substring without Repeating Characters
unordered_map<char,int> mp;
int l = 0, ans = 0; // r: right pointer; l: left pointer
for(int r = 0; r < s.size(); r++) {
    mp[s[r]]++; // addition of frequency when visited by right pointer
    while(mp[s[r]] > 1) // if frequency is more than 1 (duplicate exists) and keep moving left pointer until condition satisfied
        mp[s[l++]]--; // first decreases freq. then l+1; we are reducing the frequency because the sliding window has moved and removed the duplicate
    ans = max(ans, r - l + 1);
} return ans;

// Minimum Substring of s carrying all characters of t
unordered_map<char,int> mp;
for(char c : t) mp[c]++; // listing the frequencies of characters in t
int need = t.size(); // requirement for finding sub-array
int l = 0, start = 0, len = INT_MAX; // l: left pointer, r: right pointer, start: starting index of best answer, len: min. window
for(int r = 0; r < s.size(); r++) {
    if(mp[s[r]]-- > 0) need--; // if in s we encounter a character requirement of t, then we reduce the frequency to mark as counted and reduce need (as noted)
    while(need == 0) { // if need is complete
        if(r - l + 1 < len) { // if the current window size is smaller than the latest window size
            len = r - l + 1;
            start = l; // update len and start
        }
        if(++mp[s[l++]] > 0) need++; // meaning of map values: positive (still need these many), zero (need satisfied), negative (extra copies present); we try to minimise the window here as much as possible; if something crucial is removed, it's frequency is added back
    }
}
return len == INT_MAX ? "" : s.substr(start, len); // paste the result

// List all positions where anagrams of p are found in s (fixed size window)     
vector<int> ans;
unordered_map<char,int> mp; 
for(char c : p) mp[c]++; // listing characters and their frequencies
int need = p.size(); 
for(int l = 0, r = 0; r < s.size(); r++) { // keep moving until all characters are found (r increment)
    if(mp[s[r]]-- > 0) need--; // if required char found, reduce freq and need
    if(r - l + 1 > p.size()) { // if window is bigger than needed, move the left pointer
        if(++mp[s[l++]] > 0) need++; // placing the character back into the needed; it won't add unnecccessary characters in because the map is designed from 'p'
    }
    if(need == 0) // whenever the conditions are satisfied
        ans.push_back(l);
}
return ans;

// Return true if s1's permutation (any random rearrangement) is found in s2 (fixed window: exact same problem as above)
unordered_map<char,int> mp;
for(char c : s1) mp[c]++;
int need = s1.size();
for(int l = 0, r = 0; r < s2.size(); r++) {
    if(mp[s2[r]]-- > 0) need--;
    if(r - l + 1 > s1.size()) {
        if(++mp[s2[l++]] > 0) need++;
    }
    if(need == 0)
        return true;
}
return false;
