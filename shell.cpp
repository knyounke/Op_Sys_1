#include <string>
#include <vector>
#include <exception>
#include <cstring>
#include <iostream>
#include <sys/types.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>

using namespace std;

int main(void){
   pid_t child; //process id
   DIR * directory;
   struct dirent * directory_entry;
   int i, j;
   string k;
   string buffer, command; //buffers for command and string
   time_t time;

   while(true){
	cout<< "Time: "<< ctime(&time) << endl;
	buffer = get_current_dir_name(); //handles unknown string size instead of char[]
  	 cout << endl << "Current Directory: " << buffer << endl;
	
	directory = opendir(".");
	j = 0;
	while((directory_entry = readdir(directory))){
		if((directory_entry->d_type) & DT_DIR)
			cout << j << " Directory: " << directory_entry->d_name << endl;
		j++;

		if( ( j % 8 ) == 0) {
		  cout << "Hit N for Next" << endl; 
		  cin >> k;
		}
	}
	closedir(directory);
	cout << "------------------------------------" << endl;
	getline(cin, k);


	if(k == "q")
	  exit(0);
	else if(k == "e"){
	 cout << "Edit What? " << endl;
		   cin >> buffer;
		   command = "pico ";
		   command += buffer;
		   system(command.c_str());
		
		}
	 else if(k == "r"){
		   cout << "Run what? " << endl;
		   cin >> command;
		   system(command.c_str());
		   }
	 else if(k == "c"){
	 	 cout << "Change to? " << endl;
		   cin >> command;
		   chdir(command.c_str());
		   }
	else
		{
		cout << "ERROR. Incorrect entry!" << endl << endl;
	}
	
	
    }
  
}
