// Keywords 2 home.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;




int main()
{
	bool game = true; // keeps game going
	string playagain; // asks if game goes again
	int totalsim = 1;


	while (game == true) {
		const int MAX_WRONG = 8; //number of inccorect guesses allowed


		vector<string> words; // Create a collection of 10 words you had wrote down manually
		words.push_back("hello");
		words.push_back("game");
		words.push_back("mech");
		words.push_back("robot");
		words.push_back("human");
		words.push_back("trial");
		words.push_back("help");
		words.push_back("hanged");
		words.push_back("guess");
		words.push_back("pizza");

		string name; // holds name


		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(words.begin(), words.end());




		int sim = 1; // Create an int var to count the number of simulations being run starting at 1


		

		cout << "Welcome to keywords 2" << endl;	// Display Title of program to user
		cout << "\n Enter your name recuit\n"; // ask for name
		cin >> name; // Display Title of program to user


		cout << "\n\n Keywords 2 is a training simulation similar to hang man."; // Display Title of program to user
		cout << "Guess 1 letter at a time until you either lose or find the correct word"; // Display an directions to the recruit on how to use Keywords

		while (sim != 4) {   // Pick new 3 random words from your collection as the secret code word the recruit has to guess.


			string used = "";   //Letters already guessed


			int wrong = 0;    //number of wrong guesses
			const string THE_WORD = words[sim];     //word to guess
			string soFar(THE_WORD.size(), '-'); // words guessed so far
			cout << "You are on simulation " << sim << endl;   // Display the simulation # is staring to the recruit. 
			char guess = NULL;

			while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {   // While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word

				cout << "You have " << (MAX_WRONG - wrong);		//Tell recruit how many incorrect guesses he or she has left
				cout << " Incorrect guesses left.\n\n";
				cout << "\n You've used the following letters:\n" << used << endl;		//  Show recruit the letters he or she has guessed
				cout << "\nSo far, the word is:\n\n" << soFar << endl;   //   Show player how much of the secret word he or she has guessed


				
				cout << "\n\nEnter your guess: ";//     Get recruit's next guess
				cin >> guess;
				guess = tolower(guess); //make lower case
				while (used.find(guess) != string::npos) {

					cout << "\nYou've already guessed " << guess << ", "<< name << endl; //     While recruit has entered a letter that he or she has already guessed
					cout << "Enter your guess: ";//          Get recruit ’s guess
					cin >> guess;
					guess = tolower(guess);

				}
				used += guess;	//     Add the new guess to the group of used letters

				if (THE_WORD.find(guess) != string::npos) {//     If the guess is in the secret word
					cout << "That is correct " << name << ", "  << guess << " is within the word. \n"; // Tell the recruit the guess is correct

					for (int i = 0; i < THE_WORD.length(); i++) {

						if (THE_WORD[i] == guess) {

							soFar[i] = guess;//          Update the word guessed so far with the new letter

						}



					}


				}
				else {//     Otherwise
					cout << "Sorry, " << guess << " isn't in the word.\n";//          Tell the recruit the guess is incorrect
					++wrong;//          Increment the number of incorrect guesses the recruit has made


				}


			}

			//shut down the game

			if (wrong == MAX_WRONG) {// If the recruit has made too many incorrect guesses

				cout << "\nYou failed your training";//     Tell the recruit that he or she has failed the Keywords II course.
			}


			else {// Otherwise
				cout << "\n YOU WIN" << endl;//     Congratulate the recruit on guessing the secret words

			}


			cout << "\nThe word was " << THE_WORD << endl;
			++sim;
		}
		cout << "\nWould you like to run the simulation again " << name << "?\n\n yes or no";// Ask the recruit if they would like to run the simulation again
		cin >> playagain;


		if (playagain == "yes") {// If the recruit wants to run the simulation again
		
			game = true;//     Move program execution back up to // Display the simulation # is staring to the recruit. 
			++totalsim;//     Increment the number of simiulations ran counter

		}
		else {// Otherwise 
			game = false;
			cout << "You have run a total of " << totalsim << " of simulations." << endl;//     Display End of Simulations to the recruit

		}

	}

    return 0;//     Pause the Simulation with press any key to continue
}

