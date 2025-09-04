#include <iostream>
#include <vector>

using namespace std;

class TriesNode{
    
    public:
    
    char val;
    bool isTerminal;
    TriesNode* child[26];
    
    TriesNode(char val){
        this->val=val;
        isTerminal=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

void allSugg(TriesNode* root ,vector<string> &ans, string &temp){
     if(root->isTerminal==true)
           ans.push_back(temp);
    for(int i=0;i<26 ;i++){
          
        
        if(root->child[i]){
            temp.push_back(root->child[i]->val)  ;
            allSugg(root->child[i],ans,temp);
            temp.pop_back();
        }
    }
    
}

void searchgoog(TriesNode* root, string input,vector<string> &ans,string &temp){
    
    if(input.length()==0){
     allSugg(root,ans,temp);
     return;
    }
    
   char ch=input[0];
    int index=ch-'a';
    if(root->child[index]!=NULL){
        searchgoog(root->child[index],input.substr(1),ans,temp);
    }
}


bool search(TriesNode* root, string word){
    if( word.length()==0 )
    return true;
    char ch=word[0];
    int index=ch-'a';
    if(root->child[index]==NULL) return false;
    if(root->child[index]&& root->isTerminal && word.length()==0){
        return true;
    }

    return search(root->child[index], word.substr(1));
    
}
void insertWord( TriesNode* root, string input){
    if(input.length()==0){
        root->isTerminal=true;
        return;
    }
    char c= input[0];
    int index =c-'a';
    if(root->child[index]==NULL)
    root->child[index]=new TriesNode(c);
    
    insertWord(root->child[index],input.substr(1));
    
}

int main(){
    TriesNode* root= new TriesNode('-');
    insertWord(root, "aalaa");
     insertWord(root, "aadfs");
      insertWord(root, "aalsf");
       insertWord(root, "aalaaaaa");
        insertWord(root, "aaldlksujs");
        vector<string> ans;
        string temp;
        searchgoog(root,"aa",ans,temp);
          cout << "Suggestions for prefix \"" << prefix << "\":" << endl;
    for (string s : ans) {
        cout << s << endl;
    }

    //cout<<search(root, "o");
}
