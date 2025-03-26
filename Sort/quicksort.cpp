#include<iostream>
#include<algorithm>
using namespace std;
// phan hoach lomuto
// chon 1 vi tri pivot ( truc ) , phan hoach mang thanh 2 phan 
// phan ben trai chua cac phan tu nho hon pivot 
// ben phai chua phan tu lon hon pivot 
int partition(int a[],int l,int r){  // 2 9 6 3 4
    int pivot=a[r];                 // pivot =4
    int i=l-1;                      //i=-1
    for(int j=l;j<r;j++){
        if(a[j]<=pivot){             //2<4  9>4 ,6>4 bo qua ; j=3 ->4
            i++;                     //i=0  , swap a[0] voi a[0]   i=1 ,swap a[1] voi a[3]
            swap(a[i],a[j]);         //  step 1 : 2 9 6 3 4  step 2 : 2 3 6 9 4
        }
    }
    // dua truc ve giua 
    i++;                             // i=2 
    swap(a[i],a[r]);                 //swap 6 voi 4   -> 2 3 4 6 9 
    return i;                         // i=2
}
void quicksort(int a[],int l,int r){
    if(l>=r) 
    return;
    int p=partition(a,l,r);          
    quicksort(a,l,p-1);         // goi de quy de sap xep nua ben trai 
    quicksort(a,p+1,r);         // sap xep nua ben phai cua truc 
}
//phan hoach hoare
int partition2(int a[],int l,int r){    // 3 2 4 9 1
        int pivot=a[l];           // pivot=3  sap xep nua ben trai nho hon pivot , ben phai lon hon
        int i=l-1;                // i=-1; j=5
        int j=r+1;
        while(true){
            do{
                i++;                  // i=0
            } while(a[i]<pivot);       // 2<pivot ++i , 4>pivot 
            do{
                j--;                   //j=4 

            }while(a[j]>pivot);         //a[4]=1 <pivot 
            if(i<j){
                swap(a[i],a[j]);        //swap(a[2],a[4]) -> 3 2 1 9 4 
            }
            else 
            return j;
        }
}
void quick_sort2(int a[],int l,int r){
    if(l>=r){
        return;
    }
    int p=partition2(a,l,r);
    quick_sort2(a,l,p);
    quick_sort2(a,p+1,r);
}
int main(){
    int a[10]={2,3,1,6,8,10,9};
    quick_sort2(a,0,6);
    cout<<"mang sau khi sap xep " << endl;
    for(int i=0;i<7;i++){
        cout<<a[i] << " " ; 
    }
}