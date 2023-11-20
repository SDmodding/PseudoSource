// File Line: 30
// RVA: 0x5387B0
void __fastcall UFG::TargetingProfile::InitFromPropertySet(UFG::TargetingProfile *this, UFG::qPropertySet *pTargetingProfilePropertySet)
{
  UFG::qPropertySet *v2; // r14
  UFG::TargetingProfile *v3; // rsi
  unsigned int v4; // eax
  const char **v5; // rdi
  float *v6; // rbx
  float v7; // xmm6_4
  float *v8; // rbp
  float *v9; // rax
  float v10; // xmm0_4
  float v11; // xmm0_4
  float *v12; // rbx
  float *v13; // rbp
  float *v14; // r15
  float *v15; // r12
  float *v16; // r13
  float *v17; // rdi
  bool *v18; // rax
  float v19; // xmm0_4
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm0_4
  UFG::qSymbol result; // [rsp+B8h] [rbp+10h]
  UFG::qSymbol name; // [rsp+C0h] [rbp+18h]
  UFG::qSymbol v27; // [rsp+C8h] [rbp+20h]

  if ( pTargetingProfilePropertySet )
  {
    v2 = pTargetingProfilePropertySet;
    v3 = this;
    this->mNode.mUID = pTargetingProfilePropertySet->mName.mUID;
    v4 = _S45;
    if ( !(_S45 & 1) )
    {
      _S45 |= 1u;
      UFG::qSymbol::create_from_string(&symVertialFOV, "VertialFOV");
      atexit(UFG::TargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symVertialFOV__);
      v4 = _S45;
    }
    if ( !(v4 & 2) )
    {
      _S45 = v4 | 2;
      UFG::qSymbol::create_from_string(&symExtraPositivePitch, "ExtraPositivePitch");
      atexit(UFG::TargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symExtraPositivePitch__);
      v4 = _S45;
    }
    if ( !(v4 & 4) )
    {
      _S45 = v4 | 4;
      UFG::qSymbol::create_from_string(&symExtraNegativePitch, "ExtraNegativePitch");
      atexit(UFG::TargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symExtraNegativePitch__);
      v4 = _S45;
    }
    if ( !(v4 & 8) )
    {
      _S45 = v4 | 8;
      UFG::qSymbol::create_from_string(&symTargetReleaseDistancePastMaxDistance, "TargetReleaseDistancePastMaxDistance");
      atexit(UFG::TargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symTargetReleaseDistancePastMaxDistance__);
      v4 = _S45;
    }
    if ( !(v4 & 0x10) )
    {
      _S45 = v4 | 0x10;
      UFG::qSymbol::create_from_string(&symHalfHorizontalIntentionLimiter, "HalfHorizontalIntentionLimiter");
      atexit(UFG::TargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symHalfHorizontalIntentionLimiter__);
      v4 = _S45;
    }
    if ( !(v4 & 0x20) )
    {
      _S45 = v4 | 0x20;
      UFG::qSymbol::create_from_string(&symIdlePriorityConeHorizontalFOV, "IdlePriorityConeHorizontalFOV");
      atexit(UFG::TargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symIdlePriorityConeHorizontalFOV__);
      v4 = _S45;
    }
    if ( !(v4 & 0x40) )
    {
      _S45 = v4 | 0x40;
      UFG::qSymbol::create_from_string(&symIdlePriorityConeTime, "IdlePriorityConeTime");
      atexit(UFG::TargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symIdlePriorityConeTime__);
      v4 = _S45;
    }
    if ( (v4 & 0x80u) == 0 )
    {
      _S45 = v4 | 0x80;
      UFG::qSymbol::create_from_string(&symConsiderDownedTargets, "ConsiderDownedTargets");
      atexit(UFG::TargetingProfile::InitFromPropertySet_::_5_::_dynamic_atexit_destructor_for__symConsiderDownedTargets__);
    }
    v5 = UFG::ConeEnumNames;
    v6 = v3->m_HalfHorizontalFOVs;
    v7 = FLOAT_N1_0;
    do
    {
      UFG::qSymbol::create_from_string(&result, *v5);
      UFG::qSymbol::create_suffix(&name, &result, "_ConeDistance");
      UFG::qSymbol::create_suffix(&v27, &result, "_HorizontalFOV");
      v8 = UFG::qPropertySet::Get<float>(v2, &name, DEPTH_RECURSE);
      v9 = UFG::qPropertySet::Get<float>(v2, &v27, DEPTH_RECURSE);
      if ( v8 )
        v10 = *v8 * *v8;
      else
        v10 = FLOAT_N1_0;
      *(v6 - 6) = v10;
      if ( v9 )
        v11 = (float)((float)(*v9 * 0.5) * 3.1415927) * 0.0055555557;
      else
        v11 = FLOAT_N1_0;
      *v6 = v11;
      ++v6;
      ++v5;
    }
    while ( (signed __int64)v5 < (signed __int64)UFG::FollowCameraTypeNames );
    *(_QWORD *)&result.mUID = UFG::qPropertySet::Get<float>(v2, &symVertialFOV, DEPTH_RECURSE);
    v12 = UFG::qPropertySet::Get<float>(v2, &symExtraPositivePitch, DEPTH_RECURSE);
    v13 = UFG::qPropertySet::Get<float>(v2, &symExtraNegativePitch, DEPTH_RECURSE);
    v14 = UFG::qPropertySet::Get<float>(v2, &symTargetReleaseDistancePastMaxDistance, DEPTH_RECURSE);
    v15 = UFG::qPropertySet::Get<float>(v2, &symHalfHorizontalIntentionLimiter, DEPTH_RECURSE);
    v16 = UFG::qPropertySet::Get<float>(v2, &symIdlePriorityConeHorizontalFOV, DEPTH_RECURSE);
    v17 = UFG::qPropertySet::Get<float>(v2, &symIdlePriorityConeTime, DEPTH_RECURSE);
    v18 = UFG::qPropertySet::Get<bool>(v2, &symConsiderDownedTargets, DEPTH_RECURSE);
    if ( *(_QWORD *)&result.mUID )
      v19 = (float)((float)(**(float **)&result.mUID * 0.5) * 3.1415927) * 0.0055555557;
    else
      v19 = FLOAT_N1_0;
    v3->m_fHalfVerticalFOV = v19;
    if ( v12 )
      v20 = (float)(*v12 * 3.1415927) * 0.0055555557;
    else
      v20 = FLOAT_N1_0;
    v3->m_fExtraPositivePitch = v20;
    if ( v13 )
      v21 = (float)(*v13 * 3.1415927) * 0.0055555557;
    else
      v21 = FLOAT_N1_0;
    v3->m_fExtraNegativePitch = v21;
    if ( v14 )
      v22 = *v14;
    else
      v22 = FLOAT_N1_0;
    v3->m_fTargetReleaseDistancePastMaxDistance = v22;
    if ( v15 )
      v23 = (float)(*v15 * 3.1415927) * 0.0055555557;
    else
      v23 = FLOAT_N1_0;
    v3->m_fHalfHorizontalIntentionLimiter = v23;
    if ( v16 )
      v24 = (float)((float)(*v16 * 0.5) * 3.1415927) * 0.0055555557;
    else
      v24 = FLOAT_N1_0;
    v3->m_fHalfIdlePriorityConeHorizontalFOV = v24;
    if ( v17 )
      v7 = *v17;
    v3->m_fIdlePriorityConeTime = v7;
    if ( v18 )
      LOBYTE(v18) = *v18;
    v3->m_bConsiderDownedTargets = (char)v18;
    UFG::TargetingProfile::UpdateCachedValues(v3);
  }
}

// File Line: 97
// RVA: 0x55E7C0
void __fastcall UFG::TargetingProfile::UpdateCachedValues(UFG::TargetingProfile *this)
{
  float v1; // xmm0_4
  __m128 v2; // xmm1
  float v3; // xmm0_4

  v1 = 0.0;
  this->m_fMaximumTargetDistanceSquared = 0.0;
  this->m_fMaximumHalfHorizontalFOVWithLimiter = 0.0;
  v2 = (__m128)LODWORD(this->m_ConeDistancesSquared[0]);
  if ( v2.m128_f32[0] < 0.0 )
    v2 = 0i64;
  LODWORD(this->m_fMaximumTargetDistanceSquared) = v2.m128_i32[0];
  if ( this->m_HalfHorizontalFOVs[0] >= 0.0 )
    v1 = this->m_HalfHorizontalFOVs[0];
  this->m_fMaximumHalfHorizontalFOVWithLimiter = v1;
  if ( v2.m128_f32[0] <= this->m_ConeDistancesSquared[1] )
    v2 = (__m128)LODWORD(this->m_ConeDistancesSquared[1]);
  LODWORD(this->m_fMaximumTargetDistanceSquared) = v2.m128_i32[0];
  if ( v1 <= this->m_HalfHorizontalFOVs[1] )
    v1 = this->m_HalfHorizontalFOVs[1];
  this->m_fMaximumHalfHorizontalFOVWithLimiter = v1;
  if ( v2.m128_f32[0] <= this->m_ConeDistancesSquared[2] )
    v2 = (__m128)LODWORD(this->m_ConeDistancesSquared[2]);
  LODWORD(this->m_fMaximumTargetDistanceSquared) = v2.m128_i32[0];
  if ( v1 <= this->m_HalfHorizontalFOVs[2] )
    v1 = this->m_HalfHorizontalFOVs[2];
  this->m_fMaximumHalfHorizontalFOVWithLimiter = v1;
  if ( v2.m128_f32[0] <= this->m_ConeDistancesSquared[3] )
    v2 = (__m128)LODWORD(this->m_ConeDistancesSquared[3]);
  LODWORD(this->m_fMaximumTargetDistanceSquared) = v2.m128_i32[0];
  if ( v1 <= this->m_HalfHorizontalFOVs[3] )
    v1 = this->m_HalfHorizontalFOVs[3];
  this->m_fMaximumHalfHorizontalFOVWithLimiter = v1;
  if ( v2.m128_f32[0] <= this->m_ConeDistancesSquared[4] )
    v2 = (__m128)LODWORD(this->m_ConeDistancesSquared[4]);
  LODWORD(this->m_fMaximumTargetDistanceSquared) = v2.m128_i32[0];
  if ( v1 <= this->m_HalfHorizontalFOVs[4] )
    v1 = this->m_HalfHorizontalFOVs[4];
  this->m_fMaximumHalfHorizontalFOVWithLimiter = v1;
  if ( v2.m128_f32[0] <= this->m_ConeDistancesSquared[5] )
    v2 = (__m128)LODWORD(this->m_ConeDistancesSquared[5]);
  LODWORD(this->m_fMaximumTargetDistanceSquared) = v2.m128_i32[0];
  if ( v1 <= this->m_HalfHorizontalFOVs[5] )
    v1 = this->m_HalfHorizontalFOVs[5];
  this->m_fMaximumHalfHorizontalFOVWithLimiter = v1 + this->m_fHalfHorizontalIntentionLimiter;
  LODWORD(v3) = (unsigned __int128)_mm_sqrt_ps(v2);
  this->m_fTargetReleaseDistanceSquared = (float)(v3 + this->m_fTargetReleaseDistancePastMaxDistance)
                                        * (float)(v3 + this->m_fTargetReleaseDistancePastMaxDistance);
}

// File Line: 140
// RVA: 0x1543C60
__int64 dynamic_initializer_for__UFG::TargetingProfiles::ms_TargetingProfilePool__()
{
  `eh vector constructor iterator(
    UFG::TargetingProfiles::ms_TargetingProfilePool.p,
    0x80ui64,
    16,
    (void (__fastcall *)(void *))hkQueue<hkJobQueue::JobQueueEntry>::hkQueue<hkJobQueue::JobQueueEntry>);
  UFG::TargetingProfiles::ms_TargetingProfilePool.size = 0;
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingProfiles::ms_TargetingProfilePool__);
}

// File Line: 141
// RVA: 0x1543CB0
__int64 dynamic_initializer_for__UFG::TargetingProfiles::ms_TargetingProfiles__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::TargetingProfiles::ms_TargetingProfiles.mTree);
  return atexit(dynamic_atexit_destructor_for__UFG::TargetingProfiles::ms_TargetingProfiles__);
}

// File Line: 144
// RVA: 0x550560
void UFG::TargetingProfiles::StaticInit(void)
{
  UFG::qPropertySet *v0; // rbx
  UFG::qPropertyList *v1; // rax
  UFG::qPropertyList *v2; // rbp
  unsigned int v3; // esi
  unsigned int v4; // edi
  UFG::qSymbol *v5; // rax
  UFG::qSymbolUC *v6; // rbx
  UFG::qPropertySet *v7; // rax
  unsigned int v8; // ecx
  UFG::qBaseNodeRB *v9; // rbx
  char *v10; // rax
  char *v11; // rax
  char *v12; // rax
  char *v13; // rax
  UFG::qSymbol name; // [rsp+40h] [rbp+8h]
  UFG::qSymbol result; // [rsp+48h] [rbp+10h]

  UFG::qSymbol::create_from_string(&result, "Targeting-TargetingProfiles-manifest");
  v0 = UFG::PropertySetManager::GetPropertySet(&result);
  if ( v0 )
  {
    UFG::qSymbol::create_from_string(&name, "archetypes");
    v1 = UFG::qPropertySet::Get<UFG::qPropertyList>(v0, &name, DEPTH_RECURSE);
    v2 = v1;
    if ( v1 )
    {
      v3 = v1->mNumElements;
      v4 = 0;
      if ( v3 )
      {
        do
        {
          v5 = UFG::qPropertyList::Get<UFG::qSymbol>(v2, v4);
          v6 = (UFG::qSymbolUC *)v5;
          if ( v5 )
          {
            v7 = UFG::PropertySetManager::GetPropertySet(v5);
            if ( v7 )
            {
              v8 = UFG::TargetingProfiles::ms_TargetingProfilePool.size;
              if ( UFG::TargetingProfiles::ms_TargetingProfilePool.size >= 0x10 )
              {
                v10 = UFG::qSymbol::as_cstr_dbg(v6);
                UFG::qPrintf("WARNING: TargetingProfile::StaticInit: Pool is Full (%d) Not Adding (%s)\n", 16i64, v10);
              }
              else
              {
                ++UFG::TargetingProfiles::ms_TargetingProfilePool.size;
                v9 = &UFG::TargetingProfiles::ms_TargetingProfilePool.p[(unsigned __int64)v8].mNode;
                UFG::TargetingProfile::InitFromPropertySet(
                  &UFG::TargetingProfiles::ms_TargetingProfilePool.p[(unsigned __int64)v8],
                  v7);
                UFG::qBaseTreeRB::Add(&UFG::TargetingProfiles::ms_TargetingProfiles.mTree, v9);
              }
            }
            else
            {
              v11 = UFG::qSymbol::as_cstr_dbg(v6);
              UFG::qPrintf("WARNING: TargetingProfile::StaticInit: Profile Not Found: %s\n", v11);
            }
          }
          ++v4;
        }
        while ( v4 < v3 );
      }
    }
    else
    {
      v12 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&name);
      UFG::qPrintf("WARNING: TargetingProfile::StaticInit: Property List Not Found: %s\n", v12);
    }
  }
  else
  {
    v13 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
    UFG::qPrintf("WARNING: TargetingProfile::StaticInit: Manifest File Not Found: %s\n", v13);
  }
}

