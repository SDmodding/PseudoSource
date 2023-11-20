// File Line: 224
// RVA: 0x6BA30
void __fastcall UFG::TimeOfDayManager::LockWeather(UFG::TimeOfDayManager *this, bool lock)
{
  int v2; // eax

  if ( lock )
  {
    v2 = this->m_WeatherRandomInterval;
    if ( v2 )
    {
      this->m_WeatherRandomIntervalPreLock = v2;
      this->m_WeatherRandomInterval = 0;
    }
  }
  else if ( !this->m_WeatherRandomInterval )
  {
    this->m_WeatherRandomInterval = this->m_WeatherRandomIntervalPreLock;
  }
}

// File Line: 247
// RVA: 0x6B460
bool __fastcall UFG::TimeOfDayManager::IsSunShining(UFG::TimeOfDayManager *this, CB_EnvironmentSettings *envState)
{
  return (float)((float)(envState->SunColor[1] + envState->SunColor[0]) + envState->SunColor[2]) > 0.0099999998;
}

// File Line: 252
// RVA: 0x6B420
bool __fastcall UFG::TimeOfDayManager::IsAboutToRain(UFG::TimeOfDayManager *this)
{
  bool result; // al
  int v2; // eax

  result = 1;
  if ( this->m_WeatherState <= 1.0 )
  {
    v2 = this->m_WeatherRandomInterval;
    if ( v2 <= 0
      || this->m_NextWeatherTarget <= 1.0
      || (float)((float)v2 - UFG::TimeOfDayManager::ms_weather_interval) >= 40.0 )
    {
      result = 0;
    }
  }
  return result;
}

// File Line: 274
// RVA: 0x6BC00
void __fastcall TimePlotPoint::SetTimeValue(UFG::TimeOfDayManager *this, float gameSecondsPerRealSecond)
{
  this->m_GameSecondsPerRealSecond = gameSecondsPerRealSecond;
}

// File Line: 280
// RVA: 0x6BAA0
void __fastcall UFG::TimeOfDayManager::SetSurfaceWetnessOverride(UFG::TimeOfDayManager *this, float wetness, const char *desc)
{
  UFG::TimeOfDayManager *v3; // rbx

  v3 = this;
  UFG::qPrintf("SetSurfaceWetnessOverride (%s) = %f\n", desc, wetness);
  v3->m_OverrideSurfaceWetness = wetness;
}

// File Line: 287
// RVA: 0x6BCD0
void __fastcall UFG::TimeOfDayManager::Update(UFG::TimeOfDayManager *this, float fDelta)
{
  UFG::TimeOfDayManager *v2; // rbx
  float v3; // xmm0_4
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  signed int v7; // eax
  float v8; // xmm1_4
  float v9; // xmm6_4
  float v10; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  float v24; // xmm6_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  int v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  float v34; // xmm0_4
  __m128 v35; // xmm2
  float v36; // xmm1_4
  float v37; // xmm9_4
  __int128 v38; // xmm11
  __m128 v39; // xmm3
  float v40; // xmm4_4
  float v41; // xmm8_4
  float v42; // xmm5_4
  __int128 v43; // xmm10
  float v44; // xmm9_4
  __m128 v45; // xmm2
  float v46; // xmm1_4
  float v47; // xmm9_4
  float v48; // xmm3_4
  float v49; // xmm2_4
  __m128 v50; // xmm11
  float v51; // xmm3_4
  __m128 v52; // xmm9
  float v53; // xmm6_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  UFG::TransformNodeComponent *v56; // rcx
  float v57; // xmm2_4
  unsigned int v58; // eax
  unsigned int v59; // edx
  UFG::qVector4 dir; // [rsp+28h] [rbp-59h]
  UFG::qMatrix44 m; // [rsp+38h] [rbp-49h]
  float value; // [rsp+F0h] [rbp+6Fh]

  v2 = this;
  if ( UFG::gHoursSinceMidnight < 0.0 )
  {
    v4 = this->m_SecondsSinceMidnight;
    if ( v4 < 10800.0 || v4 > 75600.0 )
      v5 = FLOAT_1_33;
    else
      v5 = *(float *)&FLOAT_1_0;
    gPrevSecondsSinceMidnight = this->m_SecondsSinceMidnight;
    UFG::TimeOfDayManager::SetTime(this, (float)((float)(fDelta * this->m_GameSecondsPerRealSecond) * v5) + v4, 1);
  }
  else
  {
    v3 = fmodf(UFG::gHoursSinceMidnight * 3600.0, 86400.0);
    gDisabledQuantizedTime = 1;
    v2->m_SecondsSinceMidnight = v3;
    v2->m_QuantizedSecondsSinceMidnight = v3;
  }
  v6 = UFG::TimeOfDayManager::ms_weather_interval + (float)(gTOD_Speedhack * fDelta);
  UFG::TimeOfDayManager::ms_weather_interval = UFG::TimeOfDayManager::ms_weather_interval
                                             + (float)(gTOD_Speedhack * fDelta);
  v7 = v2->m_WeatherRandomInterval;
  if ( v7 > 0 )
  {
    v2->m_NextRainingInterval = v2->m_NextRainingInterval - (float)(gTOD_Speedhack * fDelta);
    v6 = UFG::TimeOfDayManager::ms_weather_interval;
  }
  if ( gTriggerRandomWeatherTarget || v7 > 0 && v6 > (float)v7 )
  {
    v2->m_WeatherTarget = v2->m_NextWeatherTarget;
    gTriggerRandomWeatherTarget = 0;
    v8 = FLOAT_0_1;
    v9 = UFG::qRandom(1.0, &gRainSeed);
    v10 = v2->m_WeatherTarget;
    if ( v10 >= 0.1 || v9 > 0.89999998 )
      v2->m_NextWeatherTarget = 0.0;
    else
      v2->m_NextWeatherTarget = 0.1;
    if ( v2->m_PendingRain && v10 > 1.0 )
    {
      v11 = UFG::qRandom(gMaxNextRainInterval - gMinNextRainInterval, &UFG::qDefaultSeed);
      v8 = FLOAT_0_1;
      v2->m_PendingRain = 0;
      v2->m_NextRainingInterval = v11 + gMinNextRainInterval;
    }
    if ( v2->m_NextRainingInterval < 0.0 )
    {
      if ( v9 >= v8 )
      {
        if ( v9 >= 0.40000001 )
          v2->m_NextWeatherTarget = 1.25;
        else
          v2->m_NextWeatherTarget = 1.75;
      }
      else
      {
        v2->m_NextWeatherTarget = 2.0;
      }
      v2->m_PendingRain = 1;
    }
    v12 = UFG::qRandom(6.2831855, &UFG::qDefaultSeed);
    v13 = v2->m_WeatherTarget;
    v2->mWindSpeedTarget = 0.75;
    v2->mWindSpeed = 0.75;
    v2->mWindDirectionTargetRadians = (float)(v12 + v2->mWindDirectionRadians) - 3.1415927;
    Render::SkyMarshall::UpdateSkydomeTarget(&Render::SkyMarshall::gSkyMarshall, v13);
    UFG::TimeOfDayManager::ms_weather_interval = 0.0;
  }
  v14 = v2->m_WeatherTarget;
  v15 = v2->m_WeatherTarget;
  value = v2->m_WeatherState;
  UFG::qApproach(&value, v15, gWeatherChangeStep, gTOD_Speedhack);
  v16 = value;
  if ( value <= *(float *)&dword_1421634FC )
    v16 = *(float *)&dword_1421634FC;
  v2->m_WeatherState = v16;
  v2->m_WeatherTarget = v14;
  if ( UFG::gWeatherState >= 0.0 )
    v2->m_WeatherState = UFG::gWeatherState;
  v17 = v2->mWindDirectionRadians;
  v18 = v2->mWindDirectionTargetRadians;
  if ( v17 <= v18 )
  {
    if ( v17 >= v18 )
      goto LABEL_37;
    v19 = v17 + gWindChangeStep;
  }
  else
  {
    v19 = v17 - gWindChangeStep;
  }
  v2->mWindDirectionRadians = v19;
LABEL_37:
  if ( gWindDirectionTweakerRadians >= 0.0 )
    v2->mWindDirectionRadians = gWindDirectionTweakerRadians;
  v20 = v2->mWindSpeed;
  v21 = v2->mWindSpeedTarget;
  v22 = gWindSpeedChangeStep;
  if ( v20 > v21 )
    v2->mWindSpeed = v20 - gWindSpeedChangeStep;
  v23 = v2->mWindSpeed;
  if ( v23 < v21 )
    v2->mWindSpeed = v23 + v22;
  if ( gWindSpeedTweaker >= 0.0 )
    v2->mWindSpeed = gWindSpeedTweaker;
  v24 = v2->mWindDirectionRadians;
  v2->mWindDirection.x = cosf(v2->mWindDirectionRadians);
  v25 = sinf(v24);
  v2->mWindDirection.z = 0.0;
  v2->mWindDirection.y = v25;
  v26 = v2->m_WeatherState;
  if ( v26 <= 0.0 )
  {
    v26 = 0.0;
    goto LABEL_49;
  }
  v27 = FLOAT_2_0;
  if ( v26 < 2.0 )
LABEL_49:
    v27 = v26;
  v2->m_WeatherState = v27;
  if ( v27 <= 1.0 )
    v28 = gWeatherSurfaceDryingStep;
  else
    v28 = gWeatherSurfaceWetnessStep;
  v29 = v28 + v2->m_WeatherSurfaceWetness;
  v2->m_WeatherSurfaceWetness = v29;
  v30 = dword_142163500;
  if ( *(float *)&dword_142163500 <= v29 )
    v30 = LODWORD(v29);
  v31 = v2->m_OverrideSurfaceWetness;
  LODWORD(v2->m_WeatherSurfaceWetness) = v30;
  if ( v31 >= 0.0 )
    v2->m_WeatherSurfaceWetness = v31;
  v32 = v2->m_WeatherSurfaceWetness;
  if ( v32 <= 0.0 )
  {
    v32 = 0.0;
  }
  else if ( v32 >= 1.0 )
  {
    v32 = *(float *)&FLOAT_1_0;
  }
  v33 = gSurfaceWetness;
  v2->m_WeatherSurfaceWetness = v32;
  if ( v33 >= 0.0 )
    v2->m_WeatherSurfaceWetness = v33;
  v34 = v2->m_SecondsSinceMidnight;
  if ( v34 < 21600.0 || v34 > 64800.0 )
  {
    v59 = v2->m_SunFx;
    if ( v59 != -1 )
    {
      Render::FXManager::KillEffect(&Render::gFXManager, v59, 0);
      v2->m_SunFx = -1;
    }
  }
  else
  {
    UFG::TimeOfDayManager::GetSunDir(v2, &dir, 0, 0);
    v35 = (__m128)LODWORD(dir.y);
    v35.m128_f32[0] = (float)((float)(v35.m128_f32[0] * v35.m128_f32[0]) + (float)(dir.x * dir.x))
                    + (float)(dir.z * dir.z);
    if ( v35.m128_f32[0] == 0.0 )
      v36 = 0.0;
    else
      v36 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v35));
    v37 = UFG::qVector3::msAxisZ.x;
    v38 = LODWORD(UFG::qVector3::msAxisZ.y);
    v39 = (__m128)LODWORD(UFG::qVector3::msAxisZ.z);
    LODWORD(v40) = COERCE_UNSIGNED_INT(dir.x * v36) ^ _xmm[0];
    LODWORD(v41) = COERCE_UNSIGNED_INT(dir.z * v36) ^ _xmm[0];
    LODWORD(v42) = COERCE_UNSIGNED_INT(dir.y * v36) ^ _xmm[0];
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                        (float)((float)(v40 * UFG::qVector3::msAxisZ.x) + (float)(v42 * UFG::qVector3::msAxisZ.y))
                      + (float)(v41 * UFG::qVector3::msAxisZ.z)) & _xmm) > 0.99900001 )
    {
      v37 = UFG::qVector3::msAxisY.x;
      v38 = LODWORD(UFG::qVector3::msAxisY.y);
      v39 = (__m128)LODWORD(UFG::qVector3::msAxisY.z);
    }
    v43 = v38;
    *(float *)&v43 = (float)(*(float *)&v38 * v41) - (float)(v39.m128_f32[0] * v42);
    v39.m128_f32[0] = (float)(v39.m128_f32[0] * v40) - (float)(v37 * v41);
    v44 = (float)(v37 * v42) - (float)(*(float *)&v38 * v40);
    v45 = v39;
    v45.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(*(float *)&v43 * *(float *)&v43))
                    + (float)(v44 * v44);
    if ( v45.m128_f32[0] == 0.0 )
      v46 = 0.0;
    else
      v46 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v45));
    v47 = v44 * v46;
    *(float *)&v43 = *(float *)&v43 * v46;
    v48 = v39.m128_f32[0] * v46;
    m.v0.w = 0.0;
    m.v0.z = v47;
    LODWORD(m.v0.x) = v43;
    m.v0.y = v48;
    v50 = (__m128)v43;
    v49 = (float)(v47 * v42) - (float)(v48 * v41);
    v50.m128_f32[0] = (float)(*(float *)&v43 * v41) - (float)(v47 * v40);
    v51 = (float)(v48 * v40) - (float)(*(float *)&v43 * v42);
    v52 = v50;
    v52.m128_f32[0] = (float)((float)(v50.m128_f32[0] * v50.m128_f32[0]) + (float)(v49 * v49)) + (float)(v51 * v51);
    if ( v52.m128_f32[0] == 0.0 )
      v53 = 0.0;
    else
      v53 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v52));
    v54 = v2->mCameraPosition.x;
    v55 = v2->mCameraPosition.y;
    v56 = v2->m_SunFxTransform;
    m.v1.w = 0.0;
    m.v2.w = 0.0;
    m.v1.x = v49 * v53;
    v57 = v2->mCameraPosition.z;
    m.v2.x = v40;
    m.v3.w = 1.0;
    m.v3.z = v57;
    m.v1.y = v50.m128_f32[0] * v53;
    m.v1.z = v51 * v53;
    m.v2.y = v42;
    m.v2.z = v41;
    m.v3.x = v54;
    m.v3.y = v55;
    UFG::TransformNodeComponent::SetWorldTransform(v56, &m);
    if ( v2->m_SunFx == -1 )
    {
      v58 = UFG::qStringHashUpper32("Sun", 0xFFFFFFFF);
      v2->m_SunFx = Render::FXManager::CreateEffect(&Render::gFXManager, v58, v2->m_SunFxTransform, 0xFFFFFFFF, 0i64);
    }
  }
}

// File Line: 482
// RVA: 0x6BAE0
void __fastcall UFG::TimeOfDayManager::SetTime(UFG::TimeOfDayManager *this, float secondsSinceMidnight, bool is_regular_update)
{
  UFG::TimeOfDayManager *v3; // rdi
  bool v4; // bl
  float v5; // xmm0_4
  float v6; // xmm8_4
  float v7; // xmm9_4
  float v8; // xmm6_4
  float v9; // xmm6_4

  v3 = this;
  v4 = is_regular_update;
  v5 = fmodf(secondsSinceMidnight, 86400.0);
  v6 = v5;
  v3->m_SecondsSinceMidnight = v5;
  if ( !v4 )
  {
    v3->m_QuantizedSecondsSinceMidnight = v5;
    gDisabledQuantizedTime = 1;
    return;
  }
  v7 = fmodf(v5, 800.0);
  v8 = v7 - 700.0;
  if ( (float)(v7 - 700.0) <= 0.0 )
    v8 = 0.0;
  v9 = v8 * 0.01010101;
  if ( !gDisabledQuantizedTime )
    goto LABEL_8;
  if ( v3->m_GameSecondsPerRealSecond > 0.0 && fmodf(gPrevSecondsSinceMidnight, 800.0) > v7 )
  {
    gDisabledQuantizedTime = 0;
LABEL_8:
    v3->m_QuantizedSecondsSinceMidnight = (float)(secondsSinceMidnight - v7) + (float)((float)(v9 * 100.0) * 8.0);
    return;
  }
  v3->m_QuantizedSecondsSinceMidnight = v6;
}

// File Line: 513
// RVA: 0x69AC0
void __fastcall UFG::TimeOfDayManager::TimeOfDayManager(UFG::TimeOfDayManager *this)
{
  UFG::TimeOfDayManager *v1; // rbx
  float v2; // xmm0_4
  float v3; // xmm7_4

  v1 = this;
  this->m_WeatherRandomIntervalPreLock = 0;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mOverrideStateBlockHandle.mPrev);
  v1->m_DefaultGameSecondsPerRealSecond = 30.0;
  v1->mNightFogZones = 0i64;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mSunnyStateBlockHandle.mPrev);
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&v1->mOvercastStateBlockHandle.mPrev);
  *(_QWORD *)&v1->mCameraPosition.x = 0i64;
  v1->mCameraPosition.z = 0.0;
  v1->m_GameSecondsPerRealSecond = 0.0;
  v2 = fmodf(0.0, 86400.0);
  v1->m_SecondsSinceMidnight = v2;
  v1->m_QuantizedSecondsSinceMidnight = v2;
  gDisabledQuantizedTime = 1;
  v1->m_SunDeclination = sinf(7.4709659) * 0.40927973;
  *(_QWORD *)&v1->m_WeatherState = 0i64;
  v1->m_NextWeatherTarget = 0.0;
  v1->m_WeatherRandomInterval = 180;
  v1->mWindDirectionTargetRadians = 0.78539819;
  v1->mWindDirectionRadians = 0.78539819;
  v3 = sinf(0.78539819);
  v1->mWindDirection.x = cosf(0.78539819);
  v1->mWindDirection.y = v3;
  v1->mWindDirection.z = 0.0;
  v1->mWindSpeedTarget = 0.75;
  v1->mWindSpeed = 0.75;
  v1->m_WeatherChanceOfPrecipitation = 0.15000001;
  v1->m_WeatherSurfaceWetness = 0.0;
  v1->m_LocalLatitude = 0.38397244;
  v1->m_OverrideStateBlockAmount = 0.0;
  v1->m_OverrideSurfaceWetness = -1.0;
  v1->mNumFogTextures = 0;
  v1->mFogCubeTexture[0] = 0i64;
  v1->mFogCubeTexture[1] = 0i64;
  v1->mFogCubeTexture[2] = 0i64;
  v1->mFogCubeTexture[3] = 0i64;
  v1->mCurrStartSlice = 0;
  v1->mFogUpdateInterval = 1;
  v1->mCurrEndSlice = 4;
  v1->mGlobalIlluminationBlend = 1.0;
  UFG::qSphericalToCartesian(v1->mAmbientSkyDirection, 0.0, 65.0);
  UFG::qSphericalToCartesian(&v1->mAmbientSkyDirection[1], 120.0, 65.0);
  UFG::qSphericalToCartesian(&v1->mAmbientSkyDirection[2], 240.0, 65.0);
  v1->m_SunFxTransform = 0i64;
  v1->m_SunFx = -1;
  v1->m_NextRainingInterval = UFG::qRandom(gMaxNextRainInterval - gMinNextRainInterval, &UFG::qDefaultSeed)
                            + gMinNextRainInterval;
  v1->m_PendingRain = 0;
}

// File Line: 553
// RVA: 0x69CE0
void __fastcall UFG::TimeOfDayManager::~TimeOfDayManager(UFG::TimeOfDayManager *this)
{
  UFG::TimeOfDayManager *v1; // rbx
  UFG::qResourceInventory *v2; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  UFG::qResourceHandle *v6; // rbx
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  v1 = this;
  operator delete[](this->mNightFogZones);
  v2 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    v2 = UFG::qResourceWarehouse::GetInventory(v3, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v2;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mOvercastStateBlockHandle.mPrev, v2);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mOvercastStateBlockHandle.mPrev);
  v4 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v4;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v1->mSunnyStateBlockHandle.mPrev, v4);
  UFG::qResourceHandle::~qResourceHandle((UFG::qResourceHandle *)&v1->mSunnyStateBlockHandle.mPrev);
  v6 = (UFG::qResourceHandle *)&v1->mOverrideStateBlockHandle.mPrev;
  v7 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v7;
  }
  UFG::qResourceHandle::Close(v6, v7);
  UFG::qResourceHandle::~qResourceHandle(v6);
}

// File Line: 558
// RVA: 0x6AA70
UFG::TimeOfDayManager *__fastcall UFG::TimeOfDayManager::GetInstance()
{
  if ( !(_S1_12 & 1) )
  {
    _S1_12 |= 1u;
    UFG::TimeOfDayManager::TimeOfDayManager(&gManager);
    atexit(UFG::TimeOfDayManager::GetInstance_::_2_::_dynamic_atexit_destructor_for__gManager__);
  }
  return &gManager;
}

// File Line: 597
// RVA: 0x6C3F0
UFG::qTask *__fastcall UFG::TimeOfDayManager::UpdateFog(UFG::TimeOfDayManager *this, CB_EnvironmentSettings *settings, bool bForceFullUpdate, bool nullOutput)
{
  bool v4; // di
  char v5; // r12
  UFG::TimeOfDayManager *v6; // rsi
  char *v7; // r15
  unsigned int v8; // er13
  Illusion::ITexturePlat *v9; // rbx
  _OWORD *v10; // rcx
  unsigned int *v11; // rdx
  signed __int64 v12; // rax
  __int64 v13; // rbx
  bool v14; // r14
  char *v15; // rax
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *v16; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *v17; // rax
  unsigned int v18; // er12
  __int64 v19; // rdi
  FogTaskParams *v20; // rbx
  float v21; // xmm1_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  UFG::qTask *v24; // rax
  UFG::qTask *v25; // rdx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v26; // rax
  UFG::qSpuElf *v27; // rax
  void (__fastcall *v28)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *v29)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *v30)(void *, void *, void *, void *); // r9
  char *v31; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v32; // rax
  unsigned int v33; // eax
  int v34; // ecx
  int v35; // ebx
  Illusion::ITexturePlat **v36; // rdi
  Illusion::ITexturePlat *v37; // r14
  _OWORD *v38; // rcx
  unsigned int *v39; // rdx
  signed __int64 v40; // rax
  char *v42; // [rsp+30h] [rbp-71h]
  UFG::qMemoryStreamer memory_streamer; // [rsp+38h] [rbp-69h]
  __int64 v44; // [rsp+88h] [rbp-19h]
  unsigned int v45; // [rsp+108h] [rbp+67h]
  void *v46; // [rsp+110h] [rbp+6Fh]
  char v47; // [rsp+118h] [rbp+77h]

  v44 = -2i64;
  v4 = nullOutput;
  v5 = bForceFullUpdate;
  v6 = this;
  v7 = 0i64;
  v42 = 0i64;
  this->mNightFogZones->x = UFG::gNightFogPosX;
  this->mNightFogZones->y = UFG::gNightFogPosY;
  this->mNightFogZones->innerRadius = UFG::gNightFogInnerRadius;
  this->mNightFogZones->outerRadius = UFG::gNightFogOuterRadius;
  v8 = 0;
  v45 = 32;
  v9 = (Illusion::ITexturePlat *)this->mFogCubeTexture[gPCFogUpdateBuffer];
  *(_QWORD *)&memory_streamer.mWorkerID = 0i64;
  *(_QWORD *)&memory_streamer.mDmaChannelWrite = 0i64;
  if ( Illusion::ITexturePlat::Lock(v9, LOCK_MODIFY, (Illusion::TextureLockInfo *)&memory_streamer.mWorkerID, 0, 0) )
  {
    v10 = *(_OWORD **)&memory_streamer.mWorkerID;
    v11 = gPCFogData;
    if ( (LOBYTE(memory_streamer.mWorkerID) | (unsigned __int8)gPCFogData) & 0xF )
    {
      memmove(*(void **)&memory_streamer.mWorkerID, gPCFogData, 0x20000ui64);
    }
    else
    {
      v12 = 1024i64;
      do
      {
        *v10 = *(_OWORD *)v11;
        v10[1] = *((_OWORD *)v11 + 1);
        v10[2] = *((_OWORD *)v11 + 2);
        v10[3] = *((_OWORD *)v11 + 3);
        v10[4] = *((_OWORD *)v11 + 4);
        v10[5] = *((_OWORD *)v11 + 5);
        v10[6] = *((_OWORD *)v11 + 6);
        v10 += 8;
        *(v10 - 1) = *((_OWORD *)v11 + 7);
        v11 += 32;
        --v12;
      }
      while ( v12 );
    }
    Illusion::ITexturePlat::Unlock(v9);
  }
  if ( !v5 )
  {
    v8 = v6->mCurrStartSlice;
    v45 = v6->mCurrEndSlice;
  }
  v13 = 4 / v6->mFogUpdateInterval;
  UFG::gCurrentFogSliceIndex = v8;
  v14 = gSpuFog != 0;
  if ( gSpuFog )
  {
    v15 = UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x140u, 0x40u);
    v7 = v15;
    v42 = v15;
    memory_streamer.mWaitReadTicks = (unsigned __int64)v15;
    memory_streamer.mMainMemTask = (UFG::qTask *)v15;
    if ( v15 )
      UFG::qTaskGroup::qTaskGroup((UFG::qTaskGroup *)v15, "FogTaskGroup");
    v16 = UFG::gTaskManager.mSingleFrameTaskGroups;
    v17 = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
    v17->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)v7;
    *(_QWORD *)v7 = v17;
    *((_QWORD *)v7 + 1) = v16;
    v16->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)v7;
  }
  if ( (_DWORD)v13 )
  {
    v18 = v4;
    v19 = v13;
    do
    {
      v20 = (FogTaskParams *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x50u, 0x10u);
      v20->destination_Remote = gPCFogData;
      v20->environmentSettings_Remote = v46;
      v20->camHeight = v6->mCameraPosition.z;
      v21 = v6->mCameraPosition.y;
      v22 = v6->mCameraPosition.z;
      v20->cameraPosition.x = v6->mCameraPosition.x;
      v20->cameraPosition.y = v21;
      v20->cameraPosition.z = v22;
      v20->cameraPosition.w = 1.0;
      v20->nightFogZones = v6->mNightFogZones;
      v20->minimumNightFog = UFG::TimeOfDayManager::GetMinimumNightFogValue(v6->m_SecondsSinceMidnight);
      v20->startSlice = v8;
      v20->endSlice = v45;
      v20->useSkyFogAmount = 1;
      v20->currSliceIndex = (void *)&UFG::gCurrentFogSliceIndex;
      if ( UFG::gIsSkyIrradFog <= 0.0 )
        v23 = FLOAT_N0_1;
      else
        v23 = FLOAT_0_2;
      v20->skyLowerThreshold = v23;
      v20->nullOutput = v18;
      if ( v14 )
      {
        v24 = (UFG::qTask *)UFG::qLinearAllocator::Malloc(UFG::gTaskManager.mAllocator, 0x80u, 0x40u);
        v25 = v24;
        memory_streamer.mMainMemTask = v24;
        memory_streamer.mWaitReadTicks = (unsigned __int64)v24;
        if ( v24 )
        {
          v24->mPrev = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v24->mPrev;
          v24->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v24->mPrev;
          v26 = (UFG::qNode<UFG::qTask,UFG::TaskPlat> *)&v24->mPrev;
          v26->mPrev = v26;
          v26->mNext = v26;
          v27 = gTaskFunctionDeclData_UpdateFogTask.mSpuElf;
          v28 = gTaskFunctionDeclData_UpdateFogTask.mTaskFunctionSPU;
          v29 = gTaskFunctionDeclData_UpdateFogTask.mTaskFunctionPPU;
          v30 = gTaskFunctionDeclData_UpdateFogTask.mTaskFunctionOffload;
          if ( !gTaskFunctionDeclData_UpdateFogTask.mCurrentSPUEnabled )
          {
            v27 = 0i64;
            v28 = 0i64;
            v30 = 0i64;
          }
          v25->mTaskGroup = (UFG::qTaskGroup *)v7;
          v25->mFlags = 2;
          v25->mSyncVars.i64 = 0i64;
          v25->mSyncVars.v.mDependents = 0i64;
          v25->mFunctionDeclData = &gTaskFunctionDeclData_UpdateFogTask;
          if ( v27 )
            v31 = v27->mAddress;
          else
            v31 = 0i64;
          v25->mSPUElfAddress = v31;
          v25->mSPUFunction = v28;
          v25->mPPUFunction = v29;
          v25->mParam0 = v20;
          v25->mParam1 = 0i64;
          v25->mParam2 = 0i64;
          v25->mParam3 = 0i64;
          if ( v30 )
          {
            v25->mFlags = 130;
            v25->mOffloadThread = 0;
          }
        }
        v32 = (UFG::qNode<UFG::qTask,UFG::qTask> *)*((_QWORD *)v7 + 2);
        v32->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)&v25->mPrev;
        v25->mPrev = v32;
        v25->mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)(v7 + 16);
        *((_QWORD *)v7 + 2) = v25;
        ++*((_DWORD *)v7 + 8);
      }
      else
      {
        memory_streamer.mDmaChannelRead = 0;
        memory_streamer.mDmaChannelWrite = 1;
        *(_QWORD *)&memory_streamer.mNumReads = 0i64;
        *(_QWORD *)&memory_streamer.mWaitReadTime = 0i64;
        memory_streamer.mWaitReadTicks = 0i64;
        memory_streamer.mWaitWriteTicks = 0i64;
        memory_streamer.mUserStats = 0i64;
        memory_streamer.mTweakParams = 0i64;
        UpdateFogTask(0, &memory_streamer, v20, 0i64, 0i64);
      }
      --v19;
    }
    while ( v19 );
    v5 = v47;
  }
  gPCFogRenderBuffer = (gPCFogRenderBuffer + 1) % v6->mNumFogTextures;
  gPCFogUpdateBuffer = (gPCFogUpdateBuffer + 1) % v6->mNumFogTextures;
  if ( !gPCFogUpdateBuffer )
  {
    v33 = 32u / (8 * v6->mFogUpdateInterval);
    v34 = ((_BYTE)v33 + (unsigned __int8)v6->mCurrStartSlice) & 0x1F;
    if ( v34 == 32 )
      v34 = 0;
    v6->mCurrStartSlice = v34;
    v6->mCurrEndSlice = v33 + v34;
  }
  if ( !v5 )
    return (UFG::qTask *)v7;
  UFG::qTaskManager::Sync(&UFG::gTaskManager);
  v35 = 0;
  if ( v6->mNumFogTextures <= 0 )
    return (UFG::qTask *)v7;
  v36 = (Illusion::ITexturePlat **)v6->mFogCubeTexture;
  do
  {
    v37 = *v36;
    memory_streamer.mWaitWriteTicks = 0i64;
    if ( Illusion::ITexturePlat::Lock(
           v37,
           LOCK_MODIFY,
           (Illusion::TextureLockInfo *)&memory_streamer.mWaitWriteTicks,
           0,
           0) )
    {
      v38 = (_OWORD *)memory_streamer.mWaitWriteTicks;
      v39 = gPCFogData;
      if ( (LOBYTE(memory_streamer.mWaitWriteTicks) | (unsigned __int8)gPCFogData) & 0xF )
      {
        memmove((void *)memory_streamer.mWaitWriteTicks, gPCFogData, 0x20000ui64);
      }
      else
      {
        v40 = 1024i64;
        do
        {
          *v38 = *(_OWORD *)v39;
          v38[1] = *((_OWORD *)v39 + 1);
          v38[2] = *((_OWORD *)v39 + 2);
          v38[3] = *((_OWORD *)v39 + 3);
          v38[4] = *((_OWORD *)v39 + 4);
          v38[5] = *((_OWORD *)v39 + 5);
          v38[6] = *((_OWORD *)v39 + 6);
          v38 += 8;
          *(v38 - 1) = *((_OWORD *)v39 + 7);
          v39 += 32;
          --v40;
        }
        while ( v40 );
      }
      Illusion::ITexturePlat::Unlock(v37);
    }
    ++v35;
    ++v36;
  }
  while ( v35 < v6->mNumFogTextures );
  return (UFG::qTask *)v42;
}

// File Line: 709
// RVA: 0x6AA60
Illusion::Texture *__fastcall UFG::TimeOfDayManager::GetFogTexture(UFG::TimeOfDayManager *this)
{
  return this->mFogCubeTexture[gPCFogRenderBuffer];
}

// File Line: 714
// RVA: 0x6BA60
void __fastcall UFG::TimeOfDayManager::SetFogSlicingMode(UFG::TimeOfDayManager *this, int updateInterval)
{
  this->mFogUpdateInterval = updateInterval;
  this->mCurrStartSlice = 0;
  this->mCurrEndSlice = 32u / (8 * updateInterval);
  gPCFogUpdateBuffer = 0;
  gPCFogRenderBuffer = 0;
}

// File Line: 723
// RVA: 0x6B2A0
void __fastcall UFG::TimeOfDayManager::Init(UFG::TimeOfDayManager *this)
{
  UFG::TimeOfDayManager *v1; // rbx
  int v2; // eax
  UFG::TransformNodeComponent *v3; // rdi
  int v4; // ebp
  Illusion::Texture **v5; // rsi
  Illusion::Texture *v6; // rax
  unsigned int v7; // eax
  UFG::qMemoryPool *v8; // rax
  char *v9; // rsi
  unsigned int v10; // eax
  UFG::TransformNodeComponent *v11; // rax
  UFG::qString result; // [rsp+58h] [rbp-30h]

  v1 = this;
  this->mNightFogZones = (NightFogZone *)UFG::qMalloc(0x10ui64, "NightFogZones", 0x1000ui64);
  v1->mSkySaturation = 1.0;
  v1->mSkyBoost = 1.0;
  v2 = Render::GetGPUCount();
  v1->mNumFogTextures = v2;
  v3 = 0i64;
  v4 = 0;
  if ( v2 > 0 )
  {
    v5 = v1->mFogCubeTexture;
    do
    {
      UFG::qString::FormatEx(&result, "FogTarget%d", (unsigned int)v4);
      v6 = Illusion::CreateTexture3D(result.mData, 32, 32, 32, 0, 0x440500u, 1, 0, 0);
      *v5 = v6;
      v7 = Illusion::Texture::GetSamplerAddressFlags(v6);
      Illusion::Texture::SetSamplerState(*v5, 1u, v7 & 0xFFFFFFFE | 2);
      UFG::qString::~qString(&result);
      ++v4;
      ++v5;
    }
    while ( v4 < v1->mNumFogTextures );
  }
  v8 = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(v8, 0x110ui64, "m_SunFxTransform", 0i64, 1u);
  if ( v9 )
  {
    v10 = UFG::qStringHashUpper32("SunTransform", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v9, v10, 0i64, 0);
    v3 = v11;
  }
  v1->m_SunFxTransform = v3;
  v1->m_GameSecondsPerRealSecond = 40.0;
}

// File Line: 823
// RVA: 0x69E00
void __fastcall UFG::ApplyColorFixup(float *rgbis, bool convert_to_linear)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm6_4
  float v5; // xmm5_4
  float v6; // xmm2_4
  float v7; // xmm6_4
  float v8; // xmm2_4
  float v9; // xmm4_4
  float v10; // xmm3_4

  if ( convert_to_linear )
  {
    v2 = rgbis[1] * rgbis[1];
    v3 = rgbis[2] * rgbis[2];
    *rgbis = *rgbis * *rgbis;
    rgbis[1] = v2;
    rgbis[2] = v3;
  }
  v4 = rgbis[3];
  v5 = rgbis[4];
  v6 = v4;
  v7 = v4 * rgbis[2];
  v8 = v6 * *rgbis;
  v9 = rgbis[3] * rgbis[1];
  v10 = (float)((float)(v9 * 0.60000002) + (float)(v8 * 0.30000001)) + (float)(v7 * 0.1);
  rgbis[2] = (float)((float)(v7 - v10) * v5) + v10;
  *rgbis = (float)((float)(v8 - v10) * v5) + v10;
  rgbis[1] = (float)((float)(v9 - v10) * v5) + v10;
}

// File Line: 849
// RVA: 0x6B480
void __fastcall UFG::LerpRGBIS(float *rgbis_dest, unsigned int index, Illusion::StateBlock *state_block0, Illusion::StateBlock *state_block1, Illusion::StateBlock *state_block2, float time, float lerp_t1, float lerp_t2)
{
  Illusion::StateBlock *v8; // rbp
  __int64 v9; // r12
  Illusion::StateBlock *v10; // r14
  unsigned int v11; // esi
  __int64 v12; // r13
  __int64 v13; // r11
  signed __int64 v14; // r15
  signed __int64 v15; // r8
  char *v16; // rdx
  char *v17; // r10
  float *v18; // r9
  int v19; // er8
  float *v20; // rcx
  __int64 v21; // r8
  float *v22; // rax
  float v23; // xmm3_4
  unsigned int v24; // edx
  int v25; // er8
  float *v26; // rcx
  __int64 v27; // r8
  float *v28; // rax
  float v29; // xmm3_4
  unsigned int v30; // edx
  float *v31; // rcx
  __int64 v32; // r8
  float *v33; // rax
  unsigned int v34; // edx
  float v35; // xmm2_4
  float v36; // xmm6_4
  float v37; // xmm7_4
  float v38; // xmm8_4
  float v39; // xmm14_4
  float v40; // xmm2_4
  float v41; // xmm12_4
  float v42; // xmm14_4
  float v43; // xmm15_4
  float v44; // xmm10_4
  float v45; // xmm13_4
  float v46; // xmm11_4
  float v47; // xmm2_4
  float v48; // xmm10_4
  float v49; // xmm11_4
  float v50; // xmm12_4
  float v51; // xmm14_4
  float v52; // xmm15_4
  float v53; // xmm13_4
  float v54; // xmm10_4
  float v55; // [rsp+0h] [rbp-118h]
  float v56; // [rsp+4h] [rbp-114h]
  float v57; // [rsp+8h] [rbp-110h]
  float v58; // [rsp+Ch] [rbp-10Ch]
  float v59; // [rsp+10h] [rbp-108h]
  float v60; // [rsp+18h] [rbp-100h]
  float v61; // [rsp+1Ch] [rbp-FCh]
  float v62; // [rsp+20h] [rbp-F8h]
  float v63; // [rsp+24h] [rbp-F4h]
  float v64; // [rsp+28h] [rbp-F0h]
  float v65; // [rsp+30h] [rbp-E8h]
  float v66; // [rsp+34h] [rbp-E4h]
  float v67; // [rsp+38h] [rbp-E0h]
  float v68; // [rsp+3Ch] [rbp-DCh]
  float v69; // [rsp+40h] [rbp-D8h]
  float *v70; // [rsp+120h] [rbp+8h]

  v70 = rgbis_dest;
  v8 = state_block1;
  v9 = (state_block0->mDataByteSize + 0xF) & 0xFFFFFFF0;
  v10 = state_block0;
  v11 = index;
  v12 = (state_block1->mDataByteSize + 15) & 0xFFFFFFF0;
  v13 = 0i64;
  v14 = 5i64;
  do
  {
    v15 = 4i64 * v11 + 128;
    v16 = (char *)v10 + *(unsigned __int16 *)((char *)&v10->mNode.mParent + v9 + v15);
    v17 = (char *)v8 + *(unsigned __int16 *)((char *)&v8->mNode.mParent + v15 + v12);
    if ( state_block2 )
      v18 = (float *)((char *)state_block2[1].mNode.mChild
                    + *(unsigned __int16 *)((char *)&state_block2->mNode.mParent
                                          + v15
                                          + ((state_block2->mDataByteSize + 15) & 0xFFFFFFF0)));
    else
      v18 = 0i64;
    v19 = *((_DWORD *)v16 + 32);
    if ( !v19 )
      goto LABEL_13;
    v20 = (float *)(v16 + 132);
    v21 = (unsigned int)(v19 - 1);
    v22 = (float *)(v16 + 140);
    if ( time <= *((float *)v16 + 33) )
    {
      v23 = *((float *)v16 + 34);
      goto LABEL_14;
    }
    if ( time >= *(float *)&v16[8 * v21 + 132] )
    {
      v23 = *(float *)&v16[8 * v21 + 136];
      goto LABEL_14;
    }
    v24 = 0;
    if ( (_DWORD)v21 )
    {
      while ( time > *v22 )
      {
        ++v24;
        v20 += 2;
        v22 += 2;
        if ( v24 >= (unsigned int)v21 )
          goto LABEL_13;
      }
      v23 = (float)((float)((float)(time - *v20) / (float)(*v22 - *v20)) * (float)(v22[1] - v20[1])) + v20[1];
    }
    else
    {
LABEL_13:
      v23 = 0.0;
    }
LABEL_14:
    v25 = *((_DWORD *)v17 + 32);
    *(float *)((char *)&v55 + v13) = v23;
    if ( !v25 )
      goto LABEL_23;
    v26 = (float *)(v17 + 132);
    v27 = (unsigned int)(v25 - 1);
    v28 = (float *)(v17 + 140);
    if ( time > *((float *)v17 + 33) )
    {
      if ( time < *(float *)&v17[8 * v27 + 132] )
      {
        v30 = 0;
        if ( (_DWORD)v27 )
        {
          while ( time > *v28 )
          {
            ++v30;
            v26 += 2;
            v28 += 2;
            if ( v30 >= (unsigned int)v27 )
              goto LABEL_23;
          }
          v29 = (float)((float)((float)(time - *v26) / (float)(*v28 - *v26)) * (float)(v28[1] - v26[1])) + v26[1];
          goto LABEL_24;
        }
LABEL_23:
        v29 = 0.0;
        goto LABEL_24;
      }
      v29 = *(float *)&v17[8 * v27 + 136];
    }
    else
    {
      v29 = *((float *)v17 + 34);
    }
LABEL_24:
    *(float *)((char *)&v60 + v13) = v29;
    if ( !v18 )
      goto LABEL_35;
    if ( !*(_DWORD *)v18 )
      goto LABEL_34;
    v31 = v18 + 1;
    v32 = (unsigned int)(*(_DWORD *)v18 - 1);
    v33 = v18 + 3;
    if ( time <= v18[1] )
    {
      v29 = v18[2];
      goto LABEL_35;
    }
    if ( time >= v18[2 * v32 + 1] )
    {
      v29 = v18[2 * v32 + 2];
      goto LABEL_35;
    }
    v34 = 0;
    if ( *(_DWORD *)v18 != 1 )
    {
      while ( time > *v33 )
      {
        ++v34;
        v31 += 2;
        v33 += 2;
        if ( v34 >= (unsigned int)v32 )
          goto LABEL_34;
      }
      v29 = (float)((float)((float)(time - *v31) / (float)(*v33 - *v31)) * (float)(v33[1] - v31[1])) + v31[1];
    }
    else
    {
LABEL_34:
      v29 = 0.0;
    }
LABEL_35:
    *(float *)((char *)&v65 + v13) = v29;
    v13 += 4i64;
    ++v11;
    --v14;
  }
  while ( v14 );
  v35 = (float)((float)((float)((float)(v56 * v56) * v58) * 0.60000002)
              + (float)((float)((float)(v55 * v55) * v58) * 0.30000001))
      + (float)((float)((float)(v57 * v57) * v58) * 0.1);
  v36 = (float)((float)((float)((float)(v55 * v55) * v58) - v35) * v59) + v35;
  v37 = (float)((float)((float)((float)(v56 * v56) * v58) - v35) * v59) + v35;
  v38 = (float)((float)((float)((float)(v57 * v57) * v58) - v35) * v59) + v35;
  v39 = v63 * (float)(v60 * v60);
  v40 = (float)((float)((float)(v63 * (float)(v61 * v61)) * 0.60000002) + (float)(v39 * 0.30000001))
      + (float)((float)(v63 * (float)(v62 * v62)) * 0.1);
  v41 = v68 * (float)(v66 * v66);
  v42 = (float)((float)(v39 - v40) * v64) + v40;
  v43 = (float)((float)((float)(v63 * (float)(v61 * v61)) - v40) * v64) + v40;
  v44 = v68 * (float)(v67 * v67);
  v45 = (float)((float)((float)(v63 * (float)(v62 * v62)) - v40) * v64) + v40;
  v46 = v68 * (float)(v65 * v65);
  v47 = (float)((float)(v41 * 0.60000002) + (float)(v46 * 0.30000001)) + (float)(v44 * 0.1);
  v48 = (float)(v44 - v47) * v69;
  v49 = (float)((float)(v46 - v47) * v69) + v47;
  v50 = (float)((float)(v41 - v47) * v69) + v47;
  v70[3] = 1.0;
  v70[4] = 1.0;
  v51 = (float)((float)(v42 - v36) * lerp_t1) + v36;
  v52 = (float)((float)(v43 - v37) * lerp_t1) + v37;
  v53 = (float)((float)(v45 - v38) * lerp_t1) + v38;
  *v70 = v51;
  v70[1] = v52;
  v70[2] = v53;
  v54 = v48 + v47;
  if ( lerp_t2 > 0.0 )
  {
    *v70 = (float)((float)(v49 - v51) * lerp_t2) + v51;
    v70[1] = (float)((float)(v50 - v52) * lerp_t2) + v52;
    v70[2] = (float)((float)(v54 - v53) * lerp_t2) + v53;
  }
}

// File Line: 882
// RVA: 0x6AB60
char __fastcall UFG::TimeOfDayManager::GetStateblockCurves(UFG::TimeOfDayManager *this, CB_EnvironmentSettings *envState, float *sbArray)
{
  Illusion::StateBlock *v3; // r14
  __int64 v4; // r10
  float *v5; // r15
  UFG::TimeOfDayManager *v6; // rbp
  float time; // xmm6_4
  char *v8; // r9
  int v9; // er8
  float *v10; // rdx
  __int64 v11; // r8
  float *v12; // rax
  float v13; // xmm3_4
  unsigned int v14; // ecx
  float v15; // xmm0_4
  Illusion::StateBlock *v16; // rsi
  Illusion::StateBlock *state_block2; // rdi
  float lerp_t1; // xmm8_4
  __int64 v19; // r10
  signed __int64 v20; // r11
  char *v21; // rcx
  int v22; // er8
  float *v23; // rdx
  __int64 v24; // r8
  float *v25; // rax
  float v26; // xmm3_4
  unsigned int v27; // ecx
  float v28; // xmm4_4
  char *v29; // rcx
  int v30; // er8
  float *v31; // rdx
  __int64 v32; // r8
  float *v33; // rax
  float v34; // xmm3_4
  unsigned int v35; // ecx

  v3 = (Illusion::StateBlock *)this->mSunnyStateBlockHandle.mData;
  v4 = 0i64;
  v5 = sbArray;
  v6 = this;
  time = this->m_SecondsSinceMidnight * 0.000011574074;
  if ( v3->mNumValues )
  {
    do
    {
      v8 = (char *)v3
         + *(unsigned __int16 *)((char *)v3[1].mNode.mChild + 4 * v4 + ((v3->mDataByteSize + 15) & 0xFFFFFFF0));
      v9 = *((_DWORD *)v8 + 32);
      if ( !v9 )
        goto LABEL_10;
      v10 = (float *)(v8 + 132);
      v11 = (unsigned int)(v9 - 1);
      v12 = (float *)(v8 + 140);
      if ( time > *((float *)v8 + 33) )
      {
        if ( time < *(float *)&v8[8 * v11 + 132] )
        {
          v14 = 0;
          if ( (_DWORD)v11 )
          {
            while ( time > *v12 )
            {
              ++v14;
              v10 += 2;
              v12 += 2;
              if ( v14 >= (unsigned int)v11 )
                goto LABEL_10;
            }
            v13 = (float)((float)((float)(time - *v10) / (float)(*v12 - *v10)) * (float)(v12[1] - v10[1])) + v10[1];
            goto LABEL_11;
          }
LABEL_10:
          v13 = 0.0;
          goto LABEL_11;
        }
        v13 = *(float *)&v8[8 * v11 + 136];
      }
      else
      {
        v13 = *((float *)v8 + 34);
      }
LABEL_11:
      gCurrentSunnyEnvironment[v4] = v13;
      v4 = (unsigned int)(v4 + 1);
    }
    while ( (unsigned int)v4 < v3->mNumValues );
  }
  v15 = v6->m_WeatherState;
  v16 = (Illusion::StateBlock *)v6->mOvercastStateBlockHandle.mData;
  state_block2 = (Illusion::StateBlock *)v6->mOverrideStateBlockHandle.mData;
  if ( v15 <= 0.0 )
  {
    v15 = 0.0;
  }
  else
  {
    lerp_t1 = *(float *)&FLOAT_1_0;
    if ( v15 >= 1.0 )
      goto LABEL_18;
  }
  lerp_t1 = v15;
LABEL_18:
  v19 = 0i64;
  do
  {
    if ( (_DWORD)v19 == 6 )
    {
      UFG::LerpRGBIS(v5 + 6, 6u, v3, v16, state_block2, time, lerp_t1, v6->m_OverrideStateBlockAmount);
      LODWORD(v19) = 10;
      goto LABEL_43;
    }
    v20 = 4 * v19 + 128;
    v21 = (char *)v16
        + *(unsigned __int16 *)((char *)&v16->mNode.mParent + v20 + ((v16->mDataByteSize + 15) & 0xFFFFFFF0));
    v22 = *((_DWORD *)v21 + 32);
    if ( !v22 )
    {
LABEL_29:
      v26 = 0.0;
      goto LABEL_30;
    }
    v23 = (float *)(v21 + 132);
    v24 = (unsigned int)(v22 - 1);
    v25 = (float *)(v21 + 140);
    if ( time > *((float *)v21 + 33) )
    {
      if ( time < *(float *)&v21[8 * v24 + 132] )
      {
        v27 = 0;
        if ( !(_DWORD)v24 )
          goto LABEL_29;
        while ( time > *v25 )
        {
          ++v27;
          v23 += 2;
          v25 += 2;
          if ( v27 >= (unsigned int)v24 )
            goto LABEL_29;
        }
        v26 = (float)((float)((float)(time - *v23) / (float)(*v25 - *v23)) * (float)(v25[1] - v23[1])) + v23[1];
      }
      else
      {
        v26 = *(float *)&v21[8 * v24 + 136];
      }
    }
    else
    {
      v26 = *((float *)v21 + 34);
    }
LABEL_30:
    v5[v19] = (float)((float)(v26 - gCurrentSunnyEnvironment[v19]) * lerp_t1) + gCurrentSunnyEnvironment[v19];
    if ( state_block2 )
    {
      v28 = v6->m_OverrideStateBlockAmount;
      if ( v28 > 0.0 )
      {
        v29 = (char *)state_block2
            + *(unsigned __int16 *)((char *)&state_block2->mNode.mParent
                                  + v20
                                  + ((state_block2->mDataByteSize + 15) & 0xFFFFFFF0));
        v30 = *((_DWORD *)v29 + 32);
        if ( v30 )
        {
          v31 = (float *)(v29 + 132);
          v32 = (unsigned int)(v30 - 1);
          v33 = (float *)(v29 + 140);
          if ( time <= *((float *)v29 + 33) )
          {
            v34 = *((float *)v29 + 34);
LABEL_42:
            v5[v19] = (float)((float)(v34 - gCurrentSunnyEnvironment[v19]) * v28) + gCurrentSunnyEnvironment[v19];
            goto LABEL_43;
          }
          if ( time >= *(float *)&v29[8 * v32 + 132] )
          {
            v34 = *(float *)&v29[8 * v32 + 136];
            goto LABEL_42;
          }
          v35 = 0;
          if ( (_DWORD)v32 )
          {
            while ( time > *v33 )
            {
              ++v35;
              v31 += 2;
              v33 += 2;
              if ( v35 >= (unsigned int)v32 )
                goto LABEL_41;
            }
            v34 = (float)((float)((float)(time - *v31) / (float)(*v33 - *v31)) * (float)(v33[1] - v31[1])) + v31[1];
            goto LABEL_42;
          }
        }
LABEL_41:
        v34 = 0.0;
        goto LABEL_42;
      }
    }
LABEL_43:
    v19 = (unsigned int)(v19 + 1);
  }
  while ( (unsigned int)v19 < 0x5D );
  return 1;
}

// File Line: 925
// RVA: 0x6AAC0
float __fastcall UFG::TimeOfDayManager::GetMinimumNightFogValue(float secondsSinceMidnight)
{
  float result; // xmm0_4

  if ( secondsSinceMidnight < 18000.0 )
    goto LABEL_11;
  if ( secondsSinceMidnight < 21600.0 )
    return (float)((float)((float)(1.0 - gMinimumNightFog) * 0.00027777778) * (float)(secondsSinceMidnight - 18000.0))
         + gMinimumNightFog;
  if ( secondsSinceMidnight < 64800.0 )
    return *(float *)&FLOAT_1_0;
  if ( secondsSinceMidnight >= 68400.0 )
LABEL_11:
    result = gMinimumNightFog;
  else
    result = (float)((float)((float)(gMinimumNightFog - 1.0) * 0.00027777778) * (float)(secondsSinceMidnight - 64800.0))
           + 1.0;
  return result;
}

// File Line: 972
// RVA: 0x69EC0
void __fastcall UFG::TimeOfDayManager::GetEnvironmentSettings(UFG::TimeOfDayManager *this, CB_EnvironmentSettings *envState, Render::ViewSettings *pViewSettings, CB_SkySettings *skyState)
{
  Render::ViewSettings *v4; // r14
  CB_SkySettings *v5; // rsi
  CB_EnvironmentSettings *v6; // rbx
  UFG::TimeOfDayManager *v7; // rdi
  float v8; // xmm1_4
  float v9; // xmm8_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm4_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm3_4
  float v19; // xmm3_4
  float v20; // xmm2_4
  float v21; // xmm13_4
  float v22; // xmm14_4
  float v23; // xmm15_4
  float v24; // xmm2_4
  float v25; // xmm2_4
  float v26; // xmm10_4
  float v27; // xmm11_4
  float v28; // xmm12_4
  float v29; // xmm2_4
  float v30; // xmm2_4
  float v31; // xmm2_4
  float v32; // xmm7_4
  float v33; // xmm1_4
  float v34; // xmm3_4
  float v35; // xmm2_4
  float v36; // xmm2_4
  float v37; // xmm1_4
  float v38; // xmm0_4
  float v39; // xmm3_4
  float v40; // xmm3_4
  float v41; // xmm2_4
  float v42; // xmm0_4
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm3_4
  float v46; // xmm2_4
  float v47; // xmm2_4
  int v48; // xmm0_4
  int v49; // xmm1_4
  float v50; // xmm3_4
  int v51; // xmm0_4
  float v52; // xmm2_4
  int v53; // xmm0_4
  int v54; // xmm1_4
  float v55; // xmm0_4
  float v56; // xmm3_4
  float v57; // xmm2_4
  float v58; // xmm2_4
  float v59; // xmm4_4
  float v60; // xmm1_4
  float v61; // xmm5_4
  int v62; // xmm1_4
  float v63; // xmm0_4
  float v64; // xmm1_4
  float v65; // xmm0_4
  float v66; // xmm1_4
  float v67; // xmm0_4
  float v68; // xmm0_4
  int v69; // xmm0_4
  float v70; // xmm2_4
  float v71; // xmm0_4
  int v72; // xmm0_4
  int v73; // xmm0_4
  float v74; // xmm1_4
  int v75; // xmm0_4
  float v76; // xmm2_4
  int v77; // xmm1_4
  float v78; // xmm2_4
  float v79; // xmm1_4
  int v80; // xmm0_4
  int v81; // xmm1_4
  int v82; // xmm0_4
  float v83; // xmm0_4
  float v84; // xmm1_4
  float v85; // xmm3_4
  int v86; // xmm2_4
  int v87; // xmm0_4
  float v88; // xmm1_4
  int v89; // xmm2_4
  int v90; // xmm0_4
  float v91; // xmm2_4
  int v92; // xmm0_4
  float v93; // [rsp+20h] [rbp-B8h]
  float v94; // [rsp+24h] [rbp-B4h]
  float v95; // [rsp+28h] [rbp-B0h]
  float v96; // [rsp+2Ch] [rbp-ACh]
  float v97; // [rsp+30h] [rbp-A8h]
  float v98; // [rsp+34h] [rbp-A4h]
  float v99; // [rsp+38h] [rbp-A0h]
  float v100; // [rsp+3Ch] [rbp-9Ch]
  float sbArray; // [rsp+50h] [rbp-88h]
  int v102; // [rsp+54h] [rbp-84h]
  float dest; // [rsp+58h] [rbp-80h]
  float v104; // [rsp+5Ch] [rbp-7Ch]
  int v105; // [rsp+60h] [rbp-78h]
  float v106; // [rsp+64h] [rbp-74h]
  float v107; // [rsp+68h] [rbp-70h]
  float v108; // [rsp+6Ch] [rbp-6Ch]
  float v109; // [rsp+70h] [rbp-68h]
  float v110; // [rsp+74h] [rbp-64h]
  float v111; // [rsp+78h] [rbp-60h]
  float v112; // [rsp+7Ch] [rbp-5Ch]
  float v113; // [rsp+80h] [rbp-58h]
  float v114; // [rsp+84h] [rbp-54h]
  float v115; // [rsp+88h] [rbp-50h]
  float v116; // [rsp+8Ch] [rbp-4Ch]
  float v117; // [rsp+90h] [rbp-48h]
  float v118; // [rsp+94h] [rbp-44h]
  float v119; // [rsp+98h] [rbp-40h]
  float v120; // [rsp+9Ch] [rbp-3Ch]
  float v121; // [rsp+A0h] [rbp-38h]
  float v122; // [rsp+A4h] [rbp-34h]
  float v123; // [rsp+A8h] [rbp-30h]
  float v124; // [rsp+ACh] [rbp-2Ch]
  float v125; // [rsp+B0h] [rbp-28h]
  float v126; // [rsp+B4h] [rbp-24h]
  float v127; // [rsp+B8h] [rbp-20h]
  float v128; // [rsp+BCh] [rbp-1Ch]
  float v129; // [rsp+C0h] [rbp-18h]
  float v130; // [rsp+C4h] [rbp-14h]
  float v131; // [rsp+C8h] [rbp-10h]
  float v132; // [rsp+CCh] [rbp-Ch]
  float v133; // [rsp+D0h] [rbp-8h]
  int v134; // [rsp+D4h] [rbp-4h]
  int v135; // [rsp+D8h] [rbp+0h]
  int v136; // [rsp+DCh] [rbp+4h]
  int v137; // [rsp+E0h] [rbp+8h]
  float v138; // [rsp+E4h] [rbp+Ch]
  float v139; // [rsp+E8h] [rbp+10h]
  float v140; // [rsp+ECh] [rbp+14h]
  float v141; // [rsp+F0h] [rbp+18h]
  float v142; // [rsp+F4h] [rbp+1Ch]
  int v143; // [rsp+F8h] [rbp+20h]
  float v144; // [rsp+FCh] [rbp+24h]
  float v145; // [rsp+100h] [rbp+28h]
  int v146; // [rsp+104h] [rbp+2Ch]
  int v147; // [rsp+108h] [rbp+30h]
  float v148; // [rsp+10Ch] [rbp+34h]
  float v149; // [rsp+114h] [rbp+3Ch]
  int v150; // [rsp+118h] [rbp+40h]
  float v151; // [rsp+11Ch] [rbp+44h]
  int v152; // [rsp+120h] [rbp+48h]
  int v153; // [rsp+124h] [rbp+4Ch]
  int v154; // [rsp+128h] [rbp+50h]
  int v155; // [rsp+12Ch] [rbp+54h]
  float v156; // [rsp+130h] [rbp+58h]
  float v157; // [rsp+134h] [rbp+5Ch]
  float v158; // [rsp+138h] [rbp+60h]
  float v159; // [rsp+13Ch] [rbp+64h]
  float v160; // [rsp+140h] [rbp+68h]
  float v161; // [rsp+144h] [rbp+6Ch]
  float v162; // [rsp+148h] [rbp+70h]
  float v163; // [rsp+14Ch] [rbp+74h]
  float v164; // [rsp+150h] [rbp+78h]
  float v165; // [rsp+154h] [rbp+7Ch]
  float v166; // [rsp+158h] [rbp+80h]
  float v167; // [rsp+15Ch] [rbp+84h]
  float v168; // [rsp+160h] [rbp+88h]
  float v169; // [rsp+164h] [rbp+8Ch]
  int v170; // [rsp+168h] [rbp+90h]
  float v171; // [rsp+16Ch] [rbp+94h]
  int v172; // [rsp+170h] [rbp+98h]
  int v173; // [rsp+174h] [rbp+9Ch]
  float v174; // [rsp+178h] [rbp+A0h]
  float v175; // [rsp+17Ch] [rbp+A4h]
  float v176; // [rsp+180h] [rbp+A8h]
  float v177; // [rsp+184h] [rbp+ACh]
  int v178; // [rsp+188h] [rbp+B0h]
  int v179; // [rsp+18Ch] [rbp+B4h]
  float v180; // [rsp+190h] [rbp+B8h]
  float v181; // [rsp+278h] [rbp+1A0h]
  float v182; // [rsp+280h] [rbp+1A8h]
  float v183; // [rsp+288h] [rbp+1B0h]
  float vars0; // [rsp+290h] [rbp+1B8h]

  v4 = pViewSettings;
  v5 = skyState;
  v6 = envState;
  v7 = this;
  UFG::TimeOfDayManager::GetStateblockCurves(this, envState, &sbArray);
  if ( UFG::gIsSkyIrradFog > 0.0 )
    UFG::qMemSet(&dest, 0, 0x58u);
  v8 = v157;
  v9 = *(float *)&FLOAT_1_0;
  v7->mTodEV = v157;
  if ( UFG::gIgnoreEnvSettingsExposure )
  {
    v10 = UFG::gOverrideExposure;
  }
  else
  {
    v11 = v8 + v7->mMeteringEV;
    if ( v11 > 1.0 )
      v11 = *(float *)&FLOAT_1_0;
    v10 = (float)(v11 + UFG::gOverrideExposure) + v7->mVisualTreatmentEV;
  }
  v12 = powf(2.0, v10);
  v13 = v107;
  v14 = v108;
  v15 = v12;
  v16 = v12;
  v17 = v109;
  v7->mExposure = v15;
  v18 = (float)(v16 * UFG::gAmbientBoost) * v7->mGlobalIlluminationBlend;
  v107 = v13 * v18;
  v109 = v17 * v18;
  v108 = v14 * v18;
  v104 = v104 * (float)(v15 * UFG::gSunBoost);
  v106 = v106 * UFG::gEmissiveBoost;
  v116 = v116 * v15;
  v121 = v121 * v15;
  v126 = v126 * v15;
  v132 = v132 * v15;
  v128 = v128 * v15;
  UFG::ApplyColorFixup(&sbArray, 1);
  v19 = (float)((float)((float)(v109 * v111) * 0.60000002) + (float)((float)(v111 * v108) * 0.30000001))
      + (float)((float)(v110 * v111) * 0.1);
  v100 = (float)((float)((float)(v111 * v108) - v19) * v112) + v19;
  v108 = (float)((float)((float)(v111 * v108) - v19) * v112) + v19;
  v109 = (float)((float)((float)(v109 * v111) - v19) * v112) + v19;
  v110 = (float)((float)((float)(v110 * v111) - v19) * v112) + v19;
  v20 = (float)((float)((float)(v114 * v116) * 0.60000002) + (float)((float)(v113 * v116) * 0.30000001))
      + (float)((float)(v115 * v116) * 0.1);
  v21 = (float)((float)((float)(v113 * v116) - v20) * v117) + v20;
  v22 = (float)((float)((float)(v114 * v116) - v20) * v117) + v20;
  v23 = (float)((float)((float)(v115 * v116) - v20) * v117) + v20;
  v113 = (float)((float)((float)(v113 * v116) - v20) * v117) + v20;
  v114 = (float)((float)((float)(v114 * v116) - v20) * v117) + v20;
  v115 = (float)((float)((float)(v115 * v116) - v20) * v117) + v20;
  v24 = (float)((float)((float)(v119 * v121) * 0.60000002) + (float)((float)(v118 * v121) * 0.30000001))
      + (float)((float)(v120 * v121) * 0.1);
  v94 = (float)((float)((float)(v120 * v121) - v24) * v122) + v24;
  v120 = (float)((float)((float)(v120 * v121) - v24) * v122) + v24;
  v99 = (float)((float)((float)(v118 * v121) - v24) * v122) + v24;
  v118 = (float)((float)((float)(v118 * v121) - v24) * v122) + v24;
  v97 = (float)((float)((float)(v119 * v121) - v24) * v122) + v24;
  v119 = (float)((float)((float)(v119 * v121) - v24) * v122) + v24;
  v25 = (float)((float)((float)(v124 * v126) * 0.60000002) + (float)((float)(v123 * v126) * 0.30000001))
      + (float)((float)(v125 * v126) * 0.1);
  v123 = (float)((float)((float)(v123 * v126) - v25) * v127) + v25;
  v26 = v123;
  v124 = (float)((float)((float)(v124 * v126) - v25) * v127) + v25;
  v27 = v124;
  v125 = (float)((float)((float)(v125 * v126) - v25) * v127) + v25;
  v28 = v125;
  v29 = (float)((float)((float)(v130 * v132) * 0.60000002) + (float)((float)(v129 * v132) * 0.30000001))
      + (float)((float)(v131 * v132) * 0.1);
  v182 = (float)((float)((float)(v130 * v132) - v29) * v133) + v29;
  v130 = (float)((float)((float)(v130 * v132) - v29) * v133) + v29;
  v95 = (float)((float)((float)(v129 * v132) - v29) * v133) + v29;
  v129 = (float)((float)((float)(v129 * v132) - v29) * v133) + v29;
  v183 = (float)((float)((float)(v131 * v132) - v29) * v133) + v29;
  v131 = (float)((float)((float)(v131 * v132) - v29) * v133) + v29;
  v30 = (float)((float)((float)(v139 * v141) * 0.60000002) + (float)((float)(v138 * v141) * 0.30000001))
      + (float)((float)(v140 * v141) * 0.1);
  vars0 = (float)((float)((float)(v139 * v141) - v30) * v142) + v30;
  v139 = (float)((float)((float)(v139 * v141) - v30) * v142) + v30;
  v96 = (float)((float)((float)(v138 * v141) - v30) * v142) + v30;
  v138 = (float)((float)((float)(v138 * v141) - v30) * v142) + v30;
  v181 = (float)((float)((float)(v140 * v141) - v30) * v142) + v30;
  v140 = (float)((float)((float)(v140 * v141) - v30) * v142) + v30;
  v31 = (float)((float)((float)(v124 * v128) * 0.60000002) + (float)((float)(v123 * v128) * 0.30000001))
      + (float)((float)(v125 * v128) * 0.1);
  v32 = (float)((float)((float)(v124 * v128) - v31) * v127) + v31;
  v98 = (float)((float)((float)(v123 * v128) - v31) * v127) + v31;
  v93 = (float)((float)((float)(v125 * v128) - v31) * v127) + v31;
  if ( v5 )
  {
    v33 = v169;
    v34 = v166 * v169;
    v35 = v167;
    v5->CloudColourBottom[2] = v168 * v169;
    v36 = v35 * v33;
    v37 = v165;
    v5->CloudColourBottom[3] = v171;
    v38 = v164 * v37;
    v5->CloudColourBottom[0] = v34;
    v39 = v162;
    v5->CloudColourBottom[1] = v36;
    v5->CloudColourMid[3] = 0.0;
    v40 = v39 * v37;
    v41 = v163;
    v5->CloudColourMid[2] = v38;
    v42 = v160;
    v43 = v41 * v37;
    v44 = v161;
    v5->CloudColourMid[0] = v40;
    v45 = v158 * v44;
    v5->CloudColourMid[1] = v43;
    v46 = v159;
    v5->CloudColourTop[2] = v42 * v44;
    v47 = v46 * v44;
    v48 = v170;
    v49 = v172;
    v5->CloudColourTop[0] = v45;
    v50 = v174;
    LODWORD(v5->CloudColourTop[3]) = v48;
    v51 = v173;
    v5->CloudColourTop[1] = v47;
    v52 = v175;
    LODWORD(v5->CloudShadingComponents[1]) = v51;
    v53 = v179;
    LODWORD(v5->CloudShadingComponents[0]) = v49;
    v54 = v178;
    LODWORD(v5->CloudShadingComponents[3]) = v53;
    v55 = v176;
    LODWORD(v5->CloudShadingComponents[2]) = v54;
    v5->CloudColourCeiling[3] = 0.0;
    v56 = v50 * v177;
    v57 = v52 * v177;
    v5->CloudColourCeiling[2] = v55 * v177;
    v5->CloudColourCeiling[0] = v56;
    v5->CloudColourCeiling[1] = v57;
  }
  v58 = v106;
  v59 = (float)((float)(v106 * 7.0) - 7.0) + 0.5;
  v60 = (float)((float)(v106 * 7.0) - 4.2000003) + 0.5;
  v61 = (float)((float)(v106 * 7.0) - 5.5999999) + 0.5;
  if ( v59 <= 0.0 )
  {
    v59 = 0.0;
  }
  else if ( v59 >= 1.0 )
  {
    v59 = *(float *)&FLOAT_1_0;
  }
  if ( v61 <= 0.0 )
  {
    v61 = 0.0;
  }
  else if ( v61 >= 1.0 )
  {
    v61 = *(float *)&FLOAT_1_0;
  }
  if ( v60 <= 0.0 )
  {
    v60 = 0.0;
    goto LABEL_22;
  }
  if ( v60 < 1.0 )
LABEL_22:
    v9 = v60;
  v62 = v102;
  v6->SunColor[0] = sbArray;
  LODWORD(v6->SunColor[1]) = v62;
  v6->SunColor[2] = dest;
  v63 = v107;
  v6->SunColor[3] = v106;
  v6->AmbientColorHorizon[0] = v63;
  v6->AmbientColorHorizon[1] = v108;
  v64 = v112;
  v6->AmbientColorHorizon[2] = v109;
  v6->AmbientColorHorizon[3] = v64;
  v65 = dest * gFogFudge;
  v66 = v107;
  v6->ScaleAndHeight[2] = v58;
  v6->ScaleAndHeight[0] = v65;
  v67 = v104;
  v6->ScaleAndHeight[3] = v66 * 0.0099999998;
  v6->ScaleAndHeight[1] = v67;
  v68 = 3.1415927 / UFG::gSunScatterHeight;
  v6->ScatterZenithColor[0] = v21 * 0.00028000001;
  v6->ScatterZenithColor[1] = v22 * 0.00028000001;
  v6->ScatterZenithColor[2] = v23 * 0.00028000001;
  v6->ScatterZenithColor[3] = v68;
  v6->ScatterHorizonColor[0] = v99 * 0.00028000001;
  v6->ScatterHorizonColor[1] = v97 * 0.00028000001;
  v6->ScatterHorizonColor[3] = v149;
  v69 = v137;
  v6->ScatterHorizonColor[2] = v94 * 0.00028000001;
  v70 = v182;
  LODWORD(v6->ScatterGroundColor[3]) = v69;
  v71 = v183 * 0.00028000001;
  v6->ScatterGroundColor[0] = v26 * 0.00028000001;
  v6->ScatterGroundColor[1] = v27 * 0.00028000001;
  v6->ScatterGroundColor[2] = v28 * 0.00028000001;
  v6->ScatterSunColor[2] = v71;
  v72 = v134;
  v6->ScatterSunColor[0] = v95 * 0.00028000001;
  LODWORD(v6->ScatterSunColor[3]) = v72;
  v73 = v143;
  v6->ScatterSunColor[1] = v70 * 0.00028000001;
  v6->CharacterParams[0] = v96;
  v6->CharacterParams[1] = vars0;
  v74 = v181;
  LODWORD(v6->CharacterParams[3]) = v73;
  v75 = v146;
  v6->CharacterParams[2] = v74;
  v76 = v7->m_WeatherSurfaceWetness;
  v77 = v147;
  LODWORD(v6->FogStartStopSky[0]) = v75;
  v6->FogStartStopSky[2] = v148;
  LODWORD(v6->FogStartStopSky[1]) = v77;
  v6->FogStartStopSky[3] = v76;
  v78 = v7->mExposure;
  v79 = v7->mExposure * v7->mSkyBoost;
  v6->DisplayDebug[2] = v7->mSkySaturation;
  v6->DisplayDebug[0] = v98 * 0.00028000001;
  v6->DisplayDebug[1] = v78;
  v6->DisplayDebug[3] = v79 * 1.3;
  v6->Lighting[0] = v7->mGlobalIlluminationBlend;
  v80 = v105;
  v6->Lighting[3] = v93 * 0.00028000001;
  v81 = v136;
  LODWORD(v6->Lighting[1]) = v80;
  v82 = v135;
  v6->Lighting[2] = v32 * 0.00028000001;
  LODWORD(v6->SunScatterParams[0]) = v82;
  v6->SunScatterParams[2] = v144;
  LODWORD(v6->SunScatterParams[1]) = v81;
  v6->SunScatterParams[3] = v145;
  v6->LitWindowTimeOn[3] = v100 * 0.0040000002;
  v6->LitWindowTimeOn[0] = v9;
  v6->LitWindowTimeOn[1] = v61;
  v6->LitWindowTimeOn[2] = v59;
  UFG::TimeOfDayManager::GetSunDir(v7, (UFG::qVector4 *)v6->SunDirWorld, 0, 0);
  if ( v4 )
    UFG::TimeOfDayManager::GetViewSpaceSunDir(v7, (UFG::qVector4 *)v6, v4);
  v83 = v7->mWindDirection.x;
  v84 = v7->mWindDirection.y;
  v85 = v7->mWindSpeed;
  v6->WindDirAndMag[2] = v7->mWindDirection.z;
  v86 = v153;
  v6->WindDirAndMag[0] = v83;
  v87 = v150;
  v6->WindDirAndMag[1] = v84;
  v88 = gBloomNearDistance;
  v6->WindDirAndMag[3] = v85;
  LODWORD(v7->mBloomFarDistance) = v86;
  v89 = v154;
  LODWORD(v7->mBloomNearThreshold) = v87;
  v90 = v152;
  LODWORD(v7->mBloomSaturation) = v89;
  v7->mProbeBoost = v156;
  LODWORD(v7->mBloomFarThreshold) = v90;
  v91 = 90.0 - v180;
  v7->mBloomBoost = v151;
  v92 = v155;
  v7->mBloomNearDistance = v88;
  LODWORD(v7->mProbeAttenDistance) = v92;
  UFG::qSphericalToCartesian(v7->mAmbientSkyDirection, 0.0, v91);
  UFG::qSphericalToCartesian(&v7->mAmbientSkyDirection[1], 120.0, 90.0 - v180);
  UFG::qSphericalToCartesian(&v7->mAmbientSkyDirection[2], 240.0, 90.0 - v180);
}

// File Line: 1100
// RVA: 0x6BC50
void __fastcall UFG::TimeOfDayManager::SetWind(UFG::TimeOfDayManager *this, float directionRadians, float speed)
{
  UFG::TimeOfDayManager *v3; // rbx
  float v4; // xmm0_4

  v3 = this;
  this->mWindDirectionTargetRadians = directionRadians;
  this->mWindDirectionRadians = directionRadians;
  this->mWindDirection.x = cosf(directionRadians);
  v4 = sinf(directionRadians);
  v3->mWindDirection.z = 0.0;
  v3->mWindDirection.y = v4;
  v3->mWindSpeedTarget = speed;
  v3->mWindSpeed = speed;
}

// File Line: 1115
// RVA: 0x6B270
void __fastcall UFG::TimeOfDayManager::GetWind(UFG::TimeOfDayManager *this, UFG::qVector3 *direction, float *speed)
{
  float v3; // xmm0_4
  float v4; // xmm1_4

  v3 = this->mWindDirection.y;
  v4 = this->mWindDirection.z;
  direction->x = this->mWindDirection.x;
  direction->y = v3;
  direction->z = v4;
  *speed = this->mWindSpeed;
}

// File Line: 1121
// RVA: 0x6B0F0
void __fastcall UFG::TimeOfDayManager::GetViewSpaceSunDir(UFG::TimeOfDayManager *this, UFG::qVector4 *out_sun_dir, Render::ViewSettings *pViewSettings)
{
  UFG::qVector4 *v3; // rdi
  Render::ViewSettings *v4; // rbx
  float v5; // xmm6_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  UFG::qVector4 dir; // [rsp+20h] [rbp-28h]

  v3 = out_sun_dir;
  v4 = pViewSettings;
  UFG::TimeOfDayManager::GetSunDir(this, &dir, 0, 0);
  v5 = (float)(dir.y * v4->mWorldView.v1.z) + (float)(dir.x * v4->mWorldView.v0.z);
  v6 = (float)(dir.y * v4->mWorldView.v1.y) + (float)(dir.x * v4->mWorldView.v0.y);
  v7 = dir.w;
  v8 = dir.z * v4->mWorldView.v2.z;
  v9 = dir.z * v4->mWorldView.v2.y;
  v3->x = (float)((float)(dir.y * v4->mWorldView.v1.x) + (float)(dir.x * v4->mWorldView.v0.x))
        + (float)(dir.z * v4->mWorldView.v2.x);
  v3->z = v5 + v8;
  v3->y = v6 + v9;
  v3->w = v7;
}

// File Line: 1133
// RVA: 0x6AEB0
void __fastcall UFG::TimeOfDayManager::GetSunDir(UFG::TimeOfDayManager *this, UFG::qVector4 *dir, bool bClampSunElevation, bool bUseQuantizedSeconds)
{
  bool v4; // di
  UFG::qVector4 *v5; // rbx
  float v6; // xmm8_4
  float v7; // xmm6_4
  float v8; // xmm7_4
  float v9; // xmm8_4
  float v10; // xmm9_4
  float v11; // xmm12_4
  float v12; // xmm13_4
  float v13; // xmm0_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm10_4
  float v18; // xmm0_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm9_4
  float v22; // xmm6_4
  float v23; // xmm0_4

  v4 = bClampSunElevation;
  v5 = dir;
  if ( bUseQuantizedSeconds )
    v6 = this->m_QuantizedSecondsSinceMidnight;
  else
    v6 = this->m_SecondsSinceMidnight;
  v7 = this->m_LocalLatitude;
  v8 = this->m_SunDeclination;
  v9 = (float)((float)(v6 - 43200.0) * 0.00027777778) * 0.2617994;
  v10 = cosf(this->m_LocalLatitude);
  v11 = sinf(v8);
  v12 = sinf(v7);
  v13 = cosf(v8);
  v14 = *(float *)&FLOAT_1_0;
  v15 = (float)((float)(v13 * cosf(v9)) * v10) + (float)(v12 * v11);
  if ( v15 <= -1.0 )
  {
    v15 = FLOAT_N1_0;
  }
  else if ( v15 >= 1.0 )
  {
    v15 = *(float *)&FLOAT_1_0;
  }
  v16 = asinf(v15);
  v17 = v16;
  if ( v4 && v16 <= 0.40000001 )
    v17 = FLOAT_0_40000001;
  v18 = sinf(v17);
  v19 = (float)((float)(v18 * v12) - v11) / (float)(cosf(v17) * v10);
  if ( v19 <= -1.0 )
  {
    v19 = FLOAT_N1_0;
    goto LABEL_15;
  }
  if ( v19 < 1.0 )
LABEL_15:
    v14 = v19;
  v20 = acosf(v14);
  v21 = v20;
  if ( v9 > 0.0 )
    v21 = v20 * -1.0;
  v22 = sinf(1.5707964 - v17);
  v5->x = cosf(v21) * v22;
  v5->y = sinf(v21) * v22;
  v23 = cosf(1.5707964 - v17);
  v5->w = 0.0;
  v5->z = v23;
}

// File Line: 1172
// RVA: 0x6B1B0
float __fastcall UFG::TimeOfDayManager::GetWeatherIntensityFromString(UFG::qString *weather)
{
  UFG::qString *v1; // rbx

  v1 = weather;
  if ( UFG::qString::operator==(weather, "sunny") )
    return 0.0;
  if ( UFG::qString::operator==(v1, "lightcloud") )
    return FLOAT_0_1;
  if ( UFG::qString::operator==(v1, "cloudy") )
    return *(float *)&FLOAT_1_0;
  if ( UFG::qString::operator==(v1, "lightrain") )
    return FLOAT_1_5;
  if ( UFG::qString::operator==(v1, "heavyrain") )
    return FLOAT_2_0;
  return FLOAT_N1_0;
}

// File Line: 1213
// RVA: 0x6B0A0
char __fastcall UFG::TimeOfDayManager::GetTimeInSeconds(float time, int *timeInSeconds)
{
  unsigned int v2; // er8
  char result; // al

  v2 = -100 * (signed int)time - (signed int)(float)(time * -100.0);
  if ( (unsigned int)(signed int)time > 0x18 || v2 > 0x3B )
    return 0;
  result = 1;
  *timeInSeconds = 60 * (v2 + 60 * (signed int)time);
  return result;
}

