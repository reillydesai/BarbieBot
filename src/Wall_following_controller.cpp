#include <Romi32U4.h>
#include "Encoders.h"
#include "Wall_following_controller.h"
#include "IR_sensor.h"
#include "Median_filter.h"

IRsensor SharpIR;
MedianFilter filter;

void WallFollowingController::Init(void)
{
  SharpIR.Init();
}

void WallFollowingController::Reset(void)
{
  filter.Init(SharpIR.ReadData());
}

float WallFollowingController::Process(float target_distance)
{
  float speed;
  E_distance = filter.GetMedian(SharpIR.ReadData()) - target_distance;
  float de = E_distance - prev_e_distance;
  speed = Kp * E_distance + Kd * de;
  prev_e_distance = E_distance;
  return speed;
}

bool WallFollowingController::SpikeDetected(void)
{
  if (filter.GetMedian() >= spike_threshold) return true;
  else return false;
}