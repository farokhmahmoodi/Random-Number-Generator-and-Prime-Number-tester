#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

//function that determines if numbers in created file are prime or not
bool isAPrime(int randNum1_100){

   for (int i = 2; i<randNum1_100-1; i++){
       if (randNum1_100 % i == 0)
          return false;
   }
	 return true;
   }

void createFile(){ //Output File Creation

//Variables
int randNum1_20; //First random number of created file ranging from 1-20
int randNum1_100; //Random number generated in created file ranging from 1-100

	string filename; //User inputed file name

	cout<<"Enter the name of the output file: \n";
	getline(cin, filename);
	ofstream outputfile;
	outputfile.open(filename.c_str());
	srand(time(NULL));
	if(outputfile.is_open()){ //If the file is opened
		randNum1_20=rand()%20+1; //Generate random number from 1-20
		cout<<randNum1_20<<endl;
		outputfile<<randNum1_20<<endl;
		for(int i=0; i<randNum1_20; i++){ //Determines how many other random numbers generated
			randNum1_100=rand()%100+1; //Generates random numbers from 1-100
			cout<<randNum1_100<<endl;

			outputfile<<randNum1_100;
			if(i< randNum1_20 -1)
				outputfile<<endl;
		}
		outputfile.close();
	  cout<<"The data has been written to the file "<<filename<<"!"<<endl;
		}
	else{ //If the file cannot be opened display error message
	  cout<<"Unable to write data to "<<filename<<"!"<<endl;
	}
}

void readFile(){ //Input File Data Reader

string filename;
int randNum1_20;
int randNum1_100;
int count;
int primes[30];
  	cout << "Enter the name of the input file: \n";
	getline(cin, filename);
    ifstream inputfile(filename.c_str());
    if (inputfile.is_open()){  //If the file is opened

	  inputfile >> randNum1_20; //Tells program how many numbers are in file
	  count = 0;
	  int sum = 0;
	   	  for (int i = 0; i<randNum1_20; i++){
		      inputfile >> randNum1_100;

		 if (isAPrime(randNum1_100)){ //function for determining prime numbers
		    int found = 0;

		   for (int j = 0; j<count; j++){
			   if (primes[j] == randNum1_100){ //If numbers in file are not prime
		           found = 1;
		               break;
		             }

		         }
		       if (found == 0) //If numbers in file are prime
		       {

		          primes[count] = randNum1_100;
		          sum = sum + randNum1_100;
		          count++;
		      }
		   }

		}
	    inputfile.close();
double average = sum/count; //Average of prime numbers in numbers generated
cout << "The average of the primes in "<<filename<<" is " << average<<
" and their sum is " << sum << endl;
	}
    else{  //If the file does not open display error message
    	 cout << "Error opening file! \n";
    }
}
int main(){ //Execution of program
cout<<"Welcome to the Happy File data reader! \n";
   createFile();
   readFile();
   return 0;
}
