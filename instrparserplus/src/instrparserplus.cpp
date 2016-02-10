//============================================================================
// Name        	: instrparserplus.cpp
// Author      	: Antonin Karlo M. Tilaon
// Course Info 	: Dr. Rainwater / COSC 3355 Assgnment I
// Description 	: Instruction Parser
// Accreditation: The assignment template almost gave the answer
//				: I was able to piece together the general idea of the assignment
//				: due to the template. Although I got the syntax of parsing
//				: the text file online Notably, stackoverflow.com cplusplus.com
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
using std::stringstream;

class Interp{

	static int PC;
	static int registers[10];
	static int instr;
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
			execute(1,1); //execute instruction*/
		}//END while run_bit is true
	}//END method interpret


	private:static int get_instr_type(int addr){
		return 0;
	}//END method get_instr_type

	private:static void execute(int type, int data){

	}//END method execute
};//END class Interp

int main()
{
	//create/initialize memory
	int memtrix[1000], instrno=0, increm=0;
	string line; //Used in parsing
	// create a file-reading object
	ifstream fin("input.txt");
	ofstream fou("output.txt");
	if(!fin){
		cout << "No input file found" << endl;
		return 1; //abort main
	}//END file-checker
	cout << "Found input.txt" << endl;
	cout << "Parsing input lines" << endl;

	//Parses Input File and install them to the matrix
	while(getline(fin, line)){
		stringstream iss(line);
			 iss >> instrno;
			 memtrix[increm] = instrno;
			 cout << "Register"<<increm<<":  " << memtrix[increm] <<endl;
			 increm++;
	  }//END while parser

	fin.close();
	fou.close();
}//END main
