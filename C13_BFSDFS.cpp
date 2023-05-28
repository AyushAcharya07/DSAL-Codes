#include <iostream>
#include <string.h>
# include <cstring>

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

class Queue {
private:
    int front, rear;
    int* array;
public:
    Queue() {
        front = rear = -1;
        array = new int[100];
    }

    bool is_full() {
        return (rear == 99);
    }

    bool is_empty() {
        return (front == -1);
    }
    void enqueue(int item) {
        if (is_full()) {
            cout << "Queue is full." << endl;
            return;
        }
        rear++;
        array[rear] = item;
        if (front == -1) {
            front = 0;
        }
    }

    int dequeue() {
        if (is_empty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int item = array[front];
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
        return item;
    }
};

void add_edge(int** adj_list, int src, int dest) {
    adj_list[src][++adj_list[src][0]] = dest;
}

void bfs(int** adj_list, int num_vertices, int start_vertex) {
    bool* visited = new bool[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = false;
    }
 Queue q;
    visited[start_vertex] = true;
    q.enqueue(start_vertex);
    while (!q.is_empty()) {
        int curr_vertex = q.dequeue();
        cout << curr_vertex << " ";
        for (int i = 1; i <= adj_list[curr_vertex][0]; i++) {
            int adj_vertex = adj_list[curr_vertex][i];
            if (!visited[adj_vertex]) {
                visited[adj_vertex] = true;
                q.enqueue(adj_vertex);
            }
        }
    }
    cout << endl;
    delete[] visited;
}


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
    
    int num_vertices, num_edges;
    int** adj_list = new int*[num_vertices];
    int ch;
    bool value=true;

    while (value)
    {
        cout<<"**********MENU**********"<<endl;
        cout<<"1.Using DFS\n2.Using BFS\n3.Exit"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                g.entry();
                for (int i=0;i<10;i++)
                {
                    visited[i]=0;
                }
                cout<<"Starting DFS from vertex 0 : "<<endl;
                g.DFS(0);
                cout<<endl;
                g.printVisited();

                break;

            case 2:

                cout << "Enter the number of vertices in the graph: ";
                cin >> num_vertices;
                
                for (int i = 0; i < num_vertices; i++) {
                    adj_list[i] = new int[num_vertices + 1];
                    adj_list[i][0] = 0;
                }
                for (int src = 0; src < num_vertices; src++) {
                    for (int dest = 0; dest < num_vertices; dest++) {
                        int edge_present;
                        cout << "Is there an edge from " << src << " to " << dest << "? (1 for yes, 0 for no, -1 to exit) ";
                        cin >> edge_present;
                        if (edge_present == 1) {
                            add_edge(adj_list, src, dest);
                        } else if (edge_present == -1) {
                            break;
                        }
                    }
                }
            cout << "Adjacency list:" << endl;
                for (int i =0; i < num_vertices; i++) {
                cout << i << ": ";
                for (int j = 1; j <= adj_list[i][0]; j++) {
                    cout << adj_list[i][j] << " ";
                    }
                cout << endl;
                }
                int start_vertex;
            cout << "Enter the starting vertex for BFS: ";
            cin >> start_vertex;

            bfs(adj_list, num_vertices, start_vertex);

            // deallocating memory
            for (int i = 0; i < num_vertices; i++) {
                delete[] adj_list[i];
            }
            delete[] adj_list;

            break;

        case 3:
            cout<<"Exited successfully!!"<<endl;
            exit(0);

        default:
            value=false;
            break;



        }
    }
    

    return 0;
}
