#include<iostream>
using namespace std;
// moi node la mot con tro 
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
void duyet(node *head){
    while(head!=NULL){
       cout<< head->data << "-> " ;
       head=head->next;
    }
    cout<<"NULL " << endl;
}
void addNodeFirst(node **head ,int x ){   // node dau tien ban dau co *head=001
    node *newNode=makeNode(x);            // node moi co dia chi  newNode la 002 ,data=2;
    newNode->next=*head;                // tro den dia chi cua node dau tien  / newNode->next=001
    *head=newNode;                     // thay doi dia chi cua node dau tien bang dia chi cua node vua moi them / *head=002
 
}
void addNodeLast(node **head,int x){
    node *newNode=makeNode(x);       // head la con tro cap 2
    node *temp=*head;                   // *head la dia chi cua node dau tien 
    if(*head==NULL){
        *head=newNode;
        return;
    }
    while(temp->next!=NULL){        // tim ra node cuoi cung 
        temp=temp->next;     
    }
    temp->next=newNode;           // cho next cua node cuoi cung tro den dia chi node vua them

}
void deleteNodeFirst(node **head){
    if(*head==NULL){
        return;
    }
    node *temp=*head;     // cho con tro temp tro den vung nho head ban dau de ti giai phong 
    *head=(*head)->next;       // cho con tro head cho den node thu 2
    delete temp;
}
void deleteNodeLast(node **head){
    if(*head==NULL){
        return;
    }
    node *temp=*head;
    if(temp->next==NULL){     // neu chi co 1 node thi cho node do tro ve null va giai phong 
        *head=NULL;
        delete temp ;
    }
//    while(last->next!=NULL){
//       last=last->next;         // last tro den node cuoi cung 
//    }
//    node *find=*head;
//    while(find!=NULL){
//       if(find->next==last){
//         find->next=NULL;
//         return;
//       }
//       find=find->next;
//    }
      while(temp->next->next!=NULL){    // tim ra node dung truoc node cuoi cung 
            temp=temp->next;
      }
      node *last=temp->next;   // cho last tro den node code cuoi can xoa
      temp->next=NULL;
    delete last;
    /* gia su co 4 node 
    node 1 :(1,0x10)
    node 2: (2,0x20)     -> co dia chi la 0x10 
    node 3 : ( 3,0x30)    -> co dia chi la 0x20
    node 4 : (4,null) -> co dia chi la 0x30
    temp tro den (1,0x10)
    step 1 : temp=0x20!=null -> temp tro den (2,0x20)
    step 2 : temp = 0x30!=null -> temp tro den (3,0x30) 
    step 3 : temp=null 
    */
}
void insertNode(node **head,int x,int k){
    node *temp=*head;
    for(int i=1;i<k-1;i++){    // tro den node truoc node can thay 
        temp=temp->next;
    }
    node *newNode=makeNode(x);
    newNode->next=temp->next;       // cho next cua node moi tro de node dang sau 
    temp->next=newNode;             // cho next cua node dang truoc tro vao node moi 

}
void deleteNode(node *head,int k){
    node *front =head;
    for(int i=1;i<k-1;i++){
        front=front->next;    // node dang truoc 
    }
    node *temp=front->next;    // node hien tai 
    // for(int i=1;i<k;i++){
    //     temp=temp->next;
    // }
    
    front->next=temp->next;    // cho node dang truoc tro den node dang sau cua node thu k 
    delete temp;
}
int main(){
    node *headnode=makeNode(1);
    node *newnode2=makeNode(2);
    node *newnode3=makeNode(3);
    node *newnode4=makeNode(4);
    cout <<"dia chi cua head node " << headnode << endl;
    cout<< "dia chi cua node 2 " << newnode2 << endl;
    cout<<" dia chi cua node 3 " << newnode3 << endl;
    headnode->next=newnode2;
    newnode2->next=newnode3;
    cout<<" node2-> next : " << newnode2->next << endl;
    duyet(headnode);
    // them node vao dau danh sach
    cout<<"them 4 vao dau danh sach " << endl;
    addNodeFirst(&headnode,4);
    duyet(headnode);
     cout <<"dia chi cua head node " << headnode << endl;
     // them node vao cuoi danh sach 
     cout<<"them 5 vao cuoi danh sach " << endl;
     addNodeLast(&headnode,5);
     duyet(headnode);
    // xoa node o dau danh sach 
    deleteNodeFirst(&headnode);
    duyet(headnode);
    //xoa node o cuoi danh sach
    deleteNodeLast(&headnode);
    cout<<"xoa node o cuoi danh sach "<<endl;
    duyet(headnode);
    //insert vao vi tri thu 3
    cout<<"insert vao vi tri thu 3" << endl;
    insertNode(&headnode,6,3);
    duyet(headnode);
    cout<<"delete vi tri thu 3" << endl;
    deleteNode(headnode,3);
    duyet(headnode);
}