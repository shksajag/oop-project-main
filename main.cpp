//header files
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class shopping{
private:
    int pcode;
    float price;
    float dis;
    string pname;
public:

//function 
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remove();
    void list();
    void recipt();
};

void shopping::menu(){

    m:
    int choice;
    string email,password;
    cout<<"\t\t\t\t______________________\n";
    cout<<"\t\t\t\t                      \n";
    cout<<"\t\t\t\t      Main Menu       \n";
    cout<<"\t\t\t\t                      \n";
    cout<<"\t\t\t\t______________________\n";
    cout<<"\t\t\t\t                      \n";
    cout<<"\t\t\t\t| 1. Administrator |\n ";
    cout<<"\t\t\t\t| 2. Buyer |        \n ";
    cout<<"\t\t\t\t| 3. Exit |\n ";
    cout<<"\n\t\t\t Please select : ";
    cin>>choice;

    switch(choice) {
        case 1:
            cout<<"\t\t Login : \n";
            cout<<"\t\t Enter Email ";
            cin>>email;
            cout<<"\t\t Enter Password";
            cin>>password;

            if(email=="admin@email.com" && password=="admin123"){
                administrator();
            }
            else{
                cout<<"INVALID EMAIL/PASSWORD ";
            }
            break;

        case 2:
            buyer();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"SELECT VALID OPTION";
            break;  
    }
    goto m;

}

void shopping::administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t ADMINISTRATOR MENU : ";
    cout<<"\n\n\n\t\t\t 1.) Add Product ";
    cout<<"\n\n\n\t\t\t 2.) Modify product";
    cout<<"\n\n\n\t\t\t 3.) Delete product";
    cout<<"\n\n\n\t\t\t 4.) Main menu";

    cout<<"\n\n\n\t\t Enter your choice:";
    cin>>choice;

    switch (choice)
    {

    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        remove();
        break;
    case 4:
        menu();
        break;
    default:
        cout<<"INVALID CHOICE ";    
    }
    goto m;
    
}

void shopping::buyer(){
    m:
    int choice;
    cout<<"\t\t\t Buyer Menu :\n";
    cout<<"\t\t\t 1.Buy Product \n";
    cout<<"\t\t\t 2. Go Back \n";
    cin>>choice;
    switch(choice){
        case 1:
            recipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"INVALID CHOICE";
            };
        goto m;
}

void shopping::add(){
    fstream data; //file handling operation by creating fstream  class's object data
    int c,token=0;
    float p,d;
    string n;

    cout<<"\n\n\t\t Add new product";
    cout<<"\n\n\t Code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of product";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"Enter the discount on the product";
    cin>>dis;

    data.open("database.txt",ios::in);    //opens database in reading mode

    //if the file does not exist

    if(!data){
        data.open("database.txt",ios::app|ios::out);        //open the file in append mode if this file doesnt exist. ios out->write mode
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<" \n";
        data.close();
    }
    else{
        //if data file exists, we read from file
        data>>c>>n>>p>>d

    }
}
