// File Line: 92
// RVA: 0x146140
UFG::qSymbol *__fastcall UFG::AudioEntity::GetName(UFG::AudioEntity *this, UFG::qSymbol *result)
{
  result->mUID = (unsigned int)this->m_name;
  return result;
}

// File Line: 168
// RVA: 0x143B10
bool __fastcall UFG::AudioEntity::CanApplyEnvironment(UFG::OneShot *this, UFG::qWiseSymbol *envType)
{
  return this->m_bEnableEnvironments
      && (envType->mUID == UFG::WwiseEnvironment::sm_SFX.mUID || envType->mUID == UFG::WwiseEnvironment::sm_All.mUID);
}

