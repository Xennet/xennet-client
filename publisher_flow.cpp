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

// To Do
int publisher_flow()
{

	int error_type=0;
	bool agree=false;
	pub_micro pub;
	contract_t provider_contract;
	contract_t publisher_contract;

//	ann process function
//	int publish_ann();

//	negotiation process in while loop
	while(!agree)
	{
//  receive a contract "provider_contract" from provider
	provider_contract=receive_contract();
//	negotiate_contract function offerers a substitute contract by publisher
	publisher_contract=negotiate_contract();
//	compare_contract function compare between contract return true if agreed
	agree = compare_contract(provider_contract,publisher_contract);
	}

//	request the publisher public key from wallet
	error_type=pub.request_publisher_pubkey();
//	request provider public key from the provider
	error_type=pub.request_provider_pubkey();
//	update publisher public key in contract
	error_type=publisher_contract.set_pubkey(pub.get_pubkey(0),pub.get_pubkey(1),0);
//	update provider public key in contract
	error_type=publisher_contract.set_pubkey(pub.get_pubkey(0),pub.get_pubkey(1),1);
//	request multi signature from the wallet
	error_type=pub.T1.request_multi_sig();





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

