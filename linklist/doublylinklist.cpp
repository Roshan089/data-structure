#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node*pre;

    //constructer
    Node (int d){
        this->data=d;
        this->next = NULL;
        this->pre = NULL;

    }

};

void Inserthead(Node* &head, int d){
    Node* temp=new Node(d);

    temp->next=head;
    head->pre=temp;
    head=temp;

}

void Inserttail(Node* &tail, int d){ 
     Node* temp=new Node(d);

    tail->next=temp;
    temp->pre=tail;
    tail=temp;
}
void insertatPos(Node* &head,Node* &tail,int pos,int d){
    Node* nodeToinsert=new Node(d);
    Node* temp=head;
    int cnt=1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
    }
    temp->next=nodeToinsert;
    nodeToinsert->pre=temp;
    
}


void print(Node* head){

    Node* temp=head;

    while(temp!=NULL){
         cout<<temp->data<<" ";
        temp=temp->next;
       
    }
cout<<endl;
}




int main(){
    Node* node1=new Node(10);
    Node* head=node1;
        Node* tail=node1;

    Inserthead(head,12);
    Inserttail(tail,16);

    print(head);
}