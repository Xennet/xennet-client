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


int CTrx::set_lock_time(double Lt)
{
	if(locktime_t==-1)
	{
		return 1;
	}
	lock_time_t=lt;
	return 0;
}

// 	This function will request for the multi signature
int CTrx::request_multi_sig()
{
}

//  This function will get the multi signature
sig_t CTrx::get_multi_sig()
{
}

//	This function will set the input vector
int CTrx::set_input_vector()
{
}

// 	This function will return the input vector
inputs_vector CTrx::get_input_vector()
{

}


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
	// reset all provider's variable to default value
	//providerpubkey
	return string::empty(providerpubkey);//.IsNullOrEmpty();
}

provider_pubkey_t CProvider::CreatePubkey()
{
}

// SendPubkeyToPublisher function will return 1 if provider public key is empty. 
// Function will return the provider public key otherwise to the publisher
provider_pubkey_t CProvider::SendPubkeyToPublisher()
{
	// check if provider public key is empty return 1
	if (providerpubkey.empty())
		return 1;
	return providerpubkey;
}


/*
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
 
