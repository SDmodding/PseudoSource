// File Line: 190
// RVA: 0x294330
void __fastcall ActionContext::UpdateProbabilites(ActionContext *this)
{
  float *mProbabilitys; // rbx
  __int64 v2; // rdi

  this->mProbabilitiesValid = 1;
  mProbabilitys = this->mProbabilitys;
  v2 = 10i64;
  do
  {
    *mProbabilitys++ = UFG::qRandom(100.0, (unsigned int *)&UFG::qDefaultSeed);
    --v2;
  }
  while ( v2 );
}

