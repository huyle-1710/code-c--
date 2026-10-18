#include <iostream>

void inMang(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << (i == n - 1 ? '\n' : ' ');
    }
}

void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    const int n = 13;
    int a[n] = {101, 23, 57, 13, 25, 121, 87, 36, 13, 204, 111, 89, 59};

    std::cout << "INSERTION SORT\nMang ban dau: ";
    inMang(a, n);

    for (int i = 1; i < n; i++) {
        std::cout << "\nBuoc " << i << ": chen " << a[i]
                  << " vao doan a[0.." << i - 1 << "]\n";
        int j = i;

        // Doi cho lien tiep de chen a[i] vao dung vi tri.
        while (j > 0) {
            if (a[j] < a[j - 1]) {
                Swap(a[j], a[j - 1]);
                std::cout << "  Doi a[" << j << "] <-> a[" << j - 1 << "]: ";
                inMang(a, n);
                j--;
            } else {
                break;
            }
        }
        std::cout << "Sau buoc " << i << ": ";
        inMang(a, n);
    }

    std::cout << "\nKet qua: ";
    inMang(a, n);

    return 0;
}
