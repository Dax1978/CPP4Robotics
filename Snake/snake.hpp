#pragma once

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "gamefield.hpp"
#include <QWidget>
#include <QVBoxLayout>
#include <QLCDNumber>
#include <QDial>

class Snake : public QWidget
{
    Q_OBJECT
//    friend GameField;

public:
    Snake(QWidget *parent = nullptr);
    ~Snake();

//    double m_directAngle;

private:
    // контейнер для расположения виджетов в ряд по вертикали
    QVBoxLayout *m_layout = new QVBoxLayout(this);
    // игровое поле с логикой самой игры
    GameField *m_gameField = new GameField();
    // вывод значения направления в градусах: 0 - напарвление вверх
    QLCDNumber *m_lcdnumber = new QLCDNumber();
    // ручка изменения значения направления от -180 до +180
    QDial *m_dial = new QDial;

public slots:
    void changeDial(int value);
};
#endif // SNAKE_HPP
