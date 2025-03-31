#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class Heap{
    private: 
    int *heap;
    int size ;
    int max;
    public : 
    Heap(int max){
        heap=new int[max];
        this->max=max;
        size=0;
    }
    bool isEmpty(){
        if(size==0)
        return true;
        return false;
    }
    bool isFull(){
        if(size==max)
        return true;
        return false;
    }
    void add(int x){
        if(isFull()){
            return;
        }
        size++;
        heap[size]=x;
        //heapifyup
        int curIndex=size;
        int parentIndex=size/2;
        while(parentIndex!=0 && heap[parentIndex]>heap[curIndex]){
            swap(heap[parentIndex],heap[curIndex]);
            curIndex=parentIndex;
            parentIndex=curIndex/2;
        }
    }
    void show(){
        for(int i=1;i<=size;i++){
            cout<< heap[i] << " ";
        }
    }
    void heapifyDown(int curIndex){
        while(2*curIndex<=size){
            int Left=2*curIndex;
            int Right=Left+1;
            int smaller=Left;
            if(Right<=size && heap[Right]<heap[Left]){
                smaller=Right;
            }
            if(heap[curIndex]>heap[smaller]){
                swap(heap[curIndex],heap[smaller]);
                curIndex=smaller;
            } else{
                break;
            }
        }
    }
    void Heap_sort(){
        if(isEmpty()){
            return;
        }
        queue<int> s;
        while(!isEmpty()){
       
        int minRoot=heap[1];
        s.push(minRoot);
        //heapify down
        heap[1]=heap[size];
        size--;
        heapifyDown(1);
        
        }
        while(!s.empty()){
            cout<<s.front() << " ";
            s.pop();
        }
        
    }
    void remove(int key){
        int curIndex=-1;
        for(int i=1;i<size;i++){
            if(heap[i]==key){
                curIndex=i;
            }
        }
        if(curIndex==-1){
            return ;
        }
        heap[curIndex]=heap[size]; // hoan doi cho phan tu cuoi cung 
        heapifyDown(curIndex);
    }

};
int main(){
    Heap h(10);
    h.add(3);
    h.add(1);
    h.add(5);
    h.add(7);
    h.add(6);
    h.add(4);
    h.add(2);
    h.show();
    cout<<endl;
    h.Heap_sort();
    // h.Heap_sort();


}