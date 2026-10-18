#include<iostream>
#include<vector>
using namespace std;
void thaphanoi (vector<int> &A, vector<int> &B, vector<int> &C, int n){
    if(n < 1) return;
    else if(n == 1){
        B.push_back(A.back());
        A.pop_back();
    }
    else{
        thaphanoi(A, C, B, n-1);
        thaphanoi(A, B, C, 1);
        thaphanoi(C, B, A, n-1);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> A, B, C;
    for(int i = n; i>=1; i--){
        A.push_back(i);
    }
    thaphanoi(A, B, C, n);
    for(int i = 0; i<B.size(); i++){
        cout << B[i] << " ";
    }
}