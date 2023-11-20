// File Line: 38
// RVA: 0xA13300
void __fastcall Scaleform::Render::GFxGdiSelectObjectGuard::~GFxGdiSelectObjectGuard(Scaleform::Render::GFxGdiSelectObjectGuard *this)
{
  SelectObject(this->WinDC, this->WinObj);
}

// File Line: 43
// RVA: 0xA13120
void __fastcall Scaleform::Render::ExternalFontWinAPI::~ExternalFontWinAPI(Scaleform::Render::ExternalFontWinAPI *this)
{
  Scaleform::Render::ExternalFontWinAPI *v1; // rbx
  HFONT__ *v2; // rcx
  HFONT__ *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ExternalFontWinAPI::`vftable';
  v2 = this->HintedFont;
  if ( v2 )
    DeleteObject(v2);
  v3 = v1->MasterFont;
  if ( v3 )
    DeleteObject(v3);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->Hinting.Typeface.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  Scaleform::HashSet<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF>>::~HashSet<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF>>(&v1->KerningPairs.mHash);
  Scaleform::HashSet<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::~HashSet<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>(&v1->CodeTable.mHash);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Glyphs.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->NameW.Data.Data);
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v1->Name.Data.Data);
  v4 = (Scaleform::Render::RenderBuffer *)v1->pFontProvider.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable';
  Scaleform::Render::FontCacheHandleRef::releaseFont(&v1->hRef);
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 58
// RVA: 0xA13640
__int64 __fastcall Scaleform::Render::EnumFontFamExProc(tagENUMLOGFONTEXW *lpelfe, tagNEWTEXTMETRICEXW *lpntme, unsigned int FontType, __int64 lParam)
{
  *(_BYTE *)lParam = 1;
  return 0i64;
}

// File Line: 78
// RVA: 0xA12860
void __fastcall Scaleform::Render::ExternalFontWinAPI::ExternalFontWinAPI(Scaleform::Render::ExternalFontWinAPI *this, Scaleform::Render::FontProviderWinAPI *pprovider, Scaleform::Render::FontSysDataWinAPI *sysData, const char *name, unsigned int fontFlags, Scaleform::Lock *fontLock)
{
  const char *v6; // rsi
  Scaleform::Render::FontSysDataWinAPI *v7; // r14
  Scaleform::Render::FontProviderWinAPI *v8; // rbx
  Scaleform::Render::ExternalFontWinAPI *v9; // rdi
  Scaleform::Render::FontCacheHandleManager *volatile v10; // rt1
  Scaleform::Render::FontCacheHandleManager *volatile v11; // rax
  signed __int64 v12; // rbx
  signed __int64 v13; // r14
  Scaleform::ArrayLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2,Scaleform::ArrayDefaultPolicy> *v14; // rax
  signed __int64 v15; // rdx
  signed __int64 v16; // rdx
  __int64 v17; // rbx
  signed __int64 v18; // rdx
  wchar_t *v19; // rcx
  __int64 v20; // r8
  wchar_t v21; // ax
  __int64 v22; // rcx
  char v23; // al
  __int64 v24; // rcx
  char v25; // al
  int v26; // ecx
  HFONT v27; // rax
  HDC v28; // rbx
  HGDIOBJ v29; // rsi
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm1_4
  tagTEXTMETRICW tm; // [rsp+90h] [rbp-70h]
  tagLOGFONTW Logfont; // [rsp+D0h] [rbp-30h]
  LPARAM lParam; // [rsp+168h] [rbp+68h]
  Scaleform::Render::Font::NativeHintingType *v36; // [rsp+170h] [rbp+70h]

  v6 = name;
  v7 = sysData;
  v8 = pprovider;
  v9 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::Font,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::Font::`vftable';
  *(_QWORD *)&this->Ascent = 0i64;
  this->Leading = 0.0;
  this->Flags = fontFlags;
  *(_DWORD *)&this->LowerCaseTop = 0;
  v10 = this->hRef.pManager.Value;
  this->hRef.pManager.Value = 0i64;
  v11 = this->hRef.pManager.Value;
  this->hRef.pFontHandle = 0i64;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::ExternalFontWinAPI::`vftable';
  if ( pprovider )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pprovider);
  v9->pFontProvider.pObject = v8;
  v9->pSysData = v7;
  v12 = (signed __int64)&v9->Name;
  *(_QWORD *)v12 = 0i64;
  *(_QWORD *)(v12 + 8) = 0i64;
  *(_QWORD *)(v12 + 16) = 0i64;
  v13 = (signed __int64)&v9->NameW;
  *(_QWORD *)v13 = 0i64;
  *(_QWORD *)(v13 + 8) = 0i64;
  *(_QWORD *)(v13 + 16) = 0i64;
  v9->MasterFont = 0i64;
  v9->HintedFont = 0i64;
  v9->LastHintedFontSize = 0;
  v14 = &v9->Glyphs;
  v14->Data.Data = 0i64;
  v14->Data.Size = 0i64;
  v14->Data.Policy.Capacity = 0i64;
  v9->CodeTable.mHash.pTable = 0i64;
  v9->KerningPairs.mHash.pTable = 0i64;
  v9->Scale1024 = 4.2666669;
  v36 = &v9->Hinting;
  Scaleform::String::String(&v9->Hinting.Typeface);
  v9->pFontLock = fontLock;
  v15 = -1i64;
  do
    ++v15;
  while ( v6[v15] );
  Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    (Scaleform::ArrayData<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&v9->Name,
    v15 + 1);
  v16 = -1i64;
  do
    ++v16;
  while ( v6[v16] );
  strcpy_s(*(char **)v12, v16 + 1, v6);
  v17 = Scaleform::UTF8Util::GetLength(v6, -1i64);
  Scaleform::ArrayData<wchar_t,Scaleform::AllocatorLH<wchar_t,2>,Scaleform::ArrayDefaultPolicy>::Resize(
    &v9->NameW.Data,
    v17 + 1);
  Scaleform::UTF8Util::DecodeStringSafe(*(wchar_t **)v13, v17 + 1, v6, -1i64);
  v18 = 32i64;
  v19 = Logfont.lfFaceName;
  v20 = *(_QWORD *)v13 - ((_QWORD)&Logfont + 28);
  while ( v18 != -2147483614 )
  {
    v21 = *(wchar_t *)((char *)v19 + v20);
    if ( !v21 )
      break;
    *v19 = v21;
    ++v19;
    if ( !--v18 )
      goto LABEL_13;
  }
  if ( v18 )
    goto LABEL_14;
LABEL_13:
  --v19;
LABEL_14:
  *v19 = 0;
  Logfont.lfCharSet = 1;
  LOBYTE(lParam) = 0;
  EnumFontFamiliesExW(
    v9->pSysData->WinHDC,
    &Logfont,
    (FONTENUMPROCW)Scaleform::Render::EnumFontFamExProc,
    (LPARAM)&lParam,
    0);
  if ( (_BYTE)lParam )
    goto LABEL_23;
  v22 = 0i64;
  while ( 1 )
  {
    v23 = v6[v22++];
    if ( v23 != aSans[v22 - 1] )
      break;
    if ( v22 == 6 )
      goto LABEL_23;
  }
  if ( !strcmp(v6, "_typewriter") )
  {
LABEL_23:
    v26 = 400;
    if ( (v9->Flags >> 1) & 1 )
      v26 = 700;
    v27 = CreateFontW(-240, 0, 0, 0, v26, v9->Flags & 1, 0, 0, 1u, 0, 0, 4u, 0, *(LPCWSTR *)v13);
    v9->MasterFont = v27;
    if ( v27 )
    {
      v28 = v9->pSysData->WinHDC;
      v29 = SelectObject(v9->pSysData->WinHDC, v27);
      if ( GetTextMetricsW(v9->pSysData->WinHDC, &tm) )
      {
        v30 = v9->Scale1024;
        v31 = (float)tm.tmDescent * v30;
        v32 = (float)tm.tmAscent * v30;
        v9->Leading = (float)tm.tmExternalLeading * v30;
        v9->Ascent = v32;
        v9->Descent = v31;
        Scaleform::Render::ExternalFontWinAPI::loadKerningPairs(v9);
      }
      SelectObject(v28, v29);
    }
  }
  else
  {
    v24 = 0i64;
    while ( 1 )
    {
      v25 = v6[v24++];
      if ( v25 != aSerif[v24 - 1] )
        break;
      if ( v24 == 7 )
        goto LABEL_23;
    }
  }
}

// File Line: 155
// RVA: 0xA152B0
void __fastcall Scaleform::Render::ExternalFontWinAPI::loadKerningPairs(Scaleform::Render::ExternalFontWinAPI *this)
{
  Scaleform::Render::ExternalFontWinAPI *v1; // rsi
  unsigned int v2; // edi
  DWORD v3; // eax
  __int64 v4; // r8
  DWORD v5; // ebx
  void **v6; // rbx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF> >::TableType *v7; // rax
  __int64 v8; // rcx
  signed __int64 v9; // rdx
  __int64 v10; // rdx
  signed __int64 v11; // rcx
  unsigned __int64 v12; // r9
  Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeRef key; // [rsp+28h] [rbp-30h]
  Scaleform::ArrayData<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> v14; // [rsp+38h] [rbp-20h]
  Scaleform::ArrayData<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *v15; // [rsp+60h] [rbp+8h]
  float v16; // [rsp+68h] [rbp+10h]

  v1 = this;
  v15 = &v14;
  v2 = 0;
  v14.Data = 0i64;
  v14.Size = 0i64;
  v14.Policy.Capacity = 0i64;
  v3 = GetKerningPairsW(this->pSysData->WinHDC, 0, 0i64);
  v5 = v3;
  if ( v3 )
  {
    Scaleform::ArrayData<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v14,
      v3);
    GetKerningPairsW(v1->pSysData->WinHDC, v5, v14.Data);
  }
  v6 = (void **)&v1->KerningPairs.mHash.pTable;
  v7 = v1->KerningPairs.mHash.pTable;
  if ( v7 )
  {
    v8 = 0i64;
    v9 = v7->SizeMask + 1;
    do
    {
      if ( *(_QWORD *)((char *)*v6 + v8 + 16) != -2i64 )
        *(_QWORD *)((char *)*v6 + v8 + 16) = -2i64;
      v8 += 24i64;
      --v9;
    }
    while ( v9 );
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v6);
    *v6 = 0i64;
  }
  if ( v14.Size )
  {
    v10 = 0i64;
    key.pFirst = (Scaleform::Render::ExternalFontWinAPI::KerningPairType *)&v15;
    key.pSecond = &v16;
    do
    {
      LODWORD(v15) = *(_DWORD *)&v14.Data[v10].wFirst;
      v16 = (float)v14.Data[v10].iKernAmount * v1->Scale1024;
      v11 = 4i64;
      v12 = 5381i64;
      do
        v12 = *((unsigned __int8 *)&v15 + --v11) + 65599 * v12;
      while ( v11 );
      Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF> > *)&v1->KerningPairs.mHash.pTable,
        &v1->KerningPairs,
        &key,
        v12);
      v10 = ++v2;
    }
    while ( v2 < v14.Size );
  }
  v15 = &v14;
  if ( v14.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, tagKERNINGPAIR *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v14.Data,
      v4);
}

// File Line: 175
// RVA: 0xA14900
char __fastcall Scaleform::Render::ExternalFontWinAPI::decomposeGlyphOutline(Scaleform::Render::ExternalFontWinAPI *this, const char *data, unsigned int size, Scaleform::Render::GlyphShape *shape, unsigned int hintedSize)
{
  int v5; // er14
  const char *v6; // rsi
  char v7; // bl
  bool v8; // zf
  Scaleform::Render::GlyphShape *v9; // r15
  const char *v10; // rdi
  int v11; // er12
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v12; // rsi
  float v13; // xmm8_4
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
  float v30; // xmm1_4
  signed int v31; // esi
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v32; // rcx
  int v33; // er14
  unsigned __int64 v34; // rax
  unsigned __int64 v35; // r14
  unsigned __int64 v36; // r8
  char *v37; // rax
  float v38; // xmm0_4
  int *v39; // r15
  int v40; // ecx
  int v41; // eax
  float v42; // xmm2_4
  int v43; // edi
  int v44; // ebx
  float v45; // xmm1_4
  int v46; // ebx
  signed int v47; // eax
  int v48; // edi
  int v49; // edx
  int v50; // er15
  __int64 *v51; // r12
  __int64 v52; // rcx
  __int64 v53; // rax
  int v54; // er8
  int v55; // edx
  int v56; // edi
  int ay; // ebx
  int v58; // er8
  __m128i v59; // xmm1
  signed int v60; // eax
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *v61; // rcx
  int v62; // edx
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v63; // rax
  unsigned int v64; // er9
  __int64 v65; // rax
  int v66; // eax
  int v67; // ecx
  __int64 v69; // [rsp+30h] [rbp-A8h]
  signed int v70; // [rsp+38h] [rbp-A0h]
  __int64 v71; // [rsp+40h] [rbp-98h]
  const char *v72; // [rsp+48h] [rbp-90h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v73; // [rsp+50h] [rbp-88h]
  float v74; // [rsp+58h] [rbp-80h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v75; // [rsp+60h] [rbp-78h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v76; // [rsp+68h] [rbp-70h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v77; // [rsp+70h] [rbp-68h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v78; // [rsp+78h] [rbp-60h]
  const char *v79; // [rsp+80h] [rbp-58h]
  Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v80; // [rsp+88h] [rbp-50h]
  float v81; // [rsp+90h] [rbp-48h]
  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > v82; // [rsp+98h] [rbp-40h]
  float v83; // [rsp+A0h] [rbp-38h]
  int v84; // [rsp+160h] [rbp+88h]
  bool v85; // [rsp+168h] [rbp+90h]
  Scaleform::Render::GlyphShape *vars0; // [rsp+170h] [rbp+98h]
  void *retaddr; // [rsp+178h] [rbp+A0h]

  v5 = (signed int)retaddr;
  v6 = &data[size];
  v7 = (_DWORD)retaddr != 0;
  v8 = shape->Data.Data.Size == 0;
  v9 = shape;
  v72 = data;
  v79 = &data[size];
  v85 = (_DWORD)retaddr != 0;
  if ( !v8 && shape->Data.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)&shape->Data,
      &shape->Data,
      0i64);
  v10 = v72;
  v11 = 0;
  v9->Data.Data.Size = 0i64;
  if ( v72 < v6 )
  {
    while ( 1 )
    {
      v12 = v9->pContainer;
      v13 = v9->Multiplier;
      v14 = (Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v10[*(unsigned int *)v10];
      v8 = v7 == 0;
      v15 = *((_DWORD *)v10 + 3);
      v16 = v10 + 16;
      v17 = *((_DWORD *)v10 + 2);
      v75.Data = v14;
      v84 = v17;
      if ( v8 )
      {
        v74 = v13;
        v73.Data = v12;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
          &v73,
          1u);
        v34 = v12->Data.Size;
        v35 = v34 + 1;
        if ( v34 + 1 >= v34 )
        {
          if ( v35 > v12->Data.Policy.Capacity )
          {
            v36 = v35 + (v35 >> 2);
LABEL_30:
            Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v12,
              v12,
              v36);
          }
        }
        else if ( v35 < v12->Data.Policy.Capacity >> 1 )
        {
          v36 = v34 + 1;
          goto LABEL_30;
        }
        v37 = v12->Data.Data;
        v12->Data.Size = v35;
        v37[v35 - 1] = 4;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
          &v73,
          0);
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt30(
          &v73,
          0);
        v38 = (float)((float)((float)(signed int)((SHIWORD(v84) << 8) + ((unsigned int)(unsigned __int16)v17 >> 8)) * 4.0)
                    * 0.0041666669)
            * v13;
        v31 = (signed int)v38;
        v70 = (signed int)v38;
        Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
          &v73,
          (signed int)v38);
        v32 = &v73;
        v33 = (signed int)(float)((float)((float)((float)(signed int)((SHIWORD(v15) << 8)
                                                                    + ((unsigned int)(unsigned __int16)v15 >> 8))
                                                * -4.0)
                                        * 0.0041666669)
                                * v13);
        goto LABEL_32;
      }
      *(float *)&v78.Data = v13;
      v77.Data = v12;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteUInt15(
        &v77,
        1u);
      v18 = v12->Data.Size;
      v19 = v18 + 1;
      if ( v18 + 1 >= v18 )
      {
        if ( v19 <= v12->Data.Policy.Capacity )
          goto LABEL_12;
        v20 = v19 + (v19 >> 2);
      }
      else
      {
        if ( v19 >= v12->Data.Policy.Capacity >> 1 )
          goto LABEL_12;
        v20 = v18 + 1;
      }
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v12,
        v12,
        v20);
LABEL_12:
      v21 = v12->Data.Data;
      v12->Data.Size = v19;
      v21[v19 - 1] = 4;
      v22 = v12->Data.Size;
      v23 = v22 + 1;
      if ( v22 + 1 >= v22 )
      {
        if ( v23 <= v12->Data.Policy.Capacity )
          goto LABEL_18;
        v24 = v23 + (v23 >> 2);
      }
      else
      {
        if ( v23 >= v12->Data.Policy.Capacity >> 1 )
          goto LABEL_18;
        v24 = v22 + 1;
      }
      Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v12,
        v12,
        v24);
LABEL_18:
      v25 = v12->Data.Data;
      v12->Data.Size = v23;
      v25[v23 - 1] = 0;
      v26 = v12->Data.Size;
      v27 = v26 + 1;
      if ( v26 + 1 >= v26 )
      {
        if ( v27 > v12->Data.Policy.Capacity )
        {
          v28 = v27 + (v27 >> 2);
          goto LABEL_23;
        }
      }
      else if ( v27 < v12->Data.Policy.Capacity >> 1 )
      {
        v28 = v26 + 1;
LABEL_23:
        Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<bool,Scaleform::AllocatorLH<bool,2>,Scaleform::ArrayDefaultPolicy> *)v12,
          v12,
          v28);
        goto LABEL_24;
      }
LABEL_24:
      v29 = v12->Data.Data;
      v12->Data.Size = v27;
      v29[v27 - 1] = 0;
      v30 = (float)((float)((float)((float)(unsigned __int16)v17 * 20.0) * 0.000015258789)
                  + (float)((float)SHIWORD(v84) * 20.0))
          * v13;
      v31 = (signed int)v30;
      v70 = (signed int)v30;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        &v77,
        (signed int)v30);
      v32 = &v77;
      v33 = (signed int)COERCE_FLOAT(COERCE_UNSIGNED_INT(
                                       (float)((float)((float)((float)(unsigned __int16)v15 * 20.0) * 0.000015258789)
                                             + (float)((float)SHIWORD(v15) * 20.0))
                                     * v13) ^ _xmm[0]);
LABEL_32:
      v84 = v33;
      Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteSInt30(
        v32,
        v33);
      if ( v16 < (_WORD *)v75.Data )
      {
        do
        {
          if ( *v16 == 1 && v16[1] > 0u )
          {
            v39 = (int *)(v16 + 2);
            do
            {
              v40 = v39[1];
              v41 = *v39;
              if ( v85 )
              {
                v42 = vars0->Multiplier;
                v76.Data = vars0->pContainer;
                *(float *)&v77.Data = v42;
                v43 = (signed int)(float)((float)((float)((float)SHIWORD(v41) * 20.0)
                                                + (float)((float)((float)(unsigned __int16)v41 * 20.0) * 0.000015258789))
                                        * v42)
                    - v31;
                v44 = -(v33
                      + (signed int)(float)((float)((float)((float)SHIWORD(v40) * 20.0)
                                                  + (float)((float)((float)(unsigned __int16)v40 * 20.0) * 0.000015258789))
                                          * v42));
                if ( v33
                   + (signed int)(float)((float)((float)((float)SHIWORD(v40) * 20.0)
                                               + (float)((float)((float)(unsigned __int16)v40 * 20.0) * 0.000015258789))
                                       * v42) )
                {
                  if ( (signed int)(float)((float)((float)((float)SHIWORD(v41) * 20.0)
                                                 + (float)((float)((float)(unsigned __int16)v41 * 20.0) * 0.000015258789))
                                         * v42) == v31 )
                  {
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                      &v76,
                      v44);
                  }
                  else
                  {
                    Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                      &v76,
                      v43,
                      v44);
                    v31 += v43;
                  }
                  v33 += v44;
                }
                else
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                    &v76,
                    v43);
                  v31 += v43;
                  v33 += v44;
                }
              }
              else
              {
                v45 = vars0->Multiplier;
                v78.Data = vars0->pContainer;
                v74 = v45;
                v46 = -v31
                    - (signed int)(float)((float)((float)((float)(signed int)(((unsigned int)(unsigned __int16)v41 >> 8)
                                                                            + (SHIWORD(v41) << 8))
                                                        * -4.0)
                                                * 0.0041666669)
                                        * v45);
                v47 = (signed int)(float)((float)((float)((float)(signed int)(((unsigned int)(unsigned __int16)v40 >> 8)
                                                                            + (SHIWORD(v40) << 8))
                                                        * 4.0)
                                                * 0.0041666669)
                                        * v45);
                v48 = -v33 - v47;
                if ( -v33 == v47 )
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
                    &v78,
                    v46);
                }
                else if ( v46 )
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
                    &v78,
                    v46,
                    v48);
                }
                else
                {
                  Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
                    &v78,
                    v48);
                }
                v31 += v46;
                v33 += v48;
              }
              ++v11;
              v39 += 2;
            }
            while ( v11 < (unsigned __int16)v16[1] );
          }
          if ( *v16 == 2 )
          {
            v49 = (unsigned __int16)v16[1];
            v50 = 0;
            if ( v49 - 1 > 0 )
            {
              v51 = (__int64 *)(v16 + 2);
              do
              {
                v52 = *v51;
                v53 = v51[1];
                ++v51;
                v69 = v53;
                v71 = v52;
                if ( v50 >= v49 - 2 )
                {
                  HIWORD(v55) = HIWORD(v53);
                  HIWORD(v54) = WORD1(v53);
                }
                else
                {
                  v54 = ((signed int)v52 + (signed int)v53) / 2;
                  LODWORD(v69) = ((signed int)v52 + (signed int)v53) / 2;
                  v55 = (HIDWORD(v53) + HIDWORD(v52)) / 2;
                  HIDWORD(v69) = (HIDWORD(v53) + HIDWORD(v52)) / 2;
                }
                if ( v85 )
                {
                  v80 = vars0->pContainer;
                  v81 = vars0->Multiplier;
                  v56 = (signed int)(float)((float)((float)((float)SHIWORD(v54) * 20.0)
                                                  + (float)((float)((float)(unsigned __int16)v69 * 20.0) * 0.000015258789))
                                          * v81)
                      - v31;
                  ay = -v33
                     - (signed int)(float)((float)((float)((float)SHIWORD(v55) * 20.0)
                                                 + (float)((float)((float)WORD2(v69) * 20.0) * 0.000015258789))
                                         * v81);
                  v58 = -v33
                      - (signed int)(float)((float)((float)((float)((float)WORD2(v52) * 20.0) * 0.000015258789)
                                                  + (float)((float)SHIWORD(v52) * 20.0))
                                          * v81);
                  v59 = _mm_cvtsi32_si128(SWORD1(v52));
                  v60 = (unsigned __int16)v52;
                  v61 = (Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v80;
                  v62 = (signed int)(float)((float)((float)(COERCE_FLOAT(_mm_cvtepi32_ps(v59)) * 20.0)
                                                  + (float)((float)((float)v60 * 20.0) * 0.000015258789))
                                          * v81)
                      - v31;
                }
                else
                {
                  v63 = vars0->pContainer;
                  v83 = vars0->Multiplier;
                  v82.Data = v63;
                  v64 = (unsigned int)(unsigned __int16)v52 >> 8;
                  v61 = &v82;
                  v56 = -v31
                      - (signed int)(float)((float)((float)((float)(signed int)((SWORD1(v69) << 8)
                                                                              + ((unsigned int)(unsigned __int16)v69 >> 8))
                                                          * -4.0)
                                                  * 0.0041666669)
                                          * v83);
                  ay = -v33
                     - (signed int)(float)((float)((float)((float)(signed int)((SHIWORD(v69) << 8)
                                                                             + ((unsigned int)WORD2(v69) >> 8))
                                                         * 4.0)
                                                 * 0.0041666669)
                                         * v83);
                  v58 = -v33
                      - (signed int)(float)((float)((float)((float)(signed int)((SHIWORD(v71) << 8)
                                                                              + ((unsigned int)WORD2(v71) >> 8))
                                                          * 4.0)
                                                  * 0.0041666669)
                                          * v83);
                  v62 = -v31
                      - (signed int)(float)((float)((float)((float)(signed int)((SWORD1(v71) << 8) + v64) * -4.0)
                                                  * 0.0041666669)
                                          * v83);
                }
                Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteQuad(
                  v61,
                  v62,
                  v58,
                  v56,
                  ay);
                v49 = (unsigned __int16)v16[1];
                ++v50;
                v31 += v56;
                v33 += ay;
              }
              while ( v50 < v49 - 1 );
            }
          }
          v11 = 0;
          v16 += 4 * (unsigned __int16)v16[1] + 2;
        }
        while ( v16 < (_WORD *)v75.Data );
        v9 = vars0;
      }
      v65 = *(unsigned int *)v72;
      *(float *)&v76.Data = v9->Multiplier;
      v10 = &v72[v65];
      v75.Data = v9->pContainer;
      v72 += v65;
      if ( v31 != v70 || v33 != v84 )
      {
        v66 = v70 - v31;
        v67 = v84 - v33;
        if ( v84 == v33 )
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteHLine(
            &v75,
            v66);
        }
        else if ( v70 == v31 )
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteVLine(
            &v75,
            v67);
        }
        else
        {
          Scaleform::Render::PathDataEncoder<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::WriteLine(
            &v75,
            v66,
            v67);
        }
      }
      Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndPath((Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v9->vfptr);
      v7 = v85;
      if ( v10 >= v79 )
      {
        v5 = (signed int)retaddr;
        break;
      }
    }
  }
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::Render::GlyphShape *))v9->vfptr[1].__vecDelDtor)(v9) )
    return 0;
  Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::EndShape((Scaleform::Render::ShapeDataPacked<Scaleform::ArrayLH_POD<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *)&v9->vfptr);
  if ( v7 )
    v11 = 20 * v5;
  v9->HintedSize = v11;
  return 1;
}

// File Line: 280
// RVA: 0xA14850
void __fastcall Scaleform::Render::ExternalFontWinAPI::decomposeGlyphBitmap(Scaleform::Render::ExternalFontWinAPI *this, const char *data, int w, int h, int x, int y, Scaleform::Render::GlyphRaster *raster)
{
  int v7; // ebp
  __int64 v8; // rsi
  const char *v9; // rdi
  char *v10; // r8
  __int64 v11; // r10
  const char *v12; // rdx
  unsigned __int8 v13; // al
  __int64 v14; // r9
  char v15; // cl

  v7 = h;
  v8 = (unsigned int)w;
  raster->OriginX = -x;
  v9 = data;
  raster->OriginY = y;
  raster->Width = w;
  raster->Height = h;
  Scaleform::ArrayData<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,75>,Scaleform::ArrayDefaultPolicy>::Resize(
    &raster->Raster.Data,
    h * w);
  v10 = raster->Raster.Data.Data;
  if ( v7 > 0 )
  {
    v11 = (unsigned int)v7;
    do
    {
      v12 = v9;
      v13 = -128;
      if ( (signed int)v8 > 0 )
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
            v13 = -128;
          }
          --v14;
        }
        while ( v14 );
      }
      v9 += (signed int)((((signed int)v8 + 31) >> 3) & 0xFFFFFFFC);
      --v11;
    }
    while ( v11 );
  }
}

// File Line: 307
// RVA: 0xA13830
signed __int64 __fastcall Scaleform::Render::ExternalFontWinAPI::GetGlyphIndex(Scaleform::Render::ExternalFontWinAPI *this, unsigned __int16 code)
{
  Scaleform::Render::ExternalFontWinAPI *v2; // rbx
  Scaleform::Lock *v3; // rsi
  Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF> >::TableType *v4; // r10
  unsigned __int64 v5; // r11
  unsigned __int64 v6; // r9
  __int64 v7; // rdx
  signed __int64 v8; // rcx
  signed __int64 v9; // rax
  unsigned int *v10; // rax
  unsigned int v11; // ebx
  HDC v12; // rdi
  HGDIOBJ v13; // r14
  float v14; // xmm3_4
  MAT2 mat2; // [rsp+48h] [rbp-31h]
  Scaleform::Render::ExternalFontWinAPI::GlyphType val; // [rsp+60h] [rbp-19h]
  HDC v18; // [rsp+80h] [rbp+7h]
  HGDIOBJ v19; // [rsp+88h] [rbp+Fh]
  _GLYPHMETRICS gm; // [rsp+90h] [rbp+17h]
  int v21; // [rsp+E0h] [rbp+67h]
  unsigned __int16 v22; // [rsp+E8h] [rbp+6Fh]
  Scaleform::Lock *v23; // [rsp+F0h] [rbp+77h]

  v22 = code;
  v2 = this;
  if ( !this->MasterFont )
    return 0xFFFFFFFFi64;
  v3 = this->pFontLock;
  v23 = v3;
  EnterCriticalSection(&v3->cs);
  v4 = v2->CodeTable.mHash.pTable;
  if ( !v4 )
    goto LABEL_13;
  v5 = v4->SizeMask;
  v6 = v5 & v22;
  v7 = v6;
  v8 = (signed __int64)&v4[v6 + 1];
  if ( *(_QWORD *)v8 == -2i64 || (v5 & *(_WORD *)(v8 + 8)) != v6 )
    goto LABEL_13;
  while ( (v5 & *(_WORD *)(v8 + 8)) != v6 || *(_WORD *)(v8 + 8) != v22 )
  {
    v7 = *(_QWORD *)v8;
    if ( *(_QWORD *)v8 == -1i64 )
      goto LABEL_13;
    v8 = (signed __int64)&v4[v7 + 1];
  }
  if ( v7 >= 0 && (v9 = (signed __int64)&v4[v7 + 1].SizeMask) != 0 && (v10 = (unsigned int *)(v9 + 4)) != 0i64 )
  {
    v11 = *v10;
  }
  else
  {
LABEL_13:
    v12 = v2->pSysData->WinHDC;
    v18 = v12;
    v13 = SelectObject(v12, v2->MasterFont);
    v19 = v13;
    *(_QWORD *)&mat2.eM11.fract = 0x10000i64;
    mat2.eM21 = 0;
    mat2.eM22 = (_FIXED)0x10000;
    if ( GetGlyphOutlineW(v2->pSysData->WinHDC, v22, 0, &gm, 0, 0i64, &mat2) == -1 )
    {
      v11 = -1;
    }
    else
    {
      val.Code = v22;
      v14 = v2->Scale1024;
      val.Advance = (float)gm.gmCellIncX * v14;
      val.Bounds.x1 = (float)gm.gmptGlyphOrigin.x * v14;
      LODWORD(val.Bounds.y1) = COERCE_UNSIGNED_INT((float)gm.gmptGlyphOrigin.y * v14) ^ _xmm[0];
      val.Bounds.x2 = (float)((float)(signed int)gm.gmBlackBoxX * v14) + val.Bounds.x1;
      val.Bounds.y2 = (float)((float)(signed int)gm.gmBlackBoxY * v14) + val.Bounds.y1;
      Scaleform::ArrayData<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy>::PushBack(
        &v2->Glyphs.Data,
        &val);
      v21 = v2->Glyphs.Data.Size - 1;
      *(_QWORD *)&val.Code = &v22;
      *(_QWORD *)(&val.Advance + 1) = &v21;
      Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::add<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeRef>(
        (Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF> > *)&v2->CodeTable.mHash.pTable,
        &v2->CodeTable,
        (Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeRef *)&val,
        v22);
      v11 = v2->Glyphs.Data.Size - 1;
    }
    SelectObject(v12, v13);
  }
  LeaveCriticalSection(&v3->cs);
  return v11;
}

// File Line: 345
// RVA: 0xA142C0
char __fastcall Scaleform::Render::ExternalFontWinAPI::IsHintedVectorGlyph(Scaleform::Render::ExternalFontWinAPI *this, unsigned int glyphIndex, unsigned int hintedSize)
{
  __int64 v3; // rsi
  Scaleform::Render::ExternalFontWinAPI *v4; // rbx
  Scaleform::Render::Font::NativeHintingRange v5; // eax
  Scaleform::Lock *v7; // rdi
  bool v8; // bl

  v3 = glyphIndex;
  v4 = this;
  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  v5 = this->Hinting.VectorRange;
  if ( v5 == DontHint || hintedSize > this->Hinting.MaxVectorHintedSize )
    return 0;
  if ( v5 == 2 )
    return 1;
  v7 = this->pFontLock;
  EnterCriticalSection(&this->pFontLock->cs);
  v8 = Scaleform::Render::Font::IsCJK((Scaleform::Render::Font *)&v4->vfptr, v4->Glyphs.Data.Data[v3].Code);
  LeaveCriticalSection(&v7->cs);
  return v8;
}

// File Line: 362
// RVA: 0xA14220
char __fastcall Scaleform::Render::ExternalFontWinAPI::IsHintedRasterGlyph(Scaleform::Render::ExternalFontWinAPI *this, unsigned int glyphIndex, unsigned int hintedSize)
{
  __int64 v3; // rsi
  Scaleform::Render::ExternalFontWinAPI *v4; // rbx
  Scaleform::Render::Font::NativeHintingRange v5; // eax
  Scaleform::Lock *v7; // rdi
  bool v8; // bl

  v3 = glyphIndex;
  v4 = this;
  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  v5 = this->Hinting.RasterRange;
  if ( v5 == DontHint || hintedSize > this->Hinting.MaxRasterHintedSize )
    return 0;
  if ( v5 == 2 )
    return 1;
  v7 = this->pFontLock;
  EnterCriticalSection(&this->pFontLock->cs);
  v8 = Scaleform::Render::Font::IsCJK((Scaleform::Render::Font *)&v4->vfptr, v4->Glyphs.Data.Data[v3].Code);
  LeaveCriticalSection(&v7->cs);
  return v8;
}

// File Line: 380
// RVA: 0xA13F30
bool __fastcall Scaleform::Render::ExternalFontWinAPI::GetTemporaryGlyphShape(Scaleform::Render::ExternalFontWinAPI *this, unsigned int glyphIndex, unsigned int hintedSize, Scaleform::Render::GlyphShape *shape)
{
  Scaleform::Render::GlyphShape *v4; // r13
  unsigned int v5; // esi
  __int64 v6; // rdi
  Scaleform::Render::ExternalFontWinAPI *v7; // rbx
  _RTL_CRITICAL_SECTION *v9; // r12
  UINT *v10; // r14
  HFONT__ *v11; // rdx
  HFONT__ *v12; // rcx
  int cWeight; // edx
  HDC v14; // rbp
  HGDIOBJ v15; // r15
  Scaleform::Render::FontSysDataWinAPI *v16; // rdi
  unsigned __int64 v17; // r8
  signed int v18; // eax
  Scaleform::Render::FontSysDataWinAPI *v19; // rdx
  DWORD v20; // eax
  bool v21; // bl
  MAT2 mat2; // [rsp+80h] [rbp-68h]
  HDC v23; // [rsp+90h] [rbp-58h]
  HGDIOBJ v24; // [rsp+98h] [rbp-50h]
  _GLYPHMETRICS gm; // [rsp+A0h] [rbp-48h]

  v4 = shape;
  v5 = hintedSize;
  v6 = glyphIndex;
  v7 = this;
  if ( (unsigned __int16)glyphIndex == 0xFFFF )
    return 0;
  if ( !(unsigned __int8)this->vfptr[8].__vecDelDtor((Scaleform::RefCountImplCore *)this, glyphIndex) )
    v5 = 0;
  v9 = &v7->pFontLock->cs;
  EnterCriticalSection(&v7->pFontLock->cs);
  v10 = &v7->Glyphs.Data.Data[v6].Code;
  v11 = v7->MasterFont;
  if ( v5 )
  {
    if ( v5 != v7->LastHintedFontSize )
    {
      v12 = v7->HintedFont;
      if ( v12 )
        DeleteObject(v12);
      cWeight = 400;
      if ( (v7->Flags >> 1) & 1 )
        cWeight = 700;
      v7->HintedFont = CreateFontW(-v5, 0, 0, 0, cWeight, v7->Flags & 1, 0, 0, 1u, 0, 0, 4u, 0, v7->NameW.Data.Data);
      v7->LastHintedFontSize = v5;
    }
    v11 = v7->HintedFont;
  }
  v14 = v7->pSysData->WinHDC;
  v23 = v14;
  v15 = SelectObject(v14, v11);
  v24 = v15;
  v16 = v7->pSysData;
  if ( !v16->GlyphBuffer.Data.Size )
  {
    if ( v16->GlyphBuffer.Data.Size <= 0x3F8 )
    {
      if ( v16->GlyphBuffer.Data.Policy.Capacity < 0x3F8 )
      {
        v17 = 1270i64;
        goto LABEL_19;
      }
    }
    else if ( (v16->GlyphBuffer.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) > 0x7F0 )
    {
      v17 = 1016i64;
LABEL_19:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)v7->pSysData,
        v7->pSysData,
        v17);
      goto LABEL_20;
    }
LABEL_20:
    v16->GlyphBuffer.Data.Size = 1016i64;
  }
  *(_QWORD *)&mat2.eM11.fract = 0x10000i64;
  mat2.eM21 = 0;
  mat2.eM22 = (_FIXED)0x10000;
  v18 = GetGlyphOutlineW(
          v7->pSysData->WinHDC,
          *v10,
          2u,
          &gm,
          v7->pSysData->GlyphBuffer.Data.Size,
          v7->pSysData->GlyphBuffer.Data.Data,
          &mat2);
  v21 = (v18 != -1 && (v19 = v7->pSysData, v18 <= SLODWORD(v19->GlyphBuffer.Data.Size))
      || (v20 = GetGlyphOutlineW(v7->pSysData->WinHDC, *v10, 2u, &gm, 0, 0i64, &mat2), v20 != -1)
      && (Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            (Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)v7->pSysData,
            (signed int)(v20 + 1016)),
          v18 = GetGlyphOutlineW(
                  v7->pSysData->WinHDC,
                  *v10,
                  2u,
                  &gm,
                  v7->pSysData->GlyphBuffer.Data.Size,
                  v7->pSysData->GlyphBuffer.Data.Data,
                  &mat2),
          v18 != -1)
      && (v19 = v7->pSysData, v18 <= SLODWORD(v19->GlyphBuffer.Data.Size)))
     && (!v18
      || Scaleform::Render::ExternalFontWinAPI::decomposeGlyphOutline(v7, v19->GlyphBuffer.Data.Data, v18, v4, v5));
  SelectObject(v14, v15);
  LeaveCriticalSection(v9);
  return v21;
}

// File Line: 479
// RVA: 0xA13A80
char __fastcall Scaleform::Render::ExternalFontWinAPI::GetGlyphRaster(Scaleform::Render::ExternalFontWinAPI *this, unsigned int glyphIndex, unsigned int hintedSize, Scaleform::Render::GlyphRaster *raster)
{
  Scaleform::Render::GlyphRaster *v4; // rbp
  unsigned int v5; // er14
  __int64 v6; // rdi
  Scaleform::Render::ExternalFontWinAPI *v7; // rbx
  _RTL_CRITICAL_SECTION *v9; // r15
  UINT *v10; // rsi
  HFONT__ *v11; // rcx
  int cWeight; // edx
  HDC v13; // r14
  HGDIOBJ v14; // r12
  Scaleform::Render::FontSysDataWinAPI *v15; // rdi
  unsigned __int64 v16; // r8
  signed int v17; // eax
  Scaleform::Render::FontSysDataWinAPI *v18; // rdx
  DWORD v19; // eax
  char v20; // bl
  MAT2 mat2; // [rsp+80h] [rbp-68h]
  HDC v22; // [rsp+90h] [rbp-58h]
  HGDIOBJ v23; // [rsp+98h] [rbp-50h]
  _GLYPHMETRICS gm; // [rsp+A0h] [rbp-48h]

  v4 = raster;
  v5 = hintedSize;
  v6 = glyphIndex;
  v7 = this;
  if ( (unsigned __int16)glyphIndex == 0xFFFF
    || !(unsigned __int8)this->vfptr[9].__vecDelDtor((Scaleform::RefCountImplCore *)this, glyphIndex) )
  {
    return 0;
  }
  v9 = &v7->pFontLock->cs;
  EnterCriticalSection(&v7->pFontLock->cs);
  v10 = &v7->Glyphs.Data.Data[v6].Code;
  if ( v5 != v7->LastHintedFontSize )
  {
    v11 = v7->HintedFont;
    if ( v11 )
      DeleteObject(v11);
    cWeight = 400;
    if ( (v7->Flags >> 1) & 1 )
      cWeight = 700;
    v7->HintedFont = CreateFontW(-v5, 0, 0, 0, cWeight, v7->Flags & 1, 0, 0, 1u, 0, 0, 4u, 0, v7->NameW.Data.Data);
    v7->LastHintedFontSize = v5;
  }
  v13 = v7->pSysData->WinHDC;
  v22 = v13;
  v14 = SelectObject(v13, v7->HintedFont);
  v23 = v14;
  v15 = v7->pSysData;
  if ( !v15->GlyphBuffer.Data.Size )
  {
    if ( v15->GlyphBuffer.Data.Size <= 0x3F8 )
    {
      if ( v15->GlyphBuffer.Data.Policy.Capacity < 0x3F8 )
      {
        v16 = 1270i64;
        goto LABEL_16;
      }
    }
    else if ( (v15->GlyphBuffer.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) > 0x7F0 )
    {
      v16 = 1016i64;
LABEL_16:
      Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)v7->pSysData,
        v7->pSysData,
        v16);
      goto LABEL_17;
    }
LABEL_17:
    v15->GlyphBuffer.Data.Size = 1016i64;
  }
  *(_QWORD *)&mat2.eM11.fract = 0x10000i64;
  mat2.eM21 = 0;
  mat2.eM22 = (_FIXED)0x10000;
  v17 = GetGlyphOutlineW(
          v7->pSysData->WinHDC,
          *v10,
          1u,
          &gm,
          v7->pSysData->GlyphBuffer.Data.Size,
          v7->pSysData->GlyphBuffer.Data.Data,
          &mat2);
  if ( v17 == -1 || (v18 = v7->pSysData, v17 > SLODWORD(v18->GlyphBuffer.Data.Size)) )
  {
    v19 = GetGlyphOutlineW(v7->pSysData->WinHDC, *v10, 1u, &gm, 0, 0i64, &mat2);
    if ( v19 == -1
      || (Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Resize(
            (Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *)v7->pSysData,
            (signed int)(v19 + 1016)),
          v17 = GetGlyphOutlineW(
                  v7->pSysData->WinHDC,
                  *v10,
                  1u,
                  &gm,
                  v7->pSysData->GlyphBuffer.Data.Size,
                  v7->pSysData->GlyphBuffer.Data.Data,
                  &mat2),
          v17 == -1)
      || (v18 = v7->pSysData, v17 > SLODWORD(v18->GlyphBuffer.Data.Size)) )
    {
      v20 = 0;
      goto LABEL_32;
    }
  }
  if ( !v17 )
  {
    v4->Width = 1;
    v4->Height = 1;
    if ( v4->Raster.Data.Size <= 1 )
    {
      if ( v4->Raster.Data.Policy.Capacity < 1 )
      {
LABEL_29:
        Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,75>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,75>,Scaleform::ArrayDefaultPolicy> *)&v4->Raster.Data.Data,
          &v4->Raster,
          1ui64);
        goto LABEL_30;
      }
    }
    else if ( (v4->Raster.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) > 2 )
    {
      goto LABEL_29;
    }
LABEL_30:
    v4->Raster.Data.Size = 1i64;
    *v4->Raster.Data.Data = 0;
    v20 = 1;
    goto LABEL_32;
  }
  Scaleform::Render::ExternalFontWinAPI::decomposeGlyphBitmap(
    v7,
    v18->GlyphBuffer.Data.Data,
    gm.gmBlackBoxX,
    gm.gmBlackBoxY,
    gm.gmptGlyphOrigin.x,
    gm.gmptGlyphOrigin.y,
    v4);
  v20 = 1;
LABEL_32:
  SelectObject(v13, v14);
  LeaveCriticalSection(v9);
  return v20;
}

// File Line: 580
// RVA: 0xA13650
float __fastcall Scaleform::Render::ExternalFontWinAPI::GetAdvance(Scaleform::Render::ExternalFontWinAPI *this, unsigned int glyphIndex)
{
  __int64 v2; // rsi
  Scaleform::Render::ExternalFontWinAPI *v3; // rdi
  Scaleform::Lock *v4; // rbx
  float v5; // xmm6_4
  float result; // xmm0_4

  v2 = glyphIndex;
  v3 = this;
  if ( (_WORD)glyphIndex == -1 )
  {
    ((void (__cdecl *)(Scaleform::Render::ExternalFontWinAPI *))this->vfptr[21].__vecDelDtor)(this);
  }
  else
  {
    v4 = this->pFontLock;
    EnterCriticalSection(&this->pFontLock->cs);
    v5 = v3->Glyphs.Data.Data[v2].Advance;
    LeaveCriticalSection(&v4->cs);
    result = v5;
  }
  return result;
}

// File Line: 590
// RVA: 0xA13E60
float __fastcall Scaleform::Render::ExternalFontWinAPI::GetKerningAdjustment(Scaleform::Render::ExternalFontWinAPI *this, unsigned int lastCode, unsigned int thisCode)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::KerningPairType,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >,Scaleform::HashNode<Scaleform::Render::ExternalFontWinAPI::KerningPairType,float,Scaleform::FixedSizeHash<Scaleform::Render::ExternalFontWinAPI::KerningPairType> >::NodeHashF> >::TableType *v3; // r10
  __int16 v4; // r11
  __int16 v5; // bx
  signed __int64 v6; // rcx
  signed __int64 v7; // r9
  __int64 v8; // rax
  signed __int64 v9; // rax
  unsigned __int64 v10; // r8
  signed __int64 v11; // rdx
  signed __int64 v12; // rcx
  bool v13; // zf
  signed __int64 v14; // rcx
  signed __int64 v15; // rcx
  float result; // xmm0_4
  __int64 v17; // [rsp+8h] [rbp+8h]
  __int16 v18; // [rsp+10h] [rbp+10h]
  __int16 v19; // [rsp+12h] [rbp+12h]

  v3 = this->KerningPairs.mHash.pTable;
  v4 = thisCode;
  v5 = lastCode;
  v18 = lastCode;
  v19 = thisCode;
  if ( !v3 )
    goto LABEL_14;
  v6 = 5381i64;
  v7 = 4i64;
  do
  {
    v8 = *((unsigned __int8 *)&v17 + v7-- + 7);
    v9 = 65599 * v6 + v8;
    v6 = v9;
  }
  while ( v7 );
  v10 = v9 & v3->SizeMask;
  v11 = v10;
  v12 = v10 + 2 * (v10 + 1);
  v13 = *(&v3->EntryCount + v12) == -2i64;
  v14 = (signed __int64)v3 + 8 * v12;
  if ( v13 || *(_QWORD *)(v14 + 8) != v10 )
    goto LABEL_14;
  while ( *(_QWORD *)(v14 + 8) != v10 || *(_WORD *)(v14 + 16) != v5 || *(_WORD *)(v14 + 18) != v4 )
  {
    v11 = *(_QWORD *)v14;
    if ( *(_QWORD *)v14 == -1i64 )
      goto LABEL_14;
    v14 = (signed __int64)v3 + 8 * (v11 + 2 * (v11 + 1));
  }
  if ( v11 >= 0 && (v15 = (signed __int64)v3 + 8 * (v11 + 2 * (v11 + 2))) != 0 )
    result = *(float *)(v15 + 4);
  else
LABEL_14:
    result = 0.0;
  return result;
}

// File Line: 604
// RVA: 0xA13DD0
float __fastcall Scaleform::Render::ExternalFontWinAPI::GetGlyphWidth(Scaleform::Render::ExternalFontWinAPI *this, unsigned int glyphIndex)
{
  __int64 v2; // rsi
  Scaleform::Render::ExternalFontWinAPI *v3; // rdi
  Scaleform::Lock *v4; // rbx
  float v5; // xmm6_4
  float result; // xmm0_4

  v2 = glyphIndex;
  v3 = this;
  if ( (_WORD)glyphIndex == -1 )
  {
    ((void (__cdecl *)(Scaleform::Render::ExternalFontWinAPI *))this->vfptr[21].__vecDelDtor)(this);
  }
  else
  {
    v4 = this->pFontLock;
    EnterCriticalSection(&this->pFontLock->cs);
    v5 = v3->Glyphs.Data.Data[v2].Bounds.x2 - v3->Glyphs.Data.Data[v2].Bounds.x1;
    LeaveCriticalSection(&v4->cs);
    result = v5;
  }
  return result;
}

// File Line: 615
// RVA: 0xA137A0
float __fastcall Scaleform::Render::ExternalFontWinAPI::GetGlyphHeight(Scaleform::Render::ExternalFontWinAPI *this, unsigned int glyphIndex)
{
  __int64 v2; // rsi
  Scaleform::Render::ExternalFontWinAPI *v3; // rdi
  Scaleform::Lock *v4; // rbx
  float v5; // xmm6_4
  float result; // xmm0_4

  v2 = glyphIndex;
  v3 = this;
  if ( (_WORD)glyphIndex == -1 )
  {
    ((void (__cdecl *)(Scaleform::Render::ExternalFontWinAPI *))this->vfptr[22].__vecDelDtor)(this);
  }
  else
  {
    v4 = this->pFontLock;
    EnterCriticalSection(&this->pFontLock->cs);
    v5 = v3->Glyphs.Data.Data[v2].Bounds.y2 - v3->Glyphs.Data.Data[v2].Bounds.y1;
    LeaveCriticalSection(&v4->cs);
    result = v5;
  }
  return result;
}

// File Line: 626
// RVA: 0xA136D0
Scaleform::Render::Rect<float> *__usercall Scaleform::Render::ExternalFontWinAPI::GetGlyphBounds@<rax>(Scaleform::Render::ExternalFontWinAPI *this@<rcx>, unsigned int glyphIndex@<edx>, Scaleform::Render::Rect<float> *prect@<r8>, float a4@<xmm0>)
{
  Scaleform::Render::Rect<float> *v4; // rdi
  __int64 v5; // rbp
  Scaleform::Render::ExternalFontWinAPI *v6; // rsi
  Scaleform::Lock *v7; // rbx
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v8; // rax
  float v9; // xmm2_4
  float v10; // xmm1_4
  float v11; // xmm0_4

  v4 = prect;
  v5 = glyphIndex;
  v6 = this;
  if ( (_WORD)glyphIndex == -1 )
  {
    ((void (__cdecl *)(Scaleform::Render::ExternalFontWinAPI *))this->vfptr[22].__vecDelDtor)(this);
    ((void (__fastcall *)(Scaleform::Render::ExternalFontWinAPI *))v6->vfptr[21].__vecDelDtor)(v6);
    *(_QWORD *)&v4->x1 = 0i64;
    v4->x2 = a4;
    v4->y2 = a4;
  }
  else
  {
    v7 = this->pFontLock;
    EnterCriticalSection(&this->pFontLock->cs);
    v8 = v6->Glyphs.Data.Data;
    v9 = v8[v5].Bounds.y2;
    v10 = v8[v5].Bounds.x2;
    v11 = v8[v5].Bounds.y1;
    v4->x1 = v8[v5].Bounds.x1;
    v4->y1 = v11;
    v4->x2 = v10;
    v4->y2 = v9;
    LeaveCriticalSection(&v7->cs);
  }
  return v4;
}

// File Line: 652
// RVA: 0xA12C20
void __fastcall Scaleform::Render::FontProviderWinAPI::FontProviderWinAPI(Scaleform::Render::FontProviderWinAPI *this, HDC__ *dc)
{
  Scaleform::Render::FontSysDataWinAPI *v2; // rax
  Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  signed __int64 v4; // rbx
  Scaleform::String src; // [rsp+28h] [rbp-30h]
  __int64 v6; // [rsp+30h] [rbp-28h]
  int v7; // [rsp+38h] [rbp-20h]
  int v8; // [rsp+3Ch] [rbp-1Ch]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::Render::FontProvider,75>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontProvider::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontProviderWinAPI::`vftable';
  v2 = &this->SysData;
  v2->GlyphBuffer.Data.Data = 0i64;
  v2->GlyphBuffer.Data.Size = 0i64;
  v2->GlyphBuffer.Data.Policy.Capacity = 0i64;
  this->SysData.WinHDC = dc;
  v3 = (Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy> *)&this->NativeHinting.Data.Data;
  v3->Data = 0i64;
  v3->Size = 0i64;
  v3->Policy.Capacity = 0i64;
  Scaleform::Lock::Lock(&this->FontLock, 0);
  Scaleform::String::String(&src);
  v6 = 1i64;
  v7 = 24;
  v8 = 24;
  Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v3,
    v3,
    v3->Size + 1);
  v4 = (signed __int64)&v3->Data[v3->Size - 1];
  if ( v4 )
  {
    Scaleform::String::String((Scaleform::String *)v4, &src);
    *(_QWORD *)(v4 + 8) = v6;
    *(_DWORD *)(v4 + 16) = v7;
    *(_DWORD *)(v4 + 20) = v8;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 663
// RVA: 0xA13240
void __fastcall Scaleform::Render::FontProviderWinAPI::~FontProviderWinAPI(Scaleform::Render::FontProviderWinAPI *this)
{
  Scaleform::Render::FontProviderWinAPI *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontProviderWinAPI::`vftable';
  Scaleform::Lock::~Lock(&this->FontLock.cs);
  Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::Render::Font::NativeHintingType,Scaleform::AllocatorGH<Scaleform::Render::Font::NativeHintingType,2>,Scaleform::ArrayDefaultPolicy> *)&v1->NativeHinting.Data.Data);
  if ( v1->SysData.GlyphBuffer.Data.Data )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v1->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::Render::FontProvider::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore((Scaleform::RefCountImplCore *)&v1->vfptr);
}

// File Line: 668
// RVA: 0xA15230
Scaleform::Render::Font::NativeHintingType *__fastcall Scaleform::Render::FontProviderWinAPI::findNativeHinting(Scaleform::Render::FontProviderWinAPI *this, const char *name)
{
  unsigned int v2; // ebx
  const char *v3; // rsi
  Scaleform::Render::FontProviderWinAPI *v4; // rdi
  __int64 v5; // rax

  v2 = 0;
  v3 = name;
  v4 = this;
  if ( !this->NativeHinting.Data.Size )
    return 0i64;
  v5 = 0i64;
  while ( Scaleform::String::CompareNoCase(
            (const char *)((v4->NativeHinting.Data.Data[v5].Typeface.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
            v3) )
  {
    v5 = ++v2;
    if ( v2 >= v4->NativeHinting.Data.Size )
      return 0i64;
  }
  return &v4->NativeHinting.Data.Data[v2];
}

// File Line: 713
// RVA: 0xA134D0
Scaleform::Render::Font *__fastcall Scaleform::Render::FontProviderWinAPI::CreateFontA(Scaleform::Render::FontProviderWinAPI *this, const char *name, unsigned int fontFlags)
{
  const char *v3; // rsi
  Scaleform::Render::FontProviderWinAPI *v4; // rdi
  unsigned int v5; // ebx
  Scaleform::Render::ExternalFontWinAPI *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rbx
  Scaleform::Render::Font *result; // rax
  Scaleform::Render::Font::NativeHintingType *v10; // rax
  Scaleform::Render::Font::NativeHintingRange v11; // eax
  Scaleform::Render::Font::NativeHintingType *v12; // rcx
  int v13; // [rsp+70h] [rbp+18h]
  Scaleform::Render::ExternalFontWinAPI *v14; // [rsp+78h] [rbp+20h]

  v3 = name;
  v4 = this;
  v5 = fontFlags & 0x303 | 0x30;
  v13 = 75;
  v6 = (Scaleform::Render::ExternalFontWinAPI *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  this,
                                                  224ui64,
                                                  (Scaleform::AllocInfo *)&v13);
  v14 = v6;
  if ( v6 )
  {
    Scaleform::Render::ExternalFontWinAPI::ExternalFontWinAPI(v6, v4, &v4->SysData, v3, v5, &v4->FontLock);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( !v8 || *(_QWORD *)(v8 + 120) )
  {
    v10 = Scaleform::Render::FontProviderWinAPI::findNativeHinting(v4, v3);
    if ( v10 )
    {
      *(_DWORD *)(v8 + 208) = v10->MaxRasterHintedSize;
      *(_DWORD *)(v8 + 212) = v10->MaxVectorHintedSize;
      *(_DWORD *)(v8 + 200) = v10->RasterRange;
      v11 = v10->VectorRange;
    }
    else
    {
      v12 = v4->NativeHinting.Data.Data;
      *(_DWORD *)(v8 + 208) = v12->MaxRasterHintedSize;
      *(_DWORD *)(v8 + 212) = v12->MaxVectorHintedSize;
      *(_DWORD *)(v8 + 200) = v12->RasterRange;
      v11 = v12->VectorRange;
    }
    *(_DWORD *)(v8 + 204) = v11;
    result = (Scaleform::Render::Font *)v8;
  }
  else
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v8);
    result = 0i64;
  }
  return result;
}

// File Line: 747
// RVA: 0xA143A0
signed __int64 __fastcall Scaleform::Render::LoadFontNamesProc(tagENUMLOGFONTEXW *lpelfe, tagNEWTEXTMETRICEXW *__formal, unsigned int a3, __int64 lParam)
{
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v4; // rbx
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+28h] [rbp-20h]
  Scaleform::String v7; // [rsp+50h] [rbp+8h]

  v4 = (Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)lParam;
  Scaleform::String::String(&v7, lpelfe->elfFullName);
  key.pFirst = &v7;
  key.pSecond = &v7;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
    v4,
    v4,
    &key);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v7.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return 1i64;
}

// File Line: 755
// RVA: 0xA14360
void __fastcall Scaleform::Render::FontProviderWinAPI::LoadFontNames(Scaleform::Render::FontProviderWinAPI *this, Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *fontnames)
{
  HDC__ *v2; // rcx
  tagLOGFONTW Logfont; // [rsp+30h] [rbp-68h]

  v2 = this->SysData.WinHDC;
  Logfont.lfCharSet = 1;
  Logfont.lfFaceName[0] = 0;
  Logfont.lfPitchAndFamily = 0;
  EnumFontFamiliesExW(v2, &Logfont, (FONTENUMPROCW)Scaleform::Render::LoadFontNamesProc, (LPARAM)fontnames, 0);
}

