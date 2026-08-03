#include <iostream>
#include <climits>
using namespace std;

int main() { // used to randomly generate the smallest/ largest possible value for a variable
    cout << INT_MIN << endl; // -2147483648
    cout << INT_MAX << endl; // 2147483647
}

// k-sum target: recursive algorithm
vector<vector<int>> kSum(nums, start, k, target)
{
    if (k == 2)
        return TwoPointer();
    for (int i = start; i < n; i++)
        recurse(i + 1, k - 1, target - nums[i]);
}
