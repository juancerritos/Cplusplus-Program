#include <iostream>
#include <fstream>
#include <map>
#include <string>

class Grocery {

private: 
	std::map<std::string, int> itemFrequency;

public:
	Grocery() {
		loadFromFile();
	}
	void loadFromFile() {
		std::ifstream inputFile("CS210_Project_Three_Input_File.txt");
		if (!inputFile) {
			std::cerr << "Error: Unable to open input file" << std::endl;
			exit(1);
		}
		std::string item;
		int quantity;

		while (inputFile >> item >> quantity) {
			itemFrequency[item] = quantity;
		}
		inputFile.close();
	}
	void searchItem() {
		std::string searchItem;
		std::cout << "Enter item or word you wish to look for: ";
		std::cin >> searchItem;

		if (itemFrequency.find(searchItem) != itemFrequency.end()) {
			std::cout << "Frequency of " << searchItem << ": " << itemFrequency[searchItem] << std::endl;
		}
		else {
			std::cout << searchItem << " not found." << std::endl;
		}
	}
	void printList() {
		for (const auto& pair : itemFrequency) {
			std::cout << pair.first << " " << pair.second << std::endl;
		}
	}
	void printHistogram() {
		for (const auto& pair : itemFrequency) {
			std::cout << pair.first << " ";
			for (int i = 0; i < pair.second; ++i) {
				std::cout << "*";
			}
			std::cout << std::endl;
		}
	}
	void saveToFile() {
		std::ofstream outputFile("frequency.dat");
		if (!outputFile) {
			std::cerr << "Error: Unable to open file!" << std::endl;
			return;
		}
		for (const auto& pair : itemFrequency) {
			outputFile << pair.first << " " << pair.second << std::endl;
		}
		outputFile.close();
		std::cout << "Data file saved to frequency.dat" << std::endl;
	}
};
int main() {
	Grocery cornerGrocer;
	int choice;

	do {
		std::cout << "Menu" << std::endl;
		std::cout << "1. Search for an item" << std::endl;
		std::cout << "2. Print the list of items and their frequencies" << std::endl;
		std::cout << "3. Print histogram of item frequencies" << std::endl;
		std::cout << "4. Save to data file" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cout << "Enter your choice";
		std::cin >> choice;

		switch (choice) {
		case 1:
			cornerGrocer.searchItem();
			break;
		case 2:
			cornerGrocer.printList();
			break;
		case 3:
			cornerGrocer.printHistogram();
			break;
		case 4:
			cornerGrocer.saveToFile();
			break;
		case 5:
			std::cout << "Exiting" << std::endl;
			break;
		default:
			std::cout << "Invalid Choice" << std::endl;
		}
	} while (choice != 5);
return 0;
}