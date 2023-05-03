// DSAL C15
/*
You have a business with several offices; you want to 
lease phone lines to connect them up with each other; and the phone company charges different 
amounts of money to connect different pairs of cities. You want a set of lines that connects all 
your offices with a minimum total cost. Solve the problem by suggesting appropriate data 
structures.
*/

# include <iostream>
using namespace std;

class Tree
{
    public:
    int arr[20][20];
    int v,e,weight;
    int v_array[20];
    int up_vertex,low_vertex;

    void tree_create();
    void min_path();
};

void Tree::tree_create()
{
    cout<<"Enter the no. of vertices : "<<endl;
    cin>>v;

    cout<<"Enter the no. of edges : "<<endl;
    cin>>e;

    for (int i=0;i<v;i++)       // initialization of visited array with 0's
    {
        v_array[i]=0;
    }

    cout<<"Contents of visited array before traversal are : "<<endl;
    for (int i=0;i<v;i++)
    {
        cout<<v_array[i]<<" ";
    }cout<<endl;

    for (int i=0;i<v;i++)   // initialization of adjacency matrix with 999's
    {
        for (int j=0;j<v;j++)
        {
            arr[i][j]=999;
        }
    }

    cout<<"Adjacency Matrix initialization : "<<endl;
    for (int i=0;i<v;i++)
    {
        for (int j=0;j<v;j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }

    for (int i=0;i<e;i++)
    {
        cout<<"Enter the vertices present at end point of edges : "<<endl;
        cin>>up_vertex;
        cin>>low_vertex;

        cout<<"Enter the weight present between "<<up_vertex<<" and "<<low_vertex<<" : "<<endl;
        cin>>weight;

        // now we update the adjacency matrix by weight between the vertices
        arr[low_vertex][up_vertex]=arr[up_vertex][low_vertex]=weight;
    }

    cout<<"Adjacency Matrix after updation is : "<<endl;
    for (int i=0;i<v;i++)
    {
        for (int j=0;j<v;j++)
        {
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
}

void Tree::min_path()
{
    int p=0,q=0,total=0,count,min;
    v_array[0]=1;
    
    for (count=0;count<(v-1);count++)
    {
        min=999;
        for (int i=0;i<v;i++)
        {
            if (v_array[i]==1)
            {
                for (int j=0;j<v;j++)
                {
                    if (v_array[j]!=1)
                    {
                        if (min>arr[i][j])
                        {
                            min=arr[i][j];
                            p=i;
                            q=j;
                        }
                    }
                }
            }
        }
        v_array[p]=1;
        v_array[q]=1;
        total=total+min;

        cout<<"The minimum path found is "<<p<<"->"<<q<<" with cost : "<<min<<endl;

    }
    cout<<"The minimum cost after traversal using Prim's algorithm is : "<<total<<endl;
}

int main()
{
    Tree t;
    t.tree_create();
    t.min_path();
    return 0;
}

Output:-
    PS D:\Ayush\Codes\C++ Codes> cd "d:\Ayush\Codes\C++ Codes\" ; if ($?) { g++ prims.cpp -o prims } ; if ($?) { .\prims }
Enter the no. of vertices : 
4
Enter the no. of edges : 
5
Contents of visited array before traversal are : 
0 0 0 0 
Adjacency Matrix initialization : 
999 999 999 999 
999 999 999 999 
999 999 999 999 
999 999 999 999 
Enter the vertices present at end point of edges :
0
1
Enter the weight present between 0 and 1 :
5
Enter the vertices present at end point of edges :
0
2
Enter the weight present between 0 and 2 :
8
Enter the vertices present at end point of edges :
1
2
Enter the weight present between 1 and 2 :
10
Enter the vertices present at end point of edges :
1
3
Enter the weight present between 1 and 3 :
15
Enter the vertices present at end point of edges :
2
3
Enter the weight present between 2 and 3 :
20
Adjacency Matrix after updation is :
999 5 8 999
5 999 10 15
8 10 999 20
999 15 20 999
The minimum path found is 0->1 with cost : 5
The minimum path found is 0->2 with cost : 8
The minimum path found is 1->3 with cost : 15
The minimum cost after traversal using Prim's algorithm is : 28
