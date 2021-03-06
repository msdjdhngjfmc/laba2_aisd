#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;
#define RANGE 255


int Search_Binary(int arr[], int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (left + right) / 2;

		if (key < arr[midd])      
			right = midd - 1;     
		else if (key > arr[midd])  
			left = midd + 1;   
		else                       
			return midd;           

		if (left > right)          
			return -1;
	}
}

int quickSort(int* numbers, int left, int right)
{
	int pivot; // разрешающий элемент
	int l_hold = left; //левая граница
	int r_hold = right; // правая граница
	pivot = numbers[left];
	while (left < right) // пока границы не сомкнутся
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--; // сдвигаем правую границу пока элемент [right] больше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
			left++; // сдвигаем левую границу вправо
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++; // сдвигаем левую границу пока элемент [left] меньше [pivot]
		if (left != right) // если границы не сомкнулись
		{
			numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
			right--; // сдвигаем правую границу вправо
		}
	}
	numbers[left] = pivot; // ставим разрешающий элемент на место
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot) // Рекурсивно вызываем сортировку для левой и правой части массива
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
	return 1;
}

int correct(int* arr, int size) {
	while (size-- > 0)
		if (arr[size - 1] > arr[size])
			return 0;
	return 1;
}

void shuffle(int* arr, int size) {
	for (int i = 0; i < size; ++i)
		std::swap(arr[i], arr[(rand() % size)]);
}

int bogoSort(int* arr, int size) {
	while (!correct(arr, size))
		shuffle(arr, size);
	return 1;
}

int str_len(char* str)
{
	int i(0);

	while (str[i] == '\0')
		i++;

	return(i);
}

int countSort(char Arr[])
{
	Arr[255];

	char* output = new char[str_len(Arr)];


	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count));

	for (i = 0; Arr[i]; ++i)
		++count[Arr[i]];

	for (i = 1; i <= RANGE; ++i)
		count[i] += count[i - 1];

	for (i = 0; Arr[i]; ++i) {
		output[count[Arr[i]] - 1] = Arr[i];
		--count[Arr[i]];
	}

	for (i = 0; Arr[i]; ++i)
		Arr[i] = output[i];
	
	return 1;
}

int insertionSort(int array[], int size) {
	int buff = 0;

	for (int i = 1; i < size; i++)
	{
		int j;
		buff = array[i]; // запомним обрабатываемый элемент
		// и начнем перемещение элементов слева от него
		// пока запомненный не окажется меньше чем перемещаемый
		for (j = i - 1; j >= 0 && array[j] > buff; j--)
			array[j + 1] = array[j];

		array[j + 1] = buff; // и поставим запомненный на его новое место 
	}

	return 1;
}

int main()
{
	setlocale(LC_ALL, "rus");

	const int SIZE = 15;
	long int size, date;
	int array[SIZE] = {};
	int key = 0, option;
	int index = 0,lok=0; // индекс ячейки с искомым значением
	bool keyOfWhile = true;
	
	while (keyOfWhile == true)
	{
		cout << "Введите вариант, с которым хотите работать\n";
		cout << "\t\t1 - Двоичный поиск\n";
		cout << "\t\t2 - Быстрая сортировка\n";
		cout << "\t\t3 - Сортировка вставками\n";
		cout << "\t\t5 - Глупая сортировка\n";
		cout << "\t\t6 - Сортировка подсчётом для типа char\n";
		cout << "\t\t0 - Заверщить программу\n\t\t |\n\t\t~|~\n\t\t ";
		cin >> option;
		if (option != 1 && option != 2 && option != 3 && option != 5 && option != 6 && option != 0)
		{
			cout << "\t\t~|~\n\t\t |\n";
			continue;
		}
		else {
			if (option == 0) {
				cout << "\t\t~|~\n\t\t |\n";
				return 0;
			}
			if (option == 6) {
				int num(0);
				cin >> num;
				for (int j = 0; j < num; j++) {
					char Arr[RANGE];
					cin >> Arr;
					countSort(Arr);
					cout << endl << "Sorted character array is " << Arr << endl << "-----------";
					
				}
				return 0;
			}
			//cout << "\t\t~|~\n\t\t |\nСколько переменных будет в массиве: ";
			size = 15;
			cout << endl;
			cout << "\t\t";
			for (int i = 0; i < size; i++) 
			{
				//cout << i + 1 << ".";
				//cin >> date;
				array[i] =1 + rand()%10;
				cout << " | " << array[i];
			}

		}
		cout << endl;
		if (option == 1) {


			cout << "\n\nВведите любое число: ";
			cin >> key;

			index = Search_Binary(array, 0, SIZE, key);

			if (index >= 0)
				cout << "Указанное число находится в ячейке с индексом: " << index + 1 << "\n\n";
			else
				cout << "В массиве нет такого числа!\n\n";
			continue;
		}
		if (option == 2) {
			time_t end;
			quickSort(array, 0, size - 1);
			keyOfWhile = false;
			end = clock();
			cout << "Time: " << end / 1000.0 << endl;
		}
		if (option == 3) {
			time_t end;

				keyOfWhile = false;
			
			insertionSort(array, size);
			end = clock();
			cout << "Time: " << end/1000.0 << endl;
		}
		if (option == 5) {
			bogoSort(array, size);
		}
		cout << "Массив после сортировки\n\n\t\t";
		for (int i = 0; i < size; i++) {
			cout << " | " << array[i];
		}
		cout << " |" << endl << endl;
	}


	return 0;
}