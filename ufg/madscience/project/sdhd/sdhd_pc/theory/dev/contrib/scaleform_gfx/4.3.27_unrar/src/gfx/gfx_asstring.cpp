// File Line: 37
// RVA: 0x8BBF30
void __fastcall Scaleform::GFx::ASString::Clear(Scaleform::GFx::ASString *this)
{
  Scaleform::GFx::ASString *v1; // rdi
  Scaleform::GFx::ASStringManager *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rcx
  signed __int64 v4; // rbx
  bool v5; // zf

  v1 = this;
  v2 = this->pNode->pManager;
  ++v2->EmptyStringNode.RefCount;
  v3 = this->pNode;
  v4 = (signed __int64)&v2->EmptyStringNode;
  v5 = v3->RefCount-- == 1;
  if ( v5 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v3);
  v1->pNode = (Scaleform::GFx::ASStringNode *)v4;
}

// File Line: 42
// RVA: 0x8A9360
bool __fastcall Scaleform::GFx::ASString::operator<(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *v2; // rcx
  Scaleform::GFx::ASStringNode *v3; // rdx
  bool result; // al
  unsigned int v5; // ebx
  const char *v6; // rdx
  size_t v7; // r8
  unsigned int v8; // edi
  const char *v9; // rcx
  int v10; // ecx

  v2 = this->pNode;
  v3 = str->pNode;
  if ( v2 == v3 )
    return 0;
  v5 = v3->Size;
  v6 = v3->pData;
  v7 = v5;
  v8 = v2->Size;
  v9 = v2->pData;
  if ( v8 < v5 )
    v7 = v8;
  v10 = memcmp(v9, v6, v7);
  if ( v10 )
    result = v10 < 0;
  else
    result = v8 < v5;
  return result;
}

// File Line: 54
// RVA: 0x8DAAC0
__int64 __fastcall Scaleform::GFx::ASConstString::GetLength(Scaleform::GFx::ASConstString *this)
{
  Scaleform::GFx::ASConstString *v1; // rdi
  Scaleform::GFx::ASStringNode *v2; // rcx
  __int64 v3; // rbx
  __int64 result; // rax

  v1 = this;
  v2 = this->pNode;
  v3 = v2->Size;
  if ( v2->HashFlags & 0x8000000 )
    return (unsigned int)v3;
  result = Scaleform::UTF8Util::GetLength(v2->pData, v3);
  if ( (_DWORD)result == (_DWORD)v3 )
    v1->pNode->HashFlags |= 0x8000000u;
  return result;
}

// File Line: 67
// RVA: 0x8D5B40
unsigned int __fastcall Scaleform::GFx::ASConstString::GetCharAt(Scaleform::GFx::ASConstString *this, unsigned int index)
{
  signed int v2; // ebx
  unsigned int result; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  v2 = index;
  if ( this->pNode->HashFlags & 0x8000000 )
    return this->pNode->pData[index];
  putf8Buffer = (char *)this->pNode->pData;
  do
  {
    result = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    --v2;
  }
  while ( v2 >= 0 );
  return result;
}

// File Line: 98
// RVA: 0x8D80A0
unsigned int __fastcall Scaleform::GFx::ASConstString::GetFirstCharAt(Scaleform::GFx::ASConstString *this, unsigned __int64 index, const char **offset)
{
  Scaleform::GFx::ASStringNode *v3; // rax
  const char **v4; // rsi
  signed __int64 v5; // rbx
  char *v6; // rdi
  unsigned int result; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  v3 = this->pNode;
  v4 = offset;
  v5 = index;
  putf8Buffer = (char *)this->pNode->pData;
  v6 = &putf8Buffer[v3->Size];
  while ( 1 )
  {
    result = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    --v5;
    if ( putf8Buffer >= v6 )
      break;
    if ( v5 < 0 )
    {
      *v4 = putf8Buffer;
      return result;
    }
  }
  return result;
}

// File Line: 123
// RVA: 0x8DB6E0
unsigned int __fastcall Scaleform::GFx::ASConstString::GetNextChar(Scaleform::GFx::ASConstString *this, const char **offset)
{
  const char **v2; // rbx
  unsigned int result; // eax

  v2 = offset;
  if ( this->pNode->HashFlags & 0x8000000 )
    return *(*offset)++;
  result = Scaleform::UTF8Util::DecodeNextChar_Advance0(offset);
  if ( !result )
    --*v2;
  return result;
}

// File Line: 137
// RVA: 0x8B63A0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASConstString::AppendCharNode(Scaleform::GFx::ASConstString *this, unsigned int ch)
{
  const char ***v2; // rbx
  unsigned int v3; // edi
  Scaleform::GFx::ASStringNode *result; // rax
  __int64 pindex; // [rsp+40h] [rbp+8h]
  char pbuffer; // [rsp+50h] [rbp+18h]

  v2 = (const char ***)this;
  v3 = ch;
  pindex = 0i64;
  Scaleform::UTF8Util::EncodeCharSafe(&pbuffer, 8ui64, &pindex, ch);
  result = Scaleform::GFx::ASStringManager::CreateStringNode(
             (Scaleform::GFx::ASStringManager *)(*v2)[1],
             **v2,
             *((unsigned int *)*v2 + 8),
             &pbuffer,
             pindex);
  if ( *((_DWORD *)*v2 + 7) & 0x8000000 )
  {
    if ( v3 < 0x80 )
      result->HashFlags |= 0x8000000u;
  }
  return result;
}

// File Line: 162
// RVA: 0x912050
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASConstString::SubstringNode(Scaleform::GFx::ASConstString *this, int start, int end)
{
  Scaleform::GFx::ASStringNode *v3; // rax
  int v4; // esi
  int v5; // er14
  Scaleform::GFx::ASConstString *v6; // r15
  char *v8; // rcx
  int v9; // ebx
  const char *v10; // rdi
  char *v11; // rbp
  unsigned int v12; // eax
  char *putf8Buffer; // [rsp+58h] [rbp+20h]

  v3 = this->pNode;
  v4 = end;
  v5 = start;
  v6 = this;
  if ( start == end )
    return &v3->pManager->EmptyStringNode;
  v8 = (char *)v3->pData;
  v9 = 0;
  putf8Buffer = v8;
  v10 = v8;
  v11 = v8;
  do
  {
    if ( v9 == v5 )
      v10 = v8;
    v12 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    v8 = putf8Buffer;
    if ( !v12 )
      v8 = putf8Buffer-- - 1;
    if ( ++v9 == v4 )
    {
      v11 = v8;
      goto LABEL_14;
    }
  }
  while ( v12 );
  if ( v9 < v4 )
    v11 = v8;
LABEL_14:
  if ( v11 < v10 )
    LODWORD(v11) = (_DWORD)v10;
  return Scaleform::GFx::ASStringManager::CreateStringNode(v6->pNode->pManager, v10, (signed int)v11 - (signed int)v10);
}

// File Line: 212
// RVA: 0x914A40
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASConstString::TruncateWhitespaceNode(Scaleform::GFx::ASConstString *this)
{
  Scaleform::GFx::ASConstString *v1; // rbx
  const char *v2; // rax
  unsigned __int64 v3; // r8
  const char *v4; // rcx
  Scaleform::StringDataPtr result; // [rsp+20h] [rbp-28h]
  Scaleform::StringDataPtr v7; // [rsp+30h] [rbp-18h]

  v1 = this;
  v2 = this->pNode->pData;
  v7.Size = this->pNode->Size;
  v7.pStr = v2;
  Scaleform::StringDataPtr::GetTruncateWhitespace(&v7, &result);
  v3 = result.Size;
  v4 = result.pStr;
  if ( v7.Size != result.Size )
    return Scaleform::GFx::ASStringManager::CreateStringNode(v1->pNode->pManager, v4, v3);
  if ( v7.pStr != result.pStr )
  {
    if ( !result.pStr || !v7.pStr )
      return Scaleform::GFx::ASStringManager::CreateStringNode(v1->pNode->pManager, v4, v3);
    if ( strncmp(result.pStr, v7.pStr, result.Size) )
    {
      v3 = result.Size;
      v4 = result.pStr;
      return Scaleform::GFx::ASStringManager::CreateStringNode(v1->pNode->pManager, v4, v3);
    }
  }
  return v1->pNode;
}

// File Line: 224
// RVA: 0x9130E0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASConstString::ToUpperNode(Scaleform::GFx::ASConstString *this)
{
  Scaleform::GFx::ASConstString *v1; // rdi
  Scaleform::String *v2; // rax
  Scaleform::GFx::ASStringNode *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::String result; // [rsp+40h] [rbp+8h]
  Scaleform::String v6; // [rsp+48h] [rbp+10h]

  v1 = this;
  Scaleform::String::String(&v6, this->pNode->pData, this->pNode->Size);
  Scaleform::String::ToUpper(v2, &result);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v6.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v3 = Scaleform::GFx::ASStringManager::CreateStringNode(
         v1->pNode->pManager,
         (const char *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
         *(_QWORD *)(result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v4 = v3;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
  {
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    v3 = v4;
  }
  return v3;
}

// File Line: 230
// RVA: 0x912DC0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASConstString::ToLowerNode(Scaleform::GFx::ASConstString *this)
{
  Scaleform::GFx::ASConstString *v1; // rbx
  Scaleform::GFx::ASStringNode *v2; // rcx
  Scaleform::GFx::ASStringNode *result; // rax

  v1 = this;
  v2 = this->pNode;
  if ( !v2->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v2);
  result = v1->pNode->pLower;
  if ( !result )
    result = &v1->pNode->pManager->EmptyStringNode;
  return result;
}

// File Line: 239
// RVA: 0x8A8D10
void __fastcall Scaleform::GFx::ASString::operator=(Scaleform::GFx::ASString *this, const char *pstr)
{
  Scaleform::GFx::ASString *v2; // rbx
  unsigned __int64 v3; // r8
  Scaleform::GFx::ASStringNode *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf

  v2 = this;
  v3 = -1i64;
  do
    ++v3;
  while ( pstr[v3] );
  v4 = Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, pstr, v3);
  v5 = v4;
  ++v4->RefCount;
  v6 = v2->pNode;
  v7 = v2->pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    v2->pNode = v5;
  }
  else
  {
    v2->pNode = v4;
  }
}

// File Line: 244
// RVA: 0x8B6340
void __fastcall Scaleform::GFx::ASString::Append(Scaleform::GFx::ASString *this, const char *str, unsigned __int64 len)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf

  v3 = this;
  v4 = Scaleform::GFx::ASStringManager::CreateStringNode(
         this->pNode->pManager,
         this->pNode->pData,
         this->pNode->Size,
         str,
         len);
  v5 = v4;
  ++v4->RefCount;
  v6 = v3->pNode;
  v7 = v3->pNode->RefCount == 1;
  --v6->RefCount;
  if ( v7 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    v3->pNode = v5;
  }
  else
  {
    v3->pNode = v4;
  }
}

// File Line: 250
// RVA: 0x8B62E0
void __fastcall Scaleform::GFx::ASString::Append(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf

  v2 = this;
  v3 = Scaleform::GFx::ASStringManager::CreateStringNode(
         this->pNode->pManager,
         this->pNode->pData,
         this->pNode->Size,
         str->pNode->pData,
         str->pNode->Size);
  v4 = v3;
  ++v3->RefCount;
  v5 = v2->pNode;
  v6 = v2->pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
    v2->pNode = v4;
  }
  else
  {
    v2->pNode = v3;
  }
}

// File Line: 256
// RVA: 0x8A92F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::operator+(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *result, const char *pstr)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rdx
  Scaleform::GFx::ASStringManager *v5; // rcx
  unsigned __int64 l2; // rax
  Scaleform::GFx::ASStringNode *v7; // rax

  v3 = result;
  v4 = this->pNode;
  v5 = this->pNode->pManager;
  l2 = -1i64;
  do
    ++l2;
  while ( pstr[l2] );
  v7 = Scaleform::GFx::ASStringManager::CreateStringNode(v5, v4->pData, v4->Size, pstr, l2);
  v3->pNode = v7;
  ++v7->RefCount;
  return v3;
}

// File Line: 262
// RVA: 0x8A9290
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::operator+(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *result, Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASString *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rax

  v3 = result;
  v4 = Scaleform::GFx::ASStringManager::CreateStringNode(
         this->pNode->pManager,
         this->pNode->pData,
         this->pNode->Size,
         str->pNode->pData,
         str->pNode->Size);
  v3->pNode = v4;
  ++v4->RefCount;
  return v3;
}

// File Line: 284
// RVA: 0x8E9190
__int64 __fastcall Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(Scaleform::GFx::ASConstString *this, const char *pstr, unsigned __int64 len, bool caseSensitive)
{
  bool v4; // r12
  unsigned __int64 v5; // rbx
  const char *v6; // rbp
  const char ***v7; // r15
  Scaleform::GFx::ASStringNode *v8; // rcx
  unsigned int v9; // edi
  unsigned int v10; // eax
  __int64 v11; // r14
  wchar_t *v12; // rsi
  wchar_t *v13; // rdi
  int v14; // eax
  unsigned int v15; // ebx
  char v17; // [rsp+20h] [rbp-418h]
  char v18; // [rsp+220h] [rbp-218h]

  v4 = caseSensitive;
  v5 = len;
  v6 = pstr;
  v7 = (const char ***)this;
  if ( len == -1i64 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( pstr[v5] );
  }
  v8 = this->pNode;
  v9 = v8->Size;
  if ( !(v8->HashFlags & 0x8000000) )
  {
    v10 = Scaleform::UTF8Util::GetLength(v8->pData, v9);
    if ( v10 == v9 )
      *((_DWORD *)*v7 + 7) |= 0x8000000u;
    v9 = v10;
  }
  v11 = v9;
  if ( v9 < 0xFAui64 )
    v12 = (wchar_t *)&v17;
  else
    v12 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2i64 * v9 + 2, 0i64);
  if ( v5 < 0xFA )
    v13 = (wchar_t *)&v18;
  else
    v13 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v5 + 2, 0i64);
  Scaleform::UTF8Util::DecodeStringSafe(v12, v11 + 1, **v7, *((unsigned int *)*v7 + 8));
  Scaleform::UTF8Util::DecodeStringSafe(v13, v5 + 1, v6, v5);
  if ( v4 )
    v14 = wcscoll(v12, v13);
  else
    v14 = wcsicoll(v12, v13);
  v15 = v14;
  if ( v12 != (wchar_t *)&v17 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
  if ( v13 != (wchar_t *)&v18 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
  return v15;
}

// File Line: 322
// RVA: 0x904100
void __fastcall Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(Scaleform::GFx::ASStringNode *this)
{
  Scaleform::GFx::ASStringNode *v1; // rdi
  Scaleform::String *v2; // rax
  Scaleform::GFx::ASStringNode *v3; // rax
  Scaleform::String result; // [rsp+40h] [rbp+8h]
  Scaleform::String v5; // [rsp+48h] [rbp+10h]

  v1 = this;
  Scaleform::String::String(&v5, this->pData, this->Size);
  Scaleform::String::ToLower(v2, &result);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v3 = Scaleform::GFx::ASStringManager::CreateStringNode(
         v1->pManager,
         (const char *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
         *(_QWORD *)(result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  if ( v3 != &v1->pManager->EmptyStringNode )
  {
    v1->pLower = v3;
    if ( v3 != v1 )
      ++v3->RefCount;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 336
// RVA: 0x8FEA00
void __fastcall Scaleform::GFx::ASStringNode::ReleaseNode(Scaleform::GFx::ASStringNode *this)
{
  Scaleform::GFx::ASStringNode *v1; // rbx
  Scaleform::GFx::ASStringNode *v2; // rcx
  bool v3; // zf
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *v4; // rcx
  char *v5; // rdx
  Scaleform::GFx::ASStringManager *v6; // rdi
  Scaleform::GFx::ASStringNode *key; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = this->pLower;
  if ( v2 != v1 )
  {
    if ( v2 )
    {
      v3 = v2->RefCount-- == 1;
      if ( v3 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v2);
    }
  }
  v4 = (Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *)v1->pManager;
  key = v1;
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
    v4 + 2,
    &key);
  v5 = (char *)v1->pData;
  v6 = v1->pManager;
  if ( v1->pData )
  {
    if ( !(v1->HashFlags & 0x40000000) )
    {
      if ( v1->Size >= 0x10 )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      }
      else
      {
        *(_QWORD *)v5 = v6->pFreeTextBuffers;
        v6->pFreeTextBuffers = (Scaleform::GFx::ASStringManager::TextPage::Entry *)v5;
      }
    }
    v1->pData = 0i64;
  }
  v1->pLower = v6->pFreeStringNodes;
  v6->pFreeStringNodes = v1;
}

// File Line: 353
// RVA: 0x894650
void __fastcall Scaleform::GFx::ASStringManager::ASStringManager(Scaleform::GFx::ASStringManager *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::GFx::ASStringManager *v2; // rsi
  Scaleform::GFx::ASStringNode *v3; // rdi
  Scaleform::GFx::ASStringNode *v4; // rcx
  Scaleform::GFx::ASStringNode *key; // [rsp+58h] [rbp+10h]

  v2 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,324>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASStringManager,324>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASStringManager::`vftable';
  v3 = (Scaleform::GFx::ASStringNode *)&this->StringSet;
  key = v3;
  v3->pData = 0i64;
  this->pHeap = pheap;
  this->pLog.pObject = 0i64;
  Scaleform::StringLH::StringLH(&this->FileName);
  v2->pStringNodePages = 0i64;
  v2->pFreeStringNodes = 0i64;
  v2->pFreeTextBuffers = 0i64;
  v2->pTextBufferPages = 0i64;
  v2->EmptyStringNode.RefCount = 1;
  v2->EmptyStringNode.Size = 0;
  v2->EmptyStringNode.HashFlags = Scaleform::String::BernsteinHashFunctionCIS(&customWorldMapCaption, 0i64, 0x1505ui64) & 0xFFFFFF | 0xC8000000;
  v2->EmptyStringNode.pData = &customWorldMapCaption;
  v2->EmptyStringNode.pManager = v2;
  v2->EmptyStringNode.pLower = &v2->EmptyStringNode;
  key = &v2->EmptyStringNode;
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
    (Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *)v3,
    v3,
    &key,
    v2->EmptyStringNode.HashFlags);
  v4 = &v2->NullStringNode;
  v4->pData = v2->EmptyStringNode.pData;
  v4->pManager = v2->EmptyStringNode.pManager;
  v4->pLower = v2->EmptyStringNode.pLower;
  *(_QWORD *)&v4->RefCount = *(_QWORD *)&v2->EmptyStringNode.RefCount;
  *(_QWORD *)&v4->Size = *(_QWORD *)&v2->EmptyStringNode.Size;
  v2->NullStringNode.pLower = &v2->NullStringNode;
}

// File Line: 377
// RVA: 0x8A2E70
void __fastcall Scaleform::GFx::ASStringManager::~ASStringManager(Scaleform::GFx::ASStringManager *this)
{
  Scaleform::GFx::ASStringManager *v1; // rdi
  unsigned int v2; // esi
  Scaleform::GFx::ASStringManager::StringNodePage *v3; // r15
  Scaleform::GFx::ASStringManager::StringNodePage *v4; // rbx
  signed __int64 v5; // rbp
  const char *v6; // rdx
  char *v7; // rdx
  Scaleform::GFx::ASStringManager::TextPage *v8; // rax
  void *v9; // rdx
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v10; // rcx
  char *v11; // r8
  Scaleform::Render::RenderBuffer *v12; // rcx
  void **v13; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *v14; // rax
  __int64 v15; // rcx
  signed __int64 v16; // rdx
  Scaleform::StringBuffer v17; // [rsp+28h] [rbp-60h]

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASStringManager::`vftable';
  Scaleform::StringBuffer::StringBuffer(&v17, Scaleform::Memory::pGlobalHeap);
  v2 = 0;
  while ( v1->pStringNodePages )
  {
    v3 = v1->pStringNodePages;
    v1->pStringNodePages = v3->pNext;
    v4 = v3;
    v5 = 127i64;
    do
    {
      if ( v4->Nodes[0].pData )
      {
        if ( v2 < 0x10 )
        {
          v6 = "'";
          if ( v2 )
            v6 = ", '";
          Scaleform::StringBuffer::AppendString(&v17, v6, -1i64);
          Scaleform::StringBuffer::AppendString(&v17, v4->Nodes[0].pData, -1i64);
          Scaleform::StringBuffer::AppendString(&v17, "'", -1i64);
        }
        ++v2;
        if ( !(v4->Nodes[0].HashFlags & 0x40000000) )
        {
          v7 = (char *)v4->Nodes[0].pData;
          if ( v4->Nodes[0].Size >= 0x10 )
          {
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
          }
          else
          {
            *(_QWORD *)v7 = v1->pFreeTextBuffers;
            v1->pFreeTextBuffers = (Scaleform::GFx::ASStringManager::TextPage::Entry *)v7;
          }
        }
      }
      v4 = (Scaleform::GFx::ASStringManager::StringNodePage *)((char *)v4 + 40);
      --v5;
    }
    while ( v5 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  }
  while ( v1->pTextBufferPages )
  {
    v8 = v1->pTextBufferPages;
    v9 = v8->pMem;
    v1->pTextBufferPages = v8->pNext;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
  }
  if ( v2 )
  {
    v10 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v1->pLog.pObject;
    if ( v10 )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        v10 + 3,
        "ActionScript Memory leaks in movie '%s', including %d string nodes",
        (v1->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
        v2,
        -2i64);
      v11 = &customWorldMapCaption;
      if ( v17.pData )
        v11 = v17.pData;
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v1->pLog.pObject->vfptr,
        "Leaked string content: %s\n",
        v11);
    }
  }
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v17);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((v1->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v12 = (Scaleform::Render::RenderBuffer *)v1->pLog.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v13 = (void **)&v1->StringSet.pTable;
  v14 = v1->StringSet.pTable;
  if ( v14 )
  {
    v15 = 0i64;
    v16 = v14->SizeMask + 1;
    do
    {
      if ( *(_QWORD *)((char *)*v13 + v15 + 16) != -2i64 )
        *(_QWORD *)((char *)*v13 + v15 + 16) = -2i64;
      v15 += 16i64;
      --v16;
    }
    while ( v16 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v13);
    *v13 = 0i64;
  }
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 442
// RVA: 0x8B5E40
void __fastcall Scaleform::GFx::ASStringManager::AllocateStringNodes(Scaleform::GFx::ASStringManager *this)
{
  Scaleform::GFx::ASStringManager *v1; // rbx
  Scaleform::GFx::ASStringManager::StringNodePage *v2; // rax
  signed __int64 v3; // rdx

  v1 = this;
  v2 = (Scaleform::GFx::ASStringManager::StringNodePage *)this->pHeap->vfptr->Alloc(this->pHeap, 5088ui64, 0i64);
  if ( v2 )
  {
    v2->pNext = v1->pStringNodePages;
    v1->pStringNodePages = v2;
    v3 = 127i64;
    do
    {
      v2->Nodes[0].pData = 0i64;
      v2->Nodes[0].pManager = v1;
      v2->Nodes[0].pLower = v1->pFreeStringNodes;
      v1->pFreeStringNodes = (Scaleform::GFx::ASStringNode *)v2;
      v2 = (Scaleform::GFx::ASStringManager::StringNodePage *)((char *)v2 + 40);
      --v3;
    }
    while ( v3 );
  }
}

// File Line: 472
// RVA: 0x8B5F10
void __fastcall Scaleform::GFx::ASStringManager::AllocateTextBuffers(Scaleform::GFx::ASStringManager *this)
{
  Scaleform::GFx::ASStringManager *v1; // rbx
  void *v2; // rax
  unsigned __int64 v3; // rcx
  signed __int64 v4; // r8
  Scaleform::GFx::ASStringManager::TextPage::Entry *v5; // rax
  Scaleform::GFx::ASStringManager::TextPage::Entry *v6; // rdx
  Scaleform::GFx::ASStringManager::TextPage::Entry *v7; // rcx

  v1 = this;
  v2 = this->pHeap->vfptr->Alloc(this->pHeap, 2040ui64, 0i64);
  v3 = ((unsigned __int64)v2 + 7) & 0xFFFFFFFFFFFFFFF8ui64;
  if ( v3 )
  {
    *(_QWORD *)(v3 + 2024) = v2;
    v4 = 21i64;
    *(_QWORD *)(v3 + 2016) = v1->pTextBufferPages;
    v1->pTextBufferPages = (Scaleform::GFx::ASStringManager::TextPage *)v3;
    v5 = (Scaleform::GFx::ASStringManager::TextPage::Entry *)(v3 + 32);
    do
    {
      v5[-2].pNextAlloc = v1->pFreeTextBuffers;
      v5[-1].pNextAlloc = v5 - 2;
      v5->pNextAlloc = v5 - 1;
      v5[1].pNextAlloc = v5;
      v6 = v5 + 2;
      v6->pNextAlloc = v5 + 1;
      v7 = v5 + 3;
      v5 += 6;
      v7->pNextAlloc = v6;
      v1->pFreeTextBuffers = v7;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 541
// RVA: 0x8B5D20
Scaleform::GFx::ASStringManager::TextPage::Entry *__fastcall Scaleform::GFx::ASStringManager::AllocTextBuffer(Scaleform::GFx::ASStringManager *this, const char *pbuffer, unsigned __int64 length)
{
  unsigned __int64 v3; // rsi
  const char *v4; // rbp
  Scaleform::GFx::ASStringManager *v5; // rdi
  Scaleform::GFx::ASStringManager::TextPage::Entry *v6; // rax
  Scaleform::GFx::ASStringManager::TextPage::Entry *v7; // rbx

  v3 = length;
  v4 = pbuffer;
  v5 = this;
  if ( length >= 0x10 )
  {
    v7 = (Scaleform::GFx::ASStringManager::TextPage::Entry *)this->pHeap->vfptr->Alloc(this->pHeap, length + 1, 0i64);
  }
  else
  {
    if ( !this->pFreeTextBuffers )
      Scaleform::GFx::ASStringManager::AllocateTextBuffers(this);
    v6 = v5->pFreeTextBuffers;
    v7 = 0i64;
    if ( v6 )
    {
      v7 = v5->pFreeTextBuffers;
      v5->pFreeTextBuffers = v6->pNextAlloc;
    }
  }
  if ( v7 )
  {
    memmove(v7, v4, v3);
    v7->Buff[v3] = 0;
  }
  return v7;
}

// File Line: 565
// RVA: 0x8BF250
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASStringManager::CreateConstStringNode(Scaleform::GFx::ASStringManager *this, const char *pstr, unsigned __int64 length, unsigned int stringFlags)
{
  unsigned __int64 v4; // r15
  const char *v5; // r12
  Scaleform::GFx::ASStringManager *v6; // rdi
  unsigned int v7; // ebp
  unsigned __int64 v8; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *v9; // r8
  unsigned __int64 v10; // rsi
  signed __int64 v11; // rax
  Scaleform::GFx::ASStringNode *result; // rax
  Scaleform::GFx::ASStringNode *v13; // rbx
  Scaleform::GFx::ASStringKey key; // [rsp+20h] [rbp-48h]
  Scaleform::GFx::ASStringNode *v15; // [rsp+70h] [rbp+8h]

  v4 = length;
  v5 = pstr;
  v6 = this;
  key.pStr = pstr;
  v7 = stringFlags;
  v8 = Scaleform::String::BernsteinHashFunctionCIS(pstr, length, 0x1505ui64);
  v9 = v6->StringSet.pTable;
  key.Length = v4;
  v10 = v8 & 0xFFFFFF;
  key.HashValue = v8 & 0xFFFFFF;
  if ( v9
    && (v11 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
                (Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *)&v6->StringSet.pTable,
                &key,
                v10 & v9->SizeMask),
        v11 >= 0) )
  {
    result = (Scaleform::GFx::ASStringNode *)v6->StringSet.pTable[v11 + 1].SizeMask;
    result->HashFlags |= v7;
  }
  else
  {
    if ( !v6->pFreeStringNodes )
      Scaleform::GFx::ASStringManager::AllocateStringNodes(v6);
    v13 = v6->pFreeStringNodes;
    if ( v13 )
      v6->pFreeStringNodes = v13->pLower;
    v15 = v13;
    if ( v13 )
    {
      v13->RefCount = 0;
      v13->Size = v4;
      v13->pData = v5;
      v13->HashFlags = v7 | v10 | 0x40000000;
      v13->pLower = 0i64;
      Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
        (Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *)&v6->StringSet.pTable,
        &v6->StringSet,
        &v15,
        v13->HashFlags);
      result = v13;
    }
    else
    {
      result = &v6->EmptyStringNode;
    }
  }
  return result;
}

// File Line: 595
// RVA: 0x8C3CD0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASStringManager::CreateStringNode(Scaleform::GFx::ASStringManager *this, const char *pstr, unsigned __int64 length)
{
  unsigned __int64 v3; // rsi
  const char *v4; // rbp
  Scaleform::GFx::ASStringManager *v5; // rdi
  unsigned __int64 v6; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *v7; // r8
  unsigned __int64 v8; // r15
  signed __int64 v9; // rax
  Scaleform::GFx::ASStringNode *v11; // rbx
  Scaleform::GFx::ASStringManager::TextPage::Entry *v12; // rax
  Scaleform::GFx::ASStringKey key; // [rsp+20h] [rbp-38h]
  Scaleform::GFx::ASStringNode *v14; // [rsp+68h] [rbp+10h]

  v3 = length;
  v4 = pstr;
  v5 = this;
  if ( !pstr || !length )
    return &this->EmptyStringNode;
  key.pStr = pstr;
  v6 = Scaleform::String::BernsteinHashFunctionCIS(pstr, length, 0x1505ui64);
  v7 = v5->StringSet.pTable;
  key.Length = v3;
  v8 = v6 & 0xFFFFFF;
  key.HashValue = v6 & 0xFFFFFF;
  if ( v7 )
  {
    v9 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
           (Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *)&v5->StringSet.pTable,
           &key,
           v8 & v7->SizeMask);
    if ( v9 >= 0 )
      return (Scaleform::GFx::ASStringNode *)v5->StringSet.pTable[v9 + 1].SizeMask;
  }
  if ( !v5->pFreeStringNodes )
    Scaleform::GFx::ASStringManager::AllocateStringNodes(v5);
  v11 = v5->pFreeStringNodes;
  if ( v11 )
    v5->pFreeStringNodes = v11->pLower;
  v14 = v11;
  if ( v11 )
  {
    v12 = Scaleform::GFx::ASStringManager::AllocTextBuffer(v5, v4, v3);
    v11->pData = (const char *)v12;
    if ( v12 )
    {
      v11->RefCount = 0;
      v11->Size = v3;
      v11->HashFlags = v8;
      v11->pLower = 0i64;
      Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
        (Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *)&v5->StringSet.pTable,
        &v5->StringSet,
        &v14,
        v11->HashFlags);
      return v11;
    }
    Scaleform::GFx::ASStringManager::FreeStringNode(v5, v11);
  }
  return &v5->EmptyStringNode;
}

// File Line: 629
// RVA: 0x8C3AC0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASStringManager::CreateStringNode(Scaleform::GFx::ASStringManager *this, const char *pstr)
{
  unsigned __int64 v3; // r8

  if ( !pstr )
    return &this->EmptyStringNode;
  v3 = -1i64;
  do
    ++v3;
  while ( pstr[v3] );
  return Scaleform::GFx::ASStringManager::CreateStringNode(this, pstr, v3);
}

// File Line: 637
// RVA: 0x8C3E00
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASStringManager::CreateStringNode(Scaleform::GFx::ASStringManager *this, const wchar_t *pwstr, __int64 len)
{
  __int64 v3; // rbx
  const wchar_t *v4; // rdi
  Scaleform::GFx::ASStringManager *v5; // rsi
  Scaleform::GFx::ASStringNode *result; // rax
  Scaleform::GFx::ASStringNode *v7; // rbx
  Scaleform::String v8; // [rsp+58h] [rbp+20h]

  v3 = len;
  v4 = pwstr;
  v5 = this;
  Scaleform::String::String(&v8);
  Scaleform::String::AppendString(&v8, v4, v3);
  result = Scaleform::GFx::ASStringManager::CreateStringNode(
             v5,
             (const char *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
             *(_QWORD *)(v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v7 = result;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
  {
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    result = v7;
  }
  return result;
}

// File Line: 649
// RVA: 0x8C3AE0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASStringManager::CreateStringNode(Scaleform::GFx::ASStringManager *this, const char *pstr1, unsigned __int64 l1, const char *pstr2, unsigned __int64 l2)
{
  unsigned __int64 v5; // r14
  const char *v6; // r12
  unsigned __int64 v7; // rsi
  unsigned __int64 v8; // rbp
  const char *v9; // r15
  Scaleform::GFx::ASStringManager *v10; // rbx
  Scaleform::GFx::ASStringManager::TextPage::Entry *v11; // rax
  Scaleform::GFx::ASStringManager::TextPage::Entry *v12; // rdi
  unsigned __int64 v13; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *v14; // r8
  unsigned __int64 v15; // r15
  signed __int64 v16; // rax
  unsigned __int64 v17; // rsi
  unsigned __int64 v19; // rsi
  Scaleform::GFx::ASStringKey key; // [rsp+20h] [rbp-38h]

  v5 = l2;
  v6 = pstr2;
  v7 = l1;
  v8 = l1 + l2;
  v9 = pstr1;
  v10 = this;
  if ( l1 + l2 >= 0x10 )
  {
    v12 = (Scaleform::GFx::ASStringManager::TextPage::Entry *)this->pHeap->vfptr->Alloc(this->pHeap, v8 + 1, 0i64);
  }
  else
  {
    if ( !this->pFreeTextBuffers )
      Scaleform::GFx::ASStringManager::AllocateTextBuffers(this);
    v11 = v10->pFreeTextBuffers;
    v12 = 0i64;
    if ( v11 )
    {
      v12 = v10->pFreeTextBuffers;
      v10->pFreeTextBuffers = v11->pNextAlloc;
    }
  }
  if ( !v12 )
    return &v10->EmptyStringNode;
  if ( v9 && v7 )
    memmove(v12, v9, v7);
  if ( v6 && v5 )
    memmove((char *)v12 + v7, v6, v5);
  v12->Buff[v8] = 0;
  key.pStr = (const char *)v12;
  v13 = Scaleform::String::BernsteinHashFunctionCIS(v12, v8, 0x1505ui64);
  v14 = v10->StringSet.pTable;
  key.Length = v8;
  v15 = v13 & 0xFFFFFF;
  key.HashValue = v13 & 0xFFFFFF;
  if ( !v14
    || (v16 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
                (Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *)&v10->StringSet.pTable,
                &key,
                v15 & v14->SizeMask),
        v16 < 0) )
  {
    if ( !v10->pFreeStringNodes )
      Scaleform::GFx::ASStringManager::AllocateStringNodes(v10);
    v19 = (unsigned __int64)v10->pFreeStringNodes;
    if ( v19 )
      v10->pFreeStringNodes = *(Scaleform::GFx::ASStringNode **)(v19 + 16);
    l2 = v19;
    if ( v19 )
    {
      *(_DWORD *)(v19 + 24) = 0;
      *(_DWORD *)(v19 + 32) = v8;
      *(_QWORD *)v19 = v12;
      *(_DWORD *)(v19 + 28) = v15;
      *(_QWORD *)(v19 + 16) = 0i64;
      Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
        (Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > > *)&v10->StringSet.pTable,
        &v10->StringSet,
        (Scaleform::GFx::ASStringNode *const *)&l2,
        *(unsigned int *)(v19 + 28));
      return (Scaleform::GFx::ASStringNode *)v19;
    }
    if ( v8 >= 0x10 )
    {
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
    }
    else
    {
      v12->pNextAlloc = v10->pFreeTextBuffers;
      v10->pFreeTextBuffers = v12;
    }
    return &v10->EmptyStringNode;
  }
  v17 = v10->StringSet.pTable[v16 + 1].SizeMask;
  if ( v8 >= 0x10 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
  }
  else
  {
    v12->pNextAlloc = v10->pFreeTextBuffers;
    v10->pFreeTextBuffers = v12;
  }
  return (Scaleform::GFx::ASStringNode *)v17;
}

// File Line: 739
// RVA: 0x8E3CA0
void __fastcall Scaleform::GFx::ASStringManager::InitBuiltinArray(Scaleform::GFx::ASStringManager *this, Scaleform::GFx::ASStringNodeHolder *nodes, const char **strings, unsigned int count)
{
  Scaleform::GFx::ASStringNodeHolder *v4; // rbx
  Scaleform::GFx::ASStringManager *v5; // rbp
  signed __int64 v6; // rsi
  __int64 v7; // rdi
  const char *v8; // r8
  unsigned __int64 v9; // r9
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-18h]
  __int64 v14; // [rsp+38h] [rbp-10h]

  if ( count )
  {
    v14 = -2i64;
    v4 = nodes;
    v5 = this;
    v6 = (char *)strings - (char *)nodes;
    v7 = count;
    do
    {
      v8 = *(const char **)((char *)&v4->pNode + v6);
      v9 = -1i64;
      do
        ++v9;
      while ( v8[v9] );
      Scaleform::GFx::ASStringManager::CreateConstString(v5, &result, v8, v9, 0x80000000);
      v10 = result.pNode;
      v4->pNode = result.pNode;
      ++v10->RefCount;
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v4->pNode);
      v11 = result.pNode;
      v12 = result.pNode->RefCount == 1;
      --v11->RefCount;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      ++v4;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 752
// RVA: 0x8FE6F0
void __fastcall Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(Scaleform::GFx::ASStringManager *this, Scaleform::GFx::ASStringNodeHolder *nodes, unsigned int count)
{
  Scaleform::GFx::ASStringNodeHolder *v3; // rbx
  __int64 v4; // rdi
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf

  if ( count )
  {
    v3 = nodes;
    v4 = count;
    do
    {
      v5 = v3->pNode;
      v6 = v3->pNode->RefCount == 1;
      --v5->RefCount;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      v3->pNode = 0i64;
      ++v3;
      --v4;
    }
    while ( v4 );
  }
}

