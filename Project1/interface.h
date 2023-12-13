#pragma once

#include "checker.h"

#include <fstream>
#include <string>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::CheckBox^ checkBox1;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Status;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Login;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Password;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Response;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Country;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;

	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Adress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Login = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Password = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Response = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Country = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(180, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Список прокси:";
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Location = System::Drawing::Point(12, 68);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(461, 205);
			this->textBox1->TabIndex = 1;
			// 
			// checkBox1
			// 
			this->checkBox1->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox1->AutoSize = true;
			this->checkBox1->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(508, 103);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(105, 29);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"HTTP|HTTPS";
			this->checkBox1->UseVisualStyleBackColor = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 313);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 31);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Начать проверку";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(503, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(155, 25);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Отображать:";
			// 
			// checkBox2
			// 
			this->checkBox2->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox2->AutoSize = true;
			this->checkBox2->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox2->Location = System::Drawing::Point(508, 138);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(79, 29);
			this->checkBox2->TabIndex = 8;
			this->checkBox2->Text = L"SOCKS4";
			this->checkBox2->UseVisualStyleBackColor = false;
			// 
			// checkBox3
			// 
			this->checkBox3->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox3->AutoSize = true;
			this->checkBox3->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox3->Location = System::Drawing::Point(508, 173);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(79, 29);
			this->checkBox3->TabIndex = 9;
			this->checkBox3->Text = L"SOCKS5";
			this->checkBox3->UseVisualStyleBackColor = false;
			// 
			// checkBox4
			// 
			this->checkBox4->Appearance = System::Windows::Forms::Appearance::Button;
			this->checkBox4->AutoSize = true;
			this->checkBox4->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox4->Location = System::Drawing::Point(508, 68);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(120, 29);
			this->checkBox4->TabIndex = 10;
			this->checkBox4->Text = L"Non-working";
			this->checkBox4->UseVisualStyleBackColor = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::MediumSpringGreen;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Status,
					this->Adress, this->Login, this->Password, this->Response, this->Country
			});
			this->dataGridView1->Location = System::Drawing::Point(-43, -2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGridView1->Size = System::Drawing::Size(715, 309);
			this->dataGridView1->TabIndex = 11;
			this->dataGridView1->TabStop = false;
			this->dataGridView1->Visible = false;
			// 
			// Status
			// 
			this->Status->HeaderText = L"Status";
			this->Status->Name = L"Status";
			this->Status->ReadOnly = true;
			this->Status->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Status->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Status->Width = 50;
			// 
			// Adress
			// 
			this->Adress->HeaderText = L"IP:Port";
			this->Adress->Name = L"Adress";
			this->Adress->ReadOnly = true;
			this->Adress->Width = 250;
			// 
			// Login
			// 
			this->Login->HeaderText = L"Login";
			this->Login->Name = L"Login";
			this->Login->ReadOnly = true;
			// 
			// Password
			// 
			this->Password->HeaderText = L"Password";
			this->Password->Name = L"Password";
			this->Password->ReadOnly = true;
			// 
			// Response
			// 
			this->Response->HeaderText = L"Response time";
			this->Response->Name = L"Response";
			this->Response->ReadOnly = true;
			this->Response->Width = 110;
			// 
			// Country
			// 
			this->Country->HeaderText = L"Country";
			this->Country->Name = L"Country";
			this->Country->ReadOnly = true;
			this->Country->Width = 60;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(461, 313);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(194, 31);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Экспорт результата";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Visible = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(12, 313);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(159, 31);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Выход";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Visible = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(480, 313);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(159, 31);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Выход";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(667, 356);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Visible = false;
		this->label2->Visible = false;

		this->textBox1->Visible = false;
		this->checkBox1->Visible = false;
		this->checkBox2->Visible = false;
		this->checkBox3->Visible = false;
		this->checkBox4->Visible = false;

		this->button1->Visible = false;
		this->button4->Visible = false;

		this->dataGridView1->Visible = true;

		this->button2->Visible = true;
		this->button3->Visible = true;

		String^ text = textBox1->Text;

		array<String^>^ lines = text->Split('\n');

		std::ofstream outputFile("proxy_list.txt");

		std::regex ipPattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
		std::regex portPattern("^[0-9]{1,5}$");

		for each (String ^ line in lines) {
			line = line->Trim();

			std::string proxy;
			for (int i = 0; i < line->Length; ++i) {
				proxy += static_cast<char>(line[i]);
			}

			size_t colonCount = std::count(proxy.begin(), proxy.end(), ':');
			if (colonCount == 1 || colonCount == 3) {
				std::string ip = proxy.substr(0, proxy.find(':'));
				std::string rest = proxy.substr(proxy.find(':') + 1);

				if (std::regex_match(ip, ipPattern) && (colonCount == 1 && std::regex_match(rest, portPattern) || colonCount == 3 && std::regex_match(rest.substr(0, rest.find(':')), portPattern))) {
					outputFile << proxy << "\n";
				}

			}
		}

		outputFile.close();

		bool http = this->checkBox1->Checked;
		bool socks4 = this->checkBox2->Checked;
		bool socks5 = this->checkBox3->Checked;
		bool non_working = this->checkBox4->Checked;

		start(http, socks4, socks5, non_working);

		delete text;
		delete[] lines;

		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader("proxy_info.txt");
		array<wchar_t>^ splitBy = { ' ' };
		for (;;)
		{
			String^ line = sr->ReadLine();
			if (line == nullptr) break;
			if (line->Length > 0)
			{
				array<String^>^ parts = line->Split(splitBy, StringSplitOptions::RemoveEmptyEntries);
				int rowIndex = dataGridView1->Rows->Add();
				for (int i = 0; i < dataGridView1->ColumnCount; i++)
				{
					if (i < parts->Length)
					{
						dataGridView1->Rows[rowIndex]->Cells[i]->Value = parts[i];
					}
					else
					{
						dataGridView1->Rows[rowIndex]->Cells[i]->Value = "-";
					}
				}
			}
		}
		sr->Close();
	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
