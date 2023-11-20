// File Line: 24
// RVA: 0x985280
unsigned __int64 __fastcall Scaleform::Render::Text::HTMLImageTagDesc::GetHash(Scaleform::Render::Text::HTMLImageTagDesc *this)
{
  Scaleform::Render::Text::HTMLImageTagDesc *v1; // r11
  signed __int64 v2; // rdx
  unsigned __int64 v3; // rax
  signed __int64 v4; // r8
  __int64 v5; // rcx
  unsigned __int64 v6; // r9
  _QWORD *v7; // rcx
  signed __int64 i; // r10
  int v9; // edx
  unsigned __int64 v10; // r9
  _QWORD *v11; // rcx
  signed __int64 j; // r8
  int v13; // edx
  char v15; // [rsp+1h] [rbp-29h]
  __int64 v16; // [rsp+2h] [rbp-28h]
  __int64 v17; // [rsp+Ah] [rbp-20h]
  __int64 v18; // [rsp+12h] [rbp-18h]
  __int64 v19; // [rsp+1Ah] [rbp-10h]

  v1 = this;
  v2 = 32i64;
  v16 = this->VSpace;
  v17 = this->HSpace;
  v18 = this->ParaId;
  v19 = (unsigned __int8)this->Alignment;
  v3 = 5381i64;
  v4 = 5381i64;
  do
  {
    v5 = (unsigned __int8)*(&v15 + v2--);
    v4 = v5 + 65599 * v4;
  }
  while ( v2 );
  v6 = 5381i64;
  v7 = (_QWORD *)(v1->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  for ( i = *v7 & 0x7FFFFFFFFFFFFFFFi64; i; v6 = v9 ^ 33 * v6 )
  {
    v9 = *((unsigned __int8 *)v7 + i-- + 11);
    if ( (unsigned int)(v9 - 65) <= 0x19 )
      v9 += 32;
  }
  v10 = v4 ^ v6;
  v11 = (_QWORD *)(v1->Id.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  for ( j = *v11 & 0x7FFFFFFFFFFFFFFFi64; j; v3 = v13 ^ 33 * v3 )
  {
    v13 = *((unsigned __int8 *)v11 + j-- + 11);
    if ( (unsigned int)(v13 - 65) <= 0x19 )
      v13 += 32;
  }
  return v10 ^ v3;
}

// File Line: 43
// RVA: 0x945FC0
void __fastcall Scaleform::Render::Text::TextFormat::TextFormat(Scaleform::Render::Text::TextFormat *this, Scaleform::MemoryHeap *pheap)
{
  Scaleform::Render::Text::TextFormat *v2; // r11
  Scaleform::MemoryHeap *v3; // rax
  Scaleform::MemoryHeap *v4; // rcx

  v2 = this;
  this->pAllocator = 0i64;
  this->RefCount = 1;
  v3 = Scaleform::Memory::pGlobalHeap;
  if ( pheap )
    v3 = pheap;
  this->FontList.pHeap = v3;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
  v4 = Scaleform::Memory::pGlobalHeap;
  if ( pheap )
    v4 = pheap;
  v2->Url.pHeap = v4;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  v2->Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
  v2->pImageDesc.pObject = 0i64;
  v2->pFontHandle.pObject = 0i64;
  v2->ColorV = -16777216;
  v2->LetterSpacing = 0.0;
  v2->FontSize = 0;
  v2->FormatFlags = 0;
  v2->PresentMask = 0;
}

// File Line: 59
// RVA: 0x945F00
void __fastcall Scaleform::Render::Text::TextFormat::TextFormat(Scaleform::Render::Text::TextFormat *this, Scaleform::Render::Text::TextFormat *srcfmt, Scaleform::Render::Text::Allocator *allocator)
{
  Scaleform::Render::Text::TextFormat *v3; // rbx
  Scaleform::Render::Text::TextFormat *v4; // rdi
  Scaleform::Render::Text::HTMLImageTagDesc *v5; // rax
  Scaleform::Render::Text::FontHandle *v6; // rax

  v3 = srcfmt;
  v4 = this;
  this->pAllocator = allocator;
  this->RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(
    &this->FontList,
    (Scaleform::String *)&srcfmt->FontList.0,
    srcfmt->FontList.pHeap);
  Scaleform::StringDH::CopyConstructHelper(&v4->Url, (Scaleform::String *)&v3->Url.0, v3->FontList.pHeap);
  v5 = v3->pImageDesc.pObject;
  if ( v5 )
    ++v5->RefCount;
  v4->pImageDesc.pObject = v3->pImageDesc.pObject;
  v6 = v3->pFontHandle.pObject;
  if ( v6 )
    _InterlockedExchangeAdd(&v6->RefCount, 1u);
  v4->pFontHandle.pObject = v3->pFontHandle.pObject;
  v4->ColorV = v3->ColorV;
  v4->LetterSpacing = v3->LetterSpacing;
  v4->FontSize = v3->FontSize;
  v4->FormatFlags = v3->FormatFlags;
  v4->PresentMask = v3->PresentMask;
}

// File Line: 63
// RVA: 0x94D0E0
void __fastcall Scaleform::Render::Text::TextFormat::~TextFormat(Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Render::Text::TextFormat *v1; // rdi
  Scaleform::Render::Text::Allocator *v2; // rcx
  Scaleform::Render::Text::FontHandle *v3; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v4; // rcx
  bool v5; // zf
  Scaleform::Render::Text::TextFormat *key; // [rsp+48h] [rbp+10h]
  Scaleform::StringDH *v7; // [rsp+50h] [rbp+18h]

  v1 = this;
  v2 = this->pAllocator;
  if ( v2 )
  {
    key = v1;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
      (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v2->TextFormatStorage.pTable,
      &key);
  }
  v3 = v1->pFontHandle.pObject;
  if ( v3 && !_InterlockedDecrement(&v3->RefCount) && v3 )
    v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  v4 = v1->pImageDesc.pObject;
  if ( v4 )
  {
    v5 = v4->RefCount-- == 1;
    if ( v5 )
      v4->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 1u);
  }
  v7 = &v1->Url;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 70
// RVA: 0x9AFAA0
void __fastcall Scaleform::Render::Text::TextFormat::SetFontList(Scaleform::Render::Text::TextFormat *this, Scaleform::String *fontList)
{
  Scaleform::String *v2; // rsi
  Scaleform::Render::Text::TextFormat *v3; // rdi
  signed __int64 v4; // rbx
  Scaleform::Render::Text::FontHandle *v5; // rcx
  Scaleform::String::DataDesc *v6; // rcx

  v2 = fontList;
  v3 = this;
  if ( (this->PresentMask >> 11) & 1 )
  {
    v4 = Scaleform::String::GetLength((Scaleform::String *)&this->FontList.0);
    if ( v4 != Scaleform::String::GetLength(v2)
      || stricmp(
           (const char *)((v3->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
           (const char *)((v2->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
    {
      v5 = v3->pFontHandle.pObject;
      if ( v5 && !_InterlockedDecrement(&v5->RefCount) && v5 )
        v5->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v5->vfptr, 1u);
      v3->pFontHandle.pObject = 0i64;
      v3->PresentMask &= 0xF7FFu;
    }
  }
  Scaleform::String::operator=((Scaleform::String *)&v3->FontList.0, v2);
  v6 = v3->FontList.pData;
  v3->PresentMask |= 4u;
  if ( strchr((const char *)(((unsigned __int64)v6 & 0xFFFFFFFFFFFFFFFCui64) + 12), 44) )
    v3->PresentMask &= 0xEFFFu;
  else
    v3->PresentMask |= 0x1000u;
}

// File Line: 90
// RVA: 0x9AFB90
void __fastcall Scaleform::Render::Text::TextFormat::SetFontList(Scaleform::Render::Text::TextFormat *this, const char *pfontList, unsigned __int64 fontListSz)
{
  __int64 v3; // rbx
  const char *v4; // rsi
  Scaleform::Render::Text::TextFormat *v5; // rdi
  Scaleform::Render::Text::FontHandle *v6; // rcx
  Scaleform::String::DataDesc *v7; // rcx

  v3 = fontListSz;
  v4 = pfontList;
  v5 = this;
  if ( fontListSz == -1i64 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( pfontList[v3] );
  }
  if ( (this->PresentMask >> 11) & 1
    && (Scaleform::String::GetLength((Scaleform::String *)&this->FontList.0) != v3
     || (unsigned int)Scaleform::String::CompareNoCase(
                        (const char *)((v5->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                        v4,
                        v3)) )
  {
    v6 = v5->pFontHandle.pObject;
    if ( v6 && !_InterlockedDecrement(&v6->RefCount) && v6 )
      v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
    v5->pFontHandle.pObject = 0i64;
    v5->PresentMask &= 0xF7FFu;
  }
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((v5->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v5->FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (_QWORD)v5->FontList.pData & 3;
  Scaleform::String::AppendString((Scaleform::String *)&v5->FontList.0, v4, v3);
  v7 = v5->FontList.pData;
  v5->PresentMask |= 4u;
  if ( strchr((const char *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFFFFCui64) + 12), 44) )
    v5->PresentMask &= 0xEFFFu;
  else
    v5->PresentMask |= 0x1000u;
}

// File Line: 118
// RVA: 0x9AFCD0
void __fastcall Scaleform::Render::Text::TextFormat::SetFontList(Scaleform::Render::Text::TextFormat *this, const wchar_t *pfontList, unsigned __int64 fontListSz)
{
  unsigned __int64 v3; // rdi
  const wchar_t *v4; // r15
  Scaleform::Render::Text::TextFormat *v5; // rsi
  unsigned __int64 v6; // rbp
  char *v7; // r14
  int v8; // ebx
  Scaleform::Render::Text::FontHandle *v9; // rcx
  Scaleform::String::DataDesc *v10; // rcx

  v3 = fontListSz;
  v4 = pfontList;
  v5 = this;
  if ( fontListSz == -1i64 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( pfontList[v3] );
  }
  if ( (this->PresentMask >> 11) & 1 )
  {
    if ( Scaleform::String::GetLength((Scaleform::String *)&this->FontList.0) == v3 )
    {
      v6 = 0i64;
      if ( !v3 )
        goto LABEL_16;
      v7 = (char *)((v5->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      while ( 1 )
      {
        v8 = Scaleform::SFtowlower(v4[v6]);
        if ( (unsigned int)Scaleform::SFtowlower(*v7) != v8 )
          break;
        ++v6;
        ++v7;
        if ( v6 >= v3 )
          goto LABEL_16;
      }
    }
    v9 = v5->pFontHandle.pObject;
    if ( v9 && !_InterlockedDecrement(&v9->RefCount) && v9 )
      v9->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, 1u);
    v5->pFontHandle.pObject = 0i64;
    v5->PresentMask &= 0xF7FFu;
  }
LABEL_16:
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v5->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v5->FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (_QWORD)v5->FontList.pData & 3;
  Scaleform::String::AppendString((Scaleform::String *)&v5->FontList.0, v4, v3);
  v10 = v5->FontList.pData;
  v5->PresentMask |= 4u;
  if ( strchr((const char *)(((unsigned __int64)v10 & 0xFFFFFFFFFFFFFFFCui64) + 12), 44) )
    v5->PresentMask &= 0xEFFFu;
  else
    v5->PresentMask |= 0x1000u;
}

// File Line: 154
// RVA: 0x984840
Scaleform::StringDH *__fastcall Scaleform::Render::Text::TextFormat::GetFontList(Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Render::Text::TextFormat *v1; // rbx
  Scaleform::StringDH *result; // rax

  v1 = this;
  if ( !(_S9_20 & 1) )
  {
    _S9_20 |= 1u;
    emptyStr.pData = &Scaleform::String::NullData;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    atexit(Scaleform::Render::Text::TextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__);
  }
  result = &v1->FontList;
  if ( !((LOBYTE(v1->PresentMask) >> 2) & 1) )
    result = (Scaleform::StringDH *)&emptyStr;
  return result;
}

// File Line: 160
// RVA: 0x9AFE60
void __fastcall Scaleform::Render::Text::TextFormat::SetFontName(Scaleform::Render::Text::TextFormat *this, Scaleform::String *fontName)
{
  Scaleform::Render::Text::TextFormat::SetFontList(this, fontName);
}

// File Line: 169
// RVA: 0x9AFE70
void __fastcall Scaleform::Render::Text::TextFormat::SetFontName(Scaleform::Render::Text::TextFormat *this, const char *pfontName, unsigned __int64 fontNameSz)
{
  if ( fontNameSz == -1i64 )
  {
    do
      ++fontNameSz;
    while ( pfontName[fontNameSz] );
  }
  Scaleform::Render::Text::TextFormat::SetFontList(this, pfontName, fontNameSz);
}

// File Line: 199
// RVA: 0x9AFA40
void __fastcall Scaleform::Render::Text::TextFormat::SetFontHandle(Scaleform::Render::Text::TextFormat *this, Scaleform::Render::Text::FontHandle *pfontHandle)
{
  Scaleform::Render::Text::FontHandle *v2; // rdi
  Scaleform::Render::Text::TextFormat *v3; // rbx
  Scaleform::Render::Text::FontHandle *v4; // rcx

  v2 = pfontHandle;
  v3 = this;
  if ( pfontHandle )
    _InterlockedExchangeAdd(&pfontHandle->RefCount, 1u);
  v4 = this->pFontHandle.pObject;
  if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
    v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
  v3->pFontHandle.pObject = v2;
  v3->PresentMask |= 0x800u;
}

// File Line: 205
// RVA: 0x9B50E0
void __fastcall Scaleform::Render::Text::TextFormat::SetUrl(Scaleform::Render::Text::TextFormat *this, const char *purl, unsigned __int64 urlSz)
{
  __int64 v3; // rbx
  const char *v4; // rdi
  Scaleform::Render::Text::TextFormat *v5; // rbp

  v3 = urlSz;
  v4 = purl;
  v5 = this;
  if ( urlSz == -1i64 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( purl[v3] );
  }
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v5->Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (_QWORD)v5->Url.pData & 3;
  Scaleform::String::AppendString((Scaleform::String *)&v5->Url.0, v4, v3);
  v5->PresentMask |= 0x100u;
}

// File Line: 215
// RVA: 0x9B5190
void __fastcall Scaleform::Render::Text::TextFormat::SetUrl(Scaleform::Render::Text::TextFormat *this, const wchar_t *purl, unsigned __int64 urlSz)
{
  __int64 v3; // rbx
  const wchar_t *v4; // rdi
  Scaleform::Render::Text::TextFormat *v5; // rbp

  v3 = urlSz;
  v4 = purl;
  v5 = this;
  if ( urlSz == -1i64 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( purl[v3] );
  }
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v5->Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (_QWORD)v5->Url.pData & 3;
  Scaleform::String::AppendString((Scaleform::String *)&v5->Url.0, v4, v3);
  v5->PresentMask |= 0x100u;
}

// File Line: 232
// RVA: 0x9AE450
void __fastcall Scaleform::Render::Text::TextFormat::SetBold(Scaleform::Render::Text::TextFormat *this, bool bold)
{
  bool v2; // di
  Scaleform::Render::Text::TextFormat *v3; // rbx
  Scaleform::Render::Text::FontHandle *v4; // rcx

  v2 = bold;
  v3 = this;
  if ( (this->PresentMask >> 11) & 1 && (this->FormatFlags & 1) != bold )
  {
    v4 = this->pFontHandle.pObject;
    if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
      v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
    v3->pFontHandle.pObject = 0i64;
    v3->PresentMask &= 0xF7FFu;
  }
  if ( v2 )
    v3->FormatFlags |= 1u;
  else
    v3->FormatFlags &= 0xFEu;
  v3->PresentMask |= 0x10u;
}

// File Line: 251
// RVA: 0x9B0E20
void __fastcall Scaleform::Render::Text::TextFormat::SetItalic(Scaleform::Render::Text::TextFormat *this, bool italic)
{
  bool v2; // di
  Scaleform::Render::Text::TextFormat *v3; // rbx
  Scaleform::Render::Text::FontHandle *v4; // rcx

  v2 = italic;
  v3 = this;
  if ( (this->PresentMask >> 11) & 1 && (((unsigned __int8)this->FormatFlags >> 1) & 1) != italic )
  {
    v4 = this->pFontHandle.pObject;
    if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
      v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
    v3->pFontHandle.pObject = 0i64;
    v3->PresentMask &= 0xF7FFu;
  }
  if ( v2 )
    v3->FormatFlags |= 2u;
  else
    v3->FormatFlags &= 0xFDu;
  v3->PresentMask |= 0x20u;
}

// File Line: 270
// RVA: 0x9B4EA0
void __fastcall Scaleform::Render::Text::TextFormat::SetUnderline(Scaleform::Render::Text::TextFormat *this, bool underline)
{
  if ( underline )
    this->FormatFlags |= 4u;
  else
    this->FormatFlags &= 0xFBu;
  this->PresentMask |= 0x40u;
}

// File Line: 283
// RVA: 0x9B0EB0
void __fastcall Scaleform::Render::Text::TextFormat::SetKerning(Scaleform::Render::Text::TextFormat *this, bool kerning)
{
  if ( kerning )
    this->FormatFlags |= 8u;
  else
    this->FormatFlags &= 0xF7u;
  this->PresentMask |= 0x80u;
}

// File Line: 296
// RVA: 0x997770
bool __fastcall Scaleform::Render::Text::TextFormat::IsFontSame(Scaleform::Render::Text::TextFormat *this, Scaleform::Render::Text::TextFormat *fmt)
{
  Scaleform::Render::Text::TextFormat *v2; // rbx
  Scaleform::Render::Text::TextFormat *v3; // rdi
  char v4; // cl
  char v5; // dl
  bool result; // al

  v2 = fmt;
  v3 = this;
  result = 0;
  if ( (LOBYTE(this->PresentMask) >> 2) & 1
    && (LOBYTE(fmt->PresentMask) >> 2) & 1
    && !stricmp(
          (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          (const char *)((fmt->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12))
    || (v3->PresentMask >> 11) & 1 && (v2->PresentMask >> 11) & 1 && v3->pFontHandle.pObject == v2->pFontHandle.pObject )
  {
    v4 = v3->FormatFlags;
    v5 = v2->FormatFlags;
    if ( !(((unsigned __int8)v5 ^ (unsigned __int8)v4) & 1) && !(((unsigned __int8)v5 ^ (unsigned __int8)v4) & 2) )
      result = 1;
  }
  return result;
}

// File Line: 303
// RVA: 0x997850
bool __fastcall Scaleform::Render::Text::TextFormat::IsHTMLFontTagSame(Scaleform::Render::Text::TextFormat *this, Scaleform::Render::Text::TextFormat *fmt)
{
  Scaleform::Render::Text::TextFormat *v2; // rbx
  Scaleform::Render::Text::TextFormat *v3; // rdi

  v2 = fmt;
  v3 = this;
  return ((LOBYTE(this->PresentMask) >> 2) & 1
       && (LOBYTE(fmt->PresentMask) >> 2) & 1
       && !stricmp(
             (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
             (const char *)((fmt->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12))
       || (v3->PresentMask >> 11) & 1
       && (v2->PresentMask >> 11) & 1
       && v3->pFontHandle.pObject == v2->pFontHandle.pObject)
      && !((v3->ColorV ^ v2->ColorV) & 0xFFFFFF)
      && HIBYTE(v3->ColorV) == HIBYTE(v2->ColorV)
      && (float)((float)v3->FontSize * 0.050000001) == (float)((float)v2->FontSize * 0.050000001)
      && !((v3->FormatFlags ^ v2->FormatFlags) & 8)
      && (float)(v3->LetterSpacing * 0.050000001) == (float)(v2->LetterSpacing * 0.050000001);
}

// File Line: 312
// RVA: 0x99B130
Scaleform::Render::Text::TextFormat *__fastcall Scaleform::Render::Text::TextFormat::Merge(Scaleform::Render::Text::TextFormat *this, Scaleform::Render::Text::TextFormat *result, Scaleform::Render::Text::TextFormat *fmt)
{
  Scaleform::Render::Text::TextFormat *v3; // rdi
  Scaleform::Render::Text::TextFormat *v4; // r14
  char v5; // si
  Scaleform::Render::Text::FontHandle *v6; // rcx
  Scaleform::Render::Text::FontHandle *v7; // r8
  unsigned __int8 v8; // cl
  unsigned __int16 v9; // dx
  char v10; // si
  char v11; // al
  unsigned __int16 v12; // dx
  char v13; // al
  char v14; // al
  unsigned int v15; // ecx
  unsigned int v16; // eax
  unsigned __int16 v17; // cx
  Scaleform::String *v18; // rdx
  Scaleform::Render::RenderBuffer *v19; // rax
  Scaleform::Render::Text::FontHandle *v20; // rsi
  Scaleform::Render::Text::FontHandle *v21; // rcx
  unsigned __int64 v22; // rdx
  unsigned __int16 v23; // ax
  Scaleform::Render::Text::HTMLImageTagDesc *v24; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v25; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v26; // rcx
  Scaleform::Render::Text::TextFormat srcfmt; // [rsp+30h] [rbp-50h]

  v3 = fmt;
  v4 = result;
  Scaleform::Render::Text::TextFormat::TextFormat(&srcfmt, this, 0i64);
  if ( (LOBYTE(v3->PresentMask) >> 4) & 1 )
  {
    v5 = v3->FormatFlags & 1;
    if ( (srcfmt.PresentMask >> 11) & 1 && (srcfmt.FormatFlags & 1) != v5 )
    {
      v6 = srcfmt.pFontHandle.pObject;
      if ( srcfmt.pFontHandle.pObject && !_InterlockedDecrement(&srcfmt.pFontHandle.pObject->RefCount) && v6 )
        v6->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, 1u);
      v7 = 0i64;
      srcfmt.pFontHandle.pObject = 0i64;
      srcfmt.PresentMask &= 0xF7FFu;
    }
    else
    {
      v7 = srcfmt.pFontHandle.pObject;
    }
    if ( v5 )
    {
      v8 = srcfmt.FormatFlags | 1;
      srcfmt.FormatFlags |= 1u;
    }
    else
    {
      v8 = srcfmt.FormatFlags & 0xFE;
      srcfmt.FormatFlags &= 0xFEu;
    }
    v9 = srcfmt.PresentMask | 0x10;
    srcfmt.PresentMask |= 0x10u;
  }
  else
  {
    v9 = srcfmt.PresentMask;
    v8 = srcfmt.FormatFlags;
    v7 = srcfmt.pFontHandle.pObject;
  }
  if ( (LOBYTE(v3->PresentMask) >> 5) & 1 )
  {
    v10 = ((unsigned __int8)v3->FormatFlags >> 1) & 1;
    if ( (v9 >> 11) & 1 && ((v8 >> 1) & 1) != v10 )
    {
      if ( v7 )
      {
        if ( !_InterlockedDecrement(&v7->RefCount) && v7 )
          v7->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, 1u);
        v8 = srcfmt.FormatFlags;
      }
      srcfmt.pFontHandle.pObject = 0i64;
      srcfmt.PresentMask &= 0xF7FFu;
    }
    if ( v10 )
      v11 = v8 | 2;
    else
      v11 = v8 & 0xFD;
    srcfmt.FormatFlags = v11;
    v8 = v11;
    srcfmt.PresentMask |= 0x20u;
  }
  v12 = v3->PresentMask;
  if ( ((unsigned __int8)v12 >> 6) & 1 )
  {
    if ( ((unsigned __int8)v3->FormatFlags >> 2) & 1 )
      v13 = v8 | 4;
    else
      v13 = v8 & 0xFB;
    srcfmt.FormatFlags = v13;
    v8 = v13;
    srcfmt.PresentMask |= 0x40u;
  }
  if ( (v12 & 0x80u) != 0 )
  {
    if ( ((unsigned __int8)v3->FormatFlags >> 3) & 1 )
      v14 = v8 | 8;
    else
      v14 = v8 & 0xF7;
    srcfmt.FormatFlags = v14;
    srcfmt.PresentMask |= 0x80u;
  }
  if ( v3->PresentMask & 1 )
  {
    v15 = v3->ColorV;
    srcfmt.ColorV = v3->ColorV;
    srcfmt.PresentMask |= 1u;
  }
  else
  {
    v15 = srcfmt.ColorV;
  }
  if ( (v12 >> 10) & 1 )
  {
    srcfmt.ColorV = v15 & 0xFFFFFF | (HIBYTE(v3->ColorV) << 24);
    srcfmt.PresentMask |= 0x400u;
  }
  if ( ((unsigned __int8)v12 >> 1) & 1 )
  {
    srcfmt.LetterSpacing = (float)(signed __int16)(signed int)v3->LetterSpacing;
    srcfmt.PresentMask |= 2u;
  }
  if ( ((unsigned __int8)v12 >> 3) & 1 )
  {
    v16 = v3->FontSize;
    v17 = -1;
    if ( v16 <= 0x10000 )
      v17 = v3->FontSize;
    srcfmt.FontSize = v17;
    srcfmt.PresentMask |= 8u;
  }
  if ( ((unsigned __int8)v12 >> 2) & 1 )
  {
    if ( !(_S9_20 & 1) )
    {
      _S9_20 |= 1u;
      emptyStr.pData = &Scaleform::String::NullData;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      atexit(Scaleform::Render::Text::TextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__);
    }
    v18 = (Scaleform::String *)&v3->FontList.0;
    if ( !((LOBYTE(v3->PresentMask) >> 2) & 1) )
      v18 = &emptyStr;
    Scaleform::Render::Text::TextFormat::SetFontList(&srcfmt, v18);
  }
  if ( (v3->PresentMask >> 11) & 1 )
  {
    v19 = Scaleform::Render::Text::TextFormat::GetFontHandle(v3);
    v20 = (Scaleform::Render::Text::FontHandle *)v19;
    if ( v19 )
      _InterlockedExchangeAdd(&v19->RefCount, 1u);
    v21 = srcfmt.pFontHandle.pObject;
    if ( srcfmt.pFontHandle.pObject && !_InterlockedDecrement(&srcfmt.pFontHandle.pObject->RefCount) && v21 )
      v21->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v21->vfptr, 1u);
    srcfmt.pFontHandle.pObject = v20;
    srcfmt.PresentMask |= 0x800u;
  }
  if ( v3->PresentMask & 0x100 )
  {
    if ( !Scaleform::String::GetLength((Scaleform::String *)&v3->Url.0) )
    {
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      v22 = srcfmt.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      if ( !_InterlockedDecrement((volatile signed __int32 *)((srcfmt.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v22);
      srcfmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (_QWORD)srcfmt.Url.pData & 3;
      v23 = srcfmt.PresentMask & 0xFEFF;
      goto LABEL_71;
    }
    if ( v3->PresentMask & 0x100 && Scaleform::String::GetLength((Scaleform::String *)&v3->Url.0) )
    {
      Scaleform::String::operator=((Scaleform::String *)&srcfmt.Url.0, (Scaleform::String *)&v3->Url.0);
      v23 = srcfmt.PresentMask | 0x100;
LABEL_71:
      srcfmt.PresentMask = v23;
      goto LABEL_72;
    }
  }
LABEL_72:
  if ( (v3->PresentMask >> 9) & 1 )
  {
    v24 = Scaleform::Render::Text::TextFormat::GetImageDesc(v3);
    v25 = v24;
    if ( v24 )
      ++v24->RefCount;
    v26 = srcfmt.pImageDesc.pObject;
    if ( srcfmt.pImageDesc.pObject )
    {
      --srcfmt.pImageDesc.pObject->RefCount;
      if ( !v26->RefCount )
        v26->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v26->vfptr, 1u);
    }
    srcfmt.pImageDesc.pObject = v25;
    srcfmt.PresentMask |= 0x200u;
  }
  Scaleform::Render::Text::TextFormat::TextFormat(v4, &srcfmt, 0i64);
  Scaleform::Render::Text::TextFormat::~TextFormat(&srcfmt);
  return v4;
}

// File Line: 344
// RVA: 0x996CF0
Scaleform::Render::Text::TextFormat *__fastcall Scaleform::Render::Text::TextFormat::Intersection(Scaleform::Render::Text::TextFormat *this, Scaleform::Render::Text::TextFormat *result, Scaleform::Render::Text::TextFormat *fmt)
{
  Scaleform::Render::Text::TextFormat *v3; // rsi
  Scaleform::Render::Text::TextFormat *v4; // r15
  Scaleform::Render::Text::TextFormat *v5; // r14
  Scaleform::MemoryHeap *v6; // r9
  Scaleform::MemoryHeap *v7; // rax
  Scaleform::MemoryHeap *v8; // rax
  char v9; // di
  Scaleform::Render::Text::FontHandle *v10; // rcx
  Scaleform::Render::Text::FontHandle *v11; // r8
  unsigned __int8 v12; // cl
  unsigned __int16 v13; // dx
  char v14; // di
  char v15; // al
  unsigned __int16 v16; // dx
  char v17; // r8
  char v18; // al
  char v19; // r8
  char v20; // al
  unsigned int v21; // ecx
  unsigned __int8 v22; // al
  unsigned __int16 v23; // ax
  unsigned __int16 v24; // cx
  Scaleform::StringDH *v25; // rax
  Scaleform::Render::RenderBuffer *v26; // rdi
  Scaleform::Render::RenderBuffer *v27; // rax
  Scaleform::Render::Text::FontHandle *v28; // rdi
  Scaleform::Render::Text::FontHandle *v29; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v30; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v31; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v32; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v33; // rcx
  Scaleform::Render::Text::TextFormat srcfmt; // [rsp+30h] [rbp-50h]

  v3 = fmt;
  v4 = result;
  v5 = this;
  v6 = fmt->FontList.pHeap;
  srcfmt.pAllocator = 0i64;
  srcfmt.RefCount = 1;
  v7 = Scaleform::Memory::pGlobalHeap;
  if ( v6 )
    v7 = v6;
  srcfmt.FontList.pHeap = v7;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  srcfmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
  v8 = Scaleform::Memory::pGlobalHeap;
  if ( v6 )
    v8 = v6;
  srcfmt.Url.pHeap = v8;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  srcfmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | 2;
  srcfmt.pImageDesc.pObject = 0i64;
  srcfmt.pFontHandle.pObject = 0i64;
  srcfmt.ColorV = -16777216;
  srcfmt.LetterSpacing = 0.0;
  srcfmt.FontSize = 0;
  srcfmt.FormatFlags = 0;
  srcfmt.PresentMask = 0;
  if ( (LOBYTE(this->PresentMask) >> 4) & 1
    && (LOBYTE(fmt->PresentMask) >> 4) & 1
    && (v9 = fmt->FormatFlags & 1, (this->FormatFlags & 1) == v9) )
  {
    if ( (srcfmt.PresentMask >> 11) & 1 && (srcfmt.FormatFlags & 1) != v9 )
    {
      v10 = srcfmt.pFontHandle.pObject;
      if ( srcfmt.pFontHandle.pObject && !_InterlockedDecrement(&srcfmt.pFontHandle.pObject->RefCount) && v10 )
        v10->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v10->vfptr, 1u);
      v11 = 0i64;
      srcfmt.pFontHandle.pObject = 0i64;
      srcfmt.PresentMask &= 0xF7FFu;
    }
    else
    {
      v11 = srcfmt.pFontHandle.pObject;
    }
    if ( v9 )
    {
      v12 = srcfmt.FormatFlags | 1;
      srcfmt.FormatFlags |= 1u;
    }
    else
    {
      v12 = srcfmt.FormatFlags & 0xFE;
      srcfmt.FormatFlags &= 0xFEu;
    }
    v13 = srcfmt.PresentMask | 0x10;
    srcfmt.PresentMask |= 0x10u;
  }
  else
  {
    v13 = srcfmt.PresentMask;
    v12 = srcfmt.FormatFlags;
    v11 = srcfmt.pFontHandle.pObject;
  }
  if ( (LOBYTE(v5->PresentMask) >> 5) & 1 )
  {
    if ( (LOBYTE(v3->PresentMask) >> 5) & 1 )
    {
      v14 = ((unsigned __int8)v3->FormatFlags >> 1) & 1;
      if ( (((unsigned __int8)v5->FormatFlags >> 1) & 1) == v14 )
      {
        if ( (v13 >> 11) & 1 && ((v12 >> 1) & 1) != v14 )
        {
          if ( v11 )
          {
            if ( !_InterlockedDecrement(&v11->RefCount) && v11 )
              v11->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v11->vfptr, 1u);
            v12 = srcfmt.FormatFlags;
          }
          srcfmt.pFontHandle.pObject = 0i64;
          srcfmt.PresentMask &= 0xF7FFu;
        }
        if ( v14 )
          v15 = v12 | 2;
        else
          v15 = v12 & 0xFD;
        srcfmt.FormatFlags = v15;
        v12 = v15;
        srcfmt.PresentMask |= 0x20u;
      }
    }
  }
  v16 = v5->PresentMask;
  if ( ((unsigned __int8)v16 >> 6) & 1 )
  {
    if ( (LOBYTE(v3->PresentMask) >> 6) & 1 )
    {
      v17 = ((unsigned __int8)v3->FormatFlags >> 2) & 1;
      if ( (((unsigned __int8)v5->FormatFlags >> 2) & 1) == v17 )
      {
        if ( v17 )
          v18 = v12 | 4;
        else
          v18 = v12 & 0xFB;
        srcfmt.FormatFlags = v18;
        v12 = v18;
        srcfmt.PresentMask |= 0x40u;
      }
    }
  }
  if ( (v16 & 0x80u) != 0 && SLOBYTE(v3->PresentMask) < 0 )
  {
    v19 = ((unsigned __int8)v3->FormatFlags >> 3) & 1;
    if ( (((unsigned __int8)v5->FormatFlags >> 3) & 1) == v19 )
    {
      if ( v19 )
        v20 = v12 | 8;
      else
        v20 = v12 & 0xF7;
      srcfmt.FormatFlags = v20;
      srcfmt.PresentMask |= 0x80u;
    }
  }
  if ( v5->PresentMask & 1 && v3->PresentMask & 1 && (v21 = v3->ColorV, v5->ColorV == v21) )
  {
    srcfmt.ColorV = v3->ColorV;
    srcfmt.PresentMask |= 1u;
  }
  else
  {
    v21 = srcfmt.ColorV;
  }
  if ( (v16 >> 10) & 1 )
  {
    if ( (v3->PresentMask >> 10) & 1 )
    {
      v22 = HIBYTE(v3->ColorV);
      if ( HIBYTE(v5->ColorV) == v22 )
      {
        srcfmt.ColorV = v21 & 0xFFFFFF | (v22 << 24);
        srcfmt.PresentMask |= 0x400u;
      }
    }
  }
  if ( ((unsigned __int8)v16 >> 1) & 1
    && (LOBYTE(v3->PresentMask) >> 1) & 1
    && (float)(v5->LetterSpacing * 0.050000001) == (float)(v3->LetterSpacing * 0.050000001) )
  {
    srcfmt.LetterSpacing = (float)(signed __int16)(signed int)v3->LetterSpacing;
    srcfmt.PresentMask |= 2u;
  }
  if ( ((unsigned __int8)v16 >> 3) & 1 )
  {
    if ( (LOBYTE(v3->PresentMask) >> 3) & 1 )
    {
      v23 = v3->FontSize;
      if ( v5->FontSize == v23 )
      {
        v24 = -1;
        if ( v23 <= 0x10000u )
          v24 = v3->FontSize;
        srcfmt.FontSize = v24;
        srcfmt.PresentMask |= 8u;
      }
    }
  }
  if ( ((unsigned __int8)v16 >> 2) & 1
    && (LOBYTE(v3->PresentMask) >> 2) & 1
    && !stricmp(
          (const char *)((v5->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          (const char *)((v3->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
  {
    v25 = Scaleform::Render::Text::TextFormat::GetFontList(v3);
    Scaleform::Render::Text::TextFormat::SetFontList(&srcfmt, (Scaleform::String *)&v25->0);
  }
  if ( (v5->PresentMask >> 11) & 1 )
  {
    if ( (v3->PresentMask >> 11) & 1 )
    {
      v26 = Scaleform::Render::Text::TextFormat::GetFontHandle(v3);
      if ( Scaleform::Render::Text::TextFormat::GetFontHandle(v5) == v26 )
      {
        v27 = Scaleform::Render::Text::TextFormat::GetFontHandle(v3);
        v28 = (Scaleform::Render::Text::FontHandle *)v27;
        if ( v27 )
          _InterlockedExchangeAdd(&v27->RefCount, 1u);
        v29 = srcfmt.pFontHandle.pObject;
        if ( srcfmt.pFontHandle.pObject && !_InterlockedDecrement(&srcfmt.pFontHandle.pObject->RefCount) && v29 )
          v29->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v29->vfptr, 1u);
        srcfmt.pFontHandle.pObject = v28;
        srcfmt.PresentMask |= 0x800u;
      }
    }
  }
  if ( v5->PresentMask & 0x100
    && Scaleform::String::GetLength((Scaleform::String *)&v5->Url.0)
    && v3->PresentMask & 0x100
    && Scaleform::String::GetLength((Scaleform::String *)&v3->Url.0)
    && !stricmp(
          (const char *)((v5->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          (const char *)((v3->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
  {
    Scaleform::String::operator=((Scaleform::String *)&srcfmt.Url.0, (Scaleform::String *)&v3->Url.0);
    srcfmt.PresentMask |= 0x100u;
  }
  if ( (v5->PresentMask >> 9) & 1 )
  {
    if ( (v3->PresentMask >> 9) & 1 )
    {
      v30 = Scaleform::Render::Text::TextFormat::GetImageDesc(v3);
      if ( Scaleform::Render::Text::TextFormat::GetImageDesc(v5) == v30 )
      {
        v31 = Scaleform::Render::Text::TextFormat::GetImageDesc(v3);
        v32 = v31;
        if ( v31 )
          ++v31->RefCount;
        v33 = srcfmt.pImageDesc.pObject;
        if ( srcfmt.pImageDesc.pObject )
        {
          --srcfmt.pImageDesc.pObject->RefCount;
          if ( !v33->RefCount )
            v33->vfptr->__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v33->vfptr, 1u);
        }
        srcfmt.pImageDesc.pObject = v32;
        srcfmt.PresentMask |= 0x200u;
      }
    }
  }
  Scaleform::Render::Text::TextFormat::TextFormat(v4, &srcfmt, 0i64);
  Scaleform::Render::Text::TextFormat::~TextFormat(&srcfmt);
  return v4;
}

// File Line: 374
// RVA: 0x992D80
void __fastcall Scaleform::Render::Text::TextFormat::InitByDefaultValues(Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Render::Text::TextFormat *v1; // rbx
  Scaleform::Render::Text::FontHandle *v2; // rcx
  unsigned __int16 v3; // ax
  Scaleform::Render::Text::FontHandle *v4; // rcx
  unsigned __int16 v5; // ax

  this->ColorV &= 0xFF000000;
  this->PresentMask |= 1u;
  v1 = this;
  Scaleform::Render::Text::TextFormat::SetFontList(this, "Times New Roman", 0xFFFFFFFFFFFFFFFFui64);
  v1->PresentMask |= 8u;
  v1->FontSize = 240;
  if ( (v1->PresentMask >> 11) & 1 && v1->FormatFlags & 1 )
  {
    v2 = v1->pFontHandle.pObject;
    if ( v2 && !_InterlockedDecrement(&v2->RefCount) && v2 )
      v2->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, 1u);
    v1->pFontHandle.pObject = 0i64;
    v1->PresentMask &= 0xF7FFu;
  }
  v1->PresentMask |= 0x10u;
  v3 = v1->PresentMask;
  v1->FormatFlags &= 0xFEu;
  if ( (v3 >> 11) & 1 && v1->FormatFlags & 2 )
  {
    v4 = v1->pFontHandle.pObject;
    if ( v4 && !_InterlockedDecrement(&v4->RefCount) && v4 )
      v4->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, 1u);
    v1->pFontHandle.pObject = 0i64;
    v1->PresentMask &= 0xF7FFu;
  }
  v5 = v1->PresentMask;
  v1->FormatFlags &= 0xF1u;
  v1->ColorV |= 0xFF000000;
  v1->LetterSpacing = 0.0;
  v1->PresentMask = v5 & 0xFBFD | 0xE0;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((v1->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v1->Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (_QWORD)v1->Url.pData & 3;
  v1->PresentMask &= 0xFEFFu;
}

// File Line: 389
// RVA: 0x95BF50
signed __int64 __fastcall Scaleform::Render::Text::TextFormat::HashFunctor::CalcHash(Scaleform::Render::Text::TextFormat *data)
{
  Scaleform::Render::Text::TextFormat *v1; // rsi
  __int64 v2; // rcx
  bool v3; // zf
  unsigned __int16 v4; // bp
  __int64 v5; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v6; // rcx
  unsigned __int64 v7; // rdi
  signed __int64 v8; // rcx
  signed __int64 v9; // rbx
  __int64 v10; // rax
  unsigned __int64 v11; // rdx
  _QWORD *v12; // r9
  signed __int64 i; // r8
  int v14; // ecx
  _QWORD *v15; // r8
  signed __int64 j; // rdx
  int v17; // ecx
  char v19; // [rsp+1Fh] [rbp-49h]
  __int64 v20; // [rsp+20h] [rbp-48h]
  __int64 v21; // [rsp+28h] [rbp-40h]
  __int64 v22; // [rsp+30h] [rbp-38h]
  __int64 v23; // [rsp+38h] [rbp-30h]
  unsigned __int64 v24; // [rsp+40h] [rbp-28h]

  v1 = data;
  v2 = 0i64;
  v3 = (v1->PresentMask & 1) == 0;
  v20 = 0i64;
  v24 = 0i64;
  if ( !v3 || (v1->PresentMask >> 10) & 1 )
    v20 = v1->ColorV;
  v4 = v1->PresentMask;
  if ( ((unsigned __int8)v4 >> 1) & 1 )
    v2 = LODWORD(v1->LetterSpacing);
  v21 = v2;
  v5 = (unsigned __int8)v1->FormatFlags;
  v22 = (unsigned __int8)v1->FormatFlags;
  if ( ((unsigned __int8)v4 >> 3) & 1 )
  {
    v5 = (v1->FontSize << 8) | (unsigned __int64)v5;
    v22 = v5;
  }
  if ( v1->pFontHandle.pObject )
    v22 = v5 | 0x1000000;
  v23 = v4;
  if ( (v4 >> 9) & 1 )
  {
    v6 = v1->pImageDesc.pObject;
    if ( v6 )
      v24 = Scaleform::Render::Text::HTMLImageTagDesc::GetHash(v6);
  }
  v7 = 5381i64;
  v8 = 40i64;
  v9 = 5381i64;
  do
  {
    v10 = (unsigned __int8)*(&v19 + v8--);
    v9 = v10 + 65599 * v9;
  }
  while ( v8 );
  if ( ((unsigned __int8)v4 >> 2) & 1 )
  {
    v11 = 5381i64;
    v12 = (_QWORD *)(v1->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
    for ( i = *v12 & 0x7FFFFFFFFFFFFFFFi64; i; v11 = v14 ^ 33 * v11 )
    {
      v14 = *((unsigned __int8 *)v12 + i-- + 11);
      if ( (unsigned int)(v14 - 65) <= 0x19 )
        v14 += 32;
    }
    v9 ^= v11;
  }
  if ( v4 & 0x100 && Scaleform::String::GetLength((Scaleform::String *)&v1->Url.0) )
  {
    v15 = (_QWORD *)(v1->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
    for ( j = *v15 & 0x7FFFFFFFFFFFFFFFi64; j; v7 = v17 ^ 33 * v7 )
    {
      v17 = *((unsigned __int8 *)v15 + j-- + 11);
      if ( (unsigned int)(v17 - 65) <= 0x19 )
        v17 += 32;
    }
    v9 ^= v7;
  }
  return v9;
}

// File Line: 444
// RVA: 0x94BC00
void __fastcall Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(Scaleform::Render::Text::ParagraphFormat *this)
{
  Scaleform::Render::Text::ParagraphFormat *v1; // rbx
  Scaleform::Render::Text::Allocator *v2; // rcx
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = this->pAllocator;
  if ( v2 )
  {
    key = v1;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&v2->ParagraphFormatStorage.pTable,
      &key);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->pTabStops);
  v1->pTabStops = 0i64;
}

// File Line: 451
// RVA: 0x99AB90
Scaleform::Render::Text::ParagraphFormat *__fastcall Scaleform::Render::Text::ParagraphFormat::Merge(Scaleform::Render::Text::ParagraphFormat *this, Scaleform::Render::Text::ParagraphFormat *result, Scaleform::Render::Text::ParagraphFormat *fmt)
{
  Scaleform::Render::Text::ParagraphFormat *v3; // rdi
  Scaleform::Render::Text::ParagraphFormat *v4; // rsi
  unsigned int *v5; // r14
  Scaleform::MemoryHeapVtbl *v6; // rax
  unsigned int v7; // ebx
  unsigned __int16 v8; // cx
  unsigned __int16 v9; // dx
  __int16 v10; // ax
  const unsigned int *v11; // rdx
  unsigned __int16 v12; // ax
  Scaleform::Render::Text::ParagraphFormat v14; // [rsp+30h] [rbp-30h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+90h] [rbp+30h]
  Scaleform::Render::Text::ParagraphFormat *v16; // [rsp+98h] [rbp+38h]

  v16 = result;
  v3 = fmt;
  v4 = result;
  v14.pAllocator = 0i64;
  v14.RefCount = 1;
  v14.pTabStops = 0i64;
  v14.BlockIndent = this->BlockIndent;
  v14.Indent = this->Indent;
  v14.Leading = this->Leading;
  v14.LeftMargin = this->LeftMargin;
  v14.RightMargin = this->RightMargin;
  v14.PresentMask = this->PresentMask;
  v5 = this->pTabStops;
  v6 = Scaleform::Memory::pGlobalHeap->vfptr;
  if ( v5 )
  {
    v7 = *v5;
    v6->Free(Scaleform::Memory::pGlobalHeap, 0i64);
    v14.pTabStops = 0i64;
    v14.pTabStops = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                      Scaleform::Memory::pGlobalHeap,
                                      4i64 * (v7 + 1),
                                      0i64);
    *v14.pTabStops = v7;
    memmove(v14.pTabStops + 1, v5 + 1, 4i64 * v7);
  }
  else
  {
    v6->Free(Scaleform::Memory::pGlobalHeap, 0i64);
    v14.pTabStops = 0i64;
  }
  if ( v3->PresentMask & 1 )
  {
    v8 = v14.PresentMask ^ (v14.PresentMask ^ (((v3->PresentMask >> 9) & 3) << 9)) & 0x600 | 1;
    v14.PresentMask = v14.PresentMask ^ (v14.PresentMask ^ (((v3->PresentMask >> 9) & 3) << 9)) & 0x600 | 1;
  }
  else
  {
    v8 = v14.PresentMask;
  }
  v9 = v3->PresentMask;
  if ( (v9 & 0x80u) != 0 )
  {
    if ( (v9 & 0x8000u) == 0 )
      v10 = v8 & 0x7FFF;
    else
      v10 = v8 | 0x8000;
    v8 = v10 | 0x80;
    v14.PresentMask = v10 | 0x80;
  }
  if ( ((unsigned __int8)v9 >> 1) & 1 )
  {
    v14.BlockIndent = v3->BlockIndent;
    v8 |= 2u;
    v14.PresentMask = v8;
  }
  if ( ((unsigned __int8)v9 >> 2) & 1 )
  {
    v14.Indent = v3->Indent;
    v8 |= 4u;
    v14.PresentMask = v8;
  }
  if ( ((unsigned __int8)v9 >> 3) & 1 )
  {
    v14.Leading = v3->Leading;
    v8 |= 8u;
    v14.PresentMask = v8;
  }
  if ( ((unsigned __int8)v9 >> 4) & 1 )
  {
    v14.LeftMargin = v3->LeftMargin;
    v8 |= 0x10u;
    v14.PresentMask = v8;
  }
  if ( ((unsigned __int8)v9 >> 5) & 1 )
  {
    v14.RightMargin = v3->RightMargin;
    v8 |= 0x20u;
    v14.PresentMask = v8;
  }
  if ( ((unsigned __int8)v9 >> 6) & 1 )
  {
    v11 = v3->pTabStops;
    if ( v11 && *v11 )
    {
      Scaleform::Render::Text::ParagraphFormat::CopyTabStops(&v14, v11);
      v12 = v14.PresentMask | 0x40;
    }
    else
    {
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14.pTabStops);
      v14.pTabStops = 0i64;
      v12 = v14.PresentMask & 0xFFBF;
    }
    v14.PresentMask = v12;
    v8 = v12;
  }
  if ( (v3->PresentMask >> 8) & 1 )
  {
    v14.PresentMask = v8 ^ (v8 ^ (((v3->PresentMask >> 11) & 3) << 11)) & 0x1800;
    v8 = v14.PresentMask | 0x100;
    v14.PresentMask |= 0x100u;
  }
  v4->pAllocator = 0i64;
  v4->RefCount = 1;
  v4->pTabStops = 0i64;
  v4->BlockIndent = v14.BlockIndent;
  v4->Indent = v14.Indent;
  v4->Leading = v14.Leading;
  v4->LeftMargin = v14.LeftMargin;
  v4->RightMargin = v14.RightMargin;
  v4->PresentMask = v8;
  Scaleform::Render::Text::ParagraphFormat::CopyTabStops(v4, v14.pTabStops);
  if ( v14.pAllocator )
  {
    key = &v14;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&v14.pAllocator->ParagraphFormatStorage.pTable,
      &key);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14.pTabStops);
  return v4;
}

// File Line: 475
// RVA: 0x996970
Scaleform::Render::Text::ParagraphFormat *__fastcall Scaleform::Render::Text::ParagraphFormat::Intersection(Scaleform::Render::Text::ParagraphFormat *this, Scaleform::Render::Text::ParagraphFormat *result, Scaleform::Render::Text::ParagraphFormat *fmt)
{
  Scaleform::Render::Text::ParagraphFormat *v3; // rdi
  Scaleform::Render::Text::ParagraphFormat *v4; // r15
  Scaleform::Render::Text::ParagraphFormat *v5; // r14
  unsigned int v6; // edx
  int v7; // edx
  unsigned __int16 v8; // bx
  unsigned __int16 v9; // dx
  unsigned __int16 v10; // r8
  __int16 v11; // r8
  __int16 v12; // ax
  const unsigned int *v13; // rsi
  unsigned int *v14; // rcx
  unsigned __int16 v15; // ax
  unsigned __int16 v16; // dx
  unsigned __int16 v17; // cx
  Scaleform::Render::Text::ParagraphFormat v19; // [rsp+30h] [rbp-30h]
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+90h] [rbp+30h]
  Scaleform::Render::Text::ParagraphFormat *v21; // [rsp+98h] [rbp+38h]

  v21 = result;
  v3 = fmt;
  v4 = result;
  v5 = this;
  v19.pAllocator = 0i64;
  v19.RefCount = 1;
  v19.pTabStops = 0i64;
  *(_QWORD *)&v19.BlockIndent = 0i64;
  *(_DWORD *)&v19.RightMargin = 0;
  if ( this->PresentMask & 1
    && fmt->PresentMask & 1
    && (v6 = fmt->PresentMask, !((this->PresentMask ^ (unsigned __int16)v6) & 0x600)) )
  {
    v7 = v19.PresentMask ^ (v19.PresentMask ^ (((v6 >> 9) & 3) << 9)) & 0x600;
    v8 = v7 | 1;
    v19.PresentMask = v7 | 1;
  }
  else
  {
    v8 = v19.PresentMask;
  }
  v9 = this->PresentMask;
  if ( (v9 & 0x80u) != 0 )
  {
    v10 = fmt->PresentMask;
    if ( (v10 & 0x80u) != 0 )
    {
      v11 = v10 & 0x8000;
      if ( (unsigned int)v9 >> 15 == (v11 != 0) )
      {
        if ( v11 )
          v12 = v8 | 0x8000;
        else
          v12 = v8 & 0x7FFF;
        v8 = v12 | 0x80;
        v19.PresentMask = v12 | 0x80;
      }
    }
  }
  if ( ((unsigned __int8)v9 >> 1) & 1 && (LOBYTE(v3->PresentMask) >> 1) & 1 && this->BlockIndent == v3->BlockIndent )
  {
    v19.BlockIndent = v3->BlockIndent;
    v8 |= 2u;
    v19.PresentMask = v8;
  }
  if ( ((unsigned __int8)v9 >> 2) & 1 && (LOBYTE(v3->PresentMask) >> 2) & 1 && this->Indent == v3->Indent )
  {
    v19.Indent = v3->Indent;
    v8 |= 4u;
    v19.PresentMask = v8;
  }
  if ( ((unsigned __int8)v9 >> 3) & 1 && (LOBYTE(v3->PresentMask) >> 3) & 1 && this->Leading == v3->Leading )
  {
    v19.Leading = v3->Leading;
    v8 |= 8u;
    v19.PresentMask = v8;
  }
  if ( ((unsigned __int8)v9 >> 4) & 1 && (LOBYTE(v3->PresentMask) >> 4) & 1 && this->LeftMargin == v3->LeftMargin )
  {
    v19.LeftMargin = v3->LeftMargin;
    v8 |= 0x10u;
    v19.PresentMask = v8;
  }
  if ( ((unsigned __int8)v9 >> 5) & 1 && (LOBYTE(v3->PresentMask) >> 5) & 1 && this->RightMargin == v3->RightMargin )
  {
    v19.RightMargin = v3->RightMargin;
    v8 |= 0x20u;
    v19.PresentMask = v8;
  }
  if ( ((unsigned __int8)v9 >> 6) & 1 )
  {
    if ( (LOBYTE(v3->PresentMask) >> 6) & 1 )
    {
      v13 = v3->pTabStops;
      v14 = this->pTabStops;
      if ( v14 == v13 || v14 && v13 && *v14 == *v13 && !memcmp(v14 + 1, v13 + 1, 4i64 * *v14) )
      {
        if ( v13 && *v13 )
        {
          Scaleform::Render::Text::ParagraphFormat::CopyTabStops(&v19, v13);
          v15 = v19.PresentMask | 0x40;
        }
        else
        {
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v19.pTabStops);
          v19.pTabStops = 0i64;
          v15 = v19.PresentMask & 0xFFBF;
        }
        v19.PresentMask = v15;
        v8 = v15;
      }
    }
  }
  v16 = v5->PresentMask;
  if ( v16 & 0x100 )
  {
    v17 = v3->PresentMask;
    if ( v17 & 0x100 )
    {
      if ( !((v17 ^ v16) & 0x1800) )
      {
        v19.PresentMask = v8 ^ (v8 ^ (((v3->PresentMask >> 11) & 3) << 11)) & 0x1800;
        v8 = v19.PresentMask | 0x100;
        v19.PresentMask |= 0x100u;
      }
    }
  }
  v4->pAllocator = 0i64;
  v4->RefCount = 1;
  v4->pTabStops = 0i64;
  v4->BlockIndent = v19.BlockIndent;
  v4->Indent = v19.Indent;
  v4->Leading = v19.Leading;
  v4->LeftMargin = v19.LeftMargin;
  v4->RightMargin = v19.RightMargin;
  v4->PresentMask = v8;
  Scaleform::Render::Text::ParagraphFormat::CopyTabStops(v4, v19.pTabStops);
  if ( v19.pAllocator )
  {
    key = &v19;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&v19.pAllocator->ParagraphFormatStorage.pTable,
      &key);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v19.pTabStops);
  return v4;
}

// File Line: 499
// RVA: 0x992D20
void __fastcall Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(Scaleform::Render::Text::ParagraphFormat *this)
{
  unsigned __int16 v1; // ax
  Scaleform::Render::Text::ParagraphFormat *v2; // rbx
  unsigned int *v3; // rdx

  v1 = this->PresentMask;
  v2 = this;
  v3 = this->pTabStops;
  *(_QWORD *)&this->BlockIndent = 0i64;
  this->RightMargin = 0;
  this->PresentMask = v1 & 0x7940 | 1;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3);
  v2->pTabStops = 0i64;
  v2->PresentMask &= 0xFFBFu;
}

// File Line: 546
// RVA: 0x98C630
const unsigned int *__fastcall Scaleform::Render::Text::ParagraphFormat::GetTabStops(Scaleform::Render::Text::ParagraphFormat *this, unsigned int *pnum)
{
  const unsigned int *result; // rax

  result = this->pTabStops;
  if ( result )
  {
    if ( pnum )
      *pnum = *result;
    result = this->pTabStops + 1;
  }
  return result;
}

// File Line: 558
// RVA: 0x9B40B0
void __fastcall Scaleform::Render::Text::ParagraphFormat::SetTabStopsElement(Scaleform::Render::Text::ParagraphFormat *this, unsigned int idx, unsigned int val)
{
  unsigned int *v3; // r9

  v3 = this->pTabStops;
  if ( v3 )
  {
    if ( idx < *v3 )
      v3[idx + 1] = val;
  }
}

// File Line: 566
// RVA: 0x957FE0
void __fastcall Scaleform::Render::Text::ParagraphFormat::AllocTabStops(Scaleform::Render::Text::ParagraphFormat *this, unsigned int num)
{
  Scaleform::Render::Text::ParagraphFormat *v2; // rbx
  unsigned int v3; // edi
  unsigned int *v4; // rax

  v2 = this;
  v3 = num;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
  v2->pTabStops = 0i64;
  v4 = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                         Scaleform::Memory::pGlobalHeap,
                         4i64 * (v3 + 1),
                         0i64);
  v2->pTabStops = v4;
  *v4 = v3;
}

// File Line: 573
// RVA: 0x97E670
void __fastcall Scaleform::Render::Text::ParagraphFormat::FreeTabStops(Scaleform::Render::Text::ParagraphFormat *this)
{
  Scaleform::Render::Text::ParagraphFormat *v1; // rbx

  v1 = this;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
  v1->pTabStops = 0i64;
}

// File Line: 579
// RVA: 0x9B8970
bool __fastcall Scaleform::Render::Text::ParagraphFormat::TabStopsEqual(Scaleform::Render::Text::ParagraphFormat *this, const unsigned int *psrcTabStops)
{
  unsigned int *v2; // rcx

  v2 = this->pTabStops;
  if ( v2 == psrcTabStops )
    return 1;
  if ( v2 && psrcTabStops && *v2 == *psrcTabStops )
    return memcmp(v2 + 1, psrcTabStops + 1, 4i64 * *v2) == 0;
  return 0;
}

// File Line: 595
// RVA: 0x965190
void __fastcall Scaleform::Render::Text::ParagraphFormat::CopyTabStops(Scaleform::Render::Text::ParagraphFormat *this, const unsigned int *psrcTabStops)
{
  const unsigned int *v2; // rdi
  Scaleform::Render::Text::ParagraphFormat *v3; // rbx
  __int64 v4; // rsi
  unsigned int *v5; // rdx
  unsigned int *v6; // rax

  v2 = psrcTabStops;
  v3 = this;
  if ( psrcTabStops )
  {
    v4 = *psrcTabStops;
    v5 = this->pTabStops;
    if ( !v5 || *v5 != (_DWORD)v4 )
    {
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v3->pTabStops = 0i64;
      v6 = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                             Scaleform::Memory::pGlobalHeap,
                             4i64 * (unsigned int)(v4 + 1),
                             0i64);
      v3->pTabStops = v6;
      *v6 = v4;
    }
    memmove(v3->pTabStops + 1, v2 + 1, 4 * v4);
  }
  else
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
    v3->pTabStops = 0i64;
  }
}

// File Line: 610
// RVA: 0x94E280
Scaleform::Render::Text::ParagraphFormat *__fastcall Scaleform::Render::Text::ParagraphFormat::operator=(Scaleform::Render::Text::ParagraphFormat *this, Scaleform::Render::Text::ParagraphFormat *src)
{
  Scaleform::Render::Text::ParagraphFormat *v2; // rbx

  v2 = this;
  this->BlockIndent = src->BlockIndent;
  this->Indent = src->Indent;
  this->Leading = src->Leading;
  this->LeftMargin = src->LeftMargin;
  this->RightMargin = src->RightMargin;
  this->PresentMask = src->PresentMask;
  Scaleform::Render::Text::ParagraphFormat::CopyTabStops(this, src->pTabStops);
  return v2;
}

// File Line: 622
// RVA: 0x95BE30
unsigned __int64 __fastcall Scaleform::Render::Text::ParagraphFormat::HashFunctor::CalcHash(Scaleform::Render::Text::ParagraphFormat *data)
{
  unsigned __int16 v1; // r8
  unsigned __int8 v2; // r11
  Scaleform::Render::Text::ParagraphFormat *v3; // r9
  signed __int64 v4; // rax
  unsigned int *v5; // r10
  signed __int64 i; // rdx
  __int64 v7; // rcx

  v1 = data->PresentMask;
  v2 = 0;
  v3 = data;
  v4 = 0i64;
  if ( ((unsigned __int8)v1 >> 6) & 1 )
  {
    v5 = data->pTabStops;
    if ( v5 )
    {
      v4 = 5381i64;
      for ( i = 4i64 * (*v5 + 1); i; v4 = v7 + 65599 * v4 )
        v7 = *((unsigned __int8 *)v5 + i-- - 1);
    }
  }
  if ( ((unsigned __int8)v1 >> 1) & 1 )
    v4 = v3->BlockIndent ^ (unsigned __int64)v4;
  if ( ((unsigned __int8)v1 >> 2) & 1 )
    v4 ^= (signed __int64)v3->Indent << 8;
  if ( ((unsigned __int8)v1 >> 3) & 1 )
    v4 ^= (signed __int64)v3->Leading << 12;
  if ( ((unsigned __int8)v1 >> 4) & 1 )
    v4 ^= (unsigned __int64)v3->LeftMargin << 16;
  if ( ((unsigned __int8)v1 >> 5) & 1 )
    v4 ^= (unsigned __int64)v3->RightMargin << 18;
  if ( (v1 & 0x80u) != 0 && (v1 & 0x8000u) != 0 )
    v2 = 1;
  return ((unsigned __int64)v1 >> 1) & 0xC00 ^ (v2 | ((unsigned __int64)v1 << 9) | ((unsigned __int64)v1 >> 8) & 6) ^ v4;
}

// File Line: 644
// RVA: 0x958660
Scaleform::Render::Text::TextFormat *__fastcall Scaleform::Render::Text::Allocator::AllocateTextFormat(Scaleform::Render::Text::Allocator *this, Scaleform::Render::Text::TextFormat *srcfmt)
{
  Scaleform::Render::Text::TextFormat *v2; // rsi
  Scaleform::Render::Text::Allocator *v3; // rdi
  signed __int64 v4; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v5; // r9
  signed __int64 v6; // r8
  signed __int64 v7; // rcx
  unsigned __int64 *v8; // rdx
  signed __int64 v9; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v11; // rcx
  Scaleform::Render::Text::TextFormat *v12; // rax
  Scaleform::Render::Text::TextFormat *v13; // rax
  Scaleform::Render::Text::TextFormat *v14; // rbx
  Scaleform::Render::Text::FontHandle *v15; // rcx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *v16; // rdi
  signed __int64 v17; // rax
  unsigned __int64 v18; // rsi
  signed __int64 v19; // rax
  Scaleform::Render::Text::TextFormat *key; // [rsp+48h] [rbp+10h]

  v2 = srcfmt;
  v3 = this;
  if ( !((srcfmt->PresentMask >> 9) & 1) )
  {
    if ( this->TextFormatStorage.pTable )
    {
      v4 = Scaleform::Render::Text::TextFormat::HashFunctor::CalcHash(srcfmt);
      v5 = v3->TextFormatStorage.pTable;
      v6 = v4 & v5->SizeMask;
      v7 = v6;
      v8 = &v5->EntryCount + v6 + 2 * (v6 + 1);
      if ( *v8 != -2i64 && v8[1] == v6 )
      {
        while ( v8[1] != v6 || (Scaleform::Render::Text::TextFormat *)v8[2] != v2 )
        {
          v7 = *v8;
          if ( *v8 == -1i64 )
            goto LABEL_12;
          v8 = &v5->EntryCount + v7 + 2 * (v7 + 1);
        }
        if ( v7 >= 0 )
        {
          v9 = (signed __int64)v5 + 8 * (v7 + 2 * (v7 + 2));
          if ( v9 )
          {
            ++*(_DWORD *)(*(_QWORD *)v9 + 8i64);
            return *(Scaleform::Render::Text::TextFormat **)v9;
          }
        }
      }
    }
LABEL_12:
    v11 = v3->TextFormatStorage.pTable;
    if ( v11 )
      v11 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *)v11->EntryCount;
    if ( (unsigned __int64)v11 >= v3->TextFormatStorageCap )
      Scaleform::Render::Text::Allocator::FlushTextFormatCache(v3, 0);
  }
  v12 = (Scaleform::Render::Text::TextFormat *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->pHeap->vfptr->Alloc)(
                                                 v3->pHeap,
                                                 80i64);
  key = v12;
  if ( v12 )
  {
    Scaleform::Render::Text::TextFormat::TextFormat(v12, v2, v3);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  key = v14;
  if ( v3->Flags & 1 && (v14->PresentMask >> 11) & 1 )
  {
    v15 = v14->pFontHandle.pObject;
    if ( v15 && !_InterlockedDecrement(&v15->RefCount) && v15 )
      v15->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, 1u);
    v14->pFontHandle.pObject = 0i64;
    v14->PresentMask &= 0xF7FFu;
  }
  if ( !((v2->PresentMask >> 9) & 1) )
  {
    v16 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v3->TextFormatStorage.pTable;
    v17 = Scaleform::Render::Text::TextFormat::HashFunctor::CalcHash(v14);
    v18 = v17;
    if ( v16->pTable
      && (v19 = Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::findIndexCore<Scaleform::Render::Text::TextFormat *>(
                  v16,
                  &key,
                  v17 & v16->pTable->SizeMask),
          v19 >= 0) )
    {
      *(&v16->pTable[2].EntryCount + 3 * v19) = (unsigned __int64)v14;
    }
    else
    {
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::add<Scaleform::Render::Text::TextFormat *>(
        v16,
        v16,
        &key,
        v18);
    }
  }
  return v14;
}

// File Line: 670
// RVA: 0x9584A0
Scaleform::Render::Text::ParagraphFormat *__fastcall Scaleform::Render::Text::Allocator::AllocateParagraphFormat(Scaleform::Render::Text::Allocator *this, Scaleform::Render::Text::ParagraphFormat *srcfmt)
{
  Scaleform::Render::Text::ParagraphFormat *v2; // rbp
  Scaleform::Render::Text::Allocator *v3; // rsi
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *v4; // rdi
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *v5; // rbx
  unsigned __int64 v6; // r8
  signed __int64 v7; // rcx
  unsigned __int64 *v8; // rdx
  signed __int64 v9; // rax
  Scaleform::Render::Text::ParagraphFormat *result; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *v11; // rax
  Scaleform::Render::Text::ParagraphFormat *v12; // rbx
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rax
  unsigned __int64 v15; // r8
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rcx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *v18; // rax
  unsigned __int64 v19; // rax
  Scaleform::Render::Text::ParagraphFormat *v20; // rax
  Scaleform::Render::Text::ParagraphFormat *v21; // rax
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rbp
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > v24; // rsi
  signed __int64 v25; // rax
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+50h] [rbp+8h]
  Scaleform::Render::Text::ParagraphFormat *v27; // [rsp+60h] [rbp+18h]

  key = (Scaleform::Render::Text::ParagraphFormat *)this;
  v2 = srcfmt;
  v3 = this;
  v4 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&this->ParagraphFormatStorage.pTable;
  v5 = this->ParagraphFormatStorage.pTable;
  if ( !v5 )
    goto LABEL_11;
  v6 = Scaleform::Render::Text::ParagraphFormat::HashFunctor::CalcHash(srcfmt) & v5->SizeMask;
  v7 = v6;
  v8 = &v5->EntryCount + v6 + 2 * (v6 + 1);
  if ( *v8 == -2i64 || v8[1] != v6 )
    goto LABEL_11;
  while ( v8[1] != v6 || (Scaleform::Render::Text::ParagraphFormat *)v8[2] != v2 )
  {
    v7 = *v8;
    if ( *v8 == -1i64 )
      goto LABEL_11;
    v8 = &v5->EntryCount + v7 + 2 * (v7 + 1);
  }
  if ( v7 >= 0 && (v9 = (signed __int64)v5 + 8 * (v7 + 2 * (v7 + 2))) != 0 )
  {
    ++*(_DWORD *)(*(_QWORD *)v9 + 8i64);
    result = *(Scaleform::Render::Text::ParagraphFormat **)v9;
  }
  else
  {
LABEL_11:
    v11 = v5;
    v12 = 0i64;
    v13 = 0i64;
    if ( v11 )
      v13 = v11->EntryCount;
    if ( v13 >= v3->ParagraphFormatStorageCap )
    {
      if ( v4->pTable )
        v14 = v4->pTable->EntryCount;
      else
        v14 = 0i64;
      v15 = 5 * v14 >> 2;
      if ( v4->pTable )
        v16 = v4->pTable->EntryCount;
      else
        v16 = 0i64;
      if ( v15 > v16 )
        Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::setRawCapacity(
          v4,
          v4,
          v15);
      if ( v4->pTable )
        v17 = v4->pTable->EntryCount;
      else
        v17 = 0i64;
      v18 = v4->pTable;
      if ( v17 < v3->ParagraphFormatStorageCap )
      {
        if ( !v18 || v18->EntryCount <= 0x64 )
          v3->ParagraphFormatStorageCap = 100;
      }
      else
      {
        if ( v18 )
          v19 = v18->EntryCount;
        else
          LODWORD(v19) = 0;
        v3->ParagraphFormatStorageCap = v19 + 10;
      }
    }
    v20 = (Scaleform::Render::Text::ParagraphFormat *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v3->pHeap->vfptr->Alloc)(
                                                        v3->pHeap,
                                                        40i64);
    v27 = v20;
    if ( v20 )
    {
      Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(v20, v2, v3);
      v12 = v21;
    }
    key = v12;
    v22 = Scaleform::Render::Text::ParagraphFormat::HashFunctor::CalcHash(v12);
    v23 = v22;
    v24.pTable = v4->pTable;
    if ( v4->pTable
      && (v25 = Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::findIndexCore<Scaleform::Render::Text::ParagraphFormat *>(
                  v4,
                  &key,
                  v22 & v24.pTable->SizeMask),
          v25 >= 0) )
    {
      *(&v24.pTable[2].EntryCount + 3 * v25) = (unsigned __int64)v12;
    }
    else
    {
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::add<Scaleform::Render::Text::ParagraphFormat *>(
        v4,
        v4,
        &key,
        v23);
    }
    result = v12;
  }
  return result;
}

// File Line: 687
// RVA: 0x9C20A0
void __fastcall Scaleform::Render::Text::Allocator::VisitTextFormatCache(Scaleform::Render::Text::Allocator *this, Scaleform::Render::Text::Allocator::TextFormatVisitor *visitor)
{
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v2; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *v3; // rdi
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *v4; // r8
  Scaleform::Render::Text::Allocator::TextFormatVisitor *v5; // r14
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rcx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v8; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v9; // rcx
  __int64 v10; // rdx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v11; // rdx
  unsigned __int64 v12; // rcx
  unsigned __int64 *v13; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::Iterator v14; // [rsp+20h] [rbp-18h]

  v2 = this->TextFormatStorage.pTable;
  v3 = 0i64;
  v4 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&this->TextFormatStorage.pTable;
  v5 = visitor;
  v6 = 0i64;
  if ( v2 )
  {
    v7 = v2->SizeMask;
    v8 = v2 + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      ++v6;
      v8 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *)((char *)v8 + 24);
    }
    while ( v6 <= v7 );
    v3 = v4;
    v14.pHash = v4;
  }
  else
  {
    v14.pHash = 0i64;
  }
  v14.Index = v6;
  while ( v3 )
  {
    v9 = v3->pTable;
    if ( !v3->pTable || (signed __int64)v6 > (signed __int64)v9->SizeMask )
      break;
    v10 = *(&v9[2].EntryCount + 3 * v6);
    if ( !v10
      || !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::Allocator::TextFormatVisitor *, __int64, Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *))v5->vfptr->Visit)(
            v5,
            v10,
            v4) )
    {
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::Iterator::RemoveAlt<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>>(
        &v14,
        (Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *> *)&v3->pTable[2] + 3 * v6);
      v6 = v14.Index;
      v3 = v14.pHash;
    }
    v11 = v3->pTable;
    v12 = v3->pTable->SizeMask;
    if ( (signed __int64)v6 <= (signed __int64)v12 )
    {
      v14.Index = ++v6;
      if ( v6 <= v12 )
      {
        v13 = &v11->EntryCount + v6 + 2 * (v6 + 1);
        do
        {
          if ( *v13 != -2i64 )
            break;
          ++v6;
          v13 += 3;
          v14.Index = v6;
        }
        while ( v6 <= v12 );
      }
    }
  }
}

// File Line: 698
// RVA: 0x97ADC0
bool __fastcall Scaleform::Render::Text::Allocator::FlushTextFormatCache(Scaleform::Render::Text::Allocator *this, bool noAllocationsAllowed)
{
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v2; // rax
  Scaleform::Render::Text::Allocator *v3; // rsi
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // r8
  unsigned __int64 v7; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v8; // rcx
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v11; // rax
  unsigned __int64 v12; // rax

  v2 = this->TextFormatStorage.pTable;
  v3 = this;
  v4 = 0i64;
  if ( v2 )
    v4 = v2->EntryCount;
  if ( !noAllocationsAllowed )
  {
    v5 = 0i64;
    if ( v2 )
      v5 = v2->EntryCount;
    v6 = 5 * v5 >> 2;
    if ( v2 )
      v7 = v2->EntryCount;
    else
      v7 = 0i64;
    if ( v6 > v7 )
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::setRawCapacity(
        (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *)&v3->TextFormatStorage.pTable,
        &v3->TextFormatStorage,
        v6);
  }
  v8 = v3->TextFormatStorage.pTable;
  v9 = 0i64;
  if ( v8 )
    v9 = v8->EntryCount;
  if ( v9 < v3->TextFormatStorageCap )
  {
    if ( !v8 || v8->EntryCount <= 0x64 )
      v3->TextFormatStorageCap = 100;
  }
  else
  {
    LODWORD(v10) = 0;
    if ( v8 )
      v10 = v8->EntryCount;
    v3->TextFormatStorageCap = v10 + 10;
  }
  v11 = v3->TextFormatStorage.pTable;
  if ( v11 )
    v12 = v11->EntryCount;
  else
    v12 = 0i64;
  return v4 != v12;
}

// File Line: 717
// RVA: 0x97ACF0
bool __fastcall Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(Scaleform::Render::Text::Allocator *this, bool noAllocationsAllowed)
{
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *v2; // rax
  Scaleform::Render::Text::Allocator *v3; // rsi
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // r8
  unsigned __int64 v7; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *v8; // rcx
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *v11; // rax
  unsigned __int64 v12; // rax

  v2 = this->ParagraphFormatStorage.pTable;
  v3 = this;
  v4 = 0i64;
  if ( v2 )
    v4 = v2->EntryCount;
  if ( !noAllocationsAllowed )
  {
    v5 = 0i64;
    if ( v2 )
      v5 = v2->EntryCount;
    v6 = 5 * v5 >> 2;
    if ( v2 )
      v7 = v2->EntryCount;
    else
      v7 = 0i64;
    if ( v6 > v7 )
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::setRawCapacity(
        (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *)&v3->ParagraphFormatStorage.pTable,
        &v3->ParagraphFormatStorage,
        v6);
  }
  v8 = v3->ParagraphFormatStorage.pTable;
  v9 = 0i64;
  if ( v8 )
    v9 = v8->EntryCount;
  if ( v9 < v3->ParagraphFormatStorageCap )
  {
    if ( !v8 || v8->EntryCount <= 0x64 )
      v3->ParagraphFormatStorageCap = 100;
  }
  else
  {
    LODWORD(v10) = 0;
    if ( v8 )
      v10 = v8->EntryCount;
    v3->ParagraphFormatStorageCap = v10 + 10;
  }
  v11 = v3->ParagraphFormatStorage.pTable;
  if ( v11 )
    v12 = v11->EntryCount;
  else
    v12 = 0i64;
  return v4 != v12;
}

