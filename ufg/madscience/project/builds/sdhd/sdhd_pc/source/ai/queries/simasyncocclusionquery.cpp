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
void __fastcall UFG::SimAsyncOcclusionQueryManager::SimAsyncOcclusionQueryManager(UFG::SimAsyncOcclusionQueryManager *this)
{
  UFG::SimAsyncOcclusionQueryManager *v1; // rdi
  signed __int64 v2; // rbx
  bool *v3; // rax

  v1 = this;
  v2 = 64i64;
  `eh vector constructor iterator(
    this,
    0x30ui64,
    64,
    (void (__fastcall *)(void *))UFG::SimAsyncOcclusionQuery::SimAsyncOcclusionQuery);
  v3 = &v1->mQueries[0].mInUse;
  do
  {
    *v3 = 0;
    v3 += 48;
    --v2;
  }
  while ( v2 );
}

// File Line: 45
// RVA: 0x33AF60
void __fastcall UFG::SimAsyncOcclusionQueryManager::~SimAsyncOcclusionQueryManager(UFG::SimAsyncOcclusionQueryManager *this)
{
  UFG::SimAsyncOcclusionQueryManager *v1; // rsi
  bool *v2; // rbx
  signed __int64 v3; // rdi

  v1 = this;
  v2 = &this->mQueries[0].mInUse;
  v3 = 64i64;
  do
  {
    if ( *v2 )
    {
      FX::HardwareOcclusionQuery::Release((FX::HardwareOcclusionQuery *)(v2 - 44));
      *v2 = 0;
    }
    v2 += 48;
    --v3;
  }
  while ( v3 );
  `eh vector destructor iterator(
    v1,
    0x30ui64,
    64,
    (void (__fastcall *)(void *))UFG::SimAsyncOcclusionQuery::~SimAsyncOcclusionQuery);
}

// File Line: 58
// RVA: 0x351060
UFG::SimAsyncOcclusionQueryManager *__fastcall UFG::SimAsyncOcclusionQueryManager::CreateQuery(UFG::SimAsyncOcclusionQueryManager *this, UFG::qVector3 *queryPosition, const float radius)
{
  UFG::qVector3 *v3; // rdi
  UFG::SimAsyncOcclusionQueryManager *v4; // rbx
  signed __int64 v5; // rax
  UFG::SimAsyncOcclusionQueryManager *result; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4

  v3 = queryPosition;
  v4 = this;
  v5 = 0i64;
  while ( v4->mQueries[0].mInUse )
  {
    ++v5;
    v4 = (UFG::SimAsyncOcclusionQueryManager *)((char *)v4 + 48);
    if ( v5 >= 64 )
      return 0i64;
  }
  v4->mQueries[0].mInUse = 1;
  FX::HardwareOcclusionQuery::Init((FX::HardwareOcclusionQuery *)v4);
  v7 = v3->y;
  v8 = v3->z;
  v4->mQueries[0].mPosition.x = v3->x;
  result = v4;
  v4->mQueries[0].mPosition.y = v7;
  v4->mQueries[0].mPosition.z = v8;
  v4->mQueries[0].mVisibility = 0.0;
  *(_WORD *)&v4->mQueries[0].mQueryCompleted = 0;
  v4->mQueries[0].mRadius = radius;
  return result;
}

// File Line: 81
// RVA: 0x380C50
void __fastcall UFG::SimAsyncOcclusionQueryManager::ReleaseQuery(UFG::SimAsyncOcclusionQueryManager *this, UFG::SimAsyncOcclusionQuery *pQuery)
{
  UFG::SimAsyncOcclusionQuery *v2; // rbx

  if ( pQuery )
  {
    v2 = pQuery;
    FX::HardwareOcclusionQuery::Release(&pQuery->mHardwareOcclusionQuery);
    v2->mInUse = 0;
  }
}

// File Line: 90
// RVA: 0x398720
void __fastcall UFG::SimAsyncOcclusionQueryManager::UpdateQueries(UFG::SimAsyncOcclusionQueryManager *this, Render::View *pView)
{
  Render::View *v2; // r14
  UFG::qVector3 *v3; // rbx
  signed __int64 v4; // rdi
  bool v5; // zf
  __m128 v6; // xmm2
  UFG::qMatrix44 dest; // [rsp+20h] [rbp-40h]

  v2 = pView;
  v3 = &this->mQueries[0].mPosition;
  v4 = 64i64;
  do
  {
    if ( LOBYTE(v3[1].z) )
    {
      UFG::qTranslationMatrix(&dest, v3);
      v5 = LODWORD(v3[-2].x) == -1;
      v6 = _mm_shuffle_ps((__m128)LODWORD(v3[1].x), (__m128)LODWORD(v3[1].x), 0);
      dest.v0 = (UFG::qVector4)_mm_mul_ps((__m128)dest.v0, v6);
      dest.v1 = (UFG::qVector4)_mm_mul_ps((__m128)dest.v1, v6);
      dest.v2 = (UFG::qVector4)_mm_mul_ps((__m128)dest.v2, v6);
      if ( !v5 && LODWORD(v3[-2].y) != -1 && ++BYTE2(v3[1].z) > 5 )
      {
        BYTE1(v3[1].z) = 1;
        v3[1].y = FX::HardwareOcclusionQuery::GetVisibility((FX::HardwareOcclusionQuery *)&v3[-2]);
      }
      FX::HardwareOcclusionQuery::DrawSphere((FX::HardwareOcclusionQuery *)&v3[-2], v2, &dest);
    }
    v3 += 4;
    --v4;
  }
  while ( v4 );
}

