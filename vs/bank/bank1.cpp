#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Bank
{
  public:
  string client[10];
  int balance[10]={0};
  int no[10];
  void input()
  { 
    for(int i=0;i<10;++i)
    {
      cout<<"Client "<<(i+1)<<endl;
      cout<<"Name of the Client : ";
      cin>>client[i];
      cout<<"Balance : ";
      cin>>balance[i];
      cout<<"No. of times ATM used in 30 days: "<<endl;
      cin>>no[i];
    }
  }
  void maxbal()
  {
    int a=balance[0];
    string b;
    for(int i=0;i<10;i++)
    {
      if(a<=balance[i+1])
      {
        a=balance[i+1];
        b=client[i+1];
      }
    }
    cout<<b<<"has the max balance of INR: "<<a<<endl;
  }
};

class ATM: public Bank
{
  public:
  void facility()
  {
    try
    {
      string name;
      cout<<"Enter Name: ";
      cin>>name;        
      for(int i=0;i<10;i++)
      {
        if(balance[i]<5000)
          throw(i);
        else
           cout<<"You are eligible for ATM facility.";
      }
    }
    catch(int z)
    {
      cout<<"Sorry no ATM facility is applicable for you as your bank balance is less than Rs. 5000\n";
    }
  }
  void create()
  {
    int temp=1;
    ofstream myfile ("report.txt");
    if (myfile.is_open())
    {
      for(int i=0;i<10;i++)
      {
        if(no[i]>4)
        {
          myfile<<temp<<") "<<client[i]<<"\n";
          temp++;
        }
      }
      myfile.close();
    }
  }
  void show()
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
  ATM a;
  int ch;
  a.input();
  while(1)
  {
    cout<<"MENU"<<endl;
    cout<<"1. Maximum Balance"<<endl;
    cout<<"2. Check whether policy is avaliable or not."<<endl;
    cout<<"3. Display coustomer who used ATM facility 4 times during 30 days."<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"\n Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1: a.maxbal();
              break;
      case 2: a.facility();
              break;
      case 3: a.create();
              a.show();
              break;
      case 4: cout<<"Thank You!\n";
              return 0;
      defaut: cout<<"Wrong choice, try again!\n";
              break;
    }
  }
  return 0;  
}