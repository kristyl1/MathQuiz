
//Assignment 5 - Math Quiz
//Kristy Lee

#include <iostream>
#include <fstream> //file io
#include <conio.h>
#include <vector>
#include <string>


using namespace std;

int main()
{
	cout << "Welcome to the Math Quiz! \n";

	//Designate folder & vector string
	string MathQuiz = "C:\\Temp\\Quiz.txt";
	string MathResult = "C:\\Temp\\QuizResults.txt";	
	
	//Read the questions from the text file 
	vector<string>problems;
	string number;
	ifstream ifs(MathQuiz);
	while (getline(ifs, number))
	{
		problems.push_back(number);
	}
	ifs.close();
	
	//Save the questions to a text file
	const int Questions = 3;
	int User;
	ofstream ofs(MathResult);
	for (int i = 0; i < Questions; i++)
	{
		//Generate random numbers
		srand(time(NULL));
		int randomNumber = rand() % 10 + 1;

		//Display random math questions
		cout << "\nQuestion " << (i + 1) << ": " << problems[randomNumber] << " =\n" << "Enter your Answer: ";

		//Allow user to type in their answer
		cin >> User;

		//Save the question and user input to QuizResult.txt
		ofs << problems[randomNumber] << " = " << User << endl;
	}
	ofs.close();

	//Display saved messaged, when completed
	cout << "\nResults saved to QuizResults.txt";

	(void)_getch();
	return 0; 
}