// Account management class

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <limits>

using namespace std;


class Account{
private :
	string personalAccount; // customer account
	string password;		// account password
	pair<string, string> customerName;
	int balance;			 
	
public :
	// constructor 
	Account(){
		// account is  "Numbers of 6 - 3 - 6".
		this->personalAccount.replace(0, 0, "000000-000-000000");
		// password is "Numbers of 4".
		this->password.replace(0, 0, "0000");
		// customer's name is made up to Given Name, Familly Name.
		this->customerName = make_pair("", "");
		// balance's initialize 
		this->balance = 0;
	}
	
	// get new customer's information
	void newCustomer();
	// make new account
	string newAccount();
	
	void showName();
	
	int compareName(string name); 
	
	void showAccount();
	
	void deposit(int *inAmount);
	
	void withdraw(int *outAmount);
	
	void showBalance();
	
	void showPassword();
	
	void accountCopy(Account act);
	
	// distructor 
	~Account(){
		this->personalAccount.clear();
		this->password.clear();
		this->customerName.first.clear();
		this->customerName.second.clear();
		this->balance = 0;
	}
	
};

// scan integer value ignoring '\n'.
int getInt(); 

// Function is implemented. Under coding


void Account::newCustomer(){
	this->newAccount();
	
	cout << "Enter 4 account password numbers : ";
	getline(cin, this->password);
	
	string instr, givenName, famillyName;
	
	
	cout << "Enter customer's name : ";
	getline(cin, instr);
	
	long int index;
	index = instr.find(" ", 0);
	
	if(index > instr.length()){
		givenName.replace(0, instr.length(), instr);
	}
	else{
		givenName.replace(0, instr.substr(0, index).length(), instr.substr(0, index));
		famillyName.replace(0, instr.substr(index + 1).length(), instr.substr(index + 1));
	}
	// Hangul's char type conversion, return negative number.
	// English is positive number on ascii table(capital letter 65-90, small letter 97-122) 
	if(givenName.front() < 0) { // Hangul(2bytes)'s char type(first factor) conversion, return negative number.
		if(givenName.length() == 2){ // Korea culture(allmost first name is one letter in Hangul)
			this->customerName = make_pair(givenName, famillyName);
		}
		else{
			if(famillyName.length() > 1){
				this->customerName = make_pair(givenName, famillyName);
			}
			else{
				this->customerName = make_pair(givenName.substr(0,2), givenName.substr(2));
			}
		}	
	}
	else{
		// English name 
		this->customerName = make_pair(givenName, famillyName);
	}
	
	
	this->showBalance();
	
	string answer;
	
	cout << "Do you deposit? (Y / N) : ";
	getline(cin, answer);
	
	if(answer == "y" || answer == "Y" || answer == "???"){
		int in;
		
		this->deposit(&in);
	}
	cout << "Success making new account." << endl << endl;
	
	this->showName();
	this->showAccount();
	this->showPassword();
	this->showBalance();
		
	return;
	
}

string Account::newAccount(){
	// Random number generation to get new customer account.
	// "std::random_device" generation to get seed. 
	//	but "random_device rd;"" <<< Since I did this as a seed, only a certian number came out. 
	
	// Initialize the random number engine through the computer's now time "time(NULL)".
	// "std::mt19937" is one of the random number engines providing at C++ <random> library.
	// Using an algorithm called Mersenne Twister,
	// it generates a higher quality random number sequence than the existing linear congruence method. 
	mt19937 gen(time(NULL));
	
	// "dis()" is the uniform distribution definition to uniformly generate random sequence at the range.
	uniform_int_distribution<int> dis(100000, 999499);
	
	// New customer's account generation.  
	for(int i = 0; i < 3; i++){
		switch(i){
			case 0 :
				this->personalAccount = to_string(dis(gen)) + '-';
				break; 
			case 1 :
				this->personalAccount += to_string(dis(gen) / 1000) + '-';
				break;
			case 2 :
				this->personalAccount += to_string(dis(gen));
				break;
			default : break; // Account is made up "15 numbers integer and 2 numbers '-'".
		}
	}
	
	return this->personalAccount;
}

void Account::showName(){
	
	if(this->customerName.first.front() < 0){ // if Hangul
		if(this->customerName.first.length() > 2){
			cout << "Customer's name : ";
			cout << this->customerName.first << " " << this->customerName.second << endl;
		}
		else{
			cout << "Customer's name : ";
			cout << this->customerName.first << this->customerName.second << endl;
		}
	}
	else{ // if English 
		cout << "Customer's name : ";
		cout << this->customerName.first << " " <<this->customerName.second << endl;
	}
	return;
}

int Account::compareName(string name){
	int compare = 2; // Because of returned value "-1, 0, 1" at the function.
	string sub;
	
	int index =0;
	index = name.find(" ", 0);
	// 0, name.length(),
	if(this->customerName.first.front() < 0){ // Hangul
		sub = this->customerName.first + this->customerName.second;
		compare = name.compare(sub);
		if(compare != 0){
			sub = this->customerName.first + ' ' +this->customerName.second;
			compare = name.compare(sub);
		}
	}
	else{
		sub = this->customerName.first + ' ' +this->customerName.second;
		compare = name.compare(sub);
	}
	
	return compare;
}

void Account::showAccount(){
	cout << "Account : " <<this->personalAccount << endl;
	return;
}

void Account::deposit(int *inAmount){
	string answer;
	while(1){
		
		cout << "Deposit amount : "; *inAmount = getInt();
		
		// int max : 214748364
		if(*inAmount > (numeric_limits<int>::max()) / 2){
			cout << "The amount is too large to be processed." << endl;
			cout << "Talk to the person in charge." << endl << endl;
			break;
		}
		else if(*inAmount < 0){
			cout << "Please chack the amount again." << endl;
		}
		else{
			this->balance += *inAmount;
			this->showBalance();
			
			cout << "Would you like to keep deposit? (Y / N) : ";
			getline(cin, answer);
			if(answer == "y" || answer == "Y" || answer == "???")
				continue;
			else break;
		}
	}
	return;
}
	
void Account::withdraw(int *outAmount){
	string answer; 
	while(1){
		cout << "Withdraw amount : "; *outAmount = getInt();
		
		if(*outAmount > 0){
			if(this->balance == 0){
				cout << "There is no account balance." << endl;
				break;
			}
			else if(this->balance < *outAmount){
				cout << "Your account balance is insufficient" << endl;
			}
			else{
				this->balance -= *outAmount;
				this->showBalance();
				
				cout << "Would you like to keep withdraw? (Y / N) : ";
				getline(cin, answer);
			if(answer == "y" || answer == "Y" || answer == "???")
				continue;
			else break;
			}
		}
		else{
			cout << "$0 can't withdraw." << endl;
		}
	} 
	return;
}
	
void Account::showBalance(){
	if(this->balance == 0){
		cout << "Balance : $ 0 " << endl;
		return;
	}
	else{
		cout << "Balance : $ " << this->balance << endl;
		return;
	}
}

void Account::showPassword(){
	cout << "Password : " << this->password << endl; 
	return;
} 

void Account::accountCopy(Account act){
	this->customerName = make_pair(act.customerName.first, act.customerName.second);
	this->personalAccount.replace(0, act.personalAccount.length(), act.personalAccount);
	this->password.replace(0, act.password.length(), act.password);
	this->balance = act.balance;
	return;
}

// A temporary measure

int getInt(){
	int in;
	
	while(1){
		
		cin >> in;
		
		if(cin.fail()){ // If failbit is "1", it becomes true and setisfy the conditional statement. 
			
			cin.clear(); // Initialize failbit
			// initialize failbit. Because of still input buffer is remained, using "ignore()".
			// numeric_limits<Type>::max() return the max value of the type. this is 9223372036854775807. 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ends the function when it encounters '\n'(newline letter).
			cout << "No invalid input. Please enter again : "; 
		}
		else{
			// failbit is zero. invalid input.
			// Ignore space characters('\n' etc.) in the input buffer other than integers 
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			return in; 
		}
	}
}




#endif