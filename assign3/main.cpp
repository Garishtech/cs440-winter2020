#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct employee {
    char id[8];
    char name[200];
    char bio[500];
    char manager_id[8];
};

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
					struct employee emp;
					stringstream ss(line);
					// Gets the column
					int counter = 0;
					while (getline(ss, colname, ',')) {
						switch(counter) {
							case 0:
								cout << colname;
								cout << "\n";
								strcpy(emp.id, colname.c_str());
								cout << emp.id;
								cout << "\n";
								break;
							case 1:
								cout << colname;
								cout << "\n";
								strcpy(emp.name, colname.c_str());
								cout << emp.name;
								cout << "\n";
								break;
							case 2:
								cout << colname;
								cout << "\n";
								strcpy(emp.bio, colname.c_str());
								cout << emp.bio;
								cout << "\n";
								break;
							case 3:
								cout << colname;
								cout << "\n";
								strcpy(emp.manager_id, colname.c_str());
								cout << emp.manager_id;
								cout << "\n";
								break;
						}
						cout << emp.id;
						cout << "\n";
						cout << emp.name;
						cout << "\n";
						cout << emp.bio;
						cout << "\n";
						cout << emp.manager_id;
						cout << "\n";
					}
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