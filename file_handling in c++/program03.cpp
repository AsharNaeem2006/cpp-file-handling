#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Electronic_products{
    protected:
    string name;
    string brand;
    int price;
    int quantity;
    public:
    // default constructor
    Electronic_products()
    {
        name="t";
        brand="ff";
        price=0;
        quantity=00;

    }
    // parametrized constructor
    Electronic_products(string n,string b,int p,int q)
    {
        name=n;
        brand=b;
        price=p;
        quantity=q;
    }
    // copy constructor
    Electronic_products(const Electronic_products &obj)
    {
        name=obj.name;
        brand=obj.brand;
        price=obj.price;
        quantity=obj.quantity;
    }
    void Electronics_product_setter(string n,string b,int p,int q)
    {
        name=n;
        brand=b;
        p=price;
        quantity=q;
    }
    void Electronics_product_getter()
    {
        cout  << "Electronics Product  \n";
        cout << "Name : " <<name <<endl;
        cout << "Brand : " <<brand <<endl;
        cout << "Price : "<<price<<endl;
        cout << "Quantity : "<<quantity<<endl;
    }

};
class Television:public Electronic_products
{
    private:
    int screen_size;
    int Resolution;
    public:
    Television(string n,string b,int p,int q,int scr,int r):Electronic_products(n,b,p,q)
    ,screen_size(scr),Resolution(r)
    {

    }
    void tv_setter(int s,int r)
    {
        screen_size=s;
        Resolution=r;
    }
    void tv_getter()
    {
        fstream fout;
        fout.open("record.txt",ios::out|ios::app);
        cout  << "Electronics Product  \n";
        cout << "Name : " <<name <<endl;
        cout << "Brand :" <<brand <<endl;
        cout << "Price : "<<price<<endl;
        cout << "Quantity : "<<quantity<<endl;
        cout << "Screen size : "<<screen_size<<endl;
        cout<< "Resolution : " <<Resolution<<endl;
        fout  << "Electronics Product  \n";
        fout << "Name : " <<name <<endl;
        fout << "Brand :" <<brand <<endl;
        fout << "Price : "<<price<<endl;
        fout << "Quantity : "<<quantity<<endl;
        fout << "Screen size : "<<screen_size<<endl;
        fout<< "Resolution : " <<Resolution<<endl;
    }

};
int  main()
{
    Electronic_products E1;
    Electronic_products E2("Computer","Dell",12000,12);
    Electronic_products E3(E2);
    Television T[3]
    {
        Television("TV1", "Samsung", 50000, 5, 42, 1080),
        Television("TV2", "LG", 60000, 3, 50, 4),
        Television("TV3", "Sony", 70000, 2, 55, 8)
    };
    for(int i=0;i<3;i++)
    {
        T[i].tv_getter();
    }
    return 0;

}