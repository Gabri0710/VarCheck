#pragma once
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace std;

void showr(string s, int val);

double* callcalc(double vel1, double ang1, double vel2, double ang2, double hz);

void setside(int a);

int val = 0;

string sideA = "Destra";

//int getSide();

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	


	string s;
	/// <summary>
	/// Riepilogo per MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: aggiungere qui il codice del costruttore.
			//
		}

	protected:
		/// <summary>
		/// Pulire le risorse in uso.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label11;
	protected:

	private:
		/// <summary>
		/// Variabile di progettazione necessaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metodo necessario per il supporto della finestra di progettazione. Non modificare
		/// il contenuto del metodo con l'editor di codice.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(15, 434);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(113, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Scegli immagine";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(506, 463);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(111, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Avanti";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(151, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(272, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Che immagine vuoi analizzare\?";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 530);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Immagine scelta: ";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(15, 489);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(113, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Scegli video";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(273, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Inserisci la velocità lungo l\'asse x dell\'attaccante in km/h";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 82);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(252, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Inserisci l\'angolazione del movimento dell\'attaccante";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 118);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(264, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Inserisci la velocità lungo l\'asse x del difensore in km/h";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(12, 156);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(243, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Inserisci l\'angolazione del movimento del difensore";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(274, 234);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Calcola";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(197, 285);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(121, 13);
			this->label7->TabIndex = 10;
			this->label7->Text = L"                                     -";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(197, 310);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(121, 13);
			this->label8->TabIndex = 11;
			this->label8->Text = L"                                     -";
			this->label8->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(197, 335);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(121, 13);
			this->label9->TabIndex = 12;
			this->label9->Text = L"                                     -";
			this->label9->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(417, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 13;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(417, 82);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 14;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(417, 118);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 15;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(417, 156);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 16;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(12, 193);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(218, 13);
			this->label10->TabIndex = 17;
			this->label10->Text = L"Inserisci il numero di Hertz della videocamera";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(417, 193);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 18;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Destra", L"Sinistra" });
			this->comboBox1->Location = System::Drawing::Point(274, 388);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 19;
			this->comboBox1->SelectedIndex = 1;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(12, 391);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(172, 13);
			this->label11->TabIndex = 20;
			this->label11->Text = L"In che direzione si sta attaccando\?";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(629, 564);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		Stream^ myStream;
		OpenFileDialog^ openFileDialogl = gcnew OpenFileDialog;

		openFileDialogl->InitialDirectory = "c:\\";
		openFileDialogl->Filter = "jpeg files (*.jpeg)|*.jpeg|jpg files (*.jpg)|*.jpg|png files (*.png)|*.png";
		openFileDialogl->FilterIndex = 2;
		openFileDialogl->RestoreDirectory = true;

		if (openFileDialogl->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = openFileDialogl->OpenFile()) != nullptr)
			{
				
				s = msclr::interop::marshal_as<std::string>(openFileDialogl->FileName);
				val = 1;

				label2->Text = "Immagine scelta: " + openFileDialogl->FileName;
				button2->Enabled = true;

				myStream->Close();
			}
		}
	
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
		sideA = msclr::interop::marshal_as<std::string>(comboBox1->SelectedItem->ToString());
		if (sideA == "Destra") {
			setside(-1);
		}
		else if (sideA == "Sinistra") {
			setside(1);
		}
		showr(s, val);
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Stream^ myStream;
		OpenFileDialog^ openFileDialogl = gcnew OpenFileDialog;

		openFileDialogl->InitialDirectory = "c:\\";
		openFileDialogl->Filter = "mp4 files (*.mp4)|*.mp4|avi files (*.avi)|*.avi";
		openFileDialogl->FilterIndex = 2;
		openFileDialogl->RestoreDirectory = true;

		if (openFileDialogl->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if ((myStream = openFileDialogl->OpenFile()) != nullptr)
			{

				s = msclr::interop::marshal_as<std::string>(openFileDialogl->FileName);
				val = 2;

				label2->Text = "Video scelto: " + openFileDialogl->FileName;
				button2->Enabled = true;

				myStream->Close();
			}
		}
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	double vel1 = Convert::ToDouble(textBox1->Text);
	double ang1 = Convert::ToDouble(textBox2->Text);
	double vel2 = Convert::ToDouble(textBox3->Text);
	double ang2 = Convert::ToDouble(textBox4->Text);
	double hz = Convert::ToDouble(textBox5->Text);
	

	double* ris;

	ris= callcalc(vel1, ang1, vel2, ang2, hz);
	
	//double ris = callcalc(vel1, ang1, vel2, ang2, hz);
	String^ ris1 = gcnew String(to_string(ris[0]).c_str());
	String^ ris2 = gcnew String(to_string(ris[1]).c_str());
	String^ ris3 = gcnew String(to_string(ris[2]).c_str());
	label7->Text = "L'incertezza nel caso migliore è di " + ris1 + " cm";
	label8->Text = "L'incertezza nel caso medio è di " + ris2 + " cm";
	label9->Text = "L'incertezza nel caso peggiore è di " + ris3 + " cm";



	//string ris1 = to_string(ris);
	//String^ ris2 = gcnew String(ris1.c_str());
	//label7->Text = "L'incertezza nel caso peggiore è di " + ris2 + " cm";
	

	button1->Enabled = true;
	button3->Enabled = true;
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
