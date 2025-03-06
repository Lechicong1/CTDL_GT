#include<iostream>
using namespace std; 
/* dao nguoc link list 
input:1-2-3-4-null
output:4-3-2-1-null*/
struct node{
    int data;
    node *next;       // con tro next kieu node tro den node tiep theo 
};
// khoi tao mot node 
node* makeNode(int data){
    node *newNode=new node;
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
class linklist{
        private : 
        node *head;
        public : 
        linklist(){
            head=NULL;
        }
        void duyet(){
            node *temp=head;
            while(temp!=NULL){
                cout<< temp->data << "-> " ;
                temp=temp->next;
             }
             cout<<"NULL" << endl;
        }
        void addNodeFirst(int x ){   // node dau tien ban dau co *head=001
            node *newNode=makeNode(x);            // node moi co dia chi  newNode la 002 ,data=2;
            newNode->next=head;                // tro den dia chi cua node dau tien  / newNode->next=001
            head=newNode;                     // thay doi dia chi cua node dau tien bang dia chi cua node vua moi them / *head=002
         
        }
        void addNodeLast(int x){
            node *newNode=makeNode(x);       // head la con tro cap 2
            node *temp=head;                   // *head la dia chi cua node dau tien 
            if(head==NULL){
                head=newNode;
                return;
            }
            if(head->next==NULL){
                head->next=newNode;
            }
            else{
                while(temp->next!=NULL){        // tim ra node cuoi cung 
                    temp=temp->next;     
                }
                temp->next=newNode;       
            }
              
        
        }
        void reverse(){
            node *current=head;
          
            while(current!=NULL && current->next!=NULL){
                node *next=current->next;
                current->next=next->next;
                next->next=current;
                head=next;
               

            }
        }

};
int main(){
   linklist l;
   l.addNodeFirst(1);
   l.addNodeFirst(2);
   l.addNodeFirst(3);
   l.addNodeFirst(4);
   l.duyet();
   l.reverse();
   l.duyet();

}

