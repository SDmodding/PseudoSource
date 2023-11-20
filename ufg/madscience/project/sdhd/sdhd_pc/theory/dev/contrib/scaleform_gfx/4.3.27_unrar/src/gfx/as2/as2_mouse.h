// File Line: 118
// RVA: 0x6FE930
void __fastcall Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback::Invoke(Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::ObjectInterface *pthis, Scaleform::GFx::AS2::FunctionRef *method)
{
  Scaleform::GFx::AS2::FunctionRef *v4; // rsi
  Scaleform::GFx::AS2::ObjectInterface *v5; // r15
  Scaleform::GFx::AS2::Environment *v6; // r14
  Scaleform::GFx::AS2::MouseCtorFunction::LocalInvokeCallback *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // r10
  Scaleform::GFx::AS2::LocalFrame *v9; // rdx
  int v10; // edi
  int v11; // edx
  char v12; // dl
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v15; // rcx
  unsigned int v16; // eax
  Scaleform::GFx::AS2::Value *v17; // rcx
  Scaleform::GFx::AS2::Value eventMethod; // [rsp+20h] [rbp-31h]
  void **i; // [rsp+40h] [rbp-11h]
  Scaleform::GFx::AS2::Value *v20; // [rsp+48h] [rbp-9h]
  Scaleform::GFx::AS2::ObjectInterface *v21; // [rsp+50h] [rbp-1h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v22; // [rsp+58h] [rbp+7h]
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v23; // [rsp+60h] [rbp+Fh]
  char v24; // [rsp+68h] [rbp+17h]
  Scaleform::GFx::AS2::Environment *v25; // [rsp+70h] [rbp+1Fh]
  int v26; // [rsp+78h] [rbp+27h]
  int v27; // [rsp+7Ch] [rbp+2Bh]

  v4 = method;
  v5 = pthis;
  v6 = penv;
  v7 = this;
  eventMethod.T.Type = 8;
  eventMethod.V.FunctionValue.Flags = 0;
  v8 = (Scaleform::GFx::ASStringNode *)method->Function;
  eventMethod.V.pStringNode = v8;
  if ( v8 )
    v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
  eventMethod.V.FunctionValue.pLocalFrame = 0i64;
  v9 = method->pLocalFrame;
  if ( v9 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&eventMethod.NV.8,
      v9,
      method->Flags & 1);
  eventMethod.V.FunctionValue.Flags = v7->DoubleClick;
  *((_DWORD *)&eventMethod.NV + 4) = v7->Delta;
  eventMethod.NV.Int32Value = v7->Button;
  *(_QWORD *)&eventMethod.T.Type = v7->pTargetName;
  v10 = Scaleform::GFx::AS2::MouseCtorFunction::PushListenersParams(
          v6,
          v7->MouseIndex,
          v7->EventName,
          &eventMethod,
          *(Scaleform::GFx::ASString **)&eventMethod.T.Type,
          eventMethod.NV.UInt32Value,
          *((int *)&eventMethod.NV + 4),
          eventMethod.V.FunctionValue.Flags);
  if ( eventMethod.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&eventMethod);
  if ( v10 >= 0 )
  {
    eventMethod.T.Type = 0;
    v11 = ((_QWORD)((char *)v6->Stack.pCurrent - (char *)v6->Stack.pPageStart) >> 5)
        + 32 * v6->Stack.Pages.Data.Size
        - 32;
    i = &Scaleform::GFx::AS2::FnCall::`vftable;
    v20 = &eventMethod;
    v21 = v5;
    v24 = 0;
    v22 = 0i64;
    v23 = 0i64;
    v25 = v6;
    v26 = v10;
    v27 = v11;
    ((void (__fastcall *)(Scaleform::GFx::AS2::FunctionObject *, void ***, Scaleform::GFx::AS2::LocalFrame *, _QWORD))v4->Function->vfptr[3].Finalize_GC)(
      v4->Function,
      &i,
      v4->pLocalFrame,
      0i64);
    i = &Scaleform::GFx::AS2::FnCall::`vftable;
    v12 = v24;
    if ( !(v24 & 2) )
    {
      v13 = v22;
      if ( v22 )
      {
        v14 = v22->RefCount;
        if ( v14 & 0x3FFFFFF )
        {
          v22->RefCount = v14 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v13);
          v12 = v24;
        }
      }
    }
    v22 = 0i64;
    if ( !(v12 & 1) )
    {
      v15 = v23;
      if ( v23 )
      {
        v16 = v23->RefCount;
        if ( v16 & 0x3FFFFFF )
        {
          v23->RefCount = v16 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v15);
        }
      }
    }
    v23 = 0i64;
    for ( i = &Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable; v10; --v10 )
    {
      v17 = v6->Stack.pCurrent;
      if ( v17->T.Type >= 5u )
        Scaleform::GFx::AS2::Value::DropRefs(v17);
      --v6->Stack.pCurrent;
      if ( v6->Stack.pCurrent < v6->Stack.pPageStart )
        Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32>::PopPage(&v6->Stack);
    }
    if ( eventMethod.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&eventMethod);
  }
}

