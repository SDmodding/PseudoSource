// File Line: 65
// RVA: 0x6E8A20
void __fastcall Scaleform::GFx::AS2::ValueProperty::ExecuteForEachChild_GC(Scaleform::GFx::AS2::ValueProperty *this, Scaleform::GFx::AS2::RefCountCollector<323> *prcc, Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  Scaleform::GFx::AS2::RefCountCollector<323> *v3; // rbx
  Scaleform::GFx::AS2::ValueProperty *v4; // rdi
  __int32 v5; // er8

  v3 = prcc;
  v4 = this;
  if ( operation )
  {
    v5 = operation - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          (Scaleform::GFx::AS2::FunctionRefBase *)&this->GetterMethod.Function,
          prcc);
        Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          (Scaleform::GFx::AS2::FunctionRefBase *)&v4->SetterMethod.Function,
          v3);
      }
    }
    else
    {
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        (Scaleform::GFx::AS2::FunctionRefBase *)&this->GetterMethod.Function,
        prcc);
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        (Scaleform::GFx::AS2::FunctionRefBase *)&v4->SetterMethod.Function,
        v3);
    }
  }
  else
  {
    Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      (Scaleform::GFx::AS2::FunctionRefBase *)&this->GetterMethod.Function,
      prcc);
    Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v4->SetterMethod.Function,
      v3);
  }
}

// File Line: 185
// RVA: 0x6CD8C0
void __fastcall Scaleform::GFx::AS2::Value::Value(UFG::PersistentData::Bool *this)
{
  this->mValue = 0;
}

// File Line: 270
// RVA: 0x722B60
char __fastcall Scaleform::GFx::AS2::Value::TypesMatch(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Value *val)
{
  if ( this->T.Type == val->T.Type )
    return 1;
  if ( (unsigned __int8)(this->T.Type - 3) > 1u || (unsigned __int8)(val->T.Type - 3) > 1u )
    return 0;
  return 1;
}

// File Line: 306
// RVA: 0x7221B0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Value::ToString(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::ASString *result, Scaleform::GFx::AS2::Environment *penv, int precision)
{
  Scaleform::GFx::ASString *v4; // rbx

  v4 = result;
  Scaleform::GFx::AS2::Value::ToStringImpl(this, result, penv, precision, 0);
  return v4;
}

// File Line: 346
// RVA: 0x71C3D0
void __fastcall Scaleform::GFx::AS2::Value::SetString(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASString *v2; // rdi
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::ASStringNode *v4; // rax

  v2 = str;
  v3 = this;
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  v3->T.Type = 5;
  v4 = v2->pNode;
  v3->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)v2->pNode;
  ++v4->RefCount;
}

// File Line: 347
// RVA: 0x71A290
void __fastcall Scaleform::GFx::AS2::Value::SetNumber(Scaleform::GFx::AS2::Value *this, long double val)
{
  Scaleform::GFx::AS2::Value *v2; // rbx

  v2 = this;
  if ( this->T.Type < 5u )
  {
    this->NV.NumberValue = val;
    this->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    v2->NV.NumberValue = val;
    v2->T.Type = 3;
  }
}

// File Line: 348
// RVA: 0x7132D0
void __fastcall Scaleform::GFx::AS2::Value::SetBool(Scaleform::GFx::AS2::Value *this, bool val)
{
  bool v2; // di
  Scaleform::GFx::AS2::Value *v3; // rbx

  v2 = val;
  v3 = this;
  Scaleform::GFx::AS2::Value::DropRefs(this);
  v3->T.Type = 2;
  v3->V.BooleanValue = v2;
}

// File Line: 349
// RVA: 0x714BB0
void __fastcall Scaleform::GFx::AS2::Value::SetInt(Scaleform::GFx::AS2::Value *this, unsigned int val)
{
  unsigned int v2; // edi
  Scaleform::GFx::AS2::Value *v3; // rbx

  v2 = val;
  v3 = this;
  if ( this->T.Type < 5u )
  {
    this->T.Type = 4;
    this->NV.Int32Value = val;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    v3->T.Type = 4;
    v3->NV.Int32Value = v2;
  }
}

// File Line: 375
// RVA: 0x6DA660
void __fastcall Scaleform::GFx::AS2::Value::And(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // rbx
  int v5; // esi
  int v6; // esi

  v3 = this;
  v4 = penv;
  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToInt32(v3, v4) & v5;
  if ( v3->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v3);
  v3->NV.Int32Value = v6;
  v3->T.Type = 4;
}

// File Line: 376
// RVA: 0x707B90
void __fastcall Scaleform::GFx::AS2::Value::Or(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rdi
  Scaleform::GFx::AS2::Environment *v4; // rbx
  int v5; // esi
  int v6; // esi

  v3 = this;
  v4 = penv;
  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToInt32(v3, v4) | v5;
  if ( v3->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v3);
  v3->NV.Int32Value = v6;
  v3->T.Type = 4;
}

// File Line: 377
// RVA: 0x724D40
void __usercall Scaleform::GFx::AS2::Value::Xor(Scaleform::GFx::AS2::Value *this@<rcx>, Scaleform::GFx::AS2::Environment *penv@<rdx>, Scaleform::GFx::AS2::Value *v@<r8>, __m128d *a4@<xmm0>)
{
  Scaleform::GFx::AS2::Value *v4; // rdi
  Scaleform::GFx::AS2::Environment *v5; // rbx
  int v6; // esi
  int v7; // esi

  v4 = this;
  v5 = penv;
  v6 = Scaleform::GFx::AS2::Value::ToInt32(v, penv, a4);
  v7 = (unsigned __int64)Scaleform::GFx::AS2::Value::ToInt32(v4, v5, a4) ^ v6;
  if ( v4->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v4);
  v4->NV.Int32Value = v7;
  v4->T.Type = 4;
}

// File Line: 378
// RVA: 0x71FBA0
void __fastcall Scaleform::GFx::AS2::Value::Shl(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rsi
  Scaleform::GFx::AS2::Environment *v4; // rdi
  char v5; // bl
  int v6; // edi

  v3 = this;
  v4 = penv;
  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToInt32(v3, v4) << v5;
  if ( v3->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v3);
  v3->NV.Int32Value = v6;
  v3->T.Type = 4;
}

// File Line: 379
// RVA: 0x6DA8D0
void __fastcall Scaleform::GFx::AS2::Value::Asr(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rsi
  Scaleform::GFx::AS2::Environment *v4; // rdi
  char v5; // bl
  int v6; // edi

  v3 = this;
  v4 = penv;
  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToInt32(v3, v4) >> v5;
  if ( v3->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v3);
  v3->NV.Int32Value = v6;
  v3->T.Type = 4;
}

// File Line: 380
// RVA: 0x702BB0
void __fastcall Scaleform::GFx::AS2::Value::Lsr(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::AS2::Environment *penv, Scaleform::GFx::AS2::Value *v)
{
  Scaleform::GFx::AS2::Value *v3; // rsi
  Scaleform::GFx::AS2::Environment *v4; // rdi
  char v5; // bl
  unsigned int v6; // edi

  v3 = this;
  v4 = penv;
  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToUInt32(v3, v4) >> v5;
  if ( v3->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v3);
  v3->NV.Int32Value = v6;
  v3->T.Type = 4;
}

// File Line: 432
// RVA: 0x6C88A0
void __fastcall Scaleform::GFx::AS2::FnCall::FnCall(Scaleform::GFx::AS2::FnCall *this, Scaleform::GFx::AS2::Value *ResIn, Scaleform::GFx::AS2::ObjectInterface *ThisIn, Scaleform::GFx::AS2::Environment *EnvIn, int NargsIn, int FirstIn)
{
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
  this->Result = ResIn;
  this->ThisPtr = ThisIn;
  this->ThisFunctionRef.Flags = 0;
  this->ThisFunctionRef.Function = 0i64;
  this->ThisFunctionRef.pLocalFrame = 0i64;
  this->Env = EnvIn;
  this->NArgs = NargsIn;
  this->FirstArgBottomIndex = FirstIn;
}

// File Line: 442
// RVA: 0x6C8790
void __fastcall Scaleform::GFx::AS2::FnCall::FnCall(Scaleform::GFx::AS2::FnCall *this, Scaleform::GFx::AS2::Value *ResIn, Scaleform::GFx::AS2::Value *ThisIn, Scaleform::GFx::AS2::Environment *EnvIn, int NargsIn, int FirstIn)
{
  Scaleform::GFx::AS2::Environment *v6; // rsi
  Scaleform::GFx::AS2::Value *v7; // r14
  Scaleform::GFx::AS2::FnCall *v8; // rbx
  Scaleform::GFx::AS2::FunctionRef *v9; // rax
  char v10; // al
  Scaleform::GFx::AS2::FunctionObject *v11; // rcx
  unsigned int v12; // edx
  Scaleform::GFx::AS2::LocalFrame *v13; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-30h]

  v6 = EnvIn;
  v7 = ThisIn;
  v8 = this;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
  this->Result = ResIn;
  this->ThisPtr = Scaleform::GFx::AS2::Value::ToObjectInterface(ThisIn, EnvIn);
  v8->ThisFunctionRef.Flags = 0;
  v8->ThisFunctionRef.Function = 0i64;
  v8->ThisFunctionRef.pLocalFrame = 0i64;
  v8->Env = v6;
  v8->NArgs = NargsIn;
  v8->FirstArgBottomIndex = FirstIn;
  if ( v7->T.Type == 8 || v7->T.Type == 11 )
  {
    v9 = Scaleform::GFx::AS2::Value::ToFunction(v7, &result, v6);
    Scaleform::GFx::AS2::FunctionRefBase::Assign(
      (Scaleform::GFx::AS2::FunctionRefBase *)&v8->ThisFunctionRef.Function,
      (Scaleform::GFx::AS2::FunctionRefBase *)&v9->Function);
    v10 = result.Flags;
    if ( !(result.Flags & 2) )
    {
      v11 = result.Function;
      if ( result.Function )
      {
        v12 = result.Function->RefCount;
        if ( v12 & 0x3FFFFFF )
        {
          result.Function->RefCount = v12 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v11->vfptr);
          v10 = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( !(v10 & 1) )
    {
      v13 = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v14 = result.pLocalFrame->RefCount;
        if ( v14 & 0x3FFFFFF )
        {
          result.pLocalFrame->RefCount = v14 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v13->vfptr);
        }
      }
    }
  }
}

// File Line: 448
// RVA: 0x6D14B0
void __fastcall Scaleform::GFx::AS2::FnCall::~FnCall(Scaleform::GFx::AS2::FnCall *this)
{
  Scaleform::GFx::AS2::FnCall *v1; // rbx
  Scaleform::GFx::AS2::FunctionObject *v2; // rcx
  unsigned int v3; // eax
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // rcx
  unsigned int v5; // eax

  v1 = this;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
  if ( !(this->ThisFunctionRef.Flags & 2) )
  {
    v2 = this->ThisFunctionRef.Function;
    if ( v2 )
    {
      v3 = v2->RefCount;
      if ( v3 & 0x3FFFFFF )
      {
        v2->RefCount = v3 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal((Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v2->vfptr);
      }
    }
  }
  v1->ThisFunctionRef.Function = 0i64;
  if ( !(v1->ThisFunctionRef.Flags & 1) )
  {
    v4 = (Scaleform::GFx::AS2::RefCountBaseGC<323> *)&v1->ThisFunctionRef.pLocalFrame->vfptr;
    if ( v4 )
    {
      v5 = v4->RefCount;
      if ( v5 & 0x3FFFFFF )
      {
        v4->RefCount = v5 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
      }
    }
  }
  v1->ThisFunctionRef.pLocalFrame = 0i64;
  v1->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
}

