// File Line: 13
// RVA: 0x1456980
__int64 dynamic_initializer_for__defaultType__()
{
  __int64 result; // rax

  result = UFG::qStringHashUpper32("Default", -1);
  defaultType = result;
  return result;
}

// File Line: 17
// RVA: 0x14569A0
__int64 Render::_dynamic_initializer_for__gImpactManager__()
{
  hkSeekableStreamReader *v0; // rbx
  int i; // edi

  UFG::qBaseTreeRB::qBaseTreeRB(&Render::gImpactManager.mImpactHandlers.mTree);
  v0 = &stru_14213866C;
  for ( i = 31; i >= 0; --i )
  {
    Assembly::GetRCX(v0);
    v0 = (hkSeekableStreamReader *)((char *)v0 + 28);
  }
  unk_142138668 = 0;
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gImpactManager__);
}

// File Line: 32
// RVA: 0x62800
void __fastcall Render::ImpactManager::Init(Render::ImpactManager *this)
{
  SimpleXML::XMLDocument *v2; // rax
  SimpleXML::XMLDocument *v3; // rbp
  SimpleXML::XMLNode *Node; // rax
  SimpleXML::XMLNode *i; // r15
  const char *Attribute; // rax
  int v7; // edi
  char *v8; // rax
  UFG::qBaseNodeRB *v9; // rbx
  SimpleXML::XMLNode *ChildNode; // rdi
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

  v2 = SimpleXML::XMLDocument::Open("Data\\Physics\\ImpactProperties.xml", 1ui64, 0i64);
  v3 = v2;
  if ( v2 )
  {
    Node = SimpleXML::XMLDocument::GetNode(v2, "ImpactPropertyList", 0i64);
    if ( Node )
    {
      for ( i = SimpleXML::XMLDocument::GetChildNode(v3, "Impact", Node);
            i;
            i = SimpleXML::XMLDocument::GetNode(v3, "Impact", i) )
      {
        Attribute = SimpleXML::XMLNode::GetAttribute(i, "type", "<unknown>");
        v7 = UFG::qStringHashUpper32(Attribute, 0xFFFFFFFF);
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
        UFG::qBaseTreeRB::Add(&this->mImpactHandlers.mTree, v9);
        ChildNode = SimpleXML::XMLDocument::GetChildNode(v3, "Material", i);
        if ( ChildNode )
        {
          v11 = (UFG::qBaseTreeRB *)&v9[1];
          do
          {
            v12 = SimpleXML::XMLNode::GetAttribute(ChildNode, "type", "<unknown>");
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
            v16 = SimpleXML::XMLNode::GetAttribute(ChildNode, "decal");
            if ( v16 )
              *((_DWORD *)v15 + 9) = UFG::qStringHashUpper32(v16, 0xFFFFFFFF);
            v17 = SimpleXML::XMLNode::GetAttribute(ChildNode, "effect");
            if ( v17 )
              *((_DWORD *)v15 + 8) = UFG::qStringHashUpper32(v17, 0xFFFFFFFF);
            v18 = SimpleXML::XMLNode::GetAttribute(ChildNode, "direction");
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
            v20 = SimpleXML::XMLNode::GetAttribute(ChildNode, "decalPercent");
            if ( v20 )
              *((_DWORD *)v15 + 11) = UFG::qToInt32(v20, 0);
            UFG::qBaseTreeRB::Add(v11, (UFG::qBaseNodeRB *)v15);
            ChildNode = SimpleXML::XMLDocument::GetNode(v3, "Material", ChildNode);
          }
          while ( ChildNode );
        }
      }
    }
    SimpleXML::XMLDocument::~XMLDocument(v3);
    operator delete[](v3);
  }
}

// File Line: 106
// RVA: 0x61D30
UFG::qBaseTreeRB *__fastcall Render::ImpactManager::GetImpactDesc(
        Render::ImpactManager *this,
        unsigned int impactType,
        unsigned int materialType)
{
  UFG::qBaseTreeRB *v4; // rax
  UFG::qBaseTreeRB *v5; // rdi
  UFG::qBaseTreeRB *result; // rax

  if ( !impactType )
    return 0i64;
  v4 = UFG::qBaseTreeRB::Get(&this->mImpactHandlers.mTree, impactType);
  v5 = v4;
  if ( !v4 )
    return 0i64;
  if ( !materialType || (result = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v4->mNULL, materialType)) == 0i64 )
  {
    if ( !defaultType )
      return 0i64;
    result = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v5->mNULL, defaultType);
    if ( !result )
      return 0i64;
  }
  return result;
}

// File Line: 134
// RVA: 0x61A00
void __fastcall Render::CreateEffectMatrix(UFG::qMatrix44 *basis, UFG::qVector3 *vPos, UFG::qVector3 *vDir)
{
  float x; // xmm5_4
  float y; // xmm6_4
  __int128 z_low; // xmm7
  __m128 v6; // xmm9
  __m128 v7; // xmm8
  __m128 y_low; // xmm2
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
  float v25; // xmm8_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  float v28; // xmm8_4
  float v29; // xmm6_4
  __m128 v30; // xmm2
  float v31; // xmm3_4
  float v32; // xmm0_4
  float z; // xmm1_4

  x = vDir->x;
  y = vDir->y;
  z_low = LODWORD(vDir->z);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT((float)((float)(y * 0.0) + (float)(vDir->x * 0.0)) + *(float *)&z_low) & _xmm) <= 0.99 )
  {
    v6 = 0i64;
    v7 = (__m128)(unsigned int)FLOAT_1_0;
  }
  else
  {
    v6 = (__m128)(unsigned int)FLOAT_1_0;
    v7 = 0i64;
  }
  y_low = (__m128)LODWORD(vDir->y);
  y_low.m128_f32[0] = (float)((float)(y * y) + (float)(x * x)) + (float)(*(float *)&z_low * *(float *)&z_low);
  if ( y_low.m128_f32[0] == 0.0 )
    v9 = 0.0;
  else
    v9 = 1.0 / _mm_sqrt_ps(y_low).m128_f32[0];
  v10 = x * v9;
  v11 = y * v9;
  *(float *)&z_low = *(float *)&z_low * v9;
  v12 = v7;
  basis->v2.w = 0.0;
  basis->v2.x = v10;
  basis->v2.y = v11;
  LODWORD(basis->v2.z) = z_low;
  v12.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v6.m128_f32[0] * v6.m128_f32[0]);
  if ( v12.m128_f32[0] == 0.0 )
    v13 = 0.0;
  else
    v13 = 1.0 / _mm_sqrt_ps(v12).m128_f32[0];
  v14 = v7.m128_f32[0] * v13;
  v6.m128_f32[0] = v6.m128_f32[0] * v13;
  v16 = v6;
  v15 = v13 * 0.0;
  v16.m128_f32[0] = (float)(v6.m128_f32[0] * *(float *)&z_low) - (float)(v14 * v11);
  v17 = v13 * 0.0;
  v20 = v16;
  v18 = (float)(v14 * v10) - (float)(v17 * *(float *)&z_low);
  v19 = (float)(v15 * v11) - (float)(v6.m128_f32[0] * v10);
  v20.m128_f32[0] = (float)((float)(v16.m128_f32[0] * v16.m128_f32[0]) + (float)(v18 * v18)) + (float)(v19 * v19);
  if ( v20.m128_f32[0] == 0.0 )
    v21 = 0.0;
  else
    v21 = 1.0 / _mm_sqrt_ps(v20).m128_f32[0];
  v22 = v16.m128_f32[0] * v21;
  v23 = v21 * v18;
  v24 = v21 * v19;
  basis->v0.w = 0.0;
  basis->v0.x = v22;
  basis->v0.y = v23;
  basis->v0.z = v24;
  v25 = basis->v2.y;
  v26 = basis->v2.x;
  v27 = v25 * v22;
  v28 = (float)(v25 * v24) - (float)(*(float *)&z_low * v23);
  *(float *)&z_low = (float)(*(float *)&z_low * v22) - (float)(v26 * v24);
  v29 = (float)(v26 * v23) - v27;
  v30 = (__m128)z_low;
  v30.m128_f32[0] = (float)((float)(*(float *)&z_low * *(float *)&z_low) + (float)(v28 * v28)) + (float)(v29 * v29);
  if ( v30.m128_f32[0] == 0.0 )
    v31 = 0.0;
  else
    v31 = 1.0 / _mm_sqrt_ps(v30).m128_f32[0];
  basis->v1.w = 0.0;
  basis->v1.z = v31 * v29;
  basis->v1.x = v31 * v28;
  basis->v1.y = v31 * *(float *)&z_low;
  v32 = vPos->y;
  z = vPos->z;
  basis->v3.x = vPos->x;
  basis->v3.w = 1.0;
  basis->v3.y = v32;
  basis->v3.z = z;
}

// File Line: 158
// RVA: 0x622A0
void __fastcall Render::ImpactManager::HandleImpactEvent(
        Render::ImpactManager *this,
        unsigned int impactType,
        unsigned int materialType,
        UFG::qVector3 *vImpact,
        UFG::qVector3 *vRay,
        UFG::qVector3 *vNormal,
        Render::FXSimComponent *fxComponent,
        int boneID,
        UFG::qVector3 *vDirectionOut)
{
  UFG::qBaseTreeRB *v12; // rax
  UFG::qBaseTreeRB *v13; // rsi
  UFG::qBaseTreeRB *v14; // rdi
  float y; // xmm5_4
  float z; // xmm6_4
  float v17; // xmm11_4
  float x; // xmm12_4
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
  __m128 x_low; // xmm2
  float v31; // xmm5_4
  float v32; // xmm6_4
  __int64 v33; // rcx
  float v34; // xmm0_4
  float v35; // xmm1_4
  int v36; // xmm1_4
  int v37; // xmm0_4
  unsigned int mParent; // edx
  SkeletalPose *mPose; // rcx
  float v40; // xmm4_4
  float v41; // xmm7_4
  float v42; // xmm5_4
  UFG::qVector3 vDir; // [rsp+30h] [rbp-D0h] BYREF
  UFG::qVector3 v44; // [rsp+40h] [rbp-C0h] BYREF
  UFG::qVector3 vPos; // [rsp+50h] [rbp-B0h] BYREF
  UFG::qMatrix44 d; // [rsp+60h] [rbp-A0h] BYREF
  UFG::qMatrix44 matrixWS; // [rsp+A0h] [rbp-60h] BYREF

  if ( impactType )
  {
    v12 = UFG::qBaseTreeRB::Get(&this->mImpactHandlers.mTree, impactType);
    v13 = v12;
    if ( v12 )
    {
      if ( materialType && (v14 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v12->mNULL, materialType)) != 0i64
        || defaultType && (v14 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v13->mNULL, defaultType)) != 0i64 )
      {
        y = vRay->y;
        z = vRay->z;
        v17 = vNormal->y;
        x = vNormal->x;
        v19 = LODWORD(y) ^ _xmm[0];
        v20 = vNormal->z;
        v21 = LODWORD(z) ^ _xmm[0];
        v22 = (float)((float)((float)(vNormal->x * COERCE_FLOAT(LODWORD(vRay->x) ^ _xmm[0]))
                            + (float)(v17 * COERCE_FLOAT(LODWORD(y) ^ _xmm[0])))
                    + (float)(v20 * COERCE_FLOAT(LODWORD(z) ^ _xmm[0])))
            * 2.0;
        v23 = v20 * v22;
        v24 = vRay->x + (float)(vNormal->x * v22);
        v25 = *(float *)v14->mNULL.mChild;
        v26 = y + (float)(v17 * v22);
        v27 = 0.0;
        v28 = z + v23;
        if ( v25 < 0.0 )
        {
          v29 = LODWORD(v25) ^ _xmm[0];
          vDir.x = (float)((float)(v24 - x) * *(float *)&v29) + x;
          vDir.y = (float)((float)(v26 - v17) * *(float *)&v29) + v17;
          vDir.z = (float)((float)(v28 - v20) * *(float *)&v29) + v20;
        }
        else
        {
          vDir.x = (float)((float)(COERCE_FLOAT(LODWORD(vRay->x) ^ _xmm[0]) - x) * v25) + x;
          vDir.y = (float)((float)(*(float *)&v19 - v17) * v25) + v17;
          vDir.z = (float)((float)(*(float *)&v21 - v20) * v25) + v20;
        }
        x_low = (__m128)LODWORD(vDir.x);
        x_low.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(vDir.y * vDir.y))
                          + (float)(vDir.z * vDir.z);
        if ( x_low.m128_f32[0] != 0.0 )
          v27 = 1.0 / _mm_sqrt_ps(x_low).m128_f32[0];
        v31 = vDir.y * v27;
        v44.x = vDir.x * v27;
        v44.y = vDir.y * v27;
        v32 = vDir.z * v27;
        v44.z = vDir.z * v27;
        if ( vDirectionOut )
        {
          vDirectionOut->x = vDir.x * v27;
          vDirectionOut->y = v31;
          vDirectionOut->z = v32;
        }
        if ( HIDWORD(v14->mNULL.mParent) != -1
          && this->mDecalInfos.size < 0x20
          && UFG::qRandom(98, &UFG::qDefaultSeed) + 1 < SHIDWORD(v14->mNULL.mChild[0]) )
        {
          v33 = this->mDecalInfos.size++;
          this->mDecalInfos.p[v33].mDecalUID = HIDWORD(v14->mNULL.mParent);
          v34 = vImpact->y;
          v35 = vImpact->z;
          this->mDecalInfos.p[v33].mPos.x = vImpact->x;
          this->mDecalInfos.p[v33].mPos.y = v34;
          this->mDecalInfos.p[v33].mPos.z = v35;
          v36 = LODWORD(vNormal->y) ^ _xmm[0];
          v37 = LODWORD(vNormal->z) ^ _xmm[0];
          LODWORD(this->mDecalInfos.p[v33].mNormal.x) = LODWORD(vNormal->x) ^ _xmm[0];
          LODWORD(this->mDecalInfos.p[v33].mNormal.y) = v36;
          LODWORD(this->mDecalInfos.p[v33].mNormal.z) = v37;
        }
        mParent = (unsigned int)v14->mNULL.mParent;
        if ( mParent != -1 )
        {
          if ( fxComponent && (mPose = fxComponent->mPose) != 0i64 )
          {
            SkeletalPose::GetPositionWS(mPose, boneID, &matrixWS);
            UFG::qInverseAffine(&d, &matrixWS);
            v40 = vImpact->y - matrixWS.v3.y;
            v41 = vImpact->x - matrixWS.v3.x;
            v42 = vImpact->z - matrixWS.v3.z;
            vPos.x = (float)((float)(d.v1.x * v40) + (float)(d.v0.x * v41)) + (float)(d.v2.x * v42);
            vPos.y = (float)((float)(d.v1.y * v40) + (float)(d.v0.y * v41)) + (float)(d.v2.y * v42);
            vPos.z = (float)((float)(d.v1.z * v40) + (float)(d.v0.z * v41)) + (float)(d.v2.z * v42);
            vDir.x = (float)((float)(d.v1.x * v44.y) + (float)(d.v0.x * v44.x)) + (float)(d.v2.x * v44.z);
            vDir.y = (float)((float)(d.v1.y * v44.y) + (float)(d.v0.y * v44.x)) + (float)(d.v2.y * v44.z);
            vDir.z = (float)((float)(d.v1.z * v44.y) + (float)(d.v0.z * v44.x)) + (float)(d.v2.z * v44.z);
            Render::CreateEffectMatrix(&matrixWS, &vPos, &vDir);
            Render::FXSimComponent::AttachEffect(fxComponent, (unsigned int)v14->mNULL.mParent, boneID, &matrixWS);
          }
          else
          {
            Render::FXManager::CreateEffect(&Render::gFXManager, mParent, vImpact, &v44);
          }
        }
      }
    }
  }
}

// File Line: 230
// RVA: 0x61D90
void __fastcall Render::ImpactManager::HandleHitRecordImpactEvent(
        Render::ImpactManager *this,
        unsigned int impactType,
        unsigned int materialType,
        UFG::qVector3 *vRay,
        UFG::qVector3 *vNormal,
        Render::FXSimComponent *fxComponent,
        float *iBoneID,
        UFG::qVector3 *vBoneOffset)
{
  UFG::qBaseTreeRB *v10; // rax
  UFG::qBaseTreeRB *v11; // rdi
  UFG::qBaseTreeRB *v12; // rbx
  float y; // xmm5_4
  float z; // xmm6_4
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
  __m128 v25; // xmm2
  float v26; // xmm1_4
  __m128 v27; // xmm11
  float v28; // xmm12_4
  __int128 v29; // xmm13
  __int128 v30; // xmm5
  __m128 v31; // xmm4
  float v32; // xmm7_4
  __m128 v33; // xmm2
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm4_4
  __m128 v37; // xmm3
  __m128 v38; // xmm5
  float v39; // xmm6_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float v42; // [rsp+30h] [rbp-C8h]
  float v43; // [rsp+34h] [rbp-C4h]
  float v44; // [rsp+38h] [rbp-C0h]
  UFG::qMatrix44 matrixWS; // [rsp+40h] [rbp-B8h] BYREF
  float v46; // [rsp+80h] [rbp-78h]
  float v47; // [rsp+88h] [rbp-70h]
  float v48; // [rsp+8Ch] [rbp-6Ch]
  float v49; // [rsp+90h] [rbp-68h]
  float v50; // [rsp+98h] [rbp-60h]
  float v51; // [rsp+9Ch] [rbp-5Ch]
  float v52; // [rsp+A0h] [rbp-58h]
  float *v53; // [rsp+178h] [rbp+80h]

  if ( impactType )
  {
    v10 = UFG::qBaseTreeRB::Get(&this->mImpactHandlers.mTree, impactType);
    v11 = v10;
    if ( v10 )
    {
      if ( (materialType && (v12 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v10->mNULL, materialType)) != 0i64
         || defaultType && (v12 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)&v11->mNULL, defaultType)) != 0i64)
        && LODWORD(v12->mNULL.mParent) != -1 )
      {
        y = vRay->y;
        z = vRay->z;
        v15 = v53[1];
        v16 = *v53;
        v17 = v53[2];
        v18 = LODWORD(y) ^ _xmm[0];
        v19 = LODWORD(z) ^ _xmm[0];
        v20 = (float)((float)((float)(v15 * COERCE_FLOAT(LODWORD(y) ^ _xmm[0]))
                            + (float)(*v53 * COERCE_FLOAT(LODWORD(vRay->x) ^ _xmm[0])))
                    + (float)(v17 * COERCE_FLOAT(LODWORD(z) ^ _xmm[0])))
            * 2.0;
        v21 = *(float *)v12->mNULL.mChild;
        v22 = y + (float)(v15 * v20);
        v23 = z + (float)(v17 * v20);
        if ( v21 < 0.0 )
        {
          v24 = LODWORD(v21) ^ _xmm[0];
          v42 = (float)((float)((float)(vRay->x + (float)(*v53 * v20)) - v16) * *(float *)&v24) + v16;
          v43 = (float)((float)(v22 - v15) * *(float *)&v24) + v15;
          v44 = (float)((float)(v23 - v17) * *(float *)&v24) + v17;
        }
        else
        {
          v42 = (float)((float)(COERCE_FLOAT(LODWORD(vRay->x) ^ _xmm[0]) - v16) * v21) + v16;
          v43 = (float)((float)(*(float *)&v18 - v15) * v21) + v15;
          v44 = (float)((float)(*(float *)&v19 - v17) * v21) + v17;
        }
        v25 = (__m128)LODWORD(v42);
        v25.m128_f32[0] = (float)((float)(v25.m128_f32[0] * v25.m128_f32[0]) + (float)(v43 * v43)) + (float)(v44 * v44);
        if ( v25.m128_f32[0] == 0.0 )
          v26 = 0.0;
        else
          v26 = 1.0 / _mm_sqrt_ps(v25).m128_f32[0];
        SkeletalPose::GetPositionWS(*(SkeletalPose **)&vNormal[8].x, (int)fxComponent, &matrixWS);
        UFG::qInverse((UFG::qMatrix44 *)&matrixWS.v3.z, &matrixWS);
        matrixWS.v0.w = 0.0;
        v27 = (__m128)LODWORD(v47);
        v29 = LODWORD(v49);
        v27.m128_f32[0] = (float)((float)(v47 * (float)(v43 * v26)) + (float)(matrixWS.v3.z * (float)(v42 * v26)))
                        + (float)(v50 * (float)(v44 * v26));
        v31 = v27;
        v28 = (float)((float)(v48 * (float)(v43 * v26)) + (float)(matrixWS.v3.w * (float)(v42 * v26)))
            + (float)(v51 * (float)(v44 * v26));
        matrixWS.v0.x = v27.m128_f32[0];
        matrixWS.v0.y = v28;
        *(float *)&v29 = (float)((float)(v49 * (float)(v43 * v26)) + (float)(v46 * (float)(v42 * v26)))
                       + (float)(v52 * (float)(v44 * v26));
        matrixWS.v0.z = *(float *)&v29;
        v30 = v29;
        *(float *)&v30 = (float)(*(float *)&v29 * UFG::qVector3::msDirUp.y) - (float)(v28 * UFG::qVector3::msDirUp.z);
        v31.m128_f32[0] = (float)(v27.m128_f32[0] * UFG::qVector3::msDirUp.z)
                        - (float)(*(float *)&v29 * UFG::qVector3::msDirUp.x);
        v33 = v31;
        v32 = (float)(v28 * UFG::qVector3::msDirUp.x) - (float)(v27.m128_f32[0] * UFG::qVector3::msDirUp.y);
        v33.m128_f32[0] = (float)((float)(v31.m128_f32[0] * v31.m128_f32[0]) + (float)(*(float *)&v30 * *(float *)&v30))
                        + (float)(v32 * v32);
        if ( v33.m128_f32[0] == 0.0 )
          v34 = 0.0;
        else
          v34 = 1.0 / _mm_sqrt_ps(v33).m128_f32[0];
        *(float *)&v30 = *(float *)&v30 * v34;
        matrixWS.v1.w = 0.0;
        v37 = (__m128)v30;
        LODWORD(matrixWS.v1.x) = v30;
        matrixWS.v1.z = v32 * v34;
        matrixWS.v1.y = v31.m128_f32[0] * v34;
        v35 = (float)((float)(v32 * v34) * v28) - (float)((float)(v31.m128_f32[0] * v34) * *(float *)&v29);
        v36 = (float)((float)(v31.m128_f32[0] * v34) * v27.m128_f32[0]) - (float)(*(float *)&v30 * v28);
        v37.m128_f32[0] = (float)(*(float *)&v30 * *(float *)&v29) - (float)((float)(v32 * v34) * v27.m128_f32[0]);
        v38 = v37;
        v38.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v37.m128_f32[0]) + (float)(v35 * v35)) + (float)(v36 * v36);
        if ( v38.m128_f32[0] == 0.0 )
          v39 = 0.0;
        else
          v39 = 1.0 / _mm_sqrt_ps(v38).m128_f32[0];
        matrixWS.v2.w = 0.0;
        matrixWS.v3.w = 1.0;
        matrixWS.v2.x = v35 * v39;
        matrixWS.v2.y = v37.m128_f32[0] * v39;
        v40 = iBoneID[1];
        matrixWS.v3.x = *iBoneID;
        v41 = iBoneID[2];
        matrixWS.v2.z = v36 * v39;
        matrixWS.v3.z = v41;
        matrixWS.v3.y = v40;
        Render::FXSimComponent::AttachEffect(
          (Render::FXSimComponent *)vNormal,
          (unsigned int)v12->mNULL.mParent,
          (int)fxComponent,
          &matrixWS);
      }
    }
  }
}

// File Line: 259
// RVA: 0x619A0
void __fastcall Render::ImpactManager::ApplyDecals(Render::ImpactManager *this)
{
  signed int size; // ebx
  unsigned int v3; // ebx

  size = this->mDecalInfos.size;
  if ( size > 0 )
  {
    v3 = size - 1;
    Render::DecalManager::CreateDecal(
      &Render::gDecalManager,
      this->mDecalInfos.p[v3].mDecalUID,
      &this->mDecalInfos.p[v3].mPos,
      &this->mDecalInfos.p[v3].mNormal);
    this->mDecalInfos.size = v3;
  }
}

