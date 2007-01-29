/**
 *
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
package org.apache.activemq.openwire.tool;

import java.io.PrintWriter;
import java.util.Iterator;
import java.util.List;

import org.codehaus.jam.JClass;
import org.codehaus.jam.JProperty;


/**
 *
 * @version $Revision: 379734 $
 */
public class AmqCppHeadersGenerator extends AmqCppClassesGenerator {

    protected String getFilePostFix() {
        return ".h";
    }
    
	protected void generateFile(PrintWriter out) {
		generateLicence(out);		

out.println("");
out.println("#ifndef _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_"+className.toUpperCase()+"_H_");
out.println("#define _ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_"+className.toUpperCase()+"_H_");
out.println("");
out.println("// Turn off warning message for ignored exception specification");
out.println("#ifdef _MSC_VER");
out.println("#pragma warning( disable : 4290 )");
out.println("#endif");
out.println("");
out.println("#include <activemq/connector/openwire/commands/"+baseClass+".h>");

List properties = getProperties();
for (Iterator iter = properties.iterator(); iter.hasNext();) {
    JProperty property = (JProperty) iter.next();
    if( !property.getType().isPrimitiveType() &&
        !property.getType().getSimpleName().equals("String") &&
        !property.getType().getSimpleName().equals("ByteSequence") )
    {
        String includeName = toCppType(property.getType());
        if( property.getType().isArrayType() )
        {
            JClass arrayType = property.getType().getArrayComponentType();
            if( arrayType.isPrimitiveType() )
                continue;
        }
        if( includeName.startsWith("std::vector") ) {
            includeName = includeName.substring(12, includeName.length()-2);
        }

        out.println("#include <activemq/connector/openwire/commands/"+includeName+".h>");
    }
}

out.println("#include <vector>");
out.println("#include <string>");
out.println("");
out.println("namespace activemq{");
out.println("namespace connector{");
out.println("namespace openwire{");
out.println("namespace commands{");
out.println("");
out.println("    /*");
out.println("     *");
out.println("     *  Command and marshalling code for OpenWire format for ${className}");
out.println("     *");
out.println("     *");
out.println("     *  NOTE!: This file is autogenerated - do not modify!");
out.println("     *         if you need to make a change, please see the Java Classes");
out.println("     *         in the activemq-openwire-generator module");
out.println("     *");
out.println("     */");
out.println("    class "+className+" : public "+baseClass);
out.println("    {");
out.println("    protected:");
out.println("");

       for (Iterator iter = properties.iterator(); iter.hasNext();) {
            JProperty property = (JProperty) iter.next();
            String type = toCppType(property.getType());
            String name = decapitalize(property.getSimpleName());

            if( !property.getType().isPrimitiveType() &&
                !property.getType().getSimpleName().equals("ByteSequence") && 
                !property.getType().getSimpleName().equals("String") &&
                !type.startsWith("std::vector") ) {
                   
                type = type + "*";
            }
            
            out.println("        "+type+" "+name+";");

       }
    
        String typeName = className.toUpperCase();
    
out.println("");
out.println("    public:");
out.println("");    
out.println("        const static unsigned char ID_"+typeName+" = "+getOpenWireOpCode(jclass)+";");
out.println("");    
out.println("    public:");
out.println("");    
out.println("        "+className+"();");
out.println("        virtual ~"+className+"();");
out.println("");    
out.println("        /**");
out.println("         * Get the unique identifier that this object and its own");      
out.println("         * Marshaller share.");
out.println("         * @returns new DataStructure type copy.");
out.println("         */");
out.println("        virtual unsigned char getDataStructureType() const;");
out.println("");
out.println("        /**");
out.println("         * Clone this object and return a new instance that the");      
out.println("         * caller now owns, this will be an exact copy of this one");
out.println("         * @returns new copy of this object.");
out.println("         */");
out.println("        virtual DataStructure* cloneDataStructure() const;");
out.println("");
out.println("        /**");
out.println("         * Copy the contents of the passed object into this objects");
out.println("         * members, overwriting any existing data.");
out.println("         * @return src - Source Object");
out.println("         */");
out.println("        virtual void copyDataStructure( const DataStructure* src );");
out.println("");

        for( Iterator iter = properties.iterator(); iter.hasNext(); ) {
            JProperty property = (JProperty) iter.next();
            String type = toCppType(property.getType());
            String propertyName = property.getSimpleName();
            String parameterName = decapitalize(propertyName);
            String constness = "";

            if( !property.getType().isPrimitiveType() &&
                !property.getType().getSimpleName().equals("ByteSequence") && 
                !property.getType().getSimpleName().equals("String") &&
                !type.startsWith("std::vector") ) {
                    
                    type = type + "*";
            } else if( property.getType().getSimpleName().equals("String") ||
            		   type.startsWith("std::vector") ) {

            	type = type + "&";
                constness = "const ";
            }
            
            out.println("        virtual const "+type+" "+property.getGetter().getSimpleName()+"() const;");
            out.println("        virtual "+type+" "+property.getGetter().getSimpleName()+"();");
            out.println("        virtual void "+property.getSetter().getSimpleName()+"( "+constness+type+" "+parameterName+" );");
            out.println("");
        }

out.println("    };");
out.println("");
out.println("}}}}");
out.println("");
out.println("#endif /*_ACTIVEMQ_CONNECTOR_OPENWIRE_COMMANDS_"+className.toUpperCase()+"_H_*/");
out.println("");

    }    

}
