#include <string>
#include <cctype>

string s;
string s="hello";
string s(5, 'a'); // aaaaa
string s="";

getline(cin, s); // to get full string

s[5];
s.front();
s.back();
s.length();
s.size();
s[i] = x;

reverse(s.begin(), s.end());
sort(s.begin(), s.end());
count(s.begin(), s.end(), 'a');
s.find("xyz");
s.substr(start, length);

s.erase(pos, length);
s.replace(pos, length, substr);
s.insert(pos, substr);

isdigit(x);
isalpha(x);
isupper(x);
islower(x);
tolower(x);
toupper(x);

// FREQUENCY
vector<int> freq
for(char c:s){
  freq[c-'a']++;
}
// TWO POINTER
int l=0;
int r=s.size() - 1;
while(l<r){
  . . .
  // increment/ decrement accordingly (together or independent)
  l++;
  r--:
}
// SLIDING WINDOW
// sliding forward
new sum = old sum - left element + right element (back++ & front++)
// sliding backword 
new sum = old sum + left element - right element (back-- & front--)
