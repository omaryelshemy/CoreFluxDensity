#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <msclr/marshal_cppstd.h>  // For marshaling System::String^ to std::string
#using <System.dll>

namespace CoreFluxDensity {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		std::string ConvertSystemStringToStdString(String^ sysStr) //This function was made with help from ChatGPT
		{
			// Marshal the System::String^ to a std::string
			std::string stdStr = msclr::interop::marshal_as<std::string>(sysStr);

			return stdStr;
		}

		double convertToRadians(double degree_value) { //Converts Degrees to Radians
			double radian_value = degree_value * 3.141592653589 / 180;
			return radian_value;
		}

		double calculateMu(System::String^ material, double B_value) { //Finds Mu Value for a Given B Value
			double mu_value = 0;
			B_value = abs(B_value);

			try {
				if (material == "M100" || material == "M105") {
					mu_value = 82470;
					if (B_value >= 2.08) {
						mu_value = 1;
					}
					else if (B_value > 1.14) {
						mu_value = 2.384e6 - 6.411e6 * B_value + 6.587e6 * pow(B_value, 2) - 2.942e6 * pow(B_value, 3) + 4.767e5 * pow(B_value, 4);
					}
					else {}

					if (mu_value < 1) {
						mu_value = 1;
					}
					else if (mu_value > 82470) {
						mu_value = 82470;
					}
				}
				else {
					mu_value = 71620;
					if (B_value >= 2.08) {
						mu_value = 1;
					}
					else if (B_value > 1.16) {
						mu_value = -3.209e5 + 8.652e5 * B_value - 5.965e5 * pow(B_value, 2) + 1.223e5 * pow(B_value, 3);
					}
					else {}

					if (mu_value < 1) {
						mu_value = 1;
					}
				}
			}
			catch (std::exception e) {}

			return mu_value;
		}

		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;

	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Core Flux Density";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Window Height (m)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(14, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(167, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Distance Between Main Limbs (m)";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(14, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(223, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Distance Between Main and Return Limbs (m)";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(14, 53);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(101, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Core Dimensions";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(14, 179);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(153, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Cross Section Dimensions";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(14, 209);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(160, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Cross Section of Main Limbs (m²)";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(14, 240);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(163, 13);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Cross Section of Main Yokes (m²)";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(14, 270);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(166, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Cross Section of Return Parts (m²)";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(14, 304);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(161, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Flux Density Measurements";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(14, 336);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(147, 13);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Flux Density in Main Limbs (T)";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(245, 81);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 11;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(245, 112);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 12;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(245, 144);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 13;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(245, 206);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 14;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(245, 237);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 15;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(245, 267);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 16;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(245, 333);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 17;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(14, 368);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(52, 13);
			this->label12->TabIndex = 19;
			this->label12->Text = L"Material";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(14, 397);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(44, 13);
			this->label13->TabIndex = 20;
			this->label13->Text = L"Material";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(503, 206);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(0, 29);
			this->label14->TabIndex = 22;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 428);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(328, 23);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Calculate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"M075", L"M080", L"M100", L"M105", L"M115", L"M120" });
			this->comboBox1->Location = System::Drawing::Point(245, 394);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 21);
			this->comboBox1->TabIndex = 23;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(851, 463);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MyForm";
			this->Text = L"CoreFluxDensity";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		//Program Initalization/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Example data points (you can modify this array)
		System::String^ material;
		int error = 0;

		try {
			material = comboBox1->Text;
		}
		catch (System::Exception^ e) {
			error = -1; //Material error
		}

		if (material == "M100" || material == "M105" || material == "M075" || material == "M080" || material == "M115" || material == "M120") {}
		else {
			error = -1; //Material error
		}

		//Input Variable Initalization//////////////////////////////////////////////////////////////////////////////////////////////////////////////

		double windowHeight = 0;
		double dMainLimbs = 0;
		double dMainReturnLimbs = 0;
		double csMainLimbs = 0;
		double csMainYokes = 0;
		double csReturnParts = 0;
		double flMainLimbs = 0;

		try {
			windowHeight = System::Convert::ToDouble(textBox1->Text);
			dMainLimbs = System::Convert::ToDouble(textBox2->Text);
			dMainReturnLimbs = System::Convert::ToDouble(textBox3->Text);
			csMainLimbs = System::Convert::ToDouble(textBox4->Text);
			csMainYokes = System::Convert::ToDouble(textBox5->Text);
			csReturnParts = System::Convert::ToDouble(textBox6->Text);
			flMainLimbs = System::Convert::ToDouble(textBox7->Text);
		}
		catch (System::Exception^ e) {
			error = -2; //Input Error
		}

		//Program Calculations//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (error == 0) {
			double B1i = 0, B1j = 0;  // Initialization for B1
			double B2i = 0, B3i = 0;  // Initialization for B2
			double B2j = 0, B3j = 0;  // Initialization for B3
			double maxB1 = 0, maxB2 = 0, maxB3 = 0;
			double B1iNew = 0, B1jNew = 0;
			double B1k = 0;
			double B_values[361][4];

			double mu1i = 0, mu2i = 0, mu3i = 0;
			double mu1j = 0, mu2j = 0, mu3j = 0;

			double Lr = windowHeight + 2 * dMainReturnLimbs;
			double Lm = 2 * dMainLimbs;

			std::ofstream FileOut("FluxValues.csv");
			if (!FileOut) {
				label14->Text = "File Open Error!";
			}

			bool once = false;

			// Iterate over angles
			for (int phi = 0; phi <= 360; phi++) {
				double root = 0;
				double rootB1i = 18;
				double rootB1j = 18;

				// Reset B1 guesses for each angle
				B1i = -1.7;  // Reset initial guess for B1i
				B1j = 1.7; // Reset initial guess for B1j

				// Iterate on B1 for convergence (secant method)

				do {
					// Calculate Mu1 for both B1i and B1j
					mu1i = calculateMu(material, B1i);
					mu1j = calculateMu(material, B1j);

					// Calculate B2, B3, Mu2, Mu3 for both B1i and B1j
					B2i = flMainLimbs * (csMainLimbs / csMainYokes) * sin(convertToRadians(phi)) - (csReturnParts / csMainYokes) * B1i;
					mu2i = calculateMu(material, B2i);

					B2j = flMainLimbs * (csMainLimbs / csMainYokes) * sin(convertToRadians(phi)) - (csReturnParts / csMainYokes) * B1j;
					mu2j = calculateMu(material, B2j);

					B3i = flMainLimbs * (csMainLimbs / csMainYokes) * sin(convertToRadians(phi + 240)) + (csReturnParts / csMainYokes) * B1i;
					mu3i = calculateMu(material, B3i);

					B3j = flMainLimbs * (csMainLimbs / csMainYokes) * sin(convertToRadians(phi + 240)) + (csReturnParts / csMainYokes) * B1j;
					mu3j = calculateMu(material, B3j);

					//Calculate new B1 values for both i and j
					double B1num = flMainLimbs * csMainLimbs * (sin(convertToRadians(phi)) - sin(convertToRadians(phi + 240)) * (mu2i / mu3i));
					double B1denom = csReturnParts * (2 * (Lr / Lm) * (mu2i / mu1i) * (csMainYokes / csReturnParts) + 1 + (mu2i / mu3i));
					B1iNew = B1num / B1denom;
					rootB1i = pow(B1iNew - B1i, 2);

					B1num = flMainLimbs * csMainLimbs * (sin(convertToRadians(phi)) - sin(convertToRadians(phi + 240)) * (mu2j / mu3j));
					B1denom = csReturnParts * (2 * (Lr / Lm) * (mu2j / mu1j) * (csMainYokes / csReturnParts) + 1 + (mu2j / mu3j));
					B1jNew = B1num / B1denom;
					rootB1j = pow(B1jNew - B1j, 2);

					//Calculate B1k and Root
					B1k = B1j - rootB1j * ((B1j - B1i) / (rootB1j - rootB1i));
					root = pow(B1k - B1j, 2);

					// Update B1 for next iteration
					B1i = B1j;
					B1j = B1k;
				} while (root >= 1e-27);

				// std::cout << "B1k: " << B1k << std::endl << std::endl;

				B_values[phi][0] = B1k;
				B_values[phi][1] = flMainLimbs * (csMainLimbs / csMainYokes) * sin(convertToRadians(phi)) - (csReturnParts / csMainYokes) * B1k;
				B_values[phi][2] = flMainLimbs * (csMainLimbs / csMainYokes) * sin(convertToRadians(phi + 240)) + (csReturnParts / csMainYokes) * B1k;
				B_values[phi][3] = flMainLimbs * sin(convertToRadians(phi));

				if (B1k > maxB1) {
					maxB1 = B1k;
				}
				if (B_values[phi][1] > maxB2) {
					maxB2 = B_values[phi][1];
				}
				if (B_values[phi][2] > maxB3) {
					maxB3 = B_values[phi][2];
				}
			}

			FileOut << "Window Height," << windowHeight << std::endl;
			FileOut << "Distance Between Main Limbs," << dMainLimbs << std::endl;
			FileOut << "Distance Between Main and Return Limbs," << dMainReturnLimbs << std::endl;
			FileOut << "Cross Section of Main Limbs," << csMainLimbs << std::endl;
			FileOut << "Cross Section of Main Yokes," << csMainYokes << std::endl;
			FileOut << "Cross Section of Return Parts," << csReturnParts << std::endl;
			FileOut << "Flux Density in Main Limbs," << flMainLimbs << std::endl;
			FileOut << "Material," << ConvertSystemStringToStdString(material) << std::endl << std::endl;

			FileOut << "Maximum Br," << maxB1 << std::endl;
			FileOut << "Maximum Bmy1," << maxB2 << std::endl;
			FileOut << "Maximum Bmy2, " << maxB3 << std::endl << std::endl;

			FileOut << "Phi,Br,Bmy1,Bmy2,B" << std::endl;
			for (int phi = 0; phi <= 360; ++phi) {
				FileOut << phi << "," << B_values[phi][0] << "," << B_values[phi][1] << "," << B_values[phi][2] << "," << B_values[phi][3] << std::endl;
			}

			// Close the output file
			FileOut.close();

			label14->Text = "Calculation Successful!";
		}

		else if (error < 0) {
			if (error == -1) {
				label14->Text = "Material Error!";
			}
			else {
				label14->Text = "Input Error!";
			}
		}
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}