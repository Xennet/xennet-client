//============================================================================
// Name        : zennet_contract.h
// Author      : zennet R\D
// Version     : 0
// Copyright   : zennet contract header file
// Description : zennet contract code
//============================================================================

#ifndef CONTRACT_H_
#define CONTRACT_H_

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

typedef string pubkey_t;
// resource_t is the resource name,at the provider,type declaration
typedef string resource_t;
// score_t is the resource score,at the provider,type declaration
typedef double score_t;
// 	TO DO
typedef string vm_feature_t;
// 	TO DO
typedef string	spec_t_string;
// 	TO DO (and check declaration)
typedef string coins_t;
// 	TO DO
typedef string sig_t;

// contract_t class is the zennet contract class template declaration
//template <class B_Type>
class contract_t
{
public:
//	TO DO(functions,etc)
	int set_pubkey (pubkey_t provider_pubkey,pubkey_t publisher_pubkey,int which_pubkey);
	pubkey_t get_pubkey (int which_pubkey);
	contract_t();
	contract_t(pubkey_t initial_provider_pubkey,pubkey_t initial_publisher_pubkey);

private:
//  the class member "publisher" is a string public key
//	which is related to the provider
	pubkey_t provider;

//  the class member "publisher" is a string public key
//	which is related to the publisher
	pubkey_t publisher;

//  the class member "rates" is a STL object for procfs measurements
//	vector produced by the B.M processes data according to
//	Zennet pricing algorithm
//  rates, resource_t string argument is for the procfs resource name
//	rates, score_t double argument is for the procfs resource value
	map<const resource_t,score_t> rates;

//	the class member "spec_t" is the specification STL object
	map<const vm_feature_t,spec_t_string > spec_t;

//	the class member "contract_sig" is the contract signature
//  string declaration
	sig_t contract_sig;
};

bool negotiate(contract_t provider_contract,contract_t publisher_contract);


#endif /* CONTRACT_H_ */

