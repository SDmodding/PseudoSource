// File Line: 70
// RVA: 0x6B88D0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Abs(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  Scaleform::GFx::AS2::Value *v6; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = fn;
  v4 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v6 = v3->Result;
  if ( v6->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v6);
  v6->V.pStringNode = (Scaleform::GFx::ASStringNode *)(*(_QWORD *)&v5 & _xmm);
  v6->T.Type = 3;
}

// File Line: 71
// RVA: 0x6B8C10
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Acos(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  long double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *v7; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = fn;
  v4 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v6 = acos(v5);
  v7 = v3->Result;
  if ( v7->T.Type < 5u )
  {
    v7->NV.NumberValue = v6;
    v7->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
  }
}

// File Line: 72
// RVA: 0x6B8DE0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Asin(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  long double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *v7; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = fn;
  v4 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v6 = asin(v5);
  v7 = v3->Result;
  if ( v7->T.Type < 5u )
  {
    v7->NV.NumberValue = v6;
    v7->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
  }
}

// File Line: 73
// RVA: 0x6B9130
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Atan(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  long double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *v7; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = fn;
  v4 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v6 = atan(v5);
  v7 = v3->Result;
  if ( v7->T.Type < 5u )
  {
    v7->NV.NumberValue = v6;
    v7->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
  }
}

// File Line: 74
// RVA: 0x6B9620
void __usercall Scaleform::GFx::AS2::MathCtorFunction::Ceil(Scaleform::GFx::AS2::FnCall *fn@<rcx>, __m128d a2@<xmm0>)
{
  Scaleform::GFx::AS2::Environment *v2; // r9
  unsigned __int64 v3; // r8
  Scaleform::GFx::AS2::FnCall *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rcx
  __int64 v6; // rcx
  double v7; // xmm6_8
  Scaleform::GFx::AS2::Value *v8; // rbx

  v2 = fn->Env;
  v3 = (unsigned int)fn->FirstArgBottomIndex;
  v4 = fn;
  v5 = 0i64;
  if ( (unsigned int)v3 <= 32 * (LODWORD(v2->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
    v5 = &v2->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
  a2.m128d_f64[0] = Scaleform::GFx::AS2::Value::ToNumber(v5, v2);
  v6 = (unsigned int)(signed int)a2.m128d_f64[0];
  v7 = a2.m128d_f64[0];
  if ( v6 != 0x8000000000000000i64 && (double)(signed int)v6 != a2.m128d_f64[0] )
    v7 = (double)((_mm_movemask_pd(_mm_unpckl_pd(a2, a2)) & 1 ^ 1) + (signed int)v6);
  v8 = v4->Result;
  if ( v8->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v8);
  v8->NV.NumberValue = v7;
  v8->T.Type = 3;
}

// File Line: 75
// RVA: 0x6B9780
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Cos(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *v7; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = fn;
  v4 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v6 = cos(v5);
  v7 = v3->Result;
  if ( v7->T.Type < 5u )
  {
    v7->NV.NumberValue = v6;
    v7->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
  }
}

// File Line: 76
// RVA: 0x6B99E0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Exp(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *v7; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = fn;
  v4 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v6 = exp(v5);
  v7 = v3->Result;
  if ( v7->T.Type < 5u )
  {
    v7->NV.NumberValue = v6;
    v7->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
  }
}

// File Line: 77
// RVA: 0x6B9BE0
void __usercall Scaleform::GFx::AS2::MathCtorFunction::Floor(Scaleform::GFx::AS2::FnCall *fn@<rcx>, __m128d a2@<xmm0>)
{
  Scaleform::GFx::AS2::Environment *v2; // r9
  unsigned __int64 v3; // r8
  Scaleform::GFx::AS2::FnCall *v4; // rbx
  Scaleform::GFx::AS2::Value *v5; // rcx
  __int64 v6; // rcx
  double v7; // xmm6_8
  Scaleform::GFx::AS2::Value *v8; // rbx

  v2 = fn->Env;
  v3 = (unsigned int)fn->FirstArgBottomIndex;
  v4 = fn;
  v5 = 0i64;
  if ( (unsigned int)v3 <= 32 * (LODWORD(v2->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v2->Stack.pCurrent - (char *)v2->Stack.pPageStart) >> 5) )
    v5 = &v2->Stack.Pages.Data.Data[v3 >> 5]->Values[v3 & 0x1F];
  a2.m128d_f64[0] = Scaleform::GFx::AS2::Value::ToNumber(v5, v2);
  v6 = (unsigned int)(signed int)a2.m128d_f64[0];
  v7 = a2.m128d_f64[0];
  if ( v6 != 0x8000000000000000i64 && (double)(signed int)v6 != a2.m128d_f64[0] )
    v7 = (double)(signed int)(v6 - (_mm_movemask_pd(_mm_unpckl_pd(a2, a2)) & 1));
  v8 = v4->Result;
  if ( v8->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v8);
  v8->NV.NumberValue = v7;
  v8->T.Type = 3;
}

// File Line: 78
// RVA: 0x6B9E60
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Log(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *v7; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = fn;
  v4 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v6 = log(v5);
  v7 = v3->Result;
  if ( v7->T.Type < 5u )
  {
    v7->NV.NumberValue = v6;
    v7->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
  }
}

// File Line: 79
// RVA: 0x6BA050
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Sin(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *v7; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = fn;
  v4 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v6 = sin(v5);
  v7 = v3->Result;
  if ( v7->T.Type < 5u )
  {
    v7->NV.NumberValue = v6;
    v7->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
  }
}

// File Line: 80
// RVA: 0x6BA1D0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Sqrt(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  double v5; // xmm0_8
  Scaleform::GFx::AS2::Value *v6; // rbx
  double v7; // xmm6_8

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = fn;
  v4 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v6 = v3->Result;
  v7 = sqrt(v5);
  if ( v6->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v6);
  v6->NV.NumberValue = v7;
  v6->T.Type = 3;
}

// File Line: 81
// RVA: 0x6BA340
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Tan(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::FnCall *v3; // rbx
  Scaleform::GFx::AS2::Value *v4; // rcx
  long double v5; // xmm0_8
  double v6; // xmm0_8
  Scaleform::GFx::AS2::Value *v7; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = fn;
  v4 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v4 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v5 = Scaleform::GFx::AS2::Value::ToNumber(v4, v1);
  v6 = tan(v5);
  v7 = v3->Result;
  if ( v7->T.Type < 5u )
  {
    v7->NV.NumberValue = v6;
    v7->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v7);
    v7->T.Type = 3;
    v7->NV.NumberValue = v6;
  }
}

// File Line: 83
// RVA: 0x6BA4D0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Atan2(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::FnCall *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rcx
  long double v6; // xmm0_8
  Scaleform::GFx::AS2::Environment *v7; // rdx
  long double v8; // xmm6_8
  unsigned __int64 v9; // r8
  long double v10; // xmm0_8
  double v11; // xmm0_8
  Scaleform::GFx::AS2::Value *v12; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = 0i64;
  v4 = fn;
  v5 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v5 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, v1);
  v7 = v4->Env;
  v8 = v6;
  v9 = (unsigned int)(v4->FirstArgBottomIndex - 1);
  if ( (unsigned int)v9 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
    v3 = &v7->Stack.Pages.Data.Data[v9 >> 5]->Values[(LOBYTE(v4->FirstArgBottomIndex) - 1) & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToNumber(v3, v7);
  v11 = atan2(v8, v10);
  v12 = v4->Result;
  if ( v12->T.Type < 5u )
  {
    v12->NV.NumberValue = v11;
    v12->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v4->Result);
    v12->T.Type = 3;
    v12->NV.NumberValue = v11;
  }
}

// File Line: 84
// RVA: 0x6BA8D0
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Max(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::FnCall *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rcx
  long double v6; // xmm0_8
  Scaleform::GFx::AS2::Environment *v7; // rdx
  double v8; // xmm6_8
  unsigned __int64 v9; // r8
  double v10; // xmm0_8
  Scaleform::GFx::AS2::Value *v11; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = 0i64;
  v4 = fn;
  v5 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v5 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, v1);
  v7 = v4->Env;
  v8 = v6;
  v9 = (unsigned int)(v4->FirstArgBottomIndex - 1);
  if ( (unsigned int)v9 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
    v3 = &v7->Stack.Pages.Data.Data[v9 >> 5]->Values[(LOBYTE(v4->FirstArgBottomIndex) - 1) & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToNumber(v3, v7);
  if ( v8 <= v10 )
    v8 = v10;
  v11 = v4->Result;
  if ( v11->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v4->Result);
  v11->NV.NumberValue = v8;
  v11->T.Type = 3;
}

// File Line: 85
// RVA: 0x6BAB50
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Min(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::FnCall *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rcx
  long double v6; // xmm0_8
  Scaleform::GFx::AS2::Environment *v7; // rdx
  double v8; // xmm6_8
  unsigned __int64 v9; // r8
  double v10; // xmm0_8
  Scaleform::GFx::AS2::Value *v11; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = 0i64;
  v4 = fn;
  v5 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v5 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, v1);
  v7 = v4->Env;
  v8 = v6;
  v9 = (unsigned int)(v4->FirstArgBottomIndex - 1);
  if ( (unsigned int)v9 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
    v3 = &v7->Stack.Pages.Data.Data[v9 >> 5]->Values[(LOBYTE(v4->FirstArgBottomIndex) - 1) & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToNumber(v3, v7);
  if ( v8 >= v10 )
    v8 = v10;
  v11 = v4->Result;
  if ( v11->T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(v4->Result);
  v11->NV.NumberValue = v8;
  v11->T.Type = 3;
}

// File Line: 86
// RVA: 0x6BAD20
void __fastcall Scaleform::GFx::AS2::MathCtorFunction::Pow(Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Environment *v1; // r9
  unsigned __int64 v2; // r8
  Scaleform::GFx::AS2::Value *v3; // rbx
  Scaleform::GFx::AS2::FnCall *v4; // rdi
  Scaleform::GFx::AS2::Value *v5; // rcx
  long double v6; // xmm0_8
  Scaleform::GFx::AS2::Environment *v7; // rdx
  double v8; // xmm6_8
  unsigned __int64 v9; // r8
  double v10; // xmm0_8
  double v11; // xmm0_8
  Scaleform::GFx::AS2::Value *v12; // rbx

  v1 = fn->Env;
  v2 = (unsigned int)fn->FirstArgBottomIndex;
  v3 = 0i64;
  v4 = fn;
  v5 = 0i64;
  if ( (unsigned int)v2 <= 32 * (LODWORD(v1->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v1->Stack.pCurrent - (char *)v1->Stack.pPageStart) >> 5) )
    v5 = &v1->Stack.Pages.Data.Data[v2 >> 5]->Values[v2 & 0x1F];
  v6 = Scaleform::GFx::AS2::Value::ToNumber(v5, v1);
  v7 = v4->Env;
  v8 = v6;
  v9 = (unsigned int)(v4->FirstArgBottomIndex - 1);
  if ( (unsigned int)v9 <= 32 * (LODWORD(v7->Stack.Pages.Data.Size) - 1)
                         + (unsigned int)((_QWORD)((char *)v7->Stack.pCurrent - (char *)v7->Stack.pPageStart) >> 5) )
    v3 = &v7->Stack.Pages.Data.Data[v9 >> 5]->Values[(LOBYTE(v4->FirstArgBottomIndex) - 1) & 0x1F];
  v10 = Scaleform::GFx::AS2::Value::ToNumber(v3, v7);
  v11 = pow(v8, v10);
  v12 = v4->Result;
  if ( v12->T.Type < 5u )
  {
    v12->NV.NumberValue = v11;
    v12->T.Type = 3;
  }
  else
  {
    Scaleform::GFx::AS2::Value::DropRefs(v4->Result);
    v12->T.Type = 3;
    v12->NV.NumberValue = v11;
  }
}

