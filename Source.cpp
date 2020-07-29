#include <iostream>
#include <string>
using namespace std;
 
class Expense
{
protected:
	float amount;
	string type;

public:
	Expense()
	{}
	Expense(float amount, string type)
	{
		this->amount = amount;
		this->type = type;
	}

	void set_amount(float amount)
	{
		this->amount = amount;
	}

	void set_type(float type)
	{
		this->type = type;
	}

	float get_amount()
	{
		return this->amount;
	}

	string get_type()
	{
		return this->type;
	}

	string expenseDetails()
	{
		return "A " + this->type + " of Amount " + to_string(this->amount);
	}
	
};


class CashTransaction  : public Expense
{
public:

	string theType()
	{
		return "Cash";
	}

	CashTransaction(float amount, string type)
	{
		this->amount = amount;
		this->type = type;
	}
	string expenseDetails()
	{
		return "A " + this->type + " of cash Amount " + to_string(this->amount);
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

	CreditCardTransaction(string holder_name, int exp_month, int exp_year, string card_number, float amount, string type)
	{
		this->holder_name =  holder_name;
		this->exp_month = exp_month;
		this->exp_year = exp_year;
		this->card_number =  card_number;
		this->amount = amount;
		this->type = type;
	}

	CreditCardTransaction(float amount, string type)
	{
		this->amount = amount;
		this->type = type;
	}

	string expenseDetails()
	{
		if(this->exp_month > 9)
		{
			return "A " + this->type + " of Amount " + to_string(this->amount) + "\nWith card number: " + this->card_number + " Holder Name: " + this->holder_name + " Expire Date: " + to_string(this->exp_month) + "/" + to_string(this->exp_year);
		}

		else
		{
			return "A " + this->type + " of Amount " + to_string(this->amount) + "\nWith card number: " + this->card_number + " Holder Name: " + this->holder_name + " Expire Date: " + "0" + to_string(this->exp_month) + "/" + to_string(this->exp_year);

		}

	}
};


class Account
{
protected:
	long number;
	float balance;
	string owner_name;

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

	string info()
	{
		return "Account Number: " + to_string(this->number) + " Account Owner: " + this->owner_name + " Current Balance: " + to_string(this->balance);
	}

	

};


class Saving : public Account
{
public:
	Saving(){}
	Saving(long number, float balance, string owner_name)
	{
		this->number = number;
		this->balance = balance;
		this->owner_name = owner_name;
	}

	string info()
	{
		return "Account type : Saving  Account Number: " + to_string(this->number) + " Account Owner: " + this->owner_name + " Current Balance: " + to_string(this->balance);

	}

	

		Saving& operator = (const Account& acc)
		{
			(Saving&)(*this) = acc;
			return *this;
		}
};


class Checking : public Account
{
public:
	Checking(){}

	Checking(long number, float balance, string owner_name)
	{
		this->number = number;
		this->balance = balance;
		this->owner_name = owner_name;
	}

	Checking& operator = (const Account& acc)
	{
		(Checking&)(*this) = acc;
		return *this;
	}

	string info()
	{
		return "Account type : Checking  Account Number: " + to_string(this->number) + " Account Owner: " + this->owner_name + " Current Balance: " + to_string(this->balance);

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
			str = str + "\n" + (*arr[i]).info();
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
	CashTransaction cash1(325, "Bills"), cash2(422.5, "Fuel"), cash3(181.75, "Grocery");
	CreditCardTransaction card1 ("Thomas Shelby", 7, 22, "8226485689", 385.5 , "Medicines"), card2 ("Arthur Shelby", 9, 22, "8226542189", 1220 , "Shopping");
	cout<<cash1.expenseDetails()<<endl<<endl;
	cout<<cash2.expenseDetails()<<endl<<endl;
	cout<<cash3.expenseDetails()<<endl<<endl;
	cout<<card1.expenseDetails()<<endl<<endl;
	cout<<card2.expenseDetails()<<endl<<endl;
	cout<<"*********************PART A TEST*******************"<<endl<<endl;
	/*
	*******************
	****Test Part A****
	*******************
	*/

	cout<<endl<<endl<<endl;

	/*
	*******************
	****Test Part B****
	*******************
	*/

	cout<<"*********************PART B TEST*******************"<<endl<<endl;
	Household H("Shelby", 86234569, 8);

	cout<<"Household id: "<<H.get_id()<<"  Household Name: "<<H.get_name()<<endl;
	Saving *s = new Saving(569950019, 2880, "Thomas Shleby");
	Checking *c = new Checking(568420019, 3650.23, "Arthur Shleby");
	H.set_account(s);
	H.set_account(c);
	cout<<"Family Members Account: "<<H.get_account()<<endl;
	(*s).withdrawal(405);
	(*c).deposit(220.8);

	cout<<"Family Members Account after transactions: "<<H.get_account()<<endl;
	cout<<"*********************PART B TEST*******************"<<endl<<endl;

	/*
	*******************
	****Test Part B****
	*******************
	*/
	
	cout<<endl<<endl<<endl;

	/*
	*******************
	****Test Part C****
	*******************
	*/

	cout<<"*********************PART C TEST*******************"<<endl<<endl;
	Account acc(135001250028,  8852.2, "John Shelby");
	cout<<acc.info()<<endl;
	acc.withdrawal(440);
	cout<<"Account after withdrawal 440:"<<endl;
	cout<<acc.info()<<endl;
	acc.deposit(120.5);
	cout<<"Account after deposit 120.5: "<<endl;
	cout<<acc.info()<<endl;
	cout<<"*********************PART C TEST*******************"<<endl<<endl;


	/*
	*******************
	****Test Part C****
	*******************
	*/


	/*
	*******************
	****Test Part D****
	*******************
	*/

	Household H1("Family1", 159545, 2);
	Household H2("Family2", 26548, 1);
	Household H3("Family3", 951485, 2);
	Household H4("Family4", 8421569, 1);


	Saving *acc1 = new Saving ( 5635346, 15540.25, "account1");
	Checking *acc2 = new Checking ( 5626696, 15040.25, "account2");
	Saving *acc3 = new Saving ( 5626346, 12440.25, "account3");
	Saving *acc4 = new Saving ( 5626846, 155040.25, "account4");
	Checking *acc5 = new Checking ( 5626346, 11140.25, "account5");
	Saving *acc6 = new Saving ( 5654646, 1145640.25, "account6");




	CreditCardTransaction trans1 (240, "Bills");
	CashTransaction trans2 (112.5, "Shopping");
	CreditCardTransaction trans3 (585, "Fuel");

	CreditCardTransaction trans4 (255, "Bills");
	CreditCardTransaction trans5 (417.5, "Shopping");
	CashTransaction trans6 (85, "Grocery");

	CreditCardTransaction trans7 (410, "Bills");
	CreditCardTransaction trans8 (841.8, "Shopping");

	CashTransaction trans9 (805, "Bills");
	CreditCardTransaction trans10 (1024.5, "Shopping");

	H1.set_account(acc1);
	H1.set_account(acc2);

	H2.set_account(acc3);

	H3.set_account(acc4);
	H3.set_account(acc5);

	H4.set_account(acc6);

	cout<<"Household: "<<H1.get_name()<<" Accounts Before Transactions: "<<H1.get_account()<<endl<<endl;
	cout<<"Household: "<<H2.get_name()<<" Accounts Before Transactions: "<<H2.get_account()<<endl<<endl;
	cout<<"Household: "<<H3.get_name()<<" Accounts Before Transactions: "<<H3.get_account()<<endl<<endl;
	cout<<"Household: "<<H4.get_name()<<" Accounts Before Transactions: "<<H4.get_account()<<endl<<endl;

	(*acc1).withdrawal(trans1.get_amount());
	(*acc1).withdrawal(trans2.get_amount());
	(*acc2).withdrawal(trans3.get_amount());

	(*acc3).withdrawal(trans4.get_amount());
	(*acc3).withdrawal(trans5.get_amount());
	(*acc3).withdrawal(trans6.get_amount());

	(*acc4).withdrawal(trans7.get_amount());
	(*acc5).withdrawal(trans8.get_amount());

	(*acc6).withdrawal(trans9.get_amount());
	(*acc6).withdrawal(trans10.get_amount());


	cout<<"Household: "<<H1.get_name()<<" Accounts After Transactions: "<<H1.get_account()<<endl<<endl;
	cout<<"Household: "<<H2.get_name()<<" Accounts After Transactions: "<<H2.get_account()<<endl<<endl;
	cout<<"Household: "<<H3.get_name()<<" Accounts After Transactions: "<<H3.get_account()<<endl<<endl;
	cout<<"Household: "<<H4.get_name()<<" Accounts After Transactions: "<<H4.get_account()<<endl<<endl;

	float HEMS [5][4];

	string HEMS_type [4][4];

	HEMS[0][0] = trans1.get_amount();
	HEMS[0][1] = trans2.get_amount();
	HEMS[0][2] = 0;
	HEMS[0][3] = trans3.get_amount();

	HEMS[1][0] = trans4.get_amount();
	HEMS[1][1] = trans5.get_amount();
	HEMS[1][2] = trans6.get_amount();
	HEMS[1][3] = 0;

	HEMS[2][0] = trans7.get_amount();
	HEMS[2][1] = trans8.get_amount();
	HEMS[2][2] = 0;
	HEMS[2][3] = 0;

	HEMS[3][0] = trans9.get_amount();
	HEMS[3][1] = trans10.get_amount();
	HEMS[3][2] = 0;
	HEMS[3][3] = 0;

	
	
	HEMS_type[0][0] = trans1.theType();
	HEMS_type[0][1] = trans2.theType();
	HEMS_type[0][2] = "NA";
	HEMS_type[0][3] = trans3.theType();

	HEMS_type[1][0] = trans4.theType();
	HEMS_type[1][1] = trans5.theType();
	HEMS_type[1][2] = trans6.theType();
	HEMS_type[1][3] ="NA";

	HEMS_type[2][0] = trans7.theType();
	HEMS_type[2][1] = trans8.theType();
	HEMS_type[2][2] = "NA";
	HEMS_type[2][3] = "NA";

	HEMS_type[3][0] = trans9.theType();
	HEMS_type[3][1] = trans10.theType();
	HEMS_type[3][2] = "NA";
	HEMS_type[3][3] = "NA";



	for(int i = 0 ; i < 4 ; i++)
	{
		HEMS[4][i] = 0;
		for(int j = 0 ; j < 4 ; j++)
			HEMS[4][i] += HEMS[j][i];
	}


	for(int i = 0 ; i < 5 ; i++)
	{
		if(i == 0)
		cout<<"Bills\t\tShopping\tGrocery\t\tFuel"<<endl<<endl;
		for(int j = 0 ; j < 4 ; j++)
			cout<<HEMS[i][j]<<"\t\t";

		cout<<endl<<endl;
	}

	cout<<endl<<endl<<endl;


		for(int i = 0 ; i < 4 ; i++)
	{
		if(i == 0)
		cout<<"Bills\t\t\tShopping\t\tGrocery\t\tFuel"<<endl<<endl;
		for(int j = 0 ; j < 4 ; j++)
			cout<<HEMS[i][j]<<"("<<HEMS_type[i][j]<<")"<<"\t\t";

		cout<<endl<<endl;
	}




	/*
	*******************
	****Test Part D****
	*******************
	*/
	
}