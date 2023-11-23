// File Line: 65
// RVA: 0x6E8A20
void __fastcall Scaleform::GFx::AS2::ValueProperty::ExecuteForEachChild_GC(
        Scaleform::GFx::AS2::ValueProperty *this,
        Scaleform::GFx::AS2::RefCountCollector<323> *prcc,
        Scaleform::GFx::AS2::RefCountBaseGC<323>::OperationGC operation)
{
  int v5; // r8d

  if ( operation )
  {
    v5 = operation - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          &this->GetterMethod,
          prcc);
        Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ScanInUseFunctor>(
          &this->SetterMethod,
          prcc);
      }
    }
    else
    {
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        &this->GetterMethod,
        prcc);
      Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::MarkInCycleFunctor>(
        &this->SetterMethod,
        prcc);
    }
  }
  else
  {
    Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      &this->GetterMethod,
      prcc);
    Scaleform::GFx::AS2::FunctionRefBase::ForEachChild_GC<Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseFunctor>(
      &this->SetterMethod,
      prcc);
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
bool __fastcall Scaleform::GFx::AS2::Value::TypesMatch(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Value *val)
{
  if ( this->T.Type == val->T.Type )
    return 1;
  return (unsigned __int8)(this->T.Type - 3) <= 1u && (unsigned __int8)(val->T.Type - 3) <= 1u;
}

// File Line: 306
// RVA: 0x7221B0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::AS2::Value::ToString(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::ASString *result,
        Scaleform::GFx::AS2::Environment *penv,
        int precision)
{
  Scaleform::GFx::AS2::Value::ToStringImpl(this, result, penv, precision, 0);
  return result;
}

// File Line: 346
// RVA: 0x71C3D0
void __fastcall Scaleform::GFx::AS2::Value::SetString(Scaleform::GFx::AS2::Value *this, Scaleform::GFx::ASString *str)
{
  Scaleform::GFx::ASStringNode *pNode; // rax

  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 5;
  pNode = str->pNode;
  this->NV.8 = ($B8BD913BABC9324639AA48504BEFB2FC)str->pNode;
  ++pNode->RefCount;
}

// File Line: 347
// RVA: 0x71A290
void __fastcall Scaleform::GFx::AS2::Value::SetNumber(Scaleform::GFx::AS2::Value *this, long double val)
{
  if ( this->T.Type < 5u )
  {
    this->NV.NumberValue = val;
    this->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->NV.NumberValue = val;
    this->T.Type = 3;
  }
}

// File Line: 348
// RVA: 0x7132D0
void __fastcall Scaleform::GFx::AS2::Value::SetBool(Scaleform::GFx::AS2::Value *this, bool val)
{
  Scaleform::GFx::AS2::Value::DropRefs(this);
  this->T.Type = 2;
  this->V.BooleanValue = val;
}

// File Line: 349
// RVA: 0x714BB0
void __fastcall Scaleform::GFx::AS2::Value::SetInt(Scaleform::GFx::AS2::Value *this, int val)
{
  if ( this->T.Type < 5u )
  {
    this->T.Type = 4;
    this->NV.Int32Value = val;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(this);
    this->T.Type = 4;
    this->NV.Int32Value = val;
  }
}

// File Line: 375
// RVA: 0x6DA660
void __fastcall Scaleform::GFx::AS2::Value::And(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  int v5; // esi
  int v6; // esi

  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToInt32(this, penv) & v5;
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->NV.Int32Value = v6;
  this->T.Type = 4;
}

// File Line: 376
// RVA: 0x707B90
void __fastcall Scaleform::GFx::AS2::Value::Or(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  int v5; // esi
  int v6; // esi

  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToInt32(this, penv) | v5;
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->NV.Int32Value = v6;
  this->T.Type = 4;
}

// File Line: 377
// RVA: 0x724D40
void __fastcall Scaleform::GFx::AS2::Value::Xor(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  int v5; // esi
  int v6; // esi

  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToInt32(this, penv) ^ v5;
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->NV.Int32Value = v6;
  this->T.Type = 4;
}

// File Line: 378
// RVA: 0x71FBA0
void __fastcall Scaleform::GFx::AS2::Value::Shl(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  char v5; // bl
  int v6; // edi

  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToInt32(this, penv) << v5;
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->NV.Int32Value = v6;
  this->T.Type = 4;
}

// File Line: 379
// RVA: 0x6DA8D0
void __fastcall Scaleform::GFx::AS2::Value::Asr(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  char v5; // bl
  int v6; // edi

  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToInt32(this, penv) >> v5;
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->NV.Int32Value = v6;
  this->T.Type = 4;
}

// File Line: 380
// RVA: 0x702BB0
void __fastcall Scaleform::GFx::AS2::Value::Lsr(
        Scaleform::GFx::AS2::Value *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::Value *v)
{
  char v5; // bl
  int v6; // edi

  v5 = Scaleform::GFx::AS2::Value::ToInt32(v, penv);
  v6 = Scaleform::GFx::AS2::Value::ToUInt32(this, penv) >> v5;
  if ( this->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(this);
  this->NV.Int32Value = v6;
  this->T.Type = 4;
}

// File Line: 432
// RVA: 0x6C88A0
void __fastcall Scaleform::GFx::AS2::FnCall::FnCall(
        Scaleform::GFx::AS2::FnCall *this,
        Scaleform::GFx::AS2::Value *ResIn,
        Scaleform::GFx::AS2::ObjectInterface *ThisIn,
        Scaleform::GFx::AS2::Environment *EnvIn,
        int NargsIn,
        int FirstIn)
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
void __fastcall Scaleform::GFx::AS2::FnCall::FnCall(
        Scaleform::GFx::AS2::FnCall *this,
        Scaleform::GFx::AS2::Value *ResIn,
        Scaleform::GFx::AS2::Value *ThisIn,
        Scaleform::GFx::AS2::Environment *EnvIn,
        int NargsIn,
        int FirstIn)
{
  Scaleform::GFx::AS2::FunctionRef *v9; // rax
  char Flags; // al
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v14; // eax
  Scaleform::GFx::AS2::FunctionRef result; // [rsp+28h] [rbp-30h] BYREF

  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
  this->Result = ResIn;
  this->ThisPtr = Scaleform::GFx::AS2::Value::ToObjectInterface(ThisIn, EnvIn);
  this->ThisFunctionRef.Flags = 0;
  this->ThisFunctionRef.Function = 0i64;
  this->ThisFunctionRef.pLocalFrame = 0i64;
  this->Env = EnvIn;
  this->NArgs = NargsIn;
  this->FirstArgBottomIndex = FirstIn;
  if ( ThisIn->T.Type == 8 || ThisIn->T.Type == 11 )
  {
    v9 = Scaleform::GFx::AS2::Value::ToFunction(ThisIn, &result, EnvIn);
    Scaleform::GFx::AS2::FunctionRefBase::Assign(&this->ThisFunctionRef, v9);
    Flags = result.Flags;
    if ( (result.Flags & 2) == 0 )
    {
      Function = result.Function;
      if ( result.Function )
      {
        RefCount = result.Function->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          result.Function->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
          Flags = result.Flags;
        }
      }
    }
    result.Function = 0i64;
    if ( (Flags & 1) == 0 )
    {
      pLocalFrame = result.pLocalFrame;
      if ( result.pLocalFrame )
      {
        v14 = result.pLocalFrame->RefCount;
        if ( (v14 & 0x3FFFFFF) != 0 )
        {
          result.pLocalFrame->RefCount = v14 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
        }
      }
    }
  }
}

// File Line: 448
// RVA: 0x6D14B0
void __fastcall Scaleform::GFx::AS2::FnCall::~FnCall(Scaleform::GFx::AS2::FnCall *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // rcx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // rcx
  unsigned int v5; // eax

  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable;
  if ( (this->ThisFunctionRef.Flags & 2) == 0 )
  {
    Function = this->ThisFunctionRef.Function;
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  this->ThisFunctionRef.Function = 0i64;
  if ( (this->ThisFunctionRef.Flags & 1) == 0 )
  {
    pLocalFrame = this->ThisFunctionRef.pLocalFrame;
    if ( pLocalFrame )
    {
      v5 = pLocalFrame->RefCount;
      if ( (v5 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v5 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->ThisFunctionRef.pLocalFrame = 0i64;
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::FnCall>::`vftable;
}

