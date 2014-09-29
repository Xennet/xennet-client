#include "xennet.h"
#include "mainwindow.h"
#include <assert.h>

QList<QString> benchmarks({ "bench1", "bench2", "bench3" });

QList<QString> resources({});

QList<QString> spec_basic({
														"destdir", "cpus",  "mem", "arch",
														"rootsize", "optsize", "swapsize",
														"ssh-key",
														"ssh-user-key","suite", "flavour",
														"user", "name", "pass", "rootpass"});
QList<QString> spec_net({
													"network", "ip", "mask", "net", "gw", "dns"
													"firstboot", "firstlogin", "components","hostname"});

QList<QString> spec_adv({
													"iso", "mirror",
													"proxy", "copy", "execscript",
													"addpkg", "removepkg",
													"lock-user",
												});

// TODO: remove specs and create "virtualbox options" and "vmbuilder options"
// might be done automaticlly by running them -h

QString buildvm(const QStringList& spec) {
	QString cmd = "sudo vmbuilder kvm ubuntu";
	foreach(auto s,spec) cmd += QString(" --") + s + "=" + s;
	return cmd;
}

// returns an execution command on the vm
QString tellvm(const object& spec, QString& cmd) {
	//return QString("ssh %1@%2 -t %3").arg(spec["user"], spec["host"], cmd);
}
class channel;

object *local_vms, *remote_vms, *publishers, *workers, *anns;
QMap<object*, channel*> channels;

//bool auth(const )

object* s;

void print() { (std::cout<<s->json().toStdString()).flush(); }

int main(int argc,char** argv)
{
	QApplication app(argc, argv);
	(new MainWindow)->show();
	return app.exec();
}
