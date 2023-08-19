#include "MyForm.h"
#include "Origine.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Calcolo.h"

using namespace System;
using namespace System::Windows::Forms;




[STAThread]



void mainn() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project3::MyForm form;
	Application::Run(% form);

}


void showr(string s, int val) {
	main(s, val);
}

double* callcalc(double vel1, double ang1, double vel2, double ang2, double hz) {
	return calcola(vel1, ang1, vel2, ang2, hz);
}

void setside(int a) {
	setSide(a);
}


//int getSide() {
//	if (side == "Destra") {
//		return 1;
//	}
//	else return 2;
//}
 