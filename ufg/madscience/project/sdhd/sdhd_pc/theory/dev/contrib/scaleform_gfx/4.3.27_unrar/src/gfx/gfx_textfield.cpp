// File Line: 37
// RVA: 0x89E210
void __fastcall Scaleform::GFx::TextField::TextField(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::TextFieldDef *def,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *parent,
        Scaleform::MemoryHeap *id)
{
  Scaleform::GFx::InteractiveObject *v10; // r15
  Scaleform::GFx::MovieImpl *v11; // rsi
  Scaleform::GFx::MovieImpl *pMovieImpl; // r13
  __int64 v13; // rax
  Scaleform::Render::Text::Allocator *v14; // r12
  Scaleform::GFx::MovieDefRootNode *i; // rcx
  Scaleform::ArrayDefaultPolicy *p_Policy; // rax
  Scaleform::Render::Text::FontManagerBase *pObject; // rbp
  Scaleform::GFx::MovieDefRootNode *j; // rax
  Scaleform::Render::Text::DocView *v19; // rdi
  Scaleform::GFx::TextField *pParent; // rax
  Scaleform::Log *CachedLog; // rax
  Scaleform::GFx::MovieImpl *v22; // rax
  Scaleform::Render::RenderBuffer *v23; // rcx
  Scaleform::RefCountNTSImpl *pLoadQueueHead; // rcx
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::Render::TreeText *v26; // rax
  int MaxLength; // eax
  Scaleform::Render::Text::DocView *v28; // rax
  unsigned __int16 Flags; // ax
  bool v30; // di
  Scaleform::Render::Text::DocView *v32; // rcx
  char v33; // al
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> result; // [rsp+B8h] [rbp+20h] BYREF

  LODWORD(id) = id->vfptr;
  v10 = parent;
  Scaleform::GFx::InteractiveObject::InteractiveObject(this, pbindingDefImpl, pasRoot, parent, &id);
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::TextField::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::TextField::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  if ( def )
    _InterlockedExchangeAdd(&def->RefCount.Value, 1u);
  this->pDef.pObject = def;
  v11 = 0i64;
  this->pDocument.pObject = 0i64;
  this->pFilters.pObject = 0i64;
  Scaleform::StringLH::StringLH(&this->OriginalTextValue);
  Scaleform::GFx::TextField::TextDocumentListener::TextDocumentListener(&this->TextDocListener);
  this->pImageDescAssoc = 0i64;
  if ( pbindingDefImpl )
    this->pBinding = &pbindingDefImpl->pBindData.pObject->ResourceBinding;
  else
    this->pBinding = 0i64;
  this->Flags = 0;
  this->FocusedControllerIdx = -1;
  this->Alignment = def->Alignment;
  this->Flags = (def->Flags & 4) != 0 ? 4 : 0;
  if ( SLOBYTE(def->Flags) >= 0 )
    this->Flags &= ~2u;
  else
    this->Flags |= 2u;
  this->Flags |= 0x80u;
  this->pShadow = 0i64;
  pMovieImpl = pasRoot->pMovieImpl;
  v13 = ((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pMovieImpl->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[60].__vecDelDtor)(pMovieImpl->pASMovieRoot.pObject);
  v14 = (Scaleform::Render::Text::Allocator *)v13;
  if ( v13 )
    ++*(_DWORD *)(v13 + 8);
  for ( i = pMovieImpl->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
  {
    p_Policy = &pMovieImpl->MovieLevels.Data.Policy;
    if ( pMovieImpl == (Scaleform::GFx::MovieImpl *)-112i64 )
      p_Policy = 0i64;
    if ( i == (Scaleform::GFx::MovieDefRootNode *)p_Policy )
      break;
    if ( (i->pDefImpl == pbindingDefImpl || !pbindingDefImpl) && i->pFontManager.pObject )
    {
      pObject = i->pFontManager.pObject;
      if ( pObject )
        goto LABEL_30;
      break;
    }
  }
  if ( !v10
    || (pObject = (Scaleform::Render::Text::FontManagerBase *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[67].__vecDelDtor)(v10)) == 0i64 )
  {
    for ( j = pMovieImpl->RootMovieDefNodes.Root.pNext; ; j = j->pNext )
    {
      i = (Scaleform::GFx::MovieDefRootNode *)&pMovieImpl->MovieLevels.Data.Policy;
      if ( pMovieImpl == (Scaleform::GFx::MovieImpl *)-112i64 )
        i = 0i64;
      if ( j == i )
        break;
      if ( j->pFontManager.pObject )
      {
        pObject = j->pFontManager.pObject;
        goto LABEL_30;
      }
    }
    pObject = 0i64;
  }
LABEL_30:
  id = pMovieImpl->pHeap;
  v19 = (Scaleform::Render::Text::DocView *)id->vfptr->Alloc((Scaleform::MemoryHeap *)i, 352ui64, 0i64);
  if ( v19 )
  {
    pParent = this;
    while ( SLOBYTE(pParent->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >= 0 )
    {
      pParent = (Scaleform::GFx::TextField *)pParent->pParent;
      if ( !pParent )
        goto LABEL_36;
    }
    v11 = pParent->pASRoot->pMovieImpl;
LABEL_36:
    CachedLog = Scaleform::GFx::MovieImpl::GetCachedLog(v11);
    Scaleform::Render::Text::DocView::DocView(v19, v14, pObject, CachedLog);
    v11 = v22;
  }
  v23 = (Scaleform::Render::RenderBuffer *)this->pDocument.pObject;
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  this->pDocument.pObject = (Scaleform::Render::Text::DocView *)v11;
  if ( this != (Scaleform::GFx::TextField *)-288i64 )
    ++this->TextDocListener.RefCount;
  pLoadQueueHead = (Scaleform::RefCountNTSImpl *)v11->pLoadQueueHead;
  if ( pLoadQueueHead )
    Scaleform::RefCountNTSImpl::Release(pLoadQueueHead);
  v11->pLoadQueueHead = (Scaleform::GFx::LoadQueueEntry *)&this->TextDocListener;
  this->pDocument.pObject->pDocument.pObject->RTFlags |= 2u;
  this->pDocument.pObject->FlagsEx |= 4u;
  if ( (def->Flags & 0x40) != 0 )
  {
    this->pDocument.pObject->BackgroundColor = -1;
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
    this->pDocument.pObject->BorderColor = -16777216;
    v26 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(v26);
  }
  Scaleform::GFx::TextField::SetInitialFormatsAsDefault(this);
  MaxLength = def->MaxLength;
  if ( MaxLength > 0 )
    this->pDocument.pObject->MaxLength = MaxLength;
  Scaleform::Render::Text::DocView::SetViewRect(this->pDocument.pObject, &def->TextRect, UseExternally);
  if ( (def->Flags & 0x100) != 0 )
  {
    this->pDocument.pObject->Flags |= 0x20u;
    this->pDocument.pObject->Flags |= 0x40u;
  }
  v28 = this->pDocument.pObject;
  if ( (def->Flags & 2) != 0 )
    v28->Flags |= 4u;
  else
    v28->Flags &= ~4u;
  Flags = def->Flags;
  v30 = (Flags & 0x10) != 0;
  if ( (Flags & 0x10) != 0 && ((Flags & 1) == 0 || (Flags & 2) == 0) )
    Scaleform::Render::Text::DocView::SetAutoSizeX(this->pDocument.pObject);
  if ( v30 )
    Scaleform::Render::Text::DocView::SetAutoSizeY(this->pDocument.pObject);
  if ( (def->Flags & 1) != 0 )
    Scaleform::Render::Text::DocView::SetWordWrap(this->pDocument.pObject);
  if ( (this->Flags & 4) != 0 )
    this->pDocument.pObject->Flags |= 0x10u;
  if ( (def->Flags & 0x400) != 0 )
    this->pDocument.pObject->Flags |= 0x40u;
  v32 = this->pDocument.pObject;
  if ( v32->pEditorKit.pObject )
    v33 = ((__int64 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v32->pEditorKit.pObject->vfptr[2].__vecDelDtor)(v32->pEditorKit.pObject);
  else
    v33 = (this->pDef.pObject->Flags & 8) != 0;
  if ( !v33 || (def->Flags & 0x20) != 0 )
  {
    Scaleform::GFx::TextField::CreateEditorKit(this, &result);
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  }
  this->Flags |= 0x10000u;
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release(v14);
}

// File Line: 125
// RVA: 0x8A8000
void __fastcall Scaleform::GFx::TextField::~TextField(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField::ShadowParams *pShadow; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::GFx::TextFieldDef *v5; // rsi
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::TextField::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::TextField::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  Scaleform::GFx::TextField::ClearIdImageDescAssoc(this);
  Scaleform::Render::Text::DocView::Close(this->pDocument.pObject);
  pShadow = this->pShadow;
  if ( pShadow )
  {
    Scaleform::GFx::TextField::ShadowParams::~ShadowParams(this->pShadow);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pShadow);
  }
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&this->TextDocListener);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  pObject = (Scaleform::Render::RenderBuffer *)this->pFilters.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  v4 = (Scaleform::Render::RenderBuffer *)this->pDocument.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = this->pDef.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount.Value) )
  {
    pLib = v5->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v5);
      v5->pLib = 0i64;
    }
    v5->vfptr->__vecDelDtor(v5, 1u);
  }
  Scaleform::GFx::InteractiveObject::~InteractiveObject(this);
}

// File Line: 140
// RVA: 0x8E7810
bool __fastcall Scaleform::GFx::TextField::IsSelectable(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rdx

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    return ((__int64)pObject[10].vfptr & 2) != 0;
  else
    return (this->pDef.pObject->Flags & 0x20) != 0;
}

// File Line: 146
// RVA: 0x8E77D0
bool __fastcall Scaleform::GFx::TextField::IsReadOnly(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    return (bool)pObject->vfptr[2].__vecDelDtor(pObject, (unsigned int)this);
  else
    return (this->pDef.pObject->Flags & 8) != 0;
}

// File Line: 152
// RVA: 0x907250
void __fastcall Scaleform::GFx::TextField::SetFilters(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::Resource *filters)
{
  Scaleform::Render::RenderBuffer *pObject; // rcx
  unsigned int i; // ebx
  Scaleform::Render::Filter *Filter; // rax
  Scaleform::Render::Text::DocView *v7; // rbx
  float BlurX; // xmm1_4
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::Render::Text::TextFilter v10; // [rsp+30h] [rbp-68h] BYREF

  if ( !filters )
    return;
  Scaleform::Render::RenderBuffer::AddRef(filters);
  pObject = (Scaleform::Render::RenderBuffer *)this->pFilters.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pFilters.pObject = (Scaleform::Render::FilterSet *)filters;
  Scaleform::Render::Text::TextFilter::TextFilter(&v10);
  for ( i = 0;
        i < (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)filters);
        ++i )
  {
    Filter = Scaleform::Render::FilterSet::GetFilter((Scaleform::Render::FilterSet *)filters, i);
    if ( Filter )
      Scaleform::Render::Text::TextFilter::LoadFilterDesc(&v10, Filter);
  }
  v7 = this->pDocument.pObject;
  if ( v7 )
  {
    BlurX = v10.BlurX;
    if ( v10.BlurX != v7->Filter.BlurX || v10.BlurY != v7->Filter.BlurY || v10.BlurStrength != v7->Filter.BlurStrength )
      goto LABEL_18;
    if ( !Scaleform::Render::BlurFilterParams::EqualsAll(&v7->Filter.ShadowParams, &v10.ShadowParams)
      || v7->Filter.ShadowFlags != v10.ShadowFlags
      || v7->Filter.ShadowAlpha != v10.ShadowAlpha
      || v10.ShadowAngle != v7->Filter.ShadowAngle
      || v10.ShadowDistance != v7->Filter.ShadowDistance )
    {
      BlurX = v10.BlurX;
LABEL_18:
      v7->Filter.BlurX = BlurX;
      v7->Filter.BlurY = v10.BlurY;
      v7->Filter.BlurStrength = v10.BlurStrength;
      Scaleform::Render::BlurFilterParams::operator=(&v7->Filter.ShadowParams, &v10.ShadowParams);
      v7->Filter.ShadowFlags = v10.ShadowFlags;
      v7->Filter.ShadowAngle = v10.ShadowAngle;
      v7->Filter.ShadowDistance = v10.ShadowDistance;
      v7->Filter.ShadowAlpha = v10.ShadowAlpha;
      RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
      Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
    }
  }
  if ( v10.ShadowParams.Gradient.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10.ShadowParams.Gradient.pObject);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore(&v10);
}

// File Line: 178
// RVA: 0x8DF1D0
long double __fastcall Scaleform::GFx::TextField::GetTextWidth(Scaleform::GFx::TextField *this)
{
  return (float)(Scaleform::Render::Text::DocView::GetTextWidth(this->pDocument.pObject) * 0.050000001);
}

// File Line: 183
// RVA: 0x8DF160
long double __fastcall Scaleform::GFx::TextField::GetTextHeight(Scaleform::GFx::TextField *this)
{
  return (float)(Scaleform::Render::Text::DocView::GetTextHeight(this->pDocument.pObject) * 0.050000001);
}

// File Line: 206
// RVA: 0x906ED0
void __fastcall Scaleform::GFx::TextField::SetDirtyFlag(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::TreeText *RenderNode; // rax

  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}

// File Line: 214
// RVA: 0x90BBA0
void __fastcall Scaleform::GFx::TextField::SetSelectable(Scaleform::GFx::TextField *this, bool v)
{
  Scaleform::GFx::Resource *pObject; // rbx
  Scaleform::GFx::Resource **v5; // rdi
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> result; // [rsp+50h] [rbp+18h] BYREF

  pObject = (Scaleform::GFx::Resource *)this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)this->pDocument.pObject->pEditorKit.pObject);
  if ( v )
  {
    v5 = (Scaleform::GFx::Resource **)Scaleform::GFx::TextField::CreateEditorKit(this, &result);
    if ( *v5 )
      Scaleform::Render::RenderBuffer::AddRef(*v5);
    if ( pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pObject);
    pObject = *v5;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    LOWORD(pObject[6].pLib) |= 2u;
  }
  else if ( pObject )
  {
    LOWORD(pObject[6].pLib) &= ~2u;
  }
  if ( pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)pObject);
}

// File Line: 234
// RVA: 0x8BF460
Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> *__fastcall Scaleform::GFx::TextField::CreateEditorKit(
        Scaleform::GFx::TextField *this,
        Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> *result)
{
  Scaleform::GFx::Text::EditorKit *v4; // rsi
  Scaleform::Render::Text::DocView *pObject; // rax
  Scaleform::GFx::Text::EditorKit *v6; // rbp
  Scaleform::GFx::Text::EditorKit *v7; // rax
  Scaleform::GFx::Text::EditorKit *v8; // rax
  Scaleform::GFx::StateBag *v9; // rcx
  Scaleform::GFx::StateBag *v10; // rax
  Scaleform::GFx::Clipboard *v11; // rsi
  Scaleform::GFx::Text::EditorKit *v12; // rbp
  Scaleform::Render::RenderBuffer *v13; // rcx
  Scaleform::GFx::StateBag *v14; // rcx
  Scaleform::GFx::StateBag *v15; // rax
  Scaleform::GFx::TextKeyMap *v16; // rsi
  Scaleform::GFx::Text::EditorKit *v17; // rbp
  Scaleform::Render::RenderBuffer *v18; // rcx
  Scaleform::GFx::Text::EditorKit *v19; // rax
  Scaleform::Ptr<Scaleform::GFx::Clipboard> resulta; // [rsp+28h] [rbp-40h] BYREF
  __int64 v22; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::Text::EditorKit *v23; // [rsp+38h] [rbp-30h]
  int v24; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::Ptr<Scaleform::GFx::TextKeyMap> v25; // [rsp+88h] [rbp+20h] BYREF

  v22 = -2i64;
  v4 = 0i64;
  pObject = this->pDocument.pObject;
  v6 = (Scaleform::GFx::Text::EditorKit *)pObject->pEditorKit.pObject;
  if ( v6 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)pObject->pEditorKit.pObject);
  result->pObject = v6;
  if ( !result->pObject )
  {
    v24 = 74;
    v7 = (Scaleform::GFx::Text::EditorKit *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::TextField *, __int64, int *, int))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              176i64,
                                              &v24,
                                              1);
    v23 = v7;
    if ( v7 )
    {
      Scaleform::GFx::Text::EditorKit::EditorKit(v7, (Scaleform::GFx::Resource *)this->pDocument.pObject);
      v4 = v8;
    }
    if ( result->pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result->pObject);
    result->pObject = v4;
    if ( (this->pDef.pObject->Flags & 8) != 0 )
      v4->Flags |= 1u;
    if ( (this->pDef.pObject->Flags & 0x20) != 0 )
      result->pObject->Flags |= 2u;
    v9 = &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag;
    v10 = (Scaleform::GFx::StateBag *)v9->vfptr->GetStateBagImpl(v9);
    Scaleform::GFx::StateBag::GetClipboard(v10, &resulta);
    v11 = resulta.pObject;
    v12 = result->pObject;
    if ( resulta.pObject )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)resulta.pObject);
    v13 = (Scaleform::Render::RenderBuffer *)v12->pClipboard.pObject;
    if ( v13 )
      Scaleform::RefCountImpl::Release(v13);
    v12->pClipboard.pObject = v11;
    v14 = &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag;
    v15 = (Scaleform::GFx::StateBag *)v14->vfptr->GetStateBagImpl(v14);
    Scaleform::GFx::StateBag::GetTextKeyMap(v15, &v25);
    v16 = v25.pObject;
    v17 = result->pObject;
    if ( v25.pObject )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v25.pObject);
    v18 = (Scaleform::Render::RenderBuffer *)v17->pKeyMap.pObject;
    if ( v18 )
      Scaleform::RefCountImpl::Release(v18);
    v17->pKeyMap.pObject = v16;
    v19 = result->pObject;
    if ( (this->Flags & 0x100) != 0 )
      v19->Flags |= 4u;
    else
      v19->Flags &= ~4u;
    if ( v25.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v25.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
  return result;
}

// File Line: 264
// RVA: 0x8DA1D0
void __fastcall Scaleform::GFx::TextField::GetInitialFormats(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Text::TextFormat *ptextFmt,
        Scaleform::Render::Text::ParagraphFormat *pparaFmt)
{
  char v6; // r14
  Scaleform::GFx::TextFieldDef *pObject; // rcx
  Scaleform::GFx::ResourceBindData *ResourceData; // r14
  Scaleform::GFx::Resource *v9; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::MovieDefImpl *v11; // rax
  Scaleform::GFx::MovieDefImpl *v12; // rbx
  Scaleform::GFx::ResourceLibBase *v13; // rcx
  Scaleform::GFx::TextFieldDef *v14; // rcx
  Scaleform::GFx::Resource *v15; // rax
  __int64 v16; // rbx
  Scaleform::GFx::TextFieldDef *v17; // r8
  __int64 Id_low; // r9
  Scaleform::String::DataDesc *pData; // rax
  Scaleform::GFx::Resource *v20; // rax
  Scaleform::GFx::Resource *vfptr; // r14
  const char *v22; // rax
  Scaleform::GFx::TextFieldDef *v23; // rcx
  Scaleform::GFx::Resource *pOwnerDefRes; // r15
  unsigned __int16 TextHeight; // ax
  Scaleform::GFx::TextFieldDef::alignment Alignment; // edx
  __int32 v27; // edx
  __int32 v28; // edx
  Scaleform::GFx::TextFieldDef *v29; // rcx
  unsigned __int16 PresentMask; // cx
  Scaleform::GFx::Resource *v31; // rbx
  Scaleform::GFx::ResourceLibBase *v32; // rcx
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+48h] [rbp-21h] BYREF
  Scaleform::GFx::ResourceBindData result; // [rsp+58h] [rbp-11h] BYREF
  Scaleform::Render::Text::ParagraphFormat v35; // [rsp+68h] [rbp-1h] BYREF

  Scaleform::Render::Text::TextFormat::InitByDefaultValues(ptextFmt);
  Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(pparaFmt);
  presBindData.pResource.pObject = 0i64;
  presBindData.pBinding = 0i64;
  v6 = 1;
  pObject = this->pDef.pObject;
  if ( LOWORD(pObject->FontId.Id) )
  {
    ResourceData = Scaleform::GFx::ResourceBinding::GetResourceData(this->pBinding, &result, &pObject->pFont);
    if ( ResourceData->pResource.pObject )
      _InterlockedExchangeAdd(&ResourceData->pResource.pObject->RefCount.Value, 1u);
    presBindData = *ResourceData;
    v9 = result.pResource.pObject;
    if ( result.pResource.pObject && !_InterlockedDecrement(&result.pResource.pObject->RefCount.Value) )
    {
      pLib = v9->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v9);
        v9->pLib = 0i64;
      }
      v9->vfptr->__vecDelDtor(v9, 1u);
    }
  }
  else if ( (*(_QWORD *)(pObject->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) != 0 )
  {
    v11 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(this);
    v12 = v11;
    if ( v11 )
      _InterlockedExchangeAdd(&v11->RefCount.Value, 1u);
    if ( !Scaleform::GFx::MovieImpl::FindExportedResource(
            this->pASRoot->pMovieImpl,
            v11,
            &presBindData,
            &this->pDef.pObject->FontClass) )
    {
      Scaleform::Render::Text::TextFormat::SetFontName(ptextFmt, &this->pDef.pObject->FontClass);
      v6 = 0;
    }
    if ( v12 && !_InterlockedDecrement(&v12->RefCount.Value) )
    {
      v13 = v12->pLib;
      if ( v13 )
      {
        v13->vfptr[1].__vecDelDtor(v13, (unsigned int)v12);
        v12->pLib = 0i64;
      }
      v12->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v12, 1u);
    }
    if ( !v6 )
      goto LABEL_49;
  }
  v14 = this->pDef.pObject;
  if ( !LOWORD(v14->FontId.Id)
    && (*(_QWORD *)(v14->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) == 0 )
  {
    goto LABEL_49;
  }
  if ( presBindData.pResource.pObject )
  {
    if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)(presBindData.pResource.pObject) & 0xFF00) == 512 )
    {
      if ( !presBindData.pResource.pObject )
        goto LABEL_49;
      vfptr = (Scaleform::GFx::Resource *)presBindData.pResource.pObject[1].vfptr;
      v22 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::Resource *))vfptr->vfptr->GetKey)(vfptr);
      Scaleform::Render::Text::TextFormat::SetFontName(ptextFmt, v22, 0xFFFFFFFFFFFFFFFFui64);
      v23 = this->pDef.pObject;
      if ( SLOBYTE(v23->Flags) < 0
        && (*(_QWORD *)(v23->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) == 0 )
      {
        goto LABEL_49;
      }
      Scaleform::Render::Text::TextFormat::SetBold(ptextFmt, (HIDWORD(vfptr[1].vfptr) & 2) != 0);
      Scaleform::Render::Text::TextFormat::SetItalic(ptextFmt, BYTE4(vfptr[1].vfptr) & 1);
      if ( (this->pDef.pObject->Flags & 0x100) != 0 || (HIDWORD(vfptr[1].vfptr) & 0x40) != 0 )
        goto LABEL_49;
      v16 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
              Scaleform::Memory::pGlobalHeap,
              64i64);
      if ( v16 )
      {
        pOwnerDefRes = presBindData.pBinding->pOwnerDefRes;
        *(_QWORD *)v16 = &Scaleform::RefCountImplCore::`vftable;
        *(_DWORD *)(v16 + 8) = 1;
        *(_QWORD *)v16 = &Scaleform::RefCountImpl::`vftable;
        *(_QWORD *)v16 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
        *(_QWORD *)v16 = &Scaleform::RefCountBase<Scaleform::Render::Text::FontHandle,74>::`vftable;
        *(_QWORD *)v16 = &Scaleform::Render::Text::FontHandle::`vftable;
        *(_QWORD *)(v16 + 16) = 0i64;
        *(_DWORD *)(v16 + 24) = 0;
        Scaleform::StringLH::StringLH((Scaleform::StringLH *)(v16 + 32));
        *(_DWORD *)(v16 + 40) = 1065353216;
        Scaleform::Render::RenderBuffer::AddRef(vfptr);
        *(_QWORD *)(v16 + 48) = vfptr;
        *(_QWORD *)v16 = &Scaleform::GFx::FontHandle::`vftable;
        if ( pOwnerDefRes )
          _InterlockedExchangeAdd(&pOwnerDefRes->RefCount.Value, 1u);
        *(_QWORD *)(v16 + 56) = pOwnerDefRes;
      }
      else
      {
        v16 = 0i64;
      }
      Scaleform::Render::Text::TextFormat::SetFontHandle(ptextFmt, (Scaleform::Render::Text::FontHandle *)v16);
    }
    else
    {
      v20 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[76].__vecDelDtor)(this);
      v16 = (__int64)v20;
      if ( v20 )
        Scaleform::Render::RenderBuffer::AddRef(v20);
      if ( v16 )
        Scaleform::Log::LogError(
          (Scaleform::Log *)v16,
          "Font id = %d is referring to non-font resource in text field id = %d, def text = %s",
          LOWORD(this->pDef.pObject->FontId.Id),
          LOWORD(this->Id.Id),
          (const char *)((this->pDef.pObject->DefaultText.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12));
    }
  }
  else
  {
    v15 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[76].__vecDelDtor)(this);
    v16 = (__int64)v15;
    if ( v15 )
      Scaleform::Render::RenderBuffer::AddRef(v15);
    if ( v16 )
    {
      v17 = this->pDef.pObject;
      Id_low = LOWORD(this->Id.Id);
      pData = v17->DefaultText.pData;
      if ( LOWORD(v17->FontId.Id) )
        Scaleform::Log::LogError(
          (Scaleform::Log *)v16,
          "Resource for font id = %d is not found in text field id = %d, def text = %s",
          LOWORD(v17->FontId.Id),
          Id_low,
          (const char *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 12));
      else
        Scaleform::Log::LogError(
          (Scaleform::Log *)v16,
          "Resource for font class = %s is not found in text field id = %d, def text = %s",
          (const char *)((v17->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          Id_low,
          (const char *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 12));
    }
  }
  if ( v16 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v16);
LABEL_49:
  TextHeight = -1;
  if ( (unsigned int)(int)this->pDef.pObject->TextHeight <= 0x10000 )
    TextHeight = (int)this->pDef.pObject->TextHeight;
  ptextFmt->FontSize = TextHeight;
  ptextFmt->PresentMask |= 8u;
  ptextFmt->ColorV = this->pDef.pObject->ColorV.Raw;
  ptextFmt->PresentMask |= 1u;
  v35.pAllocator = 0i64;
  v35.RefCount = 1;
  memset(&v35.pTabStops, 0, 20);
  Alignment = this->pDef.pObject->Alignment;
  if ( Alignment )
  {
    v27 = Alignment - 1;
    if ( v27 )
    {
      v28 = v27 - 1;
      if ( v28 )
      {
        if ( v28 == 1 )
        {
          pparaFmt->PresentMask &= ~0x200u;
          pparaFmt->PresentMask |= 0x401u;
        }
      }
      else
      {
        pparaFmt->PresentMask |= 0x601u;
      }
    }
    else
    {
      pparaFmt->PresentMask &= ~0x400u;
      pparaFmt->PresentMask |= 0x201u;
    }
  }
  else
  {
    pparaFmt->PresentMask &= 0xF9FFu;
    pparaFmt->PresentMask |= 1u;
  }
  v29 = this->pDef.pObject;
  if ( (v29->Flags & 0x200) != 0 )
  {
    pparaFmt->LeftMargin = (int)(float)(v29->LeftMargin * 0.050000001);
    pparaFmt->PresentMask |= 0x10u;
    PresentMask = pparaFmt->PresentMask;
    pparaFmt->RightMargin = (int)(float)(this->pDef.pObject->RightMargin * 0.050000001);
    PresentMask |= 0x20u;
    pparaFmt->PresentMask = PresentMask;
    pparaFmt->Indent = (int)(float)(this->pDef.pObject->Indent * 0.050000001);
    PresentMask |= 4u;
    pparaFmt->PresentMask = PresentMask;
    pparaFmt->Leading = (int)(float)(this->pDef.pObject->Leading * 0.050000001);
    pparaFmt->PresentMask = PresentMask | 8;
  }
  Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&v35);
  v31 = presBindData.pResource.pObject;
  if ( presBindData.pResource.pObject
    && _InterlockedExchangeAdd(&presBindData.pResource.pObject->RefCount.Value, 0xFFFFFFFF) == 1 )
  {
    v32 = v31->pLib;
    if ( v32 )
    {
      v32->vfptr[1].__vecDelDtor(v32, (unsigned int)v31);
      v31->pLib = 0i64;
    }
    v31->vfptr->__vecDelDtor(v31, 1u);
  }
}

// File Line: 368
// RVA: 0x9082A0
void __fastcall Scaleform::GFx::TextField::SetInitialFormatsAsDefault(Scaleform::GFx::TextField *this)
{
  Scaleform::MemoryHeap *v2; // rax
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rax
  Scaleform::Render::Text::TextFormat *v4; // rsi
  Scaleform::Render::Text::ParagraphFormat *v5; // rdi
  Scaleform::Render::Text::TextFormat *v6; // rax
  Scaleform::Render::Text::ParagraphFormat *v7; // rax
  Scaleform::MemoryHeap *v8; // rax
  Scaleform::Render::Text::TextFormat *v9; // rax
  Scaleform::Render::Text::ParagraphFormat *v10; // rax
  Scaleform::Render::Text::ParagraphFormat pparaFmt; // [rsp+20h] [rbp-D8h] BYREF
  Scaleform::Render::Text::ParagraphFormat v12; // [rsp+48h] [rbp-B0h] BYREF
  __int64 v13; // [rsp+70h] [rbp-88h]
  Scaleform::Render::Text::TextFormat ptextFmt; // [rsp+78h] [rbp-80h] BYREF
  Scaleform::Render::Text::TextFormat result; // [rsp+C8h] [rbp-30h] BYREF
  Scaleform::Render::Text::TextFormat v16; // [rsp+118h] [rbp+20h] BYREF

  v13 = -2i64;
  v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  Scaleform::Render::Text::TextFormat::TextFormat(&ptextFmt, v2);
  pparaFmt.pAllocator = 0i64;
  pparaFmt.RefCount = 1;
  memset(&pparaFmt.pTabStops, 0, 20);
  pObject = this->pDocument.pObject->pDocument.pObject;
  v4 = pObject->pDefaultTextFormat.pObject;
  v5 = pObject->pDefaultParagraphFormat.pObject;
  if ( (this->pDef.pObject->Flags & 0x800) != 0 )
  {
    if ( v4 )
      Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v4);
    if ( v5 )
      Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v5);
    v8 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
    Scaleform::Render::Text::TextFormat::TextFormat(&result, v8);
    v12.pAllocator = 0i64;
    v12.RefCount = 1;
    memset(&v12.pTabStops, 0, 20);
    Scaleform::Render::Text::TextFormat::InitByDefaultValues(&result);
    Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(&v12);
    v9 = Scaleform::Render::Text::TextFormat::Merge(&result, &v16, &ptextFmt);
    Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v9);
    Scaleform::Render::Text::TextFormat::~TextFormat(&v16);
    v10 = Scaleform::Render::Text::ParagraphFormat::Merge(
            &v12,
            (Scaleform::Render::Text::ParagraphFormat *)&v16,
            &pparaFmt);
    Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v10);
    Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat((Scaleform::Render::Text::ParagraphFormat *)&v16);
    Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&v12);
    Scaleform::Render::Text::TextFormat::~TextFormat(&result);
  }
  else
  {
    Scaleform::GFx::TextField::GetInitialFormats(this, &ptextFmt, &pparaFmt);
    if ( v4 )
    {
      v6 = Scaleform::Render::Text::TextFormat::Merge(v4, &result, &ptextFmt);
      Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v6);
      Scaleform::Render::Text::TextFormat::~TextFormat(&result);
    }
    if ( v5 )
    {
      v7 = Scaleform::Render::Text::ParagraphFormat::Merge(v5, &v12, &pparaFmt);
      Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v7);
      Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&v12);
    }
  }
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this->pDocument.pObject->pDocument.pObject, &ptextFmt);
  this->Flags |= 0x10000u;
  Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(this->pDocument.pObject->pDocument.pObject, &pparaFmt);
  this->Flags |= 0x10000u;
  Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&pparaFmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&ptextFmt);
}

// File Line: 402
// RVA: 0x8BA6E0
__int64 __fastcall Scaleform::GFx::TextField::CheckAdvanceStatus(Scaleform::GFx::TextField *this, bool playingNow)
{
  unsigned int v2; // ebx
  unsigned __int16 Flags; // dx
  unsigned int v6; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbp
  Scaleform::Render::Text::EditorKitBase *pObject; // r14

  v2 = 0;
  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0xC) == 0 )
  {
    Flags = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
    if ( (Flags & 0x40) == 0 && (this->pDef.pObject->Flags & 0x1000) == 0 )
    {
      v6 = this->Flags;
      if ( (v6 & 0x4000) != 0
        || (v6 & 0x8000) != 0
        || (pMovieImpl = this->pASRoot->pMovieImpl,
            pObject = this->pDocument.pObject->pEditorKit.pObject,
            (Flags & 0x4000) != 0)
        && pObject
        && (!((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))pObject->vfptr[2].__vecDelDtor)(pObject)
         && Scaleform::GFx::MovieImpl::IsFocused(pMovieImpl, this)
         || ((__int64)pObject[10].vfptr & 0x20) != 0) )
      {
        if ( !playingNow )
          return 1i64;
      }
      else if ( playingNow )
      {
        return 0xFFFFFFFFi64;
      }
      return 0i64;
    }
  }
  if ( playingNow )
    return (unsigned int)-1;
  return v2;
}

// File Line: 445
// RVA: 0x90C3F0
void __fastcall Scaleform::GFx::TextField::SetStateChangeFlags(Scaleform::GFx::TextField *this, char flags)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  unsigned __int16 v4; // dx
  Scaleform::GFx::InteractiveObject *pPlayListHead; // rax
  unsigned int v6; // ecx
  bool v7; // dl
  int v8; // eax

  this->Scaleform::GFx::InteractiveObject::Flags &= 0xFFF0FFFF;
  this->Flags |= 0x4000u;
  this->Scaleform::GFx::InteractiveObject::Flags |= (flags & 0xF | 0x10) << 16;
  if ( !this->pPlayNext && !this->pPlayPrev )
  {
    pMovieImpl = this->pASRoot->pMovieImpl;
    if ( pMovieImpl->pPlayListHead != this )
    {
      v4 = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
      if ( (v4 & 0x10) == 0 && (v4 & 0x1000) == 0 && this->Depth >= -1 )
      {
        pPlayListHead = pMovieImpl->pPlayListHead;
        if ( pPlayListHead )
        {
          pPlayListHead->pPlayPrev = this;
          this->pPlayNext = pMovieImpl->pPlayListHead;
        }
        pMovieImpl->pPlayListHead = this;
      }
    }
  }
  v6 = this->Scaleform::GFx::InteractiveObject::Flags;
  v7 = (v6 & 0x200000) != 0 && (v6 & 0x400000) == 0;
  v8 = Scaleform::GFx::TextField::CheckAdvanceStatus(this, v7);
  if ( v8 == -1 )
  {
    this->Scaleform::GFx::InteractiveObject::Flags |= 0x400000u;
  }
  else if ( v8 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
  }
}

// File Line: 456
// RVA: 0x917D70
void __fastcall Scaleform::GFx::TextField::UpdateTransform3D(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Rect<float> *ViewRect; // rbx
  double Z; // xmm4_8
  float v4; // xmm2_4
  float v5; // xmm3_4
  double YScale; // xmm2_8
  double ZScale; // xmm3_8
  float XScale; // xmm1_4
  float v9; // ebx
  float v10; // esi
  float v11; // r14d
  double XRotation; // xmm1_8
  float v13; // edi
  float v14; // r15d
  float v15; // r12d
  float v16; // r13d
  float v17; // xmm6_4
  float v18; // xmm0_4
  float v19; // edx
  float v20; // r8d
  float v21; // r9d
  float v22; // r10d
  float v23; // r11d
  double YRotation; // xmm0_8
  float v25; // xmm6_4
  float v26; // xmm0_4
  double Rotation; // xmm0_8
  float v28; // xmm6_4
  float v29; // xmm0_4
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+20h] [rbp-D8h] BYREF
  char v31[52]; // [rsp+50h] [rbp-A8h] BYREF
  float v32; // [rsp+84h] [rbp-74h]
  float v33; // [rsp+88h] [rbp-70h]
  int v34; // [rsp+8Ch] [rbp-6Ch]
  float v35; // [rsp+90h] [rbp-68h]
  float v36; // [rsp+94h] [rbp-64h]
  __int64 v37; // [rsp+98h] [rbp-60h]
  int v38; // [rsp+A0h] [rbp-58h]
  int v39; // [rsp+A4h] [rbp-54h]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+A8h] [rbp-50h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+D8h] [rbp-20h] BYREF
  Scaleform::Render::Matrix3x4<float> v42; // [rsp+108h] [rbp+10h] BYREF
  Scaleform::Render::Matrix3x4<float> v43; // [rsp+138h] [rbp+40h] BYREF
  Scaleform::Render::Matrix3x4<float> v44; // [rsp+168h] [rbp+70h] BYREF
  Scaleform::Render::Matrix3x4<float> v45; // [rsp+198h] [rbp+A0h] BYREF
  void *retaddr; // [rsp+238h] [rbp+140h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // [rsp+240h] [rbp+148h]

  ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  memset(&Dst, 0, sizeof(Dst));
  pGeomData = this->pGeomData;
  Z = pGeomData->Z;
  v4 = (float)pGeomData->X - ViewRect->x1;
  v5 = (float)pGeomData->Y - ViewRect->y1;
  *(_QWORD *)&v31[44] = *(_QWORD *)&Dst.M[0][1];
  *(float *)&Z = Z;
  v33 = Dst.M[1][0];
  v35 = Dst.M[1][2];
  *(_DWORD *)&v31[40] = (_DWORD)FLOAT_1_0;
  v37 = *(_QWORD *)&Dst.M[2][0];
  v32 = v4;
  v34 = (int)FLOAT_1_0;
  v36 = v5;
  v38 = (int)FLOAT_1_0;
  v39 = LODWORD(Z);
  memset(&Dst, 0, sizeof(Dst));
  YScale = pGeomData->YScale;
  ZScale = pGeomData->ZScale;
  XScale = pGeomData->XScale;
  m2.M[0][0] = XScale * 0.0099999998;
  m2.M[1][0] = Dst.M[1][0];
  *(_QWORD *)&m2.M[0][1] = *(_QWORD *)&Dst.M[0][1];
  m2.M[0][3] = Dst.M[0][3];
  *(_QWORD *)&m2.M[1][2] = *(_QWORD *)&Dst.M[1][2];
  *(_QWORD *)&m2.M[2][0] = *(_QWORD *)&Dst.M[2][0];
  m2.M[1][1] = (float)YScale * 0.0099999998;
  m2.M[2][2] = (float)ZScale * 0.0099999998;
  v9 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][3];
  v10 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][1];
  v11 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][0];
  m2.M[2][3] = Dst.M[2][3];
  XRotation = pGeomData->XRotation;
  v13 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][2];
  v14 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][3];
  v15 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][2];
  v16 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][1];
  if ( XRotation == 0.0 )
  {
    v23 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    v22 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v21 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v20 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    v19 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    Dst = Scaleform::Render::Matrix3x4<float>::Identity;
  }
  else
  {
    v17 = XRotation * 3.141592653589793 * 0.005555555555555556;
    memset(&Dst, 0, sizeof(Dst));
    cosf(v17);
    v18 = sinf(v17);
    v19 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    v20 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    Dst.M[1][1] = v17;
    *(_QWORD *)&Dst.M[2][1] = __PAIR64__(LODWORD(v17), LODWORD(v18));
    v21 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v22 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v23 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    LODWORD(Dst.M[1][2]) = LODWORD(v17) ^ _xmm[0];
    *(_QWORD *)&Dst.M[0][0] = 1065353216i64;
    Dst.M[1][0] = 0.0;
    Dst.M[2][0] = 0.0;
    Dst.M[0][2] = 0.0;
  }
  m1 = Dst;
  YRotation = pGeomData->YRotation;
  if ( YRotation == 0.0 )
  {
    *(_QWORD *)&Dst.M[0][0] = __PAIR64__(LODWORD(v22), LODWORD(v23));
    *(_QWORD *)&Dst.M[0][2] = __PAIR64__(LODWORD(v20), LODWORD(v21));
    *(_QWORD *)&Dst.M[1][0] = __PAIR64__(LODWORD(v16), LODWORD(v19));
    *(_QWORD *)&Dst.M[1][2] = __PAIR64__(LODWORD(v14), LODWORD(v15));
    *(_QWORD *)&Dst.M[2][0] = __PAIR64__(LODWORD(v10), LODWORD(v11));
    *(_QWORD *)&Dst.M[2][2] = __PAIR64__(LODWORD(v9), LODWORD(v13));
  }
  else
  {
    v25 = YRotation * 3.141592653589793 * 0.005555555555555556;
    memset(&Dst, 0, sizeof(Dst));
    cosf(v25);
    v26 = sinf(v25);
    v19 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    v20 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    *(_QWORD *)&Dst.M[0][0] = LODWORD(v25);
    Dst.M[2][2] = v25;
    Dst.M[0][2] = v26;
    v21 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v22 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v23 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    *(_QWORD *)&Dst.M[2][0] = (unsigned int)(LODWORD(v25) ^ _xmm[0]);
    Dst.M[1][0] = 0.0;
    *(_QWORD *)&Dst.M[1][1] = 1065353216i64;
  }
  v42 = Dst;
  Rotation = pGeomData->Rotation;
  if ( Rotation == 0.0 )
  {
    *(_QWORD *)&Dst.M[0][0] = __PAIR64__(LODWORD(v22), LODWORD(v23));
    *(_QWORD *)&Dst.M[0][2] = __PAIR64__(LODWORD(v20), LODWORD(v21));
    *(_QWORD *)&Dst.M[1][0] = __PAIR64__(LODWORD(v16), LODWORD(v19));
    *(_QWORD *)&Dst.M[1][2] = __PAIR64__(LODWORD(v14), LODWORD(v15));
    *(_QWORD *)&Dst.M[2][0] = __PAIR64__(LODWORD(v10), LODWORD(v11));
    *(_QWORD *)&Dst.M[2][2] = __PAIR64__(LODWORD(v9), LODWORD(v13));
  }
  else
  {
    v28 = Rotation * 3.141592653589793 * 0.005555555555555556;
    memset(&Dst, 0, sizeof(Dst));
    cosf(v28);
    v29 = sinf(v28);
    Dst.M[0][0] = v28;
    *(_QWORD *)&Dst.M[1][1] = LODWORD(v28);
    *(_QWORD *)&Dst.M[2][0] = 0i64;
    Dst.M[1][0] = v29;
    Dst.M[2][2] = 1.0;
    *(_QWORD *)&Dst.M[0][1] = (unsigned int)(LODWORD(v28) ^ _xmm[0]);
  }
  *(Scaleform::Render::Matrix3x4<float> *)v31 = Dst;
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&Dst, &m1, &m2);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v44, (Scaleform::Render::Matrix3x4<float> *)v31, &v42);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v45, &v44, &Dst);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v43, (Scaleform::Render::Matrix3x4<float> *)&v31[40], &v45);
  if ( Scaleform::Render::Matrix3x4<float>::IsValid(&v43) )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix3x4<float> *))(*(_QWORD *)retaddr + 40i64))(retaddr, &v43);
}

// File Line: 477
// RVA: 0x8B59F0
void __fastcall Scaleform::GFx::TextField::AdvanceFrame(
        Scaleform::GFx::TextField *this,
        bool nextFrame,
        float framePos)
{
  char v5; // al
  Scaleform::Render::Text::DocView *pObject; // rcx
  unsigned int Flags; // ecx
  bool v8; // dl
  int v9; // eax
  unsigned __int8 AvmObjOffset; // al
  __int64 v11; // rax
  Scaleform::Render::Text::EditorKitBase *v12; // rdi
  Scaleform::GFx::MovieImpl *pMovieImpl; // rsi
  __int64 TimeElapsed; // rax
  double v15; // xmm1_8
  Scaleform::Render::TreeText *RenderNode; // rax

  v5 = ((__int64 (*)(void))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[80].__vecDelDtor)();
  if ( (v5 & 0xF) != 0 || (this->pASRoot->pMovieImpl->Flags2 & 2) != 0 )
  {
    pObject = this->pDocument.pObject;
    if ( pObject )
    {
      this->Scaleform::GFx::InteractiveObject::Flags &= ~0x100000u;
      pObject->RTFlags |= 2u;
      this->Flags |= 0x10000u;
      if ( (v5 & 8) != 0 )
      {
        Scaleform::GFx::TextField::TextDocumentListener::TranslatorChanged(&this->TextDocListener);
        Scaleform::GFx::TextField::SetTextValue(
          this,
          (const char *)((this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          (this->Flags & 0x1000) != 0,
          1);
      }
    }
  }
  this->Scaleform::GFx::InteractiveObject::Flags &= 0xFFF0FFFF;
  Flags = this->Scaleform::GFx::InteractiveObject::Flags;
  if ( (this->Flags & 0x4000) != 0 )
  {
    this->Flags &= ~0x4000u;
    v8 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
    v9 = Scaleform::GFx::TextField::CheckAdvanceStatus(this, v8);
    if ( v9 == -1 )
    {
      this->Scaleform::GFx::InteractiveObject::Flags |= 0x400000u;
    }
    else if ( v9 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
    }
  }
  if ( nextFrame )
  {
    if ( (this->Flags & 0x8000) != 0 )
    {
      AvmObjOffset = this->AvmObjOffset;
      if ( AvmObjOffset )
      {
        v11 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                       + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v11 + 248i64))(v11);
      }
    }
    this->Flags |= 0x40u;
  }
  else
  {
    this->Flags &= ~0x40u;
  }
  v12 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v12 )
  {
    pMovieImpl = this->pASRoot->pMovieImpl;
    if ( Scaleform::GFx::MovieImpl::IsFocused(pMovieImpl, this) || ((__int64)v12[10].vfptr & 0x20) != 0 )
    {
      TimeElapsed = pMovieImpl->TimeElapsed;
      v15 = (double)(int)TimeElapsed;
      if ( TimeElapsed < 0 )
        v15 = v15 + 1.844674407370955e19;
      Scaleform::GFx::Text::EditorKit::Advance((Scaleform::GFx::Text::EditorKit *)v12, v15 * 0.000001);
    }
  }
  if ( (this->Flags & 0x10000) != 0 )
  {
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  }
}

// File Line: 558
// RVA: 0x8E3270
bool __fastcall Scaleform::GFx::TextField::HasStyleSheet(Scaleform::GFx::TextField *this)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v2; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0;
  v2 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 184i64))(v2);
}

// File Line: 565
// RVA: 0x8DE790
Scaleform::GFx::Text::StyleManager *__fastcall Scaleform::GFx::TextField::GetStyleSheet(
        Scaleform::GFx::TextField *this)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v2; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0i64;
  v2 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  return (Scaleform::GFx::Text::StyleManager *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 176i64))(v2);
}

// File Line: 572
// RVA: 0x8E78F0
bool __fastcall Scaleform::GFx::TextField::IsTabable(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx
  char v3; // al
  unsigned int v4; // eax
  unsigned __int8 AvmObjOffset; // cl
  __int64 v6; // rax
  bool v8; // zf
  char v9; // al

  if ( (this->pDef.pObject->Flags & 0x1000) != 0
    || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this) )
  {
    return 0;
  }
  pObject = this->pDocument.pObject->pEditorKit.pObject;
  v3 = pObject
     ? ((unsigned __int64 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))pObject->vfptr[2].__vecDelDtor)(pObject)
     : (this->pDef.pObject->Flags & 8) != 0;
  if ( v3 )
    return 0;
  v4 = this->Scaleform::GFx::InteractiveObject::Flags & 0x60;
  if ( v4 || (AvmObjOffset = this->AvmObjOffset) == 0 )
  {
    if ( !v4 || (v8 = v4 == 96, v9 = 1, v8) )
      v9 = 0;
    return v9 == 0;
  }
  else
  {
    v6 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 168i64))(v6);
  }
}

// File Line: 591
// RVA: 0x90DE40
char __fastcall Scaleform::GFx::TextField::SetTextValue(
        Scaleform::GFx::TextField *this,
        const char *pnewText,
        char html,
        bool notifyVariable)
{
  Scaleform::Render::Text::StyleManagerBase *v7; // r14
  int v8; // ebx
  Scaleform::StringLH *p_OriginalTextValue; // rdi
  unsigned __int64 v10; // rax
  const char *v11; // r10
  int v12; // ecx
  int v13; // edx
  unsigned __int8 AvmObjOffset; // al
  __int64 v16; // rax
  const char *v17; // r13
  char v18; // di
  char v19; // r15
  const char *pData; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v23; // di
  Scaleform::Render::Text::DocView *pObject; // rbx
  Scaleform::GFx::Text::StyleManager *pstyleMgr; // rax
  unsigned __int64 v26; // rbx
  Scaleform::MemoryHeap *v27; // rax
  Scaleform::Render::Text::TextFormat *v28; // rax
  Scaleform::Render::Text::ParagraphFormat *v29; // rax
  Scaleform::MemoryHeap *v30; // rax
  bool v31; // di
  Scaleform::GFx::ASStringNode *pText; // rcx
  Scaleform::Render::Text::DocView *v33; // rbx
  Scaleform::GFx::Text::StyleManager *StyleSheet; // rax
  wchar_t *v35; // rdx
  Scaleform::MemoryHeap *v36; // rax
  Scaleform::Render::Text::TextFormat *v37; // rax
  Scaleform::Render::Text::ParagraphFormat *v38; // rax
  Scaleform::MemoryHeap *v39; // rax
  unsigned __int8 v40; // al
  __int64 v41; // rax
  Scaleform::Render::Text::EditorKitBase *v42; // rcx
  unsigned __int64 Length; // rax
  Scaleform::GFx::Text::EditorKit *v44; // rcx
  unsigned __int8 v45; // al
  __int64 v46; // rax
  unsigned __int8 v47; // al
  __int64 v48; // rax
  unsigned __int8 v49; // al
  __int64 v50; // rax
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::Render::TreeText *v52; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imageInfoArray; // [rsp+40h] [rbp-C0h] BYREF
  unsigned int v54; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::ASString v55; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::Render::Text::ParagraphFormat pparaFmt; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Render::Text::ParagraphFormat *ppdestParaFmt; // [rsp+98h] [rbp-68h] BYREF
  Scaleform::Render::Text::TextFormat ptextFmt; // [rsp+A0h] [rbp-60h] BYREF
  __int64 v59; // [rsp+F0h] [rbp-10h]
  Scaleform::Render::Text::TextFormat v60; // [rsp+F8h] [rbp-8h] BYREF
  _QWORD v61[3]; // [rsp+150h] [rbp+50h] BYREF
  Scaleform::GFx::ASString v62; // [rsp+168h] [rbp+68h]
  char *v63; // [rsp+170h] [rbp+70h]
  __int64 v64; // [rsp+178h] [rbp+78h]
  char v65[1024]; // [rsp+180h] [rbp+80h] BYREF
  char *v66; // [rsp+580h] [rbp+480h]
  __int64 v67; // [rsp+588h] [rbp+488h]
  char v68[1024]; // [rsp+590h] [rbp+490h] BYREF
  Scaleform::WStringBuffer pstring; // [rsp+990h] [rbp+890h] BYREF
  Scaleform::WStringBuffer pBuffer; // [rsp+9B0h] [rbp+8B0h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+A10h] [rbp+910h] BYREF
  bool v72; // [rsp+A28h] [rbp+928h]

  v72 = notifyVariable;
  v59 = -2i64;
  v7 = 0i64;
  v8 = 0;
  v54 = 0;
  p_OriginalTextValue = &this->OriginalTextValue;
  v10 = (this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12;
  v11 = &pnewText[-v10];
  do
  {
    v12 = (unsigned __int8)v11[v10];
    v13 = *(unsigned __int8 *)v10 - v12;
    if ( v13 )
      break;
    ++v10;
  }
  while ( v12 );
  if ( !v13 && (this->Flags & 0x10000) == 0 )
    return 0;
  this->Flags &= ~0x10000u;
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v16 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v16 + 184i64))(v16) )
    {
      html = 1;
      this->Flags |= 2u;
    }
  }
  Scaleform::String::operator=(p_OriginalTextValue, pnewText);
  if ( html )
    this->Flags |= 0x1000u;
  else
    this->Flags &= ~0x1000u;
  v17 = (const char *)((p_OriginalTextValue->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v18 = 0;
  v19 = 0;
  if ( (this->Flags & 8) != 0 )
    goto LABEL_46;
  Scaleform::GFx::StateBag::GetTranslator(&this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag, &result);
  if ( result.pObject )
  {
    if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags & 2) != 0 )
    {
      pData = &customCaption;
    }
    else
    {
      v8 = 1;
      v54 = 1;
      pData = Scaleform::GFx::DisplayObject::GetName(this, &v55)->pNode->pData;
    }
    v61[0] = 0i64;
    LOBYTE(v62.pNode) = 0;
    v63 = v65;
    v64 = 512i64;
    v66 = v68;
    v67 = 512i64;
    pstring.pText = (wchar_t *)v65;
    pstring.Length = 0i64;
    pstring.Reserved.pBuffer = (wchar_t *)v65;
    pstring.Reserved.Size = 512i64;
    pBuffer.pText = (wchar_t *)v68;
    pBuffer.Length = 0i64;
    pBuffer.Reserved.pBuffer = (wchar_t *)v68;
    pBuffer.Reserved.Size = 512i64;
    v61[1] = &pstring;
    v61[2] = pData;
    if ( (v8 & 1) != 0 )
    {
      v54 = v8 & 0xFFFFFFFE;
      pNode = v55.pNode;
      if ( v55.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
    if ( !html
      || (((__int64 (__fastcall *)(Scaleform::GFx::Translator *))result.pObject->vfptr[1].__vecDelDtor)(result.pObject) & 1) != 0 )
    {
      v26 = (int)(Scaleform::UTF8Util::GetLength(v17, -1i64) + 1);
      Scaleform::WStringBuffer::Resize(&pBuffer, v26);
      Scaleform::UTF8Util::DecodeStringSafe(pBuffer.pText, v26, v17, -1i64);
      v61[0] = pBuffer.pText;
      if ( html )
        LOBYTE(v62.pNode) |= 4u;
      result.pObject->vfptr[2].__vecDelDtor(result.pObject, (unsigned int)v61);
    }
    else
    {
      v23 = (this->Flags & 0x10) != 0;
      pObject = this->pDocument.pObject;
      pstyleMgr = Scaleform::GFx::TextField::GetStyleSheet(this);
      Scaleform::Render::Text::DocView::ParseHtml(
        pObject,
        v17,
        0xFFFFFFFFFFFFFFFFui64,
        v23,
        0i64,
        pstyleMgr,
        0i64,
        0i64);
      Scaleform::Render::Text::StyledText::GetText(this->pDocument.pObject->pDocument.pObject, &pBuffer);
      if ( (((__int64 (__fastcall *)(Scaleform::GFx::Translator *))result.pObject->vfptr[1].__vecDelDtor)(result.pObject) & 2) != 0 )
        Scaleform::WStringBuffer::StripTrailingNewLines(&pBuffer);
      v61[0] = pBuffer.pText;
      result.pObject->vfptr[2].__vecDelDtor(result.pObject, (unsigned int)v61);
      v18 = 0;
    }
    v19 = (__int64)v62.pNode & 1;
    if ( ((__int64)v62.pNode & 1) != 0 )
    {
      if ( ((__int64)v62.pNode & 2) != 0 )
      {
        v27 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
        Scaleform::Render::Text::TextFormat::TextFormat(&ptextFmt, v27);
        pparaFmt.pAllocator = 0i64;
        pparaFmt.RefCount = 1;
        memset(&pparaFmt.pTabStops, 0, 20);
        Scaleform::GFx::TextField::GetInitialFormats(this, &ptextFmt, &pparaFmt);
        if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags & 1) == 0 )
        {
          v28 = Scaleform::Render::Text::TextFormat::Merge(
                  &ptextFmt,
                  &v60,
                  this->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject);
          Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v28);
          Scaleform::Render::Text::TextFormat::~TextFormat(&v60);
          v29 = Scaleform::Render::Text::ParagraphFormat::Merge(
                  &pparaFmt,
                  (Scaleform::Render::Text::ParagraphFormat *)&v60,
                  this->pDocument.pObject->pDocument.pObject->pDefaultParagraphFormat.pObject);
          Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v29);
          Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat((Scaleform::Render::Text::ParagraphFormat *)&v60);
        }
        v30 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
        ppdestParaFmt = (Scaleform::Render::Text::ParagraphFormat *)&imageInfoArray;
        memset(&imageInfoArray, 0, 24);
        imageInfoArray.Data.pHeap = v30;
        v31 = (this->Flags & 0x10) != 0;
        pText = (Scaleform::GFx::ASStringNode *)byte_1416A7BD8;
        if ( pstring.pText )
          pText = (Scaleform::GFx::ASStringNode *)pstring.pText;
        v55.pNode = pText;
        v33 = this->pDocument.pObject;
        StyleSheet = Scaleform::GFx::TextField::GetStyleSheet(this);
        Scaleform::Render::Text::DocView::ParseHtml(
          v33,
          (const wchar_t *)v55.pNode,
          0xFFFFFFFFFFFFFFFFui64,
          v31,
          &imageInfoArray,
          StyleSheet,
          &ptextFmt,
          &pparaFmt);
        if ( imageInfoArray.Data.Size )
          Scaleform::GFx::TextField::ProcessImageTags(this, &imageInfoArray);
        ppdestParaFmt = (Scaleform::Render::Text::ParagraphFormat *)&imageInfoArray;
        Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
          imageInfoArray.Data.Data,
          imageInfoArray.Data.Size);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, imageInfoArray.Data.Data);
        Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&pparaFmt);
        Scaleform::Render::Text::TextFormat::~TextFormat(&ptextFmt);
      }
      else
      {
        Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
          this->pDocument.pObject->pDocument.pObject,
          (Scaleform::Render::Text::TextFormat **)&v55,
          &ppdestParaFmt,
          0i64);
        Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
          this->pDocument.pObject->pDocument.pObject,
          (Scaleform::Render::Text::TextFormat *)v55.pNode);
        Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
          this->pDocument.pObject->pDocument.pObject,
          ppdestParaFmt);
        v35 = (wchar_t *)byte_1416A7BD8;
        if ( pstring.pText )
          v35 = pstring.pText;
        Scaleform::Render::Text::DocView::SetText(this->pDocument.pObject, v35, 0xFFFFFFFFFFFFFFFFui64);
      }
      v18 = 1;
    }
    Scaleform::WStringBuffer::~WStringBuffer(&pBuffer);
    Scaleform::WStringBuffer::~WStringBuffer(&pstring);
  }
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( !v19 )
  {
LABEL_46:
    if ( html )
    {
      v36 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      Scaleform::Render::Text::TextFormat::TextFormat(&ptextFmt, v36);
      pparaFmt.pAllocator = 0i64;
      pparaFmt.RefCount = 1;
      memset(&pparaFmt.pTabStops, 0, 20);
      Scaleform::GFx::TextField::GetInitialFormats(this, &ptextFmt, &pparaFmt);
      if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Flags & 1) == 0 )
      {
        v37 = Scaleform::Render::Text::TextFormat::Merge(
                &ptextFmt,
                &v60,
                this->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject);
        Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v37);
        Scaleform::Render::Text::TextFormat::~TextFormat(&v60);
        v38 = Scaleform::Render::Text::ParagraphFormat::Merge(
                &pparaFmt,
                (Scaleform::Render::Text::ParagraphFormat *)&v60,
                this->pDocument.pObject->pDocument.pObject->pDefaultParagraphFormat.pObject);
        Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v38);
        Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat((Scaleform::Render::Text::ParagraphFormat *)&v60);
      }
      v39 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
      result.pObject = (Scaleform::GFx::Translator *)&imageInfoArray;
      memset(&imageInfoArray, 0, 24);
      imageInfoArray.Data.pHeap = v39;
      v40 = this->AvmObjOffset;
      if ( v40 )
      {
        v41 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                       + 4 * v40))[4].__vecDelDtor)((char *)this + 4 * v40);
        v7 = (Scaleform::Render::Text::StyleManagerBase *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v41 + 176i64))(v41);
      }
      Scaleform::Render::Text::DocView::ParseHtml(
        this->pDocument.pObject,
        v17,
        0xFFFFFFFFFFFFFFFFui64,
        (this->Flags & 0x10) != 0,
        &imageInfoArray,
        v7,
        &ptextFmt,
        &pparaFmt);
      if ( imageInfoArray.Data.Size )
        Scaleform::GFx::TextField::ProcessImageTags(this, &imageInfoArray);
      result.pObject = (Scaleform::GFx::Translator *)&imageInfoArray;
      Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
        imageInfoArray.Data.Data,
        imageInfoArray.Data.Size);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, imageInfoArray.Data.Data);
      Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&pparaFmt);
      Scaleform::Render::Text::TextFormat::~TextFormat(&ptextFmt);
    }
    else
    {
      Scaleform::Render::Text::DocView::SetText(this->pDocument.pObject, v17, 0xFFFFFFFFFFFFFFFFui64);
    }
  }
  v42 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v42 )
  {
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v42->vfptr[2].__vecDelDtor)(v42) )
    {
      Length = Scaleform::Render::Text::StyledText::GetLength(this->pDocument.pObject->pDocument.pObject);
      v44 = (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject;
      if ( v44->CursorPos > Length )
        Scaleform::GFx::Text::EditorKit::SetCursorPos(v44, Length, 0);
    }
  }
  v45 = this->AvmObjOffset;
  if ( v45 )
  {
    v46 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * v45))[4].__vecDelDtor)((char *)this + 4 * v45);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v46 + 184i64))(v46);
  }
  if ( v72 )
  {
    v47 = this->AvmObjOffset;
    if ( v47 )
    {
      v48 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                     + 4 * v47))[4].__vecDelDtor)((char *)this + 4 * v47);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v48 + 256i64))(v48);
    }
  }
  if ( v18 )
  {
    v49 = this->AvmObjOffset;
    if ( v49 )
    {
      v50 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                     + 4 * v49))[4].__vecDelDtor)((char *)this + 4 * v49);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v50 + 192i64))(v50);
    }
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  }
  this->Flags |= 0x2000u;
  v52 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v52);
  return 1;
}

// File Line: 787
// RVA: 0x913B60
Scaleform::Render::Point<float> *__fastcall Scaleform::GFx::TextField::TransformToTextRectSpace(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Point<float> *result,
        Scaleform::GFx::Value::DisplayInfo *info)
{
  __int64 v6; // rbp
  float Y; // xmm3_4
  float X; // xmm2_4
  float v9; // xmm1_4
  Scaleform::Render::Rect<float> *ViewRect; // rax
  float y1; // xmm0_4
  float v12; // xmm2_4
  Scaleform::Render::Point<float> *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  Scaleform::Render::Point<float> resulta; // [rsp+30h] [rbp+8h] BYREF

  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
  if ( (info->VarsSet & 2) != 0 )
    Y = info->Y * 20.0;
  else
    Y = (float)this->pGeomData->Y;
  if ( (info->VarsSet & 1) != 0 )
    X = info->X * 20.0;
  else
    X = (float)this->pGeomData->X;
  result->x = X;
  result->y = Y;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse((Scaleform::Render::Matrix2x4<float> *)v6, &resulta, result);
  v9 = resulta.y;
  result->x = resulta.x;
  result->y = v9;
  ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  y1 = ViewRect->y1;
  v12 = result->x - ViewRect->x1;
  v13 = result;
  v14 = result->y - y1;
  result->x = v12;
  result->y = v14;
  v15 = (float)((float)(v14 * *(float *)(v6 + 20)) + (float)(v12 * *(float *)(v6 + 16))) + *(float *)(v6 + 28);
  v16 = (float)((float)(v14 * *(float *)(v6 + 4)) + (float)(v12 * *(float *)v6)) + *(float *)(v6 + 12);
  result->y = v15 * 0.050000001;
  result->x = v16 * 0.050000001;
  return v13;
}

// File Line: 804
// RVA: 0x8DC230
void __fastcall Scaleform::GFx::TextField::GetPosition(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  double v5; // xmm7_8
  double v6; // xmm8_8
  Scaleform::Render::Cxform *v7; // rdx
  long double v8; // xmm6_8
  char v9; // al
  long double Rotation; // xmm0_8
  long double XScale; // xmm1_8
  long double YScale; // xmm0_8
  long double Z; // xmm0_8
  long double XRotation; // xmm1_8
  long double YRotation; // xmm0_8
  long double ZScale; // xmm1_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [rsp+20h] [rbp-98h] BYREF

  *(_OWORD *)&pgeomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&pgeomData.OrigMatrix.M[1][0] = _xmm;
  pgeomData.YScale = DOUBLE_100_0;
  pgeomData.XScale = DOUBLE_100_0;
  pgeomData.Rotation = 0.0;
  *(_OWORD *)&pgeomData.XRotation = 0i64;
  *(_QWORD *)&pgeomData.X = 0i64;
  *(_OWORD *)&pgeomData.Z = _xmm;
  Scaleform::GFx::TextField::UpdateAndGetGeomData(this, &pgeomData, 0);
  pObject = this->pRenNode.pObject;
  v5 = (double)pgeomData.X * 0.05;
  v6 = (double)pgeomData.Y * 0.05;
  if ( pObject )
    v7 = (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64)
                                                             + 0x20)
                                                 + 8i64
                                                 * (unsigned int)((int)((_DWORD)pObject
                                                                      - ((unsigned int)pObject & 0xFFFFF000)
                                                                      - 56)
                                                                / 56)
                                                 + 40)
                                     + 80i64);
  else
    v7 = &Scaleform::Render::Cxform::Identity;
  v8 = (float)(v7->M[0][3] * 100.0);
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this);
  Rotation = pgeomData.Rotation;
  pinfo->Visible = v9;
  XScale = pgeomData.XScale;
  pinfo->Rotation = Rotation;
  YScale = pgeomData.YScale;
  pinfo->VarsSet |= 0x7FFu;
  pinfo->YScale = YScale;
  Z = pgeomData.Z;
  pinfo->XScale = XScale;
  XRotation = pgeomData.XRotation;
  pinfo->Z = Z;
  YRotation = pgeomData.YRotation;
  pinfo->XRotation = XRotation;
  ZScale = pgeomData.ZScale;
  pinfo->X = v5;
  pinfo->Y = v6;
  pinfo->Alpha = v8;
  pinfo->YRotation = YRotation;
  pinfo->ZScale = ZScale;
}

// File Line: 822
// RVA: 0x8DE860
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::TextField::GetText(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::ASString *result,
        bool reqHtml)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringManager *v7; // rbp
  unsigned __int8 AvmObjOffset; // cl
  __int64 v9; // rax
  Scaleform::Render::Text::DocView *v10; // rcx
  Scaleform::String *Html; // rax
  Scaleform::String::DataDesc *pData; // rdx
  Scaleform::String *Text; // rax
  Scaleform::String *v14; // rax
  Scaleform::String v16; // [rsp+28h] [rbp-30h] BYREF
  __int64 v17; // [rsp+30h] [rbp-28h]
  Scaleform::String resulta; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v19; // [rsp+68h] [rbp+10h]
  Scaleform::String v20; // [rsp+78h] [rbp+20h] BYREF

  v19 = result;
  v17 = -2i64;
  pObject = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v7 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
  if ( reqHtml )
  {
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v9 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v9 + 184i64))(v9) )
      {
        Scaleform::GFx::ASStringManager::CreateString(v7, result, &this->OriginalTextValue);
        return result;
      }
    }
    v10 = this->pDocument.pObject;
    if ( (this->Flags & 2) != 0 )
    {
      Html = Scaleform::Render::Text::DocView::GetHtml(v10, &resulta);
      Scaleform::GFx::ASStringManager::CreateString(v7, result, Html);
      pData = resulta.pData;
    }
    else
    {
      Text = Scaleform::Render::Text::DocView::GetText(v10, &v20);
      Scaleform::GFx::ASStringManager::CreateString(v7, result, Text);
      pData = v20.pData;
    }
  }
  else
  {
    v14 = Scaleform::Render::Text::DocView::GetText(this->pDocument.pObject, &v16);
    Scaleform::GFx::ASStringManager::CreateString(v7, result, v14);
    pData = v16.pData;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return result;
}

// File Line: 847
// RVA: 0x8D9B70
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::TextField::GetHtml(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringManager *v5; // rdi
  Scaleform::String *Html; // rax
  Scaleform::String resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v9; // [rsp+48h] [rbp+10h]

  v9 = result;
  pObject = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v5 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
  Html = Scaleform::Render::Text::DocView::GetHtml(this->pDocument.pObject, &resulta);
  Scaleform::GFx::ASStringManager::CreateString(v5, result, Html);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((resulta.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return result;
}

// File Line: 856
// RVA: 0x8E05B0
__int64 __fastcall Scaleform::GFx::TextField::GetTopMostMouseEntity(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  __int64 result; // rax
  Scaleform::GFx::DisplayObject *Mask; // rax
  __int64 v8; // r8
  Scaleform::GFx::DisplayObject *v9; // r14
  Scaleform::GFx::DisplayObjectBase *v10; // rcx
  float *v11; // rax
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float v16; // xmm0_4
  float v17; // xmm2_4
  _OWORD *v18; // rax
  Scaleform::GFx::InteractiveObject *v19; // rcx
  float *v20; // rax
  __int64 v21; // r8
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm3_4
  float v25; // xmm4_4
  float v26; // xmm11_4
  float v27; // xmm12_4
  float v28; // xmm5_4
  float v29; // xmm10_4
  float v30; // xmm11_4
  float v31; // xmm12_4
  float v32; // xmm13_4
  float v33; // xmm14_4
  float *v34; // rax
  Scaleform::GFx::DisplayObjectBase *pParent; // rcx
  Scaleform::Render::Matrix3x4<float> *v36; // rax
  Scaleform::Render::ScreenToWorld *p_ScreenToWorld; // rbx
  Scaleform::Render::Text::DocView *pObject; // rcx
  Scaleform::GFx::InteractiveObject *v39; // rbx
  unsigned __int8 AvmObjOffset; // al
  __int64 v41; // rax
  Scaleform::GFx::InteractiveObject *pIgnoreMC; // rax
  float y; // xmm1_4
  _BYTE pmat[48]; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Render::Matrix3x4<float> v45; // [rsp+60h] [rbp-A0h] BYREF
  int Dst[16]; // [rsp+90h] [rbp-70h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::Render::Point<float> p; // [rsp+1C0h] [rbp+C0h] BYREF
  Scaleform::Render::Point<float> ptOut; // [rsp+1D0h] [rbp+D0h] BYREF

  pdescr->pResult = 0i64;
  if ( (this->pDef.pObject->Flags & 0x1000) != 0
    || (this->Scaleform::GFx::InteractiveObject::Flags & 0x800) != 0
    || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this)
    || pdescr->pIgnoreMC == this )
  {
    return 2i64;
  }
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &p, pt, 1, 0i64);
  Mask = Scaleform::GFx::DisplayObject::GetMask(this);
  v9 = Mask;
  if ( Mask
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))Mask->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(Mask)
    && (v9->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
  {
    if ( Scaleform::GFx::DisplayObjectBase::Has3D(v9) )
    {
      memset(pmat, 0, sizeof(pmat));
      *(_DWORD *)pmat = 1065353216;
      *(_DWORD *)&pmat[20] = 1065353216;
      *(_DWORD *)&pmat[40] = 1065353216;
      memset(Dst, 0, sizeof(Dst));
      Dst[0] = 1065353216;
      Dst[5] = 1065353216;
      Dst[10] = 1065353216;
      Dst[15] = 1065353216;
      memset(&v45, 0, sizeof(v45));
      pParent = v9->pParent;
      v45.M[0][0] = 1.0;
      v45.M[1][1] = 1.0;
      v45.M[2][2] = 1.0;
      if ( pParent )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(pParent, &v45);
        v36 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v9->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(v9);
        m1 = v45;
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v45, &m1, v36);
      }
      else
      {
        v45 = *(Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v9->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(v9);
      }
      p_ScreenToWorld = &this->pASRoot->pMovieImpl->ScreenToWorld;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, int *, _QWORD))v9->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[6].__vecDelDtor)(
             v9,
             Dst,
             0i64) )
      {
        LODWORD(p_ScreenToWorld->MatProj.M[0][0]) = Dst[0];
        LODWORD(p_ScreenToWorld->MatProj.M[0][1]) = Dst[1];
        LODWORD(p_ScreenToWorld->MatProj.M[0][2]) = Dst[2];
        LODWORD(p_ScreenToWorld->MatProj.M[0][3]) = Dst[3];
        LODWORD(p_ScreenToWorld->MatProj.M[1][0]) = Dst[4];
        LODWORD(p_ScreenToWorld->MatProj.M[1][1]) = Dst[5];
        LODWORD(p_ScreenToWorld->MatProj.M[1][2]) = Dst[6];
        LODWORD(p_ScreenToWorld->MatProj.M[1][3]) = Dst[7];
        LODWORD(p_ScreenToWorld->MatProj.M[2][0]) = Dst[8];
        LODWORD(p_ScreenToWorld->MatProj.M[2][1]) = Dst[9];
        LODWORD(p_ScreenToWorld->MatProj.M[2][2]) = Dst[10];
        LODWORD(p_ScreenToWorld->MatProj.M[2][3]) = Dst[11];
        LODWORD(p_ScreenToWorld->MatProj.M[3][0]) = Dst[12];
        LODWORD(p_ScreenToWorld->MatProj.M[3][1]) = Dst[13];
        LODWORD(p_ScreenToWorld->MatProj.M[3][2]) = Dst[14];
        LODWORD(p_ScreenToWorld->MatProj.M[3][3]) = Dst[15];
      }
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, _BYTE *, _QWORD))v9->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[9].__vecDelDtor)(
             v9,
             pmat,
             0i64) )
      {
        *(_OWORD *)&p_ScreenToWorld->MatView.M[0][0] = *(_OWORD *)pmat;
        *(_OWORD *)&p_ScreenToWorld->MatView.M[1][0] = *(_OWORD *)&pmat[16];
        p_ScreenToWorld->MatView.M[2][0] = *(float *)&pmat[32];
        p_ScreenToWorld->MatView.M[2][1] = *(float *)&pmat[36];
        p_ScreenToWorld->MatView.M[2][2] = *(float *)&pmat[40];
        p_ScreenToWorld->MatView.M[2][3] = *(float *)&pmat[44];
      }
      p_ScreenToWorld->MatWorld = v45;
      Scaleform::Render::ScreenToWorld::GetWorldPoint(p_ScreenToWorld, &ptOut);
    }
    else
    {
      v10 = v9->pParent;
      *(_OWORD *)&v45.M[0][0] = _xmm;
      *(__m128 *)&v45.M[1][0] = _xmm;
      *(_OWORD *)pmat = _xmm;
      *(__m128 *)&pmat[16] = _xmm;
      if ( v10 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v10, (Scaleform::Render::Matrix2x4<float> *)pmat);
        v11 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v9->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(v9);
        v12 = *(float *)pmat;
        v13 = *(float *)&pmat[4];
        v14 = *(float *)&pmat[16];
        v15 = *(float *)&pmat[20];
        *(float *)pmat = (float)(*(float *)&pmat[4] * v11[4]) + (float)(*(float *)pmat * *v11);
        *(float *)&pmat[16] = (float)(*(float *)&pmat[20] * v11[4]) + (float)(*(float *)&pmat[16] * *v11);
        *(float *)&pmat[4] = (float)(v12 * v11[1]) + (float)(*(float *)&pmat[4] * v11[5]);
        v16 = *(float *)&pmat[20] * v11[5];
        v17 = v14 * v11[1];
        *(_DWORD *)&pmat[8] = 0;
        *(_QWORD *)&pmat[20] = COERCE_UNSIGNED_INT(v17 + v16);
        *(float *)&pmat[12] = *(float *)&pmat[12] + (float)((float)(v13 * v11[7]) + (float)(v12 * v11[3]));
        *(float *)&pmat[28] = *(float *)&pmat[28] + (float)((float)(v15 * v11[7]) + (float)(v14 * v11[3]));
      }
      else
      {
        v18 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v9->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(v9);
        *(_OWORD *)pmat = *v18;
        *(_OWORD *)&pmat[16] = v18[1];
      }
      Scaleform::Render::Matrix2x4<float>::SetInverse(
        (Scaleform::Render::Matrix2x4<float> *)&v45,
        (Scaleform::Render::Matrix2x4<float> *)pmat);
      v19 = this->pParent;
      *(_OWORD *)pmat = _xmm;
      *(__m128 *)&pmat[16] = _xmm;
      if ( v19 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v19, (Scaleform::Render::Matrix2x4<float> *)pmat);
        v20 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
        v22 = *(float *)pmat;
        v23 = *(float *)&pmat[4];
        v24 = *(float *)&pmat[16];
        v25 = *(float *)&pmat[20];
        v26 = *(float *)pmat;
        v27 = *(float *)&pmat[16];
        v28 = (float)(*(float *)pmat * *v20) + (float)(*(float *)&pmat[4] * v20[4]);
        *(float *)pmat = v28;
        v29 = (float)(*(float *)&pmat[16] * *v20) + (float)(*(float *)&pmat[20] * v20[4]);
        *(float *)&pmat[16] = v29;
        v30 = (float)(v26 * v20[1]) + (float)(*(float *)&pmat[4] * v20[5]);
        *(_QWORD *)&pmat[4] = LODWORD(v30);
        v31 = (float)(v27 * v20[1]) + (float)(*(float *)&pmat[20] * v20[5]);
        *(_QWORD *)&pmat[20] = LODWORD(v31);
        v32 = *(float *)&pmat[12] + (float)((float)(v23 * v20[7]) + (float)(v22 * v20[3]));
        *(float *)&pmat[12] = v32;
        v33 = *(float *)&pmat[28] + (float)((float)(v25 * v20[7]) + (float)(v24 * v20[3]));
      }
      else
      {
        v34 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
        v28 = *v34;
        *(float *)pmat = *v34;
        v30 = v34[1];
        *(_QWORD *)&pmat[4] = *(_QWORD *)(v34 + 1);
        v32 = v34[3];
        *(float *)&pmat[12] = v32;
        v29 = v34[4];
        *(float *)&pmat[16] = v29;
        v31 = v34[5];
        *(_QWORD *)&pmat[20] = *(_QWORD *)(v34 + 5);
        v33 = v34[7];
      }
      ptOut.x = (float)((float)((float)((float)(v45.M[0][1] * v29) + (float)(v45.M[0][0] * v28)) * p.x)
                      + (float)((float)((float)(v45.M[0][1] * v31) + (float)(v45.M[0][0] * v30)) * p.y))
              + (float)(v45.M[0][3] + (float)((float)(v45.M[0][1] * v33) + (float)(v45.M[0][0] * v32)));
      ptOut.y = (float)((float)((float)((float)(v45.M[1][1] * v29) + (float)(v45.M[1][0] * v28)) * p.x)
                      + (float)((float)((float)(v45.M[1][1] * v31) + (float)(v45.M[1][0] * v30)) * p.y))
              + (float)(v45.M[1][3] + (float)((float)(v45.M[1][1] * v33) + (float)(v45.M[1][0] * v32)));
    }
    LOBYTE(v21) = 1;
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Point<float> *, __int64))v9->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
            v9,
            &ptOut,
            v21) )
    {
      pdescr->pResult = 0i64;
      return 2i64;
    }
  }
  if ( this->ClipDepth )
    goto LABEL_43;
  LOBYTE(v8) = 1;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *, Scaleform::Render::Point<float> *, __int64))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
          this,
          &p,
          v8) )
    goto LABEL_43;
  if ( !pdescr->TestAll && !Scaleform::GFx::TextField::IsSelectable(this) )
  {
    if ( Scaleform::GFx::TextField::IsSelectable(this)
      || (this->Flags & 2) == 0
      || (pObject = this->pDocument.pObject, (pObject->pDocument.pObject->RTFlags & 1) == 0)
      || !(unsigned __int8)Scaleform::Render::Text::DocView::IsUrlAtPoint(pObject, p.x, p.y, 0i64) )
    {
      v39 = this->pParent;
      if ( v39 )
      {
        while ( (v39->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
        {
          if ( pdescr->TestAll
            || (AvmObjOffset = v39->AvmObjOffset) != 0
            && (v41 = ((__int64 (__fastcall *)(__int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v39->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                                + 4 * AvmObjOffset))[1].__vecDelDtor)((__int64)v39 + 4 * AvmObjOffset),
                (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v41 + 96i64))(v41)) )
          {
            pIgnoreMC = pdescr->pIgnoreMC;
            if ( !pIgnoreMC || v39 != pIgnoreMC )
            {
              pdescr->pResult = v39;
              return 1i64;
            }
          }
          v39 = v39->pParent;
          if ( !v39 )
            break;
        }
      }
LABEL_43:
      y = p.y;
      result = 3i64;
      pdescr->LocalPt.x = p.x;
      pdescr->LocalPt.y = y;
      pdescr->pResult = 0i64;
      return result;
    }
  }
  pdescr->pResult = this;
  return 1i64;
}

// File Line: 948
// RVA: 0x8D66B0
__int64 __fastcall Scaleform::GFx::TextField::GetCursorType(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rdx
  char v3; // al
  unsigned __int8 AvmObjOffset; // al
  __int64 v5; // rax

  if ( (this->Flags & 0x20) != 0 )
    return 1i64;
  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    v3 = LOBYTE(pObject[10].vfptr) >> 1;
  else
    v3 = LOBYTE(this->pDef.pObject->Flags) >> 5;
  if ( (v3 & 1) != 0 )
    return 2i64;
  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0i64;
  v5 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 104i64))(v5);
}

// File Line: 957
// RVA: 0x8E7A80
bool __fastcall Scaleform::GFx::TextField::IsUrlUnderMouseCursor(
        Scaleform::GFx::TextField *this,
        unsigned int mouseIndex,
        Scaleform::Render::Point<float> *pPnt,
        Scaleform::Range *purlRangePos)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  __int64 v9; // rax
  float v10; // xmm11_4
  float v11; // xmm12_4
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  float *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm9_4
  float v18; // xmm7_4
  float v19; // xmm4_4
  float v20; // xmm10_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm8_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  float *v27; // rax
  float v28; // xmm1_4
  float v29; // xmm2_4
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+20h] [rbp-79h] BYREF
  Scaleform::Render::Matrix2x4<float> v31; // [rsp+40h] [rbp-59h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [rsp+60h] [rbp-39h] BYREF

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( !pMovieImpl )
    return 0;
  if ( mouseIndex < 6 )
    v9 = (__int64)&pMovieImpl->mMouseState[mouseIndex];
  else
    v9 = 0i64;
  v10 = *(float *)(v9 + 56);
  v11 = *(float *)(v9 + 60);
  pParent = this->pParent;
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, &pmat);
    v13 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    v14 = pmat.M[0][0];
    v15 = pmat.M[0][1];
    v16 = pmat.M[1][0];
    v17 = 0.0;
    v18 = pmat.M[0][0];
    v19 = pmat.M[1][1];
    v20 = 0.0;
    v21 = (float)(pmat.M[0][0] * *v13) + (float)(pmat.M[0][1] * v13[4]);
    pmat.M[0][0] = v21;
    v22 = (float)(pmat.M[1][1] * v13[4]) + (float)(pmat.M[1][0] * *v13);
    pmat.M[1][0] = v22;
    v23 = (float)(v18 * v13[1]) + (float)(pmat.M[0][1] * v13[5]);
    *(_QWORD *)&pmat.M[0][1] = LODWORD(v23);
    v24 = (float)(v16 * v13[1]) + (float)(pmat.M[1][1] * v13[5]);
    *(_QWORD *)&pmat.M[1][1] = LODWORD(v24);
    v25 = pmat.M[0][3] + (float)((float)(v15 * v13[7]) + (float)(v14 * v13[3]));
    pmat.M[0][3] = v25;
    v26 = pmat.M[1][3] + (float)((float)(v19 * v13[7]) + (float)(v16 * v13[3]));
  }
  else
  {
    v27 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    v21 = *v27;
    pmat.M[0][0] = *v27;
    v23 = v27[1];
    pmat.M[0][1] = v23;
    v20 = v27[2];
    pmat.M[0][2] = v20;
    v25 = v27[3];
    pmat.M[0][3] = v25;
    v22 = v27[4];
    pmat.M[1][0] = v22;
    v24 = v27[5];
    pmat.M[1][1] = v24;
    v17 = v27[6];
    pmat.M[1][2] = v17;
    v26 = v27[7];
  }
  pmat.M[1][3] = v26;
  *(_QWORD *)&v31.M[0][0] = __PAIR64__(LODWORD(v23), LODWORD(v21));
  *(_QWORD *)&v31.M[0][2] = __PAIR64__(LODWORD(v25), LODWORD(v20));
  *(_QWORD *)&v31.M[1][0] = __PAIR64__(LODWORD(v24), LODWORD(v22));
  *(_QWORD *)&v31.M[1][2] = __PAIR64__(LODWORD(v26), LODWORD(v17));
  *(_QWORD *)&m.M[0][0] = __PAIR64__(LODWORD(v23), LODWORD(v21));
  *(_QWORD *)&m.M[0][2] = __PAIR64__(LODWORD(v25), LODWORD(v20));
  *(_QWORD *)&m.M[1][0] = __PAIR64__(LODWORD(v24), LODWORD(v22));
  *(_QWORD *)&m.M[1][2] = __PAIR64__(LODWORD(v26), LODWORD(v17));
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v31, &m);
  v28 = (float)((float)(v31.M[0][1] * v11) + (float)(v31.M[0][0] * v10)) + v31.M[0][3];
  v29 = (float)((float)(v31.M[1][1] * v11) + (float)(v31.M[1][0] * v10)) + v31.M[1][3];
  if ( pPnt )
  {
    pPnt->x = v28;
    pPnt->y = v29;
  }
  return Scaleform::Render::Text::DocView::IsUrlAtPoint(this->pDocument.pObject, v28, v29, purlRangePos);
}

// File Line: 1065
// RVA: 0x8F3F40
void __fastcall Scaleform::GFx::TextField::PropagateMouseEvent(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // r14
  __int64 ControllerIndex; // rax
  __int64 v6; // rsi
  Scaleform::GFx::MouseState *v7; // rcx
  Scaleform::GFx::TextField *pObject; // rax
  unsigned __int8 AvmObjOffset; // cl
  __int64 v10; // rax
  Scaleform::Render::Text::DocView *v11; // rax
  unsigned int v12; // eax
  __int64 v13; // rax
  Scaleform::GFx::InteractiveObject *v14; // rcx
  float *v15; // rax
  float v16; // xmm3_4
  float v17; // xmm4_4
  float v18; // xmm5_4
  float v19; // xmm6_4
  __int64 v20; // rax
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  float *v22; // rax
  float v23; // xmm3_4
  float v24; // xmm4_4
  float v25; // xmm5_4
  float v26; // xmm6_4
  float v27; // xmm1_4
  __int64 v28; // rax
  Scaleform::GFx::InteractiveObject *v29; // rcx
  float *v30; // rax
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm1_4
  unsigned int Flags; // edx
  unsigned int v37; // eax
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-30h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> result; // [rsp+90h] [rbp+30h] BYREF
  Scaleform::Render::Point<float> p; // [rsp+A0h] [rbp+40h] BYREF
  Scaleform::Render::Point<float> v41; // [rsp+A8h] [rbp+48h] BYREF

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( pMovieImpl && (this->pDef.pObject->Flags & 0x1000) == 0 )
  {
    if ( id->Id == 8 )
      Scaleform::GFx::InteractiveObject::DoMouseDrag(this, id->ControllerIndex);
    ControllerIndex = (unsigned int)id->ControllerIndex;
    v6 = 0i64;
    if ( (unsigned int)ControllerIndex < 6 )
      v7 = &pMovieImpl->mMouseState[ControllerIndex];
    else
      v7 = 0i64;
    Scaleform::GFx::MouseState::GetTopmostEntity(v7, &result);
    pObject = (Scaleform::GFx::TextField *)result.pObject;
    if ( result.pObject != this || id->Id == 0x4000 )
    {
      AvmObjOffset = this->AvmObjOffset;
      if ( AvmObjOffset )
      {
        v10 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                       + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 184i64))(v10);
        pObject = (Scaleform::GFx::TextField *)result.pObject;
      }
    }
    if ( pObject != this )
    {
      v11 = this->pDocument.pObject;
      if ( !v11->pEditorKit.pObject || ((__int64)v11->pEditorKit.pObject[10].vfptr & 0x20) == 0 )
        goto LABEL_53;
    }
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this) )
      goto LABEL_54;
    v12 = id->Id;
    if ( id->Id != 8 )
    {
      if ( v12 == 16 )
      {
        if ( this->pDocument.pObject->pEditorKit.pObject )
        {
          v20 = (unsigned int)id->ControllerIndex;
          if ( (unsigned int)v20 < 6 )
            v6 = (__int64)&pMovieImpl->mMouseState[v20];
          *(_OWORD *)&pmat.M[0][0] = _xmm;
          *(__m128 *)&pmat.M[1][0] = _xmm;
          pParent = this->pParent;
          if ( pParent )
          {
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, &pmat);
            v22 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
            v23 = pmat.M[0][0];
            v24 = pmat.M[0][1];
            v25 = pmat.M[1][0];
            v26 = pmat.M[1][1];
            pmat.M[0][0] = (float)(pmat.M[0][1] * v22[4]) + (float)(pmat.M[0][0] * *v22);
            pmat.M[1][0] = (float)(pmat.M[1][1] * v22[4]) + (float)(pmat.M[1][0] * *v22);
            pmat.M[0][1] = (float)(v23 * v22[1]) + (float)(pmat.M[0][1] * v22[5]);
            pmat.M[1][1] = (float)(v25 * v22[1]) + (float)(pmat.M[1][1] * v22[5]);
            pmat.M[1][2] = 0.0;
            pmat.M[0][2] = 0.0;
            pmat.M[0][3] = pmat.M[0][3] + (float)((float)(v24 * v22[7]) + (float)(v23 * v22[3]));
            pmat.M[1][3] = pmat.M[1][3] + (float)((float)(v26 * v22[7]) + (float)(v25 * v22[3]));
          }
          else
          {
            pmat = *(Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
          }
          v27 = *(float *)(v6 + 60);
          p.x = *(float *)(v6 + 56);
          p.y = v27;
          Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &v41, &p);
          Scaleform::GFx::Text::EditorKit::OnMouseDown(
            (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
            COERCE_DOUBLE((unsigned __int64)LODWORD(v41.x)),
            COERCE_DOUBLE((unsigned __int64)LODWORD(v41.y)),
            *(_DWORD *)(v6 + 48));
          goto LABEL_28;
        }
      }
      else if ( (v12 == 32 || v12 == 4096) && this->pDocument.pObject->pEditorKit.pObject )
      {
        v13 = (unsigned int)id->ControllerIndex;
        if ( (unsigned int)v13 < 6 )
          v6 = (__int64)&pMovieImpl->mMouseState[v13];
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        v14 = this->pParent;
        if ( v14 )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v14, &pmat);
          v15 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
          v16 = pmat.M[0][0];
          v17 = pmat.M[0][1];
          v18 = pmat.M[1][0];
          v19 = pmat.M[1][1];
          pmat.M[0][0] = (float)(pmat.M[0][1] * v15[4]) + (float)(pmat.M[0][0] * *v15);
          pmat.M[1][0] = (float)(pmat.M[1][1] * v15[4]) + (float)(pmat.M[1][0] * *v15);
          pmat.M[0][1] = (float)(pmat.M[0][1] * v15[5]) + (float)(v16 * v15[1]);
          pmat.M[1][1] = (float)(v18 * v15[1]) + (float)(pmat.M[1][1] * v15[5]);
          pmat.M[1][2] = 0.0;
          pmat.M[0][2] = 0.0;
          pmat.M[0][3] = pmat.M[0][3] + (float)((float)(v17 * v15[7]) + (float)(v16 * v15[3]));
          pmat.M[1][3] = pmat.M[1][3] + (float)((float)(v19 * v15[7]) + (float)(v18 * v15[3]));
        }
        else
        {
          pmat = *(Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
        }
        if ( (*(_BYTE *)(v6 + 48) & 1) == 0 )
          LOWORD(this->pDocument.pObject->pEditorKit.pObject[10].vfptr) &= ~0x20u;
LABEL_28:
        if ( !Scaleform::GFx::InteractiveObject::IsInPlayList(this) )
          Scaleform::GFx::InteractiveObject::AddToPlayList(this);
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(this);
      }
LABEL_53:
      this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[72].__vecDelDtor(
        this,
        (unsigned int)id);
LABEL_54:
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release(result.pObject);
      return;
    }
    v28 = (unsigned int)id->ControllerIndex;
    if ( (unsigned int)v28 < 6 )
      v6 = (__int64)&pMovieImpl->mMouseState[v28];
    if ( this->pDocument.pObject->pEditorKit.pObject )
    {
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      v29 = this->pParent;
      if ( v29 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v29, &pmat);
        v30 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
        v31 = pmat.M[0][0];
        v32 = pmat.M[0][1];
        v33 = pmat.M[1][0];
        v34 = pmat.M[1][1];
        pmat.M[0][0] = (float)(pmat.M[0][1] * v30[4]) + (float)(pmat.M[0][0] * *v30);
        pmat.M[1][0] = (float)(pmat.M[1][1] * v30[4]) + (float)(pmat.M[1][0] * *v30);
        pmat.M[0][1] = (float)(v31 * v30[1]) + (float)(pmat.M[0][1] * v30[5]);
        pmat.M[1][1] = (float)(v33 * v30[1]) + (float)(pmat.M[1][1] * v30[5]);
        pmat.M[1][2] = 0.0;
        pmat.M[0][2] = 0.0;
        pmat.M[0][3] = pmat.M[0][3] + (float)((float)(v32 * v30[7]) + (float)(v31 * v30[3]));
        pmat.M[1][3] = pmat.M[1][3] + (float)((float)(v34 * v30[7]) + (float)(v33 * v30[3]));
      }
      else
      {
        pmat = *(Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
      }
      v35 = *(float *)(v6 + 60);
      p.x = *(float *)(v6 + 56);
      p.y = v35;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &v41, &p);
      Scaleform::GFx::Text::EditorKit::OnMouseMove(
        (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
        COERCE_DOUBLE((unsigned __int64)LODWORD(v41.x)),
        COERCE_DOUBLE((unsigned __int64)LODWORD(v41.y)));
    }
    Flags = this->Flags;
    if ( (Flags & 2) != 0 && (this->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0 )
    {
      if ( Scaleform::GFx::TextField::IsUrlUnderMouseCursor(this, id->ControllerIndex, 0i64, 0i64) )
        this->Flags |= 0x20u;
      else
        this->Flags &= ~0x20u;
    }
    else
    {
      if ( (Flags & 0x20) == 0 )
        goto LABEL_53;
      this->Flags = Flags & 0xFFFFFFDF;
    }
    v37 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[116].__vecDelDtor)(this);
    Scaleform::GFx::MovieImpl::ChangeMouseCursorType(pMovieImpl, id->ControllerIndex, v37);
    goto LABEL_53;
  }
}

// File Line: 1233
// RVA: 0x8EE7D0
bool __fastcall Scaleform::GFx::TextField::OnMouseEvent(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::EventId *event)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v5; // rax

  if ( (this->pDef.pObject->Flags & 0x1000) != 0 )
    return 0;
  ((void (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[99].__vecDelDtor)(this);
  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0;
  v5 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  return (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v5 + 208i64))(v5, event);
}

// File Line: 1243
// RVA: 0x8E7090
bool __fastcall Scaleform::GFx::TextField::IsFocusAllowed(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::MovieImpl *proot,
        unsigned int controllerIdx)
{
  unsigned int FocusedControllerIdx; // eax

  if ( (this->pDef.pObject->Flags & 0x1000) != 0 )
    return 0;
  FocusedControllerIdx = this->FocusedControllerIdx;
  return (FocusedControllerIdx == -1 || FocusedControllerIdx == controllerIdx)
      && Scaleform::GFx::InteractiveObject::IsFocusAllowed(this, proot, controllerIdx);
}

// File Line: 1251
// RVA: 0x8E7000
bool __fastcall Scaleform::GFx::TextField::IsFocusAllowed(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::MovieImpl *proot,
        unsigned int controllerIdx)
{
  unsigned int FocusedControllerIdx; // eax
  unsigned int v6; // edi
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  int FocusGroupMask; // eax

  if ( (this->pDef.pObject->Flags & 0x1000) != 0 )
    return 0;
  FocusedControllerIdx = this->FocusedControllerIdx;
  if ( FocusedControllerIdx != -1 && FocusedControllerIdx != controllerIdx )
    return 0;
  v6 = (unsigned __int8)proot->FocusGroupIndexes[controllerIdx];
  if ( !this->FocusGroupMask )
  {
    pParent = this->pParent;
    if ( pParent )
      this->FocusGroupMask = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(pParent);
  }
  FocusGroupMask = this->FocusGroupMask;
  return _bittest(&FocusGroupMask, v6) != 0;
}

// File Line: 1261
// RVA: 0x8ECB70
void __fastcall Scaleform::GFx::TextField::OnFocus(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::InteractiveObject::FocusEventType *event,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        unsigned int controllerIdx)
{
  unsigned int v6; // esi
  Scaleform::GFx::TextFieldDef *pObject; // rcx
  Scaleform::Render::Text::DocView *v9; // rdx
  char v10; // cl
  __int64 Length; // rax
  Scaleform::Render::Text::DocView *v12; // rbx
  Scaleform::Render::Text::EditorKitBase *v13; // rbx
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::Render::Text::DocView *v15; // rcx
  char v16; // al
  Scaleform::GFx::VirtualKeyboardInterface *v17; // rbx
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  float *v19; // rax
  float v20; // xmm3_4
  float v21; // xmm4_4
  float v22; // xmm5_4
  float v23; // xmm6_4
  float *v24; // rax
  unsigned int v25; // xmm4_4
  unsigned int v26; // xmm3_4
  int v27; // xmm1_4
  Scaleform::Render::Text::DocView *v28; // rbx
  Scaleform::Render::TreeText *v29; // rax
  Scaleform::GFx::VirtualKeyboardInterface *v30; // rbx
  Scaleform::Render::Text::EditorKitBase *v31; // rcx
  char v32; // al
  Scaleform::Render::Text::EditorKitBase *v33; // rcx
  char v34; // al
  bool v35; // r8
  bool v36; // dl
  unsigned __int8 AvmObjOffset; // al
  __int64 *v38; // rax
  __int64 v39; // r10
  Scaleform::Render::Text::EditorKitBase *v40; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  unsigned __int16 Flags; // dx
  Scaleform::GFx::InteractiveObject *pPlayListHead; // rax
  int v44[2]; // [rsp+18h] [rbp-21h] BYREF
  unsigned __int64 v45; // [rsp+20h] [rbp-19h]
  char v46[16]; // [rsp+28h] [rbp-11h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+38h] [rbp-1h] BYREF
  Scaleform::Ptr<Scaleform::GFx::VirtualKeyboardInterface> result; // [rsp+98h] [rbp+5Fh] BYREF
  void *retaddr; // [rsp+B8h] [rbp+7Fh]

  v6 = (unsigned int)event;
  pObject = this->pDef.pObject;
  if ( (pObject->Flags & 0x1000) == 0 )
  {
    if ( (_DWORD)event == 1 )
    {
      v9 = this->pDocument.pObject;
      if ( v9->pEditorKit.pObject )
        v10 = LOBYTE(v9->pEditorKit.pObject[10].vfptr) >> 1;
      else
        v10 = LOBYTE(pObject->Flags) >> 5;
      if ( (v10 & 1) != 0 && (this->Flags & 0x400) == 0 && (_DWORD)retaddr == 2 )
      {
        Length = Scaleform::Render::Text::StyledText::GetLength(v9->pDocument.pObject);
        Scaleform::GFx::TextField::SetSelection(this, 0i64, Length);
      }
      this->FocusedControllerIdx = controllerIdx;
      v12 = this->pDocument.pObject;
      if ( v12->pEditorKit.pObject )
      {
        v13 = v12->pEditorKit.pObject;
        Scaleform::Render::Text::DocView::SetSelectionTextColor(
          (Scaleform::Render::Text::DocView *)v13[1].vfptr,
          HIDWORD(v13[9].vfptr));
        Scaleform::Render::Text::DocView::SetSelectionBackgroundColor(
          (Scaleform::Render::Text::DocView *)v13[1].vfptr,
          (unsigned int)v13[9].vfptr);
        LOWORD(v13[10].vfptr) |= 0x400u;
        RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
        Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
        v15 = this->pDocument.pObject;
        v16 = v15->pEditorKit.pObject
            ? ((__int64 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v15->pEditorKit.pObject->vfptr[2].__vecDelDtor)(v15->pEditorKit.pObject)
            : (this->pDef.pObject->Flags & 8) != 0;
        if ( !v16 )
        {
          v17 = Scaleform::GFx::StateBag::GetVirtualKeyboardInterface(
                  &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
                  &result)->pObject;
          if ( result.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
          if ( v17 )
          {
            *(_OWORD *)&pmat.M[0][0] = _xmm;
            *(__m128 *)&pmat.M[1][0] = _xmm;
            pParent = this->pParent;
            if ( pParent )
            {
              Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, &pmat);
              v19 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
              v20 = pmat.M[0][0];
              v21 = pmat.M[0][1];
              v22 = pmat.M[1][0];
              v23 = pmat.M[1][1];
              pmat.M[0][0] = (float)(pmat.M[0][0] * *v19) + (float)(pmat.M[0][1] * v19[4]);
              pmat.M[1][0] = (float)(pmat.M[1][0] * *v19) + (float)(pmat.M[1][1] * v19[4]);
              pmat.M[0][1] = (float)(v20 * v19[1]) + (float)(pmat.M[0][1] * v19[5]);
              pmat.M[1][1] = (float)(v22 * v19[1]) + (float)(pmat.M[1][1] * v19[5]);
              pmat.M[1][2] = 0.0;
              pmat.M[0][2] = 0.0;
              pmat.M[0][3] = pmat.M[0][3] + (float)((float)(v21 * v19[7]) + (float)(v20 * v19[3]));
              pmat.M[1][3] = pmat.M[1][3] + (float)((float)(v23 * v19[7]) + (float)(v22 * v19[3]));
            }
            else
            {
              pmat = *(Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
            }
            v24 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *, char *, Scaleform::Render::Matrix2x4<float> *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
                             this,
                             v46,
                             &pmat);
            *(float *)&v25 = v24[3] * 0.050000001;
            *(float *)&v26 = v24[2] * 0.050000001;
            *(float *)&v27 = v24[1] * 0.050000001;
            *(float *)v44 = *v24 * 0.050000001;
            v44[1] = v27;
            v45 = __PAIR64__(v25, v26);
            ((void (__fastcall *)(Scaleform::GFx::VirtualKeyboardInterface *, bool, int *))v17->vfptr[1].__vecDelDtor)(
              v17,
              (this->pDocument.pObject->Flags & 4) != 0,
              v44);
          }
        }
      }
    }
    else if ( !(_DWORD)event )
    {
      this->FocusedControllerIdx = -1;
      v28 = this->pDocument.pObject;
      if ( v28->pEditorKit.pObject )
      {
        if ( Scaleform::GFx::TextField::IsSelectable(this) && (this->Flags & 0x200) == 0 )
          Scaleform::Render::Text::DocView::SetSelection(
            (Scaleform::Render::Text::DocView *)v28->pEditorKit.pObject[1].vfptr,
            0i64,
            0i64,
            1);
        Scaleform::GFx::Text::EditorKit::OnKillFocus((Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject);
        v29 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
        Scaleform::Render::TreeText::NotifyLayoutChanged(v29);
        if ( !Scaleform::GFx::TextField::IsReadOnly(this) )
        {
          v30 = Scaleform::GFx::StateBag::GetVirtualKeyboardInterface(
                  &this->pASRoot->pMovieImpl->Scaleform::GFx::StateBag,
                  &result)->pObject;
          if ( result.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
          if ( v30 )
            ((void (__fastcall *)(Scaleform::GFx::VirtualKeyboardInterface *))v30->vfptr[2].__vecDelDtor)(v30);
        }
      }
    }
    v31 = this->pDocument.pObject->pEditorKit.pObject;
    if ( v31 )
      v32 = ((__int64 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v31->vfptr[2].__vecDelDtor)(v31);
    else
      v32 = (this->pDef.pObject->Flags & 8) != 0;
    if ( !v32
      || ((v33 = this->pDocument.pObject->pEditorKit.pObject) == 0i64
        ? (v34 = LOBYTE(this->pDef.pObject->Flags) >> 5)
        : (v34 = LOBYTE(v33[10].vfptr) >> 1),
          (v34 & 1) != 0) )
    {
      if ( v6 == 1 )
      {
        v35 = 1;
        v36 = 1;
      }
      else
      {
        v35 = 0;
        v36 = 0;
      }
      Scaleform::GFx::TextField::ResetBlink(this, v36, v35);
      AvmObjOffset = this->AvmObjOffset;
      if ( AvmObjOffset )
      {
        v38 = (__int64 *)((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                                  + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
        v39 = *v38;
        LODWORD(v45) = (_DWORD)retaddr;
        (*(void (__fastcall **)(__int64 *, _QWORD, Scaleform::GFx::InteractiveObject *, _QWORD, unsigned __int64))(v39 + 128))(
          v38,
          v6,
          oldOrNewFocusCh,
          controllerIdx,
          v45);
      }
      v40 = this->pDocument.pObject->pEditorKit.pObject;
      if ( v40
        && !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v40->vfptr[2].__vecDelDtor)(v40) )
      {
        this->Flags |= 0x4000u;
        if ( !this->pPlayNext && !this->pPlayPrev )
        {
          pMovieImpl = this->pASRoot->pMovieImpl;
          if ( pMovieImpl->pPlayListHead != this )
          {
            Flags = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
            if ( (Flags & 0x10) == 0 && (Flags & 0x1000) == 0 && this->Depth >= -1 )
            {
              pPlayListHead = pMovieImpl->pPlayListHead;
              if ( pPlayListHead )
              {
                pPlayListHead->pPlayPrev = this;
                this->pPlayNext = pMovieImpl->pPlayListHead;
              }
              pMovieImpl->pPlayListHead = this;
            }
          }
        }
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(this);
      }
    }
    else if ( !v6
           || this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[89].__vecDelDtor(
                this,
                (unsigned int)retaddr) )
    {
      Scaleform::GFx::InteractiveObject::OnFocus(
        this,
        (Scaleform::GFx::InteractiveObject::FocusEventType *)v6,
        oldOrNewFocusCh,
        controllerIdx,
        (Scaleform::GFx::FocusMovedType)retaddr);
    }
  }
}

// File Line: 1352
// RVA: 0x8D5400
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::TextField::GetBounds(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *t)
{
  Scaleform::Render::Rect<float> *ViewRect; // rax

  ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(t, result, ViewRect);
  return result;
}

// File Line: 1357
// RVA: 0x8F0860
bool __fastcall Scaleform::GFx::TextField::PointTestLocal(
        Scaleform::GFx::TextField *this,
        Scaleform::Render::Point<float> *pt,
        char hitTestMask)
{
  bool result; // al
  Scaleform::Render::Rect<float> *ViewRect; // rax
  float y; // xmm0_4

  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0x800) != 0
    || (hitTestMask & 2) != 0
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this) )
  {
    return 0;
  }
  ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  result = 0;
  if ( pt->x <= ViewRect->x2 && pt->x >= ViewRect->x1 )
  {
    y = pt->y;
    if ( y <= ViewRect->y2 && y >= ViewRect->y1 )
      return 1;
  }
  return result;
}

// File Line: 1367
// RVA: 0x9011C0
void __fastcall Scaleform::GFx::TextField::ResetBlink(Scaleform::GFx::TextField *this, bool state, bool blocked)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx
  Scaleform::Render::TreeText *RenderNode; // rax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
  {
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))pObject->vfptr[2].__vecDelDtor)(pObject) )
    {
      Scaleform::GFx::Text::EditorKit::ResetBlink(
        (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
        state,
        blocked);
      RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
      Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
    }
  }
}

// File Line: 1379
// RVA: 0x90BCE0
void __fastcall Scaleform::GFx::TextField::SetSelection(
        Scaleform::GFx::TextField *this,
        __int64 beginIndex,
        __int64 endIndex)
{
  Scaleform::Render::Text::DocView *pObject; // rcx
  Scaleform::Render::Text::StyledText *v7; // rcx
  signed __int64 Length; // rax
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> result; // [rsp+30h] [rbp+8h] BYREF

  if ( !this->pDocument.pObject->pEditorKit.pObject )
  {
    Scaleform::GFx::TextField::CreateEditorKit(this, &result);
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  }
  pObject = this->pDocument.pObject;
  if ( pObject->pEditorKit.pObject )
  {
    v7 = pObject->pDocument.pObject;
    if ( beginIndex < 0 )
      beginIndex = 0i64;
    if ( endIndex < 0 )
      endIndex = 0i64;
    Length = Scaleform::Render::Text::StyledText::GetLength(v7);
    if ( Length < endIndex )
      endIndex = Length;
    if ( Length < beginIndex )
      beginIndex = Length;
    Scaleform::GFx::Text::EditorKit::SetSelection(
      (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
      beginIndex,
      endIndex);
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  }
}

// File Line: 1402
// RVA: 0x8D5A10
__int64 __fastcall Scaleform::GFx::TextField::GetCaretIndex(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx
  char v3; // al
  Scaleform::Render::Text::EditorKitBase *v4; // rcx
  char v5; // al
  Scaleform::Render::Text::EditorKitBase *v6; // rax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    v3 = ((__int64 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))pObject->vfptr[2].__vecDelDtor)(pObject);
  else
    v3 = (this->pDef.pObject->Flags & 8) != 0;
  if ( (!v3
     || ((v4 = this->pDocument.pObject->pEditorKit.pObject) == 0i64
       ? (v5 = LOBYTE(this->pDef.pObject->Flags) >> 5)
       : (v5 = LOBYTE(v4[10].vfptr) >> 1),
         (v5 & 1) != 0))
    && (v6 = this->pDocument.pObject->pEditorKit.pObject) != 0i64 )
  {
    return *(_QWORD *)&v6[3].RefCount;
  }
  else
  {
    return -1i64;
  }
}

// File Line: 1416
// RVA: 0x8D4D90
void *(__fastcall *__fastcall Scaleform::GFx::TextField::GetBeginIndex(
        Scaleform::GFx::TextField *this))(Scaleform::RefCountImplCore *this, unsigned int)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rcx
  void *(__fastcall *result)(Scaleform::RefCountImplCore *, unsigned int); // rax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( !pObject )
    return 0i64;
  vfptr = pObject[1].vfptr;
  result = vfptr[8].__vecDelDtor;
  if ( (char *)vfptr[7].__vecDelDtor < (char *)result )
    return vfptr[7].__vecDelDtor;
  return result;
}

// File Line: 1428
// RVA: 0x8D73F0
void *(__fastcall *__fastcall Scaleform::GFx::TextField::GetEndIndex(
        Scaleform::GFx::TextField *this))(Scaleform::RefCountImplCore *this, unsigned int)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rcx
  void *(__fastcall *result)(Scaleform::RefCountImplCore *, unsigned int); // rax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( !pObject )
    return 0i64;
  vfptr = pObject[1].vfptr;
  result = vfptr[8].__vecDelDtor;
  if ( (char *)result < (char *)vfptr[7].__vecDelDtor )
    return vfptr[7].__vecDelDtor;
  return result;
}

// File Line: 1440
// RVA: 0x8EC760
void __fastcall Scaleform::GFx::TextField::OnEventLoad(Scaleform::GFx::TextField *this)
{
  const char *v2; // rdx
  unsigned __int8 AvmObjOffset; // al
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [rsp+20h] [rbp-68h] BYREF

  if ( Scaleform::String::GetLength(&this->pDef.pObject->DefaultText) )
    v2 = (const char *)((this->pDef.pObject->DefaultText.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  else
    v2 = &customCaption;
  Scaleform::GFx::TextField::SetTextValue(this, v2, (this->Flags & 2) != 0, 0);
  Scaleform::Render::Text::DocView::Format(this->pDocument.pObject);
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x2000u;
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    ((void (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                          + 4 * AvmObjOffset))[9].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  if ( !this->pGeomData )
  {
    *(_QWORD *)&pgeomData.X = 0i64;
    *(_OWORD *)&pgeomData.OrigMatrix.M[0][0] = _xmm;
    *(__m128 *)&pgeomData.OrigMatrix.M[1][0] = _xmm;
    pgeomData.YScale = DOUBLE_100_0;
    pgeomData.XScale = DOUBLE_100_0;
    pgeomData.Rotation = 0.0;
    *(_OWORD *)&pgeomData.XRotation = 0i64;
    *(_OWORD *)&pgeomData.Z = _xmm;
    Scaleform::GFx::TextField::UpdateAndGetGeomData(this, &pgeomData, 1);
  }
}

// File Line: 1476
// RVA: 0x8ECA90
void __fastcall Scaleform::GFx::TextField::OnEventUnload(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::TreeText *RenderNode; // rax

  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x1000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::GFx::InteractiveObject::OnEventUnload(this);
}

// File Line: 1496
// RVA: 0x916B50
Scaleform::GFx::DisplayObjectBase::GeomDataType *__fastcall Scaleform::GFx::TextField::UpdateAndGetGeomData(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::DisplayObjectBase::GeomDataType *pgeomData,
        bool force)
{
  Scaleform::Render::Rect<float> *ViewRect; // rax
  float x1; // xmm6_4
  float y1; // xmm7_4
  float *v9; // rax
  double v10; // xmm4_8
  double v11; // xmm3_8
  double v12; // xmm4_8
  double v13; // xmm3_8

  Scaleform::GFx::DisplayObjectBase::GetGeomData(this, pgeomData);
  if ( force || (this->Flags & 0x2000) != 0 )
  {
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
    x1 = ViewRect->x1;
    y1 = ViewRect->y1;
    v9 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    v10 = *v9 * x1 + v9[1] * y1 + v9[3];
    v11 = v9[4] * x1 + v9[5] * y1 + v9[7];
    if ( v10 <= 0.0 )
      v12 = v10 - 0.5;
    else
      v12 = v10 + 0.5;
    pgeomData->X = (int)v12;
    if ( v11 <= 0.0 )
      v13 = v11 - 0.5;
    else
      v13 = v11 + 0.5;
    pgeomData->Y = (int)v13;
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, pgeomData);
    this->Flags &= ~0x2000u;
  }
  return pgeomData;
}

// File Line: 1520
// RVA: 0x8EDDE0
char __fastcall Scaleform::GFx::TextField::OnKeyEvent(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  __int64 v8; // rcx
  int v9; // r15d
  unsigned __int8 AvmObjOffset; // al
  __int64 v11; // rax
  unsigned int KeyCode; // edx
  Scaleform::GFx::Text::EditorKit *v13; // rcx
  Scaleform::Render::Text::EditorKitBase *v14; // rcx
  unsigned __int8 v15; // bl
  Scaleform::Render::Text::EditorKitBase *pObject; // rbp
  Scaleform::RefCountImplCoreVtbl *vfptr; // rdi
  Scaleform::GFx::TextKeyMap::KeyMapEntry *FirstEntry; // r8
  void *(__fastcall *vecDelDtor)(Scaleform::RefCountImplCore *, unsigned int); // rdx
  __int64 v20; // rcx
  __int64 v21; // rcx
  __int16 v22; // cx
  Scaleform::KeyModifiers specKeysState; // [rsp+40h] [rbp+8h] BYREF

  if ( (this->pDef.pObject->Flags & 0x1000) != 0 )
    return 0;
  pMovieImpl = this->pASRoot->pMovieImpl;
  v8 = (unsigned __int8)pMovieImpl->FocusGroupIndexes[id->ControllerIndex];
  v9 = 1 << v8;
  if ( (*(_WORD *)pkeyMask & (unsigned __int16)(1 << v8)) != 0
    || !pMovieImpl
    || !Scaleform::GFx::FocusGroupDescr::IsFocused(&pMovieImpl->FocusGroups[v8], (Scaleform::GFx::Sprite *)this) )
  {
    return 0;
  }
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v11 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::EventId *, int *))(*(_QWORD *)v11 + 144i64))(v11, id, pkeyMask);
  }
  if ( !this->pDocument.pObject->pEditorKit.pObject
    || Scaleform::GFx::TextField::IsReadOnly(this) && !Scaleform::GFx::TextField::IsSelectable(this) )
  {
    goto LABEL_30;
  }
  if ( id->Id != 64 )
  {
    if ( id->Id == 128 )
    {
      v15 = id->KeysState.States | 0x80;
      pObject = this->pDocument.pObject->pEditorKit.pObject;
      vfptr = pObject[2].vfptr;
      if ( vfptr )
      {
        FirstEntry = Scaleform::GFx::TextKeyMap::FindFirstEntry(
                       (Scaleform::GFx::TextKeyMap *)pObject[2].vfptr,
                       id->KeyCode);
        if ( FirstEntry )
        {
          while ( FirstEntry->mState != State_Up || (FirstEntry->SpecKeysPressed & v15) != FirstEntry->SpecKeysPressed )
          {
            vecDelDtor = vfptr[3].__vecDelDtor;
            v20 = ((char *)FirstEntry - (char *)vecDelDtor) >> 4;
            if ( (char *)(v20 + 1) < (char *)vfptr[4].__vecDelDtor )
            {
              v21 = 16 * v20;
              if ( *(_DWORD *)((char *)vecDelDtor + v21 + 20) == FirstEntry->KeyCode )
              {
                FirstEntry = (Scaleform::GFx::TextKeyMap::KeyMapEntry *)((char *)vecDelDtor + v21 + 16);
                if ( FirstEntry )
                  continue;
              }
            }
            goto LABEL_30;
          }
          if ( FirstEntry->Action == KeyAct_LeaveSelectionMode )
          {
            v22 = (__int16)pObject[10].vfptr;
            if ( (v22 & 2) != 0 && (v22 & 0x40) != 0 )
              LOWORD(pObject[10].vfptr) = v22 & 0xFFBF;
          }
        }
      }
    }
    goto LABEL_30;
  }
  KeyCode = id->KeyCode;
  v13 = (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject;
  specKeysState.States = id->KeysState.States | 0x80;
  Scaleform::GFx::Text::EditorKit::OnKeyDown(v13, KeyCode, &specKeysState);
  if ( id->KeyCode != 45 )
  {
LABEL_30:
    *pkeyMask |= (unsigned __int16)v9;
    return 1;
  }
  v14 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v14 )
    Scaleform::GFx::TextField::SetOverwriteMode(this, LOBYTE(v14[10].vfptr) >> 7 == 0);
  else
    Scaleform::GFx::TextField::SetOverwriteMode(this, 1);
  *pkeyMask |= (unsigned __int16)v9;
  return 1;
}

// File Line: 1574
// RVA: 0x8EC520
char __fastcall Scaleform::GFx::TextField::OnCharEvent(
        Scaleform::GFx::TextField *this,
        unsigned int wcharCode,
        unsigned int controllerIdx)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx
  char *v8; // rcx
  __int64 v9; // rax

  if ( (this->pDef.pObject->Flags & 0x1000) != 0 )
    return 0;
  if ( this->pASRoot->pMovieImpl )
  {
    pObject = this->pDocument.pObject->pEditorKit.pObject;
    if ( pObject )
    {
      if ( (!((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))pObject->vfptr[2].__vecDelDtor)(pObject)
         || Scaleform::GFx::TextField::IsSelectable(this))
        && this->FocusedControllerIdx == controllerIdx )
      {
        v8 = (char *)this + 4 * (unsigned __int8)this->AvmObjOffset;
        v9 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 32i64))(v8);
        if ( (*(unsigned __int8 (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v9 + 216i64))(
               v9,
               (unsigned __int16)wcharCode,
               controllerIdx) )
        {
          Scaleform::GFx::Text::EditorKit::OnChar(
            (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject,
            wcharCode);
        }
      }
    }
  }
  return 1;
}

// File Line: 1591
// RVA: 0x909BB0
void __fastcall Scaleform::GFx::TextField::SetOverwriteMode(Scaleform::GFx::TextField *this, bool overwMode)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rcx

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
  {
    if ( overwMode )
      LOWORD(pObject[10].vfptr) |= 0x80u;
    else
      LOWORD(pObject[10].vfptr) &= ~0x80u;
  }
}

// File Line: 1626
// RVA: 0x8EE950
char __fastcall Scaleform::GFx::TextField::OnMouseWheelEvent(Scaleform::GFx::TextField *this, int mwDelta)
{
  signed int MaxVScroll; // edi
  Scaleform::Render::TreeText *RenderNode; // rax

  if ( (this->Flags & 0x80) == 0 )
    return 0;
  MaxVScroll = Scaleform::Render::Text::DocView::GetVScrollOffset(this->pDocument.pObject) - mwDelta;
  if ( MaxVScroll < 0 )
    MaxVScroll = 0;
  if ( MaxVScroll > (int)Scaleform::Render::Text::DocView::GetMaxVScroll(this->pDocument.pObject) )
    MaxVScroll = Scaleform::Render::Text::DocView::GetMaxVScroll(this->pDocument.pObject);
  Scaleform::Render::Text::DocView::SetVScrollOffset(this->pDocument.pObject, MaxVScroll);
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  return 1;
}

// File Line: 1647
// RVA: 0x8B1400
void __fastcall Scaleform::GFx::TextField::AddIdImageDescAssoc(
        Scaleform::GFx::TextField *this,
        const char *idStr,
        Scaleform::Render::Text::ImageDesc *pdesc)
{
  Scaleform::RefCountNTSImpl *v6; // rax
  Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pImageDescAssoc; // rcx
  Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::String v9; // [rsp+60h] [rbp+8h] BYREF
  int v10; // [rsp+70h] [rbp+18h] BYREF
  Scaleform::RefCountNTSImpl *v11; // [rsp+78h] [rbp+20h] BYREF

  v9.pData = (Scaleform::String::DataDesc *)this;
  if ( !this->pImageDescAssoc )
  {
    v10 = 2;
    v6 = (Scaleform::RefCountNTSImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::TextField *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         8i64,
                                         &v10,
                                         -2i64);
    v11 = v6;
    if ( v6 )
    {
      key.pFirst = (Scaleform::String *)v6;
      v6->vfptr = 0i64;
    }
    this->pImageDescAssoc = (Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)v6;
  }
  if ( pdesc )
    ++pdesc->RefCount;
  v11 = pdesc;
  Scaleform::String::String(&v9, idStr);
  pImageDescAssoc = this->pImageDescAssoc;
  key.pFirst = &v9;
  key.pSecond = (Scaleform::Ptr<Scaleform::Render::Text::ImageDesc> *)&v11;
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
    &pImageDescAssoc->mHash,
    pImageDescAssoc,
    &key);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v11 )
    Scaleform::RefCountNTSImpl::Release(v11);
}

// File Line: 1653
// RVA: 0x8FF840
void __fastcall Scaleform::GFx::TextField::RemoveIdImageDescAssoc(Scaleform::GFx::TextField *this, const char *idStr)
{
  Scaleform::String key; // [rsp+40h] [rbp+8h] BYREF

  if ( this->pImageDescAssoc )
  {
    Scaleform::String::String(&key, idStr);
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::String>(
      &this->pImageDescAssoc->mHash,
      &key);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((key.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 1660
// RVA: 0x8BC370
void __fastcall Scaleform::GFx::TextField::ClearIdImageDescAssoc(Scaleform::GFx::TextField *this)
{
  Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pImageDescAssoc; // rbx

  pImageDescAssoc = this->pImageDescAssoc;
  if ( pImageDescAssoc )
  {
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear(&pImageDescAssoc->mHash);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pImageDescAssoc);
    this->pImageDescAssoc = 0i64;
  }
  else
  {
    this->pImageDescAssoc = 0i64;
  }
}

// File Line: 1673
// RVA: 0x8F28D0
void __fastcall Scaleform::GFx::TextField::ProcessImageTags(
        Scaleform::GFx::TextField *this,
        Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *imageInfoArray)
{
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v4; // rax
  Scaleform::Render::ImageBase *pImage; // rbx
  __int64 v6; // rsi
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo *Data; // r13
  __int64 v8; // rax
  Scaleform::GFx::MovieDefImpl *v9; // r14
  Scaleform::String *v10; // r12
  char IsProtocolImage; // di
  unsigned __int64 v12; // rbx
  Scaleform::Log *v13; // rax
  Scaleform::GFx::ResourceLibBase *pLib; // rcx
  Scaleform::GFx::Resource *pObject; // rbx
  Scaleform::GFx::ResourceLibBase *v16; // rcx
  Scaleform::GFx::MovieImpl *v17; // rsi
  const char *v18; // rdi
  Scaleform::GFx::MovieDefImpl *v19; // rax
  unsigned __int64 v20; // rbx
  Scaleform::Log *v21; // rax
  Scaleform::GFx::ImageResource *v22; // rbx
  Scaleform::GFx::ResourceLibBase *v23; // rcx
  Scaleform::GFx::ResourceLibBase *v24; // rcx
  Scaleform::GFx::Resource *v25; // rbx
  Scaleform::GFx::ResourceLibBase *v26; // rcx
  bool v27; // si
  Scaleform::MemoryHeap *v28; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *ImageCreator; // rax
  Scaleform::GFx::ImageResource *v30; // rdi
  Scaleform::GFx::ResourceLibBase *v31; // rcx
  __int64 v32; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *ImageFileHandlerRegistry; // rdi
  __int64 *FileOpener; // rbx
  Scaleform::Ptr<Scaleform::Log> *Log; // rax
  __int64 v36; // rdx
  __int64 v37; // rax
  Scaleform::GFx::ImageCreator *v38; // rbx
  __int64 v39; // rdi
  __int64 v40; // rcx
  float v41; // xmm5_4
  float v42; // xmm4_4
  int v43; // eax
  float v44; // xmm3_4
  int v45; // eax
  float v46; // xmm2_4
  float v47; // xmm0_4
  float *v48; // rax
  float v49; // xmm2_4
  float v50; // xmm3_4
  unsigned __int64 v51; // r8
  Scaleform::GFx::ResourceLibBase *v52; // rcx
  Scaleform::GFx::ResourceLibBase *v53; // rcx
  Scaleform::GFx::ResourceLibBase *v54; // rcx
  bool v55; // zf
  __int64 v56; // [rsp+20h] [rbp-E0h]
  Scaleform::Render::ImageBase *v57; // [rsp+28h] [rbp-D8h]
  Scaleform::Ptr<Scaleform::GFx::ImageResource> result; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+38h] [rbp-C8h] BYREF
  Scaleform::LogMessageId v60; // [rsp+48h] [rbp-B8h] BYREF
  unsigned __int64 Size; // [rsp+50h] [rbp-B0h]
  int v62; // [rsp+58h] [rbp-A8h] BYREF
  int v63; // [rsp+5Ch] [rbp-A4h]
  int v64; // [rsp+60h] [rbp-A0h]
  int v65; // [rsp+64h] [rbp-9Ch]
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> v66; // [rsp+68h] [rbp-98h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v67; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> v68; // [rsp+78h] [rbp-88h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v69; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::Ptr<Scaleform::Log> v70; // [rsp+88h] [rbp-78h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v71; // [rsp+90h] [rbp-70h] BYREF
  int v72; // [rsp+98h] [rbp-68h] BYREF
  __int64 v73; // [rsp+A0h] [rbp-60h]
  int v74; // [rsp+A8h] [rbp-58h]
  int v75; // [rsp+ACh] [rbp-54h]
  __int64 v76; // [rsp+B0h] [rbp-50h]
  __int64 v77; // [rsp+B8h] [rbp-48h]
  __int64 v78; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::MovieImpl *pMovieImpl; // [rsp+C8h] [rbp-38h]
  int v80; // [rsp+D0h] [rbp-30h] BYREF
  Scaleform::MemoryHeap *v81; // [rsp+D8h] [rbp-28h]
  int v82; // [rsp+E0h] [rbp-20h]
  int v83; // [rsp+E4h] [rbp-1Ch]
  __int64 v84; // [rsp+E8h] [rbp-18h]
  __int64 v85; // [rsp+F0h] [rbp-10h]
  __int64 v86; // [rsp+F8h] [rbp-8h]
  __int64 v87; // [rsp+100h] [rbp+0h]
  __int64 v88; // [rsp+108h] [rbp+8h]
  __int64 v89; // [rsp+110h] [rbp+10h]
  Scaleform::LogMessageId id; // [rsp+1A0h] [rbp+A0h] BYREF
  Scaleform::LogMessageId v92; // [rsp+1A8h] [rbp+A8h] BYREF

  v89 = -2i64;
  Size = imageInfoArray->Data.Size;
  if ( Size )
  {
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
    v4 = imageInfoArray;
    pImage = 0i64;
    v6 = 0i64;
    v56 = 0i64;
    while ( 1 )
    {
      Data = v4->Data.Data;
      presBindData.pResource.pObject = 0i64;
      presBindData.pBinding = 0i64;
      v8 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(this);
      v9 = (Scaleform::GFx::MovieDefImpl *)v8;
      if ( v8 )
        _InterlockedExchangeAdd((volatile signed __int32 *)(v8 + 8), 1u);
      v88 = v8;
      if ( !v8 )
        goto LABEL_78;
      v10 = (Scaleform::StringDH *)((char *)&Data->Url + v6);
      IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(v10, 0i64, 0i64);
      if ( IsProtocolImage )
        goto LABEL_21;
      if ( Scaleform::GFx::MovieImpl::FindExportedResource(
             this->pASRoot->pMovieImpl,
             v9,
             &presBindData,
             (Scaleform::String *)((char *)&Data->Url + v6)) )
      {
        break;
      }
      if ( ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[76].__vecDelDtor)(this) )
      {
        v12 = v10->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
        v13 = (Scaleform::Log *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[76].__vecDelDtor)(this);
        Scaleform::Log::LogWarning(
          v13,
          "ProcessImageTags: cant find a resource for export name %s\n",
          (const char *)(v12 + 12));
      }
      if ( !_InterlockedDecrement(&v9->RefCount.Value) )
      {
        pLib = v9->pLib;
        if ( pLib )
        {
          pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v9);
          v9->pLib = 0i64;
        }
        v9->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v9, 1u);
      }
      pObject = presBindData.pResource.pObject;
      if ( !presBindData.pResource.pObject || _InterlockedDecrement(&presBindData.pResource.pObject->RefCount.Value) )
        goto LABEL_90;
      v16 = pObject->pLib;
      if ( v16 )
      {
        v16->vfptr[1].__vecDelDtor(v16, (unsigned int)pObject);
        pObject->pLib = 0i64;
      }
LABEL_18:
      pObject->vfptr->__vecDelDtor(pObject, 1u);
LABEL_90:
      v6 += 64i64;
      v56 = v6;
      v55 = Size-- == 1;
      v4 = imageInfoArray;
      pImage = 0i64;
      if ( v55 )
        return;
    }
    if ( (((__int64 (__fastcall *)(Scaleform::GFx::Resource *))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)(presBindData.pResource.pObject) & 0xFF00) == 256 )
    {
LABEL_21:
      v57 = 0i64;
      if ( IsProtocolImage )
      {
        v32 = (__int64)v9->pLoaderImpl.pObject->pWeakResourceLib.pObject->pImageHeap.pObject;
        v72 = 1;
        v73 = v32;
        v74 = 0;
        v75 = 1;
        v76 = 0i64;
        v77 = 0i64;
        v78 = 0i64;
        pMovieImpl = 0i64;
        ImageFileHandlerRegistry = Scaleform::GFx::StateBag::GetImageFileHandlerRegistry(
                                     &v9->Scaleform::GFx::StateBag,
                                     &v68);
        FileOpener = (__int64 *)Scaleform::GFx::StateBag::GetFileOpener(&v9->Scaleform::GFx::StateBag, &v66);
        Log = Scaleform::GFx::StateBag::GetLog(&v9->Scaleform::GFx::StateBag, &v70);
        v36 = (__int64)ImageFileHandlerRegistry->pObject;
        v37 = (__int64)Log->pObject;
        v77 = *FileOpener;
        v76 = v37;
        v78 = v36;
        if ( v70.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v70.pObject);
        if ( v66.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v66.pObject);
        if ( v68.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v68.pObject);
        pMovieImpl = this->pASRoot->pMovieImpl;
        v38 = Scaleform::GFx::StateBag::GetImageCreator(&v9->Scaleform::GFx::StateBag, &v69)->pObject;
        if ( v69.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v69.pObject);
        if ( !v38 )
        {
          v92.Id = 135168;
          Scaleform::LogDebugMessage(
            (Scaleform::LogMessageId)&v92,
            "Image resource creation failed - ImageCreator not installed");
LABEL_73:
          v51 = v10->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
          v60.Id = 135168;
          Scaleform::LogDebugMessage(
            (Scaleform::LogMessageId)&v60,
            "Image %s wasnt created in ProcessImageTags",
            (const char *)(v51 + 12));
          if ( !_InterlockedDecrement(&v9->RefCount.Value) )
          {
            v52 = v9->pLib;
            if ( v52 )
            {
              v52->vfptr[1].__vecDelDtor(v52, (unsigned int)v9);
              v9->pLib = 0i64;
            }
            v9->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v9, 1u);
          }
LABEL_34:
          v25 = presBindData.pResource.pObject;
          if ( presBindData.pResource.pObject && !_InterlockedDecrement(&presBindData.pResource.pObject->RefCount.Value) )
          {
            v26 = v25->pLib;
            if ( v26 )
            {
              v26->vfptr[1].__vecDelDtor(v26, (unsigned int)v25);
              v25->pLib = 0i64;
            }
            v25->vfptr->__vecDelDtor(v25, 1u);
          }
          v6 = v56;
          goto LABEL_90;
        }
        pImage = (Scaleform::Render::ImageBase *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, __int64))v38->vfptr[1].__vecDelDtor)(
                                                   v38,
                                                   &v72,
                                                   (__int64)&Data->Url + v6);
      }
      else
      {
        v17 = this->pASRoot->pMovieImpl;
        v18 = (const char *)((v10->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
        v19 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(this);
        Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(v17, &result, v19, v18);
        if ( !result.pObject )
        {
          if ( ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[76].__vecDelDtor)(this) )
          {
            v20 = v10->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
            v21 = (Scaleform::Log *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[76].__vecDelDtor)(this);
            Scaleform::Log::LogWarning(v21, "ProcessImageTags: cant load the image %s\n", (const char *)(v20 + 12));
          }
          v22 = result.pObject;
          if ( result.pObject && !_InterlockedDecrement(&result.pObject->RefCount.Value) )
          {
            v23 = v22->pLib;
            if ( v23 )
            {
              v23->vfptr[1].__vecDelDtor(v23, (unsigned int)v22);
              v22->pLib = 0i64;
            }
            v22->vfptr->__vecDelDtor(v22, 1u);
          }
          if ( !_InterlockedDecrement(&v9->RefCount.Value) )
          {
            v24 = v9->pLib;
            if ( v24 )
            {
              v24->vfptr[1].__vecDelDtor(v24, (unsigned int)v9);
              v9->pLib = 0i64;
            }
            v9->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v9, 1u);
          }
          goto LABEL_34;
        }
        if ( ((unsigned int (__fastcall *)(Scaleform::Render::ImageBase *))result.pObject->pImage->vfptr[3].__vecDelDtor)(result.pObject->pImage) )
        {
          pImage = result.pObject->pImage;
          if ( pImage )
            ((void (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[1].__vecDelDtor)(result.pObject->pImage);
          v57 = pImage;
        }
        else
        {
          v27 = Scaleform::GFx::StateBag::GetImageCreator(&v9->Scaleform::GFx::StateBag, &v67)->pObject == 0i64;
          if ( v67.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v67.pObject);
          if ( v27 )
          {
            id.Id = 135168;
            Scaleform::LogDebugMessage((Scaleform::LogMessageId)&id, "ImageCreator is null in ProcessImageTags");
          }
          else
          {
            v28 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
            v80 = 3;
            v81 = v28;
            v82 = 1;
            v83 = 1;
            v84 = 0i64;
            v85 = 0i64;
            v86 = 0i64;
            v87 = 0i64;
            ImageCreator = Scaleform::GFx::StateBag::GetImageCreator(&v9->Scaleform::GFx::StateBag, &v71);
            pImage = (Scaleform::Render::ImageBase *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))ImageCreator->pObject->vfptr[4].__vecDelDtor)(
                                                       ImageCreator->pObject,
                                                       &v80,
                                                       result.pObject->pImage);
            v57 = pImage;
            if ( v71.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v71.pObject);
          }
        }
        v30 = result.pObject;
        if ( result.pObject )
        {
          if ( !_InterlockedDecrement(&result.pObject->RefCount.Value) )
          {
            v31 = v30->pLib;
            if ( v31 )
            {
              v31->vfptr[1].__vecDelDtor(v31, (unsigned int)v30);
              v30->pLib = 0i64;
            }
            v30->vfptr->__vecDelDtor(v30, 1u);
          }
          pImage = v57;
        }
      }
      if ( !pImage )
        goto LABEL_73;
      pImage->vfptr[6].__vecDelDtor(pImage, (unsigned int)&v62);
      v6 = v56;
      v39 = *(__int64 *)((char *)&Data->pTextImageDesc.pObject + v56);
      ((void (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[1].__vecDelDtor)(pImage);
      v40 = *(_QWORD *)(v39 + 16);
      if ( v40 )
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v40 + 16i64))(v40);
      *(_QWORD *)(v39 + 16) = pImage;
      v41 = (float)(v64 - v62);
      v42 = (float)(v65 - v63);
      v43 = *(unsigned int *)((char *)&Data->Width + v56);
      if ( !v43 )
        v43 = 20 * (v64 - v62);
      v44 = (float)v43;
      v45 = *(unsigned int *)((char *)&Data->Height + v56);
      if ( !v45 )
        v45 = 20 * (v65 - v63);
      v46 = (float)v45;
      v47 = (float)*(int *)((char *)&Data->VSpace + v56);
      (*(Scaleform::Render::Text::ImageDesc **)((char *)&Data->pTextImageDesc.pObject + v56))->ScreenWidth = v44;
      (*(Scaleform::Render::Text::ImageDesc **)((char *)&Data->pTextImageDesc.pObject + v56))->ScreenHeight = (float)v45;
      (*(Scaleform::Render::Text::ImageDesc **)((char *)&Data->pTextImageDesc.pObject + v56))->BaseLineY = (float)((float)(v42 * 20.0) + v47) * 0.050000001;
      (*(Scaleform::Render::Text::ImageDesc **)((char *)&Data->pTextImageDesc.pObject + v56))->Matrix.M[1][3] = COERCE_FLOAT(LODWORD((*(Scaleform::Render::Text::ImageDesc **)((char *)&Data->pTextImageDesc.pObject + v56))->BaseLineY) ^ _xmm[0]) + (*(Scaleform::Render::Text::ImageDesc **)((char *)&Data->pTextImageDesc.pObject + v56))->Matrix.M[1][3];
      v48 = *(float **)((char *)&Data->pTextImageDesc.pObject + v56);
      v49 = v46 / v42;
      v50 = v44 / v41;
      v48[12] = v50 * v48[12];
      v48[13] = v50 * v48[13];
      v48[14] = v50 * v48[14];
      v48[15] = v50 * v48[15];
      v48[16] = v49 * v48[16];
      v48[17] = v49 * v48[17];
      v48[18] = v49 * v48[18];
      v48[19] = v49 * v48[19];
      this->pDocument.pObject->RTFlags |= 2u;
      ((void (__fastcall *)(Scaleform::Render::ImageBase *))pImage->vfptr[2].__vecDelDtor)(pImage);
    }
    else
    {
      presBindData.pResource.pObject->vfptr->GetResourceTypeCode(presBindData.pResource.pObject);
    }
LABEL_78:
    if ( v9 && !_InterlockedDecrement(&v9->RefCount.Value) )
    {
      v53 = v9->pLib;
      if ( v53 )
      {
        v53->vfptr[1].__vecDelDtor(v53, (unsigned int)v9);
        v9->pLib = 0i64;
      }
      v9->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::vfptr->__vecDelDtor(v9, 1u);
    }
    pObject = presBindData.pResource.pObject;
    if ( !presBindData.pResource.pObject || _InterlockedDecrement(&presBindData.pResource.pObject->RefCount.Value) )
      goto LABEL_90;
    v54 = pObject->pLib;
    if ( v54 )
    {
      v54->vfptr[1].__vecDelDtor(v54, (unsigned int)pObject);
      pObject->pLib = 0i64;
    }
    goto LABEL_18;
  }
}

// File Line: 1793
// RVA: 0x900380
void __fastcall Scaleform::GFx::TextField::ReplaceText(
        Scaleform::GFx::TextField *this,
        const wchar_t *ptext,
        unsigned __int64 beginPos,
        unsigned __int64 endPos,
        unsigned __int64 textLen)
{
  Scaleform::Render::Text::DocView *pObject; // rcx
  unsigned __int64 Length; // rax
  Scaleform::GFx::Text::EditorKit *v8; // rcx
  unsigned __int8 AvmObjOffset; // al
  __int64 v10; // rax
  unsigned __int8 v11; // al
  __int64 v12; // rax
  Scaleform::Render::TreeText *RenderNode; // rax

  Scaleform::Render::Text::DocView::ReplaceText(this->pDocument.pObject, ptext, beginPos, endPos, textLen);
  pObject = this->pDocument.pObject;
  if ( pObject->pEditorKit.pObject )
  {
    Length = Scaleform::Render::Text::StyledText::GetLength(pObject->pDocument.pObject);
    v8 = (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject;
    if ( v8->CursorPos > Length )
      Scaleform::GFx::Text::EditorKit::SetCursorPos(v8, Length, 0);
  }
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v10 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 256i64))(v10);
  }
  v11 = this->AvmObjOffset;
  this->Flags |= 0x10000u;
  if ( v11 )
  {
    v12 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * v11))[4].__vecDelDtor)((char *)this + 4 * v11);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v12 + 192i64))(v12);
  }
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}

// File Line: 2301
// RVA: 0x90F940
void __fastcall Scaleform::GFx::TextField::SetX(Scaleform::GFx::TextField *this, double x)
{
  double v2; // xmm12_8
  float *v4; // rax
  double v5; // xmm12_8
  float v6; // xmm10_4
  float v7; // xmm11_4
  unsigned int v8; // xmm0_4
  float v9; // xmm9_4
  unsigned int v10; // xmm1_4
  unsigned int v11; // xmm2_4
  unsigned int v12; // xmm3_4
  unsigned int v13; // xmm4_4
  float v14; // xmm8_4
  float v15; // xmm7_4
  float v16; // xmm6_4
  Scaleform::Render::Rect<float> *ViewRect; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rcx
  double v19; // xmm12_8
  Scaleform::Render::Matrix2x4<float> v20; // [rsp+20h] [rbp-69h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [rsp+40h] [rbp-49h] BYREF

  v2 = x;
  if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 || (*(_QWORD *)&x & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    if ( x == -INFINITY || x == INFINITY )
      v2 = 0.0;
    v4 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    v5 = v2 * 20.0;
    v6 = *v4;
    v7 = v4[1];
    v8 = *((_DWORD *)v4 + 2);
    v9 = v4[3];
    v10 = *((_DWORD *)v4 + 4);
    v11 = *((_DWORD *)v4 + 5);
    v12 = *((_DWORD *)v4 + 6);
    v13 = *((_DWORD *)v4 + 7);
    *(_QWORD *)&v20.M[0][0] = __PAIR64__(LODWORD(v7), LODWORD(v6));
    *(_QWORD *)&v20.M[0][2] = __PAIR64__(LODWORD(v9), v8);
    *(_QWORD *)&v20.M[1][0] = __PAIR64__(v11, v10);
    *(_QWORD *)&v20.M[1][2] = __PAIR64__(v13, v12);
    *(_QWORD *)&m.M[0][0] = __PAIR64__(LODWORD(v7), LODWORD(v6));
    *(_QWORD *)&m.M[0][2] = __PAIR64__(LODWORD(v9), v8);
    *(_QWORD *)&m.M[1][0] = __PAIR64__(v11, v10);
    *(_QWORD *)&m.M[1][2] = __PAIR64__(v13, v12);
    v14 = v5;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v20, &m);
    v15 = (float)((float)(v20.M[1][1] * v14) + (float)(v20.M[1][0] * v14)) + v20.M[1][3];
    v16 = (float)((float)(v20.M[0][1] * v14) + (float)(v20.M[0][0] * v14)) + v20.M[0][3];
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
    Scaleform::GFx::DisplayObjectBase::SetX(
      this,
      (float)((float)((float)((float)(v7 * v15) + (float)(v6 * (float)(v16 - ViewRect->x1))) + v9) * 0.050000001));
    pGeomData = this->pGeomData;
    if ( pGeomData )
    {
      if ( v5 <= 0.0 )
        v19 = v5 - 0.5;
      else
        v19 = v5 + 0.5;
      pGeomData->X = (int)v19;
    }
  }
}

// File Line: 2327
// RVA: 0x910100
void __fastcall Scaleform::GFx::TextField::SetY(Scaleform::GFx::TextField *this, double y)
{
  double v2; // xmm12_8
  double v4; // xmm12_8
  __int64 v5; // rax
  float v6; // xmm8_4
  unsigned int v7; // xmm1_4
  unsigned int v8; // xmm2_4
  float v9; // xmm3_4
  float v10; // xmm11_4
  float v11; // xmm9_4
  unsigned int v12; // xmm4_4
  float v13; // xmm10_4
  float v14; // xmm7_4
  float v15; // xmm6_4
  Scaleform::Render::Rect<float> *ViewRect; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rcx
  double v18; // xmm12_8
  Scaleform::Render::Matrix2x4<float> v19; // [rsp+20h] [rbp-69h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [rsp+40h] [rbp-49h] BYREF

  v2 = y;
  if ( (*(_QWORD *)&y & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 || (*(_QWORD *)&y & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    if ( y == -INFINITY || y == INFINITY )
      v2 = 0.0;
    v4 = v2 * 20.0;
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    v6 = v4;
    v7 = *(_DWORD *)(v5 + 4);
    v8 = *(_DWORD *)(v5 + 8);
    v9 = *(float *)(v5 + 12);
    v10 = *(float *)(v5 + 16);
    v11 = *(float *)(v5 + 20);
    v12 = *(_DWORD *)(v5 + 24);
    v13 = *(float *)(v5 + 28);
    v19.M[0][0] = *(float *)v5;
    *(_QWORD *)&v19.M[0][1] = __PAIR64__(v8, v7);
    v19.M[0][3] = v9;
    *(_QWORD *)&v19.M[1][0] = __PAIR64__(LODWORD(v11), LODWORD(v10));
    *(_QWORD *)&v19.M[1][2] = __PAIR64__(LODWORD(v13), v12);
    *(_QWORD *)&m.M[0][0] = __PAIR64__(v7, LODWORD(v19.M[0][0]));
    *(_QWORD *)&m.M[0][2] = __PAIR64__(LODWORD(v9), v8);
    *(_QWORD *)&m.M[1][0] = __PAIR64__(LODWORD(v11), LODWORD(v10));
    *(_QWORD *)&m.M[1][2] = __PAIR64__(LODWORD(v13), v12);
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v19, &m);
    v14 = (float)((float)(v19.M[1][1] * v6) + (float)(v19.M[1][0] * 0.0)) + v19.M[1][3];
    v15 = (float)((float)(v19.M[0][1] * v6) + (float)(v19.M[0][0] * 0.0)) + v19.M[0][3];
    ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
    Scaleform::GFx::DisplayObjectBase::SetY(
      this,
      (float)((float)((float)((float)(v10 * v15) + (float)(v11 * (float)(v14 - ViewRect->y1))) + v13) * 0.050000001));
    pGeomData = this->pGeomData;
    if ( pGeomData )
    {
      if ( v4 <= 0.0 )
        v18 = v4 - 0.5;
      else
        v18 = v4 + 0.5;
      pGeomData->Y = (int)v18;
    }
  }
}

// File Line: 2352
// RVA: 0x8E1BC0
double __fastcall Scaleform::GFx::TextField::GetX(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&pgeomData.X = 0i64;
  *(_OWORD *)&pgeomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&pgeomData.OrigMatrix.M[1][0] = _xmm;
  pgeomData.YScale = DOUBLE_100_0;
  pgeomData.XScale = DOUBLE_100_0;
  pgeomData.Rotation = 0.0;
  *(_OWORD *)&pgeomData.XRotation = 0i64;
  *(_OWORD *)&pgeomData.Z = _xmm;
  Scaleform::GFx::TextField::UpdateAndGetGeomData(this, &pgeomData, 0);
  return (double)pgeomData.X * 0.05;
}

// File Line: 2359
// RVA: 0x8E1DD0
double __fastcall Scaleform::GFx::TextField::GetY(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&pgeomData.X = 0i64;
  *(_OWORD *)&pgeomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&pgeomData.OrigMatrix.M[1][0] = _xmm;
  pgeomData.YScale = DOUBLE_100_0;
  pgeomData.XScale = DOUBLE_100_0;
  pgeomData.Rotation = 0.0;
  *(_OWORD *)&pgeomData.XRotation = 0i64;
  *(_OWORD *)&pgeomData.Z = _xmm;
  Scaleform::GFx::TextField::UpdateAndGetGeomData(this, &pgeomData, 0);
  return (double)pgeomData.Y * 0.05;
}

// File Line: 2366
// RVA: 0x90F6B0
void __fastcall Scaleform::GFx::TextField::SetWidth(Scaleform::GFx::TextField *this, long double width)
{
  Scaleform::Render::Rect<float> *ViewRect; // rax
  Scaleform::Render::Text::DocView *pObject; // rcx
  float x1; // xmm3_4
  float y2; // xmm2_4
  float v7; // xmm0_4
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::Render::Rect<float> rect; // [rsp+20h] [rbp-28h] BYREF

  ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  pObject = this->pDocument.pObject;
  x1 = ViewRect->x1;
  y2 = ViewRect->y2;
  rect.y1 = ViewRect->y1;
  rect.x1 = x1;
  rect.y2 = y2;
  v7 = width * 20.0;
  rect.x2 = v7 + x1;
  Scaleform::Render::Text::DocView::SetViewRect(pObject, &rect, UseExternally);
  this->Flags |= 0x2000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}

// File Line: 2375
// RVA: 0x907BD0
void __fastcall Scaleform::GFx::TextField::SetHeight(Scaleform::GFx::TextField *this, long double height)
{
  Scaleform::Render::Rect<float> *ViewRect; // rax
  Scaleform::Render::Text::DocView *pObject; // rcx
  float y1; // xmm3_4
  float x2; // xmm2_4
  float v7; // xmm0_4
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::Render::Rect<float> rect; // [rsp+20h] [rbp-28h] BYREF

  ViewRect = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  pObject = this->pDocument.pObject;
  y1 = ViewRect->y1;
  x2 = ViewRect->x2;
  rect.x1 = ViewRect->x1;
  rect.y1 = y1;
  rect.x2 = x2;
  v7 = height * 20.0;
  rect.y2 = v7 + y1;
  Scaleform::Render::Text::DocView::SetViewRect(pObject, &rect, UseExternally);
  this->Flags |= 0x2000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}

// File Line: 2384
// RVA: 0x90FED0
void __fastcall Scaleform::GFx::TextField::SetXScale(Scaleform::GFx::TextField *this, double xscale)
{
  Scaleform::Render::TreeText *RenderNode; // rax

  this->Flags |= 0x2000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::GFx::DisplayObjectBase::SetXScale(this, xscale);
}

// File Line: 2390
// RVA: 0x9106A0
void __fastcall Scaleform::GFx::TextField::SetYScale(Scaleform::GFx::TextField *this, double yscale)
{
  Scaleform::Render::TreeText *RenderNode; // rax

  this->Flags |= 0x2000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::GFx::DisplayObjectBase::SetYScale(this, yscale);
}

// File Line: 2396
// RVA: 0x90B4B0
void __fastcall Scaleform::GFx::TextField::SetRotation(Scaleform::GFx::TextField *this, long double rotation)
{
  Scaleform::Render::TreeText *RenderNode; // rax

  this->Flags |= 0x2000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::GFx::DisplayObjectBase::SetRotation(this, rotation);
}

// File Line: 2402
// RVA: 0x9062C0
void __fastcall Scaleform::GFx::TextField::SetBackground(Scaleform::GFx::TextField *this, bool b)
{
  Scaleform::Render::Text::DocView *pObject; // r8
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::Render::TreeText *v5; // rax
  unsigned int BackgroundColor; // [rsp+38h] [rbp+10h]

  pObject = this->pDocument.pObject;
  BackgroundColor = pObject->BackgroundColor;
  HIBYTE(BackgroundColor) = -b;
  pObject->BackgroundColor = BackgroundColor;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  v5 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v5);
}

// File Line: 2413
// RVA: 0x906380
void __fastcall Scaleform::GFx::TextField::SetBackgroundColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::Render::TreeText *RenderNode; // rax

  this->pDocument.pObject->BackgroundColor ^= (rgb ^ this->pDocument.pObject->BackgroundColor) & 0xFFFFFF;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}

// File Line: 2425
// RVA: 0x906760
void __fastcall Scaleform::GFx::TextField::SetBorder(Scaleform::GFx::TextField *this, bool b)
{
  Scaleform::Render::Text::DocView *pObject; // r8
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::Render::TreeText *v5; // rax
  unsigned int BorderColor; // [rsp+38h] [rbp+10h]

  pObject = this->pDocument.pObject;
  BorderColor = pObject->BorderColor;
  HIBYTE(BorderColor) = -b;
  pObject->BorderColor = BorderColor;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  v5 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v5);
}

// File Line: 2442
// RVA: 0x9067C0
void __fastcall Scaleform::GFx::TextField::SetBorderColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::Render::TreeText *RenderNode; // rax

  this->pDocument.pObject->BorderColor ^= (rgb ^ this->pDocument.pObject->BorderColor) & 0xFFFFFF;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}

// File Line: 2448
// RVA: 0x90CA00
void __fastcall Scaleform::GFx::TextField::SetText(
        Scaleform::GFx::TextField *this,
        const wchar_t *pnewText,
        bool reqHtml)
{
  unsigned int Flags; // eax
  unsigned int v7; // eax
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rsi
  char *v10; // rdi

  Flags = this->Flags;
  if ( reqHtml )
  {
    if ( (this->Flags & 2) != 0 )
      goto LABEL_7;
    v7 = Flags | 2;
  }
  else
  {
    if ( (this->Flags & 2) == 0 )
      goto LABEL_7;
    v7 = Flags & 0xFFFFFFFD;
  }
  this->Flags = v7;
LABEL_7:
  v8 = Scaleform::SFwcslen(pnewText);
  v9 = v8 + 2 * v8 + 1;
  if ( v9 > 0x200 )
    v10 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                    Scaleform::Memory::pGlobalHeap,
                    this,
                    v8 + 2 * v8 + 1,
                    0i64);
  else
    v10 = stackBuff;
  Scaleform::UTF8Util::EncodeStringSafe(v10, v9, pnewText, -1i64);
  Scaleform::GFx::TextField::SetTextValue(this, v10, reqHtml, 1);
  if ( v10 != stackBuff )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
}

// File Line: 2470
// RVA: 0x90CAF0
void __fastcall Scaleform::GFx::TextField::SetTextColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::MemoryHeap *v4; // rax
  Scaleform::Render::TreeText *RenderNode; // rax
  Scaleform::Render::Text::TextFormat fmt; // [rsp+30h] [rbp-58h] BYREF

  v4 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  Scaleform::Render::Text::TextFormat::TextFormat(&fmt, v4);
  rgb &= 0xFFFFFFu;
  fmt.ColorV = rgb | fmt.ColorV & 0xFF000000;
  fmt.PresentMask |= 1u;
  Scaleform::Render::Text::DocView::SetTextFormat(this->pDocument.pObject, &fmt, 0i64, 0xFFFFFFFFFFFFFFFFui64);
  Scaleform::Render::Text::TextFormat::operator=(
    &fmt,
    this->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject);
  fmt.ColorV = rgb | fmt.ColorV & 0xFF000000;
  fmt.PresentMask |= 1u;
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(this->pDocument.pObject->pDocument.pObject, &fmt);
  this->Flags |= 0x10000u;
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
}

// File Line: 2491
// RVA: 0x8DE9C0
__int64 __fastcall Scaleform::GFx::TextField::GetTextColor32(Scaleform::GFx::TextField *this)
{
  unsigned int ColorV; // ecx

  ColorV = this->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject->ColorV;
  return (unsigned __int8)ColorV | ((BYTE1(ColorV) | (BYTE2(ColorV) << 8)) << 8);
}

// File Line: 2497
// RVA: 0x90BE20
void __fastcall Scaleform::GFx::TextField::SetShadowStyle(Scaleform::GFx::TextField *this, const char *pstr)
{
  Scaleform::GFx::TextField::ShadowParams *v4; // rbx
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringManager *v6; // rax
  Scaleform::GFx::TextField::ShadowParams *v7; // rax
  unsigned int v8; // edx
  Scaleform::GFx::TextField::ShadowParams *pShadow; // rbx
  Scaleform::GFx::TextField::ShadowParams *v10; // rbx
  const char *v11; // rsi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *p_TextOffsets; // rdi
  char v13; // cl
  _BYTE *v14; // rsi
  _BYTE *v15; // rbx
  char v16; // al
  float v17; // xmm7_4
  const char *v18; // rbx
  const char *v19; // rdx
  signed __int64 v20; // rsi
  float v21; // xmm6_4
  unsigned __int64 Size; // rax
  unsigned __int64 v23; // rbx
  unsigned __int64 v24; // r8
  __int64 v25; // rcx
  Scaleform::GFx::ASMovieRootBase *v26; // rcx
  Scaleform::GFx::ASStringManager *v27; // rax
  Scaleform::GFx::ASString *v28; // rax
  Scaleform::GFx::TextField::ShadowParams *v29; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v31; // rcx
  bool v32; // zf
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::Render::TreeText *RenderNode; // rax
  __int64 v35; // [rsp+20h] [rbp-88h]
  char Dst[24]; // [rsp+28h] [rbp-80h] BYREF
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp+8h] BYREF
  __int64 v38; // [rsp+C0h] [rbp+18h] BYREF
  Scaleform::GFx::TextField::ShadowParams *v39; // [rsp+C8h] [rbp+20h]

  result.pNode = (Scaleform::GFx::ASStringNode *)this;
  v35 = -2i64;
  if ( this->pShadow )
    goto LABEL_6;
  LODWORD(v38) = 323;
  v4 = (Scaleform::GFx::TextField::ShadowParams *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::TextField *, __int64, __int64 *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    64i64,
                                                    &v38,
                                                    v35);
  v39 = v4;
  if ( v4 )
  {
    pObject = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v6 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
    Scaleform::GFx::TextField::ShadowParams::ShadowParams(v4, v6);
  }
  else
  {
    v7 = 0i64;
  }
  this->pShadow = v7;
  if ( v7 )
  {
LABEL_6:
    v8 = this->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw & 0xFFFFFF;
    this->pShadow->ShadowColor.Channels.Blue = this->pDocument.pObject->Filter.ShadowParams.Colors[0].Channels.Blue;
    this->pShadow->ShadowColor.Channels.Green = BYTE1(v8);
    this->pShadow->ShadowColor.Channels.Red = BYTE2(v8);
    this->pDocument.pObject->Filter.ShadowFlags |= 1u;
$reset:
    pShadow = this->pShadow;
    if ( pShadow->ShadowOffsets.Data.Size && (pShadow->ShadowOffsets.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( pShadow->ShadowOffsets.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pShadow->ShadowOffsets.Data.Data = 0i64;
      }
      pShadow->ShadowOffsets.Data.Policy.Capacity = 0i64;
    }
    pShadow->ShadowOffsets.Data.Size = 0i64;
    v10 = this->pShadow;
    if ( v10->TextOffsets.Data.Size && (v10->TextOffsets.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64) != 0 )
    {
      if ( v10->TextOffsets.Data.Data )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v10->TextOffsets.Data.Data = 0i64;
      }
      v10->TextOffsets.Data.Policy.Capacity = 0i64;
    }
    v10->TextOffsets.Data.Size = 0i64;
    v11 = pstr;
    p_TextOffsets = 0i64;
    while ( 1 )
    {
      v13 = *v11;
      if ( !*v11 )
        break;
      if ( ((v13 - 83) & 0xDF) != 0 )
      {
        if ( ((v13 - 84) & 0xDF) != 0 )
        {
          if ( v13 == 123 && p_TextOffsets )
          {
            v14 = v11 + 1;
            v15 = v14;
            v16 = *v14;
            if ( *v14 )
            {
              while ( v16 != 44 )
              {
                v16 = *++v15;
                if ( !*v15 )
                  goto LABEL_46;
              }
            }
            if ( *v15 && v15 - v14 <= 23 )
            {
              memmove(Dst, v14, v15 - v14);
              Dst[v15 - v14] = 0;
              v17 = Scaleform::SFstrtod(Dst, 0i64) * 20.0;
              v18 = v15 + 1;
              v19 = v18;
              while ( 1 )
              {
                if ( !*v18 )
                  goto LABEL_46;
                if ( *v18 == 125 )
                  break;
                ++v18;
              }
              if ( *v18 )
              {
                v20 = v18 - v19;
                if ( v18 - v19 <= 23 )
                {
                  memmove(Dst, v19, v18 - v19);
                  Dst[v20] = 0;
                  v21 = Scaleform::SFstrtod(Dst, 0i64) * 20.0;
                  v11 = v18 + 1;
                  Size = p_TextOffsets->Size;
                  v23 = Size + 1;
                  if ( Size + 1 >= Size )
                  {
                    if ( v23 > p_TextOffsets->Policy.Capacity )
                    {
                      v24 = v23 + (v23 >> 2);
LABEL_40:
                      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                        p_TextOffsets,
                        p_TextOffsets,
                        v24);
                    }
                  }
                  else if ( v23 < p_TextOffsets->Policy.Capacity >> 1 )
                  {
                    v24 = Size + 1;
                    goto LABEL_40;
                  }
                  p_TextOffsets->Size = v23;
                  v25 = (__int64)&p_TextOffsets->Data[v23 - 1];
                  result.pNode = (Scaleform::GFx::ASStringNode *)v25;
                  v38 = v25;
                  if ( v25 )
                  {
                    *(float *)v25 = v17;
                    *(float *)(v25 + 4) = v21;
                  }
                  continue;
                }
              }
            }
          }
LABEL_46:
          pstr = this->pShadow->ShadowStyleStr.pNode->pData;
          goto $reset;
        }
        p_TextOffsets = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->pShadow->TextOffsets;
        ++v11;
      }
      else
      {
        p_TextOffsets = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&this->pShadow->ShadowOffsets;
        ++v11;
      }
    }
    if ( *pstr )
    {
      v26 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
      v27 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))v26->vfptr[59].__vecDelDtor)(v26);
      v28 = Scaleform::GFx::ASStringManager::CreateString(v27, &result, pstr);
      v29 = this->pShadow;
      pNode = v28->pNode;
      ++v28->pNode->RefCount;
      v31 = v29->ShadowStyleStr.pNode;
      v32 = v31->RefCount-- == 1;
      if ( v32 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
      v29->ShadowStyleStr.pNode = pNode;
      v33 = result.pNode;
      v32 = result.pNode->RefCount-- == 1;
      if ( v32 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v33);
    }
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
  }
}ode::ReleaseNode(v33);


// File Line: 2568
// RVA: 0x90BDA0
void __fastcall Scaleform::GFx::TextField::SetShadowColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::GFx::TextField::ShadowParams *pShadow; // rcx
  unsigned int v4; // edx
  Scaleform::Render::TreeText *RenderNode; // rax

  this->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw = rgb & 0xFFFFFF | ((unsigned __int8)this->pDocument.pObject->Filter.ShadowAlpha << 24);
  pShadow = this->pShadow;
  if ( pShadow )
  {
    v4 = this->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw & 0xFFFFFF;
    pShadow->ShadowColor.Channels.Blue = this->pDocument.pObject->Filter.ShadowParams.Colors[0].Channels.Blue;
    this->pShadow->ShadowColor.Channels.Green = BYTE1(v4);
    this->pShadow->ShadowColor.Channels.Red = BYTE2(v4);
  }
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}

// File Line: 2582
// RVA: 0x8DE010
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::TextField::GetShadowStyle(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::TextField::ShadowParams *pShadow; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rbx
  Scaleform::GFx::ASString *v5; // rax
  char v6; // di
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringManager *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rax
  char v10; // di
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v14; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v15; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+60h] [rbp+18h] BYREF

  v15 = result;
  pShadow = this->pShadow;
  if ( pShadow )
  {
    pNode = pShadow->ShadowStyleStr.pNode;
    v14 = pNode;
    ++pNode->RefCount;
    v5 = (Scaleform::GFx::ASString *)&v14;
    v6 = 1;
  }
  else
  {
    pObject = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v8 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
    v5 = Scaleform::GFx::ASStringManager::CreateEmptyString(v8, &resulta);
    v6 = 2;
    pNode = v14;
  }
  v9 = v5->pNode;
  result->pNode = v9;
  ++v9->RefCount;
  v10 = v6 | 4;
  if ( (v10 & 2) != 0 )
  {
    v10 &= ~2u;
    v11 = resulta.pNode;
    v12 = resulta.pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  if ( (v10 & 1) != 0 )
  {
    v12 = pNode->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  return result;
}

// File Line: 2588
// RVA: 0x8D6660
__int64 __fastcall Scaleform::GFx::TextField::GetCursorPos(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rax

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
    return *(_QWORD *)&pObject[3].RefCount;
  else
    return -1i64;
}

// File Line: 2593
// RVA: 0x90AEB0
__int64 __fastcall Scaleform::GFx::TextField::SetRestrict(
        Scaleform::GFx::TextField *this,
        Scaleform::GFx::ASString *restrStr)
{
  Scaleform::String *v4; // rax
  Scaleform::String *v5; // rdi
  Scaleform::GFx::Text::EditorKit *pObject; // rbx
  unsigned __int8 v7; // si
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> result; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::String v10; // [rsp+48h] [rbp+10h] BYREF

  if ( !this->pDocument.pObject->pEditorKit.pObject )
  {
    Scaleform::GFx::TextField::CreateEditorKit(this, &result);
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  }
  Scaleform::String::String(&v10, restrStr->pNode->pData);
  v5 = v4;
  pObject = (Scaleform::GFx::Text::EditorKit *)this->pDocument.pObject->pEditorKit.pObject;
  v7 = Scaleform::GFx::Text::EditorKit::ParseRestrict(
         pObject,
         (char *)((v4->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
         *(_QWORD *)(v4->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  Scaleform::String::operator=(&pObject->pRestrict.pObject->RestrictString, v5);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v10.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v7;
}

// File Line: 2607
// RVA: 0x8BC980
void __fastcall Scaleform::GFx::TextField::ClearRestrict(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *pObject; // rbx
  Scaleform::GFx::Text::EditorKit::RestrictParams *v2; // rcx

  pObject = this->pDocument.pObject->pEditorKit.pObject;
  if ( pObject )
  {
    v2 = *(Scaleform::GFx::Text::EditorKit::RestrictParams **)&pObject[2].RefCount;
    if ( v2 )
    {
      if ( LOBYTE(pObject[3].vfptr) )
      {
        LOBYTE(pObject[3].vfptr) = 0;
        Scaleform::GFx::Text::EditorKit::RestrictParams::`scalar deleting destructor(v2, 1);
      }
      *(_QWORD *)&pObject[2].RefCount = 0i64;
    }
    LOBYTE(pObject[3].vfptr) = 0;
  }
}

// File Line: 2613
// RVA: 0x8C2A20
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::TextField::CreateRenderNode(
        Scaleform::GFx::TextField *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeText::NodeData *v6; // rax
  Scaleform::Render::ContextImpl::EntryData *v7; // rbx
  Scaleform::Render::TreeText *EntryHelper; // rbx

  v6 = (Scaleform::Render::TreeText::NodeData *)context->pHeap->vfptr->Alloc(context->pHeap, 176i64, 0i64);
  v7 = v6;
  if ( v6 )
    Scaleform::Render::TreeText::NodeData::NodeData(v6);
  EntryHelper = (Scaleform::Render::TreeText *)Scaleform::Render::ContextImpl::Context::createEntryHelper(context, v7);
  Scaleform::Render::TreeText::Init(EntryHelper, this->pDocument.pObject);
  if ( EntryHelper )
    ++EntryHelper->RefCount;
  result->pObject = EntryHelper;
  if ( EntryHelper )
  {
    if ( EntryHelper->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(EntryHelper);
  }
  return result;
}

// File Line: 2627
// RVA: 0x8E71E0
bool __fastcall Scaleform::GFx::TextField::IsFocusEnabled(Scaleform::GFx::TextField *this, unsigned int fmt)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v4; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0;
  v4 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                + 4 * AvmObjOffset))[4].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  return (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 160i64))(v4, fmt);
}

// File Line: 2644
// RVA: 0x89E150
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::TextDocumentListener(
        Scaleform::GFx::TextField::TextDocumentListener *this)
{
  Scaleform::GFx::Translator *pObject; // rcx
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+48h] [rbp+10h] BYREF

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountNTSImpl,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseNTS<Scaleform::Render::Text::DocView::DocumentListener,74>::`vftable;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::Render::Text::DocView::DocumentListener::`vftable;
  this->HandlersMask = 14;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::TextField::TextDocumentListener::`vftable;
  Scaleform::GFx::StateBag::GetTranslator(
    (Scaleform::GFx::StateBag *)(*(_QWORD *)(*(_QWORD *)&this[-11].RefCount + 16i64) + 16i64),
    &result);
  pObject = result.pObject;
  if ( result.pObject )
  {
    if ( result.pObject->WWMode )
      this->HandlersMask |= 1u;
    if ( (((__int64 (__fastcall *)(Scaleform::GFx::Translator *))pObject->vfptr[1].__vecDelDtor)(pObject) & 4) != 0 )
      this->HandlersMask |= 0x10u;
  }
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 2660
// RVA: 0x9149C0
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::TranslatorChanged(
        Scaleform::GFx::TextField::TextDocumentListener *this)
{
  Scaleform::GFx::Translator *pObject; // rcx
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+40h] [rbp+8h] BYREF

  Scaleform::GFx::StateBag::GetTranslator(
    (Scaleform::GFx::StateBag *)(*(_QWORD *)(*(_QWORD *)&this[-11].RefCount + 16i64) + 16i64),
    &result);
  pObject = result.pObject;
  if ( result.pObject && result.pObject->WWMode )
    this->HandlersMask |= 1u;
  else
    this->HandlersMask &= ~1u;
  if ( pObject
    && (((__int64 (__fastcall *)(Scaleform::GFx::Translator *))pObject->vfptr[1].__vecDelDtor)(pObject) & 4) != 0 )
  {
    this->HandlersMask |= 0x10u;
  }
  else
  {
    this->HandlersMask &= ~0x10u;
  }
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 2682
// RVA: 0x919570
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::View_OnMaxScrollChanged(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::DocView *view,
        __int64 newScroll)
{
  unsigned __int8 v3; // al
  __int64 v4; // rax

  v3 = *((_BYTE *)&this[-8].RefCount + 5);
  if ( v3 )
  {
    v4 = ((__int64 (__fastcall *)(char *, Scaleform::Render::Text::DocView *, __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this[-12].vfptr + 4 * v3))[4].__vecDelDtor)(
           (char *)&this[-12] + 4 * v3,
           view,
           newScroll);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 224i64))(v4);
  }
}

// File Line: 2696
// RVA: 0x919420
__int64 __fastcall Scaleform::GFx::TextField::TextDocumentListener::View_OnLineFormat(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::DocView *__formal,
        Scaleform::Render::Text::DocView::LineFormatDesc *desc)
{
  Scaleform::GFx::Translator *pObject; // rcx
  unsigned __int64 v5; // r8
  unsigned __int8 v6; // bl
  __int64 v8[4]; // [rsp+30h] [rbp-58h] BYREF
  unsigned __int64 NumCharsInLine; // [rsp+50h] [rbp-38h]
  float v10; // [rsp+58h] [rbp-30h]
  float v11; // [rsp+5Ch] [rbp-2Ch]
  float v12; // [rsp+60h] [rbp-28h]
  float v13; // [rsp+64h] [rbp-24h]
  char Alignment; // [rsp+68h] [rbp-20h]
  unsigned __int64 ProposedWordWrapPoint; // [rsp+70h] [rbp-18h]
  bool UseHyphenation; // [rsp+78h] [rbp-10h]
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+90h] [rbp+8h] BYREF

  Scaleform::GFx::StateBag::GetTranslator(
    (Scaleform::GFx::StateBag *)(*(_QWORD *)(*(_QWORD *)&this[-11].RefCount + 16i64) + 16i64),
    &result);
  pObject = result.pObject;
  if ( !result.pObject )
    goto LABEL_7;
  v11 = desc->CurrentLineWidth * 0.050000001;
  v13 = desc->DashSymbolWidth * 0.050000001;
  v8[3] = desc->LineStartPos;
  v12 = desc->LineWidthBeforeWordWrap * 0.050000001;
  NumCharsInLine = desc->NumCharsInLine;
  v8[2] = (__int64)desc->pWidths;
  v8[0] = (__int64)desc->pParaText;
  v8[1] = desc->ParaTextLen;
  ProposedWordWrapPoint = desc->ProposedWordWrapPoint;
  v10 = desc->VisibleRectWidth * 0.050000001;
  UseHyphenation = desc->UseHyphenation;
  Alignment = desc->Alignment;
  v5 = 0i64;
  if ( NumCharsInLine )
  {
    do
    {
      desc->pWidths[v5] = desc->pWidths[v5] * 0.050000001;
      ++v5;
    }
    while ( v5 < NumCharsInLine );
    pObject = result.pObject;
  }
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Translator *, __int64 *, unsigned __int64))pObject->vfptr[3].__vecDelDtor)(
         pObject,
         v8,
         v5) )
  {
    desc->ProposedWordWrapPoint = ProposedWordWrapPoint;
    desc->UseHyphenation = UseHyphenation;
    v6 = 1;
  }
  else
  {
LABEL_7:
    v6 = 0;
  }
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  return v6;
}

// File Line: 2738
// RVA: 0x9195B0
__int64 __fastcall Scaleform::GFx::TextField::TextDocumentListener::View_PrepareBidiText(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::DocView *__formal,
        const wchar_t *paraText,
        unsigned __int64 textLen,
        wchar_t *newParaText,
        unsigned int *indexMap,
        bool *mirroredBits)
{
  unsigned __int8 v9; // bl
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+50h] [rbp+8h] BYREF

  Scaleform::GFx::StateBag::GetTranslator(
    (Scaleform::GFx::StateBag *)(*(_QWORD *)(*(_QWORD *)&this[-11].RefCount + 16i64) + 16i64),
    &result);
  if ( result.pObject
    && (((__int64 (__fastcall *)(Scaleform::GFx::Translator *))result.pObject->vfptr[1].__vecDelDtor)(result.pObject) & 4) != 0 )
  {
    v9 = ((__int64 (__fastcall *)(Scaleform::GFx::Translator *, const wchar_t *, unsigned __int64, wchar_t *, unsigned int *, bool *, __int64))result.pObject->vfptr[4].__vecDelDtor)(
           result.pObject,
           paraText,
           textLen,
           newParaText,
           indexMap,
           mirroredBits,
           -2i64);
  }
  else
  {
    v9 = 0;
  }
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  return v9;
}

// File Line: 2748
// RVA: 0x919400
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::View_OnChanged(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::DocView *__formal)
{
  Scaleform::Render::TreeText *RenderNode; // rax

  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this[-12]);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}

// File Line: 2755
// RVA: 0x8C7F60
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::Editor_OnChanged(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::EditorKitBase *editor)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx
  unsigned __int8 AvmObjOffset; // al
  __int64 v4; // rax
  unsigned __int8 v5; // al
  __int64 v6; // rax
  Scaleform::Render::TreeText *RenderNode; // rax

  v2 = (Scaleform::GFx::DisplayObjectBase *)&this[-12];
  Scaleform::Render::Text::DocView::GetText(
    *(Scaleform::Render::Text::DocView **)&this[-3].RefCount,
    (Scaleform::String *)&this[-2].HandlersMask);
  AvmObjOffset = v2->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v4 = ((__int64 (__fastcall *)(__int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v2->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * AvmObjOffset))[4].__vecDelDtor)((__int64)v2 + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 256i64))(v4);
  }
  v5 = v2->AvmObjOffset;
  if ( v5 )
  {
    v6 = ((__int64 (__fastcall *)(__int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v2->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * v5))[4].__vecDelDtor)((__int64)v2 + 4 * v5);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 192i64))(v6);
  }
  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v2);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}

// File Line: 2772
// RVA: 0x8C8000
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::Editor_OnCursorBlink(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::EditorKitBase *editor)
{
  Scaleform::Render::TreeText *RenderNode; // rax

  RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this[-12]);
  Scaleform::Render::TreeText::NotifyLayoutChanged(RenderNode);
}

// File Line: 2780
// RVA: 0x8C8030
char __fastcall Scaleform::GFx::TextField::TextDocumentListener::Editor_OnInsertingText(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::EditorKitBase *__formal,
        unsigned __int64 pos,
        unsigned __int64 len,
        const wchar_t *wstr)
{
  unsigned __int8 v5; // al
  void *v8; // rax

  v5 = *((_BYTE *)&this[-8].RefCount + 5);
  if ( !v5 )
    return 1;
  v8 = (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this[-12].vfptr + 4 * v5))[4].__vecDelDtor(
         (char *)&this[-12] + 4 * v5,
         __formal);
  return (*(__int64 (__fastcall **)(void *, unsigned __int64, unsigned __int64, const wchar_t *))(*(_QWORD *)v8 + 232i64))(
           v8,
           pos,
           len,
           wstr);
}

// File Line: 2787
// RVA: 0x8C80A0
char __fastcall Scaleform::GFx::TextField::TextDocumentListener::Editor_OnRemovingText(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::Render::Text::EditorKitBase *__formal,
        unsigned __int64 pos,
        unsigned __int64 len)
{
  unsigned __int8 v4; // al
  void *v7; // rax

  v4 = *((_BYTE *)&this[-8].RefCount + 5);
  if ( !v4 )
    return 1;
  v7 = (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this[-12].vfptr + 4 * v4))[4].__vecDelDtor(
         (char *)&this[-12] + 4 * v4,
         __formal);
  return (*(__int64 (__fastcall **)(void *, unsigned __int64, unsigned __int64, _QWORD))(*(_QWORD *)v7 + 240i64))(
           v7,
           pos,
           len,
           0i64);
}

// File Line: 2795
// RVA: 0x8D6270
Scaleform::String *__fastcall Scaleform::GFx::TextField::TextDocumentListener::GetCharacterPath(
        Scaleform::GFx::TextField::TextDocumentListener *this,
        Scaleform::String *result)
{
  unsigned __int8 v4; // al

  Scaleform::String::String(result);
  v4 = *((_BYTE *)&this[-8].RefCount + 5);
  if ( v4 )
    (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this[-12].vfptr + 4 * v4))[6].__vecDelDtor(
      (Scaleform::GFx::TextField::TextDocumentListener *)((char *)&this[-12] + 4 * v4),
      (unsigned int)result);
  return result;
}

// File Line: 2813
// RVA: 0x8D7D70
Scaleform::Render::FilterSet *__fastcall Scaleform::GFx::TextField::GetFilters(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::TreeText *RenderNode; // rbp
  Scaleform::Render::TreeText::Filter *p_filtersBuf; // rbx
  int i; // edi
  unsigned __int64 Filters; // rbp
  Scaleform::Render::FilterSet *v6; // rax
  Scaleform::Render::FilterSet *v7; // rax
  Scaleform::Render::FilterSet *v8; // rbx
  Scaleform::Render::RenderBuffer *pObject; // rcx
  $AD53D16137C3AE4177DAFEDA37259559 *j; // rbx
  Scaleform::Render::GlowFilter *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rdi
  char Flags; // cl
  int v15; // eax
  Scaleform::Render::BlurFilter *v16; // rax
  __int64 v17; // rax
  Scaleform::Render::ShadowFilter *v18; // rax
  __int64 v19; // rax
  char v20; // cl
  Scaleform::Render::RenderBuffer *v21; // rcx
  Scaleform::Render::TreeText::Filter filtersBuf; // [rsp+40h] [rbp-C8h] BYREF

  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) && !this->pFilters.pObject )
  {
    RenderNode = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    p_filtersBuf = &filtersBuf;
    for ( i = 2; i >= 0; --i )
    {
      p_filtersBuf->Type = 0;
      Scaleform::Render::TreeText::Filter::InitByDefaultValues(p_filtersBuf++);
    }
    Filters = Scaleform::Render::TreeText::GetFilters(RenderNode, &filtersBuf, 3ui64);
    if ( Filters )
    {
      v6 = (Scaleform::Render::FilterSet *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                             Scaleform::Memory::pGlobalHeap,
                                             56i64);
      if ( v6 )
      {
        Scaleform::Render::FilterSet::FilterSet(v6, 0i64);
        v8 = v7;
      }
      else
      {
        v8 = 0i64;
      }
      pObject = (Scaleform::Render::RenderBuffer *)this->pFilters.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      this->pFilters.pObject = v8;
      for ( j = &filtersBuf.4;
            LODWORD(j[-1].DropShadow.Distance) != 1;
            j = ($AD53D16137C3AE4177DAFEDA37259559 *)((char *)j + 32) )
      {
        if ( LODWORD(j[-1].DropShadow.Distance) == 2 )
        {
          v16 = (Scaleform::Render::BlurFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   80i64);
          if ( v16 )
          {
            Scaleform::Render::BlurFilter::BlurFilter(v16, j->Blur.BlurX, j->Blur.BlurY, 1u);
            v13 = v17;
          }
          else
          {
            v13 = 0i64;
          }
          *(float *)(v13 + 48) = j->Blur.Strength * 0.0099999998;
          Scaleform::Render::FilterSet::AddFilter(this->pFilters.pObject, (Scaleform::Render::Filter *)v13);
          goto LABEL_39;
        }
        if ( LODWORD(j[-1].DropShadow.Distance) == 3 )
        {
          v11 = (Scaleform::Render::GlowFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   80i64);
          if ( v11 )
          {
            Scaleform::Render::GlowFilter::GlowFilter(v11, j->Blur.BlurX, j->Blur.BlurY, 1u);
            v13 = v12;
          }
          else
          {
            v13 = 0i64;
          }
          *(float *)(v13 + 48) = j->Blur.Strength * 0.0099999998;
          *(_DWORD *)(v13 + 52) = j->Glow.Color;
          Flags = j->Glow.Flags;
          v15 = 0;
          if ( (Flags & 0x20) != 0 )
            v15 = 16;
          if ( (Flags & 0x40) != 0 )
            v15 |= 0x40u;
          if ( Flags < 0 )
            v15 |= 0x80u;
          goto LABEL_38;
        }
LABEL_40:
        if ( !--Filters )
          return this->pFilters.pObject;
      }
      v18 = (Scaleform::Render::ShadowFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 80i64);
      if ( v18 )
      {
        Scaleform::Render::ShadowFilter::ShadowFilter(
          v18,
          j->DropShadow.Angle * 3.141592653589793 * 0.005555555555555556,
          j->DropShadow.Distance,
          j->Blur.BlurX,
          j->Blur.BlurY,
          1u);
        v13 = v19;
      }
      else
      {
        v13 = 0i64;
      }
      *(float *)(v13 + 48) = j->Blur.Strength * 0.0099999998;
      *(_DWORD *)(v13 + 52) = j->Glow.Color;
      v20 = j->Glow.Flags;
      v15 = 0;
      if ( (v20 & 0x20) != 0 )
        v15 = 16;
      if ( (v20 & 0x40) != 0 )
        v15 |= 0x40u;
      if ( v20 < 0 )
        v15 |= 0x80u;
LABEL_38:
      *(_DWORD *)(v13 + 24) = v15;
      Scaleform::Render::FilterSet::AddFilter(this->pFilters.pObject, (Scaleform::Render::Filter *)v13);
LABEL_39:
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v13);
      goto LABEL_40;
    }
    v21 = (Scaleform::Render::RenderBuffer *)this->pFilters.pObject;
    if ( v21 )
      Scaleform::RefCountImpl::Release(v21);
    this->pFilters.pObject = 0i64;
  }
  return this->pFilters.pObject;
}

