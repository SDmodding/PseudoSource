// File Line: 18
// RVA: 0x131B8B0
void __fastcall hkVertexFormat::Element::getText(hkVertexFormat::Element *this, hkStringBuf *buf)
{
  int m_numValues; // [rsp+28h] [rbp-10h]

  m_numValues = (unsigned __int8)this->m_numValues;
  hkStringBuf::printf(
    buf,
    "%s(%i) %s(%i)",
    hkVertexFormat::s_usageText[(unsigned __int8)this->m_usage.m_storage],
    (unsigned __int8)this->m_subUsage,
    hkVertexFormat::s_typeText[(unsigned __int8)this->m_dataType.m_storage],
    m_numValues);
}

// File Line: 76
// RVA: 0x131B910
void __fastcall hkVertexFormat::hkVertexFormat(hkVertexFormat *this)
{
  this->m_numElements = 0;
}

// File Line: 80
// RVA: 0x131B930
void __fastcall hkVertexFormat::hkVertexFormat(hkVertexFormat *this, hkVertexFormat *rhs)
{
  hkVertexFormat::set(this, rhs);
}

// File Line: 85
// RVA: 0x131BA00
// attributes: thunk
void __fastcall hkVertexFormat::operator=(hkVertexFormat *this, hkVertexFormat *rhs)
{
  hkVertexFormat::set(this, rhs);
}

// File Line: 90
// RVA: 0x131B950
char __fastcall hkVertexFormat::operator==(hkVertexFormat *this, hkVertexFormat *rhs)
{
  int m_numElements; // eax
  __int64 v5; // rdx
  char *p_m_numValues; // rax
  signed __int64 v7; // r8

  m_numElements = this->m_numElements;
  if ( m_numElements != rhs->m_numElements )
    return 0;
  v5 = 0i64;
  if ( m_numElements > 0 )
  {
    p_m_numValues = &this->m_elements[0].m_numValues;
    v7 = (char *)rhs - (char *)this;
    while ( *(p_m_numValues - 1) == p_m_numValues[v7 - 1]
         && *p_m_numValues == p_m_numValues[v7]
         && p_m_numValues[1] == p_m_numValues[v7 + 1]
         && p_m_numValues[2] == p_m_numValues[v7 + 2]
         && p_m_numValues[v7 + 3] == p_m_numValues[3] )
    {
      ++v5;
      p_m_numValues += 8;
      if ( v5 >= this->m_numElements )
        return 1;
    }
    return 0;
  }
  return 1;
}

// File Line: 110
// RVA: 0x131B9C0
void __fastcall hkVertexFormat::set(hkVertexFormat *this, hkVertexFormat *rhs)
{
  __int64 m_numElements; // r8
  signed __int64 v3; // rdx
  __int64 v4; // rax

  this->m_numElements = rhs->m_numElements;
  m_numElements = rhs->m_numElements;
  if ( m_numElements > 0 )
  {
    v3 = (char *)rhs - (char *)this;
    do
    {
      v4 = *(__int64 *)((char *)this->m_elements + v3);
      this = (hkVertexFormat *)((char *)this + 8);
      *(_QWORD *)&this[-1].m_elements[31].m_flags.m_storage = v4;
      --m_numElements;
    }
    while ( m_numElements );
  }
}

// File Line: 122
// RVA: 0x131BB00
__int64 __fastcall hkVertexFormat::findNextSubUsage(hkVertexFormat *this, hkVertexFormat::ComponentUsage usage)
{
  __int64 m_numElements; // r8
  __int64 result; // rax
  char v4; // r9
  char *p_m_subUsage; // rcx
  int v6; // edx

  m_numElements = this->m_numElements;
  result = 0i64;
  v4 = usage;
  if ( m_numElements > 0 )
  {
    p_m_subUsage = &this->m_elements[0].m_subUsage;
    do
    {
      if ( *(p_m_subUsage - 1) == v4 )
      {
        v6 = (unsigned __int8)*p_m_subUsage + 1;
        if ( v6 > (int)result )
          result = (unsigned int)v6;
      }
      p_m_subUsage += 8;
      --m_numElements;
    }
    while ( m_numElements );
  }
  return result;
}

// File Line: 140
// RVA: 0x131BAC0
__int64 __fastcall hkVertexFormat::findElementIndex(
        hkVertexFormat *this,
        hkVertexFormat::ComponentUsage usage,
        int subUsage)
{
  __int64 m_numElements; // r11
  unsigned int v4; // r10d
  __int64 v5; // r9
  char *i; // rax

  m_numElements = this->m_numElements;
  v4 = 0;
  v5 = 0i64;
  if ( m_numElements <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = &this->m_elements[0].m_subUsage; *(i - 1) != (_BYTE)usage || (unsigned __int8)*i != subUsage; i += 8 )
  {
    ++v5;
    ++v4;
    if ( v5 >= m_numElements )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

// File Line: 154
// RVA: 0x131BA60
char __fastcall hkVertexFormat::isCanonicalOrder(hkVertexFormat *this)
{
  __int64 m_numElements; // r9
  __int64 v2; // rdx
  char *i; // rax
  unsigned __int8 v4; // cl
  unsigned __int8 v5; // r8

  m_numElements = this->m_numElements;
  v2 = 1i64;
  if ( m_numElements <= 1 )
    return 1;
  for ( i = &this->m_elements[0].m_subUsage; ; i += 8 )
  {
    v4 = *(i - 1);
    v5 = i[7];
    if ( v4 > v5 || v4 >= v5 && (unsigned __int8)*i >= (unsigned __int8)i[8] )
      break;
    if ( ++v2 >= m_numElements )
      return 1;
  }
  return 0;
}

// File Line: 185
// RVA: 0x131BC90
bool __fastcall hkVertexFormat_orderComponents(hkVertexFormat::Element *a, hkVertexFormat::Element *b)
{
  unsigned __int8 m_storage; // al
  unsigned __int8 v3; // r8

  m_storage = a->m_usage.m_storage;
  v3 = b->m_usage.m_storage;
  return m_storage < v3 || m_storage == v3 && a->m_subUsage < (unsigned int)b->m_subUsage;
}

// File Line: 190
// RVA: 0x131BA10
void __fastcall hkVertexFormat::makeCanonicalOrder(hkVertexFormat *this)
{
  int m_numElements; // r8d

  if ( !hkVertexFormat::isCanonicalOrder(this) )
  {
    m_numElements = this->m_numElements;
    if ( m_numElements > 1 )
      hkAlgorithm::quickSortRecursive<hkVertexFormat::Element,bool (*)(hkVertexFormat::Element const &,hkVertexFormat::Element const &)>(
        this->m_elements,
        0,
        m_numElements - 1,
        hkVertexFormat_orderComponents);
  }
}

// File Line: 202
// RVA: 0x131BB40
void __fastcall hkVertexFormat::addElement(
        hkVertexFormat *this,
        __int32 usage,
        hkVertexFormat::ComponentType type,
        char numValues,
        char flags)
{
  __int64 m_numElements; // rdi
  char v7; // r14
  char v8; // si
  char NextSubUsage; // al

  m_numElements = this->m_numElements;
  v7 = type;
  v8 = usage;
  if ( (int)m_numElements < 32 )
  {
    NextSubUsage = hkVertexFormat::findNextSubUsage(this, (hkVertexFormat::ComponentUsage)usage);
    this->m_numElements = m_numElements + 1;
    this->m_elements[m_numElements].m_subUsage = NextSubUsage;
    this->m_elements[m_numElements].m_dataType.m_storage = v7;
    this->m_elements[m_numElements].m_numValues = numValues;
    this->m_elements[m_numElements].m_usage.m_storage = v8;
    this->m_elements[m_numElements].m_flags.m_storage = flags;
  }
}

// File Line: 222
// RVA: 0x131BBC0
void __fastcall hkVertexFormat::addElement(hkVertexFormat *this, hkVertexFormat::Element *element)
{
  if ( this->m_numElements < 32
    && (int)hkVertexFormat::findElementIndex(
              this,
              (hkVertexFormat::ComponentUsage)(unsigned __int8)element->m_usage.m_storage,
              (unsigned __int8)element->m_subUsage) < 0 )
  {
    this->m_elements[this->m_numElements++] = *element;
  }
}

// File Line: 239
// RVA: 0x131BC10
__int64 __fastcall hkVertexFormat::calculateSharingType(hkVertexFormat *this)
{
  __int64 m_numElements; // r9
  __int64 result; // rax
  int v3; // edx
  __int64 v4; // r8
  hkFlags<enum hkVertexFormat::HintFlags,unsigned char> *p_m_flags; // rcx

  m_numElements = this->m_numElements;
  result = 0i64;
  v3 = 0;
  v4 = m_numElements;
  if ( (int)m_numElements > 0 )
  {
    p_m_flags = &this->m_elements[0].m_flags;
    do
    {
      if ( (p_m_flags->m_storage & 8) != 0 )
        ++v3;
      p_m_flags += 8;
      --v4;
    }
    while ( v4 );
    if ( v3 )
    {
      LOBYTE(result) = v3 != (_DWORD)m_numElements;
      return (unsigned int)(result + 1);
    }
  }
  return result;
}

// File Line: 269
// RVA: 0x131BC50
__int64 __fastcall hkMeshVertexBuffer::LockedVertices::findBufferIndex(
        hkMeshVertexBuffer::LockedVertices *this,
        hkVertexFormat::ComponentUsage usage,
        int subUsage)
{
  __int64 m_numBuffers; // r11
  unsigned int v4; // r10d
  __int64 v5; // r9
  char *i; // rax

  m_numBuffers = this->m_numBuffers;
  v4 = 0;
  v5 = 0i64;
  if ( m_numBuffers <= 0 )
    return 0xFFFFFFFFi64;
  for ( i = &this->m_buffers[0].m_element.m_subUsage; *(i - 1) != (_BYTE)usage || (unsigned __int8)*i != subUsage; i += 24 )
  {
    ++v5;
    ++v4;
    if ( v5 >= m_numBuffers )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

