/*
	This file contains functions used at the system and main level.
	
	Author:		Larry Henschen
	Last Modified:	Oct 21, 2016 (Sara Sood)
*/



#include <fstream>
#include <string>
#include <cctype>
#include <iostream>
#include <string>
#include "Lineup.h"
#include "functions.h"

using namespace std;


void parseLine(string line, string tklist[]) {
	string* newstring = new string;
	int ntokens = 0;
	int stringsize = line.length();
	for (int i = 0; i < (stringsize - 1); i++) {
		if (line[i] == ' ') {
			continue;
		}
		else {
			int h = i;
			while (h < line.length() && line[h] != ' ') {
				*newstring += line[h];
				h++;
			}
			tklist[ntokens] = *newstring;
			ntokens++;
			i = h;
			*newstring = "";
		}
	}
	delete newstring;
}


void order_lineup(int lu[]) {
	for (int i = 0; i < 5; i++) {
		int dummy = 0;
		if (lu[0] > lu[1]) {
			dummy = lu[0];
			lu[0] = lu[1];
			lu[1] = dummy;
		}
		if (lu[1] > lu[2]) {
			dummy = lu[1];
			lu[1] = lu[2];
			lu[2] = dummy;
		}
		if (lu[2] > lu[3]) {
			dummy = lu[2];
			lu[2] = lu[3];
			lu[3] = dummy;
		}
		if (lu[3] > lu[4]) {
			dummy = lu[3];
			lu[3] = lu[4];
			lu[4] = dummy;
		}
	}
}

int convert_string_to_int(string s) 
{
	int number = 0; 
	for (size_t i = 0; i < s.length(); i++) {
		number = number * 10 + (s[i] - '0');
	}
	return number;
}

double convert_time(string st) 
{
	string minutes = "";
	string seconds = "";
	int m = 0; 
	double s = 0; 
	if (isdigit(st[1])) {
		minutes = st[0] + st[1]; 
		seconds = st[3] + st[4]; 
		m = convert_string_to_int(minutes);
		s = convert_string_to_int(seconds) / 60; 
		return m + s; 
	}
	else {
		minutes = st[0]; 
		seconds = st[2] + st[3]; 
		m = convert_string_to_int(minutes); 
		s = convert_string_to_int(seconds) / 60; 
		return m + s; 
	}
}

int find(int num, int n[])
{
	for (int i = 0; i < 14; i++) {
		if (n[i] == num) {
			return i;
		} 
	}
}

void update(Lineup* curr, Lineup real)
{
	real.set_possessions(curr->get_possessions());
	real.set_fga(curr->get_total_fga());
	real.set_turnovers(curr->get_total_turnovers());
	real.set_fgm(curr->get_total_fgm());
	real.set_tpa(curr->get_total_tpa());
	real.set_tpm(curr->get_total_tpm());
	real.set_twopa(curr->get_total_twopa());
	real.set_twopm(curr->get_total_twopm());
	real.set_fta(curr->get_total_fta());
	real.set_ftm(curr->get_total_ftm());
	real.set_points(curr->get_total_points());
	real.set_assists(curr->get_total_assists());
	real.set_rebounds(curr->get_total_rebounds());
	real.set_oreb(curr->get_total_oreb());
	real.set_dreb(curr->get_total_dreb());
	real.set_steals(curr->get_total_steals());
	real.set_blocks(curr->get_total_blocks());
	real.set_fouls(curr->get_total_fouls());

	real.set_fg_pct();
	real.set_ft_pct();

	real.set_opp_possessions(curr->get_opp_possessions());
	real.set_opp_fga(curr->get_opp_total_fga());
	real.set_opp_turnovers(curr->get_opp_total_turnovers());
	real.set_opp_fgm(curr->get_opp_total_fgm());
	real.set_opp_tpa(curr->get_opp_total_tpa());
	real.set_opp_tpm(curr->get_opp_total_tpm());
	real.set_opp_twopa(curr->get_opp_total_twopa());
	real.set_opp_twopm(curr->get_opp_total_twopm());
	real.set_opp_fta(curr->get_opp_total_fta());
	real.set_opp_ftm(curr->get_opp_total_ftm());
	real.set_opp_points(curr->get_opp_total_points());
	real.set_opp_assists(curr->get_opp_total_assists());
	real.set_opp_rebounds(curr->get_opp_total_rebounds());
	real.set_opp_oreb(curr->get_opp_total_oreb());
	real.set_opp_dreb(curr->get_opp_total_dreb());
	real.set_opp_steals(curr->get_opp_total_steals());
	real.set_opp_blocks(curr->get_opp_total_blocks());
	real.set_opp_fouls(curr->get_opp_total_fouls());
	
	real.set_opp_fg_pct();
	real.set_opp_ft_pct();

	real.set_in_time(curr->get_in_time());
	real.set_out_time(curr->get_in_time());
}

int first_empty(Lineup l[])
{
	for (int i = 0; i < 30; i++) {
		int empty_array[5] = {};
		if ((l[i]).lineup_array == empty_array) {
			return i;
			break; 
		}
		else {
			return 200;
		}
	}
}

int first_match(Lineup* curr, Lineup l[])
{
	for (int i = 0; i < 30; i++) {
		if (curr->lineup_array == (l[i]).lineup_array) {
			return i; 
		}
		else {
			return 200; 
		}
	}
}