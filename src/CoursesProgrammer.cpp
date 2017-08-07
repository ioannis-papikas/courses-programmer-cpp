//============================================================================
// Name        : CoursesProgrammer.cpp
// Author      : Papikas Ioannis
// Version     :
// Copyright   : 
// Description : Course Programmer, Ansi-style
//============================================================================

#include <iostream>
#include "CourseManager.h"
using namespace std;

int main() {
	// Create a new CourseManager
	int courses = 5;
	int teachers = 20;
	int rooms = 10;

	// Create initial population
	CourseManager *GACourseManager = new CourseManager(courses, teachers, rooms);

	// Initialize GA
	int epoch = 0;
	int MAX_EPOCH = 200;
	int errorScore = 1000;

	// And there be... EVOLUTION
	while (errorScore > 50 && epoch < MAX_EPOCH) {

		// 0. Get random position for crosscheck
		int crossPos = rand() % 100 % (GACourseManager->getChromeSize());

		// 1. Order the chromosomes
		GACourseManager->sortChromes();

		// 2. Take the 2 first as the elite
		// Keep and not cross

		// 3. Choose the next 8 randomly to populate
		for (int i=0; i<4; i++) {
			int toPopulate1, toPopulate2;
			do {
				toPopulate1 = rand() % 8;
				toPopulate2 = rand()  % 8;

				if (toPopulate1 != toPopulate2)
					GACourseManager->crosscheck(toPopulate1 + 2, toPopulate2 + 2 ,crossPos);
			} while (toPopulate1 == toPopulate2);
		}

		// 4. Check for mutations
		// We have no mutations at this round

		// 5. Re-initialize the population
		GACourseManager->CalculateScore();
		GACourseManager->sortChromes();

		// 6. Calculate the max score and the average
		int maxScore = GACourseManager->getChrome(0)->getScore();

		int sumScore = 0;
		for (int i=0; i<GACourseManager->getPopSize(); i++) {
			sumScore += GACourseManager->getChrome(i)->getScore();
		}
		int avgScore = sumScore / GACourseManager->getPopSize();

		// 7. Check the error tolerance
		errorScore = 1000.0 - maxScore;
		printf("SCORE | max / average / error : %d / %d / %d\n", maxScore, avgScore, errorScore);
		// 8. Go to next epoch
		epoch++;
	}

	return 0;
}
