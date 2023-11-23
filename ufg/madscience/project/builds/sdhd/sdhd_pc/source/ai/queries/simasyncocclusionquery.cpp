// File Line: 17
// RVA: 0x366440
void UFG::SimAsyncOcclusionQueryManager::Init(void)
{
  UFG::allocator::free_link *v0; // rax
  UFG::SimAsyncOcclusionQueryManager *v1; // rax

  v0 = UFG::qMalloc(0xC00ui64, "SimAsyncOcclusionQueryManager", 0i64);
  if ( v0 )
  {
    UFG::SimAsyncOcclusionQueryManager::SimAsyncOcclusionQueryManager((UFG::SimAsyncOcclusionQueryManager *)v0);
    sInstance_1 = v1;
  }
  else
  {
    sInstance_1 = 0i64;
  }
}

// File Line: 23
// RVA: 0x3521E0
void UFG::SimAsyncOcclusionQueryManager::Destroy(void)
{
  UFG::SimAsyncOcclusionQueryManager *v0; // rbx

  v0 = sInstance_1;
  if ( sInstance_1 )
  {
    UFG::SimAsyncOcclusionQueryManager::~SimAsyncOcclusionQueryManager(sInstance_1);
    operator delete[](v0);
  }
  sInstance_1 = 0i64;
}

// File Line: 30
// RVA: 0x359620
UFG::SimAsyncOcclusionQueryManager *__fastcall UFG::SimAsyncOcclusionQueryManager::Get()
{
  return sInstance_1;
}

// File Line: 36
// RVA: 0x331DE0
void __fastcall UFG::SimAsyncOcclusionQueryManager::SimAsyncOcclusionQueryManager(
        UFG::SimAsyncOcclusionQueryManager *this)
{
  __int64 v2; // rbx
  bool *p_mInUse; // rax

  v2 = 64i64;
  `eh vector constructor iterator(
    this,
    0x30ui64,
    64,
    (void (__fastcall *)(void *))UFG::SimAsyncOcclusionQuery::SimAsyncOcclusionQuery);
  p_mInUse = &this->mQueries[0].mInUse;
  do
  {
    *p_mInUse = 0;
    p_mInUse += 48;
    --v2;
  }
  while ( v2 );
}

// File Line: 45
// RVA: 0x33AF60
void __fastcall UFG::SimAsyncOcclusionQueryManager::~SimAsyncOcclusionQueryManager(
        UFG::SimAsyncOcclusionQueryManager *this)
{
  bool *p_mInUse; // rbx
  __int64 v3; // rdi

  p_mInUse = &this->mQueries[0].mInUse;
  v3 = 64i64;
  do
  {
    if ( *p_mInUse )
    {
      FX::HardwareOcclusionQuery::Release((FX::HardwareOcclusionQuery *)(p_mInUse - 44));
      *p_mInUse = 0;
    }
    p_mInUse += 48;
    --v3;
  }
  while ( v3 );
  `eh vector destructor iterator(
    this,
    0x30ui64,
    64,
    (void (__fastcall *)(void *))UFG::SimAsyncOcclusionQuery::~SimAsyncOcclusionQuery);
}

// File Line: 58
// RVA: 0x351060
UFG::SimAsyncOcclusionQueryManager *__fastcall UFG::SimAsyncOcclusionQueryManager::CreateQuery(
        UFG::SimAsyncOcclusionQueryManager *this,
        UFG::qVector3 *queryPosition,
        float radius)
{
  __int64 v5; // rax
  UFG::SimAsyncOcclusionQueryManager *result; // rax
  float y; // xmm0_4
  float z; // xmm1_4

  v5 = 0i64;
  while ( this->mQueries[0].mInUse )
  {
    ++v5;
    this = (UFG::SimAsyncOcclusionQueryManager *)((char *)this + 48);
    if ( v5 >= 64 )
      return 0i64;
  }
  this->mQueries[0].mInUse = 1;
  FX::HardwareOcclusionQuery::Init((FX::HardwareOcclusionQuery *)this);
  y = queryPosition->y;
  z = queryPosition->z;
  this->mQueries[0].mPosition.x = queryPosition->x;
  result = this;
  this->mQueries[0].mPosition.y = y;
  this->mQueries[0].mPosition.z = z;
  this->mQueries[0].mVisibility = 0.0;
  *(_WORD *)&this->mQueries[0].mQueryCompleted = 0;
  this->mQueries[0].mRadius = radius;
  return result;
}

// File Line: 81
// RVA: 0x380C50
void __fastcall UFG::SimAsyncOcclusionQueryManager::ReleaseQuery(
        UFG::SimAsyncOcclusionQueryManager *this,
        UFG::SimAsyncOcclusionQuery *pQuery)
{
  if ( pQuery )
  {
    FX::HardwareOcclusionQuery::Release(&pQuery->mHardwareOcclusionQuery);
    pQuery->mInUse = 0;
  }
}

// File Line: 90
// RVA: 0x398720
void __fastcall UFG::SimAsyncOcclusionQueryManager::UpdateQueries(
        UFG::SimAsyncOcclusionQueryManager *this,
        Render::View *pView)
{
  UFG::qVector3 *p_mPosition; // rbx
  __int64 v4; // rdi
  bool v5; // zf
  __m128 v6; // xmm2
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-40h] BYREF

  p_mPosition = &this->mQueries[0].mPosition;
  v4 = 64i64;
  do
  {
    if ( LOBYTE(p_mPosition[1].z) )
    {
      UFG::qTranslationMatrix(&dest, p_mPosition);
      v5 = LODWORD(p_mPosition[-2].x) == -1;
      v6 = _mm_shuffle_ps((__m128)LODWORD(p_mPosition[1].x), (__m128)LODWORD(p_mPosition[1].x), 0);
      dest.v0 = (UFG::qVector4)_mm_mul_ps((__m128)dest.v0, v6);
      dest.v1 = (UFG::qVector4)_mm_mul_ps((__m128)dest.v1, v6);
      dest.v2 = (UFG::qVector4)_mm_mul_ps((__m128)dest.v2, v6);
      if ( !v5 && LODWORD(p_mPosition[-2].y) != -1 && (char)++BYTE2(p_mPosition[1].z) > 5 )
      {
        BYTE1(p_mPosition[1].z) = 1;
        p_mPosition[1].y = FX::HardwareOcclusionQuery::GetVisibility((FX::HardwareOcclusionQuery *)&p_mPosition[-2]);
      }
      FX::HardwareOcclusionQuery::DrawSphere((FX::HardwareOcclusionQuery *)&p_mPosition[-2], pView, &dest);
    }
    p_mPosition += 4;
    --v4;
  }
  while ( v4 );
}

