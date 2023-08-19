#define _USE_MATH_DEFINES
#include<math.h>
#include <cmath>
#include "Calcolo.h"

using namespace std;

double riss;			//risultato peggiore
int side = 1;			//LEFT

double* calcola(double vel1, double ang1, double vel2, double ang2, double hz) {
	double vel1ms = vel1 / 3.6;					//calcolo la velocità dell'attaccante in ms
	double vel2ms = vel2 / 3.6;					//calcolo la velocità del difensore in ms
	double ang1r = (ang1 / 180) * M_PI;			//calcolo l'angolazione dell'attaccante in radianti
	double ang2r = (ang2 / 180) * M_PI;			//calcolo l'angolazione del difensore in radianti
	
	double velfms = (vel1ms * cos(ang1r)) - (vel2ms * cos(ang2r));			//calcolo la velocità relativa dell'attaccante rispetto al difensore

	double camp = 1.0 / hz;						//calcolo quanto passa tra un frame e il successivo

	double* ris = new double[3];
	ris[0] = (velfms * (camp / 10.0))*100;		//risultato caso migliore
	ris[1] = (velfms * (camp / 2.0)) * 100;		//risultato caso medio
	ris[2] = (velfms * (camp)) * 100;			//risultato caso peggiore

	riss = ris[2];							//memorizzo il risultato peggiore
	return ris;
}

void setSide(int a) {
	side = a;
}


double getris() {
	return riss*side;						//mostro l'incertezza a destra o a sinistra, in base al lato verso la quale attacco
}