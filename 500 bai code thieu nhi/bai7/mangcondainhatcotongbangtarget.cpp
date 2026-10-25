#include<iostream>
#include<vector>

using namespace std;

void inMang(vector<int> &a, int start, int end) {
    for (int i = start; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

int chiamang(int n, vector<int> a, int target){
    if(n > a.size()){
        return 0;
    }
    else{
        int tong = 0;
        for(int i = 0; i < n; i++){
            tong += a[i];
        }
        int count = 0;
        if(tong == target){
            inMang(a, 0, n-1);
        }
        else{
            count++;
        }
        for(int i = 0; i < (a.size() - n); i++){
            tong = tong - a[i] + a[n + i];
            if(tong == target){
                inMang(a, i+1, n + i);
            }
            else{
                count ++;
            }
        }
        if(count == (a.size()-n+1)){
            return 0;
        }
        else{
            return n;
        }
    }
}

int main(){
    int target;
    cin >> target;
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x; 
        a.push_back(x);
    }
    int c = 0;
    for(int i = 0; i < n; i++){
        c = chiamang(n - i, a, target);
        if(c!=0){
            cout << c << endl;
            break;
        }
    }
    if(c == 0){
        cout << "Khong ton tai mang con co tong bang target!" << endl;
    }
}