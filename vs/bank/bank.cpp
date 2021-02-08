#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Bank{
    public:
    string client[10];
    int money[10]={ 0 };

    void input()
    {
        for(int i=0;i<10;i++)
        {
            cout<<"Client "<<(i+1)<<"-->"<<endl;
            cout<<"Name: ";
            cin>>client[i];
            cout<<"Starting Balance: ";
            cin>>money[i];
        }
    }
    void max()
    {
        int max=0,temp;
        for(int i=0;i<10;i++)
        {
            if(money[i]>max)
            {
                max=money[i];
                temp=i;
            }
        }
        cout<<"Client "<<temp<<" has the maximum balance of Rs. "<<max<<endl;
    }
};
class ATM: public Bank{
    public:
    int atmuse[10]={ 0 };

    void withdrawn(){
        try{
        cout<<"Enter Name: ";
        string name;
        cin>>name;
        int i=0;
        for(;i<10;i++)
        {
            if(client[i]==name)
            break;
        }
        if(money[i]<5000)
        throw(i);
        else
        {
            cout<<"Money to be withdrawn: ";
            int temp;
            cin>>temp;
            money[i]=money[i]-temp;
            atmuse[i]++;
        }
        }
        catch(int z){
            cout<<"Sorry no ATM facility for you as your bank balance is less than Rs. 5000\n";
        }
    }
    void create_report()
    {
        int temp=1;
        ofstream myfile ("report.txt");
        if (myfile.is_open())
        {
        for(int i=0;i<10;i++)
        {
            if(atmuse[i]>4)
            {
                myfile<<temp<<") "<<client[i]<<"\n";
                temp++;
            }
        }
        myfile.close();
        }
    }
    void show_report()
    {
        string line;
        ifstream myfile ("report.txt");
        if (myfile.is_open())
        {
        while ( getline (myfile,line) )
        {
        cout << line << '\n';
        }
        myfile.close();
        }
    }
};
int main()
{
    ATM ob;
    ob.input();
    while(1){
        cout<<"Menu--->\n";
        cout<<" 1) Maximum Balance\n 2) Use ATM facility\n 3) Report for those who used the ATM more than 4 times\n 4) Exit\n";
        cout<<"Enter your choice: ";
        int ch;
        cin>>ch;
        switch(ch){
            case 1:
            ob.max();
            break;
            case 2:
            ob.withdrawn();
            break;
            case 3:
            ob.create_report();
            ob.show_report();
            break;
            case 4:
            cout<<"Bye. Have a nice day.\n";
            return 0;
            defaut:
            cout<<"Wrong choice. Try again.\n";
            break;
        }
    }
    return 0;
}