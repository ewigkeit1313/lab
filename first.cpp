#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


	// __________________----LOG----____________________
		

	//_______file__________________


	class go_file{

		public: void check_file(const char * file_name){   //проверяем, есть ли файл, если его нет, то создаем! \(^_^)/
			

				fstream w_f(file_name);

					if(!w_f){
						cout<<"Такого файла нет, но я создам!"<<endl;
						ofstream c_f(file_name);
						c_f.close();
					}
				w_f.close(); 
		}


		public: void wr_to_file(int end_file, const char * log_text, const char* file_name){

				if (end_file == '1'){
					ofstream writef("main.txt", ios_base::trunc);
				}else{
					ofstream writef("main.txt",ios_base::app);
				}
				
					writef<<log_text<<"\n";

		}

//		public lock_file(){

//		}

	};


		class logs{
			

			public: void addlog(){
				go_file ADD;
				ADD.check_file("logs.log");


			}


		};


int main(){

	//logs LOG;
	//LOG.addlog(1, "log");


	go_file usegofile;

    usegofile.check_file("main.txt");



    usegofile.wr_to_file(2, "}{yY", "main.txt");
	//std:cout<<"'Hell world! =)'";
		return 0;
}