#pragma once
#include <iostream>
#include <json.hpp>
#include <fstream>
#include <msclr\marshal_cppstd.h>

#include "NewPlayer.h"
#include "mainApp.h"

namespace DnDCharacterSheetV2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for realMenu
	/// </summary>
	public ref class realMenu : public System::Windows::Forms::Form
	{
	public:
		realMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~realMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;

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
		
		void jsonCheck()
		{
			string name = msclr::interop::marshal_as<std::string>(this->textBox1->Text);
			string jsonFileName = name + "charsheet.json";
			ifstream file(jsonFileName);
			if (!file)
			{
				NewPlayer^ NP = gcnew NewPlayer(this->textBox1->Text);
				NP->ShowDialog();
			}
			else
			{
				this->Hide();
				mainApp^ app = gcnew mainApp(this->textBox1->Text);
				app->ShowDialog();
			}
		}
		
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(204, 13);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Write your Character name and press play";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(63, 105);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(141, 20);
			this->textBox1->TabIndex = 22;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &realMenu::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(63, 131);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(141, 23);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Play";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &realMenu::button2_Click);
			// 
			// realMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Name = L"realMenu";
			this->Text = L"realMenu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		jsonCheck();
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
