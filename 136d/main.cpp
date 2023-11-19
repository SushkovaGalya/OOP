//Cушкова Галина ИВТ-22
//https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

#include <iostream> 	//основная библиотека для ввода/вывода
#include <time.h> 		//время для рандомных элементов массива
#include <math.h> 		//математическая бибилотека
#include <fstream> 		//библиотека для работы с файлами   
#include <cassert>		//библиотека для assert
#include <exception>	//библиотека для обработки исключений
#include "unit136d.h" 	//подключенный модуль
#include <vector> 		//библиотека для массивов

using namespace std; 	//пространство

using namespace massive;


int main(int argc, char *argv[])
{
	string carg, file_name; 											//имя файла

	srand(time(0)); 													//устанавливает в качестве базы текущее время для того, чтобы при разных запусках у генератора псевдослучайных чисел была разная база

	int size_arr; 														//размер массива
	float up_limit, down_limit;											//верхняя и нижняя граница рандома	
	char check;															// считывание ответа пользователя							

	unsigned size_test = 4;												//размер массивов для проверки

	vector<float> test = {3, 4, 6,5};										//создаем массив
	assert(summa(test) == 86);											//проводим проверку
	test.clear();														//очищаем массив

	test = {7, 5, 6,8};													//задаём массиву новые значения
	assert(summa(test) == 174);										//проводим проверку
	test.clear();														//очищаем массив

	test = {2, 4, 9,8};													//задаём массиву новые значения
	assert(summa(test) == 165);											//проводим проверку
	test.clear();


	if (argc > 1) 														//если в командной строке есть какие-то аргументы
	{
		carg = argv[1];
		if (carg == "load") 											//если пользователь хочет загрузить массив из файла
		{
			file_name = argv[2]; 										//считываем имя файла в переменную file_name
			cout << "Entered name of file: " << file_name << endl;
			size_arr = poisk_from_file(file_name); 				//узнаём размера массива в файле
			try
			{
				unsigned size = poisk_from_file(file_name); 		//выводится ошибка, если такого файла нет
			}
			catch(const exception& error)
			{
				cout << error.what();
			}
			vector<float> mass; 																	
			mass.resize(size_arr);										//выделяем память под заданное кол-во элементов
			array_from_file(mass, size_arr, file_name);					//считываем массив из файла
			print_mas(mass); 											//ф-ция вывода массива на экран
			cout << endl << "Result: " << summa(mass);					
			mass.clear();												//очищаем массив			
		}

		if (carg == "create") 											//если пользователь хочет создать новый массив
		{
			size_arr = stoul(argv[2]); 									//считываем размер массива в переменную size_arr									
			up_limit = stoul(argv[3]);									
            down_limit = stoul(argv[4]);								

            cout << "Entered size of array: "<< size_arr <<endl; 		//выводим значения, которые пользователь ввёл в командную строку
            cout << "Entered up limit: " << up_limit << endl;
            cout << "Entered down limit: " << down_limit << endl;

            vector<float> mass; 										//дин массив, пустой
			mass.resize(size_arr);										//выделяем память под заданное кол-во элементов
			mas_rand(mass, up_limit, down_limit);						//ф-ция заполнения массива случайными числами
			cout << "Array: ";
			print_mas <float> (mass); 									//ф-ция вывода массива на экран
			cout << endl<< "Result: " << summa(mass) << endl;	
			if (argc == 6) 												//если аргументов в строке 6, значит польователь ввёл название файла и хочет сохранить массив
			{
            	file_name = argv[5];									//считываем имя файла в переменную file_name
            	print_to_file(mass, file_name); 						//вывод массива в текстовый файл
				cout << "Array saved" << endl;
			}
			mass.clear();												//очищаем массив
		}
	}
	else
	{
		cout << "Create a new array?" << endl;							//запрашиваем у пользователя нужно ли создавать новый массив
		cin >> check;
		if ((check == 'Y') or (check == 'y'))
		{
			cout << "Print size array" << endl;							//запрашиваем у пользователя размер массива
			cin >> size_arr;
			while (size_arr < 0)										//проверка
			{
				cout << "Print size array > 0 "<< endl; 				//если размер массива меньше 0, то выводим ошибку
				cin >> size_arr;										//просим ввести значение заново
			}
			cout << "Print up limit: " << endl;							
			cin >> up_limit;
			cout << "Print down limit: " << endl;						
			cin >> down_limit;
			vector<float> mass; 										//дин массив, пустой
			mass.resize(size_arr);										//выделяем память под заданное кол-во элементов
			mas_rand(mass, up_limit, down_limit);						//ф-ция заполнения массива случайными числами
			cout << "Array: ";
			print_mas <float> (mass); 									//ф-ция вывода массива на экран
			cout << endl<< "Result: " << summa(mass) << endl;			//выводим результат
			cout << "Save array?" << endl;								//запрашиваем у пользователя нужно ли сохранить массив
			cin >> check;
			if ((check == 'Y') or (check == 'y'))
			{
				cout << "Print name file" << endl; 						//запрашиваем у пользователя имя файла
				cin >> file_name;
				print_to_file(mass, file_name); 						//вывод массива в текстовый файл
				cout << "Array saved" << endl;	
			}
			mass.clear();												//очищаем память
		}									
		else
		{
			cout << "Print name file" << endl; 							//запрашиваем у пользователя имя файла
			cin >> file_name;
			size_arr = poisk_from_file(file_name); 				//узнаём размера массива в файле
			try
			{
				unsigned size = poisk_from_file(file_name);
			}
			catch(const exception& error)
			{
				cout << error.what();
			}
			vector<float> mass; 																	
			mass.resize(size_arr);										//выделяем память под заданное кол-во элементов
			array_from_file(mass, size_arr, file_name);					//считываем массив из файла
			print_mas(mass); 											//ф-ция вывода массива на экран
			cout << endl << "Result: " << summa(mass);				
			mass.clear();												//очищаем память
		}
	}
}
