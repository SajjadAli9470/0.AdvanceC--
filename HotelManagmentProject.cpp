#include<iostream>
#include<string.h>
#include <iomanip>
#include <ctime>
using namespace std;
class Customer
{
	string name;	   			
	string address;				
	string phone;			
	int days=0;	    			
	float payment_advance;	
	double bill=0;				
	int booking_id;				
	int room;					
	int status;
public:
	Customer()
{
		days=0;
		payment_advance=0;
		bill=0;
		booking_id=0;
		status=0;
		room=0;
}
	void accept();				
	void display();				
	friend class room;
	friend class Hotel;
};
void Customer::accept()	
{
	cout<<"Enter customer name: ";
	getline(cin, name);
	getline(cin, name);
	cout<<"Enter Customer address: ";
	getline(cin,address);
	flag:
	cout<<"Enter mobile number: ";
	cin>>phone;
	for(int i=0;i<(phone.length());i++)
  	{								
		if(!isdigit(phone[i]))
		{
			cout<<"Phone number has to be in digits.\n";
			goto flag;
		}
  	}
  	if(phone.length()!=10)	
  	{
  	  cout<<"Phone number should be 10 digits.\n";
  	  goto flag;
 	 }
}
//

void Customer::display()	
{
	cout<<booking_id<<"\t\t";
	cout<<"| "<<left<<setfill(' ')<<setw(30)<<name;
	cout<<"| "<<phone<<"\t\t\t";
	cout<<"| "<<left<<setfill(' ')<<setw(30)<<address;
	cout<<"| "<<room<<"\t\t\t";
	if(status==1){cout<<"|\t\t-\t\t|"<<endl;}
	else{cout<<"|\tCHECKED OUT.\t\t|"<<endl;}
}
class Room
{
	char type;				
	char stype;				
	char ac;				
	int roomNumber;			
	double rent;			
	int status=0;			
public:
	friend class Hotel;
	void acceptroom(int rno);		
	void displayroom();		
	Room()					
	{
		type='\0';
		stype='\0';
		ac='\0';
		roomNumber=0;
		rent=0;
		status=0;
	}
};
void Room::acceptroom(int rno)		
{
	roomNumber=rno;	
	cout<<"Type AC/Non-AC (A/N) : ";
	cin>>ac;
	while(ac!='A'|| ac!='a'&& ac!='N'||ac!='n')		
	{
		cout<<"Please Re-Enter Type: AC/Non-AC (A/N) : ";
		cin>>ac;
	}
	cout<<"Type Comfort Suite or Normal (S/N) : ";
	cin>>type;
	while(type!='S'||type!='s' && type!='N'||type!='n')
	{
		cout<<"Please Re-enter Type Comfort Suite or Normal (S/N) : ";
		cin>>type;
	}
	cout<<"Type Size (B/S) : ";
	cin>>stype;
	while(stype!='B'||stype!='b'&& stype!='S'||stype!='s')
	{
		cout<<"Please Re-enter Type Size (B/S) : ";
		cin>>stype;
	}
	cout<<"Daily Rent : ";
	cin>>rent;
	while(rent<0 || rent>20000)
	{
		cout<<"Please enter valid rent.";
		cin>>rent;
	}
	status=0;	//BOOKING STATUS OF THE ROOM
	cout<<"\nRoom Added Successfully!"<<endl;
}
void Room::displayroom()
{
	cout<<"| "<<roomNumber<<".\t\t|\t"<<ac<<"\t\t|\t"<<type<<"\t\t|\t"<<stype<<"\t\t|\t"<<rent<<"\t\t|\t";
	if(status==0){cout<<"Available.\t|";}
	else{cout<<"Booked.\t\t|";}
	cout<<endl;
}
//class Hotel
class Hotel
{
	Room a[100];		
	Customer c[100];			
	int nroom=0, ncust=0;	
public:
	void addRooms();		
	void searchroom();		
	void CheckIn();			
	void searchcust();		
	void availability();	
	void CheckOut();		
	void Summary();	
};
void Hotel::addRooms()
{
	int rno;
	cout<<"Enter number of rooms: ";
	cin>>nroom;		
	while(nroom<=0)
	{
		cout<<"Invalid. Enter valid number of rooms.";
		cin>>nroom;
	}
	for(int i=0;i<nroom;i++)
	{
		cout<<"ROOM "<<(i+1)<<endl;
		flag:
		cout<<endl<<"Enter room number : ";
		cin>>rno;
		if(rno<=0)	
		{
			cout<<endl<<"This room number is invalid! Please Re-enter the room number : ";
			goto flag;
		}
		for(int i=0; i<nroom;i++)
		{
			if(a[i].roomNumber==rno)
			{
				cout<<"Invalid. Repetitive room numbers."<<endl;
				goto flag;
			}
		}
		a[i].acceptroom(rno);	
	}
}
void Hotel::availability()		
{
	if(nroom==0)
	{
		cout<<"Please add rooms."<<endl;
		return;
	}
	cout<<"The list of all available rooms:"<<endl;
	cout<<"| Room No.\t|\tAC/Non-AC\t|\tType\t\t|\tStype\t\t|\tRent\t\t|\tAvailability  \t|"<<endl;
	for(int i=0;i<nroom;i++)
	{
		a[i].displayroom();	
	}
}
void Hotel::searchroom()	
{
	if(nroom==0)
	{
		cout<<"Please add rooms."<<endl;
		return;
	}
	int flag=0;
	char ac1, type1, stype1;
	cout<<"Do you want AC or Non-AC? (A/N): "<<endl;
	cin>>ac1;
	cout<<"Do you want suite or normal room?"<<endl;
	cin>>type1;
	cout<<"Size? (B/S)"<<endl;
	cin>>stype1;
	for(int i=0;i<nroom;i++)
	{
		if(a[i].ac==ac1 && a[i].type==type1 && a[i].stype==stype1)	
		{
			flag=1;
			cout<<"Room found"<<endl;
			a[i].displayroom();
		}
	}
	if(flag==0)
	{
		cout<<"No such room is available."<<endl;
	}
}
void Hotel::CheckIn()		
{
	if(nroom==0)
	{
		cout<<"Please add rooms."<<endl;
		return;
	}
	int i, rno;
	if(ncust<=nroom){	
		c[ncust].booking_id=ncust+1;	
		flag:
		int flag1=0;
		cout<<"Enter room number=";	
		cin>>rno;
		for(i=0;i<nroom; i++){
			if(rno==a[i].roomNumber)
			{
				flag1=1;
				break;
			}
		}
		if(flag1==0){
			cout<<"Invalid room number. Please Enter again.\n";
			goto flag;
		}
		if(a[i].status==0)	
		{
			char ch2;
			cout<<"Room available."<<endl;
			a[i].displayroom();
			cout<<"Do you wish to continue? Press(Y/y)";		
			cin>>ch2;
			if(ch2=='Y'||ch2=='y')
			{
				c[ncust].accept();		
				cout<<"Enter number of days of stay: ";
				cin>>c[ncust].days;
				c[ncust].bill = c[ncust].days*a[i].rent;	
				cout<<"Your total bill will approx be Rs."<<(c[ncust].bill)<<"."<<endl<<". Min adv payment="<<c[ncust].bill/4<<"What will you be paying?";
				cin>>c[ncust].payment_advance;
				while(c[ncust].payment_advance<c[ncust].bill/4||c[ncust].payment_advance>c[ncust].bill)
				{
					cout<<"Enter valid amount.";
					cin>>c[ncust].payment_advance;
				}
				cout<<"Thank you. Booking confirmed."<<endl;		
				cout<<"--------------------------------------------------------------"<<endl;	
				cout<<"Booking Id: "<<c[ncust].booking_id<<"\nName: "<<c[ncust].name<<"\nRoom no.: "<<rno<<"\nDate: ";
				time_t my_time = time(NULL);
					
				printf("%s", ctime(&my_time));
				a[i].status=1;
				c[ncust].room=rno;	
				c[ncust].status=1;
				ncust++;
			}
			else
			{
				goto flag;
			}
		}
		else	
		{
			cout<<"Room Occupied. Please choose another room."<<endl;
		}
	}
	else		
	{
		cout<<"Sorry! Hotel is Full."<<endl;
	}
}
void Hotel::searchcust()
{
	int id, flag=0;
	cout<<"Enter booking id of customer.";
	cin>>id;
	for(int i=0;i<=ncust;i++)		
	{
		if(c[i].booking_id==id)
		{
			cout<<"\t\t\t Name"<<setw(20);
			cout<<"\t\t\t Phone"<<setw(20);
			cout<<"\t\t\t Address"<<setw(20);
			cout<<"\t\t\tRoom no: "<<setw(20)<<endl;
			c[i].display();
			flag=1;
		}
	}
	if(flag==0)	
	{
		cout<<"No customer found."<<endl;
	}
}
void Hotel::CheckOut()		
{
	int rno, i, j;
	cout<<"Enter room number= ";
	cin>>rno;
	for(j=0;j<nroom; j++){
		if(rno==a[j].roomNumber)
		{
			break;
		}
	}
	if(a[j].status==0)
	{
		cout<<"Invalid."<<endl;
	}
	for(i=0;i<ncust;i++)
	{
		if(c[i].room==rno)
		{
			cout<<"CHECKING OUT."<<endl;
			c[i].display();		
			cout<<"Your total bill is "<<c[i].bill<<endl;
			cout<<"Adv payment: "<<c[i].payment_advance;
			cout<<endl<<"Hence, pending payment= Rs."<<c[i].bill-c[i].payment_advance;				cout<<endl<<"Thank you! Visit Again :)"<<endl;
			a[j].status=0;	
			c[i].status=0;	
			break;
		}
	}
}
void Hotel::Summary()
{
	if(nroom==0)
	{
		cout<<"No customers as yet."<<endl;
		return;
	}
	cout<<"Guest Summary:"<<endl;
	cout<<"Id.\t\t";
	cout<<"|	Name	\t\t";
	cout<<"|	Phone	\t\t";
	cout<<"|	Address	\t\t";
	cout<<"|	Room no	: \t";
	cout<<"|	Status	\t\t|"<<endl;
	for(int i=0;i<ncust;i++)
	{
		c[i].display();
	}
}

int main()
{
	Hotel Taj;		
	char ch;
	    cout<<endl<<"==================Welcome to Guest House==========================";
	do
	{		
		cout<<endl<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<endl<<"\t\t\t"
				"MENU:\n\t\t\t"
				"1.OPERATE AS ADMIN\n\t\t\t"
				"2.OPERATE AS CUSTOMER\n\t\t\t"
				"3.EXIT\n\t\t\t"
				"Enter your choice:";
		cin>>ch;
		switch(ch)
		{
		case '1':
			cout<<"Add database of rooms in the hotel:"<<endl;
			Taj.addRooms();
			cout<<"Database updated. Going back to main menu."<<endl;
			break;
		case '2':
			char ch1;
			do
			{
				
				cout<<endl<<"***************************************************************"<<endl;
				      cout<<"======================Welcome to Guest House==================="<<endl;
				cout<<"\n\t\t\t"
						"Menu:\n\t\t\t"
						"1.Check Availability of rooms.\n\t\t\t"
						"2.Search Room\n\t\t\t"
						"3.Check In\n\t\t\t"
						"4.Search Customer\n\t\t\t"
						"5.Guest Summary\n\t\t\t"
						"6.Checkout.\n\t\t\t"
						"7.Go back to Main Menu.\n\t\t\t"
						"Enter your choice:";
				cin>>ch1;
				switch(ch1)
				{
				case '1':
					Taj.availability();
					break;
				case '2':
					Taj.searchroom();
					break;
				case '3':
					Taj.CheckIn();
					break;
				case '4':
					Taj.searchcust();
					break;
				case '5':
					Taj.Summary();
					break;
				case '6':
					Taj.CheckOut();
					break;
				case '7':
					break;
				default:
					cout<<"Invalid Choice."<<endl;
					break;
				}
			}while(ch1!='7');
			break;
		case '3':
			cout<<"Thank you!";
			exit(0);
		default:
			cout<<"Invalid Choice."<<endl;
			break;
		}
	}while(ch!='3');
	return 0;
}
