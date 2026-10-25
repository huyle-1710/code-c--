#include <iostream>
#include <vector>

using namespace std;

void inMang(const vector<int>& a, int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}
void timMangCon(const vector<int>& a) {
    bool found = false;
    for (int i = 0; i < a.size(); i++) {
        int tong = 0;
        for (int j = i; j < a.size(); j++) {
            tong += a[j];
            if (tong == 0) {
                inMang(a, i, j);
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Khong co mang con co tong bang 0!\n";
    }
}

int main() {
    int n;
    cin >> n;
    if (n < 0) {
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    timMangCon(a);
    return 0;
}