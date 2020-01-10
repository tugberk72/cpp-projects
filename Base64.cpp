#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main() {

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	int value = 0;
	string text;
	string binary = "";
	string temp = "";
	string output = "";

	cout << "Text: \n";
	getline(cin, text);
	int x = text.length();
	for (int i = 0; i < x; i++) {
		int k = (int)text[i];
		bitset<8> out(k);
		binary += out.to_string();
	} 
	cout << binary;

	// Turns the input into Binary

	cout << "\n\n";
	int xbin = binary.length();
	string last = "";
	if (xbin % 6 == 4) {
		last += "=";
		binary += "00";
		xbin += 2;
	}
	else if (xbin % 6 == 2) {
		last += "==";
		binary += "0000";
		xbin += 4;
	}

	// Makes sure that the digits are dividable by 6

	for (int j = 0; j < xbin; j++) {
		temp += binary[j];
		if (temp.length() == 6) {
			if (temp[0] == '1') { value += 32; };
			if (temp[1] == '1') { value += 16; };
			if (temp[2] == '1') { value += 8; };
			if (temp[3] == '1') { value += 4; };
			if (temp[4] == '1') { value += 2; };
			if (temp[5] == '1') { value += 1; };
			output += alphabet[value];
			temp = "";
			value = 0;
		}
	}

	// Binary to Base64

	output += last;
	cout << output;
	return 0;
}
