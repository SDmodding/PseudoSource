// File Line: 45
// RVA: 0x6DBAC0
void __fastcall Scaleform::GFx::AS2::Selection::BroadcastOnSetFocus(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *pOldFocus,
        Scaleform::GFx::InteractiveObject *pNewFocus,
        int controllerIdx)
{
  Scaleform::GFx::AS2::Object *v8; // rax
  Scaleform::GFx::AS2::ObjectInterface *v9; // r12
  int v10; // edi
  Scaleform::GFx::AS2::Value *pCurrent; // rax
  char Type; // si
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // rbx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rax
  char v17; // si
  Scaleform::GFx::CharacterHandle *CharacterHandle; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  Scaleform::GFx::ASStringNode *v20; // rax
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback pcallback; // [rsp+8h] [rbp-31h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+18h] [rbp-21h] BYREF
  Scaleform::GFx::AS2::Value v26; // [rsp+38h] [rbp-1h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+67h] BYREF

  v26.T.Type = 0;
  if ( penv->StringContext.pContext->pGlobal.pObject->vfptr->GetMemberRaw(
         &penv->StringContext.pContext->pGlobal.pObject->Scaleform::GFx::AS2::ObjectInterface,
         &penv->StringContext,
         (Scaleform::GFx::ASString *)&penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[12],
         &v26) )
  {
    v8 = Scaleform::GFx::AS2::Value::ToObject(&v26, penv);
    if ( v8 )
    {
      v9 = &v8->Scaleform::GFx::AS2::ObjectInterface;
      if ( v8 != (Scaleform::GFx::AS2::Object *)-32i64 )
      {
        v10 = 2;
        if ( penv->StringContext.pContext->GFxExtensions.Value == 1 )
        {
          if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
          pCurrent = penv->Stack.pCurrent;
          result.pNode = (Scaleform::GFx::ASStringNode *)pCurrent;
          pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)pCurrent;
          if ( pCurrent )
          {
            pCurrent->T.Type = 3;
            pCurrent->NV.NumberValue = (double)controllerIdx;
          }
          v10 = 3;
        }
        if ( pNewFocus )
        {
          Type = 7;
          v.T.Type = 7;
          pObject = pNewFocus->pNameHandle.pObject;
          if ( !pObject )
            pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pNewFocus);
          v.V.pStringNode = (Scaleform::GFx::ASStringNode *)pObject;
          if ( pObject )
            ++pObject->RefCount;
          p_Stack = &penv->Stack;
          if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
          v15 = (Scaleform::GFx::ASStringNode *)p_Stack->pCurrent;
          result.pNode = v15;
          pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)v15;
          if ( v15 )
          {
            Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v15, &v);
            Type = v.T.Type;
          }
          if ( (unsigned __int8)Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
        else
        {
          p_Stack = &penv->Stack;
          if ( ++penv->Stack.pCurrent >= penv->Stack.pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(&penv->Stack);
          v16 = (Scaleform::GFx::ASStringNode *)p_Stack->pCurrent;
          result.pNode = v16;
          pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)v16;
          if ( v16 )
            LOBYTE(v16->pData) = 1;
        }
        if ( pOldFocus )
        {
          v17 = 7;
          v.T.Type = 7;
          CharacterHandle = pOldFocus->pNameHandle.pObject;
          if ( !CharacterHandle )
            CharacterHandle = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pOldFocus);
          v.V.pStringNode = (Scaleform::GFx::ASStringNode *)CharacterHandle;
          if ( CharacterHandle )
            ++CharacterHandle->RefCount;
          if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
          v19 = (Scaleform::GFx::ASStringNode *)p_Stack->pCurrent;
          result.pNode = v19;
          pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)v19;
          if ( v19 )
          {
            Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v19, &v);
            v17 = v.T.Type;
          }
          if ( (unsigned __int8)v17 >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(&v);
        }
        else
        {
          if ( ++p_Stack->pCurrent >= p_Stack->pPageEnd )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_Stack);
          v20 = (Scaleform::GFx::ASStringNode *)p_Stack->pCurrent;
          result.pNode = v20;
          pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)v20;
          if ( v20 )
            LOBYTE(v20->pData) = 1;
        }
        v21 = Scaleform::GFx::AS2::Environment::CreateConstString(penv, &result, "onSetFocus");
        Scaleform::GFx::AS2::AsBroadcaster::BroadcastMessageWithCallback(penv, v9, v21, &pcallback);
        pcallback.vfptr = (Scaleform::GFx::AS2::AsBroadcaster::InvokeCallbackVtbl *)&Scaleform::GFx::AS2::AsBroadcaster::InvokeCallback::`vftable;
        pNode = result.pNode;
        if ( result.pNode->RefCount-- == 1 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        do
        {
          if ( p_Stack->pCurrent->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(p_Stack->pCurrent);
          if ( --p_Stack->pCurrent < p_Stack->pPageStart )
            Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(p_Stack);
          --v10;
        }
        while ( v10 );
      }
    }
  }
  if ( v26.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v26);
}

// File Line: 73
// RVA: 0x6E29A0
void __fastcall Scaleform::GFx::AS2::Selection::DoTransferFocus(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r10
  Scaleform::GFx::InteractiveObject *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // r9
  Scaleform::GFx::MovieImpl *pMovieImpl; // r14
  unsigned int v6; // edx
  double v7; // xmm0_8
  Scaleform::GFx::AS2::Environment *v8; // rdx
  unsigned __int64 v9; // r8
  Scaleform::GFx::AS2::Value *v10; // r9
  unsigned int v11; // eax
  Scaleform::GFx::AS2::Environment *v12; // r9
  unsigned int FirstArgBottomIndex; // r10d
  unsigned int v14; // esi
  __int64 v15; // r8
  Scaleform::GFx::CharacterHandle *v16; // rcx
  Scaleform::GFx::DisplayObject *v17; // rax

  Env = fn->Env;
  v3 = 0i64;
  v4 = 0i64;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  v6 = fn->FirstArgBottomIndex - 1;
  if ( v6 <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
           + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[(unsigned __int64)v6 >> 5]->Values[v6 & 0x1F];
  v7 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  v8 = fn->Env;
  v9 = (unsigned int)(fn->FirstArgBottomIndex - 2);
  v10 = 0i64;
  if ( (unsigned int)v9 <= 32 * (LODWORD(v8->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)(v8->Stack.pCurrent - v8->Stack.pPageStart) )
    v10 = &v8->Stack.Pages.Data.Data[v9 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 2) & 0x1F];
  v11 = Scaleform::GFx::AS2::Value::ToUInt32(v10, v8);
  v12 = fn->Env;
  FirstArgBottomIndex = fn->FirstArgBottomIndex;
  v14 = v11;
  v15 = 0i64;
  if ( FirstArgBottomIndex <= 32 * (LODWORD(v12->Stack.Pages.Data.Size) - 1)
                            + (unsigned int)(v12->Stack.pCurrent - v12->Stack.pPageStart) )
    v15 = (__int64)&v12->Stack.Pages.Data.Data[(unsigned __int64)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
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
          if ( SLOBYTE(v17->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
            v3 = (Scaleform::GFx::InteractiveObject *)v17;
        }
      }
    }
  }
  Scaleform::GFx::MovieImpl::TransferFocus(pMovieImpl, v3, v14, (Scaleform::GFx::FocusMovedType)v7);
}

// File Line: 86
// RVA: 0x70B310
void __fastcall Scaleform::GFx::AS2::Selection::QueueSetFocus(
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::InteractiveObject *pNewFocus,
        int controllerIdx,
        int fmt)
{
  char Type; // bl
  Scaleform::GFx::CharacterHandle *pObject; // rax
  char v9; // bl
  char v10; // bl
  Scaleform::GFx::MovieImpl *pMovieImpl; // r8
  unsigned int v12; // ecx
  Scaleform::GFx::MovieImpl *v13; // rdi
  unsigned __int64 Size; // rdx
  __int64 v15; // rax
  Scaleform::GFx::MovieImpl::LevelInfo *Data; // rdi
  Scaleform::GFx::InteractiveObject *v17; // rdi
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *inserted; // rax
  Scaleform::GFx::AS2::MovieRoot::ActionEntry *v19; // rbx
  Scaleform::RefCountNTSImpl *v20; // rcx
  Scaleform::RefCountNTSImpl *v21; // rcx
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> pheapAddr; // [rsp+28h] [rbp-38h] BYREF
  Scaleform::GFx::AS2::Value v; // [rsp+40h] [rbp-20h] BYREF

  memset(&pheapAddr, 0, sizeof(pheapAddr));
  if ( pNewFocus )
  {
    Type = 7;
    v.T.Type = 7;
    pObject = pNewFocus->pNameHandle.pObject;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(pNewFocus);
    v.V.pStringNode = (Scaleform::GFx::ASStringNode *)pObject;
    if ( pObject )
      ++pObject->RefCount;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    if ( &pheapAddr.Data[pheapAddr.Size - 1] )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
      Type = v.T.Type;
    }
  }
  else
  {
    Type = 1;
    v.T.Type = 1;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pheapAddr,
      &pheapAddr,
      pheapAddr.Size + 1);
    if ( &pheapAddr.Data[pheapAddr.Size - 1] )
    {
      Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
      Type = v.T.Type;
    }
  }
  if ( (unsigned __int8)Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v9 = 4;
  v.T.Type = 4;
  v.NV.Int32Value = fmt;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pheapAddr,
    &pheapAddr,
    pheapAddr.Size + 1);
  if ( &pheapAddr.Data[pheapAddr.Size - 1] )
  {
    Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
    v9 = v.T.Type;
  }
  if ( (unsigned __int8)v9 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  v10 = 3;
  v.T.Type = 3;
  v.NV.NumberValue = (double)controllerIdx;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pheapAddr,
    &pheapAddr,
    pheapAddr.Size + 1);
  if ( &pheapAddr.Data[pheapAddr.Size - 1] )
  {
    Scaleform::GFx::AS2::Value::Value(&pheapAddr.Data[pheapAddr.Size - 1], &v);
    v10 = v.T.Type;
  }
  if ( (unsigned __int8)v10 >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v);
  pMovieImpl = penv->Target->pASRoot->pMovieImpl;
  v12 = 0;
  v13 = pMovieImpl->pASMovieRoot.pObject->pMovieImpl;
  Size = v13->MovieLevels.Data.Size;
  if ( Size )
  {
    v15 = 0i64;
    Data = v13->MovieLevels.Data.Data;
    while ( Data[v15].Level )
    {
      v15 = ++v12;
      if ( v12 >= Size )
        goto LABEL_27;
    }
    v17 = Data[v12].pSprite.pObject;
  }
  else
  {
LABEL_27:
    v17 = 0i64;
  }
  inserted = Scaleform::GFx::AS2::MovieRoot::ActionQueueType::InsertEntry(
               (Scaleform::GFx::AS2::MovieRoot::ActionQueueType *)&pMovieImpl->pASMovieRoot.pObject[3].RefCount,
               AP_Frame);
  v19 = inserted;
  inserted->Type = Entry_CFunction;
  if ( v17 )
    ++v17->RefCount;
  v20 = inserted->pCharacter.pObject;
  if ( v20 )
    Scaleform::RefCountNTSImpl::Release(v20);
  v19->pCharacter.pObject = v17;
  v21 = v19->pActionBuffer.pObject;
  if ( v21 )
    Scaleform::RefCountNTSImpl::Release(v21);
  v19->pActionBuffer.pObject = 0i64;
  v19->CFunction = Scaleform::GFx::AS2::Selection::DoTransferFocus;
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>>::operator=(
    &v19->FunctionParams,
    (Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> > *)&pheapAddr);
  Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>(&pheapAddr);
}

