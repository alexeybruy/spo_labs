#pragma once

namespace Curs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			RefreshColorPanel();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ redUpButton;
	protected:
	private: System::Windows::Forms::Button^ redDownButton;
	private: System::Windows::Forms::Button^ greenUpButton;
	private: System::Windows::Forms::Button^ greenDownButton;
	private: System::Windows::Forms::Button^ blueUpButton;
	private: System::Windows::Forms::Button^ blueDownButton;
	private: System::Windows::Forms::Panel^ colorPanel;


	private: int changeColorStep = 20;

	private: int redColorComponent = 240;
	private: int greenColorComponent = 200;
	private: int blueColorComponent = 60;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->redUpButton = (gcnew System::Windows::Forms::Button());
			this->redDownButton = (gcnew System::Windows::Forms::Button());
			this->greenUpButton = (gcnew System::Windows::Forms::Button());
			this->greenDownButton = (gcnew System::Windows::Forms::Button());
			this->blueUpButton = (gcnew System::Windows::Forms::Button());
			this->blueDownButton = (gcnew System::Windows::Forms::Button());
			this->colorPanel = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// redUpButton
			// 
			this->redUpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->redUpButton->Location = System::Drawing::Point(12, 12);
			this->redUpButton->Name = L"redUpButton";
			this->redUpButton->Size = System::Drawing::Size(160, 30);
			this->redUpButton->TabIndex = 0;
			this->redUpButton->Text = L"красный +";
			this->redUpButton->UseVisualStyleBackColor = true;
			this->redUpButton->Click += gcnew System::EventHandler(this, &Main::redUpButton_Click);
			// 
			// redDownButton
			// 
			this->redDownButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->redDownButton->Location = System::Drawing::Point(12, 41);
			this->redDownButton->Name = L"redDownButton";
			this->redDownButton->Size = System::Drawing::Size(160, 30);
			this->redDownButton->TabIndex = 1;
			this->redDownButton->Text = L"красный -";
			this->redDownButton->UseVisualStyleBackColor = true;
			this->redDownButton->Click += gcnew System::EventHandler(this, &Main::redDownButton_Click);
			// 
			// greenUpButton
			// 
			this->greenUpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->greenUpButton->Location = System::Drawing::Point(12, 89);
			this->greenUpButton->Name = L"greenUpButton";
			this->greenUpButton->Size = System::Drawing::Size(160, 30);
			this->greenUpButton->TabIndex = 2;
			this->greenUpButton->Text = L"зеленый +";
			this->greenUpButton->UseVisualStyleBackColor = true;
			this->greenUpButton->Click += gcnew System::EventHandler(this, &Main::greenUpButton_Click);
			// 
			// greenDownButton
			// 
			this->greenDownButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->greenDownButton->Location = System::Drawing::Point(12, 118);
			this->greenDownButton->Name = L"greenDownButton";
			this->greenDownButton->Size = System::Drawing::Size(160, 30);
			this->greenDownButton->TabIndex = 3;
			this->greenDownButton->Text = L"зеленый -";
			this->greenDownButton->UseVisualStyleBackColor = true;
			this->greenDownButton->Click += gcnew System::EventHandler(this, &Main::greenDownButton_Click);
			// 
			// blueUpButton
			// 
			this->blueUpButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->blueUpButton->Location = System::Drawing::Point(12, 171);
			this->blueUpButton->Name = L"blueUpButton";
			this->blueUpButton->Size = System::Drawing::Size(160, 30);
			this->blueUpButton->TabIndex = 4;
			this->blueUpButton->Text = L"синий +";
			this->blueUpButton->UseVisualStyleBackColor = true;
			this->blueUpButton->Click += gcnew System::EventHandler(this, &Main::blueUpButton_Click);
			// 
			// blueDownButton
			// 
			this->blueDownButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->blueDownButton->Location = System::Drawing::Point(12, 200);
			this->blueDownButton->Name = L"blueDownButton";
			this->blueDownButton->Size = System::Drawing::Size(160, 30);
			this->blueDownButton->TabIndex = 5;
			this->blueDownButton->Text = L"синий -";
			this->blueDownButton->UseVisualStyleBackColor = true;
			this->blueDownButton->Click += gcnew System::EventHandler(this, &Main::blueDownButton_Click);
			// 
			// colorPanel
			// 
			this->colorPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->colorPanel->Location = System::Drawing::Point(227, 12);
			this->colorPanel->Name = L"colorPanel";
			this->colorPanel->Size = System::Drawing::Size(286, 211);
			this->colorPanel->TabIndex = 6;
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(525, 260);
			this->Controls->Add(this->colorPanel);
			this->Controls->Add(this->blueDownButton);
			this->Controls->Add(this->blueUpButton);
			this->Controls->Add(this->greenDownButton);
			this->Controls->Add(this->greenUpButton);
			this->Controls->Add(this->redDownButton);
			this->Controls->Add(this->redUpButton);
			this->Name = L"Main";
			this->Text = L"Бруй А.А. / Курсовой проект СПО ";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void redUpButton_Click(System::Object^ sender, System::EventArgs^ e) {		
		redColorComponent = IncreaseColor(redColorComponent);
		RefreshColorPanel();
	}
	private: System::Void redDownButton_Click(System::Object^ sender, System::EventArgs^ e) {
		redColorComponent = DecreaseColor(redColorComponent);
		RefreshColorPanel();
	}
	private: System::Void greenUpButton_Click(System::Object^ sender, System::EventArgs^ e) {
		greenColorComponent = IncreaseColor(greenColorComponent);
		RefreshColorPanel();
	}
	private: System::Void greenDownButton_Click(System::Object^ sender, System::EventArgs^ e) {
		greenColorComponent = DecreaseColor(greenColorComponent);
		RefreshColorPanel();
	}
	private: System::Void blueUpButton_Click(System::Object^ sender, System::EventArgs^ e) {
		blueColorComponent = IncreaseColor(blueColorComponent);
		RefreshColorPanel();
	}
	private: System::Void blueDownButton_Click(System::Object^ sender, System::EventArgs^ e) {
		blueColorComponent = DecreaseColor(blueColorComponent);
		RefreshColorPanel();
	}

	private: int IncreaseColor(int prevColor)
	{
		int newColor = prevColor + changeColorStep;

		return newColor > 256 ? prevColor : newColor;
	}

	private: int DecreaseColor(int prevColor)
	{
		int newColor = prevColor - changeColorStep;
		
		return newColor < 0 ? prevColor : newColor;
	}

	private: void RefreshColorPanel()
	{
		colorPanel->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(redColorComponent)),
			static_cast<System::Int32>(static_cast<System::Byte>(greenColorComponent)),
			static_cast<System::Int32>(static_cast<System::Byte>(blueColorComponent)));
	}
	};
}
