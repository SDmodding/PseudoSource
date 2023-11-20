// File Line: 15
// RVA: 0xE67370
__int64 __fastcall `anonymous namespace::extractAndAdvance<int>(const void *p, int *off)
{
  __int64 v2; // r8

  v2 = *off;
  *off = v2 + 4;
  return *(unsigned int *)((char *)p + v2);
}

// File Line: 22
// RVA: 0xE67330
const char *__fastcall `anonymous namespace::extractAndAdvanceString(const void *p, int *off)
{
  int *v2; // r9
  __int64 v3; // rdx
  const char *v4; // r8
  int v5; // ecx
  const char *v6; // rax
  int i; // ecx
  const char *result; // rax

  v2 = off;
  v3 = *off;
  v4 = (char *)p + v3;
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
  for ( i = v5 + 1; i & 3; ++i )
    ;
  result = v4;
  *v2 = i + v3;
  return result;
}

// File Line: 36
// RVA: 0xE67170
void __fastcall hkPackfileSectionHeader::getExports(hkPackfileSectionHeader *this, const void *sectionBegin, hkArray<hkResource::Export,hkContainerHeapAllocator> *exportsOut)
{
  hkArray<hkResource::Export,hkContainerHeapAllocator> *v3; // rbx
  __int64 v4; // r8
  int v5; // eax
  char *v6; // r15
  hkPackfileSectionHeader *v7; // rbp
  char *v8; // rdi
  int v9; // eax
  __int64 v10; // rsi
  const char *v11; // r14
  hkResource::Export *v12; // rcx
  int off; // [rsp+40h] [rbp+8h]

  v3 = exportsOut;
  v4 = this->m_exportsOffset;
  v5 = this->m_importsOffset - v4;
  v6 = (char *)sectionBegin;
  v7 = this;
  v8 = (char *)sectionBegin + v4;
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
      if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 16);
      v12 = &v3->m_data[v3->m_size++];
      v12->name = v11;
      v12->data = &v6[v10];
    }
    while ( off < v7->m_importsOffset - v7->m_exportsOffset );
  }
}

// File Line: 54
// RVA: 0xE67250
void __fastcall hkPackfileSectionHeader::getImports(hkPackfileSectionHeader *this, const void *sectionBegin, hkArray<hkResource::Import,hkContainerHeapAllocator> *importsOut)
{
  hkArray<hkResource::Import,hkContainerHeapAllocator> *v3; // rbx
  __int64 v4; // r8
  int v5; // eax
  char *v6; // r15
  hkPackfileSectionHeader *v7; // rbp
  char *v8; // rdi
  int v9; // eax
  __int64 v10; // rsi
  const char *v11; // r14
  hkResource::Import *v12; // rcx
  int off; // [rsp+40h] [rbp+8h]

  v3 = importsOut;
  v4 = this->m_importsOffset;
  v5 = this->m_endOffset - v4;
  v6 = (char *)sectionBegin;
  v7 = this;
  v8 = (char *)sectionBegin + v4;
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
      if ( v3->m_size == (v3->m_capacityAndFlags & 0x3FFFFFFF) )
        hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v3, 16);
      v12 = &v3->m_data[v3->m_size++];
      v12->name = v11;
      v12->location = (void **)&v6[v10];
    }
    while ( off < v7->m_endOffset - v7->m_importsOffset );
  }
}

