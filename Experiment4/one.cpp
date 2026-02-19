#include <bits/stdc++.h>
using namespace std;

int totalHammingDistance(vector<int>& A) {
    int n = A.size();
    long long ans = 0;

    // Check each bit position (0 to 31 for int)
    for (int bit = 0; bit < 32; bit++) {
        int count1 = 0;

        // Count numbers having current bit set
        for (int i = 0; i < n; i++) {
            if (A[i] & (1 << bit))
                count1++;
        }

        int count0 = n - count1;

        // For ordered pairs multiply by 2
        ans += (long long)count1 * count0 * 2;
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> A(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Total Hamming Distance: "
         << totalHammingDistance(A) << endl;

    return 0;
}
