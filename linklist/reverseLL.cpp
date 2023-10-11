#include <iostream>
using namespace std;

class Node{
    
    public :
    int data;
    Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    //deconstructor
    ~Node(){
      int value =this->data;

      if(this->next != NULL){
        delete next;
        this->next=NULL;
      }
    }

};

void insertHead ( Node* &head,int d){
  Node* temp=new Node(d);
  temp->next=head;
  head=temp;
}


void insertTail(Node* &tail,int d){
  Node* temp=new Node(d);
  tail->next=temp;;
  tail=temp;
}

void insertatPosition(Node* &tail,Node* &head, int pos,int d){
    Node* temp=head;

    
    if(pos==1){
      insertHead(head,d);
       return;
    }
     if(temp->next==NULL){
      insertTail(tail,d);
      return;
    }

    Node* nodetoInsert= new Node(d);
    int cnt=1;

    
    while (cnt<pos-1)
    {
      temp=temp->next;
      cnt++;
    }

   

    nodetoInsert->next=temp->next;
    temp->next=nodetoInsert;
    
}
void deleteNode(Node* &head,int pos){
   
    if(pos==1){
       Node* temp=head;
       head=head->next;
     temp->next=NULL;
       delete temp;
    }
    else
    {
      Node* curr=head;
      Node* pre=NULL;
    int cnt=1;
      while(cnt<pos){
        pre=curr;
        curr=curr->next;
        cnt++;
      }

      pre->next=curr->next;
      curr->next=NULL;
      delete curr;
    }

}

void print(Node* &head){
  Node* temp=head;

  while(temp!=NULL){
     cout<<temp->data<<" ";
     temp=temp->next;
  }

  

}

int main(){
   
   Node* node1=new Node(10);


   Node * head=node1;
   Node* tail=node1;

   insertTail(tail,12);
 insertTail(tail,14);
 insertTail(tail,18);
   insertatPosition(tail ,head,3,16);
 
   print(head);
   cout<<"he"<<head->data;


}