#include<iostream>
#include<vector>

using namespace std;

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void chuyen0vecuoimang( vector<int> &a ){
    int k = 0;
    for(int i = 0; i < a.size() - 1; i++){
        if(a[i] == 0){
            if(a[i+1]!=0){
                 swap(a[i-k], a[i+1]);
        }
        else k++;
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
    chuyen0vecuoimang(a);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}