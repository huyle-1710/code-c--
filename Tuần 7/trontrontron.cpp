#include<iostream>
#include<vector>

using namespace std;

void inMang(vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}
void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void trontrontron (vector<int> &a, int begin, int end, int mid){
    int x = begin;
    int y = mid + 1;
    while(x < y && y <= end){
        if(a[x] <= a[y]) x++;
        else{
            for(int i = y; i > x; i--){
                swap(a[i], a[i-1]);
            }
            x++;
            y++; 
        }
    }
    inMang(a);
}

void tachtachtach(vector<int> &a, int begin, int end){
    int mid = (begin + end)/2;
    if((end - begin) <= 0){
        return;
    }
    else{
        tachtachtach(a, begin, mid);
        tachtachtach(a, mid + 1, end);
        trontrontron(a, begin, end, mid);
    }
}