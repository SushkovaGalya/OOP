#include <iostream> 	//основная библиотека для ввода/вывода
#include <math.h> 		//математическая бибилотека
#include <fstream> 		//библиотека для работы с файлами   
#include <iomanip>      //библиотека для форматирования вывода
#include <vector>       //библиотека для массивов

using namespace std;    //пространство имён

namespace massive
{

///Заполнение массива  случайными числами
void mas_rand(vector<float> &mas, float up_limit, float down_limit)
{
    int range = up_limit - down_limit;                         //диапазон рандома
	for(unsigned i = 0; i < mas.size(); i ++) 
	{		
        mas[i]=(float)rand()/RAND_MAX*range +down_limit;    //RAND_MAX константа для определения диапазона
	}
}


///Сумма квадратов элементов массива
float summa(vector<float> &mas)
{
	float res = 0;
	for(unsigned i = 0; i < mas.size(); i ++) 
	{
		res += pow(mas[i], 2); 								     //находим сумму квадратов элементов массива
	}
	return res;
}

///Вывод массива  в текстовый файд 
void print_to_file(vector<float> &mas, const string &file_name)
{
	ofstream file(file_name); 								     //открытие файла
	if (!file.is_open())                                	     //если файл не открыт, то выводим ошибку
    {
        throw runtime_error("File not found");       
    }
    for (unsigned i=0; i < mas.size(); i++)                     
    {
    	file << mas[i] << endl; 			                     //выводим по одному элементу в строку
    }
}

///Поиск кол-ва элементов массива в файле 
unsigned poisk_from_file(const string &file_name)
{
	unsigned res = 0;                                   	     //переменная для счета кол-ва строк
    string line;                                        	     
    ifstream file(file_name);                           	    
    if (!file.is_open())                                	     //если файл не открыт, то выводим ошибку
    {
        throw runtime_error("File not found");        		
    }
    while (getline(file, line))                         	    
    {
        res++;                                      	
    }

    file.close();                                       	     //закрываем файл
    return res;
}

///Загрузка массива  из файла 
void array_from_file(vector<float> &mas, unsigned size_arr, const string &file_name)
{
    ifstream file(file_name);                           	     //открытие файла 
    if (!file.is_open())                                	     //если файл не открыт, то выводим ошибку
    {
        throw runtime_error("File not found");     
    }
    for (unsigned i = 0; i < size_arr; i++)                	  //цикл для чтения массива из файла
    {
        file >> mas[i];                                 	     //записываем построчно числа в массив
    }
}

}