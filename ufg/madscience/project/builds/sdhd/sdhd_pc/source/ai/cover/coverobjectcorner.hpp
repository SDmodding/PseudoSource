// File Line: 86
// RVA: 0x35FEF0
float __fastcall UFG::CoverObjectCorner::GetHeight(UFG::CoverObjectCorner *this)
{
  signed __int64 v1; // rax
  float result; // xmm0_4

  v1 = UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  if ( v1 )
    result = *(float *)(v1 + 40);
  else
    result = 0.0;
  return result;
}

