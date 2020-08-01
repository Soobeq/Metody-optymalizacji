#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// deklaracja funkcji dla wszystkich metod
double funkcja(double);

// funkcje wykorzystywane w metodach
bool sprawdzenie_iteracja(double, double, double);
double minimum_paraboliczna(double, double, double);
double pochodna(double);

//metody
double metoda_dzielenia_na_pol();
double metoda_iteracyjna();
double metoda_paraboliczna();
double metoda_zlotego_podzialu();
double metoda_najszybszego_spadku();

int main(int argc, char** argv) {

int case_switch;

	cout << "- METODY OPTYMALIZACJI	-" << endl ;
	cout << "- Sebastian Gorczak	-" << endl ;
	cout << "- nr: 341035 Uniwersytet Łódzki -" << endl << endl;
	
	cout << "WYBIERZ METODE SZUKANIA MINIMUM FUNKCJI : " << endl ;
    cout << "[1] Dzielenie przedzialu na pol" << endl ;
    cout << "[2] Iteracyjna" << endl ;
    cout << "[3] Interpolacja paraboliczna" << endl ;
	cout << "[4] Zloty podzial" << endl ;
	cout << "[5] Najszybszego spadku" << endl << endl ;
	     
	cout << "Podaj numer metody: " ;     
	cin >> case_switch;
    if(case_switch <1  || case_switch >5){
    	cout << "Wybrales niepoprawny parametr !" << endl;
	}
	
    switch( case_switch )
    {
    case 1:
    	system("cls"); 
		cout << "Metoda dzielenia przedzialu na pol." << endl<< endl;
		cout << metoda_dzielenia_na_pol() << endl;
        break;
    case 2:
        system("cls"); 
		cout << "Metoda iteracyjna." << endl;
		cout << metoda_iteracyjna();
        break;
    case 3:
        system("cls"); 
		cout << "Interpolacja paraboliczna." << endl;
		cout << metoda_paraboliczna();
        break;
    case 4:
        system("cls"); 
		cout << "Metoda zlotego podzialu." << endl;
		cout << metoda_zlotego_podzialu();
        break;
    case 5:
        system("cls"); 
		cout << "Metoda najszybszego spadku." << endl;
		cout << metoda_najszybszego_spadku();
        break;
    }
    return 0;

}

// globalna funkcja dla wszystkich metod
double funkcja(double x) { return (x+(1.0/(x*x))); }

// funkcja do sprawdzenia warunku w metodzie iteracyjnej
bool sprawdzenie_iteracja(double x0, double minimum, double iteracja) { return (funkcja(x0)<funkcja(minimum) && funkcja(x0-iteracja)>funkcja(x0) && funkcja(x0+iteracja)>funkcja(x0)); }

//funkcja do sprwdzenia do znajdowania minimum w metodzie parabolicznej
double minimum_paraboliczna(double a, double b, double c) {	return 0.5*(funkcja(a)*(b*b-c*c)+funkcja(b)*(c*c-a*a)+ funkcja(c)*(a*a-b*b))/(funkcja(a)*(b-c)+funkcja(b)*(c-a)+funkcja(c)*(a-b));; }

//fukcja dla metody najszybszego spadku 
double pochodna(double x) { return (1-(2/(x*x*x))); }

double metoda_dzielenia_na_pol(){
	
	int 	i=0;
	
	double 	a=1.0, a2=1.0, 
			b=2.0, b2=2.0,
			eps=0.00000000001;
	
	double 	dlugosc = b - a,
			xn = a + dlugosc / 2.0,
			x1 = a + dlugosc / 4.0,
			x2 = b - dlugosc / 4.0,
			f_x1 = funkcja(x1),
			f_x2 = funkcja(x2),
			f_xn = funkcja(xn);

	
	while (dlugosc > eps) {
		
		dlugosc = b - a;
		x1 = a + dlugosc / 4.0;
		x2 = b - dlugosc / 4.0;
		f_x1 = funkcja(x1);
		f_x2 = funkcja(x2);
		
		//cout << "["<< x1 << ", " << x2 << "] " << endl;
		
		if (f_x1 < f_xn) {
			a = a;
			b = xn;
			xn = x1;
			f_xn = f_x1;
		}
		
		else if (f_x2 <  f_xn) {
			a = xn;
			b = b;
			xn = x2;
			f_xn = f_x2;
		}
		
		else {
			a = x1;
			b = x2;
			xn = xn;
		}
		i++;
	}
	cout << endl << endl << "Wynik dla danych wejsciowych: " << endl;
	
	cout << "Przedzial a,b [" << a2 << ", " << b2 << "]" << endl;
	cout << "Epsilon: " << eps << endl;
	cout << "Dla funkcji f(x)= x+(1.0/(x*x))" << endl;
	cout << endl << "Wynik: " << endl;
	cout << "x1: " << x1 << endl; 
	cout << "x2: " << x2 << endl;
	
	cout << endl << "Wykonano w " << i << " krokach dla epsilona rownego " << eps << endl <<endl;
	system("pause");
	return 0;
}

double metoda_iteracyjna(){
	
	int 	i=0, 
			i2=0;
	
	double 	x1, 
			x2, 
			x0 = 1.0, 
			a = 1.0, 
			b = 2.0;
			
	double 	kroki = 1000.0,
			dlugosc = b - a,
			iteracja = dlugosc / kroki,
			minimum = x0;
	
	for (; i < kroki; i++) {
		x0=x0+iteracja;
		if (sprawdzenie_iteracja(x0,minimum,iteracja)) {
		 x1=x0-iteracja; 
		 x2=x0+iteracja;
		 minimum = x0;	
		}
	//	cout << "["<< x1<< ", " << x2 << "]"<< endl;
		i2++;
	}
	cout << endl << endl << "Wynik dla danych wejsciowych: " << endl;
	
	cout << "Przedzial a,b [" << a << ", " << b << "]" << endl;
	cout << "Dokladnosc: " << kroki << endl;
	cout << "Dla funkcji f(x)= x+(1.0/(x*x))" << endl;
	cout << endl << "Wynik: " << endl;
	cout << "x1: " << x1 << endl; 
	cout << "x2: " << x2 << endl;
	
	
	cout << endl << "Wykonano w " << i2 << " krokach " << endl <<endl;
	
	system("pause");
	return 0;
	
}

double metoda_paraboliczna(){
	
	int 	i=0;
	
	bool 	exit = false;	
	
	double 	a = 1.0, a2=a,
			b = 2.0, b2=b,
			c = (a+b)/2, c2=c, 
			d = minimum_paraboliczna(a,b,c),
			d2 = 0.0,
			eps = 0.0001;
	
	double 	f_c = funkcja(c),
			f_d = funkcja(d);

	while (!exit) {
		i++;
		f_d = funkcja(d);
		f_c = funkcja(c);
		
		if (a<d && d<c) {
			if(f_d < f_c){
				a = a;
				b = c;
				c = d;
				d2 = d;
				d = minimum_paraboliczna(a,b,c);
				if (abs(d2-d)<eps || abs(d-c)<eps) exit = true;
			} else {
				a = d;
				b = c;
				c = c;
				d2 = d;
				d = minimum_paraboliczna(a,b,c);
				if (abs(d2-d)<eps || abs(d-a)<eps) exit = true;
				}
		 } // end of if (a<d && d<c) {
		
		else if (c<d && d<b) {
			if(f_d < f_c){
				b = b;
				a = c;
				c = d;
				d2 = d;
				d = minimum_paraboliczna(a, b, c);
				if (abs(d2-d)<eps || abs(d-c)<eps) exit = true; 
			} else {
				a = a;
				b = d;
				c = c;
				d2 = d;
				d = minimum_paraboliczna(a,b,c);
				if (abs(d2-d)<eps || abs(d-b)<eps) exit = true; 
				}
		} // end of else if (c<d && d<b)
	} // end of while 
	
	cout << endl << endl << "Wynik dla danych wejsciowych: " << endl;
	cout << "Przedzial a,b [" << a2 << ", " << b2 << "]" << " oraz c= " << c2 << endl;
	cout << "Epsilon: " << eps << endl;
	cout << "Dla funkcji f(x)= x+(1.0/(x*x))" << endl;
	cout << endl << "Wynik: " << endl;
	cout << "a: " << a << endl; 
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
	cout << "d: " << d << endl;
	
	cout << endl << "Wykonano w " << i << " krokach " << endl <<endl;


	system("pause");
	return 0;
}

double metoda_zlotego_podzialu(){
	
	int 	i=0;
	
	double 	a=1.0, a2=a,
			b=2.0, b2=b,
			eps=0.000000000001;	
			
	double 	wsp=(sqrt(5.0)-1)/2.0;
	
	double 	c=a+(1.0-wsp)*(b-a),
			d=a+wsp*(b-a),
			f_c=funkcja(c),
			f_d=funkcja(d);

	while ( (b-a)>eps ) {
		//cout << "[" << a << "," << b << "]" << endl;
		i++;
		if (f_c < f_d) {
			b=d;
			d=c;
			c=a+(1.0-wsp)*(b-a);
			f_d=f_c;
			f_c=funkcja(c);
		} else {
			a=c;
			c=d;
			d=a+wsp*(b-a);
			f_c=f_d;
			f_d=funkcja(d);
		}
	} //end of while
	
	
	cout << endl << endl << "Wynik dla danych wejsciowych: " << endl;
	cout << "Przedzial a,b [" << a2 << ", " << b2 << "]" << endl;
	cout << "Epsilon: " << eps << endl;
	cout << "Dla funkcji f(x)= x+(1.0/(x*x))" << endl;
	cout << endl << "Wynik: " << endl;
	cout << "a: " << a << endl; 
	cout << "b: " << b << endl;

	
	cout << endl << "Wykonano w " << i << " krokach dla epsilona rownego "<< eps << endl <<endl;

	system("pause");
	return 0;
	
}

double metoda_najszybszego_spadku(){
	
	int i=0;
	
	double 	x=4.0, 
			x2=0.0,
			lambda=0.2,	
			eps=0.001;

	while (abs(x-x2) > eps) {
		i++;
		x2=x;
		x=x-lambda*pochodna(x);
		
		cout << "x: " << x<< " x2:" << x2 << endl;
	}
	
	cout << endl << endl << "Wynik dla danych wejsciowych: " << endl;
	cout << "Epsilon: " << eps << endl;
	cout << "Lambda: " << lambda << endl;
	
	cout << endl << "Wynik: " << endl;
	cout << "x: " << x << endl; 

	
	cout << endl << "Wykonano w " << i << " krokach dla epsilona rownego "<< eps << " oraz lambdy " << lambda << endl <<endl;
	
	system("pause");
	return 0;
	
	
}

