/*#pragma once
#include "mainApp.h"
#include "NewPlayer.h"
#include "DnDMenu.h"
#include <iostream>
#include <fstream>
#include <json.hpp>

using json = nlohmann::json;
using namespace std;
namespace
	{
		string jsonFileName;
	}

/*void createNewJson()
{
	json jsonNew;
    jsonNew["character"] = {
		{"name", ""},
		{"class", ""},
		{"background", ""},
		{"race", ""},
		{"playerName", ""},
		{"aligment", ""},
		{"xp", 0}
	};
	jsonNew["ability"] = {
		{"strength", 0},
		{"dexterity", 0},
		{"constitution", 0},
		{"intelligence", 0},
		{"wisdom", 0},
		{"charisma", 0}
	};
	jsonNew["inspiration"] = 0;
	jsonNew["proficiencyBonus"] = 0;
	jsonNew["savingThrows"] = {
		{"strength", 0},
		{"dexterity", 0},
		{"constitution", 0},
		{"intelligence", 0},
		{"wisdom", 0},
		{"charisma", 0}
	};
	jsonNew["skills"] = {
		{"acrobatics", 0},
		{"animal", 0},
		{"arcana", 0},
		{"athletics", 0},
		{"deception", 0},
		{"history", 0},
		{"insight", 0},
		{"intimidation", 0},
		{"investigation", 0},
		{"medicine", 0},
		{"nature", 0},
		{"perception", 0},
		{"performance", 0},
		{"persuasion", 0},
		{"religion", 0},
		{"sleightOfHand", 0},
		{"stelth", 0},
		{"survival", 0},
	};
	jsonNew["passiveWisdom"] = 0;
	jsonNew["otherProficienciesAndLanguage"] = "";
	jsonNew["armorClass"] = 0;
	jsonNew["initiative"] = 0;
	jsonNew["speed"] = 0;
	jsonNew["HP"] = 0;
	jsonNew["temporaryHP"] = "";
	jsonNew["totalHitDice"] = "";
	//Death Save
	jsonNew["successses"] = {
		{"1", false},
		{"2", false},
		{"3", false}
	};
	jsonNew["failures"] = {
		{"1", false},
		{"2", false},
		{"3", false}
	};
	jsonNew["attacksAndSpells"] = "";
	jsonNew["equipment"] = {
		{"Name", ""},
		{"CP", 0},
		{"SP", 0},
		{"EP", 0},
		{"GP", 0},
		{"PP", 0}
	};
	jsonNew["personalityTraits"] = "";
	jsonNew["ideals"] = "";
	jsonNew["bonds"] = "";
	jsonNew["flaws"] = "";
	jsonNew["featuresAndTraits"] = "";
	jsonNew["notes"] = "";



	ofstream jsonData(jsonFileName);
	jsonData << setw(2) << jsonNew;
	jsonData.close();
}*/