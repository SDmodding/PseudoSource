// File Line: 31
// RVA: 0x6C93D0
void __fastcall Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(Scaleform::GFx::AS2::IntervalTimer *this, Scaleform::GFx::AS2::FunctionRef *function, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::ASStringContext *v3; // rdi
  Scaleform::GFx::AS2::FunctionRef *v4; // r9
  Scaleform::GFx::AS2::IntervalTimer *v5; // rbx
  Scaleform::GFx::AS2::FunctionRefBase *v6; // rcx
  Scaleform::GFx::AS2::FunctionObject *v7; // rdx
  Scaleform::GFx::AS2::LocalFrame *v8; // rdx
  Scaleform::GFx::ASStringNode *v9; // rcx
  signed __int64 v10; // [rsp+58h] [rbp+10h]

  v3 = psc;
  v4 = function;
  v5 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASIntervalTimerIntf,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::IntervalTimer::`vftable';
  v6 = (Scaleform::GFx::AS2::FunctionRefBase *)&this->Function.Function;
  v6->Flags = 0;
  v7 = function->Function;
  v6->Function = v7;
  if ( v7 )
    v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
  v6->pLocalFrame = 0i64;
  v8 = v4->pLocalFrame;
  if ( v8 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(v6, v8, v4->Flags & 1);
  v5->pObject.pObject = 0i64;
  v5->Character.pProxy.pObject = 0i64;
  v9 = *(Scaleform::GFx::ASStringNode **)&v3->pContext->pMovieRoot->pASMovieRoot.pObject[7].AVMVersion;
  v5->MethodName.pNode = v9;
  ++v9->RefCount;
  v10 = (signed __int64)&v5->Params;
  *(_OWORD *)v10 = 0ui64;
  *(_QWORD *)(v10 + 16) = 0i64;
  v5->Interval = 0i64;
  v5->InvokeTime = 0i64;
  v5->Id = 0;
  v5->LevelHandle.pObject = 0i64;
  *(_WORD *)&v5->Active = 1;
}

// File Line: 37
// RVA: 0x6C95C0
void __fastcall Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(Scaleform::GFx::AS2::IntervalTimer *this, Scaleform::GFx::AS2::Object *object, Scaleform::GFx::ASString *methodName)
{
  Scaleform::GFx::ASStringNode *v3; // rax
  Scaleform::Array<Scaleform::GFx::AS2::Value,2,Scaleform::ArrayDefaultPolicy> *v4; // [rsp+28h] [rbp+10h]

  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASIntervalTimerIntf,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::IntervalTimer::`vftable';
  this->Function.Flags = 0;
  this->Function.Function = 0i64;
  this->Function.pLocalFrame = 0i64;
  if ( object )
    object->RefCount = (object->RefCount + 1) & 0x8FFFFFFF;
  this->pObject.pObject = object;
  this->Character.pProxy.pObject = 0i64;
  v3 = methodName->pNode;
  this->MethodName = (Scaleform::GFx::ASString)methodName->pNode;
  ++v3->RefCount;
  v4 = &this->Params;
  *(_OWORD *)&v4->Data.Data = 0ui64;
  v4->Data.Policy.Capacity = 0i64;
  this->Interval = 0i64;
  this->InvokeTime = 0i64;
  this->Id = 0;
  this->LevelHandle.pObject = 0i64;
  *(_WORD *)&this->Active = 1;
}

// File Line: 42
// RVA: 0x6C94E0
void __fastcall Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(Scaleform::GFx::AS2::IntervalTimer *this, Scaleform::GFx::InteractiveObject *character, Scaleform::GFx::ASString *methodName)
{
  Scaleform::GFx::ASString *v3; // rsi
  Scaleform::GFx::AS2::IntervalTimer *v4; // rbx
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v5; // rdi
  Scaleform::WeakPtrProxy *v6; // rax
  Scaleform::GFx::ASStringNode *v7; // rax
  signed __int64 v8; // [rsp+58h] [rbp+10h]

  v3 = methodName;
  v4 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::ASIntervalTimerIntf,323>::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable';
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::AS2::IntervalTimer::`vftable';
  this->Function.Flags = 0;
  this->Function.Function = 0i64;
  this->Function.pLocalFrame = 0i64;
  this->pObject.pObject = 0i64;
  v5 = &this->Character;
  if ( character )
    v6 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&character->vfptr);
  else
    v6 = 0i64;
  v5->pProxy.pObject = v6;
  v7 = v3->pNode;
  v4->MethodName = (Scaleform::GFx::ASString)v3->pNode;
  ++v7->RefCount;
  v8 = (signed __int64)&v4->Params;
  *(_OWORD *)v8 = 0ui64;
  *(_QWORD *)(v8 + 16) = 0i64;
  v4->Interval = 0i64;
  v4->InvokeTime = 0i64;
  v4->Id = 0;
  v4->LevelHandle.pObject = 0i64;
  *(_WORD *)&v4->Active = 1;
}

// File Line: 46
// RVA: 0x720870
void __fastcall Scaleform::GFx::AS2::IntervalTimer::Start(Scaleform::GFx::AS2::IntervalTimer *this, Scaleform::GFx::MovieImpl *proot)
{
  this->InvokeTime = this->Interval + proot->TimeElapsed;
}

// File Line: 54
// RVA: 0x6FE200
char __fastcall Scaleform::GFx::AS2::IntervalTimer::Invoke(Scaleform::GFx::AS2::IntervalTimer *this, Scaleform::GFx::MovieImpl *proot, float frameTime)
{
  Scaleform::GFx::MovieImpl *v3; // r14
  Scaleform::GFx::AS2::IntervalTimer *v4; // r13
  char v6; // si
  signed __int64 v7; // rsi
  Scaleform::GFx::AS2::FunctionObject *v8; // r12
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v9; // rdi
  Scaleform::GFx::Sprite *v10; // rbx
  Scaleform::GFx::Sprite *v11; // r15
  Scaleform::GFx::AS2::Object *v12; // rcx
  unsigned int v13; // eax
  signed __int64 v14; // rcx
  __int64 v15; // rax
  signed __int64 v16; // rcx
  __int64 v17; // rax
  Scaleform::GFx::InteractiveObject *v18; // rax
  __int64 v19; // rcx
  __int64 v20; // rax
  Scaleform::GFx::AS2::FunctionRef *v21; // rax
  char v22; // al
  Scaleform::GFx::AS2::FunctionObject *v23; // rcx
  unsigned int v24; // edx
  Scaleform::GFx::AS2::LocalFrame *v25; // rcx
  unsigned int v26; // eax
  Scaleform::GFx::CharacterHandle *v27; // rcx
  Scaleform::GFx::DisplayObject *v28; // rax
  Scaleform::RefCountNTSImpl *v29; // rsi
  unsigned __int8 *v30; // rcx
  signed __int64 v31; // rcx
  Scaleform::GFx::InteractiveObject *v32; // rax
  __int64 v33; // rcx
  unsigned __int64 v34; // r12
  int v35; // er14
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v36; // rsi
  signed __int64 v37; // r15
  Scaleform::GFx::AS2::Value *v38; // rdx
  Scaleform::GFx::AS2::Value *v39; // rcx
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *v40; // rsi
  unsigned int v41; // edx
  Scaleform::GFx::AS2::LocalFrame *v42; // r14
  char v43; // dl
  Scaleform::GFx::AS2::FunctionObject *v44; // rcx
  unsigned int v45; // eax
  Scaleform::GFx::AS2::LocalFrame *v46; // rcx
  unsigned int v47; // eax
  float v48; // xmm6_4
  signed __int64 v49; // rax
  unsigned __int64 v50; // rdx
  unsigned __int64 v51; // rcx
  __int64 v52; // r8
  unsigned __int64 v53; // rax
  unsigned int v54; // eax
  char v55; // bl
  unsigned int v56; // eax
  unsigned int v57; // edx
  Scaleform::GFx::AS2::MovieRoot *v58; // [rsp+20h] [rbp-71h]
  Scaleform::GFx::AS2::MovieRoot *v59; // [rsp+20h] [rbp-71h]
  Scaleform::GFx::AS2::FunctionRefBase v60; // [rsp+28h] [rbp-69h]
  unsigned __int64 v61; // [rsp+40h] [rbp-51h]
  void **v62; // [rsp+48h] [rbp-49h]
  Scaleform::GFx::AS2::FunctionRef v63; // [rsp+50h] [rbp-41h]
  Scaleform::GFx::AS2::Value v64; // [rsp+68h] [rbp-29h]
  Scaleform::GFx::Sprite *v65; // [rsp+88h] [rbp-9h]
  void *v66; // [rsp+90h] [rbp-1h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v67; // [rsp+98h] [rbp+7h]
  __int64 v68; // [rsp+A0h] [rbp+Fh]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+F8h] [rbp+67h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v70; // [rsp+110h] [rbp+7Fh]

  v68 = -2i64;
  v3 = proot;
  v4 = this;
  if ( !this->Active )
    return 0;
  v58 = (Scaleform::GFx::AS2::MovieRoot *)proot->pASMovieRoot.pObject;
  v61 = proot->TimeElapsed;
  v6 = 0;
  if ( v61 >= this->InvokeTime )
  {
    v60.Flags = 0;
    v7 = 0i64;
    v8 = 0i64;
    v60.Function = 0i64;
    v60.pLocalFrame = 0i64;
    v70 = 0i64;
    v9 = 0i64;
    v67 = 0i64;
    v10 = 0i64;
    v65 = 0i64;
    v11 = 0i64;
    result.pObject = 0i64;
    if ( this->Function.Function )
    {
      Scaleform::GFx::AS2::FunctionRefBase::Assign(
        &v60,
        (Scaleform::GFx::AS2::FunctionRefBase *)&this->Function.Function);
      v8 = v60.Function;
      goto LABEL_41;
    }
    v12 = this->pObject.pObject;
    if ( v12 )
      v12->RefCount = (v12->RefCount + 1) & 0x8FFFFFFF;
    v70 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v4->pObject.pObject->vfptr;
    v9 = v70;
    if ( v70 )
      v70->RefCount = (v70->RefCount + 1) & 0x8FFFFFFF;
    v67 = v9;
    if ( v9 )
    {
      v13 = v9->RefCount;
      if ( v13 & 0x3FFFFFF )
      {
        v9->RefCount = v13 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
      v7 = (signed __int64)&v9[1];
      v70 = v9 + 1;
    }
    else
    {
      Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
        (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v4->Character,
        &result);
      v10 = result.pObject;
      if ( result.pObject )
      {
        ++result.pObject->RefCount;
        v10 = result.pObject;
      }
      v70 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v10;
      if ( v10 )
        ++v10->RefCount;
      v65 = v10;
      if ( v10 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
      if ( result.pObject )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
      if ( !v10 )
        goto LABEL_83;
      v14 = (signed __int64)v10 + 4 * (unsigned __int8)v10->AvmObjOffset;
      v15 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v14 + 8i64))(v14);
      if ( v15 )
        v7 = v15 + 8;
      v70 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)v7;
      v16 = (signed __int64)v10 + 4 * (unsigned __int8)v10->AvmObjOffset;
      v17 = (*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v16 + 8i64))(v16);
      v11 = (Scaleform::GFx::Sprite *)(*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v17 + 240i64))(v17);
      result.pObject = v11;
    }
    if ( v7 )
    {
      v64.T.Type = 0;
      v18 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(v58, 0);
      v19 = (__int64)v18;
      if ( v18 )
        v19 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v18->vfptr
                                                                          + 4 * (unsigned __int8)v18->AvmObjOffset))[1].__vecDelDtor)();
      v20 = (*(__int64 (**)(void))(*(_QWORD *)v19 + 240i64))();
      if ( (*(unsigned __int8 (__fastcall **)(signed __int64, __int64, Scaleform::GFx::ASString *, Scaleform::GFx::AS2::Value *))(*(_QWORD *)v7 + 88i64))(
             v7,
             v20 + 232,
             &v4->MethodName,
             &v64) )
      {
        v21 = Scaleform::GFx::AS2::Value::ToFunction(&v64, &v63, (Scaleform::GFx::AS2::Environment *)v11);
        Scaleform::GFx::AS2::FunctionRefBase::Assign(&v60, (Scaleform::GFx::AS2::FunctionRefBase *)&v21->Function);
        v22 = v63.Flags;
        if ( !(v63.Flags & 2) )
        {
          v23 = v63.Function;
          if ( v63.Function )
          {
            v24 = v63.Function->RefCount;
            if ( v24 & 0x3FFFFFF )
            {
              v63.Function->RefCount = v24 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v23->vfptr);
              v22 = v63.Flags;
            }
          }
        }
        v63.Function = 0i64;
        if ( !(v22 & 1) )
        {
          v25 = v63.pLocalFrame;
          if ( v63.pLocalFrame )
          {
            v26 = v63.pLocalFrame->RefCount;
            if ( v26 & 0x3FFFFFF )
            {
              v63.pLocalFrame->RefCount = v26 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v25->vfptr);
            }
          }
        }
        v63.pLocalFrame = 0i64;
        v8 = v60.Function;
      }
      if ( v64.T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(&v64);
LABEL_41:
      if ( v8 )
      {
        v64.T.Type = 0;
        if ( !v11 )
        {
          v27 = v4->LevelHandle.pObject;
          if ( !v27 )
            goto LABEL_113;
          v28 = Scaleform::GFx::CharacterHandle::ResolveCharacter(v27, v3);
          v29 = (Scaleform::RefCountNTSImpl *)&v28->vfptr;
          if ( v28 )
            ++v28->RefCount;
          v66 = v28;
          if ( v28 )
          {
            v30 = 0i64;
            if ( SLOBYTE(v28->Flags) < 0 )
              v30 = (unsigned __int8 *)v28;
            if ( v30 )
            {
              v31 = (signed __int64)&v30[4 * v30[109]];
              v30 = (unsigned __int8 *)(*(__int64 (__cdecl **)(signed __int64))(*(_QWORD *)v31 + 8i64))(v31);
            }
            v11 = (Scaleform::GFx::Sprite *)(*(__int64 (__cdecl **)(unsigned __int8 *))(*(_QWORD *)v30 + 240i64))(v30);
            result.pObject = v11;
          }
          if ( v29 )
            Scaleform::RefCountNTSImpl::Release(v29);
          if ( !v11 )
          {
LABEL_113:
            v32 = Scaleform::GFx::AS2::MovieRoot::GetLevelMovie(v58, 0);
            v33 = (__int64)v32;
            if ( v32 )
              v33 = ((__int64 (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v32->vfptr
                                                                                + 4 * (unsigned __int8)v32->AvmObjOffset))[1].__vecDelDtor)();
            v11 = (Scaleform::GFx::Sprite *)(*(__int64 (**)(void))(*(_QWORD *)v33 + 240i64))();
            result.pObject = v11;
          }
        }
        v34 = v4->Params.Data.Size;
        if ( (signed int)v34 > 0 )
        {
          v35 = v34 - 1;
          if ( (signed int)v34 - 1 >= 0 )
          {
            v36 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&v11->RefCount;
            v37 = v35;
            do
            {
              v38 = &v4->Params.Data.Data[v37];
              v59 = (Scaleform::GFx::AS2::MovieRoot *)&v4->Params.Data.Data[v37];
              ++v36->pCurrent;
              if ( v36->pCurrent >= v36->pPageEnd )
              {
                Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PushPage(v36);
                v38 = (Scaleform::GFx::AS2::Value *)v59;
              }
              v39 = v36->pCurrent;
              v66 = v39;
              if ( v39 )
                Scaleform::GFx::AS2::Value::Value(v39, v38, (__int64)v9);
              --v37;
              --v35;
            }
            while ( v35 >= 0 );
          }
        }
        v40 = (Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *)&result.pObject->RefCount;
        v41 = ((signed __int64)(*(_QWORD *)&result.pObject->RefCount - (unsigned __int64)result.pObject->pWeakProxy) >> 5)
            + 32 * *(unsigned __int64 *)&result.pObject->CreateFrame
            - 32;
        v60.Flags = 0;
        v60.Function = 0i64;
        v60.pLocalFrame = 0i64;
        v61 = (unsigned __int64)result.pObject;
        v62 = (void **)__PAIR__(v41, (unsigned int)v34);
        v42 = 0i64;
        (*(void (__fastcall **)(_QWORD, void ***, _QWORD, _QWORD, Scaleform::GFx::AS2::RefCountBaseGC<323> *))(MEMORY[0] + 80))(
          0i64,
          &v62,
          0i64,
          0i64,
          v70);
        v62 = &Scaleform::GFx::AS2::FnCall::`vftable';
        v43 = v60.Flags;
        if ( !(v60.Flags & 2) )
        {
          v44 = v60.Function;
          if ( v60.Function )
          {
            v45 = v60.Function->RefCount;
            if ( v45 & 0x3FFFFFF )
            {
              v60.Function->RefCount = v45 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v44->vfptr);
              v43 = v60.Flags;
            }
          }
        }
        v60.Function = 0i64;
        if ( !(v43 & 1) )
        {
          v46 = v60.pLocalFrame;
          if ( v60.pLocalFrame )
          {
            v47 = v60.pLocalFrame->RefCount;
            if ( v47 & 0x3FFFFFF )
            {
              v60.pLocalFrame->RefCount = v47 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v46->vfptr);
            }
          }
        }
        v60.pLocalFrame = 0i64;
        v62 = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable';
        if ( (signed int)v34 > 0 )
        {
          do
          {
            if ( v40->pCurrent->T.Type >= 5u )
              Scaleform::GFx::AS2::Value::DropRefs(v40->pCurrent);
            --v40->pCurrent;
            if ( v40->pCurrent < v40->pPageStart )
              Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(v40);
            LODWORD(v34) = v34 - 1;
          }
          while ( (_DWORD)v34 );
        }
        if ( v64.T.Type >= 5u )
          Scaleform::GFx::AS2::Value::DropRefs(&v64);
        v8 = v60.Function;
        goto LABEL_85;
      }
LABEL_84:
      v42 = v60.pLocalFrame;
LABEL_85:
      if ( v4->Timeout )
      {
        v4->Active = 0;
      }
      else
      {
        v48 = frameTime * 1000000.0;
        v49 = 0i64;
        if ( (float)(frameTime * 1000000.0) >= 9.223372e18 )
        {
          v48 = v48 - 9.223372e18;
          if ( v48 < 9.223372e18 )
            v49 = 0x8000000000000000i64;
        }
        v50 = (unsigned __int64)((v49 + (unsigned __int64)(unsigned int)(signed int)v48)
                               * (unsigned __int128)0xCCCCCCCCCCCCCCCDui64 >> 64) >> 3;
        v51 = v4->Interval;
        if ( v51 < v50 )
          v51 = (unsigned int)v50;
        if ( v51 && (v52 = v4->InvokeTime, (v53 = v51 * ((v61 + v51 - v52) / v51)) != 0) )
          v4->InvokeTime = v52 + v53;
        else
          v4->InvokeTime = v61;
      }
      v6 = 1;
      if ( v10 )
        Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v10->vfptr);
      if ( v9 )
      {
        v54 = v9->RefCount;
        if ( v54 & 0x3FFFFFF )
        {
          v9->RefCount = v54 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
      v55 = v60.Flags;
      if ( !(v60.Flags & 2) )
      {
        if ( v8 )
        {
          v56 = v8->RefCount;
          if ( v56 & 0x3FFFFFF )
          {
            v8->RefCount = v56 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v8->vfptr);
          }
        }
      }
      v60.Function = 0i64;
      if ( !(v55 & 1) && v42 )
      {
        v57 = v42->RefCount;
        if ( v57 & 0x3FFFFFF )
        {
          v42->RefCount = v57 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v42->vfptr);
        }
      }
      v60.pLocalFrame = 0i64;
      return v6;
    }
LABEL_83:
    v4->Active = 0;
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
  Scaleform::GFx::AS2::Environment *v1; // r10
  Scaleform::GFx::AS2::Value *v2; // r9
  Scaleform::GFx::MovieImpl *v3; // rbx
  unsigned int v4; // edx
  double v5; // xmm0_8

  if ( fn->NArgs >= 1 )
  {
    v1 = fn->Env;
    v2 = 0i64;
    v3 = v1->Target->pASRoot->pMovieImpl;
    v4 = fn->FirstArgBottomIndex;
    if ( v4 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
             + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
      v2 = &v1->Stack.Pages.Data.Data[(unsigned __int64)v4 >> 5]->Values[v4 & 0x1F];
    v5 = Scaleform::GFx::AS2::Value::ToNumber(v2, v1);
    if ( (*(_QWORD *)&v5 & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(*(_QWORD *)&v5 & 0xFFFFFFFFFFFFFi64) )
      Scaleform::GFx::MovieImpl::ClearIntervalTimer(v3, (signed int)v5);
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
void __fastcall Scaleform::GFx::AS2::IntervalTimer::ClearTimeout(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::IntervalTimer::ClearInterval(fn);
}

// File Line: 206
// RVA: 0x7129D0
void __fastcall Scaleform::GFx::AS2::IntervalTimer::Set(Scaleform::GFx::AS2::FnCall *fn, bool timeout)
{
  bool v2; // r12
  Scaleform::GFx::AS2::FnCall *v3; // rsi
  char v4; // r14
  Scaleform::GFx::AS2::Value *v5; // rbx
  __int64 v6; // rbx
  signed int v7; // edi
  Scaleform::GFx::AS2::Environment *v8; // r9
  Scaleform::MemoryHeap *v9; // r11
  unsigned int v10; // er10
  Scaleform::GFx::AS2::Value *v11; // r8
  Scaleform::GFx::AS2::Value *v12; // rdx
  Scaleform::GFx::AS2::IntervalTimer *v13; // r15
  Scaleform::GFx::AS2::Value *v14; // rax
  Scaleform::GFx::ASString *v15; // rbx
  Scaleform::GFx::AS2::Value *v16; // rax
  Scaleform::GFx::AS2::Object *v17; // rax
  __int64 v18; // rax
  Scaleform::GFx::ASStringNode *v19; // rcx
  bool v20; // zf
  Scaleform::GFx::AS2::Value *v21; // rdx
  Scaleform::GFx::AS2::IntervalTimer *v22; // r15
  Scaleform::GFx::AS2::Value *v23; // rax
  Scaleform::GFx::ASString *v24; // rbx
  Scaleform::GFx::AS2::Value *v25; // rax
  Scaleform::GFx::InteractiveObject *v26; // rax
  __int64 v27; // rax
  Scaleform::GFx::ASStringNode *v28; // rbx
  unsigned int v29; // er10
  Scaleform::GFx::AS2::Environment *v30; // r8
  Scaleform::GFx::AS2::Value *v31; // r9
  Scaleform::GFx::AS2::FunctionRef *v32; // rax
  __int64 v33; // rax
  char v34; // al
  Scaleform::GFx::AS2::FunctionObject *v35; // rcx
  unsigned int v36; // edx
  Scaleform::GFx::AS2::LocalFrame *v37; // rcx
  unsigned int v38; // eax
  Scaleform::GFx::InteractiveObject *v39; // rcx
  Scaleform::GFx::DisplayObject *v40; // rax
  Scaleform::GFx::CharacterHandle *v41; // r14
  Scaleform::GFx::CharacterHandle *v42; // r15
  unsigned int v43; // er9
  Scaleform::GFx::AS2::Environment *v44; // rdx
  Scaleform::GFx::AS2::Value *v45; // r10
  __int64 v46; // rdi
  double v47; // xmm0_8
  signed __int64 v48; // rcx
  unsigned int v49; // edx
  Scaleform::GFx::AS2::Environment *v50; // r8
  Scaleform::GFx::AS2::Value *v51; // r14
  signed __int64 v52; // rcx
  Scaleform::GFx::ASStringNode *v53; // rcx
  Scaleform::GFx::MovieImpl *v54; // r14
  signed int v55; // er15
  Scaleform::GFx::AS2::Value *v56; // rdi
  Scaleform::GFx::AS2::FunctionRef v57; // [rsp+38h] [rbp-18h]
  Scaleform::GFx::ASString result; // [rsp+A0h] [rbp+50h]
  Scaleform::GFx::ASStringNode *v59; // [rsp+A8h] [rbp+58h]

  v2 = timeout;
  v3 = fn;
  v4 = 0;
  v5 = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  v5->T.Type = 0;
  if ( v3->NArgs >= 2 )
  {
    v6 = 0i64;
    v7 = 1;
    v8 = v3->Env;
    v9 = v8->StringContext.pContext->pHeap;
    v59 = (Scaleform::GFx::ASStringNode *)v8->StringContext.pContext->pHeap;
    v10 = v3->FirstArgBottomIndex;
    v11 = 0i64;
    if ( v10 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
      v11 = &v8->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
    if ( v11->T.Type == 8 || v11->T.Type == 11 )
    {
      v28 = (Scaleform::GFx::ASStringNode *)v9->vfptr->Alloc(v9, 128ui64, 0i64);
      result.pNode = v28;
      if ( v28 )
      {
        v29 = v3->FirstArgBottomIndex;
        v30 = v3->Env;
        v31 = 0i64;
        if ( v29 <= 32 * ((unsigned int)v30->Stack.Pages.Data.Size - 1)
                  + (unsigned int)((_QWORD)((char *)v30->Stack.pCurrent - (char *)v30->Stack.pPageStart) >> 5) )
          v31 = &v30->Stack.Pages.Data.Data[v29 >> 5]->Values[v29 & 0x1F];
        v32 = Scaleform::GFx::AS2::Value::ToFunction(v31, &v57, v30);
        v4 = 1;
        Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(
          (Scaleform::GFx::AS2::IntervalTimer *)v28,
          v32,
          &v3->Env->StringContext);
        v6 = v33;
      }
      else
      {
        v6 = 0i64;
      }
      if ( v4 & 1 )
      {
        v34 = v57.Flags;
        if ( !(v57.Flags & 2) )
        {
          v35 = v57.Function;
          if ( v57.Function )
          {
            v36 = v57.Function->RefCount;
            if ( v36 & 0x3FFFFFF )
            {
              v57.Function->RefCount = v36 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v35->vfptr);
              v34 = v57.Flags;
            }
          }
        }
        v57.Function = 0i64;
        if ( !(v34 & 1) )
        {
          v37 = v57.pLocalFrame;
          if ( v57.pLocalFrame )
          {
            v38 = v57.pLocalFrame->RefCount;
            if ( v38 & 0x3FFFFFF )
            {
              v57.pLocalFrame->RefCount = v38 - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v37->vfptr);
            }
          }
        }
        v57.pLocalFrame = 0i64;
      }
      goto LABEL_39;
    }
    v12 = 0i64;
    if ( v10 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
              + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
      v12 = &v8->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
    if ( v12->T.Type == 6 )
    {
      v13 = (Scaleform::GFx::AS2::IntervalTimer *)v9->vfptr->Alloc(v9, 128ui64, 0i64);
      if ( v13 )
      {
        v14 = Scaleform::GFx::AS2::FnCall::Arg(v3, 1);
        v15 = Scaleform::GFx::AS2::Value::ToString(v14, &result, v3->Env, -1);
        v4 = 2;
        v16 = Scaleform::GFx::AS2::FnCall::Arg(v3, 0);
        v17 = Scaleform::GFx::AS2::Value::ToObject(v16, v3->Env);
        Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(v13, v17, v15);
        v6 = v18;
      }
      else
      {
        v6 = 0i64;
      }
      if ( !(v4 & 2) )
      {
LABEL_15:
        v7 = 2;
LABEL_39:
        if ( v3->NArgs > v7 )
        {
          v39 = v3->Env->Target;
          if ( v39 )
          {
            v40 = (Scaleform::GFx::DisplayObject *)v39->vfptr[68].__vecDelDtor(
                                                     (Scaleform::RefCountNTSImplCore *)&v39->vfptr,
                                                     0);
            v41 = v40->pNameHandle.pObject;
            if ( v41 || (v41 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v40)) != 0i64 )
              ++v41->RefCount;
            v42 = *(Scaleform::GFx::CharacterHandle **)(v6 + 112);
            if ( v42 )
            {
              if ( --v42->RefCount <= 0 )
              {
                Scaleform::GFx::CharacterHandle::~CharacterHandle(v42);
                Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v42);
              }
            }
            *(_QWORD *)(v6 + 112) = v41;
          }
          v43 = v3->FirstArgBottomIndex - v7;
          v44 = v3->Env;
          v45 = 0i64;
          if ( v43 <= 32 * ((unsigned int)v44->Stack.Pages.Data.Size - 1)
                    + (unsigned int)((_QWORD)((char *)v44->Stack.pCurrent - (char *)v44->Stack.pPageStart) >> 5) )
            v45 = &v44->Stack.Pages.Data.Data[v43 >> 5]->Values[v43 & 0x1F];
          v46 = (unsigned int)(v7 + 1);
          v47 = Scaleform::GFx::AS2::Value::ToNumber(v45, v44);
          v48 = 0i64;
          if ( v47 >= 9.223372036854776e18 )
          {
            v47 = v47 - 9.223372036854776e18;
            if ( v47 < 9.223372036854776e18 )
              v48 = 0x8000000000000000i64;
          }
          *(_QWORD *)(v6 + 88) = 1000 * (v48 + (unsigned int)(signed int)v47);
          for ( *(_BYTE *)(v6 + 121) = v2; (signed int)v46 < v3->NArgs; v46 = (unsigned int)(v46 + 1) )
          {
            v49 = v3->FirstArgBottomIndex - v46;
            v50 = v3->Env;
            v51 = 0i64;
            if ( v49 <= 32 * ((unsigned int)v50->Stack.Pages.Data.Size - 1)
                      + (unsigned int)((_QWORD)((char *)v50->Stack.pCurrent - (char *)v50->Stack.pPageStart) >> 5) )
              v51 = &v50->Stack.Pages.Data.Data[v49 >> 5]->Values[v49 & 0x1F];
            Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
              (Scaleform::ArrayDataBase<Scaleform::GFx::AS2::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS2::Value,2>,Scaleform::ArrayDefaultPolicy> *)(v6 + 64),
              (const void *)(v6 + 64),
              *(_QWORD *)(v6 + 72) + 1i64);
            v52 = 32i64 * *(_QWORD *)(v6 + 72) - 32;
            v20 = *(_QWORD *)(v6 + 64) + v52 == 0;
            v53 = (Scaleform::GFx::ASStringNode *)(*(_QWORD *)(v6 + 64) + v52);
            result.pNode = v53;
            v59 = v53;
            if ( !v20 )
              Scaleform::GFx::AS2::Value::Value((Scaleform::GFx::AS2::Value *)v53, v51, v46);
          }
          v54 = v3->Env->Target->pASRoot->pMovieImpl;
          v55 = Scaleform::GFx::MovieImpl::AddIntervalTimer(v54, (Scaleform::GFx::ASIntervalTimerIntf *)v6);
          v56 = v3->Result;
          if ( v56->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v3->Result);
          v56->T.Type = 3;
          v56->NV.NumberValue = (double)v55;
          (*(void (__fastcall **)(__int64, Scaleform::GFx::MovieImpl *))(*(_QWORD *)v6 + 8i64))(v6, v54);
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
      if ( v10 <= 32 * ((unsigned int)v8->Stack.Pages.Data.Size - 1)
                + (unsigned int)((_QWORD)((char *)v8->Stack.pCurrent - (char *)v8->Stack.pPageStart) >> 5) )
        v21 = &v8->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
      if ( v21->T.Type != 7 )
        goto LABEL_62;
      v22 = (Scaleform::GFx::AS2::IntervalTimer *)v9->vfptr->Alloc(v9, 128ui64, 0i64);
      if ( v22 )
      {
        v23 = Scaleform::GFx::AS2::FnCall::Arg(v3, 1);
        v24 = Scaleform::GFx::AS2::Value::ToString(v23, &result, v3->Env, -1);
        v4 = 4;
        v25 = Scaleform::GFx::AS2::FnCall::Arg(v3, 0);
        v26 = Scaleform::GFx::AS2::Value::ToCharacter(v25, v3->Env);
        Scaleform::GFx::AS2::IntervalTimer::IntervalTimer(v22, v26, v24);
        v6 = v27;
      }
      else
      {
        v6 = 0i64;
      }
      if ( !(v4 & 4) )
        goto LABEL_15;
    }
    v19 = result.pNode;
    v20 = result.pNode->RefCount == 1;
    --v19->RefCount;
    if ( v20 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v19);
    goto LABEL_15;
  }
}

