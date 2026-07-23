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


