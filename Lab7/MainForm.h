#include <string>
#include <msclr/marshal_cppstd.h>
#include <functional>
#include <list>
#include <cmath>
#include <iostream>
#include <fstream>
#using <System.Numerics.dll>
#include <ctime>
#include <functional>
#pragma once
namespace Lab7 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Numerics;
	using namespace msclr::interop;
	using namespace std;
	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	char* characters = new char[12]{ '#', '1', '2', '3', '4', '5', '6', '7', '8',    '9', '0', '-' }; //Число М(i) = номер этой буквы в массиве
	vector<int> primeNumbers
	{
		11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199
	};

	long p; //p
	long q; //q
	long m; // = (p - 1) * (q - 1)
	long n; // = p * q
	long d; // взаимнопростое с числом m
	long e; // (e * d) mod m = 1
	long n_new; //вводимые ключи при расшифровании
	long d_new; //
	//Будем использовать хеш-значения каждого символа:
	std::hash<char> hash_char; //хеш-функция
	std::hash<std::string>stringHashFunction;
	string fileData; //строка из файла
	string hash_of_str; //строка-результат посимвольного хеширования
	string result_hash;
	std::hash<int> hash; //хеш-функция
	list<string> result; // результат шифрования
	list<int> result_two; // результат шифрования
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;













	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox12;


	private: System::Windows::Forms::Label^ evaluatedResultsLabel;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Label^ fileSignLabel;
	private: System::Windows::Forms::Label^ estimatedSignLabel;

	private: System::Windows::Forms::Label^ fileHashDataLabel;
	private: System::Windows::Forms::Label^ solutionLabel;
	protected:
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->solutionLabel = (gcnew System::Windows::Forms::Label());
			this->fileSignLabel = (gcnew System::Windows::Forms::Label());
			this->estimatedSignLabel = (gcnew System::Windows::Forms::Label());
			this->fileHashDataLabel = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->evaluatedResultsLabel = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(14, 31);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(159, 28);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Вычислить значения RSA";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button4);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Location = System::Drawing::Point(17, 103);
			this->groupBox3->Margin = System::Windows::Forms::Padding(2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(2);
			this->groupBox3->Size = System::Drawing::Size(502, 152);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Шаг 2. Чтение файла";
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(305, 112);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(189, 28);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Открыть файл и вычислить хэш";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 24);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(110, 13);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Содержимое файла:";
			this->label7->Click += gcnew System::EventHandler(this, &MainForm::label7_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(140, 24);
			this->textBox7->Margin = System::Windows::Forms::Padding(2);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(354, 84);
			this->textBox7->TabIndex = 0;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(15, 81);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(135, 13);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Зашифрованная подпись";
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(166, 57);
			this->textBox12->Margin = System::Windows::Forms::Padding(2);
			this->textBox12->Name = L"textBox12";
			this->textBox12->ReadOnly = true;
			this->textBox12->Size = System::Drawing::Size(323, 20);
			this->textBox12->TabIndex = 10;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(15, 57);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(51, 13);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Подпись";
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(324, 105);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(165, 28);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Сформировать попись";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(166, 81);
			this->textBox8->Margin = System::Windows::Forms::Padding(2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->ReadOnly = true;
			this->textBox8->Size = System::Drawing::Size(323, 20);
			this->textBox8->TabIndex = 1;
			this->textBox8->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox8_TextChanged);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->solutionLabel);
			this->groupBox4->Controls->Add(this->fileSignLabel);
			this->groupBox4->Controls->Add(this->estimatedSignLabel);
			this->groupBox4->Controls->Add(this->fileHashDataLabel);
			this->groupBox4->Controls->Add(this->textBox10);
			this->groupBox4->Controls->Add(this->button7);
			this->groupBox4->Controls->Add(this->textBox11);
			this->groupBox4->Controls->Add(this->label11);
			this->groupBox4->Controls->Add(this->textBox9);
			this->groupBox4->Controls->Add(this->label9);
			this->groupBox4->Controls->Add(this->button5);
			this->groupBox4->Controls->Add(this->button6);
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Location = System::Drawing::Point(19, 412);
			this->groupBox4->Margin = System::Windows::Forms::Padding(2);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(2);
			this->groupBox4->Size = System::Drawing::Size(502, 283);
			this->groupBox4->TabIndex = 10;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Шаг 4. Проверка подписи";
			// 
			// solutionLabel
			// 
			this->solutionLabel->AutoSize = true;
			this->solutionLabel->Location = System::Drawing::Point(18, 179);
			this->solutionLabel->Name = L"solutionLabel";
			this->solutionLabel->Size = System::Drawing::Size(69, 13);
			this->solutionLabel->TabIndex = 20;
			this->solutionLabel->Text = L"solutionLabel";
			// 
			// fileSignLabel
			// 
			this->fileSignLabel->AutoSize = true;
			this->fileSignLabel->Location = System::Drawing::Point(18, 127);
			this->fileSignLabel->Name = L"fileSignLabel";
			this->fileSignLabel->Size = System::Drawing::Size(67, 13);
			this->fileSignLabel->TabIndex = 19;
			this->fileSignLabel->Text = L"fileSignLabel";
			// 
			// estimatedSignLabel
			// 
			this->estimatedSignLabel->AutoSize = true;
			this->estimatedSignLabel->Location = System::Drawing::Point(18, 154);
			this->estimatedSignLabel->Name = L"estimatedSignLabel";
			this->estimatedSignLabel->Size = System::Drawing::Size(99, 13);
			this->estimatedSignLabel->TabIndex = 18;
			this->estimatedSignLabel->Text = L"estimatedSignLabel";
			// 
			// fileHashDataLabel
			// 
			this->fileHashDataLabel->AutoSize = true;
			this->fileHashDataLabel->Location = System::Drawing::Point(18, 100);
			this->fileHashDataLabel->Name = L"fileHashDataLabel";
			this->fileHashDataLabel->Size = System::Drawing::Size(94, 13);
			this->fileHashDataLabel->TabIndex = 17;
			this->fileHashDataLabel->Text = L"fileHashDataLabel";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(322, 100);
			this->textBox10->Margin = System::Windows::Forms::Padding(2);
			this->textBox10->Name = L"textBox10";
			this->textBox10->ReadOnly = true;
			this->textBox10->Size = System::Drawing::Size(165, 20);
			this->textBox10->TabIndex = 10;
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->Location = System::Drawing::Point(341, 33);
			this->button7->Margin = System::Windows::Forms::Padding(2);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(161, 28);
			this->button7->TabIndex = 13;
			this->button7->Text = L"Применить закрытые ключи";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MainForm::button7_Click);
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(243, 33);
			this->textBox11->Margin = System::Windows::Forms::Padding(2);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(76, 20);
			this->textBox11->TabIndex = 15;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(172, 33);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(67, 13);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Значение n:";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(86, 33);
			this->textBox9->Margin = System::Windows::Forms::Padding(2);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(76, 20);
			this->textBox9->TabIndex = 13;
			this->textBox9->TextChanged += gcnew System::EventHandler(this, &MainForm::textBox9_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(18, 33);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(67, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Значение d:";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(21, 57);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(192, 28);
			this->button5->TabIndex = 9;
			this->button5->Text = L"Извлечь подпись и проверить";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Enabled = false;
			this->button6->Location = System::Drawing::Point(303, 217);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(182, 28);
			this->button6->TabIndex = 5;
			this->button6->Text = L"Проверить";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(338, 137);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(31, 13);
			this->label10->TabIndex = 2;
			this->label10->Text = L"Хеш:";
			// 
			// evaluatedResultsLabel
			// 
			this->evaluatedResultsLabel->AutoSize = true;
			this->evaluatedResultsLabel->Location = System::Drawing::Point(183, 39);
			this->evaluatedResultsLabel->Name = L"evaluatedResultsLabel";
			this->evaluatedResultsLabel->Size = System::Drawing::Size(16, 13);
			this->evaluatedResultsLabel->TabIndex = 11;
			this->evaluatedResultsLabel->Text = L"...";
			this->evaluatedResultsLabel->Click += gcnew System::EventHandler(this, &MainForm::evaluatedResultsLabel_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->textBox12);
			this->groupBox1->Controls->Add(this->textBox13);
			this->groupBox1->Controls->Add(this->textBox8);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Location = System::Drawing::Point(17, 260);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(502, 147);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Шаг 3. Формирование подписи";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MainForm::groupBox1_Enter);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(15, 33);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(107, 13);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Хеш-данные файла:";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(166, 33);
			this->textBox13->Margin = System::Windows::Forms::Padding(2);
			this->textBox13->Name = L"textBox13";
			this->textBox13->ReadOnly = true;
			this->textBox13->Size = System::Drawing::Size(323, 20);
			this->textBox13->TabIndex = 12;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->evaluatedResultsLabel);
			this->groupBox2->Location = System::Drawing::Point(17, 24);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(501, 74);
			this->groupBox2->TabIndex = 13;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Шаг 1. Вычисление RSA";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &MainForm::groupBox2_Enter);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(532, 706);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainForm";
			this->Text = L"Lab7";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ ev) {
		srand(time(NULL));
		
		int firstRandomIndex = rand() % primeNumbers.size();
		int secondRandomIndex = rand() % primeNumbers.size();

		if (secondRandomIndex == firstRandomIndex)
		{
			secondRandomIndex++;
			secondRandomIndex %= primeNumbers.size();
		}

		p = primeNumbers[firstRandomIndex];
		q = primeNumbers[secondRandomIndex];

		n = p * q;
		m = (p - 1) * (q - 1);
		//textBox4->Text = Convert::ToString(m);
		//textBox3->Text = Convert::ToString(n);
		d = calculateD(m);
		e = calculateE(d, m);

		String^ result("");

		result += "p = " + Convert::ToString(p) + ", ";
		result += "q = " + Convert::ToString(q) + ", ";
		result += "n = " + Convert::ToString(n) + ", ";
		result += "m = " + Convert::ToString(m) + ", ";
		result += "d = " + Convert::ToString(d) + ", ";
		result += "e = " + Convert::ToString(e);
		
		evaluatedResultsLabel->Text = result;

		     button4->Enabled = true;
     //button3->Enabled = true;
     button1->Enabled = false;
     //textBox1->Enabled = false;
     //textBox2->Enabled = false;
		
		//textBox6->Text = Convert::ToString(d);
		//textBox5->Text = Convert::ToString(e);
		
		//if (textBox1->Text == "" || textBox2->Text == "")
		//{
		//	MessageBox::Show("Введите данные");
		//}
		//else
		//{


			// long p_ = Convert::ToInt64(textBox1->Text);
			// long q_ = Convert::ToInt64(textBox2->Text);
			// bool fl1 = is_simple(p_); //Проверка чисел на простоту
			// bool fl2 = is_simple(q_); //
			// if (fl1 == true && fl2 == true)
			// {
			//     setp(p_);
			//     setq(q_);
			//     button4->Enabled = true;
			//     button3->Enabled = true;
			//     button1->Enabled = false;
			//     textBox1->Enabled = false;
			//     textBox2->Enabled = false;
			// }
			// else
			// {
			//     MessageBox::Show("Введите простые числа p и q");
			// }
		//}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   void set_new_n(long ss)
		   {
			   n_new = ss;
		   }
		   void set_new_d(long ss)
		   {
			   d_new = ss;
		   }
		   void setp(long ss)
		   {
			   p = ss;
		   }
		   void setq(long ss)
		   {
			   q = ss;
			   set_n_and_m();
		   }
		   void set_n_and_m()
		   {
			   n = p * q;
			   m = (p - 1) * (q - 1);
			   //textBox4->Text = Convert::ToString(m);
			   //textBox3->Text = Convert::ToString(n);
			   d = calculateD(m);
			   e = calculateE(d, m);
			   //textBox6->Text = Convert::ToString(d);
			   //textBox5->Text = Convert::ToString(e);
		   }
		   long int calculateD(long m)
		   {
			   long d = m - 1;
			   for (long i = 2; i <= m; i++)
			   {
				   if ((m % i == 0) && (d % i == 0)) //если имеют общие делители
				   {
					   d--;
					   i = 1;
				   }
			   }
			   return d;
		   }
		   long int calculateE(long d, long m)
		   {
			   long e = 10;
			   while (true)
			   {
				   if ((e * d) % m == 1 && e != d)
					   break;
				   else
					   e++;
			   }
			   return e;
		   }
		   //bool is_simple(long number)
		   //{
			  // if (number < 2)
				 //  return false;
			  // if (number == 2)
				 //  return true;
			  // for (long i = 2; i < number; i++)
				 //  if (number % i == 0)
					//   return false;
			  // return true;
		   //}
		   list<string> RsaEncode(string s, long ee, long n) //Шифрование
		   {
			   list<string> result;
			   BigInteger bi;
			   for (int i = 0; i < s.length(); i++)
			   {
				   int index = 0;
				   for (int j = 0; j < 12; j++)
				   {
					   if (characters[j] == s[i])
					   {
						   index = j + 1;
						   break;
					   }
				   }
				   bi = index;//hash(index);//hash_char(s[i]); //= index;
				   if (i != 0)
				   {
					   result_hash = result_hash + " ";
				   }
				   result_hash = result_hash +
					   marshal_as<std::string>(bi.ToString());
				   bi = BigInteger::Pow(bi, ee);
				   BigInteger n_ = (int)n;
				   bi = bi % n;
				   list<string>::iterator it = result.end();

				   result.push_back(marshal_as<std::string>(bi.ToString()));
			   }
			   return result;
		   }
		   string RsaDecode(list<int> input, long d__, long n__) //Расшифровка
		   {
			   string result = "";
			   BigInteger bi;
			   for (list<int>::iterator it = input.begin(); it != input.end(); ++it)
			   {
				   if (it != input.begin())
				   {
					   result = result + " ";
				   }
				   int s = *it;
				   bi = s;
				   bi = BigInteger::Pow(bi, d__);
				   bi = bi % n__;
				   result = result +
					   marshal_as<std::string>(bi.ToString());//characters[index].ToString();
			   }
			   return result;
		   }
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ ev) {
		//button3->Enabled = false;
		button7->Enabled = true;
		textBox9->Enabled = true;
		textBox11->Enabled = true;
		//textBox6->Text = "";
		//textBox3->Text = "";
		result = RsaEncode(fileData, e, n);
		list<string>::iterator it;
		for (list<string>::iterator it = result.begin(); it != result.end(); ++it)
		{
			if (it != result.begin())
			{
				hash_of_str = hash_of_str + " ";
			}
			hash_of_str = hash_of_str + *it;
		}
		textBox8->Text = marshal_as<System::String^>(hash_of_str);
		ofstream outfile("hash_out.txt");
		for (list<string>::iterator it = result.begin(); it != result.end(); ++it)
		{
			outfile << *it << endl;
		}
		textBox12->Text = marshal_as<System::String^>(result_hash);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		//textBox6->Text = "";
		//textBox3->Text = "";
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		button2->Enabled = true;
		string fg;
		ifstream infile("in.txt");
		if (infile.is_open())
		{
			while (getline(infile, fg))
			{
				fileData = fileData + " " + fg.c_str();
			}
		}

		
		textBox7->Text = marshal_as<System::String^>(fileData);
		size_t hash = stringHashFunction(fileData);
		fileData = to_string(hash);
		textBox13->Text = marshal_as<String^>(fileData);
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		button5->Enabled = true;
		textBox9->Enabled = false;
		textBox11->Enabled = false;

		n_new = Convert::ToInt64(textBox11->Text);
		d_new = Convert::ToInt64(textBox9->Text);
		//set_new_n(Convert::ToInt64(textBox11->Text));
		//set_new_d(Convert::ToInt64(textBox9->Text));
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {

		//button5->Enabled = true;
		//textBox9->Enabled = false;
		//textBox11->Enabled = false;

		n_new = Convert::ToInt64(textBox11->Text);
		d_new = Convert::ToInt64(textBox9->Text);
		
		//button5->Enabled = false;
		result_two.clear();
		textBox10->Text = "";
		string fg;
		ifstream infile("hash_out.txt");
		if (infile.is_open())
		{			
			while (getline(infile, fg))
			{
				result_two.push_back(stoi(fg));
			}
		}

		fileHashDataLabel->Text = marshal_as<System::String^>(fileData);
		fileSignLabel->Text = marshal_as<System::String^>(RsaDecode(result_two, d_new, n_new));

		estimatedSignLabel->Text = textBox12->Text;	


		
		
		solutionLabel->Text = estimatedSignLabel->Text == fileSignLabel->Text
			? marshal_as<System::String^>("Подпись верна")
			: marshal_as<System::String^>("Подпись неверна");
			
			
			
		
		//textBox10->Text = marshal_as<System::String^>(RSA_Decode(result_two, d_new, n_new));
		//button6->Enabled = true;
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox12->Text == textBox10->Text)
		{
			MessageBox::Show("Подпись подлинная. Ключи верны");
		}
		else
		{
			MessageBox::Show("Подпись подделана. Ключи не верны");
		}
		textBox9->Enabled = true;
		textBox11->Enabled = true;
	}
	private: System::Void evaluatedResultsLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox9_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
