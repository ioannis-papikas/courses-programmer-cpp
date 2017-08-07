/*
 * Program.h
 *
 *  Created on: Feb 18, 2013
 *      Author: john
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <vector>
#include <algorithm>
#include "Chromosome.h"

class Program {
public:
	Program(int size);
	Chromosome *getChrome(int pos);
	void addChrome(Chromosome *chr);
	int getSize();
	void sortChromes();
	void setChrome(int i, Chromosome *chr);
	std::vector<Chromosome> chromes;
private:
	int size;
};

#endif /* PROGRAM_H_ */
