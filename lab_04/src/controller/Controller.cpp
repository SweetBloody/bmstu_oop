#include "Controller.hpp"

#include <QLabel>
#include <QDebug>

Controller::Controller(QWidget *parent) : QWidget(parent)
{
    this->_layout = std::make_unique<QVBoxLayout>();
    this->setLayout(this->_layout.get());

    auto new_button = std::make_shared<Button>();
    new_button->setDisabled(true);
    new_button->setStyleSheet("background-color:grey; color:black");
    new_button->setFloor(FLOORS + 1);
    new_button->setText("Buttons on floor");

    this->_buttons_floor.insert(this->_buttons_floor.begin(), new_button);
    _layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

    for (size_t i = 0; i < FLOORS; i++)
    {

        auto new_button = std::make_shared<Button>();
        new_button->setFloor(FLOORS - i);
        new_button->setText(QString::number(FLOORS - i));
        new_button->setStyleSheet(QString("background-color:") + COLORBUTTONINACTIVE);

        this->_buttons_floor.insert(this->_buttons_floor.begin(), new_button);
        _layout->addWidget(dynamic_cast<QPushButton *>(new_button.get()));

        _is_visit.push_back(false);

        // нажата кнопка => добавляем этаж в цели
        QObject::connect(new_button.get(), SIGNAL(pressSignal(bool,int)), this, SLOT(newTarget(bool,int)));
    }

    auto lift_button = std::make_shared<Button>();
    lift_button->setDisabled(true);
    lift_button->setStyleSheet("background-color:grey; color:black");
    lift_button->setFloor(2 * FLOORS + 2);
    lift_button->setText("Buttons in lift");
    this->_buttons_lift.insert(this->_buttons_lift.begin(), lift_button);
    _layout->addWidget(dynamic_cast<QPushButton *>(lift_button.get()));


    for (size_t i = 0; i < FLOORS; i++)
    {
        auto button = std::make_shared<Button>();
        button->setFloor(FLOORS - i);
        button->setText(QString::number(FLOORS - i));
        button->setStyleSheet(QString("background-color:") + COLORBUTTONINACTIVE);

        this->_buttons_lift.insert(this->_buttons_lift.begin(), button);
        _layout->addWidget(dynamic_cast<QPushButton *>(button.get()));

        _is_visit.push_back(false);

        // нажата кнопка => добавляем этаж в цели
        QObject::connect(button.get(), SIGNAL(pressSignal(bool,int)), this, SLOT(newTarget(bool,int)));
    }


    QObject::connect(this, SIGNAL(reachFloorSignal()), this, SLOT(reachFloor()));
}

void Controller::newTarget(bool got_new, int floor)
{
    this->_state = BUSY;
    if (got_new)
    {
        this->_is_visit[floor - 1] = true;

        _identifyNewTarget(floor);
        _targetFloor = floor;
        _decideDirection();
        if (_direction == STAY)
        {
            emit reachFloorSignal();
        }
        else
        {
            emit moveCabinSignal();
        }
    }
    else if (_identifyNewTarget(floor))
    {
        _targetFloor = floor;
        _decideDirection();


        if (_direction != STAY)
        {
             _updateFloor();
            emit moveCabinSignal();
        }
        else
        {
            emit reachFloorSignal();
        }
     }
}

void Controller::_decideDirection()
{
    if (_targetFloor > _curFloor)
    {
        _direction = UP;
    }
    else if (_targetFloor < _curFloor)
    {
        _direction = DOWN;
    }
    else
    {
        _last_direction = _direction;
        _direction = STAY;
    }
}

bool Controller::_identifyNewTarget(int &new_target)
{
    bool rc = false;

    Direction dir;

    if (_direction != STAY)
        dir = _direction;
    else
        dir = (_last_direction == STAY) ? UP: _last_direction;

    for (int i = _curFloor; !rc && i <= FLOORS && i > 0; i = i + dir)
        if (_is_visit[i - 1])
        {
            new_target = i;
            rc = true;
        }

    if (!rc)
    {
        dir = ((dir == UP) ? DOWN : UP);

        for (int i = _curFloor; !rc && i <= FLOORS && i > 0; i = i + dir)
        {
            if (_is_visit[i - 1])
            {
                new_target = i;
                rc = true;
            }
        }
    }

    return rc;
}

void Controller::reachFloor()
{
    // Если контроллер не занят, выходим [лифт не движется]
    if (_state != BUSY) return;

    qDebug() << "Elevator stopped on " << _targetFloor  << " floor.";

    emit _buttons_floor[_targetFloor - 1]->unpressSignal(); // кнопка разжимается

    emit _buttons_lift[_targetFloor - 1]->unpressSignal(); // кнопка разжимается

    _is_visit[_targetFloor - 1] = false; // посещать его уже не надо


    // проверим, есть ли ещё цели
    if (_identifyNewTarget(_targetFloor))
    {
        emit stopCabinSignal();
    }
    else
    {
        // Целей нет
        _state = FREE; // Контроллер освободился
        emit stopCabinSignal();
    }
}

void Controller::_updateFloor()
{
    _curFloor += _direction;

     qDebug() << "Floor:" << _curFloor;
}
