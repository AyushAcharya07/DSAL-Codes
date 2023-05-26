// Sequential File

/*
Department maintains a student information. The file 
contains roll number, name, division, and address. Allow user to add delete information of 
student. Display information of particular student. If record of student does not exist an 
appropriate message is displayed. If it is, then the system displays the student details. Use 
sequential file to maintain the data.
*/

# include <iostream>
# include <fstream>
# include <string.h>
# include <string>

using namespace std;

struct stud
{
    int roll_no;
    char name[20];
    char div[6];
    char address[20];
};

class Student
{
    public:
    stud rec;
    ofstream write;
    ifstream read;
    fstream f;

    void create();
    void append();
    void display();
    int search(int);
    void del();
};

void Student::create()
{
    string ans;
    
    write.open("Students.txt",ios::out);
    do
    {
        cout<<"\nEnter the Name of the Student : "<<endl;
        cin>>rec.name;
        cout<<"Enter the Roll No. of the Student : "<<endl;
        cin>>rec.roll_no;
        cout<<"Enter the Class and Division of the Student : "<<endl;
        cin>>rec.div;
        cout<<"Enter the Address of the Student : "<<endl;
        cin>>rec.address;

        write.write((char *)&rec,sizeof(stud))<<flush;

        cout<<"Do you want to add more??"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;

    }while (ans=="1");
    write.close();
    cout<<"File closed successfully after writing the data!!"<<endl;

}

void Student::append()
{
    string ans;
    
    write.open("Students.txt",ios::app);
    do
    {
        cout<<"\nEnter the Name of the Student : "<<endl;
        cin>>rec.name;
        cout<<"Enter the Roll No. of the Student : "<<endl;
        cin>>rec.roll_no;
        cout<<"Enter the Class and Division of the Student : "<<endl;
        cin>>rec.div;
        cout<<"Enter the Address of the Student : "<<endl;
        cin>>rec.address;

        write.write((char *)&rec,sizeof(stud))<<flush;

        cout<<"Do you want to add more??"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;

    }while (ans=="1");
    write.close();
    cout<<"File closed successfully after appending the data!!"<<endl;
}

void Student::display()
{
    read.open("Students.txt",ios::in);
    read.seekg(0,ios::beg);
    cout<<"\t\tThe contents of the file are  "<<endl;

    cout<<"\nRoll No\t\tName\t\tDiv\tAddress"<<endl;
    cout<<endl;
    while(read.read((char *)&rec,sizeof(stud)))
    {
        if (rec.roll_no!=0)
        {
            cout<<"\n"<<rec.roll_no<<"\t\t"<<rec.name<<"\t\t"<<rec.div<<"\t"<<rec.address<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
        }
    }
    read.close();
    cout<<"File closed successfully after reading the data!!"<<endl;
}

int Student::search(int roll)
{
    int i=0;
    read.open("Students.txt",ios::in);
    read.seekg(0,ios::beg);
    if (rec.roll_no!=roll)
        cout<<"Record not found in the file!!!"<<endl;  
    while(read.read((char *)&rec,sizeof(stud)))
    {
        if (rec.roll_no==roll)
        {
            cout<<"\nRoll No. of student successfully found in the file!!"<<endl;
            cout<<"\nRoll No\t\tName\t\tDiv\tAddress"<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"\n"<<rec.roll_no<<"\t\t"<<rec.name<<"\t\t"<<rec.div<<"\t"<<rec.address<<endl;
            read.close();
            cout<<"\nFile successfully closed after searching!!"<<endl;
        }
       
    }
    return 0;

}

void Student::del()
{
    int roll;
    cout<<"Enter the Roll No. of the student to delete: " << endl;
    cin>>roll;

    ifstream inFile("Students.txt", ios::binary);
    ofstream outFile("Temp.txt", ios::binary);

    if (!inFile || !outFile)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    bool recordFound = false;
    while (inFile.read((char *)&rec,sizeof(rec)))
    {
        if (rec.roll_no==roll)
        {
            recordFound = true;
            continue; // Skip writing this record to the output file
        }
        outFile.write((char *)&rec,sizeof(rec));
    }

    inFile.close();
    outFile.close();

    if (recordFound)
    {
        remove("Students.txt");       // Delete the original file
        rename("Temp.txt", "Students.txt"); // Rename the temporary file
        cout<<"Record deleted successfully from the file!!"<<endl;
    }
    else
    {
        remove("Temp.txt"); // Delete the temporary file
        cout<<"Record not found!"<<endl;
    }
}


int main()
{
    int roll_no,ch,ans;
    Student s;
    do
    {
        cout<<endl;
        cout<<"***************MENU***************"<<endl;
        cout<<"1.Add data to the file\n2.Display the file\n3.Append Data to file\n4.Search for an record in the file\n5.Delete a record from the file\n6.Exit"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:
                s.create();
                break;

            case 2:
                s.display();
                break;

            case 3:
                s.append();
                break;

            case 4:
                cout<<"\nEnter the roll no. to search : "<<endl;
                cin>>roll_no;
                s.search(roll_no);
                break;

            case 5:
                s.del();
                s.display();
                break;

            case 6:
                cout<<"Exiting from the program............"<<endl;
                exit(0);
                break;

            default:
                cout<<"You have entered a wrong choice!!!"<<endl;
                break;

        }
        cout<<"\nDo you want to continue??"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;
    }while (ans==1);
    
    return 0;
}