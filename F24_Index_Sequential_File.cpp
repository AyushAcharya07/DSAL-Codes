
# include <iostream>
# include <fstream>
# include <stdio.h>

using namespace std;

ofstream write;
ifstream read;
fstream file;

struct emp
{
    int emp_code;
    char name[20];
    float salary;
};

class Employee
{
    public:
    
    emp rec;

    void get_data();
    void display();
    int getcode()
    {
        return rec.emp_code;
    }
    int getsalary()
    {
        return rec.salary;
    }
    void updatesalary(float s)
    {
        rec.salary=rec.salary+s;
    }
};

void Employee::get_data()
{
    cout<<"Enter the Employee code : "<<endl;
    cin>>rec.emp_code;
    cout<<"Enter the name of the employee : "<<endl;
    cin>>rec.name;
    cout<<"Enter the salary of the employee : "<<endl;
    cin>>rec.salary;
}

void Employee::display()
{
    cout<<"\n\tEmployee Code : "<<rec.emp_code<<"\n\tEmployee Name : "<<rec.name<<"\n\tEmployee Salary : "<<rec.salary<<endl;
    cout<<"----------------------------------------------------------------------------------------------"<<endl;
}

void deleteFile()
{
    remove("EMPLOYEE.dat");
}

void add_to_file()
{
    Employee obj;
    write.open("Employee.dat",ios::out);
    if (!write)
    {
        cout<<"\n\tError in opening the File!!"<<endl;
        return;
    }
    obj.get_data();
    write.write((char *)&obj,sizeof(obj));
    cout<<"\n\tData added successfully to the file!"<<endl;
    write.close();
    cout<<"File closed successfully after addition !"<<endl;

}

void display_DATA()
{
    Employee obj;
    read.open("Employee.dat", ios::in | ios::binary);

    if (!read)
    {
        cout << "\n\tError in opening the file!" << endl;
        return;
    }

    while (read.read(reinterpret_cast<char *>(&obj), sizeof(obj)))
    {
        obj.display();
    }

    read.close();
}

void search_Rec()
{
    Employee obj;
    int c, isfound = 0;

    cout << "Enter the Employee code: " << endl;
    cin >> c;

    read.open("Employee.dat", ios::in | ios::binary);
    if (!read)
    {
        cout << "\n\tError in opening the file!" << endl;
        return;
    }

    while (read.read((char *)&obj, sizeof(obj)))
    {
        if (obj.getcode() == c)
        {
            obj.display();
            isfound = 1;
            break;
        }
    }

    if (isfound == 0)
    {
        cout << "\n\tRecord not found!" << endl;
    }

    read.close();
}


void inc_salary()
{
    Employee obj;
    int c, isfound = 0;
    float salary;

    cout << "Enter the code of the Employee: " << endl;
    cin >> c;

    file.open("Employee.dat", ios::in | ios::out | ios::binary);
    if (!file)
    {
        cout << "\n\tError in opening the file!" << endl;
        return;
    }

    while (file.read(reinterpret_cast<char *>(&obj), sizeof(obj)))
    {
        if (obj.getcode() == c)
        {
            cout << "Enter the increment in the salary: " << endl;
            cin >> salary;
            obj.updatesalary(salary);
            file.seekp(file.tellp() - sizeof(obj));
            file.write(reinterpret_cast<char *>(&obj), sizeof(obj));
            isfound = 1;
            break;
        }
    }

    if (isfound == 0)
        cout << "\n\tRecord not found!" << endl;

    file.close();
    cout << "\nSalary incremented successfully!" << endl;
}


void Ins_rec()
{
    Employee obj;
    Employee newEmp;

    file.open("Employee.dat", ios::in | ios::out | ios::binary);

    if (!file)
    {
        cout << "\n\tError in opening 'Employee.dat' file!" << endl;
        return;
    }

    write.open("Temp.dat", ios::out | ios::binary);

    if (!write)
    {
        cout << "\n\tError in opening 'Temp.dat' file!" << endl;
        file.close();
        return;
    }

    newEmp.get_data(); 

    bool isInserted = false; 

    while (file.read(reinterpret_cast<char *>(&obj), sizeof(obj)))
    {
        if (!isInserted && obj.getcode() > newEmp.getcode())
        {
            write.write(reinterpret_cast<char *>(&newEmp), sizeof(newEmp));
            isInserted = true;
        }

        write.write(reinterpret_cast<char *>(&obj), sizeof(obj));
    }

    if (!isInserted)
    {
        write.write(reinterpret_cast<char *>(&newEmp), sizeof(newEmp));
    }

    write.close();
    file.close();

    remove("Employee.dat");
    rename("Temp.dat", "Employee.dat");

    cout << "\n\tRecord inserted successfully in the file!" << endl;
}




int main ()
{
    int ch,ans;
    bool val=true;

    do
    {
        cout<<"***************MENU***************"<<endl;
        cout<<"1.Add Employee Data\n2.Display the Data\n3.Search for Data\n4.Increment in the Salary\n5.Insert Data\n6.Exit"<<endl;
        cout<<"Enter your choice : "<<endl;
        cin>>ch;
        switch (ch)
        {
            case 1:
                int res,ans2;
                
                cout<<"\n\tThis method would overwrite the previous file contents !"<<endl;
                cout<<"\n\tDo you want to proceed for adding data??\n\t1.Yes\t2.No"<<endl;
                cin>>ans2;
                if (ans2==1)
                    res=1;
                else
                    res=0;

                if (res==1)
                    add_to_file();
                if (res==0)
                    break;
                break;

            case 2:
                display_DATA();
                break;

            case 3:
                search_Rec();
                break;

            case 4:
                inc_salary();
                break;

            case 5:
                Ins_rec();
                break;

            case 6:
                cout<<"\n\tExiting from the program........."<<endl;
                exit(0);
                break;

            default:
                cout<<"You have entered a wrong choice !"<<endl;
                val=false;
                break;
        }
        cout<<"\nDo you want to continue?"<<endl;
        cout<<"1.Yes\n2.No"<<endl;
        cin>>ans;
    }while (ans==1);

    return 0;
}
