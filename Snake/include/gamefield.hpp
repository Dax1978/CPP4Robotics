#pragma once

#ifndef GAMEFIELD_HPP
#define GAMEFIELD_HPP

#define _USE_MATH_DEFINES

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include <QVector>

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

    QImage dot;
    QImage head;
    QImage apple;
    QImage wall;

    static const int B_WIDTH = 300;
    static const int B_HEIGHT = 300;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = 900;
    static const int RAND_POS = 29;
    static const int DELAY = 140;
    static const int WALL_MIN = 2;
    static const int WALL_MAX = 6;

    int timerId;
    int dots;
    int apple_x;
    int apple_y;

    int x[ALL_DOTS];
    int y[ALL_DOTS];

    QVector<int> wallH_x;
    QVector<int> wallH_y;
    QVector<int> wallV_x;
    QVector<int> wallV_y;

    bool inGame;

    void loadImages();
    void locateApple();
    void initGame();
    void affineRotateMove(double, double);
    void move();
    void checkCollision();
    void checkApple();
    void gameOver(QPainter &);
    void locateWalls();
};

#endif // GAMEFIELD_HPP
