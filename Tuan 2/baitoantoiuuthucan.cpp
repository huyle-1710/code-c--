#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Mathang {
    private:
        string ten;
        int khoiluong;
        int calo;
    
    public:
        Mathang(int khoiluong, int calo, const string& ten){
            this->khoiluong = khoiluong;
            this->calo = calo;
            this->ten = ten;
        }
        bool operator ==(const Mathang& other) const {
            return this->ten == other.ten && this->khoiluong == other.khoiluong && this->calo == other.calo;
        }
        const string& layten() {
            return ten;
        }
        int laykhoiluong() {
            return khoiluong;
        }
        int laycalo() { 
            return calo;
        }
};

class Danhsachmathang{
    private:
        vector<Mathang> ds;
        vector<Mathang> toiuuthucan;
        vector<Mathang> truyvet;
    public:
        Danhsachmathang(vector<Mathang> ds){
            this->ds = ds;
            this->toiuuthucan.assign(1001, Mathang(0, 0, "Khong co mat hang"));
        }
         int timmaxcalo(){
            int m = 1000;
            vector<int> Tongcalo;
            Tongcalo.resize(1001, 0);
            for(int i = 0; i <= 1000; i++){
                for(int j = 0; j < ds.size(); j++){
                    if(i >= ds[j].laykhoiluong()){
                        if(Tongcalo[i] < Tongcalo[i - ds[j].laykhoiluong()] + ds[j].laycalo()){
                            Tongcalo[i] = Tongcalo[i - ds[j].laykhoiluong()] + ds[j].laycalo();
                            toiuuthucan[i] = ds[j];
                        }
                    }
                }
            }
            return Tongcalo[1000];
         }
         void truyvetnguoc(){
            truyvet.clear();
            int i = 1000;
            while(i>=0){
                if(toiuuthucan[i].layten() == "Khong co mat hang"){
                    break;  
                }
                else{
                    truyvet.push_back(toiuuthucan[i]);
                    i = i - toiuuthucan[i].laykhoiluong();
                }
            }
    }
         void ketqua(){
            for(int i = 0; i<ds.size(); i++){
                int count = 0;
                for(int j = 0; j<truyvet.size(); j++){
                    if(truyvet[j].layten() == ds[i].layten()){
                        count++;
                    }
                }
                if(count > 0){
                    cout << "Mat hang: " << ds[i].layten() << endl;
                    cout << "So luong: " << count << endl;
                }
            }
         }   
};
int main(){
    int n;
    cout << "Nhap so luong mat hang: ";
    cin >> n;
    vector<Mathang>ds;
    for(int i = 0; i<n; i++){
        int kl, calo;
        string ten;
        cout << "Nhap ten mat hang: ";
        getline (cin >> ws ,ten);
        cout << "Nhap khoi luong: ";
        cin >> kl;
        cout << "Nhap luong calo: ";
        cin >> calo;
        ds.push_back(Mathang(kl, calo, ten));
    }
    Danhsachmathang toiuu(ds);
    int c = toiuu.timmaxcalo();
    cout << "Luong calo toi da la: " << c << endl;
    toiuu.truyvetnguoc();
    toiuu.ketqua();
}
