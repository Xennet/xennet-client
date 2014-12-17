//============================================================================
// Name        : zennet_contract.cpp
// Author      : zennet
// Version     :
// Copyright   : zennet contract
// Description : zennet contract code
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include "contractRavit.h"
using namespace std;

/*
// pubkey_t is the public key related to the provider\publisher
// type declaration
typedef std::string pubkey_t;
// resource_t is the resource name,at the provider,type declaration
typedef std::string resource_t;
// score_t is the resource score,at the provider,type declaration
typedef double score_t;
// .................need to add about vm_feature_t........
typedef std::string vm_feature_t;
//.................need to add about  spec_t_string.........
typedef std::string	spec_t_string;
//........need to add about coins_t and check declaration
typedef std::string coins_t;
//
typedef std::string sig_t;



// 	tx_t class template is for the "logical deposit box" class
//	declaration in the micropayment protocol
template <class A_Type> class tx_t
{
//	inputs_vector is the inputs vector...need to add about
	vector<pubkey_t> inputs_vector;
//  output_object is the output STL object...need to add about
	map<pubkey_t,coins_t> output_object;
//	deposit_sig member is the deposit signature string declaration
	sig_t deposit_sig;
};
*/


/*
// contract_t class is the zennet contract class template declaration
template <class A_Type> class contract_t
{
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

};

*/

int main(int argc, char** argv)
{
	cout << "zennet contract" << endl; // prints zennet contract
	return 0;
}
