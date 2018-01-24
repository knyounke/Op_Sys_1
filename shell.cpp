#include <string>
#include <vector>
#include <exception>
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
	}
	
    }
  
}
