#include <iostream>
#include <string>
using namespace std;

enum class Material {Wood,Board,Steel,foam};
class Furniture
{
protected:
    double price;
    double discount;
    Material madeof;
    string productName;
public:
    Furniture()
    { }
    Furniture(double p,double d,Material m, string name):price(0),discount(0),madeof(Material::Wood), productName("")
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        setProductName(name);
    }

    void setPrice(double val)
    {
        if(val > 0)
            price = val;
    }

    void setDiscount(double val)
    {
        if(val<=price)
            discount=val;
    }

    void setMadeof(Material val)
    {
        madeof=val;
    }
    
    void setProductName(string name)
    {
        productName = name;
    }

    string getMadeof()
    {
        if(madeof==Material::Wood)
            return string("Wood");
        else if(madeof==Material::Board)
            return string("Board");
        else if(madeof==Material::Steel)
            return string("Steel");
        else
            return string("");
    }

    double getDiscountedPrice()
    {
        return price - discount;
    }

    virtual void productDetails()=0;
};



enum class BedSize {Single,SemiDouble,Double};

class Bed:public Furniture
{
    private:
    BedSize bedsize;
    
    public:
    Bed(double p = 0, double d = 0, Material m = Material::Wood, BedSize b = BedSize::Single)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        bedsize = b;
    }
    void productDetails()
    {
        cout << string(20, '-') << '\n';
        if(productName != "")
            cout << "Product Name: " << productName << '\n';
        cout << "Regular Price: " << price << '\n';
        cout << "Discounted Price: " << getDiscountedPrice() << '\n';
        cout << "Material: " << getMadeof() << '\n';
        cout << "Bed Size: " << getBedSize() << '\n';
        cout << string(20, '#') << '\n';
    }

    string getBedSize()
    {
        if (bedsize == BedSize::Single)
            return "Single";
        if (bedsize == BedSize::SemiDouble)
            return "Semidouble";
        if (bedsize == BedSize::Double)
            return "Double";
    }
};

enum class SeatNumber {One, Two, Three, Four, Five};

class Sofa:public Furniture
{
    private:
    SeatNumber seatnumber;
   
    public:
    Sofa(double p = 0, double d = 0, Material m = Material::Wood, SeatNumber s = SeatNumber::One)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        seatnumber = s;
    }

    void productDetails()
    {
        cout << string(20, '-') << '\n';
        if(productName != "")
            cout << "Product Name: " << productName << '\n';
        cout << "Regular Price: " << price << '\n';
        cout << "Discounted Price: " << getDiscountedPrice() << '\n';
        cout << "Material: " << getMadeof() << '\n';
        cout << "Seat Number: " << getSeatNumber() << '\n';
        cout << string(20, '#') << '\n';
    }

    string getSeatNumber()
    {
        if (seatnumber == SeatNumber::One)
            return "One";
        if (seatnumber == SeatNumber::Two)
            return "Two";
        if (seatnumber == SeatNumber::Three)
            return "Three";
        if (seatnumber == SeatNumber::Four)
            return "Four";
        if (seatnumber == SeatNumber::Five)
            return "Five";
    }
};

enum class ChairCount {Two, Four, Six};

class DiningTable:public Furniture
{
    private:
    ChairCount chaircount;
    
    public:
    DiningTable(double p = 0, double d = 0, Material m = Material::Wood, ChairCount c = ChairCount::Two)
    {
        setPrice(p);
        setDiscount(d);
        setMadeof(m);
        chaircount = c;
    }

    void productDetails()
    {
        cout << string(20, '-') << '\n';
        cout << "Product Name: " << productName << '\n';
        cout << "Regular Price: " << price << '\n';
        cout << "Discounted Price: " << getDiscountedPrice() << '\n';
        cout << "Material: " << getMadeof() << '\n';
        cout << "Chair Count: " << getChairCount() << '\n';
        cout << string(20, '#') << '\n';
    }

    string getChairCount()
    {
        if (chaircount == ChairCount::Two)
            return "Two";
        if (chaircount == ChairCount::Four)
            return "Four";
        if (chaircount == ChairCount::Six)
            return "Six";
    }
};


/**task 4
sort_furniture_discount will sort the array in descending order based on their discount price.
You may need to add some member functions
**/
void sort_furniture_discount(Furniture* furnitures[],int no_of_furnitures)
{
    for (int i = 0; i < no_of_furnitures; i++)
    {
        for (int j = i + 1; j < no_of_furnitures; j++)
        {
            if (furnitures[i]->getDiscountedPrice() < furnitures[j]->getDiscountedPrice())
            {
                Furniture* temp = furnitures[i];
                furnitures[i] = furnitures[j];
                furnitures[j] = temp;
            }
        }
    }
}

void demo(int arr[], int n)
{
    arr[3] = 10;
}

int main()
{
    // Furniture* f_list[4];

    // f_list[0] = new Bed(10000,123,Material::Wood,BedSize::Single);
    // f_list[1] = new Sofa(11000,234,Material::Steel,SeatNumber::Five);
    // f_list[2] = new Sofa(13000,345,Material::Wood,SeatNumber::Two);
    // f_list[3] = new Bed(10090,123,Material::Wood,BedSize::Single);

    // for (int i = 0; i < 4; i ++)
    //     f_list[i]->productDetails();
    
    // f_list[2]->setDiscount(30);

    // for(int i = 0; i < 4; i++)
    //     f_list[i]->productDetails();
    
    // f_list[0]->setProductName("Kimochi Bed");
    // f_list[0]->productDetails();

    // sort_furniture_discount(f_list, 4);
    // for (int i = 0; i < 4; i++)
    //     f_list[i]->productDetails();
    
    // return 0;

    int arr[5] = {1, 2, -3, 4, 5};

    demo(arr, 5);

    cout << arr[3];
}
