#include <iostream>
#include <queue>
#include <string>
#include <vector>
class Car {
public:
	int time;
	int arrival;
	bool is_left;
	void end(int init) {
		arrival = init;
	}
	void set(int time, std::string side) { this->time = time; is_left = (side == "left" ? true : false); };
	Car() {};
};

class Operator {
public:
	Operator(int, int,int, Car*);
private:
	bool is_left = true;
	std::queue<Car*> left_side;
	std::queue<Car*> right_side;
	int travel_time;
	int ferry_slots;
	int on_board;
	int current_time;
	void load_and_go();
	bool left();
	bool is_available();
	bool get_faster_side();
	int current_slot_time();
	bool is_empty(std::queue<Car*>*);
	void swap_to_faster_side();
	void work();
	std::queue<Car*>* current();
	std::queue<Car*>* opposite();

};
Operator::Operator(int travel, int ferry_slot, int amount, Car* list) {
	current_time = 0;
	ferry_slots = ferry_slot;
	travel_time = travel;
	for (Car* i = list; i < list+amount; ++i) {
		(i->is_left ? left_side : right_side).push(i);
	}
	work();
}
std::queue<Car*>* Operator::current() {
	return (is_left ? &left_side : &right_side);
}
std::queue<Car*>* Operator::opposite() {
	return (!is_left ? &left_side : &right_side);
}
void Operator::load_and_go() {
	on_board = 0;
	while (on_board !=  ferry_slots && !is_empty(current()) && current_slot_time() <= current_time) {
		(current()->front())->end(current_time + travel_time);
		current()->pop();
		on_board++;
	}
	
	if ((on_board != 0)) {
		current_time += travel_time;
		is_left = !is_left;
	}
}
bool Operator::left()
{
	return (!right_side.empty() || !left_side.empty());
}
bool Operator::is_available()
{
	if (!current()->empty()) {
		if (current_slot_time() <= current_time) {
			return true;
		}
	}
	return false;
}
bool Operator::is_empty(std::queue<Car *> * a) {
	return a->empty();
}
bool Operator::get_faster_side() {
	bool csE = !is_empty(current());
	bool osE = !is_empty(opposite());
	if (csE && osE) {
		if (current_slot_time() >= opposite()->front()->time) {
			return !is_left;
		}
		else {
			return is_left;
		}
	}
	else if (csE) {
		return is_left;
	}
	else {
		return !is_left;
	}
}
int Operator::current_slot_time()
{
	return current()->front()->time;
}
void Operator::swap_to_faster_side() {
	bool side = get_faster_side();
	bool add_time = (side != is_left);
	is_left = side;
	
	if (current_slot_time() > current_time) current_time = current_slot_time();
	if (add_time) current_time += travel_time;
	
}
void Operator::work() {
	while (!left_side.empty() || !right_side.empty()) {
		load_and_go();
		if (on_board == 0 && !is_available() && left()) swap_to_faster_side();
	}
}


int main() {
	int tests;
	std::cin >> tests;
	while (tests != 0) {
		tests--;
		int ferry_cap, travel, car_amount;
		std::cin >> ferry_cap >> travel >> car_amount;
		Car *car_list = new Car[car_amount];
		for (int i = 0; i < car_amount; ++i) {
			std::string side;
			int date;
			std::cin >> date >> side;
			(car_list+i)->set(date,side);
		}
		Operator anOperator(travel,ferry_cap, car_amount, car_list);
		for (int i = 0; i <car_amount; ++i) {
			std::cout << car_list[i].arrival << std::endl;
		}
		if (tests != 0) std::cout << std::endl;
		delete[] car_list;
	}
	return 0;
}

