#include <iostream>
#include<fstream>
#include<cstdlib>

using namespace std;


int main() {
	cout << "Hello world!\n";

	ifstream fileIn;

	fileIn.open("input.odt", ios_base::in);


	int a[9][9];
	int n;
	fileIn >> n;

	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < 9; ++i) {
			for(int j = 0; j < 9; ++j) {
				fileIn >> a[i][j];
			}
			cout << endl;
		}
	}

	fileIn.close();


	return 0;
}