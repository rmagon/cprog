#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int k;
	struct node* left,*right;
	int height;
};

void printPreOrder(struct node* root)
{
    if(root == NULL)
    return;
    
    cout<<root->k<<"("<<root->height<<") ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}


struct node* createNode(int k)
{
	node* temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->height = 1;
	temp->k = k;
	return temp;
}

int getHeight(struct node* curr)
{
	if(curr == NULL)
	return 0;
	else 
	return curr->height;
}

int getBalance(struct node* root)
{
	return getHeight(root->left) - getHeight(root->right);
}

struct node* leftRotate(struct node* root)
{
	struct node* T2 = root->right->left;
	struct node* newRoot = root->right;
	
	newRoot->left = root;
	newRoot->left->right = T2;
	
	newRoot->left->height = max(getHeight(newRoot->left->left),getHeight(newRoot->left->right)) +1;
	newRoot->height = max(getHeight(newRoot->left),getHeight(newRoot->right)) + 1;
	
	return newRoot;
}

struct node* rightRotate(struct node* root)
{
	struct node* T2 = root->left->right;
	//cout<<"T2="<<T2->k<<endl;
	struct node* newRoot = root->left;
	
	newRoot->right = root;
	root->left = T2;
	
	newRoot->right->height = max(getHeight(newRoot->right->left),getHeight(newRoot->right->right)) + 1;
	newRoot->height = max(getHeight(newRoot->left),getHeight(newRoot->right)) + 1;
	
	return newRoot;
}

struct node* insert(struct node* root, int k)
{
	if(root == NULL)
	return createNode(k);
	
	if(root->k < k)
	root->right = insert(root->right,k);
	else if(root->k > k)
	root->left = insert(root->left,k);
	
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
	
	int balance = getBalance(root);
//	cout<<"Balance at insert="<<k<<" key="<<root->k<<":"<<balance<<endl;
	if((balance < -1)&&(root->right->k < k))
	{
	//	cout<<"left left"<<endl;
		root = leftRotate(root);
	}
	else if((balance < -1)&&(root->right->k > k))
	{
	//	cout<<"right left"<<endl;
		root->right = rightRotate(root->right);
		root = leftRotate(root);
	}
	else if((balance > 1) && (root->left->k > k))
	{
	//	cout<<"right right"<<endl;
		root = rightRotate(root);
	}
	else if((balance > 1) && (root->left->k < k))
	{
	//	cout<<"left right"<<endl;
		root->left = leftRotate(root->left);
		root = rightRotate(root);
	}
	return root;
}

struct node* inOrderSuccessor(struct node* root)
{
	struct node* succ = root->right;
	while(succ->left != NULL)
	{
		succ = succ->left;
	}
	return succ;
}

struct node* deleteNode(struct node* root, int k)
{
	if(root == NULL)
	return root;
	
	if(root->k > k)
	root->left = deleteNode(root->left,k);
	else if(root->k < k)
	root->right = deleteNode(root->right,k);
	
	else
	{
		if((root->left == NULL)||(root->right == NULL))
		{
			struct node* temp = root->left ?  root->left : root->right;
			struct node* newRoot = temp;
			free(root);
			return temp;
		}
		else
		{
			struct node* succ = inOrderSuccessor(root);
			root->k = succ->k;
			root->right = deleteNode(root->right,succ->k);
		}
	}
	
	if(root==NULL)
	return root;
	
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
	
	int balance = getBalance(root);
	//cout<<"Height of ["<<root->k<<"]="<<root->height<<" Balance="<<balance<<" Balance(left)="<<getBalance(root->left)<<endl;
	// Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        root = rightRotate(root);
 
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
	return root;
}

int getMax(struct node* root)
{
	while(root->right!=NULL)
	{
		root = root->right;
	}
	
	return root->k;
}
void printKMax(int arr[], int n, int k)
{
	struct node* root = NULL;
	for(int i=0;i<k;i++)
	{
		//cout<<arr[i]<<" ";
		root = insert(root,arr[i]);
	}
	
//	root = deleteNode(root,10);
	for(int i=k;i<=n;i++)
	{
	//	cout<<arr[i-k];
		cout<<getMax(root)<<" ";
		root = deleteNode(root,arr[i-k]);
		root = insert(root,arr[i]);
	}
}

int main()
{
	int arr[] = {1, 2, 100, 4, 5, 6, 7, 8, 9, 280};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout<<n<<" "<<k<<endl;
    printKMax(arr, n, k);
    return 0;
}

