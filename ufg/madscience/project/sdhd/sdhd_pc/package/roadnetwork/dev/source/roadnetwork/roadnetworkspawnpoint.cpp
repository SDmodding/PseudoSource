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
bool __fastcall UFG::RoadNetworkSpawnPoint::CanSpawnCar(UFG::RoadNetworkSpawnPoint *this)
{
  UFG::RoadNetworkLane *mLane; // rax
  UFG::RoadNetworkSegment *mOffset; // rcx

  if ( this->mSubSegment->mStatus.mValue != 4 )
    return 0;
  mLane = this->mLane;
  mOffset = (UFG::RoadNetworkSegment *)this->mLane->mNode.mOffset;
  if ( mOffset )
    mOffset = (UFG::RoadNetworkSegment *)((char *)mOffset + (_QWORD)mLane);
  return UFG::RoadNetworkSegment::GetRoadDensity(mOffset) != 0.0;
}

// File Line: 117
// RVA: 0xE0FA0
bool __fastcall UFG::RoadNetworkSpawnPoint::Update(UFG::RoadNetworkSpawnPoint *this, float seconds)
{
  float mSpawnTime; // xmm0_4

  mSpawnTime = this->mSpawnTime;
  if ( mSpawnTime >= 0.0 )
    this->mSpawnTime = mSpawnTime - seconds;
  return this->mSpawnTime <= 0.0;
}

// File Line: 124
// RVA: 0xE0020
void __fastcall UFG::RoadNetworkSpawnPoint::Reset(UFG::RoadNetworkSpawnPoint *this)
{
  UFG::RoadNetworkLane *mLane; // rax
  UFG::RoadNetworkSegment *v3; // rdi
  float RoadDensity; // xmm3_4
  float mSpeedLimit; // xmm1_4
  float v6; // xmm0_4

  if ( UFG::TrafficSettings::mOverrideSpawnTime )
  {
    this->mSpawnTime = UFG::TrafficSettings::mSpawnTimeOverride;
  }
  else
  {
    mLane = this->mLane;
    if ( this->mLane )
    {
      if ( mLane->mNode.mOffset )
        v3 = (UFG::RoadNetworkSegment *)((char *)mLane + mLane->mNode.mOffset);
      else
        v3 = 0i64;
      RoadDensity = UFG::RoadNetworkSegment::GetRoadDensity(v3);
      if ( RoadDensity > 0.0 )
      {
        ARandom::c_gen.i_seed = 1664525 * ARandom::c_gen.i_seed + 1013904223;
        mSpeedLimit = v3->mSpeedLimit;
        if ( mSpeedLimit <= 1.0 )
          mSpeedLimit = *(float *)&FLOAT_1_0;
        v6 = 1.0 / (float)(mSpeedLimit * RoadDensity);
        if ( v6 <= UFG::TrafficSettings::mMinSpawnTime )
          v6 = UFG::TrafficSettings::mMinSpawnTime;
        this->mSpawnTime = v6
                         + (float)((float)((float)(COERCE_FLOAT((ARandom::c_gen.i_seed >> 9) | 0x3F800000) - 1.0)
                                         * UFG::TrafficSettings::mSpawnTimeAddMax)
                                 + UFG::TrafficSettings::mSpawnBaseTimeAdd);
      }
      else
      {
        this->mSpawnTime = UFG::TrafficSettings::mDefaultSpawnTime;
      }
    }
    else
    {
      this->mSpawnTime = UFG::TrafficSettings::mDefaultSpawnTime;
    }
  }
}

