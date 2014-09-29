#include "model.h"

using namespace std;

template<typename T> QVariantMap pr(T x) {
	QVariantMap r;
	r["ui"] = x;
	return r;
}

map<QString, type_t*> tomap(const QList<QString>& x, const char* l) {
	map<QString, type_t*> res;
	foreach(auto k,x) res[k] = classes[l];
	return res;
}

void init_classes()
{
	new type_t("var");
	new type_t("int");
	new type_t("uint");
	new type_t("float");
	new type_t("string");
	new type_t("file");
	new type_t("dir");
	new type_t("range");

	new type_t("specs", {
							 { "Basic",		new type_t("spec_basic", tomap(spec_basic, "var"))} ,
							 { "Net",			new type_t("spec_net", tomap(spec_net, "var"))} ,
							 { "Advanced", new type_t("spec_adv", tomap(spec_adv, "var"))}
						 });
	new type_t("rates", {
							 { "Basic",		new type_t("rates_basic", tomap(spec_basic, "float"))} ,
							 { "Net",			new type_t("rates_net", tomap(spec_net, "float"))} ,
							 { "Advanced", new type_t("rates_adv", tomap(spec_adv, "float"))} ,
							 { "Resources", new type_t("resources", tomap(resources, "float"))}
						 });
	new type_t("scores", tomap(benchmarks, "float"));

	type_t& p = *new type_t("performance");
	foreach(auto b,benchmarks) {
		p["Score"]= classes["float"];
		foreach(auto r,resources) p[r] = classes["float"];
	}

	new type_t("vm", {
							 { "spec", classes["specs"]  },
							 { "performance", classes["performance"]  },
							 { "rates", classes["rates"]  }
						 } );

	// TODO: remove class menu and use type_t ops
	// TODO: wallet type
	new type_t("ann", {
							 { "Host",	classes["string"] },
							 { "Port",	classes["uint"] },
							 { "MinPOW",	classes["uint"] },
							 { "Spec",	classes["specs"] },
							 { "Rate",	classes["specs"] },
							 { "Scores",	classes["scores"] }
						 });

#define __SET_BUTTONS__(x) classes[x]->props["button"] = classes[x]->props["grid"] = 1;
	__SET_BUTTONS__("spec_basic");
	__SET_BUTTONS__("spec_net");
	__SET_BUTTONS__("spec_adv");
	__SET_BUTTONS__("rates");
	__SET_BUTTONS__("scores");
/*	classes["ann"]->ops["View as Tree"] = [](object* o){
		auto d = new QDialog;
		auto l = new QVBoxLayout;
		d->setLayout(l);
		auto t = new QTreeView;
		l->addWidget(t);
		auto m = new QStandardItemModel(1,1);
		t->setModel(m);
		m->setItem(0,0,o);
		d->exec();
	};*/
}

map<QString, type_t*> classes;
map<QString, object*> instances;

struct onexit_t {
	~onexit_t() {
		for(auto x:classes)delete x.second;
		for(auto x:instances)delete x.second;
	}
} onexit;

bool object::has(const char* x) const { return type->has(x); }
bool type_t::has(const char* x) const { if(props.find(x)==props.end())return false; return props.at(x).isValid(); }
QString object::prop(const char* x) { return type->props.at(x).toString(); }

void object::on_change(const QString&) { print(); }

object::object(QString name, const type_t* _clas, object* p) : type(_clas), parent(p) {
	uint n = 0;
	setRowCount(type->size());
	for(auto x : *type) setChild(n++, new object(x.first, x.second, this));
	setText(name);
	setEditable(!type->size());
}

object& object::operator=(const QString& json) {
	return (*this) = QJsonDocument::fromJson(json.toLatin1()).object().toVariantMap();
}

object& object::operator=(const QVariantMap& m) {
	setText(m.begin().key());
	if (m.begin().value().type() == QVariant::Map)
		for(auto x: members()) *x = m[x->text()].toMap();
	else
		setData(m.begin().value());
	return *this;
}

object::operator const QVariant&() {
	if (!rowCount()) return data();
	QVariantMap r, ch;
	for(auto x: members()) ch.insert(x->text(), (const QVariant&)*x);
	r.insert(text(), ch);
	setData(r);
	return r;
}

QString object::json() {
	return QString::fromLatin1(QJsonDocument(QJsonObject::fromVariantMap(((const QVariant&)*this).toMap())).toJson());
}

void object::on_text_changed(const QString& s) {
	setData(s);
	print();
}

type_t::type_t(QString _name, const members_t& m) : members_t(m), name(_name) {
	classes[name] = this;
}

type_t* type_t::clone(QString newname) {
	auto r = new type_t(newname, *this);
	r->props = props;
	r->ops = ops;
	return r;
}

std::vector<object*> object::members() {
	std::vector<object*> r;
	for (uint n = 0; n < rowCount(); ++n) r.push_back(dynamic_cast<object*>(child(n)));
	return r;
}

QMenu* object::contextMenu() {
	if (!type->ops.size()) return 0;
	auto m = new QMenu(type->name);
	for(auto x: type->ops) {
		auto a = new QAction(x.first, 0);
		m->insertAction(0, a);
		connect(a, &QAction::triggered, [=](bool){(*x.second)(this);});
	}
	return m;
}

void add(object* o) {
	/*auto i = new QInputDialog;
	i->setInputMode(type->has("string") ? QInputDialog::TextInput : (
									type->has("int") ? QInputDialog::IntInput :
									type->has("float") ? QInputDialog::DoubleInput : throw std::invalid_argument("in setInputMode")
	));
	i->exec();*/
	auto t = ((const container*)o->type)->type;
	bool ok;
	QString name;
	name = QInputDialog::getText(0, "Add New", (QString("Name of new ") + t->name) + ":", QLineEdit::Normal, name, &ok);
	if (!ok) return;
	o->insertRow(o->rowCount(), new object(name, t, o));
}

container::container(QString name, QString _type) : type_t(name), type(classes[_type]) {
	ops["Create"] = new std::function<void(object*)>(add);
}
