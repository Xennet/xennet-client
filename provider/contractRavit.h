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

// The pubkey_t is the public key provided by the provider or publisher to store at .sshfolder in the VM user's home
typedef std::string pubkey_t;
// resource_t is the resource name,at the provider,type declaration
typedef std::string resource_t;
// score_t is the resource score,at the provider,type declaration
typedef std::string score_t;
// 	The feature_t is the features supporting by a CPU machine (souch as: SEE2...)
typedef std::string vm_feature_t;
// 	The spec_t_string is The VM Specification (CPUs, RAM etc.)
//  Each spec contains:
// 	i. VM specs
// 	ii. Rates per Resource
// 	iii. Canonical Scores
// 	iv. The user should have the ability to automatically generate default
// 		values for the above three.
typedef std::string	spec_t_string;
// The coins_t is the amounts of coins needed for the rate
typedef std::string coins_t;
// The sig_t is the multisig address requiring both Publisher and Provider signatures
typedef std::string sig_t;


// 	tx_t class is for the "logical deposit box" class
//	declaration in the micropayment protocol
class tx_t
{
public:
// 	TO DO(functions,etc)

private:
//	TO DO
	vector<pubkey_t> inputs_vector;
//  TO DO
	map<pubkey_t,coins_t> output_object;
//	deposit_sig member is the deposit signature string declaration
	sig_t deposit_sig;
};

// contract_t class is the zennet contract class template declaration
//template <class B_Type>
class contract_t
{
public:
	// function set_pubkey () will checks validation of the given keys and then set the pubkeys value
	// by calling the class private functions set_publisher_pubkey() and set_provider_pubkey() 
	// function will return 1 if pubkeys were sets and return 0 if not
	bool set_pubkey (pubkey_t provider_pubkey,pubkey_t publisher_pubkey);

	// TODO
	//int compare_pubkey (pubkey_t provider_pubkey,pubkey_t publisher_pubkey);

	// function get_publisher_pubkey () will retrives the publisher public key
	pubkey_t get_publisher_pubkey ();

	// function get_provider_pubkey () will retrives the provider public key
	pubkey_t get_provider_pubkey ();

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
	map<resource_t,score_t> rates;

//	the class member "spec_t" is the specification STL object
	map<vm_feature_t,spec_t_string > spec_t;

//	the class member "tx_contract" is the Zennet contract deposit object
//  which is declared by the tx_t class template for the micropayment
//	protocol purposes
	tx_t tx_contract;

//	the class member "contract_sig" is the contract signature
//  string declaration
	sig_t contract_sig;

	// function set_publisher_pubkey () will set the publisher public key value
	void set_publisher_pubkey (pubkey_t publisher_pubkey);
	// function set_provider_pubkey () will set the provider public key value
	void set_provider_pubkey (pubkey_t provider_pubkey);
};

#endif /* CONTRACT_H_ */
