// File Line: 32
// RVA: 0x14AD3F0
__int64 dynamic_initializer_for__UFG::CoverObjectBase::ms_listUsers__()
{
  return atexit(dynamic_atexit_destructor_for__UFG::CoverObjectBase::ms_listUsers__);
}

// File Line: 50
// RVA: 0x335DC0
void __fastcall UFG::CoverObjectBase::~CoverObjectBase(UFG::CoverObjectBase *this)
{
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable;
}

// File Line: 64
// RVA: 0x36A080
char __fastcall UFG::CoverObjectBase::IsConnected(UFG::CoverObjectParkour *coParkourA, UFG::CoverObjectParkour *coParkourB)
{
  UFG::ParkourHandle *v2; // rsi
  UFG::ParkourHandle *v3; // rdi
  UFG::CoverObjectParkour *v4; // rbx
  float v5; // xmm2_4
  float v6; // xmm0_4
  signed __int64 v7; // r8
  UFG::qVector3 *v8; // rdx
  signed __int64 v9; // rax
  UFG::qVector3 *v10; // rcx
  UFG::qVector3 out; // [rsp+20h] [rbp-A8h]
  UFG::qVector3 v13; // [rsp+30h] [rbp-98h]
  char v14; // [rsp+40h] [rbp-88h]
  float v15; // [rsp+48h] [rbp-80h]
  char v16; // [rsp+50h] [rbp-78h]
  float v17; // [rsp+58h] [rbp-70h]
  UFG::qVector3 p0; // [rsp+60h] [rbp-68h]
  UFG::qVector3 p1; // [rsp+6Ch] [rbp-5Ch]
  UFG::qVector3 v20; // [rsp+78h] [rbp-50h]
  UFG::qVector3 v21; // [rsp+84h] [rbp-44h]

  v2 = coParkourB->m_pParkourHandle.m_pPointer;
  v3 = coParkourA->m_pParkourHandle.m_pPointer;
  v4 = coParkourB;
  coParkourA->vfptr->GetSyncPos((UFG::CoverObjectBase *)coParkourA, (UFG::qVector3 *)&v14);
  v4->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v4->vfptr, (UFG::qVector3 *)&v16);
  UFG::ParkourHandle::GetNormal(v3, &out);
  UFG::ParkourHandle::GetNormal(v2, &v13);
  v5 = (float)((float)(out.x * v13.x) + (float)(v13.y * out.y)) + (float)(out.z * v13.z);
  if ( v5 <= -1.0 )
  {
    v5 = FLOAT_N1_0;
    goto LABEL_5;
  }
  v6 = *(float *)&FLOAT_1_0;
  if ( v5 < 1.0 )
LABEL_5:
    v6 = v5;
  if ( acosf(v6) < fCompareAngle )
  {
    UFG::ParkourHandle::GetEndpoints(v3, &p0, &p1);
    UFG::ParkourHandle::GetEndpoints(v2, &v20, &v21);
    v7 = 0i64;
    v8 = &p0;
    while ( 2 )
    {
      v9 = 0i64;
      v10 = &v20;
      do
      {
        if ( (float)((float)((float)(v8->x - v10->x) * (float)(v8->x - v10->x))
                   + (float)((float)(v8->y - v10->y) * (float)(v8->y - v10->y))) < fCompareDistSqr2D
          && COERCE_FLOAT(COERCE_UNSIGNED_INT(v15 - v17) & _xmm) < fCompareHeight )
        {
          return 1;
        }
        ++v9;
        ++v10;
      }
      while ( v9 < 2 );
      ++v7;
      ++v8;
      if ( v7 < 2 )
        continue;
      break;
    }
  }
  return 0;
}

// File Line: 112
// RVA: 0x36A240
char __fastcall UFG::CoverObjectBase::IsConnected(UFG::CoverObjectParkour *coParkour, UFG::CoverObjectCorner *coCorner)
{
  UFG::ParkourHandle *v2; // rsi
  UFG::CoverObjectParkour *v3; // rbx
  float *v4; // rdi
  float v5; // xmm2_4
  float v6; // xmm0_4
  signed __int64 v7; // rcx
  UFG::qVector3 *v8; // rax
  UFG::qVector3 out; // [rsp+20h] [rbp-68h]
  char v11; // [rsp+30h] [rbp-58h]
  float v12; // [rsp+38h] [rbp-50h]
  UFG::qVector3 p0; // [rsp+40h] [rbp-48h]
  UFG::qVector3 p1; // [rsp+4Ch] [rbp-3Ch]

  v2 = coParkour->m_pParkourHandle.m_pPointer;
  v3 = coParkour;
  v4 = (float *)UFG::CoverCornerHandle::Get(&coCorner->m_CornerHandle);
  v3->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v3->vfptr, (UFG::qVector3 *)&v11);
  UFG::ParkourHandle::GetNormal(v2, &out);
  v5 = (float)((float)(out.y * v4[8]) + (float)(out.x * v4[7])) + (float)(out.z * 0.0);
  if ( v5 <= -1.0 )
  {
    v5 = FLOAT_N1_0;
    goto LABEL_5;
  }
  v6 = *(float *)&FLOAT_1_0;
  if ( v5 < 1.0 )
LABEL_5:
    v6 = v5;
  if ( acosf(v6) >= fCompareAngle_0 )
    return 0;
  UFG::ParkourHandle::GetEndpoints(v2, &p0, &p1);
  v7 = 0i64;
  v8 = &p0;
  while ( (float)((float)((float)(v8->y - v4[5]) * (float)(v8->y - v4[5]))
                + (float)((float)(v8->x - v4[4]) * (float)(v8->x - v4[4]))) >= fCompareDistSqr2D_0
       || COERCE_FLOAT(COERCE_UNSIGNED_INT(v12 - v4[6]) & _xmm) >= fCompareHeight_0 )
  {
    ++v7;
    ++v8;
    if ( v7 >= 2 )
      return 0;
  }
  return 1;
}

// File Line: 156
// RVA: 0x369F90
bool __fastcall UFG::CoverObjectBase::IsConnected(UFG::CoverObjectCorner *coCornerA, UFG::CoverObjectCorner *coCornerB)
{
  UFG::CoverObjectCorner *v2; // rbx
  UFG::CoverCorner *v3; // rdi
  UFG::CoverCorner *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool v7; // al
  UFG::qVector3 result; // [rsp+20h] [rbp-28h]
  UFG::qVector3 v9; // [rsp+30h] [rbp-18h]

  v2 = coCornerB;
  v3 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(&coCornerA->m_CornerHandle);
  v4 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(&v2->m_CornerHandle);
  v5 = (float)(v4->m_vWallNormal.y * v3->m_vWallNormal.y) + (float)(v4->m_vWallNormal.x * v3->m_vWallNormal.x);
  if ( v5 <= -1.0 )
  {
    v5 = FLOAT_N1_0;
  }
  else
  {
    v6 = *(float *)&FLOAT_1_0;
    if ( v5 >= 1.0 )
      goto LABEL_6;
  }
  v6 = v5;
LABEL_6:
  v7 = 0;
  if ( acosf(v6) < fCompareAngle_1 )
  {
    UFG::CoverCorner::GetSyncPos(v3, &result);
    UFG::CoverCorner::GetSyncPos(v4, &v9);
    if ( (float)((float)((float)(result.y - v9.y) * (float)(result.y - v9.y))
               + (float)((float)(result.x - v9.x) * (float)(result.x - v9.x))) < fCompareDistSqr2D_1
      && COERCE_FLOAT(COERCE_UNSIGNED_INT(result.z - v9.z) & _xmm) < fCompareHeight_1 )
    {
      v7 = 1;
    }
  }
  return v7;
}

// File Line: 191
// RVA: 0x36B600
bool __fastcall UFG::CoverObjectBase::IsLeft(UFG::CoverObjectParkour *coParkourA, UFG::CoverObjectParkour *coParkourB)
{
  UFG::ParkourHandle *v2; // rbx
  UFG::ParkourHandle *v3; // rdi
  float v4; // xmm8_4
  float v5; // xmm7_4
  float v6; // xmm6_4
  UFG::qVector3 *v7; // rbx
  UFG::qVector3 *v8; // rax
  UFG::qVector3 out; // [rsp+20h] [rbp-68h]
  UFG::qVector3 result; // [rsp+30h] [rbp-58h]
  UFG::qVector3 v12; // [rsp+3Ch] [rbp-4Ch]

  v2 = coParkourA->m_pParkourHandle.m_pPointer;
  v3 = coParkourB->m_pParkourHandle.m_pPointer;
  UFG::ParkourHandle::GetNormal(coParkourA->m_pParkourHandle.m_pPointer, &out);
  v4 = (float)(UFG::qVector3::msAxisZ.y * out.z) - (float)(UFG::qVector3::msAxisZ.z * out.y);
  v5 = (float)(UFG::qVector3::msAxisZ.z * out.x) - (float)(UFG::qVector3::msAxisZ.x * out.z);
  v6 = (float)(UFG::qVector3::msAxisZ.x * out.y) - (float)(UFG::qVector3::msAxisZ.y * out.x);
  v7 = UFG::ParkourHandle::GetPosition(v2, &result);
  v8 = UFG::ParkourHandle::GetPosition(v3, &v12);
  return (float)((float)((float)((float)(v8->y - v7->y) * v5) + (float)((float)(v8->x - v7->x) * v4))
               + (float)((float)(v8->z - v7->z) * v6)) > 0.0;
}

// File Line: 214
// RVA: 0x36B700
bool __fastcall UFG::CoverObjectBase::IsLeft(UFG::CoverObjectParkour *coParkour, UFG::CoverObjectCorner *coCorner)
{
  UFG::ParkourHandle *v2; // rbx
  float *v3; // rdi
  float v4; // xmm8_4
  float v5; // xmm7_4
  float v6; // xmm6_4
  UFG::qVector3 *v7; // rax
  UFG::qVector3 out; // [rsp+20h] [rbp-58h]
  UFG::qVector3 result; // [rsp+30h] [rbp-48h]

  v2 = coParkour->m_pParkourHandle.m_pPointer;
  v3 = (float *)UFG::CoverCornerHandle::Get(&coCorner->m_CornerHandle);
  UFG::ParkourHandle::GetNormal(v2, &out);
  v4 = (float)(UFG::qVector3::msAxisZ.y * out.z) - (float)(UFG::qVector3::msAxisZ.z * out.y);
  v5 = (float)(UFG::qVector3::msAxisZ.z * out.x) - (float)(UFG::qVector3::msAxisZ.x * out.z);
  v6 = (float)(UFG::qVector3::msAxisZ.x * out.y) - (float)(UFG::qVector3::msAxisZ.y * out.x);
  v7 = UFG::ParkourHandle::GetPosition(v2, &result);
  return (float)((float)((float)((float)(v3[5] - v7->y) * v5) + (float)((float)(v3[4] - v7->x) * v4))
               + (float)((float)(v3[6] - v7->z) * v6)) > 0.0;
}

// File Line: 237
// RVA: 0x36B530
bool __fastcall UFG::CoverObjectBase::IsLeft(UFG::CoverObjectCorner *coCornerA, UFG::CoverObjectCorner *coCornerB)
{
  UFG::CoverObjectCorner *v2; // rbx
  float *v3; // rdi
  float *v4; // rax

  v2 = coCornerB;
  v3 = (float *)UFG::CoverCornerHandle::Get(&coCornerA->m_CornerHandle);
  v4 = (float *)UFG::CoverCornerHandle::Get(&v2->m_CornerHandle);
  return (float)((float)((float)((float)(v4[5] - v3[5])
                               * (float)((float)(UFG::qVector3::msAxisZ.z * v3[7])
                                       - (float)(UFG::qVector3::msAxisZ.x * 0.0)))
                       + (float)((float)(v4[4] - v3[4])
                               * (float)((float)(UFG::qVector3::msAxisZ.y * 0.0)
                                       - (float)(UFG::qVector3::msAxisZ.z * v3[8]))))
               + (float)((float)(v4[6] - v3[6])
                       * (float)((float)(UFG::qVector3::msAxisZ.x * v3[8]) - (float)(UFG::qVector3::msAxisZ.y * v3[7])))) > 0.0;
}

// File Line: 258
// RVA: 0x369960
char __fastcall UFG::CoverObjectBase::IsAnyLineOrCornerShared(UFG::CoverObjectBase *pObject1, UFG::CoverObjectBase *pObject2)
{
  UFG::CoverObjectBase *v2; // rsi
  UFG::CoverObjectBase *v3; // rbx
  UFG::CoverObjectBase *v4; // rax
  __int64 v5; // rdi
  char result; // al
  UFG::CoverObjectBaseVtbl *v7; // rax
  UFG::CoverObjectBase *v8; // rdx
  UFG::CoverObjectBase *v9; // rcx

  v2 = pObject2;
  v3 = pObject1;
  if ( (*((unsigned __int8 (**)(void))&pObject1->vfptr->__vecDelDtor + 3))() )
  {
LABEL_4:
    v5 = 0i64;
    if ( LODWORD(v3[1].vfptr) )
    {
      while ( !UFG::CoverObjectBase::IsAnyLineOrCornerShared(
                 v2,
                 *(UFG::CoverObjectBase **)(*(_QWORD *)&v3[1].m_iRefCount + 8 * v5)) )
      {
        v5 = (unsigned int)(v5 + 1);
        if ( (unsigned int)v5 >= LODWORD(v3[1].vfptr) )
          goto LABEL_7;
      }
      result = 1;
    }
    else
    {
LABEL_7:
      result = 0;
    }
  }
  else
  {
    while ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v2->vfptr->__vecDelDtor + 3))(v2) )
    {
      v4 = v3;
      v3 = v2;
      v2 = v4;
      if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v3->vfptr->__vecDelDtor + 3))(v3) )
        goto LABEL_4;
    }
    if ( v3->vfptr->IsPosition(v3) )
    {
      v7 = v3->vfptr;
      v8 = v2;
      v9 = v3;
    }
    else
    {
      v7 = v2->vfptr;
      v8 = v3;
      v9 = v2;
    }
    result = v7->IsAnyLineOrCornerShared(v9, v8);
  }
  return result;
}

// File Line: 340
// RVA: 0x34E1E0
void __fastcall UFG::CoverObjectBase::CheckObstructionLineLine(UFG::CoverObjectParkour *pFirst, UFG::CoverObjectParkour *pSecond, unsigned int *uObstructed)
{
  unsigned int *v3; // rsi
  UFG::CoverObjectParkour *v4; // rdi
  UFG::CoverObjectParkour *v5; // rbx
  UFG::ParkourHandle *v6; // r14
  UFG::ParkourHandle *v7; // r15
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm8_4
  __m128 v11; // xmm2
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm13_4
  float v15; // xmm12_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  UFG::qVector3 vZoneNormal; // [rsp+40h] [rbp-A8h]
  UFG::qVector3 result; // [rsp+50h] [rbp-98h]
  UFG::qVector3 vZonePt1; // [rsp+60h] [rbp-88h]
  UFG::qVector3 p1; // [rsp+6Ch] [rbp-7Ch]
  UFG::qVector3 p0; // [rsp+78h] [rbp-70h]
  UFG::qVector3 vTestPt2; // [rsp+84h] [rbp-64h]
  UFG::qVector3 vZoneAxis; // [rsp+90h] [rbp-58h]
  UFG::qVector3 out; // [rsp+A0h] [rbp-48h]
  __int64 v28; // [rsp+B0h] [rbp-38h]

  v28 = -2i64;
  v3 = uObstructed;
  v4 = pSecond;
  v5 = pFirst;
  *uObstructed = 0;
  v6 = pFirst->m_pParkourHandle.m_pPointer;
  v7 = pSecond->m_pParkourHandle.m_pPointer;
  v8 = UFG::ParkourHandle::GetHalfLength(pFirst->m_pParkourHandle.m_pPointer);
  v9 = UFG::ParkourHandle::GetHalfLength(v7);
  v10 = v9;
  UFG::CoverObjectParkour::GetParkourSync(v5, &result);
  UFG::CoverObjectParkour::GetParkourSync(v4, &vZoneNormal);
  v11 = (__m128)LODWORD(vZoneNormal.x);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(vZoneNormal.z - result.z) & _xmm) < 0.5 )
  {
    v11.m128_f32[0] = (float)((float)(vZoneNormal.x - result.x) * (float)(vZoneNormal.x - result.x))
                    + (float)((float)(vZoneNormal.y - result.y) * (float)(vZoneNormal.y - result.y));
    if ( COERCE_FLOAT(_mm_sqrt_ps(v11)) < (float)((float)(v9 + v8) + 0.5) )
    {
      UFG::ParkourHandle::GetNormal(v6, &out);
      UFG::ParkourHandle::GetNormal(v7, &vZoneNormal);
      v12 = (float)((float)(out.x * vZoneNormal.x) + (float)(out.y * vZoneNormal.y)) + (float)(out.z * vZoneNormal.z);
      if ( _S53 & 1 )
      {
        v13 = kfMinDot;
      }
      else
      {
        _S53 |= 1u;
        v13 = cosf(0.78539819);
        kfMinDot = v13;
      }
      if ( v12 > v13 )
      {
        UFG::ParkourHandle::GetEndpoints(v6, &p0, &p1);
        UFG::ParkourHandle::GetEndpoints(v7, &p0, &vTestPt2);
        v14 = (float)((float)(p1.y - vTestPt2.y) * (float)(p0.x - vTestPt2.x))
            - (float)((float)(p0.y - vTestPt2.y) * (float)(p1.x - vTestPt2.x));
        v15 = (float)((float)(p1.y - p0.y) * (float)(p0.x - p0.x))
            - (float)((float)(p0.y - p0.y) * (float)(p1.x - p0.x));
        if ( (float)(v15 * v14) >= 0.0
          || (v16 = (float)((float)(vTestPt2.y - p0.y) * (float)(p0.x - p0.x))
                  - (float)((float)(p0.y - p0.y) * (float)(vTestPt2.x - p0.x)),
              v17 = (float)(v16 + v15) - v14,
              (float)(v17 * v16) >= 0.0)
          || ((v18 = v16 / (float)(v16 - v17), v18 <= 0.5) ? (v19 = v18) : (v19 = 1.0 - v18),
              (float)((float)(v19 * v8) * 2.0) <= 0.1) )
        {
          UFG::ParkourHandle::GetAxis(v6, &vZoneAxis);
          p1.x = p1.x - (float)(vZoneAxis.x * 0.1);
          p1.y = p1.y - (float)(vZoneAxis.y * 0.1);
          p1.z = p1.z - (float)(vZoneAxis.z * 0.1);
          vZonePt1.x = p0.x + (float)(vZoneAxis.x * 0.1);
          vZonePt1.y = p0.y + (float)(vZoneAxis.y * 0.1);
          vZonePt1.z = vZonePt1.z + (float)(vZoneAxis.z * 0.1);
          if ( UFG::CoverObjectBase::IsZoneObstructed(
                 &vZonePt1,
                 &p1,
                 &out,
                 &vZoneAxis,
                 (float)(v8 - 0.1) * 2.0,
                 &p0,
                 &vTestPt2) )
          {
            *v3 = 1;
          }
          else
          {
            UFG::ParkourHandle::GetAxis(v7, &result);
            vZonePt1.x = vTestPt2.x - (float)(result.x * 0.1);
            vZonePt1.y = vTestPt2.y - (float)(result.y * 0.1);
            vZonePt1.z = vTestPt2.z - (float)(result.z * 0.1);
            p1.x = p0.x + (float)(result.x * 0.1);
            p1.y = p0.y + (float)(result.y * 0.1);
            p1.z = p0.z + (float)(result.z * 0.1);
            if ( UFG::CoverObjectBase::IsZoneObstructed(
                   &p1,
                   &vZonePt1,
                   &vZoneNormal,
                   &result,
                   (float)(v10 - 0.1) * 2.0,
                   &p0,
                   &p1) )
            {
              *v3 = 2;
            }
          }
        }
        else
        {
          *v3 = 3;
        }
      }
    }
  }
}

// File Line: 420
// RVA: 0x36C590
char __fastcall UFG::CoverObjectBase::IsZoneObstructed(UFG::qVector3 *vZonePt1, UFG::qVector3 *vZonePt2, UFG::qVector3 *vZoneNormal, UFG::qVector3 *vZoneAxis, float fZoneLen, UFG::qVector3 *vTestPt1, UFG::qVector3 *vTestPt2)
{
  float v7; // xmm10_4
  float v8; // xmm11_4
  float v9; // xmm8_4
  float v10; // xmm5_4
  float v11; // xmm9_4
  float v12; // xmm6_4
  float v13; // xmm2_4
  float v14; // xmm4_4
  float v15; // xmm2_4
  char result; // al
  float v17; // xmm6_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm0_4
  float v24; // xmm2_4
  float v25; // xmm13_4
  float v26; // xmm14_4
  float v27; // xmm2_4
  float v28; // xmm9_4
  float v29; // xmm1_4
  float v30; // xmm4_4

  v7 = vZonePt1->x;
  v8 = vZonePt1->y;
  v9 = vTestPt1->x;
  v10 = vTestPt1->y;
  v11 = vTestPt1->z - vZonePt1->z;
  v12 = vTestPt1->x - vZonePt1->x;
  v13 = vTestPt1->y - v8;
  v14 = (float)((float)(vZoneAxis->x * v12) + (float)(vZoneAxis->y * v13)) + (float)(vZoneAxis->z * v11);
  if ( v14 > 0.0 && v14 < fZoneLen )
  {
    v15 = (float)((float)(v13 * vZoneNormal->y) + (float)(v12 * vZoneNormal->x)) + (float)(v11 * vZoneNormal->z);
    if ( v15 > 0.0 && v15 < 1.0 )
      goto LABEL_17;
  }
  v17 = vTestPt2->x;
  v18 = vTestPt2->y;
  v19 = vTestPt2->z - vZonePt1->z;
  v20 = vTestPt2->x - v7;
  v21 = vTestPt2->y - v8;
  v22 = (float)((float)(vZoneAxis->x * v20) + (float)(vZoneAxis->y * v21)) + (float)(vZoneAxis->z * v19);
  if ( v22 > 0.0 && v22 < fZoneLen )
  {
    v23 = (float)((float)(v21 * vZoneNormal->y) + (float)(v20 * vZoneNormal->x)) + (float)(v19 * vZoneNormal->z);
    if ( v23 > 0.0 && v23 < 1.0 )
      goto LABEL_17;
  }
  if ( (v24 = vZonePt2->y + vZoneNormal->y,
        v25 = (float)((float)(vZonePt2->x - v17) * (float)(v24 - v18))
            - (float)((float)(vZonePt2->y - v18) * (float)((float)(vZonePt2->x + vZoneNormal->x) - v17)),
        v26 = (float)((float)(vZonePt2->x - v9) * (float)(v24 - v10))
            - (float)((float)(vZonePt2->y - v10) * (float)((float)(vZonePt2->x + vZoneNormal->x) - v9)),
        (float)(v26 * v25) < 0.0)
    && (v27 = (float)((float)(v18 - vZonePt2->y) * (float)(v9 - vZonePt2->x))
            - (float)((float)(v10 - vZonePt2->y) * (float)(v17 - vZonePt2->x)),
        (float)((float)((float)(v27 + v26) - v25) * v27) < 0.0)
    || (v28 = (float)((float)(v7 - v17) * (float)((float)(v8 + vZoneNormal->y) - v18))
            - (float)((float)(v8 - v18) * (float)((float)(v7 + vZoneNormal->x) - v17)),
        v29 = (float)((float)(v7 - v9) * (float)((float)(v8 + vZoneNormal->y) - v10))
            - (float)((float)(v8 - v10) * (float)((float)(v7 + vZoneNormal->x) - v9)),
        (float)(v29 * v28) < 0.0)
    && (v30 = (float)((float)(v18 - v8) * (float)(v9 - v7)) - (float)((float)(v10 - v8) * (float)(v17 - v7)),
        (float)((float)((float)(v30 + v29) - v28) * v30) < 0.0) )
  {
LABEL_17:
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 465
// RVA: 0x34DF80
void __usercall UFG::CoverObjectBase::CheckObstructionLineCorner(UFG::CoverObjectParkour *pFirst@<rcx>, UFG::CoverObjectCorner *pSecond@<rdx>, unsigned int *uObstructed@<r8>, float a4@<xmm0>)
{
  unsigned int *v4; // rsi
  UFG::CoverObjectCorner *v5; // rdi
  UFG::CoverObjectParkour *v6; // rbx
  float v7; // xmm3_4
  UFG::CoverCornerHandle *v8; // rbp
  signed __int64 v9; // rdi
  float v10; // xmm6_4
  UFG::CoverCorner *v11; // rax
  UFG::qVector3 *v12; // rax
  float v13; // xmm2_4
  float v14; // xmm6_4
  __m128 v15; // xmm7
  UFG::qVector3 *v16; // rax
  float v17; // [rsp+28h] [rbp-90h]
  float v18; // [rsp+2Ch] [rbp-8Ch]
  float v19; // [rsp+30h] [rbp-88h]
  float v20; // [rsp+38h] [rbp-80h]
  float v21; // [rsp+3Ch] [rbp-7Ch]
  float v22; // [rsp+40h] [rbp-78h]
  UFG::qVector3 result; // [rsp+48h] [rbp-70h]
  UFG::qVector3 v24; // [rsp+58h] [rbp-60h]
  UFG::qVector3 p0; // [rsp+68h] [rbp-50h]
  UFG::qVector3 p1; // [rsp+74h] [rbp-44h]

  v4 = uObstructed;
  v5 = pSecond;
  v6 = pFirst;
  pSecond->vfptr->GetHeight((UFG::CoverObjectBase *)pSecond);
  if ( a4 <= 0.5 || a4 >= 1.6 )
  {
    v6->vfptr->GetHeight((UFG::CoverObjectBase *)&v6->vfptr);
    v6->vfptr->GetHeight((UFG::CoverObjectBase *)&v6->vfptr);
    if ( a4 > 0.5 && a4 < 1.6 )
      goto LABEL_16;
    if ( a4 <= 1.5 )
      goto LABEL_16;
  }
  v6->vfptr->GetWallNormal((UFG::CoverObjectBase *)&v6->vfptr, (UFG::qVector3 *)&v17);
  v5->vfptr->GetWallNormal((UFG::CoverObjectBase *)&v5->vfptr, (UFG::qVector3 *)&v20);
  if ( _S56 & 1 )
  {
    v7 = kfMinDot_0;
  }
  else
  {
    _S56 |= 1u;
    v7 = cosf(45.0);
    kfMinDot_0 = v7;
  }
  if ( (float)((float)((float)(v17 * v20) + (float)(v18 * v21)) + (float)(v19 * v22)) <= v7 )
    goto LABEL_16;
  v8 = &v5->m_CornerHandle;
  v9 = UFG::CoverCornerHandle::Get(&v5->m_CornerHandle);
  v10 = *(float *)(v9 + 24);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(v10 - UFG::CoverObjectParkour::GetParkourSync(v6, &result)->z) & _xmm) >= 1.0 )
    goto LABEL_16;
  UFG::ParkourHandle::GetEndpoints(v6->m_pParkourHandle.m_pPointer, &p0, &p1);
  v11 = (UFG::CoverCorner *)UFG::CoverCornerHandle::Get(v8);
  v12 = UFG::CoverCorner::GetAlongWall(v11, &result);
  v13 = v12->y * 0.30000001;
  result.x = *(float *)(v9 + 16) - (float)(v12->x * 0.30000001);
  v14 = result.x;
  v15 = (__m128)*(unsigned int *)(v9 + 20);
  v15.m128_f32[0] = v15.m128_f32[0] - v13;
  LODWORD(result.y) = v15.m128_i32[0];
  p0.z = 0.0;
  p1.z = 0.0;
  result.z = 0.0;
  v16 = UFG::qNearestSegPoint(&v24, &p0, &p1, &result);
  v15.m128_f32[0] = (float)((float)((float)(v15.m128_f32[0] - v16->y) * (float)(v15.m128_f32[0] - v16->y))
                          + (float)((float)(v14 - v16->x) * (float)(v14 - v16->x)))
                  + (float)(COERCE_FLOAT(LODWORD(v16->z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(v16->z) ^ _xmm[0]));
  if ( COERCE_FLOAT(_mm_sqrt_ps(v15)) >= 0.15000001 )
LABEL_16:
    *v4 = 0;
  else
    *v4 = 2;
}

// File Line: 515
// RVA: 0x34E970
void __fastcall UFG::CoverObjectBase::Clear(UFG::CoverObjectBase *this)
{
  UFG::CoverObjectBase *v1; // rbx

  v1 = this;
  ((void (*)(void))this->vfptr->RemoveUser)();
  v1->m_fPriority = 0.0;
  v1->m_pCoverObjectGroup = 0i64;
}

// File Line: 523
// RVA: 0x355D30
char __fastcall UFG::CoverObjectBase::FacesPosition(UFG::CoverObjectBase *this, UFG::qVector3 *vPosition, float fTestAngle)
{
  UFG::qVector3 *v3; // rbx
  UFG::CoverObjectBase *v4; // rdi
  float v5; // xmm9_4
  UFG::qVector3 *v6; // rax
  __m128 v7; // xmm7
  float v8; // xmm8_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  __m128 v11; // xmm1
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v15; // [rsp+20h] [rbp-68h]
  float v16; // [rsp+24h] [rbp-64h]
  float v17; // [rsp+28h] [rbp-60h]
  char v18; // [rsp+30h] [rbp-58h]

  v3 = vPosition;
  v4 = this;
  v5 = fTestAngle;
  v6 = this->vfptr->GetPosition(this, (UFG::qVector3 *)&v18);
  v7 = (__m128)LODWORD(v3->x);
  v7.m128_f32[0] = v7.m128_f32[0] - v6->x;
  v8 = v3->y - v6->y;
  v9 = v3->z - v6->z;
  v4->vfptr->GetWallNormal(v4, (UFG::qVector3 *)&v15);
  if ( (float)((float)((float)(v15 * v7.m128_f32[0]) + (float)(v16 * v8)) + (float)(v17 * v9)) >= 0.0 )
    return 0;
  v10 = *(float *)&FLOAT_1_0;
  v11 = v7;
  v11.m128_f32[0] = (float)(v7.m128_f32[0] * v7.m128_f32[0]) + (float)(v8 * v8);
  v12 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v11));
  LODWORD(v13) = COERCE_UNSIGNED_INT(
                   (float)((float)((float)(v12 * v7.m128_f32[0]) * v15) + (float)((float)(v12 * v8) * v16))
                 + (float)(v17 * 0.0)) ^ _xmm[0];
  if ( v13 <= -1.0 )
  {
    v13 = FLOAT_N1_0;
    goto LABEL_6;
  }
  if ( v13 < 1.0 )
LABEL_6:
    v10 = v13;
  if ( acosf(v10) < v5 )
    return 1;
  return 0;
}

// File Line: 554
// RVA: 0x359770
void __fastcall UFG::CoverObjectBase::GetAngleFromSweetSpot(UFG::CoverObjectBase *this, UFG::qVector3 *vPosition)
{
  UFG::qVector3 *v2; // rdi
  UFG::CoverObjectBase *v3; // rbx
  float v4; // xmm2_4
  float v5; // xmm7_4
  __m128 v6; // xmm5
  float v7; // xmm6_4
  float v8; // xmm3_4
  __m128 v9; // xmm4
  float v10; // xmm2_4
  float v11; // [rsp+20h] [rbp-48h]
  float v12; // [rsp+24h] [rbp-44h]
  float v13; // [rsp+28h] [rbp-40h]
  float v14; // [rsp+30h] [rbp-38h]
  float v15; // [rsp+34h] [rbp-34h]
  float v16; // [rsp+38h] [rbp-30h]

  v2 = vPosition;
  v3 = this;
  this->vfptr->GetFiringPosition(this, (UFG::qVector3 *)&v11);
  v3->vfptr->GetSweetSpotDir(v3, (UFG::qVector3 *)&v14);
  v6 = (__m128)LODWORD(v2->y);
  v4 = 0.0;
  v5 = v2->x - v11;
  v6.m128_f32[0] = v6.m128_f32[0] - v12;
  v7 = v2->z - v13;
  v9 = v6;
  v8 = *(float *)&FLOAT_1_0;
  v9.m128_f32[0] = (float)((float)(v6.m128_f32[0] * v6.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
  if ( v9.m128_f32[0] != 0.0 )
    v4 = 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v9));
  v10 = (float)((float)(v15 * (float)(v6.m128_f32[0] * v4)) + (float)(v14 * (float)(v4 * v5)))
      + (float)(v16 * (float)(v7 * v4));
  if ( v10 <= -1.0 )
  {
    v10 = FLOAT_N1_0;
  }
  else if ( v10 >= 1.0 )
  {
    goto LABEL_8;
  }
  v8 = v10;
LABEL_8:
  acosf(v8);
}

