
#include <iostream>
#include <string>

#define MAX 20

#define SERIOUS 10
#define NONSERIOUS 5  
#define GENERAL 1    

using namespace std;

class Queue
{
    public:
    string Q[MAX];
    int Pr[MAX];
    int rear, front;

    Queue()
    {
        rear = front = -1;
    }

    int isempty()
    {
        if (front == -1)
            return 1;
        else
            return 0;
    }

    int isfull()
    {
        if (front == 0 && rear == MAX - 1)
            return 1;
        else
            return 0;
    }

    void enqueue(string data, int p)
    {
        int i;
        if (isfull() == 1)
            cout << "\n\tQueue is full!" << endl;
        else
        {
            if (isempty() == 1)
            {
                front = rear = 0;
                Q[rear] = data;
                Pr[rear] = p;
            }
            else if (rear == MAX - 1)
            {
                for (i = front; i <= rear; i++)
                {
                    Q[i - front] = Q[i];
                    Pr[i - front] = Pr[i];
                }
                rear = rear - front;
                front = 0;
                for (i = rear; i > front; i--)
                {
                    if (p > Pr[i])
                    {
                        Q[i + 1] = Q[i];
                        Pr[i + 1] = Pr[i];
                    }
                    else
                        break;
                }
                Q[i + 1] = data;
                Pr[i + 1] = p;
                rear++;
            }
            else
            {
                for (i = rear; i >= front; i--)
                {
                    if (p > Pr[i])
                    {
                        Q[i + 1] = Q[i];
                        Pr[i + 1] = Pr[i];
                    }
                    else
                        break;
                }
                Q[i + 1] = data;
                Pr[i + 1] = p;
                rear++;
            }
        }
    }

    void print()
    {
        int i;
        for (i = front; i <= rear; i++)
        {
            cout << "\n\t Patient's Name : " << Q[i];
            switch (Pr[i])
            {
                case GENERAL:
                    cout << "\n\t Priority : \t 'General'" << endl;
                    cout<<"-------------------------------------------------"<<endl;
                    break;

                case NONSERIOUS:
                    cout << "\n\t Priority : \t 'Non-serious'" << endl;
                    cout<<"-------------------------------------------------"<<endl;
                    break;

                case SERIOUS:
                    cout << "\n\t Priority : \t 'Serious'" << endl;
                    cout<<"-------------------------------------------------"<<endl;
                    break;

                default:
                    cout << "\n\t Priority not found !" << endl;
                    cout<<"-------------------------------------------------"<<endl;
                    break;
            }
        }
    }

    void dequeue()
    {
        if (isempty() == 1)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            cout << "Deleted Patient Record : " << Q[front] << endl;
            cout << "Priority : " << Pr[front] << endl;
            if (front == rear)
                front = rear = -1;
            else
                front++;
        }
    }
};

int main()
{
    Queue q;
    string data;
    int opt, n, i, p;
    bool value = true;

    while (value)
    {
        cout << "\n***************MENU***************" << endl;
        cout << "1. Insert Data in Queue" << endl;
        cout << "2. Display the Queue" << endl;
        cout << "3. Delete Data from Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> opt;
        switch (opt)
        {
        case 1:
            cout << "\nEnter the number of patients : ";
            cin >> n;
            i = 0;
            while (i < n)
            {
                cout << "\nEnter the name of the patient : ";
                cin >> data;
                ifnotdoagain:
                cout<<"\n\t0.Serious\n\t1.Non-Serious\n\t2.General Checkup\n\tEnter your choice : ";
                cin >> p;
                switch (p)
                {
                case 0:
                    q.enqueue(data, SERIOUS);
                    break;
                case 1:
                    q.enqueue(data, NONSERIOUS);
                    break;
                case 2:
                    q.enqueue(data, GENERAL);
                    break;
                default:
                    goto ifnotdoagain;
                }
                i++;
            }
            break;

        case 2:
            q.print();
            break;

        case 3:
            q.dequeue();
            break;

        case 4:
            cout << "Exiting from the Code......." << endl;
            value = false;
            break;

        default:
            cout << "Incorrect Choice Entered!" << endl;
            break;
        }
    }
    return 0;
}
