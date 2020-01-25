#include<iostream>
#include<map>
#include<string>
#include <queue>

int main() {
	int teams = 0, scenario = 0;
	while (std::cin >> teams, teams) {
		std::queue<int> main_queue;
		std::queue<int>* queuer = new std::queue<int>[teams];
		int *teamqueue = new int[1000001];
		while (teams--) {
			int amount, team;
			std::cin >> amount;
			for (int i = 0; i < amount; ++i) {
				std::cin >> team;
				teamqueue[team]=teams;
			}
		}
		std::cout << "Scenario #" << ++scenario << "\n";
		std::string input;
		while (std::cin >> input, input[0] != 'S') {
			if (input[0] == 'E') {
				int team_number;
				std::cin >> team_number;
				int id = teamqueue[team_number];
				if (queuer[id].empty()) main_queue.push(id);
				queuer[id].push(team_number);
			}
			else {
				int team_number = main_queue.front();
				std::cout << queuer[team_number].front() << std::endl;
				queuer[team_number].pop();
				if (queuer[team_number].empty()) main_queue.pop();
			}

		}
		std::cout << std::endl;
		delete[] queuer;
		delete[] teamqueue;
	}
	return 0;
}
