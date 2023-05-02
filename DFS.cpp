#include <iostream>
#include <string.h>
using namespace std;

int n;
int a_matrix[10][10];
int visited[10],stk[20];;


class Stack
{
    public:
    int top=-1;

    bool isEmpty() 
    {
        return top==-1;
    }

    void push(int value) 
    {
        stk[++top]=value;
    }

    int pop() 
    {
        return stk[top--];
    }
};

class Graph 
{
    public:
    void entry() 
    {
        cout<<"Enter the no. of vertices of the graph: "<<endl;
        cin>>n;
        cout<<"Enter 1 if there is an edge present between the 2 vertices, 0 otherwise: "<<endl;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                int val;
                cout<<"Is there an edge between vertex "<<i<<" and vertex "<<j<<"? (0/1): ";
                cin>>val;
                a_matrix[i][j]=val;
            }
        }

        cout<<"The adjacency matrix is: "<<endl;
        cout<<"* ";
        for (int i=0;i<n;i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;

        for (int i=0;i<n;i++)
        {
            cout<<i<<" ";
            for (int j=0;j<n;j++)
            {
                cout <<a_matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void DFS(int v) 
    {
        Stack s;
        s.push(v);
        visited[v]=1;
        cout<<v<<" ";

        while (!s.isEmpty()) 
        {
            int w=-1;
            int u=s.pop();

            for (int i=0;i<n;i++) 
            {
                if (a_matrix[u][i]==1 && visited[i]==0) 
                {
                    w=i;
                    break;
                }
            }

            if (w!=-1) 
            {
                visited[w]=1;
                cout<<w<<" ";
                s.push(u);
                s.push(w);
            }
        }
    }

    /*void printVisited() 
    {
        cout <<"Visited array : ";
        for (int i=0;i<n;i++) 
        {
            cout<<visited[i]<<" ";
        }
        cout << endl;
    }*/
    void printVisited() 
    {
    cout <<"Visited vertices: ";
    for (int i=0;i<n;i++) 
    {
        if (visited[i]==1)
        {
            cout<<i<<" ";
        }
    }
    cout << endl;
    }

};

int main() 
{
    Graph g;
    g.entry();
    memset(visited, 0, sizeof(visited));

    cout << "Starting DFS from vertex 0: ";
    g.DFS(0);
    cout << endl;
    cout<<"done"<<endl;
    g.printVisited();

    return 0;
}
