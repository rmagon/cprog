#include <iostream>
using namespace std;
struct node
{
    int key;
    struct node* left,*right;
};

struct node* createNode(int k)
{
    struct node* no = new node;
    no->key = k;
    no->left = NULL;
    no->right = NULL;
    return no;
}

struct node* insertRecur(struct node* root, int k)
{
    if(root==NULL)
    return createNode(k);
    
    if(root->key>k)
    root->left = insertRecur(root->left,k);
    else
    root->right = insertRecur(root->right,k);
    
    return root;
}
struct node* insert(struct node* root, int k)
{
    if(root==NULL)
    return createNode(k);
    else
    {
        struct node* temp = root,*parent;
        
        while(temp!=NULL)
        {
            parent = temp;
            if (temp->key > k)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        
        if(parent->key > k)
        parent->left = createNode(k);
        else
        parent->right = createNode(k);
    }
}

void printInOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);
}

void search(struct node* root,int k)
{
    if(root==NULL)
    {
    cout<<"Not Found"<<endl;
    return;
    }
    
    if(root->key > k)
    search(root->left,k);
    else if(root->key < k)
    search(root->right,k);
    else if(root->key ==k)
    cout<<"Found "<<k<<endl;
    
    return;
    
}
int main() {
	struct node *root = NULL;
    root = insertRecur(root, 50);
    insertRecur(root, 30);
    insertRecur(root, 20);
    insertRecur(root, 40);
    insertRecur(root, 70);
    insertRecur(root, 60);
    insertRecur(root, 80);
    
    printInOrder(root);
    
    search(root,70);
	return 0;
}
