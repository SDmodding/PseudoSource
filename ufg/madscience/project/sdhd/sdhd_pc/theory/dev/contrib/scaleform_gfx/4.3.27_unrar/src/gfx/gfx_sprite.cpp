// File Line: 79
// RVA: 0x89CCF0
void __fastcall Scaleform::GFx::Sprite::Sprite(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::TimelineDef *pdef,
        Scaleform::GFx::MovieDefImpl *pdefImpl,
        Scaleform::GFx::ASMovieRootBase *pr,
        Scaleform::GFx::InteractiveObject *pparent,
        _DWORD *id,
        bool loadedSeparately)
{
  int *pLib; // rax
  int v12; // xmm3_4
  int v13; // xmm2_4
  int v14; // xmm1_4
  __int128 *v15; // rax
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  char v19; // al
  bool v20; // di
  char v21; // al
  bool v22; // dl
  int v23[4]; // [rsp+40h] [rbp-48h] BYREF
  Scaleform::Render::Rect<float> rect; // [rsp+50h] [rbp-38h] BYREF
  __int128 v25; // [rsp+60h] [rbp-28h] BYREF

  LODWORD(id) = *id;
  Scaleform::GFx::DisplayObjContainer::DisplayObjContainer(
    this,
    pdefImpl,
    pr,
    pparent,
    (Scaleform::GFx::DisplayList *)&id);
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::Sprite::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::Sprite::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  if ( pdef )
    _InterlockedExchangeAdd(&pdef->RefCount.Value, 1u);
  this->pDef.pObject = pdef;
  *(_QWORD *)&this->PlayStatePriv = 0i64;
  this->pDrawingAPI.pObject = 0i64;
  this->pHitAreaHandle.pObject = 0i64;
  this->pHitAreaHolder = 0i64;
  *(_WORD *)&this->Flags = 0;
  this->MouseStatePriv = UP;
  this->pASRoot = pr;
  if ( (((__int64 (__fastcall *)(Scaleform::GFx::TimelineDef *))pdef->vfptr->GetResourceTypeCode)(pdef) & 0xFF00) == 33792 )
  {
    pLib = (int *)pdef[2].pLib;
    if ( pLib )
    {
      v12 = pLib[3];
      v13 = pLib[2];
      v14 = pLib[1];
      v23[0] = *pLib;
      v23[1] = v14;
      v23[2] = v13;
      v23[3] = v12;
      v15 = (__int128 *)v23;
    }
    else
    {
      v25 = 0i64;
      v15 = &v25;
    }
    v16 = *((float *)v15 + 3);
    v17 = *((float *)v15 + 2);
    v18 = *((float *)v15 + 1);
    rect.x1 = *(float *)v15;
    rect.y1 = v18;
    rect.x2 = v17;
    rect.y2 = v16;
    Scaleform::GFx::DisplayObjContainer::SetScale9Grid(this, &rect);
    this->Flags |= 0x40u;
  }
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x400u;
  v19 = this->Flags & 0xDC | 1;
  this->Flags = v19;
  v20 = loadedSeparately;
  if ( loadedSeparately )
    v21 = v19 | 0x10;
  else
    v21 = v19 & 0xEF;
  this->Flags = v21;
  if ( !pparent
    || v20
    || (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pparent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(pparent) == pdefImpl )
  {
    v22 = 0;
    if ( !v20 )
      return;
  }
  else
  {
    v22 = 1;
  }
  Scaleform::GFx::DisplayObjContainer::AssignRootNode(this, v22);
}

// File Line: 120
// RVA: 0x8A7A00
void __fastcall Scaleform::GFx::Sprite::~Sprite(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::CharacterHandle *pObject; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v4; // zf
  Scaleform::GFx::ASStringNode *v5; // rcx
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::GFx::DrawingContext *v7; // rcx
  Scaleform::GFx::TimelineDef *v8; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::Sprite::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::Sprite::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
  pObject = this->pHitAreaHandle.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      pNode = pObject->OriginalName.pNode;
      v4 = pNode->RefCount-- == 1;
      if ( v4 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v5 = pObject->NamePath.pNode;
      v4 = v5->RefCount-- == 1;
      if ( v4 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      v6 = pObject->Name.pNode;
      v4 = v6->RefCount-- == 1;
      if ( v4 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  v7 = this->pDrawingAPI.pObject;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v8 = this->pDef.pObject;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount.Value) )
  {
    pLib = v8->pLib;
    if ( pLib )
    {
      pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)v8);
      v8->pLib = 0i64;
    }
    v8->vfptr->__vecDelDtor(v8, 1u);
  }
  Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer(this);
}

// File Line: 134
// RVA: 0x908910
void __fastcall Scaleform::GFx::Sprite::SetLoadedSeparately(Scaleform::GFx::Sprite *this, bool v)
{
  char Flags; // al
  char v3; // al

  Flags = this->Flags;
  if ( v )
    v3 = Flags | 0x10;
  else
    v3 = Flags & 0xEF;
  this->Flags = v3;
  if ( v )
    Scaleform::GFx::DisplayObjContainer::AssignRootNode(this, 0);
}

// File Line: 146
// RVA: 0x90B170
void __fastcall Scaleform::GFx::Sprite::SetRootNodeLoadingStat(
        Scaleform::GFx::Sprite *this,
        unsigned int bytesLoaded,
        unsigned int loadingFrame)
{
  Scaleform::GFx::MovieDefRootNode *pRootNode; // rax
  Scaleform::GFx::MovieDefRootNode *v4; // rax

  pRootNode = this->pRootNode;
  if ( pRootNode )
  {
    pRootNode->BytesLoaded = bytesLoaded;
    v4 = this->pRootNode;
    if ( v4->ImportFlag )
      loadingFrame = 0;
    v4->LoadingFrame = loadingFrame;
  }
}

// File Line: 191
// RVA: 0x8CE430
void __fastcall Scaleform::GFx::Sprite::ForceShutdown(Scaleform::GFx::Sprite *this)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v3; // rax

  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v3 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 232i64))(v3);
  }
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this);
}

// File Line: 201
// RVA: 0x8E1100
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::Sprite::GetTopParent(
        Scaleform::GFx::Sprite *this,
        bool ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *pParent; // r8
  char Flags; // al

  pParent = this->pParent;
  if ( !pParent )
    return this;
  if ( !ignoreLockRoot )
  {
    Flags = this->Flags;
    if ( (Flags & 0x10) != 0 && (Flags & 0x20) != 0 )
      return this;
  }
  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0 )
    return (Scaleform::GFx::Sprite *)this->pASRoot->pMovieImpl->pMainMovie;
  return (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor)(this->pParent);
}

// File Line: 224
// RVA: 0x8D5970
__int64 __fastcall Scaleform::GFx::Sprite::GetBytesLoaded(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // rax
  Scaleform::GFx::MovieDefRootNode *pRootNode; // rcx

  while ( this )
  {
    v1 = 0i64;
    if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x200) != 0 )
      v1 = this;
    if ( v1 && v1->pRootNode )
    {
      pRootNode = v1->pRootNode;
      if ( pRootNode )
        return pRootNode->BytesLoaded;
      return 0i64;
    }
    this = (Scaleform::GFx::Sprite *)this->pParent;
  }
  return 0i64;
}

// File Line: 234
// RVA: 0x8DAC20
__int64 __fastcall Scaleform::GFx::Sprite::GetLoadingFrame(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::MovieDefRootNode *pRootNode; // rax

  pRootNode = this->pRootNode;
  if ( !pRootNode || pRootNode->ImportFlag )
    return ((__int64 (__fastcall *)(Scaleform::GFx::TimelineDef *))this->pDef.pObject->vfptr[2].GetResourceTypeCode)(this->pDef.pObject);
  else
    return pRootNode->LoadingFrame;
}

// File Line: 249
// RVA: 0x8D5210
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Sprite::GetBounds(
        Scaleform::GFx::Sprite *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::DrawingContext *pObject; // rcx
  float x2; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float x1; // xmm4_4
  float v11; // xmm0_4
  float y1; // xmm1_4
  float v13; // xmm0_4
  float y2; // xmm1_4
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // rax
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  Scaleform::Render::Rect<float> pr; // [rsp+30h] [rbp-20h] BYREF
  Scaleform::Render::Rect<float> pRect; // [rsp+40h] [rbp-10h] BYREF

  Scaleform::GFx::DisplayList::GetBounds(&this->mDisplayList, result, transform);
  pObject = this->pDrawingAPI.pObject;
  if ( pObject )
  {
    pRect = 0i64;
    Scaleform::GFx::DrawingContext::ComputeBound(pObject, &pRect);
    if ( pRect.x1 < pRect.x2 && pRect.y1 < pRect.y2 )
    {
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, &pr, &pRect);
      x2 = result->x2;
      if ( result->x1 >= x2 || (v8 = result->y1, v9 = result->y2, v8 >= v9) )
      {
        y1 = pr.y1;
        result->x1 = pr.x1;
        v13 = pr.x2;
        result->y1 = y1;
        y2 = pr.y2;
        result->x2 = v13;
        result->y2 = y2;
      }
      else
      {
        x1 = pr.x1;
        if ( result->x1 <= pr.x1 )
          x1 = result->x1;
        if ( x2 <= pr.x2 )
          x2 = pr.x2;
        v11 = pr.y1;
        if ( v8 <= pr.y1 )
          v11 = result->y1;
        if ( v9 <= pr.y2 )
          v9 = pr.y2;
        result->x1 = x1;
        result->y1 = v11;
        result->x2 = x2;
        result->y2 = v9;
      }
    }
  }
  pScrollRect = this->pScrollRect;
  if ( pScrollRect )
  {
    v16 = pScrollRect->Rectangle.y2;
    v17 = pScrollRect->Rectangle.y1;
    v18 = pScrollRect->Rectangle.x1;
    pRect.x2 = pScrollRect->Rectangle.x2;
    pRect.x1 = v18;
    pRect.y1 = v17;
    pRect.y2 = v16;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, &pr, &pRect);
    Scaleform::Render::Rect<float>::Intersect(result, pr.x1, pr.y1, pr.x2, pr.y2);
  }
  return result;
}

// File Line: 281
// RVA: 0x8DD480
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Sprite::GetRectBounds(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *t)
{
  Scaleform::GFx::DisplayList::GetRectBounds(&this->mDisplayList, result, t);
  return result;
}

// File Line: 286
// RVA: 0x8D8340
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Sprite::GetFocusRect(
        Scaleform::GFx::Sprite *this,
        Scaleform::Render::Rect<float> *result)
{
  __int64 v4; // rax
  __int64 v5; // rsi
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  Scaleform::Render::Rect<float> r; // [rsp+20h] [rbp-48h] BYREF
  __m128 v9; // [rsp+30h] [rbp-38h]
  Scaleform::Render::Matrix2x4<float> v10; // [rsp+40h] [rbp-28h] BYREF

  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[120].__vecDelDtor)(this);
  v5 = v4;
  *(_OWORD *)&v10.M[0][0] = _xmm;
  *(__m128 *)&v10.M[1][0] = _xmm;
  if ( v4 )
  {
    v10 = *(Scaleform::Render::Matrix2x4<float> *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 16i64))(v4);
    (*(void (__fastcall **)(__int64, Scaleform::Render::Rect<float> *))(*(_QWORD *)v5 + 744i64))(v5, &r);
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v10, result, &r);
  }
  else
  {
    vfptr = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    r = (Scaleform::Render::Rect<float>)_xmm;
    v9 = _xmm;
    ((void (__fastcall *)(Scaleform::GFx::Sprite *, Scaleform::Render::Rect<float> *, Scaleform::Render::Rect<float> *))vfptr[61].__vecDelDtor)(
      this,
      result,
      &r);
  }
  return result;
}

// File Line: 335
// RVA: 0x904600
void __fastcall Scaleform::GFx::Sprite::Restart(Scaleform::GFx::Sprite *this)
{
  char v2; // al
  char v3; // cl
  unsigned __int8 AvmObjOffset; // al
  __int64 v5; // rax

  Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(&this->mDisplayList, this, 0);
  v2 = this->Flags | 1;
  *(_QWORD *)&this->PlayStatePriv = 0i64;
  this->RollOverCnt = 0;
  v3 = v2;
  AvmObjOffset = this->AvmObjOffset;
  this->Flags = v3 & 0xFD;
  if ( AvmObjOffset )
  {
    v5 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v5 + 224i64))(v5, this->CurrentFrame);
  }
  Scaleform::GFx::Sprite::ExecuteFrameTags(this, this->CurrentFrame);
  Scaleform::GFx::DisplayList::UnloadMarkedObjects(&this->mDisplayList, this);
}

// File Line: 356
// RVA: 0x8E03D0
__int64 __fastcall Scaleform::GFx::Sprite::GetTopMostMouseEntity(
        Scaleform::GFx::Sprite *this,
        Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  unsigned int TopMostMouseEntity; // ebp
  Scaleform::GFx::InteractiveObject *v6; // rsi
  unsigned __int8 AvmObjOffset; // al
  __int64 v8; // rax
  unsigned __int8 v9; // al
  __int64 v10; // rax
  unsigned __int8 v11; // al
  __int64 v12; // rax
  Scaleform::GFx::DisplayObject *v14; // rax
  Scaleform::GFx::DisplayObject *v15; // rdx
  Scaleform::GFx::Sprite *pParent; // rcx
  Scaleform::GFx::InteractiveObject *pResult; // rax

  TopMostMouseEntity = Scaleform::GFx::DisplayObjContainer::GetTopMostMouseEntity(this, pt, pdescr);
  if ( TopMostMouseEntity != 3 || !this->pDrawingAPI.pObject )
    return TopMostMouseEntity;
  v6 = (Scaleform::GFx::InteractiveObject *)((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[121].__vecDelDtor)(this);
  if ( this->pASRoot->AVMVersion != 2 || !pdescr->TestAll )
  {
    AvmObjOffset = this->AvmObjOffset;
    if ( !AvmObjOffset
      || (v8 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                        + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset),
          !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v8 + 96i64))(v8)) )
    {
      if ( !v6 )
        return TopMostMouseEntity;
      if ( !pdescr->TestAll )
      {
        v9 = v6->AvmObjOffset;
        if ( !v9 )
          return TopMostMouseEntity;
        v10 = ((__int64 (__fastcall *)(__int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                        + 4 * v9))[1].__vecDelDtor)((__int64)v6 + 4 * v9);
        if ( !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v10 + 96i64))(v10) )
          return TopMostMouseEntity;
      }
    }
  }
  if ( !Scaleform::GFx::DrawingContext::DefPointTestLocal(this->pDrawingAPI.pObject, &pdescr->LocalPt, 1, this) )
    return TopMostMouseEntity;
  if ( v6 )
  {
    if ( pdescr->TestAll
      || (v11 = v6->AvmObjOffset) != 0
      && (v12 = ((__int64 (__fastcall *)(__int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                          + 4 * v11))[1].__vecDelDtor)((__int64)v6 + 4 * v11),
          (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v12 + 96i64))(v12)) )
    {
      pdescr->pResult = v6;
      pdescr->pHitArea = this;
      return 1i64;
    }
  }
  v14 = (Scaleform::GFx::DisplayObject *)((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[120].__vecDelDtor)(this);
  v15 = v14;
  if ( this->pASRoot->AVMVersion == 1 )
  {
    if ( v14 )
    {
      pParent = (Scaleform::GFx::Sprite *)v14;
      while ( 1 )
      {
        pParent = (Scaleform::GFx::Sprite *)pParent->pParent;
        if ( !pParent )
          goto LABEL_24;
        if ( pParent == this )
        {
          if ( v14 != pdescr->pHitArea )
            goto LABEL_24;
          break;
        }
      }
    }
LABEL_23:
    pdescr->pResult = this;
    return 1i64;
  }
  if ( !v14 )
    goto LABEL_23;
  pResult = pdescr->pResult;
  if ( pdescr->pResult )
  {
    if ( pResult != this
      && SLOBYTE(pResult->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
    {
      return TopMostMouseEntity;
    }
  }
  if ( v15 != pdescr->pHitArea )
  {
LABEL_24:
    pdescr->pResult = 0i64;
    return 2i64;
  }
  pdescr->pResult = this;
  return 1i64;
}

// File Line: 964
// RVA: 0x8E3610
void __fastcall Scaleform::GFx::Sprite::IncrementFrameAndCheckForLoop(Scaleform::GFx::Sprite *this)
{
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  unsigned int v3; // edi
  unsigned int v4; // eax

  vfptr = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
  ++this->CurrentFrame;
  v3 = ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))vfptr[111].__vecDelDtor)(this);
  v4 = this->pDef.pObject->vfptr[2].GetResourceTypeCode(this->pDef.pObject);
  if ( v3 >= v4 || this->CurrentFrame < v3 )
  {
    if ( this->CurrentFrame >= v4 )
    {
      this->Flags |= 2u;
      this->CurrentFrame = 0;
      if ( v4 <= 1 )
        this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[114].__vecDelDtor(
          this,
          1u);
      else
        Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(&this->mDisplayList, this, 0);
    }
  }
  else if ( v3 )
  {
    this->CurrentFrame = v3 - 1;
  }
  else
  {
    this->CurrentFrame = 0;
  }
}

// File Line: 994
// RVA: 0x8B5940
void __fastcall Scaleform::GFx::Sprite::AdvanceFrame(Scaleform::GFx::Sprite *this, bool nextFrame, float framePos)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v6; // rax

  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0xC) == 0
    && (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) == 0
    && this->Depth >= -1 )
  {
    ++this->RefCount;
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v6 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
      (*(void (__fastcall **)(__int64, bool))(*(_QWORD *)v6 + 200i64))(v6, nextFrame);
    }
    Scaleform::RefCountNTSImpl::Release(this);
  }
}

// File Line: 1025
// RVA: 0x8CA7D0
void __fastcall Scaleform::GFx::Sprite::ExecuteFrame0Events(Scaleform::GFx::Sprite *this)
{
  char Flags; // al
  unsigned __int8 AvmObjOffset; // al
  __int64 v4; // rax
  unsigned __int8 v5; // al
  __int64 v6; // rax

  Flags = this->Flags;
  if ( (Flags & 8) == 0 )
  {
    this->Flags = Flags | 8;
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v4 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
      (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 224i64))(v4, 0i64);
    }
    Scaleform::GFx::Sprite::ExecuteFrameTags(this, 0);
    v5 = this->AvmObjOffset;
    if ( v5 )
    {
      v6 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * v5))[2].__vecDelDtor)((char *)this + 4 * v5);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 208i64))(v6);
    }
  }
}

// File Line: 1052
// RVA: 0x8CA850
void __fastcall Scaleform::GFx::Sprite::ExecuteFrameTags(Scaleform::GFx::Sprite *this, unsigned int frame)
{
  __int64 i; // rdi
  unsigned __int8 AvmObjOffset; // al
  __int64 v6; // rax
  __int64 v7; // [rsp+28h] [rbp-20h] BYREF
  unsigned int v8; // [rsp+30h] [rbp-18h]

  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x800) != 0
    || !frame )
  {
    ++this->RefCount;
    if ( frame < ((unsigned int (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[111].__vecDelDtor)(this) )
    {
      ((void (__fastcall *)(Scaleform::GFx::TimelineDef *, __int64 *, _QWORD))this->pDef.pObject->vfptr[2].GetResourceReport)(
        this->pDef.pObject,
        &v7,
        frame);
      for ( i = 0i64; (unsigned int)i < v8; i = (unsigned int)(i + 1) )
        (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Sprite *, __int64))(**(_QWORD **)(v7 + 8 * i) + 16i64))(
          *(_QWORD *)(v7 + 8 * i),
          this,
          4i64);
      AvmObjOffset = this->AvmObjOffset;
      if ( AvmObjOffset )
      {
        v6 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                      + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v6 + 216i64))(v6, frame);
      }
    }
    Scaleform::RefCountNTSImpl::Release(this);
  }
}

// File Line: 1086
// RVA: 0x8CA910
void __fastcall Scaleform::GFx::Sprite::ExecuteImportedInitActions(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::MovieDef *psourceMovie)
{
  _QWORD *v4; // r12
  unsigned __int64 v5; // r15
  _RTL_CRITICAL_SECTION *v6; // rdi
  _RTL_CRITICAL_SECTION *v7; // rbx
  unsigned __int64 SpinCount; // rdi
  __int64 i; // rsi
  unsigned int *v10; // rbx
  __int64 v11; // rbp
  unsigned __int64 v12; // rdi
  __int64 v13; // rdi
  __int64 v14; // [rsp+28h] [rbp-50h] BYREF
  unsigned int v15; // [rsp+30h] [rbp-48h]
  unsigned __int64 v16; // [rsp+88h] [rbp+10h]

  v4 = *(_QWORD **)(*(_QWORD *)&psourceMovie[3].RefCount.Value + 24i64);
  v5 = 0i64;
  v6 = (_RTL_CRITICAL_SECTION *)v4[8];
  v7 = v6 + 10;
  EnterCriticalSection(v6 + 10);
  SpinCount = v6[11].SpinCount;
  LeaveCriticalSection(v7);
  v16 = (unsigned int)SpinCount;
  if ( (_DWORD)SpinCount )
  {
    do
    {
      v14 = 0i64;
      v15 = 0;
      if ( (*(unsigned __int8 (__fastcall **)(_QWORD *, __int64 *, _QWORD))(*v4 + 96i64))(v4, &v14, (unsigned int)v5) )
      {
        for ( i = 0i64; (unsigned int)i < v15; i = (unsigned int)(i + 1) )
        {
          v10 = *(unsigned int **)(v14 + 8 * i);
          if ( (*(unsigned __int8 (__fastcall **)(unsigned int *))(*(_QWORD *)v10 + 40i64))(v10) )
          {
            v11 = *(_QWORD *)&psourceMovie[3].RefCount.Value;
            v12 = v10[2];
            EnterCriticalSection((LPCRITICAL_SECTION)(v11 + 152));
            if ( v12 < *(_QWORD *)(v11 + 136) )
            {
              v13 = *(_QWORD *)(*(_QWORD *)(v11 + 128) + 8i64 * (unsigned int)v12);
              LeaveCriticalSection((LPCRITICAL_SECTION)(v11 + 152));
              if ( v13
                && *(int *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 104) + 24i64) + 64i64) + 488i64) > 0
                && v13 != ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(this) )
              {
                this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[119].__vecDelDtor(
                  this,
                  v13);
              }
            }
            else
            {
              LeaveCriticalSection((LPCRITICAL_SECTION)(v11 + 152));
            }
          }
          else
          {
            (*(void (__fastcall **)(unsigned int *, Scaleform::GFx::Sprite *, _QWORD))(*(_QWORD *)v10 + 16i64))(
              v10,
              this,
              0i64);
          }
        }
      }
      ++v5;
    }
    while ( v5 < v16 );
  }
}

// File Line: 1125
// RVA: 0x8E21E0
void __fastcall Scaleform::GFx::Sprite::GotoFrame(Scaleform::GFx::Sprite *this, signed int targetFrameNumber)
{
  unsigned __int16 Flags; // cx
  unsigned int v5; // edi
  unsigned int CurrentFrame; // eax
  unsigned int v7; // r8d
  Scaleform::MemoryHeap *v8; // rax
  unsigned __int8 v9; // al
  __int64 v10; // rax
  Scaleform::MemoryHeap *pHeap; // rax
  unsigned int i; // esi
  char *v13; // rcx
  __int64 v14; // rax
  unsigned __int8 AvmObjOffset; // al
  __int64 v16; // rax
  Scaleform::GFx::TimelineSnapshot v17; // [rsp+18h] [rbp-29h] BYREF
  Scaleform::ArrayDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2,Scaleform::ArrayDefaultPolicy> *p_SnapshotSortedArray; // [rsp+A8h] [rbp+67h]
  Scaleform::ArrayDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2,Scaleform::ArrayDefaultPolicy> *retaddr; // [rsp+B8h] [rbp+77h]

  Flags = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
  if ( (Flags & 0x800) != 0 && (Flags & 0x1000) == 0 && this->Depth >= -1 )
  {
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[111].__vecDelDtor)(this)
       - 1;
    if ( targetFrameNumber < (int)v5 )
      v5 = targetFrameNumber;
    if ( (v5 & 0x80000000) != 0 )
      v5 = 0;
    CurrentFrame = this->CurrentFrame;
    if ( v5 >= CurrentFrame )
    {
      if ( v5 > CurrentFrame )
      {
        if ( v5 <= 1 || v5 <= CurrentFrame + 1 )
        {
          this->CurrentFrame = v5;
        }
        else
        {
          pHeap = this->pASRoot->pMovieImpl->pHeap;
          *(_OWORD *)&v17.SnapshotHeap.FirstPage = 0i64;
          v17.SnapshotHeap.NumElementsInPage = 50;
          v17.SnapshotHeap.FirstEmptySlot = 0i64;
          v17.SnapshotHeap.pHeapOrPtr = pHeap;
          p_SnapshotSortedArray = &v17.SnapshotSortedArray;
          retaddr = &v17.SnapshotSortedArray;
          memset(&v17.SnapshotSortedArray, 0, 24);
          v17.SnapshotSortedArray.Data.pHeap = pHeap;
          v17.SnapshotList.Root.pPrev = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&v17.SnapshotList;
          v17.SnapshotList.Root.pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&v17.SnapshotList;
          v17.pOwnerSprite = this;
          v17.Direction = Direction_Forward;
          Scaleform::GFx::TimelineSnapshot::MakeSnapshot(&v17, this->pDef.pObject, this->CurrentFrame + 1, v5 - 1);
          if ( this->AvmObjOffset )
          {
            for ( i = this->CurrentFrame + 1; i < v5; ++i )
            {
              v13 = (char *)this + 4 * (unsigned __int8)this->AvmObjOffset;
              v14 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v13 + 16i64))(v13);
              (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v14 + 224i64))(v14, i);
            }
          }
          this->CurrentFrame = v5;
          Scaleform::GFx::TimelineSnapshot::ExecuteSnapshot(&v17, this);
          Scaleform::GFx::TimelineSnapshot::~TimelineSnapshot(&v17);
        }
        AvmObjOffset = this->AvmObjOffset;
        if ( AvmObjOffset )
        {
          v16 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                         + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
          (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v16 + 224i64))(v16, v5);
        }
        Scaleform::GFx::Sprite::ExecuteFrameTags(this, v5);
      }
    }
    else
    {
      v7 = v5 - 1;
      if ( !v5 )
        v7 = 0;
      Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(&this->mDisplayList, this, v7);
      if ( v5 )
      {
        v8 = (Scaleform::MemoryHeap *)((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))this->pASRoot->pMovieImpl->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::vfptr[48].__vecDelDtor)(this->pASRoot->pMovieImpl);
        *(_OWORD *)&v17.SnapshotHeap.FirstPage = 0i64;
        v17.SnapshotHeap.NumElementsInPage = 50;
        v17.SnapshotHeap.FirstEmptySlot = 0i64;
        v17.SnapshotHeap.pHeapOrPtr = v8;
        p_SnapshotSortedArray = &v17.SnapshotSortedArray;
        retaddr = &v17.SnapshotSortedArray;
        memset(&v17.SnapshotSortedArray, 0, 24);
        v17.SnapshotSortedArray.Data.pHeap = v8;
        v17.SnapshotList.Root.pPrev = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&v17.SnapshotList;
        v17.SnapshotList.Root.pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&v17.SnapshotList;
        v17.pOwnerSprite = this;
        v17.Direction = Direction_Backward;
        Scaleform::GFx::TimelineSnapshot::MakeSnapshot(&v17, this->pDef.pObject, 0, v5 - 1);
        this->CurrentFrame = v5;
        Scaleform::GFx::TimelineSnapshot::ExecuteSnapshot(&v17, this);
        Scaleform::GFx::TimelineSnapshot::~TimelineSnapshot(&v17);
      }
      else
      {
        this->CurrentFrame = 0;
      }
      v9 = this->AvmObjOffset;
      if ( v9 )
      {
        v10 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                       + 4 * v9))[2].__vecDelDtor)((char *)this + 4 * v9);
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v10 + 224i64))(v10, v5);
      }
      Scaleform::GFx::Sprite::ExecuteFrameTags(this, v5);
      Scaleform::GFx::DisplayList::UnloadMarkedObjects(&this->mDisplayList, this);
    }
    this->PlayStatePriv = State_Paused;
  }
}

// File Line: 1262
// RVA: 0x8E2580
char __fastcall Scaleform::GFx::Sprite::GotoLabeledFrame(Scaleform::GFx::Sprite *this, const char *label, int offset)
{
  Scaleform::GFx::TimelineDef *pObject; // rcx
  int v8; // [rsp+30h] [rbp+8h] BYREF

  pObject = this->pDef.pObject;
  v8 = -1;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::TimelineDef *, const char *, int *, _QWORD))pObject->vfptr[3].GetKey)(
         pObject,
         label,
         &v8,
         0i64) )
  {
    this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[110].__vecDelDtor(
      this,
      v8 + offset);
    return 1;
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogWarning(
      &this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
      "MovieImpl::GotoLabeledFrame(%s) unknown label",
      label);
    return 0;
  }
}

// File Line: 1277
// RVA: 0x909D00
void __fastcall Scaleform::GFx::Sprite::SetPlayState(Scaleform::GFx::Sprite *this, Scaleform::GFx::PlayState s)
{
  unsigned __int16 Flags; // ax

  Flags = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
  this->PlayStatePriv = s;
  if ( (Flags & 0x1000) == 0 && this->Depth >= -1 && (Flags & 0x10) == 0 )
    Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>(this);
}

// File Line: 1290
// RVA: 0x8BD130
void __fastcall Scaleform::GFx::Sprite::CloneInternalData(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::InteractiveObject *src)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rdx
  unsigned __int8 AvmObjOffset; // al
  __int64 v6; // rax
  unsigned __int8 v7; // al
  __int64 v8; // rax

  pGeomData = src->pGeomData;
  if ( pGeomData )
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, pGeomData);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v6 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v6 + 112i64))(v6, src);
  }
  v7 = this->AvmObjOffset;
  if ( v7 )
  {
    v8 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * v7))[2].__vecDelDtor)((char *)this + 4 * v7);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v8 + 112i64))(v8, src);
  }
}

// File Line: 1317
// RVA: 0x8BA610
__int64 __fastcall Scaleform::GFx::Sprite::CheckAdvanceStatus(Scaleform::GFx::Sprite *this, bool playingNow)
{
  unsigned int v2; // ebx
  char v5; // si
  unsigned __int8 AvmObjOffset; // al
  __int64 v7; // rax
  unsigned __int8 v9; // al
  __int64 v10; // rax

  v2 = 0;
  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0xC) != 0
    || (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x40) != 0 )
  {
    v5 = 1;
  }
  else
  {
    v5 = 0;
    if ( !((unsigned int (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[115].__vecDelDtor)(this) )
    {
      LOBYTE(v2) = !playingNow;
      return v2;
    }
  }
  if ( playingNow )
  {
    if ( v5 )
      return 0xFFFFFFFFi64;
    AvmObjOffset = this->AvmObjOffset;
    if ( !AvmObjOffset )
      return 0xFFFFFFFFi64;
    v7 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    if ( !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v7 + 256i64))(v7) )
      return 0xFFFFFFFFi64;
  }
  else if ( !v5 )
  {
    v9 = this->AvmObjOffset;
    if ( v9 )
    {
      v10 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                     + 4 * v9))[2].__vecDelDtor)((char *)this + 4 * v9);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v10 + 256i64))(v10) )
        return 1;
    }
  }
  return v2;
}

// File Line: 1402
// RVA: 0x8B0710
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::Sprite::AddDisplayObject(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::CharPosInfo *pos,
        Scaleform::GFx::ASString *name,
        Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *peventHandlers)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v8; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0i64;
  v8 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  return (Scaleform::GFx::DisplayObjectBase *)(*(__int64 (__fastcall **)(__int64, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASString *, Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *))(*(_QWORD *)v8 + 192i64))(
                                                v8,
                                                pos,
                                                name,
                                                peventHandlers);
}

// File Line: 1409
// RVA: 0x8BE7B0
void __fastcall Scaleform::GFx::Sprite::CreateAndReplaceDisplayObject(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::CharPosInfo *pos,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::DisplayObjectBase **newChar)
{
  if ( newChar )
    *newChar = 0i64;
  Scaleform::GFx::DisplayObjContainer::CreateAndReplaceDisplayObject(this, pos, name, newChar);
  if ( newChar )
  {
    if ( *newChar )
      (*newChar)->CreateFrame = this->CurrentFrame;
  }
}

// File Line: 1434
// RVA: 0x8EC690
bool __fastcall Scaleform::GFx::Sprite::OnEvent(Scaleform::GFx::Sprite *this, Scaleform::GFx::EventId *id)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v4; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0;
  v4 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  return (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v4 + 64i64))(v4, id);
}

// File Line: 1442
// RVA: 0x8EE740
bool __fastcall Scaleform::GFx::Sprite::OnMouseEvent(Scaleform::GFx::Sprite *this, Scaleform::GFx::EventId *id)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v5; // rax
  unsigned __int8 v6; // al
  __int64 v7; // rax
  Scaleform::GFx::InteractiveObject *pParent; // rcx

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v5 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 248i64))(v5) )
      return 0;
  }
  v6 = this->AvmObjOffset;
  if ( v6 )
  {
    v7 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * v6))[2].__vecDelDtor)((char *)this + 4 * v6);
    if ( (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v7 + 64i64))(v7, id) )
      return 0;
  }
  pParent = this->pParent;
  if ( !pParent )
    return 0;
  else
    return (bool)pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
                   pParent,
                   (unsigned int)id);
}

// File Line: 1463
// RVA: 0x8ECA50
void __fastcall Scaleform::GFx::Sprite::OnEventUnload(Scaleform::GFx::Sprite *this)
{
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x1000u;
  if ( this->pHitAreaHandle.pObject )
    Scaleform::GFx::Sprite::SetHitArea(this, 0i64);
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
  Scaleform::GFx::InteractiveObject::OnEventUnload(this);
}

// File Line: 1482
// RVA: 0x8EEAB0
bool __fastcall Scaleform::GFx::Sprite::OnUnloading(Scaleform::GFx::Sprite *this)
{
  bool result; // al
  unsigned __int8 AvmObjOffset; // cl

  result = Scaleform::GFx::DisplayList::UnloadAll(&this->mDisplayList, this);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    return (bool)(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                         + 4 * AvmObjOffset))[11].__vecDelDtor(
                   (char *)this + 4 * AvmObjOffset,
                   result);
  return result;
}

// File Line: 1493
// RVA: 0x8EDC10
__int64 __fastcall Scaleform::GFx::Sprite::OnKeyEvent(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  __int64 result; // rax
  __int64 v7; // rax
  __int64 v8; // rax
  unsigned __int8 v9; // bp
  int v10; // eax
  __int16 v11; // r14
  __int64 v12; // rax
  Scaleform::GFx::MovieImpl *pMovieImpl; // rsi
  unsigned int KeyCode; // eax
  int v15; // eax
  unsigned int WcharCode; // eax
  char *v17; // rcx
  __int64 v18; // rax
  __int64 AvmObjOffset; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // [rsp+20h] [rbp-28h] BYREF
  unsigned int v23; // [rsp+28h] [rbp-20h]
  unsigned int TouchID; // [rsp+2Ch] [rbp-1Ch]
  int v25; // [rsp+30h] [rbp-18h]

  result = (unsigned __int8)this->AvmObjOffset;
  if ( (_BYTE)result )
  {
    v7 = *(__int64 *)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                    + 4 * (unsigned __int8)result);
    if ( id->Id == 64 )
    {
      v8 = (*(__int64 (**)(void))(v7 + 16))();
      v9 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v8 + 64i64))(v8, id);
      if ( (*pkeyMask & 0x10000) == 0 )
      {
        v10 = Scaleform::GFx::EventId::ConvertToButtonKeyCode(id);
        v11 = v10;
        if ( v10 )
        {
          v12 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                         + 4
                                                                                         * (unsigned __int8)this->AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * (unsigned __int8)this->AvmObjOffset);
          v22 = 0x20000i64;
          v23 = v11;
          LOBYTE(TouchID) = 0;
          v25 = 0;
          v9 = (*(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v12 + 64i64))(v12, &v22);
          if ( v9 )
            *pkeyMask |= 0x10000u;
        }
      }
      pMovieImpl = this->pASRoot->pMovieImpl;
      if ( Scaleform::GFx::MovieImpl::IsKeyboardFocused(pMovieImpl, this, id->ControllerIndex) )
      {
        KeyCode = id->KeyCode;
        if ( KeyCode == 13 || KeyCode == 32 )
        {
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[88].__vecDelDtor)(this) )
            goto LABEL_14;
          v15 = (pMovieImpl->Flags >> 26) & 3;
          if ( v15 == 3 )
            v15 = -1;
          if ( v15 == 1 )
          {
LABEL_14:
            LODWORD(v22) = id->Id;
            WcharCode = id->WcharCode;
            LODWORD(v22) = 1024;
            HIDWORD(v22) = WcharCode;
            v23 = id->KeyCode;
            TouchID = id->TouchID;
            v25 = *(_DWORD *)&id->RollOverCnt;
            v17 = (char *)this + 4 * (unsigned __int8)this->AvmObjOffset;
            v18 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v17 + 16i64))(v17);
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v18 + 64i64))(v18, &v22);
            AvmObjOffset = (unsigned __int8)this->AvmObjOffset;
            LODWORD(v22) = 2048;
            v20 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                           + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v20 + 64i64))(v20, &v22);
          }
        }
      }
      return v9;
    }
    else
    {
      v21 = (*(__int64 (**)(void))(v7 + 16))();
      return (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v21 + 64i64))(v21, id);
    }
  }
  return result;
}

// File Line: 1536
// RVA: 0x8C5160
void __fastcall Scaleform::GFx::Sprite::DefaultOnEventLoad(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite::ExecuteFrameTags(this, 0);
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x20u;
}

// File Line: 1544
// RVA: 0x8ECAC0
void __fastcall Scaleform::GFx::Sprite::OnEventXmlsocketOnxml(Scaleform::GFx::Sprite *this)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v2; // rax
  __int64 v3; // [rsp+20h] [rbp-28h] BYREF
  int v4; // [rsp+28h] [rbp-20h]
  char v5; // [rsp+2Ch] [rbp-1Ch]
  int v6; // [rsp+30h] [rbp-18h]

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v3 = 16777223i64;
    v4 = 0;
    v5 = 0;
    v6 = 65280;
    v2 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v2 + 64i64))(v2, &v3);
  }
}

// File Line: 1559
// RVA: 0x8EC850
void __fastcall Scaleform::GFx::Sprite::OnEventLoadProgress(Scaleform::GFx::Sprite *this)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v2; // rax
  __int64 v3; // [rsp+20h] [rbp-28h] BYREF
  int v4; // [rsp+28h] [rbp-20h]
  char v5; // [rsp+2Ch] [rbp-1Ch]
  int v6; // [rsp+30h] [rbp-18h]

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v3 = 16777218i64;
    v4 = 0;
    v5 = 0;
    v6 = 65280;
    v2 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v2 + 64i64))(v2, &v3);
  }
}

// File Line: 1566
// RVA: 0x8F0750
bool __fastcall Scaleform::GFx::Sprite::PointTestLocal(
        Scaleform::GFx::Sprite *this,
        Scaleform::Render::Point<float> *pt,
        unsigned __int8 hitTestMask)
{
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  float *v7; // rax
  float y; // xmm0_4
  bool result; // al
  Scaleform::GFx::DrawingContext *pObject; // rcx
  char v11[16]; // [rsp+20h] [rbp-38h] BYREF
  __int128 v12[2]; // [rsp+30h] [rbp-28h] BYREF

  result = 0;
  if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 0x800) == 0 )
  {
    if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 1) != 0
      || (vfptr = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr,
          v12[0] = _xmm,
          v12[1] = (__int128)_xmm,
          v7 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::Sprite *, char *, __int128 *))vfptr[61].__vecDelDtor)(
                          this,
                          v11,
                          v12),
          pt->x <= v7[2])
      && pt->x >= *v7
      && (y = pt->y, y <= v7[3])
      && y >= v7[1] )
    {
      if ( (hitTestMask & 2) == 0
        || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this) )
      {
        if ( Scaleform::GFx::DisplayObjContainer::PointTestLocal(this, pt, hitTestMask) )
          return 1;
        pObject = this->pDrawingAPI.pObject;
        if ( pObject )
        {
          if ( Scaleform::GFx::DrawingContext::DefPointTestLocal(pObject, pt, hitTestMask & 1, this) )
            return 1;
        }
      }
    }
  }
  return result;
}

// File Line: 1588
// RVA: 0x8ED170
void __fastcall Scaleform::GFx::Sprite::OnGettingKeyboardFocus(
        Scaleform::GFx::Sprite *this,
        char controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v6; // rax
  unsigned int v7; // eax
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v9; // [rsp+20h] [rbp-28h] BYREF
  int v10; // [rsp+28h] [rbp-20h]
  char v11; // [rsp+2Ch] [rbp-1Ch]
  char v12; // [rsp+30h] [rbp-18h]
  char v13; // [rsp+31h] [rbp-17h]
  __int16 v14; // [rsp+32h] [rbp-16h]

  if ( fmt == GFx_FocusMovedByKeyboard )
  {
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v6 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v6 + 96i64))(v6) )
      {
        v7 = (this->pASRoot->pMovieImpl->Flags >> 28) & 3;
        if ( v7 == 3 )
          v7 = -1;
        if ( v7 != 1 )
        {
          v10 = 0;
          v11 = 0;
          v12 = 0;
          v14 = 0;
          vfptr = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
          v9 = 0x2000i64;
          v13 = controllerIdx;
          vfptr[100].__vecDelDtor(this, (unsigned int)&v9);
        }
      }
    }
  }
}

// File Line: 1596
// RVA: 0x8EE120
char __fastcall Scaleform::GFx::Sprite::OnLosingKeyboardFocus(
        Scaleform::GFx::Sprite *this,
        Scaleform::GFx::InteractiveObject *__formal,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  __int64 v4; // rdi
  unsigned __int8 AvmObjOffset; // al
  void *v7; // rax
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  int v9; // eax
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v12; // [rsp+20h] [rbp-28h] BYREF
  int v13; // [rsp+28h] [rbp-20h]
  char v14; // [rsp+2Ch] [rbp-1Ch]
  char v15; // [rsp+30h] [rbp-18h]
  char v16; // [rsp+31h] [rbp-17h]
  __int16 v17; // [rsp+32h] [rbp-16h]

  v4 = controllerIdx;
  if ( fmt == GFx_FocusMovedByKeyboard )
  {
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v7 = (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                   + 4 * AvmObjOffset))[1].__vecDelDtor(
             (char *)this + 4 * AvmObjOffset,
             __formal);
      if ( (*(unsigned __int8 (__fastcall **)(void *))(*(_QWORD *)v7 + 96i64))(v7) )
      {
        pMovieImpl = this->pASRoot->pMovieImpl;
        if ( pMovieImpl->FocusGroups[(unsigned __int8)pMovieImpl->FocusGroupIndexes[v4]].FocusRectShown )
        {
          v9 = (pMovieImpl->Flags >> 28) & 3;
          if ( v9 == 3 )
            v9 = -1;
          if ( v9 != 1 )
          {
            v13 = 0;
            v14 = 0;
            v15 = 0;
            v17 = 0;
            vfptr = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
            v12 = 0x4000i64;
            v16 = v4;
            vfptr[100].__vecDelDtor(this, (unsigned int)&v12);
          }
        }
      }
    }
  }
  return 1;
}

// File Line: 1606
// RVA: 0x8F4790
void __fastcall Scaleform::GFx::Sprite::PropagateNoAdvanceGlobalFlag(Scaleform::GFx::Sprite *this)
{
  unsigned __int64 Size; // rsi
  bool v3; // bp
  __int64 v4; // rdi
  Scaleform::GFx::InteractiveObject *pCharacter; // rbx
  __int64 v6; // rdx
  unsigned int Flags; // ecx
  int v8; // eax

  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  v3 = (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 8) != 0;
  if ( Size )
  {
    v4 = 0i64;
    do
    {
      pCharacter = 0i64;
      if ( SLOBYTE(this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter->Flags) < 0 )
        pCharacter = (Scaleform::GFx::InteractiveObject *)this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter;
      if ( pCharacter )
      {
        if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 8) != 0 || v3 )
          pCharacter->Flags |= 8u;
        else
          pCharacter->Flags &= ~8u;
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))pCharacter->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[104].__vecDelDtor)(pCharacter);
        Flags = pCharacter->Flags;
        if ( (Flags & 0x200000) == 0 || (Flags & 0x400000) != 0 )
          v6 = 0i64;
        else
          LOBYTE(v6) = 1;
        v8 = (int)pCharacter->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
                    pCharacter,
                    v6);
        if ( v8 == -1 )
        {
          pCharacter->Flags |= 0x400000u;
        }
        else if ( v8 == 1 )
        {
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(pCharacter);
        }
      }
      ++v4;
      --Size;
    }
    while ( Size );
  }
}

// File Line: 1621
// RVA: 0x8F49D0
void __fastcall Scaleform::GFx::Sprite::PropagateNoAdvanceLocalFlag(Scaleform::GFx::Sprite *this)
{
  unsigned __int64 Size; // rsi
  bool v3; // bp
  __int64 v4; // rdi
  Scaleform::GFx::InteractiveObject *pCharacter; // rbx
  __int64 v6; // rdx
  unsigned int Flags; // ecx
  int v8; // eax

  Size = this->mDisplayList.DisplayObjectArray.Data.Size;
  v3 = (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 4) != 0;
  if ( Size )
  {
    v4 = 0i64;
    do
    {
      pCharacter = 0i64;
      if ( SLOBYTE(this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter->Flags) < 0 )
        pCharacter = (Scaleform::GFx::InteractiveObject *)this->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter;
      if ( pCharacter )
      {
        if ( (this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags & 4) != 0 || v3 )
          pCharacter->Flags |= 4u;
        else
          pCharacter->Flags &= ~4u;
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))pCharacter->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[105].__vecDelDtor)(pCharacter);
        Flags = pCharacter->Flags;
        if ( (Flags & 0x200000) == 0 || (Flags & 0x400000) != 0 )
          v6 = 0i64;
        else
          LOBYTE(v6) = 1;
        v8 = (int)pCharacter->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
                    pCharacter,
                    v6);
        if ( v8 == -1 )
        {
          pCharacter->Flags |= 0x400000u;
        }
        else if ( v8 == 1 )
        {
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(pCharacter);
        }
      }
      ++v4;
      --Size;
    }
    while ( Size );
  }
}

// File Line: 1636
// RVA: 0x90F170
void __fastcall Scaleform::GFx::Sprite::SetVisible(Scaleform::GFx::Sprite *this, bool visible)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  char v4; // dl
  unsigned int Flags; // ecx
  unsigned int v6; // ecx
  Scaleform::Render::TreeNode *RenderNode; // rax
  bool v8; // dl
  int v9; // eax

  if ( visible )
  {
    this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x4000u;
    pObject = this->pRenNode.pObject;
    if ( pObject )
      Scaleform::Render::TreeNode::SetVisible(pObject, visible);
    goto LABEL_4;
  }
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags &= ~0x4000u;
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::SetVisible(RenderNode, 0);
  if ( (this->pASRoot->pMovieImpl->Flags & 0x800) == 0 )
  {
LABEL_4:
    v4 = 0;
    goto LABEL_5;
  }
  v4 = 1;
LABEL_5:
  Flags = this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags;
  if ( v4 == ((Flags & 8) != 0) )
    return;
  if ( v4 )
    v6 = Flags | 8;
  else
    v6 = Flags & 0xFFFFFFF7;
  this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags = v6;
  v8 = (v6 & 0x200000) != 0 && (v6 & 0x400000) == 0;
  v9 = Scaleform::GFx::Sprite::CheckAdvanceStatus(this, v8);
  if ( v9 == -1 )
  {
    this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Flags |= 0x400000u;
  }
  else if ( v9 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
    ((void (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[104].__vecDelDtor)(this);
    return;
  }
  ((void (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[104].__vecDelDtor)(this);
}

// File Line: 1652
// RVA: 0x8D7150
Scaleform::GFx::DrawingContext *__fastcall Scaleform::GFx::Sprite::GetDrawingContext(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::DisplayObject *pMaskCharacter; // rdi
  Scaleform::GFx::DrawingContext *DrawingContext; // rsi
  Scaleform::GFx::DrawingContext *pObject; // rcx
  Scaleform::Render::TreeContainer *v5; // rax

  if ( this->pDrawingAPI.pObject )
    return this->pDrawingAPI.pObject;
  if ( !this->pMaskCharacter
    || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this) )
  {
    pMaskCharacter = 0i64;
  }
  else
  {
    pMaskCharacter = this->pMaskCharacter;
    if ( pMaskCharacter )
      ++pMaskCharacter->RefCount;
  }
  if ( pMaskCharacter )
    Scaleform::GFx::DisplayObject::SetMask(this, 0i64, 1);
  DrawingContext = Scaleform::GFx::MovieImpl::CreateDrawingContext(this->pASRoot->pMovieImpl);
  pObject = this->pDrawingAPI.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->pDrawingAPI.pObject = DrawingContext;
  v5 = Scaleform::GFx::DisplayObjectBase::ConvertToTreeContainer(this);
  Scaleform::Render::TreeContainer::Insert(v5, 0i64, this->pDrawingAPI.pObject->pTreeContainer.pObject);
  if ( pMaskCharacter )
    Scaleform::GFx::DisplayObject::SetMask(this, pMaskCharacter, 1);
  if ( pMaskCharacter )
    Scaleform::RefCountNTSImpl::Release(pMaskCharacter);
  return this->pDrawingAPI.pObject;
}

// File Line: 1676
// RVA: 0x8DD620
Scaleform::Render::TreeContainer *__fastcall Scaleform::GFx::Sprite::GetRenderContainer(Scaleform::GFx::Sprite *this)
{
  Scaleform::Render::TreeContainer *result; // rax
  _QWORD *v3; // rax

  result = (Scaleform::Render::TreeContainer *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  if ( this->pDrawingAPI.pObject )
  {
    v3 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)result & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                              + 8i64
                              * (unsigned int)((int)((_DWORD)result - ((unsigned int)result & 0xFFFFF000) - 56) / 56)
                              + 40)
                  + 144i64);
    if ( (*(_BYTE *)v3 & 1) != 0 )
      v3 = (_QWORD *)((*v3 & 0xFFFFFFFFFFFFFFFEui64) + 16);
    return (Scaleform::Render::TreeContainer *)v3[1];
  }
  return result;
}

// File Line: 1689
// RVA: 0x907C70
void __fastcall Scaleform::GFx::Sprite::SetHitArea(Scaleform::GFx::Sprite *this, Scaleform::GFx::Sprite *phitArea)
{
  __int64 v4; // rax
  Scaleform::GFx::CharacterHandle *pObject; // rsi
  Scaleform::GFx::CharacterHandle *v6; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::CharacterHandle *v11; // rbx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  unsigned __int8 AvmObjOffset; // al
  __int64 v16; // rax

  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[120].__vecDelDtor)(this);
  if ( v4 )
    *(_QWORD *)(v4 + 304) = 0i64;
  if ( phitArea )
  {
    pObject = phitArea->pNameHandle.pObject;
    if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(phitArea)) != 0i64 )
      ++pObject->RefCount;
    v6 = this->pHitAreaHandle.pObject;
    if ( v6 )
    {
      if ( --v6->RefCount <= 0 )
      {
        pNode = v6->OriginalName.pNode;
        v8 = pNode->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v9 = v6->NamePath.pNode;
        v8 = v9->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
        v10 = v6->Name.pNode;
        v8 = v10->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v10);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
      }
    }
    this->pHitAreaHandle.pObject = pObject;
    phitArea->pHitAreaHolder = this;
  }
  else
  {
    v11 = this->pHitAreaHandle.pObject;
    if ( v11 )
    {
      if ( --v11->RefCount <= 0 )
      {
        v12 = v11->OriginalName.pNode;
        v8 = v12->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        v13 = v11->NamePath.pNode;
        v8 = v13->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v13);
        v14 = v11->Name.pNode;
        v8 = v14->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v14);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
      }
    }
    this->pHitAreaHandle.pObject = 0i64;
  }
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v16 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * AvmObjOffset))[2].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::Sprite *))(*(_QWORD *)v16 + 264i64))(v16, phitArea);
  }
}

// File Line: 1708
// RVA: 0x8D9B00
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::Sprite::GetHitArea(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::CharacterHandle *pObject; // r8
  __int64 pCharacter; // rdx
  Scaleform::GFx::ASMovieRootBase *v3; // rcx
  Scaleform::GFx::Sprite *result; // rax

  pObject = this->pHitAreaHandle.pObject;
  if ( !pObject )
    return 0i64;
  pCharacter = (__int64)pObject->pCharacter;
  if ( !pCharacter )
  {
    v3 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    pCharacter = (__int64)v3->vfptr[8].__vecDelDtor(v3, (unsigned int)&pObject->NamePath);
    if ( !pCharacter )
      return 0i64;
  }
  result = 0i64;
  if ( (*(_WORD *)(pCharacter + 106) & 0x400) != 0 )
    return (Scaleform::GFx::Sprite *)pCharacter;
  return result;
}

// File Line: 1719
// RVA: 0x909B00
void __fastcall Scaleform::GFx::Sprite::SetName(Scaleform::GFx::Sprite *this, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::DisplayObject::SetName(this, name);
  this->mDisplayList.pCachedChar = 0i64;
}

// File Line: 1726
// RVA: 0x8E7120
char __fastcall Scaleform::GFx::Sprite::IsFocusEnabled(Scaleform::GFx::Sprite *this, unsigned int fmt)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v4; // rax
  char Value; // dl
  unsigned __int8 v7; // al
  __int64 v8; // rax
  unsigned __int8 v9; // al
  __int64 v10; // rax

  if ( fmt == 1 )
  {
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v4 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
      return (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 160i64))(v4, fmt);
    }
    else
    {
      return 1;
    }
  }
  else
  {
    Value = this->FocusEnabled.Value;
    if ( Value || (v7 = this->AvmObjOffset) == 0 )
    {
      if ( Value == 2 )
      {
        v9 = this->AvmObjOffset;
        if ( v9 )
        {
          v10 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                         + 4 * v9))[1].__vecDelDtor)((char *)this + 4 * v9);
          return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 96i64))(v10);
        }
        else
        {
          return 0;
        }
      }
      else
      {
        return Value == 1;
      }
    }
    else
    {
      v8 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * v7))[2].__vecDelDtor)((char *)this + 4 * v7);
      return (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v8 + 160i64))(v8, fmt);
    }
  }
}

