#define _USE_MATH_DEFINES // для C++

#include "include/snake.hpp"
#include <cmath>


Snake::Snake(QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QVBoxLayout(this);
    m_gameField = new GameField();
    m_lcdnumber = new QLCDNumber();
    m_dial = new QDial;

    m_lcdnumber->display(0);
    m_lcdnumber->setDigitCount(4);
    m_lcdnumber->setSmallDecimalPoint(true);

    m_dial->setRange(-180, 180);
    m_dial->setNotchTarget(5);
    m_dial->setNotchesVisible(true);
    m_dial->setSingleStep(45);
    m_dial->setPageStep(90);

    connect(m_dial, &QDial::valueChanged, this, &Snake::changeDial);

    m_layout->addWidget(m_gameField);
    m_layout->addWidget(m_lcdnumber);
    m_layout->addWidget(m_dial);

    setStyleSheet("background: rgb(90, 100, 112);");
}

Snake::~Snake() {  }

void Snake::changeDial(int value)
{
    m_lcdnumber->display(value);
    m_gameField->setAngle(value * (M_PI / 180.0));
}
