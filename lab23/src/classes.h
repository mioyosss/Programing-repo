#pragma once

/**
 * @file lib.h
 * @brief Файл з классами та прототипами методів.
 *
 * @author Steghniy B.
 * @date 26-apr-2021
 * @version 0.1
 */


#include "lib.h"
using namespace std;
#ifndef DEFEND_1
#define DEFEND_1

/**
 * @class Fighter
 */
class Fighter {
private:

	bool human;
	bool gender;
	string name;
	int health;
	int power;
	enum clan { red, green, blue } clancolor;
	enum boost { none, shield_10, shield_20, extra_life } bonus;

public:

	/*----------CONSTRUCTORS----------*/
	
	/**
 	* @constructor Fighter
 	*/
	Fighter();	// Дефолт
	
	/**
 	* @constructor Fighter
 	*/	
	Fighter(bool humanValue, bool genderValue, string nameValue, int healthValue, int powerValue, int clancolorValue, int bonusValue);	// С аргументами
	
	/**
 	* @constructor Fighter
 	*/
	Fighter(const Fighter &other);	// Копирования

	/*----------GET----------*/
	/**
 	* @function GetHuman
 	*/
	bool GetHuman();
	/**
 	* @function GetGender
 	*/
	bool GetGender();
	/**
 	* @function GetName
 	*/
	string GetName();
	/**
 	* @function GetHealth
 	*/
	int GetHealth();
	/**
 	* @function GetPower
 	*/
	int GetPower();
	/**
 	* @function GetClancolor
 	*/
	clan GetClancolor();
	/**
 	* @function GetBonus
 	*/
	boost GetBonus();

	/*----------SET----------*/
	/**
 	* @function SetHuman
 	*/
	void SetHuman(bool valueHuman);
	/**
 	* @function SetGender
 	*/
	void SetGender(bool valueGender);
	/**
 	* @function SetName
 	*/
	void SetName(string valueName);
	/**
 	* @function SetHealth
 	*/
	void SetHealth(int valueHealth);
	/**
 	* @function SetPower
 	*/
	void SetPower(int valuePower);
	/**
 	* @function SetClan
 	*/
	void SetClan(int valueClancolor);
	/**
 	* @function SetBonus
 	*/
	void SetBonus(int valueBonus);
		
};

/**
 * @class Fighter_Arr
 */
class Fighter_Arr {
private:
	Fighter* Fighter_Mass;
	int size;

public:
	/**
 	* @constructor Fighter_Arr
 	*/
	Fighter_Arr(int n);	// Конструктор 
	/**
 	* @destructor Fighter_Arr
 	*/
	~Fighter_Arr();	// Деструктор

	/**
 	* @function FillArr
 	*/
	void FillArr();

	/**
 	* @function PrintMass
 	*/	
	void PrintMass();

	/**
 	* @function AddFighter
 	*/
	void AddFighter(Fighter &object);

	/**
 	* @function GetFighter
 	*/
	Fighter& GetFighter(int index);

	/**
 	* @function DeleteFighter
 	*/
	void DeleteFighter(int index);

	/**
 	* @function SearchClan
 	*/
	int SearchClan();
};



#endif
