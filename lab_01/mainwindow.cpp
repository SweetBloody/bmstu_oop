#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "task_manager.h"
#include "error.h"
#include "operations.h"


MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    request_t req;
    req.t = INIT;
    task_manager(req);
}


MainWindow::~MainWindow()
{
    delete ui;
}


// Drawing figure
errors draw_action(Ui::MainWindow* ui)
{
    draw_t dr;

    dr.gV = ui->graphicsView;
    dr.h = ui->graphicsView->height();
    dr.w = ui->graphicsView->width();

    request_t req;
    req.t = DRAW;
    req.draw = dr;

    errors err = (errors) task_manager(req);
    return err;
}


// Process of requests
errors transform_and_show(request_t req, Ui::MainWindow* ui)
{
    errors err = (errors) task_manager(req);
    if (err)
        return err;
    else
        err = draw_action(ui);

    return err;
}


// Load figure from file
void MainWindow::on_actionOpen_clicked()
{
    request_t req;
    req.t = LOAD_FILE;
    req.load_f.filename = "data.txt";

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}


// Process of move button
void MainWindow::on_button_Move_clicked()
{
    request_t req;
    req.t = MOVE;

    req.move.dx = ui->lineEdit_MoveX->text().toInt();
    req.move.dy = ui->lineEdit_MoveY->text().toInt();
    req.move.dz = ui->lineEdit_MoveZ->text().toInt();

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}


// Process of scale button
void MainWindow::on_button_Scale_clicked()
{
    request_t req;
    req.t = SCALE;

    req.scale.kx = ui->lineEdit_ScaleX->text().toFloat();
    req.scale.ky = ui->lineEdit_ScaleY->text().toFloat();
    req.scale.kz = ui->lineEdit_ScaleZ->text().toFloat();

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}


// Process of turn button
void MainWindow::on_button_Turn_clicked()
{
    request_t req;
    req.t = TURN;

    req.turn.ox = ui->lineEdit_TurnX->text().toFloat();
    req.turn.oy = ui->lineEdit_TurnY->text().toFloat();
    req.turn.oz = ui->lineEdit_TurnZ->text().toFloat();

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

