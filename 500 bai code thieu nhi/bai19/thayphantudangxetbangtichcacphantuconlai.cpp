#include<iostream>
#include<vector>

using namespace std;

void tichdien(vector<int> a){
    int n = a.size();
    vector<int> b(n,1);
    int l = 1;
    for(int i = 0; i < n; i++){
        b[i] = l;
        l *= a[i]; 
    }
    int r = 1;
    for(int i = n-1 ; i >= 0; i--){
        b[i] *= r;
        r *= a[i];
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
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
    tichdien(a);

}