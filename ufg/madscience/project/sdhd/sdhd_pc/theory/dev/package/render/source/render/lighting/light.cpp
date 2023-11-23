// File Line: 27
// RVA: 0x14541A0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_Render::rIrradianceVolume_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("Render::rIrradianceVolume", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    &UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::sInventory,
    "Render::rIrradianceVolume",
    v0);
  UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<Render::rIrradianceVolume>::`vftable;
  UFG::qReflectInventory<Render::rIrradianceVolume>::OnAddToWarehouse(&UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(v1, &UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::sInventory);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::qReflectObjectType_Render::rIrradianceVolume_UFG::qReflectObject_::sInventory__);
}

// File Line: 125
// RVA: 0x281C0
_BOOL8 __fastcall Render::IsLightOn(Render::Light *light, float currentTime)
{
  float mOnTime; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm6_4
  int data; // [rsp+68h] [rbp+10h] BYREF

  mOnTime = light->mOnTime;
  v5 = light->mOffTime - mOnTime;
  if ( v5 < 0.0 )
    v5 = v5 + 86400.0;
  if ( (float)(86400.0 - v5) >= 7200.0 )
  {
    data = (int)light;
    v6 = (float)((float)(unsigned __int16)UFG::qDataHash32(&data, 4ui64, 0xFFFFFFFF) * 0.000015259022) * 3600.0;
    mOnTime = v6 + light->mOnTime;
    v5 = (float)(light->mOffTime - v6) - mOnTime;
    if ( v5 < 0.0 )
      v5 = v5 + 86400.0;
  }
  v7 = currentTime - mOnTime;
  if ( v7 < 0.0 )
    v7 = v7 + 86400.0;
  return v7 <= v5;
}

// File Line: 152
// RVA: 0x28360
void __fastcall Render::UpdateInventoryLights(float currentTime)
{
  UFG::qBaseTreeRB *v1; // rax
  UFG::qBaseTreeRB *Next; // rbx
  int *p_mCount; // r15
  __int64 v4; // rax
  char *v5; // rsi
  __int64 i; // rdi
  __int64 v7; // rax
  char *v8; // rdx
  BOOL IsLightOn; // eax
  char v10; // cl
  char *v11; // rbp
  __int64 j; // rdi
  UFG::qBaseNodeRB *v13; // rax
  char *v14; // rdx
  BOOL v15; // eax
  char v16; // cl
  char *v17; // rbp
  __int64 k; // rdi
  UFG::qBaseNodeRB *mParent; // rax
  char *v20; // rdx
  BOOL v21; // eax
  char v22; // cl
  char *v23; // rbp
  __int64 m; // rdi
  UFG::qBaseNodeRB *v25; // rax
  char *v26; // rdx
  BOOL v27; // eax
  char v28; // cl

  if ( uid
    && (v1 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&stru_142134FA0, uid)) != 0i64
    && (Next = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142134FA0, &v1->mRoot)) != 0i64
    || (Next = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142134FA0)) != 0i64 )
  {
    p_mCount = &Next[1].mCount;
    v4 = *(_QWORD *)&Next[1].mCount;
    if ( v4 )
      v5 = (char *)p_mCount + v4 + LODWORD(Next[2].mRoot.mChild[0]);
    else
      v5 = 0i64;
    for ( i = 0i64; (unsigned int)i < HIDWORD(Next[2].mRoot.mChild[0]); i = (unsigned int)(i + 1) )
    {
      if ( (v5[i] & 1) != 0 )
      {
        v7 = *(_QWORD *)&Next[1].mRoot.mUID;
        if ( v7 )
          v8 = (char *)&Next[1].mRoot.mChild[2] + v7;
        else
          v8 = 0i64;
        IsLightOn = Render::IsLightOn((Render::Light *)&v8[160 * i], currentTime);
        v10 = 1;
        if ( IsLightOn )
          v10 = 3;
        v5[i] = v10;
      }
    }
    if ( *(_QWORD *)p_mCount )
      v11 = (char *)p_mCount + *(_QWORD *)p_mCount;
    else
      v11 = 0i64;
    for ( j = 0i64; (unsigned int)j < LODWORD(Next[2].mRoot.mChild[0]); j = (unsigned int)(j + 1) )
    {
      if ( (v11[j] & 1) != 0 )
      {
        v13 = Next[1].mRoot.mChild[1];
        if ( v13 )
          v14 = (char *)&Next[1].mRoot.mChild[1] + (_QWORD)v13;
        else
          v14 = 0i64;
        v15 = Render::IsLightOn((Render::Light *)&v14[160 * j], currentTime);
        v16 = 1;
        if ( v15 )
          v16 = 3;
        v11[j] = v16;
      }
    }
    if ( *(_QWORD *)p_mCount )
      v17 = (char *)p_mCount
          + *(_QWORD *)p_mCount
          + (unsigned int)(HIDWORD(Next[2].mRoot.mChild[0]) + LODWORD(Next[2].mRoot.mChild[0]));
    else
      v17 = 0i64;
    for ( k = 0i64; (unsigned int)k < LODWORD(Next[2].mRoot.mChild[1]); k = (unsigned int)(k + 1) )
    {
      if ( (v17[k] & 1) != 0 )
      {
        mParent = Next[1].mNULL.mParent;
        if ( mParent )
          v20 = (char *)&Next[1].mNULL + (_QWORD)mParent;
        else
          v20 = 0i64;
        v21 = Render::IsLightOn((Render::Light *)&v20[160 * k], currentTime);
        v22 = 1;
        if ( v21 )
          v22 = 3;
        v17[k] = v22;
      }
    }
    if ( *(_QWORD *)p_mCount )
      v23 = (char *)p_mCount
          + *(_QWORD *)p_mCount
          + (unsigned int)(HIDWORD(Next[2].mRoot.mChild[0])
                         + LODWORD(Next[2].mRoot.mChild[1])
                         + LODWORD(Next[2].mRoot.mChild[0]));
    else
      v23 = 0i64;
    for ( m = 0i64; (unsigned int)m < HIDWORD(Next[2].mRoot.mChild[1]); m = (unsigned int)(m + 1) )
    {
      if ( (v23[m] & 1) != 0 )
      {
        v25 = Next[1].mNULL.mChild[0];
        if ( v25 )
          v26 = (char *)Next[1].mNULL.mChild + (_QWORD)v25;
        else
          v26 = 0i64;
        v27 = Render::IsLightOn((Render::Light *)&v26[160 * m], currentTime);
        v28 = 1;
        if ( v27 )
          v28 = 3;
        v23[m] = v28;
      }
    }
    uid = Next->mRoot.mUID;
  }
}

// File Line: 243
// RVA: 0x27D70
void __fastcall Render::BuildShadowSpotView(
        UFG::qMatrix44 *shadowWorldView,
        UFG::qMatrix44 *shadowProjection,
        UFG::qMatrix44 *transform,
        float fNear,
        float fFar,
        float fFov,
        float fAspectRatio)
{
  UFG::qPerspectiveMatrix(shadowProjection, fFov, fAspectRatio, fNear, fFar);
  UFG::qInverseAffine(shadowWorldView, transform);
}

// File Line: 255
// RVA: 0x27DC0
void __fastcall Render::EnableLightLayer(unsigned int layerUID, bool enable)
{
  const char *v4; // r8
  Render::SkinningCacheNode *Head; // rax
  UFG::qBaseTreeRB *Next; // rcx
  int *p_mCount; // r11
  __int64 v8; // rax
  char *v9; // r10
  __int64 i; // rdx
  __int64 v11; // rax
  char *v12; // r9
  char *v13; // r10
  __int64 j; // rdx
  UFG::qBaseNodeRB *v15; // rax
  char *v16; // r9
  char *v17; // r10
  __int64 k; // rdx
  UFG::qBaseNodeRB *mParent; // rax
  char *v20; // r8
  char *v21; // r10
  __int64 m; // rdx
  UFG::qBaseNodeRB *v23; // rax
  char *v24; // r9
  int *v25; // r11
  __int64 v26; // rax
  char *v27; // r10
  __int64 n; // rdx
  __int64 v29; // rax
  char *v30; // r9
  char *v31; // r10
  __int64 ii; // rdx
  UFG::qBaseNodeRB *v33; // rax
  char *v34; // r9
  char *v35; // r10
  __int64 jj; // rdx
  UFG::qBaseNodeRB *v37; // rax
  char *v38; // r8
  char *v39; // r10
  __int64 kk; // rdx
  UFG::qBaseNodeRB *v41; // rax
  char *v42; // r9

  v4 = "false";
  if ( enable )
    v4 = "true";
  UFG::qPrintf("EnableLightLayer called: layerUID = %x, enable=%s\n", layerUID, v4);
  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142134FA0);
  Next = (UFG::qBaseTreeRB *)Head;
  if ( enable )
  {
    if ( Head )
    {
      do
      {
        p_mCount = &Next[1].mCount;
        v8 = *(_QWORD *)&Next[1].mCount;
        if ( v8 )
          v9 = (char *)p_mCount + v8 + LODWORD(Next[2].mRoot.mChild[0]);
        else
          v9 = 0i64;
        for ( i = 0i64; (unsigned int)i < HIDWORD(Next[2].mRoot.mChild[0]); i = (unsigned int)(i + 1) )
        {
          v11 = *(_QWORD *)&Next[1].mRoot.mUID;
          if ( v11 )
            v12 = (char *)&Next[1].mRoot.mChild[2] + v11;
          else
            v12 = 0i64;
          if ( *(_DWORD *)&v12[160 * i + 108] == layerUID )
            v9[i] |= 1u;
        }
        if ( *(_QWORD *)p_mCount )
          v13 = (char *)p_mCount + *(_QWORD *)p_mCount;
        else
          v13 = 0i64;
        for ( j = 0i64; (unsigned int)j < LODWORD(Next[2].mRoot.mChild[0]); j = (unsigned int)(j + 1) )
        {
          v15 = Next[1].mRoot.mChild[1];
          if ( v15 )
            v16 = (char *)&Next[1].mRoot.mChild[1] + (_QWORD)v15;
          else
            v16 = 0i64;
          if ( *(_DWORD *)&v16[160 * j + 108] == layerUID )
            v13[j] |= 1u;
        }
        if ( *(_QWORD *)p_mCount )
          v17 = (char *)p_mCount
              + *(_QWORD *)p_mCount
              + (unsigned int)(LODWORD(Next[2].mRoot.mChild[0]) + HIDWORD(Next[2].mRoot.mChild[0]));
        else
          v17 = 0i64;
        for ( k = 0i64; (unsigned int)k < LODWORD(Next[2].mRoot.mChild[1]); k = (unsigned int)(k + 1) )
        {
          mParent = Next[1].mNULL.mParent;
          if ( mParent )
            v20 = (char *)&Next[1].mNULL + (_QWORD)mParent;
          else
            v20 = 0i64;
          if ( *(_DWORD *)&v20[160 * k + 108] == layerUID )
            v17[k] |= 1u;
        }
        if ( *(_QWORD *)p_mCount )
          v21 = (char *)p_mCount
              + *(_QWORD *)p_mCount
              + (unsigned int)(LODWORD(Next[2].mRoot.mChild[0])
                             + LODWORD(Next[2].mRoot.mChild[1])
                             + HIDWORD(Next[2].mRoot.mChild[0]));
        else
          v21 = 0i64;
        for ( m = 0i64; (unsigned int)m < HIDWORD(Next[2].mRoot.mChild[1]); m = (unsigned int)(m + 1) )
        {
          v23 = Next[1].mNULL.mChild[0];
          if ( v23 )
            v24 = (char *)Next[1].mNULL.mChild + (_QWORD)v23;
          else
            v24 = 0i64;
          if ( *(_DWORD *)&v24[160 * m + 108] == layerUID )
            v21[m] |= 1u;
        }
        Next = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142134FA0, &Next->mRoot);
      }
      while ( Next );
    }
  }
  else if ( Head )
  {
    do
    {
      v25 = &Next[1].mCount;
      v26 = *(_QWORD *)&Next[1].mCount;
      if ( v26 )
        v27 = (char *)v25 + v26 + LODWORD(Next[2].mRoot.mChild[0]);
      else
        v27 = 0i64;
      for ( n = 0i64; (unsigned int)n < HIDWORD(Next[2].mRoot.mChild[0]); n = (unsigned int)(n + 1) )
      {
        v29 = *(_QWORD *)&Next[1].mRoot.mUID;
        if ( v29 )
          v30 = (char *)&Next[1].mRoot.mChild[2] + v29;
        else
          v30 = 0i64;
        if ( *(_DWORD *)&v30[160 * n + 108] == layerUID )
          v27[n] &= 0xFCu;
      }
      if ( *(_QWORD *)v25 )
        v31 = (char *)v25 + *(_QWORD *)v25;
      else
        v31 = 0i64;
      for ( ii = 0i64; (unsigned int)ii < LODWORD(Next[2].mRoot.mChild[0]); ii = (unsigned int)(ii + 1) )
      {
        v33 = Next[1].mRoot.mChild[1];
        if ( v33 )
          v34 = (char *)&Next[1].mRoot.mChild[1] + (_QWORD)v33;
        else
          v34 = 0i64;
        if ( *(_DWORD *)&v34[160 * ii + 108] == layerUID )
          v31[ii] &= 0xFCu;
      }
      if ( *(_QWORD *)v25 )
        v35 = (char *)v25
            + *(_QWORD *)v25
            + (unsigned int)(HIDWORD(Next[2].mRoot.mChild[0]) + LODWORD(Next[2].mRoot.mChild[0]));
      else
        v35 = 0i64;
      for ( jj = 0i64; (unsigned int)jj < LODWORD(Next[2].mRoot.mChild[1]); jj = (unsigned int)(jj + 1) )
      {
        v37 = Next[1].mNULL.mParent;
        if ( v37 )
          v38 = (char *)&Next[1].mNULL + (_QWORD)v37;
        else
          v38 = 0i64;
        if ( *(_DWORD *)&v38[160 * jj + 108] == layerUID )
          v35[jj] &= 0xFCu;
      }
      if ( *(_QWORD *)v25 )
        v39 = (char *)v25
            + *(_QWORD *)v25
            + (unsigned int)(HIDWORD(Next[2].mRoot.mChild[0])
                           + LODWORD(Next[2].mRoot.mChild[0])
                           + LODWORD(Next[2].mRoot.mChild[1]));
      else
        v39 = 0i64;
      for ( kk = 0i64; (unsigned int)kk < HIDWORD(Next[2].mRoot.mChild[1]); kk = (unsigned int)(kk + 1) )
      {
        v41 = Next[1].mNULL.mChild[0];
        if ( v41 )
          v42 = (char *)Next[1].mNULL.mChild + (_QWORD)v41;
        else
          v42 = 0i64;
        if ( *(_DWORD *)&v42[160 * kk + 108] == layerUID )
          v39[kk] &= 0xFCu;
      }
      Next = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142134FA0, &Next->mRoot);
    }
    while ( Next );
  }
}

// File Line: 369
// RVA: 0x27970
char __fastcall Render::AddLightContributionToHarmonic(
        Render::SphericalHarmonic *sh,
        Render::Light *light,
        UFG::qVector3 *probe_pos,
        UFG::qMatrix44 *world_local,
        float luminance_threshold,
        float radius_boost)
{
  char mType; // dl
  float v10; // xmm7_4
  float v11; // xmm8_4
  __m128 x_low; // xmm9
  __m128 v13; // xmm2
  float v14; // xmm3_4
  float v15; // xmm0_4
  float mDecayPower; // xmm4_4
  float v17; // xmm13_4
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm12_4
  float v25; // xmm4_4
  float v26; // xmm5_4
  float v27; // xmm12_4
  float v28; // xmm6_4
  float v29; // xmm15_4
  float v30; // xmm14_4
  int v31; // xmm11_4
  int v32; // xmm9_4
  int v33; // xmm10_4
  float v34; // xmm7_4
  float v35; // xmm9_4
  __int64 mNumHelperLights; // rax
  float v38; // [rsp+20h] [rbp-E8h]
  float v39; // [rsp+24h] [rbp-E4h]
  UFG::qVector3 direction; // [rsp+38h] [rbp-D0h] BYREF
  UFG::qColour colour; // [rsp+48h] [rbp-C0h] BYREF

  mType = light->mType;
  if ( mType == 2 )
    return 0;
  v10 = light->mTransform.v3.z - probe_pos->z;
  v11 = light->mTransform.v3.y - probe_pos->y;
  x_low = (__m128)LODWORD(light->mTransform.v3.x);
  x_low.m128_f32[0] = x_low.m128_f32[0] - probe_pos->x;
  v13 = x_low;
  v13.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v11 * v11)) + (float)(v10 * v10);
  LODWORD(v14) = _mm_sqrt_ps(v13).m128_u32[0];
  if ( (`Render::Light::LuminanceAndColourAtDistanceApprox::`2::`local static guard & 1) == 0 )
  {
    `Render::Light::LuminanceAndColourAtDistanceApprox::`2::`local static guard |= 1u;
    `Render::Light::LuminanceAndColourAtDistanceApprox::`2::luminance_mul = LODWORD(FLOAT_0_30000001);
    dword_142134D0C = LODWORD(FLOAT_0_5);
    dword_142134D10 = LODWORD(FLOAT_0_2);
  }
  v15 = radius_boost * light->mDecayRadius;
  mDecayPower = light->mDecayPower;
  v17 = *(float *)&FLOAT_1_0;
  if ( (float)(mDecayPower + 1.0) < 1.5 )
    v18 = *(float *)&FLOAT_1_0;
  else
    v18 = radius_boost * light->mDecayRadius;
  v19 = v18 * v15;
  if ( (float)(mDecayPower + 1.0) < 2.5 )
    v15 = *(float *)&FLOAT_1_0;
  v20 = 1.0 / (float)(v19 * v15);
  v21 = mDecayPower < 1.5 ? *(float *)&FLOAT_1_0 : v14;
  v22 = v21 * v14;
  v23 = mDecayPower < 2.5 ? *(float *)&FLOAT_1_0 : v14;
  v24 = (float)(1.0 / (float)(v22 * v23)) - (float)(v20 * v14);
  if ( v24 <= 0.0 )
  {
    v24 = 0.0;
  }
  else if ( v24 >= 1.0 )
  {
    v24 = *(float *)&FLOAT_1_0;
  }
  v38 = v24 * light->mColor.x;
  v25 = v38;
  v39 = v24 * light->mColor.y;
  v26 = v39;
  v27 = v24 * light->mColor.z;
  if ( (float)((float)((float)(v39 * *(float *)&dword_142134D0C)
                     + (float)(v38 * *(float *)&`Render::Light::LuminanceAndColourAtDistanceApprox::`2::luminance_mul))
             + (float)(v27 * *(float *)&dword_142134D10)) <= luminance_threshold )
    return 0;
  v28 = (float)(1.0 / v14) * x_low.m128_f32[0];
  v29 = (float)(1.0 / v14) * v11;
  v30 = (float)(1.0 / v14) * v10;
  if ( mType == 1 || (unsigned __int8)(mType - 4) <= 1u )
  {
    v31 = LODWORD(light->mTransform.v2.x) ^ _xmm[0];
    v32 = LODWORD(light->mTransform.v2.y) ^ _xmm[0];
    v33 = LODWORD(light->mTransform.v2.z) ^ _xmm[0];
    v34 = cosf(light->mFovHalfOuter);
    v35 = (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(v29) ^ _xmm[0]) * *(float *)&v32)
                                + (float)(COERCE_FLOAT(LODWORD(v28) ^ _xmm[0]) * *(float *)&v31))
                        + (float)(COERCE_FLOAT(LODWORD(v30) ^ _xmm[0]) * *(float *)&v33))
                - v34)
        / (float)(cosf(light->mFovHalfInner) - v34);
    if ( v35 <= 0.0 )
    {
      v35 = 0.0;
    }
    else if ( v35 >= 1.0 )
    {
      goto LABEL_27;
    }
    v17 = v35;
LABEL_27:
    v25 = v38 * v17;
    v26 = v39 * v17;
    v27 = v27 * v17;
  }
  direction.x = (float)((float)(v29 * world_local->v1.x) + (float)(v28 * world_local->v0.x))
              + (float)(v30 * world_local->v2.x);
  direction.y = (float)((float)(v29 * world_local->v1.y) + (float)(v28 * world_local->v0.y))
              + (float)(v30 * world_local->v2.y);
  direction.z = (float)((float)(v29 * world_local->v1.z) + (float)(v28 * world_local->v0.z))
              + (float)(v30 * world_local->v2.z);
  colour.r = v25;
  colour.g = v26;
  colour.b = v27;
  colour.a = 1.0;
  Render::SphericalHarmonic::EvalDirectionalLight(sh, &direction, &colour);
  mNumHelperLights = sh->mNumHelperLights;
  if ( (unsigned int)mNumHelperLights < 0x10 )
  {
    sh->mHelperLight[mNumHelperLights] = light;
    ++sh->mNumHelperLights;
  }
  return 1;
}

// File Line: 603
// RVA: 0x14540F0
__int64 dynamic_initializer_for__Render::UILightGroup::sDebugLightGroup__()
{
  UFG::qResourceHandle::qResourceHandle(&Render::UILightGroup::sDebugLightGroup);
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::UILightGroup::sDebugLightGroup__);
}

