#include<iostream>
#include<vector>

using namespace std;

void mangconmax(vector<int> a){
    if(a.size() == 0){
        cout << "Mảng rỗng" << endl;
    }
    else{
        int tong = a[0];
        int max = a[0];
        int low = 0;
        int high = 0;
        int start = 0;
        for(int i = 1; i < a.size(); i++){
            if(tong < 0){
                start = i;
                tong = a[i];
            }
            else{
                tong += a[i];
            }
            if(tong > max){
                max = tong;
                low = start;
                high = i; 
            }

        }
        cout << max << endl; 
        for(int i = low; i <= high; i++){
            cout << a[i] << " ";   
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
    mangconmax(a);

}