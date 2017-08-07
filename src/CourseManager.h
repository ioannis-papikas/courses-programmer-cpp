/*
 * CourseManager.h
 *
 *  Created on: Feb 18, 2013
 *      Author: john
 */

#ifndef COURSEMANAGER_H_
#define COURSEMANAGER_H_

#include "Program.h"
#include <vector>

using std::string;

class CourseManager {
public:
	CourseManager(int courses, int rooms, int teachers);
	void calculateScore(Chromosome *chr);
	void CalculateScore();
	void crosscheck(int chr1, int chr2, int pos);
	void printChromes();
	void sortChromes();
	Chromosome *getChrome(int pos);
	int getChromeSize();
	int getPopSize();
private:
	int courses, rooms, teachers;
	int geneSize, chromeSize;
	Program *program;
};

#endif /* COURSEMANAGER_H_ */
