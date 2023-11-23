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
  float m_CurrentDriftSpeed; // xmm2_4
  float v3; // xmm0_4
  float m_DesiredLateralOffset; // xmm1_4
  float v5; // xmm0_4

  if ( !this->m_AtTarget )
  {
    m_CurrentDriftSpeed = this->m_CurrentDriftSpeed;
    v3 = m_CurrentDriftSpeed * seconds;
    m_DesiredLateralOffset = this->m_DesiredLateralOffset;
    v5 = v3 + this->m_CurrentLateralOffset;
    this->m_CurrentLateralOffset = v5;
    if ( v5 <= m_DesiredLateralOffset )
    {
      if ( m_CurrentDriftSpeed <= 0.0 )
      {
LABEL_6:
        this->m_AtTarget = 1;
LABEL_7:
        if ( this->m_AtTarget )
        {
          this->m_CurrentLateralOffset = m_DesiredLateralOffset;
          this->m_CurrentDriftSpeed = 0.0;
        }
        return;
      }
      if ( v5 < m_DesiredLateralOffset )
        goto LABEL_7;
    }
    if ( m_CurrentDriftSpeed < 0.0 )
      goto LABEL_7;
    goto LABEL_6;
  }
}

// File Line: 49
// RVA: 0x68AA40
void __fastcall UFG::DrivingTargetOffsetMover::SetNewTarget(
        UFG::DrivingTargetOffsetMover *this,
        float desiredOffset,
        float transitonTime)
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
  int v0; // ebx
  int i; // edi
  __int64 v2; // [rsp+20h] [rbp-98h]
  __int64 v3; // [rsp+20h] [rbp-98h]
  __int64 v4; // [rsp+20h] [rbp-98h]
  char dest[136]; // [rsp+30h] [rbp-88h] BYREF

  v0 = 0;
  for ( i = 0; i < 10; ++i )
  {
    LODWORD(v2) = i;
    UFG::qSPrintf(dest, "%s%s%d", "\\AI\\Driving\\Misc\\Traffic\\Braking\\Stopping\\", "distance", v2);
    LODWORD(v3) = i;
    UFG::qSPrintf(dest, "%s%s%d", "\\AI\\Driving\\Misc\\Traffic\\Braking\\Stopping\\", "speed", v3);
  }
  do
  {
    LODWORD(v2) = v0;
    UFG::qSPrintf(dest, "%s%s%d", "\\AI\\Driving\\Misc\\Traffic\\Braking\\CarGaps\\", "speed", v2);
    LODWORD(v4) = v0;
    UFG::qSPrintf(dest, "%s%s%d", "\\AI\\Driving\\Misc\\Traffic\\Braking\\CarGaps\\", "distance", v4);
    ++v0;
  }
  while ( v0 < 10 );
}

// File Line: 134
// RVA: 0x670070
void UFG::TrafficCarDebugDrawSettings::AddToTweaker(void)
{
  char dest[136]; // [rsp+20h] [rbp-88h] BYREF

  UFG::qSPrintf(dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\carDebugDraw\\", "laneOffsetMarker");
  UFG::qSPrintf(dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\carDebugDraw\\", "roadGuide");
  UFG::qSPrintf(dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\carDebugDraw\\", "carExtents");
  UFG::qSPrintf(dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\carDebugDraw\\", "controlStick");
  UFG::qSPrintf(dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\carDebugDraw\\", "navSelector");
}

// File Line: 198
// RVA: 0x670120
void UFG::TrafficSettings::AddToTweaker(void)
{
  char dest[136]; // [rsp+20h] [rbp-88h] BYREF

  UFG::qSPrintf(dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\settings\\", "straight speedLimit");
  UFG::qSPrintf(dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\settings\\", "slight turn speedLimit");
  UFG::qSPrintf(dest, "%s%s", "\\AI\\Driving\\Misc\\Traffic\\settings\\", "major turn speedLimit");
}

