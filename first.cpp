#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


	// __________________----LOG----____________________
		

	//_______file__________________


	class go_file{


		public: char* get_date(){
				time_t seconds = time(NULL);
				tm* timeinfo = localtime(&seconds);
				char* time = asctime(timeinfo);
				 return time;
		}

		public: void check_file(const char * file_name){   //проверяем, есть ли файл, если его нет, то создаем! \(^_^)/
			

				fstream w_f(file_name);

					if(!w_f){
						cout<<"Такого файла нет, но я создам!"<<endl;
						ofstream c_f(file_name);
						c_f.close();
					}
				w_f.close(); 
		}


		public: void wr_to_file(bool end_file, const char * text, const char* file_name){

				ofstream writef; // связываем файл с потоком ввода

				if (end_file != true){
					writef.open(file_name, ios_base::trunc);
				}else{
					writef.open(file_name, ios_base::app);
				}
				
					writef<<  <<text<<"\n";

			writef.close();
		}

//		public lock_file(){

//		}

	};

/*
		class logs{
			

			public: void addlog(){
				go_file ADD;
				ADD.check_file("logs.log");


			}


		};

*/

	class lab1{

		public: void work_w_mass(){
						go_file usegofile;
						go_file time;

			usegofile.wr_to_file(true,time.get_date(),"main.txt");
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

    usegofile.check_file("main.txt");
    usegofile.wr_to_file(true, "}{yY12", "main.txt");
	//std:cout<<"'Hell world! =)'";

    lab_do.work_w_mass();

		return 0;
}