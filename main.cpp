//#include "ofMain.h"
//#include "ofApp.h"
#include <Windows.h>
#include "ofSoundPlayer.h"

#include<iostream>
#include "Sample.h"
#include "Division.h"
#include "Piste.h"
#include "Pattern.h"
#include "Position.h"

using namespace std;

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

	
	getchar();

}
