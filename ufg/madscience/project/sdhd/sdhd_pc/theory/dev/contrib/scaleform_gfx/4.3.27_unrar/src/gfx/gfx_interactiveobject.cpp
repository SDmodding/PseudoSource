// File Line: 39
// RVA: 0x897DB0
void __fastcall Scaleform::GFx::InteractiveObject::InteractiveObject(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::MovieDefImpl *pbindingDefImpl, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::InteractiveObject *pparent, Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::MovieDefImpl *v5; // rsi
  Scaleform::GFx::InteractiveObject *v6; // rdi

  v5 = pbindingDefImpl;
  v6 = this;
  id.Id = **(_DWORD **)&id.Id;
  Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(
    (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
    pasRoot,
    pparent,
    (__int64)&id);
  v6->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  v6->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  v6->pNameHandle.pObject = 0i64;
  v6->pScrollRect = 0i64;
  v6->pMaskCharacter = 0i64;
  v6->Flags |= 0x100u;
  v6->Flags = 10;
  v6->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::InteractiveObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  v6->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::InteractiveObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( v5 )
    _InterlockedExchangeAdd(&v5->RefCount.Value, 1u);
  v6->pDefImpl.pObject = v5;
  *(_QWORD *)&v6->Flags = 16i64;
  v6->RollOverCnt = 0;
  v6->pDisplayCallback = 0i64;
  v6->DisplayCallbackUserPtr = 0i64;
  v6->Flags |= 0x80u;
  v6->pPlayPrev = 0i64;
  v6->pPlayNext = 0i64;
  v6->pPlayPrevOpt = 0i64;
  v6->pPlayNextOpt = 0i64;
}

// File Line: 49
// RVA: 0x8A5010
void __fastcall Scaleform::GFx::InteractiveObject::~InteractiveObject(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rdi
  Scaleform::GFx::MovieDefImpl *v2; // rbx
  Scaleform::GFx::ResourceLibBase *v3; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::InteractiveObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::InteractiveObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this);
  v2 = v1->pDefImpl.pObject;
  if ( v2 && !_InterlockedDecrement(&v2->RefCount.Value) )
  {
    v3 = v2->pLib;
    if ( v3 )
    {
      v3->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, (unsigned int)v2);
      v2->pLib = 0i64;
    }
    v2->vfptr->__vecDelDtor((Scaleform::GFx::Resource *)&v2->vfptr, 1u);
  }
  Scaleform::GFx::DisplayObject::~DisplayObject((Scaleform::GFx::DisplayObject *)&v1->vfptr);
}

// File Line: 54
// RVA: 0x8C2920
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::InteractiveObject::CreateRenderNode(Scaleform::GFx::InteractiveObject *this, Scaleform::Ptr<Scaleform::Render::TreeNode> *result, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v3; // rbx
  Scaleform::Render::ContextImpl::Entry *v4; // rax
  bool v5; // zf

  v3 = result;
  v4 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(context);
  if ( v4 )
    ++v4->RefCount;
  v3->pObject = (Scaleform::Render::TreeNode *)v4;
  if ( v4 )
  {
    v5 = v4->RefCount-- == 1;
    if ( v5 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
  return v3;
}

// File Line: 60
// RVA: 0x8DD610
Scaleform::Render::TreeNode *__fastcall Scaleform::GFx::InteractiveObject::GetRenderContainer(Scaleform::GFx::InteractiveObject *this)
{
  return Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
}

// File Line: 72
// RVA: 0x909B20
void __fastcall Scaleform::GFx::InteractiveObject::SetNextUnloaded(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::InteractiveObject *punlObj)
{
  this->Flags |= 0x10u;
  this->pPlayNextOpt = punlObj;
}

// File Line: 84
// RVA: 0x8EC9D0
void __fastcall Scaleform::GFx::InteractiveObject::OnEventUnload(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rbx
  Scaleform::GFx::MovieImpl *v2; // rdi
  Scaleform::GFx::CharacterHandle *v3; // rax
  unsigned __int8 v4; // al

  v1 = this;
  this->Flags |= 0x1000u;
  v2 = this->pASRoot->pMovieImpl;
  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this);
  Scaleform::GFx::MovieImpl::StopDragCharacter(v2, v1);
  if ( v2 )
    Scaleform::GFx::MovieImpl::ResetFocusForChar(v2, v1);
  Scaleform::GFx::DisplayObjectBase::OnEventUnload((Scaleform::GFx::DisplayObjectBase *)&v1->vfptr);
  v3 = v1->pNameHandle.pObject;
  if ( v3 )
    v3->pCharacter = 0i64;
  v4 = v1->AvmObjOffset;
  if ( v4 )
    ((void (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr + 4 * v4))[10].__vecDelDtor)((signed __int64)v1 + 4 * v4);
}

// File Line: 111
// RVA: 0x8E7360
bool __fastcall Scaleform::GFx::InteractiveObject::IsInPlayList(Scaleform::GFx::InteractiveObject *this)
{
  return *(_OWORD *)&this->pPlayNext != 0i64 || this->pASRoot->pMovieImpl->pPlayListHead == this;
}

// File Line: 116
// RVA: 0x8B33F0
void __fastcall Scaleform::GFx::InteractiveObject::AddToPlayList(Scaleform::GFx::InteractiveObject *this)
{
  unsigned __int16 v1; // dx
  Scaleform::GFx::MovieImpl *v2; // rdx
  Scaleform::GFx::InteractiveObject *v3; // rax

  v1 = this->Flags;
  if ( !(((unsigned __int8)v1 >> 4) & 1) && !(v1 & 0x1000) && this->Depth >= -1 )
  {
    v2 = this->pASRoot->pMovieImpl;
    v3 = v2->pPlayListHead;
    if ( v3 )
    {
      v3->pPlayPrev = this;
      this->pPlayNext = v2->pPlayListHead;
    }
    v2->pPlayListHead = this;
  }
}

// File Line: 140
// RVA: 0x8E6A70
void __fastcall Scaleform::GFx::InteractiveObject::InsertToPlayListAfter(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::InteractiveObject *pafterCh)
{
  unsigned __int16 v2; // r8
  Scaleform::GFx::InteractiveObject *v3; // rax

  v2 = this->Flags;
  if ( !(((unsigned __int8)v2 >> 4) & 1) && !(v2 & 0x1000) && this->Depth >= -1 )
  {
    this->pPlayPrev = pafterCh;
    this->pPlayNext = pafterCh->pPlayNext;
    pafterCh->pPlayNext = this;
    v3 = this->pPlayNext;
    if ( v3 )
      v3->pPlayPrev = this;
  }
}

// File Line: 167
// RVA: 0x8B3290
void __fastcall Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::ASMovieRootBase *v1; // rax
  Scaleform::GFx::InteractiveObject *v2; // rbx
  unsigned int v3; // ecx
  Scaleform::GFx::MovieImpl *v4; // rdi
  unsigned __int16 v5; // cx
  Scaleform::GFx::InteractiveObject *v6; // rcx
  Scaleform::GFx::InteractiveObject *v7; // rax
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  Scaleform::GFx::InteractiveObject *v10; // rax

  v1 = this->pASRoot;
  v2 = this;
  v3 = this->Flags;
  v4 = v1->pMovieImpl;
  if ( (v3 >> 21) & 1 || (v4->Flags >> 19) & 1 )
  {
    v2->Flags = v3 & 0xFFBFFFFF;
  }
  else
  {
    v5 = v2->Flags;
    if ( !(((unsigned __int8)v5 >> 4) & 1)
      && !(v5 & 0x1000)
      && v2->Depth >= -1
      && Scaleform::GFx::InteractiveObject::IsInPlayList(v2) )
    {
      v6 = v2->pPlayPrev;
      if ( v6 )
      {
        while ( !((v6->Flags >> 21) & 1)
             || ((unsigned __int8)(v6->Flags >> 23) ^ (unsigned __int8)(v4->Flags2 >> 3)) & 1 )
        {
          v6 = v6->pPlayPrev;
          if ( !v6 )
            goto LABEL_11;
        }
        v10 = v6->pPlayNextOpt;
        v2->pPlayPrevOpt = v6;
        v2->pPlayNextOpt = v10;
        if ( v10 )
          v10->pPlayPrevOpt = v2;
        v6->pPlayNextOpt = v2;
      }
      else
      {
LABEL_11:
        v7 = v4->pPlayListOptHead;
        v2->pPlayPrevOpt = 0i64;
        v2->pPlayNextOpt = v7;
        if ( v7 )
          v7->pPlayPrevOpt = v2;
        v4->pPlayListOptHead = v2;
      }
      v2->Flags |= 0x200000u;
      v8 = v2->Flags;
      if ( (v4->Flags2 >> 3) & 1 )
        v9 = v8 | 0x800000;
      else
        v9 = v8 & 0xFF7FFFFF;
      v2->Flags = v9;
      v2->Flags &= 0xFFBFFFFF;
    }
  }
}

// File Line: 213
// RVA: 0x8FF440
void __fastcall Scaleform::GFx::InteractiveObject::RemoveFromPlayList(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::MovieImpl *v1; // rdx
  Scaleform::GFx::InteractiveObject *v2; // r8
  Scaleform::GFx::InteractiveObject *v3; // rax
  Scaleform::GFx::InteractiveObject *v4; // r8
  Scaleform::GFx::InteractiveObject *v5; // r8
  Scaleform::GFx::InteractiveObject *v6; // r8

  v1 = this->pASRoot->pMovieImpl;
  if ( (this->Flags >> 21) & 1 )
  {
    if ( !((v1->Flags >> 19) & 1) && !(((unsigned __int8)(this->Flags >> 23) ^ (unsigned __int8)(v1->Flags2 >> 3)) & 1) )
    {
      v2 = this->pPlayPrevOpt;
      v3 = this->pPlayNextOpt;
      if ( v2 )
        v2->pPlayNextOpt = v3;
      else
        v1->pPlayListOptHead = v3;
      v4 = this->pPlayNextOpt;
      if ( v4 )
        v4->pPlayPrevOpt = this->pPlayPrevOpt;
    }
    this->Flags &= 0xFF9FFFFF;
    this->pPlayPrevOpt = 0i64;
    this->pPlayNextOpt = 0i64;
  }
  v5 = this->pPlayNext;
  if ( v5 )
    v5->pPlayPrev = this->pPlayPrev;
  v6 = this->pPlayPrev;
  if ( v6 )
  {
    v6->pPlayNext = this->pPlayNext;
    this->pPlayPrev = 0i64;
    this->pPlayNext = 0i64;
  }
  else
  {
    if ( v1->pPlayListHead == this )
      v1->pPlayListHead = this->pPlayNext;
    this->pPlayPrev = 0i64;
    this->pPlayNext = 0i64;
  }
}

// File Line: 231
// RVA: 0x8FF3A0
void __fastcall Scaleform::GFx::InteractiveObject::RemoveFromOptimizedPlayList(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::MovieImpl *v1; // r8
  Scaleform::GFx::InteractiveObject *v2; // rdx
  Scaleform::GFx::InteractiveObject *v3; // rax
  Scaleform::GFx::InteractiveObject *v4; // rdx

  v1 = this->pASRoot->pMovieImpl;
  if ( (this->Flags >> 21) & 1 )
  {
    if ( !((v1->Flags >> 19) & 1) && !(((unsigned __int8)(this->Flags >> 23) ^ (unsigned __int8)(v1->Flags2 >> 3)) & 1) )
    {
      v2 = this->pPlayPrevOpt;
      v3 = this->pPlayNextOpt;
      if ( v2 )
        v2->pPlayNextOpt = v3;
      else
        v1->pPlayListOptHead = v3;
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
void __fastcall Scaleform::GFx::InteractiveObject::CloneInternalData(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::InteractiveObject *src)
{
  Scaleform::GFx::InteractiveObject *v2; // rdi
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v3; // rdx
  Scaleform::GFx::InteractiveObject *v4; // rbx
  unsigned __int8 v5; // al
  __int64 v6; // rax

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
}

// File Line: 271
// RVA: 0x8C7910
void __fastcall Scaleform::GFx::InteractiveObject::DoMouseDrag(Scaleform::GFx::InteractiveObject *this, unsigned int mouseIndex)
{
  Scaleform::GFx::InteractiveObject *v2; // rbx
  Scaleform::GFx::MovieImpl *v3; // r8
  bool v4; // si
  float v5; // xmm12_4
  float v6; // xmm13_4
  float v7; // xmm11_4
  float v8; // xmm14_4
  signed __int64 v9; // rax
  Scaleform::GFx::InteractiveObject *v10; // rdi
  int v11; // xmm15_4
  Scaleform::GFx::DisplayObjectBase *v12; // rcx
  float *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm9_4
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // xmm8_4
  float v21; // xmm10_4
  float v22; // xmm5_4
  float v23; // xmm7_4
  float v24; // xmm6_4
  float v25; // xmm8_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  float *v29; // rax
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+20h] [rbp-81h]
  float v31; // [rsp+40h] [rbp-61h]
  float v32; // [rsp+44h] [rbp-5Dh]
  float v33; // [rsp+108h] [rbp+67h]
  int vars0; // [rsp+110h] [rbp+6Fh]
  float retaddr; // [rsp+118h] [rbp+77h]

  v2 = this;
  v3 = this->pASRoot->pMovieImpl;
  v4 = v3->CurrentDragStates[mouseIndex].Bound;
  v5 = v3->CurrentDragStates[mouseIndex].BoundLT.x;
  v6 = v3->CurrentDragStates[mouseIndex].BoundLT.y;
  v7 = v3->CurrentDragStates[mouseIndex].BoundRB.x;
  v8 = v3->CurrentDragStates[mouseIndex].BoundRB.y;
  v33 = v3->CurrentDragStates[mouseIndex].CenterDelta.x;
  retaddr = v3->CurrentDragStates[mouseIndex].CenterDelta.y;
  if ( this == v3->CurrentDragStates[mouseIndex].pCharacter )
  {
    if ( mouseIndex < 6 )
      v9 = (signed __int64)&v3->mMouseState[mouseIndex];
    else
      v9 = 0i64;
    v10 = this->pParent;
    v11 = *(_DWORD *)(v9 + 56);
    vars0 = *(_DWORD *)(v9 + 60);
    *(__m128 *)&pmat.M[1][0] = _xmm;
    *(_OWORD *)&pmat.M[0][0] = _xmm;
    if ( v10 )
    {
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      v12 = v10->pParentChar;
      if ( v12 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v12, &pmat);
        v13 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v10->vfptr[2].__vecDelDtor)(v10);
        v15 = pmat.M[0][1];
        v14 = pmat.M[0][0];
        v16 = pmat.M[1][0];
        v17 = 0.0;
        v18 = pmat.M[0][0];
        v19 = pmat.M[1][1];
        v20 = pmat.M[1][0];
        v21 = 0.0;
        v22 = (float)(pmat.M[0][0] * *v13) + (float)(pmat.M[0][1] * v13[4]);
        pmat.M[0][0] = (float)(pmat.M[0][0] * *v13) + (float)(pmat.M[0][1] * v13[4]);
        v23 = (float)(pmat.M[1][0] * *v13) + (float)(pmat.M[1][1] * v13[4]);
        pmat.M[1][0] = (float)(pmat.M[1][0] * *v13) + (float)(pmat.M[1][1] * v13[4]);
        v24 = (float)(v18 * v13[1]) + (float)(pmat.M[0][1] * v13[5]);
        *(_QWORD *)&pmat.M[0][1] = LODWORD(v24);
        v25 = (float)(v20 * v13[1]) + (float)(pmat.M[1][1] * v13[5]);
        *(_QWORD *)&pmat.M[1][1] = LODWORD(v25);
        v26 = (float)(v15 * v13[7]) + (float)(v14 * v13[3]);
        v27 = pmat.M[0][3] + v26;
        pmat.M[0][3] = pmat.M[0][3] + v26;
        v28 = v24 + (float)((float)(v19 * v13[7]) + (float)(v16 * v13[3]));
      }
      else
      {
        v29 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v10->vfptr[2].__vecDelDtor)(v10);
        v22 = *v29;
        pmat.M[0][0] = *v29;
        v24 = v29[1];
        pmat.M[0][1] = v29[1];
        v21 = v29[2];
        pmat.M[0][2] = v29[2];
        v27 = v29[3];
        pmat.M[0][3] = v29[3];
        v23 = v29[4];
        pmat.M[1][0] = v29[4];
        v25 = v29[5];
        pmat.M[1][1] = v29[5];
        v17 = v29[6];
        pmat.M[1][2] = v29[6];
        v28 = v29[7];
      }
    }
    else
    {
      v28 = pmat.M[0][1];
      v17 = pmat.M[1][2];
      v25 = pmat.M[1][1];
      v23 = pmat.M[1][0];
      v27 = pmat.M[0][3];
      v21 = pmat.M[0][2];
      v24 = pmat.M[0][1];
      v22 = pmat.M[0][0];
    }
    *(_QWORD *)&pmat.M[0][0] = __PAIR__(LODWORD(v28), LODWORD(v22));
    *(_QWORD *)&pmat.M[0][2] = __PAIR__(LODWORD(v24), LODWORD(v22));
    *(_QWORD *)&pmat.M[1][0] = __PAIR__(LODWORD(v27), LODWORD(v21));
    *(_QWORD *)&pmat.M[1][2] = __PAIR__(LODWORD(v25), LODWORD(v23));
    v31 = v17;
    v32 = v28;
    Scaleform::Render::Matrix2x4<float>::SetInverse(&pmat, (Scaleform::Render::Matrix2x4<float> *)((char *)&pmat + 8));
    v2->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 0);
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[21].__vecDelDtor)(v2);
    ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[23].__vecDelDtor)(v2);
  }
}

// File Line: 313
// RVA: 0x8BE350
void __fastcall Scaleform::GFx::InteractiveObject::CopyPhysicalProperties(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::InteractiveObject *poldChar)
{
  Scaleform::GFx::InteractiveObject *v2; // rdi
  Scaleform::GFx::InteractiveObject *v3; // rsi
  Scaleform::Render::TreeNode *v4; // rcx
  Scaleform::Render::Cxform *v5; // rbx
  Scaleform::Render::TreeNode *v6; // rax
  Scaleform::Render::ContextImpl::EntryData *v7; // rax
  Scaleform::Render::TreeNode *v8; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *v9; // rbx
  __int64 v10; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v11; // rbx
  __int64 v12; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v13; // rdx
  __int64 v14; // rax
  unsigned __int8 v15; // al
  __int64 v16; // rax

  v2 = this;
  v3 = poldChar;
  this->Depth = poldChar->Depth;
  v4 = poldChar->pRenNode.pObject;
  if ( v4 )
    v5 = (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                 + 8
                                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1] - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1] - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                 + 40)
                                     + 80i64);
  else
    v5 = &Scaleform::Render::Cxform::Identity;
  v6 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr);
  v7 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v6->0, 2u);
  v7[5] = *(Scaleform::Render::ContextImpl::EntryData *)&v5->M[0][0];
  v7[6] = *(Scaleform::Render::ContextImpl::EntryData *)&v5->M[1][0];
  v8 = v2->pRenNode.pObject;
  if ( v8
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v8[-1] - ((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v8[-1]
                                                                                       - ((unsigned __int64)v8 & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) >> 9) & 1 )
  {
    v9 = v2->vfptr;
    v10 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v3->vfptr[4].__vecDelDtor)(v3);
    v9[5].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, v10);
  }
  else
  {
    v11 = v2->vfptr;
    v12 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v3->vfptr[2].__vecDelDtor)(v3);
    v11[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, v12);
  }
  v13 = v3->pGeomData;
  if ( v13 )
    Scaleform::GFx::DisplayObjectBase::SetGeomData((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr, v13);
  v14 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v3->vfptr[57].__vecDelDtor)(v3);
  if ( v14 )
    v2->vfptr[56].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, v14);
  v15 = v2->AvmObjOffset;
  if ( v15 )
  {
    v16 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v2->vfptr + 4 * v15))[1].__vecDelDtor)((signed __int64)v2 + 4 * v15);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::InteractiveObject *))(*(_QWORD *)v16 + 120i64))(v16, v3);
  }
}

// File Line: 333
// RVA: 0x8EBAB0
void __fastcall Scaleform::GFx::InteractiveObject::MoveNameHandle(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::InteractiveObject *poldChar)
{
  Scaleform::GFx::InteractiveObject *v2; // rsi
  Scaleform::GFx::InteractiveObject *v3; // rdi
  Scaleform::GFx::CharacterHandle *v4; // rax
  Scaleform::GFx::CharacterHandle *v5; // rbx
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::CharacterHandle *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::CharacterHandle *v14; // rax

  v2 = poldChar;
  v3 = this;
  v4 = poldChar->pNameHandle.pObject;
  if ( v4 )
    ++v4->RefCount;
  v5 = this->pNameHandle.pObject;
  if ( v5 )
  {
    if ( --v5->RefCount <= 0 )
    {
      v6 = v5->OriginalName.pNode;
      v7 = v6->RefCount-- == 1;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
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
  v3->pNameHandle.pObject = v2->pNameHandle.pObject;
  v10 = v2->pNameHandle.pObject;
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
  v2->pNameHandle.pObject = 0i64;
  v14 = v3->pNameHandle.pObject;
  if ( v14 )
    v14->pCharacter = (Scaleform::GFx::DisplayObject *)&v3->vfptr;
}

// File Line: 342
// RVA: 0x8E7220
char __fastcall Scaleform::GFx::InteractiveObject::IsFocusRectEnabled(Scaleform::GFx::InteractiveObject *this, __int64 a2)
{
  Scaleform::GFx::InteractiveObject *v2; // rbx
  unsigned int v3; // ecx
  char result; // al
  __int64 v5; // rax

  v2 = this;
  v3 = this->Flags & 0x180;
  if ( v3 )
    return v3 == 384;
  LOBYTE(a2) = 1;
  v5 = (__int64)v2->vfptr[68].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, a2);
  if ( v5 && (Scaleform::GFx::InteractiveObject *)v5 != v2 )
    result = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v5 + 704i64))(v5);
  else
    result = 1;
  return result;
}

// File Line: 355
// RVA: 0x8ECB10
void __fastcall Scaleform::GFx::InteractiveObject::OnFocus(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::InteractiveObject::FocusEventType *event, Scaleform::GFx::InteractiveObject *oldOrNewFocusCh, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 v5; // al
  unsigned int v6; // ebx
  Scaleform::GFx::InteractiveObject *v7; // rdi
  unsigned int v8; // esi
  __int64 v9; // rax
  Scaleform::GFx::FocusMovedType v10; // ST20_4

  v5 = this->AvmObjOffset;
  v6 = controllerIdx;
  v7 = oldOrNewFocusCh;
  v8 = (unsigned int)event;
  if ( v5 )
  {
    v9 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v5))[1].__vecDelDtor)();
    v10 = fmt;
    (*(void (__fastcall **)(__int64, _QWORD, Scaleform::GFx::InteractiveObject *, _QWORD, Scaleform::GFx::FocusMovedType))(*(_QWORD *)v9 + 128i64))(
      v9,
      v8,
      v7,
      v6,
      v10);
  }
}

// File Line: 361
// RVA: 0x8E78B0
bool __fastcall Scaleform::GFx::InteractiveObject::IsTabable(Scaleform::GFx::InteractiveObject *this)
{
  unsigned __int8 v1; // al
  __int64 v2; // rax

  v1 = this->AvmObjOffset;
  if ( !v1 )
    return 0;
  v2 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v1))[1].__vecDelDtor)();
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 168i64))(v2);
}

// File Line: 368
// RVA: 0x8DE610
Scaleform::GFx::ASStringManager *__fastcall Scaleform::GFx::InteractiveObject::GetStringManager(Scaleform::GFx::InteractiveObject *this)
{
  return (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))this->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
}

// File Line: 373
// RVA: 0x8D6680
__int64 __fastcall Scaleform::GFx::InteractiveObject::GetCursorType(Scaleform::GFx::InteractiveObject *this)
{
  unsigned __int8 v1; // al
  __int64 v2; // rax

  v1 = this->AvmObjOffset;
  if ( !v1 )
    return 0i64;
  v2 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v1))[1].__vecDelDtor)();
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v2 + 104i64))(v2);
}

// File Line: 387
// RVA: 0x8FF300
void __fastcall Scaleform::GFx::InteractiveObject::RemoveDisplayObject(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::InteractiveObject *v1; // r8
  Scaleform::GFx::InteractiveObject *v2; // rcx
  Scaleform::GFx::InteractiveObject *v3; // rdx
  unsigned int v4; // eax
  int v5; // er8
  Scaleform::GFx::ResourceId id; // [rsp+30h] [rbp+8h]

  v1 = this;
  v2 = this->pParent;
  if ( v2 )
  {
    v3 = 0i64;
    if ( (v2->Flags >> 9) & 1 )
      v3 = v2;
    if ( v3 )
    {
      v4 = v1->Id.Id;
      v5 = v1->Depth;
      id.Id = v4;
      Scaleform::GFx::DisplayList::RemoveDisplayObject(
        (Scaleform::GFx::DisplayList *)&v3[1],
        (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr,
        v5,
        (__int64)&id);
    }
  }
}

// File Line: 405
// RVA: 0x8D81A0
__int64 __fastcall Scaleform::GFx::InteractiveObject::GetFocusGroupMask(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rbx
  Scaleform::GFx::InteractiveObject *v2; // rcx

  v1 = this;
  if ( this->FocusGroupMask )
    return this->FocusGroupMask;
  v2 = this->pParent;
  if ( v2 )
    v1->FocusGroupMask = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(v2);
  return v1->FocusGroupMask;
}

// File Line: 412
// RVA: 0x8E6FA0
unsigned __int8 __fastcall Scaleform::GFx::InteractiveObject::IsFocusAllowed(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::MovieImpl *proot, unsigned int controllerIdx)
{
  unsigned int v3; // edi
  unsigned __int16 v4; // ax
  Scaleform::GFx::InteractiveObject *v5; // rbx
  Scaleform::GFx::InteractiveObject *v6; // rcx
  int v7; // ecx

  v3 = (unsigned __int8)proot->FocusGroupIndexes[controllerIdx];
  v4 = this->FocusGroupMask;
  if ( !v4 )
  {
    v5 = this->pParent;
    if ( !v5->FocusGroupMask )
    {
      v6 = v5->pParent;
      if ( v6 )
        v5->FocusGroupMask = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(v6);
    }
    v4 = v5->FocusGroupMask;
  }
  v7 = v4;
  return _bittest(&v7, v3);
}

// File Line: 418
// RVA: 0x8E6F50
unsigned __int8 __fastcall Scaleform::GFx::InteractiveObject::IsFocusAllowed(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::MovieImpl *proot, unsigned int controllerIdx)
{
  Scaleform::GFx::InteractiveObject *v3; // rbx
  unsigned int v4; // edi
  Scaleform::GFx::InteractiveObject *v5; // rcx
  int v6; // ecx

  v3 = this;
  v4 = (unsigned __int8)proot->FocusGroupIndexes[controllerIdx];
  if ( !this->FocusGroupMask )
  {
    v5 = this->pParent;
    if ( v5 )
      v3->FocusGroupMask = Scaleform::GFx::InteractiveObject::GetFocusGroupMask(v5);
  }
  v6 = v3->FocusGroupMask;
  return _bittest(&v6, v4);
}

// File Line: 424
// RVA: 0x8E70E0
char __fastcall Scaleform::GFx::InteractiveObject::IsFocusEnabled(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::FocusMovedType fmt)
{
  unsigned __int8 v2; // al
  Scaleform::GFx::FocusMovedType v3; // ebx
  __int64 v4; // rax

  v2 = this->AvmObjOffset;
  v3 = fmt;
  if ( !v2 )
    return 1;
  v4 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v2))[1].__vecDelDtor)();
  return (*(__int64 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v4 + 160i64))(v4, (unsigned int)v3);
}

