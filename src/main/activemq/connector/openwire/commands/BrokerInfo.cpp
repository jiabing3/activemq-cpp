/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <activemq/connector/openwire/commands/BrokerInfo.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshaling code for OpenWire format for BrokerInfo
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
BrokerInfo::BrokerInfo()
{
    this->brokerId = NULL;
    this->brokerURL = "";
    this->brokerName = "";
    this->slaveBroker = false;
    this->masterBroker = false;
    this->faultTolerantConfiguration = false;
    this->duplexConnection = false;
    this->networkConnection = false;
    this->connectionId = 0;
}

////////////////////////////////////////////////////////////////////////////////
BrokerInfo::~BrokerInfo()
{
    delete this->brokerId;
    for( size_t ipeerBrokerInfos = 0; ipeerBrokerInfos < peerBrokerInfos.size(); ++ipeerBrokerInfos ) {
        delete peerBrokerInfos[ipeerBrokerInfos];
    }
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* BrokerInfo::cloneDataStructure() const {
    BrokerInfo* brokerInfo = new BrokerInfo();

    // Copy the data from the base class or classes
    brokerInfo->copyDataStructure( this );

    return brokerInfo;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand<transport::Command>::copyDataStructure( src );

    const BrokerInfo* srcPtr = dynamic_cast<const BrokerInfo*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "BrokerInfo::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getBrokerId() != NULL ) {
        this->setBrokerId( 
            dynamic_cast<BrokerId*>( 
                srcPtr->getBrokerId()->cloneDataStructure() ) );
    }
    this->setBrokerURL( srcPtr->getBrokerURL() );
    for( size_t ipeerBrokerInfos = 0; ipeerBrokerInfos < srcPtr->getPeerBrokerInfos().size(); ++ipeerBrokerInfos ) {
        if( srcPtr->getPeerBrokerInfos()[ipeerBrokerInfos] != NULL ) {
            this->getPeerBrokerInfos().push_back( 
                dynamic_cast<BrokerInfo*>( 
                    srcPtr->getPeerBrokerInfos()[ipeerBrokerInfos]->cloneDataStructure() ) );
        } else {
            this->getPeerBrokerInfos().push_back( NULL );
        }
    }
    this->setBrokerName( srcPtr->getBrokerName() );
    this->setSlaveBroker( srcPtr->isSlaveBroker() );
    this->setMasterBroker( srcPtr->isMasterBroker() );
    this->setFaultTolerantConfiguration( srcPtr->isFaultTolerantConfiguration() );
    this->setDuplexConnection( srcPtr->isDuplexConnection() );
    this->setNetworkConnection( srcPtr->isNetworkConnection() );
    this->setConnectionId( srcPtr->getConnectionId() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char BrokerInfo::getDataStructureType() const {
    return BrokerInfo::ID_BROKERINFO; 
}

////////////////////////////////////////////////////////////////////////////////
std::string BrokerInfo::toString() const {

    ostringstream stream;

    stream << "Begin Class = BrokerInfo" << std::endl;
    stream << " Value of BrokerInfo::ID_BROKERINFO = 2" << std::endl; 
    stream << " Value of BrokerId is Below:" << std::endl;
    if( this->getBrokerId() != NULL ) {
        stream << this->getBrokerId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    stream << " Value of BrokerURL = " << this->getBrokerURL() << std::endl;
    for( size_t ipeerBrokerInfos = 0; ipeerBrokerInfos < this->getPeerBrokerInfos().size(); ++ipeerBrokerInfos ) {
        stream << " Value of PeerBrokerInfos[" << ipeerBrokerInfos << "] is Below:" << std::endl;
        if( this->getPeerBrokerInfos()[ipeerBrokerInfos] != NULL ) {
            stream << this->getPeerBrokerInfos()[ipeerBrokerInfos]->toString() << std::endl;
        } else {
            stream << "   Object is NULL" << std::endl;
        }
    }
    stream << " Value of BrokerName = " << this->getBrokerName() << std::endl;
    stream << " Value of SlaveBroker = " << this->isSlaveBroker() << std::endl;
    stream << " Value of MasterBroker = " << this->isMasterBroker() << std::endl;
    stream << " Value of FaultTolerantConfiguration = " << this->isFaultTolerantConfiguration() << std::endl;
    stream << " Value of DuplexConnection = " << this->isDuplexConnection() << std::endl;
    stream << " Value of NetworkConnection = " << this->isNetworkConnection() << std::endl;
    stream << " Value of ConnectionId = " << this->getConnectionId() << std::endl;
    // Copy the data of the base class or classes
    stream << BaseCommand<transport::Command>::toString();
    stream << "End Class = BrokerInfo" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::equals( const DataStructure* value ) const {
    const BrokerInfo* valuePtr = dynamic_cast<const BrokerInfo*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
const BrokerId* BrokerInfo::getBrokerId() const {
    return brokerId;
}

////////////////////////////////////////////////////////////////////////////////
BrokerId* BrokerInfo::getBrokerId() {
    return brokerId;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setBrokerId(BrokerId* brokerId ) {
    this->brokerId = brokerId;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& BrokerInfo::getBrokerURL() const {
    return brokerURL;
}

////////////////////////////////////////////////////////////////////////////////
std::string& BrokerInfo::getBrokerURL() {
    return brokerURL;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setBrokerURL(const std::string& brokerURL ) {
    this->brokerURL = brokerURL;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<BrokerInfo*>& BrokerInfo::getPeerBrokerInfos() const {
    return peerBrokerInfos;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<BrokerInfo*>& BrokerInfo::getPeerBrokerInfos() {
    return peerBrokerInfos;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setPeerBrokerInfos(const std::vector<BrokerInfo*>& peerBrokerInfos ) {
    this->peerBrokerInfos = peerBrokerInfos;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& BrokerInfo::getBrokerName() const {
    return brokerName;
}

////////////////////////////////////////////////////////////////////////////////
std::string& BrokerInfo::getBrokerName() {
    return brokerName;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setBrokerName(const std::string& brokerName ) {
    this->brokerName = brokerName;
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::isSlaveBroker() const {
    return slaveBroker;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setSlaveBroker(bool slaveBroker ) {
    this->slaveBroker = slaveBroker;
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::isMasterBroker() const {
    return masterBroker;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setMasterBroker(bool masterBroker ) {
    this->masterBroker = masterBroker;
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::isFaultTolerantConfiguration() const {
    return faultTolerantConfiguration;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setFaultTolerantConfiguration(bool faultTolerantConfiguration ) {
    this->faultTolerantConfiguration = faultTolerantConfiguration;
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::isDuplexConnection() const {
    return duplexConnection;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setDuplexConnection(bool duplexConnection ) {
    this->duplexConnection = duplexConnection;
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::isNetworkConnection() const {
    return networkConnection;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setNetworkConnection(bool networkConnection ) {
    this->networkConnection = networkConnection;
}

////////////////////////////////////////////////////////////////////////////////
long long BrokerInfo::getConnectionId() const {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setConnectionId(long long connectionId ) {
    this->connectionId = connectionId;
}

