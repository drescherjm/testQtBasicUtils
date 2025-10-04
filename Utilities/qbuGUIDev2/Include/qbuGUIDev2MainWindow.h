#pragma once

#ifndef QBUGUIDEV0MAINWINDOW_H
#define QBUGUIDEV0MAINWINDOW_H

#include <QMainWindow>
#include <qbuBase/qbuMacros.h>
#include "ui_qbuGUIDev2MainWindow.h"

/////////////////////////////////////////////////////////////////////////////////////////

class qbuGUIDev2MainWindow : public QMainWindow, public Ui::qbuGUIDev2MainWindow
{
	Q_OBJECT
	QBU_DECLARE_SUPERCLASS(QMainWindow)
public:
	explicit qbuGUIDev2MainWindow(QWidget* parent = 0, Qt::WindowFlags flags = Qt::WindowFlags{});
    ~qbuGUIDev2MainWindow();

signals:
    void    stopJob();

public slots:
	void	on_actionTestLog0_triggered();
    void    on_actionToggleRandomData_triggered();
    void    on_actionToggle_Random_Data_Generation_Job_triggered();
	void	on_actionHide_Filename_Column_triggered();

    void    generateLogDataTimer();
private:

};

/////////////////////////////////////////////////////////////////////////////////////////

#endif // QBUGUIDEV0MAINWINDOW_H
