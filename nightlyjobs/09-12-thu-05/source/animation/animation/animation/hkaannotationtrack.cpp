// File Line: 13
// RVA: 0xB451A0
void __fastcall hkaAnnotationTrack::hkaAnnotationTrack(hkaAnnotationTrack *this)
{
  hkStringPtr::hkStringPtr(&this->m_trackName);
  this->m_annotations.m_data = 0i64;
  this->m_annotations.m_size = 0;
  this->m_annotations.m_capacityAndFlags = 0x80000000;
}

// File Line: 18
// RVA: 0xB451D0
void __fastcall hkaAnnotationTrack::hkaAnnotationTrack(hkaAnnotationTrack *this, hkaAnnotationTrack *that)
{
  __int64 m_size; // rbp
  __int64 v5; // rsi
  int v6; // ebx
  hkStringPtr *p_m_text; // rdi
  hkaAnnotationTrack::Annotation *m_data; // rax
  __int64 v9; // r15
  hkStringPtr *v10; // rbx
  char *v11; // rdi
  hkaAnnotationTrack::Annotation *v12; // rbx
  __int64 v13; // rdi
  signed __int64 v14; // rsi
  int v15; // [rsp+70h] [rbp+8h]
  hkResult result; // [rsp+78h] [rbp+10h] BYREF

  hkStringPtr::hkStringPtr(&this->m_trackName, &that->m_trackName);
  this->m_annotations.m_capacityAndFlags = 0x80000000;
  this->m_annotations.m_data = 0i64;
  this->m_annotations.m_size = 0;
  m_size = that->m_annotations.m_size;
  LODWORD(v5) = m_size;
  if ( (int)m_size > 0 )
    LODWORD(v5) = 0;
  v15 = v5;
  if ( (int)m_size > 0 )
    hkArrayUtil::_reserve(&result, &hkContainerHeapAllocator::s_alloc, &this->m_annotations, m_size, 16);
  v6 = -1 - m_size;
  if ( -1 - (int)m_size >= 0 )
  {
    p_m_text = &this->m_annotations.m_data[m_size + v6].m_text;
    do
    {
      hkStringPtr::~hkStringPtr(p_m_text);
      p_m_text -= 2;
      --v6;
    }
    while ( v6 >= 0 );
  }
  m_data = this->m_annotations.m_data;
  v9 = (int)v5;
  if ( (int)v5 > 0 )
  {
    v10 = &m_data->m_text;
    v11 = (char *)((char *)that->m_annotations.m_data - (char *)m_data);
    v5 = (int)v5;
    do
    {
      LODWORD(v10[-1].m_stringAndFlag) = *(_DWORD *)((char *)&v10[-1].m_stringAndFlag + (_QWORD)v11);
      hkStringPtr::operator=(v10, (hkStringPtr *)((char *)v10 + (_QWORD)v11));
      v10 += 2;
      --v5;
    }
    while ( v5 );
  }
  v12 = &this->m_annotations.m_data[v9];
  v13 = (int)m_size - v15;
  if ( (int)m_size - v15 > 0 )
  {
    v14 = (char *)that->m_annotations.m_data - (char *)this->m_annotations.m_data;
    do
    {
      if ( v12 )
      {
        v12->m_time = *(float *)((char *)&v12->m_time + v14);
        hkStringPtr::hkStringPtr(&v12->m_text, (hkStringPtr *)((char *)&v12->m_text + v14));
      }
      ++v12;
      --v13;
    }
    while ( v13 );
  }
  this->m_annotations.m_size = m_size;
}

