#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "model.h"
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	init_classes();
	model->appendRow(new object("VMs", new container("vms", "vm")));
	model->appendRow(new object("Tasks", new container("anns", "ann")));
	ui->treeView->setModel(model);
	connect(ui->treeView, &QWidget::customContextMenuRequested, [&](const QPoint &pos){
		auto idx = ui->treeView->indexAt(pos);
		if (idx.isValid()) {
				auto cm = ((object*)model->itemFromIndex(idx))->contextMenu();
				if(cm) cm->exec(ui->treeView->mapToGlobal(pos));
		}
	});
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::contextMenu(const QPoint &pos){

}
