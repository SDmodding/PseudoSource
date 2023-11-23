// File Line: 190
// RVA: 0xA86A10
void __fastcall CAkPath::RandomizePosition(CAkPath *this, AkVector *in_rPosition)
{
  in_rPosition->X = (float)((float)((float)((float)rand() * 0.000061038882) - 1.0) * this->m_pCurrentList->fRangeX)
                  + in_rPosition->X;
  in_rPosition->Z = (float)((float)((float)((float)rand() * 0.000061038882) - 1.0) * this->m_pCurrentList->fRangeY)
                  + in_rPosition->Z;
}

