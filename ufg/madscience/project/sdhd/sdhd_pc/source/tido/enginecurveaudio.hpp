// File Line: 37
// RVA: 0x59CF70
void __fastcall UFG::AudioCurveSymbolManager::GetInstance()
{
  UFG::allocator::free_link *v0; // rax

  if ( !UFG::AudioCurveSymbolManager::ms_instance )
  {
    v0 = UFG::qMemoryPool::Allocate(&g_AudioComponentPool, 0x400ui64, "AudioCurveSymbolManager", 0i64, 1u);
    if ( v0 )
      UFG::AudioCurveSymbolManager::AudioCurveSymbolManager((UFG::AudioCurveSymbolManager *)v0);
    UFG::AudioCurveSymbolManager::ms_instance = (UFG::AudioCurveSymbolManager *)v0;
  }
}

// File Line: 96
// RVA: 0x592BA0
void __fastcall UFG::AudioCurveSymbolManager::AudioCurveSymbolManager(UFG::AudioCurveSymbolManager *this)
{
  UFG::AudioCurveSymbolManager *v2; // rax
  __int64 v3; // rdx

  `eh vector constructor iterator(this, 4ui64, 255, (void (__fastcall *)(void *))BackInfo::BackInfo);
  this->m_numSymbols = 1;
  v2 = this;
  v3 = 254i64;
  do
  {
    v2->m_symbols[0] = UFG::gNullQSymbol;
    v2 = (UFG::AudioCurveSymbolManager *)((char *)v2 + 4);
    --v3;
  }
  while ( v3 );
}

// File Line: 132
// RVA: 0x593CF0
void __fastcall UFG::AudioCurve::~AudioCurve(UFG::AudioCurve *this)
{
  UFG::qArray<UFG::AudioCurve::PointProperties,0> *mPointProperties; // rdi
  UFG::AudioCurve::PointProperties *p; // rcx
  UFG::qSymbol *p_mVehicleEvent; // rbx

  mPointProperties = this->mPointProperties;
  if ( mPointProperties )
  {
    p = mPointProperties->p;
    if ( p )
    {
      p_mVehicleEvent = &p[-1].mVehicleEvent;
      `eh vector destructor iterator(
        p,
        0xCui64,
        p[-1].mVehicleEvent.mUID,
        (void (__fastcall *)(void *))UFG::AudioCurve::PointProperties::~PointProperties);
      operator delete[](p_mVehicleEvent);
    }
    mPointProperties->p = 0i64;
    *(_QWORD *)&mPointProperties->size = 0i64;
    operator delete[](mPointProperties);
    this->mPointProperties = 0i64;
  }
  else
  {
    this->mPointProperties = 0i64;
  }
  --UFG::AudioCurve::sm_count;
}

// File Line: 217
// RVA: 0x5944F0
void __fastcall UFG::EngineCurve::~EngineCurve(UFG::EngineCurve *this)
{
  UFG::AudioCurveSet **p; // rcx
  UFG::AudioCurveSet **v3; // rcx
  UFG::qNode<UFG::EngineCurve,UFG::EngineCurve> *mPrev; // rcx
  UFG::qNode<UFG::EngineCurve,UFG::EngineCurve> *mNext; // rax

  UFG::EngineCurve::DestroyEngineCurve(this);
  p = this->m_namedCurveSets.p;
  if ( p )
    operator delete[](p);
  this->m_namedCurveSets.p = 0i64;
  *(_QWORD *)&this->m_namedCurveSets.size = 0i64;
  v3 = this->m_gears.p;
  if ( v3 )
    operator delete[](v3);
  this->m_gears.p = 0i64;
  *(_QWORD *)&this->m_gears.size = 0i64;
  mPrev = this->mPrev;
  mNext = this->mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  this->mPrev = this;
  this->mNext = this;
}

