//#include "ofMain.h"
//#include "ofApp.h"
#include <Windows.h>
#include <time.h>
#include "ofSoundPlayer.h"

#include<iostream>
#include "Sample.h"
#include "Division.h"
#include "Piste.h"
#include "Pattern.h"
#include "Position.h"
#include "Morceau.h"

#include "StException.h"

using namespace std;

#define QUANT 8

void starwars(){
	Morceau m;
	Pattern p;
	Sample s;
	Sample s2;
	Sample s3;
	s.setSound("../../data/sample.wav");
	s2.setSound("../../data/sample2.wav");
	s3.setSound("../../data/setbass.wav");
	//s3.setRepeat(true);


	p.getPiste(0).getDivision(0 * QUANT).setSample(&s);
	p.getPiste(0).getDivision(0 * QUANT).setNote(220);
	p.getPiste(1).getDivision(0 * QUANT).setSample(&s2);
	p.getPiste(2).getDivision(0 * QUANT).setSample(&s3);

	p.getPiste(0).getDivision(1 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(1 * QUANT - 1).setNote(220);
	p.getPiste(1).getDivision(1 * QUANT - 1).setSample(&s2);

	p.getPiste(0).getDivision(2 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(2 * QUANT - 1).setNote(220);
	p.getPiste(1).getDivision(2 * QUANT - 1).setSample(&s2);

	p.getPiste(0).getDivision(3 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(3 * QUANT - 1).setNote(176);
	p.getPiste(1).getDivision(3 * QUANT - 1).setSample(&s2);


	p.getPiste(1).getDivision(3 * QUANT + 4).setSample(&s2);
	p.getPiste(1).getDivision(3 * QUANT + 5).setSample(&s2);
	p.getPiste(1).getDivision(3 * QUANT + 6).setSample(&s2);
	p.getPiste(1).getDivision(3 * QUANT + 7).setSample(&s2);

	p.getPiste(0).getDivision(3 * QUANT + 6).setSample(&s);
	p.getPiste(0).getDivision(3 * QUANT + 6).setNote(264);

	p.getPiste(0).getDivision(4 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(4 * QUANT - 1).setNote(220);
	p.getPiste(2).getDivision(4 * QUANT).setSample(&s3);
	p.getPiste(2).getDivision(4 * QUANT).setNote(220);

	p.getPiste(1).getDivision(4 * QUANT + 4).setSample(&s2);
	p.getPiste(1).getDivision(4 * QUANT + 5).setSample(&s2);
	p.getPiste(1).getDivision(4 * QUANT + 6).setSample(&s2);
	p.getPiste(1).getDivision(4 * QUANT + 7).setSample(&s2);

	p.getPiste(0).getDivision(5 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(5 * QUANT - 1).setNote(176); 
	p.getPiste(1).getDivision(5 * QUANT - 1).setSample(&s2);
	p.getPiste(1).getDivision(5 * QUANT - 1).setSample(&s2);

	p.getPiste(1).getDivision(5 * QUANT + 4).setSample(&s2);
	p.getPiste(1).getDivision(5 * QUANT + 5).setSample(&s2);
	p.getPiste(1).getDivision(5 * QUANT + 6).setSample(&s2);
	p.getPiste(1).getDivision(5 * QUANT + 7).setSample(&s2);

	p.getPiste(0).getDivision(5 * QUANT + 6).setSample(&s);
	p.getPiste(0).getDivision(5 * QUANT + 6).setNote(264);

	p.getPiste(0).getDivision(6 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(6 * QUANT - 1).setNote(220);
	p.getPiste(1).getDivision(6 * QUANT - 1).setSample(&s2);
	p.getPiste(1).getDivision(6 * QUANT - 1).setSample(&s2);
	
	m.affecterPattern(0, &p);
	//m.getDivision(&p, 0, 6 * QUANT - 1).setNote(100);
	m.lecture(true, 0, 5);
}

//========================================================================
int main( ){
	/*
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());*/

	/* TEST SAMPLES*/
	/*
	cout << "Test samples" << endl;
	for (int i = 0; i < 15; i++){
		Sample s;
		s.debug();
		cout << "Nom : " << s.getNom() << endl << endl;
	} 
	*/
	
	/* TEST DIVISIONS*/
	/*
	cout << "Test Division" << endl;
	Sample *s = new Sample();
	s->debug();
	Division d;
	d.setSample(s);
	d.debug();
	*/

	/* TEST PISTES*/
	/*
	Piste p;
	p.debug();
	*/

	/* TEST PATTERNS*/
	/*
	Pattern p;
	p.debug();
	*/

	/* TEST POSITIONS*/
	/*
	Position p;
	p.debug();
	Pattern pa;
	pa.debug();
	p.setPattern(&pa);
	p.debug();
	*/
	/* GAMME MAJEURE */
	/*
	Sample s;
	s.setSound("../../data/sample.wav");
	s.play();
	Division divs[8];
	int note = 132;

	for (int i = 0; i < 9; i++){
		cout << note << endl;
		divs[i].setSample(&s);
		divs[i].setNote(note);
		divs[i].play();
		Sleep(300);
		if (i==2 || i == 6)
			note = note * 1.059463;
		else
			note = note * (1.059463*1.059463);
	}
	*/

	/*
	Sample s;
	s.setSound("../../data/sample.wav");
	Piste p;
	int note = 55;
	for (int i = 63; i >=0; i--){
		cout << note << endl;
		p.getDivision(i).setSample(&s);
		p.getDivision(i).setNote(note);
		note = note * 1.059463;
	}
	p.play(96, 30);
	*/
	//starwars();

	Morceau m;
	Sample s;
	s.setSound("../../data/sample.wav");
	Pattern p;
	try{
		m.affecterPattern(1, &p);
	}
	catch (StException e){
		cout << e.getMsg()<<endl;
	}

	getchar();

}
