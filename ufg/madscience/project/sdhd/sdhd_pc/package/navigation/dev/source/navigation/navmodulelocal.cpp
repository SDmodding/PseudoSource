// File Line: 19
// RVA: 0x2627E0
void __fastcall UFG::NavModuleLocal::NavModuleLocal(UFG::NavModuleLocal *this, UFG::NavComponent *parent)
{
  UFG::NavModuleLocal *v2; // rbx
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm2_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm2_4
  float v10; // xmm0_4

  this->m_navComponent = parent;
  this->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocal::`vftable;
  this->m_adjustedWaypoint.m_navPosition.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v2 = this;
  v3 = UFG::qVector3::msZero.y;
  v4 = UFG::qVector3::msZero.z;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.x = UFG::qVector3::msZero.x;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.y = v3;
  this->m_adjustedWaypoint.m_navPosition.m_vPosition.z = v4;
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
  this->m_deferrer.mTimeSinceLastCheck = UFG::qRandom(0.40000001, &UFG::qDefaultSeed);
  v5 = UFG::qVector3::msZero.z;
  v6 = UFG::qVector3::msZero.x;
  v2->m_steerData.m_vDesiredDirection.y = UFG::qVector3::msZero.y;
  v2->m_steerData.m_vDesiredDirection.z = v5;
  v2->m_steerData.m_vDesiredDirection.x = v6;
  v7 = UFG::qVector3::msZero.z;
  v8 = UFG::qVector3::msZero.x;
  v2->m_steerData.m_vClampedDirection.y = UFG::qVector3::msZero.y;
  v2->m_steerData.m_vClampedDirection.z = v7;
  v2->m_steerData.m_vClampedDirection.x = v8;
  v9 = UFG::qVector3::msZero.z;
  v10 = UFG::qVector3::msZero.x;
  v2->m_steerData.m_vLocalDirection.y = UFG::qVector3::msZero.y;
  v2->m_steerData.m_vLocalDirection.z = v9;
  v2->m_steerData.m_vLocalDirection.x = v10;
  v2->m_steerData.m_fLocalSpeed = 0.0;
}

// File Line: 28
// RVA: 0x2666E0
void __fastcall UFG::NavModuleLocal::Update(UFG::NavModuleLocal *this, float dt)
{
  UFG::NavModuleLocal *v2; // rbx

  v2 = this;
  if ( UFG::NavModuleLocal::HasInput(this) )
    UFG::NavModuleLocal::UpdateAdjustedWaypointAndSpeed(v2, dt);
  else
    v2->m_steerData.m_fLocalSpeed = 0.0;
}

// File Line: 42
// RVA: 0x265E60
void __fastcall UFG::NavModuleLocal::Reset(UFG::NavModuleLocal *this)
{
  float v1; // xmm1_4
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm1_4
  float v8; // xmm2_4

  v1 = UFG::qVector3::msZero.y;
  v2 = UFG::qVector3::msZero.z;
  this->m_steerData.m_vDesiredDirection.x = UFG::qVector3::msZero.x;
  this->m_steerData.m_vDesiredDirection.y = v1;
  this->m_steerData.m_vDesiredDirection.z = v2;
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
void __fastcall UFG::NavModuleLocal::GetTargetPosition(UFG::NavModuleLocal *this, UFG::NavWaypoint *wp, float distanceAhead)
{
  UFG::NavModuleLocal *v3; // rsi
  float v4; // xmm0_4
  UFG::NavComponent *v5; // r8
  UFG::NavModulePathing *v6; // rax
  UFG::TransformNodeComponent *v7; // r14
  __int64 v8; // rdi
  float v9; // xmm3_4
  float v10; // xmm10_4
  float v11; // xmm15_4
  UFG::NavModulePathing *v12; // rax
  char v13; // bl
  bool v14; // r8
  __int64 v15; // r12
  char v16; // r13
  float v17; // xmm0_4
  hkVector4f v18; // xmm11
  float v19; // xmm0_4
  signed int v20; // er9
  signed int v21; // er10
  char v22; // si
  signed __int64 v23; // rcx
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
  float v45; // xmm4_4
  float v46; // xmm5_4
  float v47; // xmm6_4
  __int64 v48; // rsi
  __int64 v49; // rbx
  hkVector4f *v50; // rdi
  float v51; // xmm6_4
  float v52; // xmm10_4
  float v53; // xmm12_4
  unsigned int v54; // eax
  unsigned int v55; // edi
  char v56; // al
  float v57; // xmm5_4
  float v58; // xmm4_4
  float v59; // xmm6_4
  hkVector4f v60; // xmm0
  unsigned int v61; // eax
  char v62; // al
  float v63; // [rsp+30h] [rbp-90h]
  float v64; // [rsp+34h] [rbp-8Ch]
  float v65; // [rsp+38h] [rbp-88h]
  __m128 v66; // [rsp+40h] [rbp-80h]
  float v67; // [rsp+50h] [rbp-70h]
  signed int v68; // [rsp+54h] [rbp-6Ch]
  __int64 v69; // [rsp+60h] [rbp-60h]
  float v70; // [rsp+68h] [rbp-58h]
  float v71; // [rsp+6Ch] [rbp-54h]
  float v72; // [rsp+70h] [rbp-50h]
  int v73; // [rsp+74h] [rbp-4Ch]
  float v74; // [rsp+78h] [rbp-48h]
  float v75; // [rsp+7Ch] [rbp-44h]
  float v76; // [rsp+80h] [rbp-40h]
  UFG::HavokNavPosition v77; // [rsp+90h] [rbp-30h]
  __int64 v78; // [rsp+D0h] [rbp+10h]
  __int16 v79; // [rsp+D8h] [rbp+18h]
  char v80; // [rsp+DAh] [rbp+1Ah]
  UFG::NavPath *v81; // [rsp+E0h] [rbp+20h]
  UFG::HavokNavPosition v82; // [rsp+F0h] [rbp+30h]
  __int64 v83; // [rsp+220h] [rbp+160h]
  __int64 v84; // [rsp+228h] [rbp+168h]
  float v85; // [rsp+230h] [rbp+170h]
  float v86; // [rsp+238h] [rbp+178h]

  v3 = this;
  v4 = cosf(1.5707964);
  v5 = v3->m_navComponent;
  v6 = v5->m_pNavModulePathing;
  v7 = (UFG::TransformNodeComponent *)v5->m_pSimObject;
  v8 = 0i64;
  v63 = 0.0;
  v76 = v4;
  v81 = v6->m_pPath.m_pNavPath;
  v73 = v81->m_aWaypoints.size;
  if ( v7 )
    v7 = (UFG::TransformNodeComponent *)v7->mChildren.mNode.mNext;
  UFG::TransformNodeComponent::UpdateWorldTransform(v7);
  v9 = v7->mWorldTransform.v3.y;
  v10 = v7->mWorldTransform.v3.z;
  v11 = v7->mWorldTransform.v3.x;
  v12 = v3->m_navComponent->m_pNavModulePathing;
  v13 = 0;
  v14 = 0;
  v15 = 0i64;
  v16 = 0;
  v17 = v12->m_vHalfSpaceNormal.x;
  v86 = v7->mWorldTransform.v3.y;
  v18.m_quad = _mm_unpacklo_ps(
                 _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.x), (__m128)LODWORD(UFG::qVector3::msZero.z)),
                 _mm_unpacklo_ps((__m128)LODWORD(UFG::qVector3::msZero.y), (__m128)(unsigned int)FLOAT_1_0));
  v72 = v17;
  v19 = v12->m_vHalfSpaceNormal.y;
  v64 = v10;
  LOBYTE(v74) = 0;
  v20 = -1;
  v21 = -1;
  v66 = v18.m_quad;
  v75 = v19;
  v65 = UFG::qVector3::msZero.x;
  v70 = UFG::qVector3::msZero.x;
  v68 = -1;
  v77.m_packedKey = -1;
  v77.m_aiMeshUid = -1;
  v77.m_hkvMeshPosition = (hkVector4f)v18.m_quad;
  v67 = UFG::qVector3::msZero.y;
  v71 = UFG::qVector3::msZero.y;
  v66.m128_i32[0] = LODWORD(UFG::qVector3::msZero.z);
  v69 = 0i64;
  LOWORD(v70) = 0;
  v72 = UFG::qVector3::msZero.z;
  v77.m_vPosition = UFG::qVector3::msZero;
  BYTE2(v70) = 1;
  v77.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v77.m_bValid = 0;
  v78 = 0i64;
  v79 = 0;
  v80 = 1;
  v22 = 0;
  do
  {
    v23 = (signed __int64)&v81->m_aWaypoints.p[v8];
    v24 = (__m128)*(unsigned int *)(v23 + 12);
    v25 = *(float *)(v23 + 16);
    v26 = *(int *)(v23 + 8);
    v27 = *(float *)(v23 + 12);
    v28 = *(float *)(v23 + 16);
    v71 = *(float *)(v23 + 12);
    v72 = v28;
    v70 = *(float *)&v26;
    v29 = *(_BYTE *)(v23 + 24);
    if ( v29 )
    {
      LOBYTE(v74) = *(_BYTE *)(v23 + 24);
      v18.m_quad = *(__m128 *)(v23 + 32);
      v66 = *(__m128 *)(v23 + 32);
      v20 = *(_DWORD *)(v23 + 48);
      v67 = *(float *)(v23 + 48);
      v21 = *(_DWORD *)(v23 + 52);
      v68 = *(_DWORD *)(v23 + 52);
    }
    else
    {
      v29 = 0;
      LOBYTE(v74) = 0;
    }
    v30 = *(_QWORD *)(v23 + 64);
    v32 = v24;
    v69 = *(_QWORD *)(v23 + 64);
    v31 = *(_BYTE *)(v23 + 72);
    v74 = *(float *)&v26;
    v32.m128_f32[0] = v24.m128_f32[0] - v9;
    v33 = *(float *)&v26 - v11;
    v34 = v32;
    LOBYTE(v70) = v31;
    v35 = *(_BYTE *)(v23 + 73);
    v36 = v25 - v10;
    BYTE1(v70) = *(_BYTE *)(v23 + 73);
    v37 = *(_BYTE *)(v23 + 74);
    BYTE2(v70) = v37;
    v34.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v33 * v33)) + (float)(v36 * v36);
    LODWORD(v38) = (unsigned __int128)_mm_sqrt_ps(v34);
    v39 = v38 + v63;
    v40 = (float)(v38 + v63) < v85;
    v41 = (float)(v38 + v63) == v85;
    v63 = v38 + v63;
    if ( (float)((float)((float)((float)((float)(v24.m128_f32[0] - v9) * (float)(1.0 / v38)) * v75)
                       + (float)((float)((float)(*(float *)&v26 - v11) * (float)(1.0 / v38)) * v72))
               + (float)((float)(v36 * (float)(1.0 / v38)) * 0.0)) < v76
      && !v13 )
    {
      v15 = 0i64;
      v14 = 0;
      v13 = 1;
      v16 = 0;
      v77.m_bValid = 0;
      v65 = v11;
      v77.m_vPosition.x = v11;
      v78 = 0i64;
      v79 = 0;
      v80 = 1;
      v67 = v86;
      v77.m_vPosition.y = v86;
      v66.m128_f32[0] = v64;
      v77.m_vPosition.z = v64;
      v39 = v63;
    }
    if ( !v40 && !v41 )
    {
      v43 = v32;
      v42 = v38 - (float)(v39 - v85);
      v43.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v32.m128_f32[0]) + (float)(v33 * v33)) + (float)(v36 * v36);
      if ( v43.m128_f32[0] == 0.0 )
        v44 = 0.0;
      else
        v44 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v43));
      v30 = 0i64;
      v29 = 0;
      v37 = 1;
      v31 = 0;
      LOBYTE(v74) = 0;
      v69 = 0i64;
      v45 = (float)(v33 * v44) * v42;
      v46 = (float)(v32.m128_f32[0] * v44) * v42;
      v35 = 0;
      v22 = 1;
      *(float *)&v26 = v11 + v45;
      v27 = v86 + v46;
      v47 = (float)(v36 * v44) * v42;
      v70 = v11 + v45;
      v71 = v86 + v46;
      v28 = v64 + v47;
      v72 = v64 + v47;
    }
    v11 = v74;
    v9 = v24.m128_f32[0];
    v10 = v25;
    v8 = (unsigned int)(v8 + 1);
    v86 = v24.m128_f32[0];
    v64 = v25;
  }
  while ( !v22 && (signed int)v8 < v73 );
  v48 = v83;
  v41 = v13 == 0;
  v49 = v84;
  if ( v41 )
    goto LABEL_33;
  v50 = *(hkVector4f **)(v83 + 8);
  v82.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::NavPositionBase::`vftable;
  v51 = v50[5].m_quad.m128_f32[3];
  v52 = v50[6].m_quad.m128_f32[0];
  v53 = v50[5].m_quad.m128_f32[2];
  v82.vfptr = (UFG::NavPositionBaseVtbl *)&UFG::HavokNavPosition::`vftable;
  v82.m_vPosition.x = v53;
  v82.m_vPosition.y = v51;
  v82.m_vPosition.z = v52;
  v82.m_bValid = v50[6].m_quad.m128_i8[8];
  v82.m_hkvMeshPosition = (hkVector4f)v50[7].m_quad;
  v54 = v50[8].m_quad.m128_u32[0];
  v55 = -1;
  v40 = *(float *)(v83 + 172) < *(float *)(v83 + 164);
  v82.m_packedKey = v54;
  v56 = *(_BYTE *)(v83 + 176);
  v82.m_aiMeshUid = -1;
  if ( v40
    || (float)((float)((float)((float)(*(float *)(v83 + 156) - v51) * (float)(*(float *)(v83 + 156) - v51))
                     + (float)((float)(*(float *)(v83 + 152) - v53) * (float)(*(float *)(v83 + 152) - v53)))
             + (float)((float)(*(float *)(v83 + 160) - v52) * (float)(*(float *)(v83 + 160) - v52))) > (float)(*(float *)(v83 + 168) * *(float *)(v83 + 168)) )
  {
    UFG::HavokNavPosition::`vftable(&v77);
    UFG::HavokNavPosition::Validate(&v82, 1.0, 1.0, 0.0);
    v56 = UFG::NavManager::ms_pInstance->vfptr->AIRayCastHits(
            UFG::NavManager::ms_pInstance,
            &v82,
            (UFG::HavokNavPosition *)&v69,
            (UFG::NavParams *)(*(_QWORD *)(v48 + 8) + 188i64),
            0i64);
    v37 = BYTE2(v70);
    v35 = BYTE1(v70);
    v18.m_quad = v66;
    v28 = v72;
    v27 = v71;
    *(float *)&v26 = v70;
    v57 = v77.m_vPosition.y;
    v58 = v77.m_vPosition.x;
    v31 = LOBYTE(v70);
    v30 = v69;
    v21 = v68;
    v20 = LODWORD(v67);
    v29 = LOBYTE(v74);
    v16 = v79;
    v15 = v78;
    v14 = v77.m_bValid;
    *(_BYTE *)(v48 + 176) = v56;
    *(float *)(v48 + 156) = v51;
    v59 = v77.m_vPosition.z;
    *(float *)(v48 + 152) = v53;
    *(float *)(v48 + 160) = v52;
    *(_DWORD *)(v48 + 164) = 0;
    v55 = v77.m_packedKey;
  }
  else
  {
    v58 = v65;
    v57 = v67;
    v59 = v66.m128_f32[0];
  }
  if ( !v56 )
  {
LABEL_33:
    *(float *)(v49 + 8) = *(float *)&v26;
    *(float *)(v49 + 12) = v27;
    *(float *)(v49 + 16) = v28;
    if ( v29 )
    {
      *(_BYTE *)(v49 + 24) = v29;
      *(hkVector4f *)(v49 + 32) = (hkVector4f)v18.m_quad;
      *(_DWORD *)(v49 + 48) = v20;
      *(_DWORD *)(v49 + 52) = v21;
    }
    else
    {
      *(_BYTE *)(v49 + 24) = 0;
    }
    *(_QWORD *)(v49 + 64) = v30;
    *(_BYTE *)(v49 + 72) = v31;
    *(_BYTE *)(v49 + 73) = v35;
    *(_BYTE *)(v49 + 74) = v37;
  }
  else
  {
    *(float *)(v49 + 8) = v58;
    *(float *)(v49 + 12) = v57;
    *(float *)(v49 + 16) = v59;
    if ( v14 )
    {
      v60.m_quad = (__m128)v77.m_hkvMeshPosition;
      v61 = v77.m_aiMeshUid;
      *(_BYTE *)(v49 + 24) = v14;
      *(hkVector4f *)(v49 + 32) = (hkVector4f)v60.m_quad;
      *(_DWORD *)(v49 + 52) = v61;
      *(_DWORD *)(v49 + 48) = v55;
    }
    else
    {
      *(_BYTE *)(v49 + 24) = 0;
    }
    v62 = HIBYTE(v79);
    *(_QWORD *)(v49 + 64) = v15;
    *(_BYTE *)(v49 + 72) = v16;
    *(_BYTE *)(v49 + 73) = v62;
    *(_BYTE *)(v49 + 74) = v80;
  }
}

// File Line: 156
// RVA: 0x266A20
void __fastcall UFG::NavModuleLocal::UpdateAdjustedWaypointAndSpeed(UFG::NavModuleLocal *this, float dt)
{
  UFG::TransformNodeComponent *v2; // rbp
  UFG::NavModuleLocal *v3; // rbx
  UFG::NavPath *v4; // rax
  UFG::NavWaypoint *v5; // rcx
  hkVector4f v6; // xmm0
  float v7; // xmm1_4
  bool v8; // al
  UFG::NavComponent *v9; // rcx
  UFG::NavModulePathing *v10; // rax
  float v11; // xmm1_4
  UFG::NavObject *v12; // rsi
  UFG::NavComponent *v13; // r14
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm2_4
  __m128 v17; // xmm3
  __m128 v18; // xmm1
  float v19; // xmm1_4
  UFG::NavWaypoint *v20; // rax
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm2_4
  UFG::NavComponent *v24; // rax
  UFG::SimObject *v25; // rcx
  UFG::qVector2 *v26; // r14
  UFG::TransformNodeComponent *v27; // rdi
  float v28; // xmm1_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm1_4
  UFG::SimObject *v32; // rcx
  __m128 v33; // xmm2
  float v34; // xmm1_4
  float v35; // xmm1_4
  float v36; // xmm3_4
  UFG::qVector2 vOutRadiusCenter; // [rsp+40h] [rbp-38h]
  UFG::qVector2 vPointB; // [rsp+80h] [rbp+8h]
  float fOutRadius; // [rsp+88h] [rbp+10h]
  UFG::qVector2 vPointA; // [rsp+90h] [rbp+18h]
  UFG::qVector2 vOutRadiusTangent; // [rsp+98h] [rbp+20h]

  v2 = 0i64;
  v3 = this;
  this->m_fAdjustedSpeed = 0.0;
  this->m_deferrer.mTimeSinceLastCheck = dt + this->m_deferrer.mTimeSinceLastCheck;
  v4 = this->m_navComponent->m_pNavModulePathing->m_pPath.m_pNavPath;
  if ( !v4 || v4->m_aWaypoints.size <= 0 )
    return;
  v5 = v4->m_aWaypoints.p;
  v6.m_quad.m128_i32[0] = LODWORD(v5->m_navPosition.m_vPosition.y);
  v7 = v5->m_navPosition.m_vPosition.z;
  v3->m_adjustedWaypoint.m_navPosition.m_vPosition.x = v5->m_navPosition.m_vPosition.x;
  LODWORD(v3->m_adjustedWaypoint.m_navPosition.m_vPosition.y) = v6.m_quad.m128_i32[0];
  v3->m_adjustedWaypoint.m_navPosition.m_vPosition.z = v7;
  v8 = v5->m_navPosition.m_bValid;
  if ( v8 )
  {
    v3->m_adjustedWaypoint.m_navPosition.m_bValid = v8;
    v6.m_quad = (__m128)v5->m_navPosition.m_hkvMeshPosition;
    v3->m_adjustedWaypoint.m_navPosition.m_hkvMeshPosition = (hkVector4f)v6.m_quad;
    v3->m_adjustedWaypoint.m_navPosition.m_packedKey = v5->m_navPosition.m_packedKey;
    v3->m_adjustedWaypoint.m_navPosition.m_aiMeshUid = v5->m_navPosition.m_aiMeshUid;
  }
  else
  {
    v3->m_adjustedWaypoint.m_navPosition.m_bValid = 0;
  }
  v3->m_adjustedWaypoint.m_pNavObject = v5->m_pNavObject;
  v3->m_adjustedWaypoint.m_stopPoint = v5->m_stopPoint;
  v3->m_adjustedWaypoint.m_goalPoint = v5->m_goalPoint;
  v3->m_adjustedWaypoint.m_canSmooth = v5->m_canSmooth;
  v9 = v3->m_navComponent;
  v10 = v9->m_pNavModulePathing;
  if ( v10->m_aGoalPoints.size <= 0 || (v6.m_quad.m128_i32[0] = 0, v11 = v10->m_aGoalPoints.p->m_speed, v11 <= 0.0) )
    v11 = v9->m_fDesiredSpeed;
  v12 = v3->m_adjustedWaypoint.m_pNavObject;
  v3->m_fAdjustedSpeed = v11;
  if ( !((unsigned __int8 (__fastcall *)(UFG::NavWaypoint *))v3->m_adjustedWaypoint.m_navPosition.vfptr->IsOnMesh)(&v3->m_adjustedWaypoint) )
    goto LABEL_42;
  v13 = v3->m_navComponent;
  v13->m_navPosition.vfptr->GetMeshPosition(
    (UFG::NavPositionBase *)&v13->m_navPosition.vfptr,
    (UFG::qVector3 *)&vOutRadiusCenter);
  v17 = (__m128)LODWORD(vOutRadiusCenter.y);
  v14 = v13->m_navPosition.m_vPosition.x;
  v15 = v13->m_navPosition.m_vPosition.y;
  v16 = vOutRadiusCenter.x - v14;
  v17.m128_f32[0] = vOutRadiusCenter.y - v15;
  v6.m_quad.m128_f32[0] = v16 * v16;
  v18 = v17;
  v18.m128_f32[0] = (float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16);
  LODWORD(v19) = (unsigned __int128)_mm_sqrt_ps(v18);
  if ( v19 <= 0.050000001 )
  {
LABEL_42:
    if ( v12 )
    {
      v20 = v12->vfptr->GetAdjustedWaypoint(v12);
      UFG::NavWaypoint::operator=(&v3->m_adjustedWaypoint, v20);
      goto LABEL_24;
    }
    v21 = v3->m_fAdjustedSpeed;
    if ( v3->m_adjustedWaypoint.m_canSmooth )
    {
      v6.m_quad.m128_f32[0] = v21 * 0.5;
      v22 = FLOAT_1_5;
      if ( v6.m_quad.m128_f32[0] > 1.5 )
      {
        v23 = FLOAT_3_0;
        if ( v6.m_quad.m128_f32[0] >= 3.0 )
          goto LABEL_23;
        goto LABEL_22;
      }
    }
    else
    {
      v22 = FLOAT_0_5;
      v6.m_quad.m128_f32[0] = v21 * 0.5;
      if ( v6.m_quad.m128_f32[0] > 0.5 )
      {
        v23 = *(float *)&FLOAT_1_0;
        if ( v6.m_quad.m128_f32[0] >= 1.0 )
          goto LABEL_23;
        goto LABEL_22;
      }
    }
    v6.m_quad.m128_f32[0] = v22;
LABEL_22:
    v23 = v6.m_quad.m128_f32[0];
LABEL_23:
    UFG::NavModuleLocal::GetTargetPosition(v3, &v3->m_adjustedWaypoint, v23);
    goto LABEL_24;
  }
  v6.m_quad.m128_i32[0] = LODWORD(v13->m_navPosition.m_vPosition.z);
  LODWORD(v3->m_adjustedWaypoint.m_navPosition.m_vPosition.z) = v6.m_quad.m128_i32[0];
  v3->m_adjustedWaypoint.m_navPosition.m_vPosition.x = (float)(v16 * (float)(1.0 / v19)) + v14;
  v3->m_adjustedWaypoint.m_navPosition.m_vPosition.y = (float)(v17.m128_f32[0] * (float)(1.0 / v19)) + v15;
  v3->m_adjustedWaypoint.m_navPosition.m_bValid = 0;
LABEL_24:
  v24 = v3->m_navComponent;
  if ( v24->m_iHasSteeringControl > 0 )
  {
    v25 = v24->m_pSimObject;
    v26 = &v24->m_vForward;
    v27 = 0i64;
    if ( v25 )
      v27 = v25->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v27);
    v28 = v3->m_adjustedWaypoint.m_navPosition.m_vPosition.y;
    vPointB.x = v3->m_adjustedWaypoint.m_navPosition.m_vPosition.x;
    v29 = v27->mWorldTransform.v3.x;
    vPointB.y = v28;
    v30 = v27->mWorldTransform.v3.y;
    vPointA.x = v29;
    v6.m_quad.m128_f32[0] = FLOAT_0_15000001;
    vPointA.y = v30;
    UFG::NavModuleLocal::GetPointDirectionRadius(
      &vPointA,
      v26,
      &vPointB,
      3.4028235e38,
      &vOutRadiusCenter,
      &vOutRadiusTangent,
      &fOutRadius,
      0.15000001);
    ((void (__fastcall *)(UFG::NavModuleLocal *))v3->vfptr->GetMaxSpeedForRadius)(v3);
    v31 = v3->m_fAdjustedSpeed;
    if ( v31 >= 0.15000001 )
      v31 = FLOAT_0_15000001;
    v3->m_fAdjustedSpeed = v31;
  }
  if ( v3->m_adjustedWaypoint.m_stopPoint )
  {
    v32 = v3->m_navComponent->m_pSimObject;
    if ( v32 )
      v2 = v32->m_pTransformNodeComponent;
    UFG::TransformNodeComponent::UpdateWorldTransform(v2);
    v33 = (__m128)LODWORD(v3->m_adjustedWaypoint.m_navPosition.m_vPosition.y);
    v34 = v3->m_adjustedWaypoint.m_navPosition.m_vPosition.x - v2->mWorldTransform.v3.x;
    v6.m_quad.m128_f32[0] = (float)(v3->m_adjustedWaypoint.m_navPosition.m_vPosition.z - v2->mWorldTransform.v3.z)
                          * (float)(v3->m_adjustedWaypoint.m_navPosition.m_vPosition.z - v2->mWorldTransform.v3.z);
    v33.m128_f32[0] = (float)((float)(v33.m128_f32[0] - v2->mWorldTransform.v3.y)
                            * (float)(v33.m128_f32[0] - v2->mWorldTransform.v3.y))
                    + (float)(v34 * v34);
    v35 = *(float *)&FLOAT_1_0;
    v33.m128_f32[0] = v33.m128_f32[0] + v6.m_quad.m128_f32[0];
    LODWORD(v36) = (unsigned __int128)_mm_sqrt_ps(v33);
    if ( v36 < 1.0 || (v35 = FLOAT_2_0, v36 < 2.0) )
    {
      v6.m_quad.m128_i32[0] = LODWORD(v3->m_fAdjustedSpeed);
      if ( v6.m_quad.m128_f32[0] >= v35 )
        v6.m_quad.m128_f32[0] = v35;
      LODWORD(v3->m_fAdjustedSpeed) = v6.m_quad.m128_i32[0];
    }
  }
  if ( v12 )
  {
    v12->vfptr->GetAdjustedSpeed(v12);
    LODWORD(v3->m_fAdjustedSpeed) = v6.m_quad.m128_i32[0];
  }
}

// File Line: 260
// RVA: 0x264E80
bool __fastcall UFG::NavModuleLocal::HasInput(UFG::NavModuleLocal *this)
{
  UFG::NavComponent *v1; // rdx
  UFG::NavModulePathing *v2; // r8
  UFG::NavPath *v3; // rax
  bool v4; // cl
  float v5; // xmm0_4

  v1 = this->m_navComponent;
  v2 = v1->m_pNavModulePathing;
  v3 = v2->m_pPath.m_pNavPath;
  v4 = v3 && v3->m_aWaypoints.size;
  if ( !v2->m_aGoalPoints.size || (v5 = v2->m_aGoalPoints.p->m_speed, v5 <= 0.0) )
    v5 = v1->m_fDesiredSpeed;
  return v4 && v5 > 0.0 && v2->m_aGoalPoints.size;
}

// File Line: 270
// RVA: 0x265260
_BOOL8 __fastcall UFG::NavModuleLocal::IsAvoidanceEnabled(UFG::NavModuleLocal *this)
{
  bool v1; // bl
  bool v2; // al
  bool v3; // cl

  v1 = this->m_avoidanceType != 8;
  v2 = this->m_navComponent->m_navPosition.vfptr->IsMeshPositionValid((UFG::NavPositionBase *)&this->m_navComponent->m_navPosition);
  v3 = v1;
  if ( !v2 )
    v3 = 0;
  return v3;
}

// File Line: 294
// RVA: 0x264340
void __fastcall UFG::NavModuleLocal::GetPointDirectionRadius(UFG::qVector2 *vPointA, UFG::qVector2 *vPointADirection, UFG::qVector2 *vPointB, float fMaxRadius, UFG::qVector2 *vOutRadiusCenter, UFG::qVector2 *vOutRadiusTangent, float *fOutRadius, float fSideBuffer)
{
  UFG::qVector2 *v8; // rdi
  UFG::qVector2 *v9; // rbx
  UFG::qVector2 *v10; // rsi
  float v11; // xmm9_4
  float v12; // xmm11_4
  __m128 v13; // xmm12
  __m128 v14; // xmm2
  float v15; // xmm1_4
  float v16; // xmm11_4
  float v17; // xmm12_4
  float v18; // xmm3_4
  __m128 v19; // xmm5
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
  float v32; // xmm6_4
  float v33; // xmm7_4
  float v34; // xmm6_4
  float v35; // xmm7_4
  float v36; // xmm7_4
  float v37; // xmm0_4
  float v38; // xmm6_4
  float v39; // xmm11_4
  float v40; // xmm9_4
  float v41; // xmm2_4
  float v42; // xmm8_4
  float v43; // xmm7_4
  float v44; // xmm6_4
  float v45; // xmm4_4
  __m128 v46; // xmm5
  __m128 v47; // xmm1
  float v48; // xmm8_4
  UFG::qVector2 *v49; // rax
  float v50; // xmm0_4
  float v51; // eax
  UFG::qVector2 *v52; // rax
  float v53; // xmm12_4
  UFG::qVector2 *v54; // rcx
  UFG::qVector2 source; // [rsp+D0h] [rbp+8h]

  v8 = vPointB;
  v9 = vPointADirection;
  v10 = vPointA;
  v13 = (__m128)LODWORD(vPointADirection->x);
  v11 = fMaxRadius;
  v12 = (float)(UFG::qVector3::msDirUp.y * 0.0) - (float)(vPointADirection->y * UFG::qVector3::msDirUp.z);
  v13.m128_f32[0] = (float)(v13.m128_f32[0] * UFG::qVector3::msDirUp.z) - (float)(UFG::qVector3::msDirUp.x * 0.0);
  v14 = v13;
  v14.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v12 * v12))
                  + (float)((float)((float)(vPointADirection->y * UFG::qVector3::msDirUp.x)
                                  - (float)(vPointADirection->x * UFG::qVector3::msDirUp.y))
                          * (float)((float)(vPointADirection->y * UFG::qVector3::msDirUp.x)
                                  - (float)(vPointADirection->x * UFG::qVector3::msDirUp.y)));
  if ( v14.m128_f32[0] == 0.0 )
    v15 = 0.0;
  else
    v15 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v14));
  v19 = (__m128)LODWORD(vPointB->y);
  v16 = v12 * v15;
  v17 = v13.m128_f32[0] * v15;
  v18 = vPointB->x - vPointA->x;
  v19.m128_f32[0] = v19.m128_f32[0] - vPointA->y;
  v20 = (float)(v19.m128_f32[0] * v17) + (float)(v18 * v16);
  if ( v20 <= 0.0 )
    v21 = FLOAT_N1_0;
  else
    v21 = *(float *)&FLOAT_1_0;
  v22 = COERCE_FLOAT(LODWORD(v20) & _xmm) - fSideBuffer;
  if ( v22 < 0.0 )
    v22 = 0.0;
  v23 = v19;
  v24 = v22 * v21;
  v23.m128_f32[0] = (float)(v19.m128_f32[0] * v19.m128_f32[0]) + (float)(v18 * v18);
  LODWORD(v25) = (unsigned __int128)_mm_sqrt_ps(v23);
  if ( v24 < 0.0 )
    LODWORD(v24) ^= _xmm[0];
  if ( v24 < 0.001 || v25 == 0.0 )
  {
    *fOutRadius = v11;
    v52 = vOutRadiusCenter;
    v53 = (float)(v17 * v11) + vPointA->y;
    vOutRadiusCenter->x = (float)(v16 * v11) + vPointA->x;
    v52->y = v53;
    v50 = vPointADirection->y;
    v51 = vPointADirection->x;
    goto LABEL_37;
  }
  v26 = COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(vPointADirection->y * v19.m128_f32[0]) + (float)(vPointADirection->x
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
  if ( v11 < v29 )
    v29 = v11;
  v30 = fOutRadius;
  v31 = vOutRadiusCenter;
  *fOutRadius = v29;
  v32 = v29 * v21;
  v33 = v32;
  v34 = (float)(v32 * v17) + v10->y;
  v35 = (float)(v33 * v16) + v10->x;
  v31->y = v34;
  v31->x = v35;
  v36 = v35 - v8->x;
  v37 = v36 * v36;
  v38 = v34 - v8->y;
  if ( v11 != *v30 )
  {
    if ( (float)((float)(v38 * v38) + v37) > 0.001 )
    {
      v43 = v36 * v21;
      v44 = v38 * v21;
      v46 = (__m128)LODWORD(UFG::qVector3::msDirUp.x);
      v45 = (float)(v44 * UFG::qVector3::msDirUp.z) - (float)(UFG::qVector3::msDirUp.y * 0.0);
      v46.m128_f32[0] = (float)(UFG::qVector3::msDirUp.x * 0.0) - (float)(v43 * UFG::qVector3::msDirUp.z);
      v47 = v46;
      v47.m128_f32[0] = (float)((float)(v46.m128_f32[0] * v46.m128_f32[0]) + (float)(v45 * v45))
                      + (float)((float)((float)(v43 * UFG::qVector3::msDirUp.y) - (float)(v44 * UFG::qVector3::msDirUp.x))
                              * (float)((float)(v43 * UFG::qVector3::msDirUp.y) - (float)(v44 * UFG::qVector3::msDirUp.x)));
      if ( v47.m128_f32[0] == 0.0 )
        v48 = 0.0;
      else
        v48 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v47));
      v49 = vOutRadiusTangent;
      vOutRadiusTangent->x = v45 * v48;
      v49->y = v46.m128_f32[0] * v48;
      return;
    }
    v50 = v9->y;
    v51 = v9->x;
LABEL_37:
    v54 = vOutRadiusTangent;
    vOutRadiusTangent->y = v50;
    v54->x = v51;
    return;
  }
  v39 = (float)(v38 * v38) + v37;
  v40 = v11 / fsqrt(v39);
  if ( v40 <= -1.0 )
  {
    v40 = FLOAT_N1_0;
  }
  else if ( v40 >= 1.0 )
  {
    v40 = *(float *)&FLOAT_1_0;
  }
  v41 = asinf(v40) * v21;
  if ( v39 == 0.0 )
    v42 = 0.0;
  else
    v42 = 1.0 / fsqrt(v39);
  source.x = v36 * v42;
  source.y = v38 * v42;
  UFG::qRotateVectorZ(vOutRadiusTangent, &source, v41);
}

