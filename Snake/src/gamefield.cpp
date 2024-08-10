#include "include/gamefield.hpp"

#include <QRandomGenerator>
#include <QTime>

GameField::GameField(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(B_WIDTH, B_HEIGHT);
    inGame = true;

    loadImages();
    initGame();
}

void GameField::setAngle(double angle) { directAngle = angle; }

void GameField::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QBrush gameFieldBrush(QColor(139, 144, 163), Qt::SolidPattern);
    QPainter painter(this);

    // отрисовка игрового поля
    painter.setBrush(gameFieldBrush);
    painter.setPen(QColor(0, 0, 0));
    painter.drawRect(0, 0, width()-1, height()-1);

    if (inGame) {
        painter.drawImage(apple_x, apple_y, apple);
        for (size_t i = 0; i < wallH_x.size(); i++)
        {
            painter.drawImage(wallH_x[i], wallH_y[i], wall);
        }
        for (size_t i = 0; i < wallV_x.size(); i++)
        {
            painter.drawImage(wallV_x[i], wallV_y[i], wall);
        }
        for (int z = 0; z < dots; z++)
        {
            if (z == 0)
            {
                painter.drawImage(x[z], y[z], head);
            } else {
                painter.drawImage(x[z], y[z], dot);
            }
        }

    } else {
        gameOver(painter);
    }
}

void GameField::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    if (inGame)
    {
        checkApple();
        checkCollision();
        move();
    }
    repaint();
}

void GameField::loadImages()
{
    dot.load(":/pic/img/dot.png");
    head.load(":/pic/img/head.png");
    apple.load(":/pic/img/apple.png");
    wall.load(":/pic/img/wall.png");
}

void GameField::locateApple()
{
    int r = QRandomGenerator::global()->generate() % RAND_POS;
    apple_x = (r * DOT_SIZE);
    for (size_t i = 0; i < wallH_x.size(); i++)
    {
        if(apple_x == wallH_x[i])
        {
            locateApple();
        }
    }
    for (size_t i = 0; i < wallV_x.size(); i++)
    {
        if(apple_x == wallV_x[i])
        {
            locateApple();
        }
    }
    r = QRandomGenerator::global()->generate() % RAND_POS;
    apple_y = (r * DOT_SIZE);
    for (size_t i = 0; i < wallH_y.size(); i++)
    {
        if(apple_y == wallH_y[i])
        {
            locateApple();
        }
    }
    for (size_t i = 0; i < wallV_y.size(); i++)
    {
        if(apple_y == wallV_y[i])
        {
            locateApple();
        }
    }
}

void GameField::initGame()
{
    directAngle = 0.0;
    dots = 3;
    for (int z = 0; z < dots; z++) {
        x[z] = 50 - z * 10;
        y[z] = 50;
    }
    locateWalls();
    locateApple();
    timerId = startTimer(DELAY);
}

void GameField::affineRotateMove(double dx=0, double dy=DOT_SIZE)
{
    x[0] = dx * std::cos(directAngle) + dy * std::sin(directAngle) + x[0];
    y[0] = dx * std::sin(directAngle) - dy * std::cos(directAngle) + y[0];
}

void GameField::move()
{
    for (int z = dots; z > 0; z--)
    {
        x[z] = x[(z - 1)];
        y[z] = y[(z - 1)];
    }
    affineRotateMove();
}

void GameField::checkCollision()
{
    for (int z = dots; z > 0; z--)
    {
        if ((z > 4) && (std::abs(x[0] - x[z]) <= DOT_SIZE) && (std::abs(y[0] - y[z]) <= DOT_SIZE)) { inGame = false; }
    }
    if (y[0] >= B_HEIGHT) { y[0] = 0; }
    if (y[0] < 0) { y[0] = B_HEIGHT; }
    if (x[0] >= B_WIDTH) { x[0] = 0; }
    if (x[0] < 0) { x[0] = B_WIDTH; }
    if(!inGame) { killTimer(timerId); }

    for(size_t i = 0; i < wallH_x.size(); i++)
    {
        if((std::abs(x[0] - wallH_x[i]) <= 5) && (std::abs(y[0] - wallH_y[i]) <= 5)) { inGame = false; }
    }
    for(size_t i = 0; i < wallV_x.size(); i++)
    {
        if((std::abs(x[0] - wallV_x[i]) <= 5) && (std::abs(y[0] - wallV_y[i]) <= 5)) { inGame = false; }
    }
}

void GameField::checkApple()
{
    if ((std::abs(x[0] - apple_x) <= (DOT_SIZE / 2)) && (std::abs(y[0] - apple_y) <= (DOT_SIZE / 2)))
    {
        dots++;
        locateApple();
    }
}

void GameField::gameOver(QPainter &qp)
{
    QString message = "Game over";
    QFont font("Courier", 17, QFont::DemiBold);
    QPen penHText(QColor("#ee0000"));
    qp.setPen(penHText);
    QFontMetrics fm(font);
    int textWidth = fm.horizontalAdvance(message);

    qp.setFont(font);
    int h = height();
    int w = width();

    qp.translate(QPoint(w/2, h/2));
    qp.drawText(-textWidth/2, 0, message);
}

void GameField::locateWalls()
{
    int l = WALL_MIN + QRandomGenerator::global()->generate() % (WALL_MAX - WALL_MIN);
    int h = QRandomGenerator::global()->generate() % (RAND_POS - l);
    int v = QRandomGenerator::global()->generate() % RAND_POS;
    for(size_t i = 0; i < l; i++)
    {
        wallH_x.push_back(h * DOT_SIZE + i * DOT_SIZE);
        wallH_y.push_back(v * DOT_SIZE);
    };

    l = WALL_MIN + QRandomGenerator::global()->generate() % (WALL_MAX - WALL_MIN);
    h = QRandomGenerator::global()->generate() % RAND_POS;
    v = QRandomGenerator::global()->generate() % (RAND_POS - 1);
    for(size_t i = 0; i < l; i++)
    {
        wallV_x.push_back(h * DOT_SIZE);
        wallV_y.push_back(v * DOT_SIZE + i * DOT_SIZE);
    };
}
