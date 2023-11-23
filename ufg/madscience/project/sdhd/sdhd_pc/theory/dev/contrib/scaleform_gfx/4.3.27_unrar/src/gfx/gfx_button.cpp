// File Line: 120
// RVA: 0x894D40
void __fastcall Scaleform::GFx::Button::Button(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::ButtonDef *def,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *parent,
        _DWORD *id)
{
  Scaleform::GFx::Scale9Grid *pScale9Grid; // rax
  float y2; // xmm3_4
  float x2; // xmm2_4
  float y1; // xmm1_4
  Scaleform::Render::Rect<float> rect; // [rsp+40h] [rbp-18h] BYREF

  LODWORD(id) = *id;
  Scaleform::GFx::InteractiveObject::InteractiveObject(
    this,
    pbindingDefImpl,
    pasRoot,
    parent,
    (Scaleform::GFx::ResourceId)&id);
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::Button::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::Button::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  this->pDef = def;
  `eh vector constructor iterator(
    this->States,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Scaleform::GFx::Button::StateCharacters::StateCharacters);
  *(_QWORD *)&this->LastMouseFlags = 0i64;
  this->MouseState = MouseUp;
  pScale9Grid = def->pScale9Grid;
  if ( pScale9Grid )
  {
    y2 = pScale9Grid->Rect.y2;
    x2 = pScale9Grid->Rect.x2;
    y1 = pScale9Grid->Rect.y1;
    rect.x1 = pScale9Grid->Rect.x1;
    rect.y1 = y1;
    rect.x2 = x2;
    rect.y2 = y2;
  }
  else
  {
    rect = 0i64;
  }
  Scaleform::GFx::DisplayObjContainer::SetScale9Grid((Scaleform::GFx::DisplayObjContainer *)this, &rect);
  if ( this->pDef->Menu )
    this->Scaleform::GFx::InteractiveObject::Flags |= 0x4000u;
  else
    this->Scaleform::GFx::InteractiveObject::Flags &= ~0x4000u;
}

// File Line: 139
// RVA: 0x90B520
void __fastcall Scaleform::GFx::DisplayObjContainer::SetScale9Grid(
        Scaleform::GFx::DisplayObjContainer *this,
        Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::State *State; // rax
  bool v6; // si
  Scaleform::Render::TreeNode *v7; // rax
  float v8[6]; // [rsp+20h] [rbp-18h]

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  State = Scaleform::Render::TreeNode::GetState(RenderNode, State_Scale9);
  if ( State )
    *(_OWORD *)v8 = *(_OWORD *)(State->DataValue + 16);
  else
    *(_OWORD *)v8 = 0i64;
  v6 = v8[0] != rect->x1 || v8[2] != rect->x2 || v8[1] != rect->y1 || v8[3] != rect->y2;
  v7 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::SetScale9Grid(v7, rect);
  if ( rect->x2 <= rect->x1 || rect->y2 <= rect->y1 )
    this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags &= ~1u;
  else
    this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 1u;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[20].__vecDelDtor)(this);
}

// File Line: 148
// RVA: 0x8F4AD0
void __fastcall Scaleform::GFx::Button::PropagateScale9GridExists(Scaleform::GFx::Button *this)
{
  bool HasScale9Grid; // al
  bool v3; // r14
  unsigned __int64 *p_Size; // rsi
  __int64 v5; // r15
  unsigned __int64 v6; // rbx
  __int64 v7; // rdi
  __int64 v8; // rdx
  _WORD *v9; // rcx

  HasScale9Grid = Scaleform::GFx::DisplayObjectBase::HasScale9Grid(this);
  v3 = HasScale9Grid;
  if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 1) != 0
    || !HasScale9Grid )
  {
    p_Size = &this->States[0].Characters.Data.Size;
    v5 = 4i64;
    do
    {
      v6 = 0i64;
      if ( *p_Size )
      {
        v7 = 0i64;
        do
        {
          v8 = *(_QWORD *)(v7 + *(p_Size - 1));
          if ( v8 )
          {
            v9 = 0i64;
            if ( *(char *)(v8 + 106) < 0 )
              v9 = *(_WORD **)(v7 + *(p_Size - 1));
            if ( v9 )
            {
              if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 1) != 0
                || v3 )
              {
                v9[53] |= 1u;
              }
              else
              {
                v9[53] &= ~1u;
              }
              (*(void (__fastcall **)(_WORD *))(*(_QWORD *)v9 + 160i64))(v9);
            }
          }
          ++v6;
          v7 += 16i64;
        }
        while ( v6 < *p_Size );
      }
      p_Size += 4;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 173
// RVA: 0x8F4650
void __fastcall Scaleform::GFx::Button::PropagateNoAdvanceGlobalFlag(Scaleform::GFx::Button *this)
{
  bool v2; // r14
  unsigned __int64 *p_Size; // rbp
  __int64 v4; // r12
  unsigned __int64 v5; // rdi
  __int64 v6; // rsi
  __int64 v7; // rcx
  Scaleform::GFx::InteractiveObject *v8; // rbx
  __int64 v9; // rdx
  unsigned int Flags; // ecx
  int v11; // eax

  v2 = (this->Scaleform::GFx::InteractiveObject::Flags & 8) != 0;
  if ( this->pASRoot->pMovieImpl )
  {
    p_Size = &this->States[0].Characters.Data.Size;
    v4 = 4i64;
    do
    {
      v5 = 0i64;
      if ( *p_Size )
      {
        v6 = 0i64;
        do
        {
          v7 = *(_QWORD *)(v6 + *(p_Size - 1));
          if ( v7 )
          {
            v8 = 0i64;
            if ( *(char *)(v7 + 106) < 0 )
              v8 = *(Scaleform::GFx::InteractiveObject **)(v6 + *(p_Size - 1));
            if ( v8 )
            {
              if ( (this->Scaleform::GFx::InteractiveObject::Flags & 8) != 0 || v2 )
                v8->Flags |= 8u;
              else
                v8->Flags &= ~8u;
              ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[104].__vecDelDtor)(v8);
              Flags = v8->Flags;
              if ( (Flags & 0x200000) == 0 || (Flags & 0x400000) != 0 )
                v9 = 0i64;
              else
                LOBYTE(v9) = 1;
              v11 = (int)v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
                           v8,
                           v9);
              if ( v11 == -1 )
              {
                v8->Flags |= 0x400000u;
              }
              else if ( v11 == 1 )
              {
                Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v8);
              }
            }
          }
          ++v5;
          v6 += 16i64;
        }
        while ( v5 < *p_Size );
      }
      p_Size += 4;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 199
// RVA: 0x8F4890
void __fastcall Scaleform::GFx::Button::PropagateNoAdvanceLocalFlag(Scaleform::GFx::Button *this)
{
  bool v2; // r14
  unsigned __int64 *p_Size; // rbp
  __int64 v4; // r12
  unsigned __int64 v5; // rdi
  __int64 v6; // rsi
  __int64 v7; // rcx
  Scaleform::GFx::InteractiveObject *v8; // rbx
  __int64 v9; // rdx
  unsigned int Flags; // ecx
  int v11; // eax

  v2 = (this->Scaleform::GFx::InteractiveObject::Flags & 4) != 0;
  if ( this->pASRoot->pMovieImpl )
  {
    p_Size = &this->States[0].Characters.Data.Size;
    v4 = 4i64;
    do
    {
      v5 = 0i64;
      if ( *p_Size )
      {
        v6 = 0i64;
        do
        {
          v7 = *(_QWORD *)(v6 + *(p_Size - 1));
          if ( v7 )
          {
            v8 = 0i64;
            if ( *(char *)(v7 + 106) < 0 )
              v8 = *(Scaleform::GFx::InteractiveObject **)(v6 + *(p_Size - 1));
            if ( v8 )
            {
              if ( (this->Scaleform::GFx::InteractiveObject::Flags & 4) != 0 || v2 )
                v8->Flags |= 4u;
              else
                v8->Flags &= ~4u;
              ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[105].__vecDelDtor)(v8);
              Flags = v8->Flags;
              if ( (Flags & 0x200000) == 0 || (Flags & 0x400000) != 0 )
                v9 = 0i64;
              else
                LOBYTE(v9) = 1;
              v11 = (int)v8->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
                           v8,
                           v9);
              if ( v11 == -1 )
              {
                v8->Flags |= 0x400000u;
              }
              else if ( v11 == 1 )
              {
                Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v8);
              }
            }
          }
          ++v5;
          v6 += 16i64;
        }
        while ( v5 < *p_Size );
      }
      p_Size += 4;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 225
// RVA: 0x90F080
void __fastcall Scaleform::GFx::Button::SetVisible(Scaleform::GFx::Button *this, bool visible)
{
  bool v2; // di
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  bool v7; // dl
  unsigned int Flags; // ecx
  unsigned int v9; // ecx
  Scaleform::GFx::InteractiveObject *pParent; // rax

  v2 = visible;
  if ( visible )
  {
    this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x4000u;
    pObject = this->pRenNode.pObject;
    if ( !pObject )
      goto LABEL_6;
  }
  else
  {
    this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags &= ~0x4000u;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    visible = 0;
    pObject = RenderNode;
  }
  Scaleform::Render::TreeNode::SetVisible(pObject, visible);
LABEL_6:
  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( pMovieImpl )
  {
    v7 = !v2 && (pMovieImpl->Flags & 0x800) != 0;
    Flags = this->Scaleform::GFx::InteractiveObject::Flags;
    if ( v7 != ((Flags & 8) != 0) )
    {
      if ( v7 )
        v9 = Flags | 8;
      else
        v9 = Flags & 0xFFFFFFF7;
      this->Scaleform::GFx::InteractiveObject::Flags = v9;
      Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Button>(this);
      pParent = this->pParent;
      if ( pParent )
      {
        if ( (pParent->Flags & 8) == 0 )
          ((void (__fastcall *)(Scaleform::GFx::Button *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[104].__vecDelDtor)(this);
      }
    }
  }
}

// File Line: 243
// RVA: 0x904250
void __fastcall Scaleform::GFx::Button::Restart(Scaleform::GFx::Button *this)
{
  Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *p_Characters; // rsi
  __int64 v2; // rbp
  unsigned __int64 v3; // rbx
  __int64 v4; // rdi
  Scaleform::GFx::DisplayObjectBase *pObject; // rcx

  *(_QWORD *)&this->LastMouseFlags = 0i64;
  this->MouseState = MouseUp;
  this->RollOverCnt = 0;
  p_Characters = &this->States[0].Characters;
  v2 = 4i64;
  do
  {
    v3 = 0i64;
    if ( p_Characters->Data.Size )
    {
      v4 = 0i64;
      do
      {
        pObject = p_Characters->Data.Data[v4].Char.pObject;
        if ( pObject )
          ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pObject->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[70].__vecDelDtor)(pObject);
        ++v3;
        ++v4;
      }
      while ( v3 < p_Characters->Data.Size );
    }
    p_Characters = (Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *)((char *)p_Characters + 32);
    --v2;
  }
  while ( v2 );
}

// File Line: 277
// RVA: 0x8EC6D0
void __fastcall Scaleform::GFx::Button::OnEventLoad(Scaleform::GFx::Button *this)
{
  unsigned __int8 AvmObjOffset; // al
  unsigned __int8 v3; // al
  __int64 v4; // rax

  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x2000u;
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    ((void (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                          + 4 * AvmObjOffset))[9].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
  v3 = this->AvmObjOffset;
  if ( v3 )
  {
    v4 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * v3))[3].__vecDelDtor)((char *)this + 4 * v3);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 176i64))(v4);
  }
}

// File Line: 283
// RVA: 0x8EC8A0
void __fastcall Scaleform::GFx::Button::OnEventUnload(Scaleform::GFx::Button *this)
{
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x1000u;
  Scaleform::GFx::Button::UnloadCharactersForState(this, Up);
  Scaleform::GFx::Button::UnloadCharactersForState(this, Over);
  Scaleform::GFx::Button::UnloadCharactersForState(this, Down);
  Scaleform::GFx::Button::UnloadCharactersForState(this, Hit);
  Scaleform::GFx::InteractiveObject::OnEventUnload(this);
}

// File Line: 293
// RVA: 0x8EFE70
char __fastcall Scaleform::GFx::Button::PointTestLocal(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Point<float> *pt,
        unsigned __int8 hitTestMask)
{
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  float *v8; // rax
  float y; // xmm0_4
  __int64 v10; // rsi
  __int64 i; // r14
  Scaleform::GFx::DisplayObjectBase *pObject; // rbx
  __int64 v13; // rax
  unsigned int v14; // xmm1_4
  unsigned int v15; // xmm0_4
  Scaleform::Render::Matrix2x4<float> v16; // [rsp+20h] [rbp-68h] BYREF
  __int128 v17[2]; // [rsp+40h] [rbp-48h] BYREF
  Scaleform::Render::Point<float> result; // [rsp+90h] [rbp+8h] BYREF

  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0x800) != 0 )
    return 0;
  if ( (hitTestMask & 2) != 0
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Button *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this) )
  {
    return 0;
  }
  if ( (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 1) == 0 )
  {
    vfptr = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v17[0] = _xmm;
    v17[1] = (__int128)_xmm;
    v8 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::Button *, Scaleform::Render::Matrix2x4<float> *, __int128 *))vfptr[61].__vecDelDtor)(
                    this,
                    &v16,
                    v17);
    if ( pt->x <= v8[2] && pt->x >= *v8 )
    {
      y = pt->y;
      if ( y <= v8[3] && y >= v8[1] )
      {
        if ( (hitTestMask & 1) == 0 )
          return 1;
        goto LABEL_13;
      }
    }
    return 0;
  }
LABEL_13:
  v10 = 0i64;
  if ( !this->States[3].Characters.Data.Size )
    return 0;
  for ( i = 0i64; ; ++i )
  {
    pObject = this->States[3].Characters.Data.Data[i].Char.pObject;
    if ( pObject
      && ((hitTestMask & 2) == 0
       || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pObject->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pObject)) )
    {
      v13 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pObject->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pObject);
      v14 = *(_DWORD *)(v13 + 4);
      v16.M[0][0] = *(float *)v13;
      *(_QWORD *)&v16.M[0][1] = __PAIR64__(*(_DWORD *)(v13 + 8), v14);
      v15 = *(_DWORD *)(v13 + 16);
      v16.M[0][3] = *(float *)(v13 + 12);
      *(_QWORD *)&v16.M[1][0] = __PAIR64__(*(_DWORD *)(v13 + 20), v15);
      *(_QWORD *)&v16.M[1][2] = *(_QWORD *)(v13 + 24);
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v16, &result, pt);
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, _QWORD))pObject->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
             pObject,
             &result,
             hitTestMask) )
      {
        break;
      }
    }
    if ( ++v10 >= this->States[3].Characters.Data.Size )
      return 0;
  }
  return 1;
}

// File Line: 331
// RVA: 0x8DF890
__int64 __fastcall Scaleform::GFx::Button::GetTopMostMouseEntity(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // rax
  float x1; // xmm0_4
  float y1; // xmm1_4
  __int64 result; // rax
  unsigned __int64 v10; // rdi
  __int64 v11; // rsi
  Scaleform::GFx::Button::CharToRec *Data; // rax
  Scaleform::GFx::DisplayObjectBase *pObject; // r14
  __int64 v14; // r8
  float y; // xmm1_4
  Scaleform::Render::Point<float> pta; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::Render::Point<float> p; // [rsp+70h] [rbp+18h] BYREF

  pdescr->pResult = 0i64;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Button *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this)
    || pdescr->pIgnoreMC == this
    || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Button *, Scaleform::GFx::MovieImpl *, _QWORD))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[85].__vecDelDtor)(
          this,
          this->pASRoot->pMovieImpl,
          pdescr->ControllerIdx) )
  {
    return 2i64;
  }
  if ( this->pScrollRect )
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &p, pt, 1, 0i64);
    pScrollRect = this->pScrollRect;
    pta = p;
    x1 = pScrollRect->Rectangle.x1;
    y1 = pScrollRect->Rectangle.y1;
    pta.x = x1 + p.x;
    pta.y = y1 + p.y;
    if ( p.x < 0.0
      || p.y < 0.0
      || p.x > pScrollRect->Rectangle.x2 - pScrollRect->Rectangle.x1
      || p.y > pScrollRect->Rectangle.y2 - pScrollRect->Rectangle.y1 )
    {
      return 2i64;
    }
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &pta, pt, 1, 0i64);
  }
  v10 = 0i64;
  if ( this->States[3].Characters.Data.Size )
  {
    v11 = 0i64;
    while ( 1 )
    {
      Data = this->States[3].Characters.Data.Data;
      pObject = Data[v11].Char.pObject;
      if ( pObject )
      {
        Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(Data[v11].Char.pObject, &p, &pta, 1, 0i64);
        LOBYTE(v14) = 1;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, __int64))pObject->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
               pObject,
               &p,
               v14) )
        {
          break;
        }
      }
      ++v10;
      ++v11;
      if ( v10 >= this->States[3].Characters.Data.Size )
        goto LABEL_16;
    }
    pdescr->pResult = this;
    return 1i64;
  }
  else
  {
LABEL_16:
    y = pta.y;
    result = 3i64;
    pdescr->LocalPt.x = pta.x;
    pdescr->LocalPt.y = y;
  }
  return result;
}

// File Line: 369
// RVA: 0x8D5650
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetBoundsOfRecord(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform,
        Scaleform::GFx::DisplayObjectBase *pch)
{
  float v6; // xmm1_4
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float *v10; // rax
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  Scaleform::RefCountNTSImplCoreVtbl *v19; // rax
  __int64 v20; // rax
  char v22[16]; // [rsp+20h] [rbp-40h] BYREF
  __int128 v23; // [rsp+30h] [rbp-30h] BYREF
  __m128 v24; // [rsp+40h] [rbp-20h]

  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v23 = _xmm;
  v24 = _xmm;
  if ( pch )
  {
    v6 = transform->M[0][1];
    vfptr = pch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    *(float *)&v23 = transform->M[0][0];
    *(_QWORD *)((char *)&v23 + 4) = __PAIR64__(LODWORD(transform->M[0][2]), LODWORD(v6));
    v8 = transform->M[1][0];
    HIDWORD(v23) = LODWORD(transform->M[0][3]);
    v24.m128_u64[0] = __PAIR64__(LODWORD(transform->M[1][1]), LODWORD(v8));
    v9 = transform->M[1][3];
    v24.m128_u64[1] = *(_QWORD *)&transform->M[1][2];
    v10 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))vfptr[2].__vecDelDtor)(pch);
    v11 = *(float *)&v23;
    v12 = *((float *)&v23 + 1);
    v13 = v24.m128_f32[0];
    v14 = v24.m128_f32[1];
    *(float *)&v23 = (float)(*(float *)&v23 * *v10) + (float)(*((float *)&v23 + 1) * v10[4]);
    v24.m128_f32[0] = (float)(v24.m128_f32[0] * *v10) + (float)(v24.m128_f32[1] * v10[4]);
    *((float *)&v23 + 1) = (float)(v11 * v10[1]) + (float)(*((float *)&v23 + 1) * v10[5]);
    v15 = v13 * v10[1];
    v16 = v24.m128_f32[1] * v10[5];
    DWORD2(v23) = 0;
    *(unsigned __int64 *)((char *)v24.m128_u64 + 4) = COERCE_UNSIGNED_INT(v16 + v15);
    *((float *)&v23 + 3) = *((float *)&v23 + 3) + (float)((float)(v11 * v10[3]) + (float)(v12 * v10[7]));
    v17 = v14 * v10[7];
    v18 = v13 * v10[3];
    v19 = pch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v24.m128_f32[3] = v9 + (float)(v17 + v18);
    v20 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, char *, __int128 *))v19[61].__vecDelDtor)(
            pch,
            v22,
            &v23);
    result->x1 = *(float *)v20;
    result->y1 = *(float *)(v20 + 4);
    *(_QWORD *)&result->x2 = *(_QWORD *)(v20 + 8);
  }
  return result;
}

// File Line: 386
// RVA: 0x8DCF00
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetRectBounds(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform,
        Scaleform::GFx::DisplayObjectBase *pch)
{
  float v6; // xmm1_4
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float *v10; // rax
  float v11; // xmm4_4
  float v12; // xmm3_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // xmm2_4
  float v17; // xmm6_4
  float v18; // xmm5_4
  Scaleform::RefCountNTSImplCoreVtbl *v19; // rax
  __int64 v20; // rax
  char v22[16]; // [rsp+20h] [rbp-40h] BYREF
  __int128 v23; // [rsp+30h] [rbp-30h] BYREF
  __m128 v24; // [rsp+40h] [rbp-20h]

  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v23 = _xmm;
  v24 = _xmm;
  if ( pch )
  {
    v6 = transform->M[0][1];
    vfptr = pch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    *(float *)&v23 = transform->M[0][0];
    *(_QWORD *)((char *)&v23 + 4) = __PAIR64__(LODWORD(transform->M[0][2]), LODWORD(v6));
    v8 = transform->M[1][0];
    HIDWORD(v23) = LODWORD(transform->M[0][3]);
    v24.m128_u64[0] = __PAIR64__(LODWORD(transform->M[1][1]), LODWORD(v8));
    v9 = transform->M[1][3];
    v24.m128_u64[1] = *(_QWORD *)&transform->M[1][2];
    v10 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))vfptr[2].__vecDelDtor)(pch);
    v11 = *(float *)&v23;
    v12 = *((float *)&v23 + 1);
    v13 = v24.m128_f32[0];
    v14 = v24.m128_f32[1];
    *(float *)&v23 = (float)(*(float *)&v23 * *v10) + (float)(*((float *)&v23 + 1) * v10[4]);
    v24.m128_f32[0] = (float)(v24.m128_f32[0] * *v10) + (float)(v24.m128_f32[1] * v10[4]);
    *((float *)&v23 + 1) = (float)(v11 * v10[1]) + (float)(*((float *)&v23 + 1) * v10[5]);
    v15 = v13 * v10[1];
    v16 = v24.m128_f32[1] * v10[5];
    DWORD2(v23) = 0;
    *(unsigned __int64 *)((char *)v24.m128_u64 + 4) = COERCE_UNSIGNED_INT(v16 + v15);
    *((float *)&v23 + 3) = *((float *)&v23 + 3) + (float)((float)(v11 * v10[3]) + (float)(v12 * v10[7]));
    v17 = v14 * v10[7];
    v18 = v13 * v10[3];
    v19 = pch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v24.m128_f32[3] = v9 + (float)(v17 + v18);
    v20 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, char *, __int128 *))v19[62].__vecDelDtor)(
            pch,
            v22,
            &v23);
    result->x1 = *(float *)v20;
    result->y1 = *(float *)(v20 + 4);
    *(_QWORD *)&result->x2 = *(_QWORD *)(v20 + 8);
  }
  return result;
}

// File Line: 405
// RVA: 0x8D4E40
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetBounds(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  unsigned __int64 v3; // rdi
  char v5; // r15
  Scaleform::GFx::ButtonRecord::MouseState MouseState; // edx
  int v9; // r9d
  __int32 v10; // edx
  __int64 v11; // r14
  __int64 v12; // rsi
  Scaleform::Render::Rect<float> *BoundsOfRecord; // rax
  float x1; // xmm4_4
  float x2; // xmm2_4
  float y1; // xmm1_4
  float y2; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  Scaleform::Render::Rect<float> resulta; // [rsp+20h] [rbp-28h] BYREF

  v3 = 0i64;
  v5 = 0;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  MouseState = this->MouseState;
  v9 = 0;
  if ( MouseState )
  {
    v10 = MouseState - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        v9 = 1;
    }
    else
    {
      v9 = 2;
    }
  }
  v11 = v9;
  if ( this->States[v11].Characters.Data.Size )
  {
    v12 = 0i64;
    do
    {
      BoundsOfRecord = Scaleform::GFx::Button::GetBoundsOfRecord(
                         this,
                         &resulta,
                         transform,
                         this->States[v11].Characters.Data.Data[v12].Char.pObject);
      x1 = BoundsOfRecord->x1;
      x2 = BoundsOfRecord->x2;
      y1 = BoundsOfRecord->y1;
      y2 = BoundsOfRecord->y2;
      if ( x2 != BoundsOfRecord->x1 || y2 != y1 )
      {
        if ( v5 )
        {
          if ( result->x1 <= x1 )
            x1 = result->x1;
          v18 = result->x2;
          if ( v18 <= x2 )
            v18 = BoundsOfRecord->x2;
          if ( result->y1 <= y1 )
            y1 = result->y1;
          v19 = result->y2;
          if ( v19 <= y2 )
            v19 = BoundsOfRecord->y2;
          result->x2 = v18;
          result->y2 = v19;
        }
        else
        {
          result->x2 = x2;
          result->y2 = y2;
          v5 = 1;
        }
        result->y1 = y1;
        result->x1 = x1;
      }
      ++v3;
      ++v12;
    }
    while ( v3 < this->States[v11].Characters.Data.Size );
  }
  return result;
}

// File Line: 437
// RVA: 0x8DD0B0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetRectBounds(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  unsigned __int64 v3; // rdi
  char v5; // r15
  Scaleform::GFx::ButtonRecord::MouseState MouseState; // edx
  int v9; // r9d
  __int32 v10; // edx
  __int64 v11; // r14
  __int64 v12; // rsi
  Scaleform::Render::Rect<float> *RectBounds; // rax
  float x1; // xmm4_4
  float x2; // xmm2_4
  float y1; // xmm1_4
  float y2; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  Scaleform::Render::Rect<float> resulta; // [rsp+20h] [rbp-28h] BYREF

  v3 = 0i64;
  v5 = 0;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  MouseState = this->MouseState;
  v9 = 0;
  if ( MouseState )
  {
    v10 = MouseState - 1;
    if ( v10 )
    {
      if ( v10 == 1 )
        v9 = 1;
    }
    else
    {
      v9 = 2;
    }
  }
  v11 = v9;
  if ( this->States[v11].Characters.Data.Size )
  {
    v12 = 0i64;
    do
    {
      RectBounds = Scaleform::GFx::Button::GetRectBounds(
                     this,
                     &resulta,
                     transform,
                     this->States[v11].Characters.Data.Data[v12].Char.pObject);
      x1 = RectBounds->x1;
      x2 = RectBounds->x2;
      y1 = RectBounds->y1;
      y2 = RectBounds->y2;
      if ( x2 != RectBounds->x1 || y2 != y1 )
      {
        if ( v5 )
        {
          if ( result->x1 <= x1 )
            x1 = result->x1;
          v18 = result->x2;
          if ( v18 <= x2 )
            v18 = RectBounds->x2;
          if ( result->y1 <= y1 )
            y1 = result->y1;
          v19 = result->y2;
          if ( v19 <= y2 )
            v19 = RectBounds->y2;
          result->x2 = v18;
          result->y2 = v19;
        }
        else
        {
          result->x2 = x2;
          result->y2 = y2;
          v5 = 1;
        }
        result->y1 = y1;
        result->x1 = x1;
      }
      ++v3;
      ++v12;
    }
    while ( v3 < this->States[v11].Characters.Data.Size );
  }
  return result;
}

// File Line: 472
// RVA: 0x8D5800
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetBoundsOfState(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Rect<float> *result,
        Scaleform::Render::Matrix2x4<float> *transform,
        Scaleform::GFx::Button::ButtonState state)
{
  unsigned __int64 v4; // rdi
  __int64 v6; // rbp
  __int64 v9; // rsi
  Scaleform::Render::Rect<float> *BoundsOfRecord; // rax
  float x1; // xmm8_4
  float x2; // xmm7_4
  float y1; // xmm6_4
  float y2; // xmm9_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  Scaleform::Render::Rect<float> resulta; // [rsp+20h] [rbp-68h] BYREF

  v4 = 0i64;
  v6 = state;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  if ( this->States[v6].Characters.Data.Size )
  {
    v9 = 0i64;
    do
    {
      BoundsOfRecord = Scaleform::GFx::Button::GetBoundsOfRecord(
                         this,
                         &resulta,
                         transform,
                         this->States[v6].Characters.Data.Data[v9].Char.pObject);
      x1 = BoundsOfRecord->x1;
      x2 = BoundsOfRecord->x2;
      y1 = BoundsOfRecord->y1;
      y2 = BoundsOfRecord->y2;
      if ( x2 != BoundsOfRecord->x1 || y2 != y1 )
      {
        if ( Scaleform::Render::Rect<float>::IsNull(result) )
        {
          result->x2 = x2;
          result->y2 = y2;
        }
        else
        {
          if ( result->x1 <= x1 )
            x1 = result->x1;
          v15 = result->x2;
          if ( v15 <= x2 )
            v15 = x2;
          if ( result->y1 <= y1 )
            y1 = result->y1;
          v16 = result->y2;
          if ( v16 <= y2 )
            v16 = y2;
          result->x2 = v15;
          result->y2 = v16;
        }
        result->y1 = y1;
        result->x1 = x1;
      }
      ++v4;
      ++v9;
    }
    while ( v4 < this->States[v6].Characters.Data.Size );
  }
  return result;
}

// File Line: 501
// RVA: 0x8D81F0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetFocusRect(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *BoundsOfState; // rax
  float x1; // xmm2_4
  float x2; // xmm3_4
  float y1; // xmm0_4
  float y2; // xmm1_4
  Scaleform::Render::Rect<float> *v9; // rax
  Scaleform::Render::Rect<float> *v10; // rax
  Scaleform::Render::Rect<float> *v11; // rax
  Scaleform::Render::Rect<float> *v12; // rax
  Scaleform::Render::Rect<float> resulta; // [rsp+20h] [rbp-38h] BYREF
  Scaleform::Render::Matrix2x4<float> transform; // [rsp+30h] [rbp-28h] BYREF

  *(_OWORD *)&transform.M[0][0] = _xmm;
  *(__m128 *)&transform.M[1][0] = _xmm;
  BoundsOfState = Scaleform::GFx::Button::GetBoundsOfState(this, &resulta, &transform, Hit);
  x1 = BoundsOfState->x1;
  x2 = BoundsOfState->x2;
  y1 = BoundsOfState->y1;
  y2 = BoundsOfState->y2;
  if ( x2 != BoundsOfState->x1 )
    goto LABEL_10;
  if ( y2 != y1 )
    goto LABEL_10;
  v9 = Scaleform::GFx::Button::GetBoundsOfState(this, &resulta, &transform, Down);
  x1 = v9->x1;
  x2 = v9->x2;
  y1 = v9->y1;
  y2 = v9->y2;
  if ( x2 != v9->x1 )
    goto LABEL_10;
  if ( y2 != y1 )
    goto LABEL_10;
  v10 = Scaleform::GFx::Button::GetBoundsOfState(this, &resulta, &transform, Over);
  x1 = v10->x1;
  x2 = v10->x2;
  y1 = v10->y1;
  y2 = v10->y2;
  if ( x2 != v10->x1 )
    goto LABEL_10;
  if ( y2 == y1
    && (v11 = Scaleform::GFx::Button::GetBoundsOfState(this, &resulta, &transform, Up),
        x1 = v11->x1,
        x2 = v11->x2,
        y1 = v11->y1,
        y2 = v11->y2,
        x2 == v11->x1)
    && y2 == y1 )
  {
    ((void (__fastcall *)(Scaleform::GFx::Button *, Scaleform::Render::Rect<float> *, Scaleform::Render::Matrix2x4<float> *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
      this,
      result,
      &transform);
    return result;
  }
  else
  {
LABEL_10:
    result->y2 = y2;
    result->x2 = x2;
    result->y1 = y1;
    v12 = result;
    result->x1 = x1;
  }
  return v12;
}

// File Line: 517
// RVA: 0x8ED120
void __fastcall Scaleform::GFx::Button::OnGettingKeyboardFocus(
        Scaleform::GFx::Button *this,
        char controllerIdx,
        Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v4; // [rsp+20h] [rbp-28h] BYREF
  int v5; // [rsp+28h] [rbp-20h]
  char v6; // [rsp+2Ch] [rbp-1Ch]
  char v7; // [rsp+30h] [rbp-18h]
  char v8; // [rsp+31h] [rbp-17h]
  __int16 v9; // [rsp+32h] [rbp-16h]

  if ( fmt == GFx_FocusMovedByKeyboard )
  {
    vfptr = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v8 = controllerIdx;
    v4 = 0x2000i64;
    v5 = 9;
    v6 = 0;
    v7 = 0;
    v9 = 0;
    vfptr[100].__vecDelDtor(this, (unsigned int)&v4);
  }
}

// File Line: 524
// RVA: 0x8EE0B0
char __fastcall Scaleform::GFx::Button::OnLosingKeyboardFocus(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::InteractiveObject *__formal,
        unsigned int controllerIdx,
        Scaleform::GFx::FocusMovedType a4)
{
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v6; // [rsp+20h] [rbp-28h] BYREF
  int v7; // [rsp+28h] [rbp-20h]
  char v8; // [rsp+2Ch] [rbp-1Ch]
  char v9; // [rsp+30h] [rbp-18h]
  char v10; // [rsp+31h] [rbp-17h]
  __int16 v11; // [rsp+32h] [rbp-16h]

  if ( this->pASRoot->pMovieImpl->FocusGroups[(unsigned __int8)this->pASRoot->pMovieImpl->FocusGroupIndexes[controllerIdx]].FocusRectShown )
  {
    vfptr = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v6 = 0x4000i64;
    v7 = 9;
    v8 = 0;
    v9 = 0;
    v11 = 0;
    v10 = controllerIdx;
    vfptr[100].__vecDelDtor(this, (unsigned int)&v6);
  }
  return 1;
}

// File Line: 532
// RVA: 0x8F3DD0
void __fastcall Scaleform::GFx::Button::PropagateMouseEvent(Scaleform::GFx::Button *this, Scaleform::GFx::EventId *evt)
{
  if ( evt->Id == 8 )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(this, evt->ControllerIndex);
  this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[72].__vecDelDtor(
    this,
    (unsigned int)evt);
}

// File Line: 544
// RVA: 0x8EE590
char __fastcall Scaleform::GFx::Button::OnMouseEvent(Scaleform::GFx::Button *this, Scaleform::GFx::EventId *evt)
{
  unsigned __int16 Flags; // ax
  char v5; // si
  __int64 ControllerIndex; // rax
  Scaleform::GFx::MouseState *v7; // rcx
  unsigned int Id; // eax
  unsigned int v9; // eax
  unsigned __int8 AvmObjOffset; // al
  __int64 v12; // rax

  Flags = this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
  if ( (Flags & 0x1000) != 0 || this->Depth < -1 || (Flags & 0x10) != 0 )
    return 0;
  v5 = 0;
  if ( !evt->RollOverCnt )
  {
    ControllerIndex = (unsigned int)evt->ControllerIndex;
    if ( (unsigned int)ControllerIndex < 6 )
      v7 = &this->pASRoot->pMovieImpl->mMouseState[ControllerIndex];
    else
      v7 = 0i64;
    Id = evt->Id;
    if ( evt->Id > 0x1000 )
    {
      if ( Id == 0x2000 )
      {
        if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0x4000) == 0 || (v7->PrevButtonsState & 1) == 0 )
        {
          if ( (v7->CurButtonsState & 1) != 0 )
            return 0;
          goto LABEL_25;
        }
        goto LABEL_23;
      }
      if ( Id != 0x4000 )
      {
        if ( Id != 0x8000 )
        {
          if ( Id == 0x10000 )
            this->MouseState = 2 * ((this->Scaleform::GFx::InteractiveObject::Flags & 0x4000) == 0);
          goto LABEL_26;
        }
        goto LABEL_23;
      }
    }
    else if ( Id != 4096 )
    {
      if ( Id != 16 )
      {
        if ( Id == 32 )
        {
LABEL_25:
          this->MouseState = MouseOver;
          goto LABEL_26;
        }
        if ( Id != 1024 )
        {
          if ( Id == 2048 )
            goto LABEL_25;
LABEL_26:
          Scaleform::GFx::Button::SwitchState(this);
          goto LABEL_27;
        }
      }
LABEL_23:
      this->MouseState = MouseDown;
      goto LABEL_26;
    }
    this->MouseState = MouseUp;
    goto LABEL_26;
  }
LABEL_27:
  v9 = (this->pASRoot->pMovieImpl->Flags >> 28) & 3;
  if ( v9 == 3 )
    v9 = -1;
  if ( v9 == 1 && ((evt->Id - 0x2000) & 0xFFFFDFFF) == 0 && evt->KeyCode )
    return 0;
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v12 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                   + 4 * AvmObjOffset))[3].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    return (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v12 + 184i64))(v12, evt);
  }
  return v5;
}

// File Line: 640
// RVA: 0x9152C0
void __fastcall Scaleform::GFx::Button::UnloadCharactersForState(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::Button::ButtonState state)
{
  unsigned __int64 v2; // rdi
  __int64 v3; // r13
  unsigned __int64 v5; // rbp
  Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *p_Characters; // r14
  __int64 v7; // rsi
  char *pObject; // rbx
  Scaleform::GFx::DisplayObjectBase *v9; // rax
  Scaleform::GFx::Button::CharToRec *Data; // rbx
  Scaleform::RefCountNTSImpl *v11; // rcx
  __int64 v12; // rbx
  unsigned __int64 v13; // r9
  __int64 v14; // rdx
  __int64 v15; // rax
  Scaleform::Render::TreeContainer *v16; // rax

  v2 = 0i64;
  v3 = state;
  v5 = 0i64;
  p_Characters = &this->States[state].Characters;
  if ( p_Characters->Data.Size )
  {
    v7 = 0i64;
    do
    {
      pObject = (char *)p_Characters->Data.Data[v7].Char.pObject;
      v9 = 0i64;
      if ( pObject[106] < 0 )
        v9 = p_Characters->Data.Data[v7].Char.pObject;
      if ( v9
        && (*(unsigned __int8 (__fastcall **)(Scaleform::GFx::DisplayObjectBase *))(*(_QWORD *)pObject + 592i64))(p_Characters->Data.Data[v7].Char.pObject) )
      {
        (*(void (__fastcall **)(char *))(*(_QWORD *)pObject + 600i64))(pObject);
      }
      Data = p_Characters->Data.Data;
      v11 = p_Characters->Data.Data[v7].Char.pObject;
      if ( v11 )
        Scaleform::RefCountNTSImpl::Release(v11);
      Data[v7].Char.pObject = 0i64;
      ++v5;
      ++v7;
    }
    while ( v5 < p_Characters->Data.Size );
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &p_Characters->Data,
    p_Characters,
    0i64);
  v12 = 4 * (v3 + 7);
  v13 = (unsigned __int64)(&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr)[v12];
  if ( v13 )
  {
    v14 = *(_QWORD *)(*(_QWORD *)((v13 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                    + 8i64 * (unsigned int)((int)(v13 - (v13 & 0xFFFFF000) - 56) / 56)
                    + 40);
    v15 = *(_QWORD *)(v14 + 144);
    if ( v15 )
    {
      if ( (v15 & 1) != 0 )
      {
        v2 = *(_QWORD *)((v15 & 0xFFFFFFFFFFFFFFFEui64) + 8);
      }
      else
      {
        LOBYTE(v2) = *(_QWORD *)(v14 + 152) != 0i64;
        ++v2;
      }
    }
    Scaleform::Render::TreeContainer::Remove(
      (Scaleform::Render::TreeContainer *)(&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr)[v12],
      0i64,
      v2);
    if ( (&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr)[v12][4].__vecDelDtor )
    {
      v16 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::Button *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[69].__vecDelDtor)(this);
      Scaleform::Render::TreeContainer::Remove(v16, 0i64, 1ui64);
    }
  }
}
      Scalefor

// File Line: 664
// RVA: 0x8BC910
void __fastcall Scaleform::GFx::Button::ClearRenderTreeForState(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::Button::ButtonState state)
{
  Scaleform::GFx::Button::StateCharacters *v3; // rsi
  __int64 Size; // rax
  Scaleform::Render::TreeContainer *v5; // rax

  v3 = &this->States[state];
  if ( v3->pRenNode.pObject )
  {
    Size = Scaleform::Render::TreeContainer::GetSize(v3->pRenNode.pObject);
    Scaleform::Render::TreeContainer::Remove(v3->pRenNode.pObject, 0i64, Size);
    if ( v3->pRenNode.pObject->pParent )
    {
      v5 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::Button *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[69].__vecDelDtor)(this);
      Scaleform::Render::TreeContainer::Remove(v5, 0i64, 1ui64);
    }
  }
}

// File Line: 677
// RVA: 0x8FF0E0
void __fastcall Scaleform::GFx::Button::RemoveDisplayObject(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::DisplayObjectBase *chToRemove)
{
  Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *p_Characters; // rdi
  __int64 v4; // rbp
  unsigned __int64 v5; // rsi
  __int64 v6; // rbx
  Scaleform::GFx::DisplayObjectBase *pObject; // rdx
  Scaleform::GFx::DisplayObjectBase *v8; // rcx
  Scaleform::GFx::Button::CharToRec *Data; // r14
  Scaleform::RefCountNTSImpl *v10; // rcx

  p_Characters = &this->States[0].Characters;
  v4 = 4i64;
  do
  {
    v5 = 0i64;
    if ( p_Characters->Data.Size )
    {
      v6 = 0i64;
      do
      {
        pObject = p_Characters->Data.Data[v6].Char.pObject;
        if ( pObject )
        {
          v8 = 0i64;
          if ( SLOBYTE(pObject->Flags) < 0 )
            v8 = p_Characters->Data.Data[v6].Char.pObject;
          if ( v8 == chToRemove )
          {
            ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v8->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[75].__vecDelDtor)(v8);
            Data = p_Characters->Data.Data;
            v10 = p_Characters->Data.Data[v6].Char.pObject;
            if ( v10 )
              Scaleform::RefCountNTSImpl::Release(v10);
            Data[v6].Char.pObject = 0i64;
          }
        }
        ++v5;
        ++v6;
      }
      while ( v5 < p_Characters->Data.Size );
    }
    p_Characters = (Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *)((char *)p_Characters + 32);
    --v4;
  }
  while ( v4 );
}

// File Line: 697
// RVA: 0x8BF0C0
void __fastcall Scaleform::GFx::Button::CreateCharacters(Scaleform::GFx::Button *this)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v2; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v2 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[3].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 176i64))(v2);
  }
}

// File Line: 703
// RVA: 0x9127E0
void __fastcall Scaleform::GFx::Button::SwitchState(Scaleform::GFx::Button *this)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v3; // rax

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v3 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[3].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v3 + 200i64))(v3, (unsigned int)this->MouseState);
  }
}

// File Line: 710
// RVA: 0x90C2D0
void __fastcall Scaleform::GFx::Button::SetStateChangeFlags(Scaleform::GFx::Button *this, unsigned __int8 flags)
{
  unsigned __int64 *p_Size; // rsi
  __int64 v4; // r14
  unsigned __int64 v5; // rbx
  __int64 v6; // rdi
  __int64 v7; // rcx

  this->Scaleform::GFx::InteractiveObject::Flags &= 0xFFF0FFFF;
  p_Size = &this->States[0].Characters.Data.Size;
  v4 = 4i64;
  this->Scaleform::GFx::InteractiveObject::Flags |= (flags & 0xF) << 16;
  do
  {
    v5 = 0i64;
    if ( *p_Size )
    {
      v6 = 0i64;
      do
      {
        v7 = *(_QWORD *)(v6 + *(p_Size - 1));
        if ( v7 )
          (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v7 + 632i64))(v7, flags);
        ++v5;
        v6 += 16i64;
      }
      while ( v5 < *p_Size );
    }
    p_Size += 4;
    --v4;
  }
  while ( v4 );
}

// File Line: 725
// RVA: 0x8EDA40
char __fastcall Scaleform::GFx::Button::OnKeyEvent(
        Scaleform::GFx::Button *this,
        Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v7; // rax
  char AsciiCode; // dl
  unsigned int KeyCode; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rsi
  unsigned int v11; // eax
  int v12; // eax
  char ControllerIndex; // al
  __int64 v14; // r9
  __int64 v15; // rdx
  char v16; // al
  __int64 v18; // [rsp+28h] [rbp-18h] BYREF
  unsigned int v19; // [rsp+30h] [rbp-10h]
  char v20; // [rsp+34h] [rbp-Ch]
  int v21; // [rsp+38h] [rbp-8h]

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
  {
    v7 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                  + 4 * AvmObjOffset))[3].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::EventId *, int *))(*(_QWORD *)v7 + 192i64))(v7, id, pkeyMask);
  }
  if ( id->Id == 64 )
  {
    if ( (*pkeyMask & 0x10000) == 0 )
    {
      AsciiCode = id->AsciiCode;
      if ( !AsciiCode )
      {
        if ( id->WcharCode - 32 > 0x5F )
        {
          if ( id->KeyCode >= 0x20 )
            AsciiCode = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(id);
        }
        else
        {
          AsciiCode = id->WcharCode;
        }
      }
      KeyCode = id->KeyCode;
      v18 = 0x20000i64;
      v19 = KeyCode;
      v20 = AsciiCode;
      v21 = 0;
      if ( this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
             this,
             &v18) )
      {
        *pkeyMask |= 0x10000u;
      }
    }
    pMovieImpl = this->pASRoot->pMovieImpl;
    if ( Scaleform::GFx::MovieImpl::IsKeyboardFocused(pMovieImpl, (Scaleform::GFx::Sprite *)this, id->ControllerIndex) )
    {
      v11 = id->KeyCode;
      if ( v11 == 13 || v11 == 32 )
      {
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Button *))this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[88].__vecDelDtor)(this) )
          goto LABEL_19;
        v12 = (pMovieImpl->Flags >> 26) & 3;
        if ( v12 == 3 )
          v12 = -1;
        if ( v12 == 1 )
        {
LABEL_19:
          ControllerIndex = id->ControllerIndex;
          v18 = 1024i64;
          v19 = 13;
          v20 = 0;
          LOBYTE(v21) = 0;
          HIWORD(v21) = 0;
          BYTE1(v21) = ControllerIndex;
          this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
            this,
            (unsigned int)&v18);
          ++this->RefCount;
          LOBYTE(v14) = 1;
          ((void (__fastcall *)(Scaleform::GFx::MovieImpl *, __int64, _QWORD, __int64, __int64))pMovieImpl->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[24].__vecDelDtor)(
            pMovieImpl,
            v15,
            0i64,
            v14,
            -2i64);
          v16 = id->ControllerIndex;
          v18 = 2048i64;
          v19 = 13;
          v20 = 0;
          LOBYTE(v21) = 0;
          HIWORD(v21) = 0;
          BYTE1(v21) = v16;
          this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[100].__vecDelDtor(
            this,
            (unsigned int)&v18);
          Scaleform::RefCountNTSImpl::Release(this);
        }
      }
    }
  }
  return 1;
}

// File Line: 778
// RVA: 0x8B54A0
void __fastcall Scaleform::GFx::Button::AdvanceFrame(Scaleform::GFx::Button *this, bool nextFrame, float __formal)
{
  unsigned __int8 AvmObjOffset; // al
  __int64 v4; // rax
  __int64 v5; // [rsp+20h] [rbp-28h] BYREF
  int v6; // [rsp+28h] [rbp-20h]
  char v7; // [rsp+2Ch] [rbp-1Ch]
  int v8; // [rsp+30h] [rbp-18h]

  if ( nextFrame )
  {
    AvmObjOffset = this->AvmObjOffset;
    if ( AvmObjOffset )
    {
      v5 = 2i64;
      v6 = 0;
      v7 = 0;
      v8 = 65280;
      v4 = ((__int64 (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                    + 4 * AvmObjOffset))[3].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
      (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v4 + 64i64))(v4, &v5);
    }
  }
}

// File Line: 794
// RVA: 0x8BA5E0
__int64 __fastcall Scaleform::GFx::Button::CheckAdvanceStatus(Scaleform::GFx::Button *this, bool playingNow)
{
  unsigned int v2; // r8d

  v2 = 0;
  if ( (this->Scaleform::GFx::InteractiveObject::Flags & 0xC) != 0
    || (this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x40) != 0 )
  {
    if ( playingNow )
      return (unsigned int)-1;
    return v2;
  }
  else
  {
    LOBYTE(v2) = !playingNow;
    return v2;
  }
}

// File Line: 866
// RVA: 0x8D5950
__int64 __fastcall Scaleform::GFx::Button::GetButtonState(Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  int v1; // ecx

  if ( mouseState )
  {
    v1 = mouseState - 1;
    if ( !v1 )
      return 2i64;
    if ( v1 == 1 )
      return 1i64;
  }
  return 0i64;
}

// File Line: 879
// RVA: 0x8C3A10
Scaleform::Ptr<Scaleform::Render::TreeContainer> *__fastcall Scaleform::GFx::Button::CreateStateRenderContainer(
        Scaleform::GFx::Button *this,
        Scaleform::Ptr<Scaleform::Render::TreeContainer> *result,
        Scaleform::GFx::Button::ButtonState buttonState)
{
  __int64 v3; // rbx
  Scaleform::RefCountNTSImplCoreVtbl *v6; // rsi
  __int64 v7; // rbx
  Scaleform::Render::ContextImpl::Entry *v8; // rcx

  v3 = buttonState;
  v6 = (Scaleform::RefCountNTSImplCoreVtbl *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&this->pASRoot->pMovieImpl->RenderContext);
  v7 = 4 * (v3 + 7);
  v8 = (Scaleform::Render::ContextImpl::Entry *)(&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr)[v7];
  if ( v8 )
  {
    if ( v8->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
  }
  (&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr)[v7] = v6;
  if ( v6 )
    ++v6[1].__vecDelDtor;
  result->pObject = (Scaleform::Render::TreeContainer *)(&this->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr)[v7];
  return result;
}

