#ifndef MODEL_H
#define MODEL_H

#include <utility>
#include <algorithm>
//#include <thread>
#include <cmath>
#include <QApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>
#include <QTextStream>
#include <iostream>
#include <map>
#include <QTextEdit>
#include <set>
#include <functional>
#include <QtWidgets>
#include <vector>
#include <functional>

class type_t;
class object;
typedef std::map<QString, type_t*> class_map_t;
typedef std::map<QString, object*> object_map_t;
extern class_map_t classes;
extern object_map_t instances;
extern QList<QString> spec_basic, spec_adv, spec_net, benchmarks, resources;

void init_classes();
void print();

typedef std::map<QString, type_t*> members_t;

class type_t : public members_t
{
public:
	const QString name;
	type_t(QString _name, const members_t& m = members_t());
	map<QString, QVariant> props;
	map<QString, std::function<void(object*)>* > ops;
	type_t* clone(QString newname);
	bool has(const char* x) const;
};

class container : public type_t {
public:
	type_t* type;
	container(QString name, QString _type);
};

class object :
		public QObject,
		public QStandardItem
{
	Q_OBJECT
	bool has(const char* x) const;
	QString prop(const char* x);
	QWidget* create_groupbox(QLayout* layout);
	QWidget* create_frame(QLayout* layout);
	QLayout* create_layout();

public:
	const type_t* type;
	const object* parent;
	object(QString name, const type_t* _clas, object* p = 0);
	QString json();
	object& operator=(const QString& json);
	object& operator=(const QVariantMap& m);
	virtual operator const QVariant&();
	operator QWidget*();
	operator const QStringList& () const;
	void on_op(QString op) {}
	std::vector<object*> members();
	operator std::vector<object*>() { return members(); }
	QMenu* contextMenu();
public slots:
	virtual void on_text_changed(const QString& s);
	virtual void on_change(const QString&);
};
#endif // MODEL_H
