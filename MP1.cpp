/* ========================================================
Leah Perry								CIS 161 Spring 2015
MP1							 			 Submitted: 1/30/15
Read, edit, and write file				Revised on: -------


Data Dictionary
Variable				Used to
--------				-------
string filename			stores the name of the file
char ch					stores character from file
string stringname		holds original file
string reversestring	holds edited file
int repeat				determines whether or not user wants to repeat program, set as 1 so it runs once
int letters				stores the number of letters in the original file
int LoLetters			stores the number of lowercase letters in the original file
int CapLetters			stores the number of capital letters in the original file
int SpacePunk			stores the number of spaces and punctuation marks in the original file
int numbers				stores the number of numbers in the original file
int Reletters			stores the number of letters in the reversed file
int ReLoLetters			stores the number of lowercase letters in the reversed file

Functions Called		What They Do
----------------		------------
OpenInputFile			Opens Input file
OpenOutputFile			Opens Output file
MainLoop				Determines whether or not user wants to repeat program


C:\User\Owner\My Documents\Visual Studio 2013\Projects\MP1b
==========================================================*/

//precompiler directives
#include <iostream>	//IO Functions
#include <fstream>	//external stream functions
#include <cstdlib>	//external errors
#include <string>	//string functions
#include <cmath>	//CMath
#include <stdlib.h>
#include <stdio.h> 
#include <iomanip>

using namespace std;

//function prototypes go here
ifstream OpenInputFile(string file); //opens input file
ofstream OpenOutputFile(string file); //opens output file
int MainLoop(); //determines whether or not to repeat program

//main function
int main (void) 
{
	/* ========================================================
	Leah Perry								CIS 161 Spring 2015
	MP1							 			 Submitted: 1/30/15
	Read, edit, and write file				Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	string filename			stores the name of the file
	char ch					stores character from file
	string stringname		holds original file
	string reversestring	holds edited file
	int repeat				determines whether or not user wants to repeat program, set as 1 so it runs once
	int letters				stores the number of letters in the original file
	int LoLetters			stores the number of lowercase letters in the original file
	int CapLetters			stores the number of capital letters in the original file
	int SpacePunk			stores the number of spaces and punctuation marks in the original file
	int numbers				stores the number of numbers in the original file
	int Reletters			stores the number of letters in the reversed file
	int ReLoLetters			stores the number of lowercase letters in the reversed file

	Functions Called		What They Do
	----------------		------------
	OpenInputFile			Opens Input file
	OpenOutputFile			Opens Output file
	MainLoop				Determines whether or not user wants to repeat program

	==========================================================*/
	//insert code here

	
	string filename; //the name of the file
	char ch; //character from file
	//Character types for the original file:
	int letters = 0;
	int LoLetters = 0;
	int CapLetters = 0;
	int SpacePunk = 0;
	int numbers = 0;
	//character types for the edited file:
	int Reletters = 0;
	int ReLoLetters = 0;
	string stringname = ""; //holds original file
	string reversestring = ""; //holds edited file
	int repeat = 1; //determines whether or not user wants to repeat program, set as 1 so it runs once

	ofstream outputstream; //makes stream to store output

	outputstream = OpenOutputFile("\LeahPerryConsoleOutput.dat"); //sets up output stream

	while (repeat == 1) { //while user wants to run program...
		ch = 'a'; //set as 'a' so the ch while loop runs once
		cout << "Enter the name of the file.\n"; //asks user for file
		outputstream << "Enter the name of the fle. \n"; //puts this into the console output file
		cin >> filename; //scans in filename
		outputstream << filename;

		ifstream streamname; //makes stream

		streamname = OpenInputFile(filename); //sets up stream

		while (ch != EOF) {//run until the EOF
			ch = streamname.get(); //gets first character from file
			stringname = stringname + ch; //adds first character to string
			cout << ch;
			outputstream << ch;
			if (ch >= 97 && ch <= 122) { //if ch is a lower case letter
				letters++;
				LoLetters++;
				Reletters++; //because the reverse values will be the same so we might as well add them now
				ReLoLetters++;
				continue;
			} //end lower case letters
			else if (ch >= 65 && ch <= 90){ //if ch is an uppercase letter
				letters++;
				CapLetters++;
				Reletters++; //because the reverse values will be the same so we might as well add them now
				ReLoLetters++;
				continue;
			}//end upper case letters
			else if (ch >= 48 && ch <= 57){//if ch is a number
				numbers++;
				continue;
			}//end numbers
			else { //otherwise it's a space or a punctuation mark
				SpacePunk++;
			}//end space/punctuation
			
		}



		//now to deal with reverse editing stuff

		for (int i = (stringname.length() - 1); i >= 0; i--){//goes through characters from the end to the beginning
			if (stringname[i] >= 65 && stringname[i] <= 90) { //checks if the character is uppercase
				stringname[i] = tolower(stringname[i]); //makes uppercase letters lowercase
			}//end if
			if (stringname[i] >= 97 && stringname[i] <= 122){ //checks if a character is a lowercase letter
				reversestring = reversestring + stringname[i]; //adds the lowercase letter to the reverse string
			}//end if
		}//end reverse-string-creation for



		ofstream reversestream; //makesstream

		reversestream = OpenOutputFile("\CIS160MP1output.dat"); //sets up output stream
		reversestream << reversestring; //puts the reverse string into the new file


		streamname.close();//close output stream
		reversestream.close();//close output stream


		cout << "\n-------------------\nCharacter Count:\n\nOriginal File:\n\tLetters: \t\t" << letters
			<< "\n\tLower Case Letters: \t" << LoLetters << "\n\tCapital: \t\t" << CapLetters << "\n\tNumbers: \t\t"
			<< numbers << "\n\tSpaces/Punctuation: \t" << SpacePunk << endl;//prints info on original file
		cout << "New File:\n\tLetters: \t\t" << Reletters << "\n\tLower Case Letters: \t" << ReLoLetters
			<< "\n\tCapital Letters: \t" << 0 << "\n\tNumbers: \t\t" << 0
			<< "\n\tSpaces/Punctuation: \t" << 0 << endl;//prints info on new file

		outputstream << "\n-------------------\nCharacter Count:\n\nOriginal File:\n\tLetters: \t\t" << letters
			<< "\n\tLower Case Letters: \t" << LoLetters << "\n\tCapital: \t\t" << CapLetters << "\n\tNumbers: \t\t"
			<< numbers << "\n\tSpaces/Punctuation: \t" << SpacePunk << endl;//prints info on original file into console output file
		outputstream << "New File:\n\tLetters: \t\t" << Reletters << "\n\tLower Case Letters: \t" << ReLoLetters
			<< "\n\tCapital Letters: \t" << 0 << "\n\tNumbers: \t\t" << 0
			<< "\n\tSpaces/Punctuation: \t" << 0 << endl;//prints info on new file into console output file

		outputstream.close();

		repeat = MainLoop();//checks if user wants to repeat the program
	}
return 0;
} //end main function

//insert function definitions here


ifstream OpenInputFile(string file) {
	/* ========================================================
	Leah Perry								CIS 161 Spring 2015
	MP1							 			 Submitted: 1/30/15
	Opens Input File						Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	string file				get filename
	ifstream instream		create input stream to file

	Functions Called		What They Do
	----------------		------------

	==========================================================*/
	ifstream instream;

	instream.open(file.c_str());  // Open the input stream
	if (instream.fail())    // If the input stream cannot open, report it then close the program
	{
		cerr << "\n\n Error. Cannot open " << file << endl;
	}
	else {
		cout << file << " has been opened.\n";
	}

	return instream;
}//opens instream

ofstream OpenOutputFile(string file) {
	/* ========================================================
	Leah Perry								CIS 161 Spring 2015
	MP1							 			 Submitted: 1/30/15
	Opens Output File						Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	string file				get filename
	ofstream outstream		create output stream to file

	Functions Called		What They Do
	----------------		------------

	==========================================================*/
	ofstream outstream;
	outstream.open(file.c_str()); //opens the output stream
	if (outstream.fail()) { //if output stream can't open, report to user
		cerr << "\n Error. Cannot Open " << file << endl;
	}
	else {
		cout << "\n" << file << " has been opened.\n";
	}
	return outstream;
} //opensoutstream


int MainLoop()
{
	/* ========================================================
	Leah Perry								CIS 161 Spring 2015
	MP1							 			 Submitted: 1/30/15
	Does the User Want to Rerun Code?		Revised on: -------


	Data Dictionary
	Variable				Used to
	--------				-------
	int MainLoopInput		holds value to determine answer
	int ans					hold int value to return results

	Functions Called		What They Do
	----------------		------------

	==========================================================*/
	string MainLoopInput;
	int ans = 3;
	while (ans == 3) {
		printf("Do you want to run the program again? \nEnter 'Yes' or 'Y' to continue the program. Enter 'No' or 'N' to close."); //exit prompt
		cin >> MainLoopInput; //scan user response
		if (MainLoopInput[0] == 'Y' || MainLoopInput[0] == 'y') {
			ans = 1; //if any variatoin of 'yes', program returns true
		}
		else if (MainLoopInput[0] == 'N' || MainLoopInput[0] == 'n') {
			ans = 0; //returns 0 for false
		}
	}
	return ans;
}//End MainLoop