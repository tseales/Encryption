#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


void Encryption() {								//Encryption Function
	int matrix[4][4] = {};						//4x4 Matrix for encryption
	cout << "Enter text to be converted to be encrypted: ";
	string input = "";
	cin >> input;
	ifstream infile;
	int c;
	infile.open("Encrypt.txt");					//opens file
	int countRow = 0;							//fills in matrix w/ contents from encryption text file (while loop and if statement)
	int countColumn = 0;
	while (infile >> c) {
		matrix[countRow][countColumn] = c;
		countColumn++;
		if (countColumn >= 4) {
			countRow++;
			countColumn = 0;						
		}
	}
	infile.close();								//closes file
	vector<char> encrypted;						//keeps track of all encrypted characters
	vector<char> cinput(input.begin(), input.end());			//converts input into a character vector
	for (int in = 0; in < cinput.size(); in+=4) {				//loops through character vector in groups of 4
		int mult[4] = {};										//array that holds the encryption values 
		int arr[4] = {};										//array holds 4 characters from cinput to be encrypted
		for (int a = 0; a < 4; a++) {							//converts letters to respective numbers (a=1,b=2,etc.) and stores in arr
			if (a + in < cinput.size()) {
				arr[a] = cinput.at(a + in);
				arr[a] = arr[a] - 'A' + 1;
			}
			//cout << arr[a] << " a ";
		}
		//cout << endl;
		for (int i = 0; i < 4; ++i) {							//multiplies the contents of the matrix and array using matrix multiplication
				for (int k = 0; k < 4; ++k){
					mult[i] += matrix[i][k] * arr[k];
				}
		}
		
		for (int i = 0; i < 4; ++i) {							//after multiplication, stores encrypted values in encrypted string
			int d = mult[i];
			//cout << d << " b ";
			encrypted.push_back(mult[i]+33);					//add 33 to number to give values a base number to start at on ASCII table 
		}
		//cout << endl;
	}

	string str(encrypted.begin(), encrypted.end());				//converts encrypted vector into a string
	cout << str << endl;
}
void Decryption() {												//decryption function
	int matrix[4][4] = {};
	cout << "Enter text to be converted to be decrypted: ";
	string input = "";
	cin >> input;
	ifstream infile;
	int c;
	infile.open("Decrypt.txt");
	int countRow = 0;
	int countColumn = 0;
	while (infile >> c) {
		matrix[countRow][countColumn] = c;
		countColumn++;
		if (countColumn >= 4) {
			countRow++;
			countColumn = 0;
		}
	}
	infile.close();
	vector<char> decrypted;
	vector<char> cinput(input.begin(), input.end());
	for (int in = 0; in < cinput.size(); in += 4) {						//for loop that subtracts by 33 
		int mult[4] = {};
		int arr[4] = {};
		for (int a = 0; a < 4; a++) {		
			if (a + in < cinput.size()) {
				arr[a] = cinput.at(a + in);
				arr[a] = arr[a] - 33;
			}
			//cout << arr[a] << " a ";
		}
		//cout << endl;	
		for (int i = 0; i < 4; ++i) {									//goes back through matrix multiplication to get original assigned numbers of character values (added by 1)
			for (int k = 0; k < 4; ++k) {
				mult[i] += matrix[i][k] * arr[k];
			}
		}

		for (int i = 0; i < 4; ++i) {									//subtracts by 1 to get original character values
			char b = mult[i] + 'A' - 1;
			//cout << b << " b ";
			if (b == '@') {												//if @ comes up then it translates to a space (because if string size is less than 1 it won't translate since base is 1)
				decrypted.push_back(' ');
			}
			else
			decrypted.push_back(b);
		}
		//cout << endl;
	}

	string str(decrypted.begin(), decrypted.end());						//changes character vector to string
	cout << str << endl;
}	

int main()
{
	Encryption();
	Decryption();
	/*
	string sInputtext;
	cout << "Enter a text to be converted to be ecrypted: ";
	getline(cin, sInputtext);
	cin >> sInputtext;
	ASCIIconversion(sInputtext);
	*/
	return 0;
}