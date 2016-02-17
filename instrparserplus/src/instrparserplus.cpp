//============================================================================
// Name        	: instrparserplus.cpp
// Author      	: Antonin Karlo M. Tilaon
// Course Info 	: COSC 3355 Assgnment I
//Instructor	: Dr. Stephen Rainwater
// Description 	: Instruction Parser
// Accreditation: The assignment template almost gave the answer
//				: I was able to piece together the general idea of the
//              : assignment due to the template given in java.
//				: Sources online made me aware,
//				: of c++ functions that could parse the data inside a text file
//				: stackoverflow.com cplusplus.com
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

	static int PC;	//Program Counter
	int instr;
	int instr_type;
	int counter;	//instruction counter
	//declare arrays inside class
	static int memory[];
	static int registers[];
	bool run_bit;

public:void interpret(int (&memory)[1000], int starting_address){
		//initialize counter to zero whenever interpret is called
		counter = 0;
		//variable that determines if the program will run
		run_bit = true;
		PC = starting_address;
		while(run_bit){
			//set a current memory command as current instruction
			instr = memory[PC];
			if (instr == 100)
				run_bit = false;
			cout <<"Instruction No : "<<counter<<endl;
			cout <<"instruction : " << memory[PC] <<" PC : "<<PC<< endl;
			PC++; //Program Counter Increment
			instr_type = get_instr_type(instr);
			execute(instr_type, instr);
			for(int i=0;i<10;i++){
						cout<<"Register "<<i<<" : ";
						cout<<setfill('0')<<setw(3);
						cout<<registers[i]<<endl;
			}//END for
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
		opcode = addr /100;
		cout <<"Opcode : "<< opcode;
	return opcode;
	}//END method get_instr_type


	public: void execute(int type, int data){
		static int dten;		//2nd-digit int holder
		static int sone;		//3rd-digit int holder
		//static int regS,regSType,regSdten,regSone;
		dten = (data/10)%10;
		sone = data%10;
		cout<<" D : "<<dten;
		cout<<" N/S : "<<sone<<endl;
		switch(type){
				case 0:
					//**if I want to check each digit of Register S
					//regS = registers[sone];	//Register S value
					//regSType = regS /100;	//Opcode digit
					//regSdten = (regS/10)%10;//2nd digit
					//regSone = regS%10;		//3rd digit
					//unless register s contains 0
					//if(regSType!=0)&&(regSdten!=0)&&(regSone!=0)
					//**if I want to check each digit of Register S
					if(registers[sone]!=0)
						//go to the location in register d
						PC = registers[dten];
					break;
				case 2:
					//means set register d to the value n
					registers[dten]=sone;
					break;
				case 3:
					//means multiply register d by the value n
					registers[dten]=(registers[dten] * sone)%1000;
					break;
				case 4:
					registers[dten]=(registers[dten]+sone)%1000;
					break;
				case 5:
					registers[dten]=registers[sone];
					break;
				case 6:
					registers[dten]=(registers[dten] * registers[sone])%1000;
					break;
				case 7:
					registers[dten]=(registers[dten] + registers[sone])%1000;
					break;
				case 8:
					registers[dten] = memory[registers[sone]];
					break;
				case 9:
					memory[registers[sone]] = registers[dten];
					break;
				default:
					//Do nothing to the registers
					cout <<"catch opcode 1"<<endl;
				}//END switch
		counter++;
	}//END method execute
};//END class Interp

//defining Arrays
int Interp::memory[1000];
int Interp::registers[10];
int Interp::PC=0;

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
