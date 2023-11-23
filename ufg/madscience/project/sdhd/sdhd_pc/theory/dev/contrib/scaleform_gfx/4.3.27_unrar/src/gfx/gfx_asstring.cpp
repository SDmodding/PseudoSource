// File Line: 37
// RVA: 0x8BBF30
void __fastcall Scaleform::GFx::ASString::Clear(Scaleform::GFx::ASString *this)
{
  Scaleform::GFx::ASStringManager *pManager; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // rbx

  pManager = this->pNode->pManager;
  ++pManager->EmptyStringNode.RefCount;
  pNode = this->pNode;
  p_EmptyStringNode = &pManager->EmptyStringNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  this->pNode = p_EmptyStringNode;
}

// File Line: 42
// RVA: 0x8A9360
bool __fastcall Scaleform::GFx::ASString::operator<(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v3; // rdx
  unsigned int Size; // ebx
  const char *pData; // rdx
  size_t v7; // r8
  unsigned int v8; // edi
  const char *v9; // rcx
  int v10; // ecx

  pNode = this->pNode;
  v3 = str->pNode;
  if ( pNode == v3 )
    return 0;
  Size = v3->Size;
  pData = v3->pData;
  v7 = Size;
  v8 = pNode->Size;
  v9 = pNode->pData;
  if ( v8 < Size )
    v7 = v8;
  v10 = memcmp(v9, pData, v7);
  if ( v10 )
    return v10 < 0;
  else
    return v8 < Size;
}

// File Line: 54
// RVA: 0x8DAAC0
__int64 __fastcall Scaleform::GFx::ASConstString::GetLength(Scaleform::GFx::ASConstString *this)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  __int64 Size; // rbx
  __int64 result; // rax

  pNode = this->pNode;
  Size = pNode->Size;
  if ( (pNode->HashFlags & 0x8000000) != 0 )
    return (unsigned int)Size;
  result = Scaleform::UTF8Util::GetLength(pNode->pData, Size);
  if ( (_DWORD)result == (_DWORD)Size )
    this->pNode->HashFlags |= 0x8000000u;
  return result;
}

// File Line: 67
// RVA: 0x8D5B40
unsigned int __fastcall Scaleform::GFx::ASConstString::GetCharAt(Scaleform::GFx::ASConstString *this, int index)
{
  int v2; // ebx
  unsigned int result; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h] BYREF

  v2 = index;
  if ( (this->pNode->HashFlags & 0x8000000) != 0 )
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
unsigned int __fastcall Scaleform::GFx::ASConstString::GetFirstCharAt(
        Scaleform::GFx::ASConstString *this,
        __int64 index,
        char **offset)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  char *v6; // rdi
  unsigned int result; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h] BYREF

  pNode = this->pNode;
  putf8Buffer = (char *)this->pNode->pData;
  v6 = &putf8Buffer[pNode->Size];
  while ( 1 )
  {
    result = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    --index;
    if ( putf8Buffer >= v6 )
      break;
    if ( index < 0 )
    {
      *offset = putf8Buffer;
      return result;
    }
  }
  return result;
}

// File Line: 123
// RVA: 0x8DB6E0
unsigned int __fastcall Scaleform::GFx::ASConstString::GetNextChar(
        Scaleform::GFx::ASConstString *this,
        const char **offset)
{
  unsigned int result; // eax

  if ( (this->pNode->HashFlags & 0x8000000) != 0 )
  {
    return *(*offset)++;
  }
  else
  {
    result = Scaleform::UTF8Util::DecodeNextChar_Advance0(offset);
    if ( !result )
      --*offset;
  }
  return result;
}

// File Line: 137
// RVA: 0x8B63A0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASConstString::AppendCharNode(
        Scaleform::GFx::ASConstString *this,
        unsigned int ch)
{
  Scaleform::GFx::ASStringNode *result; // rax
  __int64 pindex; // [rsp+40h] [rbp+8h] BYREF
  char pbuffer; // [rsp+50h] [rbp+18h] BYREF

  pindex = 0i64;
  Scaleform::UTF8Util::EncodeCharSafe(&pbuffer, 8ui64, &pindex, ch);
  result = Scaleform::GFx::ASStringManager::CreateStringNode(
             this->pNode->pManager,
             this->pNode->pData,
             this->pNode->Size,
             &pbuffer,
             pindex);
  if ( (this->pNode->HashFlags & 0x8000000) != 0 && ch < 0x80 )
    result->HashFlags |= 0x8000000u;
  return result;
}

// File Line: 162
// RVA: 0x912050
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASConstString::SubstringNode(
        Scaleform::GFx::ASConstString *this,
        int start,
        int end)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  char *pData; // rcx
  int v9; // ebx
  const char *v10; // rdi
  char *v11; // rbp
  unsigned int Char_Advance0; // eax
  char *putf8Buffer; // [rsp+58h] [rbp+20h] BYREF

  pNode = this->pNode;
  if ( start == end )
    return &pNode->pManager->EmptyStringNode;
  pData = (char *)pNode->pData;
  v9 = 0;
  putf8Buffer = pData;
  v10 = pData;
  v11 = pData;
  do
  {
    if ( v9 == start )
      v10 = pData;
    Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    pData = putf8Buffer;
    if ( !Char_Advance0 )
      pData = --putf8Buffer;
    if ( ++v9 == end )
    {
      v11 = pData;
      goto LABEL_14;
    }
  }
  while ( Char_Advance0 );
  if ( v9 < end )
    v11 = pData;
LABEL_14:
  if ( v11 < v10 )
    LODWORD(v11) = (_DWORD)v10;
  return Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, v10, (int)v11 - (int)v10);
}

// File Line: 212
// RVA: 0x914A40
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASConstString::TruncateWhitespaceNode(
        Scaleform::GFx::ASConstString *this)
{
  const char *pData; // rax
  unsigned __int64 Size; // r8
  const char *pStr; // rcx
  Scaleform::StringDataPtr result; // [rsp+20h] [rbp-28h] BYREF
  Scaleform::StringDataPtr v7; // [rsp+30h] [rbp-18h] BYREF

  pData = this->pNode->pData;
  v7.Size = this->pNode->Size;
  v7.pStr = pData;
  Scaleform::StringDataPtr::GetTruncateWhitespace(&v7, &result);
  Size = result.Size;
  pStr = result.pStr;
  if ( v7.Size != result.Size )
    return Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, pStr, Size);
  if ( v7.pStr != result.pStr )
  {
    if ( !result.pStr || !v7.pStr )
      return Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, pStr, Size);
    if ( strncmp(result.pStr, v7.pStr, result.Size) )
    {
      Size = result.Size;
      pStr = result.pStr;
      return Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, pStr, Size);
    }
  }
  return this->pNode;
}

// File Line: 224
// RVA: 0x9130E0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASConstString::ToUpperNode(
        Scaleform::GFx::ASConstString *this)
{
  Scaleform::String *v2; // rax
  Scaleform::GFx::ASStringNode *StringNode; // rax
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::String result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::String v6; // [rsp+48h] [rbp+10h] BYREF

  Scaleform::String::String(&v6, this->pNode->pData, this->pNode->Size);
  Scaleform::String::ToUpper(v2, &result);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v6.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 (const char *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                 *(_QWORD *)(result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v4 = StringNode;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    return v4;
  }
  return StringNode;
}

// File Line: 230
// RVA: 0x912DC0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASConstString::ToLowerNode(
        Scaleform::GFx::ASConstString *this)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *result; // rax

  pNode = this->pNode;
  if ( !pNode->pLower )
    Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(pNode);
  result = this->pNode->pLower;
  if ( !result )
    return &this->pNode->pManager->EmptyStringNode;
  return result;
}

// File Line: 239
// RVA: 0x8A8D10
void __fastcall Scaleform::GFx::ASString::operator=(Scaleform::GFx::ASString *this, const char *pstr)
{
  unsigned __int64 v3; // r8
  Scaleform::GFx::ASStringNode *StringNode; // rax
  Scaleform::GFx::ASStringNode *v5; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx

  v3 = -1i64;
  do
    ++v3;
  while ( pstr[v3] );
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(this->pNode->pManager, pstr, v3);
  v5 = StringNode;
  ++StringNode->RefCount;
  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    this->pNode = v5;
  }
  else
  {
    this->pNode = StringNode;
  }
}

// File Line: 244
// RVA: 0x8B6340
void __fastcall Scaleform::GFx::ASString::Append(Scaleform::GFx::ASString *this, const char *str, unsigned __int64 len)
{
  Scaleform::GFx::ASStringNode *StringNode; // rax
  Scaleform::GFx::ASStringNode *v5; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 this->pNode->pData,
                 this->pNode->Size,
                 str,
                 len);
  v5 = StringNode;
  ++StringNode->RefCount;
  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    this->pNode = v5;
  }
  else
  {
    this->pNode = StringNode;
  }
}

// File Line: 250
// RVA: 0x8B62E0
void __fastcall Scaleform::GFx::ASString::Append(Scaleform::GFx::ASString *this, Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // rax
  Scaleform::GFx::ASStringNode *v4; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 this->pNode->pData,
                 this->pNode->Size,
                 str->pNode->pData,
                 str->pNode->Size);
  v4 = StringNode;
  ++StringNode->RefCount;
  pNode = this->pNode;
  if ( this->pNode->RefCount-- == 1 )
  {
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    this->pNode = v4;
  }
  else
  {
    this->pNode = StringNode;
  }
}

// File Line: 256
// RVA: 0x8A92F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::operator+(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result,
        const char *pstr)
{
  Scaleform::GFx::ASStringNode *pNode; // rdx
  Scaleform::GFx::ASStringManager *pManager; // rcx
  unsigned __int64 l2; // rax
  Scaleform::GFx::ASStringNode *StringNode; // rax

  pNode = this->pNode;
  pManager = this->pNode->pManager;
  l2 = -1i64;
  do
    ++l2;
  while ( pstr[l2] );
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(pManager, pNode->pData, pNode->Size, pstr, l2);
  result->pNode = StringNode;
  ++StringNode->RefCount;
  return result;
}

// File Line: 262
// RVA: 0x8A9290
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::ASString::operator+(
        Scaleform::GFx::ASString *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *StringNode; // rax

  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pNode->pManager,
                 this->pNode->pData,
                 this->pNode->Size,
                 str->pNode->pData,
                 str->pNode->Size);
  result->pNode = StringNode;
  ++StringNode->RefCount;
  return result;
}

// File Line: 284
// RVA: 0x8E9190
__int64 __fastcall Scaleform::GFx::ASConstString::LocaleCompare_CaseCheck(
        Scaleform::GFx::ASConstString *this,
        const char *pstr,
        unsigned __int64 len,
        bool caseSensitive)
{
  unsigned __int64 v5; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int Size; // edi
  unsigned int Length; // eax
  __int64 v11; // r14
  wchar_t *v12; // rsi
  wchar_t *v13; // rdi
  int v14; // eax
  unsigned int v15; // ebx
  char v17[512]; // [rsp+20h] [rbp-418h] BYREF
  char v18[512]; // [rsp+220h] [rbp-218h] BYREF

  v5 = len;
  if ( len == -1i64 )
  {
    v5 = -1i64;
    do
      ++v5;
    while ( pstr[v5] );
  }
  pNode = this->pNode;
  Size = pNode->Size;
  if ( (pNode->HashFlags & 0x8000000) == 0 )
  {
    Length = Scaleform::UTF8Util::GetLength(pNode->pData, Size);
    if ( Length == Size )
      this->pNode->HashFlags |= 0x8000000u;
    Size = Length;
  }
  v11 = Size;
  if ( Size < 0xFAui64 )
    v12 = (wchar_t *)v17;
  else
    v12 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2i64 * Size + 2, 0i64);
  if ( v5 < 0xFA )
    v13 = (wchar_t *)v18;
  else
    v13 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v5 + 2, 0i64);
  Scaleform::UTF8Util::DecodeStringSafe(v12, v11 + 1, this->pNode->pData, this->pNode->Size);
  Scaleform::UTF8Util::DecodeStringSafe(v13, v5 + 1, pstr, v5);
  if ( caseSensitive )
    v14 = wcscoll(v12, v13);
  else
    v14 = wcsicoll(v12, v13);
  v15 = v14;
  if ( v12 != (wchar_t *)v17 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
  if ( v13 != (wchar_t *)v18 )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v13);
  return v15;
}

// File Line: 322
// RVA: 0x904100
void __fastcall Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(Scaleform::GFx::ASStringNode *this)
{
  Scaleform::String *v2; // rax
  Scaleform::GFx::ASStringNode *StringNode; // rax
  Scaleform::String result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::String v5; // [rsp+48h] [rbp+10h] BYREF

  Scaleform::String::String(&v5, this->pData, this->Size);
  Scaleform::String::ToLower(v2, &result);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v5.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  StringNode = Scaleform::GFx::ASStringManager::CreateStringNode(
                 this->pManager,
                 (const char *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                 *(_QWORD *)(result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  if ( StringNode != &this->pManager->EmptyStringNode )
  {
    this->pLower = StringNode;
    if ( StringNode != this )
      ++StringNode->RefCount;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 336
// RVA: 0x8FEA00
void __fastcall Scaleform::GFx::ASStringNode::ReleaseNode(Scaleform::GFx::ASStringNode *this)
{
  Scaleform::GFx::ASStringNode *pLower; // rcx
  Scaleform::GFx::ASStringManager *pManager; // rcx
  char *pData; // rdx
  Scaleform::GFx::ASStringManager *v6; // rdi
  Scaleform::GFx::ASStringNode *key; // [rsp+30h] [rbp+8h] BYREF

  pLower = this->pLower;
  if ( pLower != this )
  {
    if ( pLower )
    {
      if ( pLower->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pLower);
    }
  }
  pManager = this->pManager;
  key = this;
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::RemoveAlt<Scaleform::GFx::ASStringNode *>(
    &pManager->StringSet,
    &key);
  pData = (char *)this->pData;
  v6 = this->pManager;
  if ( this->pData )
  {
    if ( (this->HashFlags & 0x40000000) == 0 )
    {
      if ( this->Size >= 0x10 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      }
      else
      {
        *(_QWORD *)pData = v6->pFreeTextBuffers;
        v6->pFreeTextBuffers = (Scaleform::GFx::ASStringManager::TextPage::Entry *)pData;
      }
    }
    this->pData = 0i64;
  }
  this->pLower = v6->pFreeStringNodes;
  v6->pFreeStringNodes = this;
}

// File Line: 353
// RVA: 0x894650
void __fastcall Scaleform::GFx::ASStringManager::ASStringManager(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::HashSetUncachedLH<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,324> *p_StringSet; // rdi
  Scaleform::GFx::ASStringNode *key; // [rsp+58h] [rbp+10h] BYREF

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,324>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASStringManager,324>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASStringManager::`vftable;
  p_StringSet = &this->StringSet;
  key = (Scaleform::GFx::ASStringNode *)&this->StringSet;
  this->StringSet.pTable = 0i64;
  this->pHeap = pheap;
  this->pLog.pObject = 0i64;
  Scaleform::StringLH::StringLH(&this->FileName);
  this->pStringNodePages = 0i64;
  this->pFreeStringNodes = 0i64;
  this->pFreeTextBuffers = 0i64;
  this->pTextBufferPages = 0i64;
  this->EmptyStringNode.RefCount = 1;
  this->EmptyStringNode.Size = 0;
  this->EmptyStringNode.HashFlags = Scaleform::String::BernsteinHashFunctionCIS(&customCaption, 0i64, 0x1505ui64) & 0xFFFFFF | 0xC8000000;
  this->EmptyStringNode.pData = &customCaption;
  this->EmptyStringNode.pManager = this;
  this->EmptyStringNode.pLower = &this->EmptyStringNode;
  key = &this->EmptyStringNode;
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
    p_StringSet,
    p_StringSet,
    &key,
    this->EmptyStringNode.HashFlags);
  this->NullStringNode = this->EmptyStringNode;
  this->NullStringNode.pLower = &this->NullStringNode;
}

// File Line: 377
// RVA: 0x8A2E70
void __fastcall Scaleform::GFx::ASStringManager::~ASStringManager(Scaleform::GFx::ASStringManager *this)
{
  unsigned int v2; // esi
  Scaleform::GFx::ASStringManager::StringNodePage *pStringNodePages; // r15
  Scaleform::GFx::ASStringManager::StringNodePage *v4; // rbx
  __int64 v5; // rbp
  const char *v6; // rdx
  Scaleform::GFx::ASStringManager::TextPage::Entry *pData; // rdx
  Scaleform::GFx::ASStringManager::TextPage *pTextBufferPages; // rax
  void *pMem; // rdx
  Scaleform::GFx::LogState *pObject; // rcx
  char *v11; // r8
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::HashSetUncachedLH<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,324> *p_StringSet; // rbx
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *pTable; // rax
  __int64 v15; // rcx
  __int64 v16; // rdx
  Scaleform::StringBuffer v17; // [rsp+28h] [rbp-60h] BYREF

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASStringManager::`vftable;
  Scaleform::StringBuffer::StringBuffer(&v17, Scaleform::Memory::pGlobalHeap);
  v2 = 0;
  while ( this->pStringNodePages )
  {
    pStringNodePages = this->pStringNodePages;
    this->pStringNodePages = pStringNodePages->pNext;
    v4 = pStringNodePages;
    v5 = 127i64;
    do
    {
      if ( v4->Nodes[0].pData )
      {
        if ( v2 < 0x10 )
        {
          v6 = "";
          if ( v2 )
            v6 = ", ";
          Scaleform::StringBuffer::AppendString(&v17, v6, -1i64);
          Scaleform::StringBuffer::AppendString(&v17, v4->Nodes[0].pData, -1i64);
          Scaleform::StringBuffer::AppendString(&v17, "", -1i64);
        }
        ++v2;
        if ( (v4->Nodes[0].HashFlags & 0x40000000) == 0 )
        {
          pData = (Scaleform::GFx::ASStringManager::TextPage::Entry *)v4->Nodes[0].pData;
          if ( v4->Nodes[0].Size >= 0x10 )
          {
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pData);
          }
          else
          {
            pData->pNextAlloc = this->pFreeTextBuffers;
            this->pFreeTextBuffers = pData;
          }
        }
      }
      v4 = (Scaleform::GFx::ASStringManager::StringNodePage *)((char *)v4 + 40);
      --v5;
    }
    while ( v5 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pStringNodePages);
  }
  while ( this->pTextBufferPages )
  {
    pTextBufferPages = this->pTextBufferPages;
    pMem = pTextBufferPages->pMem;
    this->pTextBufferPages = pTextBufferPages->pNext;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pMem);
  }
  if ( v2 )
  {
    pObject = this->pLog.pObject;
    if ( pObject )
    {
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        &pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "ActionScript Memory leaks in movie %s, including %d string nodes",
        (const char *)((this->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
        v2);
      v11 = &customCaption;
      if ( v17.pData )
        v11 = v17.pData;
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogScriptError(
        &this->pLog.pObject->Scaleform::GFx::LogBase<Scaleform::GFx::LogState>,
        "Leaked string content: %s\n",
        v11);
    }
  }
  Scaleform::ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::MsgFormat::fmt_record,Scaleform::AllocatorGH_POD<Scaleform::MsgFormat::fmt_record,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<int,Scaleform::AllocatorGH<int,2>,Scaleform::ArrayDefaultPolicy> *)&v17);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((this->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v12 = (Scaleform::Render::RenderBuffer *)this->pLog.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  p_StringSet = &this->StringSet;
  pTable = this->StringSet.pTable;
  if ( pTable )
  {
    v15 = 0i64;
    v16 = pTable->SizeMask + 1;
    do
    {
      if ( p_StringSet->pTable[v15 + 1].EntryCount != -2i64 )
        p_StringSet->pTable[v15 + 1].EntryCount = -2i64;
      ++v15;
      --v16;
    }
    while ( v16 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_StringSet->pTable);
    p_StringSet->pTable = 0i64;
  }
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 442
// RVA: 0x8B5E40
void __fastcall Scaleform::GFx::ASStringManager::AllocateStringNodes(Scaleform::GFx::ASStringManager *this)
{
  Scaleform::GFx::ASStringManager::StringNodePage *v2; // rax
  __int64 v3; // rdx

  v2 = (Scaleform::GFx::ASStringManager::StringNodePage *)this->pHeap->vfptr->Alloc(this->pHeap, 5088i64, 0i64);
  if ( v2 )
  {
    v2->pNext = this->pStringNodePages;
    this->pStringNodePages = v2;
    v3 = 127i64;
    do
    {
      v2->Nodes[0].pData = 0i64;
      v2->Nodes[0].pManager = this;
      v2->Nodes[0].pLower = this->pFreeStringNodes;
      this->pFreeStringNodes = (Scaleform::GFx::ASStringNode *)v2;
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
  void *v2; // rax
  Scaleform::GFx::ASStringManager::TextPage *v3; // rcx
  __int64 v4; // r8
  Scaleform::GFx::ASStringManager::TextPage::Entry *v5; // rax
  Scaleform::GFx::ASStringManager::TextPage::Entry *v6; // rdx
  Scaleform::GFx::ASStringManager::TextPage::Entry *v7; // rcx

  v2 = this->pHeap->vfptr->Alloc(this->pHeap, 2040i64, 0i64);
  v3 = (Scaleform::GFx::ASStringManager::TextPage *)(((unsigned __int64)v2 + 7) & 0xFFFFFFFFFFFFFFF8ui64);
  if ( v3 )
  {
    v3->pMem = v2;
    v4 = 21i64;
    v3->pNext = this->pTextBufferPages;
    this->pTextBufferPages = v3;
    v5 = &v3->Entries[2];
    do
    {
      v5[-2].pNextAlloc = this->pFreeTextBuffers;
      v5[-1].pNextAlloc = v5 - 2;
      v5->pNextAlloc = v5 - 1;
      v5[1].pNextAlloc = v5;
      v6 = v5 + 2;
      v5[2].pNextAlloc = v5 + 1;
      v7 = v5 + 3;
      v5 += 6;
      v7->pNextAlloc = v6;
      this->pFreeTextBuffers = v7;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 541
// RVA: 0x8B5D20
Scaleform::GFx::ASStringManager::TextPage::Entry *__fastcall Scaleform::GFx::ASStringManager::AllocTextBuffer(
        Scaleform::GFx::ASStringManager *this,
        const char *pbuffer,
        size_t length)
{
  Scaleform::GFx::ASStringManager::TextPage::Entry *pFreeTextBuffers; // rax
  Scaleform::GFx::ASStringManager::TextPage::Entry *v7; // rbx

  if ( length >= 0x10 )
  {
    v7 = (Scaleform::GFx::ASStringManager::TextPage::Entry *)this->pHeap->vfptr->Alloc(this->pHeap, length + 1, 0i64);
  }
  else
  {
    if ( !this->pFreeTextBuffers )
      Scaleform::GFx::ASStringManager::AllocateTextBuffers(this);
    pFreeTextBuffers = this->pFreeTextBuffers;
    v7 = 0i64;
    if ( pFreeTextBuffers )
    {
      v7 = this->pFreeTextBuffers;
      this->pFreeTextBuffers = pFreeTextBuffers->pNextAlloc;
    }
  }
  if ( v7 )
  {
    memmove(v7, pbuffer, length);
    v7->Buff[length] = 0;
  }
  return v7;
}

// File Line: 565
// RVA: 0x8BF250
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASStringManager::CreateConstStringNode(
        Scaleform::GFx::ASStringManager *this,
        const char *pstr,
        unsigned __int64 length,
        unsigned int stringFlags)
{
  unsigned __int64 v8; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *pTable; // r8
  unsigned __int64 v10; // rsi
  signed __int64 v11; // rax
  Scaleform::GFx::ASStringNode *result; // rax
  Scaleform::GFx::ASStringNode *pFreeStringNodes; // rbx
  Scaleform::GFx::ASStringKey key; // [rsp+20h] [rbp-48h] BYREF
  Scaleform::GFx::ASStringNode *v15; // [rsp+70h] [rbp+8h] BYREF

  key.pStr = pstr;
  v8 = Scaleform::String::BernsteinHashFunctionCIS(pstr, length, 0x1505ui64);
  pTable = this->StringSet.pTable;
  key.Length = length;
  v10 = v8 & 0xFFFFFF;
  key.HashValue = v10;
  if ( pTable
    && (v11 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
                &this->StringSet,
                &key,
                v10 & pTable->SizeMask),
        v11 >= 0) )
  {
    result = (Scaleform::GFx::ASStringNode *)this->StringSet.pTable[v11 + 1].SizeMask;
    result->HashFlags |= stringFlags;
  }
  else
  {
    if ( !this->pFreeStringNodes )
      Scaleform::GFx::ASStringManager::AllocateStringNodes(this);
    pFreeStringNodes = this->pFreeStringNodes;
    if ( pFreeStringNodes )
      this->pFreeStringNodes = pFreeStringNodes->pLower;
    v15 = pFreeStringNodes;
    if ( pFreeStringNodes )
    {
      pFreeStringNodes->RefCount = 0;
      pFreeStringNodes->Size = length;
      pFreeStringNodes->pData = pstr;
      pFreeStringNodes->HashFlags = stringFlags | v10 | 0x40000000;
      pFreeStringNodes->pLower = 0i64;
      Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
        &this->StringSet,
        &this->StringSet,
        &v15,
        pFreeStringNodes->HashFlags);
      return pFreeStringNodes;
    }
    else
    {
      return &this->EmptyStringNode;
    }
  }
  return result;
}

// File Line: 595
// RVA: 0x8C3CD0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        const char *pstr,
        unsigned __int64 length)
{
  unsigned __int64 v6; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *pTable; // r8
  unsigned __int64 v8; // r15
  signed __int64 v9; // rax
  Scaleform::GFx::ASStringNode *pFreeStringNodes; // rbx
  Scaleform::GFx::ASStringManager::TextPage::Entry *v12; // rax
  Scaleform::GFx::ASStringKey key; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::GFx::ASStringNode *v14; // [rsp+68h] [rbp+10h] BYREF

  if ( !pstr || !length )
    return &this->EmptyStringNode;
  key.pStr = pstr;
  v6 = Scaleform::String::BernsteinHashFunctionCIS(pstr, length, 0x1505ui64);
  pTable = this->StringSet.pTable;
  key.Length = length;
  v8 = v6 & 0xFFFFFF;
  key.HashValue = v8;
  if ( pTable )
  {
    v9 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
           &this->StringSet,
           &key,
           v8 & pTable->SizeMask);
    if ( v9 >= 0 )
      return (Scaleform::GFx::ASStringNode *)this->StringSet.pTable[v9 + 1].SizeMask;
  }
  if ( !this->pFreeStringNodes )
    Scaleform::GFx::ASStringManager::AllocateStringNodes(this);
  pFreeStringNodes = this->pFreeStringNodes;
  if ( pFreeStringNodes )
    this->pFreeStringNodes = pFreeStringNodes->pLower;
  v14 = pFreeStringNodes;
  if ( !pFreeStringNodes )
    return &this->EmptyStringNode;
  v12 = Scaleform::GFx::ASStringManager::AllocTextBuffer(this, pstr, length);
  pFreeStringNodes->pData = (const char *)v12;
  if ( !v12 )
  {
    Scaleform::GFx::ASStringManager::FreeStringNode(this, pFreeStringNodes);
    return &this->EmptyStringNode;
  }
  pFreeStringNodes->RefCount = 0;
  pFreeStringNodes->Size = length;
  pFreeStringNodes->HashFlags = v8;
  pFreeStringNodes->pLower = 0i64;
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
    &this->StringSet,
    &this->StringSet,
    &v14,
    pFreeStringNodes->HashFlags);
  return pFreeStringNodes;
}

// File Line: 629
// RVA: 0x8C3AC0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        const char *pstr)
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
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        const wchar_t *pwstr,
        __int64 len)
{
  Scaleform::GFx::ASStringNode *result; // rax
  Scaleform::GFx::ASStringNode *v7; // rbx
  Scaleform::String v8; // [rsp+58h] [rbp+20h] BYREF

  Scaleform::String::String(&v8);
  Scaleform::String::AppendString(&v8, pwstr, len);
  result = Scaleform::GFx::ASStringManager::CreateStringNode(
             this,
             (const char *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
             *(_QWORD *)(v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  v7 = result;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v8.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    return v7;
  }
  return result;
}

// File Line: 649
// RVA: 0x8C3AE0
Scaleform::GFx::ASStringNode *__fastcall Scaleform::GFx::ASStringManager::CreateStringNode(
        Scaleform::GFx::ASStringManager *this,
        const char *pstr1,
        size_t l1,
        const char *pstr2,
        Scaleform::GFx::ASStringNode *l2)
{
  size_t v5; // r14
  unsigned __int64 v8; // rbp
  Scaleform::GFx::ASStringManager::TextPage::Entry *pFreeTextBuffers; // rax
  Scaleform::GFx::ASStringManager::TextPage::Entry *v12; // rdi
  unsigned __int64 v13; // rax
  Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *> > >::TableType *pTable; // r8
  unsigned __int64 v15; // r15
  signed __int64 v16; // rax
  unsigned __int64 SizeMask; // rsi
  Scaleform::GFx::ASStringNode *pFreeStringNodes; // rsi
  Scaleform::GFx::ASStringKey key; // [rsp+20h] [rbp-38h] BYREF

  v5 = (size_t)l2;
  v8 = (unsigned __int64)l2 + l1;
  if ( (unsigned __int64)l2 + l1 >= 0x10 )
  {
    v12 = (Scaleform::GFx::ASStringManager::TextPage::Entry *)this->pHeap->vfptr->Alloc(this->pHeap, v8 + 1, 0i64);
  }
  else
  {
    if ( !this->pFreeTextBuffers )
      Scaleform::GFx::ASStringManager::AllocateTextBuffers(this);
    pFreeTextBuffers = this->pFreeTextBuffers;
    v12 = 0i64;
    if ( pFreeTextBuffers )
    {
      v12 = this->pFreeTextBuffers;
      this->pFreeTextBuffers = pFreeTextBuffers->pNextAlloc;
    }
  }
  if ( !v12 )
    return &this->EmptyStringNode;
  if ( pstr1 && l1 )
    memmove(v12, pstr1, l1);
  if ( pstr2 && v5 )
    memmove((char *)v12 + l1, pstr2, v5);
  v12->Buff[v8] = 0;
  key.pStr = (const char *)v12;
  v13 = Scaleform::String::BernsteinHashFunctionCIS(v12, v8, 0x1505ui64);
  pTable = this->StringSet.pTable;
  key.Length = v8;
  v15 = v13 & 0xFFFFFF;
  key.HashValue = v15;
  if ( !pTable
    || (v16 = Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::findIndexCore<Scaleform::GFx::ASStringKey>(
                &this->StringSet,
                &key,
                v15 & pTable->SizeMask),
        v16 < 0) )
  {
    if ( !this->pFreeStringNodes )
      Scaleform::GFx::ASStringManager::AllocateStringNodes(this);
    pFreeStringNodes = this->pFreeStringNodes;
    if ( pFreeStringNodes )
      this->pFreeStringNodes = pFreeStringNodes->pLower;
    l2 = pFreeStringNodes;
    if ( pFreeStringNodes )
    {
      pFreeStringNodes->RefCount = 0;
      pFreeStringNodes->Size = v8;
      pFreeStringNodes->pData = (const char *)v12;
      pFreeStringNodes->HashFlags = v15;
      pFreeStringNodes->pLower = 0i64;
      Scaleform::HashSetBase<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>,Scaleform::AllocatorLH<Scaleform::GFx::ASStringNode *,324>,Scaleform::HashsetEntry<Scaleform::GFx::ASStringNode *,Scaleform::GFx::ASStringNodeHashFunc<Scaleform::GFx::ASStringNode *>>>::add<Scaleform::GFx::ASStringNode *>(
        &this->StringSet,
        &this->StringSet,
        &l2,
        pFreeStringNodes->HashFlags);
      return pFreeStringNodes;
    }
    if ( v8 >= 0x10 )
    {
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
    }
    else
    {
      v12->pNextAlloc = this->pFreeTextBuffers;
      this->pFreeTextBuffers = v12;
    }
    return &this->EmptyStringNode;
  }
  SizeMask = this->StringSet.pTable[v16 + 1].SizeMask;
  if ( v8 >= 0x10 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
  }
  else
  {
    v12->pNextAlloc = this->pFreeTextBuffers;
    this->pFreeTextBuffers = v12;
  }
  return (Scaleform::GFx::ASStringNode *)SizeMask;
}

// File Line: 739
// RVA: 0x8E3CA0
void __fastcall Scaleform::GFx::ASStringManager::InitBuiltinArray(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASStringNodeHolder *nodes,
        const char **strings,
        unsigned int count)
{
  Scaleform::GFx::ASStringNodeHolder *v4; // rbx
  signed __int64 v6; // rsi
  __int64 v7; // rdi
  const char *v8; // r8
  unsigned __int64 v9; // r9
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString result; // [rsp+30h] [rbp-18h] BYREF
  __int64 v14; // [rsp+38h] [rbp-10h]

  if ( count )
  {
    v14 = -2i64;
    v4 = nodes;
    v6 = (char *)strings - (char *)nodes;
    v7 = count;
    do
    {
      v8 = *(const char **)((char *)&v4->pNode + v6);
      v9 = -1i64;
      do
        ++v9;
      while ( v8[v9] );
      Scaleform::GFx::ASStringManager::CreateConstString(this, &result, v8, v9, 0x80000000);
      pNode = result.pNode;
      v4->pNode = result.pNode;
      ++pNode->RefCount;
      Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v4->pNode);
      v11 = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      ++v4;
      --v7;
    }
    while ( v7 );
  }
}

// File Line: 752
// RVA: 0x8FE6F0
void __fastcall Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(
        Scaleform::GFx::ASStringManager *this,
        Scaleform::GFx::ASStringNodeHolder *nodes,
        unsigned int count)
{
  __int64 v4; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx

  if ( count )
  {
    v4 = count;
    do
    {
      pNode = nodes->pNode;
      if ( nodes->pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      nodes->pNode = 0i64;
      ++nodes;
      --v4;
    }
    while ( v4 );
  }
}

