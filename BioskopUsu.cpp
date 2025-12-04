#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int interpolationSearch(const vector<int>& arr, int n, int x) {
    int low = 0, high = n - 1;
    int index = -1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low; 

            return -1;
        }

            
        int pos = low + ((x - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    int n, x;
    cin >> n;

    vector<int> seats(200);
    for (int i = 0; i < n; ++i) {
        cin >> seats[i];
    }

    cin >> x;

    int index = interpolationSearch(seats, n, x);
    if (index != -1) {
        cout << "TERSEDIA: Mencari Kursi nomor " << x << " ada di posisi index " << index << endl;
        cout << "Silakan melakukan pemesanan." << endl;
        cout << "Terima kasih." << endl;
    } else {
        cout << "TIDAK TERSEDIA: Kursi nomor " << x << " tidak ditemukan." << endl;
        cout << "Silakan memilih nomor kursi lainnya." << endl; 
        cout << "Terima kasih." << endl;
    }

    return 0;
}