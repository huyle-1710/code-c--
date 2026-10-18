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
    int pivot;
    if(begin < end){
        int i = begin; 
        int j = end - 1;
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
        pivot = i;
        if(pivot != end){
            inMang(a);
        }
    }
    return pivot;
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
