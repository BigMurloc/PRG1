#include <iostream>
#include "functions.h"
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;
bool random_statement;
int main()
{
	srand(time(NULL));
	int rand_choice = 0, loop = true;
	while (loop)
	{
		cout << "Czy chcesz wpisywac recznie liczby?" << endl;
		cout << "1. Tak" << endl;
		cout << "2. Nie" << endl;
		cin >> rand_choice;
		switch (rand_choice)
		{
			case 1:
			{
				random_statement = false;
				loop = false;
			}
			break;
			case 2:
			{
				random_statement = true;
				loop = false;
			}
			break;
			default:
			{
				cout << "Nie ma takiego wyboru" << endl;
			}
		}
	}
	system("CLS");
	while (true)
	{
		int*** matrix;
		matrix = new int** [3];
		int row[3], column[3], counter = 0;
		int n, i, j;                              // stopien macierzy
		int* WK;                                 // wektor kolumn
		int matrix_counter = 0;
		cout << "Witaj w kalkulatorze macierzy!" << endl;
		cout << "Co chcesz dzisiaj zrobic?" << endl;
		cout << "1. Dodac do siebie dwie macierze" << endl;
		cout << "2. Odjac do siebie dwie macierze" << endl;
		cout << "3. Pomnozyc przez siebie dwie macierze" << endl;
		cout << "4. Obliczyc wyznacznik" << endl;
		cout << "5. Transponowac" << endl;
		cout << "6. Zmiana trybu pracy programu reczny/losowy" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
			/*CASE0*/ case 0:
			{
				_exit(0);
			}
			/*CASE1*/ case 1:
			{
				cout << "Dodawanie" << endl;
				cout << "Macierze, ktore chcesz dodac musza byc kwadratowe." << endl;
				cout << "Podaj ich wymiar: "; cin >> row[0];
				row[1] = row[0];
				while (counter < 2) {
					draw_array(matrix, row, row, counter, random_statement, matrix_counter); //funkcja tworzaca macierz
					show_specific_array(matrix, row, row, counter); //funkcja pokazujaca macierz
					cout << endl;
					counter++;
				}
				cout << "Wynik tego dodawania to: " << endl;
				add(matrix, row[0], row[0]); //funkcja dodajaca do siebie macierze
				show_specific_array(matrix, row, row, 0); //funkcja pokazujaca macierz

				cout << "Czy chcesz obliczyc wyznacznik?" << endl;
				cout << "1. Tak" << endl;
				cout << "2. Nie" << endl;
				int det_option;
				cin >> det_option;
				if (det_option == 1)
				{
					WK = new int[row[0]];                              // tworzymy wiersz kolumn
					for (i = 0; i < row[0]; i++) { WK[i] = i; }                   // wypelniamy go numerami kolumn
					cout << "Wyznacznik to: " << det(row[0], 0, WK, matrix, 0) << endl; //funkcja obliczajaca wyznacznik
				}
			}
			break;

			/*CASE2*/ case 2:
			{
				cout << "Odejmowanie" << endl;
				//swich recznie lub losowo
				cout << "Macierze, ktore chcesz odjac musza byc kwadratowe." << endl;
				cout << "Podaj ich wymiar: "; cin >> row[0];
				row[1] = row[0];
				while (counter < 2) {
					draw_array(matrix, row, row, counter, random_statement, matrix_counter); //funkcja tworzaca macierz
					show_specific_array(matrix, row, row, counter); //funkcja pokazujaca macierz
					cout << endl;
					counter++;
				}
				cout << "Wynik tego odejmowania to: " << endl;
				subtract(matrix, row[0], row[0]); //funkcja odejmujaca od siebie macierze
				show_specific_array(matrix, row, row, 0); //funkcja pokazujaca macierz
				cout << "Czy chcesz obliczyc wyznacznik?" << endl;
				cout << "1. Tak" << endl;
				cout << "2. Nie" << endl;
				int det_option;
				cin >> det_option;
				if (det_option == 1)
				{
					WK = new int[row[0]];                              // tworzymy wiersz kolumn
					for (i = 0; i < row[0]; i++) { WK[i] = i; }                   // wypelniamy go numerami kolumn
					cout << "Wyznacznik to: " << det(row[0], 0, WK, matrix, 0) << endl; //funkcja obliczajaca wyznacznik
				}
			}
			break;


			/*CASE3*/ case 3:
			{
				cout << "Mnozenie" << endl;
				//swich recznie lub losowo
				cout << "Mnozone macierze musza miec wymiary AxB BxC" << endl;
				while (counter < 2) {
					cout << "Podaj wymiar " << counter + 1 << " macierzy: " << endl;
					cout << "Liczba wierszy: "; cin >> row[counter];
					cout << "Liczba kolumn: "; cin >> column[counter];
					draw_array(matrix, row, column, counter, random_statement, matrix_counter); //funkcja rysujaca macierz
					show_specific_array(matrix, row, column, counter); //funkcja wyswietlajaca macierz
					counter++;
				}
				if (multiply_statement(row, column)) //if sprawdza czy macierz jest wymiaru AxB BxC
				{
					row[2] = row[0];
					column[2] = column[1];
					draw_array(matrix, row, column, 2, true, matrix_counter); //funkcja rysujaca macierz 
					multiply(matrix, row, column); //funkcja mnozaca macierze
					cout << endl << endl;
					cout << "Wynik tego mnozenia to: " << endl;
					show_specific_array(matrix, row, column, 2); //funkcja pokazujaca macierz
				}
				else
				{
					cout << "Nie mozna pomnozyc takiej macierzy" << endl;
					break;
				}
				if (square_statement(row[2], column[2])) { //if sprawdza czy macierz jest kwadratowa
					cout << "Czy chcesz obliczyc wyznacznik?" << endl;
					cout << "1. Tak" << endl;
					cout << "2. Nie" << endl;
					int det_option;
					cin >> det_option;
					if (det_option == 1)
					{
						WK = new int[row[2]];                              // tworzymy wiersz kolumn
						for (i = 0; i < row[2]; i++) { WK[i] = i; }                   // wypelniamy go numerami kolumn
						cout << "Wyznacznik to: " << det(row[2], 0, WK, matrix, 2) << endl; //funkcja obliczajaca wyznacznik
					}
				}
			}
			break;


			/*CASE4*/ case 4:
			{
				cout << "Wyznacznik" << endl;
				cout << "Aby policzyc wyznacznik musisz najpierw stworzyc macierz." << endl;
				cout << "Macierz ta musi byc kwadratowa." << endl;
				cout << "Podaj jej wymiar: "; cin >> row[0];
				draw_array(matrix, row, row, counter, random_statement, matrix_counter); //funkcja tworzaca macierz
				show_specific_array(matrix, row, row, counter);
				WK = new int[row[0]];                              // tworzymy wiersz kolumn
				for (i = 0; i < row[0]; i++) { WK[i] = i; }                   // wypelniamy go numerami kolumn
				cout << "Wyznacznik to: " << det(row[0], 0, WK, matrix, 0) << endl; //funkcja obliczajaca wyznacznik
				//wyzczanik();
			}
			break;

			/*CASE5*/ case 5:
			{
				cout << "Transponowanie" << endl;
				cout << "Stworz macierz, ktora chcesz transponowac" << endl;
				cout << "Liczba wierszy: "; cin >> row[0];
				cout << "Liczba kolumn: "; cin >> column[0];
				draw_array(matrix, row, column, 0, random_statement, matrix_counter); //funkcja tworzaca macierz
				show_specific_array(matrix, row, column, 0); cout << endl; //funkcja wyswietlajaca macierz
				transposition(matrix, row[0], column[0], 0); cout << endl; // funkcja transponujaca macierz
				show_specific_array(matrix, column, row, 0); cout << endl; //funkcja wyswietlajaca macierz
			}
			break;
			/*CASE6*/ case 6:
			{
				if (random_statement)
				{
					random_statement = false;
					cout << "Zmieniono sposob tworzenia macierzy na reczny" << endl;
				}
				else
				{
					random_statement = true;
					cout << "Zmieniono sposob tworzenia macierzy na losowy" << endl;
				}
			}
			break;

			/*DEFAULT*/	default:
			{
				cout << "Nie ma takiego wyboru" << endl;
			}
		}
		system("PAUSE");
		system("CLS");
		delete_matrices(row, column, matrix, matrix_counter); //funkcja usuwajaca wszystkie macierze
		}
	}
