#pragma once
#include <IOutput.h>
#include <Utilities.h>

namespace heater
{

unique_ptr<IOutput> getDefaultRelayInstance();

} //namespace heater
