#include <iostream>
#include <string>

using namespace std;

class Seat
{
    protected:
    string comfortability;
    bool seat_warmer_presence;
    
    public:
    Seat()
    { }
    Seat(string comf, bool presence):
        comfortability(comf), seat_warmer_presence(presence)
    { }

    void set_comfortability(string comf)
    {
        comfortability = comf;
    } 
    void set_seat_warmer_presence(bool presence)
    {
        seat_warmer_presence = presence;
    }

    string get_comfortability() const
    {
        return comfortability;
    }
    bool get_seat_warmer_presence() const
    {
        return seat_warmer_presence;
    }
};

class Wheel
{
    protected:
    double circumference;

    public:
    Wheel()
    { }
    Wheel(double c): circumference(c)  
    { }

    void set_circumference(double c)
    {
        circumference = c;
    }
    
    double get_circumference() const
    {
        return circumference;
    }
};

class Engine
{
    protected:
    double max_fuel_consumption_rate;
    double max_energy_production_rate;
    int avg_RPM;

    public:
    Engine()
    { }
    Engine(double f_rate, double e_rate, int rpm):
        max_fuel_consumption_rate(f_rate), max_energy_production_rate(e_rate),
        avg_RPM(rpm)
    { }

    void set_max_fuel_consumption_rate(double f_rate)
    {
        max_fuel_consumption_rate = f_rate;
    }
    void set_max_energy_production_rate(double e_rate)
    {
        max_energy_production_rate = e_rate;
    }
    void set_avg_RPM(int rpm)
    {
        avg_RPM = rpm;
    }

    double get_max_fuel_consumtion_rate() const
    {
        return max_fuel_consumption_rate;
    }
    double get_max_energy_production_rate() const
    {
        return max_energy_production_rate;
    }
    int get_avg_RPM() const
    {
        return avg_RPM;
    }
};

class Door
{
    protected:
    string opening_mode;

    public:
    Door()
    { }
    Door(string mode): opening_mode(mode)
    { }

    void set_opening_mode(string mode)
    {
        opening_mode = mode;
    }
    
    string get_opening_mode() const
    {
        return opening_mode;
    }
};

class Car: public Seat, public Wheel, public Engine, public Door
{
    private:
    double maximum_acceleration;
    double fuel_capacity;

    public:
    Car(): Seat(), Wheel(), Engine(), Door()
    { }
    Car(double max_acc, double f_cap): Seat(), Wheel(), Engine(), Door(),
        maximum_acceleration(max_acc), fuel_capacity(f_cap)
    { }
    Car(double max_acc, double f_cap, 
        string comf, bool presence,
        double circumf,
        double f_rate, double e_rate, int rpm,
        string mode):
            Seat(comf, presence), Wheel(circumf), Engine(f_rate, e_rate, rpm), Door(mode),
            maximum_acceleration(max_acc), fuel_capacity(f_cap)
    { }

    void set_maximum_acceleration(double max_acc)
    {
        maximum_acceleration = max_acc;
    }
    void set_fuel_capacity(double f_cap)
    {
        fuel_capacity = f_cap;
    }

    double get_maximum_acceleration() const
    {
        return maximum_acceleration;
    }
    double get_fuel_capacity() const
    {
        return fuel_capacity;
    }

    void display() const
    {
        cout << "Maximum Acceleration: " << get_maximum_acceleration() << endl
            << "Fuel Capacity: " << get_fuel_capacity() << endl
            << "Seat Comfortability: " << get_comfortability() << endl
            << "Seat Warmer Presence: " << get_seat_warmer_presence() << endl
            << "Wheel Circumference: " << get_circumference() << endl
            << "Maximum Fuel Consumption Rate: " << get_max_fuel_consumtion_rate() << endl
            << "Maximum Energy Production Rate: " << get_max_energy_production_rate() << endl
            << "Average RPM: " << get_avg_RPM() << endl
            << "Door Opening Mode: " << get_opening_mode() << endl;
    }
};

int main()
{
    Car car(100, 50, "Comfortable", true, 20, 2.5, 60, 7200, "sideways");

    car.display();

    return 0;
}