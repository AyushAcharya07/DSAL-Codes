// OBST Code

/*
    Given sequence k = k1 <k2 < ... <kn of n sorted keys, with a search probability pi for each
    key ki . Build the Binary search tree that has the least search cost given the access
    probability for each key?
*/

# include <iostream>
using namespace std;

class OBST
{
    public:
    int n;
    int p[10],q[10];
    string values[10];
    int w[10][10],c[10][10],r[10][10];
    
    void entry();
    void assign();
    int find(int a,int b);
    void print(int a,int b);
    void display();
    
    
};

void OBST::entry()
{
    cout<<"Enter the no. of values in the OBST : "<<endl;
    cin>>n;
    cout<<"Enter the values : "<<endl;
    
    for (int i=1;i<=n;i++)
    {
        cin>>values[i];
    }
    cout<<"Enter the values of success : "<<endl;
    for (int i=1;i<=n;i++)
        cin>>p[i];

    cout<<"Enter the values of failure : "<<endl;
    for (int i=0;i<=n;i++)
        cin>>q[i];
}

void OBST::assign()
{
    for (int i=0;i<=n;i++)
    {
        w[i][i]=q[i];
        c[i][i]=r[i][i]=0;
    }
    for (int i=0;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            w[i][j]=p[j]+q[i]+q[j];
            c[i][j]=q[i]+c[i][j-1]+c[j][j];
            r[i][j]=j;
        }
    }
    for (int m=2;m<=n;m++)
    {
        for (int i=0;i<=n;i++)
        {
            int j=i+m;
            w[i][j]=w[i][j-1]+p[i]+q[j];
            int k=find(i,j);
            r[i][j]=k;
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
        }
    }
}

int OBST::find(int a,int b)
{
    int min=1000;
    int l;
    for (int m=a+1;m<=b;m++)
    {
        if (c[a][m-1]+c[m][b]<min)
        {
            min=c[a][m-1]+c[m][b];
            l=m;
        }
    }
    return l;
}

void OBST::print(int a,int b)
{
    if (a<b)
        cout<<"\n"<<values[r[a][b]];
    else
        return;
    print(a,r[a][b]-1);
    print(r[a][b],b);    
    
}

int main()
{
    OBST o;
    o.entry();
    return 0;
}
