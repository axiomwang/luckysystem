#include "nameinterface.h"
#include "ui_nameinterface.h"
#include<QFileDialog>
#include <QDir>

NameInterface::NameInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NameInterface)
{
    ui->setupUi(this);
}

void NameInterface::mousePressEvent(QMouseEvent *e){
    if (e->button() == Qt::LeftButton) {
        const QString fileName = QFileDialog::getOpenFileName(
                    this,
                    "选择你想导入的文件",
                    QDir::currentPath(),
                    "文本文件 (*.txt);;CSV 文件 (*.csv);;Excel 文件 (*.xlsx)");
        Q_UNUSED(fileName)
    } else {
        QWidget::mousePressEvent(e);
    }
}

void NameInterface::slideShow()
{
}

NameInterface::~NameInterface()
{
    delete ui;
}
