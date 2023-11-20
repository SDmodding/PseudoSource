// File Line: 20
// RVA: 0x335DD0
void __fastcall UFG::CoverObjectGroup::~CoverObjectGroup(UFG::CoverObjectGroup *this)
{
  UFG::CoverObjectGroup *v1; // rbx
  signed __int64 v2; // rdi
  signed __int64 v3; // rsi
  UFG::CoverObjectBase *v4; // rcx
  UFG::CoverObjectBase *v5; // rcx
  bool v6; // zf
  UFG::CoverObjectBase **v7; // rcx

  v1 = this;
  this->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectGroup::`vftable;
  v2 = 0i64;
  if ( this->m_aChildObjects.size )
  {
    do
    {
      v3 = v2;
      v4 = v1->m_aChildObjects.p[v2];
      if ( (UFG::CoverObjectGroup *)((__int64 (__cdecl *)(UFG::CoverObjectBase *))v4->vfptr->GetCoverObjectGroup)(v4) == v1 )
        v1->m_aChildObjects.p[v3]->vfptr->SetCoverObjectGroup(v1->m_aChildObjects.p[v3], 0i64);
      v5 = v1->m_aChildObjects.p[v3];
      v6 = v5->m_iRefCount-- == 1;
      if ( v6 )
        v5->vfptr->__vecDelDtor(v5, 1u);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->m_aChildObjects.size );
  }
  v7 = v1->m_aChildObjects.p;
  if ( v7 )
    operator delete[](v7);
  v1->m_aChildObjects.p = 0i64;
  *(_QWORD *)&v1->m_aChildObjects.size = 0i64;
  v1->vfptr = (UFG::CoverObjectBaseVtbl *)&UFG::CoverObjectBase::`vftable;
}

// File Line: 33
// RVA: 0x36BF60
char __fastcall UFG::CoverObjectGroup::IsValid(UFG::CoverObjectGroup *this)
{
  unsigned int v1; // eax
  UFG::CoverObjectGroup *v2; // rdi
  __int64 v4; // rbx

  v1 = this->m_aChildObjects.size;
  v2 = this;
  if ( v1 < 2 )
    return 0;
  v4 = 0i64;
  if ( !v1 )
    return 1;
  while ( (*((unsigned __int8 (**)(void))&v2->m_aChildObjects.p[v4]->vfptr->__vecDelDtor + 2))() )
  {
    v4 = (unsigned int)(v4 + 1);
    if ( (unsigned int)v4 >= v2->m_aChildObjects.size )
      return 1;
  }
  return 0;
}

// File Line: 57
// RVA: 0x3409E0
void __fastcall UFG::CoverObjectGroup::AddObject(UFG::CoverObjectGroup *this, UFG::CoverObjectBase *pCoverObject)
{
  UFG::CoverObjectBaseVtbl *v2; // rax
  UFG::CoverObjectBase *v3; // r14
  UFG::CoverObjectGroup *v4; // rbx
  unsigned int v5; // er12
  signed __int64 v6; // rbp
  unsigned int v7; // edi
  UFG::CoverObjectBase *v8; // rsi
  unsigned int v9; // ecx
  unsigned int v10; // edi
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned __int64 v13; // rax
  UFG::allocator::free_link *v14; // rax
  UFG::CoverObjectBase **v15; // r15
  signed __int64 v16; // r8
  signed __int64 v17; // r8
  signed __int64 v18; // r9

  v2 = pCoverObject->vfptr;
  ++pCoverObject->m_iRefCount;
  v3 = pCoverObject;
  v4 = this;
  v2->SetCoverObjectGroup(pCoverObject, this);
  v5 = v4->m_aChildObjects.size;
  v6 = 0i64;
  if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v3->vfptr->__vecDelDtor + 2))(v3) )
  {
    v7 = 0;
    if ( v4->m_aChildObjects.size > 0 )
    {
      while ( 1 )
      {
        v8 = v4->m_aChildObjects.p[v7];
        if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v8->vfptr->__vecDelDtor + 2))(v8) )
        {
          if ( v3->vfptr->IsConnectedTo(v3, v8) && v3->vfptr->IsLeftOf(v3, v8) )
            break;
        }
        if ( ++v7 >= v4->m_aChildObjects.size )
          goto LABEL_9;
      }
      v5 = v7;
    }
  }
LABEL_9:
  v9 = v4->m_aChildObjects.size;
  v10 = v4->m_aChildObjects.capacity;
  v11 = v9 + 1;
  if ( v9 + 1 > v10 )
  {
    if ( v10 )
      v12 = 2 * v10;
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
      if ( v4->m_aChildObjects.p )
      {
        if ( v4->m_aChildObjects.size > 0 )
        {
          do
          {
            v16 = v6;
            v6 = (unsigned int)(v6 + 1);
            v14[v16] = (UFG::allocator::free_link)v4->m_aChildObjects.p[v16];
          }
          while ( (unsigned int)v6 < v4->m_aChildObjects.size );
        }
        operator delete[](v4->m_aChildObjects.p);
      }
      v4->m_aChildObjects.p = v15;
      v4->m_aChildObjects.capacity = v12;
    }
  }
  v17 = v11 - 1;
  v4->m_aChildObjects.size = v11;
  if ( (unsigned int)v17 > v5 )
  {
    v18 = v17;
    do
    {
      v17 = (unsigned int)(v17 - 1);
      --v18;
      v4->m_aChildObjects.p[v18 + 1] = v4->m_aChildObjects.p[v17];
    }
    while ( (unsigned int)v17 > v5 );
  }
  v4->m_aChildObjects.p[v5] = v3;
}

// File Line: 92
// RVA: 0x3407E0
void __fastcall UFG::CoverObjectGroup::AddGroup(UFG::CoverObjectGroup *this, UFG::CoverObjectBase *pGroupObject)
{
  __int64 v2; // r12
  UFG::CoverObjectBase *v3; // r13
  UFG::CoverObjectGroup *v4; // rbx
  UFG::CoverObjectBase *v5; // r14
  UFG::CoverObjectBaseVtbl *v6; // rax
  unsigned int v7; // er15
  __int64 v8; // rdi
  UFG::CoverObjectBase *v9; // rsi
  unsigned int v10; // ecx
  unsigned int v11; // edi
  unsigned int v12; // esi
  unsigned int v13; // edi
  unsigned __int64 v14; // rax
  UFG::allocator::free_link *v15; // rax
  UFG::CoverObjectBase **v16; // rbp
  signed __int64 v17; // r9
  signed __int64 v18; // r8
  signed __int64 v19; // r8
  signed __int64 v20; // r9

  v2 = 0i64;
  v3 = pGroupObject;
  v4 = this;
  if ( LODWORD(pGroupObject[1].vfptr) )
  {
    do
    {
      if ( (*(unsigned __int8 (**)(void))(**(_QWORD **)(8 * v2 + *(_QWORD *)&v3[1].m_iRefCount) + 16i64))() )
      {
        v5 = *(UFG::CoverObjectBase **)(8 * v2 + *(_QWORD *)&v3[1].m_iRefCount);
        v6 = v5->vfptr;
        ++v5->m_iRefCount;
        v6->SetCoverObjectGroup(v5, v4);
        v7 = v4->m_aChildObjects.size;
        if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v5->vfptr->__vecDelDtor + 2))(v5) )
        {
          v8 = 0i64;
          if ( v4->m_aChildObjects.size )
          {
            while ( 1 )
            {
              v9 = v4->m_aChildObjects.p[v8];
              if ( (*((unsigned __int8 (__fastcall **)(UFG::CoverObjectBase *))&v9->vfptr->__vecDelDtor + 2))(v9) )
              {
                if ( v5->vfptr->IsConnectedTo(v5, v9) && v5->vfptr->IsLeftOf(v5, v9) )
                  break;
              }
              v8 = (unsigned int)(v8 + 1);
              if ( (unsigned int)v8 >= v4->m_aChildObjects.size )
                goto LABEL_11;
            }
            v7 = v8;
          }
        }
LABEL_11:
        v10 = v4->m_aChildObjects.size;
        v11 = v4->m_aChildObjects.capacity;
        v12 = v10 + 1;
        if ( v10 + 1 > v11 )
        {
          if ( v11 )
            v13 = 2 * v11;
          else
            v13 = 1;
          for ( ; v13 < v12; v13 *= 2 )
            ;
          if ( v13 <= 2 )
            v13 = 2;
          if ( v13 - v12 > 0x10000 )
            v13 = v10 + 65537;
          if ( v13 != v10 )
          {
            v14 = 8i64 * v13;
            if ( !is_mul_ok(v13, 8ui64) )
              v14 = -1i64;
            v15 = UFG::qMalloc(v14, "qArray.Insert", 0i64);
            v16 = (UFG::CoverObjectBase **)v15;
            if ( v4->m_aChildObjects.p )
            {
              v17 = 0i64;
              if ( v4->m_aChildObjects.size )
              {
                do
                {
                  v18 = v17;
                  v17 = (unsigned int)(v17 + 1);
                  v15[v18] = (UFG::allocator::free_link)v4->m_aChildObjects.p[v18];
                }
                while ( (unsigned int)v17 < v4->m_aChildObjects.size );
              }
              operator delete[](v4->m_aChildObjects.p);
            }
            v4->m_aChildObjects.p = v16;
            v4->m_aChildObjects.capacity = v13;
          }
        }
        v19 = v12 - 1;
        v4->m_aChildObjects.size = v12;
        if ( (unsigned int)v19 > v7 )
        {
          v20 = v19;
          do
          {
            v19 = (unsigned int)(v19 - 1);
            --v20;
            v4->m_aChildObjects.p[v20 + 1] = v4->m_aChildObjects.p[v19];
          }
          while ( (unsigned int)v19 > v7 );
        }
        v4->m_aChildObjects.p[v7] = v5;
      }
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < LODWORD(v3[1].vfptr) );
  }
}

// File Line: 107
// RVA: 0x35C110
UFG::CoverPosition *__fastcall UFG::CoverObjectGroup::GetCoverPosition(UFG::CoverObjectGroup *this, UFG::qVector3 *vCharPos, UFG::CoverPosition *pCurrentPosition, float fRange)
{
  UFG::qVector3 *v4; // rbp
  UFG::CoverObjectGroup *v5; // rdi
  float v6; // xmm6_4
  UFG::CoverPosition *result; // rax
  UFG::CoverPosition *v8; // rbx
  __int64 v9; // rsi
  UFG::CoverObjectBase **v10; // rcx
  UFG::CoverObjectParkour *v11; // r14
  UFG::CoverObjectParkour *v12; // r15
  float v13; // xmm0_4
  UFG::CoverPosition *v14; // rax
  float v15; // xmm1_4
  float v16; // xmm0_4

  v4 = vCharPos;
  v5 = this;
  v6 = 0.0;
  result = UFG::CoverObjectGroup::GetCoverPositionExact(this, vCharPos);
  v8 = result;
  if ( !result || 0.0 == result->m_fDistToLeft && 0.0 == result->m_fDistToRight )
  {
    v9 = 0i64;
    if ( v5->m_aChildObjects.size != 1 )
    {
      while ( 1 )
      {
        v10 = v5->m_aChildObjects.p;
        v11 = (UFG::CoverObjectParkour *)v10[v9];
        v9 = (unsigned int)(v9 + 1);
        v12 = (UFG::CoverObjectParkour *)v10[(unsigned int)v9];
        if ( v11->vfptr->IsParkour((UFG::CoverObjectBase *)&v11->vfptr) )
        {
          v13 = UFG::ParkourHandle::GetHalfLength(v11->m_pParkourHandle.m_pPointer) * 2.0;
          v6 = v6 + v13;
          if ( v12->vfptr->IsParkour((UFG::CoverObjectBase *)&v12->vfptr) )
          {
            v14 = UFG::CoverObjectGroup::GetInbetweenParkourPosition(v5, v11, v12, v4, v8);
            v8 = v14;
            if ( v14 )
            {
              if ( v14->m_bInbetweenParkourLine )
                break;
            }
          }
        }
        if ( (unsigned int)v9 >= v5->m_aChildObjects.size - 1 )
          goto LABEL_16;
      }
      v14->vfptr->GetHeight((UFG::CoverObjectBase *)&v14->vfptr);
      if ( v13 <= 0.5 || v13 >= 1.6 )
        v15 = UFG::CoverObjectBase::ms_fHighSideOffset;
      else
        v15 = UFG::CoverObjectBase::ms_fLowSideOffset;
      v16 = (float)(v5->m_fTotalLength - v6) - v15;
      v8->m_fDistToLeft = v6 - v15;
      v8->m_fDistToRight = v16;
LABEL_16:
      result = v8;
    }
  }
  return result;
}

// File Line: 160
// RVA: 0x35C850
UFG::CoverPosition *__fastcall UFG::CoverObjectGroup::GetCoverPositionExact(UFG::CoverObjectGroup *this, UFG::qVector3 *vCharPos)
{
  UFG::CoverPosition *v2; // rsi
  UFG::qVector3 *v3; // r15
  UFG::CoverObjectGroup *v4; // r14
  float v5; // xmm9_4
  unsigned int v6; // ebp
  UFG::ParkourHandle **v7; // rdi
  __int64 v8; // rbx
  float v9; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  float v13; // xmm2_4
  float v14; // xmm0_4

  v2 = 0i64;
  v3 = vCharPos;
  v4 = this;
  v5 = 0.0;
  v6 = 0;
  if ( this->m_aChildObjects.size )
  {
    do
    {
      v7 = (UFG::ParkourHandle **)v4->m_aChildObjects.p[v6];
      if ( ((unsigned __int8 (__fastcall *)(UFG::ParkourHandle **))(*v7)->m_SafePointerList.mNode.mNext)(v7) )
      {
        v8 = ((__int64 (__fastcall *)(UFG::ParkourHandle **, UFG::qVector3 *, _QWORD))(*v7)->mCachedRightNeighbor.mNext)(
               v7,
               v3,
               0i64);
        if ( !v8 )
          goto LABEL_19;
        if ( !((unsigned __int8 (__fastcall *)(UFG::ParkourHandle **))(*v7)->mSimObject.mNext)(v7) )
          goto LABEL_16;
        v9 = *(float *)(v8 + 200);
        v10 = (float)(UFG::ParkourHandle::GetHalfLength(*(UFG::ParkourHandle **)(v8 + 48)) + v9) + v5;
        v11 = v4->m_fTotalLength - v10;
        if ( v10 >= v11 )
          v12 = v4->m_fTotalLength - v10;
        else
          v12 = v10;
        if ( v12 >= 0.5
          || (v13 = 0.5 - v12,
              LODWORD(v12) = *(_DWORD *)(v8 + 204) & _xmm,
              (float)((float)(v13 * v13) + (float)((float)(0.5 - v12) * (float)(0.5 - v12))) <= 0.25) )
        {
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 224i64))(v8);
          if ( v12 <= 0.5 || v12 >= 1.6 )
            v14 = UFG::CoverObjectBase::ms_fHighSideOffset;
          else
            v14 = UFG::CoverObjectBase::ms_fLowSideOffset;
          *(float *)(v8 + 208) = v10 - v14;
          *(float *)(v8 + 212) = v11 - v14;
LABEL_16:
          if ( v2 )
          {
            UFG::CoverPosition::operator+=(v2, (UFG::CoverPosition *)v8);
            (**(void (__fastcall ***)(__int64, signed __int64))v8)(v8, 1i64);
          }
          else
          {
            v2 = (UFG::CoverPosition *)v8;
          }
LABEL_19:
          if ( ((unsigned __int8 (__fastcall *)(UFG::ParkourHandle **))(*v7)->mSimObject.mNext)(v7) )
            v5 = v5 + (float)(UFG::ParkourHandle::GetHalfLength(v7[6]) * 2.0);
          goto LABEL_21;
        }
        (**(void (__fastcall ***)(__int64, signed __int64))v8)(v8, 1i64);
      }
LABEL_21:
      ++v6;
    }
    while ( v6 < v4->m_aChildObjects.size );
  }
  return v2;
}

// File Line: 231
// RVA: 0x360250
UFG::CoverPosition *__fastcall UFG::CoverObjectGroup::GetInbetweenParkourPosition(UFG::CoverObjectGroup *this, UFG::CoverObjectParkour *pLeftChild, UFG::CoverObjectParkour *pRightChild, UFG::qVector3 *vCharPos)
{
  UFG::qVector3 *v4; // r15
  UFG::CoverObjectParkour *v5; // rdi
  UFG::CoverObjectParkour *v6; // rbx
  UFG::ParkourHandle *v7; // rsi
  UFG::ParkourHandle *v8; // r14
  float v9; // xmm14_4
  float v10; // xmm15_4
  float v11; // xmm1_4
  float v12; // xmm11_4
  float v13; // xmm6_4
  float v14; // xmm7_4
  float v15; // xmm10_4
  float v16; // xmm9_4
  __m128 v17; // xmm8
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
  UFG::qVector3 v38; // [rsp+28h] [rbp-B0h]
  UFG::qVector3 result; // [rsp+38h] [rbp-A0h]
  UFG::qVector3 out; // [rsp+48h] [rbp-90h]
  UFG::qVector3 v41; // [rsp+58h] [rbp-80h]
  UFG::qVector3 v42; // [rsp+64h] [rbp-74h]
  __int64 v43; // [rsp+70h] [rbp-68h]
  float v44; // [rsp+78h] [rbp-60h]
  float v45; // [rsp+7Ch] [rbp-5Ch]
  float v46; // [rsp+150h] [rbp+78h]
  float v47; // [rsp+158h] [rbp+80h]
  UFG::allocator::free_link *vars0; // [rsp+160h] [rbp+88h]
  UFG::CoverPosition *retaddr; // [rsp+168h] [rbp+90h]

  v43 = -2i64;
  v4 = vCharPos;
  v5 = pRightChild;
  v6 = pLeftChild;
  v7 = pLeftChild->m_pParkourHandle.m_pPointer;
  v8 = pRightChild->m_pParkourHandle.m_pPointer;
  UFG::ParkourHandle::GetAxis(v7, &result);
  UFG::ParkourHandle::GetAxis(v8, &v38);
  UFG::ParkourHandle::GetEndpoints(v7, (UFG::qVector3 *)((char *)&v42 + 4), (UFG::qVector3 *)((char *)&v43 + 4));
  UFG::ParkourHandle::GetEndpoints(v8, &v41, &v42);
  v9 = (float)(v45 + v41.z) * 0.5;
  v46 = (float)(v44 + v41.y) * 0.5;
  v10 = (float)(*((float *)&v43 + 1) + v41.x) * 0.5;
  v47 = (float)(v5->m_fParkourSyncZOffset + v6->m_fParkourSyncZOffset) * 0.5;
  v11 = v4->z;
  v12 = v4->z - v9;
  v13 = v4->y - v46;
  v37 = v4->y - v46;
  v14 = v4->x - v10;
  *(float *)&vars0 = v4->x - v10;
  if ( (float)((float)(v9 + v47) - v11) >= kfMaxHeightDiff_1 )
    return retaddr;
  UFG::ParkourHandle::GetNormal(v7, &out);
  UFG::ParkourHandle::GetNormal(v8, &v41);
  v15 = out.z + v41.z;
  v16 = out.y + v41.y;
  v17 = (__m128)LODWORD(out.x);
  v17.m128_f32[0] = out.x + v41.x;
  v18 = v17;
  v18.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16)) + (float)(v15 * v15);
  v19 = v18.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v18));
  v20 = v15 * v19;
  v21 = v16 * v19;
  v22 = v17.m128_f32[0] * v19;
  v23 = (float)((float)(v22 * v14) + (float)(v21 * v13)) + (float)(v20 * v12);
  if ( v23 <= 0.0 || v23 >= 1.0 )
    return retaddr;
  v24 = result.z + v38.z;
  v25 = result.y + v38.y;
  v26 = (__m128)LODWORD(result.x);
  v26.m128_f32[0] = result.x + v38.x;
  v27 = v26;
  v27.m128_f32[0] = (float)((float)(v26.m128_f32[0] * v26.m128_f32[0]) + (float)(v25 * v25)) + (float)(v24 * v24);
  v28 = v27.m128_f32[0] == 0.0 ? 0.0 : 1.0 / COERCE_FLOAT(_mm_sqrt_ps(v27));
  v29 = v24 * v28;
  v30 = v25 * v28;
  v31 = v26.m128_f32[0] * v28;
  v32 = (float)(v31 * *(float *)&vars0) + (float)(v30 * v37);
  if ( v32 <= -0.5
    || v32 >= 0.5
    || (float)((float)((float)(*((float *)&v43 + 1) - v4->x) * result.x) + (float)(result.y * (float)(v44 - v4->y))) > 0.0
    || (float)((float)((float)(v41.x - v4->x) * v38.x) + (float)(v38.y * (float)(v41.y - v4->y))) < 0.0 )
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
  UFG::CoverPosition::SetParkourHandle(v33, v7);
  return v33;
}

// File Line: 359
// RVA: 0x35CDD0
bool __fastcall UFG::CoverObjectGroup::GetCoverPositions(UFG::CoverObjectGroup *this, UFG::qArray<UFG::CoverPosition *,0> *aCoverPositions)
{
  UFG::qArray<UFG::CoverPosition *,0> *v2; // rdi
  UFG::CoverObjectGroup *v3; // r14
  float v4; // xmm11_4
  float v5; // xmm0_4
  signed int v6; // ebx
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
  float v21; // xmm2_4
  float v22; // xmm0_4
  __int64 v23; // r12
  unsigned int v24; // esi
  unsigned int v25; // ebx
  unsigned int v26; // ebx
  unsigned __int64 v27; // rax
  UFG::allocator::free_link *v28; // r14
  unsigned int v29; // er9
  unsigned int v30; // er12
  UFG::CoverObjectBase *v31; // r14
  int v32; // esi
  UFG::CoverPosition *v33; // r15
  UFG::CoverObjectBaseVtbl *v34; // rbx
  __int64 v35; // rax
  __int64 v36; // rax
  __int64 v37; // rcx
  int v38; // eax
  __int64 v39; // rdx
  UFG::CoverCorner *v40; // rdx
  __int64 v41; // rax
  __int64 v42; // rcx
  signed __int64 v43; // rcx
  UFG::allocator::free_link *v44; // rcx
  __int64 v45; // rdx
  UFG::CoverCorner *v46; // rdx
  __int64 v47; // rax
  __int64 v48; // rdx
  signed __int64 v49; // r8
  UFG::CoverPosition *v50; // rax
  UFG::CoverPosition *v51; // r15
  __int64 v52; // rbp
  unsigned int v53; // esi
  unsigned int v54; // ebx
  unsigned int v55; // ebx
  unsigned __int64 v56; // rax
  UFG::allocator::free_link *v57; // rax
  UFG::CoverPosition **v58; // r14
  unsigned int v59; // er9
  char v61; // [rsp+28h] [rbp-F0h]
  UFG::CoverObjectGroup *v62; // [rsp+120h] [rbp+8h]
  int v63; // [rsp+128h] [rbp+10h]
  signed int v64; // [rsp+130h] [rbp+18h]

  v62 = this;
  v2 = aCoverPositions;
  v3 = this;
  v4 = this->m_fTotalLength;
  if ( v4 > 0.5 )
  {
    v5 = *(float *)&FLOAT_1_0;
    if ( (float)(signed int)(float)(v4 * 1.0526316) >= 1.0 )
      v5 = (float)(signed int)(float)(v4 * 1.0526316);
    v6 = (signed int)v5;
    v64 = (signed int)v5;
    v7 = v4 / (float)(signed int)v5;
    v8 = 0;
    v9 = 0.0;
    if ( !(*(unsigned __int8 (__cdecl **)(UFG::CoverObjectBase *))(**(_QWORD **)this->m_aChildObjects.p + 48i64))(*this->m_aChildObjects.p) )
    {
      do
        v10 = v3->m_aChildObjects.p[++v8];
      while ( !((unsigned __int8 (__cdecl *)(UFG::CoverObjectBase *))v10->vfptr->IsParkour)(v10) );
    }
    v11 = v3->m_aChildObjects.p[v8];
    v12 = UFG::ParkourHandle::GetHalfLength((UFG::ParkourHandle *)v11[1].m_pCoverObjectGroup) * 2.0;
    v13 = 0;
    v63 = 0;
    if ( v6 > 0 )
    {
      do
      {
        v14 = (float)((float)v13 * v7) + (float)(v7 * 0.5);
        while ( v14 > v12 )
        {
          v15 = v3->m_aChildObjects.p[++v8];
          if ( ((unsigned __int8 (__cdecl *)(UFG::CoverObjectBase *))v15->vfptr->IsParkour)(v15) )
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
        v19->vfptr->GetHeight((UFG::CoverObjectBase *)&v19->vfptr);
        if ( v20 <= 0.5 || v20 >= 1.6 )
          v21 = UFG::CoverObjectBase::ms_fHighSideOffset;
        else
          v21 = UFG::CoverObjectBase::ms_fLowSideOffset;
        v22 = (float)(v3->m_fTotalLength - v14) - v21;
        v19->m_fDistToLeft = v14 - v21;
        v19->m_fDistToRight = v22;
        v23 = v2->size;
        v24 = v23 + 1;
        v25 = v2->capacity;
        if ( (signed int)v23 + 1 > v25 )
        {
          if ( v25 )
            v26 = 2 * v25;
          else
            v26 = 1;
          for ( ; v26 < v24; v26 *= 2 )
            ;
          if ( v26 <= 2 )
            v26 = 2;
          if ( v26 - v24 > 0x10000 )
            v26 = v23 + 65537;
          if ( v26 != (_DWORD)v23 )
          {
            v27 = 8i64 * v26;
            if ( !is_mul_ok(v26, 8ui64) )
              v27 = -1i64;
            v28 = UFG::qMalloc(v27, "qArray.Add", 0i64);
            if ( v2->p )
            {
              v29 = 0;
              if ( v2->size )
              {
                do
                {
                  v28[v29] = (UFG::allocator::free_link)v2->p[v29];
                  ++v29;
                }
                while ( v29 < v2->size );
              }
              operator delete[](v2->p);
            }
            v2->p = (UFG::CoverPosition **)v28;
            v2->capacity = v26;
            v3 = v62;
          }
        }
        v2->size = v24;
        v2->p[v23] = v19;
        v13 = v63 + 1;
        v63 = v13;
      }
      while ( v13 < v64 );
    }
  }
  v30 = 0;
  if ( v3->m_aChildObjects.size )
  {
    do
    {
      v31 = v3->m_aChildObjects.p[v30];
      if ( v31->vfptr->IsCorner(v31) )
      {
        v32 = 0;
        if ( v2->size )
        {
          while ( 1 )
          {
            v33 = v2->p[v32];
            v34 = v31->vfptr;
            v35 = (__int64)v33->vfptr->GetSyncPos((UFG::CoverObjectBase *)&v2->p[v32]->vfptr, (UFG::qVector3 *)&v61);
            v36 = ((__int64 (__fastcall *)(UFG::CoverObjectBase *, __int64, _QWORD))v34->GetCoverPosition)(
                    v31,
                    v35,
                    0i64);
            v37 = v36;
            if ( v36 )
              break;
            if ( ++v32 >= v2->size )
              goto LABEL_56;
          }
          v38 = *(_DWORD *)(v36 + 8);
          *(_DWORD *)(v37 + 8) = v38;
          if ( !v38 )
            (**(void (__fastcall ***)(__int64, signed __int64))v37)(v37, 1i64);
          v39 = *(_QWORD *)&v31[2].m_fPriority;
          if ( v39 )
          {
            v40 = (UFG::CoverCorner *)(v39 + 24);
          }
          else
          {
            v41 = *(_QWORD *)&v31[1].m_fPriority;
            if ( v41 )
            {
              v42 = *(_QWORD *)(v41 + 96);
              if ( v42 )
                v43 = v41 + v42 + 96;
              else
                v43 = 0i64;
              v40 = (UFG::CoverCorner *)(v43 + 48i64 * LOWORD(v31[1].vfptr));
            }
            else
            {
              v40 = 0i64;
            }
          }
          if ( v40->m_eCoverSide.mValue == 1 )
            UFG::CoverCornerHandle::operator=(&v33->m_RightCorner, v40);
          else
            UFG::CoverCornerHandle::operator=(&v33->m_LeftCorner, v40);
        }
        else
        {
LABEL_56:
          v44 = UFG::qMalloc(0x170ui64, "CoverPosition", 0i64);
          if ( v44 )
          {
            v45 = *(_QWORD *)&v31[2].m_fPriority;
            if ( v45 )
            {
              v46 = (UFG::CoverCorner *)(v45 + 24);
            }
            else
            {
              v47 = *(_QWORD *)&v31[1].m_fPriority;
              if ( v47 )
              {
                v48 = *(_QWORD *)(v47 + 96);
                if ( v48 )
                  v49 = v47 + v48 + 96;
                else
                  v49 = 0i64;
                v46 = (UFG::CoverCorner *)(v49 + 48i64 * LOWORD(v31[1].vfptr));
              }
              else
              {
                v46 = 0i64;
              }
            }
            UFG::CoverPosition::CoverPosition((UFG::CoverPosition *)v44, v46);
            v51 = v50;
          }
          else
          {
            v51 = 0i64;
          }
          v52 = v2->size;
          v53 = v52 + 1;
          v54 = v2->capacity;
          if ( (signed int)v52 + 1 > v54 )
          {
            if ( v54 )
              v55 = 2 * v54;
            else
              v55 = 1;
            for ( ; v55 < v53; v55 *= 2 )
              ;
            if ( v55 <= 2 )
              v55 = 2;
            if ( v55 - v53 > 0x10000 )
              v55 = v52 + 65537;
            if ( v55 != (_DWORD)v52 )
            {
              v56 = 8i64 * v55;
              if ( !is_mul_ok(v55, 8ui64) )
                v56 = -1i64;
              v57 = UFG::qMalloc(v56, "qArray.Add", 0i64);
              v58 = (UFG::CoverPosition **)v57;
              if ( v2->p )
              {
                v59 = 0;
                if ( v2->size )
                {
                  do
                  {
                    v57[v59] = (UFG::allocator::free_link)v2->p[v59];
                    ++v59;
                  }
                  while ( v59 < v2->size );
                }
                operator delete[](v2->p);
              }
              v2->p = v58;
              v2->capacity = v55;
            }
          }
          v2->size = v53;
          v2->p[v52] = v51;
        }
      }
      ++v30;
      v3 = v62;
    }
    while ( v30 < v62->m_aChildObjects.size );
  }
  return v2->size != 0;
}

// File Line: 457
// RVA: 0x398FE0
void __fastcall UFG::CoverObjectGroup::UpdateTransforms(UFG::CoverObjectGroup *this)
{
  __int64 v1; // rbx
  UFG::CoverObjectGroup *v2; // rdi

  v1 = 0i64;
  v2 = this;
  if ( this->m_aChildObjects.size )
  {
    do
    {
      ((void (*)(void))v2->m_aChildObjects.p[v1]->vfptr->UpdateTransforms)();
      v1 = (unsigned int)(v1 + 1);
    }
    while ( (unsigned int)v1 < v2->m_aChildObjects.size );
  }
}

