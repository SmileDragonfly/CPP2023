#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsTest.h"

class QtWidgetsTest : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsTest(QWidget *parent = nullptr);
    ~QtWidgetsTest();

private:
    Ui::QtWidgetsTestClass ui;
};
