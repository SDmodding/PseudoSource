// File Line: 76
// RVA: 0x2010
void __fastcall Illusion::MaterialModifierParams<10>::MaterialModifierParams<10>(
        Illusion::MaterialModifierParams<10> *this)
{
  Illusion::ParamOverride *mOverrides; // rbx

  mOverrides = this->mOverrides;
  `eh vector constructor iterator(
    this->mOverrides,
    0x68ui64,
    10,
    (void (__fastcall *)(void *))Illusion::ParamOverride::ParamOverride);
  this->mOverridesPtr = mOverrides;
  this->mMaxOverrides = 10;
  this->mNumOverrides = 0;
}

