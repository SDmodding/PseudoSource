// File Line: 34
// RVA: 0x6C7850
void __fastcall Scaleform::GFx::AS2::AvmTextField::AvmTextField(Scaleform::GFx::AS2::AvmTextField *this, Scaleform::GFx::TextField *ptf)
{
  Scaleform::GFx::TextField *v2; // r14
  Scaleform::GFx::AS2::AvmTextField *v3; // rsi
  Scaleform::String *v4; // rbx
  Scaleform::GFx::ASStringManager *v5; // rax
  Scaleform::GFx::AS2::Environment *v6; // rdx
  Scaleform::GFx::InteractiveObject *v7; // rax
  signed __int64 v8; // rcx
  Scaleform::GFx::AS2::Object *v9; // rax
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  signed __int64 v13; // rcx
  __int64 v14; // rax
  signed __int64 v15; // rcx
  Scaleform::GFx::AS2::Environment *v16; // rax
  Scaleform::GFx::AvmTextFieldBase *v17; // [rsp+58h] [rbp+10h]

  v2 = ptf;
  v3 = this;
  Scaleform::GFx::AS2::AvmCharacter::AvmCharacter(
    (Scaleform::GFx::AS2::AvmCharacter *)&this->vfptr,
    (Scaleform::GFx::InteractiveObject *)&ptf->vfptr);
  v17 = (Scaleform::GFx::AvmTextFieldBase *)&v3->vfptr;
  v17->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmDisplayObjBase::`vftable;
  v17->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmInteractiveObjBase::`vftable;
  v17->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AvmTextFieldBase::`vftable;
  v3->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmTextField::`vftable{for `Scaleform::GFx::AvmInteractiveObjBase};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::AvmTextField::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v17->vfptr = (Scaleform::GFx::AvmDisplayObjBaseVtbl *)&Scaleform::GFx::AS2::AvmTextField::`vftable;
  v4 = (Scaleform::String *)v2->pDef.pObject;
  v5 = Scaleform::GFx::InteractiveObject::GetStringManager((Scaleform::GFx::InteractiveObject *)&v2->vfptr);
  Scaleform::GFx::ASStringManager::CreateString(v5, &v3->VariableName, v4 + 15);
  v3->VariableVal.T.Type = 0;
  v6 = 0i64;
  v3->ASTextFieldObj.pObject = 0i64;
  if ( v3->VariableName.pNode->Size )
    v2->Flags |= 0x8000u;
  v7 = v3->pDispObj->pParent;
  if ( v7 )
  {
    while ( !((v7->Flags >> 10) & 1) )
    {
      v7 = v7->pParent;
      if ( !v7 )
        goto LABEL_8;
    }
    v8 = (signed __int64)v7 + 4 * (unsigned __int8)v7->AvmObjOffset;
    v6 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v8 + 240i64))(v8);
  }
LABEL_8:
  v9 = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
         (Scaleform::GFx::AS2::GlobalContext *)v3->pDispObj->pASRoot[2].vfptr,
         v6,
         ASBuiltin_TextField);
  v10 = v9;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
  v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v3->pProto.pObject->vfptr;
  if ( v11 )
  {
    v12 = v11->RefCount;
    if ( v12 & 0x3FFFFFF )
    {
      v11->RefCount = v12 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  v3->pProto.pObject = v10;
  v13 = (signed __int64)v2 + 4 * (unsigned __int8)v2->AvmObjOffset;
  v14 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v13 + 240i64))(v13);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    (Scaleform::GFx::AS2::ASStringContext *)(v14 + 232),
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr);
  v15 = (signed __int64)v2 + 4 * (unsigned __int8)v2->AvmObjOffset;
  v16 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v15 + 240i64))(v15);
  Scaleform::GFx::AS2::AsBroadcaster::AddListener(
    v16,
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr);
}

// File Line: 52
// RVA: 0x6EE330
Scaleform::GFx::AS2::TextFieldObject *__fastcall Scaleform::GFx::AS2::AvmTextField::GetASObject(Scaleform::GFx::AS2::AvmTextField *this)
{
  return Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(this);
}

// File Line: 69
// RVA: 0x6F6840
Scaleform::GFx::AS2::TextFieldObject *__fastcall Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::AvmTextField *v1; // rbx
  Scaleform::GFx::AS2::TextFieldObject *v2; // rdi
  Scaleform::GFx::AS2::GlobalContext *v3; // rax
  Scaleform::GFx::AS2::TextFieldObject *v4; // rax
  Scaleform::GFx::AS2::TextFieldObject *v5; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v6; // rcx
  unsigned int v7; // eax
  int v9; // [rsp+48h] [rbp+10h]
  Scaleform::GFx::AS2::TextFieldObject *v10; // [rsp+50h] [rbp+18h]

  v1 = this;
  if ( this->ASTextFieldObj.pObject )
    return this->ASTextFieldObj.pObject;
  v9 = 323;
  v2 = (Scaleform::GFx::AS2::TextFieldObject *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::AvmTextField *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this,
                                                 112i64,
                                                 &v9,
                                                 -2i64);
  v10 = v2;
  if ( v2 )
  {
    v3 = (Scaleform::GFx::AS2::GlobalContext *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmTextField *))v1->vfptr[1].OnUnloading)(v1);
    Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(v2, v3, v1->pDispObj);
    v5 = v4;
  }
  else
  {
    v5 = 0i64;
  }
  v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->ASTextFieldObj.pObject->vfptr;
  if ( v6 )
  {
    v7 = v6->RefCount;
    if ( v7 & 0x3FFFFFF )
    {
      v6->RefCount = v7 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  v1->ASTextFieldObj.pObject = v5;
  return v5;
}

// File Line: 102
// RVA: 0x7069C0
char __fastcall Scaleform::GFx::AS2::AvmTextField::OnMouseEvent(Scaleform::GFx::AS2::AvmTextField *this, Scaleform::GFx::EventId *event)
{
  Scaleform::GFx::AS2::AvmTextField *v2; // rsi
  Scaleform::GFx::TextField *v3; // rbx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // rbx
  __int64 v6; // r14
  const char *v7; // rbx
  char *v8; // rdi
  signed int v9; // er15
  signed __int64 v10; // rdi
  __int64 v11; // rbx
  __int64 v12; // rdx
  char v14; // [rsp+40h] [rbp-39h]
  __int64 v15; // [rsp+50h] [rbp-29h]
  unsigned int v16; // [rsp+58h] [rbp-21h]
  __int64 v17; // [rsp+60h] [rbp-19h]
  char v18; // [rsp+70h] [rbp-9h]
  __int64 v19; // [rsp+80h] [rbp+7h]
  unsigned int v20; // [rsp+88h] [rbp+Fh]
  __int64 v21; // [rsp+90h] [rbp+17h]
  Scaleform::String v22; // [rsp+E8h] [rbp+6Fh]
  Scaleform::Render::Point<float> pPnt; // [rsp+F0h] [rbp+77h]
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+F8h] [rbp+7Fh]

  v2 = this;
  if ( event->Id != 2048 )
    return 0;
  v3 = (Scaleform::GFx::TextField *)*((_QWORD *)&this[-1].VariableVal.NV + 3);
  if ( (v3->Flags >> 1) & 1 )
  {
    if ( v3->pDocument.pObject->pDocument.pObject->RTFlags & 1 )
    {
      if ( Scaleform::GFx::TextField::IsUrlUnderMouseCursor(v3, event->ControllerIndex, &pPnt, 0i64) )
      {
        v4 = Scaleform::Render::Text::DocView::GetCharIndexAtPoint(v3->pDocument.pObject, pPnt.x, pPnt.y);
        if ( v4 != -1i64
          && Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
               (Scaleform::Render::Text::StyledText *)&v3->pDocument.pObject->pDocument.pObject->vfptr,
               &ppdestTextFmt,
               0i64,
               v4)
          && Scaleform::Render::Text::TextFormat::IsUrlSet(ppdestTextFmt) )
        {
          v5 = ppdestTextFmt->Url.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64;
          v6 = *(_QWORD *)(*(_QWORD *)(*((_QWORD *)&v2[-1].VariableVal.NV + 3) + 32i64) + 16i64);
          if ( v6 )
          {
            if ( !Scaleform::String::CompareNoCase((const char *)(v5 + 12), "asfunction:", 11i64) )
            {
              v7 = (const char *)(v5 + 23);
              v8 = strchr(v7, 44);
              Scaleform::String::String(&v22);
              v15 = 0i64;
              v16 = 0;
              v9 = 0;
              if ( v8 )
              {
                Scaleform::String::AppendString(&v22, v7, v8 - v7);
                v10 = (signed __int64)(v8 + 1);
                v9 = 1;
                if ( (v16 >> 6) & 1 )
                {
                  (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
                  v15 = 0i64;
                }
                v16 = 6;
                v17 = v10;
              }
              else
              {
                Scaleform::String::operator=(&v22, v7);
              }
              v19 = 0i64;
              v20 = 0;
              v11 = *(_QWORD *)(*((_QWORD *)&v2[-1].VariableVal.NV + 3) + 56i64);
              if ( v11 )
                ++*(_DWORD *)(v11 + 8);
              if ( !v11 )
                goto LABEL_35;
              v12 = 0i64;
              if ( (*(_WORD *)(v11 + 106) >> 10) & 1 )
                v12 = v11;
              if ( v12 )
                (*(void (__fastcall **)(_QWORD, __int64, unsigned __int64, char *, char *, signed int, signed __int64, __int64))(**(_QWORD **)(v6 + 24) + 488i64))(
                  *(_QWORD *)(v6 + 24),
                  v12,
                  (v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                  &v18,
                  &v14,
                  v9,
                  -2i64,
                  v11);
              else
LABEL_35:
                (*(void (__fastcall **)(_QWORD, unsigned __int64, char *, char *, signed int))(**(_QWORD **)(v6 + 24)
                                                                                             + 448i64))(
                  *(_QWORD *)(v6 + 24),
                  (v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12,
                  &v18,
                  &v14,
                  v9);
              if ( v11 )
                Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)v11);
              if ( (v20 >> 6) & 1 )
              {
                (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
                v19 = 0i64;
              }
              v20 = 0;
              if ( (v16 >> 6) & 1 )
              {
                (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &v14, v17);
                v15 = 0i64;
              }
              v16 = 0;
              if ( !_InterlockedDecrement((volatile signed __int32 *)((v22.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
                ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
            }
          }
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
  Scaleform::GFx::AS2::AvmTextField *v1; // rbx
  Scaleform::GFx::TextField *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // rax
  bool v4; // si
  __int64 v5; // rdx
  __int64 v6; // r8
  Scaleform::GFx::AS2::Value presult; // [rsp+48h] [rbp-30h]

  v1 = this;
  v2 = (Scaleform::GFx::TextField *)this->pDispObj;
  if ( Scaleform::String::GetLength((Scaleform::String *)&v2->pDef.pObject->DefaultText.0) )
  {
    if ( !v1->VariableName.pNode->Size )
      goto LABEL_12;
    v2->Flags |= 0x8000u;
    v3 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::AvmTextField *))v1->vfptr[2].GetAbsolutePath)(v1);
    if ( !v3 )
      goto LABEL_12;
    presult.T.Type = 0;
    v4 = Scaleform::GFx::AS2::Environment::GetVariable(v3, &v1->VariableName, &presult, 0i64);
    if ( presult.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&presult);
    if ( !v4 )
    {
LABEL_12:
      Scaleform::GFx::TextField::SetTextValue(
        v2,
        (const char *)(((_QWORD)v1->pDispObj[1].vfptr[14].__vecDelDtor & 0xFFFFFFFFFFFFFFFCui64) + 12),
        (v2->Flags >> 1) & 1,
        1);
      ((void (__cdecl *)(Scaleform::GFx::AvmDisplayObjBaseVtbl **, __int64, __int64))v1->vfptr[2].OnEvent)(
        &v1->vfptr,
        v5,
        v6);
    }
  }
  else
  {
    Scaleform::GFx::TextField::SetTextValue(v2, &customWorldMapCaption, (v2->Flags >> 1) & 1, 0);
  }
  ((void (*)(void))v1->vfptr[2].HasEventHandler)();
}

// File Line: 227
// RVA: 0x723080
char __fastcall Scaleform::GFx::AS2::AvmTextField::UpdateTextFromVariable(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::AvmTextField *v1; // rbx
  Scaleform::GFx::TextField *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // rsi
  Scaleform::GFx::ASStringNode *v4; // rcx
  bool v5; // zf
  Scaleform::GFx::AS2::Value presult; // [rsp+48h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h]

  v1 = this;
  if ( LODWORD(this->vfptr->GetMember) )
  {
    v2 = (Scaleform::GFx::TextField *)*((_QWORD *)&this[-1].VariableVal.NV + 3);
    v2->Flags |= 0x8000u;
    v3 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (**)(void))(*(_QWORD *)&this[-1].VariableVal.T.Type + 240i64))();
    if ( v3 )
    {
      presult.T.Type = 0;
      if ( Scaleform::GFx::AS2::Environment::GetVariable(v3, (Scaleform::GFx::ASString *)&v1->vfptr, &presult, 0i64) )
      {
        if ( !Scaleform::GFx::AS2::Value::IsEqual(&presult, v3, (Scaleform::GFx::AS2::Value *)&v1->pProto) )
        {
          Scaleform::GFx::AS2::Value::operator=((Scaleform::GFx::AS2::Value *)&v1->pProto, &presult, (__int64)v2);
          Scaleform::GFx::AS2::Value::ToString(&presult, &result, v3, -1);
          Scaleform::GFx::TextField::SetTextValue(v2, result.pNode->pData, 0, 0);
          v4 = result.pNode;
          v5 = result.pNode->RefCount == 1;
          --v4->RefCount;
          if ( v5 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v4);
          if ( presult.T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&presult);
          return 1;
        }
      }
      else
      {
        Scaleform::GFx::TextField::SetTextValue(v2, &customWorldMapCaption, 0, 0);
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
signed __int64 __fastcall Scaleform::GFx::AS2::AvmTextField::GetStandardMemberBitMask(Scaleform::GFx::AS2::AvmTextField *this)
{
  return 1652404175i64;
}

// File Line: 280
// RVA: 0x722F10
void __fastcall Scaleform::GFx::AS2::AvmTextField::UpdateAutosizeSettings(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::InteractiveObject *v1; // rbx
  char v2; // di
  bool v3; // al

  v1 = this->pDispObj;
  v2 = BYTE4(v1[1].pASRoot) & 1;
  v3 = v2 && !(*(_BYTE *)(*(_QWORD *)&v1[1].RefCount + 344i64) & 8);
  if ( v3 )
    Scaleform::Render::Text::DocView::SetAutoSizeX(*(Scaleform::Render::Text::DocView **)&v1[1].RefCount);
  else
    *(_BYTE *)(*(_QWORD *)&v1[1].RefCount + 344i64) &= 0xFEu;
  if ( v2 )
    Scaleform::Render::Text::DocView::SetAutoSizeY(*(Scaleform::Render::Text::DocView **)&v1[1].RefCount);
  else
    *(_BYTE *)(*(_QWORD *)&v1[1].RefCount + 344i64) &= 0xFDu;
  HIDWORD(v1[1].pASRoot) |= 0x2000u;
  Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v1);
}

// File Line: 296
// RVA: 0x715A60
_BOOL8 __fastcall Scaleform::GFx::AS2::AvmTextField::SetMember(Scaleform::GFx::AS2::AvmTextField *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *origVal)
{
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::ASString *v5; // r15
  Scaleform::GFx::AS2::Environment *v6; // rsi
  Scaleform::GFx::AS2::AvmTextField *v7; // r14
  unsigned int v8; // ebx
  Scaleform::GFx::TextField *v9; // rdi
  unsigned int v10; // eax
  Scaleform::GFx::ASStringNode *v11; // rcx
  unsigned int v12; // eax
  unsigned int v13; // eax
  bool v14; // al
  const char *v15; // rdx
  Scaleform::Render::Text::DocView *v16; // r8
  int v17; // er10
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
  bool v29; // al
  Scaleform::Render::Text::DocView *v30; // rcx
  char v31; // bl
  bool v32; // al
  Scaleform::Render::Text::DocView *v33; // rax
  Scaleform::GFx::ASString *v34; // rax
  Scaleform::GFx::ASStringNode *v35; // rcx
  bool v36; // al
  Scaleform::Render::Text::DocView *v37; // rax
  char v38; // bl
  bool v39; // al
  Scaleform::Render::Text::DocView *v40; // rax
  signed int v41; // eax
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
  Scaleform::GFx::AS2::Value newVal; // [rsp+30h] [rbp-A8h]
  Scaleform::GFx::ASString v151; // [rsp+50h] [rbp-88h]
  Scaleform::GFx::ASString v152; // [rsp+58h] [rbp-80h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp-78h]
  Scaleform::GFx::ASString v154; // [rsp+68h] [rbp-70h]
  Scaleform::GFx::ASString v155; // [rsp+70h] [rbp-68h]
  Scaleform::GFx::ASString v156; // [rsp+78h] [rbp-60h]
  Scaleform::String v157; // [rsp+80h] [rbp-58h]
  Scaleform::GFx::ASString v158; // [rsp+88h] [rbp-50h]
  Scaleform::GFx::ASString v159; // [rsp+90h] [rbp-48h]
  Scaleform::GFx::ASString v160; // [rsp+98h] [rbp-40h]
  Scaleform::Ptr<Scaleform::GFx::Text::EditorKit> v161; // [rsp+A0h] [rbp-38h]
  Scaleform::GFx::ASString v162; // [rsp+A8h] [rbp-30h]
  Scaleform::GFx::ASString v163; // [rsp+B0h] [rbp-28h]
  Scaleform::GFx::ASString v164; // [rsp+B8h] [rbp-20h]
  Scaleform::GFx::AS2::Value v; // [rsp+C0h] [rbp-18h]
  __int64 v166; // [rsp+E0h] [rbp+8h]
  Scaleform::GFx::ASString v167; // [rsp+138h] [rbp+60h]

  v166 = -2i64;
  v4 = origVal;
  v5 = name;
  v6 = penv;
  v7 = this;
  v8 = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
         (Scaleform::GFx::AS2::AvmCharacter *)&this[-1].ASTextFieldObj,
         name);
  Scaleform::GFx::AS2::Value::Value(&newVal, v4, (__int64)v4);
  if ( v8 > 0x15
    && v6
    && Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject((Scaleform::GFx::AS2::AvmTextField *)((char *)v7 - 8))
    && *(_QWORD *)(*((_QWORD *)&v7->VariableVal.NV + 3) + 80i64) )
  {
    v.T.Type = 0;
    if ( (unsigned __int8)Scaleform::GFx::AS2::Object::InvokeWatchpoint(
                            *((Scaleform::GFx::AS2::Object **)&v7->VariableVal.NV + 3),
                            v6,
                            v5,
                            &newVal,
                            &v) )
      Scaleform::GFx::AS2::Value::operator=(&newVal, &v, (__int64)v4);
    if ( v.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
  }
  if ( !((unsigned __int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *, _QWORD, Scaleform::GFx::AS2::Value *, _QWORD))v7[-1].ASTextFieldObj.pObject[2].Members.mHash.pTable)(
          &v7[-1].ASTextFieldObj,
          v8,
          v4,
          0i64) )
  {
    v9 = (Scaleform::GFx::TextField *)v7->pProto.pObject;
    switch ( v8 )
    {
      case 0x19u:
      case 0x2Fu:
        goto $LN256;
      case 0x28u:
        Scaleform::GFx::TextField::ResetBlink((Scaleform::GFx::TextField *)v7->pProto.pObject, 1, 0);
        v12 = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)v7->pProto.pObject);
        Scaleform::GFx::AS2::Value::ToStringVersioned(&newVal, &v155, v6, v12);
        Scaleform::GFx::TextField::SetTextValue(v9, v155.pNode->pData, 0, 1);
        v11 = v155.pNode;
        goto LABEL_296;
      case 0x2Bu:
        v13 = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, v6);
        Scaleform::GFx::TextField::SetTextColor(v9, v13);
        goto $LN256;
      case 0x2Du:
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v6) )
          v9->Flags |= 2u;
        else
          v9->Flags &= 0xFFFFFFFD;
        goto $LN256;
      case 0x2Eu:
        v10 = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)v7->pProto.pObject);
        Scaleform::GFx::AS2::Value::ToStringVersioned(&newVal, &result, v6, v10);
        Scaleform::GFx::TextField::SetTextValue(v9, result.pNode->pData, (v9->Flags >> 1) & 1, 1);
        v11 = result.pNode;
        goto LABEL_296;
      case 0x30u:
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v154, v6, -1);
        if ( newVal.T.Type == 2 )
        {
          v14 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
          v15 = "none";
          if ( v14 )
            v15 = "left";
        }
        else
        {
          v15 = v154.pNode->pData;
        }
        Scaleform::String::String(&v157, v15);
        v16 = v9->pDocument.pObject;
        v17 = v16->AlignProps & 3;
        v18 = v9->Flags & 1;
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
            v9->Flags &= 0xFFFFFFFE;
            v16->AlignProps &= 0xFCu;
LABEL_37:
            v16->RTFlags |= 1u;
            goto LABEL_38;
          }
        }
        v9->Flags |= 1u;
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
            v16->AlignProps &= 0xFDu;
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
            v16->AlignProps &= 0xFEu;
            v16->AlignProps |= 2u;
            goto LABEL_37;
          }
        }
LABEL_38:
        if ( v17 != (v9->pDocument.pObject->AlignProps & 3) || v18 != (v9->Flags & 1) )
          Scaleform::GFx::AS2::AvmTextField::UpdateAutosizeSettings((Scaleform::GFx::AS2::AvmTextField *)((char *)v7 - 8));
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v7->pProto.pObject);
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v157.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v11 = v154.pNode;
        goto LABEL_296;
      case 0x31u:
        v28 = ((unsigned __int8)v9->pDocument.pObject->Flags >> 3) & 1;
        v29 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
        if ( v29 != v28 )
        {
          v30 = v9->pDocument.pObject;
          if ( v29 )
            Scaleform::Render::Text::DocView::SetWordWrap(v30);
          else
            Scaleform::Render::Text::DocView::ClearWordWrap(v30);
          Scaleform::GFx::AS2::AvmTextField::UpdateAutosizeSettings((Scaleform::GFx::AS2::AvmTextField *)((char *)v7 - 8));
        }
        goto LABEL_66;
      case 0x32u:
        v31 = ((unsigned __int8)v9->pDocument.pObject->Flags >> 2) & 1;
        v32 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
        if ( v31 != v32 )
        {
          v51 = v32 == 0;
          v33 = v9->pDocument.pObject;
          if ( v51 )
            v33->Flags &= 0xFBu;
          else
            v33->Flags |= 4u;
          Scaleform::GFx::AS2::AvmTextField::UpdateAutosizeSettings((Scaleform::GFx::AS2::AvmTextField *)((char *)v7 - 8));
        }
        goto LABEL_66;
      case 0x33u:
        v43 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
        Scaleform::GFx::TextField::SetBorder(v9, v43);
        goto $LN256;
      case 0x34u:
        v34 = Scaleform::GFx::AS2::Value::ToString(&newVal, &v158, v6, -1);
        Scaleform::GFx::ASString::operator=((Scaleform::GFx::ASString *)&v7->vfptr, v34);
        v35 = v158.pNode;
        v51 = v158.pNode->RefCount == 1;
        --v35->RefCount;
        if ( v51 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
        ((void (*)(void))v7->EventHandlers.mHash.pTable[15].SizeMask)();
        v9->Flags |= 0x8000u;
        Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>((Scaleform::GFx::InteractiveObject *)&v9->vfptr);
        goto $LN256;
      case 0x35u:
        v36 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
        Scaleform::GFx::TextField::SetSelectable(v9, v36);
        goto $LN256;
      case 0x36u:
        v51 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6) == 0;
        v37 = v9->pDocument.pObject;
        if ( v51 )
          v37->Flags |= 0x20u;
        else
          v37->Flags &= 0xDFu;
        goto LABEL_65;
      case 0x37u:
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v151, v6, -1);
        v64 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v6->StringContext, &v162, "normal");
        v65 = v64;
        if ( v6->StringContext.SWFVersion <= 6u )
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
        v51 = v162.pNode->RefCount == 1;
        --v69->RefCount;
        if ( v51 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v69);
        if ( v68 )
        {
          v9->pDocument.pObject->Flags &= 0xBFu;
        }
        else
        {
          v70 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v6->StringContext, &v159, "advanced");
          v71 = v70;
          if ( v6->StringContext.SWFVersion <= 6u )
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
          v51 = v159.pNode->RefCount == 1;
          --v75->RefCount;
          if ( v51 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v75);
          if ( v74 )
            v9->pDocument.pObject->Flags |= 0x40u;
        }
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v7->pProto.pObject);
        v11 = v151.pNode;
        goto LABEL_296;
      case 0x38u:
        v41 = Scaleform::GFx::AS2::Value::ToInt32(&newVal, v6);
        if ( v41 < 0 )
          v41 = 0;
        Scaleform::Render::Text::DocView::SetHScrollOffset(v9->pDocument.pObject, (signed int)((double)v41 * 20.0));
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v7->pProto.pObject);
        goto $LN256;
      case 0x39u:
        v42 = Scaleform::GFx::AS2::Value::ToInt32(&newVal, v6);
        if ( v42 < 1 )
          v42 = 1;
        Scaleform::Render::Text::DocView::SetVScrollOffset(v9->pDocument.pObject, v42 - 1);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v7->pProto.pObject);
        goto $LN256;
      case 0x3Cu:
        v44 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
        Scaleform::GFx::TextField::SetBackground(v9, v44);
        goto $LN256;
      case 0x3Du:
        v45 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6);
        if ( !Scaleform::GFx::NumberUtil::IsNaN(v45) )
        {
          v46 = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, v6);
          Scaleform::GFx::TextField::SetBackgroundColor(v9, v46);
        }
        goto $LN256;
      case 0x3Eu:
        v47 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6);
        if ( !Scaleform::GFx::NumberUtil::IsNaN(v47) )
        {
          v48 = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, v6);
          Scaleform::GFx::TextField::SetBorderColor(v9, v48);
        }
        goto $LN256;
      case 0x40u:
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v167, v6, -1);
        v49 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v6->StringContext, &v164, "dynamic");
        v50 = v49;
        if ( v6->StringContext.SWFVersion <= 6u )
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
        v51 = v164.pNode->RefCount == 1;
        --v54->RefCount;
        if ( v51 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v54);
        if ( v53 )
        {
          v55 = v9->pDocument.pObject;
          if ( v55->pEditorKit.pObject )
            LOWORD(v55->pEditorKit.pObject[10].vfptr) |= 1u;
        }
        else
        {
          v56 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v6->StringContext, &v163, "input");
          v57 = v56;
          if ( v6->StringContext.SWFVersion <= 6u )
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
          v51 = v163.pNode->RefCount == 1;
          --v61->RefCount;
          if ( v51 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v61);
          if ( v60 && !((unsigned __int8 (*)(void))v7->EventHandlers.mHash.pTable[11].SizeMask)() )
          {
            v62 = Scaleform::GFx::TextField::CreateEditorKit(v9, &v161)->pObject;
            if ( v161.pObject )
              Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v161.pObject);
            v62->Flags &= 0xFFFEu;
          }
        }
        v9->pDocument.pObject->RTFlags |= 1u;
        v11 = v167.pNode;
        goto LABEL_296;
      case 0x41u:
        v63 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6);
        if ( !Scaleform::GFx::NumberUtil::IsNaN(v63) && v63 >= 0.0 )
          v9->pDocument.pObject->MaxLength = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, v6);
        goto $LN256;
      case 0x42u:
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v6) )
          v9->Flags |= 0x10u;
        else
          v9->Flags &= 0xFFFFFFEF;
        goto $LN256;
      case 0x43u:
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v6) )
          v9->Flags |= 0x80u;
        else
          v9->Flags &= 0xFFFFFF7F;
        goto $LN256;
      case 0x44u:
        v38 = (v9->Flags >> 2) & 1;
        v39 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
        if ( v38 != v39 )
        {
          v51 = v39 == 0;
          v40 = v9->pDocument.pObject;
          if ( v51 )
          {
            v9->Flags &= 0xFFFFFFFB;
            v40->Flags &= 0xEFu;
          }
          else
          {
            v9->Flags |= 4u;
            v40->Flags |= 0x10u;
          }
LABEL_65:
          v9->pDocument.pObject->RTFlags |= 2u;
        }
LABEL_66:
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v7->pProto.pObject);
        goto $LN256;
      case 0x45u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v152, v6, -1);
        Scaleform::GFx::TextField::SetShadowStyle(v9, v152.pNode->pData);
        v11 = v152.pNode;
        goto LABEL_296;
      case 0x46u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v76 = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, v6);
        Scaleform::GFx::TextField::SetShadowColor(v9, v76);
        goto $LN256;
      case 0x47u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v77 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))v7[-1].ASTextFieldObj.pObject[2].pPrev)(&v7[-1].ASTextFieldObj);
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v77) )
          v9->Flags |= 0x800u;
        else
          v9->Flags &= 0xFFFFF7FF;
        goto $LN256;
      case 0x48u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v78 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))v7[-1].ASTextFieldObj.pObject[2].pPrev)(&v7[-1].ASTextFieldObj);
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v78) )
          v9->Flags |= 8u;
        else
          v9->Flags &= 0xFFFFFFF7;
        v9->pDocument.pObject->RTFlags |= 2u;
        goto $LN256;
      case 0x4Bu:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v156, v6, -1);
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
            v9->pDocument.pObject->Flags &= 0xFDu;
            v107 = v9->pDocument.pObject;
            v107->AlignProps &= 0xF3u;
LABEL_213:
            v107->RTFlags |= 1u;
            goto LABEL_214;
          }
        }
        Scaleform::Render::Text::DocView::SetAutoSizeY(v9->pDocument.pObject);
        v108 = (unsigned __int64)v152.pNode & 0xFFFFFFFFFFFFFFFCui64;
        v109 = 0i64;
        while ( 1 )
        {
          v110 = *(_BYTE *)(v108 + v109++ + 12);
          if ( v110 != aTop_2[v109 - 1] )
            break;
          if ( v109 == 4 )
          {
            v107 = v9->pDocument.pObject;
            v107->AlignProps &= 0xF7u;
            v107->AlignProps |= 4u;
            goto LABEL_213;
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
            v107 = v9->pDocument.pObject;
            v107->AlignProps &= 0xFBu;
            v107->AlignProps |= 8u;
            goto LABEL_213;
          }
        }
        while ( 1 )
        {
          v113 = *(_BYTE *)(v108 + v104++ + 12);
          if ( v113 != aCenter_0[v104 - 1] )
            break;
          if ( v104 == 7 )
          {
            v107 = v9->pDocument.pObject;
            v107->AlignProps |= 0xCu;
            goto LABEL_213;
          }
        }
LABEL_214:
        v9->Flags |= 0x2000u;
        Scaleform::GFx::TextField::SetDirtyFlag(v9);
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v7->pProto.pObject);
        if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v152.pNode & 0xFFFFFFFFFFFFFFFCui64)
                                                              + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v11 = v156.pNode;
        goto LABEL_296;
      case 0x4Cu:
        if ( v6->StringContext.pContext->GFxExtensions.Value == 1 )
        {
          v114 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6);
          if ( v114 > 0.0 && v114 < 1000.0 )
          {
            v115 = v114;
            Scaleform::Render::Text::DocView::SetFontScaleFactor(v9->pDocument.pObject, v115);
          }
          Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v7->pProto.pObject);
        }
        goto LABEL_295;
      case 0x4Du:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v156, v6, -1);
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
            v120 = v9->pDocument.pObject;
            v120->AlignProps &= 0xF3u;
LABEL_238:
            v120->RTFlags |= 1u;
            goto LABEL_239;
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
            v120 = v9->pDocument.pObject;
            v120->AlignProps &= 0xF7u;
            v120->AlignProps |= 4u;
            goto LABEL_238;
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
            v120 = v9->pDocument.pObject;
            v120->AlignProps &= 0xFBu;
            v120->AlignProps |= 8u;
            goto LABEL_238;
          }
        }
        while ( 1 )
        {
          v125 = *(_BYTE *)(v116 + v117++ + 12);
          if ( v125 != aCenter_0[v117 - 1] )
            break;
          if ( v117 == 7 )
          {
            v120 = v9->pDocument.pObject;
            v120->AlignProps |= 0xCu;
            goto LABEL_238;
          }
        }
LABEL_239:
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v7->pProto.pObject);
        if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)v154.pNode & 0xFFFFFFFFFFFFFFFCui64)
                                                              + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v11 = v156.pNode;
        goto LABEL_296;
      case 0x4Eu:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        Scaleform::GFx::AS2::Value::ToString(&newVal, &v155, v6, -1);
        Scaleform::String::String((Scaleform::String *)&result, v155.pNode->pData);
        v126 = (unsigned __int64)result.pNode & 0xFFFFFFFFFFFFFFFCui64;
        v127 = 0i64;
        v128 = 0i64;
        break;
      case 0x4Fu:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v134 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))v7[-1].ASTextFieldObj.pObject[2].pPrev)(&v7[-1].ASTextFieldObj);
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v134) )
          v9->Flags |= 0x100u;
        else
          v9->Flags &= 0xFFFFFEFF;
        v135 = v9->pDocument.pObject;
        if ( v135->pEditorKit.pObject )
        {
          v136 = v135->pEditorKit.pObject;
          if ( (LOWORD(v9->Flags) >> 8) & 1 )
            LOWORD(v136[10].vfptr) |= 4u;
          else
            LOWORD(v136[10].vfptr) &= 0xFFFBu;
        }
        goto $LN256;
      case 0x50u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v137 = (Scaleform::GFx::AS2::Environment *)((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))v7[-1].ASTextFieldObj.pObject[2].pPrev)(&v7[-1].ASTextFieldObj);
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v137) )
          v9->Flags |= 0x200u;
        else
          v9->Flags &= 0xFFFFFDFF;
        goto $LN256;
      case 0x53u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v140 = v9->pDocument.pObject;
        if ( !v140->pEditorKit.pObject )
          goto LABEL_295;
        v141 = (Scaleform::GFx::Text::EditorKit *)v140->pEditorKit.pObject;
        v141->ActiveSelectionBkColor = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, v6);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v141);
        goto $LN256;
      case 0x54u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v138 = v9->pDocument.pObject;
        if ( !v138->pEditorKit.pObject )
          goto LABEL_295;
        v139 = (Scaleform::GFx::Text::EditorKit *)v138->pEditorKit.pObject;
        v139->ActiveSelectionTextColor = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, v6);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v139);
        goto $LN256;
      case 0x55u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v144 = v9->pDocument.pObject;
        if ( !v144->pEditorKit.pObject )
          goto LABEL_295;
        v145 = (Scaleform::GFx::Text::EditorKit *)v144->pEditorKit.pObject;
        v145->InactiveSelectionBkColor = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, v6);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v145);
        goto $LN256;
      case 0x56u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v142 = v9->pDocument.pObject;
        if ( !v142->pEditorKit.pObject )
          goto LABEL_295;
        v143 = (Scaleform::GFx::Text::EditorKit *)v142->pEditorKit.pObject;
        v143->InactiveSelectionTextColor = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, v6);
        Scaleform::GFx::Text::EditorKit::InvalidateSelectionColors(v143);
        goto $LN256;
      case 0x57u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v6) )
          v9->Flags |= 0x400u;
        else
          v9->Flags &= 0xFFFFFBFF;
        goto $LN256;
      case 0x58u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        if ( Scaleform::GFx::AS2::Value::ToBool(&newVal, v6) )
          v9->Flags |= 0x800u;
        else
          v9->Flags &= 0xFFFFF7FF;
        goto $LN256;
      case 0x5Du:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v51 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6) == 0;
        v79 = v9->pDocument.pObject;
        if ( v51 )
          v79->Flags &= 0x7Fu;
        else
          v79->Flags |= 0x80u;
        goto LABEL_196;
      case 0x5Eu:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v80 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6) * 20.0;
        v9->pDocument.pObject->Filter.BlurX = v80;
        goto LABEL_196;
      case 0x5Fu:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v81 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6) * 20.0;
        v9->pDocument.pObject->Filter.BlurY = v81;
        goto LABEL_196;
      case 0x60u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v82 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6);
        v9->pDocument.pObject->Filter.BlurStrength = v82;
        goto LABEL_196;
      case 0x61u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v83 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6);
        v9->pDocument.pObject->Outline = v83;
        goto LABEL_196;
      case 0x62u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v84 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
        v85 = v9->pDocument.pObject;
        if ( v84 )
          v85->FlagsEx |= 1u;
        else
          v85->FlagsEx &= 0xFEu;
        goto LABEL_196;
      case 0x63u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v86 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
        v87 = v9->pDocument.pObject;
        if ( v86 )
          v87->FlagsEx |= 2u;
        else
          v87->FlagsEx &= 0xFDu;
        goto LABEL_196;
      case 0x64u:
        if ( newVal.T.Type <= 1u || newVal.T.Type == 10 )
        {
          Scaleform::GFx::TextField::ClearRestrict((Scaleform::GFx::TextField *)v7->pProto.pObject);
        }
        else
        {
          v146 = Scaleform::GFx::AS2::Value::ToString(&newVal, &v160, v6, -1);
          Scaleform::GFx::TextField::SetRestrict(v9, v146);
          v147 = v160.pNode;
          v51 = v160.pNode->RefCount == 1;
          --v147->RefCount;
          if ( v51 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v147);
        }
        goto LABEL_295;
      case 0x65u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v9->pDocument.pObject->Filter.ShadowFlags &= 0xFFFFFFFE;
        v88 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6);
        Scaleform::GFx::TextField::SetShadowAlpha(v9, v88);
        goto LABEL_196;
      case 0x66u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v9->pDocument.pObject->Filter.ShadowFlags &= 0xFFFFFFFE;
        v89 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6);
        v90 = v89 * 0.017453292;
        v91 = (float *)v9->pDocument.pObject;
        v91[77] = v90;
        v92 = v90;
        goto LABEL_175;
      case 0x67u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v9->pDocument.pObject->Filter.ShadowFlags &= 0xFFFFFFFE;
        v94 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6) * 20.0;
        v9->pDocument.pObject->Filter.ShadowParams.BlurX = v94;
        goto LABEL_196;
      case 0x68u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v9->pDocument.pObject->Filter.ShadowFlags &= 0xFFFFFFFE;
        v95 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6) * 20.0;
        v9->pDocument.pObject->Filter.ShadowParams.BlurY = v95;
        goto LABEL_196;
      case 0x69u:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v9->pDocument.pObject->Filter.ShadowFlags &= 0xFFFFFFFE;
        v96 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6);
        v91 = (float *)v9->pDocument.pObject;
        v91[78] = v96 * 20.0;
        v92 = v91[77];
LABEL_175:
        v93 = sinf(v92) * v91[78];
        v91[68] = cosf(v92) * v91[78];
        v91[69] = v93;
        goto LABEL_196;
      case 0x6Au:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v9->pDocument.pObject->Filter.ShadowFlags &= 0xFFFFFFFE;
        v97 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
        v98 = v9->pDocument.pObject;
        if ( v97 )
          v98->Filter.ShadowFlags |= 0x40u;
        else
          v98->Filter.ShadowFlags &= 0xFFFFFFBF;
        goto LABEL_196;
      case 0x6Bu:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v9->pDocument.pObject->Filter.ShadowFlags &= 0xFFFFFFFE;
        v99 = Scaleform::GFx::AS2::Value::ToBool(&newVal, v6);
        v100 = v9->pDocument.pObject;
        if ( v99 )
          v100->Filter.ShadowFlags |= 0x20u;
        else
          v100->Filter.ShadowFlags &= 0xFFFFFFDF;
        goto LABEL_196;
      case 0x6Cu:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v9->pDocument.pObject->Filter.ShadowFlags &= 0xFFFFFFFE;
        v101 = Scaleform::GFx::AS2::Value::ToUInt32(&newVal, v6);
        v102 = v9->pDocument.pObject;
        if ( v101 <= 1 )
          v102->Filter.ShadowFlags &= 0xFFFFFF7F;
        else
          v102->Filter.ShadowFlags |= 0x80u;
        goto LABEL_196;
      case 0x6Du:
        if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
          goto LABEL_295;
        v9->pDocument.pObject->Filter.ShadowFlags &= 0xFFFFFFFE;
        v103 = Scaleform::GFx::AS2::Value::ToNumber(&newVal, v6);
        v9->pDocument.pObject->Filter.ShadowParams.Strength = v103;
LABEL_196:
        Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v7->pProto.pObject);
        goto $LN256;
      default:
LABEL_295:
        v148 = Scaleform::GFx::AS2::AvmCharacter::SetMember(
                 (Scaleform::GFx::AS2::AvmCharacter *)&v7->vfptr,
                 v6,
                 v5,
                 &newVal);
        goto LABEL_299;
    }
    while ( 1 )
    {
      v129 = *(_BYTE *)(v126 + v128++ + 12);
      if ( v129 != aNone[v128 - 1] )
        break;
      if ( v128 == 5 )
      {
        v130 = v9->pDocument.pObject;
        v130->AlignProps &= 0xCFu;
LABEL_254:
        v130->RTFlags |= 1u;
        goto LABEL_255;
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
        v130 = v9->pDocument.pObject;
        v130->AlignProps &= 0xDFu;
        v130->AlignProps |= 0x10u;
        goto LABEL_254;
      }
    }
    while ( 1 )
    {
      v133 = *(_BYTE *)(v126 + v127++ + 12);
      if ( v133 != aFit[v127 - 1] )
        break;
      if ( v127 == 4 )
      {
        v130 = v9->pDocument.pObject;
        v130->AlignProps &= 0xEFu;
        v130->AlignProps |= 0x20u;
        goto LABEL_254;
      }
    }
LABEL_255:
    Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v7->pProto.pObject);
    if ( !_InterlockedDecrement((volatile signed __int32 *)(((unsigned __int64)result.pNode & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    v11 = v155.pNode;
LABEL_296:
    v51 = v11->RefCount-- == 1;
    if ( v51 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  }
$LN256:
  v148 = 1;
LABEL_299:
  if ( newVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&newVal);
  return v148;
}  if ( newVal.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&newVal);
  return v148;
}

// File Line: 998
// RVA: 0x6F0850
char __fastcall Scaleform::GFx::AS2::AvmTextField::GetMember(Scaleform::GFx::AS2::AvmTextField *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::ASString *name, Scaleform::GFx::AS2::Value *pval)
{
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::ASString *v5; // r12
  Scaleform::GFx::AS2::Environment *v6; // rsi
  Scaleform::GFx::AS2::AvmTextField *v7; // r13
  __int64 v8; // r14
  Scaleform::GFx::AS2::AvmCharacter::StandardMember v9; // er10
  Scaleform::GFx::AS2::Object *v10; // rbx
  char v11; // bl
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASString *v16; // rax
  unsigned int v17; // eax
  double v18; // xmm1_8
  signed __int64 v19; // rax
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::Render::Text::DocView *v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  unsigned int v25; // ecx
  Scaleform::GFx::AS2::Value *v26; // rcx
  Scaleform::GFx::ASString *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  double v29; // xmm0_8
  signed int v30; // ecx
  unsigned int v31; // eax
  Scaleform::GFx::ASString *v32; // rax
  signed int v33; // ebx
  Scaleform::GFx::ASStringNode *v34; // rcx
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASString *v36; // rax
  signed int v37; // ebx
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::ASStringNode *v39; // rcx
  Scaleform::Render::Text::DocView *v40; // rax
  Scaleform::GFx::ASString *v41; // rax
  Scaleform::GFx::ASStringNode *v42; // rcx
  Scaleform::GFx::ASString *v43; // rax
  Scaleform::GFx::ASString *v44; // rax
  Scaleform::GFx::ASString *v45; // rax
  Scaleform::GFx::ASString *v46; // rax
  unsigned int v47; // ecx
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
  Scaleform::Render::Text::EditorKitBase *v61; // rcx
  Scaleform::Render::Text::EditorKitBase *v62; // rcx
  Scaleform::Render::Text::EditorKitBase *v63; // rcx
  __int64 v64; // rcx
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v65; // rcx
  char v66; // al
  Scaleform::GFx::ASString v67; // [rsp+18h] [rbp-79h]
  Scaleform::GFx::ASString v68; // [rsp+20h] [rbp-71h]
  Scaleform::GFx::ASString v69; // [rsp+28h] [rbp-69h]
  Scaleform::GFx::ASString v70; // [rsp+30h] [rbp-61h]
  Scaleform::GFx::ASString v71; // [rsp+38h] [rbp-59h]
  Scaleform::GFx::ASString v72; // [rsp+40h] [rbp-51h]
  Scaleform::GFx::ASString v73; // [rsp+48h] [rbp-49h]
  Scaleform::GFx::ASString v74; // [rsp+50h] [rbp-41h]
  Scaleform::GFx::ASString v75; // [rsp+58h] [rbp-39h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp-31h]
  Scaleform::GFx::ASString v77; // [rsp+68h] [rbp-29h]
  Scaleform::GFx::ASString v78; // [rsp+70h] [rbp-21h]
  Scaleform::GFx::ASString v79; // [rsp+78h] [rbp-19h]
  Scaleform::GFx::ASString v80; // [rsp+80h] [rbp-11h]
  Scaleform::GFx::ASString v81; // [rsp+88h] [rbp-9h]
  Scaleform::GFx::ASString v82; // [rsp+90h] [rbp-1h]
  Scaleform::GFx::ASString v83; // [rsp+98h] [rbp+7h]
  Scaleform::GFx::ASString v84; // [rsp+A0h] [rbp+Fh]
  Scaleform::GFx::ASString v85; // [rsp+A8h] [rbp+17h]
  Scaleform::GFx::ASString v86; // [rsp+B0h] [rbp+1Fh]
  __int64 v87; // [rsp+B8h] [rbp+27h]
  Scaleform::GFx::ASString v88; // [rsp+F8h] [rbp+67h]

  v87 = -2i64;
  v4 = pval;
  v5 = name;
  v6 = penv;
  v7 = this;
  v8 = 0i64;
  LODWORD(v68.pNode) = 0;
  v9 = Scaleform::GFx::AS2::AvmCharacter::GetStandardMemberConstant(
         (Scaleform::GFx::AS2::AvmCharacter *)&this[-1].ASTextFieldObj,
         name);
  v10 = v7->pProto.pObject;
  switch ( v9 )
  {
    case 0x19u:
    case 0x2Fu:
      goto $LN104_5;
    case 0x28u:
      v16 = Scaleform::GFx::TextField::GetText((Scaleform::GFx::TextField *)v7->pProto.pObject, &v71, 0);
      Scaleform::GFx::AS2::Value::SetString(v4, v16);
      v14 = v71.pNode;
      goto LABEL_8;
    case 0x29u:
      v18 = Scaleform::GFx::TextField::GetTextWidth((Scaleform::GFx::TextField *)v7->pProto.pObject);
      goto LABEL_40;
    case 0x2Au:
      v18 = Scaleform::GFx::TextField::GetTextHeight((Scaleform::GFx::TextField *)v7->pProto.pObject);
      goto LABEL_40;
    case 0x2Bu:
      v17 = Scaleform::GFx::TextField::GetTextColor32((Scaleform::GFx::TextField *)v7->pProto.pObject);
      Scaleform::GFx::AS2::Value::SetInt(v4, v17);
      return 1;
    case 0x2Cu:
      v19 = Scaleform::Render::Text::StyledText::GetLength(*(Scaleform::Render::Text::StyledText **)&v10[2].vfptr->gap8[8]);
      goto LABEL_84;
    case 0x2Du:
      LODWORD(v10) = HIDWORD(v10[2].ResolveHandler.Function) >> 1;
      goto LABEL_3;
    case 0x2Eu:
      v13 = Scaleform::GFx::TextField::GetText((Scaleform::GFx::TextField *)v7->pProto.pObject, &result, 1);
      Scaleform::GFx::AS2::Value::SetString(v4, v13);
      v14 = result.pNode;
      goto LABEL_8;
    case 0x30u:
      if ( BYTE4(v10[2].ResolveHandler.Function) & 1 )
      {
        v21 = (Scaleform::Render::Text::DocView *)v10[2].vfptr;
        if ( v21->AlignProps & 3 )
        {
          if ( (v21->AlignProps & 3) == 1 )
          {
            v23 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v78, "right");
            Scaleform::GFx::AS2::Value::SetString(v4, v23);
            v14 = v78.pNode;
          }
          else
          {
            if ( (v21->AlignProps & 3) != 2 )
              goto $LN104_5;
            v22 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v68, "center");
            Scaleform::GFx::AS2::Value::SetString(v4, v22);
            v14 = v68.pNode;
          }
        }
        else
        {
          v24 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v70, "left");
          Scaleform::GFx::AS2::Value::SetString(v4, v24);
          v14 = v70.pNode;
        }
      }
      else
      {
        v20 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v82, "none");
        Scaleform::GFx::AS2::Value::SetString(v4, v20);
        v14 = v82.pNode;
      }
LABEL_8:
      v15 = v14->RefCount-- == 1;
      if ( !v15 )
        return 1;
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      return 1;
    case 0x31u:
      LOBYTE(v10) = v10[2].vfptr[2].gap8[0] >> 3;
      goto LABEL_3;
    case 0x32u:
      LOBYTE(v10) = v10[2].vfptr[2].gap8[0] >> 2;
      goto LABEL_3;
    case 0x33u:
      v25 = (unsigned int)v10[2].vfptr[1].Unwatch;
      goto LABEL_26;
    case 0x34u:
      v26 = v4;
      if ( !LODWORD(v7->vfptr->ToAvmTextFieldBase) )
        goto LABEL_60;
      Scaleform::GFx::AS2::Value::SetString(v4, (Scaleform::GFx::ASString *)&v7->vfptr);
      return 1;
    case 0x35u:
      v11 = Scaleform::GFx::TextField::IsSelectable((Scaleform::GFx::TextField *)v7->pProto.pObject);
      goto LABEL_4;
    case 0x36u:
      LOBYTE(v10) = ~(v10[2].vfptr[2].gap8[0] >> 5);
      goto LABEL_3;
    case 0x37u:
      if ( v10[2].vfptr[2].gap8[0] & 0x40 )
      {
        v36 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v84, "advanced");
        v37 = 4;
      }
      else
      {
        v36 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v74, "normal");
        v37 = 8;
      }
      LODWORD(v68.pNode) = v37;
      Scaleform::GFx::AS2::Value::SetString(v4, v36);
      if ( v37 & 8 )
      {
        v37 &= 0xFFFFFFF7;
        LODWORD(v68.pNode) = v37;
        v38 = v74.pNode;
        v15 = v74.pNode->RefCount == 1;
        --v38->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v38);
      }
      if ( v37 & 4 )
      {
        LODWORD(v68.pNode) = v37 & 0xFFFFFFFB;
        v39 = v84.pNode;
        v15 = v84.pNode->RefCount == 1;
        --v39->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v39);
      }
      return 1;
    case 0x38u:
      v29 = Scaleform::GFx::TextField::GetHScrollOffset((Scaleform::GFx::TextField *)v7->pProto.pObject);
      goto LABEL_38;
    case 0x39u:
      v31 = Scaleform::Render::Text::DocView::GetVScrollOffset((Scaleform::Render::Text::DocView *)v10[2].vfptr);
      goto LABEL_42;
    case 0x3Au:
      v31 = Scaleform::Render::Text::DocView::GetMaxVScroll((Scaleform::Render::Text::DocView *)v10[2].vfptr);
LABEL_42:
      Scaleform::GFx::AS2::Value::SetNumber(v4, (double)(signed int)(v31 + 1));
      return 1;
    case 0x3Bu:
      v29 = (double)(signed int)Scaleform::Render::Text::DocView::GetMaxHScroll((Scaleform::Render::Text::DocView *)v10[2].vfptr)
          * 0.05;
LABEL_38:
      v30 = (signed int)v29;
      goto LABEL_39;
    case 0x3Cu:
      v25 = HIDWORD(v10[2].vfptr[1].Unwatch);
LABEL_26:
      LODWORD(v88.pNode) = v25;
      Scaleform::GFx::AS2::Value::DropRefs(v4);
      v4->V.BooleanValue = BYTE3(v88.pNode) != 0;
      goto LABEL_5;
    case 0x3Du:
      v18 = (double)(HIDWORD(v10[2].vfptr[1].Unwatch) & 0xFFFFFF);
      goto LABEL_40;
    case 0x3Eu:
      v18 = (double)((_QWORD)v10[2].vfptr[1].Unwatch & 0xFFFFFF);
      goto LABEL_40;
    case 0x3Fu:
      v18 = (double)(signed int)(Scaleform::Render::Text::DocView::GetBottomVScroll((Scaleform::Render::Text::DocView *)v10[2].vfptr)
                               + 1);
      goto LABEL_40;
    case 0x40u:
      if ( Scaleform::GFx::TextField::IsReadOnly((Scaleform::GFx::TextField *)v7->pProto.pObject) )
      {
        v32 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v80, "dynamic");
        v33 = 1;
      }
      else
      {
        v32 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v72, "input");
        v33 = 2;
      }
      LODWORD(v68.pNode) = v33;
      Scaleform::GFx::AS2::Value::SetString(v4, v32);
      if ( v33 & 2 )
      {
        v33 &= 0xFFFFFFFD;
        LODWORD(v68.pNode) = v33;
        v34 = v72.pNode;
        v15 = v72.pNode->RefCount == 1;
        --v34->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v34);
      }
      if ( v33 & 1 )
      {
        LODWORD(v68.pNode) = v33 & 0xFFFFFFFE;
        v35 = v80.pNode;
        v15 = v80.pNode->RefCount == 1;
        --v35->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v35);
      }
      return 1;
    case 0x41u:
      v30 = (signed int)v10[2].vfptr[1].GetMember;
      if ( v30 )
      {
LABEL_39:
        v18 = (double)v30;
LABEL_40:
        Scaleform::GFx::AS2::Value::SetNumber(v4, v18);
      }
      else
      {
        v26 = v4;
LABEL_60:
        Scaleform::GFx::AS2::Value::DropRefs(v26);
        v4->T.Type = 1;
      }
      return 1;
    case 0x42u:
      LODWORD(v10) = HIDWORD(v10[2].ResolveHandler.Function) >> 4;
      goto LABEL_3;
    case 0x43u:
      LODWORD(v10) = HIDWORD(v10[2].ResolveHandler.Function) >> 7;
      goto LABEL_3;
    case 0x44u:
      LODWORD(v10) = HIDWORD(v10[2].ResolveHandler.Function) >> 2;
      goto LABEL_3;
    case 0x45u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v27 = Scaleform::GFx::TextField::GetShadowStyle((Scaleform::GFx::TextField *)v7->pProto.pObject, &v86);
      Scaleform::GFx::AS2::Value::SetString(v4, v27);
      v28 = v86.pNode;
      v15 = v86.pNode->RefCount == 1;
      --v28->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      return 1;
    case 0x46u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      Scaleform::GFx::AS2::Value::SetInt(v4, HIDWORD(v10[2].vfptr[1].Get__constructor__) & 0xFFFFFF);
      return 1;
    case 0x47u:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))v7[-1].ASTextFieldObj.pObject[2].pPrev)(&v7[-1].ASTextFieldObj)
                                + 232)
                    + 104i64) != 1 )
        goto $LN7_74;
      LODWORD(v10) = *(_DWORD *)&v10[1].ArePropertiesSet >> 11;
      goto LABEL_3;
    case 0x48u:
      if ( *(_BYTE *)(*(_QWORD *)(((__int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *))v7[-1].ASTextFieldObj.pObject[2].pPrev)(&v7[-1].ASTextFieldObj)
                                + 232)
                    + 104i64) != 1 )
        goto $LN7_74;
      LODWORD(v10) = HIDWORD(v10[2].ResolveHandler.Function) >> 3;
      goto LABEL_3;
    case 0x49u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = (double)(signed int)Scaleform::GFx::TextField::GetCursorPos((Scaleform::GFx::TextField *)v7->pProto.pObject);
      goto LABEL_40;
    case 0x4Au:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = (double)(signed int)Scaleform::Render::Text::DocView::GetLinesCount((Scaleform::Render::Text::DocView *)v10[2].vfptr);
      goto LABEL_40;
    case 0x4Bu:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v40 = (Scaleform::Render::Text::DocView *)v10[2].vfptr;
      if ( v40->Flags & 2 )
      {
        if ( ((unsigned int)(unsigned __int8)v40->AlignProps >> 2) & 3 )
        {
          switch ( ((unsigned int)(unsigned __int8)v40->AlignProps >> 2) & 3 )
          {
            case 1u:
              v45 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v69, "top");
              Scaleform::GFx::AS2::Value::SetString(v4, v45);
              v42 = v69.pNode;
              break;
            case 2u:
              v44 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v67, "bottom");
              Scaleform::GFx::AS2::Value::SetString(v4, v44);
              v42 = v67.pNode;
              break;
            case 3u:
              v43 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v70, "center");
              Scaleform::GFx::AS2::Value::SetString(v4, v43);
              v42 = v70.pNode;
              break;
            default:
              goto $LN104_5;
          }
        }
        else
        {
          v46 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v71, "none");
          Scaleform::GFx::AS2::Value::SetString(v4, v46);
          v42 = v71.pNode;
        }
      }
      else
      {
        v41 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v69, "none");
        Scaleform::GFx::AS2::Value::SetString(v4, v41);
        v42 = v69.pNode;
      }
      v15 = v42->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v42);
      return 1;
    case 0x4Cu:
      if ( v6->StringContext.pContext->GFxExtensions.Value == 1 )
        Scaleform::GFx::AS2::Value::SetNumber(v4, (float)((float)WORD1(v10[2].vfptr[2].__vecDelDtor) * 0.050000001));
      goto $LN7_74;
    case 0x4Du:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v47 = ((unsigned int)(unsigned __int8)v10[2].vfptr[2].gap8[1] >> 2) & 3;
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
              Scaleform::GFx::AS2::Value::DropRefs(v4);
              v4->T.Type = 0;
              return 1;
            }
            v50 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v73, "center");
            Scaleform::GFx::AS2::Value::SetString(v4, v50);
            v51 = v73.pNode;
          }
          else
          {
            v52 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v75, "bottom");
            Scaleform::GFx::AS2::Value::SetString(v4, v52);
            v51 = v75.pNode;
          }
        }
        else
        {
          v53 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v77, "top");
          Scaleform::GFx::AS2::Value::SetString(v4, v53);
          v51 = v77.pNode;
        }
      }
      else
      {
        v54 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v79, "none");
        Scaleform::GFx::AS2::Value::SetString(v4, v54);
        v51 = v79.pNode;
      }
      v15 = v51->RefCount-- == 1;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v51);
      return 1;
    case 0x4Eu:
      if ( v6->StringContext.pContext->GFxExtensions.Value == 1 )
      {
        if ( (((unsigned int)(unsigned __int8)v10[2].vfptr[2].gap8[1] >> 4) & 3) == 1 )
        {
          v58 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v85, "shrink");
          Scaleform::GFx::AS2::Value::SetString(v4, v58);
          v56 = v85.pNode;
        }
        else if ( (((unsigned int)(unsigned __int8)v10[2].vfptr[2].gap8[1] >> 4) & 3) == 2 )
        {
          v57 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v83, "fit");
          Scaleform::GFx::AS2::Value::SetString(v4, v57);
          v56 = v83.pNode;
        }
        else
        {
          v55 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &v81, "none");
          Scaleform::GFx::AS2::Value::SetString(v4, v55);
          v56 = v81.pNode;
        }
        v15 = v56->RefCount-- == 1;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v56);
      }
      goto $LN7_74;
    case 0x4Fu:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v59 = HIDWORD(v10[2].ResolveHandler.Function) >> 8;
      goto LABEL_159;
    case 0x50u:
      if ( v6->StringContext.pContext->GFxExtensions.Value == 1 )
      {
        v59 = HIDWORD(v10[2].ResolveHandler.Function) >> 9;
LABEL_159:
        Scaleform::GFx::AS2::Value::DropRefs(v4);
        v4->T.Type = 2;
        v4->V.BooleanValue = v59 & 1;
      }
      goto $LN7_74;
    case 0x51u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      if ( !Scaleform::GFx::TextField::IsSelectable((Scaleform::GFx::TextField *)v7->pProto.pObject)
        || !v10[2].vfptr[1].DeleteMember )
      {
        goto LABEL_86;
      }
      v19 = Scaleform::GFx::TextField::GetBeginIndex((Scaleform::GFx::TextField *)v10);
      goto LABEL_84;
    case 0x52u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      if ( Scaleform::GFx::TextField::IsSelectable((Scaleform::GFx::TextField *)v7->pProto.pObject)
        && v10[2].vfptr[1].DeleteMember )
      {
        v19 = Scaleform::GFx::TextField::GetEndIndex((Scaleform::GFx::TextField *)v10);
LABEL_84:
        v18 = (double)(signed int)v19;
        if ( v19 < 0 )
          v18 = v18 + 1.844674407370955e19;
      }
      else
      {
LABEL_86:
        v18 = DOUBLE_N1_0;
      }
      goto LABEL_40;
    case 0x53u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v61 = (Scaleform::Render::Text::EditorKitBase *)v10[2].vfptr[1].DeleteMember;
      if ( !v61 )
        goto $LN7_74;
      v18 = (double)SLODWORD(v61[9].vfptr);
      goto LABEL_40;
    case 0x54u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v60 = (Scaleform::Render::Text::EditorKitBase *)v10[2].vfptr[1].DeleteMember;
      if ( !v60 )
        goto $LN7_74;
      v18 = (double)SHIDWORD(v60[9].vfptr);
      goto LABEL_40;
    case 0x55u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v63 = (Scaleform::Render::Text::EditorKitBase *)v10[2].vfptr[1].DeleteMember;
      if ( !v63 )
        goto $LN7_74;
      v18 = (double)(signed int)v63[9].RefCount;
      goto LABEL_40;
    case 0x56u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v62 = (Scaleform::Render::Text::EditorKitBase *)v10[2].vfptr[1].DeleteMember;
      if ( !v62 )
        goto $LN7_74;
      v18 = (double)*((signed int *)&v62[9].RefCount + 1);
      goto LABEL_40;
    case 0x57u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LODWORD(v10) = HIDWORD(v10[2].ResolveHandler.Function) >> 10;
      goto LABEL_3;
    case 0x58u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LODWORD(v10) = HIDWORD(v10[2].ResolveHandler.Function) >> 11;
      goto LABEL_3;
    case 0x5Du:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v11 = v10[2].vfptr[2].gap8[0] >> 7;
      goto LABEL_4;
    case 0x5Eu:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = *(float *)&v10[2].vfptr[1].HasMember * 0.05;
      goto LABEL_40;
    case 0x5Fu:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = *((float *)&v10[2].vfptr[1].HasMember + 1) * 0.05;
      goto LABEL_40;
    case 0x60u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = *(float *)&v10[2].vfptr[1].SetMemberRaw;
      goto LABEL_40;
    case 0x61u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = *((float *)&v10[2].vfptr[2].__vecDelDtor + 1);
      goto LABEL_40;
    case 0x62u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LOBYTE(v10) = v10[2].vfptr[2].gap8[2];
      goto LABEL_3;
    case 0x63u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LOBYTE(v10) = v10[2].vfptr[2].gap8[2] >> 1;
      goto LABEL_3;
    case 0x65u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = (float)((float)BYTE4(v10[2].vfptr[1].InstanceOf) * 0.0039215689);
      goto LABEL_40;
    case 0x66u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = (float)(*((float *)&v10[2].vfptr[1].AddInterface + 1) * 57.295784);
      goto LABEL_40;
    case 0x67u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = *(float *)&v10[2].vfptr[1].ToFunction * 0.05;
      goto LABEL_40;
    case 0x68u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = *((float *)&v10[2].vfptr[1].ToFunction + 1) * 0.05;
      goto LABEL_40;
    case 0x69u:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = *(float *)&v10[2].vfptr[1].InstanceOf * 0.05;
      goto LABEL_40;
    case 0x6Au:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LODWORD(v10) = LODWORD(v10[2].vfptr[1].AddInterface) >> 6;
      goto LABEL_3;
    case 0x6Bu:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LODWORD(v10) = LODWORD(v10[2].vfptr[1].AddInterface) >> 5;
LABEL_3:
      v11 = (unsigned __int8)v10 & 1;
LABEL_4:
      Scaleform::GFx::AS2::Value::DropRefs(v4);
      v4->V.BooleanValue = v11;
LABEL_5:
      v4->T.Type = 2;
      return 1;
    case 0x6Cu:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      LOBYTE(v8) = SLOBYTE(v10[2].vfptr[1].AddInterface) < 0;
      v18 = (double)((signed int)v8 + 1);
      goto LABEL_40;
    case 0x6Du:
      if ( v6->StringContext.pContext->GFxExtensions.Value != 1 )
        goto $LN7_74;
      v18 = *(float *)&v10[2].vfptr[1].Get__constructor__;
      goto LABEL_40;
    case 0x6Eu:
      goto $LN7_74;
    default:
      if ( ((unsigned __int64 (__fastcall *)(Scaleform::Ptr<Scaleform::GFx::AS2::TextFieldObject> *, _QWORD, Scaleform::GFx::AS2::Value *, _QWORD))v7[-1].ASTextFieldObj.pObject[2].ResolveHandler.Function)(
             &v7[-1].ASTextFieldObj,
             v9,
             v4,
             0i64) )
      {
        return 1;
      }
$LN7_74:
      v64 = *((_QWORD *)&v7->VariableVal.NV + 3);
      if ( v64 )
        return (*(__int64 (__fastcall **)(__int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)(v64 + 32) + 32i64))(
                 v64 + 32,
                 v6,
                 v5,
                 v4);
      if ( v6
        && v5->pNode == (Scaleform::GFx::ASStringNode *)v6->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl )
      {
        Scaleform::GFx::AS2::Value::SetAsObject(v4, (Scaleform::GFx::AS2::Object *)v7->vfptr);
        return 1;
      }
      v65 = v7->vfptr;
      if ( v65
        && (*((unsigned __int8 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v65->GetMember
            + 4))(
             (signed __int64)&v65->GetMember,
             v6,
             v5,
             v4) )
      {
        return 1;
      }
      do
      {
        v66 = v5->pNode->pData[v8++];
        if ( v66 != aGlobal_0[v8 - 1] )
          return 0;
      }
      while ( v8 != 8 );
      if ( v6 )
      {
        Scaleform::GFx::AS2::Value::SetAsObject(v4, v6->StringContext.pContext->pGlobal.pObject);
        return 1;
      }
      return 0;
  }
}

// File Line: 1603
// RVA: 0x700E00
bool __fastcall Scaleform::GFx::AS2::AvmTextField::IsTabable(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::AvmTextField *v1; // rbx
  Scaleform::GFx::AS2::Object *v2; // rdi
  Scaleform::GFx::AS2::Environment *v3; // rax
  Scaleform::GFx::AS2::Environment *v4; // rsi
  Scaleform::GFx::ASString *v5; // rax
  char v6; // di
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  bool v9; // bl
  Scaleform::GFx::AS2::Value v11; // [rsp+28h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+60h] [rbp+8h]

  v1 = this;
  v2 = this->pProto.pObject;
  if ( !v2 )
    return Scaleform::GFx::TextField::IsReadOnly((Scaleform::GFx::TextField *)v1->pDispObj) == 0;
  v11.T.Type = 0;
  v3 = (Scaleform::GFx::AS2::Environment *)((__int64 (__cdecl *)(Scaleform::GFx::AS2::AvmTextField *))this->vfptr[2].ToAvmDispContainerBase)(this);
  v4 = v3;
  v5 = Scaleform::GFx::AS2::Environment::CreateConstString(v3, &result, "tabEnabled");
  v6 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v2->vfptr->GetMemberRaw)(
         &v2->vfptr,
         &v4->StringContext,
         v5,
         &v11,
         -2i64);
  v7 = result.pNode;
  v8 = result.pNode->RefCount == 1;
  --v7->RefCount;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  if ( !v6 || !v11.T.Type || v11.T.Type == 10 )
  {
    if ( v11.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v11);
    return Scaleform::GFx::TextField::IsReadOnly((Scaleform::GFx::TextField *)v1->pDispObj) == 0;
  }
  v9 = Scaleform::GFx::AS2::Value::ToBool(&v11, v4);
  if ( v11.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v11);
  return v9;
}

// File Line: 1620
// RVA: 0x7231D0
void __fastcall Scaleform::GFx::AS2::AvmTextField::UpdateVariable(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::AvmTextField *v1; // rbx
  Scaleform::GFx::AS2::Environment *v2; // rsi
  Scaleform::GFx::ASString *v3; // r14
  Scaleform::GFx::ASStringNode *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]

  v1 = this;
  if ( LODWORD(this->vfptr->GetMember) )
  {
    v2 = (Scaleform::GFx::AS2::Environment *)(*(__int64 (**)(void))(*(_QWORD *)&this[-1].VariableVal.T.Type + 240i64))();
    if ( v2 )
    {
      v3 = Scaleform::GFx::TextField::GetText(*((Scaleform::GFx::TextField **)&v1[-1].VariableVal.NV + 3), &result, 0);
      if ( LOBYTE(v1->pProto.pObject) >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&v1->pProto);
      LOBYTE(v1->pProto.pObject) = 5;
      v4 = v3->pNode;
      v1->pDispObj = (Scaleform::GFx::InteractiveObject *)v3->pNode;
      ++v4->RefCount;
      v5 = result.pNode;
      v6 = result.pNode->RefCount == 1;
      --v5->RefCount;
      if ( v6 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v5);
      Scaleform::GFx::AS2::Environment::SetVariable(
        v2,
        (Scaleform::GFx::ASString *)&v1->vfptr,
        (Scaleform::GFx::AS2::Value *)&v1->pProto,
        0i64,
        1);
    }
  }
}

// File Line: 1635
// RVA: 0x703340
void __fastcall Scaleform::GFx::AS2::AvmTextField::NotifyChanged(Scaleform::GFx::AS2::AvmTextField *this)
{
  Scaleform::GFx::AS2::AvmTextField *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // r12
  __int64 v3; // rax
  Scaleform::GFx::AS2::Environment *v4; // r15
  __int64 v5; // rdi
  __int64 v6; // rcx
  int v7; // edi
  __int64 v8; // rax
  Scaleform::GFx::DisplayObject *v9; // rcx
  char v10; // bp
  Scaleform::GFx::AS2::ObjectInterface *v11; // r14
  Scaleform::GFx::ASStringNode *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASString *v14; // rax
  unsigned int v15; // er8
  Scaleform::GFx::ASStringNode *v16; // rcx
  bool v17; // zf
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::Value v; // [rsp+28h] [rbp-50h]
  Scaleform::GFx::ASString result; // [rsp+80h] [rbp+8h]
  __int64 v21; // [rsp+88h] [rbp+10h]

  v1 = this;
  v2 = &this[-1].VariableVal;
  v3 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::Value *))(*(_QWORD *)&this[-1].VariableVal.T.Type + 240i64))(&this[-1].VariableVal);
  v4 = (Scaleform::GFx::AS2::Environment *)v3;
  v5 = 1i64;
  if ( *(_BYTE *)(*(_QWORD *)(v3 + 232) + 104i64) == 1 )
  {
    v6 = *((_QWORD *)&v1[-1].VariableVal.NV + 3);
    if ( *(_DWORD *)(v6 + 280) != -1 )
    {
      v7 = *(_DWORD *)(v6 + 280);
      *(_QWORD *)(v3 + 8) += 32i64;
      if ( *(_QWORD *)(v3 + 8) >= *(_QWORD *)(v3 + 24) )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage((Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v3 + 8));
      v8 = (__int64)v4->Stack.pCurrent;
      result.pNode = (Scaleform::GFx::ASStringNode *)v8;
      v21 = v8;
      if ( v8 )
      {
        *(_BYTE *)v8 = 4;
        *(_DWORD *)(v8 + 8) = v7;
      }
      v5 = 2i64;
    }
  }
  v9 = (Scaleform::GFx::DisplayObject *)*((_QWORD *)&v1[-1].VariableVal.NV + 3);
  v10 = 7;
  v.T.Type = 7;
  v11 = 0i64;
  if ( v9 )
  {
    v12 = (Scaleform::GFx::ASStringNode *)v9->pNameHandle.pObject;
    if ( !v12 )
      v12 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle(v9);
    v.V.pStringNode = v12;
    if ( v12 )
      ++LODWORD(v12->pData);
  }
  else
  {
    v.V.pStringNode = 0i64;
  }
  ++v4->Stack.pCurrent;
  if ( v4->Stack.pCurrent >= v4->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v4->Stack);
  v13 = (Scaleform::GFx::ASStringNode *)v4->Stack.pCurrent;
  result.pNode = v13;
  v21 = (__int64)v13;
  if ( v13 )
  {
    Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v13, &v, v5);
    v10 = v.T.Type;
  }
  if ( (unsigned __int8)v10 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  if ( v2 )
    v11 = (Scaleform::GFx::AS2::ObjectInterface *)&v1[-1].VariableVal.NV.8;
  v14 = Scaleform::GFx::AS2::Environment::CreateConstString(v4, &result, "onChanged");
  v15 = ((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) + 32 * v4->Stack.Pages.Data.Size - 32;
  if ( v11 )
  {
    *(_QWORD *)&v.T.Type = `Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v.V.pStringNode = (Scaleform::GFx::ASStringNode *)__PAIR__(v15, (unsigned int)v5);
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
      v4,
      v11,
      v14,
      (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *)&v);
    *(_QWORD *)&v.T.Type = &Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  v16 = result.pNode;
  v17 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v17 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  for ( ; (_DWORD)v5; LODWORD(v5) = v5 - 1 )
  {
    v18 = v4->Stack.pCurrent;
    if ( v18->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v18);
    --v4->Stack.pCurrent;
    if ( v4->Stack.pCurrent < v4->Stack.pPageStart )
      Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
  }
}

// File Line: 1650
// RVA: 0x6DB6E0
void __fastcall Scaleform::GFx::AS2::AvmTextField::BroadcastMessage(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  unsigned int v2; // er9
  Scaleform::GFx::AS2::Environment *v3; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  Scaleform::GFx::AS2::Environment *v5; // r10
  int v6; // er8
  int v7; // eax
  Scaleform::GFx::AS2::ObjectInterface *v8; // rdx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-20h]
  int v12; // [rsp+30h] [rbp-18h]
  int v13; // [rsp+34h] [rbp-14h]
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]

  v1 = fn;
  v2 = fn->FirstArgBottomIndex;
  v3 = fn->Env;
  v4 = 0i64;
  if ( v2 <= 32 * ((unsigned int)v3->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v3->Stack.pCurrent - (char *)v3->Stack.pPageStart) >> 5) )
    v4 = &v3->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v4, &result, v3, -1);
  v5 = v1->Env;
  v6 = ((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) + 32 * v5->Stack.Pages.Data.Size - 33;
  v7 = v1->NArgs - 1;
  v8 = v1->ThisPtr;
  if ( v8 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v12 = v7;
    v13 = v6;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v5, v8, &result, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  v9 = result.pNode;
  v10 = result.pNode->RefCount == 1;
  --v9->RefCount;
  if ( v10 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v9);
}

// File Line: 1656
// RVA: 0x706F20
void __usercall Scaleform::GFx::AS2::AvmTextField::OnScroll(Scaleform::GFx::AS2::AvmTextField *this@<rcx>, __int64 a2@<r12>, __int64 a3@<r13>)
{
  Scaleform::GFx::AS2::AvmTextField *v3; // rsi
  Scaleform::GFx::InteractiveObject *v4; // rbx
  __int64 v5; // rdi
  Scaleform::GFx::InteractiveObject *v6; // r8
  __int64 *v7; // rdx
  int v8; // eax
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::ASStringNode *v12; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v13; // rax
  __int64 v14; // rdi
  Scaleform::RefCountNTSImpl *v15; // rcx
  Scaleform::RefCountNTSImpl *v16; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+20h] [rbp-99h]
  Scaleform::GFx::AS2::Value v; // [rsp+38h] [rbp-81h]
  Scaleform::GFx::AS2::MovieRoot::ActionEntry v19; // [rsp+60h] [rbp-59h]
  __int64 v20; // [rsp+E0h] [rbp+27h]
  Scaleform::GFx::ASString result; // [rsp+120h] [rbp+67h]
  Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *v22; // [rsp+128h] [rbp+6Fh]
  Scaleform::GFx::AS2::Value *v23; // [rsp+130h] [rbp+77h]

  v20 = -2i64;
  v3 = this;
  v4 = (Scaleform::GFx::InteractiveObject *)*((_QWORD *)&this[-1].VariableVal.NV + 3);
  v5 = (*(__int64 (**)(void))(*(_QWORD *)&this[-1].VariableVal.T.Type + 240i64))();
  v19.pCharacter.pObject = 0i64;
  *(_QWORD *)&v19.mEventId.Id = 0i64;
  v19.mEventId.KeyCode = 0;
  v19.mEventId.AsciiCode = 0;
  *(_DWORD *)&v19.mEventId.RollOverCnt = 65280;
  v19.Function.Flags = 0;
  v19.Function.Function = 0i64;
  v19.Function.pLocalFrame = 0i64;
  result.pNode = (Scaleform::GFx::ASStringNode *)&v19.FunctionParams;
  v22 = &v19.FunctionParams;
  v19.FunctionParams.Data.Data = 0i64;
  v19.FunctionParams.Data.Size = 0i64;
  v19.FunctionParams.Data.Policy.Capacity = 0i64;
  v19.pNextEntry = 0i64;
  v19.pActionBuffer.pObject = 0i64;
  v19.SessionId = 0;
  v19.Type = 4;
  if ( v4 )
    ++v4->RefCount;
  if ( v19.pCharacter.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v19.pCharacter.pObject->vfptr);
  v6 = v4;
  v19.pCharacter.pObject = v4;
  if ( v19.pActionBuffer.pObject )
  {
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v19.pActionBuffer.pObject->vfptr);
    v6 = v19.pCharacter.pObject;
  }
  v19.pActionBuffer.pObject = 0i64;
  v19.CFunction = Scaleform::GFx::AS2::AvmTextField::BroadcastMessage;
  v7 = *(__int64 **)(*(_QWORD *)(*((_QWORD *)&v3[-1].VariableVal.NV + 3) + 32i64) + 224i64);
  if ( v7 )
  {
    while ( 1 )
    {
      if ( *((_DWORD *)v7 + 2) == v19.Type
        && !v7[3]
        && (Scaleform::GFx::InteractiveObject *)v7[2] == v6
        && (void (__fastcall *)(Scaleform::GFx::AS2::FnCall *))v7[10] == Scaleform::GFx::AS2::AvmTextField::BroadcastMessage
        && (Scaleform::GFx::AS2::FunctionObject *)v7[7] == v19.Function.Function )
      {
        v8 = *((_DWORD *)v7 + 8);
        if ( v8 == v19.mEventId.Id && (!_bittest(&v8, 0x11u) || *((_DWORD *)v7 + 10) == v19.mEventId.KeyCode) )
          break;
      }
      v7 = (__int64 *)*v7;
      if ( !v7 )
        goto LABEL_17;
    }
  }
  else
  {
LABEL_17:
    result.pNode = (Scaleform::GFx::ASStringNode *)&pheapAddr;
    pheapAddr.Data = 0i64;
    *(_OWORD *)&pheapAddr.Size = 0ui64;
    v9 = Scaleform::GFx::AS2::Environment::CreateConstString(
           (Scaleform::GFx::AS2::Environment *)v5,
           &result,
           "onScroller");
    LOBYTE(v5) = 5;
    v.T.Type = 5;
    v.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v9->pNode;
    ++v.V.pStringNode->RefCount;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    v22 = (Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
    v23 = &pheapAddr.Data[pheapAddr.Size - 1];
    if ( v22 )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, v5);
      v5 = (unsigned __int8)v.T.Type;
    }
    if ( (unsigned __int8)v5 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v10 = result.pNode;
    v11 = result.pNode->RefCount == 1;
    --v10->RefCount;
    if ( v11 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
    LOBYTE(v5) = 7;
    v.T.Type = 7;
    if ( v4 )
    {
      v12 = (Scaleform::GFx::ASStringNode *)v4->pNameHandle.pObject;
      if ( !v12 )
        v12 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v4->vfptr);
      v.V.pStringNode = v12;
      if ( v12 )
        ++LODWORD(v12->pData);
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
    v22 = (Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *)&pheapAddr.Data[pheapAddr.Size - 1];
    if ( result.pNode )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, v5);
      LOBYTE(v5) = v.T.Type;
    }
    if ( (unsigned __int8)v5 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v13 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
            (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)(*(_QWORD *)(*((_QWORD *)&v3[-1].VariableVal.NV + 3)
                                                                          + 32i64)
                                                              + 128i64),
            AP_Frame);
    v14 = (__int64)v13;
    v13->Type = 4;
    if ( v4 )
      ++v4->RefCount;
    v15 = (Scaleform::RefCountNTSImpl *)&v13->pCharacter.pObject->vfptr;
    if ( v15 )
      Scaleform::RefCountNTSImpl::Release(v15);
    *(_QWORD *)(v14 + 16) = v4;
    v16 = *(Scaleform::RefCountNTSImpl **)(v14 + 24);
    if ( v16 )
      Scaleform::RefCountNTSImpl::Release(v16);
    *(_QWORD *)(v14 + 24) = 0i64;
    *(_QWORD *)(v14 + 80) = Scaleform::GFx::AS2::AvmTextField::BroadcastMessage;
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)(v14 + 88),
      (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr,
      v14,
      a2,
      a3,
      0i64,
      (__int64)Scaleform::GFx::AS2::AvmTextField::BroadcastMessage);
    result.pNode = (Scaleform::GFx::ASStringNode *)&pheapAddr;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
  }
  Scaleform::GFx::AS2::MovieRoot::ActionEntry::~ActionEntry(&v19);
}

// File Line: 1673
// RVA: 0x708C30
void __fastcall Scaleform::GFx::AS2::AvmTextField::ProceedImageSubstitution(Scaleform::GFx::AS2::AvmTextField *this, Scaleform::GFx::AS2::FnCall *fn, int idx, Scaleform::GFx::AS2::Value *pve)
{
  unsigned int v4; // er12
  Scaleform::GFx::AS2::FnCall *v5; // rsi
  Scaleform::GFx::AS2::AvmTextField *v6; // r13
  Scaleform::GFx::TextField *v7; // rdi
  Scaleform::GFx::AS2::Object *v8; // r14
  Scaleform::RefCountNTSImpl *v9; // r15
  Scaleform::GFx::AS2::ASStringContext *v10; // rbx
  signed __int64 v11; // r14
  Scaleform::GFx::ASString *v12; // rax
  __int64 v13; // rbx
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  unsigned __int64 v16; // rbx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASStringNode *v19; // rcx
  float v20; // xmm7_4
  float v21; // xmm9_4
  float v22; // xmm10_4
  float v23; // xmm12_4
  float v24; // xmm11_4
  Scaleform::GFx::ASStringNode *v25; // rbx
  Scaleform::GFx::AS2::ASStringContext *v26; // rdi
  Scaleform::GFx::ASString *v27; // rax
  __int64 v28; // rdi
  Scaleform::GFx::ASStringNode *v29; // rcx
  Scaleform::GFx::AS2::Object *v30; // rax
  Scaleform::GFx::AS2::Object *v31; // rdi
  Scaleform::GFx::Resource *v32; // rax
  __int64 v33; // rdi
  char v34; // al
  Scaleform::MemoryHeap *v35; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *v36; // rax
  Scaleform::GFx::ASString *v37; // rax
  Scaleform::GFx::ASStringNode *v38; // rcx
  Scaleform::GFx::AS2::ASStringContext *v39; // rdi
  Scaleform::GFx::ASString *v40; // rax
  char v41; // di
  Scaleform::GFx::ASStringNode *v42; // rcx
  Scaleform::GFx::AS2::ASStringContext *v43; // rdi
  Scaleform::GFx::ASString *v44; // rax
  char v45; // di
  Scaleform::GFx::ASStringNode *v46; // rcx
  Scaleform::GFx::AS2::ASStringContext *v47; // rdi
  Scaleform::GFx::ASString *v48; // rax
  char v49; // di
  Scaleform::GFx::ASStringNode *v50; // rcx
  Scaleform::GFx::AS2::ASStringContext *v51; // rdi
  Scaleform::GFx::ASString *v52; // rax
  char v53; // di
  Scaleform::GFx::ASStringNode *v54; // rcx
  float v55; // xmm6_4
  Scaleform::GFx::AS2::ASStringContext *v56; // rdi
  Scaleform::GFx::ASString *v57; // rax
  char v58; // di
  Scaleform::GFx::ASStringNode *v59; // rcx
  const char *v60; // rdi
  Scaleform::Render::Text::ImageDesc *v61; // rax
  Scaleform::RefCountNTSImpl *v62; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v63; // rcx
  Scaleform::GFx::TextField *v64; // rsi
  Scaleform::RefCountNTSImpl *v65; // rax
  int v66; // xmm2_4
  float *v67; // rax
  float v68; // xmm3_4
  float v69; // xmm2_4
  Scaleform::GFx::ASString *v70; // rax
  Scaleform::GFx::ASStringNode *v71; // rcx
  Scaleform::GFx::ASString *v72; // rax
  Scaleform::GFx::ASStringNode *v73; // rcx
  Scaleform::GFx::ASString v74; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::TextField *v75; // [rsp+28h] [rbp-D8h]
  Scaleform::GFx::AS2::Value v76; // [rsp+30h] [rbp-D0h]
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v77; // [rsp+50h] [rbp-B0h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v78; // [rsp+58h] [rbp-A8h]
  int v79; // [rsp+60h] [rbp-A0h]
  int v80; // [rsp+64h] [rbp-9Ch]
  Scaleform::Render::Text::ImageDesc *v81; // [rsp+68h] [rbp-98h]
  wchar_t pbuff; // [rsp+70h] [rbp-90h]
  Scaleform::RefCountNTSImpl *v83; // [rsp+98h] [rbp-68h]
  char v84; // [rsp+A0h] [rbp-60h]
  Scaleform::Render::Text::DocView::ImageSubstitutor *v85; // [rsp+A8h] [rbp-58h]
  __int64 v86; // [rsp+B0h] [rbp-50h]
  int v87; // [rsp+B8h] [rbp-48h]
  Scaleform::MemoryHeap *v88; // [rsp+C0h] [rbp-40h]
  int v89; // [rsp+C8h] [rbp-38h]
  int v90; // [rsp+CCh] [rbp-34h]
  __int64 v91; // [rsp+D0h] [rbp-30h]
  __int64 v92; // [rsp+D8h] [rbp-28h]
  __int64 v93; // [rsp+E0h] [rbp-20h]
  __int64 v94; // [rsp+E8h] [rbp-18h]
  __int64 v95; // [rsp+F0h] [rbp-10h]
  Scaleform::GFx::ASString result; // [rsp+1B8h] [rbp+B8h]

  if ( pve )
  {
    v95 = -2i64;
    v4 = idx;
    v5 = fn;
    v6 = this;
    if ( pve->T.Type == 6 )
    {
      v75 = (Scaleform::GFx::TextField *)this->pDispObj;
      v7 = v75;
      v8 = Scaleform::GFx::AS2::Value::ToObject(pve, fn->Env);
      v76.T.Type = 0;
      v85 = Scaleform::GFx::TextField::CreateImageSubstitutor(v75);
      if ( !v85 )
      {
LABEL_81:
        if ( v76.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v76);
        return;
      }
      v9 = 0i64;
      v83 = 0i64;
      v10 = &v5->Env->StringContext;
      v11 = (signed __int64)&v8->vfptr;
      v12 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v10, &result, "subString");
      v13 = (*(unsigned __int8 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v11 + 88i64))(
              v11,
              v10,
              v12,
              &v76);
      v14 = result.pNode;
      v15 = result.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( !(_BYTE)v13 )
      {
        v72 = Scaleform::GFx::AS3::AvmDisplayObj::GetName((Scaleform::GFx::AS2::AvmCharacter *)&v6->vfptr, &result);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v7->vfptr,
          "%s.setImageSubstitutions() failed for #%d element - subString should be specified",
          v72->pNode->pData,
          v4);
LABEL_77:
        v73 = result.pNode;
        v15 = result.pNode->RefCount == 1;
        --v73->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v73);
LABEL_79:
        if ( v83 )
          Scaleform::RefCountNTSImpl::Release(v83);
        goto LABEL_81;
      }
      Scaleform::GFx::AS2::Value::ToString(&v76, &result, v5->Env, -1);
      v16 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode);
      if ( v16 > 0xF )
      {
        v17 = Scaleform::GFx::AS3::AvmDisplayObj::GetName((Scaleform::GFx::AS2::AvmCharacter *)&v6->vfptr, &v74);
        Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
          (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v7->vfptr,
          "%s.setImageSubstitutions() failed for #%d element - length of subString should not exceed 15 characters",
          v17->pNode->pData,
          v4);
        v18 = v74.pNode;
        v15 = v74.pNode->RefCount == 1;
        --v18->RefCount;
        if ( v15 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v18);
        goto LABEL_77;
      }
      Scaleform::UTF8Util::DecodeStringSafe(&pbuff, 0x14ui64, result.pNode->pData, result.pNode->Size + 1);
      v84 = v16;
      v19 = result.pNode;
      v15 = result.pNode->RefCount == 1;
      --v19->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v19);
      v20 = 0.0;
      v21 = 0.0;
      v22 = 0.0;
      v23 = 0.0;
      v24 = 0.0;
      v81 = 0i64;
      v25 = 0i64;
      v74.pNode = 0i64;
      v26 = &v5->Env->StringContext;
      v27 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v26, &result, "image");
      v28 = (*(unsigned __int8 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, _QWORD))(*(_QWORD *)v11 + 88i64))(
              v11,
              v26,
              v27,
              &v76,
              0i64);
      v29 = result.pNode;
      v15 = result.pNode->RefCount == 1;
      --v29->RefCount;
      if ( v15 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v29);
      if ( !(_BYTE)v28 )
        goto LABEL_72;
      v30 = Scaleform::GFx::AS2::Value::ToObject(&v76, v5->Env);
      v31 = v30;
      if ( !v30 || (*(unsigned int (**)(void))&v30->vfptr->gap8[8])() != 26 )
        goto LABEL_72;
      v77 = v31[1].vfptr;
      v32 = (Scaleform::GFx::Resource *)((__int64 (*)(void))v6->pDispObj->vfptr[66].__vecDelDtor)();
      v33 = (__int64)v32;
      if ( v32 )
        Scaleform::Render::RenderBuffer::AddRef(v32);
      v86 = v33;
      if ( (*(unsigned int (**)(void))(*(_QWORD *)v77[1].ExecuteForEachChild_GC + 24i64))() )
      {
        v25 = (Scaleform::GFx::ASStringNode *)v77[1].ExecuteForEachChild_GC;
        if ( v25 )
          (*((void (__fastcall **)(void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)))v25->pData
           + 1))(v77[1].ExecuteForEachChild_GC);
        v74.pNode = v25;
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
          if ( v25 )
          {
            v39 = &v5->Env->StringContext;
            v40 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v39, &result, "width");
            v41 = (*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v11 + 88i64))(
                    v11,
                    v39,
                    v40,
                    &v76);
            v42 = result.pNode;
            v15 = result.pNode->RefCount == 1;
            --v42->RefCount;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v42);
            if ( v41 )
              v21 = Scaleform::GFx::AS2::Value::ToNumber(&v76, v5->Env) * 20.0;
            v43 = &v5->Env->StringContext;
            v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v43, &result, "height");
            v45 = (*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v11 + 88i64))(
                    v11,
                    v43,
                    v44,
                    &v76);
            v46 = result.pNode;
            v15 = result.pNode->RefCount == 1;
            --v46->RefCount;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v46);
            if ( v45 )
              v22 = Scaleform::GFx::AS2::Value::ToNumber(&v76, v5->Env) * 20.0;
            v47 = &v5->Env->StringContext;
            v48 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v47, &result, "baseLineX");
            v49 = (*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v11 + 88i64))(
                    v11,
                    v47,
                    v48,
                    &v76);
            v50 = result.pNode;
            v15 = result.pNode->RefCount == 1;
            --v50->RefCount;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v50);
            if ( v49 )
              v20 = Scaleform::GFx::AS2::Value::ToNumber(&v76, v5->Env) * 20.0;
            v51 = &v5->Env->StringContext;
            v52 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v51, &result, "baseLineY");
            v53 = (*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v11 + 88i64))(
                    v11,
                    v51,
                    v52,
                    &v76);
            v54 = result.pNode;
            v15 = result.pNode->RefCount == 1;
            --v54->RefCount;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v54);
            if ( v53 )
              v55 = Scaleform::GFx::AS2::Value::ToNumber(&v76, v5->Env) * 20.0;
            else
              v55 = v24 - 20.0;
            v56 = &v5->Env->StringContext;
            v57 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v56, &result, "id");
            v58 = (*(__int64 (__fastcall **)(signed __int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v11 + 88i64))(
                    v11,
                    v56,
                    v57,
                    &v76);
            v59 = result.pNode;
            v15 = result.pNode->RefCount == 1;
            --v59->RefCount;
            if ( v15 )
              Scaleform::GFx::ASStringNode::ReleaseNode(v59);
            if ( v58 )
            {
              v60 = Scaleform::GFx::AS2::Value::ToString(&v76, &result, v5->Env, -1)->pNode->pData;
              v59 = result.pNode;
              v15 = result.pNode->RefCount == 1;
              --v59->RefCount;
              if ( v15 )
                Scaleform::GFx::ASStringNode::ReleaseNode(v59);
            }
            else
            {
              v60 = (const char *)v81;
            }
            v86 = (__int64)v5->Env->StringContext.pContext->pHeap;
            v61 = (Scaleform::Render::Text::ImageDesc *)(*(__int64 (__fastcall **)(Scaleform::GFx::ASStringNode *, signed __int64))(*(_QWORD *)v86 + 80i64))(
                                                          v59,
                                                          80i64);
            v81 = v61;
            if ( v61 )
            {
              Scaleform::Render::Text::ImageDesc::ImageDesc(v61);
              v9 = v62;
            }
            if ( v83 )
              Scaleform::RefCountNTSImpl::Release(v83);
            v83 = v9;
            (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))v25->pData + 1))(v25);
            v63 = v9[1].vfptr;
            if ( v63 )
              (*((void (**)(void))v63->__vecDelDtor + 2))();
            v9[1].vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)v25;
            *(float *)&v83[1].RefCount = v20 * 0.050000001;
            *((float *)&v83[1].RefCount + 1) = v55 * 0.050000001;
            *(float *)&v83[2].vfptr = v21;
            *((float *)&v83[2].vfptr + 1) = v22;
            v64 = v75;
            if ( v60 )
              Scaleform::GFx::TextField::AddIdImageDescAssoc(v75, v60, (Scaleform::Render::Text::ImageDesc *)v83);
            v65 = v83;
            v66 = *(&v83[1].RefCount + 1) ^ _xmm[0];
            *((float *)&v83[3].RefCount + 1) = COERCE_FLOAT(v83[1].RefCount ^ _xmm[0])
                                             + *((float *)&v83[3].RefCount + 1);
            *((float *)&v65[4].RefCount + 1) = *(float *)&v66 + *((float *)&v65[4].RefCount + 1);
            v67 = (float *)v83;
            v68 = *((float *)&v83[2].vfptr + 1) / v24;
            v69 = *(float *)&v83[2].vfptr / v23;
            *(float *)&v83[3].vfptr = v69 * *(float *)&v83[3].vfptr;
            v67[13] = v69 * v67[13];
            v67[14] = v69 * v67[14];
            v67[15] = v69 * v67[15];
            v67[16] = v68 * v67[16];
            v67[17] = v68 * v67[17];
            v67[18] = v68 * v67[18];
            v67[19] = v68 * v67[19];
            Scaleform::Render::Text::DocView::ImageSubstitutor::AddImageDesc(
              v85,
              (Scaleform::Render::Text::DocView::ImageSubstitutor::Element *)&pbuff);
            v64->pDocument.pObject->RTFlags |= 2u;
            Scaleform::GFx::TextField::SetDirtyFlag((Scaleform::GFx::TextField *)v6->pDispObj);
            (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))v25->pData + 2))(v25);
            goto LABEL_79;
          }
LABEL_72:
          v70 = Scaleform::GFx::AS3::AvmDisplayObj::GetName((Scaleform::GFx::AS2::AvmCharacter *)&v6->vfptr, &result);
          Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
            (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v75->vfptr,
            "%s.setImageSubstitutions() failed for #%d element - image is not specified or not a BitmapData",
            v70->pNode->pData,
            v4,
            v74.pNode);
          v71 = result.pNode;
          v15 = result.pNode->RefCount == 1;
          --v71->RefCount;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v71);
          goto LABEL_74;
        }
        v35 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v6);
        v87 = 3;
        v88 = v35;
        v89 = 1;
        v90 = 1;
        v91 = 0i64;
        v92 = 0i64;
        v93 = 0i64;
        v94 = 0i64;
        v36 = Scaleform::GFx::StateBag::GetImageCreator(
                (Scaleform::GFx::StateBag *)(v33 + 24),
                (Scaleform::Ptr<Scaleform::GFx::ImageCreator> *)&result);
        v25 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, _QWORD))v36->pObject->vfptr[4].__vecDelDtor)(
                                                v36->pObject,
                                                &v87,
                                                v77[1].ExecuteForEachChild_GC);
        v74.pNode = v25;
        if ( result.pNode )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pNode);
      }
      if ( v25 )
      {
        (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *, Scaleform::Ptr<Scaleform::GFx::ImageCreator> *))v25->pData
         + 6))(
          v25,
          &v78);
        v23 = (float)(v79 - LODWORD(v78.pObject));
        v24 = (float)(v80 - HIDWORD(v78.pObject));
        v21 = v23 * 20.0;
        v22 = v24 * 20.0;
        if ( v23 == 0.0 || v24 == 0.0 )
        {
          v37 = Scaleform::GFx::AS3::AvmDisplayObj::GetName((Scaleform::GFx::AS2::AvmCharacter *)&v6->vfptr, &result);
          Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
            (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v75->vfptr,
            "%s.setImageSubstitutions() failed for #%d element - image has one zero dimension",
            v37->pNode->pData,
            v4,
            v74.pNode);
          v38 = result.pNode;
          v15 = result.pNode->RefCount == 1;
          --v38->RefCount;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v38);
          if ( v33 )
            Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v33);
LABEL_74:
          if ( v25 )
            (*((void (__fastcall **)(Scaleform::GFx::ASStringNode *))v25->pData + 2))(v25);
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
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rbx
  int v5; // esi
  Scaleform::GFx::TextField *v6; // rbx
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // rbp
  Scaleform::GFx::AS2::Value *v9; // r8
  Scaleform::GFx::AS2::Value *v10; // rax
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // r14
  __int64 v13; // rbp
  __int64 v14; // r15
  Scaleform::GFx::AS2::Value *v15; // rax
  Scaleform::GFx::ASString *v16; // rax
  Scaleform::GFx::ASStringNode *v17; // rcx
  bool v18; // zf
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  v3 = v1->ThisPtr;
  if ( v3 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) == 4 )
  {
    v4 = v1->ThisPtr;
    v5 = 0;
    v6 = (Scaleform::GFx::TextField *)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v1->ThisPtr)
                                     - 2 > 3 ? 0i64 : v4[1].vfptr);
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      if ( v9->T.Type == 1 )
      {
        Scaleform::GFx::TextField::ClearIdImageDescAssoc(v6);
        Scaleform::GFx::TextField::ClearImageSubstitutor(v6);
        v6->pDocument.pObject->RTFlags |= 2u;
        Scaleform::GFx::TextField::SetDirtyFlag(v6);
      }
      else
      {
        v10 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        v11 = Scaleform::GFx::AS2::Value::ToObject(v10, v8);
        v12 = v11;
        if ( v11 )
        {
          if ( (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v11->vfptr->gap8[8])(&v11->vfptr) == 7 )
          {
            v13 = 0i64;
            v14 = (signed int)v12[1].RootIndex;
            if ( v14 > 0 )
            {
              do
                Scaleform::GFx::AS2::AvmTextField::ProceedImageSubstitution(
                  (Scaleform::GFx::AS2::AvmTextField *)((char *)v6 + 4 * (unsigned __int8)v6->AvmObjOffset),
                  v1,
                  v5++,
                  (Scaleform::GFx::AS2::Value *)(&v12[1].pRCC->vfptr)[v13++]);
              while ( v13 < v14 );
            }
          }
          else
          {
            v15 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
            Scaleform::GFx::AS2::AvmTextField::ProceedImageSubstitution(
              (Scaleform::GFx::AS2::AvmTextField *)((char *)v6 + 4 * (unsigned __int8)v6->AvmObjOffset),
              v1,
              0,
              v15);
          }
        }
        else
        {
          v16 = Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)&v6->vfptr, &result);
          Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
            (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v6->vfptr,
            "%s.setImageSubstitutions() failed: parameter should be either null, object or array",
            v16->pNode->pData);
          v17 = result.pNode;
          v18 = result.pNode->RefCount == 1;
          --v17->RefCount;
          if ( v18 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v17);
        }
      }
    }
  }
}

// File Line: 1851
// RVA: 0x6BB550
void __fastcall Scaleform::GFx::AS2::AvmTextField::UpdateImageSubstitution(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdi
  __int64 v5; // rbx
  Scaleform::GFx::TextField *v6; // r15
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::StringHashLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2,Scaleform::String::NoCaseHashFunctor,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v10; // r14
  unsigned __int64 v11; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v12; // r13
  unsigned __int64 v13; // r14
  signed __int64 v14; // r11
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::Ptr<Scaleform::Render::Text::ImageDesc>,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v15; // r10
  unsigned __int8 *v16; // rax
  int v17; // ecx
  int v18; // er8
  signed __int64 v19; // r11
  Scaleform::Render::Text::ImageDesc **v20; // r14
  Scaleform::Render::Text::ImageDesc *v21; // r14
  char v22; // cl
  Scaleform::GFx::AS2::Value *v23; // rax
  Scaleform::GFx::AS2::Object *v24; // rax
  Scaleform::GFx::AS2::Object *v25; // rdi
  Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *v26; // rsi
  Scaleform::GFx::Resource *v27; // rax
  __int64 v28; // rdi
  bool v29; // r12
  Scaleform::MemoryHeap *v30; // rax
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> *v31; // rax
  Scaleform::Render::Image *v32; // rcx
  Scaleform::Render::Text::DocView::ImageSubstitutor *v33; // rax
  Scaleform::GFx::ASStringNode *v34; // rcx
  bool v35; // zf
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v36; // [rsp+20h] [rbp-49h]
  Scaleform::Ptr<Scaleform::GFx::ImageCreator> v37; // [rsp+28h] [rbp-41h]
  __int64 v38; // [rsp+30h] [rbp-39h]
  __int64 v39; // [rsp+38h] [rbp-31h]
  int v40; // [rsp+40h] [rbp-29h]
  Scaleform::MemoryHeap *v41; // [rsp+48h] [rbp-21h]
  int v42; // [rsp+50h] [rbp-19h]
  int v43; // [rsp+54h] [rbp-15h]
  __int64 v44; // [rsp+58h] [rbp-11h]
  __int64 v45; // [rsp+60h] [rbp-9h]
  __int64 v46; // [rsp+68h] [rbp-1h]
  __int64 v47; // [rsp+70h] [rbp+7h]
  Scaleform::LogMessageId id; // [rsp+D0h] [rbp+67h]
  Scaleform::String v49; // [rsp+D8h] [rbp+6Fh]
  Scaleform::GFx::ASString result; // [rsp+E0h] [rbp+77h]
  __int64 v51; // [rsp+E8h] [rbp+7Fh]

  v38 = -2i64;
  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  v3 = v1->ThisPtr;
  if ( v3 && (*(unsigned int (**)(void))&v3->vfptr->gap8[8])() == 4 )
  {
    v4 = v1->ThisPtr;
    v5 = 0i64;
    v6 = (Scaleform::GFx::TextField *)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v4->vfptr->gap8[8])(v1->ThisPtr)
                                     - 2 > 3 ? 0i64 : v4[1].vfptr);
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v9, &result, v8, -1);
      v10 = v6->pImageDescAssoc;
      if ( v10 )
      {
        Scaleform::String::String(&v49, result.pNode->pData);
        if ( !v10->mHash.pTable )
          goto LABEL_22;
        v11 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v49.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v49.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64);
        v12 = v10->mHash.pTable;
        v13 = v11 & v10->mHash.pTable->SizeMask;
        v14 = v13;
        v15 = &v12[2 * v13 + 1];
        if ( v15->EntryCount == -2i64 || v15->SizeMask != v13 )
          goto LABEL_22;
        while ( 1 )
        {
          if ( v15->SizeMask == v13 )
          {
            v16 = (unsigned __int8 *)((v15[1].EntryCount & 0xFFFFFFFFFFFFFFFCui64) + 12);
            do
            {
              v17 = v16[(v49.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (v15[1].EntryCount & 0xFFFFFFFFFFFFFFFCui64)];
              v18 = *v16 - v17;
              if ( *v16 != v17 )
                break;
              ++v16;
            }
            while ( v17 );
            if ( !v18 )
              break;
          }
          v14 = v15->EntryCount;
          if ( v15->EntryCount == -1i64 )
            goto LABEL_22;
          v15 = &v12[2 * v14 + 1];
        }
        if ( v14 < 0
          || (v19 = 2 * (v14 + 1), v20 = (Scaleform::Render::Text::ImageDesc **)&v12[v19].SizeMask, !&v12[v19]) )
        {
LABEL_22:
          v20 = 0i64;
        }
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v49.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        if ( v20 )
        {
          v21 = *v20;
          if ( v1->NArgs >= 2 )
          {
            if ( Scaleform::GFx::AS2::FnCall::Arg(v1, 1)->T.Type != 1
              && (v22 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1)->T.Type) != 0
              && v22 != 10 )
            {
              v23 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
              v24 = Scaleform::GFx::AS2::Value::ToObject(v23, v1->Env);
              v25 = v24;
              if ( v24 && (*(unsigned int (**)(void))&v24->vfptr->gap8[8])() == 26 )
              {
                v26 = v25[1].vfptr;
                v27 = (Scaleform::GFx::Resource *)((__int64 (__fastcall *)(Scaleform::GFx::TextField *))v6->vfptr[66].__vecDelDtor)(v6);
                v28 = (__int64)v27;
                if ( v27 )
                  Scaleform::Render::RenderBuffer::AddRef(v27);
                v39 = v28;
                v51 = 0i64;
                if ( (*(unsigned int (**)(void))(*(_QWORD *)v26[1].ExecuteForEachChild_GC + 24i64))() )
                {
                  v5 = (__int64)v26[1].ExecuteForEachChild_GC;
                  if ( v5 )
                    (*(void (__fastcall **)(void (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::RefCountCollector<323> *, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC)))(*(_QWORD *)v5 + 8i64))(v26[1].ExecuteForEachChild_GC);
                  v51 = v5;
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
                    v31 = Scaleform::GFx::StateBag::GetImageCreator((Scaleform::GFx::StateBag *)(v28 + 24), &v37);
                    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::ImageCreator *, int *, _QWORD))v31->pObject->vfptr[4].__vecDelDtor)(
                           v31->pObject,
                           &v40,
                           v26[1].ExecuteForEachChild_GC);
                    v51 = v5;
                    if ( v37.pObject )
                      Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v37.pObject);
                  }
                }
                if ( v5 )
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 8i64))(v5);
                v32 = v21->pImage.pObject;
                if ( v32 )
                  ((void (*)(void))v32->vfptr[2].__vecDelDtor)();
                v21->pImage.pObject = (Scaleform::Render::Image *)v5;
                Scaleform::GFx::TextField::SetDirtyFlag(v6);
                if ( v5 )
                  (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 16i64))(v5);
                if ( v28 )
                  Scaleform::GFx::Resource::Release((Scaleform::GFx::Resource *)v28);
              }
            }
            else
            {
              v33 = Scaleform::GFx::TextField::CreateImageSubstitutor(v6);
              if ( v33 )
              {
                Scaleform::Render::Text::DocView::ImageSubstitutor::RemoveImageDesc(v33, v21);
                v6->pDocument.pObject->RTFlags |= 2u;
                Scaleform::GFx::TextField::RemoveIdImageDescAssoc(v6, result.pNode->pData);
                Scaleform::GFx::TextField::SetDirtyFlag(v6);
              }
            }
          }
        }
      }
      v34 = result.pNode;
      v35 = result.pNode->RefCount == 1;
      --v34->RefCount;
      if ( v35 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v34);
    }
  }
}

// File Line: 1916
// RVA: 0x6B84E0
void __fastcall Scaleform::GFx::AS2::AvmTextField::SetTextFormat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::TextField *v4; // rsi
  signed int v5; // eax
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

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (Scaleform::GFx::TextField *)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                                     - 2 > 3 ? 0i64 : v3[1].vfptr);
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) )
    {
      v5 = v1->NArgs;
      if ( v5 == 1 )
      {
        v6 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        v7 = Scaleform::GFx::AS2::Value::ToObject(v6, v1->Env);
        v8 = v7;
        if ( v7 )
        {
          if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v7->vfptr->gap8[8])(&v7->vfptr) == 30 )
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
      else if ( v5 == 2 )
      {
        v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
        v10 = Scaleform::GFx::AS2::Value::ToObject(v9, v1->Env);
        v11 = v10;
        if ( v10 )
        {
          if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v10->vfptr->gap8[8])(&v10->vfptr) == 30 )
          {
            v12 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
            v13 = Scaleform::GFx::AS2::Value::ToNumber(v12, v1->Env);
            if ( v13 >= 0.0 )
            {
              Scaleform::Render::Text::DocView::SetTextFormat(
                v4->pDocument.pObject,
                (Scaleform::Render::Text::TextFormat *)&v11[1],
                (unsigned int)(signed int)v13,
                (unsigned int)((signed int)v13 + 1));
              Scaleform::Render::Text::DocView::SetParagraphFormat(
                v4->pDocument.pObject,
                (Scaleform::Render::Text::ParagraphFormat *)&v11[1].pWatchpoints,
                (unsigned int)(signed int)v13,
                (unsigned int)((signed int)v13 + 1));
              Scaleform::GFx::TextField::SetDirtyFlag(v4);
            }
          }
        }
      }
      else if ( v5 >= 3 )
      {
        v14 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        v15 = Scaleform::GFx::AS2::Value::ToObject(v14, v1->Env);
        v16 = v15;
        if ( v15 )
        {
          if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v15->vfptr->gap8[8])(&v15->vfptr) == 30 )
          {
            v17 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
            v18 = 0.0;
            v19 = Scaleform::GFx::AS2::Value::ToNumber(v17, v1->Env);
            if ( v19 < 0.0 )
              v19 = 0.0;
            v20 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
            v21 = Scaleform::GFx::AS2::Value::ToNumber(v20, v1->Env);
            if ( v21 >= 0.0 )
              v18 = v21;
            if ( v19 <= v18 )
            {
              Scaleform::Render::Text::DocView::SetTextFormat(
                v4->pDocument.pObject,
                (Scaleform::Render::Text::TextFormat *)&v16[1],
                (unsigned int)(signed int)v19,
                (unsigned int)(signed int)v18);
              Scaleform::Render::Text::DocView::SetParagraphFormat(
                v4->pDocument.pObject,
                (Scaleform::Render::Text::ParagraphFormat *)&v16[1].pWatchpoints,
                (unsigned int)(signed int)v19,
                (unsigned int)(signed int)v18);
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
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::TextFormatObject *v4; // rdi
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *v5; // r14
  unsigned __int64 v6; // rbp
  unsigned __int64 endPos; // rsi
  unsigned int v8; // er10
  Scaleform::GFx::AS2::Environment *v9; // rdx
  Scaleform::GFx::AS2::Value *v10; // r9
  double v11; // xmm0_8
  signed int v12; // eax
  unsigned int v13; // er9
  Scaleform::GFx::AS2::Environment *v14; // rdx
  Scaleform::GFx::AS2::Value *v15; // r10
  double v16; // xmm0_8
  Scaleform::GFx::AS2::Value *v17; // rax
  Scaleform::MemoryHeap *v18; // rcx
  Scaleform::GFx::AS2::TextFormatObject *v19; // rax
  Scaleform::GFx::AS2::TextFormatObject *v20; // rax
  unsigned int v21; // eax
  Scaleform::GFx::AS2::Value *v22; // rbx
  Scaleform::GFx::AS2::Value *v23; // rbx
  Scaleform::Render::Text::ParagraphFormat pdestParaFmt; // [rsp+30h] [rbp-A8h]
  __int64 v25; // [rsp+58h] [rbp-80h]
  Scaleform::Render::Text::TextFormat pdestTextFmt; // [rsp+60h] [rbp-78h]

  v25 = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( !v2 || (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() != 4 )
  {
    v23 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v23);
    v23->T.Type = 0;
    return;
  }
  v3 = v1->ThisPtr;
  v4 = 0i64;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) - 2 > 3 )
    v5 = 0i64;
  else
    v5 = v3[1].vfptr;
  v6 = 0i64;
  endPos = -1i64;
  if ( v1->NArgs >= 1 )
  {
    v8 = v1->FirstArgBottomIndex;
    v9 = v1->Env;
    v10 = 0i64;
    if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
      v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v11 = Scaleform::GFx::AS2::Value::ToNumber(v10, v9);
    if ( v11 < 0.0 )
      v11 = 0.0;
    v6 = (unsigned int)(signed int)v11;
  }
  v12 = v1->NArgs;
  if ( v12 >= 2 )
  {
    v13 = v1->FirstArgBottomIndex - 1;
    v14 = v1->Env;
    v15 = 0i64;
    if ( v13 <= 32 * ((unsigned int)v14->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v14->Stack.pCurrent - (char *)v14->Stack.pPageStart) >> 5) )
      v15 = &v14->Stack.Pages.Data.Data[v13 >> 5]->Values[v13 & 0x1F];
    v16 = Scaleform::GFx::AS2::Value::ToNumber(v15, v14);
    goto LABEL_18;
  }
  if ( v12 >= 1 )
  {
    v17 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
    v16 = Scaleform::GFx::AS2::Value::ToNumber(v17, v1->Env) + 1.0;
LABEL_18:
    if ( v16 < 0.0 )
      v16 = 0.0;
    endPos = (unsigned int)(signed int)v16;
  }
  if ( v6 > endPos )
  {
    v22 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v22);
    v22->T.Type = 0;
  }
  else
  {
    Scaleform::Render::Text::TextFormat::TextFormat(&pdestTextFmt, v1->Env->StringContext.pContext->pHeap);
    pdestParaFmt.pAllocator = 0i64;
    pdestParaFmt.RefCount = 1;
    pdestParaFmt.pTabStops = 0i64;
    *(_QWORD *)&pdestParaFmt.BlockIndent = 0i64;
    *(_DWORD *)&pdestParaFmt.RightMargin = 0;
    Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
      *((Scaleform::Render::Text::StyledText **)v5[1].SetMemberFlags + 2),
      &pdestTextFmt,
      &pdestParaFmt,
      v6,
      endPos);
    v19 = (Scaleform::GFx::AS2::TextFormatObject *)v1->Env->StringContext.pContext->pHeap->vfptr->Alloc(
                                                     v18,
                                                     216ui64,
                                                     0i64);
    if ( v19 )
    {
      Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(v19, v1->Env);
      v4 = v20;
    }
    Scaleform::GFx::AS2::TextFormatObject::SetTextFormat(v4, &v1->Env->StringContext, &pdestTextFmt);
    Scaleform::GFx::AS2::TextFormatObject::SetParagraphFormat(v4, &v1->Env->StringContext, &pdestParaFmt);
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v4->vfptr);
    if ( v4 )
    {
      v21 = v4->RefCount;
      if ( v21 & 0x3FFFFFF )
      {
        v4->RefCount = v21 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->vfptr);
      }
    }
    Scaleform::Render::Text::ParagraphFormat::~ParagraphFormat(&pdestParaFmt);
    Scaleform::Render::Text::TextFormat::~TextFormat(&pdestTextFmt);
  }
}

// File Line: 2031
// RVA: 0x6B8CB0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetNewTextFormat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::TextFormatObject *v4; // rbx
  Scaleform::MemoryHeap *v5; // rcx
  __int64 v6; // rax
  Scaleform::Render::Text::TextFormat *v7; // rsi
  Scaleform::Render::Text::ParagraphFormat *v8; // rbp
  Scaleform::GFx::AS2::TextFormatObject *v9; // rax
  Scaleform::GFx::AS2::TextFormatObject *v10; // rax
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Value *v12; // rbx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) - 2 > 3 )
      v5 = 0i64;
    else
      v5 = (Scaleform::MemoryHeap *)v3[1].vfptr;
    v6 = *(_QWORD *)(v5[1].SelfSize + 16);
    v7 = *(Scaleform::Render::Text::TextFormat **)(v6 + 56);
    v8 = *(Scaleform::Render::Text::ParagraphFormat **)(v6 + 48);
    v9 = (Scaleform::GFx::AS2::TextFormatObject *)v1->Env->StringContext.pContext->pHeap->vfptr->Alloc(
                                                    v5,
                                                    216ui64,
                                                    0i64);
    if ( v9 )
    {
      Scaleform::GFx::AS2::TextFormatObject::TextFormatObject(v9, v1->Env);
      v4 = v10;
    }
    if ( v7 )
      Scaleform::GFx::AS2::TextFormatObject::SetTextFormat(v4, &v1->Env->StringContext, v7);
    if ( v8 )
      Scaleform::GFx::AS2::TextFormatObject::SetParagraphFormat(v4, &v1->Env->StringContext, v8);
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v4->vfptr);
    if ( v4 )
    {
      v11 = v4->RefCount;
      if ( v11 & 0x3FFFFFF )
      {
        v4->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->vfptr);
      }
    }
  }
  else
  {
    v12 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
    v12->T.Type = 0;
  }
}

// File Line: 2056
// RVA: 0x6B8790
void __fastcall Scaleform::GFx::AS2::AvmTextField::SetNewTextFormat(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::TextField *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::GFx::AS2::Object *v6; // rax
  Scaleform::GFx::AS2::Object *v7; // rsi
  Scaleform::Render::Text::DocView::DocumentText *v8; // rax
  Scaleform::Render::Text::ParagraphFormat *v9; // rbx
  Scaleform::Render::Text::TextFormat *v10; // rax
  Scaleform::Render::Text::ParagraphFormat *v11; // rax
  Scaleform::Render::Text::TextFormat result; // [rsp+28h] [rbp-60h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 4 )
  {
    v3 = v1->ThisPtr;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) - 2 > 3 )
      v4 = 0i64;
    else
      v4 = (Scaleform::GFx::TextField *)v3[1].vfptr;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) && v1->NArgs >= 1 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      v6 = Scaleform::GFx::AS2::Value::ToObject(v5, v1->Env);
      v7 = v6;
      if ( v6 )
      {
        if ( (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v6->vfptr->gap8[8])(&v6->vfptr) == 30 )
        {
          v8 = v4->pDocument.pObject->pDocument.pObject;
          v9 = v8->pDefaultParagraphFormat.pObject;
          v10 = Scaleform::Render::Text::TextFormat::Merge(
                  v8->pDefaultTextFormat.pObject,
                  &result,
                  (Scaleform::Render::Text::TextFormat *)&v7[1]);
          Scaleform::Render::Text::StyledText::SetDefaultTextFormat(
            (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->pDocument.pObject->vfptr,
            v10);
          v4->Flags |= 0x10000u;
          Scaleform::Render::Text::TextFormat::~TextFormat(&result);
          v11 = Scaleform::Render::Text::ParagraphFormat::Merge(
                  v9,
                  (Scaleform::Render::Text::ParagraphFormat *)&result,
                  (Scaleform::Render::Text::ParagraphFormat *)&v7[1].pWatchpoints);
          Scaleform::Render::Text::StyledText::SetDefaultParagraphFormat(
            (Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->pDocument.pObject->vfptr,
            v11);
          v4->Flags |= 0x10000u;
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
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r15
  Scaleform::GFx::TextField *v4; // r15
  Scaleform::GFx::AS2::Value *v5; // rax
  double v6; // xmm6_8
  Scaleform::GFx::AS2::Value *v7; // rax
  double v8; // xmm7_8
  Scaleform::GFx::AS2::Value *v9; // rax
  unsigned int v10; // er14
  unsigned int v11; // esi
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // r12
  unsigned __int64 v15; // r13
  bool v16; // cf
  Scaleform::Render::Text::DocView *v17; // rax
  Scaleform::Render::Text::TextFormat *v18; // rdi
  bool v19; // zf
  Scaleform::Render::Text::TextFormat *v20; // rbx
  __int64 v21; // rsi
  wchar_t *v22; // r14
  Scaleform::Render::Text::DocView *v23; // rcx
  Scaleform::GFx::ASStringNode *v24; // rcx
  Scaleform::Render::Text::TextFormat *ppdestTextFmt; // [rsp+30h] [rbp-90h]
  Scaleform::Render::Text::TextFormat *v26; // [rsp+38h] [rbp-88h]
  Scaleform::Render::Text::ParagraphFormat *ppdestParaFmt; // [rsp+40h] [rbp-80h]
  __int64 v28; // [rsp+48h] [rbp-78h]
  __int64 v29; // [rsp+50h] [rbp-70h]
  wchar_t pbuff; // [rsp+60h] [rbp-60h]
  unsigned int v31; // [rsp+890h] [rbp+7D0h]
  Scaleform::GFx::ASString result; // [rsp+898h] [rbp+7D8h]
  Scaleform::Render::Text::TextFormat *v33; // [rsp+8A0h] [rbp+7E0h]
  Scaleform::Render::Text::TextFormat *v34; // [rsp+8A8h] [rbp+7E8h]

  v29 = -2i64;
  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (Scaleform::GFx::TextField *)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                                     - 2 > 3 ? 0i64 : v3[1].vfptr);
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) && v1->NArgs >= 3 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, v1->Env);
      v7 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
      v8 = Scaleform::GFx::AS2::Value::ToNumber(v7, v1->Env);
      v9 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
      Scaleform::GFx::AS2::Value::ToString(v9, &result, v1->Env, -1);
      v10 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode);
      v31 = v10;
      v11 = (signed int)v6;
      v28 = (unsigned int)(signed int)v6;
      v12 = (signed int)v8;
      if ( v6 >= 0.0 && v8 >= 0.0 && v11 <= v12 )
      {
        v33 = 0i64;
        v34 = 0i64;
        v13 = Scaleform::Render::Text::StyledText::GetLength((Scaleform::Render::Text::StyledText *)&v4->pDocument.pObject->pDocument.pObject->vfptr);
        v14 = v13 + v10 - (unsigned __int64)(v12 - v11);
        v15 = v11;
        v16 = v11 < v13;
        v17 = v4->pDocument.pObject;
        if ( v16 )
        {
          Scaleform::Render::Text::StyledText::GetTextAndParagraphFormat(
            (Scaleform::Render::Text::StyledText *)&v17->pDocument.pObject->vfptr,
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
          v18 = v17->pDocument.pObject->pDefaultTextFormat.pObject;
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
        if ( v10 >= 0x400 )
        {
          v21 = v10 + 1;
          v22 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v21, 0i64);
          Scaleform::UTF8Util::DecodeStringSafe(v22, (unsigned int)v21, result.pNode->pData, -1i64);
          Scaleform::GFx::TextField::ReplaceText(v4, v22, v15, (unsigned int)(signed int)v8, 0xFFFFFFFFFFFFFFFFui64);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v22);
          v11 = v28;
          v10 = v31;
        }
        else
        {
          Scaleform::UTF8Util::DecodeStringSafe(&pbuff, 0x400ui64, result.pNode->pData, -1i64);
          Scaleform::GFx::TextField::ReplaceText(v4, &pbuff, v11, (unsigned int)(signed int)v8, 0xFFFFFFFFFFFFFFFFui64);
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
            v11 + v10);
        if ( v18 )
          Scaleform::Render::Text::DocView::SetTextFormat(v4->pDocument.pObject, v18, v15, v11 + v10);
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
      v24 = result.pNode;
      v19 = result.pNode->RefCount == 1;
      --v24->RefCount;
      if ( v19 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
    }
  }
}

// File Line: 2165
// RVA: 0x6B8E80
void __fastcall Scaleform::GFx::AS2::AvmTextField::ReplaceSel(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // r14
  Scaleform::GFx::TextField *v4; // r14
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::Render::Text::TextFormat *v6; // rsi
  Scaleform::Render::Text::ParagraphFormat *v7; // rbp
  unsigned int v8; // eax
  __int64 v9; // r13
  Scaleform::Render::Text::EditorKitBase *v10; // rcx
  Scaleform::RefCountImplCoreVtbl *v11; // rdx
  unsigned __int64 v12; // r15
  Scaleform::RefCountImplCoreVtbl *v13; // rdx
  unsigned __int64 v14; // r12
  __int64 v15; // rbx
  wchar_t *v16; // rdi
  bool v17; // zf
  Scaleform::GFx::ASStringNode *v18; // rcx
  wchar_t pbuff; // [rsp+40h] [rbp-838h]
  Scaleform::GFx::ASString result; // [rsp+880h] [rbp+8h]
  Scaleform::Render::Text::TextFormat *v21; // [rsp+888h] [rbp+10h]
  Scaleform::Render::Text::ParagraphFormat *v22; // [rsp+890h] [rbp+18h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (Scaleform::GFx::TextField *)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                                     - 2 > 3 ? 0i64 : v3[1].vfptr);
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) && v1->NArgs >= 1 && v4->pDocument.pObject->pEditorKit.pObject )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToString(v5, &result, v1->Env, -1);
      v6 = v4->pDocument.pObject->pDocument.pObject->pDefaultTextFormat.pObject;
      v21 = 0i64;
      if ( v6 )
        ++v6->RefCount;
      v21 = v6;
      v7 = v4->pDocument.pObject->pDocument.pObject->pDefaultParagraphFormat.pObject;
      v22 = 0i64;
      if ( v7 )
        ++v7->RefCount;
      v22 = v7;
      v8 = Scaleform::GFx::ASConstString::GetLength((Scaleform::GFx::ASConstString *)&result.pNode);
      v9 = v8;
      v10 = v4->pDocument.pObject->pEditorKit.pObject;
      v11 = v10[1].vfptr;
      v12 = (unsigned __int64)v11[8].__vecDelDtor;
      if ( (char *)v11[7].__vecDelDtor < (char *)v12 )
        v12 = (unsigned __int64)v11[7].__vecDelDtor;
      v13 = v10[1].vfptr;
      v14 = (unsigned __int64)v13[8].__vecDelDtor;
      if ( (char *)v14 < (char *)v13[7].__vecDelDtor )
        v14 = (unsigned __int64)v13[7].__vecDelDtor;
      if ( v8 >= 0x400 )
      {
        v15 = v8 + 1;
        v16 = (wchar_t *)Scaleform::Memory::pGlobalHeap->vfptr->Alloc(Scaleform::Memory::pGlobalHeap, 2 * v15, 0i64);
        Scaleform::UTF8Util::DecodeStringSafe(v16, (unsigned int)v15, result.pNode->pData, -1i64);
        Scaleform::GFx::TextField::ReplaceText(v4, v16, v12, v14, 0xFFFFFFFFFFFFFFFFui64);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v16);
      }
      else
      {
        Scaleform::UTF8Util::DecodeStringSafe(&pbuff, 0x400ui64, result.pNode->pData, -1i64);
        Scaleform::GFx::TextField::ReplaceText(v4, &pbuff, v12, v14, 0xFFFFFFFFFFFFFFFFui64);
      }
      Scaleform::GFx::Text::EditorKit::SetCursorPos(
        (Scaleform::GFx::Text::EditorKit *)v4->pDocument.pObject->pEditorKit.pObject,
        v12 + v9,
        0);
      if ( v7 )
        Scaleform::Render::Text::DocView::SetParagraphFormat(v4->pDocument.pObject, v7, v12, v12 + v9);
      if ( v6 )
        Scaleform::Render::Text::DocView::SetTextFormat(v4->pDocument.pObject, v6, v12, v12 + v9);
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
      if ( v6 )
      {
        v17 = v6->RefCount-- == 1;
        if ( v17 )
        {
          Scaleform::Render::Text::TextFormat::~TextFormat(v6);
          Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
        }
      }
      v18 = result.pNode;
      v17 = result.pNode->RefCount == 1;
      --v18->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    }
  }
}

// File Line: 2206
// RVA: 0x6B96E0
void __fastcall Scaleform::GFx::AS2::AvmTextField::RemoveTextField(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  Scaleform::GFx::InteractiveObject *v4; // rbx
  Scaleform::GFx::ASString *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 4 )
  {
    v3 = v1->ThisPtr;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v3) - 2 > 3 )
      v4 = 0i64;
    else
      v4 = (Scaleform::GFx::InteractiveObject *)v3[1].vfptr;
    if ( v4->Depth >= 0x4000 )
    {
      Scaleform::GFx::InteractiveObject::RemoveDisplayObject(v4);
    }
    else
    {
      v5 = Scaleform::GFx::DisplayObject::GetName((Scaleform::GFx::DisplayObject *)&v4->vfptr, &result);
      Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::LogScriptWarning(
        (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase> *)&v4->vfptr,
        "%s.removeMovieClip() failed - depth must be >= 0",
        v5->pNode->pData);
      v6 = result.pNode;
      v7 = result.pNode->RefCount == 1;
      --v6->RefCount;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    }
  }
}

// File Line: 2223
// RVA: 0x6BBCD0
void __fastcall Scaleform::GFx::AS2::AvmTextField::AppendText(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::TextField *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf
  Scaleform::GFx::ASString result; // [rsp+40h] [rbp+8h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 4 )
  {
    v3 = v1->ThisPtr;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr) - 2 > 3 )
      v4 = 0i64;
    else
      v4 = (Scaleform::GFx::TextField *)v3[1].vfptr;
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) && v1->NArgs >= 1 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToString(v5, &result, v1->Env, -1);
      Scaleform::Render::Text::DocView::AppendText(v4->pDocument.pObject, result.pNode->pData, 0xFFFFFFFFFFFFFFFFui64);
      v4->Flags |= 0x10000u;
      Scaleform::GFx::TextField::SetDirtyFlag(v4);
      v6 = result.pNode;
      v7 = result.pNode->RefCount == 1;
      --v6->RefCount;
      if ( v7 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    }
  }
}

// File Line: 2240
// RVA: 0x6BBDA0
void __fastcall Scaleform::GFx::AS2::AvmTextField::AppendHtml(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rbx
  Scaleform::GFx::TextField *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rax
  Scaleform::MemoryHeap *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> imageInfoArray; // [rsp+38h] [rbp-30h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]
  Scaleform::ArrayDH<Scaleform::Render::Text::StyledText::HTMLImageTagInfo,2,Scaleform::ArrayDefaultPolicy> *v11; // [rsp+78h] [rbp+10h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (Scaleform::GFx::TextField *)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                                     - 2 > 3 ? 0i64 : v3[1].vfptr);
    if ( !Scaleform::GFx::TextField::HasStyleSheet(v4) && v1->NArgs >= 1 )
    {
      v5 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
      Scaleform::GFx::AS2::Value::ToString(v5, &result, v1->Env, -1);
      v6 = Scaleform::Memory::pGlobalHeap->vfptr->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v4);
      v11 = &imageInfoArray;
      imageInfoArray.Data.Data = 0i64;
      *(_OWORD *)&imageInfoArray.Data.Size = 0ui64;
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
      v11 = &imageInfoArray;
      Scaleform::ConstructorMov<Scaleform::Render::Text::StyledText::HTMLImageTagInfo>::DestructArray(
        imageInfoArray.Data.Data,
        imageInfoArray.Data.Size);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, imageInfoArray.Data.Data);
      v7 = result.pNode;
      v8 = result.pNode->RefCount == 1;
      --v7->RefCount;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
    }
  }
}

// File Line: 2262
// RVA: 0x6B9820
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetCharBoundaries(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::RectangleObject *v4; // rdi
  signed __int64 v5; // rsi
  unsigned int v6; // er10
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  unsigned int v9; // eax
  __int64 v10; // rcx
  Scaleform::GFx::AS2::RectangleObject *v11; // rax
  Scaleform::GFx::AS2::RectangleObject *v12; // rax
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::Render::Rect<float> pCharRect; // [rsp+30h] [rbp-38h]
  Scaleform::Render::Rect<double> r; // [rsp+40h] [rbp-28h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    v5 = (signed __int64)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                        - 2 > 3 ? 0i64 : v3[1].vfptr);
    if ( v1->NArgs >= 1 )
    {
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      v8 = 0i64;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToUInt32(v8, v7);
      pCharRect = 0i64;
      if ( Scaleform::Render::Text::DocView::GetCharBoundaries(
             *(Scaleform::Render::Text::DocView **)(v5 + 224),
             &pCharRect,
             v9) )
      {
        v11 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, signed __int64))v1->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                        v10,
                                                        96i64);
        if ( v11 )
        {
          Scaleform::GFx::AS2::RectangleObject::RectangleObject(v11, v1->Env);
          v4 = v12;
        }
        r.x1 = pCharRect.x1 * 0.05;
        r.y1 = pCharRect.y1 * 0.05;
        r.x2 = pCharRect.x2 * 0.05;
        r.y2 = pCharRect.y2 * 0.05;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(v4, v1->Env, &r);
        Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v4->vfptr);
        if ( v4 )
        {
          v13 = v4->RefCount;
          if ( v13 & 0x3FFFFFF )
          {
            v4->RefCount = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->vfptr);
          }
        }
      }
      else
      {
        v14 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v14);
        v14->T.Type = 1;
      }
    }
  }
}

// File Line: 2304
// RVA: 0x6B9CA0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetExactCharBoundaries(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::RectangleObject *v4; // rdi
  signed __int64 v5; // rsi
  unsigned int v6; // er10
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  unsigned int v9; // eax
  __int64 v10; // rcx
  Scaleform::GFx::AS2::RectangleObject *v11; // rax
  Scaleform::GFx::AS2::RectangleObject *v12; // rax
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::Render::Rect<float> pCharRect; // [rsp+30h] [rbp-38h]
  Scaleform::Render::Rect<double> r; // [rsp+40h] [rbp-28h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    v5 = (signed __int64)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                        - 2 > 3 ? 0i64 : v3[1].vfptr);
    if ( v1->NArgs >= 1 )
    {
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      v8 = 0i64;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToUInt32(v8, v7);
      pCharRect = 0i64;
      if ( Scaleform::Render::Text::DocView::GetExactCharBoundaries(
             *(Scaleform::Render::Text::DocView **)(v5 + 224),
             &pCharRect,
             v9) )
      {
        v11 = (Scaleform::GFx::AS2::RectangleObject *)((__int64 (__fastcall *)(__int64, signed __int64))v1->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                        v10,
                                                        96i64);
        if ( v11 )
        {
          Scaleform::GFx::AS2::RectangleObject::RectangleObject(v11, v1->Env);
          v4 = v12;
        }
        r.x1 = pCharRect.x1 * 0.05;
        r.y1 = pCharRect.y1 * 0.05;
        r.x2 = pCharRect.x2 * 0.05;
        r.y2 = pCharRect.y2 * 0.05;
        Scaleform::GFx::AS2::RectangleObject::SetProperties(v4, v1->Env, &r);
        Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)&v4->vfptr);
        if ( v4 )
        {
          v13 = v4->RefCount;
          if ( v13 & 0x3FFFFFF )
          {
            v4->RefCount = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->vfptr);
          }
        }
      }
      else
      {
        v14 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v14);
        v14->T.Type = 1;
      }
    }
  }
}

// File Line: 2345
// RVA: 0x6B9A80
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetCharIndexAtPoint(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::Value *v4; // rbx
  signed __int64 v5; // rsi
  Scaleform::GFx::AS2::Environment *v6; // rdx
  unsigned __int64 v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r9
  double v9; // xmm0_8
  Scaleform::GFx::AS2::Environment *v10; // rdx
  unsigned __int64 v11; // r8
  float v12; // xmm1_4
  float v13; // xmm2_4
  signed __int64 v14; // rax
  double v15; // xmm1_8

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    v5 = (signed __int64)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                        - 2 > 3 ? 0i64 : v3[1].vfptr);
    if ( v1->NArgs >= 2 )
    {
      v6 = v1->Env;
      v7 = (unsigned int)v1->FirstArgBottomIndex;
      v8 = 0i64;
      if ( (unsigned int)v7 <= 32 * (LODWORD(v6->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
        v8 = &v6->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToNumber(v8, v6);
      v10 = v1->Env;
      v11 = (unsigned int)(v1->FirstArgBottomIndex - 1);
      if ( (unsigned int)v11 <= 32 * (LODWORD(v10->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)((_QWORD)((char *)v10->Stack.pCurrent - (char *)v10->Stack.pPageStart) >> 5) )
        v4 = &v10->Stack.Pages.Data.Data[v11 >> 5]->Values[(LOBYTE(v1->FirstArgBottomIndex) - 1) & 0x1F];
      v12 = v9 * 20.0;
      v13 = Scaleform::GFx::AS2::Value::ToNumber(v4, v10) * 20.0;
      v14 = Scaleform::Render::Text::DocView::GetCharIndexAtPoint(
              *(Scaleform::Render::Text::DocView **)(v5 + 224),
              v12,
              v13);
      if ( v14 == -1 )
      {
        v15 = DOUBLE_N1_0;
      }
      else
      {
        v15 = (double)(signed int)v14;
        if ( v14 < 0 )
          v15 = v15 + 1.844674407370955e19;
      }
      Scaleform::GFx::AS2::Value::SetNumber(v1->Result, v15);
    }
  }
}

// File Line: 2364
// RVA: 0x6B9F00
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineIndexAtPoint(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::Value *v4; // rbx
  signed __int64 v5; // rsi
  Scaleform::GFx::AS2::Environment *v6; // rdx
  unsigned __int64 v7; // r8
  Scaleform::GFx::AS2::Value *v8; // r9
  double v9; // xmm0_8
  Scaleform::GFx::AS2::Environment *v10; // rdx
  unsigned __int64 v11; // r8
  float v12; // xmm1_4
  float v13; // xmm2_4
  signed int v14; // eax
  double v15; // xmm1_8

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    v5 = (signed __int64)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                        - 2 > 3 ? 0i64 : v3[1].vfptr);
    if ( v1->NArgs >= 2 )
    {
      v6 = v1->Env;
      v7 = (unsigned int)v1->FirstArgBottomIndex;
      v8 = 0i64;
      if ( (unsigned int)v7 <= 32 * (LODWORD(v6->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
        v8 = &v6->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToNumber(v8, v6);
      v10 = v1->Env;
      v11 = (unsigned int)(v1->FirstArgBottomIndex - 1);
      if ( (unsigned int)v11 <= 32 * (LODWORD(v10->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)((_QWORD)((char *)v10->Stack.pCurrent - (char *)v10->Stack.pPageStart) >> 5) )
        v4 = &v10->Stack.Pages.Data.Data[v11 >> 5]->Values[(LOBYTE(v1->FirstArgBottomIndex) - 1) & 0x1F];
      v12 = v9 * 20.0;
      v13 = Scaleform::GFx::AS2::Value::ToNumber(v4, v10) * 20.0;
      v14 = Scaleform::Render::Text::DocView::GetLineIndexAtPoint(
              *(Scaleform::Render::Text::DocView **)(v5 + 224),
              v12,
              v13);
      if ( v14 == -1 )
        v15 = DOUBLE_N1_0;
      else
        v15 = (double)v14;
      Scaleform::GFx::AS2::Value::SetNumber(v1->Result, v15);
    }
  }
}

// File Line: 2383
// RVA: 0x6BA250
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineOffset(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // r9
  signed __int64 v6; // rdi
  Scaleform::GFx::AS2::Environment *v7; // rdx
  unsigned __int64 v8; // r8
  signed int v9; // edx
  signed __int64 v10; // rax
  double v11; // xmm1_8

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr);
    v5 = 0i64;
    v6 = (signed __int64)((unsigned int)(v4 - 2) > 3 ? 0i64 : v3[1].vfptr);
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->Env;
      v8 = (unsigned int)v1->FirstArgBottomIndex;
      if ( (unsigned int)v8 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v5 = &v7->Stack.Pages.Data.Data[v8 >> 5]->Values[v1->FirstArgBottomIndex & 0x1F];
      v9 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v5, v7);
      if ( v9 < 0
        || (v10 = Scaleform::Render::Text::DocView::GetLineOffset(*(Scaleform::Render::Text::DocView **)(v6 + 224), v9),
            v10 == -1) )
      {
        v11 = DOUBLE_N1_0;
      }
      else
      {
        v11 = (double)(signed int)v10;
        if ( v10 < 0 )
          v11 = v11 + 1.844674407370955e19;
      }
      Scaleform::GFx::AS2::Value::SetNumber(v1->Result, v11);
    }
  }
}

// File Line: 2406
// RVA: 0x6BA3E0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineLength(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // r9
  signed __int64 v6; // rdi
  Scaleform::GFx::AS2::Environment *v7; // rdx
  unsigned __int64 v8; // r8
  signed int v9; // edx
  signed __int64 v10; // rax
  double v11; // xmm1_8

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr);
    v5 = 0i64;
    v6 = (signed __int64)((unsigned int)(v4 - 2) > 3 ? 0i64 : v3[1].vfptr);
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->Env;
      v8 = (unsigned int)v1->FirstArgBottomIndex;
      if ( (unsigned int)v8 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v5 = &v7->Stack.Pages.Data.Data[v8 >> 5]->Values[v1->FirstArgBottomIndex & 0x1F];
      v9 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v5, v7);
      if ( v9 < 0
        || (v10 = Scaleform::Render::Text::DocView::GetLineLength(
                    *(Scaleform::Render::Text::DocView **)(v6 + 224),
                    v9,
                    0i64),
            v10 == -1) )
      {
        v11 = DOUBLE_N1_0;
      }
      else
      {
        v11 = (double)(signed int)v10;
        if ( v10 < 0 )
          v11 = v11 + 1.844674407370955e19;
      }
      Scaleform::GFx::AS2::Value::SetNumber(v1->Result, v11);
    }
  }
}

// File Line: 2429
// RVA: 0x6BA5C0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineMetrics(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rdi
  signed __int64 v5; // rsi
  unsigned int v6; // er10
  Scaleform::GFx::AS2::Environment *v7; // rdx
  Scaleform::GFx::AS2::Value *v8; // r9
  signed int v9; // edx
  __int64 v10; // rcx
  Scaleform::GFx::AS2::Object *v11; // rax
  Scaleform::GFx::AS2::Object *v12; // rax
  unsigned int v13; // eax
  Scaleform::GFx::AS2::Value *v14; // rbx
  Scaleform::Render::Text::DocView::LineMetrics pmetrics; // [rsp+28h] [rbp-48h]
  Scaleform::GFx::AS2::Value val; // [rsp+40h] [rbp-30h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    v5 = (signed __int64)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                        - 2 > 3 ? 0i64 : v3[1].vfptr);
    if ( v1->NArgs >= 1 )
    {
      v6 = v1->FirstArgBottomIndex;
      v7 = v1->Env;
      v8 = 0i64;
      if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v8 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
      v9 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v8, v7);
      if ( v9 >= 0
        && Scaleform::Render::Text::DocView::GetLineMetrics(
             *(Scaleform::Render::Text::DocView **)(v5 + 224),
             v9,
             &pmetrics) )
      {
        v11 = (Scaleform::GFx::AS2::Object *)((__int64 (__fastcall *)(__int64, signed __int64))v1->Env->StringContext.pContext->pHeap->vfptr->Alloc)(
                                               v10,
                                               96i64);
        if ( v11 )
        {
          Scaleform::GFx::AS2::Object::Object(v11, v1->Env);
          v4 = v12;
        }
        val.T.Type = 3;
        val.NV.NumberValue = (double)(signed int)pmetrics.Ascent * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
          &v1->Env->StringContext,
          "ascent",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        val.T.Type = 3;
        val.NV.NumberValue = (double)(signed int)pmetrics.Descent * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
          &v1->Env->StringContext,
          "descent",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        val.T.Type = 3;
        val.NV.NumberValue = (double)(signed int)pmetrics.Width * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
          &v1->Env->StringContext,
          "width",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        val.T.Type = 3;
        val.NV.NumberValue = (double)(signed int)pmetrics.Height * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
          &v1->Env->StringContext,
          "height",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        val.T.Type = 3;
        val.NV.NumberValue = (double)pmetrics.Leading * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
          &v1->Env->StringContext,
          "leading",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        val.T.Type = 3;
        val.NV.NumberValue = (double)pmetrics.FirstCharXOff * 0.05;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
          &v1->Env->StringContext,
          "x",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v4);
        if ( v4 )
        {
          v13 = v4->RefCount;
          if ( v13 & 0x3FFFFFF )
          {
            v4->RefCount = v13 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->vfptr);
          }
        }
      }
      else
      {
        v14 = v1->Result;
        Scaleform::GFx::AS2::Value::DropRefs(v14);
        v14->T.Type = 0;
      }
    }
  }
}

// File Line: 2462
// RVA: 0x6BA9B0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineText(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  signed __int64 v4; // rdi
  unsigned int v5; // er10
  Scaleform::GFx::AS2::Environment *v6; // rdx
  Scaleform::GFx::AS2::Value *v7; // r9
  signed int v8; // edx
  Scaleform::GFx::AS2::Value *v9; // rbx
  const wchar_t *v10; // rdi
  Scaleform::GFx::AS2::Value *v11; // rbx
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASString *v14; // rax
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]
  Scaleform::String str; // [rsp+58h] [rbp+10h]
  unsigned __int64 plen; // [rsp+60h] [rbp+18h]
  Scaleform::GFx::ASString v19; // [rsp+68h] [rbp+20h]

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v2->vfptr->gap8[8])(v2) == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (signed __int64)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                        - 2 > 3 ? 0i64 : v3[1].vfptr);
    if ( v1->NArgs >= 1 )
    {
      v5 = v1->FirstArgBottomIndex;
      v6 = v1->Env;
      v7 = 0i64;
      if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
        v7 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
      v8 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v7, v6);
      if ( v8 >= 0 )
      {
        plen = 0i64;
        v10 = Scaleform::Render::Text::DocView::GetLineText(*(Scaleform::Render::Text::DocView **)(v4 + 224), v8, &plen);
        if ( v10 )
        {
          Scaleform::String::String(&str);
          Scaleform::String::AppendString(&str, v10, plen);
          Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &result, &str);
          v11 = v1->Result;
          if ( v11->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v11);
          v11->T.Type = 5;
          v11->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)result.pNode;
          ++result.pNode->RefCount;
          v12 = result.pNode;
          v13 = result.pNode->RefCount == 1;
          --v12->RefCount;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v12);
          if ( !_InterlockedDecrement((volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
        }
        else
        {
          v14 = Scaleform::GFx::AS2::Environment::CreateConstString(v1->Env, &v19, &customWorldMapCaption);
          Scaleform::GFx::AS2::Value::SetString(v1->Result, v14);
          v15 = v19.pNode;
          v13 = v19.pNode->RefCount == 1;
          --v15->RefCount;
          if ( v13 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v15);
        }
      }
      else
      {
        v9 = v1->Result;
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
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // r9
  signed __int64 v6; // rdi
  Scaleform::GFx::AS2::Environment *v7; // rdx
  unsigned __int64 v8; // r8
  signed int v9; // eax
  signed __int64 v10; // rax
  double v11; // xmm1_8

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr);
    v5 = 0i64;
    v6 = (signed __int64)((unsigned int)(v4 - 2) > 3 ? 0i64 : v3[1].vfptr);
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->Env;
      v8 = (unsigned int)v1->FirstArgBottomIndex;
      if ( (unsigned int)v8 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v5 = &v7->Stack.Pages.Data.Data[v8 >> 5]->Values[v1->FirstArgBottomIndex & 0x1F];
      v9 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v5, v7);
      if ( v9 < 0
        || (v10 = Scaleform::Render::Text::DocView::GetFirstCharInParagraph(
                    *(Scaleform::Render::Text::DocView **)(v6 + 224),
                    (unsigned int)v9),
            v10 == -1) )
      {
        v11 = DOUBLE_N1_0;
      }
      else
      {
        v11 = (double)(signed int)v10;
        if ( v10 < 0 )
          v11 = v11 + 1.844674407370955e19;
      }
      Scaleform::GFx::AS2::Value::SetNumber(v1->Result, v11);
    }
  }
}

// File Line: 2515
// RVA: 0x6BA0F0
void __fastcall Scaleform::GFx::AS2::AvmTextField::GetLineIndexOfChar(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  int v4; // eax
  Scaleform::GFx::AS2::Value *v5; // r9
  signed __int64 v6; // rdi
  Scaleform::GFx::AS2::Environment *v7; // rdx
  unsigned __int64 v8; // r8
  signed int v9; // eax
  signed int v10; // eax
  double v11; // xmm1_8

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr);
    v5 = 0i64;
    v6 = (signed __int64)((unsigned int)(v4 - 2) > 3 ? 0i64 : v3[1].vfptr);
    if ( v1->NArgs >= 1 )
    {
      v7 = v1->Env;
      v8 = (unsigned int)v1->FirstArgBottomIndex;
      if ( (unsigned int)v8 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v5 = &v7->Stack.Pages.Data.Data[v8 >> 5]->Values[v1->FirstArgBottomIndex & 0x1F];
      v9 = (signed int)Scaleform::GFx::AS2::Value::ToNumber(v5, v7);
      if ( v9 < 0
        || (v10 = Scaleform::Render::Text::DocView::GetLineIndexOfChar(
                    *(Scaleform::Render::Text::DocView **)(v6 + 224),
                    (unsigned int)v9),
            v10 == -1) )
      {
        v11 = DOUBLE_N1_0;
      }
      else
      {
        v11 = (double)v10;
      }
      Scaleform::GFx::AS2::Value::SetNumber(v1->Result, v11);
    }
  }
}

// File Line: 2541
// RVA: 0x6BBF00
void __fastcall Scaleform::GFx::AS2::AvmTextField::CopyToClipboard(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  signed __int64 v4; // rax
  __int64 v5; // rdi
  __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // r14
  bool v10; // si
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rax
  Scaleform::GFx::AS2::Value *v13; // rax

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (signed __int64)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                        - 2 > 3 ? 0i64 : v3[1].vfptr);
    v5 = *(_QWORD *)(*(_QWORD *)(v4 + 224) + 216i64);
    if ( v5 )
    {
      v6 = *(_QWORD *)(v5 + 16);
      v7 = *(_QWORD *)(v6 + 56);
      v8 = *(_QWORD *)(v6 + 64);
      v9 = *(_QWORD *)(v6 + 64);
      v10 = (*(_BYTE *)(v5 + 160) >> 2) & 1;
      if ( v7 < v9 )
        LODWORD(v9) = v7;
      if ( v8 < v7 )
        LODWORD(v8) = v7;
      if ( v1->NArgs >= 1 )
      {
        v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        v10 = Scaleform::GFx::AS2::Value::ToBool(v11, v1->Env);
      }
      if ( v1->NArgs >= 2 )
      {
        v12 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
        LODWORD(v9) = Scaleform::GFx::AS2::Value::ToUInt32(v12, v1->Env);
      }
      if ( v1->NArgs >= 3 )
      {
        v13 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        LODWORD(v8) = Scaleform::GFx::AS2::Value::ToUInt32(v13, v1->Env);
      }
      Scaleform::GFx::Text::EditorKit::CopyToClipboard(
        (Scaleform::GFx::Text::EditorKit *)v5,
        (unsigned int)v9,
        (unsigned int)v8,
        v10);
    }
  }
}

// File Line: 2567
// RVA: 0x6BC030
void __fastcall Scaleform::GFx::AS2::AvmTextField::CutToClipboard(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::TextField *v4; // rdi
  Scaleform::Render::Text::EditorKitBase *v5; // rsi
  Scaleform::RefCountImplCoreVtbl *v6; // rcx
  void *(__fastcall *v7)(Scaleform::RefCountImplCore *, unsigned int); // rax
  void *(__fastcall *v8)(Scaleform::RefCountImplCore *, unsigned int); // r14
  bool v9; // bp
  void *(__fastcall *v10)(Scaleform::RefCountImplCore *, unsigned int); // r15
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rax
  Scaleform::GFx::AS2::Value *v13; // rax

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (Scaleform::GFx::TextField *)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                                     - 2 > 3 ? 0i64 : v3[1].vfptr);
    v5 = v4->pDocument.pObject->pEditorKit.pObject;
    if ( v5 )
    {
      v6 = v5[1].vfptr;
      v7 = v6[7].__vecDelDtor;
      v8 = v6[8].__vecDelDtor;
      v9 = (LOBYTE(v5[10].vfptr) >> 2) & 1;
      v10 = v6[8].__vecDelDtor;
      if ( (unsigned __int64)v7 < (unsigned __int64)v10 )
        LODWORD(v10) = (_DWORD)v7;
      if ( (unsigned __int64)v8 < (unsigned __int64)v7 )
        LODWORD(v8) = (_DWORD)v7;
      if ( v1->NArgs >= 1 )
      {
        v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        v9 = Scaleform::GFx::AS2::Value::ToBool(v11, v1->Env);
      }
      if ( v1->NArgs >= 2 )
      {
        v12 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
        LODWORD(v10) = Scaleform::GFx::AS2::Value::ToUInt32(v12, v1->Env);
      }
      if ( v1->NArgs >= 3 )
      {
        v13 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        LODWORD(v8) = Scaleform::GFx::AS2::Value::ToUInt32(v13, v1->Env);
      }
      Scaleform::GFx::Text::EditorKit::CutToClipboard(
        (Scaleform::GFx::Text::EditorKit *)v5,
        (unsigned int)v10,
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
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::TextField *v4; // rdi
  Scaleform::Render::Text::EditorKitBase *v5; // rsi
  Scaleform::RefCountImplCoreVtbl *v6; // rcx
  void *(__fastcall *v7)(Scaleform::RefCountImplCore *, unsigned int); // rax
  void *(__fastcall *v8)(Scaleform::RefCountImplCore *, unsigned int); // r14
  bool v9; // bp
  void *(__fastcall *v10)(Scaleform::RefCountImplCore *, unsigned int); // r15
  Scaleform::GFx::AS2::Value *v11; // rax
  Scaleform::GFx::AS2::Value *v12; // rax
  Scaleform::GFx::AS2::Value *v13; // rax

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( v2 && (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() == 4 )
  {
    v3 = v1->ThisPtr;
    v4 = (Scaleform::GFx::TextField *)((*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&v3->vfptr->gap8[8])(v1->ThisPtr)
                                     - 2 > 3 ? 0i64 : v3[1].vfptr);
    v5 = v4->pDocument.pObject->pEditorKit.pObject;
    if ( v5 )
    {
      v6 = v5[1].vfptr;
      v7 = v6[7].__vecDelDtor;
      v8 = v6[8].__vecDelDtor;
      v9 = (LOBYTE(v5[10].vfptr) >> 2) & 1;
      v10 = v6[8].__vecDelDtor;
      if ( (unsigned __int64)v7 < (unsigned __int64)v10 )
        LODWORD(v10) = (_DWORD)v7;
      if ( (unsigned __int64)v8 < (unsigned __int64)v7 )
        LODWORD(v8) = (_DWORD)v7;
      if ( v1->NArgs >= 1 )
      {
        v11 = Scaleform::GFx::AS2::FnCall::Arg(v1, 0);
        v9 = Scaleform::GFx::AS2::Value::ToBool(v11, v1->Env);
      }
      if ( v1->NArgs >= 2 )
      {
        v12 = Scaleform::GFx::AS2::FnCall::Arg(v1, 1);
        LODWORD(v10) = Scaleform::GFx::AS2::Value::ToUInt32(v12, v1->Env);
      }
      if ( v1->NArgs >= 3 )
      {
        v13 = Scaleform::GFx::AS2::FnCall::Arg(v1, 2);
        LODWORD(v8) = Scaleform::GFx::AS2::Value::ToUInt32(v13, v1->Env);
      }
      Scaleform::GFx::Text::EditorKit::PasteFromClipboard(
        (Scaleform::GFx::Text::EditorKit *)v5,
        (unsigned int)v10,
        (unsigned int)v8,
        v9);
      Scaleform::GFx::TextField::SetDirtyFlag(v4);
    }
  }
}

// File Line: 2621
// RVA: 0x6CBF40
void __fastcall Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(Scaleform::GFx::AS2::TextFieldObject *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *pprototype)
{
  Scaleform::GFx::AS2::Object *v3; // rbx
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::TextFieldObject *v5; // rsi

  v3 = pprototype;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v5->pTextField.pProxy.pObject = 0i64;
  v5->pIMECompositionStringStyles = 0i64;
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v5->vfptr, v4, v3);
}

// File Line: 2628
// RVA: 0x6CBFC0
void __fastcall Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(Scaleform::GFx::AS2::TextFieldObject *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::TextFieldObject *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3->pTextField.pProxy.pObject = 0i64;
  v3->pIMECompositionStringStyles = 0i64;
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->StringContext.pContext, ASBuiltin_TextField);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, &v2->StringContext, v4);
}

// File Line: 2635
// RVA: 0x6CC050
void __fastcall Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(Scaleform::GFx::AS2::TextFieldObject *this, Scaleform::GFx::AS2::GlobalContext *gCtxt, Scaleform::GFx::InteractiveObject *ptextfield)
{
  Scaleform::GFx::InteractiveObject *v3; // rbx
  Scaleform::GFx::AS2::TextFieldObject *v4; // rdi
  Scaleform::GFx::MovieImpl *v5; // rax
  Scaleform::GFx::AS2::ASRefCountCollector *v6; // rdx
  Scaleform::WeakPtrProxy *v7; // rax
  _QWORD *v8; // rbx
  __int64 v9; // rdx
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::Value v13; // [rsp+38h] [rbp-40h]
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v14; // [rsp+88h] [rbp+10h]

  v3 = ptextfield;
  v4 = this;
  v5 = gCtxt->pMovieRoot;
  if ( v5 )
    v6 = (Scaleform::GFx::AS2::ASRefCountCollector *)v5->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    v6 = 0i64;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, v6);
  v4->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v4->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v14 = &v4->pTextField;
  if ( v3 )
    v7 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v3->vfptr);
  else
    v7 = 0i64;
  v4->pTextField.pProxy.pObject = v7;
  v8 = (Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * (unsigned __int8)v3->AvmObjOffset);
  v9 = (*(__int64 (__fastcall **)(_QWORD *))(*v8 + 240i64))(v8) + 232;
  v10 = (Scaleform::GFx::AS2::Object *)v8[2];
  if ( !v4->pProto.pObject )
  {
    LOBYTE(v14) = 3;
    v13.T.Type = 10;
    v4->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
      (Scaleform::GFx::AS2::ASStringContext *)v9,
      (Scaleform::GFx::ASString *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)v9 + 40i64) + 24i64) + 936i64),
      &v13,
      (Scaleform::GFx::AS2::PropFlags *)&v14);
    if ( v13.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v13);
  }
  if ( v10 )
    v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
  v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->pProto.pObject->vfptr;
  if ( v11 )
  {
    v12 = v11->RefCount;
    if ( v12 & 0x3FFFFFF )
    {
      v11->RefCount = v12 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
    }
  }
  v4->pProto.pObject = v10;
  v4->pIMECompositionStringStyles = 0i64;
}

// File Line: 2644
// RVA: 0x6D27B0
void __fastcall Scaleform::GFx::AS2::TextFieldObject::~TextFieldObject(Scaleform::GFx::AS2::TextFieldObject *this)
{
  Scaleform::GFx::AS2::TextFieldObject *v1; // rbx
  Scaleform::WeakPtrProxy *v2; // rdx
  bool v3; // zf

  v1 = this;
  this->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pIMECompositionStringStyles);
  v2 = v1->pTextField.pProxy.pObject;
  if ( v2 )
  {
    v3 = v2->RefCount-- == 1;
    if ( v3 )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  Scaleform::GFx::AS2::Object::~Object((Scaleform::GFx::AS2::Object *)&v1->vfptr);
}

// File Line: 2649
// RVA: 0x6EFB70
Scaleform::GFx::Text::IMEStyle *__fastcall Scaleform::GFx::AS2::TextFieldObject::GetIMECompositionStringStyles(Scaleform::GFx::AS2::TextFieldObject *this)
{
  Scaleform::GFx::AS2::TextFieldObject *v1; // rbx

  v1 = this;
  if ( this->pIMECompositionStringStyles )
    return v1->pIMECompositionStringStyles;
  while ( 1 )
  {
    v1 = (Scaleform::GFx::AS2::TextFieldObject *)v1->pProto.pObject;
    if ( !v1
      || (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v1->vfptr->gap8[8])(&v1->vfptr) != 13 )
    {
      break;
    }
    if ( v1->pIMECompositionStringStyles )
      return v1->pIMECompositionStringStyles;
  }
  return 0i64;
}

// File Line: 2662
// RVA: 0x714750
void __fastcall Scaleform::GFx::AS2::TextFieldObject::SetIMECompositionStringStyles(Scaleform::GFx::AS2::TextFieldObject *this, Scaleform::GFx::Text::IMEStyle *imeStyles)
{
  Scaleform::GFx::Text::IMEStyle *v2; // rbx
  Scaleform::GFx::AS2::TextFieldObject *v3; // rdi
  Scaleform::GFx::Text::IMEStyle *v4; // rcx
  __int64 v5; // rax
  Scaleform::GFx::Text::IMEStyle *v6; // rdx
  int v7; // [rsp+50h] [rbp+18h]
  __int64 v8; // [rsp+58h] [rbp+20h]

  v2 = imeStyles;
  v3 = this;
  v4 = this->pIMECompositionStringStyles;
  if ( v4 )
  {
    v4->HighlightStyles[0].BackgroundColor.Raw = imeStyles->HighlightStyles[0].BackgroundColor.Raw;
    v4->HighlightStyles[0].TextColor.Raw = imeStyles->HighlightStyles[0].TextColor.Raw;
    v4->HighlightStyles[0].UnderlineColor.Raw = imeStyles->HighlightStyles[0].UnderlineColor.Raw;
    v4->HighlightStyles[0].Flags = imeStyles->HighlightStyles[0].Flags;
    v4->HighlightStyles[1].BackgroundColor.Raw = imeStyles->HighlightStyles[1].BackgroundColor.Raw;
    v4->HighlightStyles[1].TextColor.Raw = imeStyles->HighlightStyles[1].TextColor.Raw;
    v4->HighlightStyles[1].UnderlineColor.Raw = imeStyles->HighlightStyles[1].UnderlineColor.Raw;
    v4->HighlightStyles[1].Flags = imeStyles->HighlightStyles[1].Flags;
    v4->HighlightStyles[2].BackgroundColor.Raw = imeStyles->HighlightStyles[2].BackgroundColor.Raw;
    v4->HighlightStyles[2].TextColor.Raw = imeStyles->HighlightStyles[2].TextColor.Raw;
    v4->HighlightStyles[2].UnderlineColor.Raw = imeStyles->HighlightStyles[2].UnderlineColor.Raw;
    v4->HighlightStyles[2].Flags = imeStyles->HighlightStyles[2].Flags;
    v4->HighlightStyles[3].BackgroundColor.Raw = imeStyles->HighlightStyles[3].BackgroundColor.Raw;
    v4->HighlightStyles[3].TextColor.Raw = imeStyles->HighlightStyles[3].TextColor.Raw;
    v4->HighlightStyles[3].UnderlineColor.Raw = imeStyles->HighlightStyles[3].UnderlineColor.Raw;
    v4->HighlightStyles[3].Flags = imeStyles->HighlightStyles[3].Flags;
    v4->HighlightStyles[4].BackgroundColor.Raw = imeStyles->HighlightStyles[4].BackgroundColor.Raw;
    v4->HighlightStyles[4].TextColor.Raw = imeStyles->HighlightStyles[4].TextColor.Raw;
    v4->HighlightStyles[4].UnderlineColor.Raw = imeStyles->HighlightStyles[4].UnderlineColor.Raw;
    v4->HighlightStyles[4].Flags = imeStyles->HighlightStyles[4].Flags;
    v4->PresenceMask = imeStyles->PresenceMask;
  }
  else
  {
    v7 = 325;
    v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS2::TextFieldObject *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
           Scaleform::Memory::pGlobalHeap,
           v3,
           84i64,
           &v7,
           -2i64);
    v6 = (Scaleform::GFx::Text::IMEStyle *)v5;
    v8 = v5;
    if ( v5 )
    {
      *(_DWORD *)v5 = v2->HighlightStyles[0].BackgroundColor.Raw;
      *(_DWORD *)(v5 + 4) = v2->HighlightStyles[0].TextColor.Raw;
      *(_DWORD *)(v5 + 8) = v2->HighlightStyles[0].UnderlineColor.Raw;
      *(_BYTE *)(v5 + 12) = v2->HighlightStyles[0].Flags;
      *(_DWORD *)(v5 + 16) = v2->HighlightStyles[1].BackgroundColor.Raw;
      *(_DWORD *)(v5 + 20) = v2->HighlightStyles[1].TextColor.Raw;
      *(_DWORD *)(v5 + 24) = v2->HighlightStyles[1].UnderlineColor.Raw;
      *(_BYTE *)(v5 + 28) = v2->HighlightStyles[1].Flags;
      *(_DWORD *)(v5 + 32) = v2->HighlightStyles[2].BackgroundColor.Raw;
      *(_DWORD *)(v5 + 36) = v2->HighlightStyles[2].TextColor.Raw;
      *(_DWORD *)(v5 + 40) = v2->HighlightStyles[2].UnderlineColor.Raw;
      *(_BYTE *)(v5 + 44) = v2->HighlightStyles[2].Flags;
      *(_DWORD *)(v5 + 48) = v2->HighlightStyles[3].BackgroundColor.Raw;
      *(_DWORD *)(v5 + 52) = v2->HighlightStyles[3].TextColor.Raw;
      *(_DWORD *)(v5 + 56) = v2->HighlightStyles[3].UnderlineColor.Raw;
      *(_BYTE *)(v5 + 60) = v2->HighlightStyles[3].Flags;
      *(_DWORD *)(v5 + 64) = v2->HighlightStyles[4].BackgroundColor.Raw;
      *(_DWORD *)(v5 + 68) = v2->HighlightStyles[4].TextColor.Raw;
      *(_DWORD *)(v5 + 72) = v2->HighlightStyles[4].UnderlineColor.Raw;
      *(_BYTE *)(v5 + 76) = v2->HighlightStyles[4].Flags;
      *(_BYTE *)(v5 + 80) = v2->PresenceMask;
    }
    else
    {
      v6 = 0i64;
    }
    v3->pIMECompositionStringStyles = v6;
  }
}

// File Line: 2715
// RVA: 0x6CC190
void __fastcall Scaleform::GFx::AS2::TextFieldProto::TextFieldProto(Scaleform::GFx::AS2::TextFieldProto *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::AS2::Object *prototype, Scaleform::GFx::AS2::FunctionRef *constructor)
{
  Scaleform::GFx::AS2::ASStringContext *v4; // rbx
  Scaleform::GFx::AS2::TextFieldProto *v5; // rsi
  signed __int64 v6; // rdi
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
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
  Scaleform::GFx::AS2::PropFlags flags; // [rsp+30h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+38h] [rbp-38h]
  __int64 v72; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value v73; // [rsp+48h] [rbp-28h]

  v72 = -2i64;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment>(
    (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::TextFieldObject,Scaleform::GFx::AS2::Environment> *)&this->vfptr,
    psc,
    prototype,
    constructor);
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v6 = (signed __int64)&v5->vfptr;
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v5->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::TextFieldProto::`vftable;
  if ( v5 != (Scaleform::GFx::AS2::TextFieldProto *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      v4,
      GAS_AsBcFunctionTable,
      1);
  flags.Flags = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v5->vfptr,
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    GAS_TextFieldFunctionTable,
    &flags);
  flags.Flags = 2;
  v73.T.Type = 10;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "scroll");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v7,
    &v73,
    &flags);
  v8 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v10 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "hscroll");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v10,
    &v73,
    &flags);
  v11 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v12 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "maxscroll");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v12,
    &v73,
    &flags);
  v13 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v14 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "maxhscroll");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v14,
    &v73,
    &flags);
  v15 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "background");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v16,
    &v73,
    &flags);
  v17 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "backgroundColor");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v18,
    &v73,
    &flags);
  v19 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v20 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "border");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v20,
    &v73,
    &flags);
  v21 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v21->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v22 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "borderColor");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v22,
    &v73,
    &flags);
  v23 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v23->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "bottomScroll");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v24,
    &v73,
    &flags);
  v25 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v25->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v26 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "mouseWheelEnabled");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v26,
    &v73,
    &flags);
  v27 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v27->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v28 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "antiAliasType");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v28,
    &v73,
    &flags);
  v29 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v29->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "autoSize");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v30,
    &v73,
    &flags);
  v31 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v31->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v32 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "condenseWhite");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v32,
    &v73,
    &flags);
  v33 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v33->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v34 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "embedFonts");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v34,
    &v73,
    &flags);
  v35 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v35->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v36 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "html");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v36,
    &v73,
    &flags);
  v37 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v37->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v38 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "htmlText");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v38,
    &v73,
    &flags);
  v39 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v39->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v40 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "length");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v40,
    &v73,
    &flags);
  v41 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v41->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v42 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "maxChars");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v42,
    &v73,
    &flags);
  v43 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v43->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "multiline");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v44,
    &v73,
    &flags);
  v45 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v45->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v46 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "password");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v46,
    &v73,
    &flags);
  v47 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v47->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 1;
  v48 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "restrict");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v48,
    &v73,
    &flags);
  v49 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v49->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v50 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "selectable");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v50,
    &v73,
    &flags);
  v51 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v51->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v52 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "styleSheet");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v52,
    &v73,
    &flags);
  v53 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v53->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v54 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "tabIndex");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v54,
    &v73,
    &flags);
  v55 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v55->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v55);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v56 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "text");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v56,
    &v73,
    &flags);
  v57 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v57->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v58 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "textColor");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v58,
    &v73,
    &flags);
  v59 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v59->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v59);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v60 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "textHeight");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v60,
    &v73,
    &flags);
  v61 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v61->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v61);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v62 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "textWidth");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v62,
    &v73,
    &flags);
  v63 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v63->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v63);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v64 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "type");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v64,
    &v73,
    &flags);
  v65 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v65->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v65);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v66 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "variable");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v66,
    &v73,
    &flags);
  v67 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v67->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v67);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 2;
  v73.T.Type = 10;
  v68 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "wordWrap");
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v68,
    &v73,
    &flags);
  v69 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v69->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v69);
  if ( v73.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v73);
  flags.Flags = 1;
  Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
    (Scaleform::GFx::AS2::GASPrototypeBase *)&v5->vfptr,
    (Scaleform::GFx::AS2::Object *)&v5->vfptr,
    v4,
    GAS_TextFieldExtFunctionTable,
    &flags);
}alue *, Scaleform::GFx::AS2::PropFlags *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v68,
    &v73,
    &flags);
  v69 = result.pNode;
  v9 = result.pNode->RefCount == 1;
  --v69->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v69);
  if ( v73.T.Type >= 5u )


// File Line: 2777
// RVA: 0x6CBE80
void __fastcall Scaleform::GFx::AS2::TextFieldCtorFunction::TextFieldCtorFunction(Scaleform::GFx::AS2::TextFieldCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // rdi
  Scaleform::GFx::AS2::TextFieldCtorFunction *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax

  v2 = psc;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, psc);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v3->pFunction = (void (__fastcall *)(Scaleform::GFx::AS2::FnCall *))_;
  v4 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__((Scaleform::GFx::AS2::Object *)&v3->vfptr, v2, v4);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::TextFieldCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::TextFieldCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    GAS_TextFieldStaticFunctionTable,
    7);
}

// File Line: 2784
// RVA: 0x6E08C0
void __fastcall Scaleform::GFx::AS2::TextFieldCtorFunction::CreateNewObject(Scaleform::GFx::AS2::TextFieldCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::TextFieldObject *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::TextFieldObject *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::TextFieldCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                 this,
                                                 112i64);
  if ( v3 )
    Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(v3, v2);
}

// File Line: 2795
// RVA: 0x70F0E0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::TextFieldCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::TextFieldCtorFunction *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::TextFieldProto *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rbx
  Scaleform::GFx::AS2::Object *v10; // r14
  Scaleform::GFx::ASStringNode *v11; // rax
  Scaleform::GFx::AS2::LocalFrame *v12; // rdx
  unsigned int v13; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value v16; // [rsp+50h] [rbp-20h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+A8h] [rbp+38h]
  void *v18; // [rsp+B0h] [rbp+40h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v19; // [rsp+B8h] [rbp+48h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::TextFieldCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64))objproto.pObject->vfptr[3].Finalize_GC)(
                                                       result,
                                                       104i64);
  v18 = v4;
  if ( v4 )
    Scaleform::GFx::AS2::TextFieldCtorFunction::TextFieldCtorFunction(v4, &psc);
  v3->Flags = 0;
  v3->Function = (Scaleform::GFx::AS2::FunctionObject *)&v4->vfptr;
  v3->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v2->pHeap;
  v6 = (Scaleform::GFx::AS2::TextFieldProto *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(
                                                v5,
                                                176i64,
                                                0i64);
  v18 = v6;
  if ( v6 )
  {
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::TextFieldProto::TextFieldProto(v6, &psc, v7, v3);
    v9 = v8;
  }
  else
  {
    v9 = 0i64;
  }
  v18 = v9;
  v19 = &objproto;
  if ( v9 )
    v9->RefCount = (v9->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v9;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_TextField,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v10 = v2->pGlobal.pObject;
  v16.T.Type = 8;
  v16.V.FunctionValue.Flags = 0;
  v11 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v16.V.pStringNode = v11;
  if ( v11 )
  {
    ++v11->RefCount;
    v11->RefCount &= 0x8FFFFFFF;
  }
  v16.V.FunctionValue.pLocalFrame = 0i64;
  v12 = v3->pLocalFrame;
  if ( v12 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v16.NV.8,
      v12,
      v3->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v10->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v10->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[9].AVMVersion,
    &v16,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v16.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v16);
  if ( v9 )
  {
    v13 = v9->RefCount;
    if ( v13 & 0x3FFFFFF )
    {
      v9->RefCount = v13 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
    }
  }
  return v3;
}

// File Line: 2811
// RVA: 0x6AA2D0
void __fastcall Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::InteractiveObject *v2; // rdx
  Scaleform::GFx::StateBag *v3; // rbx
  __int64 v4; // rcx
  Scaleform::GFx::StateBag *v5; // rdi
  Scaleform::GFx::FontLib *v6; // rbx
  Scaleform::GFx::FontProvider *v7; // rbx
  Scaleform::GFx::FontProvider *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rax
  __int64 v10; // rax
  __int64 v11; // r15
  unsigned __int64 v12; // rcx
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v13; // rdx
  __int64 v14; // rbx
  __int64 v15; // r13
  __int64 v16; // rax
  Scaleform::GFx::ASString *v17; // rax
  char v18; // r12
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::AS2::Value *v21; // rax
  __int64 v22; // rax
  __int64 v23; // r14
  unsigned __int64 v24; // rax
  unsigned __int64 v25; // rsi
  unsigned __int64 v26; // r8
  _QWORD *v27; // rcx
  unsigned __int64 v28; // rcx
  _QWORD *v29; // rax
  int v30; // eax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v31; // rdx
  __int64 v32; // rdi
  unsigned __int64 v33; // r14
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v34; // rbx
  __m128i v35; // [rsp+20h] [rbp-59h]
  Scaleform::GFx::ASString v36; // [rsp+30h] [rbp-49h]
  void **v37; // [rsp+38h] [rbp-41h]
  Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *v38; // [rsp+40h] [rbp-39h]
  Scaleform::Ptr<Scaleform::GFx::FontProvider> v39; // [rsp+48h] [rbp-31h]
  Scaleform::GFx::AS2::Value v; // [rsp+50h] [rbp-29h]
  __int64 v41; // [rsp+70h] [rbp-9h]
  __int64 v42; // [rsp+78h] [rbp-1h]
  __int64 v43; // [rsp+80h] [rbp+7h]
  Scaleform::GFx::AS2::FnCall *v44; // [rsp+E0h] [rbp+67h]
  Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *v45; // [rsp+E8h] [rbp+6Fh]
  Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > fontnames; // [rsp+F0h] [rbp+77h]
  Scaleform::Ptr<Scaleform::GFx::FontLib> result; // [rsp+F8h] [rbp+7Fh]

  v44 = fn;
  v43 = -2i64;
  v1 = fn;
  v2 = fn->Env->Target;
  v3 = (Scaleform::GFx::StateBag *)v2->pASRoot->pMovieImpl;
  v4 = ((__int64 (__fastcall *)(Scaleform::GFx::MovieImpl *))v3->vfptr->~StateBag)(v2->pASRoot->pMovieImpl);
  v45 = &fontnames;
  fontnames.mHash.pTable = 0i64;
  v37 = (void **)`Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList::`2::FontsVisitor::`vftable;
  v38 = &fontnames;
  (*(void (__fastcall **)(__int64, void ***, signed __int64))(*(_QWORD *)v4 + 208i64))(v4, &v37, 1i64);
  v5 = v3 + 2;
  v6 = Scaleform::GFx::StateBag::GetFontLib(v3 + 2, &result)->pObject;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)result.pObject);
  if ( v6 )
    Scaleform::GFx::FontLib::LoadFontNames(v6, &fontnames);
  v7 = Scaleform::GFx::StateBag::GetFontProvider(v5, &v39)->pObject;
  v8 = v39.pObject;
  if ( v39.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v39.pObject);
  if ( v7 )
    v7->vfptr[2].__vecDelDtor((Scaleform::RefCountImplCore *)&v7->vfptr, (unsigned int)&fontnames);
  v45 = (Scaleform::StringHash<Scaleform::String,Scaleform::AllocatorGH<Scaleform::String,2> > *)v1->Env->StringContext.pContext->pHeap;
  v9 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::FontProvider *, signed __int64, _QWORD))v45->mHash.pTable[5].EntryCount)(
                                         v8,
                                         144i64,
                                         0i64);
  v36.pNode = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS2::ArrayObject::ArrayObject((Scaleform::GFx::AS2::ArrayObject *)v9, v1->Env);
    v11 = v10;
  }
  else
  {
    v11 = 0i64;
  }
  v41 = v11;
  if ( fontnames.mHash.pTable )
  {
    v12 = 0i64;
    v13 = fontnames.mHash.pTable + 1;
    do
    {
      if ( v13->EntryCount != -2i64 )
        break;
      ++v12;
      v13 += 2;
    }
    while ( v12 <= fontnames.mHash.pTable->SizeMask );
    v35.m128i_i64[0] = (__int64)&fontnames;
    v35.m128i_i64[1] = v12;
  }
  else
  {
    v35 = 0ui64;
  }
  _mm_store_si128(&v35, v35);
  v14 = v35.m128i_i64[1];
  v15 = v35.m128i_i64[0];
  while ( v15 )
  {
    v16 = *(_QWORD *)v15;
    if ( !*(_QWORD *)v15 || v14 > *(_QWORD *)(v16 + 8) )
      break;
    v17 = Scaleform::GFx::AS2::Environment::CreateString(v1->Env, &v36, (Scaleform::String *)(v16 + 32 * (v14 + 1)));
    v18 = 5;
    v.T.Type = 5;
    v.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v17->pNode;
    ++v.V.pStringNode->RefCount;
    v19 = v36.pNode;
    v20 = v36.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    v42 = v11;
    LODWORD(v45) = 323;
    v21 = (Scaleform::GFx::AS2::Value *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                          Scaleform::Memory::pGlobalHeap,
                                          (const void *)v11,
                                          32ui64,
                                          (Scaleform::AllocInfo *)&v45);
    v35.m128i_i64[0] = (__int64)v21;
    if ( v21 )
    {
      Scaleform::GFx::AS2::Value::Value(v21, &v);
      v23 = v22;
      v18 = v.T.Type;
    }
    else
    {
      v23 = 0i64;
    }
    v24 = *(_QWORD *)(v11 + 112);
    v25 = v24 + 1;
    if ( v24 + 1 >= v24 )
    {
      if ( v25 <= *(_QWORD *)(v11 + 120) )
        goto LABEL_33;
      v26 = v25 + (v25 >> 2);
    }
    else
    {
      if ( v25 >= *(_QWORD *)(v11 + 120) >> 1 )
        goto LABEL_33;
      v26 = v24 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)(v11 + 104),
      (const void *)(v11 + 104),
      v26);
LABEL_33:
    *(_QWORD *)(v11 + 112) = v25;
    v27 = (_QWORD *)(*(_QWORD *)(v11 + 104) + 8 * (v25 - 1));
    if ( v27 )
      *v27 = v23;
    if ( (unsigned __int8)v18 >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v);
    v28 = *(_QWORD *)(*(_QWORD *)v15 + 8i64);
    v1 = v44;
    if ( v14 <= (signed __int64)v28 && ++v14 <= v28 )
    {
      v29 = (_QWORD *)(*(_QWORD *)v15 + 32 * v14 + 16);
      do
      {
        v1 = v44;
        if ( *v29 != -2i64 )
          break;
        ++v14;
        v29 += 4;
      }
      while ( v14 <= v28 );
    }
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, (Scaleform::GFx::AS2::Object *)v11);
  if ( v11 )
  {
    v30 = *(_DWORD *)(v11 + 24);
    if ( v30 & 0x3FFFFFF )
    {
      *(_DWORD *)(v11 + 24) = v30 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v11);
    }
  }
  v37 = &Scaleform::GFx::MovieDef::ResourceVisitor::`vftable;
  v31 = fontnames.mHash.pTable;
  if ( fontnames.mHash.pTable )
  {
    v32 = 0i64;
    v33 = fontnames.mHash.pTable->SizeMask + 1;
    do
    {
      v34 = &v31[v32];
      if ( v31[v32 + 1].EntryCount != -2i64 )
      {
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v34[2].SizeMask & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        if ( !_InterlockedDecrement((volatile signed __int32 *)((v34[2].EntryCount & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
          ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
        v34[1].EntryCount = -2i64;
        v31 = fontnames.mHash.pTable;
      }
      v32 += 2i64;
      --v33;
    }
    while ( v33 );
    if ( v31 )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 2826
// RVA: 0x7236A0
void __fastcall Scaleform::GFx::AS2::TextFieldCtorFunction::GetFontList_::_2_::FontsVisitor::Visit(Scaleform::GFx::MovieDef *__formal, Scaleform::GFx::Resource *presource, __int64 a3, const char *a4)
{
  __int64 v4; // rbx
  Scaleform::GFx::MovieDef *v5; // rdi
  const char *v6; // rax
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *v7; // rcx
  Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+28h] [rbp-20h]
  Scaleform::String v9; // [rsp+60h] [rbp+18h]

  v4 = a3;
  v5 = __formal;
  if ( ((*(__int64 (__fastcall **)(__int64, Scaleform::GFx::Resource *, __int64, const char *, signed __int64))(*(_QWORD *)a3 + 16i64))(
          a3,
          presource,
          a3,
          a4,
          -2i64) & 0xFF00) == 512 )
  {
    v6 = (const char *)(*(__int64 (**)(void))(**(_QWORD **)(v4 + 24) + 8i64))();
    Scaleform::String::String(&v9, v6);
    v7 = *(Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > **)&v5->RefCount.Value;
    key.pFirst = &v9;
    key.pSecond = &v9;
    Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorGH<Scaleform::String,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>,Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::Set<Scaleform::HashNode<Scaleform::String,Scaleform::String,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
      v7,
      v7,
      &key);
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v9.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 2862
// RVA: 0x707E30
Scaleform::Render::Text::HighlightInfo *__fastcall Scaleform::GFx::AS2::TextFieldProto::ParseStyle(Scaleform::Render::Text::HighlightInfo *result, Scaleform::GFx::AS2::FnCall *fn, unsigned int paramIndex, Scaleform::Render::Text::HighlightInfo *initialHInfo)
{
  Scaleform::GFx::AS2::FnCall *v4; // rsi
  Scaleform::Render::Text::HighlightInfo *v5; // rbx
  unsigned int v6; // er9
  Scaleform::GFx::AS2::Environment *v7; // rdx
  __int64 v8; // rdi
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::AS2::Object *v10; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // r14
  Scaleform::GFx::ASString *v12; // rax
  __int64 v13; // r15
  Scaleform::GFx::ASStringNode *v14; // rcx
  const char *v15; // rdx
  __int64 v16; // rax
  char v17; // cl
  bool v18; // zf
  bool v19; // r15
  Scaleform::GFx::ASStringNode *v20; // rcx
  unsigned int v21; // eax
  Scaleform::GFx::ASString *v22; // rax
  __int64 v23; // r15
  Scaleform::GFx::ASStringNode *v24; // rcx
  const char *v25; // rdx
  __int64 v26; // rax
  char v27; // cl
  bool v28; // zf
  bool v29; // r15
  Scaleform::GFx::ASStringNode *v30; // rcx
  unsigned int v31; // eax
  Scaleform::GFx::ASString *v32; // rax
  __int64 v33; // r15
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
  unsigned int v52; // eax
  Scaleform::GFx::AS2::Value v54; // [rsp+28h] [rbp-28h]
  Scaleform::GFx::ASString resulta; // [rsp+90h] [rbp+40h]
  Scaleform::GFx::AS2::Object *v56; // [rsp+98h] [rbp+48h]

  v4 = fn;
  v5 = result;
  result->BackgroundColor.Raw = initialHInfo->BackgroundColor.Raw;
  result->TextColor.Raw = initialHInfo->TextColor.Raw;
  result->UnderlineColor.Raw = initialHInfo->UnderlineColor.Raw;
  result->Flags = initialHInfo->Flags;
  if ( fn->NArgs >= 1 )
  {
    v6 = fn->FirstArgBottomIndex - paramIndex;
    v7 = fn->Env;
    v8 = 0i64;
    v9 = 0i64;
    if ( v6 <= 32 * ((unsigned int)v7->Stack.Pages.Data.Size - 1)
             + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
      v9 = &v7->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    v10 = Scaleform::GFx::AS2::Value::ToObject(v9, v7);
    v11 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v10->vfptr;
    if ( v10 )
      v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
    v56 = v10;
    if ( v10 )
    {
      v54.T.Type = 0;
      v12 = Scaleform::GFx::AS2::Environment::CreateConstString(v4->Env, &resulta, "textColor");
      v13 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, signed __int64))v11[1].vfptr[1].Finalize_GC)(
              &v11[1],
              v4->Env,
              v12,
              &v54,
              -2i64);
      v14 = resulta.pNode;
      v18 = resulta.pNode->RefCount == 1;
      --v14->RefCount;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      if ( (_BYTE)v13 )
      {
        v15 = Scaleform::GFx::AS2::Value::ToString(&v54, &resulta, v4->Env, -1)->pNode->pData;
        v16 = 0i64;
        while ( 1 )
        {
          v17 = v15[v16++];
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
        v18 = resulta.pNode->RefCount == 1;
        --v20->RefCount;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v20);
        if ( v19 )
        {
          v5->Flags &= 0xEFu;
        }
        else
        {
          resulta.pNode = COERCE_SCALEFORM__GFX__ASSTRINGNODE__(Scaleform::GFx::AS2::Value::ToNumber(&v54, v4->Env));
          if ( ((unsigned __int64)resulta.pNode & 0x7FF0000000000000i64) != 9218868437227405312i64 )
          {
            v21 = Scaleform::GFx::AS2::Value::ToUInt32(&v54, v4->Env);
            v5->Flags |= 0x10u;
            v5->TextColor.Raw = v21 | 0xFF000000;
          }
        }
      }
      v22 = Scaleform::GFx::AS2::Environment::CreateConstString(v4->Env, &resulta, "backgroundColor");
      v23 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v11[1].vfptr[1].Finalize_GC)(
              &v11[1],
              v4->Env,
              v22,
              &v54);
      v24 = resulta.pNode;
      v18 = resulta.pNode->RefCount == 1;
      --v24->RefCount;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( (_BYTE)v23 )
      {
        v25 = Scaleform::GFx::AS2::Value::ToString(&v54, &resulta, v4->Env, -1)->pNode->pData;
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
        v18 = resulta.pNode->RefCount == 1;
        --v30->RefCount;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v30);
        if ( v29 )
        {
          v5->Flags &= 0xF7u;
        }
        else
        {
          resulta.pNode = COERCE_SCALEFORM__GFX__ASSTRINGNODE__(Scaleform::GFx::AS2::Value::ToNumber(&v54, v4->Env));
          if ( ((unsigned __int64)resulta.pNode & 0x7FF0000000000000i64) != 9218868437227405312i64 )
          {
            v31 = Scaleform::GFx::AS2::Value::ToUInt32(&v54, v4->Env);
            v5->Flags |= 8u;
            v5->BackgroundColor.Raw = v31 | 0xFF000000;
          }
        }
      }
      v32 = Scaleform::GFx::AS2::Environment::CreateConstString(v4->Env, &resulta, "underlineColor");
      v33 = ((unsigned __int8 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v11[1].vfptr[1].Finalize_GC)(
              &v11[1],
              v4->Env,
              v32,
              &v54);
      v34 = resulta.pNode;
      v18 = resulta.pNode->RefCount == 1;
      --v34->RefCount;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v34);
      if ( (_BYTE)v33 )
      {
        v35 = Scaleform::GFx::AS2::Value::ToString(&v54, &resulta, v4->Env, -1)->pNode->pData;
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
        v18 = resulta.pNode->RefCount == 1;
        --v40->RefCount;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v40);
        if ( v39 )
        {
          v5->Flags &= 0xDFu;
        }
        else
        {
          resulta.pNode = COERCE_SCALEFORM__GFX__ASSTRINGNODE__(Scaleform::GFx::AS2::Value::ToNumber(&v54, v4->Env));
          if ( ((unsigned __int64)resulta.pNode & 0x7FF0000000000000i64) != 9218868437227405312i64 )
          {
            v41 = Scaleform::GFx::AS2::Value::ToUInt32(&v54, v4->Env);
            v5->Flags |= 0x20u;
            v5->UnderlineColor.Raw = v41 | 0xFF000000;
          }
        }
      }
      v42 = Scaleform::GFx::AS2::Environment::CreateConstString(v4->Env, &resulta, "underlineStyle");
      v43 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))v11[1].vfptr[1].Finalize_GC)(
              &v11[1],
              v4->Env,
              v42,
              &v54);
      v44 = resulta.pNode;
      v18 = resulta.pNode->RefCount == 1;
      --v44->RefCount;
      if ( v18 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v44);
      if ( v43 )
      {
        Scaleform::GFx::AS2::Value::ToString(&v54, &resulta, v4->Env, -1);
        v45 = resulta.pNode->pData;
        v46 = 0i64;
        while ( 1 )
        {
          v47 = v45[v46++];
          if ( v47 != aDotted[v46 - 1] )
            break;
          if ( v46 == 7 )
          {
            v5->Flags &= 0xFBu;
            v5->Flags |= 3u;
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
            v5->Flags &= 0xF9u;
            v5->Flags |= 1u;
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
            v5->Flags &= 0xFAu;
            v5->Flags |= 2u;
            goto LABEL_65;
          }
        }
        if ( !strcmp(resulta.pNode->pData, "ditheredSingle") )
        {
          v5->Flags &= 0xFDu;
          v5->Flags |= 5u;
        }
        else if ( !strcmp(v45, "ditheredThick") )
        {
          v5->Flags &= 0xFEu;
          v5->Flags |= 6u;
        }
        else
        {
          v5->Flags &= 0xF8u;
        }
LABEL_65:
        v51 = resulta.pNode;
        v18 = resulta.pNode->RefCount == 1;
        --v51->RefCount;
        if ( v18 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v51);
      }
      if ( v54.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v54);
    }
    if ( v11 )
    {
      v52 = v11->RefCount;
      if ( v52 & 0x3FFFFFF )
      {
        v11->RefCount = v52 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
  }
  return v5;
}

// File Line: 2925
// RVA: 0x702D50
void __fastcall Scaleform::GFx::AS2::TextFieldProto::MakeStyle(Scaleform::GFx::AS2::FnCall *fn, Scaleform::Render::Text::HighlightInfo *hinfo)
{
  Scaleform::Render::Text::HighlightInfo *v2; // r14
  Scaleform::GFx::AS2::FnCall *v3; // r15
  Scaleform::GFx::ASStringNode *v4; // rax
  Scaleform::GFx::AS2::Object *v5; // rax
  Scaleform::GFx::AS2::Object *v6; // rsi
  char v7; // al
  const char *v8; // r8
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::AS2::Environment *v10; // rdi
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  int v15; // ecx
  Scaleform::GFx::AS2::Environment *v16; // rdi
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  int v19; // ecx
  Scaleform::GFx::AS2::Environment *v20; // rdi
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *v22; // rcx
  int v23; // ecx
  Scaleform::GFx::AS2::Environment *v24; // rdi
  Scaleform::GFx::ASString *v25; // rax
  Scaleform::GFx::ASStringNode *v26; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::AS2::Value v28; // [rsp+38h] [rbp-30h]
  Scaleform::MemoryHeap *v29; // [rsp+A0h] [rbp+38h]
  Scaleform::GFx::ASString v30; // [rsp+A8h] [rbp+40h]
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp+48h]
  Scaleform::GFx::AS2::Object *v32; // [rsp+B8h] [rbp+50h]

  v2 = hinfo;
  v3 = fn;
  v29 = fn->Env->StringContext.pContext->pHeap;
  v4 = (Scaleform::GFx::ASStringNode *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FnCall *, signed __int64))v29->vfptr->Alloc)(
                                         fn,
                                         96i64);
  v30.pNode = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v4, v3->Env);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  v32 = v6;
  v7 = v2->Flags;
  if ( v7 & 7 )
  {
    switch ( v7 & 7 )
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
    v9 = Scaleform::GFx::AS2::Environment::CreateConstString(v3->Env, &result, v8);
    v28.T.Type = 5;
    v28.NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v9->pNode;
    ++v28.V.pStringNode->RefCount;
    v10 = v3->Env;
    v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v10->StringContext, &v30, "underlineStyle");
    LOBYTE(v29) = 0;
    v6->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
      &v10->StringContext,
      v11,
      &v28,
      (Scaleform::GFx::AS2::PropFlags *)&v29);
    v12 = v30.pNode;
    v13 = v30.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    if ( v28.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v28);
    v14 = result.pNode;
    v13 = result.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  }
LABEL_21:
  if ( v2->Flags & 0x20 )
  {
    v15 = v2->UnderlineColor.Raw & 0xFFFFFF;
    v28.T.Type = 3;
    v28.NV.NumberValue = (double)v15;
    v16 = v3->Env;
    v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v16->StringContext, &v30, "underlineColor");
    LOBYTE(v29) = 0;
    v6->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
      &v16->StringContext,
      v17,
      &v28,
      (Scaleform::GFx::AS2::PropFlags *)&v29);
    v18 = v30.pNode;
    v13 = v30.pNode->RefCount == 1;
    --v18->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v18);
    if ( v28.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v28);
  }
  if ( v2->Flags & 8 )
  {
    v19 = v2->BackgroundColor.Raw & 0xFFFFFF;
    v28.T.Type = 3;
    v28.NV.NumberValue = (double)v19;
    v20 = v3->Env;
    v21 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v20->StringContext, &v30, "backgroundColor");
    LOBYTE(v29) = 0;
    v6->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
      &v20->StringContext,
      v21,
      &v28,
      (Scaleform::GFx::AS2::PropFlags *)&v29);
    v22 = v30.pNode;
    v13 = v30.pNode->RefCount == 1;
    --v22->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v22);
    if ( v28.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v28);
  }
  if ( v2->Flags & 0x10 )
  {
    v23 = v2->TextColor.Raw & 0xFFFFFF;
    v28.T.Type = 3;
    v28.NV.NumberValue = (double)v23;
    v24 = v3->Env;
    v25 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(&v24->StringContext, &v30, "textColor");
    LOBYTE(v29) = 0;
    v6->vfptr->SetMemberRaw(
      (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
      &v24->StringContext,
      v25,
      &v28,
      (Scaleform::GFx::AS2::PropFlags *)&v29);
    v26 = v30.pNode;
    v13 = v30.pNode->RefCount == 1;
    --v26->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v26);
    if ( v28.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v28);
  }
  Scaleform::GFx::AS2::Value::SetAsObject(v3->Result, v6);
  if ( v6 )
  {
    v27 = v6->RefCount;
    if ( v27 & 0x3FFFFFF )
    {
      v6->RefCount = v27 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
}

// File Line: 2961
// RVA: 0x6EDB10
int __fastcall Scaleform::GFx::AS2::GFx_StringToIMEStyleCategory(Scaleform::GFx::ASString *categoryStr)
{
  Scaleform::GFx::Text::IMEStyle::Category v1; // edi
  const char *v2; // rbx
  int result; // eax

  v1 = 5;
  v2 = categoryStr->pNode->pData;
  result = strcmp(categoryStr->pNode->pData, "compositionSegment");
  if ( result )
  {
    if ( !strcmp(v2, "clauseSegment") )
    {
      result = 1;
    }
    else if ( !strcmp(v2, "convertedSegment") )
    {
      result = 2;
    }
    else if ( !strcmp(v2, "phraseLengthAdj") )
    {
      result = 3;
    }
    else
    {
      if ( !strcmp(v2, "lowConfSegment") )
        v1 = 4;
      result = v1;
    }
  }
  return result;
}

// File Line: 2977
// RVA: 0x6A9510
void __fastcall Scaleform::GFx::AS2::TextFieldProto::SetIMECompositionStringStyle(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // r15
  Scaleform::GFx::AS2::TextFieldObject *v2; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rax
  Scaleform::GFx::AS2::AvmTextField *v4; // rcx
  Scaleform::GFx::AS2::TextFieldObject *v5; // rax
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  unsigned int v7; // er9
  Scaleform::GFx::AS2::Environment *v8; // r8
  Scaleform::GFx::AS2::Value *v9; // r10
  Scaleform::GFx::Text::IMEStyle::Category v10; // eax
  __int64 v11; // rdi
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::Text::IMEStyle *v14; // rax
  char v15; // r12
  Scaleform::Render::Text::HighlightInfo *v16; // r14
  Scaleform::Render::Text::HighlightInfo *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  unsigned int v19; // eax
  Scaleform::Render::Text::HighlightInfo v20; // [rsp+8h] [rbp-41h]
  Scaleform::GFx::Text::IMEStyle imeStyles; // [rsp+20h] [rbp-29h]
  Scaleform::GFx::ASString result; // [rsp+B0h] [rbp+67h]
  Scaleform::GFx::AS2::TextFieldObject *v23; // [rsp+B8h] [rbp+6Fh]

  v1 = fn;
  if ( fn->ThisPtr )
  {
    v2 = 0i64;
    v23 = 0i64;
    if ( (*(unsigned int (**)(void))&fn->ThisPtr->vfptr->gap8[8])() == 4 )
    {
      v3 = v1->ThisPtr;
      v4 = (Scaleform::GFx::AS2::AvmTextField *)&v3[-1].pProto;
      if ( !v3 )
        v4 = 0i64;
      v5 = Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(v4);
      v2 = v5;
      if ( v5 )
        v5->RefCount = (v5->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      if ( (*(unsigned int (**)(void))&v1->ThisPtr->vfptr->gap8[8])() != 13 )
        goto LABEL_24;
      v6 = v1->ThisPtr;
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
    if ( v2 && v1->NArgs >= 1 )
    {
      v7 = v1->FirstArgBottomIndex;
      v8 = v1->Env;
      v9 = 0i64;
      if ( v7 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
               + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v9 = &v8->Stack.Pages.Data.Data[v7 >> 5]->Values[v7 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v9, &result, v8, -1);
      v10 = Scaleform::GFx::AS2::GFx_StringToIMEStyleCategory(&result);
      v11 = v10;
      if ( (signed int)v10 >= 5 )
      {
        v12 = result.pNode;
        v13 = result.pNode->RefCount == 1;
        --v12->RefCount;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
LABEL_25:
        v19 = v2->RefCount;
        if ( v19 & 0x3FFFFFF )
        {
          v2->RefCount = v19 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->vfptr);
        }
        return;
      }
      v14 = Scaleform::GFx::AS2::TextFieldObject::GetIMECompositionStringStyles(v2);
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
      v15 = 0;
      imeStyles.PresenceMask = 0;
      if ( v14 )
      {
        imeStyles.HighlightStyles[0].BackgroundColor.Raw = v14->HighlightStyles[0].BackgroundColor.Raw;
        imeStyles.HighlightStyles[0].TextColor.Raw = v14->HighlightStyles[0].TextColor.Raw;
        imeStyles.HighlightStyles[0].UnderlineColor.Raw = v14->HighlightStyles[0].UnderlineColor.Raw;
        imeStyles.HighlightStyles[0].Flags = v14->HighlightStyles[0].Flags;
        imeStyles.HighlightStyles[1].BackgroundColor.Raw = v14->HighlightStyles[1].BackgroundColor.Raw;
        imeStyles.HighlightStyles[1].TextColor.Raw = v14->HighlightStyles[1].TextColor.Raw;
        imeStyles.HighlightStyles[1].UnderlineColor.Raw = v14->HighlightStyles[1].UnderlineColor.Raw;
        imeStyles.HighlightStyles[1].Flags = v14->HighlightStyles[1].Flags;
        imeStyles.HighlightStyles[2].BackgroundColor.Raw = v14->HighlightStyles[2].BackgroundColor.Raw;
        imeStyles.HighlightStyles[2].TextColor.Raw = v14->HighlightStyles[2].TextColor.Raw;
        imeStyles.HighlightStyles[2].UnderlineColor.Raw = v14->HighlightStyles[2].UnderlineColor.Raw;
        imeStyles.HighlightStyles[2].Flags = v14->HighlightStyles[2].Flags;
        imeStyles.HighlightStyles[3].BackgroundColor.Raw = v14->HighlightStyles[3].BackgroundColor.Raw;
        imeStyles.HighlightStyles[3].TextColor.Raw = v14->HighlightStyles[3].TextColor.Raw;
        imeStyles.HighlightStyles[3].UnderlineColor.Raw = v14->HighlightStyles[3].UnderlineColor.Raw;
        imeStyles.HighlightStyles[3].Flags = v14->HighlightStyles[3].Flags;
        imeStyles.HighlightStyles[4].BackgroundColor.Raw = v14->HighlightStyles[4].BackgroundColor.Raw;
        imeStyles.HighlightStyles[4].TextColor.Raw = v14->HighlightStyles[4].TextColor.Raw;
        imeStyles.HighlightStyles[4].UnderlineColor.Raw = v14->HighlightStyles[4].UnderlineColor.Raw;
        imeStyles.HighlightStyles[4].Flags = v14->HighlightStyles[4].Flags;
        v15 = v14->PresenceMask;
        imeStyles.PresenceMask = v14->PresenceMask;
      }
      v16 = &imeStyles.HighlightStyles[v11];
      v17 = Scaleform::GFx::AS2::TextFieldProto::ParseStyle(&v20, v1, 1u, v16);
      imeStyles.PresenceMask = (1 << v11) | v15;
      v16->BackgroundColor.Raw = v17->BackgroundColor.Raw;
      v16->TextColor.Raw = v17->TextColor.Raw;
      v16->UnderlineColor.Raw = v17->UnderlineColor.Raw;
      v16->Flags = v17->Flags;
      Scaleform::GFx::AS2::TextFieldObject::SetIMECompositionStringStyles(v2, &imeStyles);
      v18 = result.pNode;
      v13 = result.pNode->RefCount == 1;
      --v18->RefCount;
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
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::Value *v3; // rsi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v5; // rax
  Scaleform::GFx::AS2::AvmTextField *v6; // rcx
  Scaleform::GFx::AS2::TextFieldObject *v7; // rax
  Scaleform::GFx::AS2::ObjectInterface *v8; // rbx
  Scaleform::GFx::Text::IMEStyle *v9; // rbp
  Scaleform::GFx::AS2::TextFieldObject *v10; // rbp
  unsigned int v11; // er9
  Scaleform::GFx::AS2::Environment *v12; // r8
  Scaleform::GFx::Text::IMEStyle::Category v13; // eax
  Scaleform::GFx::ASStringNode *v14; // rcx
  bool v15; // zf
  Scaleform::GFx::ASStringNode *v16; // rcx
  unsigned int v17; // eax
  Scaleform::GFx::ASString result; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v19; // [rsp+58h] [rbp+10h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 0;
  if ( v1->ThisPtr )
  {
    v3 = 0i64;
    v4 = 0i64;
    v19 = 0i64;
    if ( (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->ThisPtr->vfptr->gap8[8])(v1->ThisPtr) == 4 )
    {
      v5 = v1->ThisPtr;
      v6 = (Scaleform::GFx::AS2::AvmTextField *)&v5[-1].pProto;
      if ( !v5 )
        v6 = 0i64;
      v7 = Scaleform::GFx::AS2::AvmTextField::GetTextFieldASObject(v6);
      v4 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v7->vfptr;
      if ( v7 )
        v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    }
    else
    {
      if ( (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->ThisPtr->vfptr->gap8[8])(v1->ThisPtr) != 13 )
        goto LABEL_25;
      v8 = v1->ThisPtr;
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
      v9 = (Scaleform::GFx::Text::IMEStyle *)v4[3].pRCC;
      if ( v9
        || (v10 = (Scaleform::GFx::AS2::TextFieldObject *)v4[1].pRCC) != 0i64
        && (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **))&v10->vfptr->gap8[8])(&v10->vfptr) == 13
        && (v9 = Scaleform::GFx::AS2::TextFieldObject::GetIMECompositionStringStyles(v10)) != 0i64 )
      {
        v11 = v1->FirstArgBottomIndex;
        v12 = v1->Env;
        if ( v11 <= 32 * ((unsigned int)v12->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
          v3 = &v12->Stack.Pages.Data.Data[v11 >> 5]->Values[v11 & 0x1F];
        Scaleform::GFx::AS2::Value::ToString(v3, &result, v12, -1);
        v13 = Scaleform::GFx::AS2::GFx_StringToIMEStyleCategory(&result);
        if ( (signed int)v13 >= 5 )
        {
          v14 = result.pNode;
          v15 = result.pNode->RefCount == 1;
          --v14->RefCount;
          if ( v15 )
            Scaleform::GFx::ASStringNode::ReleaseNode(v14);
LABEL_26:
          v17 = v4->RefCount;
          if ( v17 & 0x3FFFFFF )
          {
            v4->RefCount = v17 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
          }
          return;
        }
        Scaleform::GFx::AS2::TextFieldProto::MakeStyle(v1, &v9->HighlightStyles[v13]);
        v16 = result.pNode;
        v15 = result.pNode->RefCount == 1;
        --v16->RefCount;
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

