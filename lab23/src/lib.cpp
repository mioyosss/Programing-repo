#include "classes.h"

/**
 * @file lib.cpp
 * @brief Файл з реалізацією методів.
 *
 * @author Steghniy B.
 * @date 26-apr-2021
 * @version 0.1
 */


Fighter::Fighter() {
	cout << endl << "---Вызвался конструктор по умолчанию Fighter ---" << endl << endl;
};


Fighter::Fighter(bool humanValue, bool genderValue, string nameValue, int healthValue, int powerValue, int clancolorValue, int bonusValue)
	: human(humanValue), gender(genderValue), name(nameValue), health(healthValue), power(powerValue)
{
	if (clancolorValue == 0)
		clancolor = red;
	else if (clancolorValue == 1)
		clancolor = green;
	else if (clancolorValue == 2)
		clancolor = blue;

	if (bonusValue == 0)
		bonus = none;
	else if (bonusValue == 1)
		bonus = shield_10;
	else if (bonusValue == 2)
		bonus = shield_20;
	else if (bonusValue == 3)
		bonus = extra_life;

	cout << endl << "---Вызвался конструктор c аргументами Fighter ---" << endl << endl;
};


Fighter::Fighter(const Fighter& other) {
	this->human = other.human;
	this->gender = other.gender;
	this->name = other.name;
	this->health = other.health;
	this->power = other.power;
	this->clancolor = other.clancolor;
	this->bonus = other.bonus;
	cout << endl << "---Вызвался конструктор копирования Fighter ---" << endl << endl;
};


void Fighter::SetHuman(bool valueHuman) {

	valueHuman == true ? human = true : human = false;
	
}
void Fighter::SetGender(bool valueGender) {
	
	valueGender == true ? gender = true : gender = false;
	
}
void Fighter::SetName(string valueName) {
	name = valueName;
}
void Fighter::SetHealth(int valueHealth) {
	health = valueHealth;
}
void Fighter::SetPower(int valuePower) {
	power = valuePower;
}
void Fighter::SetClan(int valueClancolor) {
	if (valueClancolor == 0)
		clancolor = red;
	else if (valueClancolor == 1)
		clancolor = green;
	else if (valueClancolor == 2)
		clancolor = blue;
}
void Fighter::SetBonus(int valueBonus) {
	if (valueBonus == 0)
		bonus = none;
	else if (valueBonus == 1)
		bonus = shield_10;
	else if (valueBonus == 2)
		bonus = shield_20;
	else if (valueBonus == 3)
		bonus = extra_life;
}


bool Fighter::GetHuman() {
	return human;
}
bool Fighter::GetGender() {
	return gender;
}
string Fighter::GetName() {
	return name;
}
int Fighter::GetHealth() {
	return health;
}
int Fighter::GetPower() {
	return power;
}
Fighter::clan Fighter::GetClancolor() {
	return clancolor;
}
Fighter::boost Fighter::GetBonus() {
	return bonus;
}





Fighter_Arr::Fighter_Arr(int n) {
	size = n;
	Fighter_Mass = new Fighter[n];
	cout << endl << "Вызвался конструктор для Fighter_Arr" << endl << endl;
};


Fighter_Arr::~Fighter_Arr() {
	delete[]Fighter_Mass;
	cout << endl << "Вызвался деструктор для Fighter_Arr" << endl << endl;
};

void Fighter_Arr::FillArr() {
	string randname[100];
	for(int i = 0; i < size; i++){
		stringstream ss;
		ss << "Fighter №" << i + 1;
		randname[i] = ss.str();
		Fighter_Mass[i].SetBonus(rand() % 3);
		Fighter_Mass[i].SetClan(rand() % 3);
		Fighter_Mass[i].SetGender(rand() % 2);

		Fighter_Mass[i].SetHealth((rand() % 100)+1);
		Fighter_Mass[i].SetHuman(rand() % 2);

		Fighter_Mass[i].SetName(randname[i]);
		Fighter_Mass[i].SetPower((rand() % 100) + 1);
	}
};


void Fighter_Arr::AddFighter(Fighter& object) {

	int n = ++this->size;

	Fighter* temp_fighter = new Fighter[n];

	for (int i = 0; i < n - 1; i++) {
		temp_fighter[i] = Fighter_Mass[i];
	}

	temp_fighter[n - 1] = object;
	temp_fighter[n - 1].SetBonus(rand() % 3);
	temp_fighter[n - 1].SetClan(rand() % 2);
	temp_fighter[n - 1].SetGender(rand() % 2);
	temp_fighter[n - 1].SetHealth((rand() % 100) + 1);
	temp_fighter[n - 1].SetHuman(rand() % 2);
	temp_fighter[n - 1].SetName("[ADDED]");
	temp_fighter[n - 1].SetPower((rand() % 100) + 1);

	delete[] Fighter_Mass;

	Fighter_Mass = temp_fighter;
};

Fighter& Fighter_Arr::GetFighter(int index) {

	if (Fighter_Mass[index].GetHuman()) cout << " Человек: Да" << endl; else cout << " Человек: Нет" << endl;
	if (Fighter_Mass[index].GetGender()) cout << " Пол: Мужчина" << endl; else cout << " Пол: Женщина" << endl;
	cout << " Имя: " << Fighter_Mass[index].GetName() << endl << " ХП: " << Fighter_Mass[index].GetHealth() << endl << " Сила: " << Fighter_Mass[index].GetPower() << endl;
	if (Fighter_Mass[index].GetClancolor() == 0) cout << " Клан: Красный" << endl; else if (Fighter_Mass[index].GetClancolor() == 1) cout << " Клан: Зеленый" << endl; else if (Fighter_Mass[index].GetClancolor() == 2) cout << " Клан: Синий" << endl;
	if (Fighter_Mass[index].GetBonus() == 0) cout << " Бонус: Нет" << endl << endl; else if (Fighter_Mass[index].GetBonus() == 1) cout << " Бонус: Защита 10" << endl << endl; else if (Fighter_Mass[index].GetBonus() == 2) cout << " Бонус: Защита 20" << endl << endl; else if (Fighter_Mass[index].GetBonus() == 3) cout << " Бонус: Дополнительная жизнь" << endl << endl;

	return Fighter_Mass[index];
}


void Fighter_Arr::PrintMass() {
	for (int i = 0; i < this->size; i++) {
		GetFighter(i);
	}
};


void Fighter_Arr::DeleteFighter(int index) {

	int n = --this->size;

	for (int i = index; i < n; i++)
	{
		Fighter_Mass[i] = Fighter_Mass[i + 1];
	}
}

int Fighter_Arr::SearchClan() {

	int count_red = 0;
	int count_green = 0;
	int count_blue = 0;

	for (int i = 0; i < size; i++) {
		if (Fighter_Mass[i].GetClancolor() == 0) 
			count_red++;
	}

	for (int i = 0; i < size; i++) {
		if (Fighter_Mass[i].GetClancolor() == 1)
			count_green++;
	}

	for (int i = 0; i < size; i++) {
		if (Fighter_Mass[i].GetClancolor() == 2) {
			count_blue++;
		}
	}
		
	printf("Количество бойцов красного клана: %d\nКоличество бойцов зеленого клана: %d\nКоличество бойцов синего клана: %d\n", count_red, count_green, count_blue);
	printf("\n");

	if (count_red > count_blue && count_red > count_green)
		return count_red;
	else if (count_blue > count_red && count_blue > count_green)
		return count_blue;
	else if (count_green > count_red && count_green > count_blue)
		return count_green;
	else
		return 0;

}


