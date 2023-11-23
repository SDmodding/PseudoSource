// File Line: 185
// RVA: 0xECD750
void __fastcall OSuite::ZMimeEntity::SerializeTo(OSuite::ZMimeEntity *this, OSuite::IHttpRequest *request)
{
  OSuite::ZObjectVtbl *vfptr; // rsi
  unsigned __int64 v5; // rdi
  const void *v6; // rax
  void *v7; // rdi
  unsigned __int64 i; // rsi
  __int64 v9; // rbx

  vfptr = request->vfptr;
  v5 = OSuite::ZStringBuilder::Count((OSuite::ZStringBuilder *)&this->m_Content);
  v6 = OSuite::ZUtf8Buffer::Buffer(&this->m_Content);
  ((void (__fastcall *)(OSuite::IHttpRequest *, const void *, unsigned __int64))vfptr[14].__vecDelDtor)(request, v6, v5);
  if ( this->m_pFileContent )
  {
    v7 = (void *)OSuite::ZObject::m_allocator->vfptr->malloc(OSuite::ZObject::m_allocator, 1024i64, 0i64);
    this->m_pFileContent->vfptr->Rewind(this->m_pFileContent);
    for ( i = this->m_pFileContent->vfptr->Size(this->m_pFileContent); i; i -= v9 )
    {
      v9 = 1024i64;
      if ( i < 0x400 )
        v9 = i;
      (*((void (__fastcall **)(OSuite::IReader *, void *, __int64))&this->m_pFileContent->vfptr->__vecDelDtor + 1))(
        this->m_pFileContent,
        v7,
        v9);
      ((void (__fastcall *)(OSuite::IHttpRequest *, void *, __int64))request->vfptr[14].__vecDelDtor)(request, v7, v9);
    }
    OSuite::ZObject::free(this, v7);
  }
}

// File Line: 214
// RVA: 0xECD504
OSuite::ZString *__fastcall OSuite::ZMimeEntity::Base64Encode(
        OSuite::ZString *result,
        char *pBuffer,
        unsigned __int64 nLength)
{
  int v6; // edi
  int v7; // ebx
  __int64 v8; // r14
  unsigned __int8 *v9; // r13
  unsigned __int64 v10; // rsi
  __int64 v11; // rbx
  int v12; // edi
  __int64 v13; // rbx
  __int64 v14; // rbx
  OSuite::ZString resulta; // [rsp+20h] [rbp-50h] BYREF
  OSuite::ZStringBuilder v17; // [rsp+38h] [rbp-38h] BYREF

  v17.m_Chars.m_pList = 0i64;
  OSuite::ZStringBuilder::ZStringBuilder(&v17, 4 * nLength / 3 + 2);
  v6 = nLength % 3;
  v7 = 3 * (nLength / 3);
  v8 = v7;
  if ( v7 > 0 )
  {
    v9 = (unsigned __int8 *)(pBuffer + 1);
    v10 = (v7 - 1i64) / 3ui64 + 1;
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
  v12 = v6 - 1;
  if ( v12 )
  {
    if ( v12 == 1 )
    {
      v13 = (((unsigned __int8)pBuffer[v8] << 8) | (unsigned int)(unsigned __int8)pBuffer[v8 + 1]) << 8;
      OSuite::ZStringBuilder::Append(
        &v17,
        OSuite::ZMimeEntity::s_cBase64[((((unsigned __int8)pBuffer[v8] << 8) | (unsigned __int8)pBuffer[v8 + 1]) << 8 >> 18) & 0x3F]);
      OSuite::ZStringBuilder::Append(&v17, OSuite::ZMimeEntity::s_cBase64[(v13 >> 12) & 0x3F]);
      OSuite::ZStringBuilder::Append(&v17, OSuite::ZMimeEntity::s_cBase64[(v13 >> 6) & 0x3F]);
      OSuite::ZStringBuilder::Append(&v17, 61);
    }
  }
  else
  {
    v14 = (unsigned __int8)pBuffer[v8] << 16;
    OSuite::ZStringBuilder::Append(
      &v17,
      OSuite::ZMimeEntity::s_cBase64[((int)(unsigned __int8)pBuffer[v8] >> 2) & 0x3F]);
    OSuite::ZStringBuilder::Append(&v17, OSuite::ZMimeEntity::s_cBase64[(v14 >> 12) & 0x3F]);
    OSuite::ZStringBuilder::Append(&v17, asc_141743BB0);
  }
  OSuite::ZStringBuilder::ToString(&v17, &resulta);
  OSuite::ZString::ZString(result, &resulta);
  OSuite::ZString::~ZString(&resulta);
  OSuite::ZUtf8Buffer::~ZUtf8Buffer(&v17);
  return result;
}

// File Line: 260
// RVA: 0xECD334
char __fastcall OSuite::ZMimeEntity::Base64Decode(char *pBuffer, OSuite::ZString *sBase64)
{
  unsigned __int64 v4; // rbx
  int v5; // ebp
  int v6; // edi

  v4 = 0i64;
  v5 = OSuite::ZMimeEntity::Base64DecodedLength(sBase64);
  if ( !OSuite::ZString::Count(sBase64) )
    return 1;
  while ( 1 )
  {
    v6 = v5;
    if ( v5 > 3 )
      v6 = 3;
    if ( !OSuite::ZMimeEntity::Base64DecodeGroup(pBuffer, v6, sBase64, v4) )
      break;
    v5 -= v6;
    pBuffer += v6;
    v4 += 4i64;
    if ( v4 >= OSuite::ZString::Count(sBase64) )
      return 1;
  }
  return 0;
}

// File Line: 280
// RVA: 0xECD428
char __fastcall OSuite::ZMimeEntity::Base64DecodeGroup(
        char *pDest,
        int nDestSize,
        OSuite::ZString *sBase64,
        unsigned __int64 nIndex)
{
  int v4; // ebx
  int i; // ebp
  int v10; // eax
  int v11; // eax
  int v12; // esi

  v4 = 0;
  for ( i = 0; i < 4; ++i )
  {
    v10 = OSuite::ZMimeEntity::Base64DecodeChar(sBase64, nIndex++);
    if ( v10 == -1 )
      return 0;
    v4 = v10 | (v4 << 6);
  }
  v11 = nDestSize;
  v12 = nDestSize - 1;
  if ( v11 > 0 )
  {
    *pDest = BYTE2(v4);
    if ( v12 > 0 )
    {
      pDest[1] = BYTE1(v4);
      if ( v12 - 1 > 0 )
        pDest[2] = v4;
    }
  }
  return 1;
}

// File Line: 311
// RVA: 0xECD3C4
__int64 __fastcall OSuite::ZMimeEntity::Base64DecodeChar(OSuite::ZString *sBase64, unsigned __int64 nIndex)
{
  char v4; // al
  char v5; // r9
  __int64 result; // rax

  v4 = OSuite::ZString::CharAt(sBase64, nIndex);
  v5 = v4;
  if ( (unsigned __int8)(v4 - 32) > 0x5Fu )
    return 0xFFFFFFFFi64;
  result = (unsigned int)OSuite::ZMimeEntity::s_cDecode64[v4 - 32];
  if ( (_DWORD)result != -1 )
    return result;
  if ( v5 == 61 && nIndex >= OSuite::ZString::Count(sBase64) - 2 )
    return 0i64;
  else
    return 0xFFFFFFFFi64;
}

// File Line: 333
// RVA: 0xECD4B4
__int64 __fastcall OSuite::ZMimeEntity::Base64DecodedLength(OSuite::ZString *sBase64)
{
  int v2; // eax
  int v3; // ebx
  unsigned int i; // edi

  v2 = OSuite::ZString::Count(sBase64);
  v3 = v2;
  if ( (v2 & 3) != 0 )
    return 0i64;
  for ( i = 3 * (v2 >> 2); OSuite::ZString::CharAt(sBase64, --v3) == 61; --i )
    ;
  return i;
}

