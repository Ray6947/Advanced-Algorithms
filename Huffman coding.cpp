#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
    char ch;
    int freq;
    Node *left,*right;
    Node(char c,int f){
        ch=c;
        freq=f;
        left=right=nullptr;
    }
};

struct compare{
    bool operator()(Node* l,Node* r){
        return l->freq>r->freq;
    }
};

void preorder(Node* root,string val,vector<string>& Codes){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        Codes.push_back(val);
    }
    preorder(root->left,val+"0",Codes);
    preorder(root->right,val+"1",Codes);
}

vector<string> huffmanCodes(string S,vector<int> f){
    priority_queue<Node*,vector<Node*>,compare> pq;

    for(int i=0;i<S.size();i++){
        pq.push(new Node(S[i],f[i]));
    }
    while(pq.size()>1){
        Node *l=pq.top(); 
        pq.pop();
        Node *r=pq.top();
        pq.pop();

        Node *a=new Node('_',l->freq + r->freq);
        a->left=l;
        a->right=r;
        pq.push(a);
    }
    Node *root=pq.top();
    vector<string> Codes;
    preorder(root,"",Codes);
    return Codes;
}

int main(){
    string str;
    cout<<"Enter the string: ";
    cin>>str;
    vector<int> freq;
    cout<<"Enter the frequency of each character: ";
    for(int i=0;i<str.length();i++){
        int val;
        cin>>val;
        freq.push_back(val);
    }
    cout<<"Output: ";
    vector<string> res=huffmanCodes(str,freq);
    for (int i=0;i<res.size();i++){
	    cout<<res[i]<<" ";
	}
    return 0;
}
