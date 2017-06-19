#pragma once

struct IOutput
{
  virtual void setOn() = 0;
  virtual void setOff() = 0;
};
