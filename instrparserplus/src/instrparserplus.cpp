//============================================================================
// Name        	: instrparserplus.cpp
// Author      	: Antonin Karlo M. Tilaon
// Course Info 	: Dr. Rainwater / COSC 3355 Assgnment I
// Description 	: Instruction Parser
// Accreditation: The assignment template almost gave the answer
//				: I was able to piece together the general idea of the
//                assignment
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
#include<iomanip>
using std::setw;
using std::setfill;

//Input and Output pointer and creation
ifstream fin("input.txt");
ofstream fou("output.txt");

class Interp{

	int PC;
	int instr;
	int instr_type;
	int counter;	//instruction counter
	//declare arrays inside class
	static int memory[];
	static int registers[];
	bool run_bit;

public:void interpret(int (&memory)[1000], int starting_address){
		counter = 0;
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
			fou<<"Register "<<i<<" : ";
			fou<<setfill('0')<<setw(3);
			fou<<registers[i]<<endl;
		}//END for
		fou <<"Number of instructions executed: "<<counter<<endl;
}//END method interpret


	private:static int get_instr_type(int addr){
		static int opcode;
		static int i;
		opcode = addr /100;
		cout <<"Opcode "<<i++<<" : "<< opcode << endl;
	return opcode;
	}//END method get_instr_type


	public: void execute(int type, int data){
		static int dten;
		static int sone;
		dten = (data/10)%10;
		sone = data%10;
		switch(type){
				case 0:
					static int regS=registers[sone];
					static int regSType,regSten,regSone;
					regSType=regS/100;
					regSten=(regS/10)%10;
					regSone=regS%10;
					if(regSType==0||regSten==0||regSone==0){
						//register contains zero
					}
					else{
						//means go to the location in register d
						fou <<"go to the location in register d"<<endl;
						//**
					}//END if-else
					break;
				case 2:
					registers[dten]=sone;
					break;
				case 3:
					registers[dten]=(registers[dten] * sone)%1000;
					break;
				case 4:
					registers[dten]=(registers[sone]+registers[dten])%1000;
					break;
				case 5:
					registers[dten]=registers[sone];
					break;
				case 6:
					registers[dten]=(registers[dten] * registers[sone])%1000;
					break;
				case 7:
					registers[dten]=(registers[dten]+registers[sone])%1000;
					break;
				case 8:
					registers[dten] = memory[registers[sone]];
					break;
				case 9:
					memory[registers[sone]] = registers[dten];
					break;
				default:
					cout <<"error output"<<endl;
				}//END switch
		counter++;
	}//END method execute
};//END class Interp

//defining Arrays
int Interp::memory[1000];
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
