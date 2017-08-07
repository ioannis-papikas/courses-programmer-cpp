/*
 * Program.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: john
 */

#include "Program.h"

bool sortFunc (Chromosome i,Chromosome j) { return (i.getScore()>j.getScore()); }

Program::Program(int size) {
	// Set size
	this->size = size;
}

Chromosome *Program::getChrome(int pos) {
	return &this->chromes[pos];
}

void Program::addChrome(Chromosome *chr) {
	this->chromes.push_back(*chr);
}

void Program::setChrome(int i, Chromosome *chr) {
	this->chromes[i] = *chr;
}

int Program::getSize() {
	return this->size;
}
//sortChromes
void Program::sortChromes() {
	//return this->size;
	std::sort(this->chromes.begin(), this->chromes.end(), sortFunc);
}
