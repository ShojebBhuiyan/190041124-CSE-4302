#include <iostream>
#include <string>

using namespace std;

class Animal
{
    private:
    string nameOfAnimal;
    string habitat_area;
    string sound;
    int weight;
    int height;
    int birthYear;

    public:
    Animal(): birthYear(2021)
    { }
    Animal(string Sound): sound(Sound), birthYear(2021)
    { }
    Animal(string name, string area, string Sound, int w, int h):
        nameOfAnimal(name), habitat_area(area), sound(Sound), weight(w), height(h), birthYear(2021)
    { }
    Animal(string name, string area, string Sound, int w, int h, int year):
        nameOfAnimal(name), habitat_area(area), sound(Sound), weight(w), height(h), birthYear(year)
    { 
        if (birthYear > 2021)
        {
            cout << "Invalid birth year. Setting it to 2021\n";
        }
        birthYear = 2021;
    }
    
    void set_name(string name)
    {
        nameOfAnimal = name;
    }
    void set_habitat(string area)
    {
        habitat_area = area;
    }
    void set_sound(string Sound)
    {
        sound = Sound;
    }
    void set_weight(int w)
    {
        weight = w;
    }
    void set_height(int h)
    {
        height = h;
    }
    void set_birthYear(int year)
    {
        birthYear = year;
    }

    string get_name() const
    {
        return nameOfAnimal;
    }
    string get_habitat() const
    {
        return habitat_area;
    }
    string get_sound() const
    {
        return sound;
    }
    int get_weight() const
    {
        return weight;
    }
    int get_height() const
    {
        return height;
    }
    int get_age() const
    {
        return birthYear - 2021;
    }

    void getInformation() const
    {
        cout << "Name: " << nameOfAnimal << endl
            << "Habitat Area: " << habitat_area << endl
            << "Sound: " << sound << endl
            << "Weight: " << weight << endl
            << "Height: " << height << endl
            << "Birth Year: " << birthYear << endl
            << "Age: " << get_age() << endl;
    }

    void changeWeight(int pounds)
    {
        weight = pounds;
    }

    void vocalize() const
    {
        cout << sound;
    }
};

class Cow : public Animal
{   
    public:
    Cow(): Animal("moo")
    { }
    Cow(string name, string area, string Sound, int w, int h): Animal(name, area, Sound, w, h)
    { }
    Cow(string name, string area, string Sound, int w, int h, int year): Animal(name, area, Sound, w, h, year)
    { }
};

class Chicken : public Animal
{
    public:
    Chicken(): Animal("buck buck")
    { }
    Chicken(string name, string area, string Sound, int w, int h): Animal(name, area, Sound, w, h)
    { }
    Chicken(string name, string area, string Sound, int w, int h, int year): Animal(name, area, Sound, w, h, year)
    { }
};

class Cat : public Animal
{
    public:
    Cat(): Animal("meow")
    { }
    Cat(string name, string area, string Sound, int w, int h): Animal(name, area, Sound, w, h)
    { }
    Cat(string name, string area, string Sound, int w, int h, int year): Animal(name, area, Sound, w, h, year)
    { }
};

int main()
{
    Cow cow;
    Chicken chicken;
    Cat cat;
    cow.getInformation();
    chicken.getInformation();
    cat.getInformation();

    return 0;
}