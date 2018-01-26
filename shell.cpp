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
   int i, j, k; //incrementors
   char buffer[256], command[256]; //buffers for command and string
   time_t time;

   while(true){
	cout<< "Time: "<< ctime(&time) << endl;
	 getcwd(buffer, 300); //figure out second argument size
  	 cout << endl << "Current Directory: " << buffer << endl;
	
	directory = opendir(".");
	j = 0;
	while((directory_entry = readdir(directory))){
		if((directory_entry->d_type) & DT_DIR)
			cout << j << "Directory: " << directory_entry->d_name << endl;
		if( ( j % 8 ) == 0) {
		  cout << "Hit N for Next" << endl; //handle times if only subdirs (if none, goes in infinite loop)
		  cin >> k;
		}
	}
	closedir(directory);
	cout << "------------------------------------" << endl;
	cin >> j;
	switch (j) {
	 case 'q': exit(0);
		   break;
	 case 'e': cout << "Edit What? " << endl;
		   cin >> buffer;
		   strcpy(command, "pico ");
		   strcat(command, buffer);
		   system(command);
		   break;
	 case 'r': cout << "Run what? " << endl;
		   cin >> command;
		   system(command);
		   break;
	 case 'c': cout << "Change to? " << endl;
		   cin >> command;
		   chdir(command);
		   break;
	}
	
	
    }
  
}
