// File Line: 48
// RVA: 0x8C5090
void __fastcall Scaleform::GFx::URLBuilder::DefaultBuildURL(
        Scaleform::String *ppath,
        Scaleform::GFx::URLBuilder::LocationInfo *loc)
{
  __int64 v4; // rbp
  int v5; // ecx

  if ( Scaleform::GFx::URLBuilder::IsPathAbsolute((const char *)((loc->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                               + 12)) )
  {
    Scaleform::String::operator=(ppath, &loc->FileName);
  }
  else
  {
    v4 = *(_QWORD *)(loc->ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64;
    if ( v4 )
    {
      Scaleform::String::operator=(ppath, &loc->ParentPath);
      v5 = *(char *)((loc->ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + v4 + 11);
      if ( v5 != 92 && v5 != 47 )
        Scaleform::String::AppendString(ppath, "/", -1i64);
      Scaleform::String::operator+=(ppath, &loc->FileName);
    }
    else
    {
      Scaleform::String::operator=(ppath, &loc->FileName);
    }
  }
}

// File Line: 79
// RVA: 0x8E74A0
char __fastcall Scaleform::GFx::URLBuilder::IsPathAbsolute(char *putf8str)
{
  unsigned int Char_Advance0; // eax
  unsigned int v2; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h] BYREF

  putf8Buffer = putf8str;
  if ( !putf8str || !*putf8str )
    return 1;
  Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
  if ( !Char_Advance0 )
    --putf8Buffer;
  if ( Char_Advance0 == 47 || Char_Advance0 == 92 )
    return 1;
  while ( Char_Advance0 )
  {
    do
    {
      if ( Char_Advance0 == 58 )
      {
        v2 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
        if ( v2 )
        {
          if ( v2 == 47 || v2 == 92 )
            return 1;
        }
        else
        {
          --putf8Buffer;
        }
      }
      else if ( Char_Advance0 == 47 || Char_Advance0 == 92 )
      {
        return 0;
      }
      Char_Advance0 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    }
    while ( Char_Advance0 );
    --putf8Buffer;
  }
  return 0;
}

// File Line: 131
// RVA: 0x8CB250
bool __fastcall Scaleform::GFx::URLBuilder::ExtractFilePath(Scaleform::String *ppath)
{
  signed __int64 v2; // rbx
  bool v3; // sf
  unsigned int CharAt; // eax
  Scaleform::String *v5; // rax
  Scaleform::String result; // [rsp+48h] [rbp+10h] BYREF

  v2 = Scaleform::String::GetLength(ppath) - 1;
  v3 = v2 < 0;
  if ( v2 >= 0 )
  {
    while ( 1 )
    {
      CharAt = Scaleform::String::GetCharAt(ppath, v2);
      if ( CharAt == 47 || CharAt == 92 )
        break;
      if ( --v2 < 0 )
        goto LABEL_8;
    }
    v5 = Scaleform::String::Substring(ppath, &result, 0i64, v2 + 1);
    Scaleform::String::operator=(ppath, v5);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_8:
    v3 = v2 < 0;
  }
  return !v3;
}

// File Line: 155
// RVA: 0x8E7540
__int64 __fastcall Scaleform::GFx::URLBuilder::IsProtocol(Scaleform::String *path)
{
  unsigned __int64 v1; // rcx
  __int64 v2; // rax
  __int64 v3; // r8
  char v4; // dl
  char v5; // dl
  unsigned __int8 v6; // bl
  Scaleform::String result; // [rsp+48h] [rbp+10h] BYREF

  Scaleform::String::GetProtocol(path, &result);
  v1 = result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v2 = 0i64;
  v3 = 0i64;
  while ( 1 )
  {
    v4 = *(_BYTE *)(v1 + v3++ + 12);
    if ( v4 != aHttp[v3 - 1] )
      break;
    if ( v3 == 8 )
      goto LABEL_10;
  }
  while ( 1 )
  {
    v5 = *(_BYTE *)(v1 + v2++ + 12);
    if ( v5 != aFile_0[v2 - 1] )
      break;
    if ( v2 == 8 )
      goto LABEL_10;
  }
  if ( strcmp((const char *)(v1 + 12), "https://") )
  {
    v6 = 0;
    goto LABEL_11;
  }
LABEL_10:
  v6 = 1;
LABEL_11:
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v6;
}

// File Line: 302
// RVA: 0x899EB0
void __fastcall Scaleform::GFx::Loader::Loader(
        Scaleform::GFx::Loader *this,
        Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> *pfileOpener,
        Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> *pzlib)
{
  Scaleform::GFx::FileOpenerBase *pObject; // rdi
  Scaleform::GFx::ZlibSupportBase *v7; // rsi
  Scaleform::GFx::Loader::LoaderConfig cfg; // [rsp+28h] [rbp-20h] BYREF

  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::Loader::`vftable;
  cfg.DefLoadFlags = 0;
  if ( pfileOpener->pObject )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pfileOpener->pObject);
  pObject = pfileOpener->pObject;
  cfg.pFileOpener.pObject = pObject;
  if ( pzlib->pObject )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pzlib->pObject);
  v7 = pzlib->pObject;
  cfg.pZLibSupport.pObject = v7;
  Scaleform::GFx::Loader::InitLoader(this, &cfg);
  if ( v7 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pObject);
}

// File Line: 324
// RVA: 0x8A5B80
void __fastcall Scaleform::GFx::Loader::~Loader(Scaleform::GFx::Loader *this)
{
  Scaleform::Render::RenderBuffer *pImpl; // rcx
  Scaleform::Render::RenderBuffer *pStrongResourceLib; // rcx

  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::Loader::`vftable;
  pImpl = (Scaleform::Render::RenderBuffer *)this->pImpl;
  if ( pImpl )
    Scaleform::RefCountImpl::Release(pImpl);
  pStrongResourceLib = (Scaleform::Render::RenderBuffer *)this->pStrongResourceLib;
  if ( pStrongResourceLib )
    Scaleform::RefCountImpl::Release(pStrongResourceLib);
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable;
}

// File Line: 334
// RVA: 0x8E4650
void __fastcall Scaleform::GFx::Loader::InitLoader(
        Scaleform::GFx::Loader *this,
        Scaleform::GFx::Loader::LoaderConfig *cfg)
{
  bool v4; // bl
  Scaleform::GFx::ResourceLib *v5; // rax
  Scaleform::GFx::LoaderImpl *v6; // rax
  __int64 v7; // rbx

  v4 = (cfg->DefLoadFlags & 0x10000000) != 0;
  this->DefLoadFlags = cfg->DefLoadFlags;
  v5 = (Scaleform::GFx::ResourceLib *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        40i64);
  if ( v5 )
    Scaleform::GFx::ResourceLib::ResourceLib(v5, v4);
  this->pStrongResourceLib = v5;
  v6 = (Scaleform::GFx::LoaderImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                       Scaleform::Memory::pGlobalHeap,
                                       120i64);
  if ( v6 )
    Scaleform::GFx::LoaderImpl::LoaderImpl(v6, this->pStrongResourceLib, v4);
  this->pImpl = v6;
  if ( v6 )
  {
    this->vfptr->SetState(this, State_OrigScale9Parent|State_MaskNode, cfg->pFileOpener.pObject);
    v7 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
           Scaleform::Memory::pGlobalHeap,
           32i64);
    if ( v7 )
    {
      *(_QWORD *)v7 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v7 + 8) = 1;
      *(_QWORD *)v7 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v7 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v7 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable;
      *(_QWORD *)v7 = &Scaleform::GFx::State::`vftable;
      *(_DWORD *)(v7 + 16) = 16;
      *(_QWORD *)v7 = &Scaleform::GFx::ParseControl::`vftable;
      *(_DWORD *)(v7 + 24) = 0;
    }
    else
    {
      v7 = 0i64;
    }
    this->vfptr->SetState(this, (Scaleform::GFx::State::StateType)16i64, (Scaleform::GFx::State *)v7);
    if ( v7 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
    this->vfptr->SetState(this, State_Internal_MaskOwner|State_MaskNode|0x10, cfg->pZLibSupport.pObject);
  }
}

// File Line: 362
// RVA: 0x8DE410
Scaleform::GFx::StateBag *__fastcall Scaleform::GFx::MovieDefImpl::GetStateBagImpl(Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::StateBag *result; // rax

  result = *(Scaleform::GFx::StateBag **)&this->RefCount.Value;
  if ( result )
    result += 2;
  return result;
}

// File Line: 367
// RVA: 0x8BB140
bool __fastcall Scaleform::GFx::Loader::CheckTagLoader(Scaleform::GFx::Loader *this, unsigned int tagType)
{
  if ( !this->pImpl )
    return 0;
  if ( tagType < 0x5C )
    return Scaleform::GFx::SWF_TagLoaderTable[tagType] != 0i64;
  if ( tagType - 1000 > 9 )
    return 0;
  return Scaleform::GFx::GFx_GFX_TagLoaderTable[tagType - 1000] != 0i64;
}

// File Line: 414
// RVA: 0x8C1020
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::Loader::CreateMovie(
        Scaleform::GFx::Loader *this,
        const char *pfilename,
        unsigned int loadConstants,
        unsigned __int64 memoryArena)
{
  Scaleform::GFx::LoaderImpl *pImpl; // rcx

  if ( pfilename && *pfilename && (pImpl = this->pImpl) != 0i64 )
    return Scaleform::GFx::LoaderImpl::CreateMovie(pImpl, pfilename, loadConstants | this->DefLoadFlags, memoryArena);
  else
    return 0i64;
}

// File Line: 476
// RVA: 0x8E3C90
// attributes: thunk
void __fastcall Scaleform::GFx::System::Init(
        Scaleform::MemoryHeap::HeapDesc *rootHeapDesc,
        Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::System::Init(rootHeapDesc, psysAlloc);
}

