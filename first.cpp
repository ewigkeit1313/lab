#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;


	// __________________----LOG----____________________
		

	//_______file__________________


	class go_file{


		public: std::string get_date(){
 				   std::time_t result = std::time(NULL);
 				   std::string time = std::asctime(std::localtime(&result));
 			return time.erase(time.find('\n'),1);
		}
/*
		public: void check_file(const char * file_name){   //проверяем, есть ли файл, если его нет, то создаем! \(^_^)/
			

				fstream w_f(file_name);

					if(!w_f){
						cout<<"Такого файла нет, но я создам!"<<endl;
						ofstream c_f(file_name);
						c_f.close();
					}
				w_f.close(); 
		}
*/

		public: void wr_to_file(bool end_file, char text[], char file_name[]){

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
			char mass_size[6];
				go_file usegofile;
				usegofile.wr_to_file(true, "зашли в класс lab1 ", "ladlog.log");

			std::cout << "из скольки чисел будет состоять наш массив?";
			std::cin>>mass_size;

			//char text_log = strcat(mass_size,2);

			usegofile.wr_to_file(true,mass_size, "ladlog.log");
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

		return 0;
}