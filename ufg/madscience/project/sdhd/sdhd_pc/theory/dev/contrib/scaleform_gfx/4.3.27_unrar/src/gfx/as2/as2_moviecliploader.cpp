// File Line: 30
// RVA: 0x6CA870
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::MovieClipLoader(
        Scaleform::GFx::AS2::MovieClipLoader *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // rax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipLoader::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipLoader::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  this->ProgressInfo.mHash.pTable = 0i64;
  p_StringContext = &penv->StringContext;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(p_StringContext->pContext, ASBuiltin_MovieClipLoader);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->Set__proto__(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    p_StringContext,
    Prototype);
  if ( this != (Scaleform::GFx::AS2::MovieClipLoader *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      &this->Scaleform::GFx::AS2::ObjectInterface,
      p_StringContext,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(p_StringContext, &this->Scaleform::GFx::AS2::ObjectInterface);
}

// File Line: 61
// RVA: 0x704710
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadStart(
        Scaleform::GFx::AS2::MovieClipLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  Scaleform::GFx::ASStringNode *pCurrent; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v7; // rsi
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::ASString *v9; // rax
  int v10; // r8d
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v13; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-40h] BYREF
  int v15; // [rsp+30h] [rbp-38h]
  int v16; // [rsp+34h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *v18; // [rsp+78h] [rbp+10h]

  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  pCurrent = (Scaleform::GFx::ASStringNode *)penv->Stack.pCurrent;
  result.pNode = pCurrent;
  v18 = pCurrent;
  v7 = 0i64;
  if ( pCurrent )
  {
    LOBYTE(pCurrent->pData) = 7;
    if ( ptarget )
    {
      pObject = ptarget->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
      pCurrent->pManager = (Scaleform::GFx::ASStringManager *)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
    else
    {
      pCurrent->pManager = 0i64;
    }
  }
  if ( this )
    v7 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v9 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "onLoadStart");
  v10 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  if ( v7 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v15 = 1;
    v16 = v10;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v7, v9, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v13 = penv->Stack.pCurrent;
  if ( v13->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v13);
  if ( --penv->Stack.pCurrent < penv->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
}

// File Line: 68
// RVA: 0x703F40
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadComplete(
        Scaleform::GFx::AS2::MovieClipLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *ptarget,
        int status)
{
  Scaleform::GFx::AS2::Value *pCurrent; // rax
  Scaleform::GFx::ASStringNode *v9; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v10; // rsi
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::ASString *v12; // rax
  int v13; // r8d
  int v14; // edi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v17; // rcx
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::Value *v19; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-40h] BYREF
  int v21; // [rsp+30h] [rbp-38h]
  int v22; // [rsp+34h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF
  void *v24; // [rsp+78h] [rbp+10h]

  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  pCurrent = penv->Stack.pCurrent;
  result.pNode = (Scaleform::GFx::ASStringNode *)pCurrent;
  v24 = pCurrent;
  if ( pCurrent )
  {
    pCurrent->T.Type = 4;
    pCurrent->NV.Int32Value = status;
  }
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v9 = (Scaleform::GFx::ASStringNode *)penv->Stack.pCurrent;
  result.pNode = v9;
  v24 = v9;
  v10 = 0i64;
  if ( v9 )
  {
    LOBYTE(v9->pData) = 7;
    if ( ptarget )
    {
      pObject = ptarget->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
      v9->pManager = (Scaleform::GFx::ASStringManager *)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
    else
    {
      v9->pManager = 0i64;
    }
  }
  if ( this )
    v10 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v12 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "onLoadComplete");
  v13 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  v14 = 2;
  if ( v10 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v21 = 2;
    v22 = v13;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v10, v12, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v17 = penv->Stack.pCurrent;
  if ( &v17[-2] >= penv->Stack.pPageStart )
  {
    if ( v17->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v17);
    v19 = --penv->Stack.pCurrent;
    if ( v19->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v19);
    --penv->Stack.pCurrent;
  }
  else
  {
    do
    {
      v18 = penv->Stack.pCurrent;
      if ( v18->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v18);
      if ( --penv->Stack.pCurrent < penv->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
      --v14;
    }
    while ( v14 );
  }
}

// File Line: 76
// RVA: 0x7042C0
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadInit(
        Scaleform::GFx::AS2::MovieClipLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *ptarget)
{
  Scaleform::GFx::ASStringNode *pCurrent; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v7; // rsi
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::ASString *v9; // rax
  int v10; // r8d
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v13; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-40h] BYREF
  int v15; // [rsp+30h] [rbp-38h]
  int v16; // [rsp+34h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::ASStringNode *v18; // [rsp+78h] [rbp+10h]

  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  pCurrent = (Scaleform::GFx::ASStringNode *)penv->Stack.pCurrent;
  result.pNode = pCurrent;
  v18 = pCurrent;
  v7 = 0i64;
  if ( pCurrent )
  {
    LOBYTE(pCurrent->pData) = 7;
    if ( ptarget )
    {
      pObject = ptarget->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
      pCurrent->pManager = (Scaleform::GFx::ASStringManager *)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
    else
    {
      pCurrent->pManager = 0i64;
    }
  }
  if ( this )
    v7 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v9 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "onLoadInit");
  v10 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  if ( v7 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v15 = 1;
    v16 = v10;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v7, v9, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v13 = penv->Stack.pCurrent;
  if ( v13->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v13);
  if ( --penv->Stack.pCurrent < penv->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
}

// File Line: 83
// RVA: 0x704100
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadError(
        Scaleform::GFx::AS2::MovieClipLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *ptarget,
        const char *errorCode,
        int status)
{
  Scaleform::GFx::AS2::Value *pCurrent; // r8
  Scaleform::GFx::ASString *v10; // rdi
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *v11; // rcx
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v16; // rsi
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::ASString *v18; // rax
  int v19; // r8d
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-40h] BYREF
  int v22; // [rsp+30h] [rbp-38h]
  int v23; // [rsp+34h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF
  void *v25; // [rsp+78h] [rbp+10h]

  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  pCurrent = penv->Stack.pCurrent;
  result.pNode = (Scaleform::GFx::ASStringNode *)pCurrent;
  v25 = pCurrent;
  if ( pCurrent )
  {
    pCurrent->T.Type = 4;
    pCurrent->NV.Int32Value = status;
  }
  v10 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, errorCode);
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v11 = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)penv->Stack.pCurrent;
  v25 = v11;
  pcallback.vfptr = v11;
  if ( v11 )
  {
    LOBYTE(v11->__vecDelDtor) = 5;
    pNode = v10->pNode;
    v11->Invoke = (void (__fastcall *)(Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::FunctionRef *))v10->pNode;
    ++pNode->RefCount;
  }
  v13 = result.pNode;
  v14 = result.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v15 = (Scaleform::GFx::ASStringNode *)penv->Stack.pCurrent;
  result.pNode = v15;
  v25 = v15;
  v16 = 0i64;
  if ( v15 )
  {
    LOBYTE(v15->pData) = 7;
    if ( ptarget )
    {
      pObject = ptarget->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
      v15->pManager = (Scaleform::GFx::ASStringManager *)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
    else
    {
      v15->pManager = 0i64;
    }
  }
  if ( this )
    v16 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v18 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "onLoadError");
  v19 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  if ( v16 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v22 = 3;
    v23 = v19;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v16, v18, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  v20 = result.pNode;
  v14 = result.pNode->RefCount-- == 1;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&penv->Stack);
}

// File Line: 92
// RVA: 0x704410
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadProgress(
        Scaleform::GFx::AS2::MovieClipLoader *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *ptarget,
        unsigned int loadedBytes,
        int totalBytes)
{
  int v9; // esi
  unsigned __int64 v10; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *pTable; // rdi
  __int64 v12; // rbx
  __int64 EntryCount; // r11
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v14; // r10
  Scaleform::String::DataDesc *pData; // rdx
  unsigned __int8 *v16; // rax
  int v17; // ecx
  int v18; // r8d
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v19; // r11
  unsigned int *p_SizeMask; // r11
  unsigned __int64 v21; // rax
  Scaleform::String::DataDesc *pCurrent; // rax
  Scaleform::String::DataDesc *v23; // rax
  Scaleform::GFx::AS2::Value *v24; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v25; // rsi
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::ASString *v27; // rax
  int v28; // r8d
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-28h] BYREF
  int v32; // [rsp+30h] [rbp-20h]
  int v33; // [rsp+34h] [rbp-1Ch]
  Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+38h] [rbp-18h] BYREF
  Scaleform::String ppath; // [rsp+90h] [rbp+40h] BYREF
  unsigned __int64 v36; // [rsp+98h] [rbp+48h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+50h] BYREF

  v9 = totalBytes;
  if ( !ptarget )
    goto LABEL_21;
  Scaleform::String::String(&ppath);
  Scaleform::GFx::DisplayObject::GetAbsolutePath(ptarget, &ppath);
  if ( this->ProgressInfo.mHash.pTable
    && (v10 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64),
        pTable = this->ProgressInfo.mHash.pTable,
        v12 = v10 & pTable->SizeMask,
        EntryCount = v12,
        v14 = &pTable[2 * v12 + 1],
        v14->EntryCount != -2i64)
    && v14->SizeMask == v12 )
  {
    pData = ppath.pData;
    while ( 1 )
    {
      if ( v14->SizeMask == v12 )
      {
        v16 = (unsigned __int8 *)((v14[1].EntryCount & 0xFFFFFFFFFFFFFFFCui64) + 12);
        do
        {
          v17 = v16[(ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (v14[1].EntryCount & 0xFFFFFFFFFFFFFFFCui64)];
          v18 = *v16 - v17;
          if ( v18 )
            break;
          ++v16;
        }
        while ( v17 );
        if ( !v18 )
          break;
      }
      EntryCount = v14->EntryCount;
      if ( v14->EntryCount == -1i64 )
        goto LABEL_18;
      v14 = &pTable[2 * EntryCount + 1];
    }
    if ( EntryCount >= 0 )
    {
      v19 = &pTable[2 * EntryCount + 2];
      if ( v19 )
      {
        p_SizeMask = (unsigned int *)&v19->SizeMask;
        if ( p_SizeMask )
        {
          *p_SizeMask = loadedBytes;
          p_SizeMask[1] = v9;
          goto LABEL_19;
        }
      }
    }
  }
  else
  {
    pData = ppath.pData;
  }
LABEL_18:
  v36 = __PAIR64__(v9, loadedBytes);
  key.pFirst = &ppath;
  key.pSecond = (Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc *)&v36;
  v21 = Scaleform::String::BernsteinHashFunctionCIS(
          (const void *)(((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) + 12),
          *(_QWORD *)((unsigned __int64)pData & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
          0x1505ui64);
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
    &this->ProgressInfo.mHash,
    &this->ProgressInfo,
    &key,
    v21);
LABEL_19:
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_21:
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  pCurrent = (Scaleform::String::DataDesc *)penv->Stack.pCurrent;
  ppath.pData = pCurrent;
  v36 = (unsigned __int64)pCurrent;
  if ( pCurrent )
  {
    LOBYTE(pCurrent->Size) = 4;
    pCurrent->RefCount = v9;
  }
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v23 = (Scaleform::String::DataDesc *)penv->Stack.pCurrent;
  ppath.pData = v23;
  v36 = (unsigned __int64)v23;
  if ( v23 )
  {
    LOBYTE(v23->Size) = 4;
    v23->RefCount = loadedBytes;
  }
  if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v24 = penv->Stack.pCurrent;
  ppath.pData = (Scaleform::String::DataDesc *)v24;
  v36 = (unsigned __int64)v24;
  v25 = 0i64;
  if ( v24 )
  {
    v24->T.Type = 7;
    if ( ptarget )
    {
      pObject = ptarget->pNameHandle.pObject;
      if ( !pObject )
        pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(ptarget);
      v24->V.pStringNode = (Scaleform::GFx::ASStringNode *)pObject;
      if ( pObject )
        ++pObject->RefCount;
    }
    else
    {
      v24->V.pStringNode = 0i64;
    }
  }
  if ( this )
    v25 = &this->Scaleform::GFx::AS2::ObjectInterface;
  v27 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "onLoadProgress");
  v28 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
  if ( v25 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage::`4::LocalInvokeCallback::`vftable;
    v32 = 3;
    v33 = v28;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v25, v27, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
  }
  pNode = result.pNode;
  if ( result.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&penv->Stack);
}

// File Line: 119
// RVA: 0x6B3740
void __fastcall Scaleform::GFx::AS2::MovieClipLoaderProto::GetProgress(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  __int64 v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rax
  int *v5; // r14
  Scaleform::GFx::AS2::ObjectInterface *v6; // rbp
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rsi
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v12; // r10
  unsigned __int64 v13; // rax
  Scaleform::GFx::AS2::ObjectInterfaceVtbl *vfptr; // r15
  __int64 v15; // rbp
  __int64 v16; // r11
  __int64 *v17; // r10
  unsigned __int8 *v18; // rax
  int v19; // ecx
  int v20; // r8d
  bool (__fastcall **v21)(Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *); // r11
  int v22; // eax
  int v23; // eax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value val; // [rsp+28h] [rbp-70h] BYREF
  Scaleform::GFx::AS2::Value v28; // [rsp+48h] [rbp-50h] BYREF
  Scaleform::String v29; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+10h] BYREF
  Scaleform::GFx::AS2::Object *v31; // [rsp+B0h] [rbp+18h]

  if ( fn->NArgs >= 1 )
  {
    v2 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v2);
    v2->T.Type = 0;
    if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 25 )
    {
      ThisPtr = fn->ThisPtr;
      v5 = 0i64;
      v6 = ThisPtr - 2;
      if ( !ThisPtr )
        v6 = 0i64;
      v29.pData = (Scaleform::String::DataDesc *)fn->Env->StringContext.pContext->pHeap;
      v7 = (Scaleform::GFx::AS2::Object *)(*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v29.HeapTypeBits
                                                                                      + 80i64))(
                                            v3,
                                            96i64);
      v31 = v7;
      if ( v7 )
      {
        Scaleform::GFx::AS2::Object::Object(v7, fn->Env);
        v9 = v8;
      }
      else
      {
        v9 = 0i64;
      }
      v31 = v9;
      FirstArgBottomIndex = fn->FirstArgBottomIndex;
      Env = fn->Env;
      v12 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v12 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v12, &result, Env, -1);
      Scaleform::String::String(&v29, result.pNode->pData);
      if ( v6[6].vfptr )
      {
        v13 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64);
        vfptr = v6[6].vfptr;
        v15 = v13 & *(_QWORD *)vfptr->gap8;
        v16 = v15;
        v17 = (__int64 *)&vfptr->gap8[32 * v15 + 8];
        if ( *v17 != -2 && v17[1] == v15 )
        {
          while ( 1 )
          {
            if ( v17[1] == v15 )
            {
              v18 = (unsigned __int8 *)((v17[2] & 0xFFFFFFFFFFFFFFFCui64) + 12);
              do
              {
                v19 = v18[(v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (v17[2] & 0xFFFFFFFFFFFFFFFCui64)];
                v20 = *v18 - v19;
                if ( v20 )
                  break;
                ++v18;
              }
              while ( v19 );
              if ( !v20 )
                break;
            }
            v16 = *v17;
            if ( *v17 == -1 )
              goto LABEL_23;
            v17 = (__int64 *)&vfptr->gap8[32 * v16 + 8];
          }
          if ( v16 >= 0 )
          {
            v21 = &vfptr->GetMember + 4 * v16;
            if ( v21 )
              v5 = (int *)(v21 + 1);
          }
        }
      }
LABEL_23:
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( v5 )
      {
        v22 = *v5;
        val.T.Type = 4;
        val.NV.Int32Value = v22;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v9->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "bytesLoaded",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v23 = v5[1];
        v28.T.Type = 4;
        v28.NV.Int32Value = v23;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          &v9->Scaleform::GFx::AS2::ObjectInterface,
          &fn->Env->StringContext,
          "bytesTotal",
          &v28);
        if ( v28.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v28);
      }
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v9);
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      if ( v9 )
      {
        RefCount = v9->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v9->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
    }
  }
}

// File Line: 145
// RVA: 0x6B3A30
void __fastcall Scaleform::GFx::AS2::MovieClipLoaderProto::LoadClip(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::MovieClipLoader *pmovieClipLoader; // rbp
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rax
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r8
  Scaleform::GFx::AS2::Value *v7; // r10
  unsigned int v8; // r9d
  Scaleform::GFx::AS2::Environment *v9; // r8
  Scaleform::GFx::AS2::Value *v10; // r10
  unsigned __int64 Size; // rax
  __int64 v12; // rcx
  __int64 v13; // rdx
  Scaleform::GFx::CharacterHandle *v14; // rcx
  Scaleform::GFx::DisplayObject *v15; // rax
  Scaleform::GFx::InteractiveObject *v16; // rbx
  Scaleform::GFx::AS2::Value *v17; // r10
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::InteractiveObject *Target; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v21; // zf
  unsigned int v22; // r9d
  Scaleform::GFx::AS2::Environment *v23; // r8
  Scaleform::GFx::AS2::Value *v24; // r10
  Scaleform::GFx::ASString *v25; // rdi
  unsigned int Version; // eax
  int v27; // edi
  Scaleform::GFx::ASStringNode *v28; // rcx
  unsigned int v29; // r10d
  Scaleform::GFx::AS2::Environment *v30; // r8
  Scaleform::GFx::AS2::Value *v31; // r11
  Scaleform::GFx::ASString *v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::AS2::Value *v34; // rdi
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::GFx::InteractiveObject *v37; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::ASString v38; // [rsp+80h] [rbp+18h] BYREF
  char *ptail; // [rsp+88h] [rbp+20h] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  if ( fn->NArgs < 2 )
    return;
  pmovieClipLoader = 0i64;
  if ( (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&fn->ThisPtr->vfptr->gap8[8])(fn->ThisPtr) == 25 )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
      pmovieClipLoader = (Scaleform::GFx::AS2::MovieClipLoader *)&ThisPtr[-2];
  }
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v7 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v7 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v7, &result, Env, -1);
  v37 = 0i64;
  v8 = fn->FirstArgBottomIndex - 1;
  v9 = fn->Env;
  v10 = 0i64;
  if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
           + (unsigned int)(v9->Stack.pCurrent - v9->Stack.pPageStart) )
    v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
  Size = v9->Stack.Pages.Data.Size;
  v12 = v9->Stack.pCurrent - v9->Stack.pPageStart;
  if ( v10->T.Type == 7 )
  {
    v13 = 0i64;
    if ( v8 <= 32 * ((int)Size - 1) + (int)v12 )
      v13 = (__int64)&v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    if ( *(_BYTE *)v13 == 7
      && v9
      && (v14 = *(Scaleform::GFx::CharacterHandle **)(v13 + 8)) != 0i64
      && (v15 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v14, v9->Target->pASRoot->pMovieImpl)) != 0i64 )
    {
      v16 = 0i64;
      if ( SLOBYTE(v15->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
        v16 = (Scaleform::GFx::InteractiveObject *)v15;
      if ( v16 )
        ++v16->RefCount;
    }
    else
    {
      v16 = 0i64;
    }
    v37 = v16;
  }
  else
  {
    v17 = 0i64;
    if ( v8 <= 32 * ((int)Size - 1) + (int)v12 )
      v17 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v18 = Scaleform::GFx::AS2::Value::ToString(v17, &v38, v9, -1);
    Target = Scaleform::GFx::AS2::Environment::FindTarget(fn->Env, v18, 0);
    v16 = Target;
    if ( Target )
      ++Target->RefCount;
    v37 = Target;
    pNode = v38.pNode;
    v21 = v38.pNode->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( v16 )
  {
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
      (Scaleform::GFx::AS2::MovieRoot *)fn->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      v16,
      result.pNode->pData,
      LM_None,
      pmovieClipLoader);
  }
  else
  {
    v22 = fn->FirstArgBottomIndex - 1;
    v23 = fn->Env;
    v24 = 0i64;
    if ( v22 <= 32 * ((unsigned int)v23->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v23->Stack.pCurrent - v23->Stack.pPageStart) )
      v24 = &v23->Stack.Pages.Data.Data[v22 >> 5]->Values[v22 & 0x1F];
    v25 = Scaleform::GFx::AS2::Value::ToString(v24, &v38, v23, -1);
    Version = Scaleform::GFx::DisplayObjectBase::GetVersion(fn->Env->Target);
    v27 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(v25->pNode->pData, (const char **)&ptail, Version > 6);
    v28 = v38.pNode;
    v21 = v38.pNode->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    if ( v27 == -1 )
      goto LABEL_40;
    v29 = fn->FirstArgBottomIndex - 1;
    v30 = fn->Env;
    v31 = 0i64;
    if ( v29 <= 32 * ((unsigned int)v30->Stack.Pages.Data.Size - 1)
              + (unsigned int)(v30->Stack.pCurrent - v30->Stack.pPageStart) )
      v31 = &v30->Stack.Pages.Data.Data[v29 >> 5]->Values[v29 & 0x1F];
    v32 = Scaleform::GFx::AS2::Value::ToString(v31, &v38, v30, -1);
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
      (Scaleform::GFx::AS2::MovieRoot *)fn->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      v32->pNode->pData,
      result.pNode->pData,
      fn->Env,
      LM_None,
      pmovieClipLoader);
    v33 = v38.pNode;
    v21 = v38.pNode->RefCount-- == 1;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  }
  v34 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v34);
  v34->T.Type = 2;
  v34->V.BooleanValue = 1;
LABEL_40:
  if ( v16 )
    Scaleform::RefCountNTSImpl::Release(v16);
  v35 = result.pNode;
  v21 = result.pNode->RefCount-- == 1;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
}

// File Line: 179
// RVA: 0x6B3DD0
void __fastcall Scaleform::GFx::AS2::MovieClipLoaderProto::UnloadClip(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int FirstArgBottomIndex; // r9d
  Scaleform::GFx::AS2::Environment *Env; // r10
  Scaleform::GFx::AS2::Value *v5; // r8
  unsigned __int64 Size; // rax
  __int64 v7; // rcx
  __int64 v8; // rdx
  Scaleform::GFx::CharacterHandle *v9; // rcx
  Scaleform::GFx::DisplayObject *v10; // rax
  Scaleform::GFx::InteractiveObject *v11; // rbx
  Scaleform::GFx::AS2::Value *v12; // r8
  Scaleform::GFx::AS2::Value *v13; // r11
  __int64 v14; // rcx
  unsigned __int64 v15; // rax
  Scaleform::GFx::ASMovieRootBase *pObject; // rbx
  int v17; // eax
  unsigned int v18; // edx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  unsigned __int64 v20; // r9
  __int64 v21; // rcx
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // r8
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::InteractiveObject *Target; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::Value *v27; // rdi
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v2);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  if ( fn->NArgs < 1 )
    return;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  Env = fn->Env;
  v5 = 0i64;
  if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                            + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  Size = Env->Stack.Pages.Data.Size;
  v7 = Env->Stack.pCurrent - Env->Stack.pPageStart;
  if ( v5->T.Type == 7 )
  {
    v8 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((int)Size - 1) + (int)v7 )
      v8 = (__int64)&Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    if ( *(_BYTE *)v8 == 7 )
    {
      if ( Env )
      {
        v9 = *(Scaleform::GFx::CharacterHandle **)(v8 + 8);
        if ( v9 )
        {
          v10 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v9, Env->Target->pASRoot->pMovieImpl);
          if ( v10 )
          {
            v11 = 0i64;
            if ( SLOBYTE(v10->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
              v11 = (Scaleform::GFx::InteractiveObject *)v10;
            if ( v11 )
              ++v11->RefCount;
            goto LABEL_35;
          }
        }
      }
    }
  }
  else
  {
    v12 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((int)Size - 1) + (int)v7 )
      v12 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v13 = 0i64;
    v14 = Env->Stack.pCurrent - Env->Stack.pPageStart;
    v15 = Env->Stack.Pages.Data.Size;
    if ( (unsigned __int8)(v12->T.Type - 3) > 1u )
    {
      if ( FirstArgBottomIndex <= 32 * ((int)v15 - 1) + (int)v14 )
        v13 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      v23 = Scaleform::GFx::AS2::Value::ToString(v13, &result, fn->Env, -1);
      Target = Scaleform::GFx::AS2::Environment::FindTarget(fn->Env, v23, 0);
      v11 = Target;
      if ( Target )
        ++Target->RefCount;
      pNode = result.pNode;
      if ( result.pNode->RefCount-- == 1 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      goto LABEL_35;
    }
    if ( FirstArgBottomIndex <= 32 * ((int)v15 - 1) + (int)v14 )
      v13 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    pObject = Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v17 = Scaleform::GFx::AS2::Value::ToInt32(v13, fn->Env);
    v18 = 0;
    pMovieImpl = pObject->pMovieImpl;
    v20 = pMovieImpl->MovieLevels.Data.Size;
    if ( v20 )
    {
      v21 = 0i64;
      Data = pMovieImpl->MovieLevels.Data.Data;
      while ( Data[v21].Level != v17 )
      {
        v21 = ++v18;
        if ( v18 >= v20 )
          goto LABEL_27;
      }
      v11 = Data[v18].pSprite.pObject;
      if ( v11 )
        ++v11->RefCount;
      goto LABEL_35;
    }
  }
LABEL_27:
  v11 = 0i64;
LABEL_35:
  if ( v11 )
  {
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
      (Scaleform::GFx::AS2::MovieRoot *)fn->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      v11,
      &customCaption,
      LM_None,
      0i64);
    v27 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v27);
    v27->T.Type = 2;
    v27->V.BooleanValue = 1;
  }
  if ( v11 )
    Scaleform::RefCountNTSImpl::Release(v11);
}

// File Line: 223
// RVA: 0x6F9720
void __fastcall Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v4; // r8
  Scaleform::GFx::AS2::Object *v5; // rdi
  Scaleform::GFx::AS2::Value *Result; // rbx

  ThisPtr = fn->ThisPtr;
  if ( ThisPtr
    && (*(unsigned int (__fastcall **)(Scaleform::GFx::AS2::ObjectInterface *))&ThisPtr->vfptr->gap8[8])(ThisPtr) == 25
    && !fn->ThisPtr->vfptr->IsBuiltinPrototype(fn->ThisPtr) )
  {
    v3 = fn->ThisPtr;
    v4 = 0i64;
    if ( v3 )
    {
      v5 = (Scaleform::GFx::AS2::Object *)&v3[-2];
      if ( v5 )
        v4 = &v5->Scaleform::GFx::AS2::ObjectInterface;
    }
    else
    {
      v5 = 0i64;
    }
    Scaleform::GFx::AS2::AsBroadcaster::AddListener(fn->Env, v4, v4);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v5);
  }
  else
  {
    Result = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 1;
  }
}

// File Line: 236
// RVA: 0x6E0680
void __fastcall Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::CreateNewObject(
        Scaleform::GFx::AS2::MovieClipLoaderCtorFunction *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::MovieClipLoader *v3; // rax

  v3 = (Scaleform::GFx::AS2::MovieClipLoader *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieClipLoaderCtorFunction *, __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                 this,
                                                 104i64);
  if ( v3 )
    Scaleform::GFx::AS2::MovieClipLoader::MovieClipLoader(v3, penv);
}

// File Line: 241
// RVA: 0x70DEB0
Scaleform::MemoryHeap *__fastcall Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::Register(
        Scaleform::MemoryHeap *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *pObject; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // r15
  unsigned int RefCount; // eax
  __int64 v9; // rdi
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::GFx::AS2::Object *v13; // rbx
  Scaleform::GFx::ASStringNode *vfptr; // rax
  Scaleform::GFx::AS2::LocalFrame *pPrev; // rdx
  int v16; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+48h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v19; // [rsp+58h] [rbp-28h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+C8h] [rbp+48h] BYREF
  Scaleform::MemoryHeap *flags; // [rsp+D0h] [rbp+50h] BYREF
  void *pHeap; // [rsp+D8h] [rbp+58h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)flags->vfptr->Alloc(result, 104ui64, 0i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  pHeap = v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6[1].Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::GlobalCtor;
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
        &v6->Scaleform::GFx::AS2::ObjectInterface,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    if ( Prototype )
      Prototype->RefCount = (Prototype->RefCount + 1) & 0x8FFFFFFF;
    pObject = v6->pProto.pObject;
    if ( pObject )
    {
      RefCount = pObject->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        pObject->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
      }
    }
    v6->pProto.pObject = Prototype;
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  }
  else
  {
    v6 = 0i64;
  }
  LOBYTE(result->pNext) = 0;
  result->vfptr = (Scaleform::MemoryHeapVtbl *)v6;
  result->pPrev = 0i64;
  pHeap = pgc->pHeap;
  v9 = (*(__int64 (__fastcall **)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, __int64, _QWORD))(*(_QWORD *)pHeap + 80i64))(
         pObject,
         168i64,
         0i64);
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v9, &psc);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::MovieClipLoader::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::MovieClipLoader::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    objproto.pObject = (Scaleform::GFx::AS2::Object *)(v9 + 96);
    flags = (Scaleform::MemoryHeap *)(v9 + 96);
    *(_QWORD *)(v9 + 96) = 0i64;
    if ( !*(_QWORD *)(v9 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v19.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v9 + 32) + 80i64))(
        v9 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v19,
        &objproto);
      if ( v19.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v19);
    }
    if ( v10 )
      v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
    v11 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v9 + 40);
    if ( v11 )
    {
      v12 = v11->RefCount;
      if ( (v12 & 0x3FFFFFF) != 0 )
      {
        v11->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
    *(_QWORD *)(v9 + 40) = v10;
    flags = (Scaleform::MemoryHeap *)(v9 + 104);
    *(_QWORD *)(v9 + 104) = &Scaleform::GFx::AS2::GASPrototypeBase::`vftable;
    *(_BYTE *)(v9 + 128) = 0;
    *(_QWORD *)(v9 + 112) = 0i64;
    *(_QWORD *)(v9 + 120) = 0i64;
    *(_BYTE *)(v9 + 152) = 0;
    *(_QWORD *)(v9 + 136) = 0i64;
    *(_QWORD *)(v9 + 144) = 0i64;
    *(_QWORD *)(v9 + 160) = 0i64;
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipLoader,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipLoader,Scaleform::GFx::AS2::Environment>::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v9 + 104) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipLoader,Scaleform::GFx::AS2::Environment>::`vftable;
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v9 + 104),
      (Scaleform::GFx::AS2::Object *)v9,
      &psc,
      (Scaleform::GFx::AS2::FunctionRef *)result);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::MovieClipLoaderProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::MovieClipLoaderProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    *(_QWORD *)(v9 + 104) = &Scaleform::GFx::AS2::MovieClipLoaderProto::`vftable;
    LOBYTE(flags) = 1;
    Scaleform::GFx::AS2::GASPrototypeBase::InitFunctionMembers(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v9 + 104),
      (Scaleform::GFx::AS2::Object *)v9,
      &psc,
      GAS_MovieClipLoaderFuncTable,
      (Scaleform::GFx::AS2::PropFlags *)&flags);
  }
  else
  {
    v9 = 0i64;
  }
  flags = (Scaleform::MemoryHeap *)v9;
  pHeap = &objproto;
  if ( v9 )
    *(_DWORD *)(v9 + 24) = (*(_DWORD *)(v9 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v9;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_MovieClipLoader,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v13 = pgc->pGlobal.pObject;
  v19.T.Type = 8;
  v19.V.FunctionValue.Flags = 0;
  vfptr = (Scaleform::GFx::ASStringNode *)result->vfptr;
  v19.V.pStringNode = vfptr;
  if ( vfptr )
  {
    ++vfptr->RefCount;
    vfptr->RefCount &= 0x8FFFFFFF;
  }
  v19.V.FunctionValue.pLocalFrame = 0i64;
  pPrev = (Scaleform::GFx::AS2::LocalFrame *)result->pPrev;
  if ( pPrev )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v19.V.FunctionValue, pPrev, (__int64)result->pNext & 1);
  LOBYTE(objproto.pObject) = 0;
  v13->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &v13->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[13].pASSupport,
    &v19,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v19.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v19);
  if ( v9 )
  {
    v16 = *(_DWORD *)(v9 + 24);
    if ( (v16 & 0x3FFFFFF) != 0 )
    {
      *(_DWORD *)(v9 + 24) = v16 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9);
    }
  }
  return result;
}

