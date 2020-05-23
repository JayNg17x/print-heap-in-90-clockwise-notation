#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;


void knapsackDP(int W[], int V[], int n, int M) {
	
	int table[n+1][M+1];
	int i, j;

	for(j = 0; j <= M; ++j) {
		table[0][j] = 0;
	}

	for(i = 1; i <= n; ++i) {
		for(j = 0; j <= M; ++j) {
			table[i][j] = table[i-1][j];

			if((j >= W[i - 1]) && (table[i][j] < table[i - 1][j - W[i - 1]] + V[i - 1])) {
				table[i][j] = table[i - 1][j - W[i - 1]] + V[i - 1];
			}
			cout << table[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nMax value: " << table[n][M];
	cout << "\nSelected packs: ";

	while(n != 0) {
		if(table[n][M] != table[n - 1][M]) {
			cout << "\nPackage " << n << " with W = " << W[n - 1] << " and Value = " << V[n - 1];
			
			M = M - W[n - 1];
		}
		n--;
	}

}
int main() {
	printf("Hello world!\n");
	int W[] = {3, 4, 5, 9, 4};
	int V[] = {1, 2, 4, 5, 6};
	int size_V = sizeof(V)/sizeof(V[0]);
	int M = 15;

	knapsackDP(W, V, size_V - 1, M);


	return 0;
}