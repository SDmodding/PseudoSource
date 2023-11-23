// File Line: 28
// RVA: 0x957F0
void __fastcall Illusion::ParamOverride::SetOverride(
        Illusion::ParamOverride *this,
        unsigned int param_uid,
        unsigned int resource_type_name_uid,
        unsigned int override_name_uid,
        Illusion::ParamOverride::Condition condition,
        unsigned int original_name_uid)
{
  int mCurrentParamIndex; // r10d
  int v10; // r11d
  int v11; // eax
  Illusion::StateParamLookup *v12; // rdx
  unsigned __int16 mParamIndex; // ax

  mCurrentParamIndex = Illusion::gStateSystem.mCurrentParamIndex;
  if ( Illusion::gStateSystem.mCurrentParamIndex > 0 )
  {
    v10 = 0;
    if ( Illusion::gStateSystem.mCurrentParamIndex >= 0 )
    {
      do
      {
        v11 = (mCurrentParamIndex + v10) / 2;
        v12 = &Illusion::gStateSystem.mStateParamLookup[v11];
        if ( param_uid <= v12->mNameUID )
        {
          if ( param_uid >= v12->mNameUID )
          {
            mParamIndex = v12->mParamIndex;
            goto LABEL_9;
          }
          mCurrentParamIndex = v11 - 1;
        }
        else
        {
          v10 = v11 + 1;
        }
      }
      while ( v10 <= mCurrentParamIndex );
    }
  }
  mParamIndex = 0;
LABEL_9:
  this->mConstantBlock = 0i64;
  this->mStateParamIndex = mParamIndex;
  this->mConstantBlockSize = 0;
  this->mOverrideResourceHandle.mTypeUID = resource_type_name_uid;
  this->mOverrideResourceHandle.mNameUID = override_name_uid;
  this->mCondition = condition;
  UFG::qResourceHandle::Init(
    &this->mOverrideResourceHandle,
    this->mOverrideResourceHandle.mTypeUID,
    this->mOverrideResourceHandle.mNameUID);
  this->mOriginalResourceHandle.mNameUID = original_name_uid;
  this->mOriginalResourceHandle.mTypeUID = resource_type_name_uid;
  UFG::qResourceHandle::Init(
    &this->mOriginalResourceHandle,
    this->mOriginalResourceHandle.mTypeUID,
    this->mOriginalResourceHandle.mNameUID);
}

// File Line: 57
// RVA: 0x95A20
void __fastcall Illusion::ParamOverride::SetTextureOverride(
        Illusion::ParamOverride *this,
        unsigned int param_uid,
        unsigned int override_name_uid,
        Illusion::ParamOverride::Condition condition,
        unsigned int original_name_uid)
{
  Illusion::ParamOverride::SetOverride(this, param_uid, 0x8B43FABF, override_name_uid, condition, original_name_uid);
}

