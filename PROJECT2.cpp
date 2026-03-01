
#include <iostream>
#include <iomanip>

using namespace std;

void printDetails(int year, double yearEndBalance, double interestEarned) {

	cout << left << setw(12) << year;
	cout << left << "$" << setw(19) << fixed << setprecision(2) << yearEndBalance;
	cout << left << "$" << setw(18) << fixed << setprecision(2) << interestEarned << endl;
	cout << endl;
}


double calculateBalanceWithMonthlyDeposit(double initalInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {

	double balance = initalInvestment;
	double monthlyRate = (interestRate / 100.0) / 12.0;

	for (int year = 1; year <= numberOfYears; ++year) {
		double interestEarnedThisYear = 0.0;

		for (int month = 1; month <= 12; ++month) {
			double monthlyInterest = balance * monthlyRate;
			balance += monthlyDeposit;
			balance += monthlyInterest;
			interestEarnedThisYear += monthlyInterest;
		}
		printDetails(year, balance, interestEarnedThisYear);
		}
	return balance;
}

double calculateBalanceWithOutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {

	double balance = initialInvestment;
	double monthlyRate = (interestRate / 100.0) / 12.0;

	for (int year = 1; year <= numberOfYears; ++year) {
		double interestEarnedThisYear = 0.0;

		for (int month = 1; month <= 12; ++month) {
			double monthlyInterest = balance * monthlyRate;
			balance += monthlyInterest;
			interestEarnedThisYear += monthlyInterest;
		}
		printDetails(year, balance, interestEarnedThisYear);

	}
	return balance;

}


double getDouble(string prompt) {
		double value;
		while (true) {
			cout << prompt;
			cin >> value;
			if (cin.fail() || value < 0) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid" << endl;
			}
			else {
				return value;
			}
		}
	}
int main() {
	double initialInvestment;
	double interestRate;
	double monthlyDeposit;
	int numberOfYears;


		cout << "*********************************\n"; //displays the menu
		cout << "********* Data Input ************\n";
		cout << endl;

		cout << "Initial Investment Amount: $\n";
		cout << "Monthly Deposit: $\n";
		cout << "Annual Interest: %\n";
		cout << "Number of Years: \n";
		cout << "Press enter key to continue . . ." << endl;
		cout << endl;

		cout << "*********************************\n"; //displays menu while taking values
		cout << "********* Data Input ************\n";
		cout << endl;

		initialInvestment = getDouble("Initial Investment Amount: $");
		monthlyDeposit = getDouble("Monthly Deposit: $");
		interestRate = getDouble("Annual Interest: %");
		numberOfYears = getDouble("Number of Years: ");
		cout << "Press enter key to continue . . ." << endl;
		cout << endl;
	
		cout << "Balance and Interest Without Additional Monthly Deposits" << endl;//calls and calculates then presents
		cout << "________________________________________________________" << endl;
		cout << "________________________________________________________" << endl;
		cout << left << setw(8) << "Year";
		cout << left << setw(20) << "Year End Balance";
		cout << right << setw(25) << "Year End Earned Interest";
		cout << endl;
		cout << "--------------------------------------------------------" << endl;
		calculateBalanceWithOutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);
		cout << endl;

		cout << "Balance and Interest With Additional Monthly Deposits" << endl;//calls and calculates then presents
		cout << "_____________________________________________________" << endl;
		cout << "_____________________________________________________" << endl;
		cout << left << setw(8) << "Year";
		cout << left << setw(20) << "Year End Balance";
		cout << right << setw(25) << "Year End Earned Interest";
		cout << endl;
		cout << "-----------------------------------------------------" << endl;
		calculateBalanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
		cout << endl;



}