//============================================================================
// Name        : publisher_micro_payment.cpp
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
#include "publisher_micro_payment.h"
using namespace std;


int tx_t::request_multi_sig()
{
// request public key from publisher(own) wallet and set it
	sig_t new_multi_sig;
	cout<<"publisher wallet, please create a multi signature for publisher\n";
	cin>>new_multi_sig;
	if(new_multi_sig.empty())
	{
		return 1;
	}
	multi_sig=new_multi_sig;
	return 0;
};

sig_t tx_t::get_multi_sig()
{
//	return the multi signature
	sig_t tx_multi_sig;
	tx_multi_sig=multi_sig;

	return multi_sig;

}

int tx_t::set_input_vector()
{
// TO DO (with lukas data)
	return 0;

}

inputs_vector tx_t::get_input_vector()
{
// TO DO (with lukas data)

	inputs_vector output;
	return output;
}

int tx_t::set_output_object(output_object outputs)
{
// TO DO (with lukas data)
	output_object output;
	return 0;
}

output_object tx_t::get_output_object()
{
// TO DO (with lukas data)
	output_object output;
	return output;
}

int tx_t::set_lock_time(double lt)
{
	if(lt==-1)
	{
		return 1;
	}
	lock_time=lt;
	return 0;
}

tx_t::tx_t()
{
	lock_time=0;
	multi_sig="new";
}

pub_micro::pub_micro()
{
	T1.lock_time=0;
	T2.lock_time=0;
	T1.multi_sig="new";
	T2.multi_sig="new";
}

int pub_micro::request_publisher_pubkey()
{
// request public key from publisher(own) wallet
	pubkey_t new_pubkey;
	new_pubkey.clear();
	cout<<"publisher wallet, please create a public key for publisher\n";
	cin>>new_pubkey;
	if(new_pubkey.empty())
	{
		return 1;
	}
	else
	{
		publisher=new_pubkey;
		return 0;
	}
}

int pub_micro::request_provider_pubkey()
{
// request public key from provider wallet
	pubkey_t new_pubkey;
	new_pubkey.clear();
	cout<<"provider wallet, please send a public key for provider\n";
	cin>>new_pubkey;
	if(new_pubkey.empty())
	{
		return 1;
	}
	else
	{
		provider=new_pubkey;
		return 0;
	}

}


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

