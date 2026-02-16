#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* createTree(){
    cout<<"enter the value for Node"<<endl;
    int val;
    cin>>val;

    if(val==-1){
        return NULL;
    }
    else{
        Node* root=new Node(val);
        cout<<"add node to the left of:- "<<val<<endl;
        root->left=createTree();
        cout<<"add node to the right of:- "<<val<<endl;
        root->right=createTree();

        return root;
    }
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    preorder(root->left);
    cout<<root->data<<" ";
    preorder(root->right);
}
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node *root=NULL;
    root=createTree();
    cout<<"this is a preorder traversal:- "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"this is a inorder traversal:- "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"this is a postorder traversal:- "<<endl;
    postorder(root);
    cout<<"avi ka ho gya bhai"<<endl;

    return 0;
}

