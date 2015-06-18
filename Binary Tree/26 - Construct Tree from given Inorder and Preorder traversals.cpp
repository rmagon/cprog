#include <iostream>
#include <string>
using namespace std;

struct node
{
    char data;
    struct node* left,*right;
};

struct node* createNode(char k)
{
    struct node* temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->data = k;
    return temp;
}

struct node* createTree(string inO,string preO)
{
    if(inO.length() < 1)
    return NULL;
    
    
    
    char root = preO[0];
    struct node* temp = createNode(root);
    
    if(inO.compare(preO)==0)
    return temp;
    
    string leftInO="",rightInO="";
    string leftPreO="",rightPreO="";
    
    bool flag = false;
    int rootCount = -1;
    for(int i=0;i<inO.length();i++)
    {
        if(inO[i]==preO[0])
        {
            flag = true;
            rootCount = i;
        }
        else if(!flag)
        {
            leftInO = leftInO + inO[i];
        }
        else
        {
            rightInO = rightInO + inO[i];
        }
    }
    
    //cout<<"Root at Position"<<rootCount<<endl;
    flag = false;
    for(int i=1;i<inO.length();i++)
    {
        
        if(!flag)
        {
            leftPreO = leftPreO + preO[i];
        }
        else
        {
            rightPreO = rightPreO + preO[i];
        }
       // cout<<inO[rootCount-1]<<" "<<preO[i]<<endl;
        if(inO[rootCount-1]==preO[i])
        {
            flag = true;
        }
    }
    
    //cout<<"Left In Order "<<leftInO<<endl;
    //cout<<"Left Pre Order "<<leftPreO<<endl;
    //cout<<"Right In Order"<<rightInO<<endl;
    //cout<<"Right Pre Oder"<<rightPreO<<endl;
    temp->left = createTree(leftInO,leftPreO);
    temp->right = createTree(rightInO,rightPreO);
    
    return temp;
}
void printInOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    printInOrder(root->left);
    cout<<root->data<<" ";
    printInOrder(root->right);
}
int main() {
	string inO="DBEAFC";
	string preO="ABDECF";
	
	struct node* root = createTree(inO,preO);
	printInOrder(root);
	return 0;
}
