#include<bits/stdc++.h>
#include<cctype>
using namespace std;
struct node{
    char data;
    node *next;
};
node* makeNode(int x){
        node* newnode=new node();
        newnode->data=x;
        newnode->next=NULL;
        return newnode;
}

class Mystack{
    private:
    node *topNode=NULL;
    int n=0;
    public  : 
    void push(int x ){
        node* newnode=makeNode(x);              // them cac phan tu vao dau node , cang vao sau se duoc dua len dau dslk 
        if(topNode==NULL){
            topNode=newnode;
            n++;
            return;
        }
        newnode->next=topNode;
        topNode=newnode;
        n++; 
    }
    void pop(){                              // vao sau ra truoc , xoa cac phan tu o dau dslk
        node *temp=topNode;
        if(topNode!=NULL)
        topNode=(topNode)->next;
        n--;
        delete temp;
    }
    void duyet(){
        node *temp=topNode;
        while(temp!=NULL){
            cout<<temp->data << "->" ;
           temp=temp->next;
        }
        cout<<"NULL"<<endl;
    
    delete temp;
    }
   char top(){
    char top;
        if(topNode!=NULL)
          top= topNode->data;
        return top;
    }
    int size(){
        return n;
    }
    bool isEmpty(){
        if(topNode==NULL){
            return true;
        }
        return false;
    }
};
bool checktoanhang(char c){
    return isalnum(c);
}
bool checktoantu(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' ||
        c == '^' || c == '=' || c == '<' || c == '>' || c == '!' ||
        c == '&' || c == '|' || c == '~');
}
int doUuTien(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3; // Lũy thừa có độ ưu tiên cao nhất
    return 0; // Trường hợp không phải toán tử hợp lệ
}
bool sosanhUuTien(char op1, char op2) {
    if(op2=='(') return true;   
    return doUuTien(op1) > doUuTien(op2);
}


int main(){
    Mystack stack;
    // stack.push(1); 
    // stack.push(2);
    // stack.push(3);
    // stack.duyet();
    // stack.pop();
    // stack.duyet();
    // cout<<stack.size()<<endl;
    // cout<<" top cua stack " ; 
    // stack.top() ;
    
    /*
    - toan hang -> output 
    - toan tu uu tien cao hon toan tu o dinh-> day vao stack 
    - toan tu thap hon = thi lay toan tu o dinh ra output , day toan tu moi vao stack 
    - dau ( day vao stack 
    - gap dau ) thi pop cac toan tu ra cho vao output den khi gap ( roi bo ( 

    */
   string s="(A+B-C)*E/(F-G)+D";
    vector<char> output;
    for(int i=0;i<s.size();i++){
        if(checktoanhang(s[i])){     //toan hang -> output
            output.push_back(s[i]);  
        }
        if(s[i]=='('){             // dau ( -> stack 
            stack.push(s[i]);
        }
        if(s[i]==')'){  
           while(stack.top()!='(' && !stack.isEmpty()){
            if(checktoantu(stack.top())){   
                output.push_back(stack.top())  ;  // lay toan tu ra output 
                stack.pop();  
            }
            if(!stack.isEmpty() && stack.top()=='(')
            stack.pop(); // xoa bo (
          
           }
           
        } 
        if(checktoantu(s[i])){             // toan tu 
            if(stack.isEmpty()){           // stack rong-> day thang vao stack 
                stack.push(s[i]);
            }
            else {
                if(sosanhUuTien(s[i],stack.top()) && !stack.isEmpty()){    // toan tu co do uu tien cao hon thi day vao stack   
                    stack.push(s[i]);
                }
                else{    
                    while(!sosanhUuTien(s[i],stack.top()))  {                // toan tu o dinh cao hon hoac bang 
                   output.push_back(stack.top()) ;  // lay toan tu o dinh stack ra cho vao output
                   stack.pop();
                  
                }
                stack.push(s[i]); // cho toan tu moi vao 
            }
            }
        }

    }
    while (!stack.isEmpty()) {
        output.push_back(stack.top());
        stack.pop();
    }
    
    for(char x : output){
        cout<<x<<"";
    }

}