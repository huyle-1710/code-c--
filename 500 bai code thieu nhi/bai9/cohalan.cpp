
#include<iostream>
#include<vector>

using namespace std;

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void cohalan(vector<int>& a) {
    int low = 0;
    int mid = 0;
    int high = a.size() - 1;

    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else { // a[mid] == 2
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    cohalan(a);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}


