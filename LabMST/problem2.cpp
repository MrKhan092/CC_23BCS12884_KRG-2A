/*Step 1: Convert numbers to binary
nums = [2,6,5,8]

2 = 0010
6 = 0110
5 = 0101
8 = 1000

Count set bits per position:

Bit	Count
0	1
1	2
2	2
3	1
Step 2: Construct numbers greedily

Build numbers using available bits.

First number

Take all possible bits:

bit0 -> 1
bit1 -> 1
bit2 -> 1
bit3 -> 1
1111 = 15

Remaining counts:

bit0 = 0
bit1 = 1
bit2 = 1
bit3 = 0
Second number
bit1 -> 1
bit2 -> 1
0110 = 6
Step 3: Compute answer
15² + 6²
= 225 + 36
= 261
*/
#include <bits/stdc++.h>
using namespace std;

long long maxSum(vector<int>& nums, int k) {
    vector<int> cnt(32, 0);

    for (int x : nums) {
        for (int b = 0; b < 32; b++) {
            if (x & (1 << b)) cnt[b]++;
        }
    }

    long long ans = 0;

    while (k--) {
        long long val = 0;

        for (int b = 0; b < 32; b++) {
            if (cnt[b] > 0) {
                val |= (1LL << b);
                cnt[b]--;
            }
        }

        ans += val * val;
    }

    return ans;
}

int main() {
    vector<int> nums = {2,6,5,8};
    int k = 2;

    cout << maxSum(nums, k);
}