// File Line: 34
// RVA: 0x6C7850
void __fastcall Scaleform::GFx::AS2::AvmTextField::AvmTextField(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::TextField *ptf)
{
  Scaleform::GFx::TextFieldDef *pObject; // rbx
  Scaleform::GFx::ASStringManager *StringManager; // rax
  Scaleform::GFx::AS2::Environment *v6; // rdx
  Scaleform::GFx::InteractiveObject *pParent; // rax
  char *v8; // rcx
  Scaleform::GFx::AS2::Object *ActualPrototype; // rax
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::Object *v11; // rcx
  unsigned int RefCount; // eax
  char *v13; // rcx
  __int64 v14; // rax
  char *v15; // rcx
  Scaleform::GFx::AS2::Environment *v16; // rax

  Scaleform::GFx::AS2::AvmCharacter::AvmCharacter(this, ptf);
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmTextFieldBase::`vftable;
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmTextField::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmTextField::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmTextField::`vftable;
  pObject = ptf->pDef.pObject;
  StringManager = Scaleform::GFx::InteractiveObject::GetStringManager(ptf);
  Scaleform::GFx::ASStringManager::CreateString(StringManager, &this->VariableName, &pObject->VariableName);
  this->VariableVal.T.Type = 0;
  v6 = 0i64;
  this->ASTextFieldObj.pObject = 0i64;
  if ( this->VariableName.pNode->Size )
    ptf->Flags |= 0x8000u;
  pParent = this->pDispObj->pParent;
  if ( pParent )
  {
    while ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) == 0 )
    {
      pParent = pParent->pParent;
      if ( !pParent )
        goto LABEL_8;
    }
    v8 = (char *)pParent + 4 * (unsigned __int8)pParent->AvmObjOffset;
    v6 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v8 + 240i64))(v8);
  }
LABEL_8:
  ActualPrototype = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
                      (Scaleform::GFx::AS2::GlobalContext *)this->pDispObj->pASRoot[2].vfptr,
                      v6,
                      ASBuiltin_TextField);
  v10 = ActualPrototype;
  if ( ActualPrototype )
    ActualPrototype->RefCount = (ActualPrototype->RefCount + 1) & 0x8FFFFFFF;
  v11 = this->pProto.pObject;
  if ( v11 )
  {
    RefCount = v11->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v11->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  this->pProto.pObject = v10;
  v13 = (char *)ptf + 4 * (unsigned __int8)ptf->AvmObjOffset;
  v14 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v13 + 240i64))(v13);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    (Scaleform::GFx::AS2::ASStringContext *)(v14 + 232),
    &this->Scaleform::GFx::AS2::ObjectInterface);
  v15 = (char *)ptf + 4 * (unsigned __int8)ptf->AvmObjOffset;
  v16 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(char *))(*(_QWORD *)v15 + 240i64))(v15);
  Scaleform::GFx::AS2::AsBroadcaster::AddListener(
    v16,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    &this->Scaleform::GFx::AS2::ObjectInterface);
}

// File Line: 52
// RVA: 0x6EE330
// attributes: thunk
Scaleform::GFx::AS2::TextFieldObject *__fastcall Scaleform::GFx::AS2::AvmTextField::GetASObject(
        Scaleform::GFx::AS2::AvmTextField *this)
{
  return Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(this);
}

// File Line: 69
// RVA: 0x6F6840
Scaleform::GFx::AS2::TextFieldObject *__fastcall Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(
        Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::TextFieldObject *v2; // rdi
  Scaleform::GFx::AS2::GlobalContext *v3; // rax
  Scaleform::GFx::AS2::TextFieldObject *v4; // rax
  Scaleform::GFx::AS2::TextFieldObject *v5; // rdi
  Scaleform::GFx::AS2::TextFieldObject *pObject; // rcx
  unsigned int RefCount; // eax
  int v9; // [rsp+48h] [rbp+10h] BYREF
  Scaleform::GFx::AS2::TextFieldObject *v10; // [rsp+50h] [rbp+18h]

  if ( this->ASTextFieldObj.pObject )
    return this->ASTextFieldObj.pObject;
  v9 = 323;
  v2 = (Scaleform::GFx::AS2::TextFieldObject *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::AvmTextField *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 112i64,
                                                 &v9,
                                                 -2i64);
  v10 = v2;
  if ( v2 )
  {
    v3 = (Scaleform::GFx::AS2::GlobalContext *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmTextField *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[1].OnUnloading)(this);
    Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(v2, v3, this->pDispObj);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  pObject = this->ASTextFieldObj.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->ASTextFieldObj.pObject = v5;
  return v5;
}

// File Line: 102
// RVA: 0x7069C0
char __fastcall Scaleform::GFx::AS2::AvmTextField::OnMouseEvent(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::EventId *event)
{
  Scaleform::GFx::TextField *v3; // rbx
  unsigned __int64 CharIndexAtPoint; // rax
  unsigned __int64 v5; // rbx
  __int64 v6; // r14
  const char *v7; // rbx
  char *v8; // rdi
  int v9; // r15d
  __int64 v10; // rbx
  __int64 v11; // rdx
  char v13[16]; // [rsp+40h] [rbp-39h] BYREF
  __int64 v14; // [rsp+50h] [rbp-29h]
  int v15; // [rsp+58h] [rbp-21h]
  char *v16; // [rsp+60h] [rbp-19h]
  char v17[16]; // [rsp+70h] [rbp-9h] BYREF
  __int64 v18; // [rsp+80h] [rbp+7h]
  int v19; // [rsp+88h] [rbp+Fh]
  __int64 v20; // [rsp+90h] [rbp+17h]
  Scaleform::String v21; // [rsp+E8h] [rbp+6Fh] BYREF
  Scaleform::Render::Point<float> pPnt; // [rsp+F0h] [rbp+77h] BYREF
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+F8h] [rbp+7Fh] BYREF

  if ( event->Id != 2048 )
    return 0;
  v3 = (Scaleform::GFx::TextField *)*((_QWORD *)&this[-1].VariableVal.NV + 3);
  if ( (v3->Flags & 2) != 0
    && (v3->pDocument.pObject->pDocument.pObject->RTFlags & 1) != 0
    && Scaleform::GFx::TextField::IsUrlUnderMouseCursor(v3, event->ControllerIndex, &pPnt, 0i64) )
  {
    CharIndexAtPoint = Scaleform::Render::Text::DocView::GetCharIndexAtPoint(v3->pDocument.pObject, pPnt.x, pPnt.y);
    if ( CharIndexAtPoint != -1i64
      && Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
           v3->pDocument.pObject->pDocument.pObject,
           &ppdestTextFmt,
           0i64,
           CharIndexAtPoint)
      && Scaleform::Render::Text::TextFormat::IsUrlSet(ppdestTextFmt) )
    {
      v5 = ppdestTextFmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
      v6 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)&this[-1].VariableVal.NV + 3) + 32i64) + 16i64);
      if ( v6 )
      {
        if ( !Scaleform::String::CompareNoCase((const char *)(v5 + 12), "asfunction:", 11i64) )
        {
          v7 = (const char *)(v5 + 23);
          v8 = strchr(v7, 44);
          Scaleform::String::String(&v21);
          v14 = 0i64;
          v15 = 0;
          v9 = 0;
          if ( v8 )
          {
            Scaleform::String::AppendString(&v21, v7, v8 - v7);
            v9 = 1;
            v15 = 6;
            v16 = v8 + 1;
          }
          else
          {
            Scaleform::String::operator=(&v21, v7);
          }
          v18 = 0i64;
          v19 = 0;
          v10 = *(_QWORD *)(*((_QWORD *)&this[-1].VariableVal.NV + 3) + 56i64);
          if ( v10 )
            ++*(_DWORD *)(v10 + 8);
          if ( !v10 )
            goto LABEL_20;
          v11 = 0i64;
          if ( (*(_WORD *)(v10 + 106) & 0x400) != 0 )
            v11 = v10;
          if ( v11 )
            (*(void (__fastcall **)(_QWORD, __int64, unsigned __int64, char *, char *, int, __int64, __int64))(**(_QWORD **)(v6 + 24) + 488i64))(
              *(_QWORD *)(v6 + 24),
              v11,
              (v21.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
              v17,
              v13,
              v9,
              -2i64,
              v10);
          else
LABEL_20:
            (*(void (__fastcall **)(_QWORD, unsigned __int64, char *, char *, int))(**(_QWORD **)(v6 + 24) + 448i64))(
              *(_QWORD *)(v6 + 24),
              (v21.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
              v17,
              v13,
              v9);
          if ( v10 )
            Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v10);
          if ( (v19 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v18 + 16i64))(v18, v17, v20);
            v18 = 0i64;
          }
          v19 = 0;
          if ( (v15 & 0x40) != 0 )
          {
            (*(void (__fastcall **)(__int64, char *, char *))(*(_QWORD *)v14 + 16i64))(v14, v13, v16);
            v14 = 0i64;
          }
          v15 = 0;
          if ( !_InterlockedDecrement((volatile signed __int32 *)((v21.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
      }
    }
  }
  return 1;
}

// File Line: 187
// RVA: 0x705D80
void __fastcall Scaleform::GFx::AS2::AvmTextField::OnEventLoad(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::TextField *pDispObj; // rdi
  Scaleform::GFx::AS2::Environment *v3; // rax
  bool Variable; // si
  Scaleform::GFx::AS2::Value presult; // [rsp+48h] [rbp-30h] BYREF

  pDispObj = (Scaleform::GFx::TextField *)this->pDispObj;
  if ( Scaleform::String::GetLength(&pDispObj->pDef.pObject->DefaultText) )
  {
    if ( !this->VariableName.pNode->Size )
      goto LABEL_7;
    pDispObj->Flags |= 0x8000u;
    v3 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmTextField *))this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].GetAbsolutePath)(this);
    if ( !v3 )
      goto LABEL_7;
    presult.T.Type = 0;
    Variable = Scaleform::GFx::AS2::Environment::GetVariable(v3, &this->VariableName, &presult, 0i64);
    if ( presult.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&presult);
    if ( !Variable )
    {
LABEL_7:
      Scaleform::GFx::TextField::SetTextValue(
        pDispObj,
        (const char *)(((unsigned __int64)this->pDispObj[1].Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[14].__vecDelDtor & 0xFFFFFFFFFFFFFFFCui64)
                     + 12),
        (pDispObj->Flags & 2) != 0,
        1);
      ((void (__fastcall *)(Scaleform::GFx::AvmTextFieldBase *))this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].OnEvent)(&this->Scaleform::GFx::AvmTextFieldBase);
    }
  }
  else
  {
    Scaleform::GFx::TextField::SetTextValue(pDispObj, &customCaption, (pDispObj->Flags & 2) != 0, 0);
  }
  ((void (__fastcall *)(Scaleform::GFx::AvmTextFieldBase *))this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].HasEventHandler)(&this->Scaleform::GFx::AvmTextFieldBase);
}

// File Line: 227
// RVA: 0x723080
char __fastcall Scaleform::GFx::AS2::AvmTextField::UpdateTextFromVariable(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::TextField *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // rsi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value presult; // [rsp+48h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h] BYREF

  if ( LODWORD(this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMember) )
  {
    v2 = (Scaleform::GFx::TextField *)*((_QWORD *)&this[-1].VariableVal.NV + 3);
    v2->Flags |= 0x8000u;
    v3 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::Value *))(*(_QWORD *)&this[-1].VariableVal.T.Type + 240i64))(&this[-1].VariableVal);
    if ( v3 )
    {
      presult.T.Type = 0;
      if ( Scaleform::GFx::AS2::Environment::GetVariable(
             v3,
             (Scaleform::GFx::ASString *)&this->Scaleform::GFx::AS2::ObjectInterface,
             &presult,
             0i64) )
      {
        if ( !Scaleform::GFx::AS2::Value::IsEqual(&presult, v3, (Scaleform::GFx::AS2::Value *)&this->pProto) )
        {
          Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&this->pProto, &presult);
          Scaleform::GFx::AS2::Value::ToString(&presult, &result, v3, -1);
          Scaleform::GFx::TextField::SetTextValue(v2, result.pNode->pData, 0, 0);
          pNode = result.pNode;
          if ( result.pNode->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          if ( presult.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&presult);
          return 1;
        }
      }
      else
      {
        Scaleform::GFx::TextField::SetTextValue(v2, &customCaption, 0, 0);
      }
      if ( presult.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&presult);
    }
    return 0;
  }
  return 1;
}

// File Line: 261
// RVA: 0x6F63A0
__int64 __fastcall Scaleform::GFx::AS2::AvmTextField::GetStandardMemberBitMask(Scaleform::GFx::AS2::AvmTextField *this)
{
  return 1652404175i64;
}

// File Line: 280
// RVA: 0x722F10
void __fastcall Scaleform::GFx::AS2::AvmTextField::UpdateAutosizeSettings(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::InteractiveObject *pDispObj; // rbx
  char v2; // di

  pDispObj = this->pDispObj;
  v2 = BYTE4(pDispObj[1].pASRoot) & 1;
  if ( v2 && (*(_BYTE *)(*(_QWORD *)&pDispObj[1].RefCount + 344i64) & 8) == 0 )
    Scaleform::Render::Text::DocView::SetAutoSizeX(*(Scaleform::Render::Text::DocView **)&pDispObj[1].RefCount);
  else
    *(_BYTE *)(*(_QWORD *)&pDispObj[1].RefCount + 344i64) &= ~1u;
  if ( v2 )
    Scaleform::Render::Text::DocView::SetAutoSizeY(*(Scaleform::Render::Text::DocView **)&pDispObj[1].RefCount);
  else
    *(_BYTE *)(*(_QWORD *)&pDispObj[1].RefCount + 344i64) &= ~2u;
  HIDWORD(pDispObj[1].pASRoot) |= 0x2000u;
  Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)pDispObj);
}

// File Line: 296
// RVA: 0x715A60
_BOOL8 __fastcall Scaleform::GFx::AS2::AvmTextField::SetMember(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASStringNode *name,
        Scaleform::GFx::AS2::Value *origVal)
{
  unsigned int StandardMemberConstant; // ebx
  Scaleform::GFx::TextField *pObject; // rdi
  unsigned int v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int Version; // eax
  unsigned int v13; // eax
  bool v14; // al
  const char *pData; // rdx
  Scaleform::Render::Text::DocView *v16; // r8
  int v17; // r10d
  char v18; // r9
  unsigned __int64 v19; // rax
  __int64 v20; // rsi
  __int64 v21; // rdx
  char v22; // cl
  __int64 v23; // rdx
  char v24; // cl
  __int64 v25; // rdx
  char v26; // cl
  char v27; // cl
  char v28; // bl
  char v29; // al
  Scaleform::Render::Text::DocView *v30; // rcx
  char v31; // bl
  char v32; // al
  Scaleform::Render::Text::DocView *v33; // rax
  Scaleform::GFx::ASString *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  bool v36; // al
  Scaleform::Render::Text::DocView *v37; // rax
  char v38; // bl
  char v39; // al
  Scaleform::Render::Text::DocView *v40; // rax
  int v41; // eax
  int v42; // eax
  bool v43; // al
  bool v44; // al
  long double v45; // xmm0_8
  unsigned int v46; // eax
  long double v47; // xmm0_8
  unsigned int v48; // eax
  Scaleform::GFx::ASString *v49; // rax
  Scaleform::GFx::ASString *v50; // rbx
  bool v51; // zf
  Scaleform::GFx::ASStringNode *v52; // rax
  bool v53; // bl
  Scaleform::GFx::ASStringNode *v54; // rcx
  Scaleform::Render::Text::DocView *v55; // rax
  Scaleform::GFx::ASString *v56; // rax
  Scaleform::GFx::ASString *v57; // rbx
  bool v58; // zf
  Scaleform::GFx::ASStringNode *v59; // rax
  bool v60; // bl
  Scaleform::GFx::ASStringNode *v61; // rcx
  Scaleform::GFx::Text::EditorKit *v62; // rbx
  long double v63; // xmm6_8
  Scaleform::GFx::ASString *v64; // rax
  Scaleform::GFx::ASString *v65; // rbx
  bool v66; // zf
  Scaleform::GFx::ASStringNode *v67; // rax
  bool v68; // bl
  Scaleform::GFx::ASStringNode *v69; // rcx
  Scaleform::GFx::ASString *v70; // rax
  Scaleform::GFx::ASString *v71; // rbx
  bool v72; // zf
  Scaleform::GFx::ASStringNode *v73; // rax
  bool v74; // bl
  Scaleform::GFx::ASStringNode *v75; // rcx
  unsigned int v76; // eax
  Scaleform::GFx::AS2::Environment *v77; // rax
  Scaleform::GFx::AS2::Environment *v78; // rax
  Scaleform::Render::Text::DocView *v79; // rax
  float v80; // xmm0_4
  float v81; // xmm0_4
  float v82; // xmm1_4
  float v83; // xmm1_4
  bool v84; // al
  Scaleform::Render::Text::DocView *v85; // rcx
  bool v86; // al
  Scaleform::Render::Text::DocView *v87; // rcx
  float v88; // xmm1_4
  float v89; // xmm1_4
  float v90; // xmm1_4
  float *v91; // rbx
  float v92; // xmm6_4
  float v93; // xmm8_4
  float v94; // xmm0_4
  float v95; // xmm0_4
  float v96; // xmm1_4
  bool v97; // al
  Scaleform::Render::Text::DocView *v98; // rcx
  bool v99; // al
  Scaleform::Render::Text::DocView *v100; // rcx
  unsigned int v101; // eax
  Scaleform::Render::Text::DocView *v102; // rcx
  float v103; // xmm1_4
  __int64 v104; // rsi
  __int64 v105; // rdx
  char v106; // cl
  Scaleform::Render::Text::DocView *v107; // rax
  unsigned __int64 v108; // rax
  __int64 v109; // rdx
  char v110; // cl
  __int64 v111; // rdx
  char v112; // cl
  char v113; // cl
  double v114; // xmm0_8
  float v115; // xmm1_4
  unsigned __int64 v116; // rax
  __int64 v117; // rsi
  __int64 v118; // rdx
  char v119; // cl
  Scaleform::Render::Text::DocView *v120; // rax
  __int64 v121; // rdx
  char v122; // cl
  __int64 v123; // rdx
  char v124; // cl
  char v125; // cl
  unsigned __int64 v126; // rax
  __int64 v127; // rsi
  __int64 v128; // rdx
  char v129; // cl
  Scaleform::Render::Text::DocView *v130; // rax
  __int64 v131; // rdx
  char v132; // cl
  char v133; // cl
  Scaleform::GFx::AS2::Environment *v134; // rax
  Scaleform::Render::Text::DocView *v135; // rcx
  Scaleform::Render::Text::EditorKitBase *v136; // rax
  Scaleform::GFx::AS2::Environment *v137; // rax
  Scaleform::Render::Text::DocView *v138; // rbx
  Scaleform::GFx::Text::EditorKit *v139; // rbx
  Scaleform::Render::Text::DocView *v140; // rbx
  Scaleform::GFx::Text::EditorKit *v141; // rbx
  Scaleform::Render::Text::DocView *v142; // rbx
  Scaleform::GFx::Text::EditorKit *v143; // rbx
  Scaleform::Render::Text::DocView *v144; // rbx
  Scaleform::GFx::Text::EditorKit *v145; // rbx
  Scaleform::GFx::ASString *v146; // rax
  Scaleform::GFx::ASStringNode *v147; // rcx
  bool v148; // bl
  Scaleform::GFx::AS2::Value newVal; // [rsp+30h] [rbp-A8h] BYREF
  Scaleform::GFx::ASString v151; // [rsp+50h] [rbp-88h] BYREF
  Scaleform::GFx::ASString v152; // [rsp+58h] [rbp-80h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp-78h] BYREF
  Scaleform::GFx::ASString v154; // [rsp+68h] [rbp-70h] BYREF
  Scaleform::GFx::ASString v155; // [rsp+70h] [rbp-68h] BYREF
  Scaleform::GFx::ASString v156; // [rsp+78h] [rbp-60h] BYREF
  Scaleform::String v157; // [rsp+80h] [rbp-58h] BYREF
  Scaleform::GFx::ASString v158; // [rsp+88h] [rbp-50h] BYREF
  Scaleform::GFx::ASString v159; // [rsp+90h] [rbp-48h] BYREF
  Scaleform::GFx::ASString v160; // [rsp+98h] [rbp-40h] BYREF
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> v161; // [rsp+A0h] [rbp-38h] BYREF
  Scaleform::GFx::ASString v162; // [rsp+A8h] [rbp-30h] BYREF
  Scaleform::GFx::ASString v163; // [rsp+B0h] [rbp-28h] BYREF
  Scaleform::GFx::ASString v164; // [rsp+B8h] [rbp-20h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+C0h] [rbp-18h] BYREF
  __int64 v166; // [rsp+E0h] [rbp+8h]
  Scaleform::GFx::ASString v167; // [rsp+138h] [rbp+60h] BYREF

  v166 = -2i64;
  StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                             (Scaleform::GFx::AS2::AvmTextField *)((char *)this - 8),
                             name);
  Scaleform::GFx::AS2::Value::Value(&newVal, origVal);
  if ( StandardMemberConstant > 0x15
    && penv
    && Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject((Scaleform::GFx::AS2::AvmTextField *)((char *)this - 8))
    && *(_QWORD *)(*((_QWORD *)&this->VariableVal.NV + 3) + 80i64) )
  {
    v.T.Type = 0;
    if ( (unsigned __int8)Scaleform::GFx::AS2::Object::InvokeWatchpoint(
                            *((Scaleform::GFx::AS2::Object **)&this->VariableVal.NV + 3),
                            penv,
                            (Scaleform::GFx::ASString *)name,
                            &newVal,
                            &v) )
      Scaleform::GFx::AS2::Value::operator=(&newVal, &v);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( !((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *, _QWORD, Scaleform::GFx::AS2::Value *, _QWORD))this[-1].ASTextFieldObj.pObject[2].Members.mHash.pTable)(
          &this[-1].ASTextFieldObj,
          StandardMemberConstant,
          origVal,
          0i64) )
  {
    pObject = (Scaleform::GFx::TextField *)this->pProto.pObject;
    switch ( StandardMemberConstant )
    {
      case 0x19u:
      case 0x2Fu:
        goto $LN256;
      case 0x28u:
        Scaleform::GFx::TextField::ResetBlink((Scaleform::GFx::TextField *)this->pProto.pObject, 1, 0);
        Version = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)this->pProto.pObject);
        Scaleform::GFx::AS2::Value::ToStringVersioned(&newVal, &v155, penv, Version);
        Scaleform::GFx::TextField::SetTextValue(pObject, v155.pNode->pData, 0, 1);
        pNode = v155.pNode;
        goto LABEL_294;
      case 0x2Bu:
        v13 = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, penv);
        Scaleform::GFx::TextField::SetTextColor(pObject, v13);
        goto $LN256;
      case 0x2Du:
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, penv) )
          pObject->Flags |= 2u;
        else
          pObject->Flags &= ~2u;
        goto $LN256;
      case 0x2Eu:
        v10 = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)this->pProto.pObject);
        Scaleform::GFx::AS2::Value::ToStringVersioned(&newVal, &result, penv, v10);
        Scaleform::GFx::TextField::SetTextValue(pObject, result.pNode->pData, (pObject->Flags & 2) != 0, 1);
        pNode = result.pNode;
        goto LABEL_294;
      case 0x30u:
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v154, penv, -1);
        if ( newVal.T.Type == 2 )
        {
          v14 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
          pData = "none";
          if ( v14 )
            pData = "left";
        }
        else
        {
          pData = v154.pNode->pData;
        }
        Scaleform::String::String(&v157, pData);
        v16 = pObject->pDocument.pObject;
        v17 = v16->AlignProps & 3;
        v18 = pObject->Flags & 1;
        v19 = v157.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
        v20 = 0i64;
        v21 = 0i64;
        while ( 1 )
        {
          v22 = *(_BYTE *)(v19 + v21++ + 12);
          if ( v22 != aNone[v21 - 1] )
            break;
          if ( v21 == 5 )
          {
            pObject->Flags &= ~1u;
            v16->AlignProps &= 0xFCu;
LABEL_37:
            v16->RTFlags |= 1u;
            goto LABEL_38;
          }
        }
        pObject->Flags |= 1u;
        v23 = 0i64;
        while ( 1 )
        {
          v24 = *(_BYTE *)(v19 + v23++ + 12);
          if ( v24 != aLeft_0[v23 - 1] )
            break;
          if ( v23 == 5 )
          {
            v16->AlignProps &= 0xFCu;
            goto LABEL_37;
          }
        }
        v25 = 0i64;
        while ( 1 )
        {
          v26 = *(_BYTE *)(v19 + v25++ + 12);
          if ( v26 != aRight_0[v25 - 1] )
            break;
          if ( v25 == 6 )
          {
            v16->AlignProps &= ~2u;
            v16->AlignProps |= 1u;
            goto LABEL_37;
          }
        }
        while ( 1 )
        {
          v27 = *(_BYTE *)(v19 + v20++ + 12);
          if ( v27 != aCenter_0[v20 - 1] )
            break;
          if ( v20 == 7 )
          {
            v16->AlignProps &= ~1u;
            v16->AlignProps |= 2u;
            goto LABEL_37;
          }
        }
LABEL_38:
        if ( v17 != (pObject->pDocument.pObject->AlignProps & 3) || v18 != (pObject->Flags & 1) )
          Scaleform::GFx::AS2::AvmTextField::UpdateAutosizeSettings((Scaleform::GFx::AS2::AvmTextField *)((char *)this - 8));
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v157.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pNode = v154.pNode;
        goto LABEL_294;
      case 0x31u:
        v28 = (pObject->pDocument.pObject->Flags & 8) != 0;
        v29 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        if ( v29 == v28 )
          goto LABEL_65;
        v30 = pObject->pDocument.pObject;
        if ( v29 )
          Scaleform::Render::Text::DocView::SetWordWrap(v30);
        else
          Scaleform::Render::Text::DocView::ClearWordWrap(v30);
        goto LABEL_48;
      case 0x32u:
        v31 = (pObject->pDocument.pObject->Flags & 4) != 0;
        v32 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        if ( v31 == v32 )
          goto LABEL_65;
        v51 = v32 == 0;
        v33 = pObject->pDocument.pObject;
        if ( v51 )
          v33->Flags &= ~4u;
        else
          v33->Flags |= 4u;
LABEL_48:
        Scaleform::GFx::AS2::AvmTextField::UpdateAutosizeSettings((Scaleform::GFx::AS2::AvmTextField *)((char *)this - 8));
        goto LABEL_65;
      case 0x33u:
        v43 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        Scaleform::GFx::TextField::SetBorder(pObject, v43);
        goto $LN256;
      case 0x34u:
        v34 = Scaleform::GFx::AS2::Value::ToString(&newVal, &v158, penv, -1);
        Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&this->Scaleform::GFx::AvmTextFieldBase, v34);
        v35 = v158.pNode;
        v51 = v158.pNode->RefCount-- == 1;
        if ( v51 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
        ((void (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this->EventHandlers.mHash.pTable[15].SizeMask)(&this->EventHandlers);
        pObject->Flags |= 0x8000u;
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(pObject);
        goto $LN256;
      case 0x35u:
        v36 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        Scaleform::GFx::TextField::SetSelectable(pObject, v36);
        goto $LN256;
      case 0x36u:
        v51 = !Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        v37 = pObject->pDocument.pObject;
        if ( v51 )
          v37->Flags |= 0x20u;
        else
          v37->Flags &= ~0x20u;
        goto LABEL_64;
      case 0x37u:
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v151, penv, -1);
        v64 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &v162, "normal");
        v65 = v64;
        if ( penv->StringContext.SWFVersion <= 6u )
        {
          if ( !v64->pNode->pLower )
            Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v64->pNode);
          v67 = v151.pNode;
          if ( !v151.pNode->pLower )
          {
            Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v151.pNode);
            v67 = v151.pNode;
          }
          v66 = v65->pNode->pLower == v67->pLower;
        }
        else
        {
          v66 = v64->pNode == v151.pNode;
        }
        v68 = v66;
        v69 = v162.pNode;
        v51 = v162.pNode->RefCount-- == 1;
        if ( v51 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v69);
        if ( v68 )
        {
          pObject->pDocument.pObject->Flags &= ~0x40u;
        }
        else
        {
          v70 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &v159, "advanced");
          v71 = v70;
          if ( penv->StringContext.SWFVersion <= 6u )
          {
            if ( !v70->pNode->pLower )
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v70->pNode);
            v73 = v151.pNode;
            if ( !v151.pNode->pLower )
            {
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v151.pNode);
              v73 = v151.pNode;
            }
            v72 = v71->pNode->pLower == v73->pLower;
          }
          else
          {
            v72 = v70->pNode == v151.pNode;
          }
          v74 = v72;
          v75 = v159.pNode;
          v51 = v159.pNode->RefCount-- == 1;
          if ( v51 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v75);
          if ( v74 )
            pObject->pDocument.pObject->Flags |= 0x40u;
        }
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        pNode = v151.pNode;
        goto LABEL_294;
      case 0x38u:
        v41 = Scaleform::GFx::AS2::Value::ToInt32(&newVal, penv);
        if ( v41 < 0 )
          v41 = 0;
        Scaleform::Render::Text::DocView::SetHScrollOffset(pObject->pDocument.pObject, (int)((double)v41 * 20.0));
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto $LN256;
      case 0x39u:
        v42 = Scaleform::GFx::AS2::Value::ToInt32(&newVal, penv);
        if ( v42 < 1 )
          v42 = 1;
        Scaleform::Render::Text::DocView::SetVScrollOffset(pObject->pDocument.pObject, v42 - 1);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto $LN256;
      case 0x3Cu:
        v44 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        Scaleform::GFx::TextField::SetBackground(pObject, v44);
        goto $LN256;
      case 0x3Du:
        v45 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv);
        if ( !Scaleform::GFx::NumberUtil::IsNaN(v45) )
        {
          v46 = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, penv);
          Scaleform::GFx::TextField::SetBackgroundColor(pObject, v46);
        }
        goto $LN256;
      case 0x3Eu:
        v47 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv);
        if ( !Scaleform::GFx::NumberUtil::IsNaN(v47) )
        {
          v48 = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, penv);
          Scaleform::GFx::TextField::SetBorderColor(pObject, v48);
        }
        goto $LN256;
      case 0x40u:
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v167, penv, -1);
        v49 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &v164, "dynamic");
        v50 = v49;
        if ( penv->StringContext.SWFVersion <= 6u )
        {
          if ( !v49->pNode->pLower )
            Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v49->pNode);
          v52 = v167.pNode;
          if ( !v167.pNode->pLower )
          {
            Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v167.pNode);
            v52 = v167.pNode;
          }
          v51 = v50->pNode->pLower == v52->pLower;
        }
        else
        {
          v51 = v49->pNode == v167.pNode;
        }
        v53 = v51;
        v54 = v164.pNode;
        v51 = v164.pNode->RefCount-- == 1;
        if ( v51 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v54);
        if ( v53 )
        {
          v55 = pObject->pDocument.pObject;
          if ( v55->pEditorKit.pObject )
            LOWORD(v55->pEditorKit.pObject[10].vfptr) |= 1u;
        }
        else
        {
          v56 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&penv->StringContext, &v163, "input");
          v57 = v56;
          if ( penv->StringContext.SWFVersion <= 6u )
          {
            if ( !v56->pNode->pLower )
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v56->pNode);
            v59 = v167.pNode;
            if ( !v167.pNode->pLower )
            {
              Scaleform::GFx::ASStringNode::ResolveLowercase_Impl(v167.pNode);
              v59 = v167.pNode;
            }
            v58 = v57->pNode->pLower == v59->pLower;
          }
          else
          {
            v58 = v56->pNode == v167.pNode;
          }
          v60 = v58;
          v61 = v163.pNode;
          v51 = v163.pNode->RefCount-- == 1;
          if ( v51 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v61);
          if ( v60
            && !((unsigned __int8 (__fastcall *)(Scaleform::HashLH<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor,323,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>,Scaleform::HashNode<Scaleform::GFx::EventId,Scaleform::ArrayLH<Scaleform::GFx::AS2::Value,323,Scaleform::ArrayDefaultPolicy>,Scaleform::GFx::EventIdHashFunctor>::NodeHashF> > *))this->EventHandlers.mHash.pTable[11].SizeMask)(&this->EventHandlers) )
          {
            v62 = Scaleform::GFx::TextField::CreateEditorKit(pObject, &v161)->pObject;
            if ( v161.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v161.pObject);
            v62->Flags &= ~1u;
          }
        }
        pObject->pDocument.pObject->RTFlags |= 1u;
        pNode = v167.pNode;
        goto LABEL_294;
      case 0x41u:
        v63 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv);
        if ( !Scaleform::GFx::NumberUtil::IsNaN(v63) && v63 >= 0.0 )
          pObject->pDocument.pObject->MaxLength = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, penv);
        goto $LN256;
      case 0x42u:
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, penv) )
          pObject->Flags |= 0x10u;
        else
          pObject->Flags &= ~0x10u;
        goto $LN256;
      case 0x43u:
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, penv) )
          pObject->Flags |= 0x80u;
        else
          pObject->Flags &= ~0x80u;
        goto $LN256;
      case 0x44u:
        v38 = (pObject->Flags & 4) != 0;
        v39 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        if ( v38 == v39 )
          goto LABEL_65;
        v51 = v39 == 0;
        v40 = pObject->pDocument.pObject;
        if ( v51 )
        {
          pObject->Flags &= ~4u;
          v40->Flags &= ~0x10u;
        }
        else
        {
          pObject->Flags |= 4u;
          v40->Flags |= 0x10u;
        }
LABEL_64:
        pObject->pDocument.pObject->RTFlags |= 2u;
        goto LABEL_65;
      case 0x45u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v152, penv, -1);
        Scaleform::GFx::TextField::SetShadowStyle(pObject, v152.pNode->pData);
        pNode = v152.pNode;
        goto LABEL_294;
      case 0x46u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v76 = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, penv);
        Scaleform::GFx::TextField::SetShadowColor(pObject, v76);
        goto $LN256;
      case 0x47u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v77 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))this[-1].ASTextFieldObj.pObject[2].pPrev)(&this[-1].ASTextFieldObj);
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v77) )
          pObject->Scaleform::GFx::InteractiveObject::Flags |= 0x800u;
        else
          pObject->Scaleform::GFx::InteractiveObject::Flags &= ~0x800u;
        goto $LN256;
      case 0x48u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v78 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))this[-1].ASTextFieldObj.pObject[2].pPrev)(&this[-1].ASTextFieldObj);
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v78) )
          pObject->Flags |= 8u;
        else
          pObject->Flags &= ~8u;
        pObject->pDocument.pObject->RTFlags |= 2u;
        goto $LN256;
      case 0x4Bu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v156, penv, -1);
        Scaleform::String::String((Scaleform::String *)&v152, v156.pNode->pData);
        v104 = 0i64;
        v105 = 0i64;
        while ( 1 )
        {
          v106 = *(_BYTE *)(((unsigned __int64)v152.pNode & 0xFFFFFFFFFFFFFFFCui64) + v105++ + 12);
          if ( v106 != aNone[v105 - 1] )
            break;
          if ( v105 == 5 )
          {
            pObject->pDocument.pObject->Flags &= ~2u;
            v107 = pObject->pDocument.pObject;
            v107->AlignProps &= 0xF3u;
LABEL_211:
            v107->RTFlags |= 1u;
            goto LABEL_212;
          }
        }
        Scaleform::Render::Text::DocView::SetAutoSizeY(pObject->pDocument.pObject);
        v108 = (unsigned __int64)v152.pNode & 0xFFFFFFFFFFFFFFFCui64;
        v109 = 0i64;
        while ( 1 )
        {
          v110 = *(_BYTE *)(v108 + v109++ + 12);
          if ( v110 != aTop_2[v109 - 1] )
            break;
          if ( v109 == 4 )
          {
            v107 = pObject->pDocument.pObject;
            v107->AlignProps &= ~8u;
            v107->AlignProps |= 4u;
            goto LABEL_211;
          }
        }
        v111 = 0i64;
        while ( 1 )
        {
          v112 = *(_BYTE *)(v108 + v111++ + 12);
          if ( v112 != aBottom[v111 - 1] )
            break;
          if ( v111 == 7 )
          {
            v107 = pObject->pDocument.pObject;
            v107->AlignProps &= ~4u;
            v107->AlignProps |= 8u;
            goto LABEL_211;
          }
        }
        while ( 1 )
        {
          v113 = *(_BYTE *)(v108 + v104++ + 12);
          if ( v113 != aCenter_0[v104 - 1] )
            break;
          if ( v104 == 7 )
          {
            v107 = pObject->pDocument.pObject;
            v107->AlignProps |= 0xCu;
            goto LABEL_211;
          }
        }
LABEL_212:
        pObject->Flags |= 0x2000u;
        Scaleform::GFx::TextField::SetDirtyFlag(pObject);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v152.pNode & 0xFFFFFFFFFFFFFFFCui64)
                                                              + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pNode = v156.pNode;
        goto LABEL_294;
      case 0x4Cu:
        if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
        {
          v114 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv);
          if ( v114 > 0.0 && v114 < 1000.0 )
          {
            v115 = v114;
            Scaleform::Render::Text::DocView::SetFontScaleFactor(pObject->pDocument.pObject, v115);
          }
          Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        }
        goto LABEL_293;
      case 0x4Du:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v156, penv, -1);
        Scaleform::String::String((Scaleform::String *)&v154, v156.pNode->pData);
        v116 = (unsigned __int64)v154.pNode & 0xFFFFFFFFFFFFFFFCui64;
        v117 = 0i64;
        v118 = 0i64;
        while ( 1 )
        {
          v119 = *(_BYTE *)(v116 + v118++ + 12);
          if ( v119 != aNone[v118 - 1] )
            break;
          if ( v118 == 5 )
          {
            v120 = pObject->pDocument.pObject;
            v120->AlignProps &= 0xF3u;
LABEL_236:
            v120->RTFlags |= 1u;
            goto LABEL_237;
          }
        }
        v121 = 0i64;
        while ( 1 )
        {
          v122 = *(_BYTE *)(v116 + v121++ + 12);
          if ( v122 != aTop_2[v121 - 1] )
            break;
          if ( v121 == 4 )
          {
            v120 = pObject->pDocument.pObject;
            v120->AlignProps &= ~8u;
            v120->AlignProps |= 4u;
            goto LABEL_236;
          }
        }
        v123 = 0i64;
        while ( 1 )
        {
          v124 = *(_BYTE *)(v116 + v123++ + 12);
          if ( v124 != aBottom[v123 - 1] )
            break;
          if ( v123 == 7 )
          {
            v120 = pObject->pDocument.pObject;
            v120->AlignProps &= ~4u;
            v120->AlignProps |= 8u;
            goto LABEL_236;
          }
        }
        while ( 1 )
        {
          v125 = *(_BYTE *)(v116 + v117++ + 12);
          if ( v125 != aCenter_0[v117 - 1] )
            break;
          if ( v117 == 7 )
          {
            v120 = pObject->pDocument.pObject;
            v120->AlignProps |= 0xCu;
            goto LABEL_236;
          }
        }
LABEL_237:
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v154.pNode & 0xFFFFFFFFFFFFFFFCui64)
                                                              + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        pNode = v156.pNode;
        goto LABEL_294;
      case 0x4Eu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v155, penv, -1);
        Scaleform::String::String((Scaleform::String *)&result, v155.pNode->pData);
        v126 = (unsigned __int64)result.pNode & 0xFFFFFFFFFFFFFFFCui64;
        v127 = 0i64;
        v128 = 0i64;
        break;
      case 0x4Fu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v134 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))this[-1].ASTextFieldObj.pObject[2].pPrev)(&this[-1].ASTextFieldObj);
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v134) )
          pObject->Flags |= 0x100u;
        else
          pObject->Flags &= ~0x100u;
        v135 = pObject->pDocument.pObject;
        if ( v135->pEditorKit.pObject )
        {
          v136 = v135->pEditorKit.pObject;
          if ( (pObject->Flags & 0x100) != 0 )
            LOWORD(v136[10].vfptr) |= 4u;
          else
            LOWORD(v136[10].vfptr) &= ~4u;
        }
        goto $LN256;
      case 0x50u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v137 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))this[-1].ASTextFieldObj.pObject[2].pPrev)(&this[-1].ASTextFieldObj);
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v137) )
          pObject->Flags |= 0x200u;
        else
          pObject->Flags &= ~0x200u;
        goto $LN256;
      case 0x53u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v140 = pObject->pDocument.pObject;
        if ( !v140->pEditorKit.pObject )
          goto LABEL_293;
        v141 = (Scaleform::GFx::Text::EditorKit *)v140->pEditorKit.pObject;
        v141->ActiveSelectionBkColor = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, penv);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v141);
        goto $LN256;
      case 0x54u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v138 = pObject->pDocument.pObject;
        if ( !v138->pEditorKit.pObject )
          goto LABEL_293;
        v139 = (Scaleform::GFx::Text::EditorKit *)v138->pEditorKit.pObject;
        v139->ActiveSelectionTextColor = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, penv);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v139);
        goto $LN256;
      case 0x55u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v144 = pObject->pDocument.pObject;
        if ( !v144->pEditorKit.pObject )
          goto LABEL_293;
        v145 = (Scaleform::GFx::Text::EditorKit *)v144->pEditorKit.pObject;
        v145->InactiveSelectionBkColor = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, penv);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v145);
        goto $LN256;
      case 0x56u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v142 = pObject->pDocument.pObject;
        if ( !v142->pEditorKit.pObject )
          goto LABEL_293;
        v143 = (Scaleform::GFx::Text::EditorKit *)v142->pEditorKit.pObject;
        v143->InactiveSelectionTextColor = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, penv);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v143);
        goto $LN256;
      case 0x57u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, penv) )
          pObject->Flags |= 0x400u;
        else
          pObject->Flags &= ~0x400u;
        goto $LN256;
      case 0x58u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, penv) )
          pObject->Flags |= 0x800u;
        else
          pObject->Flags &= ~0x800u;
        goto $LN256;
      case 0x5Du:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v51 = !Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        v79 = pObject->pDocument.pObject;
        if ( v51 )
          v79->Flags &= ~0x80u;
        else
          v79->Flags |= 0x80u;
        goto LABEL_65;
      case 0x5Eu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v80 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv) * 20.0;
        pObject->pDocument.pObject->Filter.BlurX = v80;
        goto LABEL_65;
      case 0x5Fu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v81 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv) * 20.0;
        pObject->pDocument.pObject->Filter.BlurY = v81;
        goto LABEL_65;
      case 0x60u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v82 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv);
        pObject->pDocument.pObject->Filter.BlurStrength = v82;
        goto LABEL_65;
      case 0x61u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v83 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv);
        pObject->pDocument.pObject->Outline = v83;
        goto LABEL_65;
      case 0x62u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v84 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        v85 = pObject->pDocument.pObject;
        if ( v84 )
          v85->FlagsEx |= 1u;
        else
          v85->FlagsEx &= ~1u;
        goto LABEL_65;
      case 0x63u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        v86 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        v87 = pObject->pDocument.pObject;
        if ( v86 )
          v87->FlagsEx |= 2u;
        else
          v87->FlagsEx &= ~2u;
        goto LABEL_65;
      case 0x64u:
        if ( newVal.T.Type <= 1u || newVal.T.Type == 10 )
        {
          Scaleform::GFx::TextField::ClearRestrict((Scaleform::GFx::TextField *)this->pProto.pObject);
        }
        else
        {
          v146 = Scaleform::GFx::AS2::Value::ToString(&newVal, &v160, penv, -1);
          Scaleform::GFx::TextField::SetRestrict(pObject, v146);
          v147 = v160.pNode;
          v51 = v160.pNode->RefCount-- == 1;
          if ( v51 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v147);
        }
        goto LABEL_293;
      case 0x65u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v88 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv);
        Scaleform::GFx::TextField::SetShadowAlpha(pObject, v88);
        goto LABEL_65;
      case 0x66u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v89 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv);
        v90 = v89 * 0.017453292;
        v91 = (float *)pObject->pDocument.pObject;
        v91[77] = v90;
        v92 = v90;
        goto LABEL_174;
      case 0x67u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v94 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv) * 20.0;
        pObject->pDocument.pObject->Filter.ShadowParams.BlurX = v94;
        goto LABEL_65;
      case 0x68u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v95 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv) * 20.0;
        pObject->pDocument.pObject->Filter.ShadowParams.BlurY = v95;
        goto LABEL_65;
      case 0x69u:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v96 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv);
        v91 = (float *)pObject->pDocument.pObject;
        v91[78] = v96 * 20.0;
        v92 = v91[77];
LABEL_174:
        v93 = sinf(v92) * v91[78];
        v91[68] = cosf(v92) * v91[78];
        v91[69] = v93;
        goto LABEL_65;
      case 0x6Au:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v97 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        v98 = pObject->pDocument.pObject;
        if ( v97 )
          v98->Filter.ShadowFlags |= 0x40u;
        else
          v98->Filter.ShadowFlags &= ~0x40u;
        goto LABEL_65;
      case 0x6Bu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v99 = Scaleform::GFx::AS2::Value::ToBool(&newVal, penv);
        v100 = pObject->pDocument.pObject;
        if ( v99 )
          v100->Filter.ShadowFlags |= 0x20u;
        else
          v100->Filter.ShadowFlags &= ~0x20u;
        goto LABEL_65;
      case 0x6Cu:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v101 = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, penv);
        v102 = pObject->pDocument.pObject;
        if ( v101 <= 1 )
          v102->Filter.ShadowFlags &= ~0x80u;
        else
          v102->Filter.ShadowFlags |= 0x80u;
        goto LABEL_65;
      case 0x6Du:
        if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_293;
        pObject->pDocument.pObject->Filter.ShadowFlags &= ~1u;
        v103 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, penv);
        pObject->pDocument.pObject->Filter.ShadowParams.Strength = v103;
LABEL_65:
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
        goto $LN256;
      default:
LABEL_293:
        v148 = Scaleform::GFx::AS2::AvmCharacter::SetMember(this, penv, (Scaleform::GFx::ASString *)name, &newVal);
        goto LABEL_297;
    }
    while ( 1 )
    {
      v129 = *(_BYTE *)(v126 + v128++ + 12);
      if ( v129 != aNone[v128 - 1] )
        break;
      if ( v128 == 5 )
      {
        v130 = pObject->pDocument.pObject;
        v130->AlignProps &= 0xCFu;
LABEL_252:
        v130->RTFlags |= 1u;
        goto LABEL_253;
      }
    }
    v131 = 0i64;
    while ( 1 )
    {
      v132 = *(_BYTE *)(v126 + v131++ + 12);
      if ( v132 != aShrink[v131 - 1] )
        break;
      if ( v131 == 7 )
      {
        v130 = pObject->pDocument.pObject;
        v130->AlignProps &= ~0x20u;
        v130->AlignProps |= 0x10u;
        goto LABEL_252;
      }
    }
    while ( 1 )
    {
      v133 = *(_BYTE *)(v126 + v127++ + 12);
      if ( v133 != aFit[v127 - 1] )
        break;
      if ( v127 == 4 )
      {
        v130 = pObject->pDocument.pObject;
        v130->AlignProps &= ~0x10u;
        v130->AlignProps |= 0x20u;
        goto LABEL_252;
      }
    }
LABEL_253:
    Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pProto.pObject);
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)result.pNode & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    pNode = v155.pNode;
LABEL_294:
    v51 = pNode->RefCount-- == 1;
    if ( v51 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
$LN256:
  v148 = 1;
LABEL_297:
  if ( newVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&newVal);
  return v148;
}20u;
        v130->AlignProps |= 0x10u;
        goto LABEL_2

// File Line: 998
// RVA: 0x6F0850
char __fastcall Scaleform::GFx::AS2::AvmTextField::GetMember(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::AS2::Value *pval)
{
  __int64 v8; // r14
  Scaleform::GFx::AS2::AvmCharacter::StandardMember StandardMemberConstant; // r10d
  Scaleform::GFx::AS2::Object *pObject; // rbx
  char IsSelectable; // bl
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v15; // zf
  Scaleform::GFx::ASString *Text; // rax
  unsigned int TextColor32; // eax
  double TextWidth; // xmm1_8
  __int64 Length; // rax
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::Render::Text::DocView *vfptr; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  unsigned int Unwatch; // ecx
  Scaleform::GFx::AS2::Value *v26; // rcx
  Scaleform::GFx::ASString *ShadowStyle; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  double HScrollOffset; // xmm0_8
  int GetMember; // ecx
  unsigned int VScrollOffset; // eax
  Scaleform::GFx::ASString *v32; // rax
  int v33; // ebx
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASString *v36; // rax
  int v37; // ebx
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::Render::Text::DocView *v40; // rax
  Scaleform::GFx::ASString *v41; // rax
  Scaleform::GFx::ASStringNode *v42; // rcx
  Scaleform::GFx::ASString *v43; // rax
  Scaleform::GFx::ASString *v44; // rax
  Scaleform::GFx::ASString *v45; // rax
  Scaleform::GFx::ASString *v46; // rax
  int v47; // ecx
  int v48; // ecx
  int v49; // ecx
  Scaleform::GFx::ASString *v50; // rax
  Scaleform::GFx::ASStringNode *v51; // rcx
  Scaleform::GFx::ASString *v52; // rax
  Scaleform::GFx::ASString *v53; // rax
  Scaleform::GFx::ASString *v54; // rax
  Scaleform::GFx::ASString *v55; // rax
  Scaleform::GFx::ASStringNode *v56; // rcx
  Scaleform::GFx::ASString *v57; // rax
  Scaleform::GFx::ASString *v58; // rax
  unsigned int v59; // ebx
  Scaleform::Render::Text::EditorKitBase *v60; // rcx
  Scaleform::Render::Text::EditorKitBase *DeleteMember; // rcx
  Scaleform::Render::Text::EditorKitBase *v62; // rcx
  Scaleform::Render::Text::EditorKitBase *v63; // rcx
  __int64 v64; // rcx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v65; // rcx
  char v66; // al
  Scaleform::GFx::ASString v67; // [rsp+18h] [rbp-79h] BYREF
  Scaleform::GFx::ASString v68; // [rsp+20h] [rbp-71h] BYREF
  Scaleform::GFx::ASString v69; // [rsp+28h] [rbp-69h] BYREF
  Scaleform::GFx::ASString v70; // [rsp+30h] [rbp-61h] BYREF
  Scaleform::GFx::ASString v71; // [rsp+38h] [rbp-59h] BYREF
  Scaleform::GFx::ASString v72; // [rsp+40h] [rbp-51h] BYREF
  Scaleform::GFx::ASString v73; // [rsp+48h] [rbp-49h] BYREF
  Scaleform::GFx::ASString v74; // [rsp+50h] [rbp-41h] BYREF
  Scaleform::GFx::ASString v75; // [rsp+58h] [rbp-39h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp-31h] BYREF
  Scaleform::GFx::ASString v77; // [rsp+68h] [rbp-29h] BYREF
  Scaleform::GFx::ASString v78; // [rsp+70h] [rbp-21h] BYREF
  Scaleform::GFx::ASString v79; // [rsp+78h] [rbp-19h] BYREF
  Scaleform::GFx::ASString v80; // [rsp+80h] [rbp-11h] BYREF
  Scaleform::GFx::ASString v81; // [rsp+88h] [rbp-9h] BYREF
  Scaleform::GFx::ASString v82; // [rsp+90h] [rbp-1h] BYREF
  Scaleform::GFx::ASString v83; // [rsp+98h] [rbp+7h] BYREF
  Scaleform::GFx::ASString v84; // [rsp+A0h] [rbp+Fh] BYREF
  Scaleform::GFx::ASString v85; // [rsp+A8h] [rbp+17h] BYREF
  Scaleform::GFx::ASString v86; // [rsp+B0h] [rbp+1Fh] BYREF
  __int64 v87; // [rsp+B8h] [rbp+27h]
  Scaleform::GFx::ASString v88; // [rsp+F8h] [rbp+67h]

  v87 = -2i64;
  v8 = 0i64;
  LODWORD(v68.pNode) = 0;
  StandardMemberConstant = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
                             (Scaleform::GFx::AS2::AvmTextField *)((char *)this - 8),
                             name);
  pObject = this->pProto.pObject;
  switch ( StandardMemberConstant )
  {
    case M_filters:
    case M_styleSheet:
      goto $LN104_5;
    case M_text:
      Text = Scaleform::GFx::TextField::GetText((Scaleform::GFx::TextField *)this->pProto.pObject, &v71, 0);
      Scaleform::GFx::AS2::Value::SetString(pval, Text);
      pNode = v71.pNode;
      goto LABEL_8;
    case M_textWidth:
      TextWidth = Scaleform::GFx::TextField::GetTextWidth((Scaleform::GFx::TextField *)this->pProto.pObject);
      goto LABEL_40;
    case M_textHeight:
      TextWidth = Scaleform::GFx::TextField::GetTextHeight((Scaleform::GFx::TextField *)this->pProto.pObject);
      goto LABEL_40;
    case M_textColor:
      TextColor32 = Scaleform::GFx::TextField::GetTextColor32((Scaleform::GFx::TextField *)this->pProto.pObject);
      Scaleform::GFx::AS2::Value::SetInt(pval, TextColor32);
      return 1;
    case M_length:
      Length = Scaleform::Render::Text::StyledText::GetLength(*(Scaleform::Render::Text::StyledText **)&pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8]);
      goto LABEL_84;
    case M_html:
      LODWORD(pObject) = HIDWORD(pObject[2].ResolveHandler.Function) >> 1;
      goto LABEL_3;
    case M_htmlText:
      v13 = Scaleform::GFx::TextField::GetText((Scaleform::GFx::TextField *)this->pProto.pObject, &result, 1);
      Scaleform::GFx::AS2::Value::SetString(pval, v13);
      pNode = result.pNode;
      goto LABEL_8;
    case M_autoSize:
      if ( (BYTE4(pObject[2].ResolveHandler.Function) & 1) != 0 )
      {
        vfptr = (Scaleform::Render::Text::DocView *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr;
        if ( (vfptr->AlignProps & 3) != 0 )
        {
          if ( (vfptr->AlignProps & 3) == 1 )
          {
            v23 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v78, "right");
            Scaleform::GFx::AS2::Value::SetString(pval, v23);
            pNode = v78.pNode;
          }
          else
          {
            if ( (vfptr->AlignProps & 3) != 2 )
              goto $LN104_5;
            v22 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v68, "center");
            Scaleform::GFx::AS2::Value::SetString(pval, v22);
            pNode = v68.pNode;
          }
        }
        else
        {
          v24 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v70, "left");
          Scaleform::GFx::AS2::Value::SetString(pval, v24);
          pNode = v70.pNode;
        }
      }
      else
      {
        v20 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v82, "none");
        Scaleform::GFx::AS2::Value::SetString(pval, v20);
        pNode = v82.pNode;
      }
LABEL_8:
      v15 = pNode->RefCount-- == 1;
      if ( !v15 )
        return 1;
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      return 1;
    case M_wordWrap:
      LOBYTE(pObject) = pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].gap8[0] >> 3;
      goto LABEL_3;
    case M_multiline:
      LOBYTE(pObject) = pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].gap8[0] >> 2;
      goto LABEL_3;
    case M_border:
      Unwatch = (unsigned int)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].Unwatch;
      goto LABEL_26;
    case M_variable:
      v26 = pval;
      if ( !LODWORD(this->Scaleform::GFx::AvmTextFieldBase::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr->ToAvmTextFieldBase) )
        goto LABEL_60;
      Scaleform::GFx::AS2::Value::SetString(pval, (Scaleform::GFx::ASString *)&this->Scaleform::GFx::AvmTextFieldBase);
      return 1;
    case M_selectable:
      IsSelectable = Scaleform::GFx::TextField::IsSelectable((Scaleform::GFx::TextField *)this->pProto.pObject);
      goto LABEL_4;
    case M_embedFonts:
      LOBYTE(pObject) = ~(pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].gap8[0] >> 5);
      goto LABEL_3;
    case M_antiAliasType:
      if ( (pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].gap8[0] & 0x40) != 0 )
      {
        v36 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v84, "advanced");
        v37 = 4;
      }
      else
      {
        v36 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v74, "normal");
        v37 = 8;
      }
      LODWORD(v68.pNode) = v37;
      Scaleform::GFx::AS2::Value::SetString(pval, v36);
      if ( (v37 & 8) != 0 )
      {
        v37 &= ~8u;
        LODWORD(v68.pNode) = v37;
        v38 = v74.pNode;
        v15 = v74.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v38);
      }
      if ( (v37 & 4) != 0 )
      {
        LODWORD(v68.pNode) = v37 & 0xFFFFFFFB;
        v39 = v84.pNode;
        v15 = v84.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v39);
      }
      return 1;
    case M_hscroll:
      HScrollOffset = Scaleform::GFx::TextField::GetHScrollOffset((Scaleform::GFx::TextField *)this->pProto.pObject);
      goto LABEL_38;
    case M_scroll:
      VScrollOffset = Scaleform::Render::Text::DocView::GetVScrollOffset((Scaleform::Render::Text::DocView *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr);
      goto LABEL_42;
    case M_maxscroll:
      VScrollOffset = Scaleform::Render::Text::DocView::GetMaxVScroll((Scaleform::Render::Text::DocView *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr);
LABEL_42:
      Scaleform::GFx::AS2::Value::SetNumber(pval, (double)(int)(VScrollOffset + 1));
      return 1;
    case M_maxhscroll:
      HScrollOffset = (double)(int)Scaleform::Render::Text::DocView::GetMaxHScroll((Scaleform::Render::Text::DocView *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr)
                    * 0.05;
LABEL_38:
      GetMember = (int)HScrollOffset;
      goto LABEL_39;
    case M_background:
      Unwatch = HIDWORD(pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].Unwatch);
LABEL_26:
      LODWORD(v88.pNode) = Unwatch;
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->V.BooleanValue = BYTE3(v88.pNode) != 0;
      goto LABEL_5;
    case M_backgroundColor:
      TextWidth = (double)(HIDWORD(pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].Unwatch) & 0xFFFFFF);
      goto LABEL_40;
    case M_borderColor:
      TextWidth = (double)((__int64)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].Unwatch & 0xFFFFFF);
      goto LABEL_40;
    case M_bottomScroll:
      TextWidth = (double)(int)(Scaleform::Render::Text::DocView::GetBottomVScroll((Scaleform::Render::Text::DocView *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr)
                              + 1);
      goto LABEL_40;
    case M_type:
      if ( Scaleform::GFx::TextField::IsReadOnly((Scaleform::GFx::TextField *)this->pProto.pObject) )
      {
        v32 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v80, "dynamic");
        v33 = 1;
      }
      else
      {
        v32 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v72, "input");
        v33 = 2;
      }
      LODWORD(v68.pNode) = v33;
      Scaleform::GFx::AS2::Value::SetString(pval, v32);
      if ( (v33 & 2) != 0 )
      {
        v33 &= ~2u;
        LODWORD(v68.pNode) = v33;
        v34 = v72.pNode;
        v15 = v72.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v34);
      }
      if ( (v33 & 1) != 0 )
      {
        LODWORD(v68.pNode) = v33 & 0xFFFFFFFE;
        v35 = v80.pNode;
        v15 = v80.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
      }
      return 1;
    case M_maxChars:
      GetMember = (int)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].GetMember;
      if ( GetMember )
      {
LABEL_39:
        TextWidth = (double)GetMember;
LABEL_40:
        Scaleform::GFx::AS2::Value::SetNumber(pval, TextWidth);
      }
      else
      {
        v26 = pval;
LABEL_60:
        Scaleform::GFx::AS2::Value::DropRefs(v26);
        pval->T.Type = 1;
      }
      return 1;
    case M_condenseWhite:
      LODWORD(pObject) = HIDWORD(pObject[2].ResolveHandler.Function) >> 4;
      goto LABEL_3;
    case M_mouseWheelEnabled:
      LODWORD(pObject) = HIDWORD(pObject[2].ResolveHandler.Function) >> 7;
      goto LABEL_3;
    case M_password:
      LODWORD(pObject) = HIDWORD(pObject[2].ResolveHandler.Function) >> 2;
      goto LABEL_3;
    case M_shadowStyle:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      ShadowStyle = Scaleform::GFx::TextField::GetShadowStyle((Scaleform::GFx::TextField *)this->pProto.pObject, &v86);
      Scaleform::GFx::AS2::Value::SetString(pval, ShadowStyle);
      v28 = v86.pNode;
      v15 = v86.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      return 1;
    case M_shadowColor:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      Scaleform::GFx::AS2::Value::SetInt(
        pval,
        HIDWORD(pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].Get__constructor__) & 0xFFFFFF);
      return 1;
    case M_hitTestDisable:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))this[-1].ASTextFieldObj.pObject[2].pPrev)(&this[-1].ASTextFieldObj)
                                + 232)
                    + 104i64) != 1 )
        goto $LN7_74;
      LODWORD(pObject) = *(_DWORD *)&pObject[1].ArePropertiesSet >> 11;
      goto LABEL_3;
    case M_noTranslate:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))this[-1].ASTextFieldObj.pObject[2].pPrev)(&this[-1].ASTextFieldObj)
                                + 232)
                    + 104i64) != 1 )
        goto $LN7_74;
      LODWORD(pObject) = HIDWORD(pObject[2].ResolveHandler.Function) >> 3;
      goto LABEL_3;
    case M_caretIndex:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = (double)(int)Scaleform::GFx::TextField::GetCursorPos((Scaleform::GFx::TextField *)this->pProto.pObject);
      goto LABEL_40;
    case M_numLines:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = (double)(int)Scaleform::Render::Text::DocView::GetLinesCount((Scaleform::Render::Text::DocView *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr);
      goto LABEL_40;
    case M_verticalAutoSize:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v40 = (Scaleform::Render::Text::DocView *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr;
      if ( (v40->Flags & 2) != 0 )
      {
        if ( (((unsigned __int8)v40->AlignProps >> 2) & 3) != 0 )
        {
          switch ( ((unsigned __int8)v40->AlignProps >> 2) & 3 )
          {
            case 1:
              v45 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v69, "top");
              Scaleform::GFx::AS2::Value::SetString(pval, v45);
              v42 = v69.pNode;
              break;
            case 2:
              v44 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v67, "bottom");
              Scaleform::GFx::AS2::Value::SetString(pval, v44);
              v42 = v67.pNode;
              break;
            case 3:
              v43 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v70, "center");
              Scaleform::GFx::AS2::Value::SetString(pval, v43);
              v42 = v70.pNode;
              break;
            default:
              goto $LN104_5;
          }
        }
        else
        {
          v46 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v71, "none");
          Scaleform::GFx::AS2::Value::SetString(pval, v46);
          v42 = v71.pNode;
        }
      }
      else
      {
        v41 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v69, "none");
        Scaleform::GFx::AS2::Value::SetString(pval, v41);
        v42 = v69.pNode;
      }
      v15 = v42->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v42);
      return 1;
    case M_fontScaleFactor:
      if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
        Scaleform::GFx::AS2::Value::SetNumber(
          pval,
          (float)((float)WORD1(pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].__vecDelDtor) * 0.050000001));
      goto $LN7_74;
    case M_verticalAlign:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v47 = ((unsigned __int8)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].gap8[1] >> 2) & 3;
      if ( v47 )
      {
        v48 = v47 - 1;
        if ( v48 )
        {
          v49 = v48 - 1;
          if ( v49 )
          {
            if ( v49 != 1 )
            {
$LN104_5:
              Scaleform::GFx::AS2::Value::DropRefs(pval);
              pval->T.Type = 0;
              return 1;
            }
            v50 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v73, "center");
            Scaleform::GFx::AS2::Value::SetString(pval, v50);
            v51 = v73.pNode;
          }
          else
          {
            v52 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v75, "bottom");
            Scaleform::GFx::AS2::Value::SetString(pval, v52);
            v51 = v75.pNode;
          }
        }
        else
        {
          v53 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v77, "top");
          Scaleform::GFx::AS2::Value::SetString(pval, v53);
          v51 = v77.pNode;
        }
      }
      else
      {
        v54 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v79, "none");
        Scaleform::GFx::AS2::Value::SetString(pval, v54);
        v51 = v79.pNode;
      }
      v15 = v51->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v51);
      return 1;
    case M_textAutoSize:
      if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
      {
        if ( (((unsigned __int8)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].gap8[1] >> 4) & 3) == 1 )
        {
          v58 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v85, "shrink");
          Scaleform::GFx::AS2::Value::SetString(pval, v58);
          v56 = v85.pNode;
        }
        else if ( (((unsigned __int8)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].gap8[1] >> 4) & 3) == 2 )
        {
          v57 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v83, "fit");
          Scaleform::GFx::AS2::Value::SetString(pval, v57);
          v56 = v83.pNode;
        }
        else
        {
          v55 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &v81, "none");
          Scaleform::GFx::AS2::Value::SetString(pval, v55);
          v56 = v81.pNode;
        }
        v15 = v56->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v56);
      }
      goto $LN7_74;
    case M_useRichTextClipboard:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v59 = HIDWORD(pObject[2].ResolveHandler.Function) >> 8;
      goto LABEL_159;
    case M_alwaysShowSelection:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v59 = HIDWORD(pObject[2].ResolveHandler.Function) >> 9;
LABEL_159:
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->T.Type = 2;
      pval->V.BooleanValue = v59 & 1;
$LN7_74:
      v64 = *((_QWORD *)&this->VariableVal.NV + 3);
      if ( v64 )
        return (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v64 + 32) + 32i64))(
                 v64 + 32,
                 penv,
                 name,
                 pval);
      if ( penv
        && name->pNode == (Scaleform::GFx::ASStringNode *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl )
      {
        Scaleform::GFx::AS2::Value::SetAsObject(
          pval,
          (Scaleform::GFx::AS2::Object *)this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr);
        return 1;
      }
      v65 = this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr;
      if ( v65
        && (*((unsigned __int8 (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v65->GetMember
            + 4))(
             (__int64)&v65->GetMember,
             penv,
             name,
             pval) )
      {
        return 1;
      }
      do
      {
        v66 = name->pNode->pData[v8++];
        if ( v66 != aGlobal_0[v8 - 1] )
          return 0;
      }
      while ( v8 != 8 );
      if ( penv )
      {
        Scaleform::GFx::AS2::Value::SetAsObject(pval, penv->StringContext.pContext->pGlobal.pObject);
        return 1;
      }
      return 0;
    case M_selectionBeginIndex:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      if ( !Scaleform::GFx::TextField::IsSelectable((Scaleform::GFx::TextField *)this->pProto.pObject)
        || !pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].DeleteMember )
      {
        goto LABEL_86;
      }
      Length = Scaleform::GFx::TextField::GetBeginIndex((Scaleform::GFx::TextField *)pObject);
      goto LABEL_84;
    case M_selectionEndIndex:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      if ( Scaleform::GFx::TextField::IsSelectable((Scaleform::GFx::TextField *)this->pProto.pObject)
        && pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].DeleteMember )
      {
        Length = Scaleform::GFx::TextField::GetEndIndex((Scaleform::GFx::TextField *)pObject);
LABEL_84:
        TextWidth = (double)(int)Length;
        if ( Length < 0 )
          TextWidth = TextWidth + 1.844674407370955e19;
      }
      else
      {
LABEL_86:
        TextWidth = DOUBLE_N1_0;
      }
      goto LABEL_40;
    case M_selectionBkgColor:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      DeleteMember = (Scaleform::Render::Text::EditorKitBase *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].DeleteMember;
      if ( !DeleteMember )
        goto $LN7_74;
      TextWidth = (double)SLODWORD(DeleteMember[9].vfptr);
      goto LABEL_40;
    case M_selectionTextColor:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v60 = (Scaleform::Render::Text::EditorKitBase *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].DeleteMember;
      if ( !v60 )
        goto $LN7_74;
      TextWidth = (double)SHIDWORD(v60[9].vfptr);
      goto LABEL_40;
    case M_inactiveSelectionBkgColor:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v63 = (Scaleform::Render::Text::EditorKitBase *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].DeleteMember;
      if ( !v63 )
        goto $LN7_74;
      TextWidth = (double)(int)v63[9].RefCount;
      goto LABEL_40;
    case M_inactiveSelectionTextColor:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v62 = (Scaleform::Render::Text::EditorKitBase *)pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].DeleteMember;
      if ( !v62 )
        goto $LN7_74;
      TextWidth = (double)*((int *)&v62[9].RefCount + 1);
      goto LABEL_40;
    case M_noAutoSelection:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LODWORD(pObject) = HIDWORD(pObject[2].ResolveHandler.Function) >> 10;
      goto LABEL_3;
    case M_disableIME:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LODWORD(pObject) = HIDWORD(pObject[2].ResolveHandler.Function) >> 11;
      goto LABEL_3;
    case M_autoFit:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      IsSelectable = pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].gap8[0] >> 7;
      goto LABEL_4;
    case M_blurX:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = *(float *)&pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].HasMember * 0.05;
      goto LABEL_40;
    case M_blurY:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = *((float *)&pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].HasMember + 1) * 0.05;
      goto LABEL_40;
    case M_blurStrength:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = *(float *)&pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].SetMemberRaw;
      goto LABEL_40;
    case M_outline:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = *((float *)&pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].__vecDelDtor + 1);
      goto LABEL_40;
    case M_fauxBold:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LOBYTE(pObject) = pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].gap8[2];
      goto LABEL_3;
    case M_fauxItalic:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LOBYTE(pObject) = pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[2].gap8[2] >> 1;
      goto LABEL_3;
    case M_shadowAlpha:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = (float)((float)BYTE4(pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].InstanceOf)
                        * 0.0039215689);
      goto LABEL_40;
    case M_shadowAngle:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = (float)(*((float *)&pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].AddInterface + 1)
                        * 57.295784);
      goto LABEL_40;
    case M_shadowBlurX:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = *(float *)&pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].ToFunction * 0.05;
      goto LABEL_40;
    case M_shadowBlurY:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = *((float *)&pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].ToFunction + 1) * 0.05;
      goto LABEL_40;
    case M_shadowDistance:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = *(float *)&pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].InstanceOf * 0.05;
      goto LABEL_40;
    case M_shadowHideObject:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LODWORD(pObject) = LODWORD(pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].AddInterface) >> 6;
      goto LABEL_3;
    case M_shadowKnockOut:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LODWORD(pObject) = LODWORD(pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].AddInterface) >> 5;
LABEL_3:
      IsSelectable = (unsigned __int8)pObject & 1;
LABEL_4:
      Scaleform::GFx::AS2::Value::DropRefs(pval);
      pval->V.BooleanValue = IsSelectable;
LABEL_5:
      pval->T.Type = 2;
      return 1;
    case M_shadowQuality:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LOBYTE(v8) = SLOBYTE(pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].AddInterface) < 0;
      TextWidth = (double)((int)v8 + 1);
      goto LABEL_40;
    case M_shadowStrength:
      if ( penv->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      TextWidth = *(float *)&pObject[2].Scaleform::GFx::AS2::ObjectInterface::vfptr[1].Get__constructor__;
      goto LABEL_40;
    case M_shadowOutline:
      goto $LN7_74;
    default:
      if ( ((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *, _QWORD, Scaleform::GFx::AS2::Value *, _QWORD))this[-1].ASTextFieldObj.pObject[2].ResolveHandler.Function)(
             &this[-1].ASTextFieldObj,
             (unsigned int)StandardMemberConstant,
             pval,
             0i64) )
      {
        return 1;
      }
      goto $LN7_74;
  }
}

// File Line: 1603
// RVA: 0x700E00
bool __fastcall Scaleform::GFx::AS2::AvmTextField::IsTabable(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::Object *pObject; // rdi
  Scaleform::GFx::AS2::Environment *v3; // rsi
  Scaleform::GFx::ASString *v4; // rax
  char v5; // di
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // bl
  Scaleform::GFx::AS2::Value v10; // [rsp+28h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h] BYREF

  pObject = this->pProto.pObject;
  if ( !pObject )
    return !Scaleform::GFx::TextField::IsReadOnly((Scaleform::GFx::TextField *)this->pDispObj);
  v10.T.Type = 0;
  v3 = (Scaleform::GFx::AS2::Environment *)this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AvmInteractiveObjBase::Scaleform::GFx::AvmDisplayObjBase::vfptr[2].ToAvmDispContainerBase(this);
  v4 = Scaleform::GFx::AS2::Environment::CreateConstString(v3, &result, "tabEnabled");
  v5 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMemberRaw)(
         &pObject->Scaleform::GFx::AS2::ObjectInterface,
         &v3->StringContext,
         v4,
         &v10,
         -2i64);
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( !v5 || !v10.T.Type || v10.T.Type == 10 )
  {
    if ( v10.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v10);
    return !Scaleform::GFx::TextField::IsReadOnly((Scaleform::GFx::TextField *)this->pDispObj);
  }
  v8 = Scaleform::GFx::AS2::Value::ToBool(&v10, v3);
  if ( v10.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v10);
  return v8;
}

// File Line: 1620
// RVA: 0x7231D0
void __fastcall Scaleform::GFx::AS2::AvmTextField::UpdateVariable(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::Environment *v2; // rsi
  Scaleform::GFx::InteractiveObject **Text; // r14
  Scaleform::GFx::InteractiveObject *v4; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF

  if ( LODWORD(this->Scaleform::GFx::AS2::AvmCharacter::Scaleform::GFx::AS2::ObjectInterface::vfptr->GetMember) )
  {
    v2 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::Value *))(*(_QWORD *)&this[-1].VariableVal.T.Type + 240i64))(&this[-1].VariableVal);
    if ( v2 )
    {
      Text = (Scaleform::GFx::InteractiveObject **)Scaleform::GFx::TextField::GetText(
                                                     *((Scaleform::GFx::TextField **)&this[-1].VariableVal.NV + 3),
                                                     &result,
                                                     0);
      if ( LOBYTE(this->pProto.pObject) >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&this->pProto);
      LOBYTE(this->pProto.pObject) = 5;
      v4 = *Text;
      this->pDispObj = *Text;
      ++LODWORD(v4->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      Scaleform::GFx::AS2::Environment::SetVariable(
        v2,
        (Scaleform::GFx::ASString *)&this->Scaleform::GFx::AS2::ObjectInterface,
        (Scaleform::GFx::AS2::Value *)&this->pProto,
        0i64,
        1);
    }
  }
}

// File Line: 1635
// RVA: 0x703340
void __fastcall Scaleform::GFx::AS2::AvmTextField::NotifyChanged(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::Value *p_VariableVal; // r12
  __int64 v3; // rax
  Scaleform::GFx::AS2::Environment *v4; // r15
  int v5; // edi
  __int64 v6; // rcx
  int v7; // edi
  __int64 pCurrent; // rax
  Scaleform::GFx::DisplayObject *v9; // rcx
  char Type; // bp
  Scaleform::GFx::AS2::ObjectInterface *v11; // r14
  Scaleform::GFx::ASStringNode *pObject; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASString *v14; // rax
  unsigned int v15; // r8d
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-50h] BYREF
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h] BYREF
  __int64 v21; // [rsp+88h] [rbp+10h]

  p_VariableVal = &this[-1].VariableVal;
  v3 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::Value *))(*(_QWORD *)&this[-1].VariableVal.T.Type + 240i64))(&this[-1].VariableVal);
  v4 = (Scaleform::GFx::AS2::Environment *)v3;
  v5 = 1;
  if ( *(_BYTE *)(*(_QWORD *)(v3 + 232) + 104i64) == 1 )
  {
    v6 = *((_QWORD *)&this[-1].VariableVal.NV + 3);
    if ( *(_DWORD *)(v6 + 280) != -1 )
    {
      v7 = *(_DWORD *)(v6 + 280);
      *(_QWORD *)(v3 + 8) += 32i64;
      if ( *(_QWORD *)(v3 + 8) >= *(_QWORD *)(v3 + 24) )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage((Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v3 + 8));
      pCurrent = (__int64)v4->Stack.pCurrent;
      result.pNode = (Scaleform::GFx::ASStringNode *)pCurrent;
      v21 = pCurrent;
      if ( pCurrent )
      {
        *(_BYTE *)pCurrent = 4;
        *(_DWORD *)(pCurrent + 8) = v7;
      }
      v5 = 2;
    }
  }
  v9 = (Scaleform::GFx::DisplayObject *)*((_QWORD *)&this[-1].VariableVal.NV + 3);
  Type = 7;
  v.T.Type = 7;
  v11 = 0i64;
  if ( v9 )
  {
    pObject = (Scaleform::GFx::ASStringNode *)v9->pNameHandle.pObject;
    if ( !pObject )
      pObject = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v9);
    v.V.pStringNode = pObject;
    if ( pObject )
      ++LODWORD(pObject->pData);
  }
  else
  {
    v.V.pStringNode = 0i64;
  }
  if ( ++v4->Stack.pCurrent >= v4->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
  v13 = (Scaleform::GFx::ASStringNode *)v4->Stack.pCurrent;
  result.pNode = v13;
  v21 = (__int64)v13;
  if ( v13 )
  {
    Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v13, &v);
    Type = v.T.Type;
  }
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( p_VariableVal )
    v11 = (Scaleform::GFx::AS2::ObjectInterface *)&this[-1].VariableVal.NV.8;
  v14 = Scaleform::GFx::AS2::Environment::CreateConstString(v4, &result, "onChanged");
  v15 = v4->Stack.pCurrent - v4->Stack.pPageStart + 32 * v4->Stack.Pages.Data.Size - 32;
  if ( v11 )
  {
    *(_QWORD *)&v.T.Type = `Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v.V.pStringNode = (Scaleform::GFx::ASStringNode *)__PAIR64__(v15, v5);
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v4,
      v11,
      v14,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *)&v);
    *(_QWORD *)&v.T.Type = &Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  do
  {
    v18 = v4->Stack.pCurrent;
    if ( v18->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v18);
    if ( --v4->Stack.pCurrent < v4->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
    --v5;
  }
  while ( v5 );
}

// File Line: 1650
// RVA: 0x6DB6E0
void __fastcall Scaleform::GFx::AS2::AvmTextField::BroadcastMessage(Scaleform::GFx::AS2::FnCall *fn)
{
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::Environment *v5; // r10
  int v6; // r8d
  int v7; // eax
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rdx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-20h] BYREF
  int v12; // [rsp+30h] [rbp-18h]
  int v13; // [rsp+34h] [rbp-14h]
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF

  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v4 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v4, &result, Env, -1);
  v5 = fn->Env;
  v6 = v5->Stack.pCurrent - v5->Stack.pPageStart + 32 * v5->Stack.Pages.Data.Size - 33;
  v7 = fn->NArgs - 1;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v12 = v7;
    v13 = v6;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v5, ThisPtr, &result, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 1656
// RVA: 0x706F20
void __fastcall Scaleform::GFx::AS2::AvmTextField::OnScroll(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::InteractiveObject *v2; // rbx
  Scaleform::GFx::AS2::Environment *v3; // rdi
  Scaleform::GFx::InteractiveObject *pObject; // r8
  __int64 *v5; // rdx
  int v6; // eax
  Scaleform::GFx::ASString *v7; // rax
  char Type; // di
  Scaleform::GFx::ASStringNode *pNode; // rcx
  char v11; // di
  Scaleform::GFx::ASStringNode *CharacterHandle; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v14; // rdi
  Scaleform::RefCountNTSImpl *v15; // rcx
  Scaleform::RefCountNTSImpl *v16; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+20h] [rbp-99h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+38h] [rbp-81h] BYREF
  Scaleform::GFx::AS2::MovieRoot::ActionEntry v19; // [rsp+60h] [rbp-59h] BYREF
  __int64 v20; // [rsp+E0h] [rbp+27h]
  Scaleform::GFx::ASString result; // [rsp+120h] [rbp+67h] BYREF
  Scaleform::GFx::AS2::Value *p_FunctionParams; // [rsp+128h] [rbp+6Fh]
  Scaleform::GFx::AS2::Value *v23; // [rsp+130h] [rbp+77h]

  v20 = -2i64;
  v2 = (Scaleform::GFx::InteractiveObject *)*((_QWORD *)&this[-1].VariableVal.NV + 3);
  v3 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__fastcall **)(Scaleform::GFx::AS2::Value *))(*(_QWORD *)&this[-1].VariableVal.T.Type + 240i64))(&this[-1].VariableVal);
  memset(&v19.pCharacter, 0, 29);
  *(_DWORD *)&v19.mEventId.RollOverCnt = 65280;
  memset(&v19.Function, 0, 17);
  result.pNode = (Scaleform::GFx::ASStringNode *)&v19.FunctionParams;
  p_FunctionParams = (Scaleform::GFx::AS2::Value *)&v19.FunctionParams;
  memset(&v19.FunctionParams, 0, 28);
  v19.pNextEntry = 0i64;
  v19.Type = Entry_CFunction;
  if ( v2 )
    ++v2->RefCount;
  if ( v19.pCharacter.pObject )
    Scaleform::RefCountNTSImpl::Release(v19.pCharacter.pObject);
  pObject = v2;
  v19.pCharacter.pObject = v2;
  if ( v19.pActionBuffer.pObject )
  {
    Scaleform::RefCountNTSImpl::Release(v19.pActionBuffer.pObject);
    pObject = v19.pCharacter.pObject;
  }
  v19.pActionBuffer.pObject = 0i64;
  v19.CFunction = Scaleform::GFx::AS2::AvmTextField::BroadcastMessage;
  v5 = *(__int64 **)(*(_QWORD *)(*((_QWORD *)&this[-1].VariableVal.NV + 3) + 32i64) + 224i64);
  if ( v5 )
  {
    while ( 1 )
    {
      if ( *((_DWORD *)v5 + 2) == v19.Type
        && !v5[3]
        && (Scaleform::GFx::InteractiveObject *)v5[2] == pObject
        && (void (__fastcall *)(Scaleform::GFx::AS2::FnCall *))v5[10] == Scaleform::GFx::AS2::AvmTextField::BroadcastMessage
        && (Scaleform::GFx::AS2::FunctionObject *)v5[7] == v19.Function.Function )
      {
        v6 = *((_DWORD *)v5 + 8);
        if ( v6 == v19.mEventId.Id && ((v6 & 0x20000) == 0 || *((_DWORD *)v5 + 10) == v19.mEventId.KeyCode) )
          break;
      }
      v5 = (__int64 *)*v5;
      if ( !v5 )
        goto LABEL_17;
    }
  }
  else
  {
LABEL_17:
    result.pNode = (Scaleform::GFx::ASStringNode *)&pheapAddr;
    memset(&pheapAddr, 0, sizeof(pheapAddr));
    v7 = Scaleform::GFx::AS2::Environment::CreateConstString(v3, &result, "onScroller");
    Type = 5;
    v.T.Type = 5;
    v.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v7->pNode;
    ++v.V.pStringNode->RefCount;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    p_FunctionParams = &pheapAddr.Data[pheapAddr.Size - 1];
    v23 = p_FunctionParams;
    if ( p_FunctionParams )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
      Type = v.T.Type;
    }
    if ( (unsigned __int8)Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    pNode = result.pNode;
    if ( result.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v11 = 7;
    v.T.Type = 7;
    if ( v2 )
    {
      CharacterHandle = (Scaleform::GFx::ASStringNode *)v2->pNameHandle.pObject;
      if ( !CharacterHandle )
        CharacterHandle = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v2);
      v.V.pStringNode = CharacterHandle;
      if ( CharacterHandle )
        ++LODWORD(CharacterHandle->pData);
    }
    else
    {
      v.V.pStringNode = 0i64;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    result.pNode = (Scaleform::GFx::ASStringNode *)&pheapAddr.Data[pheapAddr.Size - 1];
    p_FunctionParams = (Scaleform::GFx::AS2::Value *)result.pNode;
    if ( result.pNode )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
      v11 = v.T.Type;
    }
    if ( (unsigned __int8)v11 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
                 (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)(*(_QWORD *)(*((_QWORD *)&this[-1].VariableVal.NV + 3)
                                                                               + 32i64)
                                                                   + 128i64),
                 AP_Frame);
    v14 = inserted;
    inserted->Type = Entry_CFunction;
    if ( v2 )
      ++v2->RefCount;
    v15 = inserted->pCharacter.pObject;
    if ( v15 )
      Scaleform::RefCountNTSImpl::Release(v15);
    v14->pCharacter.pObject = v2;
    v16 = v14->pActionBuffer.pObject;
    if ( v16 )
      Scaleform::RefCountNTSImpl::Release(v16);
    v14->pActionBuffer.pObject = 0i64;
    v14->CFunction = Scaleform::GFx::AS2::AvmTextField::BroadcastMessage;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      &v14->FunctionParams,
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr);
    result.pNode = (Scaleform::GFx::ASStringNode *)&pheapAddr;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
  }
  Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(&v19);
}

// File Line: 1673
// RVA: 0x708C30
void __fastcall Scaleform::GFx::AS2::AvmTextField::ProceedImageSubstitution(
        Scaleform::GFx::AS2::AvmTextField *this,
        Scaleform::GFx::AS2::FnCall *fn,
        unsigned int idx,
        Scaleform::GFx::AS2::Value *pve)
{
  Scaleform::GFx::TextField *v7; // rdi
  Scaleform::GFx::AS2::Object *v8; // r14
  Scaleform::Render::Text::ImageDesc *v9; // r15
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v11; // r14
  Scaleform::GFx::ASString *v12; // rax
  bool v13; // bl
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v15; // zf
  unsigned __int64 Length; // rbx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  float v20; // xmm7_4
  float v21; // xmm9_4
  float v22; // xmm10_4
  float v23; // xmm12_4
  float v24; // xmm11_4
  Scaleform::GFx::ASStringNode *ExecuteForEachChild_GC; // rbx
  Scaleform::GFx::AS2::ASStringContext *v26; // rdi
  Scaleform::GFx::ASString *v27; // rax
  char v28; // di
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::AS2::Object *v30; // rax
  Scaleform::GFx::AS2::Object *v31; // rdi
  Scaleform::GFx::Resource *v32; // rax
  __int64 v33; // rdi
  char v34; // al
  Scaleform::MemoryHeap *v35; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *ImageCreator; // rax
  Scaleform::GFx::ASString *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::AS2::ASStringContext *v39; // rdi
  Scaleform::GFx::ASString *v40; // rax
  char v41; // di
  Scaleform::GFx::ASStringNode *v42; // rcx
  Scaleform::GFx::AS2::ASStringContext *v43; // rdi
  Scaleform::GFx::ASString *v44; // rax
  bool v45; // di
  Scaleform::GFx::ASStringNode *v46; // rcx
  Scaleform::GFx::AS2::ASStringContext *v47; // rdi
  Scaleform::GFx::ASString *v48; // rax
  bool v49; // di
  Scaleform::GFx::ASStringNode *v50; // rcx
  Scaleform::GFx::AS2::ASStringContext *v51; // rdi
  Scaleform::GFx::ASString *v52; // rax
  bool v53; // di
  Scaleform::GFx::ASStringNode *v54; // rcx
  float v55; // xmm6_4
  Scaleform::GFx::AS2::ASStringContext *v56; // rdi
  Scaleform::GFx::ASString *v57; // rax
  bool v58; // di
  Scaleform::GFx::ASStringNode *v59; // rcx
  const char *pData; // rdi
  Scaleform::Render::Text::ImageDesc *v61; // rax
  Scaleform::Render::Text::ImageDesc *v62; // rax
  Scaleform::Render::Image *pObject; // rcx
  Scaleform::GFx::TextField *v64; // rsi
  Scaleform::Render::Text::ImageDesc *v65; // rax
  int v66; // xmm2_4
  float *v67; // rax
  float v68; // xmm3_4
  float v69; // xmm2_4
  Scaleform::GFx::ASString *v70; // rax
  Scaleform::GFx::ASStringNode *v71; // rcx
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *v73; // rcx
  Scaleform::GFx::ASString v74; // [rsp+20h] [rbp-E0h] BYREF
  Scaleform::GFx::TextField *pDispObj; // [rsp+28h] [rbp-D8h]
  Scaleform::GFx::AS2::Value v76; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *vfptr; // [rsp+50h] [rbp-B0h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v78; // [rsp+58h] [rbp-A8h] BYREF
  int v79; // [rsp+60h] [rbp-A0h]
  int v80; // [rsp+64h] [rbp-9Ch]
  Scaleform::Render::Text::ImageDesc *v81; // [rsp+68h] [rbp-98h]
  Scaleform::Render::Text::DocView::ImageSubstitutor::Element pbuff; // [rsp+70h] [rbp-90h] BYREF
  Scaleform::Render::Text::DocView::ImageSubstitutor *ImageSubstitutor; // [rsp+A8h] [rbp-58h]
  Scaleform::MemoryHeap *pHeap; // [rsp+B0h] [rbp-50h]
  int v85; // [rsp+B8h] [rbp-48h] BYREF
  Scaleform::MemoryHeap *v86; // [rsp+C0h] [rbp-40h]
  int v87; // [rsp+C8h] [rbp-38h]
  int v88; // [rsp+CCh] [rbp-34h]
  __int64 v89; // [rsp+D0h] [rbp-30h]
  __int64 v90; // [rsp+D8h] [rbp-28h]
  __int64 v91; // [rsp+E0h] [rbp-20h]
  __int64 v92; // [rsp+E8h] [rbp-18h]
  __int64 v93; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+1B8h] [rbp+B8h] BYREF

  if ( pve )
  {
    v93 = -2i64;
    if ( pve->T.Type == 6 )
    {
      pDispObj = (Scaleform::GFx::TextField *)this->pDispObj;
      v7 = pDispObj;
      v8 = Scaleform::GFx::AS2::Value::ToObject(pve, fn->Env);
      v76.T.Type = 0;
      ImageSubstitutor = Scaleform::GFx::TextField::CreateImageSubstitutor(pDispObj);
      if ( !ImageSubstitutor )
      {
LABEL_81:
        if ( v76.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v76);
        return;
      }
      v9 = 0i64;
      pbuff.pImageDesc.pObject = 0i64;
      p_StringContext = &fn->Env->StringContext;
      v11 = &v8->Scaleform::GFx::AS2::ObjectInterface;
      v12 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(p_StringContext, &result, "subString");
      v13 = v11->vfptr->GetMemberRaw(v11, p_StringContext, v12, &v76);
      pNode = result.pNode;
      v15 = result.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( !v13 )
      {
        Name = Scaleform::GFx::AS3::AvmDisplayObj::GetName(this, &result);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          &v7->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
          "%s.setImageSubstitutions() failed for #%d element - subString should be specified",
          Name->pNode->pData,
          idx);
LABEL_77:
        v73 = result.pNode;
        v15 = result.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v73);
LABEL_79:
        if ( pbuff.pImageDesc.pObject )
          Scaleform::RefCountNTSImpl::Release(pbuff.pImageDesc.pObject);
        goto LABEL_81;
      }
      Scaleform::GFx::AS2::Value::ToString(&v76, &result, fn->Env, -1);
      Length = Scaleform::GFx::ASConstString::GetLength(&result);
      if ( Length > 0xF )
      {
        v17 = Scaleform::GFx::AS3::AvmDisplayObj::GetName(this, &v74);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          &v7->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
          "%s.setImageSubstitutions() failed for #%d element - length of subString should not exceed 15 characters",
          v17->pNode->pData,
          idx);
        v18 = v74.pNode;
        v15 = v74.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        goto LABEL_77;
      }
      Scaleform::UTF8Util::DecodeStringSafe(pbuff.SubString, 0x14ui64, result.pNode->pData, result.pNode->Size + 1);
      pbuff.SubStringLen = Length;
      v19 = result.pNode;
      v15 = result.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      v20 = 0.0;
      v21 = 0.0;
      v22 = 0.0;
      v23 = 0.0;
      v24 = 0.0;
      v81 = 0i64;
      ExecuteForEachChild_GC = 0i64;
      v74.pNode = 0i64;
      v26 = &fn->Env->StringContext;
      v27 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v26, &result, "image");
      v28 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, _QWORD))v11->vfptr->GetMemberRaw)(
              v11,
              v26,
              v27,
              &v76,
              0i64);
      v29 = result.pNode;
      v15 = result.pNode->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      if ( !v28 )
        goto LABEL_72;
      v30 = Scaleform::GFx::AS2::Value::ToObject(&v76, fn->Env);
      v31 = v30;
      if ( !v30
        || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v30->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v30->Scaleform::GFx::AS2::ObjectInterface) != 26 )
      {
        goto LABEL_72;
      }
      vfptr = v31[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr;
      v32 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))this->pDispObj->Scaleform::GFx::AS2::AvmCharacter::vfptr[66].__vecDelDtor)(this->pDispObj);
      v33 = (__int64)v32;
      if ( v32 )
        Scaleform::Render::RenderBuffer::AddRef(v32);
      pHeap = (Scaleform::MemoryHeap *)v33;
      if ( (*(unsigned int (__fastcall **)(void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)))(*(_QWORD *)vfptr[1].ExecuteForEachChild_GC + 24i64))(vfptr[1].ExecuteForEachChild_GC) )
      {
        ExecuteForEachChild_GC = (Scaleform::GFx::ASStringNode *)vfptr[1].ExecuteForEachChild_GC;
        if ( ExecuteForEachChild_GC )
          (*((void (__fastcall **)(void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)))ExecuteForEachChild_GC->pData
           + 1))(vfptr[1].ExecuteForEachChild_GC);
        v74.pNode = ExecuteForEachChild_GC;
      }
      else
      {
        v34 = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)(v33 + 24), &v78)->pObject == 0i64;
        LOBYTE(result.pNode) = v34;
        if ( v78.pObject )
        {
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v78.pObject);
          v34 = (char)result.pNode;
        }
        if ( v34 )
        {
          LODWORD(result.pNode) = 135168;
          Scaleform::LogDebugMessage(
            (Scaleform::LogMessageId)&result,
            "ImageCreator is null in ProceedImageSubstitution");
LABEL_37:
          if ( v33 )
            Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v33);
          if ( ExecuteForEachChild_GC )
          {
            v39 = &fn->Env->StringContext;
            v40 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v39, &result, "width");
            v41 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::ASStringNode *))v11->vfptr->GetMemberRaw)(
                    v11,
                    v39,
                    v40,
                    &v76,
                    v74.pNode);
            v42 = result.pNode;
            v15 = result.pNode->RefCount-- == 1;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v42);
            if ( v41 )
              v21 = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env) * 20.0;
            v43 = &fn->Env->StringContext;
            v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v43, &result, "height");
            v45 = v11->vfptr->GetMemberRaw(v11, v43, v44, &v76);
            v46 = result.pNode;
            v15 = result.pNode->RefCount-- == 1;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v46);
            if ( v45 )
              v22 = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env) * 20.0;
            v47 = &fn->Env->StringContext;
            v48 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v47, &result, "baseLineX");
            v49 = v11->vfptr->GetMemberRaw(v11, v47, v48, &v76);
            v50 = result.pNode;
            v15 = result.pNode->RefCount-- == 1;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v50);
            if ( v49 )
              v20 = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env) * 20.0;
            v51 = &fn->Env->StringContext;
            v52 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v51, &result, "baseLineY");
            v53 = v11->vfptr->GetMemberRaw(v11, v51, v52, &v76);
            v54 = result.pNode;
            v15 = result.pNode->RefCount-- == 1;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v54);
            if ( v53 )
              v55 = Scaleform::GFx::AS2::Value::ToNumber(&v76, fn->Env) * 20.0;
            else
              v55 = v24 - 20.0;
            v56 = &fn->Env->StringContext;
            v57 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v56, &result, "id");
            v58 = v11->vfptr->GetMemberRaw(v11, v56, v57, &v76);
            v59 = result.pNode;
            v15 = result.pNode->RefCount-- == 1;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v59);
            if ( v58 )
            {
              pData = Scaleform::GFx::AS2::Value::ToString(&v76, &result, fn->Env, -1)->pNode->pData;
              v59 = result.pNode;
              v15 = result.pNode->RefCount-- == 1;
              if ( v15 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v59);
            }
            else
            {
              pData = (const char *)v81;
            }
            pHeap = fn->Env->StringContext.pContext->pHeap;
            v61 = (Scaleform::Render::Text::ImageDesc *)((__int64 (__fastcall *)(Scaleform::GFx::ASStringNode *, __int64))pHeap->vfptr->Alloc)(
                                                          v59,
                                                          80i64);
            v81 = v61;
            if ( v61 )
            {
              Scaleform::Render::Text::ImageDesc::ImageDesc(v61);
              v9 = v62;
            }
            if ( pbuff.pImageDesc.pObject )
              Scaleform::RefCountNTSImpl::Release(pbuff.pImageDesc.pObject);
            pbuff.pImageDesc.pObject = v9;
            (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))ExecuteForEachChild_GC->pData + 1))(ExecuteForEachChild_GC);
            pObject = v9->pImage.pObject;
            if ( pObject )
              ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[2].__vecDelDtor)(pObject);
            v9->pImage.pObject = (Scaleform::Render::Image *)ExecuteForEachChild_GC;
            pbuff.pImageDesc.pObject->BaseLineX = v20 * 0.050000001;
            pbuff.pImageDesc.pObject->BaseLineY = v55 * 0.050000001;
            pbuff.pImageDesc.pObject->ScreenWidth = v21;
            pbuff.pImageDesc.pObject->ScreenHeight = v22;
            v64 = pDispObj;
            if ( pData )
              Scaleform::GFx::TextField::AddIdImageDescAssoc(pDispObj, pData, pbuff.pImageDesc.pObject);
            v65 = pbuff.pImageDesc.pObject;
            v66 = LODWORD(pbuff.pImageDesc.pObject->BaseLineY) ^ _xmm[0];
            pbuff.pImageDesc.pObject->Matrix.M[0][3] = COERCE_FLOAT(LODWORD(pbuff.pImageDesc.pObject->BaseLineX) ^ _xmm[0])
                                                     + pbuff.pImageDesc.pObject->Matrix.M[0][3];
            v65->Matrix.M[1][3] = *(float *)&v66 + v65->Matrix.M[1][3];
            v67 = (float *)pbuff.pImageDesc.pObject;
            v68 = pbuff.pImageDesc.pObject->ScreenHeight / v24;
            v69 = pbuff.pImageDesc.pObject->ScreenWidth / v23;
            pbuff.pImageDesc.pObject->Matrix.M[0][0] = v69 * pbuff.pImageDesc.pObject->Matrix.M[0][0];
            v67[13] = v69 * v67[13];
            v67[14] = v69 * v67[14];
            v67[15] = v69 * v67[15];
            v67[16] = v68 * v67[16];
            v67[17] = v68 * v67[17];
            v67[18] = v68 * v67[18];
            v67[19] = v68 * v67[19];
            Scaleform::Render::Text::DocView::ImageSubstitutor::AddImageDesc(ImageSubstitutor, &pbuff);
            v64->pDocument.pObject->RTFlags |= 2u;
            Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)this->pDispObj);
            (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))ExecuteForEachChild_GC->pData + 2))(ExecuteForEachChild_GC);
            goto LABEL_79;
          }
LABEL_72:
          v70 = Scaleform::GFx::AS3::AvmDisplayObj::GetName(this, &result);
          Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
            &pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
            "%s.setImageSubstitutions() failed for #%d element - image is not specified or not a BitmapData",
            v70->pNode->pData,
            idx);
          v71 = result.pNode;
          v15 = result.pNode->RefCount-- == 1;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v71);
          goto LABEL_74;
        }
        v35 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, this);
        v85 = 3;
        v86 = v35;
        v87 = 1;
        v88 = 1;
        v89 = 0i64;
        v90 = 0i64;
        v91 = 0i64;
        v92 = 0i64;
        ImageCreator = Scaleform::GFx::StateBag::GetImageCreator(
                         (Scaleform::GFx::StateBag *)(v33 + 24),
                         (Scaleform::Ptr<Scaleform::GFx::ImageCreator> *)&result);
        ExecuteForEachChild_GC = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, _QWORD))ImageCreator->pObject->vfptr[4].__vecDelDtor)(
                                                                   ImageCreator->pObject,
                                                                   &v85,
                                                                   vfptr[1].ExecuteForEachChild_GC);
        v74.pNode = ExecuteForEachChild_GC;
        if ( result.pNode )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pNode);
      }
      if ( ExecuteForEachChild_GC )
      {
        (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::Ptr<Scaleform::GFx::ImageCreator> *))ExecuteForEachChild_GC->pData
         + 6))(
          ExecuteForEachChild_GC,
          &v78);
        v23 = (float)(v79 - LODWORD(v78.pObject));
        v24 = (float)(v80 - HIDWORD(v78.pObject));
        v21 = v23 * 20.0;
        v22 = v24 * 20.0;
        if ( v23 == 0.0 || v24 == 0.0 )
        {
          v37 = Scaleform::GFx::AS3::AvmDisplayObj::GetName(this, &result);
          Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
            &pDispObj->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
            "%s.setImageSubstitutions() failed for #%d element - image has one zero dimension",
            v37->pNode->pData,
            idx);
          v38 = result.pNode;
          v15 = result.pNode->RefCount-- == 1;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v38);
          if ( v33 )
            Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v33);
LABEL_74:
          if ( ExecuteForEachChild_GC )
            (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))ExecuteForEachChild_GC->pData + 2))(ExecuteForEachChild_GC);
          goto LABEL_79;
        }
      }
      goto LABEL_37;
    }
  }
}

// File Line: 1803
// RVA: 0x6BAE10
void __fastcall Scaleform::GFx::AS2::AvmTextField::SetImageSubstitutions(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  int v5; // esi
  Scaleform::GFx::TextField *v6; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rbp
  Scaleform::GFx::AS2::Value *v9; // r8
  Scaleform::GFx::AS2::Value *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // r14
  __int64 v13; // rbp
  __int64 RootIndex; // r15
  Scaleform::GFx::AS2::Value *v15; // rax
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v4 = fn->ThisPtr;
    v5 = 0;
    v6 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) - 2 > 3
       ? 0i64
       : (Scaleform::GFx::TextField *)v4[1].vfptr;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v9 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      if ( v9->T.Type == 1 )
      {
        Scaleform::GFx::TextField::ClearIdImageDescAssoc(v6);
        Scaleform::GFx::TextField::ClearImageSubstitutor(v6);
        v6->pDocument.pObject->RTFlags |= 2u;
        Scaleform::GFx::TextField::SetDirtyFlag(v6);
      }
      else
      {
        v10 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v11 = Scaleform::GFx::AS2::Value::ToObject(v10, Env);
        v12 = v11;
        if ( v11 )
        {
          if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v11->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v11->Scaleform::GFx::AS2::ObjectInterface) == 7 )
          {
            v13 = 0i64;
            RootIndex = (int)v12[1].RootIndex;
            if ( RootIndex > 0 )
            {
              do
                Scaleform::GFx::AS2::AvmTextField::ProceedImageSubstitution(
                  (Scaleform::GFx::AS2::AvmTextField *)((char *)v6 + 4 * (unsigned __int8)v6->AvmObjOffset),
                  fn,
                  v5++,
                  (Scaleform::GFx::AS2::Value *)(&v12[1].pRCC->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::$8D47FECC8062B48992CD8F53EA11C4BE::vfptr)[v13++]);
              while ( v13 < RootIndex );
            }
          }
          else
          {
            v15 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
            Scaleform::GFx::AS2::AvmTextField::ProceedImageSubstitution(
              (Scaleform::GFx::AS2::AvmTextField *)((char *)v6 + 4 * (unsigned __int8)v6->AvmObjOffset),
              fn,
              0,
              v15);
          }
        }
        else
        {
          Name = Scaleform::GFx::DisplayObject::GetName(v6, &result);
          Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
            &v6->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
            "%s.setImageSubstitutions() failed: parameter should be either null, object or array",
            Name->pNode->pData);
          pNode = result.pNode;
          if ( result.pNode->RefCount-- == 1 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        }
      }
    }
  }
}

// File Line: 1851
// RVA: 0x6BB550
void __fastcall Scaleform::GFx::AS2::AvmTextField::UpdateImageSubstitution(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdi
  __int64 ExecuteForEachChild_GC; // rbx
  Scaleform::GFx::TextField *v6; // r15
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *pImageDescAssoc; // r14
  unsigned __int64 v11; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // r13
  __int64 v13; // r14
  __int64 v14; // r11
  __int64 *v15; // r10
  unsigned __int8 *v16; // rax
  int v17; // ecx
  int v18; // r8d
  __int64 v19; // r11
  Scaleform::Render::Text::ImageDesc **p_SizeMask; // r14
  Scaleform::Render::Text::ImageDesc *v21; // r14
  char Type; // cl
  Scaleform::GFx::AS2::Value *v23; // rax
  Scaleform::GFx::AS2::Object *v24; // rax
  Scaleform::GFx::AS2::Object *v25; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *vfptr; // rsi
  Scaleform::GFx::Resource *v27; // rax
  __int64 v28; // rdi
  bool v29; // r12
  Scaleform::MemoryHeap *v30; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *ImageCreator; // rax
  Scaleform::Render::Image *pObject; // rcx
  Scaleform::Render::Text::DocView::ImageSubstitutor *ImageSubstitutor; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v36; // [rsp+20h] [rbp-49h] BYREF
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v37; // [rsp+28h] [rbp-41h] BYREF
  __int64 v38; // [rsp+30h] [rbp-39h]
  __int64 v39; // [rsp+38h] [rbp-31h]
  int v40; // [rsp+40h] [rbp-29h] BYREF
  Scaleform::MemoryHeap *v41; // [rsp+48h] [rbp-21h]
  int v42; // [rsp+50h] [rbp-19h]
  int v43; // [rsp+54h] [rbp-15h]
  __int64 v44; // [rsp+58h] [rbp-11h]
  __int64 v45; // [rsp+60h] [rbp-9h]
  __int64 v46; // [rsp+68h] [rbp-1h]
  __int64 v47; // [rsp+70h] [rbp+7h]
  Scaleform::LogMessageId id; // [rsp+D0h] [rbp+67h] BYREF
  Scaleform::String v49; // [rsp+D8h] [rbp+6Fh] BYREF
  Scaleform::GFx::ASString result; // [rsp+E0h] [rbp+77h] BYREF
  __int64 v51; // [rsp+E8h] [rbp+7Fh]

  v38 = -2i64;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v4 = fn->ThisPtr;
    ExecuteForEachChild_GC = 0i64;
    v6 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v4) - 2 > 3
       ? 0i64
       : (Scaleform::GFx::TextField *)v4[1].vfptr;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v9 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v9, &result, Env, -1);
      pImageDescAssoc = v6->pImageDescAssoc;
      if ( pImageDescAssoc )
      {
        Scaleform::String::String(&v49, result.pNode->pData);
        if ( !pImageDescAssoc->mHash.pTable )
          goto LABEL_22;
        v11 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v49.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v49.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64);
        pTable = pImageDescAssoc->mHash.pTable;
        v13 = v11 & pImageDescAssoc->mHash.pTable->SizeMask;
        v14 = v13;
        v15 = (__int64 *)&pTable[2 * v13 + 1];
        if ( *v15 == -2 || v15[1] != v13 )
          goto LABEL_22;
        while ( 1 )
        {
          if ( v15[1] == v13 )
          {
            v16 = (unsigned __int8 *)((v15[2] & 0xFFFFFFFFFFFFFFFCui64) + 12);
            do
            {
              v17 = v16[(v49.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (v15[2] & 0xFFFFFFFFFFFFFFFCui64)];
              v18 = *v16 - v17;
              if ( v18 )
                break;
              ++v16;
            }
            while ( v17 );
            if ( !v18 )
              break;
          }
          v14 = *v15;
          if ( *v15 == -1 )
            goto LABEL_22;
          v15 = (__int64 *)&pTable[2 * v14 + 1];
        }
        if ( v14 < 0
          || (v19 = 2 * (v14 + 1),
              p_SizeMask = (Scaleform::Render::Text::ImageDesc **)&pTable[v19].SizeMask,
              !&pTable[v19]) )
        {
LABEL_22:
          p_SizeMask = 0i64;
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v49.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( p_SizeMask )
        {
          v21 = *p_SizeMask;
          if ( fn->NArgs >= 2 )
          {
            if ( Scaleform::GFx::AS2::FnCall::Arg(fn, 1)->T.Type == 1
              || (Type = Scaleform::GFx::AS2::FnCall::Arg(fn, 1)->T.Type) == 0
              || Type == 10 )
            {
              ImageSubstitutor = Scaleform::GFx::TextField::CreateImageSubstitutor(v6);
              if ( ImageSubstitutor )
              {
                Scaleform::Render::Text::DocView::ImageSubstitutor::RemoveImageDesc(ImageSubstitutor, v21);
                v6->pDocument.pObject->RTFlags |= 2u;
                Scaleform::GFx::TextField::RemoveIdImageDescAssoc(v6, result.pNode->pData);
                Scaleform::GFx::TextField::SetDirtyFlag(v6);
              }
            }
            else
            {
              v23 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
              v24 = Scaleform::GFx::AS2::Value::ToObject(v23, fn->Env);
              v25 = v24;
              if ( v24
                && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v24->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v24->Scaleform::GFx::AS2::ObjectInterface) == 26 )
              {
                vfptr = v25[1].Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr;
                v27 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v6->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(v6);
                v28 = (__int64)v27;
                if ( v27 )
                  Scaleform::Render::RenderBuffer::AddRef(v27);
                v39 = v28;
                v51 = 0i64;
                if ( (*(unsigned int (__fastcall **)(void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)))(*(_QWORD *)vfptr[1].ExecuteForEachChild_GC + 24i64))(vfptr[1].ExecuteForEachChild_GC) )
                {
                  ExecuteForEachChild_GC = (__int64)vfptr[1].ExecuteForEachChild_GC;
                  if ( ExecuteForEachChild_GC )
                    (*(void (__fastcall **)(void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)))(*(_QWORD *)ExecuteForEachChild_GC + 8i64))(vfptr[1].ExecuteForEachChild_GC);
                  v51 = ExecuteForEachChild_GC;
                }
                else
                {
                  v29 = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)(v28 + 24), &v36)->pObject == 0i64;
                  if ( v36.pObject )
                    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v36.pObject);
                  if ( v29 )
                  {
                    id.Id = 135168;
                    Scaleform::LogDebugMessage(
                      (Scaleform::LogMessageId)&id,
                      "ImageCreator is null in UpdateImageSubstitution");
                  }
                  else
                  {
                    v30 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v6);
                    v40 = 3;
                    v41 = v30;
                    v42 = 1;
                    v43 = 1;
                    v44 = 0i64;
                    v45 = 0i64;
                    v46 = 0i64;
                    v47 = 0i64;
                    ImageCreator = Scaleform::GFx::StateBag::GetImageCreator(
                                     (Scaleform::GFx::StateBag *)(v28 + 24),
                                     &v37);
                    ExecuteForEachChild_GC = ((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, _QWORD))ImageCreator->pObject->vfptr[4].__vecDelDtor)(
                                               ImageCreator->pObject,
                                               &v40,
                                               vfptr[1].ExecuteForEachChild_GC);
                    v51 = ExecuteForEachChild_GC;
                    if ( v37.pObject )
                      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v37.pObject);
                  }
                }
                if ( ExecuteForEachChild_GC )
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)ExecuteForEachChild_GC + 8i64))(ExecuteForEachChild_GC);
                pObject = v21->pImage.pObject;
                if ( pObject )
                  ((void (__fastcall *)(Scaleform::Render::Image *))pObject->vfptr[2].__vecDelDtor)(pObject);
                v21->pImage.pObject = (Scaleform::Render::Image *)ExecuteForEachChild_GC;
                Scaleform::GFx::TextField::SetDirtyFlag(v6);
                if ( ExecuteForEachChild_GC )
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)ExecuteForEachChild_GC + 16i64))(ExecuteForEachChild_GC);
                if ( v28 )
                  Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v28);
              }
            }
          }
        }
      }
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 1916
// RVA: 0x6B84E0
void __fastcall Scaleform::GFx::AS2::AvmTextField::SetTextFormat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::TextField *v4; // rsi
  int NArgs; // eax
  Scaleform::GFx::AS2::Value *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rbx
  Scaleform::GFx::AS2::Value *v9; // rax
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rbp
  Scaleform::GFx::AS2::Value *v12; // rax
  double v13; // xmm0_8
  Scaleform::GFx::AS2::Value *v14; // rax
  Scaleform::GFx::AS2::Object *v15; // rax
  Scaleform::GFx::AS2::Object *v16; // rbp
  Scaleform::GFx::AS2::Value *v17; // rax
  double v18; // xmm6_8
  double v19; // xmm7_8
  Scaleform::GFx::AS2::Value *v20; // rax
  double v21; // xmm0_8

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : (Scaleform::GFx::TextField *)v3[1].vfptr;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) )
    {
      NArgs = fn->NArgs;
      if ( NArgs == 1 )
      {
        v6 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v7 = Scaleform::GFx::AS2::Value::ToObject(v6, fn->Env);
        v8 = v7;
        if ( v7 )
        {
          if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v7->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v7->Scaleform::GFx::AS2::ObjectInterface) == 30 )
          {
            Scaleform::Render::Text::DocView::SetTextFormat(
              v4->pDocument.pObject,
              (Scaleform::Render::Text::TextFormat *)&v8[1],
              0i64,
              0xFFFFFFFFFFFFFFFFui64);
            Scaleform::Render::Text::DocView::SetParagraphFormat(
              v4->pDocument.pObject,
              (Scaleform::Render::Text::ParagraphFormat *)&v8[1].pWatchpoints,
              0i64,
              0xFFFFFFFFFFFFFFFFui64);
            Scaleform::GFx::TextField::SetDirtyFlag(v4);
          }
        }
      }
      else if ( NArgs == 2 )
      {
        v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v10 = Scaleform::GFx::AS2::Value::ToObject(v9, fn->Env);
        v11 = v10;
        if ( v10 )
        {
          if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v10->Scaleform::GFx::AS2::ObjectInterface) == 30 )
          {
            v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
            v13 = Scaleform::GFx::AS2::Value::ToNumber(v12, fn->Env);
            if ( v13 >= 0.0 )
            {
              Scaleform::Render::Text::DocView::SetTextFormat(
                v4->pDocument.pObject,
                (Scaleform::Render::Text::TextFormat *)&v11[1],
                (unsigned int)(int)v13,
                (unsigned int)((int)v13 + 1));
              Scaleform::Render::Text::DocView::SetParagraphFormat(
                v4->pDocument.pObject,
                (Scaleform::Render::Text::ParagraphFormat *)&v11[1].pWatchpoints,
                (unsigned int)(int)v13,
                (unsigned int)((int)v13 + 1));
              Scaleform::GFx::TextField::SetDirtyFlag(v4);
            }
          }
        }
      }
      else if ( NArgs >= 3 )
      {
        v14 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        v15 = Scaleform::GFx::AS2::Value::ToObject(v14, fn->Env);
        v16 = v15;
        if ( v15 )
        {
          if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v15->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v15->Scaleform::GFx::AS2::ObjectInterface) == 30 )
          {
            v17 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
            v18 = 0.0;
            v19 = Scaleform::GFx::AS2::Value::ToNumber(v17, fn->Env);
            if ( v19 < 0.0 )
              v19 = 0.0;
            v20 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
            v21 = Scaleform::GFx::AS2::Value::ToNumber(v20, fn->Env);
            if ( v21 >= 0.0 )
              v18 = v21;
            if ( v19 <= v18 )
            {
              Scaleform::Render::Text::DocView::SetTextFormat(
                v4->pDocument.pObject,
                (Scaleform::Render::Text::TextFormat *)&v16[1],
                (unsigned int)(int)v19,
                (unsigned int)(int)v18);
              Scaleform::Render::Text::DocView::SetParagraphFormat(
                v4->pDocument.pObject,
                (Scaleform::Render::Text::ParagraphFormat *)&v16[1].pWatchpoints,
                (unsigned int)(int)v19,
                (unsigned int)(int)v18);
              Scaleform::GFx::TextField::SetDirtyFlag(v4);
            }
          }
        }
      }
    }
  }
}

// File Line: 1982
// RVA: 0x6B8960
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetTextFormat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::TextFormatObject *v4; // rdi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *vfptr; // r14
  unsigned __int64 v6; // rbp
  unsigned __int64 endPos; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v10; // r9
  double v11; // xmm0_8
  int NArgs; // eax
  unsigned int v13; // r9d
  Scaleform::GFx::AS2::Environment *v14; // rdx
  Scaleform::GFx::AS2::Value *v15; // r10
  double v16; // xmm0_8
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::MemoryHeap *v18; // rcx
  Scaleform::GFx::AS2::TextFormatObject *v19; // rax
  Scaleform::GFx::AS2::TextFormatObject *v20; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::Render::Text::ParagraphFormat pdestParaFmt; // [rsp+30h] [rbp-A8h] BYREF
  __int64 v24; // [rsp+58h] [rbp-80h]
  Scaleform::Render::Text::TextFormat pdestTextFmt; // [rsp+60h] [rbp-78h] BYREF

  v24 = -2i64;
  ThisPtr = fn->ThisPtr;
  if ( !ThisPtr
    || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) != 4 )
  {
    goto LABEL_28;
  }
  v3 = fn->ThisPtr;
  v4 = 0i64;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3 )
    vfptr = 0i64;
  else
    vfptr = v3[1].vfptr;
  v6 = 0i64;
  endPos = -1i64;
  if ( fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    Env = fn->Env;
    v10 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v10 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v11 = Scaleform::GFx::AS2::Value::ToNumber(v10, Env);
    if ( v11 < 0.0 )
      v11 = 0.0;
    v6 = (unsigned int)(int)v11;
  }
  NArgs = fn->NArgs;
  if ( NArgs < 2 )
  {
    if ( NArgs < 1 )
      goto LABEL_21;
    v17 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
    v16 = Scaleform::GFx::AS2::Value::ToNumber(v17, fn->Env) + 1.0;
  }
  else
  {
    v13 = fn->FirstArgBottomIndex - 1;
    v14 = fn->Env;
    v15 = 0i64;
    if ( v13 <= 32 * ((unsigned int)v14->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v14->Stack.pCurrent - v14->Stack.pPageStart) )
      v15 = &v14->Stack.Pages.Data.Data[v13 >> 5]->Values[v13 & 0x1F];
    v16 = Scaleform::GFx::AS2::Value::ToNumber(v15, v14);
  }
  if ( v16 < 0.0 )
    v16 = 0.0;
  endPos = (unsigned int)(int)v16;
LABEL_21:
  if ( v6 > endPos )
  {
LABEL_28:
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 0;
    return;
  }
  Scaleform::Render::Text::TextFormat::TextFormat(&pdestTextFmt, fn->Env->StringContext.pContext->pHeap);
  pdestParaFmt.pAllocator = 0i64;
  pdestParaFmt.RefCount = 1;
  memset(&pdestParaFmt.pTabStops, 0, 20);
  Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
    *((Scaleform::Render::Text::StyledText **)vfptr[1].SetMemberFlags + 2),
    &pdestTextFmt,
    &pdestParaFmt,
    v6,
    endPos);
  v19 = (Scaleform::GFx::AS2::TextFormatObject *)fn->Env->StringContext.pContext->pHeap->vfptr->Alloc(v18, 216i64, 0i64);
  if ( v19 )
  {
    Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(v19, fn->Env);
    v4 = v20;
  }
  Scaleform::GFx::AS2::TextFormatObject::SetTextFormat(v4, &fn->Env->StringContext, &pdestTextFmt);
  Scaleform::GFx::AS2::TextFormatObject::SetParagraphFormat(v4, &fn->Env->StringContext, &pdestParaFmt);
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
  if ( v4 )
  {
    RefCount = v4->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v4->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
  Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&pdestParaFmt);
  Scaleform::Render::Text::TextFormat::~TextFormat(&pdestTextFmt);
}

// File Line: 2031
// RVA: 0x6B8CB0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetNewTextFormat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::TextFormatObject *v4; // rbx
  Scaleform::MemoryHeap *vfptr; // rcx
  __int64 v6; // rax
  Scaleform::Render::Text::TextFormat *v7; // rsi
  Scaleform::Render::Text::ParagraphFormat *v8; // rbp
  Scaleform::GFx::AS2::TextFormatObject *v9; // rax
  Scaleform::GFx::AS2::TextFormatObject *v10; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3 )
      vfptr = 0i64;
    else
      vfptr = (Scaleform::MemoryHeap *)v3[1].vfptr;
    v6 = *(_QWORD *)(vfptr[1].SelfSize + 16);
    v7 = *(Scaleform::Render::Text::TextFormat **)(v6 + 56);
    v8 = *(Scaleform::Render::Text::ParagraphFormat **)(v6 + 48);
    v9 = (Scaleform::GFx::AS2::TextFormatObject *)fn->Env->StringContext.pContext->pHeap->vfptr->Alloc(
                                                    vfptr,
                                                    216i64,
                                                    0i64);
    if ( v9 )
    {
      Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(v9, fn->Env);
      v4 = v10;
    }
    if ( v7 )
      Scaleform::GFx::AS2::TextFormatObject::SetTextFormat(v4, &fn->Env->StringContext, v7);
    if ( v8 )
      Scaleform::GFx::AS2::TextFormatObject::SetParagraphFormat(v4, &fn->Env->StringContext, v8);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
    if ( v4 )
    {
      RefCount = v4->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v4->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
      }
    }
  }
  else
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 0;
  }
}

// File Line: 2056
// RVA: 0x6B8790
void __fastcall Scaleform::GFx::AS2::AvmTextField::SetNewTextFormat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::TextField *vfptr; // rdi
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::GFx::AS2::Object *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rsi
  Scaleform::Render::Text::DocView::DocumentText *pObject; // rax
  Scaleform::Render::Text::ParagraphFormat *v9; // rbx
  Scaleform::Render::Text::TextFormat *v10; // rax
  Scaleform::Render::Text::ParagraphFormat *v11; // rax
  Scaleform::Render::Text::TextFormat result; // [rsp+28h] [rbp-60h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3 )
      vfptr = 0i64;
    else
      vfptr = (Scaleform::GFx::TextField *)v3[1].vfptr;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(vfptr) && fn->NArgs >= 1 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v6 = Scaleform::GFx::AS2::Value::ToObject(v5, fn->Env);
      v7 = v6;
      if ( v6 )
      {
        if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v6->Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v6->Scaleform::GFx::AS2::ObjectInterface) == 30 )
        {
          pObject = vfptr->pDocument.pObject->pDocument.pObject;
          v9 = pObject->pDefaultParagraphFormat.pObject;
          v10 = Scaleform::Render::Text::TextFormat::Merge(
                  pObject->pDefaultTextFormat.pObject,
                  &result,
                  (Scaleform::Render::Text::TextFormat *)&v7[1]);
          Scaleform::Render::Text::StyledText::SetDefaultTextFormat(vfptr->pDocument.pObject->pDocument.pObject, v10);
          vfptr->Flags |= 0x10000u;
          Scaleform::Render::Text::TextFormat::~TextFormat(&result);
          v11 = Scaleform::Render::Text::ParagraphFormat::Merge(
                  v9,
                  (Scaleform::Render::Text::ParagraphFormat *)&result,
                  (Scaleform::Render::Text::ParagraphFormat *)&v7[1].pWatchpoints);
          Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
            vfptr->pDocument.pObject->pDocument.pObject,
            v11);
          vfptr->Flags |= 0x10000u;
          Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat((Scaleform::Render::Text::ParagraphFormat *)&result);
        }
      }
    }
  }
}

// File Line: 2085
// RVA: 0x6B91D0
void __fastcall Scaleform::GFx::AS2::AvmTextField::ReplaceText(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r15
  Scaleform::GFx::TextField *v4; // r15
  Scaleform::GFx::AS2::Value *v5; // rax
  double v6; // xmm6_8
  Scaleform::GFx::AS2::Value *v7; // rax
  double v8; // xmm7_8
  Scaleform::GFx::AS2::Value *v9; // rax
  unsigned int Length; // r14d
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // r12
  unsigned __int64 v15; // r13
  bool v16; // cf
  Scaleform::Render::Text::DocView *pObject; // rax
  Scaleform::Render::Text::TextFormat *v18; // rdi
  bool v19; // zf
  Scaleform::Render::Text::TextFormat *v20; // rbx
  __int64 v21; // rsi
  wchar_t *v22; // r14
  Scaleform::Render::Text::DocView *v23; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+30h] [rbp-90h] BYREF
  Scaleform::Render::Text::TextFormat *v26; // [rsp+38h] [rbp-88h]
  Scaleform::Render::Text::ParagraphFormat *ppdestParaFmt; // [rsp+40h] [rbp-80h] BYREF
  __int64 v28; // [rsp+48h] [rbp-78h]
  __int64 v29; // [rsp+50h] [rbp-70h]
  wchar_t pbuff[1024]; // [rsp+60h] [rbp-60h] BYREF
  unsigned int v31; // [rsp+890h] [rbp+7D0h]
  Scaleform::GFx::ASString result; // [rsp+898h] [rbp+7D8h] BYREF
  Scaleform::Render::Text::TextFormat *v33; // [rsp+8A0h] [rbp+7E0h]
  Scaleform::Render::Text::TextFormat *v34; // [rsp+8A8h] [rbp+7E8h]

  v29 = -2i64;
  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : (Scaleform::GFx::TextField *)v3[1].vfptr;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) && fn->NArgs >= 3 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, fn->Env);
      v7 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
      v8 = Scaleform::GFx::AS2::Value::ToNumber(v7, fn->Env);
      v9 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
      Scaleform::GFx::AS2::Value::ToString(v9, &result, fn->Env, -1);
      Length = Scaleform::GFx::ASConstString::GetLength(&result);
      v31 = Length;
      v11 = (int)v6;
      v28 = (unsigned int)(int)v6;
      v12 = (int)v8;
      if ( v6 >= 0.0 && v8 >= 0.0 && v11 <= v12 )
      {
        v33 = 0i64;
        v34 = 0i64;
        v13 = Scaleform::Render::Text::StyledText::GetLength(v4->pDocument.pObject->pDocument.pObject);
        v14 = v13 + Length - (unsigned __int64)(v12 - v11);
        v15 = v11;
        v16 = v11 < v13;
        pObject = v4->pDocument.pObject;
        if ( v16 )
        {
          Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
            pObject->pDocument.pObject,
            &ppdestTextFmt,
            &ppdestParaFmt,
            v11);
          v18 = ppdestTextFmt;
          v26 = 0i64;
          if ( ppdestTextFmt )
            ++ppdestTextFmt->RefCount;
          v26 = v18;
          if ( v18 )
            ++v18->RefCount;
          v33 = v18;
          if ( v18 )
          {
            v19 = v18->RefCount-- == 1;
            if ( v19 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v18);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
            }
          }
          v20 = (Scaleform::Render::Text::TextFormat *)ppdestParaFmt;
          v26 = 0i64;
          if ( ppdestParaFmt )
            ++ppdestParaFmt->RefCount;
          v26 = v20;
          if ( v20 )
            ++v20->RefCount;
          v34 = v20;
        }
        else
        {
          v18 = pObject->pDocument.pObject->pDefaultTextFormat.pObject;
          ppdestTextFmt = 0i64;
          if ( v18 )
            ++v18->RefCount;
          ppdestTextFmt = v18;
          if ( v18 )
            ++v18->RefCount;
          v33 = v18;
          if ( v18 )
          {
            v19 = v18->RefCount-- == 1;
            if ( v19 )
            {
              Scaleform::Render::Text::TextFormat::~TextFormat(v18);
              Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
            }
          }
          v20 = (Scaleform::Render::Text::TextFormat *)v4->pDocument.pObject->pDocument.pObject->pDefaultParagraphFormat.pObject;
          ppdestTextFmt = 0i64;
          if ( v20 )
            ++v20->RefCount;
          ppdestTextFmt = v20;
          if ( v20 )
            ++v20->RefCount;
          v34 = v20;
        }
        if ( v20 )
        {
          v19 = v20->RefCount-- == 1;
          if ( v19 )
          {
            Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat((Scaleform::Render::Text::ParagraphFormat *)v20);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v20);
          }
        }
        if ( Length >= 0x400 )
        {
          v21 = Length + 1;
          v22 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v21, 0i64);
          Scaleform::UTF8Util::DecodeStringSafe(v22, (unsigned int)v21, result.pNode->pData, -1i64);
          Scaleform::GFx::TextField::ReplaceText(v4, v22, v15, (unsigned int)(int)v8, 0xFFFFFFFFFFFFFFFFui64);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v22);
          v11 = v28;
          Length = v31;
        }
        else
        {
          Scaleform::UTF8Util::DecodeStringSafe(pbuff, 0x400ui64, result.pNode->pData, -1i64);
          Scaleform::GFx::TextField::ReplaceText(v4, pbuff, v11, (unsigned int)(int)v8, 0xFFFFFFFFFFFFFFFFui64);
        }
        v23 = v4->pDocument.pObject;
        if ( v23->pEditorKit.pObject
          && (unsigned __int64)hkDataArrayNative::getType((StructArrayImplementation *)v23->pEditorKit.pObject) > v14 )
        {
          Scaleform::GFx::Text::EditorKit::SetCursorPos(
            (Scaleform::GFx::Text::EditorKit *)v4->pDocument.pObject->pEditorKit.pObject,
            v14,
            0);
        }
        if ( v20 )
          Scaleform::Render::Text::DocView::SetParagraphFormat(
            v4->pDocument.pObject,
            (Scaleform::Render::Text::ParagraphFormat *)v20,
            v15,
            v11 + Length);
        if ( v18 )
          Scaleform::Render::Text::DocView::SetTextFormat(v4->pDocument.pObject, v18, v15, v11 + Length);
        Scaleform::GFx::TextField::SetDirtyFlag(v4);
        if ( v20 )
        {
          v19 = v20->RefCount-- == 1;
          if ( v19 )
          {
            Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat((Scaleform::Render::Text::ParagraphFormat *)v20);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v20);
          }
        }
        if ( v18 )
        {
          v19 = v18->RefCount-- == 1;
          if ( v19 )
          {
            Scaleform::Render::Text::TextFormat::~TextFormat(v18);
            Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
          }
        }
      }
      pNode = result.pNode;
      v19 = result.pNode->RefCount-- == 1;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 2165
// RVA: 0x6B8E80
void __fastcall Scaleform::GFx::AS2::AvmTextField::ReplaceSel(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::TextField *v4; // r14
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::Render::Text::TextFormat *pObject; // rsi
  Scaleform::Render::Text::ParagraphFormat *v7; // rbp
  unsigned int Length; // eax
  __int64 v9; // r13
  Scaleform::Render::Text::EditorKitBase *v10; // rcx
  Scaleform::RefCountImplCoreVtbl *vfptr; // rdx
  unsigned __int64 vecDelDtor; // r15
  Scaleform::RefCountImplCoreVtbl *v13; // rdx
  unsigned __int64 v14; // r12
  __int64 v15; // rbx
  wchar_t *v16; // rdi
  bool v17; // zf
  Scaleform::GFx::ASStringNode *pNode; // rcx
  wchar_t pbuff[1052]; // [rsp+40h] [rbp-838h] BYREF
  Scaleform::GFx::ASString result; // [rsp+880h] [rbp+8h] BYREF
  Scaleform::Render::Text::TextFormat *v21; // [rsp+888h] [rbp+10h]
  Scaleform::Render::Text::ParagraphFormat *v22; // [rsp+890h] [rbp+18h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : (Scaleform::GFx::TextField *)v3[1].vfptr;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) && fn->NArgs >= 1 && v4->pDocument.pObject->pEditorKit.pObject )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::ToString(v5, &result, fn->Env, -1);
      pObject = v4->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject;
      v21 = 0i64;
      if ( pObject )
        ++pObject->RefCount;
      v21 = pObject;
      v7 = v4->pDocument.pObject->pDocument.pObject->pDefaultParagraphFormat.pObject;
      v22 = 0i64;
      if ( v7 )
        ++v7->RefCount;
      v22 = v7;
      Length = Scaleform::GFx::ASConstString::GetLength(&result);
      v9 = Length;
      v10 = v4->pDocument.pObject->pEditorKit.pObject;
      vfptr = v10[1].vfptr;
      vecDelDtor = (unsigned __int64)vfptr[8].__vecDelDtor;
      if ( (char *)vfptr[7].__vecDelDtor < (char *)vecDelDtor )
        vecDelDtor = (unsigned __int64)vfptr[7].__vecDelDtor;
      v13 = v10[1].vfptr;
      v14 = (unsigned __int64)v13[8].__vecDelDtor;
      if ( (char *)v14 < (char *)v13[7].__vecDelDtor )
        v14 = (unsigned __int64)v13[7].__vecDelDtor;
      if ( Length >= 0x400 )
      {
        v15 = Length + 1;
        v16 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v15, 0i64);
        Scaleform::UTF8Util::DecodeStringSafe(v16, (unsigned int)v15, result.pNode->pData, -1i64);
        Scaleform::GFx::TextField::ReplaceText(v4, v16, vecDelDtor, v14, 0xFFFFFFFFFFFFFFFFui64);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
      else
      {
        Scaleform::UTF8Util::DecodeStringSafe(pbuff, 0x400ui64, result.pNode->pData, -1i64);
        Scaleform::GFx::TextField::ReplaceText(v4, pbuff, vecDelDtor, v14, 0xFFFFFFFFFFFFFFFFui64);
      }
      Scaleform::GFx::Text::EditorKit::SetCursorPos(
        (Scaleform::GFx::Text::EditorKit *)v4->pDocument.pObject->pEditorKit.pObject,
        vecDelDtor + v9,
        0);
      if ( v7 )
        Scaleform::Render::Text::DocView::SetParagraphFormat(v4->pDocument.pObject, v7, vecDelDtor, vecDelDtor + v9);
      if ( pObject )
        Scaleform::Render::Text::DocView::SetTextFormat(v4->pDocument.pObject, pObject, vecDelDtor, vecDelDtor + v9);
      Scaleform::GFx::TextField::SetDirtyFlag(v4);
      if ( v7 )
      {
        v17 = v7->RefCount-- == 1;
        if ( v17 )
        {
          Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(v7);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
        }
      }
      if ( pObject )
      {
        v17 = pObject->RefCount-- == 1;
        if ( v17 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(pObject);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
        }
      }
      pNode = result.pNode;
      v17 = result.pNode->RefCount-- == 1;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 2206
// RVA: 0x6B96E0
void __fastcall Scaleform::GFx::AS2::AvmTextField::RemoveTextField(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  Scaleform::GFx::InteractiveObject *vfptr; // rbx
  Scaleform::GFx::ASString *Name; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3 )
      vfptr = 0i64;
    else
      vfptr = (Scaleform::GFx::InteractiveObject *)v3[1].vfptr;
    if ( vfptr->Depth >= 0x4000 )
    {
      Scaleform::GFx::InteractiveObject::RemoveDisplayObject(vfptr);
    }
    else
    {
      Name = Scaleform::GFx::DisplayObject::GetName(vfptr, &result);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        &vfptr->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>,
        "%s.removeMovieClip() failed - depth must be >= 0",
        Name->pNode->pData);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 2223
// RVA: 0x6BBCD0
void __fastcall Scaleform::GFx::AS2::AvmTextField::AppendText(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::TextField *vfptr; // rdi
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3 )
      vfptr = 0i64;
    else
      vfptr = (Scaleform::GFx::TextField *)v3[1].vfptr;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(vfptr) && fn->NArgs >= 1 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::ToString(v5, &result, fn->Env, -1);
      Scaleform::Render::Text::DocView::AppendText(
        vfptr->pDocument.pObject,
        result.pNode->pData,
        0xFFFFFFFFFFFFFFFFui64);
      vfptr->Flags |= 0x10000u;
      Scaleform::GFx::TextField::SetDirtyFlag(vfptr);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 2240
// RVA: 0x6BBDA0
void __fastcall Scaleform::GFx::AS2::AvmTextField::AppendHtml(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  Scaleform::GFx::TextField *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::MemoryHeap *v6; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imageInfoArray; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *p_imageInfoArray; // [rsp+78h] [rbp+10h]

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : (Scaleform::GFx::TextField *)v3[1].vfptr;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) && fn->NArgs >= 1 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
      Scaleform::GFx::AS2::Value::ToString(v5, &result, fn->Env, -1);
      v6 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v4);
      p_imageInfoArray = &imageInfoArray;
      memset(&imageInfoArray, 0, 24);
      imageInfoArray.Data.pHeap = v6;
      Scaleform::Render::Text::DocView::AppendHtml(
        v4->pDocument.pObject,
        result.pNode->pData,
        0xFFFFFFFFFFFFFFFFui64,
        0,
        &imageInfoArray);
      v4->Flags |= 0x10000u;
      if ( imageInfoArray.Data.Size )
        Scaleform::GFx::TextField::ProcessImageTags(v4, &imageInfoArray);
      Scaleform::GFx::TextField::SetDirtyFlag(v4);
      p_imageInfoArray = &imageInfoArray;
      Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
        imageInfoArray.Data.Data,
        imageInfoArray.Data.Size);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, imageInfoArray.Data.Data);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    }
  }
}

// File Line: 2262
// RVA: 0x6B9820
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetCharBoundaries(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::RectangleObject *v4; // rdi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v5; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  unsigned int v9; // eax
  __int64 v10; // rcx
  Scaleform::GFx::AS2::RectangleObject *v11; // rax
  Scaleform::GFx::AS2::RectangleObject *v12; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::Render::Rect<float> pCharRect; // [rsp+30h] [rbp-38h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+40h] [rbp-28h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    v5 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : v3[1].vfptr;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v8 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToUInt32(v8, Env);
      pCharRect = 0i64;
      if ( Scaleform::Render::Text::DocView::GetCharBoundaries(
             (Scaleform::Render::Text::DocView *)v5[1].SetMemberFlags,
             &pCharRect,
             v9) )
      {
        v11 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                        v10,
                                                        96i64);
        if ( v11 )
        {
          Scaleform::GFx::AS2::RectangleObject::RectangleObject(v11, fn->Env);
          v4 = v12;
        }
        r.x1 = pCharRect.x1 * 0.05;
        r.y1 = pCharRect.y1 * 0.05;
        r.x2 = pCharRect.x2 * 0.05;
        r.y2 = pCharRect.y2 * 0.05;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(v4, fn->Env, &r);
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
        if ( v4 )
        {
          RefCount = v4->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v4->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
          }
        }
      }
      else
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 1;
      }
    }
  }
}

// File Line: 2304
// RVA: 0x6B9CA0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetExactCharBoundaries(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::RectangleObject *v4; // rdi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v5; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  unsigned int v9; // eax
  __int64 v10; // rcx
  Scaleform::GFx::AS2::RectangleObject *v11; // rax
  Scaleform::GFx::AS2::RectangleObject *v12; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::Render::Rect<float> pCharRect; // [rsp+30h] [rbp-38h] BYREF
  Scaleform::Render::Rect<double> r; // [rsp+40h] [rbp-28h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    v5 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : v3[1].vfptr;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v8 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToUInt32(v8, Env);
      pCharRect = 0i64;
      if ( Scaleform::Render::Text::DocView::GetExactCharBoundaries(
             (Scaleform::Render::Text::DocView *)v5[1].SetMemberFlags,
             &pCharRect,
             v9) )
      {
        v11 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                        v10,
                                                        96i64);
        if ( v11 )
        {
          Scaleform::GFx::AS2::RectangleObject::RectangleObject(v11, fn->Env);
          v4 = v12;
        }
        r.x1 = pCharRect.x1 * 0.05;
        r.y1 = pCharRect.y1 * 0.05;
        r.x2 = pCharRect.x2 * 0.05;
        r.y2 = pCharRect.y2 * 0.05;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(v4, fn->Env, &r);
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
        if ( v4 )
        {
          RefCount = v4->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v4->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
          }
        }
      }
      else
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 1;
      }
    }
  }
}

// File Line: 2345
// RVA: 0x6B9A80
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetCharIndexAtPoint(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v5; // rsi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v8; // r9
  double v9; // xmm0_8
  Scaleform::GFx::AS2::Environment *v10; // rdx
  unsigned __int64 v11; // r8
  float v12; // xmm1_4
  float v13; // xmm2_4
  __int64 CharIndexAtPoint; // rax
  double v15; // xmm1_8

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    v5 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : v3[1].vfptr;
    if ( fn->NArgs >= 2 )
    {
      Env = fn->Env;
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      v8 = 0i64;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToNumber(v8, Env);
      v10 = fn->Env;
      v11 = (unsigned int)(fn->FirstArgBottomIndex - 1);
      if ( (unsigned int)v11 <= 32 * (LODWORD(v10->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)(v10->Stack.pCurrent - v10->Stack.pPageStart) )
        v4 = &v10->Stack.Pages.Data.Data[v11 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
      v12 = v9 * 20.0;
      v13 = Scaleform::GFx::AS2::Value::ToNumber(v4, v10) * 20.0;
      CharIndexAtPoint = Scaleform::Render::Text::DocView::GetCharIndexAtPoint(
                           (Scaleform::Render::Text::DocView *)v5[1].SetMemberFlags,
                           v12,
                           v13);
      if ( CharIndexAtPoint == -1 )
      {
        v15 = DOUBLE_N1_0;
      }
      else
      {
        v15 = (double)(int)CharIndexAtPoint;
        if ( CharIndexAtPoint < 0 )
          v15 = v15 + 1.844674407370955e19;
      }
      Scaleform::GFx::AS2::Value::SetNumber(fn->Result, v15);
    }
  }
}

// File Line: 2364
// RVA: 0x6B9F00
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineIndexAtPoint(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::Value *v4; // rbx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v5; // rsi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v8; // r9
  double v9; // xmm0_8
  Scaleform::GFx::AS2::Environment *v10; // rdx
  unsigned __int64 v11; // r8
  float v12; // xmm1_4
  float v13; // xmm2_4
  int LineIndexAtPoint; // eax
  double v15; // xmm1_8

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    v5 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : v3[1].vfptr;
    if ( fn->NArgs >= 2 )
    {
      Env = fn->Env;
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      v8 = 0i64;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToNumber(v8, Env);
      v10 = fn->Env;
      v11 = (unsigned int)(fn->FirstArgBottomIndex - 1);
      if ( (unsigned int)v11 <= 32 * (LODWORD(v10->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)(v10->Stack.pCurrent - v10->Stack.pPageStart) )
        v4 = &v10->Stack.Pages.Data.Data[v11 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
      v12 = v9 * 20.0;
      v13 = Scaleform::GFx::AS2::Value::ToNumber(v4, v10) * 20.0;
      LineIndexAtPoint = Scaleform::Render::Text::DocView::GetLineIndexAtPoint(
                           (Scaleform::Render::Text::DocView *)v5[1].SetMemberFlags,
                           v12,
                           v13);
      if ( LineIndexAtPoint == -1 )
        v15 = DOUBLE_N1_0;
      else
        v15 = (double)LineIndexAtPoint;
      Scaleform::GFx::AS2::Value::SetNumber(fn->Result, v15);
    }
  }
}

// File Line: 2383
// RVA: 0x6BA250
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineOffset(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // r9
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v6; // rdi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  signed int v9; // edx
  __int64 LineOffset; // rax
  double v11; // xmm1_8

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3);
    v5 = 0i64;
    v6 = (unsigned int)(v4 - 2) > 3 ? 0i64 : v3[1].vfptr;
    if ( fn->NArgs >= 1 )
    {
      Env = fn->Env;
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
      v9 = (int)Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
      if ( v9 < 0
        || (LineOffset = Scaleform::Render::Text::DocView::GetLineOffset(
                           (Scaleform::Render::Text::DocView *)v6[1].SetMemberFlags,
                           v9),
            LineOffset == -1) )
      {
        v11 = DOUBLE_N1_0;
      }
      else
      {
        v11 = (double)(int)LineOffset;
        if ( LineOffset < 0 )
          v11 = v11 + 1.844674407370955e19;
      }
      Scaleform::GFx::AS2::Value::SetNumber(fn->Result, v11);
    }
  }
}

// File Line: 2406
// RVA: 0x6BA3E0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineLength(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // r9
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v6; // rdi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  signed int v9; // edx
  __int64 LineLength; // rax
  double v11; // xmm1_8

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3);
    v5 = 0i64;
    v6 = (unsigned int)(v4 - 2) > 3 ? 0i64 : v3[1].vfptr;
    if ( fn->NArgs >= 1 )
    {
      Env = fn->Env;
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
      v9 = (int)Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
      if ( v9 < 0
        || (LineLength = Scaleform::Render::Text::DocView::GetLineLength(
                           (Scaleform::Render::Text::DocView *)v6[1].SetMemberFlags,
                           v9,
                           0i64),
            LineLength == -1) )
      {
        v11 = DOUBLE_N1_0;
      }
      else
      {
        v11 = (double)(int)LineLength;
        if ( LineLength < 0 )
          v11 = v11 + 1.844674407370955e19;
      }
      Scaleform::GFx::AS2::Value::SetNumber(fn->Result, v11);
    }
  }
}

// File Line: 2429
// RVA: 0x6BA5C0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineMetrics(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rdi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v5; // rsi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  signed int v9; // edx
  __int64 v10; // rcx
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rax
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx
  Scaleform::Render::Text::DocView::LineMetrics pmetrics; // [rsp+28h] [rbp-48h] BYREF
  Scaleform::GFx::AS2::Value val; // [rsp+40h] [rbp-30h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    v5 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : v3[1].vfptr;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v8 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v8 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v9 = (int)Scaleform::GFx::AS2::Value::ToNumber(v8, Env);
      if ( v9 >= 0
        && Scaleform::Render::Text::DocView::GetLineMetrics(
             (Scaleform::Render::Text::DocView *)v5[1].SetMemberFlags,
             v9,
             &pmetrics) )
      {
        v11 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(__int64, __int64))fn->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                               v10,
                                               96i64);
        if ( v11 )
        {
          Scaleform::GFx::AS2::Object::Object(v11, fn->Env);
          v4 = v12;
        }
        val.T.Type = 3;
        val.NV.NumberValue = (double)(int)pmetrics.Ascent * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v4->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "ascent",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        val.T.Type = 3;
        val.NV.NumberValue = (double)(int)pmetrics.Descent * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v4->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "descent",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        val.T.Type = 3;
        val.NV.NumberValue = (double)(int)pmetrics.Width * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v4->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "width",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        val.T.Type = 3;
        val.NV.NumberValue = (double)(int)pmetrics.Height * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v4->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "height",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        val.T.Type = 3;
        val.NV.NumberValue = (double)pmetrics.Leading * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v4->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "leading",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        val.T.Type = 3;
        val.NV.NumberValue = (double)pmetrics.FirstCharXOff * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v4->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "x",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
        if ( v4 )
        {
          RefCount = v4->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v4->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
          }
        }
      }
      else
      {
        Result = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(Result);
        Result->T.Type = 0;
      }
    }
  }
}

// File Line: 2462
// RVA: 0x6BA9B0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineText(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v4; // rdi
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  Scaleform::GFx::AS2::Value *v7; // r9
  signed int v8; // edx
  Scaleform::GFx::AS2::Value *v9; // rbx
  const wchar_t *LineText; // rdi
  Scaleform::GFx::AS2::Value *v11; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::String str; // [rsp+58h] [rbp+10h] BYREF
  unsigned __int64 plen; // [rsp+60h] [rbp+18h] BYREF
  Scaleform::GFx::ASString v19; // [rsp+68h] [rbp+20h] BYREF

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : v3[1].vfptr;
    if ( fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v7 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v8 = (int)Scaleform::GFx::AS2::Value::ToNumber(v7, Env);
      if ( v8 >= 0 )
      {
        plen = 0i64;
        LineText = Scaleform::Render::Text::DocView::GetLineText(
                     (Scaleform::Render::Text::DocView *)v4[1].SetMemberFlags,
                     v8,
                     &plen);
        if ( LineText )
        {
          Scaleform::String::String(&str);
          Scaleform::String::AppendString(&str, LineText, plen);
          Scaleform::GFx::AS2::Environment::CreateString(fn->Env, &result, &str);
          v11 = fn->Result;
          if ( v11->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v11);
          v11->T.Type = 5;
          v11->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
          ++result.pNode->RefCount;
          pNode = result.pNode;
          v13 = result.pNode->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        else
        {
          v14 = Scaleform::GFx::AS2::Environment::CreateConstString(fn->Env, &v19, &customCaption);
          Scaleform::GFx::AS2::Value::SetString(fn->Result, v14);
          v15 = v19.pNode;
          v13 = v19.pNode->RefCount-- == 1;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      else
      {
        v9 = fn->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v9);
        v9->T.Type = 0;
      }
    }
  }
}

// File Line: 2492
// RVA: 0x6BAC30
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetFirstCharInParagraph(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // r9
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v6; // rdi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  int v9; // eax
  __int64 FirstCharInParagraph; // rax
  double v11; // xmm1_8

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3);
    v5 = 0i64;
    v6 = (unsigned int)(v4 - 2) > 3 ? 0i64 : v3[1].vfptr;
    if ( fn->NArgs >= 1 )
    {
      Env = fn->Env;
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
      v9 = (int)Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
      if ( v9 < 0
        || (FirstCharInParagraph = Scaleform::Render::Text::DocView::GetFirstCharInParagraph(
                                     (Scaleform::Render::Text::DocView *)v6[1].SetMemberFlags,
                                     (unsigned int)v9),
            FirstCharInParagraph == -1) )
      {
        v11 = DOUBLE_N1_0;
      }
      else
      {
        v11 = (double)(int)FirstCharInParagraph;
        if ( FirstCharInParagraph < 0 )
          v11 = v11 + 1.844674407370955e19;
      }
      Scaleform::GFx::AS2::Value::SetNumber(fn->Result, v11);
    }
  }
}

// File Line: 2515
// RVA: 0x6BA0F0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineIndexOfChar(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // r9
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v6; // rdi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  int v9; // eax
  int LineIndexOfChar; // eax
  double v11; // xmm1_8

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3);
    v5 = 0i64;
    v6 = (unsigned int)(v4 - 2) > 3 ? 0i64 : v3[1].vfptr;
    if ( fn->NArgs >= 1 )
    {
      Env = fn->Env;
      FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
      if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
      v9 = (int)Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
      if ( v9 < 0
        || (LineIndexOfChar = Scaleform::Render::Text::DocView::GetLineIndexOfChar(
                                (Scaleform::Render::Text::DocView *)v6[1].SetMemberFlags,
                                (unsigned int)v9),
            LineIndexOfChar == -1) )
      {
        v11 = DOUBLE_N1_0;
      }
      else
      {
        v11 = (double)LineIndexOfChar;
      }
      Scaleform::GFx::AS2::Value::SetNumber(fn->Result, v11);
    }
  }
}

// File Line: 2541
// RVA: 0x6BBF00
void __fastcall Scaleform::GFx::AS2::AvmTextField::CopyToClipboard(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v4; // rax
  __int64 v5; // rdi
  __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rbp
  unsigned int v9; // r14d
  bool v10; // si
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rax
  Scaleform::GFx::AS2::Value *v13; // rax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : v3[1].vfptr;
    v5 = *((_QWORD *)v4[1].SetMemberFlags + 27);
    if ( v5 )
    {
      v6 = *(_QWORD *)(v5 + 16);
      v7 = *(_QWORD *)(v6 + 56);
      v8 = *(_QWORD *)(v6 + 64);
      v9 = v8;
      v10 = (*(_BYTE *)(v5 + 160) & 4) != 0;
      if ( v7 < v8 )
        v9 = *(_QWORD *)(v6 + 56);
      if ( v8 < v7 )
        LODWORD(v8) = *(_QWORD *)(v6 + 56);
      if ( fn->NArgs >= 1 )
      {
        v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v10 = Scaleform::GFx::AS2::Value::ToBool(v11, fn->Env);
      }
      if ( fn->NArgs >= 2 )
      {
        v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v9 = Scaleform::GFx::AS2::Value::ToUInt32(v12, fn->Env);
      }
      if ( fn->NArgs >= 3 )
      {
        v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        LODWORD(v8) = Scaleform::GFx::AS2::Value::ToUInt32(v13, fn->Env);
      }
      Scaleform::GFx::Text::EditorKit::CopyToClipboard((Scaleform::GFx::Text::EditorKit *)v5, v9, (unsigned int)v8, v10);
    }
  }
}

// File Line: 2567
// RVA: 0x6BC030
void __fastcall Scaleform::GFx::AS2::AvmTextField::CutToClipboard(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::TextField *v4; // rdi
  Scaleform::Render::Text::EditorKitBase *pObject; // rsi
  Scaleform::RefCountImplCoreVtbl *vfptr; // rcx
  void *(__fastcall *vecDelDtor)(Scaleform::RefCountImplCore *, unsigned int); // rax
  void *(__fastcall *v8)(Scaleform::RefCountImplCore *, unsigned int); // r14
  bool v9; // bp
  unsigned int v10; // r15d
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rax
  Scaleform::GFx::AS2::Value *v13; // rax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : (Scaleform::GFx::TextField *)v3[1].vfptr;
    pObject = v4->pDocument.pObject->pEditorKit.pObject;
    if ( pObject )
    {
      vfptr = pObject[1].vfptr;
      vecDelDtor = vfptr[7].__vecDelDtor;
      v8 = vfptr[8].__vecDelDtor;
      v9 = ((__int64)pObject[10].vfptr & 4) != 0;
      v10 = (unsigned int)v8;
      if ( (unsigned __int64)vecDelDtor < (unsigned __int64)v8 )
        v10 = (unsigned int)vfptr[7].__vecDelDtor;
      if ( (unsigned __int64)v8 < (unsigned __int64)vecDelDtor )
        LODWORD(v8) = vfptr[7].__vecDelDtor;
      if ( fn->NArgs >= 1 )
      {
        v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v9 = Scaleform::GFx::AS2::Value::ToBool(v11, fn->Env);
      }
      if ( fn->NArgs >= 2 )
      {
        v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v10 = Scaleform::GFx::AS2::Value::ToUInt32(v12, fn->Env);
      }
      if ( fn->NArgs >= 3 )
      {
        v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        LODWORD(v8) = Scaleform::GFx::AS2::Value::ToUInt32(v13, fn->Env);
      }
      Scaleform::GFx::Text::EditorKit::CutToClipboard(
        (Scaleform::GFx::Text::EditorKit *)pObject,
        v10,
        (unsigned int)v8,
        v9);
      Scaleform::GFx::TextField::SetDirtyFlag(v4);
    }
  }
}

// File Line: 2594
// RVA: 0x6BC170
void __fastcall Scaleform::GFx::AS2::AvmTextField::PasteFromClipboard(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::TextField *v4; // rdi
  Scaleform::Render::Text::EditorKitBase *pObject; // rsi
  Scaleform::RefCountImplCoreVtbl *vfptr; // rcx
  void *(__fastcall *vecDelDtor)(Scaleform::RefCountImplCore *, unsigned int); // rax
  void *(__fastcall *v8)(Scaleform::RefCountImplCore *, unsigned int); // r14
  bool v9; // bp
  unsigned int v10; // r15d
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rax
  Scaleform::GFx::AS2::Value *v13; // rax

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 4 )
  {
    v3 = fn->ThisPtr;
    v4 = (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3
       ? 0i64
       : (Scaleform::GFx::TextField *)v3[1].vfptr;
    pObject = v4->pDocument.pObject->pEditorKit.pObject;
    if ( pObject )
    {
      vfptr = pObject[1].vfptr;
      vecDelDtor = vfptr[7].__vecDelDtor;
      v8 = vfptr[8].__vecDelDtor;
      v9 = ((__int64)pObject[10].vfptr & 4) != 0;
      v10 = (unsigned int)v8;
      if ( (unsigned __int64)vecDelDtor < (unsigned __int64)v8 )
        v10 = (unsigned int)vfptr[7].__vecDelDtor;
      if ( (unsigned __int64)v8 < (unsigned __int64)vecDelDtor )
        LODWORD(v8) = vfptr[7].__vecDelDtor;
      if ( fn->NArgs >= 1 )
      {
        v11 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v9 = Scaleform::GFx::AS2::Value::ToBool(v11, fn->Env);
      }
      if ( fn->NArgs >= 2 )
      {
        v12 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v10 = Scaleform::GFx::AS2::Value::ToUInt32(v12, fn->Env);
      }
      if ( fn->NArgs >= 3 )
      {
        v13 = Scaleform::GFx::AS2::FnCall::Arg(fn, 2);
        LODWORD(v8) = Scaleform::GFx::AS2::Value::ToUInt32(v13, fn->Env);
      }
      Scaleform::GFx::Text::EditorKit::PasteFromClipboard(
        (Scaleform::GFx::Text::EditorKit *)pObject,
        v10,
        (unsigned int)v8,
        v9);
      Scaleform::GFx::TextField::SetDirtyFlag(v4);
    }
  }
}

// File Line: 2621
// RVA: 0x6CBF40
void __fastcall Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(
        Scaleform::GFx::AS2::TextFieldObject *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pTextField.pProxy.pObject = 0i64;
  this->pIMECompositionStringStyles = 0i64;
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    pprototype);
}

// File Line: 2628
// RVA: 0x6CBFC0
void __fastcall Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(
        Scaleform::GFx::AS2::TextFieldObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pTextField.pProxy.pObject = 0i64;
  this->pIMECompositionStringStyles = 0i64;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(penv->StringContext.pContext, ASBuiltin_TextField);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    Prototype);
}

// File Line: 2635
// RVA: 0x6CC050
void __fastcall Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(
        Scaleform::GFx::AS2::TextFieldObject *this,
        Scaleform::GFx::AS2::GlobalContext *gCtxt,
        Scaleform::GFx::InteractiveObject *ptextfield)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *pLoadQueueHead; // rdx
  Scaleform::WeakPtrProxy *WeakProxy; // rax
  _QWORD *v8; // rbx
  Scaleform::GFx::AS2::ASStringContext *v9; // rdx
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::Object *pObject; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v13; // [rsp+38h] [rbp-40h] BYREF
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p_pTextField; // [rsp+88h] [rbp+10h] BYREF

  pMovieRoot = gCtxt->pMovieRoot;
  if ( pMovieRoot )
    pLoadQueueHead = (Scaleform::GFx::AS2::ASRefCountCollector *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0i64;
  Scaleform::GFx::AS2::Object::Object(this, pLoadQueueHead);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  p_pTextField = &this->pTextField;
  if ( ptextfield )
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(ptextfield);
  else
    WeakProxy = 0i64;
  this->pTextField.pProxy.pObject = WeakProxy;
  v8 = (Scaleform::RefCountNTSImplCoreVtbl **)((char *)&ptextfield->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                             + 4 * (unsigned __int8)ptextfield->AvmObjOffset);
  v9 = (Scaleform::GFx::AS2::ASStringContext *)((*(__int64 (__fastcall **)(_QWORD *))(*v8 + 240i64))(v8) + 232);
  v10 = (Scaleform::GFx::AS2::Object *)v8[2];
  if ( !this->pProto.pObject )
  {
    LOBYTE(p_pTextField) = 3;
    v13.T.Type = 10;
    this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      v9,
      (Scaleform::GFx::ASString *)&v9->pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
      &v13,
      (Scaleform::GFx::AS2::PropFlags *)&p_pTextField);
    if ( v13.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v13);
  }
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->pProto.pObject = v10;
  this->pIMECompositionStringStyles = 0i64;
}

// File Line: 2644
// RVA: 0x6D27B0
void __fastcall Scaleform::GFx::AS2::TextFieldObject::~TextFieldObject(Scaleform::GFx::AS2::TextFieldObject *this)
{
  Scaleform::WeakPtrProxy *pObject; // rdx

  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pIMECompositionStringStyles);
  pObject = this->pTextField.pProxy.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  Scaleform::GFx::AS2::Object::~Object(this);
}

// File Line: 2649
// RVA: 0x6EFB70
Scaleform::GFx::Text::IMEStyle *__fastcall Scaleform::GFx::AS2::TextFieldObject::GetIMECompositionStringStyles(
        Scaleform::GFx::AS2::TextFieldObject *this)
{
  Scaleform::GFx::AS2::TextFieldObject *pObject; // rbx

  pObject = this;
  if ( this->pIMECompositionStringStyles )
    return pObject->pIMECompositionStringStyles;
  while ( 1 )
  {
    pObject = (Scaleform::GFx::AS2::TextFieldObject *)pObject->pProto.pObject;
    if ( !pObject
      || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&pObject->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&pObject->Scaleform::GFx::AS2::ObjectInterface) != 13 )
    {
      break;
    }
    if ( pObject->pIMECompositionStringStyles )
      return pObject->pIMECompositionStringStyles;
  }
  return 0i64;
}

// File Line: 2662
// RVA: 0x714750
void __fastcall Scaleform::GFx::AS2::TextFieldObject::SetIMECompositionStringStyles(
        Scaleform::GFx::AS2::TextFieldObject *this,
        Scaleform::GFx::Text::IMEStyle *imeStyles)
{
  Scaleform::GFx::Text::IMEStyle *pIMECompositionStringStyles; // rcx
  __int64 v5; // rax
  Scaleform::GFx::Text::IMEStyle *v6; // rdx
  int v7; // [rsp+50h] [rbp+18h] BYREF
  __int64 v8; // [rsp+58h] [rbp+20h]

  pIMECompositionStringStyles = this->pIMECompositionStringStyles;
  if ( pIMECompositionStringStyles )
  {
    pIMECompositionStringStyles->HighlightStyles[0].BackgroundColor.Raw = imeStyles->HighlightStyles[0].BackgroundColor.Raw;
    pIMECompositionStringStyles->HighlightStyles[0].TextColor.Raw = imeStyles->HighlightStyles[0].TextColor.Raw;
    pIMECompositionStringStyles->HighlightStyles[0].UnderlineColor.Raw = imeStyles->HighlightStyles[0].UnderlineColor.Raw;
    pIMECompositionStringStyles->HighlightStyles[0].Flags = imeStyles->HighlightStyles[0].Flags;
    pIMECompositionStringStyles->HighlightStyles[1] = imeStyles->HighlightStyles[1];
    pIMECompositionStringStyles->HighlightStyles[2] = imeStyles->HighlightStyles[2];
    pIMECompositionStringStyles->HighlightStyles[3] = imeStyles->HighlightStyles[3];
    pIMECompositionStringStyles->HighlightStyles[4] = imeStyles->HighlightStyles[4];
    pIMECompositionStringStyles->PresenceMask = imeStyles->PresenceMask;
  }
  else
  {
    v7 = 325;
    v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::TextFieldObject *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
           Scaleform::Memory::pGlobalHeap,
           this,
           84i64,
           &v7,
           -2i64);
    v6 = (Scaleform::GFx::Text::IMEStyle *)v5;
    v8 = v5;
    if ( v5 )
    {
      *(_DWORD *)v5 = imeStyles->HighlightStyles[0].BackgroundColor.Raw;
      *(_DWORD *)(v5 + 4) = imeStyles->HighlightStyles[0].TextColor.Raw;
      *(_DWORD *)(v5 + 8) = imeStyles->HighlightStyles[0].UnderlineColor.Raw;
      *(_BYTE *)(v5 + 12) = imeStyles->HighlightStyles[0].Flags;
      *(_DWORD *)(v5 + 16) = imeStyles->HighlightStyles[1].BackgroundColor.Raw;
      *(_DWORD *)(v5 + 20) = imeStyles->HighlightStyles[1].TextColor.Raw;
      *(_DWORD *)(v5 + 24) = imeStyles->HighlightStyles[1].UnderlineColor.Raw;
      *(_BYTE *)(v5 + 28) = imeStyles->HighlightStyles[1].Flags;
      *(_DWORD *)(v5 + 32) = imeStyles->HighlightStyles[2].BackgroundColor.Raw;
      *(_DWORD *)(v5 + 36) = imeStyles->HighlightStyles[2].TextColor.Raw;
      *(_DWORD *)(v5 + 40) = imeStyles->HighlightStyles[2].UnderlineColor.Raw;
      *(_BYTE *)(v5 + 44) = imeStyles->HighlightStyles[2].Flags;
      *(_DWORD *)(v5 + 48) = imeStyles->HighlightStyles[3].BackgroundColor.Raw;
      *(_DWORD *)(v5 + 52) = imeStyles->HighlightStyles[3].TextColor.Raw;
      *(_DWORD *)(v5 + 56) = imeStyles->HighlightStyles[3].UnderlineColor.Raw;
      *(_BYTE *)(v5 + 60) = imeStyles->HighlightStyles[3].Flags;
      *(_DWORD *)(v5 + 64) = imeStyles->HighlightStyles[4].BackgroundColor.Raw;
      *(_DWORD *)(v5 + 68) = imeStyles->HighlightStyles[4].TextColor.Raw;
      *(_DWORD *)(v5 + 72) = imeStyles->HighlightStyles[4].UnderlineColor.Raw;
      *(_BYTE *)(v5 + 76) = imeStyles->HighlightStyles[4].Flags;
      *(_BYTE *)(v5 + 80) = imeStyles->PresenceMask;
    }
    else
    {
      v6 = 0i64;
    }
    this->pIMECompositionStringStyles = v6;
  }
}

// File Line: 2715
// RVA: 0x6CC190
void __fastcall Scaleform::GFx::AS2::TextFieldProto::TextFieldProto(
        Scaleform::GFx::AS2::TextFieldProto *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *prototype,
        Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ObjectInterface *v6; // rdi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v9; // zf
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASString *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASStringNode *v25; // rcx
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::ASStringNode *v27; // rcx
  Scaleform::GFx::ASString *v28; // rax
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASStringNode *v31; // rcx
  Scaleform::GFx::ASString *v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::ASString *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASString *v36; // rax
  Scaleform::GFx::ASStringNode *v37; // rcx
  Scaleform::GFx::ASString *v38; // rax
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::GFx::ASString *v40; // rax
  Scaleform::GFx::ASStringNode *v41; // rcx
  Scaleform::GFx::ASString *v42; // rax
  Scaleform::GFx::ASStringNode *v43; // rcx
  Scaleform::GFx::ASString *v44; // rax
  Scaleform::GFx::ASStringNode *v45; // rcx
  Scaleform::GFx::ASString *v46; // rax
  Scaleform::GFx::ASStringNode *v47; // rcx
  Scaleform::GFx::ASString *v48; // rax
  Scaleform::GFx::ASStringNode *v49; // rcx
  Scaleform::GFx::ASString *v50; // rax
  Scaleform::GFx::ASStringNode *v51; // rcx
  Scaleform::GFx::ASString *v52; // rax
  Scaleform::GFx::ASStringNode *v53; // rcx
  Scaleform::GFx::ASString *v54; // rax
  Scaleform::GFx::ASStringNode *v55; // rcx
  Scaleform::GFx::ASString *v56; // rax
  Scaleform::GFx::ASStringNode *v57; // rcx
  Scaleform::GFx::ASString *v58; // rax
  Scaleform::GFx::ASStringNode *v59; // rcx
  Scaleform::GFx::ASString *v60; // rax
  Scaleform::GFx::ASStringNode *v61; // rcx
  Scaleform::GFx::ASString *v62; // rax
  Scaleform::GFx::ASStringNode *v63; // rcx
  Scaleform::GFx::ASString *v64; // rax
  Scaleform::GFx::ASStringNode *v65; // rcx
  Scaleform::GFx::ASString *v66; // rax
  Scaleform::GFx::ASStringNode *v67; // rcx
  Scaleform::GFx::ASString *v68; // rax
  Scaleform::GFx::ASStringNode *v69; // rcx
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+30h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-38h] BYREF
  __int64 v72; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value v73; // [rsp+48h] [rbp-28h] BYREF

  v72 = -2i64;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>(
    this,
    psc,
    prototype,
    constructor);
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::TextFieldObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::TextFieldObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::TextFieldProto::`vftable;
  if ( this != (Scaleform::GFx::AS2::TextFieldProto *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      psc,
      GAS_AsBcFunctionTable,
      1);
  flags.Flags = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    this,
    psc,
    GAS_TextFieldFunctionTable,
    &flags);
  flags.Flags = 2;
  v73.T.Type = 10;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "scroll");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v7, &v73, &flags);
  pNode = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "hscroll");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v10, &v73, &flags);
  v11 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v12 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "maxscroll");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v12, &v73, &flags);
  v13 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v14 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "maxhscroll");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v14, &v73, &flags);
  v15 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "background");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v16, &v73, &flags);
  v17 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "backgroundColor");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v18, &v73, &flags);
  v19 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v20 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "border");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v20, &v73, &flags);
  v21 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v22 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "borderColor");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v22, &v73, &flags);
  v23 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "bottomScroll");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v24, &v73, &flags);
  v25 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v26 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "mouseWheelEnabled");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v26, &v73, &flags);
  v27 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v28 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "antiAliasType");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v28, &v73, &flags);
  v29 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "autoSize");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v30, &v73, &flags);
  v31 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v32 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "condenseWhite");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v32, &v73, &flags);
  v33 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v34 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "embedFonts");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v34, &v73, &flags);
  v35 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v36 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "html");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v36, &v73, &flags);
  v37 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v38 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "htmlText");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v38, &v73, &flags);
  v39 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v40 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "length");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v40, &v73, &flags);
  v41 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v42 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "maxChars");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v42, &v73, &flags);
  v43 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "multiline");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v44, &v73, &flags);
  v45 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v46 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "password");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v46, &v73, &flags);
  v47 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 1;
  v48 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "restrict");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v48, &v73, &flags);
  v49 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v50 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "selectable");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v50, &v73, &flags);
  v51 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v52 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "styleSheet");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v52, &v73, &flags);
  v53 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v54 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "tabIndex");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v54, &v73, &flags);
  v55 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v55);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v56 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "text");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v56, &v73, &flags);
  v57 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v58 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "textColor");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v58, &v73, &flags);
  v59 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v59);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v60 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "textHeight");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v60, &v73, &flags);
  v61 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v61);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v62 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "textWidth");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v62, &v73, &flags);
  v63 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v63);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v64 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "type");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v64, &v73, &flags);
  v65 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v65);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v66 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "variable");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v66, &v73, &flags);
  v67 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v67);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v68 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "wordWrap");
  v6->vfptr->SetMemberRaw(&this->Scaleform::GFx::AS2::ObjectInterface, psc, v68, &v73, &flags);
  v69 = result.pNode;
  v9 = result.pNode->RefCount-- == 1;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v69);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    &this->Scaleform::GFx::AS2::GASPrototypeBase,
    this,
    psc,
    GAS_TextFieldExtFunctionTable,
    &flags);
}

// File Line: 2777
// RVA: 0x6CBE80
void __fastcall Scaleform::GFx::AS2::TextFieldCtorFunction::TextFieldCtorFunction(
        Scaleform::GFx::AS2::TextFieldCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, psc);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->pFunction = (void (__fastcall *)(Scaleform::GFx::AS2::FnCall *))_;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    GAS_TextFieldStaticFunctionTable,
    7);
}

// File Line: 2784
// RVA: 0x6E08C0
void __fastcall Scaleform::GFx::AS2::TextFieldCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::TextFieldCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::TextFieldObject *v3; // rax

  v3 = (Scaleform::GFx::AS2::TextFieldObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::TextFieldCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                 this,
                                                 112i64);
  if ( v3 )
    Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(v3, penv);
}

// File Line: 2795
// RVA: 0x70F0E0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::TextFieldCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::TextFieldCtorFunction *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::TextFieldProto *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rbx
  Scaleform::GFx::AS2::Object *pObject; // r14
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::Value v16; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+A8h] [rbp+38h] BYREF
  void *v18; // [rsp+B0h] [rbp+40h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_objproto; // [rsp+B8h] [rbp+48h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::TextFieldCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, __int64))objproto.pObject->vfptr[3].Finalize_GC)(
                                                       result,
                                                       104i64);
  v18 = v4;
  if ( v4 )
    Scaleform::GFx::AS2::TextFieldCtorFunction::TextFieldCtorFunction(v4, &psc);
  result->Flags = 0;
  result->Function = v4;
  result->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v6 = (Scaleform::GFx::AS2::TextFieldProto *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                                v5,
                                                176i64,
                                                0i64);
  v18 = v6;
  if ( v6 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::TextFieldProto::TextFieldProto(v6, &psc, Prototype, result);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v18 = v9;
  p_objproto = &objproto;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v9;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_TextField,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  pObject = pgc->pGlobal.pObject;
  v16.T.Type = 8;
  v16.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v16.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v16.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v16.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &pObject->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[9].AVMVersion,
    &v16,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v16.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v16);
  if ( v9 )
  {
    RefCount = v9->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v9->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
  }
  return result;
}

// File Line: 2811
// RVA: 0x6AA2D0
void __fastcall Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  __int64 v3; // rcx
  Scaleform::GFx::StateBag *v4; // rdi
  Scaleform::GFx::FontLib *pObject; // rbx
  Scaleform::GFx::FontProvider *v6; // rbx
  Scaleform::GFx::FontProvider *v7; // rcx
  Scaleform::GFx::ASStringNode *v8; // rax
  __int64 v9; // rax
  __int64 v10; // r15
  unsigned __int64 v11; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v12; // rdx
  signed __int64 v13; // rbx
  __int64 v14; // rax
  Scaleform::GFx::ASString *v15; // rax
  char Type; // r12
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v19; // rax
  __int64 v20; // rax
  __int64 v21; // r14
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rsi
  unsigned __int64 v24; // r8
  _QWORD *v25; // rcx
  unsigned __int64 v26; // rcx
  _QWORD *v27; // rax
  int v28; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // rdx
  __int64 v30; // rdi
  unsigned __int64 v31; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v32; // rbx
  __int128 v33; // [rsp+20h] [rbp-59h]
  Scaleform::GFx::ASString v34; // [rsp+30h] [rbp-49h] BYREF
  __int64 v35[2]; // [rsp+38h] [rbp-41h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontProvider> v36; // [rsp+48h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+50h] [rbp-29h] BYREF
  __int64 v38; // [rsp+70h] [rbp-9h]
  __int64 v39; // [rsp+78h] [rbp-1h]
  __int64 v40; // [rsp+80h] [rbp+7h]
  Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *p_fontnames; // [rsp+E8h] [rbp+6Fh] BYREF
  Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > fontnames; // [rsp+F0h] [rbp+77h] BYREF
  Scaleform::Ptr<Scaleform::GFx::FontLib> result; // [rsp+F8h] [rbp+7Fh] BYREF

  v40 = -2i64;
  v1 = fn;
  pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
  v3 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))pMovieImpl->Scaleform::GFx::Movie::Scaleform::RefCountBase<Scaleform::GFx::Movie,327>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,327>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::vfptr[1].__vecDelDtor)(pMovieImpl);
  p_fontnames = &fontnames;
  fontnames.mHash.pTable = 0i64;
  v35[0] = (__int64)`Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList::`2::FontsVisitor::`vftable;
  v35[1] = (__int64)&fontnames;
  (*(void (__fastcall **)(__int64, __int64 *, __int64))(*(_QWORD *)v3 + 208i64))(v3, v35, 1i64);
  v4 = &pMovieImpl->Scaleform::GFx::StateBag;
  pObject = Scaleform::GFx::StateBag::GetFontLib(&pMovieImpl->Scaleform::GFx::StateBag, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( pObject )
    Scaleform::GFx::FontLib::LoadFontNames(pObject, &fontnames);
  v6 = Scaleform::GFx::StateBag::GetFontProvider(v4, &v36)->pObject;
  v7 = v36.pObject;
  if ( v36.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v36.pObject);
  if ( v6 )
    v6->vfptr[2].__vecDelDtor(v6, (unsigned int)&fontnames);
  p_fontnames = (Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *)v1->Env->StringContext.pContext->pHeap;
  v8 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::FontProvider *, __int64, _QWORD))p_fontnames->mHash.pTable[5].EntryCount)(
                                         v7,
                                         144i64,
                                         0i64);
  v34.pNode = v8;
  if ( v8 )
  {
    Scaleform::GFx::AS2::ArrayObject::ArrayObject((Scaleform::GFx::AS2::ArrayObject *)v8, v1->Env);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  v38 = v10;
  if ( fontnames.mHash.pTable )
  {
    v11 = 0i64;
    v12 = fontnames.mHash.pTable + 1;
    do
    {
      if ( v12->EntryCount != -2i64 )
        break;
      ++v11;
      v12 += 2;
    }
    while ( v11 <= fontnames.mHash.pTable->SizeMask );
    *(_QWORD *)&v33 = &fontnames;
    *((_QWORD *)&v33 + 1) = v11;
  }
  else
  {
    v33 = 0ui64;
  }
  v13 = *((_QWORD *)&v33 + 1);
  while ( (_QWORD)v33 )
  {
    v14 = *(_QWORD *)v33;
    if ( !*(_QWORD *)v33 || v13 > *(_QWORD *)(v14 + 8) )
      break;
    v15 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &v34, (Scaleform::String *)(v14 + 32 * (v13 + 1)));
    Type = 5;
    v.T.Type = 5;
    v.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v15->pNode;
    ++v.V.pStringNode->RefCount;
    pNode = v34.pNode;
    if ( v34.pNode->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v39 = v10;
    LODWORD(p_fontnames) = 323;
    v19 = (Scaleform::GFx::AS2::Value *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                          Scaleform::Memory::pGlobalHeap,
                                          v10,
                                          32i64,
                                          &p_fontnames);
    if ( v19 )
    {
      Scaleform::GFx::AS2::Value::Value(v19, &v);
      v21 = v20;
      Type = v.T.Type;
    }
    else
    {
      v21 = 0i64;
    }
    v22 = *(_QWORD *)(v10 + 112);
    v23 = v22 + 1;
    if ( v22 + 1 >= v22 )
    {
      if ( v23 <= *(_QWORD *)(v10 + 120) )
        goto LABEL_33;
      v24 = v23 + (v23 >> 2);
    }
    else
    {
      if ( v23 >= *(_QWORD *)(v10 + 120) >> 1 )
        goto LABEL_33;
      v24 = v22 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)(v10 + 104),
      (const void *)(v10 + 104),
      v24);
LABEL_33:
    *(_QWORD *)(v10 + 112) = v23;
    v25 = (_QWORD *)(*(_QWORD *)(v10 + 104) + 8 * (v23 - 1));
    if ( v25 )
      *v25 = v21;
    if ( (unsigned __int8)Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v26 = *(_QWORD *)(*(_QWORD *)v33 + 8i64);
    v1 = fn;
    if ( v13 <= (__int64)v26 && ++v13 <= v26 )
    {
      v27 = (_QWORD *)(*(_QWORD *)v33 + 32 * v13 + 16);
      do
      {
        v1 = fn;
        if ( *v27 != -2i64 )
          break;
        ++v13;
        v27 += 4;
      }
      while ( v13 <= v26 );
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)v10);
  if ( v10 )
  {
    v28 = *(_DWORD *)(v10 + 24);
    if ( (v28 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v10 + 24) = v28 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10);
    }
  }
  v35[0] = (__int64)&Scaleform::GFx::MovieDef::ResourceVisitor::`vftable;
  pTable = fontnames.mHash.pTable;
  if ( fontnames.mHash.pTable )
  {
    v30 = 0i64;
    v31 = fontnames.mHash.pTable->SizeMask + 1;
    do
    {
      v32 = &pTable[v30];
      if ( pTable[v30 + 1].EntryCount != -2i64 )
      {
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v32[2].SizeMask & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v32[2].EntryCount & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        v32[1].EntryCount = -2i64;
        pTable = fontnames.mHash.pTable;
      }
      v30 += 2i64;
      --v31;
    }
    while ( v31 );
    if ( pTable )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 2826
// RVA: 0x7236A0
void __fastcall Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList_::_2_::FontsVisitor::Visit(
        Scaleform::GFx::MovieDef *__formal,
        Scaleform::GFx::Resource *presource,
        _QWORD **a3,
        const char *a4)
{
  const char *v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v7; // rcx
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+28h] [rbp-20h] BYREF
  Scaleform::String v9; // [rsp+60h] [rbp+18h] BYREF

  if ( (((__int64 (__fastcall *)(_QWORD **, Scaleform::GFx::Resource *))(*a3)[2])(a3, presource) & 0xFF00) == 512 )
  {
    v6 = (const char *)(*(__int64 (__fastcall **)(_QWORD *))(*a3[3] + 8i64))(a3[3]);
    Scaleform::String::String(&v9, v6);
    v7 = *(Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > **)&__formal->RefCount.Value;
    key.pFirst = &v9;
    key.pSecond = &v9;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      v7,
      v7,
      &key);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 2862
// RVA: 0x707E30
Scaleform::Render::Text::HighlightInfo *__fastcall Scaleform::GFx::AS2::TextFieldProto::ParseStyle(
        Scaleform::Render::Text::HighlightInfo *result,
        Scaleform::GFx::AS2::FnCall *fn,
        unsigned int paramIndex,
        Scaleform::Render::Text::HighlightInfo *initialHInfo)
{
  unsigned int v6; // r9d
  Scaleform::GFx::AS2::Environment *Env; // rdx
  __int64 v8; // rdi
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // r14
  Scaleform::GFx::ASString *v12; // rax
  char v13; // r15
  Scaleform::GFx::ASStringNode *pNode; // rcx
  const char *pData; // rdx
  __int64 v16; // rax
  char v17; // cl
  bool v18; // zf
  bool v19; // r15
  Scaleform::GFx::ASStringNode *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::ASString *v22; // rax
  char v23; // r15
  Scaleform::GFx::ASStringNode *v24; // rcx
  const char *v25; // rdx
  __int64 v26; // rax
  char v27; // cl
  bool v28; // zf
  bool v29; // r15
  Scaleform::GFx::ASStringNode *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::ASString *v32; // rax
  char v33; // r15
  Scaleform::GFx::ASStringNode *v34; // rcx
  const char *v35; // rdx
  __int64 v36; // rax
  char v37; // cl
  bool v38; // zf
  bool v39; // r15
  Scaleform::GFx::ASStringNode *v40; // rcx
  unsigned int v41; // eax
  Scaleform::GFx::ASString *v42; // rax
  char v43; // r15
  Scaleform::GFx::ASStringNode *v44; // rcx
  const char *v45; // rsi
  __int64 v46; // rcx
  char v47; // al
  __int64 v48; // rcx
  char v49; // al
  char v50; // al
  Scaleform::GFx::ASStringNode *v51; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v54; // [rsp+28h] [rbp-28h] BYREF
  Scaleform::GFx::ASString resulta; // [rsp+90h] [rbp+40h] BYREF
  Scaleform::GFx::AS2::Object *v56; // [rsp+98h] [rbp+48h]

  *result = *initialHInfo;
  if ( fn->NArgs >= 1 )
  {
    v6 = fn->FirstArgBottomIndex - paramIndex;
    Env = fn->Env;
    v8 = 0i64;
    v9 = 0i64;
    if ( v6 <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
             + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v9 = &Env->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToObject(v9, Env);
    v11 = v10;
    if ( v10 )
      v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
    v56 = v10;
    if ( v10 )
    {
      v54.T.Type = 0;
      v12 = Scaleform::GFx::AS2::Environment::CreateConstString(fn->Env, &resulta, "textColor");
      v13 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, __int64))v11[1].vfptr[1].Finalize_GC)(
              &v11[1],
              fn->Env,
              v12,
              &v54,
              -2i64);
      pNode = resulta.pNode;
      v18 = resulta.pNode->RefCount-- == 1;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v13 )
      {
        pData = Scaleform::GFx::AS2::Value::ToString(&v54, &resulta, fn->Env, -1)->pNode->pData;
        v16 = 0i64;
        while ( 1 )
        {
          v17 = pData[v16++];
          v18 = v17 == aNone[v16 - 1];
          if ( v17 != aNone[v16 - 1] )
            break;
          if ( v16 == 5 )
          {
            v18 = v17 == aNone[4];
            break;
          }
        }
        v19 = v18;
        v20 = resulta.pNode;
        v18 = resulta.pNode->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        if ( v19 )
        {
          result->Flags &= ~0x10u;
        }
        else
        {
          resulta.pNode = COERCE_SCALEFORM_GFX_ASSTRINGNODE_(Scaleform::GFx::AS2::Value::ToNumber(&v54, fn->Env));
          if ( ((unsigned __int64)resulta.pNode & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
          {
            v21 = Scaleform::GFx::AS2::Value::ToUInt32(&v54, fn->Env);
            result->Flags |= 0x10u;
            result->TextColor.Raw = v21 | 0xFF000000;
          }
        }
      }
      v22 = Scaleform::GFx::AS2::Environment::CreateConstString(fn->Env, &resulta, "backgroundColor");
      v23 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v11[1].vfptr[1].Finalize_GC)(
              &v11[1],
              fn->Env,
              v22,
              &v54);
      v24 = resulta.pNode;
      v18 = resulta.pNode->RefCount-- == 1;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( v23 )
      {
        v25 = Scaleform::GFx::AS2::Value::ToString(&v54, &resulta, fn->Env, -1)->pNode->pData;
        v26 = 0i64;
        while ( 1 )
        {
          v27 = v25[v26++];
          v28 = v27 == aNone[v26 - 1];
          if ( v27 != aNone[v26 - 1] )
            break;
          if ( v26 == 5 )
          {
            v28 = v27 == aNone[4];
            break;
          }
        }
        v29 = v28;
        v30 = resulta.pNode;
        v18 = resulta.pNode->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v30);
        if ( v29 )
        {
          result->Flags &= ~8u;
        }
        else
        {
          resulta.pNode = COERCE_SCALEFORM_GFX_ASSTRINGNODE_(Scaleform::GFx::AS2::Value::ToNumber(&v54, fn->Env));
          if ( ((unsigned __int64)resulta.pNode & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
          {
            v31 = Scaleform::GFx::AS2::Value::ToUInt32(&v54, fn->Env);
            result->Flags |= 8u;
            result->BackgroundColor.Raw = v31 | 0xFF000000;
          }
        }
      }
      v32 = Scaleform::GFx::AS2::Environment::CreateConstString(fn->Env, &resulta, "underlineColor");
      v33 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v11[1].vfptr[1].Finalize_GC)(
              &v11[1],
              fn->Env,
              v32,
              &v54);
      v34 = resulta.pNode;
      v18 = resulta.pNode->RefCount-- == 1;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v34);
      if ( v33 )
      {
        v35 = Scaleform::GFx::AS2::Value::ToString(&v54, &resulta, fn->Env, -1)->pNode->pData;
        v36 = 0i64;
        while ( 1 )
        {
          v37 = v35[v36++];
          v38 = v37 == aNone[v36 - 1];
          if ( v37 != aNone[v36 - 1] )
            break;
          if ( v36 == 5 )
          {
            v38 = v37 == aNone[4];
            break;
          }
        }
        v39 = v38;
        v40 = resulta.pNode;
        v18 = resulta.pNode->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v40);
        if ( v39 )
        {
          result->Flags &= ~0x20u;
        }
        else
        {
          resulta.pNode = COERCE_SCALEFORM_GFX_ASSTRINGNODE_(Scaleform::GFx::AS2::Value::ToNumber(&v54, fn->Env));
          if ( ((unsigned __int64)resulta.pNode & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 )
          {
            v41 = Scaleform::GFx::AS2::Value::ToUInt32(&v54, fn->Env);
            result->Flags |= 0x20u;
            result->UnderlineColor.Raw = v41 | 0xFF000000;
          }
        }
      }
      v42 = Scaleform::GFx::AS2::Environment::CreateConstString(fn->Env, &resulta, "underlineStyle");
      v43 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v11[1].vfptr[1].Finalize_GC)(
              &v11[1],
              fn->Env,
              v42,
              &v54);
      v44 = resulta.pNode;
      v18 = resulta.pNode->RefCount-- == 1;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v44);
      if ( v43 )
      {
        Scaleform::GFx::AS2::Value::ToString(&v54, &resulta, fn->Env, -1);
        v45 = resulta.pNode->pData;
        v46 = 0i64;
        while ( 1 )
        {
          v47 = v45[v46++];
          if ( v47 != aDotted[v46 - 1] )
            break;
          if ( v46 == 7 )
          {
            result->Flags &= ~4u;
            result->Flags |= 3u;
            goto LABEL_65;
          }
        }
        v48 = 0i64;
        while ( 1 )
        {
          v49 = v45[v48++];
          if ( v49 != aSingle[v48 - 1] )
            break;
          if ( v48 == 7 )
          {
            result->Flags &= 0xF9u;
            result->Flags |= 1u;
            goto LABEL_65;
          }
        }
        while ( 1 )
        {
          v50 = v45[v8++];
          if ( v50 != aThick[v8 - 1] )
            break;
          if ( v8 == 6 )
          {
            result->Flags &= 0xFAu;
            result->Flags |= 2u;
            goto LABEL_65;
          }
        }
        if ( !strcmp(resulta.pNode->pData, "ditheredSingle") )
        {
          result->Flags &= ~2u;
          result->Flags |= 5u;
        }
        else if ( !strcmp(v45, "ditheredThick") )
        {
          result->Flags &= ~1u;
          result->Flags |= 6u;
        }
        else
        {
          result->Flags &= 0xF8u;
        }
LABEL_65:
        v51 = resulta.pNode;
        v18 = resulta.pNode->RefCount-- == 1;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v51);
      }
      if ( v54.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v54);
    }
    if ( v11 )
    {
      RefCount = v11->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v11->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
  }
  return result;
}

// File Line: 2925
// RVA: 0x702D50
void __fastcall Scaleform::GFx::AS2::TextFieldProto::MakeStyle(
        Scaleform::GFx::AS2::FnCall *fn,
        Scaleform::Render::Text::HighlightInfo *hinfo)
{
  Scaleform::GFx::ASStringNode *v4; // rax
  Scaleform::GFx::AS2::Object *v5; // rax
  Scaleform::GFx::AS2::Object *v6; // rsi
  char Flags; // al
  const char *v8; // r8
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::AS2::Environment *Env; // rdi
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  long double v15; // xmm0_8
  Scaleform::GFx::AS2::Environment *v16; // rdi
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  long double v19; // xmm0_8
  Scaleform::GFx::AS2::Environment *v20; // rdi
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  long double v23; // xmm0_8
  Scaleform::GFx::AS2::Environment *v24; // rdi
  Scaleform::GFx::ASString *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value v28; // [rsp+38h] [rbp-30h] BYREF
  Scaleform::MemoryHeap *pHeap; // [rsp+A0h] [rbp+38h] BYREF
  Scaleform::GFx::ASString v30; // [rsp+A8h] [rbp+40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp+48h] BYREF
  Scaleform::GFx::AS2::Object *v32; // [rsp+B8h] [rbp+50h]

  pHeap = fn->Env->StringContext.pContext->pHeap;
  v4 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, __int64))pHeap->vfptr->Alloc)(
                                         fn,
                                         96i64);
  v30.pNode = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v4, fn->Env);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v32 = v6;
  Flags = hinfo->Flags;
  if ( (Flags & 7) != 0 )
  {
    switch ( Flags & 7 )
    {
      case 1:
        v8 = "single";
        break;
      case 2:
        v8 = "thick";
        break;
      case 3:
        v8 = "dotted";
        break;
      case 5:
        v8 = "ditheredSingle";
        break;
      case 6:
        v8 = "ditheredThick";
        break;
      default:
        goto LABEL_21;
    }
    v9 = Scaleform::GFx::AS2::Environment::CreateConstString(fn->Env, &result, v8);
    v28.T.Type = 5;
    v28.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v9->pNode;
    ++v28.V.pStringNode->RefCount;
    Env = fn->Env;
    v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&Env->StringContext, &v30, "underlineStyle");
    LOBYTE(pHeap) = 0;
    v6->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v6->Scaleform::GFx::AS2::ObjectInterface,
      &Env->StringContext,
      v11,
      &v28,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    pNode = v30.pNode;
    v13 = v30.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    if ( v28.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v28);
    v14 = result.pNode;
    v13 = result.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
LABEL_21:
  if ( (hinfo->Flags & 0x20) != 0 )
  {
    v15 = (double)(hinfo->UnderlineColor.Raw & 0xFFFFFF);
    v28.T.Type = 3;
    v28.NV.NumberValue = v15;
    v16 = fn->Env;
    v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v16->StringContext, &v30, "underlineColor");
    LOBYTE(pHeap) = 0;
    v6->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v6->Scaleform::GFx::AS2::ObjectInterface,
      &v16->StringContext,
      v17,
      &v28,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    v18 = v30.pNode;
    v13 = v30.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    if ( v28.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v28);
  }
  if ( (hinfo->Flags & 8) != 0 )
  {
    v19 = (double)(hinfo->BackgroundColor.Raw & 0xFFFFFF);
    v28.T.Type = 3;
    v28.NV.NumberValue = v19;
    v20 = fn->Env;
    v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v20->StringContext, &v30, "backgroundColor");
    LOBYTE(pHeap) = 0;
    v6->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v6->Scaleform::GFx::AS2::ObjectInterface,
      &v20->StringContext,
      v21,
      &v28,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    v22 = v30.pNode;
    v13 = v30.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    if ( v28.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v28);
  }
  if ( (hinfo->Flags & 0x10) != 0 )
  {
    v23 = (double)(hinfo->TextColor.Raw & 0xFFFFFF);
    v28.T.Type = 3;
    v28.NV.NumberValue = v23;
    v24 = fn->Env;
    v25 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v24->StringContext, &v30, "textColor");
    LOBYTE(pHeap) = 0;
    v6->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
      &v6->Scaleform::GFx::AS2::ObjectInterface,
      &v24->StringContext,
      v25,
      &v28,
      (Scaleform::GFx::AS2::PropFlags *)&pHeap);
    v26 = v30.pNode;
    v13 = v30.pNode->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    if ( v28.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v28);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v6);
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
}

// File Line: 2961
// RVA: 0x6EDB10
int __fastcall Scaleform::GFx::AS2::GFx_StringToIMEStyleCategory(Scaleform::GFx::ASString *categoryStr)
{
  int v1; // edi
  const char *pData; // rbx
  int result; // eax

  v1 = 5;
  pData = categoryStr->pNode->pData;
  result = strcmp(pData, "compositionSegment");
  if ( result )
  {
    if ( !strcmp(pData, "clauseSegment") )
    {
      return 1;
    }
    else if ( !strcmp(pData, "convertedSegment") )
    {
      return 2;
    }
    else if ( !strcmp(pData, "phraseLengthAdj") )
    {
      return 3;
    }
    else
    {
      if ( !strcmp(pData, "lowConfSegment") )
        return 4;
      return v1;
    }
  }
  return result;
}

// File Line: 2977
// RVA: 0x6A9510
void __fastcall Scaleform::GFx::AS2::TextFieldProto::SetIMECompositionStringStyle(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::TextFieldObject *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rax
  Scaleform::GFx::AS2::AvmTextField *p_pProto; // rcx
  Scaleform::GFx::AS2::TextFieldObject *TextFieldASObject; // rax
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  int v10; // eax
  __int64 v11; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v13; // zf
  Scaleform::GFx::Text::IMEStyle *IMECompositionStringStyles; // rax
  char PresenceMask; // r12
  Scaleform::Render::Text::HighlightInfo *v16; // r14
  Scaleform::Render::Text::HighlightInfo *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned int RefCount; // eax
  Scaleform::Render::Text::HighlightInfo v20; // [rsp+8h] [rbp-41h] BYREF
  Scaleform::GFx::Text::IMEStyle imeStyles; // [rsp+20h] [rbp-29h] BYREF
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp+67h] BYREF
  Scaleform::GFx::AS2::TextFieldObject *v23; // [rsp+B8h] [rbp+6Fh]

  if ( fn->ThisPtr )
  {
    v2 = 0i64;
    v23 = 0i64;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 4 )
    {
      ThisPtr = fn->ThisPtr;
      p_pProto = (Scaleform::GFx::AS2::AvmTextField *)&ThisPtr[-1].pProto;
      if ( !ThisPtr )
        p_pProto = 0i64;
      TextFieldASObject = Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(p_pProto);
      v2 = TextFieldASObject;
      if ( TextFieldASObject )
        TextFieldASObject->RefCount = (TextFieldASObject->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr) != 13 )
        goto LABEL_24;
      v6 = fn->ThisPtr;
      if ( v6 )
      {
        v2 = (Scaleform::GFx::AS2::TextFieldObject *)&v6[-2];
        if ( v2 )
          v2->RefCount = (v2->RefCount + 1) & 0x8FFFFFFF;
      }
      else
      {
        v2 = 0i64;
      }
    }
    v23 = v2;
    if ( v2 && fn->NArgs >= 1 )
    {
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v9 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v9 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v9, &result, Env, -1);
      v10 = Scaleform::GFx::AS2::GFx_StringToIMEStyleCategory(&result);
      v11 = v10;
      if ( v10 >= 5 )
      {
        pNode = result.pNode;
        v13 = result.pNode->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_25:
        RefCount = v2->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v2->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v2);
        }
        return;
      }
      IMECompositionStringStyles = Scaleform::GFx::AS2::TextFieldObject::GetIMECompositionStringStyles(v2);
      *(_QWORD *)&imeStyles.HighlightStyles[0].TextColor.Channels.Blue = 0i64;
      imeStyles.HighlightStyles[0].BackgroundColor.Raw = 0;
      imeStyles.HighlightStyles[0].Flags = 0;
      *(_QWORD *)&imeStyles.HighlightStyles[1].TextColor.Channels.Blue = 0i64;
      imeStyles.HighlightStyles[1].BackgroundColor.Raw = 0;
      imeStyles.HighlightStyles[1].Flags = 0;
      *(_QWORD *)&imeStyles.HighlightStyles[2].TextColor.Channels.Blue = 0i64;
      imeStyles.HighlightStyles[2].BackgroundColor.Raw = 0;
      imeStyles.HighlightStyles[2].Flags = 0;
      *(_QWORD *)&imeStyles.HighlightStyles[3].TextColor.Channels.Blue = 0i64;
      imeStyles.HighlightStyles[3].BackgroundColor.Raw = 0;
      imeStyles.HighlightStyles[3].Flags = 0;
      *(_QWORD *)&imeStyles.HighlightStyles[4].TextColor.Channels.Blue = 0i64;
      imeStyles.HighlightStyles[4].BackgroundColor.Raw = 0;
      imeStyles.HighlightStyles[4].Flags = 0;
      PresenceMask = 0;
      imeStyles.PresenceMask = 0;
      if ( IMECompositionStringStyles )
      {
        imeStyles.HighlightStyles[0].BackgroundColor.Raw = IMECompositionStringStyles->HighlightStyles[0].BackgroundColor.Raw;
        imeStyles.HighlightStyles[0].TextColor.Raw = IMECompositionStringStyles->HighlightStyles[0].TextColor.Raw;
        imeStyles.HighlightStyles[0].UnderlineColor.Raw = IMECompositionStringStyles->HighlightStyles[0].UnderlineColor.Raw;
        imeStyles.HighlightStyles[0].Flags = IMECompositionStringStyles->HighlightStyles[0].Flags;
        imeStyles.HighlightStyles[1] = IMECompositionStringStyles->HighlightStyles[1];
        imeStyles.HighlightStyles[2] = IMECompositionStringStyles->HighlightStyles[2];
        imeStyles.HighlightStyles[3] = IMECompositionStringStyles->HighlightStyles[3];
        imeStyles.HighlightStyles[4] = IMECompositionStringStyles->HighlightStyles[4];
        PresenceMask = IMECompositionStringStyles->PresenceMask;
        imeStyles.PresenceMask = PresenceMask;
      }
      v16 = &imeStyles.HighlightStyles[v11];
      v17 = Scaleform::GFx::AS2::TextFieldProto::ParseStyle(&v20, fn, 1u, v16);
      imeStyles.PresenceMask = (1 << v11) | PresenceMask;
      *v16 = *v17;
      Scaleform::GFx::AS2::TextFieldObject::SetIMECompositionStringStyles(v2, &imeStyles);
      v18 = result.pNode;
      v13 = result.pNode->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
LABEL_24:
    if ( !v2 )
      return;
    goto LABEL_25;
  }
}

// File Line: 3011
// RVA: 0x6A9B50
void __fastcall Scaleform::GFx::AS2::TextFieldProto::GetIMECompositionStringStyle(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // rbx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rax
  Scaleform::GFx::AS2::AvmTextField *p_pProto; // rcx
  Scaleform::GFx::AS2::TextFieldObject *TextFieldASObject; // rax
  Scaleform::GFx::AS2::ObjectInterface *v8; // rbx
  Scaleform::GFx::Text::IMEStyle *pRCC; // rbp
  Scaleform::GFx::AS2::TextFieldObject *v10; // rbp
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  int v13; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v19; // [rsp+58h] [rbp+10h]

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 0;
  if ( fn->ThisPtr )
  {
    v3 = 0i64;
    v4 = 0i64;
    v19 = 0i64;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 4 )
    {
      ThisPtr = fn->ThisPtr;
      p_pProto = (Scaleform::GFx::AS2::AvmTextField *)&ThisPtr[-1].pProto;
      if ( !ThisPtr )
        p_pProto = 0i64;
      TextFieldASObject = Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(p_pProto);
      v4 = TextFieldASObject;
      if ( TextFieldASObject )
        TextFieldASObject->RefCount = (TextFieldASObject->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr) != 13 )
        goto LABEL_25;
      v8 = fn->ThisPtr;
      if ( v8 )
      {
        v4 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v8[-2];
        if ( v4 )
          v4->RefCount = (v4->RefCount + 1) & 0x8FFFFFFF;
      }
      else
      {
        v4 = 0i64;
      }
    }
    v19 = v4;
    if ( v4 )
    {
      pRCC = (Scaleform::GFx::Text::IMEStyle *)v4[3].pRCC;
      if ( pRCC
        || (v10 = (Scaleform::GFx::AS2::TextFieldObject *)v4[1].pRCC) != 0i64
        && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v10->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->gap8[8])(&v10->Scaleform::GFx::AS2::ObjectInterface) == 13
        && (pRCC = Scaleform::GFx::AS2::TextFieldObject::GetIMECompositionStringStyles(v10)) != 0i64 )
      {
        FirstArgBottomIndex = fn->FirstArgBottomIndex;
        Env = fn->Env;
        if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                  + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
          v3 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
        Scaleform::GFx::AS2::Value::ToString(v3, &result, Env, -1);
        v13 = Scaleform::GFx::AS2::GFx_StringToIMEStyleCategory(&result);
        if ( v13 >= 5 )
        {
          pNode = result.pNode;
          v15 = result.pNode->RefCount-- == 1;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
LABEL_26:
          RefCount = v4->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v4->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
          }
          return;
        }
        Scaleform::GFx::AS2::TextFieldProto::MakeStyle(fn, &pRCC->HighlightStyles[v13]);
        v16 = result.pNode;
        v15 = result.pNode->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v16);
      }
    }
LABEL_25:
    if ( !v4 )
      return;
    goto LABEL_26;
  }
}

