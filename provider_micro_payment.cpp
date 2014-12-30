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
//#include <stdio.h>
#include "provider_micro_payment.h"
using namespace std;


bool CTrx::Check(const unsigned char *vch) {
};

int CTrx::set_lock_time(double Lt)
{
	if(locktime_t==-1)
	{
		return 1;
	}
	lock_time_t=lt;
	return 0;
};

// 	This function will request for the multi signature
int CTrx::request_multi_sig()
{
};

//  This function will get the multi signature
sig_t CTrx::get_multi_sig()
{
};

//	This function will set the input vector
int CTrx::set_input_vector()
{
};

// 	This function will return the input vector
inputs_vector CTrx::get_input_vector()
{

};


/****************************************************************/


CProvider::CProvider()
{
	SetDefault();
}

CProvider::~CProvider()
{
}

bool CProvider::SetDefault()
{
	// TODO set all the CProvider members with default values

	// reset all provider's variable to default value
	//providerpubkey
	return string::empty(provider_pubkey_t);//.IsNullOrEmpty();
}

// Recieve a specifications and rate vector on a constant given frequency 
// according to the canonical benchmarks
SpecAndRate_vector CProvider::Recieve_SpecAndRate_vector(input_frequency input_frequency_p, input_canonical_benchmarks_vector input_canonical_benchmarks_vector_p)
{
	// TODO get the spec and rate vector according to the two function's inputs
	// TODO set the CProvider::SpecAndRate_vector_t and return it

	// return the vector
	return SpecAndRate_vector_t;
}

// Recieve Announcement from Publisher
Publisher_Ann CProvider::Recieve_Publisher_Ann()
{
	// TODO recieve a Publisher announcement

	// Set and return the CProvider::Publisher_Ann_t variable
	return Publisher_Ann_t;
}

// Create Contract C2 with specifications and rate vector
contract_c CProvider::Create_contract_c2(SpecAndRate_vector SpecAndRate_vector_p)
{
	// TODO Create a Contract c2 with the SpecAndRate_vector_p
	// TODO return the contract
	return contract_c2_t;
}

// Send Contract C2 to Publisher. function will return 0 is succeed else if not
int CProvider::Send_Contract_C2_to_Publisher()
{
	// TODO Send the contract c2 to the Publisher

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

	return provider_pubkey_t;
}

// Signed contract c2 with public key k2. function will update the Contract_provider_sign_flag_t and will return 0 is succeed else if not
int CProvider::signed_contract_c2()
{
	// TODO

	return 0;
}

// Request public key k1 from Publisher
public_key CProvider::request_pubkey_from_publisher()
{
	// TODO request public key k1 from Publisher

	return publisher_pubkey_t;
}

// Recieve public key k1 from publisher. function will update the Contract_publisher_sign_flag_t and will return 0 is succeed else if not
//int recieve_pubkey_from_publisher()
//{
//	// TODO
//	return 0;
//}

// Update publisher signature k1 in contract c2. function will return 0 is succeed else if not
int CProvider::update_publisher_sign_in_contract_c2()
{
	// TODO 

	return 0;
}

// send the public key k2 to the publisher 
public_key CProvider::SendPubkeyToPublisher()
{
	// TODO

	return provider_pubkey_t;
}






/**********************************************
provider_pubkey_t CProvider::CreatePubkey()
{
};

// SendPubkeyToPublisher function will return 1 if provider public key is empty. 
// Function will return the provider public key otherwise to the publisher
provider_pubkey_t CProvider::SendPubkeyToPublisher()
{
	// check if provider public key is empty return 1
	if (providerpubkey.empty())
		return 1;
	return providerpubkey;
};


//
pubkey_t pub_micro::get_pubkey (int which_pubkey)
{
// which_pubkey=0 for provider, which_pubkey=1 for publisher
	if (which_pubkey==0)
	{
		return provider;
	}
	else
	{
		return publisher;
	}
}

int pub_micro::set_pubkey (pubkey_t provider_pubkey,pubkey_t publisher_pubkey,int which_pubkey)
{
// which_pubkey=0 for provider, which_pubkey=1 for publisher
// return 1 if pubkey is empty, return 0 if pubkey is ok
	if (which_pubkey==0)
	{
		if(provider_pubkey.empty())
		{
			return 1;
		}
		provider=provider_pubkey;
	}
	else
	{
		if(provider_pubkey.empty())
		{
			return 1;
		}
		publisher=publisher_pubkey;
	}
	return 0;
}
*/
 
