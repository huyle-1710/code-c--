#include <iostream>

void inMang(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
}

int main() {
    const int n = 13;
    int a[n] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};

    std::cout << "SELECTION SORT\nMang ban dau: ";
    inMang(a, n);

    for (int i = 0; i < n - 1; i++) {
        int index = i;
        int min = a[i];

        // Tim phan tu nho nhat trong doan chua sap xep.
        for (int j = i + 1; j < n; j++) {
            if (a[j] < min) {
                min = a[j];
                index = j;
            }
        }

        // Dua phan tu nho nhat ve vi tri i.
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;

        std::cout << "\nBuoc " << i + 1 << ": min = " << min
                  << " tai a[" << index << "]; doi a[" << i
                  << "] <-> a[" << index << "]\nMang: ";
        inMang(a, n);
    }

    std::cout << "\nKet qua: ";
    inMang(a, n);

    return 0;
}
