/*
A Dictionary stores keywords and its meanings. Provide facility for adding new
keywords, deleting keywords, updating values of any entry. Provide facility to display
whole data sorted in ascending/ Descending order. Also find how many maximum
comparisons may require for finding any keyword. Use Binary Search Tree for
implementation.
*/

# include <iostream>
# include <string>
# include <cstring>
using namespace std;

typedef struct node
{
    char k[20];
    char m[30];
    class node* left;
    class node* right;
}node;

class dictionary
{
    public:
    node *root;
    void create();
    void insert(node* root,node* temp);
    void display(node* );
    int search(node* ,char []);
    int update(node*,char []);
    node* del (node* ,char []);
    node* min(node *);
    
};

void dictionary::create()
{
    class node* temp;
    int ch;
    do
    {
        temp=new node;
        cout<<"Enter the keyword :";
        cin>>temp->k;
        cout<<endl;
        cout<<"Enter the meaning : ";
        cin>>temp->m;
        temp->left=NULL;
        temp->right=NULL;
        if (root==NULL)
            root=temp;
        else
            insert(root,temp);
            
        cout<<"Do you want to continue adding new entries?\n1.Yes\n2.No"<<endl;
        cin>>ch;
        
    }while (ch==1);
}

void dictionary::insert(node* root,node* temp)
{
    if (strcmp(temp->k,root->k)<0)
    {
        if (root->left==NULL)
        {
            root->left=temp;
        }
        else
        {
            insert(root->left,temp);
        }
    }
    else
    {
        if(root->right==NULL)
            root->right=temp;
        else
            insert(root->right,temp);
    }
}

void dictionary::display(node* root)
{
    if (root!=NULL)
    {
        display(root->left);
        cout<<root->k<<endl;
        cout<<root->m<<endl;
        display(root->right);
    }
}

int dictionary::search(node* r,char k[20])
{
    int c=0;
    while (r!=NULL)
    {
        c++;
        if (strcmp(k,r->k)==0)
        {
            cout<<"\nNo. of comparisons : "<<c<<endl;
            return 1;
        }
        else if (strcmp(k,r->k)<0)
            r=r->left;
            
        else if (strcmp(k,r->k)>0)
            r=r->right;
    }
    return -1;
}

node* dictionary::min(node *temp)
{
    while (temp!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}

int dictionary::update(node* r,char k[20])
{
    while(r!=NULL)
    {
        if (strcmp(k,r->k)==0)
        {
            cout<<"\nEnter the new meaning of keyword ' "<<r->k<<" ' "<<endl;
            cin>>r->m;
            return 1;
        }
        
        if (strcmp(k,r->k)<0)
        {
            r=r->left;
        }
        
        if (strcmp(k,r->k)>0)
        {
            r=r->right;
        }
    }
    return -1;
}

node* dictionary::del(node * root,char k[20])
{
    node *temp;
    if (root==NULL)
    {
        cout<<"\nElement not found as tree is empty!!"<<endl;
        return root;
    }
    
    if (strcmp(k,root->k)<0)
    {
        root->left=del(root->left,k);
        return root;
    }
    
    if (strcmp(k,root->k)>0)
    {
        root->right=del(root->right,k);
        return root;
    }
    
    if (root->right==NULL && root->left==NULL)      //root is childless
    {
        temp=root;
        delete temp;
        return NULL;
    }
    
    if (root->right==NULL)          //this means only left child present
    {
        temp=root;
        root=root->left;
        delete temp;
        return root;
    }
    
    else if (root->left==NULL)           //this means only right child is present
    {
        temp=root;
        root=root->right;
        delete temp;
        return root;
        
    }
    
    temp=min(root->right);
    strcpy(root->k,temp->k);
    root->right=del(root->right,temp->k);
    return root;
    
    
}

int main()
{
    dictionary d;
    d.root=NULL;
    char k[20];
    char b[20];
    char u[20];
    int ch,ans;
    do
    {
        cout<<"*********MENU*********"<<endl;
        cout<<"1.Create the tree\n2.Display tree\n3.Search in the tree\n4.Delete the root\n5.Update the tree"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        
        switch(ch)
        {
            case 1:
                d.create();
                break;
                
            case 2:
                if (d.root==NULL)
                    cout<<"\nDictionary is empty!!"<<endl;
                else
                    d.display(d.root);
                    
                break;
                
            case 3:
                cout<<"\nEnter the value of the key : ";
                cin>>k;
                if(d.search(d.root,k)==1)
                    cout<<k<<" is found in the dictionary!! "<<endl;
                else
                    cout<<k<<" not found in the dictionary!!"<<endl;
                    
                break;
                
            case 4:
                cout<<"\nEnter the key value you want to delete : ";
                cin>>b;
                if (d.root==NULL)
                    cout<<"Dictionary is empty!\nTry again"<<endl;
                else
                {
                    d.root=d.del(d.root,b);
                }
                
                break;
                
            case 5:
                if (d.root==NULL)
                {
                    cout<<"Empty\nTry again after adding new enrties !!"<<endl;
                }
                else
                {
                    cout<<"Enter the keyword for which meaning has to be updated : "<<endl;
                    cin>>u;

                    if (d.update(d.root,u)==1)
                        cout<<"\nMeaning updated"<<endl;
                    else
                        cout<<"meaning not found"<<endl;
                    


                }
                break;
                
            default:
                cout<<"\nYou have entered a wrong choice!!\nPlease try again!!"<<endl;
                break;
        }
        cout<<"\nDo you want to continue??\n1.Yes\n2.No"<<endl;
        cin>>ans;
    }while (ans==1);
   
    if (ans==2)
        cout<<"Exited successfully!!"<<endl;
    return 0;
}