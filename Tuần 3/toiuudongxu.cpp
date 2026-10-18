/* Có n đồng xu có trọng lượng x_1,x_2,...,x_n 
bài toán đặt ra là tìm số lượng đồng xu nhỏ nhất 
để có khối tổng khối lượng là S.*/

#include<iostream>
#include<vector>
using namespace std;

// Lop tung dong xu
class Coin {
    private:
        int khoiluong;
    public:
        Coin(int khoiluong) {
            this->khoiluong = khoiluong;
        }
        int laykhoiluong() const {
            return khoiluong;
        }
    };
// danh sach khoi luong dong xu
class danhsachdongxu {
    private:
        vector<Coin> ds;
    public:
        danhsachdongxu(const vector<Coin>& ds ){
            this->ds = ds;
        }
        // ham tim min
        int timmin(int S){
            vector<int> dsmin(S + 1, S + 1);
            dsmin[0] = 0;
            for (int i = 1; i <= S; i++) {
                for(const Coin& dongxu : ds) {
                    int w = dongxu.laykhoiluong();
                    if(i >= w) {
                    if (dsmin[i - w] + 1 < dsmin[i]) {
                        dsmin[i] = dsmin[i - w] + 1;
                    }
                }
            }
        }
        return dsmin[S] != S + 1 ? dsmin[S] : -1;
    }
};

// Ham main
int main() {
    int n, S;
    cout << "Nhap tong khoi luong: ";
    cin >> S;
    cout << "Nhap so luong dong xu: ";
    cin >> n;
    vector<Coin> ds;
    cout << "Nhap khoi luong cua " << n << " dong xu: " << endl;
    for (int i = 0; i < n; i++) {
        int khoiluong;
        cin >> khoiluong;
        ds.push_back(Coin(khoiluong));
    }
    int min = danhsachdongxu(ds).timmin(S);
    if(min != -1) {
        cout << "So luong dong xu nho nhat de co khoi luong " << S << " la: " << min << endl;
    }
    else {
        cout << "Khong ton tai cach lay dong xu de co khoi luong bang " << S << endl;
    }
    return 0;
}