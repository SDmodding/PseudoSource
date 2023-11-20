// File Line: 18
// RVA: 0x131B8B0
void __fastcall hkVertexFormat::Element::getText(hkVertexFormat::Element *this, hkStringBuf *buf)
{
  _QWORD v2[2]; // [rsp+28h] [rbp-10h]

  LODWORD(v2[0]) = (unsigned __int8)this->m_numValues;
  hkStringBuf::printf(
    buf,
    "%s(%i) %s(%i)",
    hkVertexFormat::s_usageText[(unsigned __int8)this->m_usage.m_storage],
    (unsigned __int8)this->m_subUsage,
    hkVertexFormat::s_typeText[(unsigned __int8)this->m_dataType.m_storage],
    v2[0]);
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
void __fastcall hkVertexFormat::operator=(hkVertexFormat *this, hkVertexFormat *rhs)
{
  hkVertexFormat::set(this, rhs);
}

// File Line: 90
// RVA: 0x131B950
char __fastcall hkVertexFormat::operator==(hkVertexFormat *this, hkVertexFormat *rhs)
{
  int v2; // eax
  hkVertexFormat *v3; // r8
  signed __int64 v5; // rdx
  char *v6; // rax
  signed __int64 v7; // r8

  v2 = this->m_numElements;
  v3 = rhs;
  if ( v2 != rhs->m_numElements )
    return 0;
  v5 = 0i64;
  if ( v2 > 0 )
  {
    v6 = &this->m_elements[0].m_numValues;
    v7 = (char *)v3 - (char *)this;
    while ( *(v6 - 1) == v6[v7 - 1]
         && *v6 == v6[v7]
         && v6[1] == v6[v7 + 1]
         && v6[2] == v6[v7 + 2]
         && v6[v7 + 3] == v6[3] )
    {
      ++v5;
      v6 += 8;
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
  __int64 v2; // r8
  signed __int64 v3; // rdx
  __int64 v4; // rax

  this->m_numElements = rhs->m_numElements;
  v2 = rhs->m_numElements;
  if ( v2 > 0 )
  {
    v3 = (char *)rhs - (char *)this;
    do
    {
      v4 = *(__int64 *)((char *)this->m_elements + v3);
      this = (hkVertexFormat *)((char *)this + 8);
      *(_QWORD *)&this[-1].m_elements[31].m_flags.m_storage = v4;
      --v2;
    }
    while ( v2 );
  }
}

// File Line: 122
// RVA: 0x131BB00
__int64 __fastcall hkVertexFormat::findNextSubUsage(hkVertexFormat *this, hkVertexFormat::ComponentUsage usage)
{
  __int64 v2; // r8
  __int64 result; // rax
  char v4; // r9
  char *v5; // rcx
  int v6; // edx

  v2 = this->m_numElements;
  result = 0i64;
  v4 = usage;
  if ( v2 > 0 )
  {
    v5 = &this->m_elements[0].m_subUsage;
    do
    {
      if ( *(v5 - 1) == v4 )
      {
        v6 = (unsigned __int8)*v5 + 1;
        if ( v6 > (signed int)result )
          result = (unsigned int)v6;
      }
      v5 += 8;
      --v2;
    }
    while ( v2 );
  }
  return result;
}

// File Line: 140
// RVA: 0x131BAC0
signed __int64 __fastcall hkVertexFormat::findElementIndex(hkVertexFormat *this, hkVertexFormat::ComponentUsage usage, int subUsage)
{
  __int64 v3; // r11
  unsigned int v4; // er10
  __int64 v5; // r9
  char *v6; // rax

  v3 = this->m_numElements;
  v4 = 0;
  v5 = 0i64;
  if ( v3 <= 0 )
    return 0xFFFFFFFFi64;
  v6 = &this->m_elements[0].m_subUsage;
  while ( *(v6 - 1) != (_BYTE)usage || (unsigned __int8)*v6 != subUsage )
  {
    ++v5;
    ++v4;
    v6 += 8;
    if ( v5 >= v3 )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

// File Line: 154
// RVA: 0x131BA60
char __fastcall hkVertexFormat::isCanonicalOrder(hkVertexFormat *this)
{
  signed __int64 v1; // r9
  signed __int64 v2; // rdx
  char *v3; // rax
  unsigned __int8 v4; // cl
  unsigned __int8 v5; // r8
  unsigned __int8 v6; // r8

  v1 = this->m_numElements;
  v2 = 1i64;
  if ( v1 <= 1 )
    return 1;
  v3 = &this->m_elements[0].m_subUsage;
  while ( 1 )
  {
    v4 = *(v3 - 1);
    v5 = v3[7];
    if ( v4 > v5 )
      break;
    if ( v4 >= v5 )
    {
      v6 = v3[8];
      if ( (unsigned __int8)*v3 > v6 || *v3 == v6 )
        break;
    }
    ++v2;
    v3 += 8;
    if ( v2 >= v1 )
      return 1;
  }
  return 0;
}

// File Line: 185
// RVA: 0x131BC90
bool __fastcall hkVertexFormat_orderComponents(hkVertexFormat::Element *a, hkVertexFormat::Element *b)
{
  unsigned __int8 v2; // al
  unsigned __int8 v3; // r8

  v2 = a->m_usage.m_storage;
  v3 = b->m_usage.m_storage;
  return v2 < v3 || v2 == v3 && (unsigned __int8)a->m_subUsage < b->m_subUsage;
}

// File Line: 190
// RVA: 0x131BA10
void __fastcall hkVertexFormat::makeCanonicalOrder(hkVertexFormat *this)
{
  hkVertexFormat *v1; // rbx
  signed int v2; // er8

  v1 = this;
  if ( !hkVertexFormat::isCanonicalOrder(this) )
  {
    v2 = v1->m_numElements;
    if ( v2 > 1 )
      hkAlgorithm::quickSortRecursive<hkVertexFormat::Element,bool (*)(hkVertexFormat::Element const &,hkVertexFormat::Element const &)>(
        v1->m_elements,
        0,
        v2 - 1,
        hkVertexFormat_orderComponents);
  }
}

// File Line: 202
// RVA: 0x131BB40
void __fastcall hkVertexFormat::addElement(hkVertexFormat *this, hkVertexFormat::ComponentUsage usage, hkVertexFormat::ComponentType type, int numValues, int flags)
{
  __int64 v5; // rdi
  char v6; // bp
  char v7; // r14
  char v8; // si
  hkVertexFormat *v9; // rbx
  char v10; // al

  v5 = this->m_numElements;
  v6 = numValues;
  v7 = type;
  v8 = usage;
  v9 = this;
  if ( (signed int)v5 < 32 )
  {
    v10 = hkVertexFormat::findNextSubUsage(this, usage);
    v9->m_numElements = v5 + 1;
    v9->m_elements[v5].m_subUsage = v10;
    v9->m_elements[v5].m_dataType.m_storage = v7;
    v9->m_elements[v5].m_numValues = v6;
    v9->m_elements[v5].m_usage.m_storage = v8;
    v9->m_elements[v5].m_flags.m_storage = flags;
  }
}

// File Line: 222
// RVA: 0x131BBC0
void __fastcall hkVertexFormat::addElement(hkVertexFormat *this, hkVertexFormat::Element *element)
{
  hkVertexFormat::Element *v2; // rdi
  hkVertexFormat *v3; // rbx

  v2 = element;
  v3 = this;
  if ( this->m_numElements < 32
    && (signed int)hkVertexFormat::findElementIndex(
                     this,
                     (hkVertexFormat::ComponentUsage)(unsigned __int8)element->m_usage.m_storage,
                     (unsigned __int8)element->m_subUsage) < 0 )
  {
    v3->m_elements[v3->m_numElements++] = *v2;
  }
}

// File Line: 239
// RVA: 0x131BC10
__int64 __fastcall hkVertexFormat::calculateSharingType(hkVertexFormat *this)
{
  __int64 v1; // r9
  __int64 result; // rax
  int v3; // edx
  __int64 v4; // r8
  hkFlags<enum hkVertexFormat::HintFlags,unsigned char> *v5; // rcx

  v1 = this->m_numElements;
  result = 0i64;
  v3 = 0;
  v4 = v1;
  if ( (signed int)v1 > 0 )
  {
    v5 = &this->m_elements[0].m_flags;
    do
    {
      if ( v5->m_storage & 8 )
        ++v3;
      v5 += 8;
      --v4;
    }
    while ( v4 );
    if ( v3 )
    {
      LOBYTE(result) = v3 != (_DWORD)v1;
      result = (unsigned int)(result + 1);
    }
  }
  return result;
}

// File Line: 269
// RVA: 0x131BC50
signed __int64 __fastcall hkMeshVertexBuffer::LockedVertices::findBufferIndex(hkMeshVertexBuffer::LockedVertices *this, hkVertexFormat::ComponentUsage usage, int subUsage)
{
  __int64 v3; // r11
  unsigned int v4; // er10
  __int64 v5; // r9
  char *v6; // rax

  v3 = this->m_numBuffers;
  v4 = 0;
  v5 = 0i64;
  if ( v3 <= 0 )
    return 0xFFFFFFFFi64;
  v6 = &this->m_buffers[0].m_element.m_subUsage;
  while ( *(v6 - 1) != (_BYTE)usage || (unsigned __int8)*v6 != subUsage )
  {
    ++v5;
    ++v4;
    v6 += 24;
    if ( v5 >= v3 )
      return 0xFFFFFFFFi64;
  }
  return v4;
}

