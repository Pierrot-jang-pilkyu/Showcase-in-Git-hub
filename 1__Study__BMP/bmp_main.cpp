// Bank Account Manage Program

#include "account.h"
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

// task processing UI by number.
void taskNum(int *num, int nowCustomers); 

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
			cout << "Unable to login." << endl;
		}
	}
	else{
		cout << "Unable to login." << endl; 
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






