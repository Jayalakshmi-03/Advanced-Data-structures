#include<iostream>
using namespace std;

class node
{
 public:
  int data;
  node*left;
  node*right;
  int height;
};

int height(node *N)
{
 if (N == NULL)
  return 0;
 return N->height;
}

node *rightRotate(node *y)
{
 node *x = y->left;
 node *T2 = x->right;
 x->right = y;
 y->left = T2;
 y->height = max(height(y->left),
 height(y->right)) + 1;
 x->height = max(height(x->left),
 height(x->right)) + 1;
 return x;
}

node *leftRotate(node *x)
{
 node *y = x->right;
 node *T2 = y->left;
 y->left = x;
 x->right = T2;
 x->height = max(height(x->left),
 height(x->right)) + 1;
 y->height = max(height(y->left),
 height(y->right)) + 1;
 return y;
}

int getBalance(node *N)
{
 if (N == NULL)
  return 0;
 return height(N->left) - height(N->right);
}

node*Insnode(node *root,int data)
{
 if(root==NULL)
 {
 node*nn=new node();
 nn->data=data;
 nn->left=nn->right=NULL;
 root=nn;
 return root;
 }
 if(root->data<data)
   root->right=Insnode(root->right,data);
 else if(root->data>data)
   root->left=Insnode(root->left,data);
 root->height = 1 + max(height(root->left),
 height(root->right));
 int balance = getBalance(root);
 if (balance > 1 && data < root->left->data)
   return rightRotate(root);
 if (balance < -1 && data > root->right->data)
   return leftRotate(root);
 if (balance > 1 && data > root->left->data)
 {
   root->left = leftRotate(root->left);
   return rightRotate(root);
 }
 if (balance < -1 && data < root->right->data)
 {
  root->right = rightRotate(root->right);
  return leftRotate(root);
 }
 return root;
}

void searchh(node *root, int d)
{
 int depth = 0;
 node *temp = new node;
 temp = root;
 while(temp != NULL)
 {
  depth++;
  if(temp->data == d)
  {
    cout<<"\nData found at depth: "<<depth;
    return;
  }
  else if(temp->data > d)
    temp = temp->left;
  else
    temp = temp->right;
 }
 cout<<"\nData not found";
 return;
}

node*minValue(node* root)
{
 node* current = root;
 while (current && current->left != NULL)
   current = current->left;
 return current;
}

node*deletenode(node* root, int data)
{
 if (root == NULL)
   {cout<<"No element to delete"; return root;}
 if (data < root->data)
   root->left = deletenode(root->left, data);
 else if (data > root->data)
   root->right = deletenode(root->right, data);
 else
 {
   if (root->left==NULL and root->right==NULL)
     return NULL;
   else if (root->left == NULL)
   {
    node* temp = root->right;
    delete(root);
    cout<<"Node deleted";
    return temp;
   }
   else if (root->right == NULL)
   {
    node* temp = root->left;
    delete (root);
    cout<<"Node deleted";
    return temp;
   }
   node* temp = minValue(root->right);
   root->data = temp->data;
   root->right = deletenode(root->right, temp->data);
 }
 root->height = 1 + max(height(root->left), height(root->right));
 int balance = getBalance(root);
 if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);
 if (balance > 1 && getBalance(root->left) < 0)
 {
    root->left = leftRotate(root->left);
    return rightRotate(root);
 }
 if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);
 if (balance < -1 && getBalance(root->right) > 0)
 {
    root->right = rightRotate(root->right);
    return leftRotate(root);
 }
 return root;
}

node* inorder(node*root)
{
 if (root == NULL)
    return 0;
 inorder(root->left);
 cout<<root->data<<" ";
 inorder(root->right);
}

int main()
{
 int choice=0;
 int data,s,del;
 node*root=NULL;
 while(choice!=5)
 {
  cout<<"\n1.Insert\n2.Search\n3.Delete\n4.Display";
  cout<<"\nEnter your Choice: ";
  cin>>choice;
  switch(choice)
  {
  case 1:
     cout<<"\nEnter element to insert:";
     cin>>data;
     root=Insnode(root,data);
     cout<<"Elements are: ";
     inorder(root);
     break;

  case 2:
    cout<<"\nEnter Element to search: ";
    cin>>s;
    searchh(root,s);
    break;

  case 3:
    cout<<"\nEnter element to delete: ";
    cin>>del;
    root=deletenode(root, del);
    break;

  case 4:
    inorder(root);
    break;

  case 5:
    break;
  }
 }
 return 0;
}
