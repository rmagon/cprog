#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};
struct node* createNode(int k)
{
    struct node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = k;
    return temp;
}

struct node* createSpecialInorder(int a[],int start,int end)
{
    if(start>end)
    {
      //  cout<<"start>end"<<endl;
    return NULL;
    }
    
    if(start==end)
    {
       // cout<<"start==end"<<endl;
        return createNode(a[start]);
    }
    
    int maxPos = 0;
    for(int i=start;i<=end;i++)
    {
       // cout<<"Loop "<<i<<endl;
        if(a[i]>a[maxPos])
        maxPos = i;
    }
    
    struct node* root = createNode(a[maxPos]);
    root->left = createSpecialInorder(a,start,maxPos-1);
    root->right = createSpecialInorder(a,maxPos+1,end);
    return root;
}

void printInOrder(struct node* root)
{
    if(root == NULL)
    {
       // cout<<"found null"<<endl;
    return;
    }
    
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}

int main() {
    int inorder[] = {5, 10, 40, 30, 28};
    struct node* root = createSpecialInorder(inorder,0,4);
    printInOrder(root);
	return 0;
}
