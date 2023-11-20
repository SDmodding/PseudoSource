// File Line: 79
// RVA: 0x700AE0
bool __fastcall Scaleform::GFx::NumberUtil::IsNaN(long double v)
{
  long double v1; // rax

  v1 = v;
  return (*(_QWORD *)&v & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v1 & 0xFFFFFFFFFFFFFi64;
}

