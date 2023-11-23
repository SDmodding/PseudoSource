// File Line: 24
// RVA: 0x7898D0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::~AvmDisplayObjContainer(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this)
{
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmDisplayObjContainer::`vftable;
  this->Scaleform::GFx::AvmDisplayObjContainerBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(this);
}

// File Line: 28
// RVA: 0x803F50
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::OnEventUnload(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rdx
  BOOL i; // eax
  __int64 v4; // rax
  Scaleform::GFx::DisplayList *p_pRenNode; // rdi
  unsigned __int64 v6; // rsi
  __int64 v7; // rbx
  __int16 v8; // cx
  Scaleform::GFx::InteractiveObject *v9; // rdi
  bool v10; // zf
  __int64 v11; // rcx
  __int64 v12; // rcx
  char *v13; // rcx
  __int64 v14; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v15; // rcx
  __int64 v16; // rdi
  __int64 v17; // rax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v18; // rcx
  unsigned int RefCount; // eax

  pDispObj = this->pDispObj;
  for ( i = LODWORD(pDispObj[1].pGeomData) != 0; LODWORD(pDispObj[1].pGeomData); i = LODWORD(pDispObj[1].pGeomData) != 0 )
  {
    v4 = (unsigned int)(i - 1);
    if ( (unsigned int)v4 < LODWORD(pDispObj[1].pGeomData) )
    {
      p_pRenNode = (Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode;
      v6 = (unsigned int)v4;
      v7 = *((_QWORD *)&pDispObj[1].pRenNode.pObject->pPrev + 2 * v4);
      if ( v7 )
        ++*(_DWORD *)(v7 + 8);
      if ( (*(_BYTE *)(v7 + 107) & 1) != 0 )
        Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)v7, 0i64, 1);
      if ( *(__int16 *)(v7 + 106) < 0 )
        Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(
          this->pDispObj->pASRoot->pMovieImpl,
          (Scaleform::GFx::DisplayObjectBase *)v7);
      Scaleform::GFx::DisplayList::RemoveEntryAtIndex(p_pRenNode, this->pDispObj, v6);
      p_pRenNode->Flags |= 3u;
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
      (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v12 + 104i64))(v12, 0i64);
      *(_QWORD *)(v7 + 56) = 0i64;
      if ( v9 && Scaleform::GFx::InteractiveObject::IsInPlayList(v9) )
      {
        v13 = (char *)v9 + 4 * (unsigned __int8)v9->AvmObjOffset;
        v14 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v13 + 8i64))(v13);
        v15 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v14 - 56);
        if ( !v14 )
          v15 = 0i64;
        Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v15);
      }
      if ( (*(_BYTE *)(v7 + 136) & 1) != 0 )
      {
        *(_WORD *)(v7 + 136) &= ~1u;
        (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v7 + 424i64))(v7, 0i64);
        *(_DWORD *)(v7 + 48) = 0;
        *(_DWORD *)(v7 + 44) = -1;
        v16 = v7 + 4i64 * *(unsigned __int8 *)(v7 + 109);
        v17 = *(_QWORD *)(v16 + 16);
        if ( !v17 )
          v17 = *(_QWORD *)(v16 + 8);
        if ( (v17 & 1) != 0 )
          --v17;
        *(_QWORD *)(v16 + 16) = v17;
        v18 = *(Scaleform::GFx::AS3::RefCountBaseGC<328> **)(v16 + 8);
        if ( v18 )
        {
          if ( ((unsigned __int8)v18 & 1) != 0 )
          {
            *(_QWORD *)(v16 + 8) = (char *)v18 - 1;
          }
          else
          {
            RefCount = v18->RefCount;
            if ( (RefCount & 0x3FFFFF) != 0 )
            {
              v18->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
            }
          }
          *(_QWORD *)(v16 + 8) = 0i64;
        }
      }
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v7);
    }
    pDispObj = this->pDispObj;
  }
  Scaleform::GFx::AS3::AvmDisplayObj::OnEventUnload(this);
}

// File Line: 40
// RVA: 0x7F0580
__int64 __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetTopMostEntity(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::Render::Point<float> *localPt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr,
        Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *hitTest)
{
  Scaleform::GFx::InteractiveObject *pClassName; // rdi
  Scaleform::Render::Point<float> *v6; // r14
  __int64 v7; // r13
  __int64 v8; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v9; // r8
  Scaleform::GFx::InteractiveObject *pIgnoreMC; // r9
  float y; // xmm6_4
  float x; // xmm7_4
  unsigned int ControllerIdx; // r10d
  bool TestAll; // r11
  char v15; // dl
  Scaleform::GFx::DisplayObject *pHitArea; // r12
  __int64 v17; // rsi
  Scaleform::GFx::DisplayObject *v18; // r15
  int v19; // ebp
  __int64 v20; // r14
  __int64 v21; // rcx
  int v22; // eax
  int v23; // edx
  Scaleform::GFx::InteractiveObject *v24; // r8
  Scaleform::GFx::InteractiveObject *pResult; // rax
  __int64 result; // rax
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

  pClassName = (Scaleform::GFx::InteractiveObject *)this[-1].pClassName;
  v6 = localPt;
  v7 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pClassName->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[121].__vecDelDtor)(pClassName);
  v8 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pClassName->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[120].__vecDelDtor)(pClassName);
  v9 = this;
  pIgnoreMC = 0i64;
  y = v36;
  x = v35;
  ControllerIdx = 0;
  TestAll = 0;
  v15 = 0;
  pHitArea = 0i64;
  v17 = *((_QWORD *)this[-1].pClassName + 28) - 1i64;
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
      if ( (!hitTest->Data.Size || hitTest->Data.Data[v17] && !*(_WORD *)(v21 + 104))
        && (*(_BYTE *)(v21 + 106) & 2) == 0 )
      {
        break;
      }
LABEL_21:
      TestAll = v29;
      ControllerIdx = v31;
      pIgnoreMC = v33;
      v24 = v32;
LABEL_22:
      v15 = v30;
LABEL_23:
      v20 -= 16i64;
      if ( --v17 < 0 )
      {
        v6 = localPt;
        goto LABEL_38;
      }
      v9 = this;
    }
    v22 = (*(__int64 (__fastcall **)(__int64, Scaleform::Render::Point<float> *, Scaleform::GFx::DisplayObjectBase::TopMostDescr *))(*(_QWORD *)v21 + 512i64))(
            v21,
            localPt,
            pdescr);
    v23 = v22;
    if ( v22 == 1 )
    {
      if ( (pClassName->Flags & 0x2000) != 0 )
        pdescr->pResult = pClassName;
      if ( pdescr->pResult )
      {
        v24 = v32;
        pIgnoreMC = v33;
        ControllerIdx = v31;
        TestAll = v29;
        if ( (pdescr->pResult->Flags & 0x1000) != 0 )
        {
          v15 = 1;
          pdescr->pResult = pClassName;
          v30 = 1;
          goto LABEL_23;
        }
LABEL_18:
        if ( v7 )
        {
          pdescr->pHitArea = pClassName;
        }
        else if ( v18 )
        {
          pResult = pdescr->pResult;
          if ( !pdescr->pResult
            || pResult == pClassName
            || SLOBYTE(pResult->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >= 0 )
          {
            if ( v18 == pdescr->pHitArea )
              goto LABEL_31;
            pdescr->pResult = 0i64;
            v19 = 2;
            goto LABEL_22;
          }
        }
        goto LABEL_20;
      }
    }
    else
    {
      if ( v22 == 3 && pdescr->pResult )
      {
        pIgnoreMC = pdescr->pIgnoreMC;
        ControllerIdx = pdescr->ControllerIdx;
        TestAll = pdescr->TestAll;
        x = pdescr->LocalPt.x;
        y = pdescr->LocalPt.y;
        pHitArea = pdescr->pHitArea;
        v33 = pIgnoreMC;
        v31 = ControllerIdx;
        v29 = TestAll;
        v19 = 1;
        v24 = pdescr->pResult;
        v32 = pdescr->pResult;
        goto LABEL_18;
      }
      if ( v19 != 1 )
      {
LABEL_20:
        if ( v23 == 1 )
        {
          if ( v7 && pdescr->pResult == pClassName )
            pdescr->pHitArea = pClassName;
          return 1i64;
        }
        goto LABEL_21;
      }
    }
    TestAll = v29;
    ControllerIdx = v31;
    pIgnoreMC = v33;
    v24 = v32;
    goto LABEL_18;
  }
  v24 = v34;
LABEL_38:
  if ( v18 )
  {
    v27 = pdescr->pResult;
    if ( !pdescr->pResult
      || v27 == pClassName
      || SLOBYTE(v27->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) >= 0 )
    {
      if ( v18 == pdescr->pHitArea )
      {
LABEL_31:
        pdescr->pResult = pClassName;
        return 1i64;
      }
      result = 2i64;
      goto LABEL_54;
    }
  }
  if ( v19 == 1 )
  {
    pdescr->pResult = v24;
    pdescr->LocalPt.x = x;
    pdescr->LocalPt.y = y;
    pdescr->pIgnoreMC = pIgnoreMC;
    pdescr->pHitArea = pHitArea;
    pdescr->ControllerIdx = ControllerIdx;
    pdescr->TestAll = TestAll;
    if ( v7 )
    {
      if ( v24 == pClassName )
        pHitArea = pClassName;
      pdescr->pHitArea = pHitArea;
    }
    return 1i64;
  }
  v28 = v6->y;
  pdescr->LocalPt.x = v6->x;
  pdescr->LocalPt.y = v28;
  if ( !v15 )
  {
    result = 3i64;
LABEL_54:
    pdescr->pResult = 0i64;
    return result;
  }
  pdescr->pResult = pClassName;
  if ( !v7 )
    return 1i64;
  pdescr->pHitArea = pClassName;
  return 1i64;
}

// File Line: 180
// RVA: 0x7D16F0
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::FillTabableArray(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::InteractiveObject::FillTabableParams *params)
{
  const char *pClassName; // rax
  __int64 v5; // rbp
  __int64 v6; // r14
  Scaleform::GFx::DisplayObjContainer *v7; // rbx
  Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327,Scaleform::ArrayDefaultPolicy> *Array; // rdi
  _QWORD *p_pObject; // rdx

  pClassName = this[-1].pClassName;
  v5 = *((_QWORD *)pClassName + 28);
  if ( v5 && (*((_DWORD *)pClassName + 46) & 0x8000) == 0 )
  {
    v6 = 0i64;
    do
    {
      v7 = *(Scaleform::GFx::DisplayObjContainer **)(v6 + *((_QWORD *)this[-1].pClassName + 27));
      if ( v7
        && SLOBYTE(v7->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) < 0
        && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v7->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(v7) )
      {
        if ( v7->TabIndex > 0 && !params->TabIndexed )
        {
          Scaleform::ArrayDataDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::Resize(
            &params->Array->Data,
            0i64);
          params->TabIndexed = 1;
        }
        if ( (((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))v7->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[87].__vecDelDtor)(v7)
           || params->InclFocusEnabled
           && v7->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[89].__vecDelDtor(
                v7,
                2u))
          && (!params->TabIndexed || v7->TabIndex > 0) )
        {
          ++v7->RefCount;
          Array = params->Array;
          Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorDH<Scaleform::Ptr<Scaleform::GFx::InteractiveObject>,327>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            &params->Array->Data,
            (__int64 *)params->Array->Data.pHeap,
            params->Array->Data.Size + 1);
          p_pObject = &Array->Data.Data[Array->Data.Size - 1].pObject;
          if ( p_pObject )
          {
            ++v7->RefCount;
            *p_pObject = v7;
          }
          Scaleform::RefCountNTSImpl::Release(v7);
        }
        if ( (v7->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x200) != 0 )
          Scaleform::GFx::DisplayObjContainer::FillTabableArray(v7, params);
      }
      v6 += 16i64;
      --v5;
    }
    while ( v5 );
  }
}

// File Line: 220
// RVA: 0x7C4990
bool __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::DetachChild(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  return Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(this, ch) != 0i64;
}

// File Line: 227
// RVA: 0x8114C0
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::DisplayObject *ch)
{
  Scaleform::GFx::DisplayObject *v4; // rdi
  Scaleform::GFx::DisplayObject *v5; // rcx
  char *v6; // rcx
  Scaleform::GFx::DisplayObject *pDispObj; // rbp
  signed __int64 DisplayIndex; // rax
  Scaleform::GFx::InteractiveObject *v9; // rsi
  char *v10; // rcx
  __int64 v11; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v12; // rcx

  if ( ch )
    ++ch->RefCount;
  v4 = 0i64;
  v5 = 0i64;
  if ( (ch->Scaleform::GFx::DisplayObjectBase::Flags & 0x100) != 0 )
    v5 = ch;
  if ( v5 )
    v6 = (char *)v5 + 4 * (unsigned __int8)v5->AvmObjOffset;
  else
    v6 = 0i64;
  (*(void (__fastcall **)(char *, _QWORD))(*(_QWORD *)v6 + 104i64))(v6, 0i64);
  if ( (ch->Scaleform::GFx::DisplayObjectBase::Flags & 0x100) != 0 && ch->ClipDepth )
    Scaleform::GFx::DisplayObject::SetMask(ch, 0i64, 1);
  if ( (ch->Scaleform::GFx::DisplayObjectBase::Flags & 0x8000u) != 0 )
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(this->pDispObj->pASRoot->pMovieImpl, ch);
  pDispObj = this->pDispObj;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex((Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode, ch);
  if ( DisplayIndex >= 0 )
  {
    Scaleform::GFx::DisplayList::RemoveEntryAtIndex(
      (Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode,
      this->pDispObj,
      DisplayIndex);
    BYTE2(pDispObj[1].pNameHandle.pObject) |= 3u;
    v9 = 0i64;
    if ( SLOBYTE(ch->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
      v9 = (Scaleform::GFx::InteractiveObject *)ch;
    ch->pParent = 0i64;
    if ( v9 && Scaleform::GFx::InteractiveObject::IsInPlayList(v9) )
    {
      v10 = (char *)v9 + 4 * (unsigned __int8)v9->AvmObjOffset;
      v11 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 8i64))(v10);
      v12 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v11 - 56);
      if ( !v11 )
        v12 = 0i64;
      Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v12);
    }
    if ( (ch->Flags & 1) != 0 )
    {
      ch->Flags &= ~1u;
      ch->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
        ch,
        0);
      ch->CreateFrame = 0;
      ch->Depth = -1;
      Scaleform::GFx::AS3::AvmDisplayObj::OnDetachFromTimeline((Scaleform::GFx::AS3::AvmDisplayObj *)((char *)ch + 4 * (unsigned __int8)ch->AvmObjOffset));
    }
    v4 = ch;
  }
  Scaleform::RefCountNTSImpl::Release(ch);
  return v4;
}

// File Line: 277
// RVA: 0x811710
Scaleform::GFx::DisplayObjectBase *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChildAt(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        unsigned int index)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rax
  Scaleform::GFx::DisplayList *p_pRenNode; // rsi
  unsigned __int64 v6; // rbp
  __int64 v7; // rbx
  __int16 v8; // cx
  Scaleform::GFx::InteractiveObject *v9; // rdi
  bool v10; // zf
  __int64 v11; // rcx
  __int64 v12; // rcx
  char *v13; // rcx
  __int64 v14; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v15; // rcx

  pDispObj = this->pDispObj;
  if ( index >= LODWORD(pDispObj[1].pGeomData) )
    return 0i64;
  p_pRenNode = (Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode;
  v6 = index;
  v7 = *((_QWORD *)&pDispObj[1].pRenNode.pObject->pPrev + 2 * index);
  if ( v7 )
    ++*(_DWORD *)(v7 + 8);
  if ( (*(_BYTE *)(v7 + 107) & 1) != 0 )
    Scaleform::GFx::DisplayObject::SetMask((Scaleform::GFx::DisplayObject *)v7, 0i64, 1);
  if ( *(__int16 *)(v7 + 106) < 0 )
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(
      this->pDispObj->pASRoot->pMovieImpl,
      (Scaleform::GFx::DisplayObjectBase *)v7);
  Scaleform::GFx::DisplayList::RemoveEntryAtIndex(p_pRenNode, this->pDispObj, v6);
  p_pRenNode->Flags |= 3u;
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
  (*(void (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v12 + 104i64))(v12, 0i64);
  *(_QWORD *)(v7 + 56) = 0i64;
  if ( v9 && Scaleform::GFx::InteractiveObject::IsInPlayList(v9) )
  {
    v13 = (char *)v9 + 4 * (unsigned __int8)v9->AvmObjOffset;
    v14 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v13 + 8i64))(v13);
    v15 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v14 - 56);
    if ( !v14 )
      v15 = 0i64;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v15);
  }
  if ( (*(_BYTE *)(v7 + 136) & 1) != 0 )
  {
    *(_WORD *)(v7 + 136) &= ~1u;
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
char __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::DisplayObjectBase *ch,
        unsigned int index)
{
  unsigned __int64 v3; // rbp
  Scaleform::GFx::DisplayObject *pDispObj; // rdi
  Scaleform::GFx::DisplayList *p_pRenNode; // rdi
  signed __int64 DisplayIndex; // rax

  v3 = index;
  pDispObj = this->pDispObj;
  if ( index >= LODWORD(pDispObj[1].pGeomData) )
    return 0;
  p_pRenNode = (Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(p_pRenNode, ch);
  if ( DisplayIndex < 0 )
    return 0;
  if ( ch )
    ++ch->RefCount;
  Scaleform::GFx::DisplayList::RemoveEntryAtIndex(p_pRenNode, this->pDispObj, DisplayIndex);
  Scaleform::GFx::DisplayList::AddEntryAtIndex(p_pRenNode, this->pDispObj, v3, ch);
  ch->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
    ch,
    0);
  ch->CreateFrame = 0;
  ch->Depth = -1;
  p_pRenNode->Flags |= 3u;
  Scaleform::RefCountNTSImpl::Release(ch);
  return 1;
}

// File Line: 340
// RVA: 0x825160
bool __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildren(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::DisplayObjectBase *ch1,
        Scaleform::GFx::DisplayObjectBase *ch2)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rdi
  unsigned int DisplayIndex; // ebx
  unsigned int v7; // eax

  pDispObj = this->pDispObj;
  DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(
                   (Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode,
                   ch1);
  v7 = Scaleform::GFx::DisplayList::FindDisplayIndex((Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode, ch2);
  return Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildrenAt(this, DisplayIndex, v7);
}

// File Line: 348
// RVA: 0x8251C0
char __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::SwapChildrenAt(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        unsigned int i1,
        unsigned int i2)
{
  Scaleform::GFx::DisplayObject *pDispObj; // r10
  __int64 v4; // rdi
  Scaleform::Ptr<Scaleform::Render::TreeNode> *p_pRenNode; // r14
  unsigned __int64 pGeomData; // rax
  __int64 v8; // rbx
  __int64 v9; // rdi
  __int64 v10; // rbx
  Scaleform::GFx::AS3::AvmInteractiveObj *v11; // rsi
  __int64 v12; // rcx
  __int64 v13; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // rax

  pDispObj = this->pDispObj;
  v4 = i1;
  p_pRenNode = &pDispObj[1].pRenNode;
  pGeomData = (unsigned __int64)pDispObj[1].pGeomData;
  if ( i1 >= pGeomData )
    return 0;
  v8 = i2;
  if ( i2 >= pGeomData
    || !Scaleform::GFx::DisplayList::SwapEntriesAtIndexes(
          (Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode,
          pDispObj,
          i1,
          i2) )
  {
    return 0;
  }
  v9 = *((_QWORD *)&p_pRenNode->pObject->pPrev + 2 * v4);
  v10 = *((_QWORD *)&p_pRenNode->pObject->pPrev + 2 * v8);
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
  BYTE2(p_pRenNode[5].pObject) |= 3u;
  if ( *(char *)(v9 + 106) < 0 )
  {
    v12 = v9 + 4i64 * *(unsigned __int8 *)(v9 + 109);
    v13 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v12 + 8i64))(v12);
    v14 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v13 - 56);
    if ( !v13 )
      v14 = 0i64;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v14);
  }
  if ( *(char *)(v10 + 106) < 0 )
  {
    v15 = v10 + 4i64 * *(unsigned __int8 *)(v10 + 109);
    v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v15 + 8i64))(v15);
    if ( v16 )
      v11 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v16 - 56);
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v11);
  }
  return 1;
}

// File Line: 383
// RVA: 0x7AB530
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChild(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::DisplayObjContainer *ch)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rax
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::GFx::DisplayList *p_pRenNode; // rbp
  char *v6; // rsi
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // r14
  char *v9; // rcx
  __int64 v10; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v11; // rcx
  unsigned __int16 Flags; // cx
  unsigned __int16 v13; // cx
  Scaleform::GFx::InteractiveObject *v14; // rax
  char *v15; // rcx
  __int64 v16; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v17; // rcx
  Scaleform::GFx::DisplayObjContainer *v18; // rdi
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // rax
  long double y1; // xmm1_8
  long double x2; // xmm0_8
  long double y2; // xmm1_8
  Scaleform::Render::Rect<double> r; // [rsp+20h] [rbp-28h] BYREF

  pDispObj = this->pDispObj;
  pParent = ch->pParent;
  p_pRenNode = (Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode;
  v6 = 0i64;
  pGeomData = pDispObj[1].pGeomData;
  if ( pParent )
  {
    if ( pParent == pDispObj )
    {
      Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(this, ch, (_DWORD)pGeomData - 1);
      return;
    }
    v9 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset;
    v10 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v9 + 40i64))(v9);
    v11 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v10 - 72);
    if ( !v10 )
      v11 = 0i64;
    Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(v11, ch);
  }
  Scaleform::GFx::DisplayList::AddEntryAtIndex(p_pRenNode, this->pDispObj, (unsigned int)pGeomData, ch);
  p_pRenNode->Flags |= 3u;
  Flags = ch->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
  if ( (Flags & 0x10) != 0 )
  {
    v13 = Flags & 0xEFEF;
    ch->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags = v13;
    if ( (v13 & 0x200) != 0 )
      Scaleform::GFx::AS3::MovieRoot::AddScriptableMovieClip(
        (Scaleform::GFx::AS3::MovieRoot *)this->pDispObj->pASRoot,
        ch);
  }
  v14 = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  ch->Depth = -1;
  ch->pParent = v14;
  if ( SLOBYTE(ch->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) < 0
    && Scaleform::GFx::InteractiveObject::IsInPlayList(ch) )
  {
    v15 = (char *)ch + 4 * (unsigned __int8)ch->AvmObjOffset;
    v16 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v15 + 8i64))(v15);
    v17 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v16 - 56);
    if ( !v16 )
      v17 = 0i64;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v17);
  }
  v18 = 0i64;
  if ( (ch->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x100) != 0 )
    v18 = ch;
  if ( v18 )
    v6 = (char *)v18 + 4 * (unsigned __int8)v18->AvmObjOffset;
  (*(void (__fastcall **)(char *, _QWORD))(*(_QWORD *)v6 + 152i64))(v6, 0i64);
  pScrollRect = v18->pScrollRect;
  if ( pScrollRect )
  {
    y1 = pScrollRect->Rectangle.y1;
    r.x1 = pScrollRect->Rectangle.x1;
    x2 = pScrollRect->Rectangle.x2;
    r.y1 = y1;
    y2 = pScrollRect->Rectangle.y2;
    r.x2 = x2;
    r.y2 = y2;
    Scaleform::GFx::DisplayObject::SetScrollRect(v18, &r);
  }
}

// File Line: 438
// RVA: 0x7AB770
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::AddChildAt(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::DisplayObjContainer *ch,
        unsigned int index)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rdx
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  unsigned int pGeomData; // ebp
  Scaleform::GFx::DisplayList *p_pRenNode; // r14
  char *v9; // rsi
  char *v10; // rcx
  __int64 v11; // rax
  Scaleform::GFx::AS3::AvmDisplayObjContainer *v12; // rcx
  unsigned __int16 Flags; // cx
  unsigned __int16 v14; // cx
  Scaleform::GFx::InteractiveObject *v15; // rax
  char *v16; // rcx
  __int64 v17; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v18; // rcx
  Scaleform::GFx::DisplayObjContainer *v19; // rdi
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // rax
  long double y1; // xmm1_8
  long double x2; // xmm0_8
  long double y2; // xmm1_8
  Scaleform::Render::Rect<double> r; // [rsp+20h] [rbp-28h] BYREF

  pDispObj = this->pDispObj;
  pParent = ch->pParent;
  pGeomData = index;
  p_pRenNode = (Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode;
  if ( index > LODWORD(pDispObj[1].pGeomData) )
    pGeomData = (unsigned int)pDispObj[1].pGeomData;
  v9 = 0i64;
  if ( pParent )
  {
    if ( pParent == pDispObj )
    {
      Scaleform::GFx::AS3::AvmDisplayObjContainer::SetChildIndex(this, ch, pGeomData);
      return;
    }
    v10 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset;
    v11 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 40i64))(v10);
    v12 = (Scaleform::GFx::AS3::AvmDisplayObjContainer *)(v11 - 72);
    if ( !v11 )
      v12 = 0i64;
    Scaleform::GFx::AS3::AvmDisplayObjContainer::RemoveChild(v12, ch);
  }
  Scaleform::GFx::DisplayList::AddEntryAtIndex(p_pRenNode, this->pDispObj, pGeomData, ch);
  Flags = ch->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags;
  if ( (Flags & 0x10) != 0 )
  {
    v14 = Flags & 0xEFEF;
    ch->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags = v14;
    if ( (v14 & 0x200) != 0 )
      Scaleform::GFx::AS3::MovieRoot::AddScriptableMovieClip(
        (Scaleform::GFx::AS3::MovieRoot *)this->pDispObj->pASRoot,
        ch);
  }
  v15 = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  ch->Depth = -1;
  ch->pParent = v15;
  if ( SLOBYTE(ch->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags) < 0
    && Scaleform::GFx::InteractiveObject::IsInPlayList(ch) )
  {
    v16 = (char *)ch + 4 * (unsigned __int8)ch->AvmObjOffset;
    v17 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v16 + 8i64))(v16);
    v18 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v17 - 56);
    if ( !v17 )
      v18 = 0i64;
    Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v18);
  }
  v19 = 0i64;
  if ( (ch->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x100) != 0 )
    v19 = ch;
  if ( v19 )
    v9 = (char *)v19 + 4 * (unsigned __int8)v19->AvmObjOffset;
  (*(void (__fastcall **)(char *, _QWORD))(*(_QWORD *)v9 + 152i64))(v9, 0i64);
  pScrollRect = v19->pScrollRect;
  if ( pScrollRect )
  {
    y1 = pScrollRect->Rectangle.y1;
    r.x1 = pScrollRect->Rectangle.x1;
    x2 = pScrollRect->Rectangle.x2;
    r.y1 = y1;
    y2 = pScrollRect->Rectangle.y2;
    r.x2 = x2;
    r.y2 = y2;
    Scaleform::GFx::DisplayObject::SetScrollRect(v19, &r);
  }
}

// File Line: 492
// RVA: 0x7E4750
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildAt(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        unsigned int index)
{
  Scaleform::GFx::DisplayObjectBase *ChildAt; // rax
  __int64 v5; // rdx
  _QWORD *v6; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v7; // rax

  ChildAt = Scaleform::GFx::DisplayObjContainer::GetChildAt(
              (Scaleform::GFx::DisplayObjContainer *)this->pDispObj,
              index);
  if ( ChildAt )
  {
    v6 = (Scaleform::RefCountNTSImplCoreVtbl **)((char *)&ChildAt->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                               + 4 * (unsigned __int8)ChildAt->AvmObjOffset);
    LOBYTE(v5) = 1;
    (*(void (__fastcall **)(_QWORD *, __int64))(*v6 + 112i64))(v6, v5);
    v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v6[2];
    if ( !v7 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v6[1];
    if ( ((unsigned __int8)v7 & 1) != 0 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
    result->pObject = v7;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
  }
  else
  {
    result->pObject = 0i64;
  }
  return result;
}

// File Line: 504
// RVA: 0x7E47E0
Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetAS3ChildByName(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *result,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::DisplayObject *DisplayObjectByName; // rax
  __int64 v5; // rdx
  _QWORD *v6; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v7; // rax

  DisplayObjectByName = Scaleform::GFx::DisplayList::GetDisplayObjectByName(
                          (Scaleform::GFx::DisplayList *)&this->pDispObj[1].pRenNode,
                          name,
                          1);
  if ( DisplayObjectByName )
  {
    v6 = (Scaleform::RefCountNTSImplCoreVtbl **)((char *)&DisplayObjectByName->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                               + 4 * (unsigned __int8)DisplayObjectByName->AvmObjOffset);
    LOBYTE(v5) = 1;
    (*(void (__fastcall **)(_QWORD *, __int64))(*v6 + 112i64))(v6, v5);
    v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v6[2];
    if ( !v7 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)v6[1];
    if ( ((unsigned __int8)v7 & 1) != 0 )
      v7 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v7 - 1);
    result->pObject = v7;
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FBFFFFF;
  }
  else
  {
    result->pObject = 0i64;
  }
  return result;
}

// File Line: 518
// RVA: 0x7D2910
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::FindInsertToPlayList(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rbp
  unsigned int pGeomData; // r15d
  __int64 v5; // r12
  Scaleform::GFx::InteractiveObject *v7; // rdi
  unsigned int v8; // ebx
  __int64 v9; // r14
  __int64 v10; // rsi
  unsigned int v11; // ebx
  __int64 v12; // rsi
  __int64 v13; // r14
  Scaleform::GFx::DisplayObject *v14; // rcx
  Scaleform::GFx::InteractiveObject *pParent; // rax

  pDispObj = this->pDispObj;
  if ( (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0
    || (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) != 0
    || pDispObj->Depth < -1 )
  {
    return 0i64;
  }
  pGeomData = (unsigned int)pDispObj[1].pGeomData;
  v5 = 0i64;
  if ( !pGeomData )
    return *(Scaleform::GFx::InteractiveObject **)&pDispObj[1].RefCount;
  v7 = 0i64;
  v8 = 0;
  v9 = 0i64;
  do
  {
    v10 = *(__int64 *)((char *)&pDispObj[1].pRenNode.pObject->pPrev + v9);
    if ( (Scaleform::GFx::InteractiveObject *)v10 == ch )
      break;
    if ( *(char *)(v10 + 106) < 0
      && Scaleform::GFx::InteractiveObject::IsInPlayList((Scaleform::GFx::InteractiveObject *)v10) )
    {
      v7 = (Scaleform::GFx::InteractiveObject *)v10;
    }
    ++v8;
    v9 += 16i64;
  }
  while ( v8 < pGeomData );
  if ( !v7 )
    return *(Scaleform::GFx::InteractiveObject **)&pDispObj[1].RefCount;
  v11 = v8 + 1;
  if ( v11 >= pGeomData )
  {
LABEL_18:
    v14 = this->pDispObj;
    do
    {
      pParent = v7;
      while ( pParent != v14 )
      {
        if ( pParent != v14->pParent )
        {
          pParent = pParent->pParent;
          if ( pParent )
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
      v13 = *(__int64 *)((char *)&pDispObj[1].pRenNode.pObject->pPrev + v12);
      if ( *(char *)(v13 + 106) < 0
        && Scaleform::GFx::InteractiveObject::IsInPlayList(*(Scaleform::GFx::InteractiveObject **)((char *)&pDispObj[1].pRenNode.pObject->pPrev
                                                                                                 + v12)) )
      {
        return (Scaleform::GFx::InteractiveObject *)v13;
      }
      ++v11;
      v12 += 16i64;
      if ( v11 >= pGeomData )
        goto LABEL_18;
    }
  }
  return (Scaleform::GFx::InteractiveObject *)v5;
}

// File Line: 617
// RVA: 0x80A530
void __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::PropagateEvent(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::GFx::AS3::Instances::fl_events::Event *evtProto,
        bool inclChildren)
{
  __int64 v6; // r8
  Scaleform::GFx::DisplayObject *pDispObj; // rbp
  unsigned int v8; // esi
  Scaleform::GFx::DisplayObjectBase *v9; // rbx
  __int64 v10; // rdx
  __int64 v11; // rcx
  int pObject_low; // edi
  __int64 DisplayIndex; // rax

  Scaleform::GFx::AS3::AvmDisplayObj::PropagateEvent(this, evtProto, 1);
  if ( inclChildren )
  {
    pDispObj = this->pDispObj;
    v8 = 0;
    if ( LODWORD(pDispObj[1].pGeomData) )
    {
      while ( 1 )
      {
        v9 = (Scaleform::GFx::DisplayObjectBase *)*((_QWORD *)&pDispObj[1].pRenNode.pObject->pPrev + 2 * v8);
        if ( v9 )
          ++v9->RefCount;
        v10 = 0i64;
        if ( (*(_BYTE *)(*((_QWORD *)&pDispObj[1].pRenNode.pObject->pPrev + 2 * v8) + 107i64) & 1) != 0 )
          v10 = *((_QWORD *)&pDispObj[1].pRenNode.pObject->pPrev + 2 * v8);
        v11 = v10 ? v10 + 4i64 * *(unsigned __int8 *)(v10 + 109) : 0i64;
        pObject_low = LOWORD(pDispObj[1].pNameHandle.pObject);
        LOBYTE(v6) = 1;
        (*(void (__fastcall **)(__int64, Scaleform::GFx::AS3::Instances::fl_events::Event *, __int64))(*(_QWORD *)v11 + 144i64))(
          v11,
          evtProto,
          v6);
        if ( LOWORD(pDispObj[1].pNameHandle.pObject) != pObject_low )
        {
          DisplayIndex = Scaleform::GFx::DisplayList::FindDisplayIndex(
                           (Scaleform::GFx::DisplayList *)&pDispObj[1].pRenNode,
                           v9);
          v8 = DisplayIndex;
          if ( DisplayIndex < 0 )
            break;
        }
        if ( v9 )
          Scaleform::RefCountNTSImpl::Release(v9);
        if ( ++v8 >= LODWORD(pDispObj[1].pGeomData) )
          return;
      }
      if ( v9 )
        Scaleform::RefCountNTSImpl::Release(v9);
    }
  }
}

// File Line: 661
// RVA: 0x7ED300
bool __fastcall Scaleform::GFx::AS3::AvmDisplayObjContainer::GetObjectsUnderPoint(
        Scaleform::GFx::AS3::AvmDisplayObjContainer *this,
        Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *destArray,
        Scaleform::Render::Point<float> *pt)
{
  Scaleform::GFx::DisplayObjContainer *pDispObj; // r14
  unsigned __int64 Size; // rdi
  Scaleform::GFx::DisplayObject *Mask; // rax
  Scaleform::GFx::DisplayObject *v9; // rbx
  float y; // xmm2_4
  float x; // xmm3_4
  __int64 v12; // r8
  float v13; // xmm2_4
  unsigned __int64 v14; // r12
  __int64 v15; // rdi
  __int64 v16; // rsi
  Scaleform::GFx::DisplayObjectBase *pCharacter; // rbx
  _BYTE *v18; // rcx
  bool v19; // bl
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+10h] [rbp-69h] BYREF
  Scaleform::Render::Matrix2x4<float> v21; // [rsp+30h] [rbp-49h] BYREF
  Scaleform::Render::Point<float> v22; // [rsp+E0h] [rbp+67h] BYREF
  Scaleform::Render::Point<float> result; // [rsp+F8h] [rbp+7Fh] BYREF

  *(_QWORD *)&pmat.M[1][2] = -2i64;
  pDispObj = (Scaleform::GFx::DisplayObjContainer *)this->pDispObj;
  if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjContainer *))pDispObj->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pDispObj) )
    return 0;
  Size = pDispObj->mDisplayList.DisplayObjectArray.Data.Size;
  Mask = Scaleform::GFx::DisplayObject::GetMask(pDispObj);
  v9 = Mask;
  if ( Mask )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))Mask->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(Mask) )
    {
      if ( (v9->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
      {
        *(_OWORD *)&v21.M[0][0] = _xmm;
        *(__m128 *)&v21.M[1][0] = _xmm;
        *(_QWORD *)&pmat.M[1][2] = _xmm.m128_u64[1];
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v9, &pmat);
        Scaleform::Render::Matrix2x4<float>::SetInverse(&v21, &pmat);
        *(_QWORD *)&pmat.M[1][2] = _xmm.m128_u64[1];
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pDispObj, &pmat);
        y = pt->y;
        x = pt->x;
        result.x = (float)((float)(pt->x
                                 * (float)((float)(pmat.M[1][0] * v21.M[0][1]) + (float)(pmat.M[0][0] * v21.M[0][0])))
                         + (float)(y * (float)((float)(pmat.M[1][1] * v21.M[0][1]) + (float)(v21.M[0][0] * pmat.M[0][1]))))
                 + (float)(v21.M[0][3]
                         + (float)((float)(v21.M[0][1] * pmat.M[1][3]) + (float)(v21.M[0][0] * pmat.M[0][3])));
        result.y = (float)((float)(x * (float)((float)(pmat.M[1][0] * v21.M[1][1]) + (float)(pmat.M[0][0] * v21.M[1][0])))
                         + (float)(y * (float)((float)(pmat.M[1][1] * v21.M[1][1]) + (float)(v21.M[1][0] * pmat.M[0][1]))))
                 + (float)(v21.M[1][3]
                         + (float)((float)(v21.M[1][1] * pmat.M[1][3]) + (float)(v21.M[1][0] * pmat.M[0][3])));
        LOBYTE(v12) = 3;
        if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *, Scaleform::Render::Point<float> *, __int64))v9->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[63].__vecDelDtor)(
                v9,
                &result,
                v12) )
          return 0;
      }
    }
  }
  result = (Scaleform::Render::Point<float>)&v21;
  *(_QWORD *)&v21.M[0][0] = 0i64;
  Scaleform::GFx::DisplayObjContainer::CalcDisplayListHitTestMaskArray(
    pDispObj,
    (Scaleform::ArrayPOD<unsigned char,2,Scaleform::ArrayDefaultPolicy> *)&v21,
    pt,
    1);
  *(_OWORD *)&pmat.M[0][0] = _xmm;
  *(__m128 *)&pmat.M[1][0] = _xmm;
  v13 = pt->y;
  v22.x = pt->x;
  v22.y = v13;
  v14 = destArray->Data.Size;
  v15 = Size - 1;
  if ( v15 >= 0 )
  {
    v16 = v15;
    do
    {
      pCharacter = pDispObj->mDisplayList.DisplayObjectArray.Data.Data[v16].pCharacter;
      if ( (pCharacter->Flags & 0x100) != 0
        && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(pCharacter) )
      {
        pmat = *(Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))pCharacter->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pCharacter);
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &result, pt);
        v22 = result;
        v18 = (char *)pCharacter + 4 * (unsigned __int8)pCharacter->AvmObjOffset;
        (*(void (__fastcall **)(_BYTE *, Scaleform::ArrayDH<Scaleform::Ptr<Scaleform::GFx::DisplayObjectBase>,2,Scaleform::ArrayDefaultPolicy> *, Scaleform::Render::Point<float> *))(*(_QWORD *)v18 + 160i64))(
          v18,
          destArray,
          &v22);
      }
      --v16;
      --v15;
    }
    while ( v15 >= 0 );
  }
  v19 = destArray->Data.Size > v14;
  result = (Scaleform::Render::Point<float>)&v21;
  if ( *(_QWORD *)&v21.M[0][0] )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  return v19;
}

