#ifndef WALLET_H
#define WALLET_H
#include <QtWidgets>
class wallet
{
	wallet(){}
public:
	static wallet instance;
	static void publish(QString ann) {}
};

#endif // WALLET_H
