// File Line: 190
// RVA: 0x294330
void __fastcall ActionContext::UpdateProbabilites(ActionContext *this)
{
  float *v1; // rbx
  signed __int64 v2; // rdi

  this->mProbabilitiesValid = 1;
  v1 = this->mProbabilitys;
  v2 = 10i64;
  do
  {
    ++v1;
    *(v1 - 1) = UFG::qRandom(100.0, &UFG::qDefaultSeed);
    --v2;
  }
  while ( v2 );
}

