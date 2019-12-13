#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <clocale>
#include "windows.h"
#include "conio.h"
#include <cstdlib>

using namespace std;

int intellect=0;



void type_slow(string str)
{
	for (auto ch : str)
	{
		cout << ch;
		Sleep(30);
	}
}

void victorina_text()
{

	int bufff[4][10] = {
		{},
	{},

	}

	setlocale(LC_ALL, "rus");
	ifstream file("victorina.txt");//создаем объект потока istream  по имени file
						// который инициализируется  именем fileName,
					   //вызывается функция file.open();
	string str;         //переменная стринг для строки     
	string buff;
	int counter = 0;
	int entr_skeep_1 = 1;
	int var;
	string vars;
	while (getline(file, str)) //getline(istream & is, string &s,char c='\n'),читает из потока is, в строку s пока 
	{    
		counter++;
		//не встретит символ c (без этого символа до новой строки)
		//cout << str << endl;	
		// возвращает свой объект istream, в условии проверяется состояние iostate флагa, значение этого флага будет ложным, если достигнет конца файла, или будет ошибка ввода или читаемого типа
		int pos_scob = str.find_first_of("(");
		if (counter % 6 == 1 && entr_skeep_1 == 1)
		{
			
			type_slow(str.substr(0, pos_scob));
			entr_skeep_1++;
		}
		else if (counter % 6 == 1) {
			
			
			system("cls");
			type_slow(str.substr(0, pos_scob));
			entr_skeep_1++;
		}
		else {
			cout << endl << str.substr(0, pos_scob);
		}
		if (counter % 6 == 5)
		{
			var = 0;
			while (var > 4 || var < 1)
			{
				
				cin >> vars;
				try
				{
					var = stoi(vars);
				}
				catch (...)
				{
					cout << endl << "неправельный ответ" << endl;
					continue;
				}
				if(var > 4 || var < 1)
					cout << endl << "неправельный ответ" << endl;

			}

		}
		
		 // вызываем нужною функцию для полученной строки;

	}
}




int main()
{
	victorina_text();


	return 0;
}
