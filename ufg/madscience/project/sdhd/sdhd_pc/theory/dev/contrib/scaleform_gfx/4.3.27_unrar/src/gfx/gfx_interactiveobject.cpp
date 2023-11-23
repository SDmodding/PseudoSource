// File Line: 39
// RVA: 0x897DB0
void __fastcall Scaleform::GFx::InteractiveObject::InteractiveObject(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        _DWORD *id)
{
  LODWORD(id) = *id;
  Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(this, pasRoot, pparent, (unsigned int *)&id);
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObject::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObject::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  this->pNameHandle.pObject = 0i64;
  this->pScrollRect = 0i64;
  this->pMaskCharacter = 0i64;
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x100u;
  this->Scaleform::GFx::DisplayObject::Flags = 10;
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::InteractiveObject::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::InteractiveObject::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  if ( pbindingDefImpl )
    _InterlockedExchangeAdd(&pbindingDefImpl->RefCount.Value, 1u);
  this->pDefImpl.pObject = pbindingDefImpl;
  *(_QWORD *)&this->Flags = 16i64;
  this->RollOverCnt = 0;
  this->pDisplayCallback = 0i64;
  this->DisplayCallbackUserPtr = 0i64;
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x80u;
  this->pPlayPrev = 0i64;
  this->pPlayNext = 0i64;
  this->pPlayPrevOpt = 0i64;
  this->pPlayNextOpt = 0i64;
}

// File Line: 49
// RVA: 0x8A5010
void __fastcall Scaleform::GFx::InteractiveObject::~InteractiveObject(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::MovieDefImpl *pObject; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::InteractiveObject::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::InteractiveObject::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this);
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
  Scaleform::GFx::DisplayObject::~DisplayObject(this);
}

// File Line: 54
// RVA: 0x8C2920
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::InteractiveObject::CreateRenderNode(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeContainer *v4; // rax

  v4 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(context);
  if ( v4 )
    ++v4->RefCount;
  result->pObject = v4;
  if ( v4 )
  {
    if ( v4->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
  return result;
}

// File Line: 60
// RVA: 0x8DD610
// attributes: thunk
Scaleform::Render::TreeContainer *__fastcall Scaleform::GFx::InteractiveObject::GetRenderContainer(
        Scaleform::GFx::InteractiveObject *this)
{
  return (Scaleform::Render::TreeContainer *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
}

// File Line: 72
// RVA: 0x909B20
void __fastcall Scaleform::GFx::InteractiveObject::SetNextUnloaded(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::InteractiveObject *punlObj)
{
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x10u;
  this->pPlayNextOpt = punlObj;
}

// File Line: 84
// RVA: 0x8EC9D0
void __fastcall Scaleform::GFx::InteractiveObject::OnEventUnload(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdi
  Scaleform::GFx::CharacterHandle *pObject; // rax
  unsigned __int8 AvmObjOffset; // al

  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x1000u;
  pMovieImpl = this->pASRoot->pMovieImpl;
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this);
  Scaleform::GFx::MovieImpl::StopDragCharacter(pMovieImpl, this);
  if ( pMovieImpl )
    Scaleform::GFx::MovieImpl::ResetFocusForChar(pMovieImpl, this);
  Scaleform::GFx::DisplayObjectBase::OnEventUnload(this);
  pObject = this->pNameHandle.pObject;
  if ( pObject )
    pObject->pCharacter = 0i64;
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    ((void (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                          + 4 * AvmObjOffset))[10].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
}

// File Line: 111
// RVA: 0x8E7360
bool __fastcall Scaleform::GFx::InteractiveObject::IsInPlayList(Scaleform::GFx::InteractiveObject *this)
{
  return this->pPlayNext || this->pPlayPrev || this->pASRoot->pMovieImpl->pPlayListHead == this;
}

// File Line: 116
// RVA: 0x8B33F0
void __fastcall Scaleform::GFx::InteractiveObject::AddToPlayList(Scaleform::GFx::InteractiveObject *this)
{
  unsigned __int16 Flags; // dx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  Scaleform::GFx::InteractiveObject *pPlayListHead; // rax

  Flags = this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
  if ( (Flags & 0x10) == 0 && (Flags & 0x1000) == 0 && this->Depth >= -1 )
  {
    pMovieImpl = this->pASRoot->pMovieImpl;
    pPlayListHead = pMovieImpl->pPlayListHead;
    if ( pPlayListHead )
    {
      pPlayListHead->pPlayPrev = this;
      this->pPlayNext = pMovieImpl->pPlayListHead;
    }
    pMovieImpl->pPlayListHead = this;
  }
}

// File Line: 140
// RVA: 0x8E6A70
void __fastcall Scaleform::GFx::InteractiveObject::InsertToPlayListAfter(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::InteractiveObject *pafterCh)
{
  unsigned __int16 Flags; // r8
  Scaleform::GFx::InteractiveObject *pPlayNext; // rax

  Flags = this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
  if ( (Flags & 0x10) == 0 && (Flags & 0x1000) == 0 && this->Depth >= -1 )
  {
    this->pPlayPrev = pafterCh;
    this->pPlayNext = pafterCh->pPlayNext;
    pafterCh->pPlayNext = this;
    pPlayNext = this->pPlayNext;
    if ( pPlayNext )
      pPlayNext->pPlayPrev = this;
  }
}

// File Line: 167
// RVA: 0x8B3290
void __fastcall Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rax
  unsigned int Flags; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdi
  unsigned __int16 v5; // cx
  Scaleform::GFx::InteractiveObject *pPlayPrev; // rcx
  Scaleform::GFx::InteractiveObject *pPlayListOptHead; // rax
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  Scaleform::GFx::InteractiveObject *pPlayNextOpt; // rax

  pASRoot = this->pASRoot;
  Flags = this->Flags;
  pMovieImpl = pASRoot->pMovieImpl;
  if ( (Flags & 0x200000) != 0 || (pMovieImpl->Flags & 0x80000) != 0 )
  {
    this->Flags = Flags & 0xFFBFFFFF;
  }
  else
  {
    v5 = this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
    if ( (v5 & 0x10) == 0
      && (v5 & 0x1000) == 0
      && this->Depth >= -1
      && Scaleform::GFx::InteractiveObject::IsInPlayList(this) )
    {
      pPlayPrev = this->pPlayPrev;
      if ( pPlayPrev )
      {
        while ( (pPlayPrev->Flags & 0x200000) == 0
             || (((unsigned __int8)(pPlayPrev->Flags >> 23) ^ (unsigned __int8)(pMovieImpl->Flags2 >> 3)) & 1) != 0 )
        {
          pPlayPrev = pPlayPrev->pPlayPrev;
          if ( !pPlayPrev )
            goto LABEL_11;
        }
        pPlayNextOpt = pPlayPrev->pPlayNextOpt;
        this->pPlayPrevOpt = pPlayPrev;
        this->pPlayNextOpt = pPlayNextOpt;
        if ( pPlayNextOpt )
          pPlayNextOpt->pPlayPrevOpt = this;
        pPlayPrev->pPlayNextOpt = this;
      }
      else
      {
LABEL_11:
        pPlayListOptHead = pMovieImpl->pPlayListOptHead;
        this->pPlayPrevOpt = 0i64;
        this->pPlayNextOpt = pPlayListOptHead;
        if ( pPlayListOptHead )
          pPlayListOptHead->pPlayPrevOpt = this;
        pMovieImpl->pPlayListOptHead = this;
      }
      this->Flags |= 0x200000u;
      v8 = this->Flags;
      if ( (pMovieImpl->Flags2 & 8) != 0 )
        v9 = v8 | 0x800000;
      else
        v9 = v8 & 0xFF7FFFFF;
      this->Flags = v9;
      this->Flags &= ~0x400000u;
    }
  }
}

// File Line: 213
// RVA: 0x8FF440
void __fastcall Scaleform::GFx::InteractiveObject::RemoveFromPlayList(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  Scaleform::GFx::InteractiveObject *pPlayPrevOpt; // r8
  Scaleform::GFx::InteractiveObject *pPlayNextOpt; // rax
  Scaleform::GFx::InteractiveObject *v4; // r8
  Scaleform::GFx::InteractiveObject *pPlayNext; // r8
  Scaleform::GFx::InteractiveObject *pPlayPrev; // r8

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( (this->Flags & 0x200000) != 0 )
  {
    if ( (pMovieImpl->Flags & 0x80000) == 0
      && (((unsigned __int8)(this->Flags >> 23) ^ (unsigned __int8)(pMovieImpl->Flags2 >> 3)) & 1) == 0 )
    {
      pPlayPrevOpt = this->pPlayPrevOpt;
      pPlayNextOpt = this->pPlayNextOpt;
      if ( pPlayPrevOpt )
        pPlayPrevOpt->pPlayNextOpt = pPlayNextOpt;
      else
        pMovieImpl->pPlayListOptHead = pPlayNextOpt;
      v4 = this->pPlayNextOpt;
      if ( v4 )
        v4->pPlayPrevOpt = this->pPlayPrevOpt;
    }
    this->Flags &= 0xFF9FFFFF;
    this->pPlayPrevOpt = 0i64;
    this->pPlayNextOpt = 0i64;
  }
  pPlayNext = this->pPlayNext;
  if ( pPlayNext )
    pPlayNext->pPlayPrev = this->pPlayPrev;
  pPlayPrev = this->pPlayPrev;
  if ( pPlayPrev )
  {
    pPlayPrev->pPlayNext = this->pPlayNext;
    this->pPlayPrev = 0i64;
    this->pPlayNext = 0i64;
  }
  else
  {
    if ( pMovieImpl->pPlayListHead == this )
      pMovieImpl->pPlayListHead = this->pPlayNext;
    this->pPlayPrev = 0i64;
    this->pPlayNext = 0i64;
  }
}

// File Line: 231
// RVA: 0x8FF3A0
void __fastcall Scaleform::GFx::InteractiveObject::RemoveFromOptimizedPlayList(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  Scaleform::GFx::InteractiveObject *pPlayPrevOpt; // rdx
  Scaleform::GFx::InteractiveObject *pPlayNextOpt; // rax
  Scaleform::GFx::InteractiveObject *v4; // rdx

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( (this->Flags & 0x200000) != 0 )
  {
    if ( (pMovieImpl->Flags & 0x80000) == 0
      && (((unsigned __int8)(this->Flags >> 23) ^ (unsigned __int8)(pMovieImpl->Flags2 >> 3)) & 1) == 0 )
    {
      pPlayPrevOpt = this->pPlayPrevOpt;
      pPlayNextOpt = this->pPlayNextOpt;
      if ( pPlayPrevOpt )
        pPlayPrevOpt->pPlayNextOpt = pPlayNextOpt;
      else
        pMovieImpl->pPlayListOptHead = pPlayNextOpt;
      v4 = this->pPlayNextOpt;
      if ( v4 )
        v4->pPlayPrevOpt = this->pPlayPrevOpt;
    }
    this->Flags &= 0xFF9FFFFF;
    this->pPlayPrevOpt = 0i64;
    this->pPlayNextOpt = 0i64;
  }
}

// File Line: 261
// RVA: 0x8BD0E0
void __fastcall Scaleform::GFx::InteractiveObject::CloneInternalData(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::InteractiveObject *src)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rdx
  unsigned __int8 AvmObjOffset; // al
  __int64 v6; // rax

  pGeomData = src->pGeomData;
  if ( pGeomData )
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, pGeomData);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v6 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v6 + 112i64))(v6, src);
  }
}

// File Line: 271
// RVA: 0x8C7910
void __fastcall Scaleform::GFx::InteractiveObject::DoMouseDrag(
        Scaleform::GFx::InteractiveObject *this,
        unsigned int mouseIndex)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  Scaleform::GFx::MouseState *v4; // rax
  Scaleform::GFx::InteractiveObject *pParent; // rdi
  Scaleform::GFx::DisplayObjectBase *v6; // rcx
  float *v7; // rax
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm3_4
  float v11; // xmm9_4
  float v12; // xmm6_4
  float v13; // xmm4_4
  float v14; // xmm8_4
  float v15; // xmm10_4
  float v16; // xmm5_4
  float v17; // xmm7_4
  float v18; // xmm6_4
  float v19; // xmm8_4
  float v20; // xmm0_4
  float v21; // xmm1_4
  float *v22; // rax
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+20h] [rbp-81h] BYREF
  float v24; // [rsp+40h] [rbp-61h]
  float v25; // [rsp+44h] [rbp-5Dh]
  float x; // [rsp+108h] [rbp+67h]
  float y; // [rsp+110h] [rbp+6Fh]
  void *retaddr; // [rsp+118h] [rbp+77h]

  pMovieImpl = this->pASRoot->pMovieImpl;
  x = pMovieImpl->CurrentDragStates[mouseIndex].CenterDelta.x;
  *(float *)&retaddr = pMovieImpl->CurrentDragStates[mouseIndex].CenterDelta.y;
  if ( this == pMovieImpl->CurrentDragStates[mouseIndex].pCharacter )
  {
    if ( mouseIndex < 6 )
      v4 = &pMovieImpl->mMouseState[mouseIndex];
    else
      v4 = 0i64;
    pParent = this->pParent;
    y = v4->LastPosition.y;
    *(__m128 *)&pmat.M[1][0] = _xmm;
    *(_OWORD *)&pmat.M[0][0] = _xmm;
    if ( pParent )
    {
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      v6 = pParent->pParent;
      if ( v6 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v6, &pmat);
        v7 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pParent);
        v8 = pmat.M[0][0];
        v9 = pmat.M[0][1];
        v10 = pmat.M[1][0];
        v11 = 0.0;
        v12 = pmat.M[0][0];
        v13 = pmat.M[1][1];
        v14 = pmat.M[1][0];
        v15 = 0.0;
        v16 = (float)(pmat.M[0][0] * *v7) + (float)(pmat.M[0][1] * v7[4]);
        pmat.M[0][0] = v16;
        v17 = (float)(pmat.M[1][0] * *v7) + (float)(pmat.M[1][1] * v7[4]);
        pmat.M[1][0] = v17;
        v18 = (float)(v12 * v7[1]) + (float)(pmat.M[0][1] * v7[5]);
        *(_QWORD *)&pmat.M[0][1] = LODWORD(v18);
        v19 = (float)(v14 * v7[1]) + (float)(pmat.M[1][1] * v7[5]);
        *(_QWORD *)&pmat.M[1][1] = LODWORD(v19);
        v20 = pmat.M[0][3] + (float)((float)(v9 * v7[7]) + (float)(v8 * v7[3]));
        pmat.M[0][3] = v20;
        v21 = v18 + (float)((float)(v13 * v7[7]) + (float)(v10 * v7[3]));
      }
      else
      {
        v22 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pParent);
        v16 = *v22;
        pmat.M[0][0] = *v22;
        v18 = v22[1];
        pmat.M[0][1] = v18;
        v15 = v22[2];
        pmat.M[0][2] = v15;
        v20 = v22[3];
        pmat.M[0][3] = v20;
        v17 = v22[4];
        pmat.M[1][0] = v17;
        v19 = v22[5];
        pmat.M[1][1] = v19;
        v11 = v22[6];
        pmat.M[1][2] = v11;
        v21 = v22[7];
      }
    }
    else
    {
      v21 = pmat.M[0][1];
      v11 = pmat.M[1][2];
      v19 = pmat.M[1][1];
      v17 = pmat.M[1][0];
      v20 = pmat.M[0][3];
      v15 = pmat.M[0][2];
      v18 = pmat.M[0][1];
      v16 = pmat.M[0][0];
    }
    *(_QWORD *)&pmat.M[0][0] = __PAIR64__(LODWORD(v21), LODWORD(v16));
    *(_QWORD *)&pmat.M[0][2] = __PAIR64__(LODWORD(v18), LODWORD(v16));
    *(_QWORD *)&pmat.M[1][0] = __PAIR64__(LODWORD(v20), LODWORD(v15));
    *(_QWORD *)&pmat.M[1][2] = __PAIR64__(LODWORD(v19), LODWORD(v17));
    v24 = v11;
    v25 = v21;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&pmat, (Scaleform::Render::Matrix2x4<float> *)&pmat.M[0][2]);
    this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      this,
      0);
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[21].__vecDelDtor)(this);
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[23].__vecDelDtor)(this);
  }
}

// File Line: 313
// RVA: 0x8BE350
void __fastcall Scaleform::GFx::InteractiveObject::CopyPhysicalProperties(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::InteractiveObject *poldChar)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::Render::Cxform *v5; // rbx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::TreeNode *v8; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rbx
  __int64 v10; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v11; // rbx
  __int64 v12; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rdx
  __int64 v14; // rax
  unsigned __int8 AvmObjOffset; // al
  __int64 v16; // rax

  this->Depth = poldChar->Depth;
  pObject = poldChar->pRenNode.pObject;
  if ( pObject )
    v5 = (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64)
                                                             + 0x20)
                                                 + 8i64
                                                 * (unsigned int)((int)((_DWORD)pObject
                                                                      - ((unsigned int)pObject & 0xFFFFF000)
                                                                      - 56)
                                                                / 56)
                                                 + 40)
                                     + 80i64);
  else
    v5 = &Scaleform::Render::Cxform::Identity;
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 2u);
  WritableData[5] = *(Scaleform::Render::ContextImpl::EntryData *)&v5->M[0][0];
  WritableData[6] = *(Scaleform::Render::ContextImpl::EntryData *)&v5->M[1][0];
  v8 = this->pRenNode.pObject;
  if ( v8
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)v8 - ((unsigned int)v8 & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x200) != 0 )
  {
    vfptr = this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v10 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))poldChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(poldChar);
    vfptr[5].__vecDelDtor(this, v10);
  }
  else
  {
    v11 = this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v12 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))poldChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(poldChar);
    v11[3].__vecDelDtor(this, v12);
  }
  pGeomData = poldChar->pGeomData;
  if ( pGeomData )
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, pGeomData);
  v14 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))poldChar->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[57].__vecDelDtor)(poldChar);
  if ( v14 )
    this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[56].__vecDelDtor(
      this,
      v14);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v16 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v16 + 120i64))(v16, poldChar);
  }
}

// File Line: 333
// RVA: 0x8EBAB0
void __fastcall Scaleform::GFx::InteractiveObject::MoveNameHandle(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::InteractiveObject *poldChar)
{
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::CharacterHandle *v5; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::CharacterHandle *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::CharacterHandle *v14; // rax

  pObject = poldChar->pNameHandle.pObject;
  if ( pObject )
    ++pObject->RefCount;
  v5 = this->pNameHandle.pObject;
  if ( v5 )
  {
    if ( --v5->RefCount <= 0 )
    {
      pNode = v5->OriginalName.pNode;
      v7 = pNode->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v8 = v5->NamePath.pNode;
      v7 = v8->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v8);
      v9 = v5->Name.pNode;
      v7 = v9->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v5);
    }
  }
  this->pNameHandle.pObject = poldChar->pNameHandle.pObject;
  v10 = poldChar->pNameHandle.pObject;
  if ( v10 )
  {
    if ( --v10->RefCount <= 0 )
    {
      v11 = v10->OriginalName.pNode;
      v7 = v11->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      v12 = v10->NamePath.pNode;
      v7 = v12->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v13 = v10->Name.pNode;
      v7 = v13->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
    }
  }
  poldChar->pNameHandle.pObject = 0i64;
  v14 = this->pNameHandle.pObject;
  if ( v14 )
    v14->pCharacter = this;
}

// File Line: 342
// RVA: 0x8E7220
char __fastcall Scaleform::GFx::InteractiveObject::IsFocusRectEnabled(
        Scaleform::GFx::InteractiveObject *this,
        __int64 a2)
{
  unsigned int v3; // ecx
  Scaleform::GFx::InteractiveObject *v5; // rax

  v3 = this->Flags & 0x180;
  if ( v3 )
    return v3 == 384;
  LOBYTE(a2) = 1;
  v5 = (Scaleform::GFx::InteractiveObject *)this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
                                              this,
                                              a2);
  if ( !v5 || v5 == this )
    return 1;
  else
    return ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v5->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[88].__vecDelDtor)(v5);
}

// File Line: 355
// RVA: 0x8ECB10
void __fastcall Scaleform::GFx::InteractiveObject::OnFocus(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::InteractiveObject::FocusEventType *event,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 AvmObjOffset; // al
  unsigned int v8; // esi
  __int64 v9; // rax

  AvmObjOffset = this->AvmObjOffset;
  v8 = (unsigned int)event;
  if ( AvmObjOffset )
  {
    v9 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, _QWORD, Scaleform::GFx::InteractiveObject *, _QWORD, Scaleform::GFx::FocusMovedType))(*(_QWORD *)v9 + 128i64))(
      v9,
      v8,
      oldOrNewFocusCh,
      controllerIdx,
      fmt);
  }
}

// File Line: 361
// RVA: 0x8E78B0
bool __fastcall Scaleform::GFx::InteractiveObject::IsTabable(Scaleform::GFx::InteractiveObject *this)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v2; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0;
  v2 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 168i64))(v2);
}

// File Line: 368
// RVA: 0x8DE610
Scaleform::GFx::ASStringManager *__fastcall Scaleform::GFx::InteractiveObject::GetStringManager(
        Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx

  pObject = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  return (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
}

// File Line: 373
// RVA: 0x8D6680
__int64 __fastcall Scaleform::GFx::InteractiveObject::GetCursorType(Scaleform::GFx::InteractiveObject *this)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v2; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 0i64;
  v2 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 104i64))(v2);
}

// File Line: 387
// RVA: 0x8FF300
void __fastcall Scaleform::GFx::InteractiveObject::RemoveDisplayObject(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::GFx::InteractiveObject *v3; // rdx
  unsigned int v4; // eax
  int Depth; // r8d
  Scaleform::GFx::ResourceId id; // [rsp+30h] [rbp+8h] BYREF

  pParent = this->pParent;
  if ( pParent )
  {
    v3 = 0i64;
    if ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x200) != 0 )
      v3 = pParent;
    if ( v3 )
    {
      v4 = this->Id.Id;
      Depth = this->Depth;
      id.Id = v4;
      Scaleform::GFx::DisplayList::RemoveDisplayObject((Scaleform::GFx::DisplayList *)&v3[1], v3, Depth, (int *)&id);
    }
  }
}

// File Line: 405
// RVA: 0x8D81A0
__int64 __fastcall Scaleform::GFx::InteractiveObject::GetFocusGroupMask(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx

  if ( this->FocusGroupMask )
    return this->FocusGroupMask;
  pParent = this->pParent;
  if ( pParent )
    this->FocusGroupMask = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(pParent);
  return this->FocusGroupMask;
}

// File Line: 412
// RVA: 0x8E6FA0
unsigned __int8 __fastcall Scaleform::GFx::InteractiveObject::IsFocusAllowed(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::MovieImpl *proot,
        unsigned int controllerIdx)
{
  unsigned int v3; // edi
  unsigned __int16 FocusGroupMask; // ax
  Scaleform::GFx::InteractiveObject *pParent; // rbx
  Scaleform::GFx::InteractiveObject *v6; // rcx
  int v7; // ecx

  v3 = (unsigned __int8)proot->FocusGroupIndexes[controllerIdx];
  FocusGroupMask = this->FocusGroupMask;
  if ( !FocusGroupMask )
  {
    pParent = this->pParent;
    if ( !pParent->FocusGroupMask )
    {
      v6 = pParent->pParent;
      if ( v6 )
        pParent->FocusGroupMask = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(v6);
    }
    FocusGroupMask = pParent->FocusGroupMask;
  }
  v7 = FocusGroupMask;
  return _bittest(&v7, v3);
}

// File Line: 418
// RVA: 0x8E6F50
unsigned __int8 __fastcall Scaleform::GFx::InteractiveObject::IsFocusAllowed(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::MovieImpl *proot,
        unsigned int controllerIdx)
{
  unsigned int v4; // edi
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  int FocusGroupMask; // ecx

  v4 = (unsigned __int8)proot->FocusGroupIndexes[controllerIdx];
  if ( !this->FocusGroupMask )
  {
    pParent = this->pParent;
    if ( pParent )
      this->FocusGroupMask = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(pParent);
  }
  FocusGroupMask = this->FocusGroupMask;
  return _bittest(&FocusGroupMask, v4);
}

// File Line: 424
// RVA: 0x8E70E0
char __fastcall Scaleform::GFx::InteractiveObject::IsFocusEnabled(
        Scaleform::GFx::InteractiveObject *this,
        unsigned int fmt)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v4; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( !AvmObjOffset )
    return 1;
  v4 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                + 4 * AvmObjOffset))[1].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  return (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 160i64))(v4, fmt);
}

