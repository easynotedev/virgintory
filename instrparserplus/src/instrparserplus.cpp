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

//Input and Output pointer and creation
ifstream fin("input.txt");
ofstream fou("output.txt");

class Interp{

	int PC;
	static int registers[10];
	int instr;
	int instr_type;
	static int memory[1000];
	int instructionCounter;
	bool run_bit = true;

/*
 *1for (int iii=0;iii<90; iii++)
2{
3anArray[iii] = txtstream.readline(); //reads one line and writes it to the array
4}
 *
 */

public:void interpret(int memory[], int starting_address){

		PC = starting_address;
		while(run_bit){
			instr = memory[PC];		//fetch next instruction into instr
			for(int i=0;i<10;i++){	//sticks Memory data to registers
									//10 at a time
			}//END loop
			PC++;		//increment program counter
			instr_type = get_instr_type(instr);		//determine instruction type
			if(instr == 100){
				run_bit = false;
			}//END if
			fou <<"Register "<<PC<<": "<<instr << endl;
			//execute(1,1); //execute instruction*/
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
			 fou << "Memory "<<increm<<": " << memtrix[increm] <<endl;
			 increm++;
	  }//END while parser
	Interp quadcore;
	quadcore.interpret(memtrix,0);

	fin.close();
	fou.close();
}//END main
