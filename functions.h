/*
	This file contains functions used at the system and main level.
	
	Author:		Larry Henschen
	Last Modified:	Oct 21, 2016 (Sara Sood)
 */

#include <string>
#include "Lineup.h"



using namespace std;

void parseLine(string line, string tklist[]);

void order_lineup(int lu[]);

int convert_string_to_int(string s);

double convert_time(string st); 

int find(int num, int n[]); 

void update(Lineup* curr, Lineup real);

int first_empty(Lineup l[]); 

int first_match(Lineup* curr, Lineup l[]); 

void accumulate_curr();