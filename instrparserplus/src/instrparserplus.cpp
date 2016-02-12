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
	int instr;
	int instr_type;
	//declare arrays inside class
	static int memory[];
	static int registers[];
	int instructionCounter;
	bool run_bit;

public:void interpret(int memory[], int starting_address){
		run_bit = true;
		PC = starting_address;
		while(run_bit){
			instr = memory[PC];
			cout <<"instruction : " << memory[PC] << endl;
			instr_type = get_instr_type(instr);
			execute(instr_type, instr);
		    if (instr == 100)
		    	 run_bit = false;
		    PC++;
		}//END while run_bit is true		//Check registers
		for(int i=0;i<10;i++){
			fou <<"Registers "<<i<<": "<<registers[i] << endl;
		}
}//END method interpret


	private:static int get_instr_type(int addr){
		static int opcode;
		static int i;
		opcode = addr /100;
		cout <<"Opcode "<<i++<<" : "<< opcode << endl;
	return opcode;
	}//END method get_instr_type

	private:static void execute(int type, int data){
		static int counter;
		static int dten;
		static int sone;
		dten = (data/10)%10;
		sone = data%10;
		switch(type){
				/*case 0:
					break;
				case 1:
				*/	break;
				case 2:
					cout <<"dten : "<< dten <<" sone : "<<sone<< endl;
					registers[dten] = sone;
					break;
				/*case '3':
					registers[dten]=(registers[dten] * sone)%1000;
					break;
				case '4':
					registers[dten]=(registers[sone]+registers[dten])%1000;
					break;
				case '5':
					registers[dten]=registers[sone];
					break;
				case '6':
					registers[dten]=(registers[dten] * registers[sone])%1000;
					break;
				case '7':
					registers[dten]=(registers[dten]+registers[sone])%1000;
					break;
				case '8':
					registers[dten] = memory[registers[sone]];
					break;
				case '9':
					memory[registers[sone]] = registers[dten];
					break;
				*/
				default:
					registers[counter] = data;
					cout<<"WHAT? "<<counter<<" : " << registers[counter] << endl;
					break;
				}//END switch
		counter++;
	}//END method execute
};//END class Interp

//defining Array registers
int Interp::registers[10];

int main()
{
	//create/initialize memory
	int memtrix[1000]={0}, instrno=0, increm=0;
	string line; //buffer string
	ifstream fin("input.txt"); // create input file stream
	ofstream fou("output.txt");// create output file stream
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
			 increm++;
	  }//END while parser

	Interp quadcore;
	quadcore.interpret(memtrix,0);

	fin.close();
	fou.close();
}//END main
