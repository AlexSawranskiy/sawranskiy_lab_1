#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Printer
{
	string name;
	string type;
	string format;
	double speed;
};

void WritePrinterInFile(const Printer& printer)
{
	ofstream file("printers.dat", ios::binary | ios::app);
	file.write((char*)&printer, sizeof(Printer));
	file.close();
}

void ReadPrintersInFile()
{
	ifstream file("printers.dat", ios::binary);
	if (file.is_open())
	{
		while (!file.eof())
		{
			Printer printer;
			file.read((char*)&printer, sizeof(Printer));
			if (!file.eof())
			{
				cout << "Name: " << printer.name << endl;
				cout << "Type: " << printer.type << endl;
				cout << "Format: " << printer.format << endl;
				cout << "Speed:" << printer.speed << endl;
			}
		}
		file.close();
	}
	else
	{
		cout << "Unable to open this file" << endl;
	}
}

void AddPrinter()
{
	Printer printer;
	cout << "Enter printer details: " << endl;
	cout << "Name: ";
	cin >> printer.name;
	cout << "Type";
	cin >> printer.type;
	cout << "Format: ";
	cin >> printer.format;
	cout << "Speed: ";
	cin >> printer.speed;

	WritePrinterInFile(printer);

	cout << "Printer added successfull" << endl;
}

void DeletePrinter(const string& name)
{
	ifstream inFile("printers.dat", ios::binary);
	ofstream outFile("temp.dat", ios::binary);

	Printer printer;
	bool found = false;
	while (inFile.read((char*)&printer, sizeof(Printer)))
	{
		if (printer.name == name)
		{
			found = true;
		}
		else
		{
			outFile.write((char*)&printer, sizeof(Printer));
		}
	}
	inFile.close();
	outFile.close();

	remove("printers.dat");
	rename("temp.dat", "printers.dat");

	if (found)
	{
		cout << "Printer deleted succesfull" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
}

void LogOperation(const string& operation)
{
	ofstream LogFile("log.txt", ios::app);
	LogFile << operation << endl;
	LogFile.close();
}

int main()
{
	int choice;
	string name;

	do
	{
		cout << "1. Add Printer" << endl;
		cout << "2. Delete Printer" << endl;
		cout << "3. Print All Printers" << endl;
		cout << "4. Exti" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			AddPrinter();
			LogOperation("Added a printer");
			break;
		case 2:
			cout << "Enter name of printer to delete: ";
			cin >> name;
			DeletePrinter(name);
			LogOperation("Deleted a printer");
			break;
		case 3:
			ReadPrintersInFile();
			LogOperation("Printed all printers");
			break;
		case 4:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Error. Please> try again" << endl;

		}
	} while (choice != 4);

	return 0;
}