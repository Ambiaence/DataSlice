#include <iostream>

int main() {
	__int32_t whole = 0x01020304;  
	//Variable method - Not dynamic
	unsigned char a = (whole & 0xFF000000) >> 24;
	unsigned char b = (whole & 0x00FF0000) >> 16;
	unsigned char c = (whole & 0x0000FF00) >> 8;
	unsigned char d = (whole & 0x000000FF);

	//With pointers - Dynamic.
	unsigned char* aP = ((unsigned char*) &whole) + 3;
	unsigned char* bP = ((unsigned char*) &whole) + 2;
	unsigned char* cP = ((unsigned char*) &whole) + 1;
	unsigned char* dP = (unsigned char*) &whole + 0;

	//error: cannot bind non-const lvalue reference of type ‘unsigned char&’ to a value of type ‘__int32_t’ {aka ‘int’}
	//unsigned char& aRef = whole;
	//unsigned char& bRef = whole;
	//unsigned char& cRef = whole;
	//unsigned char& dRef = whole;

	std::cout << "First with variables" << '\n';
	std::cout << "Whole: " << whole << '\n';
	std::cout << "A Variable: " << (int) a << '\n';
	std::cout << "B Variable: " << (int) b << '\n';
	std::cout << "C Variable: " << (int) c << '\n';
	std::cout << "D Variable: " << (int) d << "\n\n";

	std::cout << "Now with pointers" << '\n';
	std::cout << "A Pointer: " << (int) *aP << '\n';
	std::cout << "B Pointer: " << (int) *bP << '\n';
	std::cout << "C Pointer: " << (int) *cP << '\n';
	std::cout << "D Pointer: " << (int) *dP << '\n';
}
