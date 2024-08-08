#include "gamefield.hpp"
#include "snake.hpp"

#include <QRandomGenerator>
#include <QTime>

GameField::GameField(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(B_WIDTH, B_HEIGHT);
//    setFocusPolicy(Qt::StrongFocus);

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
//    painter.begin(this);

    // отрисовка игрового поля
    painter.setBrush(gameFieldBrush);
    painter.setPen(QColor(0, 0, 0));
    painter.drawRect(0, 0, width()-1, height()-1);
//    painter.drawLine(150, 150, 150-dX, 150-dY);

    if (inGame) {
        painter.drawImage(apple_x, apple_y, apple);
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

//    painter.end();
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
    dot.load("dot.png");
    head.load("head.png");
    apple.load("apple.png");
}

void GameField::locateApple()
{
    int r = QRandomGenerator::global()->generate() % RAND_POS;
    apple_x = (r * DOT_SIZE);
    r = QRandomGenerator::global()->generate() % RAND_POS;
    apple_y = (r * DOT_SIZE);
}

void GameField::initGame()
{
    directAngle = 0.0;
    dots = 3;
    for (int z = 0; z < dots; z++) {
        x[z] = 50 - z * 10;
        y[z] = 50;
    }

    locateApple();
    timerId = startTimer(DELAY);
}

//void GameField::affineRotate()
//{
//    dX =      0.0 * std::cos(directAngle) + DOT_SIZE * std::sin(directAngle);
//    dY = -1 * 0.0 * std::sin(directAngle) + DOT_SIZE * std::cos(directAngle);
//}

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
//    affineRotate();
//    x[0] += std::round(dX);
//    y[0] -= std::round(dY);
    affineRotateMove();
}

void GameField::checkCollision()
{
    for (int z = dots; z > 0; z--)
    {
        if ((z > 4) && (std::abs(x[0] - x[z]) <= DOT_SIZE) && (std::abs(y[0] - y[z]) <= DOT_SIZE)) { inGame = false; }
    }

//    if (y[0] >= B_HEIGHT) { inGame = false; }
//    if (y[0] < 0) { inGame = false; }
//    if (x[0] >= B_WIDTH) { inGame = false; }
//    if (x[0] < 0) { inGame = false; }
    if (y[0] >= B_HEIGHT) { y[0] = 0; }
    if (y[0] < 0) { y[0] = B_HEIGHT; }
    if (x[0] >= B_WIDTH) { x[0] = 0; }
    if (x[0] < 0) { x[0] = B_WIDTH; }
    if(!inGame) { killTimer(timerId); }
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
