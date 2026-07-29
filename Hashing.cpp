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

// Subarray sum equals K
unordered_map<int, int> mp;
mp[0] = 1;
int sum = 0, ans = 0;
for (int x : nums) {
sum += x;
ans += mp[sum - k];
mp[sum]++;
} return ans;

// Need Subarray with equal number of 0's (-1) and 1's (+1): SUM=0
unordered_map<int,int> mp;
mp[0] = -1;
int sum = 0, ans = 0;
for(int i=0;i<nums.size();i++){
    sum += nums[i] ? 1 : -1;
    if(mp.count(sum))
        ans = max(ans, i - mp[sum]);
    else
        mp[sum] = i;
}
return ans;

// Longest Subarray with sum = k
unordered_map<int,int> mp;
int sum = 0, ans = 0;
for(int i=0;i<nums.size();i++){
    sum += nums[i];
    if(sum == k)
        ans = i + 1;
    if(mp.count(sum-k))
        ans = max(ans, i - mp[sum-k]);
    if(!mp.count(sum))
        mp[sum] = i;
}
return ans;
