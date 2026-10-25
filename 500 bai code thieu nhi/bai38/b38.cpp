#include <iostream>
#include <vector>

using namespace std;

int tichLonNhat(const vector<int>& a) {
    int maxEnd = a[0];
    int minEnd = a[0];
    int best = a[0];
    for (int i = 1; i < a.size(); i++) {
        int x = a[i];
        int p = maxEnd * x;
        int q = minEnd * x;
        maxEnd = x;
        if (p > maxEnd) maxEnd = p;
        if (q > maxEnd) maxEnd = q;
        minEnd = x;
        if (p < minEnd) minEnd = p;
        if (q < minEnd) minEnd = q;
        if (maxEnd > best) {
            best = maxEnd;
        }
    }
    return best;
}

int main() {
    int n;
    cin >> n;
    if (n <= 0) {
        cout << "Mang rong!\n";
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << tichLonNhat(a) << '\n';
    return 0;
}