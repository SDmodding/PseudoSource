// File Line: 133
// RVA: 0x3996E0
UFG::qSymbol *__fastcall UFG::SceneObjectProperties::operator UFG::qSymbol const(UFG::SceneObjectProperties *this, UFG::qSymbol *result)
{
  UFG::qSymbol *v2; // rbx

  v2 = result;
  UFG::qSymbol::qSymbol((UFG::qWiseSymbol *)result, this->m_NameUID);
  return v2;
}

