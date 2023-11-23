// File Line: 31
// RVA: 0x6F44C0
unsigned int __fastcall Scaleform::GFx::AS2::Math::GetNextRandom(Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::GFx::TestStream *pObject; // rdi
  unsigned int Random; // ebx
  unsigned int result; // eax
  unsigned int v4; // ebx
  Scaleform::LongFormatter v5; // [rsp+30h] [rbp-68h] BYREF
  Scaleform::String v6; // [rsp+A0h] [rbp+8h] BYREF
  Scaleform::Render::RenderBuffer *v7; // [rsp+A8h] [rbp+10h] BYREF

  pObject = Scaleform::GFx::StateBag::GetTestStream(
              &proot->Scaleform::GFx::StateBag,
              (Scaleform::Ptr<Scaleform::GFx::TestStream> *)&v7)->pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  if ( !pObject )
    return Scaleform::Alg::Random::NextRandom();
  if ( pObject->TestStatus )
  {
    Scaleform::String::String(&v6);
    ((void (__fastcall *)(Scaleform::GFx::TestStream *, const char *, Scaleform::String *))pObject->vfptr[1].__vecDelDtor)(
      pObject,
      "random",
      &v6);
    result = strtoul((const char *)((v6.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), 0i64, 10);
    v4 = result;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v6.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      return v4;
    }
  }
  else
  {
    Random = Scaleform::Alg::Random::NextRandom();
    Scaleform::LongFormatter::LongFormatter(&v5, Random);
    Scaleform::LongFormatter::Convert(&v5);
    ((void (__fastcall *)(Scaleform::GFx::TestStream *, const char *, char *))pObject->vfptr[2].__vecDelDtor)(
      pObject,
      "random",
      v5.ValueStr);
    v5.Scaleform::String::InitStruct::vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable;
    Scaleform::Formatter::~Formatter(&v5);
    return Random;
  }
  return result;
}

// File Line: 94
// RVA: 0x6CA2F0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::MathCtorFunction(
        Scaleform::GFx::AS2::MathCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v6; // zf
  Scaleform::GFx::ASString *v7; // rax
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASString *v9; // rax
  Scaleform::GFx::ASStringNode *v10; // rcx
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASString *v13; // rax
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASString *v15; // rax
  Scaleform::GFx::ASStringNode *v16; // rcx
  Scaleform::GFx::ASString *v17; // rax
  Scaleform::GFx::ASStringNode *v18; // rcx
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASStringNode *v20; // rcx
  Scaleform::GFx::AS2::Value v21; // [rsp+38h] [rbp-28h] BYREF
  char v22; // [rsp+90h] [rbp+30h] BYREF
  Scaleform::GFx::ASString result; // [rsp+98h] [rbp+38h] BYREF

  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(this, psc, Scaleform::GFx::AS2::StageCtorFunction::GlobalCtor);
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MathCtorFunction::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MathCtorFunction::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_2_718281828459045;
  v4 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "E");
  v22 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v4,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  pNode = result.pNode;
  v6 = result.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_0_6931471805599453;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "LN2");
  v22 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v7,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v8 = result.pNode;
  v6 = result.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_1_442695040888963;
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "LOG2E");
  v22 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v9,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v10 = result.pNode;
  v6 = result.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_2_302585092994046;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "LN10");
  v22 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v11,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v12 = result.pNode;
  v6 = result.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_0_4342944819032518;
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "LOG10E");
  v22 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v13,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v14 = result.pNode;
  v6 = result.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_3_141592653589793;
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "PI");
  v22 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v15,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v16 = result.pNode;
  v6 = result.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_0_7071067811865476;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "SQRT1_2");
  v22 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v17,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v18 = result.pNode;
  v6 = result.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_1_414213562373095;
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(psc, &result, "SQRT2");
  v22 = 0;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    v19,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v20 = result.pNode;
  v6 = result.pNode->RefCount-- == 1;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Scaleform::GFx::AS2::MathCtorFunction::StaticFunctionTable,
    7);
}

// File Line: 111
// RVA: 0x6BAFE0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Random(Scaleform::GFx::AS2::FnCall *fn)
{
  int NextRandom; // eax
  Scaleform::GFx::AS2::Value *Result; // rbx
  double v4; // xmm6_8

  NextRandom = Scaleform::GFx::AS2::Math::GetNextRandom(fn->Env->Target->pASRoot->pMovieImpl);
  Result = fn->Result;
  v4 = (double)NextRandom * 2.328306437080797e-10;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->NV.NumberValue = v4;
  Result->T.Type = 3;
}

// File Line: 117
// RVA: 0x6BB960
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Round(Scaleform::GFx::AS2::FnCall *fn)
{
  __int128 v1; // xmm0
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v5; // rcx
  __m128d v6; // xmm6
  int v7; // ecx
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v5 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v6.m128d_f64[1] = *((long double *)&v1 + 1);
  v6.m128d_f64[0] = Scaleform::GFx::AS2::Value::ToNumber(v5, Env) + 0.5;
  v7 = (int)v6.m128d_f64[0];
  if ( (double)v7 != v6.m128d_f64[0] )
    v6.m128d_f64[0] = (double)(v7 - (_mm_movemask_pd(_mm_unpacklo_pd(v6, v6)) & 1));
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->V.pStringNode = *(Scaleform::GFx::ASStringNode **)&v6.m128d_f64[0];
  Result->T.Type = 3;
}

// File Line: 129
// RVA: 0x70DB00
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::MathCtorFunction::Register(
        Scaleform::GFx::AS2::FunctionRef *result,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::MathCtorFunction *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Math,Scaleform::GFx::AS2::Environment> *v6; // rbx
  Scaleform::GFx::AS2::Object *Prototype; // rax
  Scaleform::GFx::AS2::Object *pObject; // r14
  Scaleform::GFx::ASStringNode *Function; // rax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rdx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-30h] BYREF
  Scaleform::GFx::AS2::Value v14; // [rsp+50h] [rbp-20h] BYREF
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+A8h] [rbp+38h] BYREF
  void *v16; // [rsp+B0h] [rbp+40h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *p_objproto; // [rsp+B8h] [rbp+48h]

  psc.pContext = pgc;
  psc.SWFVersion = 8;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::MathCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, __int64))objproto.pObject->vfptr[3].Finalize_GC)(
                                                  result,
                                                  104i64);
  v16 = v4;
  if ( v4 )
    Scaleform::GFx::AS2::MathCtorFunction::MathCtorFunction(v4, &psc);
  result->Flags = 0;
  result->Function = v4;
  result->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v6 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Math,Scaleform::GFx::AS2::Environment> *)((__int64 (__fastcall *)(__int64, __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(v5, 160i64, 0i64);
  v16 = v6;
  if ( v6 )
  {
    Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(pgc, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Math,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::Math,Scaleform::GFx::AS2::Environment>(
      v6,
      &psc,
      Prototype,
      result);
    v6->Scaleform::GFx::AS2::Math::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MathProto::`vftable{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>};
    v6->Scaleform::GFx::AS2::Math::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MathProto::`vftable{for `Scaleform::GFx::AS2::ObjectInterface};
    v6->Scaleform::GFx::AS2::GASPrototypeBase::vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::MathProto::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v16 = v6;
  p_objproto = &objproto;
  if ( v6 )
    v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = v6;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    pgc,
    ASBuiltin_Math,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  pObject = pgc->pGlobal.pObject;
  v14.T.Type = 8;
  v14.V.FunctionValue.Flags = 0;
  Function = (Scaleform::GFx::ASStringNode *)result->Function;
  v14.V.pStringNode = Function;
  if ( Function )
  {
    ++Function->RefCount;
    Function->RefCount &= 0x8FFFFFFF;
  }
  v14.V.FunctionValue.pLocalFrame = 0i64;
  pLocalFrame = result->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&v14.V.FunctionValue, pLocalFrame, result->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  pObject->Scaleform::GFx::AS2::ObjectInterface::vfptr->SetMemberRaw(
    &pObject->Scaleform::GFx::AS2::ObjectInterface,
    &psc,
    (Scaleform::GFx::ASString *)&pgc->pMovieRoot->pASMovieRoot.pObject[12].AVMVersion,
    &v14,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  return result;
}

