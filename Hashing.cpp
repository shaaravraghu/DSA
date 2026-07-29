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

// sort characters by frequency
// convert frequency to min. heap
// (OR) frequency + sort
