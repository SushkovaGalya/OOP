#ifndef UNIT136D_H
#define UNIT136D_H
#include <string>
#include <iostream> 
#include <vector> 	//библиотека для массивов
#include <iomanip> 
using namespace std;//пространство имён

namespace massive
{

///Заполнение массива  случайными числами
void mas_rand(vector<float> &mas, float up_limit, float down_limit);

///Вывод массива на экран 
template < typename El>
void print_mas(vector<El> &mas)
{
	for(unsigned i = 0; i < mas.size(); i++)
	{
		cout << setprecision(4) << mas[i] << " "; 				//выводим элементы через пробел
	}
}

///Сумма квадратов элементов массива 
float summa(vector<float> &mas);

///Вывод массива в текстовый файл 
void print_to_file(vector<float> &mas, const string &file_name);


///Поиск кол-ва элементов массива в файле 
unsigned poisk_from_file(const string &file_name);

///Загрузка массива  из файла 
void array_from_file(vector<float> &mas, unsigned size_arr, const string &file_name);
}

#endif