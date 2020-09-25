#include <iostream>
#include <fstream>

using namespace std;
int main() {
	
	int size, tsize;
	ifstream slae ("matrix_s.txt");
	//ofstream dat ("data.txt");
	
    slae >> size; // количество переменных
    slae >> tsize; //количество уравнений
    
    if (size > tsize) cout << "Many solutions";
    else {
    	
    double m;
    double x[size];   
	double arr[size][size + 1]; // tempMatrix
	double arrSlau[tsize][size + 1]; // Matrix
	
    for (int i = 0; i < tsize; i++) 
        for (int j = 0; j < size + 1; j++) 
            slae >> arrSlau[i][j];
	       
    for (int i = 0; i < size-1; i++) 
        for (int j = 0; j < size + 1; j++) 
            arr[i][j] = arrSlau[i][j];
    
    for (int i = 0; i < size + 1; i++)
    	arr[size-1][i]=arrSlau[tsize-1][i];
            
    for (int i = 0; i < size; i++) {
        x[i] = arr[i][size];
    }
    
    // прямой ход - исключение неизвестных
    for (int k = 1; k < size; k++) {
        for (int j = k; j < size; j++) {
            m = arr[j][k - 1] / arr[k - 1][k - 1];
            for (int i = 0; i < size; i++) {
                arr[j][i] = arr[j][i] - m * arr[k - 1][i];  
            }
            x[j] = x[j] - m * x[k - 1];
        }
    }
    // обратный ход - подставляем и считаем
    for (int i = size - 1; i >= 0; i--) {
        for (int j = i + 1; j < size; j++) 
			x[i] -= arr[i][j] * x[j];
        x[i] = x[i] / arr[i][i];
    }
		
	double key = 0.0;
	bool flag = 0;
	for (int i = 0; i < tsize; i++) {
		for (int j = 0; j < size; j++) {
			key += arrSlau[i][j]*x[j];
		}
		if (key != arrSlau[i][size]) flag = 1;
		key = 0.0;
	}
	if (flag == 1) cout << "No solutions";
	else 
		for (int i = 0; i < size; i++)
    		cout << x[i] << " ";
	}
	return 0;
}
