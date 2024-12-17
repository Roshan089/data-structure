#include <iostream>
#include <bits/stdc++.h>


using namespace std;


class Student{

    private:
        string gf;

    public:
        int id;
        string name;
        Student(string _name,int _id){
            name = _name;
            id = _id;
        }
         Student(){}   
        
};

int main(){
   // Student s1;
   // s1.name = "raman";

   // cout<<s1.name;
    Student s2("raka",1);

    cout << s2.name;

    return 0;
}