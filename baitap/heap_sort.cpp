/*
    Tư tưởng: Sắp xếp vun đống hoạt động bằng cách hình dung
    các phần tử của mảng như một loại cây nhị phân hoàn chỉnh
    đặc biệt được gọi là heap
    Độ phức tạp : O(nlogn)
    Định nghĩa cây nhị phân hoàn chỉnh : Complete Binary Tree
    - Cây nhị phân hoàn chỉnh là cây nhị phân trong đó tất cả
    các cấp (level) được lấp đầy hoàn toàn ngoại trừ có thể là
    cấp thấp nhất, và được điền từ bên trái 
    - Tất cả các phần tử là phải nghiêng về bên trái 
    - Nốt lá cuối cùng có thể không có anh chị em bên phải
    
*/

#include <bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int max = i;
    if ( l < n && a[l] > a[max] ){
        max = l;
    }
    if ( r < n && a[r] > a[max]){
        max = r;
    }
    if (max != i){
        swap ( a[i], a[max]);
        heapify(a, n , max); // chuyển cây nhị phân lại về max heap
    }
}
void heapSort(int a[],int  n){
    // Xây dựng Max heap 
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a , n, i);
    }
    for(int i = n - 1; i >=0; --i){
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}
int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    heapSort (a,n);
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}