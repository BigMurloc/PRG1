#pragma once //guardian

using namespace std;
const double eps = 1e-12;

//funkcja tworzaca macierz
void  draw_array(int** matrix[], int row[3], int column[3], int dimension, bool statement, int matrix_counter)
{
	matrix[dimension] = new int* [row[dimension]]; //tworzenie odpowiedniego rozmiaru macierzy
	int number; //zmienna ktora bedziemy wpisywac recznie
	for (int i = 0; i < row[dimension]; i++)
	{
		matrix[dimension][i] = new int[column[dimension]];
		for (int j = 0; j < column[dimension]; j++)
		{
			if (statement) {
				//wypelnianie losowe
				matrix[dimension][i][j] = rand() % 30;
			}
			else
			{
				//wypelnianie przez uzytkownika
				cin >> number;
				matrix[dimension][i][j] = number;
			}
		}
	}
	matrix_counter++; //zwiekszenie licznika macierzy (pomoc w usuwaniu macierzy)
}

//funkcja pokazujaca wszystkie macierze
//void show_all_arrays(int** matrix[], int row[3], int column[3], int dimension)
//{
//	int counter = 0;
//	for (int i = 0; i < dimension; i++)
//	{
//		for (int j = 0; j < row[counter]; j++)
//		{
//			for (int k = 0; k < column[counter]; k++)
//			{
//				cout << matrix[i][j][k] << "\t";
//			}
//			cout << endl;
//		}
//		cout << endl << endl;
//		counter++;
//	}
//}

//funkcja pokazujaca konkretna macierz
void show_specific_array(int** matrix[], int row[3], int column[3], int dimension)
{
	for (int i = 0; i < row[dimension]; i++)
	{
		for (int j = 0; j < column[dimension]; j++)
		{
			cout << matrix[dimension][i][j] << "\t";
		}
		cout << endl;
	}
}

//funkcja dodajaca do siebie dwie macierze
void add(int** matrix[], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[0][i][j] += matrix[1][i][j];
		}
	}
}

//funkcja odejmujaca od siebie dwie macierze
void subtract(int** matrix[], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix[0][i][j] -= matrix[1][i][j];
		}
	}
}

//funkcja sprawdzajaca warunek mnozenia
bool multiply_statement(int row[3], int column[3])
{
	return (column[0] == row[1]) ? true : false;
}

//funkcja mnozaca dwie macierze
void multiply(int** matrix[], int row[3], int column[3])
{
	
	for (int i = 0; i <row[0] ; i++) //wiersze (wymiar)
	{
		for (int j = 0; j <column[1] ; j++) //kolumny (wymiar)
		{
			int sum = 0;
			for (int k = 0; k < row[1]; k++)
			{
				sum += matrix[0][i][k] * matrix[1][k][j]; //suma mnozen odpowiedniego wiersza przez kolejne kolumny dwoch macierzy
			}
			matrix[2][i][j] = sum; //przypisanie sumy mnozen do miejsca w macierzy
		}
	}
}

//void transposition(int** matrix[], int row, int column) //funkcja nie zmienia fizycznej postaci macierzy, a wypisuje ja w inny sposob
//{
//	for (int i = 0; i < column[0]; i++)
//	{
//		for (int j = 0; j < row[0]; j++)
//		{
//			cout << matrix[0][j][i] << "\t";
//		}
//		cout << endl;
//	}
//}

//funkcja transponujaca macierze
void transposition(int** matrix[], int row, int column, int dimension) //funkcja nie zmienia fizycznej postaci macierzy, a wypisuje ja w inny sposob
{
	//tworze macierz o wymiarach takich samych jak macierz transponowana - macierz pomocnicza
	int** subMatrix;									
	subMatrix = new int* [row];
	//przechowuje w niej zmienne z macierzy ktora chce transponowac
	for (int i = 0; i < row; i++)
	{
		subMatrix[i] = new int[column];
		for (int j = 0; j < column; j++)
		{
			subMatrix[i][j] = matrix[dimension][i][j];			
		}
	}
	// zmieniam rozmiar macierzy transponowanej na kolumny x wiersze (transponuje rozmiar)
	matrix[dimension] = new int* [column];						
	for (int i = 0; i < column; i++)							
	{
		matrix[dimension][i] = new int[row];
		for (int j = 0; j < row; j++)
		{
			// wypelniam zmieniony rozmiar macierzy odpowiednimi wartosciami
			matrix[dimension][i][j] = subMatrix[j][i];      
		}
	}
	//usuwam macierz pomocnicza
	for (int i = 0; i < row; i++)
	{
			delete[] subMatrix[i];
	}
	delete[] subMatrix;
}

//funkcja sprawdzajaca warunek kwadratowosci(?) macierzy
bool square_statement(int row, int column)
{
	return (row==column) ? true : false;
}

//funkcja liczaca wyznacznik macierzy - algorytm wziety ze strony:  https://eduinf.waw.pl/inf/alg/001_search/0078.php
double det(int n, int w, int* WK, int** matrix[], int dimension)
{
	int k, m;
	int* KK;
	double s;

	if (n == 1)                                    // sprawdzamy warunek zakonczenia rekurencji
	{
		return matrix[dimension][w][WK[0]];                         // macierz 1 x 1, wyznacznik rowny elementowi
	}
	else
	{
		KK = new int[n - 1];                        // tworzymy dynamiczny wektor kolumn
		s = 0;                                      // zerujemy wartosc rozwiniecia
		m = 1;                                      // poczatkowy mnoznik
		for (int i = 0; i < n; i++)                      // petla obliczajaca rozwiniecie
		{
			k = 0;                                    // tworzymy wektor kolumn dla rekurencji
			for (int j = 0; j < n - 1; j++)                // ma on o 1 kolumne mniej niz WK
			{
				if (k == i) k++;                         // pomijamy biezaca kolumne
				KK[j] = WK[k++];                        // pozostale kolumny przenosimy do KK
			}
			s += m * matrix[dimension][w][WK[i]] * det(n - 1, w + 1, KK, matrix, dimension);
			m = -m;                                   // kolejny mnoznik
		}
		delete[] KK;                               // usuwamy zbedna już tablice dynamiczna
		return s;                                   // ustalamy wartosc funkcji
	}
}

//funkcja usuwajaca macierze
void delete_matrices(int row[], int column[], int** matrix[], int matrix_counter)
{
	int counter = matrix_counter;
	for (int i = 0; i < matrix_counter; i++)
	{
		for (int j = 0; j < row[counter]; j++)
		{
			delete[] matrix[i][j];
		}
		delete[] matrix[i];
		counter--;
	}
	delete[] matrix;
}