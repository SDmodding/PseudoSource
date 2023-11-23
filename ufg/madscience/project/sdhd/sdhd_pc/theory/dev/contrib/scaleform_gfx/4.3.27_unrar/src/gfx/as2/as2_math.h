// File Line: 70
// RVA: 0x6B88D0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Abs(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v4 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->V.pStringNode = (Scaleform::GFx::ASStringNode *)(*(_QWORD *)&v5 & _xmm);
  Result->T.Type = 3;
}

// File Line: 71
// RVA: 0x6B8C10
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Acos(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  long double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v4 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  v6 = acos(v5);
  Result = fn->Result;
  if ( Result->T.Type < 5u )
  {
    Result->NV.NumberValue = v6;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v6;
  }
}

// File Line: 72
// RVA: 0x6B8DE0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Asin(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  long double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v4 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  v6 = asin(v5);
  Result = fn->Result;
  if ( Result->T.Type < 5u )
  {
    Result->NV.NumberValue = v6;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v6;
  }
}

// File Line: 73
// RVA: 0x6B9130
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Atan(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  long double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v4 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  v6 = atan(v5);
  Result = fn->Result;
  if ( Result->T.Type < 5u )
  {
    Result->NV.NumberValue = v6;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v6;
  }
}

// File Line: 74
// RVA: 0x6B9620
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Ceil(Scaleform::GFx::AS2::FnCall *fn)
{
  __m128d v1; // xmm0
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v5; // rcx
  int v6; // ecx
  double v7; // xmm6_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v5 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v1.m128d_f64[0] = Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
  v6 = (int)v1.m128d_f64[0];
  v7 = v1.m128d_f64[0];
  if ( (double)v6 != v1.m128d_f64[0] )
    v7 = (double)(!(_mm_movemask_pd(_mm_unpacklo_pd(v1, v1)) & 1) + v6);
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->NV.NumberValue = v7;
  Result->T.Type = 3;
}

// File Line: 75
// RVA: 0x6B9780
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Cos(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v4 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  v6 = cos(v5);
  Result = fn->Result;
  if ( Result->T.Type < 5u )
  {
    Result->NV.NumberValue = v6;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v6;
  }
}

// File Line: 76
// RVA: 0x6B99E0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Exp(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v4 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  v6 = exp(v5);
  Result = fn->Result;
  if ( Result->T.Type < 5u )
  {
    Result->NV.NumberValue = v6;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v6;
  }
}

// File Line: 77
// RVA: 0x6B9BE0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Floor(Scaleform::GFx::AS2::FnCall *fn)
{
  __m128d v1; // xmm0
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v5; // rcx
  int v6; // ecx
  double v7; // xmm6_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v5 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v1.m128d_f64[0] = Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
  v6 = (int)v1.m128d_f64[0];
  v7 = v1.m128d_f64[0];
  if ( (double)v6 != v1.m128d_f64[0] )
    v7 = (double)(v6 - (_mm_movemask_pd(_mm_unpacklo_pd(v1, v1)) & 1));
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->NV.NumberValue = v7;
  Result->T.Type = 3;
}

// File Line: 78
// RVA: 0x6B9E60
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Log(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v4 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  v6 = log(v5);
  Result = fn->Result;
  if ( Result->T.Type < 5u )
  {
    Result->NV.NumberValue = v6;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v6;
  }
}

// File Line: 79
// RVA: 0x6BA050
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Sin(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v4 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  v6 = sin(v5);
  Result = fn->Result;
  if ( Result->T.Type < 5u )
  {
    Result->NV.NumberValue = v6;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v6;
  }
}

// File Line: 80
// RVA: 0x6BA1D0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Sqrt(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx
  double v7; // xmm6_8

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v4 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  Result = fn->Result;
  v7 = sqrt(v5);
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->NV.NumberValue = v7;
  Result->T.Type = 3;
}

// File Line: 81
// RVA: 0x6BA340
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Tan(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v4; // rcx
  long double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v4 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v4 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
  v6 = tan(v5);
  Result = fn->Result;
  if ( Result->T.Type < 5u )
  {
    Result->NV.NumberValue = v6;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v6;
  }
}

// File Line: 83
// RVA: 0x6BA4D0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Atan2(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::Value *v5; // rcx
  long double v6; // xmm0_8
  Scaleform::GFx::AS2::Environment *v7; // rdx
  long double v8; // xmm6_8
  unsigned __int64 v9; // r8
  long double v10; // xmm0_8
  double v11; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v3 = 0i64;
  v5 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
  v7 = fn->Env;
  v8 = v6;
  v9 = (unsigned int)(fn->FirstArgBottomIndex - 1);
  if ( (unsigned int)v9 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)(v7->Stack.pCurrent - v7->Stack.pPageStart) )
    v3 = &v7->Stack.Pages.Data.Data[v9 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToNumber(v3, v7);
  v11 = atan2(v8, v10);
  Result = fn->Result;
  if ( Result->T.Type < 5u )
  {
    Result->NV.NumberValue = v11;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v11;
  }
}

// File Line: 84
// RVA: 0x6BA8D0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Max(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::Value *v5; // rcx
  long double v6; // xmm0_8
  Scaleform::GFx::AS2::Environment *v7; // rdx
  double v8; // xmm6_8
  unsigned __int64 v9; // r8
  double v10; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v3 = 0i64;
  v5 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
  v7 = fn->Env;
  v8 = v6;
  v9 = (unsigned int)(fn->FirstArgBottomIndex - 1);
  if ( (unsigned int)v9 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)(v7->Stack.pCurrent - v7->Stack.pPageStart) )
    v3 = &v7->Stack.Pages.Data.Data[v9 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToNumber(v3, v7);
  if ( v8 <= v10 )
    v8 = v10;
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  Result->NV.NumberValue = v8;
  Result->T.Type = 3;
}

// File Line: 85
// RVA: 0x6BAB50
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Min(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::Value *v5; // rcx
  long double v6; // xmm0_8
  Scaleform::GFx::AS2::Environment *v7; // rdx
  double v8; // xmm6_8
  unsigned __int64 v9; // r8
  double v10; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v3 = 0i64;
  v5 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
  v7 = fn->Env;
  v8 = v6;
  v9 = (unsigned int)(fn->FirstArgBottomIndex - 1);
  if ( (unsigned int)v9 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)(v7->Stack.pCurrent - v7->Stack.pPageStart) )
    v3 = &v7->Stack.Pages.Data.Data[v9 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToNumber(v3, v7);
  if ( v8 >= v10 )
    v8 = v10;
  Result = fn->Result;
  if ( Result->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
  Result->NV.NumberValue = v8;
  Result->T.Type = 3;
}

// File Line: 86
// RVA: 0x6BAD20
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Pow(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *Env; // r9
  unsigned __int64 FirstArgBottomIndex; // r8
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::Value *v5; // rcx
  long double v6; // xmm0_8
  Scaleform::GFx::AS2::Environment *v7; // rdx
  double v8; // xmm6_8
  unsigned __int64 v9; // r8
  double v10; // xmm0_8
  double v11; // xmm0_8
  Scaleform::GFx::AS2::Value *Result; // rbx

  Env = fn->Env;
  FirstArgBottomIndex = (unsigned int)fn->FirstArgBottomIndex;
  v3 = 0i64;
  v5 = 0i64;
  if ( (unsigned int)FirstArgBottomIndex <= 32 * (LODWORD(Env->Stack.Pages.Data.Size) - 1)
                                          + (unsigned int)(Env->Stack.pCurrent - Env->Stack.pPageStart) )
    v5 = &Env->Stack.Pages.Data.Data[FirstArgBottomIndex >> 5]->Values[FirstArgBottomIndex & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
  v7 = fn->Env;
  v8 = v6;
  v9 = (unsigned int)(fn->FirstArgBottomIndex - 1);
  if ( (unsigned int)v9 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)(v7->Stack.pCurrent - v7->Stack.pPageStart) )
    v3 = &v7->Stack.Pages.Data.Data[v9 >> 5]->Values[(LOBYTE(fn->FirstArgBottomIndex) - 1) & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToNumber(v3, v7);
  v11 = pow(v8, v10);
  Result = fn->Result;
  if ( Result->T.Type < 5u )
  {
    Result->NV.NumberValue = v11;
    Result->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(fn->Result);
    Result->T.Type = 3;
    Result->NV.NumberValue = v11;
  }
}

