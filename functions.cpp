#include "pch.h"
#include "Functions.h"
#include <iostream>

#include <string>

#include <cstdlib>
#include <ctime>

#ifdef unix
#include <unistd.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif

//wait function that is compatible with windows and linux versions

void wait(float time)
{
#ifdef unix
	usleep(1000000 * time);
#endif
#ifdef _WIN32
	Sleep(1000 * time);
#endif
}

int random(int limit)
{
	//changes seed of randomiser

	srand(time(NULL)*rand());

	//randomises number in range of limit with new random seed

	int number = rand() % limit;
	return number;
}

void display(std::string str)
{
	//gets string length

	int length = str.length();

	for (int i = 0; i < length; i++)
	{
		//displays letter at string char index
		std::cout << str.at(i);

		//if statement to check if it is the end of a sentence, if it is, it waits for 1 second, if it isn't, then it wait's for 50 milliseconds
		if (str.at(i) == '?' || str.at(i) == '.' || str.at(i) == ',' || str.at(i) == '!')
		{
			wait(1);

			if (i + 1 < length && str.at(i + 1) != str.at(i))
			{
				std::cout << "\n";

				if (i + 1 < length && str.at(i + 1) == ' ')
				{
					i++;
				}

			}
		}
		else
		{
			wait(0.05);
		}
		
		//flushes out cout chars
		std::cout.flush();
	}

	std::cout << "\n";
}
