// File Line: 24
// RVA: 0x985280
unsigned __int64 __fastcall Scaleform::Render::Text::HTMLImageTagDesc::GetHash(
        Scaleform::Render::Text::HTMLImageTagDesc *this)
{
  __int64 v2; // rdx
  unsigned __int64 v3; // rax
  __int64 v4; // r8
  __int64 v5; // rcx
  unsigned __int64 v6; // r9
  _QWORD *v7; // rcx
  __int64 i; // r10
  int v9; // edx
  unsigned __int64 v10; // r9
  _QWORD *v11; // rcx
  __int64 j; // r8
  int v13; // edx
  char v15; // [rsp+1h] [rbp-29h]
  __int64 VSpace; // [rsp+2h] [rbp-28h]
  __int64 HSpace; // [rsp+Ah] [rbp-20h]
  __int64 ParaId; // [rsp+12h] [rbp-18h]
  __int64 Alignment; // [rsp+1Ah] [rbp-10h]

  v2 = 32i64;
  VSpace = this->VSpace;
  HSpace = this->HSpace;
  ParaId = this->ParaId;
  Alignment = (unsigned __int8)this->Alignment;
  v3 = 5381i64;
  v4 = 5381i64;
  do
  {
    v5 = (unsigned __int8)*(&v15 + v2--);
    v4 = v5 + 65599 * v4;
  }
  while ( v2 );
  v6 = 5381i64;
  v7 = (_QWORD *)(this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  for ( i = *v7 & 0x7FFFFFFFFFFFFFFFi64; i; v6 = v9 ^ (33 * v6) )
  {
    v9 = *((unsigned __int8 *)v7 + i-- + 11);
    if ( (unsigned int)(v9 - 65) <= 0x19 )
      v9 += 32;
  }
  v10 = v4 ^ v6;
  v11 = (_QWORD *)(this->Id.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  for ( j = *v11 & 0x7FFFFFFFFFFFFFFFi64; j; v3 = v13 ^ (33 * v3) )
  {
    v13 = *((unsigned __int8 *)v11 + j-- + 11);
    if ( (unsigned int)(v13 - 65) <= 0x19 )
      v13 += 32;
  }
  return v10 ^ v3;
}

// File Line: 43
// RVA: 0x945FC0
void __fastcall Scaleform::Render::Text::TextFormat::TextFormat(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::MemoryHeap *pheap)
{
  Scaleform::MemoryHeap *v3; // rax
  Scaleform::MemoryHeap *v4; // rcx

  this->pAllocator = 0i64;
  this->RefCount = 1;
  v3 = Scaleform::Memory::pGlobalHeap;
  if ( pheap )
    v3 = pheap;
  this->FontList.pHeap = v3;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
  v4 = Scaleform::Memory::pGlobalHeap;
  if ( pheap )
    v4 = pheap;
  this->Url.pHeap = v4;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  this->Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
  this->pImageDesc.pObject = 0i64;
  this->pFontHandle.pObject = 0i64;
  this->ColorV = -16777216;
  this->LetterSpacing = 0.0;
  this->FontSize = 0;
  this->FormatFlags = 0;
  this->PresentMask = 0;
}

// File Line: 59
// RVA: 0x945F00
void __fastcall Scaleform::Render::Text::TextFormat::TextFormat(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *srcfmt,
        Scaleform::Render::Text::Allocator *allocator)
{
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // rax
  Scaleform::Render::Text::FontHandle *v6; // rax

  this->pAllocator = allocator;
  this->RefCount = 1;
  Scaleform::StringDH::CopyConstructHelper(&this->FontList, &srcfmt->FontList, srcfmt->FontList.pHeap);
  Scaleform::StringDH::CopyConstructHelper(&this->Url, &srcfmt->Url, srcfmt->FontList.pHeap);
  pObject = srcfmt->pImageDesc.pObject;
  if ( pObject )
    ++pObject->RefCount;
  this->pImageDesc.pObject = srcfmt->pImageDesc.pObject;
  v6 = srcfmt->pFontHandle.pObject;
  if ( v6 )
    _InterlockedExchangeAdd(&v6->RefCount, 1u);
  this->pFontHandle.pObject = srcfmt->pFontHandle.pObject;
  this->ColorV = srcfmt->ColorV;
  this->LetterSpacing = srcfmt->LetterSpacing;
  this->FontSize = srcfmt->FontSize;
  this->FormatFlags = srcfmt->FormatFlags;
  this->PresentMask = srcfmt->PresentMask;
}

// File Line: 63
// RVA: 0x94D0E0
void __fastcall Scaleform::Render::Text::TextFormat::~TextFormat(Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Render::Text::Allocator *pAllocator; // rcx
  Scaleform::Render::Text::FontHandle *pObject; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *v4; // rcx
  Scaleform::Render::Text::TextFormat *key; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::StringDH *p_Url; // [rsp+50h] [rbp+18h]

  pAllocator = this->pAllocator;
  if ( pAllocator )
  {
    key = this;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::TextFormat *>(
      &pAllocator->TextFormatStorage,
      &key);
  }
  pObject = this->pFontHandle.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  v4 = this->pImageDesc.pObject;
  if ( v4 )
  {
    if ( v4->RefCount-- == 1 )
      v4->vfptr->__vecDelDtor(v4, 1u);
  }
  p_Url = &this->Url;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 70
// RVA: 0x9AFAA0
void __fastcall Scaleform::Render::Text::TextFormat::SetFontList(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::String *fontList)
{
  __int64 Length; // rbx
  Scaleform::Render::Text::FontHandle *pObject; // rcx
  Scaleform::String::DataDesc *pData; // rcx

  if ( (this->PresentMask & 0x800) != 0 )
  {
    Length = Scaleform::String::GetLength(&this->FontList);
    if ( Length != Scaleform::String::GetLength(fontList)
      || stricmp(
           (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
           (const char *)((fontList->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
    {
      pObject = this->pFontHandle.pObject;
      if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
        pObject->vfptr->__vecDelDtor(pObject, 1u);
      this->pFontHandle.pObject = 0i64;
      this->PresentMask &= ~0x800u;
    }
  }
  Scaleform::String::operator=(&this->FontList, fontList);
  pData = this->FontList.pData;
  this->PresentMask |= 4u;
  if ( strchr((const char *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 12), 44) )
    this->PresentMask &= ~0x1000u;
  else
    this->PresentMask |= 0x1000u;
}

// File Line: 90
// RVA: 0x9AFB90
void __fastcall Scaleform::Render::Text::TextFormat::SetFontList(
        Scaleform::Render::Text::TextFormat *this,
        const char *pfontList,
        unsigned __int64 fontListSz)
{
  unsigned __int64 v3; // rbx
  Scaleform::Render::Text::FontHandle *pObject; // rcx
  Scaleform::String::DataDesc *pData; // rcx

  v3 = fontListSz;
  if ( fontListSz == -1i64 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( pfontList[v3] );
  }
  if ( (this->PresentMask & 0x800) != 0
    && (Scaleform::String::GetLength(&this->FontList) != v3
     || (unsigned int)Scaleform::String::CompareNoCase(
                        (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                        pfontList,
                        v3)) )
  {
    pObject = this->pFontHandle.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    this->pFontHandle.pObject = 0i64;
    this->PresentMask &= ~0x800u;
  }
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (__int64)this->FontList.pData & 3;
  Scaleform::String::AppendString(&this->FontList, pfontList, v3);
  pData = this->FontList.pData;
  this->PresentMask |= 4u;
  if ( strchr((const char *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 12), 44) )
    this->PresentMask &= ~0x1000u;
  else
    this->PresentMask |= 0x1000u;
}

// File Line: 118
// RVA: 0x9AFCD0
void __fastcall Scaleform::Render::Text::TextFormat::SetFontList(
        Scaleform::Render::Text::TextFormat *this,
        const wchar_t *pfontList,
        unsigned __int64 fontListSz)
{
  unsigned __int64 v3; // rdi
  unsigned __int64 v6; // rbp
  char *v7; // r14
  int v8; // ebx
  Scaleform::Render::Text::FontHandle *pObject; // rcx
  Scaleform::String::DataDesc *pData; // rcx

  v3 = fontListSz;
  if ( fontListSz == -1i64 )
  {
    v3 = -1i64;
    do
      ++v3;
    while ( pfontList[v3] );
  }
  if ( (this->PresentMask & 0x800) != 0 )
  {
    if ( Scaleform::String::GetLength(&this->FontList) == v3 )
    {
      v6 = 0i64;
      if ( !v3 )
        goto LABEL_15;
      v7 = (char *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
      while ( 1 )
      {
        v8 = Scaleform::SFtowlower(pfontList[v6]);
        if ( (unsigned int)Scaleform::SFtowlower(*v7) != v8 )
          break;
        ++v6;
        ++v7;
        if ( v6 >= v3 )
          goto LABEL_15;
      }
    }
    pObject = this->pFontHandle.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    this->pFontHandle.pObject = 0i64;
    this->PresentMask &= ~0x800u;
  }
LABEL_15:
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (__int64)this->FontList.pData & 3;
  Scaleform::String::AppendString(&this->FontList, pfontList, v3);
  pData = this->FontList.pData;
  this->PresentMask |= 4u;
  if ( strchr((const char *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 12), 44) )
    this->PresentMask &= ~0x1000u;
  else
    this->PresentMask |= 0x1000u;
}

// File Line: 154
// RVA: 0x984840
Scaleform::StringDH *__fastcall Scaleform::Render::Text::TextFormat::GetFontList(
        Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::StringDH *result; // rax

  if ( (_S9_20 & 1) == 0 )
  {
    _S9_20 |= 1u;
    emptyStr.pData = &Scaleform::String::NullData;
    _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
    atexit(Scaleform::Render::Text::TextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__);
  }
  result = &this->FontList;
  if ( (this->PresentMask & 4) == 0 )
    return (Scaleform::StringDH *)&emptyStr;
  return result;
}

// File Line: 160
// RVA: 0x9AFE60
// attributes: thunk
void __fastcall Scaleform::Render::Text::TextFormat::SetFontName(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::String *fontName)
{
  Scaleform::Render::Text::TextFormat::SetFontList(this, fontName);
}

// File Line: 169
// RVA: 0x9AFE70
void __fastcall Scaleform::Render::Text::TextFormat::SetFontName(
        Scaleform::Render::Text::TextFormat *this,
        const char *pfontName,
        unsigned __int64 fontNameSz)
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
void __fastcall Scaleform::Render::Text::TextFormat::SetFontHandle(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::FontHandle *pfontHandle)
{
  Scaleform::Render::Text::FontHandle *pObject; // rcx

  if ( pfontHandle )
    _InterlockedExchangeAdd(&pfontHandle->RefCount, 1u);
  pObject = this->pFontHandle.pObject;
  if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
    pObject->vfptr->__vecDelDtor(pObject, 1u);
  this->pFontHandle.pObject = pfontHandle;
  this->PresentMask |= 0x800u;
}

// File Line: 205
// RVA: 0x9B50E0
void __fastcall Scaleform::Render::Text::TextFormat::SetUrl(
        Scaleform::Render::Text::TextFormat *this,
        const char *purl,
        unsigned __int64 urlSz)
{
  unsigned __int64 v3; // rbx

  v3 = urlSz;
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
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (__int64)this->Url.pData & 3;
  Scaleform::String::AppendString(&this->Url, purl, v3);
  this->PresentMask |= 0x100u;
}

// File Line: 215
// RVA: 0x9B5190
void __fastcall Scaleform::Render::Text::TextFormat::SetUrl(
        Scaleform::Render::Text::TextFormat *this,
        const wchar_t *purl,
        __int64 urlSz)
{
  __int64 v3; // rbx

  v3 = urlSz;
  if ( urlSz == -1 )
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
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (__int64)this->Url.pData & 3;
  Scaleform::String::AppendString(&this->Url, purl, v3);
  this->PresentMask |= 0x100u;
}

// File Line: 232
// RVA: 0x9AE450
void __fastcall Scaleform::Render::Text::TextFormat::SetBold(Scaleform::Render::Text::TextFormat *this, bool bold)
{
  Scaleform::Render::Text::FontHandle *pObject; // rcx

  if ( (this->PresentMask & 0x800) != 0 && (this->FormatFlags & 1) != bold )
  {
    pObject = this->pFontHandle.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    this->pFontHandle.pObject = 0i64;
    this->PresentMask &= ~0x800u;
  }
  if ( bold )
    this->FormatFlags |= 1u;
  else
    this->FormatFlags &= ~1u;
  this->PresentMask |= 0x10u;
}

// File Line: 251
// RVA: 0x9B0E20
void __fastcall Scaleform::Render::Text::TextFormat::SetItalic(Scaleform::Render::Text::TextFormat *this, bool italic)
{
  Scaleform::Render::Text::FontHandle *pObject; // rcx

  if ( (this->PresentMask & 0x800) != 0 && ((this->FormatFlags & 2) != 0) != italic )
  {
    pObject = this->pFontHandle.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    this->pFontHandle.pObject = 0i64;
    this->PresentMask &= ~0x800u;
  }
  if ( italic )
    this->FormatFlags |= 2u;
  else
    this->FormatFlags &= ~2u;
  this->PresentMask |= 0x20u;
}

// File Line: 270
// RVA: 0x9B4EA0
void __fastcall Scaleform::Render::Text::TextFormat::SetUnderline(
        Scaleform::Render::Text::TextFormat *this,
        bool underline)
{
  if ( underline )
    this->FormatFlags |= 4u;
  else
    this->FormatFlags &= ~4u;
  this->PresentMask |= 0x40u;
}

// File Line: 283
// RVA: 0x9B0EB0
void __fastcall Scaleform::Render::Text::TextFormat::SetKerning(
        Scaleform::Render::Text::TextFormat *this,
        bool kerning)
{
  if ( kerning )
    this->FormatFlags |= 8u;
  else
    this->FormatFlags &= ~8u;
  this->PresentMask |= 0x80u;
}

// File Line: 296
// RVA: 0x997770
bool __fastcall Scaleform::Render::Text::TextFormat::IsFontSame(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *fmt)
{
  char FormatFlags; // cl
  char v5; // dl
  bool result; // al

  result = 0;
  if ( (this->PresentMask & 4) != 0
    && (fmt->PresentMask & 4) != 0
    && !stricmp(
          (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          (const char *)((fmt->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12))
    || (this->PresentMask & 0x800) != 0
    && (fmt->PresentMask & 0x800) != 0
    && this->pFontHandle.pObject == fmt->pFontHandle.pObject )
  {
    FormatFlags = this->FormatFlags;
    v5 = fmt->FormatFlags;
    if ( (((unsigned __int8)v5 ^ (unsigned __int8)FormatFlags) & 1) == 0
      && (((unsigned __int8)v5 ^ (unsigned __int8)FormatFlags) & 2) == 0 )
    {
      return 1;
    }
  }
  return result;
}

// File Line: 303
// RVA: 0x997850
bool __fastcall Scaleform::Render::Text::TextFormat::IsHTMLFontTagSame(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *fmt)
{
  return ((this->PresentMask & 4) != 0
       && (fmt->PresentMask & 4) != 0
       && !stricmp(
             (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
             (const char *)((fmt->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12))
       || (this->PresentMask & 0x800) != 0
       && (fmt->PresentMask & 0x800) != 0
       && this->pFontHandle.pObject == fmt->pFontHandle.pObject)
      && ((this->ColorV ^ fmt->ColorV) & 0xFFFFFF) == 0
      && HIBYTE(this->ColorV) == HIBYTE(fmt->ColorV)
      && (float)((float)this->FontSize * 0.050000001) == (float)((float)fmt->FontSize * 0.050000001)
      && ((this->FormatFlags ^ fmt->FormatFlags) & 8) == 0
      && (float)(this->LetterSpacing * 0.050000001) == (float)(fmt->LetterSpacing * 0.050000001);
}

// File Line: 312
// RVA: 0x99B130
Scaleform::Render::Text::TextFormat *__fastcall Scaleform::Render::Text::TextFormat::Merge(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *result,
        Scaleform::Render::Text::TextFormat *fmt)
{
  char v5; // si
  Scaleform::Render::Text::FontHandle *v6; // rcx
  Scaleform::Render::Text::FontHandle *pObject; // r8
  char FormatFlags; // cl
  __int16 PresentMask; // dx
  bool v10; // si
  char v11; // al
  unsigned __int16 v12; // dx
  char v13; // al
  char v14; // al
  unsigned int ColorV; // ecx
  Scaleform::StringDH *p_FontList; // rdx
  Scaleform::Render::RenderBuffer *FontHandle; // rax
  Scaleform::Render::Text::FontHandle *v18; // rsi
  Scaleform::Render::Text::FontHandle *v19; // rcx
  unsigned __int16 v20; // ax
  Scaleform::Render::Text::HTMLImageTagDesc *ImageDesc; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v22; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v23; // rcx
  Scaleform::Render::Text::TextFormat srcfmt; // [rsp+30h] [rbp-50h] BYREF

  Scaleform::Render::Text::TextFormat::TextFormat(&srcfmt, this, 0i64);
  if ( (fmt->PresentMask & 0x10) != 0 )
  {
    v5 = fmt->FormatFlags & 1;
    if ( (srcfmt.PresentMask & 0x800) == 0 || (srcfmt.FormatFlags & 1) == v5 )
    {
      pObject = srcfmt.pFontHandle.pObject;
    }
    else
    {
      v6 = srcfmt.pFontHandle.pObject;
      if ( srcfmt.pFontHandle.pObject && !_InterlockedDecrement(&srcfmt.pFontHandle.pObject->RefCount) && v6 )
        v6->vfptr->__vecDelDtor(v6, 1u);
      pObject = 0i64;
      srcfmt.pFontHandle.pObject = 0i64;
      srcfmt.PresentMask &= ~0x800u;
    }
    if ( v5 )
    {
      FormatFlags = srcfmt.FormatFlags | 1;
      srcfmt.FormatFlags |= 1u;
    }
    else
    {
      FormatFlags = srcfmt.FormatFlags & 0xFE;
      srcfmt.FormatFlags &= ~1u;
    }
    PresentMask = srcfmt.PresentMask | 0x10;
    srcfmt.PresentMask |= 0x10u;
  }
  else
  {
    PresentMask = srcfmt.PresentMask;
    FormatFlags = srcfmt.FormatFlags;
    pObject = srcfmt.pFontHandle.pObject;
  }
  if ( (fmt->PresentMask & 0x20) != 0 )
  {
    v10 = (fmt->FormatFlags & 2) != 0;
    if ( (PresentMask & 0x800) != 0 && ((FormatFlags & 2) != 0) != v10 )
    {
      if ( pObject )
      {
        if ( !_InterlockedDecrement(&pObject->RefCount) )
          pObject->vfptr->__vecDelDtor(pObject, 1u);
        FormatFlags = srcfmt.FormatFlags;
      }
      srcfmt.pFontHandle.pObject = 0i64;
      srcfmt.PresentMask &= ~0x800u;
    }
    if ( v10 )
      v11 = FormatFlags | 2;
    else
      v11 = FormatFlags & 0xFD;
    srcfmt.FormatFlags = v11;
    FormatFlags = v11;
    srcfmt.PresentMask |= 0x20u;
  }
  v12 = fmt->PresentMask;
  if ( (v12 & 0x40) != 0 )
  {
    if ( (fmt->FormatFlags & 4) != 0 )
      v13 = FormatFlags | 4;
    else
      v13 = FormatFlags & 0xFB;
    srcfmt.FormatFlags = v13;
    FormatFlags = v13;
    srcfmt.PresentMask |= 0x40u;
  }
  if ( (v12 & 0x80u) != 0 )
  {
    if ( (fmt->FormatFlags & 8) != 0 )
      v14 = FormatFlags | 8;
    else
      v14 = FormatFlags & 0xF7;
    srcfmt.FormatFlags = v14;
    srcfmt.PresentMask |= 0x80u;
  }
  if ( (fmt->PresentMask & 1) != 0 )
  {
    ColorV = fmt->ColorV;
    srcfmt.ColorV = ColorV;
    srcfmt.PresentMask |= 1u;
  }
  else
  {
    ColorV = srcfmt.ColorV;
  }
  if ( (v12 & 0x400) != 0 )
  {
    srcfmt.ColorV = ColorV & 0xFFFFFF | (HIBYTE(fmt->ColorV) << 24);
    srcfmt.PresentMask |= 0x400u;
  }
  if ( (v12 & 2) != 0 )
  {
    srcfmt.LetterSpacing = (float)(__int16)(int)fmt->LetterSpacing;
    srcfmt.PresentMask |= 2u;
  }
  if ( (v12 & 8) != 0 )
  {
    srcfmt.FontSize = fmt->FontSize;
    srcfmt.PresentMask |= 8u;
  }
  if ( (v12 & 4) != 0 )
  {
    if ( (_S9_20 & 1) == 0 )
    {
      _S9_20 |= 1u;
      emptyStr.pData = &Scaleform::String::NullData;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      atexit(Scaleform::Render::Text::TextFormat::GetFontList_::_2_::_dynamic_atexit_destructor_for__emptyStr__);
    }
    p_FontList = &fmt->FontList;
    if ( (fmt->PresentMask & 4) == 0 )
      p_FontList = (Scaleform::StringDH *)&emptyStr;
    Scaleform::Render::Text::TextFormat::SetFontList(&srcfmt, p_FontList);
  }
  if ( (fmt->PresentMask & 0x800) != 0 )
  {
    FontHandle = Scaleform::Render::Text::TextFormat::GetFontHandle(fmt);
    v18 = (Scaleform::Render::Text::FontHandle *)FontHandle;
    if ( FontHandle )
      _InterlockedExchangeAdd(&FontHandle->RefCount, 1u);
    v19 = srcfmt.pFontHandle.pObject;
    if ( srcfmt.pFontHandle.pObject && !_InterlockedDecrement(&srcfmt.pFontHandle.pObject->RefCount) && v19 )
      v19->vfptr->__vecDelDtor(v19, 1u);
    srcfmt.pFontHandle.pObject = v18;
    srcfmt.PresentMask |= 0x800u;
  }
  if ( (fmt->PresentMask & 0x100) != 0 )
  {
    if ( !Scaleform::String::GetLength(&fmt->Url) )
    {
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      if ( !_InterlockedDecrement((volatile signed __int32 *)((srcfmt.Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      srcfmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (__int64)srcfmt.Url.pData & 3;
      v20 = srcfmt.PresentMask & 0xFEFF;
      goto LABEL_68;
    }
    if ( (fmt->PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&fmt->Url) )
    {
      Scaleform::String::operator=(&srcfmt.Url, &fmt->Url);
      v20 = srcfmt.PresentMask | 0x100;
LABEL_68:
      srcfmt.PresentMask = v20;
    }
  }
  if ( (fmt->PresentMask & 0x200) != 0 )
  {
    ImageDesc = Scaleform::Render::Text::TextFormat::GetImageDesc(fmt);
    v22 = ImageDesc;
    if ( ImageDesc )
      ++ImageDesc->RefCount;
    v23 = srcfmt.pImageDesc.pObject;
    if ( srcfmt.pImageDesc.pObject )
    {
      --srcfmt.pImageDesc.pObject->RefCount;
      if ( !v23->RefCount )
        v23->vfptr->__vecDelDtor(v23, 1u);
    }
    srcfmt.pImageDesc.pObject = v22;
    srcfmt.PresentMask |= 0x200u;
  }
  Scaleform::Render::Text::TextFormat::TextFormat(result, &srcfmt, 0i64);
  Scaleform::Render::Text::TextFormat::~TextFormat(&srcfmt);
  return result;
}

// File Line: 344
// RVA: 0x996CF0
Scaleform::Render::Text::TextFormat *__fastcall Scaleform::Render::Text::TextFormat::Intersection(
        Scaleform::Render::Text::TextFormat *this,
        Scaleform::Render::Text::TextFormat *result,
        Scaleform::Render::Text::TextFormat *fmt)
{
  Scaleform::MemoryHeap *pHeap; // r9
  Scaleform::MemoryHeap *v7; // rax
  Scaleform::MemoryHeap *v8; // rax
  char v9; // di
  char FormatFlags; // cl
  __int16 PresentMask; // dx
  bool v12; // di
  char v13; // al
  unsigned __int16 v14; // dx
  char v15; // al
  char v16; // al
  unsigned int ColorV; // ecx
  unsigned __int8 ColorV_high; // al
  Scaleform::StringDH *FontList; // rax
  Scaleform::Render::RenderBuffer *FontHandle; // rdi
  Scaleform::Render::RenderBuffer *v21; // rax
  Scaleform::Render::Text::FontHandle *v22; // rdi
  Scaleform::Render::Text::FontHandle *pObject; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *ImageDesc; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v25; // rax
  Scaleform::Render::Text::HTMLImageTagDesc *v26; // rbx
  Scaleform::Render::Text::HTMLImageTagDesc *v27; // rcx
  Scaleform::Render::Text::TextFormat srcfmt; // [rsp+30h] [rbp-50h] BYREF

  pHeap = fmt->FontList.pHeap;
  srcfmt.pAllocator = 0i64;
  srcfmt.RefCount = 1;
  v7 = Scaleform::Memory::pGlobalHeap;
  if ( pHeap )
    v7 = pHeap;
  srcfmt.FontList.pHeap = v7;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  srcfmt.FontList.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
  v8 = Scaleform::Memory::pGlobalHeap;
  if ( pHeap )
    v8 = pHeap;
  srcfmt.Url.pHeap = v8;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  srcfmt.Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData.Size + 2;
  srcfmt.pImageDesc.pObject = 0i64;
  srcfmt.pFontHandle.pObject = 0i64;
  srcfmt.ColorV = -16777216;
  srcfmt.LetterSpacing = 0.0;
  srcfmt.FontSize = 0;
  srcfmt.FormatFlags = 0;
  srcfmt.PresentMask = 0;
  if ( (this->PresentMask & 0x10) != 0
    && (fmt->PresentMask & 0x10) != 0
    && (v9 = fmt->FormatFlags & 1, (this->FormatFlags & 1) == v9) )
  {
    if ( v9 )
    {
      FormatFlags = srcfmt.FormatFlags | 1;
      srcfmt.FormatFlags |= 1u;
    }
    else
    {
      FormatFlags = srcfmt.FormatFlags & 0xFE;
      srcfmt.FormatFlags &= ~1u;
    }
    PresentMask = srcfmt.PresentMask | 0x10;
    srcfmt.PresentMask |= 0x10u;
  }
  else
  {
    PresentMask = srcfmt.PresentMask;
    FormatFlags = srcfmt.FormatFlags;
  }
  if ( (this->PresentMask & 0x20) != 0 && (fmt->PresentMask & 0x20) != 0 )
  {
    v12 = (fmt->FormatFlags & 2) != 0;
    if ( ((this->FormatFlags & 2) != 0) == v12 )
    {
      if ( (PresentMask & 0x800) != 0 && ((FormatFlags & 2) != 0) != v12 )
      {
        srcfmt.pFontHandle.pObject = 0i64;
        srcfmt.PresentMask &= ~0x800u;
      }
      if ( v12 )
        v13 = FormatFlags | 2;
      else
        v13 = FormatFlags & 0xFD;
      srcfmt.FormatFlags = v13;
      FormatFlags = v13;
      srcfmt.PresentMask |= 0x20u;
    }
  }
  v14 = this->PresentMask;
  if ( (v14 & 0x40) != 0
    && (fmt->PresentMask & 0x40) != 0
    && ((this->FormatFlags & 4) != 0) == ((fmt->FormatFlags & 4) != 0) )
  {
    if ( (fmt->FormatFlags & 4) != 0 )
      v15 = FormatFlags | 4;
    else
      v15 = FormatFlags & 0xFB;
    srcfmt.FormatFlags = v15;
    FormatFlags = v15;
    srcfmt.PresentMask |= 0x40u;
  }
  if ( (v14 & 0x80u) != 0
    && SLOBYTE(fmt->PresentMask) < 0
    && ((this->FormatFlags & 8) != 0) == ((fmt->FormatFlags & 8) != 0) )
  {
    if ( (fmt->FormatFlags & 8) != 0 )
      v16 = FormatFlags | 8;
    else
      v16 = FormatFlags & 0xF7;
    srcfmt.FormatFlags = v16;
    srcfmt.PresentMask |= 0x80u;
  }
  if ( (this->PresentMask & 1) != 0 && (fmt->PresentMask & 1) != 0 && (ColorV = fmt->ColorV, this->ColorV == ColorV) )
  {
    srcfmt.ColorV = fmt->ColorV;
    srcfmt.PresentMask |= 1u;
  }
  else
  {
    ColorV = srcfmt.ColorV;
  }
  if ( (v14 & 0x400) != 0 && (fmt->PresentMask & 0x400) != 0 )
  {
    ColorV_high = HIBYTE(fmt->ColorV);
    if ( HIBYTE(this->ColorV) == ColorV_high )
    {
      srcfmt.ColorV = ColorV & 0xFFFFFF | (ColorV_high << 24);
      srcfmt.PresentMask |= 0x400u;
    }
  }
  if ( (v14 & 2) != 0
    && (fmt->PresentMask & 2) != 0
    && (float)(this->LetterSpacing * 0.050000001) == (float)(fmt->LetterSpacing * 0.050000001) )
  {
    srcfmt.LetterSpacing = (float)(__int16)(int)fmt->LetterSpacing;
    srcfmt.PresentMask |= 2u;
  }
  if ( (v14 & 8) != 0 && (fmt->PresentMask & 8) != 0 && this->FontSize == fmt->FontSize )
  {
    srcfmt.FontSize = fmt->FontSize;
    srcfmt.PresentMask |= 8u;
  }
  if ( (v14 & 4) != 0
    && (fmt->PresentMask & 4) != 0
    && !stricmp(
          (const char *)((this->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          (const char *)((fmt->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
  {
    FontList = Scaleform::Render::Text::TextFormat::GetFontList(fmt);
    Scaleform::Render::Text::TextFormat::SetFontList(&srcfmt, FontList);
  }
  if ( (this->PresentMask & 0x800) != 0 && (fmt->PresentMask & 0x800) != 0 )
  {
    FontHandle = Scaleform::Render::Text::TextFormat::GetFontHandle(fmt);
    if ( Scaleform::Render::Text::TextFormat::GetFontHandle(this) == FontHandle )
    {
      v21 = Scaleform::Render::Text::TextFormat::GetFontHandle(fmt);
      v22 = (Scaleform::Render::Text::FontHandle *)v21;
      if ( v21 )
        _InterlockedExchangeAdd(&v21->RefCount, 1u);
      pObject = srcfmt.pFontHandle.pObject;
      if ( srcfmt.pFontHandle.pObject && !_InterlockedDecrement(&srcfmt.pFontHandle.pObject->RefCount) && pObject )
        pObject->vfptr->__vecDelDtor(pObject, 1u);
      srcfmt.pFontHandle.pObject = v22;
      srcfmt.PresentMask |= 0x800u;
    }
  }
  if ( (this->PresentMask & 0x100) != 0
    && Scaleform::String::GetLength(&this->Url)
    && (fmt->PresentMask & 0x100) != 0
    && Scaleform::String::GetLength(&fmt->Url)
    && !stricmp(
          (const char *)((this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          (const char *)((fmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12)) )
  {
    Scaleform::String::operator=(&srcfmt.Url, &fmt->Url);
    srcfmt.PresentMask |= 0x100u;
  }
  if ( (this->PresentMask & 0x200) != 0 && (fmt->PresentMask & 0x200) != 0 )
  {
    ImageDesc = Scaleform::Render::Text::TextFormat::GetImageDesc(fmt);
    if ( Scaleform::Render::Text::TextFormat::GetImageDesc(this) == ImageDesc )
    {
      v25 = Scaleform::Render::Text::TextFormat::GetImageDesc(fmt);
      v26 = v25;
      if ( v25 )
        ++v25->RefCount;
      v27 = srcfmt.pImageDesc.pObject;
      if ( srcfmt.pImageDesc.pObject )
      {
        --srcfmt.pImageDesc.pObject->RefCount;
        if ( !v27->RefCount )
          v27->vfptr->__vecDelDtor(v27, 1u);
      }
      srcfmt.pImageDesc.pObject = v26;
      srcfmt.PresentMask |= 0x200u;
    }
  }
  Scaleform::Render::Text::TextFormat::TextFormat(result, &srcfmt, 0i64);
  Scaleform::Render::Text::TextFormat::~TextFormat(&srcfmt);
  return result;
}

// File Line: 374
// RVA: 0x992D80
void __fastcall Scaleform::Render::Text::TextFormat::InitByDefaultValues(Scaleform::Render::Text::TextFormat *this)
{
  Scaleform::Render::Text::FontHandle *pObject; // rcx
  unsigned __int16 PresentMask; // ax
  Scaleform::Render::Text::FontHandle *v4; // rcx
  unsigned __int16 v5; // ax

  this->ColorV &= 0xFF000000;
  this->PresentMask |= 1u;
  Scaleform::Render::Text::TextFormat::SetFontList(this, "Times New Roman", 0xFFFFFFFFFFFFFFFFui64);
  this->PresentMask |= 8u;
  this->FontSize = 240;
  if ( (this->PresentMask & 0x800) != 0 && (this->FormatFlags & 1) != 0 )
  {
    pObject = this->pFontHandle.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    this->pFontHandle.pObject = 0i64;
    this->PresentMask &= ~0x800u;
  }
  this->PresentMask |= 0x10u;
  PresentMask = this->PresentMask;
  this->FormatFlags &= ~1u;
  if ( (PresentMask & 0x800) != 0 && (this->FormatFlags & 2) != 0 )
  {
    v4 = this->pFontHandle.pObject;
    if ( v4 && !_InterlockedDecrement(&v4->RefCount) )
      v4->vfptr->__vecDelDtor(v4, 1u);
    this->pFontHandle.pObject = 0i64;
    this->PresentMask &= ~0x800u;
  }
  v5 = this->PresentMask;
  this->FormatFlags &= 0xF1u;
  this->ColorV |= 0xFF000000;
  this->LetterSpacing = 0.0;
  this->PresentMask = v5 & 0xFB1D | 0xE0;
  _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
  if ( _InterlockedExchangeAdd(
         (volatile signed __int32 *)((this->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
         0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->Url.HeapTypeBits = (unsigned __int64)&Scaleform::String::NullData | (__int64)this->Url.pData & 3;
  this->PresentMask &= ~0x100u;
}

// File Line: 389
// RVA: 0x95BF50
signed __int64 __fastcall Scaleform::Render::Text::TextFormat::HashFunctor::CalcHash(
        Scaleform::Render::Text::TextFormat *data)
{
  __int64 LetterSpacing_low; // rcx
  bool v3; // zf
  unsigned __int16 PresentMask; // bp
  __int64 FormatFlags; // rcx
  Scaleform::Render::Text::HTMLImageTagDesc *pObject; // rcx
  unsigned __int64 v7; // rdi
  __int64 v8; // rcx
  __int64 v9; // rbx
  __int64 v10; // rax
  unsigned __int64 v11; // rdx
  _QWORD *v12; // r9
  __int64 i; // r8
  int v14; // ecx
  _QWORD *v15; // r8
  __int64 j; // rdx
  int v17; // ecx
  char v19; // [rsp+1Fh] [rbp-49h]
  __int64 ColorV; // [rsp+20h] [rbp-48h]
  __int64 v21; // [rsp+28h] [rbp-40h]
  __int64 v22; // [rsp+30h] [rbp-38h]
  __int64 v23; // [rsp+38h] [rbp-30h]
  unsigned __int64 Hash; // [rsp+40h] [rbp-28h]

  LetterSpacing_low = 0i64;
  v3 = (data->PresentMask & 1) == 0;
  ColorV = 0i64;
  Hash = 0i64;
  if ( !v3 || (data->PresentMask & 0x400) != 0 )
    ColorV = data->ColorV;
  PresentMask = data->PresentMask;
  if ( (PresentMask & 2) != 0 )
    LetterSpacing_low = LODWORD(data->LetterSpacing);
  v21 = LetterSpacing_low;
  FormatFlags = (unsigned __int8)data->FormatFlags;
  v22 = FormatFlags;
  if ( (PresentMask & 8) != 0 )
  {
    FormatFlags = (data->FontSize << 8) | (unsigned __int64)FormatFlags;
    v22 = FormatFlags;
  }
  if ( data->pFontHandle.pObject )
    v22 = FormatFlags | 0x1000000;
  v23 = PresentMask;
  if ( (PresentMask & 0x200) != 0 )
  {
    pObject = data->pImageDesc.pObject;
    if ( pObject )
      Hash = Scaleform::Render::Text::HTMLImageTagDesc::GetHash(pObject);
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
  if ( (PresentMask & 4) != 0 )
  {
    v11 = 5381i64;
    v12 = (_QWORD *)(data->FontList.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
    for ( i = *v12 & 0x7FFFFFFFFFFFFFFFi64; i; v11 = v14 ^ (33 * v11) )
    {
      v14 = *((unsigned __int8 *)v12 + i-- + 11);
      if ( (unsigned int)(v14 - 65) <= 0x19 )
        v14 += 32;
    }
    v9 ^= v11;
  }
  if ( (PresentMask & 0x100) != 0 && Scaleform::String::GetLength(&data->Url) )
  {
    v15 = (_QWORD *)(data->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
    for ( j = *v15 & 0x7FFFFFFFFFFFFFFFi64; j; v7 = v17 ^ (33 * v7) )
    {
      v17 = *((unsigned __int8 *)v15 + j-- + 11);
      if ( (unsigned int)(v17 - 65) <= 0x19 )
        v17 += 32;
    }
    return v7 ^ v9;
  }
  return v9;
}

// File Line: 444
// RVA: 0x94BC00
void __fastcall Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(
        Scaleform::Render::Text::ParagraphFormat *this)
{
  Scaleform::Render::Text::Allocator *pAllocator; // rcx
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+30h] [rbp+8h] BYREF

  pAllocator = this->pAllocator;
  if ( pAllocator )
  {
    key = this;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      &pAllocator->ParagraphFormatStorage,
      &key);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
  this->pTabStops = 0i64;
}

// File Line: 451
// RVA: 0x99AB90
Scaleform::Render::Text::ParagraphFormat *__fastcall Scaleform::Render::Text::ParagraphFormat::Merge(
        Scaleform::Render::Text::ParagraphFormat *this,
        Scaleform::Render::Text::ParagraphFormat *result,
        Scaleform::Render::Text::ParagraphFormat *fmt)
{
  unsigned int *pTabStops; // r14
  Scaleform::MemoryHeapVtbl *vfptr; // rax
  unsigned int v7; // ebx
  unsigned __int16 PresentMask; // cx
  signed __int16 v9; // dx
  __int16 v10; // ax
  unsigned int *v11; // rdx
  unsigned __int16 v12; // ax
  Scaleform::Render::Text::ParagraphFormat v14; // [rsp+30h] [rbp-30h] BYREF
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+90h] [rbp+30h] BYREF
  Scaleform::Render::Text::ParagraphFormat *v16; // [rsp+98h] [rbp+38h]

  v16 = result;
  v14.pAllocator = 0i64;
  v14.RefCount = 1;
  v14.pTabStops = 0i64;
  v14.BlockIndent = this->BlockIndent;
  v14.Indent = this->Indent;
  v14.Leading = this->Leading;
  v14.LeftMargin = this->LeftMargin;
  v14.RightMargin = this->RightMargin;
  v14.PresentMask = this->PresentMask;
  pTabStops = this->pTabStops;
  vfptr = Scaleform::Memory::pGlobalHeap->vfptr;
  if ( pTabStops )
  {
    v7 = *pTabStops;
    vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
    v14.pTabStops = 0i64;
    v14.pTabStops = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                      Scaleform::Memory::pGlobalHeap,
                                      4i64 * (v7 + 1),
                                      0i64);
    *v14.pTabStops = v7;
    memmove(v14.pTabStops + 1, pTabStops + 1, 4i64 * v7);
  }
  else
  {
    vfptr->Free(Scaleform::Memory::pGlobalHeap, 0i64);
    v14.pTabStops = 0i64;
  }
  if ( (fmt->PresentMask & 1) != 0 )
  {
    PresentMask = v14.PresentMask ^ (v14.PresentMask ^ (((fmt->PresentMask >> 9) & 3) << 9)) & 0x600 | 1;
    v14.PresentMask = PresentMask;
  }
  else
  {
    PresentMask = v14.PresentMask;
  }
  v9 = fmt->PresentMask;
  if ( (v9 & 0x80u) != 0 )
  {
    if ( v9 >= 0 )
      v10 = PresentMask & 0x7FFF;
    else
      v10 = PresentMask | 0x8000;
    PresentMask = v10 | 0x80;
    v14.PresentMask = v10 | 0x80;
  }
  if ( (v9 & 2) != 0 )
  {
    v14.BlockIndent = fmt->BlockIndent;
    PresentMask |= 2u;
    v14.PresentMask = PresentMask;
  }
  if ( (v9 & 4) != 0 )
  {
    v14.Indent = fmt->Indent;
    PresentMask |= 4u;
    v14.PresentMask = PresentMask;
  }
  if ( (v9 & 8) != 0 )
  {
    v14.Leading = fmt->Leading;
    PresentMask |= 8u;
    v14.PresentMask = PresentMask;
  }
  if ( (v9 & 0x10) != 0 )
  {
    v14.LeftMargin = fmt->LeftMargin;
    PresentMask |= 0x10u;
    v14.PresentMask = PresentMask;
  }
  if ( (v9 & 0x20) != 0 )
  {
    v14.RightMargin = fmt->RightMargin;
    PresentMask |= 0x20u;
    v14.PresentMask = PresentMask;
  }
  if ( (v9 & 0x40) != 0 )
  {
    v11 = fmt->pTabStops;
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
    PresentMask = v12;
  }
  if ( (fmt->PresentMask & 0x100) != 0 )
  {
    PresentMask = PresentMask ^ (PresentMask ^ (((fmt->PresentMask >> 11) & 3) << 11)) & 0x1800 | 0x100;
    v14.PresentMask = PresentMask;
  }
  result->pAllocator = 0i64;
  result->RefCount = 1;
  result->pTabStops = 0i64;
  result->BlockIndent = v14.BlockIndent;
  result->Indent = v14.Indent;
  result->Leading = v14.Leading;
  result->LeftMargin = v14.LeftMargin;
  result->RightMargin = v14.RightMargin;
  result->PresentMask = PresentMask;
  Scaleform::Render::Text::ParagraphFormat::CopyTabStops(result, v14.pTabStops);
  if ( v14.pAllocator )
  {
    key = &v14;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      &v14.pAllocator->ParagraphFormatStorage,
      &key);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v14.pTabStops);
  return result;
}

// File Line: 475
// RVA: 0x996970
Scaleform::Render::Text::ParagraphFormat *__fastcall Scaleform::Render::Text::ParagraphFormat::Intersection(
        Scaleform::Render::Text::ParagraphFormat *this,
        Scaleform::Render::Text::ParagraphFormat *result,
        Scaleform::Render::Text::ParagraphFormat *fmt)
{
  unsigned __int16 PresentMask; // bx
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // r8
  __int16 v9; // r8
  __int16 v10; // ax
  unsigned int *pTabStops; // rsi
  unsigned int *v12; // rcx
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // dx
  unsigned __int16 v15; // cx
  Scaleform::Render::Text::ParagraphFormat v17; // [rsp+30h] [rbp-30h] BYREF
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+90h] [rbp+30h] BYREF
  Scaleform::Render::Text::ParagraphFormat *v19; // [rsp+98h] [rbp+38h]

  v19 = result;
  v17.pAllocator = 0i64;
  v17.RefCount = 1;
  memset(&v17.pTabStops, 0, 20);
  if ( (this->PresentMask & 1) != 0
    && (fmt->PresentMask & 1) != 0
    && ((this->PresentMask ^ fmt->PresentMask) & 0x600) == 0 )
  {
    PresentMask = v17.PresentMask ^ (v17.PresentMask ^ (((fmt->PresentMask >> 9) & 3) << 9)) & 0x600 | 1;
    v17.PresentMask = PresentMask;
  }
  else
  {
    PresentMask = v17.PresentMask;
  }
  v7 = this->PresentMask;
  if ( (v7 & 0x80u) != 0 )
  {
    v8 = fmt->PresentMask;
    if ( (v8 & 0x80u) != 0 )
    {
      v9 = v8 & 0x8000;
      if ( v7 >> 15 == (v9 != 0) )
      {
        if ( v9 )
          v10 = PresentMask | 0x8000;
        else
          v10 = PresentMask & 0x7FFF;
        PresentMask = v10 | 0x80;
        v17.PresentMask = v10 | 0x80;
      }
    }
  }
  if ( (v7 & 2) != 0 && (fmt->PresentMask & 2) != 0 && this->BlockIndent == fmt->BlockIndent )
  {
    v17.BlockIndent = fmt->BlockIndent;
    PresentMask |= 2u;
    v17.PresentMask = PresentMask;
  }
  if ( (v7 & 4) != 0 && (fmt->PresentMask & 4) != 0 && this->Indent == fmt->Indent )
  {
    v17.Indent = fmt->Indent;
    PresentMask |= 4u;
    v17.PresentMask = PresentMask;
  }
  if ( (v7 & 8) != 0 && (fmt->PresentMask & 8) != 0 && this->Leading == fmt->Leading )
  {
    v17.Leading = fmt->Leading;
    PresentMask |= 8u;
    v17.PresentMask = PresentMask;
  }
  if ( (v7 & 0x10) != 0 && (fmt->PresentMask & 0x10) != 0 && this->LeftMargin == fmt->LeftMargin )
  {
    v17.LeftMargin = fmt->LeftMargin;
    PresentMask |= 0x10u;
    v17.PresentMask = PresentMask;
  }
  if ( (v7 & 0x20) != 0 && (fmt->PresentMask & 0x20) != 0 && this->RightMargin == fmt->RightMargin )
  {
    v17.RightMargin = fmt->RightMargin;
    PresentMask |= 0x20u;
    v17.PresentMask = PresentMask;
  }
  if ( (v7 & 0x40) != 0 && (fmt->PresentMask & 0x40) != 0 )
  {
    pTabStops = fmt->pTabStops;
    v12 = this->pTabStops;
    if ( v12 == pTabStops || v12 && pTabStops && *v12 == *pTabStops && !memcmp(v12 + 1, pTabStops + 1, 4i64 * *v12) )
    {
      if ( pTabStops && *pTabStops )
      {
        Scaleform::Render::Text::ParagraphFormat::CopyTabStops(&v17, pTabStops);
        v13 = v17.PresentMask | 0x40;
      }
      else
      {
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v17.pTabStops);
        v17.pTabStops = 0i64;
        v13 = v17.PresentMask & 0xFFBF;
      }
      v17.PresentMask = v13;
      PresentMask = v13;
    }
  }
  v14 = this->PresentMask;
  if ( (v14 & 0x100) != 0 )
  {
    v15 = fmt->PresentMask;
    if ( (v15 & 0x100) != 0 && ((v15 ^ v14) & 0x1800) == 0 )
    {
      PresentMask = PresentMask ^ (PresentMask ^ (((fmt->PresentMask >> 11) & 3) << 11)) & 0x1800 | 0x100;
      v17.PresentMask = PresentMask;
    }
  }
  result->pAllocator = 0i64;
  result->RefCount = 1;
  result->pTabStops = 0i64;
  result->BlockIndent = v17.BlockIndent;
  result->Indent = v17.Indent;
  result->Leading = v17.Leading;
  result->LeftMargin = v17.LeftMargin;
  result->RightMargin = v17.RightMargin;
  result->PresentMask = PresentMask;
  Scaleform::Render::Text::ParagraphFormat::CopyTabStops(result, v17.pTabStops);
  if ( v17.pAllocator )
  {
    key = &v17;
    Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::RemoveAlt<Scaleform::Render::Text::ParagraphFormat *>(
      &v17.pAllocator->ParagraphFormatStorage,
      &key);
  }
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v17.pTabStops);
  return result;
}

// File Line: 499
// RVA: 0x992D20
void __fastcall Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(
        Scaleform::Render::Text::ParagraphFormat *this)
{
  unsigned __int16 PresentMask; // ax
  unsigned int *pTabStops; // rdx

  PresentMask = this->PresentMask;
  pTabStops = this->pTabStops;
  *(_QWORD *)&this->BlockIndent = 0i64;
  this->RightMargin = 0;
  this->PresentMask = PresentMask & 0x7940 | 1;
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pTabStops);
  this->pTabStops = 0i64;
  this->PresentMask &= ~0x40u;
}

// File Line: 546
// RVA: 0x98C630
unsigned int *__fastcall Scaleform::Render::Text::ParagraphFormat::GetTabStops(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int *pnum)
{
  unsigned int *result; // rax

  result = this->pTabStops;
  if ( result )
  {
    if ( pnum )
      *pnum = *result;
    return this->pTabStops + 1;
  }
  return result;
}

// File Line: 558
// RVA: 0x9B40B0
void __fastcall Scaleform::Render::Text::ParagraphFormat::SetTabStopsElement(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int idx,
        unsigned int val)
{
  unsigned int *pTabStops; // r9

  pTabStops = this->pTabStops;
  if ( pTabStops )
  {
    if ( idx < *pTabStops )
      pTabStops[idx + 1] = val;
  }
}

// File Line: 566
// RVA: 0x957FE0
void __fastcall Scaleform::Render::Text::ParagraphFormat::AllocTabStops(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int num)
{
  unsigned int *v4; // rax

  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
  this->pTabStops = 0i64;
  v4 = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                         Scaleform::Memory::pGlobalHeap,
                         4i64 * (num + 1),
                         0i64);
  this->pTabStops = v4;
  *v4 = num;
}

// File Line: 573
// RVA: 0x97E670
void __fastcall Scaleform::Render::Text::ParagraphFormat::FreeTabStops(Scaleform::Render::Text::ParagraphFormat *this)
{
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
  this->pTabStops = 0i64;
}

// File Line: 579
// RVA: 0x9B8970
bool __fastcall Scaleform::Render::Text::ParagraphFormat::TabStopsEqual(
        Scaleform::Render::Text::ParagraphFormat *this,
        unsigned int *psrcTabStops)
{
  unsigned int *pTabStops; // rcx

  pTabStops = this->pTabStops;
  if ( pTabStops == psrcTabStops )
    return 1;
  if ( pTabStops && psrcTabStops && *pTabStops == *psrcTabStops )
    return memcmp(pTabStops + 1, psrcTabStops + 1, 4i64 * *pTabStops) == 0;
  return 0;
}

// File Line: 595
// RVA: 0x965190
void __fastcall Scaleform::Render::Text::ParagraphFormat::CopyTabStops(
        Scaleform::Render::Text::ParagraphFormat *this,
        const unsigned int *psrcTabStops)
{
  __int64 v4; // rsi
  unsigned int *pTabStops; // rdx
  unsigned int *v6; // rax

  if ( psrcTabStops )
  {
    v4 = *psrcTabStops;
    pTabStops = this->pTabStops;
    if ( !pTabStops || *pTabStops != (_DWORD)v4 )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      this->pTabStops = 0i64;
      v6 = (unsigned int *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                             Scaleform::Memory::pGlobalHeap,
                             4i64 * (unsigned int)(v4 + 1),
                             0i64);
      this->pTabStops = v6;
      *v6 = v4;
    }
    memmove(this->pTabStops + 1, psrcTabStops + 1, 4 * v4);
  }
  else
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pTabStops);
    this->pTabStops = 0i64;
  }
}

// File Line: 610
// RVA: 0x94E280
Scaleform::Render::Text::ParagraphFormat *__fastcall Scaleform::Render::Text::ParagraphFormat::operator=(
        Scaleform::Render::Text::ParagraphFormat *this,
        Scaleform::Render::Text::ParagraphFormat *src)
{
  this->BlockIndent = src->BlockIndent;
  this->Indent = src->Indent;
  this->Leading = src->Leading;
  this->LeftMargin = src->LeftMargin;
  this->RightMargin = src->RightMargin;
  this->PresentMask = src->PresentMask;
  Scaleform::Render::Text::ParagraphFormat::CopyTabStops(this, src->pTabStops);
  return this;
}

// File Line: 622
// RVA: 0x95BE30
unsigned __int64 __fastcall Scaleform::Render::Text::ParagraphFormat::HashFunctor::CalcHash(
        Scaleform::Render::Text::ParagraphFormat *data)
{
  unsigned __int16 PresentMask; // r8
  unsigned __int8 v2; // r11
  __int64 v4; // rax
  unsigned int *pTabStops; // r10
  __int64 i; // rdx
  __int64 v7; // rcx

  PresentMask = data->PresentMask;
  v2 = 0;
  v4 = 0i64;
  if ( (PresentMask & 0x40) != 0 )
  {
    pTabStops = data->pTabStops;
    if ( pTabStops )
    {
      v4 = 5381i64;
      for ( i = 4i64 * (*pTabStops + 1); i; v4 = v7 + 65599 * v4 )
        v7 = *((unsigned __int8 *)pTabStops + --i);
    }
  }
  if ( (PresentMask & 2) != 0 )
    v4 = data->BlockIndent ^ (unsigned __int64)v4;
  if ( (PresentMask & 4) != 0 )
    v4 ^= (__int64)data->Indent << 8;
  if ( (PresentMask & 8) != 0 )
    v4 ^= (__int64)data->Leading << 12;
  if ( (PresentMask & 0x10) != 0 )
    v4 ^= (unsigned __int64)data->LeftMargin << 16;
  if ( (PresentMask & 0x20) != 0 )
    v4 ^= (unsigned __int64)data->RightMargin << 18;
  if ( (PresentMask & 0x80u) != 0 && (PresentMask & 0x8000u) != 0 )
    v2 = 1;
  return ((unsigned __int64)PresentMask >> 1) & 0xC00 ^ (v2 | ((unsigned __int64)PresentMask << 9) | ((unsigned __int64)PresentMask >> 8) & 6) ^ v4;
}

// File Line: 644
// RVA: 0x958660
Scaleform::Render::Text::TextFormat *__fastcall Scaleform::Render::Text::Allocator::AllocateTextFormat(
        Scaleform::Render::Text::Allocator *this,
        Scaleform::Render::Text::TextFormat *srcfmt)
{
  signed __int64 v4; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *pTable; // r9
  __int64 v6; // r8
  __int64 v7; // rcx
  unsigned __int64 *v8; // rdx
  unsigned __int64 *v9; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v11; // rcx
  Scaleform::Render::Text::TextFormat *v12; // rax
  Scaleform::Render::Text::TextFormat *v13; // rax
  Scaleform::Render::Text::TextFormat *v14; // rbx
  Scaleform::Render::Text::FontHandle *pObject; // rcx
  Scaleform::HashSetLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,74,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *p_TextFormatStorage; // rdi
  signed __int64 v17; // rax
  unsigned __int64 v18; // rsi
  signed __int64 v19; // rax
  Scaleform::Render::Text::TextFormat *key; // [rsp+48h] [rbp+10h] BYREF

  if ( (srcfmt->PresentMask & 0x200) == 0 )
  {
    if ( this->TextFormatStorage.pTable )
    {
      v4 = Scaleform::Render::Text::TextFormat::HashFunctor::CalcHash(srcfmt);
      pTable = this->TextFormatStorage.pTable;
      v6 = v4 & pTable->SizeMask;
      v7 = v6;
      v8 = &pTable[v6 + 1].EntryCount + v6;
      if ( *v8 != -2i64 && v8[1] == v6 )
      {
        while ( v8[1] != v6 || (Scaleform::Render::Text::TextFormat *)v8[2] != srcfmt )
        {
          v7 = *v8;
          if ( *v8 == -1i64 )
            goto LABEL_12;
          v8 = &pTable[v7 + 1].EntryCount + v7;
        }
        if ( v7 >= 0 )
        {
          v9 = &pTable[v7 + 2].EntryCount + v7;
          if ( v9 )
          {
            ++*(_DWORD *)(*v9 + 8);
            return (Scaleform::Render::Text::TextFormat *)*v9;
          }
        }
      }
    }
LABEL_12:
    v11 = this->TextFormatStorage.pTable;
    if ( v11 )
      v11 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *)v11->EntryCount;
    if ( (unsigned __int64)v11 >= this->TextFormatStorageCap )
      Scaleform::Render::Text::Allocator::FlushTextFormatCache(this, 0);
  }
  v12 = (Scaleform::Render::Text::TextFormat *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                                 this->pHeap,
                                                 80i64);
  key = v12;
  if ( v12 )
  {
    Scaleform::Render::Text::TextFormat::TextFormat(v12, srcfmt, this);
    v14 = v13;
  }
  else
  {
    v14 = 0i64;
  }
  key = v14;
  if ( (this->Flags & 1) != 0 && (v14->PresentMask & 0x800) != 0 )
  {
    pObject = v14->pFontHandle.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount) )
      pObject->vfptr->__vecDelDtor(pObject, 1u);
    v14->pFontHandle.pObject = 0i64;
    v14->PresentMask &= ~0x800u;
  }
  if ( (srcfmt->PresentMask & 0x200) == 0 )
  {
    p_TextFormatStorage = &this->TextFormatStorage;
    v17 = Scaleform::Render::Text::TextFormat::HashFunctor::CalcHash(v14);
    v18 = v17;
    if ( p_TextFormatStorage->pTable
      && (v19 = Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::findIndexCore<Scaleform::Render::Text::TextFormat *>(
                  p_TextFormatStorage,
                  &key,
                  v17 & p_TextFormatStorage->pTable->SizeMask),
          v19 >= 0) )
    {
      *(&p_TextFormatStorage->pTable[2].EntryCount + 3 * v19) = (unsigned __int64)v14;
    }
    else
    {
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::add<Scaleform::Render::Text::TextFormat *>(
        p_TextFormatStorage,
        p_TextFormatStorage,
        &key,
        v18);
    }
  }
  return v14;
}

// File Line: 670
// RVA: 0x9584A0
Scaleform::Render::Text::ParagraphFormat *__fastcall Scaleform::Render::Text::Allocator::AllocateParagraphFormat(
        Scaleform::Render::Text::Allocator *this,
        Scaleform::Render::Text::ParagraphFormat *srcfmt)
{
  Scaleform::HashSetLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,74,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> > *p_ParagraphFormatStorage; // rdi
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *pTable; // rbx
  unsigned __int64 v6; // r8
  __int64 v7; // rcx
  unsigned __int64 *v8; // rdx
  unsigned __int64 *v9; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *v11; // rax
  Scaleform::Render::Text::ParagraphFormat *v12; // rbx
  unsigned __int64 EntryCount; // rcx
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
  Scaleform::Render::Text::ParagraphFormat *key; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::Render::Text::ParagraphFormat *v27; // [rsp+60h] [rbp+18h]

  key = (Scaleform::Render::Text::ParagraphFormat *)this;
  p_ParagraphFormatStorage = &this->ParagraphFormatStorage;
  pTable = this->ParagraphFormatStorage.pTable;
  if ( !pTable )
    goto LABEL_11;
  v6 = Scaleform::Render::Text::ParagraphFormat::HashFunctor::CalcHash(srcfmt) & pTable->SizeMask;
  v7 = v6;
  v8 = &pTable[v6 + 1].EntryCount + v6;
  if ( *v8 == -2i64 || v8[1] != v6 )
    goto LABEL_11;
  while ( v8[1] != v6 || (Scaleform::Render::Text::ParagraphFormat *)v8[2] != srcfmt )
  {
    v7 = *v8;
    if ( *v8 == -1i64 )
      goto LABEL_11;
    v8 = &pTable[v7 + 1].EntryCount + v7;
  }
  if ( v7 >= 0 && (v9 = &pTable[v7 + 2].EntryCount + v7) != 0i64 )
  {
    ++*(_DWORD *)(*v9 + 8);
    return (Scaleform::Render::Text::ParagraphFormat *)*v9;
  }
  else
  {
LABEL_11:
    v11 = pTable;
    v12 = 0i64;
    EntryCount = 0i64;
    if ( v11 )
      EntryCount = v11->EntryCount;
    if ( EntryCount >= this->ParagraphFormatStorageCap )
    {
      if ( p_ParagraphFormatStorage->pTable )
        v14 = p_ParagraphFormatStorage->pTable->EntryCount;
      else
        v14 = 0i64;
      v15 = (5 * v14) >> 2;
      if ( p_ParagraphFormatStorage->pTable )
        v16 = p_ParagraphFormatStorage->pTable->EntryCount;
      else
        v16 = 0i64;
      if ( v15 > v16 )
        Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::setRawCapacity(
          p_ParagraphFormatStorage,
          p_ParagraphFormatStorage,
          v15);
      if ( p_ParagraphFormatStorage->pTable )
        v17 = p_ParagraphFormatStorage->pTable->EntryCount;
      else
        v17 = 0i64;
      v18 = p_ParagraphFormatStorage->pTable;
      if ( v17 < this->ParagraphFormatStorageCap )
      {
        if ( !v18 || v18->EntryCount <= 0x64 )
          this->ParagraphFormatStorageCap = 100;
      }
      else
      {
        if ( v18 )
          v19 = v18->EntryCount;
        else
          LODWORD(v19) = 0;
        this->ParagraphFormatStorageCap = v19 + 10;
      }
    }
    v20 = (Scaleform::Render::Text::ParagraphFormat *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))this->pHeap->vfptr->Alloc)(
                                                        this->pHeap,
                                                        40i64);
    v27 = v20;
    if ( v20 )
    {
      Scaleform::Render::Text::ParagraphFormat::ParagraphFormat(v20, srcfmt, this);
      v12 = v21;
    }
    key = v12;
    v22 = Scaleform::Render::Text::ParagraphFormat::HashFunctor::CalcHash(v12);
    v23 = v22;
    v24.pTable = p_ParagraphFormatStorage->pTable;
    if ( p_ParagraphFormatStorage->pTable
      && (v25 = Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::findIndexCore<Scaleform::Render::Text::ParagraphFormat *>(
                  p_ParagraphFormatStorage,
                  &key,
                  v22 & v24.pTable->SizeMask),
          v25 >= 0) )
    {
      *(&v24.pTable[2].EntryCount + 3 * v25) = (unsigned __int64)v12;
    }
    else
    {
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::add<Scaleform::Render::Text::ParagraphFormat *>(
        p_ParagraphFormatStorage,
        p_ParagraphFormatStorage,
        &key,
        v23);
    }
    return v12;
  }
}

// File Line: 687
// RVA: 0x9C20A0
void __fastcall Scaleform::Render::Text::Allocator::VisitTextFormatCache(
        Scaleform::Render::Text::Allocator *this,
        Scaleform::Render::Text::Allocator::TextFormatVisitor *visitor)
{
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *pTable; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *pHash; // rdi
  Scaleform::HashSetLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,74,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *p_TextFormatStorage; // r8
  unsigned __int64 Index; // rbx
  unsigned __int64 SizeMask; // rcx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v8; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v9; // rcx
  __int64 v10; // rdx
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v11; // rdx
  unsigned __int64 v12; // rcx
  unsigned __int64 *v13; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::Iterator v14; // [rsp+20h] [rbp-18h] BYREF

  pTable = this->TextFormatStorage.pTable;
  pHash = 0i64;
  p_TextFormatStorage = &this->TextFormatStorage;
  Index = 0i64;
  if ( pTable )
  {
    SizeMask = pTable->SizeMask;
    v8 = pTable + 1;
    do
    {
      if ( v8->EntryCount != -2i64 )
        break;
      ++Index;
      v8 = (Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *)((char *)v8 + 24);
    }
    while ( Index <= SizeMask );
    pHash = p_TextFormatStorage;
    v14.pHash = p_TextFormatStorage;
  }
  else
  {
    v14.pHash = 0i64;
  }
  v14.Index = Index;
  while ( pHash )
  {
    v9 = pHash->pTable;
    if ( !pHash->pTable || (signed __int64)Index > (signed __int64)v9->SizeMask )
      break;
    v10 = *(&v9[2].EntryCount + 3 * Index);
    if ( !v10
      || !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::Allocator::TextFormatVisitor *, __int64, Scaleform::HashSetLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,74,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> > *))visitor->vfptr->Visit)(
            visitor,
            v10,
            p_TextFormatStorage) )
    {
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::Iterator::RemoveAlt<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>>(
        &v14,
        (Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *> *)&pHash->pTable[2] + 3 * Index);
      Index = v14.Index;
      pHash = v14.pHash;
    }
    v11 = pHash->pTable;
    v12 = pHash->pTable->SizeMask;
    if ( (__int64)Index <= (__int64)v12 )
    {
      v14.Index = ++Index;
      if ( Index <= v12 )
      {
        v13 = &v11[Index + 1].EntryCount + Index;
        do
        {
          if ( *v13 != -2i64 )
            break;
          ++Index;
          v13 += 3;
          v14.Index = Index;
        }
        while ( Index <= v12 );
      }
    }
  }
}

// File Line: 698
// RVA: 0x97ADC0
bool __fastcall Scaleform::Render::Text::Allocator::FlushTextFormatCache(
        Scaleform::Render::Text::Allocator *this,
        bool noAllocationsAllowed)
{
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *pTable; // rax
  unsigned __int64 EntryCount; // rbp
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // r8
  unsigned __int64 v7; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v8; // rcx
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor> >::TableType *v11; // rax
  unsigned __int64 v12; // rax

  pTable = this->TextFormatStorage.pTable;
  EntryCount = 0i64;
  if ( pTable )
    EntryCount = pTable->EntryCount;
  if ( !noAllocationsAllowed )
  {
    v5 = 0i64;
    if ( pTable )
      v5 = pTable->EntryCount;
    v6 = (5 * v5) >> 2;
    if ( pTable )
      v7 = pTable->EntryCount;
    else
      v7 = 0i64;
    if ( v6 > v7 )
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::Render::Text::TextFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::TextFormat *>,Scaleform::Render::Text::TextFormat::HashFunctor>>::setRawCapacity(
        &this->TextFormatStorage,
        &this->TextFormatStorage,
        v6);
  }
  v8 = this->TextFormatStorage.pTable;
  v9 = 0i64;
  if ( v8 )
    v9 = v8->EntryCount;
  if ( v9 < this->TextFormatStorageCap )
  {
    if ( !v8 || v8->EntryCount <= 0x64 )
      this->TextFormatStorageCap = 100;
  }
  else
  {
    LODWORD(v10) = 0;
    if ( v8 )
      v10 = v8->EntryCount;
    this->TextFormatStorageCap = v10 + 10;
  }
  v11 = this->TextFormatStorage.pTable;
  if ( v11 )
    v12 = v11->EntryCount;
  else
    v12 = 0i64;
  return EntryCount != v12;
}

// File Line: 717
// RVA: 0x97ACF0
bool __fastcall Scaleform::Render::Text::Allocator::FlushParagraphFormatCache(
        Scaleform::Render::Text::Allocator *this,
        bool noAllocationsAllowed)
{
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *pTable; // rax
  unsigned __int64 EntryCount; // rbp
  unsigned __int64 v5; // rcx
  unsigned __int64 v6; // r8
  unsigned __int64 v7; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *v8; // rcx
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // rax
  Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor> >::TableType *v11; // rax
  unsigned __int64 v12; // rax

  pTable = this->ParagraphFormatStorage.pTable;
  EntryCount = 0i64;
  if ( pTable )
    EntryCount = pTable->EntryCount;
  if ( !noAllocationsAllowed )
  {
    v5 = 0i64;
    if ( pTable )
      v5 = pTable->EntryCount;
    v6 = (5 * v5) >> 2;
    if ( pTable )
      v7 = pTable->EntryCount;
    else
      v7 = 0i64;
    if ( v6 > v7 )
      Scaleform::HashSetBase<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::Render::Text::ParagraphFormat::HashFunctor,Scaleform::AllocatorLH<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,74>,Scaleform::HashsetCachedEntry<Scaleform::Render::Text::PtrCompare<Scaleform::Render::Text::ParagraphFormat *>,Scaleform::Render::Text::ParagraphFormat::HashFunctor>>::setRawCapacity(
        &this->ParagraphFormatStorage,
        &this->ParagraphFormatStorage,
        v6);
  }
  v8 = this->ParagraphFormatStorage.pTable;
  v9 = 0i64;
  if ( v8 )
    v9 = v8->EntryCount;
  if ( v9 < this->ParagraphFormatStorageCap )
  {
    if ( !v8 || v8->EntryCount <= 0x64 )
      this->ParagraphFormatStorageCap = 100;
  }
  else
  {
    LODWORD(v10) = 0;
    if ( v8 )
      v10 = v8->EntryCount;
    this->ParagraphFormatStorageCap = v10 + 10;
  }
  v11 = this->ParagraphFormatStorage.pTable;
  if ( v11 )
    v12 = v11->EntryCount;
  else
    v12 = 0i64;
  return EntryCount != v12;
}

