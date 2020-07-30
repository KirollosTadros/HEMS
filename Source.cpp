#include <iostream>
#include <string>
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
			return "You Have Made a Credit Card transaction of " + to_string(this->amount) + " CAD in " + str + "\n\n" + "Credit Card Information:\n\n" + "Card Holder Name: " + this->holder_name + "\n\n" + "Expiration Date: " + to_string(this->exp_month) + "/" + to_string(this->exp_year) + "\n\n" + "Car Number: " + this->card_number ;
		}

		else
		{
			string str (type[this->t]);
			return "You Have Made a Credit Card transaction of " + to_string(this->amount) + " CAD in " + str + "\n\n" + "Credit Card Information:\n\n" + "Card Holder Name: " + this->holder_name + "\n\n" + "Expiration Date: 0" + to_string(this->exp_month) + "/" + to_string(this->exp_year) + "\n\n" + "Car Number: " + this->card_number ;

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
	cout<<"Welcome to Expense Monitoring System <\nSelect the type of expense/transaction you want to make:\n\n1- Cash/Debit Expense\n\n2- Credit Card Expense"<<endl;
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
	
}
