#ifndef GAME_H
#define GAME_H

#include <QtWidgets/QWidget>
#include <QtCore/QVector>
#include <QtCore/QPoint>
#include <QtCore/QTimerEvent>
#include <QtGui/QKeyEvent>
#include <QtGui/QPaintEvent>
#include <QtWidgets/QMessageBox>

class Game : public QWidget
{
private:
    // Переменные для размера ячейки
    static const int DOT_WIDTH  = 20;
    static const int DOT_HEIGHT = 20;
    // Переменные для количества ячеек поля
    static const int FIELD_WIDTH  = 20;
    static const int FIELD_HEIGHT = 20;
    // Переменная для шага работы таймера
    static const int DELAY = 150;
    // Нужен таймер
    int timerId;
    // Перечисление направлений движения змейки
    enum DirectionsSnake
    {
        left, right, up, down
    };
    DirectionsSnake m_directionSnake;
    // Переменная для хранения состояния игры
    bool m_inGame;
    // Переменная для хранения координат всех частей змейки
    QVector<QPoint> m_dots;
    // Точка, где хранится яблоко
    QPoint m_apple;
    // Метод инициализации игры
    void initGame();
    // Отрисовка виджета
    void doDrawing();
    // Рисуем яблоко
    void localApple();
    // Движение змейки
    void moveSnake();
    // Проверка выхода за границы поля
    void checkBorder();
    // GameOver он и в Африке gameOver
    void gameOver();
    // Проверка на съедение яблока
    void checkApple();

protected:
    // Обработка события таймера
    void timerEvent(QTimerEvent* e) override;
    // Обработка нажатия клавиш
    void keyPressEvent(QKeyEvent* e) override;
    // Событие перерисовки виджета
    void paintEvent(QPaintEvent* e) override;

public:
    // В конструктор передаю параметр, как требует родительский класс QWidget
    Game();
    // Game(QWidget* parent = nullptr);
};

#endif