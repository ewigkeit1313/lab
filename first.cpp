#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <string.h>
#include <stdarg.h>

#include <cstdlib>

using namespace std;



		//______________________Абстрактный класс и все для него______
		
		class abstract{
			public:virtual void print_msg()=0;
		};

		class useAbsrtFunc:public abstract{		// Наследуемся абстрактного класса
			void print_msg(){					//Реализация виртуальной функции в нашем классе
				cout<<"Все проошло хорошо) \n";
			}
		};


		void foo(abstract *p){   // Функция указатель на объект 
			p->print_msg();		 // Вызываем метод print_msg
		}
		//___________________________________________



//_______file__________________

	class go_file{

		public: char *concat(char *s1...){                            //ссылаемся на область памяти в которой лежит значение типа char  <-- укзатель
			   va_list par;          //указатель на параметры списка
			   char *cp;
			   int len = strlen(s1); //длина 1-го параметра

			   va_start(par,s1);     //начало переменного списка
			 
			   //цикл для определения общей длины параметров строк
			   while(cp = va_arg(par, char *))
				     len += strlen(cp); 
			 
			   //выделение памяти для результата
			   char *stroka = new char[len + 1];
			   strcpy(stroka, s1);
			   va_start(par, s1);//начало переменного списка
			   //цикл конкатенации параметров строк
			   while(cp = va_arg(par, char *))
			       		strcat(stroka, cp);
			 
			   va_end(par);
			   return stroka;
			}


		public: std::string get_date(){
 				   std::time_t result = std::time(NULL);
 				   std::string time = std::asctime(std::localtime(&result));
 			return time.erase(time.find('\n'),1);
		}



		public: void wr_to_file(bool end_file, char text[],const char file_name[]){

				ofstream writef; // связываем файл с потоком ввода

				if (end_file != true){                          // усли true пишем в конец файла. Для логов!
					writef.open(file_name, ios_base::trunc);
					writef<<text<<endl;
				}else{
					writef.open(file_name,ios_base::app);
					writef<<get_date()  << " ---> " <<text << endl;
				}
				

			writef.close();
		}

//		public lock_file(){

//		}

	};



	class lab1{

		public: void work_w_mass(){
 		
 		char mass_size_log[100];
		char *inlog;
		int mass_size;
		char znak;
		int operand;


			go_file usegofile; // Создаем объект класса. 

				usegofile.wr_to_file(true, "зашли в класс lab1 ", "ladlog.log");

					cout << "из скольки чисел будет состоять наш массив? Макс 100\n";
					cin >> mass_size_log;

						inlog = usegofile.concat("массив состоит из ",mass_size_log," элемента(ов)",NULL);
					
						//int count = atoi(mass_size);
						mass_size = atoi(mass_size_log);    // Переведем чары в инты для работы с массивом. Криво, нужно будет переделать.

							char mass[mass_size];			// Зададим размер нашего массива. 

						for(int i=0; i<mass_size;i++){      //вводим массив
							cout << i << " ---> ";
							cin >> mass[i];
						}

						cout << "Введите знак ----> ";
							cin >> znak;

						cout << "Введите операнд ----> ";
							cin >> operand;

						

				usegofile.wr_to_file(true, inlog, "ladlog.log");
				//usegofile.wr_to_file(true, mass_size, "ladlog.log");

		}



	};



int main(int argc, char* argv[]){
 
 /*+++++++++++++++++++++++++++++++++++++++++++++++++

	argc - определяет количество параметров, передаваемых функции, включая имя самой программы. 
	argv* - является указателем на массив указателей типа char.

 ++++++++++++++++++++++++++++++++++++++++++++++++++++*/

	//logs LOG;
	//LOG.addlog(1, "log");

	lab1 lab_do;
	go_file usegofile;

    //usegofile.check_file("main.txt");
    usegofile.wr_to_file(true, "}{yY!", "main.txt");
	//std:cout<<"'Hell world! =)'";

    lab_do.work_w_mass();

    useAbsrtFunc u;    // юзаем абстракную функцию и объект(класс)
    foo(&u);


		return 0;
}