#include <iostream>
#include <random>

#include "bitString.cpp"

//notes
//currently takes text as input, uses bitString as private data structure

class OneTimePadReader{
	private:
		bitString message, Key, ciphertext;

	public:
		OneTimePadReader(){
			message = bitString();
			Key = bitString();
			ciphertext = bitString();
		}
		OneTimePadReader(std::string c, std::string k){
			setKey(k);
			setCiphertext(c);
		}
		void setKey(std::string key){
			Key.parseText(key);
		//	Key = bits.substr(0, message.size()*8);
		}
		void setCiphertext(std::string m){
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
		void decryptCiphertext(){
			message = ciphertext.exor(Key);
		}
};
