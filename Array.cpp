Static:
int arr[5];

Dynamic:
vector<int> arr;

vector<int> a;
vector<int> b(10);
vector<int> c(3,5);
vector<int> d={1,2,5,8};

a[3];
a.front();
a.back();
a.size();
a.empty();
a.push_back(7);
a.pop_back();
a.clear;

for(int i=0; i<arr.size(); i++){}
for(int x:arr){}

sort(arr.begin(), arr.end());
reverse(arr.begin(), arr.end());

max_element(arr.begin(), arr.end());
min_element(arr.begin(), arr.end());
accumulate(arr.begin(), arr.end(), x);
count(arr.begin(), arr.end(), x);
find(arr.begin(), arr.end(), x);
binary_search(arr.begin(), arr.end(), x);

#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>

// LINEAR TRAVERSAL
for (int x:arr){}

// MAX/ MIN
for (int x:arr){
  val = (x > val) ? x: val;
  \\ OR
  val = max(val, x);
}

// CUMULATIVE
for (int i=0; i<arr.size(); i++){
  cum[i]=cum[i-1]+arr[i];
}

// CUMULATIVE MAX/ MIN
for (int i=0; i<arr.size(); i++){
  cum[i]= max(cum[i-1],arr[i]);
}

// FREQUENCY
for(int x:arr){
  freq[x]++;
}

// KADANE'S ALGORITHM (LARGEST CONTINUOUS SUB-ARRAY)
for(int i=0; i<arr.size(); i++){
  current_streak = max(current_streak, current_streak + arr[i]);
  best = max(best, current_streak);
}

// DIFFERENCE ARRAY
for (int i=1; i<arr.size(); i++){
  diff[i-1]= arr[i] - arr[i-1];
}

vector<vector<int>> arr(rows, vector<int>(cols)); \\ 2D ARRAY
vector<vector<vector<int>>> arr(rows, vector<vector<int>>(cols, vector<int>(depth))); \\ 3D ARRAY

// COMMON ALGORITHM PRE-DEFINED FUNCTION
#include<algorithm>
sort()
reverse()
find()
count()
binary_search()
lower_bound()
upper_bound()
min_element()
max_element()
unique()
fill()
rotate()
next_permutation()
prev_permutation()
nth_element()
partition()
stable_sort()
is_sorted()

// 1D PRE-DEFINED FUNCTIONS
v.push_back(x);
v.insert(pos, x);
v.pop_back();
v.erase(start, end); v.erase(start);
v.clear();
v.front();
v.back();
v.size();
v.empty();
v.assign(5, 10); // {10,10,10,10,10}
v.begin(); // first element
v.end(); // last element + 1 (no-element and pointer only)
v.rbegin(); // last element
v.rend(); // first element - 1 (no-element and pointer only)
find(v.begin(), v.end(), x);
count(v.begin(), v.end(), x);
sort(v.begin(), v.end());
sort(v.rbegin(), v.rend());
reverse(v.begin(), v.end());
*min_element(v.begin(), v.end());
*max_element(v.begin(), v.end());
