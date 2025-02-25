#include<iostream>
using namespace std;
void thapHaNoi(int n,char a,char b,char c){
    if(n==1)
    cout<<"chuyen dia "<< n<< " tu " << a << " sang " << c << endl ;
    else{
        thapHaNoi(n-1,a,c,b); // chuyen 2 dia tu a sang b 
        thapHaNoi(1,a,b,c);   // chuyen 1 dia tu a sang c
        thapHaNoi(n-1,b,a,c);  // chuyen 2 dia tu b sang c 
    }
}
int main(){
    thapHaNoi(3,'A','B','C');
}