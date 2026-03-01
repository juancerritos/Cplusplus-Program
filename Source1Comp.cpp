string twoDigitString(unsigned int n) {
	stringstream a;
	a << n;
	string b;
	if (n < 10) {
		b = "0" + a.str();
	}
	else {
		b = a.str();
	}
}
string nCharString(size_t n, char c) {
	string j = "";
	for (int i = 0; i < n; i++) {
		j += c;
	}
	return j;
}
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	string time24 = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
	return time24;
}
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
	string time12;
	if (h == 0) {
		time12 = twoDigitString(12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
	}
	else if (h < 12) {
		time12 = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
	}
	else if (h == 12) {
		time12 = twoDigitString(12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
	}
	else {
		time12 = twoDigitString(h - 12) + ":" + twoDigitString(m) + ":" twoDigitString(s) + " P M";
	}
	return time12;
}
void printMenu(const char* strings[], unsigned int numStrings, unsigned int width) {
	cout << nCharString(width, '*') << endl;
	for (int i = 0; i < numStrings; i++) {
		stringstream strs;
		strs << endl <<  "* " << i + 1 << " - " << strings[i];
		strings st = strs.str();
		cout << setw(width - 1) << left << st;
		cout << "*" << endl;
	}
	cout <<  nCharString(width, '*') endl;
} 
unsigned int getMenuChoice(unsigned int maxChoice) {
	int value = 0;
	while (!((value >= 1) && (value <= maxChoice))) {
		cin >> value;
	}
		return value;
	}
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
	cout << "*" << nCharString(6, ' ') << "12-Hour Clock" << nCharString(6, ' ') << "*" << nCharString(3, );
	cout << "*" << nCharString(6, ' ') << "24-Hour Clock" << nCharString(6, ' ') << "*" << endl;
	cout << endl;
	cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');
	cout << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
	cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}
void mainMenu() {
	const char* strings[4] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
	int choice = 0;
	while (choice != 4) {
		choice = getMenuChoice(4);
		switch (choice) {
		case 1: addOneHour();
			break;
		case 2: addOneMinute();
			break;
		case 3: addOneSecond();
			break;
		case 4:
			break;
		}
		}
}
void addOneSecond() {
	if (getSecond() <= 0 && getSecond() <= 58) {
		setSecond(getSecond() + 1);
	}
	else {
		setSecond(0);
		addOneMinute();
	}
}
void addOneMinute() {
	if (getMinute() >= 0 && getMinute() <= 58) {
		setMinute(getMinute() + 1);
	}
	else {
		setMinute(0);
		addOneHour();
	}
};
void addOneHour() {
	if(getHour() >= 0 && getHour() <= 22) {
		setHour(getHour() + 1);
	}
	else {
		setHour(0);
	}
};