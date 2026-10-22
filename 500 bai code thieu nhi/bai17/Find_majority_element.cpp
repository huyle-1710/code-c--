#include<iostream>
#include<vector>

using namespace std;

int phantuchiemdaso(vector<int> &a){
    int count = 0;
    int target;
    for(int i = 0; i < a.size(); i++){
        if(count == 0){
            target = a[i];
        }
        if(a[i] == target){
            count++;
        }
        else count--;
    }
    count = 0;
    for(int i = 0; i < a.size(); i++){
        if(target == a[i]){
            count ++;
        }
    }
    if(count > a.size()/2){
        cout << "Phần tử chiếm đa số là: " << target << endl;
        return 0;
    }
    else{
        cout << "Không có phần tử chiếm đa số!" << endl;
        return 0;
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
    phantuchiemdaso(a);

}