// File Line: 117
// RVA: 0x77ADB0
void __fastcall Scaleform::GFx::AS3::AvmButton::AvmButton(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::Button *pbutton)
{
  Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(this, pbutton);
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmButtonBase::`vftable;
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmButton::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  this->Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmButton::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AvmButtonBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmButton::`vftable;
  pbutton->Scaleform::GFx::InteractiveObject::Flags |= 0x60u;
}

// File Line: 129
// RVA: 0x804E30
char __fastcall Scaleform::GFx::AS3::AvmButton::OnMouseEvent(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::EventId *evt)
{
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *pDispObj; // rcx
  unsigned int WcharCode; // eax
  Scaleform::GFx::EventId evtId; // [rsp+20h] [rbp-28h] BYREF

  if ( evt->Id != 1024 )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *, Scaleform::GFx::EventId *, Scaleform::GFx::AS3::AvmButton *))this[-1].pAS3CollectiblePtr.pObject->pImpl.pObject)(
             &this[-1].pAS3CollectiblePtr,
             evt,
             this);
  pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
  if ( pDispObj || this[-1].pAS3RawPtr )
  {
    evtId.Id = evt->Id;
    WcharCode = evt->WcharCode;
    evtId.Id = 16777228;
    evtId.WcharCode = WcharCode;
    evtId.KeyCode = evt->KeyCode;
    evtId.TouchID = evt->TouchID;
    *(_DWORD *)&evtId.RollOverCnt = *(_DWORD *)&evt->RollOverCnt;
    if ( !pDispObj )
      pDispObj = this[-1].pAS3RawPtr;
    if ( ((unsigned __int8)pDispObj & 1) != 0 )
      pDispObj = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)pDispObj - 1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
      pDispObj,
      &evtId,
      (Scaleform::GFx::DisplayObject *)this[-1].pClassName);
  }
  return 1;
}

// File Line: 150
// RVA: 0x7E74A0
_BOOL8 __fastcall Scaleform::GFx::AS3::AvmButton::GetCursorType(Scaleform::GFx::AS3::AvmButton *this)
{
  return (*(_DWORD *)(*(_QWORD *)&this[-1].Scaleform::GFx::AS3::AvmInteractiveObj::Scaleform::GFx::AS3::AvmDisplayObj::Flags
                    + 184i64) & 0x10) != 0;
}

// File Line: 161
// RVA: 0x7BBF70
void __fastcall Scaleform::GFx::AS3::AvmButton::CreateCharacters(Scaleform::GFx::AS3::AvmButton *this)
{
  char *pClassName; // r13
  __int64 v2; // rbx
  Scaleform::GFx::Button::ButtonState ButtonState; // eax
  __int64 v4; // rcx
  __int64 v5; // rbx
  unsigned __int8 v6; // al
  char v7; // r15
  __int64 v8; // r12
  __int64 v9; // r14
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *v10; // rsi
  unsigned __int64 pObject; // rdi
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *v12; // rax
  Scaleform::Render::TreeContainer *v13; // rcx
  bool v14; // zf
  const char *v15; // rdx
  __int64 v16; // rcx
  Scaleform::GFx::InteractiveObject *v17; // rbx
  __int64 v18; // rax
  Scaleform::GFx::DisplayObjectBase *v19; // r13
  __int64 v20; // rcx
  __int64 v21; // rdx
  Scaleform::GFx::InteractiveObject **v22; // rdx
  __int64 v23; // rdx
  unsigned int Flags; // ecx
  int v25; // eax
  Scaleform::Render::TreeNode *RenderNode; // r9
  __int64 v27; // r8
  unsigned __int64 v28; // rdx
  Scaleform::GFx::ASString *v29; // rax
  __int64 v30; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned __int64 v32; // r9
  __int64 v33; // r8
  __int64 v34; // rdx
  unsigned __int64 v35; // rdx
  __int64 v36; // [rsp+50h] [rbp-B0h]
  __int64 v37; // [rsp+60h] [rbp-A0h]
  __int64 v38; // [rsp+68h] [rbp-98h]
  __int64 v39; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::ASString v40; // [rsp+78h] [rbp-88h] BYREF
  Scaleform::Render::TreeContainer *v41; // [rsp+80h] [rbp-80h]
  char *v42; // [rsp+88h] [rbp-78h]
  __int64 v43; // [rsp+90h] [rbp-70h]
  Scaleform::Render::Cxform v44; // [rsp+A0h] [rbp-60h] BYREF
  __int128 v45; // [rsp+C0h] [rbp-40h]
  __m128 v46; // [rsp+D0h] [rbp-30h]
  Scaleform::Render::RenderBuffer *v47; // [rsp+E0h] [rbp-20h]
  __int64 v48; // [rsp+E8h] [rbp-18h]
  int v49; // [rsp+F0h] [rbp-10h]
  __int64 v50; // [rsp+F8h] [rbp-8h]
  int v51; // [rsp+100h] [rbp+0h]
  __int16 v52; // [rsp+104h] [rbp+4h]
  Scaleform::Ptr<Scaleform::Render::TreeContainer> result; // [rsp+110h] [rbp+10h] BYREF
  __int64 v54; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::InteractiveObject *v55; // [rsp+120h] [rbp+20h]
  __int64 v56; // [rsp+128h] [rbp+28h]
  __int64 v57; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::InteractiveObject **v58; // [rsp+138h] [rbp+38h]
  Scaleform::GFx::CharacterCreateInfo v59; // [rsp+140h] [rbp+40h] BYREF
  Scaleform::GFx::CharacterCreateInfo v60; // [rsp+158h] [rbp+58h] BYREF
  unsigned __int8 v62; // [rsp+1C8h] [rbp+C8h]
  Scaleform::GFx::InteractiveObject **rid; // [rsp+1D0h] [rbp+D0h] BYREF
  int v64; // [rsp+1D8h] [rbp+D8h] BYREF

  v54 = -2i64;
  pClassName = (char *)this[-1].pClassName;
  v42 = pClassName;
  v43 = *((_QWORD *)pClassName + 27);
  v2 = v43;
  ButtonState = Scaleform::GFx::Button::GetButtonState(*((Scaleform::GFx::ButtonRecord::MouseState *)pClassName + 90));
  v38 = *(_QWORD *)(v43 + 40);
  v39 = ButtonState;
  if ( v38 )
  {
    v4 = 0i64;
    v37 = 0i64;
    do
    {
      v5 = v4 + *(_QWORD *)(v2 + 32);
      v36 = v5;
      v6 = *(_BYTE *)(v5 + 84);
      v62 = v6;
      v7 = 1;
      do
      {
        if ( ((unsigned __int8)v7 & v6) == 0 )
          goto LABEL_78;
        LODWORD(v8) = 0;
        v9 = 0i64;
        if ( (v7 & 8) == 0 )
        {
          if ( (v7 & 2) != 0 )
          {
            v8 = 2i64;
LABEL_12:
            v9 = v8;
            goto LABEL_13;
          }
          if ( (v7 & 4) != 0 )
          {
            v8 = 1i64;
            goto LABEL_12;
          }
          if ( (v7 & 1) != 0 )
          {
            v8 = 3i64;
            goto LABEL_12;
          }
        }
LABEL_13:
        v10 = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&pClassName[32 * v9 + 232];
        pObject = *(_QWORD *)&pClassName[32 * v9 + 224];
        if ( pObject )
          ++*(_QWORD *)(pObject + 8);
        v41 = (Scaleform::Render::TreeContainer *)pObject;
        if ( !pObject )
        {
          v12 = Scaleform::GFx::Button::CreateStateRenderContainer(
                  (Scaleform::GFx::Button *)pClassName,
                  &result,
                  (Scaleform::GFx::Button::ButtonState)v8);
          if ( v12->pObject )
            ++v12->pObject->RefCount;
          pObject = (unsigned __int64)v12->pObject;
          v41 = v12->pObject;
          v13 = result.pObject;
          if ( result.pObject )
          {
            v14 = result.pObject->RefCount-- == 1;
            if ( v14 )
              Scaleform::Render::ContextImpl::Entry::destroyHelper(v13);
          }
        }
        if ( v10->Size )
        {
          v17 = 0i64;
          if ( (v10->Data->Char.pObject->Flags & 0x400) != 0 )
            v17 = (Scaleform::GFx::InteractiveObject *)v10->Data->Char.pObject;
          if ( v17 )
            ++v17->RefCount;
        }
        else
        {
          LODWORD(rid) = 65537;
          Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
            *((Scaleform::GFx::MovieDefImpl **)this[-1].pClassName + 22),
            &v59,
            (Scaleform::GFx::ResourceId)&rid);
          v15 = this[-1].pClassName;
          v16 = *(_QWORD *)(*((_QWORD *)v15 + 4) + 24i64);
          v64 = *(_DWORD *)(v5 + 72);
          v17 = 0i64;
          v18 = (*(__int64 (__fastcall **)(__int64, _QWORD, Scaleform::GFx::CharacterCreateInfo *, _QWORD, int *, _DWORD))(*(_QWORD *)v16 + 32i64))(
                  v16,
                  *(_QWORD *)(*((_QWORD *)v15 + 4) + 16i64),
                  &v59,
                  0i64,
                  &v64,
                  0);
          v19 = (Scaleform::GFx::DisplayObjectBase *)v18;
          v57 = v18;
          if ( (*(_WORD *)(v18 + 106) & 0x400) != 0 )
            v17 = (Scaleform::GFx::InteractiveObject *)v18;
          if ( v17 )
            ++v17->RefCount;
          if ( v17 )
            ++v17->RefCount;
          v55 = v17;
          v56 = v36;
          Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            v10,
            v10,
            v10->Size + 1);
          v20 = 16 * v10->Size;
          v21 = (__int64)&v10->Data[-1];
          v14 = v20 + v21 == 0;
          v22 = (Scaleform::GFx::InteractiveObject **)(v20 + v21);
          rid = v22;
          v58 = v22;
          if ( !v14 )
          {
            if ( v17 )
              ++v17->RefCount;
            *v22 = v17;
            v22[1] = (Scaleform::GFx::InteractiveObject *)v36;
          }
          if ( v17 )
            Scaleform::RefCountNTSImpl::Release(v17);
          if ( !v17->pParent )
          {
            Scaleform::GFx::InteractiveObject::AddToPlayList(v17);
            Flags = v17->Flags;
            if ( (Flags & 0x200000) == 0 || (Flags & 0x400000) != 0 )
              v23 = 0i64;
            else
              LOBYTE(v23) = 1;
            v25 = (int)v17->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
                         v17,
                         v23);
            if ( v25 == -1 )
            {
              v17->Flags |= 0x400000u;
            }
            else if ( v25 == 1 )
            {
              Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v17);
            }
          }
          RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v19);
          v27 = *(_QWORD *)(*(_QWORD *)((pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                          + 8i64 * (unsigned int)((int)(pObject - (pObject & 0xFFFFF000) - 56) / 56)
                          + 40);
          v28 = *(_QWORD *)(v27 + 144);
          if ( v28 )
          {
            if ( (v28 & 1) != 0 )
              v28 = *(_QWORD *)((v28 & 0xFFFFFFFFFFFFFFFEui64) + 8);
            else
              v28 = (*(_QWORD *)(v27 + 152) != 0i64) + 1i64;
          }
          Scaleform::Render::TreeContainer::Insert((Scaleform::Render::TreeContainer *)pObject, v28, RenderNode);
          Scaleform::RefCountNTSImpl::Release(v19);
          pClassName = v42;
        }
        LODWORD(rid) = *(_DWORD *)(v36 + 72);
        Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
          *((Scaleform::GFx::MovieDefImpl **)this[-1].pClassName + 22),
          &v60,
          (Scaleform::GFx::ResourceId)&rid);
        if ( v60.pCharDef )
        {
          Scaleform::Render::Cxform::Cxform(&v44);
          v45 = _xmm;
          v46 = _xmm;
          v47 = 0i64;
          v49 = 0x40000;
          v51 = 0;
          v48 = 0i64;
          v52 = 256;
          v50 = 0i64;
          v44 = *(Scaleform::Render::Cxform *)(v36 + 32);
          v45 = *(_OWORD *)v36;
          v46 = *(__m128 *)(v36 + 16);
          v49 = *(_DWORD *)(v36 + 72);
          LOBYTE(v52) = *(_BYTE *)(v36 + 80);
          HIDWORD(v48) = *(unsigned __int16 *)(v36 + 76);
          HIWORD(v51) = 143;
          v29 = Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)(*((_QWORD *)this[-1].pClassName + 4) + 360i64),
                  &v40);
          v30 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, _QWORD, _DWORD, int, _QWORD, _QWORD))v17->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[118].__vecDelDtor)(
                  v17,
                  &v44,
                  v29,
                  0i64,
                  0i64,
                  0,
                  4,
                  0i64,
                  0i64);
          pNode = v40.pNode;
          v14 = v40.pNode->RefCount-- == 1;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          if ( v30 && *(_QWORD *)(v36 + 64) )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v30 + 448i64))(v30);
          if ( (pClassName[106] & 1) != 0 )
          {
            v17->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 1u;
            ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v17->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[20].__vecDelDtor)(v17);
          }
          if ( v47 )
            Scaleform::RefCountImpl::Release(v47);
        }
        if ( (_DWORD)v8 == 3 )
          v17->pParent = (Scaleform::GFx::InteractiveObject *)pClassName;
        if ( v39 == v9 && !*(_QWORD *)(pObject + 32) )
        {
          v32 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)pClassName + 552i64))(pClassName);
          v33 = *(_QWORD *)(*(_QWORD *)((v32 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                          + 8i64 * (unsigned int)((int)(v32 - (v32 & 0xFFFFF000) - 56) / 56)
                          + 40);
          v34 = *(_QWORD *)(v33 + 144);
          if ( v34 )
          {
            if ( (v34 & 1) != 0 )
              v35 = *(_QWORD *)((v34 & 0xFFFFFFFFFFFFFFFEui64) + 8);
            else
              v35 = (*(_QWORD *)(v33 + 152) != 0i64) + 1i64;
          }
          else
          {
            v35 = 0i64;
          }
          Scaleform::Render::TreeContainer::Insert(
            (Scaleform::Render::TreeContainer *)v32,
            v35,
            (Scaleform::Render::TreeNode *)pObject);
        }
        if ( v17 )
          Scaleform::RefCountNTSImpl::Release(v17);
        if ( pObject )
        {
          v14 = (*(_QWORD *)(pObject + 8))-- == 1i64;
          if ( v14 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)pObject);
        }
        v5 = v36;
        v6 = v62;
LABEL_78:
        v7 *= 2;
      }
      while ( (v7 & 0xF) != 0 );
      v4 = v37 + 96;
      v37 += 96i64;
      v14 = v38-- == 1;
      v2 = v43;
    }
    while ( !v14 );
  }
}

// File Line: 276
// RVA: 0x8254B0
void __fastcall Scaleform::GFx::AS3::AvmButton::SwitchState(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  const char *pClassName; // r8
  __int16 v4; // r9
  Scaleform::GFx::Button::ButtonState ButtonState; // eax

  pClassName = this[-1].pClassName;
  v4 = *((_WORD *)pClassName + 53);
  if ( (v4 & 0x10) == 0 && (v4 & 0x1000) == 0 && *((int *)pClassName + 11) >= -1 )
  {
    ButtonState = Scaleform::GFx::Button::GetButtonState(mouseState);
    Scaleform::GFx::AS3::AvmButton::SwitchStateIntl((Scaleform::GFx::AS3::AvmButton *)((char *)this - 72), ButtonState);
  }
}

// File Line: 286
// RVA: 0x825500
void __fastcall Scaleform::GFx::AS3::AvmButton::SwitchStateIntl(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::Button::ButtonState bs)
{
  __int64 v2; // rbp
  Scaleform::GFx::DisplayObject *pDispObj; // r12
  unsigned __int16 Flags; // cx
  Scaleform::Render::TreeContainer *v5; // rax
  Scaleform::Render::TreeContainer *v6; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v7; // rbx
  unsigned int v8; // esi
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType **p_pPerspectiveData; // r14
  long double FieldOfView; // rdi
  long double v11; // r15
  __int64 v12; // rcx
  __int64 v13; // rcx
  __int64 v14; // rcx
  __int64 v15; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v16; // rcx
  Scaleform::GFx::DisplayObjectBase **v17; // rax
  Scaleform::GFx::DisplayObjectBase *v18; // rdi
  Scaleform::GFx::DisplayObjectBase *v19; // r14
  Scaleform::Render::TreeContainer *v20; // rbp
  Scaleform::GFx::InteractiveObject *pParent; // rax
  Scaleform::GFx::InteractiveObject *v22; // rcx
  char *v23; // rcx
  Scaleform::Render::TreeNode *RenderNode; // rax
  char *v25; // rcx
  __int64 v26; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v27; // rcx
  __int64 v28; // rsi
  _WORD *v29; // rdi
  Scaleform::Render::TreeContainer *v30; // rax

  v2 = bs;
  pDispObj = this->pDispObj;
  Flags = pDispObj->Scaleform::GFx::DisplayObjectBase::Flags;
  if ( (Flags & 0x10) == 0 && (Flags & 0x1000) == 0 && pDispObj->Depth >= -1 )
  {
    v5 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))pDispObj->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[69].__vecDelDtor)(pDispObj);
    if ( Scaleform::Render::TreeContainer::GetSize(v5) )
    {
      v6 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))pDispObj->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[69].__vecDelDtor)(pDispObj);
      Scaleform::Render::TreeContainer::Remove(v6, 0i64, 1ui64);
    }
    v7 = 0i64;
    v8 = 0;
    p_pPerspectiveData = &pDispObj[1].pPerspectiveData;
    do
    {
      if ( p_pPerspectiveData[1] )
      {
        FieldOfView = 0.0;
        if ( (*(_BYTE *)(*(_QWORD *)&(*p_pPerspectiveData)->FieldOfView + 107i64) & 1) != 0 )
          FieldOfView = (*p_pPerspectiveData)->FieldOfView;
        v11 = 0.0;
        if ( (*(_WORD *)(*(_QWORD *)&FieldOfView + 106i64) & 0x200) != 0 )
          v11 = FieldOfView;
        if ( v8 != (_DWORD)v2 )
        {
          v12 = *(_QWORD *)(*(_QWORD *)&FieldOfView + 56i64);
          if ( v12 )
          {
            v13 = v12 + 4i64 * *(unsigned __int8 *)(v12 + 109);
            (*(void (__fastcall **)(__int64, long double))(*(_QWORD *)v13 + 168i64))(
              v13,
              COERCE_LONG_DOUBLE(*(_QWORD *)&FieldOfView));
            *(_QWORD *)(*(_QWORD *)&FieldOfView + 56i64) = 0i64;
            if ( v11 != 0.0 )
            {
              v14 = *(_QWORD *)&v11 + 4i64 * *(unsigned __int8 *)(*(_QWORD *)&v11 + 109i64);
              v15 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 8i64))(v14);
              v16 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v15 - 56);
              if ( !v15 )
                v16 = 0i64;
              Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v16);
            }
          }
        }
      }
      ++v8;
      p_pPerspectiveData += 4;
    }
    while ( v8 < 3 );
    if ( *((_QWORD *)&pDispObj[1].pIndXFormData + 4 * v2) )
    {
      v17 = (Scaleform::GFx::DisplayObjectBase **)*((_QWORD *)&pDispObj[1].pPerspectiveData + 4 * v2);
      v18 = 0i64;
      if ( ((*v17)->Flags & 0x100) != 0 )
        v18 = *v17;
      v19 = 0i64;
      if ( (v18->Flags & 0x200) != 0 )
        v19 = v18;
      v20 = (Scaleform::Render::TreeContainer *)*((_QWORD *)&pDispObj[1].pGeomData + 4 * v2);
      if ( v20 )
        ++v20->RefCount;
      pParent = v18->pParent;
      if ( pParent && (pParent != pDispObj || Scaleform::GFx::DisplayObjectBase::GetRenderNode(v18)->pParent != v20) )
      {
        v22 = v18->pParent;
        if ( v22 )
          v23 = (char *)v22 + 4 * (unsigned __int8)v22->AvmObjOffset;
        else
          v23 = 0i64;
        (*(void (__fastcall **)(char *, Scaleform::GFx::DisplayObjectBase *))(*(_QWORD *)v23 + 168i64))(v23, v18);
      }
      if ( !Scaleform::GFx::DisplayObjectBase::GetRenderNode(v18)->pParent )
      {
        RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v18);
        Scaleform::Render::TreeContainer::Add(v20, RenderNode);
      }
      if ( !v18->pParent )
      {
        v18->pParent = (Scaleform::GFx::InteractiveObject *)pDispObj;
        if ( v19 )
        {
          v25 = (char *)v19 + 4 * (unsigned __int8)v19->AvmObjOffset;
          v26 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v25 + 8i64))(v25);
          v27 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v26 - 56);
          if ( !v26 )
            v27 = 0i64;
          Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v27);
          if ( v19[2].Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr )
          {
            v28 = 0i64;
            do
            {
              v29 = *(_WORD **)(v28 + *(_QWORD *)&v19[1].ClipDepth);
              if ( (v29[53] & 0x400) != 0 )
              {
                (*(void (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)v29 + 880i64))(
                  *(_QWORD *)(v28 + *(_QWORD *)&v19[1].ClipDepth),
                  0i64);
                (*(void (__fastcall **)(_WORD *, _QWORD))(*(_QWORD *)v29 + 912i64))(v29, 0i64);
              }
              v7 = (Scaleform::RefCountNTSImplCoreVtbl *)((char *)v7 + 1);
              v28 += 16i64;
            }
            while ( v7 < v19[2].Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr );
          }
        }
      }
      v30 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))pDispObj->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[69].__vecDelDtor)(pDispObj);
      Scaleform::Render::TreeContainer::Add(v30, v20);
      if ( v20 )
      {
        if ( v20->RefCount-- == 1 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v20);
      }
    }
  }
}

// File Line: 389
// RVA: 0x7C4790
__int64 __fastcall Scaleform::GFx::AS3::AvmButton::DetachChild(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::DisplayObjectBase *child)
{
  unsigned __int8 v3; // bl
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType **p_pIndXFormData; // rsi
  __int64 v5; // r14
  Scaleform::Render::ContextImpl::Entry *v6; // rax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v7; // rdi
  __int64 v8; // r13
  Scaleform::Render::TreeContainer *pParent; // r12
  unsigned __int64 v10; // rdi
  __int64 v11; // r14
  __int64 v12; // r8
  __int64 v13; // rsi
  unsigned __int64 v14; // rsi
  _QWORD *v15; // rax
  Scaleform::Render::TreeNode *v16; // rbx
  Scaleform::Render::ContextImpl::Entry *v19; // [rsp+20h] [rbp-58h]
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v20; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType **v21; // [rsp+90h] [rbp+18h]
  __int64 v22; // [rsp+98h] [rbp+20h]

  v3 = 0;
  p_pIndXFormData = &this->pDispObj[1].pIndXFormData;
  v21 = p_pIndXFormData;
  v5 = 3i64;
  v22 = 3i64;
  do
  {
    v6 = (Scaleform::Render::ContextImpl::Entry *)*(p_pIndXFormData - 2);
    v19 = v6;
    if ( v6 )
      ++v6->RefCount;
    v7 = *p_pIndXFormData;
    v20 = *p_pIndXFormData;
    if ( *p_pIndXFormData )
    {
      v8 = 0i64;
      do
      {
        if ( *(Scaleform::GFx::DisplayObjectBase **)&(*(p_pIndXFormData - 1))->OrigTransformMatrix.M[v8][0] == child )
        {
          child->pParent = 0i64;
          if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(child) )
          {
            pParent = (Scaleform::Render::TreeContainer *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(child)->pParent;
            if ( pParent )
            {
              v10 = 0i64;
              v11 = (__int64)((__int64)&pParent[-1] - ((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64)) / 56;
              v12 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                              + 8i64 * (unsigned int)v11
                              + 40);
              v13 = *(_QWORD *)(v12 + 144);
              if ( v13 )
              {
                v14 = (v13 & 1) != 0
                    ? *(_QWORD *)((v13 & 0xFFFFFFFFFFFFFFFEui64) + 8)
                    : (*(_QWORD *)(v12 + 152) != 0i64) + 1i64;
                if ( v14 )
                {
                  while ( 1 )
                  {
                    v15 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                               + 8i64 * (unsigned int)v11
                                               + 40)
                                   + 144i64);
                    if ( (*(_BYTE *)v15 & 1) != 0 )
                      v15 = (_QWORD *)((*v15 & 0xFFFFFFFFFFFFFFFEui64) + 16);
                    v16 = (Scaleform::Render::TreeNode *)v15[v10];
                    if ( v16 == Scaleform::GFx::DisplayObjectBase::GetRenderNode(child) )
                      break;
                    if ( ++v10 >= v14 )
                      goto LABEL_20;
                  }
                  Scaleform::Render::TreeContainer::Remove(pParent, v10, 1ui64);
                }
              }
LABEL_20:
              p_pIndXFormData = v21;
              v7 = v20;
            }
          }
          v3 = 1;
        }
        ++v8;
        v7 = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)((char *)v7 - 1);
        v20 = v7;
      }
      while ( v7 );
      v6 = v19;
      v5 = v22;
    }
    if ( v6 )
    {
      if ( v6->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
    }
    p_pIndXFormData += 4;
    v21 = p_pIndXFormData;
    v22 = --v5;
  }
  while ( v5 );
  return v3;
}

// File Line: 429
// RVA: 0x81E7C0
void __fastcall Scaleform::GFx::AS3::AvmButton::SetStateObject(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::Button::ButtonState state,
        Scaleform::GFx::DisplayObject *ch)
{
  __int64 v4; // rsi
  Scaleform::GFx::Button *pDispObj; // rbp
  Scaleform::Render::TreeContainer *pObject; // rbx
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *v8; // rax
  Scaleform::Render::TreeContainer *v9; // rcx
  bool v10; // zf
  __int64 Size; // rax
  Scaleform::GFx::InteractiveObject *pParent; // rax
  Scaleform::GFx::InteractiveObject *v13; // rcx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *p_Data; // rcx
  Scaleform::RefCountNTSImpl **p_pObject; // rbx
  Scaleform::Ptr<Scaleform::Render::TreeContainer> result; // [rsp+60h] [rbp+18h] BYREF

  v4 = state;
  pDispObj = (Scaleform::GFx::Button *)this->pDispObj;
  if ( state != Hit )
  {
    pObject = pDispObj->States[state].pRenNode.pObject;
    if ( pObject )
      ++pObject->RefCount;
    if ( pObject )
    {
      Size = Scaleform::Render::TreeContainer::GetSize(pObject);
      Scaleform::Render::TreeContainer::Remove(pObject, 0i64, Size);
    }
    else
    {
      v8 = Scaleform::GFx::Button::CreateStateRenderContainer(pDispObj, &result, state);
      if ( v8->pObject )
        ++v8->pObject->RefCount;
      pObject = v8->pObject;
      v9 = result.pObject;
      if ( result.pObject )
      {
        v10 = result.pObject->RefCount-- == 1;
        if ( v10 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v9);
      }
    }
    pParent = ch->pParent;
    if ( pParent && (pParent != pDispObj || Scaleform::GFx::DisplayObjectBase::GetRenderNode(ch)->pParent != pObject) )
    {
      v13 = ch->pParent;
      if ( v13 )
        v13 = (Scaleform::GFx::InteractiveObject *)((char *)v13 + 4 * (unsigned __int8)v13->AvmObjOffset);
      if ( v13->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[21].__vecDelDtor(
             v13,
             (unsigned int)ch) )
      {
        ch->pParent = pDispObj;
      }
    }
    if ( !Scaleform::GFx::DisplayObjectBase::GetRenderNode(ch)->pParent )
    {
      RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(ch);
      Scaleform::Render::TreeContainer::Add(pObject, RenderNode);
    }
    if ( pObject )
    {
      v10 = pObject->RefCount-- == 1;
      if ( v10 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
    }
  }
  p_Data = &pDispObj->States[v4].Characters.Data;
  if ( ch )
  {
    Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      p_Data,
      1ui64);
    p_pObject = &pDispObj->States[v4].Characters.Data.Data->Char.pObject;
    ++ch->RefCount;
    if ( *p_pObject )
      Scaleform::RefCountNTSImpl::Release(*p_pObject);
    *p_pObject = ch;
  }
  else
  {
    Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      p_Data,
      0i64);
  }
  if ( Scaleform::GFx::Button::GetButtonState(pDispObj->MouseState) == (_DWORD)v4 )
    Scaleform::GFx::AS3::AvmButton::SwitchStateIntl(this, (Scaleform::GFx::Button::ButtonState)v4);
}

// File Line: 525
// RVA: 0x819970
void __fastcall Scaleform::GFx::AS3::AvmButton::SetHitStateObject(
        Scaleform::GFx::AS3::AvmButton *this,
        Scaleform::GFx::DisplayObject *ch)
{
  Scaleform::GFx::DisplayObject *pDispObj; // rbp
  Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *p_Id; // rcx
  Scaleform::RefCountNTSImpl **v6; // rdi

  pDispObj = this->pDispObj;
  p_Id = (Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&pDispObj[2].Id;
  if ( ch )
  {
    Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      p_Id,
      1ui64);
    v6 = *(Scaleform::RefCountNTSImpl ***)&pDispObj[2].Id.Id;
    ++ch->RefCount;
    if ( *v6 )
      Scaleform::RefCountNTSImpl::Release(*v6);
    *v6 = ch;
  }
  else
  {
    Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      p_Id,
      0i64);
  }
  if ( Scaleform::GFx::Button::GetButtonState((Scaleform::GFx::ButtonRecord::MouseState)pDispObj[2].pRenNode.pObject) == Hit )
    Scaleform::GFx::AS3::AvmButton::SwitchStateIntl(this, Hit);
}

