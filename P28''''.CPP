
/************************************************************************************************************
				 P R O J E C T   O N
			      T R A V E L   A G E N C Y
**************************************************************************************************************/

#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<process.h>
#include<ctype.h>
#include<string.h>
#include<dos.h>


//functions declarations

void neww(char a[]);
void search(char a[]);
void see(char a[]);
void cancel(char a[]);
void update(char a[]);
void addvehicle();
void searchvehicle(char category[], char name[]);
float search_vehicle(char category[], char name[]);
void allvehicle(char category[]);
float checkvehicle(char category[], char name[]);
int check_alphabet( char a[] );
int check_digit( char a[] );
void disp1();
void disp2();

// stream file declarations

fstream trav;
fstream vehi;
fstream hote;
fstream extra;
char yes='y';

// global variables

int i;
int x,m;


// declaration of classes

// for hotel related services

 class HOTEL
 {  char hotel[20],city[10];
    int rooms,totalrooms,available;
    int id,box;
    float price;
    char custname[15],custadd[20],contact[11];


    public : HOTEL()
	    {
	       strcpy(hotel,"TOURIST ZONE");
	       strcpy(city,"NULL");
	       totalrooms=100;
	       rooms=0;
	       price=3999;
	       available=100;

	    }

	    int hotelid(int a);   //to maintain unique hotel ID

	    void getdata();

	    void putdata()
	    {  cout<<"\nID : "<<id
		   <<"\nCustomer : "<<custname
		   <<"\nAddress : "<<custadd
		   <<"\nContact number : "<<contact
		   <<"\n\nHotel booked : "<<hotel
		   <<"\nHotel city : "<<city
		   <<"\nRooms booked : "<<rooms;

	    }


	    void dispall()             // special format to show bookings
	    {  cout<<setw(4)<<id<<"  ";
	       cout<<setw(15)<<custname<<"   ";
	       cout<<setw(18)<<hotel<<"   ";
	       cout<<setw(10)<<city<<"   ";
	       cout<<setw(3)<<rooms<<"     ";

	    }
	    void bill();

	    char *returnname()
	    {   return custname;
	    }
	    int returnregist()
	    {  return id;
	    }
 }h,h2;


 void HOTEL::getdata()
 {
       hotel :   cout<<"Enter your hotel ID : ";
	       cin>>id;
	       box=hotelid(id);
	       if(box==1)
	       {
		 cout<<"\nThis ID is already in use.\n"
		       "press any key to register with another ID.";
		  goto hotel;
	       }

      name:    cout<<"Enter the name of the customer : ";
	       gets(custname);
	       if(check_alphabet( custname)==0)
	       {
		 cout<<"\nINVALID NAME ENTERED!!!  PLEASE RE-ENTER:-\n";
		 goto name;
	       }
	       cout<<"Enter the address of the customer : ";
	       gets(custadd);


      contact: cout<<"Enter the contact number of customer : ";
	       cin>>contact;
	       contact[10]='\0';
	       if(check_digit(contact)==0)
	       {
		 cout<<"\nINVALID MOBILE NUMBER ENTERED!!!  PLEASE REENTER\n";
		 goto contact;
	       }

       hotels:  cout<<"Enter the hotel name(extra charge) or press enter for our hotel : ";
	       gets(hotel);
	       if(check_alphabet(hotel)==0)
	       {
		 cout<<"\nINVALID NAME ENTERED!!! PLEASE RE-ENTER:-\n";
		 goto hotels;
	       }
       city :
	       cout<<"Enter the city of hotel : ";
	       gets(city);
	       if(check_alphabet(city)==0)
	       {
		 cout<<"\nINVALID CITY ENTERED!!!  PLEASE REENTER:-\n";
		 goto city;
	       }

	       cout<<"Enter the number of rooms you want to book : ";
	       cin>>rooms;


	    }

 void HOTEL::bill()
	    {

		cout<<"Enter the number of rooms booked : ";
		cin>>rooms;
		price=rooms*3999;
		cout<<"Billing information is given below :-\n\n"
			 "______________________________________\n"
			 "              RECEIPT                 \n"
			 "______________________________________\n\n"
			 "     Name : "<<custname<<"\n"
			 "     Address : "<<custadd<<"\n"
			 "     Contact : "<<contact<<"\n"
			 "     Hotel : "<<hotel<<"\n"
			 "     City : "<<city<<"\n"
			 "     Rooms : "<<rooms<<"\n"
			 "_______________________________________\n"
			 "              Price : "<<price<<"\n"
			 "_______________________________________\n";

	       }


 int HOTEL::hotelid(int a)   //to maintain uniqueness of hotel ID
 {
       hote.open("hotel.dat",ios::binary|ios::in);
       int box=0;
       while(!hote.eof())
     {
	hote.read((char*)&h2,sizeof(h2));
	if(hote.eof())
	break;
	if(a==h2.returnregist())
	{


		 box=1;
		 getch();
		 break;
	}

     }

	hote.close();
	return box;
 }

 class vehicle
 {
    int units;
     char vehino[10],vname[15],category[3],city[10];
     float tempprice;
     public :


      void vehiGetdata()
      {   cout<<"Enter the category of vehicle (car/bus) : ";
	  cin>>category;
	  cout<<"Enter the model : ";
	  gets(vname);
	  cout<<"Enter the vehicle number : ";
	  cin>>vehino;
	  cout<<"Enter the number of units : ";
	  cin>>units;
	  cout<<"Enter the price for fare : ";
	  cin>>tempprice;
      }
      void vehiShowdata()
      {   cout<<"\nCategory : "<<category
	      <<"\nModel : "<<vname
	      <<"\nVehicle number : "<<vehino
	      <<"\nNumber of units : "<<units
	      <<"\nPrice per KM : "<<tempprice;
      }
      void vehiShowall()
      {   cout<<setw(8)<<vname<<setw(10)<<vehino<<setw(6)<<units<<setw(7)<<tempprice;
      }




		char *returncategory()
		{  return category;
		}
		char *returnmodel()
		{  return vname;
		}
		float return_tempPrice()
		{   return tempprice;
		}

      }t3;
 // For tourism related services
 class travel  : public vehicle
 {
      int id,box,units;
      char name[15];
      char vehino[10],vname[15],category[3],city[10];
      char address[20];
      char contact[11];
      char destination[15];
      float distance,price,tempprice;



      public :
		 travel()
		 {
		   box=0;
		   price=0;
		   strcpy(address,"NULL");
		   strcpy(name,"NULL");
		   strcpy(destination,"NULL");
		   distance=0;
		   strcpy(contact,"XXXXXXXXXX");
		   id=0;
		 }




		char *returncategory()
		{  return category;
		}
		char *returnmodel()
		{  return vname;
		}
		float return_tempPrice()
		{   return tempprice;
		}


		 travel(char catego[],char model[],float temp_price)
		 {  strcpy(category,catego);
		    strcpy(vname,model);
		    price=temp_price;
		 }

		 int travelid(int a);      //to assure for id uniqueness
		 void getdata();

		 void putdata()
		{  cout<<"\nID ; "<<id
		       <<"\nTraveller name ; "<<name
		       <<"\nAddress : "<<address
		       <<"\nContact number : "<<contact
		       <<"\nDestination : "<<destination;


		}

		int returnregist()
		{  return id;
		}

		char *returnname()
		{  return name;
		}


		void modify(char n[])
		{
		   strcpy(name,n);
		   cout<<"Enter the contact number of traveller : ";
		   cin>>contact;
		   cout<<"Enter the destination(only characters) : ";
		   gets(destination);


		}

		void modify(int reg)
		{
		    id=reg;
		    cout<<"Enter the contact number of traveller : ";
		    cin>>contact;
		    cout<<"Enter the destination(only characters) : ";
		    gets(destination);


		 }

		void dispall()             //format to show all bookings
		{
		  cout<<setw(5)<<id;
		  cout<<setw(15)<<name<<"   ";
		  cout<<setw(14)<<destination<<"  ";

		  cout<<setw(15)<<vname<<"   ";
		  cout<<setw(9)<<price;
		}

		void bill()
		{

		   cout<<"Enter the distance travelled : ";
		   cin>>distance;
		   price=distance*price+1000;
		   cout<<"Billing information is given below :-\n\n"
			 "______________________________________\n"
			 "              RECEIPT                 \n"
			 "______________________________________\n\n"
			 "     Name : "<<name<<"\n"
			 "     Address : "<<address<<"\n"
			 "     Contact : "<<contact<<"\n"
			 "     Destination : "<<destination<<"\n"
			 "     Distance : "<<distance<<"\n"
			 "     Vehicle name : "<<vname<<"\n"
			 "_______________________________________\n"
			 "              Price : "<<price<<"\n"
			 "_______________________________________\n";
		   }



 }t,t2;

 void travel::getdata()
 {
		  travel :
		  cout<<"\nEnter any number as you ID : ";
		  cin>>id;
		  box=travelid(id);
		  if(box==1)
		  { cout<<"\nEnter the details again.\n\n";
		    goto travel;
		  }

	  name :  cout<<"Enter the traveller name : ";
		  gets(name);

		  if(check_alphabet(name)==0)
		  {
		    cout<<"\nINVALID NAME ENTERED!!!  PLEASE REENTER:-\n";
		    goto name;
		  }

	  contact: cout<<"Enter the contact number of traveller : ";
		  cin>>contact;
		  contact[10]='\0';
		  if(check_digit(contact)==0)
		 {
		    cout<<"\nINVALID CONTACT NUMBER ENTERED!!!  PLEASE REENTER:-\n";
		    goto contact;
		 }
		    cout<<"Enter the address of traveller : ";
		    gets(address);


	  city:   cout<<"Enter the destination(only characters) : ";
		  gets(destination);
		  if(check_alphabet(destination)==0)
		  {
		    cout<<"\nINVALID CITY ENTERED!!!  PLEASE REENTER:-\n";
		    goto city;
		  }

		  cout<<"\nRegistered successfully with ID"<<id;
		  }

//to check uniqueness of travel ID
 int travel::travelid(int a)
 {
     trav.open("travel.dat",ios::binary|ios::in);
     int box=0;
     while(!trav.eof())
    {
	trav.read((char *)&t2,sizeof(t2));
	if(trav.eof())
	break;
	if(a==t2.returnregist())
	{  cout<<"\nThis ID is already in use.\n"
		 "press any key to register with another ID.";
		 box=1;
		 break;

       }
    }
    trav.close();
    return box;
 }


//********************** void main starts ****************************************************************************

 void main()
 {    clrscr();
      char choice;
      char yes='y';
      char category[3],model[15];  //for vehicle related services
      float price;

	   char a[]={"  WELCOME TO THE PROGRAM BASED ON TRAVEL AGENCY\n\n\t"
		     "        PRESS ANY KEY TO CONTINUE . . ."};

      cout<<"\n\n\n\n\n\n\t";

      for(int q=0;a[q]!='\0';q++)
      {  cout<<a[q];
	 delay(60);          //to slow down speed of loop
      }
      getch();

     for(m=1;;m++)        // Infinite loop to display menu again and again
   {
      char a=char(15);



      clrscr();

      cout<<"\n\n\n\n\n\n\t\t\t";

      for(i=0;i<=13;i++)
      cout<<a<<" ";

    cout<<"\n\t\t\t"<<a<<"                         "<<a<<"\n"
	    "\t\t\t"<<a<<"      H O M E            "<<a<<"\n"
	    "\t\t\t"<<a<<"                         "<<a<<"\n"
	    "\t\t\t"<<a<<"  1. Travel and tourism  "<<a<<"\n"
	    "\t\t\t"<<a<<"  2. Book hotel          "<<a<<"\n"
	    "\t\t\t"<<a<<"  3. Manage vehicles     "<<a<<"\n"
	    "\t\t\t"<<a<<"  4. Exit                "<<a<<"\n"
	    "\t\t\t"<<a<<"                         "<<a<<"\n\t\t\t";
      for(i=0;i<=13;i++)
      cout<<a<<" ";

      cout<<"\n\n\t\t\t    Enter your choice : ";
      cin>>choice;
      switch(choice)
     {
		case '1' : clrscr();
			   yes='y';
			   a=char(157);
			   disp1();

			   for(x=0; ;x++)
			 {
				 clrscr();

			    cout<<"\n\n\n\n\t\t\t";
			    for(i=1;i<=14;i++)
			    cout<<a<<" ";

			       cout<<"\n\t\t\t"<<a<<"                         "<<a<<"\n"
				       "\t\t\t"<<a<<"        M E N U          "<<a<<"\n"
				       "\t\t\t"<<a<<" 1.   Make new trip      "<<a<<"\n"
				       "\t\t\t"<<a<<" 2.   See all trips      "<<a<<"\n"
				       "\t\t\t"<<a<<" 3.   Search for a trip  "<<a<<"\n"
				       "\t\t\t"<<a<<" 4.   Update a trip      "<<a<<"\n"
				       "\t\t\t"<<a<<" 5.   Cancel a trip      "<<a<<"\n"
				       "\t\t\t"<<a<<" 6.   Display bill       "<<a<<"\n"
				       "\t\t\t"<<a<<" 7.   Back to home       "<<a<<"\n"
				       "\t\t\t"<<a<<"                         "<<a<<"\n\t\t\t";
			    for(i=1;i<=14;i++)
			    cout<<a<<" ";
			 cout<<"\n\n\t\t\t     Enter your choice : ";
				cin>>choice;
				switch(choice)
				{     case '1' : clrscr();
						 cout<<"To register for new trip,\nEnter the details below:-\n";
						 neww("trip");

						 cout<<"\n\nPress any key to go back.";
						 getch();
						 break;

				      case '2' : clrscr();
						 see("trip");
						 cout<<"\n\nPress any key to go back.";
						 getch();
						 break;

				      case '3' : clrscr();
						 search("trip");
						 cout<<"\n\nPress any key to go back.";
						 getch();
						 break;

				      case '4' : clrscr();
						 cout<<"To update record, Enter the details:-\n\n";
						 update("trip");
						 cout<<"\n\nPress any key to go back.";
						 getch();
						 break;

				      case '5' : clrscr();
						 cout<<"To cancel registration, Enter the details :-\n\n";
						 cancel("trip");
						 cout<<"\n\nPress any key to go back.";
						 getch();
						 break;

				      case '6' : clrscr();
						 int id; char found='n';
						 cout<<"Enter your ID for bill ";
						 cin>>id;
						 trav.open("travel.dat",ios::binary|ios::in);
						 while(!trav.eof())
						 {
						    trav.read((char*)&t,sizeof(t));
						    if(trav.eof())
						    break;
						    if(t.returnregist()==id)
						    {  found='y';
						       t.bill();
						       getch();
						       break;
						    }
						    else
						    found='n';
						 }
						 if(found=='n')
						 cout<<"Not found!\nPlease re-enter.\n";
						 trav.close();
						 break;

				      case '7' : yes='n';
						 break;

				      default  : cout<<"\nINVALID CHOICE ENTERED!!!";
				}             //switch statement terminates
			       if(yes=='n')
			       break;
		     }                        //loop terminates on case 6
		     break;
		case '2' : clrscr();
			   yes='y';
			   a=char(157);
			   disp2();
			   for(x=0; ; x++)
		     {     clrscr();

			   cout<<"\n\n\n\n\t\t\t";
			   for(i=1;i<=14;i++)
			    cout<<a<<" ";
			 cout<<"\n\t\t\t"<<a<<"                         "<<a<<"\n"
				 "\t\t\t"<<a<<"        M E N U          "<<a<<"\n"
				 "\t\t\t"<<a<<" 1.   Book a hotel       "<<a<<"\n"
				 "\t\t\t"<<a<<" 2.   See all bookings   "<<a<<"\n"
				 "\t\t\t"<<a<<" 3.   Search a booking   "<<a<<"\n"
				 "\t\t\t"<<a<<" 4.   Update booking     "<<a<<"\n"
				 "\t\t\t"<<a<<" 5.   Cancel reservation "<<a<<"\n"
				 "\t\t\t"<<a<<" 6.   Display Bill       "<<a<<"\n"
				 "\t\t\t"<<a<<" 7.   Back to home       "<<a<<"\n"
				 "\t\t\t"<<a<<"                         "<<a<<"\n\t\t\t";

			    for(i=1;i<=14;i++)
			    cout<<a<<" ";

			    cout<<"\n\n\t\t     Enter your choice : ";

			   cin>>choice;
			   switch(choice)
			   {
			       case '1' : clrscr();
					    cout<<"To book a room,\nEnter the details below:-\n";
					    neww("hotel");
					    cout<<"\n\nPress any key to go back.";
					    getch();
					    break;

			       case '2' : clrscr();
					    see("hotel");
					    cout<<"\n\nPress any key to go back.";
					    getch();
					    break;

			       case '3' : clrscr();
					    search("hotel");
					    cout<<"\n\nPress any key to go back.";
					    getch();
					    break;

			       case '4' : clrscr();
					    cout<<"To update record, Enter the details:-\n\n";
					    update("hotel");
					    cout<<"\n\nPress any key to go back.";
					    getch();
					    break;

			       case '5' : clrscr();
					    cout<<"To cancel booking, Enter the details :-\n\n";
					    cancel("hotel");
					    cout<<"\n\nPress any key to go back.";
					    getch();
					    break;

			       case '6' : clrscr();
					  char found='n';
					  int id;
					  cout<<"Enter you ID : ";
					  cin>>id;
					  hote.open("hotel.dat",ios::in|ios::binary);
					  while(!hote.eof())
					  {  hote.read((char *)&h,sizeof(h));
					     if(hote.eof())
					     break;
					     if(h.returnregist()==id)
					     {  found='y';
						h.bill();
						break;
					     }
					     else
					     {   found='n';
					     }
					  }
					  if(found=='n')
					  cout<<"Not found!";

					  getch();
					  break;
			       case '7' : yes='n';
					    break;

			       default : cout<<"\nINVALID CHOICE ENTERED!!!";
			   }
			  if(yes=='n')
			  break;
		     }
			  break;

		case '3' : clrscr();
			     yes='y';
			     char category[3],model[15];
			     char pass[15];
			     cout<<"\nThis option can be accessed by admin only."
				   "\nEnter the password to access : ";
			     for(i=0; ;i++)
			     {  pass[i]=getch();
				cout<<"*";
				if(pass[i]=='\r')
				{  pass[i]='\0';
				   break;
				}
			     }
			     if(strcmp(pass,"aditya")!=0)
			     { cout<<"\n\nACCESS DENIED!!!"
				     "\nPRESS ANY KEY TO GO BACK.";
				     getch();
				     break;
			     }
			     else
			  {
			     cout<<"\nPassword is correct.\npress any key to contnue.";
			     getch();




			     for(x=0; ;x++)
			     {      clrscr();

			     a=char(1);
			     cout<<"\n\n\n\n\t\t\t";
			     for(i=1;i<=13;i++)
			     cout<<a<<" ";


				  cout<<"\n\t\t\t"<<a<<"                       "<<a<<"\n"
					  "\t\t\t"<<a<<"        M E N U        "<<a<<"\n"
					  "\t\t\t"<<a<<"		        "<<a<<"\n"
					  "\t\t\t"<<a<<" 1.   Add vehicle      "<<a<<"\n"
					  "\t\t\t"<<a<<" 2.   Search vehicle   "<<a<<"\n"
					  "\t\t\t"<<a<<" 3.   See all vehicles "<<a<<"\n"
					  "\t\t\t"<<a<<" 4.   Back to home     "<<a<<"\n"
					  "\t\t\t"<<a<<"		        "<<a<<"\n\t\t\t";


				 for(i=1;i<=13;i++)
			     cout<<a<<" ";

				 cout<<"\n\n\t\t\t     Enter your choice : ";
				    cin>>choice;
				    switch(choice)
				    {
				       case '1' : clrscr();
						  addvehicle();
						  cout<<"\n\nPress any key to go back.";
						  getch();
						  break;

				       case '2' : clrscr();
						  cout<<"Enter the category to search(car/bus) : ";
						  cin>>category;
						  cout<<"Enter the model name : ";
						  gets(model);
						  searchvehicle(category,model);
						  cout<<"\n\nPress any key to go back.";
						  getch();
						  break;

				       case '3' : clrscr();
						  cout<<"Enter the category of vehicle(car/bus) : ";
						  cin>>category;
						  allvehicle(category);
						  cout<<"\n\nPress any key to go back.";
						  getch();
						  break;

				       case '4' : yes='n';
						  break;

				       default  : cout<<"\nWRONG CHOICE ENTERED!!!\n";
				    }
				  if(yes=='n')     //loop terminates on case 5
				  break;

			     }  //else statement terminates
		     }
		     break;
		case '4' : clrscr();
			   char z[]={" THANKS FOR USING PROGRAM MADE BY ADI.\n PRESS ANY KEY TO EXIT..."};
			   for(i=0;z[i]!='\0';i++)
			   {  cout<<z[i];
			      delay(50);
			   }
			   getch();
			   exit(0);
			   break;

		default : clrscr();
			  cout<<"\nINVALID CHOICE ENTERED!!!"
				"\nPRESS ANY KEY TO ENTER A VALID CHOICE.";
			  getch();
	}


  }   //infinite loop terminates

 }   //void main terminates



//******************** functions for hotel and tourisn related services************************************************

//for new registrations
void neww(char a[])
{
   char y;
   if(strcmp(a,"trip")==0)
    {
	      char category[3],model[15];
	      float price=0;

	      extra.open("travel.dat",ios::binary|ios::out|ios::app);

	      again :
	      cout<<"\nEnter the category of vehicle to travel (car/bus) : ";
	      cin>>category;
	      cout<<"Enter the model name of "<<category<<" : ";
	      gets(model);
	      price=search_vehicle(category,model);  //to check availability of vehicle

	      if(price!=0)
	      {  t=travel(category,model,price);
	      }
	      else
	      {
		cout<<"\nSERVICE NOT AVAILABLE!!!\nEnter details again.";
		goto again;
	      }
	      t.getdata();



	      extra.write((char*)&t,sizeof(t));
	      cout<<"\nRegistered successfully.";

	   extra.close();
    }


    if(strcmp(a,"hotel")==0)
    {      extra.open("hotel.dat",ios::binary|ios::out|ios::app);
	      h.getdata();
	      extra.write((char*)&h,sizeof(h));
	      cout<<"\nRegistered successfully.";



	   extra.close();
    }
}


//to search hotel or trip
void search(char a[])
{
    char nam[20],found='n',ch;
    int r;                       //for registration number
    if(strcmp(a,"trip")==0)
    {    trav.open("travel.dat",ios::in|ios::binary);
	cout<<"\tMENU\n\t"
	      "1. Search by name\n\t"
	      "2. Search by ID\n\t"
	      " Enter your choice : ";
	cin>>ch;

	switch(ch)
	{
	   case	'1' :   cout<<"Enter the name you want to search : ";
			gets(nam);
			while(!trav.eof())
			{    trav.read((char*)&t,sizeof(t));
			     if(trav.eof())
			     break;

			     if(strcmp(t.returnname(),nam)==0)
			     {    t.putdata();
				  found='y';
			     }
			}
			if(found=='n')
			{ cout<<"\nRecords with entered name not found!!!\npress any key to go back.";
			  getch();
			}
			break;

	   case '2' :   cout<<"Enter the ID to be searched : ";
			cin>>r;
			while(!trav.eof())
			{    trav.read((char*)&t,sizeof(t));
			     if(trav.eof())
			     break;

			     if(t.returnregist()==r)
			     {    t.putdata();
				  found='y';
			     }
			}
			if(found=='n')
			{ cout<<"\nRecords with entered name not found!!!\npress any key to go back.";
			  getch();
			}
			break;

	   default :    cout<<"\nINVALID CHOICE ENTERED!!!";
	   }
	   trav.close();
	}
    if(strcmp(a,"hotel")==0)
    {    hote.open("hotel.dat",ios::binary|ios::in);
	 cout<<"Enter the name you want to search : ";
	 gets(nam);
	 while(!hote.eof())
	 {    hote.read((char*)&h,sizeof(h));
	      if(hote.eof())
	      break;
	      if(strcmp(h.returnname(),nam)==0)
	      {    h.putdata();
		  found='y';
	      }
	 }
		if(found=='n')
		{ cout<<"\nRecords with entered name not found!!!\npress any key to go back.";
		  getch();
		}

	  hote.close();
    }
}

//to update hotel or trip booking
void update(char a[])
{     char found='n',nam[20],ch;
      int pos,rn;
      if(strcmp(a,"trip")==0)
      {
	trav.open("travel.dat",ios::binary|ios::out|ios::in);
	cout<<"\tMENU\n\t"
	      "1. Update by name\n\t"
	      "2. Update by ID\n\t"
	      " Enter your choice : ";
	cin>>ch;
	switch(ch)
	{    case '1' : cout<<"Enter the name you want to update : ";
			gets(nam);
			while(!trav.eof())
			{    pos=trav.tellg();
			     trav.read((char*)&t,sizeof(t));
			     if(trav.eof())
			     break;
			     if(strcmp(nam,t.returnname())==0)
			     {    found='y';
				  t.modify(nam);
				  trav.seekg(pos);
				  trav.write((char*)&t,sizeof(t));
			     }
			}
			if(found=='n')
			{  cout<<"\nRecords not found!!!";
			}
			break;
	     case '2' : cout<<"Enter the ID you want to modify : ";
			cin>>rn;
			while(!trav.eof())
			{    pos=trav.tellg();
			     trav.read((char*)&t,sizeof(t));
			     if(trav.eof())
			     break;
			     if(rn==t.returnregist())
			     {    found='y';
				  t.modify(rn);
				  trav.seekg(pos);
				  trav.write((char*)&t,sizeof(t));
			     }
			}
			if(found=='n')
			{  cout<<"\nRecords not found!!!";
			}
			break;
	     default : cout<<"\nWrong choice entered!!!";
	}
      trav.close();
      }


}

//to cancel hotel or trip booking
	void cancel(char a[])
{
      ofstream ofs("temp.dat");
      trav.open("travel.dat",ios::binary|ios::in);
      char found='n';
      int id;

      if(strcmp(a,"trip")==0)
      {    cout<<"Enter the ID you want to delete : ";
	   cin>>id;
	   while(!trav.eof())
	   {    trav.read((char *)&t,sizeof(t));
		if(trav.eof())
		break;
		if(id==t.returnregist())
		{   found='y';      //record with given id not send to file temp.dat
		    cout<<"\nRegistration canceled successfully";
		}
		else
		ofs.write((char *)&t,sizeof(t));
	   }
	   if(found=='n')
	   cout<<"\nRecords not found!!!";
	   trav.close();
	   ofs.close();
	   remove("travel.dat");
	   rename("temp.dat","travel.dat");
	   getch();
      }


      if(strcmp(a,"hotel")==0)
      {
	   hote.open("hotel.dat",ios::binary|ios::in);
	   cout<<"Enter the ID you want to delete : ";
	   cin>>id;
	   while(!hote.eof())
	   {    hote.read((char *)&h,sizeof(h));
		if(hote.eof())
		break;
		if(id==h.returnregist())
		{   found='y';      //record with given id not send to file temp.dat
		    cout<<"\nRegistration canceled successfully";
		}
		else
		ofs.write((char *)&h,sizeof(h));
	   }
	   if(found=='n')
	   cout<<"\nRecords not found!!!";
	   hote.close();
	   ofs.close();
	   remove("hotel.dat");
	   rename("temp.dat","hotel.dat");
	   getch();
      }

}

//to display all records
void see( char a[])
{     trav.open("travel.dat",ios::binary|ios::in);
      hote.open("hotel.dat",ios::binary|ios::in);
      if(strcmp(a,"trip")==0)
      {
	      cout<<"-----------------------------------------------------------------------------\n"
		    "  ID  |"
		    "     NAME      |"
		    "  DESTINATION  |"
		    "      MODEL    |"
		    "    PRICE PER KM\n"
		    "------------------------------------------------------------------------------\n\n";

	     while(!trav.eof())
	     {    trav.read((char *)&t,sizeof(t));
		  if(trav.eof())
		  break;
		  t.dispall();
		  cout<<"\n";
	     }
	   //  cout<<"\n------------------------------------------------------------------------------\n\n";
      }
      if(strcmp(a,"hotel")==0)
      {      cout<<"-------------------------------------------------------------------------------\n"
		   "  ID | "
		   "      NAME     |"
		   "      HOTEL NAME    |"
		   "    CITY    |"
		   " ROOMS |"

		   "------------------------------------------------------------------------------\n\n";
		while(!hote.eof())
	     {    hote.read((char *)&h,sizeof(h));
		  if(hote.eof())
		  break;
		  h.dispall();
		  cout<<"\n";
	     }

	     //cout<<"\n------------------------------------------------------------------------------\n\n";
      }
      trav.close();
      hote.close();
}


//************************functions for managing vehicles*****************************************************

//to add vehicles
void addvehicle()
{
    trav.open("vehicles.dat",ios::binary|ios::out);


    char category[3],model[15];
    float price;
    yes='y';          //global variable
	t3.vehiGetdata();
	trav.write((char*)&t3,sizeof(t3));
	cout<<"\nAdded successfully.";
	trav.close();


}

//to search vehicle and display details
void searchvehicle(char category[], char name[])
{
    char model[15],found='n';
    float price;

    trav.open("vehicles.dat",ios::binary|ios::in);
    while(!trav.eof())
    {
       trav.read((char*)&t3,sizeof(t3));
       if(trav.eof())
       break;
       if(strcmp(category,t3.returncategory())==0 && strcmp(name,t3.returnmodel())==0)
       {     found='y';
	     t3.vehiShowdata();
	     getch();
	     break;
       }
    }
	if(found=='n')
	 cout<<"\nNOT FOUND!!!";




	trav.close();
}

float search_vehicle(char category[], char name[])
{
    char model[15],found='n';
    float price;

    trav.open("vehicles.dat",ios::binary|ios::in);
    while(!trav.eof())
    {
       trav.read((char*)&t3,sizeof(t3));
       if(trav.eof())
       break;
       if(strcmp(category,t3.returncategory())==0 && strcmp(name,t3.returnmodel())==0)
       {     found='y';
	     price=t3.return_tempPrice();

	     break;
       }
    }
	if(found=='n')
	 cout<<"\nNOT FOUND!!!";




	trav.close();
	return price;
}

//to show list of all available vehicles
void allvehicle(char category[])
{
    char model[15];
    float price;

    trav.open("vehicles.dat",ios::binary|ios::in);
    while(!trav.eof())
    {
       trav.read((char*)&t3,sizeof(t3));
       if(trav.eof())
       break;

    if(strcmp(category,t3.returnmodel())==0)
    {
	cout<<" Model   Number   Units Price";
	t3.vehiShowall();
	cout<<"\n";
    }


}
}

/*//to check vehicle and return price
float checkvehicle(char category[], char name[])
{
    char model[15],found='n';
    float price=0;

    trav.open("vehicles.dat",ios::binary|ios::in);
    while(!trav.eof())
    {
       trav.read((char*)&t2,sizeof(t2));
       if(trav.eof())
       break;
       if(strcmp(category,t2.returncategory())==0 && strcmp(name,t2.returnmodel())==0)
       {     price=t2.return_tempPrice();
	     break;
       }
       else
       price=0;
    }
    return price;

}
  */
//*********************** functions to check alphabet and digit ********************************************


int check_alphabet( char a[] )
{                    int box=0;
		    for(i=0;a[i]!='\0';i++)
		    {     if(a[i]==' ')
			 continue;
			 if(isalpha(a[i]))
			 box=1;
			 else
			 {   box=0;
			     break;
			 }

		    }
		    return box;
}

int check_digit( char a[] )
{                   int box=0;
		    for(i=0;a[i]!='\0';i++)
		    {
			 if(isdigit(a[i]))
			 box=1;
			 else
			 {   box=0;
			     break;
			 }
		    }

		      return box;
}

//******************************** funtions for welcome ************************************
void disp1()
{   clrscr();
char a[]={"     H A P P Y  J O U R N E Y"};
    cout<<" \n\n\n\n                                                                \n"
	  "                     |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|            \n"
	  "                     |     T R A V E L  A G E N C Y   |            \n"
	  "              |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|       \n"
	  "              |    |    |    |    |    |    |   |          | |     \n"
	  "              |    |    |    |    |    |    |   |  ( )     | |     \n"
	  "              |    |    |    |    |    |    |   |   |\\___| |/      \n"
	  "              |    |____|____|____|____|____|   |   |____ \\|       \n"
	  "              |                                  \\________\\|        \n"
	  "              |                                            |       \n"
	  "              |         H A P P Y  J O U R N E Y           |       \n"
	  " >>>>>>>>>>>>>|                                            |>>>>>>>> \n"
	  "              |____________________________________________|       \n"
	  "                (         )                    (        )          \n"
	  "                 \\       /                      \\      /           \n"
	  " >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n"
	  "                                                                 \n"
	  "                                                                 \n"
	  "                                                                 \n"
	  "                                                                 \n";

	   for(i=0;a[i]!='\0';i++)
   {
	  cout<<a[i];
	  delay(70);
   }

}

void disp2()
{    clrscr();
     cout<<"                                                                 \n"
	   "                                                                  \n"
	   "                             |~~~~~~~~~~|                              \n"
	   "                             | H O T E L|                              \n"
	   "                             |__________|                              \n"
	   "                             |          |~~~~|~~~~~|                   \n"
	   "                |~~~~~|~~~~~~|          |____|_____|                   \n"
	   "                |_____|______|__________|    |     |                   \n"
	   "                |     |      |          |____|_____|~~~~~|~~~~~|       \n"
	   "        |~~~|~~~|_____|______|          |    |     |_____|_____|       \n"
	   "        |   |   |     |      |__________|____|_____|     |     |   \n"
	   "        | __|___|_____|______|          |    |     |_____|_____|   \n"
	   "        |   |   |     |      |          |____|_____|     |     |   \n"
	   "        |   |   | /~~~~~|~~~~~\\         |    |     |     |     |\n"
	   ">>>>>>>>>>>>>>> / |_____|_____| \\ >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> \n"
	   "            __/      ~     ~      \\__                                  \n"
	   "           |_________________________|            \n"
	   "             (   )           (   )                                     \n"
	   ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n\n";

	   char a[]={"      H A P P Y  J O U R N E Y... "};
	   for(i=0;a[i]!='\0';i++)
	   {  cout<<a[i];
	      delay(70);
	   }

}