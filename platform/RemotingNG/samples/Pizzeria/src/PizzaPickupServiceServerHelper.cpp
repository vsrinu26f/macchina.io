//
// PizzaPickupServiceServerHelper.cpp
//
// Package: Generated
// Module:  PizzaPickupServiceServerHelper
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2006-2016, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#include "Pizzeria/PizzaPickupServiceServerHelper.h"
#include "Pizzeria/PizzaPickupServiceSkeleton.h"
#include "Poco/RemotingNG/URIUtility.h"
#include "Poco/SingletonHolder.h"


namespace Pizzeria {


namespace
{
	static Poco::SingletonHolder<PizzaPickupServiceServerHelper> shPizzaPickupServiceServerHelper;
}


PizzaPickupServiceServerHelper::PizzaPickupServiceServerHelper():
	_pORB(0)
{
	_pORB = &Poco::RemotingNG::ORB::instance();
	_pORB->registerSkeleton("Pizzeria.PizzaPickupService", new PizzaPickupServiceSkeleton);
}


PizzaPickupServiceServerHelper::~PizzaPickupServiceServerHelper()
{
	try
	{
		_pORB->unregisterSkeleton("Pizzeria.PizzaPickupService", true);
	}
	catch (...)
	{
		poco_unexpected();
	}
}


std::string PizzaPickupServiceServerHelper::registerRemoteObject(Poco::AutoPtr<Pizzeria::PizzaPickupServiceRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return PizzaPickupServiceServerHelper::instance().registerObjectImpl(pRemoteObject, listenerId);
}


Poco::AutoPtr<Pizzeria::PizzaPickupServiceRemoteObject> PizzaPickupServiceServerHelper::createRemoteObjectImpl(Poco::SharedPtr<Pizzeria::PizzaPickupService> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
{
	return new PizzaPickupServiceRemoteObject(oid, pServiceObject);
}


PizzaPickupServiceServerHelper& PizzaPickupServiceServerHelper::instance()
{
	return *shPizzaPickupServiceServerHelper.get();
}


std::string PizzaPickupServiceServerHelper::registerObjectImpl(Poco::AutoPtr<Pizzeria::PizzaPickupServiceRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return _pORB->registerObject(pRemoteObject, listenerId);
}


void PizzaPickupServiceServerHelper::unregisterObjectImpl(const std::string& uri)
{
	_pORB->unregisterObject(uri);
}


} // namespace Pizzeria

