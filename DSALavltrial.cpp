// AVL TREE
/*
    A Dictionary stores keywords and its meanings.Provide facility for adding new keywords,
    deleting keywords,updating values of any entry.Provide the facility to display thw whole data
    in ascending or descending order. Also find how many maximum comparisons are required 
    for finding any keyword. Use height balance tree and find complexity for finding any keyword.
*/


# include <iostream>
# include <string>
# include <cstring>
using namespace std;

typedef struct node
{
    char k[20];
    char m[30];
    int height;
    class node* left;
    class node* right;
}node;

class AVL
{
    public:
    node *root;
    void create();
    void insert(node *root,node *temp);
    void display(node* root);
    int search (node *r,char []);
    int update (node *r,char []);
    int ht_allot (node *t);
    int ht_find(node *t);
    node *del (node *r,char []);
    node *min (node *r);
    node *llrotation(node *t);
    node *rrrotation(node *t);
    node *rlrotation(node *t);
    node *lrrotation(node *t);
    
};

void AVL::create()
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
            temp->height=1;
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
            temp->height=1;
        else
            insert(root->right,temp);
    }
    
    temp->height=ht_allot(temp);
}

node *AVL::llrotation(node *t)
{
    node *p,*q;
    p=t;
    q=p->left;
    p->left=q->right;
    q->right=p;
    
    return q;
}

node *AVL::rrrotation(node *t)
{
    node *p,*q;
    p=t;
    q=p->right;
    p->right=q->left;
    q->left=p;
    
    return q;
}

node *AVL::lrrotation(node *t)
{
    node *p,*q,*r;
    p=t;
    q=p->left;
    r=p->left->right;

    p -> left = r->right;
        q ->right = r->left;
        r ->right = p;
        r->left = q; 
        
        return r;
}

void AVL::display(node* root)
{
    if (root!=NULL)
    {
        display(root->left);
        cout<<root->k<<endl;
        cout<<root->m<<endl;
        display(root->right);
    }
}

int AVL::search(node* r,char k[20])
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

int AVL::update(node* r,char k[20])
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

node* AVL::del(node * root,char k[20])
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

int AVL::ht_allot (node *t)
{
    if(t->left && t->right)
    {
                    
        if (t->left==NULL && t->right)
            return t->right->height+1;
            
        else if (t->left && t->right==NULL)
            return t->left->height+1;

            
        else if (t->left->height < t->right->height)
            return t->right->height+1;
            
        else
            return t->left->height+1;
                    
    }
    return 0;

}

int AVL::ht_find(node *t)
{
    if(t->left && t->right)
    {
        return t->left->height-t->right->height; 
    }
    else if(t->left && t->right == NULL)
    {
        return t->left->height; 
    }
    else if(t->left== NULL && t->right)
    {
        return t->right->height;
    }
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






