#include <string>
#include <stdlib.h>
#include <bitset>
#include <iostream>
#include <random>

#include "bitString.cpp"

//notes
//currently takes text as input, uses bitString as private data structure

class OneTimePadGenerator{
	private:
		bitString message, Key, ciphertext;

	public:
		OneTimePadGenerator(){
			message = bitString();
			Key = bitString();
			ciphertext = bitString();
		}
		OneTimePadGenerator(std::string m, std::string k){
			setKey(k);
			setMessage(m);
		}
		void setKey(std::string key){
			Key.parseText(key);
		//	Key = bits.substr(0, message.size()*8);
		}
		void setMessage(std::string m){
			message.parseText(m);
		}
		std::string getCiphertext(){
			return ciphertext.getString();
		}
		std::string getKey(){
			return Key.getString();
		}
		std::string getMessage(){
			return message.getString();
		}
//	private:
		void generateCiphertext(){
			bitString key, m = Key, message;
			ciphertext = m.exor(key);
		}

	//old code, now in bitString class for implementation in other code
//	public: std::string bitify(std::string m){
	//		std::string messagebits;
	//		for (std::size_t i = 0; i < m.size(); ++i){
	//			std::bitset<8> charBits(m[i]);
	//			messagebits += charBits.to_string();
	//		}
	//		return messagebits;
	//	}
	//	public: std::string stringify(std::string m){
	//		std::string message;
	//		for (std::size_t i = 0; i < m.size()/8; ++i){
	//			std::bitset<8> letterbits(m.substr(i*8,i*8+8));
	//			message += letterbits.to_ulong();
	//		}
	//		return message;
	//	}
	//	public: std::string exor(std::string instring){
	//		std::string inbits = bitify(instring);
	//		std::string outbits = "";
	//		for (std::size_t i = 0; i < message.size()*8; ++i){
	//			if (inbits[i] == Key[i]){
	//				outbits += "0";
	//			}
	//			else{
	//				outbits += "1";
	//			}
	//		}
	//		return stringify(outbits);
	//	}
};
