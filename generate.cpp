#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char **argv) {
	
	int n, m;
	cout << "Enter the number of variables: ";
	cin >> n;
	cout << endl << "Enter the number of equations: ";
	cin >> m;
	
	ofstream Matrix("matrix_s.txt");
	Matrix << n << " " << m << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n+1; j++)
			Matrix << rand()%10 << " ";
		Matrix << endl;
	}
	return 0;
}
