#include <iostream>
#include <vector>
#include <string>

class Queue {
public: 
	Queue(unsigned long long, int);
	void move(unsigned long long);
	void out();
	void move_in_vect(unsigned long long);
private:
	unsigned long long citizens;
	int cases;
	bool test_case;
	std::vector<unsigned long long> list;
};

Queue::Queue(unsigned long long citizens, int cases) {
	test_case = cases < citizens;
	this->citizens = citizens;
	this->cases = cases;
	for (long long i = 1; i <= (test_case ? cases : citizens); ++i) list.push_back(i);
}

void Queue::move_in_vect(unsigned long long id) {
	int i;
	for (i = 0; i < list.size() && list[i] != id; ++i);
	if (i < list.size() && list[i] == id) {
		list.erase(list.begin() + i);
		list.insert(list.begin(), id);
	}
	else {
		list.insert(list.begin(), id);
	}
}

void Queue::move(unsigned long long id) {
	if (test_case) {
		if (id > cases) {
			list.insert(list.begin(), id);
		}
		else {
			move_in_vect(id);
		}
	}
	else {
		move_in_vect(id);
	}
}

void Queue::out() {
	std::cout << list[0] << std::endl;
	if (test_case) {
		list.erase(list.begin());

	}
	else {
		list.push_back(*list.begin());
		list.erase(list.begin());
	}
}

int main() {
	int tests = 0;
	while (true) {
		unsigned long long population; int cases;
		std::cin >> population >> cases;
		if (population == 0 && cases == 0) break;
		Queue queue(population, cases);
		std::cout << "Case " << ++tests << ":\n";
		while (cases--) {
			char MOD;
			std::cin >> MOD;
			if (MOD == 'N') queue.out();
			else {
				unsigned long long id;
				std::cin >> id;
				queue.move_in_vect(id);
			}
		}
	}
	return 0;
}
