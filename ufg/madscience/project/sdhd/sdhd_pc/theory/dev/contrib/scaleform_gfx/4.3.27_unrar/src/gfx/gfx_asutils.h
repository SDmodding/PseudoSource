// File Line: 79
// RVA: 0x700AE0
bool __fastcall Scaleform::GFx::NumberUtil::IsNaN(long double v)
{
  return (*(_QWORD *)&v & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 && (*(_QWORD *)&v & 0xFFFFFFFFFFFFFi64) != 0;
}

