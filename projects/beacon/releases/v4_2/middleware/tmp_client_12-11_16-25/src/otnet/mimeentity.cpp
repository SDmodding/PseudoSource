// File Line: 185
// RVA: 0xECD750
void __fastcall OSuite::ZMimeEntity::SerializeTo(OSuite::ZMimeEntity *this, OSuite::IHttpRequest *request)
{
  OSuite::ZObjectVtbl *v2; // rsi
  OSuite::ZMimeEntity *v3; // rbp
  OSuite::IHttpRequest *v4; // r14
  unsigned __int64 v5; // rdi
  const void *v6; // rax
  void *v7; // rdi
  unsigned __int64 i; // rsi
  signed __int64 v9; // rbx

  v2 = request->vfptr;
  v3 = this;
  v4 = request;
  v5 = OSuite::ZStringBuilder::Count((OSuite::ZStringBuilder *)&this->m_Content);
  v6 = OSuite::ZUtf8Buffer::Buffer(&v3->m_Content);
  ((void (__fastcall *)(OSuite::IHttpRequest *, const void *, unsigned __int64))v2[14].__vecDelDtor)(v4, v6, v5);
  if ( v3->m_pFileContent )
  {
    v7 = OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, 1024ui64, 0i64);
    ((void (*)(void))v3->m_pFileContent->vfptr->Rewind)();
    for ( i = ((__int64 (*)(void))v3->m_pFileContent->vfptr->Size)(); i; i -= v9 )
    {
      v9 = 1024i64;
      if ( i < 0x400 )
        v9 = i;
      (*((void (__fastcall **)(OSuite::IReader *, void *, signed __int64))&v3->m_pFileContent->vfptr->__vecDelDtor + 1))(
        v3->m_pFileContent,
        v7,
        v9);
      ((void (__fastcall *)(OSuite::IHttpRequest *, void *, signed __int64))v4->vfptr[14].__vecDelDtor)(v4, v7, v9);
    }
    OSuite::ZObject::free((OSuite::ZObject *)&v3->vfptr, v7);
  }
}

// File Line: 214
// RVA: 0xECD504
OSuite::ZString *__fastcall OSuite::ZMimeEntity::Base64Encode(OSuite::ZString *result, const void *pBuffer, unsigned __int64 nLength)
{
  OSuite::ZString *v3; // r12
  char *v4; // r15
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdx
  int v7; // edi
  __int64 v8; // r14
  unsigned __int8 *v9; // r13
  unsigned __int64 v10; // rsi
  __int64 v11; // rbx
  int v12; // edi
  __int64 v13; // rbx
  __int64 v14; // rbx
  OSuite::ZString resulta; // [rsp+20h] [rbp-50h]
  OSuite::ZStringBuilder v17; // [rsp+38h] [rbp-38h]

  v17.m_Chars.m_pList = 0i64;
  v3 = result;
  v4 = (char *)pBuffer;
  v5 = nLength;
  OSuite::ZStringBuilder::ZStringBuilder(
    &v17,
    ((unsigned __int64)(4 * nLength * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 1) + 2);
  v6 = (unsigned __int64)(v5 * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 1;
  v7 = v5 - 3 * v6;
  v8 = 3 * (signed int)v6;
  if ( 3 * (signed int)v6 > 0 )
  {
    v9 = (unsigned __int8 *)(v4 + 1);
    v10 = ((unsigned __int64)((unsigned __int64)(3 * (signed int)v6 - 1i64) * (unsigned __int128)0xAAAAAAAAAAAAAAABui64 >> 64) >> 1)
        + 1;
    do
    {
      v11 = v9[1] | ((*v9 | (*(v9 - 1) << 8)) << 8);
      OSuite::ZStringBuilder::Append(
        &v17,
        OSuite::ZMimeEntity::s_cBase64[((v9[1] | ((*v9 | (*(v9 - 1) << 8)) << 8)) >> 18) & 0x3F]);
      OSuite::ZStringBuilder::Append(&v17, OSuite::ZMimeEntity::s_cBase64[(v11 >> 12) & 0x3F]);
      OSuite::ZStringBuilder::Append(&v17, OSuite::ZMimeEntity::s_cBase64[(v11 >> 6) & 0x3F]);
      OSuite::ZStringBuilder::Append(&v17, OSuite::ZMimeEntity::s_cBase64[v11 & 0x3F]);
      v9 += 3;
      --v10;
    }
    while ( v10 );
  }
  v12 = v7 - 1;
  if ( v12 )
  {
    if ( v12 == 1 )
    {
      v13 = (((unsigned __int8)v4[v8] << 8) | (unsigned __int8)v4[v8 + 1]) << 8;
      OSuite::ZStringBuilder::Append(
        &v17,
        OSuite::ZMimeEntity::s_cBase64[((((unsigned __int8)v4[v8] << 8) | (unsigned __int8)v4[v8 + 1]) << 8 >> 18) & 0x3F]);
      OSuite::ZStringBuilder::Append(&v17, OSuite::ZMimeEntity::s_cBase64[(v13 >> 12) & 0x3F]);
      OSuite::ZStringBuilder::Append(&v17, OSuite::ZMimeEntity::s_cBase64[(v13 >> 6) & 0x3F]);
      OSuite::ZStringBuilder::Append(&v17, 61);
    }
  }
  else
  {
    v14 = (unsigned __int8)v4[v8] << 16;
    OSuite::ZStringBuilder::Append(&v17, OSuite::ZMimeEntity::s_cBase64[((unsigned __int8)v4[v8] << 16 >> 18) & 0x3F]);
    OSuite::ZStringBuilder::Append(&v17, OSuite::ZMimeEntity::s_cBase64[(v14 >> 12) & 0x3F]);
    OSuite::ZStringBuilder::Append(&v17, asc_141743BB0);
  }
  OSuite::ZStringBuilder::ToString(&v17, &resulta);
  OSuite::ZString::ZString(v3, &resulta);
  OSuite::ZString::~ZString(&resulta);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v17);
  return v3;
}

// File Line: 260
// RVA: 0xECD334
char __fastcall OSuite::ZMimeEntity::Base64Decode(void *pBuffer, OSuite::ZString *sBase64)
{
  char *v2; // r14
  OSuite::ZString *v3; // rsi
  unsigned __int64 v4; // rbx
  int v5; // ebp
  int v6; // edi

  v2 = (char *)pBuffer;
  v3 = sBase64;
  v4 = 0i64;
  v5 = OSuite::ZMimeEntity::Base64DecodedLength(sBase64);
  if ( !OSuite::ZString::Count(v3) )
    return 1;
  while ( 1 )
  {
    v6 = v5;
    if ( v5 > 3 )
      v6 = 3;
    if ( !OSuite::ZMimeEntity::Base64DecodeGroup(v2, v6, v3, v4) )
      break;
    v5 -= v6;
    v2 += v6;
    v4 += 4i64;
    if ( v4 >= OSuite::ZString::Count(v3) )
      return 1;
  }
  return 0;
}

// File Line: 280
// RVA: 0xECD428
char __fastcall OSuite::ZMimeEntity::Base64DecodeGroup(char *pDest, int nDestSize, OSuite::ZString *sBase64, unsigned __int64 nIndex)
{
  int v4; // ebx
  unsigned __int64 v5; // r14
  OSuite::ZString *v6; // r15
  signed int v7; // ebp
  int v8; // esi
  char *v9; // rdi
  int v10; // eax
  int v11; // eax
  int v12; // esi

  v4 = 0;
  v5 = nIndex;
  v6 = sBase64;
  v7 = 0;
  v8 = nDestSize;
  v9 = pDest;
  do
  {
    v10 = OSuite::ZMimeEntity::Base64DecodeChar(v6, v5++);
    if ( v10 == -1 )
      return 0;
    ++v7;
    v4 = v10 | (v4 << 6);
  }
  while ( v7 < 4 );
  v11 = v8;
  v12 = v8 - 1;
  if ( v11 > 0 )
  {
    *v9 = BYTE2(v4);
    if ( v12 > 0 )
    {
      v9[1] = BYTE1(v4);
      if ( v12 - 1 > 0 )
        v9[2] = v4;
    }
  }
  return 1;
}

// File Line: 311
// RVA: 0xECD3C4
signed __int64 __fastcall OSuite::ZMimeEntity::Base64DecodeChar(OSuite::ZString *sBase64, unsigned __int64 nIndex)
{
  unsigned __int64 v2; // rbx
  OSuite::ZString *v3; // rdi
  char v4; // al
  char v5; // r9
  signed __int64 result; // rax

  v2 = nIndex;
  v3 = sBase64;
  v4 = OSuite::ZString::CharAt(sBase64, nIndex);
  v5 = v4;
  if ( (unsigned __int8)(v4 - 32) > 0x5Fu )
    goto LABEL_9;
  result = (unsigned int)OSuite::ZMimeEntity::s_cDecode64[v4 - 32];
  if ( (_DWORD)result != -1 )
    return result;
  if ( v5 != 61 || v2 < OSuite::ZString::Count(v3) - 2 )
LABEL_9:
    result = 0xFFFFFFFFi64;
  else
    result = 0i64;
  return result;
}

// File Line: 333
// RVA: 0xECD4B4
__int64 __fastcall OSuite::ZMimeEntity::Base64DecodedLength(OSuite::ZString *sBase64)
{
  OSuite::ZString *v1; // rsi
  int v2; // eax
  int v3; // ebx
  unsigned int i; // edi

  v1 = sBase64;
  v2 = OSuite::ZString::Count(sBase64);
  v3 = v2;
  if ( v2 & 3 )
    return 0i64;
  for ( i = 3 * (v2 >> 2); OSuite::ZString::CharAt(v1, --v3) == 61; --i )
    ;
  return i;
}

