// File Line: 118
// RVA: 0x6FE930
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::Invoke(
        Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ObjectInterface *pthis,
        Scaleform::GFx::AS2::FunctionRef *method)
{
  Scaleform::GFx::ASStringNode *Function; // r10
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  int v10; // edi
  int v11; // edx
  char v12; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Value *pCurrent; // rcx
  Scaleform::GFx::AS2::Value eventMethod; // [rsp+20h] [rbp-31h] BYREF
  __int64 v19[3]; // [rsp+40h] [rbp-11h] BYREF
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v20; // [rsp+58h] [rbp+7h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v21; // [rsp+60h] [rbp+Fh]
  char v22; // [rsp+68h] [rbp+17h]
  Scaleform::GFx::AS2::Environment *v23; // [rsp+70h] [rbp+1Fh]
  int v24; // [rsp+78h] [rbp+27h]
  int v25; // [rsp+7Ch] [rbp+2Bh]

  eventMethod.T.Type = 8;
  eventMethod.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)method->Function;
  eventMethod.V.pStringNode = Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  eventMethod.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = method->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&eventMethod.V.FunctionValue, pLocalFrame, method->Flags & 1);
  v10 = Scaleform::GFx::AS2::MouseCtorFunction::PushListenersParams(
          penv,
          this->MouseIndex,
          this->EventName,
          &eventMethod,
          this->pTargetName,
          this->Button,
          this->Delta,
          this->DoubleClick);
  if ( eventMethod.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&eventMethod);
  if ( v10 >= 0 )
  {
    eventMethod.T.Type = 0;
    v11 = penv->Stack.pCurrent - penv->Stack.pPageStart + 32 * penv->Stack.Pages.Data.Size - 32;
    v19[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
    v19[1] = (__int64)&eventMethod;
    v19[2] = (__int64)pthis;
    v22 = 0;
    v20 = 0i64;
    v21 = 0i64;
    v23 = penv;
    v24 = v10;
    v25 = v11;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, __int64 *, Scaleform::GFx::AS2::LocalFrame *, _QWORD))method->Function->vfptr[3].Finalize_GC)(
      method->Function,
      v19,
      method->pLocalFrame,
      0i64);
    v19[0] = (__int64)&Scaleform::GFx::AS2::FnCall::`vftable;
    v12 = v22;
    if ( (v22 & 2) == 0 )
    {
      v13 = v20;
      if ( v20 )
      {
        RefCount = v20->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v20->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
          v12 = v22;
        }
      }
    }
    v20 = 0i64;
    if ( (v12 & 1) == 0 )
    {
      v15 = v21;
      if ( v21 )
      {
        v16 = v21->RefCount;
        if ( (v16 & 0x3FFFFFF) != 0 )
        {
          v21->RefCount = v16 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
        }
      }
    }
    v21 = 0i64;
    for ( v19[0] = (__int64)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable; v10; --v10 )
    {
      pCurrent = penv->Stack.pCurrent;
      if ( pCurrent->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(pCurrent);
      if ( --penv->Stack.pCurrent < penv->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&penv->Stack);
    }
    if ( eventMethod.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&eventMethod);
  }
}

