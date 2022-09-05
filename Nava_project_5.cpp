// Nava_project_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Alex Nava
/*This program is inteded to act a a menu for the user to interact with movei rating given by reviewers. There are 4 reviewers and each reviewers reviews 6 movies and rates then from 1-5.
the program is inteded to display a table shoig the values wihtin an array, get the highest or biggest value, get the average value, 
get the lowest or smallest value, and even let the user change the values and data within the array. This program uses 2-d arrays to achieve this and also uses function to organize and effiecianlty run the code.*/

#include <iostream>	//console
#include <cstdlib>	//random library
#include <iomanip>	//formatting

using namespace std;

const int NUM_REVIEWERS = 4;   //Number of rows in reviews array
const int NUM_MOVIES = 6;      //Number of columns in reviews array    	

void getNewRatings(int [][NUM_MOVIES]);		    //Get new reviewer rating values into the 2-D array
void displayRatings(const int someArray[][NUM_MOVIES]);      //Display current values in the 2-D array
void showAverageRatings(const int [][NUM_MOVIES]);  //Calculate average for each column in the 2-D array
void showReviewersHighestRating(const int [][NUM_MOVIES], int); //Highest value in a row in the 2-D array
void showLowestRating(const int[][NUM_MOVIES], int); //Lowest rating of a movie

int main()
{
 // Variable declarations
 int ratings[NUM_REVIEWERS][NUM_MOVIES] = 
 {
		{3,1,5,2,1,5},
		{4,2,1,4,2,4},
		{3,1,2,4,4,1},
		{5,1,4,2,4,2}
 };; // Ratings for reviewers
 int choice;	//user choice 1-5
 int reviewerNum;	//program 3 
 int MovieNum;		//program 4


	do{
		 //program interface with menu options
	cout << "---------------------------------------------------" << endl;
	cout << "2-D ARRAY PROCESSING MENU OPTIONS" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "1. Display current movie ratings" << endl;
	cout << "2. Show the average rating for each movie." << endl;
	cout << "3. Show a reviewers highest rated movie/s. (enter reviewer# 1-4)" << endl;
	cout << "4. Show a movies lowest rating. (enter movie# 100-105)" << endl;
	cout << "5. Enter new ratings (1-5) for movie# 100-105 for four reviewers" << endl;
	cout << "6. Quit program"<< endl;
	cout << endl << "Enter your choice:";
	cin >> choice;

		switch (choice)
		{
			  //calls to various functions in each case

		case(1):
			displayRatings(ratings);
			break;
		case(2):
			displayRatings(ratings);
			showAverageRatings(ratings);
			break;
		case(3):
			displayRatings(ratings);
			cout << "Enter a reviewer number (1-4), to find the Movie they rated the highest: ";
			cin >> reviewerNum;
			
			showReviewersHighestRating(ratings, reviewerNum);
			break;
		case(4):
			displayRatings(ratings);
			cout << "Enter a movie number (100-105), to find the lowest rating: ";
			cin >> MovieNum;

			showLowestRating(ratings, MovieNum);
			break;
		case(5):
			getNewRatings(ratings);
			break;
		}

		//input validation with failstate
		while (choice < 1 || choice > 6 || !cin) {
			cin.clear();
			cin.ignore('\n', 100);
			cout << "That is an invalid choice." << endl;
			cout << "Enter your choice(1-6): ";
			cin >> choice;

		}
	}while(choice != 6);	//do while loop

 return 0;
}

void displayRatings(const int disArray[][NUM_MOVIES]) {
	//function is used to display the current rating
	/*pre: an initialized set of ratings within the array, const array variables
	* post: displays the current array in a tble with reviewer number and movie number
	*/
	cout << "\n********************* MOVIE RATINGS ****************" << endl;
	cout << "REVIEWER|  MV#100 MV#101 MV#102 MV#103 MV#104 MV#105" << endl;
	cout << "****************************************************" << endl;
	
	for (int index = 0; index < NUM_REVIEWERS; index++) {

		cout << " #" << index + 1 << "    ";
		for (int index2 = 0; index2 < NUM_MOVIES; index2++) {
			cout << setw(7) << disArray[index][index2] << "";
		}
		cout << endl;
	}
	

}
void showAverageRatings(const int avgArray[][NUM_MOVIES]){
	//Function is used t0 caculate the avergae of the a reviewers ratings, it will get a row and caculate the average of the row
	/*pre: const array variables, user chooses this function array has been initialized
	* post: will display the average number for each reviewer or row in the array
	*/
	double Avg;
	double total;
	int movNum = 100;
	
	cout << "****************************************************" << endl;

	cout << "Average rating for each movie: " << endl;

	for (int index = 0; index < NUM_MOVIES; index++) {
		 total = 0;
		

		for (int index2 = 0; index2 < NUM_REVIEWERS; index2++) {
			total += avgArray[index2][index];
			
		}
		Avg = total / NUM_REVIEWERS;
		
		cout << "Movie#" << movNum << ": " << Avg << endl;
		movNum++;
	}

	

}
void showReviewersHighestRating(const int highestArray[][NUM_MOVIES], int choice) {
	//this function displays the highest score of the reviewer that the user chose to see
	/*pre: user chooses a valid choice, array has been initialized
	*/
	while (choice < 1 || choice > 4 || !cin) {
		cin.clear();
		cin.ignore('\n', 100);
		cout << "That is an invalid reviewer number." << endl;
		cout << "Enter a reviewer number (1-4), to find the Movie they rated the highest: ";
		cin >> choice;
	}

	int highest = 0;
	int mv = 0 ;
	int mv2;
	int multiHighest = 0;
	int secondHigh;
	

	for (int index2 = 0; index2 < NUM_MOVIES; index2++) {

		if (highestArray[choice - 1][index2] > highest) {
			highest = highestArray[choice - 1][index2];
			mv = index2;
		}
		else if (highestArray[choice - 1][index2] == highest) {
			multiHighest++;
			secondHigh = highestArray[choice - 1][index2];
			mv2 = index2;
		}

	}
		cout << "Reviewer#" << choice << " rated Movie#10" << mv;
		if (multiHighest > 1) {
			cout << " and" << " 10" << mv2;

		}
		cout << " as the highest" << endl;

	
}
void showLowestRating(const int lowestArray[][NUM_MOVIES], int choice) {
	//this function displays the lowest ratings that a movie of the user's choosing has 
	/*pre:user choice is valid and is withi 100 - 105, array has been initialized
	* post: displays the lowest value within the column of the array
	*/
	int lowest = lowestArray[0][choice - 100];

	for (int index = 0; index < NUM_REVIEWERS; index++) {
		if (lowestArray[index][choice - 100] < lowest) {
			lowest = lowestArray[index][choice - 100];
		}
	}

	cout << "Movie#" << choice << " has the lowest rating of " << lowest << endl;
}
void getNewRatings(int newArray[][NUM_MOVIES]) {
	//this functions allows the user to input data into the array
	/*pre: array has been initialized, user chooses this function
	* post: array has new values and can give new data to the user
	*/
	int temp;
	cout << "********DATA ENTRY FOR NEW MOVIE RATINGS ***********\n";

	//partially complete algorithm to test input interface for new ratings to be entered but the user
	for (int row = 0; row < NUM_REVIEWERS; row++)//to process rows
	{
		cout << "****************************************************\n";
		cout << "REVIEWER# " << (row + 1) << ":\n";
		cout << "****************************************************\n";
		for (int col = 0; col < NUM_MOVIES; col++)//to process a single row using the columns
		{
			cout << "Enter rating (1-5) for movie#" << (col + 100) << ": ";
			cin >> temp;
			while (temp < 1 || temp > 5 || !cin) {
				cin.clear();
				cin.ignore('\n', 10);
				cout << "That is an invalid rating." << endl;
				cout << "Enter your choice(1-5): ";
				cin >> temp;

			}
			newArray[row][col] = temp;


		}
	}

	
}
//Enter a movie number (100-105), to find the lowest rating: