// File Line: 20
// RVA: 0x335DD0
void __fastcall UFG::CoverObjectGroup::~CoverObjectGroup(UFG::CoverObjectGroup *this)
{
  __int64 i; // rdi
  __int64 v3; // rsi
  UFG::CoverObjectBase *v4; // rcx
  UFG::CoverObjectBase *v5; // rcx
  UFG::CoverObjectBase **p; // rcx

  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectGroup::`vftable;
  for ( i = 0i64; (unsigned int)i < this->m_aChildObjects.size; i = (unsigned int)(i + 1) )
  {
    v3 = i;
    v4 = this->m_aChildObjects.p[i];
    if ( v4->vfptr->GetCoverObjectGroup(v4) == this )
      this->m_aChildObjects.p[v3]->vfptr->SetCoverObjectGroup(this->m_aChildObjects.p[v3], 0i64);
    v5 = this->m_aChildObjects.p[v3];
    if ( v5->m_iRefCount-- == 1 )
      v5->vfptr->__vecDelDtor(v5, 1u);
  }
  p = this->m_aChildObjects.p;
  if ( p )
    operator delete[](p);
  this->m_aChildObjects.p = 0i64;
  *(_QWORD *)&this->m_aChildObjects.size = 0i64;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable;
}

// File Line: 33
// RVA: 0x36BF60
char __fastcall UFG::CoverObjectGroup::IsValid(UFG::CoverObjectGroup *this)
{
  __int64 v3; // rbx
  UFG::CoverObjectBase *v4; // rcx

  if ( this->m_aChildObjects.size < 2 )
    return 0;
  v3 = 0i64;
  while ( 1 )
  {
    v4 = this->m_aChildObjects.p[v3];
    if ( !(*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v4->vfptr->__vecDelDtor + 2))(v4) )
      break;
    v3 = (unsigned int)(v3 + 1);
    if ( (unsigned int)v3 >= this->m_aChildObjects.size )
      return 1;
  }
  return 0;
}

// File Line: 57
// RVA: 0x3409E0
void __fastcall UFG::CoverObjectGroup::AddObject(UFG::CoverObjectGroup *this, UFG::CoverObjectBase *pCoverObject)
{
  UFG::CoverObjectBaseVtbl *vfptr; // rax
  unsigned int size; // r12d
  __int64 v6; // rbp
  unsigned int v7; // edi
  UFG::CoverObjectBase *v8; // rsi
  unsigned int v9; // ecx
  unsigned int capacity; // edi
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::CoverObjectBase **v15; // r15
  __int64 v16; // r8
  __int64 v17; // r8
  __int64 v18; // r9

  vfptr = pCoverObject->vfptr;
  ++pCoverObject->m_iRefCount;
  vfptr->SetCoverObjectGroup(pCoverObject, this);
  size = this->m_aChildObjects.size;
  v6 = 0i64;
  if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&pCoverObject->vfptr->__vecDelDtor + 2))(pCoverObject) )
  {
    v7 = 0;
    if ( this->m_aChildObjects.size )
    {
      while ( 1 )
      {
        v8 = this->m_aChildObjects.p[v7];
        if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v8->vfptr->__vecDelDtor + 2))(v8) )
        {
          if ( pCoverObject->vfptr->IsConnectedTo(pCoverObject, v8) && pCoverObject->vfptr->IsLeftOf(pCoverObject, v8) )
            break;
        }
        if ( ++v7 >= this->m_aChildObjects.size )
          goto LABEL_9;
      }
      size = v7;
    }
  }
LABEL_9:
  v9 = this->m_aChildObjects.size;
  capacity = this->m_aChildObjects.capacity;
  v11 = v9 + 1;
  if ( v9 + 1 > capacity )
  {
    if ( capacity )
      v12 = 2 * capacity;
    else
      v12 = 1;
    for ( ; v12 < v11; v12 *= 2 )
      ;
    if ( v12 <= 2 )
      v12 = 2;
    if ( v12 - v11 > 0x10000 )
      v12 = v9 + 65537;
    if ( v12 != v9 )
    {
      v13 = 8i64 * v12;
      if ( !is_mul_ok(v12, 8ui64) )
        v13 = -1i64;
      v14 = UFG::qMalloc(v13, "qArray.Insert", 0i64);
      v15 = (UFG::CoverObjectBase **)v14;
      if ( this->m_aChildObjects.p )
      {
        if ( this->m_aChildObjects.size )
        {
          do
          {
            v16 = v6;
            v6 = (unsigned int)(v6 + 1);
            v14[v16] = (UFG::allocator::free_link)this->m_aChildObjects.p[v16];
          }
          while ( (unsigned int)v6 < this->m_aChildObjects.size );
        }
        operator delete[](this->m_aChildObjects.p);
      }
      this->m_aChildObjects.p = v15;
      this->m_aChildObjects.capacity = v12;
    }
  }
  v17 = v11 - 1;
  this->m_aChildObjects.size = v11;
  if ( (unsigned int)v17 > size )
  {
    v18 = v17;
    do
    {
      v17 = (unsigned int)(v17 - 1);
      this->m_aChildObjects.p[v18--] = this->m_aChildObjects.p[v17];
    }
    while ( (unsigned int)v17 > size );
  }
  this->m_aChildObjects.p[size] = pCoverObject;
}

// File Line: 92
// RVA: 0x3407E0
void __fastcall UFG::CoverObjectGroup::AddGroup(UFG::CoverObjectGroup *this, UFG::CoverObjectBase *pGroupObject)
{
  __int64 i; // r12
  __int64 v5; // rcx
  UFG::CoverObjectBase *v6; // r14
  UFG::CoverObjectBaseVtbl *vfptr; // rax
  unsigned int size; // r15d
  __int64 v9; // rdi
  UFG::CoverObjectBase *v10; // rsi
  unsigned int v11; // ecx
  unsigned int capacity; // edi
  unsigned int v13; // esi
  unsigned int v14; // edi
  unsigned __int64 v15; // rax
  UFG::allocator::free_link *v16; // rax
  UFG::CoverObjectBase **v17; // rbp
  __int64 j; // r9
  __int64 v19; // r8
  __int64 v20; // r8
  __int64 v21; // r9

  for ( i = 0i64; (unsigned int)i < LODWORD(pGroupObject[1].vfptr); i = (unsigned int)(i + 1) )
  {
    v5 = *(_QWORD *)(8 * i + *(_QWORD *)&pGroupObject[1].m_iRefCount);
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 16i64))(v5) )
    {
      v6 = *(UFG::CoverObjectBase **)(8 * i + *(_QWORD *)&pGroupObject[1].m_iRefCount);
      vfptr = v6->vfptr;
      ++v6->m_iRefCount;
      vfptr->SetCoverObjectGroup(v6, this);
      size = this->m_aChildObjects.size;
      if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v6->vfptr->__vecDelDtor + 2))(v6) )
      {
        v9 = 0i64;
        if ( this->m_aChildObjects.size )
        {
          while ( 1 )
          {
            v10 = this->m_aChildObjects.p[v9];
            if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v10->vfptr->__vecDelDtor + 2))(v10) )
            {
              if ( v6->vfptr->IsConnectedTo(v6, v10) && v6->vfptr->IsLeftOf(v6, v10) )
                break;
            }
            v9 = (unsigned int)(v9 + 1);
            if ( (unsigned int)v9 >= this->m_aChildObjects.size )
              goto LABEL_11;
          }
          size = v9;
        }
      }
LABEL_11:
      v11 = this->m_aChildObjects.size;
      capacity = this->m_aChildObjects.capacity;
      v13 = v11 + 1;
      if ( v11 + 1 > capacity )
      {
        if ( capacity )
          v14 = 2 * capacity;
        else
          v14 = 1;
        for ( ; v14 < v13; v14 *= 2 )
          ;
        if ( v14 <= 2 )
          v14 = 2;
        if ( v14 - v13 > 0x10000 )
          v14 = v11 + 65537;
        if ( v14 != v11 )
        {
          v15 = 8i64 * v14;
          if ( !is_mul_ok(v14, 8ui64) )
            v15 = -1i64;
          v16 = UFG::qMalloc(v15, "qArray.Insert", 0i64);
          v17 = (UFG::CoverObjectBase **)v16;
          if ( this->m_aChildObjects.p )
          {
            for ( j = 0i64;
                  (unsigned int)j < this->m_aChildObjects.size;
                  v16[v19] = (UFG::allocator::free_link)this->m_aChildObjects.p[v19] )
            {
              v19 = j;
              j = (unsigned int)(j + 1);
            }
            operator delete[](this->m_aChildObjects.p);
          }
          this->m_aChildObjects.p = v17;
          this->m_aChildObjects.capacity = v14;
        }
      }
      v20 = v13 - 1;
      this->m_aChildObjects.size = v13;
      if ( (unsigned int)v20 > size )
      {
        v21 = v20;
        do
        {
          v20 = (unsigned int)(v20 - 1);
          this->m_aChildObjects.p[v21--] = this->m_aChildObjects.p[v20];
        }
        while ( (unsigned int)v20 > size );
      }
      this->m_aChildObjects.p[size] = v6;
    }
  }
}

// File Line: 107
// RVA: 0x35C110
UFG::CoverPosition *__fastcall UFG::CoverObjectGroup::GetCoverPosition(
        UFG::CoverObjectGroup *this,
        UFG::qVector3 *vCharPos,
        UFG::CoverPosition *pCurrentPosition,
        float fRange)
{
  float v6; // xmm6_4
  UFG::CoverPosition *result; // rax
  UFG::CoverPosition *v8; // rbx
  __int64 v9; // rsi
  UFG::CoverObjectBase **p; // rcx
  UFG::CoverObjectParkour *v11; // r14
  UFG::CoverObjectParkour *v12; // r15
  UFG::CoverPosition *InbetweenParkourPosition; // rax
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm0_4

  v6 = 0.0;
  result = UFG::CoverObjectGroup::GetCoverPositionExact(this, vCharPos);
  v8 = result;
  if ( !result || result->m_fDistToLeft == 0.0 && result->m_fDistToRight == 0.0 )
  {
    v9 = 0i64;
    if ( this->m_aChildObjects.size != 1 )
    {
      while ( 1 )
      {
        p = this->m_aChildObjects.p;
        v11 = (UFG::CoverObjectParkour *)p[v9];
        v9 = (unsigned int)(v9 + 1);
        v12 = (UFG::CoverObjectParkour *)p[(unsigned int)v9];
        if ( v11->vfptr->IsParkour(v11) )
        {
          v6 = v6 + (float)(UFG::ParkourHandle::GetHalfLength(v11->m_pParkourHandle.m_pPointer) * 2.0);
          if ( v12->vfptr->IsParkour(v12) )
          {
            InbetweenParkourPosition = UFG::CoverObjectGroup::GetInbetweenParkourPosition(this, v11, v12, vCharPos, v8);
            v8 = InbetweenParkourPosition;
            if ( InbetweenParkourPosition )
            {
              if ( InbetweenParkourPosition->m_bInbetweenParkourLine )
                break;
            }
          }
        }
        if ( (unsigned int)v9 >= this->m_aChildObjects.size - 1 )
          return v8;
      }
      v14 = InbetweenParkourPosition->vfptr->GetHeight(InbetweenParkourPosition);
      if ( v14 <= 0.5 || v14 >= 1.6 )
        v15 = UFG::CoverObjectBase::ms_fHighSideOffset;
      else
        v15 = UFG::CoverObjectBase::ms_fLowSideOffset;
      v16 = (float)(this->m_fTotalLength - v6) - v15;
      v8->m_fDistToLeft = v6 - v15;
      v8->m_fDistToRight = v16;
      return v8;
    }
  }
  return result;
}

// File Line: 160
// RVA: 0x35C850
UFG::CoverPosition *__fastcall UFG::CoverObjectGroup::GetCoverPositionExact(
        UFG::CoverObjectGroup *this,
        UFG::qVector3 *vCharPos)
{
  UFG::CoverPosition *v2; // rsi
  float v5; // xmm9_4
  unsigned int i; // ebp
  UFG::ParkourHandle **v7; // rdi
  __int64 v8; // rbx
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm0_4

  v2 = 0i64;
  v5 = 0.0;
  for ( i = 0; i < this->m_aChildObjects.size; ++i )
  {
    v7 = (UFG::ParkourHandle **)this->m_aChildObjects.p[i];
    if ( ((unsigned __int8 (__fastcall *)(UFG::ParkourHandle **))(*v7)->m_SafePointerList.mNode.mNext)(v7) )
    {
      v8 = ((__int64 (__fastcall *)(UFG::ParkourHandle **, UFG::qVector3 *, _QWORD))(*v7)->mCachedRightNeighbor.mNext)(
             v7,
             vCharPos,
             0i64);
      if ( !v8 )
        goto LABEL_19;
      if ( !((unsigned __int8 (__fastcall *)(UFG::ParkourHandle **))(*v7)->mSimObject.mNext)(v7) )
        goto LABEL_16;
      v9 = *(float *)(v8 + 200);
      v10 = (float)(UFG::ParkourHandle::GetHalfLength(*(UFG::ParkourHandle **)(v8 + 48)) + v9) + v5;
      v11 = this->m_fTotalLength - v10;
      if ( v10 >= v11 )
        v12 = this->m_fTotalLength - v10;
      else
        v12 = v10;
      if ( v12 >= 0.5
        || (float)((float)((float)(0.5 - v12) * (float)(0.5 - v12))
                 + (float)((float)(0.5 - COERCE_FLOAT(*(_DWORD *)(v8 + 204) & _xmm))
                         * (float)(0.5 - COERCE_FLOAT(*(_DWORD *)(v8 + 204) & _xmm)))) <= 0.25 )
      {
        v13 = (*(float (__fastcall **)(__int64))(*(_QWORD *)v8 + 224i64))(v8);
        if ( v13 <= 0.5 || v13 >= 1.6 )
          v14 = UFG::CoverObjectBase::ms_fHighSideOffset;
        else
          v14 = UFG::CoverObjectBase::ms_fLowSideOffset;
        *(float *)(v8 + 208) = v10 - v14;
        *(float *)(v8 + 212) = v11 - v14;
LABEL_16:
        if ( v2 )
        {
          UFG::CoverPosition::operator+=(v2, (UFG::CoverPosition *)v8);
          (**(void (__fastcall ***)(__int64, __int64))v8)(v8, 1i64);
        }
        else
        {
          v2 = (UFG::CoverPosition *)v8;
        }
LABEL_19:
        if ( ((unsigned __int8 (__fastcall *)(UFG::ParkourHandle **))(*v7)->mSimObject.mNext)(v7) )
          v5 = v5 + (float)(UFG::ParkourHandle::GetHalfLength(v7[6]) * 2.0);
        continue;
      }
      (**(void (__fastcall ***)(__int64, __int64))v8)(v8, 1i64);
    }
  }
  return v2;
}

// File Line: 231
// RVA: 0x360250
UFG::CoverPosition *__fastcall UFG::CoverObjectGroup::GetInbetweenParkourPosition(
        UFG::CoverObjectGroup *this,
        UFG::CoverObjectParkour *pLeftChild,
        UFG::CoverObjectParkour *pRightChild,
        UFG::qVector3 *vCharPos)
{
  UFG::ParkourHandle *m_pPointer; // rsi
  UFG::ParkourHandle *v8; // r14
  float v9; // xmm14_4
  float v10; // xmm15_4
  float z; // xmm1_4
  float v12; // xmm11_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm10_4
  float v16; // xmm9_4
  __m128 x_low; // xmm8
  __m128 v18; // xmm3
  float v19; // xmm1_4
  float v20; // xmm10_4
  float v21; // xmm9_4
  float v22; // xmm8_4
  float v23; // xmm3_4
  float v24; // xmm11_4
  float v25; // xmm7_4
  __m128 v26; // xmm6
  __m128 v27; // xmm3
  float v28; // xmm2_4
  float v29; // xmm11_4
  float v30; // xmm7_4
  float v31; // xmm6_4
  float v32; // xmm1_4
  UFG::CoverPosition *v33; // rbx
  UFG::allocator::free_link *v34; // rax
  UFG::CoverPosition *v35; // rax
  float v37; // [rsp+20h] [rbp-B8h]
  UFG::qVector3 v38; // [rsp+28h] [rbp-B0h] BYREF
  UFG::qVector3 result; // [rsp+38h] [rbp-A0h] BYREF
  UFG::qVector3 out; // [rsp+48h] [rbp-90h] BYREF
  UFG::qVector3 v41; // [rsp+58h] [rbp-80h] BYREF
  UFG::qVector3 v42; // [rsp+64h] [rbp-74h] BYREF
  __int64 v43; // [rsp+70h] [rbp-68h] BYREF
  float p1_4; // [rsp+78h] [rbp-60h]
  float p1_8; // [rsp+7Ch] [rbp-5Ch]
  float v46; // [rsp+150h] [rbp+78h]
  float v47; // [rsp+158h] [rbp+80h]
  UFG::allocator::free_link *vars0; // [rsp+160h] [rbp+88h]
  UFG::CoverPosition *retaddr; // [rsp+168h] [rbp+90h]

  v43 = -2i64;
  m_pPointer = pLeftChild->m_pParkourHandle.m_pPointer;
  v8 = pRightChild->m_pParkourHandle.m_pPointer;
  UFG::ParkourHandle::GetAxis(m_pPointer, &result);
  UFG::ParkourHandle::GetAxis(v8, &v38);
  UFG::ParkourHandle::GetEndpoints(m_pPointer, (UFG::qVector3 *)&v42.y, (UFG::qVector3 *)((char *)&v43 + 4));
  UFG::ParkourHandle::GetEndpoints(v8, &v41, &v42);
  v9 = (float)(p1_8 + v41.z) * 0.5;
  v46 = (float)(p1_4 + v41.y) * 0.5;
  v10 = (float)(*((float *)&v43 + 1) + v41.x) * 0.5;
  v47 = (float)(pRightChild->m_fParkourSyncZOffset + pLeftChild->m_fParkourSyncZOffset) * 0.5;
  z = vCharPos->z;
  v12 = z - v9;
  v13 = vCharPos->y - v46;
  v37 = v13;
  v14 = vCharPos->x - v10;
  *(float *)&vars0 = v14;
  if ( (float)((float)(v9 + v47) - z) >= kfMaxHeightDiff_1 )
    return retaddr;
  UFG::ParkourHandle::GetNormal(m_pPointer, &out);
  UFG::ParkourHandle::GetNormal(v8, &v41);
  v15 = out.z + v41.z;
  v16 = out.y + v41.y;
  x_low = (__m128)LODWORD(out.x);
  x_low.m128_f32[0] = out.x + v41.x;
  v18 = x_low;
  v18.m128_f32[0] = (float)((float)(x_low.m128_f32[0] * x_low.m128_f32[0]) + (float)(v16 * v16)) + (float)(v15 * v15);
  v19 = v18.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v18).m128_f32[0];
  v20 = v15 * v19;
  v21 = v16 * v19;
  v22 = x_low.m128_f32[0] * v19;
  v23 = (float)((float)(v22 * v14) + (float)(v21 * v13)) + (float)(v20 * v12);
  if ( v23 <= 0.0 || v23 >= 1.0 )
    return retaddr;
  v24 = result.z + v38.z;
  v25 = result.y + v38.y;
  v26 = (__m128)LODWORD(result.x);
  v26.m128_f32[0] = result.x + v38.x;
  v27 = v26;
  v27.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v24 * v24);
  v28 = v27.m128_f32[0] == 0.0 ? 0.0 : 1.0 / _mm_sqrt_ps(v27).m128_f32[0];
  v29 = v24 * v28;
  v30 = v25 * v28;
  v31 = v26.m128_f32[0] * v28;
  v32 = (float)(v31 * *(float *)&vars0) + (float)(v30 * v37);
  if ( v32 <= -0.5
    || v32 >= 0.5
    || (float)((float)((float)(*((float *)&v43 + 1) - vCharPos->x) * result.x)
             + (float)(result.y * (float)(p1_4 - vCharPos->y))) > 0.0
    || (float)((float)((float)(v41.x - vCharPos->x) * v38.x) + (float)(v38.y * (float)(v41.y - vCharPos->y))) < 0.0 )
  {
    return retaddr;
  }
  v33 = retaddr;
  if ( !retaddr )
  {
    v34 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
    vars0 = v34;
    if ( v34 )
    {
      UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v34);
      v33 = v35;
    }
    else
    {
      v33 = 0i64;
    }
  }
  v33->m_bInbetweenParkourLine = 1;
  v33->m_vInbetweenParkourPosition.x = v10;
  v33->m_vInbetweenParkourPosition.y = v46;
  v33->m_vInbetweenParkourPosition.z = v9;
  v33->m_vInbetweenParkourNormal.x = v22;
  v33->m_vInbetweenParkourNormal.y = v21;
  v33->m_vInbetweenParkourNormal.z = v20;
  v33->m_vInbetweenParkourAxis.x = v31;
  v33->m_vInbetweenParkourAxis.y = v30;
  v33->m_vInbetweenParkourAxis.z = v29;
  v33->m_fParkourSyncZOffset = v47;
  v33->m_bFoundParkourSync = 1;
  UFG::CoverPosition::SetParkourHandle(v33, m_pPointer);
  return v33;
}

// File Line: 359
// RVA: 0x35CDD0
bool __fastcall UFG::CoverObjectGroup::GetCoverPositions(
        UFG::CoverObjectGroup *this,
        UFG::qArray<UFG::CoverPosition *,0> *aCoverPositions)
{
  UFG::CoverObjectGroup *v3; // r14
  float m_fTotalLength; // xmm11_4
  float v5; // xmm0_4
  int v6; // ebx
  float v7; // xmm11_4
  int v8; // ebp
  float v9; // xmm9_4
  UFG::CoverObjectBase *v10; // rcx
  UFG::CoverObjectBase *v11; // r13
  float v12; // xmm7_4
  int v13; // eax
  float v14; // xmm6_4
  UFG::CoverObjectBase *v15; // rcx
  float v16; // xmm8_4
  UFG::allocator::free_link *v17; // rax
  UFG::CoverPosition *v18; // rax
  UFG::CoverPosition *v19; // r15
  float v20; // xmm0_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  float v23; // xmm0_4
  __int64 size; // r12
  unsigned int v25; // esi
  unsigned int capacity; // ebx
  unsigned int v27; // ebx
  unsigned __int64 v28; // rax
  UFG::CoverPosition **v29; // r14
  unsigned int i; // r9d
  unsigned int v31; // r12d
  UFG::CoverObjectBase *v32; // r14
  int v33; // esi
  UFG::CoverPosition *v34; // r15
  UFG::CoverObjectBaseVtbl *vfptr; // rbx
  __int64 v36; // rax
  __int64 v37; // rax
  __int64 v38; // rcx
  int v39; // eax
  __int64 v40; // rdx
  UFG::CoverCorner *v41; // rdx
  __int64 v42; // rax
  __int64 v43; // rcx
  __int64 v44; // rcx
  UFG::allocator::free_link *v45; // rcx
  __int64 v46; // rdx
  UFG::CoverCorner *v47; // rdx
  __int64 v48; // rax
  __int64 v49; // rdx
  __int64 v50; // r8
  UFG::CoverPosition *v51; // rax
  UFG::CoverPosition *v52; // r15
  __int64 v53; // rbp
  unsigned int v54; // esi
  unsigned int v55; // ebx
  unsigned int v56; // ebx
  unsigned __int64 v57; // rax
  UFG::allocator::free_link *v58; // rax
  UFG::CoverPosition **v59; // r14
  unsigned int j; // r9d
  char v62; // [rsp+28h] [rbp-F0h] BYREF
  int v64; // [rsp+128h] [rbp+10h]
  int v65; // [rsp+130h] [rbp+18h]

  v3 = this;
  m_fTotalLength = this->m_fTotalLength;
  if ( m_fTotalLength > 0.5 )
  {
    v5 = *(float *)&FLOAT_1_0;
    if ( (float)(int)(float)(m_fTotalLength * 1.0526316) >= 1.0 )
      v5 = (float)(int)(float)(m_fTotalLength * 1.0526316);
    v6 = (int)v5;
    v65 = (int)v5;
    v7 = m_fTotalLength / (float)(int)v5;
    v8 = 0;
    v9 = 0.0;
    if ( !(*(unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))(**(_QWORD **)this->m_aChildObjects.p + 48i64))(*this->m_aChildObjects.p) )
    {
      do
        v10 = v3->m_aChildObjects.p[++v8];
      while ( !v10->vfptr->IsParkour(v10) );
    }
    v11 = v3->m_aChildObjects.p[v8];
    v12 = UFG::ParkourHandle::GetHalfLength((UFG::ParkourHandle *)v11[1].m_pCoverObjectGroup) * 2.0;
    v13 = 0;
    v64 = 0;
    if ( v6 > 0 )
    {
      do
      {
        v14 = (float)((float)v13 * v7) + (float)(v7 * 0.5);
        while ( v14 > v12 )
        {
          v15 = v3->m_aChildObjects.p[++v8];
          if ( v15->vfptr->IsParkour(v15) )
          {
            v11 = v3->m_aChildObjects.p[v8];
            v9 = v12;
            v12 = v12
                + (float)(UFG::ParkourHandle::GetHalfLength((UFG::ParkourHandle *)v11[1].m_pCoverObjectGroup) * 2.0);
          }
        }
        v16 = (float)(v14 - v9) - UFG::ParkourHandle::GetHalfLength((UFG::ParkourHandle *)v11[1].m_pCoverObjectGroup);
        v17 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
        if ( v17 )
        {
          UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v17, (UFG::ParkourHandle *)v11[1].m_pCoverObjectGroup);
          v19 = v18;
        }
        else
        {
          v19 = 0i64;
        }
        v19->m_fParkourTVal = v16;
        v20 = *(&v11[1].m_fPriority + 1);
        v19->m_bFoundParkourSync = 1;
        v19->m_fParkourSyncZOffset = v20;
        v21 = v19->vfptr->GetHeight(v19);
        if ( v21 <= 0.5 || v21 >= 1.6 )
          v22 = UFG::CoverObjectBase::ms_fHighSideOffset;
        else
          v22 = UFG::CoverObjectBase::ms_fLowSideOffset;
        v23 = (float)(v3->m_fTotalLength - v14) - v22;
        v19->m_fDistToLeft = v14 - v22;
        v19->m_fDistToRight = v23;
        size = aCoverPositions->size;
        v25 = size + 1;
        capacity = aCoverPositions->capacity;
        if ( (int)size + 1 > capacity )
        {
          if ( capacity )
            v27 = 2 * capacity;
          else
            v27 = 1;
          for ( ; v27 < v25; v27 *= 2 )
            ;
          if ( v27 <= 2 )
            v27 = 2;
          if ( v27 - v25 > 0x10000 )
            v27 = size + 65537;
          if ( v27 != (_DWORD)size )
          {
            v28 = 8i64 * v27;
            if ( !is_mul_ok(v27, 8ui64) )
              v28 = -1i64;
            v29 = (UFG::CoverPosition **)UFG::qMalloc(v28, "qArray.Add", 0i64);
            if ( aCoverPositions->p )
            {
              for ( i = 0; i < aCoverPositions->size; ++i )
                v29[i] = aCoverPositions->p[i];
              operator delete[](aCoverPositions->p);
            }
            aCoverPositions->p = v29;
            aCoverPositions->capacity = v27;
            v3 = this;
          }
        }
        aCoverPositions->size = v25;
        aCoverPositions->p[size] = v19;
        v13 = v64 + 1;
        v64 = v13;
      }
      while ( v13 < v65 );
    }
  }
  v31 = 0;
  if ( v3->m_aChildObjects.size )
  {
    do
    {
      v32 = v3->m_aChildObjects.p[v31];
      if ( v32->vfptr->IsCorner(v32) )
      {
        v33 = 0;
        if ( aCoverPositions->size )
        {
          while ( 1 )
          {
            v34 = aCoverPositions->p[v33];
            vfptr = v32->vfptr;
            v36 = (__int64)v34->vfptr->GetSyncPos(v34, (UFG::qVector3 *)&v62);
            v37 = ((__int64 (__fastcall *)(UFG::CoverObjectBase *, __int64, _QWORD))vfptr->GetCoverPosition)(
                    v32,
                    v36,
                    0i64);
            v38 = v37;
            if ( v37 )
              break;
            if ( ++v33 >= aCoverPositions->size )
              goto LABEL_56;
          }
          v39 = *(_DWORD *)(v37 + 8);
          *(_DWORD *)(v38 + 8) = v39;
          if ( !v39 )
            (**(void (__fastcall ***)(__int64, __int64))v38)(v38, 1i64);
          v40 = *(_QWORD *)&v32[2].m_fPriority;
          if ( v40 )
          {
            v41 = (UFG::CoverCorner *)(v40 + 24);
          }
          else
          {
            v42 = *(_QWORD *)&v32[1].m_fPriority;
            if ( v42 )
            {
              v43 = *(_QWORD *)(v42 + 96);
              if ( v43 )
                v44 = v42 + v43 + 96;
              else
                v44 = 0i64;
              v41 = (UFG::CoverCorner *)(v44 + 48i64 * LOWORD(v32[1].vfptr));
            }
            else
            {
              v41 = 0i64;
            }
          }
          if ( v41->m_eCoverSide.mValue == 1 )
            UFG::CoverCornerHandle::operator=(&v34->m_RightCorner, v41);
          else
            UFG::CoverCornerHandle::operator=(&v34->m_LeftCorner, v41);
        }
        else
        {
LABEL_56:
          v45 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
          if ( v45 )
          {
            v46 = *(_QWORD *)&v32[2].m_fPriority;
            if ( v46 )
            {
              v47 = (UFG::CoverCorner *)(v46 + 24);
            }
            else
            {
              v48 = *(_QWORD *)&v32[1].m_fPriority;
              if ( v48 )
              {
                v49 = *(_QWORD *)(v48 + 96);
                if ( v49 )
                  v50 = v48 + v49 + 96;
                else
                  v50 = 0i64;
                v47 = (UFG::CoverCorner *)(v50 + 48i64 * LOWORD(v32[1].vfptr));
              }
              else
              {
                v47 = 0i64;
              }
            }
            UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v45, v47);
            v52 = v51;
          }
          else
          {
            v52 = 0i64;
          }
          v53 = aCoverPositions->size;
          v54 = v53 + 1;
          v55 = aCoverPositions->capacity;
          if ( (int)v53 + 1 > v55 )
          {
            if ( v55 )
              v56 = 2 * v55;
            else
              v56 = 1;
            for ( ; v56 < v54; v56 *= 2 )
              ;
            if ( v56 <= 2 )
              v56 = 2;
            if ( v56 - v54 > 0x10000 )
              v56 = v53 + 65537;
            if ( v56 != (_DWORD)v53 )
            {
              v57 = 8i64 * v56;
              if ( !is_mul_ok(v56, 8ui64) )
                v57 = -1i64;
              v58 = UFG::qMalloc(v57, "qArray.Add", 0i64);
              v59 = (UFG::CoverPosition **)v58;
              if ( aCoverPositions->p )
              {
                for ( j = 0; j < aCoverPositions->size; ++j )
                  v58[j] = (UFG::allocator::free_link)aCoverPositions->p[j];
                operator delete[](aCoverPositions->p);
              }
              aCoverPositions->p = v59;
              aCoverPositions->capacity = v56;
            }
          }
          aCoverPositions->size = v54;
          aCoverPositions->p[v53] = v52;
        }
      }
      ++v31;
      v3 = this;
    }
    while ( v31 < this->m_aChildObjects.size );
  }
  return aCoverPositions->size != 0;
}

// File Line: 457
// RVA: 0x398FE0
void __fastcall UFG::CoverObjectGroup::UpdateTransforms(UFG::CoverObjectGroup *this)
{
  __int64 i; // rbx
  UFG::CoverObjectBase *v3; // rcx

  for ( i = 0i64; (unsigned int)i < this->m_aChildObjects.size; i = (unsigned int)(i + 1) )
  {
    v3 = this->m_aChildObjects.p[i];
    v3->vfptr->UpdateTransforms(v3);
  }
}

