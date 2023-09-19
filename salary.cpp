
//programm to calculate net salary of manager and secretary

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

void ClearConsole(){
	system("cls");
}

class SManager
{
	public:
	double salary;
	double netSalary;
	double Afuel = 0.14* salary;
	double Arent = 0.20 * salary;
	double Aentertainment = 0.18 * salary;
	double Arisk = 0135 * salary;
	double tax = 0.15 * salary;
	double SSNIT= 0.185 * salary;
	public:
		void TakeHome(){
			netSalary = (Afuel + Arent + Arisk) - (tax + SSNIT);
		}
	
	
	
};

class Ssecretary 
{
	public:
	double salary;
	double netSalary;
	double Afuel = 0.14 * salary;
	double Arent = 0.135 *salary;
	double Ahealth = 0.15 *salary;
	double tax = 0.15 * salary;
	double SSNIT= 0.185 * salary;
	
	public:
		void TakeHome(){
			netSalary = Afuel + Arent + Ahealth - tax - SSNIT;
		}
};

class AccountInfo{	
	public:
		AccountInfo(int userType, string userName, string password) : user_type(userType),user_name(userName), password_(password){	}
		int user_type;
		string user_name;
		string password_;	
};

//Vector for storring user data

vector<AccountInfo> AllUsers;


void CalculateSalary(string name,string password){
	double salary;
	double netSalary;
	cout<<"enter Gross Salary\n";
					cin>>salary;
	for(int i = 1; i< AllUsers.size(); i++){
		const AccountInfo Info = AllUsers[i];		
		if(name == Info.user_name && password == Info.password_ && Info.user_type == 1){
					SManager Manager;
					
					Manager.salary = salary;
					Manager.TakeHome();
					netSalary = round(Manager.netSalary);
		}else{
			double salary;
				Ssecretary Secretary;
					cin>>salary;
					Secretary.salary = salary;
					netSalary = round(Secretary.netSalary);
					Secretary.TakeHome();
		}
	}
	
	cout<<"Your Current Net salary is GHC "<<netSalary;
}

 void LogIn()
{
	string name;
	string password;
	string compName;
	string compPass;
	bool firstAtempt = true;
	bool valid = false;	
	
	cout<<"LogIn to access all features of app\n\n";
	
	do{
		cout<<"Enter User name: ";
		cin>>name;
		
		cout<<"Enter pasword: ";
		cin>>password;
		
		for(int i = 0; i < AllUsers.size(); i++){
		const AccountInfo obj = AllUsers[i];
		
		if(name == obj.user_name && password == obj.password_){
			compName = name;
			compPass = password;
		}
	}
	}
	while(name != compName);
	
	 CalculateSalary(name,password);
}

string SignUp(){
	string userName;
	int emptype;
	string password;
	string confirmPass;
	
	cout<<"Enter User name :";
	cin>>userName;
	
	cout<<"Employment Type: "<<endl;
	cout<<"(1) Manager (2) Secretary : ";
	cin>>emptype;


	cout<<"Create Password: ";
	cin>>password;
		
	AllUsers.push_back(AccountInfo(emptype,userName,password));
	
	for(int i = 0; i< AllUsers.size(); i++){
		const AccountInfo obj = AllUsers[i];
		cout<<obj.password_;
	}
	
	ClearConsole();
	
	cout<<"Account created successfully"<<endl<<endl;
	cout<<"LogIn to continue\n"<<endl;
	LogIn();
}

string Home()
{
	int action;
	cout<<"--------------------"<<endl;
	cout<<"(1) LogIn";
	cout<<"\n(2) SignUp"<<endl;
	cout<<"--------------------"<<endl;
	
	cout<<"Input Here : ";
	cin>>action;
	
	ClearConsole();
	
	switch(action){
		case 1:
			LogIn();
			break;
		case 2:
			SignUp();
			break;			
	}
}

int main()
{
	Home();
	cin.get();
	return 0;
}
