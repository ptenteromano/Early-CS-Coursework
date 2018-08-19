/* Philip Tenteromano 2/17/2017
 *
 *  Program class function definitions using program.h header
 *
 */

#include <iostream>
#include <string>

using namespace std;

#include "program.h"


//private helper to validate campus
void Program::checkCampus(string camp)
{
	while(camp != "RH" && camp != "LC" && camp != "WC") {
		
		cout<<"Input a campus (must be RH, LC, or WC): ";
		cin>>camp;
	}

	campus = camp;
}

//private helper to validate degree type
void Program::checkDegree(string degr) 
{
	while(degr != "BS" && degr != "BA") {

		cout<<"Input a degree type (must be BA or BS): ";
		cin>>degr;
	}
	
	degree = degr;
}


//default constructor defines data members
Program::Program()
{
	campus = "RH";
	degree = "BA";
	major = "Undeclared";
	minor = "None";
}

//specified constructor using only campus
Program::Program(string campus)
{
	checkCampus(campus);
	degree = "BA";
	major = "Undeclared";
	minor = "None";
}


void Program::setProgram()
{
	cout<<"Input a campus (must be RH, LC, or WC): ";
       	cin>>campus;	
	checkCampus(campus);

	cout<<"Input a degree (must be BA or BS): ";
	cin>>degree;
	checkDegree(degree);

	cout<<"Input a major or type undeclared: ";
	cin>>major;
	
	cout<<"Input a minor, or none: ";
	cin>>minor;
}

void Program::setCampus(string camp)
{
	checkCampus(camp);
}

void Program::setDegree(string degr)
{
	checkDegree(degr);
}

void Program::setMajor(string maj)
{
	major = maj;
}

void Program::setMinor(string min)
{
	minor = min;
}

void Program::print()
{
	cout<<"Your major is "<<major<<" with a minor in "<<minor<<"."<<endl;
	cout<<"The degree type is a "<<degree<<", studying at the "<<campus<<" campus."<<endl;
	cout<<endl;
}
