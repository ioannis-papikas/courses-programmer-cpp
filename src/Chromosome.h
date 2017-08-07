/*
 * Chromosome.h
 *
 *  Created on: Feb 18, 2013
 *      Author: john
 */

#ifndef CHROMOSOME_H_
#define CHROMOSOME_H_

#include <vector>

class Chromosome {
public:
	Chromosome(int size);
	void getSize();
	void set(std::vector<int> chrome);
	void print();
	std::vector<int> get();
	int get(int i);
	int getScore();
	void setScore(int score);
	int getCourse(int gene);
	int getRoom(int gene);
	int getTeacher(int gene);
	int getDuration(int gene);
	int getDaytime(int gene);
private:
	int size, score, geneLength;
	std::vector<int> chrome;
	void initialize();
	int toInt(int n1, int n2, int n3);
};

#endif /* CHROMOSOME_H_ */
