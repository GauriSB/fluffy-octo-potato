//a program to develop ATM management system
/*
mini project A.T.M
ADMIN:1>add user
2:delete user
3:view all users
USER:1>.check balance
2>.cash withdraw
3>.user details
4>.update mobile_no
*/
#include<iostream>
#include<conio.h>

int admin_pin=1111;

using namespace std;
class user
{
   private:

	    char user_name[20];
	    char l_name[10];
	    long mobile_no;
	    double balance;

  public:
       int pin;
       int account_no;
    void setdata()
    {
	cout << "\n\n*******Enter user Data*******\n";
	cout << "Account No.: "; cin >> account_no;
	cout << "First Name: "; cin>>user_name;
	cout << "Last Name: "; cin>>l_name;
	cout << "Mobile no: "; cin >> mobile_no;
	cout << "balance: "; cin>>balance;
	cout << "PIN: "; cin >>pin;
	cout << endl;
   }

	   void check_balance()
	   {
	     int u_pin;
	      cout<<"enter your pin:";
	      cin>>u_pin;
	      if(pin == u_pin)
	      {
		 cout<<"Balance:"<<balance<<endl;
	      }
	     else
	      {
		 cout<<"incorrect pin !!! \n try again....";
	      }
	   }
	   void withdraw()
	   {
	      float withdraw;
	       cout<<"enter the amount to be withdrawn:";
	       cin>>withdraw;
	      if(balance >=500 && withdraw < balance)     //here atleast 500 rs
	      {                                         //should be there in account
		   balance= balance - withdraw;
		   cout<<"the amount "<<withdraw<<"is withdrawn"<<endl;
		   cout<<"Please collect at the counter..";
	      }
	}
	   void user_details()
	   {

	   cout<<"\tThe User Details are:"<<endl;
	   cout<<"Full name:"<<user_name<<"  "<<l_name<<endl;
	   cout<<"account no:"<<account_no<<endl;
	   cout<<"linked mobile no:"<<mobile_no<<endl;

	   }

	   void update_mobile()
	   {
	    long chk_mob;
	    long new_mob;
	    cout<<"enter the current mobile no.:";
	    cin>>chk_mob;

	    if(mobile_no==chk_mob)
	    {
	       cout<<"\nenter new mobile no.:";
	       cin>>new_mob;
	       mobile_no=new_mob;
	       cout<<"\nmobile no. updated successfully....";
	    }
	    else
	    {
	    cout<<" entered mobile no. not matched!!!";
	    }
	   }
};

///////////////////////////////////

int main()
{
  int choice,i,flag=0,u_no,n,c,cho;
  int e_a_pin;
  user u[50];
  int u_count=0;
  clrscr();
  choice=0;
   while(choice!=3)
 {
  cout<<"\n\t***WELCOME TO ATM***";
  cout<<"\n\t======MENU======";
  cout<<"\n1.login as admin";
  cout<<"\n2.login as user";
  cout<<"\n3.exit";
  cout<<"\nenter your choice";
  cin>>choice;

  switch(choice)
  {
    case 1:
      {
       clrscr();
	 cout<<"\nLoging as admin...\nenter your pin";
	 cin>>e_a_pin;
	 if(e_a_pin==admin_pin)
	  {
	  c=0;
	  while(c!=4)
	       {

		  cout<<"\n\t***MENU***";
		  cout<<"\n1.add new user";
		  cout<<"\n2.view all users";
		  cout<<"\n3.delete an user";
		  cout<<"\n4.logout";
		   cin>>c;

		  switch(c)
		  {
		    case 1:
			    {           //creating an object of array of obj u[10]
			       u[u_count].setdata();//u_count monitors the index of obj
			       u_count++;
			       break;
			    }
		    case 2:
		    {                            //prints all  the uer details
		     for(int i=0;i<u_count;i++)
			 {
			 u[i].user_details();
			 }
			 break;
		    }
		    case 3:
		    {   //delete entire object
		      int d_a_no;  //var to take account no
		      cout<<"Enter the account no:";
		      cin>>d_a_no;
		     for(int i=0;i<u_count;i++)      //how to delete an object
		      {                                  //from an array of objects
		       if(u[i].account_no==d_a_no)
		      {
			    while(i!=u_count)
			    {
			     u[i]=u[i+1];
			     i++;
			    }
			    u_count--;
			cout<<"user deleted.... ";
		       }
		      }
		       break;
		    }
		//    case 4:
		  //	break;

		 }
	       }
	      }
	       else
	       cout<<"\nOOPS!!! you have entered an incorrect pin...";
	       break;
      }
    case 2:
      {             clrscr();
      cout<<"\n\t Logging as a user...";
      int user_acc,user_pin;
	  cout<<"\nEnter account_no";
	  cin>>user_acc;
	  cout<<"\nEnter your pin...";
	  cin>>user_pin;

	  for(i=0;i<u_count;i++)
	  {
	    if(user_acc==u[i].account_no  &&  user_pin==u[i].pin)
	    {flag=1;
	     u_no=i; }//u_no is here to access the objects
	  }
	if(flag==0)
	cout<<"Entered incorrect account_no or pin..";

	  if(flag==1)
	  {
	   cho=0;
	  while(cho!=5)
	   {
		  // clrscr();
	    cout<<"\n\t***MENU*** ";
	    cout<<"\n1>.check balance";
	    cout<<"\n2>.cash withdraw";
	    cout<<"\n3>.user details";
	    cout<<"\n4>.update mobile_no";
	    cout<<"\n5>.back to last menu";
	    cout<<"\nEnter your choice....";
	    cin>>cho;
      //------------------------------------------

	switch(cho)
	{
	    case 1:
	    {
	      cout<<"\nChecking balance...";
	      u[u_no].check_balance();
	      break;
	    }
	    case 2:
	    {
	      cout<<"\nwithdraw balance...";
	      u[u_no].withdraw();
	      break;
	    }
	    case 3:
	    {
	      u[u_no].user_details();
	      break;
	    }
	    case 4:
	    {
	      u[u_no].update_mobile();
	      break;
	   //   case 5:
	     // break;
	    }
	 }   //end of user switch
    //--------------------------------------
       }//end of cho!=5
      }    //end of if flag=1

    } //end of case 2

  }//end of main switch
 } //end of while choice!=0;

getch();
return 0;

}
