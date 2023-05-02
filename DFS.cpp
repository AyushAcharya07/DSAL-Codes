# include <iostream>
# include <string.h>
using namespace std;

int n;
int a_matrix[10][10];
int stk[20],v_array[20];

class adj_mat
{
    public:
    void entry()
    {
        cout<<"Enter the no. of vertices of the graph : "<<endl;
        cin>>n;
        cout<<"Enter 1 if there is an edge present between the 2 vertices : "<<endl;
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a_matrix[i][j];
            }
        }

        cout<<"The adjacency matrix is :"<<endl;
        cout<<"* "<<n-n<<" "<<n-2<<" "<<n-1<<endl;

        for (int i=0;i<n;i++)
        {
            cout<<i<<" ";
            for (int j=0;j<n;j++)
            {
                cout<<a_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

class stack
{
    public:
    int top;
    stack()
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
        if (top==n)
            return 1;
        else
            return 0;
    }

    void push(int value)
    {
        if (isfull()==1)
            cout<<"Stack is full"<<endl;
        else
        {
            top++;
            stk[top]=value;
        }
    }

    void pop()
    {
        int value;
        if (isempty()==1)
            cout<<"Stack is empty"<<endl;
        else
        {
            value=stk[top];
            top--;
        }
    }
};

class DFS
{
    public:
    adj_mat a;
    stack s;
    void convert()
    {
        a.entry();
        int i=0;
    }
};
