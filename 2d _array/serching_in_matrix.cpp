#include <iostream>
using namespace std;
  
// Driver Code
int main()
{
    int n;
    cin>>n;
    int a[n][n];
    int key;

    cin>>key;

    for(int i=0; i<n; i++) {
for(int j=0; j<n; j++)
cin >> a[i][j];
}

   int i=0;
   int j=n-1;
bool match=false;
   
   while (i<n&&j>=0)
   {
    
     if(a[i][j]==key)
     match=true;
   
     if(key>a[i][j])
     i++;
     else
     j--;

     
   

   }
   
   
if(match==true){
    cout<<"match found";
}
else 
cout<<"not found";
   

}
