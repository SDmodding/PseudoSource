// File Line: 86
// RVA: 0x35FEF0
float __fastcall UFG::CoverObjectCorner::GetHeight(UFG::CoverObjectCorner *this)
{
  UFG::CoverCorner *v1; // rax

  v1 = UFG::CoverCornerHandle::Get(&this->m_CornerHandle);
  if ( v1 )
    return v1->m_fWallHeight;
  else
    return 0.0;
}

