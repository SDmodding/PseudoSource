// File Line: 224
// RVA: 0x6BA30
void __fastcall UFG::TimeOfDayManager::LockWeather(UFG::TimeOfDayManager *this, bool lock)
{
  int m_WeatherRandomInterval; // eax

  if ( lock )
  {
    m_WeatherRandomInterval = this->m_WeatherRandomInterval;
    if ( m_WeatherRandomInterval )
    {
      this->m_WeatherRandomIntervalPreLock = m_WeatherRandomInterval;
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
  int m_WeatherRandomInterval; // eax

  result = 1;
  if ( this->m_WeatherState <= 1.0 )
  {
    m_WeatherRandomInterval = this->m_WeatherRandomInterval;
    if ( m_WeatherRandomInterval <= 0
      || this->m_NextWeatherTarget <= 1.0
      || (float)((float)m_WeatherRandomInterval - UFG::TimeOfDayManager::ms_weather_interval) >= 40.0 )
    {
      return 0;
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
void __fastcall UFG::TimeOfDayManager::SetSurfaceWetnessOverride(
        UFG::TimeOfDayManager *this,
        float wetness,
        const char *desc)
{
  UFG::qPrintf("SetSurfaceWetnessOverride (%s) = %f\n", desc, wetness);
  this->m_OverrideSurfaceWetness = wetness;
}

// File Line: 287
// RVA: 0x6BCD0
void __fastcall UFG::TimeOfDayManager::Update(UFG::TimeOfDayManager *this, float fDelta)
{
  float v3; // xmm0_4
  float m_SecondsSinceMidnight; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  int m_WeatherRandomInterval; // eax
  float v8; // xmm1_4
  float v9; // xmm6_4
  float m_WeatherTarget; // xmm0_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float mWindDirectionRadians; // xmm0_4
  float mWindDirectionTargetRadians; // xmm1_4
  float v18; // xmm0_4
  float mWindSpeed; // xmm0_4
  float mWindSpeedTarget; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm6_4
  float v24; // xmm0_4
  float m_WeatherState; // xmm1_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm1_4
  float m_OverrideSurfaceWetness; // xmm0_4
  float m_WeatherSurfaceWetness; // xmm0_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  __m128 y_low; // xmm2
  float v35; // xmm1_4
  float x; // xmm9_4
  __int128 v37; // xmm11
  __m128 z_low; // xmm3
  float v39; // xmm4_4
  float v40; // xmm8_4
  float v41; // xmm5_4
  __int128 v42; // xmm10
  float v43; // xmm9_4
  __m128 v44; // xmm2
  float v45; // xmm1_4
  float v46; // xmm2_4
  __m128 v47; // xmm11
  float v48; // xmm3_4
  __m128 v49; // xmm9
  float v50; // xmm6_4
  float v51; // xmm0_4
  float y; // xmm1_4
  UFG::TransformNodeComponent *m_SunFxTransform; // rcx
  float z; // xmm2_4
  unsigned int v55; // eax
  unsigned int m_SunFx; // edx
  UFG::qVector4 dir; // [rsp+28h] [rbp-59h] BYREF
  UFG::qMatrix44 m; // [rsp+38h] [rbp-49h] BYREF
  float value; // [rsp+F0h] [rbp+6Fh] BYREF

  if ( UFG::gHoursSinceMidnight < 0.0 )
  {
    m_SecondsSinceMidnight = this->m_SecondsSinceMidnight;
    if ( m_SecondsSinceMidnight < 10800.0 || m_SecondsSinceMidnight > 75600.0 )
      v5 = FLOAT_1_33;
    else
      v5 = *(float *)&FLOAT_1_0;
    gPrevSecondsSinceMidnight = this->m_SecondsSinceMidnight;
    UFG::TimeOfDayManager::SetTime(
      this,
      (float)((float)(fDelta * this->m_GameSecondsPerRealSecond) * v5) + m_SecondsSinceMidnight,
      1);
  }
  else
  {
    v3 = fmodf(UFG::gHoursSinceMidnight * 3600.0, 86400.0);
    gDisabledQuantizedTime = 1;
    this->m_SecondsSinceMidnight = v3;
    this->m_QuantizedSecondsSinceMidnight = v3;
  }
  v6 = UFG::TimeOfDayManager::ms_weather_interval + (float)(gTOD_Speedhack * fDelta);
  UFG::TimeOfDayManager::ms_weather_interval = v6;
  m_WeatherRandomInterval = this->m_WeatherRandomInterval;
  if ( m_WeatherRandomInterval > 0 )
  {
    this->m_NextRainingInterval = this->m_NextRainingInterval - (float)(gTOD_Speedhack * fDelta);
    v6 = UFG::TimeOfDayManager::ms_weather_interval;
  }
  if ( gTriggerRandomWeatherTarget || m_WeatherRandomInterval > 0 && v6 > (float)m_WeatherRandomInterval )
  {
    this->m_WeatherTarget = this->m_NextWeatherTarget;
    gTriggerRandomWeatherTarget = 0;
    v8 = FLOAT_0_1;
    v9 = UFG::qRandom(1.0, &gRainSeed);
    m_WeatherTarget = this->m_WeatherTarget;
    if ( m_WeatherTarget >= 0.1 || v9 > 0.89999998 )
      this->m_NextWeatherTarget = 0.0;
    else
      this->m_NextWeatherTarget = 0.1;
    if ( this->m_PendingRain && m_WeatherTarget > 1.0 )
    {
      v11 = UFG::qRandom(gMaxNextRainInterval - gMinNextRainInterval, &UFG::qDefaultSeed);
      v8 = FLOAT_0_1;
      this->m_PendingRain = 0;
      this->m_NextRainingInterval = v11 + gMinNextRainInterval;
    }
    if ( this->m_NextRainingInterval < 0.0 )
    {
      if ( v9 >= v8 )
      {
        if ( v9 >= 0.40000001 )
          this->m_NextWeatherTarget = 1.25;
        else
          this->m_NextWeatherTarget = 1.75;
      }
      else
      {
        this->m_NextWeatherTarget = 2.0;
      }
      this->m_PendingRain = 1;
    }
    v12 = UFG::qRandom(6.2831855, &UFG::qDefaultSeed);
    v13 = this->m_WeatherTarget;
    this->mWindSpeedTarget = 0.75;
    this->mWindSpeed = 0.75;
    this->mWindDirectionTargetRadians = (float)(v12 + this->mWindDirectionRadians) - 3.1415927;
    Render::SkyMarshall::UpdateSkydomeTarget(&Render::SkyMarshall::gSkyMarshall, v13);
    UFG::TimeOfDayManager::ms_weather_interval = 0.0;
  }
  v14 = this->m_WeatherTarget;
  value = this->m_WeatherState;
  UFG::qApproach(&value, v14, gWeatherChangeStep, gTOD_Speedhack);
  v15 = value;
  if ( value <= *(float *)&dword_1421634FC )
    v15 = *(float *)&dword_1421634FC;
  this->m_WeatherState = v15;
  this->m_WeatherTarget = v14;
  if ( UFG::gWeatherState >= 0.0 )
    this->m_WeatherState = UFG::gWeatherState;
  mWindDirectionRadians = this->mWindDirectionRadians;
  mWindDirectionTargetRadians = this->mWindDirectionTargetRadians;
  if ( mWindDirectionRadians <= mWindDirectionTargetRadians )
  {
    if ( mWindDirectionRadians >= mWindDirectionTargetRadians )
      goto LABEL_37;
    v18 = mWindDirectionRadians + gWindChangeStep;
  }
  else
  {
    v18 = mWindDirectionRadians - gWindChangeStep;
  }
  this->mWindDirectionRadians = v18;
LABEL_37:
  if ( gWindDirectionTweakerRadians >= 0.0 )
    this->mWindDirectionRadians = gWindDirectionTweakerRadians;
  mWindSpeed = this->mWindSpeed;
  mWindSpeedTarget = this->mWindSpeedTarget;
  v21 = gWindSpeedChangeStep;
  if ( mWindSpeed > mWindSpeedTarget )
    this->mWindSpeed = mWindSpeed - gWindSpeedChangeStep;
  v22 = this->mWindSpeed;
  if ( v22 < mWindSpeedTarget )
    this->mWindSpeed = v22 + v21;
  if ( gWindSpeedTweaker >= 0.0 )
    this->mWindSpeed = gWindSpeedTweaker;
  v23 = this->mWindDirectionRadians;
  this->mWindDirection.x = cosf(v23);
  v24 = sinf(v23);
  this->mWindDirection.z = 0.0;
  this->mWindDirection.y = v24;
  m_WeatherState = this->m_WeatherState;
  if ( m_WeatherState <= 0.0 )
  {
    m_WeatherState = 0.0;
    goto LABEL_49;
  }
  v26 = FLOAT_2_0;
  if ( m_WeatherState < 2.0 )
LABEL_49:
    v26 = m_WeatherState;
  this->m_WeatherState = v26;
  if ( v26 <= 1.0 )
    v27 = gWeatherSurfaceDryingStep;
  else
    v27 = gWeatherSurfaceWetnessStep;
  v28 = v27 + this->m_WeatherSurfaceWetness;
  this->m_WeatherSurfaceWetness = v28;
  v29 = *(float *)&dword_142163500;
  if ( *(float *)&dword_142163500 <= v28 )
    v29 = v28;
  m_OverrideSurfaceWetness = this->m_OverrideSurfaceWetness;
  this->m_WeatherSurfaceWetness = v29;
  if ( m_OverrideSurfaceWetness >= 0.0 )
    this->m_WeatherSurfaceWetness = m_OverrideSurfaceWetness;
  m_WeatherSurfaceWetness = this->m_WeatherSurfaceWetness;
  if ( m_WeatherSurfaceWetness <= 0.0 )
  {
    m_WeatherSurfaceWetness = 0.0;
  }
  else if ( m_WeatherSurfaceWetness >= 1.0 )
  {
    m_WeatherSurfaceWetness = *(float *)&FLOAT_1_0;
  }
  v32 = gSurfaceWetness;
  this->m_WeatherSurfaceWetness = m_WeatherSurfaceWetness;
  if ( v32 >= 0.0 )
    this->m_WeatherSurfaceWetness = v32;
  v33 = this->m_SecondsSinceMidnight;
  if ( v33 < 21600.0 || v33 > 64800.0 )
  {
    m_SunFx = this->m_SunFx;
    if ( m_SunFx != -1 )
    {
      Render::FXManager::KillEffect(&Render::gFXManager, m_SunFx, FXKILLOPTION_DEFAULT);
      this->m_SunFx = -1;
    }
  }
  else
  {
    UFG::TimeOfDayManager::GetSunDir(this, &dir, 0, 0);
    y_low = (__m128)LODWORD(dir.y);
    y_low.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(dir.x * dir.x))
                      + (float)(dir.z * dir.z);
    if ( y_low.m128_f32[0] == 0.0 )
      v35 = 0.0;
    else
      v35 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
    x = UFG::qVector3::msAxisZ.x;
    v37 = LODWORD(UFG::qVector3::msAxisZ.y);
    z_low = (__m128)LODWORD(UFG::qVector3::msAxisZ.z);
    LODWORD(v39) = COERCE_UNSIGNED_INT(dir.x * v35) ^ _xmm[0];
    LODWORD(v40) = COERCE_UNSIGNED_INT(dir.z * v35) ^ _xmm[0];
    LODWORD(v41) = COERCE_UNSIGNED_INT(dir.y * v35) ^ _xmm[0];
    if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(
                        (float)((float)(v39 * UFG::qVector3::msAxisZ.x) + (float)(v41 * UFG::qVector3::msAxisZ.y))
                      + (float)(v40 * UFG::qVector3::msAxisZ.z)) & _xmm) > 0.99900001 )
    {
      x = UFG::qVector3::msAxisY.x;
      v37 = LODWORD(UFG::qVector3::msAxisY.y);
      z_low = (__m128)LODWORD(UFG::qVector3::msAxisY.z);
    }
    v42 = v37;
    *(float *)&v42 = (float)(*(float *)&v37 * v40) - (float)(z_low.m128_f32[0] * v41);
    z_low.m128_f32[0] = (float)(z_low.m128_f32[0] * v39) - (float)(x * v40);
    v43 = (float)(x * v41) - (float)(*(float *)&v37 * v39);
    v44 = z_low;
    v44.m128_f32[0] = (float)((float)(z_low.m128_f32[0] * z_low.m128_f32[0]) + (float)(*(float *)&v42 * *(float *)&v42))
                    + (float)(v43 * v43);
    if ( v44.m128_f32[0] == 0.0 )
      v45 = 0.0;
    else
      v45 = 1.0 / _mm_sqrt_ps(v44).m128_f32[0];
    *(float *)&v42 = *(float *)&v42 * v45;
    m.v0.w = 0.0;
    m.v0.z = v43 * v45;
    LODWORD(m.v0.x) = v42;
    m.v0.y = z_low.m128_f32[0] * v45;
    v47 = (__m128)v42;
    v46 = (float)((float)(v43 * v45) * v41) - (float)((float)(z_low.m128_f32[0] * v45) * v40);
    v47.m128_f32[0] = (float)(*(float *)&v42 * v40) - (float)((float)(v43 * v45) * v39);
    v48 = (float)((float)(z_low.m128_f32[0] * v45) * v39) - (float)(*(float *)&v42 * v41);
    v49 = v47;
    v49.m128_f32[0] = (float)((float)(v47.m128_f32[0] * v47.m128_f32[0]) + (float)(v46 * v46)) + (float)(v48 * v48);
    if ( v49.m128_f32[0] == 0.0 )
      v50 = 0.0;
    else
      v50 = 1.0 / _mm_sqrt_ps(v49).m128_f32[0];
    v51 = this->mCameraPosition.x;
    y = this->mCameraPosition.y;
    m_SunFxTransform = this->m_SunFxTransform;
    m.v1.w = 0.0;
    m.v2.w = 0.0;
    m.v1.x = v46 * v50;
    z = this->mCameraPosition.z;
    m.v2.x = v39;
    m.v3.w = 1.0;
    m.v3.z = z;
    m.v1.y = v47.m128_f32[0] * v50;
    m.v1.z = v48 * v50;
    m.v2.y = v41;
    m.v2.z = v40;
    m.v3.x = v51;
    m.v3.y = y;
    UFG::TransformNodeComponent::SetWorldTransform(m_SunFxTransform, &m);
    if ( this->m_SunFx == -1 )
    {
      v55 = UFG::qStringHashUpper32("Sun", 0xFFFFFFFF);
      this->m_SunFx = Render::FXManager::CreateEffect(
                        &Render::gFXManager,
                        v55,
                        this->m_SunFxTransform,
                        0xFFFFFFFF,
                        0i64);
    }
  }
}

// File Line: 482
// RVA: 0x6BAE0
void __fastcall UFG::TimeOfDayManager::SetTime(
        UFG::TimeOfDayManager *this,
        float secondsSinceMidnight,
        bool is_regular_update)
{
  float v5; // xmm0_4
  float v6; // xmm8_4
  float v7; // xmm9_4
  float v8; // xmm6_4
  float v9; // xmm6_4

  v5 = fmodf(secondsSinceMidnight, 86400.0);
  v6 = v5;
  this->m_SecondsSinceMidnight = v5;
  if ( is_regular_update )
  {
    v7 = fmodf(v5, 800.0);
    v8 = v7 - 700.0;
    if ( (float)(v7 - 700.0) <= 0.0 )
      v8 = 0.0;
    v9 = v8 * 0.01010101;
    if ( gDisabledQuantizedTime )
    {
      if ( this->m_GameSecondsPerRealSecond <= 0.0 || fmodf(gPrevSecondsSinceMidnight, 800.0) <= v7 )
      {
        this->m_QuantizedSecondsSinceMidnight = v6;
        return;
      }
      gDisabledQuantizedTime = 0;
    }
    this->m_QuantizedSecondsSinceMidnight = (float)(secondsSinceMidnight - v7) + (float)((float)(v9 * 100.0) * 8.0);
  }
  else
  {
    this->m_QuantizedSecondsSinceMidnight = v5;
    gDisabledQuantizedTime = 1;
  }
}

// File Line: 513
// RVA: 0x69AC0
void __fastcall UFG::TimeOfDayManager::TimeOfDayManager(UFG::TimeOfDayManager *this)
{
  float v2; // xmm0_4
  float v3; // xmm7_4

  this->m_WeatherRandomIntervalPreLock = 0;
  UFG::qResourceHandle::qResourceHandle(&this->mOverrideStateBlockHandle);
  this->m_DefaultGameSecondsPerRealSecond = 30.0;
  this->mNightFogZones = 0i64;
  UFG::qResourceHandle::qResourceHandle(&this->mSunnyStateBlockHandle);
  UFG::qResourceHandle::qResourceHandle(&this->mOvercastStateBlockHandle);
  *(_QWORD *)&this->mCameraPosition.x = 0i64;
  this->mCameraPosition.z = 0.0;
  this->m_GameSecondsPerRealSecond = 0.0;
  v2 = fmodf(0.0, 86400.0);
  this->m_SecondsSinceMidnight = v2;
  this->m_QuantizedSecondsSinceMidnight = v2;
  gDisabledQuantizedTime = 1;
  this->m_SunDeclination = sinf(7.4709659) * 0.40927973;
  *(_QWORD *)&this->m_WeatherState = 0i64;
  this->m_NextWeatherTarget = 0.0;
  this->m_WeatherRandomInterval = 180;
  this->mWindDirectionTargetRadians = 0.78539819;
  this->mWindDirectionRadians = 0.78539819;
  v3 = sinf(0.78539819);
  this->mWindDirection.x = cosf(0.78539819);
  this->mWindDirection.y = v3;
  this->mWindDirection.z = 0.0;
  this->mWindSpeedTarget = 0.75;
  this->mWindSpeed = 0.75;
  this->m_WeatherChanceOfPrecipitation = 0.15000001;
  this->m_WeatherSurfaceWetness = 0.0;
  this->m_LocalLatitude = 0.38397244;
  this->m_OverrideStateBlockAmount = 0.0;
  this->m_OverrideSurfaceWetness = -1.0;
  this->mNumFogTextures = 0;
  this->mFogCubeTexture[0] = 0i64;
  this->mFogCubeTexture[1] = 0i64;
  this->mFogCubeTexture[2] = 0i64;
  this->mFogCubeTexture[3] = 0i64;
  this->mCurrStartSlice = 0;
  this->mFogUpdateInterval = 1;
  this->mCurrEndSlice = 4;
  this->mGlobalIlluminationBlend = 1.0;
  UFG::qSphericalToCartesian(this->mAmbientSkyDirection, 0.0, 65.0);
  UFG::qSphericalToCartesian(&this->mAmbientSkyDirection[1], 120.0, 65.0);
  UFG::qSphericalToCartesian(&this->mAmbientSkyDirection[2], 240.0, 65.0);
  this->m_SunFxTransform = 0i64;
  this->m_SunFx = -1;
  this->m_NextRainingInterval = UFG::qRandom(gMaxNextRainInterval - gMinNextRainInterval, &UFG::qDefaultSeed)
                              + gMinNextRainInterval;
  this->m_PendingRain = 0;
}

// File Line: 553
// RVA: 0x69CE0
void __fastcall UFG::TimeOfDayManager::~TimeOfDayManager(UFG::TimeOfDayManager *this)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v3; // rax
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax
  Illusion::StateBlockHandle *p_mOverrideStateBlockHandle; // rbx
  UFG::qResourceInventory *v7; // rax
  UFG::qResourceWarehouse *v8; // rax

  operator delete[](this->mNightFogZones);
  Inventory = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v3 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v3, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(&this->mOvercastStateBlockHandle, Inventory);
  UFG::qResourceHandle::~qResourceHandle(&this->mOvercastStateBlockHandle);
  v4 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v4;
  }
  UFG::qResourceHandle::Close(&this->mSunnyStateBlockHandle, v4);
  UFG::qResourceHandle::~qResourceHandle(&this->mSunnyStateBlockHandle);
  p_mOverrideStateBlockHandle = &this->mOverrideStateBlockHandle;
  v7 = `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result;
  if ( !`UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result )
  {
    v8 = UFG::qResourceWarehouse::Instance();
    v7 = UFG::qResourceWarehouse::GetInventory(v8, 0x4D04C7F2u);
    `UFG::qGetResourceInventory<Illusion::StateBlock>::`2::result = v7;
  }
  UFG::qResourceHandle::Close(p_mOverrideStateBlockHandle, v7);
  UFG::qResourceHandle::~qResourceHandle(p_mOverrideStateBlockHandle);
}

// File Line: 558
// RVA: 0x6AA70
UFG::TimeOfDayManager *__fastcall UFG::TimeOfDayManager::GetInstance()
{
  if ( (_S1_12 & 1) == 0 )
  {
    _S1_12 |= 1u;
    UFG::TimeOfDayManager::TimeOfDayManager(&gManager);
    atexit(UFG::TimeOfDayManager::GetInstance_::_2_::_dynamic_atexit_destructor_for__gManager__);
  }
  return &gManager;
}

// File Line: 597
// RVA: 0x6C3F0
UFG::qTask *__fastcall UFG::TimeOfDayManager::UpdateFog(
        UFG::TimeOfDayManager *this,
        CB_EnvironmentSettings *settings,
        char bForceFullUpdate,
        bool nullOutput)
{
  char *v7; // r15
  volatile int mCurrStartSlice; // r13d
  Illusion::ITexturePlat *v9; // rbx
  _OWORD *v10; // rcx
  unsigned int *v11; // rdx
  __int64 v12; // rax
  __int64 v13; // rbx
  bool v14; // r14
  char *v15; // rax
  UFG::qList<UFG::qTaskGroup,UFG::qTaskGroup,0,0> *mSingleFrameTaskGroups; // rcx
  UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *mPrev; // rax
  unsigned int v18; // r12d
  __int64 v19; // rdi
  FogTaskParams *v20; // rbx
  float y; // xmm1_4
  float z; // xmm2_4
  float v23; // xmm0_4
  UFG::qTask *v24; // rax
  UFG::qTask *v25; // rdx
  UFG::qNode<UFG::qTask,UFG::TaskPlat> *v26; // rax
  UFG::qSpuElf *mSpuElf; // rax
  void (__fastcall *mTaskFunctionSPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r8
  void (__fastcall *mTaskFunctionPPU)(int, UFG::qMemoryStreamer *, void *, void *, void *, void *); // r10
  unsigned int (__fastcall *mTaskFunctionOffload)(void *, void *, void *, void *); // r9
  char *mAddress; // rcx
  UFG::qNode<UFG::qTask,UFG::qTask> *v32; // rax
  unsigned int v33; // eax
  int v34; // ecx
  int v35; // ebx
  Illusion::Texture **mFogCubeTexture; // rdi
  Illusion::ITexturePlat *v37; // r14
  _OWORD *mWaitWriteTicks; // rcx
  unsigned int *v39; // rdx
  __int64 v40; // rax
  char *v42; // [rsp+30h] [rbp-71h]
  UFG::qMemoryStreamer memory_streamer; // [rsp+38h] [rbp-69h] BYREF
  __int64 v44; // [rsp+88h] [rbp-19h]
  unsigned int mCurrEndSlice; // [rsp+108h] [rbp+67h]
  void *v46; // [rsp+110h] [rbp+6Fh]
  char v47; // [rsp+118h] [rbp+77h]

  v44 = -2i64;
  v7 = 0i64;
  v42 = 0i64;
  this->mNightFogZones->x = UFG::gNightFogPosX;
  this->mNightFogZones->y = UFG::gNightFogPosY;
  this->mNightFogZones->innerRadius = UFG::gNightFogInnerRadius;
  this->mNightFogZones->outerRadius = UFG::gNightFogOuterRadius;
  mCurrStartSlice = 0;
  mCurrEndSlice = 32;
  v9 = this->mFogCubeTexture[gPCFogUpdateBuffer];
  *(_QWORD *)&memory_streamer.mWorkerID = 0i64;
  *(_QWORD *)&memory_streamer.mDmaChannelWrite = 0i64;
  if ( Illusion::ITexturePlat::Lock(v9, LOCK_MODIFY, (Illusion::TextureLockInfo *)&memory_streamer.mWorkerID, 0, 0) )
  {
    v10 = *(_OWORD **)&memory_streamer.mWorkerID;
    v11 = gPCFogData;
    if ( ((LOBYTE(memory_streamer.mWorkerID) | (unsigned __int8)gPCFogData) & 0xF) != 0 )
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
  if ( !bForceFullUpdate )
  {
    mCurrStartSlice = this->mCurrStartSlice;
    mCurrEndSlice = this->mCurrEndSlice;
  }
  v13 = (unsigned int)(4 / this->mFogUpdateInterval);
  UFG::gCurrentFogSliceIndex = mCurrStartSlice;
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
    mSingleFrameTaskGroups = UFG::gTaskManager.mSingleFrameTaskGroups;
    mPrev = UFG::gTaskManager.mSingleFrameTaskGroups->mNode.mPrev;
    mPrev->mNext = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)v7;
    *(_QWORD *)v7 = mPrev;
    *((_QWORD *)v7 + 1) = mSingleFrameTaskGroups;
    mSingleFrameTaskGroups->mNode.mPrev = (UFG::qNode<UFG::qTaskGroup,UFG::qTaskGroup> *)v7;
  }
  if ( (_DWORD)v13 )
  {
    v18 = nullOutput;
    v19 = v13;
    do
    {
      v20 = (FogTaskParams *)UFG::qLinearAllocator::Malloc(Illusion::gEngine.FrameMemory, 0x50u, 0x10u);
      v20->destination_Remote = gPCFogData;
      v20->environmentSettings_Remote = v46;
      v20->camHeight = this->mCameraPosition.z;
      y = this->mCameraPosition.y;
      z = this->mCameraPosition.z;
      v20->cameraPosition.x = this->mCameraPosition.x;
      v20->cameraPosition.y = y;
      v20->cameraPosition.z = z;
      v20->cameraPosition.w = 1.0;
      v20->nightFogZones = this->mNightFogZones;
      v20->minimumNightFog = UFG::TimeOfDayManager::GetMinimumNightFogValue(this->m_SecondsSinceMidnight);
      v20->startSlice = mCurrStartSlice;
      v20->endSlice = mCurrEndSlice;
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
          v24->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = v24;
          v24->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = v24;
          v26 = &v24->UFG::qNode<UFG::qTask,UFG::TaskPlat>;
          v26->mPrev = v26;
          v26->mNext = v26;
          mSpuElf = gTaskFunctionDeclData_UpdateFogTask.mSpuElf;
          mTaskFunctionSPU = gTaskFunctionDeclData_UpdateFogTask.mTaskFunctionSPU;
          mTaskFunctionPPU = gTaskFunctionDeclData_UpdateFogTask.mTaskFunctionPPU;
          mTaskFunctionOffload = gTaskFunctionDeclData_UpdateFogTask.mTaskFunctionOffload;
          if ( !gTaskFunctionDeclData_UpdateFogTask.mCurrentSPUEnabled )
          {
            mSpuElf = 0i64;
            mTaskFunctionSPU = 0i64;
            mTaskFunctionOffload = 0i64;
          }
          v25->mTaskGroup = (UFG::qTaskGroup *)v7;
          v25->mFlags = 2;
          v25->mSyncVars.i64 = 0i64;
          v25->mSyncVars.v.mDependents = 0i64;
          v25->mFunctionDeclData = &gTaskFunctionDeclData_UpdateFogTask;
          if ( mSpuElf )
            mAddress = mSpuElf->mAddress;
          else
            mAddress = 0i64;
          v25->mSPUElfAddress = mAddress;
          v25->mSPUFunction = mTaskFunctionSPU;
          v25->mPPUFunction = mTaskFunctionPPU;
          v25->mParam0 = v20;
          v25->mParam1 = 0i64;
          v25->mParam2 = 0i64;
          v25->mParam3 = 0i64;
          if ( mTaskFunctionOffload )
          {
            v25->mFlags = 130;
            v25->mOffloadThread = 0;
          }
        }
        v32 = (UFG::qNode<UFG::qTask,UFG::qTask> *)*((_QWORD *)v7 + 2);
        v32->mNext = v25;
        v25->UFG::qNode<UFG::qTask,UFG::qTask>::mPrev = v32;
        v25->UFG::qNode<UFG::qTask,UFG::qTask>::mNext = (UFG::qNode<UFG::qTask,UFG::qTask> *)(v7 + 16);
        *((_QWORD *)v7 + 2) = v25;
        ++*((_DWORD *)v7 + 8);
      }
      else
      {
        memory_streamer.mDmaChannelRead = 0;
        memory_streamer.mDmaChannelWrite = 1;
        memset(&memory_streamer.mWaitReadTicks, 0, 48);
        UpdateFogTask(0, &memory_streamer, v20, 0i64, 0i64);
      }
      --v19;
    }
    while ( v19 );
    bForceFullUpdate = v47;
  }
  gPCFogRenderBuffer = (gPCFogRenderBuffer + 1) % this->mNumFogTextures;
  gPCFogUpdateBuffer = (gPCFogUpdateBuffer + 1) % this->mNumFogTextures;
  if ( !gPCFogUpdateBuffer )
  {
    v33 = 32u / (8 * this->mFogUpdateInterval);
    v34 = ((_BYTE)v33 + (unsigned __int8)this->mCurrStartSlice) & 0x1F;
    if ( v34 == 32 )
      v34 = 0;
    this->mCurrStartSlice = v34;
    this->mCurrEndSlice = v33 + v34;
  }
  if ( !bForceFullUpdate )
    return (UFG::qTask *)v7;
  UFG::qTaskManager::Sync(&UFG::gTaskManager);
  v35 = 0;
  if ( this->mNumFogTextures <= 0 )
    return (UFG::qTask *)v7;
  mFogCubeTexture = this->mFogCubeTexture;
  do
  {
    v37 = *mFogCubeTexture;
    memory_streamer.mWaitWriteTicks = 0i64;
    if ( Illusion::ITexturePlat::Lock(
           v37,
           LOCK_MODIFY,
           (Illusion::TextureLockInfo *)&memory_streamer.mWaitWriteTicks,
           0,
           0) )
    {
      mWaitWriteTicks = (_OWORD *)memory_streamer.mWaitWriteTicks;
      v39 = gPCFogData;
      if ( ((LOBYTE(memory_streamer.mWaitWriteTicks) | (unsigned __int8)gPCFogData) & 0xF) != 0 )
      {
        memmove((void *)memory_streamer.mWaitWriteTicks, gPCFogData, 0x20000ui64);
      }
      else
      {
        v40 = 1024i64;
        do
        {
          *mWaitWriteTicks = *(_OWORD *)v39;
          mWaitWriteTicks[1] = *((_OWORD *)v39 + 1);
          mWaitWriteTicks[2] = *((_OWORD *)v39 + 2);
          mWaitWriteTicks[3] = *((_OWORD *)v39 + 3);
          mWaitWriteTicks[4] = *((_OWORD *)v39 + 4);
          mWaitWriteTicks[5] = *((_OWORD *)v39 + 5);
          mWaitWriteTicks[6] = *((_OWORD *)v39 + 6);
          mWaitWriteTicks += 8;
          *(mWaitWriteTicks - 1) = *((_OWORD *)v39 + 7);
          v39 += 32;
          --v40;
        }
        while ( v40 );
      }
      Illusion::ITexturePlat::Unlock(v37);
    }
    ++v35;
    ++mFogCubeTexture;
  }
  while ( v35 < this->mNumFogTextures );
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
  int GPUCount; // eax
  UFG::TransformNodeComponent *v3; // rdi
  int v4; // ebp
  Illusion::Texture **mFogCubeTexture; // rsi
  Illusion::Texture *Texture3D; // rax
  unsigned int SamplerAddressFlags; // eax
  UFG::qMemoryPool *SimulationMemoryPool; // rax
  char *v9; // rsi
  unsigned int v10; // eax
  UFG::TransformNodeComponent *v11; // rax
  UFG::qString result; // [rsp+58h] [rbp-30h] BYREF

  this->mNightFogZones = (NightFogZone *)UFG::qMalloc(0x10ui64, "NightFogZones", 0x1000ui64);
  this->mSkySaturation = 1.0;
  this->mSkyBoost = 1.0;
  GPUCount = Render::GetGPUCount();
  this->mNumFogTextures = GPUCount;
  v3 = 0i64;
  v4 = 0;
  if ( GPUCount > 0 )
  {
    mFogCubeTexture = this->mFogCubeTexture;
    do
    {
      UFG::qString::FormatEx(&result, "FogTarget%d", (unsigned int)v4);
      Texture3D = Illusion::CreateTexture3D(result.mData, 32, 32, 32, FORMAT_A8R8G8B8, 0x440500u, 1, 0, 0);
      *mFogCubeTexture = Texture3D;
      SamplerAddressFlags = Illusion::Texture::GetSamplerAddressFlags(Texture3D);
      Illusion::Texture::SetSamplerState(*mFogCubeTexture, 1u, SamplerAddressFlags & 0xFFFFFFFC | 2);
      UFG::qString::~qString(&result);
      ++v4;
      ++mFogCubeTexture;
    }
    while ( v4 < this->mNumFogTextures );
  }
  SimulationMemoryPool = UFG::GetSimulationMemoryPool();
  v9 = UFG::qMemoryPool::Allocate(SimulationMemoryPool, 0x110ui64, "m_SunFxTransform", 0i64, 1u);
  if ( v9 )
  {
    v10 = UFG::qStringHashUpper32("SunTransform", 0xFFFFFFFF);
    UFG::TransformNodeComponent::TransformNodeComponent((UFG::TransformNodeComponent *)v9, v10, 0i64, 0);
    v3 = v11;
  }
  this->m_SunFxTransform = v3;
  this->m_GameSecondsPerRealSecond = 40.0;
}

// File Line: 823
// RVA: 0x69E00
void __fastcall UFG::ApplyColorFixup(float *rgbis, bool convert_to_linear)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  float v4; // xmm5_4
  float v5; // xmm2_4
  float v6; // xmm6_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm3_4

  if ( convert_to_linear )
  {
    v2 = rgbis[1] * rgbis[1];
    v3 = rgbis[2] * rgbis[2];
    *rgbis = *rgbis * *rgbis;
    rgbis[1] = v2;
    rgbis[2] = v3;
  }
  v4 = rgbis[4];
  v5 = rgbis[3];
  v6 = v5 * rgbis[2];
  v7 = v5 * *rgbis;
  v8 = rgbis[3] * rgbis[1];
  v9 = (float)((float)(v8 * 0.60000002) + (float)(v7 * 0.30000001)) + (float)(v6 * 0.1);
  rgbis[2] = (float)((float)(v6 - v9) * v4) + v9;
  *rgbis = (float)((float)(v7 - v9) * v4) + v9;
  rgbis[1] = (float)((float)(v8 - v9) * v4) + v9;
}

// File Line: 849
// RVA: 0x6B480
void __fastcall UFG::LerpRGBIS(
        float *rgbis_dest,
        unsigned int index,
        Illusion::StateBlock *state_block0,
        Illusion::StateBlock *state_block1,
        Illusion::StateBlock *state_block2,
        float time,
        float lerp_t1,
        float lerp_t2)
{
  __int64 v9; // r12
  __int64 v12; // r13
  __int64 v13; // r11
  __int64 v14; // r15
  __int64 v15; // r8
  char *v16; // rdx
  char *v17; // r10
  float *v18; // r9
  int v19; // r8d
  float *v20; // rcx
  __int64 v21; // r8
  float *v22; // rax
  float v23; // xmm3_4
  unsigned int v24; // edx
  int v25; // r8d
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

  v9 = (state_block0->mDataByteSize + 0xF) & 0xFFFFFFF0;
  v12 = (state_block1->mDataByteSize + 15) & 0xFFFFFFF0;
  v13 = 0i64;
  v14 = 5i64;
  do
  {
    v15 = 4i64 * index + 128;
    v16 = (char *)state_block0 + *(unsigned __int16 *)((char *)&state_block0->mNode.mParent + v9 + v15);
    v17 = (char *)state_block1 + *(unsigned __int16 *)((char *)&state_block1->mNode.mParent + v15 + v12);
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
    if ( *(_DWORD *)v18 == 1 )
    {
LABEL_34:
      v29 = 0.0;
    }
    else
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
LABEL_35:
    *(float *)((char *)&v65 + v13) = v29;
    v13 += 4i64;
    ++index;
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
  rgbis_dest[3] = 1.0;
  rgbis_dest[4] = 1.0;
  v51 = (float)((float)(v42 - v36) * lerp_t1) + v36;
  v52 = (float)((float)(v43 - v37) * lerp_t1) + v37;
  v53 = (float)((float)(v45 - v38) * lerp_t1) + v38;
  *rgbis_dest = v51;
  rgbis_dest[1] = v52;
  rgbis_dest[2] = v53;
  v54 = v48 + v47;
  if ( lerp_t2 > 0.0 )
  {
    *rgbis_dest = (float)((float)(v49 - v51) * lerp_t2) + v51;
    rgbis_dest[1] = (float)((float)(v50 - v52) * lerp_t2) + v52;
    rgbis_dest[2] = (float)((float)(v54 - v53) * lerp_t2) + v53;
  }
}

// File Line: 882
// RVA: 0x6AB60
char __fastcall UFG::TimeOfDayManager::GetStateblockCurves(
        UFG::TimeOfDayManager *this,
        CB_EnvironmentSettings *envState,
        float *sbArray)
{
  Illusion::StateBlock *mData; // r14
  __int64 v4; // r10
  float time; // xmm6_4
  char *v8; // r9
  int v9; // r8d
  float *v10; // rdx
  __int64 v11; // r8
  float *v12; // rax
  float v13; // xmm3_4
  unsigned int v14; // ecx
  float m_WeatherState; // xmm0_4
  Illusion::StateBlock *v16; // rsi
  Illusion::StateBlock *state_block2; // rdi
  float lerp_t1; // xmm8_4
  __int64 v19; // r10
  __int64 v20; // r11
  char *v21; // rcx
  int v22; // r8d
  float *v23; // rdx
  __int64 v24; // r8
  float *v25; // rax
  float v26; // xmm3_4
  unsigned int v27; // ecx
  float m_OverrideStateBlockAmount; // xmm4_4
  char *v29; // rcx
  int v30; // r8d
  float *v31; // rdx
  __int64 v32; // r8
  float *v33; // rax
  float v34; // xmm3_4
  unsigned int v35; // ecx

  mData = (Illusion::StateBlock *)this->mSunnyStateBlockHandle.mData;
  v4 = 0i64;
  for ( time = this->m_SecondsSinceMidnight * 0.000011574074;
        (unsigned int)v4 < mData->mNumValues;
        v4 = (unsigned int)(v4 + 1) )
  {
    v8 = (char *)mData
       + *(unsigned __int16 *)((char *)mData[1].mNode.mChild + 4 * v4 + ((mData->mDataByteSize + 15) & 0xFFFFFFF0));
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
  }
  m_WeatherState = this->m_WeatherState;
  v16 = (Illusion::StateBlock *)this->mOvercastStateBlockHandle.mData;
  state_block2 = (Illusion::StateBlock *)this->mOverrideStateBlockHandle.mData;
  if ( m_WeatherState <= 0.0 )
  {
    m_WeatherState = 0.0;
  }
  else
  {
    lerp_t1 = *(float *)&FLOAT_1_0;
    if ( m_WeatherState >= 1.0 )
      goto LABEL_18;
  }
  lerp_t1 = m_WeatherState;
LABEL_18:
  v19 = 0i64;
  do
  {
    if ( (_DWORD)v19 == 6 )
    {
      UFG::LerpRGBIS(sbArray + 6, 6u, mData, v16, state_block2, time, lerp_t1, this->m_OverrideStateBlockAmount);
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
    sbArray[v19] = (float)((float)(v26 - gCurrentSunnyEnvironment[v19]) * lerp_t1) + gCurrentSunnyEnvironment[v19];
    if ( state_block2 )
    {
      m_OverrideStateBlockAmount = this->m_OverrideStateBlockAmount;
      if ( m_OverrideStateBlockAmount > 0.0 )
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
            sbArray[v19] = (float)((float)(v34 - gCurrentSunnyEnvironment[v19]) * m_OverrideStateBlockAmount)
                         + gCurrentSunnyEnvironment[v19];
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
  if ( secondsSinceMidnight < 18000.0 )
    return gMinimumNightFog;
  if ( secondsSinceMidnight < 21600.0 )
    return (float)((float)((float)(1.0 - gMinimumNightFog) * 0.00027777778) * (float)(secondsSinceMidnight - 18000.0))
         + gMinimumNightFog;
  if ( secondsSinceMidnight < 64800.0 )
    return *(float *)&FLOAT_1_0;
  if ( secondsSinceMidnight >= 68400.0 )
    return gMinimumNightFog;
  else
    return (float)((float)((float)(gMinimumNightFog - 1.0) * 0.00027777778) * (float)(secondsSinceMidnight - 64800.0))
         + 1.0;
}

// File Line: 972
// RVA: 0x69EC0
void __fastcall UFG::TimeOfDayManager::GetEnvironmentSettings(
        UFG::TimeOfDayManager *this,
        CB_EnvironmentSettings *envState,
        Render::ViewSettings *pViewSettings,
        CB_SkySettings *skyState)
{
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
  float v31; // xmm0_4
  float v32; // xmm2_4
  float v33; // xmm7_4
  float v34; // xmm1_4
  float v35; // xmm3_4
  float v36; // xmm2_4
  float v37; // xmm2_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float v40; // xmm3_4
  float v41; // xmm3_4
  float v42; // xmm2_4
  float v43; // xmm0_4
  float v44; // xmm2_4
  float v45; // xmm1_4
  float v46; // xmm3_4
  float v47; // xmm2_4
  float v48; // xmm2_4
  float v49; // xmm0_4
  float v50; // xmm1_4
  float v51; // xmm3_4
  float v52; // xmm0_4
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm0_4
  float v57; // xmm3_4
  float v58; // xmm2_4
  float v59; // xmm2_4
  float v60; // xmm4_4
  float v61; // xmm1_4
  float v62; // xmm5_4
  float v63; // xmm1_4
  float v64; // xmm0_4
  float v65; // xmm1_4
  float v66; // xmm0_4
  float v67; // xmm1_4
  float v68; // xmm0_4
  float v69; // xmm0_4
  float v70; // xmm0_4
  float v71; // xmm2_4
  float v72; // xmm0_4
  float v73; // xmm0_4
  float v74; // xmm0_4
  float v75; // xmm1_4
  float v76; // xmm0_4
  float m_WeatherSurfaceWetness; // xmm2_4
  float v78; // xmm1_4
  float mExposure; // xmm2_4
  float v80; // xmm1_4
  float v81; // xmm0_4
  float v82; // xmm1_4
  float v83; // xmm0_4
  float x; // xmm0_4
  float y; // xmm1_4
  float mWindSpeed; // xmm3_4
  float v87; // xmm2_4
  float v88; // xmm0_4
  float v89; // xmm1_4
  float v90; // xmm2_4
  float v91; // xmm0_4
  float v92; // xmm2_4
  float v93; // xmm0_4
  float v94; // [rsp+20h] [rbp-B8h]
  float v95; // [rsp+24h] [rbp-B4h]
  float v96; // [rsp+28h] [rbp-B0h]
  float v97; // [rsp+2Ch] [rbp-ACh]
  float v98; // [rsp+30h] [rbp-A8h]
  float v99; // [rsp+34h] [rbp-A4h]
  float v100; // [rsp+38h] [rbp-A0h]
  float v101; // [rsp+3Ch] [rbp-9Ch]
  float sbArray[2]; // [rsp+50h] [rbp-88h] BYREF
  float dest; // [rsp+58h] [rbp-80h] BYREF
  float v104; // [rsp+5Ch] [rbp-7Ch]
  float v105; // [rsp+60h] [rbp-78h]
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
  float v134; // [rsp+D4h] [rbp-4h]
  float v135; // [rsp+D8h] [rbp+0h]
  float v136; // [rsp+DCh] [rbp+4h]
  float v137; // [rsp+E0h] [rbp+8h]
  float v138; // [rsp+E4h] [rbp+Ch]
  float v139; // [rsp+E8h] [rbp+10h]
  float v140; // [rsp+ECh] [rbp+14h]
  float v141; // [rsp+F0h] [rbp+18h]
  float v142; // [rsp+F4h] [rbp+1Ch]
  float v143; // [rsp+F8h] [rbp+20h]
  float v144; // [rsp+FCh] [rbp+24h]
  float v145; // [rsp+100h] [rbp+28h]
  float v146; // [rsp+104h] [rbp+2Ch]
  float v147; // [rsp+108h] [rbp+30h]
  float v148; // [rsp+10Ch] [rbp+34h]
  float v149; // [rsp+114h] [rbp+3Ch]
  float v150; // [rsp+118h] [rbp+40h]
  float v151; // [rsp+11Ch] [rbp+44h]
  float v152; // [rsp+120h] [rbp+48h]
  float v153; // [rsp+124h] [rbp+4Ch]
  float v154; // [rsp+128h] [rbp+50h]
  float v155; // [rsp+12Ch] [rbp+54h]
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
  float v170; // [rsp+168h] [rbp+90h]
  float v171; // [rsp+16Ch] [rbp+94h]
  float v172; // [rsp+170h] [rbp+98h]
  float v173; // [rsp+174h] [rbp+9Ch]
  float v174; // [rsp+178h] [rbp+A0h]
  float v175; // [rsp+17Ch] [rbp+A4h]
  float v176; // [rsp+180h] [rbp+A8h]
  float v177; // [rsp+184h] [rbp+ACh]
  float v178; // [rsp+188h] [rbp+B0h]
  float v179; // [rsp+18Ch] [rbp+B4h]
  float v180; // [rsp+190h] [rbp+B8h]
  float v181; // [rsp+278h] [rbp+1A0h]
  float v182; // [rsp+280h] [rbp+1A8h]
  float v183; // [rsp+288h] [rbp+1B0h]
  float vars0; // [rsp+290h] [rbp+1B8h]

  UFG::TimeOfDayManager::GetStateblockCurves(this, envState, sbArray);
  if ( UFG::gIsSkyIrradFog > 0.0 )
    UFG::qMemSet(&dest, 0, 0x58u);
  v8 = v157;
  v9 = *(float *)&FLOAT_1_0;
  this->mTodEV = v157;
  if ( UFG::gIgnoreEnvSettingsExposure )
  {
    v10 = UFG::gOverrideExposure;
  }
  else
  {
    v11 = v8 + this->mMeteringEV;
    if ( v11 > 1.0 )
      v11 = *(float *)&FLOAT_1_0;
    v10 = (float)(v11 + UFG::gOverrideExposure) + this->mVisualTreatmentEV;
  }
  v12 = powf(2.0, v10);
  v13 = v107;
  v14 = v108;
  v15 = v12;
  v16 = v12;
  v17 = v109;
  this->mExposure = v15;
  v18 = (float)(v16 * UFG::gAmbientBoost) * this->mGlobalIlluminationBlend;
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
  UFG::ApplyColorFixup(sbArray, 1);
  v19 = (float)((float)((float)(v109 * v111) * 0.60000002) + (float)((float)(v111 * v108) * 0.30000001))
      + (float)((float)(v110 * v111) * 0.1);
  v101 = (float)((float)((float)(v111 * v108) - v19) * v112) + v19;
  v108 = v101;
  v109 = (float)((float)((float)(v109 * v111) - v19) * v112) + v19;
  v110 = (float)((float)((float)(v110 * v111) - v19) * v112) + v19;
  v20 = (float)((float)((float)(v114 * v116) * 0.60000002) + (float)((float)(v113 * v116) * 0.30000001))
      + (float)((float)(v115 * v116) * 0.1);
  v21 = (float)((float)((float)(v113 * v116) - v20) * v117) + v20;
  v22 = (float)((float)((float)(v114 * v116) - v20) * v117) + v20;
  v23 = (float)((float)((float)(v115 * v116) - v20) * v117) + v20;
  v113 = v21;
  v114 = v22;
  v115 = v23;
  v24 = (float)((float)((float)(v119 * v121) * 0.60000002) + (float)((float)(v118 * v121) * 0.30000001))
      + (float)((float)(v120 * v121) * 0.1);
  v95 = (float)((float)((float)(v120 * v121) - v24) * v122) + v24;
  v120 = v95;
  v100 = (float)((float)((float)(v118 * v121) - v24) * v122) + v24;
  v118 = v100;
  v98 = (float)((float)((float)(v119 * v121) - v24) * v122) + v24;
  v119 = v98;
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
  v130 = v182;
  v96 = (float)((float)((float)(v129 * v132) - v29) * v133) + v29;
  v129 = v96;
  v183 = (float)((float)((float)(v131 * v132) - v29) * v133) + v29;
  v131 = v183;
  v30 = (float)((float)((float)(v139 * v141) * 0.60000002) + (float)((float)(v138 * v141) * 0.30000001))
      + (float)((float)(v140 * v141) * 0.1);
  vars0 = (float)((float)((float)(v139 * v141) - v30) * v142) + v30;
  v139 = vars0;
  v97 = (float)((float)((float)(v138 * v141) - v30) * v142) + v30;
  v138 = v97;
  v181 = (float)((float)((float)(v140 * v141) - v30) * v142) + v30;
  v140 = v181;
  v31 = v125 * v128;
  v32 = (float)((float)((float)(v124 * v128) * 0.60000002) + (float)((float)(v123 * v128) * 0.30000001))
      + (float)(v31 * 0.1);
  v33 = (float)((float)((float)(v124 * v128) - v32) * v127) + v32;
  v99 = (float)((float)((float)(v123 * v128) - v32) * v127) + v32;
  v94 = (float)((float)(v31 - v32) * v127) + v32;
  if ( skyState )
  {
    v34 = v169;
    v35 = v166 * v169;
    v36 = v167;
    skyState->CloudColourBottom[2] = v168 * v169;
    v37 = v36 * v34;
    v38 = v165;
    skyState->CloudColourBottom[3] = v171;
    v39 = v164 * v38;
    skyState->CloudColourBottom[0] = v35;
    v40 = v162;
    skyState->CloudColourBottom[1] = v37;
    skyState->CloudColourMid[3] = 0.0;
    v41 = v40 * v38;
    v42 = v163;
    skyState->CloudColourMid[2] = v39;
    v43 = v160;
    v44 = v42 * v38;
    v45 = v161;
    skyState->CloudColourMid[0] = v41;
    v46 = v158 * v45;
    skyState->CloudColourMid[1] = v44;
    v47 = v159;
    skyState->CloudColourTop[2] = v43 * v45;
    v48 = v47 * v45;
    v49 = v170;
    v50 = v172;
    skyState->CloudColourTop[0] = v46;
    v51 = v174;
    skyState->CloudColourTop[3] = v49;
    v52 = v173;
    skyState->CloudColourTop[1] = v48;
    v53 = v175;
    skyState->CloudShadingComponents[1] = v52;
    v54 = v179;
    skyState->CloudShadingComponents[0] = v50;
    v55 = v178;
    skyState->CloudShadingComponents[3] = v54;
    v56 = v176;
    skyState->CloudShadingComponents[2] = v55;
    skyState->CloudColourCeiling[3] = 0.0;
    v57 = v51 * v177;
    v58 = v53 * v177;
    skyState->CloudColourCeiling[2] = v56 * v177;
    skyState->CloudColourCeiling[0] = v57;
    skyState->CloudColourCeiling[1] = v58;
  }
  v59 = v106;
  v60 = (float)((float)(v106 * 7.0) - 7.0) + 0.5;
  v61 = (float)((float)(v106 * 7.0) - 4.2000003) + 0.5;
  v62 = (float)((float)(v106 * 7.0) - 5.5999999) + 0.5;
  if ( v60 <= 0.0 )
  {
    v60 = 0.0;
  }
  else if ( v60 >= 1.0 )
  {
    v60 = *(float *)&FLOAT_1_0;
  }
  if ( v62 <= 0.0 )
  {
    v62 = 0.0;
  }
  else if ( v62 >= 1.0 )
  {
    v62 = *(float *)&FLOAT_1_0;
  }
  if ( v61 <= 0.0 )
  {
    v61 = 0.0;
    goto LABEL_22;
  }
  if ( v61 < 1.0 )
LABEL_22:
    v9 = v61;
  v63 = sbArray[1];
  envState->SunColor[0] = sbArray[0];
  envState->SunColor[1] = v63;
  envState->SunColor[2] = dest;
  v64 = v107;
  envState->SunColor[3] = v106;
  envState->AmbientColorHorizon[0] = v64;
  envState->AmbientColorHorizon[1] = v108;
  v65 = v112;
  envState->AmbientColorHorizon[2] = v109;
  envState->AmbientColorHorizon[3] = v65;
  v66 = dest * gFogFudge;
  v67 = v107;
  envState->ScaleAndHeight[2] = v59;
  envState->ScaleAndHeight[0] = v66;
  v68 = v104;
  envState->ScaleAndHeight[3] = v67 * 0.0099999998;
  envState->ScaleAndHeight[1] = v68;
  v69 = 3.1415927 / UFG::gSunScatterHeight;
  envState->ScatterZenithColor[0] = v21 * 0.00028000001;
  envState->ScatterZenithColor[1] = v22 * 0.00028000001;
  envState->ScatterZenithColor[2] = v23 * 0.00028000001;
  envState->ScatterZenithColor[3] = v69;
  envState->ScatterHorizonColor[0] = v100 * 0.00028000001;
  envState->ScatterHorizonColor[1] = v98 * 0.00028000001;
  envState->ScatterHorizonColor[3] = v149;
  v70 = v137;
  envState->ScatterHorizonColor[2] = v95 * 0.00028000001;
  v71 = v182;
  envState->ScatterGroundColor[3] = v70;
  v72 = v183 * 0.00028000001;
  envState->ScatterGroundColor[0] = v26 * 0.00028000001;
  envState->ScatterGroundColor[1] = v27 * 0.00028000001;
  envState->ScatterGroundColor[2] = v28 * 0.00028000001;
  envState->ScatterSunColor[2] = v72;
  v73 = v134;
  envState->ScatterSunColor[0] = v96 * 0.00028000001;
  envState->ScatterSunColor[3] = v73;
  v74 = v143;
  envState->ScatterSunColor[1] = v71 * 0.00028000001;
  envState->CharacterParams[0] = v97;
  envState->CharacterParams[1] = vars0;
  v75 = v181;
  envState->CharacterParams[3] = v74;
  v76 = v146;
  envState->CharacterParams[2] = v75;
  m_WeatherSurfaceWetness = this->m_WeatherSurfaceWetness;
  v78 = v147;
  envState->FogStartStopSky[0] = v76;
  envState->FogStartStopSky[2] = v148;
  envState->FogStartStopSky[1] = v78;
  envState->FogStartStopSky[3] = m_WeatherSurfaceWetness;
  mExposure = this->mExposure;
  v80 = mExposure * this->mSkyBoost;
  envState->DisplayDebug[2] = this->mSkySaturation;
  envState->DisplayDebug[0] = v99 * 0.00028000001;
  envState->DisplayDebug[1] = mExposure;
  envState->DisplayDebug[3] = v80 * 1.3;
  envState->Lighting[0] = this->mGlobalIlluminationBlend;
  v81 = v105;
  envState->Lighting[3] = v94 * 0.00028000001;
  v82 = v136;
  envState->Lighting[1] = v81;
  v83 = v135;
  envState->Lighting[2] = v33 * 0.00028000001;
  envState->SunScatterParams[0] = v83;
  envState->SunScatterParams[2] = v144;
  envState->SunScatterParams[1] = v82;
  envState->SunScatterParams[3] = v145;
  envState->LitWindowTimeOn[3] = v101 * 0.0040000002;
  envState->LitWindowTimeOn[0] = v9;
  envState->LitWindowTimeOn[1] = v62;
  envState->LitWindowTimeOn[2] = v60;
  UFG::TimeOfDayManager::GetSunDir(this, (UFG::qVector4 *)envState->SunDirWorld, 0, 0);
  if ( pViewSettings )
    UFG::TimeOfDayManager::GetViewSpaceSunDir(this, (UFG::qVector4 *)envState, pViewSettings);
  x = this->mWindDirection.x;
  y = this->mWindDirection.y;
  mWindSpeed = this->mWindSpeed;
  envState->WindDirAndMag[2] = this->mWindDirection.z;
  v87 = v153;
  envState->WindDirAndMag[0] = x;
  v88 = v150;
  envState->WindDirAndMag[1] = y;
  v89 = gBloomNearDistance;
  envState->WindDirAndMag[3] = mWindSpeed;
  this->mBloomFarDistance = v87;
  v90 = v154;
  this->mBloomNearThreshold = v88;
  v91 = v152;
  this->mBloomSaturation = v90;
  this->mProbeBoost = v156;
  this->mBloomFarThreshold = v91;
  v92 = 90.0 - v180;
  this->mBloomBoost = v151;
  v93 = v155;
  this->mBloomNearDistance = v89;
  this->mProbeAttenDistance = v93;
  UFG::qSphericalToCartesian(this->mAmbientSkyDirection, 0.0, v92);
  UFG::qSphericalToCartesian(&this->mAmbientSkyDirection[1], 120.0, 90.0 - v180);
  UFG::qSphericalToCartesian(&this->mAmbientSkyDirection[2], 240.0, 90.0 - v180);
}

// File Line: 1100
// RVA: 0x6BC50
void __fastcall UFG::TimeOfDayManager::SetWind(UFG::TimeOfDayManager *this, float directionRadians, float speed)
{
  float v4; // xmm0_4

  this->mWindDirectionTargetRadians = directionRadians;
  this->mWindDirectionRadians = directionRadians;
  this->mWindDirection.x = cosf(directionRadians);
  v4 = sinf(directionRadians);
  this->mWindDirection.z = 0.0;
  this->mWindDirection.y = v4;
  this->mWindSpeedTarget = speed;
  this->mWindSpeed = speed;
}

// File Line: 1115
// RVA: 0x6B270
void __fastcall UFG::TimeOfDayManager::GetWind(UFG::TimeOfDayManager *this, UFG::qVector3 *direction, float *speed)
{
  float y; // xmm0_4
  float z; // xmm1_4

  y = this->mWindDirection.y;
  z = this->mWindDirection.z;
  direction->x = this->mWindDirection.x;
  direction->y = y;
  direction->z = z;
  *speed = this->mWindSpeed;
}

// File Line: 1121
// RVA: 0x6B0F0
void __fastcall UFG::TimeOfDayManager::GetViewSpaceSunDir(
        UFG::TimeOfDayManager *this,
        UFG::qVector4 *out_sun_dir,
        Render::ViewSettings *pViewSettings)
{
  float v5; // xmm6_4
  float v6; // xmm2_4
  float w; // xmm0_4
  float v8; // xmm3_4
  float v9; // xmm1_4
  UFG::qVector4 dir; // [rsp+20h] [rbp-28h] BYREF

  UFG::TimeOfDayManager::GetSunDir(this, &dir, 0, 0);
  v5 = (float)(dir.y * pViewSettings->mWorldView.v1.z) + (float)(dir.x * pViewSettings->mWorldView.v0.z);
  v6 = (float)(dir.y * pViewSettings->mWorldView.v1.y) + (float)(dir.x * pViewSettings->mWorldView.v0.y);
  w = dir.w;
  v8 = dir.z * pViewSettings->mWorldView.v2.z;
  v9 = dir.z * pViewSettings->mWorldView.v2.y;
  out_sun_dir->x = (float)((float)(dir.y * pViewSettings->mWorldView.v1.x)
                         + (float)(dir.x * pViewSettings->mWorldView.v0.x))
                 + (float)(dir.z * pViewSettings->mWorldView.v2.x);
  out_sun_dir->z = v5 + v8;
  out_sun_dir->y = v6 + v9;
  out_sun_dir->w = w;
}

// File Line: 1133
// RVA: 0x6AEB0
void __fastcall UFG::TimeOfDayManager::GetSunDir(
        UFG::TimeOfDayManager *this,
        UFG::qVector4 *dir,
        bool bClampSunElevation,
        bool bUseQuantizedSeconds)
{
  float m_QuantizedSecondsSinceMidnight; // xmm8_4
  float m_LocalLatitude; // xmm6_4
  float m_SunDeclination; // xmm7_4
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

  if ( bUseQuantizedSeconds )
    m_QuantizedSecondsSinceMidnight = this->m_QuantizedSecondsSinceMidnight;
  else
    m_QuantizedSecondsSinceMidnight = this->m_SecondsSinceMidnight;
  m_LocalLatitude = this->m_LocalLatitude;
  m_SunDeclination = this->m_SunDeclination;
  v9 = (float)((float)(m_QuantizedSecondsSinceMidnight - 43200.0) * 0.00027777778) * 0.2617994;
  v10 = cosf(m_LocalLatitude);
  v11 = sinf(m_SunDeclination);
  v12 = sinf(m_LocalLatitude);
  v13 = cosf(m_SunDeclination);
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
  if ( bClampSunElevation && v16 <= 0.40000001 )
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
  dir->x = cosf(v21) * v22;
  dir->y = sinf(v21) * v22;
  v23 = cosf(1.5707964 - v17);
  dir->w = 0.0;
  dir->z = v23;
}

// File Line: 1172
// RVA: 0x6B1B0
float __fastcall UFG::TimeOfDayManager::GetWeatherIntensityFromString(UFG::qString *weather)
{
  if ( UFG::qString::operator==(weather, "sunny") )
    return 0.0;
  if ( UFG::qString::operator==(weather, "lightcloud") )
    return FLOAT_0_1;
  if ( UFG::qString::operator==(weather, "cloudy") )
    return *(float *)&FLOAT_1_0;
  if ( UFG::qString::operator==(weather, "lightrain") )
    return FLOAT_1_5;
  if ( UFG::qString::operator==(weather, "heavyrain") )
    return FLOAT_2_0;
  return FLOAT_N1_0;
}

// File Line: 1213
// RVA: 0x6B0A0
bool __fastcall UFG::TimeOfDayManager::GetTimeInSeconds(float time, int *timeInSeconds)
{
  unsigned int v2; // r8d
  bool result; // al

  v2 = -100 * (int)time - (int)(float)(time * -100.0);
  if ( (unsigned int)(int)time > 0x18 || v2 > 0x3B )
    return 0;
  result = 1;
  *timeInSeconds = 60 * (v2 + 60 * (int)time);
  return result;
}

