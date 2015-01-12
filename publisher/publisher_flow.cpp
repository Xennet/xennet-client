//============================================================================
// Name        : publisher_flow.cpp
// Author      : zennet R\D
// Version     : 0
// Copyright   : zennet publisher_flow cpp file
// Description : zennet publisher_flow code
//============================================================================


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "contract.h"
#include "publisher_micro_payment.h"
#include "publisher_flow.h"
using namespace std;

// 						Publisher Flow Process
int publisher_flow()
{

	int error_type=0;
	coins_t stop_condition=0;
	bool agree=false;
	coins_t coins_update=0;
	pub_micro pub;
	contract_t provider_contract;
	contract_t publisher_contract;

//						ann process

//	int publish_ann();


//						negotiation process
	while(!agree)
	{
//  receive a contract "provider_contract" from provider
	provider_contract=receive_contract();
//	negotiate_contract function offerers a substitute contract by publisher
	publisher_contract=negotiate_contract();
//	compare_contract function compare between contract return true if agreed
	agree = compare_contract(provider_contract,publisher_contract);
	}

//						micropayments process

//	request the publisher public key from wallet
	error_type=pub.request_publisher_pubkey();
//	request provider public key from the provider
	error_type=pub.request_provider_pubkey();
//	update publisher public key in contract
	error_type=publisher_contract.set_pubkey(pub.get_pubkey(0),pub.get_pubkey(1),0);
//	update provider public key in contract
	error_type=publisher_contract.set_pubkey(pub.get_pubkey(0),pub.get_pubkey(1),1);
//	request multi signature from the wallet and update T1
	error_type=pub.T1.request_multi_sig();
//	request a digital signature from the wallet for T1
	error_type=pub.T1.request_digital_signature();
//	update T1 with publisher pubkey ?? or other inputs ??
	pub.T1.set_input_vector(pub.get_pubkey(1));
//  	update T1 with multi signature as output and Zencoins
	pub.T1.set_output_object(pub.T1.get_multi_sig(),pub.T1.request_coins(1));
//	request time_lock for T2 from the publisher wallet
	error_type=pub.T2.request_time_lock(2);
//	update T2 input with multi sugnature
	pub.T2.set_input_vector(pub.T1.get_multi_sig());
//	update T2 output to publisher address as "all money refund"
	pub.T2.set_output_object(pub.get_pubkey(1),pub.T1.get_output_object(pub.T1.get_multi_sig()));
//	Send the refund transaction T2 to the provider
	error_type=pub.T2.send_transaction(0);
//	Receive the signed refund transaction T2 from the provider
	error_type=pub.T2.receive_transaction();
//	verify the provider signature in the signed refund transaction T2
	error_type=pub.T2.verify_signature(pub.T2.get_digital_signature());
//	abort the contract if signature verification is failed
	if(error_type==1)
	{
		return 1;
	}
//	send the signed transaction T1 to the provider
	error_type=pub.T1.send_transaction(0);
//	send the signed transaction T1 to the multi signature
	error_type=pub.T1.send_transaction(1);


	stop_condition=0;
//	update T3 input with multi signature
	pub.T3.set_input_vector(pub.T1.get_multi_sig());

//						micropayment step
	while(stop_condition<=pub.T1.get_output_object(pub.T1.get_multi_sig()))
	{
//	calculate the amounts of Zencoins in T3,which has been "balance change" in T1
	coins_update=pub.T3.calculate_coins();
//	update T3 output to publisher address
	pub.T3.set_output_object(pub.get_pubkey(1),coins_update);

//	sign with digital signature in T3
	//pub.T3.set_digital_signature(pub.T1.get_digital_signature());
	}



	return error_type;
}


contract_t receive_contract()
{
	contract_t provider_contract;
//	To Do
	return provider_contract;
}


contract_t negotiate_contract()
{
	contract_t publisher_contract;
//	To Do
	return publisher_contract;

}


bool compare_contract(contract_t provider_contract,contract_t publisher_contract)
{
	bool agree=false;
//	To Do
	return agree;
}
