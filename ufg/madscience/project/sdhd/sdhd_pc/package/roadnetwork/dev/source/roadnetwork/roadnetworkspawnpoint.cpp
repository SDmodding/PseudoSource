// File Line: 22
// RVA: 0xCFA00
void __fastcall UFG::RoadNetworkSpawnPoint::RoadNetworkSpawnPoint(UFG::RoadNetworkSpawnPoint *this)
{
  this->mLane = 0i64;
  this->mSubSegment = 0i64;
  *(_QWORD *)&this->mSpawnTime = 0i64;
  UFG::RoadNetworkSpawnPoint::Reset(this);
}

// File Line: 83
// RVA: 0xD3140
char __fastcall UFG::RoadNetworkSpawnPoint::CanSpawnCar(UFG::RoadNetworkSpawnPoint *this)
{
  char result; // al
  UFG::RoadNetworkLane *v2; // rax
  UFG::RoadNetworkSegment *v3; // rcx

  if ( this->mSubSegment->mStatus.mValue != 4 )
    goto LABEL_9;
  v2 = this->mLane;
  v3 = (UFG::RoadNetworkSegment *)this->mLane->mNode.mOffset;
  if ( v3 )
    v3 = (UFG::RoadNetworkSegment *)((char *)v3 + (_QWORD)v2);
  if ( UFG::RoadNetworkSegment::GetRoadDensity(v3) == 0.0 )
LABEL_9:
    result = 0;
  else
    result = 1;
  return result;
}

// File Line: 117
// RVA: 0xE0FA0
bool __fastcall UFG::RoadNetworkSpawnPoint::Update(UFG::RoadNetworkSpawnPoint *this, float seconds)
{
  float v2; // xmm0_4

  v2 = this->mSpawnTime;
  if ( v2 >= 0.0 )
    this->mSpawnTime = v2 - seconds;
  return this->mSpawnTime <= 0.0;
}

// File Line: 124
// RVA: 0xE0020
void __fastcall UFG::RoadNetworkSpawnPoint::Reset(UFG::RoadNetworkSpawnPoint *this)
{
  UFG::RoadNetworkSpawnPoint *v1; // rbx
  UFG::RoadNetworkLane *v2; // rax
  UFG::RoadNetworkSegment *v3; // rdi
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm0_4

  v1 = this;
  if ( UFG::TrafficSettings::mOverrideSpawnTime )
  {
    this->mSpawnTime = UFG::TrafficSettings::mSpawnTimeOverride;
  }
  else
  {
    v2 = this->mLane;
    if ( this->mLane )
    {
      if ( v2->mNode.mOffset )
        v3 = (UFG::RoadNetworkSegment *)((char *)v2 + v2->mNode.mOffset);
      else
        v3 = 0i64;
      v4 = UFG::RoadNetworkSegment::GetRoadDensity(v3);
      if ( v4 > 0.0 )
      {
        ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
        v5 = v3->mSpeedLimit;
        if ( v5 <= 1.0 )
          v5 = *(float *)&FLOAT_1_0;
        v6 = 1.0 / (float)(v5 * v4);
        if ( v6 <= UFG::TrafficSettings::mMinSpawnTime )
          v6 = UFG::TrafficSettings::mMinSpawnTime;
        v1->mSpawnTime = v6
                       + (float)((float)((float)(COERCE_FLOAT((ARandom::c_gen.i_seed >> 9) | 0x3F800000) - 1.0)
                                       * UFG::TrafficSettings::mSpawnTimeAddMax)
                               + UFG::TrafficSettings::mSpawnBaseTimeAdd);
      }
      else
      {
        v1->mSpawnTime = UFG::TrafficSettings::mDefaultSpawnTime;
      }
    }
    else
    {
      this->mSpawnTime = UFG::TrafficSettings::mDefaultSpawnTime;
    }
  }
}

