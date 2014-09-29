//#ifndef CHANNEL_T_H
//#define CHANNEL_T_H

//#include <QObject>
//#include <QTcpServer>
//#include <QTcpSocket>
//#include <boost/shared_ptr.hpp>
//#include <boost/bind.hpp>
//#include "model.h"

//namespace xennet
//{
//class stream_t
//{
//public:
//	typedef boost::shared_ptr<stream_t> shr_stream_;
//	virtual stream_t& operator<<(const bstr&) = 0;
//	virtual stream_t& operator>>(bstr&) = 0;
//};

////typedef stream_t::shr_stream_ shr_stream;
////typedef boost::shared_ptr<QTcpSocket> shr_sock;

////template<typename T>
////stream_t& create_stream(string host, string port, std::function<T>* t)
////{
////	if (t) std::thread(*t);
////}

////class socket : public QTcpSocket, public stream_t
////{
////	Q_OBJECT

////public:
////	virtual stream_t& operator<<(const bstr& m);
////	virtual stream_t& operator>>(bstr& m);
////};

//class channel_t : public QObject
////		, public stream_t
//{
//	Q_OBJECT

//public:
////	explicit channel_t(QObject *parent = 0);

////	shr_sock c{0};
////	QTcpServer* s{0};

////	channel_t(){}
////	channel_t(shr_sock t):c(t){}

//	void connect(const char* host, ushort port);
//	void listen(ushort port);
////	shr_stream accept();
//	virtual stream_t& operator<<(const bstr& m){}
//	virtual stream_t& operator>>(bstr& m){}
////	virtual ~channel_t();

//signals:

//public slots:

//};
//}

//#endif // CHANNEL_T_H
