// File Line: 146
// RVA: 0x8B2F80
void __fastcall Scaleform::GFx::ImportData::AddSymbol(
        Scaleform::GFx::ImportData *this,
        const char *psymbolName,
        int characterId,
        unsigned int bindIndex)
{
  Scaleform::GFx::ImportData::Symbol *v8; // rbx
  Scaleform::String src; // [rsp+30h] [rbp-18h] BYREF
  int v10; // [rsp+38h] [rbp-10h]
  unsigned int v11; // [rsp+3Ch] [rbp-Ch]

  Scaleform::String::String(&src);
  Scaleform::String::operator=(&src, psymbolName);
  v10 = characterId;
  v11 = bindIndex;
  Scaleform::ArrayDataBase<Scaleform::GFx::ImportData::Symbol,Scaleform::AllocatorLH<Scaleform::GFx::ImportData::Symbol,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->Imports.Data,
    this,
    this->Imports.Data.Size + 1);
  v8 = &this->Imports.Data.Data[this->Imports.Data.Size - 1];
  if ( v8 )
  {
    Scaleform::String::String(&v8->SymbolName, &src);
    v8->CharacterId = v10;
    v8->BindIndex = v11;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)((src.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
}

// File Line: 302
// RVA: 0x899D50
void __fastcall Scaleform::GFx::LoadUpdateSync::LoadUpdateSync(Scaleform::GFx::LoadUpdateSync *this)
{
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,264>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::LoadUpdateSync,264>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::LoadUpdateSync::`vftable;
  Scaleform::Mutex::Mutex(&this->mMutex, 1, 0);
  Scaleform::WaitCondition::WaitCondition(&this->WC);
  this->LoadFinished = 0;
}

// File Line: 327
// RVA: 0x91A1D0
void __fastcall Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(Scaleform::GFx::LoadUpdateSync *this)
{
  Scaleform::Mutex *p_mMutex; // rbx

  p_mMutex = &this->mMutex;
  Scaleform::Mutex::DoLock(&this->mMutex);
  while ( !this->LoadFinished )
    Scaleform::WaitCondition::Wait(&this->WC, p_mMutex, 0xFFFFFFFF);
  Scaleform::Mutex::Unlock(p_mMutex);
}

// File Line: 676
// RVA: 0x880650
Scaleform::GFx::FontDataUseNode *__fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::AllocMovieDefClass<Scaleform::GFx::FontDataUseNode>(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::GFx::DataAllocator *p_TagMemAllocator; // rcx
  unsigned __int64 BytesLeft; // r8
  char *pCurrent; // rdx
  Scaleform::GFx::FontDataUseNode *result; // rax

  p_TagMemAllocator = &this->TagMemAllocator;
  BytesLeft = p_TagMemAllocator->BytesLeft;
  if ( BytesLeft < 0x20 )
  {
    pCurrent = (char *)Scaleform::GFx::DataAllocator::OverflowAlloc(p_TagMemAllocator, 0x20ui64);
  }
  else
  {
    pCurrent = p_TagMemAllocator->pCurrent;
    p_TagMemAllocator->pCurrent += 32;
    p_TagMemAllocator->BytesLeft = BytesLeft - 32;
  }
  result = 0i64;
  if ( pCurrent )
  {
    *(_DWORD *)pCurrent = 0x40000;
    *((_QWORD *)pCurrent + 1) = 0i64;
    *((_DWORD *)pCurrent + 4) = 0;
    *((_QWORD *)pCurrent + 3) = 0i64;
    return (Scaleform::GFx::FontDataUseNode *)pCurrent;
  }
  return result;
}

// File Line: 751
// RVA: 0x8A73E0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::ResourceLocker::~ResourceLocker(
        Scaleform::GFx::MovieDataDef::LoadTaskData::ResourceLocker *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pLoadData; // rcx

  pLoadData = this->pLoadData;
  if ( pLoadData )
    LeaveCriticalSection(&pLoadData->ResourceLock.cs);
}

// File Line: 757
// RVA: 0x7145D0
void __fastcall Scaleform::GFx::MovieDataDef::LoadTaskData::SetExtMovieDef(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::MovieDef *m)
{
  Scaleform::GFx::MovieDef *pObject; // rcx

  if ( m )
    Scaleform::Render::RenderBuffer::AddRef(m);
  pObject = this->pExtMovieDef.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  this->pExtMovieDef.pObject = m;
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
bool __fastcall Scaleform::GFx::MovieDataDef::GetLabeledFrame(
        Scaleform::GFx::MovieDataDef *this,
        const char *label,
        unsigned int *frameNumber,
        bool translateNumbers)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetLabeledFrame(
           this->pData.pObject,
           label,
           frameNumber,
           translateNumbers);
}

// File Line: 859
// RVA: 0x8D8DE0
Scaleform::String *__fastcall Scaleform::GFx::MovieDataDef::GetFrameLabel(
        Scaleform::GFx::MovieDataDef *this,
        unsigned int frameNumber,
        unsigned int *exactFrameNumberForLabel)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabel(
           this->pData.pObject,
           frameNumber,
           exactFrameNumberForLabel);
}

// File Line: 864
// RVA: 0x8D8FB0
Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *__fastcall Scaleform::GFx::MovieDataDef::GetFrameLabels(
        Scaleform::GFx::MovieDataDef *this,
        unsigned int frameNumber,
        Scaleform::Array<Scaleform::String,2,Scaleform::ArrayDefaultPolicy> *destArr)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetFrameLabels(this->pData.pObject, frameNumber, destArr);
}

// File Line: 894
// RVA: 0x8DC1F0
Scaleform::GFx::TimelineDef::Frame *__fastcall Scaleform::GFx::MovieDataDef::GetPlaylist(
        Scaleform::GFx::MovieDataDef *this,
        Scaleform::GFx::TimelineDef::Frame *result,
        int frame)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData::GetPlaylist(this->pData.pObject, result, frame);
  return result;
}

// File Line: 897
// RVA: 0x8DA1C0
__int64 __fastcall Scaleform::GFx::MovieDataDef::GetInitActions(
        Scaleform::GFx::MovieDataDef *this,
        Scaleform::GFx::TimelineDef::Frame *pframe,
        int frame)
{
  return Scaleform::GFx::MovieDataDef::LoadTaskData::GetInitActions(this->pData.pObject, pframe, frame);
}

// File Line: 913
// RVA: 0x8DDCE0
__int64 __fastcall Scaleform::GFx::MovieDataDef::GetResourceTypeCode(Scaleform::GFx::MovieDataDef *this)
{
  return 0x8000i64;
}

// File Line: 918
// RVA: 0x8DDC60
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::MovieDataDef::GetResourceHeap(Scaleform::GFx::MovieDataDef *this)
{
  return (Scaleform::MemoryHeap *)this->Scaleform::GFx::ResourceReport::vfptr[1].GetStats;
}

// File Line: 957
// RVA: 0x89AE80
void __fastcall Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(
        Scaleform::GFx::MovieDefBindStates *this,
        Scaleform::GFx::StateBag *psharedState)
{
  Scaleform::GFx::FileOpener *v3; // rdi
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::GFx::URLBuilder *v5; // rdi
  Scaleform::Render::RenderBuffer *v6; // rcx
  Scaleform::GFx::ImageCreator *v7; // rdi
  Scaleform::Render::RenderBuffer *v8; // rcx
  Scaleform::GFx::ImportVisitor *v9; // rdi
  Scaleform::Render::RenderBuffer *v10; // rcx
  Scaleform::GFx::FontPackParams *v11; // rdi
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::FontCompactorParams *v13; // rdi
  Scaleform::Render::RenderBuffer *v14; // rcx
  Scaleform::GFx::ImagePackParamsBase *v15; // rdi
  Scaleform::Render::RenderBuffer *v16; // rcx
  Scaleform::GFx::FileOpener *v17; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::URLBuilder *v18; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::ImageCreator *v19; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::ImportVisitor *v20; // [rsp+40h] [rbp-28h]
  Scaleform::GFx::FontPackParams *v21; // [rsp+48h] [rbp-20h]
  Scaleform::GFx::FontCompactorParams *v22; // [rsp+50h] [rbp-18h]
  Scaleform::GFx::ImagePackParamsBase *v23; // [rsp+58h] [rbp-10h]

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
  v17 = 0i64;
  v18 = 0i64;
  v19 = 0i64;
  v20 = 0i64;
  v21 = 0i64;
  v22 = 0i64;
  v23 = 0i64;
  ((void (__fastcall *)(Scaleform::GFx::StateBag *, Scaleform::GFx::FileOpener **, Scaleform::GFx::State::StateType *, __int64, __int64))psharedState->vfptr->GetStatesAddRef)(
    psharedState,
    &v17,
    `Scaleform::GFx::MovieDefBindStates::MovieDefBindStates::`2::stateQuery,
    7i64,
    -2i64);
  v3 = v17;
  pObject = (Scaleform::Render::RenderBuffer *)this->pFileOpener.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFileOpener.pObject = v3;
  v5 = v18;
  v6 = (Scaleform::Render::RenderBuffer *)this->pURLBulider.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->pURLBulider.pObject = v5;
  v7 = v19;
  v8 = (Scaleform::Render::RenderBuffer *)this->pImageCreator.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  this->pImageCreator.pObject = v7;
  v9 = v20;
  v10 = (Scaleform::Render::RenderBuffer *)this->pImportVisitor.pObject;
  if ( v10 )
    Scaleform::RefCountImpl::Release(v10);
  this->pImportVisitor.pObject = v9;
  v11 = v21;
  v12 = (Scaleform::Render::RenderBuffer *)this->pFontPackParams.pObject;
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  this->pFontPackParams.pObject = v11;
  v13 = v22;
  v14 = (Scaleform::Render::RenderBuffer *)this->pFontCompactorParams.pObject;
  if ( v14 )
    Scaleform::RefCountImpl::Release(v14);
  this->pFontCompactorParams.pObject = v13;
  v15 = v23;
  v16 = (Scaleform::Render::RenderBuffer *)this->pImagePackParams.pObject;
  if ( v16 )
    Scaleform::RefCountImpl::Release(v16);
  this->pImagePackParams.pObject = v15;
}

// File Line: 982
// RVA: 0x89ACF0
void __fastcall Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(
        Scaleform::GFx::MovieDefBindStates *this,
        Scaleform::GFx::MovieDefBindStates *pother)
{
  Scaleform::GFx::FileOpener *pObject; // rcx
  Scaleform::Render::RenderBuffer *v5; // rcx
  Scaleform::GFx::URLBuilder *v6; // rcx
  Scaleform::Render::RenderBuffer *v7; // rcx
  Scaleform::GFx::ImageCreator *v8; // rcx
  Scaleform::Render::RenderBuffer *v9; // rcx
  Scaleform::GFx::Resource *v10; // rcx
  Scaleform::Render::RenderBuffer *v11; // rcx
  Scaleform::GFx::Resource *v12; // rcx
  Scaleform::Render::RenderBuffer *v13; // rcx
  Scaleform::GFx::Resource *v14; // rcx
  Scaleform::Render::RenderBuffer *v15; // rcx
  Scaleform::GFx::Resource *v16; // rcx
  Scaleform::Render::RenderBuffer *v17; // rcx

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
  pObject = pother->pFileOpener.pObject;
  if ( pObject )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject);
  v5 = (Scaleform::Render::RenderBuffer *)this->pFileOpener.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  this->pFileOpener.pObject = pother->pFileOpener.pObject;
  v6 = pother->pURLBulider.pObject;
  if ( v6 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v6);
  v7 = (Scaleform::Render::RenderBuffer *)this->pURLBulider.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  this->pURLBulider.pObject = pother->pURLBulider.pObject;
  v8 = pother->pImageCreator.pObject;
  if ( v8 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v8);
  v9 = (Scaleform::Render::RenderBuffer *)this->pImageCreator.pObject;
  if ( v9 )
    Scaleform::RefCountImpl::Release(v9);
  this->pImageCreator.pObject = pother->pImageCreator.pObject;
  v10 = (Scaleform::GFx::Resource *)pother->pImportVisitor.pObject;
  if ( v10 )
    Scaleform::Render::RenderBuffer::AddRef(v10);
  v11 = (Scaleform::Render::RenderBuffer *)this->pImportVisitor.pObject;
  if ( v11 )
    Scaleform::RefCountImpl::Release(v11);
  this->pImportVisitor.pObject = pother->pImportVisitor.pObject;
  v12 = (Scaleform::GFx::Resource *)pother->pFontPackParams.pObject;
  if ( v12 )
    Scaleform::Render::RenderBuffer::AddRef(v12);
  v13 = (Scaleform::Render::RenderBuffer *)this->pFontPackParams.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  this->pFontPackParams.pObject = pother->pFontPackParams.pObject;
  v14 = (Scaleform::GFx::Resource *)pother->pFontCompactorParams.pObject;
  if ( v14 )
    Scaleform::Render::RenderBuffer::AddRef(v14);
  v15 = (Scaleform::Render::RenderBuffer *)this->pFontCompactorParams.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  this->pFontCompactorParams.pObject = pother->pFontCompactorParams.pObject;
  v16 = (Scaleform::GFx::Resource *)pother->pImagePackParams.pObject;
  if ( v16 )
    Scaleform::Render::RenderBuffer::AddRef(v16);
  v17 = (Scaleform::Render::RenderBuffer *)this->pImagePackParams.pObject;
  if ( v17 )
    Scaleform::RefCountImpl::Release(v17);
  this->pImagePackParams.pObject = pother->pImagePackParams.pObject;
}

// File Line: 1186
// RVA: 0x78DB00
void __fastcall Scaleform::GFx::MovieDefImpl::ReleaseNotifier::~ReleaseNotifier(
        Scaleform::GFx::MovieDefImpl::ReleaseNotifier *this)
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
Scaleform::GFx::MovieDataDef *__fastcall Scaleform::GFx::MovieDefImpl::GetMovieDataResource(
        Scaleform::GFx::MovieDefImpl *this)
{
  return this->pBindData.pObject->pDataDef.pObject;
}

// File Line: 1429
// RVA: 0x8D8D40
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetFrameCount(Scaleform::GFx::MovieDefImpl *this)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::MovieDataDef *))this->pBindData.pObject->pDataDef.pObject->vfptr[2].GetResourceTypeCode)(this->pBindData.pObject->pDataDef.pObject);
}

// File Line: 1430
// RVA: 0x8D9120
float __fastcall Scaleform::GFx::MovieDefImpl::GetFrameRate(Scaleform::GFx::MovieDefImpl *this)
{
  return this->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.FPS;
}

// File Line: 1431
// RVA: 0x8D9150
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::MovieDefImpl::GetFrameRect(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rax
  float v3; // xmm1_4
  float y1; // xmm0_4
  float y2; // xmm0_4
  Scaleform::Render::Rect<float> *v6; // rax

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  v3 = pObject->Header.FrameRect.x2 * 0.050000001;
  result->x1 = pObject->Header.FrameRect.x1 * 0.050000001;
  y1 = pObject->Header.FrameRect.y1;
  result->x2 = v3;
  result->y1 = y1 * 0.050000001;
  y2 = pObject->Header.FrameRect.y2;
  v6 = result;
  result->y2 = y2 * 0.050000001;
  return v6;
}

// File Line: 1432
// RVA: 0x8E19D0
float __fastcall Scaleform::GFx::MovieDefImpl::GetWidth(Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rax
  __m128 x2_low; // xmm1
  int v3; // ecx

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  x2_low = (__m128)LODWORD(pObject->Header.FrameRect.x2);
  x2_low.m128_f32[0] = (float)(x2_low.m128_f32[0] - pObject->Header.FrameRect.x1) * 0.050000001;
  v3 = (int)x2_low.m128_f32[0];
  if ( (int)x2_low.m128_f32[0] == 0x80000000 || (float)v3 == x2_low.m128_f32[0] )
    return x2_low.m128_f32[0];
  else
    return (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(x2_low, x2_low)) & 1) + v3);
}

// File Line: 1433
// RVA: 0x8D9AB0
float __fastcall Scaleform::GFx::MovieDefImpl::GetHeight(Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rax
  __m128 y2_low; // xmm1
  int v3; // ecx

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  y2_low = (__m128)LODWORD(pObject->Header.FrameRect.y2);
  y2_low.m128_f32[0] = (float)(y2_low.m128_f32[0] - pObject->Header.FrameRect.y1) * 0.050000001;
  v3 = (int)y2_low.m128_f32[0];
  if ( (int)y2_low.m128_f32[0] == 0x80000000 || (float)v3 == y2_low.m128_f32[0] )
    return y2_low.m128_f32[0];
  else
    return (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(y2_low, y2_low)) & 1) + v3);
}

// File Line: 1434
// RVA: 0x8E1560
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetVersion(Scaleform::GFx::MovieDefImpl *this)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::MovieDataDef *))this->pBindData.pObject->pDataDef.pObject->vfptr[2].GetKey)(this->pBindData.pObject->pDataDef.pObject);
}

// File Line: 1435
// RVA: 0x8DDE40
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetSWFFlags(Scaleform::GFx::MovieDefImpl *this)
{
  return ((__int64 (__fastcall *)(Scaleform::GFx::MovieDataDef *))this->pBindData.pObject->pDataDef.pObject->vfptr[4].GetKey)(this->pBindData.pObject->pDataDef.pObject);
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
  Scaleform::GFx::MovieDataDef *pObject; // rcx
  Scaleform::GFx::MovieDataDef::LoadTaskData *v4; // rax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // rcx

  pObject = this->pBindData.pObject->pDataDef.pObject;
  if ( cancel )
  {
    v4 = pObject->pData.pObject;
    if ( v4->LoadState <= LS_LoadingFrames )
      v4->LoadingCanceled = 1;
  }
  v5 = pObject->pData.pObject;
  if ( v5->LoadState <= LS_LoadingFrames )
    Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(v5->pFrameUpdate.pObject);
  Scaleform::GFx::LoadUpdateSync::WaitForLoadFinished(this->pBindData.pObject->pBindUpdate.pObject);
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
Scaleform::GFx::ExporterInfoImpl *__fastcall Scaleform::GFx::MovieDefImpl::GetExporterInfo(
        Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::ExporterInfoImpl *result; // rax

  result = &this->pBindData.pObject->pDataDef.pObject->pData.pObject->Header.mExporterInfo;
  if ( result->SI.Format == File_Unopened )
    return 0i64;
  return result;
}

// File Line: 1469
// RVA: 0x8DAFD0
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetMetadata(
        Scaleform::GFx::MovieDefImpl *this,
        char *pbuff,
        unsigned int buffSize)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // rax
  char *pMetadata; // rdx
  unsigned int MetadataSize; // ebx

  pObject = this->pBindData.pObject->pDataDef.pObject->pData.pObject;
  if ( !pbuff )
    return pObject->MetadataSize;
  pMetadata = pObject->pMetadata;
  MetadataSize = pObject->MetadataSize;
  if ( buffSize < MetadataSize )
    MetadataSize = buffSize;
  if ( pMetadata )
    memmove(pbuff, pMetadata, MetadataSize);
  return MetadataSize;
}

// File Line: 1470
// RVA: 0x8D7A60
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetFileAttributesA(Scaleform::GFx::MovieDefImpl *this)
{
  return this->pBindData.pObject->pDataDef.pObject->pData.pObject->FileAttributes;
}

// File Line: 1545
// RVA: 0x8DA920
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::MovieDefImpl::GetKey(
        Scaleform::GFx::MovieDefImpl *this,
        Scaleform::GFx::ResourceKey *result)
{
  Scaleform::GFx::MovieDefImpl::CreateMovieKey(
    result,
    this->pBindData.pObject->pDataDef.pObject,
    (Scaleform::GFx::Resource *)this->pBindStates.pObject);
  return result;
}

// File Line: 1546
// RVA: 0x8DDCF0
__int64 __fastcall Scaleform::GFx::MovieDefImpl::GetResourceTypeCode(Scaleform::GFx::MovieDefImpl *this)
{
  return 768i64;
}

// File Line: 1633
// RVA: 0x8C9B40
void __fastcall Scaleform::GFx::MovieBindProcess::Execute(Scaleform::GFx::MovieBindProcess *this)
{
  while ( (unsigned int)Scaleform::GFx::MovieBindProcess::BindNextFrame(this) == 1 )
    ;
}

// File Line: 1640
// RVA: 0x8EC220
void __fastcall Scaleform::GFx::MovieBindProcess::OnAbandon(Scaleform::GFx::MovieBindProcess *this, bool started)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // rcx

  pObject = this->pBindData.pObject;
  if ( pObject )
  {
    if ( started )
      pObject->BindingCanceled = 1;
    else
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(pObject, 3u);
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
void __fastcall Scaleform::GFx::GFxPlaceObjectUnpacked::GFxPlaceObjectUnpacked(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this)
{
  Scaleform::GFx::CharPosInfo *p_Pos; // rbx

  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::ExecuteTag::`vftable;
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::GFxPlaceObjectBase::`vftable;
  this->vfptr = (Scaleform::GFx::ExecuteTagVtbl *)&Scaleform::GFx::GFxPlaceObjectUnpacked::`vftable;
  p_Pos = &this->Pos;
  Scaleform::Render::Cxform::Cxform(&this->Pos.ColorTransform);
  *(_QWORD *)&p_Pos->Matrix_1.M[0][0] = 1065353216i64;
  *(_QWORD *)&p_Pos->Matrix_1.M[0][2] = 0i64;
  p_Pos->Matrix_1.M[1][0] = 0.0;
  *(_QWORD *)&p_Pos->Matrix_1.M[1][1] = 1065353216i64;
  p_Pos->Matrix_1.M[1][3] = 0.0;
  p_Pos->pFilters.pObject = 0i64;
  p_Pos->CharacterId.Id = 0x40000;
  *(_DWORD *)&p_Pos->ClipDepth = 0;
  *(_QWORD *)&p_Pos->Ratio = 0i64;
  *(_WORD *)&p_Pos->BlendMode = 256;
  p_Pos->ClassName = 0i64;
}

// File Line: 1778
// RVA: 0x915660
void __fastcall Scaleform::GFx::GFxPlaceObjectUnpacked::Unpack(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this,
        Scaleform::GFx::GFxPlaceObjectBase::UnpackedData *data)
{
  data->Name = 0i64;
  data->pEventHandlers = 0i64;
  data->PlaceType = Place_Add;
  Scaleform::GFx::CharPosInfo::operator=(&data->Pos, &this->Pos);
}

// File Line: 1785
// RVA: 0x8D8100
Scaleform::GFx::CharPosInfoFlags *__fastcall Scaleform::GFx::GFxPlaceObjectUnpacked::GetFlags(
        Scaleform::GFx::GFxPlaceObjectUnpacked *this,
        Scaleform::GFx::CharPosInfoFlags *result)
{
  result->Flags = (unsigned __int16)this->Pos.Flags;
  return result;
}

