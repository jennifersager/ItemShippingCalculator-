
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
//file that output goes to
const string OUTFILENAME = "Order.txt";

int main()
{
	//stream objects
	ofstream fOutStream;

	//open stream objects
	fOutStream.open(OUTFILENAME);
	if (!fOutStream)
	{
		cout << "Error in opening the file" << endl;
		return 0;
	}

	double shipping = 0;
	//no magic numbers
	const double fragilecost = 2;
	const double total1 = 50;
	const double total2 = 100;
	const double total3 = 150;
	const double usacharge1 = 6;
	const double usacharge2 = 9;
	const double usacharge3 = 12;
	const double cancharge1 = 8;
	const double cancharge2 = 12;
	const double cancharge3 = 15;
	const double auscharge1 = 10;
	const double auscharge2 = 14;
	const double auscharge3 = 17;
	const double marscharge1 = 20;
	const double marscharge2 = 30;
	const double marscharge3 = 40;
	const double free = 0;
	
	//initalize and collect input

	string itemname;
	cout << "Please enter the item name (no spaces)" << endl;
	cin >> itemname;

	string fragile;
	cout << "Is the item fragile? (y=yes/n=no)" << endl;
	cin >> fragile;

	//check if fragile entered correctly 
	if (fragile != "y" && fragile != "Y" && fragile != "n" && fragile != "N")
	{
		cout << "Invalid entry. Program exiting." << endl;
		system("pause");
		return 0;
	}
	
	//determine fragile fee
	if (fragile == "y" || fragile == "Y")
		shipping = shipping + fragilecost;
	else
		shipping = 0;

	double ordertotal;
	cout << "Please enter your order total" << endl;
	cin >> ordertotal;

	string dest;
	cout << "Please enter desination (usa/can/aus/mars)" << endl;
	cin >> dest;

	//check if dest entered correctly 
	if (dest != "USA" && dest != "CAN" && dest != "AUS" && dest != "MARS" && dest != "usa" && dest != "can" && dest !="aus" && dest != "mars")
	{
		cout << "Invalid entry. Program exiting." << endl;
		system("pause");
		return 0;
	}

	// make itemname and dest all capital letters
	transform(dest.begin(), dest.end(), dest.begin(), ::toupper);
	transform(itemname.begin(), itemname.end(), itemname.begin(), ::toupper);
	
	//if structure for destination
	if (dest == "USA")
	//nested if for shipping charges
	{
		if (ordertotal < total1)
			shipping = shipping + usacharge1;
		else if (ordertotal > total1 && ordertotal < total2)
			shipping = shipping + usacharge2;
		else if (ordertotal > total2 && ordertotal < total3)
			shipping = shipping + usacharge3;
		else
			shipping = shipping + free;
	}
	else if (dest == "CAN")
	{
		if (ordertotal < total1)
			shipping = shipping + cancharge1;
		else if (ordertotal > total1 && ordertotal < total2)
			shipping = shipping + cancharge2;
		else if (ordertotal > total2 && ordertotal < total3)
			shipping = shipping + cancharge3;
		else
			shipping = shipping + free;
	}
	else if (dest == "AUS")
	{
		if (ordertotal < total1)
			shipping = shipping + auscharge1;
		else if (ordertotal > total1 && ordertotal < total2)
			shipping = shipping + auscharge2;
		else if (ordertotal > total2 && ordertotal < total3)
			shipping = shipping + auscharge3;
		else
			shipping = shipping + free;
	}
	else
	{
		if (ordertotal < total1)
			shipping = shipping + marscharge1;
		else if (ordertotal > total1 && ordertotal < total2)
			shipping = shipping + marscharge2;
		else if (ordertotal > total2 && ordertotal < total3)
			shipping = shipping + marscharge3;
		else
			shipping = shipping + free;
	}
	// determine total cost
	double totalshipping = 0;
	totalshipping = ordertotal + shipping;

	//output to console
	cout << "Your item is" << setw(39) << itemname << endl;
	cout << "Your shipping cost is " << setw(21) << fixed << setprecision(2) << "$" << shipping << endl;
	cout << "You are shipping to " << setw(25) << dest << endl;
	cout << "Your total shipping costs are " << setw(13) << fixed << setprecision(2) << "$" << totalshipping << endl;
	cout << setw(52) << "Thank You!" << endl;
	
	//output to file
	fOutStream << "Your item is" << setw(39) << itemname << endl;
	fOutStream << "Your shipping cost is " << setw(21) << fixed << setprecision(2) << "$" << shipping << endl;
	fOutStream << "You are shipping to " << setw(25) << dest << endl;
	fOutStream << "Your total shipping costs are " << setw(13) << fixed << setprecision(2) << "$" << totalshipping << endl;
	fOutStream << setw(52) << "Thank You!" << endl;
	
	//close file
	fOutStream.close();
	return 0;
}


