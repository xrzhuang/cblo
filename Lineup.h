#ifndef LINEUP_H
#define LINEUP_H


#include <string>
#include <iostream>

using namespace std; 

class Lineup {
public:
	Lineup();
	Lineup(int lu[]);

	int lineup_array[5];
	void display_lineup();

	void clear_stats();

	void substitution(int in, int out);

	void set_in_time(string time); 
	void set_out_time(string time);
	void set_in_time(double time);
	void set_out_time(double time);

	void add_possession();
	void add_fga();
	void add_turnover(); 
	void add_fgm();
	void add_tpa(); 
	void add_tpm(); 
	void add_fta(); 
	void add_ftm(); 
	void add_points(int pts);
	void add_assist();
	void add_oreb();
	void add_dreb(); 
	void add_steal();
	void add_block();
	void add_foul(); 

	void add_opp_possession();
	void add_opp_fga();
	void add_opp_turnover();
	void add_opp_fgm();
	void add_opp_tpa();
	void add_opp_tpm();
	void add_opp_fta();
	void add_opp_ftm();
	void add_opp_points(int pts);
	void add_opp_assist();
	void add_opp_oreb();
	void add_opp_dreb();
	void add_opp_steal();
	void add_opp_block(); 
	void add_opp_foul();

	void set_possessions(int p);
	void set_fga(int f);
	void set_turnovers(int t);
	void set_fgm(int f);
	void set_tpa(int t);
	void set_tpm(int t);
	void set_twopa(int t);
	void set_twopm(int t);
	void set_fta(int f);
	void set_ftm(int f);
	void set_points(int p);
	void set_assists(int a);
	void set_rebounds(int r);
	void set_oreb(int o);
	void set_dreb(int d);
	void set_steals(int s);
	void set_blocks(int b);
	void set_fouls(int f);

	void set_fg_pct();
	void set_ft_pct();

	void set_opp_possessions(int p);
	void set_opp_fga(int f);
	void set_opp_turnovers(int t);
	void set_opp_fgm(int f);
	void set_opp_tpa(int t);
	void set_opp_tpm(int t);
	void set_opp_twopa(int t);
	void set_opp_twopm(int t);
	void set_opp_fta(int f);
	void set_opp_ftm(int f);
	void set_opp_points(int p);
	void set_opp_assists(int a);
	void set_opp_rebounds(int r);
	void set_opp_oreb(int o);
	void set_opp_dreb(int d);
	void set_opp_steals(int s);
	void set_opp_blocks(int b);
	void set_opp_fouls(int f);

	void set_opp_fg_pct();
	void set_opp_ft_pct();

	double get_in_time() const; 
	double get_out_time() const; 
	double get_minutes_played() const; 

	double get_pace() const; 

	int get_possessions() const;
	int get_total_fga() const;
	int get_total_turnovers() const;
	int get_total_fgm() const;
	int get_total_tpa() const;
	int get_total_tpm() const;
	int get_total_twopa() const;
	int get_total_twopm() const;
	int get_total_fta() const;
	int get_total_ftm() const;
	int get_total_points() const;
	int get_total_assists() const;
	int get_total_rebounds() const;
	int get_total_oreb() const;
	int get_total_dreb() const;
	int get_total_steals() const; 
	int get_total_blocks() const;
	int get_total_fouls() const;
	double get_fg_pct() const;
	double get_tpfg_pct() const;
	double get_twopfg_pct() const;
	double get_ft_pct() const;

	int get_opp_possessions() const; 
	int get_opp_total_fga() const;
	int get_opp_total_turnovers() const;
	int get_opp_total_fgm() const;
	int get_opp_total_tpa() const;
	int get_opp_total_tpm() const;
	int get_opp_total_twopa() const;
	int get_opp_total_twopm() const;
	int get_opp_total_fta() const;
	int get_opp_total_ftm() const;
	int get_opp_total_points() const;
	int get_opp_total_assists() const;
	int get_opp_total_rebounds() const;
	int get_opp_total_oreb() const;
	int get_opp_total_dreb() const;
	int get_opp_total_steals() const; 
	int get_opp_total_blocks() const;
	int get_opp_total_fouls() const;
	double get_opp_fg_pct() const;
	double get_opp_tpfg_pct() const;
	double get_opp_twopfg_pct() const;
	double get_opp_ft_pct() const;

	double get_fga_per_100() const;
	double get_turnovers_per_100() const;
	double get_tpa_per_100() const;
	double get_twopa_per_100() const;
	double get_fta_per_100() const;
	double get_points_per_100() const;
	double get_assists_per_100() const;
	double get_rebounds_per_100() const;
	double get_oreb_per_100() const;
	double get_dreb_per_100() const;
	double get_steals_per_100() const;
	double get_blocks_per_100() const;
	double get_fouls_per_100() const;

	double get_opp_fga_per_100() const;
	double get_opp_turnovers_per_100() const;
	double get_opp_tpa_per_100() const;
	double get_opp_twopa_per_100() const;
	double get_opp_fta_per_100() const;
	double get_opp_points_per_100() const;
	double get_opp_assists_per_100() const;
	double get_opp_rebounds_per_100() const;
	double get_opp_oreb_per_100() const;
	double get_opp_dreb_per_100() const;
	double get_opp_steals_per_100() const;
	double get_opp_blocks_per_100() const; 
	double get_opp_fouls_per_100() const;
	

	
private:
	double in_time; //last time this lineup checked in
	double out_time; //last time this lineup checked out
	double minutes_played;

	double pace;

	int possessions;
	int total_fga; 
	int total_turnovers;  
	int total_fgm;
	int total_tpa; 
	int total_tpm;
	int total_twopa;
	int total_twopm;
	int total_fta; 
	int total_ftm; 
	int total_points;
	int total_assists; 
	int total_rebounds;
	int total_oreb; 
	int total_dreb;
	int total_steals;
	int total_blocks;
	int total_fouls; 
	double fg_pct; 
	double tpfg_pct;
	double twopfg_pct;
	double ft_pct;

	int opp_possessions;
	int opp_total_fga;
	int opp_total_turnovers;
	int opp_total_fgm;
	int opp_total_tpa;
	int opp_total_tpm;
	int opp_total_twopa;
	int opp_total_twopm;
	int opp_total_fta;
	int opp_total_ftm;
	int opp_total_points;
	int opp_total_assists;
	int opp_total_rebounds;
	int opp_total_oreb;
	int opp_total_dreb;
	int opp_total_steals;
	int opp_total_blocks;
	int opp_total_fouls;
	double opp_fg_pct;
	double opp_tpfg_pct;
	double opp_twopfg_pct;
	double opp_ft_pct;
};

#endif 
