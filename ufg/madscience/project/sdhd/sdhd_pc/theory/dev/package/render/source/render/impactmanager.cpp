// File Line: 13
// RVA: 0x1456980
__int64 dynamic_initializer_for__defaultType__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Default", 0xFFFFFFFF);
  defaultType = result;
  return result;
}

// File Line: 17
// RVA: 0x14569A0
__int64 Render::_dynamic_initializer_for__gImpactManager__()
{
  hkSeekableStreamReader *v0; // rbx
  signed int v1; // edi

  UFG::qBaseTreeRB::qBaseTreeRB(&Render::gImpactManager.mImpactHandlers.mTree);
  v0 = &stru_14213866C;
  v1 = 31;
  do
  {
    Assembly::GetRCX(v0);
    v0 = (hkSeekableStreamReader *)((char *)v0 + 28);
    --v1;
  }
  while ( v1 >= 0 );
  unk_142138668 = 0;
  return atexit(Render::_dynamic_atexit_destructor_for__gImpactManager__);
}

// File Line: 32
// RVA: 0x62800
void __fastcall Render::ImpactManager::Init(Render::ImpactManager *this)
{
  Render::ImpactManager *v1; // r12
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // rbp
  SimpleXML::XMLNode *v4; // rax
  SimpleXML::XMLNode *i; // r15
  const char *v6; // rax
  int v7; // edi
  char *v8; // rax
  UFG::qBaseNodeRB *v9; // rbx
  SimpleXML::XMLNode *v10; // rdi
  UFG::qBaseTreeRB *v11; // r14
  const char *v12; // rax
  int v13; // esi
  char *v14; // rax
  char *v15; // rbx
  const char *v16; // rax
  const char *v17; // rax
  const char *v18; // rax
  float v19; // xmm1_4
  const char *v20; // rax

  v1 = this;
  v2 = SimpleXML::XMLDocument::Open("Data\\Physics\\ImpactProperties.xml", 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    v4 = SimpleXML::XMLDocument::GetNode(v2, "ImpactPropertyList", 0i64);
    if ( v4 )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v3, "Impact", v4);
            i;
            i = SimpleXML::XMLDocument::GetNode(v3, "Impact", i) )
      {
        v6 = SimpleXML::XMLNode::GetAttribute(i, "type", "<unknown>");
        v7 = UFG::qStringHashUpper32(v6, 0xFFFFFFFF);
        v8 = UFG::qMalloc(0x68ui64, "ImpactHandler", 0i64);
        v9 = (UFG::qBaseNodeRB *)v8;
        if ( v8 )
        {
          *(_QWORD *)v8 = 0i64;
          *((_QWORD *)v8 + 1) = 0i64;
          *((_QWORD *)v8 + 2) = 0i64;
          *((_DWORD *)v8 + 6) = v7;
          UFG::qBaseTreeRB::qBaseTreeRB((UFG::qBaseTreeRB *)(v8 + 32));
        }
        else
        {
          v9 = 0i64;
        }
        UFG::qBaseTreeRB::Add(&v1->mImpactHandlers.mTree, v9);
        v10 = SimpleXML::XMLDocument::GetChildNode(v3, "Material", i);
        if ( v10 )
        {
          v11 = (UFG::qBaseTreeRB *)&v9[1];
          do
          {
            v12 = SimpleXML::XMLNode::GetAttribute(v10, "type", "<unknown>");
            v13 = UFG::qStringHashUpper32(v12, 0xFFFFFFFF);
            v14 = UFG::qMalloc(0x30ui64, "ImpactDesc", 0i64);
            v15 = v14;
            if ( v14 )
            {
              *(_QWORD *)v14 = 0i64;
              *((_QWORD *)v14 + 1) = 0i64;
              *((_QWORD *)v14 + 2) = 0i64;
              *((_DWORD *)v14 + 6) = v13;
              *((_QWORD *)v14 + 4) = -1i64;
              *((_DWORD *)v14 + 10) = 0;
              *((_DWORD *)v14 + 11) = 100;
            }
            else
            {
              v15 = 0i64;
            }
            v16 = SimpleXML::XMLNode::GetAttribute(v10, "decal");
            if ( v16 )
              *((_DWORD *)v15 + 9) = UFG::qStringHashUpper32(v16, 0xFFFFFFFF);
            v17 = SimpleXML::XMLNode::GetAttribute(v10, "effect");
            if ( v17 )
              *((_DWORD *)v15 + 8) = UFG::qStringHashUpper32(v17, 0xFFFFFFFF);
            v18 = SimpleXML::XMLNode::GetAttribute(v10, "direction");
            if ( v18 )
            {
              v19 = atof(v18);
              *((float *)v15 + 10) = v19;
              if ( v19 >= -1.0 )
              {
                if ( v19 > 1.0 )
                  *((_DWORD *)v15 + 10) = 1065353216;
              }
              else
              {
                *((_DWORD *)v15 + 10) = -1082130432;
              }
            }
            v20 = SimpleXML::XMLNode::GetAttribute(v10, "decalPercent");
            if ( v20 )
              *((_DWORD *)v15 + 11) = UFG::qToInt32(v20, 0);
            UFG::qBaseTreeRB::Add(v11, (UFG::qBaseNodeRB *)v15);
            v10 = SimpleXML::XMLDocument::GetNode(v3, "Material", v10);
          }
          while ( v10 );
        }
      }
    }
    SimpleXML::XMLDocument::~XMLDocument(v3);
    operator delete[](v3);
  }
}

// File Line: 106
// RVA: 0x61D30
UFG::qBaseTreeRB *__fastcall Render::ImpactManager::GetImpactDesc(Render::ImpactManager *this, unsigned int impactType, unsigned int materialType)
{
  unsigned int v3; // ebx
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseTreeRB *v5; // rdi
  UFG::qBaseTreeRB *result; // rax

  v3 = materialType;
  if ( !impactType
    || (v4 = UFG::qBaseTreeRB::Get(&this->mImpactHandlers.mTree, impactType), (v5 = v4) == 0i64)
    || (!v3 || (result = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)v4 + 32), v3)) == 0i64)
    && (!defaultType || (result = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)v5 + 32), defaultType)) == 0i64) )
  {
    result = 0i64;
  }
  return result;
}

// File Line: 134
// RVA: 0x61A00
void __fastcall Render::CreateEffectMatrix(UFG::qMatrix44 *basis, UFG::qVector3 *vPos, UFG::qVector3 *vDir)
{
  float v3; // xmm5_4
  float v4; // xmm6_4
  __int128 v5; // xmm7
  __m128 v6; // xmm9
  __m128 v7; // xmm8
  __m128 v8; // xmm2
  float v9; // xmm1_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  __m128 v12; // xmm1
  float v13; // xmm2_4
  float v14; // xmm8_4
  float v15; // xmm11_4
  __m128 v16; // xmm10
  float v17; // xmm0_4
  float v18; // xmm8_4
  float v19; // xmm11_4
  __m128 v20; // xmm2
  float v21; // xmm5_4
  float v22; // xmm10_4
  float v23; // xmm2_4
  float v24; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm8_4
  float v27; // xmm6_4
  __m128 v28; // xmm2
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm1_4

  v3 = vDir->x;
  v4 = vDir->y;
  v5 = LODWORD(vDir->z);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(vDir->y * 0.0) + (float)(vDir->x * 0.0)) + *(float *)&v5) & _xmm) <= 0.99 )
  {
    v6 = 0i64;
    v7 = (__m128)(unsigned int)FLOAT_1_0;
  }
  else
  {
    v6 = (__m128)(unsigned int)FLOAT_1_0;
    v7 = 0i64;
  }
  v8 = (__m128)LODWORD(vDir->y);
  v8.m128_f32[0] = (float)((float)(v4 * v4) + (float)(v3 * v3)) + (float)(*(float *)&v5 * *(float *)&v5);
  if ( v8.m128_f32[0] == 0.0 )
    v9 = 0.0;
  else
    v9 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v8));
  v10 = v3 * v9;
  v11 = v4 * v9;
  *(float *)&v5 = *(float *)&v5 * v9;
  v12 = v7;
  basis->v2.w = 0.0;
  basis->v2.x = v10;
  basis->v2.y = v11;
  LODWORD(basis->v2.z) = v5;
  v12.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v6.m128_f32[0] * v6.m128_f32[0]);
  if ( v12.m128_f32[0] == 0.0 )
    v13 = 0.0;
  else
    v13 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v12));
  v14 = v7.m128_f32[0] * v13;
  v6.m128_f32[0] = v6.m128_f32[0] * v13;
  v16 = v6;
  v15 = v13 * 0.0;
  v16.m128_f32[0] = (float)(v6.m128_f32[0] * *(float *)&v5) - (float)(v14 * v11);
  v17 = v13 * 0.0;
  v20 = v16;
  v18 = (float)(v14 * v10) - (float)(v17 * *(float *)&v5);
  v19 = (float)(v15 * v11) - (float)(v6.m128_f32[0] * v10);
  v20.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v18 * v18)) + (float)(v19 * v19);
  if ( v20.m128_f32[0] == 0.0 )
    v21 = 0.0;
  else
    v21 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v20));
  v22 = v16.m128_f32[0] * v21;
  v23 = v21 * v18;
  v24 = v21 * v19;
  basis->v0.w = 0.0;
  basis->v0.x = v22;
  basis->v0.y = v23;
  basis->v0.z = v24;
  v25 = basis->v2.x;
  v26 = (float)(basis->v2.y * v24) - (float)(*(float *)&v5 * v23);
  *(float *)&v5 = (float)(*(float *)&v5 * v22) - (float)(v25 * v24);
  v27 = (float)(v25 * v23) - (float)(basis->v2.y * v22);
  v28 = (__m128)v5;
  v28.m128_f32[0] = (float)((float)(*(float *)&v5 * *(float *)&v5) + (float)(v26 * v26)) + (float)(v27 * v27);
  if ( v28.m128_f32[0] == 0.0 )
    v29 = 0.0;
  else
    v29 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v28));
  basis->v1.w = 0.0;
  basis->v1.z = v29 * v27;
  basis->v1.x = v29 * v26;
  basis->v1.y = v29 * *(float *)&v5;
  v30 = vPos->y;
  v31 = vPos->z;
  basis->v3.x = vPos->x;
  basis->v3.w = 1.0;
  basis->v3.y = v30;
  basis->v3.z = v31;
}

// File Line: 158
// RVA: 0x622A0
void __fastcall Render::ImpactManager::HandleImpactEvent(Render::ImpactManager *this, unsigned int impactType, unsigned int materialType, UFG::qVector3 *vImpact, UFG::qVector3 *vRay, UFG::qVector3 *vNormal, Render::FXSimComponent *fxComponent, int boneID, UFG::qVector3 *vDirectionOut)
{
  UFG::qVector3 *v9; // r14
  unsigned int v10; // edi
  Render::ImpactManager *v11; // rbx
  UFG::qBaseTreeRB *v12; // rax
  UFG::qBaseTreeRB *v13; // rsi
  UFG::qBaseTreeRB *v14; // rdi
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm11_4
  float v18; // xmm12_4
  int v19; // xmm8_4
  float v20; // xmm13_4
  int v21; // xmm9_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm4_4
  float v25; // xmm0_4
  float v26; // xmm5_4
  float v27; // xmm3_4
  float v28; // xmm6_4
  int v29; // xmm0_4
  __m128 v30; // xmm4
  __m128 v31; // xmm2
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  signed __int64 v35; // rcx
  float v36; // xmm0_4
  float v37; // xmm1_4
  int v38; // xmm1_4
  int v39; // xmm0_4
  unsigned int v40; // edx
  SkeletalPose *v41; // rcx
  float v42; // xmm4_4
  float v43; // xmm7_4
  float v44; // xmm5_4
  UFG::qVector3 vDir; // [rsp+30h] [rbp-D0h]
  UFG::qVector3 v46; // [rsp+40h] [rbp-C0h]
  UFG::qVector3 vPos; // [rsp+50h] [rbp-B0h]
  UFG::qMatrix44 d; // [rsp+60h] [rbp-A0h]
  UFG::qMatrix44 matrixWS; // [rsp+A0h] [rbp-60h]

  if ( impactType )
  {
    v9 = vImpact;
    v10 = materialType;
    v11 = this;
    v12 = UFG::qBaseTreeRB::Get(&this->mImpactHandlers.mTree, impactType);
    v13 = v12;
    if ( v12 )
    {
      if ( v10 && (v14 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)v12 + 32), v10)) != 0i64
        || defaultType && (v14 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)v13 + 32), defaultType)) != 0i64 )
      {
        v15 = vRay->y;
        v16 = vRay->z;
        v17 = vNormal->y;
        v18 = vNormal->x;
        v19 = LODWORD(v15) ^ _xmm[0];
        v20 = vNormal->z;
        v21 = LODWORD(v16) ^ _xmm[0];
        v22 = (float)((float)((float)(vNormal->x * COERCE_FLOAT(LODWORD(vRay->x) ^ _xmm[0]))
                            + (float)(vNormal->y * COERCE_FLOAT(LODWORD(v15) ^ _xmm[0])))
                    + (float)(vNormal->z * COERCE_FLOAT(LODWORD(v16) ^ _xmm[0])))
            * 2.0;
        v23 = vNormal->z * v22;
        v24 = vRay->x + (float)(vNormal->x * v22);
        v25 = *(float *)v14->mNULL.mChild;
        v26 = v15 + (float)(v17 * v22);
        v27 = 0.0;
        v28 = v16 + v23;
        if ( v25 < 0.0 )
        {
          v29 = LODWORD(v25) ^ _xmm[0];
          vDir.x = (float)((float)(v24 - v18) * *(float *)&v29) + v18;
          vDir.y = (float)((float)(v26 - v17) * *(float *)&v29) + v17;
          vDir.z = (float)((float)(v28 - v20) * *(float *)&v29) + v20;
        }
        else
        {
          vDir.x = (float)((float)(COERCE_FLOAT(LODWORD(vRay->x) ^ _xmm[0]) - v18) * v25) + v18;
          vDir.y = (float)((float)(*(float *)&v19 - v17) * v25) + v17;
          vDir.z = (float)((float)(*(float *)&v21 - v20) * v25) + v20;
        }
        v30 = (__m128)LODWORD(vDir.x);
        v31 = v30;
        v31.m128_f32[0] = (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(vDir.y * vDir.y))
                        + (float)(vDir.z * vDir.z);
        if ( v31.m128_f32[0] != 0.0 )
          v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v31));
        v32 = v30.m128_f32[0] * v27;
        v33 = vDir.y * v27;
        v46.x = v32;
        v46.y = vDir.y * v27;
        v34 = vDir.z * v27;
        v46.z = vDir.z * v27;
        if ( vDirectionOut )
        {
          vDirectionOut->x = v32;
          vDirectionOut->y = v33;
          vDirectionOut->z = v34;
        }
        if ( HIDWORD(v14->mNULL.mParent) != -1
          && v11->mDecalInfos.size < 0x20
          && UFG::qRandom(98, &UFG::qDefaultSeed) + 1 < SHIDWORD(v14->mNULL.mChild[0]) )
        {
          v35 = v11->mDecalInfos.size++;
          v11->mDecalInfos.p[v35].mDecalUID = HIDWORD(v14->mNULL.mParent);
          v36 = v9->y;
          v37 = v9->z;
          v11->mDecalInfos.p[v35].mPos.x = v9->x;
          v11->mDecalInfos.p[v35].mPos.y = v36;
          v11->mDecalInfos.p[v35].mPos.z = v37;
          v38 = LODWORD(vNormal->y) ^ _xmm[0];
          v39 = LODWORD(vNormal->z) ^ _xmm[0];
          LODWORD(v11->mDecalInfos.p[v35].mNormal.x) = LODWORD(vNormal->x) ^ _xmm[0];
          LODWORD(v11->mDecalInfos.p[v35].mNormal.y) = v38;
          LODWORD(v11->mDecalInfos.p[v35].mNormal.z) = v39;
        }
        v40 = (unsigned int)v14->mNULL.mParent;
        if ( v40 != -1 )
        {
          if ( fxComponent && (v41 = fxComponent->mPose) != 0i64 )
          {
            SkeletalPose::GetPositionWS(v41, boneID, &matrixWS);
            UFG::qInverseAffine(&d, &matrixWS);
            v42 = v9->y - matrixWS.v3.y;
            v43 = v9->x - matrixWS.v3.x;
            v44 = v9->z - matrixWS.v3.z;
            vPos.x = (float)((float)(d.v1.x * v42) + (float)(d.v0.x * v43)) + (float)(d.v2.x * v44);
            vPos.y = (float)((float)(d.v1.y * v42) + (float)(d.v0.y * v43)) + (float)(d.v2.y * v44);
            vPos.z = (float)((float)(d.v1.z * v42) + (float)(d.v0.z * v43)) + (float)(d.v2.z * v44);
            vDir.x = (float)((float)(d.v1.x * v46.y) + (float)(d.v0.x * v46.x)) + (float)(d.v2.x * v46.z);
            vDir.y = (float)((float)(d.v1.y * v46.y) + (float)(d.v0.y * v46.x)) + (float)(d.v2.y * v46.z);
            vDir.z = (float)((float)(d.v1.z * v46.y) + (float)(d.v0.z * v46.x)) + (float)(d.v2.z * v46.z);
            Render::CreateEffectMatrix(&matrixWS, &vPos, &vDir);
            Render::FXSimComponent::AttachEffect(fxComponent, (unsigned int)v14->mNULL.mParent, boneID, &matrixWS);
          }
          else
          {
            Render::FXManager::CreateEffect(&Render::gFXManager, v40, v9, &v46);
          }
        }
      }
    }
  }
}

// File Line: 230
// RVA: 0x61D90
void __fastcall Render::ImpactManager::HandleHitRecordImpactEvent(Render::ImpactManager *this, unsigned int impactType, unsigned int materialType, UFG::qVector3 *vRay, UFG::qVector3 *vNormal, Render::FXSimComponent *fxComponent, __int64 iBoneID, UFG::qVector3 *vBoneOffset)
{
  UFG::qVector3 *v8; // rsi
  unsigned int v9; // ebx
  UFG::qBaseTreeRB *v10; // rax
  UFG::qBaseTreeRB *v11; // rdi
  UFG::qBaseTreeRB *v12; // rbx
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm11_4
  float v16; // xmm12_4
  float v17; // xmm13_4
  int v18; // xmm8_4
  int v19; // xmm9_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  int v24; // xmm0_4
  __m128 v25; // xmm7
  __m128 v26; // xmm2
  float v27; // xmm1_4
  __m128 v28; // xmm11
  float v29; // xmm12_4
  __int128 v30; // xmm13
  __int128 v31; // xmm5
  __m128 v32; // xmm4
  float v33; // xmm7_4
  __m128 v34; // xmm2
  float v35; // xmm1_4
  float v36; // xmm4_4
  float v37; // xmm2_4
  float v38; // xmm4_4
  __m128 v39; // xmm3
  __m128 v40; // xmm5
  float v41; // xmm6_4
  float v42; // xmm1_4
  float v43; // xmm0_4
  float v44; // [rsp+30h] [rbp-C8h]
  float v45; // [rsp+34h] [rbp-C4h]
  float v46; // [rsp+38h] [rbp-C0h]
  UFG::qMatrix44 matrixWS; // [rsp+40h] [rbp-B8h]
  float v48; // [rsp+80h] [rbp-78h]
  float v49; // [rsp+88h] [rbp-70h]
  float v50; // [rsp+8Ch] [rbp-6Ch]
  float v51; // [rsp+90h] [rbp-68h]
  float v52; // [rsp+98h] [rbp-60h]
  float v53; // [rsp+9Ch] [rbp-5Ch]
  float v54; // [rsp+A0h] [rbp-58h]
  float *v55; // [rsp+178h] [rbp+80h]

  if ( impactType )
  {
    v8 = vRay;
    v9 = materialType;
    v10 = UFG::qBaseTreeRB::Get(&this->mImpactHandlers.mTree, impactType);
    v11 = v10;
    if ( v10 )
    {
      if ( v9 && (v12 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)v10 + 32), v9)) != 0i64
        || defaultType && (v12 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)((char *)v11 + 32), defaultType)) != 0i64 )
      {
        if ( LODWORD(v12->mNULL.mParent) != -1 )
        {
          v13 = v8->y;
          v14 = v8->z;
          v15 = v55[1];
          v16 = *v55;
          v17 = v55[2];
          v18 = LODWORD(v13) ^ _xmm[0];
          v19 = LODWORD(v14) ^ _xmm[0];
          v20 = (float)((float)((float)(v15 * COERCE_FLOAT(LODWORD(v13) ^ _xmm[0]))
                              + (float)(*v55 * COERCE_FLOAT(LODWORD(v8->x) ^ _xmm[0])))
                      + (float)(v17 * COERCE_FLOAT(LODWORD(v14) ^ _xmm[0])))
              * 2.0;
          v21 = *(float *)v12->mNULL.mChild;
          v22 = v13 + (float)(v15 * v20);
          v23 = v14 + (float)(v17 * v20);
          if ( v21 < 0.0 )
          {
            v24 = LODWORD(v21) ^ _xmm[0];
            v44 = (float)((float)((float)(v8->x + (float)(*v55 * v20)) - v16) * *(float *)&v24) + v16;
            v45 = (float)((float)(v22 - v15) * *(float *)&v24) + v15;
            v46 = (float)((float)(v23 - v17) * *(float *)&v24) + v17;
          }
          else
          {
            v44 = (float)((float)(COERCE_FLOAT(LODWORD(v8->x) ^ _xmm[0]) - v16) * v21) + v16;
            v45 = (float)((float)(*(float *)&v18 - v15) * v21) + v15;
            v46 = (float)((float)(*(float *)&v19 - v17) * v21) + v17;
          }
          v25 = (__m128)LODWORD(v44);
          v26 = v25;
          v26.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v45 * v45))
                          + (float)(v46 * v46);
          if ( v26.m128_f32[0] == 0.0 )
            v27 = 0.0;
          else
            v27 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v26));
          SkeletalPose::GetPositionWS(*(SkeletalPose **)&vNormal[8].x, (int)fxComponent, &matrixWS);
          UFG::qInverse((UFG::qMatrix44 *)((char *)&matrixWS + 56), &matrixWS);
          matrixWS.v0.w = 0.0;
          v28 = (__m128)LODWORD(v49);
          v30 = LODWORD(v51);
          v28.m128_f32[0] = (float)((float)(v49 * (float)(v45 * v27)) + (float)(matrixWS.v3.z * (float)(v44 * v27)))
                          + (float)(v52 * (float)(v46 * v27));
          v32 = v28;
          v29 = (float)((float)(v50 * (float)(v45 * v27)) + (float)(matrixWS.v3.w * (float)(v44 * v27)))
              + (float)(v53 * (float)(v46 * v27));
          matrixWS.v0.x = (float)((float)(v49 * (float)(v45 * v27)) + (float)(matrixWS.v3.z * (float)(v44 * v27)))
                        + (float)(v52 * (float)(v46 * v27));
          matrixWS.v0.y = v29;
          *(float *)&v30 = (float)((float)(v51 * (float)(v45 * v27)) + (float)(v48 * (float)(v44 * v27)))
                         + (float)(v54 * (float)(v46 * v27));
          matrixWS.v0.z = (float)((float)(v51 * (float)(v45 * v27)) + (float)(v48 * (float)(v44 * v27)))
                        + (float)(v54 * (float)(v46 * v27));
          v31 = v30;
          *(float *)&v31 = (float)(*(float *)&v30 * UFG::qVector3::msDirUp.y) - (float)(v29 * UFG::qVector3::msDirUp.z);
          v32.m128_f32[0] = (float)(v28.m128_f32[0] * UFG::qVector3::msDirUp.z)
                          - (float)(*(float *)&v30 * UFG::qVector3::msDirUp.x);
          v34 = v32;
          v33 = (float)(v29 * UFG::qVector3::msDirUp.x) - (float)(v28.m128_f32[0] * UFG::qVector3::msDirUp.y);
          v34.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(*(float *)&v31 * *(float *)&v31))
                          + (float)(v33 * v33);
          if ( v34.m128_f32[0] == 0.0 )
            v35 = 0.0;
          else
            v35 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v34));
          *(float *)&v31 = *(float *)&v31 * v35;
          v36 = v32.m128_f32[0] * v35;
          matrixWS.v1.w = 0.0;
          v39 = (__m128)v31;
          LODWORD(matrixWS.v1.x) = v31;
          matrixWS.v1.z = v33 * v35;
          matrixWS.v1.y = v36;
          v37 = (float)((float)(v33 * v35) * v29) - (float)(v36 * *(float *)&v30);
          v38 = (float)(v36 * v28.m128_f32[0]) - (float)(*(float *)&v31 * v29);
          v39.m128_f32[0] = (float)(*(float *)&v31 * *(float *)&v30) - (float)((float)(v33 * v35) * v28.m128_f32[0]);
          v40 = v39;
          v40.m128_f32[0] = (float)((float)(v39.m128_f32[0] * v39.m128_f32[0]) + (float)(v37 * v37))
                          + (float)(v38 * v38);
          if ( v40.m128_f32[0] == 0.0 )
            v41 = 0.0;
          else
            v41 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v40));
          matrixWS.v2.w = 0.0;
          matrixWS.v3.w = 1.0;
          matrixWS.v2.x = v37 * v41;
          matrixWS.v2.y = v39.m128_f32[0] * v41;
          v42 = *(float *)(iBoneID + 4);
          matrixWS.v3.x = *(float *)iBoneID;
          v43 = *(float *)(iBoneID + 8);
          matrixWS.v2.z = v38 * v41;
          matrixWS.v3.z = v43;
          matrixWS.v3.y = v42;
          Render::FXSimComponent::AttachEffect(
            (Render::FXSimComponent *)vNormal,
            (unsigned int)v12->mNULL.mParent,
            (int)fxComponent,
            &matrixWS);
        }
      }
    }
  }
}

// File Line: 259
// RVA: 0x619A0
void __fastcall Render::ImpactManager::ApplyDecals(Render::ImpactManager *this)
{
  signed int v1; // ebx
  Render::ImpactManager *v2; // rdi
  int v3; // ebx

  v1 = this->mDecalInfos.size;
  v2 = this;
  if ( v1 > 0 )
  {
    v3 = v1 - 1;
    Render::DecalManager::CreateDecal(
      &Render::gDecalManager,
      this->mDecalInfos.p[v3].mDecalUID,
      &this->mDecalInfos.p[v3].mPos,
      &this->mDecalInfos.p[v3].mNormal);
    v2->mDecalInfos.size = v3;
  }
}

