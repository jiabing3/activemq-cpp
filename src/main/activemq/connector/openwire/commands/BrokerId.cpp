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
#include <activemq/connector/openwire/commands/BrokerId.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshaling code for OpenWire format for BrokerId
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
BrokerId::BrokerId()
{
    this->value = "";
}

////////////////////////////////////////////////////////////////////////////////
BrokerId::~BrokerId()
{
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* BrokerId::cloneDataStructure() const {
    BrokerId* brokerId = new BrokerId();

    // Copy the data from the base class or classes
    brokerId->copyDataStructure( this );

    return brokerId;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerId::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseDataStructure::copyDataStructure( src );

    const BrokerId* srcPtr = dynamic_cast<const BrokerId*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "BrokerId::copyDataStructure - src is NULL or invalid" );
    }
    this->setValue( srcPtr->getValue() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char BrokerId::getDataStructureType() const {
    return BrokerId::ID_BROKERID; 
}

////////////////////////////////////////////////////////////////////////////////
std::string BrokerId::toString() const {

    ostringstream stream;

    stream << "Begin Class = BrokerId" << std::endl;
    stream << " Value of BrokerId::ID_BROKERID = 124" << std::endl; 
    stream << " Value of Value = " << this->getValue() << std::endl;
    // Copy the data of the base class or classes
    stream << BaseDataStructure::toString();
    stream << "End Class = BrokerId" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerId::equals( const DataStructure* value ) const {
    const BrokerId* valuePtr = dynamic_cast<const BrokerId*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& BrokerId::getValue() const {
    return value;
}

////////////////////////////////////////////////////////////////////////////////
std::string& BrokerId::getValue() {
    return value;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerId::setValue(const std::string& value ) {
    this->value = value;
}

