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
	char* characters = new char[12]{ '#', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-' };
	vector<int> primeNumbers
	{
		11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199
	};

	long p;
	long q;
	long m;
	long n;
	long d;
	long e;
	long newN;
	long newD;
	std::hash<char> hashChar;
	std::hash<std::string>stringHashFunction;
	string fileData;
	string hashOfString;
	string resultHash;
	std::hash<int> hash;
	list<string> firstResult;
	list<int> secondResult;
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

	private: System::Windows::Forms::GroupBox^ secondStepGroupBox;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ encryptedSignTextBox;
	private: System::Windows::Forms::TextBox^ fileStringTextBox;
	private: System::Windows::Forms::Button^ generateSignButton;
	private: System::Windows::Forms::Label^ label8;

	private: System::Windows::Forms::Button^ openFileButton;
	private: System::Windows::Forms::GroupBox^ fourthStepGroupBox;
	private: System::Windows::Forms::TextBox^ newDInputTextBox;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ verifyButton;

	private: System::Windows::Forms::TextBox^ newNInputTextBox;
	private: System::Windows::Forms::Label^ label11;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ signTextBox;

	private: System::Windows::Forms::Label^ evaluatedResultsLabel;
	private: System::Windows::Forms::GroupBox^ thirdStepGroupBox;
	private: System::Windows::Forms::GroupBox^ firstStepGroupBox;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ hashDataTextBox;
	private: System::Windows::Forms::Label^ fileSignLabel;
	private: System::Windows::Forms::Label^ estimatedSignLabel;

	private: System::Windows::Forms::Label^ fileHashDataLabel;
	private: System::Windows::Forms::Label^ solutionLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
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
			this->secondStepGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->openFileButton = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->fileStringTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->signTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->generateSignButton = (gcnew System::Windows::Forms::Button());
			this->encryptedSignTextBox = (gcnew System::Windows::Forms::TextBox());
			this->fourthStepGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->solutionLabel = (gcnew System::Windows::Forms::Label());
			this->fileSignLabel = (gcnew System::Windows::Forms::Label());
			this->estimatedSignLabel = (gcnew System::Windows::Forms::Label());
			this->fileHashDataLabel = (gcnew System::Windows::Forms::Label());
			this->newNInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->newDInputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->verifyButton = (gcnew System::Windows::Forms::Button());
			this->evaluatedResultsLabel = (gcnew System::Windows::Forms::Label());
			this->thirdStepGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->hashDataTextBox = (gcnew System::Windows::Forms::TextBox());
			this->firstStepGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->secondStepGroupBox->SuspendLayout();
			this->fourthStepGroupBox->SuspendLayout();
			this->thirdStepGroupBox->SuspendLayout();
			this->firstStepGroupBox->SuspendLayout();
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
			this->secondStepGroupBox->Controls->Add(this->openFileButton);
			this->secondStepGroupBox->Controls->Add(this->label7);
			this->secondStepGroupBox->Controls->Add(this->fileStringTextBox);
			this->secondStepGroupBox->Location = System::Drawing::Point(17, 103);
			this->secondStepGroupBox->Margin = System::Windows::Forms::Padding(2);
			this->secondStepGroupBox->Name = L"groupBox3";
			this->secondStepGroupBox->Padding = System::Windows::Forms::Padding(2);
			this->secondStepGroupBox->Size = System::Drawing::Size(502, 152);
			this->secondStepGroupBox->TabIndex = 7;
			this->secondStepGroupBox->TabStop = false;
			this->secondStepGroupBox->Text = L"Шаг 2. Чтение файла";
			// 
			// button4
			// 
			this->openFileButton->Enabled = false;
			this->openFileButton->Location = System::Drawing::Point(305, 112);
			this->openFileButton->Margin = System::Windows::Forms::Padding(2);
			this->openFileButton->Name = L"button4";
			this->openFileButton->Size = System::Drawing::Size(189, 28);
			this->openFileButton->TabIndex = 9;
			this->openFileButton->Text = L"Открыть файл и вычислить хэш";
			this->openFileButton->UseVisualStyleBackColor = true;
			this->openFileButton->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(12, 24);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(107, 13);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Содержимое файла";
			// 
			// textBox7
			// 
			this->fileStringTextBox->Location = System::Drawing::Point(140, 24);
			this->fileStringTextBox->Margin = System::Windows::Forms::Padding(2);
			this->fileStringTextBox->Multiline = true;
			this->fileStringTextBox->Name = L"textBox7";
			this->fileStringTextBox->ReadOnly = true;
			this->fileStringTextBox->Size = System::Drawing::Size(354, 84);
			this->fileStringTextBox->TabIndex = 0;
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
			this->signTextBox->Location = System::Drawing::Point(166, 57);
			this->signTextBox->Margin = System::Windows::Forms::Padding(2);
			this->signTextBox->Name = L"textBox12";
			this->signTextBox->ReadOnly = true;
			this->signTextBox->Size = System::Drawing::Size(323, 20);
			this->signTextBox->TabIndex = 10;
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
			this->generateSignButton->Enabled = false;
			this->generateSignButton->Location = System::Drawing::Point(324, 105);
			this->generateSignButton->Margin = System::Windows::Forms::Padding(2);
			this->generateSignButton->Name = L"button2";
			this->generateSignButton->Size = System::Drawing::Size(165, 28);
			this->generateSignButton->TabIndex = 5;
			this->generateSignButton->Text = L"Сформировать попись";
			this->generateSignButton->UseVisualStyleBackColor = true;
			this->generateSignButton->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// textBox8
			// 
			this->encryptedSignTextBox->Location = System::Drawing::Point(166, 81);
			this->encryptedSignTextBox->Margin = System::Windows::Forms::Padding(2);
			this->encryptedSignTextBox->Name = L"textBox8";
			this->encryptedSignTextBox->ReadOnly = true;
			this->encryptedSignTextBox->Size = System::Drawing::Size(323, 20);
			this->encryptedSignTextBox->TabIndex = 1;
			// 
			// groupBox4
			// 
			this->fourthStepGroupBox->Controls->Add(this->label1);
			this->fourthStepGroupBox->Controls->Add(this->label2);
			this->fourthStepGroupBox->Controls->Add(this->label3);
			this->fourthStepGroupBox->Controls->Add(this->label4);
			this->fourthStepGroupBox->Controls->Add(this->solutionLabel);
			this->fourthStepGroupBox->Controls->Add(this->fileSignLabel);
			this->fourthStepGroupBox->Controls->Add(this->estimatedSignLabel);
			this->fourthStepGroupBox->Controls->Add(this->fileHashDataLabel);
			this->fourthStepGroupBox->Controls->Add(this->newNInputTextBox);
			this->fourthStepGroupBox->Controls->Add(this->label11);
			this->fourthStepGroupBox->Controls->Add(this->newDInputTextBox);
			this->fourthStepGroupBox->Controls->Add(this->label9);
			this->fourthStepGroupBox->Controls->Add(this->verifyButton);
			this->fourthStepGroupBox->Location = System::Drawing::Point(19, 412);
			this->fourthStepGroupBox->Margin = System::Windows::Forms::Padding(2);
			this->fourthStepGroupBox->Name = L"groupBox4";
			this->fourthStepGroupBox->Padding = System::Windows::Forms::Padding(2);
			this->fourthStepGroupBox->Size = System::Drawing::Size(502, 283);
			this->fourthStepGroupBox->TabIndex = 10;
			this->fourthStepGroupBox->TabStop = false;
			this->fourthStepGroupBox->Text = L"Шаг 4. Проверка подписи";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 195);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 13);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Результат";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(18, 143);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 23;
			this->label2->Text = L"Подпись есть";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 170);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(120, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Подпись должна быть";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(18, 116);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 13);
			this->label4->TabIndex = 21;
			this->label4->Text = L"Хэш файла";
			this->label4->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// solutionLabel
			// 
			this->solutionLabel->AutoSize = true;
			this->solutionLabel->Location = System::Drawing::Point(150, 195);
			this->solutionLabel->Name = L"solutionLabel";
			this->solutionLabel->Size = System::Drawing::Size(16, 13);
			this->solutionLabel->TabIndex = 20;
			this->solutionLabel->Text = L"...";
			// 
			// fileSignLabel
			// 
			this->fileSignLabel->AutoSize = true;
			this->fileSignLabel->Location = System::Drawing::Point(150, 143);
			this->fileSignLabel->Name = L"fileSignLabel";
			this->fileSignLabel->Size = System::Drawing::Size(16, 13);
			this->fileSignLabel->TabIndex = 19;
			this->fileSignLabel->Text = L"...";
			// 
			// estimatedSignLabel
			// 
			this->estimatedSignLabel->AutoSize = true;
			this->estimatedSignLabel->Location = System::Drawing::Point(150, 170);
			this->estimatedSignLabel->Name = L"estimatedSignLabel";
			this->estimatedSignLabel->Size = System::Drawing::Size(16, 13);
			this->estimatedSignLabel->TabIndex = 18;
			this->estimatedSignLabel->Text = L"...";
			// 
			// fileHashDataLabel
			// 
			this->fileHashDataLabel->AutoSize = true;
			this->fileHashDataLabel->Location = System::Drawing::Point(150, 116);
			this->fileHashDataLabel->Name = L"fileHashDataLabel";
			this->fileHashDataLabel->Size = System::Drawing::Size(16, 13);
			this->fileHashDataLabel->TabIndex = 17;
			this->fileHashDataLabel->Text = L"...";
			// 
			// textBox11
			// 
			this->newNInputTextBox->Location = System::Drawing::Point(95, 33);
			this->newNInputTextBox->Margin = System::Windows::Forms::Padding(2);
			this->newNInputTextBox->Name = L"textBox11";
			this->newNInputTextBox->Size = System::Drawing::Size(76, 20);
			this->newNInputTextBox->TabIndex = 15;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(24, 33);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(67, 13);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Значение n:";
			// 
			// textBox9
			// 
			this->newDInputTextBox->Location = System::Drawing::Point(256, 33);
			this->newDInputTextBox->Margin = System::Windows::Forms::Padding(2);
			this->newDInputTextBox->Name = L"textBox9";
			this->newDInputTextBox->Size = System::Drawing::Size(76, 20);
			this->newDInputTextBox->TabIndex = 13;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(188, 33);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(67, 13);
			this->label9->TabIndex = 14;
			this->label9->Text = L"Значение d:";
			// 
			// button5
			// 
			this->verifyButton->Enabled = false;
			this->verifyButton->Location = System::Drawing::Point(16, 67);
			this->verifyButton->Margin = System::Windows::Forms::Padding(2);
			this->verifyButton->Name = L"button5";
			this->verifyButton->Size = System::Drawing::Size(192, 28);
			this->verifyButton->TabIndex = 9;
			this->verifyButton->Text = L"Извлечь подпись и проверить";
			this->verifyButton->UseVisualStyleBackColor = true;
			this->verifyButton->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// evaluatedResultsLabel
			// 
			this->evaluatedResultsLabel->AutoSize = true;
			this->evaluatedResultsLabel->Location = System::Drawing::Point(183, 39);
			this->evaluatedResultsLabel->Name = L"evaluatedResultsLabel";
			this->evaluatedResultsLabel->Size = System::Drawing::Size(16, 13);
			this->evaluatedResultsLabel->TabIndex = 11;
			this->evaluatedResultsLabel->Text = L"...";
			// 
			// groupBox1
			// 
			this->thirdStepGroupBox->Controls->Add(this->label13);
			this->thirdStepGroupBox->Controls->Add(this->signTextBox);
			this->thirdStepGroupBox->Controls->Add(this->hashDataTextBox);
			this->thirdStepGroupBox->Controls->Add(this->encryptedSignTextBox);
			this->thirdStepGroupBox->Controls->Add(this->label12);
			this->thirdStepGroupBox->Controls->Add(this->generateSignButton);
			this->thirdStepGroupBox->Controls->Add(this->label8);
			this->thirdStepGroupBox->Location = System::Drawing::Point(17, 260);
			this->thirdStepGroupBox->Name = L"groupBox1";
			this->thirdStepGroupBox->Size = System::Drawing::Size(502, 147);
			this->thirdStepGroupBox->TabIndex = 12;
			this->thirdStepGroupBox->TabStop = false;
			this->thirdStepGroupBox->Text = L"Шаг 3. Формирование подписи";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(15, 33);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(104, 13);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Хеш-данные файла";
			// 
			// textBox13
			// 
			this->hashDataTextBox->Location = System::Drawing::Point(166, 33);
			this->hashDataTextBox->Margin = System::Windows::Forms::Padding(2);
			this->hashDataTextBox->Name = L"textBox13";
			this->hashDataTextBox->ReadOnly = true;
			this->hashDataTextBox->Size = System::Drawing::Size(323, 20);
			this->hashDataTextBox->TabIndex = 12;
			// 
			// groupBox2
			// 
			this->firstStepGroupBox->Controls->Add(this->button1);
			this->firstStepGroupBox->Controls->Add(this->evaluatedResultsLabel);
			this->firstStepGroupBox->Location = System::Drawing::Point(17, 24);
			this->firstStepGroupBox->Name = L"groupBox2";
			this->firstStepGroupBox->Size = System::Drawing::Size(501, 74);
			this->firstStepGroupBox->TabIndex = 13;
			this->firstStepGroupBox->TabStop = false;
			this->firstStepGroupBox->Text = L"Шаг 1. Вычисление RSA";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(532, 706);
			this->Controls->Add(this->firstStepGroupBox);
			this->Controls->Add(this->thirdStepGroupBox);
			this->Controls->Add(this->fourthStepGroupBox);
			this->Controls->Add(this->secondStepGroupBox);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MainForm";
			this->Text = L"Lab7";
			this->secondStepGroupBox->ResumeLayout(false);
			this->secondStepGroupBox->PerformLayout();
			this->fourthStepGroupBox->ResumeLayout(false);
			this->fourthStepGroupBox->PerformLayout();
			this->thirdStepGroupBox->ResumeLayout(false);
			this->thirdStepGroupBox->PerformLayout();
			this->firstStepGroupBox->ResumeLayout(false);
			this->firstStepGroupBox->PerformLayout();
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

		openFileButton->Enabled = true;
		button1->Enabled = false;
	}
		   long int calculateD(long m)
		   {
			   long d = m - 1;
			   for (long i = 2; i <= m; i++)
			   {
				   if ((m % i == 0) && (d % i == 0))
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
		   list<string> RsaEncode(string s, long ee, long n)
		   {
			   list<string> result;
			   BigInteger bigValue;
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
				   bigValue = index;
				   if (i != 0)
				   {
					   resultHash = resultHash + " ";
				   }
				   resultHash = resultHash +
					   marshal_as<std::string>(bigValue.ToString());
				   bigValue = BigInteger::Pow(bigValue, ee);
				   BigInteger n_ = (int)n;
				   bigValue = bigValue % n;
				   list<string>::iterator it = result.end();

				   result.push_back(marshal_as<std::string>(bigValue.ToString()));
			   }
			   return result;
		   }
		   string RsaDecode(list<int> input, long d__, long n__)
		   {
			   string result = "";
			   BigInteger bigValue;
			   for (list<int>::iterator it = input.begin(); it != input.end(); ++it)
			   {
				   if (it != input.begin())
				   {
					   result = result + " ";
				   }
				   int s = *it;
				   bigValue = s;
				   bigValue = BigInteger::Pow(bigValue, d__);
				   bigValue = bigValue % n__;
				   result = result +
					   marshal_as<std::string>(bigValue.ToString());
			   }
			   return result;
		   }
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ ev) {
		verifyButton->Enabled = true;
		generateSignButton->Enabled = false;
		newDInputTextBox->Enabled = true;
		newNInputTextBox->Enabled = true;
		firstResult = RsaEncode(fileData, e, n);
		list<string>::iterator it;
		for (list<string>::iterator it = firstResult.begin(); it != firstResult.end(); ++it)
		{
			if (it != firstResult.begin())
			{
				hashOfString = hashOfString + " ";
			}
			hashOfString = hashOfString + *it;
		}
		encryptedSignTextBox->Text = marshal_as<System::String^>(hashOfString);
		ofstream outfile("sign.txt");
		for (list<string>::iterator it = firstResult.begin(); it != firstResult.end(); ++it)
		{
			outfile << *it << endl;
		}
		signTextBox->Text = marshal_as<System::String^>(resultHash);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		generateSignButton->Enabled = true;
		openFileButton->Enabled = false;

		string fg;
		ifstream infile("data.txt");
		if (infile.is_open())
		{
			while (getline(infile, fg))
			{
				fileData = fileData + " " + fg.c_str();
			}
		}

		fileStringTextBox->Text = marshal_as<System::String^>(fileData);
		size_t hash = stringHashFunction(fileData);
		fileData = to_string(hash);
		hashDataTextBox->Text = marshal_as<String^>(fileData);
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		verifyButton->Enabled = true;
		newDInputTextBox->Enabled = false;
		newNInputTextBox->Enabled = false;

		newN = Convert::ToInt64(newNInputTextBox->Text);
		newD = Convert::ToInt64(newDInputTextBox->Text);
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		generateSignButton->Enabled = false;

		newN = Convert::ToInt64(newNInputTextBox->Text);
		newD = Convert::ToInt64(newDInputTextBox->Text);

		secondResult.clear();
		string localSignData = "";
		string signFg;
		ifstream signFile("sign.txt");
		if (signFile.is_open())
		{
			while (getline(signFile, signFg))
			{
				auto val = stoi(signFg);

				localSignData = localSignData + " " + to_string(val);
				secondResult.push_back(val);
			}
		}

		string localFileData = "";
		string fileFg;
		ifstream inFile("data.txt");
		if (inFile.is_open())
		{
			while (getline(inFile, fileFg))
			{
				localFileData = localFileData + " " + fileFg.c_str();
			}
		}

		fileHashDataLabel->Text = marshal_as<System::String^>(to_string(stringHashFunction(localFileData)));
		fileSignLabel->Text = marshal_as<System::String^>(RsaDecode(secondResult, newD, newN));

		estimatedSignLabel->Text = signTextBox->Text;

		solutionLabel->Text = estimatedSignLabel->Text == fileSignLabel->Text
			? marshal_as<System::String^>("Подпись верна")
			: marshal_as<System::String^>("Подпись неверна");
	}
	};
}
