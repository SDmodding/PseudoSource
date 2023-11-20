// File Line: 276
// RVA: 0x6D2640
void __fastcall Scaleform::GFx::AS2::StringManager::~StringManager(Scaleform::GFx::AS2::StringManager *this)
{
  Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(this->pStringManager, this->Builtins, 0x9Cu);
}

