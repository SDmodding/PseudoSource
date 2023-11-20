// File Line: 48
// RVA: 0x8C5090
void __fastcall Scaleform::GFx::URLBuilder::DefaultBuildURL(Scaleform::String *ppath, Scaleform::GFx::URLBuilder::LocationInfo *loc)
{
  Scaleform::String *v2; // rbx
  Scaleform::GFx::URLBuilder::LocationInfo *v3; // rsi
  signed __int64 v4; // rbp
  int v5; // ecx

  v2 = ppath;
  v3 = loc;
  if ( Scaleform::GFx::URLBuilder::IsPathAbsolute((const char *)((loc->FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                               + 12)) )
  {
    Scaleform::String::operator=(v2, &v3->FileName);
  }
  else
  {
    v4 = *(_QWORD *)(v3->ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64;
    if ( v4 )
    {
      Scaleform::String::operator=(v2, &v3->ParentPath);
      v5 = *(char *)((v3->ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + v4 + 11);
      if ( v5 != 92 && v5 != 47 )
        Scaleform::String::AppendString(v2, "/", -1i64);
      Scaleform::String::operator+=(v2, &v3->FileName);
    }
    else
    {
      Scaleform::String::operator=(v2, &v3->FileName);
    }
  }
}

// File Line: 79
// RVA: 0x8E74A0
char __fastcall Scaleform::GFx::URLBuilder::IsPathAbsolute(const char *putf8str)
{
  unsigned int v1; // eax
  unsigned int v2; // eax
  char *putf8Buffer; // [rsp+30h] [rbp+8h]

  putf8Buffer = (char *)putf8str;
  if ( !putf8str || !*putf8str )
    return 1;
  v1 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
  if ( !v1 )
    --putf8Buffer;
  if ( v1 == 47 || v1 == 92 )
    return 1;
  while ( v1 )
  {
    do
    {
      if ( v1 == 58 )
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
      else if ( v1 == 47 || v1 == 92 )
      {
        return 0;
      }
      v1 = Scaleform::UTF8Util::DecodeNextChar_Advance0((const char **)&putf8Buffer);
    }
    while ( v1 );
    --putf8Buffer;
  }
  return 0;
}

// File Line: 131
// RVA: 0x8CB250
bool __fastcall Scaleform::GFx::URLBuilder::ExtractFilePath(Scaleform::String *ppath)
{
  Scaleform::String *v1; // rdi
  signed __int64 v2; // rbx
  bool v3; // sf
  unsigned int v4; // eax
  Scaleform::String *v5; // rax
  Scaleform::String result; // [rsp+48h] [rbp+10h]

  v1 = ppath;
  v2 = Scaleform::String::GetLength(ppath) - 1;
  v3 = v2 < 0;
  if ( v2 >= 0 )
  {
    while ( 1 )
    {
      v4 = Scaleform::String::GetCharAt(v1, v2);
      if ( v4 == 47 || v4 == 92 )
        break;
      if ( --v2 < 0 )
        goto LABEL_8;
    }
    v5 = Scaleform::String::Substring(v1, &result, 0i64, v2 + 1);
    Scaleform::String::operator=(v1, v5);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
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
  Scaleform::String result; // [rsp+48h] [rbp+10h]

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
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v6;
}

// File Line: 302
// RVA: 0x899EB0
void __fastcall Scaleform::GFx::Loader::Loader(Scaleform::GFx::Loader *this, Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> *pfileOpener, Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> *pzlib)
{
  Scaleform::GFx::Resource **v3; // rsi
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> *v4; // rdi
  Scaleform::GFx::Loader *v5; // rbx
  Scaleform::GFx::FileOpenerBase *v6; // rdi
  Scaleform::GFx::Resource *v7; // rsi
  Scaleform::GFx::Loader::LoaderConfig cfg; // [rsp+28h] [rbp-20h]

  v3 = (Scaleform::GFx::Resource **)pzlib;
  v4 = pfileOpener;
  v5 = this;
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable';
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::Loader::`vftable';
  cfg.DefLoadFlags = 0;
  if ( pfileOpener->pObject )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pfileOpener->pObject);
  v6 = v4->pObject;
  cfg.pFileOpener.pObject = v6;
  if ( *v3 )
    Scaleform::Render::RenderBuffer::AddRef(*v3);
  v7 = *v3;
  cfg.pZLibSupport.pObject = (Scaleform::GFx::ZlibSupportBase *)v7;
  Scaleform::GFx::Loader::InitLoader(v5, &cfg);
  if ( v7 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
  if ( v6 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6);
}

// File Line: 324
// RVA: 0x8A5B80
void __fastcall Scaleform::GFx::Loader::~Loader(Scaleform::GFx::Loader *this)
{
  Scaleform::GFx::Loader *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::Loader::`vftable';
  v2 = (Scaleform::Render::RenderBuffer *)this->pImpl;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v3 = (Scaleform::Render::RenderBuffer *)v1->pStrongResourceLib;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v1->vfptr = (Scaleform::GFx::StateBagVtbl *)&Scaleform::GFx::StateBag::`vftable';
}

// File Line: 334
// RVA: 0x8E4650
void __fastcall Scaleform::GFx::Loader::InitLoader(Scaleform::GFx::Loader *this, Scaleform::GFx::Loader::LoaderConfig *cfg)
{
  Scaleform::GFx::Loader::LoaderConfig *v2; // rsi
  Scaleform::GFx::Loader *v3; // rdi
  bool v4; // bl
  Scaleform::GFx::ResourceLib *v5; // rax
  Scaleform::GFx::LoaderImpl *v6; // rax
  __int64 v7; // rbx

  v2 = cfg;
  v3 = this;
  v4 = (cfg->DefLoadFlags >> 28) & 1;
  this->DefLoadFlags = cfg->DefLoadFlags;
  v5 = (Scaleform::GFx::ResourceLib *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                        Scaleform::Memory::pGlobalHeap,
                                        40i64);
  if ( v5 )
    Scaleform::GFx::ResourceLib::ResourceLib(v5, v4);
  v3->pStrongResourceLib = v5;
  v6 = (Scaleform::GFx::LoaderImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                       Scaleform::Memory::pGlobalHeap,
                                       120i64);
  if ( v6 )
    Scaleform::GFx::LoaderImpl::LoaderImpl(v6, v3->pStrongResourceLib, v4);
  v3->pImpl = v6;
  if ( v6 )
  {
    v3->vfptr->SetState(
      (Scaleform::GFx::StateBag *)&v3->vfptr,
      State_OrigScale9Parent|State_MaskNode,
      (Scaleform::GFx::State *)&v2->pFileOpener.pObject->vfptr);
    v7 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
           Scaleform::Memory::pGlobalHeap,
           32i64);
    if ( v7 )
    {
      *(_QWORD *)v7 = &Scaleform::RefCountImplCore::`vftable';
      *(_DWORD *)(v7 + 8) = 1;
      *(_QWORD *)v7 = &Scaleform::RefCountImpl::`vftable';
      *(_QWORD *)v7 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
      *(_QWORD *)v7 = &Scaleform::RefCountBase<Scaleform::GFx::State,2>::`vftable';
      *(_QWORD *)v7 = &Scaleform::GFx::State::`vftable';
      *(_DWORD *)(v7 + 16) = 16;
      *(_QWORD *)v7 = &Scaleform::GFx::ParseControl::`vftable';
      *(_DWORD *)(v7 + 24) = 0;
    }
    else
    {
      v7 = 0i64;
    }
    v3->vfptr->SetState(
      (Scaleform::GFx::StateBag *)&v3->vfptr,
      (Scaleform::GFx::State::StateType)16i64,
      (Scaleform::GFx::State *)v7);
    if ( v7 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v7);
    v3->vfptr->SetState(
      (Scaleform::GFx::StateBag *)&v3->vfptr,
      State_Internal_MaskOwner|State_MaskNode|0x10,
      (Scaleform::GFx::State *)&v2->pZLibSupport.pObject->vfptr);
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
bool __fastcall Scaleform::GFx::Loader::CheckTagLoader(Scaleform::GFx::Loader *this, int tagType)
{
  if ( !this->pImpl )
    return 0;
  if ( (unsigned int)tagType < 0x5C )
    return Scaleform::GFx::SWF_TagLoaderTable[tagType] != 0i64;
  if ( (unsigned int)(tagType - 1000) > 9 )
    return 0;
  return Scaleform::GFx::GFx_GFX_TagLoaderTable[tagType - 1000] != 0i64;
}

// File Line: 414
// RVA: 0x8C1020
Scaleform::GFx::MovieDefImpl *__fastcall Scaleform::GFx::Loader::CreateMovie(Scaleform::GFx::Loader *this, const char *pfilename, unsigned int loadConstants, unsigned __int64 memoryArena)
{
  Scaleform::GFx::Loader *v4; // rax
  Scaleform::GFx::LoaderImpl *v5; // rcx
  Scaleform::GFx::MovieDefImpl *result; // rax

  v4 = this;
  if ( pfilename && *pfilename && (v5 = this->pImpl) != 0i64 )
    result = Scaleform::GFx::LoaderImpl::CreateMovie(v5, pfilename, loadConstants | v4->DefLoadFlags, memoryArena);
  else
    result = 0i64;
  return result;
}

// File Line: 476
// RVA: 0x8E3C90
void __fastcall Scaleform::GFx::System::Init(Scaleform::MemoryHeap::HeapDesc *rootHeapDesc, Scaleform::SysAllocBase *psysAlloc)
{
  Scaleform::System::Init(rootHeapDesc, psysAlloc);
}

