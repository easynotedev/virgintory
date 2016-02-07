//============================================================================
// Name        : instrparserplus.cpp
// Author      : Antonin Karlo M. Tilaon
// Course Info : Dr. Rainwater / COSC 3355 Assgnment I
// Description : Instrction Parser
// NOTE		   : I was able to piece together the Assignment
//  		   : because of the huge support of the online-community
// Notably	   : Stackoverflow.com , cplusplus.com , MinGW.com , Eclipse.com
//============================================================================

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <cstring>
using std::string;
#include <sstream>

//Initialize parameters
int memtrix[10],instr=0, increm=0;;

int main()
{
	//matrix-check
	for(int i=0; i<10; i++)
	{
		cout << memtrix[i] << endl;
	}
	// create a file-reading object
	ifstream fin("input.txt");
	if(!fin){
		cout << "No input file found" << endl;
		return 1;
	}//END file-checker
	cout << "Found input.txt" << endl;
	cout << "Parsing lines" << endl;
	std::string line;
	ofstream fou("output.txt");

	//Parses Input File and install them to the matrix
	while(getline(fin, line)){
		std::stringstream iss(line);
			 iss >> instr;
			 memtrix[increm] = instr;
			 cout << memtrix[increm] <<endl;
			 increm++;
	  }//END while parser

	fin.close();
	fou.close();
}//END main

