// File Line: 66
// RVA: 0x6C9730
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::KeyCtorFunction(
        Scaleform::GFx::AS2::KeyCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbx
  Scaleform::GFx::AS2::KeyCtorFunction::State *States; // rax
  int i; // ecx
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
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
  Scaleform::GFx::AS2::Value v46; // [rsp+38h] [rbp-28h] BYREF
  char v47; // [rsp+A0h] [rbp+40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+48h] BYREF

  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(this, psc, Scaleform::GFx::AS2::StageCtorFunction::GlobalCtor);
  this->Scaleform::GFx::KeyboardState::IListener::vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::KeyboardState::IListener::`vftable;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::KeyCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  v6 = &this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::KeyCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->Scaleform::GFx::KeyboardState::IListener::vfptr = (Scaleform::GFx::KeyboardState::IListenerVtbl *)&Scaleform::GFx::AS2::KeyCtorFunction::`vftable;
  States = this->States;
  for ( i = 15; i >= 0; --i )
  {
    States->LastKeyCode = 0;
    States->LastAsciiCode = 0;
    States->LastWcharCode = 0;
    ++States;
  }
  this->pMovieRoot = proot;
  if ( this != (Scaleform::GFx::AS2::KeyCtorFunction *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      psc,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(psc, &this->Scaleform::GFx::AS2::ObjectInterface);
  v46.T.Type = 4;
  v46.NV.Int32Value = 8;
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "BACKSPACE");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v9,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  pNode = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 20;
  v12 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "CAPSLOCK");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v12,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v13 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 17;
  v14 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "CONTROL");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v14,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v15 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 46;
  v16 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "DELETEKEY");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v16,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v17 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v17);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 40;
  v18 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "DOWN");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v18,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v19 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v19);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 35;
  v20 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "END");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v20,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v21 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v21);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 13;
  v22 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "ENTER");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v22,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v23 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v23);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 27;
  v24 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "ESCAPE");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v24,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v25 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v25);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 36;
  v26 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "HOME");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v26,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v27 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v27);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 45;
  v28 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "INSERT");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v28,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v29 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 37;
  v30 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "LEFT");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v30,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v31 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v31);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 34;
  v32 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "PGDN");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v32,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v33 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 33;
  v34 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "PGUP");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v34,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v35 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 39;
  v36 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "RIGHT");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v36,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v37 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v37);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 16;
  v38 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "SHIFT");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v38,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v39 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v39);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 32;
  v40 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "SPACE");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v40,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v41 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v41);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 9;
  v42 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "TAB");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v42,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v43 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v43);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  v46.T.Type = 4;
  v46.NV.Int32Value = 38;
  v44 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "UP");
  v47 = 0;
  v6->vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v44,
    &v46,
    (Scaleform::GFx::AS2::PropFlags *)&v47);
  v45 = result.pNode;
  v11 = result.pNode->RefCount-- == 1;
  if ( v11 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  if ( v46.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v46);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Scaleform::GFx::AS2::KeyCtorFunction::StaticFunctionTable,
    0);
  Scaleform::GFx::MovieImpl::SetKeyboardListener(proot, &this->Scaleform::GFx::KeyboardState::IListener);
}

// File Line: 99
// RVA: 0x722EB0
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::Update(
        Scaleform::GFx::AS2::KeyCtorFunction *this,
        Scaleform::GFx::EventId *evt)
{
  char AsciiCode; // al

  *((_DWORD *)&this->pRCC + 3 * evt->ControllerIndex) = evt->KeyCode;
  AsciiCode = evt->AsciiCode;
  if ( !AsciiCode )
    AsciiCode = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(evt);
  *((_BYTE *)&this->pNext + 12 * evt->ControllerIndex + 4) = AsciiCode;
  *(&this->RootIndex + 3 * evt->ControllerIndex) = evt->WcharCode;
}

// File Line: 108
// RVA: 0x703540
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::NotifyListeners(
        Scaleform::GFx::AS2::KeyCtorFunction *this,
        Scaleform::GFx::InteractiveObject *__formal,
        Scaleform::GFx::EventId *evt)
{
  char AsciiCode; // al
  unsigned int v6; // edi
  Scaleform::GFx::MovieImpl *pMovieRoot; // rax
  unsigned int v8; // ecx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  unsigned __int64 Size; // rdx
  __int64 v11; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  Scaleform::GFx::InteractiveObject *pObject; // rcx
  __int64 v14; // rcx
  __int64 v15; // rax
  Scaleform::GFx::AS2::Environment *v16; // rbp
  __int64 pCurrent; // rcx
  int ControllerIndex; // eax
  unsigned int v19; // r8d
  Scaleform::GFx::AS2::Value *v20; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::EventId evta; // [rsp+28h] [rbp-40h] BYREF
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF
  __int64 v25; // [rsp+80h] [rbp+18h]
  __int64 v26; // [rsp+88h] [rbp+20h]

  this->States[evt->ControllerIndex].LastKeyCode = evt->KeyCode;
  AsciiCode = evt->AsciiCode;
  if ( !AsciiCode )
    AsciiCode = Scaleform::GFx::EventId::ConvertKeyCodeToAscii(evt);
  this->States[evt->ControllerIndex].LastAsciiCode = AsciiCode;
  this->States[evt->ControllerIndex].LastWcharCode = evt->WcharCode;
  evta.Id = LOBYTE(evt->Id);
  v6 = 0;
  *(_QWORD *)&evta.WcharCode = 0i64;
  evta.AsciiCode = 0;
  *(_DWORD *)&evta.RollOverCnt = 65280;
  Scaleform::GFx::AS2::EventId_GetFunctionName(
    &result,
    (Scaleform::GFx::AS2::StringManager *)&this->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion,
    &evta);
  pMovieRoot = this->pMovieRoot;
  if ( pMovieRoot )
  {
    v8 = 0;
    pMovieImpl = pMovieRoot->pASMovieRoot.pObject->pMovieImpl;
    Size = pMovieImpl->MovieLevels.Data.Size;
    if ( Size )
    {
      v11 = 0i64;
      Data = pMovieImpl->MovieLevels.Data.Data;
      while ( Data[v11].Level )
      {
        v11 = ++v8;
        if ( v8 >= Size )
          goto LABEL_25;
      }
      pObject = Data[v8].pSprite.pObject;
      if ( pObject )
      {
        v14 = (__int64)pObject + 4 * (unsigned __int8)pObject->AvmObjOffset;
        v15 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v14 + 240i64))(v14);
        v16 = (Scaleform::GFx::AS2::Environment *)v15;
        if ( v15 )
        {
          if ( *(_BYTE *)(*(_QWORD *)(v15 + 232) + 104i64) == 1 )
          {
            *(_QWORD *)(v15 + 8) += 32i64;
            if ( *(_QWORD *)(v15 + 8) >= *(_QWORD *)(v15 + 24) )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage((Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)(v15 + 8));
            pCurrent = (__int64)v16->Stack.pCurrent;
            v25 = pCurrent;
            v26 = pCurrent;
            if ( pCurrent )
            {
              ControllerIndex = evt->ControllerIndex;
              *(_BYTE *)pCurrent = 4;
              *(_DWORD *)(pCurrent + 8) = ControllerIndex;
            }
            v6 = 1;
          }
          v19 = v16->Stack.pCurrent - v16->Stack.pPageStart + 32 * v16->Stack.Pages.Data.Size - 32;
          if ( this != (Scaleform::GFx::AS2::KeyCtorFunction *)-32i64 )
          {
            *(_QWORD *)&evta.Id = `Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
            evta.KeyCode = v6;
            evta.TouchID = v19;
            Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(
              v16,
              &this->Scaleform::GFx::AS2::ObjectInterface,
              &result,
              (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *)&evta);
            *(_QWORD *)&evta.Id = &Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
          }
          for ( ; v6; --v6 )
          {
            v20 = v16->Stack.pCurrent;
            if ( v20->T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(v20);
            if ( --v16->Stack.pCurrent < v16->Stack.pPageStart )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v16->Stack);
          }
        }
      }
    }
  }
LABEL_25:
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}

// File Line: 377
// RVA: 0x6AC1A0
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::KeyGetAscii(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rax
  Scaleform::GFx::AS2::Value *v2; // r9
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *Result; // rbx
  int v8; // edi

  ThisPtr = fn->ThisPtr;
  v2 = 0i64;
  v4 = ThisPtr - 2;
  if ( !ThisPtr )
    v4 = 0i64;
  Env = fn->Env;
  if ( Env->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v2 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    LODWORD(v2) = Scaleform::GFx::AS2::Value::ToUInt32(v2, Env);
  }
  Result = fn->Result;
  v8 = *((unsigned __int8 *)&v4[7].vfptr + 12 * (unsigned int)v2 + 4);
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->NV.Int32Value = v8;
  Result->T.Type = 4;
}

// File Line: 393
// RVA: 0x6AC530
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::KeyGetCode(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rax
  Scaleform::GFx::AS2::Value *v2; // r9
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdi
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *Result; // rbx
  int v8; // edi

  ThisPtr = fn->ThisPtr;
  v2 = 0i64;
  v4 = ThisPtr - 2;
  if ( !ThisPtr )
    v4 = 0i64;
  Env = fn->Env;
  if ( Env->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 1 )
  {
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v2 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    LODWORD(v2) = Scaleform::GFx::AS2::Value::ToUInt32(v2, Env);
  }
  Result = fn->Result;
  v8 = *((_DWORD *)&v4[7].vfptr + 3 * (unsigned int)v2);
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->NV.Int32Value = v8;
  Result->T.Type = 4;
}

// File Line: 409
// RVA: 0x6AC7C0
void __fastcall Scaleform::GFx::AS2::KeyCtorFunction::KeyIsDown(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // r9
  int v6; // eax
  Scaleform::GFx::AS2::Environment *v7; // rdx
  int v8; // esi
  unsigned int v9; // eax
  unsigned __int64 v10; // r8
  Scaleform::GFx::AS2::Value *v11; // r9
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::KeyboardState *v13; // rcx
  bool v14; // di
  Scaleform::GFx::AS2::Value *Result; // rbx

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    v5 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToInt32(v5, Env);
    v7 = fn->Env;
    v8 = v6;
    v9 = 0;
    if ( v7->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 2 )
    {
      v10 = (unsigned int)(fn->FirstArgBottomIndex - 1);
      v11 = 0i64;
      if ( (unsigned int)v10 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)(v7->Stack.pCurrent - v7->Stack.pPageStart) )
        v11 = &v7->Stack.Pages.Data.Data[v10 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToUInt32(v11, v7);
    }
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      v4 = ThisPtr - 2;
    v14 = v9 < 6
       && (v13 = (Scaleform::GFx::KeyboardState *)(&v4[19].vfptr[54].IsSuper + 209 * v9)) != 0i64
       && Scaleform::GFx::KeyboardState::IsKeyDown(v13, v8);
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v14;
    Result->T.Type = 2;
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
  Scaleform::GFx::AS2::Environment *Env; // rdx
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::ObjectInterface *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // r9
  int v6; // eax
  Scaleform::GFx::AS2::Environment *v7; // rdx
  int v8; // esi
  unsigned int v9; // eax
  unsigned __int64 v10; // r8
  Scaleform::GFx::AS2::Value *v11; // r9
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::KeyboardState *v13; // rcx
  bool v14; // di
  Scaleform::GFx::AS2::Value *Result; // rbx

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
    v4 = 0i64;
    v5 = 0i64;
    if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v6 = Scaleform::GFx::AS2::Value::ToInt32(v5, Env);
    v7 = fn->Env;
    v8 = v6;
    v9 = 0;
    if ( v7->StringContext.pContext->GFxExtensions.Value == 1 && fn->NArgs >= 2 )
    {
      v10 = (unsigned int)(fn->FirstArgBottomIndex - 1);
      v11 = 0i64;
      if ( (unsigned int)v10 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)(v7->Stack.pCurrent - v7->Stack.pPageStart) )
        v11 = &v7->Stack.Pages.Data.Data[v10 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
      v9 = Scaleform::GFx::AS2::Value::ToUInt32(v11, v7);
    }
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      v4 = ThisPtr - 2;
    v14 = v9 < 6
       && (v13 = (Scaleform::GFx::KeyboardState *)(&v4[19].vfptr[54].IsSuper + 209 * v9)) != 0i64
       && Scaleform::GFx::KeyboardState::IsKeyToggled(v13, v8);
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->V.BooleanValue = v14;
    Result->T.Type = 2;
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
  Scaleform::GFx::AS2::Value *Result; // rbx

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 1;
}

