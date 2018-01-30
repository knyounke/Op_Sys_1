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
#include <fstream>
#include <sys/stat.h>
#include <exception>

// Katherine Younke
// CSE 3320-003
// LAB 1


using namespace std;

bool is_a_file(const string file)
{
  bool is_file;
	DIR * dir;
	struct dirent * f;
	if((dir = opendir(".")) != NULL){
		while((f = readdir(dir)) != NULL){
			if(f->d_name == file)
			{
				return true;
			}
			else{
				return false;}
		}
	}	
	
}

bool can_execute(const string file)
{
	struct stat st;
	if(stat(file.c_str(), &st) < 0)
		return false;
	if((st.st_mode & S_IEXEC) != 0)
		return true;
	return false;



}


int main(void){
   pid_t child; //process id
   DIR * directory;
   struct dirent * directory_entry;
   int i, j;
   string k;
   string buffer, command; //buffers for command and string
   time_t time;
   char* const* args;

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
	if(j > 8){
		if( ( j % 8 ) == 0) {
		  cout << "Hit N for Next" << endl; 
		  cin >> k;
		}
		}
	}
	closedir(directory);
	cout << "------------------------------------" << endl;
	getline(cin, k);
	

	if(k == "q")
	  exit(0);
	else if(k == "e"){
		while(true){
	 	cout << "Edit What? " << endl;
		   cin >> buffer;
		//check to see if buffer is actually in the directory before opening in the editor	   
			if(is_a_file(buffer) == true){
		  	 command = "pico ";
		   	command += buffer;
// instead of "system(command.c_str());" which calls another shell instead of making system calls
			fork(); execv(command.c_str(), args);
		  	
			break;
			}
			else
			{
			cout << buffer << " is not a file. Try again, please." << endl;
			}
		  }
		
		}

	 else if(k == "r"){
		while(true){
		   cout << "Run what? " << endl;
		   cin >> command;
		
			//check to see if the file is actually executable
				if(can_execute(command) == true)
				{	
					fork(); execv(command.c_str(), args); break;// system(command.c_str()); break;
				}
				else
				{

					cout << command << " is not an executable. Please try again." << endl << endl;
				}
			}

		}
		  
		   
	 else if(k == "c"){
	 	 cout << "Change to? " << endl;
		   cin >> command;
		   try {chdir(command.c_str());}
			catch(exception e)
			{ cout << "Path could not be reached. Please try another path." << endl; }
		   }
	else
		{
		cout << "ERROR. Incorrect entry!" << endl << endl;
	}
	
	
    }
  
}
