#include <bits/stdc++.h>
using namespace std;
const int LEN = 32;
const int MAX = 100;
enum Employee_type
{
    tscientist,
    tweb_dev
};
class Employee
{
private:
    char name[LEN];
    int salary;
    static int count;
    static Employee *emp[];

public:
    Employee()
    {

    }

    void info()
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }

    virtual void setData()
    {
        cout << "Enter employee name: ";
        cin >> name;
        cout << "Enter employee salary: ";
        cin >> salary;
    }

    virtual void showData() = 0;
    virtual Employee_type get_type(); //get type
    static void add();                //add an Employee
    static void display();            //display all Employees
    static void read();               //read from disk file
    static void write();
};
int Employee::count=0;
Employee *Employee::emp[MAX];

class Scientist : public Employee
{
private:
    char type[LEN];

public:
    Scientist()
    {

    }

    void setData(void)
    {
        Employee::setData();
        cout << "Enter type of Scientist: ";
        cin >> type;
    }
    void showData(void)
    {
        Employee::info();
        cout << "Scientist Type: " << type << endl;
    }
};

class Webdev : public Employee
{
private:
    char language[LEN];

public:
    Webdev()
    {

    }

    void setData()
    {
        Employee::setData();
        cout << "Enter the preferred programming language: ";
        cin >> language;
    }
    void showData(void)
    {
        Employee::info();
        cout << "Programming Language Used: " << language << endl;
    }
};

void Employee::add()
{
    char ch;
    cout << "'e' to add an Scientist"
         << "\n'w' to add a web developer"
         << "\n Enter selection : ";

    cin >> ch;
    switch (ch)
    {
    //create specified Employee type
    case 'e':
        emp[count] = new Scientist;
        break;
    case 'w':
        emp[count] = new Webdev;
        break;
    default:
        cout << "\nUnknown Employee type\n";
        return;
    }

    emp[count++]->setData(); //get Employee data from user
}

//display all employees
void Employee::display()
{
    for (int j = 0; j < count; j++)
    {
        cout << (j + 1);            //display number
        switch (emp[j]->get_type()) //display type
        {
        case tscientist:
            cout << ".Type : Scientist" << endl;
            break;
        case tweb_dev:
            cout << ".Type : Web Developer" << endl;
            break;
        default:
            cout << ".Unknown type" << endl;
        }
        emp[j]->showData(); //display employee data
        cout << endl;
    }
}
//return the type of this object
Employee_type Employee::get_type()
{
    if (typeid(*this) == typeid(Scientist))
        return tscientist;
    else if (typeid(*this) == typeid(Webdev))
        return tweb_dev;
    else
    {
        cerr << "\nBad employee type";
        exit(1);
    }
}
//write all current memory objects to file
void Employee::write()
{
    int size;
    cout << "Writing " << count << " employees.\n";
    ofstream ouf;        //open ofstream in binary
    Employee_type etype; //type of each employee object
    ouf.open("Employee.txt", ios::trunc | ios::binary);
    if (!ouf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    for (int j = 0; j < count; j++) //for every employee object
    {
        //get its type
        etype = emp[j]->get_type();
        //write type to file
        ouf.write((char *)&etype, sizeof(etype));
        switch (etype) //find its size
        {
        case tscientist:
            size = sizeof(Scientist);
            break;
        case tweb_dev:
            size = sizeof(Webdev);
            break;
        } //write employee object to file
        ouf.write((char *)(emp[j]), size);
        if (!ouf)
        {
            cout << "\nCan't write to file\n";
            return;
        }
    }
}
//read data for all employees from file into memory
void Employee::read()
{
    int size;            //size of employee object
    Employee_type etype; //type of employee
    ifstream inf;        //open ifstream in binary
    inf.open("Employee.txt", ios::binary);
    if (!inf)
    {
        cout << "\nCan't open file\n";
        return;
    }
    count = 0; //no employees in memory yet
    while (true)
    {
        //read type of next employee
        inf.read((char *)&etype, sizeof(etype));
        if (inf.eof()) //quit loop on eof
            break;
        if (!inf) //error reading type
        {
            cout << "\nCan't read type from file\n";
            return;
        }
        switch (etype)
        {
        //make new employee
        case tscientist: //of correct type
            emp[count] = new Scientist;
            size = sizeof(Scientist);
            break;
        case tweb_dev:
            emp[count] = new Webdev;
            size = sizeof(Webdev);
            break;
        default:
            cout << "\nUnknown type in file\n";
            return;
        } //read data from file into it
        inf.read((char *)emp[count], size);
        if (!inf) //error but not eof
        {
            cout << "\nCan't read data from file\n";
            return;
        }
        count++; //count employee
    }            //end while
    cout << "Reading " << count << " employees\n";
}
int main(void)
{
    char ch;
    while (true)
    {
        cout << "'a' -- add data for an employee"
             "\n'd' -- display data for all employees"
             "\n'w' -- write all employee data to file"
             "\n'r' -- read all employee data from file"
             "\n'x' -- exit"
             "\nEnter selection: ";
        cin >> ch;
        switch (ch)
        {
        case 'a': //add an employee to list
            Employee::add();
            break;
        case 'd': //display all employees
            Employee::display();
            break;
        case 'w': //write employees to file
            Employee::write();
            break;
        case 'r': //read all employees from file
            Employee::read();
            break;
        case 'x':
            exit(0); //exit program
        default:
            cout << "\nUnknown command";
        } //end switch
    }     //end while
    return 0;
} //end main()
