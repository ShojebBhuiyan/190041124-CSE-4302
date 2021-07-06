#include <iostream>
#include <string>

using namespace std;

class Medicine
{
    private:
        string name;
        string genericName;
        double discountPercent = 5.f;
        double unitPrice = 0.f;

    public:
        void assignName(char name[], char genericName[])
        {
            this->name = name;
            this->genericName = genericName;
        }

        void assignPrice(double price)
        {
            if (price > -1) unitPrice = price;
            else cout << "Price must be non-negative.\n";
        }

        void setDiscountPercent(double percent)
        {
            if (percent >= 0.f && percent <= 45.f) discountPercent = percent;
            else cout << "Discount percentage must be between 0 to 45%\n";
        }

        double getSellingPrice(int nos)
        {
            return (unitPrice - (unitPrice * discountPercent / 100)) * nos; 
        }

        void display()
        {
            cout << name << " (" << genericName << ") has a unit price of BDT " << unitPrice
                << ". Current discount " << discountPercent << "%" << '\n'; 
        }
};

int main()
{
    Medicine test;
    test.assignName("Paracetamol", "Napa");
    test.assignPrice(0.80f);
    test.setDiscountPercent(10.f);
    cout << test.getSellingPrice(1) << '\n';
    test.display();

    return 0;
}