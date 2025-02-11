#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
class medicine{
protected:
      string MedName[20];//={"Antibiotics","Vitamin C","Acid Free C","Panadol","Paracitamol","Maxi Cal Tablet","Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
      int NoMed[20];//={3,33,4,6,55,98,101,299,300,0};
      float price[20];//={9.99,5.00,15.50,17.99,4.00,10.00,20.00,6.00,7.99,8.99,7.00};


public:
     medicine()
     {
     }
string* get_MedNeme(){

           static string MedName[20]={"Antibiotics","Vitamin C","Acid Free C","Panadol","Paracitamol","Maxi Cal Tablet","Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
         return MedName;}
string*p=get_MedNeme();
      int* get_NoMed(){
            static int NoMed[20]={3,33,4,6,55,98,101,299,300,0};
            return NoMed;
                   }
      int*n=get_NoMed();
float* get_price(){
          static float price[20]={9.99,5.00,15.50,17.99,4.00,10.00,20.00,6.00,7.99,8.99,7.00};
          return price;}
     float*pr= get_price();
    void store ();//to display info in the pharmacy store

};
class intro{
protected:

    string Namew,Nameu,sex,trans_d;
    int age;
    int raw;
    float receipt;
    string emp_id;
    string passcode;
public:

medicine med;
void delete_order(intro &d); //to delete the order
void modify(intro &d); //to modify the order
void user_order(intro &d); //to process the order of user
}d;
class section: public intro{
public:
    intro user;
    intro worker;
    void take_section();//to  take preference either a employee or user
    void user_section();
    void employee_section();
	void feedback();//the feedback that the user send
	void exit();  //function to exit system
	void summary();
	void client_s();
	float get_reeipt(){return receipt;}
	string get_Nameu(){return Nameu;}
	int get_age(){return age;}
	string get_sex(){return sex;}
	string get_trans_d(){return trans_d;}
    section(string nw, string empi, string pass)
{
    Namew=nw;
    emp_id=empi;
    passcode=pass;
}
section(string nu, int ag, string se, string td, float r)
{
    Nameu=nu;
    age=ag;
    sex=se;
    trans_d=td;
    receipt=r;
}
section(){}
};


int main()
{
    section s;
    s.take_section();
    return 0;
}
void section::take_section()
{   string nw,empi,pass;
    section u;
        int n;

        do{system ("cls");
        cout<<"\t\t    Welcome To Pharmacy Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1.Employee section \t\t||\n";
		cout<<"\t\t||\t2.User section\t\t        ||\n";
		cout<<"\t\t||\t3.exit\t\t                ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";
		cin>>n;
		system("cls");
		if(n==1)
            {
              cout<<"Enter your name: ";
              cin.ignore();
              getline(cin,nw);

              cout<<"Enter your Id: ";
              cin>>empi;
              cout<<"Enter your pass code: ";
              cin>>pass;
              if(pass!="1111"){
              do
              {
                cout<<"Sorry!! Incorrect pass code please enter again"<<endl;
                cin>>pass;
              }while(pass!="1111");
              }
              system("cls");
              section u(nw,empi,pass);
              u.employee_section();
            }
        else if (n==2)
        {
             u.user_section();
        }
        }while(n!=3);
        u.exit();
}
void section::employee_section()
{section s;
intro d;
    int en;
do{
        system("cls");
        cout<<"\t\t\tWelcome Employee section what you want to do"<<endl;
		cout<<"\t\t||\t1. Delete Medicine order List\t\t ||\n";
		cout<<"\t\t||\t2. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t3. Information of Medicine in Store \t ||\n";
		cout<<"\t\t||\t4. Summary Of Order List \t ||\n";
		cout<<"\t\t||\t5. Client Suggestion \t ||\n";
		cout<<"\t\t||\t6. Back\t\t\t\t\t ||\n";
		cin>>en;
		switch (en)
		{

		case 1:
			{

				s.delete_order(d);	//function delete

				break;
			}

		case 2:
			{
				s.modify(d);
				system("PAUSE");
				break;
			}

		case 3:
			{
				s.med.store();
				system("PAUSE");
				break;
			}

        case 4:
			{
			    s.summary();
				break;
			}
        case 5:
			{
			    s.client_s();
				break;
			}
        case 6:
			{
				break;
			}

		default:
			{
				cout<<"You enter invalid input\n re-enter the input\n"<<endl;
				break;
			}
			;
}

}while(en!=4);//end do

}

void intro::delete_order(intro &d)
{section u;
intro *temp;
temp=&d;

int i;
cout << "===============================================================" << endl;
cout << "Medicine Name    |  	Quantity       |         Price |" << endl;
 for(int i=0; i<10; i++)
 {
     cout<<i+1<<". "<<temp->med.p[i]<<"\t\t"<<temp->med.n[i]<<"\t\t\t"<<temp->med.pr[i]<<" Birr"<<endl;
 }
cout<<endl<<"Enter raw number to delete: ";
cin>>i;
d.med.p[i-1]="______";
d.med.n[i-1]=0;
d.med.pr[i-1]=0;
system("cls");
cout<<"deleting was successful here is the result: "<<endl;
cout<<endl;
cout << "===============================================================" << endl;
cout << "Medicine Name    |  	Quantity     |      Price |" << endl;
for(int i=0; i<10; i++)
 {
     cout<<i+1<<". "<<d.med.p[i]<<"\t\t"<<d.med.n[i]<<"\t\t\t"<<d.med.pr[i]<<" Birr"<<endl;
 }
 system ("PAUSE");
}
void intro:: modify(intro &d)
{
intro *temp;
temp=&d;
int i,q;
float p;
string s;
cout << "===============================================================" << endl;
cout << "Medicine Name    |  	Quantity       |          Price |" << endl;
 for(int i=0; i<10; i++)
 {
     cout<<i+1<<". "<<temp->med.p[i]<<"\t\t"<<temp->med.n[i]<<"\t\t\t"<<temp->med.pr[i]<<" Birr"<<endl;
 }
cout<<"Enter raw number to modify: ";
cin>>i;
cin.ignore();
cout<<"Enter The medicine name: ";
getline(cin,s);
cout<<"Enter The medicine quantity: ";
cin>>q;
cout<<"Enter The medicine price: ";
cin>>p;
d.med.p[i-1]=s;
d.med.n[i-1]=q;
d.med.pr[i-1]=p;
cout<<endl;
cout << "===============================================================" << endl;
cout << "Medicine Name    |  	    Quantity     |              Price |" << endl;
for(int i=0; i<10; i++)
 {
     cout<<i+1<<". "<<d.med.p[i]<<"\t\t"<<d.med.n[i]<<"\t\t\t\t"<<d.med.pr[i]<<" Birr"<<endl;
 }
}
void medicine:: store()
{intro *temp,d;
temp=&d;
cout<<"current information in the pharmacy store"<<endl;
    cout << "===============================================================" << endl;
cout << "Medicine Name    |  	Quantity     |        Price |" << endl;
for(int i=0; i<10; i++)
 {
     cout<<i+1<<". "<<temp->med.p[i]<<setw(18)<<temp->med.n[i]<<setw(25)<<temp->med.pr[i]<<" Birr"<<endl;
 }

}
void section::user_section()
{section s;
intro d;
    int n;
   do
   { system("cls");
       cout<<"\t\t\t  Hello USER Welcome To Pharmacy Management System \n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. client Feedback Hub \t ||\n";
		cout<<"\t\t||\t3. Back\t\t\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cin>>n;
		switch (n)
		{

		case 1:
			{
				s.user_order(d);
				break;
			}

		case 2:
			{
				s.feedback();
				system("PAUSE");
				break;
			}


        case 3:
			{

				break;

			}

		default:
			{
				cout<<"You enter invalid input\n re-enter the input\n"<<endl;
				break;
			}


}
   }while(n!=3);//end do
}
void intro::user_order(intro &d)
{int b,ag;
section s;
float n,n1,m,r;
string da,nu,se,td;
system("cls");
s.med.store();
cout<<endl;
cout<<endl;
cout<<endl;
       cout<<"Enter a your name: ";
       cin.ignore();
       getline(cin,nu);
       cout<<"Enter your age: ";
       cin>>ag;
       cout<<"enter your gender: ";
       cin>>se;
       cout<<"enter date: ";
       cin>>td;
       cout<<"enter your raw selection to buy: ";
       cin>>b;


       cout << "How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >>r;
	section u(nu,ag,se,td,r);
	if(d.med.n[b-1]==0 || d.med.n[b-1]<u.get_reeipt())
       {
           cout<<"sorry "<<u.get_Nameu()<< "there is no enough "<<d.med.p[b-1]<<" in the store please try later"<<endl;
           system("PAUSE");
       }
       else{
	if (u.get_reeipt() >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("PAUSE");
	}
	else{

        cout<<"================================================="<<endl;
        cout<<"| you ordered "<<u.get_reeipt()<<" "<<d.med.p[b-1]<<" |"<<endl;
        cout << "The amount You need to pay is: " <<(d.med.pr[b-1])*u.get_reeipt()<<" Birr"<<endl;
         cout<<"==========================================================================="<<endl;
         cout << "Please the enter the exact amount of money to pay: "<<endl;
n=d.med.pr[b-1];
n1=u.get_reeipt();
         do
         {
             cin>>m;
             cout<<"The money you enter is not equal to the medicine price. please insert the exact money; "<<endl;
         }while(m!=(n*n1));
         d.med.n[b-1]=d.med.n[b-1]-u.get_reeipt();
         system("cls");

    cout << "\t\t\tOrder Taken Successfully"<<endl;
    cout<<"\t\tHere Is Your Receipt"<<endl;
    cout<<"==========================================================================="<<endl;
    cout<<"\t\tName: "<<u.get_Nameu() <<endl;
    cout<<"\t\tAge: "<<u.get_age()<<endl;
    cout<<"\t\tGender: "<<u.get_sex() <<endl;
    cout<<"\t\tPurchase Date: "<<u.get_trans_d() <<endl;
    cout<<"\t\tOrdered: "<<u.get_reeipt()<<" "<<d.med.p[b-1]<<endl;
    cout<<"\t\tAmount of money: "<<n*n1<<" birr"<<endl;
    cout<<"\t\tPurchase status: Successful"<<endl;
    cout<<"\t\tThank you"<<endl;
    cout<<"==========================================================================="<<endl;
	system ("PAUSE");
fstream myFile;
    myFile.open("summary.txt",ios::app);
    if(myFile.is_open())
    {
    myFile<<"\t\tHere Is summary of order lists"<<endl;
    myFile<<"==========================================================================="<<endl;
    myFile<<"\t\tName: "<<u.get_Nameu()<<endl;
    myFile<<"\t\tAge: "<<u.get_age()<<endl;
    myFile<<"\t\tGender: "<<u.get_sex() <<endl;
    myFile<<"\t\tPurchase Date: "<<u.get_trans_d()<<endl;
    myFile<<"\t\tOrdered: "<<u.get_reeipt()<<" "<<d.med.p[b-1]<<endl;
    myFile<<"\t\tAmount of money: "<<n*n1<<" birr"<<endl;
    myFile<<"\t\tPurchase status: Successful"<<endl;
    myFile<<"==========================================================================="<<endl;
        myFile.close();
    }

    }
 }

}

void section::feedback()		//Function to display receipt
{intro d;
string s,nu,td,se;
int ag;
float r;
system("cls");
	cout<<"\t\t\t\tHello User Welcome To Feedback Hub"<<endl;
	cout<<"Enter a your name: ";
       cin.ignore();
       getline(cin,nu);
       cout<<"Enter your age: ";
       cin>>ag;
       cout<<"enter your gender: ";
       cin>>se;
       cout<<"enter date: ";
       cin>>td;
       cout<<endl;
       section u(nu,ag,se,td,r);
       cout<<"Please Enter your suggestion"<<endl;
       cout<<"==========================================================================="<<endl;
       cin.ignore();
       getline(cin,s);
       cout<<"==========================================================================="<<endl;
       cout<<"Thank you "<<u.get_Nameu()<<" For your suggestion"<<endl;
      fstream myFile;
    myFile.open("feedback.txt",ios::app);
    if(myFile.is_open())
    {
    myFile<<"==========================================================================="<<endl;
    myFile<<"Name: "<<nu<<endl;
    myFile<<"Age: "<<ag<<endl;
    myFile<<"Date: "<<td<<endl;
    myFile<<"suggestion ===> "<<endl;
    myFile<<s;
    myFile<<"==========================================================================="<<endl;
        myFile.close();
}

}

void section::exit() //Function to exit
{
	cout<<"\nYou choose to exit.\n"<<endl;
	cout<<"\n Thank You \n"<<endl;
}
void section:: summary()
{
   system("cls");
 fstream myFile;
    myFile.open("summary.txt",ios::in);
    if(myFile.is_open())
    {  string l;
    while(getline(myFile,l))
    {
        cout<<l<<endl;
    }

        myFile.close();
    }
    system("pause");
}
void section:: client_s()
{
   system("cls");
 fstream myFile;
    myFile.open("feedback.txt",ios::in);
    if(myFile.is_open())
    {  string l;
    while(getline(myFile,l))
    {
        cout<<l<<endl;
    }

        myFile.close();
    }
    system("pause");
}
