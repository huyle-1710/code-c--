/*Cho một mảng số nguyên chưa được sắp xếp, 
hãy tìm một cặp số trong mảng 
có tổng bằng một giá trị cho trước.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Ham sap xep mang quicksort
int phanhoach(vector<int>& a, int low, int high) {
    int pivot = a[high]; // chon phan tu cuoi lam pivot
    int b = low; // chi so cua pivot dong thoi cung la so luong phan tu nho hon pivot
    for (int i = low; i<high; i++) {
        if (a[i] < pivot) {
            swap(a[i], a[b]);// chuyen phan tu nho hon pivot sang trai
            b++;// cap nhat chi so cua pivot
        }
    }
    swap(a[b], a[high]);// chuyen pivot ve dung vi tri cua no
    return b;
}

// ham de quy quicksort
// low < high la dieu kien dung de quy
void quicksort(vector<int>& a, int low, int high) {
    if(low < high) {
        int vitri = phanhoach(a, low, high);
        quicksort(a, low, vitri - 1);
        quicksort(a, vitri + 1, high);
    }
}

// Ham tim cap so co tong bang target
void timcap(vector<int>& a, int target) {
    quicksort(a, 0 , (int)a.size() - 1);
    int low = 0;
    int i = 0;
    int high = (int)a.size() - 1;
    while (low < high) {
        int sum = a[low] + a[high];
        if (sum == target) {
            cout << "Pair found (" << a[low] << ", " << a[high] << ")" << endl;
            low ++;
            high --;
            i ++;
        }
        else if(sum < target) {
            low ++;
        }
        else {
            high --;
        }
    }
    if (i == 0) {
        cout << "No pair found" << endl;
    }
}

// Ham main
int main() {
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        a.push_back(x);
    }
    int target;
    cin >> target;
    timcap(a, target);
    return 0;
}


