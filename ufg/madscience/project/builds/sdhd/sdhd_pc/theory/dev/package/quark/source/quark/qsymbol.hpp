// File Line: 162
// RVA: 0x9A3B0
UFG::qSymbol *__fastcall UFG::qSymbol::qSymbol(UFG::qSymbol *this, UFG::qSymbol *source)
{
  this->mUID = source->mUID;
  return this;
}

// File Line: 222
// RVA: 0x9A3C0
void __fastcall BackInfo::BackInfo(UFG::qSymbol *this)
{
  this->mUID = -1;
}

