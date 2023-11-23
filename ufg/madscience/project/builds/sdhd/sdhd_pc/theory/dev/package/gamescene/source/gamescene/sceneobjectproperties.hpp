// File Line: 133
// RVA: 0x3996E0
UFG::qWiseSymbol *__fastcall UFG::SceneObjectProperties::operator UFG::qSymbol(
        UFG::SceneObjectProperties *this,
        UFG::qWiseSymbol *result) const
{
  UFG::qSymbol::qSymbol(result, this->m_NameUID);
  return result;
}

