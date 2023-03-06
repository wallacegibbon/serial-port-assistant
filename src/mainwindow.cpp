#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {

	ui->setupUi(this);

	auto ports = QSerialPortInfo::availablePorts();
	for (auto &p : ports) {
		ui->serial_port->addItem(p.portName());
		qDebug() << p.portName();
	}
	ui->baudrate->addItem("115200");
	ui->baudrate->addItem("57600");
}

MainWindow::~MainWindow() {
	delete ui;
}

