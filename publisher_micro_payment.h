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
// 	TO DO
	int request_multi_sig();
//  TO DO
	sig_t get_multi_sig();
//	TO DO
	int set_input_vector();
// 	TO DO
	inputs_vector get_input_vector();
//	TO DO
	int set_output_object(output_object outputs);
//	TO DO
	output_object get_output_object();
//	TO DO
	int set_lock_time(double lt);
//	TO DO
	tx_t();

private:
//	TO DO
//	vector<pubkey_t> inputs_vector;
	inputs_vector inputs;
//  TO DO
//	map<pubkey_t,coins_t> output_object;
	output_object outputs;
//	deposit_sig member is the deposit multi signature string declaration
	sig_t multi_sig;
//  lock time of the transaction in days
	double lock_time;
};


class pub_micro
{
public:
	int request_publisher_pubkey();
	int request_provider_pubkey();
	int set_pubkey (pubkey_t provider_pubkey,pubkey_t publisher_pubkey,int which_pubkey);
	pubkey_t get_pubkey (int which_pubkey);
	pub_micro();

private:
	//  the class member "publisher" is a string public key
		pubkey_t provider;

	//  the class member "publisher" is a string public key
		pubkey_t publisher;
	//  the class member T1 is the Zencoins transaction
		tx_t T1;
	//  the class member T2 is the refund transaction
		tx_t T2;

};







#endif /* PUBLISHER_MICRO_PAYMENT_H_ */
