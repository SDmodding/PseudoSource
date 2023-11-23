// File Line: 31
// RVA: 0x6C93D0
void __fastcall Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(
        Scaleform::GFx::AS2::IntervalTimer *this,
        Scaleform::GFx::AS2::FunctionRef *function,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::FunctionRef *p_Function; // rcx
  Scaleform::GFx::AS2::FunctionObject *v7; // rdx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  Scaleform::GFx::ASStringNode *v9; // rcx

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASIntervalTimerIntf,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::IntervalTimer::`vftable;
  p_Function = &this->Function;
  p_Function->Flags = 0;
  v7 = function->Function;
  p_Function->Function = v7;
  if ( v7 )
    v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
  p_Function->pLocalFrame = 0i64;
  pLocalFrame = function->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(p_Function, pLocalFrame, function->Flags & 1);
  this->pObject.pObject = 0i64;
  this->Character.pProxy.pObject = 0i64;
  v9 = *(Scaleform::GFx::ASStringNode **)&psc->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  this->MethodName.pNode = v9;
  ++v9->RefCount;
  this->Params.Data.Data = 0i64;
  this->Params.Data.Size = 0i64;
  this->Params.Data.Policy.Capacity = 0i64;
  this->Interval = 0i64;
  this->InvokeTime = 0i64;
  this->Id = 0;
  this->LevelHandle.pObject = 0i64;
  *(_WORD *)&this->Active = 1;
}

// File Line: 37
// RVA: 0x6C95C0
void __fastcall Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(
        Scaleform::GFx::AS2::IntervalTimer *this,
        Scaleform::GFx::AS2::Object *object,
        Scaleform::GFx::ASString *methodName)
{
  Scaleform::GFx::ASStringNode *pNode; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASIntervalTimerIntf,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::IntervalTimer::`vftable;
  this->Function.Flags = 0;
  this->Function.Function = 0i64;
  this->Function.pLocalFrame = 0i64;
  if ( object )
    object->RefCount = (object->RefCount + 1) & 0x8FFFFFFF;
  this->pObject.pObject = object;
  this->Character.pProxy.pObject = 0i64;
  pNode = methodName->pNode;
  this->MethodName = (Scaleform::GFx::ASString)methodName->pNode;
  ++pNode->RefCount;
  this->Params.Data.Data = 0i64;
  this->Params.Data.Size = 0i64;
  this->Params.Data.Policy.Capacity = 0i64;
  this->Interval = 0i64;
  this->InvokeTime = 0i64;
  this->Id = 0;
  this->LevelHandle.pObject = 0i64;
  *(_WORD *)&this->Active = 1;
}

// File Line: 42
// RVA: 0x6C94E0
void __fastcall Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(
        Scaleform::GFx::AS2::IntervalTimer *this,
        Scaleform::GFx::InteractiveObject *character,
        Scaleform::GFx::ASString *methodName)
{
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *p_Character; // rdi
  Scaleform::WeakPtrProxy *WeakProxy; // rax
  Scaleform::GFx::ASStringNode *pNode; // rax

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASIntervalTimerIntf,323>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::IntervalTimer::`vftable;
  this->Function.Flags = 0;
  this->Function.Function = 0i64;
  this->Function.pLocalFrame = 0i64;
  this->pObject.pObject = 0i64;
  p_Character = &this->Character;
  if ( character )
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(character);
  else
    WeakProxy = 0i64;
  p_Character->pProxy.pObject = WeakProxy;
  pNode = methodName->pNode;
  this->MethodName = (Scaleform::GFx::ASString)methodName->pNode;
  ++pNode->RefCount;
  this->Params.Data.Data = 0i64;
  this->Params.Data.Size = 0i64;
  this->Params.Data.Policy.Capacity = 0i64;
  this->Interval = 0i64;
  this->InvokeTime = 0i64;
  this->Id = 0;
  this->LevelHandle.pObject = 0i64;
  *(_WORD *)&this->Active = 1;
}

// File Line: 46
// RVA: 0x720870
void __fastcall Scaleform::GFx::AS2::IntervalTimer::Start(
        Scaleform::GFx::AS2::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot)
{
  this->InvokeTime = this->Interval + proot->TimeElapsed;
}

// File Line: 54
// RVA: 0x6FE200
char __fastcall Scaleform::GFx::AS2::IntervalTimer::Invoke(
        Scaleform::GFx::AS2::IntervalTimer *this,
        Scaleform::GFx::MovieImpl *proot,
        float frameTime)
{
  char v6; // si
  __int64 v7; // rsi
  Scaleform::GFx::AS2::FunctionObject *Function; // r12
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rdi
  Scaleform::GFx::Sprite *v10; // rbx
  Scaleform::GFx::Sprite *v11; // r15
  Scaleform::GFx::AS2::Object *v12; // rcx
  unsigned int RefCount; // eax
  char *v14; // rcx
  __int64 v15; // rax
  char *v16; // rcx
  __int64 v17; // rax
  Scaleform::GFx::Sprite *LevelMovie; // rax
  __int64 v19; // rcx
  char *v20; // rcx
  __int64 v21; // rax
  Scaleform::GFx::AS2::FunctionRef *v22; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *v24; // rcx
  unsigned int v25; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v27; // eax
  Scaleform::GFx::CharacterHandle *v28; // rcx
  Scaleform::GFx::DisplayObject *v29; // rax
  Scaleform::RefCountNTSImpl *v30; // rsi
  unsigned __int8 *v31; // rcx
  unsigned __int8 *v32; // rcx
  Scaleform::GFx::Sprite *v33; // rax
  __int64 v34; // rcx
  char *v35; // rcx
  unsigned __int64 Size; // r12
  int v37; // r14d
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_RefCount; // rsi
  __int64 v39; // r15
  Scaleform::GFx::AS2::Value *v40; // rdx
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v42; // rsi
  unsigned int v43; // edx
  Scaleform::GFx::AS2::LocalFrame *v44; // r14
  char v45; // dl
  Scaleform::GFx::AS2::FunctionObject *v46; // rcx
  unsigned int v47; // eax
  Scaleform::GFx::AS2::LocalFrame *v48; // rcx
  unsigned int v49; // eax
  float v50; // xmm6_4
  unsigned __int64 v51; // rax
  unsigned __int64 v52; // rdx
  unsigned __int64 Interval; // rcx
  unsigned __int64 InvokeTime; // r8
  unsigned __int64 v55; // rax
  unsigned int v56; // eax
  char v57; // bl
  unsigned int v58; // eax
  unsigned int v59; // edx
  Scaleform::GFx::AS2::MovieRoot *pObject; // [rsp+20h] [rbp-71h]
  Scaleform::GFx::AS2::MovieRoot *v61; // [rsp+20h] [rbp-71h]
  Scaleform::GFx::AS2::FunctionRefBase v62; // [rsp+28h] [rbp-69h] BYREF
  unsigned __int64 TimeElapsed; // [rsp+40h] [rbp-51h]
  void **v64; // [rsp+48h] [rbp-49h] BYREF
  Scaleform::GFx::AS2::FunctionRef v65; // [rsp+50h] [rbp-41h] BYREF
  Scaleform::GFx::AS2::Value v66; // [rsp+68h] [rbp-29h] BYREF
  Scaleform::GFx::Sprite *v67; // [rsp+88h] [rbp-9h]
  void *v68; // [rsp+90h] [rbp-1h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v69; // [rsp+98h] [rbp+7h]
  __int64 v70; // [rsp+A0h] [rbp+Fh]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+F8h] [rbp+67h] BYREF
  Scaleform::GFx::AS2::Object *v72; // [rsp+110h] [rbp+7Fh]

  v70 = -2i64;
  if ( !this->Active )
    return 0;
  pObject = (Scaleform::GFx::AS2::MovieRoot *)proot->pASMovieRoot.pObject;
  TimeElapsed = proot->TimeElapsed;
  v6 = 0;
  if ( TimeElapsed >= this->InvokeTime )
  {
    v7 = 0i64;
    Function = 0i64;
    memset(&v62, 0, 17);
    v72 = 0i64;
    v9 = 0i64;
    v69 = 0i64;
    v10 = 0i64;
    v67 = 0i64;
    v11 = 0i64;
    result.pObject = 0i64;
    if ( this->Function.Function )
    {
      Scaleform::GFx::AS2::FunctionRefBase::Assign(&v62, &this->Function);
      Function = v62.Function;
      goto LABEL_41;
    }
    v12 = this->pObject.pObject;
    if ( v12 )
      v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
    v72 = this->pObject.pObject;
    v9 = v72;
    if ( v72 )
      v72->RefCount = (v72->RefCount + 1) & 0x8FFFFFFF;
    v69 = v9;
    if ( v9 )
    {
      RefCount = v9->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
      v7 = (__int64)&v9[1];
      v72 = (Scaleform::GFx::AS2::Object *)&v9[1];
    }
    else
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->Character,
        &result);
      v10 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v10 = result.pObject;
      }
      v72 = (Scaleform::GFx::AS2::Object *)v10;
      if ( v10 )
        ++v10->RefCount;
      v67 = v10;
      if ( v10 )
        Scaleform::RefCountNTSImpl::Release(v10);
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release(result.pObject);
      if ( !v10 )
        goto LABEL_83;
      v14 = (char *)v10 + 4 * (unsigned __int8)v10->AvmObjOffset;
      v15 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v14 + 8i64))(v14);
      if ( v15 )
        v7 = v15 + 8;
      v72 = (Scaleform::GFx::AS2::Object *)v7;
      v16 = (char *)v10 + 4 * (unsigned __int8)v10->AvmObjOffset;
      v17 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v16 + 8i64))(v16);
      v11 = (Scaleform::GFx::Sprite *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v17 + 240i64))(v17);
      result.pObject = v11;
    }
    if ( v7 )
    {
      v66.T.Type = 0;
      LevelMovie = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0);
      v19 = (__int64)LevelMovie;
      if ( LevelMovie )
      {
        v20 = (char *)LevelMovie + 4 * (unsigned __int8)LevelMovie->AvmObjOffset;
        v19 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v20 + 8i64))(v20);
      }
      v21 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v19 + 240i64))(v19);
      if ( (*(unsigned __int8 (__fastcall **)(__int64, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v7 + 88i64))(
             v7,
             v21 + 232,
             &this->MethodName,
             &v66) )
      {
        v22 = Scaleform::GFx::AS2::Value::ToFunction(&v66, &v65, (Scaleform::GFx::AS2::Environment *)v11);
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&v62, v22);
        Flags = v65.Flags;
        if ( (v65.Flags & 2) == 0 )
        {
          v24 = v65.Function;
          if ( v65.Function )
          {
            v25 = v65.Function->RefCount;
            if ( (v25 & 0x3FFFFFF) != 0 )
            {
              v65.Function->RefCount = v25 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v24);
              Flags = v65.Flags;
            }
          }
        }
        v65.Function = 0i64;
        if ( (Flags & 1) == 0 )
        {
          pLocalFrame = v65.pLocalFrame;
          if ( v65.pLocalFrame )
          {
            v27 = v65.pLocalFrame->RefCount;
            if ( (v27 & 0x3FFFFFF) != 0 )
            {
              v65.pLocalFrame->RefCount = v27 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
            }
          }
        }
        v65.pLocalFrame = 0i64;
        Function = v62.Function;
      }
      if ( v66.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v66);
LABEL_41:
      if ( Function )
      {
        v66.T.Type = 0;
        if ( !v11 )
        {
          v28 = this->LevelHandle.pObject;
          if ( !v28 )
            goto LABEL_55;
          v29 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v28, proot);
          v30 = v29;
          if ( v29 )
            ++v29->RefCount;
          v68 = v29;
          if ( v29 )
          {
            v31 = 0i64;
            if ( SLOBYTE(v29->Scaleform::GFx::DisplayObjectBase::Flags) < 0 )
              v31 = (unsigned __int8 *)v29;
            if ( v31 )
            {
              v32 = &v31[4 * v31[109]];
              v31 = (unsigned __int8 *)(*(__int64 (__fastcall **)(unsigned __int8 *))(*(_QWORD *)v32 + 8i64))(v32);
            }
            v11 = (Scaleform::GFx::Sprite *)(*(__int64 (__fastcall **)(unsigned __int8 *))(*(_QWORD *)v31 + 240i64))(v31);
            result.pObject = v11;
          }
          if ( v30 )
            Scaleform::RefCountNTSImpl::Release(v30);
          if ( !v11 )
          {
LABEL_55:
            v33 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(pObject, 0);
            v34 = (__int64)v33;
            if ( v33 )
            {
              v35 = (char *)v33 + 4 * (unsigned __int8)v33->AvmObjOffset;
              v34 = (*(__int64 (__fastcall **)(char *))(*(_QWORD *)v35 + 8i64))(v35);
            }
            v11 = (Scaleform::GFx::Sprite *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v34 + 240i64))(v34);
            result.pObject = v11;
          }
        }
        Size = this->Params.Data.Size;
        if ( (int)Size > 0 )
        {
          v37 = Size - 1;
          if ( (int)Size - 1 >= 0 )
          {
            p_RefCount = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&v11->RefCount;
            v39 = v37;
            do
            {
              v40 = &this->Params.Data.Data[v39];
              v61 = (Scaleform::GFx::AS2::MovieRoot *)v40;
              if ( ++p_RefCount->pCurrent >= p_RefCount->pPageEnd )
              {
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(p_RefCount);
                v40 = (Scaleform::GFx::AS2::Value *)v61;
              }
              pCurrent = p_RefCount->pCurrent;
              v68 = pCurrent;
              if ( pCurrent )
                Scaleform::GFx::AS2::Value::Value(pCurrent, v40);
              --v39;
              --v37;
            }
            while ( v37 >= 0 );
          }
        }
        v42 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&result.pObject->RefCount;
        v43 = ((__int64)(*(_QWORD *)&result.pObject->RefCount - (unsigned __int64)result.pObject->pWeakProxy) >> 5)
            + 32 * *(_QWORD *)&result.pObject->CreateFrame
            - 32;
        memset(&v62, 0, 17);
        TimeElapsed = (unsigned __int64)result.pObject;
        v64 = (void **)__PAIR64__(v43, Size);
        v44 = 0i64;
        (*(void (__fastcall **)(_QWORD, void ***, _QWORD, _QWORD, Scaleform::GFx::AS2::Object *))(MEMORY[0] + 80))(
          0i64,
          &v64,
          0i64,
          0i64,
          v72);
        v64 = &Scaleform::GFx::AS2::FnCall::`vftable;
        v45 = v62.Flags;
        if ( (v62.Flags & 2) == 0 )
        {
          v46 = v62.Function;
          if ( v62.Function )
          {
            v47 = v62.Function->RefCount;
            if ( (v47 & 0x3FFFFFF) != 0 )
            {
              v62.Function->RefCount = v47 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v46);
              v45 = v62.Flags;
            }
          }
        }
        v62.Function = 0i64;
        if ( (v45 & 1) == 0 )
        {
          v48 = v62.pLocalFrame;
          if ( v62.pLocalFrame )
          {
            v49 = v62.pLocalFrame->RefCount;
            if ( (v49 & 0x3FFFFFF) != 0 )
            {
              v62.pLocalFrame->RefCount = v49 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v48);
            }
          }
        }
        v62.pLocalFrame = 0i64;
        v64 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
        if ( (int)Size > 0 )
        {
          do
          {
            if ( v42->pCurrent->T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(v42->pCurrent);
            if ( --v42->pCurrent < v42->pPageStart )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v42);
            LODWORD(Size) = Size - 1;
          }
          while ( (_DWORD)Size );
        }
        if ( v66.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v66);
        Function = v62.Function;
        goto LABEL_85;
      }
LABEL_84:
      v44 = v62.pLocalFrame;
LABEL_85:
      if ( this->Timeout )
      {
        this->Active = 0;
      }
      else
      {
        v50 = frameTime * 1000000.0;
        v51 = 0i64;
        if ( (float)(frameTime * 1000000.0) >= 9.223372e18 )
        {
          v50 = v50 - 9.223372e18;
          if ( v50 < 9.223372e18 )
            v51 = 0x8000000000000000ui64;
        }
        v52 = (v51 + (unsigned int)(int)v50) / 0xA;
        Interval = this->Interval;
        if ( Interval < v52 )
          Interval = (unsigned int)v52;
        if ( Interval
          && (InvokeTime = this->InvokeTime, (v55 = Interval * ((TimeElapsed + Interval - InvokeTime) / Interval)) != 0) )
        {
          this->InvokeTime = InvokeTime + v55;
        }
        else
        {
          this->InvokeTime = TimeElapsed;
        }
      }
      v6 = 1;
      if ( v10 )
        Scaleform::RefCountNTSImpl::Release(v10);
      if ( v9 )
      {
        v56 = v9->RefCount;
        if ( (v56 & 0x3FFFFFF) != 0 )
        {
          v9->RefCount = v56 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
      v57 = v62.Flags;
      if ( (v62.Flags & 2) == 0 )
      {
        if ( Function )
        {
          v58 = Function->RefCount;
          if ( (v58 & 0x3FFFFFF) != 0 )
          {
            Function->RefCount = v58 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          }
        }
      }
      v62.Function = 0i64;
      if ( (v57 & 1) == 0 && v44 )
      {
        v59 = v44->RefCount;
        if ( (v59 & 0x3FFFFFF) != 0 )
        {
          v44->RefCount = v59 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v44);
        }
      }
      v62.pLocalFrame = 0i64;
      return v6;
    }
LABEL_83:
    this->Active = 0;
    goto LABEL_84;
  }
  return v6;
}

// File Line: 173
// RVA: 0x6DDB20
void __fastcall Scaleform::GFx::AS2::IntervalTimer::Clear(Scaleform::GFx::AS2::IntervalTimer *this)
{
  this->Active = 0;
}

// File Line: 178
// RVA: 0x6A5340
void __fastcall Scaleform::GFx::AS2::IntervalTimer::SetInterval(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::IntervalTimer::Set(fn, 0);
}

// File Line: 183
// RVA: 0x6A5420
void __fastcall Scaleform::GFx::AS2::IntervalTimer::ClearInterval(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r10
  Scaleform::GFx::AS2::Value *v2; // r9
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  unsigned int FirstArgBottomIndex; // edx
  double v5; // xmm0_8

  if ( fn->NArgs >= 1 )
  {
    Env = fn->Env;
    v2 = 0i64;
    pMovieImpl = Env->Target->pASRoot->pMovieImpl;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    if ( FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v2 = &Env->Stack.Pages.Data.Data[(unsigned __int64)FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToNumber(v2, Env);
    if ( (*(_QWORD *)&v5 & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 || (*(_QWORD *)&v5 & 0xFFFFFFFFFFFFFi64) == 0 )
      Scaleform::GFx::MovieImpl::ClearIntervalTimer(pMovieImpl, (int)v5);
  }
}

// File Line: 196
// RVA: 0x6A56E0
void __fastcall Scaleform::GFx::AS2::IntervalTimer::SetTimeout(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::IntervalTimer::Set(fn, 1);
}

// File Line: 201
// RVA: 0x6A5BF0
// attributes: thunk
void __fastcall Scaleform::GFx::AS2::IntervalTimer::ClearTimeout(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::IntervalTimer::ClearInterval(fn);
}

// File Line: 206
// RVA: 0x7129D0
void __fastcall Scaleform::GFx::AS2::IntervalTimer::Set(Scaleform::GFx::AS2::FnCall *fn, bool timeout)
{
  char v4; // r14
  Scaleform::GFx::AS2::Value *v5; // rbx
  __int64 v6; // rbx
  int v7; // edi
  Scaleform::GFx::AS2::Environment *Env; // r9
  __int64 pHeap; // r11
  unsigned int FirstArgBottomIndex; // r10d
  Scaleform::GFx::AS2::Value *v11; // r8
  Scaleform::GFx::AS2::Value *v12; // rdx
  Scaleform::GFx::AS2::IntervalTimer *v13; // r15
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v14; // rax
  Scaleform::GFx::ASString *v15; // rbx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v16; // rax
  Scaleform::GFx::AS2::Object *v17; // rax
  __int64 v18; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v20; // zf
  Scaleform::GFx::AS2::Value *v21; // rdx
  Scaleform::GFx::AS2::IntervalTimer *v22; // r15
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v23; // rax
  Scaleform::GFx::ASString *v24; // rbx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::Page *v25; // rax
  Scaleform::GFx::InteractiveObject *v26; // rax
  __int64 v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rbx
  unsigned int v29; // r10d
  Scaleform::GFx::AS2::Environment *v30; // r8
  Scaleform::GFx::AS2::Value *v31; // r9
  Scaleform::GFx::AS2::FunctionRef *v32; // rax
  __int64 v33; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v38; // eax
  Scaleform::GFx::InteractiveObject *Target; // rcx
  Scaleform::GFx::DisplayObject *v40; // rax
  Scaleform::GFx::CharacterHandle *pObject; // r14
  Scaleform::GFx::CharacterHandle *v42; // r15
  unsigned int v43; // r9d
  Scaleform::GFx::AS2::Environment *v44; // rdx
  Scaleform::GFx::AS2::Value *v45; // r10
  int v46; // edi
  double v47; // xmm0_8
  unsigned __int64 v48; // rcx
  unsigned int v49; // edx
  Scaleform::GFx::AS2::Environment *v50; // r8
  Scaleform::GFx::AS2::Value *v51; // r14
  __int64 v52; // rcx
  Scaleform::GFx::ASStringNode *v53; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // r14
  int v55; // r15d
  Scaleform::GFx::AS2::Value *v56; // rdi
  Scaleform::GFx::AS2::FunctionRef v57; // [rsp+38h] [rbp-18h] BYREF
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+50h] BYREF
  __int64 v59; // [rsp+A8h] [rbp+58h]

  v4 = 0;
  v5 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(v5);
  v5->T.Type = 0;
  if ( fn->NArgs >= 2 )
  {
    v6 = 0i64;
    v7 = 1;
    Env = fn->Env;
    pHeap = (__int64)Env->StringContext.pContext->pHeap;
    v59 = pHeap;
    FirstArgBottomIndex = fn->FirstArgBottomIndex;
    v11 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v11 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    if ( v11->T.Type == 8 || v11->T.Type == 11 )
    {
      v28 = (Scaleform::GFx::ASStringNode *)(*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)pHeap
                                                                                                + 80i64))(
                                              pHeap,
                                              128i64,
                                              0i64);
      result.pNode = v28;
      if ( v28 )
      {
        v29 = fn->FirstArgBottomIndex;
        v30 = fn->Env;
        v31 = 0i64;
        if ( v29 <= 32 * ((unsigned int)v30->Stack.Pages.Data.Size - 1)
                  + (unsigned int)(v30->Stack.pCurrent - v30->Stack.pPageStart) )
          v31 = &v30->Stack.Pages.Data.Data[v29 >> 5]->Values[v29 & 0x1F];
        v32 = Scaleform::GFx::AS2::Value::ToFunction(v31, &v57, v30);
        v4 = 1;
        Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(
          (Scaleform::GFx::AS2::IntervalTimer *)v28,
          v32,
          &fn->Env->StringContext);
        v6 = v33;
      }
      else
      {
        v6 = 0i64;
      }
      if ( (v4 & 1) != 0 )
      {
        Flags = v57.Flags;
        if ( (v57.Flags & 2) == 0 )
        {
          Function = v57.Function;
          if ( v57.Function )
          {
            RefCount = v57.Function->RefCount;
            if ( (RefCount & 0x3FFFFFF) != 0 )
            {
              v57.Function->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
              Flags = v57.Flags;
            }
          }
        }
        v57.Function = 0i64;
        if ( (Flags & 1) == 0 )
        {
          pLocalFrame = v57.pLocalFrame;
          if ( v57.pLocalFrame )
          {
            v38 = v57.pLocalFrame->RefCount;
            if ( (v38 & 0x3FFFFFF) != 0 )
            {
              v57.pLocalFrame->RefCount = v38 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
            }
          }
        }
        v57.pLocalFrame = 0i64;
      }
      goto LABEL_39;
    }
    v12 = 0i64;
    if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                              + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
      v12 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
    if ( v12->T.Type == 6 )
    {
      v13 = (Scaleform::GFx::AS2::IntervalTimer *)(*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)pHeap + 80i64))(
                                                    pHeap,
                                                    128i64,
                                                    0i64);
      if ( v13 )
      {
        v14 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v15 = Scaleform::GFx::AS2::Value::ToString(v14->Values, &result, fn->Env, -1);
        v4 = 2;
        v16 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v17 = Scaleform::GFx::AS2::Value::ToObject(v16->Values, fn->Env);
        Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(v13, v17, v15);
        v6 = v18;
      }
      else
      {
        v6 = 0i64;
      }
      if ( (v4 & 2) == 0 )
      {
LABEL_15:
        v7 = 2;
LABEL_39:
        if ( fn->NArgs > v7 )
        {
          Target = fn->Env->Target;
          if ( Target )
          {
            v40 = (Scaleform::GFx::DisplayObject *)Target->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[68].__vecDelDtor(
                                                     Target,
                                                     0);
            pObject = v40->pNameHandle.pObject;
            if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v40)) != 0i64 )
              ++pObject->RefCount;
            v42 = *(Scaleform::GFx::CharacterHandle **)(v6 + 112);
            if ( v42 )
            {
              if ( --v42->RefCount <= 0 )
              {
                Scaleform::GFx::CharacterHandle::~CharacterHandle(v42);
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v42);
              }
            }
            *(_QWORD *)(v6 + 112) = pObject;
          }
          v43 = fn->FirstArgBottomIndex - v7;
          v44 = fn->Env;
          v45 = 0i64;
          if ( v43 <= 32 * ((unsigned int)v44->Stack.Pages.Data.Size - 1)
                    + (unsigned int)(v44->Stack.pCurrent - v44->Stack.pPageStart) )
            v45 = &v44->Stack.Pages.Data.Data[v43 >> 5]->Values[v43 & 0x1F];
          v46 = v7 + 1;
          v47 = Scaleform::GFx::AS2::Value::ToNumber(v45, v44);
          v48 = 0i64;
          if ( v47 >= 9.223372036854776e18 )
          {
            v47 = v47 - 9.223372036854776e18;
            if ( v47 < 9.223372036854776e18 )
              v48 = 0x8000000000000000ui64;
          }
          *(_QWORD *)(v6 + 88) = 1000 * (v48 + (unsigned int)(int)v47);
          for ( *(_BYTE *)(v6 + 121) = timeout; v46 < fn->NArgs; ++v46 )
          {
            v49 = fn->FirstArgBottomIndex - v46;
            v50 = fn->Env;
            v51 = 0i64;
            if ( v49 <= 32 * ((unsigned int)v50->Stack.Pages.Data.Size - 1)
                      + (unsigned int)(v50->Stack.pCurrent - v50->Stack.pPageStart) )
              v51 = &v50->Stack.Pages.Data.Data[v49 >> 5]->Values[v49 & 0x1F];
            Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)(v6 + 64),
              (const void *)(v6 + 64),
              *(_QWORD *)(v6 + 72) + 1i64);
            v52 = 32i64 * *(_QWORD *)(v6 + 72) - 32;
            v20 = *(_QWORD *)(v6 + 64) + v52 == 0;
            v53 = (Scaleform::GFx::ASStringNode *)(*(_QWORD *)(v6 + 64) + v52);
            result.pNode = v53;
            v59 = (__int64)v53;
            if ( !v20 )
              Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v53, v51);
          }
          pMovieImpl = fn->Env->Target->pASRoot->pMovieImpl;
          v55 = Scaleform::GFx::MovieImpl::AddIntervalTimer(pMovieImpl, (Scaleform::GFx::ASIntervalTimerIntf *)v6);
          v56 = fn->Result;
          if ( v56->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
          v56->T.Type = 3;
          v56->NV.NumberValue = (double)v55;
          (*(void (__fastcall **)(__int64, Scaleform::GFx::MovieImpl *))(*(_QWORD *)v6 + 8i64))(v6, pMovieImpl);
        }
LABEL_62:
        if ( v6 )
          Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6);
        return;
      }
    }
    else
    {
      v21 = 0i64;
      if ( FirstArgBottomIndex <= 32 * ((unsigned int)Env->Stack.Pages.Data.Size - 1)
                                + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
        v21 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
      if ( v21->T.Type != 7 )
        goto LABEL_62;
      v22 = (Scaleform::GFx::AS2::IntervalTimer *)(*(__int64 (__fastcall **)(__int64, __int64, _QWORD))(*(_QWORD *)pHeap + 80i64))(
                                                    pHeap,
                                                    128i64,
                                                    0i64);
      if ( v22 )
      {
        v23 = Scaleform::GFx::AS2::FnCall::Arg(fn, 1);
        v24 = Scaleform::GFx::AS2::Value::ToString(v23->Values, &result, fn->Env, -1);
        v4 = 4;
        v25 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v26 = Scaleform::GFx::AS2::Value::ToCharacter(v25->Values, fn->Env);
        Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(v22, v26, v24);
        v6 = v27;
      }
      else
      {
        v6 = 0i64;
      }
      if ( (v4 & 4) == 0 )
        goto LABEL_15;
    }
    pNode = result.pNode;
    v20 = result.pNode->RefCount-- == 1;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    goto LABEL_15;
  }
}

