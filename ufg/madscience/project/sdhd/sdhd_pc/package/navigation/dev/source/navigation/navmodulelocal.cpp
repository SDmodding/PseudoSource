// File Line: 19
// RVA: 0x2627E0
void __fastcall UFG::NavModuleLocal::NavModuleLocal(UFG::NavModuleLocal *this, UFG::NavComponent *parent)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v5; // xmm2_4
  float x; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm0_4

  this->m_navComponent = parent;
  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocal::`vftable;
  this->m_adjustedWaypoint.m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.y = y;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.z = z;
  this->m_adjustedWaypoint.m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  this->m_adjustedWaypoint.m_navPosition.m_bValid = 0;
  *(_QWORD *)&this->m_adjustedWaypoint.m_navPosition.m_packedKey = -1i64;
  this->m_adjustedWaypoint.m_navPosition.m_hkvMeshPosition.m_quad = _mm_unpacklo_ps(
                                                                      _mm_unpacklo_ps(
                                                                        (__m128)LODWORD(UFG::qVector3::msZero.x),
                                                                        (__m128)LODWORD(UFG::qVector3::msZero.z)),
                                                                      _mm_unpacklo_ps(
                                                                        (__m128)LODWORD(UFG::qVector3::msZero.y),
                                                                        (__m128)(unsigned int)FLOAT_1_0));
  this->m_adjustedWaypoint.m_pNavObject = 0i64;
  *(_WORD *)&this->m_adjustedWaypoint.m_stopPoint = 0;
  this->m_adjustedWaypoint.m_canSmooth = 1;
  *(_QWORD *)&this->m_avoidanceType = 0i64;
  *(_QWORD *)&this->m_deferrer.mLastPosition.x = 0i64;
  *(_QWORD *)&this->m_deferrer.mLastPosition.z = 0i64;
  this->m_deferrer.mDistanceTolerance = 0.80000001;
  this->m_deferrer.mTimeTolerance = 0.40000001;
  this->m_deferrer.mResult = 0;
  this->m_deferrer.mTimeSinceLastCheck = UFG::qRandom(0.40000001, (unsigned int *)&UFG::qDefaultSeed);
  v5 = UFG::qVector3::msZero.z;
  x = UFG::qVector3::msZero.x;
  this->m_steerData.m_vDesiredDirection.y = UFG::qVector3::msZero.y;
  this->m_steerData.m_vDesiredDirection.z = v5;
  this->m_steerData.m_vDesiredDirection.x = x;
  v7 = UFG::qVector3::msZero.z;
  v8 = UFG::qVector3::msZero.x;
  this->m_steerData.m_vClampedDirection.y = UFG::qVector3::msZero.y;
  this->m_steerData.m_vClampedDirection.z = v7;
  this->m_steerData.m_vClampedDirection.x = v8;
  v9 = UFG::qVector3::msZero.z;
  v10 = UFG::qVector3::msZero.x;
  this->m_steerData.m_vLocalDirection.y = UFG::qVector3::msZero.y;
  this->m_steerData.m_vLocalDirection.z = v9;
  this->m_steerData.m_vLocalDirection.x = v10;
  this->m_steerData.m_fLocalSpeed = 0.0;
}

// File Line: 28
// RVA: 0x2666E0
void __fastcall UFG::NavModuleLocal::Update(UFG::NavModuleLocal *this, float dt)
{
  if ( UFG::NavModuleLocal::HasInput(this) )
    UFG::NavModuleLocal::UpdateAdjustedWaypointAndSpeed(this, dt);
  else
    this->m_steerData.m_fLocalSpeed = 0.0;
}

// File Line: 42
// RVA: 0x265E60
void __fastcall UFG::NavModuleLocal::Reset(UFG::NavModuleLocal *this)
{
  float y; // xmm1_4
  float z; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4

  y = UFG::qVector3::msZero.y;
  z = UFG::qVector3::msZero.z;
  this->m_steerData.m_vDesiredDirection.x = UFG::qVector3::msZero.x;
  this->m_steerData.m_vDesiredDirection.y = y;
  this->m_steerData.m_vDesiredDirection.z = z;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->m_steerData.m_vClampedDirection.x = UFG::qVector3::msZero.x;
  this->m_steerData.m_vClampedDirection.y = v3;
  this->m_steerData.m_vClampedDirection.z = v4;
  v5 = UFG::qVector3::msZero.y;
  v6 = UFG::qVector3::msZero.z;
  this->m_steerData.m_vLocalDirection.x = UFG::qVector3::msZero.x;
  this->m_steerData.m_vLocalDirection.y = v5;
  this->m_steerData.m_vLocalDirection.z = v6;
  this->m_steerData.m_fLocalSpeed = 0.0;
  v7 = UFG::qVector3::msZero.y;
  v8 = UFG::qVector3::msZero.z;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.y = v7;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.z = v8;
  this->m_adjustedWaypoint.m_navPosition.m_bValid = 0;
  this->m_fAdjustedSpeed = 0.0;
}

// File Line: 57
// RVA: 0x264770
void __fastcall UFG::NavModuleLocal::GetTargetPosition(
        UFG::NavModuleLocal *this,
        UFG::NavWaypoint *wp,
        float distanceAhead)
{
  float v4; // xmm0_4
  UFG::NavComponent *m_navComponent; // r8
  UFG::NavModulePathing *m_pNavModulePathing; // rax
  UFG::TransformNodeComponent *m_pSimObject; // r14
  __int64 v8; // rdi
  float y; // xmm3_4
  float z; // xmm10_4
  float x; // xmm15_4
  UFG::NavModulePathing *v12; // rax
  char v13; // bl
  bool m_bValid; // r8
  __int64 v15; // r12
  char v16; // r13
  float v17; // xmm0_4
  hkVector4f v18; // xmm11
  float v19; // xmm0_4
  int v20; // r9d
  int v21; // r10d
  char v22; // si
  __int64 v23; // rcx
  __m128 v24; // xmm12
  float v25; // xmm13_4
  int v26; // xmm7_4
  float v27; // xmm8_4
  float v28; // xmm9_4
  char v29; // dl
  __int64 v30; // r11
  char v31; // r14
  __m128 v32; // xmm5
  float v33; // xmm4_4
  __m128 v34; // xmm2
  char v35; // r15
  float v36; // xmm6_4
  char v37; // cl
  float v38; // xmm10_4
  float v39; // xmm0_4
  bool v40; // cf
  bool v41; // zf
  float v42; // xmm10_4
  __m128 v43; // xmm2
  float v44; // xmm1_4
  __int64 v45; // rsi
  __int64 v46; // rbx
  hkVector4f *v47; // rdi
  float v48; // xmm6_4
  float v49; // xmm10_4
  float v50; // xmm12_4
  unsigned int v51; // eax
  unsigned int m_packedKey; // edi
  char v53; // al
  float v54; // xmm5_4
  float v55; // xmm4_4
  float v56; // xmm6_4
  hkVector4f v57; // xmm0
  unsigned int m_aiMeshUid; // eax
  char v59; // al
  float v60; // [rsp+30h] [rbp-90h]
  float v61; // [rsp+34h] [rbp-8Ch]
  float v62; // [rsp+38h] [rbp-88h]
  __m128 m_quad; // [rsp+40h] [rbp-80h]
  float v64; // [rsp+50h] [rbp-70h]
  int v65; // [rsp+54h] [rbp-6Ch]
  __int64 v66; // [rsp+60h] [rbp-60h] BYREF
  int v67; // [rsp+68h] [rbp-58h]
  float v68; // [rsp+6Ch] [rbp-54h]
  float v69; // [rsp+70h] [rbp-50h]
  int size; // [rsp+74h] [rbp-4Ch]
  float v71; // [rsp+78h] [rbp-48h]
  float v72; // [rsp+7Ch] [rbp-44h]
  float v73; // [rsp+80h] [rbp-40h]
  UFG::HavokNavPosition v74; // [rsp+90h] [rbp-30h] BYREF
  __int64 v75; // [rsp+D0h] [rbp+10h]
  __int16 v76; // [rsp+D8h] [rbp+18h]
  char v77; // [rsp+DAh] [rbp+1Ah]
  UFG::NavPath *m_pNavPath; // [rsp+E0h] [rbp+20h]
  UFG::HavokNavPosition v79; // [rsp+F0h] [rbp+30h] BYREF
  __int64 v80; // [rsp+220h] [rbp+160h]
  __int64 v81; // [rsp+228h] [rbp+168h]
  float v82; // [rsp+230h] [rbp+170h]
  float v83; // [rsp+238h] [rbp+178h]

  v4 = cosf(1.5707964);
  m_navComponent = this->m_navComponent;
  m_pNavModulePathing = m_navComponent->m_pNavModulePathing;
  m_pSimObject = (UFG::TransformNodeComponent *)m_navComponent->m_pSimObject;
  v8 = 0i64;
  v60 = 0.0;
  v73 = v4;
  m_pNavPath = m_pNavModulePathing->m_pPath.m_pNavPath;
  size = m_pNavPath->m_aWaypoints.size;
  if ( m_pSimObject )
    m_pSimObject = (UFG::TransformNodeComponent *)m_pSimObject->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(m_pSimObject);
  y = m_pSimObject->mWorldTransform.v3.y;
  z = m_pSimObject->mWorldTransform.v3.z;
  x = m_pSimObject->mWorldTransform.v3.x;
  v12 = this->m_navComponent->m_pNavModulePathing;
  v13 = 0;
  m_bValid = 0;
  v15 = 0i64;
  v16 = 0;
  v17 = v12->m_vHalfSpaceNormal.x;
  v83 = y;
  v18.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.x), (__m128)LODWORD(UFG::qVector3::msZero.z)),
                 _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.y), (__m128)(unsigned int)FLOAT_1_0));
  v69 = v17;
  v19 = v12->m_vHalfSpaceNormal.y;
  v61 = z;
  LOBYTE(v71) = 0;
  v20 = -1;
  v21 = -1;
  m_quad = v18.m_quad;
  v72 = v19;
  v62 = UFG::qVector3::msZero.x;
  HIBYTE(v67) = HIBYTE(UFG::qVector3::msZero.x);
  v65 = -1;
  v74.m_packedKey = -1;
  v74.m_aiMeshUid = -1;
  v74.m_hkvMeshPosition = (hkVector4f)v18.m_quad;
  v64 = UFG::qVector3::msZero.y;
  v68 = UFG::qVector3::msZero.y;
  m_quad.m128_i32[0] = LODWORD(UFG::qVector3::msZero.z);
  v66 = 0i64;
  LOWORD(v67) = 0;
  v69 = UFG::qVector3::msZero.z;
  v74.m_vPosition = UFG::qVector3::msZero;
  BYTE2(v67) = 1;
  v74.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v74.m_bValid = 0;
  v75 = 0i64;
  v76 = 0;
  v77 = 1;
  v22 = 0;
  do
  {
    v23 = (__int64)&m_pNavPath->m_aWaypoints.p[v8];
    v24 = (__m128)*(unsigned int *)(v23 + 12);
    v25 = *(float *)(v23 + 16);
    v26 = *(int *)(v23 + 8);
    v27 = *(float *)(v23 + 12);
    v28 = v25;
    v68 = v27;
    v69 = v25;
    v67 = v26;
    v29 = *(_BYTE *)(v23 + 24);
    if ( v29 )
    {
      LOBYTE(v71) = *(_BYTE *)(v23 + 24);
      v18.m_quad = *(__m128 *)(v23 + 32);
      m_quad = v18.m_quad;
      v20 = *(_DWORD *)(v23 + 48);
      v64 = *(float *)&v20;
      v21 = *(_DWORD *)(v23 + 52);
      v65 = v21;
    }
    else
    {
      v29 = 0;
      LOBYTE(v71) = 0;
    }
    v30 = *(_QWORD *)(v23 + 64);
    v32 = v24;
    v66 = v30;
    v31 = *(_BYTE *)(v23 + 72);
    v71 = *(float *)&v26;
    v32.m128_f32[0] = v24.m128_f32[0] - y;
    v33 = *(float *)&v26 - x;
    v34 = v32;
    LOBYTE(v67) = v31;
    v35 = *(_BYTE *)(v23 + 73);
    v36 = v25 - z;
    BYTE1(v67) = v35;
    v37 = *(_BYTE *)(v23 + 74);
    BYTE2(v67) = v37;
    v34.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v33 * v33)) + (float)(v36 * v36);
    v38 = _mm_sqrt_ps(v34).m128_f32[0];
    v39 = v38 + v60;
    v40 = (float)(v38 + v60) < v82;
    v41 = (float)(v38 + v60) == v82;
    v60 = v38 + v60;
    if ( (float)((float)((float)((float)((float)(v24.m128_f32[0] - y) * (float)(1.0 / v38)) * v72)
                       + (float)((float)((float)(*(float *)&v26 - x) * (float)(1.0 / v38)) * v69))
               + (float)((float)(v36 * (float)(1.0 / v38)) * 0.0)) < v73
      && !v13 )
    {
      v15 = 0i64;
      m_bValid = 0;
      v13 = 1;
      v16 = 0;
      v74.m_bValid = 0;
      v62 = x;
      v74.m_vPosition.x = x;
      v75 = 0i64;
      v76 = 0;
      v77 = 1;
      v64 = v83;
      v74.m_vPosition.y = v83;
      m_quad.m128_f32[0] = v61;
      v74.m_vPosition.z = v61;
      v39 = v60;
    }
    if ( !v40 && !v41 )
    {
      v43 = v32;
      v42 = v38 - (float)(v39 - v82);
      v43.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v33 * v33)) + (float)(v36 * v36);
      if ( v43.m128_f32[0] == 0.0 )
        v44 = 0.0;
      else
        v44 = 1.0 / _mm_sqrt_ps(v43).m128_f32[0];
      v30 = 0i64;
      v29 = 0;
      v37 = 1;
      v31 = 0;
      LOBYTE(v71) = 0;
      v66 = 0i64;
      v35 = 0;
      v22 = 1;
      *(float *)&v26 = x + (float)((float)(v33 * v44) * v42);
      v27 = v83 + (float)((float)(v32.m128_f32[0] * v44) * v42);
      v67 = v26;
      v68 = v27;
      v28 = v61 + (float)((float)(v36 * v44) * v42);
      v69 = v28;
    }
    x = v71;
    y = v24.m128_f32[0];
    z = v25;
    v8 = (unsigned int)(v8 + 1);
    v83 = v24.m128_f32[0];
    v61 = v25;
  }
  while ( !v22 && (int)v8 < size );
  v45 = v80;
  v41 = v13 == 0;
  v46 = v81;
  if ( v41 )
    goto LABEL_27;
  v47 = *(hkVector4f **)(v80 + 8);
  v79.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v48 = v47[5].m_quad.m128_f32[3];
  v49 = v47[6].m_quad.m128_f32[0];
  v50 = v47[5].m_quad.m128_f32[2];
  v79.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v79.m_vPosition.x = v50;
  v79.m_vPosition.y = v48;
  v79.m_vPosition.z = v49;
  v79.m_bValid = v47[6].m_quad.m128_i8[8];
  v79.m_hkvMeshPosition = (hkVector4f)v47[7].m_quad;
  v51 = v47[8].m_quad.m128_u32[0];
  m_packedKey = -1;
  v40 = *(float *)(v80 + 172) < *(float *)(v80 + 164);
  v79.m_packedKey = v51;
  v53 = *(_BYTE *)(v80 + 176);
  v79.m_aiMeshUid = -1;
  if ( v40
    || (float)((float)((float)((float)(*(float *)(v80 + 156) - v48) * (float)(*(float *)(v80 + 156) - v48))
                     + (float)((float)(*(float *)(v80 + 152) - v50) * (float)(*(float *)(v80 + 152) - v50)))
             + (float)((float)(*(float *)(v80 + 160) - v49) * (float)(*(float *)(v80 + 160) - v49))) > (float)(*(float *)(v80 + 168) * *(float *)(v80 + 168)) )
  {
    UFG::HavokNavPosition::`vftable(&v74);
    UFG::HavokNavPosition::Validate(
      &v79,
      COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
      COERCE_DOUBLE((unsigned __int64)(unsigned int)FLOAT_1_0),
      0.0);
    v53 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
            UFG::NavManager::ms_pInstance,
            &v79,
            (UFG::HavokNavPosition *)&v66,
            (UFG::NavParams *)(*(_QWORD *)(v45 + 8) + 188i64),
            0i64);
    v37 = BYTE2(v67);
    v35 = BYTE1(v67);
    v18.m_quad = m_quad;
    v28 = v69;
    v27 = v68;
    v26 = v67;
    v54 = v74.m_vPosition.y;
    v55 = v74.m_vPosition.x;
    v31 = v67;
    v30 = v66;
    v21 = v65;
    v20 = LODWORD(v64);
    v29 = LOBYTE(v71);
    v16 = v76;
    v15 = v75;
    m_bValid = v74.m_bValid;
    *(_BYTE *)(v45 + 176) = v53;
    *(float *)(v45 + 156) = v48;
    v56 = v74.m_vPosition.z;
    *(float *)(v45 + 152) = v50;
    *(float *)(v45 + 160) = v49;
    *(_DWORD *)(v45 + 164) = 0;
    m_packedKey = v74.m_packedKey;
  }
  else
  {
    v55 = v62;
    v54 = v64;
    v56 = m_quad.m128_f32[0];
  }
  if ( !v53 )
  {
LABEL_27:
    *(float *)(v46 + 8) = *(float *)&v26;
    *(float *)(v46 + 12) = v27;
    *(float *)(v46 + 16) = v28;
    if ( v29 )
    {
      *(_BYTE *)(v46 + 24) = v29;
      *(hkVector4f *)(v46 + 32) = (hkVector4f)v18.m_quad;
      *(_DWORD *)(v46 + 48) = v20;
      *(_DWORD *)(v46 + 52) = v21;
    }
    else
    {
      *(_BYTE *)(v46 + 24) = 0;
    }
    *(_QWORD *)(v46 + 64) = v30;
    *(_BYTE *)(v46 + 72) = v31;
    *(_BYTE *)(v46 + 73) = v35;
    *(_BYTE *)(v46 + 74) = v37;
  }
  else
  {
    *(float *)(v46 + 8) = v55;
    *(float *)(v46 + 12) = v54;
    *(float *)(v46 + 16) = v56;
    if ( m_bValid )
    {
      v57.m_quad = (__m128)v74.m_hkvMeshPosition;
      m_aiMeshUid = v74.m_aiMeshUid;
      *(_BYTE *)(v46 + 24) = m_bValid;
      *(hkVector4f *)(v46 + 32) = (hkVector4f)v57.m_quad;
      *(_DWORD *)(v46 + 52) = m_aiMeshUid;
      *(_DWORD *)(v46 + 48) = m_packedKey;
    }
    else
    {
      *(_BYTE *)(v46 + 24) = 0;
    }
    v59 = HIBYTE(v76);
    *(_QWORD *)(v46 + 64) = v15;
    *(_BYTE *)(v46 + 72) = v16;
    *(_BYTE *)(v46 + 73) = v59;
    *(_BYTE *)(v46 + 74) = v77;
  }
}

// File Line: 156
// RVA: 0x266A20
void __fastcall UFG::NavModuleLocal::UpdateAdjustedWaypointAndSpeed(UFG::NavModuleLocal *this, float dt)
{
  UFG::TransformNodeComponent *v2; // rbp
  UFG::NavPath *m_pNavPath; // rax
  UFG::NavWaypoint *p; // rcx
  float y; // xmm0_4
  float z; // xmm1_4
  bool m_bValid; // al
  UFG::NavComponent *m_navComponent; // rcx
  UFG::NavModulePathing *m_pNavModulePathing; // rax
  float m_fDesiredSpeed; // xmm1_4
  UFG::NavObject *m_pNavObject; // rsi
  UFG::NavComponent *v13; // r14
  float x; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm2_4
  __m128 y_low; // xmm3
  __m128 v18; // xmm1
  float v19; // xmm1_4
  UFG::NavWaypoint *v20; // rax
  float m_fAdjustedSpeed; // xmm0_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  UFG::NavComponent *v25; // rax
  UFG::SimObject *m_pSimObject; // rcx
  UFG::qVector2 *p_m_vForward; // r14
  UFG::TransformNodeComponent *m_pTransformNodeComponent; // rdi
  float v29; // xmm1_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm0_4
  float v33; // xmm1_4
  UFG::SimObject *v34; // rcx
  __m128 v35; // xmm2
  float v36; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  UFG::qVector2 vOutRadiusCenter; // [rsp+40h] [rbp-38h] BYREF
  UFG::qVector2 vPointB; // [rsp+80h] [rbp+8h] BYREF
  float fOutRadius; // [rsp+88h] [rbp+10h] BYREF
  UFG::qVector2 vPointA; // [rsp+90h] [rbp+18h] BYREF
  UFG::qVector2 vOutRadiusTangent; // [rsp+98h] [rbp+20h] BYREF

  v2 = 0i64;
  this->m_fAdjustedSpeed = 0.0;
  this->m_deferrer.mTimeSinceLastCheck = dt + this->m_deferrer.mTimeSinceLastCheck;
  m_pNavPath = this->m_navComponent->m_pNavModulePathing->m_pPath.m_pNavPath;
  if ( !m_pNavPath || !m_pNavPath->m_aWaypoints.size )
    return;
  p = m_pNavPath->m_aWaypoints.p;
  y = p->m_navPosition.m_vPosition.y;
  z = p->m_navPosition.m_vPosition.z;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.x = p->m_navPosition.m_vPosition.x;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.y = y;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.z = z;
  m_bValid = p->m_navPosition.m_bValid;
  if ( m_bValid )
  {
    this->m_adjustedWaypoint.m_navPosition.m_bValid = m_bValid;
    this->m_adjustedWaypoint.m_navPosition.m_hkvMeshPosition = p->m_navPosition.m_hkvMeshPosition;
    this->m_adjustedWaypoint.m_navPosition.m_packedKey = p->m_navPosition.m_packedKey;
    this->m_adjustedWaypoint.m_navPosition.m_aiMeshUid = p->m_navPosition.m_aiMeshUid;
  }
  else
  {
    this->m_adjustedWaypoint.m_navPosition.m_bValid = 0;
  }
  this->m_adjustedWaypoint.m_pNavObject = p->m_pNavObject;
  this->m_adjustedWaypoint.m_stopPoint = p->m_stopPoint;
  this->m_adjustedWaypoint.m_goalPoint = p->m_goalPoint;
  this->m_adjustedWaypoint.m_canSmooth = p->m_canSmooth;
  m_navComponent = this->m_navComponent;
  m_pNavModulePathing = m_navComponent->m_pNavModulePathing;
  if ( !m_pNavModulePathing->m_aGoalPoints.size
    || (m_fDesiredSpeed = m_pNavModulePathing->m_aGoalPoints.p->m_speed, m_fDesiredSpeed <= 0.0) )
  {
    m_fDesiredSpeed = m_navComponent->m_fDesiredSpeed;
  }
  m_pNavObject = this->m_adjustedWaypoint.m_pNavObject;
  this->m_fAdjustedSpeed = m_fDesiredSpeed;
  if ( !((unsigned __int8 (__fastcall *)(UFG::NavWaypoint *))this->m_adjustedWaypoint.m_navPosition.vfptr->IsOnMesh)(&this->m_adjustedWaypoint) )
    goto LABEL_12;
  v13 = this->m_navComponent;
  v13->m_navPosition.vfptr->GetMeshPosition(&v13->m_navPosition, (UFG::qVector3 *)&vOutRadiusCenter);
  y_low = (__m128)LODWORD(vOutRadiusCenter.y);
  x = v13->m_navPosition.m_vPosition.x;
  v15 = v13->m_navPosition.m_vPosition.y;
  v16 = vOutRadiusCenter.x - x;
  y_low.m128_f32[0] = vOutRadiusCenter.y - v15;
  v18 = y_low;
  v18.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v16 * v16);
  v19 = _mm_sqrt_ps(v18).m128_f32[0];
  if ( v19 <= 0.050000001 )
  {
LABEL_12:
    if ( m_pNavObject )
    {
      v20 = m_pNavObject->vfptr->GetAdjustedWaypoint(m_pNavObject);
      UFG::NavWaypoint::operator=(&this->m_adjustedWaypoint, v20);
      goto LABEL_24;
    }
    m_fAdjustedSpeed = this->m_fAdjustedSpeed;
    if ( this->m_adjustedWaypoint.m_canSmooth )
    {
      v22 = m_fAdjustedSpeed * 0.5;
      v23 = FLOAT_1_5;
      if ( v22 > 1.5 )
      {
        v24 = FLOAT_3_0;
        if ( v22 >= 3.0 )
          goto LABEL_23;
        goto LABEL_22;
      }
    }
    else
    {
      v23 = FLOAT_0_5;
      v22 = m_fAdjustedSpeed * 0.5;
      if ( v22 > 0.5 )
      {
        v24 = *(float *)&FLOAT_1_0;
        if ( v22 >= 1.0 )
          goto LABEL_23;
        goto LABEL_22;
      }
    }
    v22 = v23;
LABEL_22:
    v24 = v22;
LABEL_23:
    UFG::NavModuleLocal::GetTargetPosition(this, &this->m_adjustedWaypoint, v24);
    goto LABEL_24;
  }
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.z = v13->m_navPosition.m_vPosition.z;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.x = (float)(v16 * (float)(1.0 / v19)) + x;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.y = (float)(y_low.m128_f32[0] * (float)(1.0 / v19)) + v15;
  this->m_adjustedWaypoint.m_navPosition.m_bValid = 0;
LABEL_24:
  v25 = this->m_navComponent;
  if ( v25->m_iHasSteeringControl > 0 )
  {
    m_pSimObject = v25->m_pSimObject;
    p_m_vForward = &v25->m_vForward;
    m_pTransformNodeComponent = 0i64;
    if ( m_pSimObject )
      m_pTransformNodeComponent = m_pSimObject->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(m_pTransformNodeComponent);
    v29 = this->m_adjustedWaypoint.m_navPosition.m_vPosition.y;
    vPointB.x = this->m_adjustedWaypoint.m_navPosition.m_vPosition.x;
    v30 = m_pTransformNodeComponent->mWorldTransform.v3.x;
    vPointB.y = v29;
    v31 = m_pTransformNodeComponent->mWorldTransform.v3.y;
    vPointA.x = v30;
    vPointA.y = v31;
    UFG::NavModuleLocal::GetPointDirectionRadius(
      &vPointA,
      p_m_vForward,
      &vPointB,
      3.4028235e38,
      &vOutRadiusCenter,
      &vOutRadiusTangent,
      &fOutRadius,
      0.15000001);
    v32 = ((float (__fastcall *)(UFG::NavModuleLocal *))this->vfptr->GetMaxSpeedForRadius)(this);
    v33 = this->m_fAdjustedSpeed;
    if ( v33 >= v32 )
      v33 = v32;
    this->m_fAdjustedSpeed = v33;
  }
  if ( this->m_adjustedWaypoint.m_stopPoint )
  {
    v34 = this->m_navComponent->m_pSimObject;
    if ( v34 )
      v2 = v34->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v35 = (__m128)LODWORD(this->m_adjustedWaypoint.m_navPosition.m_vPosition.y);
    v36 = this->m_adjustedWaypoint.m_navPosition.m_vPosition.x - v2->mWorldTransform.v3.x;
    v35.m128_f32[0] = (float)((float)(v35.m128_f32[0] - v2->mWorldTransform.v3.y)
                            * (float)(v35.m128_f32[0] - v2->mWorldTransform.v3.y))
                    + (float)(v36 * v36);
    v37 = *(float *)&FLOAT_1_0;
    v35.m128_f32[0] = v35.m128_f32[0]
                    + (float)((float)(this->m_adjustedWaypoint.m_navPosition.m_vPosition.z - v2->mWorldTransform.v3.z)
                            * (float)(this->m_adjustedWaypoint.m_navPosition.m_vPosition.z - v2->mWorldTransform.v3.z));
    v38 = _mm_sqrt_ps(v35).m128_f32[0];
    if ( v38 < 1.0 || (v37 = FLOAT_2_0, v38 < 2.0) )
    {
      v39 = this->m_fAdjustedSpeed;
      if ( v39 >= v37 )
        v39 = v37;
      this->m_fAdjustedSpeed = v39;
    }
  }
  if ( m_pNavObject )
    this->m_fAdjustedSpeed = m_pNavObject->vfptr->GetAdjustedSpeed(m_pNavObject);
}

// File Line: 260
// RVA: 0x264E80
bool __fastcall UFG::NavModuleLocal::HasInput(UFG::NavModuleLocal *this)
{
  UFG::NavComponent *m_navComponent; // rdx
  UFG::NavModulePathing *m_pNavModulePathing; // r8
  UFG::NavPath *m_pNavPath; // rax
  bool v4; // cl
  float m_fDesiredSpeed; // xmm0_4

  m_navComponent = this->m_navComponent;
  m_pNavModulePathing = m_navComponent->m_pNavModulePathing;
  m_pNavPath = m_pNavModulePathing->m_pPath.m_pNavPath;
  v4 = m_pNavPath && m_pNavPath->m_aWaypoints.size;
  if ( !m_pNavModulePathing->m_aGoalPoints.size
    || (m_fDesiredSpeed = m_pNavModulePathing->m_aGoalPoints.p->m_speed, m_fDesiredSpeed <= 0.0) )
  {
    m_fDesiredSpeed = m_navComponent->m_fDesiredSpeed;
  }
  return v4 && m_fDesiredSpeed > 0.0 && m_pNavModulePathing->m_aGoalPoints.size;
}

// File Line: 270
// RVA: 0x265260
_BOOL8 __fastcall UFG::NavModuleLocal::IsAvoidanceEnabled(UFG::NavModuleLocal *this)
{
  bool v1; // bl
  bool v2; // al
  bool v3; // cl

  v1 = this->m_avoidanceType != eCOLLISION_AVOIDANCE_NO_ONE;
  v2 = this->m_navComponent->m_navPosition.vfptr->IsMeshPositionValid(&this->m_navComponent->m_navPosition);
  v3 = v1;
  if ( !v2 )
    return 0;
  return v3;
}

// File Line: 294
// RVA: 0x264340
void __fastcall UFG::NavModuleLocal::GetPointDirectionRadius(
        UFG::qVector2 *vPointA,
        UFG::qVector2 *vPointADirection,
        UFG::qVector2 *vPointB,
        float fMaxRadius,
        UFG::qVector2 *vOutRadiusCenter,
        UFG::qVector2 *vOutRadiusTangent,
        float *fOutRadius,
        float fSideBuffer)
{
  float v12; // xmm11_4
  __m128 x_low; // xmm12
  __m128 v14; // xmm2
  float v15; // xmm1_4
  float v16; // xmm11_4
  float v17; // xmm12_4
  float v18; // xmm3_4
  __m128 y_low; // xmm5
  float v20; // xmm2_4
  float v21; // xmm14_4
  float v22; // xmm2_4
  __m128 v23; // xmm1
  float v24; // xmm2_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm6_4
  float *v30; // rcx
  UFG::qVector2 *v31; // rax
  float v32; // xmm7_4
  float v33; // xmm6_4
  float v34; // xmm7_4
  float v35; // xmm7_4
  float v36; // xmm0_4
  float v37; // xmm6_4
  float v38; // xmm11_4
  float v39; // xmm9_4
  float v40; // xmm2_4
  float v41; // xmm8_4
  float v42; // xmm7_4
  float v43; // xmm6_4
  float v44; // xmm4_4
  __m128 v45; // xmm5
  __m128 v46; // xmm1
  float v47; // xmm8_4
  UFG::qVector2 *v48; // rax
  float y; // xmm0_4
  float x; // eax
  UFG::qVector2 *v51; // rax
  float v52; // xmm12_4
  UFG::qVector2 *v53; // rcx
  UFG::qVector2 source; // [rsp+D0h] [rbp+8h] BYREF

  x_low = (__m128)LODWORD(vPointADirection->x);
  v12 = (float)(UFG::qVector3::msDirUp.y * 0.0) - (float)(vPointADirection->y * UFG::qVector3::msDirUp.z);
  x_low.m128_f32[0] = (float)(x_low.m128_f32[0] * UFG::qVector3::msDirUp.z) - (float)(UFG::qVector3::msDirUp.x * 0.0);
  v14 = x_low;
  v14.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v12 * v12))
                  + (float)((float)((float)(vPointADirection->y * UFG::qVector3::msDirUp.x)
                                  - (float)(vPointADirection->x * UFG::qVector3::msDirUp.y))
                          * (float)((float)(vPointADirection->y * UFG::qVector3::msDirUp.x)
                                  - (float)(vPointADirection->x * UFG::qVector3::msDirUp.y)));
  if ( v14.m128_f32[0] == 0.0 )
    v15 = 0.0;
  else
    v15 = 1.0 / _mm_sqrt_ps(v14).m128_f32[0];
  y_low = (__m128)LODWORD(vPointB->y);
  v16 = v12 * v15;
  v17 = x_low.m128_f32[0] * v15;
  v18 = vPointB->x - vPointA->x;
  y_low.m128_f32[0] = y_low.m128_f32[0] - vPointA->y;
  v20 = (float)(y_low.m128_f32[0] * v17) + (float)(v18 * v16);
  if ( v20 <= 0.0 )
    v21 = FLOAT_N1_0;
  else
    v21 = *(float *)&FLOAT_1_0;
  v22 = COERCE_FLOAT(LODWORD(v20) & _xmm) - fSideBuffer;
  if ( v22 < 0.0 )
    v22 = 0.0;
  v23 = y_low;
  v24 = v22 * v21;
  v23.m128_f32[0] = (float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v18 * v18);
  LODWORD(v25) = _mm_sqrt_ps(v23).m128_u32[0];
  if ( v24 < 0.0 )
    LODWORD(v24) ^= _xmm[0];
  if ( v24 < 0.001 || v25 == 0.0 )
  {
    *fOutRadius = fMaxRadius;
    v51 = vOutRadiusCenter;
    v52 = (float)(v17 * fMaxRadius) + vPointA->y;
    vOutRadiusCenter->x = (float)(v16 * fMaxRadius) + vPointA->x;
    v51->y = v52;
    y = vPointADirection->y;
    x = vPointADirection->x;
    goto LABEL_37;
  }
  v26 = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(vPointADirection->y * y_low.m128_f32[0]) + (float)(vPointADirection->x
                                                                                                  * v18)) & _xmm)
      / v25;
  if ( v26 <= -1.0 )
  {
    v26 = FLOAT_N1_0;
  }
  else if ( v26 >= 1.0 )
  {
    v26 = *(float *)&FLOAT_1_0;
  }
  v27 = asinf(v26);
  v28 = cosf(v27);
  if ( v28 <= 0.0 )
    v28 = 0.0;
  v29 = (float)(v25 * 0.5) / v28;
  if ( fMaxRadius < v29 )
    v29 = fMaxRadius;
  v30 = fOutRadius;
  v31 = vOutRadiusCenter;
  *fOutRadius = v29;
  v32 = v29 * v21;
  v33 = (float)((float)(v29 * v21) * v17) + vPointA->y;
  v34 = (float)(v32 * v16) + vPointA->x;
  v31->y = v33;
  v31->x = v34;
  v35 = v34 - vPointB->x;
  v36 = v35 * v35;
  v37 = v33 - vPointB->y;
  if ( fMaxRadius != *v30 )
  {
    if ( (float)((float)(v37 * v37) + v36) > 0.001 )
    {
      v42 = v35 * v21;
      v43 = v37 * v21;
      v45 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
      v44 = (float)(v43 * UFG::qVector3::msDirUp.z) - (float)(UFG::qVector3::msDirUp.y * 0.0);
      v45.m128_f32[0] = (float)(UFG::qVector3::msDirUp.x * 0.0) - (float)(v42 * UFG::qVector3::msDirUp.z);
      v46 = v45;
      v46.m128_f32[0] = (float)((float)(v45.m128_f32[0] * v45.m128_f32[0]) + (float)(v44 * v44))
                      + (float)((float)((float)(v42 * UFG::qVector3::msDirUp.y) - (float)(v43 * UFG::qVector3::msDirUp.x))
                              * (float)((float)(v42 * UFG::qVector3::msDirUp.y) - (float)(v43 * UFG::qVector3::msDirUp.x)));
      if ( v46.m128_f32[0] == 0.0 )
        v47 = 0.0;
      else
        v47 = 1.0 / _mm_sqrt_ps(v46).m128_f32[0];
      v48 = vOutRadiusTangent;
      vOutRadiusTangent->x = v44 * v47;
      v48->y = v45.m128_f32[0] * v47;
      return;
    }
    y = vPointADirection->y;
    x = vPointADirection->x;
LABEL_37:
    v53 = vOutRadiusTangent;
    vOutRadiusTangent->y = y;
    v53->x = x;
    return;
  }
  v38 = (float)(v37 * v37) + v36;
  v39 = fMaxRadius / fsqrt(v38);
  if ( v39 <= -1.0 )
  {
    v39 = FLOAT_N1_0;
  }
  else if ( v39 >= 1.0 )
  {
    v39 = *(float *)&FLOAT_1_0;
  }
  v40 = asinf(v39) * v21;
  if ( v38 == 0.0 )
    v41 = 0.0;
  else
    v41 = 1.0 / fsqrt(v38);
  source.x = v35 * v41;
  source.y = v37 * v41;
  UFG::qRotateVectorZ(vOutRadiusTangent, &source, v40);
}

