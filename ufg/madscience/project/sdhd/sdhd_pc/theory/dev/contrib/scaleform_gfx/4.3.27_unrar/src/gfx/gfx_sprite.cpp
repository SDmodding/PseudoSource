// File Line: 79
// RVA: 0x89CCF0
void __fastcall Scaleform::GFx::Sprite::Sprite(Scaleform::GFx::Sprite *this, Scaleform::GFx::TimelineDef *pdef, Scaleform::GFx::MovieDefImpl *pdefImpl, Scaleform::GFx::ASMovieRootBase *pr, Scaleform::GFx::InteractiveObject *pparent, Scaleform::GFx::ResourceId id, bool loadedSeparately)
{
  Scaleform::GFx::ASMovieRootBase *v7; // rbp
  Scaleform::GFx::MovieDefImpl *v8; // r14
  Scaleform::GFx::TimelineDef *v9; // rdi
  Scaleform::GFx::Sprite *v10; // rbx
  int *v11; // rax
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
  int v23; // [rsp+40h] [rbp-48h]
  int v24; // [rsp+44h] [rbp-44h]
  int v25; // [rsp+48h] [rbp-40h]
  int v26; // [rsp+4Ch] [rbp-3Ch]
  Scaleform::Render::Rect<float> rect; // [rsp+50h] [rbp-38h]
  __int128 v28; // [rsp+60h] [rbp-28h]

  v7 = pr;
  v8 = pdefImpl;
  v9 = pdef;
  v10 = this;
  id.Id = **(_DWORD **)&id.Id;
  Scaleform::GFx::DisplayObjContainer::DisplayObjContainer(
    (Scaleform::GFx::DisplayObjContainer *)&this->vfptr,
    pdefImpl,
    pr,
    pparent,
    (Scaleform::GFx::ResourceId)&id);
  v10->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::Sprite::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v10->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::Sprite::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  if ( v9 )
    _InterlockedExchangeAdd(&v9->RefCount.Value, 1u);
  v10->pDef.pObject = v9;
  *(_QWORD *)&v10->PlayStatePriv = 0i64;
  v10->pDrawingAPI.pObject = 0i64;
  v10->pHitAreaHandle.pObject = 0i64;
  v10->pHitAreaHolder = 0i64;
  *(_WORD *)&v10->Flags = 0;
  v10->MouseStatePriv = 0;
  v10->pASRoot = v7;
  if ( (v9->vfptr->GetResourceTypeCode((Scaleform::GFx::Resource *)&v9->vfptr) & 0xFF00) == 33792 )
  {
    v11 = (int *)v9[2].pLib;
    if ( v11 )
    {
      v12 = v11[3];
      v13 = v11[2];
      v14 = v11[1];
      v23 = *v11;
      v24 = v14;
      v25 = v13;
      v26 = v12;
      v15 = (__int128 *)&v23;
    }
    else
    {
      v28 = 0i64;
      v15 = &v28;
    }
    v16 = *((float *)v15 + 3);
    v17 = *((float *)v15 + 2);
    v18 = *((float *)v15 + 1);
    rect.x1 = *(float *)v15;
    rect.y1 = v18;
    rect.x2 = v17;
    rect.y2 = v16;
    Scaleform::GFx::DisplayObjContainer::SetScale9Grid((Scaleform::GFx::DisplayObjContainer *)&v10->vfptr, &rect);
    v10->Flags |= 0x40u;
  }
  v10->Flags |= 0x400u;
  v19 = (v10->Flags | 1) & 0xDD;
  v10->Flags = v19;
  v20 = loadedSeparately;
  if ( loadedSeparately )
    v21 = v19 | 0x10;
  else
    v21 = v19 & 0xEF;
  v10->Flags = v21;
  if ( !pparent
    || v20
    || (Scaleform::GFx::MovieDefImpl *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pparent->vfptr[66].__vecDelDtor)(pparent) == v8 )
  {
    v22 = 0;
    if ( !v20 )
      return;
  }
  else
  {
    v22 = 1;
  }
  Scaleform::GFx::DisplayObjContainer::AssignRootNode((Scaleform::GFx::DisplayObjContainer *)&v10->vfptr, v22);
}

// File Line: 120
// RVA: 0x8A7A00
void __fastcall Scaleform::GFx::Sprite::~Sprite(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // rdi
  Scaleform::GFx::CharacterHandle *v2; // rbx
  Scaleform::GFx::ASStringNode *v3; // rcx
  bool v4; // zf
  Scaleform::GFx::ASStringNode *v5; // rcx
  Scaleform::GFx::ASStringNode *v6; // rcx
  Scaleform::RefCountNTSImpl *v7; // rcx
  Scaleform::GFx::TimelineDef *v8; // rbx
  Scaleform::GFx::ResourceLibBase *v9; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::Sprite::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::Sprite::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, (Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  v2 = v1->pHitAreaHandle.pObject;
  if ( v2 )
  {
    if ( --v2->RefCount <= 0 )
    {
      v3 = v2->OriginalName.pNode;
      v4 = v3->RefCount-- == 1;
      if ( v4 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v3);
      v5 = v2->NamePath.pNode;
      v4 = v5->RefCount-- == 1;
      if ( v4 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      v6 = v2->Name.pNode;
      v4 = v6->RefCount-- == 1;
      if ( v4 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
    }
  }
  v7 = (Scaleform::RefCountNTSImpl *)&v1->pDrawingAPI.pObject->vfptr;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  v8 = v1->pDef.pObject;
  if ( v8 && !_InterlockedDecrement(&v8->RefCount.Value) )
  {
    v9 = v8->pLib;
    if ( v9 )
    {
      v9->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v9->vfptr, (unsigned int)v8);
      v8->pLib = 0i64;
    }
    v8->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v8->vfptr, 1u);
  }
  Scaleform::GFx::DisplayObjContainer::~DisplayObjContainer((Scaleform::GFx::DisplayObjContainer *)&v1->vfptr);
}

// File Line: 134
// RVA: 0x908910
void __fastcall Scaleform::GFx::Sprite::SetLoadedSeparately(Scaleform::GFx::Sprite *this, bool v)
{
  char v2; // al
  char v3; // al

  v2 = this->Flags;
  if ( v )
    v3 = v2 | 0x10;
  else
    v3 = v2 & 0xEF;
  this->Flags = v3;
  if ( v )
    Scaleform::GFx::DisplayObjContainer::AssignRootNode((Scaleform::GFx::DisplayObjContainer *)&this->vfptr, 0);
}

// File Line: 146
// RVA: 0x90B170
void __fastcall Scaleform::GFx::Sprite::SetRootNodeLoadingStat(Scaleform::GFx::Sprite *this, unsigned int bytesLoaded, unsigned int loadingFrame)
{
  Scaleform::GFx::MovieDefRootNode *v3; // rax
  Scaleform::GFx::MovieDefRootNode *v4; // rax

  v3 = this->pRootNode;
  if ( v3 )
  {
    v3->BytesLoaded = bytesLoaded;
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
  Scaleform::GFx::Sprite *v1; // rbx
  unsigned __int8 v2; // al
  __int64 v3; // rax

  v1 = this;
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, (Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  v2 = v1->AvmObjOffset;
  if ( v2 )
  {
    v3 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr + 4 * v2))[2].__vecDelDtor)((signed __int64)v1 + 4 * v2);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 232i64))(v3);
  }
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList((Scaleform::GFx::InteractiveObject *)&v1->vfptr);
}

// File Line: 201
// RVA: 0x8E1100
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::Sprite::GetTopParent(Scaleform::GFx::Sprite *this, bool ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *v2; // r8
  char v3; // al

  v2 = this->pParent;
  if ( !v2 )
    return this;
  if ( !ignoreLockRoot )
  {
    v3 = this->Flags;
    if ( v3 & 0x10 )
    {
      if ( v3 & 0x20 )
        return this;
    }
  }
  if ( (LOBYTE(this->Flags) >> 4) & 1 )
    return (Scaleform::GFx::Sprite *)this->pASRoot->pMovieImpl->pMainMovie;
  return (Scaleform::GFx::Sprite *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[68].__vecDelDtor)(this->pParent);
}

// File Line: 224
// RVA: 0x8D5970
__int64 __fastcall Scaleform::GFx::Sprite::GetBytesLoaded(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // rax
  Scaleform::GFx::MovieDefRootNode *v2; // rcx

  while ( this )
  {
    v1 = 0i64;
    if ( (this->Flags >> 9) & 1 )
      v1 = this;
    if ( v1 && v1->pRootNode )
    {
      v2 = v1->pRootNode;
      if ( v2 )
        return v2->BytesLoaded;
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
  Scaleform::GFx::MovieDefRootNode *v1; // rax
  __int64 result; // rax

  v1 = this->pRootNode;
  if ( !v1 || v1->ImportFlag )
    result = ((__int64 (*)(void))this->pDef.pObject->vfptr[2].GetResourceTypeCode)();
  else
    result = v1->LoadingFrame;
  return result;
}

// File Line: 249
// RVA: 0x8D5210
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Sprite::GetBounds(Scaleform::GFx::Sprite *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  Scaleform::GFx::Sprite *v3; // rdi
  Scaleform::Render::Matrix2x4<float> *v4; // rsi
  Scaleform::Render::Rect<float> *v5; // rbx
  Scaleform::GFx::DrawingContext *v6; // rcx
  float v7; // xmm1_4
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm4_4
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  double *v15; // rax
  float v16; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  Scaleform::Render::Rect<float> pr; // [rsp+30h] [rbp-20h]
  Scaleform::Render::Rect<float> pRect; // [rsp+40h] [rbp-10h]

  v3 = this;
  v4 = transform;
  v5 = result;
  Scaleform::GFx::DisplayList::GetBounds(&this->mDisplayList, result, transform);
  v6 = v3->pDrawingAPI.pObject;
  if ( v6 )
  {
    pRect = 0i64;
    Scaleform::GFx::DrawingContext::ComputeBound(v6, &pRect);
    if ( pRect.x1 < pRect.x2 && pRect.y1 < pRect.y2 )
    {
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(v4, &pr, &pRect);
      v7 = v5->x2;
      if ( v5->x1 >= v7 || (v8 = v5->y1, v9 = v5->y2, v8 >= v9) )
      {
        v12 = pr.y1;
        v5->x1 = pr.x1;
        v13 = pr.x2;
        v5->y1 = v12;
        v14 = pr.y2;
        v5->x2 = v13;
        v5->y2 = v14;
      }
      else
      {
        v10 = pr.x1;
        if ( v5->x1 <= pr.x1 )
          v10 = v5->x1;
        if ( v7 <= pr.x2 )
          v7 = pr.x2;
        v11 = pr.y1;
        if ( v8 <= pr.y1 )
          v11 = v5->y1;
        if ( v9 <= pr.y2 )
          v9 = pr.y2;
        v5->x1 = v10;
        v5->y1 = v11;
        v5->x2 = v7;
        v5->y2 = v9;
      }
    }
  }
  v15 = &v3->pScrollRect->Rectangle.x1;
  if ( v15 )
  {
    v16 = v15[3];
    v17 = v15[1];
    v18 = *v15;
    pRect.x2 = v15[2];
    pRect.x1 = v18;
    pRect.y1 = v17;
    pRect.y2 = v16;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(v4, &pr, &pRect);
    Scaleform::Render::Rect<float>::Intersect(v5, pr.x1, pr.y1, pr.x2, pr.y2);
  }
  return v5;
}

// File Line: 281
// RVA: 0x8DD480
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Sprite::GetRectBounds(Scaleform::GFx::DisplayObjContainer *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *t)
{
  Scaleform::Render::Rect<float> *v3; // rbx

  v3 = result;
  Scaleform::GFx::DisplayList::GetRectBounds(&this->mDisplayList, result, t);
  return v3;
}

// File Line: 286
// RVA: 0x8D8340
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Sprite::GetFocusRect(Scaleform::GFx::Sprite *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // rdi
  Scaleform::GFx::Sprite *v3; // rbx
  __int64 v4; // rax
  __int64 v5; // rsi
  _OWORD *v6; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v8; // rax
  Scaleform::Render::Rect<float> r; // [rsp+20h] [rbp-48h]
  __m128 v10; // [rsp+30h] [rbp-38h]
  Scaleform::Render::Matrix2x4<float> v11; // [rsp+40h] [rbp-28h]

  v2 = result;
  v3 = this;
  v4 = ((__int64 (*)(void))this->vfptr[120].__vecDelDtor)();
  v5 = v4;
  *(_OWORD *)&v11.M[0][0] = _xmm;
  *(__m128 *)&v11.M[1][0] = _xmm;
  if ( v4 )
  {
    v6 = (_OWORD *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 16i64))(v4);
    *(_OWORD *)&v11.M[0][0] = *v6;
    *(_OWORD *)&v11.M[1][0] = v6[1];
    (*(void (__fastcall **)(__int64, Scaleform::Render::Rect<float> *))(*(_QWORD *)v5 + 744i64))(v5, &r);
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v11, v2, &r);
  }
  else
  {
    v8 = v3->vfptr;
    r = (Scaleform::Render::Rect<float>)_xmm;
    v10 = _xmm;
    ((void (__fastcall *)(Scaleform::GFx::Sprite *, Scaleform::Render::Rect<float> *, Scaleform::Render::Rect<float> *))v8[61].__vecDelDtor)(
      v3,
      v2,
      &r);
  }
  return v2;
}

// File Line: 335
// RVA: 0x904600
void __fastcall Scaleform::GFx::Sprite::Restart(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // rbx
  char v2; // al
  char v3; // cl
  unsigned __int8 v4; // al
  __int64 v5; // rax

  v1 = this;
  Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(
    &this->mDisplayList,
    (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
    0);
  v2 = v1->Flags | 1;
  *(_QWORD *)&v1->PlayStatePriv = 0i64;
  v1->RollOverCnt = 0;
  v3 = v2;
  v4 = v1->AvmObjOffset;
  v1->Flags = v3 & 0xFD;
  if ( v4 )
  {
    v5 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr + 4 * v4))[2].__vecDelDtor)((signed __int64)v1 + 4 * v4);
    (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v5 + 224i64))(v5, v1->CurrentFrame);
  }
  Scaleform::GFx::Sprite::ExecuteFrameTags(v1, v1->CurrentFrame);
  Scaleform::GFx::DisplayList::UnloadMarkedObjects(&v1->mDisplayList, (Scaleform::GFx::DisplayObjectBase *)&v1->vfptr);
}

// File Line: 356
// RVA: 0x8E03D0
signed __int64 __fastcall Scaleform::GFx::Sprite::GetTopMostMouseEntity(Scaleform::GFx::Sprite *this, Scaleform::Render::Point<float> *pt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v3; // rdi
  Scaleform::GFx::Sprite *v4; // rbx
  unsigned int v5; // ebp
  __int64 v6; // rsi
  unsigned __int8 v7; // al
  __int64 v8; // rax
  unsigned __int8 v9; // al
  __int64 v10; // rax
  unsigned __int8 v11; // al
  __int64 v12; // rax
  __int64 v14; // rax
  Scaleform::GFx::DisplayObject *v15; // rdx
  Scaleform::GFx::Sprite *v16; // rcx
  Scaleform::GFx::InteractiveObject *v17; // rax

  v3 = pdescr;
  v4 = this;
  v5 = Scaleform::GFx::DisplayObjContainer::GetTopMostMouseEntity(
         (Scaleform::GFx::DisplayObjContainer *)&this->vfptr,
         pt,
         pdescr);
  if ( v5 != 3 || !v4->pDrawingAPI.pObject )
    return v5;
  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))v4->vfptr[121].__vecDelDtor)(v4);
  if ( v4->pASRoot->AVMVersion != 2 || !v3->TestAll )
  {
    v7 = v4->AvmObjOffset;
    if ( !v7
      || (v8 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr
                                                                                                + 4 * v7))[1].__vecDelDtor)((signed __int64)v4 + 4 * v7),
          !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v8 + 96i64))(v8)) )
    {
      if ( !v6 )
        return v5;
      if ( !v3->TestAll )
      {
        v9 = *(_BYTE *)(v6 + 109);
        if ( !v9 )
          return v5;
        v10 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v6 + 4i64 * v9) + 8i64))(v6 + 4i64 * v9);
        if ( !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v10 + 96i64))(v10) )
          return v5;
      }
    }
  }
  if ( !Scaleform::GFx::DrawingContext::DefPointTestLocal(
          v4->pDrawingAPI.pObject,
          &v3->LocalPt,
          1,
          (Scaleform::GFx::DisplayObjectBase *)&v4->vfptr) )
    return v5;
  if ( v6 )
  {
    if ( v3->TestAll
      || (v11 = *(_BYTE *)(v6 + 109)) != 0
      && (v12 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v6 + 4i64 * v11) + 8i64))(v6 + 4i64 * v11),
          (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v12 + 96i64))(v12)) )
    {
      v3->pResult = (Scaleform::GFx::InteractiveObject *)v6;
      v3->pHitArea = (Scaleform::GFx::DisplayObject *)&v4->vfptr;
      return 1i64;
    }
  }
  v14 = ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))v4->vfptr[120].__vecDelDtor)(v4);
  v15 = (Scaleform::GFx::DisplayObject *)v14;
  if ( v4->pASRoot->AVMVersion == 1 )
  {
    if ( v14 )
    {
      v16 = (Scaleform::GFx::Sprite *)v14;
      while ( 1 )
      {
        v16 = (Scaleform::GFx::Sprite *)v16->pParent;
        if ( !v16 )
          goto LABEL_24;
        if ( v16 == v4 )
        {
          if ( (Scaleform::GFx::DisplayObject *)v14 != v3->pHitArea )
            goto LABEL_24;
          break;
        }
      }
    }
LABEL_23:
    v3->pResult = (Scaleform::GFx::InteractiveObject *)&v4->vfptr;
    return 1i64;
  }
  if ( !v14 )
    goto LABEL_23;
  v17 = v3->pResult;
  if ( v3->pResult )
  {
    if ( v17 != (Scaleform::GFx::InteractiveObject *)v4 && SLOBYTE(v17->Flags) < 0 )
      return v5;
  }
  if ( v15 != v3->pHitArea )
  {
LABEL_24:
    v3->pResult = 0i64;
    return 2i64;
  }
  v3->pResult = (Scaleform::GFx::InteractiveObject *)&v4->vfptr;
  return 1i64;
}

// File Line: 964
// RVA: 0x8E3610
void __fastcall Scaleform::GFx::Sprite::IncrementFrameAndCheckForLoop(Scaleform::GFx::Sprite *this)
{
  Scaleform::RefCountNTSImplCoreVtbl *v1; // rax
  Scaleform::GFx::Sprite *v2; // rbx
  unsigned int v3; // edi
  unsigned int v4; // eax

  v1 = this->vfptr;
  ++this->CurrentFrame;
  v2 = this;
  v3 = ((__int64 (*)(void))v1[111].__vecDelDtor)();
  v4 = ((__int64 (*)(void))v2->pDef.pObject->vfptr[2].GetResourceTypeCode)();
  if ( v3 >= v4 || v2->CurrentFrame < v3 )
  {
    if ( v2->CurrentFrame >= v4 )
    {
      v2->Flags |= 2u;
      v2->CurrentFrame = 0;
      if ( v4 <= 1 )
        v2->vfptr[114].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 1u);
      else
        Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(
          &v2->mDisplayList,
          (Scaleform::GFx::DisplayObjectBase *)&v2->vfptr,
          0);
    }
  }
  else if ( v3 )
  {
    v2->CurrentFrame = v3 - 1;
  }
  else
  {
    v2->CurrentFrame = 0;
  }
}

// File Line: 994
// RVA: 0x8B5940
void __fastcall Scaleform::GFx::Sprite::AdvanceFrame(Scaleform::GFx::Sprite *this, bool nextFrame, float framePos)
{
  bool v3; // di
  Scaleform::GFx::Sprite *v4; // rbx
  unsigned __int8 v5; // al
  __int64 v6; // rax

  v3 = nextFrame;
  v4 = this;
  if ( !(this->Flags & 0xC) && !(this->Flags & 0x1000) && this->Depth >= -1 )
  {
    ++this->RefCount;
    v5 = this->AvmObjOffset;
    if ( v5 )
    {
      v6 = ((__int64 (__cdecl *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v5))[2].__vecDelDtor)((char *)this + 4 * v5);
      (*(void (__fastcall **)(__int64, bool))(*(_QWORD *)v6 + 200i64))(v6, v3);
    }
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
  }
}

// File Line: 1025
// RVA: 0x8CA7D0
void __fastcall Scaleform::GFx::Sprite::ExecuteFrame0Events(Scaleform::GFx::Sprite *this)
{
  char v1; // al
  Scaleform::GFx::Sprite *v2; // rbx
  unsigned __int8 v3; // al
  __int64 v4; // rax
  unsigned __int8 v5; // al
  __int64 v6; // rax

  v1 = this->Flags;
  v2 = this;
  if ( !(v1 & 8) )
  {
    this->Flags = v1 | 8;
    v3 = this->AvmObjOffset;
    if ( v3 )
    {
      v4 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v3))[2].__vecDelDtor)();
      (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 224i64))(v4, 0i64);
    }
    Scaleform::GFx::Sprite::ExecuteFrameTags(v2, 0);
    v5 = v2->AvmObjOffset;
    if ( v5 )
    {
      v6 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v2->vfptr + 4 * v5))[2].__vecDelDtor)((signed __int64)v2 + 4 * v5);
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 208i64))(v6);
    }
  }
}

// File Line: 1052
// RVA: 0x8CA850
void __fastcall Scaleform::GFx::Sprite::ExecuteFrameTags(Scaleform::GFx::Sprite *this, unsigned int frame)
{
  unsigned int v2; // esi
  Scaleform::GFx::Sprite *v3; // rbx
  __int64 v4; // rdi
  unsigned __int8 v5; // al
  __int64 v6; // rax
  __int64 v7; // [rsp+28h] [rbp-20h]
  unsigned int v8; // [rsp+30h] [rbp-18h]

  v2 = frame;
  v3 = this;
  if ( (this->Flags >> 11) & 1 || !frame )
  {
    ++this->RefCount;
    if ( frame < ((unsigned int (__cdecl *)(Scaleform::GFx::Sprite *))this->vfptr[111].__vecDelDtor)(this) )
    {
      ((void (__fastcall *)(Scaleform::GFx::TimelineDef *, __int64 *, _QWORD))v3->pDef.pObject->vfptr[2].GetResourceReport)(
        v3->pDef.pObject,
        &v7,
        v2);
      v4 = 0i64;
      if ( v8 )
      {
        do
        {
          (*(void (__fastcall **)(_QWORD, Scaleform::GFx::Sprite *, signed __int64))(**(_QWORD **)(v7 + 8 * v4) + 16i64))(
            *(_QWORD *)(v7 + 8 * v4),
            v3,
            4i64);
          v4 = (unsigned int)(v4 + 1);
        }
        while ( (unsigned int)v4 < v8 );
      }
      v5 = v3->AvmObjOffset;
      if ( v5 )
      {
        v6 = ((__int64 (__cdecl *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * v5))[2].__vecDelDtor)((signed __int64)v3 + 4 * v5);
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v6 + 216i64))(v6, v2);
      }
    }
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v3->vfptr);
  }
}

// File Line: 1086
// RVA: 0x8CA910
void __fastcall Scaleform::GFx::Sprite::ExecuteImportedInitActions(Scaleform::GFx::Sprite *this, Scaleform::GFx::MovieDef *psourceMovie)
{
  Scaleform::GFx::MovieDef *v2; // r13
  Scaleform::GFx::Sprite *v3; // r14
  _QWORD *v4; // r12
  unsigned __int64 v5; // r15
  _RTL_CRITICAL_SECTION *v6; // rdi
  _RTL_CRITICAL_SECTION *v7; // rbx
  unsigned __int64 v8; // rdi
  __int64 v9; // rsi
  unsigned int *v10; // rbx
  __int64 v11; // rbp
  unsigned __int64 v12; // rdi
  __int64 v13; // rdi
  __int64 v14; // [rsp+28h] [rbp-50h]
  unsigned int v15; // [rsp+30h] [rbp-48h]
  unsigned __int64 v16; // [rsp+88h] [rbp+10h]

  v2 = psourceMovie;
  v3 = this;
  v4 = *(_QWORD **)(*(_QWORD *)&psourceMovie[3].RefCount.Value + 24i64);
  v5 = 0i64;
  v6 = (_RTL_CRITICAL_SECTION *)v4[8];
  v7 = v6 + 10;
  EnterCriticalSection(v6 + 10);
  v8 = v6[11].SpinCount;
  LeaveCriticalSection(v7);
  v16 = (unsigned int)v8;
  if ( (_DWORD)v8 )
  {
    do
    {
      v14 = 0i64;
      v15 = 0;
      if ( (*(unsigned __int8 (__fastcall **)(_QWORD *, __int64 *, _QWORD))(*v4 + 96i64))(v4, &v14, (unsigned int)v5) )
      {
        v9 = 0i64;
        if ( v15 )
        {
          do
          {
            v10 = *(unsigned int **)(v14 + 8 * v9);
            if ( (*(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)v10 + 40i64))(*(_QWORD *)(v14 + 8 * v9)) )
            {
              v11 = *(_QWORD *)&v2[3].RefCount.Value;
              v12 = v10[2];
              EnterCriticalSection((LPCRITICAL_SECTION)(v11 + 152));
              if ( v12 < *(_QWORD *)(v11 + 136) )
              {
                v13 = *(_QWORD *)(*(_QWORD *)(v11 + 128) + 8i64 * (unsigned int)v12);
                LeaveCriticalSection((LPCRITICAL_SECTION)(v11 + 152));
                if ( v13
                  && *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v13 + 104) + 24i64) + 64i64) + 488i64) > 0
                  && v13 != ((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))v3->vfptr[66].__vecDelDtor)(v3) )
                {
                  v3->vfptr[119].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, v13);
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
                v3,
                0i64);
            }
            v9 = (unsigned int)(v9 + 1);
          }
          while ( (unsigned int)v9 < v15 );
        }
      }
      ++v5;
    }
    while ( v5 < v16 );
  }
}

// File Line: 1125
// RVA: 0x8E21E0
void __fastcall Scaleform::GFx::Sprite::GotoFrame(Scaleform::GFx::Sprite *this, unsigned int targetFrameNumber)
{
  signed int v2; // esi
  Scaleform::GFx::Sprite *v3; // rbx
  unsigned __int16 v4; // cx
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // er8
  Scaleform::MemoryHeap *v8; // rax
  unsigned __int8 v9; // al
  __int64 v10; // rax
  Scaleform::MemoryHeap *v11; // rax
  unsigned int i; // esi
  __int64 v13; // rax
  unsigned __int8 v14; // al
  __int64 v15; // rax
  Scaleform::GFx::TimelineSnapshot v16; // [rsp+18h] [rbp-29h]
  void *v17; // [rsp+A8h] [rbp+67h]
  Scaleform::ArrayDH_POD<Scaleform::GFx::TimelineSnapshot::SnapshotElement *,2,Scaleform::ArrayDefaultPolicy> *retaddr; // [rsp+B8h] [rbp+77h]

  v2 = targetFrameNumber;
  v3 = this;
  v4 = this->Flags;
  if ( (v4 >> 11) & 1 && !(v4 & 0x1000) && v3->Depth >= -1 )
  {
    v5 = (unsigned __int64)((__int64 (__fastcall *)(Scaleform::GFx::Sprite *))v3->vfptr[111].__vecDelDtor)(v3) - 1;
    if ( v2 < (signed int)v5 )
      v5 = v2;
    if ( (v5 & 0x80000000) != 0 )
      v5 = 0;
    v6 = v3->CurrentFrame;
    if ( v5 >= v6 )
    {
      if ( v5 > v6 )
      {
        if ( v5 <= 1 || v5 <= v6 + 1 )
        {
          v3->CurrentFrame = v5;
        }
        else
        {
          v11 = v3->pASRoot->pMovieImpl->pHeap;
          v17 = &v16;
          _mm_store_si128((__m128i *)&v16, (__m128i)0i64);
          v16.SnapshotHeap.NumElementsInPage = 50;
          v16.SnapshotHeap.FirstEmptySlot = 0i64;
          v16.SnapshotHeap.pHeapOrPtr = v11;
          v17 = &v16.SnapshotSortedArray;
          retaddr = &v16.SnapshotSortedArray;
          v16.SnapshotSortedArray.Data.Data = 0i64;
          v16.SnapshotSortedArray.Data.Size = 0i64;
          v16.SnapshotSortedArray.Data.Policy.Capacity = 0i64;
          v16.SnapshotSortedArray.Data.pHeap = v11;
          v16.SnapshotList.Root.pPrev = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&v16.SnapshotList;
          v16.SnapshotList.Root.pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&v16.SnapshotList;
          v16.pOwnerSprite = (Scaleform::GFx::InteractiveObject *)&v3->vfptr;
          v16.Direction = 0;
          Scaleform::GFx::TimelineSnapshot::MakeSnapshot(&v16, v3->pDef.pObject, v3->CurrentFrame + 1, v5 - 1);
          if ( v3->AvmObjOffset )
          {
            for ( i = v3->CurrentFrame + 1; i < v5; ++i )
            {
              v13 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr
                                                                                + 4 * (unsigned __int8)v3->AvmObjOffset))[2].__vecDelDtor)();
              (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v13 + 224i64))(v13, i);
            }
          }
          v3->CurrentFrame = v5;
          Scaleform::GFx::TimelineSnapshot::ExecuteSnapshot(&v16, (Scaleform::GFx::DisplayObjContainer *)&v3->vfptr);
          Scaleform::GFx::TimelineSnapshot::~TimelineSnapshot(&v16);
        }
        v14 = v3->AvmObjOffset;
        if ( v14 )
        {
          v15 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * v14))[2].__vecDelDtor)();
          (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v15 + 224i64))(v15, v5);
        }
        Scaleform::GFx::Sprite::ExecuteFrameTags(v3, v5);
      }
    }
    else
    {
      v7 = v5 - 1;
      if ( !v5 )
        v7 = 0;
      Scaleform::GFx::DisplayList::MarkAllEntriesForRemoval(
        &v3->mDisplayList,
        (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr,
        v7);
      if ( v5 < 1 )
      {
        v3->CurrentFrame = v5;
      }
      else
      {
        v8 = (Scaleform::MemoryHeap *)((__int64 (*)(void))v3->pASRoot->pMovieImpl->vfptr[48].__vecDelDtor)();
        v17 = &v16;
        _mm_store_si128((__m128i *)&v16, (__m128i)0i64);
        v16.SnapshotHeap.NumElementsInPage = 50;
        v16.SnapshotHeap.FirstEmptySlot = 0i64;
        v16.SnapshotHeap.pHeapOrPtr = v8;
        v17 = &v16.SnapshotSortedArray;
        retaddr = &v16.SnapshotSortedArray;
        v16.SnapshotSortedArray.Data.Data = 0i64;
        v16.SnapshotSortedArray.Data.Size = 0i64;
        v16.SnapshotSortedArray.Data.Policy.Capacity = 0i64;
        v16.SnapshotSortedArray.Data.pHeap = v8;
        v16.SnapshotList.Root.pPrev = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&v16.SnapshotList;
        v16.SnapshotList.Root.pNext = (Scaleform::GFx::TimelineSnapshot::SnapshotElement *)&v16.SnapshotList;
        v16.pOwnerSprite = (Scaleform::GFx::InteractiveObject *)&v3->vfptr;
        v16.Direction = 1;
        Scaleform::GFx::TimelineSnapshot::MakeSnapshot(&v16, v3->pDef.pObject, 0, v5 - 1);
        v3->CurrentFrame = v5;
        Scaleform::GFx::TimelineSnapshot::ExecuteSnapshot(&v16, (Scaleform::GFx::DisplayObjContainer *)&v3->vfptr);
        Scaleform::GFx::TimelineSnapshot::~TimelineSnapshot(&v16);
      }
      v9 = v3->AvmObjOffset;
      if ( v9 )
      {
        v10 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * v9))[2].__vecDelDtor)();
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v10 + 224i64))(v10, v5);
      }
      Scaleform::GFx::Sprite::ExecuteFrameTags(v3, v5);
      Scaleform::GFx::DisplayList::UnloadMarkedObjects(
        &v3->mDisplayList,
        (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
    }
    v3->PlayStatePriv = 1;
  }
}

// File Line: 1262
// RVA: 0x8E2580
char __fastcall Scaleform::GFx::Sprite::GotoLabeledFrame(Scaleform::GFx::Sprite *this, const char *label, int offset)
{
  Scaleform::GFx::Sprite *v3; // rbx
  Scaleform::GFx::TimelineDef *v4; // rcx
  int v5; // esi
  const char *v6; // rdi
  char result; // al
  int v8; // [rsp+30h] [rbp+8h]

  v3 = this;
  v4 = this->pDef.pObject;
  v8 = -1;
  v5 = offset;
  v6 = label;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::TimelineDef *, const char *, int *, _QWORD))v4->vfptr[3].GetKey)(
         v4,
         label,
         &v8,
         0i64) )
  {
    v3->vfptr[110].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, v8 + v5);
    result = 1;
  }
  else
  {
    Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v3->vfptr,
      "MovieImpl::GotoLabeledFrame(%s) unknown label",
      v6);
    result = 0;
  }
  return result;
}

// File Line: 1277
// RVA: 0x909D00
void __fastcall Scaleform::GFx::Sprite::SetPlayState(Scaleform::GFx::Sprite *this, Scaleform::GFx::PlayState s)
{
  unsigned __int16 v2; // ax

  v2 = this->Flags;
  this->PlayStatePriv = s;
  if ( !(v2 & 0x1000) && this->Depth >= -1 )
    JUMPOUT(
      ((unsigned __int8)v2 >> 4) & 1,
      0,
      Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Sprite>);
}

// File Line: 1290
// RVA: 0x8BD130
void __fastcall Scaleform::GFx::Sprite::CloneInternalData(Scaleform::GFx::Sprite *this, Scaleform::GFx::InteractiveObject *src)
{
  Scaleform::GFx::InteractiveObject *v2; // rdi
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v3; // rdx
  Scaleform::GFx::Sprite *v4; // rbx
  unsigned __int8 v5; // al
  __int64 v6; // rax
  unsigned __int8 v7; // al
  __int64 v8; // rax

  v2 = src;
  v3 = src->pGeomData;
  v4 = this;
  if ( v3 )
    Scaleform::GFx::DisplayObjectBase::SetGeomData((Scaleform::GFx::DisplayObjectBase *)&this->vfptr, v3);
  v5 = v4->AvmObjOffset;
  if ( v5 )
  {
    v6 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr + 4 * v5))[1].__vecDelDtor)((signed __int64)v4 + 4 * v5);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v6 + 112i64))(v6, v2);
  }
  v7 = v4->AvmObjOffset;
  if ( v7 )
  {
    v8 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr + 4 * v7))[2].__vecDelDtor)((signed __int64)v4 + 4 * v7);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v8 + 112i64))(v8, v2);
  }
}

// File Line: 1317
// RVA: 0x8BA610
signed __int64 __fastcall Scaleform::GFx::Sprite::CheckAdvanceStatus(Scaleform::GFx::Sprite *this, bool playingNow)
{
  unsigned int v2; // ebx
  bool v3; // bp
  Scaleform::GFx::Sprite *v4; // rdi
  char v5; // si
  unsigned __int8 v6; // al
  __int64 v7; // rax
  unsigned __int8 v9; // al
  __int64 v10; // rax

  v2 = 0;
  v3 = playingNow;
  v4 = this;
  if ( this->Flags & 0xC || !(~(LOBYTE(this->Flags) >> 6) & 1) )
  {
    v5 = 1;
  }
  else
  {
    v5 = 0;
    if ( !((unsigned int (*)(void))this->vfptr[115].__vecDelDtor)() )
    {
      LOBYTE(v2) = v3 == 0;
      return v2;
    }
  }
  if ( v3 )
  {
    if ( v5 )
      return 0xFFFFFFFFi64;
    v6 = v4->AvmObjOffset;
    if ( !v6 )
      return 0xFFFFFFFFi64;
    v7 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr + 4 * v6))[2].__vecDelDtor)((signed __int64)v4 + 4 * v6);
    if ( !(*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v7 + 256i64))(v7) )
      return 0xFFFFFFFFi64;
  }
  else if ( !v5 )
  {
    v9 = v4->AvmObjOffset;
    if ( v9 )
    {
      v10 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr + 4 * v9))[2].__vecDelDtor)();
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v10 + 256i64))(v10) )
        v2 = 1;
    }
  }
  return v2;
}

// File Line: 1402
// RVA: 0x8B0710
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::Sprite::AddDisplayObject(Scaleform::GFx::Sprite *this, Scaleform::GFx::CharPosInfo *pos, Scaleform::GFx::ASString *name, Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *peventHandlers)
{
  unsigned __int8 v4; // al
  Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *v5; // rbx
  Scaleform::GFx::ASString *v6; // rdi
  Scaleform::GFx::CharPosInfo *v7; // rsi
  __int64 v8; // rax

  v4 = this->AvmObjOffset;
  v5 = peventHandlers;
  v6 = name;
  v7 = pos;
  if ( !v4 )
    return 0i64;
  v8 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v4))[2].__vecDelDtor)();
  return (Scaleform::GFx::DisplayObjectBase *)(*(__int64 (__fastcall **)(__int64, Scaleform::GFx::CharPosInfo *, Scaleform::GFx::ASString *, Scaleform::ArrayLH<Scaleform::GFx::SwfEvent *,260,Scaleform::ArrayDefaultPolicy> *))(*(_QWORD *)v8 + 192i64))(
                                                v8,
                                                v7,
                                                v6,
                                                v5);
}

// File Line: 1409
// RVA: 0x8BE7B0
void __fastcall Scaleform::GFx::Sprite::CreateAndReplaceDisplayObject(Scaleform::GFx::Sprite *this, Scaleform::GFx::CharPosInfo *pos, Scaleform::GFx::ASString *name, Scaleform::GFx::DisplayObjectBase **newChar)
{
  Scaleform::GFx::DisplayObjectBase **v4; // rbx
  Scaleform::GFx::Sprite *v5; // rdi

  v4 = newChar;
  v5 = this;
  if ( newChar )
    *newChar = 0i64;
  Scaleform::GFx::DisplayObjContainer::CreateAndReplaceDisplayObject(
    (Scaleform::GFx::DisplayObjContainer *)&this->vfptr,
    pos,
    name,
    newChar);
  if ( v4 )
  {
    if ( *v4 )
      (*v4)->CreateFrame = v5->CurrentFrame;
  }
}

// File Line: 1434
// RVA: 0x8EC690
bool __fastcall Scaleform::GFx::Sprite::OnEvent(Scaleform::GFx::Sprite *this, Scaleform::GFx::EventId *id)
{
  unsigned __int8 v2; // al
  Scaleform::GFx::EventId *v3; // rbx
  __int64 v4; // rax

  v2 = this->AvmObjOffset;
  v3 = id;
  if ( !v2 )
    return 0;
  v4 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v2))[2].__vecDelDtor)();
  return (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v4 + 64i64))(v4, v3);
}

// File Line: 1442
// RVA: 0x8EE740
bool __fastcall Scaleform::GFx::Sprite::OnMouseEvent(Scaleform::GFx::Sprite *this, Scaleform::GFx::EventId *id)
{
  unsigned __int8 v2; // al
  Scaleform::GFx::EventId *v3; // rdi
  Scaleform::GFx::Sprite *v4; // rbx
  __int64 v5; // rax
  unsigned __int8 v6; // al
  __int64 v7; // rax
  Scaleform::GFx::InteractiveObject *v8; // rcx
  bool result; // al

  v2 = this->AvmObjOffset;
  v3 = id;
  v4 = this;
  if ( v2
    && (v5 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v2))[2].__vecDelDtor)(),
        (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v5 + 248i64))(v5))
    || (v6 = v4->AvmObjOffset) != 0
    && (v7 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr
                                                                                              + 4 * v6))[2].__vecDelDtor)((signed __int64)v4 + 4 * v6),
        (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v7 + 64i64))(v7, v3))
    || (v8 = v4->pParent) == 0i64 )
  {
    result = 0;
  }
  else
  {
    result = (__int64)v8->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, (unsigned int)v3);
  }
  return result;
}

// File Line: 1463
// RVA: 0x8ECA50
void __fastcall Scaleform::GFx::Sprite::OnEventUnload(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // rbx

  v1 = this;
  this->Flags |= 0x1000u;
  if ( this->pHitAreaHandle.pObject )
    Scaleform::GFx::Sprite::SetHitArea(this, 0i64);
  Scaleform::GFx::DisplayList::Clear(&v1->mDisplayList, (Scaleform::GFx::DisplayObjectBase *)&v1->vfptr);
  Scaleform::GFx::InteractiveObject::OnEventUnload((Scaleform::GFx::InteractiveObject *)&v1->vfptr);
}

// File Line: 1482
// RVA: 0x8EEAB0
bool __fastcall Scaleform::GFx::Sprite::OnUnloading(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // rbx
  bool result; // al
  unsigned __int8 v3; // cl

  v1 = this;
  result = Scaleform::GFx::DisplayList::UnloadAll(
             &this->mDisplayList,
             (Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  v3 = v1->AvmObjOffset;
  if ( v3 )
    result = (__int64)(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr + 4 * v3))[11].__vecDelDtor(
                        (Scaleform::RefCountNTSImplCore *)((char *)&v1->vfptr + 4 * v3),
                        result);
  return result;
}

// File Line: 1493
// RVA: 0x8EDC10
__int64 __fastcall Scaleform::GFx::Sprite::OnKeyEvent(Scaleform::GFx::Sprite *this, Scaleform::GFx::EventId *id, int *pkeyMask)
{
  __int64 result; // rax
  int *v4; // rsi
  Scaleform::GFx::EventId *v5; // rdi
  Scaleform::GFx::Sprite *v6; // rbx
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 v9; // rbp
  int v10; // eax
  __int16 v11; // r14
  __int64 v12; // rax
  Scaleform::GFx::ASMovieRootBase *v13; // rax
  Scaleform::GFx::MovieImpl *v14; // rsi
  unsigned int v15; // eax
  int v16; // eax
  unsigned int v17; // eax
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // [rsp+20h] [rbp-28h]
  unsigned int v23; // [rsp+28h] [rbp-20h]
  unsigned int v24; // [rsp+2Ch] [rbp-1Ch]
  int v25; // [rsp+30h] [rbp-18h]

  result = (unsigned __int8)this->AvmObjOffset;
  v4 = pkeyMask;
  v5 = id;
  v6 = this;
  if ( (_BYTE)result )
  {
    v7 = *(__int64 *)((char *)&this->vfptr + 4 * (unsigned __int8)result);
    if ( id->Id == 64 )
    {
      v8 = (*(__int64 (**)(void))(v7 + 16))();
      v9 = (*(unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v8 + 64i64))(v8, v5);
      if ( !(*v4 & 0x10000) )
      {
        v10 = Scaleform::GFx::EventId::ConvertToButtonKeyCode(v5);
        v11 = v10;
        if ( v10 )
        {
          v12 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr
                                                                                                 + 4
                                                                                                 * (unsigned __int8)v6->AvmObjOffset))[2].__vecDelDtor)((signed __int64)v6 + 4 * (unsigned __int8)v6->AvmObjOffset);
          v22 = 0x20000i64;
          v23 = v11;
          LOBYTE(v24) = 0;
          v25 = 0;
          LOBYTE(v9) = (*(__int64 (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v12 + 64i64))(v12, &v22);
          if ( (_BYTE)v9 )
            *v4 |= 0x10000u;
        }
      }
      v13 = v6->pASRoot;
      v14 = v13->pMovieImpl;
      if ( Scaleform::GFx::MovieImpl::IsKeyboardFocused(
             v13->pMovieImpl,
             (Scaleform::GFx::InteractiveObject *)&v6->vfptr,
             v5->ControllerIndex) )
      {
        v15 = v5->KeyCode;
        if ( v15 == 13 || v15 == 32 )
        {
          if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *))v6->vfptr[88].__vecDelDtor)(v6) )
            goto LABEL_19;
          v16 = (v14->Flags >> 26) & 3;
          if ( v16 == 3 )
            v16 = -1;
          if ( v16 == 1 )
          {
LABEL_19:
            LODWORD(v22) = v5->Id;
            v17 = v5->WcharCode;
            LODWORD(v22) = 1024;
            HIDWORD(v22) = v17;
            v23 = v5->KeyCode;
            v24 = v5->TouchID;
            v25 = *(_DWORD *)&v5->RollOverCnt;
            v18 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr + 4 * (unsigned __int8)v6->AvmObjOffset))[2].__vecDelDtor)((signed __int64)v6 + 4 * (unsigned __int8)v6->AvmObjOffset);
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v18 + 64i64))(v18, &v22);
            v19 = (unsigned __int8)v6->AvmObjOffset;
            LODWORD(v22) = 2048;
            v20 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr + 4 * v19))[2].__vecDelDtor)((signed __int64)v6 + 4 * v19);
            (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v20 + 64i64))(v20, &v22);
          }
        }
      }
      result = (unsigned __int8)v9;
    }
    else
    {
      v21 = (*(__int64 (**)(void))(v7 + 16))();
      result = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v21 + 64i64))(v21, v5);
    }
  }
  return result;
}

// File Line: 1536
// RVA: 0x8C5160
void __fastcall Scaleform::GFx::Sprite::DefaultOnEventLoad(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // rbx

  v1 = this;
  Scaleform::GFx::Sprite::ExecuteFrameTags(this, 0);
  v1->Flags |= 0x20u;
}

// File Line: 1544
// RVA: 0x8ECAC0
void __fastcall Scaleform::GFx::Sprite::OnEventXmlsocketOnxml(Scaleform::GFx::Sprite *this, __int64 a2, __int64 a3)
{
  unsigned __int8 v3; // al
  __int64 v4; // rax
  __int64 v5; // [rsp+20h] [rbp-28h]
  int v6; // [rsp+28h] [rbp-20h]
  char v7; // [rsp+2Ch] [rbp-1Ch]
  int v8; // [rsp+30h] [rbp-18h]

  v3 = this->AvmObjOffset;
  if ( v3 )
  {
    v5 = 16777223i64;
    v6 = 0;
    v7 = 0;
    v8 = 65280;
    v4 = ((__int64 (__cdecl *)(char *, _QWORD, __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr
                                                                                                + 4 * v3))[2].__vecDelDtor)(
           (char *)this + 4 * v3,
           0i64,
           a3);
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v4 + 64i64))(v4, &v5);
  }
}

// File Line: 1559
// RVA: 0x8EC850
void __fastcall Scaleform::GFx::Sprite::OnEventLoadProgress(Scaleform::GFx::Sprite *this, __int64 a2, __int64 a3)
{
  unsigned __int8 v3; // al
  __int64 v4; // rax
  __int64 v5; // [rsp+20h] [rbp-28h]
  int v6; // [rsp+28h] [rbp-20h]
  char v7; // [rsp+2Ch] [rbp-1Ch]
  int v8; // [rsp+30h] [rbp-18h]

  v3 = this->AvmObjOffset;
  if ( v3 )
  {
    v5 = 16777218i64;
    v6 = 0;
    v7 = 0;
    v8 = 65280;
    v4 = ((__int64 (__cdecl *)(char *, _QWORD, __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr
                                                                                                + 4 * v3))[2].__vecDelDtor)(
           (char *)this + 4 * v3,
           0i64,
           a3);
    (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v4 + 64i64))(v4, &v5);
  }
}

// File Line: 1566
// RVA: 0x8F0750
bool __fastcall Scaleform::GFx::Sprite::PointTestLocal(Scaleform::GFx::Sprite *this, Scaleform::Render::Point<float> *pt, char hitTestMask)
{
  char v3; // di
  Scaleform::Render::Point<float> *v4; // rsi
  Scaleform::GFx::Sprite *v5; // rbx
  Scaleform::RefCountNTSImplCoreVtbl *v6; // rax
  float *v7; // rax
  float v8; // xmm0_4
  bool result; // al
  Scaleform::GFx::DrawingContext *v10; // rcx
  char v11; // [rsp+20h] [rbp-38h]
  __int128 v12; // [rsp+30h] [rbp-28h]
  __m128 v13; // [rsp+40h] [rbp-18h]

  v3 = hitTestMask;
  v4 = pt;
  v5 = this;
  result = 0;
  if ( !((this->Flags >> 11) & 1) )
  {
    if ( this->Flags & 1
      || (v6 = this->vfptr,
          v12 = _xmm,
          v13 = _xmm,
          v7 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::Sprite *, char *, __int128 *))v6[61].__vecDelDtor)(
                          this,
                          &v11,
                          &v12),
          v4->x <= v7[2])
      && v4->x >= *v7
      && (v8 = v4->y, v8 <= v7[3])
      && v8 >= v7[1] )
    {
      if ( !(v3 & 2) || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Sprite *))v5->vfptr[59].__vecDelDtor)(v5) )
      {
        if ( Scaleform::GFx::DisplayObjContainer::PointTestLocal(
               (Scaleform::GFx::DisplayObjContainer *)&v5->vfptr,
               v4,
               v3)
          || (v10 = v5->pDrawingAPI.pObject) != 0i64
          && Scaleform::GFx::DrawingContext::DefPointTestLocal(
               v10,
               v4,
               v3 & 1,
               (Scaleform::GFx::DisplayObjectBase *)&v5->vfptr) )
        {
          result = 1;
        }
      }
    }
  }
  return result;
}

// File Line: 1588
// RVA: 0x8ED170
void __fastcall Scaleform::GFx::Sprite::OnGettingKeyboardFocus(Scaleform::GFx::Sprite *this, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 v3; // al
  char v4; // di
  Scaleform::GFx::Sprite *v5; // rbx
  __int64 v6; // rax
  int v7; // eax
  Scaleform::RefCountNTSImplCoreVtbl *v8; // rax
  __int64 v9; // [rsp+20h] [rbp-28h]
  int v10; // [rsp+28h] [rbp-20h]
  char v11; // [rsp+2Ch] [rbp-1Ch]
  char v12; // [rsp+30h] [rbp-18h]
  char v13; // [rsp+31h] [rbp-17h]
  __int16 v14; // [rsp+32h] [rbp-16h]

  if ( fmt == 2 )
  {
    v3 = this->AvmObjOffset;
    v4 = controllerIdx;
    v5 = this;
    if ( v3 )
    {
      v6 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v3))[1].__vecDelDtor)();
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v6 + 96i64))(v6) )
      {
        v7 = (v5->pASRoot->pMovieImpl->Flags >> 28) & 3;
        if ( v7 == 3 )
          v7 = -1;
        if ( v7 != 1 )
        {
          v10 = 0;
          v11 = 0;
          v12 = 0;
          v14 = 0;
          v8 = v5->vfptr;
          v9 = 0x2000i64;
          v13 = v4;
          v8[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)&v9);
        }
      }
    }
  }
}

// File Line: 1596
// RVA: 0x8EE120
char __fastcall Scaleform::GFx::Sprite::OnLosingKeyboardFocus(Scaleform::GFx::Sprite *this, Scaleform::GFx::InteractiveObject *__formal, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt)
{
  __int64 v4; // rdi
  Scaleform::GFx::Sprite *v5; // rbx
  unsigned __int8 v6; // al
  void *v7; // rax
  Scaleform::GFx::MovieImpl *v8; // rdx
  int v9; // eax
  Scaleform::RefCountNTSImplCoreVtbl *v10; // rax
  __int64 v12; // [rsp+20h] [rbp-28h]
  int v13; // [rsp+28h] [rbp-20h]
  char v14; // [rsp+2Ch] [rbp-1Ch]
  char v15; // [rsp+30h] [rbp-18h]
  char v16; // [rsp+31h] [rbp-17h]
  __int16 v17; // [rsp+32h] [rbp-16h]

  v4 = controllerIdx;
  v5 = this;
  if ( fmt == 2 )
  {
    v6 = this->AvmObjOffset;
    if ( v6 )
    {
      v7 = (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v6))[1].__vecDelDtor(
             (Scaleform::RefCountNTSImplCore *)((char *)this + 4 * v6),
             (unsigned int)__formal);
      if ( (*(unsigned __int8 (__fastcall **)(void *))(*(_QWORD *)v7 + 96i64))(v7) )
      {
        v8 = v5->pASRoot->pMovieImpl;
        if ( v8->FocusGroups[(unsigned __int8)v8->FocusGroupIndexes[v4]].FocusRectShown )
        {
          v9 = (v8->Flags >> 28) & 3;
          if ( v9 == 3 )
            v9 = -1;
          if ( v9 != 1 )
          {
            v13 = 0;
            v14 = 0;
            v15 = 0;
            v17 = 0;
            v10 = v5->vfptr;
            v12 = 0x4000i64;
            v16 = v4;
            v10[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)&v12);
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
  unsigned __int64 v1; // rsi
  Scaleform::GFx::Sprite *v2; // r14
  char v3; // bp
  __int64 v4; // rdi
  Scaleform::GFx::InteractiveObject *v5; // rbx
  __int64 v6; // rdx
  int v7; // eax

  v1 = this->mDisplayList.DisplayObjectArray.Data.Size;
  v2 = this;
  v3 = (this->Flags >> 3) & 1;
  if ( v1 )
  {
    v4 = 0i64;
    do
    {
      v5 = 0i64;
      if ( SLOBYTE(v2->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter->Flags) < 0 )
        v5 = (Scaleform::GFx::InteractiveObject *)v2->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter;
      if ( v5 )
      {
        if ( (v2->Flags >> 3) & 1 || v3 )
          v5->Flags |= 8u;
        else
          v5->Flags &= 0xFFFFFFF7;
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v5->vfptr[104].__vecDelDtor)(v5);
        if ( !((v5->Flags >> 21) & 1) || (v5->Flags >> 22) & 1 )
          v6 = 0i64;
        else
          LOBYTE(v6) = 1;
        v7 = (__int64)v5->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, v6);
        if ( v7 == -1 )
        {
          v5->Flags |= 0x400000u;
        }
        else if ( v7 == 1 )
        {
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v5);
        }
      }
      ++v4;
      --v1;
    }
    while ( v1 );
  }
}

// File Line: 1621
// RVA: 0x8F49D0
void __fastcall Scaleform::GFx::Sprite::PropagateNoAdvanceLocalFlag(Scaleform::GFx::Sprite *this)
{
  unsigned __int64 v1; // rsi
  Scaleform::GFx::Sprite *v2; // r14
  char v3; // bp
  __int64 v4; // rdi
  Scaleform::GFx::InteractiveObject *v5; // rbx
  __int64 v6; // rdx
  int v7; // eax

  v1 = this->mDisplayList.DisplayObjectArray.Data.Size;
  v2 = this;
  v3 = (this->Flags >> 2) & 1;
  if ( v1 )
  {
    v4 = 0i64;
    do
    {
      v5 = 0i64;
      if ( SLOBYTE(v2->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter->Flags) < 0 )
        v5 = (Scaleform::GFx::InteractiveObject *)v2->mDisplayList.DisplayObjectArray.Data.Data[v4].pCharacter;
      if ( v5 )
      {
        if ( (v2->Flags >> 2) & 1 || v3 )
          v5->Flags |= 4u;
        else
          v5->Flags &= 0xFFFFFFFB;
        ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v5->vfptr[105].__vecDelDtor)(v5);
        if ( !((v5->Flags >> 21) & 1) || (v5->Flags >> 22) & 1 )
          v6 = 0i64;
        else
          LOBYTE(v6) = 1;
        v7 = (__int64)v5->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, v6);
        if ( v7 == -1 )
        {
          v5->Flags |= 0x400000u;
        }
        else if ( v7 == 1 )
        {
          Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v5);
        }
      }
      ++v4;
      --v1;
    }
    while ( v1 );
  }
}

// File Line: 1636
// RVA: 0x90F170
void __fastcall Scaleform::GFx::Sprite::SetVisible(Scaleform::GFx::Sprite *this, bool visible)
{
  Scaleform::GFx::Sprite *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rcx
  char v4; // dl
  unsigned int v5; // ecx
  unsigned int v6; // ecx
  Scaleform::Render::TreeNode *v7; // rax
  bool v8; // dl
  int v9; // eax

  v2 = this;
  if ( visible )
  {
    this->Flags |= 0x4000u;
    v3 = this->pRenNode.pObject;
    if ( v3 )
      Scaleform::Render::TreeNode::SetVisible(v3, visible);
    goto LABEL_4;
  }
  this->Flags &= 0xBFFFu;
  v7 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  Scaleform::Render::TreeNode::SetVisible(v7, 0);
  if ( !((v2->pASRoot->pMovieImpl->Flags >> 11) & 1) )
  {
LABEL_4:
    v4 = 0;
    goto LABEL_5;
  }
  v4 = 1;
LABEL_5:
  v5 = v2->Flags;
  if ( v4 == ((v2->Flags >> 3) & 1) )
    return;
  if ( v4 )
    v6 = v5 | 8;
  else
    v6 = v5 & 0xFFFFFFF7;
  v2->Flags = v6;
  v8 = (v6 >> 21) & 1 && !((v6 >> 22) & 1);
  v9 = Scaleform::GFx::Sprite::CheckAdvanceStatus(v2, v8);
  if ( v9 == -1 )
  {
    v2->Flags |= 0x400000u;
  }
  else if ( v9 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)&v2->vfptr);
    ((void (__fastcall *)(Scaleform::GFx::Sprite *))v2->vfptr[104].__vecDelDtor)(v2);
    return;
  }
  ((void (__fastcall *)(Scaleform::GFx::Sprite *))v2->vfptr[104].__vecDelDtor)(v2);
}

// File Line: 1652
// RVA: 0x8D7150
Scaleform::GFx::DrawingContext *__fastcall Scaleform::GFx::Sprite::GetDrawingContext(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // rbx
  Scaleform::GFx::DisplayObject *v2; // rdi
  Scaleform::GFx::DrawingContext *v3; // rsi
  Scaleform::RefCountNTSImpl *v4; // rcx
  Scaleform::Render::TreeContainer *v5; // rax

  v1 = this;
  if ( this->pDrawingAPI.pObject )
    return this->pDrawingAPI.pObject;
  if ( !this->pMaskCharacter
    || ((unsigned __int8 (__cdecl *)(Scaleform::GFx::Sprite *))this->vfptr[78].__vecDelDtor)(this) )
  {
    v2 = 0i64;
  }
  else
  {
    v2 = v1->pMaskCharacter;
    if ( v2 )
      ++v2->RefCount;
  }
  if ( v2 )
    Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)&v1->vfptr, 0i64, 1);
  v3 = Scaleform::GFx::MovieImpl::CreateDrawingContext(v1->pASRoot->pMovieImpl);
  v4 = (Scaleform::RefCountNTSImpl *)&v1->pDrawingAPI.pObject->vfptr;
  if ( v4 )
    Scaleform::RefCountNTSImpl::Release(v4);
  v1->pDrawingAPI.pObject = v3;
  v5 = Scaleform::GFx::DisplayObjectBase::ConvertToTreeContainer((Scaleform::GFx::DisplayObjectBase *)&v1->vfptr);
  Scaleform::Render::TreeContainer::Insert(
    v5,
    0i64,
    (Scaleform::Render::TreeNode *)&v1->pDrawingAPI.pObject->pTreeContainer.pObject->0);
  if ( v2 )
    Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)&v1->vfptr, v2, 1);
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v2->vfptr);
  return v1->pDrawingAPI.pObject;
}

// File Line: 1676
// RVA: 0x8DD620
Scaleform::Render::TreeContainer *__fastcall Scaleform::GFx::Sprite::GetRenderContainer(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::Sprite *v1; // rbx
  Scaleform::Render::TreeContainer *result; // rax
  _QWORD *v3; // rax

  v1 = this;
  result = (Scaleform::Render::TreeContainer *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  if ( v1->pDrawingAPI.pObject )
  {
    v3 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)result & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                              + 8
                              * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&result[-1] - ((unsigned __int64)result & 0xFFFFFFFFFFFFF000ui64))
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                               + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&result[-1]
                                                                                        - ((unsigned __int64)result & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                              + 40)
                  + 144i64);
    if ( *(_BYTE *)v3 & 1 )
      v3 = (_QWORD *)((*v3 & 0xFFFFFFFFFFFFFFFEui64) + 16);
    result = (Scaleform::Render::TreeContainer *)v3[1];
  }
  return result;
}

// File Line: 1689
// RVA: 0x907C70
void __fastcall Scaleform::GFx::Sprite::SetHitArea(Scaleform::GFx::Sprite *this, Scaleform::GFx::Sprite *phitArea)
{
  Scaleform::GFx::Sprite *v2; // rbp
  Scaleform::GFx::Sprite *v3; // rdi
  __int64 v4; // rax
  Scaleform::GFx::CharacterHandle *v5; // rsi
  Scaleform::GFx::CharacterHandle *v6; // rbx
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::CharacterHandle *v11; // rbx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  unsigned __int8 v15; // al
  __int64 v16; // rax

  v2 = phitArea;
  v3 = this;
  v4 = ((__int64 (__cdecl *)(Scaleform::GFx::Sprite *))this->vfptr[120].__vecDelDtor)(this);
  if ( v4 )
    *(_QWORD *)(v4 + 304) = 0i64;
  if ( v2 )
  {
    v5 = v2->pNameHandle.pObject;
    if ( v5
      || (v5 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v2->vfptr)) != 0i64 )
    {
      ++v5->RefCount;
    }
    v6 = v3->pHitAreaHandle.pObject;
    if ( v6 )
    {
      if ( --v6->RefCount <= 0 )
      {
        v7 = v6->OriginalName.pNode;
        v8 = v7->RefCount-- == 1;
        if ( v8 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v7);
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
    v3->pHitAreaHandle.pObject = v5;
    v2->pHitAreaHolder = v3;
  }
  else
  {
    v11 = v3->pHitAreaHandle.pObject;
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
    v3->pHitAreaHandle.pObject = 0i64;
  }
  v15 = v3->AvmObjOffset;
  if ( v15 )
  {
    v16 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * v15))[2].__vecDelDtor)();
    (*(void (__fastcall **)(__int64, Scaleform::GFx::Sprite *))(*(_QWORD *)v16 + 264i64))(v16, v2);
  }
}

// File Line: 1708
// RVA: 0x8D9B00
Scaleform::GFx::Sprite *__fastcall Scaleform::GFx::Sprite::GetHitArea(Scaleform::GFx::Sprite *this)
{
  Scaleform::GFx::CharacterHandle *v1; // r8
  Scaleform::GFx::Sprite *v2; // rdx
  Scaleform::GFx::ASMovieRootBase *v3; // rcx
  Scaleform::GFx::Sprite *result; // rax

  v1 = this->pHitAreaHandle.pObject;
  if ( !v1 )
    return 0i64;
  v2 = (Scaleform::GFx::Sprite *)v1->pCharacter;
  if ( !v2 )
  {
    v3 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v2 = (Scaleform::GFx::Sprite *)v3->vfptr[8].__vecDelDtor(
                                     (Scaleform::RefCountImplCore *)&v3->vfptr,
                                     (unsigned int)&v1->NamePath);
    if ( !v2 )
      return 0i64;
  }
  result = 0i64;
  if ( (v2->Flags >> 10) & 1 )
    result = v2;
  return result;
}

// File Line: 1719
// RVA: 0x909B00
void __fastcall Scaleform::GFx::Sprite::SetName(Scaleform::GFx::Sprite *this, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::Sprite *v2; // rbx

  v2 = this;
  Scaleform::GFx::DisplayObject::SetName((Scaleform::GFx::DisplayObject *)&this->vfptr, name);
  v2->mDisplayList.pCachedChar = 0i64;
}

// File Line: 1726
// RVA: 0x8E7120
char __fastcall Scaleform::GFx::Sprite::IsFocusEnabled(Scaleform::GFx::Sprite *this, Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::GFx::FocusMovedType v2; // ebx
  unsigned __int8 v3; // al
  __int64 v4; // rax
  char result; // al
  char v6; // dl
  unsigned __int8 v7; // al
  __int64 v8; // rax
  unsigned __int8 v9; // al
  __int64 v10; // rax

  v2 = fmt;
  if ( fmt == 1 )
  {
    v3 = this->AvmObjOffset;
    if ( v3 )
    {
      v4 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v3))[1].__vecDelDtor)();
      result = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 160i64))(v4, (unsigned int)v2);
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    v6 = this->FocusEnabled.Value;
    if ( v6 || (v7 = this->AvmObjOffset) == 0 )
    {
      if ( v6 == 2 )
      {
        v9 = this->AvmObjOffset;
        if ( v9 )
        {
          v10 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v9))[1].__vecDelDtor)();
          result = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v10 + 96i64))(v10);
        }
        else
        {
          result = 0;
        }
      }
      else
      {
        result = v6 == 1;
      }
    }
    else
    {
      v8 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v7))[2].__vecDelDtor)();
      result = (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v8 + 160i64))(v8, (unsigned int)v2);
    }
  }
  return result;
}

