// File Line: 42
// RVA: 0x82D920
void __fastcall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::availableGet(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this, bool *result)
{
  *result = *((_QWORD *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 71) != 0i64;
}

// File Line: 62
// RVA: 0x853130
void __fastcall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::marshallExceptionsGet(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this, bool *result)
{
  Scaleform::GFx::LogState *v2; // rbx
  Scaleform::Ptr<Scaleform::GFx::LogState> resulta; // [rsp+40h] [rbp+8h]

  *result = 0;
  v2 = Scaleform::GFx::StateBag::GetLogState(
         (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
         &resulta)->pObject;
  if ( resulta.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  if ( v2 )
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v2->vfptr,
      "ExternalInterface::marshallExceptions is not supported.");
}

// File Line: 78
// RVA: 0x8531A0
void __fastcall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::marshallExceptionsSet(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this, Scaleform::GFx::AS3::Value *result, bool value)
{
  Scaleform::GFx::LogState *v3; // rbx
  Scaleform::Ptr<Scaleform::GFx::LogState> resulta; // [rsp+40h] [rbp+8h]

  v3 = Scaleform::GFx::StateBag::GetLogState(
         (Scaleform::GFx::StateBag *)this->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
         &resulta)->pObject;
  if ( resulta.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  if ( v3 )
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v3->vfptr,
      "ExternalInterface::marshallExceptions is not supported.");
}

// File Line: 94
// RVA: 0x8557E0
void __fastcall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::objectIDGet(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *v3; // rsi
  Scaleform::GFx::ASStringNode *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::LogState *v7; // rbx
  Scaleform::Ptr<Scaleform::GFx::LogState> resulta; // [rsp+40h] [rbp+8h]

  v2 = result;
  v3 = this;
  v4 = this->pTraits.pObject->pVM->StringManagerRef->Builtins[2].pNode;
  ++v4->RefCount;
  v5 = result->pNode;
  v6 = result->pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  v2->pNode = v4;
  v7 = Scaleform::GFx::StateBag::GetLogState(
         (Scaleform::GFx::StateBag *)v3->pTraits.pObject->pVM[1].vfptr[2].__vecDelDtor + 2,
         &resulta)->pObject;
  if ( resulta.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)resulta.pObject);
  if ( v7 )
    Scaleform::GFx::LogBase<Scaleform::GFx::LogState>::LogWarning(
      (Scaleform::GFx::LogBase<Scaleform::GFx::LogState> *)&v7->vfptr,
      "ExternalInterface::objectID is not supported.");
}

// File Line: 109
// RVA: 0x82AE50
void __fastcall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::addCallback(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::ASString *functionName, Scaleform::GFx::AS3::Value *closure)
{
  Scaleform::GFx::AS3::MovieRoot::AddInvokeAlias(
    (Scaleform::GFx::AS3::MovieRoot *)this->pTraits.pObject->pVM[1].vfptr,
    functionName,
    closure);
}

// File Line: 125
// RVA: 0x82E720
void __fastcall Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::call(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *this, Scaleform::GFx::AS3::Value *result, unsigned int argc, Scaleform::GFx::AS3::Value *const argv)
{
  Scaleform::GFx::AS3::Value *v4; // rdi
  unsigned int v5; // ebx
  Scaleform::GFx::AS3::Value *v6; // r12
  Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *v7; // rbp
  Scaleform::GFx::AS3::VM *v8; // rcx
  Scaleform::GFx::AS3::MovieRoot *v9; // r14
  Scaleform::GFx::MovieImpl *v10; // r13
  __int64 v11; // rsi
  char *v12; // r15
  __int64 v13; // rbx
  Scaleform::GFx::AS3::Value *v14; // rdi
  __int64 v15; // rbp
  Scaleform::GFx::Value *v16; // r8
  Scaleform::GFx::AS3::WeakProxy *v17; // rdx
  bool v18; // zf
  const char *v19; // r8
  _QWORD *v20; // rbx
  __int64 v21; // rdi
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+30h] [rbp-228h]
  __int64 v24; // [rsp+38h] [rbp-220h]
  __int64 v25; // [rsp+40h] [rbp-218h]
  char v26; // [rsp+50h] [rbp-208h]
  __int64 v27; // [rsp+260h] [rbp+8h]

  v24 = -2i64;
  v4 = argv;
  v5 = argc;
  v6 = result;
  v7 = this;
  v8 = this->pTraits.pObject->pVM;
  v9 = (Scaleform::GFx::AS3::MovieRoot *)v8[1].vfptr;
  v10 = v9->pMovieImpl;
  if ( !v10->pExtIntfHandler.pObject )
  {
    v8->UI->vfptr->Output(v8->UI, Output_Warning, "Warning: ExternalInterface.call - handler is not installed.\n");
    Scaleform::GFx::AS3::Value::SetUndefined(v6);
    return;
  }
  LODWORD(v11) = 0;
  resulta.pNode = v8->StringManagerRef->Builtins[0].pNode;
  ++resulta.pNode->RefCount;
  if ( argc < 1 )
    goto LABEL_6;
  if ( Scaleform::GFx::AS3::Value::Convert2String(argv, (Scaleform::GFx::AS3::CheckResult *)&v27, &resulta)->Result )
  {
    v11 = v5 - 1;
    if ( (unsigned int)v11 > 0xA )
    {
      v12 = (char *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                      Scaleform::Memory::pGlobalHeap,
                      v7,
                      48 * v11,
                      0i64);
LABEL_7:
      if ( (_DWORD)v11 )
      {
        v13 = (__int64)v12;
        v14 = v4 + 1;
        v15 = (unsigned int)v11;
        do
        {
          v27 = v13;
          v25 = v13;
          if ( v13 )
          {
            *(_QWORD *)(v13 + 16) = 0i64;
            *(_DWORD *)(v13 + 24) = 0;
            v16 = (Scaleform::GFx::Value *)v13;
          }
          else
          {
            v16 = 0i64;
          }
          Scaleform::GFx::AS3::MovieRoot::ASValue2GFxValue(v9, v14, v16);
          ++v14;
          v13 += 48i64;
          --v15;
        }
        while ( v15 );
      }
      if ( (v9->ExternalIntfRetVal.Flags & 0x1F) > 9 )
      {
        if ( (v9->ExternalIntfRetVal.Flags >> 9) & 1 )
        {
          v17 = v9->ExternalIntfRetVal.Bonus.pWeakProxy;
          v18 = v17->RefCount-- == 1;
          if ( v18 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v9->ExternalIntfRetVal.Bonus.pWeakProxy = 0i64;
          v9->ExternalIntfRetVal.value.VNumber = 0.0;
          v9->ExternalIntfRetVal.value.VS._2.VObj = 0i64;
          v9->ExternalIntfRetVal.Flags &= 0xFFFFFDE0;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v9->ExternalIntfRetVal);
        }
      }
      v9->ExternalIntfRetVal.Flags &= 0xFFFFFFE0;
      v19 = 0i64;
      if ( resulta.pNode->Size )
        v19 = resulta.pNode->pData;
      ((void (__fastcall *)(Scaleform::GFx::ExternalInterface *, Scaleform::GFx::MovieImpl *, const char *, char *, _DWORD))v10->pExtIntfHandler.pObject->vfptr[1].__vecDelDtor)(
        v10->pExtIntfHandler.pObject,
        v10,
        v19,
        v12,
        v11);
      Scaleform::GFx::AS3::Value::Assign(v6, &v9->ExternalIntfRetVal);
      if ( (_DWORD)v11 )
      {
        v20 = v12 + 16;
        v21 = (unsigned int)v11;
        do
        {
          if ( (*((_DWORD *)v20 + 2) >> 6) & 1 )
          {
            (*(void (__fastcall **)(_QWORD, _QWORD *, _QWORD))(*(_QWORD *)*v20 + 16i64))(*v20, v20 - 2, v20[2]);
            *v20 = 0i64;
          }
          *((_DWORD *)v20 + 2) = 0;
          v20 += 6;
          --v21;
        }
        while ( v21 );
      }
      if ( (unsigned int)v11 > 0xA )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v12);
      goto LABEL_28;
    }
LABEL_6:
    v12 = &v26;
    goto LABEL_7;
  }
LABEL_28:
  v22 = resulta.pNode;
  v18 = resulta.pNode->RefCount == 1;
  --v22->RefCount;
  if ( v18 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v22);
}

// File Line: 213
// RVA: 0x1589D40
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface_0_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D6E0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,0,bool>::Method = Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::availableGet;
  return result;
}

// File Line: 214
// RVA: 0x1589CE0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface_1_bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D6F0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,1,bool>::Method = Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::marshallExceptionsGet;
  return result;
}

// File Line: 215
// RVA: 0x1590790
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface_2_Scaleform::GFx::AS3::Value_const__bool_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D700 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,2,Scaleform::GFx::AS3::Value const,bool>::Method = Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::marshallExceptionsSet;
  return result;
}

// File Line: 216
// RVA: 0x1589D10
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface_3_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D710 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,3,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::objectIDGet;
  return result;
}

// File Line: 217
// RVA: 0x1594FF0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface_4_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::ASString_const_____ptr64_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D720 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,4,Scaleform::GFx::AS3::Value const,Scaleform::GFx::ASString const &,Scaleform::GFx::AS3::Value const &>::Method = Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::addCallback;
  return result;
}

// File Line: 218
// RVA: 0x1595020
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc2_Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface_5_Scaleform::GFx::AS3::Value_unsigned_int_Scaleform::GFx::AS3::Value_const_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243D730 = v1;
  Scaleform::GFx::AS3::ThunkFunc2<Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface,5,Scaleform::GFx::AS3::Value,unsigned int,Scaleform::GFx::AS3::Value const *>::Method = (void (__fastcall *const )(Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface *, Scaleform::GFx::AS3::Value *, unsigned int, Scaleform::GFx::AS3::Value *))Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::call;
  return result;
}

// File Line: 251
// RVA: 0x759540
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_external::ExternalInterface::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rbx
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rdi
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rdi
  Scaleform::GFx::AS3::Class *v9; // rax
  Scaleform::GFx::AS3::Class *v10; // rdi

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_external::ExternalInterfaceCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_external::ExternalInterface::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(
      v7,
      v2,
      &Scaleform::GFx::AS3::fl_external::ExternalInterfaceCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  v10 = v9;
  if ( v9 )
  {
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
    v10->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Classes::fl_external::ExternalInterface::`vftable;
  }
  return v3;
}

