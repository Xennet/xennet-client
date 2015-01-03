//============================================================================
// Name        : publisher_micro_payment.h
// Author      : zennet R\D
// Version     : 0
// Copyright   : zennet contract header file
// Description : zennet contract code
//============================================================================


#ifndef PUBLISHER_MICRO_PAYMENT_H_
#define PUBLISHER_MICRO_PAYMENT_H_



#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "contract.h"
using namespace std;

typedef map<pubkey_t,coins_t> output_object;
typedef vector<pubkey_t>  inputs_vector;



// 	tx_t class is for the "logical deposit box" class declaration
class tx_t
{
	friend class pub_micro;
public:

//	TO DO
	void set_input_vector(pubkey_t pubkey);
// 	TO DO
	inputs_vector get_input_vector();
//	TO DO
	void set_output_object(pubkey_t pubkey,int which_tx);
//	TO DO
	output_object get_output_object();
// 	TO DO
	int request_multi_sig();
//  TO DO
	sig_t get_multi_sig();
//	TO DO
	int set_multi_sig(sig_t signature);
//	TO DO
	int request_digital_signature();
//	TO DO
	int request_time_lock(int which_tx);
//	TO DO
	int set_time_lock(double lt);
//	To Do
	int send_transaction();
//	TO DO
	tx_t();

private:

//	TO DO
	inputs_vector inputs;
//  TO DO
	output_object outputs;
//	deposit_sig member is the deposit multi signature string declaration
	sig_t multi_sig;
//	publisher signature
	sig_t signature;
//  lock time of the transaction in days
	double time_lock;
};


class pub_micro
{
	//friend class tx_t;
public:
	int request_publisher_pubkey();
	int request_provider_pubkey();
	int set_pubkey (pubkey_t provider_pubkey,pubkey_t publisher_pubkey,int which_pubkey);
	pubkey_t get_pubkey (int which_pubkey);
	pub_micro();
	int request_multi_sig();
	//  the class member T1 is the Zencoins transaction
	tx_t T1;
	//  the class member T2 is the refund transaction
	tx_t T2;
	//	the updating transaction of Zencoins
	tx_t T3;

private:
	//  the class member "publisher" is a string public key
		pubkey_t provider;

	//  the class member "publisher" is a string public key
		pubkey_t publisher;
};







#endif /* PUBLISHER_MICRO_PAYMENT_H_ */
