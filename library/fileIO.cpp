#include <iostream>
#include <fstream>

#include "../includes_usr/constants.h"
#include "../includes_usr/datastructures.h"
#include "../includes_usr/fileIO.h"
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char *filename) {
	ofstream myfile;
	myfile.open(filename);

	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	} else if (books.size() == 0) {
		return NO_BOOKS_IN_LIBRARY;
	}

	while (!myfile.eof()) {
			getline(myfile, line); //get a line from the file Name, Midterm,Final
			ss.str(line);

			//get rid of the old values
			myStudentData.clear();

			//!!!!!! NO ERROR CHECK HERE DONT ASSUMME PERFECT DATA 		!!!!!!
			//!!!!!! if any of the following fail retValue should		!!!!!!
			//!!!!!! be set to false, break out of loop, then return;	!!!!!!

			//get the name
			getline(ss, myStudentData.name, char_to_search_for);

			//get midterm
			getline(ss, token, char_to_search_for);
			myStudentData.midterm = stringToInt(token.c_str());

			//get final
			getline(ss, token, char_to_search_for);
			myStudentData.final = stringToInt(token.c_str());

			//finally add to array
			allstudentData.push_back(myStudentData);

			//clear stream so it will work for next read
			ss.clear();

	myfile.close();

	return SUCCESS;
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char *filename) {
	ofstream myfile;
	myfile.open(filename);

	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}
	string mydata;
		for (int var = 0; var < books.size(); ++var) {
			mydata = to_string(books[var].book_id) + ',' + books[var].title +
					',' + books[var].author + ',' + to_string(books[var].state)
					+ ',' + to_string(books[var].loaned_to_patron_id);
			myfile << mydata << std::endl;
		}
    if (myfile.is_open()) {
    	myfile.close();
    }
	return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char *filename) {
	ofstream myfile;
	myfile.open(filename);

	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	} else if (patrons.size() == 0) {
		return NO_PATRONS_IN_LIBRARY;
	}
	myfile.close();
	return SUCCESS;
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char *filename) {
	ofstream myfile;
	myfile.open(filename);

	if (!myfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}
	myfile.close();
	return SUCCESS;
}
