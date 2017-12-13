/*
A basic main function for testing assignment 4.

Author:		Larry Henschen
Last Modified:	Oct 5, 2016 (Sara Sood)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

#include "Lineup.h"
#include "functions.h"


string* cmd_line = new string; //a string to store each line, one at a time
string* parsed_line = new string[100]; //an array of strings

Lineup* currlineup = new Lineup();


string firstnames[14] = { "Vic", "Dererk", "Charlie", "Isiah", "Rapolas", "Scottie", "Tino", "Jordan", "Barret", "Bryant", "Nathan", "Sanjay", "Aaron", "Gavin" };
string lastnames[14] = { "Law", "Pardon", "Hall", "Brown", "Ivanauskas", "Lindsey", "Malnati", "Ash", "Benson", "McIntosh", "Taphorn", "Lumpkin", "Falzon", "Skelly" };
int playernumbers[14] = { 4, 5, 10, 12, 14, 20, 21, 23, 25, 30, 32, 34, 35, 44 };

int ftp = 0; //used to determine if a free throw will add a possession to Northwestern or opponent

int sub = 0; //if there were substitutions, this variable will indicate the need to change currlineup/update stats

int nshot = 0; //if the last thing to happen was a Northwestern missed shot (for ambiguous rebounds)

int oppshot = 0; // if the last thing to happen was an opponent missed shot (for ambiguous rebounds)

const int NO_MATCH = 200;

const int NO_SUB = 100;
int subin1 = NO_SUB;
int subin2 = NO_SUB;
int subin3 = NO_SUB;
int subin4 = NO_SUB;
int subin5 = NO_SUB;
int subout1 = NO_SUB;
int subout2 = NO_SUB;
int subout3 = NO_SUB;
int subout4 = NO_SUB;
int subout5 = NO_SUB;

string northwestern = "Northwestern";
string opponent;
int p1;
int p2;
int p3;
int p4;
int p5;


int main() {

	int numlineups = 0;
	currlineup->set_in_time(20.0);

	ifstream* inp = new ifstream;

	inp->open("test.txt", ios::in);
	if (!inp->is_open()) {
		cout << "***Could not open file.";
		return 0;
	}


	int line_number = 1;
	bool done;

	cout << "Who is Northwestern's opponent? (Spell exactly as on play-by-play)" << endl;
	cin >> opponent;
	cout << "Enter Northwestern starting lineup player numbers:" << endl;
	cout << "Player 1: ";
	cin >> p1;
	cout << "Player 2: ";
	cin >> p2;
	cout << "Player 3: ";
	cin >> p3;
	cout << "Player 4: ";
	cin >> p4;
	cout << "Player 5: ";
	cin >> p5;

	int starters_array[5] = { p1, p2, p3, p4, p5 };
	currlineup->substitution(p1, currlineup->lineup_array[0]);
	currlineup->substitution(p2, currlineup->lineup_array[1]);
	currlineup->substitution(p3, currlineup->lineup_array[2]);
	currlineup->substitution(p4, currlineup->lineup_array[3]);
	currlineup->substitution(p5, currlineup->lineup_array[4]);
	
	

	Lineup l1 = Lineup(starters_array);
	Lineup l2 = Lineup();
	Lineup l3 = Lineup();
	Lineup l4 = Lineup();
	Lineup l5 = Lineup();
	Lineup l6 = Lineup();
	Lineup l7 = Lineup();
	Lineup l8 = Lineup();
	Lineup l9 = Lineup();
	Lineup l10 = Lineup();
	Lineup l11 = Lineup();
	Lineup l12 = Lineup();
	Lineup l13 = Lineup();
	Lineup l14 = Lineup();
	Lineup l15 = Lineup();
	Lineup l16 = Lineup();
	Lineup l17 = Lineup();
	Lineup l18 = Lineup();
	Lineup l19 = Lineup();
	Lineup l20 = Lineup();
	Lineup l21 = Lineup();
	Lineup l22 = Lineup();
	Lineup l23 = Lineup();
	Lineup l24 = Lineup();
	Lineup l25 = Lineup();
	Lineup l26 = Lineup();
	Lineup l27 = Lineup();
	Lineup l28 = Lineup();
	Lineup l29 = Lineup();
	Lineup l30 = Lineup();

	Lineup all_lineups[30] = { l1, l2, l3, l4, l5, l6, l7, l8, l9, l10, l11, l12, l13, l14, l15, l16, l17, l18, l19, l20, l21, l22, l23, l24, l25, l26, l27, l28, l29, l30 };

	

	do {
		if (getline(*inp, *cmd_line))
		{
			done = false; //we were able to get a line, so we're not done
		}
		else
		{
			done = true; //failed to get a line, so we're done
		}

		if (!done) //we have a line to process
		{
			parseLine(*cmd_line, parsed_line);
			accumulate_curr();
		}
			

	} while (!done);
				/*else if (parsed_line[3] == "IN") { //if a new player is coming in
					nshot = 0;
					oppshot = 0;
					if (subin1 == NO_SUB) { //if he is the first player being subbed in
						subin1 = convert_string_to_int(parsed_line[0]);
					}
					else if (subin2 == NO_SUB) { //if he is the 2nd player being subbed in
						subin2 = convert_string_to_int(parsed_line[0]);
					}
					else if (subin3 == NO_SUB) { //if he is the 3rd player being subbed in
						subin3 = convert_string_to_int(parsed_line[0]);
					}
					else if (subin4 == NO_SUB) { //if he is the 4th player being subbed in
						subin4 = convert_string_to_int(parsed_line[0]);
					}
					else { //if he is the 5th player being subbed in
						subin5 = convert_string_to_int(parsed_line[0]);
					}
				}
				else if (parsed_line[3] == "OUT") { //if the player is coming out
					if (subin1 != NO_SUB) { //if this player is the first player being subbed out
						subout1 = convert_string_to_int(parsed_line[0]);
					}
					else if (subin2 != NO_SUB) { //if the player is the 2nd being subbed out
						subout2 = convert_string_to_int(parsed_line[0]);
					}
					else if (subin3 != NO_SUB) { //if the player is the 3rd being subbed out
						subout3 = convert_string_to_int(parsed_line[0]);
					}
					else if (subin4 != NO_SUB) { //if the player is the 4th being subbed out
						subout4 = convert_string_to_int(parsed_line[0]);
					}
					else if (subin5 != NO_SUB) { //if the player is the 5th being subbed out
						subout5 = convert_string_to_int(parsed_line[0]);
					}
					else {
						cout << "Shit. Trying to sub somebody out with nobody to sub in: ";
						cout << "This is your problem: ";
						for (int i = 0; i < 30; i++) {
							cout << parsed_line[i] << " ";
						}
						cout << endl;
					}
					sub = 1;
				}
			} 
				****************************************
						else if (parsed_line[3] == "IN") { //if a new player is coming in
							nshot = 0;
							oppshot = 0;
							continue;
						}
						else if (parsed_line[3] == "OUT") { //if the player is coming out
							continue;
						}
					}
				}
				else if ((parsed_line[0])[1] == ':' || (parsed_line[0])[2] == ':') {
					if (sub == 1) {
						currlineup->set_out_time(parsed_line[0]);
						int sub_index = first_match(currlineup, all_lineups);
						if (sub_index == NO_MATCH) { //if this is the first time the existing lineup has been on the floor in this game
							numlineups++;
							if (numlineups == 29) {
								break;
								cout << "fuck u u stupid bitch" << endl;
							}
						sub_index = first_empty(all_lineups); //make a new lineup for this group in the array
						}
						if (sub_index == NO_MATCH) { //if I fucked up
						cout << "Fuck. Too many lineups or first_empty/first_match isn't working. ";
						cout << "This is your problem: ";
						for (int i = 0; i < 30; i++) {
							cout << parsed_line[i] << " ";
						}
						cout << endl;
						}
						update(currlineup, all_lineups[sub_index]); //puts this stretch of stats into the all_lineups array
						currlineup->clear_stats(); //clears the currlineup stats
						currlineup->set_in_time(parsed_line[0]); //sets in time for new lineup
						currlineup->substitution(subin1, subout1); //subs in the first (or only) player
						subout1 = NO_SUB;
						subin1 = NO_SUB;
						if (subout2 != NO_SUB) { //if there's a second player, sub him in
							currlineup->substitution(subin2, subout2);
							subout2 = NO_SUB;
							subin2 = NO_SUB;
						}
						if (subout3 != NO_SUB) { //if there's a 3rd player, sub him in too
							currlineup->substitution(subin3, subout3);
							subout3 = NO_SUB;
							subin3 = NO_SUB;
						}
						if (subout4 != NO_SUB) { //if there's a 4th player, sub him in
							currlineup->substitution(subin4, subout4);
							subout4 = NO_SUB;
							subin4 = NO_SUB;
						}
						if (subout5 != NO_SUB) { //if there's a 5th player, why not
							currlineup->substitution(subin5, subout5);
							subout5 = NO_SUB;
							subin5 = NO_SUB;
						}
						sub = 0;
					}
					else {
						continue;
					}
				}
				else if (parsed_line[0] == "HALFTIME") {
					nshot = 0;
					oppshot = 0;
					currlineup->set_out_time(0);
					int sub_index = first_match(currlineup, all_lineups);
					if (sub_index == NO_MATCH) { //if this is the first time the existing lineup has been on the floor in this game
						numlineups++;
						if (numlineups == 29) {
							break;
							cout << "fuck u u stupid bitch" << endl;
						}
						sub_index = first_empty(all_lineups); //make a new lineup for this group in the array

					}
					if (sub_index == NO_MATCH) { //if I fucked up
						cout << "Fuck. Too many lineups or first_empty/first_match isn't working: ";
						cout << "This is your problem: ";
						for (int i = 0; i < 30; i++) {
							cout << parsed_line[i] << " ";
						}
						cout << endl;
					}
					update(currlineup, all_lineups[sub_index]); //puts this stretch of stats into the all_lineups array
					currlineup->clear_stats(); //clears the currlineup stats
					cout << "First half complete." << endl;
					cout << "Is second half lineup same as starting lineup, yes or no?" << endl;
					string ans;
					cin >> ans;
					if (ans[0] == 'Y' || ans[0] == 'y') { //if the second half starters are the same as the first half
						currlineup = new Lineup(starters_array);
					}
					else {
						cout << "Enter Northwestern second half starting lineup player numbers:" << endl;
						cout << "Player 1: ";
						cin >> p1;
						cout << "Player 2: ";
						cin >> p2;
						cout << "Player 3: ";
						cin >> p3;
						cout << "Player 4: ";
						cin >> p4;
						cout << "Player 5: ";
						cin >> p5;
						int second_starters[5] = { p1, p2, p3, p4, p5 };
						currlineup = new Lineup(second_starters);
					}
					currlineup->set_in_time(20);
				} 
				******************************************
				else {
					cout << "You're not accounting for ";
					for (int i = 0; i < 30; i++) {
						cout << parsed_line[i] << " ";
					}
					cout << endl;
				} */
					

			cout << "NU points: " << currlineup->get_total_points() << endl;
			cout << "NU FGA: " << currlineup->get_total_fga() << endl;
			cout << "NU FGM: " << currlineup->get_total_fgm() << endl;
			cout << "NU 3PA: " << currlineup->get_total_tpa() << endl;
			cout << "NU 3PM: " << currlineup->get_total_tpm() << endl;
			cout << "NU FTA: " << currlineup->get_total_fta() << endl;
			cout << "NU FTM: " << currlineup->get_total_ftm() << endl;
			cout << "NU asst: " << currlineup->get_total_assists() << endl;
			cout << "NU OREB: " << currlineup->get_total_oreb() << endl;
			cout << "NU DREB: " << currlineup->get_total_dreb() << endl;
			cout << "NU PF: " << currlineup->get_total_fouls() << endl;
			cout << "NU TO: " << currlineup->get_total_turnovers() << endl << endl;
			cout << "OPP points: " << currlineup->get_opp_total_points() << endl;
			cout << "OPP FGA: " << currlineup->get_opp_total_fga() << endl;
			cout << "OPP FGM: " << currlineup->get_opp_total_fgm() << endl;
			cout << "OPP 3PA: " << currlineup->get_opp_total_tpa() << endl;
			cout << "OPP 3PM: " << currlineup->get_opp_total_tpm() << endl;
			cout << "OPP FTA: " << currlineup->get_opp_total_fta() << endl; 
			cout << "OPP FTM: " << currlineup->get_opp_total_ftm() << endl; 
			cout << "OPP asst: " << currlineup->get_opp_total_assists() << endl;
			cout << "OPP OREB: " << currlineup->get_opp_total_oreb() << endl;
			cout << "OPP DREB: " << currlineup->get_opp_total_dreb() << endl;
			cout << "OPP PF: " << currlineup->get_opp_total_fouls() << endl;
			cout << "OPP TO: " << currlineup->get_opp_total_turnovers() << endl; 
			cout << "That's all, folks.";

			delete inp;
			delete cmd_line;
			delete[] parsed_line;
			delete currlineup;
		}

void accumulate_curr() {
	if ((parsed_line[0]).length() <= 2 && isdigit((parsed_line[0])[0])) { //if first token is player number
		if (parsed_line[1] == firstnames[find(convert_string_to_int(parsed_line[0]), playernumbers)] && parsed_line[2] == lastnames[find(convert_string_to_int(parsed_line[0]), playernumbers)]) { //if second and third tokens match NU player name
			if (parsed_line[3] == "LAYUP" || parsed_line[3] == "JUMPER" || parsed_line[3] == "DUNK") { //if the NU player took a 2 point shot
				ftp = 0;
				if (parsed_line[4] == "GOOD") { //if he made it
					currlineup->add_fgm();
					nshot = 0;
					oppshot = 0;
				}
				else { //if he missed
					currlineup->add_fga();
					nshot = 1;
					oppshot = 0;
				}
			}
			else if (parsed_line[3] == "3PTR") { //if he took a 3ptr
				ftp = 0;
				if (parsed_line[4] == "GOOD") { //if he made it
					currlineup->add_tpm();
					nshot = 0;
					oppshot = 0;
				}
				else { //if he missed
					currlineup->add_tpa();
					nshot = 1;
					oppshot = 0;
				}
			}
			else if (parsed_line[3] == "Assist") { //if the player made an assist
				ftp = 0;
				currlineup->add_assist();
			}
			else if (parsed_line[3] == "BLOCK") { //if the player made a block
				ftp = 0;
				currlineup->add_block();
			}
			else if (parsed_line[3] == "FOUL") { //if the player committed a foul
				ftp = 1;
				currlineup->add_foul();
				nshot = 0;
				oppshot = 0;
			}
			else if (parsed_line[3] == "OFF." && parsed_line[4] == "REBOUND") { //if he got an off. rebound
				ftp = 0;
				currlineup->add_oreb();
				nshot = 0;
				oppshot = 0;
			}
			else if (parsed_line[3] == "DEF." && parsed_line[4] == "REBOUND") { //if he got a def. rebound
				ftp = 0;
				currlineup->add_dreb();
				nshot = 0;
				oppshot = 0;
			}
			else if (parsed_line[3] == "FT") { //if he is shooting a free throw
				if (ftp == 1) { //if the last thing to happen was a foul (this is the first free throw)
					currlineup->add_possession();
					if (parsed_line[4] == "GOOD") { //if he makes the free throw
						currlineup->add_ftm();
						nshot = 0;
						oppshot = 0;
					}
					else { //if he missed
						currlineup->add_fta();
						nshot = 1;
						oppshot = 0;
					}
					ftp = 0;
				}
				else { //if the last thing to happen was another free throw
					if (parsed_line[4] == "GOOD") { //if he makes the free throw
						currlineup->add_ftm();
						nshot = 0;
						oppshot = 0;
					}
					else { //if he missed
						currlineup->add_fta();
						nshot = 1;
						oppshot = 0;
					}
				}
			}
		}
		else { //if it is a non-Northwestern player
			if (parsed_line[3] == "LAYUP" || parsed_line[3] == "JUMPER" || parsed_line[3] == "DUNK") { //if the opp player took a 2 point shot
				ftp = 0;
				if (parsed_line[4] == "GOOD") { //if he made it
					currlineup->add_opp_fgm();
					nshot = 0;
					oppshot = 0;
				}
				else { //if he missed
					currlineup->add_opp_fga();
					nshot = 0;
					oppshot = 1;
				}
			}
			else if (parsed_line[3] == "3PTR") { //if he took a 3ptr
				ftp = 0;
				if (parsed_line[4] == "GOOD") { //if he made it
					currlineup->add_opp_tpm();
					nshot = 0;
					oppshot = 0;
				}
				else { //if he missed
					currlineup->add_opp_tpa();
					nshot = 0;
					oppshot = 1;
				}
			}
			else if (parsed_line[3] == "Assist") { //if the player made an assist
				ftp = 0;
				currlineup->add_opp_assist();
			}
			else if (parsed_line[3] == "BLOCK") { //if the player made a block
				ftp = 0;
				currlineup->add_opp_block();
			}
			else if (parsed_line[3] == "FOUL") { //if the player committed a foul
				ftp = 1;
				currlineup->add_opp_foul();
				nshot = 0;
				oppshot = 0;
			}
			else if (parsed_line[3] == "OFF." && parsed_line[4] == "REBOUND") { //if he got an off. rebound
				ftp = 0;
				currlineup->add_opp_oreb();
				nshot = 0;
				oppshot = 0;
			}
			else if (parsed_line[3] == "DEF." && parsed_line[4] == "REBOUND") { //if he got a def. rebound
				ftp = 0;
				currlineup->add_opp_dreb();
				nshot = 0;
				oppshot = 0;
			}
			else if (parsed_line[3] == "FT") { //if he is shooting a free throw
				if (ftp == 1) { //if the last thing to happen was a foul (this is the first free throw)
					currlineup->add_opp_possession();
					if (parsed_line[4] == "GOOD") { //if he makes the free throw
						currlineup->add_opp_ftm();
						nshot = 0;
						oppshot = 0;
					}
					else { //if he missed
						currlineup->add_opp_fta();
						nshot = 0;
						oppshot = 1;
					}
					ftp = 0;
				}
				else { //if the last thing to happen was another free throw
					if (parsed_line[4] == "GOOD") { //if he makes the free throw
						currlineup->add_opp_ftm();
						nshot = 0;
						oppshot = 0;
					}
					else { //if he missed
						currlineup->add_opp_fta();
						nshot = 0;
						oppshot = 1;
					}
				}
			}
		}
	}
	if (parsed_line[0] == "Media") {
		nshot = 0;
		oppshot = 0;
	}
	else if (parsed_line[0] == northwestern) {
		if (parsed_line[1] == "REBOUND") {
			if (nshot == 1) {
				currlineup->add_oreb();
			}
			else {
				currlineup->add_dreb();
			}
		}
		else if (parsed_line[1] == "TURNOVER") {
			currlineup->add_turnover();
		}
	}
	else if (parsed_line[0] == opponent) {
		if (parsed_line[1] == "REBOUND") {
			if (oppshot == 1) {
				currlineup->add_opp_oreb();
			}
			else {
				currlineup->add_opp_dreb();
			}
		}
		else if (parsed_line[1] == "TURNOVER") {
			currlineup->add_opp_turnover();
		}
	}
	for (int i = 0; i < 99; i++) {
		if (parsed_line[i] != "") {
			parsed_line[i] = "";
		}
	}
}