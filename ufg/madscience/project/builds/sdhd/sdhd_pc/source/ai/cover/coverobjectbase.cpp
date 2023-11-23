// File Line: 32
// RVA: 0x14AD3F0
__int64 dynamic_initializer_for__UFG::CoverObjectBase::ms_listUsers__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__UFG::CoverObjectBase::ms_listUsers__);
}

// File Line: 50
// RVA: 0x335DC0
void __fastcall UFG::CoverObjectBase::~CoverObjectBase(UFG::CoverObjectBase *this)
{
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable;
}

// File Line: 64
// RVA: 0x36A080
char __fastcall UFG::CoverObjectBase::IsConnected(
        UFG::CoverObjectParkour *coParkourA,
        UFG::CoverObjectParkour *coParkourB)
{
  UFG::ParkourHandle *m_pPointer; // rsi
  UFG::ParkourHandle *v3; // rdi
  float v5; // xmm2_4
  float v6; // xmm0_4
  __int64 v7; // r8
  UFG::qVector3 *p_p0; // rdx
  __int64 v9; // rax
  UFG::qVector3 *v10; // rcx
  UFG::qVector3 out; // [rsp+20h] [rbp-A8h] BYREF
  UFG::qVector3 v13; // [rsp+30h] [rbp-98h] BYREF
  char v14[8]; // [rsp+40h] [rbp-88h] BYREF
  float v15; // [rsp+48h] [rbp-80h]
  char v16[8]; // [rsp+50h] [rbp-78h] BYREF
  float v17; // [rsp+58h] [rbp-70h]
  UFG::qVector3 p0; // [rsp+60h] [rbp-68h] BYREF
  UFG::qVector3 p1; // [rsp+6Ch] [rbp-5Ch] BYREF
  UFG::qVector3 v20; // [rsp+78h] [rbp-50h] BYREF
  UFG::qVector3 v21; // [rsp+84h] [rbp-44h] BYREF

  m_pPointer = coParkourB->m_pParkourHandle.m_pPointer;
  v3 = coParkourA->m_pParkourHandle.m_pPointer;
  coParkourA->vfptr->GetSyncPos(coParkourA, (UFG::qVector3 *)v14);
  coParkourB->vfptr->GetSyncPos(coParkourB, (UFG::qVector3 *)v16);
  UFG::ParkourHandle::GetNormal(v3, &out);
  UFG::ParkourHandle::GetNormal(m_pPointer, &v13);
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
    UFG::ParkourHandle::GetEndpoints(m_pPointer, &v20, &v21);
    v7 = 0i64;
    p_p0 = &p0;
    while ( 2 )
    {
      v9 = 0i64;
      v10 = &v20;
      do
      {
        if ( (float)((float)((float)(p_p0->x - v10->x) * (float)(p_p0->x - v10->x))
                   + (float)((float)(p_p0->y - v10->y) * (float)(p_p0->y - v10->y))) < fCompareDistSqr2D
          && COERCE_FLOAT(COERCE_UNSIGNED_INT(v15 - v17) & _xmm) < fCompareHeight )
        {
          return 1;
        }
        ++v9;
        ++v10;
      }
      while ( v9 < 2 );
      ++v7;
      ++p_p0;
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
  UFG::ParkourHandle *m_pPointer; // rsi
  UFG::CoverCorner *v4; // rdi
  float v5; // xmm2_4
  float v6; // xmm0_4
  __int64 v7; // rcx
  UFG::qVector3 *i; // rax
  UFG::qVector3 out; // [rsp+20h] [rbp-68h] BYREF
  char v11[8]; // [rsp+30h] [rbp-58h] BYREF
  float v12; // [rsp+38h] [rbp-50h]
  UFG::qVector3 p0; // [rsp+40h] [rbp-48h] BYREF
  UFG::qVector3 p1; // [rsp+4Ch] [rbp-3Ch] BYREF

  m_pPointer = coParkour->m_pParkourHandle.m_pPointer;
  v4 = UFG::CoverCornerHandle::Get(&coCorner->m_CornerHandle);
  coParkour->vfptr->GetSyncPos(coParkour, (UFG::qVector3 *)v11);
  UFG::ParkourHandle::GetNormal(m_pPointer, &out);
  v5 = (float)((float)(out.y * v4->m_vWallNormal.y) + (float)(out.x * v4->m_vWallNormal.x)) + (float)(out.z * 0.0);
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
  UFG::ParkourHandle::GetEndpoints(m_pPointer, &p0, &p1);
  v7 = 0i64;
  for ( i = &p0;
        (float)((float)((float)(i->y - v4->m_vCornerPosition.y) * (float)(i->y - v4->m_vCornerPosition.y))
              + (float)((float)(i->x - v4->m_vCornerPosition.x) * (float)(i->x - v4->m_vCornerPosition.x))) >= fCompareDistSqr2D_0
     || COERCE_FLOAT(COERCE_UNSIGNED_INT(v12 - v4->m_vCornerPosition.z) & _xmm) >= fCompareHeight_0;
        ++i )
  {
    if ( ++v7 >= 2 )
      return 0;
  }
  return 1;
}

// File Line: 156
// RVA: 0x369F90
bool __fastcall UFG::CoverObjectBase::IsConnected(UFG::CoverObjectCorner *coCornerA, UFG::CoverObjectCorner *coCornerB)
{
  UFG::CoverCorner *v3; // rdi
  UFG::CoverCorner *v4; // rbx
  float v5; // xmm1_4
  float v6; // xmm0_4
  bool v7; // al
  UFG::qVector3 result; // [rsp+20h] [rbp-28h] BYREF
  UFG::qVector3 v9; // [rsp+30h] [rbp-18h] BYREF

  v3 = UFG::CoverCornerHandle::Get(&coCornerA->m_CornerHandle);
  v4 = UFG::CoverCornerHandle::Get(&coCornerB->m_CornerHandle);
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
      return 1;
    }
  }
  return v7;
}

// File Line: 191
// RVA: 0x36B600
bool __fastcall UFG::CoverObjectBase::IsLeft(UFG::CoverObjectParkour *coParkourA, UFG::CoverObjectParkour *coParkourB)
{
  UFG::ParkourHandle *m_pPointer; // rbx
  UFG::ParkourHandle *v3; // rdi
  float v4; // xmm8_4
  float v5; // xmm7_4
  float v6; // xmm6_4
  UFG::qVector3 *Position; // rbx
  UFG::qVector3 *v8; // rax
  UFG::qVector3 out; // [rsp+20h] [rbp-68h] BYREF
  UFG::qVector3 result; // [rsp+30h] [rbp-58h] BYREF
  UFG::qVector3 v12; // [rsp+3Ch] [rbp-4Ch] BYREF

  m_pPointer = coParkourA->m_pParkourHandle.m_pPointer;
  v3 = coParkourB->m_pParkourHandle.m_pPointer;
  UFG::ParkourHandle::GetNormal(m_pPointer, &out);
  v4 = (float)(UFG::qVector3::msAxisZ.y * out.z) - (float)(UFG::qVector3::msAxisZ.z * out.y);
  v5 = (float)(UFG::qVector3::msAxisZ.z * out.x) - (float)(UFG::qVector3::msAxisZ.x * out.z);
  v6 = (float)(UFG::qVector3::msAxisZ.x * out.y) - (float)(UFG::qVector3::msAxisZ.y * out.x);
  Position = UFG::ParkourHandle::GetPosition(m_pPointer, &result);
  v8 = UFG::ParkourHandle::GetPosition(v3, &v12);
  return (float)((float)((float)((float)(v8->y - Position->y) * v5) + (float)((float)(v8->x - Position->x) * v4))
               + (float)((float)(v8->z - Position->z) * v6)) > 0.0;
}

// File Line: 214
// RVA: 0x36B700
bool __fastcall UFG::CoverObjectBase::IsLeft(UFG::CoverObjectParkour *coParkour, UFG::CoverObjectCorner *coCorner)
{
  UFG::ParkourHandle *m_pPointer; // rbx
  UFG::CoverCorner *v3; // rdi
  float v4; // xmm8_4
  float v5; // xmm7_4
  float v6; // xmm6_4
  UFG::qVector3 *Position; // rax
  UFG::qVector3 out; // [rsp+20h] [rbp-58h] BYREF
  UFG::qVector3 result; // [rsp+30h] [rbp-48h] BYREF

  m_pPointer = coParkour->m_pParkourHandle.m_pPointer;
  v3 = UFG::CoverCornerHandle::Get(&coCorner->m_CornerHandle);
  UFG::ParkourHandle::GetNormal(m_pPointer, &out);
  v4 = (float)(UFG::qVector3::msAxisZ.y * out.z) - (float)(UFG::qVector3::msAxisZ.z * out.y);
  v5 = (float)(UFG::qVector3::msAxisZ.z * out.x) - (float)(UFG::qVector3::msAxisZ.x * out.z);
  v6 = (float)(UFG::qVector3::msAxisZ.x * out.y) - (float)(UFG::qVector3::msAxisZ.y * out.x);
  Position = UFG::ParkourHandle::GetPosition(m_pPointer, &result);
  return (float)((float)((float)((float)(v3->m_vCornerPosition.y - Position->y) * v5)
                       + (float)((float)(v3->m_vCornerPosition.x - Position->x) * v4))
               + (float)((float)(v3->m_vCornerPosition.z - Position->z) * v6)) > 0.0;
}

// File Line: 237
// RVA: 0x36B530
bool __fastcall UFG::CoverObjectBase::IsLeft(UFG::CoverObjectCorner *coCornerA, UFG::CoverObjectCorner *coCornerB)
{
  UFG::CoverCorner *v3; // rdi
  UFG::CoverCorner *v4; // rax

  v3 = UFG::CoverCornerHandle::Get(&coCornerA->m_CornerHandle);
  v4 = UFG::CoverCornerHandle::Get(&coCornerB->m_CornerHandle);
  return (float)((float)((float)((float)(v4->m_vCornerPosition.y - v3->m_vCornerPosition.y)
                               * (float)((float)(UFG::qVector3::msAxisZ.z * v3->m_vWallNormal.x)
                                       - (float)(UFG::qVector3::msAxisZ.x * 0.0)))
                       + (float)((float)(v4->m_vCornerPosition.x - v3->m_vCornerPosition.x)
                               * (float)((float)(UFG::qVector3::msAxisZ.y * 0.0)
                                       - (float)(UFG::qVector3::msAxisZ.z * v3->m_vWallNormal.y))))
               + (float)((float)(v4->m_vCornerPosition.z - v3->m_vCornerPosition.z)
                       * (float)((float)(UFG::qVector3::msAxisZ.x * v3->m_vWallNormal.y)
                               - (float)(UFG::qVector3::msAxisZ.y * v3->m_vWallNormal.x)))) > 0.0;
}

// File Line: 258
// RVA: 0x369960
char __fastcall UFG::CoverObjectBase::IsAnyLineOrCornerShared(
        UFG::CoverObjectBase *pObject1,
        UFG::CoverObjectBase *pObject2)
{
  UFG::CoverObjectBase *v3; // rbx
  UFG::CoverObjectBase *v4; // rax
  __int64 v5; // rdi
  UFG::CoverObjectBaseVtbl *vfptr; // rax
  UFG::CoverObjectBase *v8; // rdx
  UFG::CoverObjectBase *v9; // rcx

  v3 = pObject1;
  if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&pObject1->vfptr->__vecDelDtor + 3))(pObject1) )
  {
LABEL_4:
    v5 = 0i64;
    if ( LODWORD(v3[1].vfptr) )
    {
      while ( !UFG::CoverObjectBase::IsAnyLineOrCornerShared(
                 pObject2,
                 *(UFG::CoverObjectBase **)(*(_QWORD *)&v3[1].m_iRefCount + 8 * v5)) )
      {
        v5 = (unsigned int)(v5 + 1);
        if ( (unsigned int)v5 >= LODWORD(v3[1].vfptr) )
          return 0;
      }
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    while ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&pObject2->vfptr->__vecDelDtor + 3))(pObject2) )
    {
      v4 = v3;
      v3 = pObject2;
      pObject2 = v4;
      if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v3->vfptr->__vecDelDtor + 3))(v3) )
        goto LABEL_4;
    }
    if ( v3->vfptr->IsPosition(v3) )
    {
      vfptr = v3->vfptr;
      v8 = pObject2;
      v9 = v3;
    }
    else
    {
      vfptr = pObject2->vfptr;
      v8 = v3;
      v9 = pObject2;
    }
    return vfptr->IsAnyLineOrCornerShared(v9, v8);
  }
}

// File Line: 340
// RVA: 0x34E1E0
void __fastcall UFG::CoverObjectBase::CheckObstructionLineLine(
        UFG::CoverObjectParkour *pFirst,
        UFG::CoverObjectParkour *pSecond,
        unsigned int *uObstructed)
{
  UFG::ParkourHandle *m_pPointer; // r14
  UFG::ParkourHandle *v7; // r15
  float HalfLength; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm8_4
  __m128 x_low; // xmm2
  float v12; // xmm6_4
  float v13; // xmm0_4
  float v14; // xmm13_4
  float v15; // xmm12_4
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  UFG::qVector3 vZoneNormal; // [rsp+40h] [rbp-A8h] BYREF
  UFG::qVector3 result; // [rsp+50h] [rbp-98h] BYREF
  UFG::qVector3 vZonePt1; // [rsp+60h] [rbp-88h] BYREF
  UFG::qVector3 p1; // [rsp+6Ch] [rbp-7Ch] BYREF
  UFG::qVector3 p0; // [rsp+78h] [rbp-70h] BYREF
  UFG::qVector3 vTestPt2; // [rsp+84h] [rbp-64h] BYREF
  UFG::qVector3 vZoneAxis; // [rsp+90h] [rbp-58h] BYREF
  UFG::qVector3 out; // [rsp+A0h] [rbp-48h] BYREF
  __int64 v28; // [rsp+B0h] [rbp-38h]

  v28 = -2i64;
  *uObstructed = 0;
  m_pPointer = pFirst->m_pParkourHandle.m_pPointer;
  v7 = pSecond->m_pParkourHandle.m_pPointer;
  HalfLength = UFG::ParkourHandle::GetHalfLength(m_pPointer);
  v9 = UFG::ParkourHandle::GetHalfLength(v7);
  v10 = v9;
  UFG::CoverObjectParkour::GetParkourSync(pFirst, &result);
  UFG::CoverObjectParkour::GetParkourSync(pSecond, &vZoneNormal);
  x_low = (__m128)LODWORD(vZoneNormal.x);
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(vZoneNormal.z - result.z) & _xmm) < 0.5 )
  {
    x_low.m128_f32[0] = (float)((float)(vZoneNormal.x - result.x) * (float)(vZoneNormal.x - result.x))
                      + (float)((float)(vZoneNormal.y - result.y) * (float)(vZoneNormal.y - result.y));
    if ( _mm_sqrt_ps(x_low).m128_f32[0] < (float)((float)(v9 + HalfLength) + 0.5) )
    {
      UFG::ParkourHandle::GetNormal(m_pPointer, &out);
      UFG::ParkourHandle::GetNormal(v7, &vZoneNormal);
      v12 = (float)((float)(out.x * vZoneNormal.x) + (float)(out.y * vZoneNormal.y)) + (float)(out.z * vZoneNormal.z);
      if ( (_S53 & 1) != 0 )
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
        UFG::ParkourHandle::GetEndpoints(m_pPointer, &p0, &p1);
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
              (float)((float)(v19 * HalfLength) * 2.0) <= 0.1) )
        {
          UFG::ParkourHandle::GetAxis(m_pPointer, &vZoneAxis);
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
                 (float)(HalfLength - 0.1) * 2.0,
                 &p0,
                 &vTestPt2) )
          {
            *uObstructed = 1;
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
              *uObstructed = 2;
            }
          }
        }
        else
        {
          *uObstructed = 3;
        }
      }
    }
  }
}

// File Line: 420
// RVA: 0x36C590
char __fastcall UFG::CoverObjectBase::IsZoneObstructed(
        UFG::qVector3 *vZonePt1,
        UFG::qVector3 *vZonePt2,
        UFG::qVector3 *vZoneNormal,
        UFG::qVector3 *vZoneAxis,
        float fZoneLen,
        UFG::qVector3 *vTestPt1,
        UFG::qVector3 *vTestPt2)
{
  float x; // xmm10_4
  float y; // xmm11_4
  float v9; // xmm8_4
  float v10; // xmm5_4
  float v11; // xmm9_4
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm2_4
  float v16; // xmm6_4
  float v17; // xmm4_4
  float v18; // xmm2_4
  float v19; // xmm1_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm13_4
  float v24; // xmm14_4
  float v25; // xmm2_4
  float v26; // xmm9_4
  float v27; // xmm1_4
  float v28; // xmm4_4

  x = vZonePt1->x;
  y = vZonePt1->y;
  v9 = vTestPt1->x;
  v10 = vTestPt1->y;
  v11 = vTestPt1->z - vZonePt1->z;
  v12 = vTestPt1->x - vZonePt1->x;
  v13 = (float)((float)(vZoneAxis->x * v12) + (float)(vZoneAxis->y * (float)(v10 - y))) + (float)(vZoneAxis->z * v11);
  if ( v13 > 0.0 && v13 < fZoneLen )
  {
    v14 = (float)((float)((float)(v10 - y) * vZoneNormal->y) + (float)(v12 * vZoneNormal->x))
        + (float)(v11 * vZoneNormal->z);
    if ( v14 > 0.0 && v14 < 1.0 )
      return 1;
  }
  v16 = vTestPt2->x;
  v17 = vTestPt2->y;
  v18 = vTestPt2->z - vZonePt1->z;
  v19 = vTestPt2->x - x;
  v20 = (float)((float)(vZoneAxis->x * v19) + (float)(vZoneAxis->y * (float)(v17 - y))) + (float)(vZoneAxis->z * v18);
  if ( v20 > 0.0 && v20 < fZoneLen )
  {
    v21 = (float)((float)((float)(v17 - y) * vZoneNormal->y) + (float)(v19 * vZoneNormal->x))
        + (float)(v18 * vZoneNormal->z);
    if ( v21 > 0.0 && v21 < 1.0 )
      return 1;
  }
  v22 = vZonePt2->y + vZoneNormal->y;
  v23 = (float)((float)(vZonePt2->x - v16) * (float)(v22 - v17))
      - (float)((float)(vZonePt2->y - v17) * (float)((float)(vZonePt2->x + vZoneNormal->x) - v16));
  v24 = (float)((float)(vZonePt2->x - v9) * (float)(v22 - v10))
      - (float)((float)(vZonePt2->y - v10) * (float)((float)(vZonePt2->x + vZoneNormal->x) - v9));
  if ( (float)(v24 * v23) < 0.0 )
  {
    v25 = (float)((float)(v17 - vZonePt2->y) * (float)(v9 - vZonePt2->x))
        - (float)((float)(v10 - vZonePt2->y) * (float)(v16 - vZonePt2->x));
    if ( (float)((float)((float)(v25 + v24) - v23) * v25) < 0.0 )
      return 1;
  }
  v26 = (float)((float)(x - v16) * (float)((float)(y + vZoneNormal->y) - v17))
      - (float)((float)(y - v17) * (float)((float)(x + vZoneNormal->x) - v16));
  v27 = (float)((float)(x - v9) * (float)((float)(y + vZoneNormal->y) - v10))
      - (float)((float)(y - v10) * (float)((float)(x + vZoneNormal->x) - v9));
  if ( (float)(v27 * v26) < 0.0
    && (v28 = (float)((float)(v17 - y) * (float)(v9 - x)) - (float)((float)(v10 - y) * (float)(v16 - x)),
        (float)((float)((float)(v28 + v27) - v26) * v28) < 0.0) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

// File Line: 465
// RVA: 0x34DF80
void __fastcall UFG::CoverObjectBase::CheckObstructionLineCorner(
        UFG::CoverObjectParkour *pFirst,
        UFG::CoverObjectCorner *pSecond,
        unsigned int *uObstructed)
{
  float v6; // xmm0_4
  double v7; // xmm0_8
  float v8; // xmm8_4
  float v9; // xmm0_4
  float v10; // xmm3_4
  UFG::CoverCornerHandle *p_m_CornerHandle; // rbp
  UFG::CoverCorner *v12; // rdi
  float z; // xmm6_4
  UFG::CoverCorner *v14; // rax
  UFG::qVector3 *AlongWall; // rax
  float v16; // xmm2_4
  float x; // xmm6_4
  __m128 y_low; // xmm7
  UFG::qVector3 *v19; // rax
  int v20[4]; // [rsp+28h] [rbp-90h] BYREF
  int v21[4]; // [rsp+38h] [rbp-80h] BYREF
  UFG::qVector3 result; // [rsp+48h] [rbp-70h] BYREF
  UFG::qVector3 v23; // [rsp+58h] [rbp-60h] BYREF
  UFG::qVector3 p0; // [rsp+68h] [rbp-50h] BYREF
  UFG::qVector3 p1; // [rsp+74h] [rbp-44h] BYREF

  v6 = pSecond->vfptr->GetHeight(pSecond);
  if ( v6 <= 0.5 || v6 >= 1.6 )
  {
    v7 = ((double (__fastcall *)(UFG::CoverObjectParkour *))pFirst->vfptr->GetHeight)(pFirst);
    v8 = *(float *)&v7;
    v9 = pFirst->vfptr->GetHeight(pFirst);
    if ( v9 > 0.5 && v9 < 1.6 )
      goto LABEL_13;
    if ( v8 <= 1.5 )
      goto LABEL_13;
  }
  pFirst->vfptr->GetWallNormal(pFirst, (UFG::qVector3 *)v20);
  pSecond->vfptr->GetWallNormal(pSecond, (UFG::qVector3 *)v21);
  if ( (_S56 & 1) != 0 )
  {
    v10 = kfMinDot_0;
  }
  else
  {
    _S56 |= 1u;
    v10 = cosf(45.0);
    kfMinDot_0 = v10;
  }
  if ( (float)((float)((float)(*(float *)v20 * *(float *)v21) + (float)(*(float *)&v20[1] * *(float *)&v21[1]))
             + (float)(*(float *)&v20[2] * *(float *)&v21[2])) <= v10 )
    goto LABEL_13;
  p_m_CornerHandle = &pSecond->m_CornerHandle;
  v12 = UFG::CoverCornerHandle::Get(&pSecond->m_CornerHandle);
  z = v12->m_vCornerPosition.z;
  if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(z - UFG::CoverObjectParkour::GetParkourSync(pFirst, &result)->z) & _xmm) >= 1.0 )
    goto LABEL_13;
  UFG::ParkourHandle::GetEndpoints(pFirst->m_pParkourHandle.m_pPointer, &p0, &p1);
  v14 = UFG::CoverCornerHandle::Get(p_m_CornerHandle);
  AlongWall = UFG::CoverCorner::GetAlongWall(v14, &result);
  v16 = AlongWall->y * 0.30000001;
  result.x = v12->m_vCornerPosition.x - (float)(AlongWall->x * 0.30000001);
  x = result.x;
  y_low = (__m128)LODWORD(v12->m_vCornerPosition.y);
  y_low.m128_f32[0] = y_low.m128_f32[0] - v16;
  LODWORD(result.y) = y_low.m128_i32[0];
  p0.z = 0.0;
  p1.z = 0.0;
  result.z = 0.0;
  v19 = UFG::qNearestSegPoint(&v23, &p0, &p1, &result);
  y_low.m128_f32[0] = (float)((float)((float)(y_low.m128_f32[0] - v19->y) * (float)(y_low.m128_f32[0] - v19->y))
                            + (float)((float)(x - v19->x) * (float)(x - v19->x)))
                    + (float)(COERCE_FLOAT(LODWORD(v19->z) ^ _xmm[0]) * COERCE_FLOAT(LODWORD(v19->z) ^ _xmm[0]));
  if ( _mm_sqrt_ps(y_low).m128_f32[0] >= 0.15000001 )
LABEL_13:
    *uObstructed = 0;
  else
    *uObstructed = 2;
}

// File Line: 515
// RVA: 0x34E970
void __fastcall UFG::CoverObjectBase::Clear(UFG::CoverObjectBase *this)
{
  this->vfptr->RemoveUser(this);
  this->m_fPriority = 0.0;
  this->m_pCoverObjectGroup = 0i64;
}

// File Line: 523
// RVA: 0x355D30
bool __fastcall UFG::CoverObjectBase::FacesPosition(
        UFG::CoverObjectBase *this,
        UFG::qVector3 *vPosition,
        float fTestAngle)
{
  UFG::qVector3 *v6; // rax
  __m128 x_low; // xmm7
  float v8; // xmm8_4
  float v9; // xmm6_4
  float v10; // xmm3_4
  __m128 v11; // xmm1
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v15; // [rsp+20h] [rbp-68h] BYREF
  float v16; // [rsp+24h] [rbp-64h]
  float v17; // [rsp+28h] [rbp-60h]
  char v18[16]; // [rsp+30h] [rbp-58h] BYREF

  v6 = this->vfptr->GetPosition(this, v18);
  x_low = (__m128)LODWORD(vPosition->x);
  x_low.m128_f32[0] = x_low.m128_f32[0] - v6->x;
  v8 = vPosition->y - v6->y;
  v9 = vPosition->z - v6->z;
  this->vfptr->GetWallNormal(this, (UFG::qVector3 *)&v15);
  if ( (float)((float)((float)(v15 * x_low.m128_f32[0]) + (float)(v16 * v8)) + (float)(v17 * v9)) >= 0.0 )
    return 0;
  v10 = *(float *)&FLOAT_1_0;
  v11 = x_low;
  v11.m128_f32[0] = (float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v8 * v8);
  v12 = 1.0 / _mm_sqrt_ps(v11).m128_f32[0];
  LODWORD(v13) = COERCE_UNSIGNED_INT(
                   (float)((float)((float)(v12 * x_low.m128_f32[0]) * v15) + (float)((float)(v12 * v8) * v16))
                 + (float)(v17 * 0.0)) ^ _xmm[0];
  if ( v13 <= -1.0 )
  {
    v13 = FLOAT_N1_0;
    goto LABEL_6;
  }
  if ( v13 < 1.0 )
LABEL_6:
    v10 = v13;
  return acosf(v10) < fTestAngle;
}

// File Line: 554
// RVA: 0x359770
double __fastcall UFG::CoverObjectBase::GetAngleFromSweetSpot(UFG::CoverObjectBase *this, UFG::qVector3 *vPosition)
{
  float v4; // xmm2_4
  float v5; // xmm7_4
  __m128 y_low; // xmm5
  float v7; // xmm6_4
  __int64 v8; // xmm3_8
  __m128 v9; // xmm4
  float v10; // xmm6_4
  float v11; // xmm5_4
  float v12; // xmm1_4
  __int64 v13; // xmm2_8
  double result; // xmm0_8
  int v15[4]; // [rsp+20h] [rbp-48h] BYREF
  float v16; // [rsp+30h] [rbp-38h] BYREF
  float v17; // [rsp+34h] [rbp-34h]
  float v18; // [rsp+38h] [rbp-30h]

  this->vfptr->GetFiringPosition(this, (UFG::qVector3 *)v15);
  this->vfptr->GetSweetSpotDir(this, (UFG::qVector3 *)&v16);
  y_low = (__m128)LODWORD(vPosition->y);
  v4 = 0.0;
  v5 = vPosition->x - *(float *)v15;
  y_low.m128_f32[0] = y_low.m128_f32[0] - *(float *)&v15[1];
  v7 = vPosition->z - *(float *)&v15[2];
  v9 = y_low;
  v8 = (unsigned int)FLOAT_1_0;
  v9.m128_f32[0] = (float)((float)(y_low.m128_f32[0] * y_low.m128_f32[0]) + (float)(v5 * v5)) + (float)(v7 * v7);
  if ( v9.m128_f32[0] != 0.0 )
    v4 = 1.0 / _mm_sqrt_ps(v9).m128_f32[0];
  v10 = v7 * v4;
  v11 = y_low.m128_f32[0] * v4;
  v12 = v4 * v5;
  v13 = LODWORD(v17);
  *(float *)&v13 = (float)((float)(v17 * v11) + (float)(v16 * v12)) + (float)(v18 * v10);
  if ( *(float *)&v13 <= -1.0 )
  {
    v13 = LODWORD(FLOAT_N1_0);
  }
  else if ( *(float *)&v13 >= 1.0 )
  {
    goto LABEL_8;
  }
  v8 = v13;
LABEL_8:
  HIDWORD(result) = HIDWORD(v8);
  *(float *)&result = acosf(*(float *)&v8);
  return result;
}

