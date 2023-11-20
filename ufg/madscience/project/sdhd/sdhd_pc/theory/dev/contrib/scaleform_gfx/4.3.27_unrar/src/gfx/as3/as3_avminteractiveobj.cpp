// File Line: 31
// RVA: 0x77AF00
void __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(Scaleform::GFx::AS3::AvmInteractiveObj *this, Scaleform::GFx::InteractiveObject *pdispObj)
{
  Scaleform::GFx::InteractiveObject *v2; // rbx
  Scaleform::GFx::AS3::AvmInteractiveObj *v3; // rdi
  Scaleform::GFx::AvmInteractiveObjBase *v4; // [rsp+48h] [rbp+10h]

  v2 = pdispObj;
  v3 = this;
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(
    (Scaleform::GFx::AS3::AvmDisplayObj *)&this->vfptr,
    (Scaleform::GFx::DisplayObject *)&pdispObj->vfptr);
  v4 = (Scaleform::GFx::AvmInteractiveObjBase *)&v3->vfptr;
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable';
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObj'};
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  *(_WORD *)&v3->MouseOverCnt = 0;
  v2->TabIndex = -1;
}

// File Line: 36
// RVA: 0x789940
void __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::~AvmInteractiveObj(Scaleform::GFx::AS3::AvmInteractiveObj *this)
{
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable'{for `Scaleform::GFx::AS3::AvmDisplayObj'};
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable'{for `Scaleform::GFx::AvmInteractiveObjBase'};
  this->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable';
  Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj((Scaleform::GFx::AS3::AvmDisplayObj *)&this->vfptr);
}

// File Line: 51
// RVA: 0x803440
char __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent(Scaleform::GFx::AS3::AvmInteractiveObj *this, Scaleform::GFx::EventId *id)
{
  unsigned __int64 v2; // rax
  Scaleform::GFx::EventId *v3; // rbx
  Scaleform::GFx::AS3::AvmInteractiveObj *v4; // r8
  signed __int64 v5; // rcx
  Scaleform::GFx::DisplayObject *v7; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v8; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v9; // rdi
  Scaleform::RefCountNTSImpl *v10; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS3::WeakProxy *v13; // rdx
  bool v14; // zf
  Scaleform::Render::RenderBuffer *v15; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v16; // rcx

  v2 = id->Id;
  v3 = id;
  v4 = this;
  if ( (unsigned int)v2 <= 0x2000 )
  {
    if ( (_DWORD)v2 != 0x2000 )
    {
      if ( (unsigned int)v2 > 0x20 )
        return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent((Scaleform::GFx::AS3::AvmDisplayObj *)&v4->vfptr, id);
      v5 = 4295033088i64;
      if ( !_bittest64(&v5, v2) )
        return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent((Scaleform::GFx::AS3::AvmDisplayObj *)&v4->vfptr, id);
    }
    goto LABEL_29;
  }
  if ( (_DWORD)v2 == 0x4000 )
    goto LABEL_29;
  if ( (unsigned int)v2 <= 0x1000009 )
    return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent((Scaleform::GFx::AS3::AvmDisplayObj *)&v4->vfptr, id);
  if ( (unsigned int)v2 <= 0x100000E )
  {
LABEL_29:
    v16 = v4->pAS3RawPtr;
    if ( v16 || v4->pAS3CollectiblePtr.pObject )
    {
      if ( !v16 )
        v16 = v4->pAS3CollectiblePtr.pObject;
      if ( (unsigned __int8)v16 & 1 )
        v16 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v16 - 1);
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
        (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v16->vfptr,
        id,
        v4->pDispObj);
    }
    return 1;
  }
  if ( (_DWORD)v2 != 16777236 )
    return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent((Scaleform::GFx::AS3::AvmDisplayObj *)&v4->vfptr, id);
  v7 = this->pDispObj;
  v8 = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(
         (Scaleform::GFx::AS3::MovieRoot *)v7->pASRoot,
         AL_ControllerEvents);
  v9 = v8;
  v8->Type = 1;
  if ( v7 )
    ++v7->RefCount;
  v10 = (Scaleform::RefCountNTSImpl *)&v8->pCharacter.pObject->vfptr;
  if ( v10 )
    Scaleform::RefCountNTSImpl::Release(v10);
  v9->pCharacter.pObject = v7;
  v9->mEventId.Id = v3->Id;
  v9->mEventId.WcharCode = v3->WcharCode;
  v9->mEventId.KeyCode = v3->KeyCode;
  v9->mEventId.AsciiCode = v3->AsciiCode;
  v9->mEventId.RollOverCnt = v3->RollOverCnt;
  v9->mEventId.ControllerIndex = v3->ControllerIndex;
  v9->mEventId.KeysState.States = v3->KeysState.States;
  v9->mEventId.MouseWheelDelta = v3->MouseWheelDelta;
  v9->CFunction = 0i64;
  v11 = v9->pAS3Obj.pObject;
  if ( v11 )
  {
    if ( (unsigned __int8)v11 & 1 )
    {
      v9->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v11 - 1);
    }
    else
    {
      v12 = v11->RefCount;
      if ( v12 & 0x3FFFFF )
      {
        v11->RefCount = v12 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v11->vfptr);
      }
    }
    v9->pAS3Obj.pObject = 0i64;
  }
  if ( (v9->Function.Flags & 0x1F) > 9 )
  {
    if ( (v9->Function.Flags >> 9) & 1 )
    {
      v13 = v9->Function.Bonus.pWeakProxy;
      v14 = v13->RefCount-- == 1;
      if ( v14 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v9->Function.Flags &= 0xFFFFFDE0;
      v9->Function.Bonus.pWeakProxy = 0i64;
      v9->Function.value.VNumber = 0.0;
      v9->Function.value.VS._2.VObj = 0i64;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v9->Function);
    }
  }
  v9->Function.Flags &= 0xFFFFFFE0;
  v15 = (Scaleform::Render::RenderBuffer *)v9->pNLoadInitCL.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  v9->pNLoadInitCL.pObject = 0i64;
  return 1;
}

// File Line: 95
// RVA: 0x804620
void __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::OnFocus(Scaleform::GFx::AS3::AvmInteractiveObj *this, Scaleform::GFx::InteractiveObject::FocusEventType *evt, Scaleform::GFx::InteractiveObject *oldOrNewFocusCh, unsigned int controllerIdx)
{
  unsigned int v4; // er14
  Scaleform::GFx::AS3::AvmInteractiveObj *v5; // rbp
  const char *v6; // rsi
  __int64 v7; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v8; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v9; // rbx
  Scaleform::GFx::ASStringManager *v10; // rax
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v14; // rsi
  Scaleform::GFx::DisplayObject *v15; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp-28h]
  __int64 v19; // [rsp+48h] [rbp-20h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> v20; // [rsp+70h] [rbp+8h]

  v19 = -2i64;
  v4 = controllerIdx;
  v5 = this;
  if ( *(_OWORD *)&this[-1].pDispObj != 0i64 )
  {
    v6 = "focusIn";
    if ( !(_DWORD)evt )
      v6 = "focusOut";
    if ( oldOrNewFocusCh )
    {
      v7 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&oldOrNewFocusCh->vfptr
                                                                       + 4
                                                                       * (unsigned __int8)oldOrNewFocusCh->AvmObjOffset))[1].__vecDelDtor)();
      if ( v7 )
        v7 -= 56i64;
      v8 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v7 + 16);
      if ( !v8 )
        v8 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v7 + 8);
      if ( (unsigned __int8)v8 & 1 )
        v8 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v8 - 1);
    }
    else
    {
      v8 = 0i64;
    }
    v9 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v5[-1].pClassName;
    if ( !v9 )
      v9 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)v5[-1].pDispObj;
    if ( (unsigned __int8)v9 & 1 )
      v9 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v9 - 1);
    v10 = (Scaleform::GFx::ASStringManager *)(*(__int64 (**)(void))(**(_QWORD **)(*(_QWORD *)(*(_QWORD *)&v5[-1].AppDomain->RefCount
                                                                                            + 16i64)
                                                                                + 24i64)
                                                                  + 472i64))();
    v11 = Scaleform::GFx::ASStringManager::CreateConstString(v10, &result, v6);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateFocusEventObject(v9, &v20, v11, v8, v4, 0);
    v12 = result.pNode;
    v13 = result.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v14 = v20.pObject;
    v15 = (Scaleform::GFx::DisplayObject *)v5[-1].AppDomain;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v20.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)v9);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
      v9,
      (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v14->vfptr,
      v15);
    v16 = v20.pObject;
    if ( v20.pObject )
    {
      if ( (_QWORD)v20.pObject & 1 )
      {
        --v20.pObject;
      }
      else
      {
        v17 = v20.pObject->RefCount;
        if ( v17 & 0x3FFFFF )
        {
          v20.pObject->RefCount = v17 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v16->vfptr);
        }
      }
    }
  }
}

// File Line: 116
// RVA: 0x8047A0
char __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::OnFocusChange(Scaleform::GFx::AS3::AvmInteractiveObj *this, Scaleform::GFx::InteractiveObject *toBeFocused, unsigned int controllerIdx, Scaleform::GFx::FocusMovedType fmt, Scaleform::GFx::ProcessFocusKeyInfo *pfocusKeyInfo)
{
  Scaleform::GFx::FocusMovedType v5; // er14
  unsigned int v6; // er15
  Scaleform::GFx::AS3::AvmInteractiveObj *v7; // rbp
  const char *v8; // rsi
  __int64 v10; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v11; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v12; // rbx
  Scaleform::GFx::ASStringManager *v13; // rax
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::ProcessFocusKeyInfo *v17; // rdx
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v18; // rsi
  Scaleform::GFx::DisplayObject *v19; // rdi
  char v20; // bl
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v21; // rcx
  unsigned int v22; // edx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp-28h]
  __int64 v24; // [rsp+48h] [rbp-20h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> v25; // [rsp+70h] [rbp+8h]

  v24 = -2i64;
  v5 = fmt;
  v6 = controllerIdx;
  v7 = this;
  v8 = "mouseFocusChange";
  if ( fmt == 2 )
    v8 = "keyFocusChange";
  if ( *(_OWORD *)&this->pAS3CollectiblePtr.pObject == 0i64 )
    return 1;
  if ( toBeFocused )
  {
    v10 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&toBeFocused->vfptr
                                                                      + 4 * (unsigned __int8)toBeFocused->AvmObjOffset))[1].__vecDelDtor)();
    if ( v10 )
      v10 -= 56i64;
    v11 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v10 + 16);
    if ( !v11 )
      v11 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v10 + 8);
    if ( (unsigned __int8)v11 & 1 )
      v11 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v11 - 1);
  }
  else
  {
    v11 = 0i64;
  }
  v12 = v7->pAS3RawPtr;
  if ( !v12 )
    v12 = v7->pAS3CollectiblePtr.pObject;
  if ( (unsigned __int8)v12 & 1 )
    v12 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v12 - 1);
  v13 = (Scaleform::GFx::ASStringManager *)((__int64 (*)(void))v7->pDispObj->pASRoot->pMovieImpl->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)();
  v14 = Scaleform::GFx::ASStringManager::CreateConstString(v13, &result, v8);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateFocusEventObject(
    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v12->vfptr,
    &v25,
    v14,
    v11,
    v6,
    0);
  v15 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  *((_BYTE *)&v25.pObject->0 + 84) |= 2u;
  if ( v5 == 2 )
  {
    v17 = pfocusKeyInfo;
    v25.pObject->KeyCode = pfocusKeyInfo->KeyCode;
    v25.pObject->ShiftKey = (v17->KeysState | 0x80) & 1;
  }
  v18 = v25.pObject;
  v19 = v7->pDispObj;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v25.pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)v12);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(
    (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v12->vfptr,
    (Scaleform::GFx::AS3::Instances::fl_events::Event *)&v18->vfptr,
    v19);
  v20 = ~(*((_BYTE *)&v25.pObject->0 + 84) >> 2) & 1;
  v21 = v25.pObject;
  if ( v25.pObject )
  {
    if ( (_QWORD)v25.pObject & 1 )
    {
      --v25.pObject;
    }
    else
    {
      v22 = v25.pObject->RefCount;
      if ( v22 & 0x3FFFFF )
      {
        v25.pObject->RefCount = v22 - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)&v21->vfptr);
      }
    }
  }
  return v20;
}ernal((Scaleform::GFx::AS3::RefCountBaseGC

// File Line: 144
// RVA: 0x7F0AF0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS3::AvmInteractiveObj::GetTopParent(Scaleform::GFx::AS3::AvmInteractiveObj *this, __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *v2; // r8
  Scaleform::GFx::InteractiveObject *v3; // rcx
  Scaleform::GFx::InteractiveObject *result; // rax

  v2 = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  v3 = v2->pParent;
  if ( v3 && v3->pASRoot->AVMVersion == 2 )
    result = (Scaleform::GFx::InteractiveObject *)v3->vfptr[68].__vecDelDtor(
                                                    (Scaleform::RefCountNTSImplCore *)&v3->vfptr,
                                                    ignoreLockRoot);
  else
    result = v2;
  return result;
}

// File Line: 152
// RVA: 0x7E60F0
Scaleform::GFx::AS3::AvmInteractiveObj *__fastcall Scaleform::GFx::AS3::AvmInteractiveObj::GetAvmTopParent(Scaleform::GFx::AS3::AvmInteractiveObj *this, __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *v2; // rcx
  __int64 v3; // rax
  __int64 v4; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *result; // rax

  v2 = this->pDispObj->pParent;
  if ( v2->pASRoot->AVMVersion == 2
    && (v3 = (__int64)v2->vfptr[68].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, ignoreLockRoot),
        (v4 = (*(__int64 (**)(void))(*(_QWORD *)(v3 + 4i64 * *(unsigned __int8 *)(v3 + 109)) + 8i64))()) != 0) )
  {
    result = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v4 - 56);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 161
// RVA: 0x7F93A0
bool __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::IsTabable(Scaleform::GFx::AS3::AvmInteractiveObj *this)
{
  Scaleform::GFx::AS3::AvmInteractiveObj *v1; // rbx
  bool result; // al
  Scaleform::GFx::AS3::VMAppDomain *v3; // rax

  v1 = this;
  result = ((__int64 (*)(void))this[-1].AppDomain->vfptr[19].Finalize_GC)();
  if ( result )
  {
    v3 = v1[-1].AppDomain;
    if ( (_QWORD)v3[2]._pRCC & 0x60 )
      result = ((_QWORD)v3[2]._pRCC & 0x60) == 96;
    else
      result = SWORD2(v3[2].pRCCRaw) > 0;
  }
  return result;
}

// File Line: 174
// RVA: 0x7AA360
char __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::ActsAsButton(Scaleform::GFx::AS3::AvmInteractiveObj *this)
{
  char *v1; // rax
  __int64 v2; // rcx

  v1 = (char *)this[-1].pClassName;
  if ( !v1 )
  {
    if ( !this[-1].pDispObj )
      return 1;
    v1 = (char *)this[-1].pDispObj;
  }
  if ( (unsigned __int8)v1 & 1 )
    --v1;
  v2 = *((_QWORD *)v1 + 8);
  if ( v2 && (*(_BYTE *)(v2 + 18) || *(_BYTE *)(v2 + 19)) )
    return 1;
  return 0;
}

// File Line: 183
// RVA: 0x7D2AB0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS3::AvmInteractiveObj::FindInsertToPlayList(Scaleform::GFx::AS3::AvmInteractiveObj *this, Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::DisplayObject *v2; // r8
  Scaleform::GFx::InteractiveObject *v3; // rax
  Scaleform::GFx::InteractiveObject *result; // rax

  v2 = this->pDispObj;
  if ( (LOBYTE(v2->Flags) >> 4) & 1
    || v2->Flags & 0x1000
    || v2->Depth < -1
    || (v3 = ch->pParent) == 0i64
    || (result = v3->pPlayPrev) == 0i64 )
  {
    result = 0i64;
  }
  return result;
}

// File Line: 202
// RVA: 0x8016F0
void __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(Scaleform::GFx::AS3::AvmInteractiveObj *this)
{
  Scaleform::GFx::DisplayObject *v1; // rbx
  signed __int64 v2; // rsi
  Scaleform::GFx::AS3::AvmInteractiveObj *v3; // rbp
  __int64 v4; // rdx
  Scaleform::RefCountNTSImplCoreVtbl *v5; // r8
  void *(__fastcall *i)(Scaleform::RefCountNTSImplCore *, unsigned int); // r9
  Scaleform::GFx::DisplayObject *v7; // rax
  Scaleform::GFx::DisplayObject *v8; // rdi
  Scaleform::GFx::MovieImpl *v9; // rcx
  Scaleform::GFx::InteractiveObject *v10; // rcx
  signed __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v14; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *v15; // rcx
  Scaleform::GFx::MovieImpl *v16; // rax

  v1 = this->pDispObj;
  v2 = 0i64;
  v3 = this;
  v4 = *(_QWORD *)&v1[1].RefCount;
  v5 = v1[1].vfptr;
  for ( i = 0i64; v4; v4 = *(_QWORD *)(v4 + 152) )
  {
    v7 = (Scaleform::GFx::DisplayObject *)v4;
    while ( v7 != v1 )
    {
      v7 = (Scaleform::GFx::DisplayObject *)&v7->pParent->vfptr;
      if ( !v7 )
      {
        v8 = *(Scaleform::GFx::DisplayObject **)(v4 + 144);
        i = (void *(__fastcall *)(Scaleform::RefCountNTSImplCore *, unsigned int))v4;
        *(_QWORD *)(v4 + 144) = v5;
        goto LABEL_9;
      }
    }
  }
  if ( v5 )
  {
    v9 = v1->pASRoot->pMovieImpl;
    v8 = (Scaleform::GFx::DisplayObject *)&v9->pPlayListHead->vfptr;
    v9->pPlayListHead = (Scaleform::GFx::InteractiveObject *)v5;
LABEL_9:
    if ( v5 )
      v5[19].__vecDelDtor = i;
  }
  else
  {
    v8 = this->pDispObj;
  }
  v1[1].vfptr = 0i64;
  *(_QWORD *)&v8[1].RefCount = 0i64;
  v10 = v3->pDispObj->pParent;
  if ( !v10 )
    goto LABEL_25;
  v11 = (signed __int64)v10 + 4 * (unsigned __int8)v10->AvmObjOffset;
  v12 = (*(__int64 (__fastcall **)(signed __int64, __int64, Scaleform::RefCountNTSImplCoreVtbl *, void *(__fastcall *)(Scaleform::RefCountNTSImplCore *, unsigned int)))(*(_QWORD *)v11 + 8i64))(
          v11,
          v4,
          v5,
          i);
  if ( v12 )
    v2 = v12 - 56;
  v13 = (*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::DisplayObject *))(*(_QWORD *)v2 + 200i64))(v2, v1);
  if ( v13 )
  {
    v14 = *(Scaleform::RefCountNTSImplCoreVtbl **)(v13 + 144);
    v1[1].vfptr = v14;
    if ( v14 )
      v14[19].__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountNTSImplCore *, unsigned int))v1;
    *(_QWORD *)(v13 + 144) = v8;
    *(_QWORD *)&v8[1].RefCount = v13;
  }
  else
  {
LABEL_25:
    v15 = (Scaleform::RefCountNTSImplCoreVtbl *)v3->pDispObj->pASRoot->pMovieImpl->pPlayListHead;
    if ( v15 )
    {
      v1[1].vfptr = v15;
      v15[19].__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountNTSImplCore *, unsigned int))v1;
    }
    v3->pDispObj->pASRoot->pMovieImpl->pPlayListHead = (Scaleform::GFx::InteractiveObject *)v8;
  }
  v16 = v3->pDispObj->pASRoot->pMovieImpl;
  v16->Flags |= 0x80000u;
}

// File Line: 290
// RVA: 0x7F6860
void __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::InsertChildToPlayList(Scaleform::GFx::AS3::AvmInteractiveObj *this, Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::InteractiveObject *v2; // rbx
  Scaleform::GFx::InteractiveObject *v3; // rax

  v2 = ch;
  v3 = (Scaleform::GFx::InteractiveObject *)(*((__int64 (**)(void))&this->vfptr[2].__vecDelDtor + 1))();
  if ( v3 )
    Scaleform::GFx::InteractiveObject::InsertToPlayListAfter(v2, v3);
  else
    Scaleform::GFx::InteractiveObject::AddToPlayList(v2);
}

