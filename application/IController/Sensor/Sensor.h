#pragma once

#include <ISetupable.h>
#include <Utilities.h>

using Temp = f32;

using Sensor = util::unique_function< Temp() >;
