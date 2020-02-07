#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	// Variable to store input
	string input;

	// Keeps asking for input until user exits the program
	while(input != "exit") {
		
		// Gets the users input
		cout << "Enter choice (type \"exit\" to exit the program): ";
		cin >> input;

		// Runs the option for "C"
		if (input == "C") {

			// Get the input file
			ifstream myFile("Employee.csv");

			// Gets each value from each tuple
			string line, colname;
			if (myFile.good()){
				// Gets the line
				while (getline(myFile, line)) {
					stringstream ss(line);
					// Gets the column
					while (getline(ss, colname, ',')) {
						cout << colname << " | ";
					}
					cout << "\n";
				}
			}

		}

		// Runs the option for "L"
		else if (input == "L") {

		}

	}

	// Exits the program
	return 0;
}