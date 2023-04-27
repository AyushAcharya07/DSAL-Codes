/*
    Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse it using post order 
    traversal (non recursive) and then delete the entire tree.
*/
# include <iostream>
# include <string.h>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
    Node()
    {
        left=right=NULL;
    }
};

class Stack
{
    public:
    Node *data[30];
    int top;

    Stack()
    {
        top=-1;
    }

    int isempty()
    {
        if (top==-1)
            return 1;
        else
            return 0;
    }

    int isfull()
    {
        if (top>=30)
            return 1;
        else
            return 0;
    }

    void push(Node *value)
    {
        top++;
        data[top]=value;
    }

    Node *pop()
    {
        return (data[top--]);
    }
};

class exp_tree
{
    public:
    Node *top;
    void expression(char p[]);
    void postorder_traverse(Node *v);
    void del(Node *t);

};

void exp_tree::expression(char p[])
{
    int len=strlen(p);
    Node *a1,*a2;
    Stack s;
    
    for(int i=len-1;i>=0;i--)
    {
        top=new Node();
        if (isalpha(p[i]))
        {
            top->data=p[i];
            s.push(top);
        }

        else if (p[i]=='+' || p[i]=='-' || p[i]=='*' || p[i]=='/' || p[i]=='^' || p[i]=='%')
        {
            a2=s.pop();
            a1=s.pop();
            top->data=p[i];
            top->left=a2;
            top->right=a1;
            s.push(top);
        }

    }
    top=s.pop();

}


void exp_tree::postorder_traverse(Node *v)
{
    Stack s1,s2;
    s1.push(v);
    while(s1.isempty()==0)
    {
        Node *t=s1.pop();
        s2.push(t);
        if (t->left)
            s1.push(t->left);
        if (t->right)
            s1.push(t->right);
    }
    while(s2.isempty()==0)
    {
        v=s2.pop();
        cout<<v->data;
    }
}

void exp_tree::del(Node *t)
{
    if (t==NULL)
        return;
    else
    {
        del(t->left);
        del(t->right);
        free(t);
        
    }//cout<<"Tree deleted successfully!!"<<endl;
}

int main()
{
    exp_tree obj;
    int ch,ans;
    char prefix[30];
    cout<<"Enter the prefix expression :"<<endl;
    cin>>prefix;

    do
    {
        cout<<"**********MENU**********"<<endl;
        cout<<"1.Construct the expression tree\n2.Display the expression\n3.Traverse using postorder traversal\n4.Delete the tree"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                obj.expression(prefix);
                cout<<"\nExpression tree created successfully from given expression!!"<<endl;
                break;

            case 2:
                cout<<"The prefix expression is : "<<prefix<<endl;
                break;

            case 3:
                cout<<"The expression tree traversal is : ";
                obj.postorder_traverse(obj.top);
                break;

            case 4:
                obj.del(obj.top);
                cout<<"The tree is deleted successfully!!"<<endl;
                break;

            default:
                cout<<"You have entered a wrong choice!!\nPlease try again"<<endl;
                break;
        }
        cout<<"\nDo you want to continue?\n1.Yes\n2.No"<<endl;
        cin>>ans;
    }while(ans==1);

    if (ans==2)
        cout<<"Exited successfully!!"<<endl;

    return 0;
}