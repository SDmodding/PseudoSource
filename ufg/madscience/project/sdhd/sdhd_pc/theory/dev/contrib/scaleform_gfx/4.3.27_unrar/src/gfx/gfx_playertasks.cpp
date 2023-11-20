// File Line: 25
// RVA: 0x8E11E0
Scaleform::String *__fastcall Scaleform::GFx::GetUrlStrGfx(Scaleform::String *result, Scaleform::String *url)
{
  Scaleform::String *v2; // rdi
  Scaleform::String *v3; // rbx
  const char *v4; // rax
  unsigned __int64 v5; // rcx

  v2 = url;
  v3 = result;
  Scaleform::String::String(result);
  v4 = (const char *)(v2->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v5 = *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64;
  if ( v5 > 4 && !Scaleform::String::CompareNoCase(&v4[v5 + 8], ".swf") )
  {
    Scaleform::String::Clear(v3);
    Scaleform::String::AppendString(
      v3,
      (const char *)((v2->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
      (*(_QWORD *)(v2->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) - 4);
    Scaleform::String::AppendString(v3, ".gfx", -1i64);
  }
  return v3;
}

// File Line: 40
// RVA: 0x89BB90
void __fastcall Scaleform::GFx::MoviePreloadTask::MoviePreloadTask(Scaleform::GFx::MoviePreloadTask *this, Scaleform::GFx::MovieImpl *pmovieRoot, Scaleform::String *url, bool stripped, bool quietOpen)
{
  bool v5; // r12
  Scaleform::String *v6; // rbx
  Scaleform::GFx::MovieImpl *v7; // rsi
  Scaleform::GFx::MoviePreloadTask *v8; // rdi
  Scaleform::GFx::LoadStates *v9; // r14
  Scaleform::String *v10; // rbx
  __int64 v11; // rdx
  Scaleform::GFx::LoadStates *v12; // r15
  Scaleform::GFx::LoaderImpl *v13; // rbx
  Scaleform::GFx::StateBag *v14; // rax
  Scaleform::GFx::LoadStates *v15; // rax
  Scaleform::Render::RenderBuffer *v16; // rcx
  unsigned int v17; // eax
  const char *v18; // rax
  Scaleform::String *v19; // rax
  unsigned __int64 v20; // rdx
  Scaleform::String result; // [rsp+78h] [rbp+10h]

  v5 = stripped;
  v6 = url;
  v7 = pmovieRoot;
  v8 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Task,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable';
  this->ThisTaskId = 131073;
  v9 = 0i64;
  this->CurrentState = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MoviePreloadTask::`vftable';
  this->pLoadStates.pObject = 0i64;
  Scaleform::String::String(&this->Level0Path);
  Scaleform::String::String(&v8->Url, v6);
  v10 = &v8->UrlStrGfx;
  Scaleform::String::String(&v8->UrlStrGfx);
  v8->pDefImpl.pObject = 0i64;
  v8->Done = 0;
  v12 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        144ui64,
                                        0i64);
  if ( v12 )
  {
    v13 = v7->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v14 = (Scaleform::GFx::StateBag *)((__int64 (__cdecl *)(Scaleform::GFx::StateBagVtbl **, __int64))v7->vfptr->GetStateBagImpl)(
                                        &v7->vfptr,
                                        v11);
    Scaleform::GFx::LoadStates::LoadStates(v12, v13, v14, 0i64);
    v9 = v15;
    v10 = &v8->UrlStrGfx;
  }
  v16 = (Scaleform::Render::RenderBuffer *)v8->pLoadStates.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  v8->pLoadStates.pObject = v9;
  v17 = v7->pMainMovieDef.pObject->pBindData.pObject->LoadFlags & 0xFFFFFFFC | 0x10000;
  v8->LoadFlags = v17;
  if ( quietOpen )
    v8->LoadFlags = v17 | 0x200000;
  if ( !v7->pMainMovie
    || (v18 = (const char *)((__int64 (__cdecl *)(Scaleform::GFx::MovieDefImpl *, __int64))v7->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(
                              v7->pMainMovieDef.pObject,
                              v11),
        Scaleform::String::operator=(&v8->Level0Path, v18),
        !Scaleform::GFx::URLBuilder::ExtractFilePath(&v8->Level0Path)) )
  {
    Scaleform::String::Clear(&v8->Level0Path);
  }
  if ( v5 )
  {
    v19 = Scaleform::GFx::GetUrlStrGfx(&result, &v8->Url);
    Scaleform::String::operator=(v10, v19);
    v20 = result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v20);
  }
}

// File Line: 53
// RVA: 0x8C9DB0
void __fastcall Scaleform::GFx::MoviePreloadTask::Execute(Scaleform::GFx::MoviePreloadTask *this)
{
  Scaleform::GFx::MoviePreloadTask *v1; // rdi
  Scaleform::GFx::MovieDefImpl *v2; // rbp
  Scaleform::GFx::MovieDefImpl *v3; // rsi
  Scaleform::GFx::ResourceLibBase *v4; // rcx
  Scaleform::GFx::MovieDefImpl *v5; // rbp
  Scaleform::GFx::MovieDefImpl *v6; // rsi
  Scaleform::GFx::ResourceLibBase *v7; // rcx
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+38h] [rbp-40h]
  Scaleform::GFx::URLBuilder::LocationInfo v9; // [rsp+50h] [rbp-28h]

  v1 = this;
  if ( Scaleform::String::GetLength(&this->UrlStrGfx) )
  {
    loc.Use = 3;
    Scaleform::String::String(&loc.FileName, &v1->UrlStrGfx);
    Scaleform::String::String(&loc.ParentPath, &v1->Level0Path);
    v2 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v1->pLoadStates.pObject, &loc, v1->LoadFlags, 0i64);
    v3 = v1->pDefImpl.pObject;
    if ( v3 && !_InterlockedDecrement(&v3->RefCount.Value) )
    {
      v4 = v3->pLib;
      if ( v4 )
      {
        v4->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v4->vfptr, (unsigned int)v3);
        v3->pLib = 0i64;
      }
      v3->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v3->vfptr, 1u);
    }
    v1->pDefImpl.pObject = v2;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  if ( !v1->pDefImpl.pObject )
  {
    v9.Use = 3;
    Scaleform::String::String(&v9.FileName, &v1->Url);
    Scaleform::String::String(&v9.ParentPath, &v1->Level0Path);
    v5 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(v1->pLoadStates.pObject, &v9, v1->LoadFlags, 0i64);
    v6 = v1->pDefImpl.pObject;
    if ( v6 && !_InterlockedDecrement(&v6->RefCount.Value) )
    {
      v7 = v6->pLib;
      if ( v7 )
      {
        v7->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)v6);
        v6->pLib = 0i64;
      }
      v6->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v6->vfptr, 1u);
    }
    v1->pDefImpl.pObject = v5;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  v1->Done = 1;
}

// File Line: 70
// RVA: 0x8E6F10
bool __fastcall Scaleform::GFx::MoviePreloadTask::IsDone(Scaleform::GFx::MoviePreloadTask *this)
{
  return this->Done == 1;
}

// File Line: 84
// RVA: 0x898DE0
void __fastcall Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(Scaleform::GFx::LoadQueueEntryMT *this, Scaleform::GFx::LoadQueueEntry *pqueueEntry, Scaleform::GFx::MovieImpl *pmovieRoot)
{
  this->pMovieImpl = pmovieRoot;
  this->pQueueEntry = pqueueEntry;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable';
  this->pNext = 0i64;
  this->pPrev = 0i64;
}

// File Line: 88
// RVA: 0x8A5330
void __fastcall Scaleform::GFx::LoadQueueEntryMT::~LoadQueueEntryMT(Scaleform::GFx::LoadQueueEntryMT *this)
{
  Scaleform::GFx::LoadQueueEntry *v1; // rcx

  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable';
  v1 = this->pQueueEntry;
  if ( v1 )
    v1->vfptr->__vecDelDtor(v1, 1u);
}

// File Line: 102
// RVA: 0x899DD0
void __fastcall Scaleform::GFx::LoadVarsTask::LoadVarsTask(Scaleform::GFx::LoadVarsTask *this, Scaleform::GFx::LoadStates *pls, Scaleform::String *level0Path, Scaleform::String *url)
{
  Scaleform::String *v4; // rsi
  Scaleform::String *v5; // rbp
  Scaleform::GFx::LoadStates *v6; // rdi
  Scaleform::GFx::LoadVarsTask *v7; // rbx

  v4 = url;
  v5 = level0Path;
  v6 = pls;
  v7 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Task,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable';
  this->ThisTaskId = 131073;
  this->CurrentState = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadVarsTask::`vftable';
  if ( pls )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pls);
  v7->pLoadStates.pObject = v6;
  Scaleform::String::String(&v7->Level0Path, v5);
  Scaleform::String::String(&v7->Url, v4);
  Scaleform::String::String(&v7->Data);
  v7->FileLen = 0;
  v7->Done = 0;
  v7->Succeeded = 0;
}

// File Line: 106
// RVA: 0x8C98E0
void __fastcall Scaleform::GFx::LoadVarsTask::Execute(Scaleform::GFx::LoadVarsTask *this)
{
  Scaleform::GFx::LoadVarsTask *v1; // rdi
  Scaleform::GFx::URLBuilder *v2; // rcx
  signed __int64 v3; // rbx
  int v4; // ecx
  Scaleform::File *v5; // rbx
  unsigned __int64 v6; // r15
  Scaleform::GFx::LoadStates *v7; // r14
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v8; // rcx
  Scaleform::Log *v9; // rax
  int v10; // [rsp+38h] [rbp-38h]
  Scaleform::String src; // [rsp+40h] [rbp-30h]
  Scaleform::String v12; // [rsp+48h] [rbp-28h]
  __int64 v13; // [rsp+50h] [rbp-20h]
  __int64 v14; // [rsp+58h] [rbp-18h]
  __int64 v15; // [rsp+60h] [rbp-10h]
  Scaleform::String path; // [rsp+A0h] [rbp+30h]
  Scaleform::File *v17; // [rsp+A8h] [rbp+38h]
  __int64 *v18; // [rsp+B0h] [rbp+40h]

  v1 = this;
  v10 = 4;
  Scaleform::String::String(&src, &this->Url);
  Scaleform::String::String(&v12, &v1->Level0Path);
  Scaleform::String::String(&path);
  v2 = v1->pLoadStates.pObject->pBindStates.pObject->pURLBulider.pObject;
  if ( v2 )
  {
    ((void (__fastcall *)(Scaleform::GFx::URLBuilder *, Scaleform::String *, int *))v2->vfptr[1].__vecDelDtor)(
      v2,
      &path,
      &v10);
  }
  else if ( Scaleform::GFx::URLBuilder::IsPathAbsolute((const char *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12))
         || (v3 = *(_QWORD *)(v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) == 0 )
  {
    Scaleform::String::operator=(&path, &src);
  }
  else
  {
    Scaleform::String::operator=(&path, &v12);
    v4 = *(char *)((v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + v3 + 11);
    if ( v4 != 92 && v4 != 47 )
      Scaleform::String::AppendString(&path, "/", -1i64);
    Scaleform::String::operator+=(&path, &src);
  }
  v5 = 0i64;
  v17 = 0i64;
  v18 = &v13;
  v13 = 0i64;
  v14 = 0i64;
  v15 = 0i64;
  if ( Scaleform::GFx::URLBuilder::IsProtocol(&path) )
    goto LABEL_32;
  v6 = path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v7 = v1->pLoadStates.pObject;
  if ( v7->pBindStates.pObject->pFileOpener.pObject )
  {
    v9 = v7->pLog.pObject->pLog.pObject;
    if ( !v9 )
      v9 = Scaleform::Log::GetGlobalLog();
    v5 = (Scaleform::File *)((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, unsigned __int64, Scaleform::Log *, signed __int64, signed int))v7->pBindStates.pObject->pFileOpener.pObject->vfptr[3].__vecDelDtor)(
                              v7->pBindStates.pObject->pFileOpener.pObject,
                              v6 + 12,
                              v9,
                              33i64,
                              438);
  }
  else
  {
    v8 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v7->pLog.pObject;
    if ( v8 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        v8 + 3,
        "Loader failed to open '%s', FileOpener not installe",
        v6 + 12);
  }
  v17 = v5;
  if ( !v5 )
LABEL_32:
    v1->Succeeded = 0;
  else
    v1->Succeeded = Scaleform::GFx::MovieImpl::ReadTextData(&v1->Data, v5, &v1->FileLen, 0);
  v1->Done = 1;
  v18 = &v13;
  if ( v13 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8), 0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 156
// RVA: 0x899010
void __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadQueueEntryMT_LoadVars(Scaleform::GFx::LoadQueueEntryMT_LoadVars *this, Scaleform::GFx::LoadQueueEntry *pqueueEntry, Scaleform::GFx::MovieImpl *pmovieRoot)
{
  Scaleform::GFx::LoadQueueEntry *v3; // r14
  Scaleform::GFx::LoadQueueEntryMT_LoadVars *v4; // rsi
  Scaleform::GFx::LoadVarsTask *v5; // rbp
  Scaleform::String::DataDesc *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // r8
  Scaleform::GFx::LoaderImpl *v8; // rbx
  Scaleform::GFx::StateBag *v9; // rax
  Scaleform::GFx::LoadStates *v10; // rax
  Scaleform::GFx::LoadStates *v11; // rbx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::MovieImpl *v13; // rcx
  const char *v14; // rax
  signed __int64 v15; // rdi
  unsigned int v16; // eax
  Scaleform::String *v17; // rax
  Scaleform::GFx::LoadVarsTask *v18; // rax
  Scaleform::GFx::LoadVarsTask *v19; // rax
  Scaleform::Render::RenderBuffer *v20; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *v21; // rax
  unsigned __int64 v22; // rdx
  Scaleform::String level0Path; // [rsp+68h] [rbp+10h]
  Scaleform::String result; // [rsp+70h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::TaskManager> v25; // [rsp+78h] [rbp+20h]

  v3 = pqueueEntry;
  v4 = this;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable';
  v5 = 0i64;
  this->pNext = 0i64;
  this->pPrev = 0i64;
  this->pMovieImpl = pmovieRoot;
  this->pQueueEntry = pqueueEntry;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT_LoadVars::`vftable';
  this->pTask.pObject = 0i64;
  this->pLoadStates.pObject = 0i64;
  v6 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        144ui64,
                                        0i64);
  result.pData = v6;
  if ( v6 )
  {
    v7 = v4->pMovieImpl;
    v8 = v7->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v9 = (Scaleform::GFx::StateBag *)((__int64 (__cdecl *)(Scaleform::GFx::StateBagVtbl **))v7->vfptr->GetStateBagImpl)(&v7->vfptr);
    Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v6, v8, v9, 0i64);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = (Scaleform::Render::RenderBuffer *)v4->pLoadStates.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v4->pLoadStates.pObject = v11;
  Scaleform::String::String(&level0Path);
  v13 = v4->pMovieImpl;
  if ( !v13->pMainMovie )
    goto LABEL_15;
  v14 = (const char *)((__int64 (__cdecl *)(Scaleform::GFx::MovieDefImpl *))v13->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(v13->pMainMovieDef.pObject);
  Scaleform::String::operator=(&level0Path, v14);
  v15 = Scaleform::String::GetLength(&level0Path) - 1;
  if ( v15 < 0 )
    goto LABEL_15;
  while ( 1 )
  {
    v16 = Scaleform::String::GetCharAt(&level0Path, v15);
    if ( v16 == 47 || v16 == 92 )
      break;
    if ( --v15 < 0 )
      goto LABEL_15;
  }
  v17 = Scaleform::String::Substring(&level0Path, &result, 0i64, v15 + 1);
  Scaleform::String::operator=(&level0Path, v17);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v15 < 0 )
LABEL_15:
    Scaleform::String::Clear(&level0Path);
  v18 = (Scaleform::GFx::LoadVarsTask *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                          Scaleform::Memory::pGlobalHeap,
                                          72i64);
  if ( v18 )
  {
    Scaleform::GFx::LoadVarsTask::LoadVarsTask(v18, v4->pLoadStates.pObject, &level0Path, &v3->URL);
    v5 = v19;
  }
  v20 = (Scaleform::Render::RenderBuffer *)v4->pTask.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  v4->pTask.pObject = v5;
  v21 = Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v4->pMovieImpl->vfptr, &v25);
  v21->pObject->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)v21->pObject, (unsigned int)v4->pTask.pObject);
  if ( v25.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v25.pObject);
  v22 = level0Path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((level0Path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v22);
}

// File Line: 165
// RVA: 0x8A53C0
void __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadVars::~LoadQueueEntryMT_LoadVars(Scaleform::GFx::LoadQueueEntryMT_LoadVars *this)
{
  Scaleform::GFx::LoadQueueEntryMT_LoadVars *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::LoadQueueEntry *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT_LoadVars::`vftable';
  v2 = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v3 = (Scaleform::Render::RenderBuffer *)v1->pTask.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v1->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable';
  v4 = v1->pQueueEntry;
  if ( v4 )
    v4->vfptr->__vecDelDtor(v4, 1u);
}

// File Line: 171
// RVA: 0x8E8600
__int64 __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadFinished(Scaleform::GFx::LoadQueueEntryMT_LoadVars *this)
{
  Scaleform::GFx::LoadQueueEntryMT_LoadVars *v1; // rdi
  Scaleform::GFx::LoadVarsTask *v2; // rbx
  char v3; // al
  char v4; // r8
  __int64 v5; // r9
  Scaleform::GFx::LoadQueueEntry *v6; // rdx
  unsigned __int8 v7; // bl
  char v8; // ST28_1
  unsigned __int64 v9; // rdx
  Scaleform::String v11; // [rsp+50h] [rbp+8h]

  v1 = this;
  Scaleform::String::String(&v11);
  v2 = v1->pTask.pObject;
  if ( v2->Done == 1 )
  {
    Scaleform::String::operator=(&v11, &v2->Data);
    v5 = (unsigned int)v2->FileLen;
    v4 = v2->Succeeded;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v4 = (char)v11.pData;
    v5 = LODWORD(v11.HeapTypeBits);
  }
  v6 = v1->pQueueEntry;
  if ( v6->Canceled )
  {
    if ( v3 )
      goto LABEL_10;
LABEL_8:
    v7 = 0;
    goto LABEL_11;
  }
  if ( !v3 )
    goto LABEL_8;
  v8 = v4;
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::LoadQueueEntry *, Scaleform::GFx::LoadStates *, Scaleform::String *, _QWORD, char, signed __int64))v1->pMovieImpl->pASMovieRoot.pObject->vfptr[36].__vecDelDtor)(
    v1->pMovieImpl->pASMovieRoot.pObject,
    v6,
    v1->pLoadStates.pObject,
    &v11,
    (signed int)v5,
    v8,
    -2i64);
LABEL_10:
  v7 = 1;
LABEL_11:
  v9 = v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *, unsigned __int64, Scaleform::MemoryHeapVtbl *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v9,
      Scaleform::Memory::pGlobalHeap->vfptr,
      v5);
  return v7;
}

// File Line: 194
// RVA: 0x898B80
void __fastcall Scaleform::GFx::LoadBinaryTask::LoadBinaryTask(Scaleform::GFx::LoadBinaryTask *this, Scaleform::GFx::LoadStates *pls, Scaleform::String *level0Path, Scaleform::String *url)
{
  Scaleform::String *v4; // rsi
  Scaleform::String *v5; // rbp
  Scaleform::GFx::LoadStates *v6; // rdi
  Scaleform::GFx::LoadBinaryTask *v7; // rbx
  signed __int64 v8; // [rsp+58h] [rbp+10h]

  v4 = url;
  v5 = level0Path;
  v6 = pls;
  v7 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Task,2>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable';
  this->ThisTaskId = 131073;
  this->CurrentState = 0;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadBinaryTask::`vftable';
  if ( pls )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pls);
  v7->pLoadStates.pObject = v6;
  Scaleform::String::String(&v7->Level0Path, v5);
  Scaleform::String::String(&v7->Url, v4);
  v8 = (signed __int64)&v7->Data;
  *(_OWORD *)v8 = 0ui64;
  *(_QWORD *)(v8 + 16) = 0i64;
  v7->FileLen = 0;
  v7->Done = 0;
  v7->Succeeded = 0;
}

// File Line: 198
// RVA: 0x8C9670
void __fastcall Scaleform::GFx::LoadBinaryTask::Execute(Scaleform::GFx::LoadBinaryTask *this)
{
  Scaleform::GFx::LoadBinaryTask *v1; // rdi
  Scaleform::GFx::URLBuilder *v2; // rcx
  signed __int64 v3; // rbx
  int v4; // ecx
  Scaleform::File *v5; // rbx
  unsigned __int64 v6; // r15
  Scaleform::GFx::LoadStates *v7; // r14
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v8; // rcx
  Scaleform::Log *v9; // rax
  int v10; // [rsp+38h] [rbp-38h]
  Scaleform::String src; // [rsp+40h] [rbp-30h]
  Scaleform::String v12; // [rsp+48h] [rbp-28h]
  __int64 v13; // [rsp+50h] [rbp-20h]
  __int64 v14; // [rsp+58h] [rbp-18h]
  __int64 v15; // [rsp+60h] [rbp-10h]
  Scaleform::String path; // [rsp+A0h] [rbp+30h]
  Scaleform::File *v17; // [rsp+A8h] [rbp+38h]
  __int64 *v18; // [rsp+B0h] [rbp+40h]

  v1 = this;
  v10 = 4;
  Scaleform::String::String(&src, &this->Url);
  Scaleform::String::String(&v12, &v1->Level0Path);
  Scaleform::String::String(&path);
  v2 = v1->pLoadStates.pObject->pBindStates.pObject->pURLBulider.pObject;
  if ( v2 )
  {
    ((void (__fastcall *)(Scaleform::GFx::URLBuilder *, Scaleform::String *, int *))v2->vfptr[1].__vecDelDtor)(
      v2,
      &path,
      &v10);
  }
  else if ( Scaleform::GFx::URLBuilder::IsPathAbsolute((const char *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12))
         || (v3 = *(_QWORD *)(v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) == 0 )
  {
    Scaleform::String::operator=(&path, &src);
  }
  else
  {
    Scaleform::String::operator=(&path, &v12);
    v4 = *(char *)((v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + v3 + 11);
    if ( v4 != 92 && v4 != 47 )
      Scaleform::String::AppendString(&path, "/", -1i64);
    Scaleform::String::operator+=(&path, &src);
  }
  v5 = 0i64;
  v17 = 0i64;
  v18 = &v13;
  v13 = 0i64;
  v14 = 0i64;
  v15 = 0i64;
  if ( Scaleform::GFx::URLBuilder::IsProtocol(&path) )
    goto LABEL_32;
  v6 = path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v7 = v1->pLoadStates.pObject;
  if ( v7->pBindStates.pObject->pFileOpener.pObject )
  {
    v9 = v7->pLog.pObject->pLog.pObject;
    if ( !v9 )
      v9 = Scaleform::Log::GetGlobalLog();
    v5 = (Scaleform::File *)((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, unsigned __int64, Scaleform::Log *, signed __int64, signed int))v7->pBindStates.pObject->pFileOpener.pObject->vfptr[3].__vecDelDtor)(
                              v7->pBindStates.pObject->pFileOpener.pObject,
                              v6 + 12,
                              v9,
                              33i64,
                              438);
  }
  else
  {
    v8 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v7->pLog.pObject;
    if ( v8 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        v8 + 3,
        "Loader failed to open '%s', FileOpener not installe",
        v6 + 12);
  }
  v17 = v5;
  if ( !v5 )
LABEL_32:
    v1->Succeeded = 0;
  else
    v1->Succeeded = Scaleform::GFx::MovieImpl::ReadBinaryData(&v1->Data, v5, &v1->FileLen);
  v1->Done = 1;
  v18 = &v13;
  if ( v13 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8), 0xFFFFFFFF) == 1 )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

// File Line: 248
// RVA: 0x898E00
void __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadBinary::LoadQueueEntryMT_LoadBinary(Scaleform::GFx::LoadQueueEntryMT_LoadBinary *this, Scaleform::GFx::LoadQueueEntry *pqueueEntry, Scaleform::GFx::MovieImpl *pmovieRoot)
{
  Scaleform::GFx::LoadQueueEntry *v3; // r14
  Scaleform::GFx::LoadQueueEntryMT_LoadBinary *v4; // rsi
  Scaleform::GFx::LoadBinaryTask *v5; // rbp
  Scaleform::String::DataDesc *v6; // rdi
  Scaleform::GFx::MovieImpl *v7; // r8
  Scaleform::GFx::LoaderImpl *v8; // rbx
  Scaleform::GFx::StateBag *v9; // rax
  Scaleform::GFx::LoadStates *v10; // rax
  Scaleform::GFx::LoadStates *v11; // rbx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::MovieImpl *v13; // rcx
  const char *v14; // rax
  signed __int64 v15; // rdi
  unsigned int v16; // eax
  Scaleform::String *v17; // rax
  Scaleform::GFx::LoadBinaryTask *v18; // rax
  Scaleform::GFx::LoadBinaryTask *v19; // rax
  Scaleform::Render::RenderBuffer *v20; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *v21; // rax
  unsigned __int64 v22; // rdx
  Scaleform::String level0Path; // [rsp+68h] [rbp+10h]
  Scaleform::String result; // [rsp+70h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::TaskManager> v25; // [rsp+78h] [rbp+20h]

  v3 = pqueueEntry;
  v4 = this;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable';
  v5 = 0i64;
  this->pNext = 0i64;
  this->pPrev = 0i64;
  this->pMovieImpl = pmovieRoot;
  this->pQueueEntry = pqueueEntry;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT_LoadBinary::`vftable';
  this->pTask.pObject = 0i64;
  this->pLoadStates.pObject = 0i64;
  v6 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        144ui64,
                                        0i64);
  result.pData = v6;
  if ( v6 )
  {
    v7 = v4->pMovieImpl;
    v8 = v7->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v9 = (Scaleform::GFx::StateBag *)((__int64 (__cdecl *)(Scaleform::GFx::StateBagVtbl **))v7->vfptr->GetStateBagImpl)(&v7->vfptr);
    Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v6, v8, v9, 0i64);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = (Scaleform::Render::RenderBuffer *)v4->pLoadStates.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v4->pLoadStates.pObject = v11;
  Scaleform::String::String(&level0Path);
  v13 = v4->pMovieImpl;
  if ( !v13->pMainMovie )
    goto LABEL_15;
  v14 = (const char *)((__int64 (__cdecl *)(Scaleform::GFx::MovieDefImpl *))v13->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(v13->pMainMovieDef.pObject);
  Scaleform::String::operator=(&level0Path, v14);
  v15 = Scaleform::String::GetLength(&level0Path) - 1;
  if ( v15 < 0 )
    goto LABEL_15;
  while ( 1 )
  {
    v16 = Scaleform::String::GetCharAt(&level0Path, v15);
    if ( v16 == 47 || v16 == 92 )
      break;
    if ( --v15 < 0 )
      goto LABEL_15;
  }
  v17 = Scaleform::String::Substring(&level0Path, &result, 0i64, v15 + 1);
  Scaleform::String::operator=(&level0Path, v17);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v15 < 0 )
LABEL_15:
    Scaleform::String::Clear(&level0Path);
  v18 = (Scaleform::GFx::LoadBinaryTask *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                            Scaleform::Memory::pGlobalHeap,
                                            88i64);
  if ( v18 )
  {
    Scaleform::GFx::LoadBinaryTask::LoadBinaryTask(v18, v4->pLoadStates.pObject, &level0Path, &v3->URL);
    v5 = v19;
  }
  v20 = (Scaleform::Render::RenderBuffer *)v4->pTask.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  v4->pTask.pObject = v5;
  v21 = Scaleform::GFx::StateBag::GetTaskManager((Scaleform::GFx::StateBag *)&v4->pMovieImpl->vfptr, &v25);
  v21->pObject->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)v21->pObject, (unsigned int)v4->pTask.pObject);
  if ( v25.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v25.pObject);
  v22 = level0Path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((level0Path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v22);
}

// File Line: 257
// RVA: 0x8A5350
void __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadBinary::~LoadQueueEntryMT_LoadBinary(Scaleform::GFx::LoadQueueEntryMT_LoadBinary *this)
{
  Scaleform::GFx::LoadQueueEntryMT_LoadBinary *v1; // rbx
  Scaleform::Render::RenderBuffer *v2; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::LoadQueueEntry *v4; // rcx

  v1 = this;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT_LoadBinary::`vftable';
  v2 = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( v2 )
    Scaleform::RefCountImpl::Release(v2);
  v3 = (Scaleform::Render::RenderBuffer *)v1->pTask.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v1->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable';
  v4 = v1->pQueueEntry;
  if ( v4 )
    v4->vfptr->__vecDelDtor(v4, 1u);
}

// File Line: 263
// RVA: 0x8E8510
__int64 __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadBinary::LoadFinished(Scaleform::GFx::LoadQueueEntryMT_LoadBinary *this)
{
  Scaleform::GFx::LoadQueueEntryMT_LoadBinary *v1; // rdi
  Scaleform::GFx::LoadBinaryTask *v2; // rbx
  char v3; // al
  char v4; // r8
  __int64 v5; // r9
  Scaleform::GFx::LoadQueueEntry *v6; // rdx
  unsigned __int8 v7; // bl
  char v8; // ST28_1
  Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> v10; // [rsp+38h] [rbp-20h]

  v1 = this;
  v10.Data = 0i64;
  v10.Size = 0i64;
  v10.Policy.Capacity = 0i64;
  v2 = this->pTask.pObject;
  if ( v2->Done == 1 )
  {
    Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v10,
      v2->Data.Data.Size);
    memmove(v10.Data, v2->Data.Data.Data, v2->Data.Data.Size);
    v5 = (unsigned int)v2->FileLen;
    v4 = v2->Succeeded;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    v4 = (unsigned __int64)&v10;
    v5 = (unsigned int)&v10;
  }
  v6 = v1->pQueueEntry;
  if ( v6->Canceled )
  {
    if ( v3 )
      goto LABEL_10;
LABEL_8:
    v7 = 0;
    goto LABEL_11;
  }
  if ( !v3 )
    goto LABEL_8;
  v8 = v4;
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::LoadQueueEntry *, Scaleform::GFx::LoadStates *, Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *, _QWORD, char, signed __int64))v1->pMovieImpl->pASMovieRoot.pObject->vfptr[37].__vecDelDtor)(
    v1->pMovieImpl->pASMovieRoot.pObject,
    v6,
    v1->pLoadStates.pObject,
    &v10,
    (signed int)v5,
    v8,
    -2i64);
LABEL_10:
  v7 = 1;
LABEL_11:
  if ( v10.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *, char *, Scaleform::MemoryHeapVtbl *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v10.Data,
      Scaleform::Memory::pGlobalHeap->vfptr,
      v5);
  return v7;
}

