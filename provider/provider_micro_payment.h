//============================================================================
// Name        : provider_micro_payment.h
// Author      : zennet R\D
// Version     : 0
// Copyright   : zennet provider_micro_payment header file
// Description : zennet provider_micro_payment code
//============================================================================

#ifndef PROVIDER_MICRO_PAYMENT_H_
#define PROVIDER_MICRO_PAYMENT_H_

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "providerwallet.h"
using namespace std;

// For class CProvider
typedef std::string private_key;
typedef std::string public_key;
typedef std::string SpecAndRate_vector;
typedef std::string input_frequency;
typedef std::string input_canonical_benchmarks_vector;
typedef std::string Publisher_Ann;
typedef std::string contract_c;


/*
	CProvider is the ZENNET Server which is a computer­ owner willing to participate and earn
	The CProvider will:
		- Will do some canonical benchmarks
		- Will deals with the specifications & rate vactor (which refers to the ZENNET pricing algorithm) on a 
			constant given frequency (given by the user or defined as a default) according to the canonical benchmarks
		- Create negocialts and signed a Ccontract with the Publisher
		- have a provider Cwallet 
		- Create 3 Transactions: T1, T2 and T3
*/

class CProvider
{
private:
	// define the CProvider private key
	private_key provider_prvkey_t;
	// define the CProvider public key
	public_key provider_pubkey_t;
	// define the Publisher public key
	public_key publisher_pubkey_t;
	// define Contract provider sign flag. 0 is unsigned else signed
	int Contract_provider_sign_flag_t;
	// define Contract publisher sign flag. 0 is unsigned else signed
	int Contract_publisher_sign_flag_t;
	// define given frequency
	input_frequency frequency_t;
	// define given canonical benchmarks
	input_canonical_benchmarks_vector canonical_benchmarks_vector_t;
	// define the specifications and rate vector
	SpecAndRate_vector SpecAndRate_vector_t;
	// define Publisher Announcement
	Publisher_Ann Publisher_Ann_t;
	// define the provider contract c2
	contract_c contract_c2_t;
	// define an alternative contract c1 (for terms negociations) 
	contract_c contract_c1_t;

	// function will reset all class members to default values
	void SetDefault();
	// Trx implement the provider's transactions (t1,t2)
//	class CTrx trx_t;
	// ProviderWallet implement the provider's wallet operations
//	struct ProviderWallet provider_wallet_t;

public:
	// Constructors
	CProvider();
	//CProvider(provider_pubkey_t providerpubkey);
	// Distructor
	~CProvider();

	// Recieve a specifications and rate vector on a constant given frequency 
	// according to the canonical benchmarks
	SpecAndRate_vector Recieve_SpecAndRate_vector(input_frequency input_frequency_p, input_canonical_benchmarks_vector input_canonical_benchmarks_vector_p);

	// Recieve Announcement from Publisher
	Publisher_Ann Recieve_Publisher_Ann();

	// Create Contract C2 with specifications and rate vector
	contract_c Create_contract_c2(SpecAndRate_vector SpecAndRate_vector_p);

	// Send Contract C2 to Publisher. function will return 0 is succeed else if not
	int Send_Contract_C2_to_Publisher();

	// Upodate contract c2 if necessary. function will return 0 is succeed else if not
	int update_contract_c2();

	// create public key k2 to the provider  
	public_key CreatePubkey();

	// Signed contract c2 with public key k2. function will update the Contract_provider_sign_flag_t and will return 0 is succeed else if not
	int signed_contract_c2();

	// Request and recieve public key k1 from Publisher
	public_key request_pubkey_from_publisher();

	// Update publisher signature k1 in contract c2. function will return 0 is succeed else if not
	int update_publisher_sign_in_contract_c2();

	// send the public key k2 to the publisher 
	public_key SendPubkeyToPublisher();
};

#endif /* PROVIDER_H_ */
