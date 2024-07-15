#include "game.h"
#include <QtCore/QDebug>
#include <QtGui/QPainter>
#include <QtCore/QTime>

Game::Game()
{
    // Определяю и устанавливаю размеры игрового поля
    this->resize(DOT_WIDTH * FIELD_WIDTH, DOT_HEIGHT * FIELD_HEIGHT);
    // Устанавливаю заголовок окна
    this->setWindowTitle("Snake");
    // Вызываю в конструкторе инициализацию игры
    this->initGame();
};

void Game::initGame()
{
    // При инициализации устанавливаем флаг - играем
    m_inGame = true;
    // В началае у змейки 3 звена
    m_dots.resize(3);
    // Инициализация координат начальных элементов
    for (int i = 0; i < m_dots.size(); ++i)
    {
        m_dots[i].rx() = m_dots.size() - i - 1;
        m_dots[i].ry() = 0;
    }

    // И надо расположить яблоко
    localApple();

    // Создаю таймер и запишу его Id
    timerId = startTimer(DELAY);
    // При инициализации сразу устанавливаю вправо
    m_directionSnake = right;
}

void Game::timerEvent(QTimerEvent* e)
{
    Q_UNUSED(e);
    // Если в игре, двигаемся!
    if (m_inGame)
    {
        // А не съела ли змея яблоко
        checkApple();
        // Движение змейки
        moveSnake();
        // Проверяю на то, что бы змейка не вышла за границу
        checkBorder();
    }
    // Перерисовываю холст
    this->repaint();   
}

// Обработка нажатия клавиш
void Game::keyPressEvent(QKeyEvent* e)
{
    // int key = e->key();
    // Проверяю нажатия влево-вправо-вверх-вниз и
    // указываю соответствующие направления в переменную, где хранится направление движения змейки
    switch (e->key())
    {
    case Qt::Key_Left:
        // Также смотрю, что предыдущее направление не противоположное
        if (m_directionSnake != right) { m_directionSnake = left; }        
        break;
    case Qt::Key_Right:
        // Также смотрю, что предыдущее направление не противоположное
        if (m_directionSnake != left) { m_directionSnake = right; }        
        break;
    case Qt::Key_Up:
        // Также смотрю, что предыдущее направление не противоположное
        if (m_directionSnake != down) { m_directionSnake = up; }
        break;
    case Qt::Key_Down:
        // Также смотрю, что предыдущее направление не противоположное
        if (m_directionSnake != up) { m_directionSnake = down; }
        break;
    default:
        break;
    }    
}

void Game::paintEvent(QPaintEvent* e)
{   
    Q_UNUSED(e);
    // Просто вызываю функцию рисовки
    doDrawing();
}


void Game::doDrawing()
{
    // Холст для рисования
    QPainter qp(this);

    // Проверяю, в игре ли мы
    if (m_inGame)
    {
        // Яблоко: будет зеленым цветом - будет круглым
        qp.setBrush(Qt::green);
        qp.drawEllipse(m_apple.x() * DOT_WIDTH, m_apple.y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
        // Змейка: желтая с красной головой
        for (int i = 0; i < m_dots.size(); ++i)
        {
            if (i == 0)
            {
                qp.setBrush(Qt::red);
                qp.drawEllipse(m_dots[i].x() * DOT_WIDTH, m_dots[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
            } else {
                qp.setBrush(Qt::yellow);
                qp.drawEllipse(m_dots[i].x() * DOT_WIDTH, m_dots[i].y() * DOT_HEIGHT, DOT_WIDTH, DOT_HEIGHT);
            }
        }
    }
    else
    {
        gameOver();
    }
}

void Game::localApple()
{
    // Инициализирую генератор случайных числе
    QTime time = QTime::currentTime();
    qsrand((uint) time.msec());
    // Записываю в положение яблока случайные числа в пределах поля
    this->m_apple.rx() = qrand() % this->FIELD_WIDTH;
    this->m_apple.ry() = qrand() % this->FIELD_HEIGHT;
}

void Game::moveSnake()
{
    // Конечно же двигаю в текущем направлении
    // Прохожу по змейке с конца в начало (без головы)
    // Двигаю тело, каждое звено с конца, занимает позицию предыдущего звена
    for (int i = m_dots.size() - 1; i > 0; --i)
    {
        m_dots[i] = m_dots[i-1];
    }
    // Двигаю голову
    switch (m_directionSnake)
    {
    case left:
        m_dots[0].rx() -= 1;
        break;
    case right:
        m_dots[0].rx() += 1;
        break;
    case up:
        m_dots[0].ry() -= 1;
        break;
    case down:
        m_dots[0].ry() += 1;
        break;    
    default:
        break;
    }
}

void Game::checkBorder()
{
    // Здесь же проверка, что змейка не съела саму себя
    if (m_dots.size() > 4)
    {
        // цикл по всем звеньям, кроме головы и сверяю с головой
        for (int i = 1; i < m_dots.size(); ++i)
        {
            // Если голова и какое то звено равны, то заканчиваю игру
            if (m_dots[0] == m_dots[i]) { m_inGame = false; }
        }
    }
    // Проверки выхода головы за пределы игрового поля
    if (m_dots[0].x() >= FIELD_WIDTH || m_dots[0].x() < 0 || m_dots[0].y() >= FIELD_HEIGHT || m_dots[0].y() < 0) { m_inGame = false; }
}

void Game::gameOver()
{
    // Останавливаю таймер
    killTimer(timerId);

    QMessageBox msg;
    msg.setText("Game Over!!!");
    msg.exec();

    // После закрытия окна сообщения, инициализирую новую игру
    initGame();
}

void Game::checkApple()
{
    // Если голова и яблоко в одном месте - змейка съела яблоко!
    if (m_apple == m_dots[0])
    {
        // Добавляю новое звено, пока просто с координатами 0, 0
        // При следующем кадре, последнее звено получит координаты предыдущего последнего звена
        m_dots.push_back(QPoint(0, 0));
        // Вызываю генерацию нового яблока в случайном месте
        localApple();
    }
}
