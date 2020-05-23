/* Algorithm course 
   Home work 1
   Solve Einsteins problem using backtracking */

/*
	Facts:
	• There are 5 houses (along the street) in 5 different colors:
	blue, green, red, white and yellow.
	• In each house lives a person of a different nationality:
	Brit, Dane, German, Norwegian and Swede.
	• These 5 owners drink a certain of beverage:
	beer, coffee, milk, tea and water,
	• These 5 owners smoke a certain brand of cigar:
	Blue Master, Dunhill, Pall Mall, Prince and Blend,
	• These 5 owners keep a certain pet:
	cat, bird, dog, fish and horse.
	• No owners have the same pet, smoke the same brand of cigar, or drink the
	same beverage.
*/

/*
Hints:
• The Brit lives in a red house.
• The Swede keeps dogs as pets.
• The Dane drinks tea.
• The green house is on the left of the white house (next to it).
• The green house owner drinks coffee.
• The person who smokes Pall Mall rears birds.
• The owner of the yellow house smokes Dunhill.
• The man living in the house right in the center drinks milk.
• The Norwegian lives in the first house.
• The man who smokes Blend lives next to the one who keeps cats.
• The man who keeps horses lives next to the man who smokes Dunhill
• The owner who smokes Blue Master drinks beer.
• The German smokes Prince.
• The Norwegian lives next to the blue house.
• The man who smokes Blend has a neighbor who drinks water.
*/

#include<iostream>
#include<cstdlib>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;
#define N 5

// const char* items[M][N] = { 
// 							{"house1","house2","house3","house4","house5"},
// 							{"yellow","blue","red","green","white"},
// 							{"nor","dane","brit","ger","swe"},
// 							{"blueM","dunH","pallM","prince", "blend"},
// 							{"beer","coffee","water","milk","tea"},
// 							{"cat","bird","dog","fish","horses"} };

const string colour[N] = {"yellow", "blue", "red", "green", "white"};
const string nationality[N] = {"Norwegian", "Dane", "Brit", "German", "Swede"};
const string smokes[N] = {"blueMaster", "dunHill", "pallMall", "prince", "blend"};
const string drink[N] = {"beer", "coffee", "water", "milk", "tea"};
const string pet[N] = {"cat", "bird", "dog", "fish", "horses"};
int i;
int houses;
const string criteria = colour[i] + nationality[i] + smokes[i] + drink[i] + pet[i];	
const string constraints[15][2] = {{"Brit", "red"},
								{"Swede", "dog"},
								{"Dane", "tea"},
								{"green", "white"},
								{"green", "coffee"},
								{"pallMall", "bird"},
								{"yellow", "dunHill"}, 
								{"milk"}, 
								{"Norwegian"}, 
								{"blend", "cat"},
								{"horses", "dunHill"},
								{"blueMaster", "beer"},
								{"German", "prince"}, 
								{"Norwegian", "blue"},
								{"blend", "water"}};
/*
	string path = " ";
	unordered_map<string, int> hints;
	hints.insert(make_pair(""))

	
	bool isProcessed() {
		for(int i = 0; i < N; ++i) 
			if(criteria = colour[i] + ....) 
				return true;
		return false;
	}

	bool isMatchWithHints() {
		
	}

	bool isReceived(string hints[], string &item)
		for(int i = 0; i < color.length; ++i) 
			for(int j = 0; j < hints.length; ++j) 
				if(color[i] == hints[j]) 
					return false;

		for(int i = 0; i < nationality.length; ++i) 
			for(int j = 0; j < hints.length; ++j) 
				if(nationality[i] == hints[j])
					return false;

		for(int i = 0; i < smokes.length; ++i) 
			for(int j = 0; j < hints.length; ++j)
				if(smokes[i] == hints[j])
					return false;

		for(int i = 0; i < drink.length; ++i) 
			for(int j = 0; j < hints.length; ++j)
				if(drink[i] == hints[j])
					return false;

		for(int i = 0; i < pet.length; ++i) 
			for(int j = 0; j < hints.length; ++j)
				if(pet[i] == hints[j]) 
					return false;

	return true;

	bool solve()


	isSafe() 

		for(int i = 0; i < N; ++i) 
			return critria = colour[i] + nationality[i] + pet[i] + drink[i] + smokes[i] && 
				for(int j = 0; j < hints.size(); ++j) 
					if(colour[i] == hints[j] && nationality[i] == hints[j] && smokes[i] == hints[j] && drink[i] == hints[j] && pet[i] == hitns[j]) 
						retur false;
			return critria = colour[i] + nationality[i] + pet[i] + drink[i] + smokes[i];
	


	solve(vector<string> hints) {
		
	}



*/ 
struct Trie {
	bool isLeaf;
	unordered_map<string, Trie*> item;

	Trie() {
		isLeaf = false;
	}
};

void insert(Trie* &root, vector<string> hints) {
	Trie* currNode = root;

	for(auto it = hints.begin(); it != hints.end(); ++it) {
		if(currNode->item.find(*it) == currNode->item.end()) {
			currNode->item[*it] = new Trie();
		}

		currNode = currNode->item[*it];
	}
	currNode->isLeaf = true;
}

bool isProcessed(const string colour[], const string nationality[], const string smokes[], const string drink[], const string pet[]) {
	const string criteria = "";
	for(int i = 0; i < N; ++i)
		return criteria == colour[i] + nationality[i] + pet[i] + drink[i] + smokes[i];
}


bool isSafe(int k, vector<string> &hints) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < hints.size(); ++j) {
		 	return colour[i] == hints[j] && nationality[i] == hints[j] && smokes[i] == hints[j] && drink[i] == hints[j] && pet[i] == hints[j];
					
		}
	}
}

bool isSafe(vector<string> &hints) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < hints.size(); ++j) {
			if(colour[i] == hints[j])
				return false;
		}
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < hints.size(); ++j) {
			if(nationality[i] == hints[j])
				return false;
		}
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < hints.size(); ++j) {
			if(smokes[i] == hints[j])
				return false;
		}
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < hints.size(); ++j) {
			if(drink[i] == hints[j])
				return false;
		}
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < hints.size(); ++j) {
			if(pet[i] == hints[j])
				return false;
		}
	}

	return true;
}

void solve() {

}



int main() {
	cout << "Hello world!\n";



	return 0;
} 