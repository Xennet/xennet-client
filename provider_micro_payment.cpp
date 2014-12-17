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
};

CProvider::~CProvider()
{
};

bool CProvider::SetDefault()
{
	// reset all provider's variable to default value
	//providerpubkey
	return string::empty(providerpubkey);//.IsNullOrEmpty();
};

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


