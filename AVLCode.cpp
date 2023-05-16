// AVL TREE
/*
    A Dictionary stores keywords and its meanings.Provide facility for adding new keywords,
    deleting keywords,updating values of any entry.Provide the facility to display thw whole data
    in ascending or descending order. Also find how many maximum comparisons are required 
    for finding any keyword. Use height balance tree and find complexity for finding any keyword.
*/


# include <iostream>
using namespace std;

class Node
{
   public:
   string key;
   string meaning;
   Node *left;
   Node *right; 
};

class AVL
{
    Node *root;
    public:
    
    AVL()
    {
        root=NULL;
    }

    void create();
    void ascending(Node *temp);
    void descending(Node *temp);
    void display();
    void search();
    void del();

    Node *delete_n(Node *temp,string word);
    Node *insert(Node *r,Node *temp);
    Node *balance(Node *temp);
    Node *min(Node *temp);
    Node *LL(Node *temp);
    Node *RR(Node *temp);
    Node *LR(Node *temp);
    Node *RL(Node *temp);

    int difference(Node *temp);
    int height(Node *temp);
    int maximum(int a,int b);

    bool search_value(Node *temp,string word);


};

void AVL::create()
{
    int ans;
    Node *temp;
    do
    {
        temp=new Node();
        cout<<"Enter the keyword : "<<endl;
        cin>>temp->key;
        cout<<"Enter the meaning : "<<endl;
        cin>>temp->meaning;
        temp->left=temp->right=NULL;

        root=insert(root,temp);
        cout<<"\nDo you want to insert more keywords??"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;

    } while(ans==1);
}

Node *AVL::insert(Node *r,Node *temp)
{
    if (r==NULL)
        return temp;

    if (temp->key<r->key)
    {
        r->left=insert(r->left,temp);
        r=balance(r);
    }

    else if(temp->key>r->key)
    {
        r->right=insert(r->right,temp);
        r=balance(r);
    }
    return r;
}

Node *AVL::balance(Node *temp)
{
    int b;
    b=difference(temp);

    if (b>=2)
    {
        if (difference(temp->left)<0)
        {
            temp=LR(temp);
        }
        else
        {
            temp=LL(temp);
        }
    }

    else if(b<=-2)
    {
        if (difference(temp->right)<0)
        {
            temp=RR(temp);
        }
        else
        {
            temp=RL(temp);
        }
    }
    return temp;
}

int AVL::height(Node *temp)
{
    if (temp==NULL)
        return -1;

    else
        return (max(height(temp->left),height(temp->right))+1);
}

int AVL::difference(Node *temp)
{
    int l,r;
    l=height(temp->left);
    r=height(temp->right);
    return l-r;
}

int AVL::maximum(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}

Node *AVL::LL(Node *temp)
{
    Node *temp1,*temp2;
    temp1=temp->left;
    temp2=temp1->right;
    temp1->right=temp;
    temp->left=temp2;
    return temp1;
}

Node *AVL::RR(Node *temp)
{
    Node *temp1,*temp2;
    temp1=temp->right;
    temp2=temp1->left;
    temp1->left=temp;
    temp->right=temp2;
    return temp1;
}

Node *AVL::RL(Node *temp)
{
    temp->right=LL(temp->right);
    return RR(temp);
}

Node *AVL::LR(Node *temp)
{
    temp->left=RR(temp->left);
    return LL(temp);
}

void AVL::ascending(Node *temp)
{
    if (temp!=NULL)
    {
        ascending(temp->left);
        cout<<"\n\t"<<temp->key<<"\t: "<<temp->meaning<<endl;
        ascending(temp->right);
    }
}

void AVL::descending(Node *temp)
{
    if (temp!=NULL)
    {
        descending(temp->right);
        cout<<"\n\t"<<temp->key<<"\t: "<<temp->meaning<<endl;
        descending(temp->left);
    }
}

void AVL::display()
{
    int ch,ans;
    do
    {
        cout<<"Enter the choice to display the AVL Tree!!"<<endl;
        cout<<"1.Ascending order\n2.Descending Order"<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:
                cout<<"\n The keywords in ascending order are : \n";
                ascending(root);
                break;

            case 2:
                cout<<"\n The keywords in descending order are : \n";
                descending(root);
                break;

            default:
                cout<<"Wrong choice entered!!"<<endl;
                break;
        }cout<<"\nDo you want to continue to display??"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;
    }while(ans==1);
                

}

bool AVL::search_value(Node *temp,string word)
{
    if (temp)
    {
        if (temp->key==word)
            return true;
        
        if (temp->key>word)
            return search_value(temp->left,word);
        
        else
            return search_value(temp->right,word);
        
    }
    return false;
}


void AVL::search()
{
    string word;
    cout<<"\nEnter the keyword you want to search : "<<endl;
    cin>>word;
    if (search_value(root,word))
        cout<<"\nThe keyword is present in the AVL Tree!!!"<<endl;
    else
        cout<<"\nThe keyword is not present in the AVL Tree!!!"<<endl;

}

Node *AVL::min(Node *temp)
{
    if (!temp->left)
        return temp->right;

    temp->left=min(temp->left);
    return balance(temp);

}

Node *AVL::delete_n(Node *temp,string word)
{
    if (!temp)
        return temp;

    if (word<temp->key)
        temp->left=delete_n(temp->left,word);

    else if(word>temp->key)
        temp->right=delete_n(temp->right,word);

    else
    {
        Node *l=temp->left;
        Node *r=temp->right;
        delete temp;
        if (!r)
            return l;
        Node *m=r;

        while (m->left)
            m=m->left;
        m->right=min(r);
        m->left=l;
        return balance(m);
    }
    return balance(temp);
}

void AVL::del()
{
    string word;
    cout<<"\nEnter the keyword you want to delete : "<<endl;
    cin>>word;
    root=delete_n(root,word);
    cout<<endl;
    cout<<word<<" successfully deleted from the AVL Tree"<<endl;
}

int main()
{
    AVL a;
    int ch,ans;
    do
    {
        cout<<"********************MENU********************"<<endl;
        cout<<"1.Add new entry\n2.Display the dictionary\n3.Search a keyword\n4.Delete a keyword\n5.Exit"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:
                a.create();
                break;

            case 2:
                a.display();
                break;

            case 3:
                a.search();
                break;

            case 4:
                a.del();
                break;

            case 5:
                cout<<"Exiting from the code............."<<endl;
                exit(0);
                break;

            default:
                cout<<"\nWrong choice entered\nPlease try again"<<endl;
                break;
        }
        cout<<"\nDo you want to continue??"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;
    } while (ans==1);
}

OUTPUT:-
PS D:\Ayush\Codes\C++ Codes> cd "d:\Ayush\Codes\C++ Codes\" ; if ($?) { g++ avltree.cpp -o avltree } ; if ($?) { .\avltree }
********************MENU********************
1.Add new entry
2.Display the dictionary
3.Search a keyword
4.Delete a keyword
5.Exit
Enter your choice : 
1
Enter the keyword : 
B
Enter the meaning : 
BOOK

Do you want to insert more keywords??
1.Yes
2.No
1
Enter the keyword :
G
Enter the meaning :
GINGER

Do you want to insert more keywords??
1.Yes
2.No
1
Enter the keyword :
E
Enter the meaning :
EAGLE

Do you want to insert more keywords??
1.Yes
2.No
1
Enter the keyword :
A
Enter the meaning :
ASTEROID

Do you want to insert more keywords??
1.Yes
2.No
1
Enter the keyword :
M
Enter the meaning :
MONKEY

Do you want to insert more keywords??
1.Yes
2.No
1
Enter the keyword :
Y
Enter the meaning :
YAK

Do you want to insert more keywords??
1.Yes
2.No
2

Do you want to continue??
1.Yes
2.No
1
********************MENU********************
1.Add new entry
2.Display the dictionary
3.Search a keyword
4.Delete a keyword
5.Exit
Enter your choice :
2
Enter the choice to display the AVL Tree!!
1.Ascending order
2.Descending Order
1

 The keywords in ascending order are :

        A       : ASTEROID

        B       : BOOK

        E       : EAGLE

        G       : GINGER

        M       : MONKEY

        Y       : YAK

Do you want to continue to display??
1.Yes
2.No
1
Enter the choice to display the AVL Tree!!
1.Ascending order
2.Descending Order
2

 The keywords in descending order are :

        Y       : YAK

        M       : MONKEY

        G       : GINGER

        E       : EAGLE

        B       : BOOK

        A       : ASTEROID

Do you want to continue to display??
1.Yes
2.No
2

Do you want to continue??
1.Yes
2.No
1
********************MENU********************
1.Add new entry
2.Display the dictionary
3.Search a keyword
4.Delete a keyword
5.Exit
Enter your choice :
3

Enter the keyword you want to search :
Y

The keyword is present in the AVL Tree!!!

Do you want to continue??
1.Yes
2.No
1
********************MENU********************
1.Add new entry
2.Display the dictionary
3.Search a keyword
4.Delete a keyword
5.Exit
Enter your choice :
4

Enter the keyword you want to delete :
M

M successfully deleted from the AVL Tree

Do you want to continue??
1.Yes
2.No
1
********************MENU********************
1.Add new entry
2.Display the dictionary
3.Search a keyword
4.Delete a keyword
5.Exit
Enter your choice :
2
Enter the choice to display the AVL Tree!!
1.Ascending order
2.Descending Order
2

 The keywords in descending order are :

        Y       : YAK

        G       : GINGER

        E       : EAGLE

        B       : BOOK

        A       : ASTEROID

Do you want to continue to display??
1.Yes
2.No
2

Do you want to continue??
1.Yes
2.No
1
********************MENU********************
1.Add new entry
2.Display the dictionary
3.Search a keyword
4.Delete a keyword
5.Exit
Enter your choice :
5
Exiting from the code.............
