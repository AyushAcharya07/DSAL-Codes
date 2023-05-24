// OBST Program
/*
Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each key ki . 
Build the Binary search tree that has the least search cost given the access probability for each key? 
*/


#include <iostream>
using namespace std;

#define MAX 10

class OBST 
{
	private:
    int p[MAX],q[MAX],w[10][10],c[10][10],r[10][10],i,j,k,n,m;
    char idnt[7][10];

    int find(int i,int j) 
	{
        int min=2000,m,l;
        for (m=i+1;m<=j;m++) 
		{
            if (c[i][m-1]+c[m][j]<min) 
			{
                min=c[i][m-1]+c[m][j];
                l=m;
            }
        }
        return l;
    }

    void print(int i, int j) 
	{
        if (i<j)
            cout<<"\n"<<idnt[r[i][j]];
        else
            return;
        print(i,r[i][j]-1);
        print(r[i][j],j);
    }

	public:
    void run() 
	{
        cout<<"Enter the number of identifiers : "<<endl;
        cin>>n;
        cout<<"Enter the identifiers : "<<endl;
        for (i = 1; i <= n; i++)
            cin>>idnt[i];
        cout<<"Enter success probability for identifiers : "<<endl;
        for (i=1;i<=n;i++)
            cin>>p[i];
        cout<<"Enter failure probability for identifiers : "<<endl;
        for (i=0;i<=n;i++)
            cin>>q[i];

		cout<<endl;
        cout<<"\t\tOBST Calculations : "<<endl;
		cout<<endl;
		cout<<"Weight\t\tCost\t\tRoot"<<endl;
		cout<<endl;

        for (i=0;i<=n;i++) 
		{
            w[i][i]=q[i];
            c[i][i]=r[i][i]=0;
            cout<<"w"<<i<<i<<" "<<w[i][i]<<"\t\tc"<<i<<i<<" "<<c[i][i]<<"\t\tr"<<i<<i<<" "<<r[i][i]<<endl;
			cout<<"----------------------------------------------------------------"<<endl;
        }

        for (i=0;i<n;i++) 
		{
            j=i+1;
            w[i][j]=p[j]+q[j]+w[i][i];
            c[i][j]=w[i][j]+c[j][j];
            r[i][j]=j;
            cout<<"w"<<i<<j<<" "<<w[i][j]<<"\t\tc"<<i<<j<<" "<<c[i][j]<<"\t\tr"<<i<<j<<" "<<r[i][j]<<endl;
			cout<<"----------------------------------------------------------------"<<endl;
        }

        for (m=2;m<=n;m++) {
            for (i=0;i<=n-m;i++) 
			{
                j=i+m;
                w[i][j]=w[i][j-1]+p[j]+q[j];
                k=find(i,j);
                r[i][j]=k;
                c[i][j]=w[i][j]+c[i][k - 1]+c[k][j];
                cout<<"w"<<i<<j<<" "<<w[i][j]<<"\t\tc"<<i<<j<<" "<<c[i][j]<<"\t\tr"<<i<<j<<"  "<<r[i][j]<<endl;
				cout<<"------------------------------------------------------------"<<endl;
            }
        }
		cout<<endl;
        cout<<"\t\tThe OBST is : "<<endl;
        print(0, n);
		cout<<endl;
    }
};

int main() 
{
    OBST obst;
	int ch,ans;
	do
	{
		cout<<"***************MENU***************"<<endl;
		cout<<"1.Create OBST\n2.Exit"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				obst.run();
				break;

			case 2:
				cout<<"\nExiting from the code......................"<<endl;
				exit(0);
				break;

			default:
				cout<<"Entered a wrong choice!!\nPlease try again!!"<<endl;
				break;
		}
		cout<<"\nDo you want to continue?"<<endl;
		cout<<"1.Yes\n2.No"<<endl;
		cin>>ans;
	} while (ans==1);

    return 0;
}
