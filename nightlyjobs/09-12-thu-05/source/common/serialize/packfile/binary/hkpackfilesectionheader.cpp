// File Line: 15
// RVA: 0xE67370
__int64 __fastcall `anonymous namespace::extractAndAdvance<int>(char *p, int *off)
{
  __int64 v2; // r8

  v2 = *off;
  *off = v2 + 4;
  return *(unsigned int *)&p[v2];
}

// File Line: 22
// RVA: 0xE67330
const char *__fastcall `anonymous namespace::extractAndAdvanceString(char *p, int *off)
{
  __int64 v3; // rdx
  const char *v4; // r8
  int v5; // ecx
  const char *v6; // rax
  int i; // ecx
  const char *result; // rax

  v3 = *off;
  v4 = &p[v3];
  v5 = 0;
  if ( *v4 )
  {
    v6 = v4;
    do
    {
      ++v6;
      ++v5;
    }
    while ( *v6 );
  }
  for ( i = v5 + 1; (i & 3) != 0; ++i )
    ;
  result = v4;
  *off = i + v3;
  return result;
}

// File Line: 36
// RVA: 0xE67170
void __fastcall hkPackfileSectionHeader::getExports(
        hkPackfileSectionHeader *this,
        char *sectionBegin,
        hkArray<hkResource::Export,hkContainerHeapAllocator> *exportsOut)
{
  __int64 m_exportsOffset; // r8
  int v5; // eax
  char *v8; // rdi
  int v9; // eax
  __int64 v10; // rsi
  const char *v11; // r14
  hkResource::Export *v12; // rcx
  int off; // [rsp+40h] [rbp+8h] BYREF

  m_exportsOffset = this->m_exportsOffset;
  v5 = this->m_importsOffset - m_exportsOffset;
  v8 = &sectionBegin[m_exportsOffset];
  off = 0;
  if ( v5 > 0 )
  {
    do
    {
      v9 = `anonymous namespace::extractAndAdvance<int>(v8, &off);
      v10 = v9;
      if ( v9 == -1 )
        break;
      v11 = `anonymous namespace::extractAndAdvanceString(v8, &off);
      if ( exportsOut->m_size == (exportsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&exportsOut->m_data, 16);
      v12 = &exportsOut->m_data[exportsOut->m_size++];
      v12->name = v11;
      v12->data = &sectionBegin[v10];
    }
    while ( off < this->m_importsOffset - this->m_exportsOffset );
  }
}

// File Line: 54
// RVA: 0xE67250
void __fastcall hkPackfileSectionHeader::getImports(
        hkPackfileSectionHeader *this,
        char *sectionBegin,
        hkArray<hkResource::Import,hkContainerHeapAllocator> *importsOut)
{
  __int64 m_importsOffset; // r8
  int v5; // eax
  char *v8; // rdi
  int v9; // eax
  __int64 v10; // rsi
  const char *v11; // r14
  hkResource::Import *v12; // rcx
  int off; // [rsp+40h] [rbp+8h] BYREF

  m_importsOffset = this->m_importsOffset;
  v5 = this->m_endOffset - m_importsOffset;
  v8 = &sectionBegin[m_importsOffset];
  off = 0;
  if ( v5 > 0 )
  {
    do
    {
      v9 = `anonymous namespace::extractAndAdvance<int>(v8, &off);
      v10 = v9;
      if ( v9 == -1 )
        break;
      v11 = `anonymous namespace::extractAndAdvanceString(v8, &off);
      if ( importsOut->m_size == (importsOut->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&importsOut->m_data, 16);
      v12 = &importsOut->m_data[importsOut->m_size++];
      v12->name = v11;
      v12->location = (void **)&sectionBegin[v10];
    }
    while ( off < this->m_endOffset - this->m_importsOffset );
  }
}

