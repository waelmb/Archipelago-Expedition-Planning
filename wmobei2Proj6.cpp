/*
*	wmobei2Proj6.cpp
*	A program for Archipelago Expedition Planning
*
****************************************/
//#include "Island.cpp"
#include "proj6.h"

class ArchipelagoExpedition
{
 private:
   Island* islands; 
   int size;
   char** files; 
   int sizeFiles;
   int filesInUse;
  
 public:
  
 // Use a constructor to initialize the Data Members for your expedition
 ArchipelagoExpedition()
 {
  size = 11;
  islands = new Island[size];
  sizeFiles = 10;
  filesInUse = 0;
  files = new char*[sizeFiles];
 }
  
  
 // The main loop for reading in input
 void processCommandLoop (FILE* inFile)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input
    
  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions 
    char* command;
    command = strtok (input , " \n\t");

    printf ("*%s*\n", command);
    
    if ( command == NULL ) {
    	printf ("Blank Line\n");	
	}
 
    else if ( strcmp (command, "q") == 0) {
    	//deallocate islands and files
		for(int i = 1; i < size; i++) {
			islands[i].removeAll();	
		}
		
    	delete islands;
    	delete files;
    	exit(1);	
	}

    else if ( strcmp (command, "?") == 0) {
    	showCommands();	
	} 
      
     
    else if ( strcmp (command, "t") == 0) {
    	doTravel();	
	}
      
     
    else if ( strcmp (command, "r") == 0) {
    	doResize();	
	}

    else if ( strcmp (command, "i") == 0) {
    	doInsert();
	}
      
    else if ( strcmp (command, "d") == 0) {
    	doDelete();	
	} 
      
    else if ( strcmp (command, "l") == 0) {
    	doList();	
	}

    else if ( strcmp (command, "f") == 0) {
    	doFile();	
	}

    else if ( strcmp (command, "#") == 0) {
    	;	
	}
     
    else {
    	printf ("Command is not known: %s\n", command);
	}
      
     
    input = fgets ( buffer, 300, inFile );   // get the next line of input

  }
 }

 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }
 
 void doTravel()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   printf ("Performing the Travel Command from %d to %d\n", val1, val2);
   
    //if islands are within range
    if(val1 < 1 || val2 < 1 ) {
    	printf("Islands can't be numbered less than 1\n'");
	}
	else {
		if(size >= val1 && size >= val2) {	
			//Perform the depth-first-search algorithm
			depthFirstSearchHelper(val1, val2);
		}
		else {
			//report that values are out of range
			printf("Islands specified are out of the current range of %d\n'", size);
		}
	}
   
 }
 
 void depthFirstSearchHelper(int x, int y) {
	//mark all islands as unvisited
	for(int i = 1; i < size; i++) {
	 	islands[i].setIsVisited(false);
    }
    
    if(dfs(x, y)) {
    	printf ("You can get from island %d to %d in one or more ferry rides\n", x, y);
	}
	else {
		printf ("You CANNOT get from island %d to %d in one or more ferry rides\n", x, y);	
	}
 }
 
 bool dfs(int a, int b) {
 	for(int i = 0; i < islands[a].getListLength(); i++) {
 		int c = islands[a].getNthValue(i);
 		
 		if(c == b) {
 			return true;
		 }
		if(islands[c].getIsVisited() == false) {
			islands[c].setIsVisited(true);
			if(dfs(c, b)) {
				return true;
			}
		}
	 }
	 return false;
 }
 
 void doResize()
 {
   int val1 = 0;
   
   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   printf ("Performing the Resize Command with %d\n", val1 );
   
   //if the value is greater than 0
   if(val1 > 0) {
		//remove all items of the dynamic array
		//deallocate all used nodes
		for(int i = 1; i < size; i++) {
			islands[i].removeAll();	
		}
		
		delete islands;
		
		//create the new dyarr
		size = val1 + 1;
		islands = new Island[size];
   }
   //if less than zero
   else{
   		//report an error
   		printf ("Expected a value greater than zero\n");
   }
   		
   

 }
 
 int larger(int a, int b) {
 	if(a > b) {
 		return a;
	 }
	 else {
	 	return b;
	 }
 }
 
 void doInsert()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   
   printf ("Performing the Insert Command from %d to %d\n", 
            val1, val2);
            
	//if either of the values is less than one, ignore it
	if(val1 < 1 || val2 < 1) {
		printf("Islands can't be numbered less than 1\n'");
	}
	else {
		//if the islands are in-range
		if(size > val1 && size > val2) {
			//insert the edge from island 1 to island 2
			islands[val1].add(val2);
		}
		else {
			//report an error
			printf ("Islands specificed are out of range\n");
		}
		
			
	}
 }
 
 void doDelete()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   
   printf ("Performing the Delete Command from %d to %d\n", val1, val2);
   
    //if islands are within range
    if(val1 < 1 || val2 < 1 ) {
    	printf("Islands can't be numbered less than 1\n'");
	}
	else {
		if(size >= val1 && size >= val2) {
			//if edge exists
			if(islands[val1].edgeExist(val2)) {
				//delete it
				islands[val1].remove(val2);
				printf ("There edge from %d to %d has been deleted\n", val1, val2);
			}
			//else
			else {
				//report that it doesn't exist
				printf ("There is no edge from %d to %d\n", val1, val2);
			}
				
			
		}
		else {
			//report that values are out of range
			printf("Islands specified are out of the current range of %d\n'", size);
		}
	}
 }
 
 void doList()
 {
	printf ("listing all the items contained in the archipelagoexpedition: \n");
		
   for(int i = 1; i < size; i++) {
   	printf ("Island %d rides: ", i);
   	islands[i].showList();
   	printf ("\n");
   }
 }
 
 void doFile()
 {
   // get a filename from the input
   char* fname = strtok (NULL, "\r\n\t");
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }
   
   printf ("Performing the File command with file: %s\n", fname);
   
   // next steps:  (if any step fails: print an error message and return ):
   //  1. verify the file name is not currently in use
   //  2. open the file using fopen creating a new instance of FILE*
   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
   //  4. close the file when processCommandLoop() returns
   bool fileExists = false;
   for(int i = 0; i < filesInUse; i++) {
		if(strcmp (fname, files[i]) == 0) {
			fileExists = true;
		}
   }
   
   //make sure the file hasn't been used before
   if(fileExists) {
   		printf ("File is already in use\n");	
   }
   else {
		//open the file if it exists
		FILE* pFile = fopen(fname, "r");
		if(pFile == NULL) {
			printf ("File didn't open correctly: (%s)\n", fname);
			return;
		}
		else {
			//grow the dynamic array if needed
			if(filesInUse == sizeFiles-1) {
				sizeFiles = sizeFiles * 2;
				char** tmp = files;
				files = new char*[sizeFiles];
				
				//copy the values from temp to the resized islands
				for(int i = 0; i < filesInUse; i++) {
					files[i] = tmp [i];
				}
				
				delete tmp;
			}
			
			//add the file name to the list
			files[filesInUse] = fname;
			filesInUse++;
			
			//call recursively
			this->processCommandLoop(pFile);
			
			//close the file
			fclose(pFile);
		}
   }
 }
};


int main (int argc, char** argv)
{
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the island adjcency list
  ArchipelagoExpedition islandData;
   
  // call the method that reads and parses the input
  islandData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  islandData.processCommandLoop (inFile);
   
  printf ("Goodbye\n");
  return 1;
 }
