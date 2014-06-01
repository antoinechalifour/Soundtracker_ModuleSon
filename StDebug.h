/**
  Fichier à inclure à la place de tous les autres.
  Le mode debug STDEBUG est défini ici.
  Les fréquences référence sont définies ici.

  @author Antoine
  */

#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <windows.h>
#include <stdio.h>

#include <QCheckBox>
#include <QDebug>
#include <QFileDialog>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMultimedia>
#include <QObject>
#include <QPushButton>
#include <QScrollArea>
#include <QSlider>
#include <QSpinBox>
#include <QString>
#include <QSettings>
#include <QSoundEffect>
#include <QTimer>
#include <QUrl>
#include <QVariant>
#include <QVBoxLayout>
#include <QVector>

#define STDEBUG

#define FREQ_C 65
#define FREQ_CS 69
#define FREQ_D 73
#define FREQ_DS 78
#define FREQ_E 82
#define FREQ_F 87
#define FREQ_FS 92
#define FREQ_G 98
#define FREQ_GS 104
#define FREQ_A 110
#define FREQ_AS 117
#define FREQ_B 123

using namespace std;

#endif // DEBUG_H
