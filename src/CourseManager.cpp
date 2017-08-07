/*
 * CourseManager.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: john
 */

#include "CourseManager.h"
#include "Gene.h"

CourseManager::CourseManager(int courses, int rooms, int teachers) {
	// Initialize variables
	this->courses = courses;
	this->rooms = rooms;
	this->teachers = teachers;
	this->geneSize = 13;
	this->chromeSize = this->geneSize * this->courses * 2;

	// Initialize gene
	//_____ Calculate Gene size
	// 3 for A/A of course
	// 3 for Room
	// 3 for Teacher
	// 2 for hour1 (2 hours) and hour2 (1 hour)
	// 2 for hour of day, from 00 to 59
	// -------------
	// Total = 13 (+)

	// Create Gene
	this->program = new Program(10);
	srand (time(NULL));
	// Create 10 chromosomes and randomize
		for (int i=0; i<10; i++) {
			// Create chromosome
			Chromosome *chrCourse = new Chromosome(this->chromeSize);

			// Parse every course and randomize (init with 2 hours and 1 hour)
			std::vector<int> chr;

			for (int j=0; j<this->courses*2; j++) {
				int f, s, t;

				// 3 for A/A of course
				int k = j/2;
				f = k / 100;
				chr.push_back(f);
				s = (k / 10) % 10;
				chr.push_back(s);
				t = (k % 10);
				chr.push_back(t);

				// 3 for room
				//srand (time(NULL));
				int room = (rand() % 100) % this->rooms;
				k = room;
				f = k / 100;
				chr.push_back(f);
				s = (k / 10) % 10;
				chr.push_back(s);
				t = (k % 10);
				chr.push_back(t);

				// 3 for teacher
				int teacher = (rand() % 100) % this->teachers;
				k = teacher;
				f = k / 100;
				chr.push_back(f);
				s = (k / 10) % 10;
				chr.push_back(s);
				t = (k % 10);
				chr.push_back(t);

				// 2 for time duration
				int hour2 = (rand() % 10) % 2;
				int hour1 = (rand() % 10) % 2;
				chr.push_back(hour2);
				chr.push_back(hour1);

				// 2 for time and day
				int daytime = (rand() % 100) % 60;
				k = daytime;
				s = (k / 10) % 10;
				chr.push_back(s);
				t = (k % 10);
				chr.push_back(t);
			}
			chrCourse->set(chr);
			this->calculateScore(chrCourse);
			this->program->addChrome(chrCourse);
		}
}
int CourseManager::getChromeSize() {
	return this->chromeSize;
}

int CourseManager::getPopSize() {
	return this->program->getSize();
}

Chromosome *CourseManager::getChrome(int pos) {
	return this->program->getChrome(pos);
}

void CourseManager::crosscheck(int chr1, int chr2, int pos) {
	Chromosome *c1 = this->program->getChrome(chr1);
	Chromosome *c2 = this->program->getChrome(chr2);
	std::vector<int> vc1_new;
	std::vector<int> vc2_new;

	// Crosscheck
	for (int i=0; i<this->geneSize * this->courses * 2; i++) {
		if (i < pos) {
			vc1_new.push_back(c1->get(i));
			vc2_new.push_back(c2->get(i));
		} else {
			vc1_new.push_back(c2->get(i));
			vc2_new.push_back(c1->get(i));
		}
	}
	c1->set(vc1_new);
	c2->set(vc2_new);
}

void CourseManager::CalculateScore() {
	for (int i=0; i<this->getPopSize(); i++) {
		Chromosome *chr = this->program->getChrome(i);
		this->calculateScore(chr);
	}
}
//void populate(int chr1, int chr2);

void CourseManager::printChromes() {
	for (int i=0; i<this->getPopSize(); i++) {
		Chromosome *chr = this->program->getChrome(i);
		chr->print();
		printf("\n");
	}
}
void CourseManager::sortChromes() {
	this->program->sortChromes();
}

// Fitness Function
void CourseManager::calculateScore(Chromosome *chr) {
	// Initialize score
	int initScore = 1000;
	int bigPenalty = 100;
	int smallPenalty = 30;
	int currentScore = initScore;
	chr->setScore(initScore);

	// Check if everything is valid for every gene
	// for each invalid, take 50 points
	int genes = this->courses*2;
	for (int i=0; i<genes; i++) {
		// Create gene
		Gene *courseGene = new Gene(chr, i);

		// Check course number
		if (courseGene->getCourse() > this->courses)
			currentScore -= bigPenalty;

		// Check room number
		if (courseGene->getRoom() > this->rooms)
			currentScore -= bigPenalty;

		// Check teacher
		if (courseGene->getTeacher() > this->teachers)
			currentScore -= bigPenalty;

		// Check daytime
		if (courseGene->getTime() > 60)
			currentScore -= bigPenalty;
	}

	// Create teacher vector to check teacher course count
	std::vector<int> teachers;
	teachers.resize(this->teachers * this->rooms + 1);

	// Prepare genes for this chromosome
	std::vector<Gene> chrGenes;
	chrGenes.clear();
	//chrGenes.resize(genes);
	for (int i=0; i<genes; i++) {
		Gene *chrgn = new Gene(chr, i);
		chrGenes.push_back(*chrgn);
	}

	// For each gene, check course conflicts
	for (int i=0; i<genes; i++) {
		// Get first gene
		Gene g1 = chrGenes[i];
		int course1 = g1.getCourse();
		int duration1 = g1.getDuration();
		int hour1 = g1.getTime();
		int room1 = g1.getRoom();

		// Check conflicts with the rest genes
		for (int j=i; j<genes; j++) {
			if (i == j)
				continue;
			// Get second gene
			Gene g2 = chrGenes[j];
			int course2 = g2.getCourse();
			int duration2 = g2.getDuration();
			int hour2 = g2.getTime();
			int room2 = g2.getRoom();

			// For the same course
			if (course1 == course2) {
				// Check total duration of the same course
				if ((duration1 + duration2) > 3)
					currentScore -= smallPenalty;

				// Check hour conflict
				int hour12 = hour1 + duration1;
				int hour21 = hour2 + duration2;
				if ((hour1 <= hour2 && hour2 < hour12) || (hour2 <= hour1 && hour1 < hour21))
					currentScore -= bigPenalty;
			}
			else {
				// If the courses are different, check that they are in a different room with no conflict
				if (room1 == room2) {
					int hour12 = hour1 + duration1;
					int hour21 = hour2 + duration2;
					if ((hour1 <= hour2 && hour2 < hour12) || (hour2 <= hour1 && hour1 < hour21))
						currentScore -= smallPenalty;
				}
			}
		}

		// Add course to teacher
		teachers[(i+1) * (course1 + 1)] = 1;
	}

	// For each teacher, count courses
	std::vector<int> teacherCourses;
	teacherCourses.resize(this->teachers);
	for (int i=1; i<=this->teachers; i++)
		for (int j=1; j<=this->courses; j++) {
			teacherCourses[i] += teachers[i*j];

			// For each course more than the limit, small penalty
			if (teachers[i*j] == 1 && teacherCourses[i] > 2)
				currentScore -= smallPenalty;
		}

	// Set Chromosome score
	chr->setScore(currentScore);
}
