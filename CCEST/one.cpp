#include <iostream>
using namespace std;

class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.resize(n + 1, 0);
    }

    void update(int i, int v) {
        for(; i <= n; i += (i & -i))
            bit[i] += v;
    }

    int sum(int i) {
        int s = 0;
        for(; i > 0; i -= (i & -i))
            s += bit[i];
        return s;
    }


    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    int n = 5;
    Fenwick ft(n);

 
    ft.update(1, 5);   
    ft.update(3, 2);   
    ft.update(5, 7);   

    cout << "Sum 1 to 5: " << ft.rangeSum(1, 5) << endl;
    cout << "Sum 2 to 4: " << ft.rangeSum(2, 4) << endl;

    return 0;
}