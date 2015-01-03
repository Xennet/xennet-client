//============================================================================
// Name        : publisher_flow.h
// Author      : zennet R\D
// Version     : 0
// Copyright   : zennet publisher_flow header file
// Description : zennet publisher_flow code
//============================================================================


#ifndef PUBLISHER_FLOW_H_
#define PUBLISHER_FLOW_H_


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "contract.h"
#include "publisher_micro_payment.h"
using namespace std;


int publisher_flow();

contract_t receive_contract();
//	negotiate_contract function offerers a substitute contract by publisher
contract_t negotiate_contract();
//	compare_contract compares between negotiated contracts
bool compare_contract(contract_t provider_contract,contract_t publisher_contract);









#endif /* PUBLISHER_FLOW_H_ */
