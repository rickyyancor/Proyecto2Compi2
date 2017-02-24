#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include "../gen-cpp/Calculator.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace tutorial;
using namespace boost;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString Solicitar(QString alto)
{
    shared_ptr<TTransport> socket(new TSocket("localhost", 9090));
    shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    CalculatorClient client(protocol);

    try {
      transport->open();

      client.ping();
      string kk;
      string pp=alto.toStdString();
      client.Generar3D(kk,pp);

      transport->close();
        return kk.data();
    }
    catch (TException &tx) {
      printf("ERROR: %s\n", tx.what());
      return "error";
    }

}
void MainWindow::on_pushButton_clicked()
{
    QString aa=ui->textEdit->toPlainText();
    aa=Solicitar(aa);
    ui->textEdit_2->setText(aa);
}
