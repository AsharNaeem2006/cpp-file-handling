#include<iostream>
#include<climits>
#include<fstream>
using namespace std;

class Arr{
    private:
    int arrays[5];
    public:
    void fill_function();
    void display_function(); 
    void largest_to_smallest();
    void smallest_to_largest();
    void find_max();
    void find_min();
};
void Arr::fill_function()
{
    cout << "Enter five values in array :";
    for(int i=0;i<5;i++)
    {
        cin >>arrays[i];
    }
}
void Arr::display_function()
{
    fstream fout;
    fout.open("Arrays.txt",ios::out|ios::app);
    fout << "The array contains following numbers :";
    for(int i=0;i<5;++i)
    {
        fout << arrays[i]<<" ";
    }
}
void Arr::find_min()
{
    fstream fout;
    fout.open("Arrays.txt",ios::out|ios::app);
    int min_value=INT_MAX;
    for(int i=0;i<5;i++)
    {
        if(arrays[i]<min_value)
        {
            min_value=arrays[i];
        }
    }
    fout << "\nMin value is :" <<min_value;
}
void Arr::find_max()
{
    fstream fout;
    fout.open("Arrays.txt",ios::out|ios::app);
    int max_value=INT_MIN;
    for(int i=0;i<5;i++)
    {
        if(arrays[i]>max_value)
        {
            max_value=arrays[i];
        }
    }
    fout << "\nMax number is : " <<max_value;
}
void Arr::smallest_to_largest()
{
    fstream fout;
    fout.open("Arrays.txt",ios::out|ios::app);
    fout << "In Ascending order :";
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(arrays[i]>arrays[j])
            {
                int temp=arrays[i];
                arrays[i]=arrays[j];
                arrays[j]=temp;
            }
        }
        fout << arrays[i]<<" ";
    }
}
void Arr::largest_to_smallest()
{
    fstream fout;
    fout.open("Arrays.txt",ios::out|ios::app);
    fout << "In desending order : ";
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(arrays[i]<arrays[j])
            {
                int temp=arrays[i];
                arrays[i]=arrays[j];
                arrays[j]=temp;
            }
        }
        fout << arrays[i]<<" ";
    }
}
int main()
{
    fstream fout;
    fout.open("Arrays.txt",ios::out|ios::app);
    Arr A;
    A.fill_function();
    A.display_function();
    A.find_min();
    A.find_max();
    fout <<endl;
    A.smallest_to_largest();
    fout <<endl;
    A.largest_to_smallest();
}