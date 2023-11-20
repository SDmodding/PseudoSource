// File Line: 30
// RVA: 0x6CA870
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::MovieClipLoader(Scaleform::GFx::AS2::MovieClipLoader *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::MovieClipLoader *v3; // rsi
  Scaleform::GFx::AS2::ASStringContext *v4; // rbx
  Scaleform::GFx::AS2::Object *v5; // rax

  v2 = penv;
  v3 = this;
  Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)&this->vfptr, penv);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipLoader::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipLoader::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v3->ProgressInfo.mHash.pTable = 0i64;
  v4 = &v2->StringContext;
  v5 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v4->pContext, ASBuiltin_MovieClipLoader);
  v3->vfptr->Set__proto__((Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr, v4, v5);
  if ( v3 != (Scaleform::GFx::AS2::MovieClipLoader *)-32i64 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
      v4,
      GAS_AsBcFunctionTable,
      1);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(v4, (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr);
}

// File Line: 61
// RVA: 0x704710
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadStart(Scaleform::GFx::AS2::MovieClipLoader *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::InteractiveObject *ptarget)
{
  Scaleform::GFx::InteractiveObject *v3; // rbp
  Scaleform::GFx::AS2::Environment *v4; // r15
  Scaleform::GFx::AS2::MovieClipLoader *v5; // r14
  Scaleform::GFx::ASStringNode *v6; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v7; // rsi
  Scaleform::GFx::CharacterHandle *v8; // rax
  Scaleform::GFx::ASString *v9; // rax
  int v10; // er8
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS2::Value *v13; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-40h]
  int v15; // [rsp+30h] [rbp-38h]
  int v16; // [rsp+34h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v18; // [rsp+78h] [rbp+10h]

  v3 = ptarget;
  v4 = penv;
  v5 = this;
  ++penv->Stack.pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v6 = (Scaleform::GFx::ASStringNode *)v4->Stack.pCurrent;
  result.pNode = v6;
  v18 = v6;
  v7 = 0i64;
  if ( v6 )
  {
    LOBYTE(v6->pData) = 7;
    if ( v3 )
    {
      v8 = v3->pNameHandle.pObject;
      if ( !v8 )
        v8 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v3->vfptr);
      v6->pManager = (Scaleform::GFx::ASStringManager *)v8;
      if ( v8 )
        ++v8->RefCount;
    }
    else
    {
      v6->pManager = 0i64;
    }
  }
  if ( v5 )
    v7 = (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr;
  v9 = Scaleform::GFx::AS2::Environment::CreateConstString(v4, &result, "onLoadStart");
  v10 = ((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) + 32 * v4->Stack.Pages.Data.Size - 32;
  if ( v7 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v15 = 1;
    v16 = v10;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v4, v7, v9, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
  }
  v11 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v13 = v4->Stack.pCurrent;
  if ( v13->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v13);
  --v4->Stack.pCurrent;
  if ( v4->Stack.pCurrent < v4->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
}

// File Line: 68
// RVA: 0x703F40
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadComplete(Scaleform::GFx::AS2::MovieClipLoader *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::InteractiveObject *ptarget, int status)
{
  int v4; // edi
  Scaleform::GFx::InteractiveObject *v5; // rbp
  Scaleform::GFx::AS2::Environment *v6; // r15
  Scaleform::GFx::AS2::MovieClipLoader *v7; // r14
  __int64 v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v10; // rsi
  Scaleform::GFx::CharacterHandle *v11; // rax
  Scaleform::GFx::ASString *v12; // rax
  int v13; // er8
  signed int v14; // edi
  Scaleform::GFx::ASStringNode *v15; // rcx
  bool v16; // zf
  Scaleform::GFx::AS2::Value *v17; // rcx
  Scaleform::GFx::AS2::Value *v18; // rcx
  Scaleform::GFx::AS2::Value *v19; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-40h]
  int v21; // [rsp+30h] [rbp-38h]
  int v22; // [rsp+34h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]
  __int64 v24; // [rsp+78h] [rbp+10h]

  v4 = status;
  v5 = ptarget;
  v6 = penv;
  v7 = this;
  ++penv->Stack.pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v8 = (__int64)v6->Stack.pCurrent;
  result.pNode = (Scaleform::GFx::ASStringNode *)v8;
  v24 = v8;
  if ( v8 )
  {
    *(_BYTE *)v8 = 4;
    *(_DWORD *)(v8 + 8) = v4;
  }
  ++v6->Stack.pCurrent;
  if ( v6->Stack.pCurrent >= v6->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v6->Stack);
  v9 = (Scaleform::GFx::ASStringNode *)v6->Stack.pCurrent;
  result.pNode = v9;
  v24 = (__int64)v9;
  v10 = 0i64;
  if ( v9 )
  {
    LOBYTE(v9->pData) = 7;
    if ( v5 )
    {
      v11 = v5->pNameHandle.pObject;
      if ( !v11 )
        v11 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v5->vfptr);
      v9->pManager = (Scaleform::GFx::ASStringManager *)v11;
      if ( v11 )
        ++v11->RefCount;
    }
    else
    {
      v9->pManager = 0i64;
    }
  }
  if ( v7 )
    v10 = (Scaleform::GFx::AS2::ObjectInterface *)&v7->vfptr;
  v12 = Scaleform::GFx::AS2::Environment::CreateConstString(v6, &result, "onLoadComplete");
  v13 = ((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) + 32 * v6->Stack.Pages.Data.Size - 32;
  v14 = 2;
  if ( v10 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v21 = 2;
    v22 = v13;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v6, v10, v12, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
  }
  v15 = result.pNode;
  v16 = result.pNode->RefCount == 1;
  --v15->RefCount;
  if ( v16 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  v17 = v6->Stack.pCurrent;
  if ( &v17[-2] >= v6->Stack.pPageStart )
  {
    if ( v17->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v17);
    --v6->Stack.pCurrent;
    v19 = v6->Stack.pCurrent;
    if ( v19->T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(v19);
    --v6->Stack.pCurrent;
  }
  else
  {
    do
    {
      v18 = v6->Stack.pCurrent;
      if ( v18->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v18);
      --v6->Stack.pCurrent;
      if ( v6->Stack.pCurrent < v6->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v6->Stack);
      --v14;
    }
    while ( v14 );
  }
}

// File Line: 76
// RVA: 0x7042C0
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadInit(Scaleform::GFx::AS2::MovieClipLoader *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::InteractiveObject *ptarget)
{
  Scaleform::GFx::InteractiveObject *v3; // rbp
  Scaleform::GFx::AS2::Environment *v4; // r15
  Scaleform::GFx::AS2::MovieClipLoader *v5; // r14
  Scaleform::GFx::ASStringNode *v6; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v7; // rsi
  Scaleform::GFx::CharacterHandle *v8; // rax
  Scaleform::GFx::ASString *v9; // rax
  int v10; // er8
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::AS2::Value *v13; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-40h]
  int v15; // [rsp+30h] [rbp-38h]
  int v16; // [rsp+34h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::ASStringNode *v18; // [rsp+78h] [rbp+10h]

  v3 = ptarget;
  v4 = penv;
  v5 = this;
  ++penv->Stack.pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v6 = (Scaleform::GFx::ASStringNode *)v4->Stack.pCurrent;
  result.pNode = v6;
  v18 = v6;
  v7 = 0i64;
  if ( v6 )
  {
    LOBYTE(v6->pData) = 7;
    if ( v3 )
    {
      v8 = v3->pNameHandle.pObject;
      if ( !v8 )
        v8 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v3->vfptr);
      v6->pManager = (Scaleform::GFx::ASStringManager *)v8;
      if ( v8 )
        ++v8->RefCount;
    }
    else
    {
      v6->pManager = 0i64;
    }
  }
  if ( v5 )
    v7 = (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr;
  v9 = Scaleform::GFx::AS2::Environment::CreateConstString(v4, &result, "onLoadInit");
  v10 = ((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) + 32 * v4->Stack.Pages.Data.Size - 32;
  if ( v7 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v15 = 1;
    v16 = v10;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v4, v7, v9, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
  }
  v11 = result.pNode;
  v12 = result.pNode->RefCount == 1;
  --v11->RefCount;
  if ( v12 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v11);
  v13 = v4->Stack.pCurrent;
  if ( v13->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v13);
  --v4->Stack.pCurrent;
  if ( v4->Stack.pCurrent < v4->Stack.pPageStart )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v4->Stack);
}

// File Line: 83
// RVA: 0x704100
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadError(Scaleform::GFx::AS2::MovieClipLoader *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::InteractiveObject *ptarget, const char *errorCode, int status)
{
  const char *v5; // rdi
  Scaleform::GFx::InteractiveObject *v6; // rbp
  Scaleform::GFx::AS2::Environment *v7; // r15
  Scaleform::GFx::AS2::MovieClipLoader *v8; // r14
  __int64 v9; // r8
  Scaleform::GFx::ASString *v10; // rdi
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rax
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v16; // rsi
  Scaleform::GFx::CharacterHandle *v17; // rax
  Scaleform::GFx::ASString *v18; // rax
  int v19; // er8
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-40h]
  int v22; // [rsp+30h] [rbp-38h]
  int v23; // [rsp+34h] [rbp-34h]
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]
  __int64 v25; // [rsp+78h] [rbp+10h]

  v5 = errorCode;
  v6 = ptarget;
  v7 = penv;
  v8 = this;
  ++penv->Stack.pCurrent;
  if ( penv->Stack.pCurrent >= penv->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
  v9 = (__int64)v7->Stack.pCurrent;
  result.pNode = (Scaleform::GFx::ASStringNode *)v9;
  v25 = v9;
  if ( v9 )
  {
    *(_BYTE *)v9 = 4;
    *(_DWORD *)(v9 + 8) = status;
  }
  v10 = Scaleform::GFx::AS2::Environment::CreateConstString(v7, &result, v5);
  ++v7->Stack.pCurrent;
  if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  v11 = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)v7->Stack.pCurrent;
  v25 = (__int64)v11;
  pcallback.vfptr = v11;
  if ( v11 )
  {
    LOBYTE(v11->__vecDelDtor) = 5;
    v12 = v10->pNode;
    v11->Invoke = (void (__fastcall *)(Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback *, Scaleform::GFx::AS2::Environment *, Scaleform::GFx::AS2::ObjectInterface *, Scaleform::GFx::AS2::FunctionRef *))v10->pNode;
    ++v12->RefCount;
  }
  v13 = result.pNode;
  v14 = result.pNode->RefCount == 1;
  --v13->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  ++v7->Stack.pCurrent;
  if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  v15 = (Scaleform::GFx::ASStringNode *)v7->Stack.pCurrent;
  result.pNode = v15;
  v25 = (__int64)v15;
  v16 = 0i64;
  if ( v15 )
  {
    LOBYTE(v15->pData) = 7;
    if ( v6 )
    {
      v17 = v6->pNameHandle.pObject;
      if ( !v17 )
        v17 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v6->vfptr);
      v15->pManager = (Scaleform::GFx::ASStringManager *)v17;
      if ( v17 )
        ++v17->RefCount;
    }
    else
    {
      v15->pManager = 0i64;
    }
  }
  if ( v8 )
    v16 = (Scaleform::GFx::AS2::ObjectInterface *)&v8->vfptr;
  v18 = Scaleform::GFx::AS2::Environment::CreateConstString(v7, &result, "onLoadError");
  v19 = ((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) + 32 * v7->Stack.Pages.Data.Size - 32;
  if ( v16 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v22 = 3;
    v23 = v19;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v7, v16, v18, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
  }
  v20 = result.pNode;
  v14 = result.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v14 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&v7->Stack);
}seNode(v20);
  Scaleform::GFx::AS2::PagedStack<Scaleform::G

// File Line: 92
// RVA: 0x704410
void __fastcall Scaleform::GFx::AS2::MovieClipLoader::NotifyOnLoadProgress(Scaleform::GFx::AS2::MovieClipLoader *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::InteractiveObject *ptarget, int loadedBytes, int totalBytes)
{
  int v5; // er12
  Scaleform::GFx::InteractiveObject *v6; // r14
  Scaleform::GFx::AS2::Environment *v7; // r13
  Scaleform::GFx::AS2::MovieClipLoader *v8; // r15
  int v9; // esi
  unsigned __int64 v10; // rax
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v11; // rdi
  unsigned __int64 v12; // rbx
  signed __int64 v13; // r11
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> >::TableType *v14; // r10
  Scaleform::String::DataDesc *v15; // rdx
  unsigned __int8 *v16; // rax
  int v17; // ecx
  int v18; // er8
  signed __int64 v19; // r11
  int *v20; // r11
  unsigned __int64 v21; // rax
  Scaleform::String::DataDesc *v22; // rax
  Scaleform::String::DataDesc *v23; // rax
  __int64 v24; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v25; // rsi
  Scaleform::GFx::CharacterHandle *v26; // rax
  Scaleform::GFx::ASString *v27; // rax
  int v28; // er8
  Scaleform::GFx::ASStringNode *v29; // rcx
  bool v30; // zf
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+28h] [rbp-28h]
  int v32; // [rsp+30h] [rbp-20h]
  int v33; // [rsp+34h] [rbp-1Ch]
  Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeRef key; // [rsp+38h] [rbp-18h]
  Scaleform::String ppath; // [rsp+90h] [rbp+40h]
  unsigned __int64 v36; // [rsp+98h] [rbp+48h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+50h]

  v5 = loadedBytes;
  v6 = ptarget;
  v7 = penv;
  v8 = this;
  v9 = totalBytes;
  if ( !ptarget )
    goto LABEL_21;
  Scaleform::String::String(&ppath);
  Scaleform::GFx::DisplayObject::GetAbsolutePath((Scaleform::GFx::DisplayObject *)&v6->vfptr, &ppath);
  if ( v8->ProgressInfo.mHash.pTable
    && (v10 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64),
        v11 = v8->ProgressInfo.mHash.pTable,
        v12 = v10 & v11->SizeMask,
        v13 = v10 & v11->SizeMask,
        v14 = &v11[2 * (v10 & v11->SizeMask) + 1],
        v14->EntryCount != -2i64)
    && v14->SizeMask == v12 )
  {
    v15 = ppath.pData;
    while ( 1 )
    {
      if ( v14->SizeMask == v12 )
      {
        v16 = (unsigned __int8 *)((v14[1].EntryCount & 0xFFFFFFFFFFFFFFFCui64) + 12);
        do
        {
          v17 = v16[(ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) - (v14[1].EntryCount & 0xFFFFFFFFFFFFFFFCui64)];
          v18 = *v16 - v17;
          if ( *v16 != v17 )
            break;
          ++v16;
        }
        while ( v17 );
        if ( !v18 )
          break;
      }
      v13 = v14->EntryCount;
      if ( v14->EntryCount == -1i64 )
        goto LABEL_18;
      v14 = &v11[2 * v13 + 1];
    }
    if ( v13 >= 0 )
    {
      v19 = (signed __int64)&v11[2 * (v13 + 1)];
      if ( v19 )
      {
        v20 = (int *)(v19 + 8);
        if ( v20 )
        {
          *v20 = v5;
          v20[1] = v9;
          goto LABEL_19;
        }
      }
    }
  }
  else
  {
    v15 = ppath.pData;
  }
LABEL_18:
  v36 = __PAIR__(v9, v5);
  key.pFirst = &ppath;
  key.pSecond = (Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc *)&v36;
  v21 = Scaleform::String::BernsteinHashFunctionCIS(
          (const void *)(((unsigned __int64)v15 & 0xFFFFFFFFFFFFFFFCui64) + 12),
          *(_QWORD *)((unsigned __int64)v15 & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
          0x1505ui64);
  Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF>>::add<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeRef>(
    (Scaleform::HashSetBase<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,2>,Scaleform::HashsetCachedNodeEntry<Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>,Scaleform::StringLH_HashNode<Scaleform::GFx::AS2::MovieClipLoader::ProgressDesc,Scaleform::String::NoCaseHashFunctor>::NodeHashF> > *)&v8->ProgressInfo.mHash.pTable,
    &v8->ProgressInfo,
    &key,
    v21);
LABEL_19:
  if ( !_InterlockedDecrement((volatile signed __int32 *)((ppath.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
LABEL_21:
  ++v7->Stack.pCurrent;
  if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  v22 = (Scaleform::String::DataDesc *)v7->Stack.pCurrent;
  ppath.pData = v22;
  v36 = (unsigned __int64)v22;
  if ( v22 )
  {
    LOBYTE(v22->Size) = 4;
    v22->RefCount = v9;
  }
  ++v7->Stack.pCurrent;
  if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  v23 = (Scaleform::String::DataDesc *)v7->Stack.pCurrent;
  ppath.pData = v23;
  v36 = (unsigned __int64)v23;
  if ( v23 )
  {
    LOBYTE(v23->Size) = 4;
    v23->RefCount = v5;
  }
  ++v7->Stack.pCurrent;
  if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
    Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
  v24 = (__int64)v7->Stack.pCurrent;
  ppath.pData = (Scaleform::String::DataDesc *)v24;
  v36 = v24;
  v25 = 0i64;
  if ( v24 )
  {
    *(_BYTE *)v24 = 7;
    if ( v6 )
    {
      v26 = v6->pNameHandle.pObject;
      if ( !v26 )
        v26 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v6->vfptr);
      *(_QWORD *)(v24 + 8) = v26;
      if ( v26 )
        ++v26->RefCount;
    }
    else
    {
      *(_QWORD *)(v24 + 8) = 0i64;
    }
  }
  if ( v8 )
    v25 = (Scaleform::GFx::AS2::ObjectInterface *)&v8->vfptr;
  v27 = Scaleform::GFx::AS2::Environment::CreateConstString(v7, &result, "onLoadProgress");
  v28 = ((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) + 32 * v7->Stack.Pages.Data.Size - 32;
  if ( v25 )
  {
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)`Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessage'::`4'::LocalInvokeCallback::`vftable';
    v32 = 3;
    v33 = v28;
    Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v7, v25, v27, &pcallback);
    pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
  }
  v29 = result.pNode;
  v30 = result.pNode->RefCount == 1;
  --v29->RefCount;
  if ( v30 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v29);
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Pop3(&v7->Stack);
}

// File Line: 119
// RVA: 0x6B3740
void __fastcall Scaleform::GFx::AS2::MovieClipLoaderProto::GetProgress(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  __int64 v3; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  int *v5; // r14
  signed __int64 v6; // rbp
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::Object *v9; // rsi
  unsigned int v10; // er9
  Scaleform::GFx::AS2::Environment *v11; // r8
  Scaleform::GFx::AS2::Value *v12; // r10
  unsigned __int64 v13; // rax
  __int64 v14; // r15
  unsigned __int64 v15; // rbp
  signed __int64 v16; // r11
  signed __int64 *v17; // r10
  unsigned __int8 *v18; // rax
  int v19; // ecx
  int v20; // er8
  signed __int64 v21; // r11
  int v22; // eax
  int v23; // eax
  Scaleform::GFx::ASStringNode *v24; // rcx
  bool v25; // zf
  unsigned int v26; // eax
  Scaleform::GFx::AS2::Value val; // [rsp+28h] [rbp-70h]
  Scaleform::GFx::AS2::Value v28; // [rsp+48h] [rbp-50h]
  Scaleform::String v29; // [rsp+A0h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+A8h] [rbp+10h]
  Scaleform::GFx::AS2::Object *v31; // [rsp+B0h] [rbp+18h]

  v1 = fn;
  if ( fn->NArgs >= 1 )
  {
    v2 = fn->Result;
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    v2->T.Type = 0;
    if ( (*(unsigned int (__cdecl **)(Scaleform::GFx::AS2::ObjectInterface *))&v1->ThisPtr->vfptr->gap8[8])(v1->ThisPtr) == 25 )
    {
      v4 = v1->ThisPtr;
      v5 = 0i64;
      v6 = (signed __int64)&v4[-2];
      if ( !v4 )
        v6 = 0i64;
      v29.pData = (Scaleform::String::DataDesc *)v1->Env->StringContext.pContext->pHeap;
      v7 = (Scaleform::GFx::AS2::Object *)(*(__int64 (__fastcall **)(__int64, signed __int64))(v29.pData->Size + 80))(
                                            v3,
                                            96i64);
      v31 = v7;
      if ( v7 )
      {
        Scaleform::GFx::AS2::Object::Object(v7, v1->Env);
        v9 = v8;
      }
      else
      {
        v9 = 0i64;
      }
      v31 = v9;
      v10 = v1->FirstArgBottomIndex;
      v11 = v1->Env;
      v12 = 0i64;
      if ( v10 <= 32 * ((unsigned int)v11->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v11->Stack.pCurrent - (char *)v11->Stack.pPageStart) >> 5) )
        v12 = &v11->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
      Scaleform::GFx::AS2::Value::ToString(v12, &result, v11, -1);
      Scaleform::String::String(&v29, result.pNode->pData);
      if ( *(_QWORD *)(v6 + 96) )
      {
        v13 = Scaleform::String::BernsteinHashFunctionCIS(
                (const void *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12),
                *(_QWORD *)(v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) & 0x7FFFFFFFFFFFFFFFi64,
                0x1505ui64);
        v14 = *(_QWORD *)(v6 + 96);
        v15 = v13 & *(_QWORD *)(v14 + 8);
        v16 = v13 & *(_QWORD *)(v14 + 8);
        v17 = (signed __int64 *)(32 * (v13 & *(_QWORD *)(v14 + 8)) + v14 + 16);
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
                if ( *v18 != v19 )
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
            v17 = (signed __int64 *)(32 * v16 + v14 + 16);
          }
          if ( v16 >= 0 )
          {
            v21 = v14 + 32 * (v16 + 1);
            if ( v21 )
              v5 = (int *)(v21 + 8);
          }
        }
      }
LABEL_23:
      if ( !_InterlockedDecrement((volatile signed __int32 *)((v29.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
        ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      if ( v5 )
      {
        v22 = *v5;
        val.T.Type = 4;
        val.NV.Int32Value = v22;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
          &v1->Env->StringContext,
          "bytesLoaded",
          &val);
        if ( val.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&val);
        v23 = v5[1];
        v28.T.Type = 4;
        v28.NV.Int32Value = v23;
        Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
          (Scaleform::GFx::AS2::ObjectInterface *)&v9->vfptr,
          &v1->Env->StringContext,
          "bytesTotal",
          &v28);
        if ( v28.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v28);
      }
      Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v9);
      v24 = result.pNode;
      v25 = result.pNode->RefCount == 1;
      --v24->RefCount;
      if ( v25 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v24);
      if ( v9 )
      {
        v26 = v9->RefCount;
        if ( v26 & 0x3FFFFFF )
        {
          v9->RefCount = v26 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v9->vfptr);
        }
      }
    }
  }
}

// File Line: 145
// RVA: 0x6B3A30
void __fastcall Scaleform::GFx::AS2::MovieClipLoaderProto::LoadClip(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rsi
  Scaleform::GFx::AS2::Value *v2; // rbx
  Scaleform::GFx::AS2::MovieClipLoader *pmovieClipLoader; // rbp
  Scaleform::GFx::AS2::ObjectInterface *v4; // rax
  unsigned int v5; // er9
  Scaleform::GFx::AS2::Environment *v6; // r8
  Scaleform::GFx::AS2::Value *v7; // r10
  unsigned int v8; // er9
  Scaleform::GFx::AS2::Environment *v9; // r8
  Scaleform::GFx::AS2::Value *v10; // r10
  unsigned __int64 v11; // rax
  __int64 v12; // rcx
  signed __int64 v13; // rdx
  Scaleform::GFx::CharacterHandle *v14; // rcx
  Scaleform::GFx::DisplayObject *v15; // rax
  Scaleform::GFx::InteractiveObject *v16; // rbx
  Scaleform::GFx::AS2::Value *v17; // r10
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::InteractiveObject *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  bool v21; // zf
  unsigned int v22; // er9
  Scaleform::GFx::AS2::Environment *v23; // r8
  Scaleform::GFx::AS2::Value *v24; // r10
  const char ***v25; // rdi
  unsigned int v26; // eax
  int v27; // edi
  Scaleform::GFx::ASStringNode *v28; // rcx
  unsigned int v29; // er10
  Scaleform::GFx::AS2::Environment *v30; // r8
  Scaleform::GFx::AS2::Value *v31; // r11
  const char ***v32; // rax
  Scaleform::GFx::ASStringNode *v33; // rcx
  Scaleform::GFx::AS2::Value *v34; // rdi
  Scaleform::GFx::ASStringNode *v35; // rcx
  Scaleform::GFx::ASString result; // [rsp+70h] [rbp+8h]
  Scaleform::GFx::InteractiveObject *v37; // [rsp+78h] [rbp+10h]
  Scaleform::GFx::ASString v38; // [rsp+80h] [rbp+18h]
  char *ptail; // [rsp+88h] [rbp+20h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  if ( v1->NArgs < 2 )
    return;
  pmovieClipLoader = 0i64;
  if ( (*(unsigned int (**)(void))&v1->ThisPtr->vfptr->gap8[8])() == 25 )
  {
    v4 = v1->ThisPtr;
    if ( v4 )
      pmovieClipLoader = (Scaleform::GFx::AS2::MovieClipLoader *)&v4[-2];
  }
  v5 = v1->FirstArgBottomIndex;
  v6 = v1->Env;
  v7 = 0i64;
  if ( v5 <= 32 * ((unsigned int)v6->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5) )
    v7 = &v6->Stack.Pages.Data.Data[v5 >> 5]->Values[v5 & 0x1F];
  Scaleform::GFx::AS2::Value::ToString(v7, &result, v6, -1);
  v37 = 0i64;
  v8 = v1->FirstArgBottomIndex - 1;
  v9 = v1->Env;
  v10 = 0i64;
  if ( v8 <= 32 * ((unsigned int)v9->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5) )
    v10 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
  v11 = v9->Stack.Pages.Data.Size;
  v12 = (_QWORD)((char *)v9->Stack.pCurrent - (char *)v9->Stack.pPageStart) >> 5;
  if ( v10->T.Type == 7 )
  {
    v13 = 0i64;
    if ( v8 <= 32 * ((signed int)v11 - 1) + (signed int)v12 )
      v13 = (signed __int64)&v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    if ( *(_BYTE *)v13 == 7
      && v9
      && (v14 = *(Scaleform::GFx::CharacterHandle **)(v13 + 8)) != 0i64
      && (v15 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v14, v9->Target->pASRoot->pMovieImpl)) != 0i64 )
    {
      v16 = 0i64;
      if ( SLOBYTE(v15->Flags) < 0 )
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
    if ( v8 <= 32 * ((signed int)v11 - 1) + (signed int)v12 )
      v17 = &v9->Stack.Pages.Data.Data[v8 >> 5]->Values[v8 & 0x1F];
    v18 = Scaleform::GFx::AS2::Value::ToString(v17, &v38, v9, -1);
    v19 = Scaleform::GFx::AS2::Environment::FindTarget(v1->Env, v18, 0);
    v16 = v19;
    if ( v19 )
      ++v19->RefCount;
    v37 = v19;
    v20 = v38.pNode;
    v21 = v38.pNode->RefCount == 1;
    --v20->RefCount;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  }
  if ( v16 )
  {
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
      (Scaleform::GFx::AS2::MovieRoot *)v1->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      v16,
      result.pNode->pData,
      0,
      pmovieClipLoader);
  }
  else
  {
    v22 = v1->FirstArgBottomIndex - 1;
    v23 = v1->Env;
    v24 = 0i64;
    if ( v22 <= 32 * ((unsigned int)v23->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v23->Stack.pCurrent - (char *)v23->Stack.pPageStart) >> 5) )
      v24 = &v23->Stack.Pages.Data.Data[v22 >> 5]->Values[v22 & 0x1F];
    v25 = (const char ***)Scaleform::GFx::AS2::Value::ToString(v24, &v38, v23, -1);
    v26 = Scaleform::GFx::DisplayObjectBase::GetVersion((Scaleform::GFx::DisplayObjectBase *)&v1->Env->Target->vfptr);
    v27 = Scaleform::GFx::AS2::MovieRoot::ParseLevelName(**v25, (const char **)&ptail, v26 > 6);
    v28 = v38.pNode;
    v21 = v38.pNode->RefCount == 1;
    --v28->RefCount;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v28);
    if ( v27 == -1 )
      goto LABEL_40;
    v29 = v1->FirstArgBottomIndex - 1;
    v30 = v1->Env;
    v31 = 0i64;
    if ( v29 <= 32 * ((unsigned int)v30->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v30->Stack.pCurrent - (char *)v30->Stack.pPageStart) >> 5) )
      v31 = &v30->Stack.Pages.Data.Data[v29 >> 5]->Values[v29 & 0x1F];
    v32 = (const char ***)Scaleform::GFx::AS2::Value::ToString(v31, &v38, v30, -1);
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntry(
      (Scaleform::GFx::AS2::MovieRoot *)v1->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      **v32,
      result.pNode->pData,
      v1->Env,
      0,
      pmovieClipLoader);
    v33 = v38.pNode;
    v21 = v38.pNode->RefCount == 1;
    --v33->RefCount;
    if ( v21 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v33);
  }
  v34 = v1->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v1->Result);
  v34->T.Type = 2;
  v34->V.BooleanValue = 1;
LABEL_40:
  if ( v16 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v16->vfptr);
  v35 = result.pNode;
  v21 = result.pNode->RefCount == 1;
  --v35->RefCount;
  if ( v21 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v35);
}

// File Line: 179
// RVA: 0x6B3DD0
void __fastcall Scaleform::GFx::AS2::MovieClipLoaderProto::UnloadClip(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rdi
  Scaleform::GFx::AS2::Value *v2; // rbx
  unsigned int v3; // er9
  Scaleform::GFx::AS2::Environment *v4; // r10
  Scaleform::GFx::AS2::Value *v5; // r8
  unsigned __int64 v6; // rax
  __int64 v7; // rcx
  signed __int64 v8; // rdx
  Scaleform::GFx::CharacterHandle *v9; // rcx
  Scaleform::GFx::DisplayObject *v10; // rax
  Scaleform::GFx::InteractiveObject *v11; // rbx
  Scaleform::GFx::AS2::Value *v12; // r8
  unsigned __int8 v13; // al
  Scaleform::GFx::AS2::Value *v14; // r11
  __int64 v15; // rcx
  bool v16; // cf
  bool v17; // zf
  unsigned __int64 v18; // rax
  Scaleform::GFx::ASMovieRootBase *v19; // rbx
  int v20; // eax
  unsigned int v21; // edx
  Scaleform::GFx::MovieImpl *v22; // r8
  unsigned __int64 v23; // r9
  __int64 v24; // rcx
  Scaleform::GFx::MovieImpl::LevelInfo *v25; // r8
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::InteractiveObject *v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rcx
  Scaleform::GFx::AS2::Value *v29; // rdi
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v1 = fn;
  v2 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v2->T.Type = 2;
  v2->V.BooleanValue = 0;
  if ( v1->NArgs < 1 )
    return;
  v3 = v1->FirstArgBottomIndex;
  v4 = v1->Env;
  v5 = 0i64;
  if ( v3 <= 32 * ((unsigned int)v4->Stack.Pages.Data.Size - 1)
           + (unsigned int)((_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5) )
    v5 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
  v6 = v4->Stack.Pages.Data.Size;
  v7 = (_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5;
  if ( v5->T.Type == 7 )
  {
    v8 = 0i64;
    if ( v3 <= 32 * ((signed int)v6 - 1) + (signed int)v7 )
      v8 = (signed __int64)&v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    if ( *(_BYTE *)v8 == 7 )
    {
      if ( v4 )
      {
        v9 = *(Scaleform::GFx::CharacterHandle **)(v8 + 8);
        if ( v9 )
        {
          v10 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v9, v4->Target->pASRoot->pMovieImpl);
          if ( v10 )
          {
            v11 = 0i64;
            if ( SLOBYTE(v10->Flags) < 0 )
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
    if ( v3 <= 32 * ((signed int)v6 - 1) + (signed int)v7 )
      v12 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v13 = v12->T.Type - 3;
    v14 = 0i64;
    v15 = (_QWORD)((char *)v4->Stack.pCurrent - (char *)v4->Stack.pPageStart) >> 5;
    v16 = v13 < 1u;
    v17 = v13 == 1;
    v18 = v4->Stack.Pages.Data.Size;
    if ( !v16 && !v17 )
    {
      if ( v3 <= 32 * ((signed int)v18 - 1) + (signed int)v15 )
        v14 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
      v26 = Scaleform::GFx::AS2::Value::ToString(v14, &result, v1->Env, -1);
      v27 = Scaleform::GFx::AS2::Environment::FindTarget(v1->Env, v26, 0);
      v11 = v27;
      if ( v27 )
        ++v27->RefCount;
      v28 = result.pNode;
      v17 = result.pNode->RefCount == 1;
      --v28->RefCount;
      if ( v17 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v28);
      goto LABEL_35;
    }
    if ( v3 <= 32 * ((signed int)v18 - 1) + (signed int)v15 )
      v14 = &v4->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
    v19 = v4->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v20 = Scaleform::GFx::AS2::Value::ToInt32(v14, v1->Env);
    v21 = 0;
    v22 = v19->pMovieImpl;
    v23 = v22->MovieLevels.Data.Size;
    if ( v23 )
    {
      v24 = 0i64;
      v25 = v22->MovieLevels.Data.Data;
      while ( v25[v24].Level != v20 )
      {
        v24 = ++v21;
        if ( v21 >= v23 )
          goto LABEL_27;
      }
      v11 = v25[v21].pSprite.pObject;
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
      (Scaleform::GFx::AS2::MovieRoot *)v1->Env->Target->pASRoot->pMovieImpl->pASMovieRoot.pObject,
      v11,
      &customWorldMapCaption,
      0,
      0i64);
    v29 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v29);
    v29->T.Type = 2;
    v29->V.BooleanValue = 1;
  }
  if ( v11 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v11->vfptr);
}

// File Line: 223
// RVA: 0x6F9720
void __fastcall Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::GlobalCtor(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::ObjectInterface *v2; // rcx
  Scaleform::GFx::AS2::ObjectInterface *v3; // rdi
  Scaleform::GFx::AS2::ObjectInterface *v4; // r8
  Scaleform::GFx::AS2::Object *v5; // rdi
  Scaleform::GFx::AS2::Value *v6; // rbx

  v1 = fn;
  v2 = fn->ThisPtr;
  if ( !v2
    || (*(unsigned int (**)(void))&v2->vfptr->gap8[8])() != 25
    || ((unsigned __int8 (*)(void))v1->ThisPtr->vfptr->IsBuiltinPrototype)() )
  {
    v6 = v1->Result;
    Scaleform::GFx::AS2::Value::DropRefs(v6);
    v6->T.Type = 1;
  }
  else
  {
    v3 = v1->ThisPtr;
    v4 = 0i64;
    if ( v3 )
    {
      v5 = (Scaleform::GFx::AS2::Object *)&v3[-2];
      if ( v5 )
        v4 = (Scaleform::GFx::AS2::ObjectInterface *)&v5->vfptr;
    }
    else
    {
      v5 = 0i64;
    }
    Scaleform::GFx::AS2::AsBroadcaster::AddListener(v1->Env, v4, v4);
    Scaleform::GFx::AS2::Value::SetAsObject(v1->Result, v5);
  }
}

// File Line: 236
// RVA: 0x6E0680
void __fastcall Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::CreateNewObject(Scaleform::GFx::AS2::MovieClipLoaderCtorFunction *this, Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Environment *v2; // rbx
  Scaleform::GFx::AS2::MovieClipLoader *v3; // rax

  v2 = penv;
  v3 = (Scaleform::GFx::AS2::MovieClipLoader *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::MovieClipLoaderCtorFunction *, signed __int64))penv->StringContext.pContext->pHeap->vfptr->Alloc)(
                                                 this,
                                                 104i64);
  if ( v3 )
    Scaleform::GFx::AS2::MovieClipLoader::MovieClipLoader(v3, v2);
}

// File Line: 241
// RVA: 0x70DEB0
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // r14
  Scaleform::GFx::AS2::FunctionRef *v3; // rsi
  Scaleform::GFx::AS2::Object *v4; // rax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v5; // rcx
  Scaleform::GFx::AS2::FunctionObject *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // r15
  unsigned int v8; // eax
  __int64 v9; // rdi
  Scaleform::GFx::AS2::Object *v10; // rbx
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v11; // rcx
  unsigned int v12; // eax
  Scaleform::MemoryHeap *v13; // rbx
  Scaleform::GFx::AS2::Object *v14; // rbx
  Scaleform::GFx::ASStringNode *v15; // rax
  Scaleform::GFx::AS2::LocalFrame *v16; // rdx
  int v17; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+48h] [rbp-38h]
  Scaleform::GFx::AS2::Value v20; // [rsp+58h] [rbp-28h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+C8h] [rbp+48h]
  Scaleform::MemoryHeap *flags; // [rsp+D0h] [rbp+50h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v23; // [rsp+D8h] [rbp+58h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  flags = pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::Object *)flags->vfptr->Alloc((Scaleform::MemoryHeap *)result, 104ui64, 0i64);
  v6 = (Scaleform::GFx::AS2::FunctionObject *)v4;
  v23 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v4;
  if ( v4 )
  {
    Scaleform::GFx::AS2::Object::Object(v4, &psc);
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::CFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6[1].vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::GlobalCtor;
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc.pContext, ASBuiltin_Function);
    if ( !v6->pProto.pObject )
    {
      LOBYTE(objproto.pObject) = 3;
      v20.T.Type = 10;
      v6->vfptr->SetMemberRaw(
        (Scaleform::GFx::AS2::ObjectInterface *)&v6->vfptr,
        &psc,
        (Scaleform::GFx::ASString *)&psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v20,
        (Scaleform::GFx::AS2::PropFlags *)&objproto);
      if ( v20.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v20);
    }
    if ( v7 )
      v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
    v5 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->pProto.pObject->vfptr;
    if ( v5 )
    {
      v8 = v5->RefCount;
      if ( v8 & 0x3FFFFFF )
      {
        v5->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
      }
    }
    v6->pProto.pObject = v7;
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MovieClipLoaderCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  }
  else
  {
    v6 = 0i64;
  }
  v3->Flags = 0;
  v3->Function = v6;
  v3->pLocalFrame = 0i64;
  v23 = (Scaleform::Ptr<Scaleform::GFx::AS2::Object> *)v2->pHeap;
  v9 = ((__int64 (__fastcall *)(Scaleform::GFx::AS2::RefCountBaseGC<323> *, signed __int64, _QWORD))v23->pObject->pWatchpoints)(
         v5,
         168i64,
         0i64);
  if ( v9 )
  {
    v10 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Object::Object((Scaleform::GFx::AS2::Object *)v9, &psc);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::MovieClipLoader::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::MovieClipLoader::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    objproto.pObject = (Scaleform::GFx::AS2::Object *)(v9 + 96);
    flags = (Scaleform::MemoryHeap *)(v9 + 96);
    *(_QWORD *)(v9 + 96) = 0i64;
    if ( !*(_QWORD *)(v9 + 40) )
    {
      LOBYTE(objproto.pObject) = 3;
      v20.T.Type = 10;
      (*(void (__fastcall **)(__int64, Scaleform::GFx::AS2::ASStringContext *, Scaleform::GFx::MovieImpl **, Scaleform::GFx::AS2::Value *, Scaleform::Ptr<Scaleform::GFx::AS2::Object> *))(*(_QWORD *)(v9 + 32) + 80i64))(
        v9 + 32,
        &psc,
        &psc.pContext->pMovieRoot->pASMovieRoot.pObject[23].pMovieImpl,
        &v20,
        &objproto);
      if ( v20.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v20);
    }
    if ( v10 )
      v10->RefCount = (v10->RefCount + 1) & 0x8FFFFFFF;
    v11 = *(Scaleform::GFx::AS2::RefCountBaseGC<323> **)(v9 + 40);
    if ( v11 )
    {
      v12 = v11->RefCount;
      if ( v12 & 0x3FFFFFF )
      {
        v11->RefCount = v12 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
    *(_QWORD *)(v9 + 40) = v10;
    v13 = (Scaleform::MemoryHeap *)(v9 + 104);
    flags = v13;
    v13->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
    LOBYTE(v13->SelfSize) = 0;
    v13->pPrev = 0i64;
    v13->pNext = 0i64;
    *(_BYTE *)(v9 + 152) = 0;
    *(_QWORD *)(v9 + 136) = 0i64;
    *(_QWORD *)(v9 + 144) = 0i64;
    *(_QWORD *)(v9 + 160) = 0i64;
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipLoader,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipLoader,Scaleform::GFx::AS2::Environment>::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v13->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::MovieClipLoader,Scaleform::GFx::AS2::Environment>::`vftable';
    Scaleform::GFx::AS2::GASPrototypeBase::Init(
      (Scaleform::GFx::AS2::GASPrototypeBase *)(v9 + 104),
      (Scaleform::GFx::AS2::Object *)v9,
      &psc,
      v3);
    *(_QWORD *)v9 = &Scaleform::GFx::AS2::MovieClipLoaderProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    *(_QWORD *)(v9 + 32) = &Scaleform::GFx::AS2::MovieClipLoaderProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v13->vfptr = (Scaleform::MemoryHeapVtbl *)&Scaleform::GFx::AS2::MovieClipLoaderProto::`vftable';
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
  v23 = &objproto;
  if ( v9 )
    *(_DWORD *)(v9 + 24) = (*(_DWORD *)(v9 + 24) + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v9;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_MovieClipLoader,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v14 = v2->pGlobal.pObject;
  v20.T.Type = 8;
  v20.V.FunctionValue.Flags = 0;
  v15 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v20.V.pStringNode = v15;
  if ( v15 )
  {
    ++v15->RefCount;
    v15->RefCount &= 0x8FFFFFFF;
  }
  v20.V.FunctionValue.pLocalFrame = 0i64;
  v16 = v3->pLocalFrame;
  if ( v16 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v20.NV.8,
      v16,
      v3->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v14->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v14->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[13].pASSupport,
    &v20,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v20.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v20);
  if ( v9 )
  {
    v17 = *(_DWORD *)(v9 + 24);
    if ( v17 & 0x3FFFFFF )
    {
      *(_DWORD *)(v9 + 24) = v17 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)v9);
    }
  }
  return v3;
}

