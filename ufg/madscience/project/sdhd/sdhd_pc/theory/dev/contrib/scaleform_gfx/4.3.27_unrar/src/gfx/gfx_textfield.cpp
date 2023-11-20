// File Line: 37
// RVA: 0x89E210
void __fastcall Scaleform::GFx::TextField::TextField(Scaleform::GFx::TextField *this, Scaleform::GFx::TextFieldDef *def, Scaleform::GFx::MovieDefImpl *pbindingDefImpl, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::InteractiveObject *parent, Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::ASMovieRootBase *v6; // rdi
  Scaleform::GFx::MovieDefImpl *v7; // rbp
  Scaleform::GFx::TextFieldDef *v8; // r14
  Scaleform::GFx::TextField *v9; // rbx
  Scaleform::GFx::InteractiveObject *v10; // r15
  Scaleform::GFx::MovieImpl *v11; // rsi
  Scaleform::GFx::MovieImpl *v12; // r13
  __int64 v13; // rax
  Scaleform::Render::Text::Allocator *v14; // r12
  Scaleform::GFx::MovieDefRootNode *i; // rcx
  signed __int64 v16; // rax
  Scaleform::Render::Text::FontManagerBase *v17; // rbp
  Scaleform::GFx::MovieDefRootNode *j; // rax
  Scaleform::Render::Text::DocView *v19; // rdi
  Scaleform::GFx::TextField *v20; // rax
  Scaleform::Log *v21; // rax
  Scaleform::GFx::MovieImpl *v22; // rax
  Scaleform::Render::RenderBuffer *v23; // rcx
  Scaleform::RefCountNTSImpl *v24; // rcx
  Scaleform::Render::TreeText *v25; // rax
  Scaleform::Render::TreeText *v26; // rax
  int v27; // eax
  Scaleform::Render::Text::DocView *v28; // rax
  unsigned __int16 v29; // ax
  char v30; // di
  bool v31; // al
  Scaleform::Render::Text::DocView *v32; // rcx
  char v33; // al
  unsigned int v34; // [rsp+A8h] [rbp+10h]
  unsigned int v35; // [rsp+B0h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> result; // [rsp+B8h] [rbp+20h]

  v6 = pasRoot;
  v7 = pbindingDefImpl;
  v8 = def;
  v9 = this;
  id.Id = **(_DWORD **)&id.Id;
  v10 = parent;
  Scaleform::GFx::InteractiveObject::InteractiveObject(
    (Scaleform::GFx::InteractiveObject *)&this->vfptr,
    pbindingDefImpl,
    pasRoot,
    parent,
    (Scaleform::GFx::ResourceId)&id);
  v9->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::TextField::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v9->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::TextField::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  if ( v8 )
    _InterlockedExchangeAdd(&v8->RefCount.Value, 1u);
  v9->pDef.pObject = v8;
  v11 = 0i64;
  v9->pDocument.pObject = 0i64;
  v9->pFilters.pObject = 0i64;
  Scaleform::StringLH::StringLH(&v9->OriginalTextValue);
  Scaleform::GFx::TextField::TextDocumentListener::TextDocumentListener(&v9->TextDocListener);
  v9->pImageDescAssoc = 0i64;
  if ( v7 )
    v9->pBinding = &v7->pBindData.pObject->ResourceBinding;
  else
    v9->pBinding = 0i64;
  v9->Flags = 0;
  v9->FocusedControllerIdx = -1;
  v9->Alignment = v8->Alignment;
  v9->Flags = ((LOBYTE(v8->Flags) >> 2) & 1) != 0 ? 4 : 0;
  if ( SLOBYTE(v8->Flags) >= 0 )
    v9->Flags &= 0xFFFFFFFD;
  else
    v9->Flags |= 2u;
  v9->Flags |= 0x80u;
  v9->pShadow = 0i64;
  v12 = v6->pMovieImpl;
  v13 = ((__int64 (*)(void))v12->pASMovieRoot.pObject->vfptr[60].__vecDelDtor)();
  v14 = (Scaleform::Render::Text::Allocator *)v13;
  if ( v13 )
    ++*(_DWORD *)(v13 + 8);
  for ( i = v12->RootMovieDefNodes.Root.pNext; ; i = i->pNext )
  {
    v16 = (signed __int64)&v12->MovieLevels.Data.Policy;
    if ( v12 == (Scaleform::GFx::MovieImpl *)-112i64 )
      v16 = 0i64;
    if ( i == (Scaleform::GFx::MovieDefRootNode *)v16 )
      break;
    if ( (i->pDefImpl == v7 || !v7) && i->pFontManager.pObject )
    {
      v17 = (Scaleform::Render::Text::FontManagerBase *)&i->pFontManager.pObject->vfptr;
      if ( v17 )
        goto LABEL_30;
      break;
    }
  }
  if ( !v10
    || (v17 = (Scaleform::Render::Text::FontManagerBase *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v10->vfptr[67].__vecDelDtor)(v10)) == 0i64 )
  {
    for ( j = v12->RootMovieDefNodes.Root.pNext; ; j = j->pNext )
    {
      i = (Scaleform::GFx::MovieDefRootNode *)&v12->MovieLevels.Data.Policy;
      if ( v12 == (Scaleform::GFx::MovieImpl *)-112i64 )
        i = 0i64;
      if ( j == i )
        break;
      if ( j->pFontManager.pObject )
      {
        v17 = (Scaleform::Render::Text::FontManagerBase *)&j->pFontManager.pObject->vfptr;
        goto LABEL_30;
      }
    }
    v17 = 0i64;
  }
LABEL_30:
  *(_QWORD *)&id.Id = v12->pHeap;
  v19 = (Scaleform::Render::Text::DocView *)(*(__int64 (__fastcall **)(Scaleform::GFx::MovieDefRootNode *, signed __int64, _QWORD))(**(_QWORD **)&id.Id + 80i64))(
                                              i,
                                              352i64,
                                              0i64);
  if ( v19 )
  {
    v20 = v9;
    while ( SLOBYTE(v20->Flags) >= 0 )
    {
      v20 = (Scaleform::GFx::TextField *)v20->pParent;
      if ( !v20 )
        goto LABEL_36;
    }
    v11 = v20->pASRoot->pMovieImpl;
LABEL_36:
    v21 = Scaleform::GFx::MovieImpl::GetCachedLog(v11);
    Scaleform::Render::Text::DocView::DocView(v19, v14, v17, v21);
    v11 = v22;
  }
  v23 = (Scaleform::Render::RenderBuffer *)v9->pDocument.pObject;
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  v9->pDocument.pObject = (Scaleform::Render::Text::DocView *)v11;
  if ( v9 != (Scaleform::GFx::TextField *)-288i64 )
    ++v9->TextDocListener.RefCount;
  v24 = (Scaleform::RefCountNTSImpl *)v11->pLoadQueueHead;
  if ( v24 )
    Scaleform::RefCountNTSImpl::Release(v24);
  v11->pLoadQueueHead = (Scaleform::GFx::LoadQueueEntry *)&v9->TextDocListener;
  v9->pDocument.pObject->pDocument.pObject->RTFlags |= 2u;
  v9->pDocument.pObject->FlagsEx |= 4u;
  if ( (LOBYTE(v8->Flags) >> 6) & 1 )
  {
    *(_WORD *)((char *)&v34 + 1) = -1;
    LOBYTE(v34) = -1;
    HIBYTE(v34) = -1;
    v9->pDocument.pObject->BackgroundColor = v34;
    v25 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v9->vfptr);
    Scaleform::Render::TreeText::NotifyLayoutChanged(v25);
    *(_WORD *)((char *)&v35 + 1) = 0;
    LOBYTE(v35) = 0;
    HIBYTE(v35) = -1;
    v9->pDocument.pObject->BorderColor = v35;
    v26 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v9->vfptr);
    Scaleform::Render::TreeText::NotifyLayoutChanged(v26);
  }
  Scaleform::GFx::TextField::SetInitialFormatsAsDefault(v9);
  v27 = v8->MaxLength;
  if ( v27 > 0 )
    v9->pDocument.pObject->MaxLength = v27;
  Scaleform::Render::Text::DocView::SetViewRect(v9->pDocument.pObject, &v8->TextRect, UseExternally);
  if ( v8->Flags & 0x100 )
  {
    v9->pDocument.pObject->Flags |= 0x20u;
    v9->pDocument.pObject->Flags |= 0x40u;
  }
  v28 = v9->pDocument.pObject;
  if ( (LOBYTE(v8->Flags) >> 1) & 1 )
    v28->Flags |= 4u;
  else
    v28->Flags &= 0xFBu;
  v29 = v8->Flags;
  v30 = ((unsigned __int8)v29 >> 4) & 1;
  v31 = v30 && (!(v29 & 1) || !(((unsigned __int8)v29 >> 1) & 1));
  if ( v31 )
    Scaleform::Render::Text::DocView::SetAutoSizeX(v9->pDocument.pObject);
  if ( v30 )
    Scaleform::Render::Text::DocView::SetAutoSizeY(v9->pDocument.pObject);
  if ( v8->Flags & 1 )
    Scaleform::Render::Text::DocView::SetWordWrap(v9->pDocument.pObject);
  if ( (v9->Flags >> 2) & 1 )
    v9->pDocument.pObject->Flags |= 0x10u;
  if ( (v8->Flags >> 10) & 1 )
    v9->pDocument.pObject->Flags |= 0x40u;
  v32 = v9->pDocument.pObject;
  if ( v32->pEditorKit.pObject )
    v33 = ((__int64 (*)(void))v32->pEditorKit.pObject->vfptr[2].__vecDelDtor)();
  else
    v33 = (LOBYTE(v9->pDef.pObject->Flags) >> 3) & 1;
  if ( !v33 || (LOBYTE(v8->Flags) >> 5) & 1 )
  {
    Scaleform::GFx::TextField::CreateEditorKit(v9, &result);
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  }
  v9->Flags |= 0x10000u;
  if ( v14 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v14->vfptr);
}

// File Line: 125
// RVA: 0x8A8000
void __fastcall Scaleform::GFx::TextField::~TextField(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // rdi
  Scaleform::GFx::TextField::ShadowParams *v2; // rbx
  Scaleform::Render::RenderBuffer *v3; // rcx
  Scaleform::Render::RenderBuffer *v4; // rcx
  Scaleform::GFx::TextFieldDef *v5; // rsi
  Scaleform::GFx::ResourceLibBase *v6; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::TextField::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::TextField::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  Scaleform::GFx::TextField::ClearIdImageDescAssoc(this);
  Scaleform::Render::Text::DocView::Close(v1->pDocument.pObject);
  v2 = v1->pShadow;
  if ( v2 )
  {
    Scaleform::GFx::TextField::ShadowParams::~ShadowParams(v1->pShadow);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore((Scaleform::RefCountNTSImplCore *)&v1->TextDocListener.vfptr);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v1->OriginalTextValue.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64)
                                                        + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v3 = (Scaleform::Render::RenderBuffer *)v1->pFilters.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::Render::RenderBuffer *)v1->pDocument.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = v1->pDef.pObject;
  if ( v5 && !_InterlockedDecrement(&v5->RefCount.Value) )
  {
    v6 = v5->pLib;
    if ( v6 )
    {
      v6->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)v5);
      v5->pLib = 0i64;
    }
    v5->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v5->vfptr, 1u);
  }
  Scaleform::GFx::InteractiveObject::~InteractiveObject((Scaleform::GFx::InteractiveObject *)&v1->vfptr);
}

// File Line: 140
// RVA: 0x8E7810
bool __fastcall Scaleform::GFx::TextField::IsSelectable(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *v1; // rdx
  bool result; // al

  v1 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v1 )
    result = (LOBYTE(v1[10].vfptr) >> 1) & 1;
  else
    result = (LOBYTE(this->pDef.pObject->Flags) >> 5) & 1;
  return result;
}

// File Line: 146
// RVA: 0x8E77D0
bool __fastcall Scaleform::GFx::TextField::IsReadOnly(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // rdx
  Scaleform::Render::Text::EditorKitBase *v2; // rcx
  bool result; // al

  v1 = this;
  v2 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v2 )
    result = (__int64)v2->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, (unsigned int)v1);
  else
    result = (LOBYTE(v1->pDef.pObject->Flags) >> 3) & 1;
  return result;
}

// File Line: 152
// RVA: 0x907250
void __fastcall Scaleform::GFx::TextField::SetFilters(Scaleform::GFx::TextField *this, Scaleform::Render::FilterSet *filters)
{
  Scaleform::Render::FilterSet *v2; // rdi
  Scaleform::GFx::TextField *v3; // rsi
  Scaleform::Render::RenderBuffer *v4; // rcx
  unsigned int v5; // ebx
  Scaleform::Render::Filter *v6; // rax
  Scaleform::Render::Text::DocView *v7; // rbx
  float v8; // xmm1_4
  Scaleform::Render::TreeText *v9; // rax
  Scaleform::Render::Text::TextFilter v10; // [rsp+30h] [rbp-68h]

  if ( !filters )
    return;
  v2 = filters;
  v3 = this;
  Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)filters);
  v4 = (Scaleform::Render::RenderBuffer *)v3->pFilters.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v3->pFilters.pObject = v2;
  Scaleform::Render::Text::TextFilter::TextFilter(&v10);
  v5 = 0;
  if ( (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)v2) )
  {
    do
    {
      v6 = Scaleform::Render::FilterSet::GetFilter(v2, v5);
      if ( v6 )
        Scaleform::Render::Text::TextFilter::LoadFilterDesc(&v10, v6);
      ++v5;
    }
    while ( v5 < (unsigned int)BasicArrayImplementation<hkDataArrayImpl *>::getSize((BasicArrayImplementation<hkDataObjectImpl *> *)v2) );
  }
  v7 = v3->pDocument.pObject;
  if ( v7 )
  {
    v8 = v10.BlurX;
    if ( v10.BlurX != v7->Filter.BlurX || v10.BlurY != v7->Filter.BlurY || v10.BlurStrength != v7->Filter.BlurStrength )
      goto LABEL_18;
    if ( !Scaleform::Render::BlurFilterParams::EqualsAll(&v7->Filter.ShadowParams, &v10.ShadowParams)
      || v7->Filter.ShadowFlags != v10.ShadowFlags
      || v7->Filter.ShadowAlpha != v10.ShadowAlpha
      || v10.ShadowAngle != v7->Filter.ShadowAngle
      || v10.ShadowDistance != v7->Filter.ShadowDistance )
    {
      v8 = v10.BlurX;
LABEL_18:
      v7->Filter.BlurX = v8;
      v7->Filter.BlurY = v10.BlurY;
      v7->Filter.BlurStrength = v10.BlurStrength;
      Scaleform::Render::BlurFilterParams::operator=(&v7->Filter.ShadowParams, &v10.ShadowParams);
      v7->Filter.ShadowFlags = v10.ShadowFlags;
      v7->Filter.ShadowAngle = v10.ShadowAngle;
      v7->Filter.ShadowDistance = v10.ShadowDistance;
      v7->Filter.ShadowAlpha = v10.ShadowAlpha;
      v9 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
      Scaleform::Render::TreeText::NotifyLayoutChanged(v9);
      goto LABEL_19;
    }
  }
LABEL_19:
  if ( v10.ShadowParams.Gradient.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v10.ShadowParams.Gradient.pObject);
  Scaleform::RefCountNTSImplCore::~RefCountNTSImplCore((Scaleform::RefCountNTSImplCore *)&v10.vfptr);
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
  Scaleform::Render::TreeText *v1; // rax

  v1 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v1);
}

// File Line: 214
// RVA: 0x90BBA0
void __fastcall Scaleform::GFx::TextField::SetSelectable(Scaleform::GFx::TextField *this, bool v)
{
  bool v2; // si
  Scaleform::GFx::TextField *v3; // rdi
  Scaleform::GFx::Resource *v4; // rbx
  Scaleform::Render::RenderBuffer **v5; // rdi
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> result; // [rsp+50h] [rbp+18h]

  v2 = v;
  v3 = this;
  v4 = (Scaleform::GFx::Resource *)this->pDocument.pObject->pEditorKit.pObject;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)this->pDocument.pObject->pEditorKit.pObject);
  if ( v2 )
  {
    v5 = Scaleform::GFx::TextField::CreateEditorKit(v3, &result);
    if ( *v5 )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)*v5);
    if ( v4 )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
    v4 = (Scaleform::GFx::Resource *)*v5;
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
    LOWORD(v4[6].pLib) |= 2u;
  }
  else if ( v4 )
  {
    LOWORD(v4[6].pLib) &= 0xFFFDu;
  }
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v4);
}

// File Line: 234
// RVA: 0x8BF460
Scaleform::Render::RenderBuffer **__fastcall Scaleform::GFx::TextField::CreateEditorKit(Scaleform::GFx::TextField *this, Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> *result)
{
  Scaleform::Render::RenderBuffer **v2; // rbx
  Scaleform::GFx::TextField *v3; // rdi
  __int64 v4; // rsi
  Scaleform::Render::Text::DocView *v5; // rax
  Scaleform::Render::RenderBuffer *v6; // rbp
  Scaleform::GFx::Text::EditorKit *v7; // rax
  __int64 v8; // rax
  Scaleform::GFx::StateBag *v9; // rax
  Scaleform::GFx::Clipboard *v10; // rsi
  Scaleform::Render::RenderBuffer *v11; // rbp
  Scaleform::Render::RenderBuffer *v12; // rcx
  Scaleform::GFx::StateBag *v13; // rax
  Scaleform::GFx::TextKeyMap *v14; // rsi
  Scaleform::Render::RenderBuffer *v15; // rbp
  Scaleform::Render::RenderBuffer *v16; // rcx
  Scaleform::Render::RenderBuffer *v17; // rax
  signed int v19; // [rsp+20h] [rbp-48h]
  Scaleform::Ptr<Scaleform::GFx::Clipboard> resulta; // [rsp+28h] [rbp-40h]
  __int64 v21; // [rsp+30h] [rbp-38h]
  Scaleform::GFx::Text::EditorKit *v22; // [rsp+38h] [rbp-30h]
  int v23; // [rsp+80h] [rbp+18h]
  Scaleform::Ptr<Scaleform::GFx::TextKeyMap> v24; // [rsp+88h] [rbp+20h]

  v21 = -2i64;
  v2 = (Scaleform::Render::RenderBuffer **)result;
  v3 = this;
  v4 = 0i64;
  v5 = this->pDocument.pObject;
  v6 = (Scaleform::Render::RenderBuffer *)v5->pEditorKit.pObject;
  if ( v6 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v5->pEditorKit.pObject);
  *v2 = v6;
  v19 = 1;
  if ( !*v2 )
  {
    v23 = 74;
    v7 = (Scaleform::GFx::Text::EditorKit *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::TextField *, signed __int64, int *, signed int))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              v3,
                                              176i64,
                                              &v23,
                                              v19);
    v22 = v7;
    if ( v7 )
    {
      Scaleform::GFx::Text::EditorKit::EditorKit(v7, v3->pDocument.pObject);
      v4 = v8;
    }
    if ( *v2 )
      Scaleform::RefCountImpl::Release(*v2);
    *v2 = (Scaleform::Render::RenderBuffer *)v4;
    if ( (LOBYTE(v3->pDef.pObject->Flags) >> 3) & 1 )
      *(_WORD *)(v4 + 160) |= 1u;
    if ( (LOBYTE(v3->pDef.pObject->Flags) >> 5) & 1 )
      LOWORD((*v2)[3].Type) |= 2u;
    v9 = (Scaleform::GFx::StateBag *)((__int64 (*)(void))v3->pASRoot->pMovieImpl->vfptr->GetStateBagImpl)();
    Scaleform::GFx::StateBag::GetClipboard(v9, &resulta);
    v10 = resulta.pObject;
    v11 = *v2;
    if ( resulta.pObject )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)resulta.pObject);
    v12 = (Scaleform::Render::RenderBuffer *)v11->pManager;
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    v11->pManager = (Scaleform::Render::RenderBufferManager *)v10;
    v13 = (Scaleform::GFx::StateBag *)((__int64 (*)(void))v3->pASRoot->pMovieImpl->vfptr->GetStateBagImpl)();
    Scaleform::GFx::StateBag::GetTextKeyMap(v13, &v24);
    v14 = v24.pObject;
    v15 = *v2;
    if ( v24.pObject )
      Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v24.pObject);
    v16 = (Scaleform::Render::RenderBuffer *)v15->pRenderTargetData;
    if ( v16 )
      Scaleform::RefCountImpl::Release(v16);
    v15->pRenderTargetData = (Scaleform::Render::RenderBuffer::RenderTargetData *)v14;
    v17 = *v2;
    if ( (LOWORD(v3->Flags) >> 8) & 1 )
      LOWORD(v17[3].Type) |= 4u;
    else
      LOWORD(v17[3].Type) &= 0xFFFBu;
    if ( v24.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v24.pObject);
    if ( resulta.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  }
  return v2;
}

// File Line: 264
// RVA: 0x8DA1D0
void __fastcall Scaleform::GFx::TextField::GetInitialFormats(Scaleform::GFx::TextField *this, Scaleform::Render::Text::TextFormat *ptextFmt, Scaleform::Render::Text::ParagraphFormat *pparaFmt)
{
  Scaleform::Render::Text::ParagraphFormat *v3; // rdi
  Scaleform::Render::Text::TextFormat *v4; // r13
  Scaleform::GFx::TextField *v5; // rsi
  char v6; // r14
  Scaleform::GFx::TextFieldDef *v7; // rcx
  Scaleform::GFx::ResourceBindData *v8; // r14
  Scaleform::GFx::Resource *v9; // rbx
  Scaleform::GFx::ResourceLibBase *v10; // rcx
  Scaleform::GFx::Resource *v11; // rbx
  Scaleform::GFx::ResourceLibBase *v12; // rcx
  Scaleform::GFx::MovieDefImpl *v13; // rax
  Scaleform::GFx::MovieDefImpl *v14; // rbx
  Scaleform::GFx::ResourceLibBase *v15; // rcx
  Scaleform::GFx::TextFieldDef *v16; // rcx
  Scaleform::GFx::Resource *v17; // rax
  __int64 v18; // rbx
  Scaleform::GFx::TextFieldDef *v19; // r8
  __int64 v20; // r9
  Scaleform::String::DataDesc *v21; // rax
  Scaleform::GFx::Resource *v22; // rax
  Scaleform::GFx::Resource *v23; // r14
  const char *v24; // rax
  Scaleform::GFx::TextFieldDef *v25; // rcx
  Scaleform::GFx::Resource *v26; // r15
  unsigned int v27; // ecx
  signed __int16 v28; // ax
  Scaleform::GFx::TextFieldDef::alignment v29; // edx
  int v30; // edx
  int v31; // edx
  Scaleform::GFx::TextFieldDef *v32; // rcx
  unsigned __int16 v33; // cx
  Scaleform::GFx::Resource *v34; // rbx
  Scaleform::GFx::ResourceLibBase *v35; // rcx
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+48h] [rbp-21h]
  Scaleform::GFx::ResourceBindData result; // [rsp+58h] [rbp-11h]
  Scaleform::Render::Text::ParagraphFormat v38; // [rsp+68h] [rbp-1h]

  v3 = pparaFmt;
  v4 = ptextFmt;
  v5 = this;
  Scaleform::Render::Text::TextFormat::InitByDefaultValues(ptextFmt);
  Scaleform::Render::Text::ParagraphFormat::InitByDefaultValues(v3);
  presBindData.pResource.pObject = 0i64;
  presBindData.pBinding = 0i64;
  v6 = 1;
  v7 = v5->pDef.pObject;
  if ( LOWORD(v7->FontId.Id) )
  {
    v8 = Scaleform::GFx::ResourceBinding::GetResourceData(
           v5->pBinding,
           &result,
           (Scaleform::GFx::ResourceHandle *)&v7->pFont.HType);
    if ( v8->pResource.pObject )
      _InterlockedExchangeAdd(&v8->pResource.pObject->RefCount.Value, 1u);
    v9 = presBindData.pResource.pObject;
    if ( presBindData.pResource.pObject && !_InterlockedDecrement(&presBindData.pResource.pObject->RefCount.Value) )
    {
      v10 = presBindData.pResource.pObject->pLib;
      if ( v10 )
      {
        v10->vfptr[1].__vecDelDtor(
          (Scaleform::RefCountImplCore *)&v10->vfptr,
          (unsigned int)presBindData.pResource.pObject);
        presBindData.pResource.pObject->pLib = 0i64;
      }
      v9->vfptr->__vecDelDtor(v9, 1u);
    }
    presBindData.pResource.pObject = v8->pResource.pObject;
    presBindData.pBinding = v8->pBinding;
    v11 = result.pResource.pObject;
    if ( result.pResource.pObject && !_InterlockedDecrement(&result.pResource.pObject->RefCount.Value) )
    {
      v12 = v11->pLib;
      if ( v12 )
      {
        v12->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v12->vfptr, (unsigned int)v11);
        v11->pLib = 0i64;
      }
      v11->vfptr->__vecDelDtor(v11, 1u);
    }
  }
  else if ( *(_QWORD *)(v7->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64 )
  {
    v13 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[66].__vecDelDtor)(v5);
    v14 = v13;
    if ( v13 )
      _InterlockedExchangeAdd(&v13->RefCount.Value, 1u);
    if ( !Scaleform::GFx::MovieImpl::FindExportedResource(
            v5->pASRoot->pMovieImpl,
            v13,
            &presBindData,
            (Scaleform::String *)&v5->pDef.pObject->FontClass.0) )
    {
      Scaleform::Render::Text::TextFormat::SetFontName(v4, (Scaleform::String *)&v5->pDef.pObject->FontClass.0);
      v6 = 0;
    }
    if ( v14 && !_InterlockedDecrement(&v14->RefCount.Value) )
    {
      v15 = v14->pLib;
      if ( v15 )
      {
        v15->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, (unsigned int)v14);
        v14->pLib = 0i64;
      }
      v14->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v14->vfptr, 1u);
    }
    if ( !v6 )
      goto LABEL_54;
  }
  v16 = v5->pDef.pObject;
  if ( !LOWORD(v16->FontId.Id)
    && !(*(_QWORD *)(v16->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) )
  {
    goto LABEL_54;
  }
  if ( presBindData.pResource.pObject )
  {
    if ( (((__int64 (*)(void))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)() & 0xFF00) == 512 )
    {
      if ( !presBindData.pResource.pObject )
        goto LABEL_54;
      v23 = (Scaleform::GFx::Resource *)presBindData.pResource.pObject[1].vfptr;
      v24 = (const char *)((__int64 (__fastcall *)(Scaleform::GFx::ResourceVtbl *))v23->vfptr->GetKey)(presBindData.pResource.pObject[1].vfptr);
      Scaleform::Render::Text::TextFormat::SetFontName(v4, v24, 0xFFFFFFFFFFFFFFFFui64);
      v25 = v5->pDef.pObject;
      if ( SLOBYTE(v25->Flags) < 0
        && !(*(_QWORD *)(v25->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64) )
      {
        goto LABEL_54;
      }
      Scaleform::Render::Text::TextFormat::SetBold(v4, (HIDWORD(v23[1].vfptr) >> 1) & 1);
      Scaleform::Render::Text::TextFormat::SetItalic(v4, BYTE4(v23[1].vfptr) & 1);
      if ( v5->pDef.pObject->Flags & 0x100 || !(~(unsigned __int8)(HIDWORD(v23[1].vfptr) >> 6) & 1) )
        goto LABEL_54;
      v18 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
              Scaleform::Memory::pGlobalHeap,
              64i64);
      if ( v18 )
      {
        v26 = presBindData.pBinding->pOwnerDefRes;
        *(_QWORD *)v18 = &Scaleform::RefCountImplCore::`vftable;
        *(_DWORD *)(v18 + 8) = 1;
        *(_QWORD *)v18 = &Scaleform::RefCountImpl::`vftable;
        *(_QWORD *)v18 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,74>::`vftable;
        *(_QWORD *)v18 = &Scaleform::RefCountBase<Scaleform::Render::Text::FontHandle,74>::`vftable;
        *(_QWORD *)v18 = &Scaleform::Render::Text::FontHandle::`vftable;
        *(_QWORD *)(v18 + 16) = 0i64;
        *(_DWORD *)(v18 + 24) = 0;
        Scaleform::StringLH::StringLH((Scaleform::StringLH *)(v18 + 32));
        *(_DWORD *)(v18 + 40) = 1065353216;
        Scaleform::Render::RenderBuffer::AddRef(v23);
        *(_QWORD *)(v18 + 48) = v23;
        *(_QWORD *)v18 = &Scaleform::GFx::FontHandle::`vftable;
        if ( v26 )
          _InterlockedExchangeAdd(&v26->RefCount.Value, 1u);
        *(_QWORD *)(v18 + 56) = v26;
      }
      else
      {
        v18 = 0i64;
      }
      Scaleform::Render::Text::TextFormat::SetFontHandle(v4, (Scaleform::Render::Text::FontHandle *)v18);
    }
    else
    {
      v22 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[76].__vecDelDtor)(v5);
      v18 = (__int64)v22;
      if ( v22 )
        Scaleform::Render::RenderBuffer::AddRef(v22);
      if ( v18 )
        Scaleform::Log::LogError(
          (Scaleform::Log *)v18,
          "Font id = %d is referring to non-font resource in text field id = %d, def text = %s",
          LOWORD(v5->pDef.pObject->FontId.Id),
          LOWORD(v5->Id.Id),
          (v5->pDef.pObject->DefaultText.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
    }
  }
  else
  {
    v17 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[76].__vecDelDtor)(v5);
    v18 = (__int64)v17;
    if ( v17 )
      Scaleform::Render::RenderBuffer::AddRef(v17);
    if ( v18 )
    {
      v19 = v5->pDef.pObject;
      v20 = LOWORD(v5->Id.Id);
      v21 = v19->DefaultText.pData;
      if ( LOWORD(v19->FontId.Id) )
        Scaleform::Log::LogError(
          (Scaleform::Log *)v18,
          "Resource for font id = %d is not found in text field id = %d, def text = %s",
          LOWORD(v19->FontId.Id),
          v20,
          ((unsigned __int64)v21 & 0xFFFFFFFFFFFFFFFCui64) + 12);
      else
        Scaleform::Log::LogError(
          (Scaleform::Log *)v18,
          "Resource for font class = %s is not found in text field id = %d, def text = %s",
          (v19->FontClass.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
          v20,
          ((unsigned __int64)v21 & 0xFFFFFFFFFFFFFFFCui64) + 12);
    }
  }
  if ( v18 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v18);
LABEL_54:
  v27 = (signed int)v5->pDef.pObject->TextHeight;
  v28 = -1;
  if ( v27 <= 0x10000 )
    v28 = (signed int)v5->pDef.pObject->TextHeight;
  v4->FontSize = v28;
  v4->PresentMask |= 8u;
  v4->ColorV = v5->pDef.pObject->ColorV.Raw;
  v4->PresentMask |= 1u;
  v38.pAllocator = 0i64;
  v38.RefCount = 1;
  v38.pTabStops = 0i64;
  *(_QWORD *)&v38.BlockIndent = 0i64;
  *(_DWORD *)&v38.RightMargin = 0;
  v29 = v5->pDef.pObject->Alignment;
  if ( v29 )
  {
    v30 = v29 - 1;
    if ( v30 )
    {
      v31 = v30 - 1;
      if ( v31 )
      {
        if ( v31 == 1 )
        {
          v3->PresentMask &= 0xFDFFu;
          v3->PresentMask |= 0x401u;
        }
      }
      else
      {
        v3->PresentMask |= 0x601u;
      }
    }
    else
    {
      v3->PresentMask &= 0xFBFFu;
      v3->PresentMask |= 0x201u;
    }
  }
  else
  {
    v3->PresentMask &= 0xF9FFu;
    v3->PresentMask |= 1u;
  }
  v32 = v5->pDef.pObject;
  if ( (v32->Flags >> 9) & 1 )
  {
    v3->LeftMargin = (signed int)(float)(v32->LeftMargin * 0.050000001);
    v3->PresentMask |= 0x10u;
    v33 = v3->PresentMask;
    v3->RightMargin = (signed int)(float)(v5->pDef.pObject->RightMargin * 0.050000001);
    v33 |= 0x20u;
    v3->PresentMask = v33;
    v3->Indent = (signed int)(float)(v5->pDef.pObject->Indent * 0.050000001);
    v33 |= 4u;
    v3->PresentMask = v33;
    v3->Leading = (signed int)(float)(v5->pDef.pObject->Leading * 0.050000001);
    v3->PresentMask = v33 | 8;
  }
  Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&v38);
  v34 = presBindData.pResource.pObject;
  if ( presBindData.pResource.pObject
    && _InterlockedExchangeAdd(&presBindData.pResource.pObject->RefCount.Value, 0xFFFFFFFF) == 1 )
  {
    v35 = v34->pLib;
    if ( v35 )
    {
      v35->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v35->vfptr, (unsigned int)v34);
      v34->pLib = 0i64;
    }
    v34->vfptr->__vecDelDtor(v34, 1u);
  }
}

// File Line: 368
// RVA: 0x9082A0
void __fastcall Scaleform::GFx::TextField::SetInitialFormatsAsDefault(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // rbx
  Scaleform::MemoryHeap *v2; // rax
  Scaleform::Render::Text::DocView::DocumentText *v3; // rax
  Scaleform::Render::Text::TextFormat *v4; // rsi
  Scaleform::Render::Text::ParagraphFormat *v5; // rdi
  Scaleform::Render::Text::TextFormat *v6; // rax
  Scaleform::Render::Text::ParagraphFormat *v7; // rax
  Scaleform::MemoryHeap *v8; // rax
  Scaleform::Render::Text::TextFormat *v9; // rax
  Scaleform::Render::Text::ParagraphFormat *v10; // rax
  Scaleform::Render::Text::ParagraphFormat pparaFmt; // [rsp+20h] [rbp-D8h]
  Scaleform::Render::Text::ParagraphFormat v12; // [rsp+48h] [rbp-B0h]
  __int64 v13; // [rsp+70h] [rbp-88h]
  Scaleform::Render::Text::TextFormat ptextFmt; // [rsp+78h] [rbp-80h]
  Scaleform::Render::Text::TextFormat result; // [rsp+C8h] [rbp-30h]
  Scaleform::Render::Text::TextFormat v16; // [rsp+118h] [rbp+20h]

  v13 = -2i64;
  v1 = this;
  v2 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  Scaleform::Render::Text::TextFormat::TextFormat(&ptextFmt, v2);
  pparaFmt.pAllocator = 0i64;
  pparaFmt.RefCount = 1;
  pparaFmt.pTabStops = 0i64;
  *(_QWORD *)&pparaFmt.BlockIndent = 0i64;
  *(_DWORD *)&pparaFmt.RightMargin = 0;
  v3 = v1->pDocument.pObject->pDocument.pObject;
  v4 = v3->pDefaultTextFormat.pObject;
  v5 = v3->pDefaultParagraphFormat.pObject;
  if ( (v1->pDef.pObject->Flags >> 11) & 1 )
  {
    if ( v4 )
      Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v4);
    if ( v5 )
      Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v5);
    v8 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v1);
    Scaleform::Render::Text::TextFormat::TextFormat(&result, v8);
    v12.pAllocator = 0i64;
    v12.RefCount = 1;
    v12.pTabStops = 0i64;
    *(_QWORD *)&v12.BlockIndent = 0i64;
    *(_DWORD *)&v12.RightMargin = 0;
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
    Scaleform::GFx::TextField::GetInitialFormats(v1, &ptextFmt, &pparaFmt);
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
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
    (Scaleform::Render::Text::StyledText *)&v1->pDocument.pObject->pDocument.pObject->vfptr,
    &ptextFmt);
  v1->Flags |= 0x10000u;
  Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
    (Scaleform::Render::Text::StyledText *)&v1->pDocument.pObject->pDocument.pObject->vfptr,
    &pparaFmt);
  v1->Flags |= 0x10000u;
  Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&pparaFmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&ptextFmt);
}

// File Line: 402
// RVA: 0x8BA6E0
signed __int64 __fastcall Scaleform::GFx::TextField::CheckAdvanceStatus(Scaleform::GFx::TextField *this, bool playingNow)
{
  unsigned int v2; // ebx
  bool v3; // si
  Scaleform::GFx::TextField *v4; // rdi
  unsigned __int16 v5; // dx
  unsigned int v6; // ecx
  Scaleform::GFx::MovieImpl *v7; // rbp
  Scaleform::Render::Text::EditorKitBase *v8; // r14
  signed __int64 result; // rax

  v2 = 0;
  v3 = playingNow;
  v4 = this;
  if ( this->Flags & 0xC
    || (v5 = this->Flags, !(~((unsigned __int8)v5 >> 6) & 1))
    || (this->pDef.pObject->Flags >> 12) & 1 )
  {
    if ( v3 )
      v2 = -1;
    result = v2;
  }
  else
  {
    v6 = this->Flags;
    if ( (v6 >> 14) & 1
      || (v6 >> 15) & 1
      || (v7 = v4->pASRoot->pMovieImpl, v8 = v4->pDocument.pObject->pEditorKit.pObject, (v5 >> 14) & 1)
      && v8
      && (!((unsigned __int8 (__fastcall *)(Scaleform::Render::Text::EditorKitBase *))v8->vfptr[2].__vecDelDtor)(v8)
       && Scaleform::GFx::MovieImpl::IsFocused(v7, (Scaleform::GFx::InteractiveObject *)&v4->vfptr)
       || (LOBYTE(v8[10].vfptr) >> 5) & 1) )
    {
      if ( !v3 )
        return 1i64;
    }
    else if ( v3 )
    {
      return 0xFFFFFFFFi64;
    }
    result = 0i64;
  }
  return result;
}

// File Line: 445
// RVA: 0x90C3F0
void __fastcall Scaleform::GFx::TextField::SetStateChangeFlags(Scaleform::GFx::TextField *this, char flags)
{
  Scaleform::GFx::TextField *v2; // rbx
  Scaleform::GFx::MovieImpl *v3; // rcx
  unsigned __int16 v4; // dx
  Scaleform::GFx::InteractiveObject *v5; // rax
  bool v6; // dl
  int v7; // eax

  this->Flags &= 0xFFF0FFFF;
  this->Flags |= 0x4000u;
  v2 = this;
  this->Flags |= (flags & 0xF | 0x10) << 16;
  if ( *(_OWORD *)&this->pPlayNext == 0i64 )
  {
    v3 = this->pASRoot->pMovieImpl;
    if ( (Scaleform::GFx::TextField *)v3->pPlayListHead != v2 )
    {
      v4 = v2->Flags;
      if ( !(((unsigned __int8)v4 >> 4) & 1) && !(v4 & 0x1000) && v2->Depth >= -1 )
      {
        v5 = v3->pPlayListHead;
        if ( v5 )
        {
          v5->pPlayPrev = (Scaleform::GFx::InteractiveObject *)&v2->vfptr;
          v2->pPlayNext = v3->pPlayListHead;
        }
        v3->pPlayListHead = (Scaleform::GFx::InteractiveObject *)&v2->vfptr;
      }
    }
  }
  v6 = (v2->Flags >> 21) & 1 && !((v2->Flags >> 22) & 1);
  v7 = Scaleform::GFx::TextField::CheckAdvanceStatus(v2, v6);
  if ( v7 == -1 )
  {
    v2->Flags |= 0x400000u;
  }
  else if ( v7 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)&v2->vfptr);
  }
}

// File Line: 456
// RVA: 0x917D70
void __fastcall Scaleform::GFx::TextField::UpdateTransform3D(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // rdi
  Scaleform::Render::Rect<float> *v2; // rbx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v3; // rdi
  double v4; // xmm4_8
  float v5; // xmm2_4
  float v6; // xmm3_4
  double v7; // xmm2_8
  double v8; // xmm3_8
  float v9; // xmm1_4
  float v10; // ebx
  float v11; // esi
  float v12; // er14
  double v13; // xmm1_8
  float v14; // edi
  float v15; // er15
  float v16; // er12
  float v17; // er13
  float v18; // xmm6_4
  float v19; // xmm7_4
  float v20; // xmm0_4
  float v21; // edx
  float v22; // er8
  float v23; // er9
  float v24; // er10
  float v25; // er11
  double v26; // xmm0_8
  float v27; // xmm6_4
  float v28; // xmm7_4
  float v29; // xmm0_4
  double v30; // xmm0_8
  float v31; // xmm6_4
  float v32; // xmm7_4
  float v33; // xmm0_4
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+20h] [rbp-D8h]
  char v35[52]; // [rsp+50h] [rbp-A8h]
  float v36; // [rsp+84h] [rbp-74h]
  float v37; // [rsp+88h] [rbp-70h]
  int v38; // [rsp+8Ch] [rbp-6Ch]
  float v39; // [rsp+90h] [rbp-68h]
  float v40; // [rsp+94h] [rbp-64h]
  __int64 v41; // [rsp+98h] [rbp-60h]
  int v42; // [rsp+A0h] [rbp-58h]
  int v43; // [rsp+A4h] [rbp-54h]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+A8h] [rbp-50h]
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+D8h] [rbp-20h]
  Scaleform::Render::Matrix3x4<float> v46; // [rsp+108h] [rbp+10h]
  Scaleform::Render::Matrix3x4<float> v47; // [rsp+138h] [rbp+40h]
  Scaleform::Render::Matrix3x4<float> v48; // [rsp+168h] [rbp+70h]
  Scaleform::Render::Matrix3x4<float> v49; // [rsp+198h] [rbp+A0h]
  void *retaddr; // [rsp+238h] [rbp+140h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v51; // [rsp+240h] [rbp+148h]

  v1 = this;
  v2 = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  memset(&Dst, 0, 0x30ui64);
  v3 = v1->pGeomData;
  v51 = v3;
  v4 = v3->Z;
  v5 = (float)v3->X - v2->x1;
  v6 = (float)v3->Y - v2->y1;
  *(_QWORD *)&v35[44] = *(_QWORD *)&Dst.M[0][1];
  *(float *)&v4 = v4;
  v37 = Dst.M[1][0];
  v39 = Dst.M[1][2];
  *(_DWORD *)&v35[40] = (_DWORD)FLOAT_1_0;
  v41 = *(_QWORD *)&Dst.M[2][0];
  v36 = v5;
  v38 = (signed int)FLOAT_1_0;
  v40 = v6;
  v42 = (signed int)FLOAT_1_0;
  v43 = LODWORD(v4);
  memset(&Dst, 0, 0x30ui64);
  v7 = v3->YScale;
  v8 = v3->ZScale;
  v9 = v3->XScale;
  m2.M[0][0] = v9 * 0.0099999998;
  m2.M[1][0] = Dst.M[1][0];
  *(_QWORD *)&m2.M[0][1] = *(_QWORD *)&Dst.M[0][1];
  m2.M[0][3] = Dst.M[0][3];
  *(_QWORD *)&m2.M[1][2] = *(_QWORD *)&Dst.M[1][2];
  *(_QWORD *)&m2.M[2][0] = *(_QWORD *)&Dst.M[2][0];
  m2.M[1][1] = (float)v7 * 0.0099999998;
  m2.M[2][2] = (float)v8 * 0.0099999998;
  v10 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][3];
  v11 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][1];
  v12 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][0];
  m2.M[2][3] = Dst.M[2][3];
  v13 = v3->XRotation;
  v14 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][2];
  v15 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][3];
  v16 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][2];
  v17 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][1];
  if ( v13 == 0.0 )
  {
    v24 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v25 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    v22 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    v23 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v21 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    Dst = Scaleform::Render::Matrix3x4<float>::Identity;
  }
  else
  {
    v18 = v13 * 3.141592653589793 * 0.005555555555555556;
    memset(&Dst, 0, 0x30ui64);
    v19 = cosf(v18);
    v20 = sinf(v18);
    v21 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    v22 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    Dst.M[1][1] = v19;
    *(_QWORD *)&Dst.M[2][1] = __PAIR__(LODWORD(v19), LODWORD(v20));
    v23 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v24 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v25 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    LODWORD(Dst.M[1][2]) = LODWORD(v20) ^ _xmm[0];
    *(_QWORD *)&Dst.M[0][0] = 1065353216i64;
    Dst.M[1][0] = 0.0;
    Dst.M[2][0] = 0.0;
    Dst.M[0][2] = 0.0;
  }
  m1 = Dst;
  v26 = v51->YRotation;
  if ( v26 == 0.0 )
  {
    *(_QWORD *)&Dst.M[0][0] = __PAIR__(LODWORD(v24), LODWORD(v25));
    *(_QWORD *)&Dst.M[0][2] = __PAIR__(LODWORD(v22), LODWORD(v23));
    *(_QWORD *)&Dst.M[1][0] = __PAIR__(LODWORD(v17), LODWORD(v21));
    *(_QWORD *)&Dst.M[1][2] = __PAIR__(LODWORD(v15), LODWORD(v16));
    *(_QWORD *)&Dst.M[2][0] = __PAIR__(LODWORD(v11), LODWORD(v12));
    *(_QWORD *)&Dst.M[2][2] = __PAIR__(LODWORD(v10), LODWORD(v14));
  }
  else
  {
    v27 = v26 * 3.141592653589793 * 0.005555555555555556;
    memset(&Dst, 0, 0x30ui64);
    v28 = cosf(v27);
    v29 = sinf(v27);
    v21 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    v22 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    *(_QWORD *)&Dst.M[0][0] = LODWORD(v28);
    Dst.M[2][2] = v28;
    Dst.M[0][2] = v29;
    v23 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v24 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v25 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    *(_QWORD *)&Dst.M[2][0] = (unsigned int)(LODWORD(v29) ^ _xmm[0]);
    Dst.M[1][0] = 0.0;
    *(_QWORD *)&Dst.M[1][1] = 1065353216i64;
  }
  v46 = Dst;
  v30 = v51->Rotation;
  if ( v30 == 0.0 )
  {
    *(_QWORD *)&Dst.M[0][0] = __PAIR__(LODWORD(v24), LODWORD(v25));
    *(_QWORD *)&Dst.M[0][2] = __PAIR__(LODWORD(v22), LODWORD(v23));
    *(_QWORD *)&Dst.M[1][0] = __PAIR__(LODWORD(v17), LODWORD(v21));
    *(_QWORD *)&Dst.M[1][2] = __PAIR__(LODWORD(v15), LODWORD(v16));
    *(_QWORD *)&Dst.M[2][0] = __PAIR__(LODWORD(v11), LODWORD(v12));
    *(_QWORD *)&Dst.M[2][2] = __PAIR__(LODWORD(v10), LODWORD(v14));
  }
  else
  {
    v31 = v30 * 3.141592653589793 * 0.005555555555555556;
    memset(&Dst, 0, 0x30ui64);
    v32 = cosf(v31);
    v33 = sinf(v31);
    Dst.M[0][0] = v32;
    *(_QWORD *)&Dst.M[1][1] = LODWORD(v32);
    *(_QWORD *)&Dst.M[2][0] = 0i64;
    Dst.M[1][0] = v33;
    Dst.M[2][2] = 1.0;
    *(_QWORD *)&Dst.M[0][1] = (unsigned int)(LODWORD(v33) ^ _xmm[0]);
  }
  *(_OWORD *)v35 = *(_OWORD *)&Dst.M[0][0];
  *(_OWORD *)&v35[16] = *(_OWORD *)&Dst.M[1][0];
  *(_OWORD *)&v35[32] = *(_OWORD *)&Dst.M[2][0];
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&Dst, &m1, &m2);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v48, (Scaleform::Render::Matrix3x4<float> *)v35, &v46);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v49, &v48, &Dst);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v47, (Scaleform::Render::Matrix3x4<float> *)&v35[40], &v49);
  if ( Scaleform::Render::Matrix3x4<float>::IsValid(&v47) )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix3x4<float> *))(*(_QWORD *)retaddr + 40i64))(retaddr, &v47);
}

// File Line: 477
// RVA: 0x8B59F0
void __fastcall Scaleform::GFx::TextField::AdvanceFrame(Scaleform::GFx::TextField *this, bool nextFrame, float framePos)
{
  Scaleform::GFx::TextField *v3; // rbx
  bool v4; // di
  char v5; // al
  Scaleform::Render::Text::DocView *v6; // rcx
  unsigned int v7; // ecx
  bool v8; // dl
  int v9; // eax
  unsigned __int8 v10; // al
  __int64 v11; // rax
  Scaleform::Render::Text::EditorKitBase *v12; // rdi
  Scaleform::GFx::MovieImpl *v13; // rsi
  signed __int64 v14; // rax
  double v15; // xmm1_8
  Scaleform::Render::TreeText *v16; // rax

  v3 = this;
  v4 = nextFrame;
  v5 = ((__int64 (*)(void))this->vfptr[80].__vecDelDtor)();
  if ( v5 & 0xF || (v3->pASRoot->pMovieImpl->Flags2 >> 1) & 1 )
  {
    v6 = v3->pDocument.pObject;
    if ( v6 )
    {
      v3->Flags &= 0xFFEFFFFF;
      v6->RTFlags |= 2u;
      v3->Flags |= 0x10000u;
      if ( v5 & 8 )
      {
        Scaleform::GFx::TextField::TextDocumentListener::TranslatorChanged(&v3->TextDocListener);
        Scaleform::GFx::TextField::SetTextValue(
          v3,
          (const char *)((v3->OriginalTextValue.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
          (v3->Flags >> 12) & 1,
          1);
      }
    }
  }
  v3->Flags &= 0xFFF0FFFF;
  v7 = v3->Flags;
  if ( (v3->Flags >> 14) & 1 )
  {
    v3->Flags &= 0xFFFFBFFF;
    v8 = (v7 >> 21) & 1 && !((v7 >> 22) & 1);
    v9 = Scaleform::GFx::TextField::CheckAdvanceStatus(v3, v8);
    if ( v9 == -1 )
    {
      v3->Flags |= 0x400000u;
    }
    else if ( v9 == 1 )
    {
      Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)&v3->vfptr);
    }
  }
  if ( v4 )
  {
    if ( (v3->Flags >> 15) & 1 )
    {
      v10 = v3->AvmObjOffset;
      if ( v10 )
      {
        v11 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr
                                                                                               + 4 * v10))[4].__vecDelDtor)((signed __int64)v3 + 4 * v10);
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v11 + 248i64))(v11);
      }
    }
    v3->Flags |= 0x40u;
  }
  else
  {
    v3->Flags &= 0xFFFFFFBF;
  }
  v12 = v3->pDocument.pObject->pEditorKit.pObject;
  if ( v12 )
  {
    v13 = v3->pASRoot->pMovieImpl;
    if ( Scaleform::GFx::MovieImpl::IsFocused(v13, (Scaleform::GFx::InteractiveObject *)&v3->vfptr)
      || (LOBYTE(v12[10].vfptr) >> 5) & 1 )
    {
      v14 = v13->TimeElapsed;
      v15 = (double)(signed int)v14;
      if ( v14 < 0 )
        v15 = v15 + 1.844674407370955e19;
      Scaleform::GFx::Text::EditorKit::Advance((Scaleform::GFx::Text::EditorKit *)v12, v15 * 0.000001);
    }
  }
  if ( v3->Flags & 0x10000 )
  {
    v16 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
    Scaleform::Render::TreeText::NotifyLayoutChanged(v16);
  }
}

// File Line: 558
// RVA: 0x8E3270
bool __fastcall Scaleform::GFx::TextField::HasStyleSheet(Scaleform::GFx::TextField *this)
{
  unsigned __int8 v1; // al
  __int64 v2; // rax

  v1 = this->AvmObjOffset;
  if ( !v1 )
    return 0;
  v2 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v1))[4].__vecDelDtor)();
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 184i64))(v2);
}

// File Line: 565
// RVA: 0x8DE790
Scaleform::GFx::Text::StyleManager *__fastcall Scaleform::GFx::TextField::GetStyleSheet(Scaleform::GFx::TextField *this)
{
  unsigned __int8 v1; // al
  __int64 v2; // rax

  v1 = this->AvmObjOffset;
  if ( !v1 )
    return 0i64;
  v2 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v1))[4].__vecDelDtor)();
  return (Scaleform::GFx::Text::StyleManager *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 176i64))(v2);
}

// File Line: 572
// RVA: 0x8E78F0
bool __fastcall Scaleform::GFx::TextField::IsTabable(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // rbx
  Scaleform::Render::Text::EditorKitBase *v2; // rcx
  unsigned __int8 v3; // al
  int v4; // eax
  unsigned __int8 v5; // cl
  __int64 v6; // rax
  bool result; // al
  bool v8; // zf
  char v9; // al

  v1 = this;
  if ( (this->pDef.pObject->Flags >> 12) & 1 || !((unsigned __int8 (*)(void))this->vfptr[59].__vecDelDtor)() )
    return 0;
  v2 = v1->pDocument.pObject->pEditorKit.pObject;
  v3 = v2 ? ((unsigned __int8 (*)(void))v2->vfptr[2].__vecDelDtor)() : (LOBYTE(v1->pDef.pObject->Flags) >> 3) & 1;
  if ( v3 )
    return 0;
  v4 = v1->Flags & 0x60;
  if ( v4 || (v5 = v1->AvmObjOffset) == 0 )
  {
    if ( !v4 || (v8 = v4 == 96, v9 = 1, v8) )
      v9 = 0;
    result = v9 == 0;
  }
  else
  {
    v6 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr + 4 * v5))[4].__vecDelDtor)((signed __int64)v1 + 4 * v5);
    result = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v6 + 168i64))(v6);
  }
  return result;
}

// File Line: 591
// RVA: 0x90DE40
char __fastcall Scaleform::GFx::TextField::SetTextValue(Scaleform::GFx::TextField *this, const char *pnewText, bool html, bool notifyVariable)
{
  bool v4; // r12
  const char *v5; // r15
  Scaleform::GFx::TextField *v6; // rsi
  Scaleform::Render::Text::StyleManagerBase *v7; // r14
  signed int v8; // ebx
  Scaleform::String *v9; // rdi
  unsigned __int64 v10; // rax
  const char *v11; // r10
  int v12; // ecx
  int v13; // edx
  unsigned __int8 v15; // al
  __int64 v16; // rax
  const char *v17; // r13
  char v18; // di
  char v19; // r15
  const char *v20; // rcx
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // zf
  bool v23; // di
  Scaleform::Render::Text::DocView *v24; // rbx
  Scaleform::GFx::Text::StyleManager *pstyleMgr; // rax
  unsigned __int64 v26; // rbx
  Scaleform::MemoryHeap *v27; // rax
  Scaleform::Render::Text::TextFormat *v28; // rax
  Scaleform::Render::Text::ParagraphFormat *v29; // rax
  Scaleform::MemoryHeap *v30; // rax
  bool v31; // di
  Scaleform::GFx::ASStringNode *v32; // rcx
  Scaleform::Render::Text::DocView *v33; // rbx
  Scaleform::GFx::Text::StyleManager *v34; // rax
  wchar_t *v35; // rdx
  Scaleform::MemoryHeap *v36; // rax
  Scaleform::Render::Text::TextFormat *v37; // rax
  Scaleform::Render::Text::ParagraphFormat *v38; // rax
  Scaleform::MemoryHeap *v39; // rax
  unsigned __int8 v40; // al
  __int64 v41; // rax
  Scaleform::Render::Text::EditorKitBase *v42; // rcx
  unsigned __int64 v43; // rax
  Scaleform::GFx::Text::EditorKit *v44; // rcx
  unsigned __int8 v45; // al
  __int64 v46; // rax
  unsigned __int8 v47; // al
  __int64 v48; // rax
  unsigned __int8 v49; // al
  __int64 v50; // rax
  Scaleform::Render::TreeText *v51; // rax
  Scaleform::Render::TreeText *v52; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imageInfoArray; // [rsp+40h] [rbp-C0h]
  unsigned int v54; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::ASString v55; // [rsp+68h] [rbp-98h]
  Scaleform::Render::Text::ParagraphFormat pparaFmt; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Text::ParagraphFormat *ppdestParaFmt; // [rsp+98h] [rbp-68h]
  Scaleform::Render::Text::TextFormat ptextFmt; // [rsp+A0h] [rbp-60h]
  __int64 v59; // [rsp+F0h] [rbp-10h]
  Scaleform::Render::Text::TextFormat v60; // [rsp+F8h] [rbp-8h]
  __int128 v61; // [rsp+150h] [rbp+50h]
  const char *v62; // [rsp+160h] [rbp+60h]
  Scaleform::GFx::ASString v63; // [rsp+168h] [rbp+68h]
  char *v64; // [rsp+170h] [rbp+70h]
  __int64 v65; // [rsp+178h] [rbp+78h]
  char v66; // [rsp+180h] [rbp+80h]
  char *v67; // [rsp+580h] [rbp+480h]
  __int64 v68; // [rsp+588h] [rbp+488h]
  char v69; // [rsp+590h] [rbp+490h]
  wchar_t *pstring; // [rsp+990h] [rbp+890h]
  __int64 v71; // [rsp+998h] [rbp+898h]
  char *v72; // [rsp+9A0h] [rbp+8A0h]
  __int64 v73; // [rsp+9A8h] [rbp+8A8h]
  Scaleform::WStringBuffer pBuffer; // [rsp+9B0h] [rbp+8B0h]
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+A10h] [rbp+910h]
  bool v76; // [rsp+A28h] [rbp+928h]

  v76 = notifyVariable;
  v59 = -2i64;
  v4 = html;
  v5 = pnewText;
  v6 = this;
  v7 = 0i64;
  v8 = 0;
  v54 = 0;
  v9 = (Scaleform::String *)&this->OriginalTextValue.0;
  v10 = (this->OriginalTextValue.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12;
  v11 = &pnewText[-v10];
  do
  {
    v12 = (unsigned __int8)v11[v10];
    v13 = *(unsigned __int8 *)v10 - v12;
    if ( *(unsigned __int8 *)v10 != v12 )
      break;
    ++v10;
  }
  while ( v12 );
  if ( !v13 && !(v6->Flags & 0x10000) )
    return 0;
  v6->Flags &= 0xFFFEFFFF;
  v15 = v6->AvmObjOffset;
  if ( v15 )
  {
    v16 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr + 4 * v15))[4].__vecDelDtor)();
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v16 + 184i64))(v16) )
    {
      v4 = 1;
      v6->Flags |= 2u;
    }
  }
  Scaleform::String::operator=(v9, v5);
  if ( v4 )
    v6->Flags |= 0x1000u;
  else
    v6->Flags &= 0xFFFFEFFF;
  v17 = (const char *)((v9->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  v18 = 0;
  v19 = 0;
  if ( (v6->Flags >> 3) & 1 )
    goto LABEL_71;
  Scaleform::GFx::StateBag::GetTranslator((Scaleform::GFx::StateBag *)&v6->pASRoot->pMovieImpl->vfptr, &result);
  if ( result.pObject )
  {
    if ( (LOBYTE(v6->Flags) >> 1) & 1 )
    {
      v20 = &customWorldMapCaption;
    }
    else
    {
      v8 = 1;
      v54 = 1;
      v20 = Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)&v6->vfptr, &v55)->pNode->pData;
    }
    _mm_store_si128((__m128i *)&v61, (__m128i)0i64);
    LOBYTE(v63.pNode) = 0;
    v64 = &v66;
    v65 = 512i64;
    v67 = &v69;
    v68 = 512i64;
    pstring = (wchar_t *)&v66;
    v71 = 0i64;
    v72 = &v66;
    v73 = 512i64;
    pBuffer.pText = (wchar_t *)&v69;
    pBuffer.Length = 0i64;
    pBuffer.Reserved.pBuffer = (wchar_t *)&v69;
    pBuffer.Reserved.Size = 512i64;
    *((_QWORD *)&v61 + 1) = &pstring;
    v62 = v20;
    if ( v8 & 1 )
    {
      v54 = v8 & 0xFFFFFFFE;
      v21 = v55.pNode;
      v22 = v55.pNode->RefCount == 1;
      --v21->RefCount;
      if ( v22 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v21);
    }
    if ( !v4 || ((__int64 (*)(void))result.pObject->vfptr[1].__vecDelDtor)() & 1 )
    {
      v26 = (signed int)((unsigned __int64)Scaleform::UTF8Util::GetLength(v17, -1i64) + 1);
      Scaleform::WStringBuffer::Resize(&pBuffer, v26);
      Scaleform::UTF8Util::DecodeStringSafe(pBuffer.pText, v26, v17, -1i64);
      *(_QWORD *)&v61 = pBuffer.pText;
      if ( v4 )
        LOBYTE(v63.pNode) |= 4u;
      result.pObject->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)result.pObject, (unsigned int)&v61);
    }
    else
    {
      v23 = (v6->Flags >> 4) & 1;
      v24 = v6->pDocument.pObject;
      pstyleMgr = Scaleform::GFx::TextField::GetStyleSheet(v6);
      Scaleform::Render::Text::DocView::ParseHtml(
        v24,
        v17,
        0xFFFFFFFFFFFFFFFFui64,
        v23,
        0i64,
        (Scaleform::Render::Text::StyleManagerBase *)&pstyleMgr->vfptr,
        0i64,
        0i64);
      Scaleform::Render::Text::StyledText::GetText(
        (Scaleform::Render::Text::StyledText *)&v6->pDocument.pObject->pDocument.pObject->vfptr,
        &pBuffer);
      if ( (((unsigned int (*)(void))result.pObject->vfptr[1].__vecDelDtor)() >> 1) & 1 )
        Scaleform::WStringBuffer::StripTrailingNewLines(&pBuffer);
      *(_QWORD *)&v61 = pBuffer.pText;
      result.pObject->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)result.pObject, (unsigned int)&v61);
      v18 = 0;
    }
    v19 = (_QWORD)v63.pNode & 1;
    if ( (_QWORD)v63.pNode & 1 )
    {
      if ( (_QWORD)v63.pNode & 2 )
      {
        v27 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v6);
        Scaleform::Render::Text::TextFormat::TextFormat(&ptextFmt, v27);
        pparaFmt.pAllocator = 0i64;
        pparaFmt.RefCount = 1;
        pparaFmt.pTabStops = 0i64;
        *(_QWORD *)&pparaFmt.BlockIndent = 0i64;
        *(_DWORD *)&pparaFmt.RightMargin = 0;
        Scaleform::GFx::TextField::GetInitialFormats(v6, &ptextFmt, &pparaFmt);
        if ( !(v6->Flags & 1) )
        {
          v28 = Scaleform::Render::Text::TextFormat::Merge(
                  &ptextFmt,
                  &v60,
                  v6->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject);
          Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v28);
          Scaleform::Render::Text::TextFormat::~TextFormat(&v60);
          v29 = Scaleform::Render::Text::ParagraphFormat::Merge(
                  &pparaFmt,
                  (Scaleform::Render::Text::ParagraphFormat *)&v60,
                  v6->pDocument.pObject->pDocument.pObject->pDefaultParagraphFormat.pObject);
          Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v29);
          Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat((Scaleform::Render::Text::ParagraphFormat *)&v60);
        }
        v30 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v6);
        ppdestParaFmt = (Scaleform::Render::Text::ParagraphFormat *)&imageInfoArray;
        imageInfoArray.Data.Data = 0i64;
        imageInfoArray.Data.Size = 0i64;
        imageInfoArray.Data.Policy.Capacity = 0i64;
        imageInfoArray.Data.pHeap = v30;
        v31 = (v6->Flags >> 4) & 1;
        v32 = (Scaleform::GFx::ASStringNode *)byte_1416A7BD8;
        if ( pstring )
          v32 = (Scaleform::GFx::ASStringNode *)pstring;
        v55.pNode = v32;
        v33 = v6->pDocument.pObject;
        v34 = Scaleform::GFx::TextField::GetStyleSheet(v6);
        Scaleform::Render::Text::DocView::ParseHtml(
          v33,
          (const wchar_t *)v55.pNode,
          0xFFFFFFFFFFFFFFFFui64,
          v31,
          &imageInfoArray,
          (Scaleform::Render::Text::StyleManagerBase *)&v34->vfptr,
          &ptextFmt,
          &pparaFmt);
        if ( imageInfoArray.Data.Size )
          Scaleform::GFx::TextField::ProcessImageTags(v6, &imageInfoArray);
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
          (Scaleform::Render::Text::StyledText *)&v6->pDocument.pObject->pDocument.pObject->vfptr,
          (Scaleform::Render::Text::TextFormat **)&v55,
          &ppdestParaFmt,
          0i64);
        Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
          (Scaleform::Render::Text::StyledText *)&v6->pDocument.pObject->pDocument.pObject->vfptr,
          (Scaleform::Render::Text::TextFormat *)v55.pNode);
        Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
          (Scaleform::Render::Text::StyledText *)&v6->pDocument.pObject->pDocument.pObject->vfptr,
          ppdestParaFmt);
        v35 = (wchar_t *)byte_1416A7BD8;
        if ( pstring )
          v35 = pstring;
        Scaleform::Render::Text::DocView::SetText(v6->pDocument.pObject, v35, 0xFFFFFFFFFFFFFFFFui64);
      }
      v18 = 1;
    }
    Scaleform::WStringBuffer::~WStringBuffer(&pBuffer);
    Scaleform::WStringBuffer::~WStringBuffer((Scaleform::WStringBuffer *)&pstring);
  }
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( !v19 )
  {
LABEL_71:
    if ( v4 )
    {
      v36 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v6);
      Scaleform::Render::Text::TextFormat::TextFormat(&ptextFmt, v36);
      pparaFmt.pAllocator = 0i64;
      pparaFmt.RefCount = 1;
      pparaFmt.pTabStops = 0i64;
      *(_QWORD *)&pparaFmt.BlockIndent = 0i64;
      *(_DWORD *)&pparaFmt.RightMargin = 0;
      Scaleform::GFx::TextField::GetInitialFormats(v6, &ptextFmt, &pparaFmt);
      if ( !(v6->Flags & 1) )
      {
        v37 = Scaleform::Render::Text::TextFormat::Merge(
                &ptextFmt,
                &v60,
                v6->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject);
        Scaleform::Render::Text::TextFormat::operator=(&ptextFmt, v37);
        Scaleform::Render::Text::TextFormat::~TextFormat(&v60);
        v38 = Scaleform::Render::Text::ParagraphFormat::Merge(
                &pparaFmt,
                (Scaleform::Render::Text::ParagraphFormat *)&v60,
                v6->pDocument.pObject->pDocument.pObject->pDefaultParagraphFormat.pObject);
        Scaleform::Render::Text::ParagraphFormat::operator=(&pparaFmt, v38);
        Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat((Scaleform::Render::Text::ParagraphFormat *)&v60);
      }
      v39 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v6);
      result.pObject = (Scaleform::GFx::Translator *)&imageInfoArray;
      imageInfoArray.Data.Data = 0i64;
      imageInfoArray.Data.Size = 0i64;
      imageInfoArray.Data.Policy.Capacity = 0i64;
      imageInfoArray.Data.pHeap = v39;
      v40 = v6->AvmObjOffset;
      if ( v40 )
      {
        v41 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr + 4 * v40))[4].__vecDelDtor)();
        v7 = (Scaleform::Render::Text::StyleManagerBase *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v41 + 176i64))(v41);
      }
      Scaleform::Render::Text::DocView::ParseHtml(
        v6->pDocument.pObject,
        v17,
        0xFFFFFFFFFFFFFFFFui64,
        (v6->Flags >> 4) & 1,
        &imageInfoArray,
        v7,
        &ptextFmt,
        &pparaFmt);
      if ( imageInfoArray.Data.Size )
        Scaleform::GFx::TextField::ProcessImageTags(v6, &imageInfoArray);
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
      Scaleform::Render::Text::DocView::SetText(v6->pDocument.pObject, v17, 0xFFFFFFFFFFFFFFFFui64);
    }
  }
  v42 = v6->pDocument.pObject->pEditorKit.pObject;
  if ( v42 )
  {
    if ( !((unsigned __int8 (*)(void))v42->vfptr[2].__vecDelDtor)() )
    {
      v43 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&v6->pDocument.pObject->pDocument.pObject->vfptr);
      v44 = (Scaleform::GFx::Text::EditorKit *)v6->pDocument.pObject->pEditorKit.pObject;
      if ( v44->CursorPos > v43 )
        Scaleform::GFx::Text::EditorKit::SetCursorPos(v44, v43, 0);
    }
  }
  v45 = v6->AvmObjOffset;
  if ( v45 )
  {
    v46 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr + 4 * v45))[4].__vecDelDtor)();
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v46 + 184i64))(v46);
  }
  if ( v76 )
  {
    v47 = v6->AvmObjOffset;
    if ( v47 )
    {
      v48 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr + 4 * v47))[4].__vecDelDtor)();
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v48 + 256i64))(v48);
    }
  }
  if ( v18 )
  {
    v49 = v6->AvmObjOffset;
    if ( v49 )
    {
      v50 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr + 4 * v49))[4].__vecDelDtor)();
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v50 + 192i64))(v50);
    }
    v51 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v6->vfptr);
    Scaleform::Render::TreeText::NotifyLayoutChanged(v51);
  }
  v6->Flags |= 0x2000u;
  v52 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v6->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v52);
  return 1;
}

// File Line: 787
// RVA: 0x913B60
Scaleform::Render::Point<float> *__fastcall Scaleform::GFx::TextField::TransformToTextRectSpace(Scaleform::GFx::TextField *this, Scaleform::Render::Point<float> *result, Scaleform::GFx::Value::DisplayInfo *info)
{
  Scaleform::GFx::Value::DisplayInfo *v3; // rbx
  Scaleform::Render::Point<float> *v4; // rsi
  Scaleform::GFx::TextField *v5; // rdi
  __int64 v6; // rbp
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  Scaleform::Render::Rect<float> *v10; // rax
  float v11; // xmm0_4
  float v12; // xmm2_4
  Scaleform::Render::Point<float> *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm3_4
  float v16; // xmm1_4
  Scaleform::Render::Point<float> resulta; // [rsp+30h] [rbp+8h]

  v3 = info;
  v4 = result;
  v5 = this;
  v6 = ((__int64 (*)(void))this->vfptr[2].__vecDelDtor)();
  if ( (LOBYTE(v3->VarsSet) >> 1) & 1 )
    v7 = v3->Y * 20.0;
  else
    v7 = (float)v5->pGeomData->Y;
  if ( v3->VarsSet & 1 )
    v8 = v3->X * 20.0;
  else
    v8 = (float)v5->pGeomData->X;
  v4->x = v8;
  v4->y = v7;
  Scaleform::Render::Matrix2x4<float>::TransformByInverse((Scaleform::Render::Matrix2x4<float> *)v6, &resulta, v4);
  v9 = resulta.y;
  v4->x = resulta.x;
  v4->y = v9;
  v10 = Scaleform::Render::Text::DocView::GetViewRect(v5->pDocument.pObject);
  v11 = v10->y1;
  v12 = v4->x - v10->x1;
  v13 = v4;
  v14 = v4->y - v11;
  v4->x = v12;
  v4->y = v14;
  v15 = (float)((float)(v14 * *(float *)(v6 + 20)) + (float)(v12 * *(float *)(v6 + 16))) + *(float *)(v6 + 28);
  v16 = (float)((float)(v14 * *(float *)(v6 + 4)) + (float)(v12 * *(float *)v6)) + *(float *)(v6 + 12);
  v4->y = v15 * 0.050000001;
  v4->x = v16 * 0.050000001;
  return v13;
}

// File Line: 804
// RVA: 0x8DC230
void __fastcall Scaleform::GFx::TextField::GetPosition(Scaleform::GFx::TextField *this, Scaleform::GFx::Value::DisplayInfo *pinfo)
{
  Scaleform::GFx::Value::DisplayInfo *v2; // rbx
  Scaleform::GFx::TextField *v3; // rdi
  Scaleform::Render::TreeNode *v4; // rcx
  double v5; // xmm7_8
  double v6; // xmm8_8
  Scaleform::Render::Cxform *v7; // rdx
  long double v8; // xmm6_8
  char v9; // al
  long double v10; // xmm0_8
  long double v11; // xmm1_8
  long double v12; // xmm0_8
  long double v13; // xmm0_8
  long double v14; // xmm1_8
  long double v15; // xmm0_8
  long double v16; // xmm1_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [rsp+20h] [rbp-98h]

  v2 = pinfo;
  v3 = this;
  *(_OWORD *)&pgeomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&pgeomData.OrigMatrix.M[1][0] = _xmm;
  pgeomData.YScale = DOUBLE_100_0;
  pgeomData.XScale = DOUBLE_100_0;
  pgeomData.Rotation = 0.0;
  *(_OWORD *)&pgeomData.XRotation = 0i64;
  *(_QWORD *)&pgeomData.X = 0i64;
  *(_OWORD *)&pgeomData.Z = _xmm;
  Scaleform::GFx::TextField::UpdateAndGetGeomData(this, &pgeomData, 0);
  v4 = v3->pRenNode.pObject;
  v5 = (double)pgeomData.X * 0.05;
  v6 = (double)pgeomData.Y * 0.05;
  if ( v4 )
    v7 = (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                 + 8
                                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1] - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1] - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                 + 40)
                                     + 80i64);
  else
    v7 = &Scaleform::Render::Cxform::Identity;
  v8 = (float)(v7->M[0][3] * 100.0);
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v3->vfptr[59].__vecDelDtor)(v3);
  v10 = pgeomData.Rotation;
  v2->Visible = v9;
  v11 = pgeomData.XScale;
  v2->Rotation = v10;
  v12 = pgeomData.YScale;
  v2->VarsSet |= 0x7FFu;
  v2->YScale = v12;
  v13 = pgeomData.Z;
  v2->XScale = v11;
  v14 = pgeomData.XRotation;
  v2->Z = v13;
  v15 = pgeomData.YRotation;
  v2->XRotation = v14;
  v16 = pgeomData.ZScale;
  v2->X = v5;
  v2->Y = v6;
  v2->Alpha = v8;
  v2->YRotation = v15;
  v2->ZScale = v16;
}

// File Line: 822
// RVA: 0x8DE860
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::TextField::GetText(Scaleform::GFx::TextField *this, Scaleform::GFx::ASString *result, bool reqHtml)
{
  bool v3; // bl
  Scaleform::GFx::ASString *v4; // rdi
  Scaleform::GFx::TextField *v5; // rsi
  Scaleform::GFx::ASMovieRootBase *v6; // rcx
  Scaleform::GFx::ASStringManager *v7; // rbp
  unsigned __int8 v8; // cl
  __int64 v9; // rax
  Scaleform::Render::Text::DocView *v10; // rcx
  Scaleform::String *v11; // rax
  Scaleform::String::DataDesc *v12; // rdx
  Scaleform::String *v13; // rax
  Scaleform::String *v14; // rax
  Scaleform::String v16; // [rsp+28h] [rbp-30h]
  __int64 v17; // [rsp+30h] [rbp-28h]
  Scaleform::String resulta; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString *v19; // [rsp+68h] [rbp+10h]
  Scaleform::String v20; // [rsp+78h] [rbp+20h]

  v19 = result;
  v17 = -2i64;
  v3 = reqHtml;
  v4 = result;
  v5 = this;
  v6 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v7 = (Scaleform::GFx::ASStringManager *)((__int64 (__cdecl *)(Scaleform::GFx::ASMovieRootBase *))v6->vfptr[59].__vecDelDtor)(v6);
  if ( v3 )
  {
    v8 = v5->AvmObjOffset;
    if ( v8 )
    {
      v9 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->vfptr + 4 * v8))[4].__vecDelDtor)();
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v9 + 184i64))(v9) )
      {
        Scaleform::GFx::ASStringManager::CreateString(v7, v4, (Scaleform::String *)&v5->OriginalTextValue.0);
        return v4;
      }
    }
    v10 = v5->pDocument.pObject;
    if ( (v5->Flags >> 1) & 1 )
    {
      v11 = Scaleform::Render::Text::DocView::GetHtml(v10, &resulta);
      Scaleform::GFx::ASStringManager::CreateString(v7, v4, v11);
      v12 = resulta.pData;
    }
    else
    {
      v13 = Scaleform::Render::Text::DocView::GetText(v10, &v20);
      Scaleform::GFx::ASStringManager::CreateString(v7, v4, v13);
      v12 = v20.pData;
    }
  }
  else
  {
    v14 = Scaleform::Render::Text::DocView::GetText(v5->pDocument.pObject, &v16);
    Scaleform::GFx::ASStringManager::CreateString(v7, v4, v14);
    v12 = v16.pData;
  }
  if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v12 & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v4;
}

// File Line: 847
// RVA: 0x8D9B70
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::TextField::GetHtml(Scaleform::GFx::TextField *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::TextField *v3; // rbx
  Scaleform::GFx::ASMovieRootBase *v4; // rcx
  Scaleform::GFx::ASStringManager *v5; // rdi
  Scaleform::String *v6; // rax
  Scaleform::String resulta; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString *v9; // [rsp+48h] [rbp+10h]

  v9 = result;
  v2 = result;
  v3 = this;
  v4 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v5 = (Scaleform::GFx::ASStringManager *)((__int64 (__cdecl *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::ASString *))v4->vfptr[59].__vecDelDtor)(
                                            v4,
                                            result);
  v6 = Scaleform::Render::Text::DocView::GetHtml(v3->pDocument.pObject, &resulta);
  Scaleform::GFx::ASStringManager::CreateString(v5, v2, v6);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((resulta.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v2;
}

// File Line: 856
// RVA: 0x8E05B0
signed __int64 __fastcall Scaleform::GFx::TextField::GetTopMostMouseEntity(Scaleform::GFx::TextField *this, Scaleform::Render::Point<float> *pt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v3; // rsi
  Scaleform::Render::Point<float> *v4; // rbx
  Scaleform::GFx::TextField *v5; // rdi
  signed __int64 result; // rax
  Scaleform::GFx::DisplayObject *v7; // rax
  __int64 v8; // r8
  Scaleform::GFx::DisplayObject *v9; // r14
  Scaleform::GFx::DisplayObjectBase *v10; // rcx
  float *v11; // rax
  __int64 v12; // kr00_8
  __int64 v13; // kr08_8
  float v14; // xmm0_4
  float v15; // xmm2_4
  _OWORD *v16; // rax
  Scaleform::GFx::DisplayObjectBase *v17; // rcx
  float *v18; // rax
  __int64 v19; // r8
  __int64 v20; // kr10_8
  __int64 v21; // kr18_8
  float v22; // xmm11_4
  float v23; // xmm12_4
  float v24; // xmm5_4
  float v25; // xmm10_4
  float v26; // xmm11_4
  float v27; // xmm12_4
  float v28; // xmm2_4
  float v29; // xmm13_4
  float v30; // xmm14_4
  float *v31; // rax
  Scaleform::GFx::DisplayObjectBase *v32; // rcx
  Scaleform::Render::Matrix3x4<float> *v33; // rax
  _OWORD *v34; // rax
  signed __int64 v35; // rbx
  Scaleform::Render::Text::DocView *v36; // rcx
  Scaleform::GFx::InteractiveObject *v37; // rbx
  unsigned __int8 v38; // al
  __int64 v39; // rax
  Scaleform::GFx::InteractiveObject *v40; // rax
  float v41; // xmm1_4
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-D0h]
  int v43; // [rsp+50h] [rbp-B0h]
  int v44; // [rsp+54h] [rbp-ACh]
  int v45; // [rsp+58h] [rbp-A8h]
  int v46; // [rsp+5Ch] [rbp-A4h]
  Scaleform::Render::Matrix2x4<float> v47; // [rsp+60h] [rbp-A0h]
  __int128 v48; // [rsp+80h] [rbp-80h]
  int Dst; // [rsp+90h] [rbp-70h]
  int v50; // [rsp+94h] [rbp-6Ch]
  int v51; // [rsp+98h] [rbp-68h]
  int v52; // [rsp+9Ch] [rbp-64h]
  int v53; // [rsp+A0h] [rbp-60h]
  int v54; // [rsp+A4h] [rbp-5Ch]
  int v55; // [rsp+A8h] [rbp-58h]
  int v56; // [rsp+ACh] [rbp-54h]
  int v57; // [rsp+B0h] [rbp-50h]
  int v58; // [rsp+B4h] [rbp-4Ch]
  int v59; // [rsp+B8h] [rbp-48h]
  int v60; // [rsp+BCh] [rbp-44h]
  int v61; // [rsp+C0h] [rbp-40h]
  int v62; // [rsp+C4h] [rbp-3Ch]
  int v63; // [rsp+C8h] [rbp-38h]
  int v64; // [rsp+CCh] [rbp-34h]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::Point<float> p; // [rsp+1C0h] [rbp+C0h]
  Scaleform::Render::Point<float> ptOut; // [rsp+1D0h] [rbp+D0h]

  v3 = pdescr;
  v4 = pt;
  pdescr->pResult = 0i64;
  v5 = this;
  if ( (this->pDef.pObject->Flags >> 12) & 1
    || (this->Flags >> 11) & 1
    || !((unsigned __int8 (*)(void))this->vfptr[59].__vecDelDtor)()
    || (Scaleform::GFx::TextField *)v3->pIgnoreMC == v5 )
  {
    return 2i64;
  }
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(
    (Scaleform::GFx::DisplayObjectBase *)&v5->vfptr,
    &p,
    v4,
    1,
    0i64);
  v7 = Scaleform::GFx::DisplayObject::GetMask((Scaleform::GFx::DisplayObject *)&v5->vfptr);
  v9 = v7;
  if ( v7
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v7->vfptr[78].__vecDelDtor)(v7)
    && !((LOBYTE(v9->Flags) >> 4) & 1) )
  {
    if ( Scaleform::GFx::DisplayObjectBase::Has3D((Scaleform::GFx::DisplayObjectBase *)&v9->vfptr) )
    {
      memset(&pmat, 0, 0x30ui64);
      pmat.M[0][0] = 1.0;
      pmat.M[1][1] = 1.0;
      v45 = 1065353216;
      memset(&Dst, 0, 0x40ui64);
      Dst = 1065353216;
      v54 = 1065353216;
      v59 = 1065353216;
      v64 = 1065353216;
      memset(&v47, 0, 0x30ui64);
      v32 = v9->pParentChar;
      v47.M[0][0] = 1.0;
      v47.M[1][1] = 1.0;
      DWORD2(v48) = 1065353216;
      if ( v32 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(v32, (Scaleform::Render::Matrix3x4<float> *)&v47);
        v33 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v9->vfptr[4].__vecDelDtor)(v9);
        *(__m256i *)&m1.M[0][0] = (__m256i)v47;
        *(_OWORD *)&m1.M[2][0] = v48;
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix((Scaleform::Render::Matrix3x4<float> *)&v47, &m1, v33);
      }
      else
      {
        v34 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v9->vfptr[4].__vecDelDtor)(v9);
        *(_OWORD *)&v47.M[0][0] = *v34;
        *(_OWORD *)&v47.M[1][0] = v34[1];
        v48 = v34[2];
      }
      v35 = (signed __int64)&v5->pASRoot->pMovieImpl->ScreenToWorld;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, int *, _QWORD))v9->vfptr[6].__vecDelDtor)(
             v9,
             &Dst,
             0i64) )
      {
        *(_DWORD *)(v35 + 16) = Dst;
        *(_DWORD *)(v35 + 20) = v50;
        *(_DWORD *)(v35 + 24) = v51;
        *(_DWORD *)(v35 + 28) = v52;
        *(_DWORD *)(v35 + 32) = v53;
        *(_DWORD *)(v35 + 36) = v54;
        *(_DWORD *)(v35 + 40) = v55;
        *(_DWORD *)(v35 + 44) = v56;
        *(_DWORD *)(v35 + 48) = v57;
        *(_DWORD *)(v35 + 52) = v58;
        *(_DWORD *)(v35 + 56) = v59;
        *(_DWORD *)(v35 + 60) = v60;
        *(_DWORD *)(v35 + 64) = v61;
        *(_DWORD *)(v35 + 68) = v62;
        *(_DWORD *)(v35 + 72) = v63;
        *(_DWORD *)(v35 + 76) = v64;
      }
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Matrix2x4<float> *, _QWORD))v9->vfptr[9].__vecDelDtor)(
             v9,
             &pmat,
             0i64) )
      {
        *(_OWORD *)(v35 + 80) = *(_OWORD *)&pmat.M[0][0];
        *(_OWORD *)(v35 + 96) = *(_OWORD *)&pmat.M[1][0];
        *(_DWORD *)(v35 + 112) = v43;
        *(_DWORD *)(v35 + 116) = v44;
        *(_DWORD *)(v35 + 120) = v45;
        *(_DWORD *)(v35 + 124) = v46;
      }
      *(_OWORD *)(v35 + 128) = *(_OWORD *)&v47.M[0][0];
      *(_OWORD *)(v35 + 144) = *(_OWORD *)&v47.M[1][0];
      *(_OWORD *)(v35 + 160) = v48;
      Scaleform::Render::ScreenToWorld::GetWorldPoint((Scaleform::Render::ScreenToWorld *)v35, &ptOut);
    }
    else
    {
      v10 = v9->pParentChar;
      *(_OWORD *)&v47.M[0][0] = _xmm;
      *(__m128 *)&v47.M[1][0] = _xmm;
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      if ( v10 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v10, &pmat);
        v11 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v9->vfptr[2].__vecDelDtor)(v9);
        v12 = *(_QWORD *)&pmat.M[0][0];
        v13 = *(_QWORD *)&pmat.M[1][0];
        pmat.M[0][0] = (float)(pmat.M[0][1] * v11[4]) + (float)(pmat.M[0][0] * *v11);
        pmat.M[1][0] = (float)(pmat.M[1][1] * v11[4]) + (float)(pmat.M[1][0] * *v11);
        pmat.M[0][1] = (float)(*(float *)&v12 * v11[1]) + (float)(pmat.M[0][1] * v11[5]);
        v14 = pmat.M[1][1] * v11[5];
        v15 = *(float *)&v13 * v11[1];
        pmat.M[0][2] = 0.0;
        *(_QWORD *)&pmat.M[1][1] = COERCE_UNSIGNED_INT(v15 + v14);
        pmat.M[0][3] = pmat.M[0][3] + (float)((float)(*((float *)&v12 + 1) * v11[7]) + (float)(*(float *)&v12 * v11[3]));
        pmat.M[1][3] = pmat.M[1][3] + (float)((float)(*((float *)&v13 + 1) * v11[7]) + (float)(*(float *)&v13 * v11[3]));
      }
      else
      {
        v16 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v9->vfptr[2].__vecDelDtor)(v9);
        *(_OWORD *)&pmat.M[0][0] = *v16;
        *(_OWORD *)&pmat.M[1][0] = v16[1];
      }
      Scaleform::Render::Matrix2x4<float>::SetInverse(&v47, &pmat);
      v17 = v5->pParentChar;
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      if ( v17 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v17, &pmat);
        v18 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[2].__vecDelDtor)(v5);
        v20 = *(_QWORD *)&pmat.M[0][0];
        v21 = *(_QWORD *)&pmat.M[1][0];
        v22 = pmat.M[0][0];
        v23 = pmat.M[1][0];
        v24 = (float)(pmat.M[0][0] * *v18) + (float)(pmat.M[0][1] * v18[4]);
        pmat.M[0][0] = (float)(pmat.M[0][0] * *v18) + (float)(pmat.M[0][1] * v18[4]);
        v25 = (float)(pmat.M[1][0] * *v18) + (float)(pmat.M[1][1] * v18[4]);
        pmat.M[1][0] = (float)(pmat.M[1][0] * *v18) + (float)(pmat.M[1][1] * v18[4]);
        v26 = (float)(v22 * v18[1]) + (float)(pmat.M[0][1] * v18[5]);
        *(_QWORD *)&pmat.M[0][1] = LODWORD(v26);
        v27 = (float)(v23 * v18[1]) + (float)(pmat.M[1][1] * v18[5]);
        *(_QWORD *)&pmat.M[1][1] = LODWORD(v27);
        v28 = (float)(*((float *)&v20 + 1) * v18[7]) + (float)(*(float *)&v20 * v18[3]);
        v29 = pmat.M[0][3] + v28;
        pmat.M[0][3] = pmat.M[0][3] + v28;
        v30 = pmat.M[1][3] + (float)((float)(*((float *)&v21 + 1) * v18[7]) + (float)(*(float *)&v21 * v18[3]));
      }
      else
      {
        v31 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v5->vfptr[2].__vecDelDtor)(v5);
        v24 = *v31;
        pmat.M[0][0] = *v31;
        v26 = v31[1];
        *(_QWORD *)&pmat.M[0][1] = *(_QWORD *)(v31 + 1);
        v29 = v31[3];
        pmat.M[0][3] = v31[3];
        v25 = v31[4];
        pmat.M[1][0] = v31[4];
        v27 = v31[5];
        *(_QWORD *)&pmat.M[1][1] = *(_QWORD *)(v31 + 5);
        v30 = v31[7];
      }
      ptOut.x = (float)((float)((float)((float)(v47.M[0][1] * v25) + (float)(v47.M[0][0] * v24)) * p.x)
                      + (float)((float)((float)(v47.M[0][1] * v27) + (float)(v47.M[0][0] * v26)) * p.y))
              + (float)(v47.M[0][3] + (float)((float)(v47.M[0][1] * v30) + (float)(v47.M[0][0] * v29)));
      ptOut.y = (float)((float)((float)((float)(v47.M[1][1] * v25) + (float)(v47.M[1][0] * v24)) * p.x)
                      + (float)((float)((float)(v47.M[1][1] * v27) + (float)(v47.M[1][0] * v26)) * p.y))
              + (float)(v47.M[1][3] + (float)((float)(v47.M[1][1] * v30) + (float)(v47.M[1][0] * v29)));
    }
    LOBYTE(v19) = 1;
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Point<float> *, __int64))v9->vfptr[63].__vecDelDtor)(
            v9,
            &ptOut,
            v19) )
    {
      v3->pResult = 0i64;
      return 2i64;
    }
  }
  if ( v5->ClipDepth )
    goto LABEL_43;
  LOBYTE(v8) = 1;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *, Scaleform::Render::Point<float> *, __int64))v5->vfptr[63].__vecDelDtor)(
          v5,
          &p,
          v8) )
    goto LABEL_43;
  if ( !v3->TestAll && !Scaleform::GFx::TextField::IsSelectable(v5) )
  {
    if ( Scaleform::GFx::TextField::IsSelectable(v5)
      || !((v5->Flags >> 1) & 1)
      || (v36 = v5->pDocument.pObject, !(v36->pDocument.pObject->RTFlags & 1))
      || !(unsigned __int8)Scaleform::Render::Text::DocView::IsUrlAtPoint(v36, p.x, p.y, 0i64) )
    {
      v37 = v5->pParent;
      if ( v37 )
      {
        while ( (v37->Flags >> 10) & 1 )
        {
          if ( v3->TestAll
            || (v38 = v37->AvmObjOffset) != 0
            && (v39 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v37->vfptr + 4 * v38))[1].__vecDelDtor)((signed __int64)v37 + 4 * v38),
                (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v39 + 96i64))(v39)) )
          {
            v40 = v3->pIgnoreMC;
            if ( !v40 || v37 != v40 )
            {
              v3->pResult = v37;
              return 1i64;
            }
          }
          v37 = v37->pParent;
          if ( !v37 )
            break;
        }
      }
LABEL_43:
      v41 = p.y;
      result = 3i64;
      v3->LocalPt.x = p.x;
      v3->LocalPt.y = v41;
      v3->pResult = 0i64;
      return result;
    }
  }
  v3->pResult = (Scaleform::GFx::InteractiveObject *)&v5->vfptr;
  return 1i64;
}

// File Line: 948
// RVA: 0x8D66B0
__int64 __fastcall Scaleform::GFx::TextField::GetCursorType(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *v2; // rdx
  char v3; // al
  unsigned __int8 v4; // al
  __int64 v5; // rax

  if ( (this->Flags >> 5) & 1 )
    return 1i64;
  v2 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v2 )
    v3 = LOBYTE(v2[10].vfptr) >> 1;
  else
    v3 = LOBYTE(this->pDef.pObject->Flags) >> 5;
  if ( v3 & 1 )
    return 2i64;
  v4 = this->AvmObjOffset;
  if ( !v4 )
    return 0i64;
  v5 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v4))[1].__vecDelDtor)();
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 104i64))(v5);
}

// File Line: 957
// RVA: 0x8E7A80
bool __fastcall Scaleform::GFx::TextField::IsUrlUnderMouseCursor(Scaleform::GFx::TextField *this, unsigned int mouseIndex, Scaleform::Render::Point<float> *pPnt, Scaleform::Range *purlRangePos)
{
  Scaleform::Render::Point<float> *v4; // rdi
  Scaleform::Range *v5; // rsi
  Scaleform::GFx::MovieImpl *v6; // r8
  Scaleform::GFx::TextField *v7; // rbx
  signed __int64 v9; // rax
  float v10; // xmm11_4
  float v11; // xmm12_4
  Scaleform::GFx::InteractiveObject *v12; // rcx
  float *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  unsigned int v17; // xmm9_4
  float v18; // xmm7_4
  float v19; // xmm4_4
  unsigned int v20; // xmm10_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  float v23; // xmm7_4
  float v24; // xmm8_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  float v27; // xmm1_4
  float *v28; // rax
  float v29; // xmm1_4
  float v30; // xmm2_4
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+20h] [rbp-79h]
  Scaleform::Render::Matrix2x4<float> v32; // [rsp+40h] [rbp-59h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+60h] [rbp-39h]

  v4 = pPnt;
  v5 = purlRangePos;
  v6 = this->pASRoot->pMovieImpl;
  v7 = this;
  if ( !v6 )
    return 0;
  if ( mouseIndex < 6 )
    v9 = (signed __int64)&v6->mMouseState[mouseIndex];
  else
    v9 = 0i64;
  v10 = *(float *)(v9 + 56);
  v11 = *(float *)(v9 + 60);
  v12 = this->pParent;
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  if ( v12 )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix((Scaleform::GFx::DisplayObjectBase *)&v12->vfptr, &pmat);
    v13 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v7->vfptr[2].__vecDelDtor)(v7);
    v15 = pmat.M[0][1];
    v14 = pmat.M[0][0];
    v16 = pmat.M[1][0];
    v17 = 0;
    v18 = pmat.M[0][0];
    v19 = pmat.M[1][1];
    v20 = 0;
    v21 = (float)(pmat.M[0][0] * *v13) + (float)(pmat.M[0][1] * v13[4]);
    pmat.M[0][0] = (float)(pmat.M[0][0] * *v13) + (float)(pmat.M[0][1] * v13[4]);
    v22 = (float)(pmat.M[1][1] * v13[4]) + (float)(pmat.M[1][0] * *v13);
    pmat.M[1][0] = (float)(pmat.M[1][1] * v13[4]) + (float)(pmat.M[1][0] * *v13);
    v23 = (float)(v18 * v13[1]) + (float)(pmat.M[0][1] * v13[5]);
    *(_QWORD *)&pmat.M[0][1] = LODWORD(v23);
    v24 = (float)(v16 * v13[1]) + (float)(pmat.M[1][1] * v13[5]);
    *(_QWORD *)&pmat.M[1][1] = LODWORD(v24);
    v25 = (float)(v15 * v13[7]) + (float)(v14 * v13[3]);
    v26 = pmat.M[0][3] + v25;
    pmat.M[0][3] = pmat.M[0][3] + v25;
    v27 = pmat.M[1][3] + (float)((float)(v19 * v13[7]) + (float)(v16 * v13[3]));
  }
  else
  {
    v28 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v7->vfptr[2].__vecDelDtor)(v7);
    v21 = *v28;
    pmat.M[0][0] = *v28;
    v23 = v28[1];
    pmat.M[0][1] = v28[1];
    v20 = *((_DWORD *)v28 + 2);
    pmat.M[0][2] = v28[2];
    v26 = v28[3];
    pmat.M[0][3] = v28[3];
    v22 = v28[4];
    pmat.M[1][0] = v28[4];
    v24 = v28[5];
    pmat.M[1][1] = v28[5];
    v17 = *((_DWORD *)v28 + 6);
    pmat.M[1][2] = v28[6];
    v27 = v28[7];
  }
  pmat.M[1][3] = v27;
  *(_QWORD *)&v32.M[0][0] = __PAIR__(LODWORD(v23), LODWORD(v21));
  *(_QWORD *)&v32.M[0][2] = __PAIR__(LODWORD(v26), v20);
  *(_QWORD *)&v32.M[1][0] = __PAIR__(LODWORD(v24), LODWORD(v22));
  *(_QWORD *)&v32.M[1][2] = __PAIR__(LODWORD(v27), v17);
  *(_QWORD *)&m.M[0][0] = __PAIR__(LODWORD(v23), LODWORD(v21));
  *(_QWORD *)&m.M[0][2] = __PAIR__(LODWORD(v26), v20);
  *(_QWORD *)&m.M[1][0] = __PAIR__(LODWORD(v24), LODWORD(v22));
  *(_QWORD *)&m.M[1][2] = __PAIR__(LODWORD(v27), v17);
  Scaleform::Render::Matrix2x4<float>::SetInverse(&v32, &m);
  v29 = (float)((float)(v32.M[0][1] * v11) + (float)(v32.M[0][0] * v10)) + v32.M[0][3];
  v30 = (float)((float)(v32.M[1][1] * v11) + (float)(v32.M[1][0] * v10)) + v32.M[1][3];
  if ( v4 )
  {
    v4->x = v29;
    v4->y = v30;
  }
  return Scaleform::Render::Text::DocView::IsUrlAtPoint(v7->pDocument.pObject, v29, v30, v5);
}

// File Line: 1065
// RVA: 0x8F3F40
void __fastcall Scaleform::GFx::TextField::PropagateMouseEvent(Scaleform::GFx::TextField *this, Scaleform::GFx::EventId *id)
{
  Scaleform::GFx::EventId *v2; // rdi
  Scaleform::GFx::TextField *v3; // rbx
  Scaleform::GFx::MovieImpl *v4; // r14
  __int64 v5; // rax
  signed __int64 v6; // rsi
  Scaleform::GFx::MouseState *v7; // rcx
  Scaleform::GFx::InteractiveObject *v8; // rax
  unsigned __int8 v9; // cl
  __int64 v10; // rax
  Scaleform::Render::Text::DocView *v11; // rax
  unsigned int v12; // eax
  __int64 v13; // rax
  Scaleform::GFx::DisplayObjectBase *v14; // rcx
  float *v15; // rax
  __int64 v16; // kr00_8
  __int64 v17; // kr08_8
  _OWORD *v18; // rax
  __int64 v19; // rax
  Scaleform::GFx::DisplayObjectBase *v20; // rcx
  float *v21; // rax
  __int64 v22; // kr10_8
  __int64 v23; // kr18_8
  _OWORD *v24; // rax
  float v25; // xmm1_4
  __int64 v26; // rax
  Scaleform::GFx::DisplayObjectBase *v27; // rcx
  float *v28; // rax
  __int64 v29; // kr20_8
  __int64 v30; // kr28_8
  _OWORD *v31; // rax
  float v32; // xmm1_4
  unsigned int v33; // edx
  unsigned int v34; // eax
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+30h] [rbp-30h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> result; // [rsp+90h] [rbp+30h]
  Scaleform::Render::Point<float> p; // [rsp+A0h] [rbp+40h]
  Scaleform::Render::Point<float> v38; // [rsp+A8h] [rbp+48h]

  v2 = id;
  v3 = this;
  v4 = this->pASRoot->pMovieImpl;
  if ( v4 && !((this->pDef.pObject->Flags >> 12) & 1) )
  {
    if ( id->Id == 8 )
      Scaleform::GFx::InteractiveObject::DoMouseDrag(
        (Scaleform::GFx::InteractiveObject *)&this->vfptr,
        id->ControllerIndex);
    v5 = (unsigned int)v2->ControllerIndex;
    v6 = 0i64;
    if ( (unsigned int)v5 < 6 )
      v7 = &v4->mMouseState[v5];
    else
      v7 = 0i64;
    Scaleform::GFx::MouseState::GetTopmostEntity(v7, &result);
    v8 = result.pObject;
    if ( (Scaleform::GFx::TextField *)result.pObject != v3 || v2->Id == 0x4000 )
    {
      v9 = v3->AvmObjOffset;
      if ( v9 )
      {
        v10 = ((__int64 (__cdecl *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * v9))[4].__vecDelDtor)((signed __int64)v3 + 4 * v9);
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 184i64))(v10);
        v8 = result.pObject;
      }
    }
    if ( v8 != (Scaleform::GFx::InteractiveObject *)v3 )
    {
      v11 = v3->pDocument.pObject;
      if ( !v11->pEditorKit.pObject || !((LOBYTE(v11->pEditorKit.pObject[10].vfptr) >> 5) & 1) )
        goto LABEL_53;
    }
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::TextField *))v3->vfptr[59].__vecDelDtor)(v3) )
      goto LABEL_54;
    v12 = v2->Id;
    if ( v2->Id != 8 )
    {
      if ( v12 == 16 )
      {
        if ( v3->pDocument.pObject->pEditorKit.pObject )
        {
          v19 = (unsigned int)v2->ControllerIndex;
          if ( (unsigned int)v19 < 6 )
            v6 = (signed __int64)&v4->mMouseState[v19];
          *(_OWORD *)&pmat.M[0][0] = _xmm;
          *(__m128 *)&pmat.M[1][0] = _xmm;
          v20 = v3->pParentChar;
          if ( v20 )
          {
            Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v20, &pmat);
            v21 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v3->vfptr[2].__vecDelDtor)(v3);
            v22 = *(_QWORD *)&pmat.M[0][0];
            v23 = *(_QWORD *)&pmat.M[1][0];
            pmat.M[0][0] = (float)(pmat.M[0][1] * v21[4]) + (float)(pmat.M[0][0] * *v21);
            pmat.M[1][0] = (float)(pmat.M[1][1] * v21[4]) + (float)(pmat.M[1][0] * *v21);
            pmat.M[0][1] = (float)(*(float *)&v22 * v21[1]) + (float)(pmat.M[0][1] * v21[5]);
            pmat.M[1][1] = (float)(*(float *)&v23 * v21[1]) + (float)(pmat.M[1][1] * v21[5]);
            pmat.M[1][2] = 0.0;
            pmat.M[0][2] = 0.0;
            pmat.M[0][3] = pmat.M[0][3]
                         + (float)((float)(*((float *)&v22 + 1) * v21[7]) + (float)(*(float *)&v22 * v21[3]));
            pmat.M[1][3] = pmat.M[1][3]
                         + (float)((float)(*((float *)&v23 + 1) * v21[7]) + (float)(*(float *)&v23 * v21[3]));
          }
          else
          {
            v24 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v3->vfptr[2].__vecDelDtor)(v3);
            *(_OWORD *)&pmat.M[0][0] = *v24;
            *(_OWORD *)&pmat.M[1][0] = v24[1];
          }
          v25 = *(float *)(v6 + 60);
          p.x = *(float *)(v6 + 56);
          p.y = v25;
          Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &v38, &p);
          Scaleform::GFx::Text::EditorKit::OnMouseDown(
            (Scaleform::GFx::Text::EditorKit *)v3->pDocument.pObject->pEditorKit.pObject,
            v38.x,
            v38.y,
            *(_DWORD *)(v6 + 48));
          goto LABEL_28;
        }
      }
      else if ( (v12 == 32 || v12 == 4096) && v3->pDocument.pObject->pEditorKit.pObject )
      {
        v13 = (unsigned int)v2->ControllerIndex;
        if ( (unsigned int)v13 < 6 )
          v6 = (signed __int64)&v4->mMouseState[v13];
        *(_OWORD *)&pmat.M[0][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        v14 = v3->pParentChar;
        if ( v14 )
        {
          Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v14, &pmat);
          v15 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v3->vfptr[2].__vecDelDtor)(v3);
          v16 = *(_QWORD *)&pmat.M[0][0];
          v17 = *(_QWORD *)&pmat.M[1][0];
          pmat.M[0][0] = (float)(pmat.M[0][1] * v15[4]) + (float)(pmat.M[0][0] * *v15);
          pmat.M[1][0] = (float)(pmat.M[1][1] * v15[4]) + (float)(pmat.M[1][0] * *v15);
          pmat.M[0][1] = (float)(pmat.M[0][1] * v15[5]) + (float)(*(float *)&v16 * v15[1]);
          pmat.M[1][1] = (float)(*(float *)&v17 * v15[1]) + (float)(pmat.M[1][1] * v15[5]);
          pmat.M[1][2] = 0.0;
          pmat.M[0][2] = 0.0;
          pmat.M[0][3] = pmat.M[0][3]
                       + (float)((float)(*((float *)&v16 + 1) * v15[7]) + (float)(*(float *)&v16 * v15[3]));
          pmat.M[1][3] = pmat.M[1][3]
                       + (float)((float)(*((float *)&v17 + 1) * v15[7]) + (float)(*(float *)&v17 * v15[3]));
        }
        else
        {
          v18 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v3->vfptr[2].__vecDelDtor)(v3);
          *(_OWORD *)&pmat.M[0][0] = *v18;
          *(_OWORD *)&pmat.M[1][0] = v18[1];
        }
        if ( !(*(_BYTE *)(v6 + 48) & 1) )
          LOWORD(v3->pDocument.pObject->pEditorKit.pObject[10].vfptr) &= 0xFFDFu;
LABEL_28:
        if ( !Scaleform::GFx::InteractiveObject::IsInPlayList((Scaleform::GFx::InteractiveObject *)&v3->vfptr) )
          Scaleform::GFx::InteractiveObject::AddToPlayList((Scaleform::GFx::InteractiveObject *)&v3->vfptr);
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>((Scaleform::GFx::InteractiveObject *)&v3->vfptr);
        goto LABEL_53;
      }
LABEL_53:
      v3->vfptr[72].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)v2);
LABEL_54:
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
      return;
    }
    v26 = (unsigned int)v2->ControllerIndex;
    if ( (unsigned int)v26 < 6 )
      v6 = (signed __int64)&v4->mMouseState[v26];
    if ( v3->pDocument.pObject->pEditorKit.pObject )
    {
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      v27 = v3->pParentChar;
      if ( v27 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v27, &pmat);
        v28 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v3->vfptr[2].__vecDelDtor)(v3);
        v29 = *(_QWORD *)&pmat.M[0][0];
        v30 = *(_QWORD *)&pmat.M[1][0];
        pmat.M[0][0] = (float)(pmat.M[0][1] * v28[4]) + (float)(pmat.M[0][0] * *v28);
        pmat.M[1][0] = (float)(pmat.M[1][1] * v28[4]) + (float)(pmat.M[1][0] * *v28);
        pmat.M[0][1] = (float)(*(float *)&v29 * v28[1]) + (float)(pmat.M[0][1] * v28[5]);
        pmat.M[1][1] = (float)(*(float *)&v30 * v28[1]) + (float)(pmat.M[1][1] * v28[5]);
        pmat.M[1][2] = 0.0;
        pmat.M[0][2] = 0.0;
        pmat.M[0][3] = pmat.M[0][3] + (float)((float)(*((float *)&v29 + 1) * v28[7]) + (float)(*(float *)&v29 * v28[3]));
        pmat.M[1][3] = pmat.M[1][3] + (float)((float)(*((float *)&v30 + 1) * v28[7]) + (float)(*(float *)&v30 * v28[3]));
      }
      else
      {
        v31 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v3->vfptr[2].__vecDelDtor)(v3);
        *(_OWORD *)&pmat.M[0][0] = *v31;
        *(_OWORD *)&pmat.M[1][0] = v31[1];
      }
      v32 = *(float *)(v6 + 60);
      p.x = *(float *)(v6 + 56);
      p.y = v32;
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &v38, &p);
      Scaleform::GFx::Text::EditorKit::OnMouseMove(
        (Scaleform::GFx::Text::EditorKit *)v3->pDocument.pObject->pEditorKit.pObject,
        v38.x,
        v38.y);
    }
    v33 = v3->Flags;
    if ( (v3->Flags >> 1) & 1 && v3->pDocument.pObject->pDocument.pObject->RTFlags & 1 )
    {
      if ( Scaleform::GFx::TextField::IsUrlUnderMouseCursor(v3, v2->ControllerIndex, 0i64, 0i64) )
        v3->Flags |= 0x20u;
      else
        v3->Flags &= 0xFFFFFFDF;
    }
    else
    {
      if ( !((v33 >> 5) & 1) )
        goto LABEL_53;
      v3->Flags = v33 & 0xFFFFFFDF;
    }
    v34 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v3->vfptr[116].__vecDelDtor)(v3);
    Scaleform::GFx::MovieImpl::ChangeMouseCursorType(v4, v2->ControllerIndex, v34);
    goto LABEL_53;
  }
}

// File Line: 1233
// RVA: 0x8EE7D0
bool __fastcall Scaleform::GFx::TextField::OnMouseEvent(Scaleform::GFx::TextField *this, Scaleform::GFx::EventId *event)
{
  Scaleform::GFx::EventId *v2; // rdi
  Scaleform::GFx::TextField *v3; // rbx
  unsigned __int8 v4; // al
  __int64 v5; // rax

  v2 = event;
  v3 = this;
  if ( (this->pDef.pObject->Flags >> 12) & 1 )
    return 0;
  ((void (*)(void))this->vfptr[99].__vecDelDtor)();
  v4 = v3->AvmObjOffset;
  if ( !v4 )
    return 0;
  v5 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * v4))[4].__vecDelDtor)((signed __int64)v3 + 4 * v4);
  return (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v5 + 208i64))(v5, v2);
}

// File Line: 1243
// RVA: 0x8E7090
bool __fastcall Scaleform::GFx::TextField::IsFocusAllowed(Scaleform::GFx::TextField *this, Scaleform::GFx::MovieImpl *proot, unsigned int controllerIdx)
{
  unsigned int v4; // eax

  if ( (this->pDef.pObject->Flags >> 12) & 1 )
    return 0;
  v4 = this->FocusedControllerIdx;
  return (v4 == -1 || v4 == controllerIdx)
      && Scaleform::GFx::InteractiveObject::IsFocusAllowed(
           (Scaleform::GFx::InteractiveObject *)&this->vfptr,
           proot,
           controllerIdx);
}

// File Line: 1251
// RVA: 0x8E7000
char __fastcall Scaleform::GFx::TextField::IsFocusAllowed(Scaleform::GFx::TextField *this, Scaleform::GFx::MovieImpl *proot, unsigned int controllerIdx)
{
  Scaleform::GFx::TextField *v3; // rbx
  char result; // al
  unsigned int v5; // eax
  unsigned int v6; // edi
  Scaleform::GFx::InteractiveObject *v7; // rcx
  int v8; // eax

  v3 = this;
  if ( (this->pDef.pObject->Flags >> 12) & 1 )
    return 0;
  v5 = this->FocusedControllerIdx;
  if ( v5 != -1 && v5 != controllerIdx )
    goto LABEL_13;
  v6 = (unsigned __int8)proot->FocusGroupIndexes[controllerIdx];
  if ( !this->FocusGroupMask )
  {
    v7 = this->pParent;
    if ( v7 )
      v3->FocusGroupMask = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(v7);
  }
  v8 = v3->FocusGroupMask;
  if ( _bittest(&v8, v6) )
    result = 1;
  else
LABEL_13:
    result = 0;
  return result;
}

// File Line: 1261
// RVA: 0x8ECB70
void __fastcall Scaleform::GFx::TextField::OnFocus(Scaleform::GFx::TextField *this, Scaleform::GFx::InteractiveObject::FocusEventType *event, Scaleform::GFx::InteractiveObject *oldOrNewFocusCh, unsigned int controllerIdx)
{
  unsigned int v4; // er15
  Scaleform::GFx::InteractiveObject *v5; // r12
  unsigned int v6; // esi
  Scaleform::GFx::TextField *v7; // rdi
  Scaleform::GFx::TextFieldDef *v8; // rcx
  Scaleform::Render::Text::DocView *v9; // rdx
  char v10; // cl
  __int64 v11; // rax
  Scaleform::Render::Text::DocView *v12; // rbx
  Scaleform::Render::Text::EditorKitBase *v13; // rbx
  Scaleform::Render::TreeText *v14; // rax
  Scaleform::Render::Text::DocView *v15; // rcx
  unsigned __int8 v16; // al
  Scaleform::GFx::VirtualKeyboardInterface *v17; // rbx
  Scaleform::GFx::DisplayObjectBase *v18; // rcx
  float *v19; // rax
  __int64 v20; // kr00_8
  __int64 v21; // kr08_8
  _OWORD *v22; // rax
  float *v23; // rax
  float v24; // xmm4_4
  float v25; // xmm3_4
  float v26; // xmm1_4
  Scaleform::Render::Text::DocView *v27; // rbx
  Scaleform::Render::TreeText *v28; // rax
  Scaleform::GFx::VirtualKeyboardInterface *v29; // rbx
  Scaleform::Render::Text::EditorKitBase *v30; // rcx
  char v31; // al
  Scaleform::Render::Text::EditorKitBase *v32; // rcx
  char v33; // al
  bool v34; // r8
  bool v35; // dl
  unsigned __int8 v36; // al
  __int64 *v37; // rax
  __int64 v38; // r10
  Scaleform::Render::Text::EditorKitBase *v39; // rcx
  Scaleform::GFx::MovieImpl *v40; // rcx
  unsigned __int16 v41; // dx
  Scaleform::GFx::InteractiveObject *v42; // rax
  float v43; // [rsp+18h] [rbp-21h]
  float v44; // [rsp+1Ch] [rbp-1Dh]
  float v45; // [rsp+20h] [rbp-19h]
  float v46; // [rsp+24h] [rbp-15h]
  char v47; // [rsp+28h] [rbp-11h]
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+38h] [rbp-1h]
  Scaleform::Ptr<Scaleform::GFx::VirtualKeyboardInterface> result; // [rsp+98h] [rbp+5Fh]
  void *retaddr; // [rsp+B8h] [rbp+7Fh]

  v4 = controllerIdx;
  v5 = oldOrNewFocusCh;
  v6 = (unsigned int)event;
  v7 = this;
  v8 = this->pDef.pObject;
  if ( !((v8->Flags >> 12) & 1) )
  {
    if ( (_DWORD)event == 1 )
    {
      v9 = v7->pDocument.pObject;
      if ( v9->pEditorKit.pObject )
        v10 = LOBYTE(v9->pEditorKit.pObject[10].vfptr) >> 1;
      else
        v10 = LOBYTE(v8->Flags) >> 5;
      if ( v10 & 1 && !((v7->Flags >> 10) & 1) && (_DWORD)retaddr == 2 )
      {
        v11 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&v9->pDocument.pObject->vfptr);
        Scaleform::GFx::TextField::SetSelection(v7, 0i64, v11);
      }
      v7->FocusedControllerIdx = v4;
      v12 = v7->pDocument.pObject;
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
        v14 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v7->vfptr);
        Scaleform::Render::TreeText::NotifyLayoutChanged(v14);
        v15 = v7->pDocument.pObject;
        v16 = v15->pEditorKit.pObject ? ((unsigned __int8 (*)(void))v15->pEditorKit.pObject->vfptr[2].__vecDelDtor)() : (LOBYTE(v7->pDef.pObject->Flags) >> 3) & 1;
        if ( !v16 )
        {
          v17 = Scaleform::GFx::StateBag::GetVirtualKeyboardInterface(
                  (Scaleform::GFx::StateBag *)&v7->pASRoot->pMovieImpl->vfptr,
                  &result)->pObject;
          if ( result.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
          if ( v17 )
          {
            *(_OWORD *)&pmat.M[0][0] = _xmm;
            *(__m128 *)&pmat.M[1][0] = _xmm;
            v18 = v7->pParentChar;
            if ( v18 )
            {
              Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v18, &pmat);
              v19 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v7->vfptr[2].__vecDelDtor)(v7);
              v20 = *(_QWORD *)&pmat.M[0][0];
              v21 = *(_QWORD *)&pmat.M[1][0];
              pmat.M[0][0] = (float)(pmat.M[0][0] * *v19) + (float)(pmat.M[0][1] * v19[4]);
              pmat.M[1][0] = (float)(pmat.M[1][0] * *v19) + (float)(pmat.M[1][1] * v19[4]);
              pmat.M[0][1] = (float)(*(float *)&v20 * v19[1]) + (float)(pmat.M[0][1] * v19[5]);
              pmat.M[1][1] = (float)(*(float *)&v21 * v19[1]) + (float)(pmat.M[1][1] * v19[5]);
              pmat.M[1][2] = 0.0;
              pmat.M[0][2] = 0.0;
              pmat.M[0][3] = pmat.M[0][3]
                           + (float)((float)(*((float *)&v20 + 1) * v19[7]) + (float)(*(float *)&v20 * v19[3]));
              pmat.M[1][3] = pmat.M[1][3]
                           + (float)((float)(*((float *)&v21 + 1) * v19[7]) + (float)(*(float *)&v21 * v19[3]));
            }
            else
            {
              v22 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v7->vfptr[2].__vecDelDtor)(v7);
              *(_OWORD *)&pmat.M[0][0] = *v22;
              *(_OWORD *)&pmat.M[1][0] = v22[1];
            }
            v23 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *, char *, Scaleform::Render::Matrix2x4<float> *))v7->vfptr[61].__vecDelDtor)(
                             v7,
                             &v47,
                             &pmat);
            v24 = v23[3] * 0.050000001;
            v25 = v23[2] * 0.050000001;
            v26 = v23[1] * 0.050000001;
            v43 = *v23 * 0.050000001;
            v44 = v26;
            v45 = v25;
            v46 = v24;
            ((void (__fastcall *)(Scaleform::GFx::VirtualKeyboardInterface *, _QWORD, float *))v17->vfptr[1].__vecDelDtor)(
              v17,
              ((unsigned __int8)v7->pDocument.pObject->Flags >> 2) & 1,
              &v43);
          }
        }
      }
    }
    else if ( !(_DWORD)event )
    {
      v7->FocusedControllerIdx = -1;
      v27 = v7->pDocument.pObject;
      if ( v27->pEditorKit.pObject )
      {
        if ( Scaleform::GFx::TextField::IsSelectable(v7) && !((v7->Flags >> 9) & 1) )
          Scaleform::Render::Text::DocView::SetSelection(
            (Scaleform::Render::Text::DocView *)v27->pEditorKit.pObject[1].vfptr,
            0i64,
            0i64,
            1);
        Scaleform::GFx::Text::EditorKit::OnKillFocus((Scaleform::GFx::Text::EditorKit *)v7->pDocument.pObject->pEditorKit.pObject);
        v28 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v7->vfptr);
        Scaleform::Render::TreeText::NotifyLayoutChanged(v28);
        if ( !Scaleform::GFx::TextField::IsReadOnly(v7) )
        {
          v29 = Scaleform::GFx::StateBag::GetVirtualKeyboardInterface(
                  (Scaleform::GFx::StateBag *)&v7->pASRoot->pMovieImpl->vfptr,
                  &result)->pObject;
          if ( result.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
          if ( v29 )
            ((void (__fastcall *)(Scaleform::GFx::VirtualKeyboardInterface *))v29->vfptr[2].__vecDelDtor)(v29);
        }
      }
    }
    v30 = v7->pDocument.pObject->pEditorKit.pObject;
    if ( v30 )
      v31 = ((__int64 (*)(void))v30->vfptr[2].__vecDelDtor)();
    else
      v31 = (LOBYTE(v7->pDef.pObject->Flags) >> 3) & 1;
    if ( !v31
      || ((v32 = v7->pDocument.pObject->pEditorKit.pObject) == 0i64 ? (v33 = LOBYTE(v7->pDef.pObject->Flags) >> 5) : (v33 = LOBYTE(v32[10].vfptr) >> 1),
          v33 & 1) )
    {
      if ( v6 == 1 )
      {
        v34 = 1;
        v35 = 1;
      }
      else
      {
        v34 = 0;
        v35 = 0;
      }
      Scaleform::GFx::TextField::ResetBlink(v7, v35, v34);
      v36 = v7->AvmObjOffset;
      if ( v36 )
      {
        v37 = (__int64 *)((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v7->vfptr + 4 * v36))[1].__vecDelDtor)();
        v38 = *v37;
        v45 = *(float *)&retaddr;
        (*(void (__fastcall **)(__int64 *, _QWORD, Scaleform::GFx::InteractiveObject *, _QWORD))(v38 + 128))(
          v37,
          v6,
          v5,
          v4);
      }
      v39 = v7->pDocument.pObject->pEditorKit.pObject;
      if ( v39 && !((unsigned __int8 (*)(void))v39->vfptr[2].__vecDelDtor)() )
      {
        v7->Flags |= 0x4000u;
        if ( !v7->pPlayNext && !v7->pPlayPrev )
        {
          v40 = v7->pASRoot->pMovieImpl;
          if ( (Scaleform::GFx::TextField *)v40->pPlayListHead != v7 )
          {
            v41 = v7->Flags;
            if ( !(((unsigned __int8)v41 >> 4) & 1) && !(v41 & 0x1000) && v7->Depth >= -1 )
            {
              v42 = v40->pPlayListHead;
              if ( v42 )
              {
                v42->pPlayPrev = (Scaleform::GFx::InteractiveObject *)&v7->vfptr;
                v7->pPlayNext = v40->pPlayListHead;
              }
              v40->pPlayListHead = (Scaleform::GFx::InteractiveObject *)&v7->vfptr;
            }
          }
        }
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>((Scaleform::GFx::InteractiveObject *)&v7->vfptr);
      }
    }
    else if ( !v6
           || (unsigned __int8)v7->vfptr[89].__vecDelDtor(
                                 (Scaleform::RefCountNTSImplCore *)&v7->vfptr,
                                 (unsigned int)retaddr) )
    {
      Scaleform::GFx::InteractiveObject::OnFocus(
        (Scaleform::GFx::InteractiveObject *)&v7->vfptr,
        (Scaleform::GFx::InteractiveObject::FocusEventType *)v6,
        v5,
        v4,
        (Scaleform::GFx::FocusMovedType)retaddr);
    }
  }
}

// File Line: 1352
// RVA: 0x8D5400
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::TextField::GetBounds(Scaleform::GFx::TextField *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *t)
{
  Scaleform::Render::Matrix2x4<float> *v3; // rbx
  Scaleform::Render::Rect<float> *v4; // rdi
  Scaleform::Render::Rect<float> *v5; // rax

  v3 = t;
  v4 = result;
  v5 = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(v3, v4, v5);
  return v4;
}

// File Line: 1357
// RVA: 0x8F0860
bool __fastcall Scaleform::GFx::TextField::PointTestLocal(Scaleform::GFx::TextField *this, Scaleform::Render::Point<float> *pt, char hitTestMask)
{
  Scaleform::Render::Point<float> *v3; // rdi
  Scaleform::GFx::TextField *v4; // rbx
  bool result; // al
  Scaleform::Render::Rect<float> *v6; // rax
  float v7; // xmm0_4

  v3 = pt;
  v4 = this;
  if ( (this->Flags >> 11) & 1 || hitTestMask & 2 && !((unsigned __int8 (*)(void))this->vfptr[59].__vecDelDtor)() )
    return 0;
  v6 = Scaleform::Render::Text::DocView::GetViewRect(v4->pDocument.pObject);
  result = 0;
  if ( v3->x <= v6->x2 && v3->x >= v6->x1 )
  {
    v7 = v3->y;
    if ( v7 <= v6->y2 && v7 >= v6->y1 )
      result = 1;
  }
  return result;
}

// File Line: 1367
// RVA: 0x9011C0
void __fastcall Scaleform::GFx::TextField::ResetBlink(Scaleform::GFx::TextField *this, bool state, bool blocked)
{
  Scaleform::GFx::TextField *v3; // rbx
  bool v4; // di
  Scaleform::Render::Text::EditorKitBase *v5; // rcx
  bool v6; // si
  Scaleform::Render::TreeText *v7; // rax

  v3 = this;
  v4 = blocked;
  v5 = this->pDocument.pObject->pEditorKit.pObject;
  v6 = state;
  if ( v5 )
  {
    if ( !((unsigned __int8 (*)(void))v5->vfptr[2].__vecDelDtor)() )
    {
      Scaleform::GFx::Text::EditorKit::ResetBlink(
        (Scaleform::GFx::Text::EditorKit *)v3->pDocument.pObject->pEditorKit.pObject,
        v6,
        v4);
      v7 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
      Scaleform::Render::TreeText::NotifyLayoutChanged(v7);
    }
  }
}

// File Line: 1379
// RVA: 0x90BCE0
void __fastcall Scaleform::GFx::TextField::SetSelection(Scaleform::GFx::TextField *this, __int64 beginIndex, __int64 endIndex)
{
  __int64 v3; // rsi
  __int64 v4; // rdi
  Scaleform::GFx::TextField *v5; // rbx
  Scaleform::Render::Text::DocView *v6; // rcx
  Scaleform::Render::Text::StyledText *v7; // rcx
  signed __int64 v8; // rax
  Scaleform::Render::TreeText *v9; // rax
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> result; // [rsp+30h] [rbp+8h]

  v3 = endIndex;
  v4 = beginIndex;
  v5 = this;
  if ( !this->pDocument.pObject->pEditorKit.pObject )
  {
    Scaleform::GFx::TextField::CreateEditorKit(this, &result);
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  }
  v6 = v5->pDocument.pObject;
  if ( v6->pEditorKit.pObject )
  {
    v7 = (Scaleform::Render::Text::StyledText *)&v6->pDocument.pObject->vfptr;
    if ( v4 < 0 )
      v4 = 0i64;
    if ( v3 < 0 )
      v3 = 0i64;
    v8 = Scaleform::Render::Text::StyledText::GetLength(v7);
    if ( v8 < v3 )
      v3 = v8;
    if ( v8 < v4 )
      v4 = v8;
    Scaleform::GFx::Text::EditorKit::SetSelection(
      (Scaleform::GFx::Text::EditorKit *)v5->pDocument.pObject->pEditorKit.pObject,
      v4,
      v3);
    v9 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
    Scaleform::Render::TreeText::NotifyLayoutChanged(v9);
  }
}

// File Line: 1402
// RVA: 0x8D5A10
__int64 __fastcall Scaleform::GFx::TextField::GetCaretIndex(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // rbx
  Scaleform::Render::Text::EditorKitBase *v2; // rcx
  char v3; // al
  Scaleform::Render::Text::EditorKitBase *v4; // rcx
  char v5; // al
  Scaleform::Render::Text::EditorKitBase *v6; // rax
  __int64 result; // rax

  v1 = this;
  v2 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v2 )
    v3 = ((__int64 (*)(void))v2->vfptr[2].__vecDelDtor)();
  else
    v3 = (LOBYTE(v1->pDef.pObject->Flags) >> 3) & 1;
  if ( (!v3
     || ((v4 = v1->pDocument.pObject->pEditorKit.pObject) == 0i64 ? (v5 = LOBYTE(v1->pDef.pObject->Flags) >> 5) : (v5 = LOBYTE(v4[10].vfptr) >> 1),
         v5 & 1))
    && (v6 = v1->pDocument.pObject->pEditorKit.pObject) != 0i64 )
  {
    result = *(_QWORD *)&v6[3].RefCount;
  }
  else
  {
    result = -1i64;
  }
  return result;
}

// File Line: 1416
// RVA: 0x8D4D90
void *(__fastcall *__fastcall Scaleform::GFx::TextField::GetBeginIndex(Scaleform::GFx::TextField *this))(Scaleform::RefCountImplCore *this, unsigned int)
{
  Scaleform::Render::Text::EditorKitBase *v1; // rcx
  Scaleform::RefCountImplCoreVtbl *v2; // rcx
  void *(__fastcall *result)(Scaleform::RefCountImplCore *, unsigned int); // rax

  v1 = this->pDocument.pObject->pEditorKit.pObject;
  if ( !v1 )
    return 0i64;
  v2 = v1[1].vfptr;
  result = v2[8].__vecDelDtor;
  if ( (char *)v2[7].__vecDelDtor < (char *)result )
    result = v2[7].__vecDelDtor;
  return result;
}

// File Line: 1428
// RVA: 0x8D73F0
void *(__fastcall *__fastcall Scaleform::GFx::TextField::GetEndIndex(Scaleform::GFx::TextField *this))(Scaleform::RefCountImplCore *this, unsigned int)
{
  Scaleform::Render::Text::EditorKitBase *v1; // rcx
  Scaleform::RefCountImplCoreVtbl *v2; // rcx
  void *(__fastcall *result)(Scaleform::RefCountImplCore *, unsigned int); // rax

  v1 = this->pDocument.pObject->pEditorKit.pObject;
  if ( !v1 )
    return 0i64;
  v2 = v1[1].vfptr;
  result = v2[8].__vecDelDtor;
  if ( (char *)result < (char *)v2[7].__vecDelDtor )
    result = v2[7].__vecDelDtor;
  return result;
}

// File Line: 1440
// RVA: 0x8EC760
void __fastcall Scaleform::GFx::TextField::OnEventLoad(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // rbx
  const char *v2; // rdx
  unsigned __int8 v3; // al
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [rsp+20h] [rbp-68h]

  v1 = this;
  if ( Scaleform::String::GetLength((Scaleform::String *)&this->pDef.pObject->DefaultText.0) )
    v2 = (const char *)((v1->pDef.pObject->DefaultText.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12);
  else
    v2 = &customWorldMapCaption;
  Scaleform::GFx::TextField::SetTextValue(v1, v2, (v1->Flags >> 1) & 1, 0);
  Scaleform::Render::Text::DocView::Format(v1->pDocument.pObject);
  v1->Flags |= 0x2000u;
  v3 = v1->AvmObjOffset;
  if ( v3 )
    ((void (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr + 4 * v3))[9].__vecDelDtor)((signed __int64)v1 + 4 * v3);
  if ( !v1->pGeomData )
  {
    *(_QWORD *)&pgeomData.X = 0i64;
    *(_OWORD *)&pgeomData.OrigMatrix.M[0][0] = _xmm;
    *(__m128 *)&pgeomData.OrigMatrix.M[1][0] = _xmm;
    pgeomData.YScale = DOUBLE_100_0;
    pgeomData.XScale = DOUBLE_100_0;
    pgeomData.Rotation = 0.0;
    *(_OWORD *)&pgeomData.XRotation = 0i64;
    *(_OWORD *)&pgeomData.Z = _xmm;
    Scaleform::GFx::TextField::UpdateAndGetGeomData(v1, &pgeomData, 1);
  }
}

// File Line: 1476
// RVA: 0x8ECA90
void __fastcall Scaleform::GFx::TextField::OnEventUnload(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // rbx
  Scaleform::Render::TreeText *v2; // rax

  v1 = this;
  this->Flags |= 0x1000u;
  v2 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v2);
  Scaleform::GFx::InteractiveObject::OnEventUnload((Scaleform::GFx::InteractiveObject *)&v1->vfptr);
}

// File Line: 1496
// RVA: 0x916B50
Scaleform::GFx::DisplayObjectBase::GeomDataType *__fastcall Scaleform::GFx::TextField::UpdateAndGetGeomData(Scaleform::GFx::TextField *this, Scaleform::GFx::DisplayObjectBase::GeomDataType *pgeomData, bool force)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v3; // rdi
  Scaleform::GFx::TextField *v4; // rsi
  bool v5; // bl
  Scaleform::Render::Rect<float> *v6; // rax
  float v7; // xmm6_4
  float v8; // xmm7_4
  float *v9; // rax
  double v10; // xmm4_8
  double v11; // xmm3_8
  double v12; // xmm4_8
  double v13; // xmm3_8

  v3 = pgeomData;
  v4 = this;
  v5 = force;
  Scaleform::GFx::DisplayObjectBase::GetGeomData((Scaleform::GFx::DisplayObjectBase *)&this->vfptr, pgeomData);
  if ( v5 || v4->Flags & 0x2000 )
  {
    v6 = Scaleform::Render::Text::DocView::GetViewRect(v4->pDocument.pObject);
    v7 = v6->x1;
    v8 = v6->y1;
    v9 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v4->vfptr[2].__vecDelDtor)(v4);
    v10 = *v9 * v7 + v9[1] * v8 + v9[3];
    v11 = v9[4] * v7 + v9[5] * v8 + v9[7];
    if ( v10 <= 0.0 )
      v12 = v10 - 0.5;
    else
      v12 = v10 + 0.5;
    v3->X = (signed int)v12;
    if ( v11 <= 0.0 )
      v13 = v11 - 0.5;
    else
      v13 = v11 + 0.5;
    v3->Y = (signed int)v13;
    Scaleform::GFx::DisplayObjectBase::SetGeomData((Scaleform::GFx::DisplayObjectBase *)&v4->vfptr, v3);
    v4->Flags &= 0xFFFFDFFF;
  }
  return v3;
}

// File Line: 1520
// RVA: 0x8EDDE0
char __fastcall Scaleform::GFx::TextField::OnKeyEvent(Scaleform::GFx::TextField *this, Scaleform::GFx::EventId *id, int *pkeyMask)
{
  int *v3; // r14
  Scaleform::GFx::EventId *v4; // rsi
  Scaleform::GFx::TextField *v5; // rdi
  Scaleform::GFx::MovieImpl *v7; // rdx
  __int64 v8; // rcx
  signed int v9; // er15
  unsigned __int8 v10; // al
  __int64 v11; // rax
  int v12; // edx
  Scaleform::GFx::Text::EditorKit *v13; // rcx
  Scaleform::Render::Text::EditorKitBase *v14; // rcx
  unsigned __int8 v15; // bl
  Scaleform::Render::Text::EditorKitBase *v16; // rbp
  Scaleform::RefCountImplCoreVtbl *v17; // rdi
  Scaleform::GFx::TextKeyMap::KeyMapEntry *v18; // r8
  void *(__fastcall *v19)(Scaleform::RefCountImplCore *, unsigned int); // rdx
  signed __int64 v20; // rcx
  signed __int64 v21; // rcx
  __int16 v22; // cx
  Scaleform::KeyModifiers specKeysState; // [rsp+40h] [rbp+8h]

  v3 = pkeyMask;
  v4 = id;
  v5 = this;
  if ( (this->pDef.pObject->Flags >> 12) & 1 )
    return 0;
  v7 = this->pASRoot->pMovieImpl;
  v8 = (unsigned __int8)v7->FocusGroupIndexes[v4->ControllerIndex];
  v9 = 1 << v8;
  if ( *(_WORD *)pkeyMask & (unsigned __int16)(1 << v8)
    || !v7
    || !(unsigned __int8)Scaleform::GFx::FocusGroupDescr::IsFocused(
                           &v7->FocusGroups[v8],
                           (Scaleform::GFx::InteractiveObject *)&v5->vfptr) )
  {
    return 0;
  }
  v10 = v5->AvmObjOffset;
  if ( v10 )
  {
    v11 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->vfptr + 4 * v10))[4].__vecDelDtor)((signed __int64)v5 + 4 * v10);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::EventId *, int *))(*(_QWORD *)v11 + 144i64))(v11, v4, v3);
  }
  if ( !v5->pDocument.pObject->pEditorKit.pObject
    || Scaleform::GFx::TextField::IsReadOnly(v5) && !Scaleform::GFx::TextField::IsSelectable(v5) )
  {
    goto LABEL_30;
  }
  if ( v4->Id != 64 )
  {
    if ( v4->Id == 128 )
    {
      v15 = v4->KeysState.States | 0x80;
      v16 = v5->pDocument.pObject->pEditorKit.pObject;
      v17 = v16[2].vfptr;
      if ( v17 )
      {
        v18 = Scaleform::GFx::TextKeyMap::FindFirstEntry((Scaleform::GFx::TextKeyMap *)v16[2].vfptr, v4->KeyCode);
        if ( v18 )
        {
          while ( v18->mState != 1 || (v18->SpecKeysPressed & v15) != v18->SpecKeysPressed )
          {
            v19 = v17[3].__vecDelDtor;
            v20 = ((char *)v18 - (char *)v19) >> 4;
            if ( (char *)(v20 + 1) < (char *)v17[4].__vecDelDtor )
            {
              v21 = 16 * v20;
              if ( *(_DWORD *)((char *)v19 + v21 + 20) == v18->KeyCode )
              {
                v18 = (Scaleform::GFx::TextKeyMap::KeyMapEntry *)((char *)v19 + v21 + 16);
                if ( v18 )
                  continue;
              }
            }
            goto LABEL_30;
          }
          if ( v18->Action == 3 )
          {
            v22 = (__int16)v16[10].vfptr;
            if ( ((unsigned __int8)v22 >> 1) & 1 )
            {
              if ( ((unsigned __int8)v22 >> 6) & 1 )
                LOWORD(v16[10].vfptr) = v22 & 0xFFBF;
            }
          }
        }
      }
    }
    goto LABEL_30;
  }
  v12 = v4->KeyCode;
  v13 = (Scaleform::GFx::Text::EditorKit *)v5->pDocument.pObject->pEditorKit.pObject;
  specKeysState.States = v4->KeysState.States | 0x80;
  Scaleform::GFx::Text::EditorKit::OnKeyDown(v13, v12, &specKeysState);
  if ( v4->KeyCode != 45 )
  {
LABEL_30:
    *v3 |= (unsigned __int16)v9;
    return 1;
  }
  v14 = v5->pDocument.pObject->pEditorKit.pObject;
  if ( v14 )
    Scaleform::GFx::TextField::SetOverwriteMode(v5, LOBYTE(v14[10].vfptr) >> 7 == 0);
  else
    Scaleform::GFx::TextField::SetOverwriteMode(v5, 1);
  *v3 |= (unsigned __int16)v9;
  return 1;
}

// File Line: 1574
// RVA: 0x8EC520
char __fastcall Scaleform::GFx::TextField::OnCharEvent(Scaleform::GFx::TextField *this, unsigned int wcharCode, unsigned int controllerIdx)
{
  unsigned int v3; // edi
  unsigned int v4; // esi
  Scaleform::GFx::TextField *v5; // rbx
  Scaleform::Render::Text::EditorKitBase *v7; // rcx
  __int64 v8; // rax

  v3 = controllerIdx;
  v4 = wcharCode;
  v5 = this;
  if ( (this->pDef.pObject->Flags >> 12) & 1 )
    return 0;
  if ( this->pASRoot->pMovieImpl )
  {
    v7 = this->pDocument.pObject->pEditorKit.pObject;
    if ( v7 )
    {
      if ( (!((unsigned __int8 (*)(void))v7->vfptr[2].__vecDelDtor)() || Scaleform::GFx::TextField::IsSelectable(v5))
        && v5->FocusedControllerIdx == v3 )
      {
        v8 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->vfptr
                                                                                              + 4
                                                                                              * (unsigned __int8)v5->AvmObjOffset))[4].__vecDelDtor)((signed __int64)v5 + 4 * (unsigned __int8)v5->AvmObjOffset);
        if ( (*(unsigned __int8 (__fastcall **)(__int64, _QWORD, _QWORD))(*(_QWORD *)v8 + 216i64))(
               v8,
               (unsigned __int16)v4,
               v3) )
        {
          Scaleform::GFx::Text::EditorKit::OnChar(
            (Scaleform::GFx::Text::EditorKit *)v5->pDocument.pObject->pEditorKit.pObject,
            v4);
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
  Scaleform::Render::Text::EditorKitBase *v2; // rcx

  v2 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v2 )
  {
    if ( overwMode )
      LOWORD(v2[10].vfptr) |= 0x80u;
    else
      LOWORD(v2[10].vfptr) &= 0xFF7Fu;
  }
}

// File Line: 1626
// RVA: 0x8EE950
char __fastcall Scaleform::GFx::TextField::OnMouseWheelEvent(Scaleform::GFx::TextField *this, int mwDelta)
{
  Scaleform::GFx::TextField *v2; // rbx
  signed int v3; // edi
  Scaleform::Render::TreeText *v4; // rax

  v2 = this;
  if ( !((this->Flags >> 7) & 1) )
    return 0;
  v3 = Scaleform::Render::Text::DocView::GetVScrollOffset(this->pDocument.pObject) - mwDelta;
  if ( v3 < 0 )
    v3 = 0;
  if ( v3 > (signed int)Scaleform::Render::Text::DocView::GetMaxVScroll(v2->pDocument.pObject) )
    v3 = Scaleform::Render::Text::DocView::GetMaxVScroll(v2->pDocument.pObject);
  Scaleform::Render::Text::DocView::SetVScrollOffset(v2->pDocument.pObject, v3);
  v4 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v4);
  return 1;
}

// File Line: 1647
// RVA: 0x8B1400
void __fastcall Scaleform::GFx::TextField::AddIdImageDescAssoc(Scaleform::GFx::TextField *this, const char *idStr, Scaleform::Render::Text::ImageDesc *pdesc)
{
  Scaleform::Render::Text::ImageDesc *v3; // rdi
  const char *v4; // rsi
  Scaleform::GFx::TextField *v5; // rbx
  Scaleform::RefCountNTSImpl *v6; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v7; // rcx
  Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+28h] [rbp-30h]
  Scaleform::String v9; // [rsp+60h] [rbp+8h]
  int v10; // [rsp+70h] [rbp+18h]
  Scaleform::RefCountNTSImpl *v11; // [rsp+78h] [rbp+20h]

  v9.pData = (Scaleform::String::DataDesc *)this;
  v3 = pdesc;
  v4 = idStr;
  v5 = this;
  if ( !this->pImageDescAssoc )
  {
    v10 = 2;
    v6 = (Scaleform::RefCountNTSImpl *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::TextField *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
    v5->pImageDescAssoc = (Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)v6;
  }
  if ( v3 )
    ++v3->RefCount;
  v11 = (Scaleform::RefCountNTSImpl *)&v3->vfptr;
  Scaleform::String::String(&v9, v4);
  v7 = (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v5->pImageDescAssoc->mHash.pTable;
  key.pFirst = &v9;
  key.pSecond = (Scaleform::Ptr<Scaleform::Render::Text::ImageDesc> *)&v11;
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
    v7,
    v7,
    &key);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v11 )
    Scaleform::RefCountNTSImpl::Release(v11);
}

// File Line: 1653
// RVA: 0x8FF840
void __fastcall Scaleform::GFx::TextField::RemoveIdImageDescAssoc(Scaleform::GFx::TextField *this, const char *idStr)
{
  Scaleform::GFx::TextField *v2; // rbx
  Scaleform::String key; // [rsp+40h] [rbp+8h]

  v2 = this;
  if ( this->pImageDescAssoc )
  {
    Scaleform::String::String(&key, idStr);
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::RemoveAlt<Scaleform::String>(
      (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v2->pImageDescAssoc->mHash.pTable,
      &key);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((key.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 1660
// RVA: 0x8BC370
void __fastcall Scaleform::GFx::TextField::ClearIdImageDescAssoc(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // rdi
  Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v2; // rbx

  v1 = this;
  v2 = this->pImageDescAssoc;
  if ( v2 )
  {
    Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v2->mHash.pTable);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
    v1->pImageDescAssoc = 0i64;
  }
  else
  {
    this->pImageDescAssoc = 0i64;
  }
}

// File Line: 1673
// RVA: 0x8F28D0
void __fastcall Scaleform::GFx::TextField::ProcessImageTags(Scaleform::GFx::TextField *this, Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *imageInfoArray)
{
  Scaleform::GFx::TextField *v2; // r15
  unsigned __int64 v3; // rbx
  Scaleform::Render::TreeText *v4; // rax
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v5; // rax
  Scaleform::Render::ImageBase *v6; // rbx
  __int64 v7; // rsi
  Scaleform::Render::Text::StyledText::HTMLImageTagInfo *v8; // r13
  __int64 v9; // rax
  Scaleform::GFx::MovieDefImpl *v10; // r14
  _QWORD *v11; // r12
  char v12; // di
  unsigned __int64 v13; // rbx
  Scaleform::Log *v14; // rax
  Scaleform::GFx::ResourceLibBase *v15; // rcx
  Scaleform::GFx::Resource *v16; // rbx
  Scaleform::GFx::ResourceLibBase *v17; // rcx
  Scaleform::GFx::MovieImpl *v18; // rsi
  const char *v19; // rdi
  Scaleform::GFx::MovieDefImpl *v20; // rax
  unsigned __int64 v21; // rbx
  Scaleform::Log *v22; // rax
  Scaleform::GFx::ImageResource *v23; // rbx
  Scaleform::GFx::ResourceLibBase *v24; // rcx
  Scaleform::GFx::ResourceLibBase *v25; // rcx
  Scaleform::GFx::Resource *v26; // rbx
  Scaleform::GFx::ResourceLibBase *v27; // rcx
  bool v28; // si
  Scaleform::MemoryHeap *v29; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *v30; // rax
  Scaleform::GFx::ImageResource *v31; // rdi
  Scaleform::GFx::ResourceLibBase *v32; // rcx
  __int64 v33; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> *v34; // rdi
  __int64 *v35; // rbx
  Scaleform::Ptr<Scaleform::Log> *v36; // rax
  __int64 v37; // rdx
  __int64 v38; // rax
  Scaleform::GFx::ImageCreator *v39; // rbx
  __int64 v40; // rdi
  __int64 v41; // rcx
  float v42; // xmm5_4
  float v43; // xmm4_4
  int v44; // eax
  float v45; // xmm3_4
  int v46; // eax
  float v47; // xmm2_4
  float v48; // xmm0_4
  float *v49; // rax
  float v50; // xmm2_4
  float v51; // xmm3_4
  unsigned __int64 v52; // r8
  Scaleform::GFx::ResourceLibBase *v53; // rcx
  Scaleform::GFx::ResourceLibBase *v54; // rcx
  Scaleform::GFx::Resource *v55; // rbx
  Scaleform::GFx::ResourceLibBase *v56; // rcx
  bool v57; // zf
  __int64 v58; // [rsp+20h] [rbp-E0h]
  Scaleform::Render::ImageBase *v59; // [rsp+28h] [rbp-D8h]
  Scaleform::Ptr<Scaleform::GFx::ImageResource> result; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::ResourceBindData presBindData; // [rsp+38h] [rbp-C8h]
  Scaleform::LogMessageId v62; // [rsp+48h] [rbp-B8h]
  unsigned __int64 v63; // [rsp+50h] [rbp-B0h]
  int v64; // [rsp+58h] [rbp-A8h]
  int v65; // [rsp+5Ch] [rbp-A4h]
  int v66; // [rsp+60h] [rbp-A0h]
  int v67; // [rsp+64h] [rbp-9Ch]
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> v68; // [rsp+68h] [rbp-98h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v69; // [rsp+70h] [rbp-90h]
  Scaleform::Ptr<Scaleform::GFx::ImageFileHandlerRegistry> v70; // [rsp+78h] [rbp-88h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v71; // [rsp+80h] [rbp-80h]
  Scaleform::Ptr<Scaleform::Log> v72; // [rsp+88h] [rbp-78h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v73; // [rsp+90h] [rbp-70h]
  int v74; // [rsp+98h] [rbp-68h]
  __int64 v75; // [rsp+A0h] [rbp-60h]
  int v76; // [rsp+A8h] [rbp-58h]
  int v77; // [rsp+ACh] [rbp-54h]
  __int64 v78; // [rsp+B0h] [rbp-50h]
  __int64 v79; // [rsp+B8h] [rbp-48h]
  __int64 v80; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::MovieImpl *v81; // [rsp+C8h] [rbp-38h]
  int v82; // [rsp+D0h] [rbp-30h]
  Scaleform::MemoryHeap *v83; // [rsp+D8h] [rbp-28h]
  int v84; // [rsp+E0h] [rbp-20h]
  int v85; // [rsp+E4h] [rbp-1Ch]
  __int64 v86; // [rsp+E8h] [rbp-18h]
  __int64 v87; // [rsp+F0h] [rbp-10h]
  __int64 v88; // [rsp+F8h] [rbp-8h]
  __int64 v89; // [rsp+100h] [rbp+0h]
  __int64 v90; // [rsp+108h] [rbp+8h]
  __int64 v91; // [rsp+110h] [rbp+10h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v92; // [rsp+198h] [rbp+98h]
  Scaleform::LogMessageId id; // [rsp+1A0h] [rbp+A0h]
  Scaleform::LogMessageId v94; // [rsp+1A8h] [rbp+A8h]

  v92 = imageInfoArray;
  v91 = -2i64;
  v2 = this;
  v3 = imageInfoArray->Data.Size;
  v63 = v3;
  if ( v3 )
  {
    v4 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
    Scaleform::Render::TreeText::NotifyLayoutChanged(v4);
    v5 = v92;
    if ( v3 )
    {
      v6 = 0i64;
      v7 = 0i64;
      v58 = 0i64;
      while ( 1 )
      {
        v8 = v5->Data.Data;
        presBindData.pResource.pObject = 0i64;
        presBindData.pBinding = 0i64;
        v9 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v2->vfptr[66].__vecDelDtor)(v2);
        v10 = (Scaleform::GFx::MovieDefImpl *)v9;
        if ( v9 )
          _InterlockedExchangeAdd((volatile signed __int32 *)(v9 + 8), 1u);
        v90 = v9;
        if ( !v9 )
          goto LABEL_79;
        v11 = (unsigned __int64 *)((char *)&v8->Url.HeapTypeBits + v7);
        v12 = Scaleform::GFx::LoaderImpl::IsProtocolImage((Scaleform::String *)((char *)&v8->Url.0 + v7), 0i64, 0i64);
        if ( v12 )
          goto LABEL_22;
        if ( Scaleform::GFx::MovieImpl::FindExportedResource(
               v2->pASRoot->pMovieImpl,
               v10,
               &presBindData,
               (Scaleform::String *)((char *)&v8->Url.0 + v7)) )
        {
          break;
        }
        if ( ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v2->vfptr[76].__vecDelDtor)(v2) )
        {
          v13 = *v11 & 0xFFFFFFFFFFFFFFFCui64;
          v14 = (Scaleform::Log *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v2->vfptr[76].__vecDelDtor)(v2);
          Scaleform::Log::LogWarning(v14, "ProcessImageTags: cant find a resource for export name %s\n", v13 + 12);
        }
        if ( !_InterlockedDecrement(&v10->RefCount.Value) )
        {
          v15 = v10->pLib;
          if ( v15 )
          {
            v15->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->vfptr, (unsigned int)v10);
            v10->pLib = 0i64;
          }
          v10->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v10->vfptr, 1u);
        }
        v16 = presBindData.pResource.pObject;
        if ( presBindData.pResource.pObject && !_InterlockedDecrement(&presBindData.pResource.pObject->RefCount.Value) )
        {
          v17 = v16->pLib;
          if ( v17 )
          {
            v17->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v17->vfptr, (unsigned int)v16);
            v16->pLib = 0i64;
          }
          v16->vfptr->__vecDelDtor(v16, 1u);
        }
LABEL_91:
        v7 += 64i64;
        v58 = v7;
        v57 = v63-- == 1;
        v5 = v92;
        v6 = 0i64;
        if ( v57 )
          return;
      }
      if ( (((__int64 (*)(void))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)() & 0xFF00) == 256 )
      {
LABEL_22:
        v59 = 0i64;
        if ( v12 )
        {
          v33 = (__int64)v10->pLoaderImpl.pObject->pWeakResourceLib.pObject->pImageHeap.pObject;
          v74 = 1;
          v75 = v33;
          v76 = 0;
          v77 = 1;
          v78 = 0i64;
          v79 = 0i64;
          v80 = 0i64;
          v81 = 0i64;
          v34 = Scaleform::GFx::StateBag::GetImageFileHandlerRegistry((Scaleform::GFx::StateBag *)&v10->vfptr, &v70);
          v35 = (__int64 *)Scaleform::GFx::StateBag::GetFileOpener((Scaleform::GFx::StateBag *)&v10->vfptr, &v68);
          v36 = Scaleform::GFx::StateBag::GetLog((Scaleform::GFx::StateBag *)&v10->vfptr, &v72);
          v37 = (__int64)v34->pObject;
          v38 = (__int64)v36->pObject;
          v79 = *v35;
          v78 = v38;
          v80 = v37;
          if ( v72.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v72.pObject);
          if ( v68.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v68.pObject);
          if ( v70.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v70.pObject);
          v81 = v2->pASRoot->pMovieImpl;
          v39 = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)&v10->vfptr, &v71)->pObject;
          if ( v71.pObject )
            Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v71.pObject);
          if ( !v39 )
          {
            v94.Id = 135168;
            Scaleform::LogDebugMessage(
              (Scaleform::LogMessageId)&v94,
              "Image resource creation failed - ImageCreator not installed");
LABEL_74:
            v52 = *v11 & 0xFFFFFFFFFFFFFFFCui64;
            v62.Id = 135168;
            Scaleform::LogDebugMessage(
              (Scaleform::LogMessageId)&v62,
              "Image %s wasnt created in ProcessImageTags",
              v52 + 12);
            if ( !_InterlockedDecrement(&v10->RefCount.Value) )
            {
              v53 = v10->pLib;
              if ( v53 )
              {
                v53->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v53->vfptr, (unsigned int)v10);
                v10->pLib = 0i64;
              }
              v10->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v10->vfptr, 1u);
            }
LABEL_35:
            v26 = presBindData.pResource.pObject;
            if ( presBindData.pResource.pObject
              && !_InterlockedDecrement(&presBindData.pResource.pObject->RefCount.Value) )
            {
              v27 = v26->pLib;
              if ( v27 )
              {
                v27->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v27->vfptr, (unsigned int)v26);
                v26->pLib = 0i64;
              }
              v26->vfptr->__vecDelDtor(v26, 1u);
            }
            v7 = v58;
            goto LABEL_91;
          }
          v6 = (Scaleform::Render::ImageBase *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, signed __int64))v39->vfptr[1].__vecDelDtor)(
                                                 v39,
                                                 &v74,
                                                 (signed __int64)&v8->Url + v7);
        }
        else
        {
          v18 = v2->pASRoot->pMovieImpl;
          v19 = (const char *)((*v11 & 0xFFFFFFFFFFFFFFFCui64) + 12);
          v20 = (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v2->vfptr[66].__vecDelDtor)(v2);
          Scaleform::GFx::MovieImpl::GetImageResourceByLinkageId(v18, &result, v20, v19);
          if ( !result.pObject )
          {
            if ( ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v2->vfptr[76].__vecDelDtor)(v2) )
            {
              v21 = *v11 & 0xFFFFFFFFFFFFFFFCui64;
              v22 = (Scaleform::Log *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v2->vfptr[76].__vecDelDtor)(v2);
              Scaleform::Log::LogWarning(v22, "ProcessImageTags: cant load the image %s\n", v21 + 12);
            }
            v23 = result.pObject;
            if ( result.pObject && !_InterlockedDecrement(&result.pObject->RefCount.Value) )
            {
              v24 = v23->pLib;
              if ( v24 )
              {
                v24->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v24->vfptr, (unsigned int)v23);
                v23->pLib = 0i64;
              }
              v23->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v23->vfptr, 1u);
            }
            if ( !_InterlockedDecrement(&v10->RefCount.Value) )
            {
              v25 = v10->pLib;
              if ( v25 )
              {
                v25->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v25->vfptr, (unsigned int)v10);
                v10->pLib = 0i64;
              }
              v10->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v10->vfptr, 1u);
            }
            goto LABEL_35;
          }
          if ( ((unsigned int (*)(void))result.pObject->pImage->vfptr[3].__vecDelDtor)() )
          {
            v6 = result.pObject->pImage;
            if ( v6 )
              ((void (__fastcall *)(Scaleform::Render::ImageBase *))v6->vfptr[1].__vecDelDtor)(result.pObject->pImage);
            v59 = v6;
          }
          else
          {
            v28 = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)&v10->vfptr, &v69)->pObject == 0i64;
            if ( v69.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v69.pObject);
            if ( v28 )
            {
              id.Id = 135168;
              Scaleform::LogDebugMessage((Scaleform::LogMessageId)&id, "ImageCreator is null in ProcessImageTags");
            }
            else
            {
              v29 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v2);
              v82 = 3;
              v83 = v29;
              v84 = 1;
              v85 = 1;
              v86 = 0i64;
              v87 = 0i64;
              v88 = 0i64;
              v89 = 0i64;
              v30 = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)&v10->vfptr, &v73);
              v6 = (Scaleform::Render::ImageBase *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, Scaleform::Render::ImageBase *))v30->pObject->vfptr[4].__vecDelDtor)(
                                                     v30->pObject,
                                                     &v82,
                                                     result.pObject->pImage);
              v59 = v6;
              if ( v73.pObject )
                Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v73.pObject);
            }
          }
          v31 = result.pObject;
          if ( result.pObject )
          {
            if ( !_InterlockedDecrement(&result.pObject->RefCount.Value) )
            {
              v32 = v31->pLib;
              if ( v32 )
              {
                v32->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v32->vfptr, (unsigned int)v31);
                v31->pLib = 0i64;
              }
              v31->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v31->vfptr, 1u);
            }
            v6 = v59;
          }
        }
        if ( !v6 )
          goto LABEL_74;
        v6->vfptr[6].__vecDelDtor((Scaleform::RefCountImplCore *)&v6->vfptr, (unsigned int)&v64);
        v7 = v58;
        v40 = *(__int64 *)((char *)&v8->pTextImageDesc.pObject + v58);
        ((void (__fastcall *)(Scaleform::Render::ImageBase *))v6->vfptr[1].__vecDelDtor)(v6);
        v41 = *(_QWORD *)(v40 + 16);
        if ( v41 )
          (*(void (**)(void))(*(_QWORD *)v41 + 16i64))();
        *(_QWORD *)(v40 + 16) = v6;
        v42 = (float)(v66 - v64);
        v43 = (float)(v67 - v65);
        v44 = *(unsigned int *)((char *)&v8->Width + v58);
        if ( !v44 )
          v44 = 20 * (v66 - v64);
        v45 = (float)v44;
        v46 = *(unsigned int *)((char *)&v8->Height + v58);
        if ( !v46 )
          v46 = 20 * (v67 - v65);
        v47 = (float)v46;
        v48 = (float)*(int *)((char *)&v8->VSpace + v58);
        (*(Scaleform::Render::Text::ImageDesc **)((char *)&v8->pTextImageDesc.pObject + v58))->ScreenWidth = v45;
        (*(Scaleform::Render::Text::ImageDesc **)((char *)&v8->pTextImageDesc.pObject + v58))->ScreenHeight = (float)v46;
        (*(Scaleform::Render::Text::ImageDesc **)((char *)&v8->pTextImageDesc.pObject + v58))->BaseLineY = (float)((float)(v43 * 20.0) + v48) * 0.050000001;
        (*(Scaleform::Render::Text::ImageDesc **)((char *)&v8->pTextImageDesc.pObject + v58))->Matrix.M[1][3] = COERCE_FLOAT(LODWORD((*(Scaleform::Render::Text::ImageDesc **)((char *)&v8->pTextImageDesc.pObject + v58))->BaseLineY) ^ _xmm[0]) + (*(Scaleform::Render::Text::ImageDesc **)((char *)&v8->pTextImageDesc.pObject + v58))->Matrix.M[1][3];
        v49 = *(float **)((char *)&v8->pTextImageDesc.pObject + v58);
        v50 = v47 / v43;
        v51 = v45 / v42;
        v49[12] = v51 * v49[12];
        v49[13] = v51 * v49[13];
        v49[14] = v51 * v49[14];
        v49[15] = v51 * v49[15];
        v49[16] = v50 * v49[16];
        v49[17] = v50 * v49[17];
        v49[18] = v50 * v49[18];
        v49[19] = v50 * v49[19];
        v2->pDocument.pObject->RTFlags |= 2u;
        ((void (__fastcall *)(Scaleform::Render::ImageBase *))v6->vfptr[2].__vecDelDtor)(v6);
      }
      else
      {
        ((void (*)(void))presBindData.pResource.pObject->vfptr->GetResourceTypeCode)();
      }
LABEL_79:
      if ( v10 && !_InterlockedDecrement(&v10->RefCount.Value) )
      {
        v54 = v10->pLib;
        if ( v54 )
        {
          v54->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v54->vfptr, (unsigned int)v10);
          v10->pLib = 0i64;
        }
        v10->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v10->vfptr, 1u);
      }
      v55 = presBindData.pResource.pObject;
      if ( presBindData.pResource.pObject && !_InterlockedDecrement(&presBindData.pResource.pObject->RefCount.Value) )
      {
        v56 = v55->pLib;
        if ( v56 )
        {
          v56->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v56->vfptr, (unsigned int)v55);
          v55->pLib = 0i64;
        }
        v55->vfptr->__vecDelDtor(v55, 1u);
      }
      goto LABEL_91;
    }
  }
}

// File Line: 1793
// RVA: 0x900380
void __fastcall Scaleform::GFx::TextField::ReplaceText(Scaleform::GFx::TextField *this, const wchar_t *ptext, unsigned __int64 beginPos, unsigned __int64 endPos, unsigned __int64 textLen)
{
  Scaleform::GFx::TextField *v5; // rbx
  Scaleform::Render::Text::DocView *v6; // rcx
  unsigned __int64 v7; // rax
  Scaleform::GFx::Text::EditorKit *v8; // rcx
  unsigned __int8 v9; // al
  __int64 v10; // rax
  unsigned __int8 v11; // al
  __int64 v12; // rax
  Scaleform::Render::TreeText *v13; // rax

  v5 = this;
  Scaleform::Render::Text::DocView::ReplaceText(this->pDocument.pObject, ptext, beginPos, endPos, textLen);
  v6 = v5->pDocument.pObject;
  if ( v6->pEditorKit.pObject )
  {
    v7 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&v6->pDocument.pObject->vfptr);
    v8 = (Scaleform::GFx::Text::EditorKit *)v5->pDocument.pObject->pEditorKit.pObject;
    if ( v8->CursorPos > v7 )
      Scaleform::GFx::Text::EditorKit::SetCursorPos(v8, v7, 0);
  }
  v9 = v5->AvmObjOffset;
  if ( v9 )
  {
    v10 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->vfptr + 4 * v9))[4].__vecDelDtor)((signed __int64)v5 + 4 * v9);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 256i64))(v10);
  }
  v11 = v5->AvmObjOffset;
  v5->Flags |= 0x10000u;
  if ( v11 )
  {
    v12 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->vfptr + 4 * v11))[4].__vecDelDtor)((signed __int64)v5 + 4 * v11);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v12 + 192i64))(v12);
  }
  v13 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v13);
}

// File Line: 2301
// RVA: 0x90F940
void __fastcall Scaleform::GFx::TextField::SetX(Scaleform::GFx::TextField *this, long double x)
{
  double v2; // xmm12_8
  Scaleform::GFx::TextField *v3; // rbx
  __int64 v4; // rax
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
  Scaleform::Render::Rect<float> *v17; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v18; // rcx
  double v19; // xmm12_8
  Scaleform::Render::Matrix2x4<float> v20; // [rsp+20h] [rbp-69h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+40h] [rbp-49h]

  v2 = x;
  v3 = this;
  if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(*(_QWORD *)&x & 0xFFFFFFFFFFFFFi64) )
  {
    if ( x == -1.797693134862316e308/*-Inf*/ || x == 1.797693134862316e308/*+Inf*/ )
      v2 = 0.0;
    v4 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->vfptr[2].__vecDelDtor)(this);
    v5 = v2 * 20.0;
    v7 = *(float *)(v4 + 4);
    v8 = *(_DWORD *)(v4 + 8);
    v9 = *(float *)(v4 + 12);
    v10 = *(_DWORD *)(v4 + 16);
    v11 = *(_DWORD *)(v4 + 20);
    v12 = *(_DWORD *)(v4 + 24);
    v13 = *(_DWORD *)(v4 + 28);
    *(_QWORD *)&v20.M[0][0] = *(_QWORD *)v4;
    v6 = v20.M[0][0];
    *(_QWORD *)&v20.M[0][2] = __PAIR__(LODWORD(v9), v8);
    *(_QWORD *)&v20.M[1][0] = __PAIR__(v11, v10);
    *(_QWORD *)&v20.M[1][2] = __PAIR__(v13, v12);
    *(_QWORD *)&m.M[0][0] = __PAIR__(LODWORD(v7), LODWORD(v20.M[0][0]));
    *(_QWORD *)&m.M[0][2] = __PAIR__(LODWORD(v9), v8);
    *(_QWORD *)&m.M[1][0] = __PAIR__(v11, v10);
    *(_QWORD *)&m.M[1][2] = __PAIR__(v13, v12);
    v14 = v5;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v20, &m);
    v15 = (float)((float)(v20.M[1][1] * v14) + (float)(v20.M[1][0] * v14)) + v20.M[1][3];
    v16 = (float)((float)(v20.M[0][1] * v14) + (float)(v20.M[0][0] * v14)) + v20.M[0][3];
    v17 = Scaleform::Render::Text::DocView::GetViewRect(v3->pDocument.pObject);
    Scaleform::GFx::DisplayObjectBase::SetX(
      (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr,
      (float)((float)((float)((float)(v7 * v15) + (float)(v6 * (float)(v16 - v17->x1))) + v9) * 0.050000001));
    v18 = v3->pGeomData;
    if ( v18 )
    {
      if ( v5 <= 0.0 )
        v19 = v5 - 0.5;
      else
        v19 = v5 + 0.5;
      v18->X = (signed int)v19;
    }
  }
}

// File Line: 2327
// RVA: 0x910100
void __fastcall Scaleform::GFx::TextField::SetY(Scaleform::GFx::TextField *this, long double y)
{
  double v2; // xmm12_8
  Scaleform::GFx::TextField *v3; // rbx
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
  Scaleform::Render::Rect<float> *v16; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v17; // rcx
  double v18; // xmm12_8
  Scaleform::Render::Matrix2x4<float> v19; // [rsp+20h] [rbp-69h]
  Scaleform::Render::Matrix2x4<float> m; // [rsp+40h] [rbp-49h]

  v2 = y;
  v3 = this;
  if ( (*(_QWORD *)&y & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(*(_QWORD *)&y & 0xFFFFFFFFFFFFFi64) )
  {
    if ( y == -1.797693134862316e308/*-Inf*/ || y == 1.797693134862316e308/*+Inf*/ )
      v2 = 0.0;
    v4 = v2 * 20.0;
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::TextField *))this->vfptr[2].__vecDelDtor)(this);
    v6 = v4;
    v7 = *(_DWORD *)(v5 + 4);
    v8 = *(_DWORD *)(v5 + 8);
    v9 = *(float *)(v5 + 12);
    v10 = *(float *)(v5 + 16);
    v11 = *(float *)(v5 + 20);
    v12 = *(_DWORD *)(v5 + 24);
    v13 = *(float *)(v5 + 28);
    v19.M[0][0] = *(float *)v5;
    *(_QWORD *)&v19.M[0][1] = __PAIR__(v8, v7);
    v19.M[0][3] = v9;
    *(_QWORD *)&v19.M[1][0] = __PAIR__(LODWORD(v11), LODWORD(v10));
    *(_QWORD *)&v19.M[1][2] = __PAIR__(LODWORD(v13), v12);
    *(_QWORD *)&m.M[0][0] = __PAIR__(v7, LODWORD(v19.M[0][0]));
    *(_QWORD *)&m.M[0][2] = __PAIR__(LODWORD(v9), v8);
    *(_QWORD *)&m.M[1][0] = __PAIR__(LODWORD(v11), LODWORD(v10));
    *(_QWORD *)&m.M[1][2] = __PAIR__(LODWORD(v13), v12);
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v19, &m);
    v14 = (float)((float)(v19.M[1][1] * v6) + (float)(v19.M[1][0] * 0.0)) + v19.M[1][3];
    v15 = (float)((float)(v19.M[0][1] * v6) + (float)(v19.M[0][0] * 0.0)) + v19.M[0][3];
    v16 = Scaleform::Render::Text::DocView::GetViewRect(v3->pDocument.pObject);
    Scaleform::GFx::DisplayObjectBase::SetY(
      (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr,
      (float)((float)((float)((float)(v10 * v15) + (float)(v11 * (float)(v14 - v16->y1))) + v13) * 0.050000001));
    v17 = v3->pGeomData;
    if ( v17 )
    {
      if ( v4 <= 0.0 )
        v18 = v4 - 0.5;
      else
        v18 = v4 + 0.5;
      v17->Y = (signed int)v18;
    }
  }
}

// File Line: 2352
// RVA: 0x8E1BC0
double __fastcall Scaleform::GFx::TextField::GetX(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::DisplayObjectBase::GeomDataType pgeomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::TextField *v2; // rbx
  Scaleform::Render::Rect<float> *v3; // rax
  Scaleform::Render::Text::DocView *v4; // rcx
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  Scaleform::Render::TreeText *v8; // rax
  Scaleform::Render::Rect<float> rect; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  v4 = v2->pDocument.pObject;
  v5 = v3->x1;
  v6 = v3->y2;
  rect.y1 = v3->y1;
  rect.x1 = v5;
  rect.y2 = v6;
  v7 = width * 20.0;
  rect.x2 = v7 + v5;
  Scaleform::Render::Text::DocView::SetViewRect(v4, &rect, UseExternally);
  v2->Flags |= 0x2000u;
  v8 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v8);
}

// File Line: 2375
// RVA: 0x907BD0
void __fastcall Scaleform::GFx::TextField::SetHeight(Scaleform::GFx::TextField *this, long double height)
{
  Scaleform::GFx::TextField *v2; // rbx
  Scaleform::Render::Rect<float> *v3; // rax
  Scaleform::Render::Text::DocView *v4; // rcx
  float v5; // xmm3_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  Scaleform::Render::TreeText *v8; // rax
  Scaleform::Render::Rect<float> rect; // [rsp+20h] [rbp-28h]

  v2 = this;
  v3 = Scaleform::Render::Text::DocView::GetViewRect(this->pDocument.pObject);
  v4 = v2->pDocument.pObject;
  v5 = v3->y1;
  v6 = v3->x2;
  rect.x1 = v3->x1;
  rect.y1 = v5;
  rect.x2 = v6;
  v7 = height * 20.0;
  rect.y2 = v7 + v5;
  Scaleform::Render::Text::DocView::SetViewRect(v4, &rect, UseExternally);
  v2->Flags |= 0x2000u;
  v8 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v8);
}

// File Line: 2384
// RVA: 0x90FED0
void __fastcall Scaleform::GFx::TextField::SetXScale(Scaleform::GFx::TextField *this, long double xscale)
{
  Scaleform::GFx::TextField *v2; // rbx
  Scaleform::Render::TreeText *v3; // rax

  this->Flags |= 0x2000u;
  v2 = this;
  v3 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v3);
  Scaleform::GFx::DisplayObjectBase::SetXScale((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr, xscale);
}

// File Line: 2390
// RVA: 0x9106A0
void __fastcall Scaleform::GFx::TextField::SetYScale(Scaleform::GFx::TextField *this, long double yscale)
{
  Scaleform::GFx::TextField *v2; // rbx
  Scaleform::Render::TreeText *v3; // rax

  this->Flags |= 0x2000u;
  v2 = this;
  v3 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v3);
  Scaleform::GFx::DisplayObjectBase::SetYScale((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr, yscale);
}

// File Line: 2396
// RVA: 0x90B4B0
void __fastcall Scaleform::GFx::TextField::SetRotation(Scaleform::GFx::TextField *this, long double rotation)
{
  Scaleform::GFx::TextField *v2; // rbx
  Scaleform::Render::TreeText *v3; // rax

  this->Flags |= 0x2000u;
  v2 = this;
  v3 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v3);
  Scaleform::GFx::DisplayObjectBase::SetRotation((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr, rotation);
}

// File Line: 2402
// RVA: 0x9062C0
void __fastcall Scaleform::GFx::TextField::SetBackground(Scaleform::GFx::TextField *this, bool b)
{
  Scaleform::Render::Text::DocView *v2; // r8
  Scaleform::GFx::TextField *v3; // rbx
  Scaleform::Render::TreeText *v4; // rax
  Scaleform::Render::TreeText *v5; // rax
  unsigned int v6; // [rsp+38h] [rbp+10h]

  v2 = this->pDocument.pObject;
  v3 = this;
  v6 = v2->BackgroundColor;
  HIBYTE(v6) = -(b != 0);
  v2->BackgroundColor = v6;
  v4 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v4);
  v5 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v5);
}

// File Line: 2413
// RVA: 0x906380
void __fastcall Scaleform::GFx::TextField::SetBackgroundColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::Render::TreeText *v2; // rax

  this->pDocument.pObject->BackgroundColor ^= (rgb ^ this->pDocument.pObject->BackgroundColor) & 0xFFFFFF;
  v2 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v2);
}

// File Line: 2425
// RVA: 0x906760
void __fastcall Scaleform::GFx::TextField::SetBorder(Scaleform::GFx::TextField *this, bool b)
{
  Scaleform::Render::Text::DocView *v2; // r8
  Scaleform::GFx::TextField *v3; // rbx
  Scaleform::Render::TreeText *v4; // rax
  Scaleform::Render::TreeText *v5; // rax
  unsigned int v6; // [rsp+38h] [rbp+10h]

  v2 = this->pDocument.pObject;
  v3 = this;
  v6 = v2->BorderColor;
  HIBYTE(v6) = -(b != 0);
  v2->BorderColor = v6;
  v4 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v4);
  v5 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v5);
}

// File Line: 2442
// RVA: 0x9067C0
void __fastcall Scaleform::GFx::TextField::SetBorderColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::Render::TreeText *v2; // rax

  this->pDocument.pObject->BorderColor ^= (rgb ^ this->pDocument.pObject->BorderColor) & 0xFFFFFF;
  v2 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v2);
}

// File Line: 2448
// RVA: 0x90CA00
void __fastcall Scaleform::GFx::TextField::SetText(Scaleform::GFx::TextField *this, const wchar_t *pnewText, bool reqHtml)
{
  unsigned int v3; // eax
  bool v4; // r14
  const wchar_t *v5; // rbp
  Scaleform::GFx::TextField *v6; // rbx
  char v7; // r9
  unsigned int v8; // eax
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rsi
  char *v11; // rdi

  v3 = this->Flags;
  v4 = reqHtml;
  v5 = pnewText;
  v6 = this;
  v7 = (this->Flags >> 1) & 1;
  if ( reqHtml )
  {
    if ( v7 )
      goto LABEL_7;
    v8 = v3 | 2;
  }
  else
  {
    if ( !v7 )
      goto LABEL_7;
    v8 = v3 & 0xFFFFFFFD;
  }
  this->Flags = v8;
LABEL_7:
  v9 = Scaleform::SFwcslen(pnewText);
  v10 = v9 + 2 * v9 + 1;
  if ( v10 > 0x200 )
    v11 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                    Scaleform::Memory::pGlobalHeap,
                    v6,
                    v9 + 2 * v9 + 1,
                    0i64);
  else
    v11 = stackBuff;
  Scaleform::UTF8Util::EncodeStringSafe(v11, v10, v5, -1i64);
  Scaleform::GFx::TextField::SetTextValue(v6, v11, v4, 1);
  if ( v11 != stackBuff )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
}

// File Line: 2470
// RVA: 0x90CAF0
void __fastcall Scaleform::GFx::TextField::SetTextColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  unsigned int v2; // ebx
  Scaleform::GFx::TextField *v3; // rdi
  Scaleform::MemoryHeap *v4; // rax
  Scaleform::Render::TreeText *v5; // rax
  Scaleform::Render::Text::TextFormat fmt; // [rsp+30h] [rbp-58h]

  v2 = rgb;
  v3 = this;
  v4 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
  Scaleform::Render::Text::TextFormat::TextFormat(&fmt, v4);
  v2 &= 0xFFFFFFu;
  fmt.ColorV = v2 | fmt.ColorV & 0xFF000000;
  fmt.PresentMask |= 1u;
  Scaleform::Render::Text::DocView::SetTextFormat(v3->pDocument.pObject, &fmt, 0i64, 0xFFFFFFFFFFFFFFFFui64);
  Scaleform::Render::Text::TextFormat::operator=(
    &fmt,
    v3->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject);
  fmt.ColorV = v2 | fmt.ColorV & 0xFF000000;
  fmt.PresentMask |= 1u;
  Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
    (Scaleform::Render::Text::StyledText *)&v3->pDocument.pObject->pDocument.pObject->vfptr,
    &fmt);
  v3->Flags |= 0x10000u;
  v5 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v5);
  Scaleform::Render::Text::TextFormat::~TextFormat(&fmt);
}

// File Line: 2491
// RVA: 0x8DE9C0
__int64 __fastcall Scaleform::GFx::TextField::GetTextColor32(Scaleform::GFx::TextField *this)
{
  unsigned int v1; // ecx

  v1 = this->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject->ColorV;
  return (unsigned __int8)v1 | ((BYTE1(v1) | ((unsigned int)BYTE2(v1) << 8)) << 8);
}

// File Line: 2497
// RVA: 0x90BE20
void __fastcall Scaleform::GFx::TextField::SetShadowStyle(Scaleform::GFx::TextField *this, const char *pstr)
{
  const char *v2; // r15
  Scaleform::GFx::TextField *v3; // r14
  Scaleform::GFx::TextField::ShadowParams *v4; // rbx
  Scaleform::GFx::ASStringManager *v5; // rax
  Scaleform::GFx::TextField::ShadowParams *v6; // rax
  int v7; // edx
  Scaleform::GFx::TextField::ShadowParams *v8; // rbx
  Scaleform::GFx::TextField::ShadowParams *v9; // rbx
  const char *v10; // rsi
  Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *v11; // rdi
  char v12; // cl
  _BYTE *v13; // rsi
  _BYTE *v14; // rbx
  char v15; // al
  float v16; // xmm7_4
  _BYTE *v17; // rbx
  _BYTE *v18; // rdx
  signed __int64 v19; // rsi
  float v20; // xmm6_4
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rbx
  unsigned __int64 v23; // r8
  signed __int64 v24; // rcx
  Scaleform::GFx::ASStringManager *v25; // rax
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::TextField::ShadowParams *v27; // rbx
  Scaleform::GFx::ASStringNode *v28; // rdi
  Scaleform::GFx::ASStringNode *v29; // rcx
  bool v30; // zf
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::Render::TreeText *v32; // rax
  __int64 v33; // [rsp+20h] [rbp-88h]
  char Dst[24]; // [rsp+28h] [rbp-80h]
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp+8h]
  __int64 v36; // [rsp+C0h] [rbp+18h]
  Scaleform::GFx::TextField::ShadowParams *v37; // [rsp+C8h] [rbp+20h]

  result.pNode = (Scaleform::GFx::ASStringNode *)this;
  v33 = -2i64;
  v2 = pstr;
  v3 = this;
  if ( this->pShadow
    || ((LODWORD(v36) = 323,
         v4 = (Scaleform::GFx::TextField::ShadowParams *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::TextField *, signed __int64, __int64 *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this,
                                                           64i64,
                                                           &v36,
                                                           v33),
         (v37 = v4) == 0i64) ? (v6 = 0i64) : (v5 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v3->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)(),
                                              Scaleform::GFx::TextField::ShadowParams::ShadowParams(v4, v5)),
        (v3->pShadow = v6) != 0i64) )
  {
    v7 = v3->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw & 0xFFFFFF;
    v3->pShadow->ShadowColor.Channels.Blue = v3->pDocument.pObject->Filter.ShadowParams.Colors[0].Channels.Blue;
    v3->pShadow->ShadowColor.Channels.Green = BYTE1(v7);
    v3->pShadow->ShadowColor.Channels.Red = BYTE2(v7);
    v3->pDocument.pObject->Filter.ShadowFlags |= 1u;
$reset:
    v8 = v3->pShadow;
    if ( v8->ShadowOffsets.Data.Size && v8->ShadowOffsets.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v8->ShadowOffsets.Data.Data )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v8->ShadowOffsets.Data.Data = 0i64;
      }
      v8->ShadowOffsets.Data.Policy.Capacity = 0i64;
    }
    v8->ShadowOffsets.Data.Size = 0i64;
    v9 = v3->pShadow;
    if ( v9->TextOffsets.Data.Size && v9->TextOffsets.Data.Policy.Capacity & 0xFFFFFFFFFFFFFFFEui64 )
    {
      if ( v9->TextOffsets.Data.Data )
      {
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v9->TextOffsets.Data.Data = 0i64;
      }
      v9->TextOffsets.Data.Policy.Capacity = 0i64;
    }
    v9->TextOffsets.Data.Size = 0i64;
    v10 = v2;
    v11 = 0i64;
    while ( 1 )
    {
      v12 = *v10;
      if ( !*v10 )
        break;
      if ( (v12 - 83) & 0xDF )
      {
        if ( (v12 - 84) & 0xDF )
        {
          if ( v12 == 123 && v11 )
          {
            v13 = v10 + 1;
            v14 = v13;
            v15 = *v13;
            if ( *v13 )
            {
              while ( v15 != 44 )
              {
                v15 = *++v14;
                if ( !*v14 )
                  goto LABEL_46;
              }
            }
            if ( *v14 && v14 - v13 <= 23 )
            {
              memmove(Dst, v13, v14 - v13);
              Dst[v14 - v13] = 0;
              v16 = Scaleform::SFstrtod(Dst, 0i64) * 20.0;
              v17 = v14 + 1;
              v18 = v17;
              while ( 1 )
              {
                if ( !*v17 )
                  goto LABEL_46;
                if ( *v17 == 125 )
                  break;
                ++v17;
              }
              if ( *v17 )
              {
                v19 = v17 - v18;
                if ( v17 - v18 <= 23 )
                {
                  memmove(Dst, v18, v17 - v18);
                  Dst[v19] = 0;
                  v20 = Scaleform::SFstrtod(Dst, 0i64) * 20.0;
                  v10 = v17 + 1;
                  v21 = v11->Size;
                  v22 = v21 + 1;
                  if ( v21 + 1 >= v21 )
                  {
                    if ( v22 > v11->Policy.Capacity )
                    {
                      v23 = v22 + (v22 >> 2);
LABEL_40:
                      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                        v11,
                        v11,
                        v23);
                    }
                  }
                  else if ( v22 < v11->Policy.Capacity >> 1 )
                  {
                    v23 = v21 + 1;
                    goto LABEL_40;
                  }
                  v11->Size = v22;
                  v24 = (signed __int64)&v11->Data[v22 - 1];
                  result.pNode = (Scaleform::GFx::ASStringNode *)v24;
                  v36 = v24;
                  if ( v24 )
                  {
                    *(float *)v24 = v16;
                    *(float *)(v24 + 4) = v20;
                  }
                  continue;
                }
              }
            }
          }
LABEL_46:
          v2 = v3->pShadow->ShadowStyleStr.pNode->pData;
          goto $reset;
        }
        v11 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->pShadow->TextOffsets;
        ++v10;
      }
      else
      {
        v11 = (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)&v3->pShadow->ShadowOffsets;
        ++v10;
      }
    }
    if ( *v2 )
    {
      v25 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v3->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
      v26 = Scaleform::GFx::ASStringManager::CreateString(v25, &result, v2);
      v27 = v3->pShadow;
      v28 = v26->pNode;
      ++v28->RefCount;
      v29 = v27->ShadowStyleStr.pNode;
      v30 = v29->RefCount-- == 1;
      if ( v30 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      v27->ShadowStyleStr.pNode = v28;
      v31 = result.pNode;
      v30 = result.pNode->RefCount == 1;
      --v31->RefCount;
      if ( v30 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v31);
    }
    v32 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
    Scaleform::Render::TreeText::NotifyLayoutChanged(v32);
  }
}

// File Line: 2568
// RVA: 0x90BDA0
void __fastcall Scaleform::GFx::TextField::SetShadowColor(Scaleform::GFx::TextField *this, unsigned int rgb)
{
  Scaleform::GFx::TextField *v2; // r9
  Scaleform::GFx::TextField::ShadowParams *v3; // rcx
  int v4; // edx
  Scaleform::Render::TreeText *v5; // rax

  v2 = this;
  this->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw = rgb & 0xFFFFFF | ((unsigned __int8)this->pDocument.pObject->Filter.ShadowAlpha << 24);
  v3 = this->pShadow;
  if ( v3 )
  {
    v4 = v2->pDocument.pObject->Filter.ShadowParams.Colors[0].Raw & 0xFFFFFF;
    v3->ShadowColor.Channels.Blue = v2->pDocument.pObject->Filter.ShadowParams.Colors[0].Channels.Blue;
    v2->pShadow->ShadowColor.Channels.Green = BYTE1(v4);
    v2->pShadow->ShadowColor.Channels.Red = BYTE2(v4);
  }
  v5 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v5);
}

// File Line: 2582
// RVA: 0x8DE010
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::TextField::GetShadowStyle(Scaleform::GFx::TextField *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::TextField::ShadowParams *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rbx
  __int64 *v5; // rax
  char v6; // di
  Scaleform::GFx::ASMovieRootBase *v7; // rcx
  Scaleform::GFx::ASStringManager *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rax
  char v10; // di
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v14; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString *v15; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::ASString resulta; // [rsp+60h] [rbp+18h]

  v15 = result;
  v2 = result;
  v3 = this->pShadow;
  if ( v3 )
  {
    v4 = v3->ShadowStyleStr.pNode;
    v14 = v4;
    ++v4->RefCount;
    v5 = (__int64 *)&v14;
    v6 = 1;
  }
  else
  {
    v7 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v8 = (Scaleform::GFx::ASStringManager *)((__int64 (__cdecl *)(Scaleform::GFx::ASMovieRootBase *, Scaleform::GFx::ASString *))v7->vfptr[59].__vecDelDtor)(
                                              v7,
                                              result);
    v5 = (__int64 *)Scaleform::GFx::ASStringManager::CreateEmptyString(v8, &resulta);
    v6 = 2;
    v4 = v14;
  }
  v9 = (Scaleform::GFx::ASStringNode *)*v5;
  v2->pNode = v9;
  ++v9->RefCount;
  v10 = v6 | 4;
  if ( v10 & 2 )
  {
    v10 &= 0xFDu;
    v11 = resulta.pNode;
    v12 = resulta.pNode->RefCount == 1;
    --v11->RefCount;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
  if ( v10 & 1 )
  {
    v12 = v4->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  }
  return v2;
}

// File Line: 2588
// RVA: 0x8D6660
__int64 __fastcall Scaleform::GFx::TextField::GetCursorPos(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *v1; // rax
  __int64 result; // rax

  v1 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v1 )
    result = *(_QWORD *)&v1[3].RefCount;
  else
    result = -1i64;
  return result;
}

// File Line: 2593
// RVA: 0x90AEB0
__int64 __fastcall Scaleform::GFx::TextField::SetRestrict(Scaleform::GFx::TextField *this, Scaleform::GFx::ASString *restrStr)
{
  const char ***v2; // rdi
  Scaleform::GFx::TextField *v3; // rbx
  Scaleform::String *v4; // rax
  Scaleform::String *v5; // rdi
  Scaleform::GFx::Text::EditorKit *v6; // rbx
  unsigned __int8 v7; // si
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> result; // [rsp+40h] [rbp+8h]
  Scaleform::String v10; // [rsp+48h] [rbp+10h]

  v2 = (const char ***)restrStr;
  v3 = this;
  if ( !this->pDocument.pObject->pEditorKit.pObject )
  {
    Scaleform::GFx::TextField::CreateEditorKit(this, &result);
    if ( result.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  }
  Scaleform::String::String(&v10, **v2);
  v5 = v4;
  v6 = (Scaleform::GFx::Text::EditorKit *)v3->pDocument.pObject->pEditorKit.pObject;
  v7 = Scaleform::GFx::Text::EditorKit::ParseRestrict(
         v6,
         (const char *)((v4->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
         *(_QWORD *)(v4->HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64);
  Scaleform::String::operator=((Scaleform::String *)&v6->pRestrict.pObject->RestrictString.0, v5);
  if ( !_InterlockedDecrement((volatile signed __int32 *)((v10.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v7;
}

// File Line: 2607
// RVA: 0x8BC980
void __fastcall Scaleform::GFx::TextField::ClearRestrict(Scaleform::GFx::TextField *this)
{
  Scaleform::Render::Text::EditorKitBase *v1; // rbx
  Scaleform::GFx::Text::EditorKit::RestrictParams *v2; // rcx

  v1 = this->pDocument.pObject->pEditorKit.pObject;
  if ( v1 )
  {
    v2 = *(Scaleform::GFx::Text::EditorKit::RestrictParams **)&v1[2].RefCount;
    if ( v2 )
    {
      if ( LOBYTE(v1[3].vfptr) )
      {
        LOBYTE(v1[3].vfptr) = 0;
        Scaleform::GFx::Text::EditorKit::RestrictParams::`scalar deleting destructor(v2, 1);
      }
      *(_QWORD *)&v1[2].RefCount = 0i64;
    }
    LOBYTE(v1[3].vfptr) = 0;
  }
}

// File Line: 2613
// RVA: 0x8C2A20
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::TextField::CreateRenderNode(Scaleform::GFx::TextField *this, Scaleform::Ptr<Scaleform::Render::TreeNode> *result, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::Context *v3; // rsi
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v4; // rdi
  Scaleform::GFx::TextField *v5; // rbp
  Scaleform::Render::TreeText::NodeData *v6; // rax
  Scaleform::Render::ContextImpl::EntryData *v7; // rbx
  Scaleform::Render::TreeText *v8; // rbx
  bool v9; // zf

  v3 = context;
  v4 = result;
  v5 = this;
  v6 = (Scaleform::Render::TreeText::NodeData *)context->pHeap->vfptr->Alloc(context->pHeap, 176ui64, 0i64);
  v7 = (Scaleform::Render::ContextImpl::EntryData *)&v6->vfptr;
  if ( v6 )
    Scaleform::Render::TreeText::NodeData::NodeData(v6);
  v8 = (Scaleform::Render::TreeText *)Scaleform::Render::ContextImpl::Context::createEntryHelper(v3, v7);
  Scaleform::Render::TreeText::Init(v8, v5->pDocument.pObject);
  if ( v8 )
    ++v8->RefCount;
  v4->pObject = (Scaleform::Render::TreeNode *)&v8->0;
  if ( v8 )
  {
    v9 = v8->RefCount-- == 1;
    if ( v9 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v8->0);
  }
  return v4;
}

// File Line: 2627
// RVA: 0x8E71E0
bool __fastcall Scaleform::GFx::TextField::IsFocusEnabled(Scaleform::GFx::TextField *this, Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 v2; // al
  Scaleform::GFx::FocusMovedType v3; // ebx
  __int64 v4; // rax

  v2 = this->AvmObjOffset;
  v3 = fmt;
  if ( !v2 )
    return 0;
  v4 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v2))[4].__vecDelDtor)();
  return (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 160i64))(v4, (unsigned int)v3);
}

// File Line: 2644
// RVA: 0x89E150
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::TextDocumentListener(Scaleform::GFx::TextField::TextDocumentListener *this)
{
  Scaleform::GFx::TextField::TextDocumentListener *v1; // rbx
  Scaleform::GFx::Translator *v2; // rcx
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+48h] [rbp+10h]

  v1 = this;
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
  v2 = result.pObject;
  if ( result.pObject )
  {
    if ( result.pObject->WWMode )
      v1->HandlersMask |= 1u;
    if ( (((unsigned int (__cdecl *)(Scaleform::GFx::Translator *))v2->vfptr[1].__vecDelDtor)(v2) >> 2) & 1 )
      v1->HandlersMask |= 0x10u;
  }
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 2660
// RVA: 0x9149C0
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::TranslatorChanged(Scaleform::GFx::TextField::TextDocumentListener *this)
{
  Scaleform::GFx::TextField::TextDocumentListener *v1; // rbx
  Scaleform::GFx::Translator *v2; // rcx
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+40h] [rbp+8h]

  v1 = this;
  Scaleform::GFx::StateBag::GetTranslator(
    (Scaleform::GFx::StateBag *)(*(_QWORD *)(*(_QWORD *)&this[-11].RefCount + 16i64) + 16i64),
    &result);
  v2 = result.pObject;
  if ( result.pObject && result.pObject->WWMode )
    v1->HandlersMask |= 1u;
  else
    v1->HandlersMask &= 0xFEu;
  if ( v2 && (((unsigned int (__cdecl *)(Scaleform::GFx::Translator *))v2->vfptr[1].__vecDelDtor)(v2) >> 2) & 1 )
    v1->HandlersMask |= 0x10u;
  else
    v1->HandlersMask &= 0xEFu;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
}

// File Line: 2682
// RVA: 0x919570
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::View_OnMaxScrollChanged(Scaleform::GFx::TextField::TextDocumentListener *this, Scaleform::Render::Text::DocView *view, __int64 newScroll)
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
__int64 __fastcall Scaleform::GFx::TextField::TextDocumentListener::View_OnLineFormat(Scaleform::GFx::TextField::TextDocumentListener *this, Scaleform::Render::Text::DocView *__formal, Scaleform::Render::Text::DocView::LineFormatDesc *desc)
{
  Scaleform::Render::Text::DocView::LineFormatDesc *v3; // rbx
  Scaleform::GFx::Translator *v4; // rcx
  unsigned __int64 v5; // r8
  unsigned __int8 v6; // bl
  const wchar_t *v8; // [rsp+30h] [rbp-58h]
  unsigned __int64 v9; // [rsp+38h] [rbp-50h]
  float *v10; // [rsp+40h] [rbp-48h]
  unsigned __int64 v11; // [rsp+48h] [rbp-40h]
  unsigned __int64 v12; // [rsp+50h] [rbp-38h]
  float v13; // [rsp+58h] [rbp-30h]
  float v14; // [rsp+5Ch] [rbp-2Ch]
  float v15; // [rsp+60h] [rbp-28h]
  float v16; // [rsp+64h] [rbp-24h]
  char v17; // [rsp+68h] [rbp-20h]
  unsigned __int64 v18; // [rsp+70h] [rbp-18h]
  bool v19; // [rsp+78h] [rbp-10h]
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+90h] [rbp+8h]

  v3 = desc;
  Scaleform::GFx::StateBag::GetTranslator(
    (Scaleform::GFx::StateBag *)(*(_QWORD *)(*(_QWORD *)&this[-11].RefCount + 16i64) + 16i64),
    &result);
  v4 = result.pObject;
  if ( !result.pObject )
    goto LABEL_13;
  v14 = v3->CurrentLineWidth * 0.050000001;
  v16 = v3->DashSymbolWidth * 0.050000001;
  v11 = v3->LineStartPos;
  v15 = v3->LineWidthBeforeWordWrap * 0.050000001;
  v12 = v3->NumCharsInLine;
  v10 = v3->pWidths;
  v8 = v3->pParaText;
  v9 = v3->ParaTextLen;
  v18 = v3->ProposedWordWrapPoint;
  v13 = v3->VisibleRectWidth * 0.050000001;
  v19 = v3->UseHyphenation;
  v17 = v3->Alignment;
  v5 = 0i64;
  if ( v12 )
  {
    do
    {
      v3->pWidths[v5] = v3->pWidths[v5] * 0.050000001;
      ++v5;
    }
    while ( v5 < v12 );
    v4 = result.pObject;
  }
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Translator *, const wchar_t **, unsigned __int64))v4->vfptr[3].__vecDelDtor)(
         v4,
         &v8,
         v5) )
  {
    v3->ProposedWordWrapPoint = v18;
    v3->UseHyphenation = v19;
    v6 = 1;
  }
  else
  {
LABEL_13:
    v6 = 0;
  }
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  return v6;
}

// File Line: 2738
// RVA: 0x9195B0
__int64 __fastcall Scaleform::GFx::TextField::TextDocumentListener::View_PrepareBidiText(Scaleform::GFx::TextField::TextDocumentListener *this, Scaleform::Render::Text::DocView *__formal, const wchar_t *paraText, unsigned __int64 textLen, wchar_t *newParaText, unsigned int *indexMap, bool *mirroredBits)
{
  unsigned __int64 v7; // rbx
  const wchar_t *v8; // rdi
  unsigned __int8 v9; // bl
  Scaleform::Ptr<Scaleform::GFx::Translator> result; // [rsp+50h] [rbp+8h]

  v7 = textLen;
  v8 = paraText;
  Scaleform::GFx::StateBag::GetTranslator(
    (Scaleform::GFx::StateBag *)(*(_QWORD *)(*(_QWORD *)&this[-11].RefCount + 16i64) + 16i64),
    &result);
  if ( result.pObject && (((unsigned int (*)(void))result.pObject->vfptr[1].__vecDelDtor)() >> 2) & 1 )
    v9 = ((__int64 (__fastcall *)(Scaleform::GFx::Translator *, const wchar_t *, unsigned __int64, wchar_t *, unsigned int *, bool *, signed __int64))result.pObject->vfptr[4].__vecDelDtor)(
           result.pObject,
           v8,
           v7,
           newParaText,
           indexMap,
           mirroredBits,
           -2i64);
  else
    v9 = 0;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  return v9;
}

// File Line: 2748
// RVA: 0x919400
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::View_OnChanged(Scaleform::GFx::TextField::TextDocumentListener *this, Scaleform::Render::Text::DocView *__formal)
{
  Scaleform::Render::TreeText *v2; // rax

  v2 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this[-12]);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v2);
}

// File Line: 2755
// RVA: 0x8C7F60
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::Editor_OnChanged(Scaleform::GFx::TextField::TextDocumentListener *this, Scaleform::Render::Text::EditorKitBase *editor)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx
  Scaleform::RefCountImplCoreVtbl *v3; // ST20_8
  __int64 v4; // ST28_8
  unsigned __int8 v5; // al
  __int64 v6; // rax
  unsigned __int8 v7; // al
  __int64 v8; // rax
  Scaleform::Render::TreeText *v9; // rax

  v2 = (Scaleform::GFx::DisplayObjectBase *)&this[-12];
  v3 = editor->vfptr;
  v4 = *(_QWORD *)&editor->RefCount;
  Scaleform::Render::Text::DocView::GetText(
    *(Scaleform::Render::Text::DocView **)&this[-3].RefCount,
    (Scaleform::String *)&this[-2].HandlersMask);
  v5 = v2->AvmObjOffset;
  if ( v5 )
  {
    v6 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v2->vfptr + 4 * v5))[4].__vecDelDtor)((signed __int64)v2 + 4 * v5);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 256i64))(v6);
  }
  v7 = v2->AvmObjOffset;
  if ( v7 )
  {
    v8 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v2->vfptr + 4 * v7))[4].__vecDelDtor)((signed __int64)v2 + 4 * v7);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 192i64))(v8);
  }
  v9 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v2);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v9);
}

// File Line: 2772
// RVA: 0x8C8000
void __fastcall Scaleform::GFx::TextField::TextDocumentListener::Editor_OnCursorBlink(Scaleform::GFx::TextField::TextDocumentListener *this, Scaleform::Render::Text::EditorKitBase *editor)
{
  Scaleform::RefCountImplCoreVtbl *v2; // ST20_8
  __int64 v3; // ST28_8
  Scaleform::Render::TreeText *v4; // rax

  v2 = editor->vfptr;
  v3 = *(_QWORD *)&editor->RefCount;
  v4 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this[-12]);
  Scaleform::Render::TreeText::NotifyLayoutChanged(v4);
}

// File Line: 2780
// RVA: 0x8C8030
char __fastcall Scaleform::GFx::TextField::TextDocumentListener::Editor_OnInsertingText(Scaleform::GFx::TextField::TextDocumentListener *this, Scaleform::Render::Text::EditorKitBase *__formal, unsigned __int64 pos, unsigned __int64 len, const wchar_t *wstr)
{
  unsigned __int8 v5; // al
  unsigned __int64 v6; // rbx
  unsigned __int64 v7; // rdi
  void *v8; // rax

  v5 = *((_BYTE *)&this[-8].RefCount + 5);
  v6 = len;
  v7 = pos;
  if ( !v5 )
    return 1;
  v8 = (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this[-12].vfptr + 4 * v5))[4].__vecDelDtor(
         (Scaleform::RefCountNTSImplCore *)((char *)&this[-12] + 4 * v5),
         (unsigned int)__formal);
  return (*(__int64 (__fastcall **)(void *, unsigned __int64, unsigned __int64, const wchar_t *))(*(_QWORD *)v8 + 232i64))(
           v8,
           v7,
           v6,
           wstr);
}

// File Line: 2787
// RVA: 0x8C80A0
char __fastcall Scaleform::GFx::TextField::TextDocumentListener::Editor_OnRemovingText(Scaleform::GFx::TextField::TextDocumentListener *this, Scaleform::Render::Text::EditorKitBase *__formal, unsigned __int64 pos, unsigned __int64 len)
{
  unsigned __int8 v4; // al
  unsigned __int64 v5; // rbx
  unsigned __int64 v6; // rdi
  void *v7; // rax

  v4 = *((_BYTE *)&this[-8].RefCount + 5);
  v5 = len;
  v6 = pos;
  if ( !v4 )
    return 1;
  v7 = (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this[-12].vfptr + 4 * v4))[4].__vecDelDtor(
         (Scaleform::RefCountNTSImplCore *)((char *)&this[-12] + 4 * v4),
         (unsigned int)__formal);
  return (*(__int64 (__fastcall **)(void *, unsigned __int64, unsigned __int64, _QWORD))(*(_QWORD *)v7 + 240i64))(
           v7,
           v6,
           v5,
           0i64);
}

// File Line: 2795
// RVA: 0x8D6270
Scaleform::String *__fastcall Scaleform::GFx::TextField::TextDocumentListener::GetCharacterPath(Scaleform::GFx::TextField::TextDocumentListener *this, Scaleform::String *result)
{
  Scaleform::String *v2; // rdi
  Scaleform::GFx::TextField::TextDocumentListener *v3; // rbx
  unsigned __int8 v4; // al

  v2 = result;
  v3 = this;
  Scaleform::String::String(result);
  v4 = *((_BYTE *)&v3[-8].RefCount + 5);
  if ( v4 )
    (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * (v4 - 72i64)))[6].__vecDelDtor(
      (Scaleform::RefCountNTSImplCore *)((char *)&v3->vfptr + 4 * (v4 - 72i64)),
      (unsigned int)v2);
  return v2;
}

// File Line: 2813
// RVA: 0x8D7D70
Scaleform::Render::FilterSet *__fastcall Scaleform::GFx::TextField::GetFilters(Scaleform::GFx::TextField *this)
{
  Scaleform::GFx::TextField *v1; // rsi
  Scaleform::Render::TreeText *v2; // rbp
  Scaleform::Render::TreeText::Filter *v3; // rbx
  signed int v4; // edi
  unsigned __int64 v5; // rbp
  Scaleform::Render::FilterSet *v6; // rax
  Scaleform::Render::FilterSet *v7; // rax
  Scaleform::Render::FilterSet *v8; // rbx
  Scaleform::Render::RenderBuffer *v9; // rcx
  $AD53D16137C3AE4177DAFEDA37259559 *v10; // rbx
  Scaleform::Render::GlowFilter *v11; // rax
  __int64 v12; // rax
  __int64 v13; // rdi
  char v14; // cl
  signed int v15; // eax
  Scaleform::Render::BlurFilter *v16; // rax
  __int64 v17; // rax
  Scaleform::Render::ShadowFilter *v18; // rax
  __int64 v19; // rax
  char v20; // cl
  signed int v21; // eax
  Scaleform::Render::RenderBuffer *v22; // rcx
  Scaleform::Render::TreeText::Filter filtersBuf; // [rsp+40h] [rbp-C8h]

  v1 = this;
  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr)
    && !v1->pFilters.pObject )
  {
    v2 = (Scaleform::Render::TreeText *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v1->vfptr);
    v3 = &filtersBuf;
    v4 = 2;
    do
    {
      v3->Type = 0;
      Scaleform::Render::TreeText::Filter::InitByDefaultValues(v3);
      ++v3;
      --v4;
    }
    while ( v4 >= 0 );
    v5 = Scaleform::Render::TreeText::GetFilters(v2, &filtersBuf, 3ui64);
    if ( v5 )
    {
      v6 = (Scaleform::Render::FilterSet *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
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
      v9 = (Scaleform::Render::RenderBuffer *)v1->pFilters.pObject;
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
      v1->pFilters.pObject = v8;
      if ( v5 )
      {
        v10 = &filtersBuf.4;
        while ( 1 )
        {
          if ( LODWORD(v10[-1].DropShadow.Distance) == 1 )
          {
            v18 = (Scaleform::Render::ShadowFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       80i64);
            if ( v18 )
            {
              Scaleform::Render::ShadowFilter::ShadowFilter(
                v18,
                v10->DropShadow.Angle * 3.141592653589793 * 0.005555555555555556,
                v10->DropShadow.Distance,
                v10->Blur.BlurX,
                v10->DropShadow.BlurY,
                1u);
              v13 = v19;
            }
            else
            {
              v13 = 0i64;
            }
            *(float *)(v13 + 48) = v10->DropShadow.Strength * 0.0099999998;
            *(_DWORD *)(v13 + 52) = v10->DropShadow.Color;
            v20 = v10->DropShadow.Flags;
            v21 = 0;
            if ( v20 & 0x20 )
              v21 = 16;
            if ( v20 & 0x40 )
              v21 |= 0x40u;
            if ( v20 < 0 )
              v21 |= 0x80u;
            *(_DWORD *)(v13 + 24) = v21;
            Scaleform::Render::FilterSet::AddFilter(v1->pFilters.pObject, (Scaleform::Render::Filter *)v13);
            goto LABEL_40;
          }
          if ( LODWORD(v10[-1].DropShadow.Distance) == 2 )
            break;
          if ( LODWORD(v10[-1].DropShadow.Distance) == 3 )
          {
            v11 = (Scaleform::Render::GlowFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     80i64);
            if ( v11 )
            {
              Scaleform::Render::GlowFilter::GlowFilter(v11, v10->Blur.BlurX, v10->DropShadow.BlurY, 1u);
              v13 = v12;
            }
            else
            {
              v13 = 0i64;
            }
            *(float *)(v13 + 48) = v10->DropShadow.Strength * 0.0099999998;
            *(_DWORD *)(v13 + 52) = v10->DropShadow.Color;
            v14 = v10->DropShadow.Flags;
            v15 = 0;
            if ( v14 & 0x20 )
              v15 = 16;
            if ( v14 & 0x40 )
              v15 |= 0x40u;
            if ( v14 < 0 )
              v15 |= 0x80u;
            *(_DWORD *)(v13 + 24) = v15;
            Scaleform::Render::FilterSet::AddFilter(v1->pFilters.pObject, (Scaleform::Render::Filter *)v13);
            goto LABEL_40;
          }
LABEL_41:
          v10 = ($AD53D16137C3AE4177DAFEDA37259559 *)((char *)v10 + 32);
          if ( !--v5 )
            return v1->pFilters.pObject;
        }
        v16 = (Scaleform::Render::BlurFilter *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 80i64);
        if ( v16 )
        {
          Scaleform::Render::BlurFilter::BlurFilter(v16, v10->Blur.BlurX, v10->DropShadow.BlurY, 1u);
          v13 = v17;
        }
        else
        {
          v13 = 0i64;
        }
        *(float *)(v13 + 48) = v10->DropShadow.Strength * 0.0099999998;
        Scaleform::Render::FilterSet::AddFilter(v1->pFilters.pObject, (Scaleform::Render::Filter *)v13);
LABEL_40:
        Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v13);
        goto LABEL_41;
      }
    }
    else
    {
      v22 = (Scaleform::Render::RenderBuffer *)v1->pFilters.pObject;
      if ( v22 )
        Scaleform::RefCountImpl::Release(v22);
      v1->pFilters.pObject = 0i64;
    }
  }
  return v1->pFilters.pObject;
}

