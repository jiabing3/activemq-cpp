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
#include <activemq/connector/openwire/commands/ReplayCommand.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshaling code for OpenWire format for ReplayCommand
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
ReplayCommand::ReplayCommand()
{
    this->firstNakNumber = 0;
    this->lastNakNumber = 0;
}

////////////////////////////////////////////////////////////////////////////////
ReplayCommand::~ReplayCommand()
{
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* ReplayCommand::cloneDataStructure() const {
    ReplayCommand* replayCommand = new ReplayCommand();

    // Copy the data from the base class or classes
    replayCommand->copyDataStructure( this );

    return replayCommand;
}

////////////////////////////////////////////////////////////////////////////////
void ReplayCommand::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand<transport::Command>::copyDataStructure( src );

    const ReplayCommand* srcPtr = dynamic_cast<const ReplayCommand*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "ReplayCommand::copyDataStructure - src is NULL or invalid" );
    }
    this->setFirstNakNumber( srcPtr->getFirstNakNumber() );
    this->setLastNakNumber( srcPtr->getLastNakNumber() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char ReplayCommand::getDataStructureType() const {
    return ReplayCommand::ID_REPLAYCOMMAND; 
}

////////////////////////////////////////////////////////////////////////////////
std::string ReplayCommand::toString() const {

    ostringstream stream;

    stream << "Begin Class = ReplayCommand" << std::endl;
    stream << " Value of ReplayCommand::ID_REPLAYCOMMAND = 65" << std::endl; 
    stream << " Value of FirstNakNumber = " << this->getFirstNakNumber() << std::endl;
    stream << " Value of LastNakNumber = " << this->getLastNakNumber() << std::endl;
    // Copy the data of the base class or classes
    stream << BaseCommand<transport::Command>::toString();
    stream << "End Class = ReplayCommand" << std::endl;

    return stream.str();
}

////////////////////////////////////////////////////////////////////////////////
bool ReplayCommand::equals( const DataStructure* value ) const {
    const ReplayCommand* valuePtr = dynamic_cast<const ReplayCommand*>( value );

    if( valuePtr == NULL || value == NULL ) {
        return false;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////
int ReplayCommand::getFirstNakNumber() const {
    return firstNakNumber;
}

////////////////////////////////////////////////////////////////////////////////
void ReplayCommand::setFirstNakNumber(int firstNakNumber ) {
    this->firstNakNumber = firstNakNumber;
}

////////////////////////////////////////////////////////////////////////////////
int ReplayCommand::getLastNakNumber() const {
    return lastNakNumber;
}

////////////////////////////////////////////////////////////////////////////////
void ReplayCommand::setLastNakNumber(int lastNakNumber ) {
    this->lastNakNumber = lastNakNumber;
}

