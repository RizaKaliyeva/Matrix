#include"Matrix.h"
#include"Matrix.cpp"

int main() {
	setlocale(LC_ALL, "Rus");
	int n;
	cin >> n;
	switch (n)
	{
	case 1: {

	}break;

	case 2: {
		matrix <int> mas(2, 3, 5);
		cout << "1:\n";
		cout << mas;

		matrix <int> mas2;
		mas2 = mas;
		cout << "2:\n";
		cout << mas2;
	}break;


	case 3: {
		matrix <int> mas(1, 1, 1);
		matrix<int> mas1(5, 4, 2);
		cout << "2:\n";
		cout << mas1;
		cout << "----------------------------------------------" << endl;
		matrix<int> mas2;
		mas2 = mas + mas1;
		cout << mas2;
	}break;



	}
	system("pause");
	return 0;
}