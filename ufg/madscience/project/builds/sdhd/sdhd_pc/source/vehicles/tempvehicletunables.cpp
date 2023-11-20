// File Line: 14
// RVA: 0x667FD0
void __fastcall UFG::DrivingTargetOffsetMover::DrivingTargetOffsetMover(UFG::DrivingTargetOffsetMover *this)
{
  this->m_AtTarget = 1;
  *(_QWORD *)&this->m_CurrentLateralOffset = 0i64;
  this->m_CurrentDriftSpeed = 0.0;
}

// File Line: 23
// RVA: 0x6908E0
void __fastcall UFG::DrivingTargetOffsetMover::Update(UFG::DrivingTargetOffsetMover *this, float seconds)
{
  float v2; // xmm2_4
  float v3; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4

  if ( !this->m_AtTarget )
  {
    v2 = this->m_CurrentDriftSpeed;
    v3 = this->m_CurrentDriftSpeed * seconds;
    v4 = this->m_DesiredLateralOffset;
    v5 = v3 + this->m_CurrentLateralOffset;
    this->m_CurrentLateralOffset = v5;
    if ( v5 <= v4 )
    {
      if ( v2 <= 0.0 )
      {
LABEL_6:
        this->m_AtTarget = 1;
LABEL_7:
        if ( this->m_AtTarget )
        {
          this->m_CurrentLateralOffset = v4;
          this->m_CurrentDriftSpeed = 0.0;
        }
        return;
      }
      if ( v5 < v4 )
        goto LABEL_7;
    }
    if ( v2 < 0.0 )
      goto LABEL_7;
    goto LABEL_6;
  }
}

// File Line: 49
// RVA: 0x68AA40
void __fastcall UFG::DrivingTargetOffsetMover::SetNewTarget(UFG::DrivingTargetOffsetMover *this, float desiredOffset, float transitonTime)
{
  float v3; // xmm1_4

  this->m_DesiredLateralOffset = desiredOffset;
  v3 = desiredOffset - this->m_CurrentLateralOffset;
  this->m_AtTarget = 0;
  this->m_CurrentDriftSpeed = v3 / transitonTime;
}

// File Line: 81
// RVA: 0x66FFB0
void UFG::BrakingBehavior::AddToTweaker(void)
{
  signed int v0; // ebx
  signed int v1; // edi
  __int64 v2; // ST20_8
  __int64 v3; // ST20_8
  _QWORD v4[2]; // [rsp+20h] [rbp-98h]
  char dest; // [rsp+30h] [rbp-88h]

  v0 = 0;
  v1 = 0;
  do
  {
    LODWORD(v4[0]) = v1;
    UFG::qSPrintf(&dest, "%s%s%d", "\\AI\\Driving\\Misc\\Traffic\\Braking\\Stopping\\", "distance", v4[0]);
    LODWORD(v2) = v1;
    UFG::qSPrintf(&dest, "%s%s%d", "\\AI\\Driving\\Misc\\Traffic\\Braking\\Stopping\\", "speed", v2);
    ++v1;
  }
  while ( v1 < 10 );
  do
  {
    LODWORD(v4[0]) = v0;
    UFG::qSPrintf(&dest, "%s%s%d", "\\AI\\Driving\\Misc\\Traffic\\Braking\\CarGaps\\", "speed", v4[0]);
    LODWORD(v3) = v0;
    UFG::qSPrintf(&dest, "%s%s%d", "\\AI\\Driving\\Misc\\Traffic\\Braking\\CarGaps\\", "distance", v3);
    ++v0;
  }
  while ( v0 < 10 );
}

// File Line: 134
// RVA: 0x670070
void UFG::TrafficCarDebugDrawSettings::AddToTweaker(void)
{
  char dest; // [rsp+20h] [rbp-88h]

  UFG::qSPrintf(&dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\carDebugDraw\\", "laneOffsetMarker");
  UFG::qSPrintf(&dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\carDebugDraw\\", "roadGuide");
  UFG::qSPrintf(&dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\carDebugDraw\\", "carExtents");
  UFG::qSPrintf(&dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\carDebugDraw\\", "controlStick");
  UFG::qSPrintf(&dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\carDebugDraw\\", "navSelector");
}

// File Line: 198
// RVA: 0x670120
void UFG::TrafficSettings::AddToTweaker(void)
{
  char dest; // [rsp+20h] [rbp-88h]

  UFG::qSPrintf(&dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\settings\\", "straight speedLimit");
  UFG::qSPrintf(&dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\settings\\", "slight turn speedLimit");
  UFG::qSPrintf(&dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\settings\\", "major turn speedLimit");
}

