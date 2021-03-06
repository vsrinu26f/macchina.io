//
// LEDServerHelper.cpp
//
// Library: IoT/Devices
// Package: Generated
// Module:  LEDServerHelper
//
// This file has been generated.
// Warning: All changes to this will be lost when the file is re-generated.
//
// Copyright (c) 2014-2015, Applied Informatics Software Engineering GmbH.
// All rights reserved.
// 
// SPDX-License-Identifier: Apache-2.0
//


#include "IoT/Devices/LEDServerHelper.h"
#include "IoT/Devices/LEDSkeleton.h"
#include "Poco/RemotingNG/URIUtility.h"
#include "Poco/SingletonHolder.h"


namespace IoT {
namespace Devices {


namespace
{
	static Poco::SingletonHolder<LEDServerHelper> shLEDServerHelper;
}


LEDServerHelper::LEDServerHelper():
	_pORB(0)
{
	_pORB = &Poco::RemotingNG::ORB::instance();
	_pORB->registerSkeleton("IoT.Devices.LED", new LEDSkeleton);
}


LEDServerHelper::~LEDServerHelper()
{
	try
	{
		_pORB->unregisterSkeleton("IoT.Devices.LED", true);
	}
	catch (...)
	{
		poco_unexpected();
	}
}


std::string LEDServerHelper::registerRemoteObject(Poco::AutoPtr<IoT::Devices::LEDRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return LEDServerHelper::instance().registerObjectImpl(pRemoteObject, listenerId);
}


Poco::AutoPtr<IoT::Devices::LEDRemoteObject> LEDServerHelper::createRemoteObjectImpl(Poco::SharedPtr<IoT::Devices::LED> pServiceObject, const Poco::RemotingNG::Identifiable::ObjectId& oid)
{
	return new LEDRemoteObject(oid, pServiceObject);
}


LEDServerHelper& LEDServerHelper::instance()
{
	return *shLEDServerHelper.get();
}


std::string LEDServerHelper::registerObjectImpl(Poco::AutoPtr<IoT::Devices::LEDRemoteObject> pRemoteObject, const std::string& listenerId)
{
	return _pORB->registerObject(pRemoteObject, listenerId);
}


void LEDServerHelper::unregisterObjectImpl(const std::string& uri)
{
	_pORB->unregisterObject(uri);
}


} // namespace Devices
} // namespace IoT

