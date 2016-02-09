//============================================================================
// Name        : instrparserplus.cpp
// Author      : Antonin Karlo M. Tilaon
// Course Info : Dr. Rainwater / COSC 3355 Assgnment I
// Description : Instrction Parser
// NOTE		   : I was able to piece together the Assignment
//  		   : because of the huge support of the online-community
// Notably	   : Stackoverflow.com , cplusplus.com , MinGW.com , Eclipse.com
//============================================================================
//I notice that the assignment only manages the first 10 Registers, since each
//register holds three-digit integer means d or n could only reach up until 9
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
int memtrix[1000],instr=0, increm=0;


int main()
{
	//matrix-check
	cout << "Initialize RAM" << endl;
	for(int i=0; i<1000; i++)
	{
		 cout << "Register"<<i<<":  " << memtrix[i] <<endl;
	}
	// create a file-reading object
	ifstream fin("input.txt");
	if(!fin){
		cout << "No input file found" << endl;
		return 1;
	}//END file-checker
	cout << "Found input.txt" << endl;
	cout << "Parsing input lines" << endl;
	cout << endl;
	std::string line;
	ofstream fou("output.txt");

	//Parses Input File and install them to the matrix
	while(getline(fin, line)){
		std::stringstream iss(line);
			 iss >> instr;
			 memtrix[increm] = instr;
			 cout << "Register"<<increm<<":  " << memtrix[increm] <<endl;
			 increm++;
	  }//END while parser

	fin.close();
	fou.close();
}//END main



class Interp{

	static int PC;
	static int registers[10];
	static int instr_type;
	static int memory[1000];
	static int instructionCounter;
	static bool run_bit;

	public:void interpret(int memory[], int starting_address){
		run_bit = true;
		PC = starting_address;
		while(run_bit){

			instr = memory[PC];		//fetch next instruction into instr
			PC++;		//increment program counter
			instr_type = get_instr_type(instr);		//determine instruction type

			/*put //execute instruction*/
		}//END while run_bit is true
	}//END method interpret


	private:static int get_instr_type(int addr){
		return 0;
	}//END method get_instr_type

	private:static void execute(int type, int data){

	}//END method execute

};//END class Interp

