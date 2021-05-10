#include <iostream>
#include <string>
#include <random> 
#include <chrono>
#include <vector>
#include <utility> 
#include <limits>

using namespace std;
// program user =  manager's ID
static string ManagerID = "pb_bank123";
static string ManagerPW = "pb_bank321";

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
// task processing UI by number.
void taskNum(int *num, int nowCustomers); 
// add account toi dynamic memory allocation
// void addMemAccount(Account *nowAccount, int nowCustomers);
// find account by name ( retouch this function )
int accountByName(Account *nowAccount, int nowCustomers);  

bool managerLogin();
// print account of all customers 
void allShowBalance(Account *nowAccount, int nowCustomers);

int main(){
	static int allCustomers = 0;
	static Account *allAccount = new Account;
	
	string choice; // in task processing choice variable
	int num = 0; // in task UI number initialize 
	int Amount = 0; // deposit or withdraw Amount initialize
	int index = -1; // return value in compare all list and input name. 
	
	while(1){
		
		taskNum(&num, allCustomers);
		
		
		
		switch(num){
			case 1 : // add new account
				 
				allCustomers++;
				
				if(allCustomers == 1){
					allAccount[allCustomers - 1].newCustomer();
				}
				else if(allCustomers == 2){
					Account *temp = new Account;
					temp->accountCopy(allAccount[0]);
					delete allAccount;
					allAccount = new Account[allCustomers];
					allAccount[0].accountCopy(temp[0]);
					allAccount[allCustomers - 1].newCustomer();
					delete temp;
				}
				else{
					Account *temp = new Account[allCustomers];
					for(int i = 0; i < allCustomers-1; i++){
						temp[i].accountCopy(allAccount[i]);
					}
					delete []allAccount;
					allAccount = new Account[allCustomers];
					for(int i = 0; i < allCustomers-1; i++){
						allAccount[i].accountCopy(temp[i]);
					}
					allAccount[allCustomers - 1].newCustomer();
					delete []temp;
				}
				break;
			case 2 : // deposit
				index = accountByName(allAccount, allCustomers);
				if(allCustomers == index){
					// no matched 
					cout << "Do not invalid value. Return to start menu." << endl;
					break; 
				}
				allAccount[index].deposit(&Amount);
				break;
			case 3 : // withdraw
				index = accountByName(allAccount, allCustomers);
				if(allCustomers == index){
					// no matched
					cout << "Do not invalid value. Please restart." << endl;
					break; 
				}
				allAccount[index].withdraw(&Amount);
				break;
			case 4 : // Balance inquiry
				index = accountByName(allAccount, allCustomers);
				if(allCustomers == index){
					cout << "Do not invalid value. Please restart." << endl;
					break; 
				}
				allAccount[index].showBalance();
				break;
			case 0 : // manager-only menu
				if(managerLogin()){
					int mNum;
					cout << "All customers balance inquiry. Press no.0 : "; mNum = getInt();
					cout << endl << endl << endl;
					allShowBalance(allAccount, allCustomers);
					break;
				}
				else{
					cout << "Login failed." << endl;
					cout << "Please restart." << endl;
				}
				break;
			default :
				cout << "Do not invalid value." << endl;
				cout << "Please check and press number again." << endl;
				break;
		}
		
		
		cout << "Return to start menu? (Y / N) : ";
		getline(cin, choice);
		if(choice == "y" || choice == "Y" || choice == "ㅛ"){
			continue;
		}
		else if(choice == "n" || choice == "N" || choice == "ㅜ"){
			break;
		}
		else{
			cout << "Wrong input data. Return to start menu. " << endl;
		}
		
	}
	
	
	delete []allAccount;
	
	return 0;
}

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
	
	if(answer == "y" || answer == "Y" || answer == "ㅛ"){
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
		
		if(*inAmount > (numeric_limits<int>::max() / 10)){
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
			if(answer == "y" || answer == "Y" || answer == "ㅛ")
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
			}
			else if(this->balance < *outAmount){
				cout << "You account balance is insufficient" << endl;
			}
			else{
				this->balance -= *outAmount;
				this->showBalance();
				
				cout << "Would you like to keep withdraw? (Y / N) : ";
				getline(cin, answer);
			if(answer == "y" || answer == "Y" || answer == "ㅛ")
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
	
void taskNum(int *num, int nowCustomers){
	
	cout << "Currently, the number of accounts on the sever is : " << nowCustomers;
	cout << endl << endl << endl; 
	
	cout << "Please enter the task number to be processed." << endl << endl;
	cout << "Make new account : Enter no.1" << endl;
	cout << "Deposit : Enter no.2" << endl;
	cout << "Withdraw : Enter no.3, " << endl;
	cout << "Balance iquiry : Enter no.4" << endl;
	cout << "Manager-only menu : Enter no.0" << endl << endl << endl;
	cout << "Entered by number : ";
	
	*num = getInt();
	
	return;
	
}
/* error -> Implemented in main().	
void addMemAccount(Account *nowAccount, int nowCustomers){
	int i;
	Account *tempAccount = new Account[nowCustomers];
	
	for(i = 0; i < nowCustomers-1; i++){
		cout << i + 3 << endl;
		tempAccount[i].accountCopy(nowAccount[i]);
	}
	delete []nowAccount;
	
	nowAccount = new Account[nowCustomers];
	
	for(i=0; i< nowCustomers; i++){
		cout << i + 8 << endl;
		nowAccount[i].accountCopy(tempAccount[i]);
	}
	
	delete []tempAccount;
}*/

int accountByName(Account *nowAccount, int nowCustomers){
	int i; string name;
	
	cout << "Enter the customer's name : "; getline(cin, name);

	for(i = 0; i < nowCustomers; i++){
		if(nowAccount[i].compareName(name) == 0){
			nowAccount[i].showAccount();
			break;
		}
	}
	
	if(i == nowCustomers){
		char c;
		cout << "There is no account to that customer." << endl;
	}
	return i;
}

bool managerLogin(){
	int compareID =2, comparePW = 2;
	string ID, PW;
	
	cout << "Manager I	D : "; getline(cin, ID);
	compareID = ManagerID.compare(ID);
	if(compareID == 0){
		cout << "Manager PASSWORD : "; getline(cin, PW);
		comparePW = ManagerPW.compare(PW);
		
		if(comparePW == 0){
			cout << "Lonined." << endl;
			return true;
		}
		else{
			cout << "Wrong Manager PASSWORD." << endl;
		}
	}
	else{
		cout << "Wrong Manager ID." << endl; 
	}
	
	return false;
}

void allShowBalance(Account *nowAccount, int nowCustomers){
	int i;
	
	for(i = 0; i < nowCustomers; i++){
		nowAccount[i].showName();
		nowAccount[i].showAccount();
		nowAccount[i].showBalance();
		cout << endl << endl; 
	}
	return;
}






