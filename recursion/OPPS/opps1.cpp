#include <iostream>
#include <bits/stdc++.h>


using namespace std;


class Student{

    private:
        string gf;//these are  the private member these can only accesible in the class

    public:

    //thrse data member are called properties
        int id;
        string name;


        //member function   //function in class called the name as behevior
        void sleep (){
            cout << "I am sleeping"<<endl;
        }

        //parameterized constructor
        Student(string _name,int _id){
            name = _name;
            id = _id;
        }

        //default constructor
         Student(){}   
        
};

int main(){
   // Student s1;
   // s1.name = "raman";

   // cout<<s1.name;
    Student s2("raka",1);

    s2.sleep();

    cout << s2.name;

    return 0;
}