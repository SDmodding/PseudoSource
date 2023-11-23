// File Line: 96
// RVA: 0x14686F0
__int64 dynamic_initializer_for__UFG::Metrics::msInstance__()
{
  UFG::qNode<UFG::qString,UFG::qString> *mPrev; // rax

  UFG::Metrics::msInstance.mSimTimeMSec = 0i64;
  UFG::Metrics::msInstance.mSimTimeTicks.mTicks = 0;
  UFG::Metrics::msInstance.mSimTime = 0.0;
  *(_QWORD *)&UFG::Metrics::msInstance.mSimTime_Temp = 0i64;
  *(_QWORD *)&UFG::Metrics::msInstance.mSimFrameCount = 0x3F80000000000000i64;
  UFG::Metrics::msInstance.mSimPausedInGame = 0;
  UFG::Metrics::msInstance.mSimTimeScaleDebug = 1.0;
  UFG::Metrics::msInstance.mSimPausedDebug = 0;
  UFG::Metrics::msInstance.mSimTimeDeltaMax = Metrics_sim_time_delta_max_def_19;
  UFG::Metrics::msInstance.mSimTimeDeltaLocked = FLOAT_N1_0;
  *(_OWORD *)&UFG::Metrics::msInstance.mSimTimeDeltaStep = _xmm;
  if ( (_S2_6 & 1) == 0 )
  {
    _S2_6 |= 1u;
    stru_14235C4C0.mPrev = &stru_14235C4C0;
    stru_14235C4C0.mNext = &stru_14235C4C0;
    atexit((int (__fastcall *)())UFG::Metrics::GetUpdatingList_::_2_::_dynamic_atexit_destructor_for__sUpdateList__);
  }
  mPrev = stru_14235C4C0.mPrev;
  stru_14235C4C0.mPrev->mNext = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::Metrics::msInstance;
  UFG::Metrics::msInstance.mPrev = (UFG::qNode<UFG::Metrics,UFG::Metrics> *)mPrev;
  UFG::Metrics::msInstance.mNext = (UFG::qNode<UFG::Metrics,UFG::Metrics> *)&stru_14235C4C0;
  stru_14235C4C0.mPrev = (UFG::qNode<UFG::qString,UFG::qString> *)&UFG::Metrics::msInstance;
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::Metrics::msInstance__);
}

// File Line: 167
// RVA: 0x191830
void __fastcall UFG::Metrics::Update(UFG::Metrics *this)
{
  float v2; // xmm2_4
  float mSimTimeDeltaLocked; // xmm1_4
  float mSimTimeDeltaMax; // xmm1_4
  float v5; // xmm2_4
  unsigned __int64 v6; // rdx
  long double v7; // xmm1_8
  float v8; // xmm0_4
  double v9; // xmm1_8
  unsigned __int64 v10; // rcx
  float mSimTimeDeltaStep; // xmm2_4
  unsigned __int64 v12; // rdx
  long double v13; // xmm1_8
  float v14; // xmm0_4
  double v15; // xmm1_8
  unsigned __int64 v16; // rcx

  if ( this->mSimPausedInGame
    || this->mSimPausedDebug
    || (v2 = this->mSimTimeScaleDebug * this->mSimTimeScaleInGame, v2 <= 0.0) )
  {
    mSimTimeDeltaStep = this->mSimTimeDeltaStep;
    if ( mSimTimeDeltaStep > 0.0 )
    {
      v12 = 0i64;
      this->mSimTimeDelta = mSimTimeDeltaStep;
      v13 = mSimTimeDeltaStep + this->mSimTime;
      this->mSimTimeUnscaledDelta = mSimTimeDeltaStep;
      v14 = v13;
      this->mSimTime = v13;
      v15 = v13 * 1000.0;
      this->mSimTime_Temp = v14;
      if ( v15 >= 9.223372036854776e18 )
      {
        v15 = v15 - 9.223372036854776e18;
        if ( v15 < 9.223372036854776e18 )
          v12 = 0x8000000000000000ui64;
      }
      v16 = v12 + (unsigned int)(int)v15;
      this->mSimTimeMSec = v16;
      this->mSimTimeTicks.mTicks = (v16 + 60) / 0x78;
      ++this->mSimFrameCount;
      this->mSimTimeDeltaStep = 0.0;
    }
    else
    {
      *(_QWORD *)&this->mSimTimeDelta = 0i64;
    }
  }
  else
  {
    mSimTimeDeltaLocked = this->mSimTimeDeltaLocked;
    if ( mSimTimeDeltaLocked >= 0.0 )
    {
      this->mSimTimeDelta = mSimTimeDeltaLocked;
      this->mSimTimeUnscaledDelta = mSimTimeDeltaLocked;
    }
    else
    {
      mSimTimeDeltaMax = UFG::Metrics::msRealTimeDelta_Accurate * v2;
      if ( (float)(UFG::Metrics::msRealTimeDelta_Accurate * v2) <= 0.0 )
        mSimTimeDeltaMax = 0.0;
      if ( mSimTimeDeltaMax >= this->mSimTimeDeltaMax )
        mSimTimeDeltaMax = this->mSimTimeDeltaMax;
      this->mSimTimeDelta = mSimTimeDeltaMax;
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
        v6 = 0x8000000000000000ui64;
    }
    v10 = v6 + (unsigned int)(int)v9;
    this->mSimTimeMSec = v10;
    this->mSimTimeTicks.mTicks = (v10 + 60) / 0x78;
    ++this->mSimFrameCount;
  }
}

// File Line: 271
// RVA: 0x191AA0
void __fastcall UFG::Metrics::UpdateAllCommon(
        unsigned __int64 realTimeElapsedUnclamped,
        unsigned int realTimeDeltaUnclamped,
        bool frameRendered,
        bool nisPlaying)
{
  unsigned __int64 v7; // rdx
  float v8; // xmm7_4
  UFG::Metrics *mNext; // rbx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  bool v15; // al

  if ( realTimeDeltaUnclamped <= UFG::Metrics::msRealTimeDeltaMSecMax )
  {
    v7 = UFG::Metrics::mMSecCounterClamped;
  }
  else
  {
    v7 = realTimeDeltaUnclamped - UFG::Metrics::msRealTimeDeltaMSecMax + UFG::Metrics::mMSecCounterClamped;
    UFG::Metrics::mMSecCounterClamped = v7;
  }
  UFG::Metrics::msRealTimeMSec = realTimeElapsedUnclamped - v7;
  UFG::Metrics::msRealTimeTicks.mTicks = (realTimeElapsedUnclamped - v7 + 60) / 0x78;
  v8 = UFG::Metrics::msRealTimeDelta_Accurate;
  UFG::Metrics::msRealTimeDelta = UFG::Metrics::msRealTimeDelta_Accurate;
  if ( (_S2_6 & 1) == 0 )
  {
    _S2_6 |= 1u;
    stru_14235C4C0.mPrev = &stru_14235C4C0;
    stru_14235C4C0.mNext = &stru_14235C4C0;
    atexit(UFG::Metrics::GetUpdatingList_::_2_::_dynamic_atexit_destructor_for__sUpdateList__);
    v8 = UFG::Metrics::msRealTimeDelta;
  }
  mNext = (UFG::Metrics *)stru_14235C4C0.mNext;
  if ( stru_14235C4C0.mNext != &stru_14235C4C0 )
  {
    do
    {
      UFG::Metrics::Update(mNext);
      mNext = (UFG::Metrics *)mNext->mNext;
    }
    while ( mNext != (UFG::Metrics *)&stru_14235C4C0 );
    v8 = UFG::Metrics::msRealTimeDelta;
  }
  if ( frameRendered )
  {
    v10 = ++UFG::Metrics::msFrameCount;
    if ( (unsigned int)(realTimeElapsedUnclamped - UFG::Metrics::msFrameTicksPrev) >= 0x1F4 )
    {
      UFG::Metrics::msFramesPerSec = (int)(float)((float)((float)(int)(v10 - UFG::Metrics::msFrameCountPrev)
                                                        / (float)((float)((int)realTimeElapsedUnclamped
                                                                        - (int)UFG::Metrics::msFrameTicksPrev)
                                                                * 0.001))
                                                + 0.5);
      UFG::Metrics::msFrameCountPrev = v10;
      UFG::Metrics::msFrameTicksPrev = realTimeElapsedUnclamped;
    }
    if ( !UFG::Metrics::msInstance.mSimPausedInGame )
    {
      v11 = (int)(float)((float)(int)(float)(1.0 / v8) * 0.2);
      if ( v11 )
      {
        if ( v11 >= 6 )
          v11 = 6;
      }
      else
      {
        v11 = 0;
      }
      if ( nisPlaying )
        ++UFG::Metrics::msNISFramesPerSecBuckets[v11];
      else
        ++UFG::Metrics::msFramesPerSecBuckets[v11];
    }
  }
  v12 = sSineWaveSecs + v8;
  sSineWaveSecs = v12;
  if ( v12 > 2.0 )
  {
    v12 = v12 + -2.0;
    sSineWaveSecs = v12;
  }
  v13 = (float)(sinf((float)((float)((float)(v12 * 0.5) * 2.0) * 3.1415927) + 4.712389) + 1.0) * 0.5;
  UFG::Metrics::msRealTimeSineWave = v13;
  v14 = sRampWaveSecs + v8;
  sRampWaveSecs = v14;
  if ( v14 <= 1.0 )
  {
    v15 = sRampFlip;
  }
  else
  {
    v15 = !sRampFlip;
    sRampFlip = !sRampFlip;
    sRampWaveSecs = v14 + -1.0;
  }
  if ( v15 )
    UFG::Metrics::msRealTimeRampUpWave = v13;
  else
    UFG::Metrics::msRealTimeRampUpWave = 1.0 - v13;
}

// File Line: 403
// RVA: 0x1919C0
void __fastcall UFG::Metrics::UpdateAll(
        unsigned int realTimeMSecTicks,
        float deltaTime,
        bool frameRendered,
        bool nisPlaying)
{
  unsigned __int64 v5; // r10
  unsigned int v6; // r11d
  unsigned __int64 v7; // r8
  __int64 v8; // rax

  UFG::Metrics::msRealTimeDelta_Accurate = deltaTime;
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
  UFG::Metrics::UpdateAllCommon(v7 + realTimeMSecTicks - v6, realTimeMSecTicks - v5, frameRendered, nisPlaying);
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

