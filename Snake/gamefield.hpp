#pragma once

#ifndef GAMEFIELD_HPP
#define GAMEFIELD_HPP

#define _USE_MATH_DEFINES

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

#include <iostream>

class GameField : public QWidget
{
    Q_OBJECT

public:
    explicit GameField(QWidget *parent = nullptr);
    void setAngle(double angle);

protected:
    void paintEvent(QPaintEvent *e) override;
    void timerEvent(QTimerEvent *e) override;

private:
    double directAngle;
//    double dX;
//    double dY;

    QImage dot;
    QImage head;
    QImage apple;

    static const int B_WIDTH = 300;
    static const int B_HEIGHT = 300;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = 900;
    static const int RAND_POS = 29;
    static const int DELAY = 140;

    int timerId;
    int dots;
    int apple_x;
    int apple_y;

    int x[ALL_DOTS];
    int y[ALL_DOTS];

    bool inGame;

    void loadImages();
    void locateApple();
    void initGame();
//    void affineRotate();
    void affineRotateMove(double, double);
    void move();
    void checkCollision();
    void checkApple();
    void gameOver(QPainter &);
};

#endif // GAMEFIELD_HPP
