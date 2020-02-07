#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>
#include <string.h>

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

	// Creates our linear hash table
	unordered_map<string, struct employee> constants;

	// Keeps asking for input until user exits the program
	while(input != "exit") {
		
		// Gets the users input
		cout << "Enter choice (type \"C\", \"L\", or \"exit\" to exit the program): ";
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

						// Adds the values to their specific variable in the employee struct
						switch(counter) {
							case 0:
								strcpy(emp.id, colname.c_str());
								break;
							case 1:
								strcpy(emp.name, colname.c_str());
								break;
							case 2:
								strcpy(emp.bio, colname.c_str());
								break;
							case 3:
								strcpy(emp.manager_id, colname.c_str());
								break;
						}
						counter = counter + 1;

					}

					// Adds our employee struct as a value in our linear hash table
					stringstream str(emp.id);
					string id;
					str >> id;
					constants.insert(make_pair(id, emp));

				}

			}

			// Lets the user know the tuples have been added to the hash table
			cout << "Relations have been added to the table from the \"Employee.csv\" file." << endl;

		}

		// Runs the option for "L"
		else if (input.at(0) == 'L') {

			// Gets the id of the tuple the user wants
			string index = input.substr(1);

			// Prints the matching tuple
			for (auto itr = constants.begin(); itr != constants.end(); itr++) {
				if (itr->first == index) {
					cout << "ID: " << itr->second.id << endl;
					cout << "Name: " << itr->second.name << endl;
					cout << "Bio: " << itr->second.bio << endl;
					cout << "Manager ID: " << itr->second.manager_id << endl;
				}
			}

		}

	}

	// Exits the program
	return 0;
}