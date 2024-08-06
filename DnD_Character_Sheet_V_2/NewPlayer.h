#pragma once
#include "mainApp.h"
#include "iostream"
#include "json.hpp"
#include <fstream>
#include <msclr\marshal_cppstd.h>

namespace DnDCharacterSheetV2 
{

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
		string data;
		string jsonFileName;
	}

	/// <summary>
	/// Summary for NewPlayer
	/// </summary>
	public ref class NewPlayer : public System::Windows::Forms::Form
	{
	public:
		NewPlayer(void)
		{
			InitializeComponent();
		}
		NewPlayer(String^ data)
		{
			InitializeComponent();
			string names = msclr::interop::marshal_as<std::string>(data);
			jsonFileName = names + "charsheet.json";
			this->textBox1->Text = data;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewPlayer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
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
		
		void createNewJson()
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
			jsonNew["HPMax"] = 0;
			jsonNew["HPNow"] = 0;
			jsonNew["temporaryHP"] = 0;
			jsonNew["totalHitDice"] = "";
			jsonNew["HitDice"] = 0;
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
		}
		
		
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(75, 47);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(115, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Create new character\?";
			this->label1->Click += gcnew System::EventHandler(this, &NewPlayer::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(29, 119);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Yes";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NewPlayer::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(178, 119);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"No";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &NewPlayer::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Location = System::Drawing::Point(200, 123);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(36, 13);
			this->textBox1->TabIndex = 3;
			// 
			// NewPlayer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"NewPlayer";
			this->Text = L"NewPlayer";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		createNewJson();
		
		this->Hide();
		mainApp^ mA = gcnew mainApp(this->textBox1->Text);
		mA->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Close();
	}
	};
}
