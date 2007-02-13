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
#include <activemq/connector/openwire/commands/RemoveInfo.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshaling code for OpenWire format for RemoveInfo
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
RemoveInfo::RemoveInfo()
{
    this->objectId = NULL;
}

////////////////////////////////////////////////////////////////////////////////
RemoveInfo::~RemoveInfo()
{
    delete this->objectId;
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* RemoveInfo::cloneDataStructure() const {
    RemoveInfo* removeInfo = new RemoveInfo();

    // Copy the data from the base class or classes
    removeInfo->copyDataStructure( this );

    return removeInfo;
}

////////////////////////////////////////////////////////////////////////////////
void RemoveInfo::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand<transport::Command>::copyDataStructure( src );

    const RemoveInfo* srcPtr = dynamic_cast<const RemoveInfo*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "RemoveInfo::copyDataStructure - src is NULL or invalid" );
    }
    if( srcPtr->getObjectId() != NULL ) {
        this->setObjectId( 
            dynamic_cast<DataStructure*>( 
                srcPtr->getObjectId()->cloneDataStructure() ) );
    }
}

////////////////////////////////////////////////////////////////////////////////
unsigned char RemoveInfo::getDataStructureType() const {
    return RemoveInfo::ID_REMOVEINFO; 
}

////////////////////////////////////////////////////////////////////////////////
std::string RemoveInfo::toString() const {

    ostringstream stream;

    stream << "Begin Class = RemoveInfo" << std::endl;
    stream << " Value of RemoveInfo::ID_REMOVEINFO = 12" << std::endl; 
    stream << " Value of ObjectId is Below:" << std::endl;
    if( this->getObjectId() != NULL ) {
        stream << this->getObjectId()->toString() << std::endl;
    } else {
        stream << "   Object is NULL" << std::endl;
    }
    // Copy the data of the base class or classes
    stream << BaseCommand<transport::Command>::toString();
    stream << "End Class = RemoveInfo" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool RemoveInfo::equals( const DataStructure* value ) const {
    const RemoveInfo* valuePtr = dynamic_cast<const RemoveInfo*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
const DataStructure* RemoveInfo::getObjectId() const {
    return objectId;
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* RemoveInfo::getObjectId() {
    return objectId;
}

////////////////////////////////////////////////////////////////////////////////
void RemoveInfo::setObjectId(DataStructure* objectId ) {
    this->objectId = objectId;
}

