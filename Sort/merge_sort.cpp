#include<iostream>
#include<vector>
using namespace std;
void meger(vector<int> a,int l,int m,int r){

    vector<int> left(a.begin()+1,a.begin()+m+1);
    vector<int> right(a.begin()+m+1,a.begin()+r+1);
    int i=0,j=0,k=l;
    while(i<left.size() && j<right.size()){
        if(left[i]<right[j]){
            a[k++]=left[i++];
        }
        else{
            a[k++]=right[j++];
        }
    }
    // sao chep cac phan tu con lai cua mang trai 
    while(i<left.size()){
        a[k++]=left[i++];
    }
    while(j<right.size()){
        a[k++]=right[j++];
    }

}

void merge(int a[],int l,int m,int r){  //3 8   4 9 10
    int len_left=m-l+1;  // so luong phan tu mang ben trai 
    int len_right=r-m;   // so luong phan tu mang ben phai
    int *L=new int[len_left]; // tao mang tam de luu cac phan tu ben trai 
    int *R=new int[len_right];
    // chuyen du lieu tu mang ben trai vao mang a_leftx
    for(int i=0;i<len_left;i++){     
       L[i]=a[l+i];                 
    }
    // chuyen du lieu tu mang ben trai vao mang a_right
    for(int j=0;j<len_right;j++){    
        R[j]=a[m+j+1];            // R[0]=a[2+0+1]=a[3]=9
    }
    //tron 2 mang , so sanh 2 phan tu cua 2 mang , phan tu nao nho hon se duoc dua vao mang tron
    int i=0;
    int j=0;
    int k=l;                    //mang left: 3 8 
                                // mang right : 4 9 10
    while(i<len_left && j <len_right){    
        if(L[i]<=R[j]){             // 3<4         8>4          8<9
            a[k]=L[i];             //a[0]=3       a[1]=4       a[2]=8
            i++;                    // i=1;       j=1          i=2
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;                       // k=1      k=2           k=3
    }
    //luc nay mang left 3 va 8 da duoc dua vao mang tron nen khong con phan tu 
    // nao de so sanh voi mang right, can phai sao chep cac phan tu o mang right
    // con lai vao mang tron 
    while(j<len_right){
        a[k]=R[j];     //a[3]=R[1]=9      a[4]=10
        j++;             // j=2          
        k++;             // k=4
    }
    while(i<len_left){  // luc nay i =2 <2 false nen vong while nay khong chay 
        a[k]=L[i];
        i++;
        k++;
    }
    delete []L;
    delete []R;     

}
void merge_sort(int a[],int l,int r){
    if(l<r){
     int m=(l+r)/2;
     merge_sort(a,l,m);   // tach doi mang ben trai  
    merge_sort(a,m+1,r);  // tach doi mang ben phai 
    //gop 2 mang lai voi nhau 
     merge(a,l,m,r);
    }
    
}
int main(){
    int a[5]={1,9,7,0,3};
    merge_sort(a,0,4);
    for(int i=0;i<5;i++){
        cout<<a[i] << " " ;
    }

}