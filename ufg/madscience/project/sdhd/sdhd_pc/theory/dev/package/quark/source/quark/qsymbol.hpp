// File Line: 177
// RVA: 0x67E80
bool __fastcall UFG::qSymbol::is_null(UFG::qSymbol *this)
{
  return this->mUID == -1;
}

// File Line: 193
// RVA: 0x64B80
bool __fastcall UFG::qSymbol::operator==(UFG::qSymbol *this, UFG::qSymbol *sym)
{
  return this->mUID == sym->mUID;
}

// File Line: 196
// RVA: 0x1EF710
bool __fastcall UFG::qSymbol::operator!=(UFG::qSymbol *this, UFG::qSymbol *sym)
{
  return this->mUID != sym->mUID;
}

// File Line: 360
// RVA: 0x48E70
void __fastcall UFG::qStaticSymbol::qStaticSymbol(UFG::qStaticSymbol *this, const char *string)
{
  UFG::qStaticSymbol *v2; // rdi
  unsigned int v3; // eax

  v2 = this;
  v3 = UFG::qStringHash32(string, 0xFFFFFFFF);
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)v2, v3);
}

