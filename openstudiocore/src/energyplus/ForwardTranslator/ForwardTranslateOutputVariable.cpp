/**********************************************************************
 *  Copyright (c) 2008-2014, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include "../ForwardTranslator.hpp"

#include "../../model/Model.hpp"
#include "../../model/OutputVariable.hpp"
#include "../../model/OutputVariable_Impl.hpp"
#include "../../model/Schedule.hpp"
#include "../../model/Schedule_Impl.hpp"

#include <utilities/idd/Output_Variable_FieldEnums.hxx>
#include <utilities/idd/IddEnums.hxx>

using namespace openstudio::model;

using namespace std;

namespace openstudio {

namespace energyplus {

boost::optional<IdfObject> ForwardTranslator::translateOutputVariable( OutputVariable & modelObject )
{
  IdfObject idfObject( openstudio::IddObjectType::Output_Variable);
  m_idfObjects.push_back(idfObject);

  if (!modelObject.isKeyValueDefaulted()){
    idfObject.setString(Output_VariableFields::KeyValue, modelObject.keyValue());
  }

  idfObject.setString(Output_VariableFields::VariableName, modelObject.variableName());

  if (!modelObject.isReportingFrequencyDefaulted()){
    idfObject.setString(Output_VariableFields::ReportingFrequency, modelObject.reportingFrequency());
  }
 
  if (modelObject.schedule()){
    idfObject.setString(Output_VariableFields::ScheduleName, modelObject.schedule()->name().get());
  }

  return idfObject;
}

} // energyplus

} // openstudio

