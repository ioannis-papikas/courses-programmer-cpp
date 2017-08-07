/*
 * Gene.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: john
 */

#include "Gene.h"

Gene::Gene(Chromosome *chrome, int gene) {
	this->chrome = chrome;
	this->gene = gene;
}

int Gene::getCourse() {
	return this->chrome->getCourse(this->gene);
}

int Gene::getRoom() {
	return this->chrome->getRoom(this->gene);
}

int Gene::getTeacher() {
	return this->chrome->getTeacher(this->gene);
}

int Gene::getDuration() {
	return this->chrome->getDuration(this->gene);
}

int Gene::getTime() {
	return this->chrome->getDaytime(this->gene);
}
