#include <iostream>
#include <queue>
using namespace std;
struct node
{
    int data;
    struct node *left,*right;
    struct node* rightNext;
};


void LevelOrder(struct node* a)
{
    int prevlevel = 0,currentLevel = 0;
    queue<struct node*> q;
    queue<int> qLevel;
    struct node* current = a,*prev;
    while(current!=NULL)
    {
        if(current->left!=NULL)
        {
            q.push(current->left);
            qLevel.push(currentLevel+1);
        }
        
        if(current->right!=NULL)
        {
            q.push(current->right);
            qLevel.push(currentLevel+1);
        }
        
        if((currentLevel!=0)&&(currentLevel == prevlevel))
        {
            prev->rightNext = current;
        }
        cout<<current->data;
        
        if(!q.empty())
        {
            prevlevel = currentLevel;
            prev = current;
            currentLevel = qLevel.front();
            current = q.front();
            q.pop();
            qLevel.pop();
        }
        else
        {
            current = NULL;
            
        }
    }
}

struct node* createNode(int k)
{
    struct node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = k;
    temp->rightNext = NULL;
    return temp;
}

void traverse(struct node* start)
{
    while(start!=NULL)
    {
        cout<<start->data;
        start = start->rightNext;
    }
}
int main() {
	struct node* root = createNode(1);
	root->right = createNode(3);
	root->left = createNode(2);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
    root->right->left = createNode(6);
    LevelOrder(root);
	
	cout<<endl<<"Level One ";
	traverse(root->left);
	
	cout<<endl<<"Level Two ";
	traverse(root->left->left);
	
	return 0;
}
