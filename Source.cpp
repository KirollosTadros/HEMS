#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
 
const char *type[6] = { "Bills" , "Shopping" , "Grocery" , "Fuel" , "Medicine" , "Others"  };

class Expense
{
protected:
	float amount;
	int t;

public:
	Expense()
	{}
	Expense(float amount, int t)
	{
		this->amount = amount;
		this->t = t-1;
	}

	void set_amount(float amount)
	{
		this->amount = amount;
	}

	void set_type(int t)
	{
		this->t = t-1;
	}

	float get_amount()
	{
		return this->amount;
	}

	string get_type()
	{
		return type[this->t];
	}

	string expenseDetails()
	{
		string str(type[this->t]);
		return "You Have Made a transaction of " + to_string(this->amount) + "CAD in " + to_string(this->t);
	}
	
};


class CashTransaction  : public Expense
{
public:

	string theType()
	{
		return "Cash";
	}

	CashTransaction(float amount, int t)
	{
		this->amount = amount;
		this->t = t - 1;
	}
	string expenseDetails()
	{
		string str(type[this->t]);
		return "You Have Made a CASH/Debit transaction of " + to_string(this->amount) + " CAD in " + str;
	}	

};


class CreditCardTransaction : public Expense
{
	string holder_name;
	int exp_month;
	int exp_year;
	string card_number;


public:

	string theType()
	{
		return "Credit";
	}

	CreditCardTransaction(string holder_name, int exp_month, int exp_year, string card_number)
	{
		this->holder_name =  holder_name;
		this->exp_month = exp_month;
		this->exp_year = exp_year;
		this->card_number =  card_number;
	}

	CreditCardTransaction(string holder_name, int exp_month, int exp_year, string card_number, float amount, int t)
	{
		this->holder_name =  holder_name;
		this->exp_month = exp_month;
		this->exp_year = exp_year;
		this->card_number =  card_number;
		this->amount = amount;
		this->t = t - 1;
	}

	CreditCardTransaction(float amount, int t)
	{
		this->amount = amount;
		this->t = t - 1;
	}

	string expenseDetails()
	{
		if(this->exp_month > 9)
		{
			string str (type[this->t]);
			return "You Have Made a Credit Card transaction of " + to_string(this->amount) + " CAD in " + str + "\n\n" + "Credit Card Information:\n\n" + "Card Holder Name: " + this->holder_name + "\n\n" + "Expiration Date: " + to_string(this->exp_month) + "/" + to_string(this->exp_year) + "\n\n" + "Card Number: " + this->card_number ;
		}

		else
		{
			string str (type[this->t]);
			return "You Have Made a Credit Card transaction of " + to_string(this->amount) + " CAD in " + str + "\n\n" + "Credit Card Information:\n\n" + "Card Holder Name: " + this->holder_name + "\n\n" + "Expiration Date: 0" + to_string(this->exp_month) + "/" + to_string(this->exp_year) + "\n\n" + "Card Number: " + this->card_number ;

		}

	}
};


class Account
{
protected:
	long number;
	float balance;
	string owner_name;
	string type;

public:

	Account(){}

	Account(long number, float balance, string owner_name)
	{
		this->number = number;
		this->balance = balance;
		this->owner_name = owner_name;
	}

	void set_number(long number)
	{
		this->number = number;
	}

	void set_balance( float balance)
	{
		this->balance = balance;
	}
	void set_name( string name)
	{
		this->owner_name = name;
	}

	long get_number()
	{
		return this->number;
	}

	float get_balance()
	{
		return this->balance;
	}

	string get_owner_name()
	{
		return this->owner_name;
	}


	void withdrawal(float amount)
	{
		this->balance = this->balance - amount;
	}

	void deposit (float amount)
	{
		this->balance = this->balance + amount;
	}

	void set_type(string type)
	{
		this->type = type;
	}

	string get_type()
	{
		return this->type ;
	}


	string info()
	{
		return "Account Number: " + to_string(this->number) + "\n\nAccount Owner: " + this->owner_name + "\n\nCurrent Balance: " + to_string(this->balance) + "\n\nAccount Type: " +this->type;
	}

	

};


class Saving : public Account
{
public:
	Saving(){}
	Saving(long number, float balance, string owner_name, string type = "Saving")
	{
		this->number = number;
		this->balance = balance;
		this->owner_name = owner_name;
		this->type = type;
	}

	string info()
	{
		return "Account type : Saving  Account Number: " + to_string(this->number) + " Account Owner: " + this->owner_name + " Current Balance: " + to_string(this->balance) + "Type: " + "Saving";

	}

};

class Checking : public Account
{
public:
	Checking(){}

	Checking(long number, float balance, string owner_name , string type = "Checking")
	{
		this->number = number;
		this->balance = balance;
		this->owner_name = owner_name;
		this->type = type;
	}


	string info()
	{
		return "Account type : Checking  Account Number: " + to_string(this->number) + " Account Owner: " + this->owner_name + " Current Balance: " + to_string(this->balance) + "Type: " + "Checking";

	}
};

class Household {

	string name;
	long id;
	Account **arr;
	int last_index;

public:

	Household(){}
	Household( string name, long id, int n)
	{
		this->name = name;
		this->id = id;;
		this->last_index = 0;
		arr = new Account* [n];
	}

	long get_id()
	{
		return this->id;
	}

	string get_name()
	{
		return this->name;
	}


	

	void set_account(Account* acc)
	{
		arr[this->last_index] = acc;
		this->last_index++;
	}



	string get_account()
	{
		int i=0;
		string str = "";
		
		while(i < this->last_index)
		{
			str = str + "\n\n\n" + "Account " + to_string(i+1) + ":\n"  + (*arr[i]).info();
			i++;
		}

		return str;
	}
	
};





int main()
{

	/*
	*******************
	****Test Part A****
	*******************
	*/
	cout<<"*********************PART A TEST*******************"<<endl<<endl;
	cout<<"Welcome to Expense Monitoring System \nSelect the type of expense/transaction you want to make:\n\n1- Cash/Debit Expense\n\n2- Credit Card Expense"<<endl;
	int x;
	cin>>x;
	cout<<"Enter the Expense Amount: ";
	float amount;
	cin>>amount;
	cout<< "Select the Expense Type:\n\n1- Bills\n\n2- Shopping\n\n3- Grocery\n\n4- Fuel\n\n5- Medicine\n\n6- Others"<<endl;
	int the_type;
	cin>>the_type;

	if( x == 1)
	{
		CashTransaction cash(amount, the_type);
		cout<<cash.expenseDetails()<<endl<<endl;
	}

	if( x == 2)
	{
		cout<<"Credit Card Holder: ";
		string  holder;
		getline(cin >> ws, holder);
		cout<<endl;
		cout<<"Credit Card Exp Month: ";
		int month;
		cin>>month;
		cout<<endl;
		cout<<"Credit Card Exp Year: ";
		int year;
		cin>>year;
		cout<<endl;
		cout<<"Credit Card Number: ";
		string Number;
		cin>>Number;
		cout <<endl<<endl;
		CreditCardTransaction card ( holder, month, year, Number, amount,the_type);

		cout<<card.expenseDetails()<<endl<<endl;
	}


	
	cout<<"*********************PART A TEST*******************"<<endl<<endl;
	/*
	*******************
	****Test Part A****
	*******************
	*/

	
	/*
	*******************
	****Test Part B****
	*******************
	*/

	cout<<"*********************PART B TEST*******************"<<endl<<endl;

	cout<<"Enter the Household’s Name: ";
	string name;
	getline(cin >> ws, name);

	cout<<"Enter the Household’s  ID Number: ";
	long id;
	cin>>id;

	cout<<"Enter the number of Accounts of Household: ";
	int n;
	cin>>n;
	
	Household H(name, id, n);

	for(int i = 0 ;i < n ; i++ )
	{
		cout<< "Select Account Type: \n\n1-	Saving Account\n2-	Checking Account"<<endl;
		cin>>x;
		if( x == 1)
		{
			cout<<"Enter Initial Balance: ";
			float balance;
			cin>>balance;

			cout<<"Account Number: ";
			long number;
			cin>>number;
			cout<<endl<<endl;

			Account *Acc;
			Acc = new Saving (number, balance, H.get_name());
			H.set_account(Acc);
		}

		if ( x == 2)
		{
			cout<<"Credit Card Limit: ";
			float balance;
			cin>>balance;

			cout<<"Account Number: ";
			long number;
			cin>>number;
			cout<<endl<<endl;

			Account *Acc;
			Acc = new Checking (number, balance, H.get_name());
			H.set_account(Acc);
		}
	
		cout<<H.get_account()<<endl<<endl;
	}

	cout<<"*********************PART B TEST*******************"<<endl<<endl;
	/*
	*******************
	****Test Part B****
	*******************
	*/


	/*
	*******************
	****Test Part C****
	*******************
	*/

	cout<<"*********************PART C TEST*******************"<<endl<<endl;
	
	Account *arr[3];
	for(int i = 0 ;i < 3 ; i++ )
	{
		cout<< "Select Account Type: \n\n1-	Saving Account\n2-	Checking Account"<<endl;
		cin>>x;
		if( x == 1)
		{
			cout<<"Enter Initial Balance: ";
			float balance;
			cin>>balance;
			cout<<"Account Number: ";
			long number;
			cin>>number;

			cout<<"Account Owner: ";
			string name;
			cin>>name;
			cout<<endl<<endl;
			arr[i] = new Saving (number, balance, name);

		}

		if ( x == 2)
		{
			cout<<"Credit Card Limit: ";
			float balance;
			cin>>balance;
			cout<<"Account Number: ";
			long number;
			cin>>number;

			cout<<"Account Owner: ";
			string name;
			cin>>name;
			cout<<endl<<endl;
			arr[i] = new Checking (number, balance, name);
		}
		
		for(int j = 0 ; j <= i ; j++ )
		{
			cout<<(*arr[j]).info();
		}

	}
	cout<<endl<<endl;

	cout<<"*********************PART C TEST*******************"<<endl<<endl;
	/*
	*******************
	****Test Part C****
	*******************
	*/


	

	/*
	*******************
	**** Part D****
	*******************
	*/

	cout<<"*********************PART D TEST*******************"<<endl<<endl;

	cout<<"Enter Number of Households : ";
	int household_number;
	cin>>household_number;
	Household **House =  new Household*[household_number];

	float **HEMS = new float* [household_number + 1];
	string **optional = new string * [household_number ];

	for(int i = 0; i < household_number+1; ++i)
	{
		HEMS[i] = new float[6];
		if( i != household_number)
			optional[i] = new string[6];
	}

		for (int row = 0 ; row < household_number + 1 ; row++)
		{
			for (int col = 0 ; col < 6 ; col++)
			{
				HEMS[row][col] = 0;
				if(row != household_number)
					optional [row] [col] = "NA";
			}

			cout<<endl;
		}
	
	for (int k = 0 ; k < household_number ; k++)
	{
		cout<<"Enter the Household’s Name: ";
		string name;
		getline(cin >> ws, name);

		cout<<"Enter the Household’s  ID Number: ";
		long id;
		cin>>id;

		cout<<"Enter the number of Accounts of Household: ";
		int num;
		cin>>num;
	
		House[k] =  new Household(name, id, num);

		for(int itr = 0 ;itr < num ; itr++ )
		{
			cout<< "Select Account Type: \n\n1-	Saving Account\n2-	Checking Account"<<endl;
			int x;
			cin>>x;
			if( x == 1)
			{
				cout<<"Enter Initial Balance: ";
				float balance;
				cin>>balance;

				cout<<"Account Number: ";
				long number;
				cin>>number;
				cout<<endl<<endl;

				Account *Acc;
				Acc = new Saving (number, balance, (*House[k]).get_name());
				(*House[k]).set_account(Acc);
			}

			if ( x == 2)
			{
				cout<<"Credit Card Limit: ";
				float balance;
				cin>>balance;

				cout<<"Account Number: ";
				long number;
				cin>>number;
				cout<<endl<<endl;

				Account *Acc;
				Acc = new Checking (number, balance, (*House[k]).get_name());
				(*House[k]).set_account(Acc);
			}
	
			cout<<(*House[k]).get_account()<<endl<<endl;
		}
	}

	for (int k = 0 ; k < household_number ; k++)
	{
		cout<<endl<<endl<<"*************************************"<<endl<<endl<<endl;
		
		cout<< "Enter Expanses of " + (*House[k]).get_name()<<endl<<endl;
		while(1)
		{
			cout<<"Select the type of expense/transaction you want to make:\n\n1- Cash/Debit Expense\n\n2- Credit Card Expense\n0- To Exit this Household"<<endl;
			int x;
			cin>>x;

			if ( x == 0)
			{
				break;
			}

			cout<<"Enter the Expense Amount: ";
			float amount;
			cin>>amount;
			cout<< "Select the Expense Type:\n\n1- Bills\n\n2- Shopping\n\n3- Grocery\n\n4- Fuel\n\n5- Medicine\n\n6- Others  \n\n 0- To exit this house hold"<<endl;
			int the_type;
			cin>>the_type;
			 
			if(the_type == 0)
				break;

			if( x == 1)
			{
				CashTransaction cash(amount, the_type);
				cout<<cash.expenseDetails()<<endl<<endl;
				HEMS[k][the_type - 1] =  cash.get_amount();
				optional [k][the_type - 1] = "Cash";
			}

			if( x == 2)
			{
				cout<<"Credit Card Holder: ";
				string  holder;
				getline(cin >> ws, holder);
				cout<<endl;
				cout<<"Credit Card Exp Month: ";
				int month;
				cin>>month;
				cout<<endl;
				cout<<"Credit Card Exp Year: ";
				int year;
				cin>>year;
				cout<<endl;
				cout<<"Credit Card Number: ";
				string Number;
				cin>>Number;
				cout <<endl<<endl;
				CreditCardTransaction card ( holder, month, year, Number, amount,the_type);
				cout<<card.expenseDetails()<<endl<<endl;
				HEMS[k][the_type - 1] =  card.get_amount();
				optional [k][the_type - 1] = "Credit";
		}
	
		}
	}



	cout<<"Bills"<<setw(7)<<setfill(' ')<<"Shopping"<<setw(7)<<setfill(' ') << "Grocery" <<setw(7)<<setfill(' ') << "Fuel" << setw(7)<<setfill(' ')  << "Medicine"  <<setw(7)<<setfill(' ') << "Others"<<endl<<endl;
	

		for (int row = 0 ; row < household_number + 1 ; row++)
		{
			cout<<(*House[row]).get_name()<<setw(7)<<setfill(' ');
			for (int col = 0 ; col < 6 ; col++)
			{
				if(row != household_number)
					cout<<to_string(HEMS[row][col])+ "(" + optional[row][col] + ")"<<setw(7)<<setfill(' ');
				else
					cout<<to_string(HEMS[row][col])<<setw(7)<<setfill(' ');
			}

			cout<<endl;
		}
}
