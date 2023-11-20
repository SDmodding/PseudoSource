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
  UFG::AudioCurveSymbolManager *v1; // rbx
  UFG::qSymbol *v2; // rax
  signed __int64 v3; // rdx

  v1 = this;
  `eh vector constructor iterator(this, 4ui64, 255, (void (__fastcall *)(void *))BackInfo::BackInfo);
  v1->m_numSymbols = 1;
  v2 = (UFG::qSymbol *)v1;
  v3 = 254i64;
  do
  {
    v2->mUID = UFG::gNullQSymbol.mUID;
    ++v2;
    --v3;
  }
  while ( v3 );
}

// File Line: 132
// RVA: 0x593CF0
void __fastcall UFG::AudioCurve::~AudioCurve(UFG::AudioCurve *this)
{
  UFG::AudioCurve *v1; // rsi
  UFG::qArray<UFG::AudioCurve::PointProperties,0> *v2; // rdi
  UFG::AudioCurve::PointProperties *v3; // rcx
  UFG::qSymbol *v4; // rbx

  v1 = this;
  v2 = this->mPointProperties;
  if ( v2 )
  {
    v3 = v2->p;
    if ( v3 )
    {
      v4 = &v3[-1].mVehicleEvent;
      `eh vector destructor iterator(
        v3,
        0xCui64,
        v3[-1].mVehicleEvent.mUID,
        (void (__fastcall *)(void *))UFG::AudioCurve::PointProperties::~PointProperties);
      operator delete[](v4);
    }
    v2->p = 0i64;
    *(_QWORD *)&v2->size = 0i64;
    operator delete[](v2);
    v1->mPointProperties = 0i64;
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
  UFG::EngineCurve *v1; // rbx
  UFG::AudioCurveSet **v2; // rcx
  UFG::AudioCurveSet **v3; // rcx
  UFG::qNode<UFG::EngineCurve,UFG::EngineCurve> *v4; // rcx
  UFG::qNode<UFG::EngineCurve,UFG::EngineCurve> *v5; // rax

  v1 = this;
  UFG::EngineCurve::DestroyEngineCurve(this);
  v2 = v1->m_namedCurveSets.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_namedCurveSets.p = 0i64;
  *(_QWORD *)&v1->m_namedCurveSets.size = 0i64;
  v3 = v1->m_gears.p;
  if ( v3 )
    operator delete[](v3);
  v1->m_gears.p = 0i64;
  *(_QWORD *)&v1->m_gears.size = 0i64;
  v4 = v1->mPrev;
  v5 = v1->mNext;
  v4->mNext = v5;
  v5->mPrev = v4;
  v1->mPrev = (UFG::qNode<UFG::EngineCurve,UFG::EngineCurve> *)&v1->mPrev;
  v1->mNext = (UFG::qNode<UFG::EngineCurve,UFG::EngineCurve> *)&v1->mPrev;
}

