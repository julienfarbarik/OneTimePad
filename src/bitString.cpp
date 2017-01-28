#include <string>
#include <bitset>
#include <stdexcept>
#include <iostream>
#include <type_traits>
#include <math.h>

//notes
//figure out how to get rid of/manage new


class bitString{
	private:
		std::string String, StringBits;

	public:
//constructors
		bitString(){
			String = "";
			StringBits = "";
		}
		bitString(const bitString& b){
			*this = b;
		}
		bitString(std::string s){
			*this = s;
		}
//getters/setters
		std::string parseText(std::string s){
			String = s;
			StringBits = StringToBits(s);
			return StringBits;
		}
		std::string getString(){
			return String;
		}
		std::string getBits(){
			return StringBits;
		}
//other
		int size(){
			return StringBits.size();
		}
		int stringsize(){
			return String.size();
		}

		std::string StringToBits(std::string s){
			std::string stringbits;
			for (std::size_t i = 0; i < s.size(); ++i){
				std::bitset<8> charBits(s[i]);
				stringbits += charBits.to_string();
			}
			return stringbits;
		}
		std::string BitsToString(std::string s){
			std::string string;
			for (std::size_t i = 0; i < s.size()/8; ++i){
				std::bitset<8> letterbits(s.substr(i*8,i*8+8));
				string += letterbits.to_ulong();
			}
			return string;
		}

		//MAKE SO ONLY SHIFTS B
		bitString exor(bitString b){
			//uncomment if bit lengths must be equal, comment out next two ifs
//			if (String.size() != b.getString().size()){
//				throw std::invalid_argument("mismatched binary sizes");
//				return *this;
//			}
			int dif = size()-b.size();
			if (dif>0){
				b.shiftRight(dif);
			}
			else if (dif<0){
				shiftRight(0-dif);
			}
			std::string inbits = b.getBits();
			std::string outbits = "";
			for (std::size_t i = 0; i < inbits.size(); ++i){
				if (inbits[i] == StringBits[i]){
					outbits += "0";
				}
				else{
					outbits += "1";
				}
			}
			*this = bitString(outbits);
			if (dif < 0){
				shiftLeft(dif);
			}
			return *this;
		}
//modifiers
		bitString shiftRight(int n){
			std::string zeros = "";
//			std::cout<<StringBits<<std::endl;
			for (int i = 0; i < n; ++i){
				zeros += "0";
			}
			StringBits = zeros + StringBits;
			String = BitsToString(StringBits);
			return *this;
		}
		bitString shiftLeft(int n){
			StringBits = StringBits.substr(n, StringBits.size());
			String = BitsToString(StringBits);
			return *this;
		}
		bitString shift(int n){
			if (n>0){
				return shiftRight(n);
			}
			else{
				return shiftLeft(n);
			}
		}

		//OVERLOADED OPERATORS
		bitString & operator= (const bitString* b){
			if (this==b){
				return *this;
			}
			else{
				String = b->String;
				StringBits = b->StringBits;
			}
			return *this;
		}
		bitString & operator= (std::string s){
			this->StringBits = s;
			this->String = BitsToString(s);
			return *this;
		}
		bitString & operator+ (const bitString* b){
			bitString* bs = new bitString();
			bs->parseText(StringBits + b->StringBits);
			return *bs;
		}
		bitString & operator+= (bitString b){
			StringBits += b.getBits();
			String += b.getString();
			return *this;
		}

};








