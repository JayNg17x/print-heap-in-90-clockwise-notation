#include <iostream>
#include <cstdlib>
#include<unordered_set>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;

// Find duplicate element in an array using unordered_set
void findDup(int a[], int n) {
	unordered_set<int > set;
	unordered_set<int > dup;

	for(int i = 0; i < n; ++i) {
		// If element is not there, then insert that
		if(set.find(a[i]) == set.end()) {
			set.insert(a[i]);
		} else {
			dup.insert(a[i]);
		}
	}

	// Print the result
	unordered_set<int>:: iterator i;
	cout << "Found duplicate elements are: \n";
	for(i = dup.begin(); i != dup.end(); ++i) {
		cout << *i << " " << endl;
	}
}

int main() {
	cout << "Hello world!\n";

	int a[] = {1,1,2,3,2,3,4};
	int size_a = sizeof(a)/sizeof(a[0]);
	findDup(a, size_a);

	unordered_set<string> str;

	str.insert("toi");
	str.insert("di");
	str.insert("code");
	str.insert("dao");

	string key = "senior";

	// Find string key in set
	if(str.find(key) == str.end()) {
		cout << "key " << key << " not found!\n"; 
	} else {
		cout << "Found " << key << endl;
	}

	key = "code";

	// Find string key in set
	if(str.find(key) == str.end()) {
		cout << "key " << key << " not found!\n";
	} else {
		cout << "Found " << key << endl;
	}

	// Iterating over set and print its content
	cout << "All elements: \n";
	unordered_set<string> :: iterator i;
	for(i = str.begin(); i != str.end(); ++i) {
		cout << *i << " " << endl;
	}

	// Erase string key from set
	if(str.find("haha") == str.end()) {
		cout << "haha" << " not found\n"; 
	} else {
		cout << "haha" << " found!";
		str.erase("haha");
	}

	if(str.find("code") == str.end()) {
		cout << "code " << " is found\n";
		str.erase("code");
	} else {
		cout << "code " << " is not found\n";
	}

	if(str.find("code") == str.end()) {
		cout << "code " << "is not erased yet!";
	} else {
		cout << "code " << "is erased!";
	}

	// count particular element in set
	int count = str.count("di");
	cout << count << endl;


	for(i = str.cbegin(); i != str.cend(); ++i) {
		cout << *i << " " << endl;
	}




	return 0;
}