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


int tx_t::set_multi_sig(sig_t signature)
{
	if(signature.empty())
	{
		return 1;
	}
	else
	{
		multi_sig=signature;
		return 0;
	}
}

sig_t tx_t::get_multi_sig()
{
//	return the multi signature
	return multi_sig;
}

void tx_t::set_input_vector(pubkey_t pubkey)
{
	inputs.reserve(1);
	inputs[1]=pubkey;
}


inputs_vector tx_t::get_input_vector()
{
// TO DO (with lukas data)

	inputs_vector output;
	return output;
}

void tx_t::set_output_object (pubkey_t pubkey,coins_t coins)
{
	outputs[pubkey]=coins;
}

coins_t tx_t::request_coins (int which_tx)
{
	coins_t new_coins;
	cout<<"publisher wallet, please send an output coins for T"<<which_tx<< "\n";
	cin>>new_coins;
	return new_coins;
}

coins_t tx_t::calculate_coins()
{
	coins_t new_coins=0;
	pricing_vector v;
	cout<<"publisher OS, please send a cgroup vector\n";
	// coins calculation by Zennet Os pricing vector
	return new_coins;
}

coins_t tx_t::get_output_object (pubkey_t pubkey)
{
// return the coins for specific pubkey in output STL object
	return outputs[pubkey];
}

int tx_t::request_digital_signature()
{
//	request publisher wallet for a digital signature
	sig_t new_signature;
	new_signature.clear();
	cout<<"publisher wallet, please create a digital signature for publisher\n";
	cin>>new_signature;
	if(new_signature.empty())
	{
		return 1;
	}
	else
	{
		signature=new_signature;
		return 0;
	}
}

int tx_t::set_digital_signature(sig_t new_sig)
{
	if(new_sig.empty())
	{
		return 1;
	}
	else
	{
		signature=new_sig;
		return 0;
	}
}

sig_t tx_t::get_digital_signature()
{
	return signature;
}

int tx_t::request_time_lock(int which_tx)
{
	double new_time_lock=0;
	cout<<"publisher wallet, please define a time_lock for T"<<which_tx<<"\n";
	cin>>new_time_lock;
	if(new_time_lock>=0)
	{
		time_lock=new_time_lock;
		return 0;
	}
	else
	{
		return 1;
	}
}

int tx_t::set_time_lock(double tl)
{
	if(tl==-1)
	{
		return 1;
	}
	time_lock=tl;
	return 0;
}

int tx_t::send_transaction(int which_address)
{
//	send transaction with Linux (with Lukas)
//	which_address=0 for provider, and which_address=1 for multi signature
	return 0;
}

int tx_t::receive_transaction()
{
//	receive transaction with Linux (with Lukas)
	return 0;
}

int tx_t::verify_signature(sig_t new_signature)
{
//	verify a digital signature of the provider by the publisher wallet
//	wallet return "1" to abort or "0" if verified
	int error_type=0;
	cout<<"wallet, pls verify provider digital signature\n"<<new_signature<<"\n";
	cin>>error_type;
	return error_type;
}

tx_t::tx_t()
{
	time_lock=0;
	multi_sig.empty();
}

pub_micro::pub_micro()
{
	T1.time_lock=0;
	T2.time_lock=0;
	T3.time_lock=0;
	T1.multi_sig.clear();
	T2.multi_sig.clear();
	T3.multi_sig.clear();
	T1.signature.clear();
	T2.signature.clear();
	T3.signature.clear();
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
