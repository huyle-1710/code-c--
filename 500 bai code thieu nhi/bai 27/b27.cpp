#include<iostream>
#include<vector>

using namespace std;

int maxvatimvitri (vector<int> a, int &start, int &end, int &max){
    vector<int> b;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == 0){
            b.push_back(i);
        }
    }
    int tong;
    if(b.size() == 0){
        max = a.size();
        start = 0;
        end = max - 1;
        return max;
    }
    else{
        b.push_back(a.size());
        tong = b[0];
        if(tong > max){
            max = tong;
            start = 0;
            end = b[0] - 1;
        }
        for(int i = 0; i < b.size() - 1; i++){
            tong  = b[i+1] - b[i] - 1; 
            if(max < tong){
                max = tong;
                start = b[i] + 1;
                end = b[i+1] - 1;
            }
        }
        return max;
    }
}

void input(int k, vector<int> &a){
    vector<int> b;
    int max = 0;
    int start = 0;
    int end = -1;
    for(int i = 0; i < a.size() ; i++){
        if(a[i] == 0){
            b.push_back(i);
        }
    }
    if(k > b.size()){
        input(b.size(), a);
        return;
    }
    for(int i = 0; i < b.size() - k + 1; i ++){
        for(int j = 0; j<k; j++){
            a[b[i + j]] = 1;
        }
        maxvatimvitri(a, start, end, max);
        for(int j = 0; j<k; j++){
            a[b[i + j]] = 0;
        }
    }
    cout <<"Kích thước tối đa là: " << max << endl;
    if(max == 0){
        cout << "Không có đoạn số 1" << endl;
    }
    else{
        cout << "Từ vị trí " << start << " đến " << end << endl;
    }
}

int main(){
    int k, n;
    if(!(cin >> k >> n) || k < 0 || n < 0){
        return 0;
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        if(!(cin >> a[i]) || (a[i] != 0 && a[i] != 1)){
            return 0;
        }
    }

    input(k, a);
    return 0;
}
