#pragma once

#include <ISetupable.h>

struct IController : public ISetupable
{
  virtual void controlLoop() = 0;
  virtual ~IController() = default;
};
