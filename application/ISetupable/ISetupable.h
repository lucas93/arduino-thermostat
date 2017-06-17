#pragma once

struct ISetupable
{
  virtual void setup() = 0;
  virtual ~ISetupable();
};
