// File Line: 96
// RVA: 0x14686F0
__int64 dynamic_initializer_for__UFG::Metrics::msInstance__()
{
  UFG::qNode<UFG::qString,UFG::qString> *v0; // rax

  UFG::Metrics::msInstance.mSimTimeMSec = 0i64;
  UFG::Metrics::msInstance.mSimTimeTicks.mTicks = 0;
  UFG::Metrics::msInstance.mSimTime = 0.0;
  *(_QWORD *)&UFG::Metrics::msInstance.mSimTime_Temp = 0i64;
  UFG::Metrics::msInstance.mSimFrameCount = 0;
  UFG::Metrics::msInstance.mSimTimeScaleInGame = 1.0;
  UFG::Metrics::msInstance.mSimPausedInGame = 0;
  UFG::Metrics::msInstance.mSimTimeScaleDebug = 1.0;
  UFG::Metrics::msInstance.mSimPausedDebug = 0;
  UFG::Metrics::msInstance.mSimTimeDeltaMax = Metrics_sim_time_delta_max_def_19;
  UFG::Metrics::msInstance.mSimTimeDeltaLocked = FLOAT_N1_0;
  *(_OWORD *)&UFG::Metrics::msInstance.mSimTimeDeltaStep = _xmm;
  if ( !(_S2_6 & 1) )
  {
    _S2_6 |= 1u;
    stru_14235C4C0.mPrev = &stru_14235C4C0;
    stru_14235C4C0.mNext = &stru_14235C4C0;
    atexit(UFG::Metrics::GetUpdatingList_::_2_::_dynamic_atexit_destructor_for__sUpdateList__);
  }
  v0 = stru_14235C4C0.mPrev;
  stru_14235C4C0.mPrev->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::Metrics::msInstance;
  UFG::Metrics::msInstance.mPrev = (UFG::qNode<UFG::Metrics,UFG::Metrics> *)v0;
  UFG::Metrics::msInstance.mNext = (UFG::qNode<UFG::Metrics,UFG::Metrics> *)&stru_14235C4C0;
  stru_14235C4C0.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::Metrics::msInstance;
  return atexit(dynamic_atexit_destructor_for__UFG::Metrics::msInstance__);
}

// File Line: 167
// RVA: 0x191830
void __fastcall UFG::Metrics::Update(UFG::Metrics *this)
{
  UFG::Metrics *v1; // r8
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  signed __int64 v6; // rdx
  long double v7; // xmm1_8
  float v8; // xmm0_4
  double v9; // xmm1_8
  unsigned __int64 v10; // rcx
  float v11; // xmm2_4
  signed __int64 v12; // rdx
  long double v13; // xmm1_8
  float v14; // xmm0_4
  double v15; // xmm1_8
  unsigned __int64 v16; // rcx

  v1 = this;
  if ( this->mSimPausedInGame
    || this->mSimPausedDebug
    || (v2 = this->mSimTimeScaleDebug * this->mSimTimeScaleInGame, v2 <= 0.0) )
  {
    v11 = this->mSimTimeDeltaStep;
    if ( v11 > 0.0 )
    {
      v12 = 0i64;
      this->mSimTimeDelta = v11;
      v13 = v11 + this->mSimTime;
      this->mSimTimeUnscaledDelta = v11;
      v14 = v13;
      this->mSimTime = v13;
      v15 = v13 * 1000.0;
      this->mSimTime_Temp = v14;
      if ( v15 >= 9.223372036854776e18 )
      {
        v15 = v15 - 9.223372036854776e18;
        if ( v15 < 9.223372036854776e18 )
          v12 = 0x8000000000000000i64;
      }
      v16 = v12 + (unsigned int)(signed int)v15;
      v1->mSimTimeMSec = v16;
      v1->mSimTimeTicks.mTicks = (unsigned __int64)((v16 + 60) * (unsigned __int128)0x8888888888888889ui64 >> 64) >> 6;
      ++v1->mSimFrameCount;
      v1->mSimTimeDeltaStep = 0.0;
    }
    else
    {
      *(_QWORD *)&this->mSimTimeDelta = 0i64;
    }
  }
  else
  {
    v3 = this->mSimTimeDeltaLocked;
    if ( v3 >= 0.0 )
    {
      this->mSimTimeDelta = v3;
      this->mSimTimeUnscaledDelta = v3;
    }
    else
    {
      v4 = UFG::Metrics::msRealTimeDelta_Accurate * v2;
      if ( (float)(UFG::Metrics::msRealTimeDelta_Accurate * v2) <= 0.0 )
        v4 = 0.0;
      if ( v4 >= this->mSimTimeDeltaMax )
        v4 = this->mSimTimeDeltaMax;
      this->mSimTimeDelta = v4;
      v5 = UFG::Metrics::msRealTimeDelta_Accurate;
      if ( UFG::Metrics::msRealTimeDelta_Accurate <= 0.0 )
        v5 = 0.0;
      if ( v5 >= this->mSimTimeDeltaMax )
        v5 = this->mSimTimeDeltaMax;
      this->mSimTimeUnscaledDelta = v5;
    }
    v6 = 0i64;
    v7 = this->mSimTimeDelta + this->mSimTime;
    v8 = v7;
    this->mSimTime = v7;
    v9 = v7 * 1000.0;
    this->mSimTime_Temp = v8;
    if ( v9 >= 9.223372036854776e18 )
    {
      v9 = v9 - 9.223372036854776e18;
      if ( v9 < 9.223372036854776e18 )
        v6 = 0x8000000000000000i64;
    }
    v10 = v6 + (unsigned int)(signed int)v9;
    v1->mSimTimeMSec = v10;
    v1->mSimTimeTicks.mTicks = (unsigned __int64)((v10 + 60) * (unsigned __int128)0x8888888888888889ui64 >> 64) >> 6;
    ++v1->mSimFrameCount;
  }
}

// File Line: 271
// RVA: 0x191AA0
void __fastcall UFG::Metrics::UpdateAllCommon(unsigned __int64 realTimeElapsedUnclamped, unsigned int realTimeDeltaUnclamped, bool frameRendered, bool nisPlaying)
{
  bool v4; // bp
  bool v5; // si
  unsigned __int64 v6; // rdi
  __int64 v7; // rax
  unsigned __int64 v8; // rdx
  float v9; // xmm7_4
  UFG::Metrics *v10; // rbx
  unsigned int v11; // ecx
  __int64 v12; // rax
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  bool v16; // al

  v4 = nisPlaying;
  v5 = frameRendered;
  v6 = realTimeElapsedUnclamped;
  if ( realTimeDeltaUnclamped <= UFG::Metrics::msRealTimeDeltaMSecMax )
  {
    v8 = UFG::Metrics::mMSecCounterClamped;
  }
  else
  {
    v7 = realTimeDeltaUnclamped - UFG::Metrics::msRealTimeDeltaMSecMax;
    v8 = v7 + UFG::Metrics::mMSecCounterClamped;
    UFG::Metrics::mMSecCounterClamped += v7;
  }
  UFG::Metrics::msRealTimeMSec = realTimeElapsedUnclamped - v8;
  UFG::Metrics::msRealTimeTicks.mTicks = (unsigned __int64)((realTimeElapsedUnclamped - v8 + 60)
                                                          * (unsigned __int128)0x8888888888888889ui64 >> 64) >> 6;
  v9 = UFG::Metrics::msRealTimeDelta_Accurate;
  UFG::Metrics::msRealTimeDelta = UFG::Metrics::msRealTimeDelta_Accurate;
  if ( !(_S2_6 & 1) )
  {
    _S2_6 |= 1u;
    stru_14235C4C0.mPrev = &stru_14235C4C0;
    stru_14235C4C0.mNext = &stru_14235C4C0;
    atexit(UFG::Metrics::GetUpdatingList_::_2_::_dynamic_atexit_destructor_for__sUpdateList__);
    v9 = UFG::Metrics::msRealTimeDelta;
  }
  v10 = (UFG::Metrics *)stru_14235C4C0.mNext;
  if ( stru_14235C4C0.mNext != &stru_14235C4C0 )
  {
    do
    {
      UFG::Metrics::Update(v10);
      v10 = (UFG::Metrics *)v10->mNext;
    }
    while ( v10 != (UFG::Metrics *)&stru_14235C4C0 );
    v9 = UFG::Metrics::msRealTimeDelta;
  }
  if ( v5 )
  {
    v11 = UFG::Metrics::msFrameCount++ + 1;
    if ( (unsigned int)(v6 - UFG::Metrics::msFrameTicksPrev) >= 0x1F4 )
    {
      UFG::Metrics::msFramesPerSec = (signed int)(float)((float)((float)(signed int)(v11 - UFG::Metrics::msFrameCountPrev)
                                                               / (float)((float)((signed int)v6
                                                                               - (signed int)UFG::Metrics::msFrameTicksPrev)
                                                                       * 0.001))
                                                       + 0.5);
      UFG::Metrics::msFrameCountPrev = v11;
      UFG::Metrics::msFrameTicksPrev = v6;
    }
    if ( !UFG::Metrics::msInstance.mSimPausedInGame )
    {
      LODWORD(v12) = (signed int)(float)((float)(signed int)(float)(1.0 / v9) * 0.2);
      if ( (_DWORD)v12 )
      {
        if ( (unsigned int)v12 >= 6 )
          LODWORD(v12) = 6;
      }
      else
      {
        LODWORD(v12) = 0;
      }
      v12 = (unsigned int)v12;
      if ( v4 )
        ++UFG::Metrics::msNISFramesPerSecBuckets[v12];
      else
        ++UFG::Metrics::msFramesPerSecBuckets[v12];
    }
  }
  v13 = sSineWaveSecs + v9;
  sSineWaveSecs = v13;
  if ( v13 > 2.0 )
  {
    v13 = v13 + -2.0;
    sSineWaveSecs = v13;
  }
  v14 = (float)(sinf((float)((float)((float)(v13 * 0.5) * 2.0) * 3.1415927) + 4.712389) + 1.0) * 0.5;
  UFG::Metrics::msRealTimeSineWave = v14;
  v15 = sRampWaveSecs + v9;
  sRampWaveSecs = v15;
  if ( v15 <= 1.0 )
  {
    v16 = sRampFlip;
  }
  else
  {
    v16 = sRampFlip == 0;
    sRampFlip = sRampFlip == 0;
    sRampWaveSecs = v15 + -1.0;
  }
  if ( v16 )
    UFG::Metrics::msRealTimeRampUpWave = v14;
  else
    UFG::Metrics::msRealTimeRampUpWave = 1.0 - v14;
}

// File Line: 403
// RVA: 0x1919C0
void __fastcall UFG::Metrics::UpdateAll(unsigned int realTimeMSecTicks, float deltaTime, bool frameRendered, bool nisPlaying)
{
  bool v4; // bl
  unsigned __int64 v5; // r10
  unsigned int v6; // er11
  unsigned __int64 v7; // r8
  __int64 v8; // rax

  UFG::Metrics::msRealTimeDelta_Accurate = deltaTime;
  v4 = frameRendered;
  if ( UFG::Metrics::msInitialized )
  {
    v6 = UFG::Metrics::mMSecCounterMinor;
    v5 = UFG::Metrics::mMSecCounterPrev;
  }
  else
  {
    v5 = realTimeMSecTicks;
    v6 = realTimeMSecTicks;
    UFG::Metrics::mMSecCounterMinor = realTimeMSecTicks;
    UFG::Metrics::msFrameTicksPrev = realTimeMSecTicks;
    UFG::Metrics::msInitialized = 1;
  }
  if ( UFG::Metrics::msFullyFixedTimeSteps )
  {
    realTimeMSecTicks = v5 + 34;
    if ( !switchWasOn )
    {
      v5 = realTimeMSecTicks;
      v6 = realTimeMSecTicks;
      UFG::Metrics::mMSecCounterMinor = realTimeMSecTicks;
      UFG::Metrics::msFrameTicksPrev = realTimeMSecTicks;
    }
    switchWasOn = 1;
  }
  else
  {
    switchWasOn = 0;
  }
  if ( v5 > realTimeMSecTicks && (unsigned int)v5 - realTimeMSecTicks < 0x7FFFFFFF )
    realTimeMSecTicks = v5 + 1;
  v7 = UFG::Metrics::mMSecCounterMajor;
  v8 = realTimeMSecTicks - v6;
  if ( (unsigned int)v8 > 0x90321000 )
  {
    v7 = v8 + UFG::Metrics::mMSecCounterMajor;
    v6 = realTimeMSecTicks;
    UFG::Metrics::mMSecCounterMinor = realTimeMSecTicks;
    UFG::Metrics::mMSecCounterMajor += v8;
  }
  UFG::Metrics::mMSecCounterPrev = realTimeMSecTicks;
  UFG::Metrics::UpdateAllCommon(v7 + realTimeMSecTicks - v6, realTimeMSecTicks - v5, v4, nisPlaying);
}

// File Line: 571
// RVA: 0x190CB0
bool __fastcall UFG::Metrics::IsTimeScaled(UFG::Metrics *this)
{
  float v1; // xmm0_4

  if ( this->mSimPausedInGame || this->mSimPausedDebug )
    v1 = 0.0;
  else
    v1 = this->mSimTimeScaleDebug * this->mSimTimeScaleInGame;
  return COERCE_FLOAT(COERCE_UNSIGNED_INT(v1 - 1.0) & _xmm) > 0.0099999998;
}

