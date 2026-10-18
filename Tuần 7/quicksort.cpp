#include<iostream>
 
using namespace std;

void swap (int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int phanhoach (int *a, int begin, int end) {
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
    }
    return pivot;
}

void quicksort(int *a, int begin, int end){
    if(begin >= end){
        return ;
    }
    else{
        int x = phanhoach(a, begin, end);
        quicksort(a, begin, x-1);
        quicksort(a, x+1, end);
    }
}
