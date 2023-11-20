// File Line: 31
// RVA: 0x6F44C0
unsigned int __fastcall Scaleform::GFx::AS2::Math::GetNextRandom(Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::GFx::TestStream *v1; // rdi
  unsigned int v2; // ebx
  unsigned int result; // eax
  unsigned int v4; // ebx
  Scaleform::LongFormatter v5; // [rsp+30h] [rbp-68h]
  Scaleform::String v6; // [rsp+A0h] [rbp+8h]
  Scaleform::Render::RenderBuffer *v7; // [rsp+A8h] [rbp+10h]

  v1 = Scaleform::GFx::StateBag::GetTestStream(
         (Scaleform::GFx::StateBag *)&proot->vfptr,
         (Scaleform::Ptr<Scaleform::GFx::TestStream> *)&v7)->pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release(v7);
  if ( !v1 )
    return Scaleform::Alg::Random::NextRandom();
  if ( v1->TestStatus )
  {
    Scaleform::String::String(&v6);
    ((void (__fastcall *)(Scaleform::GFx::TestStream *, const char *, Scaleform::String *))v1->vfptr[1].__vecDelDtor)(
      v1,
      "random",
      &v6);
    result = strtoul((const char *)((v6.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 12), 0i64, 10);
    v4 = result;
    if ( !_InterlockedDecrement((volatile signed __int32 *)((v6.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8)) )
    {
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      result = v4;
    }
  }
  else
  {
    v2 = Scaleform::Alg::Random::NextRandom();
    Scaleform::LongFormatter::LongFormatter(&v5, v2);
    Scaleform::LongFormatter::Convert(&v5);
    ((void (__fastcall *)(Scaleform::GFx::TestStream *, const char *, char *))v1->vfptr[2].__vecDelDtor)(
      v1,
      "random",
      v5.ValueStr);
    v5.vfptr = (Scaleform::String::InitStructVtbl *)&Scaleform::String::InitStruct::`vftable';
    Scaleform::Formatter::~Formatter((Scaleform::Formatter *)&v5.vfptr);
    result = v2;
  }
  return result;
}

// File Line: 94
// RVA: 0x6CA2F0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::MathCtorFunction(Scaleform::GFx::AS2::MathCtorFunction *this, Scaleform::GFx::AS2::ASStringContext *psc)
{
  Scaleform::GFx::AS2::ASStringContext *v2; // rbx
  Scaleform::GFx::AS2::MathCtorFunction *v3; // rsi
  Scaleform::GFx::ASString *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rcx
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
  Scaleform::GFx::AS2::Value v21; // [rsp+38h] [rbp-28h]
  char v22; // [rsp+90h] [rbp+30h]
  Scaleform::GFx::ASString result; // [rsp+98h] [rbp+38h]

  v2 = psc;
  v3 = this;
  Scaleform::GFx::AS2::CFunctionObject::CFunctionObject(
    (Scaleform::GFx::AS2::CFunctionObject *)&this->vfptr,
    psc,
    Scaleform::GFx::AS2::StageCtorFunction::GlobalCtor);
  v3->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MathCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  v3->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MathCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_2_718281828459045;
  v4 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v2, &result, "E");
  v22 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    v4,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v5 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_0_6931471805599453;
  v7 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v2, &result, "LN2");
  v22 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    v7,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v8 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v8->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v8);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_1_442695040888963;
  v9 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v2, &result, "LOG2E");
  v22 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    v9,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v10 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v10->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_2_302585092994046;
  v11 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v2, &result, "LN10");
  v22 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    v11,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v12 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v12->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_0_4342944819032518;
  v13 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v2, &result, "LOG10E");
  v22 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    v13,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v14 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v14->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v14);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_3_141592653589793;
  v15 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v2, &result, "PI");
  v22 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    v15,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v16 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v16->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_0_7071067811865476;
  v17 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v2, &result, "SQRT1_2");
  v22 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    v17,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v18 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v18->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v18);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  v21.T.Type = 3;
  v21.NV.NumberValue = DOUBLE_1_414213562373095;
  v19 = Scaleform::GFx::AS2::ASStringContext::CreateConstString(v2, &result, "SQRT2");
  v22 = 0;
  v3->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    v19,
    &v21,
    (Scaleform::GFx::AS2::PropFlags *)&v22);
  v20 = result.pNode;
  v6 = result.pNode->RefCount == 1;
  --v20->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v20);
  if ( v21.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v21);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    (Scaleform::GFx::AS2::ObjectInterface *)&v3->vfptr,
    v2,
    Scaleform::GFx::AS2::MathCtorFunction::StaticFunctionTable,
    7);
}

// File Line: 111
// RVA: 0x6BAFE0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Random(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  signed int v2; // eax
  Scaleform::GFx::AS2::Value *v3; // rbx
  double v4; // xmm6_8

  v1 = fn;
  v2 = Scaleform::GFx::AS2::Math::GetNextRandom(fn->Env->Target->pASRoot->pMovieImpl);
  v3 = v1->Result;
  v4 = (double)v2 * 2.328306437080797e-10;
  if ( v3->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v3);
  v3->NV.NumberValue = v4;
  v3->T.Type = 3;
}

// File Line: 117
// RVA: 0x6BB960
void __usercall Scaleform::GFx::AS2::MathCtorFunction::Round(Scaleform::GFx::AS2::FnCall *fn@<rcx>, __int128 a2@<xmm0>)
{
  Scaleform::GFx::AS2::Environment *v2; // r9
  unsigned __int64 v3; // r8
  Scaleform::GFx::AS2::FnCall *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rcx
  __m128d v6; // xmm6
  __int64 v7; // rcx
  Scaleform::GFx::AS2::Value *v8; // rbx

  v2 = fn->Env;
  v3 = (unsigned int)fn->FirstArgBottomIndex;
  v4 = fn;
  v5 = 0i64;
  if ( (unsigned int)v3 <= 32 * (LODWORD(v2->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
    v5 = &v2->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
  v6.m128d_f64[1] = *((long double *)&a2 + 1);
  v6.m128d_f64[0] = Scaleform::GFx::AS2::Value::ToNumber(v5, v2) + 0.5;
  v7 = (unsigned int)(signed int)v6.m128d_f64[0];
  if ( v7 != 0x8000000000000000i64 && (double)(signed int)v7 != v6.m128d_f64[0] )
    v6.m128d_f64[0] = (double)(signed int)(v7 - (_mm_movemask_pd(_mm_unpckl_pd(v6, v6)) & 1));
  v8 = v4->Result;
  if ( v8->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v8);
  v8->V.pStringNode = *(Scaleform::GFx::ASStringNode **)&v6.m128d_f64[0];
  v8->T.Type = 3;
}

// File Line: 129
// RVA: 0x70DB00
Scaleform::GFx::AS2::FunctionRef *__fastcall Scaleform::GFx::AS2::MathCtorFunction::Register(Scaleform::GFx::AS2::FunctionRef *result, Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::AS2::GlobalContext *v2; // rsi
  Scaleform::GFx::AS2::FunctionRef *v3; // rdi
  Scaleform::GFx::AS2::MathCtorFunction *v4; // rax
  __int64 v5; // rcx
  Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Math,Scaleform::GFx::AS2::Environment> *v6; // rbx
  Scaleform::GFx::AS2::Object *v7; // rax
  Scaleform::GFx::AS2::Object *v8; // r14
  Scaleform::GFx::ASStringNode *v9; // rax
  Scaleform::GFx::AS2::LocalFrame *v10; // rdx
  unsigned int v11; // eax
  Scaleform::GFx::AS2::ASStringContext psc; // [rsp+40h] [rbp-30h]
  Scaleform::GFx::AS2::Value v14; // [rsp+50h] [rbp-20h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> objproto; // [rsp+A8h] [rbp+38h]
  void *v16; // [rsp+B0h] [rbp+40h]
  Scaleform::Ptr<Scaleform::GFx::AS2::Object> *v17; // [rsp+B8h] [rbp+48h]

  v2 = pgc;
  v3 = result;
  psc.pContext = pgc;
  psc.SWFVersion = 8;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)pgc->pHeap;
  v4 = (Scaleform::GFx::AS2::MathCtorFunction *)((__int64 (__fastcall *)(Scaleform::GFx::AS2::FunctionRef *, signed __int64))objproto.pObject->vfptr[3].Finalize_GC)(
                                                  result,
                                                  104i64);
  v16 = v4;
  if ( v4 )
    Scaleform::GFx::AS2::MathCtorFunction::MathCtorFunction(v4, &psc);
  v3->Flags = 0;
  v3->Function = (Scaleform::GFx::AS2::FunctionObject *)&v4->vfptr;
  v3->pLocalFrame = 0i64;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)v2->pHeap;
  v6 = (Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Math,Scaleform::GFx::AS2::Environment> *)((__int64 (__fastcall *)(__int64, signed __int64, _QWORD))objproto.pObject->vfptr[3].Finalize_GC)(v5, 160i64, 0i64);
  v16 = v6;
  if ( v6 )
  {
    v7 = Scaleform::GFx::AS2::GlobalContext::GetPrototype(v2, ASBuiltin_Object);
    Scaleform::GFx::AS2::Prototype<Scaleform::GFx::AS2::Math,Scaleform::GFx::AS2::Environment>::Prototype<Scaleform::GFx::AS2::Math,Scaleform::GFx::AS2::Environment>(
      v6,
      &psc,
      v7,
      v3);
    v6->vfptr = (Scaleform::GFx::AS2::RefCountBaseGC<323>Vtbl *)&Scaleform::GFx::AS2::MathProto::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
    v6->vfptr = (Scaleform::GFx::AS2::ObjectInterfaceVtbl *)&Scaleform::GFx::AS2::MathProto::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
    v6->vfptr = (Scaleform::GFx::AS2::GASPrototypeBaseVtbl *)&Scaleform::GFx::AS2::MathProto::`vftable';
  }
  else
  {
    v6 = 0i64;
  }
  v16 = v6;
  v17 = &objproto;
  if ( v6 )
    v6->RefCount = (v6->RefCount + 1) & 0x8FFFFFFF;
  objproto.pObject = (Scaleform::GFx::AS2::Object *)&v6->vfptr;
  Scaleform::GFx::AS2::GlobalContext::SetPrototype(
    v2,
    ASBuiltin_Math,
    (Scaleform::Ptr<Scaleform::GFx::AS2::Object>)&objproto);
  v8 = v2->pGlobal.pObject;
  v14.T.Type = 8;
  v14.V.FunctionValue.Flags = 0;
  v9 = (Scaleform::GFx::ASStringNode *)v3->Function;
  v14.V.pStringNode = v9;
  if ( v9 )
  {
    ++v9->RefCount;
    v9->RefCount &= 0x8FFFFFFF;
  }
  v14.V.FunctionValue.pLocalFrame = 0i64;
  v10 = v3->pLocalFrame;
  if ( v10 )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v14.NV.8,
      v10,
      v3->Flags & 1);
  LOBYTE(objproto.pObject) = 0;
  v8->vfptr->SetMemberRaw(
    (Scaleform::GFx::AS2::ObjectInterface *)&v8->vfptr,
    &psc,
    (Scaleform::GFx::ASString *)&v2->pMovieRoot->pASMovieRoot.pObject[12].AVMVersion,
    &v14,
    (Scaleform::GFx::AS2::PropFlags *)&objproto);
  if ( v14.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v14);
  if ( v6 )
  {
    v11 = v6->RefCount;
    if ( v11 & 0x3FFFFFF )
    {
      v6->RefCount = v11 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  return v3;
}seInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v6->vfptr);
    }
  }
  retu

