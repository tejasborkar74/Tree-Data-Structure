#include <bits/stdc++.h>
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

    if(d==-1)return NULL;

    node *root= new node(d);

    root->left=buildTree();
    root->right=buildTree();

    return root;
}

int height(node *root)
{
    if(root==NULL)return 0;

    int l=height(root->left);
    int r=height(root->right);

    return max(l,r)+1;
}

//recursive level order travalser

void printKthLevel(node *root,int k)
{
    if(root==NULL)
    {
        return;
    }

    if(k==1)
    {
        cout<<root->data<<" ";
        return;
    }

    printKthLevel(root->left,k-1);
    printKthLevel(root->right,k-1);
}

void levelOrderRecursion(node *root)
{
    int h=height(root);

    for(int i=1;i<=h;i++)
    {
        printKthLevel(root,i);
        cout<<endl;
    }

}

//BFS travalser

void bfs(node *root)
{
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *f=q.front();

        if(f==NULL)
        {
            cout<<endl;
            q.pop();

            if(!q.empty())
            {
                q.push(NULL);
            }
            else
            {
                return;
            }
        }

        f=q.front();
        cout<<f->data<<" ";
        q.pop();

        if(f->left)
        {
            q.push(f->left);
        }
        if(f->right)
        {
            q.push(f->right);
        }
    }
}
int main()
{
    node * root=buildTree();

   // levelOrderRecursion(root);
   bfs(root);
}
