// File Line: 162
// RVA: 0x78E520
void __fastcall Scaleform::GFx::AS3::StringManager::~StringManager(Scaleform::GFx::AS3::StringManager *this)
{
  Scaleform::GFx::ASStringManager::ReleaseBuiltinArray(this->pStringManager, this->Builtins, 0x40u);
}

