#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	string input;

	while(input != "exit") {
		cout << "Enter choice (type \"exit\" to exit the program): ";
		cin >> input;

		if (input == "C") {
			ifstream myFile("Employee.csv");
			string line, colname;
			if (myFile.good()){
				while (getline(myFile, line)) {
					stringstream ss(line);
					while (getline(ss, colname, ',')) {
						cout << colname + "|";
					}
					cout << "\n";
				}
			}
		}
		else if (input == "L") {

		}

	}
	return 0;
}