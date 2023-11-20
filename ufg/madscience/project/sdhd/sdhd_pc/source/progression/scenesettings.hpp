// File Line: 23
// RVA: 0x48CE20
void __fastcall UFG::SceneSettings::LayerSetup::LayerSetup(UFG::SceneSettings::LayerSetup *this)
{
  this->mLayerName.mUID = -1;
  this->mGeoSettingsPresent = 0;
  *(_WORD *)&this->mGeoAutoActivate = 1;
}

// File Line: 39
// RVA: 0x48A860
void __fastcall UFG::SceneSettings::AltLayerSetup::AltLayerSetup(UFG::SceneSettings::AltLayerSetup *this)
{
  UFG::SceneSettings::AltLayerSetup *v1; // rbx

  v1 = this;
  UFG::qString::qString(&this->mLayerName);
  *(_WORD *)&v1->mFlush = 0;
}

// File Line: 51
// RVA: 0x48DF60
void __fastcall UFG::SceneSettings::VendorSetup::VendorSetup(UFG::SceneSettings::VendorSetup *this)
{
  this->mVendorType.mUID = -1;
  this->mEnable = 0;
}

// File Line: 64
// RVA: 0x48A910
void __fastcall UFG::SceneSettings::DisguiseSetup::DisguiseSetup(UFG::SceneSettings::DisguiseSetup *this)
{
  this->mDisguise.mUID = -1;
  *(_WORD *)&this->mEnableWardrobe = 0;
  this->mKeepOutfit = 0;
}

// File Line: 77
// RVA: 0x48CE40
void __fastcall UFG::SecondaryObjective::SecondaryObjective(UFG::SecondaryObjective *this)
{
  this->mStatus = 0;
  UFG::qString::qString(&this->mCaption);
}

