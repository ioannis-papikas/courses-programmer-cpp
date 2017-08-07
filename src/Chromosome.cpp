/*
 * Chromosome.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: john
 */

#include "Chromosome.h"

Chromosome::Chromosome(int size) {
	this->size = size;
	this->score = 1000;
	this->geneLength = 13;
	this->initialize();
}

void Chromosome::initialize() {
	// Initialize size
	this->chrome.clear();
	this->chrome.resize(this->size);
}

void Chromosome::set(std::vector<int> chrome) {
	for (int i=0; i<this->size; i++)
		this->chrome[i] = chrome[i];
}

int Chromosome::get(int i) {
	return this->chrome[i];
}

std::vector<int> Chromosome::get() {
	return this->chrome;
}

void Chromosome::print() {
	for (int i=0; i<this->size; i++)
		printf("%d", this->chrome[i]);
	printf(" %d", this->score);
}

int Chromosome::getScore() {
	return this->score;
}
void Chromosome::setScore(int score) {
	this->score = score;
}

int Chromosome::getCourse(int gene){
	int n1, n2, n3;
	int pos = 0;
	int init = gene*this->geneLength;
	n1 = this->chrome[init + pos + 0];
	n2 = this->chrome[init + pos + 1];
	n3 = this->chrome[init + pos + 2];
	return this->toInt(n1, n2, n3);
}

int Chromosome::getRoom(int gene){
	int n1, n2, n3;
	int pos = 3;
	int init = gene*this->geneLength;
	n1 = this->chrome[init + pos + 0];
	n2 = this->chrome[init + pos + 1];
	n3 = this->chrome[init + pos + 2];
	return this->toInt(n1, n2, n3);
}
int Chromosome::getTeacher(int gene){
	int n1, n2, n3;
	int pos = 6;
	int init = gene*this->geneLength;
	n1 = this->chrome[init + pos + 0];
	n2 = this->chrome[init + pos + 1];
	n3 = this->chrome[init + pos + 2];
	return this->toInt(n1, n2, n3);
}
int Chromosome::getDuration(int gene){
	int n1, n2;
	int pos = 9;
	int init = gene*this->geneLength;
	n1 = this->chrome[init + pos + 0];
	n2 = this->chrome[init + pos + 1];
	return n1 + n2;
}
int Chromosome::getDaytime(int gene){
	int n1, n2;
	int pos = 11;
	int init = gene*this->geneLength;
	n1 = this->chrome[init + pos + 0];
	n2 = this->chrome[init + pos + 1];
	return this->toInt(0, n1, n2);
}
int Chromosome::toInt(int n1, int n2, int n3) {
	return 100*n1 + 10*n2 + n3;
}
