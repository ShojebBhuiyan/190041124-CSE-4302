#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
    string EmpName;
    int ID;
    int Age;
    float Salary;

    string getStatus()
    {
        if (Age <= 25)
        {
            if (Salary <= 20000) return "Low";
            else return "Moderate"; 
        }

        else
        {
            if (Salary <= 21000) return "Low";
            else if (Salary > 21000 && Salary <= 60000) return "Moderate";
            else return "High";
        }
    }

public:

    void FeedInfo(string name, int id, int age, int salary)
    {
        EmpName = name;
        ID = id;
        Age = age;
        Salary = salary;
    }

    void ShowInfo()
    {
        cout << "Employee Name: " << EmpName << endl
            << "Employee ID: " << ID << endl
            << "Employee Age: " << Age << endl
            << "Employee Status: " << getStatus() << " Salaried Person" << endl;
    }
};

int main()
{
    Employee demo;

    demo.FeedInfo("Yes", 1, 21, 21000);
    demo.ShowInfo();

    return 0;
}