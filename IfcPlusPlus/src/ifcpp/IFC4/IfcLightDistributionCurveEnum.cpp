/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPException.h"
#include "include/IfcLightDistributionCurveEnum.h"

// TYPE IfcLightDistributionCurveEnum = ENUMERATION OF	(TYPE_A	,TYPE_B	,TYPE_C	,NOTDEFINED);
IfcLightDistributionCurveEnum::IfcLightDistributionCurveEnum() {}
IfcLightDistributionCurveEnum::~IfcLightDistributionCurveEnum() {}
shared_ptr<IfcPPObject> IfcLightDistributionCurveEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcLightDistributionCurveEnum> copy_self( new IfcLightDistributionCurveEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcLightDistributionCurveEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCLIGHTDISTRIBUTIONCURVEENUM("; }
	if( m_enum == ENUM_TYPE_A )
	{
		stream << ".TYPE_A.";
	}
	else if( m_enum == ENUM_TYPE_B )
	{
		stream << ".TYPE_B.";
	}
	else if( m_enum == ENUM_TYPE_C )
	{
		stream << ".TYPE_C.";
	}
	else if( m_enum == ENUM_NOTDEFINED )
	{
		stream << ".NOTDEFINED.";
	}
	if( is_select_type ) { stream << ")"; }
}
shared_ptr<IfcLightDistributionCurveEnum> IfcLightDistributionCurveEnum::createObjectFromSTEP( const std::wstring& arg )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcLightDistributionCurveEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcLightDistributionCurveEnum>(); }
	shared_ptr<IfcLightDistributionCurveEnum> type_object( new IfcLightDistributionCurveEnum() );
	if( boost::iequals( arg, L".TYPE_A." ) )
	{
		type_object->m_enum = IfcLightDistributionCurveEnum::ENUM_TYPE_A;
	}
	else if( boost::iequals( arg, L".TYPE_B." ) )
	{
		type_object->m_enum = IfcLightDistributionCurveEnum::ENUM_TYPE_B;
	}
	else if( boost::iequals( arg, L".TYPE_C." ) )
	{
		type_object->m_enum = IfcLightDistributionCurveEnum::ENUM_TYPE_C;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcLightDistributionCurveEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}
