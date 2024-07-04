#include <iostream>
using namespace std;

class Stack{
    //properties
    public:

    int size;
    int *arr;
    int top;

   //function
   Stack (int size){
    this->size=size;
    arr=new int[size];
    top=-1;

   }

   void push(int ele){
    if(size-top>1){
        top++;
        arr[top]=ele;
    }
        else
        cout<<"overflow"<<endl;
        
    }
    void pop(){
        if(top>=0){
            top --;

        }
        else
        cout<<"underflow"<<endl;
    }
    int  peek(){
        if(top>=0&&top<size){
            return arr[top];
        }
        else 
        cout<<"empty"<<endl;
        return -1;
    }
    bool isEmpty (){
        if(top==-1)
     return true;
        else
        return false;

    }
    
   
};

int main(){
    
  Stack st (5);
  st.push(20);
  st.push(33);
  st.pop();
  st.pop();
  
  int a=st.peek();
  cout<<st.isEmpty();


}