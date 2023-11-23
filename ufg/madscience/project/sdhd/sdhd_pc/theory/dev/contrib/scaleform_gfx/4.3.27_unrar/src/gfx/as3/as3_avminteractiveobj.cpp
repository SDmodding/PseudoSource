// File Line: 31
// RVA: 0x77AF00
void __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        Scaleform::GFx::InteractiveObject *pdispObj)
{
  Scaleform::GFx::AS3::AvmDisplayObj::AvmDisplayObj(this, pdispObj);
  this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  *(_WORD *)&this->MouseOverCnt = 0;
  pdispObj->TabIndex = -1;
}

// File Line: 36
// RVA: 0x789940
void __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::~AvmInteractiveObj(
        Scaleform::GFx::AS3::AvmInteractiveObj *this)
{
  this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmInteractiveObj::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(this);
}

// File Line: 51
// RVA: 0x803440
char __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::OnEvent(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        Scaleform::GFx::EventId *id)
{
  unsigned __int64 v2; // rax
  __int64 v5; // rcx
  Scaleform::GFx::DisplayObject *pDispObj; // rsi
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS3::MovieRoot::ActionEntry *v9; // rdi
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v11; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx
  Scaleform::Render::RenderBuffer *v15; // rcx
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rcx

  v2 = id->Id;
  if ( (unsigned int)v2 <= 0x2000 )
  {
    if ( (_DWORD)v2 != 0x2000 )
    {
      if ( (unsigned int)v2 > 0x20 )
        return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(this, id);
      v5 = 0x100010100i64;
      if ( !_bittest64(&v5, v2) )
        return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(this, id);
    }
    goto LABEL_29;
  }
  if ( (_DWORD)v2 == 0x4000 )
    goto LABEL_29;
  if ( (unsigned int)v2 <= 0x1000009 )
    return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(this, id);
  if ( (unsigned int)v2 <= 0x100000E )
  {
LABEL_29:
    pAS3RawPtr = this->pAS3RawPtr;
    if ( pAS3RawPtr || this->pAS3CollectiblePtr.pObject )
    {
      if ( !pAS3RawPtr )
        pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
      if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
        pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
      Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(pAS3RawPtr, id, this->pDispObj);
    }
    return 1;
  }
  if ( (_DWORD)v2 != 16777236 )
    return Scaleform::GFx::AS3::AvmDisplayObj::OnEvent(this, id);
  pDispObj = this->pDispObj;
  inserted = Scaleform::GFx::AS3::MovieRoot::InsertEmptyAction(
               (Scaleform::GFx::AS3::MovieRoot *)pDispObj->pASRoot,
               AL_ControllerEvents);
  v9 = inserted;
  inserted->Type = Entry_Buffer;
  if ( pDispObj )
    ++pDispObj->RefCount;
  pObject = inserted->pCharacter.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v9->pCharacter.pObject = pDispObj;
  v9->mEventId.Id = id->Id;
  v9->mEventId.WcharCode = id->WcharCode;
  v9->mEventId.KeyCode = id->KeyCode;
  v9->mEventId.AsciiCode = id->AsciiCode;
  v9->mEventId.RollOverCnt = id->RollOverCnt;
  v9->mEventId.ControllerIndex = id->ControllerIndex;
  v9->mEventId.KeysState.States = id->KeysState.States;
  v9->mEventId.MouseWheelDelta = id->MouseWheelDelta;
  v9->CFunction = 0i64;
  v11 = v9->pAS3Obj.pObject;
  if ( v11 )
  {
    if ( ((unsigned __int8)v11 & 1) != 0 )
    {
      v9->pAS3Obj.pObject = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v11 - 1);
    }
    else
    {
      RefCount = v11->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v11->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v11);
      }
    }
    v9->pAS3Obj.pObject = 0i64;
  }
  if ( (v9->Function.Flags & 0x1F) > 9 )
  {
    if ( (v9->Function.Flags & 0x200) != 0 )
    {
      pWeakProxy = v9->Function.Bonus.pWeakProxy;
      if ( pWeakProxy->RefCount-- == 1 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v9->Function.Flags &= 0xFFFFFDE0;
      v9->Function.Bonus.pWeakProxy = 0i64;
      v9->Function.value.VS._1.VStr = 0i64;
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
void __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::OnFocus(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        Scaleform::GFx::InteractiveObject::FocusEventType *evt,
        Scaleform::GFx::InteractiveObject *oldOrNewFocusCh,
        char controllerIdx)
{
  const char *v6; // rsi
  char *v7; // rcx
  __int64 v8; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v9; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *pClassName; // rbx
  __int64 v11; // rcx
  Scaleform::GFx::ASStringManager *v12; // rax
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *pObject; // rsi
  Scaleform::GFx::DisplayObject *AppDomain; // rdi
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v18; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp-28h] BYREF
  __int64 v21; // [rsp+48h] [rbp-20h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> v22; // [rsp+70h] [rbp+8h] BYREF

  v21 = -2i64;
  if ( this[-1].pClassName || this[-1].pDispObj )
  {
    v6 = "focusIn";
    if ( !(_DWORD)evt )
      v6 = "focusOut";
    if ( oldOrNewFocusCh )
    {
      v7 = (char *)oldOrNewFocusCh + 4 * (unsigned __int8)oldOrNewFocusCh->AvmObjOffset;
      v8 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v7 + 8i64))(v7);
      if ( v8 )
        v8 -= 56i64;
      v9 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v8 + 16);
      if ( !v9 )
        v9 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v8 + 8);
      if ( ((unsigned __int8)v9 & 1) != 0 )
        v9 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v9 - 1);
    }
    else
    {
      v9 = 0i64;
    }
    pClassName = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pClassName;
    if ( !pClassName )
      pClassName = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
    if ( ((unsigned __int8)pClassName & 1) != 0 )
      pClassName = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)pClassName - 1);
    v11 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)&this[-1].AppDomain->RefCount + 16i64) + 24i64);
    v12 = (Scaleform::GFx::ASStringManager *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v11 + 472i64))(v11);
    v13 = Scaleform::GFx::ASStringManager::CreateConstString(v12, &result, v6);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateFocusEventObject(
      pClassName,
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v22,
      v13,
      v9,
      controllerIdx,
      0);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    pObject = v22.pObject;
    AppDomain = (Scaleform::GFx::DisplayObject *)this[-1].AppDomain;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v22.pObject->Target,
      (Scaleform::GFx::AS3::Instances::fl::XMLList *)pClassName);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(pClassName, pObject, AppDomain);
    v18 = v22.pObject;
    if ( v22.pObject )
    {
      if ( ((__int64)v22.pObject & 1) != 0 )
      {
        --v22.pObject;
      }
      else
      {
        RefCount = v22.pObject->RefCount;
        if ( (RefCount & 0x3FFFFF) != 0 )
        {
          v22.pObject->RefCount = RefCount - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v18);
        }
      }
    }
  }
}

// File Line: 116
// RVA: 0x8047A0
char __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::OnFocusChange(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        Scaleform::GFx::InteractiveObject *toBeFocused,
        char controllerIdx,
        Scaleform::GFx::FocusMovedType fmt,
        Scaleform::GFx::ProcessFocusKeyInfo *pfocusKeyInfo)
{
  const char *v8; // rsi
  char *v10; // rcx
  __int64 v11; // rax
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *v12; // rdi
  Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *pAS3RawPtr; // rbx
  Scaleform::GFx::ASMovieRootBase *pObject; // rcx
  Scaleform::GFx::ASStringManager *v15; // rax
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ProcessFocusKeyInfo *v19; // rdx
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v20; // rsi
  Scaleform::GFx::DisplayObject *pDispObj; // rdi
  bool v22; // bl
  Scaleform::GFx::AS3::Instances::fl_events::FocusEvent *v23; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp-28h] BYREF
  __int64 v26; // [rsp+48h] [rbp-20h]
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::FocusEvent> v27; // [rsp+70h] [rbp+8h] BYREF

  v26 = -2i64;
  v8 = "mouseFocusChange";
  if ( fmt == GFx_FocusMovedByKeyboard )
    v8 = "keyFocusChange";
  if ( !this->pAS3RawPtr && !this->pAS3CollectiblePtr.pObject )
    return 1;
  if ( toBeFocused )
  {
    v10 = (char *)toBeFocused + 4 * (unsigned __int8)toBeFocused->AvmObjOffset;
    v11 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v10 + 8i64))(v10);
    if ( v11 )
      v11 -= 56i64;
    v12 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v11 + 16);
    if ( !v12 )
      v12 = *(Scaleform::GFx::AS3::Instances::fl_display::DisplayObject **)(v11 + 8);
    if ( ((unsigned __int8)v12 & 1) != 0 )
      v12 = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)v12 - 1);
  }
  else
  {
    v12 = 0i64;
  }
  pAS3RawPtr = this->pAS3RawPtr;
  if ( !pAS3RawPtr )
    pAS3RawPtr = this->pAS3CollectiblePtr.pObject;
  if ( ((unsigned __int8)pAS3RawPtr & 1) != 0 )
    pAS3RawPtr = (Scaleform::GFx::AS3::Instances::fl_display::DisplayObject *)((char *)pAS3RawPtr - 1);
  pObject = this->pDispObj->pASRoot->pMovieImpl->pASMovieRoot.pObject;
  v15 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pObject->vfptr[59].__vecDelDtor)(pObject);
  v16 = Scaleform::GFx::ASStringManager::CreateConstString(v15, &result, v8);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::CreateFocusEventObject(
    pAS3RawPtr,
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *)&v27,
    v16,
    v12,
    controllerIdx,
    0);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  *((_BYTE *)&v27.pObject->Scaleform::GFx::AS3::Instances::fl_events::Event + 84) |= 2u;
  if ( fmt == GFx_FocusMovedByKeyboard )
  {
    v19 = pfocusKeyInfo;
    v27.pObject->KeyCode = pfocusKeyInfo->KeyCode;
    v27.pObject->ShiftKey = v19->KeysState & 1;
  }
  v20 = v27.pObject;
  pDispObj = this->pDispObj;
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_geom::Vector3D>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl::XMLList> *)&v27.pObject->Target,
    (Scaleform::GFx::AS3::Instances::fl::XMLList *)pAS3RawPtr);
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::DoDispatchEvent(pAS3RawPtr, v20, pDispObj);
  v22 = (*((_BYTE *)&v27.pObject->Scaleform::GFx::AS3::Instances::fl_events::Event + 84) & 4) == 0;
  v23 = v27.pObject;
  if ( v27.pObject )
  {
    if ( ((__int64)v27.pObject & 1) != 0 )
    {
      --v27.pObject;
    }
    else
    {
      RefCount = v27.pObject->RefCount;
      if ( (RefCount & 0x3FFFFF) != 0 )
      {
        v27.pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
      }
    }
  }
  return v22;
}eform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v23);
      }
    }
 

// File Line: 144
// RVA: 0x7F0AF0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS3::AvmInteractiveObj::GetTopParent(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        __int64 ignoreLockRoot)
{
  Scaleform::GFx::DisplayObject *pDispObj; // r8
  Scaleform::GFx::InteractiveObject *pParent; // rcx

  pDispObj = this->pDispObj;
  pParent = pDispObj->pParent;
  if ( pParent && pParent->pASRoot->AVMVersion == 2 )
    return (Scaleform::GFx::InteractiveObject *)pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
                                                  pParent,
                                                  ignoreLockRoot);
  else
    return (Scaleform::GFx::InteractiveObject *)pDispObj;
}

// File Line: 152
// RVA: 0x7E60F0
Scaleform::GFx::AS3::AvmInteractiveObj *__fastcall Scaleform::GFx::AS3::AvmInteractiveObj::GetAvmTopParent(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        __int64 ignoreLockRoot)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  __int64 v3; // rax
  __int64 v4; // rcx
  __int64 v5; // rax

  pParent = this->pDispObj->pParent;
  if ( pParent->pASRoot->AVMVersion == 2
    && (v3 = (__int64)pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
                        pParent,
                        ignoreLockRoot),
        v4 = v3 + 4i64 * *(unsigned __int8 *)(v3 + 109),
        (v5 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v4 + 8i64))(v4)) != 0) )
  {
    return (Scaleform::GFx::AS3::AvmInteractiveObj *)(v5 - 56);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 161
// RVA: 0x7F93A0
bool __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::IsTabable(Scaleform::GFx::AS3::AvmInteractiveObj *this)
{
  bool result; // al
  Scaleform::GFx::AS3::VMAppDomain *AppDomain; // rax

  result = ((__int64 (__fastcall *)(Scaleform::GFx::AS3::VMAppDomain *))this[-1].AppDomain->Scaleform::GFx::AS3::AvmDisplayObj::vfptr[19].Finalize_GC)(this[-1].AppDomain);
  if ( result )
  {
    AppDomain = this[-1].AppDomain;
    if ( ((__int64)AppDomain[2]._pRCC & 0x60) != 0 )
      return ((__int64)AppDomain[2]._pRCC & 0x60) == 96;
    else
      return SWORD2(AppDomain[2].pRCCRaw) > 0;
  }
  return result;
}

// File Line: 174
// RVA: 0x7AA360
bool __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::ActsAsButton(Scaleform::GFx::AS3::AvmInteractiveObj *this)
{
  char *pClassName; // rax
  __int64 v2; // rcx

  pClassName = (char *)this[-1].pClassName;
  if ( !pClassName )
  {
    if ( !this[-1].pDispObj )
      return 1;
    pClassName = (char *)this[-1].pDispObj;
  }
  if ( ((unsigned __int8)pClassName & 1) != 0 )
    --pClassName;
  v2 = *((_QWORD *)pClassName + 8);
  return v2 && (*(_BYTE *)(v2 + 18) || *(_BYTE *)(v2 + 19));
}

// File Line: 183
// RVA: 0x7D2AB0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::AS3::AvmInteractiveObj::FindInsertToPlayList(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::DisplayObject *pDispObj; // r8
  Scaleform::GFx::InteractiveObject *pParent; // rax
  Scaleform::GFx::InteractiveObject *result; // rax

  pDispObj = this->pDispObj;
  if ( (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) != 0 )
    return 0i64;
  if ( (pDispObj->Scaleform::GFx::DisplayObjectBase::Flags & 0x1000) != 0 )
    return 0i64;
  if ( pDispObj->Depth < -1 )
    return 0i64;
  pParent = ch->pParent;
  if ( !pParent )
    return 0i64;
  result = pParent->pPlayPrev;
  if ( !result )
    return 0i64;
  return result;
}

// File Line: 202
// RVA: 0x8016F0
void __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(
        Scaleform::GFx::AS3::AvmInteractiveObj *this)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rbx
  __int64 v2; // rsi
  __int64 v4; // rdx
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // r8
  void *(__fastcall *i)(Scaleform::RefCountNTSImplCore *, unsigned int); // r9
  Scaleform::GFx::DisplayObject *pParent; // rax
  Scaleform::GFx::InteractiveObject *pPlayListHead; // rdi
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  Scaleform::GFx::InteractiveObject *v10; // rcx
  char *v11; // rcx
  __int64 v12; // rax
  __int64 v13; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v14; // rcx
  Scaleform::GFx::InteractiveObject *v15; // rcx
  Scaleform::GFx::MovieImpl *v16; // rax

  pDispObj = this->pDispObj;
  v2 = 0i64;
  v4 = *(_QWORD *)&pDispObj[1].RefCount;
  vfptr = pDispObj[1].Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
  for ( i = 0i64; v4; v4 = *(_QWORD *)(v4 + 152) )
  {
    pParent = (Scaleform::GFx::DisplayObject *)v4;
    while ( pParent != pDispObj )
    {
      pParent = pParent->pParent;
      if ( !pParent )
      {
        pPlayListHead = *(Scaleform::GFx::InteractiveObject **)(v4 + 144);
        i = (void *(__fastcall *)(Scaleform::RefCountNTSImplCore *, unsigned int))v4;
        *(_QWORD *)(v4 + 144) = vfptr;
        goto LABEL_9;
      }
    }
  }
  if ( vfptr )
  {
    pMovieImpl = pDispObj->pASRoot->pMovieImpl;
    pPlayListHead = pMovieImpl->pPlayListHead;
    pMovieImpl->pPlayListHead = (Scaleform::GFx::InteractiveObject *)vfptr;
LABEL_9:
    if ( vfptr )
      vfptr[19].__vecDelDtor = i;
  }
  else
  {
    pPlayListHead = (Scaleform::GFx::InteractiveObject *)this->pDispObj;
  }
  pDispObj[1].Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = 0i64;
  pPlayListHead->pPlayPrev = 0i64;
  v10 = this->pDispObj->pParent;
  if ( !v10 )
    goto LABEL_19;
  v11 = (char *)v10 + 4 * (unsigned __int8)v10->AvmObjOffset;
  v12 = (*(__int64 (__fastcall **)(char *, __int64, Scaleform::RefCountNTSImplCoreVtbl *, void *(__fastcall *)(Scaleform::RefCountNTSImplCore *, unsigned int)))(*(_QWORD *)v11 + 8i64))(
          v11,
          v4,
          vfptr,
          i);
  if ( v12 )
    v2 = v12 - 56;
  v13 = (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::DisplayObject *))(*(_QWORD *)v2 + 200i64))(v2, pDispObj);
  if ( v13 )
  {
    v14 = *(Scaleform::RefCountNTSImplCoreVtbl **)(v13 + 144);
    pDispObj[1].Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = v14;
    if ( v14 )
      v14[19].__vecDelDtor = (void *(__fastcall *)(Scaleform::RefCountNTSImplCore *, unsigned int))pDispObj;
    *(_QWORD *)(v13 + 144) = pPlayListHead;
    pPlayListHead->pPlayPrev = (Scaleform::GFx::InteractiveObject *)v13;
  }
  else
  {
LABEL_19:
    v15 = this->pDispObj->pASRoot->pMovieImpl->pPlayListHead;
    if ( v15 )
    {
      pDispObj[1].Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)v15;
      v15->pPlayPrev = (Scaleform::GFx::InteractiveObject *)pDispObj;
    }
    this->pDispObj->pASRoot->pMovieImpl->pPlayListHead = pPlayListHead;
  }
  v16 = this->pDispObj->pASRoot->pMovieImpl;
  v16->Flags |= 0x80000u;
}

// File Line: 290
// RVA: 0x7F6860
void __fastcall Scaleform::GFx::AS3::AvmInteractiveObj::InsertChildToPlayList(
        Scaleform::GFx::AS3::AvmInteractiveObj *this,
        Scaleform::GFx::InteractiveObject *ch)
{
  Scaleform::GFx::InteractiveObject *v3; // rax

  v3 = (Scaleform::GFx::InteractiveObject *)(*((__int64 (__fastcall **)(Scaleform::GFx::AS3::AvmInteractiveObj *))&this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].__vecDelDtor
                                             + 1))(this);
  if ( v3 )
    Scaleform::GFx::InteractiveObject::InsertToPlayListAfter(ch, v3);
  else
    Scaleform::GFx::InteractiveObject::AddToPlayList(ch);
}

