// File Line: 46
// RVA: 0xA1B700
void __fastcall Illusion::OcclusionPlat::InitBank(
        Illusion::OcclusionPlat *this,
        unsigned int maxQueries,
        unsigned int numTiles)
{
  __int64 v4; // rbx
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // rax
  UFG::allocator::free_link *v7; // rax
  UFG::allocator::free_link *v8; // rcx
  int i; // edx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  __int64 v12; // [rsp+58h] [rbp+20h] BYREF

  Illusion::gOcclusionBank.mMaxQueries = maxQueries;
  v4 = 0i64;
  Illusion::gOcclusionBank.mNumQueries = 0;
  v5 = maxQueries;
  v6 = 16i64 * maxQueries;
  if ( !is_mul_ok(maxQueries, 0x10ui64) )
    v6 = -1i64;
  v7 = UFG::qMalloc(v6, "OcclusionQuery", 0i64);
  if ( v7 )
  {
    v8 = v7;
    for ( i = maxQueries - 1; i >= 0; --i )
    {
      LODWORD(v8->mNext) = 0;
      v8[1].mNext = 0i64;
      v8 += 2;
    }
  }
  else
  {
    v7 = 0i64;
  }
  Illusion::gOcclusionBank.pQueries = (Illusion::OcclusionQuery *)v7;
  v12 = 1i64;
  v10 = 8 * v5;
  if ( !is_mul_ok(v5, 8ui64) )
    v10 = -1i64;
  Illusion::gOcclusionBank.mPercentResults[0] = (unsigned __int64 *)UFG::qMalloc(v10, "mPercentResults[0]", 0i64);
  v11 = 8 * v5;
  if ( !is_mul_ok(v5, 8ui64) )
    v11 = -1i64;
  Illusion::gOcclusionBank.mPercentResults[1] = (unsigned __int64 *)UFG::qMalloc(v11, "mPercentResults[1]", 0i64);
  UFG::qMemSet(Illusion::gOcclusionBank.mPercentResults[0], 0, 8 * maxQueries);
  UFG::qMemSet(Illusion::gOcclusionBank.mPercentResults[1], 0, 8 * maxQueries);
  Illusion::gOcclusionBank.mCurrentBuffer = 0;
  if ( maxQueries )
  {
    do
    {
      ((void (__fastcall *)(ID3D11Device *, __int64 *, ID3D11Query **))UFG::gD3D11Device->vfptr->OMSetRenderTargets)(
        UFG::gD3D11Device,
        &v12,
        &Illusion::gOcclusionBank.pQueries[v4++].mQuery);
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 115
// RVA: 0xA17AE0
void __fastcall Illusion::OcclusionPlat::BeginQuery(
        Illusion::OcclusionPlat *this,
        unsigned int curQuery,
        unsigned int numTiles)
{
  Illusion::OcclusionQuery *pQueries; // rax
  __int64 v4; // rbx
  __int64 v5; // rdi
  Illusion::OcclusionQuery *v6; // rdx
  __int64 v7; // rcx

  if ( curQuery != -1 )
  {
    pQueries = Illusion::gOcclusionBank.pQueries;
    v4 = curQuery;
    v5 = curQuery;
    if ( Illusion::gOcclusionBank.pQueries[curQuery].mState == 2 )
    {
      Illusion::ITargetPlat::EndQuery(this, curQuery, numTiles);
      Illusion::gOcclusionBank.pQueries[v4].mState = 1;
      Illusion::gOcclusionBank.mPercentResults[(LOBYTE(Illusion::gOcclusionBank.mCurrentBuffer) - 1) & 1][v5] = 0i64;
      pQueries = Illusion::gOcclusionBank.pQueries;
    }
    v6 = &pQueries[v4];
    if ( v6->mState == 1 || v6->mState == 4 )
    {
      v7 = *(_QWORD *)(*((_QWORD *)NtCurrentTeb()->Reserved1[11] + tls_index) + 104i64);
      (*(void (__fastcall **)(__int64, ID3D11Query *))(*(_QWORD *)v7 + 216i64))(v7, v6->mQuery);
      Illusion::gOcclusionBank.pQueries[v4].mState = 2;
    }
  }
}

// File Line: 167
// RVA: 0xA20FE0
void __fastcall Illusion::OcclusionPlat::ReleaseQueryHandle(
        Illusion::OcclusionPlat *this,
        unsigned int queryId,
        Illusion::Target *pTarget)
{
  if ( queryId != -1 )
    Illusion::gOcclusionBank.pQueries[queryId].mState = 0;
}

// File Line: 175
// RVA: 0xA1B060
__int64 __fastcall Illusion::OcclusionPlat::GetQueryHandle(Illusion::OcclusionPlat *this, Illusion::Target *pTarget)
{
  __int64 result; // rax
  Illusion::OcclusionQuery *i; // rcx

  result = 0i64;
  if ( !Illusion::gOcclusionBank.mMaxQueries )
    return 0xFFFFFFFFi64;
  for ( i = Illusion::gOcclusionBank.pQueries; i->mState; ++i )
  {
    result = (unsigned int)(result + 1);
    if ( (unsigned int)result >= Illusion::gOcclusionBank.mMaxQueries )
      return 0xFFFFFFFFi64;
  }
  Illusion::gOcclusionBank.pQueries[(unsigned int)result].mState = 1;
  Illusion::gOcclusionBank.mPercentResults[Illusion::gOcclusionBank.mCurrentBuffer][result] = 0i64;
  return result;
}

// File Line: 184
// RVA: 0xA1B000
float __fastcall Illusion::OcclusionPlat::GetPercentVisible(
        Illusion::OcclusionPlat *this,
        unsigned int queryId,
        unsigned int unculledQueryId,
        Illusion::Target *pTarget)
{
  __int64 v4; // r9
  unsigned __int64 *v5; // rcx
  __int64 v6; // rdx
  __int64 v7; // rcx
  float v8; // xmm0_4
  float v9; // xmm1_4

  v4 = queryId;
  if ( queryId == -1 )
    return 0.0;
  v5 = Illusion::gOcclusionBank.mPercentResults[Illusion::gOcclusionBank.mCurrentBuffer];
  v6 = v5[unculledQueryId];
  if ( !v6 )
    return 0.0;
  v7 = v5[v4];
  v8 = (float)(int)v7;
  if ( v7 < 0 )
    v8 = v8 + 1.8446744e19;
  v9 = (float)(int)v6;
  if ( v6 < 0 )
    v9 = v9 + 1.8446744e19;
  return v8 / v9;
}

// File Line: 216
// RVA: 0xA1B0C0
void __fastcall Illusion::OcclusionPlat::GetQueryResultsForFrame(Illusion::OcclusionPlat *this)
{
  unsigned int v1; // ebx
  __int64 v2; // rbp
  __int64 v3; // rsi
  _QWORD *v4; // rax
  __int64 v5; // rcx
  unsigned __int64 v6; // [rsp+68h] [rbp+10h] BYREF

  v1 = 0;
  if ( Illusion::gOcclusionBank.mMaxQueries )
  {
    v2 = tls_index;
    do
    {
      v3 = v1;
      Illusion::gOcclusionBank.mPercentResults[(LOBYTE(Illusion::gOcclusionBank.mCurrentBuffer) - 1) & 1][v3] = Illusion::gOcclusionBank.mPercentResults[Illusion::gOcclusionBank.mCurrentBuffer][v3];
      if ( Illusion::gOcclusionBank.pQueries[v1].mState == 3 )
      {
        v4 = NtCurrentTeb()->Reserved1[11];
        v6 = 0i64;
        v5 = *(_QWORD *)(v4[v2] + 104i64);
        if ( !(*(unsigned int (__fastcall **)(__int64, ID3D11Query *, unsigned __int64 *, __int64, int))(*(_QWORD *)v5 + 232i64))(
                v5,
                Illusion::gOcclusionBank.pQueries[v1].mQuery,
                &v6,
                8i64,
                1) )
        {
          Illusion::gOcclusionBank.pQueries[v1].mState = 4;
          Illusion::gOcclusionBank.mPercentResults[(LOBYTE(Illusion::gOcclusionBank.mCurrentBuffer) - 1) & 1][v3] = v6;
        }
      }
      ++v1;
    }
    while ( v1 < Illusion::gOcclusionBank.mMaxQueries );
  }
  Illusion::gOcclusionBank.mCurrentBuffer = (LOBYTE(Illusion::gOcclusionBank.mCurrentBuffer) - 1) & 1;
}

