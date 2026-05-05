#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    fstream fin;
    fin.open("marks.txt",ios::in);
    if(!fin.is_open() || fin.peek()==EOF)
    {
        cout << "File is not open or empty\n";
    }
    else{          
        string name;
        char ch;
        int marks[4];
        while(getline(fin,name,'|'))
        {
            for(int i=0;i<4;++i)
            {
                fin>>marks[i];
                if(i<3)
                {
                    fin >>ch;
                }
            }
            int sum=0;
            for(int i=0;i<4;i++)
            {
                sum+=marks[i];
            }
            float avg=sum/4;
            cout << "Name " <<name << " Sum :"<<sum<<" Average "<<avg<<endl;
        }
    }
    fin.close();
}