#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

struct employee{
string employeeName;
string password;
string salary;
string joiningDate;
string designation;
};
struct customer{
string customerName;
string roomNo;
string stay;
string category;
};

        
      
void manage(int esize,string user,string pwd,int loggedInUserType,int input,employee employeeData[],customer customerData[],string customerComplain[][8],string stay,string roomNo,string category,string bookedRooms[],int r,string unbookedRooms,int input1,string salary,string date,string designation);

void adminLogin(int esize,string user,string pwd,int input,int input1,employee employeeData[],customer customerData[],string customerComplain[][8],string stay,string roomNo,string category,int r,string bookedRooms[],int loggedInUserType,string unboookedRooms,string salary,string date,string designation);
void employeeLogin(int esize,string user,string pwd,int input,int input1,employee employeeData[],customer customerData[],string customerComplain[][8],string roomNo,string stay,string category,int r,string bookedRooms[],int loggedInUserType,string unbookedRooms,string salary,string date,string designation);
void customerLogin(int esize,string user,string pwd,int input,int input1,customer customerData[],string customerComplain[][8],string roomNo,string category,string stay,string unbookedRooms,int loggedInUserType,employee employeeData[],string bookedRooms[],int r,string salary,string date,string designation);
void rooms(int esize,string user,string pwd,int input,int input1,string unbookedRooms,int r,string bookedRooms[]);
void budget();
void reviews();
void complain(customer customerData[],string customerComplain[][8]);
    
bool loadData(employee employeeData[]);
bool saveData(employee employeeData[]);
bool deleteData(employee employeeData[],int esize);
      
    
   
    
int main()
{  
    int esize=10;
    string user,pwd;
    string designation;
    string roomNo;
    string salary,category;
    string stay,date;
    int loggedInUserType=-10;
    int input;
    int input1=-1;
    int r;

    employee employeeData[10];
    customer customerData[10];
    string customerComplain[2][8];
    string bookedRooms[10];
    
    string unbookedRooms;
    

   
    cout<<"*    *    *******    *********    ********    *"<<endl;
    cout<<"*    *   *        *      *        *           *"<<endl;
    cout<<"******  *          *     *        ********    *"<<endl;
    cout<<"*    *   *        *      *        *           *"<<endl;
    cout<<"*    *     ******        *        ********    *******"<<endl;
    cout<<"                                                                                      "<<endl;
    cout<<"         **        **     *******    **      **   *******    *******   ********  **      **  *******  **     **  ********"<<endl;
    cout<<"         *   ****   *    *       *   * *      *  *       *  *       *  *         *  ***   *  *        * *     *      *"<<endl;
    cout<<"         *    **    *    *       *   *  *     *  *       *  *          *         *   **   *  *        *   *   *      *"<<endl;
    cout<<"         *     *    *    *********   *    *   *  *********  *    ***** *******   *    *   *  *******  *    *  *      *"<<endl;
    cout<<"         *          *    *       *   *      * *  *       *  *       *  *         *        *  *        *     * *      *"<<endl;
    cout<<"         *          *    *       *   *        *  *       *   ********  *******   *        *  *******  *       *      *"<<endl; 
    cout<<"                                                                                   "<<endl; 
    cout<<"                           ******   *      *     ******   **********   *********     **      **                     "<<endl;
    cout<<"                          *      *   *    *     *      *      *        *             *  ***  *       "<<endl;
    cout<<"                          *           ****      *             *        *             *   **   *      "<<endl;
    cout<<"                             **        *           **         *        *********     *   **   *             "<<endl; 
    cout<<"                               **      *             **       *        *             *        *            "<<endl;
    cout<<"                          **    *      *        **     *      *        *             *        *           "<<endl;
    cout<<"                             ***       *           ***        *        *********     *        *            "<<endl;
    cout<<"                                        "<<endl;
    manage(esize,user,pwd,loggedInUserType,input,employeeData,customerData, customerComplain, stay, roomNo,category, bookedRooms, r,unbookedRooms,input1,salary,date,designation);
}
void manage(int esize, string user, string pwd, int loggedInUserType, int input, employee employeeData[], customer customerData[], string customerComplain[][8], string stay, string roomNo, string category, string bookedRooms[], int r, string unbookedRooms, int input1,string salary,string date,string designation)
{
        loggedInUserType=2;
        cout<<"Choose the desired option:\n";
        cout << left << setw(10) << "\t"
         << setw(25)<< "1-Administration login"
         <<setw(25)<< "2-Employee login"
         <<setw(25)<< "3-Customer "
         << setw(25)<<"0-Exit";
         cout<<endl;
         
         cin>>input;

         switch(input){
            case 1:
            {
                cout<<"Enter the username:"<<endl;
                cin>>user;
                cout<<"Enter the password:"<<endl;
                cin>>pwd;
                if(user=="Administrator"&&pwd=="HMS")
                {
                    loggedInUserType=1;
                }
                else{
                    loggedInUserType=-1;
                    cout<<"You have entered invalid credentials"<<endl;
                     manage(esize,user,pwd,loggedInUserType,input,employeeData,customerData, customerComplain, stay, roomNo,category, bookedRooms, r,unbookedRooms,input1,salary,date,designation);
                }
                break;
            }
            case 2:
            {

                cout<<"Enter the username:"<<endl;
                cin>>user;
                cout<<"Enter the password:"<<endl;
                cin>>pwd;
                
                    for(int j=0;j<esize;j++)
                {
                    if(user==employeeData[j].employeeName&&pwd==employeeData[j].password)
                     { 
                        loggedInUserType=2;
                        break;
                     }
                     if(loggedInUserType!=2)
                     {
                        cout<<"Employee not found"<<endl;
                        manage(esize,user,pwd,loggedInUserType,input,employeeData,customerData, customerComplain, stay, roomNo,category, bookedRooms, r,unbookedRooms,input1,salary,date,designation);
                        break;
                     }
                }
                
                break;
            }
            case 3:
            {
               
                loggedInUserType=3;
                break;
            }
            case 0:
            {
                cout<<"Thank you for using the system"<<endl;
                loggedInUserType=-10;
                break;
            }
         }
         if(loggedInUserType==1)
         {
            adminLogin( esize, user, pwd, input, input1, employeeData, customerData, customerComplain, stay, roomNo, category, r, bookedRooms, loggedInUserType,unbookedRooms,salary,date,designation);
         }
         else if(loggedInUserType==2)
         {
            employeeLogin(esize, user, pwd, input, input1, employeeData, customerData, customerComplain, roomNo, stay, category, r, bookedRooms, loggedInUserType, unbookedRooms,salary,date,designation);
         }
         else if(loggedInUserType==3)
         {
            customerLogin( esize, user, pwd, input, input1, customerData, customerComplain, roomNo, category, stay, unbookedRooms, loggedInUserType, employeeData,bookedRooms,r,salary,date,designation);
         }
}
void adminLogin(int esize, string user, string pwd, int input, int input1, employee employeeData[], customer customerData[], string customerComplain[][8], string roomNo, string stay, string category, int r, string bookedRooms[], int loggedInUserType, string unbookedRooms,string salary,string date,string designation)
{
     do{
            cout<<"Choose the desired option\n";
            cout<< left<<setw(10)<<"\t"
            <<setw(25)<<"1-Data of Employess"
            <<setw(25)<<"2-Data of Customers"
            <<setw(25)<<"3-Rooms"
            <<setw(25)<<"\n"
            <<setw(25)<<"4-Total Budget"
            <<setw(25)<<"5-Customer Reviews"
            <<setw(25)<<"0-Exit"
             <<setw(25)<<"\n";
            
            cout<<"Choose the option"<<endl;
            cin>>input;

             switch(input)
            {
                case 1:
                
                 cout<<"****************************************************************"<<endl;
                cout<<"               DATA   OF   EMPLOYESS"<<endl;
                cout<<"****************************************************************"<<endl;
                cout<<"Choose the desired option:\n";
                cout<< left<<setw(10)<<"\t"
                <<setw(25)<<"1-Add an employee"
                <<setw(25)<<"2- Delete an employee"
                <<setw(25)<<"3- List of employees"
                <<setw(25)<<"0- Exit";

                cin>>input1;
                if(input1==1)
                {
                
                     cout<<"Enter the name of the employee:"<<endl;
                    
                    cout<<"Enter the password you want to assign:"<<endl;
                
                    cout<<"Enter the salary:"<<endl;
                    
                    
                    cout<<"Enter the joining date:"<<endl;

                    cout<<"Enter the designation of the employee:"<<endl;
                    
                   bool a=loadData(employeeData);
                   cout<<a<<endl;
                   bool b=saveData(employeeData);
                   cout<<b<<endl;

                }
                    else if(input1==2)
                    {
                        cout<<"Enter the employee name you want to delete:"<<endl;
                        cin>>user;
                        for(int j=0;j<esize;j++)
                        {
                            if(employeeData[j].employeeName==user)
                            {
                                employeeData[j].employeeName="";
                                employeeData[j].password="";
                                employeeData[j].salary="";
                                employeeData[j].joiningDate="";
                                employeeData[j].designation="";
                                bool c=deleteData(employeeData,esize);
                                
                                
                                cout<<"Employee deleted successfully!"<<endl;
                                break;
                            }
                            else
                            {
                                cout<<"Employee not found:"<<endl;
                                adminLogin(esize, user, pwd, input, input1, employeeData, customerData, customerComplain, stay, roomNo, category, r, bookedRooms, loggedInUserType,unbookedRooms,salary,date,designation);
                            }
                        }
                        
                    }
                   else  if(input1==3)
                    {
                        cout<<left<<setw(15)<<"Employee Name"
                        <<setw(15)<<"\t"
                        <<setw(15)<<"Salary"
                        <<setw(15)<<"\t"
                        <<setw(15)<<"Joining Date"
                        <<setw(15)<<"\t"
                        <<setw(15)<<"Designation\n";
                        
                        
                        for(int j=0;j<esize;j++)
                        {
                            
                            cout<<left<<setw(15)<<employeeData[j].employeeName
                            <<setw(15)<<"\t"
                            <<setw(15)<<employeeData[j].salary
                            <<setw(15)<<"\t"
                            <<setw(15)<<employeeData[j].joiningDate
                            <<setw(15)<<"\t"
                            <<setw(15)<<employeeData[j].designation
                            <<setw(15)<<"\n";



                        }
                    }
                    else if(input1==0)
                    {
                        cout<<"Thank you"<<endl;
                        adminLogin( esize, user, pwd, input, input1, employeeData, customerData, customerComplain, stay, roomNo, category, r, bookedRooms, loggedInUserType,unbookedRooms,salary,date,designation);
                    
                    }
                        else
                        {
                            cout<<"Invalid Input"<<endl;
                            adminLogin( esize, user, pwd, input, input1, employeeData, customerData, customerComplain, stay, roomNo, category, r, bookedRooms, loggedInUserType,unbookedRooms,salary,date,designation);
                        }
                
                 break;
                  case 2:
                
                  cout<<"****************************************************************"<<endl;
                cout<<"               DATA   OF   CUSTOMERS"<<endl;
                cout<<"****************************************************************"<<endl;
                cout<<"Choose the desired option:\n";
                cout<< left<<setw(10)<<"\t"
                <<setw(25)<<"1-Add a customer"
                <<setw(25)<<"2-List of customers"
                <<setw(25)<<"3-Customer Complains"
                <<setw(25)<<"0- Exit";
                cin>>input1;
                if(input1==1)
                {
                    cout<<"Enter the name of the customer:"<<endl;
                    cin>>user;
                    cout<<"Enter the Room number:"<<endl;
                    cin>>roomNo;
                    r=r+1;
                    cin.ignore(256,'\n');
                    cout<<"Enter the stay duration:"<<endl;
                    getline(cin,stay);
                    cout<<"Enter the room category:"<<endl;
                    cin>>category;
                    for(int j=0;j<esize;j++)
                    {
                        if(customerData[j].customerName=="")
                        {
                            customerData[j].customerName=user;
                            customerData[j].roomNo=roomNo;
                            customerData[j].stay=stay;
                            bookedRooms[j]=roomNo;
                            customerData[j].category=category;
                            cout<<"Customer added successfully!"<<endl;
                            break;
                        }
                        else{
                            cout<<"No room is left"<<endl;
                            adminLogin( esize, user, pwd, input, input1, employeeData, customerData, customerComplain, stay, roomNo, category, r, bookedRooms, loggedInUserType,unbookedRooms,salary,date,designation);
                        }
                        break;
                    }
                 
                }
               else if (input1==2)
                {
                    cout<<left<<setw(15)<<"Customer Name"
                        <<setw(15)<<"\t"
                        <<setw(15)<<"Room Number"
                        <<setw(15)<<"\t"
                        <<setw(15)<<"Stay Duration"
                        <<setw(15)<<"\t"
                        <<setw(15)<<"Room Category\n";
                        

                        for(int j=0;j<esize;j++)
                        {
                    
                           cout<<left<<setw(15)<<customerData[j].customerName
                            <<setw(15)<<"\t"
                            <<setw(15)<<customerData[j].roomNo
                            <<setw(15)<<"\t"
                            <<setw(15)<<customerData[j].stay
                            <<setw(15)<<"\t"
                            <<setw(15)<<customerData[j].category
                            <<setw(15)<<"\n";
                        


                        } 
                }
                else if(input1==3)
                {
                    for(int j=0;j<8;j++)
                    {
                    cout<<left<<setw(25)<<customerComplain[0][j]
                    <<setw(25)<<'\n'
                    <<setw(25)<<customerComplain[1][j]
                    <<setw(25)<<"\n";
                    }
                }
                else if(input1==0)
                {
                    cout<<"Thank you"<<endl;
                    adminLogin( esize, user, pwd, input, input1, employeeData, customerData, customerComplain, stay, roomNo, category, r, bookedRooms, loggedInUserType,unbookedRooms,salary,date,designation);
                }
                else{
                    cout<<"Invalid Input"<<endl;
                    adminLogin( esize, user, pwd, input, input1, employeeData, customerData, customerComplain, stay, roomNo, category, r, bookedRooms, loggedInUserType,unbookedRooms,salary,date,designation);
                }
                break;
                 case 3:
                 rooms( esize, user, pwd, input,input1, unbookedRooms, r, bookedRooms);
                 break;
                case 4:
                budget();
                break;
                case 5:
                reviews();
                break;
                case 0:
                cout<<"Thank you for using the system"<<endl;
                 manage(esize,user,pwd,loggedInUserType,input,employeeData,customerData, customerComplain, stay, roomNo,category, bookedRooms, r,unbookedRooms,input1,salary,date,designation);
                break;
                default:
                cout<<"Invalid choice"<<endl;
                break;

            }
     }while(input!=0);
}
void employeeLogin(int esize, string user, string pwd, int input, int input1, employee employeeData[], customer customerData[], string customerComplain[][8], string roomNo, string category, string stay, int r, string bookedRooms[], int loggedInUserType, string unbookedRooms,string salary,string date,string designation)
{
     do{
            cout<<"Choose the desired option\n";
            cout<< left<<setw(10)<<"\t"
            <<setw(15)<<"1-Your Data"
            <<setw(15)<<"2-Rooms"
            <<setw(15)<<"3-Data of customers"
            <<setw(15)<<"\n"
            <<setw(15)<<"4-Customer Reviews"
            <<setw(15)<<"5-Total Budget"
            <<setw(15)<<"0-Exit";
            
            cout<<"Choose the option"<<endl;
            cin>>input;

            switch(input)
            {
                case 1:
                cout<<"**********************************************************"<<endl;
                cout<<"            YOUR      PERSONAL      DATA"<<endl;
                cout<<"**********************************************************"<<endl;
                    for(int j=0;j<esize;j++)
                    {
                        if(user==employeeData[j].employeeName)
                        {
                            cout<<left<<setw(25)<<"Name \t"
                            <<setw(15)<<"Salary \t"
                            <<setw(15)<<"Date of Joining\t "
                            <<setw(15)<<"Designation\n"
                            <<setw(15)<<employeeData[j].employeeName
                            <<setw(15)<<"\t"
                            <<setw(15)<<employeeData[j].salary
                            <<setw(15)<<"\t"
                            <<setw(15)<<employeeData[j].joiningDate
                            <<setw(15)<<"\t"
                            <<setw(15)<<employeeData[j].designation;
                            break;
                        }
                    }
                    break;
                    case 2:
                    rooms(esize, user, pwd, input, input1, unbookedRooms,r, bookedRooms);
                    break;
                    case 3:
                cout<<"****************************************************************"<<endl;
                cout<<"               DATA   OF   CUSTOMERS"<<endl;
                cout<<"****************************************************************"<<endl;
                cout<<"Choose the desired option:\n";
                cout<< left<<setw(10)<<"\t"
                <<setw(25)<<"1-Add a customer"
                <<setw(25)<<"2- List of customers"
                <<setw(25)<<"3-Customer Complains"
                <<setw(25)<<"0- Exit";
                cin>>input1;
                if(input1==1)
                {
                     cout<<"Enter the name of the customer:"<<endl;
                    cin>>user;
                    cout<<"Enter the Room number:"<<endl;
                    cin>>roomNo;
                    r=r+1;
                    cin.ignore(256,'\n');
                    cout<<"Enter the stay duration:"<<endl;
                    getline(cin,stay);
                    cout<<"Enter the room category:"<<endl;
                    cin>>category;
                    for(int j=0;j<esize;j++)
                    {
                        if(customerData[j].customerName=="")
                        {
                            customerData[j].customerName=user;
                            customerData[j].roomNo=roomNo;
                            customerData[j].stay=stay;
                            bookedRooms[j]=roomNo;
                            customerData[j].category=category;
                            cout<<"Customer added successfully!"<<endl;
                            break;
                        }
                        else{
                            cout<<"No room is left"<<endl;
                             employeeLogin(esize, user, pwd, input, input1, employeeData, customerData, customerComplain, roomNo, stay, category, r, bookedRooms, loggedInUserType, unbookedRooms,salary,date,designation);
                        }
                    }
                 
                }
               else if (input1==2)
                {
                    cout<<left<<setw(15)<<"Customer Name"
                        <<setw(15)<<"\t"
                        <<setw(15)<<"Room Number"
                        <<setw(15)<<"\t"
                        <<setw(15)<<"Stay Duration"
                        <<setw(15)<<"\t"
                        <<setw(15)<<"Room Category\n";

                        for(int j=0;j<esize;j++)
                        {
                           
                            cout<<left<<setw(15)<<customerData[j].customerName
                            <<setw(15)<<"\t"
                            <<setw(15)<<customerData[j].roomNo
                            <<setw(15)<<"\t"
                            <<setw(15)<<customerData[j].stay
                            <<setw(15)<<"\t"
                            <<setw(15)<<customerData[j].category
                            <<setw(15)<<"\n";


                        } 
                }
                else if(input1==3)
                {
                    for(int j=0;j<8;j++)
                    {
                    cout<<left<<setw(25)<<customerComplain[0][j]
                    <<setw(25)<<'\n'
                    <<setw(25)<<customerComplain[1][j]
                    <<setw(25)<<"\n";
                    }
                }
                else if(input1==0)
                {
                    cout<<"Thank you"<<endl;
                     employeeLogin(esize, user, pwd, input, input1, employeeData, customerData, customerComplain, roomNo, stay, category, r, bookedRooms, loggedInUserType, unbookedRooms,salary,date,designation);
                    
                }
                else{
                    cout<<"Invalid Input"<<endl;
                     employeeLogin(esize, user, pwd, input, input1, employeeData, customerData, customerComplain, roomNo, stay, category, r, bookedRooms, loggedInUserType, unbookedRooms,salary,date,designation);
                    
                }
                break;
                case 4:
                 reviews();
                 break;
                 case 5:
                 budget();
                 break;
                 case 0:
                  manage(esize,user,pwd,loggedInUserType,input,employeeData,customerData, customerComplain, stay, roomNo,category, bookedRooms, r,unbookedRooms,input1,salary,date,designation);
                 break;
                 default:
                 cout<<"Invalid Input"<<endl;
                 break;

            }
            }while(input!=0);
}
void customerLogin(int esize,string user,string pwd,int input,int input1,customer customerData[],string customerComplain[][8],string roomNo,string category,string stay,string unbookedRooms,int loggedInUserType,employee employeeData[],string bookedRooms[],int r,string salary,string date,string designation)
{
         cout<<"**************************************************************"<<endl;
         cout<<"      WELCOME  TO  THE  GRANG  MARINE   HOTEL  "<<endl;
         cout<<"**************************************************************"<<endl;
         cout<<"                                                           "<<endl;
         do{
         cout<<left<<setw(25)<<"\t"
         <<setw(15)<<"1-Information about unbooked rooms"
         <<setw(15)<<"\n"
         <<setw(25)<<"\t"
         <<setw(15)<<"2-Customer Reviews"
         <<setw(15)<<"\n"
         <<setw(25)<<"\t"
         <<setw(15)<<"3-Online Booking"
         <<setw(15)<<"\n"
         <<setw(25)<<"\t"
         <<setw(15)<<"4-Cancel Booking"
         <<setw(15)<<"\n"
         <<setw(25)<<"\t"
         <<setw(15)<<"5-Prices "
         <<setw(15)<<"\n"
         <<setw(25)<<"\t"
         <<setw(15)<<"6-Complain"
         <<setw(15)<<"\n"
         <<setw(25)<<"\t"
         <<setw(15)<<"0-Exit"
         <<endl;

         cout<<"Enter your choice"<<endl;
         cin>>input;

         switch(input)
         {
            case 1:
             cout<<"Unbooked rooms are:"<<endl;
            for(int i=0;i<5;i++)
            {
                cout<<unbookedRooms[i]<<endl;

            }
            break;
            case 2:
            reviews();
            break;
            case 3:
            cout<<"Enter your name"<<endl;
            cin>>user;
            cout<<"Enter the duration of stay:"<<endl;
            cin>>stay;
            cout<<"Enter the room category:"<<endl;
            cin>>category;
            cout<<"Enter the room no:"<<endl;
            cin>>roomNo;
            
           
            for (int j= 0; j < esize; j++)
            {
                if(customerData[j].customerName=="")
                {
                    customerData[j].customerName=user;
                    customerData[j].roomNo=roomNo;
                    customerData[j].stay=stay;
                    customerData[j].category=category;
                    cout<<"Thank you for choosing our hotel"<<endl;
                    break;

                }
                else{
                    cout<<"No room is left"<<endl;
                }
            }
            break;
            case 4:
            cout<<"Enter your name"<<endl;
            cin>>user;
            
           
            for (int j= 0; j < esize; j++)
            {
                if(customerData[j].customerName=="user")
                {
                    customerData[j].customerName="";
                    customerData[j].roomNo="";
                    cout<<"Your booking is cancelled!"<<endl;
                    break;

                }
               
            }
            break;
            case 5:
            cout<<"Prices for 1 day stay =    Rs. 10000"<<endl;
            cout<<"Prices for 24 hours stay =    Rs. 25000"<<endl;
            cout<<"Prices for 1 week stay  =    Rs. 54000"<<endl;
            cout<<"Prices for  1 month  stay=    Rs. 150000"<<endl;
            break;
            case 6:
            complain(customerData,customerComplain);
            break;
            case 0:
            cout<<"Thank you!"<<endl;
             manage(esize,user,pwd,loggedInUserType,input,employeeData,customerData, customerComplain, stay, roomNo,category, bookedRooms, r,unbookedRooms,input1,salary,date,designation);
            break;
            default:
            cout<<"Invalid Input"<<endl;
            break;
           
            

            
         }
         }while(input!=0);
}
void budget()
{
    int lastYearProfit=400000;
    int lossOf2022=150000;
    int jan=20000;
    int feb=15000;
    int march=20000;
    int april=40000;
    int may=35000;
    int june=14000;
    int july=25000;
    int august=36000;
    int sep=5000;
    int oct=10000;
    int nov=30000;

                cout<<"*****************************************************************"<<endl;
                cout<<"              BUDGET'S   INFORMATION"<<endl;
                cout<<"*****************************************************************"<<endl;
                cout<<"Loss of year 2022 is = \t"<<lossOf2022<<endl;
                cout<<"Hotel has gained profit last year which is of amount = \t"<<lastYearProfit<<endl;
                cout<<"Profit and Loss of running year:"<<endl;
                cout<<"January\tRs."<<jan<<"    Profit"<<endl;
                cout<<"February\tRs."<<feb<<"    Profit"<<endl;
                cout<<"March\tRs."<<march<<"    Profit"<<endl;
                cout<<"April\tRs."<<april<<"   Year's Biggest  Profit"<<endl;
                cout<<"May\tRs."<<may<<"    Profit"<<endl;
                cout<<"June\tRs."<<june<<"    Profit"<<endl;
                cout<<"July\tRs."<<july<<"    Profit"<<endl;
                cout<<"August\tRs."<<august<<"    Profit"<<endl;
                cout<<"September\tRs."<<sep<<"    Loss"<<endl;
                cout<<"October\tRs."<<oct<<"    loss"<<endl;
                cout<<"November\tRs."<<nov<<"    Profit"<<endl;
    

}
void reviews()
{
                cout<<"*****************************************************************"<<endl;
                cout<<"              CUSTOMER   REVIEWS"<<endl;
                cout<<"*****************************************************************"<<endl;
                cout<<"Kinza Junaid"<<endl;
                cout<<"\t The management of grand marina is excellent.Their food is very delicious."<<endl;
                cout<<"\t It's interior is very attractive."<<endl;
                cout<<"Maryam Rehman"<<endl;
                cout<<"\t Food quality and the taste is very awesome.Services 100 out of 100."<<endl;
                cout<<"\t Ambiance is also satisfactory."<<endl;
                cout<<"Tanzeel Mohsin"<<endl;
                cout<<"\t The hotel is perfect for tourists wanting easy access to local sites. "<<endl;
                cout<<"\t Everything is in walking distance or a short drive away."<<endl;
}
void rooms(int esize,string user,string pwd,int input,int input1,string unbookedRooms,int r,string bookedRooms[])
{
                cout<<"**************************************************************"<<endl;
                cout<<"               ROOMS  INFORMATION"<<endl;
                cout<<"*************************************************************"<<endl;
                cout<<left<<setw(15)<<"\t"
                <<setw(10)<<"Booked Rooms"
                <<setw(10)<<"\t"
                <<setw(10)<<"Unbooked Rooms"
                <<setw(10)<<"\n";
                unbookedRooms=10-r;
               
                    for(int i=0;i<5;i++)
                     {
                         cout<<left<<setw(15)<<"\t"
                        <<setw(10)<<bookedRooms[i]
                        <<setw(10)<<"\t"
                        <<setw(10)<<unbookedRooms<<"Rooms are still unbooked:"
                        <<setw(10)<<"\n";
                     }
}
void complain(customer customerData[],string customerComplain[][8])
{
    for(int j=0;j<8;j++)
    {
        if(customerComplain[0][j]=="N")
        {
            cout<<"Enter your name:"<<endl;
            cin>>customerComplain[0][j];
            cin.ignore(256,'\n');
            cout<<"Enter your complain:"<<endl;
            getline(cin,customerComplain[1][j]);
            cout<<"Your complain has been recorded!"<<endl;
            break;
            
        }
    }
    

}
bool loadData(employee employeeData[])
{
    system("cls");

    ifstream fin;
    fin.open("C:/Users/dell/Documents/employeedata.txt");
    int j=0;

    if(!fin)
    {
        return false;
    }
    
    while(!fin.eof())
    {
             getline(fin,employeeData[j].employeeName,',');
             getline(fin,employeeData[j].password,',');
             getline(fin,employeeData[j].salary,',');
             getline(fin,employeeData[j].joiningDate,',');
             getline(fin,employeeData[j].designation,'.');
             

             j++;
             
        
    

    }
        fin.close();
        return true;


}
bool saveData(employee employeeData[])
{
    system("cls");

    ofstream fout("C:/Users/dell/Documents/employeedata1.txt");
    if(!fout)
    {
        return false;
    }
    for(int j=0;j<10;j++)
    {
        if(employeeData[j].employeeName!="")
        {
            fout<< employeeData[j].employeeName<<",";
            fout<< employeeData[j].password<<",";
            fout<< employeeData[j].salary<<",";
            fout<< employeeData[j].joiningDate<<",";
            fout<< employeeData[j].designation;
            fout<<endl;


        }
    }
        fout.close();
        return true;
}
bool deleteData(employee employeeData[], int esize)
{
    system("cls");

    ofstream fout("C:/Users/dell/Documents/employeedata1.txt");
    if(!fout)
    {
        return false;
    }
    for(int j=0;j<esize;j++)
    {
        if(employeeData[j].employeeName!="")
        {
            fout<< employeeData[j].employeeName<<",";
            fout<< employeeData[j].password<<",";
            fout<< employeeData[j].salary<<",";
            fout<< employeeData[j].joiningDate<<",";
            fout<< employeeData[j].designation;
            fout<<endl;


        }
    }
}




            

         
         



            

         
         
