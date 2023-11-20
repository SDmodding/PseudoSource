// File Line: 66
// RVA: 0x6C9730
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::KeyCtorFunction(Scaleform::GFx::AS2::KeyCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc, Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::GFx::MovieImpl *v3; // r14
  Scaleform::GFx::AS2::ASStringContext *v4; // rdi
  Scaleform::GFx::AS2::KeyCtorFunction *v5; // rsi
  signed __int64 v6; // rbx
  signed __int64 v7; // rax
  signed int v8; // ecx
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  bool v11; // zf
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
  Scaleform::GFx::AS2::Value v46; // [rsp+38h] [rbp-28h]
  char v47; // [rsp+A0h] [rbp+40h]
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+48h]

  v3 = proot;
  v4 = psc;
  v5 = this;
  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
    (Scaleform::GFx::AS2::CFunctionObject *)&this->vfptr,
    psc,
    Scaleform::GFx::AS2::StageCtorFunction::GlobalCtor);
  v5->vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::KeyboardState::IListener::`vftable;
  v5->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::KeyCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v6 = (signed __int64)&v5->vfptr;
  v5->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::KeyCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v5->vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::AS2::KeyCtorFunction::`vftable;
  v7 = (signed __int64)v5->States;
  v8 = 15;
  do
  {
    *(_DWORD *)v7 = 0;
    *(_BYTE *)(v7 + 4) = 0;
    *(_DWORD *)(v7 + 8) = 0;
    v7 += 12i64;
    --v8;
  }
  while ( v8 >= 0 );
  v5->pMovieRoot = v3;
  if ( v5 != (Scaleform::GFx::AS2::KeyCtorFunction *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
      v4,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(v4, (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr);
  v46.T.Type = 4;
  v46.NV.Int32Value = 8;
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "BACKSPACE");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v9,
    &v46,
    &v47);
  v10 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 20;
  v12 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "CAPSLOCK");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v12,
    &v46,
    &v47);
  v13 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 17;
  v14 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "CONTROL");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v14,
    &v46,
    &v47);
  v15 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 46;
  v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "DELETEKEY");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v16,
    &v46,
    &v47);
  v17 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v17->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 40;
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "DOWN");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v18,
    &v46,
    &v47);
  v19 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v19->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 35;
  v20 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "END");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v20,
    &v46,
    &v47);
  v21 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v21->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 13;
  v22 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "ENTER");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v22,
    &v46,
    &v47);
  v23 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v23->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 27;
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "ESCAPE");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v24,
    &v46,
    &v47);
  v25 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v25->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 36;
  v26 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "HOME");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v26,
    &v46,
    &v47);
  v27 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v27->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 45;
  v28 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "INSERT");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v28,
    &v46,
    &v47);
  v29 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v29->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 37;
  v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "LEFT");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v30,
    &v46,
    &v47);
  v31 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v31->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 34;
  v32 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "PGDN");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v32,
    &v46,
    &v47);
  v33 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v33->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 33;
  v34 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "PGUP");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v34,
    &v46,
    &v47);
  v35 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v35->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 39;
  v36 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "RIGHT");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v36,
    &v46,
    &v47);
  v37 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v37->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 16;
  v38 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "SHIFT");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v38,
    &v46,
    &v47);
  v39 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v39->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 32;
  v40 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "SPACE");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v40,
    &v46,
    &v47);
  v41 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v41->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 9;
  v42 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "TAB");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v42,
    &v46,
    &v47);
  v43 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v43->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 38;
  v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v4, &result, "UP");
  v47 = 0;
  (*(void (__fastcall **)(Scaleform::GFx::AS2::ObjectInterfaceVtbl **, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *, char *))(*(_QWORD *)v6 + 80i64))(
    &v5->vfptr,
    v4,
    v44,
    &v46,
    &v47);
  v45 = result.pNode;
  v11 = result.pNode->RefCount == 1;
  --v45->RefCount;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr,
    v4,
    Scaleform::GFx::AS2::KeyCtorFunction::StaticFunctionTable,
    0);
  Scaleform::GFx::MovieImpl::SetKeyboardListener(v3, (Scaleform::GFx::KeyboardState::IListener *)&v5->vfptr);
}

// File Line: 99
// RVA: 0x722EB0
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::Update(Scaleform::GFx::AS2::KeyCtorFunction *this, Scaleform::GFx::EventId *evt)
{
  Scaleform::GFx::EventId *v2; // rbx
  Scaleform::GFx::AS2::KeyCtorFunction *v3; // rdi
  char v4; // al

  v2 = evt;
  v3 = this;
  *((_DWORD *)&this->pRCC + 3 * evt->ControllerIndex) = evt->KeyCode;
  v4 = evt->AsciiCode;
  if ( !v4 )
    v4 = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(evt);
  *((_BYTE *)&v3->vfptr + 12 * (v2->ControllerIndex + 1i64)) = v4;
  *(&v3->RootIndex + 3 * v2->ControllerIndex) = v2->WcharCode;
}

// File Line: 108
// RVA: 0x703540
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::NotifyListeners(Scaleform::GFx::AS2::KeyCtorFunction *this, Scaleform::GFx::InteractiveObject *__formal, Scaleform::GFx::EventId *evt)
{
  Scaleform::GFx::EventId *v3; // rsi
  Scaleform::GFx::AS2::KeyCtorFunction *v4; // r14
  char v5; // al
  unsigned int v6; // edi
  Scaleform::GFx::MovieImpl *v7; // rax
  unsigned int v8; // ecx
  Scaleform::GFx::MovieImpl *v9; // r8
  unsigned __int64 v10; // rdx
  __int64 v11; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v12; // r8
  Scaleform::GFx::InteractiveObject *v13; // rcx
  signed __int64 v14; // rcx
  __int64 v15; // rax
  Scaleform::GFx::AS2::Environment *v16; // rbp
  __int64 v17; // rcx
  int v18; // eax
  unsigned int v19; // er8
  Scaleform::GFx::AS2::Value *v20; // rcx
  Scaleform::GFx::ASStringNode *v21; // rcx
  bool v22; // zf
  Scaleform::GFx::EventId evta; // [rsp+28h] [rbp-40h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]
  __int64 v25; // [rsp+80h] [rbp+18h]
  __int64 v26; // [rsp+88h] [rbp+20h]

  v3 = evt;
  v4 = this;
  this->States[evt->ControllerIndex].LastKeyCode = evt->KeyCode;
  v5 = evt->AsciiCode;
  if ( !v5 )
    v5 = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(evt);
  v4->States[v3->ControllerIndex].LastAsciiCode = v5;
  *((_DWORD *)&v4->vfptr + 3 * (v3->ControllerIndex + 10i64)) = v3->WcharCode;
  evta.Id = LOBYTE(v3->Id);
  v6 = 0;
  *(_QWORD *)&evta.WcharCode = 0i64;
  evta.AsciiCode = 0;
  *(_DWORD *)&evta.RollOverCnt = 65280;
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)&v4->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    &evta);
  v7 = v4->pMovieRoot;
  if ( v7 )
  {
    v8 = 0;
    v9 = v7->pASMovieRoot.pObject->pMovieImpl;
    v10 = v9->MovieLevels.Data.Size;
    if ( v10 )
    {
      v11 = 0i64;
      v12 = v9->MovieLevels.Data.Data;
      while ( v12[v11].Level )
      {
        v11 = ++v8;
        if ( v8 >= v10 )
          goto LABEL_25;
      }
      v13 = v12[v8].pSprite.pObject;
      if ( v13 )
      {
        v14 = (signed __int64)v13 + 4 * (unsigned __int8)v13->AvmObjOffset;
        v15 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v14 + 240i64))(v14);
        v16 = (Scaleform::GFx::AS2::Environment *)v15;
        if ( v15 )
        {
          if ( *(_BYTE *)(*(_QWORD *)(v15 + 232) + 104i64) == 1 )
          {
            *(_QWORD *)(v15 + 8) += 32i64;
            if ( *(_QWORD *)(v15 + 8) >= *(_QWORD *)(v15 + 24) )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage((Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v15 + 8));
            v17 = (__int64)v16->Stack.pCurrent;
            v25 = v17;
            v26 = v17;
            if ( v17 )
            {
              v18 = v3->ControllerIndex;
              *(_BYTE *)v17 = 4;
              *(_DWORD *)(v17 + 8) = v18;
            }
            v6 = 1;
          }
          v19 = ((_QWORD)((char *)v16->Stack.pCurrent - (char *)v16->Stack.pPageStart) >> 5)
              + 32 * v16->Stack.Pages.Data.Size
              - 32;
          if ( v4 != (Scaleform::GFx::AS2::KeyCtorFunction *)-32i64 )
          {
            *(_QWORD *)&evta.Id = `Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
            evta.KeyCode = v6;
            evta.TouchID = v19;
            Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
              v16,
              (Scaleform::GFx::AS2::ObjectInterface *)&v4->vfptr,
              &result,
              (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *)&evta);
            *(_QWORD *)&evta.Id = &Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
          }
          for ( ; v6; --v6 )
          {
            v20 = v16->Stack.pCurrent;
            if ( v20->T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(v20);
            --v16->Stack.pCurrent;
            if ( v16->Stack.pCurrent < v16->Stack.pPageStart )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v16->Stack);
          }
        }
      }
    }
  }
LABEL_25:
  v21 = result.pNode;
  v22 = result.pNode->RefCount == 1;
  --v21->RefCount;
  if ( v22 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
}

// File Line: 377
// RVA: 0x6AC1A0
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::KeyGetAscii(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rax
  Scaleform::GFx::AS2::Value *v2; // r9
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  signed __int64 v4; // rdi
  Scaleform::GFx::AS2::Environment *v5; // rdx
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS2::Value *v7; // rbx
  int v8; // edi

  v1 = fn->ThisPtr;
  v2 = 0i64;
  v3 = fn;
  v4 = (signed __int64)&v1[-2];
  if ( !v1 )
    v4 = 0i64;
  v5 = fn->Env;
  if ( v5->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 1 )
  {
    v6 = (unsigned int)fn->FirstArgBottomIndex;
    if ( (unsigned int)v6 <= 32 * (LODWORD(v5->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
      v2 = &v5->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    LODWORD(v2) = Scaleform::GFx::AS2::Value::ToUInt32(v2, v5);
  }
  v7 = v3->Result;
  v8 = *(unsigned __int8 *)(v4 + 12i64 * (unsigned int)v2 + 116);
  if ( v7->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v7);
  v7->NV.Int32Value = v8;
  v7->T.Type = 4;
}

// File Line: 393
// RVA: 0x6AC530
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::KeyGetCode(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *v1; // rax
  Scaleform::GFx::AS2::Value *v2; // r9
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  signed __int64 v4; // rdi
  Scaleform::GFx::AS2::Environment *v5; // rdx
  unsigned __int64 v6; // r8
  Scaleform::GFx::AS2::Value *v7; // rbx
  int v8; // edi

  v1 = fn->ThisPtr;
  v2 = 0i64;
  v3 = fn;
  v4 = (signed __int64)&v1[-2];
  if ( !v1 )
    v4 = 0i64;
  v5 = fn->Env;
  if ( v5->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 1 )
  {
    v6 = (unsigned int)fn->FirstArgBottomIndex;
    if ( (unsigned int)v6 <= 32 * (LODWORD(v5->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v5->Stack.pCurrent - (char *)v5->Stack.pPageStart) >> 5) )
      v2 = &v5->Stack.Pages.Data.Data[v6 >> 5]->Values[v6 & 0x1F];
    LODWORD(v2) = Scaleform::GFx::AS2::Value::ToUInt32(v2, v5);
  }
  v7 = v3->Result;
  v8 = *(_DWORD *)(v4 + 12i64 * (unsigned int)v2 + 112);
  if ( v7->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v7);
  v7->NV.Int32Value = v8;
  v7->T.Type = 4;
}

// File Line: 409
// RVA: 0x6AC7C0
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::KeyIsDown(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::Environment *v2; // rdx
  unsigned __int64 v3; // r8
  signed __int64 v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // r9
  int v6; // eax
  Scaleform::GFx::AS2::Environment *v7; // rdx
  int v8; // esi
  unsigned int v9; // eax
  unsigned __int64 v10; // r8
  Scaleform::GFx::AS2::Value *v11; // r9
  Scaleform::GFx::AS2::ObjectInterface *v12; // rcx
  Scaleform::GFx::KeyboardState *v13; // rcx
  bool v14; // di
  Scaleform::GFx::AS2::Value *v15; // rbx

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = fn->Env;
    v3 = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    v5 = 0i64;
    if ( (unsigned int)v3 <= 32 * (LODWORD(v2->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
      v5 = &v2->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToInt32(v5, v2);
    v7 = v1->Env;
    v8 = v6;
    v9 = 0;
    if ( v7->StringContext.pContext->GFxExtensions.Value == 1 && v1->NArgs >= 2 )
    {
      v10 = (unsigned int)(v1->FirstArgBottomIndex - 1);
      v11 = 0i64;
      if ( (unsigned int)v10 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v11 = &v7->Stack.Pages.Data.Data[v10 >> 5]->Values[(LOBYTE(v1->FirstArgBottomIndex) - 1) & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToUInt32(v11, v7);
    }
    v12 = v1->ThisPtr;
    if ( v12 )
      v4 = (signed __int64)&v12[-2];
    if ( v9 < 6 && (v13 = (Scaleform::GFx::KeyboardState *)(*(_QWORD *)(v4 + 304) + 1672i64 * v9 + 9192)) != 0i64 )
      v14 = Scaleform::GFx::KeyboardState::IsKeyDown(v13, v8);
    else
      v14 = 0;
    v15 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v15);
    v15->V.BooleanValue = v14;
    v15->T.Type = 2;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(fn->Env, "KeyIsDown needs one Argument (the key code)");
  }
}

// File Line: 434
// RVA: 0x6ACA20
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::KeyIsToggled(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::Environment *v2; // rdx
  unsigned __int64 v3; // r8
  signed __int64 v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // r9
  int v6; // eax
  Scaleform::GFx::AS2::Environment *v7; // rdx
  int v8; // esi
  unsigned int v9; // eax
  unsigned __int64 v10; // r8
  Scaleform::GFx::AS2::Value *v11; // r9
  Scaleform::GFx::AS2::ObjectInterface *v12; // rcx
  Scaleform::GFx::KeyboardState *v13; // rcx
  bool v14; // di
  Scaleform::GFx::AS2::Value *v15; // rbx

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = fn->Env;
    v3 = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    v5 = 0i64;
    if ( (unsigned int)v3 <= 32 * (LODWORD(v2->Stack.Pages.Data.Size) - 1)
                           + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
      v5 = &v2->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToInt32(v5, v2);
    v7 = v1->Env;
    v8 = v6;
    v9 = 0;
    if ( v7->StringContext.pContext->GFxExtensions.Value == 1 && v1->NArgs >= 2 )
    {
      v10 = (unsigned int)(v1->FirstArgBottomIndex - 1);
      v11 = 0i64;
      if ( (unsigned int)v10 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
        v11 = &v7->Stack.Pages.Data.Data[v10 >> 5]->Values[(LOBYTE(v1->FirstArgBottomIndex) - 1) & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToUInt32(v11, v7);
    }
    v12 = v1->ThisPtr;
    if ( v12 )
      v4 = (signed __int64)&v12[-2];
    if ( v9 < 6 && (v13 = (Scaleform::GFx::KeyboardState *)(*(_QWORD *)(v4 + 304) + 1672i64 * v9 + 9192)) != 0i64 )
      v14 = Scaleform::GFx::KeyboardState::IsKeyToggled(v13, v8);
    else
      v14 = 0;
    v15 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v15);
    v15->V.BooleanValue = v14;
    v15->T.Type = 2;
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(fn->Env, "KeyIsToggled needs one Argument (the key code)");
  }
}

// File Line: 457
// RVA: 0x6F96A0
void __fastcall Scaleform::GFx::AS2::StageCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v1; // rbx

  v1 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v1->T.Type = 1;
}

