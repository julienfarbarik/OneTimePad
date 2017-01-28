//============================================================================
// Name        : hello_world.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//if issues with c++11
// http://stackoverflow.com/questions/17457069/enabling-c11-in-eclipse-juno-kepler-luna-cdt



#include "otp_generator.h"


int main() {

	std::string MESSAGE = "Make an application that reads off a book or something for the key.";
	std::string KEY = "B:KIOWO:EIFL?KLLKSDLKp'oo;weaaeri;ghaerg;ioO:;abeo;a;ioiohaewfo;;O:SOIGHEGno;eo;rbs;eio";

//	OTPGEN test


//
//	OneTimePadGenerator og = OneTimePadGenerator(MESSAGE, KEY);
//	og.generateCiphertext();
//	std::cout<<og.getCiphertext()<<std::endl;


//	bitString test

	bitString bs1 = bitString();
	bs1.parseText(MESSAGE);
	bitString bs2 = bitString();
	bs2.parseText(KEY);
	std::cout<< bs1.getString()<<std::endl;
	std::cout<< bs2.getString()<<std::endl;
	std::cout<< bs1.exor(bs2).getString()<<std::endl;
//	std::cout<< bs1.getString()<<std::endl;
//	std::cout<< bs2.getString()<<std::endl;

	return 0;
}
