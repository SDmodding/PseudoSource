// File Line: 45
// RVA: 0x6DBAC0
void __fastcall Scaleform::GFx::AS2::Selection::BroadcastOnSetFocus(Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::InteractiveObject *pOldFocus, Scaleform::GFx::InteractiveObject *pNewFocus, unsigned int controllerIdx)
{
  signed int v4; // esi
  Scaleform::GFx::InteractiveObject *v5; // r15
  Scaleform::GFx::InteractiveObject *v6; // r13
  Scaleform::GFx::AS2::Environment *v7; // r14
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::ObjectInterface *v9; // r12
  __int64 v10; // rdi
  Scaleform::GFx::AS2::Value *v11; // rax
  char v12; // si
  Scaleform::GFx::ASStringNode *v13; // rax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v14; // rbx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rax
  char v17; // si
  Scaleform::GFx::ASStringNode *v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASStringNode *v20; // rax
  Scaleform::GFx::ASString *v21; // rax
  int v22; // er8
  Scaleform::GFx::ASStringNode *v23; // rcx
  bool v24; // zf
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+8h] [rbp-31h]
  Scaleform::GFx::AS2::Value v; // [rsp+18h] [rbp-21h]
  Scaleform::GFx::AS2::Value v27; // [rsp+38h] [rbp-1h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+67h]

  v4 = controllerIdx;
  v5 = pNewFocus;
  v6 = pOldFocus;
  v7 = penv;
  v27.T.Type = 0;
  if ( penv->StringContext.pContext->pGlobal.pObject->vfptr->GetMemberRaw(
         (Scaleform::GFx::AS2::ObjectInterface *)&penv->StringContext.pContext->pGlobal.pObject->vfptr,
         &penv->StringContext,
         (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[12],
         &v27) )
  {
    v8 = Scaleform::GFx::AS2::Value::ToObject(&v27, v7);
    if ( v8 )
    {
      v9 = (Scaleform::GFx::AS2::ObjectInterface *)&v8->vfptr;
      if ( v8 != (Scaleform::GFx::AS2::Object *)-32i64 )
      {
        v10 = 2i64;
        if ( v7->StringContext.pContext->GFxExtensions.Value == 1 )
        {
          ++v7->Stack.pCurrent;
          if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
          v11 = v7->Stack.pCurrent;
          result.pNode = (Scaleform::GFx::ASStringNode *)v11;
          pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)v11;
          if ( v11 )
          {
            v11->T.Type = 3;
            v11->NV.NumberValue = (double)v4;
          }
          v10 = 3i64;
        }
        if ( v5 )
        {
          v12 = 7;
          v.T.Type = 7;
          v13 = (Scaleform::GFx::ASStringNode *)v5->pNameHandle.pObject;
          if ( !v13 )
            v13 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v5->vfptr);
          v.V.pStringNode = v13;
          if ( v13 )
            ++LODWORD(v13->pData);
          v14 = &v7->Stack;
          ++v14->pCurrent;
          if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
          v15 = (Scaleform::GFx::ASStringNode *)v14->pCurrent;
          result.pNode = v15;
          pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)v15;
          if ( v15 )
          {
            Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v15, &v, v10);
            v12 = v.T.Type;
          }
          if ( (unsigned __int8)v12 >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
        else
        {
          v14 = &v7->Stack;
          ++v14->pCurrent;
          if ( v7->Stack.pCurrent >= v7->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&v7->Stack);
          v16 = (Scaleform::GFx::ASStringNode *)v14->pCurrent;
          result.pNode = v16;
          pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)v16;
          if ( v16 )
            LOBYTE(v16->pData) = 1;
        }
        if ( v6 )
        {
          v17 = 7;
          v.T.Type = 7;
          v18 = (Scaleform::GFx::ASStringNode *)v6->pNameHandle.pObject;
          if ( !v18 )
            v18 = (Scaleform::GFx::ASStringNode *)Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&v6->vfptr);
          v.V.pStringNode = v18;
          if ( v18 )
            ++LODWORD(v18->pData);
          ++v14->pCurrent;
          if ( v14->pCurrent >= v14->pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v14);
          v19 = (Scaleform::GFx::ASStringNode *)v14->pCurrent;
          result.pNode = v19;
          pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)v19;
          if ( v19 )
          {
            Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v19, &v, v10);
            v17 = v.T.Type;
          }
          if ( (unsigned __int8)v17 >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
        else
        {
          ++v14->pCurrent;
          if ( v14->pCurrent >= v14->pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v14);
          v20 = (Scaleform::GFx::ASStringNode *)v14->pCurrent;
          result.pNode = v20;
          pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)v20;
          if ( v20 )
            LOBYTE(v20->pData) = 1;
        }
        v21 = Scaleform::GFx::AS2::Environment::CreateConstString(v7, &result, "onSetFocus");
        v22 = ((_QWORD)((char *)v14->pCurrent - (char *)v14->pPageStart) >> 5) - 32 + 32 * v14->Pages.Data.Size;
        Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(v7, v9, v21, &pcallback);
        pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable';
        v23 = result.pNode;
        v24 = result.pNode->RefCount == 1;
        --v23->RefCount;
        if ( v24 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        for ( ; (_DWORD)v10; LODWORD(v10) = v10 - 1 )
        {
          if ( v14->pCurrent->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v14->pCurrent);
          --v14->pCurrent;
          if ( v14->pCurrent < v14->pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v14);
        }
      }
    }
  }
  if ( v27.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v27);
}

// File Line: 73
// RVA: 0x6E29A0
void __fastcall Scaleform::GFx::AS2::Selection::DoTransferFocus(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r10
  Scaleform::GFx::AS2::FnCall *v2; // rdi
  Scaleform::GFx::InteractiveObject *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // r9
  Scaleform::GFx::MovieImpl *v5; // r14
  unsigned int v6; // edx
  double v7; // xmm0_8
  Scaleform::GFx::AS2::Environment *v8; // rdx
  unsigned __int64 v9; // r8
  Scaleform::GFx::AS2::Value *v10; // r9
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Environment *v12; // r9
  unsigned int v13; // er10
  unsigned int v14; // esi
  signed __int64 v15; // r8
  Scaleform::GFx::CharacterHandle *v16; // rcx
  Scaleform::GFx::DisplayObject *v17; // rax

  v1 = fn->Env;
  v2 = fn;
  v3 = 0i64;
  v4 = 0i64;
  v5 = v1->Target->pASRoot->pMovieImpl;
  v6 = fn->FirstArgBottomIndex - 1;
  if ( v6 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
           + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[(unsigned __int64)v6 >> 5]->Values[v6 & 0x1F];
  v7 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v8 = v2->Env;
  v9 = (unsigned int)(v2->FirstArgBottomIndex - 2);
  v10 = 0i64;
  if ( (unsigned int)v9 <= 32 * (LODWORD(v8->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
    v10 = &v8->Stack.Pages.Data.Data[v9 >> 5]->Values[(LOBYTE(v2->FirstArgBottomIndex) - 2) & 0x1F];
  v11 = Scaleform::GFx::AS2::Value::ToUInt32(v10, v8);
  v12 = v2->Env;
  v13 = v2->FirstArgBottomIndex;
  v14 = v11;
  v15 = 0i64;
  if ( v13 <= 32 * (LODWORD(v12->Stack.Pages.Data.Size) - 1)
            + (unsigned int)((_QWORD)((char *)v12->Stack.pCurrent - (char *)v12->Stack.pPageStart) >> 5) )
    v15 = (signed __int64)&v12->Stack.Pages.Data.Data[(unsigned __int64)v13 >> 5]->Values[v13 & 0x1F];
  if ( *(_BYTE *)v15 == 7 )
  {
    if ( v12 )
    {
      v16 = *(Scaleform::GFx::CharacterHandle **)(v15 + 8);
      if ( v16 )
      {
        v17 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v16, v12->Target->pASRoot->pMovieImpl);
        if ( v17 )
        {
          if ( SLOBYTE(v17->Flags) < 0 )
            v3 = (Scaleform::GFx::InteractiveObject *)v17;
        }
      }
    }
  }
  Scaleform::GFx::MovieImpl::TransferFocus(v5, v3, v14, (Scaleform::GFx::FocusMovedType)v7);
}

// File Line: 86
// RVA: 0x70B310
void __usercall Scaleform::GFx::AS2::Selection::QueueSetFocus(Scaleform::GFx::AS2::Environment *penv@<rcx>, Scaleform::GFx::InteractiveObject *pNewFocus@<rdx>, unsigned int controllerIdx@<r8d>, Scaleform::GFx::FocusMovedType fmt@<r9d>, __int64 a5@<r12>, __int64 a6@<r13>)
{
  __int64 v6; // rdi
  signed int v7; // esi
  Scaleform::GFx::AS2::Environment *v8; // r14
  char v9; // bl
  Scaleform::GFx::CharacterHandle *v10; // rax
  char v11; // bl
  char v12; // bl
  Scaleform::GFx::MovieImpl *v13; // r8
  unsigned int v14; // ecx
  Scaleform::GFx::MovieImpl *v15; // rdi
  unsigned __int64 v16; // rdx
  __int64 v17; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *v18; // rdi
  __int64 v19; // rdi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v20; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v21; // rbx
  Scaleform::RefCountNTSImpl *v22; // rcx
  Scaleform::RefCountNTSImpl *v23; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+28h] [rbp-38h]
  Scaleform::GFx::AS2::Value v; // [rsp+40h] [rbp-20h]

  v6 = (unsigned int)fmt;
  v7 = controllerIdx;
  v8 = penv;
  pheapAddr.Data = 0i64;
  pheapAddr.Size = 0i64;
  pheapAddr.Policy.Capacity = 0i64;
  if ( pNewFocus )
  {
    v9 = 7;
    v.T.Type = 7;
    v10 = pNewFocus->pNameHandle.pObject;
    if ( !v10 )
      v10 = Scaleform::GFx::DisplayObject::CreateCharacterHandle((Scaleform::GFx::DisplayObject *)&pNewFocus->vfptr);
    v.V.pStringNode = (Scaleform::GFx::ASStringNode *)v10;
    if ( v10 )
      ++v10->RefCount;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    if ( &pheapAddr.Data[pheapAddr.Size - 1] )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, v6);
      v9 = v.T.Type;
    }
  }
  else
  {
    v9 = 1;
    v.T.Type = 1;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    if ( &pheapAddr.Data[pheapAddr.Size - 1] )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, v6);
      v9 = v.T.Type;
    }
  }
  if ( (unsigned __int8)v9 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v11 = 4;
  v.T.Type = 4;
  v.NV.Int32Value = v6;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pheapAddr,
    &pheapAddr,
    pheapAddr.Size + 1);
  if ( &pheapAddr.Data[pheapAddr.Size - 1] )
  {
    Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, v6);
    v11 = v.T.Type;
  }
  if ( (unsigned __int8)v11 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v12 = 3;
  v.T.Type = 3;
  v.NV.NumberValue = (double)v7;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pheapAddr,
    &pheapAddr,
    pheapAddr.Size + 1);
  if ( &pheapAddr.Data[pheapAddr.Size - 1] )
  {
    Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v, v6);
    v12 = v.T.Type;
  }
  if ( (unsigned __int8)v12 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v13 = v8->Target->pASRoot->pMovieImpl;
  v14 = 0;
  v15 = v13->pASMovieRoot.pObject->pMovieImpl;
  v16 = v15->MovieLevels.Data.Size;
  if ( v16 )
  {
    v17 = 0i64;
    v18 = v15->MovieLevels.Data.Data;
    while ( v18[v17].Level )
    {
      v17 = ++v14;
      if ( v14 >= v16 )
        goto LABEL_27;
    }
    v19 = (__int64)v18[v14].pSprite.pObject;
  }
  else
  {
LABEL_27:
    v19 = 0i64;
  }
  v20 = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
          (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&v13->pASMovieRoot.pObject[3].RefCount,
          AP_Frame);
  v21 = v20;
  v20->Type = 4;
  if ( v19 )
    ++*(_DWORD *)(v19 + 8);
  v22 = (Scaleform::RefCountNTSImpl *)&v20->pCharacter.pObject->vfptr;
  if ( v22 )
    Scaleform::RefCountNTSImpl::Release(v22);
  v21->pCharacter.pObject = (Scaleform::GFx::InteractiveObject *)v19;
  v23 = (Scaleform::RefCountNTSImpl *)&v21->pActionBuffer.pObject->vfptr;
  if ( v23 )
    Scaleform::RefCountNTSImpl::Release(v23);
  v21->pActionBuffer.pObject = 0i64;
  v21->CFunction = Scaleform::GFx::AS2::Selection::DoTransferFocus;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&v21->FunctionParams.Data,
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr,
    v19,
    a5,
    a6,
    (__int64)v8,
    0i64);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
}

