#pragma once
#include <iostream>
#include <fstream>
#include <json.hpp>
#include <msclr\marshal_cppstd.h>

namespace DnDCharacterSheetV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	//Moja uprava
	using json = nlohmann::json;
	using namespace std;
	namespace
	{
		string name;
		string jsonFileNames;
	}
	extern string filename;

	/// <summary>
	/// Summary for mainApp
	/// </summary>
	public ref class mainApp : public System::Windows::Forms::Form
	{
	public:
		mainApp(void)
		{
			InitializeComponent();
			
			//
			//TODO: Add the constructor code here
			//
		}
		mainApp(String^data)
		{

			InitializeComponent();
			this->label1->Text = data;
			string name = msclr::interop::marshal_as<std::string>(data);
			jsonFileNames = name + "charsheet.json";
			loadSheet();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainApp()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::TextBox^ backgroundT;
	private: System::Windows::Forms::TextBox^ playerNameT;
	private: System::Windows::Forms::TextBox^ raceT;
	private: System::Windows::Forms::TextBox^ alignmentT;
	private: System::Windows::Forms::NumericUpDown^ xpC;






	private: System::Windows::Forms::NumericUpDown^ strC;
	private: System::Windows::Forms::NumericUpDown^ dexT;
	private: System::Windows::Forms::NumericUpDown^ conC;
	private: System::Windows::Forms::NumericUpDown^ intC;
	private: System::Windows::Forms::NumericUpDown^ wisC;
	private: System::Windows::Forms::NumericUpDown^ charC;
	private: System::Windows::Forms::NumericUpDown^ inspiration;
	private: System::Windows::Forms::NumericUpDown^ profiBonus;
	private: System::Windows::Forms::NumericUpDown^ strSave;
	private: System::Windows::Forms::NumericUpDown^ dexSave;
	private: System::Windows::Forms::NumericUpDown^ conSave;
	private: System::Windows::Forms::NumericUpDown^ intSave;
	private: System::Windows::Forms::NumericUpDown^ wisSave;
	private: System::Windows::Forms::NumericUpDown^ charSave;
	private: System::Windows::Forms::NumericUpDown^ acroSkill;
	private: System::Windows::Forms::NumericUpDown^ animalSkill;
	private: System::Windows::Forms::NumericUpDown^ arcanaSkill;

	private: System::Windows::Forms::NumericUpDown^ athletSkill;
	private: System::Windows::Forms::NumericUpDown^ intimSkill;






	private: System::Windows::Forms::NumericUpDown^ insigSkill;

	private: System::Windows::Forms::NumericUpDown^ historySkill;

	private: System::Windows::Forms::NumericUpDown^ decepSkill;
	private: System::Windows::Forms::NumericUpDown^ slihandSkill;


	private: System::Windows::Forms::NumericUpDown^ religSkill;

	private: System::Windows::Forms::NumericUpDown^ pressSkill;

	private: System::Windows::Forms::NumericUpDown^ perforSkill;

	private: System::Windows::Forms::NumericUpDown^ percepSkil;

	private: System::Windows::Forms::NumericUpDown^ natureSkill;

	private: System::Windows::Forms::NumericUpDown^ medSkill;

	private: System::Windows::Forms::NumericUpDown^ investSkill;
	private: System::Windows::Forms::NumericUpDown^ stelthSkill;
	private: System::Windows::Forms::NumericUpDown^ surSkill;
	private: System::Windows::Forms::NumericUpDown^ passWis;
	private: System::Windows::Forms::TextBox^ lange;
	private: System::Windows::Forms::NumericUpDown^ hpMax;
	private: System::Windows::Forms::NumericUpDown^ hpNow;
	private: System::Windows::Forms::NumericUpDown^ tempoHp;
	private: System::Windows::Forms::NumericUpDown^ hitDice;











private: System::Windows::Forms::CheckBox^ saveA;
private: System::Windows::Forms::CheckBox^ saveB;
private: System::Windows::Forms::CheckBox^ saveC;
private: System::Windows::Forms::CheckBox^ FailC;




private: System::Windows::Forms::CheckBox^ FailB;

private: System::Windows::Forms::CheckBox^ FailA;

private: System::Windows::Forms::TextBox^ spells;
private: System::Windows::Forms::TextBox^ equipt;
private: System::Windows::Forms::TextBox^ traits;
private: System::Windows::Forms::TextBox^ ideals;
private: System::Windows::Forms::TextBox^ bonds;
private: System::Windows::Forms::TextBox^ flaws;
private: System::Windows::Forms::TextBox^ features;







	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Button^ save;

private: System::Windows::Forms::NumericUpDown^ armorClass;
private: System::Windows::Forms::NumericUpDown^ init;
private: System::Windows::Forms::NumericUpDown^ speed;
private: System::Windows::Forms::NumericUpDown^ moneyD;
private: System::Windows::Forms::NumericUpDown^ moneyE;





private: System::Windows::Forms::NumericUpDown^ moneyC;

private: System::Windows::Forms::NumericUpDown^ moneyB;

private: System::Windows::Forms::NumericUpDown^ moneyA;

private: System::Windows::Forms::TextBox^ totalHitDice;
private: System::Windows::Forms::ComboBox^ classT;
private: System::Windows::Forms::Label^ label1;




















	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>

		std::string toString(System::String^ managedString) 
		{
			return msclr::interop::marshal_as<std::string>(managedString);
		}

		int toInt(System::Decimal manageInt)
		{
			return static_cast<int>(manageInt);
		}
		std::string toList(System::String^ managedList)
		{
			return msclr::interop::marshal_as<std::string>(managedList);
		}

		void loadSheet()
		{
			ifstream file(jsonFileNames);
			json jsonRead;
			file >> jsonRead;

			this->classT->SelectedItem = gcnew System::String(jsonRead["character"]["class"].get<string>().c_str());
			this->backgroundT->Text = gcnew System::String(jsonRead["character"]["background"].get<string>().c_str());
			this->raceT->Text = gcnew System::String(jsonRead["character"]["race"].get<string>().c_str());
			this->playerNameT->Text = gcnew System::String(jsonRead["character"]["playerName"].get<string>().c_str());
			this->alignmentT->Text = gcnew System::String(jsonRead["character"]["aligment"].get<string>().c_str());
			this->xpC->Value = jsonRead["character"]["xp"].get<int>();

			this->strC->Value = jsonRead["ability"]["strength"].get<int>();
			this->dexT->Value = jsonRead["ability"]["dexterity"].get<int>();
			this->conC->Value = jsonRead["ability"]["constitution"].get<int>();
			this->intC->Value = jsonRead["ability"]["intelligence"].get<int>();
			this->wisC->Value = jsonRead["ability"]["wisdom"].get<int>();
			this->charC->Value = jsonRead["ability"]["charisma"].get<int>();

			this->inspiration->Value = jsonRead["inspiration"].get<int>();

			this->profiBonus->Value = jsonRead["proficiencyBonus"].get<int>();

			this->strSave->Value = jsonRead["savingThrows"]["strength"].get<int>();
			this->dexSave->Value = jsonRead["savingThrows"]["dexterity"].get<int>();
			this->conSave->Value = jsonRead["savingThrows"]["constitution"].get<int>();
			this->intSave->Value = jsonRead["savingThrows"]["intelligence"].get<int>();
			this->wisSave->Value = jsonRead["savingThrows"]["wisdom"].get<int>();
			this->charSave->Value = jsonRead["savingThrows"]["charisma"].get<int>();

			this->acroSkill->Value = jsonRead["skills"]["acrobatics"].get<int>();
			this->animalSkill->Value = jsonRead["skills"]["animal"].get<int>();
			this->arcanaSkill->Value = jsonRead["skills"]["arcana"].get<int>();
			this->acroSkill->Value = jsonRead["skills"]["athletics"].get<int>();
			this->athletSkill->Value = jsonRead["skills"]["deception"].get<int>();
			this->historySkill->Value = jsonRead["skills"]["history"].get<int>();
			this->insigSkill->Value = jsonRead["skills"]["insight"].get<int>();
			this->intimSkill->Value = jsonRead["skills"]["intimidation"].get<int>();
			this->investSkill->Value = jsonRead["skills"]["investigation"].get<int>();
			this->medSkill->Value = jsonRead["skills"]["medicine"].get<int>();
			this->natureSkill->Value = jsonRead["skills"]["nature"].get<int>();
			this->percepSkil->Value = jsonRead["skills"]["perception"].get<int>();
			this->perforSkill->Value = jsonRead["skills"]["performance"].get<int>();
			this->pressSkill->Value = jsonRead["skills"]["persuasion"].get<int>();
			this->religSkill->Value = jsonRead["skills"]["religion"].get<int>();
			this->slihandSkill->Value = jsonRead["skills"]["sleightOfHand"].get<int>();
			this->stelthSkill->Value = jsonRead["skills"]["stelth"].get<int>();
			this->surSkill->Value = jsonRead["skills"]["survival"].get<int>();

			this->passWis->Value = jsonRead["passiveWisdom"].get<int>();

			this->profiBonus->Text = gcnew System::String(jsonRead["otherProficienciesAndLanguage"].get<string>().c_str());

			this->armorClass->Value = jsonRead["armorClass"].get<int>();

			this->init->Value = jsonRead["initiative"].get<int>();

			this->speed->Value = jsonRead["speed"].get<int>();

			this->hpMax->Value = jsonRead["HPMax"].get<int>();

			this->hpNow->Value = jsonRead["HPNow"].get<int>();

			this->tempoHp->Value = jsonRead["temporaryHP"].get<int>();

			this->totalHitDice->Text = gcnew System::String(jsonRead["totalHitDice"].get<string>().c_str());

			this->hitDice->Value = jsonRead["HitDice"].get<int>();

			this->saveA->Checked = jsonRead["successses"]["1"].get<bool>();
			this->saveB->Checked = jsonRead["successses"]["2"].get<bool>();
			this->saveC->Checked = jsonRead["successses"]["3"].get<bool>();

			this->FailA->Checked = jsonRead["failures"]["1"].get<bool>();
			this->FailA->Checked = jsonRead["failures"]["2"].get<bool>();
			this->FailA->Checked = jsonRead["failures"]["3"].get<bool>();

			this->spells->Text = gcnew System::String(jsonRead["attacksAndSpells"].get<string>().c_str());

			this->equipt->Text = gcnew System::String(jsonRead["equipment"]["Name"].get<string>().c_str());
			this->moneyA->Value = jsonRead["equipment"]["CP"].get<int>();
			this->moneyB->Value = jsonRead["equipment"]["SP"].get<int>();
			this->moneyC->Value = jsonRead["equipment"]["EP"].get<int>();
			this->moneyD->Value = jsonRead["equipment"]["GP"].get<int>();
			this->moneyE->Value = jsonRead["equipment"]["PP"].get<int>();

			this->traits->Text = gcnew System::String(jsonRead["personalityTraits"].get<string>().c_str());

			this->ideals->Text = gcnew System::String(jsonRead["ideals"].get<string>().c_str());

			this->bonds->Text = gcnew System::String(jsonRead["bonds"].get<string>().c_str());

			this->flaws->Text = gcnew System::String(jsonRead["flaws"].get<string>().c_str());

			this->features->Text = gcnew System::String(jsonRead["featuresAndTraits"].get<string>().c_str());
		}

		
		void saveSheet()
		{
			json jsonNew;
			jsonNew["character"] = {
				{"name", name},
				{"class", this->classT->SelectedItem ? toList(this->classT->SelectedItem->ToString()) : "Unknown"},
				{"background", toString(this->backgroundT->Text)},
				{"race", toString(this->raceT->Text)},
				{"playerName", toString(this->playerNameT->Text)},
				{"aligment", toString(this->alignmentT->Text)},
				{"xp", toInt(this->xpC->Value)}
			};
			jsonNew["ability"] = {
				{"strength", toInt(this->strC->Value)},
				{"dexterity", toInt(this->dexT->Value)},
				{"constitution", toInt(this->conC->Value)},
				{"intelligence", toInt(this->intC->Value)},
				{"wisdom", toInt(this->wisC->Value)},
				{"charisma", toInt(this->charC->Value)}
			};
			jsonNew["inspiration"] = toInt(this->inspiration->Value);
			jsonNew["proficiencyBonus"] = toInt(this->profiBonus->Value);
			jsonNew["savingThrows"] = {
				{"strength", toInt(this->strSave->Value)},
				{"dexterity",  toInt(this->dexSave->Value)},
				{"constitution",  toInt(this->conSave->Value)},
				{"intelligence",  toInt(this->intSave->Value)},
				{"wisdom",  toInt(this->wisSave->Value)},
				{"charisma",  toInt(this->charSave->Value)}
			};
			jsonNew["skills"] = {
				{"acrobatics", toInt(this->acroSkill->Value)},
				{"animal", toInt(this->animalSkill->Value)},
				{"arcana", toInt(this->arcanaSkill->Value)},
				{"athletics", toInt(this->athletSkill->Value)},
				{"deception", toInt(this->decepSkill->Value)},
				{"history", toInt(this->historySkill->Value)},
				{"insight", toInt(this->insigSkill->Value)},
				{"intimidation", toInt(this->intimSkill->Value)},
				{"investigation", toInt(this->investSkill->Value)},
				{"medicine", toInt(this->medSkill->Value)},
				{"nature", toInt(this->natureSkill->Value)},
				{"perception", toInt(this->percepSkil->Value)},
				{"performance", toInt(this->percepSkil->Value)},
				{"persuasion", toInt(this->pressSkill->Value)},
				{"religion", toInt(this->religSkill->Value)},
				{"sleightOfHand", toInt(this->slihandSkill->Value)},
				{"stelth", toInt(this->stelthSkill->Value)},
				{"survival", toInt(this->surSkill->Value)},
			};
			jsonNew["passiveWisdom"] = toInt(this->passWis->Value);
			jsonNew["otherProficienciesAndLanguage"] = toString(this->profiBonus->Text);
			jsonNew["armorClass"] = toInt(this->armorClass->Value);
			jsonNew["initiative"] = toInt(this->init->Value);
			jsonNew["speed"] = toInt(this->speed->Value);
			jsonNew["HPMax"] = toInt(this->hpMax->Value);
			jsonNew["HPNow"] = toInt(this->hpNow->Value);
			jsonNew["temporaryHP"] = toInt(this->tempoHp->Value);
			jsonNew["totalHitDice"] = toString(this->totalHitDice->Text);
			jsonNew["HitDice"] = toInt(this->hitDice->Value);
			//Death Save
			jsonNew["successses"] = {
				{"1", this->saveA->Checked},
				{"2", this->saveB->Checked},
				{"3", this->saveC->Checked}
			};
			jsonNew["failures"] = {
				{"1", this->FailA->Checked},
				{"2", this->FailB->Checked},
				{"3", this->FailC->Checked}
			};
			jsonNew["attacksAndSpells"] = toString(this->spells->Text);
			jsonNew["equipment"] = {
				{"Name", toString(this->equipt->Text)},
				{"CP", toInt(this->moneyA->Value)},
				{"SP", toInt(this->moneyB->Value)},
				{"EP", toInt(this->moneyC->Value)},
				{"GP", toInt(this->moneyD->Value)},
				{"PP", toInt(this->moneyD->Value)}
			};
			jsonNew["personalityTraits"] = toString(this->traits->Text);
			jsonNew["ideals"] = toString(this->ideals->Text);
			jsonNew["bonds"] = toString(this->bonds->Text);
			jsonNew["flaws"] = toString(this->flaws->Text);
			jsonNew["featuresAndTraits"] = toString(this->features->Text);
			jsonNew["notes"] = "";



			ofstream jsonData(jsonFileNames);
			jsonData << setw(2) << jsonNew;
			jsonData.close();
		}
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mainApp::typeid));
			this->backgroundT = (gcnew System::Windows::Forms::TextBox());
			this->playerNameT = (gcnew System::Windows::Forms::TextBox());
			this->raceT = (gcnew System::Windows::Forms::TextBox());
			this->alignmentT = (gcnew System::Windows::Forms::TextBox());
			this->xpC = (gcnew System::Windows::Forms::NumericUpDown());
			this->strC = (gcnew System::Windows::Forms::NumericUpDown());
			this->dexT = (gcnew System::Windows::Forms::NumericUpDown());
			this->conC = (gcnew System::Windows::Forms::NumericUpDown());
			this->intC = (gcnew System::Windows::Forms::NumericUpDown());
			this->wisC = (gcnew System::Windows::Forms::NumericUpDown());
			this->charC = (gcnew System::Windows::Forms::NumericUpDown());
			this->inspiration = (gcnew System::Windows::Forms::NumericUpDown());
			this->profiBonus = (gcnew System::Windows::Forms::NumericUpDown());
			this->strSave = (gcnew System::Windows::Forms::NumericUpDown());
			this->dexSave = (gcnew System::Windows::Forms::NumericUpDown());
			this->conSave = (gcnew System::Windows::Forms::NumericUpDown());
			this->intSave = (gcnew System::Windows::Forms::NumericUpDown());
			this->wisSave = (gcnew System::Windows::Forms::NumericUpDown());
			this->charSave = (gcnew System::Windows::Forms::NumericUpDown());
			this->acroSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->animalSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->arcanaSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->athletSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->intimSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->insigSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->historySkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->decepSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->slihandSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->religSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->pressSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->perforSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->percepSkil = (gcnew System::Windows::Forms::NumericUpDown());
			this->natureSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->medSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->investSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->stelthSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->surSkill = (gcnew System::Windows::Forms::NumericUpDown());
			this->passWis = (gcnew System::Windows::Forms::NumericUpDown());
			this->lange = (gcnew System::Windows::Forms::TextBox());
			this->hpMax = (gcnew System::Windows::Forms::NumericUpDown());
			this->hpNow = (gcnew System::Windows::Forms::NumericUpDown());
			this->tempoHp = (gcnew System::Windows::Forms::NumericUpDown());
			this->hitDice = (gcnew System::Windows::Forms::NumericUpDown());
			this->saveA = (gcnew System::Windows::Forms::CheckBox());
			this->saveB = (gcnew System::Windows::Forms::CheckBox());
			this->saveC = (gcnew System::Windows::Forms::CheckBox());
			this->FailC = (gcnew System::Windows::Forms::CheckBox());
			this->FailB = (gcnew System::Windows::Forms::CheckBox());
			this->FailA = (gcnew System::Windows::Forms::CheckBox());
			this->spells = (gcnew System::Windows::Forms::TextBox());
			this->equipt = (gcnew System::Windows::Forms::TextBox());
			this->traits = (gcnew System::Windows::Forms::TextBox());
			this->ideals = (gcnew System::Windows::Forms::TextBox());
			this->bonds = (gcnew System::Windows::Forms::TextBox());
			this->flaws = (gcnew System::Windows::Forms::TextBox());
			this->features = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->save = (gcnew System::Windows::Forms::Button());
			this->armorClass = (gcnew System::Windows::Forms::NumericUpDown());
			this->init = (gcnew System::Windows::Forms::NumericUpDown());
			this->speed = (gcnew System::Windows::Forms::NumericUpDown());
			this->moneyD = (gcnew System::Windows::Forms::NumericUpDown());
			this->moneyE = (gcnew System::Windows::Forms::NumericUpDown());
			this->moneyC = (gcnew System::Windows::Forms::NumericUpDown());
			this->moneyB = (gcnew System::Windows::Forms::NumericUpDown());
			this->moneyA = (gcnew System::Windows::Forms::NumericUpDown());
			this->totalHitDice = (gcnew System::Windows::Forms::TextBox());
			this->classT = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xpC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->strC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dexT))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->conC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->intC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wisC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->charC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inspiration))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profiBonus))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->strSave))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dexSave))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->conSave))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->intSave))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wisSave))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->charSave))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->acroSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->animalSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arcanaSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->athletSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->intimSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->insigSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->historySkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->decepSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->slihandSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->religSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pressSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->perforSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->percepSkil))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->natureSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->medSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->investSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stelthSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->surSkill))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->passWis))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hpMax))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hpNow))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tempoHp))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hitDice))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->armorClass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->init))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->speed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moneyD))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moneyE))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moneyC))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moneyB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moneyA))->BeginInit();
			this->SuspendLayout();
			// 
			// backgroundT
			// 
			this->backgroundT->AccessibleName = L"";
			this->backgroundT->Location = System::Drawing::Point(501, 63);
			this->backgroundT->Name = L"backgroundT";
			this->backgroundT->Size = System::Drawing::Size(100, 20);
			this->backgroundT->TabIndex = 2;
			// 
			// playerNameT
			// 
			this->playerNameT->Location = System::Drawing::Point(631, 63);
			this->playerNameT->Name = L"playerNameT";
			this->playerNameT->Size = System::Drawing::Size(100, 20);
			this->playerNameT->TabIndex = 3;
			// 
			// raceT
			// 
			this->raceT->Location = System::Drawing::Point(357, 98);
			this->raceT->Name = L"raceT";
			this->raceT->Size = System::Drawing::Size(100, 20);
			this->raceT->TabIndex = 4;
			// 
			// alignmentT
			// 
			this->alignmentT->Location = System::Drawing::Point(501, 98);
			this->alignmentT->Name = L"alignmentT";
			this->alignmentT->Size = System::Drawing::Size(100, 20);
			this->alignmentT->TabIndex = 5;
			// 
			// xpC
			// 
			this->xpC->Location = System::Drawing::Point(631, 98);
			this->xpC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->xpC->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->xpC->Name = L"xpC";
			this->xpC->Size = System::Drawing::Size(120, 20);
			this->xpC->TabIndex = 6;
			// 
			// strC
			// 
			this->strC->Location = System::Drawing::Point(58, 213);
			this->strC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->strC->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->strC->Name = L"strC";
			this->strC->Size = System::Drawing::Size(39, 20);
			this->strC->TabIndex = 7;
			this->strC->ValueChanged += gcnew System::EventHandler(this, &mainApp::strC_ValueChanged);
			// 
			// dexT
			// 
			this->dexT->Location = System::Drawing::Point(58, 307);
			this->dexT->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->dexT->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->dexT->Name = L"dexT";
			this->dexT->Size = System::Drawing::Size(39, 20);
			this->dexT->TabIndex = 8;
			// 
			// conC
			// 
			this->conC->Location = System::Drawing::Point(58, 399);
			this->conC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->conC->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->conC->Name = L"conC";
			this->conC->Size = System::Drawing::Size(39, 20);
			this->conC->TabIndex = 9;
			// 
			// intC
			// 
			this->intC->Location = System::Drawing::Point(58, 493);
			this->intC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->intC->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->intC->Name = L"intC";
			this->intC->Size = System::Drawing::Size(39, 20);
			this->intC->TabIndex = 10;
			// 
			// wisC
			// 
			this->wisC->Location = System::Drawing::Point(58, 589);
			this->wisC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->wisC->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->wisC->Name = L"wisC";
			this->wisC->Size = System::Drawing::Size(39, 20);
			this->wisC->TabIndex = 11;
			// 
			// charC
			// 
			this->charC->Location = System::Drawing::Point(58, 684);
			this->charC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->charC->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->charC->Name = L"charC";
			this->charC->Size = System::Drawing::Size(39, 20);
			this->charC->TabIndex = 12;
			// 
			// inspiration
			// 
			this->inspiration->Location = System::Drawing::Point(129, 174);
			this->inspiration->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->inspiration->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->inspiration->Name = L"inspiration";
			this->inspiration->Size = System::Drawing::Size(30, 20);
			this->inspiration->TabIndex = 13;
			// 
			// profiBonus
			// 
			this->profiBonus->Location = System::Drawing::Point(129, 223);
			this->profiBonus->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->profiBonus->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->profiBonus->Name = L"profiBonus";
			this->profiBonus->Size = System::Drawing::Size(30, 20);
			this->profiBonus->TabIndex = 14;
			// 
			// strSave
			// 
			this->strSave->Location = System::Drawing::Point(132, 263);
			this->strSave->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->strSave->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->strSave->Name = L"strSave";
			this->strSave->Size = System::Drawing::Size(42, 20);
			this->strSave->TabIndex = 15;
			// 
			// dexSave
			// 
			this->dexSave->Location = System::Drawing::Point(132, 281);
			this->dexSave->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->dexSave->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->dexSave->Name = L"dexSave";
			this->dexSave->Size = System::Drawing::Size(42, 20);
			this->dexSave->TabIndex = 16;
			// 
			// conSave
			// 
			this->conSave->Location = System::Drawing::Point(132, 301);
			this->conSave->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->conSave->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->conSave->Name = L"conSave";
			this->conSave->Size = System::Drawing::Size(42, 20);
			this->conSave->TabIndex = 17;
			// 
			// intSave
			// 
			this->intSave->Location = System::Drawing::Point(132, 320);
			this->intSave->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->intSave->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->intSave->Name = L"intSave";
			this->intSave->Size = System::Drawing::Size(42, 20);
			this->intSave->TabIndex = 18;
			// 
			// wisSave
			// 
			this->wisSave->Location = System::Drawing::Point(132, 339);
			this->wisSave->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->wisSave->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->wisSave->Name = L"wisSave";
			this->wisSave->Size = System::Drawing::Size(42, 20);
			this->wisSave->TabIndex = 19;
			// 
			// charSave
			// 
			this->charSave->Location = System::Drawing::Point(132, 359);
			this->charSave->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->charSave->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->charSave->Name = L"charSave";
			this->charSave->Size = System::Drawing::Size(42, 20);
			this->charSave->TabIndex = 20;
			// 
			// acroSkill
			// 
			this->acroSkill->Location = System::Drawing::Point(132, 419);
			this->acroSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->acroSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->acroSkill->Name = L"acroSkill";
			this->acroSkill->Size = System::Drawing::Size(42, 20);
			this->acroSkill->TabIndex = 21;
			// 
			// animalSkill
			// 
			this->animalSkill->Location = System::Drawing::Point(132, 436);
			this->animalSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->animalSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->animalSkill->Name = L"animalSkill";
			this->animalSkill->Size = System::Drawing::Size(42, 20);
			this->animalSkill->TabIndex = 22;
			// 
			// arcanaSkill
			// 
			this->arcanaSkill->Location = System::Drawing::Point(132, 456);
			this->arcanaSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->arcanaSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->arcanaSkill->Name = L"arcanaSkill";
			this->arcanaSkill->Size = System::Drawing::Size(42, 20);
			this->arcanaSkill->TabIndex = 23;
			// 
			// athletSkill
			// 
			this->athletSkill->Location = System::Drawing::Point(132, 473);
			this->athletSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->athletSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->athletSkill->Name = L"athletSkill";
			this->athletSkill->Size = System::Drawing::Size(42, 20);
			this->athletSkill->TabIndex = 24;
			// 
			// intimSkill
			// 
			this->intimSkill->Location = System::Drawing::Point(132, 545);
			this->intimSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->intimSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->intimSkill->Name = L"intimSkill";
			this->intimSkill->Size = System::Drawing::Size(42, 20);
			this->intimSkill->TabIndex = 28;
			// 
			// insigSkill
			// 
			this->insigSkill->Location = System::Drawing::Point(132, 528);
			this->insigSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->insigSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->insigSkill->Name = L"insigSkill";
			this->insigSkill->Size = System::Drawing::Size(42, 20);
			this->insigSkill->TabIndex = 27;
			// 
			// historySkill
			// 
			this->historySkill->Location = System::Drawing::Point(132, 508);
			this->historySkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->historySkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->historySkill->Name = L"historySkill";
			this->historySkill->Size = System::Drawing::Size(42, 20);
			this->historySkill->TabIndex = 26;
			// 
			// decepSkill
			// 
			this->decepSkill->Location = System::Drawing::Point(132, 491);
			this->decepSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->decepSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->decepSkill->Name = L"decepSkill";
			this->decepSkill->Size = System::Drawing::Size(42, 20);
			this->decepSkill->TabIndex = 25;
			// 
			// slihandSkill
			// 
			this->slihandSkill->Location = System::Drawing::Point(132, 688);
			this->slihandSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->slihandSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->slihandSkill->Name = L"slihandSkill";
			this->slihandSkill->Size = System::Drawing::Size(42, 20);
			this->slihandSkill->TabIndex = 36;
			// 
			// religSkill
			// 
			this->religSkill->Location = System::Drawing::Point(132, 671);
			this->religSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->religSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->religSkill->Name = L"religSkill";
			this->religSkill->Size = System::Drawing::Size(42, 20);
			this->religSkill->TabIndex = 35;
			// 
			// pressSkill
			// 
			this->pressSkill->Location = System::Drawing::Point(132, 651);
			this->pressSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->pressSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->pressSkill->Name = L"pressSkill";
			this->pressSkill->Size = System::Drawing::Size(42, 20);
			this->pressSkill->TabIndex = 34;
			// 
			// perforSkill
			// 
			this->perforSkill->Location = System::Drawing::Point(132, 634);
			this->perforSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->perforSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->perforSkill->Name = L"perforSkill";
			this->perforSkill->Size = System::Drawing::Size(42, 20);
			this->perforSkill->TabIndex = 33;
			// 
			// percepSkil
			// 
			this->percepSkil->Location = System::Drawing::Point(132, 616);
			this->percepSkil->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->percepSkil->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->percepSkil->Name = L"percepSkil";
			this->percepSkil->Size = System::Drawing::Size(42, 20);
			this->percepSkil->TabIndex = 32;
			// 
			// natureSkill
			// 
			this->natureSkill->Location = System::Drawing::Point(132, 599);
			this->natureSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->natureSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->natureSkill->Name = L"natureSkill";
			this->natureSkill->Size = System::Drawing::Size(42, 20);
			this->natureSkill->TabIndex = 31;
			// 
			// medSkill
			// 
			this->medSkill->Location = System::Drawing::Point(132, 579);
			this->medSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->medSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->medSkill->Name = L"medSkill";
			this->medSkill->Size = System::Drawing::Size(42, 20);
			this->medSkill->TabIndex = 30;
			// 
			// investSkill
			// 
			this->investSkill->Location = System::Drawing::Point(132, 562);
			this->investSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->investSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->investSkill->Name = L"investSkill";
			this->investSkill->Size = System::Drawing::Size(42, 20);
			this->investSkill->TabIndex = 29;
			// 
			// stelthSkill
			// 
			this->stelthSkill->Location = System::Drawing::Point(132, 705);
			this->stelthSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->stelthSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->stelthSkill->Name = L"stelthSkill";
			this->stelthSkill->Size = System::Drawing::Size(42, 20);
			this->stelthSkill->TabIndex = 37;
			// 
			// surSkill
			// 
			this->surSkill->Location = System::Drawing::Point(132, 725);
			this->surSkill->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->surSkill->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->surSkill->Name = L"surSkill";
			this->surSkill->Size = System::Drawing::Size(42, 20);
			this->surSkill->TabIndex = 38;
			// 
			// passWis
			// 
			this->passWis->Location = System::Drawing::Point(47, 778);
			this->passWis->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->passWis->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->passWis->Name = L"passWis";
			this->passWis->Size = System::Drawing::Size(29, 20);
			this->passWis->TabIndex = 39;
			// 
			// lange
			// 
			this->lange->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->lange->Location = System::Drawing::Point(48, 825);
			this->lange->Multiline = true;
			this->lange->Name = L"lange";
			this->lange->Size = System::Drawing::Size(216, 166);
			this->lange->TabIndex = 40;
			// 
			// hpMax
			// 
			this->hpMax->Location = System::Drawing::Point(390, 254);
			this->hpMax->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->hpMax->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->hpMax->Name = L"hpMax";
			this->hpMax->Size = System::Drawing::Size(42, 20);
			this->hpMax->TabIndex = 41;
			// 
			// hpNow
			// 
			this->hpNow->Location = System::Drawing::Point(390, 291);
			this->hpNow->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->hpNow->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->hpNow->Name = L"hpNow";
			this->hpNow->Size = System::Drawing::Size(42, 20);
			this->hpNow->TabIndex = 42;
			// 
			// tempoHp
			// 
			this->tempoHp->Location = System::Drawing::Point(390, 359);
			this->tempoHp->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->tempoHp->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->tempoHp->Name = L"tempoHp";
			this->tempoHp->Size = System::Drawing::Size(42, 20);
			this->tempoHp->TabIndex = 43;
			// 
			// hitDice
			// 
			this->hitDice->Location = System::Drawing::Point(330, 445);
			this->hitDice->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->hitDice->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->hitDice->Name = L"hitDice";
			this->hitDice->Size = System::Drawing::Size(42, 20);
			this->hitDice->TabIndex = 45;
			// 
			// saveA
			// 
			this->saveA->AutoSize = true;
			this->saveA->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveA->Location = System::Drawing::Point(456, 424);
			this->saveA->Name = L"saveA";
			this->saveA->Size = System::Drawing::Size(12, 11);
			this->saveA->TabIndex = 46;
			this->saveA->UseVisualStyleBackColor = true;
			// 
			// saveB
			// 
			this->saveB->AutoSize = true;
			this->saveB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveB->Location = System::Drawing::Point(474, 424);
			this->saveB->Name = L"saveB";
			this->saveB->Size = System::Drawing::Size(12, 11);
			this->saveB->TabIndex = 47;
			this->saveB->UseVisualStyleBackColor = true;
			// 
			// saveC
			// 
			this->saveC->AutoSize = true;
			this->saveC->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveC->Location = System::Drawing::Point(490, 424);
			this->saveC->Name = L"saveC";
			this->saveC->Size = System::Drawing::Size(12, 11);
			this->saveC->TabIndex = 48;
			this->saveC->UseVisualStyleBackColor = true;
			// 
			// FailC
			// 
			this->FailC->AutoSize = true;
			this->FailC->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FailC->Location = System::Drawing::Point(491, 444);
			this->FailC->Name = L"FailC";
			this->FailC->Size = System::Drawing::Size(12, 11);
			this->FailC->TabIndex = 51;
			this->FailC->UseVisualStyleBackColor = true;
			// 
			// FailB
			// 
			this->FailB->AutoSize = true;
			this->FailB->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FailB->Location = System::Drawing::Point(475, 444);
			this->FailB->Name = L"FailB";
			this->FailB->Size = System::Drawing::Size(12, 11);
			this->FailB->TabIndex = 50;
			this->FailB->UseVisualStyleBackColor = true;
			// 
			// FailA
			// 
			this->FailA->AutoSize = true;
			this->FailA->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->FailA->Location = System::Drawing::Point(457, 444);
			this->FailA->Name = L"FailA";
			this->FailA->Size = System::Drawing::Size(12, 11);
			this->FailA->TabIndex = 49;
			this->FailA->UseVisualStyleBackColor = true;
			// 
			// spells
			// 
			this->spells->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->spells->Location = System::Drawing::Point(290, 518);
			this->spells->Multiline = true;
			this->spells->Name = L"spells";
			this->spells->Size = System::Drawing::Size(228, 227);
			this->spells->TabIndex = 52;
			// 
			// equipt
			// 
			this->equipt->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->equipt->Location = System::Drawing::Point(353, 783);
			this->equipt->Multiline = true;
			this->equipt->Name = L"equipt";
			this->equipt->Size = System::Drawing::Size(162, 208);
			this->equipt->TabIndex = 53;
			// 
			// traits
			// 
			this->traits->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->traits->Location = System::Drawing::Point(551, 185);
			this->traits->Multiline = true;
			this->traits->Name = L"traits";
			this->traits->Size = System::Drawing::Size(204, 62);
			this->traits->TabIndex = 54;
			// 
			// ideals
			// 
			this->ideals->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ideals->Location = System::Drawing::Point(551, 275);
			this->ideals->Multiline = true;
			this->ideals->Name = L"ideals";
			this->ideals->Size = System::Drawing::Size(204, 45);
			this->ideals->TabIndex = 55;
			// 
			// bonds
			// 
			this->bonds->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->bonds->Location = System::Drawing::Point(551, 350);
			this->bonds->Multiline = true;
			this->bonds->Name = L"bonds";
			this->bonds->Size = System::Drawing::Size(204, 43);
			this->bonds->TabIndex = 56;
			// 
			// flaws
			// 
			this->flaws->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->flaws->Location = System::Drawing::Point(551, 421);
			this->flaws->Multiline = true;
			this->flaws->Name = L"flaws";
			this->flaws->Size = System::Drawing::Size(204, 43);
			this->flaws->TabIndex = 57;
			// 
			// features
			// 
			this->features->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->features->Location = System::Drawing::Point(540, 510);
			this->features->Multiline = true;
			this->features->Name = L"features";
			this->features->Size = System::Drawing::Size(223, 481);
			this->features->TabIndex = 58;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(201, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(399, 13);
			this->label2->TabIndex = 59;
			this->label2->Text = L"Tutorial: https://www.instructables.com/Creating-a-DD-5e-Character-for-Beginners/"
				L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(304, 768);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(39, 13);
			this->label3->TabIndex = 60;
			this->label3->Text = L"Money";
			// 
			// save
			// 
			this->save->Location = System::Drawing::Point(656, 2);
			this->save->Name = L"save";
			this->save->Size = System::Drawing::Size(75, 23);
			this->save->TabIndex = 61;
			this->save->Text = L"Save";
			this->save->UseVisualStyleBackColor = true;
			this->save->Click += gcnew System::EventHandler(this, &mainApp::save_Click);
			// 
			// armorClass
			// 
			this->armorClass->Location = System::Drawing::Point(312, 194);
			this->armorClass->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->armorClass->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->armorClass->Name = L"armorClass";
			this->armorClass->Size = System::Drawing::Size(36, 20);
			this->armorClass->TabIndex = 62;
			// 
			// init
			// 
			this->init->Location = System::Drawing::Point(383, 194);
			this->init->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->init->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->init->Name = L"init";
			this->init->Size = System::Drawing::Size(36, 20);
			this->init->TabIndex = 63;
			// 
			// speed
			// 
			this->speed->Location = System::Drawing::Point(463, 196);
			this->speed->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->speed->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->speed->Name = L"speed";
			this->speed->Size = System::Drawing::Size(36, 20);
			this->speed->TabIndex = 64;
			// 
			// moneyD
			// 
			this->moneyD->Location = System::Drawing::Point(303, 891);
			this->moneyD->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->moneyD->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->moneyD->Name = L"moneyD";
			this->moneyD->Size = System::Drawing::Size(42, 20);
			this->moneyD->TabIndex = 69;
			// 
			// moneyE
			// 
			this->moneyE->Location = System::Drawing::Point(303, 925);
			this->moneyE->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->moneyE->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->moneyE->Name = L"moneyE";
			this->moneyE->Size = System::Drawing::Size(42, 20);
			this->moneyE->TabIndex = 68;
			// 
			// moneyC
			// 
			this->moneyC->Location = System::Drawing::Point(302, 857);
			this->moneyC->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->moneyC->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->moneyC->Name = L"moneyC";
			this->moneyC->Size = System::Drawing::Size(42, 20);
			this->moneyC->TabIndex = 67;
			// 
			// moneyB
			// 
			this->moneyB->Location = System::Drawing::Point(303, 823);
			this->moneyB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->moneyB->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->moneyB->Name = L"moneyB";
			this->moneyB->Size = System::Drawing::Size(42, 20);
			this->moneyB->TabIndex = 66;
			// 
			// moneyA
			// 
			this->moneyA->Location = System::Drawing::Point(302, 789);
			this->moneyA->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->moneyA->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, System::Int32::MinValue });
			this->moneyA->Name = L"moneyA";
			this->moneyA->Size = System::Drawing::Size(42, 20);
			this->moneyA->TabIndex = 65;
			// 
			// totalHitDice
			// 
			this->totalHitDice->Location = System::Drawing::Point(330, 415);
			this->totalHitDice->Name = L"totalHitDice";
			this->totalHitDice->Size = System::Drawing::Size(54, 20);
			this->totalHitDice->TabIndex = 70;
			// 
			// classT
			// 
			this->classT->FormattingEnabled = true;
			this->classT->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Artificer", L"Barbarian", L"Bard", L"Druid", L"Fighter",
					L"Monk", L"Paladin", L"Ranger", L"Rougue", L"Sorcerer", L"Warlock", L"Wizard"
			});
			this->classT->Location = System::Drawing::Point(357, 63);
			this->classT->Name = L"classT";
			this->classT->Size = System::Drawing::Size(121, 21);
			this->classT->TabIndex = 71;
			this->classT->Text = L"(None)";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(62, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(242, 31);
			this->label1->TabIndex = 72;
			this->label1->Text = L"Name Will Be Here";
			this->label1->Click += gcnew System::EventHandler(this, &mainApp::label1_Click_1);
			// 
			// mainApp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(808, 1041);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->classT);
			this->Controls->Add(this->totalHitDice);
			this->Controls->Add(this->moneyD);
			this->Controls->Add(this->moneyE);
			this->Controls->Add(this->moneyC);
			this->Controls->Add(this->moneyB);
			this->Controls->Add(this->moneyA);
			this->Controls->Add(this->speed);
			this->Controls->Add(this->init);
			this->Controls->Add(this->armorClass);
			this->Controls->Add(this->save);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->features);
			this->Controls->Add(this->flaws);
			this->Controls->Add(this->bonds);
			this->Controls->Add(this->ideals);
			this->Controls->Add(this->traits);
			this->Controls->Add(this->equipt);
			this->Controls->Add(this->spells);
			this->Controls->Add(this->FailC);
			this->Controls->Add(this->FailB);
			this->Controls->Add(this->FailA);
			this->Controls->Add(this->saveC);
			this->Controls->Add(this->saveB);
			this->Controls->Add(this->saveA);
			this->Controls->Add(this->hitDice);
			this->Controls->Add(this->tempoHp);
			this->Controls->Add(this->hpNow);
			this->Controls->Add(this->hpMax);
			this->Controls->Add(this->lange);
			this->Controls->Add(this->passWis);
			this->Controls->Add(this->surSkill);
			this->Controls->Add(this->stelthSkill);
			this->Controls->Add(this->slihandSkill);
			this->Controls->Add(this->religSkill);
			this->Controls->Add(this->pressSkill);
			this->Controls->Add(this->perforSkill);
			this->Controls->Add(this->percepSkil);
			this->Controls->Add(this->natureSkill);
			this->Controls->Add(this->medSkill);
			this->Controls->Add(this->investSkill);
			this->Controls->Add(this->intimSkill);
			this->Controls->Add(this->insigSkill);
			this->Controls->Add(this->historySkill);
			this->Controls->Add(this->decepSkill);
			this->Controls->Add(this->athletSkill);
			this->Controls->Add(this->arcanaSkill);
			this->Controls->Add(this->animalSkill);
			this->Controls->Add(this->acroSkill);
			this->Controls->Add(this->charSave);
			this->Controls->Add(this->wisSave);
			this->Controls->Add(this->intSave);
			this->Controls->Add(this->conSave);
			this->Controls->Add(this->dexSave);
			this->Controls->Add(this->strSave);
			this->Controls->Add(this->profiBonus);
			this->Controls->Add(this->inspiration);
			this->Controls->Add(this->charC);
			this->Controls->Add(this->wisC);
			this->Controls->Add(this->intC);
			this->Controls->Add(this->conC);
			this->Controls->Add(this->dexT);
			this->Controls->Add(this->strC);
			this->Controls->Add(this->xpC);
			this->Controls->Add(this->alignmentT);
			this->Controls->Add(this->raceT);
			this->Controls->Add(this->playerNameT);
			this->Controls->Add(this->backgroundT);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"mainApp";
			this->Text = L"mainApp";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->xpC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->strC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dexT))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->conC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->intC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wisC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->charC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->inspiration))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profiBonus))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->strSave))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dexSave))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->conSave))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->intSave))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wisSave))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->charSave))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->acroSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->animalSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->arcanaSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->athletSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->intimSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->insigSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->historySkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->decepSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->slihandSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->religSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pressSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->perforSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->percepSkil))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->natureSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->medSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->investSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stelthSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->surSkill))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->passWis))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hpMax))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hpNow))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tempoHp))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hitDice))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->armorClass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->init))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->speed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moneyD))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moneyE))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moneyC))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moneyB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->moneyA))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void strC_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void classT_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void save_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		saveSheet();

	}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}