#include<iostream>
#include <cstdlib>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<string>

using namespace std;

#define M 4
#define N 4

int row[] = {-1,-1,-1,0,1,0,1,1};
int col[] = {-1,1,0,-1,-1,1,0,1};

/* The function check if it is safe to go to the cell (x, y) from current cell.
   The function returns false if (x, y) is not valid matrix coordinates
   or cell(x, y) is already processed.
   */

// The time complexity of this algorithm is exponential

bool isSafe(int x, int y, bool processed[][N]) {

	return (x >= 0 && x < M) && (y >= 0 && y < N) && !processed[x][y];
}

// A recursive function to generate all possible words in a boggle 
void searchBoggle(char board[][N], unordered_set<string> &words, bool processed[][N], int i, int j, string path) {

	// Mark the current node as processed
	processed[i][j] = true;

	// Update the path with currnent character and insert it into set
	path += board[i][j];
	words.insert(path);

	// Check for all 8 possible movements from the current cell
	for(int k = 0; k < 8; ++k) {
		// Skip if the cell is invalid or it is already processed
		if(isSafe(i + row[k], j + col[k], processed)) {
			searchBoggle(board, words, processed, i + row[k], j + col[k], path);
		}
	}

	// Mark current not as unprocessed 
	processed[i][j] = false;
}

// Function to search for given set of words in a boggle 
void searchBoggle(char board[][N], vector<string> &input) {

	// Construct boolean matrix to store whether a cell is processed or not 
	bool processed[M][N] = {};

	// Construct a set to store all possible words constructed from the matrix  
	unordered_set<string> words;

	// Generate all possible words in a boggle 
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < N; ++j) {
			// Consider each character as a starting point and run DFS
			searchBoggle(board, words, processed, i, j, " ");
		}
	}

	// For each word in the input list, check whether it is present in the set 
	for(string word : input) {
		if(words.find(word) != words.end()) {
			cout << word << " " << endl;
		}
	}
}

// Another solution using Trie data structure 

struct Trie {
	// True when node is leaf node
	bool isLeaf;

	unordered_map<char, Trie*> character;

	// Trie constructor 
	Trie() {
		isLeaf = false;
	}
};

// Iterative function to insert a string into a Trie
void insert(Trie* root, string &str) {
	// Start from the root node
	Trie* currNode = root;

	for(char ch : str) {
		// Create a new node is path does not exits 
		if(currNode->character.find(ch) == currNode->character.end()) {
			currNode->character[ch] = new Trie();
		}
		// Go to the next node
		currNode = currNode->character[ch];
	}

	currNode->isLeaf = true;
}

int row[] = {-1,-1,-1,0,1,0,1,1};
int col[] = {-1,1,0,-1,-1,1,0,1};

bool isSafe(char board[][N], bool processed[][N], int x, int y, char ch) {
	return (x >= 0 && x < M) && (y >= 0 && y < N) && !processed[x][y] && board[x][y] = false;
}

void searchBoggle(Trie* root, char board[][N], int i, int j, bool processed[][N], string path, unordered_set<string> &result) {
	// If lead node is encountered 
	if(root->isLeaf) {
		result.insert(path);
	}

	// Mark the curent cell is true
	processed[i][j] = true;

	// Traverse all the child of the current Trie node 
	for(auto it : root->character) {
		// Check for all 8 possible movements from the current cell
		for(int k = 0; k < 8; ++k) {
			// Skip if the cell is invalid or it is already processed 
			// Or does not lead to any path in the Trie
			if(isSafe(board, processed, x + row[k], j + col[k], it.first)) {
				searchBoggle(it.second, board, i + row[k], j + col[k], processed, path + it.first, result);
			}
		}
	}
	processed[i][j] = false;
} 

void searchBoggle(char board[][N], vector<string> words) {
	// Insert all words into a trie
	Trie* root = new Trie();
	for(string word : words) {
		insert(root, word);
	}

	// Construct a set for storing the result 
	unordered_set<string> result;

	// Construct a boolean matrix to store whether a cell is processed or not 
	bool processed[M][N] = {};

	string str;

	// Consider each character in the matrix 
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < N; ++j) {
			// Current character 
			char ch = board[i][j];
			// Proceed only if character is the child of the trie root node 
			if(root->character[ch]) {
				str = ch;
				searchBoggle(root->character[ch], board, i, j, processed, str, result);
			}
		}
	}

	// Print all word result 
	for(string word : reuslt) {
		cout << word << endl;
	}
}


int main() {
	cout << "Hello world!\n";

	char board[M][N] = {
					{'M','S','E','F'},
					{'R','A','T','D'},
					{'L','O','N','E'} };

	vector<string> words;
	words.push_back("START");
	words.push_back("NOTE");
	words.push_back("SAND");
	words.push_back("STONED");
	cout << words.size();

	searchBoggle(board, words);

	return 0;
}