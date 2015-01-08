//============================================================================
// Name        : provider_micro_payment.cpp
// Author      : zennet R\D
// Version     : 0
// Copyright   : zennet provider_micro_payment cpp file
// Description : zennet provider_micro_payment code
//============================================================================


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include<stdlib.h>
#include <stdio.h>
#include "provider_micro_payment.h"
using namespace std;


CProvider::CProvider()
{
	SetDefault();
}

CProvider::~CProvider()
{
}

void CProvider::SetDefault()
{
	CProvider::provider_prvkey_t = "";
	CProvider::provider_pubkey_t = "";
	CProvider::publisher_pubkey_t = "";
	CProvider::Contract_provider_sign_flag_t = 0;
	CProvider::Contract_publisher_sign_flag_t = 0;
	CProvider::frequency_t = "";
	CProvider::canonical_benchmarks_vector_t = "";
	CProvider::SpecAndRate_vector_t = "";
	CProvider::Publisher_Ann_t = "";
	CProvider::contract_c2_t = "";
	CProvider::contract_c1_t = "";
//	CTrx CProvider::trx_t;
//	ProviderWallet CProvider::provider_wallet_t;
}

// Recieve a specifications and rate vector on a constant given frequency 
// according to the canonical benchmarks
SpecAndRate_vector CProvider::Recieve_SpecAndRate_vector(input_frequency input_frequency_p, input_canonical_benchmarks_vector input_canonical_benchmarks_vector_p)
{
	// TODO get the spec and rate vector according to the two function's inputs
	// TODO set the CProvider::SpecAndRate_vector_t and return it

	// return the vector
	return CProvider::SpecAndRate_vector_t;
}

// Recieve Announcement from Publisher
Publisher_Ann CProvider::Recieve_Publisher_Ann()
{
	// TODO recieve a Publisher announcement

	// Set and return the CProvider::Publisher_Ann_t variable
	return CProvider::Publisher_Ann_t;
}

// Create Contract C2 with specifications and rate vector
contract_c CProvider::Create_contract_c2(SpecAndRate_vector SpecAndRate_vector_p)
{
	// TODO Create a Contract c2 with the SpecAndRate_vector_p
	// TODO return the contract
	return CProvider::contract_c2_t;
}

// Send Contract C2 to Publisher. function will return 0 is succeed else if not
int CProvider::Send_Contract_C2_to_Publisher()
{
	// TODO Send the contract c2 to the Publisher
	cout<<"Provider: sending contract c2 to Publisher:";
	cout<<CProvider::contract_c2_t; // TODO a desplay function to contract object
	return 0;
}

// Upodate contract c2 if necessary. function will return 0 is succeed else if not
int CProvider::update_contract_c2()
{
	// TODO update contract c2

	return 0;
}

// create public key k2 to the provider  
public_key CProvider::CreatePubkey()
{
	// TODO create public key k2 for the Provider and return it

	return CProvider::provider_pubkey_t;
}

// Signed contract c2 with public key k2. function will update the Contract_provider_sign_flag_t and will return 0 is succeed else if not
int CProvider::signed_contract_c2()
{
	// TODO
	CProvider::Contract_provider_sign_flag_t = true;

	return 0;
}

// Request and recieve public key k1 from Publisher
public_key CProvider::request_pubkey_from_publisher()
{
	// TODO request public key k1 from Publisher
	cout<<"Provider: Requesting for public key k1 from Publisher";
	cin>>CProvider::publisher_pubkey_t;

	return CProvider::publisher_pubkey_t;
}

// Update publisher signature k1 in contract c2. function will return 0 is succeed else if not
int CProvider::update_publisher_sign_in_contract_c2()
{
	// TODO 
	CProvider::Contract_publisher_sign_flag_t = true;
	return 0;
}

// send the public key k2 to the publisher 
public_key CProvider::SendPubkeyToPublisher()
{
	// TODO
	cout<<"Provider: Sending public key k2 to Publisher";
	cout<<CProvider::provider_pubkey_t;
	return CProvider::provider_pubkey_t;
}

