// File Line: 25
// RVA: 0x8E11E0
Scaleform::String *__fastcall Scaleform::GFx::GetUrlStrGfx(Scaleform::String *result, Scaleform::String *url)
{
  const char *v4; // rax
  unsigned __int64 v5; // rcx

  Scaleform::String::String(result);
  v4 = (const char *)(url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64);
  v5 = *(_QWORD *)v4 & 0x7FFFFFFFFFFFFFFFi64;
  if ( v5 > 4 && !Scaleform::String::CompareNoCase(&v4[v5 + 8], ".swf") )
  {
    Scaleform::String::Clear(result);
    Scaleform::String::AppendString(
      result,
      (const char *)((url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
      (*(_QWORD *)(url->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) - 4);
    Scaleform::String::AppendString(result, ".gfx", -1i64);
  }
  return result;
}

// File Line: 40
// RVA: 0x89BB90
void __fastcall Scaleform::GFx::MoviePreloadTask::MoviePreloadTask(
        Scaleform::GFx::MoviePreloadTask *this,
        Scaleform::GFx::MovieImpl *pmovieRoot,
        Scaleform::String *url,
        bool stripped,
        bool quietOpen)
{
  Scaleform::GFx::LoadStates *v9; // r14
  Scaleform::String *p_UrlStrGfx; // rbx
  Scaleform::GFx::LoadStates *v11; // r15
  Scaleform::GFx::Resource *pObject; // rbx
  Scaleform::GFx::ResourceLibBase **v13; // rax
  Scaleform::GFx::LoadStates *v14; // rax
  Scaleform::Render::RenderBuffer *v15; // rcx
  unsigned int v16; // eax
  const char *v17; // rax
  Scaleform::String *UrlStrGfx; // rax
  Scaleform::String result; // [rsp+78h] [rbp+10h] BYREF

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Task,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  this->ThisTaskId = Id_MovieDataLoad;
  v9 = 0i64;
  this->CurrentState = State_Stopped;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MoviePreloadTask::`vftable;
  this->pLoadStates.pObject = 0i64;
  Scaleform::String::String(&this->Level0Path);
  Scaleform::String::String(&this->Url, url);
  p_UrlStrGfx = &this->UrlStrGfx;
  Scaleform::String::String(&this->UrlStrGfx);
  this->pDefImpl.pObject = 0i64;
  this->Done = 0;
  v11 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        144i64,
                                        0i64);
  if ( v11 )
  {
    pObject = (Scaleform::GFx::Resource *)pmovieRoot->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v13 = (Scaleform::GFx::ResourceLibBase **)pmovieRoot->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr->GetStateBagImpl(&pmovieRoot->Scaleform::GFx::StateBag);
    Scaleform::GFx::LoadStates::LoadStates(v11, pObject, v13, 0i64);
    v9 = v14;
    p_UrlStrGfx = &this->UrlStrGfx;
  }
  v15 = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  this->pLoadStates.pObject = v9;
  v16 = pmovieRoot->pMainMovieDef.pObject->pBindData.pObject->LoadFlags & 0xFFFEFFFC | 0x10000;
  this->LoadFlags = v16;
  if ( quietOpen )
    this->LoadFlags = v16 | 0x200000;
  if ( !pmovieRoot->pMainMovie
    || (v17 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))pmovieRoot->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(pmovieRoot->pMainMovieDef.pObject),
        Scaleform::String::operator=(&this->Level0Path, v17),
        !Scaleform::GFx::URLBuilder::ExtractFilePath(&this->Level0Path)) )
  {
    Scaleform::String::Clear(&this->Level0Path);
  }
  if ( stripped )
  {
    UrlStrGfx = Scaleform::GFx::GetUrlStrGfx(&result, &this->Url);
    Scaleform::String::operator=(p_UrlStrGfx, UrlStrGfx);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 53
// RVA: 0x8C9DB0
void __fastcall Scaleform::GFx::MoviePreloadTask::Execute(Scaleform::GFx::MoviePreloadTask *this)
{
  Scaleform::GFx::MovieDefImpl *v2; // rbp
  Scaleform::GFx::MovieDefImpl *pObject; // rsi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::MovieDefImpl *v5; // rbp
  Scaleform::GFx::MovieDefImpl *v6; // rsi
  Scaleform::GFx::ResourceLibBase *v7; // rcx
  Scaleform::GFx::URLBuilder::LocationInfo loc; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::GFx::URLBuilder::LocationInfo v9; // [rsp+50h] [rbp-28h] BYREF

  if ( Scaleform::String::GetLength(&this->UrlStrGfx) )
  {
    loc.Use = File_LoadMovie;
    Scaleform::String::String(&loc.FileName, &this->UrlStrGfx);
    Scaleform::String::String(&loc.ParentPath, &this->Level0Path);
    v2 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(this->pLoadStates.pObject, &loc, this->LoadFlags, 0i64);
    pObject = this->pDefImpl.pObject;
    if ( pObject && !_InterlockedDecrement(&pObject->RefCount.Value) )
    {
      pLib = pObject->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pObject);
        pObject->pLib = 0i64;
      }
      pObject->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(pObject, 1u);
    }
    this->pDefImpl.pObject = v2;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((loc.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  if ( !this->pDefImpl.pObject )
  {
    v9.Use = File_LoadMovie;
    Scaleform::String::String(&v9.FileName, &this->Url);
    Scaleform::String::String(&v9.ParentPath, &this->Level0Path);
    v5 = Scaleform::GFx::LoaderImpl::CreateMovie_LoadState(this->pLoadStates.pObject, &v9, this->LoadFlags, 0i64);
    v6 = this->pDefImpl.pObject;
    if ( v6 && !_InterlockedDecrement(&v6->RefCount.Value) )
    {
      v7 = v6->pLib;
      if ( v7 )
      {
        v7->vfptr[1].__vecDelDtor(v7, (unsigned int)v6);
        v6->pLib = 0i64;
      }
      v6->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v6, 1u);
    }
    this->pDefImpl.pObject = v5;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.ParentPath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.FileName.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  this->Done = 1;
}

// File Line: 70
// RVA: 0x8E6F10
bool __fastcall Scaleform::GFx::MoviePreloadTask::IsDone(Scaleform::GFx::MoviePreloadTask *this)
{
  return this->Done == 1;
}

// File Line: 84
// RVA: 0x898DE0
void __fastcall Scaleform::GFx::LoadQueueEntryMT::LoadQueueEntryMT(
        Scaleform::GFx::LoadQueueEntryMT *this,
        Scaleform::GFx::LoadQueueEntry *pqueueEntry,
        Scaleform::GFx::MovieImpl *pmovieRoot)
{
  this->pMovieImpl = pmovieRoot;
  this->pQueueEntry = pqueueEntry;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable;
  this->pNext = 0i64;
  this->pPrev = 0i64;
}

// File Line: 88
// RVA: 0x8A5330
void __fastcall Scaleform::GFx::LoadQueueEntryMT::~LoadQueueEntryMT(Scaleform::GFx::LoadQueueEntryMT *this)
{
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // rcx

  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable;
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry )
    pQueueEntry->vfptr->__vecDelDtor(pQueueEntry, 1u);
}

// File Line: 102
// RVA: 0x899DD0
void __fastcall Scaleform::GFx::LoadVarsTask::LoadVarsTask(
        Scaleform::GFx::LoadVarsTask *this,
        Scaleform::GFx::Resource *pls,
        Scaleform::String *level0Path,
        Scaleform::String *url)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Task,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  this->ThisTaskId = Id_MovieDataLoad;
  this->CurrentState = State_Stopped;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadVarsTask::`vftable;
  if ( pls )
    Scaleform::Render::RenderBuffer::AddRef(pls);
  this->pLoadStates.pObject = (Scaleform::GFx::LoadStates *)pls;
  Scaleform::String::String(&this->Level0Path, level0Path);
  Scaleform::String::String(&this->Url, url);
  Scaleform::String::String(&this->Data);
  this->FileLen = 0;
  this->Done = 0;
  this->Succeeded = 0;
}

// File Line: 106
// RVA: 0x8C98E0
void __fastcall Scaleform::GFx::LoadVarsTask::Execute(Scaleform::GFx::LoadVarsTask *this)
{
  Scaleform::GFx::URLBuilder *pObject; // rcx
  __int64 v3; // rbx
  int v4; // ecx
  Scaleform::File *v5; // rbx
  unsigned __int64 v6; // r15
  Scaleform::GFx::LoadStates *v7; // r14
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v8; // rcx
  Scaleform::Log *GlobalLog; // rax
  int v10; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::String src; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::String v12; // [rsp+48h] [rbp-28h] BYREF
  __int64 v13[4]; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::String path; // [rsp+A0h] [rbp+30h] BYREF
  Scaleform::File *v15; // [rsp+A8h] [rbp+38h]
  __int64 *v16; // [rsp+B0h] [rbp+40h]

  v10 = 4;
  Scaleform::String::String(&src, &this->Url);
  Scaleform::String::String(&v12, &this->Level0Path);
  Scaleform::String::String(&path);
  pObject = this->pLoadStates.pObject->pBindStates.pObject->pURLBulider.pObject;
  if ( pObject )
  {
    ((void (__fastcall *)(Scaleform::GFx::URLBuilder *, Scaleform::String *, int *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
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
  v15 = 0i64;
  v16 = v13;
  memset(v13, 0, 24);
  if ( Scaleform::GFx::URLBuilder::IsProtocol(&path) )
    goto LABEL_19;
  v6 = path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v7 = this->pLoadStates.pObject;
  if ( v7->pBindStates.pObject->pFileOpener.pObject )
  {
    GlobalLog = v7->pLog.pObject->pLog.pObject;
    if ( !GlobalLog )
      GlobalLog = Scaleform::Log::GetGlobalLog();
    v5 = (Scaleform::File *)((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, unsigned __int64, Scaleform::Log *, __int64, int))v7->pBindStates.pObject->pFileOpener.pObject->vfptr[3].__vecDelDtor)(
                              v7->pBindStates.pObject->pFileOpener.pObject,
                              v6 + 12,
                              GlobalLog,
                              33i64,
                              438);
  }
  else
  {
    v8 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v7->pLog.pObject;
    if ( v8 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        v8 + 3,
        "Loader failed to open %s, FileOpener not installe",
        (const char *)(v6 + 12));
  }
  v15 = v5;
  if ( !v5 )
LABEL_19:
    this->Succeeded = 0;
  else
    this->Succeeded = Scaleform::GFx::MovieImpl::ReadTextData(&this->Data, v5, &this->FileLen, 0);
  this->Done = 1;
  v16 = v13;
  if ( v13[0] )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8), 0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 156
// RVA: 0x899010
void __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadQueueEntryMT_LoadVars(
        Scaleform::GFx::LoadQueueEntryMT_LoadVars *this,
        Scaleform::GFx::LoadQueueEntry *pqueueEntry,
        Scaleform::GFx::MovieImpl *pmovieRoot)
{
  Scaleform::GFx::LoadVarsTask *v5; // rbp
  Scaleform::String::DataDesc *v6; // rdi
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  Scaleform::GFx::LoaderImpl *pObject; // rbx
  Scaleform::GFx::StateBag *v9; // rax
  Scaleform::GFx::LoadStates *v10; // rax
  Scaleform::GFx::LoadStates *v11; // rbx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::MovieImpl *v13; // rcx
  const char *v14; // rax
  signed __int64 v15; // rdi
  unsigned int CharAt; // eax
  Scaleform::String *v17; // rax
  Scaleform::GFx::LoadVarsTask *v18; // rax
  Scaleform::GFx::LoadVarsTask *v19; // rax
  Scaleform::Render::RenderBuffer *v20; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *TaskManager; // rax
  Scaleform::String level0Path; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::String result; // [rsp+70h] [rbp+18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::TaskManager> v24; // [rsp+78h] [rbp+20h] BYREF

  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable;
  v5 = 0i64;
  this->pNext = 0i64;
  this->pPrev = 0i64;
  this->pMovieImpl = pmovieRoot;
  this->pQueueEntry = pqueueEntry;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT_LoadVars::`vftable;
  this->pTask.pObject = 0i64;
  this->pLoadStates.pObject = 0i64;
  v6 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        144i64,
                                        0i64);
  result.pData = v6;
  if ( v6 )
  {
    pMovieImpl = this->pMovieImpl;
    pObject = pMovieImpl->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v9 = (Scaleform::GFx::StateBag *)pMovieImpl->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr->GetStateBagImpl(&pMovieImpl->Scaleform::GFx::StateBag);
    Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v6, pObject, v9, 0i64);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  this->pLoadStates.pObject = v11;
  Scaleform::String::String(&level0Path);
  v13 = this->pMovieImpl;
  if ( v13->pMainMovie
    && (v14 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v13->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(v13->pMainMovieDef.pObject),
        Scaleform::String::operator=(&level0Path, v14),
        v15 = Scaleform::String::GetLength(&level0Path) - 1,
        v15 >= 0) )
  {
    while ( 1 )
    {
      CharAt = Scaleform::String::GetCharAt(&level0Path, v15);
      if ( CharAt == 47 || CharAt == 92 )
        break;
      if ( --v15 < 0 )
        goto LABEL_15;
    }
    v17 = Scaleform::String::Substring(&level0Path, &result, 0i64, v15 + 1);
    Scaleform::String::operator=(&level0Path, v17);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  else
  {
LABEL_15:
    Scaleform::String::Clear(&level0Path);
  }
  v18 = (Scaleform::GFx::LoadVarsTask *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                          Scaleform::Memory::pGlobalHeap,
                                          72i64);
  if ( v18 )
  {
    Scaleform::GFx::LoadVarsTask::LoadVarsTask(v18, this->pLoadStates.pObject, &level0Path, &pqueueEntry->URL);
    v5 = v19;
  }
  v20 = (Scaleform::Render::RenderBuffer *)this->pTask.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  this->pTask.pObject = v5;
  TaskManager = Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &v24);
  TaskManager->pObject->vfptr[1].__vecDelDtor(TaskManager->pObject, (unsigned int)this->pTask.pObject);
  if ( v24.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v24.pObject);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((level0Path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 165
// RVA: 0x8A53C0
void __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadVars::~LoadQueueEntryMT_LoadVars(
        Scaleform::GFx::LoadQueueEntryMT_LoadVars *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // rcx

  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT_LoadVars::`vftable;
  pObject = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (Scaleform::Render::RenderBuffer *)this->pTask.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable;
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry )
    pQueueEntry->vfptr->__vecDelDtor(pQueueEntry, 1u);
}

// File Line: 171
// RVA: 0x8E8600
__int64 __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadVars::LoadFinished(
        Scaleform::GFx::LoadQueueEntryMT_LoadVars *this)
{
  Scaleform::GFx::LoadVarsTask *pObject; // rbx
  char v3; // al
  char Succeeded; // r8
  __int64 FileLen; // r9
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // rdx
  unsigned __int8 v7; // bl
  unsigned __int64 v8; // rdx
  char v10; // [rsp+28h] [rbp-20h]
  Scaleform::String v11; // [rsp+50h] [rbp+8h] BYREF

  Scaleform::String::String(&v11);
  pObject = this->pTask.pObject;
  if ( pObject->Done == 1 )
  {
    Scaleform::String::operator=(&v11, &pObject->Data);
    FileLen = (unsigned int)pObject->FileLen;
    Succeeded = pObject->Succeeded;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    Succeeded = (char)v11.pData;
    FileLen = LODWORD(v11.HeapTypeBits);
  }
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry->Canceled )
  {
    if ( v3 )
      goto LABEL_10;
LABEL_8:
    v7 = 0;
    goto LABEL_11;
  }
  if ( !v3 )
    goto LABEL_8;
  v10 = Succeeded;
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::LoadQueueEntry *, Scaleform::GFx::LoadStates *, Scaleform::String *, _QWORD, char, __int64))this->pMovieImpl->pASMovieRoot.pObject->vfptr[36].__vecDelDtor)(
    this->pMovieImpl->pASMovieRoot.pObject,
    pQueueEntry,
    this->pLoadStates.pObject,
    &v11,
    (int)FileLen,
    v10,
    -2i64);
LABEL_10:
  v7 = 1;
LABEL_11:
  v8 = v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v11.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *, unsigned __int64, Scaleform::MemoryHeapVtbl *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v8,
      Scaleform::Memory::pGlobalHeap->vfptr,
      FileLen);
  return v7;
}

// File Line: 194
// RVA: 0x898B80
void __fastcall Scaleform::GFx::LoadBinaryTask::LoadBinaryTask(
        Scaleform::GFx::LoadBinaryTask *this,
        Scaleform::GFx::Resource *pls,
        Scaleform::String *level0Path,
        Scaleform::String *url)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::Task,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::Task::`vftable;
  this->ThisTaskId = Id_MovieDataLoad;
  this->CurrentState = State_Stopped;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadBinaryTask::`vftable;
  if ( pls )
    Scaleform::Render::RenderBuffer::AddRef(pls);
  this->pLoadStates.pObject = (Scaleform::GFx::LoadStates *)pls;
  Scaleform::String::String(&this->Level0Path, level0Path);
  Scaleform::String::String(&this->Url, url);
  this->Data.Data.Data = 0i64;
  this->Data.Data.Size = 0i64;
  this->Data.Data.Policy.Capacity = 0i64;
  this->FileLen = 0;
  this->Done = 0;
  this->Succeeded = 0;
}

// File Line: 198
// RVA: 0x8C9670
void __fastcall Scaleform::GFx::LoadBinaryTask::Execute(Scaleform::GFx::LoadBinaryTask *this)
{
  Scaleform::GFx::URLBuilder *pObject; // rcx
  __int64 v3; // rbx
  int v4; // ecx
  Scaleform::File *v5; // rbx
  unsigned __int64 v6; // r15
  Scaleform::GFx::LoadStates *v7; // r14
  Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *v8; // rcx
  Scaleform::Log *GlobalLog; // rax
  int v10; // [rsp+38h] [rbp-38h] BYREF
  Scaleform::String src; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::String v12; // [rsp+48h] [rbp-28h] BYREF
  __int64 v13[4]; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::String path; // [rsp+A0h] [rbp+30h] BYREF
  Scaleform::File *v15; // [rsp+A8h] [rbp+38h]
  __int64 *v16; // [rsp+B0h] [rbp+40h]

  v10 = 4;
  Scaleform::String::String(&src, &this->Url);
  Scaleform::String::String(&v12, &this->Level0Path);
  Scaleform::String::String(&path);
  pObject = this->pLoadStates.pObject->pBindStates.pObject->pURLBulider.pObject;
  if ( pObject )
  {
    ((void (__fastcall *)(Scaleform::GFx::URLBuilder *, Scaleform::String *, int *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
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
  v15 = 0i64;
  v16 = v13;
  memset(v13, 0, 24);
  if ( Scaleform::GFx::URLBuilder::IsProtocol(&path) )
    goto LABEL_19;
  v6 = path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  v7 = this->pLoadStates.pObject;
  if ( v7->pBindStates.pObject->pFileOpener.pObject )
  {
    GlobalLog = v7->pLog.pObject->pLog.pObject;
    if ( !GlobalLog )
      GlobalLog = Scaleform::Log::GetGlobalLog();
    v5 = (Scaleform::File *)((__int64 (__fastcall *)(Scaleform::GFx::FileOpener *, unsigned __int64, Scaleform::Log *, __int64, int))v7->pBindStates.pObject->pFileOpener.pObject->vfptr[3].__vecDelDtor)(
                              v7->pBindStates.pObject->pFileOpener.pObject,
                              v6 + 12,
                              GlobalLog,
                              33i64,
                              438);
  }
  else
  {
    v8 = (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)v7->pLog.pObject;
    if ( v8 )
      Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogError(
        v8 + 3,
        "Loader failed to open %s, FileOpener not installe",
        (const char *)(v6 + 12));
  }
  v15 = v5;
  if ( !v5 )
LABEL_19:
    this->Succeeded = 0;
  else
    this->Succeeded = Scaleform::GFx::MovieImpl::ReadBinaryData(&this->Data, v5, &this->FileLen);
  this->Done = 1;
  v16 = v13;
  if ( v13[0] )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v5 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v5);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v12.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8), 0xFFFFFFFF) == 1 )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 248
// RVA: 0x898E00
void __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadBinary::LoadQueueEntryMT_LoadBinary(
        Scaleform::GFx::LoadQueueEntryMT_LoadBinary *this,
        Scaleform::GFx::LoadQueueEntry *pqueueEntry,
        Scaleform::GFx::MovieImpl *pmovieRoot)
{
  Scaleform::GFx::LoadBinaryTask *v5; // rbp
  Scaleform::String::DataDesc *v6; // rdi
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  Scaleform::GFx::LoaderImpl *pObject; // rbx
  Scaleform::GFx::StateBag *v9; // rax
  Scaleform::GFx::LoadStates *v10; // rax
  Scaleform::GFx::LoadStates *v11; // rbx
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::MovieImpl *v13; // rcx
  const char *v14; // rax
  signed __int64 v15; // rdi
  unsigned int CharAt; // eax
  Scaleform::String *v17; // rax
  Scaleform::GFx::LoadBinaryTask *v18; // rax
  Scaleform::GFx::LoadBinaryTask *v19; // rax
  Scaleform::Render::RenderBuffer *v20; // rcx
  Scaleform::Ptr<Scaleform::GFx::TaskManager> *TaskManager; // rax
  Scaleform::String level0Path; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::String result; // [rsp+70h] [rbp+18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::TaskManager> v24; // [rsp+78h] [rbp+20h] BYREF

  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable;
  v5 = 0i64;
  this->pNext = 0i64;
  this->pPrev = 0i64;
  this->pMovieImpl = pmovieRoot;
  this->pQueueEntry = pqueueEntry;
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT_LoadBinary::`vftable;
  this->pTask.pObject = 0i64;
  this->pLoadStates.pObject = 0i64;
  v6 = (Scaleform::String::DataDesc *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(
                                        Scaleform::Memory::pGlobalHeap,
                                        144i64,
                                        0i64);
  result.pData = v6;
  if ( v6 )
  {
    pMovieImpl = this->pMovieImpl;
    pObject = pMovieImpl->pMainMovieDef.pObject->pLoaderImpl.pObject;
    v9 = (Scaleform::GFx::StateBag *)pMovieImpl->Scaleform::GFx::Movie::Scaleform::GFx::StateBag::vfptr->GetStateBagImpl(&pMovieImpl->Scaleform::GFx::StateBag);
    Scaleform::GFx::LoadStates::LoadStates((Scaleform::GFx::LoadStates *)v6, pObject, v9, 0i64);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  this->pLoadStates.pObject = v11;
  Scaleform::String::String(&level0Path);
  v13 = this->pMovieImpl;
  if ( v13->pMainMovie
    && (v14 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::MovieDefImpl *))v13->pMainMovieDef.pObject->vfptr[3].__vecDelDtor)(v13->pMainMovieDef.pObject),
        Scaleform::String::operator=(&level0Path, v14),
        v15 = Scaleform::String::GetLength(&level0Path) - 1,
        v15 >= 0) )
  {
    while ( 1 )
    {
      CharAt = Scaleform::String::GetCharAt(&level0Path, v15);
      if ( CharAt == 47 || CharAt == 92 )
        break;
      if ( --v15 < 0 )
        goto LABEL_15;
    }
    v17 = Scaleform::String::Substring(&level0Path, &result, 0i64, v15 + 1);
    Scaleform::String::operator=(&level0Path, v17);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((result.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  else
  {
LABEL_15:
    Scaleform::String::Clear(&level0Path);
  }
  v18 = (Scaleform::GFx::LoadBinaryTask *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                            Scaleform::Memory::pGlobalHeap,
                                            88i64);
  if ( v18 )
  {
    Scaleform::GFx::LoadBinaryTask::LoadBinaryTask(
      v18,
      (Scaleform::GFx::Resource *)this->pLoadStates.pObject,
      &level0Path,
      &pqueueEntry->URL);
    v5 = v19;
  }
  v20 = (Scaleform::Render::RenderBuffer *)this->pTask.pObject;
  if ( v20 )
    Scaleform::RefCountImpl::Release(v20);
  this->pTask.pObject = v5;
  TaskManager = Scaleform::GFx::StateBag::GetTaskManager(&this->pMovieImpl->Scaleform::GFx::StateBag, &v24);
  TaskManager->pObject->vfptr[1].__vecDelDtor(TaskManager->pObject, (unsigned int)this->pTask.pObject);
  if ( v24.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v24.pObject);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((level0Path.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 257
// RVA: 0x8A5350
void __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadBinary::~LoadQueueEntryMT_LoadBinary(
        Scaleform::GFx::LoadQueueEntryMT_LoadBinary *this)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // rcx

  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT_LoadBinary::`vftable;
  pObject = (Scaleform::Render::RenderBuffer *)this->pLoadStates.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v3 = (Scaleform::Render::RenderBuffer *)this->pTask.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  this->vfptr = (Scaleform::GFx::LoadQueueEntryMTVtbl *)&Scaleform::GFx::LoadQueueEntryMT::`vftable;
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry )
    pQueueEntry->vfptr->__vecDelDtor(pQueueEntry, 1u);
}

// File Line: 263
// RVA: 0x8E8510
__int64 __fastcall Scaleform::GFx::LoadQueueEntryMT_LoadBinary::LoadFinished(
        Scaleform::GFx::LoadQueueEntryMT_LoadBinary *this)
{
  Scaleform::GFx::LoadBinaryTask *pObject; // rbx
  char v3; // al
  unsigned __int8 Succeeded; // r8
  __int64 FileLen; // r9
  Scaleform::GFx::LoadQueueEntry *pQueueEntry; // rdx
  unsigned __int8 v7; // bl
  Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> v9; // [rsp+38h] [rbp-20h] BYREF

  memset(&v9, 0, sizeof(v9));
  pObject = this->pTask.pObject;
  if ( pObject->Done == 1 )
  {
    Scaleform::ArrayData<unsigned char,Scaleform::AllocatorGH<unsigned char,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &v9,
      pObject->Data.Data.Size);
    memmove(v9.Data, pObject->Data.Data.Data, pObject->Data.Data.Size);
    FileLen = (unsigned int)pObject->FileLen;
    Succeeded = pObject->Succeeded;
    v3 = 1;
  }
  else
  {
    v3 = 0;
    Succeeded = (unsigned __int8)&v9;
    FileLen = (unsigned int)&v9;
  }
  pQueueEntry = this->pQueueEntry;
  if ( pQueueEntry->Canceled )
  {
    if ( v3 )
      goto LABEL_10;
LABEL_8:
    v7 = 0;
    goto LABEL_11;
  }
  if ( !v3 )
    goto LABEL_8;
  ((void (__fastcall *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::LoadQueueEntry *, Scaleform::GFx::LoadStates *, Scaleform::ArrayData<char,Scaleform::AllocatorGH<char,2>,Scaleform::ArrayDefaultPolicy> *, _QWORD, unsigned __int8, __int64))this->pMovieImpl->pASMovieRoot.pObject->vfptr[37].__vecDelDtor)(
    this->pMovieImpl->pASMovieRoot.pObject,
    pQueueEntry,
    this->pLoadStates.pObject,
    &v9,
    (int)FileLen,
    Succeeded,
    -2i64);
LABEL_10:
  v7 = 1;
LABEL_11:
  if ( v9.Data )
    ((void (__fastcall *)(Scaleform::MemoryHeap *, char *, Scaleform::MemoryHeapVtbl *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v9.Data,
      Scaleform::Memory::pGlobalHeap->vfptr,
      FileLen);
  return v7;
}

