// File Line: 27
// RVA: 0x14541A0
__int64 dynamic_initializer_for__UFG::qReflectObjectType_Render::rIrradianceVolume_UFG::qReflectObject_::sInventory__()
{
  unsigned __int64 v0; // rax
  UFG::qReflectWarehouse *v1; // rax

  v0 = UFG::qStringHash64("Render::rIrradianceVolume", 0xFFFFFFFFFFFFFFFFui64);
  UFG::qReflectInventoryBase::qReflectInventoryBase(
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::sInventory.vfptr,
    "Render::rIrradianceVolume",
    v0);
  UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::sInventory.vfptr = (UFG::qReflectInventoryBaseVtbl *)&UFG::qReflectInventory<Render::rIrradianceVolume>::`vftable';
  UFG::qReflectInventory<Render::rIrradianceVolume>::OnAddToWarehouse(&UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::sInventory);
  v1 = UFG::qReflectWarehouse::Instance();
  UFG::qReflectWarehouse::Add(
    v1,
    (UFG::qReflectInventoryBase *)&UFG::qReflectObjectType<Render::rIrradianceVolume,UFG::qReflectObject>::sInventory.vfptr);
  return atexit(dynamic_atexit_destructor_for__UFG::qReflectObjectType_Render::rIrradianceVolume_UFG::qReflectObject_::sInventory__);
}

// File Line: 125
// RVA: 0x281C0
_BOOL8 __fastcall Render::IsLightOn(Render::Light *light, float currentTime)
{
  Render::Light *v2; // rbx
  float v3; // xmm6_4
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm6_4
  int data; // [rsp+68h] [rbp+10h]

  v2 = light;
  v3 = currentTime;
  v4 = light->mOnTime;
  v5 = light->mOffTime - v4;
  if ( v5 < 0.0 )
    v5 = v5 + 86400.0;
  if ( (float)(86400.0 - v5) >= 7200.0 )
  {
    data = (signed int)light;
    v6 = (float)((float)(unsigned __int16)UFG::qDataHash32(&data, 4ui64, 0xFFFFFFFF) * 0.000015259022) * 3600.0;
    v4 = v6 + v2->mOnTime;
    v5 = (float)(v2->mOffTime - v6) - v4;
    if ( v5 < 0.0 )
      v5 = v5 + 86400.0;
  }
  v7 = v3 - v4;
  if ( v7 < 0.0 )
    v7 = v7 + 86400.0;
  return v7 <= v5;
}

// File Line: 152
// RVA: 0x28360
void __fastcall Render::UpdateInventoryLights(float currentTime)
{
  UFG::qBaseTreeRB *v1; // rax
  UFG::qBaseTreeRB *v2; // rbx
  int *v3; // r15
  __int64 v4; // rax
  char *v5; // rsi
  __int64 v6; // rdi
  __int64 v7; // rax
  signed __int64 v8; // rdx
  BOOL v9; // eax
  char v10; // cl
  char *v11; // rbp
  __int64 v12; // rdi
  UFG::qBaseNodeRB *v13; // rax
  signed __int64 v14; // rdx
  BOOL v15; // eax
  char v16; // cl
  char *v17; // rbp
  __int64 v18; // rdi
  UFG::qBaseNodeRB *v19; // rax
  signed __int64 v20; // rdx
  BOOL v21; // eax
  char v22; // cl
  char *v23; // rbp
  __int64 v24; // rdi
  UFG::qBaseNodeRB *v25; // rax
  signed __int64 v26; // rdx
  BOOL v27; // eax
  char v28; // cl

  if ( uid
    && (v1 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&stru_142134FA0, uid)) != 0i64
    && (v2 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142134FA0, &v1->mRoot)) != 0i64
    || (v2 = (UFG::qBaseTreeRB *)UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142134FA0)) != 0i64 )
  {
    v3 = &v2[1].mCount;
    v4 = *(_QWORD *)&v2[1].mCount;
    if ( v4 )
      v5 = (char *)v3 + v4 + LODWORD(v2[2].mRoot.mChild[0]);
    else
      v5 = 0i64;
    v6 = 0i64;
    if ( HIDWORD(v2[2].mRoot.mChild[0]) )
    {
      do
      {
        if ( v5[v6] & 1 )
        {
          v7 = *(_QWORD *)&v2[1].mRoot.mUID;
          if ( v7 )
            v8 = (signed __int64)&v2[1].mRoot.mUID + v7;
          else
            v8 = 0i64;
          v9 = Render::IsLightOn((Render::Light *)(v8 + 160 * v6), currentTime);
          v10 = 1;
          if ( v9 )
            v10 = 3;
          v5[v6] = v10;
        }
        v6 = (unsigned int)(v6 + 1);
      }
      while ( (unsigned int)v6 < HIDWORD(v2[2].mRoot.mChild[0]) );
    }
    if ( *(_QWORD *)v3 )
      v11 = (char *)v3 + *(_QWORD *)v3;
    else
      v11 = 0i64;
    v12 = 0i64;
    if ( LODWORD(v2[2].mRoot.mChild[0]) )
    {
      do
      {
        if ( v11[v12] & 1 )
        {
          v13 = v2[1].mRoot.mChild[1];
          if ( v13 )
            v14 = (signed __int64)&v2[1].mRoot.mChild[1] + (_QWORD)v13;
          else
            v14 = 0i64;
          v15 = Render::IsLightOn((Render::Light *)(v14 + 160 * v12), currentTime);
          v16 = 1;
          if ( v15 )
            v16 = 3;
          v11[v12] = v16;
        }
        v12 = (unsigned int)(v12 + 1);
      }
      while ( (unsigned int)v12 < LODWORD(v2[2].mRoot.mChild[0]) );
    }
    if ( *(_QWORD *)v3 )
      v17 = (char *)v3 + *(_QWORD *)v3 + (unsigned int)(HIDWORD(v2[2].mRoot.mChild[0]) + LODWORD(v2[2].mRoot.mChild[0]));
    else
      v17 = 0i64;
    v18 = 0i64;
    if ( LODWORD(v2[2].mRoot.mChild[1]) )
    {
      do
      {
        if ( v17[v18] & 1 )
        {
          v19 = v2[1].mNULL.mParent;
          if ( v19 )
            v20 = (signed __int64)&v2[1].mNULL + (_QWORD)v19;
          else
            v20 = 0i64;
          v21 = Render::IsLightOn((Render::Light *)(v20 + 160 * v18), currentTime);
          v22 = 1;
          if ( v21 )
            v22 = 3;
          v17[v18] = v22;
        }
        v18 = (unsigned int)(v18 + 1);
      }
      while ( (unsigned int)v18 < LODWORD(v2[2].mRoot.mChild[1]) );
    }
    if ( *(_QWORD *)v3 )
      v23 = (char *)v3
          + *(_QWORD *)v3
          + (unsigned int)(HIDWORD(v2[2].mRoot.mChild[0])
                         + LODWORD(v2[2].mRoot.mChild[1])
                         + LODWORD(v2[2].mRoot.mChild[0]));
    else
      v23 = 0i64;
    v24 = 0i64;
    if ( HIDWORD(v2[2].mRoot.mChild[1]) )
    {
      do
      {
        if ( v23[v24] & 1 )
        {
          v25 = v2[1].mNULL.mChild[0];
          if ( v25 )
            v26 = (signed __int64)v2[1].mNULL.mChild + (_QWORD)v25;
          else
            v26 = 0i64;
          v27 = Render::IsLightOn((Render::Light *)(v26 + 160 * v24), currentTime);
          v28 = 1;
          if ( v27 )
            v28 = 3;
          v23[v24] = v28;
        }
        v24 = (unsigned int)(v24 + 1);
      }
      while ( (unsigned int)v24 < HIDWORD(v2[2].mRoot.mChild[1]) );
    }
    uid = v2->mRoot.mUID;
  }
}4 = (un

// File Line: 243
// RVA: 0x27D70
void __fastcall Render::BuildShadowSpotView(UFG::qMatrix44 *shadowWorldView, UFG::qMatrix44 *shadowProjection, UFG::qMatrix44 *transform, float fNear, float fFar, float fFov, float fAspectRatio)
{
  UFG::qMatrix44 *v7; // rbx
  UFG::qMatrix44 *v8; // rdi

  v7 = shadowWorldView;
  v8 = transform;
  UFG::qPerspectiveMatrix(shadowProjection, fFov, fAspectRatio, fNear, fFar);
  UFG::qInverseAffine(v7, v8);
}

// File Line: 255
// RVA: 0x27DC0
void __fastcall Render::EnableLightLayer(unsigned int layerUID, bool enable)
{
  bool v2; // bl
  unsigned int v3; // edi
  const char *v4; // r8
  Render::SkinningCacheNode *v5; // rax
  UFG::qBaseTreeRB *v6; // rcx
  int *v7; // r11
  __int64 v8; // rax
  char *v9; // r10
  __int64 v10; // rdx
  __int64 v11; // rax
  signed __int64 v12; // r9
  char *v13; // r10
  __int64 v14; // rdx
  UFG::qBaseNodeRB *v15; // rax
  signed __int64 v16; // r9
  char *v17; // r10
  __int64 v18; // rdx
  UFG::qBaseNodeRB *v19; // rax
  signed __int64 v20; // r8
  char *v21; // r10
  __int64 v22; // rdx
  UFG::qBaseNodeRB *v23; // rax
  signed __int64 v24; // r9
  int *v25; // r11
  __int64 v26; // rax
  char *v27; // r10
  __int64 v28; // rdx
  __int64 v29; // rax
  signed __int64 v30; // r9
  char *v31; // r10
  __int64 v32; // rdx
  UFG::qBaseNodeRB *v33; // rax
  signed __int64 v34; // r9
  char *v35; // r10
  __int64 v36; // rdx
  UFG::qBaseNodeRB *v37; // rax
  signed __int64 v38; // r8
  char *v39; // r10
  __int64 v40; // rdx
  UFG::qBaseNodeRB *v41; // rax
  signed __int64 v42; // r9

  v2 = enable;
  v3 = layerUID;
  v4 = "false";
  if ( enable )
    v4 = "true";
  UFG::qPrintf("EnableLightLayer called: layerUID = %x, enable=%s\n", layerUID, v4);
  v5 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_142134FA0);
  v6 = (UFG::qBaseTreeRB *)v5;
  if ( v2 )
  {
    if ( v5 )
    {
      do
      {
        v7 = &v6[1].mCount;
        v8 = *(_QWORD *)&v6[1].mCount;
        if ( v8 )
          v9 = (char *)v7 + v8 + LODWORD(v6[2].mRoot.mChild[0]);
        else
          v9 = 0i64;
        v10 = 0i64;
        if ( HIDWORD(v6[2].mRoot.mChild[0]) )
        {
          do
          {
            v11 = *(_QWORD *)&v6[1].mRoot.mUID;
            if ( v11 )
              v12 = (signed __int64)&v6[1].mRoot.mUID + v11;
            else
              v12 = 0i64;
            if ( *(_DWORD *)(160 * v10 + v12 + 108) == v3 )
              v9[v10] |= 1u;
            v10 = (unsigned int)(v10 + 1);
          }
          while ( (unsigned int)v10 < HIDWORD(v6[2].mRoot.mChild[0]) );
        }
        if ( *(_QWORD *)v7 )
          v13 = (char *)v7 + *(_QWORD *)v7;
        else
          v13 = 0i64;
        v14 = 0i64;
        if ( LODWORD(v6[2].mRoot.mChild[0]) )
        {
          do
          {
            v15 = v6[1].mRoot.mChild[1];
            if ( v15 )
              v16 = (signed __int64)&v6[1].mRoot.mChild[1] + (_QWORD)v15;
            else
              v16 = 0i64;
            if ( *(_DWORD *)(160 * v14 + v16 + 108) == v3 )
              v13[v14] |= 1u;
            v14 = (unsigned int)(v14 + 1);
          }
          while ( (unsigned int)v14 < LODWORD(v6[2].mRoot.mChild[0]) );
        }
        if ( *(_QWORD *)v7 )
          v17 = (char *)v7
              + *(_QWORD *)v7
              + (unsigned int)(LODWORD(v6[2].mRoot.mChild[0]) + HIDWORD(v6[2].mRoot.mChild[0]));
        else
          v17 = 0i64;
        v18 = 0i64;
        if ( LODWORD(v6[2].mRoot.mChild[1]) )
        {
          do
          {
            v19 = v6[1].mNULL.mParent;
            if ( v19 )
              v20 = (signed __int64)&v6[1].mNULL + (_QWORD)v19;
            else
              v20 = 0i64;
            if ( *(_DWORD *)(160 * v18 + v20 + 108) == v3 )
              v17[v18] |= 1u;
            v18 = (unsigned int)(v18 + 1);
          }
          while ( (unsigned int)v18 < LODWORD(v6[2].mRoot.mChild[1]) );
        }
        if ( *(_QWORD *)v7 )
          v21 = (char *)v7
              + *(_QWORD *)v7
              + (unsigned int)(LODWORD(v6[2].mRoot.mChild[0])
                             + LODWORD(v6[2].mRoot.mChild[1])
                             + HIDWORD(v6[2].mRoot.mChild[0]));
        else
          v21 = 0i64;
        v22 = 0i64;
        if ( HIDWORD(v6[2].mRoot.mChild[1]) )
        {
          do
          {
            v23 = v6[1].mNULL.mChild[0];
            if ( v23 )
              v24 = (signed __int64)v6[1].mNULL.mChild + (_QWORD)v23;
            else
              v24 = 0i64;
            if ( *(_DWORD *)(160 * v22 + v24 + 108) == v3 )
              v21[v22] |= 1u;
            v22 = (unsigned int)(v22 + 1);
          }
          while ( (unsigned int)v22 < HIDWORD(v6[2].mRoot.mChild[1]) );
        }
        v6 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142134FA0, &v6->mRoot);
      }
      while ( v6 );
    }
  }
  else if ( v5 )
  {
    do
    {
      v25 = &v6[1].mCount;
      v26 = *(_QWORD *)&v6[1].mCount;
      if ( v26 )
        v27 = (char *)v25 + v26 + LODWORD(v6[2].mRoot.mChild[0]);
      else
        v27 = 0i64;
      v28 = 0i64;
      if ( HIDWORD(v6[2].mRoot.mChild[0]) )
      {
        do
        {
          v29 = *(_QWORD *)&v6[1].mRoot.mUID;
          if ( v29 )
            v30 = (signed __int64)&v6[1].mRoot.mUID + v29;
          else
            v30 = 0i64;
          if ( *(_DWORD *)(160 * v28 + v30 + 108) == v3 )
            v27[v28] &= 0xFCu;
          v28 = (unsigned int)(v28 + 1);
        }
        while ( (unsigned int)v28 < HIDWORD(v6[2].mRoot.mChild[0]) );
      }
      if ( *(_QWORD *)v25 )
        v31 = (char *)v25 + *(_QWORD *)v25;
      else
        v31 = 0i64;
      v32 = 0i64;
      if ( LODWORD(v6[2].mRoot.mChild[0]) )
      {
        do
        {
          v33 = v6[1].mRoot.mChild[1];
          if ( v33 )
            v34 = (signed __int64)&v6[1].mRoot.mChild[1] + (_QWORD)v33;
          else
            v34 = 0i64;
          if ( *(_DWORD *)(160 * v32 + v34 + 108) == v3 )
            v31[v32] &= 0xFCu;
          v32 = (unsigned int)(v32 + 1);
        }
        while ( (unsigned int)v32 < LODWORD(v6[2].mRoot.mChild[0]) );
      }
      if ( *(_QWORD *)v25 )
        v35 = (char *)v25
            + *(_QWORD *)v25
            + (unsigned int)(HIDWORD(v6[2].mRoot.mChild[0]) + LODWORD(v6[2].mRoot.mChild[0]));
      else
        v35 = 0i64;
      v36 = 0i64;
      if ( LODWORD(v6[2].mRoot.mChild[1]) )
      {
        do
        {
          v37 = v6[1].mNULL.mParent;
          if ( v37 )
            v38 = (signed __int64)&v6[1].mNULL + (_QWORD)v37;
          else
            v38 = 0i64;
          if ( *(_DWORD *)(160 * v36 + v38 + 108) == v3 )
            v35[v36] &= 0xFCu;
          v36 = (unsigned int)(v36 + 1);
        }
        while ( (unsigned int)v36 < LODWORD(v6[2].mRoot.mChild[1]) );
      }
      if ( *(_QWORD *)v25 )
        v39 = (char *)v25
            + *(_QWORD *)v25
            + (unsigned int)(HIDWORD(v6[2].mRoot.mChild[0])
                           + LODWORD(v6[2].mRoot.mChild[0])
                           + LODWORD(v6[2].mRoot.mChild[1]));
      else
        v39 = 0i64;
      v40 = 0i64;
      if ( HIDWORD(v6[2].mRoot.mChild[1]) )
      {
        do
        {
          v41 = v6[1].mNULL.mChild[0];
          if ( v41 )
            v42 = (signed __int64)v6[1].mNULL.mChild + (_QWORD)v41;
          else
            v42 = 0i64;
          if ( *(_DWORD *)(160 * v40 + v42 + 108) == v3 )
            v39[v40] &= 0xFCu;
          v40 = (unsigned int)(v40 + 1);
        }
        while ( (unsigned int)v40 < HIDWORD(v6[2].mRoot.mChild[1]) );
      }
      v6 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_142134FA0, &v6->mRoot);
    }
    while ( v6 );
  }
}

// File Line: 369
// RVA: 0x27970
char __fastcall Render::AddLightContributionToHarmonic(Render::SphericalHarmonic *sh, Render::Light *light, UFG::qVector3 *probe_pos, UFG::qMatrix44 *world_local, const float luminance_threshold, const float radius_boost)
{
  UFG::qMatrix44 *v6; // rsi
  Render::Light *v7; // rbx
  Render::SphericalHarmonic *v8; // rdi
  char v9; // dl
  float v10; // xmm7_4
  float v11; // xmm8_4
  __m128 v12; // xmm9
  __m128 v13; // xmm2
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm4_4
  float v17; // xmm13_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  float v22; // xmm0_4
  float v23; // xmm0_4
  float v24; // xmm1_4
  float v25; // xmm12_4
  float v26; // xmm4_4
  float v27; // xmm5_4
  float v28; // xmm12_4
  float v29; // xmm6_4
  float v30; // xmm15_4
  float v31; // xmm14_4
  int v32; // xmm11_4
  int v33; // xmm9_4
  int v34; // xmm10_4
  float v35; // xmm7_4
  float v36; // xmm9_4
  __int64 v37; // rax
  float v39; // [rsp+20h] [rbp-E8h]
  float v40; // [rsp+24h] [rbp-E4h]
  float v41; // [rsp+28h] [rbp-E0h]
  UFG::qVector3 direction; // [rsp+38h] [rbp-D0h]
  UFG::qColour colour; // [rsp+48h] [rbp-C0h]

  v6 = world_local;
  v7 = light;
  v8 = sh;
  v9 = light->mType;
  if ( v9 == 2 )
    return 0;
  v10 = v7->mTransform.v3.z - probe_pos->z;
  v11 = v7->mTransform.v3.y - probe_pos->y;
  v12 = (__m128)LODWORD(v7->mTransform.v3.x);
  v12.m128_f32[0] = v12.m128_f32[0] - probe_pos->x;
  v13 = v12;
  v13.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v12.m128_f32[0]) + (float)(v11 * v11)) + (float)(v10 * v10);
  LODWORD(v14) = (unsigned __int128)_mm_sqrt_ps(v13);
  if ( !(`Render::Light::LuminanceAndColourAtDistanceApprox'::`2'::`local static guard' & 1) )
  {
    `Render::Light::LuminanceAndColourAtDistanceApprox'::`2'::`local static guard' |= 1u;
    `Render::Light::LuminanceAndColourAtDistanceApprox'::`2'::luminance_mul = LODWORD(FLOAT_0_30000001);
    dword_142134D0C = LODWORD(FLOAT_0_5);
    dword_142134D10 = LODWORD(FLOAT_0_2);
  }
  v15 = radius_boost * v7->mDecayRadius;
  v16 = v7->mDecayPower;
  v17 = *(float *)&FLOAT_1_0;
  v18 = v7->mDecayPower + 1.0;
  if ( v18 < 1.5 )
    v19 = *(float *)&FLOAT_1_0;
  else
    v19 = radius_boost * v7->mDecayRadius;
  v20 = v19 * v15;
  if ( v18 < 2.5 )
    v15 = *(float *)&FLOAT_1_0;
  v21 = 1.0 / (float)(v20 * v15);
  v22 = v16 < 1.5 ? *(float *)&FLOAT_1_0 : v14;
  v23 = v22 * v14;
  v24 = v16 < 2.5 ? *(float *)&FLOAT_1_0 : v14;
  v25 = (float)(1.0 / (float)(v23 * v24)) - (float)(v21 * v14);
  if ( v25 <= 0.0 )
  {
    v25 = 0.0;
  }
  else if ( v25 >= 1.0 )
  {
    v25 = *(float *)&FLOAT_1_0;
  }
  v39 = v25 * v7->mColor.x;
  v26 = v39;
  v40 = v25 * v7->mColor.y;
  v27 = v40;
  v28 = v25 * v7->mColor.z;
  if ( (float)((float)((float)(v40 * *(float *)&dword_142134D0C)
                     + (float)(v39 * *(float *)&`Render::Light::LuminanceAndColourAtDistanceApprox'::`2'::luminance_mul))
             + (float)(v28 * *(float *)&dword_142134D10)) <= luminance_threshold )
    return 0;
  v29 = (float)(1.0 / v14) * v12.m128_f32[0];
  v41 = (float)(1.0 / v14) * v12.m128_f32[0];
  v30 = (float)(1.0 / v14) * v11;
  v31 = (float)(1.0 / v14) * v10;
  if ( v9 == 1 || (unsigned __int8)(v9 - 4) <= 1u )
  {
    v32 = LODWORD(v7->mTransform.v2.x) ^ _xmm[0];
    v33 = LODWORD(v7->mTransform.v2.y) ^ _xmm[0];
    v34 = LODWORD(v7->mTransform.v2.z) ^ _xmm[0];
    v35 = cosf(v7->mFovHalfOuter);
    v36 = (float)((float)((float)((float)(COERCE_FLOAT(LODWORD(v30) ^ _xmm[0]) * *(float *)&v33)
                                + (float)(COERCE_FLOAT(LODWORD(v29) ^ _xmm[0]) * *(float *)&v32))
                        + (float)(COERCE_FLOAT(LODWORD(v31) ^ _xmm[0]) * *(float *)&v34))
                - v35)
        / (float)(cosf(v7->mFovHalfInner) - v35);
    if ( v36 <= 0.0 )
    {
      v36 = 0.0;
    }
    else if ( v36 >= 1.0 )
    {
      goto LABEL_27;
    }
    v17 = v36;
LABEL_27:
    v26 = v39 * v17;
    v27 = v40 * v17;
    v28 = v28 * v17;
    v29 = v41;
  }
  direction.x = (float)((float)(v30 * v6->v1.x) + (float)(v29 * v6->v0.x)) + (float)(v31 * v6->v2.x);
  direction.y = (float)((float)(v30 * v6->v1.y) + (float)(v29 * v6->v0.y)) + (float)(v31 * v6->v2.y);
  direction.z = (float)((float)(v30 * v6->v1.z) + (float)(v29 * v6->v0.z)) + (float)(v31 * v6->v2.z);
  colour.r = v26;
  colour.g = v27;
  colour.b = v28;
  colour.a = 1.0;
  Render::SphericalHarmonic::EvalDirectionalLight(v8, &direction, &colour);
  v37 = v8->mNumHelperLights;
  if ( (unsigned int)v37 < 0x10 )
  {
    v8->mHelperLight[v37] = v7;
    ++v8->mNumHelperLights;
  }
  return 1;
}

// File Line: 603
// RVA: 0x14540F0
__int64 dynamic_initializer_for__Render::UILightGroup::sDebugLightGroup__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&Render::UILightGroup::sDebugLightGroup.mPrev);
  return atexit(dynamic_atexit_destructor_for__Render::UILightGroup::sDebugLightGroup__);
}

