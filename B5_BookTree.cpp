// DSAL TREE PRACTICAL NO. B1
// TREE IMPLEMENTATION

# include <iostream>
# include <string>
using namespace std;


struct node
{
	char label[50];		//for the name of the book 
	int ch_cnt;	// for the no. of children of the root node i.e. the total no. of chapters
	struct node *child[50];	// creating new node for the child nodes
}*root;

class Book
{
	public:
	void create();
	void display(node *r);
	Book()
	{
		root=NULL;
	}
	

	
};

void Book::create()
{
	int total_chaps,total_secns;	//count for the children 
	string chap_name;	//chapter names
	root=new node;		// creating a new node for the root 
	cout<<"Enter the book name : ";
	cin>>root->label;	// storing in the label part of the root node 
	cout<<"\nEnter the total no. of chapters in the book : ";
	cin>>total_chaps;
	root->ch_cnt=total_chaps;	//storing the total chapter cnt in the chapter cnt of root node
	
	for (int i=0;i<total_chaps;i++)
	{
		root->child[i]=new node;	//creating the new node for the child parts of the root
		cout<<"\nEnter the chapter name : ";
		cin>>root->label;
		cout<<"\nEnter the total no. of sections in the chapter : ";
		cin>>root->child[i]->ch_cnt;
		for (int j=0;j<root->child[i]->ch_cnt;j++)
		{
			root->child[i]->child[j]=new node;
			cout<<"\nEnter the name of the sections in the chapter :";
			cin>>root->child[i]->child[j]->label;
		}
		
		
	}		
}

void Book::display(node *r)
{
	int tch;
	string name;
	if (r!=NULL)
	{
		cout<<"Book Tree Hierarchy : "<<endl;
		
		tch=r->ch_cnt;
		for (int i=0;i<tch;i++)
		{
			cout<<"Chapter : "<<i+1<<" "<<r->child[i]->label;
			cout<<r->label;
			cout<<r->child[i]->label<<endl;
			cout<<"\nSections : "<<endl;
			for (int j=0;j<r->child[i]->ch_cnt;j++)
			{
				cout<<"\n"<<r->child[i]->child[j]->label<<endl;
				
			}
		}
	}
}

int main()
{
	Book B;
	int ch,ans;
	do
	{
		cout<<"**********MENU**********"<<endl;
		cout<<"1.Entry in the tree\n2.Display the tree data"<<endl;
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				B.create();
				break;
				
			case 2:
				B.display(root);
				break;
				
			default:
				cout<<"You have entered a wrong choice!!!"<<endl;
				cout<<"Please try again!!"<<endl;
				
		}
		cout<<"\nDo you want to continue???"<<endl;
		cout<<"1.Yes\n2.No"<<endl;
		cin>>ans;
		
		
	}while(ans==1);
	
	if (ans>=2)
		cout<<"Exited successfully!!!"<<endl;
	return 0;
}


