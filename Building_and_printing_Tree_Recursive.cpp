#include<bits/stdc++.h>
using namespace std;

class node
{
public:

    int data;
    node *left;
    node *right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }

};

node* buildTree()
{
    int d;
    cin>>d;

    if(d==-1)
    {
        return NULL;
    }

    node *root=new node(d);

    root->left=buildTree();
    root->right=buildTree();


    return root;

}

void preorderPrint(node *root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void inorderPrint(node *root)
{
    if(root==NULL)
    {
        return;
    }

    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
void postorderPrint(node *root)
{
    if(root==NULL)
    {
        return;
    }

    postorderPrint(root->left);
    postorderPrint(root->right);
    cout<<root->data<<" ";
}


int main()
{
    node *root =buildTree();

    preorderPrint(root);
    cout<<endl;
    inorderPrint(root);
    cout<<endl;
    postorderPrint(root);



}
