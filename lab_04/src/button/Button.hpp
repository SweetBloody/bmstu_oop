#ifndef LAB_04_BUTTON_HPP
#define LAB_04_BUTTON_HPP

#include <QPushButton>
#include <memory>
#include "../defines.hpp"

class Button : public QPushButton
{
    Q_OBJECT;

    using ButtonState = enum
    {
        PRESSED,
        UNPRESSED
    };

public:
    explicit Button(QWidget *parent = nullptr);
    ~Button() override = default;

    void setFloor(int floor);

signals:
    void pressSignal(bool, int);
    void unpressSignal();

public slots:
    void pressSlot();
    void unpressSlot();

private:
    ButtonState _state;
    size_t _currentButtonFloor;
};

#endif// LAB_04_BUTTON_HPP
