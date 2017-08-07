/*
 * Gene.h
 *
 *  Created on: Feb 18, 2013
 *      Author: john
 */

#ifndef GENE_H_
#define GENE_H_

#include <vector>
#include "Chromosome.h"

class Gene {
public:
	Gene(Chromosome *chrome, int gene);
	int getCourse();
	int getRoom();
	int getTeacher();
	int getDuration();
	int getTime();
private:
	Chromosome *chrome;
	int gene;
};

#endif /* GENE_H_ */
