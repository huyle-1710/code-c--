#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void thaphanoi(vector<int> &A, vector<int> &B, vector<int> &C,int n){
    int buoc = pow(2,n) - 1;
    for(int i =1; i <= buoc; i++){
            if(i % 3 == 1){
                if(B.empty() || (!A.empty() && A.back() < B.back())){
                    B.push_back(A.back());
                    A.pop_back();
                }
                else{
                    A.push_back(B.back());
                    B.pop_back();
                }            
            }
            else if(i % 3 == 2){
                if(C.empty() || (!A.empty() && A.back() < C.back())){
                    C.push_back(A.back());
                    A.pop_back();
                }
                else{
                    A.push_back(C.back());
                    C.pop_back();
                }            
            }
            else{
                if(C.empty() || (!B.empty() && B.back() < C.back())){
                    C.push_back(B.back());
                    B.pop_back();
                }
                else{
                    B.push_back(C.back());
                    C.pop_back();
                }            
            }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> A, B, C;
    for(int i =n; i >= 1; i--){
        A.push_back(i);
    }
    if(n%2 == 1) thaphanoi(A, B, C, n);
    else thaphanoi(A, C, B, n);
    for(int i = 0; i < B.size(); i++){
        cout << B[i] << " ";
    }
}