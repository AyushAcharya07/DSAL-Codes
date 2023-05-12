/*
    Department maintains a student information. The file contains roll number, name,
    division and address. Allow user to add, delete information of student. Display
    information of particular employee. If record of student does not exist an appropriate
    message is displayed. If it is, then the system displays the student details. Use sequential
    file to main the data.
*/

# include <iostream>
# include <fstream>
# include <string>
using namespace std;

typedef struct data
{
    int roll_no;
    string name;
    string division;
    string address;
}data;

data obj;

class file
{
    public:
    ofstream write;
    ifstream read;
    void getdata()
    {
        cout<<"Enter the name of the student : "<<endl;
        cin>>obj.name;
        cout<<"Enter the roll no. of the student : "<<endl;
        cin>>obj.roll_no;
        cout<<"Enter the class and division of the student : "<<endl;
        cin>>obj.division;
        cout<<"Enter the address of the student : "<<endl;
        cin>>obj.address;
    }
    
    void write_file()
    {
        write.open("Students.txt",ios::binary);
        write<<"********************STUDENT INFO FILE********************"<<endl;
        write<<"ROLL NO.\t\tNAME\t\t\tCLASS\t\tADDRESS"<<endl;
        write<<endl;
        write<<obj.roll_no<<"\t\t\t\t"<<obj.name<<"\t\t\t"<<obj.division<<"\t\t"<<obj.address;
    }
};


int main()
{
    file f;
    f.getdata();
    f.write_file();
    return 0;
}
