//============================================================================
// Name        : contract.cpp
// Author      : zennet R\D
// Version     : 0
// Copyright   : zennet contract_functions cpp file
// Description : zennet contract functions code
//============================================================================


#include <iostream>
#include <map>
#include <vector>
#include <string>
//#include <stdio.h>
#include "contractRavit.h"
using namespace std;

// function set_pubkey () will checks validation of the given keys and then set the pubkeys value
// by calling the class private functions set_publisher_pubkey() and set_provider_pubkey()
// function will return 0 if pubkeys were sets and return 1 if not
bool contract_t::set_pubkey (pubkey_t provider_pubkey, pubkey_t publisher_pubkey) 
{
	// Check pubkey validation. if pubkeys not valid (if one or both parameters equal null string) then return 0
	if ((provider_pubkey.empty()) || (publisher_pubkey.empty()))
		return 1;
	
	// else call set_publisher_pubkey() and set_provider_pubkey() functions and return 1
	set_publisher_pubkey (publisher_pubkey);
	set_provider_pubkey (provider_pubkey);
	return 0;
}

// function set_publisher_pubkey () will set the publisher public key value
void contract_t::set_publisher_pubkey (pubkey_t publisher_pubkey)
{
	publisher=publisher_pubkey;
}

// function set_provider_pubkey () will set the provider public key value
void contract_t::set_provider_pubkey (pubkey_t provider_pubkey)
{
	provider=provider_pubkey;
}

// function get_publisher_pubkey () will retrives the publisher public key
pubkey_t contract_t::get_publisher_pubkey ()
{
	return publisher;
}

// function get_provider_pubkey () will retrives the provider public key
pubkey_t contract_t::get_provider_pubkey ()
{
	return provider;
}




