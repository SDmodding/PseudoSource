// File Line: 146
// RVA: 0x8B2F80
void __fastcall Scaleform::GFx::ImportData::AddSymbol(Scaleform::GFx::ImportData *this, const char *psymbolName, int characterId, unsigned int bindIndex)
{
  unsigned int v4; // esi
  int v5; // edi
  const char *v6; // rbx
  Scaleform::GFx::ImportData *v7; // r14
  signed __int64 v8; // rbx
  unsigned __int64 v9; // rdx
  Scaleform::String src; // [rsp+30h] [rbp-18h]
  int v11; // [rsp+38h] [rbp-10h]
  unsigned int v12; // [rsp+3Ch] [rbp-Ch]

  v4 = bindIndex;
  v5 = characterId;
  v6 = psymbolName;
  v7 = this;
  Scaleform::String::String(&src);
  Scaleform::String::operator=(&src, v6);
  v11 = v5;
  v12 = v4;
  Scaleform::ArrayDataBase<Scaleform::GFx::ImportData::Symbol,Scaleform::AllocatorLH<Scaleform::GFx::ImportData::Symbol,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    (Scaleform::ArrayDataBase<Scaleform::GFx::ImportData::Symbol,Scaleform::AllocatorLH<Scaleform::GFx::ImportData::Symbol,2>,Scaleform::ArrayDefaultPolicy> *)&v7->Imports.Data.Data,
    v7,
    v7->Imports.Data.Size + 1);
  v8 = (signed __int64)&v7->Imports.Data.Data[v7->Imports.Data.Size - 1];
  if ( v8 )
  {
    Scaleform::String::String((Scaleform::String *)v8, &src);
    *(_DWORD *)(v8 + 8) = v11;
    *(_DWORD *)(v8 + 12) = v12;
  }
  v9 = src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *, unsigned __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
      Scaleform::Memory::pGlobalHeap,
      v9);
}

// File Line: 302
// RVA: 0x899D50
void __fastcall Scaleform::GFx::LoadUpdateSync::LoadUpdateSync(Scaleform::GFx::LoadUpdateSync *this)
{
  Scaleform::GFx::LoadUpdateSync *v1; // rbx

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,264>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::LoadUpdateSync,264>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadUpdateSync::`vftable;
  Scaleform::Mutex::Mutex(&this->mMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&v1->WC);
  v1->LoadFinished = 0;
}

// File Line: 327
// RVA: 0x91A1D0
void __fastcall Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(Scaleform::GFx::LoadUpdateSync *this)
{
  Scaleform::GFx::LoadUpdateSync *v1; // rdi
  Scaleform::Mutex *v2; // rbx

  v1 = this;
  v2 = &this->mMutex;
  Scaleform::Mutex::DoLock(&this->mMutex);
  while ( !v1->LoadFinished )
    Scaleform::WaitCondition::Wait(&v1->WC, v2, 0xFFFFFFFF);
  Scaleform::Mutex::Unlock(v2);
}

// File Line: 676
// RVA: 0x880650
Scaleform::GFx::FontDataUseNode *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::AllocMovieDefClass<Scaleform::GFx::FontDataUseNode>(Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::GFx::DataAllocator *v1; // rcx
  unsigned __int64 v2; // r8
  Scaleform::GFx::FontDataUseNode *v3; // rdx
  Scaleform::GFx::FontDataUseNode *result; // rax
  Scaleform::GFx::FontDataUseNode *volatile v5; // rt1
  Scaleform::GFx::FontDataUseNode *volatile v6; // rcx

  v1 = &this->TagMemAllocator;
  v2 = v1->BytesLeft;
  if ( v2 < 0x20 )
  {
    v3 = (Scaleform::GFx::FontDataUseNode *)Scaleform::GFx::DataAllocator::OverflowAlloc(v1, 0x20ui64);
  }
  else
  {
    v3 = (Scaleform::GFx::FontDataUseNode *)v1->pCurrent;
    v1->pCurrent += 32;
    v1->BytesLeft = v2 - 32;
  }
  result = 0i64;
  if ( v3 )
  {
    v3->Id.Id = 0x40000;
    v3->pFontData.pObject = 0i64;
    v3->BindIndex = 0;
    v5 = v3->pNext.Value;
    v3->pNext.Value = 0i64;
    v6 = v3->pNext.Value;
    result = v3;
  }
  return result;
}

// File Line: 751
// RVA: 0x8A73E0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::ResourceLocker::~ResourceLocker(Scaleform::GFx::MovieDataDef::LoadTaskData::ResourceLocker *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v1; // rcx

  v1 = this->pLoadData;
  if ( v1 )
    LeaveCriticalSection(&v1->ResourceLock.cs);
}

// File Line: 757
// RVA: 0x7145D0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::SetExtMovieDef(Scaleform::GFx::MovieDataDef::LoadTaskData *this, Scaleform::GFx::MovieDef *m)
{
  Scaleform::GFx::MovieDef *v2; // rbx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v3; // rdi
  Scaleform::GFx::Resource *v4; // rcx

  v2 = m;
  v3 = this;
  if ( m )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)&m->vfptr);
  v4 = (Scaleform::GFx::Resource *)&v3->pExtMovieDef.pObject->vfptr;
  if ( v4 )
    Scaleform::GFx::Resource::Release(v4);
  v3->pExtMovieDef.pObject = v2;
}

// File Line: 828
// RVA: 0x8E1550
__int64 __fastcall Scaleform::GFx::MovieDataDef::GetVersion(Scaleform::GFx::MovieDataDef *this)
{
  return (unsigned int)this->pData.pObject->Header.Version;
}

// File Line: 829
// RVA: 0x8DAC00
__int64 __fastcall Scaleform::GFx::MovieDataDef::GetLoadingFrame(Scaleform::GFx::MovieDataDef *this)
{
  return this->pData.pObject->LoadingFrame;
}

// File Line: 830
// RVA: 0x8DDE30
__int64 __fastcall Scaleform::GFx::MovieDataDef::GetSWFFlags(Scaleform::GFx::MovieDataDef *this)
{
  return this->pData.pObject->Header.SWFFlags;
}

// File Line: 837
// RVA: 0x8D8D30
__int64 __fastcall Scaleform::GFx::MovieDataDef::GetFrameCount(Scaleform::GFx::MovieDataDef *this)
{
  return this->pData.pObject->Header.FrameCount;
}

// File Line: 855
// RVA: 0x8DAA70
bool __fastcall Scaleform::GFx::MovieDataDef::GetLabeledFrame(Scaleform::GFx::MovieDataDef *this, const char *label, unsigned int *frameNumber, bool translateNumbers)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetLabeledFrame(
           this->pData.pObject,
           label,
           frameNumber,
           translateNumbers);
}

// File Line: 859
// RVA: 0x8D8DE0
Scaleform::String *__fastcall Scaleform::GFx::MovieDataDef::GetFrameLabel(Scaleform::GFx::MovieDataDef *this, unsigned int frameNumber, unsigned int *exactFrameNumberForLabel)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabel(
           this->pData.pObject,
           frameNumber,
           exactFrameNumberForLabel);
}

// File Line: 864
// RVA: 0x8D8FB0
Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::MovieDataDef::GetFrameLabels(Scaleform::GFx::MovieDataDef *this, unsigned int frameNumber, Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *destArr)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabels(this->pData.pObject, frameNumber, destArr);
}

// File Line: 894
// RVA: 0x8DC1F0
Scaleform::GFx::TimelineDef::Frame *__fastcall Scaleform::GFx::MovieDataDef::GetPlaylist(Scaleform::GFx::MovieDataDef *this, Scaleform::GFx::TimelineDef::Frame *result, int frame)
{
  Scaleform::GFx::TimelineDef::Frame *v3; // rbx

  v3 = result;
  Scaleform::GFx::MovieDataDef::LoadTaskData::GetPlaylist(this->pData.pObject, result, frame);
  return v3;
}

// File Line: 897
// RVA: 0x8DA1C0
__int64 __fastcall Scaleform::GFx::MovieDataDef::GetInitActions(Scaleform::GFx::MovieDataDef *this, Scaleform::GFx::TimelineDef::Frame *pframe, int frame)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetInitActions(this->pData.pObject, pframe, frame);
}

// File Line: 913
// RVA: 0x8DDCE0
signed __int64 __fastcall Scaleform::GFx::MovieDataDef::GetResourceTypeCode(Scaleform::GFx::MovieDataDef *this)
{
  return 0x8000i64;
}

// File Line: 918
// RVA: 0x8DDC60
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::MovieDataDef::GetResourceHeap(Scaleform::GFx::MovieDataDef *this)
{
  return (Scaleform::MemoryHeap *)this->vfptr[1].GetStats;
}

// File Line: 957
// RVA: 0x89AE80
void __fastcall Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(Scaleform::GFx::MovieDefBindStates *this, Scaleform::GFx::StateBag *psharedState)
{
  Scaleform::GFx::MovieDefBindStates *v2; // rbx
  Scaleform::GFx::FileOpener *v3; // rdi
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::GFx::URLBuilder *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rcx
  __int64 v7; // rdi
  Scaleform::Render::RenderBuffer *v8; // rcx
  __int64 v9; // rdi
  Scaleform::Render::RenderBuffer *v10; // rcx
  __int64 v11; // rdi
  Scaleform::Render::RenderBuffer *v12; // rcx
  __int64 v13; // rdi
  Scaleform::Render::RenderBuffer *v14; // rcx
  __int64 v15; // rdi
  Scaleform::Render::RenderBuffer *v16; // rcx
  __int128 v17; // [rsp+28h] [rbp-40h]
  __int64 v18; // [rsp+38h] [rbp-30h]
  __int64 v19; // [rsp+40h] [rbp-28h]
  __int64 v20; // [rsp+48h] [rbp-20h]
  __int64 v21; // [rsp+50h] [rbp-18h]
  __int64 v22; // [rsp+58h] [rbp-10h]

  v2 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::MovieDefBindStates,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieDefBindStates::`vftable;
  this->pFileOpener.pObject = 0i64;
  this->pURLBulider.pObject = 0i64;
  this->pImageCreator.pObject = 0i64;
  this->pImageFileHandlerRegistry.pObject = 0i64;
  this->pImportVisitor.pObject = 0i64;
  this->pFontPackParams.pObject = 0i64;
  this->pFontCompactorParams.pObject = 0i64;
  this->pImagePackParams.pObject = 0i64;
  v17 = 0ui64;
  v18 = 0i64;
  v19 = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0i64;
  ((void (__fastcall *)(Scaleform::GFx::StateBag *, __int128 *, Scaleform::GFx::State::StateType *, signed __int64, signed __int64))psharedState->vfptr->GetStatesAddRef)(
    psharedState,
    &v17,
    `Scaleform::GFx::MovieDefBindStates::MovieDefBindStates::`2::stateQuery,
    7i64,
    -2i64);
  v3 = (Scaleform::GFx::FileOpener *)v17;
  v4 = (Scaleform::Render::RenderBuffer *)v2->pFileOpener.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v2->pFileOpener.pObject = v3;
  v5 = (Scaleform::GFx::URLBuilder *)*((_QWORD *)&v17 + 1);
  v6 = (Scaleform::Render::RenderBuffer *)v2->pURLBulider.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  v2->pURLBulider.pObject = v5;
  v7 = v18;
  v8 = (Scaleform::Render::RenderBuffer *)v2->pImageCreator.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v2->pImageCreator.pObject = (Scaleform::GFx::ImageCreator *)v7;
  v9 = v19;
  v10 = (Scaleform::Render::RenderBuffer *)v2->pImportVisitor.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  v2->pImportVisitor.pObject = (Scaleform::GFx::ImportVisitor *)v9;
  v11 = v20;
  v12 = (Scaleform::Render::RenderBuffer *)v2->pFontPackParams.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  v2->pFontPackParams.pObject = (Scaleform::GFx::FontPackParams *)v11;
  v13 = v21;
  v14 = (Scaleform::Render::RenderBuffer *)v2->pFontCompactorParams.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  v2->pFontCompactorParams.pObject = (Scaleform::GFx::FontCompactorParams *)v13;
  v15 = v22;
  v16 = (Scaleform::Render::RenderBuffer *)v2->pImagePackParams.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  v2->pImagePackParams.pObject = (Scaleform::GFx::ImagePackParamsBase *)v15;
}

// File Line: 982
// RVA: 0x89ACF0
void __fastcall Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(Scaleform::GFx::MovieDefBindStates *this, Scaleform::GFx::MovieDefBindStates *pother)
{
  Scaleform::GFx::MovieDefBindStates *v2; // rdi
  Scaleform::GFx::MovieDefBindStates *v3; // rbx
  Scaleform::GFx::FileOpener *v4; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::GFx::Resource *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::GFx::Resource *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx
  Scaleform::GFx::Resource *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::GFx::Resource *v12; // rcx
  Scaleform::Render::RenderBuffer *v13; // rcx
  Scaleform::GFx::Resource *v14; // rcx
  Scaleform::Render::RenderBuffer *v15; // rcx
  Scaleform::GFx::Resource *v16; // rcx
  Scaleform::Render::RenderBuffer *v17; // rcx

  v2 = pother;
  v3 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::MovieDefBindStates,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::MovieDefBindStates::`vftable;
  this->pFileOpener.pObject = 0i64;
  this->pURLBulider.pObject = 0i64;
  this->pImageCreator.pObject = 0i64;
  this->pImageFileHandlerRegistry.pObject = 0i64;
  this->pImportVisitor.pObject = 0i64;
  this->pFontPackParams.pObject = 0i64;
  this->pFontCompactorParams.pObject = 0i64;
  this->pImagePackParams.pObject = 0i64;
  v4 = pother->pFileOpener.pObject;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v4);
  v5 = (Scaleform::Render::RenderBuffer *)v3->pFileOpener.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v3->pFileOpener.pObject = v2->pFileOpener.pObject;
  v6 = (Scaleform::GFx::Resource *)v2->pURLBulider.pObject;
  if ( v6 )
    Scaleform::Render::RenderBuffer::AddRef(v6);
  v7 = (Scaleform::Render::RenderBuffer *)v3->pURLBulider.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  v3->pURLBulider.pObject = v2->pURLBulider.pObject;
  v8 = (Scaleform::GFx::Resource *)v2->pImageCreator.pObject;
  if ( v8 )
    Scaleform::Render::RenderBuffer::AddRef(v8);
  v9 = (Scaleform::Render::RenderBuffer *)v3->pImageCreator.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  v3->pImageCreator.pObject = v2->pImageCreator.pObject;
  v10 = (Scaleform::GFx::Resource *)v2->pImportVisitor.pObject;
  if ( v10 )
    Scaleform::Render::RenderBuffer::AddRef(v10);
  v11 = (Scaleform::Render::RenderBuffer *)v3->pImportVisitor.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  v3->pImportVisitor.pObject = v2->pImportVisitor.pObject;
  v12 = (Scaleform::GFx::Resource *)v2->pFontPackParams.pObject;
  if ( v12 )
    Scaleform::Render::RenderBuffer::AddRef(v12);
  v13 = (Scaleform::Render::RenderBuffer *)v3->pFontPackParams.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  v3->pFontPackParams.pObject = v2->pFontPackParams.pObject;
  v14 = (Scaleform::GFx::Resource *)v2->pFontCompactorParams.pObject;
  if ( v14 )
    Scaleform::Render::RenderBuffer::AddRef(v14);
  v15 = (Scaleform::Render::RenderBuffer *)v3->pFontCompactorParams.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  v3->pFontCompactorParams.pObject = v2->pFontCompactorParams.pObject;
  v16 = (Scaleform::GFx::Resource *)v2->pImagePackParams.pObject;
  if ( v16 )
    Scaleform::Render::RenderBuffer::AddRef(v16);
  v17 = (Scaleform::Render::RenderBuffer *)v3->pImagePackParams.pObject;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  v3->pImagePackParams.pObject = v2->pImagePackParams.pObject;
}

// File Line: 1186
// RVA: 0x78DB00
void __fastcall Scaleform::GFx::MovieDefImpl::ReleaseNotifier::~ReleaseNotifier(Scaleform::GFx::MovieDefImpl::ReleaseNotifier *this)
{
  this->vfptr = (Scaleform::GFx::MovieDefImpl::ReleaseNotifierVtbl *)&Scaleform::GFx::MovieDefImpl::ReleaseNotifier::`vftable;
}

// File Line: 1406
// RVA: 0x8DABE0
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::MovieDefImpl::GetLoadDataHeap(Scaleform::GFx::MovieDefImpl *this)
{
  return this->pBindData.pObject->pDataDef.pObject->pData.pObject->pHeap;
}

// File Line: 1407
// RVA: 0x8D4DC0
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::MovieDefImpl::GetBindDataHeap(Scaleform::GFx::MovieDefImpl *this)
{
  return this->pBindData.pObject->pHeap;
}

// File Line: 1408
// RVA: 0x8D9D30
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::MovieDefImpl::GetImageHeap(Scaleform::GFx::MovieDefImpl *this)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetImageHeap(this->pBindData.pObject->pDataDef.pObject->pData.pObject);
}

// File Line: 1409
// RVA: 0x8DB4D0
Scaleform::GFx::MovieDataDef *__fastcall Scaleform::GFx::MovieDefImpl::GetMovieDataResource(Scaleform::GFx::MovieDefImpl *this)
{
  return this->pBindData.pObject->pDataDef.pObject;
}

// File Line: 1429
// RVA: 0x8D8D40
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetFrameCount(Scaleform::GFx::MovieDefImpl *this)
{
  return ((__int64 (*)(void))this->pBindData.pObject->pDataDef.pObject->vfptr[2].GetResourceTypeCode)();
}

// File Line: 1430
// RVA: 0x8D9120
float __fastcall Scaleform::GFx::MovieDefImpl::GetFrameRate(Scaleform::GFx::MovieDefImpl *this)
{
  return this->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FPS;
}

// File Line: 1431
// RVA: 0x8D9150
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::MovieDefImpl::GetFrameRect(Scaleform::GFx::MovieDefImpl *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v2; // rax
  float v3; // xmm1_4
  float v4; // xmm0_4
  float v5; // xmm0_4
  Scaleform::Render::Rect<float> *v6; // rax

  v2 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v3 = v2->Header.FrameRect.x2 * 0.050000001;
  result->x1 = v2->Header.FrameRect.x1 * 0.050000001;
  v4 = v2->Header.FrameRect.y1;
  result->x2 = v3;
  result->y1 = v4 * 0.050000001;
  v5 = v2->Header.FrameRect.y2;
  v6 = result;
  result->y2 = v5 * 0.050000001;
  return v6;
}

// File Line: 1432
// RVA: 0x8E19D0
float __fastcall Scaleform::GFx::MovieDefImpl::GetWidth(Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v1; // rax
  __m128 v2; // xmm1
  signed int v3; // ecx
  float result; // xmm0_4

  v1 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v2 = (__m128)LODWORD(v1->Header.FrameRect.x2);
  v2.m128_f32[0] = (float)(v2.m128_f32[0] - v1->Header.FrameRect.x1) * 0.050000001;
  v3 = (signed int)v2.m128_f32[0];
  if ( (signed int)v2.m128_f32[0] == 0x80000000 || (float)v3 == v2.m128_f32[0] )
    result = v2.m128_f32[0];
  else
    result = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v2, v2)) & 1 ^ 1) + v3);
  return result;
}

// File Line: 1433
// RVA: 0x8D9AB0
float __fastcall Scaleform::GFx::MovieDefImpl::GetHeight(Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v1; // rax
  __m128 v2; // xmm1
  signed int v3; // ecx
  float result; // xmm0_4

  v1 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v2 = (__m128)LODWORD(v1->Header.FrameRect.y2);
  v2.m128_f32[0] = (float)(v2.m128_f32[0] - v1->Header.FrameRect.y1) * 0.050000001;
  v3 = (signed int)v2.m128_f32[0];
  if ( (signed int)v2.m128_f32[0] == 0x80000000 || (float)v3 == v2.m128_f32[0] )
    result = v2.m128_f32[0];
  else
    result = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v2, v2)) & 1 ^ 1) + v3);
  return result;
}

// File Line: 1434
// RVA: 0x8E1560
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetVersion(Scaleform::GFx::MovieDefImpl *this)
{
  return ((__int64 (*)(void))this->pBindData.pObject->pDataDef.pObject->vfptr[2].GetKey)();
}

// File Line: 1435
// RVA: 0x8DDE40
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetSWFFlags(Scaleform::GFx::MovieDefImpl *this)
{
  return ((__int64 (*)(void))this->pBindData.pObject->pDataDef.pObject->vfptr[4].GetKey)();
}

// File Line: 1436
// RVA: 0x8D7BB0
const char *__fastcall Scaleform::GFx::MovieDefImpl::GetFileURL(Scaleform::GFx::MovieDefImpl *this)
{
  return (const char *)((this->pBindData.pObject->pDataDef.pObject->pData.pObject->FileURL.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                      + 12);
}

// File Line: 1439
// RVA: 0x8DAC10
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetLoadingFrame(Scaleform::GFx::MovieDefImpl *this)
{
  return this->pBindData.pObject->BindingFrame;
}

// File Line: 1447
// RVA: 0x91A170
void __fastcall Scaleform::GFx::MovieDefImpl::WaitForLoadFinish(Scaleform::GFx::MovieDefImpl *this, bool cancel)
{
  Scaleform::GFx::MovieDefImpl *v2; // rbx
  Scaleform::GFx::MovieDataDef *v3; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v4; // rax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rcx

  v2 = this;
  v3 = this->pBindData.pObject->pDataDef.pObject;
  if ( cancel )
  {
    v4 = v3->pData.pObject;
    if ( v4->LoadState <= 1 )
      v4->LoadingCanceled = 1;
  }
  v5 = v3->pData.pObject;
  if ( v5->LoadState <= 1 )
    Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(v5->pFrameUpdate.pObject);
  Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(v2->pBindData.pObject->pBindUpdate.pObject);
}

// File Line: 1456
// RVA: 0x91A150
void __fastcall Scaleform::GFx::MovieDefImpl::WaitForFrame(Scaleform::GFx::MovieDefImpl *this, unsigned int frame)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData::WaitForFrame(
    this->pBindData.pObject->pDataDef.pObject->pData.pObject,
    frame);
}

// File Line: 1459
// RVA: 0x8D7A20
Scaleform::GFx::ExporterInfoImpl *__fastcall Scaleform::GFx::MovieDefImpl::GetExporterInfo(Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::ExporterInfoImpl *result; // rax

  result = &this->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.mExporterInfo;
  if ( result->SI.Format == File_Unopened )
    result = 0i64;
  return result;
}

// File Line: 1469
// RVA: 0x8DAFD0
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetMetadata(Scaleform::GFx::MovieDefImpl *this, char *pbuff, unsigned int buffSize)
{
  char *v3; // r9
  Scaleform::GFx::MovieDataDef::LoadTaskData *v4; // rax
  char *v6; // rdx
  unsigned int v7; // ebx

  v3 = pbuff;
  v4 = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  if ( !pbuff )
    return v4->MetadataSize;
  v6 = v4->pMetadata;
  v7 = v4->MetadataSize;
  if ( buffSize < v7 )
    v7 = buffSize;
  if ( v6 )
    memmove(v3, v6, v7);
  return v7;
}

// File Line: 1470
// RVA: 0x8D7A60
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetFileAttributesA(Scaleform::GFx::MovieDefImpl *this)
{
  return this->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes;
}

// File Line: 1545
// RVA: 0x8DA920
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::MovieDefImpl::GetKey(Scaleform::GFx::MovieDefImpl *this, Scaleform::GFx::ResourceKey *result)
{
  Scaleform::GFx::ResourceKey *v2; // rbx

  v2 = result;
  Scaleform::GFx::MovieDefImpl::CreateMovieKey(
    result,
    this->pBindData.pObject->pDataDef.pObject,
    this->pBindStates.pObject);
  return v2;
}

// File Line: 1546
// RVA: 0x8DDCF0
signed __int64 __fastcall Scaleform::GFx::MovieDefImpl::GetResourceTypeCode(Scaleform::GFx::MovieDefImpl *this)
{
  return 768i64;
}

// File Line: 1633
// RVA: 0x8C9B40
void __fastcall Scaleform::GFx::MovieBindProcess::Execute(Scaleform::GFx::MovieBindProcess *this)
{
  Scaleform::GFx::MovieBindProcess *v1; // rbx

  v1 = this;
  while ( (unsigned int)Scaleform::GFx::MovieBindProcess::BindNextFrame(v1) == 1 )
    ;
}

// File Line: 1640
// RVA: 0x8EC220
void __fastcall Scaleform::GFx::MovieBindProcess::OnAbandon(Scaleform::GFx::MovieBindProcess *this, bool started)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *v2; // rcx

  v2 = this->pBindData.pObject;
  if ( v2 )
  {
    if ( started )
      v2->BindingCanceled = 1;
    else
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(v2, 3u);
  }
}

// File Line: 1685
// RVA: 0x8A4500
void __fastcall Scaleform::GFx::ExecuteTag::~ExecuteTag(Scaleform::GFx::ExecuteTag *this)
{
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable;
}

// File Line: 1773
// RVA: 0x896FE0
void __fastcall Scaleform::GFx::GFxPlaceObjectUnpacked::GFxPlaceObjectUnpacked(Scaleform::GFx::GFxPlaceObjectUnpacked *this)
{
  Scaleform::GFx::CharPosInfo *v1; // rbx

  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable;
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::GFxPlaceObjectBase::`vftable;
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::GFxPlaceObjectUnpacked::`vftable;
  v1 = &this->Pos;
  Scaleform::Render::Cxform::Cxform(&this->Pos.ColorTransform);
  *(_QWORD *)&v1->Matrix_1.M[0][0] = 1065353216i64;
  *(_QWORD *)&v1->Matrix_1.M[0][2] = 0i64;
  v1->Matrix_1.M[1][0] = 0.0;
  *(_QWORD *)&v1->Matrix_1.M[1][1] = 1065353216i64;
  v1->Matrix_1.M[1][3] = 0.0;
  v1->pFilters.pObject = 0i64;
  v1->CharacterId.Id = 0x40000;
  *(_DWORD *)&v1->ClipDepth = 0;
  *(_QWORD *)&v1->Ratio = 0i64;
  *(_WORD *)&v1->BlendMode = 256;
  v1->ClassName = 0i64;
}

// File Line: 1778
// RVA: 0x915660
void __fastcall Scaleform::GFx::GFxPlaceObjectUnpacked::Unpack(Scaleform::GFx::GFxPlaceObjectUnpacked *this, Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  data->Name = 0i64;
  data->pEventHandlers = 0i64;
  data->PlaceType = 0;
  Scaleform::GFx::CharPosInfo::operator=(&data->Pos, &this->Pos);
}

// File Line: 1785
// RVA: 0x8D8100
Scaleform::GFx::CharPosInfoFlags *__fastcall Scaleform::GFx::GFxPlaceObjectUnpacked::GetFlags(Scaleform::GFx::GFxPlaceObjectUnpacked *this, Scaleform::GFx::CharPosInfoFlags *result)
{
  result->Flags = (unsigned __int16)this->Pos.Flags;
  return result;
}

