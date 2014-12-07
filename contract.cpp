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
#include "contract.h"
using namespace std;

//	TO DO
contract_t::contract_t()
{
// the initial pubkey's string are "new"
	provider="new";
	publisher="new";
}

contract_t::contract_t(pubkey_t initial_provider_pubkey,pubkey_t initial_publisher_pubkey)
{
	provider=initial_provider_pubkey;
	publisher=initial_publisher_pubkey;
}


int contract_t::set_pubkey (pubkey_t provider_pubkey,pubkey_t publisher_pubkey,int which_pubkey)
{
// which_pubkey=0 for provider, which_pubkey=1 for publisher
// return 1 if pubkey is empty, return 0 if pubkey is ok (neede for log error manager file)
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
		if(publisher_pubkey.empty())
		{
			return 1;
		}
		publisher=publisher_pubkey;
	}
	return 0;
}

pubkey_t contract_t::get_pubkey (int which_pubkey)
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
