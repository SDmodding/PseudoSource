// File Line: 117
// RVA: 0x77ADB0
void __fastcall Scaleform::GFx::AS3::AvmButton::AvmButton(Scaleform::GFx::AS3::AvmButton *this, Scaleform::GFx::Button *pbutton)
{
  Scaleform::GFx::Button *v2; // rbx
  Scaleform::GFx::AS3::AvmButton *v3; // rdi
  Scaleform::GFx::AvmButtonBase *v4; // [rsp+50h] [rbp+18h]

  v2 = pbutton;
  v3 = this;
  Scaleform::GFx::AS3::AvmInteractiveObj::AvmInteractiveObj(
    (Scaleform::GFx::AS3::AvmInteractiveObj *)&this->vfptr,
    (Scaleform::GFx::InteractiveObject *)&pbutton->vfptr);
  v4 = (Scaleform::GFx::AvmButtonBase *)&v3->vfptr;
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmButtonBase::`vftable;
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmButton::`vftable{for `Scaleform::GFx::AS3::AvmDisplayObj};
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmButton::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  v4->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS3::AvmButton::`vftable;
  v2->Flags |= 0x60u;
}

// File Line: 129
// RVA: 0x804E30
char __fastcall Scaleform::GFx::AS3::AvmButton::OnMouseEvent(Scaleform::GFx::AS3::AvmButton *this, Scaleform::GFx::EventId *evt)
{
  Scaleform::GFx::AS3::AvmButton *v2; // r8
  Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *v3; // rcx
  unsigned int v4; // eax
  Scaleform::GFx::EventId evtId; // [rsp+20h] [rbp-28h]

  v2 = this;
  if ( evt->Id != 1024 )
    return ((__int64 (__fastcall *)(Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::DisplayObject> *, Scaleform::GFx::EventId *, Scaleform::GFx::AS3::AvmButton *))this[-1].pAS3CollectiblePtr.pObject->pImpl.pObject)(
             &this[-1].pAS3CollectiblePtr,
             evt,
             this);
  v3 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)this[-1].pDispObj;
  if ( v3 || v2[-1].pAS3RawPtr )
  {
    evtId.Id = evt->Id;
    v4 = evt->WcharCode;
    evtId.Id = 16777228;
    evtId.WcharCode = v4;
    evtId.KeyCode = evt->KeyCode;
    evtId.TouchID = evt->TouchID;
    *(_DWORD *)&evtId.RollOverCnt = *(_DWORD *)&evt->RollOverCnt;
    if ( !v3 )
      v3 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)&v2[-1].pAS3RawPtr->vfptr;
    if ( (unsigned __int8)v3 & 1 )
      v3 = (Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher *)((char *)v3 - 1);
    Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Dispatch(
      v3,
      &evtId,
      (Scaleform::GFx::DisplayObject *)v2[-1].pClassName);
  }
  return 1;
}

// File Line: 150
// RVA: 0x7E74A0
__int64 __fastcall Scaleform::GFx::AS3::AvmButton::GetCursorType(Scaleform::GFx::AS3::AvmButton *this)
{
  return (*(_DWORD *)(*(_QWORD *)&this[-1].Flags + 184i64) >> 4) & 1;
}

// File Line: 161
// RVA: 0x7BBF70
void __fastcall Scaleform::GFx::AS3::AvmButton::CreateCharacters(Scaleform::GFx::AS3::AvmButton *this)
{
  char *v1; // r13
  __int64 v2; // rbx
  Scaleform::GFx::Button::ButtonState v3; // eax
  signed __int64 v4; // rcx
  signed __int64 v5; // rbx
  unsigned __int8 v6; // al
  char v7; // r15
  signed __int64 v8; // r12
  signed __int64 v9; // r14
  Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *v10; // rsi
  unsigned __int64 v11; // rdi
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *v12; // rax
  Scaleform::Render::TreeContainer *v13; // rcx
  bool v14; // zf
  const char *v15; // rdx
  __int64 v16; // rcx
  Scaleform::GFx::InteractiveObject *v17; // rbx
  __int64 v18; // rax
  Scaleform::GFx::DisplayObjectBase *v19; // r13
  signed __int64 v20; // rcx
  signed __int64 v21; // rdx
  Scaleform::GFx::InteractiveObject **v22; // rdx
  __int64 v23; // rdx
  int v24; // eax
  Scaleform::Render::TreeNode *v25; // r9
  __int64 v26; // r8
  unsigned __int64 v27; // rdx
  Scaleform::GFx::ASString *v28; // rax
  __int64 v29; // rsi
  Scaleform::GFx::ASStringNode *v30; // rcx
  unsigned __int64 v31; // r9
  __int64 v32; // r8
  __int64 v33; // rdx
  unsigned __int64 v34; // rdx
  __int64 v35; // [rsp+28h] [rbp-D8h]
  __int64 v36; // [rsp+30h] [rbp-D0h]
  __int64 v37; // [rsp+50h] [rbp-B0h]
  __int64 v38; // [rsp+60h] [rbp-A0h]
  __int64 v39; // [rsp+68h] [rbp-98h]
  __int64 v40; // [rsp+70h] [rbp-90h]
  Scaleform::GFx::ASString v41; // [rsp+78h] [rbp-88h]
  Scaleform::Render::TreeContainer *v42; // [rsp+80h] [rbp-80h]
  char *v43; // [rsp+88h] [rbp-78h]
  __int64 v44; // [rsp+90h] [rbp-70h]
  Scaleform::Render::Cxform v45; // [rsp+A0h] [rbp-60h]
  __int128 v46; // [rsp+C0h] [rbp-40h]
  char v47[20]; // [rsp+D0h] [rbp-30h]
  __int64 v48; // [rsp+E8h] [rbp-18h]
  int v49; // [rsp+F0h] [rbp-10h]
  __int64 v50; // [rsp+F8h] [rbp-8h]
  int v51; // [rsp+100h] [rbp+0h]
  __int16 v52; // [rsp+104h] [rbp+4h]
  Scaleform::Ptr<Scaleform::Render::TreeContainer> result; // [rsp+110h] [rbp+10h]
  __int64 v54; // [rsp+118h] [rbp+18h]
  Scaleform::GFx::InteractiveObject *v55; // [rsp+120h] [rbp+20h]
  __int64 v56; // [rsp+128h] [rbp+28h]
  __int64 v57; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::InteractiveObject **v58; // [rsp+138h] [rbp+38h]
  Scaleform::GFx::CharacterCreateInfo v59; // [rsp+140h] [rbp+40h]
  Scaleform::GFx::CharacterCreateInfo v60; // [rsp+158h] [rbp+58h]
  Scaleform::GFx::AS3::AvmButton *v61; // [rsp+1C0h] [rbp+C0h]
  unsigned __int8 v62; // [rsp+1C8h] [rbp+C8h]
  Scaleform::GFx::ResourceId rid; // [rsp+1D0h] [rbp+D0h]
  int v64; // [rsp+1D8h] [rbp+D8h]

  v61 = this;
  v54 = -2i64;
  v1 = (char *)this[-1].pClassName;
  v43 = v1;
  v44 = *((_QWORD *)v1 + 27);
  v2 = v44;
  v3 = Scaleform::GFx::Button::GetButtonState(*((Scaleform::GFx::ButtonRecord::MouseState *)v1 + 90));
  v39 = *(_QWORD *)(v44 + 40);
  v40 = v3;
  if ( v39 )
  {
    v4 = 0i64;
    v38 = 0i64;
    do
    {
      v5 = v4 + *(_QWORD *)(v2 + 32);
      v37 = v5;
      v6 = *(_BYTE *)(v5 + 84);
      v62 = *(_BYTE *)(v5 + 84);
      v7 = 1;
      do
      {
        if ( !((unsigned __int8)v7 & v6) )
          goto LABEL_78;
        LODWORD(v8) = 0;
        v9 = 0i64;
        if ( !(v7 & 8) )
        {
          if ( v7 & 2 )
          {
            v8 = 2i64;
LABEL_12:
            v9 = v8;
            goto LABEL_13;
          }
          if ( v7 & 4 )
          {
            v8 = 1i64;
            goto LABEL_12;
          }
          if ( v7 & 1 )
          {
            v8 = 3i64;
            goto LABEL_12;
          }
        }
LABEL_13:
        v10 = (Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&v1[32 * v9 + 232];
        v11 = *(_QWORD *)&v1[32 * (v9 + 7)];
        if ( v11 )
          ++*(_QWORD *)(v11 + 8);
        v42 = (Scaleform::Render::TreeContainer *)v11;
        if ( !v11 )
        {
          v12 = Scaleform::GFx::Button::CreateStateRenderContainer(
                  (Scaleform::GFx::Button *)v1,
                  &result,
                  (Scaleform::GFx::Button::ButtonState)v8);
          if ( v12->pObject )
            ++v12->pObject->RefCount;
          v11 = (unsigned __int64)v12->pObject;
          v42 = v12->pObject;
          v13 = result.pObject;
          if ( result.pObject )
          {
            v14 = result.pObject->RefCount-- == 1;
            if ( v14 )
              Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v13->0);
          }
        }
        if ( v10->Size )
        {
          v17 = 0i64;
          if ( (v10->Data->Char.pObject->Flags >> 10) & 1 )
            v17 = (Scaleform::GFx::InteractiveObject *)v10->Data->Char.pObject;
          if ( v17 )
            ++v17->RefCount;
        }
        else
        {
          rid.Id = 65537;
          Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
            *((Scaleform::GFx::MovieDefImpl **)v61[-1].pClassName + 22),
            &v59,
            (Scaleform::GFx::ResourceId)&rid);
          v15 = v61[-1].pClassName;
          v16 = *(_QWORD *)(*((_QWORD *)v15 + 4) + 24i64);
          v64 = *(_DWORD *)(v5 + 72);
          v17 = 0i64;
          v18 = (*(__int64 (__fastcall **)(__int64, _QWORD, Scaleform::GFx::CharacterCreateInfo *, _QWORD))(*(_QWORD *)v16 + 32i64))(
                  v16,
                  *(_QWORD *)(*((_QWORD *)v15 + 4) + 16i64),
                  &v59,
                  0i64);
          v19 = (Scaleform::GFx::DisplayObjectBase *)v18;
          v57 = v18;
          if ( (*(_WORD *)(v18 + 106) >> 10) & 1 )
            v17 = (Scaleform::GFx::InteractiveObject *)v18;
          if ( v17 )
            ++v17->RefCount;
          if ( v17 )
            ++v17->RefCount;
          v55 = v17;
          v56 = v37;
          Scaleform::ArrayDataBase<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
            v10,
            v10,
            v10->Size + 1);
          v20 = 16 * v10->Size;
          v21 = (signed __int64)&v10->Data[-1];
          v14 = v20 + v21 == 0;
          v22 = (Scaleform::GFx::InteractiveObject **)(v20 + v21);
          *(_QWORD *)&rid.Id = v22;
          v58 = v22;
          if ( !v14 )
          {
            if ( v17 )
              ++v17->RefCount;
            *v22 = v17;
            v22[1] = (Scaleform::GFx::InteractiveObject *)v37;
          }
          if ( v17 )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v17->vfptr);
          if ( !v17->pParent )
          {
            Scaleform::GFx::InteractiveObject::AddToPlayList(v17);
            if ( !((v17->Flags >> 21) & 1) || (v17->Flags >> 22) & 1 )
              v23 = 0i64;
            else
              LOBYTE(v23) = 1;
            v24 = (__int64)v17->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v17->vfptr, v23);
            if ( v24 == -1 )
            {
              v17->Flags |= 0x400000u;
            }
            else if ( v24 == 1 )
            {
              Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v17);
            }
          }
          v25 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v19);
          v26 = *(_QWORD *)(*(_QWORD *)((v11 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                          + 8
                          * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v11
                                                                                                - (v11 & 0xFFFFFFFFFFFFF000ui64)
                                                                                                - 56)
                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                           + ((unsigned __int64)((unsigned __int128)((signed __int64)(v11
                                                                                    - (v11 & 0xFFFFFFFFFFFFF000ui64)
                                                                                    - 56)
                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                          + 40);
          v27 = *(_QWORD *)(v26 + 144);
          if ( v27 )
          {
            if ( v27 & 1 )
              v27 = *(_QWORD *)((v27 & 0xFFFFFFFFFFFFFFFEui64) + 8);
            else
              v27 = (*(_QWORD *)(v26 + 152) != 0i64) + 1i64;
          }
          Scaleform::Render::TreeContainer::Insert((Scaleform::Render::TreeContainer *)v11, v27, v25);
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v19->vfptr);
          v1 = v43;
        }
        rid.Id = *(_DWORD *)(v37 + 72);
        Scaleform::GFx::MovieDefImpl::GetCharacterCreateInfo(
          *((Scaleform::GFx::MovieDefImpl **)v61[-1].pClassName + 22),
          &v60,
          (Scaleform::GFx::ResourceId)&rid);
        if ( v60.pCharDef )
        {
          Scaleform::Render::Cxform::Cxform(&v45);
          v46 = _xmm;
          *(__m128 *)v47 = _xmm;
          *(_QWORD *)&v47[16] = 0i64;
          v49 = 0x40000;
          v51 = 0;
          v48 = 0i64;
          v52 = 256;
          v50 = 0i64;
          *(_OWORD *)&v45.M[0][0] = *(_OWORD *)(v37 + 32);
          *(_OWORD *)&v45.M[1][0] = *(_OWORD *)(v37 + 48);
          v46 = *(_OWORD *)v37;
          *(_QWORD *)v47 = *(_QWORD *)(v37 + 16);
          *(_DWORD *)&v47[8] = *(_DWORD *)(v37 + 24);
          *(_QWORD *)&v47[12] = *(unsigned int *)(v37 + 28);
          v49 = *(_DWORD *)(v37 + 72);
          LOBYTE(v52) = *(_BYTE *)(v37 + 80);
          HIDWORD(v48) = *(unsigned __int16 *)(v37 + 76);
          HIWORD(v51) = 143;
          v28 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateEmptyString(
                  (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)(*((_QWORD *)v61[-1].pClassName + 4) + 360i64),
                  &v41);
          LODWORD(v36) = 4;
          LODWORD(v35) = 0;
          v29 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Cxform *, Scaleform::GFx::ASString *, _QWORD, _QWORD, __int64, __int64, _QWORD, _QWORD))v17->vfptr[118].__vecDelDtor)(
                  v17,
                  &v45,
                  v28,
                  0i64,
                  0i64,
                  v35,
                  v36,
                  0i64,
                  0i64);
          v30 = v41.pNode;
          v14 = v41.pNode->RefCount == 1;
          --v30->RefCount;
          if ( v14 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v30);
          if ( v29 && *(_QWORD *)(v37 + 64) )
            (*(void (__fastcall **)(__int64))(*(_QWORD *)v29 + 448i64))(v29);
          if ( v1[106] & 1 )
          {
            v17->Flags |= 1u;
            ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *))v17->vfptr[20].__vecDelDtor)(v17);
          }
          if ( *(_QWORD *)&v47[16] )
            Scaleform::RefCountImpl::Release(*(Scaleform::Render::RenderBuffer **)&v47[16]);
        }
        if ( (_DWORD)v8 == 3 )
          v17->pParent = (Scaleform::GFx::InteractiveObject *)v1;
        if ( v40 == v9 && !*(_QWORD *)(v11 + 32) )
        {
          v31 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v1 + 552i64))(v1);
          v32 = *(_QWORD *)(*(_QWORD *)((v31 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                          + 8
                          * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v31
                                                                                                - (v31 & 0xFFFFFFFFFFFFF000ui64)
                                                                                                - 56)
                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                           + ((unsigned __int64)((unsigned __int128)((signed __int64)(v31
                                                                                    - (v31 & 0xFFFFFFFFFFFFF000ui64)
                                                                                    - 56)
                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                          + 40);
          v33 = *(_QWORD *)(v32 + 144);
          if ( v33 )
          {
            if ( v33 & 1 )
              v34 = *(_QWORD *)((v33 & 0xFFFFFFFFFFFFFFFEui64) + 8);
            else
              v34 = (*(_QWORD *)(v32 + 152) != 0i64) + 1i64;
          }
          else
          {
            v34 = 0i64;
          }
          Scaleform::Render::TreeContainer::Insert(
            (Scaleform::Render::TreeContainer *)v31,
            v34,
            (Scaleform::Render::TreeNode *)v11);
        }
        if ( v17 )
          Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v17->vfptr);
        if ( v11 )
        {
          v14 = (*(_QWORD *)(v11 + 8))-- == 1i64;
          if ( v14 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)v11);
        }
        v5 = v37;
        v6 = v62;
LABEL_78:
        v7 *= 2;
      }
      while ( v7 & 0xF );
      v4 = v38 + 96;
      v38 += 96i64;
      v14 = v39-- == 1;
      v2 = v44;
    }
    while ( !v14 );
  }
}

// File Line: 276
// RVA: 0x8254B0
void __fastcall Scaleform::GFx::AS3::AvmButton::SwitchState(Scaleform::GFx::AS3::AvmButton *this, Scaleform::GFx::ButtonRecord::MouseState mouseState)
{
  const char *v2; // r8
  Scaleform::GFx::AS3::AvmButton *v3; // rbx
  __int16 v4; // r9
  Scaleform::GFx::Button::ButtonState v5; // eax

  v2 = this[-1].pClassName;
  v3 = this;
  v4 = *((_WORD *)v2 + 53);
  if ( !(((unsigned __int8)v4 >> 4) & 1) && !(v4 & 0x1000) && *((_DWORD *)v2 + 11) >= -1 )
  {
    v5 = Scaleform::GFx::Button::GetButtonState(mouseState);
    Scaleform::GFx::AS3::AvmButton::SwitchStateIntl((Scaleform::GFx::AS3::AvmButton *)((char *)v3 - 72), v5);
  }
}

// File Line: 286
// RVA: 0x825500
void __fastcall Scaleform::GFx::AS3::AvmButton::SwitchStateIntl(Scaleform::GFx::AS3::AvmButton *this, Scaleform::GFx::Button::ButtonState bs)
{
  __int64 v2; // rbp
  Scaleform::GFx::DisplayObject *v3; // r12
  unsigned __int16 v4; // cx
  Scaleform::Render::TreeContainer *v5; // rax
  Scaleform::Render::TreeContainer *v6; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v7; // rbx
  unsigned int v8; // esi
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType **v9; // r14
  long double v10; // rdi
  long double v11; // r15
  __int64 v12; // rcx
  signed __int64 v13; // rcx
  signed __int64 v14; // rcx
  __int64 v15; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v16; // rcx
  Scaleform::GFx::DisplayObjectBase **v17; // rax
  Scaleform::GFx::DisplayObjectBase *v18; // rdi
  Scaleform::GFx::DisplayObjectBase *v19; // r14
  Scaleform::Render::TreeContainer *v20; // rbp
  Scaleform::GFx::InteractiveObject *v21; // rax
  Scaleform::GFx::InteractiveObject *v22; // rcx
  signed __int64 v23; // rcx
  Scaleform::Render::TreeNode *v24; // rax
  signed __int64 v25; // rcx
  __int64 v26; // rax
  Scaleform::GFx::AS3::AvmInteractiveObj *v27; // rcx
  __int64 v28; // rsi
  _WORD *v29; // rdi
  Scaleform::Render::TreeContainer *v30; // rax
  bool v31; // zf

  v2 = bs;
  v3 = this->pDispObj;
  v4 = v3->Flags;
  if ( !(((unsigned __int8)v4 >> 4) & 1) && !(v4 & 0x1000) && v3->Depth >= -1 )
  {
    v5 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v3->vfptr[69].__vecDelDtor)(v3);
    if ( Scaleform::Render::TreeContainer::GetSize(v5) )
    {
      v6 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v3->vfptr[69].__vecDelDtor)(v3);
      Scaleform::Render::TreeContainer::Remove(v6, 0i64, 1ui64);
    }
    v7 = 0i64;
    v8 = 0;
    v9 = &v3[1].pPerspectiveData;
    do
    {
      if ( (unsigned __int64)v9[1] > 0 )
      {
        v10 = 0.0;
        if ( *(_BYTE *)(*(_QWORD *)&(*v9)->FieldOfView + 107i64) & 1 )
          v10 = (*v9)->FieldOfView;
        v11 = 0.0;
        if ( (*(_WORD *)(*(_QWORD *)&v10 + 106i64) >> 9) & 1 )
          v11 = v10;
        if ( v8 != (_DWORD)v2 )
        {
          v12 = *(_QWORD *)(*(_QWORD *)&v10 + 56i64);
          if ( v12 )
          {
            v13 = v12 + 4i64 * *(unsigned __int8 *)(v12 + 109);
            (*(void (__fastcall **)(signed __int64, long double))(*(_QWORD *)v13 + 168i64))(
              v13,
              COERCE_LONG_DOUBLE(*(_QWORD *)&v10));
            *(_QWORD *)(*(_QWORD *)&v10 + 56i64) = 0i64;
            if ( v11 != 0.0 )
            {
              v14 = *(_QWORD *)&v11 + 4i64 * *(unsigned __int8 *)(*(_QWORD *)&v11 + 109i64);
              v15 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v14 + 8i64))(v14);
              v16 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v15 - 56);
              if ( !v15 )
                v16 = 0i64;
              Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v16);
            }
          }
        }
      }
      ++v8;
      v9 += 4;
    }
    while ( v8 < 3 );
    if ( *((_QWORD *)&v3[1].pIndXFormData + 4 * v2) > 0ui64 )
    {
      v17 = (Scaleform::GFx::DisplayObjectBase **)*((_QWORD *)&v3[1].pPerspectiveData + 4 * v2);
      v18 = 0i64;
      if ( (*v17)->Flags & 0x100 )
        v18 = *v17;
      v19 = 0i64;
      if ( (v18->Flags >> 9) & 1 )
        v19 = v18;
      v20 = (Scaleform::Render::TreeContainer *)(&v3->vfptr)[4 * (v2 + 7)];
      if ( v20 )
        ++v20->RefCount;
      v21 = v18->pParent;
      if ( v21
        && (v21 != (Scaleform::GFx::InteractiveObject *)v3
         || (Scaleform::Render::TreeContainer *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v18)->pParent != v20) )
      {
        v22 = v18->pParent;
        if ( v22 )
          v23 = (signed __int64)v22 + 4 * (unsigned __int8)v22->AvmObjOffset;
        else
          v23 = 0i64;
        (*(void (__fastcall **)(signed __int64, Scaleform::GFx::DisplayObjectBase *))(*(_QWORD *)v23 + 168i64))(
          v23,
          v18);
      }
      if ( !Scaleform::GFx::DisplayObjectBase::GetRenderNode(v18)->pParent )
      {
        v24 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v18);
        Scaleform::Render::TreeContainer::Add(v20, v24);
      }
      if ( !v18->pParent )
      {
        v18->pParent = (Scaleform::GFx::InteractiveObject *)v3;
        if ( v19 )
        {
          v25 = (signed __int64)v19 + 4 * (unsigned __int8)v19->AvmObjOffset;
          v26 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v25 + 8i64))(v25);
          v27 = (Scaleform::GFx::AS3::AvmInteractiveObj *)(v26 - 56);
          if ( !v26 )
            v27 = 0i64;
          Scaleform::GFx::AS3::AvmInteractiveObj::MoveBranchInPlayList(v27);
          if ( v19[2].vfptr )
          {
            v28 = 0i64;
            do
            {
              v29 = *(_WORD **)(v28 + *(_QWORD *)&v19[1].ClipDepth);
              if ( (v29[53] >> 10) & 1 )
              {
                (*(void (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)v29 + 880i64))(
                  *(_QWORD *)(v28 + *(_QWORD *)&v19[1].ClipDepth),
                  0i64);
                (*(void (__fastcall **)(_WORD *, _QWORD))(*(_QWORD *)v29 + 912i64))(v29, 0i64);
              }
              v7 = (Scaleform::RefCountNTSImplCoreVtbl *)((char *)v7 + 1);
              v28 += 16i64;
            }
            while ( v7 < v19[2].vfptr );
          }
        }
      }
      v30 = (Scaleform::Render::TreeContainer *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObject *))v3->vfptr[69].__vecDelDtor)(v3);
      Scaleform::Render::TreeContainer::Add(v30, (Scaleform::Render::TreeNode *)&v20->0);
      if ( v20 )
      {
        v31 = v20->RefCount-- == 1;
        if ( v31 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v20->0);
      }
    }
  }
}

// File Line: 389
// RVA: 0x7C4790
__int64 __fastcall Scaleform::GFx::AS3::AvmButton::DetachChild(Scaleform::GFx::AS3::AvmButton *this, Scaleform::GFx::DisplayObjectBase *child)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbp
  unsigned __int8 v3; // bl
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType **v4; // rsi
  signed __int64 v5; // r14
  Scaleform::Render::ContextImpl::Entry *v6; // rax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v7; // rdi
  __int64 v8; // r13
  Scaleform::Render::TreeContainer *v9; // r12
  unsigned __int64 v10; // rdi
  __int64 v11; // r8
  __int64 v12; // rsi
  unsigned __int64 v13; // rsi
  _QWORD *v14; // rax
  Scaleform::Render::TreeNode *v15; // rbx
  bool v16; // zf
  Scaleform::Render::ContextImpl::Entry *v18; // [rsp+20h] [rbp-58h]
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v19; // [rsp+80h] [rbp+8h]
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType **v20; // [rsp+90h] [rbp+18h]
  signed __int64 v21; // [rsp+98h] [rbp+20h]

  v2 = child;
  v3 = 0;
  v4 = &this->pDispObj[1].pIndXFormData;
  v20 = &this->pDispObj[1].pIndXFormData;
  v5 = 3i64;
  v21 = 3i64;
  do
  {
    v6 = (Scaleform::Render::ContextImpl::Entry *)*(v4 - 2);
    v18 = v6;
    if ( v6 )
      ++v6->RefCount;
    v7 = *v4;
    v19 = *v4;
    if ( *v4 )
    {
      v8 = 0i64;
      do
      {
        if ( *(Scaleform::GFx::DisplayObjectBase **)&(*(v4 - 1))->OrigTransformMatrix.M[v8][0] == v2 )
        {
          v2->pParent = 0i64;
          if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(v2) )
          {
            v9 = (Scaleform::Render::TreeContainer *)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v2)->pParent;
            if ( v9 )
            {
              v10 = 0i64;
              v11 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v9 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                              + 8
                              * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v9[-1]
                                                                                        - ((unsigned __int64)v9 & 0xFFFFFFFFFFFFF000ui64))
                                                                       * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                               + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v9[-1] - ((unsigned __int64)v9 & 0xFFFFFFFFFFFFF000ui64))
                                                                                   * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                              + 40);
              v12 = *(_QWORD *)(v11 + 144);
              if ( v12 )
              {
                v13 = v12 & 1 ? *(_QWORD *)((v12 & 0xFFFFFFFFFFFFFFFEui64) + 8) : (*(_QWORD *)(v11 + 152) != 0i64)
                                                                                + 1i64;
                if ( v13 )
                {
                  while ( 1 )
                  {
                    v14 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v9 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                               + 8
                                               * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v9[-1] - ((unsigned __int64)v9 & 0xFFFFFFFFFFFFF000ui64))
                                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                                + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v9[-1] - ((unsigned __int64)v9 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                               + 40)
                                   + 144i64);
                    if ( *(_BYTE *)v14 & 1 )
                      v14 = (_QWORD *)((*v14 & 0xFFFFFFFFFFFFFFFEui64) + 16);
                    v15 = (Scaleform::Render::TreeNode *)v14[v10];
                    if ( v15 == Scaleform::GFx::DisplayObjectBase::GetRenderNode(v2) )
                      break;
                    if ( ++v10 >= v13 )
                      goto LABEL_20;
                  }
                  Scaleform::Render::TreeContainer::Remove(v9, v10, 1ui64);
                }
              }
LABEL_20:
              v4 = v20;
              v7 = v19;
            }
          }
          v3 = 1;
        }
        ++v8;
        v7 = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)((char *)v7 - 1);
        v19 = v7;
      }
      while ( v7 );
      v6 = v18;
      v5 = v21;
    }
    if ( v6 )
    {
      v16 = v6->RefCount-- == 1;
      if ( v16 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
    }
    v4 += 4;
    v20 = v4;
    v21 = --v5;
  }
  while ( v5 );
  return v3;
}

// File Line: 429
// RVA: 0x81E7C0
void __fastcall Scaleform::GFx::AS3::AvmButton::SetStateObject(Scaleform::GFx::AS3::AvmButton *this, Scaleform::GFx::Button::ButtonState state, Scaleform::GFx::DisplayObject *ch)
{
  Scaleform::GFx::DisplayObject *v3; // rdi
  __int64 v4; // rsi
  Scaleform::GFx::AS3::AvmButton *v5; // r14
  Scaleform::GFx::Button *v6; // rbp
  Scaleform::Render::TreeContainer *v7; // rbx
  Scaleform::Ptr<Scaleform::Render::TreeContainer> *v8; // rax
  Scaleform::Render::TreeContainer *v9; // rcx
  bool v10; // zf
  signed __int64 v11; // rax
  Scaleform::GFx::Button *v12; // rax
  unsigned __int8 *v13; // rcx
  Scaleform::Render::TreeNode *v14; // rax
  Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *v15; // rcx
  Scaleform::RefCountNTSImpl **v16; // rbx
  Scaleform::Ptr<Scaleform::Render::TreeContainer> result; // [rsp+60h] [rbp+18h]

  v3 = ch;
  v4 = state;
  v5 = this;
  v6 = (Scaleform::GFx::Button *)this->pDispObj;
  if ( state != 3 )
  {
    v7 = (Scaleform::Render::TreeContainer *)(&v6->vfptr)[4 * ((signed int)state + 7i64)];
    if ( v7 )
      ++v7->RefCount;
    if ( v7 )
    {
      v11 = Scaleform::Render::TreeContainer::GetSize(v7);
      Scaleform::Render::TreeContainer::Remove(v7, 0i64, v11);
    }
    else
    {
      v8 = Scaleform::GFx::Button::CreateStateRenderContainer(v6, &result, state);
      if ( v8->pObject )
        ++v8->pObject->RefCount;
      v7 = v8->pObject;
      v9 = result.pObject;
      if ( result.pObject )
      {
        v10 = result.pObject->RefCount-- == 1;
        if ( v10 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v9->0);
      }
    }
    v12 = (Scaleform::GFx::Button *)v3->pParent;
    if ( v12
      && (v12 != v6
       || (Scaleform::Render::TreeContainer *)Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr)->pParent != v7) )
    {
      v13 = (unsigned __int8 *)v3->pParent;
      if ( v13 )
        v13 += 4 * v13[109];
      if ( (*(unsigned __int8 (__fastcall **)(unsigned __int8 *, Scaleform::GFx::DisplayObject *))(*(_QWORD *)v13
                                                                                                 + 168i64))(
             v13,
             v3) )
      {
        v3->pParent = (Scaleform::GFx::InteractiveObject *)&v6->vfptr;
      }
    }
    if ( !Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr)->pParent )
    {
      v14 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
      Scaleform::Render::TreeContainer::Add(v7, v14);
    }
    if ( v7 )
    {
      v10 = v7->RefCount-- == 1;
      if ( v10 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v7->0);
    }
  }
  v15 = &v6->States[v4].Characters.Data;
  if ( v3 )
  {
    Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      v15,
      1ui64);
    v16 = (Scaleform::RefCountNTSImpl **)v6->States[v4].Characters.Data.Data;
    ++v3->RefCount;
    if ( *v16 )
      Scaleform::RefCountNTSImpl::Release(*v16);
    *v16 = (Scaleform::RefCountNTSImpl *)&v3->vfptr;
  }
  else
  {
    Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      v15,
      0i64);
  }
  if ( Scaleform::GFx::Button::GetButtonState(v6->MouseState) == (_DWORD)v4 )
    Scaleform::GFx::AS3::AvmButton::SwitchStateIntl(v5, (Scaleform::GFx::Button::ButtonState)v4);
}

// File Line: 525
// RVA: 0x819970
void __fastcall Scaleform::GFx::AS3::AvmButton::SetHitStateObject(Scaleform::GFx::AS3::AvmButton *this, Scaleform::GFx::DisplayObject *ch)
{
  Scaleform::GFx::DisplayObject *v2; // rbp
  Scaleform::GFx::AS3::AvmButton *v3; // rsi
  Scaleform::GFx::DisplayObject *v4; // rbx
  Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *v5; // rcx
  Scaleform::RefCountNTSImpl **v6; // rdi

  v2 = this->pDispObj;
  v3 = this;
  v4 = ch;
  v5 = (Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy> *)&v2[2].Id;
  if ( ch )
  {
    Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      v5,
      1ui64);
    v6 = *(Scaleform::RefCountNTSImpl ***)&v2[2].Id.Id;
    ++v4->RefCount;
    if ( *v6 )
      Scaleform::RefCountNTSImpl::Release(*v6);
    *v6 = (Scaleform::RefCountNTSImpl *)&v4->vfptr;
  }
  else
  {
    Scaleform::ArrayData<Scaleform::GFx::Button::CharToRec,Scaleform::AllocatorLH<Scaleform::GFx::Button::CharToRec,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      v5,
      0i64);
  }
  if ( Scaleform::GFx::Button::GetButtonState((Scaleform::GFx::ButtonRecord::MouseState)v2[2].pRenNode.pObject) == 3 )
    Scaleform::GFx::AS3::AvmButton::SwitchStateIntl(v3, Hit);
}

