// File Line: 38
// RVA: 0xA13300
void __fastcall Scaleform::Render::GFxGdiSelectObjectGuard::~GFxGdiSelectObjectGuard(
        Scaleform::Render::GFxGdiSelectObjectGuard *this)
{
  SelectObject(this->WinDC, this->WinObj);
}

// File Line: 43
// RVA: 0xA13120
void __fastcall Scaleform::Render::ExternalFontWinAPI::~ExternalFontWinAPI(Scaleform::Render::ExternalFontWinAPI *this)
{
  HFONT__ *HintedFont; // rcx
  HFONT__ *MasterFont; // rcx
  Scaleform::Render::RenderBuffer *pObject; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ExternalFontWinAPI::`vftable;
  HintedFont = this->HintedFont;
  if ( HintedFont )
    DeleteObject(HintedFont);
  MasterFont = this->MasterFont;
  if ( MasterFont )
    DeleteObject(MasterFont);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->Hinting.Typeface.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::HashSet<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF>>::~HashSet<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF>>(&this->KerningPairs.mHash);
  Scaleform::HashSet<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::~HashSet<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>(&this->CodeTable.mHash);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Glyphs.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->NameW.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Name.Data.Data);
  pObject = (Scaleform::Render::RenderBuffer *)this->pFontProvider.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable;
  Scaleform::Render::FontCacheHandleRef::releaseFont(&this->hRef);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 58
// RVA: 0xA13640
__int64 __fastcall Scaleform::Render::EnumFontFamExProc(
        tagENUMLOGFONTEXW *lpelfe,
        tagNEWTEXTMETRICEXW *lpntme,
        unsigned int FontType,
        _BYTE *lParam)
{
  *lParam = 1;
  return 0i64;
}

// File Line: 78
// RVA: 0xA12860
void __fastcall Scaleform::Render::ExternalFontWinAPI::ExternalFontWinAPI(
        Scaleform::Render::ExternalFontWinAPI *this,
        Scaleform::GFx::Resource *pprovider,
        Scaleform::Render::FontSysDataWinAPI *sysData,
        char *name,
        unsigned int fontFlags,
        Scaleform::Lock *fontLock)
{
  Scaleform::ArrayLH<wchar_t,2,Scaleform::ArrayDefaultPolicy> *p_NameW; // r14
  __int64 v11; // rdx
  __int64 v12; // rdx
  __int64 Length; // rbx
  __int64 v14; // rdx
  wchar_t *lfFaceName; // rcx
  signed __int64 v16; // r8
  wchar_t v17; // ax
  __int64 v18; // rcx
  char v19; // al
  __int64 v20; // rcx
  char v21; // al
  int v22; // ecx
  HFONT__ *FontW; // rax
  HDC__ *WinHDC; // rbx
  HGDIOBJ v25; // rsi
  float Scale1024; // xmm2_4
  float v27; // xmm3_4
  float v28; // xmm1_4
  tagTEXTMETRICW tm; // [rsp+90h] [rbp-70h] BYREF
  tagLOGFONTW Logfont; // [rsp+D0h] [rbp-30h] BYREF
  LPARAM lParam; // [rsp+168h] [rbp+68h] BYREF
  Scaleform::Render::Font::NativeHintingType *p_Hinting; // [rsp+170h] [rbp+70h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Font,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable;
  *(_QWORD *)&this->Ascent = 0i64;
  this->Leading = 0.0;
  this->Flags = fontFlags;
  *(_DWORD *)&this->LowerCaseTop = 0;
  this->hRef.pManager.Value = 0i64;
  this->hRef.pFontHandle = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ExternalFontWinAPI::`vftable;
  if ( pprovider )
    Scaleform::Render::RenderBuffer::AddRef(pprovider);
  this->pFontProvider.pObject = (Scaleform::Render::FontProviderWinAPI *)pprovider;
  this->pSysData = sysData;
  this->Name.Data.Data = 0i64;
  this->Name.Data.Size = 0i64;
  this->Name.Data.Policy.Capacity = 0i64;
  p_NameW = &this->NameW;
  this->NameW.Data.Data = 0i64;
  this->NameW.Data.Size = 0i64;
  this->NameW.Data.Policy.Capacity = 0i64;
  this->MasterFont = 0i64;
  this->HintedFont = 0i64;
  this->LastHintedFontSize = 0;
  this->Glyphs.Data.Data = 0i64;
  this->Glyphs.Data.Size = 0i64;
  this->Glyphs.Data.Policy.Capacity = 0i64;
  this->CodeTable.mHash.pTable = 0i64;
  this->KerningPairs.mHash.pTable = 0i64;
  this->Scale1024 = 4.2666669;
  p_Hinting = &this->Hinting;
  Scaleform::String::String(&this->Hinting.Typeface);
  this->pFontLock = fontLock;
  v11 = -1i64;
  do
    ++v11;
  while ( name[v11] );
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&this->Name,
    v11 + 1);
  v12 = -1i64;
  do
    ++v12;
  while ( name[v12] );
  strcpy_s(this->Name.Data.Data, v12 + 1, name);
  Length = Scaleform::UTF8Util::GetLength(name, -1i64);
  Scaleform::ArrayData<wchar_t,Scaleform::AllocatorLH<wchar_t,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &this->NameW.Data,
    Length + 1);
  Scaleform::UTF8Util::DecodeStringSafe(p_NameW->Data.Data, Length + 1, name, -1i64);
  v14 = 32i64;
  lfFaceName = Logfont.lfFaceName;
  v16 = (char *)p_NameW->Data.Data - (char *)Logfont.lfFaceName;
  while ( v14 != -2147483614 )
  {
    v17 = *(wchar_t *)((char *)lfFaceName + v16);
    if ( !v17 )
      break;
    *lfFaceName++ = v17;
    if ( !--v14 )
    {
      --lfFaceName;
      break;
    }
  }
  *lfFaceName = 0;
  Logfont.lfCharSet = 1;
  LOBYTE(lParam) = 0;
  EnumFontFamiliesExW(
    this->pSysData->WinHDC,
    &Logfont,
    (FONTENUMPROCW)Scaleform::Render::EnumFontFamExProc,
    (LPARAM)&lParam,
    0);
  if ( (_BYTE)lParam )
    goto LABEL_21;
  v18 = 0i64;
  while ( 1 )
  {
    v19 = name[v18++];
    if ( v19 != aSans[v18 - 1] )
      break;
    if ( v18 == 6 )
      goto LABEL_21;
  }
  if ( !strcmp(name, "_typewriter") )
  {
LABEL_21:
    v22 = 400;
    if ( (this->Flags & 2) != 0 )
      v22 = 700;
    FontW = CreateFontW(-240, 0, 0, 0, v22, this->Flags & 1, 0, 0, 1u, 0, 0, 4u, 0, p_NameW->Data.Data);
    this->MasterFont = FontW;
    if ( FontW )
    {
      WinHDC = this->pSysData->WinHDC;
      v25 = SelectObject(WinHDC, FontW);
      if ( GetTextMetricsW(this->pSysData->WinHDC, &tm) )
      {
        Scale1024 = this->Scale1024;
        v27 = (float)tm.tmDescent * Scale1024;
        v28 = (float)tm.tmAscent * Scale1024;
        this->Leading = (float)tm.tmExternalLeading * Scale1024;
        this->Ascent = v28;
        this->Descent = v27;
        Scaleform::Render::ExternalFontWinAPI::loadKerningPairs(this);
      }
      SelectObject(WinHDC, v25);
    }
  }
  else
  {
    v20 = 0i64;
    while ( 1 )
    {
      v21 = name[v20++];
      if ( v21 != aSerif[v20 - 1] )
        break;
      if ( v20 == 7 )
        goto LABEL_21;
    }
  }
}

// File Line: 155
// RVA: 0xA152B0
void __fastcall Scaleform::Render::ExternalFontWinAPI::loadKerningPairs(Scaleform::Render::ExternalFontWinAPI *this)
{
  unsigned int v2; // edi
  DWORD KerningPairsW; // eax
  DWORD v4; // ebx
  Scaleform::HashLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>,2,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF> > *p_KerningPairs; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF> >::TableType *pTable; // rax
  __int64 v7; // rcx
  __int64 v8; // rdx
  __int64 v9; // rdx
  __int64 v10; // rcx
  unsigned __int64 v11; // r9
  Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeRef key; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::ArrayData<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> v13; // [rsp+38h] [rbp-20h] BYREF
  Scaleform::ArrayData<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *v14; // [rsp+60h] [rbp+8h] BYREF
  float v15; // [rsp+68h] [rbp+10h] BYREF

  v14 = &v13;
  v2 = 0;
  memset(&v13, 0, sizeof(v13));
  KerningPairsW = GetKerningPairsW(this->pSysData->WinHDC, 0, 0i64);
  v4 = KerningPairsW;
  if ( KerningPairsW )
  {
    Scaleform::ArrayData<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v13,
      KerningPairsW);
    GetKerningPairsW(this->pSysData->WinHDC, v4, v13.Data);
  }
  p_KerningPairs = &this->KerningPairs;
  pTable = this->KerningPairs.mHash.pTable;
  if ( pTable )
  {
    v7 = 0i64;
    v8 = pTable->SizeMask + 1;
    do
    {
      if ( *(unsigned __int64 *)((char *)&p_KerningPairs->mHash.pTable[1].EntryCount + v7) != -2i64 )
        *(unsigned __int64 *)((char *)&p_KerningPairs->mHash.pTable[1].EntryCount + v7) = -2i64;
      v7 += 24i64;
      --v8;
    }
    while ( v8 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, p_KerningPairs->mHash.pTable);
    p_KerningPairs->mHash.pTable = 0i64;
  }
  if ( v13.Size )
  {
    v9 = 0i64;
    key.pFirst = (Scaleform::Render::ExternalFontWinAPI::KerningPairType *)&v14;
    key.pSecond = &v15;
    do
    {
      LODWORD(v14) = *(_DWORD *)&v13.Data[v9].wFirst;
      v15 = (float)v13.Data[v9].iKernAmount * this->Scale1024;
      v10 = 4i64;
      v11 = 5381i64;
      do
      {
        --v10;
        v11 = *((unsigned __int8 *)&v14 + v10) + 65599 * v11;
      }
      while ( v10 );
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeRef>(
        &this->KerningPairs.mHash,
        &this->KerningPairs,
        &key,
        v11);
      v9 = ++v2;
    }
    while ( v2 < v13.Size );
  }
  v14 = &v13;
  if ( v13.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 175
// RVA: 0xA14900
char __fastcall Scaleform::Render::ExternalFontWinAPI::decomposeGlyphOutline(
        Scaleform::Render::ExternalFontWinAPI *this,
        const char *data,
        unsigned int size,
        Scaleform::Render::GlyphShape *shape,
        unsigned int hintedSize)
{
  int v5; // r14d
  const char *v6; // rsi
  char v7; // bl
  bool v8; // zf
  Scaleform::Render::GlyphShape *v9; // r15
  const char *v10; // rdi
  int v11; // r12d
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *pContainer; // rsi
  float Multiplier; // xmm8_4
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v14; // rax
  unsigned int v15; // ebx
  _WORD *v16; // r13
  int v17; // edi
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // r14
  unsigned __int64 v20; // r8
  char *v21; // rax
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // r14
  unsigned __int64 v24; // r8
  char *v25; // rax
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // r14
  unsigned __int64 v28; // r8
  char *v29; // rax
  int v30; // esi
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v31; // rcx
  int v32; // r14d
  unsigned __int64 v33; // rax
  unsigned __int64 v34; // r14
  unsigned __int64 v35; // r8
  char *v36; // rax
  int *v37; // r15
  int v38; // ecx
  int v39; // eax
  float v40; // xmm2_4
  int v41; // edi
  int v42; // ebx
  float v43; // xmm1_4
  int v44; // ebx
  int v45; // eax
  int v46; // edi
  int v47; // edx
  int v48; // r15d
  __int64 *v49; // r12
  __int64 v50; // rcx
  __int64 v51; // rax
  int v52; // r8d
  int v53; // edx
  int v54; // edi
  int ay; // ebx
  int v56; // r8d
  __m128i v57; // xmm1
  int v58; // eax
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v59; // rcx
  int v60; // edx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v61; // rax
  int v62; // r9d
  __int64 v63; // rax
  int v64; // eax
  int v65; // ecx
  __int64 v67; // [rsp+30h] [rbp-A8h]
  int v68; // [rsp+38h] [rbp-A0h]
  __int64 v69; // [rsp+40h] [rbp-98h]
  const char *v70; // [rsp+48h] [rbp-90h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v71; // [rsp+50h] [rbp-88h] BYREF
  float v72; // [rsp+58h] [rbp-80h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v73; // [rsp+60h] [rbp-78h] BYREF
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v74; // [rsp+68h] [rbp-70h] BYREF
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v75; // [rsp+70h] [rbp-68h] BYREF
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v76; // [rsp+78h] [rbp-60h] BYREF
  unsigned __int64 v77; // [rsp+80h] [rbp-58h]
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v78; // [rsp+88h] [rbp-50h] BYREF
  float v79; // [rsp+90h] [rbp-48h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v80; // [rsp+98h] [rbp-40h] BYREF
  float v81; // [rsp+A0h] [rbp-38h]
  int v82; // [rsp+160h] [rbp+88h]
  bool v83; // [rsp+168h] [rbp+90h]
  Scaleform::Render::GlyphShape *vars0; // [rsp+170h] [rbp+98h]
  void *retaddr; // [rsp+178h] [rbp+A0h]

  v5 = (int)retaddr;
  v6 = &data[size];
  v7 = (_DWORD)retaddr != 0;
  v8 = shape->Data.Data.Size == 0;
  v9 = shape;
  v70 = data;
  v77 = (unsigned __int64)v6;
  v83 = (_DWORD)retaddr != 0;
  if ( !v8 && (shape->Data.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&shape->Data,
      &shape->Data,
      0i64);
  v10 = v70;
  v11 = 0;
  v9->Data.Data.Size = 0i64;
  if ( v70 < v6 )
  {
    while ( 1 )
    {
      pContainer = v9->pContainer;
      Multiplier = v9->Multiplier;
      v14 = (Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v10[*(unsigned int *)v10];
      v8 = v7 == 0;
      v15 = *((_DWORD *)v10 + 3);
      v16 = v10 + 16;
      v17 = *((_DWORD *)v10 + 2);
      v73.Data = v14;
      v82 = v17;
      if ( v8 )
      {
        v72 = Multiplier;
        v71.Data = pContainer;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
          &v71,
          1u);
        v33 = pContainer->Data.Size;
        v34 = v33 + 1;
        if ( v33 + 1 >= v33 )
        {
          if ( v34 > pContainer->Data.Policy.Capacity )
          {
            v35 = v34 + (v34 >> 2);
LABEL_30:
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
              pContainer,
              v35);
          }
        }
        else if ( v34 < pContainer->Data.Policy.Capacity >> 1 )
        {
          v35 = v33 + 1;
          goto LABEL_30;
        }
        v36 = pContainer->Data.Data;
        pContainer->Data.Size = v34;
        v36[v34 - 1] = 4;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
          &v71,
          0);
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
          &v71,
          0);
        v30 = (int)(float)((float)((float)((float)((SHIWORD(v82) << 8) + BYTE1(v17)) * 4.0) * 0.0041666669) * Multiplier);
        v68 = v30;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
          &v71,
          v30);
        v31 = &v71;
        v32 = (int)(float)((float)((float)((float)((SHIWORD(v15) << 8) + BYTE1(v15)) * -4.0) * 0.0041666669) * Multiplier);
        goto LABEL_32;
      }
      *(float *)&v76.Data = Multiplier;
      v75.Data = pContainer;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
        &v75,
        1u);
      v18 = pContainer->Data.Size;
      v19 = v18 + 1;
      if ( v18 + 1 >= v18 )
      {
        if ( v19 <= pContainer->Data.Policy.Capacity )
          goto LABEL_12;
        v20 = v19 + (v19 >> 2);
      }
      else
      {
        if ( v19 >= pContainer->Data.Policy.Capacity >> 1 )
          goto LABEL_12;
        v20 = v18 + 1;
      }
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
        pContainer,
        v20);
LABEL_12:
      v21 = pContainer->Data.Data;
      pContainer->Data.Size = v19;
      v21[v19 - 1] = 4;
      v22 = pContainer->Data.Size;
      v23 = v22 + 1;
      if ( v22 + 1 >= v22 )
      {
        if ( v23 <= pContainer->Data.Policy.Capacity )
          goto LABEL_18;
        v24 = v23 + (v23 >> 2);
      }
      else
      {
        if ( v23 >= pContainer->Data.Policy.Capacity >> 1 )
          goto LABEL_18;
        v24 = v22 + 1;
      }
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
        pContainer,
        v24);
LABEL_18:
      v25 = pContainer->Data.Data;
      pContainer->Data.Size = v23;
      v25[v23 - 1] = 0;
      v26 = pContainer->Data.Size;
      v27 = v26 + 1;
      if ( v26 + 1 >= v26 )
      {
        if ( v27 > pContainer->Data.Policy.Capacity )
        {
          v28 = v27 + (v27 >> 2);
          goto LABEL_23;
        }
      }
      else if ( v27 < pContainer->Data.Policy.Capacity >> 1 )
      {
        v28 = v26 + 1;
LABEL_23:
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)pContainer,
          pContainer,
          v28);
      }
      v29 = pContainer->Data.Data;
      pContainer->Data.Size = v27;
      v29[v27 - 1] = 0;
      v30 = (int)(float)((float)((float)((float)((float)(unsigned __int16)v17 * 20.0) * 0.000015258789)
                               + (float)((float)SHIWORD(v82) * 20.0))
                       * Multiplier);
      v68 = v30;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        &v75,
        v30);
      v31 = &v75;
      v32 = (int)COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                (float)((float)((float)((float)(unsigned __int16)v15 * 20.0) * 0.000015258789)
                                      + (float)((float)SHIWORD(v15) * 20.0))
                              * Multiplier) ^ _xmm[0]);
LABEL_32:
      v82 = v32;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        v31,
        v32);
      if ( v16 < (_WORD *)v73.Data )
      {
        do
        {
          if ( *v16 == 1 && v16[1] )
          {
            v37 = (int *)(v16 + 2);
            do
            {
              v38 = v37[1];
              v39 = *v37;
              if ( v83 )
              {
                v40 = vars0->Multiplier;
                v74.Data = vars0->pContainer;
                *(float *)&v75.Data = v40;
                v41 = (int)(float)((float)((float)((float)SHIWORD(v39) * 20.0)
                                         + (float)((float)((float)(unsigned __int16)v39 * 20.0) * 0.000015258789))
                                 * v40)
                    - v30;
                v42 = -(v32
                      + (int)(float)((float)((float)((float)SHIWORD(v38) * 20.0)
                                           + (float)((float)((float)(unsigned __int16)v38 * 20.0) * 0.000015258789))
                                   * v40));
                if ( v32
                   + (int)(float)((float)((float)((float)SHIWORD(v38) * 20.0)
                                        + (float)((float)((float)(unsigned __int16)v38 * 20.0) * 0.000015258789))
                                * v40) )
                {
                  if ( v41 )
                  {
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                      &v74,
                      v41,
                      v42);
                    v30 += v41;
                  }
                  else
                  {
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                      &v74,
                      v42);
                  }
                  v32 += v42;
                }
                else
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                    &v74,
                    v41);
                  v30 += v41;
                  v32 += v42;
                }
              }
              else
              {
                v43 = vars0->Multiplier;
                v76.Data = vars0->pContainer;
                v72 = v43;
                v44 = -v30
                    - (int)(float)((float)((float)((float)(BYTE1(v39) + (SHIWORD(v39) << 8)) * -4.0) * 0.0041666669)
                                 * v43);
                v45 = (int)(float)((float)((float)((float)(BYTE1(v38) + (SHIWORD(v38) << 8)) * 4.0) * 0.0041666669) * v43);
                v46 = -v32 - v45;
                if ( -v32 == v45 )
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                    &v76,
                    v44);
                }
                else if ( v44 )
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                    &v76,
                    v44,
                    v46);
                }
                else
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                    &v76,
                    v46);
                }
                v30 += v44;
                v32 += v46;
              }
              ++v11;
              v37 += 2;
            }
            while ( v11 < (unsigned __int16)v16[1] );
          }
          if ( *v16 == 2 )
          {
            v47 = (unsigned __int16)v16[1];
            v48 = 0;
            if ( v47 - 1 > 0 )
            {
              v49 = (__int64 *)(v16 + 2);
              do
              {
                v50 = *v49;
                v51 = v49[1];
                ++v49;
                v67 = v51;
                v69 = v50;
                if ( v48 >= v47 - 2 )
                {
                  HIWORD(v53) = HIWORD(v51);
                  HIWORD(v52) = WORD1(v51);
                }
                else
                {
                  v52 = ((int)v50 + (int)v51) / 2;
                  LODWORD(v67) = v52;
                  v53 = (HIDWORD(v51) + HIDWORD(v50)) / 2;
                  HIDWORD(v67) = v53;
                }
                if ( v83 )
                {
                  v78 = vars0->pContainer;
                  v79 = vars0->Multiplier;
                  v54 = (int)(float)((float)((float)((float)SHIWORD(v52) * 20.0)
                                           + (float)((float)((float)(unsigned __int16)v67 * 20.0) * 0.000015258789))
                                   * v79)
                      - v30;
                  ay = -v32
                     - (int)(float)((float)((float)((float)SHIWORD(v53) * 20.0)
                                          + (float)((float)((float)WORD2(v67) * 20.0) * 0.000015258789))
                                  * v79);
                  v56 = -v32
                      - (int)(float)((float)((float)((float)((float)WORD2(v50) * 20.0) * 0.000015258789)
                                           + (float)((float)SHIWORD(v50) * 20.0))
                                   * v79);
                  v57 = _mm_cvtsi32_si128(SWORD1(v50));
                  v58 = (unsigned __int16)v50;
                  v59 = (Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v78;
                  v60 = (int)(float)((float)((float)(_mm_cvtepi32_ps(v57).m128_f32[0] * 20.0)
                                           + (float)((float)((float)v58 * 20.0) * 0.000015258789))
                                   * v79)
                      - v30;
                }
                else
                {
                  v61 = vars0->pContainer;
                  v81 = vars0->Multiplier;
                  v80.Data = v61;
                  v62 = BYTE1(v50);
                  v59 = &v80;
                  v54 = -v30
                      - (int)(float)((float)((float)((float)((SWORD1(v67) << 8) + BYTE1(v67)) * -4.0) * 0.0041666669)
                                   * v81);
                  ay = -v32
                     - (int)(float)((float)((float)((float)((SHIWORD(v67) << 8) + HIBYTE(WORD2(v67))) * 4.0)
                                          * 0.0041666669)
                                  * v81);
                  v56 = -v32
                      - (int)(float)((float)((float)((float)((SHIWORD(v69) << 8) + HIBYTE(WORD2(v69))) * 4.0)
                                           * 0.0041666669)
                                   * v81);
                  v60 = -v30
                      - (int)(float)((float)((float)((float)((SWORD1(v69) << 8) + v62) * -4.0) * 0.0041666669) * v81);
                }
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
                  v59,
                  v60,
                  v56,
                  v54,
                  ay);
                v47 = (unsigned __int16)v16[1];
                ++v48;
                v30 += v54;
                v32 += ay;
              }
              while ( v48 < v47 - 1 );
            }
          }
          v11 = 0;
          v16 += 4 * (unsigned __int16)v16[1] + 2;
        }
        while ( v16 < (_WORD *)v73.Data );
        v9 = vars0;
      }
      v63 = *(unsigned int *)v70;
      *(float *)&v74.Data = v9->Multiplier;
      v10 = &v70[v63];
      v73.Data = v9->pContainer;
      v70 += v63;
      if ( v30 != v68 || v32 != v82 )
      {
        v64 = v68 - v30;
        v65 = v82 - v32;
        if ( v82 == v32 )
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
            &v73,
            v64);
        }
        else if ( v64 )
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
            &v73,
            v64,
            v65);
        }
        else
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
            &v73,
            v65);
        }
      }
      Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath(v9);
      v7 = v83;
      if ( (unsigned __int64)v10 >= v77 )
      {
        v5 = (int)retaddr;
        break;
      }
    }
  }
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::GlyphShape *))v9->vfptr[1].__vecDelDtor)(v9) )
    return 0;
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape(v9);
  if ( v7 )
    v11 = 20 * v5;
  v9->HintedSize = v11;
  return 1;
}

// File Line: 280
// RVA: 0xA14850
void __fastcall Scaleform::Render::ExternalFontWinAPI::decomposeGlyphBitmap(
        Scaleform::Render::ExternalFontWinAPI *this,
        const char *data,
        unsigned int w,
        unsigned int h,
        int x,
        int y,
        Scaleform::Render::GlyphRaster *raster)
{
  __int64 v8; // rsi
  char *v10; // r8
  __int64 v11; // r10
  const char *v12; // rdx
  unsigned __int8 v13; // al
  __int64 v14; // r9
  char v15; // cl

  v8 = w;
  raster->OriginX = -x;
  raster->OriginY = y;
  raster->Width = w;
  raster->Height = h;
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,75>,Scaleform::ArrayDefaultPolicy>::Resize(
    &raster->Raster.Data,
    (int)(h * w));
  v10 = raster->Raster.Data.Data;
  if ( (int)h > 0 )
  {
    v11 = h;
    do
    {
      v12 = data;
      v13 = 0x80;
      if ( (int)v8 > 0 )
      {
        v14 = v8;
        do
        {
          v15 = -((v13 & *v12) != 0);
          ++v10;
          v13 >>= 1;
          *(v10 - 1) = v15;
          if ( !v13 )
          {
            ++v12;
            v13 = 0x80;
          }
          --v14;
        }
        while ( v14 );
      }
      data += (int)((((int)v8 + 31) >> 3) & 0xFFFFFFFC);
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 307
// RVA: 0xA13830
__int64 __fastcall Scaleform::Render::ExternalFontWinAPI::GetGlyphIndex(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned __int16 code)
{
  Scaleform::Lock *pFontLock; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *pTable; // r10
  unsigned __int64 SizeMask; // r11
  __int64 v6; // r9
  __int64 EntryCount; // rdx
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v8; // rcx
  __int64 p_SizeMask; // rax
  unsigned int *v10; // rax
  unsigned int v11; // ebx
  HDC__ *WinHDC; // rdi
  HGDIOBJ v13; // r14
  float Scale1024; // xmm3_4
  MAT2 mat2; // [rsp+48h] [rbp-31h] BYREF
  Scaleform::Render::ExternalFontWinAPI::GlyphType val; // [rsp+60h] [rbp-19h] BYREF
  HDC__ *v18; // [rsp+80h] [rbp+7h]
  HGDIOBJ v19; // [rsp+88h] [rbp+Fh]
  _GLYPHMETRICS gm; // [rsp+90h] [rbp+17h] BYREF
  int v21; // [rsp+E0h] [rbp+67h] BYREF
  unsigned __int16 v22; // [rsp+E8h] [rbp+6Fh] BYREF
  Scaleform::Lock *v23; // [rsp+F0h] [rbp+77h]

  v22 = code;
  if ( !this->MasterFont )
    return 0xFFFFFFFFi64;
  pFontLock = this->pFontLock;
  v23 = pFontLock;
  EnterCriticalSection(&pFontLock->cs);
  pTable = this->CodeTable.mHash.pTable;
  if ( !pTable )
    goto LABEL_13;
  SizeMask = pTable->SizeMask;
  v6 = SizeMask & v22;
  EntryCount = v6;
  v8 = &pTable[v6 + 1];
  if ( v8->EntryCount == -2i64 || (SizeMask & LOWORD(v8->SizeMask)) != v6 )
    goto LABEL_13;
  while ( (SizeMask & LOWORD(v8->SizeMask)) != v6 || LOWORD(v8->SizeMask) != v22 )
  {
    EntryCount = v8->EntryCount;
    if ( v8->EntryCount == -1i64 )
      goto LABEL_13;
    v8 = &pTable[EntryCount + 1];
  }
  if ( EntryCount >= 0
    && (p_SizeMask = (__int64)&pTable[EntryCount + 1].SizeMask) != 0
    && (v10 = (unsigned int *)(p_SizeMask + 4)) != 0i64 )
  {
    v11 = *v10;
  }
  else
  {
LABEL_13:
    WinHDC = this->pSysData->WinHDC;
    v18 = WinHDC;
    v13 = SelectObject(WinHDC, this->MasterFont);
    v19 = v13;
    *(_QWORD *)&mat2.eM11.fract = 0x10000i64;
    mat2.eM21 = 0;
    mat2.eM22 = (_FIXED)0x10000;
    if ( GetGlyphOutlineW(this->pSysData->WinHDC, v22, 0, &gm, 0, 0i64, &mat2) == -1 )
    {
      v11 = -1;
    }
    else
    {
      val.Code = v22;
      Scale1024 = this->Scale1024;
      val.Advance = (float)gm.gmCellIncX * Scale1024;
      val.Bounds.x1 = (float)gm.gmptGlyphOrigin.x * Scale1024;
      LODWORD(val.Bounds.y1) = COERCE_UNSIGNED_INT((float)gm.gmptGlyphOrigin.y * Scale1024) ^ _xmm[0];
      val.Bounds.x2 = (float)((float)(int)gm.gmBlackBoxX * Scale1024) + val.Bounds.x1;
      val.Bounds.y2 = (float)((float)(int)gm.gmBlackBoxY * Scale1024) + val.Bounds.y1;
      Scaleform::ArrayData<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &this->Glyphs.Data,
        &val);
      v21 = this->Glyphs.Data.Size - 1;
      *(_QWORD *)&val.Code = &v22;
      *(_QWORD *)(&val.Advance + 1) = &v21;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::add<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeRef>(
        &this->CodeTable.mHash,
        &this->CodeTable,
        (Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeRef *)&val,
        v22);
      v11 = this->Glyphs.Data.Size - 1;
    }
    SelectObject(WinHDC, v13);
  }
  LeaveCriticalSection(&pFontLock->cs);
  return v11;
}

// File Line: 345
// RVA: 0xA142C0
char __fastcall Scaleform::Render::ExternalFontWinAPI::IsHintedVectorGlyph(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex,
        unsigned int hintedSize)
{
  __int64 v3; // rsi
  Scaleform::Render::Font::NativeHintingRange VectorRange; // eax
  Scaleform::Lock *pFontLock; // rdi
  bool IsCJK; // bl

  v3 = glyphIndex;
  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  VectorRange = this->Hinting.VectorRange;
  if ( VectorRange == DontHint || hintedSize > this->Hinting.MaxVectorHintedSize )
    return 0;
  if ( VectorRange == HintAll )
    return 1;
  pFontLock = this->pFontLock;
  EnterCriticalSection(&pFontLock->cs);
  IsCJK = Scaleform::Render::Font::IsCJK(this, this->Glyphs.Data.Data[v3].Code);
  LeaveCriticalSection(&pFontLock->cs);
  return IsCJK;
}

// File Line: 362
// RVA: 0xA14220
char __fastcall Scaleform::Render::ExternalFontWinAPI::IsHintedRasterGlyph(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex,
        unsigned int hintedSize)
{
  __int64 v3; // rsi
  Scaleform::Render::Font::NativeHintingRange RasterRange; // eax
  Scaleform::Lock *pFontLock; // rdi
  bool IsCJK; // bl

  v3 = glyphIndex;
  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  RasterRange = this->Hinting.RasterRange;
  if ( RasterRange == DontHint || hintedSize > this->Hinting.MaxRasterHintedSize )
    return 0;
  if ( RasterRange == HintAll )
    return 1;
  pFontLock = this->pFontLock;
  EnterCriticalSection(&pFontLock->cs);
  IsCJK = Scaleform::Render::Font::IsCJK(this, this->Glyphs.Data.Data[v3].Code);
  LeaveCriticalSection(&pFontLock->cs);
  return IsCJK;
}

// File Line: 380
// RVA: 0xA13F30
bool __fastcall Scaleform::Render::ExternalFontWinAPI::GetTemporaryGlyphShape(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex,
        unsigned int hintedSize,
        Scaleform::Render::GlyphShape *shape)
{
  __int64 v6; // rdi
  Scaleform::Lock *pFontLock; // r12
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v10; // r14
  HFONT__ *MasterFont; // rdx
  HFONT__ *HintedFont; // rcx
  int cWeight; // edx
  HDC__ *WinHDC; // rbp
  HGDIOBJ v15; // r15
  Scaleform::Render::FontSysDataWinAPI *pSysData; // rdi
  unsigned __int64 v17; // r8
  signed int GlyphOutlineW; // eax
  Scaleform::Render::FontSysDataWinAPI *v19; // rdx
  DWORD v20; // eax
  bool v21; // bl
  MAT2 mat2; // [rsp+80h] [rbp-68h] BYREF
  HDC__ *v23; // [rsp+90h] [rbp-58h]
  HGDIOBJ v24; // [rsp+98h] [rbp-50h]
  _GLYPHMETRICS gm; // [rsp+A0h] [rbp-48h] BYREF

  v6 = glyphIndex;
  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  if ( !this->vfptr[8].__vecDelDtor(this, glyphIndex) )
    hintedSize = 0;
  pFontLock = this->pFontLock;
  EnterCriticalSection(&pFontLock->cs);
  v10 = &this->Glyphs.Data.Data[v6];
  MasterFont = this->MasterFont;
  if ( hintedSize )
  {
    if ( hintedSize != this->LastHintedFontSize )
    {
      HintedFont = this->HintedFont;
      if ( HintedFont )
        DeleteObject(HintedFont);
      cWeight = 400;
      if ( (this->Flags & 2) != 0 )
        cWeight = 700;
      this->HintedFont = CreateFontW(
                           -hintedSize,
                           0,
                           0,
                           0,
                           cWeight,
                           this->Flags & 1,
                           0,
                           0,
                           1u,
                           0,
                           0,
                           4u,
                           0,
                           this->NameW.Data.Data);
      this->LastHintedFontSize = hintedSize;
    }
    MasterFont = this->HintedFont;
  }
  WinHDC = this->pSysData->WinHDC;
  v23 = WinHDC;
  v15 = SelectObject(WinHDC, MasterFont);
  v24 = v15;
  pSysData = this->pSysData;
  if ( !pSysData->GlyphBuffer.Data.Size )
  {
    if ( pSysData->GlyphBuffer.Data.Size <= 0x3F8 )
    {
      if ( pSysData->GlyphBuffer.Data.Policy.Capacity < 0x3F8 )
      {
        v17 = 1270i64;
        goto LABEL_19;
      }
    }
    else if ( (pSysData->GlyphBuffer.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) > 0x7F0 )
    {
      v17 = 1016i64;
LABEL_19:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->pSysData,
        this->pSysData,
        v17);
    }
    pSysData->GlyphBuffer.Data.Size = 1016i64;
  }
  *(_QWORD *)&mat2.eM11.fract = 0x10000i64;
  mat2.eM21 = 0;
  mat2.eM22 = (_FIXED)0x10000;
  GlyphOutlineW = GetGlyphOutlineW(
                    this->pSysData->WinHDC,
                    v10->Code,
                    2u,
                    &gm,
                    this->pSysData->GlyphBuffer.Data.Size,
                    this->pSysData->GlyphBuffer.Data.Data,
                    &mat2);
  v21 = (GlyphOutlineW != -1 && (v19 = this->pSysData, GlyphOutlineW <= SLODWORD(v19->GlyphBuffer.Data.Size))
      || (v20 = GetGlyphOutlineW(this->pSysData->WinHDC, v10->Code, 2u, &gm, 0, 0i64, &mat2), v20 != -1)
      && (Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            (Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->pSysData,
            (int)(v20 + 1016)),
          GlyphOutlineW = GetGlyphOutlineW(
                            this->pSysData->WinHDC,
                            v10->Code,
                            2u,
                            &gm,
                            this->pSysData->GlyphBuffer.Data.Size,
                            this->pSysData->GlyphBuffer.Data.Data,
                            &mat2),
          GlyphOutlineW != -1)
      && (v19 = this->pSysData, GlyphOutlineW <= SLODWORD(v19->GlyphBuffer.Data.Size)))
     && (!GlyphOutlineW
      || Scaleform::Render::ExternalFontWinAPI::decomposeGlyphOutline(
           this,
           v19->GlyphBuffer.Data.Data,
           GlyphOutlineW,
           shape,
           hintedSize));
  SelectObject(WinHDC, v15);
  LeaveCriticalSection(&pFontLock->cs);
  return v21;
}

// File Line: 479
// RVA: 0xA13A80
char __fastcall Scaleform::Render::ExternalFontWinAPI::GetGlyphRaster(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex,
        unsigned int hintedSize,
        Scaleform::Render::GlyphRaster *raster)
{
  __int64 v6; // rdi
  Scaleform::Lock *pFontLock; // r15
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v10; // rsi
  HFONT__ *HintedFont; // rcx
  int cWeight; // edx
  HDC__ *WinHDC; // r14
  HGDIOBJ v14; // r12
  Scaleform::Render::FontSysDataWinAPI *pSysData; // rdi
  unsigned __int64 v16; // r8
  signed int GlyphOutlineW; // eax
  Scaleform::Render::FontSysDataWinAPI *v18; // rdx
  DWORD v19; // eax
  char v20; // bl
  MAT2 mat2; // [rsp+80h] [rbp-68h] BYREF
  HDC__ *v22; // [rsp+90h] [rbp-58h]
  HGDIOBJ v23; // [rsp+98h] [rbp-50h]
  _GLYPHMETRICS gm; // [rsp+A0h] [rbp-48h] BYREF

  v6 = glyphIndex;
  if ( (unsigned __int16)glyphIndex == 0xFFFF || !this->vfptr[9].__vecDelDtor(this, glyphIndex) )
    return 0;
  pFontLock = this->pFontLock;
  EnterCriticalSection(&pFontLock->cs);
  v10 = &this->Glyphs.Data.Data[v6];
  if ( hintedSize != this->LastHintedFontSize )
  {
    HintedFont = this->HintedFont;
    if ( HintedFont )
      DeleteObject(HintedFont);
    cWeight = 400;
    if ( (this->Flags & 2) != 0 )
      cWeight = 700;
    this->HintedFont = CreateFontW(
                         -hintedSize,
                         0,
                         0,
                         0,
                         cWeight,
                         this->Flags & 1,
                         0,
                         0,
                         1u,
                         0,
                         0,
                         4u,
                         0,
                         this->NameW.Data.Data);
    this->LastHintedFontSize = hintedSize;
  }
  WinHDC = this->pSysData->WinHDC;
  v22 = WinHDC;
  v14 = SelectObject(WinHDC, this->HintedFont);
  v23 = v14;
  pSysData = this->pSysData;
  if ( !pSysData->GlyphBuffer.Data.Size )
  {
    if ( pSysData->GlyphBuffer.Data.Size <= 0x3F8 )
    {
      if ( pSysData->GlyphBuffer.Data.Policy.Capacity < 0x3F8 )
      {
        v16 = 1270i64;
        goto LABEL_16;
      }
    }
    else if ( (pSysData->GlyphBuffer.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) > 0x7F0 )
    {
      v16 = 1016i64;
LABEL_16:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->pSysData,
        this->pSysData,
        v16);
    }
    pSysData->GlyphBuffer.Data.Size = 1016i64;
  }
  *(_QWORD *)&mat2.eM11.fract = 0x10000i64;
  mat2.eM21 = 0;
  mat2.eM22 = (_FIXED)0x10000;
  GlyphOutlineW = GetGlyphOutlineW(
                    this->pSysData->WinHDC,
                    v10->Code,
                    1u,
                    &gm,
                    this->pSysData->GlyphBuffer.Data.Size,
                    this->pSysData->GlyphBuffer.Data.Data,
                    &mat2);
  if ( GlyphOutlineW == -1 || (v18 = this->pSysData, GlyphOutlineW > SLODWORD(v18->GlyphBuffer.Data.Size)) )
  {
    v19 = GetGlyphOutlineW(this->pSysData->WinHDC, v10->Code, 1u, &gm, 0, 0i64, &mat2);
    if ( v19 == -1
      || (Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            (Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)this->pSysData,
            (int)(v19 + 1016)),
          GlyphOutlineW = GetGlyphOutlineW(
                            this->pSysData->WinHDC,
                            v10->Code,
                            1u,
                            &gm,
                            this->pSysData->GlyphBuffer.Data.Size,
                            this->pSysData->GlyphBuffer.Data.Data,
                            &mat2),
          GlyphOutlineW == -1)
      || (v18 = this->pSysData, GlyphOutlineW > SLODWORD(v18->GlyphBuffer.Data.Size)) )
    {
      v20 = 0;
      goto LABEL_32;
    }
  }
  if ( !GlyphOutlineW )
  {
    raster->Width = 1;
    raster->Height = 1;
    if ( raster->Raster.Data.Size <= 1 )
    {
      if ( !raster->Raster.Data.Policy.Capacity )
LABEL_29:
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,75>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &raster->Raster.Data,
          &raster->Raster,
          1ui64);
    }
    else if ( (raster->Raster.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) > 2 )
    {
      goto LABEL_29;
    }
    raster->Raster.Data.Size = 1i64;
    *raster->Raster.Data.Data = 0;
    v20 = 1;
    goto LABEL_32;
  }
  Scaleform::Render::ExternalFontWinAPI::decomposeGlyphBitmap(
    this,
    v18->GlyphBuffer.Data.Data,
    gm.gmBlackBoxX,
    gm.gmBlackBoxY,
    gm.gmptGlyphOrigin.x,
    gm.gmptGlyphOrigin.y,
    raster);
  v20 = 1;
LABEL_32:
  SelectObject(WinHDC, v14);
  LeaveCriticalSection(&pFontLock->cs);
  return v20;
}

// File Line: 580
// RVA: 0xA13650
float __fastcall Scaleform::Render::ExternalFontWinAPI::GetAdvance(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex)
{
  __int64 v2; // rsi
  Scaleform::Lock *pFontLock; // rbx
  float Advance; // xmm6_4
  float result; // xmm0_4

  v2 = glyphIndex;
  if ( (_WORD)glyphIndex == 0xFFFF )
  {
    ((void (__fastcall *)(Scaleform::Render::ExternalFontWinAPI *))this->vfptr[21].__vecDelDtor)(this);
  }
  else
  {
    pFontLock = this->pFontLock;
    EnterCriticalSection(&pFontLock->cs);
    Advance = this->Glyphs.Data.Data[v2].Advance;
    LeaveCriticalSection(&pFontLock->cs);
    return Advance;
  }
  return result;
}

// File Line: 590
// RVA: 0xA13E60
float __fastcall Scaleform::Render::ExternalFontWinAPI::GetKerningAdjustment(
        Scaleform::Render::ExternalFontWinAPI *this,
        __int16 lastCode,
        __int16 thisCode)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF> >::TableType *pTable; // r10
  __int64 v6; // rcx
  __int64 v7; // r9
  __int64 v8; // rax
  __int64 v9; // rax
  __int64 v10; // r8
  __int64 v11; // rdx
  __int64 v12; // rcx
  bool v13; // zf
  unsigned __int64 *v14; // rcx
  float *v15; // rcx
  __int64 v17; // [rsp+8h] [rbp+8h]
  __int16 v18; // [rsp+10h] [rbp+10h]
  __int16 v19; // [rsp+12h] [rbp+12h]

  pTable = this->KerningPairs.mHash.pTable;
  v18 = lastCode;
  v19 = thisCode;
  if ( !pTable )
    return 0.0;
  v6 = 5381i64;
  v7 = 4i64;
  do
  {
    v8 = *((unsigned __int8 *)&v17 + v7-- + 7);
    v9 = 65599 * v6 + v8;
    v6 = v9;
  }
  while ( v7 );
  v10 = v9 & pTable->SizeMask;
  v11 = v10;
  v12 = v10 + 2 * (v10 + 1);
  v13 = *(&pTable->EntryCount + v12) == -2i64;
  v14 = &pTable->EntryCount + v12;
  if ( v13 || v14[1] != v10 )
    return 0.0;
  while ( v14[1] != v10 || *((_WORD *)v14 + 8) != lastCode || *((_WORD *)v14 + 9) != thisCode )
  {
    v11 = *v14;
    if ( *v14 == -1i64 )
      return 0.0;
    v14 = &pTable[v11 + 1].EntryCount + v11;
  }
  if ( v11 >= 0 && (v15 = (float *)(&pTable[v11 + 2].EntryCount + v11)) != 0i64 )
    return v15[1];
  else
    return 0.0;
}

// File Line: 604
// RVA: 0xA13DD0
float __fastcall Scaleform::Render::ExternalFontWinAPI::GetGlyphWidth(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex)
{
  __int64 v2; // rsi
  Scaleform::Lock *pFontLock; // rbx
  float v5; // xmm6_4
  float result; // xmm0_4

  v2 = glyphIndex;
  if ( (_WORD)glyphIndex == 0xFFFF )
  {
    ((void (__fastcall *)(Scaleform::Render::ExternalFontWinAPI *))this->vfptr[21].__vecDelDtor)(this);
  }
  else
  {
    pFontLock = this->pFontLock;
    EnterCriticalSection(&pFontLock->cs);
    v5 = this->Glyphs.Data.Data[v2].Bounds.x2 - this->Glyphs.Data.Data[v2].Bounds.x1;
    LeaveCriticalSection(&pFontLock->cs);
    return v5;
  }
  return result;
}

// File Line: 615
// RVA: 0xA137A0
float __fastcall Scaleform::Render::ExternalFontWinAPI::GetGlyphHeight(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex)
{
  __int64 v2; // rsi
  Scaleform::Lock *pFontLock; // rbx
  float v5; // xmm6_4
  float result; // xmm0_4

  v2 = glyphIndex;
  if ( (_WORD)glyphIndex == 0xFFFF )
  {
    ((void (__fastcall *)(Scaleform::Render::ExternalFontWinAPI *))this->vfptr[22].__vecDelDtor)(this);
  }
  else
  {
    pFontLock = this->pFontLock;
    EnterCriticalSection(&pFontLock->cs);
    v5 = this->Glyphs.Data.Data[v2].Bounds.y2 - this->Glyphs.Data.Data[v2].Bounds.y1;
    LeaveCriticalSection(&pFontLock->cs);
    return v5;
  }
  return result;
}

// File Line: 626
// RVA: 0xA136D0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::ExternalFontWinAPI::GetGlyphBounds(
        Scaleform::Render::ExternalFontWinAPI *this,
        unsigned int glyphIndex,
        Scaleform::Render::Rect<float> *prect)
{
  __int64 v4; // rbp
  double v6; // xmm0_8
  float v7; // xmm6_4
  Scaleform::Lock *pFontLock; // rbx
  Scaleform::Render::ExternalFontWinAPI::GlyphType *Data; // rax
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4

  v4 = glyphIndex;
  if ( (_WORD)glyphIndex == 0xFFFF )
  {
    v6 = ((double (__fastcall *)(Scaleform::Render::ExternalFontWinAPI *))this->vfptr[22].__vecDelDtor)(this);
    v7 = *(float *)&v6;
    *(float *)&v6 = ((float (__fastcall *)(Scaleform::Render::ExternalFontWinAPI *))this->vfptr[21].__vecDelDtor)(this);
    *(_QWORD *)&prect->x1 = 0i64;
    prect->x2 = *(float *)&v6;
    prect->y2 = v7;
  }
  else
  {
    pFontLock = this->pFontLock;
    EnterCriticalSection(&pFontLock->cs);
    Data = this->Glyphs.Data.Data;
    y2 = Data[v4].Bounds.y2;
    x2 = Data[v4].Bounds.x2;
    y1 = Data[v4].Bounds.y1;
    prect->x1 = Data[v4].Bounds.x1;
    prect->y1 = y1;
    prect->x2 = x2;
    prect->y2 = y2;
    LeaveCriticalSection(&pFontLock->cs);
  }
  return prect;
}

// File Line: 652
// RVA: 0xA12C20
void __fastcall Scaleform::Render::FontProviderWinAPI::FontProviderWinAPI(
        Scaleform::Render::FontProviderWinAPI *this,
        HDC__ *dc)
{
  Scaleform::Array<Scaleform::Render::Font::NativeHintingType,2,Scaleform::ArrayDefaultPolicy> *p_NativeHinting; // rbx
  __int64 v3; // rbx
  Scaleform::String src; // [rsp+28h] [rbp-30h] BYREF
  __int64 v5; // [rsp+30h] [rbp-28h]
  int v6; // [rsp+38h] [rbp-20h]
  int v7; // [rsp+3Ch] [rbp-1Ch]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::FontProvider,75>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontProvider::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontProviderWinAPI::`vftable;
  this->SysData.GlyphBuffer.Data.Data = 0i64;
  this->SysData.GlyphBuffer.Data.Size = 0i64;
  this->SysData.GlyphBuffer.Data.Policy.Capacity = 0i64;
  this->SysData.WinHDC = dc;
  p_NativeHinting = &this->NativeHinting;
  this->NativeHinting.Data.Data = 0i64;
  this->NativeHinting.Data.Size = 0i64;
  this->NativeHinting.Data.Policy.Capacity = 0i64;
  Scaleform::Lock::Lock(&this->FontLock, 0);
  Scaleform::String::String(&src);
  v5 = 1i64;
  v6 = 24;
  v7 = 24;
  Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &p_NativeHinting->Data,
    p_NativeHinting,
    p_NativeHinting->Data.Size + 1);
  v3 = (__int64)&p_NativeHinting->Data.Data[p_NativeHinting->Data.Size - 1];
  if ( v3 )
  {
    Scaleform::String::String((Scaleform::String *)v3, &src);
    *(_QWORD *)(v3 + 8) = v5;
    *(_DWORD *)(v3 + 16) = v6;
    *(_DWORD *)(v3 + 20) = v7;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 663
// RVA: 0xA13240
void __fastcall Scaleform::Render::FontProviderWinAPI::~FontProviderWinAPI(Scaleform::Render::FontProviderWinAPI *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontProviderWinAPI::`vftable;
  Scaleform::Lock::~Lock(&this->FontLock.cs);
  Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>(&this->NativeHinting.Data);
  if ( this->SysData.GlyphBuffer.Data.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontProvider::`vftable;
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}

// File Line: 668
// RVA: 0xA15230
Scaleform::Render::Font::NativeHintingType *__fastcall Scaleform::Render::FontProviderWinAPI::findNativeHinting(
        Scaleform::Render::FontProviderWinAPI *this,
        const char *name)
{
  unsigned int v2; // ebx
  __int64 v5; // rax

  v2 = 0;
  if ( !this->NativeHinting.Data.Size )
    return 0i64;
  v5 = 0i64;
  while ( Scaleform::String::CompareNoCase(
            (const char *)((this->NativeHinting.Data.Data[v5].Typeface.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
            name) )
  {
    v5 = ++v2;
    if ( v2 >= this->NativeHinting.Data.Size )
      return 0i64;
  }
  return &this->NativeHinting.Data.Data[v2];
}

// File Line: 713
// RVA: 0xA134D0
Scaleform::Render::Font *__fastcall Scaleform::Render::FontProviderWinAPI::CreateFontA(
        Scaleform::Render::FontProviderWinAPI *this,
        char *name,
        __int16 fontFlags)
{
  int v5; // ebx
  Scaleform::Render::ExternalFontWinAPI *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  Scaleform::Render::Font::NativeHintingType *NativeHinting; // rax
  Scaleform::Render::Font::NativeHintingRange VectorRange; // eax
  Scaleform::Render::Font::NativeHintingType *Data; // rcx
  int v13; // [rsp+70h] [rbp+18h] BYREF
  Scaleform::Render::ExternalFontWinAPI *v14; // [rsp+78h] [rbp+20h]

  v5 = fontFlags & 0x303 | 0x30;
  v13 = 75;
  v6 = (Scaleform::Render::ExternalFontWinAPI *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this,
                                                  224i64,
                                                  &v13);
  v14 = v6;
  if ( v6 )
  {
    Scaleform::Render::ExternalFontWinAPI::ExternalFontWinAPI(
      v6,
      (Scaleform::GFx::Resource *)this,
      &this->SysData,
      name,
      v5,
      &this->FontLock);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( !v8 || *(_QWORD *)(v8 + 120) )
  {
    NativeHinting = Scaleform::Render::FontProviderWinAPI::findNativeHinting(this, name);
    if ( NativeHinting )
    {
      *(_DWORD *)(v8 + 208) = NativeHinting->MaxRasterHintedSize;
      *(_DWORD *)(v8 + 212) = NativeHinting->MaxVectorHintedSize;
      *(_DWORD *)(v8 + 200) = NativeHinting->RasterRange;
      VectorRange = NativeHinting->VectorRange;
    }
    else
    {
      Data = this->NativeHinting.Data.Data;
      *(_DWORD *)(v8 + 208) = Data->MaxRasterHintedSize;
      *(_DWORD *)(v8 + 212) = Data->MaxVectorHintedSize;
      *(_DWORD *)(v8 + 200) = Data->RasterRange;
      VectorRange = Data->VectorRange;
    }
    *(_DWORD *)(v8 + 204) = VectorRange;
    return (Scaleform::Render::Font *)v8;
  }
  else
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
    return 0i64;
  }
}

// File Line: 747
// RVA: 0xA143A0
__int64 __fastcall Scaleform::Render::LoadFontNamesProc(
        tagENUMLOGFONTEXW *lpelfe,
        tagNEWTEXTMETRICEXW *__formal,
        unsigned int a3,
        Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *lParam)
{
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::String v7; // [rsp+50h] [rbp+8h] BYREF

  Scaleform::String::String(&v7, lpelfe->elfFullName);
  key.pFirst = &v7;
  key.pSecond = &v7;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
    lParam,
    lParam,
    &key);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v7.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return 1i64;
}

// File Line: 755
// RVA: 0xA14360
void __fastcall Scaleform::Render::FontProviderWinAPI::LoadFontNames(
        Scaleform::Render::FontProviderWinAPI *this,
        Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *fontnames)
{
  HDC__ *WinHDC; // rcx
  tagLOGFONTW Logfont; // [rsp+30h] [rbp-68h] BYREF

  WinHDC = this->SysData.WinHDC;
  Logfont.lfCharSet = 1;
  Logfont.lfFaceName[0] = 0;
  Logfont.lfPitchAndFamily = 0;
  EnumFontFamiliesExW(WinHDC, &Logfont, (FONTENUMPROCW)Scaleform::Render::LoadFontNamesProc, (LPARAM)fontnames, 0);
}

