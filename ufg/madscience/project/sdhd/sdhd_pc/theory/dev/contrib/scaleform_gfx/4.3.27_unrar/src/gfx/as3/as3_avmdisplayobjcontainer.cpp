// File Line: 24
// RVA: 0x7898D0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::~AvmDisplayObjContainer(Scaleform::GFx::AS3::AvmDisplayObjContainer *this)
{
  Scaleform::GFx::AvmInteractiveObjBase *v1; // rdx

  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObj'};
  v1 = (Scaleform::GFx::AvmInteractiveObjBase *)&this->vfptr;
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable';
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObj'};
  v1->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  v1->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj((Scaleform::GFx::AS3::AvmDisplayObj *)&this->vfptr);
}

// File Line: 28
// RVA: 0x803F50
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::OnEventUnload(Scaleform::GFx::AS3::AvmDisplayObjContainer *this)
{
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v1; // rbp
  Scaleform::GFx::DisplayObject *v2; // rdx
  BOOL v3; // eax
  __int64 v4; // rax
  Scaleform::GFx::DisplayList *v5; // rdi
  unsigned __int64 v6; // rsi
  __int64 v7; // rbx
  __int16 v8; // cx
  Scaleform::GFx::InteractiveObject *v9; // rdi
  bool v10; // zf
  __int64 v11; // rcx
  signed __int64 v12; // rcx
  signed __int64 v13; // rcx
  __int64 v14; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v15; // rcx
  signed __int64 v16; // rdi
  __int64 v17; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // rcx
  unsigned int v19; // eax

  v1 = this;
  v2 = this->pDispObj;
  v3 = LODWORD(v2[1].pGeomData) != 0;
  if ( LODWORD(v2[1].pGeomData) )
  {
    do
    {
      v4 = (unsigned int)(v3 - 1);
      if ( (unsigned int)v4 < LODWORD(v2[1].pGeomData) )
      {
        v5 = (Scaleform::GFx::DisplayList *)&v2[1].pRenNode;
        v6 = (unsigned int)v4;
        v7 = *((_QWORD *)&v2[1].pRenNode.pObject->pPrev + 2 * v4);
        if ( v7 )
          ++*(_DWORD *)(v7 + 8);
        if ( *(_BYTE *)(v7 + 107) & 1 )
          Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)v7, 0i64, 1);
        if ( *(_WORD *)(v7 + 106) < 0 )
          Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(
            v1->pDispObj->pASRoot->pMovieImpl,
            (Scaleform::GFx::DisplayObjectBase *)v7);
        Scaleform::GFx::DisplayList::RemoveEntryAtIndex(
          v5,
          (Scaleform::GFx::DisplayObjectBase *)&v1->pDispObj->vfptr,
          v6);
        v5->Flags |= 3u;
        v8 = *(_WORD *)(v7 + 106);
        v9 = 0i64;
        if ( (v8 & 0x80u) != 0 )
          v9 = (Scaleform::GFx::InteractiveObject *)v7;
        v10 = (v8 & 0x100) == 0;
        v11 = 0i64;
        if ( !v10 )
          v11 = v7;
        if ( v11 )
          v12 = v11 + 4i64 * *(unsigned __int8 *)(v11 + 109);
        else
          v12 = 0i64;
        (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v12 + 104i64))(v12, 0i64);
        *(_QWORD *)(v7 + 56) = 0i64;
        if ( v9 && Scaleform::GFx::InteractiveObject::IsInPlayList(v9) )
        {
          v13 = (signed __int64)v9 + 4 * (unsigned __int8)v9->AvmObjOffset;
          v14 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v13 + 8i64))(v13);
          v15 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v14 - 56);
          if ( !v14 )
            v15 = 0i64;
          Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v15);
        }
        if ( *(_BYTE *)(v7 + 136) & 1 )
        {
          *(_WORD *)(v7 + 136) &= 0xFFFEu;
          (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v7 + 424i64))(v7, 0i64);
          *(_DWORD *)(v7 + 48) = 0;
          *(_DWORD *)(v7 + 44) = -1;
          v16 = v7 + 4i64 * *(unsigned __int8 *)(v7 + 109);
          v17 = *(_QWORD *)(v16 + 16);
          if ( !v17 )
            v17 = *(_QWORD *)(v16 + 8);
          if ( v17 & 1 )
            --v17;
          *(_QWORD *)(v16 + 16) = v17;
          v18 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v16 + 8);
          if ( v18 )
          {
            if ( (unsigned __int8)v18 & 1 )
            {
              *(_QWORD *)(v16 + 8) = (char *)v18 - 1;
            }
            else
            {
              v19 = v18->RefCount;
              if ( v19 & 0x3FFFFF )
              {
                v18->RefCount = v19 - 1;
                Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
              }
            }
            *(_QWORD *)(v16 + 8) = 0i64;
          }
        }
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v7);
      }
      v2 = v1->pDispObj;
      v3 = LODWORD(v2[1].pGeomData) > 0;
    }
    while ( LODWORD(v2[1].pGeomData) > 0 );
  }
  Scaleform::GFx::AS3::AvmDisplayObj::OnEventUnload((Scaleform::GFx::AS3::AvmDisplayObj *)&v1->vfptr);
}
  }
  Scaleform::GFx::AS3::AvmDisplayObj::OnEventUnload((Scaleform::GFx::AS3::AvmDisplayObj

// File Line: 40
// RVA: 0x7F0580
signed __int64 __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetTopMostEntity(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::Render::Point<float> *localPt, Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr, Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *hitTest)
{
  const char *v4; // rdi
  Scaleform::GFx::DisplayObjectBase::TopMostDescr *v5; // rbx
  Scaleform::Render::Point<float> *v6; // r14
  __int64 v7; // r13
  __int64 v8; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v9; // r8
  Scaleform::GFx::InteractiveObject *v10; // r9
  float v11; // xmm6_4
  float v12; // xmm7_4
  unsigned int v13; // er10
  bool v14; // r11
  char v15; // dl
  Scaleform::GFx::DisplayObject *v16; // r12
  signed __int64 v17; // rsi
  Scaleform::GFx::DisplayObject *v18; // r15
  signed int v19; // ebp
  signed __int64 v20; // r14
  __int64 v21; // rcx
  int v22; // eax
  int v23; // edx
  Scaleform::GFx::InteractiveObject *v24; // r8
  Scaleform::GFx::InteractiveObject *v25; // rax
  signed __int64 result; // rax
  Scaleform::GFx::InteractiveObject *v27; // rax
  float v28; // xmm0_4
  bool v29; // [rsp+20h] [rbp-98h]
  char v30; // [rsp+21h] [rbp-97h]
  unsigned int v31; // [rsp+24h] [rbp-94h]
  Scaleform::GFx::InteractiveObject *v32; // [rsp+28h] [rbp-90h]
  Scaleform::GFx::InteractiveObject *v33; // [rsp+30h] [rbp-88h]
  Scaleform::GFx::InteractiveObject *v34; // [rsp+38h] [rbp-80h]
  float v35; // [rsp+40h] [rbp-78h]
  float v36; // [rsp+44h] [rbp-74h]
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v37; // [rsp+C0h] [rbp+8h]
  Scaleform::Render::Point<float> *v38; // [rsp+C8h] [rbp+10h]
  Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *v39; // [rsp+D8h] [rbp+20h]

  v39 = hitTest;
  v38 = localPt;
  v37 = this;
  v4 = this[-1].pClassName;
  v5 = pdescr;
  v6 = localPt;
  v7 = (*(__int64 (__fastcall **)(const char *))(*(_QWORD *)v4 + 968i64))(this[-1].pClassName);
  v8 = (*(__int64 (__fastcall **)(const char *))(*(_QWORD *)v4 + 960i64))(v4);
  v9 = v37;
  v10 = 0i64;
  v11 = v36;
  v12 = v35;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0i64;
  v17 = *((_QWORD *)v37[-1].pClassName + 28) - 1i64;
  v18 = (Scaleform::GFx::DisplayObject *)v8;
  v33 = 0i64;
  v31 = 0;
  v29 = 0;
  v19 = 2;
  v30 = 0;
  if ( v17 >= 0 )
  {
    v32 = v34;
    v20 = 16 * v17;
    while ( 1 )
    {
      v21 = *(_QWORD *)(v20 + *((_QWORD *)v9[-1].pClassName + 27));
      if ( (!v39->Data.Size || v39->Data.Data[v17] && !*(_WORD *)(v21 + 104)) && !((*(_BYTE *)(v21 + 106) >> 1) & 1) )
        break;
LABEL_21:
      v14 = v29;
      v13 = v31;
      v10 = v33;
      v24 = v32;
LABEL_22:
      v15 = v30;
LABEL_23:
      v20 -= 16i64;
      if ( --v17 < 0 )
      {
        v6 = v38;
        goto LABEL_38;
      }
      v9 = v37;
    }
    v22 = (*(__int64 (__fastcall **)(__int64, Scaleform::Render::Point<float> *, Scaleform::GFx::DisplayObjectBase::TopMostDescr *))(*(_QWORD *)v21 + 512i64))(
            v21,
            v38,
            v5);
    v23 = v22;
    if ( v22 == 1 )
    {
      if ( (*((_DWORD *)v4 + 46) >> 13) & 1 )
        v5->pResult = (Scaleform::GFx::InteractiveObject *)v4;
      if ( v5->pResult )
      {
        v24 = v32;
        v10 = v33;
        v13 = v31;
        v14 = v29;
        if ( (v5->pResult->Flags >> 12) & 1 )
        {
          v15 = 1;
          v5->pResult = (Scaleform::GFx::InteractiveObject *)v4;
          v30 = 1;
          goto LABEL_23;
        }
LABEL_18:
        if ( v7 )
        {
          v5->pHitArea = (Scaleform::GFx::DisplayObject *)v4;
        }
        else if ( v18 )
        {
          v25 = v5->pResult;
          if ( !v5->pResult || v25 == (Scaleform::GFx::InteractiveObject *)v4 || SLOBYTE(v25->Flags) >= 0 )
          {
            if ( v18 == v5->pHitArea )
              goto LABEL_31;
            v5->pResult = 0i64;
            v19 = 2;
            goto LABEL_22;
          }
        }
        goto LABEL_20;
      }
    }
    else
    {
      if ( v22 == 3 && v5->pResult )
      {
        v10 = v5->pIgnoreMC;
        v13 = v5->ControllerIdx;
        v14 = v5->TestAll;
        v12 = v5->LocalPt.x;
        v11 = v5->LocalPt.y;
        v16 = v5->pHitArea;
        v33 = v5->pIgnoreMC;
        v31 = v5->ControllerIdx;
        v29 = v5->TestAll;
        v19 = 1;
        v24 = v5->pResult;
        v32 = v5->pResult;
        goto LABEL_18;
      }
      if ( v19 != 1 )
      {
LABEL_20:
        if ( v23 == 1 )
        {
          if ( v7 && (const char *)v5->pResult == v4 )
            v5->pHitArea = (Scaleform::GFx::DisplayObject *)v4;
          return 1i64;
        }
        goto LABEL_21;
      }
    }
    v14 = v29;
    v13 = v31;
    v10 = v33;
    v24 = v32;
    goto LABEL_18;
  }
  v24 = v34;
LABEL_38:
  if ( v18 )
  {
    v27 = v5->pResult;
    if ( !v5->pResult || v27 == (Scaleform::GFx::InteractiveObject *)v4 || SLOBYTE(v27->Flags) >= 0 )
    {
      if ( v18 == v5->pHitArea )
      {
LABEL_31:
        v5->pResult = (Scaleform::GFx::InteractiveObject *)v4;
        return 1i64;
      }
      result = 2i64;
      goto LABEL_54;
    }
  }
  if ( v19 == 1 )
  {
    v5->pResult = v24;
    v5->LocalPt.x = v12;
    v5->LocalPt.y = v11;
    v5->pIgnoreMC = v10;
    v5->pHitArea = v16;
    v5->ControllerIdx = v13;
    v5->TestAll = v14;
    if ( v7 )
    {
      if ( v24 == (Scaleform::GFx::InteractiveObject *)v4 )
        v16 = (Scaleform::GFx::DisplayObject *)v4;
      v5->pHitArea = v16;
    }
    return 1i64;
  }
  v28 = v6->y;
  v5->LocalPt.x = v6->x;
  v5->LocalPt.y = v28;
  if ( !v15 )
  {
    result = 3i64;
LABEL_54:
    v5->pResult = 0i64;
    return result;
  }
  v5->pResult = (Scaleform::GFx::InteractiveObject *)v4;
  if ( !v7 )
    return 1i64;
  v5->pHitArea = (Scaleform::GFx::DisplayObject *)v4;
  return 1i64;
}

// File Line: 180
// RVA: 0x7D16F0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::FillTabableArray(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::InteractiveObject::FillTabableParams *params)
{
  Scaleform::GFx::InteractiveObject::FillTabableParams *v2; // rsi
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v3; // r15
  const char *v4; // rax
  __int64 v5; // rbp
  __int64 v6; // r14
  Scaleform::GFx::DisplayObjContainer *v7; // rbx
  Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> *v8; // rdi
  _QWORD *v9; // rdx

  v2 = params;
  v3 = this;
  v4 = this[-1].pClassName;
  v5 = *((_QWORD *)v4 + 28);
  if ( v5 && !((*((_DWORD *)v4 + 46) >> 15) & 1) && v5 )
  {
    v6 = 0i64;
    do
    {
      v7 = *(Scaleform::GFx::DisplayObjContainer **)(v6 + *((_QWORD *)v3[-1].pClassName + 27));
      if ( v7
        && SLOBYTE(v7->Flags) < 0
        && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v7->vfptr[59].__vecDelDtor)(v7) )
      {
        if ( v7->TabIndex > 0 && !v2->TabIndexed )
        {
          Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Resize(
            &v2->Array->Data,
            0i64);
          v2->TabIndexed = 1;
        }
        if ( (((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v7->vfptr[87].__vecDelDtor)(v7)
           || v2->InclFocusEnabled
           && (unsigned __int8)v7->vfptr[89].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v7->vfptr, 2u))
          && (!v2->TabIndexed || v7->TabIndex > 0) )
        {
          ++v7->RefCount;
          v8 = &v2->Array->Data;
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy> *)&v2->Array->Data.Data,
            v2->Array->Data.pHeap,
            v2->Array->Data.Size + 1);
          v9 = &v8->Data[v8->Size - 1].pObject;
          if ( v9 )
          {
            ++v7->RefCount;
            *v9 = v7;
          }
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v7->vfptr);
        }
        if ( (v7->Flags >> 9) & 1 )
          Scaleform::GFx::DisplayObjContainer::FillTabableArray(v7, v2);
      }
      v6 += 16i64;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 220
// RVA: 0x7C4990
bool __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::DetachChild(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::DisplayObjectBase *ch)
{
  return Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(this, ch) != 0i64;
}

// File Line: 227
// RVA: 0x8114C0
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v3; // rsi
  Scaleform::GFx::DisplayObjectBase *v4; // rdi
  Scaleform::GFx::DisplayObjectBase *v5; // rcx
  signed __int64 v6; // rcx
  Scaleform::GFx::DisplayObject *v7; // rbp
  signed __int64 v8; // rax
  Scaleform::GFx::InteractiveObject *v9; // rsi
  signed __int64 v10; // rcx
  __int64 v11; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v12; // rcx

  v2 = ch;
  v3 = this;
  if ( ch )
    ++ch->RefCount;
  v4 = 0i64;
  v5 = 0i64;
  if ( ch->Flags & 0x100 )
    v5 = ch;
  if ( v5 )
    v6 = (signed __int64)v5 + 4 * (unsigned __int8)v5->AvmObjOffset;
  else
    v6 = 0i64;
  (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v6 + 104i64))(v6, 0i64);
  if ( v2->Flags & 0x100 && v2->ClipDepth > 0u )
    Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)v2, 0i64, 1);
  if ( (v2->Flags & 0x8000u) != 0 )
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(v3->pDispObj->pASRoot->pMovieImpl, v2);
  v7 = v3->pDispObj;
  v8 = Scaleform::GFx::DisplayList::FindDisplayIndex((Scaleform::GFx::DisplayList *)&v7[1].pRenNode, v2);
  if ( v8 >= 0 )
  {
    Scaleform::GFx::DisplayList::RemoveEntryAtIndex(
      (Scaleform::GFx::DisplayList *)&v7[1].pRenNode,
      (Scaleform::GFx::DisplayObjectBase *)&v3->pDispObj->vfptr,
      v8);
    BYTE2(v7[1].pNameHandle.pObject) |= 3u;
    v9 = 0i64;
    if ( SLOBYTE(v2->Flags) < 0 )
      v9 = (Scaleform::GFx::InteractiveObject *)v2;
    v2->pParent = 0i64;
    if ( v9 && Scaleform::GFx::InteractiveObject::IsInPlayList(v9) )
    {
      v10 = (signed __int64)v9 + 4 * (unsigned __int8)v9->AvmObjOffset;
      v11 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v10 + 8i64))(v10);
      v12 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v11 - 56);
      if ( !v11 )
        v12 = 0i64;
      Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v12);
    }
    if ( (_QWORD)v2[1].vfptr & 1 )
    {
      LOWORD(v2[1].vfptr) &= 0xFFFEu;
      v2->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 0);
      v2->CreateFrame = 0;
      v2->Depth = -1;
      Scaleform::GFx::AS3::AvmDisplayObj::OnDetachFromTimeline((Scaleform::GFx::AS3::AvmDisplayObj *)((char *)v2 + 4 * (unsigned __int8)v2->AvmObjOffset));
    }
    v4 = v2;
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v2->vfptr);
  return v4;
}

// File Line: 277
// RVA: 0x811710
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChildAt(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, unsigned int index)
{
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v2; // rdi
  Scaleform::GFx::DisplayObject *v3; // rax
  Scaleform::GFx::DisplayList *v5; // rsi
  unsigned __int64 v6; // rbp
  __int64 v7; // rbx
  __int16 v8; // cx
  Scaleform::GFx::InteractiveObject *v9; // rdi
  bool v10; // zf
  __int64 v11; // rcx
  signed __int64 v12; // rcx
  signed __int64 v13; // rcx
  __int64 v14; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v15; // rcx

  v2 = this;
  v3 = this->pDispObj;
  if ( index >= LODWORD(v3[1].pGeomData) )
    return 0i64;
  v5 = (Scaleform::GFx::DisplayList *)&v3[1].pRenNode;
  v6 = index;
  v7 = *((_QWORD *)&v3[1].pRenNode.pObject->pPrev + 2 * index);
  if ( v7 )
    ++*(_DWORD *)(v7 + 8);
  if ( *(_BYTE *)(v7 + 107) & 1 )
    Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)v7, 0i64, 1);
  if ( *(_WORD *)(v7 + 106) < 0 )
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(
      v2->pDispObj->pASRoot->pMovieImpl,
      (Scaleform::GFx::DisplayObjectBase *)v7);
  Scaleform::GFx::DisplayList::RemoveEntryAtIndex(v5, (Scaleform::GFx::DisplayObjectBase *)&v2->pDispObj->vfptr, v6);
  v5->Flags |= 3u;
  v8 = *(_WORD *)(v7 + 106);
  v9 = 0i64;
  if ( (v8 & 0x80u) != 0 )
    v9 = (Scaleform::GFx::InteractiveObject *)v7;
  v10 = (v8 & 0x100) == 0;
  v11 = 0i64;
  if ( !v10 )
    v11 = v7;
  if ( v11 )
    v12 = v11 + 4i64 * *(unsigned __int8 *)(v11 + 109);
  else
    v12 = 0i64;
  (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v12 + 104i64))(v12, 0i64);
  *(_QWORD *)(v7 + 56) = 0i64;
  if ( v9 && Scaleform::GFx::InteractiveObject::IsInPlayList(v9) )
  {
    v13 = (signed __int64)v9 + 4 * (unsigned __int8)v9->AvmObjOffset;
    v14 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v13 + 8i64))(v13);
    v15 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v14 - 56);
    if ( !v14 )
      v15 = 0i64;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v15);
  }
  if ( *(_BYTE *)(v7 + 136) & 1 )
  {
    *(_WORD *)(v7 + 136) &= 0xFFFEu;
    (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v7 + 424i64))(v7, 0i64);
    *(_DWORD *)(v7 + 48) = 0;
    *(_DWORD *)(v7 + 44) = -1;
    Scaleform::GFx::AS3::AvmDisplayObj::OnDetachFromTimeline((Scaleform::GFx::AS3::AvmDisplayObj *)(v7
                                                                                                  + 4i64 * *(unsigned __int8 *)(v7 + 109)));
  }
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v7);
  return (Scaleform::GFx::DisplayObjectBase *)v7;
}

// File Line: 317
// RVA: 0x8186D0
char __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::DisplayObjectBase *ch, unsigned int index)
{
  unsigned __int64 v3; // rbp
  Scaleform::GFx::DisplayObjectBase *v4; // rbx
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v5; // rsi
  Scaleform::GFx::DisplayObject *v6; // rdi
  Scaleform::GFx::DisplayList *v8; // rdi
  signed __int64 v9; // rax

  v3 = index;
  v4 = ch;
  v5 = this;
  v6 = this->pDispObj;
  if ( index >= LODWORD(v6[1].pGeomData) )
    return 0;
  v8 = (Scaleform::GFx::DisplayList *)&v6[1].pRenNode;
  v9 = Scaleform::GFx::DisplayList::FindDisplayIndex(v8, ch);
  if ( v9 < 0 )
    return 0;
  if ( v4 )
    ++v4->RefCount;
  Scaleform::GFx::DisplayList::RemoveEntryAtIndex(v8, (Scaleform::GFx::DisplayObjectBase *)&v5->pDispObj->vfptr, v9);
  Scaleform::GFx::DisplayList::AddEntryAtIndex(v8, (Scaleform::GFx::DisplayObjectBase *)&v5->pDispObj->vfptr, v3, v4);
  v4->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v4->vfptr, 0);
  v4->CreateFrame = 0;
  v4->Depth = -1;
  v8->Flags |= 3u;
  Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->vfptr);
  return 1;
}

// File Line: 340
// RVA: 0x825160
bool __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildren(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::DisplayObjectBase *ch1, Scaleform::GFx::DisplayObjectBase *ch2)
{
  Scaleform::GFx::DisplayObject *v3; // rdi
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v4; // rbp
  Scaleform::GFx::DisplayObjectBase *v5; // rsi
  unsigned int v6; // ebx
  unsigned int v7; // eax

  v3 = this->pDispObj;
  v4 = this;
  v5 = ch2;
  v6 = Scaleform::GFx::DisplayList::FindDisplayIndex((Scaleform::GFx::DisplayList *)&v3[1].pRenNode, ch1);
  v7 = Scaleform::GFx::DisplayList::FindDisplayIndex((Scaleform::GFx::DisplayList *)&v3[1].pRenNode, v5);
  return Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildrenAt(v4, v6, v7);
}

// File Line: 348
// RVA: 0x8251C0
char __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildrenAt(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, unsigned int i1, unsigned int i2)
{
  Scaleform::GFx::DisplayObject *v3; // r10
  __int64 v4; // rdi
  signed __int64 v5; // r14
  unsigned __int64 v6; // rax
  __int64 v8; // rbx
  __int64 v9; // rdi
  __int64 v10; // rbx
  Scaleform::GFx::AS3::AvmInteractiveObj *v11; // rsi
  __int64 v12; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v13; // rcx
  __int64 v14; // rax

  v3 = this->pDispObj;
  v4 = i1;
  v5 = (signed __int64)&v3[1].pRenNode;
  v6 = (unsigned __int64)v3[1].pGeomData;
  if ( i1 >= v6 )
    return 0;
  v8 = i2;
  if ( i2 >= v6
    || !Scaleform::GFx::DisplayList::SwapEntriesAtIndexes(
          (Scaleform::GFx::DisplayList *)&v3[1].pRenNode,
          (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr,
          i1,
          i2) )
  {
    return 0;
  }
  v9 = *(_QWORD *)(*(_QWORD *)v5 + 16 * v4);
  v10 = *(_QWORD *)(*(_QWORD *)v5 + 16 * v8);
  v11 = 0i64;
  if ( v9 )
  {
    (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v9 + 424i64))(v9, 0i64);
    *(_DWORD *)(v9 + 48) = 0;
    *(_DWORD *)(v9 + 44) = -1;
  }
  if ( v10 )
  {
    (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v10 + 424i64))(v10, 0i64);
    *(_DWORD *)(v10 + 48) = 0;
    *(_DWORD *)(v10 + 44) = -1;
  }
  *(_BYTE *)(v5 + 42) |= 3u;
  if ( *(_BYTE *)(v9 + 106) < 0 )
  {
    v12 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v9 + 4i64 * *(unsigned __int8 *)(v9 + 109)) + 8i64))(v9 + 4i64 * *(unsigned __int8 *)(v9 + 109));
    v13 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v12 - 56);
    if ( !v12 )
      v13 = 0i64;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v13);
  }
  if ( *(_BYTE *)(v10 + 106) < 0 )
  {
    v14 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v10 + 4i64 * *(unsigned __int8 *)(v10 + 109)) + 8i64))(v10 + 4i64 * *(unsigned __int8 *)(v10 + 109));
    if ( v14 )
      v11 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v14 - 56);
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v11);
  }
  return 1;
}

// File Line: 383
// RVA: 0x7AB530
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::DisplayObject *v2; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v3; // rdi
  Scaleform::GFx::InteractiveObject *v4; // rcx
  Scaleform::GFx::DisplayList *v5; // rbp
  signed __int64 v6; // rsi
  Scaleform::GFx::DisplayObjectBase *v7; // rbx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v8; // r14
  __int64 v9; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v10; // rcx
  unsigned __int16 v11; // cx
  unsigned __int16 v12; // cx
  Scaleform::GFx::InteractiveObject *v13; // rax
  __int64 v14; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v15; // rcx
  Scaleform::GFx::DisplayObject *v16; // rdi
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v17; // rax
  long double v18; // xmm1_8
  long double v19; // xmm0_8
  long double v20; // xmm1_8
  Scaleform::Render::Rect<double> r; // [rsp+20h] [rbp-28h]

  v2 = this->pDispObj;
  v3 = this;
  v4 = ch->pParent;
  v5 = (Scaleform::GFx::DisplayList *)&v2[1].pRenNode;
  v6 = 0i64;
  v7 = ch;
  v8 = v2[1].pGeomData;
  if ( v4 )
  {
    if ( v4 == (Scaleform::GFx::InteractiveObject *)v2 )
    {
      Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(v3, ch, (_DWORD)v8 - 1);
      return;
    }
    v9 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr
                                                                     + 4 * (unsigned __int8)v4->AvmObjOffset))[5].__vecDelDtor)();
    v10 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v9 - 72);
    if ( !v9 )
      v10 = 0i64;
    Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(v10, v7);
  }
  Scaleform::GFx::DisplayList::AddEntryAtIndex(
    v5,
    (Scaleform::GFx::DisplayObjectBase *)&v3->pDispObj->vfptr,
    (unsigned int)v8,
    v7);
  v5->Flags |= 3u;
  v11 = v7->Flags;
  if ( ((unsigned __int8)v11 >> 4) & 1 )
  {
    v12 = v11 & 0xEFEF;
    v7->Flags = v12;
    if ( (v12 >> 9) & 1 )
      Scaleform::GFx::AS3::MovieRoot::AddScriptableMovieClip(
        (Scaleform::GFx::AS3::MovieRoot *)v3->pDispObj->pASRoot,
        (Scaleform::GFx::DisplayObjContainer *)v7);
  }
  v13 = (Scaleform::GFx::InteractiveObject *)v3->pDispObj;
  v7->Depth = -1;
  v7->pParent = v13;
  if ( SLOBYTE(v7->Flags) < 0
    && Scaleform::GFx::InteractiveObject::IsInPlayList((Scaleform::GFx::InteractiveObject *)v7) )
  {
    v14 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v7->vfptr
                                                                                           + 4
                                                                                           * (unsigned __int8)v7->AvmObjOffset))[1].__vecDelDtor)((signed __int64)v7 + 4 * (unsigned __int8)v7->AvmObjOffset);
    v15 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v14 - 56);
    if ( !v14 )
      v15 = 0i64;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v15);
  }
  v16 = 0i64;
  if ( v7->Flags & 0x100 )
    v16 = (Scaleform::GFx::DisplayObject *)v7;
  if ( v16 )
    v6 = (signed __int64)v16 + 4 * (unsigned __int8)v16->AvmObjOffset;
  (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v6 + 152i64))(v6, 0i64);
  v17 = v16->pScrollRect;
  if ( v17 )
  {
    v18 = v17->Rectangle.y1;
    r.x1 = v17->Rectangle.x1;
    v19 = v17->Rectangle.x2;
    r.y1 = v18;
    v20 = v17->Rectangle.y2;
    r.x2 = v19;
    r.y2 = v20;
    Scaleform::GFx::DisplayObject::SetScrollRect(v16, &r);
  }
}

// File Line: 438
// RVA: 0x7AB770
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::DisplayObjectBase *ch, unsigned int index)
{
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  Scaleform::GFx::DisplayObject *v4; // rdx
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v5; // rdi
  Scaleform::GFx::InteractiveObject *v6; // rcx
  unsigned int v7; // ebp
  Scaleform::GFx::DisplayList *v8; // r14
  signed __int64 v9; // rsi
  __int64 v10; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v11; // rcx
  unsigned __int16 v12; // cx
  unsigned __int16 v13; // cx
  Scaleform::GFx::InteractiveObject *v14; // rax
  __int64 v15; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v16; // rcx
  Scaleform::GFx::DisplayObject *v17; // rdi
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v18; // rax
  long double v19; // xmm1_8
  long double v20; // xmm0_8
  long double v21; // xmm1_8
  Scaleform::Render::Rect<double> r; // [rsp+20h] [rbp-28h]

  v3 = ch;
  v4 = this->pDispObj;
  v5 = this;
  v6 = v3->pParent;
  v7 = index;
  v8 = (Scaleform::GFx::DisplayList *)&v4[1].pRenNode;
  if ( index > LODWORD(v4[1].pGeomData) )
    v7 = (unsigned int)v4[1].pGeomData;
  v9 = 0i64;
  if ( v6 )
  {
    if ( v6 == (Scaleform::GFx::InteractiveObject *)v4 )
    {
      Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(v5, v3, v7);
      return;
    }
    v10 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v6->vfptr
                                                                      + 4 * (unsigned __int8)v6->AvmObjOffset))[5].__vecDelDtor)();
    v11 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v10 - 72);
    if ( !v10 )
      v11 = 0i64;
    Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(v11, v3);
  }
  Scaleform::GFx::DisplayList::AddEntryAtIndex(v8, (Scaleform::GFx::DisplayObjectBase *)&v5->pDispObj->vfptr, v7, v3);
  v12 = v3->Flags;
  if ( ((unsigned __int8)v12 >> 4) & 1 )
  {
    v13 = v12 & 0xEFEF;
    v3->Flags = v13;
    if ( (v13 >> 9) & 1 )
      Scaleform::GFx::AS3::MovieRoot::AddScriptableMovieClip(
        (Scaleform::GFx::AS3::MovieRoot *)v5->pDispObj->pASRoot,
        (Scaleform::GFx::DisplayObjContainer *)v3);
  }
  v14 = (Scaleform::GFx::InteractiveObject *)v5->pDispObj;
  v3->Depth = -1;
  v3->pParent = v14;
  if ( SLOBYTE(v3->Flags) < 0
    && Scaleform::GFx::InteractiveObject::IsInPlayList((Scaleform::GFx::InteractiveObject *)v3) )
  {
    v15 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr
                                                                                           + 4
                                                                                           * (unsigned __int8)v3->AvmObjOffset))[1].__vecDelDtor)((signed __int64)v3 + 4 * (unsigned __int8)v3->AvmObjOffset);
    v16 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v15 - 56);
    if ( !v15 )
      v16 = 0i64;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v16);
  }
  v17 = 0i64;
  if ( v3->Flags & 0x100 )
    v17 = (Scaleform::GFx::DisplayObject *)v3;
  if ( v17 )
    v9 = (signed __int64)v17 + 4 * (unsigned __int8)v17->AvmObjOffset;
  (*(void (__fastcall **)(signed __int64, _QWORD))(*(_QWORD *)v9 + 152i64))(v9, 0i64);
  v18 = v17->pScrollRect;
  if ( v18 )
  {
    v19 = v18->Rectangle.y1;
    r.x1 = v18->Rectangle.x1;
    v20 = v18->Rectangle.x2;
    r.y1 = v19;
    v21 = v18->Rectangle.y2;
    r.x2 = v20;
    r.y2 = v21;
    Scaleform::GFx::DisplayObject::SetScrollRect(v17, &r);
  }
}

// File Line: 492
// RVA: 0x7E4750
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildAt(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result, unsigned int index)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v3; // rbx
  Scaleform::GFx::DisplayObjectBase *v4; // rax
  __int64 v5; // rdx
  _QWORD *v6; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v7; // rax

  v3 = result;
  v4 = Scaleform::GFx::DisplayObjContainer::GetChildAt((Scaleform::GFx::DisplayObjContainer *)this->pDispObj, index);
  if ( v4 )
  {
    v6 = (Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr + 4 * (unsigned __int8)v4->AvmObjOffset);
    LOBYTE(v5) = 1;
    (*(void (__fastcall **)(_QWORD *, __int64))(*v6 + 112i64))(v6, v5);
    v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v6[2];
    if ( !v7 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v6[1];
    if ( (unsigned __int8)v7 & 1 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
    v3->pObject = v7;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
  }
  else
  {
    v3->pObject = 0i64;
  }
  return v3;
}

// File Line: 504
// RVA: 0x7E47E0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *v3; // rbx
  Scaleform::GFx::DisplayObject *v4; // rax
  __int64 v5; // rdx
  _QWORD *v6; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v7; // rax

  v3 = result;
  v4 = Scaleform::GFx::DisplayList::GetDisplayObjectByName(
         (Scaleform::GFx::DisplayList *)&this->pDispObj[1].pRenNode,
         name,
         1);
  if ( v4 )
  {
    v6 = (Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v4->vfptr + 4 * (unsigned __int8)v4->AvmObjOffset);
    LOBYTE(v5) = 1;
    (*(void (__fastcall **)(_QWORD *, __int64))(*v6 + 112i64))(v6, v5);
    v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v6[2];
    if ( !v7 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v6[1];
    if ( (unsigned __int8)v7 & 1 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
    v3->pObject = v7;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
  }
  else
  {
    v3->pObject = 0i64;
  }
  return v3;
}

// File Line: 518
// RVA: 0x7D2910
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::FindInsertToPlayList(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::DisplayObject *v2; // rbp
  Scaleform::GFx::InteractiveObject *v3; // r13
  unsigned int v4; // er15
  __int64 v5; // r12
  Scaleform::GFx::InteractiveObject *v7; // rdi
  unsigned int v8; // ebx
  __int64 v9; // r14
  __int64 v10; // rsi
  unsigned int v11; // ebx
  signed __int64 v12; // rsi
  __int64 v13; // r14
  Scaleform::GFx::DisplayObject *v14; // rcx
  Scaleform::GFx::InteractiveObject *v15; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v16; // [rsp+50h] [rbp+8h]

  v16 = this;
  v2 = this->pDispObj;
  v3 = ch;
  if ( (LOBYTE(v2->Flags) >> 4) & 1 || v2->Flags & 0x1000 || v2->Depth < -1 )
    return 0i64;
  v4 = (unsigned int)v2[1].pGeomData;
  v5 = 0i64;
  if ( !v4 )
    return *(Scaleform::GFx::InteractiveObject **)&v2[1].RefCount;
  v7 = 0i64;
  v8 = 0;
  if ( !v4 )
    return *(Scaleform::GFx::InteractiveObject **)&v2[1].RefCount;
  v9 = 0i64;
  do
  {
    v10 = *(__int64 *)((char *)&v2[1].pRenNode.pObject->pPrev + v9);
    if ( (Scaleform::GFx::InteractiveObject *)v10 == v3 )
      break;
    if ( *(_BYTE *)(v10 + 106) < 0
      && Scaleform::GFx::InteractiveObject::IsInPlayList((Scaleform::GFx::InteractiveObject *)v10) )
    {
      v7 = (Scaleform::GFx::InteractiveObject *)v10;
    }
    ++v8;
    v9 += 16i64;
  }
  while ( v8 < v4 );
  if ( !v7 )
    return *(Scaleform::GFx::InteractiveObject **)&v2[1].RefCount;
  v11 = v8 + 1;
  if ( v11 >= v4 )
  {
LABEL_19:
    v14 = v16->pDispObj;
    do
    {
      v15 = v7;
      while ( v15 != (Scaleform::GFx::InteractiveObject *)v14 )
      {
        if ( v15 != v14->pParent )
        {
          v15 = v15->pParent;
          if ( v15 )
            continue;
        }
        return v7;
      }
      v7 = v7->pPlayPrev;
    }
    while ( v7 );
  }
  else
  {
    v12 = 16i64 * v11;
    while ( 1 )
    {
      v13 = *(__int64 *)((char *)&v2[1].pRenNode.pObject->pPrev + v12);
      if ( *(_BYTE *)(v13 + 106) < 0
        && Scaleform::GFx::InteractiveObject::IsInPlayList(*(Scaleform::GFx::InteractiveObject **)((char *)&v2[1].pRenNode.pObject->pPrev
                                                                                                 + v12)) )
      {
        break;
      }
      ++v11;
      v12 += 16i64;
      if ( v11 >= v4 )
        goto LABEL_19;
    }
    v5 = v13;
  }
  return (Scaleform::GFx::InteractiveObject *)v5;
}

// File Line: 617
// RVA: 0x80A530
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::PropagateEvent(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::GFx::AS3::Instances::fl_events::Event *evtProto, bool inclChildren)
{
  bool v3; // bl
  Scaleform::GFx::AS3::Instances::fl_events::Event *v4; // r15
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v5; // rdi
  __int64 v6; // r8
  Scaleform::GFx::DisplayObject *v7; // rbp
  unsigned int v8; // esi
  Scaleform::GFx::DisplayObjectBase *v9; // rbx
  __int64 v10; // rdx
  signed __int64 v11; // rcx
  int v12; // edi
  __int64 v13; // rax

  v3 = inclChildren;
  v4 = evtProto;
  v5 = this;
  Scaleform::GFx::AS3::AvmDisplayObj::PropagateEvent((Scaleform::GFx::AS3::AvmDisplayObj *)&this->vfptr, evtProto, 1);
  if ( v3 )
  {
    v7 = v5->pDispObj;
    v8 = 0;
    if ( LODWORD(v7[1].pGeomData) )
    {
      while ( 1 )
      {
        v9 = (Scaleform::GFx::DisplayObjectBase *)*((_QWORD *)&v7[1].pRenNode.pObject->pPrev + 2 * v8);
        if ( v9 )
          ++v9->RefCount;
        v10 = 0i64;
        if ( *(_BYTE *)(*((_QWORD *)&v7[1].pRenNode.pObject->pPrev + 2 * v8) + 107i64) & 1 )
          v10 = *((_QWORD *)&v7[1].pRenNode.pObject->pPrev + 2 * v8);
        v11 = v10 ? v10 + 4i64 * *(unsigned __int8 *)(v10 + 109) : 0i64;
        v12 = LOWORD(v7[1].pNameHandle.pObject);
        LOBYTE(v6) = 1;
        (*(void (__fastcall **)(signed __int64, Scaleform::GFx::AS3::Instances::fl_events::Event *, __int64))(*(_QWORD *)v11 + 144i64))(
          v11,
          v4,
          v6);
        if ( LOWORD(v7[1].pNameHandle.pObject) != v12 )
        {
          v13 = Scaleform::GFx::DisplayList::FindDisplayIndex((Scaleform::GFx::DisplayList *)&v7[1].pRenNode, v9);
          v8 = v13;
          if ( v13 < 0 )
            break;
        }
        if ( v9 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v9->vfptr);
        if ( ++v8 >= LODWORD(v7[1].pGeomData) )
          return;
      }
      if ( v9 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v9->vfptr);
    }
  }
}

// File Line: 661
// RVA: 0x7ED300
bool __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetObjectsUnderPoint(Scaleform::GFx::AS3::AvmDisplayObjContainer *this, Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *destArray, Scaleform::Render::Point<float> *pt)
{
  Scaleform::Render::Point<float> *v3; // r15
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *v4; // r13
  Scaleform::GFx::DisplayObjContainer *v5; // r14
  unsigned __int64 v7; // rdi
  Scaleform::GFx::DisplayObject *v8; // rax
  Scaleform::GFx::DisplayObject *v9; // rbx
  float v10; // xmm2_4
  float v11; // xmm3_4
  __int64 v12; // r8
  float v13; // xmm2_4
  unsigned __int64 v14; // r12
  signed __int64 v15; // rdi
  signed __int64 v16; // rsi
  Scaleform::GFx::DisplayObjectBase *v17; // rbx
  _OWORD *v20; // rax
  signed __int64 v21; // rcx
  bool v22; // bl
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+10h] [rbp-69h]
  Scaleform::Render::Matrix2x4<float> v24; // [rsp+30h] [rbp-49h]
  Scaleform::Render::Point<float> v25; // [rsp+E0h] [rbp+67h]
  Scaleform::Render::Point<float> result; // [rsp+F8h] [rbp+7Fh]

  *(_QWORD *)&pmat.M[1][2] = -2i64;
  v3 = pt;
  v4 = destArray;
  v5 = (Scaleform::GFx::DisplayObjContainer *)this->pDispObj;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v5->vfptr[59].__vecDelDtor)(this->pDispObj) )
    return 0;
  v7 = v5->mDisplayList.DisplayObjectArray.Data.Size;
  v8 = Scaleform::GFx::DisplayObject::GetMask((Scaleform::GFx::DisplayObject *)&v5->vfptr);
  v9 = v8;
  if ( v8 )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v8->vfptr[78].__vecDelDtor)(v8) )
    {
      if ( !((LOBYTE(v9->Flags) >> 4) & 1) )
      {
        *(_OWORD *)&v24.M[0][0] = _xmm;
        *(__m128 *)&v24.M[1][0] = _xmm;
        *(__m128 *)&pmat.M[1][0] = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix((Scaleform::GFx::DisplayObjectBase *)&v9->vfptr, &pmat);
        Scaleform::Render::Matrix2x4<float>::SetInverse(&v24, &pmat);
        *(__m128 *)&pmat.M[1][0] = _xmm;
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix((Scaleform::GFx::DisplayObjectBase *)&v5->vfptr, &pmat);
        v10 = v3->y;
        v11 = v3->x;
        result.x = (float)((float)(v3->x
                                 * (float)((float)(pmat.M[1][0] * v24.M[0][1]) + (float)(pmat.M[0][0] * v24.M[0][0])))
                         + (float)(v3->y
                                 * (float)((float)(pmat.M[1][1] * v24.M[0][1]) + (float)(v24.M[0][0] * pmat.M[0][1]))))
                 + (float)(v24.M[0][3]
                         + (float)((float)(v24.M[0][1] * pmat.M[1][3]) + (float)(v24.M[0][0] * pmat.M[0][3])));
        result.y = (float)((float)(v11
                                 * (float)((float)(pmat.M[1][0] * v24.M[1][1]) + (float)(pmat.M[0][0] * v24.M[1][0])))
                         + (float)(v10
                                 * (float)((float)(pmat.M[1][1] * v24.M[1][1]) + (float)(v24.M[1][0] * pmat.M[0][1]))))
                 + (float)(v24.M[1][3]
                         + (float)((float)(v24.M[1][1] * pmat.M[1][3]) + (float)(v24.M[1][0] * pmat.M[0][3])));
        LOBYTE(v12) = 3;
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Point<float> *, __int64))v9->vfptr[63].__vecDelDtor)(
                v9,
                &result,
                v12) )
          return 0;
      }
    }
  }
  result = (Scaleform::Render::Point<float>)&v24;
  *(_QWORD *)&v24.M[0][0] = 0i64;
  Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(
    v5,
    (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v24,
    v3,
    1);
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  v13 = v3->y;
  v25.x = v3->x;
  v25.y = v13;
  v14 = v4->Data.Size;
  v15 = v7 - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      v17 = v5->mDisplayList.DisplayObjectArray.Data.Data[v16].pCharacter;
      if ( v17->Flags & 0x100
        && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v17->vfptr[59].__vecDelDtor)(v17) )
      {
        v20 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v17->vfptr[2].__vecDelDtor)(v17);
        *(_OWORD *)&pmat.M[0][0] = *v20;
        *(_OWORD *)&pmat.M[1][0] = v20[1];
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &result, v3);
        v25 = result;
        v21 = (signed __int64)v17 + 4 * (unsigned __int8)v17->AvmObjOffset;
        (*(void (__fastcall **)(signed __int64, Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *, Scaleform::Render::Point<float> *))(*(_QWORD *)v21 + 160i64))(
          v21,
          v4,
          &v25);
      }
      --v16;
      --v15;
    }
    while ( v15 >= 0 );
  }
  v22 = v4->Data.Size > v14;
  result = (Scaleform::Render::Point<float>)&v24;
  if ( *(_QWORD *)&v24.M[0][0] )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  return v22;
}

