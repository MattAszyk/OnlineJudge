#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

enum Status {
	WIN=3,TIES=1,LOSS=0
};
class Match {
public:
	Match(std::string);
	std::string first_team, second_team;
	Status first_team_status=LOSS, second_team_status=LOSS;
	int first_team_goals=0, second_team_goals=0;
	
};
class Team {
public:
	 int points=0;
	 int shoted_goals=0;
	 int match_played=0;
	 int match_won=0;
	 int match_loss=0;
	 int lost_goals = 0;
	 int ties_match = 0;
	Team(std::string);
	std::string name;
private:
};
Match::Match(std::string input) {
	size_t pos = 0;
	std::string::size_type sz;
	pos = input.find("#");
	first_team = input.substr(0, pos);
	input = input.substr(pos, input.size() - 1);
	pos = input.find("@");
	first_team_goals = std::stoi(input.substr(1, pos - 1),&sz);
	input = input.substr(pos, input.size() - 1);
	pos = input.find("#");
	second_team_goals = std::stoi(input.substr(1, pos - 1),&sz);
	second_team = input.substr(pos + 1, input.size() - 1);
	if (first_team_goals > second_team_goals) {
		first_team_status = WIN;
		second_team_status = LOSS;
	}
	else if (first_team_goals < second_team_goals) {
		first_team_status = LOSS;
		second_team_status = WIN;
	}
	else {
		first_team_status = TIES;
		second_team_status = TIES;
	}
	/**std::cout << first_team << " " << first_team_goals << ":" << second_team_goals << " " << second_team << std::endl;
	std::cout << "FT: " << first_team << " " << first_team_goals << " " << first_team_status << std::endl;
	std::cout << "ST: " << second_team << " " << second_team_goals << " " << second_team_status << std::endl;
	**/
}
Team::Team(std::string input) {
	name = input;
}
class TeamController {
public:
	void add_team(Team);
	void add_match(Match);
	void print();
private:
	void sort();
	std::vector<Team> teams;
	std::vector<Match> matchs;
};
void TeamController::add_team(Team t) {
	teams.push_back(t);
}
void TeamController::sort() {
	std::sort(teams.begin(), teams.end(), [](const Team& a, const Team& b) {
	if(a.points != b.points)    return a.points > b.points;
    if(a.match_won != b.match_won)  return a.match_won > b.match_won;
    if(a.shoted_goals-a.lost_goals != b.shoted_goals-b.lost_goals)
        return a.shoted_goals-a.lost_goals > b.shoted_goals-b.lost_goals;
    if(a.shoted_goals != b.shoted_goals)
        return a.shoted_goals > b.shoted_goals;
    if(a.match_played != b.match_played)
        return a.match_played < b.match_played;

    std::string aName = a.name, bName = b.name;
    for(int i=0; i<aName.length(); i++) aName[i] = tolower(aName[i]);
	for(int i=0; i<bName.length(); i++) bName[i] = tolower(bName[i]);

    return aName < bName;
	});
}
void TeamController::add_match(Match match) {
	int i = 0;
	for (i = 0; i < teams.size() && teams[i].name != match.first_team; ++i);
	teams[i].match_played++;
	teams[i].shoted_goals += match.first_team_goals;
	teams[i].lost_goals += match.second_team_goals;
	teams[i].points += match.first_team_status;
	if (match.first_team_status == WIN) teams[i].match_won++;
	else if (match.first_team_status == TIES) teams[i].ties_match++;
	else teams[i].match_loss++;
	for (i = 0; i < teams.size() && teams[i].name != match.second_team; ++i);
	teams[i].match_played++;
	teams[i].shoted_goals += match.second_team_goals;
	teams[i].lost_goals += match.first_team_goals;
	teams[i].points += match.second_team_status;
	if (match.second_team_status == WIN) teams[i].match_won++;
	else if (match.second_team_status == TIES) teams[i].ties_match++;
	else teams[i].match_loss++;
}
void TeamController::print() {
	sort();
	for (int i = 0; i < teams.size(); ++i) {
		std::cout << std::endl << i + 1 << ") " << teams[i].name << " " <<
			teams[i].points << "p, " << teams[i].match_played << "g (" <<
			teams[i].match_won << "-" << teams[i].ties_match << "-" <<
			teams[i].match_loss << "), " << teams[i].shoted_goals - teams[i].lost_goals <<
			"gd (" << teams[i].shoted_goals << "-" << teams[i].lost_goals << ")";
	}
}
int main() {
	std::string::size_type sz;
	int tests;
    bool show_enter = false;
	std::string test_s;
	std::getline( std::cin, test_s);
	tests = std::stoi(test_s, &sz);
	while (tests--) {
		TeamController controller;
		std::string name, s_team; int team_amount, plays;
		std::getline(std::cin, name);
		std::getline(std::cin, s_team);
		team_amount = std::stoi(s_team, &sz);
		while (team_amount--) {
			std::string name_of_team;
			std::getline(std::cin, name_of_team);
			controller.add_team(Team(name_of_team));
		}
		std::getline(std::cin, s_team);
		team_amount = std::stoi(s_team, &sz);
		while (team_amount--) {
			std::string match_stats;
			std::getline(std::cin,match_stats);
			controller.add_match(Match(match_stats));
		}
        if(show_enter) std::cout << "\n";
		std::cout << (show_enter ? "\n" : "") << name;
		controller.print();
		show_enter = true;
        if(tests==0) std::cout << "\n";
	}

	return 0;
}
