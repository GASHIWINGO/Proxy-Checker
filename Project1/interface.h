#pragma once

#include "checker.h"
#include "DB.h"

#include <fstream>
#include <windows.h>

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
	private: System::Windows::Forms::CheckBox^ CheckHTTP;

	private: System::Windows::Forms::Button^ StartButton;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::CheckBox^ CheckSOCKS4;
	private: System::Windows::Forms::CheckBox^ CheckSOCKS5;
	private: System::Windows::Forms::CheckBox^ CheckNonW;
	private: System::Windows::Forms::DataGridView^ GridResults;







	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Status;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Adress;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Login;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Password;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Response;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Country;
	private: System::Windows::Forms::Label^ labelResults;







	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->CheckHTTP = (gcnew System::Windows::Forms::CheckBox());
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->CheckSOCKS4 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckSOCKS5 = (gcnew System::Windows::Forms::CheckBox());
			this->CheckNonW = (gcnew System::Windows::Forms::CheckBox());
			this->GridResults = (gcnew System::Windows::Forms::DataGridView());
			this->Status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Adress = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Login = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Password = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Response = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Country = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->labelResults = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridResults))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(173, 30);
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
			// CheckHTTP
			// 
			this->CheckHTTP->AccessibleRole = System::Windows::Forms::AccessibleRole::TitleBar;
			this->CheckHTTP->AutoSize = true;
			this->CheckHTTP->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->CheckHTTP->CheckAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckHTTP->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CheckHTTP->Location = System::Drawing::Point(508, 103);
			this->CheckHTTP->Name = L"CheckHTTP";
			this->CheckHTTP->Size = System::Drawing::Size(123, 25);
			this->CheckHTTP->TabIndex = 2;
			this->CheckHTTP->Text = L"HTTP|HTTPS";
			this->CheckHTTP->UseVisualStyleBackColor = false;
			// 
			// StartButton
			// 
			this->StartButton->BackColor = System::Drawing::Color::MediumSpringGreen;
			this->StartButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->StartButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->StartButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->StartButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StartButton->Location = System::Drawing::Point(12, 313);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(159, 31);
			this->StartButton->TabIndex = 6;
			this->StartButton->Text = L"Начать проверку";
			this->StartButton->UseVisualStyleBackColor = false;
			this->StartButton->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(503, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 30);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Отображать:";
			// 
			// CheckSOCKS4
			// 
			this->CheckSOCKS4->AccessibleRole = System::Windows::Forms::AccessibleRole::TitleBar;
			this->CheckSOCKS4->AutoSize = true;
			this->CheckSOCKS4->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->CheckSOCKS4->CheckAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckSOCKS4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CheckSOCKS4->Location = System::Drawing::Point(508, 138);
			this->CheckSOCKS4->Name = L"CheckSOCKS4";
			this->CheckSOCKS4->Size = System::Drawing::Size(88, 25);
			this->CheckSOCKS4->TabIndex = 8;
			this->CheckSOCKS4->Text = L"SOCKS4";
			this->CheckSOCKS4->UseVisualStyleBackColor = false;
			// 
			// CheckSOCKS5
			// 
			this->CheckSOCKS5->AccessibleRole = System::Windows::Forms::AccessibleRole::TitleBar;
			this->CheckSOCKS5->AutoSize = true;
			this->CheckSOCKS5->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->CheckSOCKS5->CheckAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckSOCKS5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CheckSOCKS5->Location = System::Drawing::Point(508, 173);
			this->CheckSOCKS5->Name = L"CheckSOCKS5";
			this->CheckSOCKS5->Size = System::Drawing::Size(88, 25);
			this->CheckSOCKS5->TabIndex = 9;
			this->CheckSOCKS5->Text = L"SOCKS5";
			this->CheckSOCKS5->UseVisualStyleBackColor = false;
			// 
			// CheckNonW
			// 
			this->CheckNonW->AccessibleRole = System::Windows::Forms::AccessibleRole::TitleBar;
			this->CheckNonW->AutoSize = true;
			this->CheckNonW->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->CheckNonW->CheckAlign = System::Drawing::ContentAlignment::TopLeft;
			this->CheckNonW->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CheckNonW->Location = System::Drawing::Point(508, 68);
			this->CheckNonW->Name = L"CheckNonW";
			this->CheckNonW->Size = System::Drawing::Size(131, 25);
			this->CheckNonW->TabIndex = 10;
			this->CheckNonW->Text = L"Non-working";
			this->CheckNonW->UseVisualStyleBackColor = false;
			// 
			// GridResults
			// 
			this->GridResults->AllowUserToAddRows = false;
			this->GridResults->AllowUserToDeleteRows = false;
			this->GridResults->AllowUserToResizeRows = false;
			this->GridResults->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::MediumSpringGreen;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->GridResults->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->GridResults->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->GridResults->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Status, this->Adress,
					this->Login, this->Password, this->Response, this->Country
			});
			this->GridResults->EnableHeadersVisualStyles = false;
			this->GridResults->Location = System::Drawing::Point(-45, -4);
			this->GridResults->Name = L"GridResults";
			this->GridResults->ReadOnly = true;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::TopCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::MediumSpringGreen;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::Black;
			this->GridResults->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->GridResults->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->GridResults->Size = System::Drawing::Size(736, 311);
			this->GridResults->TabIndex = 11;
			this->GridResults->TabStop = false;
			this->GridResults->Visible = false;
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
			// labelResults
			// 
			this->labelResults->AutoSize = true;
			this->labelResults->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelResults->Location = System::Drawing::Point(143, 319);
			this->labelResults->Name = L"labelResults";
			this->labelResults->Size = System::Drawing::Size(403, 21);
			this->labelResults->TabIndex = 14;
			this->labelResults->Text = L"Результаты проверки сохранены в файл result.txt";
			this->labelResults->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(667, 356);
			this->Controls->Add(this->labelResults);
			this->Controls->Add(this->CheckNonW);
			this->Controls->Add(this->CheckSOCKS5);
			this->Controls->Add(this->CheckSOCKS4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->StartButton);
			this->Controls->Add(this->CheckHTTP);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->GridResults);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Proxy Checker";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridResults))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Visible = false;
		this->label2->Visible = false;

		this->textBox1->Visible = false;
		this->CheckHTTP->Visible = false;
		this->CheckSOCKS4->Visible = false;
		this->CheckSOCKS5->Visible = false;
		this->CheckNonW->Visible = false;

		this->StartButton->Visible = false;

		this->GridResults->Visible = true;

		this->Text = "Proxy Checker - пожалуйста, подождите, идёт проверка прокси (приложение может зависнуть)";

		String^ text = textBox1->Text;

		array<String^>^ lines = text->Split('\n');

		std::regex ipPattern("^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
		std::regex portPattern("^[0-9]{1,5}$");

		//new user for this checking in DB 
		add_user(); 

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
					std::string login;
					std::string password;
					if (colonCount == 3) {
						login = rest.substr(rest.find(':') + 1, rest.rfind(':') - rest.find(':') - 1);
						password = rest.substr(rest.rfind(':') + 1);
					}
					//add each server from list to DB
					add_server(ip + ":" + rest.substr(0, rest.find(':')), login, password); 
				}
			}
		}

		bool http = this->CheckHTTP->Checked;
		bool socks4 = this->CheckSOCKS4->Checked;
		bool socks5 = this->CheckSOCKS5->Checked;
		bool non_working = this->CheckNonW->Checked;

		//start main function for checking
		start(http, socks4, socks5, non_working);

		delete text;
		delete[] lines;

		this->Text = "Proxy Checker - проверка завершена";

		System::IO::StreamReader^ sr = gcnew System::IO::StreamReader("proxy_info.txt");

		array<wchar_t>^ splitBy = { ' ' };
		for (;;)
		{
			String^ line = sr->ReadLine();
			if (line == nullptr) break;
			if (line->Length > 0)
			{
				array<String^>^ parts = line->Split(splitBy, StringSplitOptions::RemoveEmptyEntries);
				int rowIndex = GridResults->Rows->Add();
				for (int i = 0; i < GridResults->ColumnCount; i++)
				{
					if (i < parts->Length)
					{
						GridResults->Rows[rowIndex]->Cells[i]->Value = parts[i];
					}
					else
					{
						GridResults->Rows[rowIndex]->Cells[i]->Value = "-";
					}
				}
			}
		}
		sr->Close();

		this->labelResults->Visible = true;
	}
};
}
