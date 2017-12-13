#include "Lineup.h"
#include "functions.h"
#include <string>
#include <iostream>
using namespace std; 

Lineup::Lineup() 
{
	for (int i = 0; i < 5; i++) {
		lineup_array[i] = 0;
	}
	minutes_played = 0;
	pace = 0;

	possessions = 0;
	total_fga = 0;
	total_turnovers = 0;
	total_fgm = 0;
	total_tpa = 0;
	total_tpm = 0;
	total_twopa = 0;
	total_twopm = 0;
	total_fta = 0;
	total_ftm = 0;
	total_points = 0;
	total_assists = 0;
	total_rebounds = 0;
	total_oreb = 0;
	total_dreb = 0;
	total_steals = 0;
	total_blocks = 0;
	total_fouls = 0;
	fg_pct = 0;
	tpfg_pct = 0;
	twopfg_pct = 0;
	ft_pct = 0;

	opp_possessions = 0;
	opp_total_fga = 0;
	opp_total_turnovers = 0;
	opp_total_fgm = 0;
	opp_total_tpa = 0;
	opp_total_tpm = 0;
	opp_total_twopa = 0;
	opp_total_twopm = 0;
	opp_total_fta = 0;
	opp_total_ftm = 0;
	opp_total_points = 0;
	opp_total_assists = 0;
	opp_total_rebounds = 0;
	opp_total_oreb = 0;
	opp_total_dreb = 0;
	opp_total_steals = 0;
	opp_total_blocks = 0;
	opp_total_fouls = 0;
	opp_fg_pct = 0;
	opp_tpfg_pct = 0;
	opp_twopfg_pct = 0;
	opp_ft_pct = 0;
}

Lineup::Lineup(int lu[]) 
{
	for (int i = 0; i < 5; i++) {
		order_lineup(lu);
		lineup_array[i] = lu[i];
	}
	minutes_played = 0;
	pace = 0;

	possessions = 0;
	total_fga = 0;
	total_turnovers = 0;
	total_fgm = 0;
	total_tpa = 0;
	total_tpm = 0;
	total_twopa = 0;
	total_twopm = 0;
	total_fta = 0;
	total_ftm = 0;
	total_points = 0;
	total_assists = 0;
	total_rebounds = 0;
	total_oreb = 0;
	total_dreb = 0;
	total_steals = 0;
	total_blocks = 0;
	total_fouls = 0;
	fg_pct = 0;
	tpfg_pct = 0;
	twopfg_pct = 0;
	ft_pct = 0;

	opp_possessions = 0;
	opp_total_fga = 0;
	opp_total_turnovers = 0;
	opp_total_fgm = 0;
	opp_total_tpa = 0;
	opp_total_tpm = 0;
	opp_total_twopa = 0;
	opp_total_twopm = 0;
	opp_total_fta = 0;
	opp_total_ftm = 0;
	opp_total_points = 0;
	opp_total_assists = 0;
	opp_total_rebounds = 0;
	opp_total_oreb = 0;
	opp_total_dreb = 0;
	opp_total_steals = 0;
	opp_total_blocks = 0;
	opp_total_fouls = 0;
	opp_fg_pct = 0;
	opp_tpfg_pct = 0;
	opp_twopfg_pct = 0;
	opp_ft_pct = 0;
}

void Lineup::display_lineup()
{
	for (int i = 0; i < 5; i++) {
		cout << "Player " << i + 1 << ": " << lineup_array[i] << endl; 
	}
}

void Lineup::clear_stats()
{
	minutes_played = 0;
	pace = 0;

	possessions = 0;
	total_fga = 0;
	total_turnovers = 0;
	total_fgm = 0;
	total_tpa = 0;
	total_tpm = 0;
	total_twopa = 0;
	total_twopm = 0;
	total_fta = 0;
	total_ftm = 0;
	total_points = 0;
	total_assists = 0;
	total_rebounds = 0;
	total_oreb = 0;
	total_dreb = 0;
	total_steals = 0;
	total_blocks = 0;
	total_fouls = 0;
	fg_pct = 0;
	tpfg_pct = 0;
	twopfg_pct = 0;
	ft_pct = 0;

	opp_possessions = 0;
	opp_total_fga = 0;
	opp_total_turnovers = 0;
	opp_total_fgm = 0;
	opp_total_tpa = 0;
	opp_total_tpm = 0;
	opp_total_twopa = 0;
	opp_total_twopm = 0;
	opp_total_fta = 0;
	opp_total_ftm = 0;
	opp_total_points = 0;
	opp_total_assists = 0;
	opp_total_rebounds = 0;
	opp_total_oreb = 0;
	opp_total_dreb = 0;
	opp_total_steals = 0;
	opp_total_blocks = 0;
	opp_total_fouls = 0;
	opp_fg_pct = 0;
	opp_tpfg_pct = 0;
	opp_twopfg_pct = 0;
	opp_ft_pct = 0;
}

void Lineup::substitution(int in, int out)
{
	for (int i = 0; i < 4; i++) {
		if (lineup_array[i] == out) {
			lineup_array[i] = in;
			order_lineup(lineup_array);
			break;
		}
	}
}

void Lineup::set_in_time(string time)
{
	in_time = convert_time(time);
}

void Lineup::set_out_time(string time)
{
	out_time = convert_time(time);
	minutes_played += (in_time - out_time);
	pace = 40 * (possessions / minutes_played);
}

void Lineup::set_in_time(double time)
{
	in_time = time; 
}

void Lineup::set_out_time(double time)
{
	out_time = time;
	minutes_played += (in_time - out_time);
	pace = 40 * (possessions / minutes_played);
}

void Lineup::add_possession()
{
	possessions++; 
}

void Lineup::add_fga()
{
	total_fga++;
	possessions++; 
}

void Lineup::add_turnover()
{
	total_turnovers++; 
	possessions++; 
}

void Lineup::add_fgm()
{
	total_fgm++;
	total_fga++;
	possessions++;
	add_points(2); 
	set_fg_pct();
}

void Lineup::add_tpa() {
	total_tpa++;
	total_fga++;
	possessions++;
	set_fg_pct();
}

void Lineup::add_tpm()
{
	total_tpm++;
	total_tpa++; 
	total_fga++; 
	total_fgm++;
	possessions++;
	add_points(3);
	set_fg_pct();
}

void Lineup::add_fta()
{
	total_fta++;
	set_ft_pct();
}

void Lineup::add_ftm()
{
	total_ftm++;
	total_fta++; 
	add_points(1);
	set_ft_pct(); 
}

void Lineup::add_points(int pts)
{
	total_points += pts; 
}

void Lineup::add_assist()
{
	total_assists++; 
}

void Lineup::add_oreb()
{
	total_oreb++;
	total_rebounds++;
	possessions--; 
}

void Lineup::add_dreb()
{
	total_dreb++; 
	total_rebounds++;
}

void Lineup::add_steal()
{
	total_steals++;
}

void Lineup::add_block()
{
	total_blocks++;
}

void Lineup::add_foul()
{
	total_fouls++; 
}

void Lineup::set_fg_pct()
{
	if (total_fga >= 1) {
		fg_pct = total_fgm / total_fga;
		twopfg_pct = (total_fgm - total_tpm) / (total_fga - total_tpa);
	}
	if (total_tpa >= 1) {
		tpfg_pct = total_tpm / total_tpa;
	}
}

void Lineup::set_ft_pct()
{
	if (total_fta >= 0) {
		ft_pct = total_ftm / total_fta;
	}
}

void Lineup::set_opp_possessions(int p)
{
	opp_possessions += p; 
}

void Lineup::set_opp_fga(int f)
{
	opp_total_fga += f; 
}

void Lineup::set_opp_turnovers(int t)
{
	opp_total_turnovers += t; 
}

void Lineup::set_opp_fgm(int f)
{
	opp_total_fgm += f; 
}

void Lineup::set_opp_tpa(int t)
{
	opp_total_tpa += t; 
}

void Lineup::set_opp_tpm(int t)
{
	opp_total_tpm += t; 
}

void Lineup::set_opp_twopa(int t)
{
	opp_total_twopa += t; 
}

void Lineup::set_opp_twopm(int t)
{
	opp_total_twopm += t; 
}

void Lineup::set_opp_fta(int f)
{
	opp_total_fta += f;
}

void Lineup::set_opp_ftm(int f)
{
	opp_total_ftm += f; 
}

void Lineup::set_opp_points(int p)
{
	opp_total_points += p; 
}

void Lineup::set_opp_assists(int a)
{
	opp_total_assists += a; 
}

void Lineup::set_opp_rebounds(int r)
{
	opp_total_rebounds += r; 
}

void Lineup::set_opp_oreb(int o)
{
	opp_total_oreb += o; 
}

void Lineup::set_opp_dreb(int d)
{
	opp_total_dreb += d; 
}

void Lineup::set_opp_steals(int s)
{
	opp_total_steals += s; 
}

void Lineup::set_opp_blocks(int b)
{
	opp_total_blocks += b; 
}

void Lineup::set_opp_fouls(int f)
{
	opp_total_fouls += f; 
}

void Lineup::add_opp_possession()
{
	opp_possessions++;
}

void Lineup::add_opp_fga()
{
	opp_total_fga++;
	opp_possessions++;
}

void Lineup::add_opp_turnover()
{
	opp_total_turnovers++;
	opp_possessions++;
}

void Lineup::add_opp_fgm()
{
	opp_total_fgm++;
	opp_total_fga++;
	opp_possessions++;
	add_opp_points(2);
	set_opp_fg_pct();
}

void Lineup::add_opp_tpa()
{
	opp_total_tpa++;
	opp_total_fga++;
	opp_possessions++;
	set_opp_fg_pct();
}

void Lineup::add_opp_tpm()
{
	opp_total_tpm++;
	opp_total_tpa++;
	opp_total_fga++;
	opp_total_fgm++;
	opp_possessions++;
	add_opp_points(3);
	set_opp_fg_pct();
}

void Lineup::add_opp_fta()
{
	opp_total_fta++;
	set_opp_ft_pct();
}

void Lineup::add_opp_ftm()
{
	opp_total_ftm++;
	opp_total_fta++;
	add_opp_points(1);
	set_opp_ft_pct();
}

void Lineup::add_opp_points(int pts)
{
	opp_total_points += pts;
}

void Lineup::add_opp_assist()
{
	opp_total_assists++;
}

void Lineup::add_opp_oreb()
{
	opp_total_oreb++;
	opp_total_rebounds++;
	opp_possessions--; 
}

void Lineup::add_opp_dreb()
{
	opp_total_dreb++;
	opp_total_rebounds++;
}

void Lineup::add_opp_steal()
{
	opp_total_steals++;
}

void Lineup::add_opp_block()
{
	opp_total_blocks++;
}

void Lineup::add_opp_foul()
{
	opp_total_fouls++;
}

void Lineup::set_possessions(int p)
{
	possessions += p; 
}

void Lineup::set_fga(int f)
{
	total_fga += f; 
}

void Lineup::set_turnovers(int t)
{
	total_turnovers += t;
}

void Lineup::set_fgm(int f)
{
	total_fgm += f; 
}

void Lineup::set_tpa(int t)
{
	total_tpa += t; 
}

void Lineup::set_tpm(int t)
{
	total_tpm += t; 
}

void Lineup::set_twopa(int t)
{
	total_twopa += t; 
}

void Lineup::set_twopm(int t)
{
	total_twopm += t; 
}

void Lineup::set_fta(int f)
{
	total_fta += f; 
}

void Lineup::set_ftm(int f)
{
	total_ftm += f; 
}

void Lineup::set_points(int p)
{
	total_points += p; 
}

void Lineup::set_assists(int a)
{
	total_assists += a;
}

void Lineup::set_rebounds(int r)
{
	total_rebounds += r;
}

void Lineup::set_oreb(int o)
{
	total_oreb += o;
}

void Lineup::set_dreb(int d)
{
	total_dreb += d; 
}

void Lineup::set_steals(int s)
{
	total_steals += s;
}

void Lineup::set_blocks(int b)
{
	total_blocks += b;
}

void Lineup::set_fouls(int f)
{
	total_fouls += f;
}

void Lineup::set_opp_fg_pct()
{
	if (opp_total_fga >= 1) {
		opp_fg_pct = opp_total_fgm / opp_total_fga;
		opp_twopfg_pct = (opp_total_fgm - opp_total_tpm) / (opp_total_fga - opp_total_tpa);
	}
	if (opp_total_tpa >= 1) {
		opp_tpfg_pct = opp_total_tpm / opp_total_tpa;
	}
}

void Lineup::set_opp_ft_pct()
{
	if (opp_total_fta >= 1) {
		opp_ft_pct = opp_total_ftm / opp_total_fta;
	}
}

double Lineup::get_in_time() const
{
	return in_time;
}

double Lineup::get_out_time() const
{
	return out_time;
}

double Lineup::get_minutes_played() const
{
	return minutes_played;
}

double Lineup::get_pace() const
{
	return pace;
}

int Lineup::get_possessions() const
{
	return possessions;
}

int Lineup::get_total_fga() const
{
	return total_fga;
}

int Lineup::get_total_turnovers() const
{
	return total_turnovers;
}

int Lineup::get_total_fgm() const
{
	return total_fgm;
}

int Lineup::get_total_tpa() const
{
	return total_tpa;
}

int Lineup::get_total_tpm() const
{
	return total_tpm;
}

int Lineup::get_total_twopa() const
{
	return (total_fga - total_tpa);
}

int Lineup::get_total_twopm() const
{
	return (total_fgm - total_tpm);
}

int Lineup::get_total_fta() const
{
	return total_fta;
}

int Lineup::get_total_ftm() const
{
	return total_ftm;
}

int Lineup::get_total_points() const
{
	return total_points;
}

int Lineup::get_total_assists() const
{
	return total_assists;
}

int Lineup::get_total_rebounds() const
{
	return total_rebounds;
}

int Lineup::get_total_oreb() const
{
	return total_oreb;
}

int Lineup::get_total_dreb() const
{
	return total_dreb;
}

int Lineup::get_total_steals() const
{
	return total_steals;
}

int Lineup::get_total_blocks() const
{
	return total_blocks;
}

int Lineup::get_total_fouls() const
{
	return total_fouls;
}

double Lineup::get_fg_pct() const
{
	return fg_pct;
}

double Lineup::get_tpfg_pct() const
{
	return tpfg_pct;
}

double Lineup::get_twopfg_pct() const
{
	return twopfg_pct;
}

double Lineup::get_ft_pct() const
{
	return ft_pct;
}

int Lineup::get_opp_possessions() const
{
	return opp_possessions;
}

int Lineup::get_opp_total_fga() const
{
	return opp_total_fga;
}

int Lineup::get_opp_total_turnovers() const
{
	return opp_total_turnovers;
}

int Lineup::get_opp_total_fgm() const
{
	return opp_total_fgm;
}

int Lineup::get_opp_total_tpa() const
{
	return opp_total_tpa;
}

int Lineup::get_opp_total_tpm() const
{
	return opp_total_tpm;
}

int Lineup::get_opp_total_twopa() const
{
	return (opp_total_fga - opp_total_tpa);
}

int Lineup::get_opp_total_twopm() const
{
	return (opp_total_fgm - opp_total_tpm);
}

int Lineup::get_opp_total_fta() const
{
	return opp_total_fta;
}

int Lineup::get_opp_total_ftm() const
{
	return opp_total_ftm;
}

int Lineup::get_opp_total_points() const
{
	return opp_total_points;
}

int Lineup::get_opp_total_assists() const
{
	return opp_total_assists;
}

int Lineup::get_opp_total_rebounds() const
{
	return opp_total_rebounds;
}

int Lineup::get_opp_total_oreb() const
{
	return opp_total_oreb;
}

int Lineup::get_opp_total_dreb() const
{
	return opp_total_dreb;
}

int Lineup::get_opp_total_steals() const
{
	return opp_total_steals;
}

int Lineup::get_opp_total_blocks() const
{
	return opp_total_blocks;
}

int Lineup::get_opp_total_fouls() const
{
	return opp_total_fouls;
}

double Lineup::get_opp_fg_pct() const
{
	return opp_fg_pct;
}

double Lineup::get_opp_tpfg_pct() const
{
	return opp_tpfg_pct;
}

double Lineup::get_opp_twopfg_pct() const
{
	return opp_twopfg_pct;
}

double Lineup::get_opp_ft_pct() const
{
	return opp_ft_pct;
}

double Lineup::get_fga_per_100() const
{
	return (100 * (total_fga / possessions));
}

double Lineup::get_turnovers_per_100() const
{
	return (100 * (total_turnovers / possessions));
}

double Lineup::get_tpa_per_100() const
{
	return (100 * (total_tpa / possessions));
}

double Lineup::get_twopa_per_100() const
{
	return (100 * ((total_fga - total_tpa) / possessions)); 
}

double Lineup::get_fta_per_100() const
{
	return (100 * (total_fta / possessions));
}

double Lineup::get_points_per_100() const
{
	return (100 * (total_points / possessions));
}

double Lineup::get_assists_per_100() const
{
	return (100 * (total_assists / possessions));
}

double Lineup::get_rebounds_per_100() const
{
	return (100 * (total_rebounds / possessions));
}

double Lineup::get_oreb_per_100() const
{
	return (100 * (total_oreb / possessions));
}

double Lineup::get_dreb_per_100() const
{
	return (100 * (total_dreb / possessions));
}

double Lineup::get_steals_per_100() const
{
	return (100 * (total_steals / possessions));
}

double Lineup::get_blocks_per_100() const
{
	return (100 * (total_blocks / possessions));
}

double Lineup::get_fouls_per_100() const
{
	return (100 * (total_fouls / possessions));
}

double Lineup::get_opp_fga_per_100() const
{
	return (100 * (opp_total_fga / possessions));
}

double Lineup::get_opp_turnovers_per_100() const
{
	return (100 * (opp_total_turnovers / possessions));
}

double Lineup::get_opp_tpa_per_100() const
{
	return (100 * (opp_total_tpa / possessions));
}

double Lineup::get_opp_twopa_per_100() const
{
	return (100 * ((opp_total_fga - opp_total_tpa) / possessions));
}

double Lineup::get_opp_fta_per_100() const
{
	return (100 * (opp_total_fta / possessions));
}

double Lineup::get_opp_points_per_100() const
{
	return (100 * (opp_total_points / possessions));
}

double Lineup::get_opp_assists_per_100() const
{
	return (100 * (opp_total_assists / possessions));
}

double Lineup::get_opp_rebounds_per_100() const
{
	return (100 * (opp_total_rebounds / possessions));
}

double Lineup::get_opp_oreb_per_100() const
{
	return (100 * (opp_total_oreb / possessions));
}

double Lineup::get_opp_dreb_per_100() const
{
	return (100 * (opp_total_dreb / possessions));
}

double Lineup::get_opp_steals_per_100() const
{
	return (100 * (opp_total_steals / possessions));
}

double Lineup::get_opp_blocks_per_100() const
{
	return (100 * (opp_total_blocks / possessions));
}

double Lineup::get_opp_fouls_per_100() const
{
	return (100 * (opp_total_blocks / possessions));
}
