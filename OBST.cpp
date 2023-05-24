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
    int w[10][10],c[10][10],r[10][10],i,j,k,m; 
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
    
    for (i=1;i<=n;i++)
    {
        cin>>values[i];
    }
    cout<<"Enter the values of success : "<<endl;
    for (i=1;i<=n;i++)
        cin>>p[i];

    cout<<"Enter the values of failure : "<<endl;
    for (i=0;i<=n;i++)
        cin>>q[i];
}

void OBST::assign()
{
    for (i=0;i<=n;i++)
    {
        w[i][i]=q[i];
        c[i][i]=r[i][i]=0;
    }
    for (i=0;i<=n;i++)
    {
        for (j=i+1;j<=n;j++)
        {
            w[i][j]=p[j]+q[j]+w[i][i];
            c[i][j]=w[i][j]+c[j][j];
            r[i][j]=j;
        }
    }
    for (m=2;m<=n;m++)
    {
        for (i=0;i<=n;i++)
        {
            j=i+m;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            k=find(i,j);
            r[i][j]=k;
            c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
        }
    }
}

int OBST::find(int i,int j)
{
    int min=2000;
    int l,m;
    for (m=i+1;i<=j;i++)
    {
        if (c[i][m-1]+c[m][i]<min)
        {
            min=c[i][m-1]+c[m][j];
            l=m;
        }
    }
    return l;
}

void OBST::print(int i,int j)
{
    
    if (i<j)
        cout<<"\n"<<values[r[i][j]];
    else
        return;
    print(i,r[i][j]-1);
    print(r[i][j],j);    
    
}



int main()
{
    OBST o;

    o.entry();
    o.print(0,o.n);
    //o.display();
    return 0;
}
