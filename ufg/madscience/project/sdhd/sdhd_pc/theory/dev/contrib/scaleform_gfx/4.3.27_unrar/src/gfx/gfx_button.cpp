// File Line: 120
// RVA: 0x894D40
void __fastcall Scaleform::GFx::Button::Button(Scaleform::GFx::Button *this, Scaleform::GFx::ButtonDef *def, Scaleform::GFx::MovieDefImpl *pbindingDefImpl, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::InteractiveObject *parent, Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::ButtonDef *v6; // rdi
  Scaleform::GFx::Button *v7; // rsi
  Scaleform::GFx::Scale9Grid *v8; // rax
  float v9; // xmm3_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  Scaleform::Render::Rect<float> rect; // [rsp+40h] [rbp-18h]

  v6 = def;
  v7 = this;
  id.Id = **(_DWORD **)&id.Id;
  Scaleform::GFx::InteractiveObject::InteractiveObject(
    (Scaleform::GFx::InteractiveObject *)&this->vfptr,
    pbindingDefImpl,
    pasRoot,
    parent,
    (Scaleform::GFx::ResourceId)&id);
  v7->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::Button::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  v7->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::Button::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  v7->pDef = v6;
  `eh vector constructor iterator(
    v7->States,
    0x20ui64,
    4,
    (void (__fastcall *)(void *))Scaleform::GFx::Button::StateCharacters::StateCharacters);
  *(_QWORD *)&v7->LastMouseFlags = 0i64;
  v7->MouseState = 0;
  v8 = v6->pScale9Grid;
  if ( v8 )
  {
    v9 = v8->Rect.y2;
    v10 = v8->Rect.x2;
    v11 = v8->Rect.y1;
    rect.x1 = v8->Rect.x1;
    rect.y1 = v11;
    rect.x2 = v10;
    rect.y2 = v9;
  }
  else
  {
    rect = 0i64;
  }
  Scaleform::GFx::DisplayObjContainer::SetScale9Grid((Scaleform::GFx::DisplayObjContainer *)v7, &rect);
  if ( v7->pDef->Menu )
    v7->Flags |= 0x4000u;
  else
    v7->Flags &= 0xFFFFBFFF;
}

// File Line: 139
// RVA: 0x90B520
void __fastcall Scaleform::GFx::DisplayObjContainer::SetScale9Grid(Scaleform::GFx::DisplayObjContainer *this, Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::Rect<float> *v2; // rbx
  Scaleform::GFx::DisplayObjContainer *v3; // rdi
  Scaleform::Render::TreeNode *v4; // rax
  Scaleform::Render::State *v5; // rax
  bool v6; // si
  Scaleform::Render::TreeNode *v7; // rax
  float v8[6]; // [rsp+20h] [rbp-18h]

  v2 = rect;
  v3 = this;
  v4 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  v5 = Scaleform::Render::TreeNode::GetState(v4, State_Scale9);
  if ( v5 )
    *(_OWORD *)v8 = *(_OWORD *)(v5->DataValue + 16);
  else
    *(_OWORD *)v8 = 0i64;
  v6 = v8[0] != v2->x1 || v8[2] != v2->x2 || v8[1] != v2->y1 || v8[3] != v2->y2;
  v7 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
  Scaleform::Render::TreeNode::SetScale9Grid(v7, v2);
  if ( v2->x2 <= v2->x1 || v2->y2 <= v2->y1 )
    v3->Flags &= 0xFFFEu;
  else
    v3->Flags |= 1u;
  if ( v6 )
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v3->vfptr[20].__vecDelDtor)(v3);
}

// File Line: 148
// RVA: 0x8F4AD0
void __fastcall Scaleform::GFx::Button::PropagateScale9GridExists(Scaleform::GFx::Button *this)
{
  Scaleform::GFx::Button *v1; // rbp
  bool v2; // al
  bool v3; // r14
  unsigned __int64 *v4; // rsi
  signed __int64 v5; // r15
  unsigned __int64 v6; // rbx
  __int64 v7; // rdi
  __int64 v8; // rdx
  _WORD *v9; // rcx

  v1 = this;
  v2 = Scaleform::GFx::DisplayObjectBase::HasScale9Grid((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  v3 = v2;
  if ( v1->Flags & 1 || !v2 )
  {
    v4 = &v1->States[0].Characters.Data.Size;
    v5 = 4i64;
    do
    {
      v6 = 0i64;
      if ( *v4 )
      {
        v7 = 0i64;
        do
        {
          v8 = *(_QWORD *)(v7 + *(v4 - 1));
          if ( v8 )
          {
            v9 = 0i64;
            if ( *(_BYTE *)(v8 + 106) < 0 )
              v9 = *(_WORD **)(v7 + *(v4 - 1));
            if ( v9 )
            {
              if ( v1->Flags & 1 || v3 )
                v9[53] |= 1u;
              else
                v9[53] &= 0xFFFEu;
              (*(void (**)(void))(*(_QWORD *)v9 + 160i64))();
            }
          }
          ++v6;
          v7 += 16i64;
        }
        while ( v6 < *v4 );
      }
      v4 += 4;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 173
// RVA: 0x8F4650
void __fastcall Scaleform::GFx::Button::PropagateNoAdvanceGlobalFlag(Scaleform::GFx::Button *this)
{
  Scaleform::GFx::Button *v1; // r15
  char v2; // r14
  unsigned __int64 *v3; // rbp
  signed __int64 v4; // r12
  unsigned __int64 v5; // rdi
  __int64 v6; // rsi
  __int64 v7; // rcx
  Scaleform::GFx::InteractiveObject *v8; // rbx
  __int64 v9; // rdx
  int v10; // eax

  v1 = this;
  v2 = (this->Flags >> 3) & 1;
  if ( this->pASRoot->pMovieImpl )
  {
    v3 = &this->States[0].Characters.Data.Size;
    v4 = 4i64;
    do
    {
      v5 = 0i64;
      if ( *v3 )
      {
        v6 = 0i64;
        do
        {
          v7 = *(_QWORD *)(v6 + *(v3 - 1));
          if ( v7 )
          {
            v8 = 0i64;
            if ( *(_BYTE *)(v7 + 106) < 0 )
              v8 = *(Scaleform::GFx::InteractiveObject **)(v6 + *(v3 - 1));
            if ( v8 )
            {
              if ( (v1->Flags >> 3) & 1 || v2 )
                v8->Flags |= 8u;
              else
                v8->Flags &= 0xFFFFFFF7;
              ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v8->vfptr[104].__vecDelDtor)(v8);
              if ( !((v8->Flags >> 21) & 1) || (v8->Flags >> 22) & 1 )
                v9 = 0i64;
              else
                LOBYTE(v9) = 1;
              v10 = (__int64)v8->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, v9);
              if ( v10 == -1 )
              {
                v8->Flags |= 0x400000u;
              }
              else if ( v10 == 1 )
              {
                Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v8);
              }
            }
          }
          ++v5;
          v6 += 16i64;
        }
        while ( v5 < *v3 );
      }
      v3 += 4;
      --v4;
    }
    while ( v4 );
  }
}

// File Line: 199
// RVA: 0x8F4890
void __fastcall Scaleform::GFx::Button::PropagateNoAdvanceLocalFlag(Scaleform::GFx::Button *this)
{
  Scaleform::GFx::Button *v1; // r15
  char v2; // r14
  unsigned __int64 *v3; // rbp
  signed __int64 v4; // r12
  unsigned __int64 v5; // rdi
  __int64 v6; // rsi
  __int64 v7; // rcx
  Scaleform::GFx::InteractiveObject *v8; // rbx
  __int64 v9; // rdx
  int v10; // eax

  v1 = this;
  v2 = (this->Flags >> 2) & 1;
  if ( this->pASRoot->pMovieImpl )
  {
    v3 = &this->States[0].Characters.Data.Size;
    v4 = 4i64;
    do
    {
      v5 = 0i64;
      if ( *v3 )
      {
        v6 = 0i64;
        do
        {
          v7 = *(_QWORD *)(v6 + *(v3 - 1));
          if ( v7 )
          {
            v8 = 0i64;
            if ( *(_BYTE *)(v7 + 106) < 0 )
              v8 = *(Scaleform::GFx::InteractiveObject **)(v6 + *(v3 - 1));
            if ( v8 )
            {
              if ( (v1->Flags >> 2) & 1 || v2 )
                v8->Flags |= 4u;
              else
                v8->Flags &= 0xFFFFFFFB;
              ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v8->vfptr[105].__vecDelDtor)(v8);
              if ( !((v8->Flags >> 21) & 1) || (v8->Flags >> 22) & 1 )
                v9 = 0i64;
              else
                LOBYTE(v9) = 1;
              v10 = (__int64)v8->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v8->vfptr, v9);
              if ( v10 == -1 )
              {
                v8->Flags |= 0x400000u;
              }
              else if ( v10 == 1 )
              {
                Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v8);
              }
            }
          }
          ++v5;
          v6 += 16i64;
        }
        while ( v5 < *v3 );
      }
      v3 += 4;
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
  Scaleform::GFx::Button *v3; // rbx
  Scaleform::Render::TreeNode *v4; // rcx
  Scaleform::Render::TreeNode *v5; // rax
  Scaleform::GFx::MovieImpl *v6; // rcx
  bool v7; // dl
  unsigned int v8; // ecx
  unsigned int v9; // ecx
  Scaleform::GFx::InteractiveObject *v10; // rax

  v2 = visible;
  v3 = this;
  if ( visible )
  {
    this->Flags |= 0x4000u;
    v4 = this->pRenNode.pObject;
    if ( !v4 )
      goto LABEL_6;
  }
  else
  {
    this->Flags &= 0xBFFFu;
    v5 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
    visible = 0;
    v4 = v5;
  }
  Scaleform::Render::TreeNode::SetVisible(v4, visible);
LABEL_6:
  v6 = v3->pASRoot->pMovieImpl;
  if ( v6 )
  {
    v7 = !v2 && (v6->Flags >> 11) & 1;
    v8 = v3->Flags;
    if ( v7 != ((v3->Flags >> 3) & 1) )
    {
      if ( v7 )
        v9 = v8 | 8;
      else
        v9 = v8 & 0xFFFFFFF7;
      v3->Flags = v9;
      Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::Button>((Scaleform::GFx::InteractiveObject *)&v3->vfptr);
      v10 = v3->pParent;
      if ( v10 )
      {
        if ( !((v10->Flags >> 3) & 1) )
          ((void (__fastcall *)(Scaleform::GFx::Button *))v3->vfptr[104].__vecDelDtor)(v3);
      }
    }
  }
}

// File Line: 243
// RVA: 0x904250
void __fastcall Scaleform::GFx::Button::Restart(Scaleform::GFx::Button *this)
{
  Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *v1; // rsi
  signed __int64 v2; // rbp
  unsigned __int64 v3; // rbx
  __int64 v4; // rdi
  Scaleform::GFx::DisplayObjectBase *v5; // rcx

  *(_QWORD *)&this->LastMouseFlags = 0i64;
  this->MouseState = 0;
  this->RollOverCnt = 0;
  v1 = &this->States[0].Characters;
  v2 = 4i64;
  do
  {
    v3 = 0i64;
    if ( v1->Data.Size )
    {
      v4 = 0i64;
      do
      {
        v5 = v1->Data.Data[v4].Char.pObject;
        if ( v5 )
          ((void (*)(void))v5->vfptr[70].__vecDelDtor)();
        ++v3;
        ++v4;
      }
      while ( v3 < v1->Data.Size );
    }
    v1 = (Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *)((char *)v1 + 32);
    --v2;
  }
  while ( v2 );
}

// File Line: 277
// RVA: 0x8EC6D0
void __fastcall Scaleform::GFx::Button::OnEventLoad(Scaleform::GFx::Button *this)
{
  Scaleform::GFx::Button *v1; // rbx
  unsigned __int8 v2; // al
  unsigned __int8 v3; // al
  __int64 v4; // rax

  v1 = this;
  this->Flags |= 0x2000u;
  v2 = this->AvmObjOffset;
  if ( v2 )
    ((void (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v2))[9].__vecDelDtor)();
  v3 = v1->AvmObjOffset;
  if ( v3 )
  {
    v4 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr + 4 * v3))[3].__vecDelDtor)((signed __int64)v1 + 4 * v3);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 176i64))(v4);
  }
}

// File Line: 283
// RVA: 0x8EC8A0
void __fastcall Scaleform::GFx::Button::OnEventUnload(Scaleform::GFx::Button *this)
{
  Scaleform::GFx::Button *v1; // rbx

  v1 = this;
  this->Flags |= 0x1000u;
  Scaleform::GFx::Button::UnloadCharactersForState(this, 0);
  Scaleform::GFx::Button::UnloadCharactersForState(v1, Over);
  Scaleform::GFx::Button::UnloadCharactersForState(v1, Down);
  Scaleform::GFx::Button::UnloadCharactersForState(v1, Hit);
  Scaleform::GFx::InteractiveObject::OnEventUnload((Scaleform::GFx::InteractiveObject *)&v1->vfptr);
}

// File Line: 293
// RVA: 0x8EFE70
char __fastcall Scaleform::GFx::Button::PointTestLocal(Scaleform::GFx::Button *this, Scaleform::Render::Point<float> *pt, char hitTestMask)
{
  unsigned __int8 v3; // r15
  Scaleform::Render::Point<float> *v4; // r12
  Scaleform::GFx::Button *v5; // rdi
  Scaleform::RefCountNTSImplCoreVtbl *v7; // rax
  float *v8; // rax
  float v9; // xmm0_4
  unsigned __int64 v10; // rsi
  __int64 v11; // r14
  Scaleform::GFx::DisplayObjectBase *v12; // rbx
  __int64 v13; // rax
  unsigned int v14; // xmm1_4
  unsigned int v15; // xmm0_4
  Scaleform::Render::Matrix2x4<float> v16; // [rsp+20h] [rbp-68h]
  __int128 v17; // [rsp+40h] [rbp-48h]
  __m128 v18; // [rsp+50h] [rbp-38h]
  Scaleform::Render::Point<float> result; // [rsp+90h] [rbp+8h]

  v3 = hitTestMask;
  v4 = pt;
  v5 = this;
  if ( (this->Flags >> 11) & 1 )
    return 0;
  if ( hitTestMask & 2 && !((unsigned __int8 (*)(void))this->vfptr[59].__vecDelDtor)() )
    return 0;
  if ( !(v5->Flags & 1) )
  {
    v7 = v5->vfptr;
    v17 = _xmm;
    v18 = _xmm;
    v8 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::Button *, Scaleform::Render::Matrix2x4<float> *, __int128 *))v7[61].__vecDelDtor)(
                    v5,
                    &v16,
                    &v17);
    if ( v4->x <= v8[2] && v4->x >= *v8 )
    {
      v9 = v4->y;
      if ( v9 <= v8[3] && v9 >= v8[1] )
      {
        if ( !(v3 & 1) )
          return 1;
        goto LABEL_13;
      }
    }
    return 0;
  }
LABEL_13:
  v10 = 0i64;
  if ( !v5->States[3].Characters.Data.Size )
    return 0;
  v11 = 0i64;
  while ( 1 )
  {
    v12 = v5->States[3].Characters.Data.Data[v11].Char.pObject;
    if ( v12
      && (!(v3 & 2)
       || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v12->vfptr[59].__vecDelDtor)(v12)) )
    {
      v13 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v12->vfptr[2].__vecDelDtor)(v12);
      v14 = *(_DWORD *)(v13 + 4);
      v16.M[0][0] = *(float *)v13;
      *(_QWORD *)&v16.M[0][1] = __PAIR__(*(_DWORD *)(v13 + 8), v14);
      v15 = *(_DWORD *)(v13 + 16);
      v16.M[0][3] = *(float *)(v13 + 12);
      *(_QWORD *)&v16.M[1][0] = __PAIR__(*(_DWORD *)(v13 + 20), v15);
      *(_QWORD *)&v16.M[1][2] = *(_QWORD *)(v13 + 24);
      Scaleform::Render::Matrix2x4<float>::TransformByInverse(&v16, &result, v4);
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, _QWORD))v12->vfptr[63].__vecDelDtor)(
             v12,
             &result,
             v3) )
      {
        break;
      }
    }
    ++v10;
    ++v11;
    if ( v10 >= v5->States[3].Characters.Data.Size )
      return 0;
  }
  return 1;
}

// File Line: 331
// RVA: 0x8DF890
signed __int64 __fastcall Scaleform::GFx::Button::GetTopMostMouseEntity(Scaleform::GFx::Button *this, Scaleform::Render::Point<float> *pt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v3; // r15
  Scaleform::Render::Point<float> *v4; // rdi
  Scaleform::GFx::Button *v5; // rbx
  double *v6; // rax
  float v7; // xmm0_4
  float v8; // xmm1_4
  signed __int64 result; // rax
  unsigned __int64 v10; // rdi
  __int64 v11; // rsi
  Scaleform::GFx::Button::CharToRec *v12; // rax
  Scaleform::GFx::DisplayObjectBase *v13; // r14
  __int64 v14; // r8
  float v15; // xmm1_4
  Scaleform::Render::Point<float> pta; // [rsp+60h] [rbp+8h]
  Scaleform::Render::Point<float> p; // [rsp+70h] [rbp+18h]

  v3 = pdescr;
  v4 = pt;
  pdescr->pResult = 0i64;
  v5 = this;
  if ( !((unsigned __int8 (*)(void))this->vfptr[59].__vecDelDtor)()
    || (Scaleform::GFx::Button *)v3->pIgnoreMC == v5
    || !((unsigned __int8 (__fastcall *)(Scaleform::GFx::Button *, Scaleform::GFx::MovieImpl *, _QWORD))v5->vfptr[85].__vecDelDtor)(
          v5,
          v5->pASRoot->pMovieImpl,
          v3->ControllerIdx) )
  {
    return 2i64;
  }
  if ( v5->pScrollRect )
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(
      (Scaleform::GFx::DisplayObjectBase *)&v5->vfptr,
      &p,
      v4,
      1,
      0i64);
    v6 = &v5->pScrollRect->Rectangle.x1;
    pta = p;
    v7 = *v6;
    v8 = v6[1];
    pta.x = v7 + p.x;
    pta.y = v8 + p.y;
    if ( p.x < 0.0 || p.y < 0.0 || p.x > v6[2] - *v6 || p.y > v6[3] - v6[1] )
      return 2i64;
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(
      (Scaleform::GFx::DisplayObjectBase *)&v5->vfptr,
      &pta,
      v4,
      1,
      0i64);
  }
  v10 = 0i64;
  if ( v5->States[3].Characters.Data.Size <= 0 )
  {
LABEL_16:
    v15 = pta.y;
    result = 3i64;
    v3->LocalPt.x = pta.x;
    v3->LocalPt.y = v15;
  }
  else
  {
    v11 = 0i64;
    while ( 1 )
    {
      v12 = v5->States[3].Characters.Data.Data;
      v13 = v12[v11].Char.pObject;
      if ( v13 )
      {
        Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(v12[v11].Char.pObject, &p, &pta, 1, 0i64);
        LOBYTE(v14) = 1;
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Point<float> *, __int64))v13->vfptr[63].__vecDelDtor)(
               v13,
               &p,
               v14) )
        {
          break;
        }
      }
      ++v10;
      ++v11;
      if ( v10 >= v5->States[3].Characters.Data.Size )
        goto LABEL_16;
    }
    v3->pResult = (Scaleform::GFx::InteractiveObject *)&v5->vfptr;
    result = 1i64;
  }
  return result;
}

// File Line: 369
// RVA: 0x8D5650
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetBoundsOfRecord(Scaleform::GFx::Button *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform, Scaleform::GFx::DisplayObjectBase *pch)
{
  Scaleform::GFx::DisplayObjectBase *v4; // rdi
  Scaleform::Render::Rect<float> *v5; // rbx
  float v6; // xmm1_4
  Scaleform::RefCountNTSImplCoreVtbl *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float *v10; // rax
  __int64 v11; // kr00_8
  unsigned __int64 v12; // kr08_8
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm6_4
  float v16; // xmm5_4
  Scaleform::RefCountNTSImplCoreVtbl *v17; // rax
  float *v18; // rax
  float v19; // ecx
  char v21; // [rsp+20h] [rbp-40h]
  __int128 v22; // [rsp+30h] [rbp-30h]
  __m128 v23; // [rsp+40h] [rbp-20h]

  v4 = pch;
  v5 = result;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v22 = _xmm;
  v23 = _xmm;
  if ( pch )
  {
    v6 = transform->M[0][1];
    v7 = pch->vfptr;
    *(float *)&v22 = transform->M[0][0];
    *(_QWORD *)((char *)&v22 + 4) = __PAIR__(LODWORD(transform->M[0][2]), LODWORD(v6));
    v8 = transform->M[1][0];
    HIDWORD(v22) = LODWORD(transform->M[0][3]);
    v23.m128_u64[0] = __PAIR__(LODWORD(transform->M[1][1]), LODWORD(v8));
    v9 = transform->M[1][3];
    v23.m128_i32[2] = LODWORD(transform->M[1][2]);
    v23.m128_f32[3] = v9;
    v10 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v7[2].__vecDelDtor)(pch);
    v11 = v22;
    v12 = v23.m128_u64[0];
    *(float *)&v22 = (float)(*(float *)&v22 * *v10) + (float)(*((float *)&v22 + 1) * v10[4]);
    v23.m128_f32[0] = (float)(v23.m128_f32[0] * *v10) + (float)(v23.m128_f32[1] * v10[4]);
    *((float *)&v22 + 1) = (float)(*(float *)&v11 * v10[1]) + (float)(*((float *)&v22 + 1) * v10[5]);
    v13 = *(float *)&v12 * v10[1];
    v14 = v23.m128_f32[1] * v10[5];
    DWORD2(v22) = 0;
    *(unsigned __int64 *)((char *)v23.m128_u64 + 4) = COERCE_UNSIGNED_INT(v14 + v13);
    *((float *)&v22 + 3) = *((float *)&v22 + 3)
                         + (float)((float)(*(float *)&v11 * v10[3]) + (float)(*((float *)&v11 + 1) * v10[7]));
    v15 = *((float *)&v12 + 1) * v10[7];
    v16 = *(float *)&v12 * v10[3];
    v17 = v4->vfptr;
    v23.m128_f32[3] = v9 + (float)(v15 + v16);
    v18 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, char *, __int128 *))v17[61].__vecDelDtor)(
                     v4,
                     &v21,
                     &v22);
    v5->x1 = *v18;
    v5->y1 = v18[1];
    v19 = v18[2];
    v5->y2 = v18[3];
    v5->x2 = v19;
  }
  return v5;
}

// File Line: 386
// RVA: 0x8DCF00
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetRectBounds(Scaleform::GFx::Button *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform, Scaleform::GFx::DisplayObjectBase *pch)
{
  Scaleform::GFx::DisplayObjectBase *v4; // rdi
  Scaleform::Render::Rect<float> *v5; // rbx
  float v6; // xmm1_4
  Scaleform::RefCountNTSImplCoreVtbl *v7; // rax
  float v8; // xmm0_4
  float v9; // xmm1_4
  float *v10; // rax
  __int64 v11; // kr00_8
  unsigned __int64 v12; // kr08_8
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm6_4
  float v16; // xmm5_4
  Scaleform::RefCountNTSImplCoreVtbl *v17; // rax
  float *v18; // rax
  float v19; // ecx
  char v21; // [rsp+20h] [rbp-40h]
  __int128 v22; // [rsp+30h] [rbp-30h]
  __m128 v23; // [rsp+40h] [rbp-20h]

  v4 = pch;
  v5 = result;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v22 = _xmm;
  v23 = _xmm;
  if ( pch )
  {
    v6 = transform->M[0][1];
    v7 = pch->vfptr;
    *(float *)&v22 = transform->M[0][0];
    *(_QWORD *)((char *)&v22 + 4) = __PAIR__(LODWORD(transform->M[0][2]), LODWORD(v6));
    v8 = transform->M[1][0];
    HIDWORD(v22) = LODWORD(transform->M[0][3]);
    v23.m128_u64[0] = __PAIR__(LODWORD(transform->M[1][1]), LODWORD(v8));
    v9 = transform->M[1][3];
    v23.m128_i32[2] = LODWORD(transform->M[1][2]);
    v23.m128_f32[3] = v9;
    v10 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v7[2].__vecDelDtor)(pch);
    v11 = v22;
    v12 = v23.m128_u64[0];
    *(float *)&v22 = (float)(*(float *)&v22 * *v10) + (float)(*((float *)&v22 + 1) * v10[4]);
    v23.m128_f32[0] = (float)(v23.m128_f32[0] * *v10) + (float)(v23.m128_f32[1] * v10[4]);
    *((float *)&v22 + 1) = (float)(*(float *)&v11 * v10[1]) + (float)(*((float *)&v22 + 1) * v10[5]);
    v13 = *(float *)&v12 * v10[1];
    v14 = v23.m128_f32[1] * v10[5];
    DWORD2(v22) = 0;
    *(unsigned __int64 *)((char *)v23.m128_u64 + 4) = COERCE_UNSIGNED_INT(v14 + v13);
    *((float *)&v22 + 3) = *((float *)&v22 + 3)
                         + (float)((float)(*(float *)&v11 * v10[3]) + (float)(*((float *)&v11 + 1) * v10[7]));
    v15 = *((float *)&v12 + 1) * v10[7];
    v16 = *(float *)&v12 * v10[3];
    v17 = v4->vfptr;
    v23.m128_f32[3] = v9 + (float)(v15 + v16);
    v18 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, char *, __int128 *))v17[62].__vecDelDtor)(
                     v4,
                     &v21,
                     &v22);
    v5->x1 = *v18;
    v5->y1 = v18[1];
    v19 = v18[2];
    v5->y2 = v18[3];
    v5->x2 = v19;
  }
  return v5;
}

// File Line: 405
// RVA: 0x8D4E40
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetBounds(Scaleform::GFx::Button *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  unsigned __int64 v3; // rdi
  Scaleform::Render::Rect<float> *v4; // rbx
  char v5; // r15
  Scaleform::GFx::ButtonRecord::MouseState v6; // edx
  Scaleform::Render::Matrix2x4<float> *v7; // r12
  Scaleform::GFx::Button *v8; // rbp
  signed int v9; // er9
  int v10; // edx
  unsigned __int64 v11; // r14
  __int64 v12; // rsi
  Scaleform::Render::Rect<float> *v13; // rax
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  Scaleform::Render::Rect<float> resulta; // [rsp+20h] [rbp-28h]

  v3 = 0i64;
  v4 = result;
  v5 = 0;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v6 = this->MouseState;
  v7 = transform;
  v8 = this;
  v9 = 0;
  if ( v6 )
  {
    v10 = v6 - 1;
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
  if ( this->States[v11].Characters.Data.Size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = Scaleform::GFx::Button::GetBoundsOfRecord(
              v8,
              &resulta,
              v7,
              v8->States[v11].Characters.Data.Data[v12].Char.pObject);
      v14 = v13->x1;
      v15 = v13->x2;
      v16 = v13->y1;
      v17 = v13->y2;
      if ( v15 != v13->x1 || v17 != v16 )
      {
        if ( v5 )
        {
          if ( v4->x1 <= v14 )
            v14 = v4->x1;
          v18 = v4->x2;
          if ( v18 <= v15 )
            v18 = v13->x2;
          if ( v4->y1 <= v16 )
            v16 = v4->y1;
          v19 = v4->y2;
          if ( v19 <= v17 )
            v19 = v13->y2;
          v4->x2 = v18;
          v4->y2 = v19;
        }
        else
        {
          v4->x2 = v15;
          v4->y2 = v17;
          v5 = 1;
        }
        v4->y1 = v16;
        v4->x1 = v14;
      }
      ++v3;
      ++v12;
    }
    while ( v3 < v8->States[v11].Characters.Data.Size );
  }
  return v4;
}

// File Line: 437
// RVA: 0x8DD0B0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetRectBounds(Scaleform::GFx::Button *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform)
{
  unsigned __int64 v3; // rdi
  Scaleform::Render::Rect<float> *v4; // rbx
  char v5; // r15
  Scaleform::GFx::ButtonRecord::MouseState v6; // edx
  Scaleform::Render::Matrix2x4<float> *v7; // r12
  Scaleform::GFx::Button *v8; // rbp
  signed int v9; // er9
  int v10; // edx
  unsigned __int64 v11; // r14
  __int64 v12; // rsi
  Scaleform::Render::Rect<float> *v13; // rax
  float v14; // xmm4_4
  float v15; // xmm2_4
  float v16; // xmm1_4
  float v17; // xmm5_4
  float v18; // xmm3_4
  float v19; // xmm0_4
  Scaleform::Render::Rect<float> resulta; // [rsp+20h] [rbp-28h]

  v3 = 0i64;
  v4 = result;
  v5 = 0;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v6 = this->MouseState;
  v7 = transform;
  v8 = this;
  v9 = 0;
  if ( v6 )
  {
    v10 = v6 - 1;
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
  if ( this->States[v11].Characters.Data.Size > 0 )
  {
    v12 = 0i64;
    do
    {
      v13 = Scaleform::GFx::Button::GetRectBounds(
              v8,
              &resulta,
              v7,
              v8->States[v11].Characters.Data.Data[v12].Char.pObject);
      v14 = v13->x1;
      v15 = v13->x2;
      v16 = v13->y1;
      v17 = v13->y2;
      if ( v15 != v13->x1 || v17 != v16 )
      {
        if ( v5 )
        {
          if ( v4->x1 <= v14 )
            v14 = v4->x1;
          v18 = v4->x2;
          if ( v18 <= v15 )
            v18 = v13->x2;
          if ( v4->y1 <= v16 )
            v16 = v4->y1;
          v19 = v4->y2;
          if ( v19 <= v17 )
            v19 = v13->y2;
          v4->x2 = v18;
          v4->y2 = v19;
        }
        else
        {
          v4->x2 = v15;
          v4->y2 = v17;
          v5 = 1;
        }
        v4->y1 = v16;
        v4->x1 = v14;
      }
      ++v3;
      ++v12;
    }
    while ( v3 < v8->States[v11].Characters.Data.Size );
  }
  return v4;
}

// File Line: 472
// RVA: 0x8D5800
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetBoundsOfState(Scaleform::GFx::Button *this, Scaleform::Render::Rect<float> *result, Scaleform::Render::Matrix2x4<float> *transform, Scaleform::GFx::Button::ButtonState state)
{
  unsigned __int64 v4; // rdi
  Scaleform::Render::Matrix2x4<float> *v5; // r15
  unsigned __int64 v6; // rbp
  Scaleform::Render::Rect<float> *v7; // rbx
  Scaleform::GFx::Button *v8; // r14
  __int64 v9; // rsi
  Scaleform::Render::Rect<float> *v10; // rax
  float v11; // xmm8_4
  float v12; // xmm7_4
  float v13; // xmm6_4
  float v14; // xmm9_4
  float v15; // xmm1_4
  float v16; // xmm0_4
  Scaleform::Render::Rect<float> resulta; // [rsp+20h] [rbp-68h]

  v4 = 0i64;
  v5 = transform;
  v6 = state;
  *(_QWORD *)&result->x1 = 0i64;
  *(_QWORD *)&result->x2 = 0i64;
  v7 = result;
  v8 = this;
  if ( this->States[v6].Characters.Data.Size )
  {
    v9 = 0i64;
    do
    {
      v10 = Scaleform::GFx::Button::GetBoundsOfRecord(
              v8,
              &resulta,
              v5,
              v8->States[v6].Characters.Data.Data[v9].Char.pObject);
      v11 = v10->x1;
      v12 = v10->x2;
      v13 = v10->y1;
      v14 = v10->y2;
      if ( v12 != v10->x1 || v14 != v13 )
      {
        if ( Scaleform::Render::Rect<float>::IsNull(v7) )
        {
          v7->x2 = v12;
          v7->y2 = v14;
        }
        else
        {
          if ( v7->x1 <= v11 )
            v11 = v7->x1;
          v15 = v7->x2;
          if ( v15 <= v12 )
            v15 = v12;
          if ( v7->y1 <= v13 )
            v13 = v7->y1;
          v16 = v7->y2;
          if ( v16 <= v14 )
            v16 = v14;
          v7->x2 = v15;
          v7->y2 = v16;
        }
        v7->y1 = v13;
        v7->x1 = v11;
      }
      ++v4;
      ++v9;
    }
    while ( v4 < v8->States[v6].Characters.Data.Size );
  }
  return v7;
}

// File Line: 501
// RVA: 0x8D81F0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::Button::GetFocusRect(Scaleform::GFx::Button *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // rbx
  Scaleform::GFx::Button *v3; // rdi
  Scaleform::Render::Rect<float> *v4; // rax
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  Scaleform::Render::Rect<float> *v9; // rax
  Scaleform::Render::Rect<float> *v10; // rax
  Scaleform::Render::Rect<float> *v11; // rax
  Scaleform::Render::Rect<float> *v12; // rax
  Scaleform::Render::Rect<float> resulta; // [rsp+20h] [rbp-38h]
  Scaleform::Render::Matrix2x4<float> transform; // [rsp+30h] [rbp-28h]

  v2 = result;
  v3 = this;
  *(_OWORD *)&transform.M[0][0] = _xmm;
  *(__m128 *)&transform.M[1][0] = _xmm;
  v4 = Scaleform::GFx::Button::GetBoundsOfState(this, &resulta, &transform, Hit);
  v5 = v4->x1;
  v6 = v4->x2;
  v7 = v4->y1;
  v8 = v4->y2;
  if ( v6 != v4->x1 )
    goto LABEL_13;
  if ( v8 != v7 )
    goto LABEL_13;
  v9 = Scaleform::GFx::Button::GetBoundsOfState(v3, &resulta, &transform, Down);
  v5 = v9->x1;
  v6 = v9->x2;
  v7 = v9->y1;
  v8 = v9->y2;
  if ( v6 != v9->x1 )
    goto LABEL_13;
  if ( v8 != v7 )
    goto LABEL_13;
  v10 = Scaleform::GFx::Button::GetBoundsOfState(v3, &resulta, &transform, Over);
  v5 = v10->x1;
  v6 = v10->x2;
  v7 = v10->y1;
  v8 = v10->y2;
  if ( v6 != v10->x1
    || v8 != v7
    || (v11 = Scaleform::GFx::Button::GetBoundsOfState(v3, &resulta, &transform, 0),
        v5 = v11->x1,
        v6 = v11->x2,
        v7 = v11->y1,
        v8 = v11->y2,
        v6 != v11->x1)
    || v8 != v7 )
  {
LABEL_13:
    v2->y2 = v8;
    v2->x2 = v6;
    v2->y1 = v7;
    v12 = v2;
    v2->x1 = v5;
  }
  else
  {
    ((void (__fastcall *)(Scaleform::GFx::Button *, Scaleform::Render::Rect<float> *, Scaleform::Render::Matrix2x4<float> *))v3->vfptr[61].__vecDelDtor)(
      v3,
      v2,
      &transform);
    v12 = v2;
  }
  return v12;
}

// File Line: 517
// RVA: 0x8ED120
void __fastcall Scaleform::GFx::Button::OnGettingKeyboardFocus(Scaleform::GFx::Button *this, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt)
{
  Scaleform::RefCountNTSImplCoreVtbl *v3; // rax
  __int64 v4; // [rsp+20h] [rbp-28h]
  int v5; // [rsp+28h] [rbp-20h]
  char v6; // [rsp+2Ch] [rbp-1Ch]
  char v7; // [rsp+30h] [rbp-18h]
  char v8; // [rsp+31h] [rbp-17h]
  __int16 v9; // [rsp+32h] [rbp-16h]

  if ( fmt == 2 )
  {
    v3 = this->vfptr;
    v8 = controllerIdx;
    v4 = 0x2000i64;
    v5 = 9;
    v6 = 0;
    v7 = 0;
    v9 = 0;
    v3[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&this->vfptr, (unsigned int)&v4);
  }
}

// File Line: 524
// RVA: 0x8EE0B0
char __fastcall Scaleform::GFx::Button::OnLosingKeyboardFocus(Scaleform::GFx::Button *this, Scaleform::GFx::InteractiveObject *__formal, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType a4)
{
  Scaleform::RefCountNTSImplCoreVtbl *v4; // rax
  __int64 v6; // [rsp+20h] [rbp-28h]
  int v7; // [rsp+28h] [rbp-20h]
  char v8; // [rsp+2Ch] [rbp-1Ch]
  char v9; // [rsp+30h] [rbp-18h]
  char v10; // [rsp+31h] [rbp-17h]
  __int16 v11; // [rsp+32h] [rbp-16h]

  if ( this->pASRoot->pMovieImpl->FocusGroups[(unsigned __int8)this->pASRoot->pMovieImpl->FocusGroupIndexes[controllerIdx]].FocusRectShown )
  {
    v4 = this->vfptr;
    v6 = 0x4000i64;
    v7 = 9;
    v8 = 0;
    v9 = 0;
    v11 = 0;
    v10 = controllerIdx;
    v4[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&this->vfptr, (unsigned int)&v6);
  }
  return 1;
}

// File Line: 532
// RVA: 0x8F3DD0
void __fastcall Scaleform::GFx::Button::PropagateMouseEvent(Scaleform::GFx::Button *this, Scaleform::GFx::EventId *evt)
{
  Scaleform::GFx::EventId *v2; // rbx
  Scaleform::GFx::Button *v3; // rdi

  v2 = evt;
  v3 = this;
  if ( evt->Id == 8 )
    Scaleform::GFx::InteractiveObject::DoMouseDrag(
      (Scaleform::GFx::InteractiveObject *)&this->vfptr,
      evt->ControllerIndex);
  v3->vfptr[72].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)v2);
}

// File Line: 544
// RVA: 0x8EE590
char __fastcall Scaleform::GFx::Button::OnMouseEvent(Scaleform::GFx::Button *this, Scaleform::GFx::EventId *evt)
{
  unsigned __int16 v2; // ax
  Scaleform::GFx::EventId *v3; // rdi
  Scaleform::GFx::Button *v4; // rbx
  char v5; // si
  __int64 v6; // rax
  Scaleform::GFx::MouseState *v7; // rcx
  unsigned int v8; // eax
  int v9; // eax
  unsigned __int8 v11; // al
  __int64 v12; // rax

  v2 = this->Flags;
  v3 = evt;
  v4 = this;
  if ( v2 & 0x1000 || this->Depth < -1 || ((unsigned __int8)v2 >> 4) & 1 )
    return 0;
  v5 = 0;
  if ( !evt->RollOverCnt )
  {
    v6 = (unsigned int)evt->ControllerIndex;
    if ( (unsigned int)v6 < 6 )
      v7 = &this->pASRoot->pMovieImpl->mMouseState[v6];
    else
      v7 = 0i64;
    v8 = evt->Id;
    if ( evt->Id > 0x1000 )
    {
      if ( v8 == 0x2000 )
      {
        if ( !((v4->Flags >> 14) & 1) || !(v7->PrevButtonsState & 1) )
        {
          if ( v7->CurButtonsState & 1 )
            return 0;
          goto LABEL_25;
        }
        goto LABEL_23;
      }
      if ( v8 != 0x4000 )
      {
        if ( v8 != 0x8000 )
        {
          if ( v8 == 0x10000 )
            v4->MouseState = 2 * (~(unsigned __int8)(v4->Flags >> 14) & 1);
          goto LABEL_26;
        }
        goto LABEL_23;
      }
    }
    else if ( v8 != 4096 )
    {
      if ( v8 != 16 )
      {
        if ( v8 == 32 )
        {
LABEL_25:
          v4->MouseState = 2;
          goto LABEL_26;
        }
        if ( v8 != 1024 )
        {
          if ( v8 == 2048 )
            goto LABEL_25;
LABEL_26:
          Scaleform::GFx::Button::SwitchState(v4);
          goto LABEL_27;
        }
      }
LABEL_23:
      v4->MouseState = 1;
      goto LABEL_26;
    }
    v4->MouseState = 0;
    goto LABEL_26;
  }
LABEL_27:
  v9 = (v4->pASRoot->pMovieImpl->Flags >> 28) & 3;
  if ( v9 == 3 )
    v9 = -1;
  if ( v9 == 1 && !((v3->Id - 0x2000) & 0xFFFFDFFF) && v3->KeyCode )
    return 0;
  v11 = v4->AvmObjOffset;
  if ( v11 )
  {
    v12 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr + 4 * v11))[3].__vecDelDtor)((signed __int64)v4 + 4 * v11);
    v5 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::EventId *))(*(_QWORD *)v12 + 184i64))(v12, v3);
  }
  return v5;
}

// File Line: 640
// RVA: 0x9152C0
void __fastcall Scaleform::GFx::Button::UnloadCharactersForState(Scaleform::GFx::Button *this, Scaleform::GFx::Button::ButtonState state)
{
  unsigned __int64 v2; // rdi
  __int64 v3; // r13
  Scaleform::GFx::Button *v4; // r15
  unsigned __int64 v5; // rbp
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *v6; // r14
  __int64 v7; // rsi
  Scaleform::GFx::DisplayObjectBase *v8; // rbx
  Scaleform::GFx::DisplayObjectBase *v9; // rax
  Scaleform::GFx::Button::CharToRec *v10; // rbx
  Scaleform::RefCountNTSImpl *v11; // rcx
  signed __int64 v12; // rbx
  unsigned __int64 v13; // r9
  __int64 v14; // rdx
  __int64 v15; // rax
  Scaleform::Render::TreeContainer *v16; // rax

  v2 = 0i64;
  v3 = state;
  v4 = this;
  v5 = 0i64;
  v6 = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&this->States[state].Characters.Data.Data;
  if ( v6->Size )
  {
    v7 = 0i64;
    do
    {
      v8 = v6->Data[v7].Char.pObject;
      v9 = 0i64;
      if ( SLOBYTE(v8->Flags) < 0 )
        v9 = v6->Data[v7].Char.pObject;
      if ( v9
        && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v8->vfptr[74].__vecDelDtor)(v6->Data[v7].Char.pObject) )
      {
        ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v8->vfptr[75].__vecDelDtor)(v8);
      }
      v10 = v6->Data;
      v11 = (Scaleform::RefCountNTSImpl *)&v6->Data[v7].Char.pObject->vfptr;
      if ( v11 )
        Scaleform::RefCountNTSImpl::Release(v11);
      v10[v7].Char.pObject = 0i64;
      ++v5;
      ++v7;
    }
    while ( v5 < v6->Size );
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    v6,
    v6,
    0i64);
  v12 = 4 * (v3 + 7);
  v13 = (unsigned __int64)(&v4->vfptr)[v12];
  if ( v13 )
  {
    v14 = *(_QWORD *)(*(_QWORD *)((v13 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                    + 8
                    * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v13
                                                                                          - (v13 & 0xFFFFFFFFFFFFF000ui64)
                                                                                          - 56)
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                     + ((unsigned __int64)((unsigned __int128)((signed __int64)(v13 - (v13 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                    + 40);
    v15 = *(_QWORD *)(v14 + 144);
    if ( v15 )
    {
      if ( v15 & 1 )
      {
        v2 = *(_QWORD *)((v15 & 0xFFFFFFFFFFFFFFFEui64) + 8);
      }
      else
      {
        LOBYTE(v2) = *(_QWORD *)(v14 + 152) != 0i64;
        ++v2;
      }
    }
    Scaleform::Render::TreeContainer::Remove((Scaleform::Render::TreeContainer *)(&v4->vfptr)[v12], 0i64, v2);
    if ( (&v4->vfptr)[v12][4].__vecDelDtor )
    {
      v16 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::Button *))v4->vfptr[69].__vecDelDtor)(v4);
      Scaleform::Render::TreeContainer::Remove(v16, 0i64, 1ui64);
    }
  }
}

// File Line: 664
// RVA: 0x8BC910
void __fastcall Scaleform::GFx::Button::ClearRenderTreeForState(Scaleform::GFx::Button *this, Scaleform::GFx::Button::ButtonState state)
{
  Scaleform::GFx::Button *v2; // rbx
  Scaleform::Render::TreeContainer **v3; // rsi
  signed __int64 v4; // rax
  Scaleform::Render::TreeContainer *v5; // rax

  v2 = this;
  v3 = (Scaleform::Render::TreeContainer **)((char *)this + 32 * ((signed int)state + 7i64));
  if ( *v3 )
  {
    v4 = Scaleform::Render::TreeContainer::GetSize(*v3);
    Scaleform::Render::TreeContainer::Remove(*v3, 0i64, v4);
    if ( (*v3)->pParent )
    {
      v5 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::Button *))v2->vfptr[69].__vecDelDtor)(v2);
      Scaleform::Render::TreeContainer::Remove(v5, 0i64, 1ui64);
    }
  }
}

// File Line: 677
// RVA: 0x8FF0E0
void __fastcall Scaleform::GFx::Button::RemoveDisplayObject(Scaleform::GFx::Button *this, Scaleform::GFx::DisplayObjectBase *chToRemove)
{
  Scaleform::GFx::DisplayObjectBase *v2; // r15
  Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  signed __int64 v4; // rbp
  unsigned __int64 v5; // rsi
  __int64 v6; // rbx
  Scaleform::GFx::DisplayObjectBase *v7; // rdx
  Scaleform::GFx::DisplayObjectBase *v8; // rcx
  Scaleform::GFx::Button::CharToRec *v9; // r14
  Scaleform::RefCountNTSImpl *v10; // rcx

  v2 = chToRemove;
  v3 = &this->States[0].Characters;
  v4 = 4i64;
  do
  {
    v5 = 0i64;
    if ( v3->Data.Size > 0 )
    {
      v6 = 0i64;
      do
      {
        v7 = v3->Data.Data[v6].Char.pObject;
        if ( v7 )
        {
          v8 = 0i64;
          if ( SLOBYTE(v7->Flags) < 0 )
            v8 = v3->Data.Data[v6].Char.pObject;
          if ( v8 == v2 )
          {
            ((void (*)(void))v8->vfptr[75].__vecDelDtor)();
            v9 = v3->Data.Data;
            v10 = (Scaleform::RefCountNTSImpl *)&v3->Data.Data[v6].Char.pObject->vfptr;
            if ( v10 )
              Scaleform::RefCountNTSImpl::Release(v10);
            v9[v6].Char.pObject = 0i64;
          }
        }
        ++v5;
        ++v6;
      }
      while ( v5 < v3->Data.Size );
    }
    v3 = (Scaleform::ArrayLH<Scaleform::GFx::Button::CharToRec,2,Scaleform::ArrayDefaultPolicy> *)((char *)v3 + 32);
    --v4;
  }
  while ( v4 );
}

// File Line: 697
// RVA: 0x8BF0C0
void __fastcall Scaleform::GFx::Button::CreateCharacters(Scaleform::GFx::Button *this)
{
  unsigned __int8 v1; // al
  __int64 v2; // rax

  v1 = this->AvmObjOffset;
  if ( v1 )
  {
    v2 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v1))[3].__vecDelDtor)();
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 176i64))(v2);
  }
}

// File Line: 703
// RVA: 0x9127E0
void __fastcall Scaleform::GFx::Button::SwitchState(Scaleform::GFx::Button *this)
{
  unsigned __int8 v1; // al
  Scaleform::GFx::Button *v2; // rbx
  __int64 v3; // rax

  v1 = this->AvmObjOffset;
  v2 = this;
  if ( v1 )
  {
    v3 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v1))[3].__vecDelDtor)();
    (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v3 + 200i64))(v3, (unsigned int)v2->MouseState);
  }
}

// File Line: 710
// RVA: 0x90C2D0
void __fastcall Scaleform::GFx::Button::SetStateChangeFlags(Scaleform::GFx::Button *this, char flags)
{
  unsigned __int8 v2; // bp
  unsigned __int64 *v3; // rsi
  signed __int64 v4; // r14
  unsigned __int64 v5; // rbx
  __int64 v6; // rdi
  __int64 v7; // rcx

  this->Flags &= 0xFFF0FFFF;
  v2 = flags;
  v3 = &this->States[0].Characters.Data.Size;
  v4 = 4i64;
  this->Flags |= (flags & 0xF) << 16;
  do
  {
    v5 = 0i64;
    if ( *v3 )
    {
      v6 = 0i64;
      do
      {
        v7 = *(_QWORD *)(v6 + *(v3 - 1));
        if ( v7 )
          (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v7 + 632i64))(v7, v2);
        ++v5;
        v6 += 16i64;
      }
      while ( v5 < *v3 );
    }
    v3 += 4;
    --v4;
  }
  while ( v4 );
}

// File Line: 725
// RVA: 0x8EDA40
char __fastcall Scaleform::GFx::Button::OnKeyEvent(Scaleform::GFx::Button *this, Scaleform::GFx::EventId *id, int *pkeyMask)
{
  int *v3; // rsi
  Scaleform::GFx::EventId *v4; // rbx
  Scaleform::GFx::Button *v5; // rdi
  unsigned __int8 v6; // al
  __int64 v7; // rax
  char v8; // dl
  int v9; // ecx
  Scaleform::GFx::ASMovieRootBase *v10; // rax
  Scaleform::GFx::MovieImpl *v11; // rsi
  unsigned int v12; // eax
  int v13; // eax
  char v14; // al
  __int64 v15; // r9
  __int64 v16; // rdx
  char v17; // al
  __int64 v19; // [rsp+28h] [rbp-18h]
  int v20; // [rsp+30h] [rbp-10h]
  char v21; // [rsp+34h] [rbp-Ch]
  int v22; // [rsp+38h] [rbp-8h]

  v3 = pkeyMask;
  v4 = id;
  v5 = this;
  v6 = this->AvmObjOffset;
  if ( v6 )
  {
    v7 = ((__int64 (__cdecl *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v6))[3].__vecDelDtor)((char *)this + 4 * v6);
    (*(void (__fastcall **)(__int64, Scaleform::GFx::EventId *, int *))(*(_QWORD *)v7 + 192i64))(v7, v4, v3);
  }
  if ( v4->Id == 64 )
  {
    if ( !(*v3 & 0x10000) )
    {
      v8 = v4->AsciiCode;
      if ( !v8 )
      {
        if ( v4->WcharCode - 32 > 0x5F )
        {
          if ( v4->KeyCode >= 0x20 )
            v8 = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(v4);
        }
        else
        {
          v8 = v4->WcharCode;
        }
      }
      v9 = v4->KeyCode;
      v19 = 0x20000i64;
      v20 = v9;
      v21 = v8;
      v22 = 0;
      if ( v5->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)&v19) )
        *v3 |= 0x10000u;
    }
    v10 = v5->pASRoot;
    v11 = v10->pMovieImpl;
    if ( Scaleform::GFx::MovieImpl::IsKeyboardFocused(
           v10->pMovieImpl,
           (Scaleform::GFx::InteractiveObject *)&v5->vfptr,
           v4->ControllerIndex) )
    {
      v12 = v4->KeyCode;
      if ( v12 == 13 || v12 == 32 )
      {
        if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::Button *))v5->vfptr[88].__vecDelDtor)(v5) )
          goto LABEL_23;
        v13 = (v11->Flags >> 26) & 3;
        if ( v13 == 3 )
          v13 = -1;
        if ( v13 == 1 )
        {
LABEL_23:
          v14 = v4->ControllerIndex;
          v19 = 1024i64;
          v20 = 13;
          v21 = 0;
          LOBYTE(v22) = 0;
          HIWORD(v22) = 0;
          BYTE1(v22) = v14;
          v5->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)&v19);
          ++v5->RefCount;
          LOBYTE(v15) = 1;
          ((void (__fastcall *)(Scaleform::GFx::MovieImpl *, __int64, _QWORD, __int64, signed __int64))v11->vfptr[24].__vecDelDtor)(
            v11,
            v16,
            0i64,
            v15,
            -2i64);
          v17 = v4->ControllerIndex;
          v19 = 2048i64;
          v20 = 13;
          v21 = 0;
          LOBYTE(v22) = 0;
          HIWORD(v22) = 0;
          BYTE1(v22) = v17;
          v5->vfptr[100].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v5->vfptr, (unsigned int)&v19);
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v5->vfptr);
        }
      }
    }
  }
  return 1;
}

// File Line: 778
// RVA: 0x8B54A0
void __usercall Scaleform::GFx::Button::AdvanceFrame(Scaleform::GFx::Button *this@<rcx>, bool nextFrame@<dl>, float __formal@<xmm2>, __int64 a4@<r8>)
{
  unsigned __int8 v4; // al
  __int64 v5; // rax
  __int64 v6; // [rsp+20h] [rbp-28h]
  int v7; // [rsp+28h] [rbp-20h]
  char v8; // [rsp+2Ch] [rbp-1Ch]
  int v9; // [rsp+30h] [rbp-18h]

  if ( nextFrame )
  {
    v4 = this->AvmObjOffset;
    if ( v4 )
    {
      v6 = 2i64;
      v7 = 0;
      v8 = 0;
      v9 = 65280;
      v5 = ((__int64 (__cdecl *)(char *, _QWORD, __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr
                                                                                                  + 4 * v4))[3].__vecDelDtor)(
             (char *)this + 4 * v4,
             0i64,
             a4);
      (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v5 + 64i64))(v5, &v6);
    }
  }
}

// File Line: 794
// RVA: 0x8BA5E0
__int64 __fastcall Scaleform::GFx::Button::CheckAdvanceStatus(Scaleform::GFx::Button *this, bool playingNow)
{
  unsigned int v2; // er8
  __int64 result; // rax

  v2 = 0;
  if ( this->Flags & 0xC || !(~(LOBYTE(this->Flags) >> 6) & 1) )
  {
    if ( playingNow )
      v2 = -1;
    result = v2;
  }
  else
  {
    LOBYTE(v2) = playingNow == 0;
    result = v2;
  }
  return result;
}

// File Line: 866
// RVA: 0x8D5950
signed __int64 __fastcall Scaleform::GFx::Button::GetButtonState(Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  __int32 v1; // ecx

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
Scaleform::Ptr<Scaleform::Render::TreeContainer> *__fastcall Scaleform::GFx::Button::CreateStateRenderContainer(Scaleform::GFx::Button *this, Scaleform::Ptr<Scaleform::Render::TreeContainer> *result, Scaleform::GFx::Button::ButtonState buttonState)
{
  __int64 v3; // rbx
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *v4; // r14
  Scaleform::GFx::Button *v5; // rdi
  Scaleform::Render::ContextImpl::Entry *v6; // rsi
  signed __int64 v7; // rbx
  Scaleform::Render::ContextImpl::Entry *v8; // rcx
  bool v9; // zf

  v3 = buttonState;
  v4 = result;
  v5 = this;
  v6 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&this->pASRoot->pMovieImpl->RenderContext);
  v7 = 4 * (v3 + 7);
  v8 = (Scaleform::Render::ContextImpl::Entry *)(&v5->vfptr)[v7];
  if ( v8 )
  {
    v9 = v8->RefCount-- == 1;
    if ( v9 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v8);
  }
  (&v5->vfptr)[v7] = (Scaleform::RefCountNTSImplCoreVtbl *)v6;
  if ( v6 )
    ++v6->RefCount;
  v4->pObject = (Scaleform::Render::TreeContainer *)(&v5->vfptr)[v7];
  return v4;
}

