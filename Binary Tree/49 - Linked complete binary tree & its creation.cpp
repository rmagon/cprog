#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
};

bool isComplete(struct node* a)
{
    bool foundIncomplete = false;
    struct node* current = a;
    queue<struct node*> q;

    while(current!=NULL)
    {
        if(current->left != NULL)
        q.push(current->left);
        
        if(current->right != NULL)
        q.push(current->right);
        
        cout<<"Level Order "<<current->data<<endl;
        
        if(current!=NULL)
        {
            if((current->left==NULL)&&(current->right!=NULL))
            return false;
            
            if(foundIncomplete == false)
            {
                if((current->left !=NULL)&&(current->right==NULL))
                {
                    cout<<"Found In Complete :"<<current->data<<endl;
                    foundIncomplete = true;
                }
                if((current->left ==NULL)&&(current->right==NULL))
                {
                    cout<<"Found In Complete :"<<current->data<<endl;
                    foundIncomplete = true;
                }
            }
            else if(foundIncomplete == true)
            {
                if(current->left!=NULL)
                {
                    cout<<"Left is not null for "<<current->data<<endl;
                    return false;
                }
                
                if(current->right!=NULL)
                {
                    cout<<"Right is not null for "<<current->data<<endl;
                    return false;
                }
            }
        }
        
        if(!q.empty())
        {
           
            current = q.front();
             q.pop();
        }
        else
        {
            current = NULL;
        }
    }
    return true;
}

struct node* createNode(int k)
{
    struct node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = k;
    return temp;
}

int main() {
	struct node* root = createNode(1);
	root->right = createNode(3);
	root->left = createNode(2);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->right = createNode(9);
	
	
	bool b = isComplete(root);
	cout<<endl;
	cout<<"is Complete "<<b;
	
	return 0;
}
