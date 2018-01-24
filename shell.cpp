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
   char * string, command; //buffers for command and string
   time_t time;

   while(true){
	cout<< "Time: "<< ctime(&time) << endl;
	}

}
