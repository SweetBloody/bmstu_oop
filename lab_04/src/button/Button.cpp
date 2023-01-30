#include "Button.hpp"
#include <QDebug>

Button::Button(QWidget *parent) : QPushButton(parent)
{
    QObject::connect(this, SIGNAL(clicked()), this, SLOT(pressSlot()));
    QObject::connect(this, SIGNAL(unpressSignal()), this, SLOT(unpressSlot())); // Выключается когда лифт приедет и издаст сигнал

    _state = UNPRESSED;
    _currentButtonFloor = 1;
}

void Button::setFloor(int floor)
{
    _currentButtonFloor = floor;
}

void Button::pressSlot()
{
    if (this->_state != UNPRESSED) return;

    // Визуальное изменение кнопки
    this->setStyleSheet(QString("background-color:") + COLORBUTTONACTIVE);
    this->update();

    qDebug() << "Call from " << this->_currentButtonFloor << " floor!";

    // Изменение состояния
    this->_state = PRESSED;
    this->setDisabled(true);

    // Сигнал всем, что нажата данная кнопка
    emit pressSignal(true, this->_currentButtonFloor);
}

void Button::unpressSlot()
{
    // Если кнопка уже разжата, выходим
    if (this->_state == UNPRESSED) return;

    // Визуальное изменение кнопки
    this->setStyleSheet((QString("background-color:") + COLORBUTTONINACTIVE));
    this->update();

    // Изменение состояния
    this->_state = UNPRESSED;
    this->setDisabled(false);
}
