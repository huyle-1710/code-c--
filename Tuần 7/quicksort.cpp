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

int phanhoach (vector<int> &a, int begin, int end) {
    int i = begin; 
    int j = end - 1;
    if(begin < end){
        while(i <= j){
            while(i <= j && a[end] > a[i]) i++;
            while(i <= j && a[end] < a[j]) j--;
            if(i <= j){
                swap(a[i], a[j]);
                i++;
                j--;
           }
        }
        swap(a[end], a[i]);
        if(i != end){
            inMang(a);
        }
    }
    return i;
}

void quicksort(vector<int> &a, int begin, int end){
    if(begin >= end){
        return ;
    }
    else{
        int x = phanhoach(a, begin, end);
        quicksort(a, begin, x-1);
        quicksort(a, x+1, end);
    }
}

int main(){
    vector<int> a = {101, 23, 57, 13, 26, 121, 87, 36, 13, 204, 111, 89, 69};
    quicksort(a, 0, a.size() - 1);
}
