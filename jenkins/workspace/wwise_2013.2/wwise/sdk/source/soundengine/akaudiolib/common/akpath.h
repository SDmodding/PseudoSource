// File Line: 190
// RVA: 0xA86A10
void __fastcall CAkPath::RandomizePosition(CAkPath *this, AkVector *in_rPosition)
{
  AkVector *v2; // rdi
  CAkPath *v3; // rbx

  v2 = in_rPosition;
  v3 = this;
  v2->X = (float)((float)((float)((float)rand() * 0.000061038882) - 1.0) * this->m_pCurrentList->fRangeX) + v2->X;
  v2->Z = (float)((float)((float)((float)rand() * 0.000061038882) - 1.0) * v3->m_pCurrentList->fRangeY) + v2->Z;
}

