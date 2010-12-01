/*
Copyright (C) 2007 <SWGEmu>. All rights reserved.
Distribution of this file for usage outside of Core3 is prohibited.
*/

#include "TransactionalMemoryManager.h"

using namespace engine::stm;

TransactionalMemoryManager::TransactionalMemoryManager() {
	socketManager = new TransactionalSocketManager();
}

Transaction* TransactionalMemoryManager::getTransaction() {
	Transaction* transaction = currentTransaction.get();

	if (transaction == NULL) {
		transaction = new Transaction();

		//transaction->info("created");

		currentTransaction.set(transaction);
	}

	return transaction;
}

void TransactionalMemoryManager::clearTransaction() {
	currentTransaction.set(NULL);
}
