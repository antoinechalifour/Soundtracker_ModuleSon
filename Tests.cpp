#include "Tests.h"

void starwars(){
	Morceau m;
	Pattern p;
	Sample s;
	Sample s2;
	Sample s3;
	s.setSound("../../data/guitar.wav");
	s2.setSound("../../data/guitar.wav");
	//s2.setRepeat(true);
	s2.setVolume(50);

	/* SOLO */
	/*
	p.getPiste(0).getDivision(0 * QUANT).setSample(&s);
	p.getPiste(0).getDivision(0 * QUANT).setNote(220 * OCT);

	p.getPiste(0).getDivision(1 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(1 * QUANT - 1).setNote(220 * OCT);

	p.getPiste(0).getDivision(2 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(2 * QUANT - 1).setNote(220 * OCT);

	p.getPiste(0).getDivision(3 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(3 * QUANT - 1).setNote(176 * OCT);

	p.getPiste(0).getDivision(3 * QUANT + 6).setSample(&s);
	p.getPiste(0).getDivision(3 * QUANT + 6).setNote(264 * OCT);

	p.getPiste(0).getDivision(4 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(4 * QUANT - 1).setNote(220 * OCT);

	p.getPiste(0).getDivision(5 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(5 * QUANT - 1).setNote(176 * OCT);

	p.getPiste(0).getDivision(5 * QUANT + 6).setSample(&s);
	p.getPiste(0).getDivision(5 * QUANT + 6).setNote(264 * OCT);

	p.getPiste(0).getDivision(6 * QUANT - 1).setSample(&s);
	p.getPiste(0).getDivision(6 * QUANT - 1).setNote(220 * OCT);

	/* FOND */
	p.getPiste(1).getDivision(0 * QUANT).setSample(&s2);
	p.getPiste(1).getDivision(0 * QUANT).setNote(220);
	p.getPiste(2).getDivision(0 * QUANT).setSample(&s2);
	p.getPiste(2).getDivision(0 * QUANT).setNote(330);

	p.getPiste(1).getDivision(3 * QUANT).setSample(&s2);
	p.getPiste(1).getDivision(3 * QUANT).setNote(349);
	p.getPiste(2).getDivision(3 * QUANT).setSample(&s2);
	p.getPiste(2).getDivision(3 * QUANT).setNote(523);

	m.affecterPattern(0, &p);
	cout << "Nb samples : " << Sample::getNbSamples() << endl;
	cout << "Nb Divisions : " << Division::getNbDivisions() << endl;
	cout << "Nb Pistes : " << Piste::getNbPistes() << endl;
	cout << "Nb patterns : " << Pattern::getNbPatterns() << endl;
	cout << "Nb positions : " << Position::getNbPositions() << endl;

	m.lecture(true, 0, 0);
}

void testRepeat(){
	Morceau m;
	Pattern p;
	Sample s;
	Sample s2;
	s.setSound("../../data/guitar.wav");
	s.setRepeat(true);
	s2.setSound("../../data/sample.wav");
	s2.setPitch(220);

	p.getPiste(0).getDivision(0).setSample(&s);
	p.getPiste(0).getDivision(QUANT).setSample(&s2);/*
													p.getPiste(0).getDivision(2 * QUANT).setSample(&s);
													p.getPiste(0).getDivision(2 * QUANT).setNote(660);
													p.getPiste(0).getDivision(3*QUANT).setSample(&s2);
													p.getPiste(0).getDivision(4 * QUANT).setSample(&s);
													p.getPiste(0).getDivision(4 * QUANT).setNote(1000);
													p.getPiste(0).getDivision(5*QUANT).setSample(&s2);*/

	m.affecterPattern(0, &p);
	m.lecture(true, 0, 0);
}

void testAccords(){
	Morceau m;
	Pattern p;
	Sample s;
	Sample s2;
	s.setSound("../../data/guitar.wav");
	s.setRepeat(true);
	s.setPitch(220);
	s2.setSound("../../data/sample.wav");
	s2.setRepeat(true);
	s2.setPitch(330);

	s.play();
	s2.play();
}


void testInit(){
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
	/*
	Morceau m;
	Sample s;
	s.setSound("../../data/sample.wav");
	Pattern p;
	try{
	m.affecterPattern(1, &p);
	}
	catch (StException e){
	cout << e.getMsg()<<endl;
	}*/
}

void composure(){
	Morceau m;
	Pattern p;
	Sample c;
	Sample cs;
	Sample d;
	Sample ds;
	Sample e;
	Sample f;
	Sample fs;
	Sample g;
	Sample gs;
	Sample a;
	Sample as;
	Sample b;

	c.setSound("../../data/guitarC.wav");
	cs.setSound("../../data/guitarCs.wav"); 
	d.setSound("../../data/guitarD.wav");
	ds.setSound("../../data/guitarDs.wav");
	e.setSound("../../data/guitarE.wav");
	f.setSound("../../data/guitarF.wav");
	fs.setSound("../../data/guitarFs.wav");
	g.setSound("../../data/guitarG.wav");
	gs.setSound("../../data/guitarGs.wav");
	a.setSound("../../data/guitarA.wav");
	as.setSound("../../data/guitarAs.wav");
	b.setSound("../../data/guitarB.wav");

	c.setRepeat(true);
	cs.setRepeat(true);
	d.setRepeat(true);
	ds.setRepeat(true);
	e.setRepeat(true);
	f.setRepeat(true);
	fs.setRepeat(true);
	g.setRepeat(true);
	gs.setRepeat(true);
	a.setRepeat(true);
	as.setRepeat(true);
	b.setRepeat(true);

	p.getPiste(0).getDivision(0).setSample(&c);
	p.getPiste(1).getDivision(0).setSample(&g);

	p.getPiste(0).getDivision(32).setSample(&gs);
	p.getPiste(1).getDivision(32).setSample(&ds);
	p.getPiste(1).getDivision(32).setNote(880);

	p.getPiste(0).getDivision(48).setSample(&ds);
	p.getPiste(1).getDivision(48).setSample(&b);

	p.getPiste(0).getDivision(56).setSample(&d);
	p.getPiste(1).getDivision(56).setSample(&b);

	m.affecterPattern(0, &p);
	m.lecture(true, 0, 0);
}