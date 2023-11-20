// File Line: 76
// RVA: 0x2010
void __fastcall Illusion::MaterialModifierParams<10>::MaterialModifierParams<10>(Illusion::MaterialModifierParams<10> *this)
{
  Illusion::MaterialModifierParams<10> *v1; // rdi
  Illusion::ParamOverride *v2; // rbx

  v1 = this;
  v2 = this->mOverrides;
  `eh vector constructor iterator'(
    this->mOverrides,
    0x68ui64,
    10,
    (void (__fastcall *)(void *))Illusion::ParamOverride::ParamOverride);
  v1->mOverridesPtr = v2;
  v1->mMaxOverrides = 10;
  v1->mNumOverrides = 0;
}

