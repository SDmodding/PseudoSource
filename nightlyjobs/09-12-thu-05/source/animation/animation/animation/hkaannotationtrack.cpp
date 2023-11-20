// File Line: 13
// RVA: 0xB451A0
void __fastcall hkaAnnotationTrack::hkaAnnotationTrack(hkaAnnotationTrack *this)
{
  hkaAnnotationTrack *v1; // rbx

  v1 = this;
  hkStringPtr::hkStringPtr(&this->m_trackName);
  v1->m_annotations.m_data = 0i64;
  v1->m_annotations.m_size = 0;
  v1->m_annotations.m_capacityAndFlags = 2147483648;
}

// File Line: 18
// RVA: 0xB451D0
void __fastcall hkaAnnotationTrack::hkaAnnotationTrack(hkaAnnotationTrack *this, hkaAnnotationTrack *that)
{
  hkaAnnotationTrack *v2; // r12
  hkaAnnotationTrack *v3; // r13
  __int64 v4; // rbp
  __int64 v5; // rsi
  int v6; // er9
  int v7; // ebx
  hkStringPtr *v8; // rdi
  hkaAnnotationTrack::Annotation *v9; // rax
  __int64 v10; // r15
  hkStringPtr *v11; // rbx
  char *v12; // rdi
  signed __int64 v13; // rbx
  __int64 v14; // rdi
  signed __int64 v15; // rsi
  int v16; // [rsp+70h] [rbp+8h]
  hkResult result; // [rsp+78h] [rbp+10h]

  v2 = that;
  v3 = this;
  hkStringPtr::hkStringPtr(&this->m_trackName, &that->m_trackName);
  v3->m_annotations.m_capacityAndFlags = 2147483648;
  v3->m_annotations.m_data = 0i64;
  v3->m_annotations.m_size = 0;
  v4 = v2->m_annotations.m_size;
  LODWORD(v5) = v4;
  if ( (signed int)v4 > 0 )
    LODWORD(v5) = 0;
  v16 = v5;
  if ( (signed int)v4 > 0 )
  {
    v6 = v4;
    if ( (signed int)v4 < 0 )
      v6 = 0;
    hkArrayUtil::_reserve(
      &result,
      (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
      &v3->m_annotations,
      v6,
      16);
  }
  v7 = -1 - v4;
  if ( -1 - (signed int)v4 >= 0 )
  {
    v8 = &v3->m_annotations.m_data[v4 + v7].m_text;
    do
    {
      hkStringPtr::~hkStringPtr(v8);
      v8 -= 2;
      --v7;
    }
    while ( v7 >= 0 );
  }
  v9 = v3->m_annotations.m_data;
  v10 = (signed int)v5;
  if ( (signed int)v5 > 0 )
  {
    v11 = &v9->m_text;
    v12 = (char *)((char *)v2->m_annotations.m_data - (char *)v9);
    v5 = (signed int)v5;
    do
    {
      LODWORD(v11[-1].m_stringAndFlag) = *(_DWORD *)((char *)&v11[-1].m_stringAndFlag + (_QWORD)v12);
      hkStringPtr::operator=(v11, (hkStringPtr *)((char *)v11 + (_QWORD)v12));
      v11 += 2;
      --v5;
    }
    while ( v5 );
  }
  v13 = (signed __int64)&v3->m_annotations.m_data[v10];
  v14 = (signed int)v4 - v16;
  if ( (signed int)v4 - v16 > 0 )
  {
    v15 = (char *)v2->m_annotations.m_data - (char *)v3->m_annotations.m_data;
    do
    {
      if ( v13 )
      {
        *(_DWORD *)v13 = *(_DWORD *)(v15 + v13);
        hkStringPtr::hkStringPtr((hkStringPtr *)(v13 + 8), (hkStringPtr *)(v15 + v13 + 8));
      }
      v13 += 16i64;
      --v14;
    }
    while ( v14 );
  }
  v3->m_annotations.m_size = v4;
}

