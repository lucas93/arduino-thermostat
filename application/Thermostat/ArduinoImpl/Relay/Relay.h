#pragma once
#include <IOutput.h>
#include <Utilities.h>

namespace heater
{

owner<IOutput> getDefaultRelayInstance();

} //namespace heater
