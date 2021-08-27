#include <iostream>
using namespace std;
 
class Animal
{
    public:
 
        virtual void food() const
        {
            cout << "Generic food" << endl;
        }
 
        virtual void sound() const = 0;
 
};
 
class Cat: public Animal
{
    public:
        void food() const
        {
            cout << "Cat food" << endl;
        }
 
        void sound() const
        {
            cout << "Mew" << endl;
        }
 
};
 
class Dog: public Animal
{

    public:
        void sound() const
        {
            cout << "Bark" << endl;
        }
 
};
 
int main()
{
 
    Cat cat;
    Dog dog;
 
    Animal *a1 = &cat;
    Animal *a2 = &dog;
 
    a1->food();
    a1->sound();
 
 
    a2->food();
    a2->sound();
 
    return 0;
}

