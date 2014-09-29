//#include "channel_t.h"

//namespace xennet
//{

//channel_t::channel_t(QObject *parent) :
//	QObject(parent)
//{
//}

//void channel_t::connect(const char* host, ushort port)
//{
//	if (c || s) throw std::runtime_error("socket not null");
////	 c = new QTcpSocket();
//	 c->connectToHost(host, port);
//}

//void channel_t::listen(ushort port)
//{
//	if (c || s) throw std::runtime_error("socket not null");
//	s = new QTcpServer();
//	if (!s->listen(QHostAddress::Any, port))
//		throw std::runtime_error("listen failed");
//}

//shr_stream channel_t::accept()
//{
//	if (!s) throw std::runtime_error("accepting without init");
////	return new channel_t(s->nextPendingConnection());
//}

//stream_t& channel_t::operator<<(const bstr& m)
//{
//	if (!c) throw std::runtime_error("socket not initialized");
//	uint32_t sz = m.size();
//	if (c->write((const char*)&sz, sizeof(uint32_t)) != sizeof(uint32_t))
//		throw std::runtime_error("write failed");
//	if (c->write(m.c_str(), sz) != sz)
//		throw std::runtime_error("write failed");
//	return *this;
//}

//stream_t& channel_t::operator>>(bstr& m)
//{
//	uint32_t sz;
////	if (c->read((const char*)&sz, sizeof(uint32_t)) != sizeof(uint32_t))
////		throw std::runtime_error("read failed");
//	char *a = new char[sz];
//	if (c->read(a, sz) != sz)
//		throw std::runtime_error("read failed");
//	m = a;
//	delete[] a;
//	return *this;
//}

//channel_t::~channel_t()
//{
//	if (s) delete s;
//}

//}
